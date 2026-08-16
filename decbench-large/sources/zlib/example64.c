






     
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



static char hello[] = "hello, hello!";




static const char dictionary[] = "hello";
static uLong dictId;

void test_deflate (Byte *compr, uLong comprLen);
void test_inflate (Byte *compr, uLong comprLen, Byte *uncompr, uLong uncomprLen)
                                                             ;
void test_large_deflate (Byte *compr, uLong comprLen, Byte *uncompr, uLong uncomprLen)
                                                             ;
void test_large_inflate (Byte *compr, uLong comprLen, Byte *uncompr, uLong uncomprLen)
                                                             ;
void test_flush (Byte *compr, uLong *comprLen);
void test_sync (Byte *compr, uLong comprLen, Byte *uncompr, uLong uncomprLen)
                                                             ;
void test_dict_deflate (Byte *compr, uLong comprLen);
void test_dict_inflate (Byte *compr, uLong comprLen, Byte *uncompr, uLong uncomprLen)
                                                             ;
int main (int argc, char *argv[]);
static alloc_func zalloc = (alloc_func)0;
static free_func zfree = (free_func)0;

void test_compress (Byte *compr, uLong comprLen, Byte *uncompr, uLong uncomprLen)
                                                             ;
void test_gzio (const char *fname, Byte *uncompr, uLong uncomprLen)
                                                             ;




void test_compress(compr, comprLen, uncompr, uncomprLen)
    Byte *compr, *uncompr;
    uLong comprLen, uncomprLen;
{
    int err;
    uLong len = (uLong)strlen(hello)+1;

    err = compress(compr, &comprLen, (const Bytef*)hello, len);
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "compress", err); exit(1); } };

    strcpy((char*)uncompr, "garbage");

    err = uncompress(uncompr, &uncomprLen, compr, comprLen);
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "uncompress", err); exit(1); } };

    if (strcmp((char*)uncompr, hello)) {
        fprintf(
               stderr
                     , "bad uncompress\n");
        exit(1);
    } else {
        printf("uncompress(): %s\n", (char *)uncompr);
    }
}




void test_gzio(fname, uncompr, uncomprLen)
    const char *fname;
    Byte *uncompr;
    uLong uncomprLen;
{



    int err;
    int len = (int)strlen(hello)+1;
    gzFile file;
    off_t pos;

    file = gzopen64(fname, "wb");
    if (file == 
               ((void *)0)
                   ) {
        fprintf(
               stderr
                     , "gzopen error\n");
        exit(1);
    }
    gzputc(file, 'h');
    if (gzputs(file, "ello") != 4) {
        fprintf(
               stderr
                     , "gzputs err: %s\n", gzerror(file, &err));
        exit(1);
    }
    if (gzprintf(file, ", %s!", "hello") != 8) {
        fprintf(
               stderr
                     , "gzprintf err: %s\n", gzerror(file, &err));
        exit(1);
    }
    gzseek64(file, 1L, 
                    1
                            );
    gzclose(file);

    file = gzopen64(fname, "rb");
    if (file == 
               ((void *)0)
                   ) {
        fprintf(
               stderr
                     , "gzopen error\n");
        exit(1);
    }
    strcpy((char*)uncompr, "garbage");

    if (gzread(file, uncompr, (unsigned)uncomprLen) != len) {
        fprintf(
               stderr
                     , "gzread err: %s\n", gzerror(file, &err));
        exit(1);
    }
    if (strcmp((char*)uncompr, hello)) {
        fprintf(
               stderr
                     , "bad gzread: %s\n", (char*)uncompr);
        exit(1);
    } else {
        printf("gzread(): %s\n", (char*)uncompr);
    }

    pos = gzseek64(file, -8L, 
                           1
                                   );
    if (pos != 6 || gztell64(file) != pos) {
        fprintf(
               stderr
                     , "gzseek error, pos=%ld, gztell=%ld\n",
                (long)pos, (long)gztell64(file));
        exit(1);
    }

    if (((file)->have ? ((file)->have--, (file)->pos++, *((file)->next)++) : (gzgetc)(file)) != ' ') {
        fprintf(
               stderr
                     , "gzgetc error\n");
        exit(1);
    }

    if (gzungetc(' ', file) != ' ') {
        fprintf(
               stderr
                     , "gzungetc error\n");
        exit(1);
    }

    gzgets(file, (char*)uncompr, (int)uncomprLen);
    if (strlen((char*)uncompr) != 7) {
        fprintf(
               stderr
                     , "gzgets err after gzseek: %s\n", gzerror(file, &err));
        exit(1);
    }
    if (strcmp((char*)uncompr, hello + 6)) {
        fprintf(
               stderr
                     , "bad gzgets after gzseek\n");
        exit(1);
    } else {
        printf("gzgets() after gzseek: %s\n", (char*)uncompr);
    }

    gzclose(file);

}






