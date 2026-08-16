// Function: main @ 0x3d60
#include <getopt.h>
#include <libintl.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

#define _(msgid) dcgettext(NULL, (msgid), LC_MESSAGES)

extern const char *Prog;
extern bool quiet;

extern const char *Basename(const char *path);
extern void usage(int status) __attribute__((noreturn));
extern void process_root_flag(const char *option, int argc, char **argv);
extern void vipwedit(const char *file, int (*file_lock)(void),
                     int (*file_unlock)(void));

extern const char *gr_dbname(void);
extern int gr_lock(void);
extern int gr_unlock(void);
extern bool sgr_file_present(void);
extern const char *sgr_dbname(void);
extern int sgr_lock(void);
extern int sgr_unlock(void);

extern const char *pw_dbname(void);
extern int pw_lock(void);
extern int pw_unlock(void);
extern bool spw_file_present(void);
extern const char *spw_dbname(void);
extern int spw_lock(void);
extern int spw_unlock(void);

extern void nscd_set_progname(const char *progname);
extern void nscd_set_logfd(FILE *stream);
extern int nscd_flush_cache(const char *service);
extern int sssd_flush_cache(int databases);

int main(int argc, char **argv)
{
    enum {
        E_USAGE = 2,
        SSSD_DB_PASSWD = 1,
        SSSD_DB_GROUP = 2
    };
    static struct option long_options[] = {
        { "group",  no_argument,       NULL, 'g' },
        { "help",   no_argument,       NULL, 'h' },
        { "passwd", no_argument,       NULL, 'p' },
        { "quiet",  no_argument,       NULL, 'q' },
        { "root",   required_argument, NULL, 'R' },
        { "shadow", no_argument,       NULL, 's' },
        { NULL,      0,                 NULL,  0  }
    };
    bool do_vipw;
    bool do_shadow = false;
    int c;

    Prog = Basename(argv[0]);
    nscd_set_progname(Prog);
    nscd_set_logfd(stderr);

    setlocale(LC_ALL, "");
    bindtextdomain("libshadow", "/usr/share/locale");
    textdomain("libshadow");

    process_root_flag("-R", argc, argv);

    do_vipw = strcmp(Prog, "vigr") != 0;
    openlog(do_vipw ? "vipw" : "vigr", LOG_PID, LOG_AUTHPRIV);

    while ((c = getopt_long(argc, argv, "ghpqR:s", long_options, NULL)) != -1) {
        switch (c) {
        case 'g':
            do_vipw = false;
            break;
        case 'h':
            usage(EXIT_SUCCESS);
        case 'p':
            do_vipw = true;
            break;
        case 'q':
            quiet = true;
            break;
        case 'R':
            break;
        case 's':
            do_shadow = true;
            break;
        default:
            usage(E_USAGE);
        }
    }

    if (optind != argc)
        usage(E_USAGE);

    if (do_vipw) {
        if (do_shadow) {
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
        if (do_shadow) {
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
    sssd_flush_cache(SSSD_DB_PASSWD | SSSD_DB_GROUP);

    return EXIT_SUCCESS;
}


