// Function: grp_update @ 0x62e0
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* On-disk group record (see <grp.h>). */
struct group {
	char   *gr_name;	/* +0x00 */
	char   *gr_passwd;	/* +0x08 */
	gid_t   gr_gid;		/* +0x10 */
	char  **gr_mem;		/* +0x18 */
};

/* On-disk shadow-group record (see <gshadow.h>). */
struct sgrp {
	char   *sg_namp;	/* +0x00 */
	char   *sg_passwd;	/* +0x08 */
	char  **sg_adm;		/* +0x10 */
	char  **sg_mem;		/* +0x18 */
};

#define E_GRP_UPDATE	10

/* i18n: dcgettext(NULL, msg, LC_MESSAGES) */
extern char *dcgettext(const char *domain, const char *msg, int category);
#define _(msg) dcgettext((char *)0, msg, 5)

/* Program name and parsed command-line options / values. */
extern char *Prog;
extern char *group_name;	/* group being modified                 */
extern char *group_newname;	/* -n: new name          (used by new_grp) */
extern char *group_passwd;	/* -p: new password      (used by new_grp) */
extern gid_t group_newid;	/* -g: new gid                          */
extern char *user_list;		/* -M/-A: comma separated member list   */
extern bool  pflg;		/* -p was given                         */
extern bool  nflg;		/* -n was given                         */
extern bool  gflg;		/* -g was given                         */
extern bool  aflg;		/* append (rather than replace) members */
extern bool  is_shadow_grp;	/* gshadow file is present              */

/* group / gshadow database back-end (commonio wrappers). */
extern const struct group *gr_locate(const char *name);
extern int                 gr_update(const struct group *gr);
extern int                 gr_remove(const char *name);
extern const char         *gr_dbname(void);
extern const struct sgrp  *sgr_locate(const char *name);
extern int                 sgr_update(const struct sgrp *sg);
extern int                 sgr_remove(const char *name);
extern const char         *sgr_dbname(void);

/* Apply the -n/-g/-p changes to a freshly copied record. */
extern void new_grp(struct group *grp);
extern void new_sgrp(struct sgrp *sgrp);

/* Re-point every user whose primary group is old_gid onto new_gid. */
extern void update_primary_groups(gid_t old_gid, gid_t new_gid);

/* String-list and allocation helpers. */
extern char **dup_list(char **list);
extern char **add_list(char **list, const char *name);
extern void   free_gr_mem(struct group *grp);
extern void  *xmalloc(size_t size);
extern char  *xstrdup(const char *str);

/* Look the member up in the passwd database; NULL if unknown. */
extern struct passwd *xgetpwnam(const char *name);

/* Empty admin list used when synthesising a new gshadow entry. */
static char *empty_admins[1];

void grp_update(void)
{
	const struct group *ogrp;
	const struct sgrp  *osgrp = (const struct sgrp *)0;
	struct group grpent;
	struct sgrp  sgent;
	char *member;

	ogrp = gr_locate(group_name);
	if ((const struct group *)0 == ogrp) {
		fprintf(stderr,
		        _("%s: group '%s' does not exist in %s\n"),
		        Prog, group_name, gr_dbname());
		exit(E_GRP_UPDATE);
	}

	grpent = *ogrp;
	new_grp(&grpent);

	/*
	 * If a shadowed gshadow entry is in use and the password or name
	 * is changing, fetch (or synthesise) the matching gshadow record.
	 */
	if (is_shadow_grp && (pflg || nflg)) {
		osgrp = sgr_locate(group_name);
		if ((const struct sgrp *)0 != osgrp) {
			sgent = *osgrp;
			new_sgrp(&sgent);
		} else if (pflg && strcmp(grpent.gr_passwd, "x") == 0) {
			/* The password lives in gshadow but there is no
			 * entry yet: build one from the group record. */
			memset(&sgent, 0, sizeof(sgent));
			sgent.sg_namp   = xstrdup(grpent.gr_name);
			sgent.sg_passwd = xstrdup(grpent.gr_passwd);
			sgent.sg_adm    = empty_admins;
			sgent.sg_mem    = dup_list(grpent.gr_mem);
			new_sgrp(&sgent);
			osgrp = &sgent;
		}
	}

	/* When the gid changes, move the affected users' primary group. */
	if (gflg) {
		update_primary_groups(ogrp->gr_gid, group_newid);
	}

	/*
	 * Update the group's member list: either append to the existing
	 * members (-A) or replace them wholesale (-M).
	 */
	if ((char *)0 != user_list) {
		if (aflg) {
			if ((char *)0 != grpent.gr_mem[0]) {
				grpent.gr_mem = dup_list(grpent.gr_mem);
			}
		} else {
			if ((char *)0 != grpent.gr_mem[0]) {
				free_gr_mem(&grpent);
			}
			grpent.gr_mem = xmalloc(sizeof(char *));
			grpent.gr_mem[0] = (char *)0;
		}

		for (member = strtok(user_list, ",");
		     (char *)0 != member;
		     member = strtok((char *)0, ",")) {
			if ((struct passwd *)0 == xgetpwnam(member)) {
				fprintf(stderr,
				        _("Invalid member username %s\n"),
				        member);
				exit(E_GRP_UPDATE);
			}
			grpent.gr_mem = add_list(grpent.gr_mem, member);
		}
	}

	if (gr_update(&grpent) == 0) {
		fprintf(stderr,
		        _("%s: failed to prepare the new %s entry '%s'\n"),
		        Prog, gr_dbname(), grpent.gr_name);
		exit(E_GRP_UPDATE);
	}
	if (nflg && (gr_remove(group_name) == 0)) {
		fprintf(stderr,
		        _("%s: cannot remove entry '%s' from %s\n"),
		        Prog, grpent.gr_name, gr_dbname());
		exit(E_GRP_UPDATE);
	}

	if ((const struct sgrp *)0 != osgrp) {
		if (sgr_update(&sgent) == 0) {
			fprintf(stderr,
			        _("%s: failed to prepare the new %s entry '%s'\n"),
			        Prog, sgr_dbname(), sgent.sg_namp);
			exit(E_GRP_UPDATE);
		}
		if (nflg && (sgr_remove(group_name) == 0)) {
			fprintf(stderr,
			        _("%s: cannot remove entry '%s' from %s\n"),
			        Prog, group_name, sgr_dbname());
			exit(E_GRP_UPDATE);
		}
	}
}


