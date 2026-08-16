// Function: mergelines_node @ 0xa020
#include <stddef.h>
#include <stdio.h>

struct line
{
  char *text;
  size_t length;
  char *keybeg;
  char *keylim;
};

struct merge_node
{
  struct line *lo;
  struct line *hi;
  struct line *end_lo;
  struct line *end_hi;
  struct line **dest;
  size_t nlo;
  size_t nhi;
  struct merge_node *parent;
  struct merge_node *lo_child;
  struct merge_node *hi_child;
  unsigned int level;
  unsigned char queued;
};

extern int compare (struct line const *, struct line const *);
extern void write_unique (struct line const *, FILE *, char const *);

void
mergelines_node (struct merge_node *restrict node, size_t total_lines,
          FILE *tfp, char const *temp_output)
{
  struct line *lo_orig = node->lo;
  struct line *hi_orig = node->hi;
  size_t to_merge = (total_lines >> (2 * node->level + 2)) + 1;

  if (node->level > 1)
    {
      struct line *dest = *node->dest;

      while (node->lo != node->end_lo
             && node->hi != node->end_hi
             && to_merge != 0)
        {
          --to_merge;
          --dest;
          if (compare (node->lo - 1, node->hi - 1) > 0)
            *dest = *--node->hi;
          else
            *dest = *--node->lo;
        }

      if (node->hi == node->end_hi
          && (size_t) (hi_orig - node->hi) == node->nhi)
        {
          while (node->lo != node->end_lo && to_merge != 0)
            {
              --to_merge;
              *--dest = *--node->lo;
            }
        }
      else if (node->lo == node->end_lo
               && (size_t) (lo_orig - node->lo) == node->nlo
               && (size_t) (hi_orig - node->hi) != node->nhi)
        {
          while (node->hi != node->end_hi && to_merge != 0)
            {
              --to_merge;
              *--dest = *--node->hi;
            }
        }

      *node->dest = dest;
    }
  else
    {
      while (node->lo != node->end_lo
             && node->hi != node->end_hi
             && to_merge != 0)
        {
          --to_merge;
          if (compare (node->lo - 1, node->hi - 1) > 0)
            write_unique (--node->hi, tfp, temp_output);
          else
            write_unique (--node->lo, tfp, temp_output);
        }

      if (node->hi == node->end_hi
          && (size_t) (hi_orig - node->hi) == node->nhi)
        {
          while (node->lo != node->end_lo && to_merge != 0)
            {
              --to_merge;
              write_unique (--node->lo, tfp, temp_output);
            }
        }
      else if (node->lo == node->end_lo
               && (size_t) (lo_orig - node->lo) == node->nlo
               && (size_t) (hi_orig - node->hi) != node->nhi)
        {
          while (node->hi != node->end_hi && to_merge != 0)
            {
              --to_merge;
              write_unique (--node->hi, tfp, temp_output);
            }
        }
    }

  node->nlo -= lo_orig - node->lo;
  node->nhi -= hi_orig - node->hi;
}


