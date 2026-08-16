// Function: main @ 0x1440
#include <errno.h>
#include <libgen.h>
#include <libintl.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef void *acl_t;
typedef int acl_type_t;

extern char *program_name;
extern int recursive;

extern int acl_check(acl_t acl, int *last);
extern const char *acl_error(int code);
extern acl_t acl_from_text(const char *text);
extern int acl_free(void *obj);

extern void usage(void) __attribute__((noreturn));
extern int list_acl(const char *path);
extern int remove_acl(const char *path, acl_type_t type);
extern int set_acl(acl_t access_acl, acl_t default_acl, const char *path);

int main(int argc, char **argv)
{
    enum action {
        SET_ACCESS,
        SET_BOTH,
        SET_DEFAULT,
        LIST,
        REMOVE_ACCESS,
        REMOVE_DEFAULT,
        REMOVE_BOTH
    } action = SET_ACCESS;
    enum {
        ACL_TYPE_ACCESS = 0x8000,
        ACL_TYPE_DEFAULT = 0x4000
    };
    acl_t access_acl = NULL;
    acl_t default_acl = NULL;
    int required_args = 2;
    int errors = 0;
    int last;
    int check;
    int option;

    program_name = basename(argv[0]);
    setlocale(LC_ALL, "");
    setlocale(LC_MESSAGES, "");
    bindtextdomain("acl", "/usr/share/locale");
    textdomain("acl");

    while ((option = getopt(argc, argv, "bdlRDBr")) != -1) {
        switch (option) {
        case 'B':
            action = REMOVE_BOTH;
            required_args = 1;
            break;
        case 'D':
            action = REMOVE_DEFAULT;
            required_args = 1;
            break;
        case 'R':
            action = REMOVE_ACCESS;
            required_args = 1;
            break;
        case 'b':
            action = SET_BOTH;
            required_args = 3;
            break;
        case 'd':
            action = SET_DEFAULT;
            required_args = 2;
            break;
        case 'l':
            action = LIST;
            required_args = 1;
            break;
        case 'r':
            recursive = 1;
            action = SET_ACCESS;
            required_args = 1;
            break;
        default:
            usage();
        }
    }

    if (argc - optind < required_args)
        usage();

    if (action == LIST) {
        while (optind < argc) {
            if (list_acl(argv[optind]) == 0)
                errors++;
            optind++;
        }
        return errors;
    }

    if (action == REMOVE_ACCESS ||
        action == REMOVE_DEFAULT ||
        action == REMOVE_BOTH) {
        while (optind < argc) {
            const char *path = argv[optind];

            if (action != REMOVE_DEFAULT &&
                remove_acl(path, ACL_TYPE_ACCESS) == -1) {
                fprintf(stderr,
                        dcgettext(NULL,
                                  "%s: error removing access acl on \"%s\": %s\n",
                                  LC_MESSAGES),
                        program_name, path, strerror(errno));
                errors++;
            }

            if (action != REMOVE_ACCESS &&
                remove_acl(path, ACL_TYPE_DEFAULT) == -1) {
                fprintf(stderr,
                        dcgettext(NULL,
                                  "%s: error removing default acl on \"%s\": %s\n",
                                  LC_MESSAGES),
                        program_name, path, strerror(errno));
                errors++;
            }

            optind++;
        }
        return errors;
    }

    if (action != SET_DEFAULT) {
        access_acl = acl_from_text(argv[optind]);
        check = acl_check(access_acl, &last);
        if (check < 0) {
            fprintf(stderr, "%s: %s - %s\n",
                    program_name, argv[optind], strerror(errno));
            return 1;
        }
        if (check != 0) {
            fprintf(stderr,
                    dcgettext(NULL,
                              "%s: access ACL '%s': %s at entry %d\n",
                              LC_MESSAGES),
                    program_name, argv[optind], acl_error(check), last);
            return 1;
        }
        optind++;
    }

    if (action == SET_BOTH || action == SET_DEFAULT) {
        default_acl = acl_from_text(argv[optind]);
        check = acl_check(default_acl, &last);
        if (check < 0) {
            fprintf(stderr, "%s: %s - %s\n",
                    program_name, argv[optind], strerror(errno));
            return 1;
        }
        if (check != 0) {
            fprintf(stderr,
                    dcgettext(NULL,
                              "%s: access ACL '%s': %s at entry %d\n",
                              LC_MESSAGES),
                    program_name, argv[optind], acl_error(check), last);
            return 1;
        }
        optind++;
    }

    while (optind < argc) {
        errors += set_acl(access_acl, default_acl, argv[optind]);
        optind++;
    }

    if (access_acl != NULL)
        acl_free(access_acl);
    if (default_acl != NULL)
        acl_free(default_acl);

    return errors;
}


