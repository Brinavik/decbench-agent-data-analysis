











































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
struct sshkey;
struct sshsigopt;
struct sshkey_sig_details;

typedef int sshsig_signer(struct sshkey *, u_char **, size_t *,
    const u_char *, size_t, const char *, const char *, const char *,
    u_int, void *);
int sshsig_signb(struct sshkey *key, const char *hashalg,
    const char *sk_provider, const char *sk_pin, const struct sshbuf *message,
    const char *sig_namespace, struct sshbuf **out,
    sshsig_signer *signer, void *signer_ctx);






int sshsig_verifyb(struct sshbuf *signature,
    const struct sshbuf *message, const char *sig_namespace,
    struct sshkey **sign_keyp, struct sshkey_sig_details **sig_details);
int sshsig_sign_fd(struct sshkey *key, const char *hashalg,
    const char *sk_provider, const char *sk_pin,
    int fd, const char *sig_namespace,
    struct sshbuf **out, sshsig_signer *signer, void *signer_ctx);






int sshsig_verify_fd(struct sshbuf *signature, int fd,
    const char *sig_namespace, struct sshkey **sign_keyp,
    struct sshkey_sig_details **sig_details);






int sshsig_armor(const struct sshbuf *blob, struct sshbuf **out);




int sshsig_dearmor(struct sshbuf *sig, struct sshbuf **out);





int sshsig_check_allowed_keys(const char *path, const struct sshkey *sign_key,
    const char *principal, const char *ns, uint64_t verify_time);


struct sshsigopt *sshsigopt_parse(const char *opts,
    const char *path, u_long linenum, const char **errstrp);


void sshsigopt_free(struct sshsigopt *opts);


int sshsig_get_pubkey(struct sshbuf *signature, struct sshkey **pubkey);




int sshsig_find_principals(const char *path, const struct sshkey *sign_key,
    uint64_t verify_time, char **principal);


