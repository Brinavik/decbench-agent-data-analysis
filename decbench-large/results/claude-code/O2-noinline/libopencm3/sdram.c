// Function: main @ 0x800053c
#include <stdint.h>

/* Board / peripheral bring-up */
extern void clock_setup(void);
extern void usart_setup(void);
extern void sdram_setup(void);

/* UART console helpers */
extern void uart_puts(const char *s);
extern int  uart_getc(int blocking);

/* Hex-dump helpers: print a 16-byte line / a 256-byte page starting at
   'addr', labelling offsets relative to 'base'.  Both return the address
   immediately after the region they printed. */
extern unsigned char *dump_line(unsigned char *addr, unsigned char *base);
extern unsigned char *dump_page(unsigned char *addr, unsigned char *base);

#define main ((unsigned char *)0xD0000000u)
#define PAGE_SIZE  0x100u

void main(void)
{
    unsigned char *page;
    unsigned char *p;
    uint32_t      *w;
    unsigned int   i;
    int            c;

    clock_setup();
    usart_setup();
    sdram_setup();

    uart_puts("SDRAM Example.\n");
    uart_puts("Original data:\n");
    dump_page(main, 0);

    /* Overwrite the first page with an incrementing pattern (each byte
       gets the low 8 bits of its own address). */
    for (p = main; p != main + PAGE_SIZE; p++)
        *p = (unsigned char)(uintptr_t)p;

    uart_puts("Modified data (with Fill Increment)\n");
    page = dump_page(main, 0);

    for (;;) {
        uart_puts("CMD> ");
        c = uart_getc(1);

        switch (c) {
        case 'F':
        case 'f':
            uart_puts("Fill ");
            c = uart_getc(1);
            switch (c) {
            case 'F':
            case 'f':
                uart_puts("Ones (0xff)\n");
                for (w = (uint32_t *)page;
                     w != (uint32_t *)(page + PAGE_SIZE); w++)
                    *w = 0xffffffffu;
                dump_page(page, 0);
                break;
            case 'I':
            case 'i':
                uart_puts("Increment\n");
                for (i = 0; i < PAGE_SIZE; i++)
                    page[i] = (unsigned char)i;
                dump_page(page, 0);
                break;
            case '0':
                uart_puts("Zero\n");
                for (w = (uint32_t *)page;
                     w != (uint32_t *)(page + PAGE_SIZE); w++)
                    *w = 0;
                dump_page(page, 0);
                break;
            default:
                uart_puts("Unrecognized Command, press ? for help\n");
                break;
            }
            break;

        case 'N':
        case 'n':
            uart_puts("Next ");
            c = uart_getc(1);
            switch (c) {
            case 'P':
            case 'p':
                uart_puts("Page\n");
                page += PAGE_SIZE;
                dump_page(page, 0);
                break;
            case 'L':
            case 'l':
                uart_puts("Line\n");
                page += 16;
                dump_line(page, 0);
                break;
            default:
                uart_puts("Unrecognized Command, press ? for help\n");
                break;
            }
            break;

        case 'P':
        case 'p':
            uart_puts("Previous ");
            c = uart_getc(1);
            switch (c) {
            case 'P':
            case 'p':
                uart_puts("Page\n");
                page -= PAGE_SIZE;
                dump_page(page, 0);
                break;
            case 'L':
            case 'l':
                uart_puts("Line\n");
                page -= 16;
                dump_line(page, 0);
                break;
            default:
                uart_puts("Unrecognized Command, press ? for help\n");
                break;
            }
            break;

        default:
            uart_puts("Help\n");
            uart_puts(" n p - dump next page\n");
            uart_puts(" n l - dump next line\n");
            uart_puts(" p p - dump previous page\n");
            uart_puts(" p l - dump previous line\n");
            uart_puts(" f 0 - fill current page with 0\n");
            uart_puts(" f i - fill current page with 0 to 255\n");
            uart_puts(" f f - fill current page with 0xff\n");
            uart_puts(" ? - this message\n");
            break;
        }
    }
}


