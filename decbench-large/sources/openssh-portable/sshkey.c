











































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


const char *ssh_err(int n);
struct Forward {
 char *listen_host;
 int listen_port;
 char *listen_path;
 char *connect_host;
 int connect_port;
 char *connect_path;
 int allocated_port;
 int handle;
};

int forward_equals(const struct Forward *, const struct Forward *);
int daemonized(void);


struct ForwardOptions {
 int gateway_ports;
 mode_t streamlocal_bind_mask;
 int streamlocal_bind_unlink;
};



char *chop(char *);
void rtrim(char *);
void skip_space(char **);
char *strdelim(char **);
char *strdelimw(char **);
int set_nonblock(int);
int unset_nonblock(int);
void set_nodelay(int);
int set_reuseaddr(int);
char *get_rdomain(int);
int set_rdomain(int, const char *);
int get_sock_af(int);
void set_sock_tos(int, int);
int waitrfd(int, int *);
int timeout_connect(int, const struct sockaddr *, socklen_t, int *);
int a2port(const char *);
int a2tun(const char *, int *);
char *put_host_port(const char *, u_short);
char *hpdelim2(char **, char *);
char *hpdelim(char **);
char *cleanhostname(char *);
char *colon(char *);
int parse_user_host_path(const char *, char **, char **, char **);
int parse_user_host_port(const char *, char **, char **, int *);
int parse_uri(const char *, const char *, char **, char **, int *, char **);
int convtime(const char *);
const char *fmt_timeframe(time_t t);
int tilde_expand(const char *, uid_t, char **);
char *tilde_expand_filename(const char *, uid_t);

char *dollar_expand(int *, const char *string, ...);
char *percent_expand(const char *, ...) __attribute__(());
char *percent_dollar_expand(const char *, ...) __attribute__(());
char *tohex(const void *, size_t);
void xextendf(char **s, const char *sep, const char *fmt, ...)
    __attribute__((__format__ (printf, 3, 4))) __attribute__((__nonnull__ (3)));
void sanitise_stdfd(void);
void ms_subtract_diff(struct timeval *, int *);
void ms_to_timespec(struct timespec *, int);
void monotime_ts(struct timespec *);
void monotime_tv(struct timeval *);
time_t monotime(void);
double monotime_double(void);
void lowercase(char *s);
int unix_listener(const char *, int, int);
int valid_domain(char *, int, const char **);
int valid_env_name(const char *);
const char *atoi_err(const char *, int *);
int parse_absolute_time(const char *, uint64_t *);
void format_absolute_time(uint64_t, char *, size_t);
int path_absolute(const char *);
int stdfd_devnull(int, int, int);

void sock_set_v6only(int);

struct passwd *pwcopy(struct passwd *);
const char *ssh_gai_strerror(int);

typedef void privdrop_fn(struct passwd *);
typedef void privrestore_fn(void);





pid_t subprocess(const char *, const char *, int, char **, FILE **, u_int,
    struct passwd *, privdrop_fn *, privrestore_fn *);

typedef struct arglist arglist;
struct arglist {
 char **list;
 u_int num;
 u_int nalloc;
};
void addargs(arglist *, char *, ...)
     __attribute__((format(printf, 2, 3)));
void replacearg(arglist *, u_int, char *, ...)
     __attribute__((format(printf, 3, 4)));
void freeargs(arglist *);

int tun_open(int, int, char **);
u_int64_t get_u64(const void *)
    __attribute__(());
u_int32_t get_u32(const void *)
    __attribute__(());
u_int16_t get_u16(const void *)
    __attribute__(());
void put_u64(void *, u_int64_t)
    __attribute__(());
void put_u32(void *, u_int32_t)
    __attribute__(());
void put_u16(void *, u_int16_t)
    __attribute__(());


u_int32_t get_u32_le(const void *)
    __attribute__(());
void put_u32_le(void *, u_int32_t)
    __attribute__(());

struct bwlimit {
 size_t buflen;
 u_int64_t rate;
 u_int64_t thresh;
 u_int64_t lamt;
 struct timeval bwstart, bwend;
};

void bandwidth_limit_init(struct bwlimit *, u_int64_t, size_t);
void bandwidth_limit(struct bwlimit *, size_t);

int parse_ipqos(const char *);
const char *iptos2str(int);
void mktemp_proto(char *, size_t);

void child_set_env(char ***envp, u_int *envsizep, const char *name,
     const char *value);
const char *lookup_env_in_list(const char *env,
     char * const *envs, size_t nenvs);
const char *lookup_setenv_in_list(const char *env,
     char * const *envs, size_t nenvs);

int argv_split(const char *, int *, char ***, int);
char *argv_assemble(int, char **argv);
char *argv_next(int *, char ***);
void argv_consume(int *);
void argv_free(char **, int);

int exited_cleanly(pid_t, const char *, const char *, int);

struct stat;
int safe_path(const char *, struct stat *, const char *, uid_t,
     char *, size_t);
int safe_path_fd(int, const char *, struct passwd *,
     char *err, size_t errlen);


int opt_flag(const char *opt, int allow_negate, const char **optsp);
char *opt_dequote(const char **sp, const char **errstrp);
int opt_match(const char **opts, const char *term);


void opt_array_append(const char *file, const int line,
     const char *directive, char ***array, u_int *lp, const char *s);
void opt_array_append2(const char *file, const int line,
     const char *directive, char ***array, int **iarray, u_int *lp,
     const char *s, int i);
struct notifier_ctx;

char *read_passphrase(const char *, int);
int ask_permission(const char *, ...) __attribute__((format(printf, 1, 2)));
struct notifier_ctx *notify_start(int, const char *, ...)
 __attribute__((format(printf, 2, 3)));
void notify_complete(struct notifier_ctx *, const char *, ...)
 __attribute__((format(printf, 2, 3)));





typedef void (*sshsig_t)(int);
sshsig_t ssh_signal(int, sshsig_t);
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
struct chacha_ctx {
 u_int input[16];
};







void chacha_keysetup(struct chacha_ctx *x, const u_char *k, u_int kbits)
    __attribute__(());
void chacha_ivsetup(struct chacha_ctx *x, const u_char *iv, const u_char *ctr)
    __attribute__(())
    __attribute__(());
void chacha_encrypt_bytes(struct chacha_ctx *x, const u_char *m,
    u_char *c, u_int bytes)
    __attribute__(())
    __attribute__(());
void poly1305_auth(u_char out[16], const u_char *m, size_t inlen,
    const u_char key[32])
    __attribute__(())
    __attribute__(())
    __attribute__(());



struct chachapoly_ctx;

struct chachapoly_ctx *chachapoly_new(const u_char *key, u_int keylen)
    __attribute__(());
void chachapoly_free(struct chachapoly_ctx *cpctx);

int chachapoly_crypt(struct chachapoly_ctx *cpctx, u_int seqnr,
    u_char *dest, const u_char *src, u_int len, u_int aadlen, u_int authlen,
    int do_encrypt);
int chachapoly_get_length(struct chachapoly_ctx *cpctx,
    u_int *plenp, u_int seqnr, const u_char *cp, u_int len)
    __attribute__(());
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int rijndaelKeySetupEnc(unsigned int [], const unsigned char [], int);
void rijndaelEncrypt(const unsigned int [], int, const u8 [16], u8 [16]);


typedef struct {
 int decrypt;
 int Nr;
 u32 ek[4*(14 + 1)];
 u32 dk[4*(14 + 1)];
} rijndael_ctx;

void rijndael_set_key(rijndael_ctx *, u_char *, int, int);
void rijndael_decrypt(rijndael_ctx *, u_char *, u_char *);
void rijndael_encrypt(rijndael_ctx *, u_char *, u_char *);



typedef struct aesctr_ctx {
 int rounds;
 u32 ek[4*(14 + 1)];
 u8 ctr[16];
} aesctr_ctx;

void aesctr_keysetup(aesctr_ctx *x,const u8 *k,u32 kbits,u32 ivbits);
void aesctr_ivsetup(aesctr_ctx *x,const u8 *iv);
void aesctr_encrypt_bytes(aesctr_ctx *x,const u8 *m,u8 *c,u32 bytes);




struct sshcipher;
struct sshcipher_ctx;

const struct sshcipher *cipher_by_name(const char *);
const char *cipher_warning_message(const struct sshcipher_ctx *);
int ciphers_valid(const char *);
char *cipher_alg_list(char, int);
const char *compression_alg_list(int);
int cipher_init(struct sshcipher_ctx **, const struct sshcipher *,
    const u_char *, u_int, const u_char *, u_int, int);
int cipher_crypt(struct sshcipher_ctx *, u_int, u_char *, const u_char *,
    u_int, u_int, u_int);
int cipher_get_length(struct sshcipher_ctx *, u_int *, u_int,
    const u_char *, u_int);
void cipher_free(struct sshcipher_ctx *);
u_int cipher_blocksize(const struct sshcipher *);
u_int cipher_keylen(const struct sshcipher *);
u_int cipher_seclen(const struct sshcipher *);
u_int cipher_authlen(const struct sshcipher *);
u_int cipher_ivlen(const struct sshcipher *);
u_int cipher_is_cbc(const struct sshcipher *);

u_int cipher_ctx_is_plaintext(struct sshcipher_ctx *);

int cipher_get_keyiv(struct sshcipher_ctx *, u_char *, size_t);
int cipher_set_keyiv(struct sshcipher_ctx *, const u_char *, size_t);
int cipher_get_keyiv_len(const struct sshcipher_ctx *);
struct sshbuf;
struct ssh_digest_ctx;


int ssh_digest_alg_by_name(const char *name);


const char *ssh_digest_alg_name(int alg);


size_t ssh_digest_bytes(int alg);


size_t ssh_digest_blocksize(struct ssh_digest_ctx *ctx);


int ssh_digest_copy_state(struct ssh_digest_ctx *from,
    struct ssh_digest_ctx *to);


int ssh_digest_memory(int alg, const void *m, size_t mlen,
    u_char *d, size_t dlen)
 __attribute__(())
 __attribute__(());
int ssh_digest_buffer(int alg, const struct sshbuf *b, u_char *d, size_t dlen)
 __attribute__(());


struct ssh_digest_ctx *ssh_digest_start(int alg);
int ssh_digest_update(struct ssh_digest_ctx *ctx, const void *m, size_t mlen)
 __attribute__(());
int ssh_digest_update_buffer(struct ssh_digest_ctx *ctx,
    const struct sshbuf *b);
int ssh_digest_final(struct ssh_digest_ctx *ctx, u_char *d, size_t dlen)
 __attribute__(());
void ssh_digest_free(struct ssh_digest_ctx *ctx);

struct sshbuf;


enum sshkey_types {
 KEY_RSA,
 KEY_DSA,
 KEY_ECDSA,
 KEY_ED25519,
 KEY_RSA_CERT,
 KEY_DSA_CERT,
 KEY_ECDSA_CERT,
 KEY_ED25519_CERT,
 KEY_XMSS,
 KEY_XMSS_CERT,
 KEY_ECDSA_SK,
 KEY_ECDSA_SK_CERT,
 KEY_ED25519_SK,
 KEY_ED25519_SK_CERT,
 KEY_UNSPEC
};





enum sshkey_fp_rep {
 SSH_FP_DEFAULT = 0,
 SSH_FP_HEX,
 SSH_FP_BASE64,
 SSH_FP_BUBBLEBABBLE,
 SSH_FP_RANDOMART
};


enum sshkey_serialize_rep {
 SSHKEY_SERIALIZE_DEFAULT = 0,
 SSHKEY_SERIALIZE_STATE = 1,
 SSHKEY_SERIALIZE_FULL = 2,
 SSHKEY_SERIALIZE_SHIELD = 3,
 SSHKEY_SERIALIZE_INFO = 254,
};


enum sshkey_private_format {
 SSHKEY_PRIVATE_OPENSSH = 0,
 SSHKEY_PRIVATE_PEM = 1,
 SSHKEY_PRIVATE_PKCS8 = 2,
};






struct sshkey_cert {
 struct sshbuf *certblob;
 u_int type;
 u_int64_t serial;
 char *key_id;
 u_int nprincipals;
 char **principals;
 u_int64_t valid_after, valid_before;
 struct sshbuf *critical;
 struct sshbuf *extensions;
 struct sshkey *signature_key;
 char *signature_type;
};


struct sshkey {
 int type;
 int flags;

 RSA *rsa;

 DSA *dsa;

 int ecdsa_nid;
 EC_KEY *ecdsa;

 u_char *ed25519_sk;
 u_char *ed25519_pk;

 char *xmss_name;
 char *xmss_filename;
 void *xmss_state;
 u_char *xmss_sk;
 u_char *xmss_pk;

 char *sk_application;
 uint8_t sk_flags;
 struct sshbuf *sk_key_handle;
 struct sshbuf *sk_reserved;

 struct sshkey_cert *cert;

 u_char *shielded_private;
 size_t shielded_len;
 u_char *shield_prekey;
 size_t shield_prekey_len;
};





struct sshkey_sig_details {
 uint32_t sk_counter;
 uint8_t sk_flags;
};

struct sshkey *sshkey_new(int);
void sshkey_free(struct sshkey *);
int sshkey_equal_public(const struct sshkey *,
    const struct sshkey *);
int sshkey_equal(const struct sshkey *, const struct sshkey *);
char *sshkey_fingerprint(const struct sshkey *,
    int, enum sshkey_fp_rep);
int sshkey_fingerprint_raw(const struct sshkey *k,
    int, u_char **retp, size_t *lenp);
const char *sshkey_type(const struct sshkey *);
const char *sshkey_cert_type(const struct sshkey *);
int sshkey_format_text(const struct sshkey *, struct sshbuf *);
int sshkey_write(const struct sshkey *, FILE *);
int sshkey_read(struct sshkey *, char **);
u_int sshkey_size(const struct sshkey *);

int sshkey_generate(int type, u_int bits, struct sshkey **keyp);
int sshkey_from_private(const struct sshkey *, struct sshkey **);

int sshkey_is_shielded(struct sshkey *);
int sshkey_shield_private(struct sshkey *);
int sshkey_unshield_private(struct sshkey *);

int sshkey_type_from_name(const char *);
int sshkey_is_cert(const struct sshkey *);
int sshkey_is_sk(const struct sshkey *);
int sshkey_type_is_cert(int);
int sshkey_type_plain(int);


int sshkey_match_keyname_to_sigalgs(const char *, const char *);

int sshkey_to_certified(struct sshkey *);
int sshkey_drop_cert(struct sshkey *);
int sshkey_cert_copy(const struct sshkey *, struct sshkey *);
int sshkey_cert_check_authority(const struct sshkey *, int, int, int,
    uint64_t, const char *, const char **);
int sshkey_cert_check_authority_now(const struct sshkey *, int, int, int,
    const char *, const char **);
int sshkey_cert_check_host(const struct sshkey *, const char *,
    int , const char *, const char **);
size_t sshkey_format_cert_validity(const struct sshkey_cert *,
    char *, size_t) __attribute__(());
int sshkey_check_cert_sigtype(const struct sshkey *, const char *);

int sshkey_certify(struct sshkey *, struct sshkey *,
    const char *, const char *, const char *);

typedef int sshkey_certify_signer(struct sshkey *, u_char **, size_t *,
    const u_char *, size_t, const char *, const char *, const char *,
    u_int, void *);
int sshkey_certify_custom(struct sshkey *, struct sshkey *, const char *,
    const char *, const char *, sshkey_certify_signer *, void *);

int sshkey_ecdsa_nid_from_name(const char *);
int sshkey_curve_name_to_nid(const char *);
const char * sshkey_curve_nid_to_name(int);
u_int sshkey_curve_nid_to_bits(int);
int sshkey_ecdsa_bits_to_nid(int);
int sshkey_ecdsa_key_to_nid(EC_KEY *);
int sshkey_ec_nid_to_hash_alg(int nid);
int sshkey_ec_validate_public(const EC_GROUP *, const EC_POINT *);
int sshkey_ec_validate_private(const EC_KEY *);
const char *sshkey_ssh_name(const struct sshkey *);
const char *sshkey_ssh_name_plain(const struct sshkey *);
int sshkey_names_valid2(const char *, int);
char *sshkey_alg_list(int, int, int, char);

int sshkey_from_blob(const u_char *, size_t, struct sshkey **);
int sshkey_fromb(struct sshbuf *, struct sshkey **);
int sshkey_froms(struct sshbuf *, struct sshkey **);
int sshkey_to_blob(const struct sshkey *, u_char **, size_t *);
int sshkey_to_base64(const struct sshkey *, char **);
int sshkey_putb(const struct sshkey *, struct sshbuf *);
int sshkey_puts(const struct sshkey *, struct sshbuf *);
int sshkey_puts_opts(const struct sshkey *, struct sshbuf *,
    enum sshkey_serialize_rep);
int sshkey_plain_to_blob(const struct sshkey *, u_char **, size_t *);
int sshkey_putb_plain(const struct sshkey *, struct sshbuf *);

int sshkey_sign(struct sshkey *, u_char **, size_t *,
    const u_char *, size_t, const char *, const char *, const char *, u_int);
int sshkey_verify(const struct sshkey *, const u_char *, size_t,
    const u_char *, size_t, const char *, u_int, struct sshkey_sig_details **);
int sshkey_check_sigtype(const u_char *, size_t, const char *);
const char *sshkey_sigalg_by_name(const char *);
int sshkey_get_sigtype(const u_char *, size_t, char **);


void sshkey_dump_ec_point(const EC_GROUP *, const EC_POINT *);
void sshkey_dump_ec_key(const EC_KEY *);


int sshkey_private_serialize(struct sshkey *key, struct sshbuf *buf);
int sshkey_private_serialize_opt(struct sshkey *key, struct sshbuf *buf,
    enum sshkey_serialize_rep);
int sshkey_private_deserialize(struct sshbuf *buf, struct sshkey **keyp);


int sshkey_private_to_fileblob(struct sshkey *key, struct sshbuf *blob,
    const char *passphrase, const char *comment,
    int format, const char *openssh_format_cipher, int openssh_format_rounds);
int sshkey_parse_private_fileblob(struct sshbuf *buffer,
    const char *passphrase, struct sshkey **keyp, char **commentp);
int sshkey_parse_private_fileblob_type(struct sshbuf *blob, int type,
    const char *passphrase, struct sshkey **keyp, char **commentp);
int sshkey_parse_pubkey_from_private_fileblob_type(struct sshbuf *blob,
    int type, struct sshkey **pubkeyp);

int sshkey_check_rsa_length(const struct sshkey *, int);

int ssh_rsa_complete_crt_parameters(struct sshkey *, const BIGNUM *);


int sshkey_set_filename(struct sshkey *, const char *);
int sshkey_enable_maxsign(struct sshkey *, u_int32_t);
u_int32_t sshkey_signatures_left(const struct sshkey *);
int sshkey_forward_state(const struct sshkey *, u_int32_t, int);
int sshkey_private_serialize_maxsign(struct sshkey *key,
    struct sshbuf *buf, u_int32_t maxsign, int);

void sshkey_sig_details_free(struct sshkey_sig_details *);


int ssh_rsa_sign(const struct sshkey *key,
    u_char **sigp, size_t *lenp, const u_char *data, size_t datalen,
    const char *ident);
int ssh_rsa_verify(const struct sshkey *key,
    const u_char *sig, size_t siglen, const u_char *data, size_t datalen,
    const char *alg);
int ssh_dss_sign(const struct sshkey *key, u_char **sigp, size_t *lenp,
    const u_char *data, size_t datalen, u_int compat);
int ssh_dss_verify(const struct sshkey *key,
    const u_char *signature, size_t signaturelen,
    const u_char *data, size_t datalen, u_int compat);
int ssh_ecdsa_sign(const struct sshkey *key, u_char **sigp, size_t *lenp,
    const u_char *data, size_t datalen, u_int compat);
int ssh_ecdsa_verify(const struct sshkey *key,
    const u_char *signature, size_t signaturelen,
    const u_char *data, size_t datalen, u_int compat);
int ssh_ecdsa_sk_verify(const struct sshkey *key,
    const u_char *signature, size_t signaturelen,
    const u_char *data, size_t datalen, u_int compat,
    struct sshkey_sig_details **detailsp);
int ssh_ed25519_sign(const struct sshkey *key, u_char **sigp, size_t *lenp,
    const u_char *data, size_t datalen, u_int compat);
int ssh_ed25519_verify(const struct sshkey *key,
    const u_char *signature, size_t signaturelen,
    const u_char *data, size_t datalen, u_int compat);
int ssh_ed25519_sk_verify(const struct sshkey *key,
    const u_char *signature, size_t signaturelen,
    const u_char *data, size_t datalen, u_int compat,
    struct sshkey_sig_details **detailsp);
int ssh_xmss_sign(const struct sshkey *key, u_char **sigp, size_t *lenp,
    const u_char *data, size_t datalen, u_int compat);
int ssh_xmss_verify(const struct sshkey *key,
    const u_char *signature, size_t signaturelen,
    const u_char *data, size_t datalen, u_int compat);
int match_pattern(const char *, const char *);
int match_pattern_list(const char *, const char *, int);
int match_usergroup_pattern_list(const char *, const char *);
int match_hostname(const char *, const char *);
int match_host_and_ip(const char *, const char *, const char *);
int match_user(const char *, const char *, const char *, const char *);
char *match_list(const char *, const char *, u_int *);
char *match_filter_denylist(const char *, const char *);
char *match_filter_allowlist(const char *, const char *);


