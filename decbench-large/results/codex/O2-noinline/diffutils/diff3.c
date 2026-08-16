// Function: output_diff3_edscript @ 0x50f0
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

typedef long lin;

enum diff_type
{
  DIFF_ALL = 4,
  DIFF_1ST = 5,
  DIFF_2ND = 6,
  DIFF_3RD = 7
};

struct line_range
{
  lin first;
  lin last;
};

struct diff3_block
{
  enum diff_type type;
  struct line_range ranges[3];
  char **lines[3];
  size_t *line_lengths[3];
  struct diff3_block *next;
};

extern bool simple_only;
extern bool overlap_only;
extern bool show_all;
extern bool flagging;
extern bool finalwrite;

extern struct diff3_block *reverse_diff3_blocklist(struct diff3_block *);
extern bool output_diff3_block(FILE *, const struct diff3_block *, int);
extern void finish_ed_command(FILE *, bool, lin, lin);

int
output_diff3_edscript(FILE *output, struct diff3_block *blocks, const int file_order[3],
         const int type_map[3], const char *file0_name,
         const char *file1_name, const char *file2_name)
{
  bool conflicts_found = false;
  struct diff3_block *block = reverse_diff3_blocklist(blocks);

  for (; block != NULL; block = block->next)
    {
      bool special_show_all = false;

      if (block->type == DIFF_ALL)
        {
          if (simple_only)
            continue;
        }
      else
        {
          int const file = type_map[block->type - DIFF_1ST];

          if (file == 1)
            {
              if (!show_all)
                continue;
              special_show_all = true;
            }
          else if (file == 2)
            {
              if (overlap_only)
                continue;
            }
          else if (file == -1)
            {
              if (simple_only)
                continue;
            }
          else
            continue;
        }

      struct line_range const first = block->ranges[file_order[0]];
      struct line_range const second = block->ranges[file_order[1]];
      struct line_range const third = block->ranges[file_order[2]];
      lin const first_length = first.last - first.first;
      lin const second_length = second.last - second.first;
      lin const third_length = third.last - third.first;

      if (special_show_all)
        {
          fprintf(output, "%lda\n", first.last);
          fprintf(output, ">>>>>>> %s\n", file2_name);
          finish_ed_command(output, false, first.last + 2,
                            second_length + third_length + 3);

          fprintf(output, "%lda\n<<<<<<< %s\n", first.first - 1,
                  file0_name);
          bool const dot = output_diff3_block(output, block, file_order[1]);
          fputs("=======\n", output);
          finish_ed_command(output, dot, first.first + 1,
                            second_length + 1);
          conflicts_found = true;
          continue;
        }

      if (flagging)
        {
          bool dot = false;

          fprintf(output, "%lda\n", first.last);
          if (show_all)
            {
              fprintf(output, "||||||| %s\n", file1_name);
              dot = output_diff3_block(output, block, file_order[1]);
            }
          fputs("=======\n", output);
          dot |= output_diff3_block(output, block, file_order[2]);
          fprintf(output, ">>>>>>> %s\n", file2_name);
          finish_ed_command(output, dot, first.last + 2,
                            second_length + third_length + 3);

          fprintf(output, "%lda\n<<<<<<< %s\n", first.first - 1,
                  file0_name);
          finish_ed_command(output, false, first.first + 1,
                            second_length + 1);
          conflicts_found = true;
          continue;
        }

      if (third_length == -1)
        {
          if (first.first == first.last)
            fprintf(output, "%ldd\n", first.first);
          else
            fprintf(output, "%ld,%ldd\n", first.first, first.last);
          continue;
        }

      if (first_length == -1)
        fprintf(output, "%lda\n", first.last);
      else if (first_length == 0)
        fprintf(output, "%ldc\n", first.last);
      else
        fprintf(output, "%ld,%ldc\n", first.first, first.last);

      bool const dot = output_diff3_block(output, block, file_order[2]);
      finish_ed_command(output, dot, first.first, third_length + 1);
    }

  if (finalwrite)
    fputs("w\nq\n", output);

  return conflicts_found;
}


