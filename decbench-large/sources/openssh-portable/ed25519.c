











































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
typedef struct
{
  crypto_sign_ed25519_ref_fe25519 x;
  crypto_sign_ed25519_ref_fe25519 y;
  crypto_sign_ed25519_ref_fe25519 z;
  crypto_sign_ed25519_ref_fe25519 t;
} crypto_sign_ed25519_ref_ge25519;

extern const crypto_sign_ed25519_ref_ge25519 crypto_sign_ed25519_ref_ge25519_base;

int crypto_sign_ed25519_ref_unpackneg_vartime(crypto_sign_ed25519_ref_ge25519 *r, const unsigned char p[32]);

void crypto_sign_ed25519_ref_pack(unsigned char r[32], const crypto_sign_ed25519_ref_ge25519 *p);

int crypto_sign_ed25519_ref_isneutral_vartime(const crypto_sign_ed25519_ref_ge25519 *p);

void crypto_sign_ed25519_ref_double_scalarmult_vartime(crypto_sign_ed25519_ref_ge25519 *r, const crypto_sign_ed25519_ref_ge25519 *p1, const crypto_sign_ed25519_ref_sc25519 *s1, const crypto_sign_ed25519_ref_ge25519 *p2, const crypto_sign_ed25519_ref_sc25519 *s2);

void crypto_sign_ed25519_ref_scalarmult_base(crypto_sign_ed25519_ref_ge25519 *r, const crypto_sign_ed25519_ref_sc25519 *s);

static void get_hram(unsigned char *hram, const unsigned char *sm, const unsigned char *pk, unsigned char *playground, unsigned long long smlen)
{
  unsigned long long i;

  for (i = 0;i < 32;++i) playground[i] = sm[i];
  for (i = 32;i < 64;++i) playground[i] = pk[i-32];
  for (i = 64;i < smlen;++i) playground[i] = sm[i];

  crypto_hash_sha512(hram,playground,smlen);
}


int crypto_sign_ed25519_keypair(
    unsigned char *pk,
    unsigned char *sk
    )
{
  crypto_sign_ed25519_ref_sc25519 scsk;
  crypto_sign_ed25519_ref_ge25519 gepk;
  unsigned char extsk[64];
  int i;

  arc4random_buf((sk), (32));
  crypto_hash_sha512(extsk, sk, 32);
  extsk[0] &= 248;
  extsk[31] &= 127;
  extsk[31] |= 64;

  crypto_sign_ed25519_ref_sc25519_from32bytes(&scsk,extsk);

  crypto_sign_ed25519_ref_scalarmult_base(&gepk, &scsk);
  crypto_sign_ed25519_ref_pack(pk, &gepk);
  for(i=0;i<32;i++)
    sk[32 + i] = pk[i];
  return 0;
}

int crypto_sign_ed25519(
    unsigned char *sm,unsigned long long *smlen,
    const unsigned char *m,unsigned long long mlen,
    const unsigned char *sk
    )
{
  crypto_sign_ed25519_ref_sc25519 sck, scs, scsk;
  crypto_sign_ed25519_ref_ge25519 ger;
  unsigned char r[32];
  unsigned char s[32];
  unsigned char extsk[64];
  unsigned long long i;
  unsigned char hmg[64U];
  unsigned char hram[64U];

  crypto_hash_sha512(extsk, sk, 32);
  extsk[0] &= 248;
  extsk[31] &= 127;
  extsk[31] |= 64;

  *smlen = mlen+64;
  for(i=0;i<mlen;i++)
    sm[64 + i] = m[i];
  for(i=0;i<32;i++)
    sm[32 + i] = extsk[32+i];

  crypto_hash_sha512(hmg, sm+32, mlen+32);


  crypto_sign_ed25519_ref_sc25519_from64bytes(&sck, hmg);
  crypto_sign_ed25519_ref_scalarmult_base(&ger, &sck);
  crypto_sign_ed25519_ref_pack(r, &ger);


  for(i=0;i<32;i++)
    sm[i] = r[i];

  get_hram(hram, sm, sk+32, sm, mlen+64);

  crypto_sign_ed25519_ref_sc25519_from64bytes(&scs, hram);
  crypto_sign_ed25519_ref_sc25519_from32bytes(&scsk, extsk);
  crypto_sign_ed25519_ref_sc25519_mul(&scs, &scs, &scsk);

  crypto_sign_ed25519_ref_sc25519_add(&scs, &scs, &sck);

  crypto_sign_ed25519_ref_sc25519_to32bytes(s,&scs);
  for(i=0;i<32;i++)
    sm[32 + i] = s[i];

  return 0;
}

int crypto_sign_ed25519_open(
    unsigned char *m,unsigned long long *mlen,
    const unsigned char *sm,unsigned long long smlen,
    const unsigned char *pk
    )
{
  unsigned int i;
  int ret;
  unsigned char t2[32];
  crypto_sign_ed25519_ref_ge25519 get1, get2;
  crypto_sign_ed25519_ref_sc25519 schram, scs;
  unsigned char hram[64U];

  *mlen = (unsigned long long) -1;
  if (smlen < 64) return -1;

  if (crypto_sign_ed25519_ref_unpackneg_vartime(&get1, pk)) return -1;

  get_hram(hram,sm,pk,m,smlen);

  crypto_sign_ed25519_ref_sc25519_from64bytes(&schram, hram);

  crypto_sign_ed25519_ref_sc25519_from32bytes(&scs, sm+32);

  crypto_sign_ed25519_ref_double_scalarmult_vartime(&get2, &get1, &schram, &crypto_sign_ed25519_ref_ge25519_base, &scs);
  crypto_sign_ed25519_ref_pack(t2, &get2);

  ret = crypto_verify_32(sm, t2);

  if (!ret)
  {
    for(i=0;i<smlen-64;i++)
      m[i] = sm[i + 64];
    *mlen = smlen-64;
  }
  else
  {
    for(i=0;i<smlen-64;i++)
      m[i] = 0;
  }
  return ret;
}