int addr_match_list(const char *, const char *);
int addr_match_cidr_list(const char *, const char *);
struct sshbuf;
struct sshkey;
struct sk_option;
struct sshsk_resident_key {
 struct sshkey *key;
 uint8_t *user_id;
 size_t user_id_len;
};
int sshsk_enroll(int type, const char *provider_path, const char *device,
    const char *application, const char *userid, uint8_t flags,
    const char *pin, struct sshbuf *challenge_buf,
    struct sshkey **keyp, struct sshbuf *attest);







int sshsk_sign(const char *provider_path, struct sshkey *key,
    u_char **sigp, size_t *lenp, const u_char *data, size_t datalen,
    u_int compat, const char *pin);







int sshsk_load_resident(const char *provider_path, const char *device,
    const char *pin, u_int flags, struct sshsk_resident_key ***srksp,
    size_t *nsrksp);


void sshsk_free_resident_keys(struct sshsk_resident_key **srks, size_t nsrks);









int ssh_compatible_openssl(long, long);
void ssh_libcrypto_init(void);
int EVP_CIPHER_CTX_set_iv(EVP_CIPHER_CTX *ctx,
    const unsigned char *iv, size_t len);
void DSA_SIG_get0(const DSA_SIG *sig, const BIGNUM **pr, const BIGNUM **ps);



int DSA_SIG_set0(DSA_SIG *sig, BIGNUM *r, BIGNUM *s);
EVP_MD_CTX *EVP_MD_CTX_new(void);



void EVP_MD_CTX_free(EVP_MD_CTX *ctx);
int sshkey_private_serialize_opt(struct sshkey *key,
    struct sshbuf *buf, enum sshkey_serialize_rep);
static int sshkey_from_blob_internal(struct sshbuf *buf,
    struct sshkey **keyp, int allow_cert);


struct keytype {
 const char *name;
 const char *shortname;
 const char *sigalg;
 int type;
 int nid;
 int cert;
 int sigonly;
};
static const struct keytype keytypes[] = {
 { "ssh-ed25519", "ED25519", 
                            ((void *)0)
                                , KEY_ED25519, 0, 0, 0 },
 { "ssh-ed25519-cert-v01@openssh.com", "ED25519-CERT", 
                                                      ((void *)0)
                                                          ,
     KEY_ED25519_CERT, 0, 1, 0 },

 { "sk-ssh-ed25519@openssh.com", "ED25519-SK", 
                                              ((void *)0)
                                                  ,
     KEY_ED25519_SK, 0, 0, 0 },
 { "sk-ssh-ed25519-cert-v01@openssh.com", "ED25519-SK-CERT", 
                                                            ((void *)0)
                                                                ,
     KEY_ED25519_SK_CERT, 0, 1, 0 },







 { "ssh-rsa", "RSA", 
                    ((void *)0)
                        , KEY_RSA, 0, 0, 0 },
 { "rsa-sha2-256", "RSA", 
                         ((void *)0)
                             , KEY_RSA, 0, 0, 1 },
 { "rsa-sha2-512", "RSA", 
                         ((void *)0)
                             , KEY_RSA, 0, 0, 1 },
 { "ssh-dss", "DSA", 
                    ((void *)0)
                        , KEY_DSA, 0, 0, 0 },

 { "ecdsa-sha2-nistp256", "ECDSA", 
                                  ((void *)0)
                                      ,
     KEY_ECDSA, 
               415
                                   , 0, 0 },
 { "ecdsa-sha2-nistp384", "ECDSA", 
                                  ((void *)0)
                                      ,
     KEY_ECDSA, 
               715
                            , 0, 0 },

 { "ecdsa-sha2-nistp521", "ECDSA", 
                                  ((void *)0)
                                      ,
     KEY_ECDSA, 
               716
                            , 0, 0 },


 { "sk-ecdsa-sha2-nistp256@openssh.com", "ECDSA-SK", 
                                                    ((void *)0)
                                                        ,
     KEY_ECDSA_SK, 
                  415
                                      , 0, 0 },
 { "webauthn-sk-ecdsa-sha2-nistp256@openssh.com", "ECDSA-SK", 
                                                             ((void *)0)
                                                                 ,
     KEY_ECDSA_SK, 
                  415
                                      , 0, 1 },


 { "ssh-rsa-cert-v01@openssh.com", "RSA-CERT", 
                                              ((void *)0)
                                                  ,
     KEY_RSA_CERT, 0, 1, 0 },
 { "rsa-sha2-256-cert-v01@openssh.com", "RSA-CERT",
     "rsa-sha2-256", KEY_RSA_CERT, 0, 1, 1 },
 { "rsa-sha2-512-cert-v01@openssh.com", "RSA-CERT",
     "rsa-sha2-512", KEY_RSA_CERT, 0, 1, 1 },
 { "ssh-dss-cert-v01@openssh.com", "DSA-CERT", 
                                              ((void *)0)
                                                  ,
     KEY_DSA_CERT, 0, 1, 0 },

 { "ecdsa-sha2-nistp256-cert-v01@openssh.com", "ECDSA-CERT", 
                                                            ((void *)0)
                                                                ,
     KEY_ECDSA_CERT, 
                    415
                                        , 1, 0 },
 { "ecdsa-sha2-nistp384-cert-v01@openssh.com", "ECDSA-CERT", 
                                                            ((void *)0)
                                                                ,
     KEY_ECDSA_CERT, 
                    715
                                 , 1, 0 },

 { "ecdsa-sha2-nistp521-cert-v01@openssh.com", "ECDSA-CERT", 
                                                            ((void *)0)
                                                                ,
     KEY_ECDSA_CERT, 
                    716
                                 , 1, 0 },


 { "sk-ecdsa-sha2-nistp256-cert-v01@openssh.com", "ECDSA-SK-CERT", 
                                                                  ((void *)0)
                                                                      ,
     KEY_ECDSA_SK_CERT, 
                       415
                                           , 1, 0 },



 { 
  ((void *)0)
      , 
        ((void *)0)
            , 
              ((void *)0)
                  , -1, -1, 0, 0 }
};

const char *
sshkey_type(const struct sshkey *k)
{
 const struct keytype *kt;

 for (kt = keytypes; kt->type != -1; kt++) {
  if (kt->type == k->type)
   return kt->shortname;
 }
 return "unknown";
}

static const char *
sshkey_ssh_name_from_type_nid(int type, int nid)
{
 const struct keytype *kt;

 for (kt = keytypes; kt->type != -1; kt++) {
  if (kt->type == type && (kt->nid == 0 || kt->nid == nid))
   return kt->name;
 }
 return "ssh-unknown";
}

int
sshkey_type_is_cert(int type)
{
 const struct keytype *kt;

 for (kt = keytypes; kt->type != -1; kt++) {
  if (kt->type == type)
   return kt->cert;
 }
 return 0;
}

const char *
sshkey_ssh_name(const struct sshkey *k)
{
 return sshkey_ssh_name_from_type_nid(k->type, k->ecdsa_nid);
}

const char *
sshkey_ssh_name_plain(const struct sshkey *k)
{
 return sshkey_ssh_name_from_type_nid(sshkey_type_plain(k->type),
     k->ecdsa_nid);
}

int
sshkey_type_from_name(const char *name)
{
 const struct keytype *kt;

 for (kt = keytypes; kt->type != -1; kt++) {

  if ((kt->name != 
                  ((void *)0) 
                       && strcmp(name, kt->name) == 0) ||
      (!kt->cert && strcasecmp(kt->shortname, name) == 0))
   return kt->type;
 }
 return KEY_UNSPEC;
}

static int
key_type_is_ecdsa_variant(int type)
{
 switch (type) {
 case KEY_ECDSA:
 case KEY_ECDSA_CERT:
 case KEY_ECDSA_SK:
 case KEY_ECDSA_SK_CERT:
  return 1;
 }
 return 0;
}

int
sshkey_ecdsa_nid_from_name(const char *name)
{
 const struct keytype *kt;

 for (kt = keytypes; kt->type != -1; kt++) {
  if (!key_type_is_ecdsa_variant(kt->type))
   continue;
  if (kt->name != 
                 ((void *)0) 
                      && strcmp(name, kt->name) == 0)
   return kt->nid;
 }
 return -1;
}

int
sshkey_match_keyname_to_sigalgs(const char *keyname, const char *sigalgs)
{
 int ktype;

 if (sigalgs == 
               ((void *)0) 
                    || *sigalgs == '\0' ||
     (ktype = sshkey_type_from_name(keyname)) == KEY_UNSPEC)
  return 0;
 else if (ktype == KEY_RSA) {
  return match_pattern_list("ssh-rsa", sigalgs, 0) == 1 ||
      match_pattern_list("rsa-sha2-256", sigalgs, 0) == 1 ||
      match_pattern_list("rsa-sha2-512", sigalgs, 0) == 1;
 } else if (ktype == KEY_RSA_CERT) {
  return match_pattern_list("ssh-rsa-cert-v01@openssh.com",
      sigalgs, 0) == 1 ||
      match_pattern_list("rsa-sha2-256-cert-v01@openssh.com",
      sigalgs, 0) == 1 ||
      match_pattern_list("rsa-sha2-512-cert-v01@openssh.com",
      sigalgs, 0) == 1;
 } else
  return match_pattern_list(keyname, sigalgs, 0) == 1;
}

char *
sshkey_alg_list(int certs_only, int plain_only, int include_sigonly, char sep)
{
 char *tmp, *ret = 
                  ((void *)0)
                      ;
 size_t nlen, rlen = 0;
 const struct keytype *kt;

 for (kt = keytypes; kt->type != -1; kt++) {
  if (kt->name == 
                 ((void *)0)
                     )
   continue;
  if (!include_sigonly && kt->sigonly)
   continue;
  if ((certs_only && !kt->cert) || (plain_only && kt->cert))
   continue;
  if (ret != 
            ((void *)0)
                )
   ret[rlen++] = sep;
  nlen = strlen(kt->name);
  if ((tmp = realloc(ret, rlen + nlen + 2)) == 
                                              ((void *)0)
                                                  ) {
   free(ret);
   return 
         ((void *)0)
             ;
  }
  ret = tmp;
  memcpy(ret + rlen, kt->name, nlen + 1);
  rlen += nlen;
 }
 return ret;
}

int
sshkey_names_valid2(const char *names, int allow_wildcard)
{
 char *s, *cp, *p;
 const struct keytype *kt;
 int type;

 if (names == 
             ((void *)0) 
                  || strcmp(names, "") == 0)
  return 0;
 if ((s = cp = strdup(names)) == 
                                ((void *)0)
                                    )
  return 0;
 for ((p = strsep(&cp, ",")); p && *p != '\0';
     (p = strsep(&cp, ","))) {
  type = sshkey_type_from_name(p);
  if (type == KEY_UNSPEC) {
   if (allow_wildcard) {





    for (kt = keytypes; kt->type != -1; kt++) {
     if (match_pattern_list(kt->name,
         p, 0) != 0)
      break;
    }
    if (kt->type != -1)
     continue;
   }
   free(s);
   return 0;
  }
 }
 free(s);
 return 1;
}

u_int
sshkey_size(const struct sshkey *k)
{

 const BIGNUM *rsa_n, *dsa_p;


 switch (k->type) {

 case KEY_RSA:
 case KEY_RSA_CERT:
  if (k->rsa == 
               ((void *)0)
                   )
   return 0;
  RSA_get0_key(k->rsa, &rsa_n, 
                              ((void *)0)
                                  , 
                                    ((void *)0)
                                        );
  return BN_num_bits(rsa_n);
 case KEY_DSA:
 case KEY_DSA_CERT:
  if (k->dsa == 
               ((void *)0)
                   )
   return 0;
  DSA_get0_pqg(k->dsa, &dsa_p, 
                              ((void *)0)
                                  , 
                                    ((void *)0)
                                        );
  return BN_num_bits(dsa_p);
 case KEY_ECDSA:
 case KEY_ECDSA_CERT:
 case KEY_ECDSA_SK:
 case KEY_ECDSA_SK_CERT:
  return sshkey_curve_nid_to_bits(k->ecdsa_nid);

 case KEY_ED25519:
 case KEY_ED25519_CERT:
 case KEY_ED25519_SK:
 case KEY_ED25519_SK_CERT:
 case KEY_XMSS:
 case KEY_XMSS_CERT:
  return 256;
 }
 return 0;
}

static int
sshkey_type_is_valid_ca(int type)
{
 switch (type) {
 case KEY_RSA:
 case KEY_DSA:
 case KEY_ECDSA:
 case KEY_ECDSA_SK:
 case KEY_ED25519:
 case KEY_ED25519_SK:
 case KEY_XMSS:
  return 1;
 default:
  return 0;
 }
}

int
sshkey_is_cert(const struct sshkey *k)
{
 if (k == 
         ((void *)0)
             )
  return 0;
 return sshkey_type_is_cert(k->type);
}

int
sshkey_is_sk(const struct sshkey *k)
{
 if (k == 
         ((void *)0)
             )
  return 0;
 switch (sshkey_type_plain(k->type)) {
 case KEY_ECDSA_SK:
 case KEY_ED25519_SK:
  return 1;
 default:
  return 0;
 }
}


int
sshkey_type_plain(int type)
{
 switch (type) {
 case KEY_RSA_CERT:
  return KEY_RSA;
 case KEY_DSA_CERT:
  return KEY_DSA;
 case KEY_ECDSA_CERT:
  return KEY_ECDSA;
 case KEY_ECDSA_SK_CERT:
  return KEY_ECDSA_SK;
 case KEY_ED25519_CERT:
  return KEY_ED25519;
 case KEY_ED25519_SK_CERT:
  return KEY_ED25519_SK;
 case KEY_XMSS_CERT:
  return KEY_XMSS;
 default:
  return type;
 }
}



int
sshkey_curve_name_to_nid(const char *name)
{
 if (strcmp(name, "nistp256") == 0)
  return 
        415
                            ;
 else if (strcmp(name, "nistp384") == 0)
  return 
        715
                     ;

 else if (strcmp(name, "nistp521") == 0)
  return 
        716
                     ;

 else
  return -1;
}

u_int
sshkey_curve_nid_to_bits(int nid)
{
 switch (nid) {
 case 
     415
                         :
  return 256;
 case 
     715
                  :
  return 384;

 case 
     716
                  :
  return 521;

 default:
  return 0;
 }
}

int
sshkey_ecdsa_bits_to_nid(int bits)
{
 switch (bits) {
 case 256:
  return 
        415
                            ;
 case 384:
  return 
        715
                     ;

 case 521:
  return 
        716
                     ;

 default:
  return -1;
 }
}

const char *
sshkey_curve_nid_to_name(int nid)
{
 switch (nid) {
 case 
     415
                         :
  return "nistp256";
 case 
     715
                  :
  return "nistp384";

 case 
     716
                  :
  return "nistp521";

 default:
  return 
        ((void *)0)
            ;
 }
}

int
sshkey_ec_nid_to_hash_alg(int nid)
{
 int kbits = sshkey_curve_nid_to_bits(nid);

 if (kbits <= 0)
  return -1;


 if (kbits <= 256)
  return 2;
 else if (kbits <= 384)
  return 3;
 else
  return 4;
}


static void
cert_free(struct sshkey_cert *cert)
{
 u_int i;

 if (cert == 
            ((void *)0)
                )
  return;
 sshbuf_free(cert->certblob);
 sshbuf_free(cert->critical);
 sshbuf_free(cert->extensions);
 free(cert->key_id);
 for (i = 0; i < cert->nprincipals; i++)
  free(cert->principals[i]);
 free(cert->principals);
 sshkey_free(cert->signature_key);
 free(cert->signature_type);
 freezero(cert, sizeof(*cert));
}

static struct sshkey_cert *
cert_new(void)
{
 struct sshkey_cert *cert;

 if ((cert = calloc(1, sizeof(*cert))) == 
                                         ((void *)0)
                                             )
  return 
        ((void *)0)
            ;
 if ((cert->certblob = sshbuf_new()) == 
                                       ((void *)0) 
                                            ||
     (cert->critical = sshbuf_new()) == 
                                       ((void *)0) 
                                            ||
     (cert->extensions = sshbuf_new()) == 
                                         ((void *)0)
                                             ) {
  cert_free(cert);
  return 
        ((void *)0)
            ;
 }
 cert->key_id = 
               ((void *)0)
                   ;
 cert->principals = 
                   ((void *)0)
                       ;
 cert->signature_key = 
                      ((void *)0)
                          ;
 cert->signature_type = 
                       ((void *)0)
                           ;
 return cert;
}

struct sshkey *
sshkey_new(int type)
{
 struct sshkey *k;

 RSA *rsa;
 DSA *dsa;


 if ((k = calloc(1, sizeof(*k))) == 
                                   ((void *)0)
                                       )
  return 
        ((void *)0)
            ;
 k->type = type;
 k->ecdsa = 
           ((void *)0)
               ;
 k->ecdsa_nid = -1;
 k->dsa = 
         ((void *)0)
             ;
 k->rsa = 
         ((void *)0)
             ;
 k->cert = 
          ((void *)0)
              ;
 k->ed25519_sk = 
                ((void *)0)
                    ;
 k->ed25519_pk = 
                ((void *)0)
                    ;
 k->xmss_sk = 
             ((void *)0)
                 ;
 k->xmss_pk = 
             ((void *)0)
                 ;
 switch (k->type) {

 case KEY_RSA:
 case KEY_RSA_CERT:
  if ((rsa = RSA_new()) == 
                          ((void *)0)
                              ) {
   free(k);
   return 
         ((void *)0)
             ;
  }
  k->rsa = rsa;
  break;
 case KEY_DSA:
 case KEY_DSA_CERT:
  if ((dsa = DSA_new()) == 
                          ((void *)0)
                              ) {
   free(k);
   return 
         ((void *)0)
             ;
  }
  k->dsa = dsa;
  break;
 case KEY_ECDSA:
 case KEY_ECDSA_CERT:
 case KEY_ECDSA_SK:
 case KEY_ECDSA_SK_CERT:

  break;

 case KEY_ED25519:
 case KEY_ED25519_CERT:
 case KEY_ED25519_SK:
 case KEY_ED25519_SK_CERT:
 case KEY_XMSS:
 case KEY_XMSS_CERT:

  break;
 case KEY_UNSPEC:
  break;
 default:
  free(k);
  return 
        ((void *)0)
            ;
 }

 if (sshkey_is_cert(k)) {
  if ((k->cert = cert_new()) == 
                               ((void *)0)
                                   ) {
   sshkey_free(k);
   return 
         ((void *)0)
             ;
  }
 }

 return k;
}

void
sshkey_free(struct sshkey *k)
{
 if (k == 
         ((void *)0)
             )
  return;
 switch (k->type) {

 case KEY_RSA:
 case KEY_RSA_CERT:
  RSA_free(k->rsa);
  k->rsa = 
          ((void *)0)
              ;
  break;
 case KEY_DSA:
 case KEY_DSA_CERT:
  DSA_free(k->dsa);
  k->dsa = 
          ((void *)0)
              ;
  break;

 case KEY_ECDSA_SK:
 case KEY_ECDSA_SK_CERT:
  free(k->sk_application);
  sshbuf_free(k->sk_key_handle);
  sshbuf_free(k->sk_reserved);

 case KEY_ECDSA:
 case KEY_ECDSA_CERT:
  EC_KEY_free(k->ecdsa);
  k->ecdsa = 
            ((void *)0)
                ;
  break;


 case KEY_ED25519_SK:
 case KEY_ED25519_SK_CERT:
  free(k->sk_application);
  sshbuf_free(k->sk_key_handle);
  sshbuf_free(k->sk_reserved);

 case KEY_ED25519:
 case KEY_ED25519_CERT:
  freezero(k->ed25519_pk, 32U);
  k->ed25519_pk = 
                 ((void *)0)
                     ;
  freezero(k->ed25519_sk, 64U);
  k->ed25519_sk = 
                 ((void *)0)
                     ;
  break;
 case KEY_UNSPEC:
  break;
 default:
  break;
 }
 if (sshkey_is_cert(k))
  cert_free(k->cert);
 freezero(k->shielded_private, k->shielded_len);
 freezero(k->shield_prekey, k->shield_prekey_len);
 freezero(k, sizeof(*k));
}

static int
cert_compare(struct sshkey_cert *a, struct sshkey_cert *b)
{
 if (a == 
         ((void *)0) 
              && b == 
                      ((void *)0)
                          )
  return 1;
 if (a == 
         ((void *)0) 
              || b == 
                      ((void *)0)
                          )
  return 0;
 if (sshbuf_len(a->certblob) != sshbuf_len(b->certblob))
  return 0;
 if (timingsafe_bcmp(sshbuf_ptr(a->certblob), sshbuf_ptr(b->certblob),
     sshbuf_len(a->certblob)) != 0)
  return 0;
 return 1;
}





