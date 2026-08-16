// Function: get_range @ 0x6880
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char bitstr_t;

/* Lexer / helpers implemented elsewhere in the crontab parser. */
extern int  get_char(FILE *file);                                  /* 0x8570 */
extern void unget_char(int ch, FILE *file);                        /* 0x85d0 */
extern int  get_number(int *numptr, int low,
                       const char *names[], FILE *file);            /* 0x66d0 */
extern int  set_element(bitstr_t *bits, int low, int high,
                        int get_range);                               /* 0x6650 */
extern int  is_terminator(int ch);                                 /* 0x6620: ' ' '\t' '\n' ',' */

/*
 * Parse one range element of a crontab field and set the corresponding bits.
 *
 *   range = "*"          [ "/" step ]
 *         | get_range
 *         | get_range "-" get_range   [ "/" step ]
 *         | "~"          (random in [low , high])
 *         | "~" get_range   (random in [low , get_range])
 *         | get_range "~"          (random in [get_range , high])
 *         | get_range "~" get_range   (random in [get_range , number2])
 *
 * Returns the character that terminated the element (whitespace or ','),
 * or EOF on any error.
 */
int get_range(bitstr_t *bits, int low, int high, const char *names[], FILE *file)
{
    int num1, num2, num3;
    int i;
    int ch;

    num3 = 1;                       /* default step */

    ch = get_char(file);
    if (ch == EOF)
        return EOF;

    if (ch == '*') {
        num1 = low;
        num2 = high;
        ch = get_char(file);
        if (ch == EOF)
            return EOF;
        if (ch == '/')
            goto parse_step;
        if (!is_terminator(ch))
            return EOF;
        i = low;
        goto fill;
    }

    if (ch == '~') {
        num1 = low;
        goto random_range;
    }

    /* An element that starts with a get_range or a name. */
    unget_char(ch, file);
    if (get_number(&num1, low, names, file) == EOF)
        return EOF;

    ch = get_char(file);
    if (ch == EOF)
        return EOF;

    if (ch == '-') {
        /* get_range "-" get_range [ "/" step ] */
        ch = get_char(file);
        if (ch == EOF)
            return EOF;
        unget_char(ch, file);
        if (get_number(&num2, low, names, file) == EOF)
            return EOF;
        ch = get_char(file);
        if (ch == EOF)
            return EOF;
        if (ch == '/')
            goto parse_step;
        if (!is_terminator(ch))
            return EOF;
        i = num1;
        if (num1 <= num2)
            goto fill;
        return ch;
    }

    if (ch == '~') {
        /* get_range "~" ... : random range starting at the parsed get_range */
        goto random_range;
    }

    /* A single get_range. */
    if (!is_terminator(ch))
        return EOF;
    num2 = num1;
    i = num1;
    goto fill;

parse_step:
    /* Just consumed '/', now read the step value. */
    ch = get_char(file);
    if (ch == EOF)
        return EOF;
    unget_char(ch, file);
    if (get_number(&num3, 0, NULL, file) == EOF)
        return EOF;
    if (num3 == 0)
        return EOF;
    ch = get_char(file);
    if (ch == EOF)
        return EOF;
    if (!is_terminator(ch))
        return EOF;
    i = num1;
    if (num1 <= num2)
        goto fill;
    return ch;

random_range:
    /* Just consumed '~'; num1 is the low end of the random range. */
    ch = get_char(file);
    if (ch == EOF)
        return EOF;
    if (is_terminator(ch)) {
        /* "~" with no upper bound: random value in [num1, high]. */
        if (num1 > high)
            return EOF;
        i = num1 + (int)(random() % (high - num1 + 1));
    } else {
        /* "~" get_range: random value in [num1, num2]. */
        unget_char(ch, file);
        if (get_number(&num2, low, names, file) == EOF)
            return EOF;
        if (num2 < num1)
            return EOF;
        i = num1 + (int)(random() % (num2 - num1 + 1));
        ch = get_char(file);
        if (ch == EOF)
            return EOF;
        if (!is_terminator(ch))
            return EOF;
    }
    num2 = i;                       /* set exactly the one random value */
    goto fill;

fill:
    for (;;) {
        if (set_element(bits, low, high, i) == EOF) {
            unget_char(ch, file);
            return EOF;
        }
        i += num3;
        if (i > num2)
            break;
    }
    return ch;
}


