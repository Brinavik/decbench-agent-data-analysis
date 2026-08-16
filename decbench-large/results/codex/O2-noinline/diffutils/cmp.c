// Function: cmp @ 0x35e0
#include <errno.h>
#include <inttypes.h>
#include <libintl.h>
#include <locale.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

enum comparison_type
{
  type_first_diff,
  type_all_diffs,
  type_no_stdout,
  type_status
};

extern enum comparison_type comparison_type;
extern bool print_chars;
extern off_t bytes_to_compare;
extern off_t ignore_initial[2];
extern size_t buffer_size;
extern unsigned char *buffer[2];
extern int file_desc[2];
extern char const *file[2];
extern struct stat stat_buf[2];

extern size_t block_read(int, void *, size_t);
extern size_t block_compare(unsigned char const *, unsigned char const *);
extern off_t file_position(int);
extern size_t count_newlines(unsigned char *, size_t);
extern void sprint_char(char *, unsigned char);
extern char *offtostr(off_t, char *);
extern bool hard_locale(int);
extern void error(int, int, char const *, ...);

int
cmp(void)
{
  off_t byte_number = 1;
  off_t line_number = 1;
  off_t remaining = bytes_to_compare;
  int differing = 0;
  int byte_number_width = 0;
  bool ended_with_newline = true;
  size_t i;

  if (comparison_type == type_all_diffs)
    {
      off_t byte_number_max = (remaining < 0 ? INT64_MAX : remaining);

      if (S_ISREG(stat_buf[0].st_mode))
        {
          off_t n = stat_buf[0].st_size - file_position(0);
          if (n < byte_number_max)
            byte_number_max = n;
        }
      if (S_ISREG(stat_buf[1].st_mode))
        {
          off_t n = stat_buf[1].st_size - file_position(1);
          if (n < byte_number_max)
            byte_number_max = n;
        }

      byte_number_width = 1;
      while ((byte_number_max /= 10) != 0)
        ++byte_number_width;
    }

  for (i = 0; i < 2; ++i)
    {
      off_t skip = ignore_initial[i];

      if (skip != 0 && file_position((int) i) < 0)
        while (skip != 0)
          {
            size_t request = ((uintmax_t) skip < buffer_size
                              ? (size_t) skip : buffer_size);
            size_t nread = block_read(file_desc[i], buffer[0], request);

            if (nread == (size_t) -1)
              {
                error(2, errno, "%s", file[i]);
                return 2;
              }
            if (nread != request)
              break;
            skip -= request;
          }
    }

  for (;;)
    {
      size_t request = buffer_size;
      size_t read0;
      size_t read1;
      size_t common;

      if (remaining >= 0)
        {
          if ((uintmax_t) remaining < request)
            request = (size_t) remaining;
          remaining -= request;
        }

      read0 = block_read(file_desc[0], buffer[0], request);
      if (read0 == (size_t) -1)
        {
          error(2, errno, "%s", file[0]);
          return 2;
        }

      read1 = block_read(file_desc[1], buffer[1], request);
      if (read1 == (size_t) -1)
        {
          error(2, errno, "%s", file[1]);
          return 2;
        }

      common = read0 < read1 ? read0 : read1;
      if (memcmp(buffer[0], buffer[1], common) == 0)
        {
          byte_number += common;
          if (comparison_type == type_first_diff && common != 0)
            {
              line_number += count_newlines(buffer[0], common);
              ended_with_newline = buffer[0][common - 1] == '\n';
            }
        }
      else
        {
          size_t first_diff;

          buffer[0][read0] = (unsigned char) ~buffer[1][read0];
          buffer[1][read1] = (unsigned char) ~buffer[0][read1];

          for (i = read0 + 1; i % sizeof(uint64_t) != 0; ++i)
            buffer[0][i] = 0;
          for (i = read1 + 1; i % sizeof(uint64_t) != 0; ++i)
            buffer[1][i] = 0;

          first_diff = block_compare(buffer[0], buffer[1]);
          byte_number += first_diff;

          if (first_diff != 0 && comparison_type == type_first_diff)
            {
              line_number += count_newlines(buffer[0], first_diff);
              if (first_diff >= common)
                ended_with_newline = buffer[0][first_diff - 1] == '\n';
            }

          if (first_diff < common)
            {
              if (comparison_type == type_first_diff)
                {
                  char byte_buf[21];
                  char line_buf[21];
                  char char0[5];
                  char char1[5];
                  char *byte_string = offtostr(byte_number, byte_buf);
                  char *line_string = offtostr(line_number, line_buf);

                  if (print_chars)
                    {
                      sprint_char(char0, buffer[0][first_diff]);
                      sprint_char(char1, buffer[1][first_diff]);
                      printf(dcgettext(NULL,
                                      "%s %s differ: byte %s, line %s is %3o %s %3o %s\n",
                                      LC_MESSAGES),
                             file[0], file[1], byte_string, line_string,
                             (unsigned int) buffer[0][first_diff], char0,
                             (unsigned int) buffer[1][first_diff], char1);
                    }
                  else
                    {
                      char const *msg =
                        "%s %s differ: byte %s, line %s\n";
                      char const *format = dcgettext(NULL, msg, LC_MESSAGES);

                      if (format == msg && !hard_locale(LC_MESSAGES))
                        format = "%s %s differ: char %s, line %s\n";
                      printf(format, file[0], file[1],
                             byte_string, line_string);
                    }
                  return 1;
                }
              else if (comparison_type == type_all_diffs)
                {
                  off_t block_start = byte_number - (off_t) first_diff;
                  off_t block_end = block_start + (off_t) common;

                  while (byte_number < block_end)
                    {
                      size_t offset = (size_t) (byte_number - block_start);

                      if (buffer[0][offset] != buffer[1][offset])
                        {
                          char number_buf[21];
                          char *number_string = offtostr(byte_number,
                                                        number_buf);

                          if (print_chars)
                            {
                              char char0[5];
                              char char1[5];

                              sprint_char(char0, buffer[0][offset]);
                              sprint_char(char1, buffer[1][offset]);
                              printf("%*s %3o %-4s %3o %s\n",
                                     byte_number_width, number_string,
                                     (unsigned int) buffer[0][offset], char0,
                                     (unsigned int) buffer[1][offset], char1);
                            }
                          else
                            printf("%*s %3o %3o\n",
                                   byte_number_width, number_string,
                                   (unsigned int) buffer[0][offset],
                                   (unsigned int) buffer[1][offset]);
                        }
                      ++byte_number;
                    }
                  differing = -1;
                }
              else
                return 1;
            }
        }

      if (read0 != read1)
        {
          char const *short_file;

          if (comparison_type == type_status)
            return 1;

          short_file = file[read0 > read1];
          if (byte_number == 1)
            fprintf(stderr,
                    dcgettext(NULL, "cmp: EOF on %s which is empty\n",
                              LC_MESSAGES),
                    short_file);
          else
            {
              char byte_buf[21];
              char *byte_string = offtostr(byte_number - 1, byte_buf);

              if (comparison_type != type_first_diff)
                fprintf(stderr,
                        dcgettext(NULL, "cmp: EOF on %s after byte %s\n",
                                  LC_MESSAGES),
                        short_file, byte_string);
              else
                {
                  char line_buf[21];
                  char *line_string =
                    offtostr(line_number - ended_with_newline, line_buf);
                  char const *msg =
                    (ended_with_newline
                     ? "cmp: EOF on %s after byte %s, line %s\n"
                     : "cmp: EOF on %s after byte %s, in line %s\n");

                  fprintf(stderr, dcgettext(NULL, msg, LC_MESSAGES),
                          short_file, byte_string, line_string);
                }
            }
          return 1;
        }

      if (read0 != buffer_size)
        return differing != 0;
    }
}


