// Function: grp_update @ 0x62e0
#include <gshadow.h>
#include <grp.h>
#include <libintl.h>
#include <pwd.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

extern const char *Prog;
extern char *group_name;
extern char *user_list;
extern gid_t group_newid;
extern bool aflg;
extern bool gflg;
extern bool nflg;
extern bool pflg;
extern bool is_shadow_grp;
extern char *empty_list;

extern const struct group *gr_locate(const char *name);
extern int gr_update(const struct group *group);
extern int gr_remove(const char *name);
extern const char *gr_dbname(void);
extern const struct sgrp *sgr_locate(const char *name);
extern int sgr_update(const struct sgrp *group);
extern int sgr_remove(const char *name);
extern const char *sgr_dbname(void);
extern void update_group(struct group *group);
extern void update_gshadow(struct sgrp *group);
extern void update_primary_groups(gid_t old_gid, gid_t new_gid);
extern void gr_free_members(struct group *group);
extern char **dup_list(char *const *list);
extern char **add_list(char *const *list, const char *member);
extern void *xmalloc(size_t size);
extern char *xstrdup(const char *string);
extern struct passwd *prefix_getpwnam(const char *name);

void grp_update(void)
{
    const struct group *group;
    const struct sgrp *shadow_group = NULL;
    struct group group_entry;
    struct sgrp shadow_entry;
    char *member;

    group = gr_locate(group_name);
    if (group == NULL) {
        fprintf(stderr,
                gettext("%s: group '%s' does not exist in %s\n"),
                Prog, group_name, gr_dbname());
        exit(10);
    }

    group_entry = *group;
    update_group(&group_entry);

    if (is_shadow_grp && (pflg || nflg)) {
        shadow_group = sgr_locate(group_name);
        if (shadow_group != NULL) {
            shadow_entry = *shadow_group;
            update_gshadow(&shadow_entry);
        } else if (pflg && strcmp(group_entry.gr_passwd, "x") == 0) {
            memset(&shadow_entry, 0, sizeof(shadow_entry));
            shadow_entry.sg_name = xstrdup(group_entry.gr_name);
            shadow_entry.sg_passwd = xstrdup(group_entry.gr_passwd);
            shadow_entry.sg_adm = &empty_list;
            shadow_entry.sg_mem = dup_list(group_entry.gr_mem);
            update_gshadow(&shadow_entry);
            shadow_group = &shadow_entry;
        }
    }

    if (gflg) {
        update_primary_groups(group->gr_gid, group_newid);
    }

    if (user_list != NULL) {
        if (aflg) {
            if (group_entry.gr_mem[0] != NULL) {
                group_entry.gr_mem = dup_list(group_entry.gr_mem);
            }
        } else {
            if (group_entry.gr_mem[0] != NULL) {
                gr_free_members(&group_entry);
            }
            group_entry.gr_mem = xmalloc(sizeof(*group_entry.gr_mem));
            group_entry.gr_mem[0] = NULL;
        }

        for (member = strtok(user_list, ",");
             member != NULL;
             member = strtok(NULL, ",")) {
            if (prefix_getpwnam(member) == NULL) {
                fprintf(stderr,
                        gettext("Invalid member username %s\n"), member);
                exit(10);
            }
            group_entry.gr_mem = add_list(group_entry.gr_mem, member);
        }
    }

    if (!gr_update(&group_entry)) {
        fprintf(stderr,
                gettext("%s: failed to prepare the new %s entry '%s'\n"),
                Prog, gr_dbname(), group_entry.gr_name);
        exit(10);
    }

    if (nflg && !gr_remove(group_name)) {
        fprintf(stderr,
                gettext("%s: cannot remove entry '%s' from %s\n"),
                Prog, group_entry.gr_name, gr_dbname());
        exit(10);
    }

    if (shadow_group != NULL) {
        if (!sgr_update(&shadow_entry)) {
            fprintf(stderr,
                    gettext("%s: failed to prepare the new %s entry '%s'\n"),
                    Prog, sgr_dbname(), shadow_entry.sg_name);
            exit(10);
        }

        if (nflg && !sgr_remove(group_name)) {
            fprintf(stderr,
                    gettext("%s: cannot remove entry '%s' from %s\n"),
                    Prog, group_name, sgr_dbname());
            exit(10);
        }
    }
}


