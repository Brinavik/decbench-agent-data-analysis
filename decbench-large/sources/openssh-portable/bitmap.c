











































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




struct bitmap;


struct bitmap *bitmap_new(void);


void bitmap_free(struct bitmap *b);


void bitmap_zero(struct bitmap *b);


int bitmap_test_bit(struct bitmap *b, u_int n);


int bitmap_set_bit(struct bitmap *b, u_int n);


void bitmap_clear_bit(struct bitmap *b, u_int n);


size_t bitmap_nbits(struct bitmap *b);


size_t bitmap_nbytes(struct bitmap *b);


int bitmap_to_string(struct bitmap *b, void *p, size_t l);


int bitmap_from_string(struct bitmap *b, const void *p, size_t l);






struct bitmap {
 u_int *d;
 size_t len;
 size_t top;
};

struct bitmap *
bitmap_new(void)
{
 struct bitmap *ret;

 if ((ret = calloc(1, sizeof(*ret))) == 
                                       ((void *)0)
                                           )
  return 
        ((void *)0)
            ;
 if ((ret->d = calloc(1, (sizeof(u_int)))) == 
                                          ((void *)0)
                                              ) {
  free(ret);
  return 
        ((void *)0)
            ;
 }
 ret->len = 1;
 ret->top = 0;
 return ret;
}

void
bitmap_free(struct bitmap *b)
{
 if (b != 
         ((void *)0) 
              && b->d != 
                         ((void *)0)
                             ) {
  bitmap_zero(b);
  free(b->d);
  b->d = 
        ((void *)0)
            ;
 }
 free(b);
}

void
bitmap_zero(struct bitmap *b)
{
 memset(b->d, 0, b->len * (sizeof(u_int)));
 b->top = 0;
}

int
bitmap_test_bit(struct bitmap *b, u_int n)
{
 if (b->top >= b->len)
  return 0;
 if (b->len == 0 || (n / (sizeof(u_int) * 8)) > b->top)
  return 0;
 return (b->d[n / (sizeof(u_int) * 8)] >> (n & ((u_int)(sizeof(u_int) * 8) - 1))) & 1;
}

static int
reserve(struct bitmap *b, u_int n)
{
 u_int *tmp;
 size_t nlen;

 if (b->top >= b->len || n > (1<<24))
  return -1;
 nlen = (n / (sizeof(u_int) * 8)) + 1;
 if (b->len < nlen) {
  if ((tmp = recallocarray(b->d, b->len,
      nlen, (sizeof(u_int)))) == 
                             ((void *)0)
                                 )
   return -1;
  b->d = tmp;
  b->len = nlen;
 }
 return 0;
}

int
bitmap_set_bit(struct bitmap *b, u_int n)
{
 int r;
 size_t offset;

 if ((r = reserve(b, n)) != 0)
  return r;
 offset = n / (sizeof(u_int) * 8);
 if (offset > b->top)
  b->top = offset;
 b->d[offset] |= (u_int)1 << (n & ((u_int)(sizeof(u_int) * 8) - 1));
 return 0;
}


static void
retop(struct bitmap *b)
{
 if (b->top >= b->len)
  return;
 while (b->top > 0 && b->d[b->top] == 0)
  b->top--;
}

void
bitmap_clear_bit(struct bitmap *b, u_int n)
{
 size_t offset;

 if (b->top >= b->len || n > (1<<24))
  return;
 offset = n / (sizeof(u_int) * 8);
 if (offset > b->top)
  return;
 b->d[offset] &= ~((u_int)1 << (n & ((u_int)(sizeof(u_int) * 8) - 1)));

 retop(b);
}

size_t
bitmap_nbits(struct bitmap *b)
{
 size_t bits;
 u_int w;

 retop(b);
 if (b->top >= b->len)
  return 0;
 if (b->len == 0 || (b->top == 0 && b->d[0] == 0))
  return 0;

 w = b->d[b->top];
 bits = (b->top + 1) * (sizeof(u_int) * 8);
 while (!(w & ((u_int)1 << ((sizeof(u_int) * 8) - 1)))) {
  w <<= 1;
  bits--;
 }
 return bits;
}

size_t
bitmap_nbytes(struct bitmap *b)
{
 return (bitmap_nbits(b) + 7) / 8;
}

int
bitmap_to_string(struct bitmap *b, void *p, size_t l)
{
 u_char *s = (u_char *)p;
 size_t i, j, k, need = bitmap_nbytes(b);

 if (l < need || b->top >= b->len)
  return -1;
 if (l > need)
  l = need;

 for (i = k = 0; i < b->top + 1; i++) {
  for (j = 0; j < (sizeof(u_int)); j++) {
   if (k >= l)
    break;
   s[need - 1 - k++] = (b->d[i] >> (j * 8)) & 0xff;
  }
 }
 return 0;
}

int
bitmap_from_string(struct bitmap *b, const void *p, size_t l)
{
 int r;
 size_t i, offset, shift;
 const u_char *s = (const u_char *)p;

 if (l > (1<<24) / 8)
  return -1;
 if ((r = reserve(b, l * 8)) != 0)
  return r;
 bitmap_zero(b);
 if (l == 0)
  return 0;
 b->top = offset = ((l + ((sizeof(u_int)) - 1)) / (sizeof(u_int))) - 1;
 shift = ((l + ((sizeof(u_int)) - 1)) % (sizeof(u_int))) * 8;
 for (i = 0; i < l; i++) {
  b->d[offset] |= (u_int)s[i] << shift;
  if (shift == 0) {
   offset--;
   shift = (sizeof(u_int) * 8) - 8;
  } else
   shift -= 8;
 }
 retop(b);
 return 0;
}
