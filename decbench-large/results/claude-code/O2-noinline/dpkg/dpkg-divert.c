// Function: diversion_add @ 0x62c0
#include <sys/stat.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define _(str) gettext(str)
extern char *gettext(const char *msgid);

/* --- dpkg data structures (only the fields this function touches) --- */

struct pkgset {
	struct pkgset *next;		/* 0x00 */
	const char *name;		/* 0x08 */
};

struct diversion;

struct fsys_namenode {
	struct fsys_namenode *next;	/* 0x00 */
	const char *name;		/* 0x08 */
	void *packages;			/* 0x10 */
	struct diversion *divert;	/* 0x18 */
};

struct diversion {
	struct fsys_namenode *useinstead;	/* 0x00 */
	struct fsys_namenode *camefrom;		/* 0x08 */
	struct pkgset *pkg;			/* 0x10 */
	bool camefrom_installed;		/* 0x18 */
};

enum file_stat_state {
	FILE_STAT_INVALID,
	FILE_STAT_VALID,
	FILE_STAT_NOFILE,
};

struct file {
	const char *name;		/* 0x00 */
	enum file_stat_state stat_state;/* 0x08 */
	struct stat stat;		/* 0x10 */
};

struct command {
	const char *olong;
};

/* --- externals referenced by this function --- */

extern struct command *cipaction;
extern const char *opt_divertto;
extern const char *opt_pkgname;
extern int opt_rename;
extern int opt_verbose;
extern int opt_test;
extern bool opt_pkgname_match_any;

extern void badusage(const char *fmt, ...) __attribute__((noreturn));
extern void ohshit(const char *fmt, ...) __attribute__((noreturn));
extern void warning(const char *fmt, ...);
extern char *str_fmt(const char *fmt, ...);
extern void *nfmalloc(size_t size);

extern void opt_rename_setup(void);
extern void check_filename(const char *filename);

extern void file_init(struct file *file, const char *filename);
extern void file_stat(struct file *file);
extern void file_rename(struct file *from, struct file *to);
extern void file_deinit(struct file *file);

extern struct fsys_namenode *fsys_hash_find_node(const char *name, int flags);
extern struct pkgset *pkg_hash_find_set(const char *name);

extern char *diversion_current(const char *filename);
extern char *diversion_describe(struct diversion *div);
extern bool check_rename(struct file *from, struct file *to);
extern bool diversion_is_owned_by(struct pkgset *set, struct fsys_namenode *fnn);
extern bool diversion_is_essential(struct fsys_namenode *fnn);

extern void divertdb_write(void);

int
diversion_add(const char *const *argv)
{
	struct file file_from, file_to;
	struct fsys_namenode *namenode, *divertto_node;
	struct pkgset *pkgset;
	struct diversion *contest, *altname;
	const char *filename = argv[0];

	opt_pkgname_match_any = false;

	opt_rename_setup();

	/* Handle filename. */
	if (filename == NULL || argv[1] != NULL)
		badusage(_("--%s needs a single argument"), cipaction->olong);

	check_filename(filename);

	file_init(&file_from, filename);
	file_stat(&file_from);

	if (file_from.stat_state == FILE_STAT_VALID &&
	    S_ISDIR(file_from.stat.st_mode))
		badusage(_("cannot divert directories"));

	namenode = fsys_hash_find_node(filename, 0);

	if (opt_divertto == NULL)
		opt_divertto = str_fmt("%s.distrib", filename);

	if (strcmp(filename, opt_divertto) == 0)
		badusage(_("cannot divert file '%s' to itself"), filename);

	file_init(&file_to, opt_divertto);

	divertto_node = fsys_hash_find_node(opt_divertto, 0);

	if (opt_pkgname == NULL)
		pkgset = NULL;
	else
		pkgset = pkg_hash_find_set(opt_pkgname);

	/* Check we are not stomping over another diversion. */
	contest = namenode->divert;
	altname = divertto_node->divert;

	if (contest && altname &&
	    altname->camefrom &&
	    strcmp(altname->camefrom->name, filename) == 0 &&
	    contest->useinstead &&
	    strcmp(contest->useinstead->name, opt_divertto) == 0 &&
	    contest->pkg == pkgset) {
		/* Diversion already present. */
		if (opt_verbose > 0)
			printf(_("Leaving '%s'\n"), diversion_describe(contest));

		file_deinit(&file_from);
		file_deinit(&file_to);
		return 0;
	} else if (contest || altname) {
		ohshit(_("'%s' clashes with '%s'"),
		       diversion_current(filename),
		       diversion_describe(contest ? contest : altname));
	}

	/* Create new diversion. */
	contest = nfmalloc(sizeof(*contest));
	altname = nfmalloc(sizeof(*altname));

	altname->camefrom = namenode;
	namenode->divert = contest;
	altname->useinstead = NULL;
	altname->pkg = pkgset;

	contest->useinstead = divertto_node;
	divertto_node->divert = altname;
	contest->camefrom = NULL;
	contest->pkg = pkgset;

	if (opt_verbose > 0)
		printf(_("Adding '%s'\n"), diversion_describe(contest));

	if (opt_rename)
		opt_rename = check_rename(&file_from, &file_to);

	/* Do not rename files owned by the diverting package. */
	if (opt_rename) {
		if (diversion_is_owned_by(pkgset, namenode)) {
			if (opt_verbose > 0)
				printf(_("Ignoring request to rename file '%s' "
				         "owned by diverting package '%s'\n"),
				       filename, pkgset->name);
			opt_rename = 0;
		} else if (opt_rename && diversion_is_essential(namenode)) {
			warning(_("diverting file '%s' from an Essential "
			          "package with rename is dangerous, use "
			          "--no-rename"), filename);
		}
	}

	if (!opt_test) {
		divertdb_write();
		if (opt_rename)
			file_rename(&file_from, &file_to);
	}

	file_deinit(&file_from);
	file_deinit(&file_to);

	return 0;
}


