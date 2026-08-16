




     
    typedef size_t z_size_t;
typedef unsigned char Byte;

typedef unsigned int uInt;
typedef unsigned long uLong;





   typedef Byte Bytef;

typedef char charf;
typedef int intf;
typedef uInt uIntf;
typedef uLong uLongf;


   typedef void const *voidpc;
   typedef void *voidpf;
   typedef void *voidp;







   typedef unsigned z_crc_t;






typedef voidpf (*alloc_func) (voidpf opaque, uInt items, uInt size);
typedef void (*free_func) (voidpf opaque, voidpf address);

struct internal_state;

typedef struct z_stream_s {
    Bytef *next_in;
    uInt avail_in;
    uLong total_in;

    Bytef *next_out;
    uInt avail_out;
    uLong total_out;

    char *msg;
    struct internal_state *state;

    alloc_func zalloc;
    free_func zfree;
    voidpf opaque;

    int data_type;

    uLong adler;
    uLong reserved;
} z_stream;

typedef z_stream *z_streamp;





typedef struct gz_header_s {
    int text;
    uLong time;
    int xflags;
    int os;
    Bytef *extra;
    uInt extra_len;
    uInt extra_max;
    Bytef *name;
    uInt name_max;
    Bytef *comment;
    uInt comm_max;
    int hcrc;
    int done;

} gz_header;

typedef gz_header *gz_headerp;
extern const char * zlibVersion (void);
extern int deflate (z_streamp strm, int flush);
extern int deflateEnd (z_streamp strm);
extern int inflate (z_streamp strm, int flush);
extern int inflateEnd (z_streamp strm);
extern int deflateSetDictionary (z_streamp strm, const Bytef *dictionary, uInt dictLength)

                                                               ;
extern int deflateGetDictionary (z_streamp strm, Bytef *dictionary, uInt *dictLength)

                                                                ;
extern int deflateCopy (z_streamp dest, z_streamp source)
                                                      ;
extern int deflateReset (z_streamp strm);
extern int deflateParams (z_streamp strm, int level, int strategy)

                                                    ;
extern int deflateTune (z_streamp strm, int good_length, int max_lazy, int nice_length, int max_chain)



                                                   ;
extern uLong deflateBound (z_streamp strm, uLong sourceLen)
                                                        ;
extern int deflatePending (z_streamp strm, unsigned *pending, int *bits)

                                                  ;
extern int deflatePrime (z_streamp strm, int bits, int value)

                                                ;
extern int deflateSetHeader (z_streamp strm, gz_headerp head)
                                                          ;
extern int inflateSetDictionary (z_streamp strm, const Bytef *dictionary, uInt dictLength)

                                                               ;
extern int inflateGetDictionary (z_streamp strm, Bytef *dictionary, uInt *dictLength)

                                                                ;
extern int inflateSync (z_streamp strm);
extern int inflateCopy (z_streamp dest, z_streamp source)
                                                      ;
extern int inflateReset (z_streamp strm);
extern int inflateReset2 (z_streamp strm, int windowBits)
                                                      ;
extern int inflatePrime (z_streamp strm, int bits, int value)

                                                ;
extern long inflateMark (z_streamp strm);
extern int inflateGetHeader (z_streamp strm, gz_headerp head)
                                                          ;
typedef unsigned (*in_func) (void *, unsigned char * *)
                                                                   ;
typedef int (*out_func) (void *, unsigned char *, unsigned);

extern int inflateBack (z_streamp strm, in_func in, void *in_desc, out_func out, void *out_desc)

                                                                      ;
extern int inflateBackEnd (z_streamp strm);







extern uLong zlibCompileFlags (void);
extern int compress (Bytef *dest, uLongf *destLen, const Bytef *source, uLong sourceLen)
                                                                       ;
extern int compress2 (Bytef *dest, uLongf *destLen, const Bytef *source, uLong sourceLen, int level)

                                             ;
extern uLong compressBound (uLong sourceLen);






extern int uncompress (Bytef *dest, uLongf *destLen, const Bytef *source, uLong sourceLen)
                                                                         ;
extern int uncompress2 (Bytef *dest, uLongf *destLen, const Bytef *source, uLong *sourceLen)
                                                                           ;
typedef struct gzFile_s *gzFile;
extern gzFile gzdopen (int fd, const char *mode);
extern int gzbuffer (gzFile file, unsigned size);
extern int gzsetparams (gzFile file, int level, int strategy);
extern int gzread (gzFile file, voidp buf, unsigned len);
extern z_size_t gzfread (voidp buf, z_size_t size, z_size_t nitems, gzFile file)
                                                  ;
