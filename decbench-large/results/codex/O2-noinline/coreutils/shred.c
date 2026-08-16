// Function: dopass @ 0x3a20
#include <errno.h>
#include <error.h>
#include <inttypes.h>
#include <libintl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define _(msgid) dcgettext (NULL, msgid, 5)

struct randread_source;

int
dopass (int fd, struct stat const *st, char const *qname, off_t *sizep,
          int type, struct randread_source *rand_source,
          unsigned long int pass, unsigned long int passes)
{
  extern void *xalignalloc (size_t, size_t);
  extern bool rewind_fd (int, mode_t);
  extern void direct_mode (int, bool);
  extern void fillpattern (int, unsigned char *, size_t);
  extern void passname (unsigned char const *, char *);
  extern void randread (struct randread_source *, void *, size_t);
  extern char *human_readable (uintmax_t, char *, int, uintmax_t, uintmax_t);
  extern char *umaxtostr (uintmax_t, char *);
  extern int dosync (int, char const *);

  enum
    {
      WRITE_SIZE = 64 * 1024,
      THREE_BYTE_WRITE_SIZE = 60 * 1024,
      SECTOR_SIZE = 512,
      HUMAN_BUFSIZE = 652,
      HUMAN_PROGRESS = 0x1b2,
      HUMAN_SIZE = 0x1b0,
      UPDATE_INTERVAL = 5
    };

  off_t target_size = *sizep;
  bool three_byte_pattern = false;

  if (type > 0)
    {
      unsigned int p = (unsigned int) type & 0xfff;
      unsigned int repeated = (p << 12) | p;
      unsigned char a = repeated;
      unsigned char b = repeated >> 4;
      unsigned char c = repeated >> 8;
      three_byte_pattern = a != b || b != c;
    }

  size_t write_size = (three_byte_pattern
                       ? THREE_BYTE_WRITE_SIZE : WRITE_SIZE);
  size_t allocation_size = write_size + (three_byte_pattern ? 0 : 2);
  unsigned char *buffer = xalignalloc ((size_t) getpagesize (),
                                       allocation_size);
  bool direct_done = 0 < target_size && (uintmax_t) target_size < write_size;

  if (!direct_done)
    direct_mode (fd, true);

  bool rewound = rewind_fd (fd, st->st_mode);
  if (!rewound)
    {
      error (0, errno, _("%s: cannot rewind"), qname);
      free (buffer);
      return -1;
    }

  bool size_known = 0 <= target_size;
  if (0 <= type)
    {
      size_t fill_size = allocation_size;
      if (size_known && (uintmax_t) target_size < fill_size)
        fill_size = target_size;
      fillpattern (type, buffer, fill_size);
    }

  char pass_string[7];
  passname (0 <= type ? buffer : NULL, pass_string);

  char previous[HUMAN_BUFSIZE];
  char progress_buf[HUMAN_BUFSIZE];
  char size_buf[HUMAN_BUFSIZE];
  previous[0] = '\0';

  bool had_error = false;
  off_t offset = 0;
  time_t now = 0;
  time_t next_update = 0;

  if (passes != 0)
    {
      error (0, 0, _("%s: pass %lu/%lu (%s)..."),
             qname, pass, passes, pass_string);
      next_update = time (NULL) + UPDATE_INTERVAL;
    }

  for (;;)
    {
      size_t block_size = write_size;

      if (size_known)
        {
          if (target_size <= offset)
            break;

          uintmax_t remaining = (uintmax_t) target_size - (uintmax_t) offset;
          if (remaining < block_size)
            block_size = remaining;
        }

      if (type < 0)
        randread (rand_source, buffer, block_size);

      size_t written = 0;
      while (written < block_size)
        {
          ssize_t n = write (fd, buffer + written, block_size - written);
          if (0 < n)
            {
              written += n;
              continue;
            }

          int write_errno = errno;

          if (!size_known && (n == 0 || write_errno == ENOSPC))
            {
              if ((uintmax_t) offset > INT64_MAX - written)
                {
                  error (0, 0, _("%s: file too large"), qname);
                  free (buffer);
                  return -1;
                }

              target_size = offset + written;
              *sizep = target_size;
              size_known = 0 <= target_size;
              block_size = written;
              break;
            }

          if (write_errno == EINVAL && !direct_done)
            {
              direct_mode (fd, false);
              direct_done = rewound;
              continue;
            }

          char *offset_string = umaxtostr ((uintmax_t) offset + written,
                                           size_buf);
          error (0, write_errno, _("%s: error writing at offset %s"),
                 qname, offset_string);

          if (write_errno == EIO)
            {
              size_t next_sector = (written | (SECTOR_SIZE - 1)) + 1;
              if (next_sector < block_size)
                {
                  off_t seek_to = offset + next_sector;
                  if (lseek (fd, seek_to, SEEK_SET) != (off_t) -1)
                    {
                      written = next_sector;
                      had_error = size_known;
                      continue;
                    }

                  error (0, errno, _("%s: lseek failed"), qname);
                }
            }

          free (buffer);
          return -1;
        }

      if ((uintmax_t) offset > INT64_MAX - block_size)
        {
          error (0, 0, _("%s: file too large"), qname);
          free (buffer);
          return -1;
        }

      offset += block_size;

      if (passes == 0)
        continue;

      if (offset != target_size)
        {
          now = time (NULL);
          if (now < next_update)
            continue;
        }
      else if (previous[0] == '\0')
        {
          now = time (NULL);
          if (now < next_update)
            continue;
        }

      char *progress = human_readable ((uintmax_t) offset, progress_buf,
                                       HUMAN_PROGRESS, 1, 1);
      if (strcmp (previous, progress) == 0)
        continue;

      if (size_known)
        {
          int percent;
          if (target_size == 0)
            percent = 100;
          else if ((uintmax_t) offset <= UINT64_MAX / 100)
            percent = (uintmax_t) offset * 100 / (uintmax_t) target_size;
          else
            percent = (uintmax_t) offset / ((uintmax_t) target_size / 100);

          char *total = human_readable ((uintmax_t) target_size, size_buf,
                                        HUMAN_SIZE, 1, 1);
          char *shown = target_size == offset ? total : progress;
          error (0, 0, _("%s: pass %lu/%lu (%s)...%s/%s %d%%"),
                 qname, pass, passes, pass_string, shown, total, percent);
          strcpy (previous, shown);
        }
      else
        {
          error (0, 0, _("%s: pass %lu/%lu (%s)...%s"),
                 qname, pass, passes, pass_string, progress);
          strcpy (previous, progress);
        }

      next_update = now + UPDATE_INTERVAL;
      if (dosync (fd, qname) != 0)
        {
          if (errno != EIO)
            {
              free (buffer);
              return -1;
            }
          had_error = true;
        }
    }

  if (dosync (fd, qname) != 0)
    {
      int sync_errno = errno;
      free (buffer);
      return sync_errno == EIO ? 1 : -1;
    }

  free (buffer);
  return had_error;
}


