











































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
struct sk_enroll_response {
 uint8_t flags;
 uint8_t *public_key;
 size_t public_key_len;
 uint8_t *key_handle;
 size_t key_handle_len;
 uint8_t *signature;
 size_t signature_len;
 uint8_t *attestation_cert;
 size_t attestation_cert_len;
 uint8_t *authdata;
 size_t authdata_len;
};

struct sk_sign_response {
 uint8_t flags;
 uint32_t counter;
 uint8_t *sig_r;
 size_t sig_r_len;
 uint8_t *sig_s;
 size_t sig_s_len;
};

struct sk_resident_key {
 uint32_t alg;
 size_t slot;
 char *application;
 struct sk_enroll_response key;
 uint8_t flags;
 uint8_t *user_id;
 size_t user_id_len;
};

struct sk_option {
 char *name;
 char *value;
 uint8_t required;
};





uint32_t sk_api_version(void);


int sk_enroll(uint32_t alg, const uint8_t *challenge, size_t challenge_len,
    const char *application, uint8_t flags, const char *pin,
    struct sk_option **options, struct sk_enroll_response **enroll_response);


int sk_sign(uint32_t alg, const uint8_t *data, size_t data_len,
    const char *application, const uint8_t *key_handle, size_t key_handle_len,
    uint8_t flags, const char *pin, struct sk_option **options,
    struct sk_sign_response **sign_response);


int sk_load_resident_keys(const char *pin, struct sk_option **options,
    struct sk_resident_key ***rks, size_t *nrks);
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
struct sshsk_provider {
 char *path;
 void *dlhandle;


 uint32_t (*sk_api_version)(void);


 int (*sk_enroll)(int alg, const uint8_t *challenge,
     size_t challenge_len, const char *application, uint8_t flags,
     const char *pin, struct sk_option **opts,
     struct sk_enroll_response **enroll_response);


 int (*sk_sign)(int alg, const uint8_t *message, size_t message_len,
     const char *application,
     const uint8_t *key_handle, size_t key_handle_len,
     uint8_t flags, const char *pin, struct sk_option **opts,
     struct sk_sign_response **sign_response);


 int (*sk_load_resident_keys)(const char *pin, struct sk_option **opts,
     struct sk_resident_key ***rks, size_t *nrks);
};


int ssh_sk_enroll(int alg, const uint8_t *challenge,
    size_t challenge_len, const char *application, uint8_t flags,
    const char *pin, struct sk_option **opts,
    struct sk_enroll_response **enroll_response);
int ssh_sk_sign(int alg, const uint8_t *message, size_t message_len,
    const char *application,
    const uint8_t *key_handle, size_t key_handle_len,
    uint8_t flags, const char *pin, struct sk_option **opts,
    struct sk_sign_response **sign_response);
int ssh_sk_load_resident_keys(const char *pin, struct sk_option **opts,
    struct sk_resident_key ***rks, size_t *nrks);

static void
sshsk_free(struct sshsk_provider *p)
{
 if (p == 
         ((void *)0)
             )
  return;
 free(p->path);
 if (p->dlhandle != 
                   ((void *)0)
                       )
  dlclose(p->dlhandle);
 free(p);
}

