











































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
static void crypto_sort_int32(void *array,long long n)
{
  long long top,p,q,r,i,j;
  crypto_int32 *x = array;

  if (n < 2) return;
  top = 1;
  while (top < n - top) top += top;

  for (p = top;p >= 1;p >>= 1) {
    i = 0;
    while (i + 2 * p <= n) {
      for (j = i;j < i + p;++j)
        do { int64_t ab = (int64_t)x[j+p] ^ (int64_t)x[j]; int64_t c = (int64_t)x[j+p] - (int64_t)x[j]; c ^= ab & (c ^ x[j+p]); c >>= 31; c &= ab; x[j] ^= c; x[j+p] ^= c; } while(0);
      i += 2 * p;
    }
    for (j = i;j < n - p;++j)
      do { int64_t ab = (int64_t)x[j+p] ^ (int64_t)x[j]; int64_t c = (int64_t)x[j+p] - (int64_t)x[j]; c ^= ab & (c ^ x[j+p]); c >>= 31; c &= ab; x[j] ^= c; x[j+p] ^= c; } while(0);

    i = 0;
    j = 0;
    for (q = top;q > p;q >>= 1) {
      if (j != i) for (;;) {
        if (j == n - q) goto done;
        crypto_int32 a = x[j + p];
        for (r = q;r > p;r >>= 1)
          do { int64_t ab = (int64_t)x[j + r] ^ (int64_t)a; int64_t c = (int64_t)x[j + r] - (int64_t)a; c ^= ab & (c ^ x[j + r]); c >>= 31; c &= ab; a ^= c; x[j + r] ^= c; } while(0);
        x[j + p] = a;
        ++j;
        if (j == i + p) {
          i += 2 * p;
          break;
        }
      }
      while (i + p <= n - q) {
        for (j = i;j < i + p;++j) {
          crypto_int32 a = x[j + p];
          for (r = q;r > p;r >>= 1)
            do { int64_t ab = (int64_t)x[j+r] ^ (int64_t)a; int64_t c = (int64_t)x[j+r] - (int64_t)a; c ^= ab & (c ^ x[j+r]); c >>= 31; c &= ab; a ^= c; x[j+r] ^= c; } while(0);
          x[j + p] = a;
        }
        i += 2 * p;
      }

      j = i;
      while (j < n - q) {
        crypto_int32 a = x[j + p];
        for (r = q;r > p;r >>= 1)
          do { int64_t ab = (int64_t)x[j+r] ^ (int64_t)a; int64_t c = (int64_t)x[j+r] - (int64_t)a; c ^= ab & (c ^ x[j+r]); c >>= 31; c &= ab; a ^= c; x[j+r] ^= c; } while(0);
        x[j + p] = a;
        ++j;
      }

      done: ;
    }
  }
}






static void crypto_sort_uint32(void *array,long long n)
{
  crypto_uint32 *x = array;
  long long j;
  for (j = 0;j < n;++j) x[j] ^= 0x80000000;
  crypto_sort_int32(array,n);
  for (j = 0;j < n;++j) x[j] ^= 0x80000000;
}
static void uint32_divmod_uint14(crypto_uint32 *q,crypto_uint16 *r,crypto_uint32 x,crypto_uint16 m)
{
  crypto_uint32 v = 0x80000000;
  crypto_uint32 qpart;
  crypto_uint32 mask;

  v /= m;






  *q = 0;

  qpart = (x*(crypto_uint64)v)>>31;







  x -= qpart*m; *q += qpart;


  qpart = (x*(crypto_uint64)v)>>31;





  x -= qpart*m; *q += qpart;


  x -= m; *q += 1;
  mask = -(x>>31);
  x += mask&(crypto_uint32)m; *q += mask;


  *r = x;
}


static crypto_uint16 uint32_mod_uint14(crypto_uint32 x,crypto_uint16 m)
{
  crypto_uint32 q;
  crypto_uint16 r;
  uint32_divmod_uint14(&q,&r,x,m);
  return r;
}



