











































void platform_pre_listen(void);
void platform_pre_fork(void);
void platform_pre_restart(void);
void platform_post_fork_parent(pid_t child_pid);
void platform_post_fork_child(void);
int platform_privileged_uidswap(void);
void platform_setusercontext(struct passwd *);
void platform_setusercontext_post_groups(struct passwd *);
char *platform_get_krb5_client(const char *);
char *platform_krb5_get_principal_name(const char *);
int platform_locked_account(struct passwd *);
int platform_sys_dir_uid(uid_t);
void platform_disable_tracing(int);


void platform_pledge_agent(void);
void platform_pledge_sftp_server(void);
void platform_pledge_mux(void);









int b64_ntop(u_char const *src, size_t srclength, char *target,
    size_t targsize);






int b64_pton(char const *src, u_char *target, size_t targsize);
char * readpassphrase(const char *, char *, size_t, int);
char *vis(char *, int, int, int);
int strvis(char *, const char *, int);
int stravis(char **, const char *, int);
int strnvis(char *, const char *, size_t, int)
  __attribute__ (());
int strvisx(char *, const char *, size_t, int)
  __attribute__ (());
int strunvis(char *, const char *);
int unvis(char *, char, int *, int);
ssize_t strnunvis(char *, const char *, size_t)
  __attribute__ (());

struct rdatainfo {
 unsigned int rdi_length;
 unsigned char *rdi_data;
};

struct rrsetinfo {
 unsigned int rri_flags;
 unsigned int rri_rdclass;
 unsigned int rri_rdtype;
 unsigned int rri_ttl;
 unsigned int rri_nrdatas;
 unsigned int rri_nsigs;
 char *rri_name;
 struct rdatainfo *rri_rdatas;
 struct rdatainfo *rri_sigs;
};

int getrrsetbyname(const char *, unsigned int, unsigned int, unsigned int, struct rrsetinfo **);
void freerrset(struct rrsetinfo *);
typedef struct BlowfishContext {
 u_int32_t S[4][256];
 u_int32_t P[16 + 2];
} blf_ctx;







void Blowfish_encipher(blf_ctx *, u_int32_t *, u_int32_t *);
void Blowfish_decipher(blf_ctx *, u_int32_t *, u_int32_t *);
void Blowfish_initstate(blf_ctx *);
void Blowfish_expand0state(blf_ctx *, const u_int8_t *, u_int16_t);
void Blowfish_expandstate
(blf_ctx *, const u_int8_t *, u_int16_t, const u_int8_t *, u_int16_t);



void blf_key(blf_ctx *, const u_int8_t *, u_int16_t);
void blf_enc(blf_ctx *, u_int32_t *, u_int16_t);
void blf_dec(blf_ctx *, u_int32_t *, u_int16_t);

void blf_ecb_encrypt(blf_ctx *, u_int8_t *, u_int32_t);
void blf_ecb_decrypt(blf_ctx *, u_int8_t *, u_int32_t);

void blf_cbc_encrypt(blf_ctx *, u_int8_t *, u_int8_t *, u_int32_t);
void blf_cbc_decrypt(blf_ctx *, u_int8_t *, u_int8_t *, u_int32_t);


u_int32_t Blowfish_stream2word(const u_int8_t *, u_int16_t , u_int16_t *);
int bindresvport_sa(int sd, struct sockaddr *sa);
void *memmem(const void *, size_t, const void *, size_t);







void *recallocarray(void *, size_t, size_t, size_t);







size_t strlcpy(char *dst, const char *src, size_t siz);



size_t strlcat(char *dst, const char *src, size_t siz);
void strmode(int mode, char *p);
int fmt_scaled(long long number, char *result);



int scan_scaled(char *, long long *);
void setproctitle(const char *fmt, ...);
void compat_init_setproctitle(int argc, char *argv[]);







int BSDgetopt(int argc, char * const *argv, const char *opts);
struct option {

 const char *name;




 int has_arg;

 int *flag;

 int val;
};

int getopt_long(int, char * const *, const char *,
     const struct option *, int *);
int getopt_long_only(int, char * const *, const char *,
     const struct option *, int *);


int BSDgetopt(int, char * const *, const char *);
int getsubopt(char **, char * const *, char **);

