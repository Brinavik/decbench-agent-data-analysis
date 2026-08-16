











































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






typedef int8_t crypto_int8;
typedef uint8_t crypto_uint8;
typedef int16_t crypto_int16;
typedef uint16_t crypto_uint16;
typedef int32_t crypto_int32;
typedef uint32_t crypto_uint32;
typedef int64_t crypto_int64;
typedef uint64_t crypto_uint64;






int crypto_hash_sha512(unsigned char *, const unsigned char *,
    unsigned long long);

int crypto_verify_32(const unsigned char *, const unsigned char *);





int crypto_sign_ed25519(unsigned char *, unsigned long long *,
    const unsigned char *, unsigned long long, const unsigned char *);
int crypto_sign_ed25519_open(unsigned char *, unsigned long long *,
    const unsigned char *, unsigned long long, const unsigned char *);
int crypto_sign_ed25519_keypair(unsigned char *, unsigned char *);






int crypto_kem_sntrup761_enc(unsigned char *cstr, unsigned char *k,
    const unsigned char *pk);
int crypto_kem_sntrup761_dec(unsigned char *k,
    const unsigned char *cstr, const unsigned char *sk);
int crypto_kem_sntrup761_keypair(unsigned char *pk, unsigned char *sk);
typedef struct
{
  crypto_uint32 v[32];
}
crypto_sign_ed25519_ref_fe25519;

void crypto_sign_ed25519_ref_fe25519_freeze(crypto_sign_ed25519_ref_fe25519 *r);

void crypto_sign_ed25519_ref_fe25519_unpack(crypto_sign_ed25519_ref_fe25519 *r, const unsigned char x[32]);

void crypto_sign_ed25519_ref_fe25519_pack(unsigned char r[32], const crypto_sign_ed25519_ref_fe25519 *x);

int crypto_sign_ed25519_ref_fe25519_iszero(const crypto_sign_ed25519_ref_fe25519 *x);

int crypto_sign_ed25519_ref_fe25519_iseq_vartime(const crypto_sign_ed25519_ref_fe25519 *x, const crypto_sign_ed25519_ref_fe25519 *y);

void crypto_sign_ed25519_ref_fe25519_cmov(crypto_sign_ed25519_ref_fe25519 *r, const crypto_sign_ed25519_ref_fe25519 *x, unsigned char b);

void crypto_sign_ed25519_ref_fe25519_setone(crypto_sign_ed25519_ref_fe25519 *r);

void crypto_sign_ed25519_ref_fe25519_setzero(crypto_sign_ed25519_ref_fe25519 *r);

void crypto_sign_ed25519_ref_fe25519_neg(crypto_sign_ed25519_ref_fe25519 *r, const crypto_sign_ed25519_ref_fe25519 *x);

unsigned char crypto_sign_ed25519_ref_fe25519_getparity(const crypto_sign_ed25519_ref_fe25519 *x);

void crypto_sign_ed25519_ref_fe25519_add(crypto_sign_ed25519_ref_fe25519 *r, const crypto_sign_ed25519_ref_fe25519 *x, const crypto_sign_ed25519_ref_fe25519 *y);

void crypto_sign_ed25519_ref_fe25519_sub(crypto_sign_ed25519_ref_fe25519 *r, const crypto_sign_ed25519_ref_fe25519 *x, const crypto_sign_ed25519_ref_fe25519 *y);

void crypto_sign_ed25519_ref_fe25519_mul(crypto_sign_ed25519_ref_fe25519 *r, const crypto_sign_ed25519_ref_fe25519 *x, const crypto_sign_ed25519_ref_fe25519 *y);

void crypto_sign_ed25519_ref_fe25519_square(crypto_sign_ed25519_ref_fe25519 *r, const crypto_sign_ed25519_ref_fe25519 *x);

void crypto_sign_ed25519_ref_fe25519_invert(crypto_sign_ed25519_ref_fe25519 *r, const crypto_sign_ed25519_ref_fe25519 *x);

void crypto_sign_ed25519_ref_fe25519_pow2523(crypto_sign_ed25519_ref_fe25519 *r, const crypto_sign_ed25519_ref_fe25519 *x);