void test_deflate(compr, comprLen)
    Byte *compr;
    uLong comprLen;
{
    z_stream c_stream;
    int err;
    uLong len = (uLong)strlen(hello)+1;

    c_stream.zalloc = zalloc;
    c_stream.zfree = zfree;
    c_stream.opaque = (voidpf)0;

    err = deflateInit_((&c_stream), ((-1)), "1.2.13", (int)sizeof(z_stream));
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "deflateInit", err); exit(1); } };

    c_stream.next_in = ( unsigned char *)hello;
    c_stream.next_out = compr;

    while (c_stream.total_in != len && c_stream.total_out < comprLen) {
        c_stream.avail_in = c_stream.avail_out = 1;
        err = deflate(&c_stream, 0);
        { if (err != 0) { fprintf(
       stderr
       , "%s error: %d\n", "deflate", err); exit(1); } };
    }

    for (;;) {
        c_stream.avail_out = 1;
        err = deflate(&c_stream, 4);
        if (err == 1) break;
        { if (err != 0) { fprintf(
       stderr
       , "%s error: %d\n", "deflate", err); exit(1); } };
    }

    err = deflateEnd(&c_stream);
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "deflateEnd", err); exit(1); } };
}




void test_inflate(compr, comprLen, uncompr, uncomprLen)
    Byte *compr, *uncompr;
    uLong comprLen, uncomprLen;
{
    int err;
    z_stream d_stream;

    strcpy((char*)uncompr, "garbage");

    d_stream.zalloc = zalloc;
    d_stream.zfree = zfree;
    d_stream.opaque = (voidpf)0;

    d_stream.next_in = compr;
    d_stream.avail_in = 0;
    d_stream.next_out = uncompr;

    err = inflateInit_((&d_stream), "1.2.13", (int)sizeof(z_stream));
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "inflateInit", err); exit(1); } };

    while (d_stream.total_out < uncomprLen && d_stream.total_in < comprLen) {
        d_stream.avail_in = d_stream.avail_out = 1;
        err = inflate(&d_stream, 0);
        if (err == 1) break;
        { if (err != 0) { fprintf(
       stderr
       , "%s error: %d\n", "inflate", err); exit(1); } };
    }

    err = inflateEnd(&d_stream);
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "inflateEnd", err); exit(1); } };

    if (strcmp((char*)uncompr, hello)) {
        fprintf(
               stderr
                     , "bad inflate\n");
        exit(1);
    } else {
        printf("inflate(): %s\n", (char *)uncompr);
    }
}




void test_large_deflate(compr, comprLen, uncompr, uncomprLen)
    Byte *compr, *uncompr;
    uLong comprLen, uncomprLen;
{
    z_stream c_stream;
    int err;

    c_stream.zalloc = zalloc;
    c_stream.zfree = zfree;
    c_stream.opaque = (voidpf)0;

    err = deflateInit_((&c_stream), (1), "1.2.13", (int)sizeof(z_stream));
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "deflateInit", err); exit(1); } };

    c_stream.next_out = compr;
    c_stream.avail_out = (uInt)comprLen;




    c_stream.next_in = uncompr;
    c_stream.avail_in = (uInt)uncomprLen;
    err = deflate(&c_stream, 0);
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "deflate", err); exit(1); } };
    if (c_stream.avail_in != 0) {
        fprintf(
               stderr
                     , "deflate not greedy\n");
        exit(1);
    }


    deflateParams(&c_stream, 0, 0);
    c_stream.next_in = compr;
    c_stream.avail_in = (uInt)comprLen/2;
    err = deflate(&c_stream, 0);
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "deflate", err); exit(1); } };


    deflateParams(&c_stream, 9, 1);
    c_stream.next_in = uncompr;
    c_stream.avail_in = (uInt)uncomprLen;
    err = deflate(&c_stream, 0);
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "deflate", err); exit(1); } };

    err = deflate(&c_stream, 4);
    if (err != 1) {
        fprintf(
               stderr
                     , "deflate should report Z_STREAM_END\n");
        exit(1);
    }
    err = deflateEnd(&c_stream);
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "deflateEnd", err); exit(1); } };
}




