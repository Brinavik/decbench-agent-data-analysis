











































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















struct stat;
typedef struct {
 size_t gl_pathc;
 size_t gl_matchc;
 size_t gl_offs;
 int gl_flags;
 char **gl_pathv;
 struct stat **gl_statv;

 int (*gl_errfunc)(const char *, int);






 void (*gl_closedir)(void *);
 struct dirent *(*gl_readdir)(void *);
 void *(*gl_opendir)(const char *);
 int (*gl_lstat)(const char *, struct stat *);
 int (*gl_stat)(const char *, struct stat *);
} _ssh_compat_glob_t;
int _ssh__compat_glob(const char *, int, int (*)(const char *, int), _ssh_compat_glob_t *);
void _ssh__compat_globfree(_ssh_compat_glob_t *);
void *xmalloc(size_t);
void *xcalloc(size_t, size_t);
void *xreallocarray(void *, size_t, size_t);
void *xrecallocarray(void *, size_t, size_t, size_t);
char *xstrdup(const char *);
int xasprintf(char **, const char *, ...)
    __attribute__((__format__ (printf, 2, 3))) __attribute__((__nonnull__ (2)));
int xvasprintf(char **, const char *, va_list)
    __attribute__((__nonnull__ (2)));
const char *ssh_err(int n);
struct ssh;

void compat_banner(struct ssh *, const char *);
char *compat_cipher_proposal(struct ssh *, char *);
char *compat_pkalg_proposal(struct ssh *, char *);
char *compat_kex_proposal(struct ssh *, char *);


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
typedef enum {
 SYSLOG_FACILITY_DAEMON,
 SYSLOG_FACILITY_USER,
 SYSLOG_FACILITY_AUTH,



 SYSLOG_FACILITY_LOCAL0,
 SYSLOG_FACILITY_LOCAL1,
 SYSLOG_FACILITY_LOCAL2,
 SYSLOG_FACILITY_LOCAL3,
 SYSLOG_FACILITY_LOCAL4,
 SYSLOG_FACILITY_LOCAL5,
 SYSLOG_FACILITY_LOCAL6,
 SYSLOG_FACILITY_LOCAL7,
 SYSLOG_FACILITY_NOT_SET = -1
} SyslogFacility;

typedef enum {
 SYSLOG_LEVEL_QUIET,
 SYSLOG_LEVEL_FATAL,
 SYSLOG_LEVEL_ERROR,
 SYSLOG_LEVEL_INFO,
 SYSLOG_LEVEL_VERBOSE,
 SYSLOG_LEVEL_DEBUG1,
 SYSLOG_LEVEL_DEBUG2,
 SYSLOG_LEVEL_DEBUG3,
 SYSLOG_LEVEL_NOT_SET = -1
} LogLevel;

typedef void (log_handler_fn)(LogLevel, int, const char *, void *);

void log_init(const char *, LogLevel, SyslogFacility, int);
LogLevel log_level_get(void);
int log_change_level(LogLevel);
int log_is_on_stderr(void);
void log_redirect_stderr_to(const char *);
void log_verbose_add(const char *);
void log_verbose_reset(void);

SyslogFacility log_facility_number(char *);
const char * log_facility_name(SyslogFacility);
LogLevel log_level_number(char *);
const char * log_level_name(LogLevel);

void set_log_handler(log_handler_fn *, void *);
void cleanup_exit(int) __attribute__((noreturn));

void sshlog(const char *, const char *, int, int,
    LogLevel, const char *, const char *, ...)
    __attribute__((format(printf, 7, 8)));
void sshlogv(const char *, const char *, int, int,
    LogLevel, const char *, const char *, va_list);
void sshsigdie(const char *, const char *, int, int,
    LogLevel, const char *, const char *, ...) __attribute__((noreturn))
    __attribute__((format(printf, 7, 8)));
void sshlogdie(const char *, const char *, int, int,
    LogLevel, const char *, const char *, ...) __attribute__((noreturn))
    __attribute__((format(printf, 7, 8)));
void sshfatal(const char *, const char *, int, int,
    LogLevel, const char *, const char *, ...) __attribute__((noreturn))
    __attribute__((format(printf, 7, 8)));
void sshlogdirect(LogLevel, int, const char *, ...)
    __attribute__((format(printf, 3, 4)));


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
struct allowed_cname {
 char *source_list;
 char *target_list;
};

typedef struct {
 int forward_agent;
 char *forward_agent_sock_path;
 int forward_x11;
 int forward_x11_timeout;
 int forward_x11_trusted;
 int exit_on_forward_failure;
 char *xauth_location;
 struct ForwardOptions fwd_opts;
 int pubkey_authentication;
 int hostbased_authentication;
 int gss_authentication;
 int gss_deleg_creds;
 int password_authentication;

 int kbd_interactive_authentication;
 char *kbd_interactive_devices;
 int batch_mode;
 int check_host_ip;
 int strict_host_key_checking;
 int compression;
 int tcp_keep_alive;
 int ip_qos_interactive;
 int ip_qos_bulk;
 SyslogFacility log_facility;
 LogLevel log_level;
 u_int num_log_verbose;
 char **log_verbose;
 int port;
 int address_family;
 int connection_attempts;

 int connection_timeout;

 int number_of_password_prompts;

 char *ciphers;
 char *macs;
 char *hostkeyalgorithms;
 char *kex_algorithms;
 char *ca_sign_algorithms;
 char *hostname;
 char *host_key_alias;
 char *proxy_command;
 char *user;
 int escape_char;

 u_int num_system_hostfiles;
 char *system_hostfiles[32];
 u_int num_user_hostfiles;
 char *user_hostfiles[32];
 char *preferred_authentications;
 char *bind_address;
 char *bind_interface;
 char *pkcs11_provider;
 char *sk_provider;
 int verify_host_key_dns;

 int num_identity_files;
 char *identity_files[100];
 int identity_file_userprovided[100];
 struct sshkey *identity_keys[100];

 int num_certificate_files;
 char *certificate_files[100];
 int certificate_file_userprovided[100];
 struct sshkey *certificates[100];

 int add_keys_to_agent;
 int add_keys_to_agent_lifespan;
 char *identity_agent;


 int num_local_forwards;
 struct Forward *local_forwards;


 int num_remote_forwards;
 struct Forward *remote_forwards;
 int clear_forwardings;


 char **permitted_remote_opens;
 u_int num_permitted_remote_opens;


 char *stdio_forward_host;
 int stdio_forward_port;

 int enable_ssh_keysign;
 int64_t rekey_limit;
 int rekey_interval;
 int no_host_authentication_for_localhost;
 int identities_only;
 int server_alive_interval;
 int server_alive_count_max;

 u_int num_send_env;
 char **send_env;
 u_int num_setenv;
 char **setenv;

 char *control_path;
 int control_master;
 int control_persist;
 int control_persist_timeout;

 int hash_known_hosts;

 int tun_open;
 int tun_local;
 int tun_remote;

 char *local_command;
 int permit_local_command;
 char *remote_command;
 int visual_host_key;

 int request_tty;
 int session_type;
 int stdin_null;
 int fork_after_authentication;

 int proxy_use_fdpass;

 int num_canonical_domains;
 char *canonical_domains[32];
 int canonicalize_hostname;
 int canonicalize_max_dots;
 int canonicalize_fallback_local;
 int num_permitted_cnames;
 struct allowed_cname permitted_cnames[32];

 char *revoked_host_keys;

 int fingerprint_hash;

 int update_hostkeys;

 char *hostbased_accepted_algos;
 char *pubkey_accepted_algos;

 char *jump_user;
 char *jump_host;
 int jump_port;
 char *jump_extra;

 char *known_hosts_command;

 int required_rsa_size;

 char *ignored_unknown;
} Options;
const char *kex_default_pk_alg(void);
char *ssh_connection_hash(const char *thishost, const char *host,
    const char *portstr, const char *user);
void initialize_options(Options *);
int fill_default_options(Options *);
void fill_default_options_for_canonicalization(Options *);
void free_options(Options *o);
int process_config_line(Options *, struct passwd *, const char *,
    const char *, char *, const char *, int, int *, int);
int read_config_file(const char *, struct passwd *, const char *,
    const char *, Options *, int, int *);
int parse_forward(struct Forward *, const char *, int, int);
int parse_jump(const char *, Options *, int);
int parse_ssh_uri(const char *, char **, char **, int *);
int default_ssh_port(void);
int option_clear_or_none(const char *);
int config_has_permitted_cnames(Options *);
void dump_client_config(Options *o, const char *host);

void add_local_forward(Options *, const struct Forward *);
void add_remote_forward(Options *, const struct Forward *);
void add_identity_file(Options *, const char *, const char *, int);
void add_certificate_file(Options *, const char *, int);
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
struct sshmac {
 char *name;
 int enabled;
 u_int mac_len;
 u_char *key;
 u_int key_len;
 int type;
 int etm;
 struct ssh_hmac_ctx *hmac_ctx;
 struct umac_ctx *umac_ctx;
};

int mac_valid(const char *);
char *mac_alg_list(char);
int mac_setup(struct sshmac *, char *);
int mac_init(struct sshmac *);
int mac_compute(struct sshmac *, u_int32_t, const u_char *, int,
    u_char *, size_t);
int mac_check(struct sshmac *, u_int32_t, const u_char *, size_t,
    const u_char *, size_t);
void mac_clear(struct sshmac *);
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




enum kex_init_proposals {
 PROPOSAL_KEX_ALGS,
 PROPOSAL_SERVER_HOST_KEY_ALGS,
 PROPOSAL_ENC_ALGS_CTOS,
 PROPOSAL_ENC_ALGS_STOC,
 PROPOSAL_MAC_ALGS_CTOS,
 PROPOSAL_MAC_ALGS_STOC,
 PROPOSAL_COMP_ALGS_CTOS,
 PROPOSAL_COMP_ALGS_STOC,
 PROPOSAL_LANG_CTOS,
 PROPOSAL_LANG_STOC,
 PROPOSAL_MAX
};

enum kex_modes {
 MODE_IN,
 MODE_OUT,
 MODE_MAX
};

enum kex_exchange {
 KEX_DH_GRP1_SHA1,
 KEX_DH_GRP14_SHA1,
 KEX_DH_GRP14_SHA256,
 KEX_DH_GRP16_SHA512,
 KEX_DH_GRP18_SHA512,
 KEX_DH_GEX_SHA1,
 KEX_DH_GEX_SHA256,
 KEX_ECDH_SHA2,
 KEX_C25519_SHA256,
 KEX_KEM_SNTRUP761X25519_SHA512,
 KEX_MAX
};
struct sshenc {
 char *name;
 const struct sshcipher *cipher;
 int enabled;
 u_int key_len;
 u_int iv_len;
 u_int block_size;
 u_char *key;
 u_char *iv;
};
struct sshcomp {
 u_int type;
 int enabled;
 char *name;
};
struct newkeys {
 struct sshenc enc;
 struct sshmac mac;
 struct sshcomp comp;
};

struct ssh;
struct sshbuf;

struct kex {
 struct newkeys *newkeys[MODE_MAX];
 u_int we_need;
 u_int dh_need;
 int server;
 char *name;
 char *hostkey_alg;
 int hostkey_type;
 int hostkey_nid;
 u_int kex_type;
 char *server_sig_algs;
 int ext_info_c;
 struct sshbuf *my;
 struct sshbuf *peer;
 struct sshbuf *client_version;
 struct sshbuf *server_version;
 struct sshbuf *session_id;
 struct sshbuf *initial_sig;
 struct sshkey *initial_hostkey;
 sig_atomic_t done;
 u_int flags;
 int hash_alg;
 int ec_nid;
 char *failed_choice;
 int (*verify_host_key)(struct sshkey *, struct ssh *);
 struct sshkey *(*load_host_public_key)(int, int, struct ssh *);
 struct sshkey *(*load_host_private_key)(int, int, struct ssh *);
 int (*host_key_index)(struct sshkey *, int, struct ssh *);
 int (*sign)(struct ssh *, struct sshkey *, struct sshkey *,
     u_char **, size_t *, const u_char *, size_t, const char *);
 int (*kex[KEX_MAX])(struct ssh *);

 DH *dh;
 u_int min, max, nbits;
 EC_KEY *ec_client_key;
 const EC_GROUP *ec_group;
 u_char c25519_client_key[32];
 u_char c25519_client_pubkey[32];
 u_char sntrup761_client_key[1763];
 struct sshbuf *client_pub;
};

int kex_names_valid(const char *);
char *kex_alg_list(char);
char *kex_names_cat(const char *, const char *);
int kex_assemble_names(char **, const char *, const char *);

int kex_exchange_identification(struct ssh *, int, const char *);

struct kex *kex_new(void);
int kex_ready(struct ssh *, char *[PROPOSAL_MAX]);
int kex_setup(struct ssh *, char *[PROPOSAL_MAX]);
void kex_free_newkeys(struct newkeys *);
void kex_free(struct kex *);

int kex_buf2prop(struct sshbuf *, int *, char ***);
int kex_prop2buf(struct sshbuf *, char *proposal[PROPOSAL_MAX]);
void kex_prop_free(char **);
int kex_load_hostkey(struct ssh *, struct sshkey **, struct sshkey **);
int kex_verify_host_key(struct ssh *, struct sshkey *);

int kex_send_kexinit(struct ssh *);
int kex_input_kexinit(int, u_int32_t, struct ssh *);
int kex_input_ext_info(int, u_int32_t, struct ssh *);
int kex_protocol_error(int, u_int32_t, struct ssh *);
int kex_derive_keys(struct ssh *, u_char *, u_int, const struct sshbuf *);
int kex_send_newkeys(struct ssh *);
int kex_start_rekex(struct ssh *);

int kexgex_client(struct ssh *);
int kexgex_server(struct ssh *);
int kex_gen_client(struct ssh *);
int kex_gen_server(struct ssh *);

int kex_dh_keypair(struct kex *);
int kex_dh_enc(struct kex *, const struct sshbuf *, struct sshbuf **,
    struct sshbuf **);
int kex_dh_dec(struct kex *, const struct sshbuf *, struct sshbuf **);

int kex_ecdh_keypair(struct kex *);
int kex_ecdh_enc(struct kex *, const struct sshbuf *, struct sshbuf **,
    struct sshbuf **);
int kex_ecdh_dec(struct kex *, const struct sshbuf *, struct sshbuf **);

int kex_c25519_keypair(struct kex *);
int kex_c25519_enc(struct kex *, const struct sshbuf *, struct sshbuf **,
    struct sshbuf **);
int kex_c25519_dec(struct kex *, const struct sshbuf *, struct sshbuf **);

int kex_kem_sntrup761x25519_keypair(struct kex *);
int kex_kem_sntrup761x25519_enc(struct kex *, const struct sshbuf *,
    struct sshbuf **, struct sshbuf **);
int kex_kem_sntrup761x25519_dec(struct kex *, const struct sshbuf *,
    struct sshbuf **);

int kex_dh_keygen(struct kex *);
int kex_dh_compute_key(struct kex *, BIGNUM *, struct sshbuf *);

int kexgex_hash(int, const struct sshbuf *, const struct sshbuf *,
    const struct sshbuf *, const struct sshbuf *, const struct sshbuf *,
    int, int, int,
    const BIGNUM *, const BIGNUM *, const BIGNUM *,
    const BIGNUM *, const u_char *, size_t,
    u_char *, size_t *);

void kexc25519_keygen(u_char key[32], u_char pub[32])
 __attribute__(())
 __attribute__(());
int kexc25519_shared_key(const u_char key[32],
    const u_char pub[32], struct sshbuf *out)
 __attribute__(())
 __attribute__(());
int kexc25519_shared_key_ext(const u_char key[32],
    const u_char pub[32], struct sshbuf *out, int)
 __attribute__(())
 __attribute__(());

void temporarily_use_uid(struct passwd *);
void restore_uid(void);
void permanently_set_uid(struct passwd *);
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
static int read_config_file_depth(const char *filename, struct passwd *pw,
    const char *host, const char *original_host, Options *options,
    int flags, int *activep, int *want_final_pass, int depth);
static int process_config_line_depth(Options *options, struct passwd *pw,
    const char *host, const char *original_host, char *line,
    const char *filename, int linenum, int *activep, int flags,
    int *want_final_pass, int depth);