static crypto_uint32 equal(crypto_uint32 a,crypto_uint32 b)
{
  crypto_uint32 x = a ^ b;
  x -= 1;
  x >>= 31;
  return x;
}

static crypto_uint32 ge(crypto_uint32 a,crypto_uint32 b)
{
  unsigned int x = a;
  x -= (unsigned int) b;
  x >>= 31;
  x ^= 1;
  return x;
}

static crypto_uint32 times19(crypto_uint32 a)
{
  return (a << 4) + (a << 1) + a;
}

static crypto_uint32 times38(crypto_uint32 a)
{
  return (a << 5) + (a << 2) + (a << 1);
}

static void reduce_add_sub(crypto_sign_ed25519_ref_fe25519 *r)
{
  crypto_uint32 t;
  int i,rep;

  for(rep=0;rep<4;rep++)
  {
    t = r->v[31] >> 7;
    r->v[31] &= 127;
    t = times19(t);
    r->v[0] += t;
    for(i=0;i<31;i++)
    {
      t = r->v[i] >> 8;
      r->v[i+1] += t;
      r->v[i] &= 255;
    }
  }
}

static void reduce_mul(crypto_sign_ed25519_ref_fe25519 *r)
{
  crypto_uint32 t;
  int i,rep;

  for(rep=0;rep<2;rep++)
  {
    t = r->v[31] >> 7;
    r->v[31] &= 127;
    t = times19(t);
    r->v[0] += t;
    for(i=0;i<31;i++)
    {
      t = r->v[i] >> 8;
      r->v[i+1] += t;
      r->v[i] &= 255;
    }
  }
}


void crypto_sign_ed25519_ref_fe25519_freeze(crypto_sign_ed25519_ref_fe25519 *r)
{
  int i;
  crypto_uint32 m = equal(r->v[31],127);
  for(i=30;i>0;i--)
    m &= equal(r->v[i],255);
  m &= ge(r->v[0],237);

  m = -m;

  r->v[31] -= m&127;
  for(i=30;i>0;i--)
    r->v[i] -= m&255;
  r->v[0] -= m&237;
}

void crypto_sign_ed25519_ref_fe25519_unpack(crypto_sign_ed25519_ref_fe25519 *r, const unsigned char x[32])
{
  int i;
  for(i=0;i<32;i++) r->v[i] = x[i];
  r->v[31] &= 127;
}


void crypto_sign_ed25519_ref_fe25519_pack(unsigned char r[32], const crypto_sign_ed25519_ref_fe25519 *x)
{
  int i;
  crypto_sign_ed25519_ref_fe25519 y = *x;
  crypto_sign_ed25519_ref_fe25519_freeze(&y);
  for(i=0;i<32;i++)
    r[i] = y.v[i];
}

int crypto_sign_ed25519_ref_fe25519_iszero(const crypto_sign_ed25519_ref_fe25519 *x)
{
  int i;
  int r;
  crypto_sign_ed25519_ref_fe25519 t = *x;
  crypto_sign_ed25519_ref_fe25519_freeze(&t);
  r = equal(t.v[0],0);
  for(i=1;i<32;i++)
    r &= equal(t.v[i],0);
  return r;
}

int crypto_sign_ed25519_ref_fe25519_iseq_vartime(const crypto_sign_ed25519_ref_fe25519 *x, const crypto_sign_ed25519_ref_fe25519 *y)
{
  int i;
  crypto_sign_ed25519_ref_fe25519 t1 = *x;
  crypto_sign_ed25519_ref_fe25519 t2 = *y;
  crypto_sign_ed25519_ref_fe25519_freeze(&t1);
  crypto_sign_ed25519_ref_fe25519_freeze(&t2);
  for(i=0;i<32;i++)
    if(t1.v[i] != t2.v[i]) return 0;
  return 1;
}

void crypto_sign_ed25519_ref_fe25519_cmov(crypto_sign_ed25519_ref_fe25519 *r, const crypto_sign_ed25519_ref_fe25519 *x, unsigned char b)
{
  int i;
  crypto_uint32 mask = b;
  mask = -mask;
  for(i=0;i<32;i++) r->v[i] ^= mask & (x->v[i] ^ r->v[i]);
}