int
sshkey_equal_public(const struct sshkey *a, const struct sshkey *b)
{

 const BIGNUM *rsa_e_a, *rsa_n_a;
 const BIGNUM *rsa_e_b, *rsa_n_b;
 const BIGNUM *dsa_p_a, *dsa_q_a, *dsa_g_a, *dsa_pub_key_a;
 const BIGNUM *dsa_p_b, *dsa_q_b, *dsa_g_b, *dsa_pub_key_b;


 if (a == 
         ((void *)0) 
              || b == 
                      ((void *)0) 
                           ||
     sshkey_type_plain(a->type) != sshkey_type_plain(b->type))
  return 0;

 switch (a->type) {

 case KEY_RSA_CERT:
 case KEY_RSA:
  if (a->rsa == 
               ((void *)0) 
                    || b->rsa == 
                                 ((void *)0)
                                     )
   return 0;
  RSA_get0_key(a->rsa, &rsa_n_a, &rsa_e_a, 
                                          ((void *)0)
                                              );
  RSA_get0_key(b->rsa, &rsa_n_b, &rsa_e_b, 
                                          ((void *)0)
                                              );
  return BN_cmp(rsa_e_a, rsa_e_b) == 0 &&
      BN_cmp(rsa_n_a, rsa_n_b) == 0;
 case KEY_DSA_CERT:
 case KEY_DSA:
  if (a->dsa == 
               ((void *)0) 
                    || b->dsa == 
                                 ((void *)0)
                                     )
   return 0;
  DSA_get0_pqg(a->dsa, &dsa_p_a, &dsa_q_a, &dsa_g_a);
  DSA_get0_pqg(b->dsa, &dsa_p_b, &dsa_q_b, &dsa_g_b);
  DSA_get0_key(a->dsa, &dsa_pub_key_a, 
                                      ((void *)0)
                                          );
  DSA_get0_key(b->dsa, &dsa_pub_key_b, 
                                      ((void *)0)
                                          );
  return BN_cmp(dsa_p_a, dsa_p_b) == 0 &&
      BN_cmp(dsa_q_a, dsa_q_b) == 0 &&
      BN_cmp(dsa_g_a, dsa_g_b) == 0 &&
      BN_cmp(dsa_pub_key_a, dsa_pub_key_b) == 0;

 case KEY_ECDSA_SK:
 case KEY_ECDSA_SK_CERT:
  if (a->sk_application == 
                          ((void *)0) 
                               || b->sk_application == 
                                                       ((void *)0)
                                                           )
   return 0;
  if (strcmp(a->sk_application, b->sk_application) != 0)
   return 0;

 case KEY_ECDSA_CERT:
 case KEY_ECDSA:
  if (a->ecdsa == 
                 ((void *)0) 
                      || b->ecdsa == 
                                     ((void *)0) 
                                          ||
      EC_KEY_get0_public_key(a->ecdsa) == 
                                         ((void *)0) 
                                              ||
      EC_KEY_get0_public_key(b->ecdsa) == 
                                         ((void *)0)
                                             )
   return 0;
  if (EC_GROUP_cmp(EC_KEY_get0_group(a->ecdsa),
      EC_KEY_get0_group(b->ecdsa), 
                                  ((void *)0)
                                      ) != 0 ||
      EC_POINT_cmp(EC_KEY_get0_group(a->ecdsa),
      EC_KEY_get0_public_key(a->ecdsa),
      EC_KEY_get0_public_key(b->ecdsa), 
                                       ((void *)0)
                                           ) != 0)
   return 0;
  return 1;


 case KEY_ED25519_SK:
 case KEY_ED25519_SK_CERT:
  if (a->sk_application == 
                          ((void *)0) 
                               || b->sk_application == 
                                                       ((void *)0)
                                                           )
   return 0;
  if (strcmp(a->sk_application, b->sk_application) != 0)
   return 0;

 case KEY_ED25519:
 case KEY_ED25519_CERT:
  return a->ed25519_pk != 
                         ((void *)0) 
                              && b->ed25519_pk != 
                                                  ((void *)0) 
                                                       &&
      memcmp(a->ed25519_pk, b->ed25519_pk, 32U) == 0;







 default:
  return 0;
 }

}

int
sshkey_equal(const struct sshkey *a, const struct sshkey *b)
{
 if (a == 
         ((void *)0) 
              || b == 
                      ((void *)0) 
                           || a->type != b->type)
  return 0;
 if (sshkey_is_cert(a)) {
  if (!cert_compare(a->cert, b->cert))
   return 0;
 }
 return sshkey_equal_public(a, b);
}

static int
to_blob_buf(const struct sshkey *key, struct sshbuf *b, int force_plain,
  enum sshkey_serialize_rep opts)
{
 int type, ret = -1;
 const char *typename;

 const BIGNUM *rsa_n, *rsa_e, *dsa_p, *dsa_q, *dsa_g, *dsa_pub_key;


 if (key == 
           ((void *)0)
               )
  return -10;

 if (sshkey_is_cert(key)) {
  if (key->cert == 
                  ((void *)0)
                      )
   return -16;
  if (sshbuf_len(key->cert->certblob) == 0)
   return -17;
 }
 type = force_plain ? sshkey_type_plain(key->type) : key->type;
 typename = sshkey_ssh_name_from_type_nid(type, key->ecdsa_nid);

 switch (type) {

 case KEY_DSA_CERT:
 case KEY_ECDSA_CERT:
 case KEY_ECDSA_SK_CERT:
 case KEY_RSA_CERT:

 case KEY_ED25519_CERT:
 case KEY_ED25519_SK_CERT:





  if ((ret = sshbuf_putb(b, key->cert->certblob)) != 0)
   return ret;
  break;

 case KEY_DSA:
  if (key->dsa == 
                 ((void *)0)
                     )
   return -10;
  DSA_get0_pqg(key->dsa, &dsa_p, &dsa_q, &dsa_g);
  DSA_get0_key(key->dsa, &dsa_pub_key, 
                                      ((void *)0)
                                          );
  if ((ret = sshbuf_put_cstring(b, typename)) != 0 ||
      (ret = sshbuf_put_bignum2(b, dsa_p)) != 0 ||
      (ret = sshbuf_put_bignum2(b, dsa_q)) != 0 ||
      (ret = sshbuf_put_bignum2(b, dsa_g)) != 0 ||
      (ret = sshbuf_put_bignum2(b, dsa_pub_key)) != 0)
   return ret;
  break;

 case KEY_ECDSA:
 case KEY_ECDSA_SK:
  if (key->ecdsa == 
                   ((void *)0)
                       )
   return -10;
  if ((ret = sshbuf_put_cstring(b, typename)) != 0 ||
      (ret = sshbuf_put_cstring(b,
      sshkey_curve_nid_to_name(key->ecdsa_nid))) != 0 ||
      (ret = sshbuf_put_eckey(b, key->ecdsa)) != 0)
   return ret;
  if (type == KEY_ECDSA_SK) {
   if ((ret = sshbuf_put_cstring(b,
       key->sk_application)) != 0)
    return ret;
  }
  break;

 case KEY_RSA:
  if (key->rsa == 
                 ((void *)0)
                     )
   return -10;
  RSA_get0_key(key->rsa, &rsa_n, &rsa_e, 
                                        ((void *)0)
                                            );
  if ((ret = sshbuf_put_cstring(b, typename)) != 0 ||
      (ret = sshbuf_put_bignum2(b, rsa_e)) != 0 ||
      (ret = sshbuf_put_bignum2(b, rsa_n)) != 0)
   return ret;
  break;

 case KEY_ED25519:
 case KEY_ED25519_SK:
  if (key->ed25519_pk == 
                        ((void *)0)
                            )
   return -10;
  if ((ret = sshbuf_put_cstring(b, typename)) != 0 ||
      (ret = sshbuf_put_string(b,
      key->ed25519_pk, 32U)) != 0)
   return ret;
  if (type == KEY_ED25519_SK) {
   if ((ret = sshbuf_put_cstring(b,
       key->sk_application)) != 0)
    return ret;
  }
  break;
 default:
  return -14;
 }
 return 0;
}

int
sshkey_putb(const struct sshkey *key, struct sshbuf *b)
{
 return to_blob_buf(key, b, 0, SSHKEY_SERIALIZE_DEFAULT);
}

int
sshkey_puts_opts(const struct sshkey *key, struct sshbuf *b,
    enum sshkey_serialize_rep opts)
{
 struct sshbuf *tmp;
 int r;

 if ((tmp = sshbuf_new()) == 
                            ((void *)0)
                                )
  return -2;
 r = to_blob_buf(key, tmp, 0, opts);
 if (r == 0)
  r = sshbuf_put_stringb(b, tmp);
 sshbuf_free(tmp);
 return r;
}

int
sshkey_puts(const struct sshkey *key, struct sshbuf *b)
{
 return sshkey_puts_opts(key, b, SSHKEY_SERIALIZE_DEFAULT);
}

int
sshkey_putb_plain(const struct sshkey *key, struct sshbuf *b)
{
 return to_blob_buf(key, b, 1, SSHKEY_SERIALIZE_DEFAULT);
}

static int
to_blob(const struct sshkey *key, u_char **blobp, size_t *lenp, int force_plain,
    enum sshkey_serialize_rep opts)
{
 int ret = -1;
 size_t len;
 struct sshbuf *b = 
                   ((void *)0)
                       ;

 if (lenp != 
            ((void *)0)
                )
  *lenp = 0;
 if (blobp != 
             ((void *)0)
                 )
  *blobp = 
          ((void *)0)
              ;
 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              )
  return -2;
 if ((ret = to_blob_buf(key, b, force_plain, opts)) != 0)
  goto out;
 len = sshbuf_len(b);
 if (lenp != 
            ((void *)0)
                )
  *lenp = len;
 if (blobp != 
             ((void *)0)
                 ) {
  if ((*blobp = malloc(len)) == 
                               ((void *)0)
                                   ) {
   ret = -2;
   goto out;
  }
  memcpy(*blobp, sshbuf_ptr(b), len);
 }
 ret = 0;
 out:
 sshbuf_free(b);
 return ret;
}

int
sshkey_to_blob(const struct sshkey *key, u_char **blobp, size_t *lenp)
{
 return to_blob(key, blobp, lenp, 0, SSHKEY_SERIALIZE_DEFAULT);
}

int
sshkey_plain_to_blob(const struct sshkey *key, u_char **blobp, size_t *lenp)
{
 return to_blob(key, blobp, lenp, 1, SSHKEY_SERIALIZE_DEFAULT);
}

int
sshkey_fingerprint_raw(const struct sshkey *k, int dgst_alg,
    u_char **retp, size_t *lenp)
{
 u_char *blob = 
               ((void *)0)
                   , *ret = 
                            ((void *)0)
                                ;
 size_t blob_len = 0;
 int r = -1;

 if (retp != 
            ((void *)0)
                )
  *retp = 
         ((void *)0)
             ;
 if (lenp != 
            ((void *)0)
                )
  *lenp = 0;
 if (ssh_digest_bytes(dgst_alg) == 0) {
  r = -10;
  goto out;
 }
 if ((r = to_blob(k, &blob, &blob_len, 1, SSHKEY_SERIALIZE_DEFAULT))
     != 0)
  goto out;
 if ((ret = calloc(1, 64)) == 
                                                ((void *)0)
                                                    ) {
  r = -2;
  goto out;
 }
 if ((r = ssh_digest_memory(dgst_alg, blob, blob_len,
     ret, 64)) != 0)
  goto out;

 if (retp != 
            ((void *)0)
                ) {
  *retp = ret;
  ret = 
       ((void *)0)
           ;
 }
 if (lenp != 
            ((void *)0)
                )
  *lenp = ssh_digest_bytes(dgst_alg);
 r = 0;
 out:
 free(ret);
 if (blob != 
            ((void *)0)
                )
  freezero(blob, blob_len);
 return r;
}

static char *
fingerprint_b64(const char *alg, u_char *dgst_raw, size_t dgst_raw_len)
{
 char *ret;
 size_t plen = strlen(alg) + 1;
 size_t rlen = ((dgst_raw_len + 2) / 3) * 4 + plen + 1;

 if (dgst_raw_len > 65536 || (ret = calloc(1, rlen)) == 
                                                       ((void *)0)
                                                           )
  return 
        ((void *)0)
            ;
 strlcpy(ret, alg, rlen);
 strlcat(ret, ":", rlen);
 if (dgst_raw_len == 0)
  return ret;
 if (
    __b64_ntop
    (dgst_raw,dgst_raw_len,ret + plen,rlen - plen) == -1) {
  freezero(ret, rlen);
  return 
        ((void *)0)
            ;
 }

 ret[strcspn(ret, "=")] = '\0';
 return ret;
}

static char *
fingerprint_hex(const char *alg, u_char *dgst_raw, size_t dgst_raw_len)
{
 char *retval, hex[5];
 size_t i, rlen = dgst_raw_len * 3 + strlen(alg) + 2;

 if (dgst_raw_len > 65536 || (retval = calloc(1, rlen)) == 
                                                          ((void *)0)
                                                              )
  return 
        ((void *)0)
            ;
 strlcpy(retval, alg, rlen);
 strlcat(retval, ":", rlen);
 for (i = 0; i < dgst_raw_len; i++) {
  snprintf(hex, sizeof(hex), "%s%02x",
      i > 0 ? ":" : "", dgst_raw[i]);
  strlcat(retval, hex, rlen);
 }
 return retval;
}

static char *
fingerprint_bubblebabble(u_char *dgst_raw, size_t dgst_raw_len)
{
 char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'y' };
 char consonants[] = { 'b', 'c', 'd', 'f', 'g', 'h', 'k', 'l', 'm',
     'n', 'p', 'r', 's', 't', 'v', 'z', 'x' };
 u_int i, j = 0, rounds, seed = 1;
 char *retval;

 rounds = (dgst_raw_len / 2) + 1;
 if ((retval = calloc(rounds, 6)) == 
                                    ((void *)0)
                                        )
  return 
        ((void *)0)
            ;
 retval[j++] = 'x';
 for (i = 0; i < rounds; i++) {
  u_int idx0, idx1, idx2, idx3, idx4;
  if ((i + 1 < rounds) || (dgst_raw_len % 2 != 0)) {
   idx0 = (((((u_int)(dgst_raw[2 * i])) >> 6) & 3) +
       seed) % 6;
   idx1 = (((u_int)(dgst_raw[2 * i])) >> 2) & 15;
   idx2 = ((((u_int)(dgst_raw[2 * i])) & 3) +
       (seed / 6)) % 6;
   retval[j++] = vowels[idx0];
   retval[j++] = consonants[idx1];
   retval[j++] = vowels[idx2];
   if ((i + 1) < rounds) {
    idx3 = (((u_int)(dgst_raw[(2 * i) + 1])) >> 4) & 15;
    idx4 = (((u_int)(dgst_raw[(2 * i) + 1]))) & 15;
    retval[j++] = consonants[idx3];
    retval[j++] = '-';
    retval[j++] = consonants[idx4];
    seed = ((seed * 5) +
        ((((u_int)(dgst_raw[2 * i])) * 7) +
        ((u_int)(dgst_raw[(2 * i) + 1])))) % 36;
   }
  } else {
   idx0 = seed % 6;
   idx1 = 16;
   idx2 = seed / 6;
   retval[j++] = vowels[idx0];
   retval[j++] = consonants[idx1];
   retval[j++] = vowels[idx2];
  }
 }
 retval[j++] = 'x';
 retval[j++] = '\0';
 return retval;
}
static char *
fingerprint_randomart(const char *alg, u_char *dgst_raw, size_t dgst_raw_len,
    const struct sshkey *k)
{




 char *augmentation_string = " .o+=*BOX@%&#/^SE";
 char *retval, *p, title[(8 * 2 + 1)], hash[(8 * 2 + 1)];
 u_char field[(8 * 2 + 1)][(8 + 1)];
 size_t i, tlen, hlen;
 u_int b;
 int x, y, r;
 size_t len = strlen(augmentation_string) - 1;

 if ((retval = calloc(((8 * 2 + 1) + 3), ((8 + 1) + 2))) == 
                                                           ((void *)0)
                                                               )
  return 
        ((void *)0)
            ;


 memset(field, 0, (8 * 2 + 1) * (8 + 1) * sizeof(char));
 x = (8 * 2 + 1) / 2;
 y = (8 + 1) / 2;


 for (i = 0; i < dgst_raw_len; i++) {
  int input;

  input = dgst_raw[i];
  for (b = 0; b < 4; b++) {

   x += (input & 0x1) ? 1 : -1;
   y += (input & 0x2) ? 1 : -1;


   x = (((x) > (0)) ? (x) : (0));
   y = (((y) > (0)) ? (y) : (0));
   x = (((x) < ((8 * 2 + 1) - 1)) ? (x) : ((8 * 2 + 1) - 1));
   y = (((y) < ((8 + 1) - 1)) ? (y) : ((8 + 1) - 1));


   if (field[x][y] < len - 2)
    field[x][y]++;
   input = input >> 2;
  }
 }


 field[(8 * 2 + 1) / 2][(8 + 1) / 2] = len - 1;
 field[x][y] = len;


 r = snprintf(title, sizeof(title), "[%s %u]",
  sshkey_type(k), sshkey_size(k));

 if (r < 0 || r > (int)sizeof(title))
  r = snprintf(title, sizeof(title), "[%s]", sshkey_type(k));
 tlen = (r <= 0) ? 0 : strlen(title);


 r = snprintf(hash, sizeof(hash), "[%s]", alg);
 hlen = (r <= 0) ? 0 : strlen(hash);


 p = retval;
 *p++ = '+';
 for (i = 0; i < ((8 * 2 + 1) - tlen) / 2; i++)
  *p++ = '-';
 memcpy(p, title, tlen);
 p += tlen;
 for (i += tlen; i < (8 * 2 + 1); i++)
  *p++ = '-';
 *p++ = '+';
 *p++ = '\n';


 for (y = 0; y < (8 + 1); y++) {
  *p++ = '|';
  for (x = 0; x < (8 * 2 + 1); x++)
   *p++ = augmentation_string[(((field[x][y]) < (len)) ? (field[x][y]) : (len))];
  *p++ = '|';
  *p++ = '\n';
 }


 *p++ = '+';
 for (i = 0; i < ((8 * 2 + 1) - hlen) / 2; i++)
  *p++ = '-';
 memcpy(p, hash, hlen);
 p += hlen;
 for (i += hlen; i < (8 * 2 + 1); i++)
  *p++ = '-';
 *p++ = '+';

 return retval;
}

char *
sshkey_fingerprint(const struct sshkey *k, int dgst_alg,
    enum sshkey_fp_rep dgst_rep)
{
 char *retval = 
               ((void *)0)
                   ;
 u_char *dgst_raw;
 size_t dgst_raw_len;

 if (sshkey_fingerprint_raw(k, dgst_alg, &dgst_raw, &dgst_raw_len) != 0)
  return 
        ((void *)0)
            ;
 switch (dgst_rep) {
 case SSH_FP_DEFAULT:
  if (dgst_alg == 0) {
   retval = fingerprint_hex(ssh_digest_alg_name(dgst_alg),
       dgst_raw, dgst_raw_len);
  } else {
   retval = fingerprint_b64(ssh_digest_alg_name(dgst_alg),
       dgst_raw, dgst_raw_len);
  }
  break;
 case SSH_FP_HEX:
  retval = fingerprint_hex(ssh_digest_alg_name(dgst_alg),
      dgst_raw, dgst_raw_len);
  break;
 case SSH_FP_BASE64:
  retval = fingerprint_b64(ssh_digest_alg_name(dgst_alg),
      dgst_raw, dgst_raw_len);
  break;
 case SSH_FP_BUBBLEBABBLE:
  retval = fingerprint_bubblebabble(dgst_raw, dgst_raw_len);
  break;
 case SSH_FP_RANDOMART:
  retval = fingerprint_randomart(ssh_digest_alg_name(dgst_alg),
      dgst_raw, dgst_raw_len, k);
  break;
 default:
  freezero(dgst_raw, dgst_raw_len);
  return 
        ((void *)0)
            ;
 }
 freezero(dgst_raw, dgst_raw_len);
 return retval;
}

static int
peek_type_nid(const char *s, size_t l, int *nid)
{
 const struct keytype *kt;

 for (kt = keytypes; kt->type != -1; kt++) {
  if (kt->name == 
                 ((void *)0) 
                      || strlen(kt->name) != l)
   continue;
  if (memcmp(s, kt->name, l) == 0) {
   *nid = -1;
   if (key_type_is_ecdsa_variant(kt->type))
    *nid = kt->nid;
   return kt->type;
  }
 }
 return KEY_UNSPEC;
}


