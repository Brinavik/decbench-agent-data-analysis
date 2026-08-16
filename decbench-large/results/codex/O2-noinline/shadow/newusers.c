// Function: close_files @ 0x6780
#define _GNU_SOURCE
#include <libintl.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

void close_files(void)
{
	extern const char *Prog;
	extern bool is_shadow_pwd;
	extern bool is_shadow_grp;
	extern bool use_sub_uids;
	extern bool use_sub_gids;
	extern bool pw_locked;
	extern bool spw_locked;
	extern bool gr_locked;
	extern bool sgr_locked;
	extern bool sub_uid_locked;
	extern bool sub_gid_locked;

	extern bool pw_close(void);
	extern bool pw_unlock(void);
	extern const char *pw_dbname(void);
	extern bool spw_close(void);
	extern bool spw_unlock(void);
	extern const char *spw_dbname(void);
	extern bool gr_close(void);
	extern bool gr_unlock(void);
	extern const char *gr_dbname(void);
	extern bool sgr_close(void);
	extern bool sgr_unlock(void);
	extern const char *sgr_dbname(void);
	extern bool sub_uid_close(void);
	extern bool sub_uid_unlock(void);
	extern const char *sub_uid_dbname(void);
	extern bool sub_gid_close(void);
	extern bool sub_gid_unlock(void);
	extern const char *sub_gid_dbname(void);
	extern _Noreturn void fail_exit(void);

#define SYSLOG(args)                                                        \
	do {                                                                  \
		const char *current_locale = setlocale(LC_ALL, NULL);            \
		char *saved_locale = NULL;                                       \
		if (current_locale != NULL)                                      \
			saved_locale = strdup(current_locale);                      \
		if (saved_locale != NULL)                                        \
			(void)setlocale(LC_ALL, "C");                              \
		syslog args;                                                       \
		if (saved_locale != NULL) {                                      \
			(void)setlocale(LC_ALL, saved_locale);                       \
			free(saved_locale);                                          \
		}                                                                 \
	} while (0)

	if (!pw_close()) {
		fprintf(stderr,
		        gettext("%s: failure while writing changes to %s\n"),
		        Prog, pw_dbname());
		SYSLOG((LOG_ERR, "failure while writing changes to %s",
		        pw_dbname()));
		fail_exit();
	}
	if (!pw_unlock()) {
		fprintf(stderr, gettext("%s: failed to unlock %s\n"),
		        Prog, pw_dbname());
		SYSLOG((LOG_ERR, "failed to unlock %s", pw_dbname()));
	}
	pw_locked = false;

	if (is_shadow_pwd) {
		if (!spw_close()) {
			fprintf(stderr,
			        gettext("%s: failure while writing changes to %s\n"),
			        Prog, spw_dbname());
			SYSLOG((LOG_ERR, "failure while writing changes to %s",
			        spw_dbname()));
			fail_exit();
		}
		if (!spw_unlock()) {
			fprintf(stderr, gettext("%s: failed to unlock %s\n"),
			        Prog, spw_dbname());
			SYSLOG((LOG_ERR, "failed to unlock %s", spw_dbname()));
		}
		spw_locked = false;
	}

	if (!gr_close()) {
		fprintf(stderr,
		        gettext("%s: failure while writing changes to %s\n"),
		        Prog, gr_dbname());
		SYSLOG((LOG_ERR, "failure while writing changes to %s",
		        gr_dbname()));
		fail_exit();
	}

	if (use_sub_uids && !sub_uid_close()) {
		fprintf(stderr,
		        gettext("%s: failure while writing changes to %s\n"),
		        Prog, sub_uid_dbname());
		SYSLOG((LOG_ERR, "failure while writing changes to %s",
		        sub_uid_dbname()));
		fail_exit();
	}

	if (use_sub_gids && !sub_gid_close()) {
		fprintf(stderr,
		        gettext("%s: failure while writing changes to %s\n"),
		        Prog, sub_gid_dbname());
		SYSLOG((LOG_ERR, "failure while writing changes to %s",
		        sub_gid_dbname()));
		fail_exit();
	}

	if (!gr_unlock()) {
		fprintf(stderr, gettext("%s: failed to unlock %s\n"),
		        Prog, gr_dbname());
		SYSLOG((LOG_ERR, "failed to unlock %s", gr_dbname()));
	}
	gr_locked = false;

	if (is_shadow_grp) {
		if (!sgr_close()) {
			fprintf(stderr,
			        gettext("%s: failure while writing changes to %s\n"),
			        Prog, sgr_dbname());
			SYSLOG((LOG_ERR, "failure while writing changes to %s",
			        sgr_dbname()));
			fail_exit();
		}
		if (!sgr_unlock()) {
			fprintf(stderr, gettext("%s: failed to unlock %s\n"),
			        Prog, sgr_dbname());
			SYSLOG((LOG_ERR, "failed to unlock %s", sgr_dbname()));
		}
		sgr_locked = false;
	}

	if (use_sub_uids) {
		if (!sub_uid_unlock()) {
			fprintf(stderr, gettext("%s: failed to unlock %s\n"),
			        Prog, sub_uid_dbname());
			SYSLOG((LOG_ERR, "failed to unlock %s",
			        sub_uid_dbname()));
		}
		sub_uid_locked = false;
	}

	if (use_sub_gids) {
		if (!sub_gid_unlock()) {
			fprintf(stderr, gettext("%s: failed to unlock %s\n"),
			        Prog, sub_gid_dbname());
			SYSLOG((LOG_ERR, "failed to unlock %s",
			        sub_gid_dbname()));
		}
		sub_gid_locked = false;
	}

#undef SYSLOG
}