typedef enum {
 oBadOption,
 oHost, oMatch, oInclude,
 oForwardAgent, oForwardX11, oForwardX11Trusted, oForwardX11Timeout,
 oGatewayPorts, oExitOnForwardFailure,
 oPasswordAuthentication,
 oXAuthLocation,
 oIdentityFile, oHostname, oPort, oRemoteForward, oLocalForward,
 oPermitRemoteOpen,
 oCertificateFile, oAddKeysToAgent, oIdentityAgent,
 oUser, oEscapeChar, oProxyCommand,
 oGlobalKnownHostsFile, oUserKnownHostsFile, oConnectionAttempts,
 oBatchMode, oCheckHostIP, oStrictHostKeyChecking, oCompression,
 oTCPKeepAlive, oNumberOfPasswordPrompts,
 oLogFacility, oLogLevel, oLogVerbose, oCiphers, oMacs,
 oPubkeyAuthentication,
 oKbdInteractiveAuthentication, oKbdInteractiveDevices, oHostKeyAlias,
 oDynamicForward, oPreferredAuthentications, oHostbasedAuthentication,
 oHostKeyAlgorithms, oBindAddress, oBindInterface, oPKCS11Provider,
 oClearAllForwardings, oNoHostAuthenticationForLocalhost,
 oEnableSSHKeysign, oRekeyLimit, oVerifyHostKeyDNS, oConnectTimeout,
 oAddressFamily, oGssAuthentication, oGssDelegateCreds,
 oServerAliveInterval, oServerAliveCountMax, oIdentitiesOnly,
 oSendEnv, oSetEnv, oControlPath, oControlMaster, oControlPersist,
 oHashKnownHosts,
 oTunnel, oTunnelDevice,
 oLocalCommand, oPermitLocalCommand, oRemoteCommand,
 oVisualHostKey,
 oKexAlgorithms, oIPQoS, oRequestTTY, oSessionType, oStdinNull,
 oForkAfterAuthentication, oIgnoreUnknown, oProxyUseFdpass,
 oCanonicalDomains, oCanonicalizeHostname, oCanonicalizeMaxDots,
 oCanonicalizeFallbackLocal, oCanonicalizePermittedCNAMEs,
 oStreamLocalBindMask, oStreamLocalBindUnlink, oRevokedHostKeys,
 oFingerprintHash, oUpdateHostkeys, oHostbasedAcceptedAlgorithms,
 oPubkeyAcceptedAlgorithms, oCASignatureAlgorithms, oProxyJump,
 oSecurityKeyProvider, oKnownHostsCommand, oRequiredRSASize,
 oIgnore, oIgnoredUnknownOption, oDeprecated, oUnsupported
} OpCodes;



static struct {
 const char *name;
 OpCodes opcode;
} keywords[] = {

 { "protocol", oIgnore },
 { "cipher", oDeprecated },
 { "fallbacktorsh", oDeprecated },
 { "globalknownhostsfile2", oDeprecated },
 { "rhostsauthentication", oDeprecated },
 { "userknownhostsfile2", oDeprecated },
 { "useroaming", oDeprecated },
 { "usersh", oDeprecated },
 { "useprivilegedport", oDeprecated },


 { "afstokenpassing", oUnsupported },
 { "kerberosauthentication", oUnsupported },
 { "kerberostgtpassing", oUnsupported },
 { "rsaauthentication", oUnsupported },
 { "rhostsrsaauthentication", oUnsupported },
 { "compressionlevel", oUnsupported },






 { "gssapiauthentication", oUnsupported },
 { "gssapidelegatecredentials", oUnsupported },


 { "pkcs11provider", oPKCS11Provider },
 { "smartcarddevice", oPKCS11Provider },





 { "forwardagent", oForwardAgent },
 { "forwardx11", oForwardX11 },
 { "forwardx11trusted", oForwardX11Trusted },
 { "forwardx11timeout", oForwardX11Timeout },
 { "exitonforwardfailure", oExitOnForwardFailure },
 { "xauthlocation", oXAuthLocation },
 { "gatewayports", oGatewayPorts },
 { "passwordauthentication", oPasswordAuthentication },
 { "kbdinteractiveauthentication", oKbdInteractiveAuthentication },
 { "kbdinteractivedevices", oKbdInteractiveDevices },
 { "challengeresponseauthentication", oKbdInteractiveAuthentication },
 { "skeyauthentication", oKbdInteractiveAuthentication },
 { "tisauthentication", oKbdInteractiveAuthentication },
 { "pubkeyauthentication", oPubkeyAuthentication },
 { "dsaauthentication", oPubkeyAuthentication },
 { "hostbasedauthentication", oHostbasedAuthentication },
 { "identityfile", oIdentityFile },
 { "identityfile2", oIdentityFile },
 { "identitiesonly", oIdentitiesOnly },
 { "certificatefile", oCertificateFile },
 { "addkeystoagent", oAddKeysToAgent },
 { "identityagent", oIdentityAgent },
 { "hostname", oHostname },
 { "hostkeyalias", oHostKeyAlias },
 { "proxycommand", oProxyCommand },
 { "port", oPort },
 { "ciphers", oCiphers },
 { "macs", oMacs },
 { "remoteforward", oRemoteForward },
 { "localforward", oLocalForward },
 { "permitremoteopen", oPermitRemoteOpen },
 { "user", oUser },
 { "host", oHost },
 { "match", oMatch },
 { "escapechar", oEscapeChar },
 { "globalknownhostsfile", oGlobalKnownHostsFile },
 { "userknownhostsfile", oUserKnownHostsFile },
 { "connectionattempts", oConnectionAttempts },
 { "batchmode", oBatchMode },
 { "checkhostip", oCheckHostIP },
 { "stricthostkeychecking", oStrictHostKeyChecking },
 { "compression", oCompression },
 { "tcpkeepalive", oTCPKeepAlive },
 { "keepalive", oTCPKeepAlive },
 { "numberofpasswordprompts", oNumberOfPasswordPrompts },
 { "syslogfacility", oLogFacility },
 { "loglevel", oLogLevel },
 { "logverbose", oLogVerbose },
 { "dynamicforward", oDynamicForward },
 { "preferredauthentications", oPreferredAuthentications },
 { "hostkeyalgorithms", oHostKeyAlgorithms },
 { "casignaturealgorithms", oCASignatureAlgorithms },
 { "bindaddress", oBindAddress },
 { "bindinterface", oBindInterface },
 { "clearallforwardings", oClearAllForwardings },
 { "enablesshkeysign", oEnableSSHKeysign },
 { "verifyhostkeydns", oVerifyHostKeyDNS },
 { "nohostauthenticationforlocalhost", oNoHostAuthenticationForLocalhost },
 { "rekeylimit", oRekeyLimit },
 { "connecttimeout", oConnectTimeout },
 { "addressfamily", oAddressFamily },
 { "serveraliveinterval", oServerAliveInterval },
 { "serveralivecountmax", oServerAliveCountMax },
 { "sendenv", oSendEnv },
 { "setenv", oSetEnv },
 { "controlpath", oControlPath },
 { "controlmaster", oControlMaster },
 { "controlpersist", oControlPersist },
 { "hashknownhosts", oHashKnownHosts },
 { "include", oInclude },
 { "tunnel", oTunnel },
 { "tunneldevice", oTunnelDevice },
 { "localcommand", oLocalCommand },
 { "permitlocalcommand", oPermitLocalCommand },
 { "remotecommand", oRemoteCommand },
 { "visualhostkey", oVisualHostKey },
 { "kexalgorithms", oKexAlgorithms },
 { "ipqos", oIPQoS },
 { "requesttty", oRequestTTY },
 { "sessiontype", oSessionType },
 { "stdinnull", oStdinNull },
 { "forkafterauthentication", oForkAfterAuthentication },
 { "proxyusefdpass", oProxyUseFdpass },
 { "canonicaldomains", oCanonicalDomains },
 { "canonicalizefallbacklocal", oCanonicalizeFallbackLocal },
 { "canonicalizehostname", oCanonicalizeHostname },
 { "canonicalizemaxdots", oCanonicalizeMaxDots },
 { "canonicalizepermittedcnames", oCanonicalizePermittedCNAMEs },
 { "streamlocalbindmask", oStreamLocalBindMask },
 { "streamlocalbindunlink", oStreamLocalBindUnlink },
 { "revokedhostkeys", oRevokedHostKeys },
 { "fingerprinthash", oFingerprintHash },
 { "updatehostkeys", oUpdateHostkeys },
 { "hostbasedacceptedalgorithms", oHostbasedAcceptedAlgorithms },
 { "hostbasedkeytypes", oHostbasedAcceptedAlgorithms },
 { "pubkeyacceptedalgorithms", oPubkeyAcceptedAlgorithms },
 { "pubkeyacceptedkeytypes", oPubkeyAcceptedAlgorithms },
 { "ignoreunknown", oIgnoreUnknown },
 { "proxyjump", oProxyJump },
 { "securitykeyprovider", oSecurityKeyProvider },
 { "knownhostscommand", oKnownHostsCommand },
 { "requiredrsasize", oRequiredRSASize },

 { 
  ((void *)0)
      , oBadOption }
};

static const char *lookup_opcode_name(OpCodes code);

const char *
kex_default_pk_alg(void)
{
 static char *pkalgs;

 if (pkalgs == 
              ((void *)0)
                  ) {
  char *all_key;

  all_key = sshkey_alg_list(0, 0, 1, ',');
  pkalgs = match_filter_allowlist("ssh-ed25519-cert-v01@openssh.com," "ecdsa-sha2-nistp256-cert-v01@openssh.com," "ecdsa-sha2-nistp384-cert-v01@openssh.com," "ecdsa-sha2-nistp521-cert-v01@openssh.com," "sk-ssh-ed25519-cert-v01@openssh.com," "sk-ecdsa-sha2-nistp256-cert-v01@openssh.com," "rsa-sha2-512-cert-v01@openssh.com," "rsa-sha2-256-cert-v01@openssh.com," "ssh-ed25519," "ecdsa-sha2-nistp256," "ecdsa-sha2-nistp384," "ecdsa-sha2-nistp521," "sk-ssh-ed25519@openssh.com," "sk-ecdsa-sha2-nistp256@openssh.com," "rsa-sha2-512," "rsa-sha2-256", all_key);
  free(all_key);
 }
 return pkalgs;
}

char *
ssh_connection_hash(const char *thishost, const char *host, const char *portstr,
    const char *user)
{
 struct ssh_digest_ctx *md;
 u_char conn_hash[64];

 if ((md = ssh_digest_start(1)) == 
                                                ((void *)0) 
                                                     ||
     ssh_digest_update(md, thishost, strlen(thishost)) < 0 ||
     ssh_digest_update(md, host, strlen(host)) < 0 ||
     ssh_digest_update(md, portstr, strlen(portstr)) < 0 ||
     ssh_digest_update(md, user, strlen(user)) < 0 ||
     ssh_digest_final(md, conn_hash, sizeof(conn_hash)) < 0)
  sshfatal("readconf.c", __func__, 358, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "mux digest failed");
 ssh_digest_free(md);
 return tohex(conn_hash, ssh_digest_bytes(1));
}






void
add_local_forward(Options *options, const struct Forward *newfwd)
{
 struct Forward *fwd;
 int i;


 for (i = 0; i < options->num_local_forwards; i++) {
  if (forward_equals(newfwd, options->local_forwards + i))
   return;
 }
 options->local_forwards = xreallocarray(options->local_forwards,
     options->num_local_forwards + 1,
     sizeof(*options->local_forwards));
 fwd = &options->local_forwards[options->num_local_forwards++];

 fwd->listen_host = newfwd->listen_host;
 fwd->listen_port = newfwd->listen_port;
 fwd->listen_path = newfwd->listen_path;
 fwd->connect_host = newfwd->connect_host;
 fwd->connect_port = newfwd->connect_port;
 fwd->connect_path = newfwd->connect_path;
}






void
add_remote_forward(Options *options, const struct Forward *newfwd)
{
 struct Forward *fwd;
 int i;


 for (i = 0; i < options->num_remote_forwards; i++) {
  if (forward_equals(newfwd, options->remote_forwards + i))
   return;
 }
 options->remote_forwards = xreallocarray(options->remote_forwards,
     options->num_remote_forwards + 1,
     sizeof(*options->remote_forwards));
 fwd = &options->remote_forwards[options->num_remote_forwards++];

 fwd->listen_host = newfwd->listen_host;
 fwd->listen_port = newfwd->listen_port;
 fwd->listen_path = newfwd->listen_path;
 fwd->connect_host = newfwd->connect_host;
 fwd->connect_port = newfwd->connect_port;
 fwd->connect_path = newfwd->connect_path;
 fwd->handle = newfwd->handle;
 fwd->allocated_port = 0;
}

static void
clear_forwardings(Options *options)
{
 int i;

 for (i = 0; i < options->num_local_forwards; i++) {
  free(options->local_forwards[i].listen_host);
  free(options->local_forwards[i].listen_path);
  free(options->local_forwards[i].connect_host);
  free(options->local_forwards[i].connect_path);
 }
 if (options->num_local_forwards > 0) {
  free(options->local_forwards);
  options->local_forwards = 
                           ((void *)0)
                               ;
 }
 options->num_local_forwards = 0;
 for (i = 0; i < options->num_remote_forwards; i++) {
  free(options->remote_forwards[i].listen_host);
  free(options->remote_forwards[i].listen_path);
  free(options->remote_forwards[i].connect_host);
  free(options->remote_forwards[i].connect_path);
 }
 if (options->num_remote_forwards > 0) {
  free(options->remote_forwards);
  options->remote_forwards = 
                            ((void *)0)
                                ;
 }
 options->num_remote_forwards = 0;
 options->tun_open = 0x00;
}