extern int gzwrite (gzFile file, voidpc buf, unsigned len);





extern z_size_t gzfwrite (voidpc buf, z_size_t size, z_size_t nitems, gzFile file)
                                                                    ;
extern int gzprintf (gzFile file, const char *format, ...);
extern int gzputs (gzFile file, const char *s);







extern char * gzgets (gzFile file, char *buf, int len);
extern int gzputc (gzFile file, int c);





extern int gzgetc (gzFile file);
extern int gzungetc (int c, gzFile file);
extern int gzflush (gzFile file, int flush);
extern int gzrewind (gzFile file);
extern int gzeof (gzFile file);
extern int gzdirect (gzFile file);
extern int gzclose (gzFile file);
extern int gzclose_r (gzFile file);
extern int gzclose_w (gzFile file);
extern const char * gzerror (gzFile file, int *errnum);
extern void gzclearerr (gzFile file);
extern uLong adler32 (uLong adler, const Bytef *buf, uInt len);
extern uLong adler32_z (uLong adler, const Bytef *buf, z_size_t len)
                                                  ;
extern uLong crc32 (uLong crc, const Bytef *buf, uInt len);
extern uLong crc32_z (uLong crc, const Bytef *buf, z_size_t len)
                                                ;
extern uLong crc32_combine_op (uLong crc1, uLong crc2, uLong op);
extern int deflateInit_ (z_streamp strm, int level, const char *version, int stream_size)
                                                                           ;
extern int inflateInit_ (z_streamp strm, const char *version, int stream_size)
                                                                           ;
extern int deflateInit2_ (z_streamp strm, int level, int method, int windowBits, int memLevel, int strategy, const char *version, int stream_size)


                                                       ;
extern int inflateInit2_ (z_streamp strm, int windowBits, const char *version, int stream_size)
                                                                            ;
extern int inflateBackInit_ (z_streamp strm, int windowBits, unsigned char *window, const char *version, int stream_size)


                                                          ;
struct gzFile_s {
    unsigned have;
    unsigned char *next;
    off64_t pos;
};
extern int gzgetc_ (gzFile file);
   extern gzFile gzopen64 (const char *, const char *);
   extern off64_t gzseek64 (gzFile, off64_t, int);
   extern off64_t gztell64 (gzFile);
   extern off64_t gzoffset64 (gzFile);
   extern uLong adler32_combine64 (uLong, uLong, off64_t);
   extern uLong crc32_combine64 (uLong, uLong, off64_t);
   extern uLong crc32_combine_gen64 (off64_t);
   extern gzFile gzopen (const char *, const char *);
   extern off_t gzseek (gzFile, off_t, int);
   extern off_t gztell (gzFile);
   extern off_t gzoffset (gzFile);
   extern uLong adler32_combine (uLong, uLong, off_t);
   extern uLong crc32_combine (uLong, uLong, off_t);
   extern uLong crc32_combine_gen (off_t);
extern const char * zError (int);
extern int inflateSyncPoint (z_streamp);
extern const z_crc_t * get_crc_table (void);
extern int inflateUndermine (z_streamp, int);
extern int inflateValidate (z_streamp, int);
extern unsigned long inflateCodesUsed (z_streamp);
extern int inflateResetKeep (z_streamp);
extern int deflateResetKeep (z_streamp);






extern int gzvprintf (gzFile file, const char *format, va_list va)

                                                              ;





typedef unsigned char uch;
typedef uch uchf;
typedef unsigned short ush;
typedef ush ushf;
typedef unsigned long ulg;


extern char * const z_errmsg[10];
   voidpf __attribute__((visibility ("hidden"))) zcalloc (voidpf opaque, unsigned items, unsigned size)
                                                   ;
   void __attribute__((visibility ("hidden"))) zcfree (voidpf opaque, voidpf ptr);
typedef struct {
    unsigned char op;
    unsigned char bits;
    unsigned short val;
} code;
typedef enum {
    CODES,
    LENS,
    DISTS
} codetype;

int __attribute__((visibility ("hidden"))) inflate_table (codetype type, unsigned short *lens, unsigned codes, code * *table, unsigned *bits, unsigned short *work)

                                                                           ;



const char inflate_copyright[] =
   " inflate 1.2.13 Copyright 1995-2022 Mark Adler ";