static struct sshsk_provider *
sshsk_open(const char *path)
{
 struct sshsk_provider *ret = 
                             ((void *)0)
                                 ;
 uint32_t version;

 if (path == 
            ((void *)0) 
                 || *path == '\0') {
  sshlog("ssh-sk.c", __func__, 113, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "No FIDO SecurityKeyProvider specified");
  return 
        ((void *)0)
            ;
 }
 if ((ret = calloc(1, sizeof(*ret))) == 
                                       ((void *)0)
                                           ) {
  sshlog("ssh-sk.c", __func__, 117, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "calloc failed");
  return 
        ((void *)0)
            ;
 }
 if ((ret->path = strdup(path)) == 
                                  ((void *)0)
                                      ) {
  sshlog("ssh-sk.c", __func__, 121, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "strdup failed");
  goto fail;
 }

 if (strcasecmp(ret->path, "internal") == 0) {






  sshlog("ssh-sk.c", __func__, 132, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "internal security key support not enabled");
  goto fail;

 }
 if ((ret->dlhandle = dlopen(path, 
                                  0x00002
                                          )) == 
                                                ((void *)0)
                                                    ) {
  sshlog("ssh-sk.c", __func__, 137, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Provider \"%s\" dlopen failed: %s", path, dlerror());
  goto fail;
 }
 if ((ret->sk_api_version = dlsym(ret->dlhandle,
     "sk_api_version")) == 
                          ((void *)0)
                              ) {
  sshlog("ssh-sk.c", __func__, 142, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Provider \"%s\" dlsym(sk_api_version) failed: %s", path, dlerror())
                      ;
  goto fail;
 }
 version = ret->sk_api_version();
 sshlog("ssh-sk.c", __func__, 147, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "provider %s implements version 0x%08lx", ret->path, (u_long)version)
                     ;
 if ((version & 0xffff0000) != 0x000a0000) {
  sshlog("ssh-sk.c", __func__, 150, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Provider \"%s\" implements unsupported " "version 0x%08lx (supported: 0x%08lx)", path, (u_long)version, (u_long)0x000a0000)

                                                          ;
  goto fail;
 }
 if ((ret->sk_enroll = dlsym(ret->dlhandle, "sk_enroll")) == 
                                                            ((void *)0)
                                                                ) {
  sshlog("ssh-sk.c", __func__, 156, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Provider %s dlsym(sk_enroll) failed: %s", path, dlerror())
                      ;
  goto fail;
 }
 if ((ret->sk_sign = dlsym(ret->dlhandle, "sk_sign")) == 
                                                        ((void *)0)
                                                            ) {
  sshlog("ssh-sk.c", __func__, 161, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Provider \"%s\" dlsym(sk_sign) failed: %s", path, dlerror())
                      ;
  goto fail;
 }
 if ((ret->sk_load_resident_keys = dlsym(ret->dlhandle,
     "sk_load_resident_keys")) == 
                                 ((void *)0)
                                     ) {
  sshlog("ssh-sk.c", __func__, 167, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Provider \"%s\" dlsym(sk_load_resident_keys) " "failed: %s", path, dlerror())
                                    ;
  goto fail;
 }

 return ret;
fail:
 sshsk_free(ret);
 return 
       ((void *)0)
           ;
}

static void
sshsk_free_enroll_response(struct sk_enroll_response *r)
{
 if (r == 
         ((void *)0)
             )
  return;
 freezero(r->key_handle, r->key_handle_len);
 freezero(r->public_key, r->public_key_len);
 freezero(r->signature, r->signature_len);
 freezero(r->attestation_cert, r->attestation_cert_len);
 freezero(r->authdata, r->authdata_len);
 freezero(r, sizeof(*r));
}

static void
sshsk_free_sign_response(struct sk_sign_response *r)
{
 if (r == 
         ((void *)0)
             )
  return;
 freezero(r->sig_r, r->sig_r_len);
 freezero(r->sig_s, r->sig_s_len);
 freezero(r, sizeof(*r));
}



static int
sshsk_ecdsa_assemble(struct sk_enroll_response *resp, struct sshkey **keyp)
{
 struct sshkey *key = 
                     ((void *)0)
                         ;
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 EC_POINT *q = 
              ((void *)0)
                  ;
 int r;

 *keyp = 
        ((void *)0)
            ;
 if ((key = sshkey_new(KEY_ECDSA_SK)) == 
                                        ((void *)0)
                                            ) {
  sshlog("ssh-sk.c", __func__, 213, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshkey_new failed");
  r = -2;
  goto out;
 }
 key->ecdsa_nid = 
                 415
                                     ;
 if ((key->ecdsa = EC_KEY_new_by_curve_name(key->ecdsa_nid)) == 
                                                               ((void *)0) 
                                                                    ||
     (q = EC_POINT_new(EC_KEY_get0_group(key->ecdsa))) == 
                                                         ((void *)0) 
                                                              ||
     (b = sshbuf_new()) == 
                          ((void *)0)
                              ) {
  sshlog("ssh-sk.c", __func__, 221, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "allocation failed");
  r = -2;
  goto out;
 }
 if ((r = sshbuf_put_string(b,
     resp->public_key, resp->public_key_len)) != 0) {
  sshlog("ssh-sk.c", __func__, 227, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshbuf_put_string");
  goto out;
 }
 if ((r = sshbuf_get_ec(b, q, EC_KEY_get0_group(key->ecdsa))) != 0) {
  sshlog("ssh-sk.c", __func__, 231, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse");
  r = -4;
  goto out;
 }
 if (sshkey_ec_validate_public(EC_KEY_get0_group(key->ecdsa), q) != 0) {
  sshlog("ssh-sk.c", __func__, 236, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Authenticator returned invalid ECDSA key");
  r = -20;
  goto out;
 }
 if (EC_KEY_set_public_key(key->ecdsa, q) != 1) {

  sshlog("ssh-sk.c", __func__, 242, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "allocation failed");
  r = -2;
  goto out;
 }

 *keyp = key;
 key = 
      ((void *)0)
          ;
 r = 0;
 out:
 EC_POINT_free(q);
 sshkey_free(key);
 sshbuf_free(b);
 return r;
}


static int
sshsk_ed25519_assemble(struct sk_enroll_response *resp, struct sshkey **keyp)
{
 struct sshkey *key = 
                     ((void *)0)
                         ;
 int r;

 *keyp = 
        ((void *)0)
            ;
 if (resp->public_key_len != 32U) {
  sshlog("ssh-sk.c", __func__, 266, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "invalid size: %zu", resp->public_key_len);
  r = -4;
  goto out;
 }
 if ((key = sshkey_new(KEY_ED25519_SK)) == 
                                          ((void *)0)
                                              ) {
  sshlog("ssh-sk.c", __func__, 271, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshkey_new failed");
  r = -2;
  goto out;
 }
 if ((key->ed25519_pk = malloc(32U)) == 
                                                 ((void *)0)
                                                     ) {
  sshlog("ssh-sk.c", __func__, 276, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "malloc failed");
  r = -2;
  goto out;
 }
 memcpy(key->ed25519_pk, resp->public_key, 32U);

 *keyp = key;
 key = 
      ((void *)0)
          ;
 r = 0;
 out:
 sshkey_free(key);
 return r;
}

static int
sshsk_key_from_response(int alg, const char *application, uint8_t flags,
    struct sk_enroll_response *resp, struct sshkey **keyp)
{
 struct sshkey *key = 
                     ((void *)0)
                         ;
 int r = -1;

 *keyp = 
        ((void *)0)
            ;


 if (resp->public_key == 
                        ((void *)0) 
                             || resp->key_handle == 
                                                    ((void *)0)
                                                        ) {
  sshlog("ssh-sk.c", __func__, 301, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sk_enroll response invalid");
  r = -4;
  goto out;
 }
 switch (alg) {

 case 0x00:
  if ((r = sshsk_ecdsa_assemble(resp, &key)) != 0)
   goto out;
  break;

 case 0x01:
  if ((r = sshsk_ed25519_assemble(resp, &key)) != 0)
   goto out;
  break;
 default:
  sshlog("ssh-sk.c", __func__, 317, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unsupported algorithm %d", alg);
  r = -10;
  goto out;
 }
 key->sk_flags = flags;
 if ((key->sk_key_handle = sshbuf_new()) == 
                                           ((void *)0) 
                                                ||
     (key->sk_reserved = sshbuf_new()) == 
                                         ((void *)0)
                                             ) {
  sshlog("ssh-sk.c", __func__, 324, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "allocation failed");
  r = -2;
  goto out;
 }
 if ((key->sk_application = strdup(application)) == 
                                                   ((void *)0)
                                                       ) {
  sshlog("ssh-sk.c", __func__, 329, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "strdup application failed");
  r = -2;
  goto out;
 }
 if ((r = sshbuf_put(key->sk_key_handle, resp->key_handle,
     resp->key_handle_len)) != 0) {
  sshlog("ssh-sk.c", __func__, 335, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "put key handle");
  goto out;
 }

 r = 0;
 *keyp = key;
 key = 
      ((void *)0)
          ;
 out:
 sshkey_free(key);
 return r;
}

static int
skerr_to_ssherr(int skerr)
{
 switch (skerr) {
 case -2:
  return -59;
 case -3:
  return -43;
 case -4:
  return -60;
 case -5:
  return -44;
 case -1:
 default:
  return -4;
 }
}

static void
sshsk_free_options(struct sk_option **opts)
{
 size_t i;

 if (opts == 
            ((void *)0)
                )
  return;
 for (i = 0; opts[i] != 
                       ((void *)0)
                           ; i++) {
  free(opts[i]->name);
  free(opts[i]->value);
  free(opts[i]);
 }
 free(opts);
}

static int
sshsk_add_option(struct sk_option ***optsp, size_t *noptsp,
    const char *name, const char *value, uint8_t required)
{
 struct sk_option **opts = *optsp;
 size_t nopts = *noptsp;

 if ((opts = recallocarray(opts, nopts, nopts + 2,
     sizeof(*opts))) == 
                       ((void *)0)
                           ) {
  sshlog("ssh-sk.c", __func__, 389, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "array alloc failed");
  return -2;
 }
 *optsp = opts;
 *noptsp = nopts + 1;
 if ((opts[nopts] = calloc(1, sizeof(**opts))) == 
                                                 ((void *)0)
                                                     ) {
  sshlog("ssh-sk.c", __func__, 395, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "alloc failed");
  return -2;
 }
 if ((opts[nopts]->name = strdup(name)) == 
                                          ((void *)0) 
                                               ||
     (opts[nopts]->value = strdup(value)) == 
                                            ((void *)0)
                                                ) {
  sshlog("ssh-sk.c", __func__, 400, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "alloc failed");
  return -2;
 }
 opts[nopts]->required = required;
 return 0;
}

static int
make_options(const char *device, const char *user_id,
    struct sk_option ***optsp)
{
 struct sk_option **opts = 
                          ((void *)0)
                              ;
 size_t nopts = 0;
 int r, ret = -1;

 if (device != 
              ((void *)0) 
                   &&
     (r = sshsk_add_option(&opts, &nopts, "device", device, 0)) != 0) {
  ret = r;
  goto out;
 }
 if (user_id != 
               ((void *)0) 
                    &&
     (r = sshsk_add_option(&opts, &nopts, "user", user_id, 0)) != 0) {
  ret = r;
  goto out;
 }

 *optsp = opts;
 opts = 
       ((void *)0)
           ;
 nopts = 0;
 ret = 0;
 out:
 sshsk_free_options(opts);
 return ret;
}


static int
fill_attestation_blob(const struct sk_enroll_response *resp,
    struct sshbuf *attest)
{
 int r;

 if (attest == 
              ((void *)0)
                  )
  return 0;
 if ((r = sshbuf_put_cstring(attest, "ssh-sk-attest-v01")) != 0 ||
     (r = sshbuf_put_string(attest,
     resp->attestation_cert, resp->attestation_cert_len)) != 0 ||
     (r = sshbuf_put_string(attest,
     resp->signature, resp->signature_len)) != 0 ||
     (r = sshbuf_put_string(attest,
     resp->authdata, resp->authdata_len)) != 0 ||
     (r = sshbuf_put_u32(attest, 0)) != 0 ||
     (r = sshbuf_put_string(attest, 
                                   ((void *)0)
                                       , 0)) != 0 ) {
  sshlog("ssh-sk.c", __func__, 453, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "compose");
  return r;
 }

 return 0;
}

int
sshsk_enroll(int type, const char *provider_path, const char *device,
    const char *application, const char *userid, uint8_t flags,
    const char *pin, struct sshbuf *challenge_buf,
    struct sshkey **keyp, struct sshbuf *attest)
{
 struct sshsk_provider *skp = 
                             ((void *)0)
                                 ;
 struct sshkey *key = 
                     ((void *)0)
                         ;
 u_char randchall[32];
 const u_char *challenge;
 size_t challenge_len;
 struct sk_enroll_response *resp = 
                                  ((void *)0)
                                      ;
 struct sk_option **opts = 
                          ((void *)0)
                              ;
 int r = -1;
 int alg;

 sshlog("ssh-sk.c", __func__, 476, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "provider \"%s\", device \"%s\", application \"%s\", " "userid \"%s\", flags 0x%02x, challenge len %zu%s", provider_path, device, application, userid, flags, challenge_buf == 
((void *)0) 
? 0 : sshbuf_len(challenge_buf), (pin != 
((void *)0) 
&& *pin != '\0') ? " with-pin" : "")



                                                      ;

 *keyp = 
        ((void *)0)
            ;
 if (attest)
  sshbuf_reset(attest);

 if ((r = make_options(device, userid, &opts)) != 0)
  goto out;

 switch (type) {

 case KEY_ECDSA_SK:
  alg = 0x00;
  break;

 case KEY_ED25519_SK:
  alg = 0x01;
  break;
 default:
  sshlog("ssh-sk.c", __func__, 499, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unsupported key type");
  r = -10;
  goto out;
 }
 if (provider_path == 
                     ((void *)0)
                         ) {
  sshlog("ssh-sk.c", __func__, 504, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "missing provider");
  r = -10;
  goto out;
 }
 if (application == 
                   ((void *)0) 
                        || *application == '\0') {
  sshlog("ssh-sk.c", __func__, 509, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "missing application");
  r = -10;
  goto out;
 }
 if (challenge_buf == 
                     ((void *)0)
                         ) {
  sshlog("ssh-sk.c", __func__, 514, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "using random challenge");
  arc4random_buf(randchall, sizeof(randchall));
  challenge = randchall;
  challenge_len = sizeof(randchall);
 } else if (sshbuf_len(challenge_buf) == 0) {
  sshlog("ssh-sk.c", __func__, 519, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Missing enrollment challenge");
  r = -10;
  goto out;
 } else {
  challenge = sshbuf_ptr(challenge_buf);
  challenge_len = sshbuf_len(challenge_buf);
  sshlog("ssh-sk.c", __func__, 525, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "using explicit challenge len=%zd", challenge_len);
 }
 if ((skp = sshsk_open(provider_path)) == 
                                         ((void *)0)
                                             ) {
  r = -4;
  goto out;
 }


 if ((r = skp->sk_enroll(alg, challenge, challenge_len, application,
     flags, pin, opts, &resp)) != 0) {
  sshlog("ssh-sk.c", __func__, 535, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "provider \"%s\" failure %d", provider_path, r);
  r = skerr_to_ssherr(r);
  goto out;
 }

 if ((r = sshsk_key_from_response(alg, application, resp->flags,
     resp, &key)) != 0)
  goto out;


 if ((r = fill_attestation_blob(resp, attest)) != 0)
  goto out;


 *keyp = key;
 key = 
      ((void *)0)
          ;
 r = 0;
 out:
 sshsk_free_options(opts);
 sshsk_free(skp);
 sshkey_free(key);
 sshsk_free_enroll_response(resp);
 explicit_bzero(randchall, sizeof(randchall));
 return r;
}


static int
sshsk_ecdsa_sig(struct sk_sign_response *resp, struct sshbuf *sig)
{
 struct sshbuf *inner_sig = 
                           ((void *)0)
                               ;
 int r = -1;


 if (resp->sig_r == 
                   ((void *)0) 
                        || resp->sig_s == 
                                          ((void *)0)
                                              ) {
  sshlog("ssh-sk.c", __func__, 570, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sk_sign response invalid");
  r = -4;
  goto out;
 }
 if ((inner_sig = sshbuf_new()) == 
                                  ((void *)0)
                                      ) {
  r = -2;
  goto out;
 }

 if ((r = sshbuf_put_bignum2_bytes(inner_sig,
     resp->sig_r, resp->sig_r_len)) != 0 ||
     (r = sshbuf_put_bignum2_bytes(inner_sig,
     resp->sig_s, resp->sig_s_len)) != 0) {
  sshlog("ssh-sk.c", __func__, 583, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "compose inner");
  goto out;
 }
 if ((r = sshbuf_put_stringb(sig, inner_sig)) != 0 ||
     (r = sshbuf_put_u8(sig, resp->flags)) != 0 ||
     (r = sshbuf_put_u32(sig, resp->counter)) != 0) {
  sshlog("ssh-sk.c", __func__, 589, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "compose");
  goto out;
 }
 r = 0;
 out:
 sshbuf_free(inner_sig);
 return r;
}


static int
sshsk_ed25519_sig(struct sk_sign_response *resp, struct sshbuf *sig)
{
 int r = -1;


 if (resp->sig_r == 
                   ((void *)0)
                       ) {
  sshlog("ssh-sk.c", __func__, 614, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sk_sign response invalid");
  r = -4;
  goto out;
 }
 if ((r = sshbuf_put_string(sig,
     resp->sig_r, resp->sig_r_len)) != 0 ||
     (r = sshbuf_put_u8(sig, resp->flags)) != 0 ||
     (r = sshbuf_put_u32(sig, resp->counter)) != 0) {
  sshlog("ssh-sk.c", __func__, 622, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "compose");
  goto out;
 }




 r = 0;
 out:
 return r;
}

int
sshsk_sign(const char *provider_path, struct sshkey *key,
    u_char **sigp, size_t *lenp, const u_char *data, size_t datalen,
    u_int compat, const char *pin)
{
 struct sshsk_provider *skp = 
                             ((void *)0)
                                 ;
 int r = -1;
 int type, alg;
 struct sk_sign_response *resp = 
                                ((void *)0)
                                    ;
 struct sshbuf *inner_sig = 
                           ((void *)0)
                               , *sig = 
                                        ((void *)0)
                                            ;
 struct sk_option **opts = 
                          ((void *)0)
                              ;

 sshlog("ssh-sk.c", __func__, 646, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "provider \"%s\", key %s, flags 0x%02x%s", provider_path, sshkey_type(key), key->sk_flags, (pin != 
((void *)0) 
&& *pin != '\0') ? " with-pin" : "")

                                                      ;

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
 type = sshkey_type_plain(key->type);
 switch (type) {

 case KEY_ECDSA_SK:
  alg = 0x00;
  break;

 case KEY_ED25519_SK:
  alg = 0x01;
  break;
 default:
  return -10;
 }
 if (provider_path == 
                     ((void *)0) 
                          ||
     key->sk_key_handle == 
                          ((void *)0) 
                               ||
     key->sk_application == 
                           ((void *)0) 
                                || *key->sk_application == '\0') {
  r = -10;
  goto out;
 }
 if ((skp = sshsk_open(provider_path)) == 
                                         ((void *)0)
                                             ) {
  r = -4;
  goto out;
 }






 if ((r = skp->sk_sign(alg, data, datalen, key->sk_application,
     sshbuf_ptr(key->sk_key_handle), sshbuf_len(key->sk_key_handle),
     key->sk_flags, pin, opts, &resp)) != 0) {
  sshlog("ssh-sk.c", __func__, 686, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "sk_sign failed with code %d", r);
  r = skerr_to_ssherr(r);
  goto out;
 }

 if ((sig = sshbuf_new()) == 
                            ((void *)0)
                                ) {
  r = -2;
  goto out;
 }
 if ((r = sshbuf_put_cstring(sig, sshkey_ssh_name_plain(key))) != 0) {
  sshlog("ssh-sk.c", __func__, 696, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "compose outer");
  goto out;
 }
 switch (type) {

 case KEY_ECDSA_SK:
  if ((r = sshsk_ecdsa_sig(resp, sig)) != 0)
   goto out;
  break;

 case KEY_ED25519_SK:
  if ((r = sshsk_ed25519_sig(resp, sig)) != 0)
   goto out;
  break;
 }
 if (sigp != 
            ((void *)0)
                ) {
  if ((*sigp = malloc(sshbuf_len(sig))) == 
                                          ((void *)0)
                                              ) {
   r = -2;
   goto out;
  }
  memcpy(*sigp, sshbuf_ptr(sig), sshbuf_len(sig));
 }
 if (lenp != 
            ((void *)0)
                )
  *lenp = sshbuf_len(sig);

 r = 0;
 out:
 sshsk_free_options(opts);
 sshsk_free(skp);
 sshsk_free_sign_response(resp);
 sshbuf_free(sig);
 sshbuf_free(inner_sig);
 return r;
}

static void
sshsk_free_sk_resident_keys(struct sk_resident_key **rks, size_t nrks)
{
 size_t i;

 if (nrks == 0 || rks == 
                        ((void *)0)
                            )
  return;
 for (i = 0; i < nrks; i++) {
  free(rks[i]->application);
  freezero(rks[i]->user_id, rks[i]->user_id_len);
  freezero(rks[i]->key.key_handle, rks[i]->key.key_handle_len);
  freezero(rks[i]->key.public_key, rks[i]->key.public_key_len);
  freezero(rks[i]->key.signature, rks[i]->key.signature_len);
  freezero(rks[i]->key.attestation_cert,
      rks[i]->key.attestation_cert_len);
  freezero(rks[i], sizeof(**rks));
 }
 free(rks);
}

static void
sshsk_free_resident_key(struct sshsk_resident_key *srk)
{
 if (srk == 
           ((void *)0)
               )
  return;
 sshkey_free(srk->key);
 freezero(srk->user_id, srk->user_id_len);
 free(srk);
}


void
sshsk_free_resident_keys(struct sshsk_resident_key **srks, size_t nsrks)
{
 size_t i;

 if (srks == 
            ((void *)0) 
                 || nsrks == 0)
  return;

 for (i = 0; i < nsrks; i++)
  sshsk_free_resident_key(srks[i]);
 free(srks);
}

int
sshsk_load_resident(const char *provider_path, const char *device,
    const char *pin, u_int flags, struct sshsk_resident_key ***srksp,
    size_t *nsrksp)
{
 struct sshsk_provider *skp = 
                             ((void *)0)
                                 ;
 int r = -1;
 struct sk_resident_key **rks = 
                               ((void *)0)
                                   ;
 size_t i, nrks = 0, nsrks = 0;
 struct sshkey *key = 
                     ((void *)0)
                         ;
 struct sshsk_resident_key *srk = 
                                 ((void *)0)
                                     , **srks = 
                                                ((void *)0)
                                                    , **tmp;
 uint8_t sk_flags;
 struct sk_option **opts = 
                          ((void *)0)
                              ;

 sshlog("ssh-sk.c", __func__, 797, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "provider \"%s\"%s", provider_path, (pin != 
((void *)0) 
&& *pin != '\0') ? ", have-pin": "")
                                                      ;

 if (srksp == 
             ((void *)0) 
                  || nsrksp == 
                               ((void *)0)
                                   )
  return -10;
 *srksp = 
         ((void *)0)
             ;
 *nsrksp = 0;

 if ((r = make_options(device, 
                              ((void *)0)
                                  , &opts)) != 0)
  goto out;
 if ((skp = sshsk_open(provider_path)) == 
                                         ((void *)0)
                                             ) {
  r = -4;
  goto out;
 }
 if ((r = skp->sk_load_resident_keys(pin, opts, &rks, &nrks)) != 0) {
  sshlog("ssh-sk.c", __func__, 812, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Provider \"%s\" returned failure %d", provider_path, r);
  r = skerr_to_ssherr(r);
  goto out;
 }
 for (i = 0; i < nrks; i++) {
  sshlog("ssh-sk.c", __func__, 817, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "rk %zu: slot %zu, alg %d, app \"%s\", uidlen %zu", i, rks[i]->slot, rks[i]->alg, rks[i]->application, rks[i]->user_id_len)

                          ;

  if (strncmp(rks[i]->application, "ssh:", 4) != 0)
   continue;
  switch (rks[i]->alg) {
  case 0x00:
  case 0x01:
   break;
  default:
   continue;
  }
  sk_flags = 0x01|0x20;
  if ((rks[i]->flags & 0x04))
   sk_flags |= 0x04;
  if ((r = sshsk_key_from_response(rks[i]->alg,
      rks[i]->application, sk_flags, &rks[i]->key, &key)) != 0)
   goto out;
  if ((srk = calloc(1, sizeof(*srk))) == 
                                        ((void *)0)
                                            ) {
   sshlog("ssh-sk.c", __func__, 837, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "calloc failed");
   r = -2;
   goto out;
  }
  srk->key = key;
  key = 
       ((void *)0)
           ;
  if ((srk->user_id = calloc(1, rks[i]->user_id_len)) == 
                                                        ((void *)0)
                                                            ) {
   sshlog("ssh-sk.c", __func__, 844, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "calloc failed");
   r = -2;
   goto out;
  }
  memcpy(srk->user_id, rks[i]->user_id, rks[i]->user_id_len);
  srk->user_id_len = rks[i]->user_id_len;
  if ((tmp = recallocarray(srks, nsrks, nsrks + 1,
      sizeof(*tmp))) == 
                       ((void *)0)
                           ) {
   sshlog("ssh-sk.c", __func__, 852, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "recallocarray failed");
   r = -2;
   goto out;
  }
  srks = tmp;
  srks[nsrks++] = srk;
  srk = 
       ((void *)0)
           ;

 }

 *srksp = srks;
 *nsrksp = nsrks;
 srks = 
       ((void *)0)
           ;
 nsrks = 0;
 r = 0;
 out:
 sshsk_free_options(opts);
 sshsk_free(skp);
 sshsk_free_sk_resident_keys(rks, nrks);
 sshkey_free(key);
 sshsk_free_resident_key(srk);
 sshsk_free_resident_keys(srks, nsrks);
 return r;
}
