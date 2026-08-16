











































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
crypto_sign_ed25519_ref_sc25519;

typedef struct
{
  crypto_uint32 v[16];
}
crypto_sign_ed25519_ref_shortsc25519;

void crypto_sign_ed25519_ref_sc25519_from32bytes(crypto_sign_ed25519_ref_sc25519 *r, const unsigned char x[32]);

void crypto_sign_ed25519_ref_shortsc25519_from16bytes(crypto_sign_ed25519_ref_shortsc25519 *r, const unsigned char x[16]);

void crypto_sign_ed25519_ref_sc25519_from64bytes(crypto_sign_ed25519_ref_sc25519 *r, const unsigned char x[64]);

void crypto_sign_ed25519_ref_sc25519_from_shortsc(crypto_sign_ed25519_ref_sc25519 *r, const crypto_sign_ed25519_ref_shortsc25519 *x);

void crypto_sign_ed25519_ref_sc25519_to32bytes(unsigned char r[32], const crypto_sign_ed25519_ref_sc25519 *x);

int crypto_sign_ed25519_ref_sc25519_iszero_vartime(const crypto_sign_ed25519_ref_sc25519 *x);

int crypto_sign_ed25519_ref_sc25519_isshort_vartime(const crypto_sign_ed25519_ref_sc25519 *x);

int crypto_sign_ed25519_ref_sc25519_lt_vartime(const crypto_sign_ed25519_ref_sc25519 *x, const crypto_sign_ed25519_ref_sc25519 *y);

void crypto_sign_ed25519_ref_sc25519_add(crypto_sign_ed25519_ref_sc25519 *r, const crypto_sign_ed25519_ref_sc25519 *x, const crypto_sign_ed25519_ref_sc25519 *y);

void crypto_sign_ed25519_ref_sc25519_sub_nored(crypto_sign_ed25519_ref_sc25519 *r, const crypto_sign_ed25519_ref_sc25519 *x, const crypto_sign_ed25519_ref_sc25519 *y);

void crypto_sign_ed25519_ref_sc25519_mul(crypto_sign_ed25519_ref_sc25519 *r, const crypto_sign_ed25519_ref_sc25519 *x, const crypto_sign_ed25519_ref_sc25519 *y);

void crypto_sign_ed25519_ref_sc25519_mul_shortsc(crypto_sign_ed25519_ref_sc25519 *r, const crypto_sign_ed25519_ref_sc25519 *x, const crypto_sign_ed25519_ref_shortsc25519 *y);




void crypto_sign_ed25519_ref_sc25519_window3(signed char r[85], const crypto_sign_ed25519_ref_sc25519 *s);




void crypto_sign_ed25519_ref_sc25519_window5(signed char r[51], const crypto_sign_ed25519_ref_sc25519 *s);

void crypto_sign_ed25519_ref_sc25519_2interleave2(unsigned char r[127], const crypto_sign_ed25519_ref_sc25519 *s1, const crypto_sign_ed25519_ref_sc25519 *s2);



static const crypto_uint32 m[32] = {0xED, 0xD3, 0xF5, 0x5C, 0x1A, 0x63, 0x12, 0x58, 0xD6, 0x9C, 0xF7, 0xA2, 0xDE, 0xF9, 0xDE, 0x14,
                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10};

static const crypto_uint32 mu[33] = {0x1B, 0x13, 0x2C, 0x0A, 0xA3, 0xE5, 0x9C, 0xED, 0xA7, 0x29, 0x63, 0x08, 0x5D, 0x21, 0x06, 0x21,
                                     0xEB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F};

static crypto_uint32 lt(crypto_uint32 a,crypto_uint32 b)
{
  unsigned int x = a;
  x -= (unsigned int) b;
  x >>= 31;
  return x;
}


static void reduce_add_sub(crypto_sign_ed25519_ref_sc25519 *r)
{
  crypto_uint32 pb = 0;
  crypto_uint32 b;
  crypto_uint32 mask;
  int i;
  unsigned char t[32];

  for(i=0;i<32;i++)
  {
    pb += m[i];
    b = lt(r->v[i],pb);
    t[i] = r->v[i]-pb+(b<<8);
    pb = b;
  }
  mask = b - 1;
  for(i=0;i<32;i++)
    r->v[i] ^= mask & (r->v[i] ^ t[i]);
}


