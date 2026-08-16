// Function: copy_reg @ 0x8680
/* Reconstruction of the GNU coreutils copy.c helper copy_reg().
   The binary is stripped; this recovers the function at virtual
   address 0x8680, named here copy_reg. */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

/* ---- Supporting declarations (normally pulled in from copy.h etc.) ---- */

#ifndef O_BINARY
# define O_BINARY 0
#endif
#define S_IRWXUGO (S_IRWXU | S_IRWXG | S_IRWXO)

#define _(msgid) gettext (msgid)
extern char *gettext (const char *);
extern void error (int status, int errnum, const char *format, ...);
extern char *quotearg_style (int style, char const *arg);
extern char *quotearg_n_style (int n, int style, char const *arg);
#define shell_escape_always_quoting_style 4
#define quoteaf(arg)      quotearg_style (shell_escape_always_quoting_style, (arg))
#define quotearg_n_style_colon(n, s, a) quotearg_n_style ((n), (s), (a))

#define SAME_INODE(a, b) \
  ((a).st_ino == (b).st_ino && (a).st_dev == (b).st_dev)

enum Dereference_symlink
{
  DEREF_UNDEFINED = 1,
  DEREF_NEVER,
  DEREF_COMMAND_LINE_ARGUMENTS,
  DEREF_ALWAYS
};

enum Sparse_type
{
  SPARSE_UNUSED,
  SPARSE_NEVER,
  SPARSE_AUTO,
  SPARSE_ALWAYS
};

enum Reflink_type
{
  REFLINK_NEVER,
  REFLINK_AUTO,
  REFLINK_ALWAYS
};

enum scantype
{
  ERROR_SCANTYPE,
  PLAIN_SCANTYPE,
  ZERO_SCANTYPE,
  LSEEK_SCANTYPE = 3
};

union scan_inference
{
  off_t ext_start;
};

/* The options controlling the copy.  Field offsets match those used by the
   compiled code; unnamed reserved bytes stand in for members this function
   does not reference. */
struct cp_options
{
  int backup_type;                        /* 0x00 */
  enum Dereference_symlink dereference;   /* 0x04 */
  int interactive;                        /* 0x08 */
  enum Sparse_type sparse_mode;           /* 0x0c */
  mode_t mode;                            /* 0x10 */
  char reserved_14[2];                    /* 0x14 */
  bool unlink_dest_after_failed_open;     /* 0x16 */
  char reserved_17;                       /* 0x17 */
  bool preserve_security_context;         /* 0x18 */
  char reserved_19[2];                    /* 0x19 */
  bool move_mode;                         /* 0x1b */
  char reserved_1c;                       /* 0x1c */
  bool preserve_ownership;                /* 0x1d */
  char reserved_1e;                       /* 0x1e */
  bool preserve_timestamps;               /* 0x1f */
  bool preserve_links;                    /* 0x20 */
  char reserved_21[7];                    /* 0x21 */
  void *set_security_context;             /* 0x28 */
  bool data_copy_required;                /* 0x31 */
  bool require_preserve;                  /* 0x32 */
  bool require_preserve_context;          /* 0x33 */
  bool preserve_xattr;                    /* 0x34 */
  bool selinux_privileges;                /* 0x35 */
  bool require_preserve_xattr;            /* 0x36 */
  char reserved_37[2];                    /* 0x37 */
  bool preserve_mode;                     /* 0x39 */
  char reserved_3a[2];                    /* 0x3a */
  bool explicit_no_preserve_mode;         /* 0x3c */
  char reserved_3d;                       /* 0x3d */
  bool dereference_dangling;              /* 0x3e */
  char reserved_3f[5];                    /* 0x3f */
  enum Reflink_type reflink_mode;         /* 0x44 */
};

/* Helper routines living elsewhere in copy.c / the coreutils libs. */
extern int  open_safer (char const *name, int flags, ...);
extern int  openat_safer (int dirfd, char const *name, int flags, ...);
extern bool clone_file (int dest_fd, int src_fd);
extern enum scantype infer_scantype (int fd, struct stat const *sb,
                                     union scan_inference *scan_inference);
