// Function: main @ 0x3920
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <locale.h>
#include <getopt.h>
#include <sys/stat.h>
#include <sys/types.h>

/* --- Definitions the original touch.c relies on --------------------------- */

#define PROGRAM_NAME "touch"
#define PACKAGE "coreutils"
#define PACKAGE_NAME "GNU coreutils"
#define LOCALEDIR "/usr/local/share/locale"

#define EXIT_FAILURE_STATUS 1

/* i18n helpers (gettext). */
extern char *dcgettext (const char *, const char *, int);
#define _(msgid) dcgettext (NULL, msgid, 5 /* LC_MESSAGES */)

/* getopt "help"/"version" pseudo option characters used by coreutils. */
enum
{
  GETOPT_HELP_CHAR = -130,
  GETOPT_VERSION_CHAR = -131
};

/* Long option that has no short equivalent. */
enum { TIME_OPTION = CHAR_MAX + 1 };

/* Bitmasks for 'change_times'. */
#define CH_ATIME 1
#define CH_MTIME 2

/* Syntax bits understood by posixtime(). */
enum
{
  PDS_LEADING_YEAR  = 1,
  PDS_TRAILING_YEAR = 2,
  PDS_CENTURY       = 4,
  PDS_SECONDS       = 8
};

#ifndef UTIME_NOW
# define UTIME_NOW ((1l << 30) - 1)
#endif

/* Author names for --version. */
extern char const *proper_name (char const *name);
extern char const *Version;

/* Externals implemented elsewhere in the program / gnulib. */
extern void set_program_name (char const *argv0);
extern void close_stdout (void);
extern void usage (int status) __attribute__ ((noreturn));
extern void version_etc (FILE *stream, const char *command_name,
                         const char *package, const char *version, ...);
extern void error (int status, int errnum, const char *format, ...);

extern bool touch (char const *file);
extern bool posixtime (time_t *p, char const *s, unsigned int syntax_bits);
extern bool parse_datetime (struct timespec *result, char const *p,
                            struct timespec const *now);
extern void gettime (struct timespec *ts);
extern struct timespec get_stat_atime (struct stat const *st);
extern struct timespec get_stat_mtime (struct stat const *st);
extern char const *quote (char const *arg);
extern char const *quoteaf (char const *arg);
extern int posix2_version (void);

extern ptrdiff_t __xargmatch_internal (char const *context, char const *arg,
                                       char const *const *arglist,
                                       char const *vallist, size_t valsize,
                                       void *exit_fn, bool allow_abbreviation);
extern void argmatch_die (void);
#define XARGMATCH(Context, Arg, Arglist, Vallist)                       \
  ((Vallist)[__xargmatch_internal (Context, Arg, Arglist,               \
                                   (char const *) (Vallist),            \
                                   sizeof *(Vallist),                   \
                                   (void *) argmatch_die, true)])

/* --- File-scope state ----------------------------------------------------- */

/* If true, the only thing we have to do is change both the access and
   modification times to the current time. */
static bool amtime_now;

/* (-h) If true, change the times of a symbolic link rather than the
   referenced file. */
static bool no_dereference;

/* If true, use a reference file for times. */
static bool use_ref;

/* (-c) If true, don't create files that don't already exist. */
static bool no_create;

/* The file whose times we take with -r. */
static char const *ref_file;

/* New access and modification times to use when setting time.  */
static struct timespec newtime[2];

/* Bitmask of which of the times to change: CH_ATIME, CH_MTIME. */
static int change_times;

static char const *const time_args[] =
{
  "atime", "access", "use", "mtime", "modify", NULL
};

static int const time_masks[] =
{
  CH_ATIME, CH_ATIME, CH_ATIME, CH_MTIME, CH_MTIME
};

static struct option const longopts[] =
{
  {"time", required_argument, NULL, TIME_OPTION},
  {"no-create", no_argument, NULL, 'c'},
  {"date", required_argument, NULL, 'd'},
  {"reference", required_argument, NULL, 'r'},
  {"no-dereference", no_argument, NULL, 'h'},
  {"help", no_argument, NULL, GETOPT_HELP_CHAR},
  {"version", no_argument, NULL, GETOPT_VERSION_CHAR},
  {NULL, 0, NULL, 0}
};

/* --- The reconstructed target main (0x3920) --------------------------- */

