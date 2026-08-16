// Function: filter_mount_list @ 0x4dc0
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

struct mount_entry
{
    char *me_devname;
    char *me_mountdir;
    char *me_mntroot;
    char *me_type;
    dev_t me_dev;
    unsigned int me_dummy : 1;
    unsigned int me_remote : 1;
    unsigned int me_type_malloced : 1;
    struct mount_entry *me_next;
};

struct devlist
{
    dev_t dev_num;
    struct mount_entry *me;
    struct devlist *next;
    struct devlist *seen_last;
};

typedef struct hash_table Hash_table;

extern struct mount_entry *mount_list;
extern Hash_table *devlist_table;
extern bool print_grand_total;
extern bool show_listed_fs;
extern bool show_local_fs;
extern bool show_all_fs;

extern size_t devlist_hash(void const *, size_t);
extern bool devlist_compare(void const *, void const *);
extern Hash_table *hash_initialize(size_t, void const *,
                                   size_t (*)(void const *, size_t),
                                   bool (*)(void const *, void const *),
                                   void (*)(void *));
extern void *hash_insert(Hash_table *, void const *);
extern void hash_free(Hash_table *);
extern struct devlist *devlist_for_dev(dev_t);
extern bool selected_fstype(char const *);
extern bool excluded_fstype(char const *);
extern void free_mount_entry(struct mount_entry *);
extern void *xmalloc(size_t);
extern void xalloc_die(void);

void
filter_mount_list(bool retain_all)
{
    int mount_count = 0;
    struct devlist *devlist = NULL;
    struct mount_entry *me;

    for (me = mount_list; me != NULL; me = me->me_next)
        ++mount_count;

    devlist_table = hash_initialize((size_t) mount_count, NULL,
                                    devlist_hash, devlist_compare, NULL);
    if (devlist_table == NULL)
        xalloc_die();

    for (me = mount_list; me != NULL; me = me->me_next)
    {
        dev_t dev = me->me_dev;
        struct devlist *devlist_entry = NULL;

        if (!(me->me_remote && show_local_fs)
            && !(me->me_dummy && !show_all_fs && !show_listed_fs)
            && selected_fstype(me->me_type)
            && !excluded_fstype(me->me_type))
        {
            struct stat buf;

            if (stat(me->me_mountdir, &buf) == 0)
            {
                struct mount_entry *old_me;
                size_t old_mountdir_len;
                size_t mountdir_len;
                bool old_root_is_shorter = false;

                dev = buf.st_dev;
                devlist_entry = devlist_for_dev(dev);
                if (devlist_entry != NULL)
                {
                    old_me = devlist_entry->me;
                    old_mountdir_len = strlen(old_me->me_mountdir);
                    mountdir_len = strlen(me->me_mountdir);

                    if (old_me->me_mntroot != NULL && me->me_mntroot != NULL)
                        old_root_is_shorter =
                            strlen(old_me->me_mntroot) < strlen(me->me_mntroot);

                    if (!print_grand_total
                        && me->me_remote
                        && old_me->me_remote
                        && strcmp(old_me->me_devname, me->me_devname) != 0)
                    {
                        devlist_entry = NULL;
                    }
                    else
                    {
                        bool replace_old =
                            (strchr(old_me->me_devname, '/') != NULL
                             && strchr(me->me_devname, '/') == NULL)
                            || (!old_root_is_shorter
                                && old_mountdir_len > mountdir_len)
                            || (strcmp(old_me->me_devname, me->me_devname) != 0
                                && strcmp(me->me_mountdir,
                                          old_me->me_mountdir) == 0);
                        struct mount_entry *discarded;

                        if (replace_old)
                        {
                            devlist_entry->me = me;
                            discarded = old_me;
                        }
                        else
                        {
                            discarded = me;
                        }

                        if (!retain_all)
                            free_mount_entry(discarded);
                        continue;
                    }
                }
            }
        }

        {
            struct devlist *new_entry = xmalloc(sizeof *new_entry);
            struct devlist *hash_entry;

            new_entry->dev_num = dev;
            new_entry->me = me;
            new_entry->next = devlist;
            hash_entry = hash_insert(devlist_table, new_entry);
            if (hash_entry == NULL)
                xalloc_die();
            hash_entry->seen_last = new_entry;
            devlist = new_entry;
        }
    }

    if (!retain_all)
    {
        mount_list = NULL;
        while (devlist != NULL)
        {
            struct devlist *next = devlist->next;
            struct mount_entry *entry = devlist->me;

            entry->me_next = mount_list;
            mount_list = entry;
            free(devlist);
            devlist = next;
        }

        hash_free(devlist_table);
        devlist_table = NULL;
    }
}


