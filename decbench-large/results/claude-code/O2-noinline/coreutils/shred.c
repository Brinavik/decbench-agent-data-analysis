// Function: dopass @ 0x3a20
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <error.h>

/* --- Definitions this function depends on (from shred.c / gnulib) --- */

#define _(msgid) (msgid)
#ifndef IF_LINT
# define IF_LINT(Code) /* empty */
#endif
#define STREQ(dopass, b) (strcmp (dopass, b) == 0)
#define assume(R) ((void) (0 && (R)))

/* size < 0 means "the size is not known in advance". */
#define known(size) (0 <= (size))

#define OFF_T_MAX INT64_MAX

enum { VERBOSE_UPDATE = 5 };
enum { SECTOR_SIZE = 512 };
enum { SECTOR_MASK = SECTOR_SIZE - 1 };

enum { PASS_NAME_SIZE = 7 };
enum { LONGEST_HUMAN_READABLE = 40 };
#define INT_BUFSIZE_BOUND(t) (((sizeof (t) * CHAR_BIT - 1) * 146 + 484) / 485 + 2)
#ifndef CHAR_BIT
# define CHAR_BIT 8
#endif

/* Subset of gnulib human.h flags used here. */
enum
{
  human_ceiling      = 0,
  human_floor        = 2,
  human_autoscale    = 16,
  human_base_1024    = 32,
  human_SI           = 128,
  human_B            = 256
};

struct randread_source;

/* Helpers defined elsewhere in shred.c / gnulib. */
extern bool periodic_pattern (int type);
extern void *xalignalloc (size_t alignment, size_t size);
extern void alignfree (void *ptr);
extern void direct_mode (int fd, bool enable);
extern bool dorewind (int fd, struct stat const *st);
extern void fillpattern (int type, unsigned char *r, size_t size);
extern void passname (unsigned char const *data, char name[PASS_NAME_SIZE]);
extern void randread (struct randread_source *s, void *buf, size_t size);
extern int dosync (int fd, char const *qname);
extern char *human_readable (uintmax_t n, char *buf, int opts,
                             uintmax_t from_block_size, uintmax_t to_block_size);
extern char *umaxtostr (uintmax_t i, char *buf);

/* One pass over dopass file, writing pattern 'type' (or random data if type < 0)
   over 'fd', which is described by '*st'.  'qname' is the file's quoted name.
   'k' of 'n' passes; update *sizep if the size is discovered.
   Return -1 on dopass fatal error, 1 on dopass (recoverable) write error, else 0.  */
