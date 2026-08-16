// Function: update_gshadow @ 0x9740
#include <gshadow.h>
#include <libintl.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

extern const char *Prog;
extern char *user_name;
extern char *user_newname;
extern char **user_groups;

extern bool aflg;
extern bool Gflg;
extern bool lflg;
extern bool rflg;

extern const struct sgrp *sgr_next(void);
extern struct sgrp *__sgr_dup(const struct sgrp *);
extern int sgr_update(const struct sgrp *);
extern const char *sgr_dbname(void);
extern bool is_on_list(char *const *, const char *);
extern char **add_list(char **, const char *);
extern char **del_list(char **, const char *);
extern void fail_exit(int) __attribute__((noreturn));

void update_gshadow(void)
{
    enum { E_GRP_UPDATE = 10 };
    const struct sgrp *sgrp;
    struct sgrp *nsgrp;
    bool was_member;
    bool was_admin;
    bool is_member;
    bool changed;

#define SYSLOG_C(priority, ...)                                              \
    do {                                                                     \
        const char *current_locale = setlocale(LC_ALL, NULL);                \
        char *saved_locale = current_locale != NULL                          \
                                 ? strdup(current_locale)                    \
                                 : NULL;                                     \
        if (saved_locale != NULL) {                                          \
            setlocale(LC_ALL, "C");                                         \
        }                                                                    \
        syslog((priority), __VA_ARGS__);                                     \
        if (saved_locale != NULL) {                                          \
            setlocale(LC_ALL, saved_locale);                                \
            free(saved_locale);                                             \
        }                                                                    \
    } while (0)

    while ((sgrp = sgr_next()) != NULL) {
        was_member = is_on_list(sgrp->sg_mem, user_name);
        was_admin = is_on_list(sgrp->sg_adm, user_name);
        is_member = Gflg;

        if (Gflg) {
            if (was_member) {
                if (aflg) {
                    is_member = true;
                } else {
                    is_member = is_on_list(user_groups, sgrp->sg_namp);
                }
            } else {
                is_member = is_on_list(user_groups, sgrp->sg_namp);
                if (!is_member && !was_admin) {
                    continue;
                }
            }

            if (rflg) {
                is_member = !is_member;
            }
        } else if (!was_member && !was_admin) {
            continue;
        }

        nsgrp = __sgr_dup(sgrp);
        if (nsgrp == NULL) {
            fprintf(stderr,
                    gettext("%s: Out of memory. Cannot update %s.\n"),
                    Prog, sgr_dbname());
            fail_exit(E_GRP_UPDATE);
        }

        changed = false;

        if (was_admin && lflg) {
            nsgrp->sg_adm = del_list(nsgrp->sg_adm, user_name);
            nsgrp->sg_adm = add_list(nsgrp->sg_adm, user_newname);
            SYSLOG_C(LOG_INFO,
                     "change admin '%s' to '%s' in shadow group '%s'",
                     user_name, user_newname, nsgrp->sg_namp);
            changed = true;
        }

        if (was_member) {
            if (Gflg && !is_member) {
                nsgrp->sg_mem = del_list(nsgrp->sg_mem, user_name);
                SYSLOG_C(LOG_INFO, "delete '%s' from shadow group '%s'",
                         user_name, nsgrp->sg_namp);
                changed = true;
            } else if (lflg) {
                nsgrp->sg_mem = del_list(nsgrp->sg_mem, user_name);
                nsgrp->sg_mem = add_list(nsgrp->sg_mem, user_newname);
                SYSLOG_C(LOG_INFO,
                         "change '%s' to '%s' in shadow group '%s'",
                         user_name, user_newname, nsgrp->sg_namp);
                changed = true;
            }
        } else if (is_member) {
            nsgrp->sg_mem = add_list(nsgrp->sg_mem, user_newname);
            SYSLOG_C(LOG_INFO, "add '%s' to shadow group '%s'",
                     user_newname, nsgrp->sg_namp);
            changed = true;
        }

        if (!changed) {
            continue;
        }

        if (sgr_update(nsgrp) == 0) {
            fprintf(stderr,
                    gettext("%s: failed to prepare the new %s entry '%s'\n"),
                    Prog, sgr_dbname(), nsgrp->sg_namp);
            SYSLOG_C(LOG_WARNING,
                     "failed to prepare the new %s entry '%s'",
                     sgr_dbname(), nsgrp->sg_namp);
            fail_exit(E_GRP_UPDATE);
        }

        free(nsgrp);
    }

#undef SYSLOG_C
}


