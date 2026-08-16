// Function: dwc_poll @ 0x8001714
#include <stdint.h>

typedef void (*hook_t)(void);
typedef void (*idx_fn_t)(void *, int);

extern void sub_8000790(void *s);
extern int  sub_8001694(void *s, int idx, void *buf, int n);
extern void sub_8001364(void *ctx, int idx);

void dwc_poll(void *arg)
{
    unsigned char *s   = (unsigned char *)arg;
    unsigned char *ctx = *(unsigned char **)(s + 0xdc);
    unsigned char *b   = *(unsigned char **)(ctx + 0x2c);
    uint32_t flags = *(uint32_t *)(b + 0x14);
    int i;

    if (flags & 0x2000) {
        uint16_t w = *(uint16_t *)(ctx + 0x32);
        *(uint32_t *)(b + 0x14) = 0x2000;
        *(uint16_t *)(s + 0xe8) = w;
        sub_8000790(s);
        return;
    }

    for (i = 0; i < 4; i++) {
        b = *(unsigned char **)(ctx + 0x2c);
        if (*(uint32_t *)(b + 0x908 + i * 32) & 1) {
            idx_fn_t fn = *(idx_fn_t *)(s + 0x68 + i * 12);
            if (fn) {
                fn(s, (unsigned char)i);
                ctx = *(unsigned char **)(s + 0xdc);
                b   = *(unsigned char **)(ctx + 0x2c);
            }
            *(uint32_t *)(b + 0x908 + i * 32) = 1;
        }
    }

    if (flags & 0x10) {
        uint32_t spec;

        b = *(unsigned char **)(ctx + 0x2c);
        spec = *(uint32_t *)(b + 0x20);
        int idx = spec & 0xf;

        switch (spec & 0x1e0000) {
        case 0x80000: {
            idx_fn_t fn = *(idx_fn_t *)(s + 0x70 + idx * 12);
            fn(s, idx);
            ctx = *(unsigned char **)(s + 0xdc);
            b   = *(unsigned char **)(ctx + 0x2c);
        }
            /* fall through */
        case 0x60000:
            *(uint32_t *)(b + 0xb10 + idx * 32) =
                *(uint32_t *)(s + 0xf0 + idx * 4);
            b = *(unsigned char **)(ctx + 0x2c);
            *(uint32_t *)(b + 0xb00 + idx * 32) |=
                *(uint8_t *)(s + 0xec + idx) ? 0x88000000u : 0x84000000u;
            return;

        case 0x40000: {
            idx_fn_t fn = *(idx_fn_t *)(s + 0x6c + idx * 12);
            *(uint16_t *)(s + 0x100) = (uint16_t)((spec >> 4) & 0x7ff);
            if (fn)
                fn(s, idx);
            break;
        }

        case 0xc0000:
            if (*(uint32_t *)(b + 0x910 + idx * 32) & (1u << 19))
                sub_8001364(ctx, idx);
            *(uint16_t *)(s + 0x100) = (uint16_t)((spec >> 4) & 0x7ff);
            sub_8001694(s, idx, s + 0x30, 8);
            break;

        default:
            return;
        }

        {
            uint16_t n = *(uint16_t *)(s + 0x100);
            if (n) {
                unsigned char *c  = *(unsigned char **)(s + 0xdc);
                unsigned char *bb = *(unsigned char **)(c + 0x2c);
                int j = 0;
                do {
                    j += 4;
                    (void)*(volatile uint32_t *)(bb + 0x1000);
                } while (j < n);
            }
            *(uint16_t *)(s + 0x100) = 0;
        }
    }

    if (flags & 0x800) {
        hook_t cb = *(hook_t *)(s + 0x20);
        if (cb)
            cb();
        b = *(unsigned char **)(*(unsigned char **)(s + 0xdc) + 0x2c);
        *(uint32_t *)(b + 0x14) = 0x800;
    }

    if ((int32_t)flags < 0) {
        hook_t cb = *(hook_t *)(s + 0x24);
        if (cb)
            cb();
        b = *(unsigned char **)(*(unsigned char **)(s + 0xdc) + 0x2c);
        *(uint32_t *)(b + 0x14) = 0x80000000u;
    }

    {
        hook_t cb28 = *(hook_t *)(s + 0x28);
        if (flags & 0x8) {
            if (cb28)
                cb28();
            b = *(unsigned char **)(*(unsigned char **)(s + 0xdc) + 0x2c);
            *(uint32_t *)(b + 0x14) = 8;
        } else {
            b = *(unsigned char **)(*(unsigned char **)(s + 0xdc) + 0x2c);
        }
        if (cb28)
            *(uint32_t *)(b + 0x18) |= 8;
        else
            *(uint32_t *)(b + 0x18) &= ~8u;
    }
}


