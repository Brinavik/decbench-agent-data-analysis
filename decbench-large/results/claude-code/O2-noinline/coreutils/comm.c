// Function: compare_files @ 0x2c30
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <errno.h>

/* gnulib line buffer (24 bytes on LP64). */
struct linebuffer
{
  size_t size;      /* Allocated. */
  size_t length;    /* Used. */
  char *buffer;
};

#define STREQ(a, b) (strcmp ((a), (b)) == 0)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define _(s) (s)
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define FADVISE_SEQUENTIAL 2
/* Enough room for the decimal representation of any uintmax_t. */
#define INT_BUFSIZE_BOUND_UINTMAX 21

/* Command-line option state (defined in the translation unit). */
extern char delimiter;                        /* line/record separator */
extern char const *col_sep;                   /* column separator string */
extern bool hard_LC_COLLATE;                  /* locale-aware comparison */
extern bool total_option;                     /* print the "total" summary */
extern bool seen_unpairable;                  /* saw a line only in one file */
extern bool issued_disorder_warning[2];       /* per-file disorder reported */

/* Helpers from elsewhere in the program / gnulib. */
extern void initbuffer (struct linebuffer *);
extern struct linebuffer *readlinebuffer_delim (struct linebuffer *, FILE *,
                                                char);
extern void writeline (struct linebuffer const *, FILE *, int);
extern void check_order (struct linebuffer const *, struct linebuffer const *,
                         int);
extern int xmemcoll (char *, size_t, char *, size_t);
extern void fadvise (FILE *, int);
extern char *quotef (char const *);
extern char *umaxtostr (uintmax_t, char *);
extern int close_stream (FILE *);
extern void error (int, int, char const *, ...);

/* Compare INFILES[0] and INFILES[1], writing the columnar diff to stdout. */
static void
compare_files (char **infiles)
{
  /* For each file, we have four line buffers in lba.  */
  struct linebuffer lba[2][4];

  /* thisline[i] points to the line buffer holding the next available line
     in file i, or is null if there are no lines left in that file.  */
  struct linebuffer *thisline[2];

  /* all_line[i][j] points to the four line buffers of file i.  */
  struct linebuffer *all_line[2][4];

  /* Rotates through the four buffers of each input file: alt[i][0] is the
     index of the current buffer, alt[i][1] is the index of the previous one. */
  int alt[2][2];

  /* streams[i] holds the input stream for file i.  */
  FILE *streams[2];

  /* Number of lines only in file 1, only in file 2, and in both.  */
  uintmax_t total[3];

  int i, j;

  /* Set up the initial state.  */
  for (i = 0; i < 2; i++)
    {
      for (j = 0; j < 4; j++)
        {
          initbuffer (&lba[i][j]);
          all_line[i][j] = &lba[i][j];
        }

      alt[i][0] = 0;
      alt[i][1] = 0;

      streams[i] = (STREQ (infiles[i], "-")
                    ? stdin
                    : fopen (infiles[i], "r"));
      if (!streams[i])
        error (EXIT_FAILURE, errno, "%s", quotef (infiles[i]));

      fadvise (streams[i], FADVISE_SEQUENTIAL);

      thisline[i] = readlinebuffer_delim (all_line[i][alt[i][0]], streams[i],
                                          delimiter);
      if (ferror (streams[i]))
        error (EXIT_FAILURE, errno, "%s", quotef (infiles[i]));
    }

  total[0] = total[1] = total[2] = 0;

  while (thisline[0] || thisline[1])
    {
      int order;
      bool fill_up[2] = { false, false };

      /* Compare the next available lines of the two files.  */
      if (!thisline[0])
        order = 1;
      else if (!thisline[1])
        order = -1;
      else
        {
          if (hard_LC_COLLATE)
            order = xmemcoll (thisline[0]->buffer, thisline[0]->length - 1,
                              thisline[1]->buffer, thisline[1]->length - 1);
          else
            {
              size_t len = MIN (thisline[0]->length, thisline[1]->length) - 1;
              order = memcmp (thisline[0]->buffer, thisline[1]->buffer, len);
              if (order == 0)
                order = (thisline[0]->length < thisline[1]->length
                         ? -1
                         : thisline[0]->length != thisline[1]->length);
            }
        }

      /* Output the smaller line, or the common line, and note which files
         must be advanced.  */
      if (order == 0)
        {
          total[2]++;
          writeline (thisline[1], stdout, 3);
          fill_up[0] = true;
          fill_up[1] = true;
        }
      else if (order <= 0)
        {
          seen_unpairable = true;
          total[0]++;
          writeline (thisline[0], stdout, 1);
          fill_up[0] = true;
        }
      else
        {
          seen_unpairable = true;
          total[1]++;
          writeline (thisline[1], stdout, 2);
          fill_up[1] = true;
        }

      /* Step each file whose line was just consumed, checking that its
         input remains in sorted order.  */
      for (i = 0; i < 2; i++)
        if (fill_up[i])
          {
            struct linebuffer *prevline = thisline[i];
            int prevprev = alt[i][1];

            alt[i][1] = alt[i][0];
            alt[i][0] = (alt[i][0] + 1) & 3;

            thisline[i] = readlinebuffer_delim (all_line[i][alt[i][0]],
                                                streams[i], delimiter);

            if (thisline[i])
              check_order (prevline, thisline[i], i + 1);
            else if (all_line[i][prevprev]->buffer)
              check_order (all_line[i][prevprev], prevline, i + 1);

            if (ferror (streams[i]))
              error (EXIT_FAILURE, errno, "%s", quotef (infiles[i]));
          }
    }

  /* Close the input files.  */
  for (i = 0; i < 2; i++)
    if (close_stream (streams[i]) != 0)
      error (EXIT_FAILURE, errno, "%s", quotef (infiles[i]));

  if (total_option)
    {
      char buf1[INT_BUFSIZE_BOUND_UINTMAX];
      char buf2[INT_BUFSIZE_BOUND_UINTMAX];
      char buf3[INT_BUFSIZE_BOUND_UINTMAX];
      printf ("%s%s%s%s%s%s%s%c",
              umaxtostr (total[0], buf1), col_sep,
              umaxtostr (total[1], buf2), col_sep,
              umaxtostr (total[2], buf3), col_sep,
              _("total"), delimiter);
    }

  if (issued_disorder_warning[0] || issued_disorder_warning[1])
    error (EXIT_FAILURE, 0, _("input is not in sorted order"));

  exit (EXIT_SUCCESS);
}