extern char *BSDoptarg;
extern int BSDopterr;
extern int BSDoptind;
extern int BSDoptopt;
extern int BSDoptreset;
extern char *suboptarg;
char *ssh_get_progname(char *);
int seed_from_prngd(unsigned char *, size_t);
int setlogin(const char *);
int pledge(const char *promises, const char *paths[]);



int getpeereid(int , uid_t *, gid_t *);



uint32_t arc4random(void);



void arc4random_buf(void *, size_t);







uint32_t arc4random_uniform(uint32_t);
long long strtonum(const char *, long long, long long, const char **);
char *user_from_uid(uid_t, int);



char *group_from_gid(gid_t, int);



int timingsafe_bcmp(const void *, const void *, size_t);



int bcrypt_pbkdf(const char *, size_t, const uint8_t *, size_t,
    uint8_t *, size_t, unsigned int);







void freezero(void *, size_t);
char *xcrypt(const char *password, const char *salt);
char *shadow_pw(struct passwd *pw);





void oom_adjust_restore(void);
void oom_adjust_setup(void);
void solaris_contract_pre_fork(void);
void solaris_contract_post_fork_child(void);
void solaris_contract_post_fork_parent(pid_t pid);
void solaris_set_default_project(struct passwd *);
struct Channel;
struct ssh;



int sys_tun_open(int, int, char **);




int sys_tun_infilter(struct ssh *, struct Channel *, char *, int);
u_char *sys_tun_outfilter(struct ssh *, struct Channel *, u_char **, size_t *);






char *sys_get_rdomain(int fd);
int sys_set_rdomain(int fd, const char *name);
int sys_valid_rdomain(const char *name);
void kludge_FD_SET(int, fd_set *);
int kludge_FD_ISSET(int, fd_set *);

struct sshbuf;

void seed_rng(void);
void rexec_send_rng_seed(struct sshbuf *);
void rexec_recv_rng_seed(struct sshbuf *);









const char *ssh_err(int n);


struct sshbuf {
 u_char *d;
 const u_char *cd;
 size_t off;
 size_t size;
 size_t max_size;
 size_t alloc;
 int readonly;
 int dont_free;
 u_int refcount;
 struct sshbuf *parent;
};





struct sshbuf *sshbuf_new(void);





struct sshbuf *sshbuf_from(const void *blob, size_t len);







struct sshbuf *sshbuf_fromb(struct sshbuf *buf);
int sshbuf_froms(struct sshbuf *buf, struct sshbuf **bufp);




void sshbuf_free(struct sshbuf *buf);




void sshbuf_reset(struct sshbuf *buf);




size_t sshbuf_max_size(const struct sshbuf *buf);





int sshbuf_set_max_size(struct sshbuf *buf, size_t max_size);




size_t sshbuf_len(const struct sshbuf *buf);




size_t sshbuf_avail(const struct sshbuf *buf);




const u_char *sshbuf_ptr(const struct sshbuf *buf);





u_char *sshbuf_mutable_ptr(const struct sshbuf *buf);







int sshbuf_check_reserve(const struct sshbuf *buf, size_t len);







int sshbuf_allocate(struct sshbuf *buf, size_t len);






int sshbuf_reserve(struct sshbuf *buf, size_t len, u_char **dpp);





int sshbuf_consume(struct sshbuf *buf, size_t len);





int sshbuf_consume_end(struct sshbuf *buf, size_t len);


int sshbuf_get(struct sshbuf *buf, void *v, size_t len);
int sshbuf_put(struct sshbuf *buf, const void *v, size_t len);
int sshbuf_putb(struct sshbuf *buf, const struct sshbuf *v);


int sshbuf_putf(struct sshbuf *buf, const char *fmt, ...)
     __attribute__((format(printf, 2, 3)));
int sshbuf_putfv(struct sshbuf *buf, const char *fmt, va_list ap);


int sshbuf_get_u64(struct sshbuf *buf, u_int64_t *valp);
int sshbuf_get_u32(struct sshbuf *buf, u_int32_t *valp);
int sshbuf_get_u16(struct sshbuf *buf, u_int16_t *valp);
int sshbuf_get_u8(struct sshbuf *buf, u_char *valp);
int sshbuf_put_u64(struct sshbuf *buf, u_int64_t val);
int sshbuf_put_u32(struct sshbuf *buf, u_int32_t val);
int sshbuf_put_u16(struct sshbuf *buf, u_int16_t val);
int sshbuf_put_u8(struct sshbuf *buf, u_char val);


