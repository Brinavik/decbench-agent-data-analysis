// Function: cmp @ 0x35e0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <error.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <locale.h>
#include <sys/stat.h>

/* Word type used for the fast, word-at-a-time buffer comparison. */
typedef unsigned long word;

#define cmp 2

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define TYPE_MAXIMUM(t) \
  ((t) (((uintmax_t) 1 << (sizeof (t) * CHAR_BIT - 1)) - 1))
#define INT_BUFSIZE_BOUND(t) (3 + (sizeof (t) * CHAR_BIT) / 3)

#define _(msgid) gettext (msgid)

/* Kind of output requested (set from the command line). */
enum comparison_type
{
  type_first_diff,	/* Print the first difference.  */
  type_all_diffs,	/* Print all differences (cmp -l).  */
  type_no_stdout,	/* No stdout output; only test whether they differ.  */
  type_status		/* Exit status only; print no messages at all.  */
};

/* Globals shared with the rest of the program. */
extern enum comparison_type comparison_type;
extern bool opt_print_bytes;		/* cmp -b */
extern uintmax_t bytes;			/* Maximum number of bytes to compare. */
extern off_t ignore_initial[2];		/* Bytes to ignore at the start. */
extern size_t buf_size;			/* Size of each input buffer. */
extern int file_desc[2];		/* File descriptors of the two inputs. */
extern char const *file[2];		/* Names of the two inputs. */
extern word *buffer[2];			/* The two input buffers. */
extern struct stat stat_buf[2];		/* Status of the two inputs. */

/* Helpers defined elsewhere in the program. */
extern off_t file_position (int i);
extern size_t block_read (int fd, char *buf, size_t nbytes);
extern size_t block_compare (word const *p0, word const *p1);
extern off_t count_newlines (char *buf, size_t nbytes);
extern void sprintc (char *s, unsigned char c);
extern char *offtostr (off_t i, char *buf);
extern bool hard_locale (int category);
extern char *gettext (char const *msgid);

/* Compare the two files already open on file_desc[0] and file_desc[1],
   using buffer[0] and buffer[1].  Return EXIT_SUCCESS if they are the
   same, EXIT_FAILURE if different, cmp (via error) on trouble.  */

