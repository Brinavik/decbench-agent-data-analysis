











































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
struct sshbuf;
struct sshkey;


struct ssh_identitylist {
 size_t nkeys;
 struct sshkey **keys;
 char **comments;
};


struct dest_constraint_hop {
 char *user;
 char *hostname;
 int is_ca;
 u_int nkeys;
 struct sshkey **keys;
 int *key_is_ca;
};
struct dest_constraint {
 struct dest_constraint_hop from;
 struct dest_constraint_hop to;
};

int ssh_get_authentication_socket(int *fdp);
int ssh_get_authentication_socket_path(const char *authsocket, int *fdp);
void ssh_close_authentication_socket(int sock);

int ssh_lock_agent(int sock, int lock, const char *password);
int ssh_fetch_identitylist(int sock, struct ssh_identitylist **idlp);
void ssh_free_identitylist(struct ssh_identitylist *idl);
int ssh_add_identity_constrained(int sock, struct sshkey *key,
    const char *comment, u_int life, u_int confirm, u_int maxsign,
    const char *provider, struct dest_constraint **dest_constraints,
    size_t ndest_constraints);
int ssh_agent_has_key(int sock, const struct sshkey *key);
int ssh_remove_identity(int sock, const struct sshkey *key);
int ssh_update_card(int sock, int add, const char *reader_id,
     const char *pin, u_int life, u_int confirm,
     struct dest_constraint **dest_constraints,
     size_t ndest_constraints);
int ssh_remove_all_identities(int sock, int version);

int ssh_agent_sign(int sock, const struct sshkey *key,
     u_char **sigp, size_t *lenp,
     const u_char *data, size_t datalen, const char *alg, u_int compat);

int ssh_agent_bind_hostkey(int sock, const struct sshkey *key,
    const struct sshbuf *session_id, const struct sshbuf *signature,
    int forwarding);
struct iovec;




size_t
atomicio6(ssize_t (*f) (int, void *, size_t), int fd, void *_s, size_t n,
    int (*cb)(void *, size_t), void *);
size_t atomicio(ssize_t (*)(int, void *, size_t), int, void *, size_t);






size_t
atomiciov6(ssize_t (*f) (int, const struct iovec *, int), int fd,
    const struct iovec *_iov, int iovcnt, int (*cb)(void *, size_t), void *);
size_t atomiciov(ssize_t (*)(int, const struct iovec *, int),
    int, const struct iovec *, int);
int pkcs11_init(int);
void pkcs11_terminate(void);
int pkcs11_add_provider(char *, char *, struct sshkey ***, char ***);
int pkcs11_del_provider(char *);




static int fd = -1;
static pid_t pid = -1;

static void
send_msg(struct sshbuf *m)
{
 u_char buf[4];
 size_t mlen = sshbuf_len(m);
 int r;

 do { const u_int32_t __v = (mlen); ((u_char *)(buf))[0] = (__v >> 24) & 0xff; ((u_char *)(buf))[1] = (__v >> 16) & 0xff; ((u_char *)(buf))[2] = (__v >> 8) & 0xff; ((u_char *)(buf))[3] = __v & 0xff; } while (0);
 if (atomicio((ssize_t (*)(int, void *, size_t))write, fd, buf, 4) != 4 ||
     atomicio((ssize_t (*)(int, void *, size_t))write, fd, sshbuf_mutable_ptr(m),
     sshbuf_len(m)) != sshbuf_len(m))
  sshlog("ssh-pkcs11-client.c", __func__, 66, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "write to helper failed");
 if ((r = sshbuf_consume(m, mlen)) != 0)
  sshfatal("ssh-pkcs11-client.c", __func__, 68, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "consume");
}