int sshbuf_peek_u64(const struct sshbuf *buf, size_t offset,
    u_int64_t *valp);
int sshbuf_peek_u32(const struct sshbuf *buf, size_t offset,
    u_int32_t *valp);
int sshbuf_peek_u16(const struct sshbuf *buf, size_t offset,
    u_int16_t *valp);
int sshbuf_peek_u8(const struct sshbuf *buf, size_t offset,
    u_char *valp);





int sshbuf_poke_u64(struct sshbuf *buf, size_t offset, u_int64_t val);
int sshbuf_poke_u32(struct sshbuf *buf, size_t offset, u_int32_t val);
int sshbuf_poke_u16(struct sshbuf *buf, size_t offset, u_int16_t val);
int sshbuf_poke_u8(struct sshbuf *buf, size_t offset, u_char val);
int sshbuf_poke(struct sshbuf *buf, size_t offset, void *v, size_t len);






int sshbuf_get_string(struct sshbuf *buf, u_char **valp, size_t *lenp);
int sshbuf_get_cstring(struct sshbuf *buf, char **valp, size_t *lenp);
int sshbuf_get_stringb(struct sshbuf *buf, struct sshbuf *v);
int sshbuf_put_string(struct sshbuf *buf, const void *v, size_t len);
int sshbuf_put_cstring(struct sshbuf *buf, const char *v);
int sshbuf_put_stringb(struct sshbuf *buf, const struct sshbuf *v);






int sshbuf_get_string_direct(struct sshbuf *buf, const u_char **valp,
     size_t *lenp);





int sshbuf_peek_string_direct(const struct sshbuf *buf, const u_char **valp,
     size_t *lenp);





int sshbuf_put_bignum2_bytes(struct sshbuf *buf, const void *v, size_t len);
int sshbuf_get_bignum2_bytes_direct(struct sshbuf *buf,
     const u_char **valp, size_t *lenp);

int sshbuf_get_bignum2(struct sshbuf *buf, BIGNUM **valp);
int sshbuf_put_bignum2(struct sshbuf *buf, const BIGNUM *v);

int sshbuf_get_ec(struct sshbuf *buf, EC_POINT *v, const EC_GROUP *g);
int sshbuf_get_eckey(struct sshbuf *buf, EC_KEY *v);
int sshbuf_put_ec(struct sshbuf *buf, const EC_POINT *v, const EC_GROUP *g);
int sshbuf_put_eckey(struct sshbuf *buf, const EC_KEY *v);




void sshbuf_dump(const struct sshbuf *buf, FILE *f);


void sshbuf_dump_data(const void *s, size_t len, FILE *f);


char *sshbuf_dtob16(struct sshbuf *buf);


char *sshbuf_dtob64_string(const struct sshbuf *buf, int wrap);
int sshbuf_dtob64(const struct sshbuf *d, struct sshbuf *b64, int wrap);

int sshbuf_dtourlb64(const struct sshbuf *d, struct sshbuf *b64, int wrap);


int sshbuf_b64tod(struct sshbuf *buf, const char *b64);
int sshbuf_cmp(const struct sshbuf *b, size_t offset,
    const void *s, size_t len);
int
sshbuf_find(const struct sshbuf *b, size_t start_offset,
    const void *s, size_t len, size_t *offsetp);






char *sshbuf_dup_string(struct sshbuf *buf);





int sshbuf_load_fd(int, struct sshbuf **)
    __attribute__((__nonnull__ (2)));
int sshbuf_load_file(const char *, struct sshbuf **)
    __attribute__((__nonnull__ (2)));





int sshbuf_write_file(const char *path, struct sshbuf *buf)
    __attribute__((__nonnull__ (2)));


int sshbuf_read(int, struct sshbuf *, size_t, size_t *)
    __attribute__((__nonnull__ (2)));
size_t sshbuf_alloc(const struct sshbuf *buf);




int sshbuf_set_parent(struct sshbuf *child, struct sshbuf *parent);




const struct sshbuf *sshbuf_parent(const struct sshbuf *buf);




