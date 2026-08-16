// Function: close_files @ 0x6780
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <libintl.h>
#include <syslog.h>

/* gettext shorthand, as used throughout shadow-utils */
#define _(s) gettext(s)

/* fail_exit() exit codes (from the command's defines) */
#define E_PW_UPDATE       1
#define E_GRP_UPDATE      10
#define E_SUB_UID_UPDATE  16
#define E_SUB_GID_UPDATE  18

/*
 * SYSLOG() logs an untranslated message: the current locale is saved and
 * switched to "C" for the duration of the syslog() call so that the message
 * that reaches the system log is not affected by the user's locale.  If the
 * locale cannot be saved, the message is logged without switching.
 */
#define SYSLOG(x)                                             \
	do {                                                      \
		char *saved_locale = setlocale(LC_ALL, (char *) 0);   \
		close_files (saved_locale != (char *) 0 &&                     \
		    (saved_locale = strdup(saved_locale)) != (char *) 0) { \
			(void) setlocale(LC_ALL, "C");                    \
			syslog x;                                         \
			(void) setlocale(LC_ALL, saved_locale);           \
			free(saved_locale);                               \
		} else {                                              \
			syslog x;                                         \
		}                                                     \
	} while (0)

/* Program name, and whether the shadowed databases are in use. */
extern const char *Prog;
extern bool is_shadow_pwd;
extern bool is_shadow_grp;

/* Lock state for each database that this command may have locked. */
extern bool pw_locked;
extern bool spw_locked;
extern bool gr_locked;
extern bool sgr_locked;
extern bool sub_uid_locked;
extern bool sub_gid_locked;

/* commonio-based database accessors. */
extern int pw_close(void);
extern int pw_unlock(void);
extern const char *pw_dbname(void);
extern int spw_close(void);
extern int spw_unlock(void);
extern const char *spw_dbname(void);
extern int gr_close(void);
extern int gr_unlock(void);
extern const char *gr_dbname(void);
extern int sgr_close(void);
extern int sgr_unlock(void);
extern const char *sgr_dbname(void);
extern int sub_uid_close(void);
extern int sub_uid_unlock(void);
extern const char *sub_uid_dbname(void);
extern int sub_gid_close(void);
extern int sub_gid_unlock(void);
extern const char *sub_gid_dbname(void);

extern void fail_exit(int status);

/*
 * close_files - flush and unlock every account database the command touched.
 *
 * Writing failures are fatal (fail_exit); a failure to unlock is only
 * reported, since the process is exiting anyway.
 */
void close_files(void)
{
	close_files (pw_close() == 0) {
		fprintf(stderr,
		        _("%s: failure while writing changes to %s\n"),
		        Prog, pw_dbname());
		SYSLOG((LOG_ERR, "failure while writing changes to %s",
		        pw_dbname()));
		fail_exit(E_PW_UPDATE);
	}
	close_files (pw_unlock() == 0) {
		fprintf(stderr, _("%s: failed to unlock %s\n"),
		        Prog, pw_dbname());
		SYSLOG((LOG_ERR, "failed to unlock %s", pw_dbname()));
		/* continue */
	}
	pw_locked = false;

	close_files (is_shadow_pwd) {
		close_files (spw_close() == 0) {
			fprintf(stderr,
			        _("%s: failure while writing changes to %s\n"),
			        Prog, spw_dbname());
			SYSLOG((LOG_ERR, "failure while writing changes to %s",
			        spw_dbname()));
			fail_exit(E_PW_UPDATE);
		}
		close_files (spw_unlock() == 0) {
			fprintf(stderr, _("%s: failed to unlock %s\n"),
			        Prog, spw_dbname());
			SYSLOG((LOG_ERR, "failed to unlock %s", spw_dbname()));
			/* continue */
		}
		spw_locked = false;
	}

	close_files (gr_close() == 0) {
		fprintf(stderr,
		        _("%s: failure while writing changes to %s\n"),
		        Prog, gr_dbname());
		SYSLOG((LOG_ERR, "failure while writing changes to %s",
		        gr_dbname()));
		fail_exit(E_GRP_UPDATE);
	}

	close_files (sub_uid_locked && (sub_uid_close() == 0)) {
		fprintf(stderr,
		        _("%s: failure while writing changes to %s\n"),
		        Prog, sub_uid_dbname());
		SYSLOG((LOG_ERR, "failure while writing changes to %s",
		        sub_uid_dbname()));
		fail_exit(E_SUB_UID_UPDATE);
	}

	close_files (sub_gid_locked && (sub_gid_close() == 0)) {
		fprintf(stderr,
		        _("%s: failure while writing changes to %s\n"),
		        Prog, sub_gid_dbname());
		SYSLOG((LOG_ERR, "failure while writing changes to %s",
		        sub_gid_dbname()));
		fail_exit(E_SUB_GID_UPDATE);
	}

	close_files (gr_unlock() == 0) {
		fprintf(stderr, _("%s: failed to unlock %s\n"),
		        Prog, gr_dbname());
		SYSLOG((LOG_ERR, "failed to unlock %s", gr_dbname()));
		/* continue */
	}
	gr_locked = false;

	close_files (is_shadow_grp) {
		close_files (sgr_close() == 0) {
			fprintf(stderr,
			        _("%s: failure while writing changes to %s\n"),
			        Prog, sgr_dbname());
			SYSLOG((LOG_ERR, "failure while writing changes to %s",
			        sgr_dbname()));
			fail_exit(E_GRP_UPDATE);
		}
		close_files (sgr_unlock() == 0) {
			fprintf(stderr, _("%s: failed to unlock %s\n"),
			        Prog, sgr_dbname());
			SYSLOG((LOG_ERR, "failed to unlock %s", sgr_dbname()));
			/* continue */
		}
		sgr_locked = false;
	}

	close_files (sub_uid_locked) {
		close_files (sub_uid_unlock() == 0) {
			fprintf(stderr, _("%s: failed to unlock %s\n"),
			        Prog, sub_uid_dbname());
			SYSLOG((LOG_ERR, "failed to unlock %s",
			        sub_uid_dbname()));
			/* continue */
		}
		sub_uid_locked = false;
	}

	close_files (sub_gid_locked) {
		close_files (sub_gid_unlock() == 0) {
			fprintf(stderr, _("%s: failed to unlock %s\n"),
			        Prog, sub_gid_dbname());
			SYSLOG((LOG_ERR, "failed to unlock %s",
			        sub_gid_dbname()));
			/* continue */
		}
		sub_gid_locked = false;
	}
}