int
main (int argc, char **argv)
{
  int c;
  bool date_set = false;
  bool ok = true;
  char const *flexible_date = NULL;

  set_program_name (argv[0]);
  setlocale (LC_ALL, "");
  bindtextdomain (PACKAGE, LOCALEDIR);
  textdomain (PACKAGE);

  atexit (close_stdout);

  change_times = 0;
  no_create = use_ref = false;

  while ((c = getopt_long (argc, argv, "acd:fhmr:t:", longopts, NULL)) != -1)
    {
      switch (c)
        {
        case 'a':
          change_times |= CH_ATIME;
          break;

        case 'c':
          no_create = true;
          break;

        case 'd':
          flexible_date = optarg;
          break;

        case 'f':
          break;

        case 'h':
          no_dereference = true;
          break;

        case 'm':
          change_times |= CH_MTIME;
          break;

        case 'r':
          use_ref = true;
          ref_file = optarg;
          break;

        case 't':
          if (! posixtime (&newtime[0].tv_sec, optarg,
                           PDS_LEADING_YEAR | PDS_CENTURY | PDS_SECONDS))
            error (EXIT_FAILURE_STATUS, 0, _("invalid date format %s"),
                   quote (optarg));
          newtime[0].tv_nsec = 0;
          newtime[1] = newtime[0];
          date_set = true;
          break;

        case TIME_OPTION:
          change_times |= XARGMATCH ("--time", optarg, time_args, time_masks);
          break;

        case GETOPT_HELP_CHAR:
          usage (EXIT_SUCCESS);

        case GETOPT_VERSION_CHAR:
          version_etc (stdout, PROGRAM_NAME, PACKAGE_NAME, Version,
                       proper_name ("Paul Rubin"),
                       proper_name ("Arnold Robbins"),
                       proper_name ("Jim Kingdon"),
                       proper_name ("David MacKenzie"),
                       proper_name ("Randy Smith"),
                       (char *) NULL);
          exit (EXIT_SUCCESS);

        default:
          usage (EXIT_FAILURE_STATUS);
        }
    }

  if (change_times == 0)
    change_times = CH_ATIME | CH_MTIME;

  if (date_set && (use_ref || flexible_date))
    {
      error (0, 0, _("cannot specify times from more than one source"));
      usage (EXIT_FAILURE_STATUS);
    }

  if (use_ref)
    {
      struct stat ref_stats;

      /* Don't dereference symlinks when -h was given.  */
      if ((no_dereference ? lstat : stat) (ref_file, &ref_stats))
        error (EXIT_FAILURE_STATUS, errno,
               _("failed to get attributes of %s"), quoteaf (ref_file));

      newtime[0] = get_stat_atime (&ref_stats);
      newtime[1] = get_stat_mtime (&ref_stats);
      date_set = true;

      if (flexible_date)
        {
          if (change_times & CH_ATIME)
            parse_datetime (&newtime[0], flexible_date, &newtime[0]);
          if (change_times & CH_MTIME)
            parse_datetime (&newtime[1], flexible_date, &newtime[1]);
        }
    }

  if (! date_set && flexible_date)
    {
      struct timespec now;

      gettime (&now);
      parse_datetime (&newtime[0], flexible_date, &now);
      newtime[1] = newtime[0];
      date_set = true;

      /* If the resulting time is exactly "now", the date may have been a
         relative expression such as "now"; re-parse it against a slightly
         different reference to find out, and if so fall back to the
         current-time handling below. */
      if (change_times == (CH_ATIME | CH_MTIME)
          && newtime[0].tv_sec == now.tv_sec
          && newtime[0].tv_nsec == now.tv_nsec)
        {
          struct timespec notnow, notnow_ts;

          notnow.tv_sec = now.tv_sec ^ 1;
          notnow.tv_nsec = now.tv_nsec;
          if (parse_datetime (&notnow_ts, flexible_date, &notnow)
              && notnow_ts.tv_sec == notnow.tv_sec
              && notnow_ts.tv_nsec == notnow.tv_nsec)
            date_set = false;
        }
    }

  if (! date_set)
    {
      /* Try the obsolete 'touch [-acm] MMDDhhmm[YY] FILE...' form, but only
         when there are at least two operands and POSIX allows it.  */
      if (2 <= argc - optind
          && posix2_version () < 200112
          && posixtime (&newtime[0].tv_sec, argv[optind],
                        PDS_TRAILING_YEAR | PDS_CENTURY | PDS_SECONDS))
        {
          newtime[0].tv_nsec = 0;
          newtime[1] = newtime[0];

          if (! getenv ("POSIXLY_CORRECT"))
            {
              struct tm const *tm = localtime (&newtime[0].tv_sec);

              if (tm)
                error (0, 0,
                       _("warning: 'touch %s' is obsolete; use "
                         "'touch -t %04ld%02d%02d%02d%02d.%02d'"),
                       argv[optind],
                       tm->tm_year + 1900L, tm->tm_mon + 1, tm->tm_mday,
                       tm->tm_hour, tm->tm_min, tm->tm_sec);
            }

          ++optind;
        }
      else if (change_times == (CH_ATIME | CH_MTIME))
        amtime_now = true;
      else
        newtime[0].tv_nsec = newtime[1].tv_nsec = UTIME_NOW;
    }

  if (optind == argc)
    {
      error (0, 0, _("missing file operand"));
      usage (EXIT_FAILURE_STATUS);
    }

  for (; optind < argc; ++optind)
    ok &= touch (argv[optind]);

  return ! ok;
}