void test_large_inflate(compr, comprLen, uncompr, uncomprLen)
    Byte *compr, *uncompr;
    uLong comprLen, uncomprLen;
{
    int err;
    z_stream d_stream;

    strcpy((char*)uncompr, "garbage");

    d_stream.zalloc = zalloc;
    d_stream.zfree = zfree;
    d_stream.opaque = (voidpf)0;

    d_stream.next_in = compr;
    d_stream.avail_in = (uInt)comprLen;

    err = inflateInit_((&d_stream), "1.2.13", (int)sizeof(z_stream));
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "inflateInit", err); exit(1); } };

    for (;;) {
        d_stream.next_out = uncompr;
        d_stream.avail_out = (uInt)uncomprLen;
        err = inflate(&d_stream, 0);
        if (err == 1) break;
        { if (err != 0) { fprintf(
       stderr
       , "%s error: %d\n", "large inflate", err); exit(1); } };
    }

    err = inflateEnd(&d_stream);
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "inflateEnd", err); exit(1); } };

    if (d_stream.total_out != 2*uncomprLen + comprLen/2) {
        fprintf(
               stderr
                     , "bad large inflate: %ld\n", d_stream.total_out);
        exit(1);
    } else {
        printf("large_inflate(): OK\n");
    }
}




void test_flush(compr, comprLen)
    Byte *compr;
    uLong *comprLen;
{
    z_stream c_stream;
    int err;
    uInt len = (uInt)strlen(hello)+1;

    c_stream.zalloc = zalloc;
    c_stream.zfree = zfree;
    c_stream.opaque = (voidpf)0;

    err = deflateInit_((&c_stream), ((-1)), "1.2.13", (int)sizeof(z_stream));
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "deflateInit", err); exit(1); } };

    c_stream.next_in = ( unsigned char *)hello;
    c_stream.next_out = compr;
    c_stream.avail_in = 3;
    c_stream.avail_out = (uInt)*comprLen;
    err = deflate(&c_stream, 3);
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "deflate", err); exit(1); } };

    compr[3]++;
    c_stream.avail_in = len - 3;

    err = deflate(&c_stream, 4);
    if (err != 1) {
        { if (err != 0) { fprintf(
       stderr
       , "%s error: %d\n", "deflate", err); exit(1); } };
    }
    err = deflateEnd(&c_stream);
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "deflateEnd", err); exit(1); } };

    *comprLen = c_stream.total_out;
}




void test_sync(compr, comprLen, uncompr, uncomprLen)
    Byte *compr, *uncompr;
    uLong comprLen, uncomprLen;
{
    int err;
    z_stream d_stream;

    strcpy((char*)uncompr, "garbage");

    d_stream.zalloc = zalloc;
    d_stream.zfree = zfree;
    d_stream.opaque = (voidpf)0;

    d_stream.next_in = compr;
    d_stream.avail_in = 2;

    err = inflateInit_((&d_stream), "1.2.13", (int)sizeof(z_stream));
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "inflateInit", err); exit(1); } };

    d_stream.next_out = uncompr;
    d_stream.avail_out = (uInt)uncomprLen;

    err = inflate(&d_stream, 0);
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "inflate", err); exit(1); } };

    d_stream.avail_in = (uInt)comprLen-2;
    err = inflateSync(&d_stream);
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "inflateSync", err); exit(1); } };

    err = inflate(&d_stream, 4);
    if (err != 1) {
        fprintf(
               stderr
                     , "inflate should report Z_STREAM_END\n");
        exit(1);
    }
    err = inflateEnd(&d_stream);
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "inflateEnd", err); exit(1); } };

    printf("after inflateSync(): hel%s\n", (char *)uncompr);
}