int sshsig_match_principals(const char *path,
 const char *principal, char ***principalsp, size_t *nprincipalsp);




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
int
sshsig_armor(const struct sshbuf *blob, struct sshbuf **out)
{
 struct sshbuf *buf = 
                     ((void *)0)
                         ;
 int r = -1;

 *out = 
       ((void *)0)
           ;

 if ((buf = sshbuf_new()) == 
                            ((void *)0)
                                ) {
  sshlog("sshsig.c", __func__, 57, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshbuf_new failed");
  r = -2;
  goto out;
 }

 if ((r = sshbuf_put(buf, "-----BEGIN SSH SIGNATURE-----\n",
     sizeof("-----BEGIN SSH SIGNATURE-----\n")-1)) != 0) {
  sshlog("sshsig.c", __func__, 64, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshbuf_putf");
  goto out;
 }

 if ((r = sshbuf_dtob64(blob, buf, 1)) != 0) {
  sshlog("sshsig.c", __func__, 69, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "base64 encode signature");
  goto out;
 }

 if ((r = sshbuf_put(buf, "-----END SSH SIGNATURE-----",
     sizeof("-----END SSH SIGNATURE-----")-1)) != 0 ||
     (r = sshbuf_put_u8(buf, '\n')) != 0) {
  sshlog("sshsig.c", __func__, 76, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshbuf_put");
  goto out;
 }

 *out = buf;
 buf = 
      ((void *)0)
          ;
 r = 0;
 out:
 sshbuf_free(buf);
 return r;
}

int
sshsig_dearmor(struct sshbuf *sig, struct sshbuf **out)
{
 int r;
 size_t eoffset = 0;
 struct sshbuf *buf = 
                     ((void *)0)
                         ;
 struct sshbuf *sbuf = 
                      ((void *)0)
                          ;
 char *b64 = 
            ((void *)0)
                ;

 if ((sbuf = sshbuf_fromb(sig)) == 
                                  ((void *)0)
                                      ) {
  sshlog("sshsig.c", __func__, 98, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshbuf_fromb failed");
  return -2;
 }

 if ((r = sshbuf_cmp(sbuf, 0,
     "-----BEGIN SSH SIGNATURE-----\n", sizeof("-----BEGIN SSH SIGNATURE-----\n")-1)) != 0) {
  sshlog("sshsig.c", __func__, 104, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Couldn't parse signature: missing header");
  goto done;
 }

 if ((r = sshbuf_consume(sbuf, sizeof("-----BEGIN SSH SIGNATURE-----\n")-1)) != 0) {
  sshlog("sshsig.c", __func__, 109, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "consume");
  goto done;
 }

 if ((r = sshbuf_find(sbuf, 0, "\n" "-----END SSH SIGNATURE-----",
     sizeof("\n" "-----END SSH SIGNATURE-----")-1, &eoffset)) != 0) {
  sshlog("sshsig.c", __func__, 115, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Couldn't parse signature: missing footer");
  goto done;
 }

 if ((r = sshbuf_consume_end(sbuf, sshbuf_len(sbuf)-eoffset)) != 0) {
  sshlog("sshsig.c", __func__, 120, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "consume");
  goto done;
 }

 if ((b64 = sshbuf_dup_string(sbuf)) == 
                                       ((void *)0)
                                           ) {
  sshlog("sshsig.c", __func__, 125, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshbuf_dup_string failed");
  r = -2;
  goto done;
 }

 if ((buf = sshbuf_new()) == 
                            ((void *)0)
                                ) {
  sshlog("sshsig.c", __func__, 131, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshbuf_new() failed");
  r = -2;
  goto done;
 }

 if ((r = sshbuf_b64tod(buf, b64)) != 0) {
  sshlog("sshsig.c", __func__, 137, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "decode base64");
  goto done;
 }


 *out = buf;
 r = 0;
 buf = 
      ((void *)0)
          ;
done:
 sshbuf_free(buf);
 sshbuf_free(sbuf);
 free(b64);
 return r;
}

static int
sshsig_wrap_sign(struct sshkey *key, const char *hashalg,
    const char *sk_provider, const char *sk_pin, const struct sshbuf *h_message,
    const char *sig_namespace, struct sshbuf **out,
    sshsig_signer *signer, void *signer_ctx)
{
 int r;
 size_t slen = 0;
 u_char *sig = 
              ((void *)0)
                  ;
 struct sshbuf *blob = 
                      ((void *)0)
                          ;
 struct sshbuf *tosign = 
                        ((void *)0)
                            ;
 const char *sign_alg = 
                       ((void *)0)
                           ;

 if ((tosign = sshbuf_new()) == 
                               ((void *)0) 
                                    ||
     (blob = sshbuf_new()) == 
                             ((void *)0)
                                 ) {
  sshlog("sshsig.c", __func__, 167, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshbuf_new failed");
  r = -2;
  goto done;
 }

 if ((r = sshbuf_put(tosign, "SSHSIG", (sizeof("SSHSIG") - 1))) != 0 ||
     (r = sshbuf_put_cstring(tosign, sig_namespace)) != 0 ||
     (r = sshbuf_put_string(tosign, 
                                   ((void *)0)
                                       , 0)) != 0 ||
     (r = sshbuf_put_cstring(tosign, hashalg)) != 0 ||
     (r = sshbuf_put_stringb(tosign, h_message)) != 0) {
  sshlog("sshsig.c", __func__, 177, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "assemble message to sign");
  goto done;
 }


 if (sshkey_type_plain(key->type) == KEY_RSA)
  sign_alg = "rsa-sha2-512";

 if (signer != 
              ((void *)0)
                  ) {
  if ((r = signer(key, &sig, &slen,
      sshbuf_ptr(tosign), sshbuf_len(tosign),
      sign_alg, sk_provider, sk_pin, 0, signer_ctx)) != 0) {
   sshlog("sshsig.c", __func__, 189, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Couldn't sign message (signer)");
   goto done;
  }
 } else {
  if ((r = sshkey_sign(key, &sig, &slen,
      sshbuf_ptr(tosign), sshbuf_len(tosign),
      sign_alg, sk_provider, sk_pin, 0)) != 0) {
   sshlog("sshsig.c", __func__, 196, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Couldn't sign message");
   goto done;
  }
 }

 if ((r = sshbuf_put(blob, "SSHSIG", (sizeof("SSHSIG") - 1))) != 0 ||
     (r = sshbuf_put_u32(blob, 0x01)) != 0 ||
     (r = sshkey_puts(key, blob)) != 0 ||
     (r = sshbuf_put_cstring(blob, sig_namespace)) != 0 ||
     (r = sshbuf_put_string(blob, 
                                 ((void *)0)
                                     , 0)) != 0 ||
     (r = sshbuf_put_cstring(blob, hashalg)) != 0 ||
     (r = sshbuf_put_string(blob, sig, slen)) != 0) {
  sshlog("sshsig.c", __func__, 208, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "assemble signature object");
  goto done;
 }

 if (out != 
           ((void *)0)
               ) {
  *out = blob;
  blob = 
        ((void *)0)
            ;
 }
 r = 0;
done:
 free(sig);
 sshbuf_free(blob);
 sshbuf_free(tosign);
 return r;
}


static int
sshsig_parse_preamble(struct sshbuf *buf)
{
 int r = -1;
 uint32_t sversion;

 if ((r = sshbuf_cmp(buf, 0, "SSHSIG", (sizeof("SSHSIG") - 1))) != 0 ||
     (r = sshbuf_consume(buf, (sizeof("SSHSIG")-1))) != 0 ||
     (r = sshbuf_get_u32(buf, &sversion)) != 0) {
  sshlog("sshsig.c", __func__, 234, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Couldn't verify signature: invalid format");
  return r;
 }

 if (sversion > 0x01) {
  sshlog("sshsig.c", __func__, 239, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Signature version %lu is larger than supported " "version %u", (unsigned long)sversion, 0x01)
                                                         ;
  return -4;
 }
 return 0;
}

static int
sshsig_check_hashalg(const char *hashalg)
{
 if (hashalg == 
               ((void *)0) 
                    ||
     match_pattern_list(hashalg, "sha256,sha512", 0) == 1)
  return 0;
 sshlog("sshsig.c", __func__, 252, 1, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "unsupported hash algorithm \"%.100s\"", hashalg);
 return -58;
}

static int
sshsig_peek_hashalg(struct sshbuf *signature, char **hashalgp)
{
 struct sshbuf *buf = 
                     ((void *)0)
                         ;
 char *hashalg = 
                ((void *)0)
                    ;
 int r = -1;

 if (hashalgp != 
                ((void *)0)
                    )
  *hashalgp = 
             ((void *)0)
                 ;
 if ((buf = sshbuf_fromb(signature)) == 
                                       ((void *)0)
                                           )
  return -2;
 if ((r = sshsig_parse_preamble(buf)) != 0)
  goto done;
 if ((r = sshbuf_get_string_direct(buf, 
                                       ((void *)0)
                                           , 
                                             ((void *)0)
                                                 )) != 0 ||
     (r = sshbuf_get_string_direct(buf, 
                                       ((void *)0)
                                           , 
                                             ((void *)0)
                                                 )) != 0 ||
     (r = sshbuf_get_string(buf, 
                                ((void *)0)
                                    , 
                                      ((void *)0)
                                          )) != 0 ||
     (r = sshbuf_get_cstring(buf, &hashalg, 
                                           ((void *)0)
                                               )) != 0 ||
     (r = sshbuf_get_string_direct(buf, 
                                       ((void *)0)
                                           , 
                                             ((void *)0)
                                                 )) != 0) {
  sshlog("sshsig.c", __func__, 274, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse signature object");
  goto done;
 }


 r = 0;
 *hashalgp = hashalg;
 hashalg = 
          ((void *)0)
              ;
 done:
 free(hashalg);
 sshbuf_free(buf);
 return r;
}

static int
sshsig_wrap_verify(struct sshbuf *signature, const char *hashalg,
    const struct sshbuf *h_message, const char *expect_namespace,
    struct sshkey **sign_keyp, struct sshkey_sig_details **sig_details)
{
 int r = -1;
 struct sshbuf *buf = 
                     ((void *)0)
                         , *toverify = 
                                       ((void *)0)
                                           ;
 struct sshkey *key = 
                     ((void *)0)
                         ;
 const u_char *sig;
 char *got_namespace = 
                      ((void *)0)
                          , *sigtype = 
                                       ((void *)0)
                                           , *sig_hashalg = 
                                                            ((void *)0)
                                                                ;
 size_t siglen;

 sshlog("sshsig.c", __func__, 300, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "verify message length %zu", sshbuf_len(h_message));
 if (sig_details != 
                   ((void *)0)
                       )
  *sig_details = 
                ((void *)0)
                    ;
 if (sign_keyp != 
                 ((void *)0)
                     )
  *sign_keyp = 
              ((void *)0)
                  ;

 if ((toverify = sshbuf_new()) == 
                                 ((void *)0)
                                     ) {
  sshlog("sshsig.c", __func__, 307, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshbuf_new failed");
  r = -2;
  goto done;
 }
 if ((r = sshbuf_put(toverify, "SSHSIG",
     (sizeof("SSHSIG") - 1))) != 0 ||
     (r = sshbuf_put_cstring(toverify, expect_namespace)) != 0 ||
     (r = sshbuf_put_string(toverify, 
                                     ((void *)0)
                                         , 0)) != 0 ||
     (r = sshbuf_put_cstring(toverify, hashalg)) != 0 ||
     (r = sshbuf_put_stringb(toverify, h_message)) != 0) {
  sshlog("sshsig.c", __func__, 317, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "assemble message to verify");
  goto done;
 }

 if ((r = sshsig_parse_preamble(signature)) != 0)
  goto done;

 if ((r = sshkey_froms(signature, &key)) != 0 ||
     (r = sshbuf_get_cstring(signature, &got_namespace, 
                                                       ((void *)0)
                                                           )) != 0 ||
     (r = sshbuf_get_string(signature, 
                                      ((void *)0)
                                          , 
                                            ((void *)0)
                                                )) != 0 ||
     (r = sshbuf_get_cstring(signature, &sig_hashalg, 
                                                     ((void *)0)
                                                         )) != 0 ||
     (r = sshbuf_get_string_direct(signature, &sig, &siglen)) != 0) {
  sshlog("sshsig.c", __func__, 329, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse signature object");
  goto done;
 }

 if (sshbuf_len(signature) != 0) {
  sshlog("sshsig.c", __func__, 334, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Signature contains trailing data");
  r = -4;
  goto done;
 }

 if (strcmp(expect_namespace, got_namespace) != 0) {
  sshlog("sshsig.c", __func__, 340, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Couldn't verify signature: namespace does not match");
  sshlog("sshsig.c", __func__, 341, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "expected namespace \"%s\" received \"%s\"", expect_namespace, got_namespace)
                                      ;
  r = -21;
  goto done;
 }
 if (strcmp(hashalg, sig_hashalg) != 0) {
  sshlog("sshsig.c", __func__, 347, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Couldn't verify signature: hash algorithm mismatch");
  sshlog("sshsig.c", __func__, 348, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "expected algorithm \"%s\" received \"%s\"", hashalg, sig_hashalg)
                           ;
  r = -21;
  goto done;
 }

 if (sshkey_type_plain(key->type) == KEY_RSA) {
  if ((r = sshkey_get_sigtype(sig, siglen, &sigtype)) != 0) {
   sshlog("sshsig.c", __func__, 356, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Couldn't verify signature: unable to get " "signature type")
                        ;
   goto done;
  }
  if (match_pattern_list(sigtype, "rsa-sha2-512,rsa-sha2-256", 0) != 1) {
   sshlog("sshsig.c", __func__, 361, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Couldn't verify signature: unsupported RSA " "signature algorithm %s", sigtype)
                                         ;
   r = -58;
   goto done;
  }
 }
 if ((r = sshkey_verify(key, sig, siglen, sshbuf_ptr(toverify),
     sshbuf_len(toverify), 
                          ((void *)0)
                              , 0, sig_details)) != 0) {
  sshlog("sshsig.c", __func__, 369, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Signature verification failed");
  goto done;
 }


 r = 0;
 if (sign_keyp != 
                 ((void *)0)
                     ) {
  *sign_keyp = key;
  key = 
       ((void *)0)
           ;
 }
done:
 free(got_namespace);
 free(sigtype);
 free(sig_hashalg);
 sshbuf_free(buf);
 sshbuf_free(toverify);
 sshkey_free(key);
 return r;
}

static int
hash_buffer(const struct sshbuf *m, const char *hashalg, struct sshbuf **bp)
{
 char *hex, hash[64];
 int alg, r = -1;
 struct sshbuf *b = 
                   ((void *)0)
                       ;

 *bp = 
      ((void *)0)
          ;
 memset(hash, 0, sizeof(hash));

 if ((r = sshsig_check_hashalg(hashalg)) != 0)
  return r;
 if ((alg = ssh_digest_alg_by_name(hashalg)) == -1) {
  sshlog("sshsig.c", __func__, 402, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "can't look up hash algorithm %s", hashalg);
  return -1;
 }
 if ((r = ssh_digest_buffer(alg, m, hash, sizeof(hash))) != 0) {
  sshlog("sshsig.c", __func__, 406, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "ssh_digest_buffer");
  return r;
 }
 if ((hex = tohex(hash, ssh_digest_bytes(alg))) != 
                                                  ((void *)0)
                                                      ) {
  sshlog("sshsig.c", __func__, 410, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "final hash: %s", hex);
  freezero(hex, strlen(hex));
 }
 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              ) {
  r = -2;
  goto out;
 }
 if ((r = sshbuf_put(b, hash, ssh_digest_bytes(alg))) != 0) {
  sshlog("sshsig.c", __func__, 418, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshbuf_put");
  goto out;
 }
 *bp = b;
 b = 
    ((void *)0)
        ;

 r = 0;
 out:
 sshbuf_free(b);
 explicit_bzero(hash, sizeof(hash));
 return r;
}

int
sshsig_signb(struct sshkey *key, const char *hashalg,
    const char *sk_provider, const char *sk_pin,
    const struct sshbuf *message, const char *sig_namespace,
    struct sshbuf **out, sshsig_signer *signer, void *signer_ctx)
{
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 int r = -1;

 if (hashalg == 
               ((void *)0)
                   )
  hashalg = "sha512";
 if (out != 
           ((void *)0)
               )
  *out = 
        ((void *)0)
            ;
 if ((r = hash_buffer(message, hashalg, &b)) != 0) {
  sshlog("sshsig.c", __func__, 445, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "hash buffer");
  goto out;
 }
 if ((r = sshsig_wrap_sign(key, hashalg, sk_provider, sk_pin, b,
     sig_namespace, out, signer, signer_ctx)) != 0)
  goto out;

 r = 0;
 out:
 sshbuf_free(b);
 return r;
}

int
sshsig_verifyb(struct sshbuf *signature, const struct sshbuf *message,
    const char *expect_namespace, struct sshkey **sign_keyp,
    struct sshkey_sig_details **sig_details)
{
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 int r = -1;
 char *hashalg = 
                ((void *)0)
                    ;

 if (sig_details != 
                   ((void *)0)
                       )
  *sig_details = 
                ((void *)0)
                    ;
 if (sign_keyp != 
                 ((void *)0)
                     )
  *sign_keyp = 
              ((void *)0)
                  ;
 if ((r = sshsig_peek_hashalg(signature, &hashalg)) != 0)
  return r;
 sshlog("sshsig.c", __func__, 473, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "signature made with hash \"%s\"", hashalg);
 if ((r = hash_buffer(message, hashalg, &b)) != 0) {
  sshlog("sshsig.c", __func__, 475, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "hash buffer");
  goto out;
 }
 if ((r = sshsig_wrap_verify(signature, hashalg, b, expect_namespace,
     sign_keyp, sig_details)) != 0)
  goto out;

 r = 0;
 out:
 sshbuf_free(b);
 free(hashalg);
 return r;
}

static int
hash_file(int fd, const char *hashalg, struct sshbuf **bp)
{
 char *hex, rbuf[8192], hash[64];
 ssize_t n, total = 0;
 struct ssh_digest_ctx *ctx = 
                             ((void *)0)
                                 ;
 int alg, oerrno, r = -1;
 struct sshbuf *b = 
                   ((void *)0)
                       ;

 *bp = 
      ((void *)0)
          ;
 memset(hash, 0, sizeof(hash));

 if ((r = sshsig_check_hashalg(hashalg)) != 0)
  return r;
 if ((alg = ssh_digest_alg_by_name(hashalg)) == -1) {
  sshlog("sshsig.c", __func__, 504, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "can't look up hash algorithm %s", hashalg);
  return -1;
 }
 if ((ctx = ssh_digest_start(alg)) == 
                                     ((void *)0)
                                         ) {
  sshlog("sshsig.c", __func__, 508, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "ssh_digest_start failed");
  return -1;
 }
 for (;;) {
  if ((n = read(fd, rbuf, sizeof(rbuf))) == -1) {
   if (
      (*__errno_location ()) 
            == 
               4 
                     || 
                        (*__errno_location ()) 
                              == 
                                 11
                                       )
    continue;
   oerrno = 
           (*__errno_location ())
                ;
   sshlog("sshsig.c", __func__, 516, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "read: %s", strerror(
  (*__errno_location ())
  ));
   
  (*__errno_location ()) 
        = oerrno;
   r = -24;
   goto out;
  } else if (n == 0) {
   sshlog("sshsig.c", __func__, 521, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "hashed %zu bytes", total);
   break;
  }
  total += (size_t)n;
  if ((r = ssh_digest_update(ctx, rbuf, (size_t)n)) != 0) {
   sshlog("sshsig.c", __func__, 526, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "ssh_digest_update");
   goto out;
  }
 }
 if ((r = ssh_digest_final(ctx, hash, sizeof(hash))) != 0) {
  sshlog("sshsig.c", __func__, 531, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "ssh_digest_final");
  goto out;
 }
 if ((hex = tohex(hash, ssh_digest_bytes(alg))) != 
                                                  ((void *)0)
                                                      ) {
  sshlog("sshsig.c", __func__, 535, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "final hash: %s", hex);
  freezero(hex, strlen(hex));
 }
 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              ) {
  r = -2;
  goto out;
 }
 if ((r = sshbuf_put(b, hash, ssh_digest_bytes(alg))) != 0) {
  sshlog("sshsig.c", __func__, 543, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshbuf_put");
  goto out;
 }
 *bp = b;
 b = 
    ((void *)0)
        ;

 r = 0;
 out:
 oerrno = 
         (*__errno_location ())
              ;
 sshbuf_free(b);
 ssh_digest_free(ctx);
 explicit_bzero(hash, sizeof(hash));
 
(*__errno_location ()) 
      = oerrno;
 return r;
}

int
sshsig_sign_fd(struct sshkey *key, const char *hashalg,
    const char *sk_provider, const char *sk_pin,
    int fd, const char *sig_namespace, struct sshbuf **out,
    sshsig_signer *signer, void *signer_ctx)
{
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 int r = -1;

 if (hashalg == 
               ((void *)0)
                   )
  hashalg = "sha512";
 if (out != 
           ((void *)0)
               )
  *out = 
        ((void *)0)
            ;
 if ((r = hash_file(fd, hashalg, &b)) != 0) {
  sshlog("sshsig.c", __func__, 573, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "hash_file");
  return r;
 }
 if ((r = sshsig_wrap_sign(key, hashalg, sk_provider, sk_pin, b,
     sig_namespace, out, signer, signer_ctx)) != 0)
  goto out;

 r = 0;
 out:
 sshbuf_free(b);
 return r;
}

int
sshsig_verify_fd(struct sshbuf *signature, int fd,
    const char *expect_namespace, struct sshkey **sign_keyp,
    struct sshkey_sig_details **sig_details)
{
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 int r = -1;
 char *hashalg = 
                ((void *)0)
                    ;

 if (sig_details != 
                   ((void *)0)
                       )
  *sig_details = 
                ((void *)0)
                    ;
 if (sign_keyp != 
                 ((void *)0)
                     )
  *sign_keyp = 
              ((void *)0)
                  ;
 if ((r = sshsig_peek_hashalg(signature, &hashalg)) != 0)
  return r;
 sshlog("sshsig.c", __func__, 601, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "signature made with hash \"%s\"", hashalg);
 if ((r = hash_file(fd, hashalg, &b)) != 0) {
  sshlog("sshsig.c", __func__, 603, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "hash_file");
  goto out;
 }
 if ((r = sshsig_wrap_verify(signature, hashalg, b, expect_namespace,
     sign_keyp, sig_details)) != 0)
  goto out;

 r = 0;
 out:
 sshbuf_free(b);
 free(hashalg);
 return r;
}

struct sshsigopt {
 int ca;
 char *namespaces;
 uint64_t valid_after, valid_before;
};

struct sshsigopt *
sshsigopt_parse(const char *opts, const char *path, u_long linenum,
    const char **errstrp)
{
 struct sshsigopt *ret;
 int r;
 char *opt;
 const char *errstr = 
                     ((void *)0)
                         ;

 if ((ret = calloc(1, sizeof(*ret))) == 
                                       ((void *)0)
                                           )
  return 
        ((void *)0)
            ;
 if (opts == 
            ((void *)0) 
                 || *opts == '\0')
  return ret;

 while (*opts && *opts != ' ' && *opts != '\t') {

  if ((r = opt_flag("cert-authority", 0, &opts)) != -1) {
   ret->ca = 1;
  } else if (opt_match(&opts, "namespaces")) {
   if (ret->namespaces != 
                         ((void *)0)
                             ) {
    errstr = "multiple \"namespaces\" clauses";
    goto fail;
   }
   ret->namespaces = opt_dequote(&opts, &errstr);
   if (ret->namespaces == 
                         ((void *)0)
                             )
    goto fail;
  } else if (opt_match(&opts, "valid-after")) {
   if (ret->valid_after != 0) {
    errstr = "multiple \"valid-after\" clauses";
    goto fail;
   }
   if ((opt = opt_dequote(&opts, &errstr)) == 
                                             ((void *)0)
                                                 )
    goto fail;
   if (parse_absolute_time(opt, &ret->valid_after) != 0 ||
       ret->valid_after == 0) {
    free(opt);
    errstr = "invalid \"valid-after\" time";
    goto fail;
   }
   free(opt);
  } else if (opt_match(&opts, "valid-before")) {
   if (ret->valid_before != 0) {
    errstr = "multiple \"valid-before\" clauses";
    goto fail;
   }
   if ((opt = opt_dequote(&opts, &errstr)) == 
                                             ((void *)0)
                                                 )
    goto fail;
   if (parse_absolute_time(opt, &ret->valid_before) != 0 ||
       ret->valid_before == 0) {
    free(opt);
    errstr = "invalid \"valid-before\" time";
    goto fail;
   }
   free(opt);
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

 if (ret->valid_after != 0 && ret->valid_before != 0 &&
     ret->valid_before <= ret->valid_after) {
  errstr = "\"valid-before\" time is before \"valid-after\"";
  goto fail;
 }

 return ret;
 fail:
 if (errstrp != 
               ((void *)0)
                   )
  *errstrp = errstr;
 sshsigopt_free(ret);
 return 
       ((void *)0)
           ;
}

void
sshsigopt_free(struct sshsigopt *opts)
{
 if (opts == 
            ((void *)0)
                )
  return;
 free(opts->namespaces);
 free(opts);
}

static int
parse_principals_key_and_options(const char *path, u_long linenum, char *line,
    const char *required_principal, char **principalsp, struct sshkey **keyp,
    struct sshsigopt **sigoptsp)
{
 char *opts = 
             ((void *)0)
                 , *tmp, *cp, *principals = 
                                            ((void *)0)
                                                ;
 const char *reason = 
                     ((void *)0)
                         ;
 struct sshsigopt *sigopts = 
                            ((void *)0)
                                ;
 struct sshkey *key = 
                     ((void *)0)
                         ;
 int r = -1;

 if (principalsp != 
                   ((void *)0)
                       )
  *principalsp = 
                ((void *)0)
                    ;
 if (sigoptsp != 
                ((void *)0)
                    )
  *sigoptsp = 
             ((void *)0)
                 ;
 if (keyp != 
            ((void *)0)
                )
  *keyp = 
         ((void *)0)
             ;

 cp = line;
 cp = cp + strspn(cp, " \t");
 if (*cp == '#' || *cp == '\0')
  return -46;


 if ((tmp = strdelimw(&cp)) == 
                              ((void *)0) 
                                   || cp == 
                                            ((void *)0)
                                                ) {
  sshlog("sshsig.c", __func__, 744, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s:%lu: invalid line", path, linenum);
  r = -4;
  goto out;
 }
 if ((principals = strdup(tmp)) == 
                                  ((void *)0)
                                      ) {
  sshlog("sshsig.c", __func__, 749, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "strdup failed");
  r = -2;
  goto out;
 }




 if (required_principal != 
                          ((void *)0)
                              ) {
  if (match_pattern_list(required_principal,
      principals, 0) != 1) {

   r = -46;
   goto out;
  }
  sshlog("sshsig.c", __func__, 764, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%s:%lu: matched principal \"%s\"", path, linenum, required_principal)
                                        ;
 }

 if ((key = sshkey_new(KEY_UNSPEC)) == 
                                      ((void *)0)
                                          ) {
  sshlog("sshsig.c", __func__, 769, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshkey_new failed");
  r = -2;
  goto out;
 }
 if (sshkey_read(key, &cp) != 0) {

  opts = cp;
  if (sshkey_advance_past_options(&cp) != 0) {
   sshlog("sshsig.c", __func__, 777, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s:%lu: invalid options", path, linenum);
   r = -4;
   goto out;
  }
  if (cp == 
           ((void *)0) 
                || *cp == '\0') {
   sshlog("sshsig.c", __func__, 782, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s:%lu: missing key", path, linenum);
   r = -4;
   goto out;
  }
  *cp++ = '\0';
  skip_space(&cp);
  if (sshkey_read(key, &cp) != 0) {
   sshlog("sshsig.c", __func__, 789, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s:%lu: invalid key", path, linenum);
   r = -4;
   goto out;
  }
 }
 sshlog("sshsig.c", __func__, 794, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s:%lu: options %s", path, linenum, opts == 
((void *)0) 
? "" : opts);
 if ((sigopts = sshsigopt_parse(opts, path, linenum, &reason)) == 
                                                                 ((void *)0)
                                                                     ) {
  sshlog("sshsig.c", __func__, 796, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s:%lu: bad options: %s", path, linenum, reason);
  r = -4;
  goto out;
 }

 if (principalsp != 
                   ((void *)0)
                       ) {
  *principalsp = principals;
  principals = 
              ((void *)0)
                  ;
 }
 if (sigoptsp != 
                ((void *)0)
                    ) {
  *sigoptsp = sigopts;
  sigopts = 
           ((void *)0)
               ;
 }
 if (keyp != 
            ((void *)0)
                ) {
  *keyp = key;
  key = 
       ((void *)0)
           ;
 }
 r = 0;
 out:
 free(principals);
 sshsigopt_free(sigopts);
 sshkey_free(key);
 return r;
}

static int
cert_filter_principals(const char *path, u_long linenum,
    char **principalsp, const struct sshkey *cert, uint64_t verify_time)
{
 char *cp, *oprincipals, *principals;
 const char *reason;
 struct sshbuf *nprincipals;
 int r = -1, success = 0;
 u_int i;

 oprincipals = principals = *principalsp;
 *principalsp = 
               ((void *)0)
                   ;

 if ((nprincipals = sshbuf_new()) == 
                                    ((void *)0)
                                        ) {
  r = -2;
  goto out;
 }

 while ((cp = strsep(&principals, ",")) != 
                                          ((void *)0) 
                                               && *cp != '\0') {

  if ((r = sshkey_cert_check_authority(cert, 0, 1, 0,
      verify_time, 
                  ((void *)0)
                      , &reason)) != 0) {
   sshlog("sshsig.c", __func__, 843, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "%s:%lu: principal \"%s\" not authorized: %s", path, linenum, cp, reason)
                                 ;
   continue;
  }

  for (i = 0; i < cert->cert->nprincipals; i++) {
   if (match_pattern(cert->cert->principals[i], cp)) {
    if ((r = sshbuf_putf(nprincipals, "%s%s",
     sshbuf_len(nprincipals) != 0 ? "," : "",
      cert->cert->principals[i])) != 0) {
     sshlog("sshsig.c", __func__, 853, 1, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "buffer error");
     goto out;
    }
   }
  }
 }
 if (sshbuf_len(nprincipals) == 0) {
  sshlog("sshsig.c", __func__, 860, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s:%lu: no valid principals found", path, linenum);
  r = -25;
  goto out;
 }
 if ((principals = sshbuf_dup_string(nprincipals)) == 
                                                     ((void *)0)
                                                         ) {
  sshlog("sshsig.c", __func__, 865, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "buffer error");
  goto out;
 }

 success = 1;
 *principalsp = principals;
 out:
 sshbuf_free(nprincipals);
 free(oprincipals);
 return success ? 0 : r;
}

static int
check_allowed_keys_line(const char *path, u_long linenum, char *line,
    const struct sshkey *sign_key, const char *principal,
    const char *sig_namespace, uint64_t verify_time, char **principalsp)
{
 struct sshkey *found_key = 
                           ((void *)0)
                               ;
 char *principals = 
                   ((void *)0)
                       ;
 int r, success = 0;
 const char *reason = 
                     ((void *)0)
                         ;
 struct sshsigopt *sigopts = 
                            ((void *)0)
                                ;
 char tvalid[64], tverify[64];

 if (principalsp != 
                   ((void *)0)
                       )
  *principalsp = 
                ((void *)0)
                    ;


 if ((r = parse_principals_key_and_options(path, linenum, line,
     principal, &principals, &found_key, &sigopts)) != 0) {

  goto done;
 }

 if (!sigopts->ca && sshkey_equal(found_key, sign_key)) {

  sshlog("sshsig.c", __func__, 901, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%s:%lu: matched key", path, linenum);
 } else if (sigopts->ca && sshkey_is_cert(sign_key) &&
     sshkey_equal_public(sign_key->cert->signature_key, found_key)) {
  if (principal) {

   if ((r = sshkey_cert_check_authority(sign_key, 0, 1, 0,
       verify_time, principal, &reason)) != 0) {
    sshlog("sshsig.c", __func__, 908, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%s:%lu: certificate not authorized: %s", path, linenum, reason)
                              ;
    goto done;
   }
   sshlog("sshsig.c", __func__, 912, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "%s:%lu: matched certificate CA key", path, linenum)
                     ;
  } else {

   if ((r = cert_filter_principals(path, linenum,
       &principals, sign_key, verify_time)) != 0) {

    sshlog("sshsig.c", __func__, 919, 0, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "%s:%lu: cert_filter_principals", path, linenum)
                      ;
    goto done;
   }
   sshlog("sshsig.c", __func__, 923, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "%s:%lu: matched certificate CA key", path, linenum)
                     ;
  }
 } else {

  goto done;
 }


 if (sigopts->namespaces != 
                           ((void *)0) 
                                && sig_namespace != 
                                                    ((void *)0) 
                                                         &&
     match_pattern_list(sig_namespace, sigopts->namespaces, 0) != 1) {
  sshlog("sshsig.c", __func__, 934, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s:%lu: key is not permitted for use in signature " "namespace \"%s\"", path, linenum, sig_namespace)
                                                       ;
  goto done;
 }


 format_absolute_time((uint64_t)verify_time, tverify, sizeof(tverify));
 if (sigopts->valid_after != 0 &&
     (uint64_t)verify_time < sigopts->valid_after) {
  format_absolute_time(sigopts->valid_after,
      tvalid, sizeof(tvalid));
  sshlog("sshsig.c", __func__, 945, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s:%lu: key is not yet valid: " "verify time %s < valid-after %s", path, linenum, tverify, tvalid)

                      ;
  goto done;
 }
 if (sigopts->valid_before != 0 &&
     (uint64_t)verify_time > sigopts->valid_before) {
  format_absolute_time(sigopts->valid_before,
      tvalid, sizeof(tvalid));
  sshlog("sshsig.c", __func__, 954, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s:%lu: key has expired: " "verify time %s > valid-before %s", path, linenum, tverify, tvalid)

                      ;
  goto done;
 }
 success = 1;

 done:
 if (success && principalsp != 
                              ((void *)0)
                                  ) {
  *principalsp = principals;
  principals = 
              ((void *)0)
                  ;
 }
 free(principals);
 sshkey_free(found_key);
 sshsigopt_free(sigopts);
 return success ? 0 : -46;
}

int
sshsig_check_allowed_keys(const char *path, const struct sshkey *sign_key,
    const char *principal, const char *sig_namespace, uint64_t verify_time)
{
 FILE *f = 
          ((void *)0)
              ;
 char *line = 
             ((void *)0)
                 ;
 size_t linesize = 0;
 u_long linenum = 0;
 int r = -1, oerrno;


 if ((f = fopen(path, "r")) == 
                              ((void *)0)
                                  ) {
  oerrno = 
          (*__errno_location ())
               ;
  sshlog("sshsig.c", __func__, 985, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Unable to open allowed keys file \"%s\": %s", path, strerror(
 (*__errno_location ())
 ))
                            ;
  
 (*__errno_location ()) 
       = oerrno;
  return -24;
 }

 while (getline(&line, &linesize, f) != -1) {
  linenum++;
  r = check_allowed_keys_line(path, linenum, line, sign_key,
      principal, sig_namespace, verify_time, 
                                            ((void *)0)
                                                );
  free(line);
  line = 
        ((void *)0)
            ;
  linesize = 0;
  if (r == -46)
   continue;
  else if (r == 0) {

   fclose(f);
   return 0;
  } else
   break;
 }

 fclose(f);
 free(line);
 return r == 0 ? -46 : r;
}

int
sshsig_find_principals(const char *path, const struct sshkey *sign_key,
    uint64_t verify_time, char **principals)
{
 FILE *f = 
          ((void *)0)
              ;
 char *line = 
             ((void *)0)
                 ;
 size_t linesize = 0;
 u_long linenum = 0;
 int r = -1, oerrno;

 if ((f = fopen(path, "r")) == 
                              ((void *)0)
                                  ) {
  oerrno = 
          (*__errno_location ())
               ;
  sshlog("sshsig.c", __func__, 1025, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Unable to open allowed keys file \"%s\": %s", path, strerror(
 (*__errno_location ())
 ))
                            ;
  
 (*__errno_location ()) 
       = oerrno;
  return -24;
 }

 r = -46;
 while (getline(&line, &linesize, f) != -1) {
  linenum++;
  r = check_allowed_keys_line(path, linenum, line,
      sign_key, 
               ((void *)0)
                   , 
                     ((void *)0)
                         , verify_time, principals);
  free(line);
  line = 
        ((void *)0)
            ;
  linesize = 0;
  if (r == -46)
   continue;
  else if (r == 0) {

   fclose(f);
   return 0;
  } else
   break;
 }
 free(line);

 if (ferror(f) != 0) {
  oerrno = 
          (*__errno_location ())
               ;
  fclose(f);
  sshlog("sshsig.c", __func__, 1053, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Unable to read allowed keys file \"%s\": %s", path, strerror(
 (*__errno_location ())
 ))
                            ;
  
 (*__errno_location ()) 
       = oerrno;
  return -24;
 }
 fclose(f);
 return r == 0 ? -46 : r;
}

int
sshsig_match_principals(const char *path, const char *principal,
    char ***principalsp, size_t *nprincipalsp)
{
 FILE *f = 
          ((void *)0)
              ;
 char *found, *line = 
                     ((void *)0)
                         , **principals = 
                                          ((void *)0)
                                              , **tmp;
 size_t i, nprincipals = 0, linesize = 0;
 u_long linenum = 0;
 int oerrno = 0, r, ret = 0;

 if (principalsp != 
                   ((void *)0)
                       )
  *principalsp = 
                ((void *)0)
                    ;
 if (nprincipalsp != 
                    ((void *)0)
                        )
  *nprincipalsp = 0;


 if ((f = fopen(path, "r")) == 
                              ((void *)0)
                                  ) {
  oerrno = 
          (*__errno_location ())
               ;
  sshlog("sshsig.c", __func__, 1080, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Unable to open allowed keys file \"%s\": %s", path, strerror(
 (*__errno_location ())
 ))
                            ;
  
 (*__errno_location ()) 
       = oerrno;
  return -24;
 }

 while (getline(&line, &linesize, f) != -1) {
  linenum++;

  if ((r = parse_principals_key_and_options(path, linenum, line,
      principal, &found, 
                        ((void *)0)
                            , 
                              ((void *)0)
                                  )) != 0) {
   if (r == -46)
    continue;
   ret = r;
   oerrno = 
           (*__errno_location ())
                ;
   break;
  }
  if ((tmp = recallocarray(principals, nprincipals,
      nprincipals + 1, sizeof(*principals))) == 
                                               ((void *)0)
                                                   ) {
   ret = -2;
   free(found);
   break;
  }
  principals = tmp;
  principals[nprincipals++] = found;
  free(line);
  line = 
        ((void *)0)
            ;
  linesize = 0;
 }
 fclose(f);

 if (ret == 0) {
  if (nprincipals == 0)
   ret = -46;
  if (principalsp != 
                    ((void *)0)
                        ) {
   *principalsp = principals;
   principals = 
               ((void *)0)
                   ;
  }
  if (nprincipalsp != 0) {
   *nprincipalsp = nprincipals;
   nprincipals = 0;
  }
 }

 for (i = 0; i < nprincipals; i++)
  free(principals[i]);
 free(principals);

 
(*__errno_location ()) 
      = oerrno;
 return ret;
}

int
sshsig_get_pubkey(struct sshbuf *signature, struct sshkey **pubkey)
{
 struct sshkey *pk = 
                    ((void *)0)
                        ;
 int r = -21;

 if (pubkey == 
              ((void *)0)
                  )
  return -1;
 if ((r = sshsig_parse_preamble(signature)) != 0)
  return r;
 if ((r = sshkey_froms(signature, &pk)) != 0)
  return r;

 *pubkey = pk;
 pk = 
     ((void *)0)
         ;
 return 0;
}
