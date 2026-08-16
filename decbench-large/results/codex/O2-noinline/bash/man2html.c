// Function: scan_format @ 0x9660
#include <ctype.h>
#include <stddef.h>

typedef struct TblCell TblCell;
typedef struct TblRow TblRow;

struct TblCell {
    char *text;
    int point_size;
    int alignment;
    int vertical_alignment;
    int colspan;
    int rowspan;
    int font;
    int right_border;
    int left_border;
    int spacing;
    int width;
    TblCell *next;
};

struct TblRow {
    TblCell *cells;
    TblRow *previous;
    TblRow *next;
};

extern void *xmalloc(size_t size);
extern void sub_3af0(TblRow *row);
extern char *sub_8f90(char *text, int *value);

char *scan_format(char *text, TblRow **rows, int *column_count)
{
    TblRow *first_row;
    TblRow *last_row;
    TblRow *row;
    TblCell *first_cells;
    TblCell *cell;
    TblCell *new_cell;
    int value;
    int sign;

    if (*rows != NULL)
        sub_3af0(*rows);

    first_row = xmalloc(sizeof(*first_row));
    first_row->previous = NULL;
    first_row->next = NULL;
    last_row = first_row;

    cell = xmalloc(sizeof(*cell));
    cell->text = NULL;
    cell->point_size = 0;
    cell->alignment = 0;
    cell->vertical_alignment = 0;
    cell->colspan = 1;
    cell->rowspan = 1;
    cell->font = 0;
    cell->right_border = 0;
    cell->left_border = 0;
    cell->spacing = 0;
    cell->width = 0;
    cell->next = NULL;
    first_row->cells = cell;

    while (*text != '\0' && *text != '.') {
        switch (*text) {
        case '\n':
        case ',':
            ++text;
            row = xmalloc(sizeof(*row));
            last_row->next = row;
            row->previous = last_row;
            row->next = NULL;
            last_row = row;

            cell = xmalloc(sizeof(*cell));
            cell->text = NULL;
            cell->point_size = 0;
            cell->alignment = 0;
            cell->vertical_alignment = 0;
            cell->colspan = 1;
            cell->rowspan = 1;
            cell->font = 0;
            cell->right_border = 0;
            cell->left_border = 0;
            cell->spacing = 0;
            cell->width = 0;
            cell->next = NULL;
            row->cells = cell;
            break;

        case 'A':
        case 'C':
        case 'L':
        case 'N':
        case 'R':
        case 'S':
        case '^':
        case '_':
        case 'a':
        case 'c':
        case 'l':
        case 'n':
        case 'r':
        case 's':
            if (cell->alignment != 0) {
                new_cell = xmalloc(sizeof(*new_cell));
                cell->next = new_cell;
                cell = new_cell;
                cell->text = NULL;
                cell->point_size = 0;
                cell->alignment = 0;
                cell->vertical_alignment = 0;
                cell->colspan = 1;
                cell->rowspan = 1;
                cell->font = 0;
                cell->right_border = 0;
                cell->left_border = 0;
                cell->spacing = 0;
                cell->width = 0;
                cell->next = NULL;
            }
            cell->alignment = toupper(*text);
            ++text;
            break;

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            value = 0;
            while (isdigit(*text)) {
                value = value * 10 + *text - '0';
                ++text;
            }
            cell->spacing = value;
            break;

        case 'B':
        case 'I':
        case 'b':
        case 'i':
            cell->font = toupper(*text);
            ++text;
            break;

        case 'F':
        case 'f':
            cell->font = toupper(text[1]);
            if (isspace(text[2]))
                text += 2;
            else
                text += 3;
            break;

        case 'P':
        case 'p':
            ++text;
            sign = 0;
            if (*text == '+') {
                sign = 1;
                ++text;
            } else if (*text == '-') {
                sign = -1;
                ++text;
            }

            value = 0;
            while (isdigit(*text)) {
                value = value * 10 + *text - '0';
                ++text;
            }
            cell->point_size = sign != 0 ? sign * value : -10;
            break;

        case 'T':
        case 't':
            cell->vertical_alignment = 't';
            ++text;
            break;

        case 'V':
        case 'W':
        case 'v':
        case 'w':
            text = sub_8f90(text + 2, &cell->width);
            break;

        case '|':
            if (cell->alignment != 0)
                ++cell->right_border;
            else
                ++cell->left_border;
            ++text;
            break;

        default:
            ++text;
            break;
        }
    }

    if (*text == '.') {
        do {
            ++text;
        } while (text[-1] != '\n');
    }

    *column_count = 0;
    row = first_row;
    first_cells = first_row->cells;
    while (row != NULL) {
        value = 0;
        for (cell = first_cells; cell != NULL; cell = cell->next)
            ++value;
        if (value > *column_count)
            *column_count = value;
        row = row->next;
    }

    *rows = first_row;
    return text;
}


