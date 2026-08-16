// Function: _usbd_standard_request_device @ 0x8001914
/*
 * Dispatcher on the "kind" byte at offset 1 of the object pointed to by op.
 * The context pointer in the first argument and the object pointer are
 * forwarded unchanged to the selected handler, whose result is returned.
 */

extern int sub_8001554(void *ctx, const unsigned char *op);
extern int sub_80013cc(void *ctx, const unsigned char *op);
extern int sub_80017c8(void *ctx, const unsigned char *op);
extern int sub_8001490(void *ctx, const unsigned char *op);
extern int sub_80013f8(void *ctx, const unsigned char *op);

int _usbd_standard_request_device(void *ctx, const unsigned char *op)
{
    switch (op[1]) {
    case 0:
        return sub_8001554(ctx, op);
    case 5:
        return sub_80013cc(ctx, op);
    case 7:
        return sub_80017c8(ctx, op);
    case 8:
        return sub_8001490(ctx, op);
    case 9:
        return sub_80013f8(ctx, op);
    default:
        return 0;
    }
}


