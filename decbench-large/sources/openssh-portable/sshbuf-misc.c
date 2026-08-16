











































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

void
sshbuf_dump_data(const void *s, size_t len, FILE *f)
{
 size_t i, j;
 const u_char *p = (const u_char *)s;

 for (i = 0; i < len; i += 16) {
  fprintf(f, "%.4zu: ", i);
  for (j = i; j < i + 16; j++) {
   if (j < len)
    fprintf(f, "%02x ", p[j]);
   else
    fprintf(f, "   ");
  }
  fprintf(f, " ");
  for (j = i; j < i + 16; j++) {
   if (j < len) {
    if (
        (((
        p[j]
        ) & ~0x7f) == 0) 
                      && 
                         ((*__ctype_b_loc ())[(int) ((
                         p[j]
                         ))] & (unsigned short int) _ISprint)
                                      )
     fprintf(f, "%c", p[j]);
    else
     fprintf(f, ".");
   }
  }
  fprintf(f, "\n");
 }
}

void
sshbuf_dump(const struct sshbuf *buf, FILE *f)
{
 fprintf(f, "buffer len = %zu\n", sshbuf_len(buf));
 sshbuf_dump_data(sshbuf_ptr(buf), sshbuf_len(buf), f);
}

char *
sshbuf_dtob16(struct sshbuf *buf)
{
 size_t i, j, len = sshbuf_len(buf);
 const u_char *p = sshbuf_ptr(buf);
 char *ret;
 const char hex[] = "0123456789abcdef";

 if (len == 0)
  return strdup("");
 if (
    (18446744073709551615UL) 
             / 2 <= len || (ret = malloc(len * 2 + 1)) == 
                                                          ((void *)0)
                                                              )
  return 
        ((void *)0)
            ;
 for (i = j = 0; i < len; i++) {
  ret[j++] = hex[(p[i] >> 4) & 0xf];
  ret[j++] = hex[p[i] & 0xf];
 }
 ret[j] = '\0';
 return ret;
}

int
sshbuf_dtob64(const struct sshbuf *d, struct sshbuf *b64, int wrap)
{
 size_t i, slen = 0;
 char *s = 
          ((void *)0)
              ;
 int r;

 if (d == 
         ((void *)0) 
              || b64 == 
                        ((void *)0) 
                             || sshbuf_len(d) >= 
                                                 (18446744073709551615UL) 
                                                          / 2)
  return -10;
 if (sshbuf_len(d) == 0)
  return 0;
 slen = ((sshbuf_len(d) + 2) / 3) * 4 + 1;
 if ((s = malloc(slen)) == 
                          ((void *)0)
                              )
  return -2;
 if (
    __b64_ntop
    (sshbuf_ptr(d),sshbuf_len(d),s,slen) == -1) {
  r = -1;
  goto fail;
 }
 if (wrap) {
  for (i = 0; s[i] != '\0'; i++) {
   if ((r = sshbuf_put_u8(b64, s[i])) != 0)
    goto fail;
   if (i % 70 == 69 && (r = sshbuf_put_u8(b64, '\n')) != 0)
    goto fail;
  }
  if ((i - 1) % 70 != 69 && (r = sshbuf_put_u8(b64, '\n')) != 0)
   goto fail;
 } else {
  if ((r = sshbuf_put(b64, s, strlen(s))) != 0)
   goto fail;
 }

 r = 0;
 fail:
 freezero(s, slen);
 return r;
}

char *
sshbuf_dtob64_string(const struct sshbuf *buf, int wrap)
{
 struct sshbuf *tmp;
 char *ret;

 if ((tmp = sshbuf_new()) == 
                            ((void *)0)
                                )
  return 
        ((void *)0)
            ;
 if (sshbuf_dtob64(buf, tmp, wrap) != 0) {
  sshbuf_free(tmp);
  return 
        ((void *)0)
            ;
 }
 ret = sshbuf_dup_string(tmp);
 sshbuf_free(tmp);
 return ret;
}

int
sshbuf_b64tod(struct sshbuf *buf, const char *b64)
{
 size_t plen = strlen(b64);
 int nlen, r;
 u_char *p;

 if (plen == 0)
  return 0;
 if ((p = malloc(plen)) == 
                          ((void *)0)
                              )
  return -2;
 if ((nlen = 
            __b64_pton
            (b64,p,plen)) < 0) {
  freezero(p, plen);
  return -4;
 }
 if ((r = sshbuf_put(buf, p, nlen)) < 0) {
  freezero(p, plen);
  return r;
 }
 freezero(p, plen);
 return 0;
}