u_int sshbuf_refcount(const struct sshbuf *buf);

int
sshbuf_get(struct sshbuf *buf, void *v, size_t len)
{
 const u_char *p = sshbuf_ptr(buf);
 int r;

 if ((r = sshbuf_consume(buf, len)) < 0)
  return r;
 if (v != 
         ((void *)0) 
              && len != 0)
  memcpy(v, p, len);
 return 0;
}

int
sshbuf_get_u64(struct sshbuf *buf, u_int64_t *valp)
{
 const u_char *p = sshbuf_ptr(buf);
 int r;

 if ((r = sshbuf_consume(buf, 8)) < 0)
  return r;
 if (valp != 
            ((void *)0)
                )
  *valp = (((u_int64_t)(((const u_char *)(p))[0]) << 56) | ((u_int64_t)(((const u_char *)(p))[1]) << 48) | ((u_int64_t)(((const u_char *)(p))[2]) << 40) | ((u_int64_t)(((const u_char *)(p))[3]) << 32) | ((u_int64_t)(((const u_char *)(p))[4]) << 24) | ((u_int64_t)(((const u_char *)(p))[5]) << 16) | ((u_int64_t)(((const u_char *)(p))[6]) << 8) | (u_int64_t)(((const u_char *)(p))[7]));
 return 0;
}

int
sshbuf_get_u32(struct sshbuf *buf, u_int32_t *valp)
{
 const u_char *p = sshbuf_ptr(buf);
 int r;

 if ((r = sshbuf_consume(buf, 4)) < 0)
  return r;
 if (valp != 
            ((void *)0)
                )
  *valp = (((u_int32_t)(((const u_char *)(p))[0]) << 24) | ((u_int32_t)(((const u_char *)(p))[1]) << 16) | ((u_int32_t)(((const u_char *)(p))[2]) << 8) | (u_int32_t)(((const u_char *)(p))[3]));
 return 0;
}

int
sshbuf_get_u16(struct sshbuf *buf, u_int16_t *valp)
{
 const u_char *p = sshbuf_ptr(buf);
 int r;

 if ((r = sshbuf_consume(buf, 2)) < 0)
  return r;
 if (valp != 
            ((void *)0)
                )
  *valp = (((u_int16_t)(((const u_char *)(p))[0]) << 8) | (u_int16_t)(((const u_char *)(p))[1]));
 return 0;
}

int
sshbuf_get_u8(struct sshbuf *buf, u_char *valp)
{
 const u_char *p = sshbuf_ptr(buf);
 int r;

 if ((r = sshbuf_consume(buf, 1)) < 0)
  return r;
 if (valp != 
            ((void *)0)
                )
  *valp = (u_int8_t)*p;
 return 0;
}

static int
check_offset(const struct sshbuf *buf, int wr, size_t offset, size_t len)
{
 if (sshbuf_ptr(buf) == 
                       ((void *)0)
                           )
  return -1;
 if (offset >= 
              (18446744073709551615UL) 
                       - len)
  return -10;
 if (offset + len > sshbuf_len(buf)) {
  return wr ?
      -9 : -3;
 }
 return 0;
}

static int
check_roffset(const struct sshbuf *buf, size_t offset, size_t len,
    const u_char **p)
{
 int r;

 *p = 
     ((void *)0)
         ;
 if ((r = check_offset(buf, 0, offset, len)) != 0)
  return r;
 *p = sshbuf_ptr(buf) + offset;
 return 0;
}

int
sshbuf_peek_u64(const struct sshbuf *buf, size_t offset, u_int64_t *valp)
{
 const u_char *p = 
                  ((void *)0)
                      ;
 int r;

 if (valp != 
            ((void *)0)
                )
  *valp = 0;
 if ((r = check_roffset(buf, offset, 8, &p)) != 0)
  return r;
 if (valp != 
            ((void *)0)
                )
  *valp = (((u_int64_t)(((const u_char *)(p))[0]) << 56) | ((u_int64_t)(((const u_char *)(p))[1]) << 48) | ((u_int64_t)(((const u_char *)(p))[2]) << 40) | ((u_int64_t)(((const u_char *)(p))[3]) << 32) | ((u_int64_t)(((const u_char *)(p))[4]) << 24) | ((u_int64_t)(((const u_char *)(p))[5]) << 16) | ((u_int64_t)(((const u_char *)(p))[6]) << 8) | (u_int64_t)(((const u_char *)(p))[7]));
 return 0;
}

