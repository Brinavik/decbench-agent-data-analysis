// Function: get_range @ 0x6880
#include <stdio.h>

typedef unsigned char bitstr_t;

int
get_range(bitstr_t *bits, int low, int high, const char *names[], FILE *file)
{
    extern int get_char(FILE *);
    extern void unget_char(int, FILE *);
    extern int is_separator(int);
    extern int get_number(int *, int, const char *[], FILE *);
    extern int set_element(bitstr_t *, int, int, int);
    extern long int random(void);

    int ch;
    int i;
    int num1;
    int num2;
    int num3 = 1;
    int random_range = 0;

    ch = get_char(file);
    if (ch == EOF)
        return EOF;

    if (ch == '*') {
        num1 = low;
        num2 = high;

        ch = get_char(file);
        if (ch == EOF)
            return EOF;
    }
    else {
        if (ch == '~') {
            num1 = low;
            random_range = 1;
        }
        else {
            unget_char(ch, file);
            if (get_number(&num1, low, names, file) == EOF)
                return EOF;

            ch = get_char(file);
            if (ch == EOF)
                return EOF;

            if (ch == '~') {
                random_range = 1;
            }
            else if (ch == '-') {
                ch = get_char(file);
                if (ch == EOF)
                    return EOF;
                unget_char(ch, file);

                if (get_number(&num2, low, names, file) == EOF)
                    return EOF;

                ch = get_char(file);
                if (ch == EOF)
                    return EOF;
            }
            else {
                num2 = num1;
            }
        }
    }

    if (random_range) {
        int number_follows;

        ch = get_char(file);
        if (ch == EOF)
            return EOF;

        number_follows = !is_separator(ch);
        if (number_follows) {
            unget_char(ch, file);
            if (get_number(&num2, low, names, file) == EOF)
                return EOF;
        }
        else {
            num2 = high;
        }

        if (num2 < num1)
            return EOF;

        num1 += random() % (num2 - num1 + 1);
        num2 = num1;

        if (number_follows) {
            ch = get_char(file);
            if (ch == EOF || !is_separator(ch))
                return EOF;
        }
    }
    else {
        if (ch == '/') {
            ch = get_char(file);
            if (ch == EOF)
                return EOF;
            unget_char(ch, file);

            if (get_number(&num3, 0, NULL, file) == EOF || num3 == 0)
                return EOF;

            ch = get_char(file);
            if (ch == EOF)
                return EOF;
        }

        if (!is_separator(ch))
            return EOF;
    }

    i = num1;
    do {
        if (set_element(bits, low, high, i) == EOF) {
            unget_char(ch, file);
            return EOF;
        }
        i += num3;
    } while (i <= num2);

    return ch;
}