int
sshbuf_dtourlb64(const struct sshbuf *d, struct sshbuf *b64, int wrap)
{
 int r = -1;
 u_char *p;
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 size_t i, l;

 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              )
  return -2;

 if ((r = sshbuf_dtob64(d, b, wrap)) != 0)
  goto out;

 for (;;) {
  l = sshbuf_len(b);
  if (l <= 1 || sshbuf_ptr(b) == 
                                ((void *)0)
                                    ) {
   r = -1;
   goto out;
  }
  if (sshbuf_ptr(b)[l - 1] != '=')
   break;
  if ((r = sshbuf_consume_end(b, 1)) != 0)
   goto out;
 }

 l = sshbuf_len(b);
 if ((p = sshbuf_mutable_ptr(b)) == 
                                   ((void *)0)
                                       ) {
  r = -1;
  goto out;
 }
 for (i = 0; i < l; i++) {
  if (p[i] == '+')
   p[i] = '-';
  else if (p[i] == '/')
   p[i] = '_';
 }
 r = sshbuf_putb(b64, b);
 out:
 sshbuf_free(b);
 return r;
}

char *
sshbuf_dup_string(struct sshbuf *buf)
{
 const u_char *p = 
                  ((void *)0)
                      , *s = sshbuf_ptr(buf);
 size_t l = sshbuf_len(buf);
 char *r;

 if (s == 
         ((void *)0) 
              || l > 
                     (18446744073709551615UL)
                             )
  return 
        ((void *)0)
            ;

 if (l > 0 && (p = memchr(s, '\0', l)) != 
                                         ((void *)0)
                                             ) {
  if (p != s + l - 1)
   return 
         ((void *)0)
             ;
  l--;
 }
 if ((r = malloc(l + 1)) == 
                           ((void *)0)
                               )
  return 
        ((void *)0)
            ;
 if (l > 0)
  memcpy(r, s, l);
 r[l] = '\0';
 return r;
}

int
sshbuf_cmp(const struct sshbuf *b, size_t offset,
    const void *s, size_t len)
{
 if (sshbuf_ptr(b) == 
                     ((void *)0)
                         )
  return -1;
 if (offset > 0x8000000 || len > 0x8000000 || len == 0)
  return -10;
 if (offset + len > sshbuf_len(b))
  return -3;
 if (timingsafe_bcmp(sshbuf_ptr(b) + offset, s, len) != 0)
  return -4;
 return 0;
}

int
sshbuf_find(const struct sshbuf *b, size_t start_offset,
    const void *s, size_t len, size_t *offsetp)
{
 void *p;

 if (offsetp != 
               ((void *)0)
                   )
  *offsetp = 0;
 if (sshbuf_ptr(b) == 
                     ((void *)0)
                         )
  return -1;
 if (start_offset > 0x8000000 || len > 0x8000000 || len == 0)
  return -10;
 if (start_offset > sshbuf_len(b) || start_offset + len > sshbuf_len(b))
  return -3;
 if ((p = memmem(sshbuf_ptr(b) + start_offset,
     sshbuf_len(b) - start_offset, s, len)) == 
                                              ((void *)0)
                                                  )
  return -4;
 if (offsetp != 
               ((void *)0)
                   )
  *offsetp = (const u_char *)p - sshbuf_ptr(b);
 return 0;
}

int
sshbuf_read(int fd, struct sshbuf *buf, size_t maxlen, size_t *rlen)
{
 int r, oerrno;
 size_t adjust;
 ssize_t rr;
 u_char *d;

 if (rlen != 
            ((void *)0)
                )
  *rlen = 0;
 if ((r = sshbuf_reserve(buf, maxlen, &d)) != 0)
  return r;
 rr = read(fd, d, maxlen);
 oerrno = 
         (*__errno_location ())
              ;


 if ((adjust = maxlen - (rr > 0 ? rr : 0)) != 0) {
  if ((r = sshbuf_consume_end(buf, adjust)) != 0) {

   memset(d + rr, '\0', adjust);
   return -1;
  }
 }
 if (rr < 0) {
  
 (*__errno_location ()) 
       = oerrno;
  return -24;
 } else if (rr == 0) {
  
 (*__errno_location ()) 
       = 
         32
              ;
  return -24;
 }

 if (rlen != 
            ((void *)0)
                )
  *rlen = (size_t)rr;
 return 0;
}
