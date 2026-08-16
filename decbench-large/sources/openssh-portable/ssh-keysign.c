











































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















int ssh_compatible_openssl(long, long);
void ssh_libcrypto_init(void);
int EVP_CIPHER_CTX_set_iv(EVP_CIPHER_CTX *ctx,
    const unsigned char *iv, size_t len);
void DSA_SIG_get0(const DSA_SIG *sig, const BIGNUM **pr, const BIGNUM **ps);



int DSA_SIG_set0(DSA_SIG *sig, BIGNUM *r, BIGNUM *s);
EVP_MD_CTX *EVP_MD_CTX_new(void);



void EVP_MD_CTX_free(EVP_MD_CTX *ctx);


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
struct sshbuf;
struct sshkey;




int sshkey_save_private(struct sshkey *, const char *,
    const char *, const char *, int, const char *, int);
int sshkey_load_cert(const char *, struct sshkey **);
int sshkey_load_public(const char *, struct sshkey **, char **);
int sshkey_load_private(const char *, const char *, struct sshkey **, char **);
int sshkey_load_private_cert(int, const char *, const char *,
    struct sshkey **);
int sshkey_load_private_type(int, const char *, const char *,
    struct sshkey **, char **);
int sshkey_load_private_type_fd(int fd, int type, const char *passphrase,
    struct sshkey **keyp, char **commentp);
int sshkey_perm_ok(int, const char *);
int sshkey_in_file(struct sshkey *, const char *, int, int);
int sshkey_check_revoked(struct sshkey *key, const char *revoked_keys_file);
int sshkey_advance_past_options(char **cpp);
int sshkey_save_public(const struct sshkey *key, const char *path,
    const char *comment);
struct sshbuf;
int ssh_msg_send(int, u_char, struct sshbuf *);
int ssh_msg_recv(int, struct sshbuf *);
char *get_peer_ipaddr(int);
int get_peer_port(int);
char *get_local_ipaddr(int);
char *get_local_name(int);
int get_local_port(int);



void ipv64_normalise_mapped(struct sockaddr_storage *, socklen_t *);
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
void temporarily_use_uid(struct passwd *);
void restore_uid(void);
void permanently_set_uid(struct passwd *);


extern char *__progname;

