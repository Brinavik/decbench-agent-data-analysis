// Function: filter_mount_list @ 0x4dc0
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

/* Mount table entry (gnulib mountlist.h layout).  */
struct mount_entry
{
  char *me_devname;             /* Device node name, including "/dev/".  */
  char *me_mountdir;            /* Mount point directory name.  */
  char *me_mntroot;             /* Directory on filesystem of device used
                                   as root for the (bind) mount.  */
  char *me_type;                /* "nfs", "ext4", etc.  */
  dev_t me_dev;                 /* Device number of me_mountdir.  */
  unsigned int me_dummy : 1;    /* Nonzero for dummy file systems.  */
  unsigned int me_remote : 1;   /* Nonzero for remote file systems.  */
  unsigned int me_type_malloced : 1;
  unsigned int me_mntroot_malloced : 1;
  struct mount_entry *me_next;
};

/* A device number with the mount entry currently chosen for it.  */
struct devlist
{
  dev_t dev_num;
  struct mount_entry *me;
  struct devlist *next;
  struct devlist *seen_last;    /* Valid for hashed devlist entries only:
                                   the most recently seen devlist with this
                                   device number.  */
};

/* gnulib hash table interface.  */
typedef struct hash_table Hash_table;
typedef size_t (*Hash_hasher) (const void *, size_t);
typedef bool (*Hash_comparator) (const void *, const void *);
typedef void (*Hash_data_freer) (void *);
extern Hash_table *hash_initialize (size_t candidate, const void *tuning,
                                    Hash_hasher hasher,
                                    Hash_comparator comparator,
                                    Hash_data_freer data_freer);
extern void *hash_insert (Hash_table *table, const void *entry);
extern void hash_free (Hash_table *table);

extern void *xmalloc (size_t n);
extern _Noreturn void xalloc_die (void);

/* df helpers defined elsewhere in this translation unit.  */
static size_t devlist_hash (const void *x, size_t table_size);
static bool devlist_compare (const void *x, const void *y);
static struct devlist *devlist_for_dev (dev_t dev);
static bool selected_fstype (const char *fstype);
static bool excluded_fstype (const char *fstype);
static void free_mount_entry (struct mount_entry *me);

/* Globals.  */
extern struct mount_entry *mount_list;  /* Linked list of mounted file systems.  */
extern Hash_table *devlist_table;       /* Hash of devlist entries by device number.  */
extern bool show_listed_fs;             /* If true, show even file systems with 0 blocks.  */
extern bool show_local_fs;              /* If true, show only local file systems.  */
extern bool show_all_fs;                /* If true, include dummy file systems.  */
extern bool print_grand_total;          /* If true, print a grand total at the end.  */

/* Filter the mount list returned by the mount table reader:
   deduplicate entries that refer to the same device, keeping the
   "best" mount point for each device.  If DEVICES_ONLY is true, only
   fill the devlist hash table (leaving MOUNT_LIST intact); otherwise
   rebuild MOUNT_LIST from the deduplicated entries and dispose of the
   hash table.  */
void
filter_mount_list (bool devices_only)
{
  struct mount_entry *me;

  /* Temporary list to keep entries ordered.  */
  struct devlist *device_list = NULL;
  int mount_list_size = 0;

  for (me = mount_list; me; me = me->me_next)
    mount_list_size++;

  devlist_table = hash_initialize (mount_list_size, NULL,
                                   devlist_hash, devlist_compare, NULL);
  if (devlist_table == NULL)
    xalloc_die ();

  /* Sort all 'wanted' entries into the list device_list.  */
  for (me = mount_list; me;)
    {
      struct stat buf;
      struct devlist *devlist = NULL;
      dev_t dev;

      if ((me->me_remote && show_local_fs)
          || (me->me_dummy && !show_all_fs && !show_listed_fs)
          || !selected_fstype (me->me_type)
          || excluded_fstype (me->me_type)
          || stat (me->me_mountdir, &buf) == -1)
        {
          /* If remote, dummy, or unselected, or the stat failed, add
             the entry unconditionally using its recorded device.  */
          dev = me->me_dev;
        }
      else if ((devlist = devlist_for_dev (buf.st_dev)) != NULL)
        {
          /* We've already seen this device: decide whether to keep
             the entry seen earlier or this one.  */
          struct mount_entry *seen_dev = devlist->me;

          size_t seen_dir_len = strlen (seen_dev->me_mountdir);
          size_t me_dir_len = strlen (me->me_mountdir);

          /* With bind mounts, prefer items nearer the root of the source.  */
          bool source_below_root = seen_dev->me_mntroot != NULL
                                   && me->me_mntroot != NULL
                                   && (strlen (seen_dev->me_mntroot)
                                       < strlen (me->me_mntroot));

          if (!print_grand_total
              && me->me_remote && seen_dev->me_remote
              && strcmp (seen_dev->me_devname, me->me_devname) != 0)
            {
              /* Don't discard remote entries with different device names,
                 as these are more likely to be different file systems.  */
              dev = buf.st_dev;
            }
          else
            {
              /* Discard one of the entries.  Prefer this one if its
                 device name is a real path, if its mount point is
                 nearer the root, or if only its device name differs.  */
              struct mount_entry *discard;

              if ((strchr (me->me_devname, '/')
                   && !strchr (seen_dev->me_devname, '/'))
                  || (seen_dir_len > me_dir_len && !source_below_root)
                  || (strcmp (seen_dev->me_devname, me->me_devname) != 0
                      && strcmp (seen_dev->me_mountdir,
                                 me->me_mountdir) == 0))
                {
                  /* Keep this entry for the device.  */
                  devlist->me = me;
                  discard = seen_dev;
                }
              else
                {
                  /* Keep the entry seen earlier.  */
                  discard = me;
                }

              me = me->me_next;
              if (!devices_only)
                free_mount_entry (discard);
              continue;
            }
        }
      else
        {
          /* First time we see this device.  */
          dev = buf.st_dev;
        }

      /* Add the device number to the device_list order.  */
      devlist = xmalloc (sizeof *devlist);
      devlist->dev_num = dev;
      devlist->me = me;
      devlist->next = device_list;

      struct devlist *hashed = hash_insert (devlist_table, devlist);
      if (hashed == NULL)
        xalloc_die ();
      hashed->seen_last = devlist;

      device_list = devlist;
      me = me->me_next;
    }

  if (!devices_only)
    {
      /* Rebuild the mount_list from the devlist.  */
      mount_list = NULL;

      struct mount_entry *last = NULL;
      while (device_list)
        {
          struct devlist *next = device_list->next;

          me = device_list->me;
          me->me_next = last;
          mount_list = me;
          free (device_list);

          last = me;
          device_list = next;
        }

      hash_free (devlist_table);
      devlist_table = NULL;
    }
}


