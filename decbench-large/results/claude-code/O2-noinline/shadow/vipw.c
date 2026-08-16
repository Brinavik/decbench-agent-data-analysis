// Function: main @ 0x3d60
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <libintl.h>
#include <syslog.h>
#include <getopt.h>

#define _(s) gettext(s)

#define PACKAGE   "shadow"
#define LOCALEDIR "/usr/share/locale"

/* shadow exit codes (lib/exitcodes.h) */
#define E_SUCCESS 0
#define E_USAGE   2

/* sssd cache flags (lib/sssd.h) */
#define SSS_CACHE_PASSWD 0x001
#define SSS_CACHE_GROUP  0x002

/* Global state (defined elsewhere in the program). */
extern const char *Prog;
static bool quiet = false;

/* Program-name / logging helpers (lib/). */
extern char *Basename(char *str);
extern void  log_set_progname(const char *name);
extern void  log_set_logfd(FILE *fd);
extern void  process_root_flag(const char *short_opt, int argc, char **argv);

/* Database name / presence / locking helpers. */
extern const char *pw_dbname(void);
extern const char *spw_dbname(void);
extern const char *gr_dbname(void);
extern const char *sgr_dbname(void);
extern bool spw_file_present(void);
extern bool sgr_file_present(void);
extern int pw_lock(void);
extern int pw_unlock(void);
extern int spw_lock(void);
extern int spw_unlock(void);
extern int gr_lock(void);
extern int gr_unlock(void);
extern int sgr_lock(void);
extern int sgr_unlock(void);

/* Cache-flushing helpers. */
extern void nscd_flush_cache(const char *service);
extern int  sssd_flush_cache(int dbflags);

extern void usage(int status);
extern void vipwedit(const char *file,
                     int (*file_lock)(void),
                     int (*file_unlock)(void));

int main(int argc, char **argv)
{
	bool editshadow = false;
	bool do_vipw;

	/*
	 * Get my name so that I can use it to report errors.
	 */
	Prog = Basename(argv[0]);
	log_set_progname(Prog);
	log_set_logfd(stderr);

	(void) setlocale(LC_ALL, "");
	(void) bindtextdomain(PACKAGE, LOCALEDIR);
	(void) textdomain(PACKAGE);

	process_root_flag("-R", argc, argv);

	do_vipw = (strcmp(Prog, "vigr") != 0);

	openlog(do_vipw ? "vipw" : "vigr", LOG_PID, LOG_AUTHPRIV);

	{
		int c;
		static struct option long_options[] = {
			{"group",  no_argument,       NULL, 'g'},
			{"help",   no_argument,       NULL, 'h'},
			{"passwd", no_argument,       NULL, 'p'},
			{"quiet",  no_argument,       NULL, 'q'},
			{"root",   required_argument, NULL, 'R'},
			{"shadow", no_argument,       NULL, 's'},
			{NULL, 0, NULL, '\0'}
		};
		while ((c = getopt_long(argc, argv, "ghpqR:s",
		                        long_options, NULL)) != -1) {
			switch (c) {
			case 'g':
				do_vipw = false;
				break;
			case 'h':
				usage(E_SUCCESS);
				break;
			case 'p':
				do_vipw = true;
				break;
			case 'q':
				quiet = true;
				break;
			case 'R': /* no-op, handled in process_root_flag() */
				break;
			case 's':
				editshadow = true;
				break;
			default:
				usage(E_USAGE);
			}
		}
	}

	if (optind != argc) {
		usage(E_USAGE);
	}

	if (do_vipw) {
		if (editshadow) {
			vipwedit(spw_dbname(), spw_lock, spw_unlock);
			printf(_("You have modified %s.\n"
			         "You may need to modify %s for consistency.\n"
			         "Please use the command '%s' to do so.\n"),
			       spw_dbname(), pw_dbname(), "vipw");
		} else {
			vipwedit(pw_dbname(), pw_lock, pw_unlock);
			if (spw_file_present()) {
				printf(_("You have modified %s.\n"
				         "You may need to modify %s for consistency.\n"
				         "Please use the command '%s' to do so.\n"),
				       pw_dbname(), spw_dbname(), "vipw -s");
			}
		}
	} else {
		if (editshadow) {
			vipwedit(sgr_dbname(), sgr_lock, sgr_unlock);
			printf(_("You have modified %s.\n"
			         "You may need to modify %s for consistency.\n"
			         "Please use the command '%s' to do so.\n"),
			       sgr_dbname(), gr_dbname(), "vigr");
		} else {
			vipwedit(gr_dbname(), gr_lock, gr_unlock);
			if (sgr_file_present()) {
				printf(_("You have modified %s.\n"
				         "You may need to modify %s for consistency.\n"
				         "Please use the command '%s' to do so.\n"),
				       gr_dbname(), sgr_dbname(), "vigr -s");
			}
		}
	}

	nscd_flush_cache("passwd");
	nscd_flush_cache("group");
	sssd_flush_cache(SSS_CACHE_PASSWD | SSS_CACHE_GROUP);

	return E_SUCCESS;
}