int
sshbuf_peek_u32(const struct sshbuf *buf, size_t offset, u_int32_t *valp)
{
 const u_char *p = 
                  ((void *)0)
                      ;
 int r;

 if (valp != 
            ((void *)0)
                )
  *valp = 0;
 if ((r = check_roffset(buf, offset, 4, &p)) != 0)
  return r;
 if (valp != 
            ((void *)0)
                )
  *valp = (((u_int32_t)(((const u_char *)(p))[0]) << 24) | ((u_int32_t)(((const u_char *)(p))[1]) << 16) | ((u_int32_t)(((const u_char *)(p))[2]) << 8) | (u_int32_t)(((const u_char *)(p))[3]));
 return 0;
}

int
sshbuf_peek_u16(const struct sshbuf *buf, size_t offset, u_int16_t *valp)
{
 const u_char *p = 
                  ((void *)0)
                      ;
 int r;

 if (valp != 
            ((void *)0)
                )
  *valp = 0;
 if ((r = check_roffset(buf, offset, 2, &p)) != 0)
  return r;
 if (valp != 
            ((void *)0)
                )
  *valp = (((u_int16_t)(((const u_char *)(p))[0]) << 8) | (u_int16_t)(((const u_char *)(p))[1]));
 return 0;
}

int
sshbuf_peek_u8(const struct sshbuf *buf, size_t offset, u_char *valp)
{
 const u_char *p = 
                  ((void *)0)
                      ;
 int r;

 if (valp != 
            ((void *)0)
                )
  *valp = 0;
 if ((r = check_roffset(buf, offset, 1, &p)) != 0)
  return r;
 if (valp != 
            ((void *)0)
                )
  *valp = *p;
 return 0;
}

int
sshbuf_get_string(struct sshbuf *buf, u_char **valp, size_t *lenp)
{
 const u_char *val;
 size_t len;
 int r;

 if (valp != 
            ((void *)0)
                )
  *valp = 
         ((void *)0)
             ;
 if (lenp != 
            ((void *)0)
                )
  *lenp = 0;
 if ((r = sshbuf_get_string_direct(buf, &val, &len)) < 0)
  return r;
 if (valp != 
            ((void *)0)
                ) {
  if ((*valp = malloc(len + 1)) == 
                                  ((void *)0)
                                      ) {
   ;
   return -2;
  }
  if (len != 0)
   memcpy(*valp, val, len);
  (*valp)[len] = '\0';
 }
 if (lenp != 
            ((void *)0)
                )
  *lenp = len;
 return 0;
}

int
sshbuf_get_string_direct(struct sshbuf *buf, const u_char **valp, size_t *lenp)
{
 size_t len;
 const u_char *p;
 int r;

 if (valp != 
            ((void *)0)
                )
  *valp = 
         ((void *)0)
             ;
 if (lenp != 
            ((void *)0)
                )
  *lenp = 0;
 if ((r = sshbuf_peek_string_direct(buf, &p, &len)) < 0)
  return r;
 if (valp != 
            ((void *)0)
                )
  *valp = p;
 if (lenp != 
            ((void *)0)
                )
  *lenp = len;
 if (sshbuf_consume(buf, len + 4) != 0) {

  ;
  ;
  return -1;
 }
 return 0;
}

int
sshbuf_peek_string_direct(const struct sshbuf *buf, const u_char **valp,
    size_t *lenp)
{
 u_int32_t len;
 const u_char *p = sshbuf_ptr(buf);

 if (valp != 
            ((void *)0)
                )
  *valp = 
         ((void *)0)
             ;
 if (lenp != 
            ((void *)0)
                )
  *lenp = 0;
 if (sshbuf_len(buf) < 4) {
  ;
  return -3;
 }
 len = (((u_int32_t)(((const u_char *)(p))[0]) << 24) | ((u_int32_t)(((const u_char *)(p))[1]) << 16) | ((u_int32_t)(((const u_char *)(p))[2]) << 8) | (u_int32_t)(((const u_char *)(p))[3]));
 if (len > 0x8000000 - 4) {
  ;
  return -6;
 }
 if (sshbuf_len(buf) - 4 < len) {
  ;
  return -3;
 }
 if (valp != 
            ((void *)0)
                )
  *valp = p + 4;
 if (lenp != 
            ((void *)0)
                )
  *lenp = len;
 return 0;
}