unsigned char crypto_sign_ed25519_ref_fe25519_getparity(const crypto_sign_ed25519_ref_fe25519 *x)
{
  crypto_sign_ed25519_ref_fe25519 t = *x;
  crypto_sign_ed25519_ref_fe25519_freeze(&t);
  return t.v[0] & 1;
}

void crypto_sign_ed25519_ref_fe25519_setone(crypto_sign_ed25519_ref_fe25519 *r)
{
  int i;
  r->v[0] = 1;
  for(i=1;i<32;i++) r->v[i]=0;
}

void crypto_sign_ed25519_ref_fe25519_setzero(crypto_sign_ed25519_ref_fe25519 *r)
{
  int i;
  for(i=0;i<32;i++) r->v[i]=0;
}

void crypto_sign_ed25519_ref_fe25519_neg(crypto_sign_ed25519_ref_fe25519 *r, const crypto_sign_ed25519_ref_fe25519 *x)
{
  crypto_sign_ed25519_ref_fe25519 t;
  int i;
  for(i=0;i<32;i++) t.v[i]=x->v[i];
  crypto_sign_ed25519_ref_fe25519_setzero(r);
  crypto_sign_ed25519_ref_fe25519_sub(r, r, &t);
}

void crypto_sign_ed25519_ref_fe25519_add(crypto_sign_ed25519_ref_fe25519 *r, const crypto_sign_ed25519_ref_fe25519 *x, const crypto_sign_ed25519_ref_fe25519 *y)
{
  int i;
  for(i=0;i<32;i++) r->v[i] = x->v[i] + y->v[i];
  reduce_add_sub(r);
}

void crypto_sign_ed25519_ref_fe25519_sub(crypto_sign_ed25519_ref_fe25519 *r, const crypto_sign_ed25519_ref_fe25519 *x, const crypto_sign_ed25519_ref_fe25519 *y)
{
  int i;
  crypto_uint32 t[32];
  t[0] = x->v[0] + 0x1da;
  t[31] = x->v[31] + 0xfe;
  for(i=1;i<31;i++) t[i] = x->v[i] + 0x1fe;
  for(i=0;i<32;i++) r->v[i] = t[i] - y->v[i];
  reduce_add_sub(r);
}

void crypto_sign_ed25519_ref_fe25519_mul(crypto_sign_ed25519_ref_fe25519 *r, const crypto_sign_ed25519_ref_fe25519 *x, const crypto_sign_ed25519_ref_fe25519 *y)
{
  int i,j;
  crypto_uint32 t[63];
  for(i=0;i<63;i++)t[i] = 0;

  for(i=0;i<32;i++)
    for(j=0;j<32;j++)
      t[i+j] += x->v[i] * y->v[j];

  for(i=32;i<63;i++)
    r->v[i-32] = t[i-32] + times38(t[i]);
  r->v[31] = t[31];

  reduce_mul(r);
}

void crypto_sign_ed25519_ref_fe25519_square(crypto_sign_ed25519_ref_fe25519 *r, const crypto_sign_ed25519_ref_fe25519 *x)
{
  crypto_sign_ed25519_ref_fe25519_mul(r, x, x);
}