extern size_t io_blksize (struct stat const *sb);
extern size_t buffer_lcm (size_t a, size_t b, size_t lcm_max);
extern int  fchmod_or_lchmodat (int fd, int dirfd, char const *name, mode_t m);
extern bool sparse_copy (int src_fd, int dest_fd, char **abuf, size_t buf_size,
                         size_t hole_size, bool punch_holes, bool allow_reflink,
                         char const *src_name, char const *dst_name,
                         uintmax_t max_n_read, off_t *total_n_read,
                         bool *last_write_made_hole);
extern bool lseek_copy (int src_fd, int dest_fd, char **abuf, size_t buf_size,
                        size_t hole_size, off_t ext_start, off_t src_total_size,
                        enum Sparse_type sparse_mode, bool allow_reflink,
                        char const *src_name, char const *dst_name);
extern bool set_process_security_ctx (char const *src_name, char const *dst_name,
                                      mode_t mode, bool new_dst,
                                      struct cp_options const *x);
extern bool set_file_security_ctx (char const *dst_name, bool process_local,
                                   struct cp_options const *x);
extern bool set_owner (struct cp_options const *x, char const *dst_name,
                       int dest_desc, struct stat const *src_sb, bool new_dst,
                       struct stat const *dst_sb);
extern bool copy_acl (char const *src_name, int source_desc,
                      char const *dst_name, int dest_desc, mode_t mode);
extern bool set_acl (char const *name, int desc, mode_t mode);
extern void copy_attr (char const *src_path, int src_fd,
                       char const *dst_path, int dst_fd,
                       struct cp_options const *x);
extern mode_t cached_umask (void);
extern int  utimens_wrapper (int fd, int dirfd, char const *name,
                             struct timespec const ts[2]);
extern struct timespec get_stat_atime (struct stat const *st);
extern struct timespec get_stat_mtime (struct stat const *st);

static bool
copy_reg (char const *src_name, char const *dst_name,
          int dst_dirfd, char const *dst_relname,
          const struct cp_options *x, mode_t dst_mode_bits,
          mode_t omitted_permissions, bool *new_dst,
          struct stat const *src_sb)
{
  char *buf = NULL;
  int dest_desc;
  int dest_errno = 0;
  int source_desc;
  mode_t src_mode = src_sb->st_mode;
  mode_t extra_permissions = 0;
  struct stat sb;
  struct stat src_open_sb;
  union scan_inference scan_inference;
  bool return_val = true;
  bool data_copy_required = x->data_copy_required;

  source_desc = open_safer (src_name,
                            (O_RDONLY | O_BINARY
                             | (x->dereference == DEREF_NEVER ? O_NOFOLLOW : 0)));
  if (source_desc < 0)
    {
      error (0, errno, _("cannot open %s for reading"), quoteaf (src_name));
      return false;
    }

  if (fstat (source_desc, &src_open_sb) != 0)
    {
      error (0, errno, _("cannot fstat %s"), quoteaf (src_name));
      return_val = false;
      goto close_src_desc;
    }

  /* Compare the source dev/ino from the open file to the incoming, saved
     ones obtained via a previous call to "stat".  */
  if (! SAME_INODE (*src_sb, src_open_sb))
    {
      error (0, 0,
             _("skipping file %s, as it was replaced while being copied"),
             quoteaf (src_name));
      return_val = false;
      goto close_src_desc;
    }

