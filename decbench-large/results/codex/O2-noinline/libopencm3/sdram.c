// Function: main @ 0x800053c
#include <stdint.h>

extern void sub_8000328(void);
extern void sub_8000284(void);
extern void sub_8000350(void);
extern void sub_8000258(const char *string);
extern uint8_t sub_800020c(int wait);
extern uint8_t *sub_8000494(uint8_t *address, uint32_t offset);
extern uint8_t *sub_8000524(uint8_t *address, uint32_t offset);

int main(void)
{
    uint8_t *address;
    uint8_t *p;
    uint8_t command;

    sub_8000328();
    sub_8000284();
    sub_8000350();

    sub_8000258("SDRAM Example.\n");
    sub_8000258("Original data:\n");
    sub_8000524((uint8_t *)0xd0000000u, 0);

    for (p = (uint8_t *)0xd0000000u;
         p != (uint8_t *)0xd0000100u;
         ++p) {
        *p = (uint8_t)(uintptr_t)p;
    }

    sub_8000258("Modified data (with Fill Increment)\n");
    address = sub_8000524((uint8_t *)0xd0000000u, 0);

    for (;;) {
        sub_8000258("CMD> ");
        command = sub_800020c(1);

        switch (command) {
        case 'F':
        case 'f':
            sub_8000258("Fill ");
            command = sub_800020c(1);

            switch (command) {
            case 'F':
            case 'f': {
                uint32_t *word = (uint32_t *)address;
                uint32_t *end = (uint32_t *)(address + 0x100);

                sub_8000258("Ones (0xff)\n");
                do {
                    *word++ = UINT32_MAX;
                } while (word != end);
                sub_8000524(address, 0);
                break;
            }

            case 'I':
            case 'i': {
                unsigned int i;

                sub_8000258("Increment\n");
                for (i = 0; i != 0x100; ++i) {
                    address[i] = (uint8_t)i;
                }
                sub_8000524(address, 0);
                break;
            }

            case '0': {
                uint32_t *word = (uint32_t *)address;
                uint32_t *end = (uint32_t *)(address + 0x100);

                sub_8000258("Zero\n");
                do {
                    *word++ = 0;
                } while (word != end);
                sub_8000524(address, 0);
                break;
            }

            default:
                sub_8000258("Unrecognized Command, press ? for help\n");
                break;
            }
            break;

        case 'N':
        case 'n':
            sub_8000258("Next ");
            command = sub_800020c(1);

            switch (command) {
            case 'P':
            case 'p':
                sub_8000258("Page\n");
                address += 0x100;
                sub_8000524(address, 0);
                break;

            case 'L':
            case 'l':
                sub_8000258("Line\n");
                address += 0x10;
                sub_8000494(address, 0);
                break;

            default:
                sub_8000258("Unrecognized Command, press ? for help\n");
                break;
            }
            break;

        case 'P':
        case 'p':
            sub_8000258("Previous ");
            command = sub_800020c(1);

            switch (command) {
            case 'P':
            case 'p':
                sub_8000258("Page\n");
                address -= 0x100;
                sub_8000524(address, 0);
                break;

            case 'L':
            case 'l':
                sub_8000258("Line\n");
                address -= 0x10;
                sub_8000494(address, 0);
                break;

            default:
                sub_8000258("Unrecognized Command, press ? for help\n");
                break;
            }
            break;

        default:
            sub_8000258("Help\n");
            sub_8000258(" n p - dump next page\n");
            sub_8000258(" n l - dump next line\n");
            sub_8000258(" p p - dump previous page\n");
            sub_8000258(" p l - dump previous line\n");
            sub_8000258(" f 0 - fill current page with 0\n");
            sub_8000258(" f i - fill current page with 0 to 255\n");
            sub_8000258(" f f - fill current page with 0xff\n");
            sub_8000258(" ? - this message\n");
            break;
        }
    }
}