void crypto_sign_ed25519_ref_fe25519_invert(crypto_sign_ed25519_ref_fe25519 *r, const crypto_sign_ed25519_ref_fe25519 *x)
{
 crypto_sign_ed25519_ref_fe25519 z2;
 crypto_sign_ed25519_ref_fe25519 z9;
 crypto_sign_ed25519_ref_fe25519 z11;
 crypto_sign_ed25519_ref_fe25519 z2_5_0;
 crypto_sign_ed25519_ref_fe25519 z2_10_0;
 crypto_sign_ed25519_ref_fe25519 z2_20_0;
 crypto_sign_ed25519_ref_fe25519 z2_50_0;
 crypto_sign_ed25519_ref_fe25519 z2_100_0;
 crypto_sign_ed25519_ref_fe25519 t0;
 crypto_sign_ed25519_ref_fe25519 t1;
 int i;

         crypto_sign_ed25519_ref_fe25519_square(&z2,x);
         crypto_sign_ed25519_ref_fe25519_square(&t1,&z2);
         crypto_sign_ed25519_ref_fe25519_square(&t0,&t1);
         crypto_sign_ed25519_ref_fe25519_mul(&z9,&t0,x);
          crypto_sign_ed25519_ref_fe25519_mul(&z11,&z9,&z2);
          crypto_sign_ed25519_ref_fe25519_square(&t0,&z11);
                      crypto_sign_ed25519_ref_fe25519_mul(&z2_5_0,&t0,&z9);

                 crypto_sign_ed25519_ref_fe25519_square(&t0,&z2_5_0);
                 crypto_sign_ed25519_ref_fe25519_square(&t1,&t0);
                 crypto_sign_ed25519_ref_fe25519_square(&t0,&t1);
                 crypto_sign_ed25519_ref_fe25519_square(&t1,&t0);
                  crypto_sign_ed25519_ref_fe25519_square(&t0,&t1);
                  crypto_sign_ed25519_ref_fe25519_mul(&z2_10_0,&t0,&z2_5_0);

                  crypto_sign_ed25519_ref_fe25519_square(&t0,&z2_10_0);
                  crypto_sign_ed25519_ref_fe25519_square(&t1,&t0);
                   for (i = 2;i < 10;i += 2) { crypto_sign_ed25519_ref_fe25519_square(&t0,&t1); crypto_sign_ed25519_ref_fe25519_square(&t1,&t0); }
                  crypto_sign_ed25519_ref_fe25519_mul(&z2_20_0,&t1,&z2_10_0);

                  crypto_sign_ed25519_ref_fe25519_square(&t0,&z2_20_0);
                  crypto_sign_ed25519_ref_fe25519_square(&t1,&t0);
                   for (i = 2;i < 20;i += 2) { crypto_sign_ed25519_ref_fe25519_square(&t0,&t1); crypto_sign_ed25519_ref_fe25519_square(&t1,&t0); }
                  crypto_sign_ed25519_ref_fe25519_mul(&t0,&t1,&z2_20_0);

                  crypto_sign_ed25519_ref_fe25519_square(&t1,&t0);
                  crypto_sign_ed25519_ref_fe25519_square(&t0,&t1);
                   for (i = 2;i < 10;i += 2) { crypto_sign_ed25519_ref_fe25519_square(&t1,&t0); crypto_sign_ed25519_ref_fe25519_square(&t0,&t1); }
                  crypto_sign_ed25519_ref_fe25519_mul(&z2_50_0,&t0,&z2_10_0);

                  crypto_sign_ed25519_ref_fe25519_square(&t0,&z2_50_0);
                  crypto_sign_ed25519_ref_fe25519_square(&t1,&t0);
                    for (i = 2;i < 50;i += 2) { crypto_sign_ed25519_ref_fe25519_square(&t0,&t1); crypto_sign_ed25519_ref_fe25519_square(&t1,&t0); }
                   crypto_sign_ed25519_ref_fe25519_mul(&z2_100_0,&t1,&z2_50_0);

                   crypto_sign_ed25519_ref_fe25519_square(&t1,&z2_100_0);
                   crypto_sign_ed25519_ref_fe25519_square(&t0,&t1);
                     for (i = 2;i < 100;i += 2) { crypto_sign_ed25519_ref_fe25519_square(&t1,&t0); crypto_sign_ed25519_ref_fe25519_square(&t0,&t1); }
                   crypto_sign_ed25519_ref_fe25519_mul(&t1,&t0,&z2_100_0);

                   crypto_sign_ed25519_ref_fe25519_square(&t0,&t1);
                   crypto_sign_ed25519_ref_fe25519_square(&t1,&t0);
                    for (i = 2;i < 50;i += 2) { crypto_sign_ed25519_ref_fe25519_square(&t0,&t1); crypto_sign_ed25519_ref_fe25519_square(&t1,&t0); }
                   crypto_sign_ed25519_ref_fe25519_mul(&t0,&t1,&z2_50_0);

                   crypto_sign_ed25519_ref_fe25519_square(&t1,&t0);
                   crypto_sign_ed25519_ref_fe25519_square(&t0,&t1);
                   crypto_sign_ed25519_ref_fe25519_square(&t1,&t0);
                   crypto_sign_ed25519_ref_fe25519_square(&t0,&t1);
                   crypto_sign_ed25519_ref_fe25519_square(&t1,&t0);
                  crypto_sign_ed25519_ref_fe25519_mul(r,&t1,&z11);
}