static void int32_divmod_uint14(crypto_int32 *q,crypto_uint16 *r,crypto_int32 x,crypto_uint16 m)
{
  crypto_uint32 uq,uq2;
  crypto_uint16 ur,ur2;
  crypto_uint32 mask;

  uint32_divmod_uint14(&uq,&ur,0x80000000+(crypto_uint32)x,m);
  uint32_divmod_uint14(&uq2,&ur2,0x80000000,m);
  ur -= ur2; uq -= uq2;
  mask = -(crypto_uint32)(ur>>15);
  ur += mask&m; uq += mask;
  *r = ur; *q = uq;
}


static crypto_uint16 int32_mod_uint14(crypto_int32 x,crypto_uint16 m)
{
  crypto_int32 q;
  crypto_uint16 r;
  int32_divmod_uint14(&q,&r,x,m);
  return r;
}
static void Decode(crypto_uint16 *out,const unsigned char *S,const crypto_uint16 *M,long long len)
{
  if (len == 1) {
    if (M[0] == 1)
      *out = 0;
    else if (M[0] <= 256)
      *out = uint32_mod_uint14(S[0],M[0]);
    else
      *out = uint32_mod_uint14(S[0]+(((crypto_uint16)S[1])<<8),M[0]);
  }
  if (len > 1) {
    crypto_uint16 R2[(len+1)/2];
    crypto_uint16 M2[(len+1)/2];
    crypto_uint16 bottomr[len/2];
    crypto_uint32 bottomt[len/2];
    long long i;
    for (i = 0;i < len-1;i += 2) {
      crypto_uint32 m = M[i]*(crypto_uint32) M[i+1];
      if (m > 256*16383) {
        bottomt[i/2] = 256*256;
        bottomr[i/2] = S[0]+256*S[1];
        S += 2;
        M2[i/2] = (((m+255)>>8)+255)>>8;
      } else if (m >= 16384) {
        bottomt[i/2] = 256;
        bottomr[i/2] = S[0];
        S += 1;
        M2[i/2] = (m+255)>>8;
      } else {
        bottomt[i/2] = 1;
        bottomr[i/2] = 0;
        M2[i/2] = m;
      }
    }
    if (i < len)
      M2[i/2] = M[i];
    Decode(R2,S,M2,(len+1)/2);
    for (i = 0;i < len-1;i += 2) {
      crypto_uint32 r = bottomr[i/2];
      crypto_uint32 r1;
      crypto_uint16 r0;
      r += bottomt[i/2]*R2[i/2];
      uint32_divmod_uint14(&r1,&r0,r,M[i]);
      r1 = uint32_mod_uint14(r1,M[i+1]);
      *out++ = r0;
      *out++ = r1;
    }
    if (i < len)
      *out++ = R2[i/2];
  }
}
static void Encode(unsigned char *out,const crypto_uint16 *R,const crypto_uint16 *M,long long len)
{
  if (len == 1) {
    crypto_uint16 r = R[0];
    crypto_uint16 m = M[0];
    while (m > 1) {
      *out++ = r;
      r >>= 8;
      m = (m+255)>>8;
    }
  }
  if (len > 1) {
    crypto_uint16 R2[(len+1)/2];
    crypto_uint16 M2[(len+1)/2];
    long long i;
    for (i = 0;i < len-1;i += 2) {
      crypto_uint32 m0 = M[i];
      crypto_uint32 r = R[i]+R[i+1]*m0;
      crypto_uint32 m = M[i+1]*m0;
      while (m >= 16384) {
        *out++ = r;
        r >>= 8;
        m = (m+255)>>8;
      }
      R2[i/2] = r;
      M2[i/2] = m;
    }
    if (i < len) {
      R2[i/2] = R[i];
      M2[i/2] = M[i];
    }
    Encode(out,R2,M2,(len+1)/2);
  }
}
static int int16_nonzero_mask(crypto_int16 x)
{
  crypto_uint16 u = x;
  crypto_uint32 v = u;
  v = -v;
  v >>= 31;
  return -v;
}




