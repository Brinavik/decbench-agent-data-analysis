




     
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







typedef struct {

    struct gzFile_s x;




    int mode;
    int fd;
    char *path;
    unsigned size;
    unsigned want;
    unsigned char *in;
    unsigned char *out;
    int direct;

    int how;
    off64_t start;
    int eof;
    int past;

    int level;
    int strategy;
    int reset;

    off64_t skip;
    int seek;

    int err;
    char *msg;

    z_stream strm;
} gz_state;
typedef gz_state *gz_statep;


void __attribute__((visibility ("hidden"))) gz_error (gz_statep, int, const char *);
static void gz_reset (gz_statep);
static gzFile gz_open (const void *, int, const char *);
static void gz_reset(state)
    gz_statep state;
{
    state->x.have = 0;
    if (state->mode == 7247) {
        state->eof = 0;
        state->past = 0;
        state->how = 0;
    }
    else
        state->reset = 0;
    state->seek = 0;
    gz_error(state, 0, 
                         ((void *)0)
                             );
    state->x.pos = 0;
    state->strm.avail_in = 0;
}


static gzFile gz_open(path, fd, mode)
    const void *path;
    int fd;
    const char *mode;
{
    gz_statep state;
    z_size_t len;
    int oflag;

    int cloexec = 0;


    int exclusive = 0;



    if (path == 
               ((void *)0)
                   )
        return 
              ((void *)0)
                  ;


    state = (gz_statep)malloc(sizeof(gz_state));
    if (state == 
                ((void *)0)
                    )
        return 
              ((void *)0)
                  ;
    state->size = 0;
    state->want = 8192;
    state->msg = 
                ((void *)0)
                    ;


    state->mode = 0;
    state->level = (-1);
    state->strategy = 0;
    state->direct = 0;
    while (*mode) {
        if (*mode >= '0' && *mode <= '9')
            state->level = *mode - '0';
        else
            switch (*mode) {
            case 'r':
                state->mode = 7247;
                break;

            case 'w':
                state->mode = 31153;
                break;
            case 'a':
                state->mode = 1;
                break;

            case '+':
                free(state);
                return 
                      ((void *)0)
                          ;
            case 'b':
                break;

            case 'e':
                cloexec = 1;
                break;


            case 'x':
                exclusive = 1;
                break;

            case 'f':
                state->strategy = 1;
                break;
            case 'h':
                state->strategy = 2;
                break;
            case 'R':
                state->strategy = 3;
                break;
            case 'F':
                state->strategy = 4;
                break;
            case 'T':
                state->direct = 1;
                break;
            default:
                ;
            }
        mode++;
    }


    if (state->mode == 0) {
        free(state);
        return 
              ((void *)0)
                  ;
    }


    if (state->mode == 7247) {
        if (state->direct) {
            free(state);
            return 
                  ((void *)0)
                      ;
        }
        state->direct = 1;
    }
        len = strlen((const char *)path);
    state->path = (char *)malloc(len + 1);
    if (state->path == 
                      ((void *)0)
                          ) {
        free(state);
        return 
              ((void *)0)
                  ;
    }
        (void)snprintf(state->path, len + 1, "%s", (const char *)path);





    oflag =

        
       0 
                   |





        (cloexec ? 
                  02000000 
                            : 0) |

        (state->mode == 7247 ?
         
        00 
                 :
         (
         01 
                  | 
                    0100 
                            |

          (exclusive ? 
                      0200 
                             : 0) |

          (state->mode == 31153 ?
           
          01000 
                  :
           
          02000
                  )));


    state->fd = fd > -1 ? fd : (



        open((const char *)path, oflag, 0666));
    if (state->fd == -1) {
        free(state->path);
        free(state);
        return 
              ((void *)0)
                  ;
    }
    if (state->mode == 1) {
        lseek64(state->fd, 0, 
                           2
                                   );
        state->mode = 31153;
    }


    if (state->mode == 7247) {
        state->start = lseek64(state->fd, 0, 
                                          1
                                                  );
        if (state->start == -1) state->start = 0;
    }


    gz_reset(state);


    return (gzFile)state;
}


gzFile gzopen(path, mode)
    const char *path;
    const char *mode;
{
    return gz_open(path, -1, mode);
}


gzFile gzopen64(path, mode)
    const char *path;
    const char *mode;
{
    return gz_open(path, -1, mode);
}


gzFile gzdopen(fd, mode)
    int fd;
    const char *mode;
{
    char *path;
    gzFile gz;

    if (fd == -1 || (path = (char *)malloc(7 + 3 * sizeof(int))) == 
                                                                   ((void *)0)
                                                                       )
        return 
              ((void *)0)
                  ;

    (void)snprintf(path, 7 + 3 * sizeof(int), "<fd:%d>", fd);



    gz = gz_open(path, fd, mode);
    free(path);
    return gz;
}
int gzbuffer(file, size)
    gzFile file;
    unsigned size;
{
    gz_statep state;


    if (file == 
               ((void *)0)
                   )
        return -1;
    state = (gz_statep)file;
    if (state->mode != 7247 && state->mode != 31153)
        return -1;


    if (state->size != 0)
        return -1;


    if ((size << 1) < size)
        return -1;
    if (size < 2)
        size = 2;
    state->want = size;
    return 0;
}


int gzrewind(file)
    gzFile file;
{
    gz_statep state;


    if (file == 
               ((void *)0)
                   )
        return -1;
    state = (gz_statep)file;


    if (state->mode != 7247 ||
            (state->err != 0 && state->err != (-5)))
        return -1;


    if (lseek64(state->fd, state->start, 
                                      0
                                              ) == -1)
        return -1;
    gz_reset(state);
    return 0;
}