int
sshbuf_get_cstring(struct sshbuf *buf, char **valp, size_t *lenp)
{
 size_t len;
 const u_char *p, *z;
 int r;

 if (valp != 
            ((void *)0)
                )
  *valp = 
         ((void *)0)
             ;
 if (lenp != 
            ((void *)0)
                )
  *lenp = 0;
 if ((r = sshbuf_peek_string_direct(buf, &p, &len)) != 0)
  return r;

 if (len > 0 &&
     (z = memchr(p , '\0', len)) != 
                                   ((void *)0) 
                                        && z < p + len - 1) {
  ;
  return -4;
 }
 if ((r = sshbuf_get_string_direct(buf, 
         ((void *)0)
         , 
         ((void *)0)
         )) != 0)
  return -1;
 if (valp != 
            ((void *)0)
                ) {
  if ((*valp = malloc(len + 1)) == 
                                  ((void *)0)
                                      ) {
   ;
   return -2;
  }
  if (len != 0)
   memcpy(*valp, p, len);
  (*valp)[len] = '\0';
 }
 if (lenp != 
            ((void *)0)
                )
  *lenp = (size_t)len;
 return 0;
}

int
sshbuf_get_stringb(struct sshbuf *buf, struct sshbuf *v)
{
 u_int32_t len;
 u_char *p;
 int r;






 if ((r = sshbuf_peek_string_direct(buf, 
                                        ((void *)0)
                                            , 
                                              ((void *)0)
                                                  )) != 0 ||
     (r = sshbuf_get_u32(buf, &len)) != 0 ||
     (r = sshbuf_reserve(v, len, &p)) != 0 ||
     (r = sshbuf_get(buf, p, len)) != 0)
  return r;
 return 0;
}

int
sshbuf_put(struct sshbuf *buf, const void *v, size_t len)
{
 u_char *p;
 int r;

 if ((r = sshbuf_reserve(buf, len, &p)) < 0)
  return r;
 if (len != 0)
  memcpy(p, v, len);
 return 0;
}

int
sshbuf_putb(struct sshbuf *buf, const struct sshbuf *v)
{
 if (v == 
         ((void *)0)
             )
  return 0;
 return sshbuf_put(buf, sshbuf_ptr(v), sshbuf_len(v));
}

int
sshbuf_putf(struct sshbuf *buf, const char *fmt, ...)
{
 va_list ap;
 int r;

 
__builtin_va_start(
ap
,
fmt
)
                 ;
 r = sshbuf_putfv(buf, fmt, ap);
 
__builtin_va_end(
ap
)
          ;
 return r;
}

int
sshbuf_putfv(struct sshbuf *buf, const char *fmt, va_list ap)
{
 va_list ap2;
 int r, len;
 u_char *p;

 
__builtin_va_copy(
ap2
,
ap
)
                ;
 if ((len = vsnprintf(
                     ((void *)0)
                         , 0, fmt, ap2)) < 0) {
  r = -10;
  goto out;
 }
 if (len == 0) {
  r = 0;
  goto out;
 }
 
__builtin_va_end(
ap2
)
           ;
 
__builtin_va_copy(
ap2
,
ap
)
                ;
 if ((r = sshbuf_reserve(buf, (size_t)len + 1, &p)) < 0)
  goto out;
 if ((r = vsnprintf((char *)p, len + 1, fmt, ap2)) != len) {
  r = -1;
  goto out;
 }

 if ((r = sshbuf_consume_end(buf, 1)) != 0)
  goto out;
 r = 0;
 out:
 
__builtin_va_end(
ap2
)
           ;
 return r;
}

int
sshbuf_put_u64(struct sshbuf *buf, u_int64_t val)
{
 u_char *p;
 int r;

 if ((r = sshbuf_reserve(buf, 8, &p)) < 0)
  return r;
 do { const u_int64_t __v = (val); ((u_char *)(p))[0] = (__v >> 56) & 0xff; ((u_char *)(p))[1] = (__v >> 48) & 0xff; ((u_char *)(p))[2] = (__v >> 40) & 0xff; ((u_char *)(p))[3] = (__v >> 32) & 0xff; ((u_char *)(p))[4] = (__v >> 24) & 0xff; ((u_char *)(p))[5] = (__v >> 16) & 0xff; ((u_char *)(p))[6] = (__v >> 8) & 0xff; ((u_char *)(p))[7] = __v & 0xff; } while (0);
 return 0;
}