int
sshkey_read(struct sshkey *ret, char **cpp)
{
 struct sshkey *k;
 char *cp, *blobcopy;
 size_t space;
 int r, type, curve_nid = -1;
 struct sshbuf *blob;

 if (ret == 
           ((void *)0)
               )
  return -10;

 switch (ret->type) {
 case KEY_UNSPEC:
 case KEY_RSA:
 case KEY_DSA:
 case KEY_ECDSA:
 case KEY_ECDSA_SK:
 case KEY_ED25519:
 case KEY_ED25519_SK:
 case KEY_DSA_CERT:
 case KEY_ECDSA_CERT:
 case KEY_ECDSA_SK_CERT:
 case KEY_RSA_CERT:
 case KEY_ED25519_CERT:
 case KEY_ED25519_SK_CERT:




  break;
 default:
  return -10;
 }


 cp = *cpp;
 space = strcspn(cp, " \t");
 if (space == strlen(cp))
  return -4;
 if ((type = peek_type_nid(cp, space, &curve_nid)) == KEY_UNSPEC)
  return -4;


 for (cp += space; *cp == ' ' || *cp == '\t'; cp++)
  ;
 if (*cp == '\0')
  return -4;
 if (ret->type != KEY_UNSPEC && ret->type != type)
  return -13;
 if ((blob = sshbuf_new()) == 
                             ((void *)0)
                                 )
  return -2;


 space = strcspn(cp, " \t");
 if ((blobcopy = strndup(cp, space)) == 
                                       ((void *)0)
                                           ) {
  sshbuf_free(blob);
  return -2;
 }
 if ((r = sshbuf_b64tod(blob, blobcopy)) != 0) {
  free(blobcopy);
  sshbuf_free(blob);
  return r;
 }
 free(blobcopy);
 if ((r = sshkey_fromb(blob, &k)) != 0) {
  sshbuf_free(blob);
  return r;
 }
 sshbuf_free(blob);


 for (cp += space; *cp == ' ' || *cp == '\t'; cp++)
  ;


 if (k->type != type) {
  sshkey_free(k);
  return -13;
 }
 if (key_type_is_ecdsa_variant(type) && curve_nid != k->ecdsa_nid) {
  sshkey_free(k);
  return -15;
 }


 ret->type = type;
 if (sshkey_is_cert(ret)) {
  if (!sshkey_is_cert(k)) {
   sshkey_free(k);
   return -16;
  }
  if (ret->cert != 
                  ((void *)0)
                      )
   cert_free(ret->cert);
  ret->cert = k->cert;
  k->cert = 
           ((void *)0)
               ;
 }
 switch (sshkey_type_plain(ret->type)) {

 case KEY_RSA:
  RSA_free(ret->rsa);
  ret->rsa = k->rsa;
  k->rsa = 
          ((void *)0)
              ;



  break;
 case KEY_DSA:
  DSA_free(ret->dsa);
  ret->dsa = k->dsa;
  k->dsa = 
          ((void *)0)
              ;



  break;

 case KEY_ECDSA:
  EC_KEY_free(ret->ecdsa);
  ret->ecdsa = k->ecdsa;
  ret->ecdsa_nid = k->ecdsa_nid;
  k->ecdsa = 
            ((void *)0)
                ;
  k->ecdsa_nid = -1;



  break;
 case KEY_ECDSA_SK:
  EC_KEY_free(ret->ecdsa);
  ret->ecdsa = k->ecdsa;
  ret->ecdsa_nid = k->ecdsa_nid;
  ret->sk_application = k->sk_application;
  k->ecdsa = 
            ((void *)0)
                ;
  k->ecdsa_nid = -1;
  k->sk_application = 
                     ((void *)0)
                         ;




  break;


 case KEY_ED25519:
  freezero(ret->ed25519_pk, 32U);
  ret->ed25519_pk = k->ed25519_pk;
  k->ed25519_pk = 
                 ((void *)0)
                     ;



  break;
 case KEY_ED25519_SK:
  freezero(ret->ed25519_pk, 32U);
  ret->ed25519_pk = k->ed25519_pk;
  ret->sk_application = k->sk_application;
  k->ed25519_pk = 
                 ((void *)0)
                     ;
  k->sk_application = 
                     ((void *)0)
                         ;
  break;
 default:
  sshkey_free(k);
  return -1;
 }
 sshkey_free(k);


 *cpp = cp;
 return 0;
}


int
sshkey_to_base64(const struct sshkey *key, char **b64p)
{
 int r = -1;
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 char *uu = 
           ((void *)0)
               ;

 if (b64p != 
            ((void *)0)
                )
  *b64p = 
         ((void *)0)
             ;
 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              )
  return -2;
 if ((r = sshkey_putb(key, b)) != 0)
  goto out;
 if ((uu = sshbuf_dtob64_string(b, 0)) == 
                                         ((void *)0)
                                             ) {
  r = -2;
  goto out;
 }

 if (b64p != 
            ((void *)0)
                ) {
  *b64p = uu;
  uu = 
      ((void *)0)
          ;
 }
 r = 0;
 out:
 sshbuf_free(b);
 free(uu);
 return r;
}

int
sshkey_format_text(const struct sshkey *key, struct sshbuf *b)
{
 int r = -1;
 char *uu = 
           ((void *)0)
               ;

 if ((r = sshkey_to_base64(key, &uu)) != 0)
  goto out;
 if ((r = sshbuf_putf(b, "%s %s",
     sshkey_ssh_name(key), uu)) != 0)
  goto out;
 r = 0;
 out:
 free(uu);
 return r;
}

int
sshkey_write(const struct sshkey *key, FILE *f)
{
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 int r = -1;

 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              )
  return -2;
 if ((r = sshkey_format_text(key, b)) != 0)
  goto out;
 if (fwrite(sshbuf_ptr(b), sshbuf_len(b), 1, f) != 1) {
  if (feof(f))
   
  (*__errno_location ()) 
        = 
          32
               ;
  r = -24;
  goto out;
 }

 r = 0;
 out:
 sshbuf_free(b);
 return r;
}

const char *
sshkey_cert_type(const struct sshkey *k)
{
 switch (k->cert->type) {
 case 1:
  return "user";
 case 2:
  return "host";
 default:
  return "unknown";
 }
}


static int
rsa_generate_private_key(u_int bits, RSA **rsap)
{
 RSA *private = 
               ((void *)0)
                   ;
 BIGNUM *f4 = 
             ((void *)0)
                 ;
 int ret = -1;

 if (rsap == 
            ((void *)0)
                )
  return -10;
 if (bits < 1024 ||
     bits > (16384 / 8) * 8)
  return -56;
 *rsap = 
        ((void *)0)
            ;
 if ((private = RSA_new()) == 
                             ((void *)0) 
                                  || (f4 = BN_new()) == 
                                                        ((void *)0)
                                                            ) {
  ret = -2;
  goto out;
 }
 if (!BN_set_word(f4, 
                     0x10001L
                           ) ||
     !RSA_generate_key_ex(private, bits, f4, 
                                            ((void *)0)
                                                )) {
  ret = -22;
  goto out;
 }
 *rsap = private;
 private = 
          ((void *)0)
              ;
 ret = 0;
 out:
 RSA_free(private);
 BN_free(f4);
 return ret;
}

static int
dsa_generate_private_key(u_int bits, DSA **dsap)
{
 DSA *private;
 int ret = -1;

 if (dsap == 
            ((void *)0)
                )
  return -10;
 if (bits != 1024)
  return -56;
 if ((private = DSA_new()) == 
                             ((void *)0)
                                 ) {
  ret = -2;
  goto out;
 }
 *dsap = 
        ((void *)0)
            ;
 if (!DSA_generate_parameters_ex(private, bits, 
                                               ((void *)0)
                                                   , 0, 
                                                        ((void *)0)
                                                            ,
     
    ((void *)0)
        , 
          ((void *)0)
              ) || !DSA_generate_key(private)) {
  ret = -22;
  goto out;
 }
 *dsap = private;
 private = 
          ((void *)0)
              ;
 ret = 0;
 out:
 DSA_free(private);
 return ret;
}


int
sshkey_ecdsa_key_to_nid(EC_KEY *k)
{
 EC_GROUP *eg;
 int nids[] = {
  
 415
                     ,
  
 715
              ,

  
 716
              ,

  -1
 };
 int nid;
 u_int i;
 const EC_GROUP *g = EC_KEY_get0_group(k);
 if ((nid = EC_GROUP_get_curve_name(g)) > 0)
  return nid;
 for (i = 0; nids[i] != -1; i++) {
  if ((eg = EC_GROUP_new_by_curve_name(nids[i])) == 
                                                   ((void *)0)
                                                       )
   return -1;
  if (EC_GROUP_cmp(g, eg, 
                         ((void *)0)
                             ) == 0)
   break;
  EC_GROUP_free(eg);
 }
 if (nids[i] != -1) {

  EC_GROUP_set_asn1_flag(eg, 
                            0x001
                                                  );
  if (EC_KEY_set_group(k, eg) != 1) {
   EC_GROUP_free(eg);
   return -1;
  }
 }
 return nids[i];
}

static int
ecdsa_generate_private_key(u_int bits, int *nid, EC_KEY **ecdsap)
{
 EC_KEY *private;
 int ret = -1;

 if (nid == 
           ((void *)0) 
                || ecdsap == 
                             ((void *)0)
                                 )
  return -10;
 if ((*nid = sshkey_ecdsa_bits_to_nid(bits)) == -1)
  return -56;
 *ecdsap = 
          ((void *)0)
              ;
 if ((private = EC_KEY_new_by_curve_name(*nid)) == 
                                                  ((void *)0)
                                                      ) {
  ret = -2;
  goto out;
 }
 if (EC_KEY_generate_key(private) != 1) {
  ret = -22;
  goto out;
 }
 EC_KEY_set_asn1_flag(private, 
                              0x001
                                                    );
 *ecdsap = private;
 private = 
          ((void *)0)
              ;
 ret = 0;
 out:
 EC_KEY_free(private);
 return ret;
}



int
sshkey_generate(int type, u_int bits, struct sshkey **keyp)
{
 struct sshkey *k;
 int ret = -1;

 if (keyp == 
            ((void *)0)
                )
  return -10;
 *keyp = 
        ((void *)0)
            ;
 if ((k = sshkey_new(KEY_UNSPEC)) == 
                                    ((void *)0)
                                        )
  return -2;
 switch (type) {
 case KEY_ED25519:
  if ((k->ed25519_pk = malloc(32U)) == 
                                                ((void *)0) 
                                                     ||
      (k->ed25519_sk = malloc(64U)) == 
                                                ((void *)0)
                                                    ) {
   ret = -2;
   break;
  }
  crypto_sign_ed25519_keypair(k->ed25519_pk, k->ed25519_sk);
  ret = 0;
  break;






 case KEY_DSA:
  ret = dsa_generate_private_key(bits, &k->dsa);
  break;

 case KEY_ECDSA:
  ret = ecdsa_generate_private_key(bits, &k->ecdsa_nid,
      &k->ecdsa);
  break;

 case KEY_RSA:
  ret = rsa_generate_private_key(bits, &k->rsa);
  break;

 default:
  ret = -10;
 }
 if (ret == 0) {
  k->type = type;
  *keyp = k;
 } else
  sshkey_free(k);
 return ret;
}

int
sshkey_cert_copy(const struct sshkey *from_key, struct sshkey *to_key)
{
 u_int i;
 const struct sshkey_cert *from;
 struct sshkey_cert *to;
 int r = -1;

 if (to_key == 
              ((void *)0) 
                   || (from = from_key->cert) == 
                                                 ((void *)0)
                                                     )
  return -10;

 if ((to = cert_new()) == 
                         ((void *)0)
                             )
  return -2;

 if ((r = sshbuf_putb(to->certblob, from->certblob)) != 0 ||
     (r = sshbuf_putb(to->critical, from->critical)) != 0 ||
     (r = sshbuf_putb(to->extensions, from->extensions)) != 0)
  goto out;

 to->serial = from->serial;
 to->type = from->type;
 if (from->key_id == 
                    ((void *)0)
                        )
  to->key_id = 
              ((void *)0)
                  ;
 else if ((to->key_id = strdup(from->key_id)) == 
                                                ((void *)0)
                                                    ) {
  r = -2;
  goto out;
 }
 to->valid_after = from->valid_after;
 to->valid_before = from->valid_before;
 if (from->signature_key == 
                           ((void *)0)
                               )
  to->signature_key = 
                     ((void *)0)
                         ;
 else if ((r = sshkey_from_private(from->signature_key,
     &to->signature_key)) != 0)
  goto out;
 if (from->signature_type != 
                            ((void *)0) 
                                 &&
     (to->signature_type = strdup(from->signature_type)) == 
                                                           ((void *)0)
                                                               ) {
  r = -2;
  goto out;
 }
 if (from->nprincipals > 256) {
  r = -10;
  goto out;
 }
 if (from->nprincipals > 0) {
  if ((to->principals = calloc(from->nprincipals,
      sizeof(*to->principals))) == 
                                  ((void *)0)
                                      ) {
   r = -2;
   goto out;
  }
  for (i = 0; i < from->nprincipals; i++) {
   to->principals[i] = strdup(from->principals[i]);
   if (to->principals[i] == 
                           ((void *)0)
                               ) {
    to->nprincipals = i;
    r = -2;
    goto out;
   }
  }
 }
 to->nprincipals = from->nprincipals;


 cert_free(to_key->cert);
 to_key->cert = to;
 to = 
     ((void *)0)
         ;
 r = 0;
 out:
 cert_free(to);
 return r;
}

int
sshkey_from_private(const struct sshkey *k, struct sshkey **pkp)
{
 struct sshkey *n = 
                   ((void *)0)
                       ;
 int r = -1;

 const BIGNUM *rsa_n, *rsa_e;
 BIGNUM *rsa_n_dup = 
                    ((void *)0)
                        , *rsa_e_dup = 
                                       ((void *)0)
                                           ;
 const BIGNUM *dsa_p, *dsa_q, *dsa_g, *dsa_pub_key;
 BIGNUM *dsa_p_dup = 
                    ((void *)0)
                        , *dsa_q_dup = 
                                       ((void *)0)
                                           , *dsa_g_dup = 
                                                          ((void *)0)
                                                              ;
 BIGNUM *dsa_pub_key_dup = 
                          ((void *)0)
                              ;


 *pkp = 
       ((void *)0)
           ;
 if ((n = sshkey_new(k->type)) == 
                                 ((void *)0)
                                     ) {
  r = -2;
  goto out;
 }
 switch (k->type) {

 case KEY_DSA:
 case KEY_DSA_CERT:
  DSA_get0_pqg(k->dsa, &dsa_p, &dsa_q, &dsa_g);
  DSA_get0_key(k->dsa, &dsa_pub_key, 
                                    ((void *)0)
                                        );
  if ((dsa_p_dup = BN_dup(dsa_p)) == 
                                    ((void *)0) 
                                         ||
      (dsa_q_dup = BN_dup(dsa_q)) == 
                                    ((void *)0) 
                                         ||
      (dsa_g_dup = BN_dup(dsa_g)) == 
                                    ((void *)0) 
                                         ||
      (dsa_pub_key_dup = BN_dup(dsa_pub_key)) == 
                                                ((void *)0)
                                                    ) {
   r = -2;
   goto out;
  }
  if (!DSA_set0_pqg(n->dsa, dsa_p_dup, dsa_q_dup, dsa_g_dup)) {
   r = -22;
   goto out;
  }
  dsa_p_dup = dsa_q_dup = dsa_g_dup = 
                                     ((void *)0)
                                         ;
  if (!DSA_set0_key(n->dsa, dsa_pub_key_dup, 
                                            ((void *)0)
                                                )) {
   r = -22;
   goto out;
  }
  dsa_pub_key_dup = 
                   ((void *)0)
                       ;

  break;

 case KEY_ECDSA:
 case KEY_ECDSA_CERT:
 case KEY_ECDSA_SK:
 case KEY_ECDSA_SK_CERT:
  n->ecdsa_nid = k->ecdsa_nid;
  n->ecdsa = EC_KEY_new_by_curve_name(k->ecdsa_nid);
  if (n->ecdsa == 
                 ((void *)0)
                     ) {
   r = -2;
   goto out;
  }
  if (EC_KEY_set_public_key(n->ecdsa,
      EC_KEY_get0_public_key(k->ecdsa)) != 1) {
   r = -22;
   goto out;
  }
  if (k->type != KEY_ECDSA_SK && k->type != KEY_ECDSA_SK_CERT)
   break;

  if ((n->sk_application = strdup(k->sk_application)) == 
                                                        ((void *)0)
                                                            )
   goto out;
  break;

 case KEY_RSA:
 case KEY_RSA_CERT:
  RSA_get0_key(k->rsa, &rsa_n, &rsa_e, 
                                      ((void *)0)
                                          );
  if ((rsa_n_dup = BN_dup(rsa_n)) == 
                                    ((void *)0) 
                                         ||
      (rsa_e_dup = BN_dup(rsa_e)) == 
                                    ((void *)0)
                                        ) {
   r = -2;
   goto out;
  }
  if (!RSA_set0_key(n->rsa, rsa_n_dup, rsa_e_dup, 
                                                 ((void *)0)
                                                     )) {
   r = -22;
   goto out;
  }
  rsa_n_dup = rsa_e_dup = 
                         ((void *)0)
                             ;
  break;

 case KEY_ED25519:
 case KEY_ED25519_CERT:
 case KEY_ED25519_SK:
 case KEY_ED25519_SK_CERT:
  if (k->ed25519_pk != 
                      ((void *)0)
                          ) {
   if ((n->ed25519_pk = malloc(32U)) == 
                                                 ((void *)0)
                                                     ) {
    r = -2;
    goto out;
   }
   memcpy(n->ed25519_pk, k->ed25519_pk, 32U);
  }
  if (k->type != KEY_ED25519_SK &&
      k->type != KEY_ED25519_SK_CERT)
   break;

  if ((n->sk_application = strdup(k->sk_application)) == 
                                                        ((void *)0)
                                                            )
   goto out;
  break;
 default:
  r = -14;
  goto out;
 }
 if (sshkey_is_cert(k) && (r = sshkey_cert_copy(k, n)) != 0)
  goto out;

 *pkp = n;
 n = 
    ((void *)0)
        ;
 r = 0;
 out:
 sshkey_free(n);

 BN_clear_free(rsa_n_dup);
 BN_clear_free(rsa_e_dup);
 BN_clear_free(dsa_p_dup);
 BN_clear_free(dsa_q_dup);
 BN_clear_free(dsa_g_dup);
 BN_clear_free(dsa_pub_key_dup);


 return r;
}

int
sshkey_is_shielded(struct sshkey *k)
{
 return k != 
            ((void *)0) 
                 && k->shielded_private != 
                                           ((void *)0)
                                               ;
}

int
sshkey_shield_private(struct sshkey *k)
{
 struct sshbuf *prvbuf = 
                        ((void *)0)
                            ;
 u_char *prekey = 
                 ((void *)0)
                     , *enc = 
                              ((void *)0)
                                  , keyiv[64];
 struct sshcipher_ctx *cctx = 
                             ((void *)0)
                                 ;
 const struct sshcipher *cipher;
 size_t i, enclen = 0;
 struct sshkey *kswap = 
                       ((void *)0)
                           , tmp;
 int r = -1;




 if ((cipher = cipher_by_name("aes256-ctr")) == 
                                                       ((void *)0)
                                                           ) {
  r = -10;
  goto out;
 }
 if (cipher_keylen(cipher) + cipher_ivlen(cipher) >
     ssh_digest_bytes(4)) {
  r = -1;
  goto out;
 }


 if ((prekey = malloc((16 * 1024))) == 
                                                   ((void *)0)
                                                       ) {
  r = -2;
  goto out;
 }
 arc4random_buf(prekey, (16 * 1024));
 if ((r = ssh_digest_memory(4,
     prekey, (16 * 1024),
     keyiv, 64)) != 0)
  goto out;





 if ((r = cipher_init(&cctx, cipher, keyiv, cipher_keylen(cipher),
     keyiv + cipher_keylen(cipher), cipher_ivlen(cipher), 1)) != 0)
  goto out;


 if ((prvbuf = sshbuf_new()) == 
                               ((void *)0)
                                   ) {
  r = -2;
  goto out;
 }
 if (sshkey_is_shielded(k) && (r = sshkey_unshield_private(k)) != 0)
  goto out;
 if ((r = sshkey_private_serialize_opt(k, prvbuf,
     SSHKEY_SERIALIZE_SHIELD)) != 0)
  goto out;

 i = 0;
 while (sshbuf_len(prvbuf) % cipher_blocksize(cipher)) {
  if ((r = sshbuf_put_u8(prvbuf, ++i & 0xff)) != 0)
   goto out;
 }





 enclen = sshbuf_len(prvbuf);
 if ((enc = malloc(enclen)) == 
                              ((void *)0)
                                  ) {
  r = -2;
  goto out;
 }
 if ((r = cipher_crypt(cctx, 0, enc,
     sshbuf_ptr(prvbuf), sshbuf_len(prvbuf), 0, 0)) != 0)
  goto out;






 if ((r = sshkey_from_private(k, &kswap)) != 0)
  goto out;


 tmp = *kswap;
 *kswap = *k;
 *k = tmp;


 k->shielded_private = enc;
 k->shielded_len = enclen;
 k->shield_prekey = prekey;
 k->shield_prekey_len = (16 * 1024);
 enc = prekey = 
               ((void *)0)
                   ;
 enclen = 0;


 k->sk_flags = kswap->sk_flags;


 r = 0;

 out:

 cipher_free(cctx);
 explicit_bzero(keyiv, sizeof(keyiv));
 explicit_bzero(&tmp, sizeof(tmp));
 freezero(enc, enclen);
 freezero(prekey, (16 * 1024));
 sshkey_free(kswap);
 sshbuf_free(prvbuf);
 return r;
}


static int
private2_check_padding(struct sshbuf *decrypted)
{
 u_char pad;
 size_t i;
 int r;

 i = 0;
 while (sshbuf_len(decrypted)) {
  if ((r = sshbuf_get_u8(decrypted, &pad)) != 0)
   goto out;
  if (pad != (++i & 0xff)) {
   r = -4;
   goto out;
  }
 }

 r = 0;
 out:
 explicit_bzero(&pad, sizeof(pad));
 explicit_bzero(&i, sizeof(i));
 return r;
}

int
sshkey_unshield_private(struct sshkey *k)
{
 struct sshbuf *prvbuf = 
                        ((void *)0)
                            ;
 u_char *cp, keyiv[64];
 struct sshcipher_ctx *cctx = 
                             ((void *)0)
                                 ;
 const struct sshcipher *cipher;
 struct sshkey *kswap = 
                       ((void *)0)
                           , tmp;
 int r = -1;




 if (!sshkey_is_shielded(k))
  return 0;

 if ((cipher = cipher_by_name("aes256-ctr")) == 
                                                       ((void *)0)
                                                           ) {
  r = -10;
  goto out;
 }
 if (cipher_keylen(cipher) + cipher_ivlen(cipher) >
     ssh_digest_bytes(4)) {
  r = -1;
  goto out;
 }

 if (k->shielded_len < cipher_blocksize(cipher) ||
     (k->shielded_len % cipher_blocksize(cipher)) != 0) {
  r = -4;
  goto out;
 }


 if ((r = ssh_digest_memory(4,
     k->shield_prekey, k->shield_prekey_len,
     keyiv, 64)) != 0)
  goto out;
 if ((r = cipher_init(&cctx, cipher, keyiv, cipher_keylen(cipher),
     keyiv + cipher_keylen(cipher), cipher_ivlen(cipher), 0)) != 0)
  goto out;







 if ((prvbuf = sshbuf_new()) == 
                               ((void *)0)
                                   ) {
  r = -2;
  goto out;
 }
 if ((r = sshbuf_reserve(prvbuf, k->shielded_len, &cp)) != 0)
  goto out;





 if ((r = cipher_crypt(cctx, 0, cp,
     k->shielded_private, k->shielded_len, 0, 0)) != 0)
  goto out;





 if ((r = sshkey_private_deserialize(prvbuf, &kswap)) != 0)
  goto out;

 if ((r = private2_check_padding(prvbuf)) != 0)
  goto out;


 tmp = *kswap;
 *kswap = *k;
 *k = tmp;


 r = 0;

 out:
 cipher_free(cctx);
 explicit_bzero(keyiv, sizeof(keyiv));
 explicit_bzero(&tmp, sizeof(tmp));
 sshkey_free(kswap);
 sshbuf_free(prvbuf);
 return r;
}

