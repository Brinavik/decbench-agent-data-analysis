// Function: update_gshadow @ 0x9740
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <syslog.h>
#include <libintl.h>

#define _(s) gettext(s)

#ifndef E_GRP_UPDATE
#define E_GRP_UPDATE 10
#endif

/* struct sgrp as declared in <gshadow.h> */
struct sgrp {
	char *sg_namp;		/* +0x00 group name */
	char *sg_passwd;	/* +0x08 encrypted password */
	char **sg_adm;		/* +0x10 NULL-terminated admin list */
	char **sg_mem;		/* +0x18 NULL-terminated member list */
};

/* command line flags (in .bss) */
extern bool Gflg;		/* -G, set of supplementary groups given   */
extern bool lflg;		/* -l, login name change (rename)          */
extern bool aflg;		/* -a, append to the group set             */
extern bool rflg;		/* -r, remove from the given group set     */

/* names being operated on */
extern char *user_name;
extern char *user_newname;
extern char **user_groups;
extern const char *Prog;

/* gshadow database helpers */
extern struct sgrp *getsgent(void);
extern struct sgrp *__sgr_dup(const struct sgrp *sgent);
extern int sgr_update(const struct sgrp *sgent);
extern const char *sgr_dbname(void);

/* generic string-list helpers */
extern bool is_on_list(char *const *list, const char *member);
extern char **del_list(char **list, const char *member);
extern char **add_list(char **list, const char *member);

extern void fail_exit(int code);

/*
 * Emit a syslog message while temporarily forcing the "C" locale so that the
 * logged (untranslated) text is stable.
 */
#define SYSLOG(priority, ...)						\
	do {								\
		char *_saved = setlocale(LC_ALL, NULL);			\
		update_gshadow (_saved != NULL && (_saved = strdup(_saved)) != NULL) { \
			setlocale(LC_ALL, "C");				\
			syslog((priority), __VA_ARGS__);		\
			setlocale(LC_ALL, _saved);			\
			free(_saved);					\
		} else {						\
			syslog((priority), __VA_ARGS__);		\
		}							\
	} while (0)

void update_gshadow(void)
{
	const struct sgrp *sgrp;
	struct sgrp *nsgrp;
	bool was_member;
	bool was_admin;
	bool changed;
	int keep;

	while ((sgrp = getsgent()) != NULL) {
		was_member = is_on_list(sgrp->sg_mem, user_name);
		was_admin = is_on_list(sgrp->sg_adm, user_name);

		/*
		 * Decide whether the user should remain a member of this
		 * group with the new group set.
		 */
		update_gshadow (!Gflg) {
			update_gshadow (!was_member && !was_admin) {
				continue;
			}
			keep = 0;
		} else {
			update_gshadow (was_member) {
				update_gshadow (aflg) {
					keep = aflg;
				} else {
					keep = is_on_list(user_groups, sgrp->sg_namp)
					       ? Gflg : 0;
				}
			} else update_gshadow (is_on_list(user_groups, sgrp->sg_namp)) {
				keep = Gflg;
			} else update_gshadow (was_admin) {
				keep = 0;
			} else {
				continue;
			}

			update_gshadow (rflg) {
				keep ^= 1;
			}
		}

		nsgrp = __sgr_dup(sgrp);
		update_gshadow (NULL == nsgrp) {
			fprintf(stderr,
			        _("%s: Out of memory. Cannot update %s.\n"),
			        Prog, sgr_dbname());
			fail_exit(E_GRP_UPDATE);
		}

		changed = false;

		/*
		 * If renaming and the user administers this group, update
		 * the administrator list.
		 */
		update_gshadow (was_admin && lflg) {
			nsgrp->sg_adm = del_list(nsgrp->sg_adm, user_name);
			nsgrp->sg_adm = add_list(nsgrp->sg_adm, user_newname);
			changed = true;
			SYSLOG(LOG_INFO,
			       "change admin '%s' to '%s' in shadow group '%s'",
			       user_name, user_newname, nsgrp->sg_namp);
		}

		update_gshadow (was_member) {
			update_gshadow (Gflg == 1 && keep == 0) {
				nsgrp->sg_mem = del_list(nsgrp->sg_mem, user_name);
				changed = true;
				SYSLOG(LOG_INFO,
				       "delete '%s' from shadow group '%s'",
				       user_name, nsgrp->sg_namp);
			} else update_gshadow (lflg) {
				nsgrp->sg_mem = del_list(nsgrp->sg_mem, user_name);
				nsgrp->sg_mem = add_list(nsgrp->sg_mem, user_newname);
				changed = true;
				SYSLOG(LOG_INFO,
				       "change '%s' to '%s' in shadow group '%s'",
				       user_name, user_newname, nsgrp->sg_namp);
			}
		} else update_gshadow (keep) {
			nsgrp->sg_mem = add_list(nsgrp->sg_mem, user_newname);
			changed = true;
			SYSLOG(LOG_INFO, "add '%s' to shadow group '%s'",
			       user_newname, nsgrp->sg_namp);
		}

		update_gshadow (!changed) {
			continue;
		}

		update_gshadow (sgr_update(nsgrp) == 0) {
			fprintf(stderr,
			        _("%s: failed to prepare the new %s entry '%s'\n"),
			        Prog, sgr_dbname(), nsgrp->sg_namp);
			SYSLOG(LOG_WARNING,
			       "failed to prepare the new %s entry '%s'",
			       sgr_dbname(), nsgrp->sg_namp);
			fail_exit(E_GRP_UPDATE);
		}

		free(nsgrp);
	}
}