int
sshbuf_put_u32(struct sshbuf *buf, u_int32_t val)
{
 u_char *p;
 int r;

 if ((r = sshbuf_reserve(buf, 4, &p)) < 0)
  return r;
 do { const u_int32_t __v = (val); ((u_char *)(p))[0] = (__v >> 24) & 0xff; ((u_char *)(p))[1] = (__v >> 16) & 0xff; ((u_char *)(p))[2] = (__v >> 8) & 0xff; ((u_char *)(p))[3] = __v & 0xff; } while (0);
 return 0;
}

int
sshbuf_put_u16(struct sshbuf *buf, u_int16_t val)
{
 u_char *p;
 int r;

 if ((r = sshbuf_reserve(buf, 2, &p)) < 0)
  return r;
 do { const u_int16_t __v = (val); ((u_char *)(p))[0] = (__v >> 8) & 0xff; ((u_char *)(p))[1] = __v & 0xff; } while (0);
 return 0;
}

int
sshbuf_put_u8(struct sshbuf *buf, u_char val)
{
 u_char *p;
 int r;

 if ((r = sshbuf_reserve(buf, 1, &p)) < 0)
  return r;
 p[0] = val;
 return 0;
}

static int
check_woffset(struct sshbuf *buf, size_t offset, size_t len, u_char **p)
{
 int r;

 *p = 
     ((void *)0)
         ;
 if ((r = check_offset(buf, 1, offset, len)) != 0)
  return r;
 if (sshbuf_mutable_ptr(buf) == 
                               ((void *)0)
                                   )
  return -49;
 *p = sshbuf_mutable_ptr(buf) + offset;
 return 0;
}

int
sshbuf_poke_u64(struct sshbuf *buf, size_t offset, u_int64_t val)
{
 u_char *p = 
            ((void *)0)
                ;
 int r;

 if ((r = check_woffset(buf, offset, 8, &p)) != 0)
  return r;
 do { const u_int64_t __v = (val); ((u_char *)(p))[0] = (__v >> 56) & 0xff; ((u_char *)(p))[1] = (__v >> 48) & 0xff; ((u_char *)(p))[2] = (__v >> 40) & 0xff; ((u_char *)(p))[3] = (__v >> 32) & 0xff; ((u_char *)(p))[4] = (__v >> 24) & 0xff; ((u_char *)(p))[5] = (__v >> 16) & 0xff; ((u_char *)(p))[6] = (__v >> 8) & 0xff; ((u_char *)(p))[7] = __v & 0xff; } while (0);
 return 0;
}

int
sshbuf_poke_u32(struct sshbuf *buf, size_t offset, u_int32_t val)
{
 u_char *p = 
            ((void *)0)
                ;
 int r;

 if ((r = check_woffset(buf, offset, 4, &p)) != 0)
  return r;
 do { const u_int32_t __v = (val); ((u_char *)(p))[0] = (__v >> 24) & 0xff; ((u_char *)(p))[1] = (__v >> 16) & 0xff; ((u_char *)(p))[2] = (__v >> 8) & 0xff; ((u_char *)(p))[3] = __v & 0xff; } while (0);
 return 0;
}

int
sshbuf_poke_u16(struct sshbuf *buf, size_t offset, u_int16_t val)
{
 u_char *p = 
            ((void *)0)
                ;
 int r;

 if ((r = check_woffset(buf, offset, 2, &p)) != 0)
  return r;
 do { const u_int16_t __v = (val); ((u_char *)(p))[0] = (__v >> 8) & 0xff; ((u_char *)(p))[1] = __v & 0xff; } while (0);
 return 0;
}

int
sshbuf_poke_u8(struct sshbuf *buf, size_t offset, u_char val)
{
 u_char *p = 
            ((void *)0)
                ;
 int r;

 if ((r = check_woffset(buf, offset, 1, &p)) != 0)
  return r;
 *p = val;
 return 0;
}

