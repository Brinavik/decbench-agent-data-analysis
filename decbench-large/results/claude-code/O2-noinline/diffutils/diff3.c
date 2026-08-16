// Function: output_diff3_edscript @ 0x50f0
#include <stdio.h>
#include <stdbool.h>

/* Line number type.  */
typedef long int lin;

/* Which file within a three-way diff.  */
enum { FILE0, FILE1, FILE2 };

/* Endpoints of a range of lines.  */
enum { RANGE_START, RANGE_END };

enum diff_type
  {
    ERROR,			/* Should not be used */
    ADD,			/* Two way diff add */
    CHANGE,			/* Two way diff change */
    DELETE,			/* Two way diff delete */
    DIFF_ALL,			/* All three are different */
    DIFF_1ST,			/* Just the first file is different */
    DIFF_2ND,			/* Just the second */
    DIFF_3RD			/* Just the third */
  };

struct diff3_block
{
  enum diff_type correspond;	/* Type of diff */
  lin ranges[3][2];		/* Ranges are inclusive */
  char **lines[3];		/* The actual lines (may contain nulls) */
  size_t *lengths[3];		/* Line lengths (including newlines, if any) */
  struct diff3_block *next;
};

#define D_LOWLINE(diff, filenum) ((diff)->ranges[filenum][RANGE_START])
#define D_HIGHLINE(diff, filenum) ((diff)->ranges[filenum][RANGE_END])
#define D_NUMLINES(diff, filenum) \
  (D_HIGHLINE (diff, filenum) - D_LOWLINE (diff, filenum) + 1)

/* Option flags set during option processing.  */
extern bool show_2nd;		/* If set, show information for DIFF_2ND diffs.  */
extern bool simple_only;	/* If set, do not output information for overlapping diffs.  */
extern bool overlap_only;	/* If set, do not output information for non-overlapping diffs.  */
extern bool flagging;		/* If set, mark overlapping changes with bracket lines.  */
extern bool finalwrite;		/* If set, append 'w' and 'q' commands to the ed script.  */

/* Reverse the order of the list of diff3 blocks.  */
extern struct diff3_block *reverse_diff3_blocklist (struct diff3_block *diff);

/* Output to OUTPUTFILE the lines of B taken from FILENUM, doubling any
   initial '.'s; return true if any initial '.'s were doubled.  */
extern bool dotlines (FILE *outputfile, struct diff3_block *b, int filenum);

/* Output to OUTPUTFILE a '.' line, plus a command to undo doubled
   leading '.'s in the NUM lines starting at line START.  */
extern void undotlines (FILE *outputfile, bool leading_dot, lin start, lin num);

/* Output a diff3 set of blocks as an ed script.  This script applies
   the changes between file's 2 & 3 to file 1.  Take the precise
   format of the ed script to be output from global variables set
   during options processing.  Reverse the order of the block list as
   processing is done.  */

bool
output_diff3_edscript (FILE *outputfile, struct diff3_block *diff,
	  int const mapping[3], int const rev_mapping[3],
	  char const *file0, char const *file1, char const *file2)
{
  bool leading_dot;
  bool conflicts_found = false;
  bool conflict;
  struct diff3_block *b;

  for (b = reverse_diff3_blocklist (diff); b; b = b->next)
    {
      /* Must do mapping correctly.  */
      enum diff_type type
	= (b->correspond == DIFF_ALL
	   ? DIFF_ALL
	   : (enum diff_type)
	     (DIFF_1ST + rev_mapping[b->correspond - DIFF_1ST]));

      lin low0, high0;

      /* If we aren't supposed to do this output block, skip it.  */
      switch (type)
	{
	default:
	  continue;
	case DIFF_2ND:
	  if (!show_2nd)
	    continue;
	  conflict = true;
	  break;
	case DIFF_3RD:
	  if (overlap_only)
	    continue;
	  conflict = false;
	  break;
	case DIFF_ALL:
	  if (simple_only)
	    continue;
	  conflict = flagging;
	  break;
	}

      low0 = D_LOWLINE (b, mapping[FILE0]);
      high0 = D_HIGHLINE (b, mapping[FILE0]);

      if (conflict)
	{
	  conflicts_found = true;

	  /* Mark end of conflict.  */

	  fprintf (outputfile, "%lda\n", high0);
	  leading_dot = false;
	  if (type == DIFF_ALL)
	    {
	      if (show_2nd)
		{
		  /* Append lines from FILE1.  */
		  fprintf (outputfile, "||||||| %s\n", file1);
		  leading_dot = dotlines (outputfile, b, mapping[FILE1]);
		}
	      /* Append lines from FILE2.  */
	      fputs ("=======\n", outputfile);
	      leading_dot |= dotlines (outputfile, b, mapping[FILE2]);
	    }
	  fprintf (outputfile, ">>>>>>> %s\n", file2);
	  undotlines (outputfile, leading_dot, high0 + 2,
		      (D_NUMLINES (b, mapping[FILE1])
		       + D_NUMLINES (b, mapping[FILE2]) + 1));

	  /* Mark start of conflict.  */

	  fprintf (outputfile, "%lda\n<<<<<<< %s\n", low0 - 1,
		   type == DIFF_ALL ? file0 : file1);
	  leading_dot = false;
	  if (type == DIFF_2ND)
	    {
	      /* Prepend lines from FILE1.  */
	      leading_dot = dotlines (outputfile, b, mapping[FILE1]);
	      fputs ("=======\n", outputfile);
	    }
	  undotlines (outputfile, leading_dot, low0 + 1,
		      D_NUMLINES (b, mapping[FILE1]));
	}
      else if (D_NUMLINES (b, mapping[FILE2]) == 0)
	{
	  /* Write out a delete.  */
	  if (low0 == high0)
	    fprintf (outputfile, "%ldd\n", low0);
	  else
	    fprintf (outputfile, "%ld,%ldd\n", low0, high0);
	}
      else
	{
	  /* Write out an add or change.  */
	  switch (high0 - low0)
	    {
	    case -1:
	      fprintf (outputfile, "%lda\n", high0);
	      break;
	    case 0:
	      fprintf (outputfile, "%ldc\n", high0);
	      break;
	    default:
	      fprintf (outputfile, "%ld,%ldc\n", low0, high0);
	      break;
	    }

	  leading_dot = dotlines (outputfile, b, mapping[FILE2]);

	  undotlines (outputfile, leading_dot, low0,
		      D_NUMLINES (b, mapping[FILE2]));
	}
    }

  if (finalwrite)
    fputs ("w\nq\n", outputfile);

  return conflicts_found;
}


