











































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
struct passwd;
struct sshkey;
struct sshauthopt {

 int permit_port_forwarding_flag;
 int permit_agent_forwarding_flag;
 int permit_x11_forwarding_flag;
 int permit_pty_flag;
 int permit_user_rc;


 int restricted;


 uint64_t valid_before;


 int cert_authority;
 char *cert_principals;

 int force_tun_device;
 char *force_command;


 size_t nenv;
 char **env;


 size_t npermitopen;
 char **permitopen;


 size_t npermitlisten;
 char **permitlisten;





 char *required_from_host_cert;
 char *required_from_host_keys;


 int no_require_user_presence;

 int require_verify;
};

struct sshauthopt *sshauthopt_new(void);
struct sshauthopt *sshauthopt_new_with_keys_defaults(void);
void sshauthopt_free(struct sshauthopt *opts);
struct sshauthopt *sshauthopt_copy(const struct sshauthopt *orig);
int sshauthopt_serialise(const struct sshauthopt *opts, struct sshbuf *m, int);
int sshauthopt_deserialise(struct sshbuf *m, struct sshauthopt **opts);





struct sshauthopt *sshauthopt_parse(const char *s, const char **errstr);





struct sshauthopt *sshauthopt_from_cert(struct sshkey *k);




struct sshauthopt *sshauthopt_merge(const struct sshauthopt *primary,
    const struct sshauthopt *additional, const char **errstrp);

static int
dup_strings(char ***dstp, size_t *ndstp, char **src, size_t nsrc)
{
 char **dst;
 size_t i, j;

 *dstp = 
        ((void *)0)
            ;
 *ndstp = 0;
 if (nsrc == 0)
  return 0;

 if ((dst = calloc(nsrc, sizeof(*src))) == 
                                          ((void *)0)
                                              )
  return -1;
 for (i = 0; i < nsrc; i++) {
  if ((dst[i] = strdup(src[i])) == 
                                  ((void *)0)
                                      ) {
   for (j = 0; j < i; j++)
    free(dst[j]);
   free(dst);
   return -1;
  }
 }

 *dstp = dst;
 *ndstp = nsrc;
 return 0;
}