static int int16_negative_mask(crypto_int16 x)
{
  crypto_uint16 u = x;
  u >>= 15;
  return -(int) u;


}



typedef crypto_int8 small;





static small F3_freeze(crypto_int16 x)
{
  return int32_mod_uint14(x+1,3)-1;
}




typedef crypto_int16 Fq;




static Fq Fq_freeze(crypto_int32 x)
{
  return int32_mod_uint14(x+((4591 -1)/2),4591)-((4591 -1)/2);
}



static Fq Fq_recip(Fq a1)
{
  int i = 1;
  Fq ai = a1;

  while (i < 4591 -2) {
    ai = Fq_freeze(a1*(crypto_int32)ai);
    i += 1;
  }
  return ai;
}
static int Weightw_mask(small *r)
{
  int weight = 0;
  int i;

  for (i = 0;i < 761;++i) weight += r[i]&1;
  return int16_nonzero_mask(weight-286);
}


static void R3_fromRq(small *out,const Fq *r)
{
  int i;
  for (i = 0;i < 761;++i) out[i] = F3_freeze(r[i]);
}


static void R3_mult(small *h,const small *f,const small *g)
{
  small fg[761 +761 -1];
  small result;
  int i,j;

  for (i = 0;i < 761;++i) {
    result = 0;
    for (j = 0;j <= i;++j) result = F3_freeze(result+f[j]*g[i-j]);
    fg[i] = result;
  }
  for (i = 761;i < 761 +761 -1;++i) {
    result = 0;
    for (j = i-761 +1;j < 761;++j) result = F3_freeze(result+f[j]*g[i-j]);
    fg[i] = result;
  }

  for (i = 761 +761 -2;i >= 761;--i) {
    fg[i-761] = F3_freeze(fg[i-761]+fg[i]);
    fg[i-761 +1] = F3_freeze(fg[i-761 +1]+fg[i]);
  }

  for (i = 0;i < 761;++i) h[i] = fg[i];
}


static int R3_recip(small *out,const small *in)
{
  small f[761 +1],g[761 +1],v[761 +1],r[761 +1];
  int i,loop,delta;
  int sign,swap,t;

  for (i = 0;i < 761 +1;++i) v[i] = 0;
  for (i = 0;i < 761 +1;++i) r[i] = 0;
  r[0] = 1;
  for (i = 0;i < 761;++i) f[i] = 0;
  f[0] = 1; f[761 -1] = f[761] = -1;
  for (i = 0;i < 761;++i) g[761 -1-i] = in[i];
  g[761] = 0;

  delta = 1;

  for (loop = 0;loop < 2*761 -1;++loop) {
    for (i = 761;i > 0;--i) v[i] = v[i-1];
    v[0] = 0;

    sign = -g[0]*f[0];
    swap = int16_negative_mask(-delta) & int16_nonzero_mask(g[0]);
    delta ^= swap&(delta^-delta);
    delta += 1;

    for (i = 0;i < 761 +1;++i) {
      t = swap&(f[i]^g[i]); f[i] ^= t; g[i] ^= t;
      t = swap&(v[i]^r[i]); v[i] ^= t; r[i] ^= t;
    }

    for (i = 0;i < 761 +1;++i) g[i] = F3_freeze(g[i]+sign*f[i]);
    for (i = 0;i < 761 +1;++i) r[i] = F3_freeze(r[i]+sign*v[i]);

    for (i = 0;i < 761;++i) g[i] = g[i+1];
    g[761] = 0;
  }

  sign = f[0];
  for (i = 0;i < 761;++i) out[i] = sign*v[761 -1-i];

  return int16_nonzero_mask(delta);
}