static int
cert_parse(struct sshbuf *b, struct sshkey *key, struct sshbuf *certbuf)
{
 struct sshbuf *principals = 
                            ((void *)0)
                                , *crit = 
                                          ((void *)0)
                                              ;
 struct sshbuf *exts = 
                      ((void *)0)
                          , *ca = 
                                  ((void *)0)
                                      ;
 u_char *sig = 
              ((void *)0)
                  ;
 size_t signed_len = 0, slen = 0, kidlen = 0;
 int ret = -1;


 if ((ret = sshbuf_putb(key->cert->certblob, certbuf)) != 0)
  return ret;


 if ((ret = sshbuf_get_u64(b, &key->cert->serial)) != 0 ||
     (ret = sshbuf_get_u32(b, &key->cert->type)) != 0 ||
     (ret = sshbuf_get_cstring(b, &key->cert->key_id, &kidlen)) != 0 ||
     (ret = sshbuf_froms(b, &principals)) != 0 ||
     (ret = sshbuf_get_u64(b, &key->cert->valid_after)) != 0 ||
     (ret = sshbuf_get_u64(b, &key->cert->valid_before)) != 0 ||
     (ret = sshbuf_froms(b, &crit)) != 0 ||
     (ret = sshbuf_froms(b, &exts)) != 0 ||
     (ret = sshbuf_get_string_direct(b, 
                                       ((void *)0)
                                           , 
                                             ((void *)0)
                                                 )) != 0 ||
     (ret = sshbuf_froms(b, &ca)) != 0) {

  ret = -4;
  goto out;
 }


 signed_len = sshbuf_len(key->cert->certblob) - sshbuf_len(b);

 if ((ret = sshbuf_get_string(b, &sig, &slen)) != 0) {
  ret = -4;
  goto out;
 }

 if (key->cert->type != 1 &&
     key->cert->type != 2) {
  ret = -18;
  goto out;
 }


 while (sshbuf_len(principals) > 0) {
  char *principal = 
                   ((void *)0)
                       ;
  char **oprincipals = 
                      ((void *)0)
                          ;

  if (key->cert->nprincipals >= 256) {
   ret = -4;
   goto out;
  }
  if ((ret = sshbuf_get_cstring(principals, &principal,
      
     ((void *)0)
         )) != 0) {
   ret = -4;
   goto out;
  }
  oprincipals = key->cert->principals;
  key->cert->principals = recallocarray(key->cert->principals,
      key->cert->nprincipals, key->cert->nprincipals + 1,
      sizeof(*key->cert->principals));
  if (key->cert->principals == 
                              ((void *)0)
                                  ) {
   free(principal);
   key->cert->principals = oprincipals;
   ret = -2;
   goto out;
  }
  key->cert->principals[key->cert->nprincipals++] = principal;
 }





 if ((ret = sshbuf_putb(key->cert->critical, crit)) != 0 ||
     (exts != 
             ((void *)0) 
                  &&
     (ret = sshbuf_putb(key->cert->extensions, exts)) != 0))
  goto out;




 while (sshbuf_len(crit) != 0) {
  if ((ret = sshbuf_get_string_direct(crit, 
                                           ((void *)0)
                                               , 
                                                 ((void *)0)
                                                     )) != 0 ||
      (ret = sshbuf_get_string_direct(crit, 
                                           ((void *)0)
                                               , 
                                                 ((void *)0)
                                                     )) != 0) {
   sshbuf_reset(key->cert->critical);
   ret = -4;
   goto out;
  }
 }
 while (exts != 
               ((void *)0) 
                    && sshbuf_len(exts) != 0) {
  if ((ret = sshbuf_get_string_direct(exts, 
                                           ((void *)0)
                                               , 
                                                 ((void *)0)
                                                     )) != 0 ||
      (ret = sshbuf_get_string_direct(exts, 
                                           ((void *)0)
                                               , 
                                                 ((void *)0)
                                                     )) != 0) {
   sshbuf_reset(key->cert->extensions);
   ret = -4;
   goto out;
  }
 }


 if (sshkey_from_blob_internal(ca, &key->cert->signature_key, 0) != 0) {
  ret = -19;
  goto out;
 }
 if (!sshkey_type_is_valid_ca(key->cert->signature_key->type)) {
  ret = -19;
  goto out;
 }
 if ((ret = sshkey_verify(key->cert->signature_key, sig, slen,
     sshbuf_ptr(key->cert->certblob), signed_len, 
                                                 ((void *)0)
                                                     , 0, 
                                                          ((void *)0)
                                                              )) != 0)
  goto out;
 if ((ret = sshkey_get_sigtype(sig, slen,
     &key->cert->signature_type)) != 0)
  goto out;


 ret = 0;
 out:
 sshbuf_free(ca);
 sshbuf_free(crit);
 sshbuf_free(exts);
 sshbuf_free(principals);
 free(sig);
 return ret;
}

int
sshkey_check_rsa_length(const struct sshkey *k, int min_size)
{

 const BIGNUM *rsa_n;
 int nbits;

 if (k == 
         ((void *)0) 
              || k->rsa == 
                           ((void *)0) 
                                ||
     (k->type != KEY_RSA && k->type != KEY_RSA_CERT))
  return 0;
 RSA_get0_key(k->rsa, &rsa_n, 
                             ((void *)0)
                                 , 
                                   ((void *)0)
                                       );
 nbits = BN_num_bits(rsa_n);
 if (nbits < 1024 ||
     (min_size > 0 && nbits < min_size))
  return -56;

 return 0;
}

static int
sshkey_from_blob_internal(struct sshbuf *b, struct sshkey **keyp,
    int allow_cert)
{
 int type, ret = -1;
 char *ktype = 
              ((void *)0)
                  , *curve = 
                             ((void *)0)
                                 , *xmss_name = 
                                                ((void *)0)
                                                    ;
 struct sshkey *key = 
                     ((void *)0)
                         ;
 size_t len;
 u_char *pk = 
             ((void *)0)
                 ;
 struct sshbuf *copy;

 BIGNUM *rsa_n = 
                ((void *)0)
                    , *rsa_e = 
                               ((void *)0)
                                   ;
 BIGNUM *dsa_p = 
                ((void *)0)
                    , *dsa_q = 
                               ((void *)0)
                                   , *dsa_g = 
                                              ((void *)0)
                                                  , *dsa_pub_key = 
                                                                   ((void *)0)
                                                                       ;

 EC_POINT *q = 
              ((void *)0)
                  ;






 if (keyp != 
            ((void *)0)
                )
  *keyp = 
         ((void *)0)
             ;
 if ((copy = sshbuf_fromb(b)) == 
                                ((void *)0)
                                    ) {
  ret = -2;
  goto out;
 }
 if (sshbuf_get_cstring(b, &ktype, 
                                  ((void *)0)
                                      ) != 0) {
  ret = -4;
  goto out;
 }

 type = sshkey_type_from_name(ktype);
 if (!allow_cert && sshkey_type_is_cert(type)) {
  ret = -19;
  goto out;
 }
 switch (type) {

 case KEY_RSA_CERT:

  if (sshbuf_get_string_direct(b, 
                                 ((void *)0)
                                     , 
                                       ((void *)0)
                                           ) != 0) {
   ret = -4;
   goto out;
  }

 case KEY_RSA:
  if ((key = sshkey_new(type)) == 
                                 ((void *)0)
                                     ) {
   ret = -2;
   goto out;
  }
  if (sshbuf_get_bignum2(b, &rsa_e) != 0 ||
      sshbuf_get_bignum2(b, &rsa_n) != 0) {
   ret = -4;
   goto out;
  }
  if (!RSA_set0_key(key->rsa, rsa_n, rsa_e, 
                                           ((void *)0)
                                               )) {
   ret = -22;
   goto out;
  }
  rsa_n = rsa_e = 
                 ((void *)0)
                     ;
  if ((ret = sshkey_check_rsa_length(key, 0)) != 0)
   goto out;



  break;
 case KEY_DSA_CERT:

  if (sshbuf_get_string_direct(b, 
                                 ((void *)0)
                                     , 
                                       ((void *)0)
                                           ) != 0) {
   ret = -4;
   goto out;
  }

 case KEY_DSA:
  if ((key = sshkey_new(type)) == 
                                 ((void *)0)
                                     ) {
   ret = -2;
   goto out;
  }
  if (sshbuf_get_bignum2(b, &dsa_p) != 0 ||
      sshbuf_get_bignum2(b, &dsa_q) != 0 ||
      sshbuf_get_bignum2(b, &dsa_g) != 0 ||
      sshbuf_get_bignum2(b, &dsa_pub_key) != 0) {
   ret = -4;
   goto out;
  }
  if (!DSA_set0_pqg(key->dsa, dsa_p, dsa_q, dsa_g)) {
   ret = -22;
   goto out;
  }
  dsa_p = dsa_q = dsa_g = 
                         ((void *)0)
                             ;
  if (!DSA_set0_key(key->dsa, dsa_pub_key, 
                                          ((void *)0)
                                              )) {
   ret = -22;
   goto out;
  }
  dsa_pub_key = 
               ((void *)0)
                   ;



  break;

 case KEY_ECDSA_CERT:
 case KEY_ECDSA_SK_CERT:

  if (sshbuf_get_string_direct(b, 
                                 ((void *)0)
                                     , 
                                       ((void *)0)
                                           ) != 0) {
   ret = -4;
   goto out;
  }

 case KEY_ECDSA:
 case KEY_ECDSA_SK:
  if ((key = sshkey_new(type)) == 
                                 ((void *)0)
                                     ) {
   ret = -2;
   goto out;
  }
  key->ecdsa_nid = sshkey_ecdsa_nid_from_name(ktype);
  if (sshbuf_get_cstring(b, &curve, 
                                   ((void *)0)
                                       ) != 0) {
   ret = -4;
   goto out;
  }
  if (key->ecdsa_nid != sshkey_curve_name_to_nid(curve)) {
   ret = -15;
   goto out;
  }
  EC_KEY_free(key->ecdsa);
  if ((key->ecdsa = EC_KEY_new_by_curve_name(key->ecdsa_nid))
      == 
        ((void *)0)
            ) {
   ret = -12;
   goto out;
  }
  if ((q = EC_POINT_new(EC_KEY_get0_group(key->ecdsa))) == 
                                                          ((void *)0)
                                                              ) {
   ret = -2;
   goto out;
  }
  if (sshbuf_get_ec(b, q, EC_KEY_get0_group(key->ecdsa)) != 0) {
   ret = -4;
   goto out;
  }
  if (sshkey_ec_validate_public(EC_KEY_get0_group(key->ecdsa),
      q) != 0) {
   ret = -20;
   goto out;
  }
  if (EC_KEY_set_public_key(key->ecdsa, q) != 1) {

   ret = -2;
   goto out;
  }



  if (type == KEY_ECDSA_SK || type == KEY_ECDSA_SK_CERT) {

   if (sshbuf_get_cstring(b, &key->sk_application,
       
      ((void *)0)
          ) != 0) {
    ret = -4;
    goto out;
   }



  }
  break;


 case KEY_ED25519_CERT:
 case KEY_ED25519_SK_CERT:

  if (sshbuf_get_string_direct(b, 
                                 ((void *)0)
                                     , 
                                       ((void *)0)
                                           ) != 0) {
   ret = -4;
   goto out;
  }

 case KEY_ED25519:
 case KEY_ED25519_SK:
  if ((ret = sshbuf_get_string(b, &pk, &len)) != 0)
   goto out;
  if (len != 32U) {
   ret = -4;
   goto out;
  }
  if ((key = sshkey_new(type)) == 
                                 ((void *)0)
                                     ) {
   ret = -2;
   goto out;
  }
  if (type == KEY_ED25519_SK || type == KEY_ED25519_SK_CERT) {

   if (sshbuf_get_cstring(b, &key->sk_application,
       
      ((void *)0)
          ) != 0) {
    ret = -4;
    goto out;
   }



  }
  key->ed25519_pk = pk;
  pk = 
      ((void *)0)
          ;
  break;
 case KEY_UNSPEC:
 default:
  ret = -14;
  goto out;
 }


 if (sshkey_is_cert(key) && (ret = cert_parse(b, key, copy)) != 0)
  goto out;

 if (key != 
           ((void *)0) 
                && sshbuf_len(b) != 0) {
  ret = -4;
  goto out;
 }
 ret = 0;
 if (keyp != 
            ((void *)0)
                ) {
  *keyp = key;
  key = 
       ((void *)0)
           ;
 }
 out:
 sshbuf_free(copy);
 sshkey_free(key);
 free(xmss_name);
 free(ktype);
 free(curve);
 free(pk);

 BN_clear_free(rsa_n);
 BN_clear_free(rsa_e);
 BN_clear_free(dsa_p);
 BN_clear_free(dsa_q);
 BN_clear_free(dsa_g);
 BN_clear_free(dsa_pub_key);

 EC_POINT_free(q);


 return ret;
}

int
sshkey_from_blob(const u_char *blob, size_t blen, struct sshkey **keyp)
{
 struct sshbuf *b;
 int r;

 if ((b = sshbuf_from(blob, blen)) == 
                                     ((void *)0)
                                         )
  return -2;
 r = sshkey_from_blob_internal(b, keyp, 1);
 sshbuf_free(b);
 return r;
}

int
sshkey_fromb(struct sshbuf *b, struct sshkey **keyp)
{
 return sshkey_from_blob_internal(b, keyp, 1);
}

int
sshkey_froms(struct sshbuf *buf, struct sshkey **keyp)
{
 struct sshbuf *b;
 int r;

 if ((r = sshbuf_froms(buf, &b)) != 0)
  return r;
 r = sshkey_from_blob_internal(b, keyp, 1);
 sshbuf_free(b);
 return r;
}

int
sshkey_get_sigtype(const u_char *sig, size_t siglen, char **sigtypep)
{
 int r;
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 char *sigtype = 
                ((void *)0)
                    ;

 if (sigtypep != 
                ((void *)0)
                    )
  *sigtypep = 
             ((void *)0)
                 ;
 if ((b = sshbuf_from(sig, siglen)) == 
                                      ((void *)0)
                                          )
  return -2;
 if ((r = sshbuf_get_cstring(b, &sigtype, 
                                         ((void *)0)
                                             )) != 0)
  goto out;

 if (sigtypep != 
                ((void *)0)
                    ) {
  *sigtypep = sigtype;
  sigtype = 
           ((void *)0)
               ;
 }
 r = 0;
 out:
 free(sigtype);
 sshbuf_free(b);
 return r;
}
int
sshkey_check_cert_sigtype(const struct sshkey *key, const char *allowed)
{
 if (key == 
           ((void *)0) 
                || allowed == 
                              ((void *)0)
                                  )
  return -10;
 if (!sshkey_type_is_cert(key->type))
  return 0;
 if (key->cert == 
                 ((void *)0) 
                      || key->cert->signature_type == 
                                                      ((void *)0)
                                                          )
  return -10;
 if (match_pattern_list(key->cert->signature_type, allowed, 0) != 1)
  return -58;
 return 0;
}




const char *
sshkey_sigalg_by_name(const char *name)
{
 const struct keytype *kt;

 for (kt = keytypes; kt->type != -1; kt++) {
  if (strcmp(kt->name, name) != 0)
   continue;
  if (kt->sigalg != 
                   ((void *)0)
                       )
   return kt->sigalg;
  if (!kt->cert)
   return kt->name;
  return sshkey_ssh_name_from_type_nid(
      sshkey_type_plain(kt->type), kt->nid);
 }
 return 
       ((void *)0)
           ;
}





int
sshkey_check_sigtype(const u_char *sig, size_t siglen,
    const char *requested_alg)
{
 const char *expected_alg;
 char *sigtype = 
                ((void *)0)
                    ;
 int r;

 if (requested_alg == 
                     ((void *)0)
                         )
  return 0;
 if ((expected_alg = sshkey_sigalg_by_name(requested_alg)) == 
                                                             ((void *)0)
                                                                 )
  return -10;
 if ((r = sshkey_get_sigtype(sig, siglen, &sigtype)) != 0)
  return r;
 r = strcmp(expected_alg, sigtype) == 0;
 free(sigtype);
 return r ? 0 : -58;
}

int
sshkey_sign(struct sshkey *key,
    u_char **sigp, size_t *lenp,
    const u_char *data, size_t datalen,
    const char *alg, const char *sk_provider, const char *sk_pin, u_int compat)
{
 int was_shielded = sshkey_is_shielded(key);
 int r2, r = -1;

 if (sigp != 
            ((void *)0)
                )
  *sigp = 
         ((void *)0)
             ;
 if (lenp != 
            ((void *)0)
                )
  *lenp = 0;
 if (datalen > (1 << 20))
  return -10;
 if ((r = sshkey_unshield_private(key)) != 0)
  return r;
 switch (key->type) {

 case KEY_DSA_CERT:
 case KEY_DSA:
  r = ssh_dss_sign(key, sigp, lenp, data, datalen, compat);
  break;

 case KEY_ECDSA_CERT:
 case KEY_ECDSA:
  r = ssh_ecdsa_sign(key, sigp, lenp, data, datalen, compat);
  break;

 case KEY_RSA_CERT:
 case KEY_RSA:
  r = ssh_rsa_sign(key, sigp, lenp, data, datalen, alg);
  break;

 case KEY_ED25519:
 case KEY_ED25519_CERT:
  r = ssh_ed25519_sign(key, sigp, lenp, data, datalen, compat);
  break;
 case KEY_ED25519_SK:
 case KEY_ED25519_SK_CERT:
 case KEY_ECDSA_SK_CERT:
 case KEY_ECDSA_SK:
  r = sshsk_sign(sk_provider, key, sigp, lenp, data,
      datalen, compat, sk_pin);
  break;






 default:
  r = -14;
  break;
 }
 if (was_shielded && (r2 = sshkey_shield_private(key)) != 0)
  return r2;
 return r;
}





int
sshkey_verify(const struct sshkey *key,
    const u_char *sig, size_t siglen,
    const u_char *data, size_t dlen, const char *alg, u_int compat,
    struct sshkey_sig_details **detailsp)
{
 if (detailsp != 
                ((void *)0)
                    )
  *detailsp = 
             ((void *)0)
                 ;
 if (siglen == 0 || dlen > (1 << 20))
  return -10;
 switch (key->type) {

 case KEY_DSA_CERT:
 case KEY_DSA:
  return ssh_dss_verify(key, sig, siglen, data, dlen, compat);

 case KEY_ECDSA_CERT:
 case KEY_ECDSA:
  return ssh_ecdsa_verify(key, sig, siglen, data, dlen, compat);
 case KEY_ECDSA_SK_CERT:
 case KEY_ECDSA_SK:
  return ssh_ecdsa_sk_verify(key, sig, siglen, data, dlen,
      compat, detailsp);

 case KEY_RSA_CERT:
 case KEY_RSA:
  return ssh_rsa_verify(key, sig, siglen, data, dlen, alg);

 case KEY_ED25519:
 case KEY_ED25519_CERT:
  return ssh_ed25519_verify(key, sig, siglen, data, dlen, compat);
 case KEY_ED25519_SK:
 case KEY_ED25519_SK_CERT:
  return ssh_ed25519_sk_verify(key, sig, siglen, data, dlen,
      compat, detailsp);





 default:
  return -14;
 }
}


int
sshkey_to_certified(struct sshkey *k)
{
 int newtype;

 switch (k->type) {

 case KEY_RSA:
  newtype = KEY_RSA_CERT;
  break;
 case KEY_DSA:
  newtype = KEY_DSA_CERT;
  break;
 case KEY_ECDSA:
  newtype = KEY_ECDSA_CERT;
  break;
 case KEY_ECDSA_SK:
  newtype = KEY_ECDSA_SK_CERT;
  break;

 case KEY_ED25519_SK:
  newtype = KEY_ED25519_SK_CERT;
  break;
 case KEY_ED25519:
  newtype = KEY_ED25519_CERT;
  break;





 default:
  return -10;
 }
 if ((k->cert = cert_new()) == 
                              ((void *)0)
                                  )
  return -2;
 k->type = newtype;
 return 0;
}


int
sshkey_drop_cert(struct sshkey *k)
{
 if (!sshkey_type_is_cert(k->type))
  return -14;
 cert_free(k->cert);
 k->cert = 
          ((void *)0)
              ;
 k->type = sshkey_type_plain(k->type);
 return 0;
}


