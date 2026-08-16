// Function: scan_format @ 0x9660
#include <ctype.h>
#include <stddef.h>

/* One layout cell (column specifier), 0x38 bytes. */
struct tbl_cell {
	char		*str;		/* 0x00: freed by the row destructor */
	int		 psz;		/* 0x08: point-size modifier ('p') */
	int		 pos;		/* 0x0c: cell type letter (upper-cased) */
	int		 flags;		/* 0x10: 't' == vertical span downward */
	int		 f14;		/* 0x14: defaults to 1 */
	int		 f18;		/* 0x18: defaults to 1 */
	int		 font;		/* 0x1c: font letter (upper-cased) */
	int		 vert_after;	/* 0x20: '|' seen after the type */
	int		 vert_before;	/* 0x24: '|' seen before the type */
	int		 spacing;	/* 0x28: inter-column spacing */
	int		 mod;		/* 0x2c: width/vertical spacing flag */
	struct tbl_cell	*next;		/* 0x30 */
};

/* One layout row, 0x18 bytes. */
struct tbl_row {
	struct tbl_cell	*first;		/* 0x00 */
	struct tbl_row	*prev;		/* 0x08 */
	struct tbl_row	*next;		/* 0x10 */
};

extern void *xmalloc(size_t);
extern void sub_3af0(struct tbl_row *);			/* frees a row list */
extern const char *sub_8f90(const char *, int *);	/* parses scan_format()/v() args */

const char *
scan_format(const char *p, struct tbl_row **rowp, int *ncols)
{
	struct tbl_row	*head, *row, *nrow;
	struct tbl_cell	*cell, *ncell, *cp;
	const char	*end;
	int		 c, n;

	if (*rowp != NULL)
		sub_3af0(*rowp);

	head = xmalloc(sizeof(*head));
	head->prev = NULL;
	head->next = NULL;
	cell = xmalloc(sizeof(*cell));
	head->first = cell;
	*cell = (struct tbl_cell){ .f14 = 1, .f18 = 1 };
	row = head;

	c = (signed char)*p;
	if (c != '\0' && c != '.') {
		for (;;) {
			switch (c) {
			case '\n':
			case ',':
				/* Start a new layout row. */
				p++;
				nrow = xmalloc(sizeof(*nrow));
				nrow->prev = row;
				nrow->next = NULL;
				row->next = nrow;
				row = nrow;
				ncell = xmalloc(sizeof(*ncell));
				*ncell = (struct tbl_cell){ .f14 = 1, .f18 = 1 };
				nrow->first = ncell;
				cell = ncell;
				break;
			case 'A': case 'C': case 'L':
			case 'N': case 'R': case 'S':
			case 'a': case 'c': case 'l':
			case 'n': case 'r': case 's':
			case '^': case '_':
				/* Cell type; a second one opens a new column. */
				if (cell->pos != 0) {
					ncell = xmalloc(sizeof(*ncell));
					cell->next = ncell;
					*ncell = (struct tbl_cell){
					    .f14 = 1, .f18 = 1 };
					cell = ncell;
				}
				cell->pos = toupper((unsigned char)c);
				p++;
				break;
			case 'B': case 'I':
			case 'b': case 'i':
				cell->font = toupper((unsigned char)c);
				p++;
				break;
			case 'F': case 'f':
				cell->font = toupper((unsigned char)p[1]);
				if (isspace((unsigned char)p[2]))
					p += 2;
				else
					p += 3;
				break;
			case 'P': case 'p': {
				int sign, val;

				if (p[1] == '+') {
					sign = 1;
					p += 2;
				} else if (p[1] == '-') {
					sign = -1;
					p += 2;
				} else {
					sign = 0;
					p++;
				}
				val = 0;
				for (c = (signed char)*p;
				    isdigit((unsigned char)c);
				    c = (signed char)*p) {
					val = val * 10 + (c - '0');
					p++;
				}
				if (sign != 0)
					cell->psz = sign * val;
				else
					cell->psz = -10;
				break;
			}
			case 'V': case 'W':
			case 'v': case 'scan_format':
				p = sub_8f90(p + 2, &cell->mod);
				break;
			case 'T': case 't':
				cell->flags = 't';
				p++;
				break;
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				n = 0;
				for (c = (signed char)*p;
				    isdigit((unsigned char)c);
				    c = (signed char)*p) {
					n = n * 10 + (c - '0');
					p++;
				}
				cell->spacing = n;
				break;
			case '|':
				if (cell->pos != 0)
					cell->vert_after++;
				else
					cell->vert_before++;
				p++;
				break;
			default:
				p++;
				break;
			}

			c = (signed char)*p;
			if (c == '\0' || c == '.')
				break;
		}
	}

	/* A '.' ends the layout: skip to the start of the next line. */
	end = p;
	if (c == '.')
		while (*end++ != '\n')
			;

	/* Number of columns == cells in the first layout row. */
	*ncols = 0;
	for (row = head; row != NULL; row = row->next) {
		n = 0;
		for (cp = head->first; cp != NULL; cp = cp->next)
			n++;
		if (n > *ncols)
			*ncols = n;
	}

	*rowp = head;
	return end;
}


