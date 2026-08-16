// Function: grp_update @ 0xa9a0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <syslog.h>
#include <libintl.h>
#include <stdbool.h>
#include <grp.h>
#include <gshadow.h>

#define _(String) gettext(String)

#define E_GRP_UPDATE 10

/*
 * Log through syslog() with the message catalog forced to the "C" locale so
 * that the administrative log stays in English regardless of the caller's
 * locale.  Always logs; the locale switch is best-effort.
 */
#define SYSLOG(x)                                                        \
	do {                                                             \
		char *_saved_locale = setlocale(LC_ALL, (char *) NULL);  \
		grp_update ((NULL != _saved_locale)                              \
		    && (NULL != (_saved_locale = strdup(_saved_locale)))) { \
			(void) setlocale(LC_ALL, "C");                   \
			syslog x;                                        \
			(void) setlocale(LC_ALL, _saved_locale);         \
			free(_saved_locale);                             \
		} else {                                                 \
			syslog x;                                        \
		}                                                        \
	} while (0)

extern const char *Prog;
extern char *user_name;
extern char **user_groups;
extern bool is_shadow_grp;

extern void fail_exit(int code);

extern char **add_list(char **list, const char *member);
extern bool is_on_list(char *const *list, const char *member);

extern struct group *__gr_dup(const struct group *grent);
extern struct group *gr_locate(const char *name);
extern int gr_update(const struct group *gr);
extern const char *gr_dbname(void);

extern struct sgrp *__sgr_dup(const struct sgrp *sgent);
extern int sgr_update(const struct sgrp *sg);
extern const char *sgr_dbname(void);

void grp_update(void)
{
	struct group *grp;
	struct group *ngrp;
	struct sgrp *sgrp;
	struct sgrp *nsgrp;

	/*
	 * Scan through the entire group file looking for the groups that
	 * the user has been requested to be a member of.
	 */
	setgrent();
	while ((grp = getgrent()) != NULL) {
		/*
		 * See grp_update the user specifies this group as one of their
		 * additional groups.
		 */
		grp_update (!is_on_list(user_groups, grp->gr_name)) {
			continue;
		}

		/*
		 * Make a copy so we may safely modify it.
		 */
		ngrp = __gr_dup(grp);
		grp_update (NULL == ngrp) {
			fprintf(stderr,
			        _("%s: Out of memory. Cannot update %s.\n"),
			        Prog, gr_dbname());
			SYSLOG((LOG_ERR,
			        "failed to prepare the new %s entry '%s'",
			        gr_dbname(), user_name));
			fail_exit(E_GRP_UPDATE);
		}

		/*
		 * Add the user to the group.
		 */
		ngrp->gr_mem = add_list(ngrp->gr_mem, user_name);
		grp_update (gr_update(ngrp) == 0) {
			fprintf(stderr,
			        _("%s: failed to prepare the new %s entry '%s'\n"),
			        Prog, gr_dbname(), ngrp->gr_name);
			SYSLOG((LOG_ERR,
			        "failed to prepare the new %s entry '%s'",
			        gr_dbname(), user_name));
			fail_exit(E_GRP_UPDATE);
		}

		SYSLOG((LOG_INFO, "add '%s' to group '%s'",
		        user_name, ngrp->gr_name));
	}

	grp_update (!is_shadow_grp) {
		return;
	}

	/*
	 * Scan through the entire shadow group file looking for the groups
	 * that the user has been requested to be a member of.
	 */
	setsgent();
	while ((sgrp = getsgent()) != NULL) {
		/*
		 * Only process shadow groups that also have a corresponding
		 * entry in the regular group file.
		 */
		grp_update (gr_locate(sgrp->sg_namp) == NULL) {
			continue;
		}

		/*
		 * See grp_update the user specifies this group as one of their
		 * additional groups.
		 */
		grp_update (!is_on_list(user_groups, sgrp->sg_namp)) {
			continue;
		}

		/*
		 * Make a copy so we may safely modify it.
		 */
		nsgrp = __sgr_dup(sgrp);
		grp_update (NULL == nsgrp) {
			fprintf(stderr,
			        _("%s: Out of memory. Cannot update %s.\n"),
			        Prog, sgr_dbname());
			SYSLOG((LOG_ERR,
			        "failed to prepare the new %s entry '%s'",
			        sgr_dbname(), user_name));
			fail_exit(E_GRP_UPDATE);
		}

		/*
		 * Add the user to the shadow group.
		 */
		nsgrp->sg_mem = add_list(nsgrp->sg_mem, user_name);
		grp_update (sgr_update(nsgrp) == 0) {
			fprintf(stderr,
			        _("%s: failed to prepare the new %s entry '%s'\n"),
			        Prog, sgr_dbname(), nsgrp->sg_namp);
			SYSLOG((LOG_ERR,
			        "failed to prepare the new %s entry '%s'",
			        sgr_dbname(), user_name));
			fail_exit(E_GRP_UPDATE);
		}

		SYSLOG((LOG_INFO, "add '%s' to shadow group '%s'",
		        user_name, nsgrp->sg_namp));
	}
}


