











































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
static void
bcrypt_hash(uint8_t *sha2pass, uint8_t *sha2salt, uint8_t *out)
{
 blf_ctx state;
 uint8_t ciphertext[(8 * 4)] =
     "OxychromaticBlowfishSwatDynamite";
 uint32_t cdata[8];
 int i;
 uint16_t j;
 size_t shalen = 64U;


 Blowfish_initstate(&state);
 Blowfish_expandstate(&state, sha2salt, shalen, sha2pass, shalen);
 for (i = 0; i < 64; i++) {
  Blowfish_expand0state(&state, sha2salt, shalen);
  Blowfish_expand0state(&state, sha2pass, shalen);
 }


 j = 0;
 for (i = 0; i < 8; i++)
  cdata[i] = Blowfish_stream2word(ciphertext, sizeof(ciphertext),
      &j);
 for (i = 0; i < 64; i++)
  blf_enc(&state, cdata, 8 / 2);


 for (i = 0; i < 8; i++) {
  out[4 * i + 3] = (cdata[i] >> 24) & 0xff;
  out[4 * i + 2] = (cdata[i] >> 16) & 0xff;
  out[4 * i + 1] = (cdata[i] >> 8) & 0xff;
  out[4 * i + 0] = cdata[i] & 0xff;
 }


 explicit_bzero(ciphertext, sizeof(ciphertext));
 explicit_bzero(cdata, sizeof(cdata));
 explicit_bzero(&state, sizeof(state));
}

int
bcrypt_pbkdf(const char *pass, size_t passlen, const uint8_t *salt, size_t saltlen,
    uint8_t *key, size_t keylen, unsigned int rounds)
{
 uint8_t sha2pass[64U];
 uint8_t sha2salt[64U];
 uint8_t out[(8 * 4)];
 uint8_t tmpout[(8 * 4)];
 uint8_t *countsalt;
 size_t i, j, amt, stride;
 uint32_t count;
 size_t origkeylen = keylen;


 if (rounds < 1)
  goto bad;
 if (passlen == 0 || saltlen == 0 || keylen == 0 ||
     keylen > sizeof(out) * sizeof(out) || saltlen > 1<<20)
  goto bad;
 if ((countsalt = calloc(1, saltlen + 4)) == 
                                            ((void *)0)
                                                )
  goto bad;
 stride = (keylen + sizeof(out) - 1) / sizeof(out);
 amt = (keylen + stride - 1) / stride;

 memcpy(countsalt, salt, saltlen);


 crypto_hash_sha512(sha2pass, pass, passlen);


 for (count = 1; keylen > 0; count++) {
  countsalt[saltlen + 0] = (count >> 24) & 0xff;
  countsalt[saltlen + 1] = (count >> 16) & 0xff;
  countsalt[saltlen + 2] = (count >> 8) & 0xff;
  countsalt[saltlen + 3] = count & 0xff;


  crypto_hash_sha512(sha2salt, countsalt, saltlen + 4);

  bcrypt_hash(sha2pass, sha2salt, tmpout);
  memcpy(out, tmpout, sizeof(out));

  for (i = 1; i < rounds; i++) {

   crypto_hash_sha512(sha2salt, tmpout, sizeof(tmpout));
   bcrypt_hash(sha2pass, sha2salt, tmpout);
   for (j = 0; j < sizeof(out); j++)
    out[j] ^= tmpout[j];
  }




  amt = (((amt) < (keylen)) ? (amt) : (keylen));
  for (i = 0; i < amt; i++) {
   size_t dest = i * stride + (count - 1);
   if (dest >= origkeylen)
    break;
   key[dest] = out[i];
  }
  keylen -= i;
 }


 freezero(countsalt, saltlen + 4);
 explicit_bzero(out, sizeof(out));
 explicit_bzero(tmpout, sizeof(tmpout));

 return 0;

bad:

 arc4random_buf(key, keylen);
 return -1;
}
