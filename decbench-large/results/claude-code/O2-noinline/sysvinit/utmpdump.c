// Function: dump @ 0x1b50
#include <stdio.h>
#include <unistd.h>

/* On-disk record (64 bytes) read when small_records is set. */
typedef struct {
    char data[64];
} record_t;

/* Expanded/decoded entry (384 bytes) that gets processed. */
typedef struct {
    char data[384];
} entry_t;

/* Decode a raw 64-byte record into a 384-byte entry (returned by value). */
extern entry_t sub_1610(record_t rec);

/* Consume/print one decoded entry. */
extern void sub_1a00(entry_t e);

void dump(FILE *stream, int follow, int small_records)
{
    record_t small;
    entry_t big;

    /* In follow mode, jump to roughly the last 10 records before reading. */
    if (follow)
        fseek(stream,
              small_records ? -10L * (long)sizeof(record_t)
                            : -10L * (long)sizeof(entry_t),
              SEEK_END);

    for (;;) {
        if (small_records) {
            while (fread(&small, sizeof(small), 1, stream) == 1)
                sub_1a00(sub_1610(small));
        } else {
            while (fread(&big, sizeof(big), 1, stream) == 1)
                sub_1a00(big);
        }

        if (!follow)
            break;

        sleep(1);
    }
}