int
sshkey_certify_custom(struct sshkey *k, struct sshkey *ca, const char *alg,
    const char *sk_provider, const char *sk_pin,
    sshkey_certify_signer *signer, void *signer_ctx)
{
 struct sshbuf *principals = 
                            ((void *)0)
                                ;
 u_char *ca_blob = 
                  ((void *)0)
                      , *sig_blob = 
                                    ((void *)0)
                                        , nonce[32];
 size_t i, ca_len, sig_len;
 int ret = -1;
 struct sshbuf *cert = 
                      ((void *)0)
                          ;
 char *sigtype = 
                ((void *)0)
                    ;

 const BIGNUM *rsa_n, *rsa_e, *dsa_p, *dsa_q, *dsa_g, *dsa_pub_key;


 if (k == 
         ((void *)0) 
              || k->cert == 
                            ((void *)0) 
                                 ||
     k->cert->certblob == 
                         ((void *)0) 
                              || ca == 
                                       ((void *)0)
                                           )
  return -10;
 if (!sshkey_is_cert(k))
  return -14;
 if (!sshkey_type_is_valid_ca(ca->type))
  return -19;





 if (alg == 
           ((void *)0)
               )
  alg = k->cert->signature_type;
 else if (k->cert->signature_type != 
                                    ((void *)0) 
                                         &&
     strcmp(alg, k->cert->signature_type) != 0)
  return -10;





 if (alg == 
           ((void *)0) 
                && ca->type == KEY_RSA)
  alg = "rsa-sha2-512";

 if ((ret = sshkey_to_blob(ca, &ca_blob, &ca_len)) != 0)
  return -19;

 cert = k->cert->certblob;
 sshbuf_reset(cert);
 if ((ret = sshbuf_put_cstring(cert, sshkey_ssh_name(k))) != 0)
  goto out;


 arc4random_buf(&nonce, sizeof(nonce));
 if ((ret = sshbuf_put_string(cert, nonce, sizeof(nonce))) != 0)
  goto out;


 switch (k->type) {

 case KEY_DSA_CERT:
  DSA_get0_pqg(k->dsa, &dsa_p, &dsa_q, &dsa_g);
  DSA_get0_key(k->dsa, &dsa_pub_key, 
                                    ((void *)0)
                                        );
  if ((ret = sshbuf_put_bignum2(cert, dsa_p)) != 0 ||
      (ret = sshbuf_put_bignum2(cert, dsa_q)) != 0 ||
      (ret = sshbuf_put_bignum2(cert, dsa_g)) != 0 ||
      (ret = sshbuf_put_bignum2(cert, dsa_pub_key)) != 0)
   goto out;
  break;

 case KEY_ECDSA_CERT:
 case KEY_ECDSA_SK_CERT:
  if ((ret = sshbuf_put_cstring(cert,
      sshkey_curve_nid_to_name(k->ecdsa_nid))) != 0 ||
      (ret = sshbuf_put_ec(cert,
      EC_KEY_get0_public_key(k->ecdsa),
      EC_KEY_get0_group(k->ecdsa))) != 0)
   goto out;
  if (k->type == KEY_ECDSA_SK_CERT) {
   if ((ret = sshbuf_put_cstring(cert,
       k->sk_application)) != 0)
    goto out;
  }
  break;

 case KEY_RSA_CERT:
  RSA_get0_key(k->rsa, &rsa_n, &rsa_e, 
                                      ((void *)0)
                                          );
  if ((ret = sshbuf_put_bignum2(cert, rsa_e)) != 0 ||
      (ret = sshbuf_put_bignum2(cert, rsa_n)) != 0)
   goto out;
  break;

 case KEY_ED25519_CERT:
 case KEY_ED25519_SK_CERT:
  if ((ret = sshbuf_put_string(cert,
      k->ed25519_pk, 32U)) != 0)
   goto out;
  if (k->type == KEY_ED25519_SK_CERT) {
   if ((ret = sshbuf_put_cstring(cert,
       k->sk_application)) != 0)
    goto out;
  }
  break;
 default:
  ret = -10;
  goto out;
 }

 if ((ret = sshbuf_put_u64(cert, k->cert->serial)) != 0 ||
     (ret = sshbuf_put_u32(cert, k->cert->type)) != 0 ||
     (ret = sshbuf_put_cstring(cert, k->cert->key_id)) != 0)
  goto out;

 if ((principals = sshbuf_new()) == 
                                   ((void *)0)
                                       ) {
  ret = -2;
  goto out;
 }
 for (i = 0; i < k->cert->nprincipals; i++) {
  if ((ret = sshbuf_put_cstring(principals,
      k->cert->principals[i])) != 0)
   goto out;
 }
 if ((ret = sshbuf_put_stringb(cert, principals)) != 0 ||
     (ret = sshbuf_put_u64(cert, k->cert->valid_after)) != 0 ||
     (ret = sshbuf_put_u64(cert, k->cert->valid_before)) != 0 ||
     (ret = sshbuf_put_stringb(cert, k->cert->critical)) != 0 ||
     (ret = sshbuf_put_stringb(cert, k->cert->extensions)) != 0 ||
     (ret = sshbuf_put_string(cert, 
                                   ((void *)0)
                                       , 0)) != 0 ||
     (ret = sshbuf_put_string(cert, ca_blob, ca_len)) != 0)
  goto out;


 if ((ret = signer(ca, &sig_blob, &sig_len, sshbuf_ptr(cert),
     sshbuf_len(cert), alg, sk_provider, sk_pin, 0, signer_ctx)) != 0)
  goto out;

 if ((ret = sshkey_get_sigtype(sig_blob, sig_len, &sigtype)) != 0)
  goto out;
 if (alg != 
           ((void *)0) 
                && strcmp(alg, sigtype) != 0) {
  ret = -58;
  goto out;
 }
 if (k->cert->signature_type == 
                               ((void *)0)
                                   ) {
  k->cert->signature_type = sigtype;
  sigtype = 
           ((void *)0)
               ;
 }

 if ((ret = sshbuf_put_string(cert, sig_blob, sig_len)) != 0)
  goto out;
 ret = 0;
 out:
 if (ret != 0)
  sshbuf_reset(cert);
 free(sig_blob);
 free(ca_blob);
 free(sigtype);
 sshbuf_free(principals);
 return ret;
}

static int
default_key_sign(struct sshkey *key, u_char **sigp, size_t *lenp,
    const u_char *data, size_t datalen,
    const char *alg, const char *sk_provider, const char *sk_pin,
    u_int compat, void *ctx)
{
 if (ctx != 
           ((void *)0)
               )
  return -10;
 return sshkey_sign(key, sigp, lenp, data, datalen, alg,
     sk_provider, sk_pin, compat);
}

int
sshkey_certify(struct sshkey *k, struct sshkey *ca, const char *alg,
    const char *sk_provider, const char *sk_pin)
{
 return sshkey_certify_custom(k, ca, alg, sk_provider, sk_pin,
     default_key_sign, 
                      ((void *)0)
                          );
}

int
sshkey_cert_check_authority(const struct sshkey *k,
    int want_host, int require_principal, int wildcard_pattern,
    uint64_t verify_time, const char *name, const char **reason)
{
 u_int i, principal_matches;

 if (reason == 
              ((void *)0)
                  )
  return -10;
 if (!sshkey_is_cert(k)) {
  *reason = "Key is not a certificate";
  return -25;
 }
 if (want_host) {
  if (k->cert->type != 2) {
   *reason = "Certificate invalid: not a host certificate";
   return -25;
  }
 } else {
  if (k->cert->type != 1) {
   *reason = "Certificate invalid: not a user certificate";
   return -25;
  }
 }
 if (verify_time < k->cert->valid_after) {
  *reason = "Certificate invalid: not yet valid";
  return -25;
 }
 if (verify_time >= k->cert->valid_before) {
  *reason = "Certificate invalid: expired";
  return -25;
 }
 if (k->cert->nprincipals == 0) {
  if (require_principal) {
   *reason = "Certificate lacks principal list";
   return -25;
  }
 } else if (name != 
                   ((void *)0)
                       ) {
  principal_matches = 0;
  for (i = 0; i < k->cert->nprincipals; i++) {
   if (wildcard_pattern) {
    if (match_pattern(k->cert->principals[i],
        name)) {
     principal_matches = 1;
     break;
    }
   } else if (strcmp(name, k->cert->principals[i]) == 0) {
    principal_matches = 1;
    break;
   }
  }
  if (!principal_matches) {
   *reason = "Certificate invalid: name is not a listed "
       "principal";
   return -25;
  }
 }
 return 0;
}

int
sshkey_cert_check_authority_now(const struct sshkey *k,
    int want_host, int require_principal, int wildcard_pattern,
    const char *name, const char **reason)
{
 time_t now;

 if ((now = time(
                ((void *)0)
                    )) < 0) {

  *reason = "Certificate invalid: not yet valid";
  return -25;
 }
 return sshkey_cert_check_authority(k, want_host, require_principal,
     wildcard_pattern, (uint64_t)now, name, reason);
}

int
sshkey_cert_check_host(const struct sshkey *key, const char *host,
    int wildcard_principals, const char *ca_sign_algorithms,
    const char **reason)
{
 int r;

 if ((r = sshkey_cert_check_authority_now(key, 1, 0, wildcard_principals,
     host, reason)) != 0)
  return r;
 if (sshbuf_len(key->cert->critical) != 0) {
  *reason = "Certificate contains unsupported critical options";
  return -25;
 }
 if (ca_sign_algorithms != 
                          ((void *)0) 
                               &&
     (r = sshkey_check_cert_sigtype(key, ca_sign_algorithms)) != 0) {
  *reason = "Certificate signed with disallowed algorithm";
  return -25;
 }
 return 0;
}

size_t
sshkey_format_cert_validity(const struct sshkey_cert *cert, char *s, size_t l)
{
 char from[32], to[32], ret[128];

 *from = *to = '\0';
 if (cert->valid_after == 0 &&
     cert->valid_before == 0xffffffffffffffffULL)
  return strlcpy(s, "forever", l);

 if (cert->valid_after != 0)
  format_absolute_time(cert->valid_after, from, sizeof(from));
 if (cert->valid_before != 0xffffffffffffffffULL)
  format_absolute_time(cert->valid_before, to, sizeof(to));

 if (cert->valid_after == 0)
  snprintf(ret, sizeof(ret), "before %s", to);
 else if (cert->valid_before == 0xffffffffffffffffULL)
  snprintf(ret, sizeof(ret), "after %s", from);
 else
  snprintf(ret, sizeof(ret), "from %s to %s", from, to);

 return strlcpy(s, ret, l);
}

int
sshkey_private_serialize_opt(struct sshkey *key, struct sshbuf *buf,
    enum sshkey_serialize_rep opts)
{
 int r = -1;
 int was_shielded = sshkey_is_shielded(key);
 struct sshbuf *b = 
                   ((void *)0)
                       ;

 const BIGNUM *rsa_n, *rsa_e, *rsa_d, *rsa_iqmp, *rsa_p, *rsa_q;
 const BIGNUM *dsa_p, *dsa_q, *dsa_g, *dsa_pub_key, *dsa_priv_key;


 if ((r = sshkey_unshield_private(key)) != 0)
  return r;
 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              )
  return -2;
 if ((r = sshbuf_put_cstring(b, sshkey_ssh_name(key))) != 0)
  goto out;
 switch (key->type) {

 case KEY_RSA:
  RSA_get0_key(key->rsa, &rsa_n, &rsa_e, &rsa_d);
  RSA_get0_factors(key->rsa, &rsa_p, &rsa_q);
  RSA_get0_crt_params(key->rsa, 
                               ((void *)0)
                                   , 
                                     ((void *)0)
                                         , &rsa_iqmp);
  if ((r = sshbuf_put_bignum2(b, rsa_n)) != 0 ||
      (r = sshbuf_put_bignum2(b, rsa_e)) != 0 ||
      (r = sshbuf_put_bignum2(b, rsa_d)) != 0 ||
      (r = sshbuf_put_bignum2(b, rsa_iqmp)) != 0 ||
      (r = sshbuf_put_bignum2(b, rsa_p)) != 0 ||
      (r = sshbuf_put_bignum2(b, rsa_q)) != 0)
   goto out;
  break;
 case KEY_RSA_CERT:
  if (key->cert == 
                  ((void *)0) 
                       || sshbuf_len(key->cert->certblob) == 0) {
   r = -10;
   goto out;
  }
  RSA_get0_key(key->rsa, 
                        ((void *)0)
                            , 
                              ((void *)0)
                                  , &rsa_d);
  RSA_get0_factors(key->rsa, &rsa_p, &rsa_q);
  RSA_get0_crt_params(key->rsa, 
                               ((void *)0)
                                   , 
                                     ((void *)0)
                                         , &rsa_iqmp);
  if ((r = sshbuf_put_stringb(b, key->cert->certblob)) != 0 ||
      (r = sshbuf_put_bignum2(b, rsa_d)) != 0 ||
      (r = sshbuf_put_bignum2(b, rsa_iqmp)) != 0 ||
      (r = sshbuf_put_bignum2(b, rsa_p)) != 0 ||
      (r = sshbuf_put_bignum2(b, rsa_q)) != 0)
   goto out;
  break;
 case KEY_DSA:
  DSA_get0_pqg(key->dsa, &dsa_p, &dsa_q, &dsa_g);
  DSA_get0_key(key->dsa, &dsa_pub_key, &dsa_priv_key);
  if ((r = sshbuf_put_bignum2(b, dsa_p)) != 0 ||
      (r = sshbuf_put_bignum2(b, dsa_q)) != 0 ||
      (r = sshbuf_put_bignum2(b, dsa_g)) != 0 ||
      (r = sshbuf_put_bignum2(b, dsa_pub_key)) != 0 ||
      (r = sshbuf_put_bignum2(b, dsa_priv_key)) != 0)
   goto out;
  break;
 case KEY_DSA_CERT:
  if (key->cert == 
                  ((void *)0) 
                       || sshbuf_len(key->cert->certblob) == 0) {
   r = -10;
   goto out;
  }
  DSA_get0_key(key->dsa, 
                        ((void *)0)
                            , &dsa_priv_key);
  if ((r = sshbuf_put_stringb(b, key->cert->certblob)) != 0 ||
      (r = sshbuf_put_bignum2(b, dsa_priv_key)) != 0)
   goto out;
  break;

 case KEY_ECDSA:
  if ((r = sshbuf_put_cstring(b,
      sshkey_curve_nid_to_name(key->ecdsa_nid))) != 0 ||
      (r = sshbuf_put_eckey(b, key->ecdsa)) != 0 ||
      (r = sshbuf_put_bignum2(b,
      EC_KEY_get0_private_key(key->ecdsa))) != 0)
   goto out;
  break;
 case KEY_ECDSA_CERT:
  if (key->cert == 
                  ((void *)0) 
                       || sshbuf_len(key->cert->certblob) == 0) {
   r = -10;
   goto out;
  }
  if ((r = sshbuf_put_stringb(b, key->cert->certblob)) != 0 ||
      (r = sshbuf_put_bignum2(b,
      EC_KEY_get0_private_key(key->ecdsa))) != 0)
   goto out;
  break;
 case KEY_ECDSA_SK:
  if ((r = sshbuf_put_cstring(b,
      sshkey_curve_nid_to_name(key->ecdsa_nid))) != 0 ||
      (r = sshbuf_put_eckey(b, key->ecdsa)) != 0 ||
      (r = sshbuf_put_cstring(b, key->sk_application)) != 0 ||
      (r = sshbuf_put_u8(b, key->sk_flags)) != 0 ||
      (r = sshbuf_put_stringb(b, key->sk_key_handle)) != 0 ||
      (r = sshbuf_put_stringb(b, key->sk_reserved)) != 0)
   goto out;
  break;
 case KEY_ECDSA_SK_CERT:
  if (key->cert == 
                  ((void *)0) 
                       || sshbuf_len(key->cert->certblob) == 0) {
   r = -10;
   goto out;
  }
  if ((r = sshbuf_put_stringb(b, key->cert->certblob)) != 0 ||
      (r = sshbuf_put_cstring(b, key->sk_application)) != 0 ||
      (r = sshbuf_put_u8(b, key->sk_flags)) != 0 ||
      (r = sshbuf_put_stringb(b, key->sk_key_handle)) != 0 ||
      (r = sshbuf_put_stringb(b, key->sk_reserved)) != 0)
   goto out;
  break;


 case KEY_ED25519:
  if ((r = sshbuf_put_string(b, key->ed25519_pk,
      32U)) != 0 ||
      (r = sshbuf_put_string(b, key->ed25519_sk,
      64U)) != 0)
   goto out;
  break;
 case KEY_ED25519_CERT:
  if (key->cert == 
                  ((void *)0) 
                       || sshbuf_len(key->cert->certblob) == 0) {
   r = -10;
   goto out;
  }
  if ((r = sshbuf_put_stringb(b, key->cert->certblob)) != 0 ||
      (r = sshbuf_put_string(b, key->ed25519_pk,
      32U)) != 0 ||
      (r = sshbuf_put_string(b, key->ed25519_sk,
      64U)) != 0)
   goto out;
  break;
 case KEY_ED25519_SK:
  if ((r = sshbuf_put_string(b, key->ed25519_pk,
      32U)) != 0 ||
      (r = sshbuf_put_cstring(b, key->sk_application)) != 0 ||
      (r = sshbuf_put_u8(b, key->sk_flags)) != 0 ||
      (r = sshbuf_put_stringb(b, key->sk_key_handle)) != 0 ||
      (r = sshbuf_put_stringb(b, key->sk_reserved)) != 0)
   goto out;
  break;
 case KEY_ED25519_SK_CERT:
  if (key->cert == 
                  ((void *)0) 
                       || sshbuf_len(key->cert->certblob) == 0) {
   r = -10;
   goto out;
  }
  if ((r = sshbuf_put_stringb(b, key->cert->certblob)) != 0 ||
      (r = sshbuf_put_string(b, key->ed25519_pk,
      32U)) != 0 ||
      (r = sshbuf_put_cstring(b, key->sk_application)) != 0 ||
      (r = sshbuf_put_u8(b, key->sk_flags)) != 0 ||
      (r = sshbuf_put_stringb(b, key->sk_key_handle)) != 0 ||
      (r = sshbuf_put_stringb(b, key->sk_reserved)) != 0)
   goto out;
  break;
 default:
  r = -10;
  goto out;
 }




 r = 0;
 out:
 if (was_shielded)
  r = sshkey_shield_private(key);
 if (r == 0)
  r = sshbuf_putb(buf, b);
 sshbuf_free(b);

 return r;
}

int
sshkey_private_serialize(struct sshkey *key, struct sshbuf *b)
{
 return sshkey_private_serialize_opt(key, b,
     SSHKEY_SERIALIZE_DEFAULT);
}

