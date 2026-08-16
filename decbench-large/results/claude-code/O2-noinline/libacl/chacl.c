// Function: main @ 0x1440
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <locale.h>
#include <libgen.h>
#include <unistd.h>
#include <libintl.h>

/* Minimal libacl surface used by this translation unit. */
typedef void *acl_t;
typedef int   acl_type_t;
#define ACL_TYPE_ACCESS   0x8000
#define ACL_TYPE_DEFAULT  0x4000

extern acl_t       acl_from_text(const char *buf_p);
extern int         acl_check(acl_t acl, int *last);
extern const char *acl_error(int code);
extern int         acl_free(void *obj_p);

/* Program-local globals and helpers (defined elsewhere in the program). */
char *progname;
int   rflag;                       /* -r : recurse into directories */

static void usage(void);                                 /* prints usage, exits(1) */
static int  list_acl(char *file);                        /* returns 1 on success */
static int  do_set(acl_t acl, acl_t dacl, char *file);   /* returns error count  */
static int  remove_acl(char *file, acl_type_t type);     /* returns 0 or -1      */

int
main(int argc, char **argv)
{
	int   c;
	int   nargs = 0;
	int   n = 0;
	int   status;
	acl_t acl = NULL, dacl = NULL;
	int   opt_B = 0;	/* -B : remove access and default acl */
	int   opt_D = 0;	/* -D : remove default acl only        */
	int   opt_R = 0;	/* -R : remove access acl only         */
	int   opt_l = 0;	/* -l : list acls                      */
	int   opt_b = 0;	/* -b : set access and default acl     */
	int   opt_d = 0;	/* -d : set default acl only           */

	progname = basename(argv[0]);

	setlocale(LC_CTYPE, "");
	setlocale(LC_MESSAGES, "");
	bindtextdomain("acl", "/usr/share/locale");
	textdomain("acl");

	c = getopt(argc, argv, "bdlRDBr");
	if (c == -1) {
		/* No option given: "chacl acl pathname..." */
		if (argc - optind - 1 <= 0)
			usage();
		goto set;
	}

	switch (c) {
	case 'B':
		opt_B = 1;
		nargs = 1;
		break;
	case 'D':
		opt_D = 1;
		nargs = 1;
		break;
	case 'R':
		opt_R = 1;
		nargs = 1;
		break;
	case 'b':
		opt_b = 1;
		nargs = 3;
		break;
	case 'd':
		opt_d = 1;
		nargs = 2;
		break;
	case 'l':
		opt_l = 1;
		nargs = 1;
		break;
	case 'r':
		rflag = 1;
		nargs = 1;
		break;
	default:
		usage();
	}

	/* Only a single option flag is accepted. */
	if (getopt(argc, argv, "bdlRDBr") != -1)
		usage();

	if (argc - optind < nargs)
		usage();

	if (opt_l) {
		for (; optind < argc; optind++)
			if (list_acl(argv[optind]) == 0)
				n++;
		return n;
	}

	if (opt_B || opt_D || opt_R) {
		for (; optind < argc; optind++) {
			if (!opt_D) {
				if (remove_acl(argv[optind], ACL_TYPE_ACCESS) == -1) {
					n++;
					fprintf(stderr,
						gettext("%s: error removing access acl on \"%s\": %s\n"),
						progname, argv[optind], strerror(errno));
				}
			}
			if (!opt_R) {
				if (remove_acl(argv[optind], ACL_TYPE_DEFAULT) == -1) {
					n++;
					fprintf(stderr,
						gettext("%s: error removing default acl on \"%s\": %s\n"),
						progname, argv[optind], strerror(errno));
				}
			}
		}
		return n;
	}

set:
	if (opt_d) {
		/* -d : set default acl only */
		dacl = acl_from_text(argv[optind]);
		status = acl_check(dacl, &c);
		if (status < 0)
			goto sys_error;
		if (status > 0)
			goto acl_invalid;
		optind++;
	} else {
		acl = acl_from_text(argv[optind]);
		status = acl_check(acl, &c);
		if (status < 0)
			goto sys_error;
		if (status > 0)
			goto acl_invalid;
		optind++;

		if (opt_b) {
			/* -b : the next argument is the default acl */
			dacl = acl_from_text(argv[optind]);
			status = acl_check(dacl, &c);
			if (status < 0)
				goto sys_error;
			if (status > 0)
				goto acl_invalid;
			optind++;
		}
	}

	for (; optind < argc; optind++)
		n += do_set(acl, dacl, argv[optind]);

	if (acl)
		acl_free(acl);
	if (dacl)
		acl_free(dacl);
	return n;

sys_error:
	fprintf(stderr, "%s: %s - %s\n",
		progname, argv[optind], strerror(errno));
	return 1;

acl_invalid:
	fprintf(stderr,
		gettext("%s: access ACL '%s': %s at entry %d\n"),
		progname, argv[optind], acl_error(status), c);
	return 1;
}


