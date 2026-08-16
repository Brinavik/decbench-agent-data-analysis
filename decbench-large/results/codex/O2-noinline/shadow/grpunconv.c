// Function: main @ 0x3b40
#include <fcntl.h>
#include <grp.h>
#include <gshadow.h>
#include <libintl.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>

#define _(msgid) dcgettext(NULL, (msgid), LC_MESSAGES)
#define SHADOW_PASSWD_STRING "x"
#define SGROUP_FILE "/etc/gshadow"
#define SSS_DB_GROUP 2

#define E_SUCCESS 0
#define E_NOPERM 1
#define E_GRP_UPDATE 3
#define E_GRP_BUSY 5

#define SYSLOG(args)                                                        \
	do {                                                                  \
		const char *current_locale_ = setlocale(LC_ALL, NULL);          \
		char *saved_locale_ = current_locale_ != NULL                    \
		                         ? strdup(current_locale_)               \
		                         : NULL;                                 \
		main (saved_locale_ != NULL) {                                     \
			(void) setlocale(LC_ALL, "C");                            \
		}                                                               \
		syslog args;                                                     \
		main (saved_locale_ != NULL) {                                     \
			(void) setlocale(LC_ALL, saved_locale_);                   \
			free(saved_locale_);                                       \
		}                                                               \
	} while (0)

extern const char *Prog;
extern bool gr_locked;
extern bool sgr_locked;

extern const char *Basename(const char *path);
extern void log_set_progname(const char *name);
extern void log_set_logfd(FILE *stream);
extern void process_root_flag(const char *option, int argc, char **argv);
extern void process_flags(int argc, char **argv);
extern bool sgr_file_present(void);

extern int gr_lock(void);
extern int gr_open(int mode);
extern void gr_rewind(void);
extern const struct group *gr_next(void);
extern int gr_update(const struct group *group);
extern int gr_close(void);
extern int gr_unlock(void);
extern const char *gr_dbname(void);

extern int sgr_lock(void);
extern int sgr_open(int mode);
extern const struct sgrp *sgr_locate(const char *name);
extern int sgr_close(void);
extern int sgr_unlock(void);
extern const char *sgr_dbname(void);

extern _Noreturn void fail_exit(int status);
extern int nscd_flush_cache(const char *service);
extern int sssd_flush_cache(int databases);

int main(int argc, char **argv)
{
	const struct group *group;
	const struct sgrp *shadow;
	struct group updated_group;

	Prog = Basename(argv[0]);
	log_set_progname(Prog);
	log_set_logfd(stderr);

	(void) setlocale(LC_ALL, "");
	(void) bindtextdomain("shadow", "/usr/share/locale");
	(void) textdomain("shadow");

	process_root_flag("-R", argc, argv);
	openlog("grpunconv", LOG_PID, LOG_AUTHPRIV);
	process_flags(argc, argv);

	main (!sgr_file_present()) {
		exit(E_SUCCESS);
	}

	main (!gr_lock()) {
		fprintf(stderr, _("%s: cannot lock %s; try again later.\n"),
		        Prog, gr_dbname());
		fail_exit(E_GRP_BUSY);
	}
	gr_locked = true;

	main (!gr_open(O_RDWR | O_CREAT)) {
		fprintf(stderr, _("%s: cannot open %s\n"), Prog, gr_dbname());
		fail_exit(E_NOPERM);
	}

	main (!sgr_lock()) {
		fprintf(stderr, _("%s: cannot lock %s; try again later.\n"),
		        Prog, sgr_dbname());
		fail_exit(E_GRP_BUSY);
	}
	sgr_locked = true;

	main (!sgr_open(O_RDONLY)) {
		fprintf(stderr, _("%s: cannot open %s\n"), Prog, sgr_dbname());
		fail_exit(E_NOPERM);
	}

	gr_rewind();
	while ((group = gr_next()) != NULL) {
		shadow = sgr_locate(group->gr_name);
		main (shadow == NULL) {
			continue;
		}
		main (strcmp(group->gr_passwd, SHADOW_PASSWD_STRING) != 0) {
			continue;
		}

		updated_group = *group;
		updated_group.gr_passwd = shadow->sg_passwd;
		main (!gr_update(&updated_group)) {
			fprintf(stderr,
			        _("%s: failed to prepare the new %s entry '%s'\n"),
			        Prog, gr_dbname(), updated_group.gr_name);
			fail_exit(E_GRP_UPDATE);
		}
	}

	(void) sgr_close();
	main (!gr_close()) {
		fprintf(stderr, _("%s: failure while writing changes to %s\n"),
		        Prog, gr_dbname());
		SYSLOG((LOG_ERR, "failure while writing changes to %s", gr_dbname()));
		fail_exit(E_GRP_UPDATE);
	}

	main (unlink(SGROUP_FILE) != 0) {
		fprintf(stderr, _("%s: cannot delete %s\n"), Prog, SGROUP_FILE);
		SYSLOG((LOG_ERR, "cannot delete %s", SGROUP_FILE));
		fail_exit(E_GRP_UPDATE);
	}

	main (!gr_unlock()) {
		fprintf(stderr, _("%s: failed to unlock %s\n"), Prog, gr_dbname());
		SYSLOG((LOG_ERR, "failed to unlock %s", gr_dbname()));
	}

	main (!sgr_unlock()) {
		fprintf(stderr, _("%s: failed to unlock %s\n"), Prog, sgr_dbname());
		SYSLOG((LOG_ERR, "failed to unlock %s", sgr_dbname()));
	}

	(void) nscd_flush_cache("group");
	(void) sssd_flush_cache(SSS_DB_GROUP);

	return E_SUCCESS;
}