static int
recv_msg(struct sshbuf *m)
{
 u_int l, len;
 u_char c, buf[1024];
 int r;

 if ((len = atomicio(read, fd, buf, 4)) != 4) {
  sshlog("ssh-pkcs11-client.c", __func__, 79, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "read from helper failed: %u", len);
  return (0);
 }
 len = (((u_int32_t)(((const u_char *)(buf))[0]) << 24) | ((u_int32_t)(((const u_char *)(buf))[1]) << 16) | ((u_int32_t)(((const u_char *)(buf))[2]) << 8) | (u_int32_t)(((const u_char *)(buf))[3]));
 if (len > 256 * 1024)
  sshfatal("ssh-pkcs11-client.c", __func__, 84, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "response too long: %u", len);

 sshbuf_reset(m);
 while (len > 0) {
  l = len;
  if (l > sizeof(buf))
   l = sizeof(buf);
  if (atomicio(read, fd, buf, l) != l) {
   sshlog("ssh-pkcs11-client.c", __func__, 92, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "response from helper failed.");
   return (0);
  }
  if ((r = sshbuf_put(m, buf, l)) != 0)
   sshfatal("ssh-pkcs11-client.c", __func__, 96, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_put");
  len -= l;
 }
 if ((r = sshbuf_get_u8(m, &c)) != 0)
  sshfatal("ssh-pkcs11-client.c", __func__, 100, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse type");
 return c;
}

int
pkcs11_init(int interactive)
{
 return (0);
}

void
pkcs11_terminate(void)
{
 if (fd >= 0)
  close(fd);
}

static int
rsa_encrypt(int flen, const u_char *from, u_char *to, RSA *rsa, int padding)
{
 struct sshkey *key = 
                     ((void *)0)
                         ;
 struct sshbuf *msg = 
                     ((void *)0)
                         ;
 u_char *blob = 
               ((void *)0)
                   , *signature = 
                                  ((void *)0)
                                      ;
 size_t blen, slen = 0;
 int r, ret = -1;

 if (padding != 
               1
                                )
  goto fail;
 key = sshkey_new(KEY_UNSPEC);
 if (key == 
           ((void *)0)
               ) {
  sshlog("ssh-pkcs11-client.c", __func__, 130, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshkey_new failed");
  goto fail;
 }
 key->type = KEY_RSA;
 RSA_up_ref(rsa);
 key->rsa = rsa;
 if ((r = sshkey_to_blob(key, &blob, &blen)) != 0) {
  sshlog("ssh-pkcs11-client.c", __func__, 137, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "encode key");
  goto fail;
 }
 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("ssh-pkcs11-client.c", __func__, 141, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, 13)) != 0 ||
     (r = sshbuf_put_string(msg, blob, blen)) != 0 ||
     (r = sshbuf_put_string(msg, from, flen)) != 0 ||
     (r = sshbuf_put_u32(msg, 0)) != 0)
  sshfatal("ssh-pkcs11-client.c", __func__, 146, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(msg);
 sshbuf_reset(msg);

 if (recv_msg(msg) == 14) {
  if ((r = sshbuf_get_string(msg, &signature, &slen)) != 0)
   sshfatal("ssh-pkcs11-client.c", __func__, 152, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
  if (slen <= (size_t)RSA_size(rsa)) {
   memcpy(to, signature, slen);
   ret = slen;
  }
  free(signature);
 }
 fail:
 free(blob);
 sshkey_free(key);
 sshbuf_free(msg);
 return (ret);
}


static ECDSA_SIG *
ecdsa_do_sign(const unsigned char *dgst, int dgst_len, const BIGNUM *inv,
    const BIGNUM *rp, EC_KEY *ec)
{
 struct sshkey *key = 
                     ((void *)0)
                         ;
 struct sshbuf *msg = 
                     ((void *)0)
                         ;
 ECDSA_SIG *ret = 
                 ((void *)0)
                     ;
 const u_char *cp;
 u_char *blob = 
               ((void *)0)
                   , *signature = 
                                  ((void *)0)
                                      ;
 size_t blen, slen = 0;
 int r, nid;

 nid = sshkey_ecdsa_key_to_nid(ec);
 if (nid < 0) {
  sshlog("ssh-pkcs11-client.c", __func__, 181, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "couldn't get curve nid");
  goto fail;
 }

 key = sshkey_new(KEY_UNSPEC);
 if (key == 
           ((void *)0)
               ) {
  sshlog("ssh-pkcs11-client.c", __func__, 187, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshkey_new failed");
  goto fail;
 }
 key->ecdsa = ec;
 key->ecdsa_nid = nid;
 key->type = KEY_ECDSA;
 EC_KEY_up_ref(ec);

 if ((r = sshkey_to_blob(key, &blob, &blen)) != 0) {
  sshlog("ssh-pkcs11-client.c", __func__, 196, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "encode key");
  goto fail;
 }
 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("ssh-pkcs11-client.c", __func__, 200, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, 13)) != 0 ||
     (r = sshbuf_put_string(msg, blob, blen)) != 0 ||
     (r = sshbuf_put_string(msg, dgst, dgst_len)) != 0 ||
     (r = sshbuf_put_u32(msg, 0)) != 0)
  sshfatal("ssh-pkcs11-client.c", __func__, 205, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(msg);
 sshbuf_reset(msg);

 if (recv_msg(msg) == 14) {
  if ((r = sshbuf_get_string(msg, &signature, &slen)) != 0)
   sshfatal("ssh-pkcs11-client.c", __func__, 211, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
  cp = signature;
  ret = d2i_ECDSA_SIG(
                     ((void *)0)
                         , &cp, slen);
  free(signature);
 }

 fail:
 free(blob);
 sshkey_free(key);
 sshbuf_free(msg);
 return (ret);
}


static RSA_METHOD *helper_rsa;

static EC_KEY_METHOD *helper_ecdsa;



static void
wrap_key(struct sshkey *k)
{
 if (k->type == KEY_RSA)
  RSA_set_method(k->rsa, helper_rsa);

 else if (k->type == KEY_ECDSA)
  EC_KEY_set_method(k->ecdsa, helper_ecdsa);

 else
  sshfatal("ssh-pkcs11-client.c", __func__, 241, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "unknown key type");
}

static int
pkcs11_start_helper_methods(void)
{
 if (helper_rsa != 
                  ((void *)0)
                      )
  return (0);


 int (*orig_sign)(int, const unsigned char *, int, unsigned char *,
     unsigned int *, const BIGNUM *, const BIGNUM *, EC_KEY *) = 
                                                                ((void *)0)
                                                                    ;
 if (helper_ecdsa != 
                    ((void *)0)
                        )
  return (0);
 helper_ecdsa = EC_KEY_METHOD_new(EC_KEY_OpenSSL());
 if (helper_ecdsa == 
                    ((void *)0)
                        )
  return (-1);
 EC_KEY_METHOD_get_sign(helper_ecdsa, &orig_sign, 
                                                 ((void *)0)
                                                     , 
                                                       ((void *)0)
                                                           );
 EC_KEY_METHOD_set_sign(helper_ecdsa, orig_sign, 
                                                ((void *)0)
                                                    , ecdsa_do_sign);


 if ((helper_rsa = RSA_meth_dup(RSA_get_default_method())) == 
                                                             ((void *)0)
                                                                 )
  sshfatal("ssh-pkcs11-client.c", __func__, 263, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "RSA_meth_dup failed");
 if (!RSA_meth_set1_name(helper_rsa, "ssh-pkcs11-helper") ||
     !RSA_meth_set_priv_enc(helper_rsa, rsa_encrypt))
  sshfatal("ssh-pkcs11-client.c", __func__, 266, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "failed to prepare method");

 return (0);
}

static int
pkcs11_start_helper(void)
{
 int pair[2];
 char *helper, *verbosity = 
                           ((void *)0)
                               ;

 if (log_level_get() >= SYSLOG_LEVEL_DEBUG1)
  verbosity = "-vvv";

 if (pkcs11_start_helper_methods() == -1) {
  sshlog("ssh-pkcs11-client.c", __func__, 281, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "pkcs11_start_helper_methods failed");
  return (-1);
 }

 if (socketpair(
               1
                      , 
                        SOCK_STREAM
                                   , 0, pair) == -1) {
  sshlog("ssh-pkcs11-client.c", __func__, 286, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "socketpair: %s", strerror(
 (*__errno_location ())
 ));
  return (-1);
 }
 if ((pid = fork()) == -1) {
  sshlog("ssh-pkcs11-client.c", __func__, 290, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "fork: %s", strerror(
 (*__errno_location ())
 ));
  return (-1);
 } else if (pid == 0) {
  if ((dup2(pair[1], 
                    0
                                ) == -1) ||
      (dup2(pair[1], 
                    1
                                 ) == -1)) {
   fprintf(
          stderr
                , "dup2: %s\n", strerror(
                                         (*__errno_location ())
                                              ));
   _exit(1);
  }
  close(pair[0]);
  close(pair[1]);
  helper = getenv("SSH_PKCS11_HELPER");
  if (helper == 
               ((void *)0) 
                    || strlen(helper) == 0)
   helper = "/usr/local/libexec/ssh-pkcs11-helper";
  sshlog("ssh-pkcs11-client.c", __func__, 303, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "starting %s %s", helper, verbosity == 
 ((void *)0) 
 ? "" : verbosity)
                                         ;
  execlp(helper, helper, verbosity, (char *)
                                           ((void *)0)
                                               );
  fprintf(
         stderr
               , "exec: %s: %s\n", helper, strerror(
                                                    (*__errno_location ())
                                                         ));
  _exit(1);
 }
 close(pair[1]);
 fd = pair[0];
 return (0);
}

int
pkcs11_add_provider(char *name, char *pin, struct sshkey ***keysp,
    char ***labelsp)
{
 struct sshkey *k;
 int r, type;
 u_char *blob;
 char *label;
 size_t blen;
 u_int nkeys, i;
 struct sshbuf *msg;

 if (fd < 0 && pkcs11_start_helper() < 0)
  return (-1);

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("ssh-pkcs11-client.c", __func__, 330, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, 20)) != 0 ||
     (r = sshbuf_put_cstring(msg, name)) != 0 ||
     (r = sshbuf_put_cstring(msg, pin)) != 0)
  sshfatal("ssh-pkcs11-client.c", __func__, 334, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(msg);
 sshbuf_reset(msg);

 type = recv_msg(msg);
 if (type == 12) {
  if ((r = sshbuf_get_u32(msg, &nkeys)) != 0)
   sshfatal("ssh-pkcs11-client.c", __func__, 341, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse nkeys");
  *keysp = xcalloc(nkeys, sizeof(struct sshkey *));
  if (labelsp)
   *labelsp = xcalloc(nkeys, sizeof(char *));
  for (i = 0; i < nkeys; i++) {

   if ((r = sshbuf_get_string(msg, &blob, &blen)) != 0 ||
       (r = sshbuf_get_cstring(msg, &label, 
                                           ((void *)0)
                                               )) != 0)
    sshfatal("ssh-pkcs11-client.c", __func__, 349, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse key");
   if ((r = sshkey_from_blob(blob, blen, &k)) != 0)
    sshfatal("ssh-pkcs11-client.c", __func__, 351, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "decode key");
   wrap_key(k);
   (*keysp)[i] = k;
   if (labelsp)
    (*labelsp)[i] = label;
   else
    free(label);
   free(blob);
  }
 } else if (type == 30) {
  if ((r = sshbuf_get_u32(msg, &nkeys)) != 0)
   nkeys = -1;
 } else {
  nkeys = -1;
 }
 sshbuf_free(msg);
 return (nkeys);
}

int
pkcs11_del_provider(char *name)
{
 int r, ret = -1;
 struct sshbuf *msg;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("ssh-pkcs11-client.c", __func__, 377, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, 21)) != 0 ||
     (r = sshbuf_put_cstring(msg, name)) != 0 ||
     (r = sshbuf_put_cstring(msg, "")) != 0)
  sshfatal("ssh-pkcs11-client.c", __func__, 381, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(msg);
 sshbuf_reset(msg);

 if (recv_msg(msg) == 6)
  ret = 0;
 sshbuf_free(msg);
 return (ret);
}
