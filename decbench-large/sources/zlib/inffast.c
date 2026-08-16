




     
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
typedef enum {
    HEAD = 16180,
    FLAGS,
    TIME,
    OS,
    EXLEN,
    EXTRA,
    NAME,
    COMMENT,
    HCRC,
    DICTID,
    DICT,
        TYPE,
        TYPEDO,
        STORED,
        COPY_,
        COPY,
        TABLE,
        LENLENS,
        CODELENS,
            LEN_,
            LEN,
            LENEXT,
            DIST,
            DISTEXT,
            MATCH,
            LIT,
    CHECK,
    LENGTH,
    DONE,
    BAD,
    MEM,
    SYNC
} inflate_mode;
struct inflate_state {
    z_streamp strm;
    inflate_mode mode;
    int last;
    int wrap;

    int havedict;
    int flags;

    unsigned dmax;
    unsigned long check;
    unsigned long total;
    gz_headerp head;

    unsigned wbits;
    unsigned wsize;
    unsigned whave;
    unsigned wnext;
    unsigned char *window;

    unsigned long hold;
    unsigned bits;

    unsigned length;
    unsigned offset;

    unsigned extra;

    code const *lencode;
    code const *distcode;
    unsigned lenbits;
    unsigned distbits;

    unsigned ncode;
    unsigned nlen;
    unsigned ndist;
    unsigned have;
    code *next;
    unsigned short lens[320];
    unsigned short work[288];
    code codes[(852 +592)];
    int sane;
    int back;
    unsigned was;
};
void __attribute__((visibility ("hidden"))) inflate_fast (z_streamp strm, unsigned start);
void __attribute__((visibility ("hidden"))) inflate_fast(strm, start)
z_streamp strm;
unsigned start;
{
    struct inflate_state *state;
    unsigned char *in;
    unsigned char *last;
    unsigned char *out;
    unsigned char *beg;
    unsigned char *end;



    unsigned wsize;
    unsigned whave;
    unsigned wnext;
    unsigned char *window;
    unsigned long hold;
    unsigned bits;
    code const *lcode;
    code const *dcode;
    unsigned lmask;
    unsigned dmask;
    code const *here;
    unsigned op;

    unsigned len;
    unsigned dist;
    unsigned char *from;


    state = (struct inflate_state *)strm->state;
    in = strm->next_in;
    last = in + (strm->avail_in - 5);
    out = strm->next_out;
    beg = out - (start - strm->avail_out);
    end = out + (strm->avail_out - 257);



    wsize = state->wsize;
    whave = state->whave;
    wnext = state->wnext;
    window = state->window;
    hold = state->hold;
    bits = state->bits;
    lcode = state->lencode;
    dcode = state->distcode;
    lmask = (1U << state->lenbits) - 1;
    dmask = (1U << state->distbits) - 1;



    do {
        if (bits < 15) {
            hold += (unsigned long)(*in++) << bits;
            bits += 8;
            hold += (unsigned long)(*in++) << bits;
            bits += 8;
        }
        here = lcode + (hold & lmask);
      dolen:
        op = (unsigned)(here->bits);
        hold >>= op;
        bits -= op;
        op = (unsigned)(here->op);
        if (op == 0) {
           

                                                                    ;
            *out++ = (unsigned char)(here->val);
        }
        else if (op & 16) {
            len = (unsigned)(here->val);
            op &= 15;
            if (op) {
                if (bits < op) {
                    hold += (unsigned long)(*in++) << bits;
                    bits += 8;
                }
                len += (unsigned)hold & ((1U << op) - 1);
                hold >>= op;
                bits -= op;
            }
            ;
            if (bits < 15) {
                hold += (unsigned long)(*in++) << bits;
                bits += 8;
                hold += (unsigned long)(*in++) << bits;
                bits += 8;
            }
            here = dcode + (hold & dmask);
          dodist:
            op = (unsigned)(here->bits);
            hold >>= op;
            bits -= op;
            op = (unsigned)(here->op);
            if (op & 16) {
                dist = (unsigned)(here->val);
                op &= 15;
                if (bits < op) {
                    hold += (unsigned long)(*in++) << bits;
                    bits += 8;
                    if (bits < op) {
                        hold += (unsigned long)(*in++) << bits;
                        bits += 8;
                    }
                }
                dist += (unsigned)hold & ((1U << op) - 1);







                hold >>= op;
                bits -= op;
                ;
                op = (unsigned)(out - beg);
                if (dist > op) {
                    op = dist - op;
                    if (op > whave) {
                        if (state->sane) {
                            strm->msg =
                                (char *)"invalid distance too far back";
                            state->mode = BAD;
                            break;
                        }
                    }
                    from = window;
                    if (wnext == 0) {
                        from += wsize - op;
                        if (op < len) {
                            len -= op;
                            do {
                                *out++ = *from++;
                            } while (--op);
                            from = out - dist;
                        }
                    }
                    else if (wnext < op) {
                        from += wsize + wnext - op;
                        op -= wnext;
                        if (op < len) {
                            len -= op;
                            do {
                                *out++ = *from++;
                            } while (--op);
                            from = window;
                            if (wnext < len) {
                                op = wnext;
                                len -= op;
                                do {
                                    *out++ = *from++;
                                } while (--op);
                                from = out - dist;
                            }
                        }
                    }
                    else {
                        from += wnext - op;
                        if (op < len) {
                            len -= op;
                            do {
                                *out++ = *from++;
                            } while (--op);
                            from = out - dist;
                        }
                    }
                    while (len > 2) {
                        *out++ = *from++;
                        *out++ = *from++;
                        *out++ = *from++;
                        len -= 3;
                    }
                    if (len) {
                        *out++ = *from++;
                        if (len > 1)
                            *out++ = *from++;
                    }
                }
                else {
                    from = out - dist;
                    do {
                        *out++ = *from++;
                        *out++ = *from++;
                        *out++ = *from++;
                        len -= 3;
                    } while (len > 2);
                    if (len) {
                        *out++ = *from++;
                        if (len > 1)
                            *out++ = *from++;
                    }
                }
            }
            else if ((op & 64) == 0) {
                here = dcode + here->val + (hold & ((1U << op) - 1));
                goto dodist;
            }
            else {
                strm->msg = (char *)"invalid distance code";
                state->mode = BAD;
                break;
            }
        }
        else if ((op & 64) == 0) {
            here = lcode + here->val + (hold & ((1U << op) - 1));
            goto dolen;
        }
        else if (op & 32) {
            ;
            state->mode = TYPE;
            break;
        }
        else {
            strm->msg = (char *)"invalid literal/length code";
            state->mode = BAD;
            break;
        }
    } while (in < last && out < end);


    len = bits >> 3;
    in -= len;
    bits -= len << 3;
    hold &= (1U << bits) - 1;


    strm->next_in = in;
    strm->next_out = out;
    strm->avail_in = (unsigned)(in < last ? 5 + (last - in) : 5 - (in - last));
    strm->avail_out = (unsigned)(out < end ?
                                 257 + (end - out) : 257 - (out - end));
    state->hold = hold;
    state->bits = bits;
    return;
}