int
sshbuf_poke(struct sshbuf *buf, size_t offset, void *v, size_t len)
{
 u_char *p = 
            ((void *)0)
                ;
 int r;

 if ((r = check_woffset(buf, offset, len, &p)) != 0)
  return r;
 memcpy(p, v, len);
 return 0;
}

int
sshbuf_put_string(struct sshbuf *buf, const void *v, size_t len)
{
 u_char *d;
 int r;

 if (len > 0x8000000 - 4) {
  ;
  return -9;
 }
 if ((r = sshbuf_reserve(buf, len + 4, &d)) < 0)
  return r;
 do { const u_int32_t __v = (len); ((u_char *)(d))[0] = (__v >> 24) & 0xff; ((u_char *)(d))[1] = (__v >> 16) & 0xff; ((u_char *)(d))[2] = (__v >> 8) & 0xff; ((u_char *)(d))[3] = __v & 0xff; } while (0);
 if (len != 0)
  memcpy(d + 4, v, len);
 return 0;
}

int
sshbuf_put_cstring(struct sshbuf *buf, const char *v)
{
 return sshbuf_put_string(buf, v, v == 
                                      ((void *)0) 
                                           ? 0 : strlen(v));
}

int
sshbuf_put_stringb(struct sshbuf *buf, const struct sshbuf *v)
{
 if (v == 
         ((void *)0)
             )
  return sshbuf_put_string(buf, 
                               ((void *)0)
                                   , 0);

 return sshbuf_put_string(buf, sshbuf_ptr(v), sshbuf_len(v));
}

int
sshbuf_froms(struct sshbuf *buf, struct sshbuf **bufp)
{
 const u_char *p;
 size_t len;
 struct sshbuf *ret;
 int r;

 if (buf == 
           ((void *)0) 
                || bufp == 
                           ((void *)0)
                               )
  return -10;
 *bufp = 
        ((void *)0)
            ;
 if ((r = sshbuf_peek_string_direct(buf, &p, &len)) != 0)
  return r;
 if ((ret = sshbuf_from(p, len)) == 
                                   ((void *)0)
                                       )
  return -2;
 if ((r = sshbuf_consume(buf, len + 4)) != 0 ||
     (r = sshbuf_set_parent(ret, buf)) != 0) {
  sshbuf_free(ret);
  return r;
 }
 *bufp = ret;
 return 0;
}

int
sshbuf_put_bignum2_bytes(struct sshbuf *buf, const void *v, size_t len)
{
 u_char *d;
 const u_char *s = (const u_char *)v;
 int r, prepend;

 if (len > 0x8000000 - 5) {
  ;
  return -9;
 }

 for (; len > 0 && *s == 0; len--, s++)
  ;




 prepend = len > 0 && (s[0] & 0x80) != 0;
 if ((r = sshbuf_reserve(buf, len + 4 + prepend, &d)) < 0)
  return r;
 do { const u_int32_t __v = (len + prepend); ((u_char *)(d))[0] = (__v >> 24) & 0xff; ((u_char *)(d))[1] = (__v >> 16) & 0xff; ((u_char *)(d))[2] = (__v >> 8) & 0xff; ((u_char *)(d))[3] = __v & 0xff; } while (0);
 if (prepend)
  d[4] = 0;
 if (len != 0)
  memcpy(d + 4 + prepend, s, len);
 return 0;
}

int
sshbuf_get_bignum2_bytes_direct(struct sshbuf *buf,
    const u_char **valp, size_t *lenp)
{
 const u_char *d;
 size_t len, olen;
 int r;

 if ((r = sshbuf_peek_string_direct(buf, &d, &olen)) < 0)
  return r;
 len = olen;

 if ((len != 0 && (*d & 0x80) != 0))
  return -5;

 if (len > (16384 / 8) + 1 ||
     (len == (16384 / 8) + 1 && *d != 0))
  return -7;

 while (len > 0 && *d == 0x00) {
  d++;
  len--;
 }
 if (valp != 
            ((void *)0)
                )
  *valp = d;
 if (lenp != 
            ((void *)0)
                )
  *lenp = len;
 if (sshbuf_consume(buf, olen + 4) != 0) {

  ;
  ;
  return -1;
 }
 return 0;
}