static void Rq_mult_small(Fq *h,const Fq *f,const small *g)
{
  Fq fg[761 +761 -1];
  Fq result;
  int i,j;

  for (i = 0;i < 761;++i) {
    result = 0;
    for (j = 0;j <= i;++j) result = Fq_freeze(result+f[j]*(crypto_int32)g[i-j]);
    fg[i] = result;
  }
  for (i = 761;i < 761 +761 -1;++i) {
    result = 0;
    for (j = i-761 +1;j < 761;++j) result = Fq_freeze(result+f[j]*(crypto_int32)g[i-j]);
    fg[i] = result;
  }

  for (i = 761 +761 -2;i >= 761;--i) {
    fg[i-761] = Fq_freeze(fg[i-761]+fg[i]);
    fg[i-761 +1] = Fq_freeze(fg[i-761 +1]+fg[i]);
  }

  for (i = 0;i < 761;++i) h[i] = fg[i];
}




static void Rq_mult3(Fq *h,const Fq *f)
{
  int i;

  for (i = 0;i < 761;++i) h[i] = Fq_freeze(3*f[i]);
}



static int Rq_recip3(Fq *out,const small *in)
{
  Fq f[761 +1],g[761 +1],v[761 +1],r[761 +1];
  int i,loop,delta;
  int swap,t;
  crypto_int32 f0,g0;
  Fq scale;

  for (i = 0;i < 761 +1;++i) v[i] = 0;
  for (i = 0;i < 761 +1;++i) r[i] = 0;
  r[0] = Fq_recip(3);
  for (i = 0;i < 761;++i) f[i] = 0;
  f[0] = 1; f[761 -1] = f[761] = -1;
  for (i = 0;i < 761;++i) g[761 -1-i] = in[i];
  g[761] = 0;

  delta = 1;

  for (loop = 0;loop < 2*761 -1;++loop) {
    for (i = 761;i > 0;--i) v[i] = v[i-1];
    v[0] = 0;

    swap = int16_negative_mask(-delta) & int16_nonzero_mask(g[0]);
    delta ^= swap&(delta^-delta);
    delta += 1;

    for (i = 0;i < 761 +1;++i) {
      t = swap&(f[i]^g[i]); f[i] ^= t; g[i] ^= t;
      t = swap&(v[i]^r[i]); v[i] ^= t; r[i] ^= t;
    }

    f0 = f[0];
    g0 = g[0];
    for (i = 0;i < 761 +1;++i) g[i] = Fq_freeze(f0*g[i]-g0*f[i]);
    for (i = 0;i < 761 +1;++i) r[i] = Fq_freeze(f0*r[i]-g0*v[i]);

    for (i = 0;i < 761;++i) g[i] = g[i+1];
    g[761] = 0;
  }

  scale = Fq_recip(f[0]);
  for (i = 0;i < 761;++i) out[i] = Fq_freeze(scale*(crypto_int32)v[761 -1-i]);

  return int16_nonzero_mask(delta);
}





static void Round(Fq *out,const Fq *a)
{
  int i;
  for (i = 0;i < 761;++i) out[i] = a[i]-F3_freeze(a[i]);
}



static void Short_fromlist(small *out,const crypto_uint32 *in)
{
  crypto_uint32 L[761];
  int i;

  for (i = 0;i < 286;++i) L[i] = in[i]&(crypto_uint32)-2;
  for (i = 286;i < 761;++i) L[i] = (in[i]&(crypto_uint32)-3)|1;
  crypto_sort_uint32(L,761);
  for (i = 0;i < 761;++i) out[i] = (L[i]&3)-1;
}






static void Hash_prefix(unsigned char *out,int b,const unsigned char *in,int inlen)
{
  unsigned char x[inlen+1];
  unsigned char h[64];
  int i;

  x[0] = b;
  for (i = 0;i < inlen;++i) x[i+1] = in[i];
  crypto_hash_sha512(h,x,inlen+1);
  for (i = 0;i < 32;++i) out[i] = h[i];
}



static crypto_uint32 urandom32(void)
{
  unsigned char c[4];
  crypto_uint32 out[4];

  arc4random_buf((c), (4));
  out[0] = (crypto_uint32)c[0];
  out[1] = ((crypto_uint32)c[1])<<8;
  out[2] = ((crypto_uint32)c[2])<<16;
  out[3] = ((crypto_uint32)c[3])<<24;
  return out[0]+out[1]+out[2]+out[3];
}