void test_dict_deflate(compr, comprLen)
    Byte *compr;
    uLong comprLen;
{
    z_stream c_stream;
    int err;

    c_stream.zalloc = zalloc;
    c_stream.zfree = zfree;
    c_stream.opaque = (voidpf)0;

    err = deflateInit_((&c_stream), (9), "1.2.13", (int)sizeof(z_stream));
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "deflateInit", err); exit(1); } };

    err = deflateSetDictionary(&c_stream,
                (const Bytef*)dictionary, (int)sizeof(dictionary));
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "deflateSetDictionary", err); exit(1); } };

    dictId = c_stream.adler;
    c_stream.next_out = compr;
    c_stream.avail_out = (uInt)comprLen;

    c_stream.next_in = ( unsigned char *)hello;
    c_stream.avail_in = (uInt)strlen(hello)+1;

    err = deflate(&c_stream, 4);
    if (err != 1) {
        fprintf(
               stderr
                     , "deflate should report Z_STREAM_END\n");
        exit(1);
    }
    err = deflateEnd(&c_stream);
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "deflateEnd", err); exit(1); } };
}




void test_dict_inflate(compr, comprLen, uncompr, uncomprLen)
    Byte *compr, *uncompr;
    uLong comprLen, uncomprLen;
{
    int err;
    z_stream d_stream;

    strcpy((char*)uncompr, "garbage");

    d_stream.zalloc = zalloc;
    d_stream.zfree = zfree;
    d_stream.opaque = (voidpf)0;

    d_stream.next_in = compr;
    d_stream.avail_in = (uInt)comprLen;

    err = inflateInit_((&d_stream), "1.2.13", (int)sizeof(z_stream));
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "inflateInit", err); exit(1); } };

    d_stream.next_out = uncompr;
    d_stream.avail_out = (uInt)uncomprLen;

    for (;;) {
        err = inflate(&d_stream, 0);
        if (err == 1) break;
        if (err == 2) {
            if (d_stream.adler != dictId) {
                fprintf(
                       stderr
                             , "unexpected dictionary");
                exit(1);
            }
            err = inflateSetDictionary(&d_stream, (const Bytef*)dictionary,
                                       (int)sizeof(dictionary));
        }
        { if (err != 0) { fprintf(
       stderr
       , "%s error: %d\n", "inflate with dict", err); exit(1); } };
    }

    err = inflateEnd(&d_stream);
    { if (err != 0) { fprintf(
   stderr
   , "%s error: %d\n", "inflateEnd", err); exit(1); } };

    if (strcmp((char*)uncompr, hello)) {
        fprintf(
               stderr
                     , "bad inflate with dict\n");
        exit(1);
    } else {
        printf("inflate with dictionary: %s\n", (char *)uncompr);
    }
}





int main(argc, argv)
    int argc;
    char *argv[];
{
    Byte *compr, *uncompr;
    uLong comprLen = 10000*sizeof(int);
    uLong uncomprLen = comprLen;
    static const char* myVersion = "1.2.13";

    if (zlibVersion()[0] != myVersion[0]) {
        fprintf(
               stderr
                     , "incompatible zlib version\n");
        exit(1);

    } else if (strcmp(zlibVersion(), "1.2.13") != 0) {
        fprintf(
               stderr
                     , "warning: different zlib version linked: %s\n",
                zlibVersion());
    }

    printf("zlib version %s = 0x%04x, compile flags = 0x%lx\n",
            "1.2.13", 0x12d0, zlibCompileFlags());

    compr = (Byte*)calloc((uInt)comprLen, 1);
    uncompr = (Byte*)calloc((uInt)uncomprLen, 1);



    if (compr == 0 || uncompr == 0) {
        printf("out of memory\n");
        exit(1);
    }





    test_compress(compr, comprLen, uncompr, uncomprLen);

    test_gzio((argc > 1 ? argv[1] : "foo.gz"),
              uncompr, uncomprLen);


    test_deflate(compr, comprLen);
    test_inflate(compr, comprLen, uncompr, uncomprLen);

    test_large_deflate(compr, comprLen, uncompr, uncomprLen);
    test_large_inflate(compr, comprLen, uncompr, uncomprLen);

    test_flush(compr, &comprLen);
    test_sync(compr, comprLen, uncompr, uncomprLen);
    comprLen = uncomprLen;

    test_dict_deflate(compr, comprLen);
    test_dict_inflate(compr, comprLen, uncompr, uncomprLen);

    free(compr);
    free(uncompr);

    return 0;
}
