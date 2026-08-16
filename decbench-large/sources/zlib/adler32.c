






     
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

static uLong adler32_combine_ (uLong adler1, uLong adler2, off64_t len2);
uLong adler32_z(adler, buf, len)
    uLong adler;
    const Bytef *buf;
    z_size_t len;
{
    unsigned long sum2;
    unsigned n;


    sum2 = (adler >> 16) & 0xffff;
    adler &= 0xffff;


    if (len == 1) {
        adler += buf[0];
        if (adler >= 65521U)
            adler -= 65521U;
        sum2 += adler;
        if (sum2 >= 65521U)
            sum2 -= 65521U;
        return adler | (sum2 << 16);
    }


    if (buf == 0)
        return 1L;


    if (len < 16) {
        while (len--) {
            adler += *buf++;
            sum2 += adler;
        }
        if (adler >= 65521U)
            adler -= 65521U;
        sum2 %= 65521U;
        return adler | (sum2 << 16);
    }


    while (len >= 5552) {
        len -= 5552;
        n = 5552 / 16;
        do {
            {adler += (buf)[0]; sum2 += adler;}; {adler += (buf)[0 +1]; sum2 += adler;};; {adler += (buf)[0 +2]; sum2 += adler;}; {adler += (buf)[0 +2 +1]; sum2 += adler;};;; {adler += (buf)[0 +4]; sum2 += adler;}; {adler += (buf)[0 +4 +1]; sum2 += adler;};; {adler += (buf)[0 +4 +2]; sum2 += adler;}; {adler += (buf)[0 +4 +2 +1]; sum2 += adler;};;;; {adler += (buf)[8]; sum2 += adler;}; {adler += (buf)[8 +1]; sum2 += adler;};; {adler += (buf)[8 +2]; sum2 += adler;}; {adler += (buf)[8 +2 +1]; sum2 += adler;};;; {adler += (buf)[8 +4]; sum2 += adler;}; {adler += (buf)[8 +4 +1]; sum2 += adler;};; {adler += (buf)[8 +4 +2]; sum2 += adler;}; {adler += (buf)[8 +4 +2 +1]; sum2 += adler;};;;;;
            buf += 16;
        } while (--n);
        adler %= 65521U;
        sum2 %= 65521U;
    }


    if (len) {
        while (len >= 16) {
            len -= 16;
            {adler += (buf)[0]; sum2 += adler;}; {adler += (buf)[0 +1]; sum2 += adler;};; {adler += (buf)[0 +2]; sum2 += adler;}; {adler += (buf)[0 +2 +1]; sum2 += adler;};;; {adler += (buf)[0 +4]; sum2 += adler;}; {adler += (buf)[0 +4 +1]; sum2 += adler;};; {adler += (buf)[0 +4 +2]; sum2 += adler;}; {adler += (buf)[0 +4 +2 +1]; sum2 += adler;};;;; {adler += (buf)[8]; sum2 += adler;}; {adler += (buf)[8 +1]; sum2 += adler;};; {adler += (buf)[8 +2]; sum2 += adler;}; {adler += (buf)[8 +2 +1]; sum2 += adler;};;; {adler += (buf)[8 +4]; sum2 += adler;}; {adler += (buf)[8 +4 +1]; sum2 += adler;};; {adler += (buf)[8 +4 +2]; sum2 += adler;}; {adler += (buf)[8 +4 +2 +1]; sum2 += adler;};;;;;
            buf += 16;
        }
        while (len--) {
            adler += *buf++;
            sum2 += adler;
        }
        adler %= 65521U;
        sum2 %= 65521U;
    }


    return adler | (sum2 << 16);
}


uLong adler32(adler, buf, len)
    uLong adler;
    const Bytef *buf;
    uInt len;
{
    return adler32_z(adler, buf, len);
}


static uLong adler32_combine_(adler1, adler2, len2)
    uLong adler1;
    uLong adler2;
    off64_t len2;
{
    unsigned long sum1;
    unsigned long sum2;
    unsigned rem;


    if (len2 < 0)
        return 0xffffffffUL;


    len2 %= 65521U;
    rem = (unsigned)len2;
    sum1 = adler1 & 0xffff;
    sum2 = rem * sum1;
    sum2 %= 65521U;
    sum1 += (adler2 & 0xffff) + 65521U - 1;
    sum2 += ((adler1 >> 16) & 0xffff) + ((adler2 >> 16) & 0xffff) + 65521U - rem;
    if (sum1 >= 65521U) sum1 -= 65521U;
    if (sum1 >= 65521U) sum1 -= 65521U;
    if (sum2 >= ((unsigned long)65521U << 1)) sum2 -= ((unsigned long)65521U << 1);
    if (sum2 >= 65521U) sum2 -= 65521U;
    return sum1 | (sum2 << 16);
}


uLong adler32_combine(adler1, adler2, len2)
    uLong adler1;
    uLong adler2;
    off_t len2;
{
    return adler32_combine_(adler1, adler2, len2);
}

uLong adler32_combine64(adler1, adler2, len2)
    uLong adler1;
    uLong adler2;
    off64_t len2;
{
    return adler32_combine_(adler1, adler2, len2);
}
