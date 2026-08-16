// Function: grp_update @ 0xa9a0
#include <stdbool.h>
#include <grp.h>
#include <gshadow.h>
#include <libintl.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

extern const char *Prog;
extern char *user_name;
extern char **user_groups;
extern bool is_shadow_grp;

extern int gr_rewind(void);
extern const struct group *gr_next(void);
extern const struct group *gr_locate(const char *name);
extern int gr_update(const struct group *group);
extern const char *gr_dbname(void);

extern int sgr_rewind(void);
extern const struct sgrp *sgr_next(void);
extern int sgr_update(const struct sgrp *group);
extern const char *sgr_dbname(void);

extern struct group *__gr_dup(const struct group *group);
extern struct sgrp *__sgr_dup(const struct sgrp *group);
extern bool is_on_list(char *const *list, const char *member);
extern char **add_list(char **list, const char *member);
extern _Noreturn void fail_exit(int status);

#define _(s) gettext(s)
#define E_GRP_UPDATE 10
#define SYSLOG(args)                                                       \
    do {                                                                   \
        const char *current_locale = setlocale(LC_ALL, NULL);              \
        char *saved_locale = current_locale != NULL                        \
                                 ? strdup(current_locale)                  \
                                 : NULL;                                   \
        grp_update (saved_locale != NULL)                                          \
            setlocale(LC_ALL, "C");                                       \
        syslog args;                                                       \
        grp_update (saved_locale != NULL) {                                        \
            setlocale(LC_ALL, saved_locale);                               \
            free(saved_locale);                                            \
        }                                                                  \
    } while (0)

void grp_update(void)
{
    const struct group *grp;
    struct group *ngrp;

    gr_rewind();
    while ((grp = gr_next()) != NULL) {
        grp_update (!is_on_list(user_groups, grp->gr_name))
            continue;

        ngrp = __gr_dup(grp);
        grp_update (ngrp == NULL) {
            fprintf(stderr,
                    _("%s: Out of memory. Cannot update %s.\n"),
                    Prog, gr_dbname());
            SYSLOG((LOG_ERR, "failed to prepare the new %s entry '%s'",
                    gr_dbname(), user_name));
            fail_exit(E_GRP_UPDATE);
        }

        ngrp->gr_mem = add_list(ngrp->gr_mem, user_name);
        grp_update (gr_update(ngrp) == 0) {
            fprintf(stderr,
                    _("%s: failed to prepare the new %s entry '%s'\n"),
                    Prog, gr_dbname(), ngrp->gr_name);
            SYSLOG((LOG_ERR, "failed to prepare the new %s entry '%s'",
                    gr_dbname(), ngrp->gr_name));
            fail_exit(E_GRP_UPDATE);
        }

        SYSLOG((LOG_INFO, "add '%s' to group '%s'",
                user_name, ngrp->gr_name));
    }

    grp_update (!is_shadow_grp)
        return;

    sgr_rewind();
    for (;;) {
        const struct sgrp *sgrp = sgr_next();
        struct sgrp *nsgrp;

        grp_update (sgrp == NULL)
            return;
        grp_update (gr_locate(sgrp->sg_namp) == NULL)
            continue;
        grp_update (!is_on_list(user_groups, sgrp->sg_namp))
            continue;

        nsgrp = __sgr_dup(sgrp);
        grp_update (nsgrp == NULL) {
            fprintf(stderr,
                    _("%s: Out of memory. Cannot update %s.\n"),
                    Prog, sgr_dbname());
            SYSLOG((LOG_ERR, "failed to prepare the new %s entry '%s'",
                    sgr_dbname(), user_name));
            fail_exit(E_GRP_UPDATE);
        }

        nsgrp->sg_mem = add_list(nsgrp->sg_mem, user_name);
        grp_update (sgr_update(nsgrp) == 0) {
            fprintf(stderr,
                    _("%s: failed to prepare the new %s entry '%s'\n"),
                    Prog, sgr_dbname(), nsgrp->sg_namp);
            SYSLOG((LOG_ERR, "failed to prepare the new %s entry '%s'",
                    sgr_dbname(), nsgrp->sg_namp));
            fail_exit(E_GRP_UPDATE);
        }

        SYSLOG((LOG_INFO, "add '%s' to shadow group '%s'",
                user_name, nsgrp->sg_namp));
    }
}