static void barrett_reduce(crypto_sign_ed25519_ref_sc25519 *r, const crypto_uint32 x[64])
{

  int i,j;
  crypto_uint32 q2[66];
  crypto_uint32 *q3 = q2 + 33;
  crypto_uint32 r1[33];
  crypto_uint32 r2[33];
  crypto_uint32 carry;
  crypto_uint32 pb = 0;
  crypto_uint32 b;

  for (i = 0;i < 66;++i) q2[i] = 0;
  for (i = 0;i < 33;++i) r2[i] = 0;

  for(i=0;i<33;i++)
    for(j=0;j<33;j++)
      if(i+j >= 31) q2[i+j] += mu[i]*x[j+31];
  carry = q2[31] >> 8;
  q2[32] += carry;
  carry = q2[32] >> 8;
  q2[33] += carry;

  for(i=0;i<33;i++)r1[i] = x[i];
  for(i=0;i<32;i++)
    for(j=0;j<33;j++)
      if(i+j < 33) r2[i+j] += m[i]*q3[j];

  for(i=0;i<32;i++)
  {
    carry = r2[i] >> 8;
    r2[i+1] += carry;
    r2[i] &= 0xff;
  }

  for(i=0;i<32;i++)
  {
    pb += r2[i];
    b = lt(r1[i],pb);
    r->v[i] = r1[i]-pb+(b<<8);
    pb = b;
  }





  reduce_add_sub(r);
  reduce_add_sub(r);
}

void crypto_sign_ed25519_ref_sc25519_from32bytes(crypto_sign_ed25519_ref_sc25519 *r, const unsigned char x[32])
{
  int i;
  crypto_uint32 t[64];
  for(i=0;i<32;i++) t[i] = x[i];
  for(i=32;i<64;++i) t[i] = 0;
  barrett_reduce(r, t);
}

void crypto_sign_ed25519_ref_shortsc25519_from16bytes(crypto_sign_ed25519_ref_shortsc25519 *r, const unsigned char x[16])
{
  int i;
  for(i=0;i<16;i++) r->v[i] = x[i];
}

void crypto_sign_ed25519_ref_sc25519_from64bytes(crypto_sign_ed25519_ref_sc25519 *r, const unsigned char x[64])
{
  int i;
  crypto_uint32 t[64];
  for(i=0;i<64;i++) t[i] = x[i];
  barrett_reduce(r, t);
}

void crypto_sign_ed25519_ref_sc25519_from_shortsc(crypto_sign_ed25519_ref_sc25519 *r, const crypto_sign_ed25519_ref_shortsc25519 *x)
{
  int i;
  for(i=0;i<16;i++)
    r->v[i] = x->v[i];
  for(i=0;i<16;i++)
    r->v[16+i] = 0;
}

void crypto_sign_ed25519_ref_sc25519_to32bytes(unsigned char r[32], const crypto_sign_ed25519_ref_sc25519 *x)
{
  int i;
  for(i=0;i<32;i++) r[i] = x->v[i];
}

int crypto_sign_ed25519_ref_sc25519_iszero_vartime(const crypto_sign_ed25519_ref_sc25519 *x)
{
  int i;
  for(i=0;i<32;i++)
    if(x->v[i] != 0) return 0;
  return 1;
}

int crypto_sign_ed25519_ref_sc25519_isshort_vartime(const crypto_sign_ed25519_ref_sc25519 *x)
{
  int i;
  for(i=31;i>15;i--)
    if(x->v[i] != 0) return 0;
  return 1;
}

int crypto_sign_ed25519_ref_sc25519_lt_vartime(const crypto_sign_ed25519_ref_sc25519 *x, const crypto_sign_ed25519_ref_sc25519 *y)
{
  int i;
  for(i=31;i>=0;i--)
  {
    if(x->v[i] < y->v[i]) return 1;
    if(x->v[i] > y->v[i]) return 0;
  }
  return 0;
}

void crypto_sign_ed25519_ref_sc25519_add(crypto_sign_ed25519_ref_sc25519 *r, const crypto_sign_ed25519_ref_sc25519 *x, const crypto_sign_ed25519_ref_sc25519 *y)
{
  int i, carry;
  for(i=0;i<32;i++) r->v[i] = x->v[i] + y->v[i];
  for(i=0;i<31;i++)
  {
    carry = r->v[i] >> 8;
    r->v[i+1] += carry;
    r->v[i] &= 0xff;
  }
  reduce_add_sub(r);
}

void crypto_sign_ed25519_ref_sc25519_sub_nored(crypto_sign_ed25519_ref_sc25519 *r, const crypto_sign_ed25519_ref_sc25519 *x, const crypto_sign_ed25519_ref_sc25519 *y)
{
  crypto_uint32 b = 0;
  crypto_uint32 t;
  int i;
  for(i=0;i<32;i++)
  {
    t = x->v[i] - y->v[i] - b;
    r->v[i] = t & 255;
    b = (t >> 8) & 1;
  }
}

void crypto_sign_ed25519_ref_sc25519_mul(crypto_sign_ed25519_ref_sc25519 *r, const crypto_sign_ed25519_ref_sc25519 *x, const crypto_sign_ed25519_ref_sc25519 *y)
{
  int i,j,carry;
  crypto_uint32 t[64];
  for(i=0;i<64;i++)t[i] = 0;

  for(i=0;i<32;i++)
    for(j=0;j<32;j++)
      t[i+j] += x->v[i] * y->v[j];


  for(i=0;i<63;i++)
  {
    carry = t[i] >> 8;
    t[i+1] += carry;
    t[i] &= 0xff;
  }

  barrett_reduce(r, t);
}

