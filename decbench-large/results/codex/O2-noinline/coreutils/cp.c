// Function: copy_reg @ 0x8680
#define _GNU_SOURCE 1
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <error.h>
#include <libintl.h>

enum dereference_symlink {
    DEREF_UNDEFINED = 0,
    DEREF_ALWAYS = 1,
    DEREF_NEVER = 2
};

enum sparse_type {
    SPARSE_NEVER = 0,
    SPARSE_AUTO = 2,
    SPARSE_ALWAYS = 3
};

enum reflink_type {
    REFLINK_NEVER = 0,
    REFLINK_AUTO = 1,
    REFLINK_ALWAYS = 2
};

struct cp_options {
    int backup_type;
    int dereference;
    int interactive;
    int sparse_mode;
    mode_t mode;
    unsigned char flag_14;
    unsigned char flag_15;
    bool unlink_dest_before_opening;
    unsigned char flag_17;
    bool move_mode;
    unsigned char owner_privileges;
    bool chown_privileges;
    bool symbolic_link;
    unsigned char flag_1c;
    bool preserve_ownership;
    bool preserve_mode;
    bool preserve_timestamps;
    bool explicit_no_preserve_mode;
    unsigned char pad_21[7];
    void *security_context;
    unsigned char flag_30;
    bool data_copy_required;
    bool require_preserve;
    bool preserve_security_context;
    bool require_preserve_context;
    bool preserve_xattr;
    bool require_preserve_xattr;
    bool reduce_diagnostics;
    unsigned char flag_38;
    bool set_mode;
    unsigned char flag_3a;
    unsigned char flag_3b;
    bool verbose;
    unsigned char flag_3d;
    bool open_dangling_dest_symlink;
    unsigned char flag_3f;
    int cached_umask;
    int reflink_mode;
};

extern int sub_e880(const char *, int, ...);
extern int sub_12710(int, const char *, int, ...);
extern char *sub_14b40(int, const char *);
extern bool sub_8250(const char *, bool, const struct cp_options *);
extern int sub_7020(int, int, const char *, mode_t);
extern bool sub_7040(const char *, int, const char *, int,
                     const struct cp_options *);
extern int sub_6770(int, int);
extern int sub_6780(int, const struct stat *, void *);
extern size_t sub_7fd0(size_t, const struct stat *);
extern size_t sub_dbf0(size_t, size_t, size_t);
extern bool sub_6a40(int, int, void **, size_t, size_t, bool, bool,
                     const char *, const char *, off_t, off_t *, bool *);
extern bool sub_7b50(int, int, void **, off_t, size_t, off_t, off_t,
                     bool, bool, const char *, const char *);
extern int sub_8430(const struct cp_options *, const char *, int,
                    const char *, int, mode_t, uid_t, gid_t, bool,
                    const struct stat *);
extern int sub_caa0(const char *, int, const char *, int, mode_t);
extern int sub_cb50(const char *, int, mode_t);
extern mode_t sub_8640(void);