int __attribute__((visibility ("hidden"))) inflate_table(type, lens, codes, table, bits, work)
codetype type;
unsigned short *lens;
unsigned codes;
code * *table;
unsigned *bits;
unsigned short *work;
{
    unsigned len;
    unsigned sym;
    unsigned min, max;
    unsigned root;
    unsigned curr;
    unsigned drop;
    int left;
    unsigned used;
    unsigned huff;
    unsigned incr;
    unsigned fill;
    unsigned low;
    unsigned mask;
    code here;
    code *next;
    const unsigned short *base;
    const unsigned short *extra;
    unsigned match;
    unsigned short count[15 +1];
    unsigned short offs[15 +1];
    static const unsigned short lbase[31] = {
        3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
        35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258, 0, 0};
    static const unsigned short lext[31] = {
        16, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18,
        19, 19, 19, 19, 20, 20, 20, 20, 21, 21, 21, 21, 16, 194, 65};
    static const unsigned short dbase[32] = {
        1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193,
        257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145,
        8193, 12289, 16385, 24577, 0, 0};
    static const unsigned short dext[32] = {
        16, 16, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22,
        23, 23, 24, 24, 25, 25, 26, 26, 27, 27,
        28, 28, 29, 29, 64, 64};
    for (len = 0; len <= 15; len++)
        count[len] = 0;
    for (sym = 0; sym < codes; sym++)
        count[lens[sym]]++;


    root = *bits;
    for (max = 15; max >= 1; max--)
        if (count[max] != 0) break;
    if (root > max) root = max;
    if (max == 0) {
        here.op = (unsigned char)64;
        here.bits = (unsigned char)1;
        here.val = (unsigned short)0;
        *(*table)++ = here;
        *(*table)++ = here;
        *bits = 1;
        return 0;
    }
    for (min = 1; min < max; min++)
        if (count[min] != 0) break;
    if (root < min) root = min;


    left = 1;
    for (len = 1; len <= 15; len++) {
        left <<= 1;
        left -= count[len];
        if (left < 0) return -1;
    }
    if (left > 0 && (type == CODES || max != 1))
        return -1;


    offs[1] = 0;
    for (len = 1; len < 15; len++)
        offs[len + 1] = offs[len] + count[len];


    for (sym = 0; sym < codes; sym++)
        if (lens[sym] != 0) work[offs[lens[sym]]++] = (unsigned short)sym;
    switch (type) {
    case CODES:
        base = extra = work;
        match = 20;
        break;
    case LENS:
        base = lbase;
        extra = lext;
        match = 257;
        break;
    default:
        base = dbase;
        extra = dext;
        match = 0;
    }


    huff = 0;
    sym = 0;
    len = min;
    next = *table;
    curr = root;
    drop = 0;
    low = (unsigned)(-1);
    used = 1U << root;
    mask = used - 1;


    if ((type == LENS && used > 852) ||
        (type == DISTS && used > 592))
        return 1;


    for (;;) {

        here.bits = (unsigned char)(len - drop);
        if (work[sym] + 1U < match) {
            here.op = (unsigned char)0;
            here.val = work[sym];
        }
        else if (work[sym] >= match) {
            here.op = (unsigned char)(extra[work[sym] - match]);
            here.val = base[work[sym] - match];
        }
        else {
            here.op = (unsigned char)(32 + 64);
            here.val = 0;
        }


        incr = 1U << (len - drop);
        fill = 1U << curr;
        min = fill;
        do {
            fill -= incr;
            next[(huff >> drop) + fill] = here;
        } while (fill != 0);


        incr = 1U << (len - 1);
        while (huff & incr)
            incr >>= 1;
        if (incr != 0) {
            huff &= incr - 1;
            huff += incr;
        }
        else
            huff = 0;


        sym++;
        if (--(count[len]) == 0) {
            if (len == max) break;
            len = lens[work[sym]];
        }


        if (len > root && (huff & mask) != low) {

            if (drop == 0)
                drop = root;


            next += min;


            curr = len - drop;
            left = (int)(1 << curr);
            while (curr + drop < max) {
                left -= count[curr + drop];
                if (left <= 0) break;
                curr++;
                left <<= 1;
            }


            used += 1U << curr;
            if ((type == LENS && used > 852) ||
                (type == DISTS && used > 592))
                return 1;


            low = huff & mask;
            (*table)[low].op = (unsigned char)curr;
            (*table)[low].bits = (unsigned char)root;
            (*table)[low].val = (unsigned short)(next - *table);
        }
    }




    if (huff != 0) {
        here.op = (unsigned char)64;
        here.bits = (unsigned char)(len - drop);
        here.val = (unsigned short)0;
        next[huff] = here;
    }


    *table += used;
    *bits = root;
    return 0;
}