static int
cert_option_list(struct sshauthopt *opts, struct sshbuf *oblob,
    u_int which, int crit)
{
 char *command, *allowed;
 char *name = 
             ((void *)0)
                 ;
 struct sshbuf *c = 
                   ((void *)0)
                       , *data = 
                                 ((void *)0)
                                     ;
 int r, ret = -1, found;

 if ((c = sshbuf_fromb(oblob)) == 
                                 ((void *)0)
                                     ) {
  sshlog("auth-options.c", __func__, 82, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshbuf_fromb failed");
  goto out;
 }

 while (sshbuf_len(c) > 0) {
  sshbuf_free(data);
  data = 
        ((void *)0)
            ;
  if ((r = sshbuf_get_cstring(c, &name, 
                                       ((void *)0)
                                           )) != 0 ||
      (r = sshbuf_froms(c, &data)) != 0) {
   sshlog("auth-options.c", __func__, 91, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Unable to parse certificate options");
   goto out;
  }
  sshlog("auth-options.c", __func__, 94, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "found certificate option \"%.100s\" len %zu", name, sshbuf_len(data))
                             ;
  found = 0;
  if ((which & 2) != 0) {
   if (strcmp(name, "no-touch-required") == 0) {
    opts->no_require_user_presence = 1;
    found = 1;
   } else if (strcmp(name, "permit-X11-forwarding") == 0) {
    opts->permit_x11_forwarding_flag = 1;
    found = 1;
   } else if (strcmp(name,
       "permit-agent-forwarding") == 0) {
    opts->permit_agent_forwarding_flag = 1;
    found = 1;
   } else if (strcmp(name,
       "permit-port-forwarding") == 0) {
    opts->permit_port_forwarding_flag = 1;
    found = 1;
   } else if (strcmp(name, "permit-pty") == 0) {
    opts->permit_pty_flag = 1;
    found = 1;
   } else if (strcmp(name, "permit-user-rc") == 0) {
    opts->permit_user_rc = 1;
    found = 1;
   }
  }
  if (!found && (which & 1) != 0) {
   if (strcmp(name, "verify-required") == 0) {
    opts->require_verify = 1;
    found = 1;
   } else if (strcmp(name, "force-command") == 0) {
    if ((r = sshbuf_get_cstring(data, &command,
        
       ((void *)0)
           )) != 0) {
     sshlog("auth-options.c", __func__, 127, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Unable to parse \"%s\" " "section", name)
                         ;
     goto out;
    }
    if (opts->force_command != 
                              ((void *)0)
                                  ) {
     sshlog("auth-options.c", __func__, 132, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "Certificate has multiple " "force-command options")
                                 ;
     free(command);
     goto out;
    }
    opts->force_command = command;
    found = 1;
   } else if (strcmp(name, "source-address") == 0) {
    if ((r = sshbuf_get_cstring(data, &allowed,
        
       ((void *)0)
           )) != 0) {
     sshlog("auth-options.c", __func__, 142, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Unable to parse \"%s\" " "section", name)
                         ;
     goto out;
    }
    if (opts->required_from_host_cert != 
                                        ((void *)0)
                                            ) {
     sshlog("auth-options.c", __func__, 147, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "Certificate has multiple " "source-address options")
                                  ;
     free(allowed);
     goto out;
    }

    if (addr_match_cidr_list(
                            ((void *)0)
                                , allowed) == -1) {
     sshlog("auth-options.c", __func__, 154, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "Certificate source-address " "contents invalid")
                            ;
     goto out;
    }
    opts->required_from_host_cert = allowed;
    found = 1;
   }
  }

  if (!found) {
   if (crit) {
    sshlog("auth-options.c", __func__, 165, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Certificate critical option \"%s\" " "is not supported", name)
                                 ;
    goto out;
   } else {
    sshlog("auth-options.c", __func__, 169, 0, SYSLOG_LEVEL_INFO, 
   ((void *)0)
   , "Certificate extension \"%s\" " "is not supported", name)
                                 ;
   }
  } else if (sshbuf_len(data) != 0) {
   sshlog("auth-options.c", __func__, 173, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Certificate option \"%s\" corrupt " "(extra data)", name)
                            ;
   goto out;
  }
  free(name);
  name = 
        ((void *)0)
            ;
 }

 ret = 0;

 out:
 free(name);
 sshbuf_free(data);
 sshbuf_free(c);
 return ret;
}

struct sshauthopt *
sshauthopt_new(void)
{
 struct sshauthopt *ret;

 if ((ret = calloc(1, sizeof(*ret))) == 
                                       ((void *)0)
                                           )
  return 
        ((void *)0)
            ;
 ret->force_tun_device = -1;
 return ret;
}

void
sshauthopt_free(struct sshauthopt *opts)
{
 size_t i;

 if (opts == 
            ((void *)0)
                )
  return;

 free(opts->cert_principals);
 free(opts->force_command);
 free(opts->required_from_host_cert);
 free(opts->required_from_host_keys);

 for (i = 0; i < opts->nenv; i++)
  free(opts->env[i]);
 free(opts->env);

 for (i = 0; i < opts->npermitopen; i++)
  free(opts->permitopen[i]);
 free(opts->permitopen);

 for (i = 0; i < opts->npermitlisten; i++)
  free(opts->permitlisten[i]);
 free(opts->permitlisten);

 freezero(opts, sizeof(*opts));
}

struct sshauthopt *
sshauthopt_new_with_keys_defaults(void)
{
 struct sshauthopt *ret = 
                         ((void *)0)
                             ;

 if ((ret = sshauthopt_new()) == 
                                ((void *)0)
                                    )
  return 
        ((void *)0)
            ;


 ret->permit_port_forwarding_flag = 1;
 ret->permit_agent_forwarding_flag = 1;
 ret->permit_x11_forwarding_flag = 1;
 ret->permit_pty_flag = 1;
 ret->permit_user_rc = 1;
 return ret;
}





static int
handle_permit(const char **optsp, int allow_bare_port,
    char ***permitsp, size_t *npermitsp, const char **errstrp)
{
 char *opt, *tmp, *cp, *host, **permits = *permitsp;
 size_t npermits = *npermitsp;
 const char *errstr = "unknown error";

 if (npermits > 4096) {
  *errstrp = "too many permission directives";
  return -1;
 }
 if ((opt = opt_dequote(optsp, &errstr)) == 
                                           ((void *)0)
                                               ) {
  return -1;
 }
 if (allow_bare_port && strchr(opt, ':') == 
                                           ((void *)0)
                                               ) {




  if (asprintf(&tmp, "*:%s", opt) == -1) {
   free(opt);
   *errstrp = "memory allocation failed";
   return -1;
  }
  free(opt);
  opt = tmp;
 }
 if ((tmp = strdup(opt)) == 
                           ((void *)0)
                               ) {
  free(opt);
  *errstrp = "memory allocation failed";
  return -1;
 }
 cp = tmp;

 host = hpdelim2(&cp, 
                     ((void *)0)
                         );
 if (host == 
            ((void *)0) 
                 || strlen(host) >= 
                                    1025
                                              ) {
  free(tmp);
  free(opt);
  *errstrp = "invalid permission hostname";
  return -1;
 }




 if (cp == 
          ((void *)0) 
               ||
     (strcmp(cp, "*") != 0 && a2port(cp) <= 0)) {
  free(tmp);
  free(opt);
  *errstrp = "invalid permission port";
  return -1;
 }

 free(tmp);

 if ((permits = recallocarray(permits, npermits, npermits + 1,
     sizeof(*permits))) == 
                          ((void *)0)
                              ) {
  free(opt);

  *errstrp = "memory allocation failed";
  return -1;
 }
 permits[npermits++] = opt;
 *permitsp = permits;
 *npermitsp = npermits;
 return 0;
}

struct sshauthopt *
sshauthopt_parse(const char *opts, const char **errstrp)
{
 char **oarray, *opt, *cp, *tmp;
 int r;
 struct sshauthopt *ret = 
                         ((void *)0)
                             ;
 const char *errstr = "unknown error";
 uint64_t valid_before;
 size_t i, l;

 if (errstrp != 
               ((void *)0)
                   )
  *errstrp = 
            ((void *)0)
                ;
 if ((ret = sshauthopt_new_with_keys_defaults()) == 
                                                   ((void *)0)
                                                       )
  goto alloc_fail;

 if (opts == 
            ((void *)0)
                )
  return ret;

 while (*opts && *opts != ' ' && *opts != '\t') {

  if ((r = opt_flag("restrict", 0, &opts)) != -1) {
   ret->restricted = 1;
   ret->permit_port_forwarding_flag = 0;
   ret->permit_agent_forwarding_flag = 0;
   ret->permit_x11_forwarding_flag = 0;
   ret->permit_pty_flag = 0;
   ret->permit_user_rc = 0;
  } else if ((r = opt_flag("cert-authority", 0, &opts)) != -1) {
   ret->cert_authority = r;
  } else if ((r = opt_flag("port-forwarding", 1, &opts)) != -1) {
   ret->permit_port_forwarding_flag = r == 1;
  } else if ((r = opt_flag("agent-forwarding", 1, &opts)) != -1) {
   ret->permit_agent_forwarding_flag = r == 1;
  } else if ((r = opt_flag("x11-forwarding", 1, &opts)) != -1) {
   ret->permit_x11_forwarding_flag = r == 1;
  } else if ((r = opt_flag("touch-required", 1, &opts)) != -1) {
   ret->no_require_user_presence = r != 1;
  } else if ((r = opt_flag("verify-required", 1, &opts)) != -1) {
   ret->require_verify = r == 1;
  } else if ((r = opt_flag("pty", 1, &opts)) != -1) {
   ret->permit_pty_flag = r == 1;
  } else if ((r = opt_flag("user-rc", 1, &opts)) != -1) {
   ret->permit_user_rc = r == 1;
  } else if (opt_match(&opts, "command")) {
   if (ret->force_command != 
                            ((void *)0)
                                ) {
    errstr = "multiple \"command\" clauses";
    goto fail;
   }
   ret->force_command = opt_dequote(&opts, &errstr);
   if (ret->force_command == 
                            ((void *)0)
                                )
    goto fail;
  } else if (opt_match(&opts, "principals")) {
   if (ret->cert_principals != 
                              ((void *)0)
                                  ) {
    errstr = "multiple \"principals\" clauses";
    goto fail;
   }
   ret->cert_principals = opt_dequote(&opts, &errstr);
   if (ret->cert_principals == 
                              ((void *)0)
                                  )
    goto fail;
  } else if (opt_match(&opts, "from")) {
   if (ret->required_from_host_keys != 
                                      ((void *)0)
                                          ) {
    errstr = "multiple \"from\" clauses";
    goto fail;
   }
   ret->required_from_host_keys = opt_dequote(&opts,
       &errstr);
   if (ret->required_from_host_keys == 
                                      ((void *)0)
                                          )
    goto fail;
  } else if (opt_match(&opts, "expiry-time")) {
   if ((opt = opt_dequote(&opts, &errstr)) == 
                                             ((void *)0)
                                                 )
    goto fail;
   if (parse_absolute_time(opt, &valid_before) != 0 ||
       valid_before == 0) {
    free(opt);
    errstr = "invalid expires time";
    goto fail;
   }
   free(opt);
   if (ret->valid_before == 0 ||
       valid_before < ret->valid_before)
    ret->valid_before = valid_before;
  } else if (opt_match(&opts, "environment")) {
   if (ret->nenv > 1024) {
    errstr = "too many environment strings";
    goto fail;
   }
   if ((opt = opt_dequote(&opts, &errstr)) == 
                                             ((void *)0)
                                                 )
    goto fail;

   if ((tmp = strchr(opt, '=')) == 
                                  ((void *)0)
                                      ) {
    free(opt);
    errstr = "invalid environment string";
    goto fail;
   }
   if ((cp = strdup(opt)) == 
                            ((void *)0)
                                ) {
    free(opt);
    goto alloc_fail;
   }
   l = (size_t)(tmp - opt);
   cp[l] = '\0';
   if (!valid_env_name(cp)) {
    free(cp);
    free(opt);
    errstr = "invalid environment string";
    goto fail;
   }

   for (i = 0; i < ret->nenv; i++) {
    if (strncmp(ret->env[i], cp, l) == 0 &&
        ret->env[i][l] == '=')
     break;
   }
   free(cp);

   if (i >= ret->nenv) {

    oarray = ret->env;
    if ((ret->env = recallocarray(ret->env,
        ret->nenv, ret->nenv + 1,
        sizeof(*ret->env))) == 
                              ((void *)0)
                                  ) {
     free(opt);

     ret->env = oarray;
     goto alloc_fail;
    }
    ret->env[ret->nenv++] = opt;
    opt = 
         ((void *)0)
             ;
   }
   free(opt);
  } else if (opt_match(&opts, "permitopen")) {
   if (handle_permit(&opts, 0, &ret->permitopen,
       &ret->npermitopen, &errstr) != 0)
    goto fail;
  } else if (opt_match(&opts, "permitlisten")) {
   if (handle_permit(&opts, 1, &ret->permitlisten,
       &ret->npermitlisten, &errstr) != 0)
    goto fail;
  } else if (opt_match(&opts, "tunnel")) {
   if ((opt = opt_dequote(&opts, &errstr)) == 
                                             ((void *)0)
                                                 )
    goto fail;
   ret->force_tun_device = a2tun(opt, 
                                     ((void *)0)
                                         );
   free(opt);
   if (ret->force_tun_device == (0x7fffffff - 1)) {
    errstr = "invalid tun device";
    goto fail;
   }
  }




  if (*opts == '\0' || *opts == ' ' || *opts == '\t')
   break;

  if (*opts != ',') {
   errstr = "unknown key option";
   goto fail;
  }
  opts++;
  if (*opts == '\0') {
   errstr = "unexpected end-of-options";
   goto fail;
  }
 }


 if (errstrp != 
               ((void *)0)
                   )
  *errstrp = 
            ((void *)0)
                ;
 return ret;

alloc_fail:
 errstr = "memory allocation failed";
fail:
 sshauthopt_free(ret);
 if (errstrp != 
               ((void *)0)
                   )
  *errstrp = errstr;
 return 
       ((void *)0)
           ;
}

struct sshauthopt *
sshauthopt_from_cert(struct sshkey *k)
{
 struct sshauthopt *ret;

 if (k == 
         ((void *)0) 
              || !sshkey_type_is_cert(k->type) || k->cert == 
                                                             ((void *)0) 
                                                                  ||
     k->cert->type != 1)
  return 
        ((void *)0)
            ;

 if ((ret = sshauthopt_new()) == 
                                ((void *)0)
                                    )
  return 
        ((void *)0)
            ;


 if (cert_option_list(ret, k->cert->critical,
     1, 1) == -1) {
  sshauthopt_free(ret);
  return 
        ((void *)0)
            ;
 }
 if (cert_option_list(ret, k->cert->extensions,
     2, 0) == -1) {
  sshauthopt_free(ret);
  return 
        ((void *)0)
            ;
 }

 return ret;
}





struct sshauthopt *
sshauthopt_merge(const struct sshauthopt *primary,
    const struct sshauthopt *additional, const char **errstrp)
{
 struct sshauthopt *ret;
 const char *errstr = "internal error";
 const char *tmp;

 if (errstrp != 
               ((void *)0)
                   )
  *errstrp = 
            ((void *)0)
                ;

 if ((ret = sshauthopt_new()) == 
                                ((void *)0)
                                    )
  goto alloc_fail;





 tmp = primary->required_from_host_cert;
 if (tmp == 
           ((void *)0)
               )
  tmp = additional->required_from_host_cert;
 if (tmp != 
           ((void *)0) 
                && (ret->required_from_host_cert = strdup(tmp)) == 
                                                                   ((void *)0)
                                                                       )
  goto alloc_fail;
 tmp = primary->required_from_host_keys;
 if (tmp == 
           ((void *)0)
               )
  tmp = additional->required_from_host_keys;
 if (tmp != 
           ((void *)0) 
                && (ret->required_from_host_keys = strdup(tmp)) == 
                                                                   ((void *)0)
                                                                       )
  goto alloc_fail;





 ret->force_tun_device = primary->force_tun_device;
 if (ret->force_tun_device == -1)
  ret->force_tun_device = additional->force_tun_device;
 if (primary->nenv > 0) {
  if (dup_strings(&ret->env, &ret->nenv,
      primary->env, primary->nenv) != 0)
   goto alloc_fail;
 } else if (additional->nenv) {
  if (dup_strings(&ret->env, &ret->nenv,
      additional->env, additional->nenv) != 0)
   goto alloc_fail;
 }
 if (primary->npermitopen > 0) {
  if (dup_strings(&ret->permitopen, &ret->npermitopen,
      primary->permitopen, primary->npermitopen) != 0)
   goto alloc_fail;
 } else if (additional->npermitopen > 0) {
  if (dup_strings(&ret->permitopen, &ret->npermitopen,
      additional->permitopen, additional->npermitopen) != 0)
   goto alloc_fail;
 }

 if (primary->npermitlisten > 0) {
  if (dup_strings(&ret->permitlisten, &ret->npermitlisten,
      primary->permitlisten, primary->npermitlisten) != 0)
   goto alloc_fail;
 } else if (additional->npermitlisten > 0) {
  if (dup_strings(&ret->permitlisten, &ret->npermitlisten,
      additional->permitlisten, additional->npermitlisten) != 0)
   goto alloc_fail;
 }




 ret->permit_port_forwarding_flag = (primary->permit_port_forwarding_flag == 1) && (additional->permit_port_forwarding_flag == 1);
 ret->permit_agent_forwarding_flag = (primary->permit_agent_forwarding_flag == 1) && (additional->permit_agent_forwarding_flag == 1);
 ret->permit_x11_forwarding_flag = (primary->permit_x11_forwarding_flag == 1) && (additional->permit_x11_forwarding_flag == 1);
 ret->permit_pty_flag = (primary->permit_pty_flag == 1) && (additional->permit_pty_flag == 1);
 ret->permit_user_rc = (primary->permit_user_rc == 1) && (additional->permit_user_rc == 1);
 ret->no_require_user_presence = (primary->no_require_user_presence == 1) && (additional->no_require_user_presence == 1);

 ret->require_verify = (primary->require_verify == 1) || (additional->require_verify == 1);



 if (primary->valid_before != 0)
  ret->valid_before = primary->valid_before;
 if (additional->valid_before != 0 &&
     additional->valid_before < ret->valid_before)
  ret->valid_before = additional->valid_before;





 if (primary->force_command != 
                              ((void *)0) 
                                   &&
     additional->force_command != 
                                 ((void *)0)
                                     ) {
  if (strcmp(primary->force_command,
      additional->force_command) == 0) {

   ret->force_command = strdup(primary->force_command);
   if (ret->force_command == 
                            ((void *)0)
                                )
    goto alloc_fail;
  } else {
   errstr = "forced command options do not match";
   goto fail;
  }
 } else if (primary->force_command != 
                                     ((void *)0)
                                         ) {
  if ((ret->force_command = strdup(
      primary->force_command)) == 
                                 ((void *)0)
                                     )
   goto alloc_fail;
 } else if (additional->force_command != 
                                        ((void *)0)
                                            ) {
  if ((ret->force_command = strdup(
      additional->force_command)) == 
                                    ((void *)0)
                                        )
   goto alloc_fail;
 }

 if (errstrp != 
               ((void *)0)
                   )
  *errstrp = 
            ((void *)0)
                ;
 return ret;

 alloc_fail:
 errstr = "memory allocation failed";
 fail:
 if (errstrp != 
               ((void *)0)
                   )
  *errstrp = errstr;
 sshauthopt_free(ret);
 return 
       ((void *)0)
           ;
}




struct sshauthopt *
sshauthopt_copy(const struct sshauthopt *orig)
{
 struct sshauthopt *ret;

 if ((ret = sshauthopt_new()) == 
                                ((void *)0)
                                    )
  return 
        ((void *)0)
            ;


 ret->permit_port_forwarding_flag = orig->permit_port_forwarding_flag;
 ret->permit_agent_forwarding_flag = orig->permit_agent_forwarding_flag;
 ret->permit_x11_forwarding_flag = orig->permit_x11_forwarding_flag;
 ret->permit_pty_flag = orig->permit_pty_flag;
 ret->permit_user_rc = orig->permit_user_rc;
 ret->restricted = orig->restricted;
 ret->cert_authority = orig->cert_authority;
 ret->force_tun_device = orig->force_tun_device;
 ret->valid_before = orig->valid_before;
 ret->no_require_user_presence = orig->no_require_user_presence;
 ret->require_verify = orig->require_verify;
 do { if (orig->cert_principals != 
((void *)0) 
&& (ret->cert_principals = strdup(orig->cert_principals)) == 
((void *)0)
) { sshauthopt_free(ret); return 
((void *)0)
; } } while (0);
 do { if (orig->force_command != 
((void *)0) 
&& (ret->force_command = strdup(orig->force_command)) == 
((void *)0)
) { sshauthopt_free(ret); return 
((void *)0)
; } } while (0);
 do { if (orig->required_from_host_cert != 
((void *)0) 
&& (ret->required_from_host_cert = strdup(orig->required_from_host_cert)) == 
((void *)0)
) { sshauthopt_free(ret); return 
((void *)0)
; } } while (0);
 do { if (orig->required_from_host_keys != 
((void *)0) 
&& (ret->required_from_host_keys = strdup(orig->required_from_host_keys)) == 
((void *)0)
) { sshauthopt_free(ret); return 
((void *)0)
; } } while (0);


 if (dup_strings(&ret->env, &ret->nenv, orig->env, orig->nenv) != 0 ||
     dup_strings(&ret->permitopen, &ret->npermitopen,
     orig->permitopen, orig->npermitopen) != 0 ||
     dup_strings(&ret->permitlisten, &ret->npermitlisten,
     orig->permitlisten, orig->npermitlisten) != 0) {
  sshauthopt_free(ret);
  return 
        ((void *)0)
            ;
 }
 return ret;
}

static int
serialise_array(struct sshbuf *m, char **a, size_t n)
{
 struct sshbuf *b;
 size_t i;
 int r;

 if (n > 0x7fffffff)
  return -1;

 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              ) {
  return -2;
 }
 for (i = 0; i < n; i++) {
  if ((r = sshbuf_put_cstring(b, a[i])) != 0) {
   sshbuf_free(b);
   return r;
  }
 }
 if ((r = sshbuf_put_u32(m, n)) != 0 ||
     (r = sshbuf_put_stringb(m, b)) != 0) {
  sshbuf_free(b);
  return r;
 }

 return 0;
}

static int
deserialise_array(struct sshbuf *m, char ***ap, size_t *np)
{
 char **a = 
           ((void *)0)
               ;
 size_t i, n = 0;
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 u_int tmp;
 int r = -1;

 if ((r = sshbuf_get_u32(m, &tmp)) != 0 ||
     (r = sshbuf_froms(m, &b)) != 0)
  goto out;
 if (tmp > 0x7fffffff) {
  r = -4;
  goto out;
 }
 n = tmp;
 if (n > 0 && (a = calloc(n, sizeof(*a))) == 
                                            ((void *)0)
                                                ) {
  r = -2;
  goto out;
 }
 for (i = 0; i < n; i++) {
  if ((r = sshbuf_get_cstring(b, &a[i], 
                                       ((void *)0)
                                           )) != 0)
   goto out;
 }

 r = 0;
 *ap = a;
 a = 
    ((void *)0)
        ;
 *np = n;
 n = 0;
 out:
 if (a != 
         ((void *)0)
             ) {
  for (i = 0; i < n; i++)
   free(a[i]);
  free(a);
 }
 sshbuf_free(b);
 return r;
}

static int
serialise_nullable_string(struct sshbuf *m, const char *s)
{
 int r;

 if ((r = sshbuf_put_u8(m, s == 
                               ((void *)0)
                                   )) != 0 ||
     (r = sshbuf_put_cstring(m, s)) != 0)
  return r;
 return 0;
}

static int
deserialise_nullable_string(struct sshbuf *m, char **sp)
{
 int r;
 u_char flag;

 *sp = 
      ((void *)0)
          ;
 if ((r = sshbuf_get_u8(m, &flag)) != 0 ||
     (r = sshbuf_get_cstring(m, flag ? 
                                      ((void *)0) 
                                           : sp, 
                                                 ((void *)0)
                                                     )) != 0)
  return r;
 return 0;
}

int
sshauthopt_serialise(const struct sshauthopt *opts, struct sshbuf *m,
    int untrusted)
{
 int r = -1;


 if ((r = sshbuf_put_u8(m, opts->permit_port_forwarding_flag)) != 0 ||
     (r = sshbuf_put_u8(m, opts->permit_agent_forwarding_flag)) != 0 ||
     (r = sshbuf_put_u8(m, opts->permit_x11_forwarding_flag)) != 0 ||
     (r = sshbuf_put_u8(m, opts->permit_pty_flag)) != 0 ||
     (r = sshbuf_put_u8(m, opts->permit_user_rc)) != 0 ||
     (r = sshbuf_put_u8(m, opts->restricted)) != 0 ||
     (r = sshbuf_put_u8(m, opts->cert_authority)) != 0 ||
     (r = sshbuf_put_u8(m, opts->no_require_user_presence)) != 0 ||
     (r = sshbuf_put_u8(m, opts->require_verify)) != 0)
  return r;


 if ((r = sshbuf_put_u64(m, opts->valid_before)) != 0)
  return r;


 if ((r = sshbuf_put_u8(m, opts->force_tun_device == -1)) != 0 ||
     (r = sshbuf_put_u32(m, (opts->force_tun_device < 0) ?
     0 : (u_int)opts->force_tun_device)) != 0)
  return r;


 if ((r = serialise_nullable_string(m,
     untrusted ? "yes" : opts->cert_principals)) != 0 ||
     (r = serialise_nullable_string(m,
     untrusted ? "true" : opts->force_command)) != 0 ||
     (r = serialise_nullable_string(m,
     untrusted ? 
                ((void *)0) 
                     : opts->required_from_host_cert)) != 0 ||
     (r = serialise_nullable_string(m,
     untrusted ? 
                ((void *)0) 
                     : opts->required_from_host_keys)) != 0)
  return r;


 if ((r = serialise_array(m, opts->env,
     untrusted ? 0 : opts->nenv)) != 0 ||
     (r = serialise_array(m, opts->permitopen,
     untrusted ? 0 : opts->npermitopen)) != 0 ||
     (r = serialise_array(m, opts->permitlisten,
     untrusted ? 0 : opts->npermitlisten)) != 0)
  return r;


 return 0;
}

int
sshauthopt_deserialise(struct sshbuf *m, struct sshauthopt **optsp)
{
 struct sshauthopt *opts = 
                          ((void *)0)
                              ;
 int r = -1;
 u_char f;
 u_int tmp;

 if ((opts = calloc(1, sizeof(*opts))) == 
                                         ((void *)0)
                                             )
  return -2;
 do { if ((r = sshbuf_get_u8(m, &f)) != 0) goto out; opts->permit_port_forwarding_flag = f; } while (0);
 do { if ((r = sshbuf_get_u8(m, &f)) != 0) goto out; opts->permit_agent_forwarding_flag = f; } while (0);
 do { if ((r = sshbuf_get_u8(m, &f)) != 0) goto out; opts->permit_x11_forwarding_flag = f; } while (0);
 do { if ((r = sshbuf_get_u8(m, &f)) != 0) goto out; opts->permit_pty_flag = f; } while (0);
 do { if ((r = sshbuf_get_u8(m, &f)) != 0) goto out; opts->permit_user_rc = f; } while (0);
 do { if ((r = sshbuf_get_u8(m, &f)) != 0) goto out; opts->restricted = f; } while (0);
 do { if ((r = sshbuf_get_u8(m, &f)) != 0) goto out; opts->cert_authority = f; } while (0);
 do { if ((r = sshbuf_get_u8(m, &f)) != 0) goto out; opts->no_require_user_presence = f; } while (0);
 do { if ((r = sshbuf_get_u8(m, &f)) != 0) goto out; opts->require_verify = f; } while (0);



 if ((r = sshbuf_get_u64(m, &opts->valid_before)) != 0)
  goto out;


 if ((r = sshbuf_get_u8(m, &f)) != 0 ||
     (r = sshbuf_get_u32(m, &tmp)) != 0)
  goto out;
 opts->force_tun_device = f ? -1 : (int)tmp;


 if ((r = deserialise_nullable_string(m, &opts->cert_principals)) != 0 ||
     (r = deserialise_nullable_string(m, &opts->force_command)) != 0 ||
     (r = deserialise_nullable_string(m,
     &opts->required_from_host_cert)) != 0 ||
     (r = deserialise_nullable_string(m,
     &opts->required_from_host_keys)) != 0)
  goto out;


 if ((r = deserialise_array(m, &opts->env, &opts->nenv)) != 0 ||
     (r = deserialise_array(m,
     &opts->permitopen, &opts->npermitopen)) != 0 ||
     (r = deserialise_array(m,
     &opts->permitlisten, &opts->npermitlisten)) != 0)
  goto out;


 r = 0;
 *optsp = opts;
 opts = 
       ((void *)0)
           ;
 out:
 sshauthopt_free(opts);
 return r;
}