bool
copy_reg(const char *src_name, const char *dst_name,
         int dst_dirfd, const char *dst_relname,
         const struct cp_options *x, mode_t dst_mode,
         mode_t omitted_permissions, bool *new_dst,
         const struct stat *src_sb)
{
    struct stat src_open_sb;
    struct stat dst_sb;
    struct timespec times[2];
    void *copy_buffer = NULL;
    off_t total_n_read = 0;
    bool last_write_made_hole = false;
    bool return_val = false;
    mode_t extra_permissions = 0;
    int src_fd;
    int dst_fd = -1;
    int open_errno;

    src_fd = sub_e880(src_name,
                      x->dereference == DEREF_NEVER ? O_NOFOLLOW : 0);
    if (src_fd < 0) {
        error(0, errno, gettext("cannot open %s for reading"),
              sub_14b40(4, src_name));
        return false;
    }

    if (fstat(src_fd, &src_open_sb) != 0) {
        error(0, errno, gettext("cannot fstat %s"),
              sub_14b40(4, src_name));
        goto close_src;
    }

    if (src_open_sb.st_dev != src_sb->st_dev
        || src_open_sb.st_ino != src_sb->st_ino) {
        error(0, 0, gettext("skipping file %s, as it was replaced while being copied"),
              sub_14b40(4, src_name));
        goto close_src;
    }

    if (!*new_dst) {
        int flags = O_WRONLY;

        if (x->data_copy_required)
            flags |= O_TRUNC;
        dst_fd = sub_12710(dst_dirfd, dst_relname, flags);
        open_errno = errno;

        if (dst_fd >= 0) {
            if (x->security_context != NULL || x->preserve_security_context) {
                extra_permissions = sub_8250(dst_name, false, x);
                if (!extra_permissions && x->require_preserve_context)
                    goto close_both;
            }
            if (*new_dst)
                goto create_dest;
            goto destination_open;
        }

        if (open_errno != ENOENT) {
            if (x->unlink_dest_before_opening) {
                if (unlinkat(dst_dirfd, dst_relname, 0) != 0) {
                    if (errno != ENOENT) {
                        error(0, errno, gettext("cannot remove %s"),
                              sub_14b40(4, dst_name));
                        goto close_src;
                    }
                } else if (x->verbose) {
                    error(0, 0, gettext("removed %s"),
                          sub_14b40(4, dst_name));
                }
            } else if (!*new_dst) {
                errno = open_errno;
                error(0, errno, gettext("cannot create regular file %s"),
                      sub_14b40(4, dst_name));
                goto close_src;
            }
        }
    }

create_dest:
    {
        mode_t create_mode = dst_mode & ~omitted_permissions;

        if (x->preserve_xattr && !x->symbolic_link)
            create_mode |= S_IRUSR;

        dst_fd = sub_12710(dst_dirfd, dst_relname,
                           O_WRONLY | O_CREAT | O_EXCL, create_mode);
        open_errno = errno;

        if (dst_fd < 0 && open_errno == EEXIST && !x->move_mode) {
            char c;
            ssize_t n = readlinkat(dst_dirfd, dst_relname, &c, 1);

            if (n >= 0) {
                if (!x->open_dangling_dest_symlink) {
                    error(0, 0, gettext("not writing through dangling symlink %s"),
                          sub_14b40(4, dst_name));
                    goto close_src;
                }

                dst_fd = sub_12710(dst_dirfd, dst_relname,
                                   O_WRONLY | O_CREAT, create_mode);
                open_errno = errno;
            }
        }

        if (dst_fd < 0) {
            if (open_errno == EISDIR && dst_name[0] != '\0') {
                size_t len = 0;
                while (dst_name[len] != '\0')
                    ++len;
                if (len != 0 && dst_name[len - 1] != '/')
                    open_errno = ENOTDIR;
            }
            errno = open_errno;
            error(0, errno, gettext("cannot create regular file %s"),
                  sub_14b40(4, dst_name));
            goto close_src;
        }

        *new_dst = true;
        extra_permissions = create_mode & ~dst_mode;
    }

destination_open:
    if (!x->data_copy_required) {
        extra_permissions = x->preserve_ownership;
        if (!extra_permissions) {
            dst_sb.st_mode = 0;
            goto preserve_metadata;
        }
        extra_permissions = 0;
    }

    if (x->data_copy_required && x->reflink_mode != REFLINK_NEVER) {
        if (sub_6770(dst_fd, src_fd) == 0)
            goto preserve_metadata;

        if (x->reflink_mode == REFLINK_ALWAYS) {
            error(0, errno, gettext("failed to clone %s from %s"),
                  sub_14b40(4, dst_name), sub_14b40(4, src_name));
            goto close_both;
        }
    }

    if (fstat(dst_fd, &dst_sb) != 0) {
        error(0, errno, gettext("cannot fstat %s"),
              sub_14b40(4, dst_name));
        goto close_both;
    }

    if ((dst_sb.st_mode | extra_permissions) != dst_sb.st_mode) {
        if (sub_7020(dst_fd, dst_dirfd, dst_relname,
                     dst_sb.st_mode | extra_permissions) != 0)
            extra_permissions = 0;
    }

    if (x->data_copy_required) {
        size_t dst_io_size = sub_7fd0(dst_sb.st_blksize, src_sb);
        size_t hole_size;
        size_t buf_size;
        off_t max_n_read;
        int scantype;
        bool copied;
        unsigned char scan_state[48];

        hole_size = (dst_sb.st_blksize > 0
                     && (uintmax_t) dst_sb.st_blksize
                        <= (uintmax_t) PTRDIFF_MAX / 8)
                    ? (size_t) dst_sb.st_blksize : 512;

        scantype = sub_6780(src_fd, src_sb, scan_state);
        if (scantype == 0) {
            error(0, errno, gettext("cannot lseek %s"),
                  sub_14b40(4, src_name));
            goto close_both;
        }

        (void) posix_fadvise(src_fd, 0, 0, POSIX_FADV_SEQUENTIAL);
        buf_size = sub_dbf0(sub_7fd0(src_sb->st_blksize, src_sb),
                            dst_io_size, (size_t) SSIZE_MAX);

        max_n_read = (off_t) dst_io_size;
        if (S_ISREG(src_sb->st_mode)
            && src_sb->st_size >= max_n_read)
            max_n_read = src_sb->st_size + 1;
        if (max_n_read > 0) {
            uintmax_t n = (uintmax_t) max_n_read + buf_size - 1;
            max_n_read = (off_t) (n - n % buf_size);
        } else {
            max_n_read = 0;
        }

        if (S_ISREG(src_sb->st_mode)
            && scantype == 3
            && (x->sparse_mode == SPARSE_ALWAYS
                || (x->sparse_mode == SPARSE_AUTO && scantype != 1))) {
            copied = sub_7b50(src_fd, dst_fd, &copy_buffer,
                              src_sb->st_size, buf_size, total_n_read,
                              max_n_read, x->sparse_mode,
                              x->reflink_mode != REFLINK_NEVER,
                              src_name, dst_name);
        } else {
            bool make_holes = x->sparse_mode == SPARSE_ALWAYS;
            size_t copy_hole_size = scantype == 3 ? hole_size : 0;

            copied = sub_6a40(src_fd, dst_fd, &copy_buffer, buf_size,
                              copy_hole_size, make_holes,
                              x->reflink_mode != REFLINK_NEVER,
                              src_name, dst_name, -1,
                              &total_n_read, &last_write_made_hole);
        }

        if (!copied)
            goto close_both;

        if (last_write_made_hole
            && ftruncate(dst_fd, total_n_read) != 0) {
            error(0, errno, gettext("failed to extend %s"),
                  sub_14b40(4, dst_name));
            goto close_both;
        }
    }

preserve_metadata:
    return_val = true;

    if (x->preserve_timestamps) {
        times[0] = src_sb->st_atim;
        times[1] = src_sb->st_mtim;
        if (futimens(dst_fd, times) != 0) {
            error(0, errno, gettext("preserving times for %s"),
                  sub_14b40(4, dst_name));
            if (x->require_preserve) {
                return_val = false;
                goto close_both;
            }
        }
    }

    if (x->preserve_ownership
        && (src_sb->st_uid != dst_sb.st_uid
            || src_sb->st_gid != dst_sb.st_gid)) {
        int owner_result = sub_8430(x, dst_name, dst_dirfd, dst_relname,
                                    dst_fd, src_sb->st_mode,
                                    src_sb->st_uid, src_sb->st_gid,
                                    *new_dst, &dst_sb);
        if (owner_result < 0) {
            return_val = false;
            goto close_both;
        }
        if (owner_result == 0)
            dst_mode &= ~07000;
    }

    if (x->preserve_xattr
        && !sub_7040(src_name, src_fd, dst_name, dst_fd, x))
        return_val = !x->require_preserve_xattr;

    if (x->move_mode || x->preserve_mode) {
        if (sub_caa0(src_name, src_fd, dst_name, dst_fd, dst_mode) != 0
            && x->require_preserve)
            return_val = false;
    } else if (x->set_mode) {
        if (sub_cb50(dst_name, dst_fd, x->mode) != 0)
            return_val = false;
    } else if (x->explicit_no_preserve_mode && *new_dst) {
        if (sub_cb50(dst_name, dst_fd, (~sub_8640()) & 0666) != 0)
            return_val = false;
    } else {
        mode_t mask = sub_8640();

        if (extra_permissions || (omitted_permissions & ~mask)) {
            if (sub_7020(dst_fd, dst_dirfd, dst_relname,
                         dst_mode & ~mask) != 0) {
                error(0, errno, gettext("preserving permissions for %s"),
                      sub_14b40(4, dst_name));
                if (x->require_preserve)
                    return_val = false;
            }
        }
    }

close_both:
    if (dst_fd >= 0 && close(dst_fd) != 0) {
        error(0, errno, gettext("failed to close %s"),
              sub_14b40(4, dst_name));
        return_val = false;
    }

close_src:
    if (close(src_fd) != 0) {
        error(0, errno, gettext("failed to close %s"),
              sub_14b40(4, src_name));
        return_val = false;
    }

    free(copy_buffer);
    return return_val;
}


