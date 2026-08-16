// Function: main @ 0x3b40
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <locale.h>
#include <libintl.h>
#include <syslog.h>
#include <stdbool.h>
#include <grp.h>
#include <gshadow.h>

#define _(s)                  gettext (s)
#define OPENLOG(progname)     openlog (progname, LOG_PID, LOG_AUTHPRIV)
#define SYSLOG(x)             syslog x

#define PACKAGE               "shadow"
#define LOCALEDIR             "/usr/share/locale"
#define SHADOW_PASSWD_STRING  "x"
#define SGROUP_FILE           "/etc/gshadow"
#define SSSD_DB_GROUP         0x002

/* program identity / logging helpers */
extern const char *Prog;
extern char *Basename (char *str);
extern void log_set_progname (const char *progname);
extern void log_set_logfd (FILE *fd);

/* command line parsing (defined elsewhere in this program) */
extern void process_root_flag (const char *short_flag, int argc, char **argv);
extern void process_flags (int argc, char **argv);

/* lock/open state flags */
extern bool gr_locked;
extern bool sgr_locked;

/* /etc/group database access */
extern int gr_lock (void);
extern int gr_open (int mode);
extern int gr_close (void);
extern int gr_unlock (void);
extern int gr_rewind (void);
extern int gr_update (const struct group *gr);
extern struct group *gr_next (void);
extern const char *gr_dbname (void);

/* /etc/gshadow database access */
extern bool sgr_file_present (void);
extern int sgr_lock (void);
extern int sgr_open (int mode);
extern int sgr_close (void);
extern int sgr_unlock (void);
extern struct sgrp *sgr_locate (const char *name);
extern const char *sgr_dbname (void);

/* name service cache flushing */
extern void nscd_flush_cache (const char *service);
extern void sssd_flush_cache (int dbflags);

/* clean up the locks we hold and terminate */
extern void fail_exit (int status) __attribute__ ((noreturn));

int
main (int argc, char **argv)
{
	const struct group *gr;
	struct group grent;
	const struct sgrp *sg;

	/*
	 * Get my name so that I can use it to report errors.
	 */
	Prog = Basename (argv[0]);
	log_set_progname (Prog);
	log_set_logfd (stderr);

	(void) setlocale (LC_ALL, "");
	(void) bindtextdomain (PACKAGE, LOCALEDIR);
	(void) textdomain (PACKAGE);

	process_root_flag ("-R", argc, argv);

	OPENLOG ("grpunconv");

	process_flags (argc, argv);

	/*
	 * The gshadow file must exist for there to be anything to un-convert.
	 */
	if (!sgr_file_present ()) {
		exit (0);
	}

	if (gr_lock () == 0) {
		fprintf (stderr,
		         _("%s: cannot lock %s; try again later.\n"),
		         Prog, gr_dbname ());
		fail_exit (5);
	}
	gr_locked = true;
	if (gr_open (O_CREAT | O_RDWR) == 0) {
		fprintf (stderr, _("%s: cannot open %s\n"), Prog, gr_dbname ());
		fail_exit (1);
	}

	if (sgr_lock () == 0) {
		fprintf (stderr,
		         _("%s: cannot lock %s; try again later.\n"),
		         Prog, sgr_dbname ());
		fail_exit (5);
	}
	sgr_locked = true;
	if (sgr_open (O_RDONLY) == 0) {
		fprintf (stderr, _("%s: cannot open %s\n"), Prog, sgr_dbname ());
		fail_exit (1);
	}

	/*
	 * Copy the password from the shadowed file back into the group file
	 * for every entry whose group password is still marked as shadowed.
	 */
	(void) gr_rewind ();
	while ((gr = gr_next ()) != NULL) {
		sg = sgr_locate (gr->gr_name);
		if (   (NULL != sg)
		    && (strcmp (gr->gr_passwd, SHADOW_PASSWD_STRING) == 0)) {
			/* add password to /etc/group */
			grent = *gr;
			grent.gr_passwd = sg->sg_passwd;
			if (gr_update (&grent) == 0) {
				fprintf (stderr,
				         _("%s: failed to prepare the new %s entry '%s'\n"),
				         Prog, gr_dbname (), grent.gr_name);
				fail_exit (3);
			}
		}
	}

	(void) sgr_close ();	/* was opened read only, no need to check */

	if (gr_close () == 0) {
		fprintf (stderr,
		         _("%s: failure while writing changes to %s\n"),
		         Prog, gr_dbname ());
		SYSLOG ((LOG_ERR, "failure while writing changes to %s",
		         gr_dbname ()));
		fail_exit (3);
	}

	if (unlink (SGROUP_FILE) != 0) {
		fprintf (stderr, _("%s: cannot delete %s\n"), Prog, SGROUP_FILE);
		SYSLOG ((LOG_ERR, "cannot delete %s", SGROUP_FILE));
		fail_exit (3);
	}

	if (gr_unlock () == 0) {
		fprintf (stderr, _("%s: failed to unlock %s\n"), Prog, gr_dbname ());
		SYSLOG ((LOG_ERR, "failed to unlock %s", gr_dbname ()));
		/* continue */
	}
	if (sgr_unlock () == 0) {
		fprintf (stderr, _("%s: failed to unlock %s\n"), Prog, sgr_dbname ());
		SYSLOG ((LOG_ERR, "failed to unlock %s", sgr_dbname ()));
		/* continue */
	}

	nscd_flush_cache ("group");
	sssd_flush_cache (SSSD_DB_GROUP);

	return 0;
}


