// Function: dump @ 0x1b50
#include <stdio.h>
#include <unistd.h>
#include <utmp.h>

struct old_utmp {
    short ut_type;
    int ut_pid;
    char ut_line[12];
    char ut_id[4];
    long old_time;
    char ut_user[8];
    char ut_host[16];
    long old_addr;
};

extern struct utmp old_to_new(struct old_utmp entry);
extern void print_utline(struct utmp entry);

void dump(FILE *input, int follow, int old_format)
{
    if (follow) {
        fseek(input,
              old_format ? -10L * (long) sizeof(struct old_utmp)
                         : -10L * (long) sizeof(struct utmp),
              SEEK_END);
    }

    for (;;) {
        if (old_format) {
            struct old_utmp entry;

            while (fread(&entry, sizeof(entry), 1, input) == 1)
                print_utline(old_to_new(entry));
        } else {
            struct utmp entry;

            while (fread(&entry, sizeof(entry), 1, input) == 1)
                print_utline(entry);
        }

        if (!follow)
            break;
        sleep(1);
    }
}