static int
valid_request(struct passwd *pw, char *host, struct sshkey **ret, char **pkalgp,
    u_char *data, size_t datalen)
{
 struct sshbuf *b;
 struct sshkey *key = 
                     ((void *)0)
                         ;
 u_char type, *pkblob;
 char *p;
 size_t blen, len;
 char *pkalg, *luser;
 int r, pktype, fail;

 if (ret != 
           ((void *)0)
               )
  *ret = 
        ((void *)0)
            ;
 if (pkalgp != 
              ((void *)0)
                  )
  *pkalgp = 
           ((void *)0)
               ;
 fail = 0;

 if ((b = sshbuf_from(data, datalen)) == 
                                        ((void *)0)
                                            )
  sshfatal("ssh-keysign.c", __func__, 83, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_from failed");


 if ((r = sshbuf_get_string(b, 
                              ((void *)0)
                                  , &len)) != 0)
  sshfatal("ssh-keysign.c", __func__, 87, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse session ID");
 if (len != 20 &&
     len != 32 &&
     len != 48 &&
     len != 64)
  fail++;

 if ((r = sshbuf_get_u8(b, &type)) != 0)
  sshfatal("ssh-keysign.c", __func__, 95, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse type");
 if (type != 50)
  fail++;


 if ((r = sshbuf_get_string_direct(b, 
         ((void *)0)
         , 
         ((void *)0)
         )) != 0)
  sshfatal("ssh-keysign.c", __func__, 101, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse user");


 if ((r = sshbuf_get_cstring(b, &p, 
                                   ((void *)0)
                                       )) != 0)
  sshfatal("ssh-keysign.c", __func__, 105, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse service");
 if (strcmp("ssh-connection", p) != 0)
  fail++;
 free(p);


 if ((r = sshbuf_get_cstring(b, &p, 
                                   ((void *)0)
                                       )) != 0)
  sshfatal("ssh-keysign.c", __func__, 112, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse method");
 if (strcmp("hostbased", p) != 0)
  fail++;
 free(p);


 if ((r = sshbuf_get_cstring(b, &pkalg, 
                                       ((void *)0)
                                           )) != 0 ||
     (r = sshbuf_get_string(b, &pkblob, &blen)) != 0)
  sshfatal("ssh-keysign.c", __func__, 120, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse pk");

 pktype = sshkey_type_from_name(pkalg);
 if (pktype == KEY_UNSPEC)
  fail++;
 else if ((r = sshkey_from_blob(pkblob, blen, &key)) != 0) {
  sshlog("ssh-keysign.c", __func__, 126, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "decode key");
  fail++;
 } else if (key->type != pktype)
  fail++;


 if ((r = sshbuf_get_cstring(b, &p, &len)) != 0)
  sshfatal("ssh-keysign.c", __func__, 133, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse hostname");
 sshlog("ssh-keysign.c", __func__, 134, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "check expect chost %s got %s", host, p);
 if (strlen(host) != len - 1)
  fail++;
 else if (p[len - 1] != '.')
  fail++;
 else if (strncasecmp(host, p, len - 1) != 0)
  fail++;
 free(p);


 if ((r = sshbuf_get_cstring(b, &luser, 
                                       ((void *)0)
                                           )) != 0)
  sshfatal("ssh-keysign.c", __func__, 145, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse luser");

 if (strcmp(pw->pw_name, luser) != 0)
  fail++;
 free(luser);


 if (sshbuf_len(b) != 0)
  fail++;
 sshbuf_free(b);

 sshlog("ssh-keysign.c", __func__, 156, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "fail %d", fail);

 if (!fail) {
  if (ret != 
            ((void *)0)
                ) {
   *ret = key;
   key = 
        ((void *)0)
            ;
  }
  if (pkalgp != 
               ((void *)0)
                   ) {
   *pkalgp = pkalg;
   pkalg = 
          ((void *)0)
              ;
  }
 }
 sshkey_free(key);
 free(pkalg);
 free(pkblob);

 return (fail ? -1 : 0);
}

int
main(int argc, char **argv)
{
 struct sshbuf *b;
 Options options;

 struct sshkey *keys[5], *key = 
                                          ((void *)0)
                                              ;
 struct passwd *pw;
 int r, key_fd[5], i, found, version = 2, fd;
 u_char *signature, *data, rver;
 char *host, *fp, *pkalg;
 size_t slen, dlen;

 if (pledge("stdio rpath getpw dns id", 
                                       ((void *)0)
                                           ) != 0)
  sshfatal("ssh-keysign.c", __func__, 189, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: pledge: %s", __progname, strerror(
 (*__errno_location ())
 ));


 if ((fd = open(
               "/dev/null"
                            , 
                              02
                                    )) < 2)
  exit(1);

 if (fd > 2)
  close(fd);

 i = 0;

 key_fd[i++] = open("/usr/local/etc" "/ssh_host_dsa_key", 
                                            00
                                                    );
 key_fd[i++] = open("/usr/local/etc" "/ssh_host_ecdsa_key", 
                                              00
                                                      );
 key_fd[i++] = open("/usr/local/etc" "/ssh_host_ed25519_key", 
                                                00
                                                        );
 key_fd[i++] = open("/usr/local/etc" "/ssh_host_xmss_key", 
                                             00
                                                     );
 key_fd[i++] = open("/usr/local/etc" "/ssh_host_rsa_key", 
                                            00
                                                    );

 if ((pw = getpwuid(getuid())) == 
                                 ((void *)0)
                                     )
  sshfatal("ssh-keysign.c", __func__, 207, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "getpwuid failed");
 pw = pwcopy(pw);

 permanently_set_uid(pw);

 seed_rng();






 initialize_options(&options);
 (void)read_config_file("/usr/local/etc" "/ssh_config", pw, "", "",
     &options, 0, 
                 ((void *)0)
                     );
 (void)fill_default_options(&options);
 if (options.enable_ssh_keysign != 1)
  sshfatal("ssh-keysign.c", __func__, 224, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ssh-keysign not enabled in %s", "/usr/local/etc" "/ssh_config")
                             ;

 if (pledge("stdio dns", 
                        ((void *)0)
                            ) != 0)
  sshfatal("ssh-keysign.c", __func__, 228, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: pledge: %s", __progname, strerror(
 (*__errno_location ())
 ));

 for (i = found = 0; i < 5; i++) {
  if (key_fd[i] != -1)
   found = 1;
 }
 if (found == 0)
  sshfatal("ssh-keysign.c", __func__, 235, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "could not open any host key");

 found = 0;
 for (i = 0; i < 5; i++) {
  keys[i] = 
           ((void *)0)
               ;
  if (key_fd[i] == -1)
   continue;
  r = sshkey_load_private_type_fd(key_fd[i], KEY_UNSPEC,
      
     ((void *)0)
         , &key, 
                 ((void *)0)
                     );
  close(key_fd[i]);
  if (r != 0)
   sshlog("ssh-keysign.c", __func__, 246, 0, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "parse key %d", i);
  else if (key != 
                 ((void *)0)
                     ) {
   keys[i] = key;
   found = 1;
  }
 }
 if (!found)
  sshfatal("ssh-keysign.c", __func__, 253, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "no hostkey found");

 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("ssh-keysign.c", __func__, 256, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: sshbuf_new failed", __progname);
 if (ssh_msg_recv(
                 0
                             , b) < 0)
  sshfatal("ssh-keysign.c", __func__, 258, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: ssh_msg_recv failed", __progname);
 if ((r = sshbuf_get_u8(b, &rver)) != 0)
  sshfatal("ssh-keysign.c", __func__, 260, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s: buffer error", __progname);
 if (rver != version)
  sshfatal("ssh-keysign.c", __func__, 262, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: bad version: received %d, expected %d", __progname, rver, version)
                                ;
 if ((r = sshbuf_get_u32(b, (u_int *)&fd)) != 0)
  sshfatal("ssh-keysign.c", __func__, 265, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s: buffer error", __progname);
 if (fd < 0 || fd == 
                    0 
                                 || fd == 
                                          1
                                                       )
  sshfatal("ssh-keysign.c", __func__, 267, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: bad fd = %d", __progname, fd);
 if ((host = get_local_name(fd)) == 
                                   ((void *)0)
                                       )
  sshfatal("ssh-keysign.c", __func__, 269, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: cannot get local name for fd", __progname);

 if ((r = sshbuf_get_string(b, &data, &dlen)) != 0)
  sshfatal("ssh-keysign.c", __func__, 272, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s: buffer error", __progname);
 if (valid_request(pw, host, &key, &pkalg, data, dlen) < 0)
  sshfatal("ssh-keysign.c", __func__, 274, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: not a valid request", __progname);
 free(host);

 found = 0;
 for (i = 0; i < 5; i++) {
  if (keys[i] != 
                ((void *)0) 
                     &&
      sshkey_equal_public(key, keys[i])) {
   found = 1;
   break;
  }
 }
 if (!found) {
  if ((fp = sshkey_fingerprint(key, options.fingerprint_hash,
      SSH_FP_DEFAULT)) == 
                         ((void *)0)
                             )
   sshfatal("ssh-keysign.c", __func__, 288, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s: sshkey_fingerprint failed", __progname);
  sshfatal("ssh-keysign.c", __func__, 289, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: no matching hostkey found for key %s %s", __progname, sshkey_type(key), fp ? fp : "")
                                     ;
 }

 if ((r = sshkey_sign(keys[i], &signature, &slen, data, dlen,
     pkalg, 
           ((void *)0)
               , 
                 ((void *)0)
                     , 0)) != 0)
  sshfatal("ssh-keysign.c", __func__, 295, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s: sshkey_sign failed", __progname);
 free(data);


 sshbuf_reset(b);
 if ((r = sshbuf_put_string(b, signature, slen)) != 0)
  sshfatal("ssh-keysign.c", __func__, 301, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s: buffer error", __progname);
 if (ssh_msg_send(
                 1
                              , version, b) == -1)
  sshfatal("ssh-keysign.c", __func__, 303, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: ssh_msg_send failed", __progname);

 return (0);
}