void crypto_sign_ed25519_ref_sc25519_mul_shortsc(crypto_sign_ed25519_ref_sc25519 *r, const crypto_sign_ed25519_ref_sc25519 *x, const crypto_sign_ed25519_ref_shortsc25519 *y)
{
  crypto_sign_ed25519_ref_sc25519 t;
  crypto_sign_ed25519_ref_sc25519_from_shortsc(&t, y);
  crypto_sign_ed25519_ref_sc25519_mul(r, x, &t);
}

void crypto_sign_ed25519_ref_sc25519_window3(signed char r[85], const crypto_sign_ed25519_ref_sc25519 *s)
{
  char carry;
  int i;
  for(i=0;i<10;i++)
  {
    r[8*i+0] = s->v[3*i+0] & 7;
    r[8*i+1] = (s->v[3*i+0] >> 3) & 7;
    r[8*i+2] = (s->v[3*i+0] >> 6) & 7;
    r[8*i+2] ^= (s->v[3*i+1] << 2) & 7;
    r[8*i+3] = (s->v[3*i+1] >> 1) & 7;
    r[8*i+4] = (s->v[3*i+1] >> 4) & 7;
    r[8*i+5] = (s->v[3*i+1] >> 7) & 7;
    r[8*i+5] ^= (s->v[3*i+2] << 1) & 7;
    r[8*i+6] = (s->v[3*i+2] >> 2) & 7;
    r[8*i+7] = (s->v[3*i+2] >> 5) & 7;
  }
  r[8*i+0] = s->v[3*i+0] & 7;
  r[8*i+1] = (s->v[3*i+0] >> 3) & 7;
  r[8*i+2] = (s->v[3*i+0] >> 6) & 7;
  r[8*i+2] ^= (s->v[3*i+1] << 2) & 7;
  r[8*i+3] = (s->v[3*i+1] >> 1) & 7;
  r[8*i+4] = (s->v[3*i+1] >> 4) & 7;


  carry = 0;
  for(i=0;i<84;i++)
  {
    r[i] += carry;
    r[i+1] += r[i] >> 3;
    r[i] &= 7;
    carry = r[i] >> 2;
    r[i] -= carry<<3;
  }
  r[84] += carry;
}

void crypto_sign_ed25519_ref_sc25519_window5(signed char r[51], const crypto_sign_ed25519_ref_sc25519 *s)
{
  char carry;
  int i;
  for(i=0;i<6;i++)
  {
    r[8*i+0] = s->v[5*i+0] & 31;
    r[8*i+1] = (s->v[5*i+0] >> 5) & 31;
    r[8*i+1] ^= (s->v[5*i+1] << 3) & 31;
    r[8*i+2] = (s->v[5*i+1] >> 2) & 31;
    r[8*i+3] = (s->v[5*i+1] >> 7) & 31;
    r[8*i+3] ^= (s->v[5*i+2] << 1) & 31;
    r[8*i+4] = (s->v[5*i+2] >> 4) & 31;
    r[8*i+4] ^= (s->v[5*i+3] << 4) & 31;
    r[8*i+5] = (s->v[5*i+3] >> 1) & 31;
    r[8*i+6] = (s->v[5*i+3] >> 6) & 31;
    r[8*i+6] ^= (s->v[5*i+4] << 2) & 31;
    r[8*i+7] = (s->v[5*i+4] >> 3) & 31;
  }
  r[8*i+0] = s->v[5*i+0] & 31;
  r[8*i+1] = (s->v[5*i+0] >> 5) & 31;
  r[8*i+1] ^= (s->v[5*i+1] << 3) & 31;
  r[8*i+2] = (s->v[5*i+1] >> 2) & 31;


  carry = 0;
  for(i=0;i<50;i++)
  {
    r[i] += carry;
    r[i+1] += r[i] >> 5;
    r[i] &= 31;
    carry = r[i] >> 4;
    r[i] -= carry<<5;
  }
  r[50] += carry;
}

void crypto_sign_ed25519_ref_sc25519_2interleave2(unsigned char r[127], const crypto_sign_ed25519_ref_sc25519 *s1, const crypto_sign_ed25519_ref_sc25519 *s2)
{
  int i;
  for(i=0;i<31;i++)
  {
    r[4*i] = ( s1->v[i] & 3) ^ (( s2->v[i] & 3) << 2);
    r[4*i+1] = ((s1->v[i] >> 2) & 3) ^ (((s2->v[i] >> 2) & 3) << 2);
    r[4*i+2] = ((s1->v[i] >> 4) & 3) ^ (((s2->v[i] >> 4) & 3) << 2);
    r[4*i+3] = ((s1->v[i] >> 6) & 3) ^ (((s2->v[i] >> 6) & 3) << 2);
  }
  r[124] = ( s1->v[31] & 3) ^ (( s2->v[31] & 3) << 2);
  r[125] = ((s1->v[31] >> 2) & 3) ^ (((s2->v[31] >> 2) & 3) << 2);
  r[126] = ((s1->v[31] >> 4) & 3) ^ (((s2->v[31] >> 4) & 3) << 2);
}
