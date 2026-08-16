// Function: compare_files @ 0x2c30
#include <errno.h>
#include <error.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
compare_files(char **infiles)
{
    typedef ptrdiff_t idx_t;

    struct linebuffer {
        idx_t size;
        idx_t length;
        char *buffer;
    };

    extern unsigned char delimiter;
    extern const char *col_sep;
    extern bool output_total;
    extern bool issued_disorder_warning[2];
    extern bool seen_unpairable;
    extern bool hard_LC_COLLATE;

    extern void initbuffer(struct linebuffer *);
    extern struct linebuffer *readlinebuffer_delim(struct linebuffer *, FILE *,
                                                    char);
    extern void fadvise(FILE *, int);
    extern FILE *fopen_safer(const char *, const char *);
    extern int close_stream(FILE *);
    extern void writeline(const struct linebuffer *, FILE *, int);
    extern void check_order(const struct linebuffer *, const struct linebuffer *,
                            int);
    extern int xmemcoll0(const char *, idx_t, const char *, idx_t);
    extern char *umaxtostr(uintmax_t, char *);
    extern char *quotearg_n_style_colon(int, int, const char *);
    extern char *dcgettext(const char *, const char *, int);

    FILE *streams[2];
    struct linebuffer linebuffer_storage[2][4];
    struct linebuffer *all_line[2][4];
    struct linebuffer *thisline[2];
    int alt[2][2] = { { 0, 0 }, { 0, 0 } };
    bool fill_up[2];
    uintmax_t column_count[3] = { 0, 0, 0 };
    int i;

    for (i = 0; i < 2; i++) {
        int j;

        for (j = 0; j < 4; j++) {
            initbuffer(&linebuffer_storage[i][j]);
            all_line[i][j] = &linebuffer_storage[i][j];
        }

        if (strcmp(infiles[i], "-") == 0)
            streams[i] = stdin;
        else
            streams[i] = fopen_safer(infiles[i], "r");

        if (streams[i] == NULL)
            error(EXIT_FAILURE, errno, "%s",
                  quotearg_n_style_colon(0, 3, infiles[i]));

        fadvise(streams[i], 2);
        thisline[i] = readlinebuffer_delim(all_line[i][0], streams[i],
                                           delimiter);
        if (ferror_unlocked(streams[i]))
            error(EXIT_FAILURE, errno, "%s",
                  quotearg_n_style_colon(0, 3, infiles[i]));
    }

    while (thisline[0] != NULL || thisline[1] != NULL) {
        if (thisline[0] == NULL) {
            seen_unpairable = true;
            writeline(thisline[1], stdout, 2);
            column_count[1]++;
            fill_up[0] = false;
            fill_up[1] = true;
        } else if (thisline[1] == NULL) {
            seen_unpairable = true;
            writeline(thisline[0], stdout, 1);
            column_count[0]++;
            fill_up[0] = true;
            fill_up[1] = false;
        } else {
            idx_t len[2];
            int order;

            len[0] = thisline[0]->length - 1;
            len[1] = thisline[1]->length - 1;

            if (hard_LC_COLLATE) {
                order = xmemcoll0(thisline[0]->buffer, len[0],
                                  thisline[1]->buffer, len[1]);
            } else {
                idx_t shorter = len[0] < len[1] ? len[0] : len[1];

                order = memcmp(thisline[0]->buffer, thisline[1]->buffer,
                               (size_t) shorter);
                if (order == 0)
                    order = (len[0] > len[1]) - (len[0] < len[1]);
            }

            if (order < 0) {
                seen_unpairable = true;
                writeline(thisline[0], stdout, 1);
                column_count[0]++;
                fill_up[0] = true;
                fill_up[1] = false;
            } else if (order > 0) {
                seen_unpairable = true;
                writeline(thisline[1], stdout, 2);
                column_count[1]++;
                fill_up[0] = false;
                fill_up[1] = true;
            } else {
                writeline(thisline[1], stdout, 3);
                column_count[2]++;
                fill_up[0] = true;
                fill_up[1] = true;
            }
        }

        for (i = 0; i < 2; i++) {
            if (fill_up[i]) {
                int old_previous = alt[i][1];
                int old_current = alt[i][0];

                alt[i][1] = old_current;
                alt[i][0] = (old_current + 1) & 3;
                thisline[i] = readlinebuffer_delim(all_line[i][alt[i][0]],
                                                   streams[i], delimiter);

                if (thisline[i] != NULL) {
                    check_order(all_line[i][old_current], thisline[i], i + 1);
                } else if (all_line[i][old_previous]->buffer != NULL) {
                    check_order(all_line[i][old_previous],
                                all_line[i][old_current], i + 1);
                }

                if (ferror_unlocked(streams[i]))
                    error(EXIT_FAILURE, errno, "%s",
                          quotearg_n_style_colon(0, 3, infiles[i]));

                fill_up[i] = false;
            }
        }
    }

    if (close_stream(streams[0]) != 0)
        error(EXIT_FAILURE, errno, "%s",
              quotearg_n_style_colon(0, 3, infiles[0]));
    if (close_stream(streams[1]) != 0)
        error(EXIT_FAILURE, errno, "%s",
              quotearg_n_style_colon(0, 3, infiles[1]));

    if (output_total) {
        char count_1[32];
        char count_2[32];
        char count_3[32];

        printf("%s%s%s%s%s%s%s%c",
               umaxtostr(column_count[0], count_1), col_sep,
               umaxtostr(column_count[1], count_2), col_sep,
               umaxtostr(column_count[2], count_3), col_sep,
               dcgettext(NULL, "total", 5), delimiter);
    }

    if (issued_disorder_warning[0] || issued_disorder_warning[1])
        error(EXIT_FAILURE, 0,
              dcgettext(NULL, "input is not in sorted order", 5));

    exit(EXIT_SUCCESS);
}