  if (! *new_dst)
    {
      /* Try to open the existing destination.  */
      dest_desc = openat_safer (dst_dirfd, dst_relname,
                                O_WRONLY | O_BINARY
                                | (data_copy_required ? O_TRUNC : 0));
      dest_errno = errno;

      if (dest_desc < 0)
        goto handle_dest_error;

      /* When copying onto an existing file that has a security context,
         arrange to install the source's context on it.  */
      if (x->set_security_context)
        {
          if (! set_file_security_ctx (dst_name, false, x))
            {
              return_val = false;
              if (x->require_preserve_context)
                goto close_dest_desc;
              return_val = true;
            }
        }

      if (*new_dst)
        goto open_with_O_CREAT;

      omitted_permissions = 0;
      extra_permissions = 0;
    }
  else
    {
    open_with_O_CREAT:
      {
        mode_t open_mode = dst_mode_bits & ~omitted_permissions;

        /* If we need write access to the freshly created file (e.g. to set
           its security context) but the requested mode denies it, add the
           owner-write bit temporarily and remember to clear it later.  */
        if (x->selinux_privileges && ! x->move_mode)
          open_mode |= S_IWUSR;

        dest_desc = openat_safer (dst_dirfd, dst_relname,
                                  O_WRONLY | O_CREAT | O_EXCL | O_BINARY,
                                  open_mode);
        dest_errno = errno;

        /* The temporary write bit is whatever we added on top of the
           requested permissions.  */
        extra_permissions = open_mode & ~dst_mode_bits;

        if (dest_desc < 0 && dest_errno == EEXIST && x->preserve_security_context)
          {
            error (0, 0, _("cannot create regular file %s"),
                   quoteaf (dst_name));
            return_val = false;
            goto close_src_desc;
          }

        if (dest_desc < 0 && dest_errno == ELOOP)
          {
            /* The destination is (or dangles through) a symlink.  */
            char linkbuf[1];
            if (readlinkat (dst_dirfd, dst_relname, linkbuf, 1) >= 0)
              {
                if (x->dereference_dangling)
                  dest_desc = openat_safer (dst_dirfd, dst_relname,
                                            O_WRONLY | O_CREAT | O_BINARY,
                                            open_mode);
                else
                  {
                    error (0, 0,
                           _("not writing through dangling symlink %s"),
                           quoteaf (dst_name));
                    return_val = false;
                    goto close_src_desc;
                  }
              }
          }

        if (dest_desc < 0)
          goto handle_dest_error;
      }
    }

  if (data_copy_required)
    {
      bool make_holes = false;
      bool sparse_src;
      enum scantype scantype;
      size_t buf_size;
      size_t hole_size;
      off_t src_total_size = 0;

      if (x->reflink_mode)
        {
          if (clone_file (dest_desc, source_desc))
            {
              data_copy_required = false;
              goto copy_done;
            }
          if (x->reflink_mode == REFLINK_ALWAYS)
            {
              error (0, errno, _("failed to clone %s from %s"),
                     quotearg_n_style (0, shell_escape_always_quoting_style,
                                       dst_name),
                     quotearg_n_style (1, shell_escape_always_quoting_style,
                                       src_name));
              return_val = false;
              goto close_dest_desc;
            }
        }

      if (fstat (dest_desc, &sb) != 0)
        {
          error (0, errno, _("cannot fstat %s"), quoteaf (dst_name));
          return_val = false;
          goto close_dest_desc;
        }

      /* Make sure the temporary extra permission bits are actually set on
         the destination before writing.  */
      if ((sb.st_mode | extra_permissions) != sb.st_mode)
        {
          if (fchmod_or_lchmodat (dest_desc, dst_dirfd, dst_relname,
                                  sb.st_mode | extra_permissions) != 0)
            extra_permissions = 0;
        }

      buf_size = io_blksize (&sb);
      hole_size = io_blksize (&src_open_sb);

      scantype = infer_scantype (source_desc, &src_open_sb, &scan_inference);
      if (scantype == ERROR_SCANTYPE)
        {
          error (0, errno, _("cannot lseek %s"), quoteaf (src_name));
          return_val = false;
          goto close_dest_desc;
        }

      if (S_ISREG (src_open_sb.st_mode))
        {
          /* Compute a good buffer size for the copy, allowing large files
             and honoring both the source and destination block sizes.  */
          if (x->sparse_mode == SPARSE_ALWAYS
              || (x->sparse_mode == SPARSE_AUTO && scantype != PLAIN_SCANTYPE))
            make_holes = true;

          src_total_size = lseek (source_desc, 0, SEEK_END);
          buf_size = buffer_lcm (io_blksize (&src_open_sb), buf_size,
                                 (size_t) -1 / 2);
        }

      /* Do the copy.  For files that appear to contain holes, prefer the
         SEEK_HOLE-driven copy; otherwise use the block-scanning copy.  */
      sparse_src = false;
      {
        off_t n_read = 0;
        bool last_write_made_hole = false;

        if (scantype == LSEEK_SCANTYPE)
          return_val = lseek_copy (source_desc, dest_desc, &buf, buf_size,
                                   hole_size, scan_inference.ext_start,
                                   src_total_size, x->sparse_mode,
                                   x->reflink_mode != REFLINK_NEVER,
                                   src_name, dst_name);
        else
          return_val = sparse_copy (source_desc, dest_desc, &buf, buf_size,
                                    hole_size, make_holes,
                                    x->reflink_mode != REFLINK_NEVER,
                                    src_name, dst_name, (uintmax_t) -1,
                                    &n_read, &last_write_made_hole);
        (void) sparse_src;
        if (! return_val)
          goto close_dest_desc;

        /* A trailing hole must be materialized with ftruncate.  */
        if (last_write_made_hole)
          {
            if (ftruncate (dest_desc, lseek (dest_desc, 0, SEEK_CUR)) < 0)
              {
                error (0, errno, _("failed to extend %s"), quoteaf (dst_name));
                return_val = false;
                goto close_dest_desc;
              }
          }
      }
    }

copy_done:
  if (x->preserve_timestamps)
    {
      struct timespec timespec[2];
      timespec[0] = get_stat_atime (&src_open_sb);
      timespec[1] = get_stat_mtime (&src_open_sb);

      if (utimens_wrapper (dest_desc, dst_dirfd, dst_relname, timespec) != 0)
        {
          error (0, errno, _("preserving times for %s"), quoteaf (dst_name));
          if (x->require_preserve)
            {
              return_val = false;
              goto close_dest_desc;
            }
        }
    }

