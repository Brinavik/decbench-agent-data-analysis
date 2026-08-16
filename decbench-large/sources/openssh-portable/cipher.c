











































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
const char *ssh_err(int n);
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






int ssh_compatible_openssl(long, long);
void ssh_libcrypto_init(void);
int EVP_CIPHER_CTX_set_iv(EVP_CIPHER_CTX *ctx,
    const unsigned char *iv, size_t len);
void DSA_SIG_get0(const DSA_SIG *sig, const BIGNUM **pr, const BIGNUM **ps);



int DSA_SIG_set0(DSA_SIG *sig, BIGNUM *r, BIGNUM *s);
EVP_MD_CTX *EVP_MD_CTX_new(void);



void EVP_MD_CTX_free(EVP_MD_CTX *ctx);





struct sshcipher_ctx {
 int plaintext;
 int encrypt;
 EVP_CIPHER_CTX *evp;
 struct chachapoly_ctx *cp_ctx;
 struct aesctr_ctx ac_ctx;
 const struct sshcipher *cipher;
};

struct sshcipher {
 char *name;
 u_int block_size;
 u_int key_len;
 u_int iv_len;
 u_int auth_len;
 u_int flags;






 const EVP_CIPHER *(*evptype)(void);



};

static const struct sshcipher ciphers[] = {


 { "3des-cbc", 8, 24, 0, 0, (1<<0), EVP_des_ede3_cbc },

 { "aes128-cbc", 16, 16, 0, 0, (1<<0), EVP_aes_128_cbc },
 { "aes192-cbc", 16, 24, 0, 0, (1<<0), EVP_aes_192_cbc },
 { "aes256-cbc", 16, 32, 0, 0, (1<<0), EVP_aes_256_cbc },
 { "aes128-ctr", 16, 16, 0, 0, 0, EVP_aes_128_ctr },
 { "aes192-ctr", 16, 24, 0, 0, 0, EVP_aes_192_ctr },
 { "aes256-ctr", 16, 32, 0, 0, 0, EVP_aes_256_ctr },
 { "aes128-gcm@openssh.com",
    16, 16, 12, 16, 0, EVP_aes_128_gcm },
 { "aes256-gcm@openssh.com",
    16, 32, 12, 16, 0, EVP_aes_256_gcm },





 { "chacha20-poly1305@openssh.com",
    8, 64, 0, 16, (1<<1), 
                                   ((void *)0) 
                                        },
 { "none", 8, 0, 0, 0, (1<<3), 
                                   ((void *)0) 
                                        },

 { 
  ((void *)0)
      , 0, 0, 0, 0, 0, 
                         ((void *)0) 
                              }
};




char *
cipher_alg_list(char sep, int auth_only)
{
 char *tmp, *ret = 
                  ((void *)0)
                      ;
 size_t nlen, rlen = 0;
 const struct sshcipher *c;

 for (c = ciphers; c->name != 
                             ((void *)0)
                                 ; c++) {
  if ((c->flags & (1<<3)) != 0)
   continue;
  if (auth_only && c->auth_len == 0)
   continue;
  if (ret != 
            ((void *)0)
                )
   ret[rlen++] = sep;
  nlen = strlen(c->name);
  if ((tmp = realloc(ret, rlen + nlen + 2)) == 
                                              ((void *)0)
                                                  ) {
   free(ret);
   return 
         ((void *)0)
             ;
  }
  ret = tmp;
  memcpy(ret + rlen, c->name, nlen + 1);
  rlen += nlen;
 }
 return ret;
}

const char *
compression_alg_list(int compression)
{

 return compression ? "zlib@openssh.com,zlib,none" :
     "none,zlib@openssh.com,zlib";



}

u_int
cipher_blocksize(const struct sshcipher *c)
{
 return (c->block_size);
}

u_int
cipher_keylen(const struct sshcipher *c)
{
 return (c->key_len);
}

u_int
cipher_seclen(const struct sshcipher *c)
{
 if (strcmp("3des-cbc", c->name) == 0)
  return 14;
 return cipher_keylen(c);
}

u_int
cipher_authlen(const struct sshcipher *c)
{
 return (c->auth_len);
}

u_int
cipher_ivlen(const struct sshcipher *c)
{




 return (c->iv_len != 0 || (c->flags & (1<<1)) != 0) ?
     c->iv_len : c->block_size;
}

u_int
cipher_is_cbc(const struct sshcipher *c)
{
 return (c->flags & (1<<0)) != 0;
}

u_int
cipher_ctx_is_plaintext(struct sshcipher_ctx *cc)
{
 return cc->plaintext;
}