static int
cmp (void)
{
  bool at_line_start = true;
  off_t line_number = 1;	/* Line number (1...) of the difference.  */
  off_t byte_number = 1;	/* Byte number (1...) of the difference.  */
  intmax_t remaining = bytes;	/* Number of bytes left to compare.  */
  size_t read0, read1;		/* Bytes read from each file.  */
  size_t first_diff;		/* Offset (0...) of the first difference.  */
  size_t smaller;		/* The lesser of read0 and read1.  */
  word *buffer0 = buffer[0];
  word *buffer1 = buffer[1];
  char *buf0 = (char *) buffer0;
  char *buf1 = (char *) buffer1;
  int differing = 0;
  int offset_width;

  if (comparison_type == type_all_diffs)
    {
      /* Compute the width of the printed byte offsets.  */
      off_t byte_number_max = MIN (bytes, TYPE_MAXIMUM (off_t));

      if (S_ISREG (stat_buf[0].st_mode))
	byte_number_max = MIN (byte_number_max,
			       stat_buf[0].st_size - file_position (0));
      if (S_ISREG (stat_buf[1].st_mode))
	byte_number_max = MIN (byte_number_max,
			       stat_buf[1].st_size - file_position (1));

      for (offset_width = 1; (byte_number_max /= 10) != 0; offset_width++)
	continue;
    }

  /* Skip the ignored prefix of each file.  If the file is not seekable,
     read and discard the prefix instead.  */
  for (int i = 0; i < 2; i++)
    {
      off_t ig = ignore_initial[i];
      if (ig != 0 && file_position (i) == -1)
	{
	  do
	    {
	      size_t bytes_to_read = MIN (ig, buf_size);
	      size_t r = block_read (file_desc[i], buf0, bytes_to_read);
	      if (r != bytes_to_read)
		{
		  if (r == SIZE_MAX)
		    error (cmp, errno, "%s", file[i]);
		  break;
		}
	      ig -= r;
	    }
	  while (ig != 0);
	}
    }

  do
    {
      size_t bytes_to_read = buf_size;

      if (0 <= remaining)
	{
	  if (remaining < bytes_to_read)
	    bytes_to_read = remaining;
	  remaining -= bytes_to_read;
	}

      read0 = block_read (file_desc[0], buf0, bytes_to_read);
      if (read0 == SIZE_MAX)
	error (cmp, errno, "%s", file[0]);
      read1 = block_read (file_desc[1], buf1, bytes_to_read);
      if (read1 == SIZE_MAX)
	error (cmp, errno, "%s", file[1]);

      smaller = MIN (read0, read1);

      if (memcmp (buf0, buf1, smaller) != 0)
	{
	  /* The buffers differ within their common prefix.

	     Place sentinel bytes just past the buffers so that the
	     word-at-a-time comparison below is guaranteed to stop, then
	     zero-fill each buffer up to the next word boundary so that
	     block_compare may read whole words safely.  */
	  if (read0 < read1)
	    {
	      buf0[read1] = 'y';
	      buf0[read0] = ~buf1[read0];
	      buf1[read1] = ~buf0[read1];
	    }
	  else
	    {
	      buf1[read0] = 'U';
	      if (read0 == read1)
		buf0[read1] = 'y';
	      buf0[read0] = ~buf1[read0];
	      buf1[read1] = ~buf0[read1];
	    }

	  for (size_t k = 1; k <= ((~read0) & (sizeof (word) - 1)); k++)
	    buf0[read0 + k] = 0;
	  for (size_t k = 1; k <= ((~read1) & (sizeof (word) - 1)); k++)
	    buf1[read1 + k] = 0;

	  first_diff = block_compare (buffer0, buffer1);

	  byte_number += first_diff;
	  if (comparison_type == type_first_diff && first_diff != 0)
	    line_number += count_newlines (buf0, first_diff);

	  if (first_diff < smaller)
	    switch (comparison_type)
	      {
	      case type_first_diff:
		{
		  char byte_buf[INT_BUFSIZE_BOUND (off_t)];
		  char line_buf[INT_BUFSIZE_BOUND (off_t)];
		  char const *byte_num = offtostr (byte_number, byte_buf);
		  char const *line_num = offtostr (line_number, line_buf);

		  if (!opt_print_bytes)
		    {
		      /* See POSIX for the required format.  In a locale
			 with no translation, keep the traditional word
			 "char" to stay compatible with older cmp.  */
		      char const *msgid = "%s %s differ: byte %s, line %s\n";
		      char const *msg = _(msgid);
		      if (msg == msgid && !hard_locale (LC_MESSAGES))
			msg = "%s %s differ: char %s, line %s\n";
		      printf (msg, file[0], file[1], byte_num, line_num);
		    }
		  else
		    {
		      unsigned char c0 = buf0[first_diff];
		      unsigned char c1 = buf1[first_diff];
		      char s0[5];
		      char s1[5];
		      sprintc (s0, c0);
		      sprintc (s1, c1);
		      printf (_("%s %s differ: byte %s, line %s"
				" is %3o %s %3o %s\n"),
			      file[0], file[1], byte_num, line_num,
			      c0, s0, c1, s1);
		    }
		  return EXIT_FAILURE;
		}

	      case type_all_diffs:
		{
		  off_t byte_num = byte_number;

		  for (size_t i = first_diff; i < smaller; i++)
		    {
		      unsigned char c0 = buf0[i];
		      unsigned char c1 = buf1[i];
		      if (c0 != c1)
			{
			  char byte_buf[INT_BUFSIZE_BOUND (off_t)];
			  char const *byte_str = offtostr (byte_num, byte_buf);

			  if (opt_print_bytes)
			    {
			      char s0[5];
			      char s1[5];
			      sprintc (s0, c0);
			      sprintc (s1, c1);
			      printf ("%*s %3o %-4s %3o %s\n",
				      offset_width, byte_str, c0, s0, c1, s1);
			    }
			  else
			    printf ("%*s %3o %3o\n",
				    offset_width, byte_str, c0, c1);
			}
		      byte_num++;
		    }

		  byte_number = byte_num;
		  differing = -1;
		}
		break;

	      case type_no_stdout:
		differing = 1;
		goto done;

	      case type_status:
		return EXIT_FAILURE;
	      }
	}
      else
	{
	  byte_number += smaller;
	  if (comparison_type == type_first_diff && smaller != 0)
	    {
	      line_number += count_newlines (buf0, smaller);
	      at_line_start = buf0[smaller - 1] == '\n';
	    }
	}

      if (read0 != read1)
	{
	  /* One file is shorter than the other.  Report the EOF unless we
	     are only interested in the exit status.  */
	  if (comparison_type != type_status)
	    {
	      char const *name = file[read0 > read1];

	      if (byte_number == 1)
		fprintf (stderr, _("cmp: EOF on %s which is empty\n"), name);
	      else
		{
		  char byte_buf[INT_BUFSIZE_BOUND (off_t)];
		  char const *byte_num = offtostr (byte_number - 1, byte_buf);

		  if (comparison_type == type_first_diff)
		    {
		      char line_buf[INT_BUFSIZE_BOUND (off_t)];
		      char const *line_num =
			offtostr (line_number - at_line_start, line_buf);
		      fprintf (stderr,
			       (at_line_start
				? _("cmp: EOF on %s after byte %s, line %s\n")
				: _("cmp: EOF on %s after byte %s,"
				    " in line %s\n")),
			       name, byte_num, line_num);
		    }
		  else
		    fprintf (stderr, _("cmp: EOF on %s after byte %s\n"),
			     name, byte_num);
		}
	    }

	  return EXIT_FAILURE;
	}
    }
  while (read0 == buf_size);

 done:
  return differing != 0 ? EXIT_FAILURE : EXIT_SUCCESS;
}