  /* Preserve the owner and group.  */
  if (x->preserve_ownership
      && (src_sb->st_uid != sb.st_uid || src_sb->st_gid != sb.st_gid))
    {
      if (! set_owner (x, dst_name, dest_desc, src_sb, *new_dst, &sb))
        {
          if (x->require_preserve)
            {
              return_val = false;
              goto close_dest_desc;
            }
          if (! x->preserve_mode)
            src_mode &= ~ (S_ISUID | S_ISGID | S_ISVTX);
        }
    }

  if (x->selinux_privileges)
    {
      if (! set_file_security_ctx (dst_name, true, x))
        {
          if (x->require_preserve_context)
            {
              return_val = false;
              goto close_dest_desc;
            }
        }
    }

  return_val = true;

  if (x->preserve_mode || x->move_mode)
    {
      if (copy_acl (src_name, source_desc, dst_name, dest_desc, src_mode)
          && x->require_preserve)
        return_val = false;
    }
  else if (x->explicit_no_preserve_mode)
    {
      if (set_acl (dst_name, dest_desc, S_IRUSR | S_IWUSR | S_IRGRP
                   | S_IWGRP | S_IROTH | S_IWOTH) != 0)
        return_val = false;
    }
  else if (omitted_permissions | extra_permissions)
    {
      /* Restore the deferred permission bits and drop the temporary
         owner-write bit.  */
      omitted_permissions &= ~ cached_umask ();
      if ((omitted_permissions & ~ extra_permissions)
          && fchmod_or_lchmodat (dest_desc, dst_dirfd, dst_relname,
                                 dst_mode_bits & ~ extra_permissions) != 0)
        {
          error (0, errno, _("preserving permissions for %s"),
                 quoteaf (dst_name));
          if (x->require_preserve)
            return_val = false;
        }
    }

close_dest_desc:
  if (close (dest_desc) < 0)
    {
      error (0, errno, _("failed to close %s"), quoteaf (dst_name));
      return_val = false;
    }

close_src_desc:
  if (close (source_desc) < 0)
    {
      error (0, errno, _("failed to close %s"), quoteaf (src_name));
      return_val = false;
    }

  free (buf);
  return return_val;

  /* ---- shared error tail for a destination that could not be opened ---- */

handle_dest_error:
  if (dest_errno == ENOENT || x->unlink_dest_after_failed_open)
    {
      /* Remove the offending destination and retry as a fresh create.  */
      if (unlinkat (dst_dirfd, dst_relname, 0) != 0)
        {
          if (dest_errno != ENOENT)
            {
              error (0, errno, _("cannot remove %s"), quoteaf (dst_name));
              return_val = false;
              goto close_src_desc;
            }
        }

      if (x->set_security_context
          && ! set_process_security_ctx (src_name, dst_name, dst_mode_bits,
                                         true, x))
        {
          error (0, 0, _("cannot create regular file %s"), quoteaf (dst_name));
          return_val = false;
          goto close_src_desc;
        }

      *new_dst = true;
      goto open_with_O_CREAT;
    }

  error (0, dest_errno, _("cannot create regular file %s"), quoteaf (dst_name));
  return_val = false;
  goto close_src_desc;
}