const struct sshcipher *
cipher_by_name(const char *name)
{
 const struct sshcipher *c;
 for (c = ciphers; c->name != 
                             ((void *)0)
                                 ; c++)
  if (strcmp(c->name, name) == 0)
   return c;
 return 
       ((void *)0)
           ;
}


int
ciphers_valid(const char *names)
{
 const struct sshcipher *c;
 char *cipher_list, *cp;
 char *p;

 if (names == 
             ((void *)0) 
                  || strcmp(names, "") == 0)
  return 0;
 if ((cipher_list = cp = strdup(names)) == 
                                          ((void *)0)
                                              )
  return 0;
 for ((p = strsep(&cp, ",")); p && *p != '\0';
     (p = strsep(&cp, ","))) {
  c = cipher_by_name(p);
  if (c == 
          ((void *)0) 
               || (c->flags & (1<<3)) != 0) {
   free(cipher_list);
   return 0;
  }
 }
 free(cipher_list);
 return 1;
}

const char *
cipher_warning_message(const struct sshcipher_ctx *cc)
{
 if (cc == 
          ((void *)0) 
               || cc->cipher == 
                                ((void *)0)
                                    )
  return 
        ((void *)0)
            ;

 return 
       ((void *)0)
           ;
}

int
cipher_init(struct sshcipher_ctx **ccp, const struct sshcipher *cipher,
    const u_char *key, u_int keylen, const u_char *iv, u_int ivlen,
    int do_encrypt)
{
 struct sshcipher_ctx *cc = 
                           ((void *)0)
                               ;
 int ret = -1;

 const EVP_CIPHER *type;
 int klen;


 *ccp = 
       ((void *)0)
           ;
 if ((cc = calloc(sizeof(*cc), 1)) == 
                                     ((void *)0)
                                         )
  return -2;

 cc->plaintext = (cipher->flags & (1<<3)) != 0;
 cc->encrypt = do_encrypt;

 if (keylen < cipher->key_len ||
     (iv != 
           ((void *)0) 
                && ivlen < cipher_ivlen(cipher))) {
  ret = -10;
  goto out;
 }

 cc->cipher = cipher;
 if ((cc->cipher->flags & (1<<1)) != 0) {
  cc->cp_ctx = chachapoly_new(key, keylen);
  ret = cc->cp_ctx != 
                     ((void *)0) 
                          ? 0 : -10;
  goto out;
 }
 if ((cc->cipher->flags & (1<<3)) != 0) {
  ret = 0;
  goto out;
 }
 type = (*cipher->evptype)();
 if ((cc->evp = EVP_CIPHER_CTX_new()) == 
                                        ((void *)0)
                                            ) {
  ret = -2;
  goto out;
 }
 if (EVP_CipherInit(cc->evp, type, 
                                  ((void *)0)
                                      , (u_char *)iv,
     (do_encrypt == 1)) == 0) {
  ret = -22;
  goto out;
 }
 if (cipher_authlen(cipher) &&
     !EVP_CIPHER_CTX_ctrl(cc->evp, 
                                  0x12
                                                           ,
     -1, (u_char *)iv)) {
  ret = -22;
  goto out;
 }
 klen = 
       EVP_CIPHER_CTX_get_key_length
                                (cc->evp);
 if (klen > 0 && keylen != (u_int)klen) {
  if (EVP_CIPHER_CTX_set_key_length(cc->evp, keylen) == 0) {
   ret = -22;
   goto out;
  }
 }
 if (EVP_CipherInit(cc->evp, 
                            ((void *)0)
                                , (u_char *)key, 
                                                 ((void *)0)
                                                     , -1) == 0) {
  ret = -22;
  goto out;
 }
 ret = 0;

 out:
 if (ret == 0) {

  *ccp = cc;
 } else {
  if (cc != 
           ((void *)0)
               ) {

   EVP_CIPHER_CTX_free(cc->evp);

   freezero(cc, sizeof(*cc));
  }
 }
 return ret;
}
int
cipher_crypt(struct sshcipher_ctx *cc, u_int seqnr, u_char *dest,
   const u_char *src, u_int len, u_int aadlen, u_int authlen)
{
 if ((cc->cipher->flags & (1<<1)) != 0) {
  return chachapoly_crypt(cc->cp_ctx, seqnr, dest, src,
      len, aadlen, authlen, cc->encrypt);
 }
 if ((cc->cipher->flags & (1<<3)) != 0) {
  memcpy(dest, src, aadlen + len);
  return 0;
 }
 if (authlen) {
  u_char lastiv[1];

  if (authlen != cipher_authlen(cc->cipher))
   return -10;

  if (!EVP_CIPHER_CTX_ctrl(cc->evp, 
                                   0x13
                                                      ,
      1, lastiv))
   return -22;

  if (!cc->encrypt &&
      !EVP_CIPHER_CTX_ctrl(cc->evp, 
                                   0x11
                                                       ,
      authlen, (u_char *)src + aadlen + len))
   return -22;
 }
 if (aadlen) {
  if (authlen &&
      EVP_Cipher(cc->evp, 
                         ((void *)0)
                             , (u_char *)src, aadlen) < 0)
   return -22;
  memcpy(dest, src, aadlen);
 }
 if (len % cc->cipher->block_size)
  return -10;
 if (EVP_Cipher(cc->evp, dest + aadlen, (u_char *)src + aadlen,
     len) < 0)
  return -22;
 if (authlen) {

  if (EVP_Cipher(cc->evp, 
                         ((void *)0)
                             , 
                               ((void *)0)
                                   , 0) < 0)
   return cc->encrypt ?
       -22 : -30;
  if (cc->encrypt &&
      !EVP_CIPHER_CTX_ctrl(cc->evp, 
                                   0x10
                                                       ,
      authlen, dest + aadlen + len))
   return -22;
 }
 return 0;

}