int
sshkey_private_deserialize(struct sshbuf *buf, struct sshkey **kp)
{
 char *tname = 
              ((void *)0)
                  , *curve = 
                             ((void *)0)
                                 , *xmss_name = 
                                                ((void *)0)
                                                    ;
 char *expect_sk_application = 
                              ((void *)0)
                                  ;
 struct sshkey *k = 
                   ((void *)0)
                       ;
 size_t pklen = 0, sklen = 0;
 int type, r = -1;
 u_char *ed25519_pk = 
                     ((void *)0)
                         , *ed25519_sk = 
                                         ((void *)0)
                                             ;
 u_char *expect_ed25519_pk = 
                            ((void *)0)
                                ;
 u_char *xmss_pk = 
                  ((void *)0)
                      , *xmss_sk = 
                                   ((void *)0)
                                       ;

 BIGNUM *exponent = 
                   ((void *)0)
                       ;
 BIGNUM *rsa_n = 
                ((void *)0)
                    , *rsa_e = 
                               ((void *)0)
                                   , *rsa_d = 
                                              ((void *)0)
                                                  ;
 BIGNUM *rsa_iqmp = 
                   ((void *)0)
                       , *rsa_p = 
                                  ((void *)0)
                                      , *rsa_q = 
                                                 ((void *)0)
                                                     ;
 BIGNUM *dsa_p = 
                ((void *)0)
                    , *dsa_q = 
                               ((void *)0)
                                   , *dsa_g = 
                                              ((void *)0)
                                                  ;
 BIGNUM *dsa_pub_key = 
                      ((void *)0)
                          , *dsa_priv_key = 
                                            ((void *)0)
                                                ;


 if (kp != 
          ((void *)0)
              )
  *kp = 
       ((void *)0)
           ;
 if ((r = sshbuf_get_cstring(buf, &tname, 
                                         ((void *)0)
                                             )) != 0)
  goto out;
 type = sshkey_type_from_name(tname);
 if (sshkey_type_is_cert(type)) {





  if ((r = sshkey_froms(buf, &k)) != 0)
   goto out;
  if (k->type != type) {
   r = -45;
   goto out;
  }

  if (k->type == KEY_ECDSA &&
      k->ecdsa_nid != sshkey_ecdsa_nid_from_name(tname)) {
   r = -45;
   goto out;
  }




  expect_sk_application = k->sk_application;
  expect_ed25519_pk = k->ed25519_pk;
  k->sk_application = 
                     ((void *)0)
                         ;
  k->ed25519_pk = 
                 ((void *)0)
                     ;
 } else {
  if ((k = sshkey_new(type)) == 
                               ((void *)0)
                                   ) {
   r = -2;
   goto out;
  }
 }
 switch (type) {

 case KEY_DSA:
  if ((r = sshbuf_get_bignum2(buf, &dsa_p)) != 0 ||
      (r = sshbuf_get_bignum2(buf, &dsa_q)) != 0 ||
      (r = sshbuf_get_bignum2(buf, &dsa_g)) != 0 ||
      (r = sshbuf_get_bignum2(buf, &dsa_pub_key)) != 0)
   goto out;
  if (!DSA_set0_pqg(k->dsa, dsa_p, dsa_q, dsa_g)) {
   r = -22;
   goto out;
  }
  dsa_p = dsa_q = dsa_g = 
                         ((void *)0)
                             ;
  if (!DSA_set0_key(k->dsa, dsa_pub_key, 
                                        ((void *)0)
                                            )) {
   r = -22;
   goto out;
  }
  dsa_pub_key = 
               ((void *)0)
                   ;

 case KEY_DSA_CERT:
  if ((r = sshbuf_get_bignum2(buf, &dsa_priv_key)) != 0)
   goto out;
  if (!DSA_set0_key(k->dsa, 
                           ((void *)0)
                               , dsa_priv_key)) {
   r = -22;
   goto out;
  }
  dsa_priv_key = 
                ((void *)0)
                    ;
  break;

 case KEY_ECDSA:
  if ((k->ecdsa_nid = sshkey_ecdsa_nid_from_name(tname)) == -1) {
   r = -10;
   goto out;
  }
  if ((r = sshbuf_get_cstring(buf, &curve, 
                                          ((void *)0)
                                              )) != 0)
   goto out;
  if (k->ecdsa_nid != sshkey_curve_name_to_nid(curve)) {
   r = -15;
   goto out;
  }
  k->ecdsa = EC_KEY_new_by_curve_name(k->ecdsa_nid);
  if (k->ecdsa == 
                  ((void *)0)
                      ) {
   r = -22;
   goto out;
  }
  if ((r = sshbuf_get_eckey(buf, k->ecdsa)) != 0)
   goto out;

 case KEY_ECDSA_CERT:
  if ((r = sshbuf_get_bignum2(buf, &exponent)) != 0)
   goto out;
  if (EC_KEY_set_private_key(k->ecdsa, exponent) != 1) {
   r = -22;
   goto out;
  }
  if ((r = sshkey_ec_validate_public(EC_KEY_get0_group(k->ecdsa),
      EC_KEY_get0_public_key(k->ecdsa))) != 0 ||
      (r = sshkey_ec_validate_private(k->ecdsa)) != 0)
   goto out;
  break;
 case KEY_ECDSA_SK:
  if ((k->ecdsa_nid = sshkey_ecdsa_nid_from_name(tname)) == -1) {
   r = -10;
   goto out;
  }
  if ((r = sshbuf_get_cstring(buf, &curve, 
                                          ((void *)0)
                                              )) != 0)
   goto out;
  if (k->ecdsa_nid != sshkey_curve_name_to_nid(curve)) {
   r = -15;
   goto out;
  }
  if ((k->sk_key_handle = sshbuf_new()) == 
                                          ((void *)0) 
                                               ||
      (k->sk_reserved = sshbuf_new()) == 
                                        ((void *)0)
                                            ) {
   r = -2;
   goto out;
  }
  k->ecdsa = EC_KEY_new_by_curve_name(k->ecdsa_nid);
  if (k->ecdsa == 
                  ((void *)0)
                      ) {
   r = -22;
   goto out;
  }
  if ((r = sshbuf_get_eckey(buf, k->ecdsa)) != 0 ||
      (r = sshbuf_get_cstring(buf, &k->sk_application,
      
     ((void *)0)
         )) != 0 ||
      (r = sshbuf_get_u8(buf, &k->sk_flags)) != 0 ||
      (r = sshbuf_get_stringb(buf, k->sk_key_handle)) != 0 ||
      (r = sshbuf_get_stringb(buf, k->sk_reserved)) != 0)
   goto out;
  if ((r = sshkey_ec_validate_public(EC_KEY_get0_group(k->ecdsa),
      EC_KEY_get0_public_key(k->ecdsa))) != 0)
   goto out;
  break;
 case KEY_ECDSA_SK_CERT:
  if ((k->sk_key_handle = sshbuf_new()) == 
                                          ((void *)0) 
                                               ||
      (k->sk_reserved = sshbuf_new()) == 
                                        ((void *)0)
                                            ) {
   r = -2;
   goto out;
  }
  if ((r = sshbuf_get_cstring(buf, &k->sk_application,
      
     ((void *)0)
         )) != 0 ||
      (r = sshbuf_get_u8(buf, &k->sk_flags)) != 0 ||
      (r = sshbuf_get_stringb(buf, k->sk_key_handle)) != 0 ||
      (r = sshbuf_get_stringb(buf, k->sk_reserved)) != 0)
   goto out;
  if ((r = sshkey_ec_validate_public(EC_KEY_get0_group(k->ecdsa),
      EC_KEY_get0_public_key(k->ecdsa))) != 0)
   goto out;
  break;

 case KEY_RSA:
  if ((r = sshbuf_get_bignum2(buf, &rsa_n)) != 0 ||
      (r = sshbuf_get_bignum2(buf, &rsa_e)) != 0)
   goto out;
  if (!RSA_set0_key(k->rsa, rsa_n, rsa_e, 
                                         ((void *)0)
                                             )) {
   r = -22;
   goto out;
  }
  rsa_n = rsa_e = 
                 ((void *)0)
                     ;

 case KEY_RSA_CERT:
  if ((r = sshbuf_get_bignum2(buf, &rsa_d)) != 0 ||
      (r = sshbuf_get_bignum2(buf, &rsa_iqmp)) != 0 ||
      (r = sshbuf_get_bignum2(buf, &rsa_p)) != 0 ||
      (r = sshbuf_get_bignum2(buf, &rsa_q)) != 0)
   goto out;
  if (!RSA_set0_key(k->rsa, 
                           ((void *)0)
                               , 
                                 ((void *)0)
                                     , rsa_d)) {
   r = -22;
   goto out;
  }
  rsa_d = 
         ((void *)0)
             ;
  if (!RSA_set0_factors(k->rsa, rsa_p, rsa_q)) {
   r = -22;
   goto out;
  }
  rsa_p = rsa_q = 
                 ((void *)0)
                     ;
  if ((r = sshkey_check_rsa_length(k, 0)) != 0)
   goto out;
  if ((r = ssh_rsa_complete_crt_parameters(k, rsa_iqmp)) != 0)
   goto out;
  break;

 case KEY_ED25519:
 case KEY_ED25519_CERT:
  if ((r = sshbuf_get_string(buf, &ed25519_pk, &pklen)) != 0 ||
      (r = sshbuf_get_string(buf, &ed25519_sk, &sklen)) != 0)
   goto out;
  if (pklen != 32U || sklen != 64U) {
   r = -4;
   goto out;
  }
  k->ed25519_pk = ed25519_pk;
  k->ed25519_sk = ed25519_sk;
  ed25519_pk = ed25519_sk = 
                           ((void *)0)
                               ;
  break;
 case KEY_ED25519_SK:
 case KEY_ED25519_SK_CERT:
  if ((r = sshbuf_get_string(buf, &ed25519_pk, &pklen)) != 0)
   goto out;
  if (pklen != 32U) {
   r = -4;
   goto out;
  }
  if ((k->sk_key_handle = sshbuf_new()) == 
                                          ((void *)0) 
                                               ||
      (k->sk_reserved = sshbuf_new()) == 
                                        ((void *)0)
                                            ) {
   r = -2;
   goto out;
  }
  if ((r = sshbuf_get_cstring(buf, &k->sk_application,
      
     ((void *)0)
         )) != 0 ||
      (r = sshbuf_get_u8(buf, &k->sk_flags)) != 0 ||
      (r = sshbuf_get_stringb(buf, k->sk_key_handle)) != 0 ||
      (r = sshbuf_get_stringb(buf, k->sk_reserved)) != 0)
   goto out;
  k->ed25519_pk = ed25519_pk;
  ed25519_pk = 
              ((void *)0)
                  ;
  break;
 default:
  r = -14;
  goto out;
 }


 switch (k->type) {
 case KEY_RSA:
 case KEY_RSA_CERT:
  if (RSA_blinding_on(k->rsa, 
                             ((void *)0)
                                 ) != 1) {
   r = -22;
   goto out;
  }
  break;
 }

 if ((expect_sk_application != 
                              ((void *)0) 
                                   && (k->sk_application == 
                                                            ((void *)0) 
                                                                 ||
     strcmp(expect_sk_application, k->sk_application) != 0)) ||
     (expect_ed25519_pk != 
                          ((void *)0) 
                               && (k->ed25519_pk == 
                                                    ((void *)0) 
                                                         ||
     memcmp(expect_ed25519_pk, k->ed25519_pk, 32U) != 0))) {
  r = -45;
  goto out;
 }

 r = 0;
 if (kp != 
          ((void *)0)
              ) {
  *kp = k;
  k = 
     ((void *)0)
         ;
 }
 out:
 free(tname);
 free(curve);

 BN_clear_free(exponent);
 BN_clear_free(dsa_p);
 BN_clear_free(dsa_q);
 BN_clear_free(dsa_g);
 BN_clear_free(dsa_pub_key);
 BN_clear_free(dsa_priv_key);
 BN_clear_free(rsa_n);
 BN_clear_free(rsa_e);
 BN_clear_free(rsa_d);
 BN_clear_free(rsa_p);
 BN_clear_free(rsa_q);
 BN_clear_free(rsa_iqmp);

 sshkey_free(k);
 freezero(ed25519_pk, pklen);
 freezero(ed25519_sk, sklen);
 free(xmss_name);
 freezero(xmss_pk, pklen);
 freezero(xmss_sk, sklen);
 free(expect_sk_application);
 free(expect_ed25519_pk);
 return r;
}


int
sshkey_ec_validate_public(const EC_GROUP *group, const EC_POINT *public)
{
 EC_POINT *nq = 
               ((void *)0)
                   ;
 BIGNUM *order = 
                ((void *)0)
                    , *x = 
                           ((void *)0)
                               , *y = 
                                      ((void *)0)
                                          , *tmp = 
                                                   ((void *)0)
                                                       ;
 int ret = -20;
 if (EC_METHOD_get_field_type(EC_GROUP_method_of(group)) !=
     
    406
                         )
  goto out;


 if (EC_POINT_is_at_infinity(group, public))
  goto out;

 if ((x = BN_new()) == 
                      ((void *)0) 
                           ||
     (y = BN_new()) == 
                      ((void *)0) 
                           ||
     (order = BN_new()) == 
                          ((void *)0) 
                               ||
     (tmp = BN_new()) == 
                        ((void *)0)
                            ) {
  ret = -2;
  goto out;
 }


 if (EC_GROUP_get_order(group, order, 
                                     ((void *)0)
                                         ) != 1 ||
     EC_POINT_get_affine_coordinates_GFp(group, public,
     x, y, 
          ((void *)0)
              ) != 1) {
  ret = -22;
  goto out;
 }
 if (BN_num_bits(x) <= BN_num_bits(order) / 2 ||
     BN_num_bits(y) <= BN_num_bits(order) / 2)
  goto out;


 if ((nq = EC_POINT_new(group)) == 
                                  ((void *)0)
                                      ) {
  ret = -2;
  goto out;
 }
 if (EC_POINT_mul(group, nq, 
                            ((void *)0)
                                , public, order, 
                                                 ((void *)0)
                                                     ) != 1) {
  ret = -22;
  goto out;
 }
 if (EC_POINT_is_at_infinity(group, nq) != 1)
  goto out;


 if (!BN_sub(tmp, order, BN_value_one())) {
  ret = -22;
  goto out;
 }
 if (BN_cmp(x, tmp) >= 0 || BN_cmp(y, tmp) >= 0)
  goto out;
 ret = 0;
 out:
 BN_clear_free(x);
 BN_clear_free(y);
 BN_clear_free(order);
 BN_clear_free(tmp);
 EC_POINT_free(nq);
 return ret;
}

int
sshkey_ec_validate_private(const EC_KEY *key)
{
 BIGNUM *order = 
                ((void *)0)
                    , *tmp = 
                             ((void *)0)
                                 ;
 int ret = -20;

 if ((order = BN_new()) == 
                          ((void *)0) 
                               || (tmp = BN_new()) == 
                                                      ((void *)0)
                                                          ) {
  ret = -2;
  goto out;
 }


 if (EC_GROUP_get_order(EC_KEY_get0_group(key), order, 
                                                      ((void *)0)
                                                          ) != 1) {
  ret = -22;
  goto out;
 }
 if (BN_num_bits(EC_KEY_get0_private_key(key)) <=
     BN_num_bits(order) / 2)
  goto out;


 if (!BN_sub(tmp, order, BN_value_one())) {
  ret = -22;
  goto out;
 }
 if (BN_cmp(EC_KEY_get0_private_key(key), tmp) >= 0)
  goto out;
 ret = 0;
 out:
 BN_clear_free(order);
 BN_clear_free(tmp);
 return ret;
}

void
sshkey_dump_ec_point(const EC_GROUP *group, const EC_POINT *point)
{
 BIGNUM *x = 
            ((void *)0)
                , *y = 
                       ((void *)0)
                           ;

 if (point == 
             ((void *)0)
                 ) {
  fputs("point=(NULL)\n", 
                         stderr
                               );
  return;
 }
 if ((x = BN_new()) == 
                      ((void *)0) 
                           || (y = BN_new()) == 
                                                ((void *)0)
                                                    ) {
  fprintf(
         stderr
               , "%s: BN_new failed\n", __func__);
  goto out;
 }
 if (EC_METHOD_get_field_type(EC_GROUP_method_of(group)) !=
     
    406
                         ) {
  fprintf(
         stderr
               , "%s: group is not a prime field\n", __func__);
  goto out;
 }
 if (EC_POINT_get_affine_coordinates_GFp(group, point,
     x, y, 
          ((void *)0)
              ) != 1) {
  fprintf(
         stderr
               , "%s: EC_POINT_get_affine_coordinates_GFp\n",
      __func__);
  goto out;
 }
 fputs("x=", 
            stderr
                  );
 BN_print_fp(
            stderr
                  , x);
 fputs("\ny=", 
              stderr
                    );
 BN_print_fp(
            stderr
                  , y);
 fputs("\n", 
            stderr
                  );
 out:
 BN_clear_free(x);
 BN_clear_free(y);
}

void
sshkey_dump_ec_key(const EC_KEY *key)
{
 const BIGNUM *exponent;

 sshkey_dump_ec_point(EC_KEY_get0_group(key),
     EC_KEY_get0_public_key(key));
 fputs("exponent=", 
                   stderr
                         );
 if ((exponent = EC_KEY_get0_private_key(key)) == 
                                                 ((void *)0)
                                                     )
  fputs("(NULL)", 
                 stderr
                       );
 else
  BN_print_fp(
             stderr
                   , EC_KEY_get0_private_key(key));
 fputs("\n", 
            stderr
                  );
}


static int
sshkey_private_to_blob2(struct sshkey *prv, struct sshbuf *blob,
    const char *passphrase, const char *comment, const char *ciphername,
    int rounds)
{
 u_char *cp, *key = 
                   ((void *)0)
                       , *pubkeyblob = 
                                       ((void *)0)
                                           ;
 u_char salt[16];
 char *b64 = 
            ((void *)0)
                ;
 size_t i, pubkeylen, keylen, ivlen, blocksize, authlen;
 u_int check;
 int r = -1;
 struct sshcipher_ctx *ciphercontext = 
                                      ((void *)0)
                                          ;
 const struct sshcipher *cipher;
 const char *kdfname = "bcrypt";
 struct sshbuf *encoded = 
                         ((void *)0)
                             , *encrypted = 
                                            ((void *)0)
                                                , *kdf = 
                                                         ((void *)0)
                                                             ;

 if (rounds <= 0)
  rounds = 16;
 if (passphrase == 
                  ((void *)0) 
                       || !strlen(passphrase)) {
  ciphername = "none";
  kdfname = "none";
 } else if (ciphername == 
                         ((void *)0)
                             )
  ciphername = "aes256-ctr";
 if ((cipher = cipher_by_name(ciphername)) == 
                                             ((void *)0)
                                                 ) {
  r = -10;
  goto out;
 }

 if ((kdf = sshbuf_new()) == 
                            ((void *)0) 
                                 ||
     (encoded = sshbuf_new()) == 
                                ((void *)0) 
                                     ||
     (encrypted = sshbuf_new()) == 
                                  ((void *)0)
                                      ) {
  r = -2;
  goto out;
 }
 blocksize = cipher_blocksize(cipher);
 keylen = cipher_keylen(cipher);
 ivlen = cipher_ivlen(cipher);
 authlen = cipher_authlen(cipher);
 if ((key = calloc(1, keylen + ivlen)) == 
                                         ((void *)0)
                                             ) {
  r = -2;
  goto out;
 }
 if (strcmp(kdfname, "bcrypt") == 0) {
  arc4random_buf(salt, 16);
  if (bcrypt_pbkdf(passphrase, strlen(passphrase),
      salt, 16, key, keylen + ivlen, rounds) < 0) {
   r = -10;
   goto out;
  }
  if ((r = sshbuf_put_string(kdf, salt, 16)) != 0 ||
      (r = sshbuf_put_u32(kdf, rounds)) != 0)
   goto out;
 } else if (strcmp(kdfname, "none") != 0) {

  r = -42;
  goto out;
 }
 if ((r = cipher_init(&ciphercontext, cipher, key, keylen,
     key + keylen, ivlen, 1)) != 0)
  goto out;

 if ((r = sshbuf_put(encoded, "openssh-key-v1", sizeof("openssh-key-v1"))) != 0 ||
     (r = sshbuf_put_cstring(encoded, ciphername)) != 0 ||
     (r = sshbuf_put_cstring(encoded, kdfname)) != 0 ||
     (r = sshbuf_put_stringb(encoded, kdf)) != 0 ||
     (r = sshbuf_put_u32(encoded, 1)) != 0 ||
     (r = sshkey_to_blob(prv, &pubkeyblob, &pubkeylen)) != 0 ||
     (r = sshbuf_put_string(encoded, pubkeyblob, pubkeylen)) != 0)
  goto out;




 check = arc4random();
 if ((r = sshbuf_put_u32(encrypted, check)) != 0 ||
     (r = sshbuf_put_u32(encrypted, check)) != 0)
  goto out;


 if ((r = sshkey_private_serialize_opt(prv, encrypted,
     SSHKEY_SERIALIZE_FULL)) != 0 ||
     (r = sshbuf_put_cstring(encrypted, comment)) != 0)
  goto out;


 i = 0;
 while (sshbuf_len(encrypted) % blocksize) {
  if ((r = sshbuf_put_u8(encrypted, ++i & 0xff)) != 0)
   goto out;
 }


 if ((r = sshbuf_put_u32(encoded, sshbuf_len(encrypted))) != 0)
  goto out;


 if ((r = sshbuf_reserve(encoded,
     sshbuf_len(encrypted) + authlen, &cp)) != 0)
  goto out;
 if ((r = cipher_crypt(ciphercontext, 0, cp,
     sshbuf_ptr(encrypted), sshbuf_len(encrypted), 0, authlen)) != 0)
  goto out;

 sshbuf_reset(blob);


 if ((r = sshbuf_put(blob, "-----BEGIN OPENSSH PRIVATE KEY-----\n", (sizeof("-----BEGIN OPENSSH PRIVATE KEY-----\n") - 1))) != 0 ||
     (r = sshbuf_dtob64(encoded, blob, 1)) != 0 ||
     (r = sshbuf_put(blob, "-----END OPENSSH PRIVATE KEY-----\n", (sizeof("-----END OPENSSH PRIVATE KEY-----\n") - 1))) != 0)
  goto out;


 r = 0;

 out:
 sshbuf_free(kdf);
 sshbuf_free(encoded);
 sshbuf_free(encrypted);
 cipher_free(ciphercontext);
 explicit_bzero(salt, sizeof(salt));
 if (key != 
           ((void *)0)
               )
  freezero(key, keylen + ivlen);
 if (pubkeyblob != 
                  ((void *)0)
                      )
  freezero(pubkeyblob, pubkeylen);
 if (b64 != 
           ((void *)0)
               )
  freezero(b64, strlen(b64));
 return r;
}

static int
private2_uudecode(struct sshbuf *blob, struct sshbuf **decodedp)
{
 const u_char *cp;
 size_t encoded_len;
 int r;
 u_char last;
 struct sshbuf *encoded = 
                         ((void *)0)
                             , *decoded = 
                                          ((void *)0)
                                              ;

 if (blob == 
            ((void *)0) 
                 || decodedp == 
                                ((void *)0)
                                    )
  return -10;

 *decodedp = 
            ((void *)0)
                ;

 if ((encoded = sshbuf_new()) == 
                                ((void *)0) 
                                     ||
     (decoded = sshbuf_new()) == 
                                ((void *)0)
                                    ) {
  r = -2;
  goto out;
 }


 cp = sshbuf_ptr(blob);
 encoded_len = sshbuf_len(blob);
 if (encoded_len < ((sizeof("-----BEGIN OPENSSH PRIVATE KEY-----\n") - 1) + (sizeof("-----END OPENSSH PRIVATE KEY-----\n") - 1)) ||
     memcmp(cp, "-----BEGIN OPENSSH PRIVATE KEY-----\n", (sizeof("-----BEGIN OPENSSH PRIVATE KEY-----\n") - 1)) != 0) {
  r = -4;
  goto out;
 }
 cp += (sizeof("-----BEGIN OPENSSH PRIVATE KEY-----\n") - 1);
 encoded_len -= (sizeof("-----BEGIN OPENSSH PRIVATE KEY-----\n") - 1);


 while (encoded_len > 0) {
  if (*cp != '\n' && *cp != '\r') {
   if ((r = sshbuf_put_u8(encoded, *cp)) != 0)
    goto out;
  }
  last = *cp;
  encoded_len--;
  cp++;
  if (last == '\n') {
   if (encoded_len >= (sizeof("-----END OPENSSH PRIVATE KEY-----\n") - 1) &&
       memcmp(cp, "-----END OPENSSH PRIVATE KEY-----\n", (sizeof("-----END OPENSSH PRIVATE KEY-----\n") - 1)) == 0) {

    if ((r = sshbuf_put_u8(encoded, 0)) != 0)
     goto out;
    break;
   }
  }
 }
 if (encoded_len == 0) {
  r = -4;
  goto out;
 }


 if ((r = sshbuf_b64tod(decoded, (char *)sshbuf_ptr(encoded))) != 0)
  goto out;


 if (sshbuf_len(decoded) < sizeof("openssh-key-v1") ||
     memcmp(sshbuf_ptr(decoded), "openssh-key-v1", sizeof("openssh-key-v1"))) {
  r = -4;
  goto out;
 }

 *decodedp = decoded;
 decoded = 
          ((void *)0)
              ;
 r = 0;
 out:
 sshbuf_free(encoded);
 sshbuf_free(decoded);
 return r;
}