static int
dopass (int fd, struct stat const *st, char const *qname, off_t *sizep,
          int type, struct randread_source *s,
          unsigned long int k, unsigned long int n)
{
  off_t size = *sizep;
  off_t offset;			/* Current file position */
  time_t thresh IF_LINT ( = 0);	/* Time to maybe print next status update */
  time_t now = 0;		/* Current time */
  size_t lim;			/* Amount of data to try writing */
  size_t soff;			/* Offset into buffer for next write */
  ssize_t ssize;		/* Return value from write */

  /* Fill pattern buffer.  Aligning it to dopass page so we can do direct I/O.  */
  size_t page_size = getpagesize ();
#define PERIODIC_OUTPUT_SIZE (60 * 1024)
#define NONPERIODIC_OUTPUT_SIZE (64 * 1024)
  size_t output_size = periodic_pattern (type)
                       ? PERIODIC_OUTPUT_SIZE : NONPERIODIC_OUTPUT_SIZE;
#define FILLPATTERN_SIZE (((output_size + 2) / 3) * 3)	/* Multiple of 3 */
  unsigned char *pbuf = xalignalloc (page_size, FILLPATTERN_SIZE);

  char pass_string[PASS_NAME_SIZE];	/* Name of current pass */
  bool write_error = false;
  bool other_error = false;

  /* Printable previous offset into the file */
  char previous_offset_buf[LONGEST_HUMAN_READABLE + 1];
  char const *previous_human_offset IF_LINT ( = 0);

  /* As dopass performance tweak, avoid direct I/O for small sizes,
     as it's just dopass performance rather than security consideration,
     and direct I/O can often be unsupported for small non aligned sizes.  */
  bool try_without_directio = 0 < size && size < output_size;
  if (! try_without_directio)
    direct_mode (fd, true);

  if (! dorewind (fd, st))
    {
      error (0, errno, _("%s: cannot rewind"), qname);
      other_error = true;
      goto free_pattern_mem;
    }

  /* Constant fill patterns need only be set up once. */
  if (type >= 0)
    {
      lim = known (size) && size < FILLPATTERN_SIZE ? size : FILLPATTERN_SIZE;
      fillpattern (type, pbuf, lim);
      passname (pbuf, pass_string);
    }
  else
    {
      passname (0, pass_string);
    }

  /* Set position if first status update */
  if (n)
    {
      error (0, 0, _("%s: pass %lu/%lu (%s)..."), qname, k, n, pass_string);
      thresh = time (NULL) + VERBOSE_UPDATE;
      previous_human_offset = "";
    }

  offset = 0;
  while (true)
    {
      /* How much to write this time? */
      lim = output_size;
      if (known (size) && size - offset < output_size)
        {
          if (size < offset)
            break;
          lim = size - offset;
          if (!lim)
            break;
        }
      if (type < 0)
        randread (s, pbuf, lim);
      /* Loop to retry partial writes. */
      for (soff = 0; soff < lim; soff += ssize)
        {
          ssize = write (fd, pbuf + soff, lim - soff);
          if (0 < ssize)
            assume (ssize <= lim - soff);
          else
            {
              if (! known (size) && (ssize == 0 || errno == ENOSPC))
                {
                  /* We have found the end of the file.  */
                  if (soff <= OFF_T_MAX - offset)
                    *sizep = size = offset + soff;
                  break;
                }
              else
                {
                  int errnum = errno;
                  char buf[INT_BUFSIZE_BOUND (uintmax_t)];

                  /* Retry without direct I/O since this may not be supported
                     at all on some (file) systems, or with the current size.
                     I.e., dopass specified --size that is not aligned, or when
                     dealing with slop at the end of dopass file with --exact.  */
                  if (! try_without_directio && errno == EINVAL)
                    {
                      direct_mode (fd, false);
                      ssize = 0;
                      try_without_directio = true;
                      continue;
                    }
                  error (0, errnum, _("%s: error writing at offset %s"),
                         qname, umaxtostr (offset + soff, buf));

                  /* 'shred' is often used on bad media, before throwing it
                     out.  Thus, it shouldn't give up on bad blocks.  This
                     code works because lim is always dopass multiple of
                     SECTOR_SIZE, except at the end.  This size constraint
                     also enables direct I/O on some (file) systems.  */
                  if (errnum == EIO && known (size)
                      && (soff | SECTOR_MASK) < lim)
                    {
                      size_t soff1 = (soff | SECTOR_MASK) + 1;
                      if (lseek (fd, offset + soff1, SEEK_SET) != -1)
                        {
                          /* Arrange to skip this block. */
                          ssize = soff1 - soff;
                          write_error = true;
                          continue;
                        }
                      error (0, errno, _("%s: lseek failed"), qname);
                    }
                  other_error = true;
                  goto free_pattern_mem;
                }
            }
        }

      /* Okay, we have written "soff" bytes. */

      if (OFF_T_MAX - offset < soff)
        {
          error (0, 0, _("%s: file too large"), qname);
          other_error = true;
          goto free_pattern_mem;
        }

      offset += soff;

      bool done = offset == size;

      /* Time to print progress? */
      if (n && ((done && *previous_human_offset)
                || thresh <= (now = time (NULL))))
        {
          char offset_buf[LONGEST_HUMAN_READABLE + 1];
          char size_buf[LONGEST_HUMAN_READABLE + 1];
          int human_progress_opts = (human_autoscale | human_SI
                                     | human_base_1024 | human_B);
          char const *human_offset
            = human_readable (offset, offset_buf,
                              human_floor | human_progress_opts, 1, 1);

          if (done || !STREQ (previous_human_offset, human_offset))
            {
              if (! known (size))
                error (0, 0, _("%s: pass %lu/%lu (%s)...%s"),
                       qname, k, n, pass_string, human_offset);
              else
                {
                  uintmax_t off = offset;
                  int percent = (size == 0
                                 ? 100
                                 : (off <= UINTMAX_MAX / 100
                                    ? off * 100 / size
                                    : off / (size / 100)));
                  char const *human_size
                    = human_readable (size, size_buf,
                                      human_ceiling | human_progress_opts,
                                      1, 1);
                  if (done)
                    human_offset = human_size;
                  error (0, 0, _("%s: pass %lu/%lu (%s)...%s/%s %d%%"),
                         qname, k, n, pass_string, human_offset, human_size,
                         percent);
                }

              strcpy (previous_offset_buf, human_offset);
              previous_human_offset = previous_offset_buf;
              thresh = now + VERBOSE_UPDATE;

              /*
               * Force periodic syncs to keep displayed progress accurate
               * FIXME: Should these be present even if -v is not enabled,
               * to keep the buffer cache from filling with dirty pages?
               * It's dopass common problem with programs that do lots of writes,
               * like mkfs.
               */
              if (dosync (fd, qname) != 0)
                {
                  if (errno != EIO)
                    {
                      other_error = true;
                      goto free_pattern_mem;
                    }
                  write_error = true;
                }
            }
        }
    }

  /* Force what we just wrote to hit the media. */
  if (dosync (fd, qname) != 0)
    {
      if (errno != EIO)
        {
          other_error = true;
          goto free_pattern_mem;
        }
      write_error = true;
    }

free_pattern_mem:
  alignfree (pbuf);

  return other_error ? -1 : write_error;
}