int
cipher_get_length(struct sshcipher_ctx *cc, u_int *plenp, u_int seqnr,
    const u_char *cp, u_int len)
{
 if ((cc->cipher->flags & (1<<1)) != 0)
  return chachapoly_get_length(cc->cp_ctx, plenp, seqnr,
      cp, len);
 if (len < 4)
  return -3;
 *plenp = (((u_int32_t)(((const u_char *)(cp))[0]) << 24) | ((u_int32_t)(((const u_char *)(cp))[1]) << 16) | ((u_int32_t)(((const u_char *)(cp))[2]) << 8) | (u_int32_t)(((const u_char *)(cp))[3]));
 return 0;
}

void
cipher_free(struct sshcipher_ctx *cc)
{
 if (cc == 
          ((void *)0)
              )
  return;
 if ((cc->cipher->flags & (1<<1)) != 0) {
  chachapoly_free(cc->cp_ctx);
  cc->cp_ctx = 
              ((void *)0)
                  ;
 } else if ((cc->cipher->flags & (1<<2)) != 0)
  explicit_bzero(&cc->ac_ctx, sizeof(cc->ac_ctx));

 EVP_CIPHER_CTX_free(cc->evp);
 cc->evp = 
          ((void *)0)
              ;

 freezero(cc, sizeof(*cc));
}






int
cipher_get_keyiv_len(const struct sshcipher_ctx *cc)
{
 const struct sshcipher *c = cc->cipher;

 if ((c->flags & (1<<1)) != 0)
  return 0;
 else if ((c->flags & (1<<2)) != 0)
  return sizeof(cc->ac_ctx.ctr);

 return 
       EVP_CIPHER_CTX_get_iv_length
                               (cc->evp);



}

int
cipher_get_keyiv(struct sshcipher_ctx *cc, u_char *iv, size_t len)
{

 const struct sshcipher *c = cc->cipher;
 int evplen;


 if ((cc->cipher->flags & (1<<1)) != 0) {
  if (len != 0)
   return -10;
  return 0;
 }
 if ((cc->cipher->flags & (1<<2)) != 0) {
  if (len != sizeof(cc->ac_ctx.ctr))
   return -10;
  memcpy(iv, cc->ac_ctx.ctr, len);
  return 0;
 }
 if ((cc->cipher->flags & (1<<3)) != 0)
  return 0;


 evplen = 
         EVP_CIPHER_CTX_get_iv_length
                                 (cc->evp);
 if (evplen == 0)
  return 0;
 else if (evplen < 0)
  return -22;
 if ((size_t)evplen != len)
  return -10;
 if (cipher_authlen(c)) {
  if (!EVP_CIPHER_CTX_ctrl(cc->evp, 
                                   0x13
                                                      ,
      len, iv))
   return -22;
 } else if (!EVP_CIPHER_CTX_get_updated_iv(cc->evp, iv, len))
  return -22;

 return 0;
}

int
cipher_set_keyiv(struct sshcipher_ctx *cc, const u_char *iv, size_t len)
{

 const struct sshcipher *c = cc->cipher;
 int evplen = 0;


 if ((cc->cipher->flags & (1<<1)) != 0)
  return 0;
 if ((cc->cipher->flags & (1<<3)) != 0)
  return 0;


 evplen = 
         EVP_CIPHER_CTX_get_iv_length
                                 (cc->evp);
 if (evplen <= 0)
  return -22;
 if ((size_t)evplen != len)
  return -10;
 if (cipher_authlen(c)) {

  if (!EVP_CIPHER_CTX_ctrl(cc->evp,
      
     0x12
                              , -1, (void *)iv))
   return -22;
 } else if (!EVP_CIPHER_CTX_set_iv(cc->evp, iv, evplen))
  return -22;

 return 0;
}
