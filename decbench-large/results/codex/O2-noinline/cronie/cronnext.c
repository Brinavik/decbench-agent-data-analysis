// Function: get_range @ 0x5180
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char bitstr_t;

extern int get_char(FILE *file);
extern void unget_char(int ch, FILE *file);
extern int is_separator(int ch);
extern int get_number(int *value, int low, const char *const *names,
                      FILE *file);
extern int set_element(bitstr_t *bits, int low, int high, int value);

int
get_range(bitstr_t *bits, int low, int high, const char *const *names,
         FILE *file)
{
    int ch;
    int first;
    int last;
    int step = 1;
    int value;
    int allow_step = 0;
    int random_range = 0;

    ch = get_char(file);
    if (ch == EOF)
        return EOF;

    if (ch == '*') {
        first = low;
        last = high;
        allow_step = 1;
        ch = get_char(file);
        if (ch == EOF)
            return EOF;
    } else if (ch == '~') {
        first = low;
        ch = get_char(file);
        if (ch == EOF)
            return EOF;

        if (is_separator(ch)) {
            last = high;
        } else {
            unget_char(ch, file);
            if (get_number(&last, low, names, file) == EOF)
                return EOF;
            ch = get_char(file);
            if (ch == EOF || !is_separator(ch))
                return EOF;
        }
        random_range = 1;
    } else {
        unget_char(ch, file);
        if (get_number(&first, low, names, file) == EOF)
            return EOF;

        ch = get_char(file);
        if (ch == EOF)
            return EOF;

        if (ch == '-') {
            ch = get_char(file);
            if (ch == EOF)
                return EOF;
            unget_char(ch, file);
            if (get_number(&last, low, names, file) == EOF)
                return EOF;
            ch = get_char(file);
            if (ch == EOF)
                return EOF;
            allow_step = 1;
        } else if (ch == '~') {
            ch = get_char(file);
            if (ch == EOF)
                return EOF;

            if (is_separator(ch)) {
                last = high;
            } else {
                unget_char(ch, file);
                if (get_number(&last, low, names, file) == EOF)
                    return EOF;
                ch = get_char(file);
                if (ch == EOF || !is_separator(ch))
                    return EOF;
            }
            random_range = 1;
        } else {
            last = first;
        }
    }

    if (random_range) {
        if (first > last)
            return EOF;
        value = first + random() % (last - first + 1);
        first = value;
        last = value;
    } else if (allow_step && ch == '/') {
        ch = get_char(file);
        if (ch == EOF)
            return EOF;
        unget_char(ch, file);
        if (get_number(&step, 0, NULL, file) == EOF || step == 0)
            return EOF;
        ch = get_char(file);
        if (ch == EOF || !is_separator(ch))
            return EOF;
    } else if (!is_separator(ch)) {
        return EOF;
    }

    for (value = first; value <= last; value += step) {
        if (set_element(bits, low, high, value) == EOF) {
            unget_char(ch, file);
            return EOF;
        }
    }

    return ch;
}