void crypto_sign_ed25519_ref_fe25519_pow2523(crypto_sign_ed25519_ref_fe25519 *r, const crypto_sign_ed25519_ref_fe25519 *x)
{
 crypto_sign_ed25519_ref_fe25519 z2;
 crypto_sign_ed25519_ref_fe25519 z9;
 crypto_sign_ed25519_ref_fe25519 z11;
 crypto_sign_ed25519_ref_fe25519 z2_5_0;
 crypto_sign_ed25519_ref_fe25519 z2_10_0;
 crypto_sign_ed25519_ref_fe25519 z2_20_0;
 crypto_sign_ed25519_ref_fe25519 z2_50_0;
 crypto_sign_ed25519_ref_fe25519 z2_100_0;
 crypto_sign_ed25519_ref_fe25519 t;
 int i;

         crypto_sign_ed25519_ref_fe25519_square(&z2,x);
         crypto_sign_ed25519_ref_fe25519_square(&t,&z2);
         crypto_sign_ed25519_ref_fe25519_square(&t,&t);
         crypto_sign_ed25519_ref_fe25519_mul(&z9,&t,x);
          crypto_sign_ed25519_ref_fe25519_mul(&z11,&z9,&z2);
          crypto_sign_ed25519_ref_fe25519_square(&t,&z11);
                      crypto_sign_ed25519_ref_fe25519_mul(&z2_5_0,&t,&z9);

                 crypto_sign_ed25519_ref_fe25519_square(&t,&z2_5_0);
                  for (i = 1;i < 5;i++) { crypto_sign_ed25519_ref_fe25519_square(&t,&t); }
                  crypto_sign_ed25519_ref_fe25519_mul(&z2_10_0,&t,&z2_5_0);

                  crypto_sign_ed25519_ref_fe25519_square(&t,&z2_10_0);
                   for (i = 1;i < 10;i++) { crypto_sign_ed25519_ref_fe25519_square(&t,&t); }
                  crypto_sign_ed25519_ref_fe25519_mul(&z2_20_0,&t,&z2_10_0);

                  crypto_sign_ed25519_ref_fe25519_square(&t,&z2_20_0);
                   for (i = 1;i < 20;i++) { crypto_sign_ed25519_ref_fe25519_square(&t,&t); }
                  crypto_sign_ed25519_ref_fe25519_mul(&t,&t,&z2_20_0);

                  crypto_sign_ed25519_ref_fe25519_square(&t,&t);
                   for (i = 1;i < 10;i++) { crypto_sign_ed25519_ref_fe25519_square(&t,&t); }
                  crypto_sign_ed25519_ref_fe25519_mul(&z2_50_0,&t,&z2_10_0);

                  crypto_sign_ed25519_ref_fe25519_square(&t,&z2_50_0);
                    for (i = 1;i < 50;i++) { crypto_sign_ed25519_ref_fe25519_square(&t,&t); }
                   crypto_sign_ed25519_ref_fe25519_mul(&z2_100_0,&t,&z2_50_0);

                   crypto_sign_ed25519_ref_fe25519_square(&t,&z2_100_0);
                     for (i = 1;i < 100;i++) { crypto_sign_ed25519_ref_fe25519_square(&t,&t); }
                   crypto_sign_ed25519_ref_fe25519_mul(&t,&t,&z2_100_0);

                   crypto_sign_ed25519_ref_fe25519_square(&t,&t);
                    for (i = 1;i < 50;i++) { crypto_sign_ed25519_ref_fe25519_square(&t,&t); }
                   crypto_sign_ed25519_ref_fe25519_mul(&t,&t,&z2_50_0);

                   crypto_sign_ed25519_ref_fe25519_square(&t,&t);
                   crypto_sign_ed25519_ref_fe25519_square(&t,&t);
                 crypto_sign_ed25519_ref_fe25519_mul(r,&t,x);
}