void
add_certificate_file(Options *options, const char *path, int userprovided)
{
 int i;

 if (options->num_certificate_files >= 100)
  sshfatal("readconf.c", __func__, 459, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Too many certificate files specified (max %d)", 100)
                                ;


 for (i = 0; i < options->num_certificate_files; i++) {
  if (options->certificate_file_userprovided[i] == userprovided &&
      strcmp(options->certificate_files[i], path) == 0) {
   sshlog("readconf.c", __func__, 466, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "ignoring duplicate key %s", path);
   return;
  }
 }

 options->certificate_file_userprovided[options->num_certificate_files] =
     userprovided;
 options->certificate_files[options->num_certificate_files++] =
     xstrdup(path);
}

void
add_identity_file(Options *options, const char *dir, const char *filename,
    int userprovided)
{
 char *path;
 int i;

 if (options->num_identity_files >= 100)
  sshfatal("readconf.c", __func__, 485, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Too many identity files specified (max %d)", 100)
                             ;

 if (dir == 
           ((void *)0)
               )
  path = xstrdup(filename);
 else if (xasprintf(&path, "%s%s", dir, filename) >= 
                                                    4096
                                                            )
  sshfatal("readconf.c", __func__, 491, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Identity file path %s too long", path);


 for (i = 0; i < options->num_identity_files; i++) {
  if (options->identity_file_userprovided[i] == userprovided &&
      strcmp(options->identity_files[i], path) == 0) {
   sshlog("readconf.c", __func__, 497, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "ignoring duplicate key %s", path);
   free(path);
   return;
  }
 }

 options->identity_file_userprovided[options->num_identity_files] =
     userprovided;
 options->identity_files[options->num_identity_files++] = path;
}

int
default_ssh_port(void)
{
 static int port;
 struct servent *sp;

 if (port == 0) {
  sp = getservbyname("ssh", "tcp");
  port = sp ? ntohs(sp->s_port) : 22;
 }
 return port;
}





static int
execute_in_shell(const char *cmd)
{
 char *shell;
 pid_t pid;
 int status;

 if ((shell = getenv("SHELL")) == 
                                 ((void *)0)
                                     )
  shell = 
         "/bin/sh"
                     ;

 if (access(shell, 
                  1
                      ) == -1) {
  sshfatal("readconf.c", __func__, 536, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Shell \"%s\" is not executable: %s", shell, strerror(
 (*__errno_location ())
 ))
                             ;
 }

 sshlog("readconf.c", __func__, 540, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Executing command: '%.500s'", cmd);


 if ((pid = fork()) == 0) {
  char *argv[4];

  if (stdfd_devnull(1, 1, 0) == -1)
   sshfatal("readconf.c", __func__, 547, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "stdfd_devnull failed");
  closefrom(
           2 
                         + 1);

  argv[0] = shell;
  argv[1] = "-c";
  argv[2] = xstrdup(cmd);
  argv[3] = 
           ((void *)0)
               ;

  execv(argv[0], argv);
  sshlog("readconf.c", __func__, 556, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Unable to execute '%.100s': %s", cmd, strerror(
 (*__errno_location ())
 ));

  ssh_signal(
            15
                   , 
                     ((__sighandler_t) 0)
                            );
  kill(getpid(), 
                15
                       );
  _exit(1);
 }

 if (pid == -1)
  sshfatal("readconf.c", __func__, 564, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "fork: %.100s", strerror(
 (*__errno_location ())
 ));

 while (waitpid(pid, &status, 0) == -1) {
  if (
     (*__errno_location ()) 
           != 
              4 
                    && 
                       (*__errno_location ()) 
                             != 
                                11
                                      )
   sshfatal("readconf.c", __func__, 568, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "waitpid: %s", strerror(
  (*__errno_location ())
  ));
 }
 if (!
     (((
     status
     ) & 0x7f) == 0)
                      ) {
  sshlog("readconf.c", __func__, 571, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "command '%.100s' exited abnormally", cmd);
  return -1;
 }
 sshlog("readconf.c", __func__, 574, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "command returned status %d", 
(((
status
) & 0xff00) >> 8)
);
 return 
       (((
       status
       ) & 0xff00) >> 8)
                          ;
}




static int
match_cfg_line(Options *options, char **condition, struct passwd *pw,
    const char *host_arg, const char *original_host, int final_pass,
    int *want_final_pass, const char *filename, int linenum)
{
 char *arg, *oattrib, *attrib, *cmd, *cp = *condition, *host, *criteria;
 const char *ruser;
 int r, port, this_result, result = 1, attributes = 0, negate;
 char thishost[
              1025
                        ], shorthost[
                                     1025
                                               ], portstr[
                                                          32
                                                                    ];
 char uidstr[32];





 port = options->port <= 0 ? default_ssh_port() : options->port;
 ruser = options->user == 
                         ((void *)0) 
                              ? pw->pw_name : options->user;
 if (final_pass) {
  host = xstrdup(options->hostname);
 } else if (options->hostname != 
                                ((void *)0)
                                    ) {

  host = percent_expand(options->hostname,
      "h", host_arg, (char *)
                            ((void *)0)
                                );
 } else {
  host = xstrdup(host_arg);
 }

 sshlog("readconf.c", __func__, 608, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "checking match for '%s' host %s originally %s", cp, host, original_host)
                             ;
 while ((oattrib = attrib = strdelim(&cp)) && *attrib != '\0') {

  if (*attrib == '#') {
   cp = 
       ((void *)0)
           ;
   break;
  }
  arg = criteria = 
                  ((void *)0)
                      ;
  this_result = 1;
  if ((negate = attrib[0] == '!'))
   attrib++;

  if (strcasecmp(attrib, "all") == 0) {
   if (attributes > 1 || ((arg = strdelim(&cp)) != 
                                                  ((void *)0) 
                                                       &&
       *arg != '\0' && *arg != '#')) {
    sshlog("readconf.c", __func__, 624, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%.200s line %d: '%s' cannot be combined " "with other Match attributes", filename, linenum, oattrib)

                                   ;
    result = -1;
    goto out;
   }
   if (arg != 
             ((void *)0) 
                  && *arg == '#')
    cp = 
        ((void *)0)
            ;
   if (result)
    result = negate ? 0 : 1;
   goto out;
  }
  attributes++;

  if (strcasecmp(attrib, "canonical") == 0 ||
      strcasecmp(attrib, "final") == 0) {




   if (strcasecmp(attrib, "final") == 0 &&
       want_final_pass != 
                         ((void *)0)
                             )
    *want_final_pass = 1;
   r = !!final_pass;
   if (r == (negate ? 1 : 0))
    this_result = result = 0;
   sshlog("readconf.c", __func__, 650, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "%.200s line %d: %smatched '%s'", filename, linenum, this_result ? "" : "not ", oattrib)

                                          ;
   continue;
  }

  if ((arg = strdelim(&cp)) == 
                              ((void *)0) 
                                   ||
      *arg == '\0' || *arg == '#') {
   sshlog("readconf.c", __func__, 658, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Missing Match criteria for %s", attrib);
   result = -1;
   goto out;
  }
  if (strcasecmp(attrib, "host") == 0) {
   criteria = xstrdup(host);
   r = match_hostname(host, arg) == 1;
   if (r == (negate ? 1 : 0))
    this_result = result = 0;
  } else if (strcasecmp(attrib, "originalhost") == 0) {
   criteria = xstrdup(original_host);
   r = match_hostname(original_host, arg) == 1;
   if (r == (negate ? 1 : 0))
    this_result = result = 0;
  } else if (strcasecmp(attrib, "user") == 0) {
   criteria = xstrdup(ruser);
   r = match_pattern_list(ruser, arg, 0) == 1;
   if (r == (negate ? 1 : 0))
    this_result = result = 0;
  } else if (strcasecmp(attrib, "localuser") == 0) {
   criteria = xstrdup(pw->pw_name);
   r = match_pattern_list(pw->pw_name, arg, 0) == 1;
   if (r == (negate ? 1 : 0))
    this_result = result = 0;
  } else if (strcasecmp(attrib, "exec") == 0) {
   char *conn_hash_hex, *keyalias;

   if (gethostname(thishost, sizeof(thishost)) == -1)
    sshfatal("readconf.c", __func__, 686, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "gethostname: %s", strerror(
   (*__errno_location ())
   ));
   strlcpy(shorthost, thishost, sizeof(shorthost));
   shorthost[strcspn(thishost, ".")] = '\0';
   snprintf(portstr, sizeof(portstr), "%d", port);
   snprintf(uidstr, sizeof(uidstr), "%llu",
       (unsigned long long)pw->pw_uid);
   conn_hash_hex = ssh_connection_hash(thishost, host,
       portstr, ruser);
   keyalias = options->host_key_alias ?
       options->host_key_alias : host;

   cmd = percent_expand(arg,
       "C", conn_hash_hex,
       "L", shorthost,
       "d", pw->pw_dir,
       "h", host,
       "k", keyalias,
       "l", thishost,
       "n", original_host,
       "p", portstr,
       "r", ruser,
       "u", pw->pw_name,
       "i", uidstr,
       (char *)
              ((void *)0)
                  );
   free(conn_hash_hex);
   if (result != 1) {

    sshlog("readconf.c", __func__, 713, 0, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "%.200s line %d: skipped exec " "\"%.100s\"", filename, linenum, cmd)
                                             ;
    free(cmd);
    continue;
   }
   r = execute_in_shell(cmd);
   if (r == -1) {
    sshfatal("readconf.c", __func__, 720, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%.200s line %d: match exec " "'%.100s' error", filename, linenum, cmd)

                     ;
   }
   criteria = xstrdup(cmd);
   free(cmd);

   r = r == 0;
   if (r == (negate ? 1 : 0))
    this_result = result = 0;
  } else {
   sshlog("readconf.c", __func__, 731, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Unsupported Match attribute %s", attrib);
   result = -1;
   goto out;
  }
  sshlog("readconf.c", __func__, 735, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "%.200s line %d: %smatched '%s \"%.100s\"' ", filename, linenum, this_result ? "": "not ", oattrib, criteria)

                        ;
  free(criteria);
 }
 if (attributes == 0) {
  sshlog("readconf.c", __func__, 741, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "One or more attributes required for Match");
  result = -1;
  goto out;
 }
 out:
 if (result != -1)
  sshlog("readconf.c", __func__, 747, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "match %sfound", result ? "" : "not ");
 *condition = cp;
 free(host);
 return result;
}


static void
rm_env(Options *options, const char *arg, const char *filename, int linenum)
{
 u_int i, j, onum_send_env = options->num_send_env;


 for (i = 0; i < options->num_send_env; ) {
  if (!match_pattern(options->send_env[i], arg + 1)) {
   i++;
   continue;
  }
  sshlog("readconf.c", __func__, 765, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "%s line %d: removing environment %s", filename, linenum, options->send_env[i])
                                              ;
  free(options->send_env[i]);
  options->send_env[i] = 
                        ((void *)0)
                            ;
  for (j = i; j < options->num_send_env - 1; j++) {
   options->send_env[j] = options->send_env[j + 1];
   options->send_env[j + 1] = 
                             ((void *)0)
                                 ;
  }
  options->num_send_env--;

 }
 if (onum_send_env != options->num_send_env) {
  options->send_env = xrecallocarray(options->send_env,
      onum_send_env, options->num_send_env,
      sizeof(*options->send_env));
 }
}




static OpCodes
parse_token(const char *cp, const char *filename, int linenum,
    const char *ignored_unknown)
{
 int i;

 for (i = 0; keywords[i].name; i++)
  if (strcmp(cp, keywords[i].name) == 0)
   return keywords[i].opcode;
 if (ignored_unknown != 
                       ((void *)0) 
                            &&
     match_pattern_list(cp, ignored_unknown, 1) == 1)
  return oIgnoredUnknownOption;
 sshlog("readconf.c", __func__, 798, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "%s: line %d: Bad configuration option: %s", filename, linenum, cp)
                           ;
 return oBadOption;
}


struct multistate {
 char *key;
 int value;
};
static const struct multistate multistate_flag[] = {
 { "true", 1 },
 { "false", 0 },
 { "yes", 1 },
 { "no", 0 },
 { 
  ((void *)0)
      , -1 }
};
static const struct multistate multistate_yesnoask[] = {
 { "true", 1 },
 { "false", 0 },
 { "yes", 1 },
 { "no", 0 },
 { "ask", 2 },
 { 
  ((void *)0)
      , -1 }
};
static const struct multistate multistate_strict_hostkey[] = {
 { "true", 2 },
 { "false", 0 },
 { "yes", 2 },
 { "no", 0 },
 { "ask", 3 },
 { "off", 0 },
 { "accept-new", 1 },
 { 
  ((void *)0)
      , -1 }
};
static const struct multistate multistate_yesnoaskconfirm[] = {
 { "true", 1 },
 { "false", 0 },
 { "yes", 1 },
 { "no", 0 },
 { "ask", 2 },
 { "confirm", 3 },
 { 
  ((void *)0)
      , -1 }
};
static const struct multistate multistate_addressfamily[] = {
 { "inet", 
            2 
                    },
 { "inet6", 
             10 
                      },
 { "any", 
           0 
                     },
 { 
  ((void *)0)
      , -1 }
};
static const struct multistate multistate_controlmaster[] = {
 { "true", 1 },
 { "yes", 1 },
 { "false", 0 },
 { "no", 0 },
 { "auto", 2 },
 { "ask", 3 },
 { "autoask", 4 },
 { 
  ((void *)0)
      , -1 }
};
static const struct multistate multistate_tunnel[] = {
 { "ethernet", 0x02 },
 { "point-to-point", 0x01 },
 { "true", 0x01 },
 { "yes", 0x01 },
 { "false", 0x00 },
 { "no", 0x00 },
 { 
  ((void *)0)
      , -1 }
};
static const struct multistate multistate_requesttty[] = {
 { "true", 2 },
 { "yes", 2 },
 { "false", 1 },
 { "no", 1 },
 { "force", 3 },
 { "auto", 0 },
 { 
  ((void *)0)
      , -1 }
};
static const struct multistate multistate_sessiontype[] = {
 { "none", 0 },
 { "subsystem", 1 },
 { "default", 2 },
 { 
  ((void *)0)
      , -1 }
};
static const struct multistate multistate_canonicalizehostname[] = {
 { "true", 1 },
 { "false", 0 },
 { "yes", 1 },
 { "no", 0 },
 { "always", 2 },
 { 
  ((void *)0)
      , -1 }
};
static const struct multistate multistate_pubkey_auth[] = {
 { "true", 0x03 },
 { "false", 0x00 },
 { "yes", 0x03 },
 { "no", 0x00 },
 { "unbound", 0x01 },
 { "host-bound", 0x02 },
 { 
  ((void *)0)
      , -1 }
};
static const struct multistate multistate_compression[] = {

 { "yes", 1 },

 { "no", 0 },
 { 
  ((void *)0)
      , -1 }
};

static int
parse_multistate_value(const char *arg, const char *filename, int linenum,
    const struct multistate *multistate_ptr)
{
 int i;

 if (!arg || *arg == '\0') {
  sshlog("readconf.c", __func__, 914, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s line %d: missing argument.", filename, linenum);
  return -1;
 }
 for (i = 0; multistate_ptr[i].key != 
                                     ((void *)0)
                                         ; i++) {
  if (strcasecmp(arg, multistate_ptr[i].key) == 0)
   return multistate_ptr[i].value;
 }
 return -1;
}





int
process_config_line(Options *options, struct passwd *pw, const char *host,
    const char *original_host, char *line, const char *filename,
    int linenum, int *activep, int flags)
{
 return process_config_line_depth(options, pw, host, original_host,
     line, filename, linenum, activep, flags, 
                                             ((void *)0)
                                                 , 0);
}


static int
process_config_line_depth(Options *options, struct passwd *pw, const char *host,
    const char *original_host, char *line, const char *filename,
    int linenum, int *activep, int flags, int *want_final_pass, int depth)
{
 char *str, **charptr, *endofnumber, *keyword, *arg, *arg2, *p;
 char **cpptr, ***cppptr, fwdarg[256];
 u_int i, *uintptr, uvalue, max_entries = 0;
 int r, oactive, negated, opcode, *intptr, value, value2, cmdline = 0;
 int remotefwd, dynamicfwd;
 LogLevel *log_level_ptr;
 SyslogFacility *log_facility_ptr;
 long long val64;
 size_t len;
 struct Forward fwd;
 const struct multistate *multistate_ptr;
 struct allowed_cname *cname;
 _ssh_compat_glob_t gl;
 const char *errstr;
 char **oav = 
             ((void *)0)
                 , **av;
 int oac = 0, ac;
 int ret = -1;

 if (activep == 
               ((void *)0)
                   ) {
  cmdline = 1;
  activep = &cmdline;
 }


 if ((len = strlen(line)) == 0)
  return 0;
 for (len--; len > 0; len--) {
  if (strchr(" \t\r\n" "\f", line[len]) == 
                                           ((void *)0)
                                               )
   break;
  line[len] = '\0';
 }

 str = line;

 if ((keyword = strdelim(&str)) == 
                                  ((void *)0)
                                      )
  return 0;

 if (*keyword == '\0')
  keyword = strdelim(&str);
 if (keyword == 
               ((void *)0) 
                    || !*keyword || *keyword == '\n' || *keyword == '#')
  return 0;

 lowercase(keyword);


 if (str != 
           ((void *)0)
               )
  str += strspn(str, " \t\r\n");
 if (str == 
           ((void *)0) 
                || *str == '\0') {
  sshlog("readconf.c", __func__, 991, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s line %d: no argument after keyword \"%s\"", filename, linenum, keyword)
                                 ;
  return -1;
 }
 opcode = parse_token(keyword, filename, linenum,
     options->ignored_unknown);
 if (argv_split(str, &oac, &oav, 1) != 0) {
  sshlog("readconf.c", __func__, 998, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s line %d: invalid quotes", filename, linenum);
  return -1;
 }
 ac = oac;
 av = oav;

 switch (opcode) {
 case oBadOption:

  goto out;
 case oIgnore:
  argv_consume(&ac);
  break;
 case oIgnoredUnknownOption:
  sshlog("readconf.c", __func__, 1012, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%s line %d: Ignored unknown option \"%s\"", filename, linenum, keyword)
                                 ;
  argv_consume(&ac);
  break;
 case oConnectTimeout:
  intptr = &options->connection_timeout;
parse_time:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshlog("readconf.c", __func__, 1021, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s line %d: missing time value.", filename, linenum)
                         ;
   goto out;
  }
  if (strcmp(arg, "none") == 0)
   value = -1;
  else if ((value = convtime(arg)) == -1) {
   sshlog("readconf.c", __func__, 1028, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s line %d: invalid time value.", filename, linenum)
                         ;
   goto out;
  }
  if (*activep && *intptr == -1)
   *intptr = value;
  break;

 case oForwardAgent:
  intptr = &options->forward_agent;

  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshlog("readconf.c", __func__, 1041, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s line %d: missing argument.", filename, linenum)
                         ;
   goto out;
  }

  value = -1;
  multistate_ptr = multistate_flag;
  for (i = 0; multistate_ptr[i].key != 
                                      ((void *)0)
                                          ; i++) {
   if (strcasecmp(arg, multistate_ptr[i].key) == 0) {
    value = multistate_ptr[i].value;
    break;
   }
  }
  if (value != -1) {
   if (*activep && *intptr == -1)
    *intptr = value;
   break;
  }

  if (*activep && *intptr == -1)
   *intptr = 1;

  charptr = &options->forward_agent_sock_path;
  goto parse_agent_path;

 case oForwardX11:
  intptr = &options->forward_x11;
 parse_flag:
  multistate_ptr = multistate_flag;
 parse_multistate:
  arg = argv_next(&ac, &av);
  if ((value = parse_multistate_value(arg, filename, linenum,
      multistate_ptr)) == -1) {
   sshlog("readconf.c", __func__, 1074, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s line %d: unsupported option \"%s\".", filename, linenum, arg)
                              ;
   goto out;
  }
  if (*activep && *intptr == -1)
   *intptr = value;
  break;

 case oForwardX11Trusted:
  intptr = &options->forward_x11_trusted;
  goto parse_flag;

 case oForwardX11Timeout:
  intptr = &options->forward_x11_timeout;
  goto parse_time;

 case oGatewayPorts:
  intptr = &options->fwd_opts.gateway_ports;
  goto parse_flag;

 case oExitOnForwardFailure:
  intptr = &options->exit_on_forward_failure;
  goto parse_flag;

 case oPasswordAuthentication:
  intptr = &options->password_authentication;
  goto parse_flag;

 case oKbdInteractiveAuthentication:
  intptr = &options->kbd_interactive_authentication;
  goto parse_flag;

 case oKbdInteractiveDevices:
  charptr = &options->kbd_interactive_devices;
  goto parse_string;

 case oPubkeyAuthentication:
  multistate_ptr = multistate_pubkey_auth;
  intptr = &options->pubkey_authentication;
  goto parse_multistate;

 case oHostbasedAuthentication:
  intptr = &options->hostbased_authentication;
  goto parse_flag;

 case oGssAuthentication:
  intptr = &options->gss_authentication;
  goto parse_flag;

 case oGssDelegateCreds:
  intptr = &options->gss_deleg_creds;
  goto parse_flag;

 case oBatchMode:
  intptr = &options->batch_mode;
  goto parse_flag;

 case oCheckHostIP:
  intptr = &options->check_host_ip;
  goto parse_flag;

 case oVerifyHostKeyDNS:
  intptr = &options->verify_host_key_dns;
  multistate_ptr = multistate_yesnoask;
  goto parse_multistate;

 case oStrictHostKeyChecking:
  intptr = &options->strict_host_key_checking;
  multistate_ptr = multistate_strict_hostkey;
  goto parse_multistate;

 case oCompression:
  intptr = &options->compression;
  multistate_ptr = multistate_compression;
  goto parse_multistate;

 case oTCPKeepAlive:
  intptr = &options->tcp_keep_alive;
  goto parse_flag;

 case oNoHostAuthenticationForLocalhost:
  intptr = &options->no_host_authentication_for_localhost;
  goto parse_flag;

 case oNumberOfPasswordPrompts:
  intptr = &options->number_of_password_prompts;
  goto parse_int;

 case oRekeyLimit:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshlog("readconf.c", __func__, 1165, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Missing argument.", filename, linenum)
               ;
   goto out;
  }
  if (strcmp(arg, "default") == 0) {
   val64 = 0;
  } else {
   if (scan_scaled(arg, &val64) == -1) {
    sshlog("readconf.c", __func__, 1173, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%.200s line %d: Bad number '%s': %s", filename, linenum, arg, strerror(
   (*__errno_location ())
   ))
                                                ;
    goto out;
   }
   if (val64 != 0 && val64 < 16) {
    sshlog("readconf.c", __func__, 1178, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%.200s line %d: RekeyLimit too small", filename, linenum)
                          ;
    goto out;
   }
  }
  if (*activep && options->rekey_limit == -1)
   options->rekey_limit = val64;
  if (ac != 0) {
   if (strcmp(av[0], "none") == 0) {
    (void)argv_next(&ac, &av);
    break;
   }
   intptr = &options->rekey_interval;
   goto parse_time;
  }
  break;

 case oIdentityFile:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshlog("readconf.c", __func__, 1198, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Missing argument.", filename, linenum)
                         ;
   goto out;
  }
  if (*activep) {
   intptr = &options->num_identity_files;
   if (*intptr >= 100) {
    sshlog("readconf.c", __func__, 1205, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%.200s line %d: Too many identity files " "specified (max %d).", filename, linenum, 100)

                               ;
    goto out;
   }
   add_identity_file(options, 
                             ((void *)0)
                                 ,
       arg, flags & 2);
  }
  break;

 case oCertificateFile:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshlog("readconf.c", __func__, 1218, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Missing argument.", filename, linenum)
                         ;
   goto out;
  }
  if (*activep) {
   intptr = &options->num_certificate_files;
   if (*intptr >= 100) {
    sshlog("readconf.c", __func__, 1225, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%.200s line %d: Too many certificate " "files specified (max %d).", filename, linenum, 100)


                                  ;
    goto out;
   }
   add_certificate_file(options, arg,
       flags & 2);
  }
  break;

 case oXAuthLocation:
  charptr=&options->xauth_location;
  goto parse_string;

 case oUser:
  charptr = &options->user;
parse_string:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshlog("readconf.c", __func__, 1245, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Missing argument.", filename, linenum)
                         ;
   goto out;
  }
  if (*activep && *charptr == 
                             ((void *)0)
                                 )
   *charptr = xstrdup(arg);
  break;

 case oGlobalKnownHostsFile:
  cpptr = (char **)&options->system_hostfiles;
  uintptr = &options->num_system_hostfiles;
  max_entries = 32;
parse_char_array:
  i = 0;
  value = *uintptr == 0;
  while ((arg = argv_next(&ac, &av)) != 
                                       ((void *)0)
                                           ) {
   if (*arg == '\0') {
    sshlog("readconf.c", __func__, 1262, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%s line %d: keyword %s empty argument", filename, linenum, keyword)
                                   ;
    goto out;
   }

   if (strcasecmp(arg, "none") == 0) {
    if (i > 0 || ac > 0) {
     sshlog("readconf.c", __func__, 1269, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "%s line %d: keyword %s \"none\" " "argument must appear alone.", filename, linenum, keyword)

                                    ;
     goto out;
    }
   }
   i++;
   if (*activep && value) {
    if ((*uintptr) >= max_entries) {
     sshlog("readconf.c", __func__, 1278, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "%s line %d: too many %s " "entries.", filename, linenum, keyword)

                 ;
     goto out;
    }
    cpptr[(*uintptr)++] = xstrdup(arg);
   }
  }
  break;

 case oUserKnownHostsFile:
  cpptr = (char **)&options->user_hostfiles;
  uintptr = &options->num_user_hostfiles;
  max_entries = 32;
  goto parse_char_array;

 case oHostname:
  charptr = &options->hostname;
  goto parse_string;

 case oHostKeyAlias:
  charptr = &options->host_key_alias;
  goto parse_string;

 case oPreferredAuthentications:
  charptr = &options->preferred_authentications;
  goto parse_string;

 case oBindAddress:
  charptr = &options->bind_address;
  goto parse_string;

 case oBindInterface:
  charptr = &options->bind_interface;
  goto parse_string;

 case oPKCS11Provider:
  charptr = &options->pkcs11_provider;
  goto parse_string;

 case oSecurityKeyProvider:
  charptr = &options->sk_provider;
  goto parse_string;

 case oKnownHostsCommand:
  charptr = &options->known_hosts_command;
  goto parse_command;

 case oProxyCommand:
  charptr = &options->proxy_command;

  if (options->jump_host != 
                           ((void *)0)
                               )
   charptr = &options->jump_host;
parse_command:
  if (str == 
            ((void *)0)
                ) {
   sshlog("readconf.c", __func__, 1333, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Missing argument.", filename, linenum)
                         ;
   goto out;
  }
  len = strspn(str, " \t\r\n" "=");
  if (*activep && *charptr == 
                             ((void *)0)
                                 )
   *charptr = xstrdup(str + len);
  argv_consume(&ac);
  break;

 case oProxyJump:
  if (str == 
            ((void *)0)
                ) {
   sshlog("readconf.c", __func__, 1345, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Missing argument.", filename, linenum)
                         ;
   goto out;
  }
  len = strspn(str, " \t\r\n" "=");

  if (parse_jump(str + len, options, *activep) == -1) {
   sshlog("readconf.c", __func__, 1352, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Invalid ProxyJump \"%s\"", filename, linenum, str + len)
                                    ;
   goto out;
  }
  argv_consume(&ac);
  break;

 case oPort:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshlog("readconf.c", __func__, 1362, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Missing argument.", filename, linenum)
                         ;
   goto out;
  }
  value = a2port(arg);
  if (value <= 0) {
   sshlog("readconf.c", __func__, 1368, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Bad port '%s'.", filename, linenum, arg)
                              ;
   goto out;
  }
  if (*activep && options->port == -1)
   options->port = value;
  break;

 case oConnectionAttempts:
  intptr = &options->connection_attempts;
parse_int:
  arg = argv_next(&ac, &av);
  if ((errstr = atoi_err(arg, &value)) != 
                                         ((void *)0)
                                             ) {
   sshlog("readconf.c", __func__, 1381, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s line %d: integer value %s.", filename, linenum, errstr)
                                 ;
   goto out;
  }
  if (*activep && *intptr == -1)
   *intptr = value;
  break;

 case oCiphers:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshlog("readconf.c", __func__, 1392, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Missing argument.", filename, linenum)
                         ;
   goto out;
  }
  if (*arg != '-' &&
      !ciphers_valid(*arg == '+' || *arg == '^' ? arg + 1 : arg)){
   sshlog("readconf.c", __func__, 1398, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Bad SSH2 cipher spec '%s'.", filename, linenum, arg ? arg : "<NONE>")
                                               ;
   goto out;
  }
  if (*activep && options->ciphers == 
                                     ((void *)0)
                                         )
   options->ciphers = xstrdup(arg);
  break;

 case oMacs:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshlog("readconf.c", __func__, 1409, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Missing argument.", filename, linenum)
                         ;
   goto out;
  }
  if (*arg != '-' &&
      !mac_valid(*arg == '+' || *arg == '^' ? arg + 1 : arg)) {
   sshlog("readconf.c", __func__, 1415, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Bad SSH2 MAC spec '%s'.", filename, linenum, arg ? arg : "<NONE>")
                                               ;
   goto out;
  }
  if (*activep && options->macs == 
                                  ((void *)0)
                                      )
   options->macs = xstrdup(arg);
  break;

 case oKexAlgorithms:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshlog("readconf.c", __func__, 1426, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Missing argument.", filename, linenum)
                         ;
   goto out;
  }
  if (*arg != '-' &&
      !kex_names_valid(*arg == '+' || *arg == '^' ?
      arg + 1 : arg)) {
   sshlog("readconf.c", __func__, 1433, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Bad SSH2 KexAlgorithms '%s'.", filename, linenum, arg ? arg : "<NONE>")
                                               ;
   goto out;
  }
  if (*activep && options->kex_algorithms == 
                                            ((void *)0)
                                                )
   options->kex_algorithms = xstrdup(arg);
  break;

 case oHostKeyAlgorithms:
  charptr = &options->hostkeyalgorithms;
parse_pubkey_algos:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshlog("readconf.c", __func__, 1446, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Missing argument.", filename, linenum)
                         ;
   goto out;
  }
  if (*arg != '-' &&
      !sshkey_names_valid2(*arg == '+' || *arg == '^' ?
      arg + 1 : arg, 1)) {
   sshlog("readconf.c", __func__, 1453, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s line %d: Bad key types '%s'.", filename, linenum, arg ? arg : "<NONE>")
                                               ;
   goto out;
  }
  if (*activep && *charptr == 
                             ((void *)0)
                                 )
   *charptr = xstrdup(arg);
  break;

 case oCASignatureAlgorithms:
  charptr = &options->ca_sign_algorithms;
  goto parse_pubkey_algos;

 case oLogLevel:
  log_level_ptr = &options->log_level;
  arg = argv_next(&ac, &av);
  value = log_level_number(arg);
  if (value == SYSLOG_LEVEL_NOT_SET) {
   sshlog("readconf.c", __func__, 1470, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: unsupported log level '%s'", filename, linenum, arg ? arg : "<NONE>")
                                               ;
   goto out;
  }
  if (*activep && *log_level_ptr == SYSLOG_LEVEL_NOT_SET)
   *log_level_ptr = (LogLevel) value;
  break;

 case oLogFacility:
  log_facility_ptr = &options->log_facility;
  arg = argv_next(&ac, &av);
  value = log_facility_number(arg);
  if (value == SYSLOG_FACILITY_NOT_SET) {
   sshlog("readconf.c", __func__, 1483, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: unsupported log facility '%s'", filename, linenum, arg ? arg : "<NONE>")
                                               ;
   goto out;
  }
  if (*log_facility_ptr == -1)
   *log_facility_ptr = (SyslogFacility) value;
  break;

 case oLogVerbose:
  cppptr = &options->log_verbose;
  uintptr = &options->num_log_verbose;
  i = 0;
  while ((arg = argv_next(&ac, &av)) != 
                                       ((void *)0)
                                           ) {
   if (*arg == '\0') {
    sshlog("readconf.c", __func__, 1497, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%s line %d: keyword %s empty argument", filename, linenum, keyword)
                                   ;
    goto out;
   }

   if (strcasecmp(arg, "none") == 0) {
    if (i > 0 || ac > 0) {
     sshlog("readconf.c", __func__, 1504, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "%s line %d: keyword %s \"none\" " "argument must appear alone.", filename, linenum, keyword)

                                    ;
     goto out;
    }
   }
   i++;
   if (*activep && *uintptr == 0) {
    *cppptr = xrecallocarray(*cppptr, *uintptr,
        *uintptr + 1, sizeof(**cppptr));
    (*cppptr)[(*uintptr)++] = xstrdup(arg);
   }
  }
  break;

 case oLocalForward:
 case oRemoteForward:
 case oDynamicForward:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshlog("readconf.c", __func__, 1524, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Missing argument.", filename, linenum)
                         ;
   goto out;
  }

  remotefwd = (opcode == oRemoteForward);
  dynamicfwd = (opcode == oDynamicForward);

  if (!dynamicfwd) {
   arg2 = argv_next(&ac, &av);
   if (arg2 == 
              ((void *)0) 
                   || *arg2 == '\0') {
    if (remotefwd)
     dynamicfwd = 1;
    else {
     sshlog("readconf.c", __func__, 1538, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "%.200s line %d: Missing target " "argument.", filename, linenum)
                                        ;
     goto out;
    }
   } else {

    snprintf(fwdarg, sizeof(fwdarg), "%s:%s", arg,
        arg2);
   }
  }
  if (dynamicfwd)
   strlcpy(fwdarg, arg, sizeof(fwdarg));

  if (parse_forward(&fwd, fwdarg, dynamicfwd, remotefwd) == 0) {
   sshlog("readconf.c", __func__, 1552, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Bad forwarding specification.", filename, linenum)
                         ;
   goto out;
  }

  if (*activep) {
   if (remotefwd) {
    add_remote_forward(options, &fwd);
   } else {
    add_local_forward(options, &fwd);
   }
  }
  break;

 case oPermitRemoteOpen:
  uintptr = &options->num_permitted_remote_opens;
  cppptr = &options->permitted_remote_opens;
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("readconf.c", __func__, 1571, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: missing %s specification", filename, linenum, lookup_opcode_name(opcode))
                                                     ;
  uvalue = *uintptr;
  if (strcmp(arg, "any") == 0 || strcmp(arg, "none") == 0) {
   if (*activep && uvalue == 0) {
    *uintptr = 1;
    *cppptr = xcalloc(1, sizeof(**cppptr));
    (*cppptr)[0] = xstrdup(arg);
   }
   break;
  }
  while ((arg = argv_next(&ac, &av)) != 
                                       ((void *)0)
                                           ) {
   arg2 = xstrdup(arg);
   p = hpdelim(&arg);
   if (p == 
           ((void *)0)
               ) {
    sshfatal("readconf.c", __func__, 1586, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s line %d: missing host in %s", filename, linenum, lookup_opcode_name(opcode))

                                   ;
   }
   p = cleanhostname(p);




   if (arg == 
             ((void *)0) 
                  ||
       (strcmp(arg, "*") != 0 && a2port(arg) <= 0)) {
    sshfatal("readconf.c", __func__, 1597, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s line %d: bad port number in %s", filename, linenum, lookup_opcode_name(opcode))

                                   ;
   }
   if (*activep && uvalue == 0) {
    opt_array_append(filename, linenum,
        lookup_opcode_name(opcode),
        cppptr, uintptr, arg2);
   }
   free(arg2);
  }
  break;

 case oClearAllForwardings:
  intptr = &options->clear_forwardings;
  goto parse_flag;

 case oHost:
  if (cmdline) {
   sshlog("readconf.c", __func__, 1616, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Host directive not supported as a command-line " "option")
                ;
   goto out;
  }
  *activep = 0;
  arg2 = 
        ((void *)0)
            ;
  while ((arg = argv_next(&ac, &av)) != 
                                       ((void *)0)
                                           ) {
   if (*arg == '\0') {
    sshlog("readconf.c", __func__, 1624, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%s line %d: keyword %s empty argument", filename, linenum, keyword)
                                   ;
    goto out;
   }
   if ((flags & 8) != 0) {
    argv_consume(&ac);
    break;
   }
   negated = *arg == '!';
   if (negated)
    arg++;
   if (match_pattern(host, arg)) {
    if (negated) {
     sshlog("readconf.c", __func__, 1637, 0, SYSLOG_LEVEL_DEBUG1, 
    ((void *)0)
    , "%.200s line %d: Skipping Host " "block because of negated match " "for %.100s", filename, linenum, arg)


             ;
     *activep = 0;
     argv_consume(&ac);
     break;
    }
    if (!*activep)
     arg2 = arg;
    *activep = 1;
   }
  }
  if (*activep)
   sshlog("readconf.c", __func__, 1651, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "%.200s line %d: Applying options for %.100s", filename, linenum, arg2)
                               ;
  break;

 case oMatch:
  if (cmdline) {
   sshlog("readconf.c", __func__, 1657, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Host directive not supported as a command-line " "option")
                ;
   goto out;
  }
  value = match_cfg_line(options, &str, pw, host, original_host,
      flags & 4, want_final_pass,
      filename, linenum);
  if (value < 0) {
   sshlog("readconf.c", __func__, 1665, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Bad Match condition", filename, linenum)
               ;
   goto out;
  }
  *activep = (flags & 8) ? 0 : value;





  if (str == 
            ((void *)0) 
                 || *str == '\0')
   argv_consume(&ac);
  break;

 case oEscapeChar:
  intptr = &options->escape_char;
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshlog("readconf.c", __func__, 1683, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Missing argument.", filename, linenum)
                         ;
   goto out;
  }
  if (strcmp(arg, "none") == 0)
   value = -2;
  else if (arg[1] == '\0')
   value = (u_char) arg[0];
  else if (arg[0] == '^' && arg[2] == 0 &&
      (u_char) arg[1] >= 64 && (u_char) arg[1] < 128)
   value = (u_char) arg[1] & 31;
  else {
   sshlog("readconf.c", __func__, 1695, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Bad escape character.", filename, linenum)
                         ;
   goto out;
  }
  if (*activep && *intptr == -1)
   *intptr = value;
  break;

 case oAddressFamily:
  intptr = &options->address_family;
  multistate_ptr = multistate_addressfamily;
  goto parse_multistate;

 case oEnableSSHKeysign:
  intptr = &options->enable_ssh_keysign;
  goto parse_flag;

 case oIdentitiesOnly:
  intptr = &options->identities_only;
  goto parse_flag;

 case oServerAliveInterval:
  intptr = &options->server_alive_interval;
  goto parse_time;

 case oServerAliveCountMax:
  intptr = &options->server_alive_count_max;
  goto parse_int;

 case oSendEnv:
  while ((arg = argv_next(&ac, &av)) != 
                                       ((void *)0)
                                           ) {
   if (*arg == '\0' || strchr(arg, '=') != 
                                          ((void *)0)
                                              ) {
    sshlog("readconf.c", __func__, 1727, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%s line %d: Invalid environment name.", filename, linenum)
                          ;
    goto out;
   }
   if (!*activep)
    continue;
   if (*arg == '-') {

    rm_env(options, arg, filename, linenum);
    continue;
   }
   opt_array_append(filename, linenum,
       lookup_opcode_name(opcode),
       &options->send_env, &options->num_send_env, arg);
  }
  break;

 case oSetEnv:
  value = options->num_setenv;
  while ((arg = argv_next(&ac, &av)) != 
                                       ((void *)0)
                                           ) {
   if (strchr(arg, '=') == 
                          ((void *)0)
                              ) {
    sshlog("readconf.c", __func__, 1748, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%s line %d: Invalid SetEnv.", filename, linenum)
                          ;
    goto out;
   }
   if (!*activep || value != 0)
    continue;
   if (lookup_setenv_in_list(arg, options->setenv,
       options->num_setenv) != 
                              ((void *)0)
                                  ) {
    sshlog("readconf.c", __func__, 1756, 0, SYSLOG_LEVEL_DEBUG2, 
   ((void *)0)
   , "%s line %d: ignoring duplicate env " "name \"%.64s\"", filename, linenum, arg)
                                                 ;
    continue;
   }
   opt_array_append(filename, linenum,
       lookup_opcode_name(opcode),
       &options->setenv, &options->num_setenv, arg);
  }
  break;

 case oControlPath:
  charptr = &options->control_path;
  goto parse_string;

 case oControlMaster:
  intptr = &options->control_master;
  multistate_ptr = multistate_controlmaster;
  goto parse_multistate;

 case oControlPersist:

  intptr = &options->control_persist;
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshlog("readconf.c", __func__, 1780, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Missing ControlPersist" " argument.", filename, linenum)
                                       ;
   goto out;
  }
  value = 0;
  value2 = 0;
  if (strcmp(arg, "no") == 0 || strcmp(arg, "false") == 0)
   value = 0;
  else if (strcmp(arg, "yes") == 0 || strcmp(arg, "true") == 0)
   value = 1;
  else if ((value2 = convtime(arg)) >= 0)
   value = 1;
  else {
   sshlog("readconf.c", __func__, 1793, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Bad ControlPersist argument.", filename, linenum)
                         ;
   goto out;
  }
  if (*activep && *intptr == -1) {
   *intptr = value;
   options->control_persist_timeout = value2;
  }
  break;

 case oHashKnownHosts:
  intptr = &options->hash_known_hosts;
  goto parse_flag;

 case oTunnel:
  intptr = &options->tun_open;
  multistate_ptr = multistate_tunnel;
  goto parse_multistate;

 case oTunnelDevice:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshlog("readconf.c", __func__, 1815, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Missing argument.", filename, linenum)
                         ;
   goto out;
  }
  value = a2tun(arg, &value2);
  if (value == (0x7fffffff - 1)) {
   sshlog("readconf.c", __func__, 1821, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Bad tun device.", filename, linenum)
                         ;
   goto out;
  }
  if (*activep && options->tun_local == -1) {
   options->tun_local = value;
   options->tun_remote = value2;
  }
  break;

 case oLocalCommand:
  charptr = &options->local_command;
  goto parse_command;

 case oPermitLocalCommand:
  intptr = &options->permit_local_command;
  goto parse_flag;

 case oRemoteCommand:
  charptr = &options->remote_command;
  goto parse_command;

 case oVisualHostKey:
  intptr = &options->visual_host_key;
  goto parse_flag;

 case oInclude:
  if (cmdline) {
   sshlog("readconf.c", __func__, 1849, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Include directive not supported as a " "command-line option")
                             ;
   goto out;
  }
  value = 0;
  while ((arg = argv_next(&ac, &av)) != 
                                       ((void *)0)
                                           ) {
   if (*arg == '\0') {
    sshlog("readconf.c", __func__, 1856, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%s line %d: keyword %s empty argument", filename, linenum, keyword)
                                   ;
    goto out;
   }







   if (*arg == '~' && (flags & 2) == 0) {
    sshlog("readconf.c", __func__, 1868, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%.200s line %d: bad include path %s.", filename, linenum, arg)
                               ;
    goto out;
   }
   if (!path_absolute(arg) && *arg != '~') {
    xasprintf(&arg2, "%s/%s",
        (flags & 2) ?
        "~/" ".ssh" : "/usr/local/etc", arg);
   } else
    arg2 = xstrdup(arg);
   memset(&gl, 0, sizeof(gl));
   r = _ssh__compat_glob(arg2, 0x0800, 
      ((void *)0)
      , &gl);
   if (r == (-3)) {
    sshlog("readconf.c", __func__, 1881, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "%.200s line %d: include %s matched no " "files",filename, linenum, arg2)
                                        ;
    free(arg2);
    continue;
   } else if (r != 0) {
    sshlog("readconf.c", __func__, 1886, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%.200s line %d: glob failed for %s.", filename, linenum, arg2)
                                ;
    goto out;
   }
   free(arg2);
   oactive = *activep;
   for (i = 0; i < gl.gl_pathc; i++) {
    sshlog("readconf.c", __func__, 1893, 0, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "%.200s line %d: Including file %s " "depth %d%s", filename, linenum, gl.gl_pathv[i], depth, oactive ? "" : " (parse only)")


                                       ;
    r = read_config_file_depth(gl.gl_pathv[i],
        pw, host, original_host, options,
        flags | 1 |
        (oactive ? 0 : 8),
        activep, want_final_pass, depth + 1);
    if (r != 1 && 
                 (*__errno_location ()) 
                       != 
                          2
                                ) {
     sshlog("readconf.c", __func__, 1903, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "Can't open user config file " "%.100s: %.100s", gl.gl_pathv[i], strerror(
    (*__errno_location ())
    ))

                         ;
     _ssh__compat_globfree(&gl);
     goto out;
    }




    *activep = oactive;
    if (r != 1)
     value = -1;
   }
   _ssh__compat_globfree(&gl);
  }
  if (value != 0)
   ret = value;
  break;

 case oIPQoS:
  arg = argv_next(&ac, &av);
  if ((value = parse_ipqos(arg)) == -1) {
   sshlog("readconf.c", __func__, 1926, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s line %d: Bad IPQoS value: %s", filename, linenum, arg)
                              ;
   goto out;
  }
  arg = argv_next(&ac, &av);
  if (arg == 
            ((void *)0)
                )
   value2 = value;
  else if ((value2 = parse_ipqos(arg)) == -1) {
   sshlog("readconf.c", __func__, 1934, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s line %d: Bad IPQoS value: %s", filename, linenum, arg)
                              ;
   goto out;
  }
  if (*activep && options->ip_qos_interactive == -1) {
   options->ip_qos_interactive = value;
   options->ip_qos_bulk = value2;
  }
  break;

 case oRequestTTY:
  intptr = &options->request_tty;
  multistate_ptr = multistate_requesttty;
  goto parse_multistate;

 case oSessionType:
  intptr = &options->session_type;
  multistate_ptr = multistate_sessiontype;
  goto parse_multistate;

 case oStdinNull:
  intptr = &options->stdin_null;
  goto parse_flag;

 case oForkAfterAuthentication:
  intptr = &options->fork_after_authentication;
  goto parse_flag;

 case oIgnoreUnknown:
  charptr = &options->ignored_unknown;
  goto parse_string;

 case oProxyUseFdpass:
  intptr = &options->proxy_use_fdpass;
  goto parse_flag;

 case oCanonicalDomains:
  value = options->num_canonical_domains != 0;
  i = 0;
  while ((arg = argv_next(&ac, &av)) != 
                                       ((void *)0)
                                           ) {
   if (*arg == '\0') {
    sshlog("readconf.c", __func__, 1975, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%s line %d: keyword %s empty argument", filename, linenum, keyword)
                                   ;
    goto out;
   }

   if (strcasecmp(arg, "none") == 0) {
    if (i > 0 || ac > 0) {
     sshlog("readconf.c", __func__, 1982, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "%s line %d: keyword %s \"none\" " "argument must appear alone.", filename, linenum, keyword)

                                    ;
     goto out;
    }
   }
   i++;
   if (!valid_domain(arg, 1, &errstr)) {
    sshlog("readconf.c", __func__, 1990, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%s line %d: %s", filename, linenum, errstr)
               ;
    goto out;
   }
   if (!*activep || value)
    continue;
   if (options->num_canonical_domains >=
       32) {
    sshlog("readconf.c", __func__, 1998, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%s line %d: too many hostname suffixes.", filename, linenum)
                          ;
    goto out;
   }
   options->canonical_domains[
       options->num_canonical_domains++] = xstrdup(arg);
  }
  break;

 case oCanonicalizePermittedCNAMEs:
  value = options->num_permitted_cnames != 0;
  i = 0;
  while ((arg = argv_next(&ac, &av)) != 
                                       ((void *)0)
                                           ) {




   if (strcasecmp(arg, "none") == 0) {
    if (i > 0 || ac > 0) {
     sshlog("readconf.c", __func__, 2017, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "%s line %d: keyword %s \"none\" " "argument must appear alone.", filename, linenum, keyword)

                                    ;
     goto out;
    }
    arg2 = "";
   } else if (strcmp(arg, "*") == 0) {
    arg2 = arg;
   } else {
    lowercase(arg);
    if ((arg2 = strchr(arg, ':')) == 
                                    ((void *)0) 
                                         ||
        arg2[1] == '\0') {
     sshlog("readconf.c", __func__, 2029, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "%s line %d: " "Invalid permitted CNAME \"%s\"", filename, linenum, arg)

                                ;
     goto out;
    }
    *arg2 = '\0';
    arg2++;
   }
   i++;
   if (!*activep || value)
    continue;
   if (options->num_permitted_cnames >=
       32) {
    sshlog("readconf.c", __func__, 2042, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%s line %d: too many permitted CNAMEs.", filename, linenum)
                          ;
    goto out;
   }
   cname = options->permitted_cnames +
       options->num_permitted_cnames++;
   cname->source_list = xstrdup(arg);
   cname->target_list = xstrdup(arg2);
  }
  break;

 case oCanonicalizeHostname:
  intptr = &options->canonicalize_hostname;
  multistate_ptr = multistate_canonicalizehostname;
  goto parse_multistate;

 case oCanonicalizeMaxDots:
  intptr = &options->canonicalize_max_dots;
  goto parse_int;

 case oCanonicalizeFallbackLocal:
  intptr = &options->canonicalize_fallback_local;
  goto parse_flag;

 case oStreamLocalBindMask:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshlog("readconf.c", __func__, 2069, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Missing StreamLocalBindMask " "argument.", filename, linenum)
                                      ;
   goto out;
  }

  value = strtol(arg, &endofnumber, 8);
  if (arg == endofnumber || value < 0 || value > 0777) {
   sshlog("readconf.c", __func__, 2076, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Bad mask.", filename, linenum);
   goto out;
  }
  options->fwd_opts.streamlocal_bind_mask = (mode_t)value;
  break;

 case oStreamLocalBindUnlink:
  intptr = &options->fwd_opts.streamlocal_bind_unlink;
  goto parse_flag;

 case oRevokedHostKeys:
  charptr = &options->revoked_host_keys;
  goto parse_string;

 case oFingerprintHash:
  intptr = &options->fingerprint_hash;
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshlog("readconf.c", __func__, 2094, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Missing argument.", filename, linenum)
                         ;
   goto out;
  }
  if ((value = ssh_digest_alg_by_name(arg)) == -1) {
   sshlog("readconf.c", __func__, 2099, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Invalid hash algorithm \"%s\".", filename, linenum, arg)
                              ;
   goto out;
  }
  if (*activep && *intptr == -1)
   *intptr = value;
  break;

 case oUpdateHostkeys:
  intptr = &options->update_hostkeys;
  multistate_ptr = multistate_yesnoask;
  goto parse_multistate;

 case oHostbasedAcceptedAlgorithms:
  charptr = &options->hostbased_accepted_algos;
  goto parse_pubkey_algos;

 case oPubkeyAcceptedAlgorithms:
  charptr = &options->pubkey_accepted_algos;
  goto parse_pubkey_algos;

 case oAddKeysToAgent:
  arg = argv_next(&ac, &av);
  arg2 = argv_next(&ac, &av);
  value = parse_multistate_value(arg, filename, linenum,
      multistate_yesnoaskconfirm);
  value2 = 0;
  if (value == 3 && arg2 != 
                           ((void *)0)
                               ) {

   if ((value2 = convtime(arg2)) == -1 ||
       value2 > 0x7fffffff) {
    sshlog("readconf.c", __func__, 2130, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%s line %d: invalid time value.", filename, linenum)
                          ;
    goto out;
   }
  } else if (value == -1 && arg2 == 
                                   ((void *)0)
                                       ) {
   if ((value2 = convtime(arg)) == -1 ||
       value2 > 0x7fffffff) {
    sshlog("readconf.c", __func__, 2137, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%s line %d: unsupported option", filename, linenum)
                          ;
    goto out;
   }
   value = 1;
  } else if (value == -1 || arg2 != 
                                   ((void *)0)
                                       ) {
   sshlog("readconf.c", __func__, 2143, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s line %d: unsupported option", filename, linenum)
                         ;
   goto out;
  }
  if (*activep && options->add_keys_to_agent == -1) {
   options->add_keys_to_agent = value;
   options->add_keys_to_agent_lifespan = value2;
  }
  break;

 case oIdentityAgent:
  charptr = &options->identity_agent;
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshlog("readconf.c", __func__, 2157, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Missing argument.", filename, linenum)
                         ;
   goto out;
  }
  parse_agent_path:

  if ((arg2 = dollar_expand(&r, arg)) == 
                                        ((void *)0) 
                                             || r) {
   sshlog("readconf.c", __func__, 2164, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Invalid environment expansion " "%s.", filename, linenum, arg)
                                     ;
   goto out;
  }
  free(arg2);

  if (arg[0] == '$' && arg[1] != '{' &&
      !valid_env_name(arg + 1)) {
   sshlog("readconf.c", __func__, 2172, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.200s line %d: Invalid environment name %s.", filename, linenum, arg)
                              ;
   goto out;
  }
  if (*activep && *charptr == 
                             ((void *)0)
                                 )
   *charptr = xstrdup(arg);
  break;

 case oRequiredRSASize:
  intptr = &options->required_rsa_size;
  goto parse_int;

 case oDeprecated:
  sshlog("readconf.c", __func__, 2185, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%s line %d: Deprecated option \"%s\"", filename, linenum, keyword)
                                 ;
  argv_consume(&ac);
  break;

 case oUnsupported:
  sshlog("readconf.c", __func__, 2191, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s line %d: Unsupported option \"%s\"", filename, linenum, keyword)
                                 ;
  argv_consume(&ac);
  break;

 default:
  sshlog("readconf.c", __func__, 2197, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s line %d: Unimplemented opcode %d", filename, linenum, opcode)
                                ;
  goto out;
 }


 if (ac > 0) {
  sshlog("readconf.c", __func__, 2204, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%.200s line %d: keyword %s extra arguments " "at end of line", filename, linenum, keyword)
                                                   ;
  goto out;
 }


 ret = 0;
 out:
 argv_free(oav, oac);
 return ret;
}






int
read_config_file(const char *filename, struct passwd *pw, const char *host,
    const char *original_host, Options *options, int flags,
    int *want_final_pass)
{
 int active = 1;

 return read_config_file_depth(filename, pw, host, original_host,
     options, flags, &active, want_final_pass, 0);
}


static int
read_config_file_depth(const char *filename, struct passwd *pw,
    const char *host, const char *original_host, Options *options,
    int flags, int *activep, int *want_final_pass, int depth)
{
 FILE *f;
 char *line = 
             ((void *)0)
                 ;
 size_t linesize = 0;
 int linenum;
 int bad_options = 0;

 if (depth < 0 || depth > 16)
  sshfatal("readconf.c", __func__, 2245, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Too many recursive configuration includes");

 if ((f = fopen(filename, "r")) == 
                                  ((void *)0)
                                      )
  return 0;

 if (flags & 1) {
  struct stat sb;

  if (fstat(fileno(f), &sb) == -1)
   sshfatal("readconf.c", __func__, 2254, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "fstat %s: %s", filename, strerror(
  (*__errno_location ())
  ));
  if (((sb.st_uid != 0 && sb.st_uid != getuid()) ||
      (sb.st_mode & 022) != 0))
   sshfatal("readconf.c", __func__, 2257, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Bad owner or permissions on %s", filename);
 }

 sshlog("readconf.c", __func__, 2260, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Reading configuration data %.200s", filename);





 linenum = 0;
 while (getline(&line, &linesize, f) != -1) {

  linenum++;





  if (process_config_line_depth(options, pw, host, original_host,
      line, filename, linenum, activep, flags, want_final_pass,
      depth) != 0)
   bad_options++;
 }
 free(line);
 fclose(f);
 if (bad_options > 0)
  sshfatal("readconf.c", __func__, 2283, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: terminating, %d bad configuration options", filename, bad_options)
                            ;
 return 1;
}


int
option_clear_or_none(const char *o)
{
 return o == 
            ((void *)0) 
                 || strcasecmp(o, "none") == 0;
}





int
config_has_permitted_cnames(Options *options)
{
 if (options->num_permitted_cnames == 1 &&
     strcasecmp(options->permitted_cnames[0].source_list, "none") == 0 &&
     strcmp(options->permitted_cnames[0].target_list, "") == 0)
  return 0;
 return options->num_permitted_cnames > 0;
}
void
initialize_options(Options * options)
{
 memset(options, 'X', sizeof(*options));
 options->forward_agent = -1;
 options->forward_agent_sock_path = 
                                   ((void *)0)
                                       ;
 options->forward_x11 = -1;
 options->forward_x11_trusted = -1;
 options->forward_x11_timeout = -1;
 options->stdio_forward_host = 
                              ((void *)0)
                                  ;
 options->stdio_forward_port = 0;
 options->clear_forwardings = -1;
 options->exit_on_forward_failure = -1;
 options->xauth_location = 
                          ((void *)0)
                              ;
 options->fwd_opts.gateway_ports = -1;
 options->fwd_opts.streamlocal_bind_mask = (mode_t)-1;
 options->fwd_opts.streamlocal_bind_unlink = -1;
 options->pubkey_authentication = -1;
 options->gss_authentication = -1;
 options->gss_deleg_creds = -1;
 options->password_authentication = -1;
 options->kbd_interactive_authentication = -1;
 options->kbd_interactive_devices = 
                                   ((void *)0)
                                       ;
 options->hostbased_authentication = -1;
 options->batch_mode = -1;
 options->check_host_ip = -1;
 options->strict_host_key_checking = -1;
 options->compression = -1;
 options->tcp_keep_alive = -1;
 options->port = -1;
 options->address_family = -1;
 options->connection_attempts = -1;
 options->connection_timeout = -1;
 options->number_of_password_prompts = -1;
 options->ciphers = 
                   ((void *)0)
                       ;
 options->macs = 
                ((void *)0)
                    ;
 options->kex_algorithms = 
                          ((void *)0)
                              ;
 options->hostkeyalgorithms = 
                             ((void *)0)
                                 ;
 options->ca_sign_algorithms = 
                              ((void *)0)
                                  ;
 options->num_identity_files = 0;
 memset(options->identity_keys, 0, sizeof(options->identity_keys));
 options->num_certificate_files = 0;
 memset(options->certificates, 0, sizeof(options->certificates));
 options->hostname = 
                    ((void *)0)
                        ;
 options->host_key_alias = 
                          ((void *)0)
                              ;
 options->proxy_command = 
                         ((void *)0)
                             ;
 options->jump_user = 
                     ((void *)0)
                         ;
 options->jump_host = 
                     ((void *)0)
                         ;
 options->jump_port = -1;
 options->jump_extra = 
                      ((void *)0)
                          ;
 options->user = 
                ((void *)0)
                    ;
 options->escape_char = -1;
 options->num_system_hostfiles = 0;
 options->num_user_hostfiles = 0;
 options->local_forwards = 
                          ((void *)0)
                              ;
 options->num_local_forwards = 0;
 options->remote_forwards = 
                           ((void *)0)
                               ;
 options->num_remote_forwards = 0;
 options->permitted_remote_opens = 
                                  ((void *)0)
                                      ;
 options->num_permitted_remote_opens = 0;
 options->log_facility = SYSLOG_FACILITY_NOT_SET;
 options->log_level = SYSLOG_LEVEL_NOT_SET;
 options->num_log_verbose = 0;
 options->log_verbose = 
                       ((void *)0)
                           ;
 options->preferred_authentications = 
                                     ((void *)0)
                                         ;
 options->bind_address = 
                        ((void *)0)
                            ;
 options->bind_interface = 
                          ((void *)0)
                              ;
 options->pkcs11_provider = 
                           ((void *)0)
                               ;
 options->sk_provider = 
                       ((void *)0)
                           ;
 options->enable_ssh_keysign = - 1;
 options->no_host_authentication_for_localhost = - 1;
 options->identities_only = - 1;
 options->rekey_limit = - 1;
 options->rekey_interval = -1;
 options->verify_host_key_dns = -1;
 options->server_alive_interval = -1;
 options->server_alive_count_max = -1;
 options->send_env = 
                    ((void *)0)
                        ;
 options->num_send_env = 0;
 options->setenv = 
                  ((void *)0)
                      ;
 options->num_setenv = 0;
 options->control_path = 
                        ((void *)0)
                            ;
 options->control_master = -1;
 options->control_persist = -1;
 options->control_persist_timeout = 0;
 options->hash_known_hosts = -1;
 options->tun_open = -1;
 options->tun_local = -1;
 options->tun_remote = -1;
 options->local_command = 
                         ((void *)0)
                             ;
 options->permit_local_command = -1;
 options->remote_command = 
                          ((void *)0)
                              ;
 options->add_keys_to_agent = -1;
 options->add_keys_to_agent_lifespan = -1;
 options->identity_agent = 
                          ((void *)0)
                              ;
 options->visual_host_key = -1;
 options->ip_qos_interactive = -1;
 options->ip_qos_bulk = -1;
 options->request_tty = -1;
 options->session_type = -1;
 options->stdin_null = -1;
 options->fork_after_authentication = -1;
 options->proxy_use_fdpass = -1;
 options->ignored_unknown = 
                           ((void *)0)
                               ;
 options->num_canonical_domains = 0;
 options->num_permitted_cnames = 0;
 options->canonicalize_max_dots = -1;
 options->canonicalize_fallback_local = -1;
 options->canonicalize_hostname = -1;
 options->revoked_host_keys = 
                             ((void *)0)
                                 ;
 options->fingerprint_hash = -1;
 options->update_hostkeys = -1;
 options->hostbased_accepted_algos = 
                                    ((void *)0)
                                        ;
 options->pubkey_accepted_algos = 
                                 ((void *)0)
                                     ;
 options->known_hosts_command = 
                               ((void *)0)
                                   ;
 options->required_rsa_size = -1;
}





void
fill_default_options_for_canonicalization(Options *options)
{
 if (options->canonicalize_max_dots == -1)
  options->canonicalize_max_dots = 1;
 if (options->canonicalize_fallback_local == -1)
  options->canonicalize_fallback_local = 1;
 if (options->canonicalize_hostname == -1)
  options->canonicalize_hostname = 0;
}





int
fill_default_options(Options * options)
{
 char *all_cipher, *all_mac, *all_kex, *all_key, *all_sig;
 char *def_cipher, *def_mac, *def_kex, *def_key, *def_sig;
 int ret = 0, r;

 if (options->forward_agent == -1)
  options->forward_agent = 0;
 if (options->forward_x11 == -1)
  options->forward_x11 = 0;
 if (options->forward_x11_trusted == -1)
  options->forward_x11_trusted = 0;
 if (options->forward_x11_timeout == -1)
  options->forward_x11_timeout = 1200;




 if (options->exit_on_forward_failure == -1)
  options->exit_on_forward_failure =
      options->stdio_forward_host != 
                                    ((void *)0) 
                                         ? 1 : 0;
 if (options->clear_forwardings == -1)
  options->clear_forwardings =
      options->stdio_forward_host != 
                                    ((void *)0) 
                                         ? 1 : 0;
 if (options->clear_forwardings == 1)
  clear_forwardings(options);

 if (options->xauth_location == 
                               ((void *)0)
                                   )
  options->xauth_location = xstrdup("/usr/bin/xauth");
 if (options->fwd_opts.gateway_ports == -1)
  options->fwd_opts.gateway_ports = 0;
 if (options->fwd_opts.streamlocal_bind_mask == (mode_t)-1)
  options->fwd_opts.streamlocal_bind_mask = 0177;
 if (options->fwd_opts.streamlocal_bind_unlink == -1)
  options->fwd_opts.streamlocal_bind_unlink = 0;
 if (options->pubkey_authentication == -1)
  options->pubkey_authentication = 0x03;
 if (options->gss_authentication == -1)
  options->gss_authentication = 0;
 if (options->gss_deleg_creds == -1)
  options->gss_deleg_creds = 0;
 if (options->password_authentication == -1)
  options->password_authentication = 1;
 if (options->kbd_interactive_authentication == -1)
  options->kbd_interactive_authentication = 1;
 if (options->hostbased_authentication == -1)
  options->hostbased_authentication = 0;
 if (options->batch_mode == -1)
  options->batch_mode = 0;
 if (options->check_host_ip == -1)
  options->check_host_ip = 0;
 if (options->strict_host_key_checking == -1)
  options->strict_host_key_checking = 3;
 if (options->compression == -1)
  options->compression = 0;
 if (options->tcp_keep_alive == -1)
  options->tcp_keep_alive = 1;
 if (options->port == -1)
  options->port = 0;
 if (options->address_family == -1)
  options->address_family = 
                           0
                                    ;
 if (options->connection_attempts == -1)
  options->connection_attempts = 1;
 if (options->number_of_password_prompts == -1)
  options->number_of_password_prompts = 3;

 if (options->add_keys_to_agent == -1) {
  options->add_keys_to_agent = 0;
  options->add_keys_to_agent_lifespan = 0;
 }
 if (options->num_identity_files == 0) {
  add_identity_file(options, "~/", ".ssh" "/id_rsa", 0);

  add_identity_file(options, "~/", ".ssh" "/id_ecdsa", 0);
  add_identity_file(options, "~/",
      ".ssh" "/id_ecdsa_sk", 0);

  add_identity_file(options, "~/",
      ".ssh" "/id_ed25519", 0);
  add_identity_file(options, "~/",
      ".ssh" "/id_ed25519_sk", 0);
  add_identity_file(options, "~/", ".ssh" "/id_xmss", 0);
  add_identity_file(options, "~/", ".ssh" "/id_dsa", 0);
 }
 if (options->escape_char == -1)
  options->escape_char = '~';
 if (options->num_system_hostfiles == 0) {
  options->system_hostfiles[options->num_system_hostfiles++] =
      xstrdup("/usr/local/etc" "/ssh_known_hosts");
  options->system_hostfiles[options->num_system_hostfiles++] =
      xstrdup("/usr/local/etc" "/ssh_known_hosts2");
 }
 if (options->update_hostkeys == -1) {
  if (options->verify_host_key_dns <= 0 &&
      (options->num_user_hostfiles == 0 ||
      (options->num_user_hostfiles == 1 && strcmp(options->
      user_hostfiles[0], "~/" ".ssh" "/known_hosts") == 0)))
   options->update_hostkeys = 1;
  else
   options->update_hostkeys = 0;
 }
 if (options->num_user_hostfiles == 0) {
  options->user_hostfiles[options->num_user_hostfiles++] =
      xstrdup("~/" ".ssh" "/known_hosts");
  options->user_hostfiles[options->num_user_hostfiles++] =
      xstrdup("~/" ".ssh" "/known_hosts2");
 }
 if (options->log_level == SYSLOG_LEVEL_NOT_SET)
  options->log_level = SYSLOG_LEVEL_INFO;
 if (options->log_facility == SYSLOG_FACILITY_NOT_SET)
  options->log_facility = SYSLOG_FACILITY_USER;
 if (options->no_host_authentication_for_localhost == - 1)
  options->no_host_authentication_for_localhost = 0;
 if (options->identities_only == -1)
  options->identities_only = 0;
 if (options->enable_ssh_keysign == -1)
  options->enable_ssh_keysign = 0;
 if (options->rekey_limit == -1)
  options->rekey_limit = 0;
 if (options->rekey_interval == -1)
  options->rekey_interval = 0;
 if (options->verify_host_key_dns == -1)
  options->verify_host_key_dns = 0;
 if (options->server_alive_interval == -1)
  options->server_alive_interval = 0;
 if (options->server_alive_count_max == -1)
  options->server_alive_count_max = 3;
 if (options->control_master == -1)
  options->control_master = 0;
 if (options->control_persist == -1) {
  options->control_persist = 0;
  options->control_persist_timeout = 0;
 }
 if (options->hash_known_hosts == -1)
  options->hash_known_hosts = 0;
 if (options->tun_open == -1)
  options->tun_open = 0x00;
 if (options->tun_local == -1)
  options->tun_local = 0x7fffffff;
 if (options->tun_remote == -1)
  options->tun_remote = 0x7fffffff;
 if (options->permit_local_command == -1)
  options->permit_local_command = 0;
 if (options->visual_host_key == -1)
  options->visual_host_key = 0;
 if (options->ip_qos_interactive == -1)
  options->ip_qos_interactive = 
                               0x48
                                              ;
 if (options->ip_qos_bulk == -1)
  options->ip_qos_bulk = 0x20;
 if (options->request_tty == -1)
  options->request_tty = 0;
 if (options->session_type == -1)
  options->session_type = 2;
 if (options->stdin_null == -1)
  options->stdin_null = 0;
 if (options->fork_after_authentication == -1)
  options->fork_after_authentication = 0;
 if (options->proxy_use_fdpass == -1)
  options->proxy_use_fdpass = 0;
 if (options->canonicalize_max_dots == -1)
  options->canonicalize_max_dots = 1;
 if (options->canonicalize_fallback_local == -1)
  options->canonicalize_fallback_local = 1;
 if (options->canonicalize_hostname == -1)
  options->canonicalize_hostname = 0;
 if (options->fingerprint_hash == -1)
  options->fingerprint_hash = 2;




 if (options->sk_provider == 
                            ((void *)0)
                                )
  options->sk_provider = xstrdup("$SSH_SK_PROVIDER");

 if (options->required_rsa_size == -1)
  options->required_rsa_size = 1024;


 all_cipher = cipher_alg_list(',', 0);
 all_mac = mac_alg_list(',');
 all_kex = kex_alg_list(',');
 all_key = sshkey_alg_list(0, 0, 1, ',');
 all_sig = sshkey_alg_list(0, 1, 1, ',');

 def_cipher = match_filter_allowlist("chacha20-poly1305@openssh.com," "aes128-ctr,aes192-ctr,aes256-ctr," "aes128-gcm@openssh.com,aes256-gcm@openssh.com", all_cipher);
 def_mac = match_filter_allowlist("umac-64-etm@openssh.com," "umac-128-etm@openssh.com," "hmac-sha2-256-etm@openssh.com," "hmac-sha2-512-etm@openssh.com," "hmac-sha1-etm@openssh.com," "umac-64@openssh.com," "umac-128@openssh.com," "hmac-sha2-256," "hmac-sha2-512," "hmac-sha1", all_mac);
 def_kex = match_filter_allowlist("sntrup761x25519-sha512@openssh.com," "curve25519-sha256," "curve25519-sha256@libssh.org," "ecdh-sha2-nistp256," "ecdh-sha2-nistp384," "ecdh-sha2-nistp521," "diffie-hellman-group-exchange-sha256," "diffie-hellman-group16-sha512," "diffie-hellman-group18-sha512," "diffie-hellman-group14-sha256", all_kex);
 def_key = match_filter_allowlist("ssh-ed25519-cert-v01@openssh.com," "ecdsa-sha2-nistp256-cert-v01@openssh.com," "ecdsa-sha2-nistp384-cert-v01@openssh.com," "ecdsa-sha2-nistp521-cert-v01@openssh.com," "sk-ssh-ed25519-cert-v01@openssh.com," "sk-ecdsa-sha2-nistp256-cert-v01@openssh.com," "rsa-sha2-512-cert-v01@openssh.com," "rsa-sha2-256-cert-v01@openssh.com," "ssh-ed25519," "ecdsa-sha2-nistp256," "ecdsa-sha2-nistp384," "ecdsa-sha2-nistp521," "sk-ssh-ed25519@openssh.com," "sk-ecdsa-sha2-nistp256@openssh.com," "rsa-sha2-512," "rsa-sha2-256", all_key);
 def_sig = match_filter_allowlist("ssh-ed25519," "ecdsa-sha2-nistp256," "ecdsa-sha2-nistp384," "ecdsa-sha2-nistp521," "sk-ssh-ed25519@openssh.com," "sk-ecdsa-sha2-nistp256@openssh.com," "rsa-sha2-512," "rsa-sha2-256", all_sig);
 do { if ((r = kex_assemble_names(&options->ciphers, def_cipher, all_cipher)) != 0) { sshlog("readconf.c", __func__, 2651, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "%s", "ciphers"); goto fail; } } while (0);
 do { if ((r = kex_assemble_names(&options->macs, def_mac, all_mac)) != 0) { sshlog("readconf.c", __func__, 2652, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "%s", "macs"); goto fail; } } while (0);
 do { if ((r = kex_assemble_names(&options->kex_algorithms, def_kex, all_kex)) != 0) { sshlog("readconf.c", __func__, 2653, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "%s", "kex_algorithms"); goto fail; } } while (0);
 do { if ((r = kex_assemble_names(&options->hostbased_accepted_algos, def_key, all_key)) != 0) { sshlog("readconf.c", __func__, 2654, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "%s", "hostbased_accepted_algos"); goto fail; } } while (0);
 do { if ((r = kex_assemble_names(&options->pubkey_accepted_algos, def_key, all_key)) != 0) { sshlog("readconf.c", __func__, 2655, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "%s", "pubkey_accepted_algos"); goto fail; } } while (0);
 do { if ((r = kex_assemble_names(&options->ca_sign_algorithms, def_sig, all_sig)) != 0) { sshlog("readconf.c", __func__, 2656, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "%s", "ca_sign_algorithms"); goto fail; } } while (0);
 do { if (option_clear_or_none(options->local_command)) { free(options->local_command); options->local_command = 
((void *)0)
; } } while(0);
 do { if (option_clear_or_none(options->remote_command)) { free(options->remote_command); options->remote_command = 
((void *)0)
; } } while(0);
 do { if (option_clear_or_none(options->proxy_command)) { free(options->proxy_command); options->proxy_command = 
((void *)0)
; } } while(0);
 do { if (option_clear_or_none(options->control_path)) { free(options->control_path); options->control_path = 
((void *)0)
; } } while(0);
 do { if (option_clear_or_none(options->revoked_host_keys)) { free(options->revoked_host_keys); options->revoked_host_keys = 
((void *)0)
; } } while(0);
 do { if (option_clear_or_none(options->pkcs11_provider)) { free(options->pkcs11_provider); options->pkcs11_provider = 
((void *)0)
; } } while(0);
 do { if (option_clear_or_none(options->sk_provider)) { free(options->sk_provider); options->sk_provider = 
((void *)0)
; } } while(0);
 do { if (option_clear_or_none(options->known_hosts_command)) { free(options->known_hosts_command); options->known_hosts_command = 
((void *)0)
; } } while(0);
 if (options->jump_host != 
                          ((void *)0) 
                               &&
     strcmp(options->jump_host, "none") == 0 &&
     options->jump_port == 0 && options->jump_user == 
                                                     ((void *)0)
                                                         ) {
  free(options->jump_host);
  options->jump_host = 
                      ((void *)0)
                          ;
 }
 if (options->num_permitted_cnames == 1 &&
     !config_has_permitted_cnames(options)) {

  free(options->permitted_cnames[0].source_list);
  free(options->permitted_cnames[0].target_list);
  memset(options->permitted_cnames, '\0',
      sizeof(*options->permitted_cnames));
  options->num_permitted_cnames = 0;
 }







 ret = 0;
 fail:
 free(all_cipher);
 free(all_mac);
 free(all_kex);
 free(all_key);
 free(all_sig);
 free(def_cipher);
 free(def_mac);
 free(def_kex);
 free(def_key);
 free(def_sig);
 return ret;
}

void
free_options(Options *o)
{
 int i;

 if (o == 
         ((void *)0)
             )
  return;
 free(o->forward_agent_sock_path);
 free(o->xauth_location);
 do { u_int _i; for (_i = 0; _i < (o->num_log_verbose); _i++) free((o->log_verbose)[_i]); } while (0);
 free(o->log_verbose);
 free(o->ciphers);
 free(o->macs);
 free(o->hostkeyalgorithms);
 free(o->kex_algorithms);
 free(o->ca_sign_algorithms);
 free(o->hostname);
 free(o->host_key_alias);
 free(o->proxy_command);
 free(o->user);
 do { u_int _i; for (_i = 0; _i < (o->num_system_hostfiles); _i++) free((o->system_hostfiles)[_i]); } while (0);
 do { u_int _i; for (_i = 0; _i < (o->num_user_hostfiles); _i++) free((o->user_hostfiles)[_i]); } while (0);
 free(o->preferred_authentications);
 free(o->bind_address);
 free(o->bind_interface);
 free(o->pkcs11_provider);
 free(o->sk_provider);
 for (i = 0; i < o->num_identity_files; i++) {
  free(o->identity_files[i]);
  sshkey_free(o->identity_keys[i]);
 }
 for (i = 0; i < o->num_certificate_files; i++) {
  free(o->certificate_files[i]);
  sshkey_free(o->certificates[i]);
 }
 free(o->identity_agent);
 for (i = 0; i < o->num_local_forwards; i++) {
  free(o->local_forwards[i].listen_host);
  free(o->local_forwards[i].listen_path);
  free(o->local_forwards[i].connect_host);
  free(o->local_forwards[i].connect_path);
 }
 free(o->local_forwards);
 for (i = 0; i < o->num_remote_forwards; i++) {
  free(o->remote_forwards[i].listen_host);
  free(o->remote_forwards[i].listen_path);
  free(o->remote_forwards[i].connect_host);
  free(o->remote_forwards[i].connect_path);
 }
 free(o->remote_forwards);
 free(o->stdio_forward_host);
 do { u_int _i; for (_i = 0; _i < (o->num_send_env); _i++) free((o->send_env)[_i]); } while (0);
 free(o->send_env);
 do { u_int _i; for (_i = 0; _i < (o->num_setenv); _i++) free((o->setenv)[_i]); } while (0);
 free(o->setenv);
 free(o->control_path);
 free(o->local_command);
 free(o->remote_command);
 do { int _i; for (_i = 0; _i < (o->num_canonical_domains); _i++) free((o->canonical_domains)[_i]); } while (0);
 for (i = 0; i < o->num_permitted_cnames; i++) {
  free(o->permitted_cnames[i].source_list);
  free(o->permitted_cnames[i].target_list);
 }
 free(o->revoked_host_keys);
 free(o->hostbased_accepted_algos);
 free(o->pubkey_accepted_algos);
 free(o->jump_user);
 free(o->jump_host);
 free(o->jump_extra);
 free(o->ignored_unknown);
 explicit_bzero(o, sizeof(*o));

}

struct fwdarg {
 char *arg;
 int ispath;
};
static int
parse_fwd_field(char **p, struct fwdarg *fwd)
{
 char *ep, *cp = *p;
 int ispath = 0;

 if (*cp == '\0') {
  *p = 
      ((void *)0)
          ;
  return -1;
 }





 if (*cp == '[') {

  for (ep = cp + 1; *ep != ']' && *ep != '\0'; ep++) {
   if (*ep == '/')
    ispath = 1;
  }

  if (ep[0] != ']' || (ep[1] != ':' && ep[1] != '\0'))
   return -1;

  *ep++ = '\0';
  if (*ep != '\0')
   *ep++ = '\0';
  fwd->arg = cp + 1;
  fwd->ispath = ispath;
  *p = ep;
  return 0;
 }

 for (cp = *p; *cp != '\0'; cp++) {
  switch (*cp) {
  case '\\':
   memmove(cp, cp + 1, strlen(cp + 1) + 1);
   if (*cp == '\0')
    return -1;
   break;
  case '/':
   ispath = 1;
   break;
  case ':':
   *cp++ = '\0';
   goto done;
  }
 }
done:
 fwd->arg = *p;
 fwd->ispath = ispath;
 *p = cp;
 return 0;
}
int
parse_forward(struct Forward *fwd, const char *fwdspec, int dynamicfwd, int remotefwd)
{
 struct fwdarg fwdargs[4];
 char *p, *cp;
 int i, err;

 memset(fwd, 0, sizeof(*fwd));
 memset(fwdargs, 0, sizeof(fwdargs));






 cp = p = dollar_expand(&err, fwdspec);
 if (p == 
         ((void *)0) 
              || err)
  return 0;


 while (
       ((*__ctype_b_loc ())[(int) ((
       (u_char)*cp
       ))] & (unsigned short int) _ISspace)
                           )
  cp++;

 for (i = 0; i < 4; ++i) {
  if (parse_fwd_field(&cp, &fwdargs[i]) != 0)
   break;
 }


 if (cp != 
          ((void *)0) 
               && *cp != '\0') {
  i = 0;
 }

 switch (i) {
 case 1:
  if (fwdargs[0].ispath) {
   fwd->listen_path = xstrdup(fwdargs[0].arg);
   fwd->listen_port = -2;
  } else {
   fwd->listen_host = 
                     ((void *)0)
                         ;
   fwd->listen_port = a2port(fwdargs[0].arg);
  }
  fwd->connect_host = xstrdup("socks");
  break;

 case 2:
  if (fwdargs[0].ispath && fwdargs[1].ispath) {
   fwd->listen_path = xstrdup(fwdargs[0].arg);
   fwd->listen_port = -2;
   fwd->connect_path = xstrdup(fwdargs[1].arg);
   fwd->connect_port = -2;
  } else if (fwdargs[1].ispath) {
   fwd->listen_host = 
                     ((void *)0)
                         ;
   fwd->listen_port = a2port(fwdargs[0].arg);
   fwd->connect_path = xstrdup(fwdargs[1].arg);
   fwd->connect_port = -2;
  } else {
   fwd->listen_host = xstrdup(fwdargs[0].arg);
   fwd->listen_port = a2port(fwdargs[1].arg);
   fwd->connect_host = xstrdup("socks");
  }
  break;

 case 3:
  if (fwdargs[0].ispath) {
   fwd->listen_path = xstrdup(fwdargs[0].arg);
   fwd->listen_port = -2;
   fwd->connect_host = xstrdup(fwdargs[1].arg);
   fwd->connect_port = a2port(fwdargs[2].arg);
  } else if (fwdargs[2].ispath) {
   fwd->listen_host = xstrdup(fwdargs[0].arg);
   fwd->listen_port = a2port(fwdargs[1].arg);
   fwd->connect_path = xstrdup(fwdargs[2].arg);
   fwd->connect_port = -2;
  } else {
   fwd->listen_host = 
                     ((void *)0)
                         ;
   fwd->listen_port = a2port(fwdargs[0].arg);
   fwd->connect_host = xstrdup(fwdargs[1].arg);
   fwd->connect_port = a2port(fwdargs[2].arg);
  }
  break;

 case 4:
  fwd->listen_host = xstrdup(fwdargs[0].arg);
  fwd->listen_port = a2port(fwdargs[1].arg);
  fwd->connect_host = xstrdup(fwdargs[2].arg);
  fwd->connect_port = a2port(fwdargs[3].arg);
  break;
 default:
  i = 0;
 }

 free(p);

 if (dynamicfwd) {
  if (!(i == 1 || i == 2))
   goto fail_free;
 } else {
  if (!(i == 3 || i == 4)) {
   if (fwd->connect_path == 
                           ((void *)0) 
                                &&
       fwd->listen_path == 
                          ((void *)0)
                              )
    goto fail_free;
  }
  if (fwd->connect_port <= 0 && fwd->connect_path == 
                                                    ((void *)0)
                                                        )
   goto fail_free;
 }

 if ((fwd->listen_port < 0 && fwd->listen_path == 
                                                 ((void *)0)
                                                     ) ||
     (!remotefwd && fwd->listen_port == 0))
  goto fail_free;
 if (fwd->connect_host != 
                         ((void *)0) 
                              &&
     strlen(fwd->connect_host) >= 
                                 1025
                                           )
  goto fail_free;




 if (fwd->connect_path != 
                         ((void *)0) 
                              &&
     strlen(fwd->connect_path) >= (sizeof((struct sockaddr_un *)0)->sun_path))
  goto fail_free;
 if (fwd->listen_host != 
                        ((void *)0) 
                             &&
     strlen(fwd->listen_host) >= 
                                1025
                                          )
  goto fail_free;
 if (fwd->listen_path != 
                        ((void *)0) 
                             &&
     strlen(fwd->listen_path) >= (sizeof((struct sockaddr_un *)0)->sun_path))
  goto fail_free;

 return (i);

 fail_free:
 free(fwd->connect_host);
 fwd->connect_host = 
                    ((void *)0)
                        ;
 free(fwd->connect_path);
 fwd->connect_path = 
                    ((void *)0)
                        ;
 free(fwd->listen_host);
 fwd->listen_host = 
                   ((void *)0)
                       ;
 free(fwd->listen_path);
 fwd->listen_path = 
                   ((void *)0)
                       ;
 return (0);
}

int
parse_jump(const char *s, Options *o, int active)
{
 char *orig, *sdup, *cp;
 char *host = 
             ((void *)0)
                 , *user = 
                           ((void *)0)
                               ;
 int r, ret = -1, port = -1, first;

 active &= o->proxy_command == 
                              ((void *)0) 
                                   && o->jump_host == 
                                                      ((void *)0)
                                                          ;

 orig = sdup = xstrdup(s);


 if ((cp = strchr(orig, '#')) != 
                                ((void *)0)
                                    )
  *cp = '\0';
 rtrim(orig);

 first = active;
 do {
  if (strcasecmp(s, "none") == 0)
   break;
  if ((cp = strrchr(sdup, ',')) == 
                                  ((void *)0)
                                      )
   cp = sdup;
  else
   *cp++ = '\0';

  if (first) {

   r = parse_ssh_uri(cp, &user, &host, &port);
   if (r == -1 || (r == 1 &&
       parse_user_host_port(cp, &user, &host, &port) != 0))
    goto out;
  } else {

   r = parse_ssh_uri(cp, 
                        ((void *)0)
                            , 
                              ((void *)0)
                                  , 
                                    ((void *)0)
                                        );
   if (r == -1 || (r == 1 &&
       parse_user_host_port(cp, 
                               ((void *)0)
                                   , 
                                     ((void *)0)
                                         , 
                                           ((void *)0)
                                               ) != 0))
    goto out;
  }
  first = 0;
 } while (cp != sdup);

 if (active) {
  if (strcasecmp(s, "none") == 0) {
   o->jump_host = xstrdup("none");
   o->jump_port = 0;
  } else {
   o->jump_user = user;
   o->jump_host = host;
   o->jump_port = port;
   o->proxy_command = xstrdup("none");
   user = host = 
                ((void *)0)
                    ;
   if ((cp = strrchr(s, ',')) != 
                                ((void *)0) 
                                     && cp != s) {
    o->jump_extra = xstrdup(s);
    o->jump_extra[cp - s] = '\0';
   }
  }
 }
 ret = 0;
 out:
 free(orig);
 free(user);
 free(host);
 return ret;
}

int
parse_ssh_uri(const char *uri, char **userp, char **hostp, int *portp)
{
 char *user = 
             ((void *)0)
                 , *host = 
                           ((void *)0)
                               , *path = 
                                         ((void *)0)
                                             ;
 int r, port;

 r = parse_uri("ssh", uri, &user, &host, &port, &path);
 if (r == 0 && path != 
                      ((void *)0)
                          )
  r = -1;
 if (r == 0) {
  if (userp != 
              ((void *)0)
                  ) {
   *userp = user;
   user = 
         ((void *)0)
             ;
  }
  if (hostp != 
              ((void *)0)
                  ) {
   *hostp = host;
   host = 
         ((void *)0)
             ;
  }
  if (portp != 
              ((void *)0)
                  )
   *portp = port;
 }
 free(user);
 free(host);
 free(path);
 return r;
}


static const char *
fmt_multistate_int(int val, const struct multistate *m)
{
 u_int i;

 for (i = 0; m[i].key != 
                        ((void *)0)
                            ; i++) {
  if (m[i].value == val)
   return m[i].key;
 }
 return "UNKNOWN";
}

static const char *
fmt_intarg(OpCodes code, int val)
{
 if (val == -1)
  return "unset";
 switch (code) {
 case oAddressFamily:
  return fmt_multistate_int(val, multistate_addressfamily);
 case oVerifyHostKeyDNS:
 case oUpdateHostkeys:
  return fmt_multistate_int(val, multistate_yesnoask);
 case oStrictHostKeyChecking:
  return fmt_multistate_int(val, multistate_strict_hostkey);
 case oControlMaster:
  return fmt_multistate_int(val, multistate_controlmaster);
 case oTunnel:
  return fmt_multistate_int(val, multistate_tunnel);
 case oRequestTTY:
  return fmt_multistate_int(val, multistate_requesttty);
 case oSessionType:
  return fmt_multistate_int(val, multistate_sessiontype);
 case oCanonicalizeHostname:
  return fmt_multistate_int(val, multistate_canonicalizehostname);
 case oAddKeysToAgent:
  return fmt_multistate_int(val, multistate_yesnoaskconfirm);
 case oPubkeyAuthentication:
  return fmt_multistate_int(val, multistate_pubkey_auth);
 case oFingerprintHash:
  return ssh_digest_alg_name(val);
 default:
  switch (val) {
  case 0:
   return "no";
  case 1:
   return "yes";
  default:
   return "UNKNOWN";
  }
 }
}

static const char *
lookup_opcode_name(OpCodes code)
{
 u_int i;

 for (i = 0; keywords[i].name != 
                                ((void *)0)
                                    ; i++)
  if (keywords[i].opcode == code)
   return(keywords[i].name);
 return "UNKNOWN";
}

static void
dump_cfg_int(OpCodes code, int val)
{
 printf("%s %d\n", lookup_opcode_name(code), val);
}

static void
dump_cfg_fmtint(OpCodes code, int val)
{
 printf("%s %s\n", lookup_opcode_name(code), fmt_intarg(code, val));
}

static void
dump_cfg_string(OpCodes code, const char *val)
{
 if (val == 
           ((void *)0)
               )
  return;
 printf("%s %s\n", lookup_opcode_name(code), val);
}

static void
dump_cfg_strarray(OpCodes code, u_int count, char **vals)
{
 u_int i;

 for (i = 0; i < count; i++)
  printf("%s %s\n", lookup_opcode_name(code), vals[i]);
}

static void
dump_cfg_strarray_oneline(OpCodes code, u_int count, char **vals)
{
 u_int i;

 printf("%s", lookup_opcode_name(code));
 if (count == 0)
  printf(" none");
 for (i = 0; i < count; i++)
  printf(" %s", vals[i]);
 printf("\n");
}

static void
dump_cfg_forwards(OpCodes code, u_int count, const struct Forward *fwds)
{
 const struct Forward *fwd;
 u_int i;


 for (i = 0; i < count; i++) {
  fwd = &fwds[i];
  if (code == oDynamicForward && fwd->connect_host != 
                                                     ((void *)0) 
                                                          &&
      strcmp(fwd->connect_host, "socks") != 0)
   continue;
  if (code == oLocalForward && fwd->connect_host != 
                                                   ((void *)0) 
                                                        &&
      strcmp(fwd->connect_host, "socks") == 0)
   continue;
  printf("%s", lookup_opcode_name(code));
  if (fwd->listen_port == -2)
   printf(" %s", fwd->listen_path);
  else if (fwd->listen_host == 
                              ((void *)0)
                                  )
   printf(" %d", fwd->listen_port);
  else {
   printf(" [%s]:%d",
       fwd->listen_host, fwd->listen_port);
  }
  if (code != oDynamicForward) {
   if (fwd->connect_port == -2)
    printf(" %s", fwd->connect_path);
   else if (fwd->connect_host == 
                                ((void *)0)
                                    )
    printf(" %d", fwd->connect_port);
   else {
    printf(" [%s]:%d",
        fwd->connect_host, fwd->connect_port);
   }
  }
  printf("\n");
 }
}

void
dump_client_config(Options *o, const char *host)
{
 int i, r;
 char buf[8], *all_key;







 all_key = sshkey_alg_list(0, 0, 1, ',');
 if ((r = kex_assemble_names(&o->hostkeyalgorithms, kex_default_pk_alg(),
     all_key)) != 0)
  sshfatal("readconf.c", __func__, 3264, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "expand HostKeyAlgorithms");
 free(all_key);


 dump_cfg_string(oUser, o->user);
 dump_cfg_string(oHostname, host);
 dump_cfg_int(oPort, o->port);


 dump_cfg_fmtint(oAddressFamily, o->address_family);
 dump_cfg_fmtint(oBatchMode, o->batch_mode);
 dump_cfg_fmtint(oCanonicalizeFallbackLocal, o->canonicalize_fallback_local);
 dump_cfg_fmtint(oCanonicalizeHostname, o->canonicalize_hostname);
 dump_cfg_fmtint(oCheckHostIP, o->check_host_ip);
 dump_cfg_fmtint(oCompression, o->compression);
 dump_cfg_fmtint(oControlMaster, o->control_master);
 dump_cfg_fmtint(oEnableSSHKeysign, o->enable_ssh_keysign);
 dump_cfg_fmtint(oClearAllForwardings, o->clear_forwardings);
 dump_cfg_fmtint(oExitOnForwardFailure, o->exit_on_forward_failure);
 dump_cfg_fmtint(oFingerprintHash, o->fingerprint_hash);
 dump_cfg_fmtint(oForwardX11, o->forward_x11);
 dump_cfg_fmtint(oForwardX11Trusted, o->forward_x11_trusted);
 dump_cfg_fmtint(oGatewayPorts, o->fwd_opts.gateway_ports);




 dump_cfg_fmtint(oHashKnownHosts, o->hash_known_hosts);
 dump_cfg_fmtint(oHostbasedAuthentication, o->hostbased_authentication);
 dump_cfg_fmtint(oIdentitiesOnly, o->identities_only);
 dump_cfg_fmtint(oKbdInteractiveAuthentication, o->kbd_interactive_authentication);
 dump_cfg_fmtint(oNoHostAuthenticationForLocalhost, o->no_host_authentication_for_localhost);
 dump_cfg_fmtint(oPasswordAuthentication, o->password_authentication);
 dump_cfg_fmtint(oPermitLocalCommand, o->permit_local_command);
 dump_cfg_fmtint(oProxyUseFdpass, o->proxy_use_fdpass);
 dump_cfg_fmtint(oPubkeyAuthentication, o->pubkey_authentication);
 dump_cfg_fmtint(oRequestTTY, o->request_tty);
 dump_cfg_fmtint(oSessionType, o->session_type);
 dump_cfg_fmtint(oStdinNull, o->stdin_null);
 dump_cfg_fmtint(oForkAfterAuthentication, o->fork_after_authentication);
 dump_cfg_fmtint(oStreamLocalBindUnlink, o->fwd_opts.streamlocal_bind_unlink);
 dump_cfg_fmtint(oStrictHostKeyChecking, o->strict_host_key_checking);
 dump_cfg_fmtint(oTCPKeepAlive, o->tcp_keep_alive);
 dump_cfg_fmtint(oTunnel, o->tun_open);
 dump_cfg_fmtint(oVerifyHostKeyDNS, o->verify_host_key_dns);
 dump_cfg_fmtint(oVisualHostKey, o->visual_host_key);
 dump_cfg_fmtint(oUpdateHostkeys, o->update_hostkeys);


 dump_cfg_int(oCanonicalizeMaxDots, o->canonicalize_max_dots);
 dump_cfg_int(oConnectionAttempts, o->connection_attempts);
 dump_cfg_int(oForwardX11Timeout, o->forward_x11_timeout);
 dump_cfg_int(oNumberOfPasswordPrompts, o->number_of_password_prompts);
 dump_cfg_int(oServerAliveCountMax, o->server_alive_count_max);
 dump_cfg_int(oServerAliveInterval, o->server_alive_interval);
 dump_cfg_int(oRequiredRSASize, o->required_rsa_size);


 dump_cfg_string(oBindAddress, o->bind_address);
 dump_cfg_string(oBindInterface, o->bind_interface);
 dump_cfg_string(oCiphers, o->ciphers);
 dump_cfg_string(oControlPath, o->control_path);
 dump_cfg_string(oHostKeyAlgorithms, o->hostkeyalgorithms);
 dump_cfg_string(oHostKeyAlias, o->host_key_alias);
 dump_cfg_string(oHostbasedAcceptedAlgorithms, o->hostbased_accepted_algos);
 dump_cfg_string(oIdentityAgent, o->identity_agent);
 dump_cfg_string(oIgnoreUnknown, o->ignored_unknown);
 dump_cfg_string(oKbdInteractiveDevices, o->kbd_interactive_devices);
 dump_cfg_string(oKexAlgorithms, o->kex_algorithms);
 dump_cfg_string(oCASignatureAlgorithms, o->ca_sign_algorithms);
 dump_cfg_string(oLocalCommand, o->local_command);
 dump_cfg_string(oRemoteCommand, o->remote_command);
 dump_cfg_string(oLogLevel, log_level_name(o->log_level));
 dump_cfg_string(oMacs, o->macs);

 dump_cfg_string(oPKCS11Provider, o->pkcs11_provider);

 dump_cfg_string(oSecurityKeyProvider, o->sk_provider);
 dump_cfg_string(oPreferredAuthentications, o->preferred_authentications);
 dump_cfg_string(oPubkeyAcceptedAlgorithms, o->pubkey_accepted_algos);
 dump_cfg_string(oRevokedHostKeys, o->revoked_host_keys);
 dump_cfg_string(oXAuthLocation, o->xauth_location);
 dump_cfg_string(oKnownHostsCommand, o->known_hosts_command);


 dump_cfg_forwards(oDynamicForward, o->num_local_forwards, o->local_forwards);
 dump_cfg_forwards(oLocalForward, o->num_local_forwards, o->local_forwards);
 dump_cfg_forwards(oRemoteForward, o->num_remote_forwards, o->remote_forwards);


 dump_cfg_strarray(oIdentityFile, o->num_identity_files, o->identity_files);
 dump_cfg_strarray_oneline(oCanonicalDomains, o->num_canonical_domains, o->canonical_domains);
 dump_cfg_strarray(oCertificateFile, o->num_certificate_files, o->certificate_files);
 dump_cfg_strarray_oneline(oGlobalKnownHostsFile, o->num_system_hostfiles, o->system_hostfiles);
 dump_cfg_strarray_oneline(oUserKnownHostsFile, o->num_user_hostfiles, o->user_hostfiles);
 dump_cfg_strarray(oSendEnv, o->num_send_env, o->send_env);
 dump_cfg_strarray(oSetEnv, o->num_setenv, o->setenv);
 dump_cfg_strarray_oneline(oLogVerbose,
     o->num_log_verbose, o->log_verbose);




 if (o->num_permitted_remote_opens == 0)
  printf("%s any\n", lookup_opcode_name(oPermitRemoteOpen));
 else
  dump_cfg_strarray_oneline(oPermitRemoteOpen,
      o->num_permitted_remote_opens, o->permitted_remote_opens);


 if (o->add_keys_to_agent_lifespan <= 0)
  dump_cfg_fmtint(oAddKeysToAgent, o->add_keys_to_agent);
 else {
  printf("addkeystoagent%s %d\n",
      o->add_keys_to_agent == 3 ? " confirm" : "",
      o->add_keys_to_agent_lifespan);
 }


 if (o->forward_agent_sock_path == 
                                  ((void *)0)
                                      )
  dump_cfg_fmtint(oForwardAgent, o->forward_agent);
 else
  dump_cfg_string(oForwardAgent, o->forward_agent_sock_path);


 if (o->connection_timeout == -1)
  printf("connecttimeout none\n");
 else
  dump_cfg_int(oConnectTimeout, o->connection_timeout);


 printf("tunneldevice");
 if (o->tun_local == 0x7fffffff)
  printf(" any");
 else
  printf(" %d", o->tun_local);
 if (o->tun_remote == 0x7fffffff)
  printf(":any");
 else
  printf(":%d", o->tun_remote);
 printf("\n");


 printf("canonicalizePermittedcnames");
 if (o->num_permitted_cnames == 0)
  printf(" none");
 for (i = 0; i < o->num_permitted_cnames; i++) {
  printf(" %s:%s", o->permitted_cnames[i].source_list,
      o->permitted_cnames[i].target_list);
 }
 printf("\n");


 if (o->control_persist == 0 || o->control_persist_timeout == 0)
  dump_cfg_fmtint(oControlPersist, o->control_persist);
 else
  dump_cfg_int(oControlPersist, o->control_persist_timeout);


 if (o->escape_char == -2)
  printf("escapechar none\n");
 else {
  vis(buf, o->escape_char, (0x04 | 0x08 | 0x10), 0);
  printf("escapechar %s\n", buf);
 }


 printf("ipqos %s ", iptos2str(o->ip_qos_interactive));
 printf("%s\n", iptos2str(o->ip_qos_bulk));


 printf("rekeylimit %llu %d\n",
     (unsigned long long)o->rekey_limit, o->rekey_interval);


 printf("streamlocalbindmask 0%o\n",
     o->fwd_opts.streamlocal_bind_mask);


 printf("syslogfacility %s\n", log_facility_name(o->log_facility));


 if (o->jump_host == 
                    ((void *)0)
                        )
  dump_cfg_string(oProxyCommand, o->proxy_command);
 else {

  i = strchr(o->jump_host, ':') != 
                                  ((void *)0) 
                                       ||
      strspn(o->jump_host, "1234567890.") == strlen(o->jump_host);
  snprintf(buf, sizeof(buf), "%d", o->jump_port);
  printf("proxyjump %s%s%s%s%s%s%s%s%s\n",

      o->jump_extra == 
                      ((void *)0) 
                           ? "" : o->jump_extra,
      o->jump_extra == 
                      ((void *)0) 
                           ? "" : ",",

      o->jump_user == 
                     ((void *)0) 
                          ? "" : o->jump_user,
      o->jump_user == 
                     ((void *)0) 
                          ? "" : "@",

      i ? "[" : "",

      o->jump_host,

      i ? "]" : "",

      o->jump_port <= 0 ? "" : ":",
      o->jump_port <= 0 ? "" : buf);
 }
}
