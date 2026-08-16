// Function: get_range @ 0x5180
#include <stdio.h>
#include <stdlib.h>

/* bit-string used to hold the set of allowed values for a cron field */
typedef unsigned char bitstr_t;

/* helpers implemented elsewhere in the program */
extern int  get_char(FILE *file);                    /* read a char, tracking line numbers */
extern void unget_char(int ch, FILE *file);          /* push a char back */
extern int  set_element(bitstr_t *bits, int low, int high, int number);
extern int  get_number(int *numptr, int low, const char *names[], FILE *file);
extern int  is_term(int ch);                         /* ch is one of ' ' '\t' '\n' ',' */

/*
 * range = number
 *       | number "-" number [ "/" step ]
 *       | number "~" number [ "/" step ]   (random value within the range)
 *       | "*"                [ "/" step ]
 *
 * Sets the matching bits in *bits and returns the terminating character
 * (or EOF on a parse/range error).
 */
int get_range(bitstr_t *bits, int low, int high, const char *names[], FILE *file)
{
	int i, num1, num2, num3;
	int ch;

	num3 = 1;			/* default step */

	ch = get_char(file);
	if (ch == EOF)
		return EOF;

	if (ch == '*') {
		/* '*' means "first-last" but may still be modified by /step */
		num1 = low;
		num2 = high;
	} else {
		if (ch == '~') {
			/* "~..." with no leading number: start from low */
			num1 = low;
		} else {
			unget_char(ch, file);
			if (get_number(&num1, low, names, file) == EOF)
				return EOF;
			ch = get_char(file);
			if (ch == EOF)
				return EOF;
		}

		if (ch == '~') {
			/* pick a random value within the range */
			ch = get_char(file);
			if (ch == EOF)
				return EOF;

			if (is_term(ch)) {
				/* no upper bound given, use high */
				num2 = high;
				if (num1 > num2)
					return EOF;
			} else {
				unget_char(ch, file);
				if (get_number(&num2, low, names, file) == EOF)
					return EOF;
				if (num2 < num1)
					return EOF;
				ch = get_char(file);
				if (ch == EOF)
					return EOF;
				if (!is_term(ch))
					return EOF;
			}

			num1 += random() % (num2 - num1 + 1);
			num2 = num1;
			goto set_range;
		} else if (ch == '-') {
			/* eat the dash and read the upper bound */
			ch = get_char(file);
			if (ch == EOF)
				return EOF;
			unget_char(ch, file);
			if (get_number(&num2, low, names, file) == EOF)
				return EOF;
			ch = get_char(file);
			if (ch == EOF)
				return EOF;
			/* fall through: may be followed by /step */
		} else {
			/* a single number */
			if (!is_term(ch))
				return EOF;
			num2 = num1;
			goto set_range;
		}
	}

	/* optional "/step", valid after '*' and after "num1-num2" */
	if (ch == '/') {
		ch = get_char(file);
		if (ch == EOF)
			return EOF;
		unget_char(ch, file);
		if (get_number(&num3, 0, (const char **)0, file) == EOF)
			return EOF;
		if (num3 == 0)
			return EOF;
		ch = get_char(file);
		if (ch == EOF)
			return EOF;
	}
	if (!is_term(ch))
		return EOF;

set_range:
	for (i = num1; i <= num2; i += num3) {
		if (set_element(bits, low, high, i) == EOF) {
			unget_char(ch, file);
			return EOF;
		}
	}
	return ch;
}