static void Short_random(small *out)
{
  crypto_uint32 L[761];
  int i;

  for (i = 0;i < 761;++i) L[i] = urandom32();
  Short_fromlist(out,L);
}



static void Small_random(small *out)
{
  int i;

  for (i = 0;i < 761;++i) out[i] = (((urandom32()&0x3fffffff)*3)>>30)-1;
}
static void KeyGen(Fq *h,small *f,small *ginv)
{
  small g[761];
  Fq finv[761];

  for (;;) {
    Small_random(g);
    if (R3_recip(ginv,g) == 0) break;
  }
  Short_random(f);
  Rq_recip3(finv,f);
  Rq_mult_small(h,finv,g);
}


static void Encrypt(Fq *c,const small *r,const Fq *h)
{
  Fq hr[761];

  Rq_mult_small(hr,h,r);
  Round(c,hr);
}


static void Decrypt(small *r,const Fq *c,const small *f,const small *ginv)
{
  Fq cf[761];
  Fq cf3[761];
  small e[761];
  small ev[761];
  int mask;
  int i;

  Rq_mult_small(cf,c,f);
  Rq_mult3(cf3,cf);
  R3_fromRq(e,cf3);
  R3_mult(ev,e,ginv);

  mask = Weightw_mask(ev);
  for (i = 0;i < 286;++i) r[i] = ((ev[i]^1)&~mask)^1;
  for (i = 286;i < 761;++i) r[i] = ev[i]&~mask;
}
static void Small_encode(unsigned char *s,const small *f)
{
  small x;
  int i;

  for (i = 0;i < 761/4;++i) {
    x = *f++ + 1;
    x += (*f++ + 1)<<2;
    x += (*f++ + 1)<<4;
    x += (*f++ + 1)<<6;
    *s++ = x;
  }
  x = *f++ + 1;
  *s++ = x;
}

static void Small_decode(small *f,const unsigned char *s)
{
  unsigned char x;
  int i;

  for (i = 0;i < 761/4;++i) {
    x = *s++;
    *f++ = ((small)(x&3))-1; x >>= 2;
    *f++ = ((small)(x&3))-1; x >>= 2;
    *f++ = ((small)(x&3))-1; x >>= 2;
    *f++ = ((small)(x&3))-1;
  }
  x = *s++;
  *f++ = ((small)(x&3))-1;
}





static void Rq_encode(unsigned char *s,const Fq *r)
{
  crypto_uint16 R[761],M[761];
  int i;

  for (i = 0;i < 761;++i) R[i] = r[i]+((4591 -1)/2);
  for (i = 0;i < 761;++i) M[i] = 4591;
  Encode(s,R,M,761);
}

static void Rq_decode(Fq *r,const unsigned char *s)
{
  crypto_uint16 R[761],M[761];
  int i;

  for (i = 0;i < 761;++i) M[i] = 4591;
  Decode(R,s,M,761);
  for (i = 0;i < 761;++i) r[i] = ((Fq)R[i])-((4591 -1)/2);
}





static void Rounded_encode(unsigned char *s,const Fq *r)
{
  crypto_uint16 R[761],M[761];
  int i;

  for (i = 0;i < 761;++i) R[i] = ((r[i]+((4591 -1)/2))*10923)>>15;
  for (i = 0;i < 761;++i) M[i] = (4591 +2)/3;
  Encode(s,R,M,761);
}

static void Rounded_decode(Fq *r,const unsigned char *s)
{
  crypto_uint16 R[761],M[761];
  int i;

  for (i = 0;i < 761;++i) M[i] = (4591 +2)/3;
  Decode(R,s,M,761);
  for (i = 0;i < 761;++i) r[i] = R[i]*3-((4591 -1)/2);
}
typedef small Inputs[761];
static void ZKeyGen(unsigned char *pk,unsigned char *sk)
{
  Fq h[761];
  small f[761],v[761];

  KeyGen(h,f,v);
  Rq_encode(pk,h);
  Small_encode(sk,f); sk += ((761 +3)/4);
  Small_encode(sk,v);
}