static int
private2_decrypt(struct sshbuf *decoded, const char *passphrase,
    struct sshbuf **decryptedp, struct sshkey **pubkeyp)
{
 char *ciphername = 
                   ((void *)0)
                       , *kdfname = 
                                    ((void *)0)
                                        ;
 const struct sshcipher *cipher = 
                                 ((void *)0)
                                     ;
 int r = -1;
 size_t keylen = 0, ivlen = 0, authlen = 0, slen = 0;
 struct sshbuf *kdf = 
                     ((void *)0)
                         , *decrypted = 
                                        ((void *)0)
                                            ;
 struct sshcipher_ctx *ciphercontext = 
                                      ((void *)0)
                                          ;
 struct sshkey *pubkey = 
                        ((void *)0)
                            ;
 u_char *key = 
              ((void *)0)
                  , *salt = 
                            ((void *)0)
                                , *dp;
 u_int blocksize, rounds, nkeys, encrypted_len, check1, check2;

 if (decoded == 
               ((void *)0) 
                    || decryptedp == 
                                     ((void *)0) 
                                          || pubkeyp == 
                                                        ((void *)0)
                                                            )
  return -10;

 *decryptedp = 
              ((void *)0)
                  ;
 *pubkeyp = 
           ((void *)0)
               ;

 if ((decrypted = sshbuf_new()) == 
                                  ((void *)0)
                                      ) {
  r = -2;
  goto out;
 }


 if ((r = sshbuf_consume(decoded, sizeof("openssh-key-v1"))) != 0 ||
     (r = sshbuf_get_cstring(decoded, &ciphername, 
                                                  ((void *)0)
                                                      )) != 0 ||
     (r = sshbuf_get_cstring(decoded, &kdfname, 
                                               ((void *)0)
                                                   )) != 0 ||
     (r = sshbuf_froms(decoded, &kdf)) != 0 ||
     (r = sshbuf_get_u32(decoded, &nkeys)) != 0)
  goto out;

 if (nkeys != 1) {

  r = -4;
  goto out;
 }

 if ((r = sshkey_froms(decoded, &pubkey)) != 0 ||
     (r = sshbuf_get_u32(decoded, &encrypted_len)) != 0)
  goto out;

 if ((cipher = cipher_by_name(ciphername)) == 
                                             ((void *)0)
                                                 ) {
  r = -42;
  goto out;
 }
 if (strcmp(kdfname, "none") != 0 && strcmp(kdfname, "bcrypt") != 0) {
  r = -42;
  goto out;
 }
 if (strcmp(kdfname, "none") == 0 && strcmp(ciphername, "none") != 0) {
  r = -4;
  goto out;
 }
 if ((passphrase == 
                   ((void *)0) 
                        || strlen(passphrase) == 0) &&
     strcmp(kdfname, "none") != 0) {

  r = -43;
  goto out;
 }


 blocksize = cipher_blocksize(cipher);
 if (encrypted_len < blocksize || (encrypted_len % blocksize) != 0) {
  r = -4;
  goto out;
 }


 keylen = cipher_keylen(cipher);
 ivlen = cipher_ivlen(cipher);
 authlen = cipher_authlen(cipher);
 if ((key = calloc(1, keylen + ivlen)) == 
                                         ((void *)0)
                                             ) {
  r = -2;
  goto out;
 }
 if (strcmp(kdfname, "bcrypt") == 0) {
  if ((r = sshbuf_get_string(kdf, &salt, &slen)) != 0 ||
      (r = sshbuf_get_u32(kdf, &rounds)) != 0)
   goto out;
  if (bcrypt_pbkdf(passphrase, strlen(passphrase), salt, slen,
      key, keylen + ivlen, rounds) < 0) {
   r = -4;
   goto out;
  }
 }


 if (sshbuf_len(decoded) < authlen ||
     sshbuf_len(decoded) - authlen < encrypted_len) {
  r = -4;
  goto out;
 }


 if ((r = sshbuf_reserve(decrypted, encrypted_len, &dp)) != 0 ||
     (r = cipher_init(&ciphercontext, cipher, key, keylen,
     key + keylen, ivlen, 0)) != 0)
  goto out;
 if ((r = cipher_crypt(ciphercontext, 0, dp, sshbuf_ptr(decoded),
     encrypted_len, 0, authlen)) != 0) {

  if (r == -30)
   r = -43;
  goto out;
 }
 if ((r = sshbuf_consume(decoded, encrypted_len + authlen)) != 0)
  goto out;

 if (sshbuf_len(decoded) != 0) {
  r = -4;
  goto out;
 }


 if ((r = sshbuf_get_u32(decrypted, &check1)) != 0 ||
     (r = sshbuf_get_u32(decrypted, &check2)) != 0)
  goto out;
 if (check1 != check2) {
  r = -43;
  goto out;
 }

 *decryptedp = decrypted;
 decrypted = 
            ((void *)0)
                ;
 *pubkeyp = pubkey;
 pubkey = 
         ((void *)0)
             ;
 r = 0;
 out:
 cipher_free(ciphercontext);
 free(ciphername);
 free(kdfname);
 sshkey_free(pubkey);
 if (salt != 
            ((void *)0)
                ) {
  explicit_bzero(salt, slen);
  free(salt);
 }
 if (key != 
           ((void *)0)
               ) {
  explicit_bzero(key, keylen + ivlen);
  free(key);
 }
 sshbuf_free(kdf);
 sshbuf_free(decrypted);
 return r;
}

static int
sshkey_parse_private2(struct sshbuf *blob, int type, const char *passphrase,
    struct sshkey **keyp, char **commentp)
{
 char *comment = 
                ((void *)0)
                    ;
 int r = -1;
 struct sshbuf *decoded = 
                         ((void *)0)
                             , *decrypted = 
                                            ((void *)0)
                                                ;
 struct sshkey *k = 
                   ((void *)0)
                       , *pubkey = 
                                   ((void *)0)
                                       ;

 if (keyp != 
            ((void *)0)
                )
  *keyp = 
         ((void *)0)
             ;
 if (commentp != 
                ((void *)0)
                    )
  *commentp = 
             ((void *)0)
                 ;


 if ((r = private2_uudecode(blob, &decoded)) != 0 ||
     (r = private2_decrypt(decoded, passphrase,
     &decrypted, &pubkey)) != 0)
  goto out;

 if (type != KEY_UNSPEC &&
     sshkey_type_plain(type) != sshkey_type_plain(pubkey->type)) {
  r = -13;
  goto out;
 }


 if ((r = sshkey_private_deserialize(decrypted, &k)) != 0 ||
     (r = sshbuf_get_cstring(decrypted, &comment, 
                                                 ((void *)0)
                                                     )) != 0)
  goto out;


 if ((r = private2_check_padding(decrypted)) != 0)
  goto out;


 if (!sshkey_equal(pubkey, k)) {
  r = -4;
  goto out;
 }


 r = 0;
 if (keyp != 
            ((void *)0)
                ) {
  *keyp = k;
  k = 
     ((void *)0)
         ;
 }
 if (commentp != 
                ((void *)0)
                    ) {
  *commentp = comment;
  comment = 
           ((void *)0)
               ;
 }
 out:
 free(comment);
 sshbuf_free(decoded);
 sshbuf_free(decrypted);
 sshkey_free(k);
 sshkey_free(pubkey);
 return r;
}

static int
sshkey_parse_private2_pubkey(struct sshbuf *blob, int type,
    struct sshkey **keyp)
{
 int r = -1;
 struct sshbuf *decoded = 
                         ((void *)0)
                             ;
 struct sshkey *pubkey = 
                        ((void *)0)
                            ;
 u_int nkeys = 0;

 if (keyp != 
            ((void *)0)
                )
  *keyp = 
         ((void *)0)
             ;

 if ((r = private2_uudecode(blob, &decoded)) != 0)
  goto out;

 if ((r = sshbuf_consume(decoded, sizeof("openssh-key-v1"))) != 0 ||
     (r = sshbuf_get_string_direct(decoded, 
         ((void *)0)
         , 
         ((void *)0)
         )) != 0 ||
     (r = sshbuf_get_string_direct(decoded, 
         ((void *)0)
         , 
         ((void *)0)
         )) != 0 ||
     (r = sshbuf_get_string_direct(decoded, 
         ((void *)0)
         , 
         ((void *)0)
         )) != 0 ||
     (r = sshbuf_get_u32(decoded, &nkeys)) != 0)
  goto out;

 if (nkeys != 1) {

  r = -4;
  goto out;
 }


 if ((r = sshkey_froms(decoded, &pubkey)) != 0)
  goto out;

 if (type != KEY_UNSPEC &&
     sshkey_type_plain(type) != sshkey_type_plain(pubkey->type)) {
  r = -13;
  goto out;
 }


 r = 0;
 if (keyp != 
            ((void *)0)
                ) {
  *keyp = pubkey;
  pubkey = 
          ((void *)0)
              ;
 }
 out:
 sshbuf_free(decoded);
 sshkey_free(pubkey);
 return r;
}



static int
sshkey_private_to_blob_pem_pkcs8(struct sshkey *key, struct sshbuf *buf,
    int format, const char *_passphrase, const char *comment)
{
 int was_shielded = sshkey_is_shielded(key);
 int success, r;
 int blen, len = strlen(_passphrase);
 u_char *passphrase = (len > 0) ? (u_char *)_passphrase : 
                                                         ((void *)0)
                                                             ;
 const EVP_CIPHER *cipher = (len > 0) ? EVP_aes_128_cbc() : 
                                                           ((void *)0)
                                                               ;
 char *bptr;
 BIO *bio = 
           ((void *)0)
               ;
 struct sshbuf *blob;
 EVP_PKEY *pkey = 
                 ((void *)0)
                     ;

 if (len > 0 && len <= 4)
  return -40;
 if ((blob = sshbuf_new()) == 
                             ((void *)0)
                                 )
  return -2;
 if ((bio = BIO_new(BIO_s_mem())) == 
                                    ((void *)0)
                                        ) {
  r = -2;
  goto out;
 }
 if (format == SSHKEY_PRIVATE_PKCS8 && (pkey = EVP_PKEY_new()) == 
                                                                 ((void *)0)
                                                                     ) {
  r = -2;
  goto out;
 }
 if ((r = sshkey_unshield_private(key)) != 0)
  goto out;

 switch (key->type) {
 case KEY_DSA:
  if (format == SSHKEY_PRIVATE_PEM) {
   success = PEM_write_bio_DSAPrivateKey(bio, key->dsa,
       cipher, passphrase, len, 
                               ((void *)0)
                                   , 
                                     ((void *)0)
                                         );
  } else {
   success = EVP_PKEY_set1_DSA(pkey, key->dsa);
  }
  break;

 case KEY_ECDSA:
  if (format == SSHKEY_PRIVATE_PEM) {
   success = PEM_write_bio_ECPrivateKey(bio, key->ecdsa,
       cipher, passphrase, len, 
                               ((void *)0)
                                   , 
                                     ((void *)0)
                                         );
  } else {
   success = EVP_PKEY_set1_EC_KEY(pkey, key->ecdsa);
  }
  break;

 case KEY_RSA:
  if (format == SSHKEY_PRIVATE_PEM) {
   success = PEM_write_bio_RSAPrivateKey(bio, key->rsa,
       cipher, passphrase, len, 
                               ((void *)0)
                                   , 
                                     ((void *)0)
                                         );
  } else {
   success = EVP_PKEY_set1_RSA(pkey, key->rsa);
  }
  break;
 default:
  success = 0;
  break;
 }
 if (success == 0) {
  r = -22;
  goto out;
 }
 if (format == SSHKEY_PRIVATE_PKCS8) {
  if ((success = PEM_write_bio_PrivateKey(bio, pkey, cipher,
      passphrase, len, 
                      ((void *)0)
                          , 
                            ((void *)0)
                                )) == 0) {
   r = -22;
   goto out;
  }
 }
 if ((blen = 
            BIO_ctrl(
            bio
            ,3,0,(char *)(
            &bptr
            ))
                                        ) <= 0) {
  r = -1;
  goto out;
 }
 if ((r = sshbuf_put(blob, bptr, blen)) != 0)
  goto out;
 r = 0;
 out:
 if (was_shielded)
  r = sshkey_shield_private(key);
 if (r == 0)
  r = sshbuf_putb(buf, blob);

 EVP_PKEY_free(pkey);
 sshbuf_free(blob);
 BIO_free(bio);
 return r;
}



int
sshkey_private_to_fileblob(struct sshkey *key, struct sshbuf *blob,
    const char *passphrase, const char *comment,
    int format, const char *openssh_format_cipher, int openssh_format_rounds)
{
 switch (key->type) {

 case KEY_DSA:
 case KEY_ECDSA:
 case KEY_RSA:
  break;

 case KEY_ED25519:
 case KEY_ED25519_SK:




 case KEY_ECDSA_SK:

  return sshkey_private_to_blob2(key, blob, passphrase,
      comment, openssh_format_cipher, openssh_format_rounds);
 default:
  return -14;
 }


 switch (format) {
 case SSHKEY_PRIVATE_OPENSSH:
  return sshkey_private_to_blob2(key, blob, passphrase,
      comment, openssh_format_cipher, openssh_format_rounds);
 case SSHKEY_PRIVATE_PEM:
 case SSHKEY_PRIVATE_PKCS8:
  return sshkey_private_to_blob_pem_pkcs8(key, blob,
      format, passphrase, comment);
 default:
  return -10;
 }

}


static int
translate_libcrypto_error(unsigned long pem_err)
{
 int pem_reason = ERR_GET_REASON(pem_err);

 switch (ERR_GET_LIB(pem_err)) {
 case 
     9
                :
  switch (pem_reason) {
  case 
      104
                             :
  case 
      109
                                     :
  case 
      101
                       :
   return -43;
  default:
   return -4;
  }
 case 
     6
                :
  switch (pem_reason) {
  case 
      100
                       :
   return -43;



  case 
      114
                        :

  case 
      145
                                    :

   return -4;
  default:
   return -22;
  }
 case 
     13
                 :
  return -4;
 }
 return -22;
}

static void
clear_libcrypto_errors(void)
{
 while (ERR_get_error() != 0)
  ;
}





static int
convert_libcrypto_error(void)
{




 if (translate_libcrypto_error(ERR_peek_error()) ==
     -43)
  return -43;
 return translate_libcrypto_error(ERR_peek_last_error());
}

static int
pem_passphrase_cb(char *buf, int size, int rwflag, void *u)
{
 char *p = (char *)u;
 size_t len;

 if (p == 
         ((void *)0) 
              || (len = strlen(p)) == 0)
  return -1;
 if (size < 0 || len > (size_t)size)
  return -1;
 memcpy(buf, p, len);
 return (int)len;
}

static int
sshkey_parse_private_pem_fileblob(struct sshbuf *blob, int type,
    const char *passphrase, struct sshkey **keyp)
{
 EVP_PKEY *pk = 
               ((void *)0)
                   ;
 struct sshkey *prv = 
                     ((void *)0)
                         ;
 BIO *bio = 
           ((void *)0)
               ;
 int r;

 if (keyp != 
            ((void *)0)
                )
  *keyp = 
         ((void *)0)
             ;

 if ((bio = BIO_new(BIO_s_mem())) == 
                                    ((void *)0) 
                                         || sshbuf_len(blob) > 0x7fffffff)
  return -2;
 if (BIO_write(bio, sshbuf_ptr(blob), sshbuf_len(blob)) !=
     (int)sshbuf_len(blob)) {
  r = -2;
  goto out;
 }

 clear_libcrypto_errors();
 if ((pk = PEM_read_bio_PrivateKey(bio, 
                                       ((void *)0)
                                           , pem_passphrase_cb,
     (char *)passphrase)) == 
                            ((void *)0)
                                ) {






  if (passphrase != 
                   ((void *)0) 
                        && *passphrase != '\0')
   r = -43;
  else
   r = convert_libcrypto_error();
  goto out;
 }
 if (
    EVP_PKEY_get_base_id
                    (pk) == 
                            6 
                                         &&
     (type == KEY_UNSPEC || type == KEY_RSA)) {
  if ((prv = sshkey_new(KEY_UNSPEC)) == 
                                       ((void *)0)
                                           ) {
   r = -2;
   goto out;
  }
  prv->rsa = EVP_PKEY_get1_RSA(pk);
  prv->type = KEY_RSA;



  if (RSA_blinding_on(prv->rsa, 
                               ((void *)0)
                                   ) != 1) {
   r = -22;
   goto out;
  }
  if ((r = sshkey_check_rsa_length(prv, 0)) != 0)
   goto out;
 } else if (
           EVP_PKEY_get_base_id
                           (pk) == 
                                   116 
                                                &&
     (type == KEY_UNSPEC || type == KEY_DSA)) {
  if ((prv = sshkey_new(KEY_UNSPEC)) == 
                                       ((void *)0)
                                           ) {
   r = -2;
   goto out;
  }
  prv->dsa = EVP_PKEY_get1_DSA(pk);
  prv->type = KEY_DSA;




 } else if (
           EVP_PKEY_get_base_id
                           (pk) == 
                                   408 
                                               &&
     (type == KEY_UNSPEC || type == KEY_ECDSA)) {
  if ((prv = sshkey_new(KEY_UNSPEC)) == 
                                       ((void *)0)
                                           ) {
   r = -2;
   goto out;
  }
  prv->ecdsa = EVP_PKEY_get1_EC_KEY(pk);
  prv->type = KEY_ECDSA;
  prv->ecdsa_nid = sshkey_ecdsa_key_to_nid(prv->ecdsa);
  if (prv->ecdsa_nid == -1 ||
      sshkey_curve_nid_to_name(prv->ecdsa_nid) == 
                                                 ((void *)0) 
                                                      ||
      sshkey_ec_validate_public(EC_KEY_get0_group(prv->ecdsa),
      EC_KEY_get0_public_key(prv->ecdsa)) != 0 ||
      sshkey_ec_validate_private(prv->ecdsa) != 0) {
   r = -4;
   goto out;
  }





 } else {
  r = -4;
  goto out;
 }
 r = 0;
 if (keyp != 
            ((void *)0)
                ) {
  *keyp = prv;
  prv = 
       ((void *)0)
           ;
 }
 out:
 BIO_free(bio);
 EVP_PKEY_free(pk);
 sshkey_free(prv);
 return r;
}


int
sshkey_parse_private_fileblob_type(struct sshbuf *blob, int type,
    const char *passphrase, struct sshkey **keyp, char **commentp)
{
 int r = -1;

 if (keyp != 
            ((void *)0)
                )
  *keyp = 
         ((void *)0)
             ;
 if (commentp != 
                ((void *)0)
                    )
  *commentp = 
             ((void *)0)
                 ;

 switch (type) {
 case KEY_ED25519:
 case KEY_XMSS:

  return sshkey_parse_private2(blob, type, passphrase,
      keyp, commentp);
 default:
  r = sshkey_parse_private2(blob, type, passphrase, keyp,
      commentp);

  if (r != -4)
   return r;

  return sshkey_parse_private_pem_fileblob(blob, type,
      passphrase, keyp);



 }
}

int
sshkey_parse_private_fileblob(struct sshbuf *buffer, const char *passphrase,
    struct sshkey **keyp, char **commentp)
{
 if (keyp != 
            ((void *)0)
                )
  *keyp = 
         ((void *)0)
             ;
 if (commentp != 
                ((void *)0)
                    )
  *commentp = 
             ((void *)0)
                 ;

 return sshkey_parse_private_fileblob_type(buffer, KEY_UNSPEC,
     passphrase, keyp, commentp);
}

void
sshkey_sig_details_free(struct sshkey_sig_details *details)
{
 freezero(details, sizeof(*details));
}

int
sshkey_parse_pubkey_from_private_fileblob_type(struct sshbuf *blob, int type,
    struct sshkey **pubkeyp)
{
 int r = -1;

 if (pubkeyp != 
               ((void *)0)
                   )
  *pubkeyp = 
            ((void *)0)
                ;

 if ((r = sshkey_parse_private2_pubkey(blob, type, pubkeyp)) != 0)
  return r;
 return 0;
}
int
sshkey_private_serialize_maxsign(struct sshkey *k, struct sshbuf *b,
    u_int32_t maxsign, int printerror)
{
 return sshkey_private_serialize_opt(k, b, SSHKEY_SERIALIZE_DEFAULT);
}

u_int32_t
sshkey_signatures_left(const struct sshkey *k)
{
 return 0;
}

int
sshkey_enable_maxsign(struct sshkey *k, u_int32_t maxsign)
{
 return -10;
}

int
sshkey_set_filename(struct sshkey *k, const char *filename)
{
 if (k == 
         ((void *)0)
             )
  return -10;
 return 0;
}
