// Function: main @ 0x3920
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <getopt.h>
#include <libintl.h>
#include <locale.h>
#include <sys/stat.h>

#define main(msgid) dcgettext(NULL, (msgid), LC_MESSAGES)

int
main(int argc, char **argv)
{
    enum {
        CH_ATIME = 1,
        CH_MTIME = 2,
        CH_BOTH = CH_ATIME | CH_MTIME,
        TIME_OPTION = 128,
        GETOPT_HELP_CHAR = -130,
        GETOPT_VERSION_CHAR = -131,
        PDS_CENTURY = 2,
        PDS_SECONDS = 4,
        PDS_TRAILING_YEAR = 1,
        PDS_PRE_2000 = 8,
        UTIME_NOW_VALUE = 1073741823
    };

    static const char *const time_args[] = {
        "atime", "access", "use", "mtime", "modify", NULL
    };
    static const int time_types[] = {
        CH_ATIME, CH_ATIME, CH_ATIME, CH_MTIME, CH_MTIME
    };
    static const struct option long_options[] = {
        { "time",           required_argument, NULL, TIME_OPTION },
        { "no-create",      no_argument,       NULL, 'c' },
        { "date",           required_argument, NULL, 'd' },
        { "reference",      required_argument, NULL, 'r' },
        { "no-dereference", no_argument,       NULL, 'h' },
        { "help",           no_argument,       NULL, GETOPT_HELP_CHAR },
        { "version",        no_argument,       NULL, GETOPT_VERSION_CHAR },
        { NULL,              0,                 NULL, 0 }
    };

    extern const char *Version;
    extern const char *ref_file;
    extern bool reference_file;
    extern bool amtime_now;
    extern bool no_dereference;
    extern bool no_create;
    extern int change_times;
    extern struct timespec newtime[2];

    extern void set_program_name(const char *);
    extern void close_stdout(void);
    extern void usage(int);
    extern void version_etc(FILE *, const char *, const char *, const char *, ...);
    extern void error(int, int, const char *, ...);
    extern const char *quote(const char *);
    extern const char *quotearg_style(int, const char *);
    extern ptrdiff_t __xargmatch_internal(const char *, const char *,
                                         const char *const *, const void *,
                                         size_t, void (*)(void), bool);
    extern void argmatch_die(void);
    extern bool posixtime(time_t *, const char *, unsigned int);
    extern int posix2_version(void);
    extern void gettime(struct timespec *);
    extern void parse_datetime_arg(struct timespec *, const char *,
                                   const struct timespec *);
    extern struct timespec get_stat_atime(const struct stat *);
    extern struct timespec get_stat_mtime(const struct stat *);
    extern bool touch(const char *);

    const char *flex_date = NULL;
    bool date_set = false;
    bool timestamps_specified;
    struct timespec now;
    struct timespec not_now;
    struct timespec reparsed;
    struct stat ref_stats;
    int c;

    set_program_name(argv[0]);
    setlocale(LC_ALL, "");
    bindtextdomain("coreutils", "/usr/local/share/locale");
    textdomain("coreutils");
    atexit(close_stdout);

    reference_file = false;
    change_times = 0;
    no_create = false;

    while ((c = getopt_long(argc, argv, "acd:fhmr:t:", long_options, NULL)) != -1) {
        switch (c) {
        case 'a':
            change_times |= CH_ATIME;
            break;

        case 'c':
            no_create = true;
            break;

        case 'd':
            flex_date = optarg;
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
            ref_file = optarg;
            reference_file = true;
            break;

        case 't':
            if (!posixtime(&newtime[0].tv_sec, optarg,
                           PDS_CENTURY | PDS_SECONDS))
                error(EXIT_FAILURE, 0, main("invalid date format %s"), quote(optarg));
            newtime[0].tv_nsec = 0;
            newtime[1] = newtime[0];
            date_set = true;
            break;

        case TIME_OPTION:
            change_times |= time_types[__xargmatch_internal(
                "--time", optarg, time_args, time_types, sizeof time_types[0],
                argmatch_die, true)];
            break;

        case GETOPT_HELP_CHAR:
            usage(EXIT_SUCCESS);
            break;

        case GETOPT_VERSION_CHAR:
            version_etc(stdout, "touch", "GNU coreutils", Version,
                        "Paul Rubin", "Arnold Robbins", "Jim Kingdon",
                        "David MacKenzie", "Randy Smith", NULL);
            exit(EXIT_SUCCESS);

        default:
            usage(EXIT_FAILURE);
        }
    }

    if (change_times == 0)
        change_times = CH_BOTH;

    if (date_set && (flex_date != NULL || reference_file)) {
        error(0, 0, main("cannot specify times from more than one source"));
        usage(EXIT_FAILURE);
    }

    timestamps_specified = date_set;

    if (!date_set && reference_file) {
        int status;

        if (no_dereference)
            status = lstat(ref_file, &ref_stats);
        else
            status = stat(ref_file, &ref_stats);

        if (status != 0)
            error(EXIT_FAILURE, errno, main("failed to get attributes of %s"),
                  quotearg_style(4, ref_file));

        newtime[0] = get_stat_atime(&ref_stats);
        newtime[1] = get_stat_mtime(&ref_stats);
        timestamps_specified = true;

        if (flex_date != NULL) {
            if (change_times & CH_ATIME)
                parse_datetime_arg(&newtime[0], flex_date, &newtime[0]);
            if (change_times & CH_MTIME)
                parse_datetime_arg(&newtime[1], flex_date, &newtime[1]);
        }
    } else if (!date_set && flex_date != NULL) {
        gettime(&now);
        parse_datetime_arg(&newtime[0], flex_date, &now);
        newtime[1] = newtime[0];
        timestamps_specified = true;

        if (change_times == CH_BOTH
            && newtime[0].tv_sec == now.tv_sec
            && newtime[0].tv_nsec == now.tv_nsec) {
            not_now = now;
            not_now.tv_sec ^= 1;
            parse_datetime_arg(&reparsed, flex_date, &not_now);
            if (reparsed.tv_sec == not_now.tv_sec
                && reparsed.tv_nsec == not_now.tv_nsec)
                timestamps_specified = false;
        }
    }

    if (!timestamps_specified) {
        if (argc - optind > 1
            && posix2_version() <= 200111
            && posixtime(&newtime[0].tv_sec, argv[optind],
                         PDS_TRAILING_YEAR | PDS_PRE_2000)) {
            struct tm *tm;

            newtime[0].tv_nsec = 0;
            newtime[1] = newtime[0];

            if (getenv("POSIXLY_CORRECT") == NULL) {
                tm = localtime(&newtime[0].tv_sec);
                if (tm != NULL)
                    error(0, 0,
                          main("warning: 'touch %s' is obsolete; use "
                            "'touch -t %04ld%02d%02d%02d%02d.%02d'"),
                          argv[optind], (long) tm->tm_year + 1900,
                          tm->tm_mon + 1, tm->tm_mday, tm->tm_hour,
                          tm->tm_min, tm->tm_sec);
            }
            ++optind;
        } else if (change_times == CH_BOTH) {
            amtime_now = true;
        } else {
            newtime[0].tv_nsec = UTIME_NOW_VALUE;
            newtime[1].tv_nsec = UTIME_NOW_VALUE;
        }
    }

    if (optind == argc) {
        error(0, 0, main("missing file operand"));
        usage(EXIT_FAILURE);
    }

    {
        bool ok = true;

        while (optind < argc) {
            ok &= touch(argv[optind]);
            ++optind;
        }
        return ok ? EXIT_SUCCESS : EXIT_FAILURE;
    }
}