off64_t gzseek64(file, offset, whence)
    gzFile file;
    off64_t offset;
    int whence;
{
    unsigned n;
    off64_t ret;
    gz_statep state;


    if (file == 
               ((void *)0)
                   )
        return -1;
    state = (gz_statep)file;
    if (state->mode != 7247 && state->mode != 31153)
        return -1;


    if (state->err != 0 && state->err != (-5))
        return -1;


    if (whence != 
                 0 
                          && whence != 
                                       1
                                               )
        return -1;


    if (whence == 
                 0
                         )
        offset -= state->x.pos;
    else if (state->seek)
        offset += state->skip;
    state->seek = 0;


    if (state->mode == 7247 && state->how == 1 &&
            state->x.pos + offset >= 0) {
        ret = lseek64(state->fd, offset - (off64_t)state->x.have, 
                                                                 1
                                                                         );
        if (ret == -1)
            return -1;
        state->x.have = 0;
        state->eof = 0;
        state->past = 0;
        state->seek = 0;
        gz_error(state, 0, 
                             ((void *)0)
                                 );
        state->strm.avail_in = 0;
        state->x.pos += offset;
        return state->x.pos;
    }


    if (offset < 0) {
        if (state->mode != 7247)
            return -1;
        offset += state->x.pos;
        if (offset < 0)
            return -1;
        if (gzrewind(file) == -1)
            return -1;
    }


    if (state->mode == 7247) {
        n = (sizeof(int) == sizeof(off64_t) && (state->x.have) > 0x7fffffff) || (off64_t)state->x.have > offset ?
            (unsigned)offset : state->x.have;
        state->x.have -= n;
        state->x.next += n;
        state->x.pos += n;
        offset -= n;
    }


    if (offset) {
        state->seek = 1;
        state->skip = offset;
    }
    return state->x.pos + offset;
}


off_t gzseek(file, offset, whence)
    gzFile file;
    off_t offset;
    int whence;
{
    off64_t ret;

    ret = gzseek64(file, (off64_t)offset, whence);
    return ret == (off_t)ret ? (off_t)ret : -1;
}


off64_t gztell64(file)
    gzFile file;
{
    gz_statep state;


    if (file == 
               ((void *)0)
                   )
        return -1;
    state = (gz_statep)file;
    if (state->mode != 7247 && state->mode != 31153)
        return -1;


    return state->x.pos + (state->seek ? state->skip : 0);
}


off_t gztell(file)
    gzFile file;
{
    off64_t ret;

    ret = gztell64(file);
    return ret == (off_t)ret ? (off_t)ret : -1;
}


off64_t gzoffset64(file)
    gzFile file;
{
    off64_t offset;
    gz_statep state;


    if (file == 
               ((void *)0)
                   )
        return -1;
    state = (gz_statep)file;
    if (state->mode != 7247 && state->mode != 31153)
        return -1;


    offset = lseek64(state->fd, 0, 
                                1
                                        );
    if (offset == -1)
        return -1;
    if (state->mode == 7247)
        offset -= state->strm.avail_in;
    return offset;
}


off_t gzoffset(file)
    gzFile file;
{
    off64_t ret;

    ret = gzoffset64(file);
    return ret == (off_t)ret ? (off_t)ret : -1;
}


int gzeof(file)
    gzFile file;
{
    gz_statep state;


    if (file == 
               ((void *)0)
                   )
        return 0;
    state = (gz_statep)file;
    if (state->mode != 7247 && state->mode != 31153)
        return 0;


    return state->mode == 7247 ? state->past : 0;
}


const char * gzerror(file, errnum)
    gzFile file;
    int *errnum;
{
    gz_statep state;


    if (file == 
               ((void *)0)
                   )
        return 
              ((void *)0)
                  ;
    state = (gz_statep)file;
    if (state->mode != 7247 && state->mode != 31153)
        return 
              ((void *)0)
                  ;


    if (errnum != 
                 ((void *)0)
                     )
        *errnum = state->err;
    return state->err == (-4) ? "out of memory" :
                                       (state->msg == 
                                                     ((void *)0) 
                                                          ? "" : state->msg);
}


void gzclearerr(file)
    gzFile file;
{
    gz_statep state;


    if (file == 
               ((void *)0)
                   )
        return;
    state = (gz_statep)file;
    if (state->mode != 7247 && state->mode != 31153)
        return;


    if (state->mode == 7247) {
        state->eof = 0;
        state->past = 0;
    }
    gz_error(state, 0, 
                         ((void *)0)
                             );
}







void __attribute__((visibility ("hidden"))) gz_error(state, err, msg)
    gz_statep state;
    int err;
    const char *msg;
{

    if (state->msg != 
                     ((void *)0)
                         ) {
        if (state->err != (-4))
            free(state->msg);
        state->msg = 
                    ((void *)0)
                        ;
    }


    if (err != 0 && err != (-5))
        state->x.have = 0;


    state->err = err;
    if (msg == 
              ((void *)0)
                  )
        return;


    if (err == (-4))
        return;


    if ((state->msg = (char *)malloc(strlen(state->path) + strlen(msg) + 3)) ==
            
           ((void *)0)
               ) {
        state->err = (-4);
        return;
    }

    (void)snprintf(state->msg, strlen(state->path) + strlen(msg) + 3,
                   "%s%s%s", state->path, ": ", msg);





}