static void ZEncrypt(unsigned char *C,const Inputs r,const unsigned char *pk)
{
  Fq h[761];
  Fq c[761];
  Rq_decode(h,pk);
  Encrypt(c,r,h);
  Rounded_encode(C,c);
}


static void ZDecrypt(Inputs r,const unsigned char *C,const unsigned char *sk)
{
  small f[761],v[761];
  Fq c[761];

  Small_decode(f,sk); sk += ((761 +3)/4);
  Small_decode(v,sk);
  Rounded_decode(c,C);
  Decrypt(r,c,f,v);
}
static void HashConfirm(unsigned char *h,const unsigned char *r,const unsigned char *pk,const unsigned char *cache)
{

  unsigned char x[32*2];
  int i;

  Hash_prefix(x,3,r,((761 +3)/4));
  for (i = 0;i < 32;++i) x[32 +i] = cache[i];







  Hash_prefix(h,2,x,sizeof x);
}




static void HashSession(unsigned char *k,int b,const unsigned char *y,const unsigned char *z)
{

  unsigned char x[32 +1007 +32];
  int i;

  Hash_prefix(x,3,y,((761 +3)/4));
  for (i = 0;i < 1007 +32;++i) x[32 +i] = z[i];







  Hash_prefix(k,b,x,sizeof x);
}




static void KEM_KeyGen(unsigned char *pk,unsigned char *sk)
{
  int i;

  ZKeyGen(pk,sk); sk += (2*((761 +3)/4));
  for (i = 0;i < 1158;++i) *sk++ = pk[i];
  arc4random_buf((sk), (((761 +3)/4))); sk += ((761 +3)/4);
  Hash_prefix(sk,4,pk,1158);
}


static void Hide(unsigned char *c,unsigned char *r_enc,const Inputs r,const unsigned char *pk,const unsigned char *cache)
{
  Small_encode(r_enc,r);
  ZEncrypt(c,r,pk); c += 1007;
  HashConfirm(c,r_enc,pk,cache);
}


static void Encap(unsigned char *c,unsigned char *k,const unsigned char *pk)
{
  Inputs r;
  unsigned char r_enc[((761 +3)/4)];
  unsigned char cache[32];

  Hash_prefix(cache,4,pk,1158);
  Short_random(r);
  Hide(c,r_enc,r,pk,cache);
  HashSession(k,1,r_enc,c);
}


static int Ciphertexts_diff_mask(const unsigned char *c,const unsigned char *c2)
{
  crypto_uint16 differentbits = 0;
  int len = 1007 +32;

  while (len-- > 0) differentbits |= (*c++)^(*c2++);
  return (1&((differentbits-1)>>8))-1;
}


static void Decap(unsigned char *k,const unsigned char *c,const unsigned char *sk)
{
  const unsigned char *pk = sk + (2*((761 +3)/4));
  const unsigned char *rho = pk + 1158;
  const unsigned char *cache = rho + ((761 +3)/4);
  Inputs r;
  unsigned char r_enc[((761 +3)/4)];
  unsigned char cnew[1007 +32];
  int mask;
  int i;

  ZDecrypt(r,c,sk);
  Hide(cnew,r_enc,r,pk,cache);
  mask = Ciphertexts_diff_mask(c,cnew);
  for (i = 0;i < ((761 +3)/4);++i) r_enc[i] ^= mask&(r_enc[i]^rho[i]);
  HashSession(k,1+mask,r_enc,c);
}




int crypto_kem_sntrup761_keypair(unsigned char *pk,unsigned char *sk)
{
  KEM_KeyGen(pk,sk);
  return 0;
}

int crypto_kem_sntrup761_enc(unsigned char *c,unsigned char *k,const unsigned char *pk)
{
  Encap(c,k,pk);
  return 0;
}

int crypto_kem_sntrup761_dec(unsigned char *k,const unsigned char *c,const unsigned char *sk)
{
  Decap(k,c,sk);
  return 0;
}
