// Function: diversion_add @ 0x62c0
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

struct pkgset {
    void *next;
    const char *name;
};

struct fsys_diversion;

struct fsys_namenode {
    void *next;
    const char *name;
    void *packages;
    struct fsys_diversion *divert;
};

struct fsys_diversion {
    struct fsys_namenode *useinstead;
    struct fsys_namenode *camefrom;
    struct pkgset *pkgset;
    void *reserved;
};

enum file_status {
    FILE_STAT_UNKNOWN,
    FILE_STAT_PRESENT,
    FILE_STAT_ABSENT
};

struct file_info {
    char *name;
    enum file_status status;
    struct stat stat;
};

struct cmdinfo {
    const char *olong;
};

extern int opt_rename;
extern int opt_verbose;
extern int opt_test;
extern bool opt_pkgset_any;
extern char *opt_divertto;
extern const char *opt_package;
extern struct cmdinfo *cipaction;

extern char *dcgettext(const char *domain, const char *msgid, int category);
extern void check_rename(void);
extern void validate_filename(const char *filename);
extern void file_info_init(struct file_info *file, const char *filename);
extern void file_info_stat(struct file_info *file);
extern bool file_info_prepare_rename(struct file_info *from,
                                     struct file_info *to);
extern void file_info_rename(struct file_info *from, struct file_info *to);
extern struct fsys_namenode *fsys_hash_find_node(const char *name, int flags);
extern struct pkgset *pkg_hash_find_set(const char *name);
extern bool pkgset_owns_file(struct pkgset *pkgset,
                             struct fsys_namenode *namenode);
extern bool essential_pkg_owns_file(struct fsys_namenode *namenode);
extern const char *diversion_describe(struct fsys_diversion *diversion);
extern const char *requested_diversion_describe(const char *filename);
extern char *m_asprintf(const char *format, ...);
extern void *nfmalloc(size_t size);
extern void m_free(void *ptr);
extern void write_diversions(void);
extern _Noreturn void badusage(const char *format, ...);
extern _Noreturn void ohshit(const char *format, ...);
extern void warning(const char *format, ...);

int
diversion_add(const char *const *argv)
{
    const char *filename = argv[0];
    struct fsys_namenode *namenode;
    struct fsys_namenode *divertto_namenode;
    struct fsys_diversion *diversion;
    struct fsys_diversion *reverse_diversion;
    struct pkgset *pkgset = NULL;
    struct file_info file_from;
    struct file_info file_to;

    opt_pkgset_any = false;
    check_rename();

    if (filename == NULL || argv[1] != NULL)
        badusage(dcgettext(NULL, "--%s needs a single argument", 5),
                 cipaction->olong);

    validate_filename(filename);
    file_info_init(&file_from, filename);
    file_info_stat(&file_from);

    if (file_from.status == FILE_STAT_PRESENT &&
        S_ISDIR(file_from.stat.st_mode))
        badusage(dcgettext(NULL, "cannot divert directories", 5));

    namenode = fsys_hash_find_node(filename, 0);

    if (opt_divertto == NULL)
        opt_divertto = m_asprintf("%s.distrib", filename);

    if (strcmp(filename, opt_divertto) == 0)
        badusage(dcgettext(NULL, "cannot divert file '%s' to itself", 5),
                 filename);

    file_info_init(&file_to, opt_divertto);
    divertto_namenode = fsys_hash_find_node(opt_divertto, 0);

    if (opt_package != NULL)
        pkgset = pkg_hash_find_set(opt_package);

    diversion = namenode->divert;
    if (diversion != NULL) {
        reverse_diversion = divertto_namenode->divert;

        if (reverse_diversion == NULL ||
            reverse_diversion->camefrom == NULL ||
            strcmp(reverse_diversion->camefrom->name, filename) != 0 ||
            diversion->useinstead == NULL ||
            strcmp(diversion->useinstead->name, opt_divertto) != 0 ||
            diversion->pkgset != pkgset) {
            ohshit(dcgettext(NULL, "'%s' clashes with '%s'", 5),
                   requested_diversion_describe(filename),
                   diversion_describe(diversion));
        }

        if (opt_verbose > 0)
            printf(dcgettext(NULL, "Leaving '%s'\n", 5),
                   diversion_describe(diversion));

        m_free(file_from.name);
        m_free(file_to.name);
        return 0;
    }

    if (divertto_namenode->divert != NULL) {
        ohshit(dcgettext(NULL, "'%s' clashes with '%s'", 5),
               requested_diversion_describe(filename),
               diversion_describe(divertto_namenode->divert));
    }

    diversion = nfmalloc(sizeof(*diversion));
    reverse_diversion = nfmalloc(sizeof(*reverse_diversion));

    reverse_diversion->useinstead = NULL;
    reverse_diversion->camefrom = namenode;
    reverse_diversion->pkgset = pkgset;
    divertto_namenode->divert = reverse_diversion;

    diversion->useinstead = divertto_namenode;
    diversion->camefrom = NULL;
    diversion->pkgset = pkgset;
    namenode->divert = diversion;

    if (opt_verbose > 0)
        printf(dcgettext(NULL, "Adding '%s'\n", 5),
               diversion_describe(diversion));

    if (opt_rename != 0) {
        opt_rename = file_info_prepare_rename(&file_from, &file_to);

        if (opt_rename != 0) {
            if (pkgset_owns_file(pkgset, namenode)) {
                if (opt_verbose > 0)
                    printf(dcgettext(NULL,
                               "Ignoring request to rename file '%s' owned by diverting package '%s'\n",
                               5),
                           filename, pkgset->name);
                opt_rename = 0;
            } else if (essential_pkg_owns_file(namenode)) {
                warning(dcgettext(NULL,
                    "diverting file '%s' from an Essential package with rename is dangerous, use --no-rename",
                    5),
                    filename);
            }
        }
    }

    if (!opt_test) {
        write_diversions();
        if (opt_rename != 0)
            file_info_rename(&file_from, &file_to);
    }

    m_free(file_from.name);
    m_free(file_to.name);
    return 0;
}


