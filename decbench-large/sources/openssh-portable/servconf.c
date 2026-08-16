











































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
struct ssh;
struct fwd_perm_list;






struct queued_listenaddr {
 char *addr;
 int port;
 char *rdomain;
};


struct listenaddr {
 char *rdomain;
 struct addrinfo *addrs;
};

typedef struct {
 u_int num_ports;
 u_int ports_from_cmdline;
 int ports[256];
 struct queued_listenaddr *queued_listen_addrs;
 u_int num_queued_listens;
 struct listenaddr *listen_addrs;
 u_int num_listen_addrs;
 int address_family;

 char *routing_domain;

 char **host_key_files;
 int *host_key_file_userprovided;
 u_int num_host_key_files;
 char **host_cert_files;
 u_int num_host_cert_files;

 char *host_key_agent;
 char *pid_file;
 char *moduli_file;
 int login_grace_time;

 int permit_root_login;
 int ignore_rhosts;
 int ignore_user_known_hosts;

 int print_motd;
 int print_lastlog;
 int x11_forwarding;
 int x11_display_offset;

 int x11_use_localhost;
 char *xauth_location;
 int permit_tty;
 int permit_user_rc;
 int strict_modes;
 int tcp_keep_alive;
 int ip_qos_interactive;
 int ip_qos_bulk;
 char *ciphers;
 char *macs;
 char *kex_algorithms;
 struct ForwardOptions fwd_opts;
 SyslogFacility log_facility;
 LogLevel log_level;
 u_int num_log_verbose;
 char **log_verbose;
 int hostbased_authentication;
 int hostbased_uses_name_from_packet_only;
 char *hostbased_accepted_algos;
 char *hostkeyalgorithms;
 char *ca_sign_algorithms;
 int pubkey_authentication;
 char *pubkey_accepted_algos;
 int pubkey_auth_options;
 int kerberos_authentication;

 int kerberos_or_local_passwd;




 int kerberos_ticket_cleanup;

 int kerberos_get_afs_token;

 int gss_authentication;
 int gss_cleanup_creds;
 int gss_strict_acceptor;
 int password_authentication;

 int kbd_interactive_authentication;
 int permit_empty_passwd;

 int permit_user_env;
 char *permit_user_env_allowlist;
 int compression;
 int allow_tcp_forwarding;
 int allow_streamlocal_forwarding;
 int allow_agent_forwarding;
 int disable_forwarding;
 u_int num_allow_users;
 char **allow_users;
 u_int num_deny_users;
 char **deny_users;
 u_int num_allow_groups;
 char **allow_groups;
 u_int num_deny_groups;
 char **deny_groups;

 u_int num_subsystems;
 char *subsystem_name[256];
 char *subsystem_command[256];
 char *subsystem_args[256];

 u_int num_accept_env;
 char **accept_env;
 u_int num_setenv;
 char **setenv;

 int max_startups_begin;
 int max_startups_rate;
 int max_startups;
 int per_source_max_startups;
 int per_source_masklen_ipv4;
 int per_source_masklen_ipv6;
 int max_authtries;
 int max_sessions;
 char *banner;
 int use_dns;
 int client_alive_interval;



 int client_alive_count_max;





 u_int num_authkeys_files;
 char **authorized_keys_files;

 char *adm_forced_command;

 int use_pam;

 int permit_tun;

 char **permitted_opens;
 u_int num_permitted_opens;
 char **permitted_listens;
 u_int num_permitted_listens;

 char *chroot_directory;
 char *revoked_keys_file;
 char *trusted_user_ca_keys;
 char *authorized_keys_command;
 char *authorized_keys_command_user;
 char *authorized_principals_file;
 char *authorized_principals_command;
 char *authorized_principals_command_user;

 int64_t rekey_limit;
 int rekey_interval;

 char *version_addendum;

 u_int num_auth_methods;
 char **auth_methods;

 int fingerprint_hash;
 int expose_userauth_info;
 u_int64_t timing_secret;
 char *sk_provider;
 int required_rsa_size;
} ServerOptions;


struct connection_info {
 const char *user;
 const char *host;
 const char *address;
 const char *laddress;
 int lport;
 const char *rdomain;
 int test;

};


struct include_item {
 char *selector;
 char *filename;
 struct sshbuf *contents;
 struct { struct include_item *tqe_next; struct include_item **tqe_prev; } entry;
};
struct include_list { struct include_item *tqh_first; struct include_item **tqh_last; };
struct connection_info *get_connection_info(struct ssh *, int, int);
void initialize_server_options(ServerOptions *);
void fill_default_server_options(ServerOptions *);
int process_server_config_line(ServerOptions *, char *, const char *, int,
     int *, struct connection_info *, struct include_list *includes);
void process_permitopen(struct ssh *ssh, ServerOptions *options);
void load_server_config(const char *, struct sshbuf *);
void parse_server_config(ServerOptions *, const char *, struct sshbuf *,
     struct include_list *includes, struct connection_info *, int);
void parse_server_match_config(ServerOptions *,
     struct include_list *includes, struct connection_info *);
int parse_server_match_testspec(struct connection_info *, char *);
int server_match_spec_complete(struct connection_info *);
void copy_set_server_options(ServerOptions *, ServerOptions *, int);
void dump_config(ServerOptions *);
char *derelativise_path(const char *);
void servconf_add_hostkey(const char *, const int,
     ServerOptions *, const char *path, int);
void servconf_add_hostcert(const char *, const int,
     ServerOptions *, const char *path);
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
struct ssh;
struct Channel;
typedef struct Channel Channel;
struct fwd_perm_list;

typedef void channel_open_fn(struct ssh *, int, int, void *);
typedef void channel_callback_fn(struct ssh *, int, void *);
typedef int channel_infilter_fn(struct ssh *, struct Channel *, char *, int);
typedef void channel_filter_cleanup_fn(struct ssh *, int, void *);
typedef u_char *channel_outfilter_fn(struct ssh *, struct Channel *,
    u_char **, size_t *);


typedef void channel_confirm_cb(struct ssh *, int, struct Channel *, void *);
typedef void channel_confirm_abandon_cb(struct ssh *, struct Channel *, void *);
struct channel_confirm {
 struct { struct channel_confirm *tqe_next; struct channel_confirm **tqe_prev; } entry;
 channel_confirm_cb *cb;
 channel_confirm_abandon_cb *abandon_cb;
 void *ctx;
};
struct channel_confirms { struct channel_confirm *tqh_first; struct channel_confirm **tqh_last; };


struct channel_connect {
 char *host;
 int port;
 struct addrinfo *ai, *aitop;
};


typedef int mux_callback_fn(struct ssh *, struct Channel *);
struct Channel {
 int type;

 int self;
 uint32_t remote_id;
 int have_remote_id;

 u_int istate;
 u_int ostate;
 int flags;
 int rfd;
 int wfd;
 int efd;
 int sock;
 u_int io_want;
 u_int io_ready;
 int pfds[4];
 int ctl_chan;
 int isatty;



 int client_tty;
 int force_drain;
 time_t notbefore;
 int delayed;




 int restore_block;
 struct sshbuf *input;

 struct sshbuf *output;

 struct sshbuf *extended;

 char *path;

 int listening_port;
 char *listening_addr;
 int host_port;
 char *remote_name;

 u_int remote_window;
 u_int remote_maxpacket;
 u_int local_window;
 u_int local_window_max;
 u_int local_consumed;
 u_int local_maxpacket;
 int extended_usage;
 int single_connection;

 char *ctype;


 channel_open_fn *open_confirm;
 void *open_confirm_ctx;
 channel_callback_fn *detach_user;
 int detach_close;
 struct channel_confirms status_confirms;


 channel_infilter_fn *input_filter;
 channel_outfilter_fn *output_filter;
 void *filter_ctx;
 channel_filter_cleanup_fn *filter_cleanup;


 int datagram;



 struct channel_connect connect_ctx;


 mux_callback_fn *mux_rcb;
 void *mux_ctx;
 int mux_pause;
 int mux_downstream_id;
};
void channel_init_channels(struct ssh *ssh);



Channel *channel_by_id(struct ssh *, int);
Channel *channel_by_remote_id(struct ssh *, u_int);
Channel *channel_lookup(struct ssh *, int);
Channel *channel_new(struct ssh *, char *, int, int, int, int,
     u_int, u_int, int, const char *, int);
void channel_set_fds(struct ssh *, int, int, int, int, int,
     int, int, u_int);
void channel_free(struct ssh *, Channel *);
void channel_free_all(struct ssh *);
void channel_stop_listening(struct ssh *);

void channel_send_open(struct ssh *, int);
void channel_request_start(struct ssh *, int, char *, int);
void channel_register_cleanup(struct ssh *, int,
     channel_callback_fn *, int);
void channel_register_open_confirm(struct ssh *, int,
     channel_open_fn *, void *);
void channel_register_filter(struct ssh *, int, channel_infilter_fn *,
     channel_outfilter_fn *, channel_filter_cleanup_fn *, void *);
void channel_register_status_confirm(struct ssh *, int,
     channel_confirm_cb *, channel_confirm_abandon_cb *, void *);
void channel_cancel_cleanup(struct ssh *, int);
int channel_close_fd(struct ssh *, Channel *, int *);
void channel_send_window_changes(struct ssh *);



int channel_proxy_downstream(struct ssh *, Channel *mc);
int channel_proxy_upstream(Channel *, int, u_int32_t, struct ssh *);



int channel_input_data(int, u_int32_t, struct ssh *);
int channel_input_extended_data(int, u_int32_t, struct ssh *);
int channel_input_ieof(int, u_int32_t, struct ssh *);
int channel_input_oclose(int, u_int32_t, struct ssh *);
int channel_input_open_confirmation(int, u_int32_t, struct ssh *);
int channel_input_open_failure(int, u_int32_t, struct ssh *);
int channel_input_port_open(int, u_int32_t, struct ssh *);
int channel_input_window_adjust(int, u_int32_t, struct ssh *);
int channel_input_status_confirm(int, u_int32_t, struct ssh *);


struct pollfd;

void channel_prepare_poll(struct ssh *, struct pollfd **,
     u_int *, u_int *, u_int, time_t *);
void channel_after_poll(struct ssh *, struct pollfd *, u_int);
void channel_output_poll(struct ssh *);

int channel_not_very_much_buffered_data(struct ssh *);
void channel_close_all(struct ssh *);
int channel_still_open(struct ssh *);
const char *channel_format_extended_usage(const Channel *);
char *channel_open_message(struct ssh *);
int channel_find_open(struct ssh *);


struct Forward;
struct ForwardOptions;
void channel_set_af(struct ssh *, int af);
void channel_permit_all(struct ssh *, int);
void channel_add_permission(struct ssh *, int, int, char *, int);
void channel_clear_permission(struct ssh *, int, int);
void channel_disable_admin(struct ssh *, int);
void channel_update_permission(struct ssh *, int, int);
Channel *channel_connect_to_port(struct ssh *, const char *, u_short,
     char *, char *, int *, const char **);
Channel *channel_connect_to_path(struct ssh *, const char *, char *, char *);
Channel *channel_connect_stdio_fwd(struct ssh *, const char*,
     u_short, int, int, int);
Channel *channel_connect_by_listen_address(struct ssh *, const char *,
     u_short, char *, char *);
Channel *channel_connect_by_listen_path(struct ssh *, const char *,
     char *, char *);
int channel_request_remote_forwarding(struct ssh *, struct Forward *);
int channel_setup_local_fwd_listener(struct ssh *, struct Forward *,
     struct ForwardOptions *);
int channel_request_rforward_cancel(struct ssh *, struct Forward *);
int channel_setup_remote_fwd_listener(struct ssh *, struct Forward *,
     int *, struct ForwardOptions *);
int channel_cancel_rport_listener(struct ssh *, struct Forward *);
int channel_cancel_lport_listener(struct ssh *, struct Forward *,
     int, struct ForwardOptions *);
int permitopen_port(const char *);



void channel_set_x11_refuse_time(struct ssh *, u_int);
int x11_connect_display(struct ssh *);
int x11_create_display_inet(struct ssh *, int, int, int, u_int *, int **);
void x11_request_forwarding_with_spoofing(struct ssh *, int,
     const char *, const char *, const char *, int);



int chan_is_dead(struct ssh *, Channel *, int);
void chan_mark_dead(struct ssh *, Channel *);



void chan_rcvd_oclose(struct ssh *, Channel *);
void chan_rcvd_eow(struct ssh *, Channel *);
void chan_read_failed(struct ssh *, Channel *);
void chan_ibuf_empty(struct ssh *, Channel *);
void chan_rcvd_ieof(struct ssh *, Channel *);
void chan_write_failed(struct ssh *, Channel *);
void chan_obuf_empty(struct ssh *, Channel *);
int ga_init(const char *, gid_t);
int ga_match(char * const *, int);
int ga_match_pattern_list(const char *);
void ga_free(void);
char *get_peer_ipaddr(int);
int get_peer_port(int);
char *get_local_ipaddr(int);
char *get_local_name(int);
int get_local_port(int);



void ipv64_normalise_mapped(struct sockaddr_storage *, socklen_t *);
struct kex;
struct sshkey;
struct sshbuf;
struct session_state;

enum {
 DISPATCH_BLOCK,
 DISPATCH_NONBLOCK
};

struct ssh;

typedef int dispatch_fn(int, u_int32_t, struct ssh *);

int dispatch_protocol_error(int, u_int32_t, struct ssh *);
int dispatch_protocol_ignore(int, u_int32_t, struct ssh *);
void ssh_dispatch_init(struct ssh *, dispatch_fn *);
void ssh_dispatch_set(struct ssh *, int, dispatch_fn *);
void ssh_dispatch_range(struct ssh *, u_int, u_int, dispatch_fn *);
int ssh_dispatch_run(struct ssh *, int, volatile sig_atomic_t *);
void ssh_dispatch_run_fatal(struct ssh *, int, volatile sig_atomic_t *);

struct key_entry {
 struct { struct key_entry *tqe_next; struct key_entry **tqe_prev; } next;
 struct sshkey *key;
};

struct ssh {

 struct session_state *state;


 struct kex *kex;


 char *remote_ipaddr;
 int remote_port;
 char *local_ipaddr;
 int local_port;
 char *rdomain_in;


 char *log_preamble;


 dispatch_fn *dispatch[255];

 int dispatch_skip_packets;


 int compat;


 struct { struct key_entry *tqh_first; struct key_entry **tqh_last; } private_keys;
 struct { struct key_entry *tqh_first; struct key_entry **tqh_last; } public_keys;


 void *authctxt;


 struct ssh_channels *chanctxt;


 void *app_data;
};

typedef int (ssh_packet_hook_fn)(struct ssh *, struct sshbuf *,
    u_char *, void *);

struct ssh *ssh_alloc_session_state(void);
struct ssh *ssh_packet_set_connection(struct ssh *, int, int);
void ssh_packet_set_timeout(struct ssh *, int, int);
int ssh_packet_stop_discard(struct ssh *);
int ssh_packet_connection_af(struct ssh *);
void ssh_packet_set_nonblocking(struct ssh *);
int ssh_packet_get_connection_in(struct ssh *);
int ssh_packet_get_connection_out(struct ssh *);
void ssh_packet_close(struct ssh *);
void ssh_packet_set_input_hook(struct ssh *, ssh_packet_hook_fn *, void *);
void ssh_packet_clear_keys(struct ssh *);
void ssh_clear_newkeys(struct ssh *, int);

int ssh_packet_is_rekeying(struct ssh *);
int ssh_packet_check_rekey(struct ssh *);
void ssh_packet_set_protocol_flags(struct ssh *, u_int);
u_int ssh_packet_get_protocol_flags(struct ssh *);
void ssh_packet_set_tos(struct ssh *, int);
void ssh_packet_set_interactive(struct ssh *, int, int, int);
int ssh_packet_is_interactive(struct ssh *);
void ssh_packet_set_server(struct ssh *);
void ssh_packet_set_authenticated(struct ssh *);
void ssh_packet_set_mux(struct ssh *);
int ssh_packet_get_mux(struct ssh *);
int ssh_packet_set_log_preamble(struct ssh *, const char *, ...)
    __attribute__((format(printf, 2, 3)));

int ssh_packet_log_type(u_char);

int ssh_packet_send2_wrapped(struct ssh *);
int ssh_packet_send2(struct ssh *);

int ssh_packet_read(struct ssh *);
int ssh_packet_read_expect(struct ssh *, u_int type);
int ssh_packet_read_poll(struct ssh *);
int ssh_packet_read_poll2(struct ssh *, u_char *, u_int32_t *seqnr_p);
int ssh_packet_process_incoming(struct ssh *, const char *buf, u_int len);
int ssh_packet_process_read(struct ssh *, int);
int ssh_packet_read_seqnr(struct ssh *, u_char *, u_int32_t *seqnr_p);
int ssh_packet_read_poll_seqnr(struct ssh *, u_char *, u_int32_t *seqnr_p);

const void *ssh_packet_get_string_ptr(struct ssh *, u_int *length_ptr);
void ssh_packet_disconnect(struct ssh *, const char *fmt, ...)
 __attribute__((format(printf, 2, 3)))
 __attribute__((noreturn));
void ssh_packet_send_debug(struct ssh *, const char *fmt, ...) __attribute__((format(printf, 2, 3)));

int ssh_set_newkeys(struct ssh *, int mode);
void ssh_packet_get_bytes(struct ssh *, u_int64_t *, u_int64_t *);

int ssh_packet_write_poll(struct ssh *);
int ssh_packet_write_wait(struct ssh *);
int ssh_packet_have_data_to_write(struct ssh *);
int ssh_packet_not_very_much_data_to_write(struct ssh *);

int ssh_packet_connection_is_on_socket(struct ssh *);
int ssh_packet_remaining(struct ssh *);

void ssh_tty_make_modes(struct ssh *, int, struct termios *);
void ssh_tty_parse_modes(struct ssh *, int);

void ssh_packet_set_alive_timeouts(struct ssh *, int);
int ssh_packet_inc_alive_timeouts(struct ssh *);
int ssh_packet_set_maxsize(struct ssh *, u_int);
u_int ssh_packet_get_maxsize(struct ssh *);

int ssh_packet_get_state(struct ssh *, struct sshbuf *);
int ssh_packet_set_state(struct ssh *, struct sshbuf *);

const char *ssh_remote_ipaddr(struct ssh *);
int ssh_remote_port(struct ssh *);
const char *ssh_local_ipaddr(struct ssh *);
int ssh_local_port(struct ssh *);
const char *ssh_packet_rdomain_in(struct ssh *);

void ssh_packet_set_rekey_limits(struct ssh *, u_int64_t, u_int32_t);
time_t ssh_packet_get_rekey_timeout(struct ssh *);

void *ssh_packet_get_input(struct ssh *);
void *ssh_packet_get_output(struct ssh *);


int sshpkt_start(struct ssh *ssh, u_char type);
int sshpkt_send(struct ssh *ssh);
int sshpkt_disconnect(struct ssh *, const char *fmt, ...)
     __attribute__((format(printf, 2, 3)));
int sshpkt_add_padding(struct ssh *, u_char);
void sshpkt_fatal(struct ssh *ssh, int r, const char *fmt, ...)
     __attribute__((format(printf, 3, 4)))
     __attribute__((noreturn));
int sshpkt_msg_ignore(struct ssh *, u_int);

int sshpkt_put(struct ssh *ssh, const void *v, size_t len);
int sshpkt_putb(struct ssh *ssh, const struct sshbuf *b);
int sshpkt_put_u8(struct ssh *ssh, u_char val);
int sshpkt_put_u32(struct ssh *ssh, u_int32_t val);
int sshpkt_put_u64(struct ssh *ssh, u_int64_t val);
int sshpkt_put_string(struct ssh *ssh, const void *v, size_t len);
int sshpkt_put_cstring(struct ssh *ssh, const void *v);
int sshpkt_put_stringb(struct ssh *ssh, const struct sshbuf *v);
int sshpkt_put_ec(struct ssh *ssh, const EC_POINT *v, const EC_GROUP *g);
int sshpkt_put_bignum2(struct ssh *ssh, const BIGNUM *v);

int sshpkt_get(struct ssh *ssh, void *valp, size_t len);
int sshpkt_get_u8(struct ssh *ssh, u_char *valp);
int sshpkt_get_u32(struct ssh *ssh, u_int32_t *valp);
int sshpkt_get_u64(struct ssh *ssh, u_int64_t *valp);
int sshpkt_get_string(struct ssh *ssh, u_char **valp, size_t *lenp);
int sshpkt_get_string_direct(struct ssh *ssh, const u_char **valp, size_t *lenp);
int sshpkt_peek_string_direct(struct ssh *ssh, const u_char **valp, size_t *lenp);
int sshpkt_get_cstring(struct ssh *ssh, char **valp, size_t *lenp);
int sshpkt_getb_froms(struct ssh *ssh, struct sshbuf **valp);
int sshpkt_get_ec(struct ssh *ssh, EC_POINT *v, const EC_GROUP *g);
int sshpkt_get_bignum2(struct ssh *ssh, BIGNUM **valp);
int sshpkt_get_end(struct ssh *ssh);
void sshpkt_fmt_connection_id(struct ssh *ssh, char *s, size_t l);
const u_char *sshpkt_ptr(struct ssh *, size_t *lenp);

typedef enum {
 HOST_OK, HOST_NEW, HOST_CHANGED, HOST_REVOKED, HOST_FOUND
} HostStatus;

typedef enum {
 MRK_ERROR, MRK_NONE, MRK_REVOKE, MRK_CA
} HostkeyMarker;

struct hostkey_entry {
 char *host;
 char *file;
 u_long line;
 struct sshkey *key;
 HostkeyMarker marker;
 u_int note;
};
struct hostkeys {
 struct hostkey_entry *entries;
 u_int num_entries;
};

struct hostkeys *init_hostkeys(void);
void load_hostkeys(struct hostkeys *, const char *,
    const char *, u_int);
void load_hostkeys_file(struct hostkeys *, const char *,
    const char *, FILE *, u_int note);
void free_hostkeys(struct hostkeys *);

HostStatus check_key_in_hostkeys(struct hostkeys *, struct sshkey *,
    const struct hostkey_entry **);
int lookup_key_in_hostkeys_by_type(struct hostkeys *, int, int,
    const struct hostkey_entry **);
int lookup_marker_in_hostkeys(struct hostkeys *, int);

int hostfile_read_key(char **, u_int *, struct sshkey *);
int add_host_to_hostfile(const char *, const char *,
    const struct sshkey *, int);

int hostfile_replace_entries(const char *filename,
    const char *host, const char *ip, struct sshkey **keys, size_t nkeys,
    int store_hash, int quiet, int hash_alg);







char *host_hash(const char *, const char *, u_int);
struct hostkey_foreach_line {
 const char *path;
 u_long linenum;
 u_int status;
 u_int match;
 char *line;
 int marker;
 const char *hosts;
 const char *rawkey;
 int keytype;
 struct sshkey *key;
 const char *comment;
 u_int note;
};






typedef int hostkeys_foreach_fn(struct hostkey_foreach_line *l, void *ctx);


int hostkeys_foreach(const char *path,
    hostkeys_foreach_fn *callback, void *ctx,
    const char *host, const char *ip, u_int options, u_int note);
int hostkeys_foreach_file(const char *path, FILE *f,
    hostkeys_foreach_fn *callback, void *ctx,
    const char *host, const char *ip, u_int options, u_int note);

void hostfile_create_user_ssh_dir(const char *, int);
struct passwd;
struct ssh;
struct sshbuf;
struct sshkey;
struct sshkey_cert;
struct sshauthopt;

typedef struct Authctxt Authctxt;
typedef struct Authmethod Authmethod;
typedef struct KbdintDevice KbdintDevice;

struct Authctxt {
 sig_atomic_t success;
 int authenticated;
 int postponed;
 int valid;
 int attempt;
 int failures;
 int server_caused_failure;
 int force_pwchange;
 char *user;
 char *service;
 struct passwd *pw;
 char *style;


 char **auth_methods;
 u_int num_auth_methods;


 void *methoddata;
 void *kbdintctxt;
 struct sshbuf *loginmsg;


 struct sshkey **prev_keys;
 u_int nprev_keys;


 struct sshkey *auth_method_key;
 char *auth_method_info;


 struct sshbuf *session_info;
};
struct Authmethod {
 char *name;
 char *synonym;
 int (*userauth)(struct ssh *, const char *);
 int *enabled;
};
struct KbdintDevice
{
 const char *name;
 void* (*init_ctx)(Authctxt*);
 int (*query)(void *ctx, char **name, char **infotxt,
      u_int *numprompts, char ***prompts, u_int **echo_on);
 int (*respond)(void *ctx, u_int numresp, char **responses);
 void (*free_ctx)(void *ctx);
};

int
auth_rhosts2(struct passwd *, const char *, const char *, const char *);

int auth_password(struct ssh *, const char *);

int hostbased_key_allowed(struct ssh *, struct passwd *,
     const char *, char *, struct sshkey *);
int user_key_allowed(struct ssh *ssh, struct passwd *, struct sshkey *,
    int, struct sshauthopt **);
int auth2_key_already_used(Authctxt *, const struct sshkey *);





void auth2_authctxt_reset_info(Authctxt *);
void auth2_record_key(Authctxt *, int, const struct sshkey *);
void auth2_record_info(Authctxt *authctxt, const char *, ...)
     __attribute__((__format__ (printf, 2, 3)))
     __attribute__((__nonnull__ (2)));
void auth2_update_session_info(Authctxt *, const char *, const char *);

int auth_shadow_acctexpired(struct spwd *);
int auth_shadow_pwexpired(Authctxt *);


struct ssh;
union login_netinfo {
 struct sockaddr sa;
 struct sockaddr_in sa_in;
 struct sockaddr_storage sa_storage;
};
struct logininfo {
 char progname[64];
 int progname_null;
 short int type;
 pid_t pid;
 uid_t uid;
 char line[64];
 char username[512];
 char hostname[256];

 int exit;
 int termination;



 unsigned int tv_sec;
 unsigned int tv_usec;
 union login_netinfo hostaddr;
};
struct logininfo *login_alloc_entry(pid_t pid, const char *username,
        const char *hostname, const char *line);

void login_free_entry(struct logininfo *li);

int login_init_entry(struct logininfo *li, pid_t pid, const char *username,
    const char *hostname, const char *line);

void login_set_current_time(struct logininfo *li);


int login_login (struct logininfo *li);
int login_logout(struct logininfo *li);







int login_write (struct logininfo *li);
int login_log_entry(struct logininfo *li);


void login_set_addr(struct logininfo *li, const struct sockaddr *sa,
      const unsigned int sa_size);





struct logininfo *login_get_lastlog(struct logininfo *li, const uid_t uid);

unsigned int login_get_lastlog_time(const uid_t uid);


char *line_fullname(char *dst, const char *src, u_int dstsize);
char *line_stripname(char *dst, const char *src, int dstsize);
char *line_abbrevname(char *dst, const char *src, int dstsize);

void record_failed_login(struct ssh *, const char *, const char *,
    const char *);

struct ssh;

enum ssh_audit_event_type {
 SSH_LOGIN_EXCEED_MAXTRIES,
 SSH_LOGIN_ROOT_DENIED,
 SSH_AUTH_SUCCESS,
 SSH_AUTH_FAIL_NONE,
 SSH_AUTH_FAIL_PASSWD,
 SSH_AUTH_FAIL_KBDINT,
 SSH_AUTH_FAIL_PUBKEY,
 SSH_AUTH_FAIL_HOSTBASED,
 SSH_AUTH_FAIL_GSSAPI,
 SSH_INVALID_USER,
 SSH_NOLOGIN,
 SSH_CONNECTION_CLOSE,
 SSH_CONNECTION_ABANDON,
 SSH_AUDIT_UNKNOWN
};
typedef enum ssh_audit_event_type ssh_audit_event_t;

void audit_connection_from(const char *, int);
void audit_event(struct ssh *, ssh_audit_event_t);
void audit_session_open(struct logininfo *);
void audit_session_close(struct logininfo *);
void audit_run_command(const char *);
ssh_audit_event_t audit_classify_auth(const char *);
void remove_kbdint_device(const char *);

void do_authentication2(struct ssh *);

void auth_log(struct ssh *, int, int, const char *, const char *);
void auth_maxtries_exceeded(struct ssh *) __attribute__((noreturn));
void userauth_finish(struct ssh *, int, const char *, const char *);
int auth_root_allowed(struct ssh *, const char *);

char *auth2_read_banner(void);
int auth2_methods_valid(const char *, int);
int auth2_update_methods_lists(Authctxt *, const char *, const char *);
int auth2_setup_methods_lists(Authctxt *);
int auth2_method_allowed(Authctxt *, const char *, const char *);

void privsep_challenge_enable(void);

int auth2_challenge(struct ssh *, char *);
void auth2_challenge_stop(struct ssh *);
int bsdauth_query(void *, char **, char **, u_int *, char ***, u_int **);
int bsdauth_respond(void *, u_int, char **);

int allowed_user(struct ssh *, struct passwd *);
struct passwd * getpwnamallow(struct ssh *, const char *user);

char *expand_authorized_keys(const char *, struct passwd *pw);
char *authorized_principals_file(struct passwd *);

int auth_key_is_revoked(struct sshkey *);

const char *auth_get_canonical_hostname(struct ssh *, int);

HostStatus
check_key_in_hostfiles(struct passwd *, struct sshkey *, const char *,
    const char *, const char *);


struct sshkey *get_hostkey_by_index(int);
struct sshkey *get_hostkey_public_by_index(int, struct ssh *);
struct sshkey *get_hostkey_public_by_type(int, int, struct ssh *);
struct sshkey *get_hostkey_private_by_type(int, int, struct ssh *);
int get_hostkey_index(struct sshkey *, int, struct ssh *);
int sshd_hostkey_sign(struct ssh *, struct sshkey *, struct sshkey *,
    u_char **, size_t *, const u_char *, size_t, const char *);


const struct sshauthopt *auth_options(struct ssh *);
int auth_activate_options(struct ssh *, struct sshauthopt *);
void auth_restrict_session(struct ssh *);
void auth_log_authopts(const char *, const struct sshauthopt *, int);


void auth_debug_add(const char *fmt,...)
    __attribute__((format(printf, 1, 2)));
void auth_debug_send(struct ssh *);
void auth_debug_reset(void);

struct passwd *fakepw(void);


int auth_authorise_keyopts(struct passwd *, struct sshauthopt *, int,
    const char *, const char *, const char *);
int auth_check_principals_line(char *, const struct sshkey_cert *,
    const char *, struct sshauthopt **);
int auth_process_principals(FILE *, const char *,
    const struct sshkey_cert *, struct sshauthopt **);
int auth_check_authkey_line(struct passwd *, struct sshkey *,
    char *, const char *, const char *, const char *, struct sshauthopt **);
int auth_check_authkeys_file(struct passwd *, FILE *, char *,
    struct sshkey *, const char *, const char *, struct sshauthopt **);
FILE *auth_openkeyfile(const char *, struct passwd *, int);
FILE *auth_openprincipals(const char *, struct passwd *, int);

int sys_auth_passwd(struct ssh *, const char *);
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

static void add_listen_addr(ServerOptions *, const char *,
    const char *, int);
static void add_one_listen_addr(ServerOptions *, const char *,
    const char *, int);
static void parse_server_config_depth(ServerOptions *options,
    const char *filename, struct sshbuf *conf, struct include_list *includes,
    struct connection_info *connectinfo, int flags, int *activep, int depth);


extern int use_privsep;
extern struct sshbuf *cfg;



void
initialize_server_options(ServerOptions *options)
{
 memset(options, 0, sizeof(*options));


 options->use_pam = -1;


 options->num_ports = 0;
 options->ports_from_cmdline = 0;
 options->queued_listen_addrs = 
                               ((void *)0)
                                   ;
 options->num_queued_listens = 0;
 options->listen_addrs = 
                        ((void *)0)
                            ;
 options->num_listen_addrs = 0;
 options->address_family = -1;
 options->routing_domain = 
                          ((void *)0)
                              ;
 options->num_host_key_files = 0;
 options->num_host_cert_files = 0;
 options->host_key_agent = 
                          ((void *)0)
                              ;
 options->pid_file = 
                    ((void *)0)
                        ;
 options->login_grace_time = -1;
 options->permit_root_login = -1;
 options->ignore_rhosts = -1;
 options->ignore_user_known_hosts = -1;
 options->print_motd = -1;
 options->print_lastlog = -1;
 options->x11_forwarding = -1;
 options->x11_display_offset = -1;
 options->x11_use_localhost = -1;
 options->permit_tty = -1;
 options->permit_user_rc = -1;
 options->xauth_location = 
                          ((void *)0)
                              ;
 options->strict_modes = -1;
 options->tcp_keep_alive = -1;
 options->log_facility = SYSLOG_FACILITY_NOT_SET;
 options->log_level = SYSLOG_LEVEL_NOT_SET;
 options->num_log_verbose = 0;
 options->log_verbose = 
                       ((void *)0)
                           ;
 options->hostbased_authentication = -1;
 options->hostbased_uses_name_from_packet_only = -1;
 options->hostbased_accepted_algos = 
                                    ((void *)0)
                                        ;
 options->hostkeyalgorithms = 
                             ((void *)0)
                                 ;
 options->pubkey_authentication = -1;
 options->pubkey_auth_options = -1;
 options->pubkey_accepted_algos = 
                                 ((void *)0)
                                     ;
 options->kerberos_authentication = -1;
 options->kerberos_or_local_passwd = -1;
 options->kerberos_ticket_cleanup = -1;
 options->kerberos_get_afs_token = -1;
 options->gss_authentication=-1;
 options->gss_cleanup_creds = -1;
 options->gss_strict_acceptor = -1;
 options->password_authentication = -1;
 options->kbd_interactive_authentication = -1;
 options->permit_empty_passwd = -1;
 options->permit_user_env = -1;
 options->permit_user_env_allowlist = 
                                     ((void *)0)
                                         ;
 options->compression = -1;
 options->rekey_limit = -1;
 options->rekey_interval = -1;
 options->allow_tcp_forwarding = -1;
 options->allow_streamlocal_forwarding = -1;
 options->allow_agent_forwarding = -1;
 options->num_allow_users = 0;
 options->num_deny_users = 0;
 options->num_allow_groups = 0;
 options->num_deny_groups = 0;
 options->ciphers = 
                   ((void *)0)
                       ;
 options->macs = 
                ((void *)0)
                    ;
 options->kex_algorithms = 
                          ((void *)0)
                              ;
 options->ca_sign_algorithms = 
                              ((void *)0)
                                  ;
 options->fwd_opts.gateway_ports = -1;
 options->fwd_opts.streamlocal_bind_mask = (mode_t)-1;
 options->fwd_opts.streamlocal_bind_unlink = -1;
 options->num_subsystems = 0;
 options->max_startups_begin = -1;
 options->max_startups_rate = -1;
 options->max_startups = -1;
 options->per_source_max_startups = -1;
 options->per_source_masklen_ipv4 = -1;
 options->per_source_masklen_ipv6 = -1;
 options->max_authtries = -1;
 options->max_sessions = -1;
 options->banner = 
                  ((void *)0)
                      ;
 options->use_dns = -1;
 options->client_alive_interval = -1;
 options->client_alive_count_max = -1;
 options->num_authkeys_files = 0;
 options->num_accept_env = 0;
 options->num_setenv = 0;
 options->permit_tun = -1;
 options->permitted_opens = 
                           ((void *)0)
                               ;
 options->permitted_listens = 
                             ((void *)0)
                                 ;
 options->adm_forced_command = 
                              ((void *)0)
                                  ;
 options->chroot_directory = 
                            ((void *)0)
                                ;
 options->authorized_keys_command = 
                                   ((void *)0)
                                       ;
 options->authorized_keys_command_user = 
                                        ((void *)0)
                                            ;
 options->revoked_keys_file = 
                             ((void *)0)
                                 ;
 options->sk_provider = 
                       ((void *)0)
                           ;
 options->trusted_user_ca_keys = 
                                ((void *)0)
                                    ;
 options->authorized_principals_file = 
                                      ((void *)0)
                                          ;
 options->authorized_principals_command = 
                                         ((void *)0)
                                             ;
 options->authorized_principals_command_user = 
                                              ((void *)0)
                                                  ;
 options->ip_qos_interactive = -1;
 options->ip_qos_bulk = -1;
 options->version_addendum = 
                            ((void *)0)
                                ;
 options->fingerprint_hash = -1;
 options->disable_forwarding = -1;
 options->expose_userauth_info = -1;
 options->required_rsa_size = -1;
}


static int
option_clear_or_none(const char *o)
{
 return o == 
            ((void *)0) 
                 || strcasecmp(o, "none") == 0;
}

static void
assemble_algorithms(ServerOptions *o)
{
 char *all_cipher, *all_mac, *all_kex, *all_key, *all_sig;
 char *def_cipher, *def_mac, *def_kex, *def_key, *def_sig;
 int r;

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





 do { if ((r = kex_assemble_names(&o->ciphers, def_cipher, all_cipher)) != 0) sshfatal("servconf.c", __func__, 231, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s", "ciphers"); } while (0);
 do { if ((r = kex_assemble_names(&o->macs, def_mac, all_mac)) != 0) sshfatal("servconf.c", __func__, 232, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s", "macs"); } while (0);
 do { if ((r = kex_assemble_names(&o->kex_algorithms, def_kex, all_kex)) != 0) sshfatal("servconf.c", __func__, 233, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s", "kex_algorithms"); } while (0);
 do { if ((r = kex_assemble_names(&o->hostkeyalgorithms, def_key, all_key)) != 0) sshfatal("servconf.c", __func__, 234, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s", "hostkeyalgorithms"); } while (0);
 do { if ((r = kex_assemble_names(&o->hostbased_accepted_algos, def_key, all_key)) != 0) sshfatal("servconf.c", __func__, 235, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s", "hostbased_accepted_algos"); } while (0);
 do { if ((r = kex_assemble_names(&o->pubkey_accepted_algos, def_key, all_key)) != 0) sshfatal("servconf.c", __func__, 236, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s", "pubkey_accepted_algos"); } while (0);
 do { if ((r = kex_assemble_names(&o->ca_sign_algorithms, def_sig, all_sig)) != 0) sshfatal("servconf.c", __func__, 237, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s", "ca_sign_algorithms"); } while (0);

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
}

void
servconf_add_hostkey(const char *file, const int line,
    ServerOptions *options, const char *path, int userprovided)
{
 char *apath = derelativise_path(path);

 opt_array_append2(file, line, "HostKey",
     &options->host_key_files, &options->host_key_file_userprovided,
     &options->num_host_key_files, apath, userprovided);
 free(apath);
}

void
servconf_add_hostcert(const char *file, const int line,
    ServerOptions *options, const char *path)
{
 char *apath = derelativise_path(path);

 opt_array_append(file, line, "HostCertificate",
     &options->host_cert_files, &options->num_host_cert_files, apath);
 free(apath);
}

void
fill_default_server_options(ServerOptions *options)
{
 u_int i;


 if (options->use_pam == -1)
  options->use_pam = 0;


 if (options->num_host_key_files == 0) {

  servconf_add_hostkey("[default]", 0, options,
      "/usr/local/etc" "/ssh_host_rsa_key", 0);

  servconf_add_hostkey("[default]", 0, options,
      "/usr/local/etc" "/ssh_host_ecdsa_key", 0);

  servconf_add_hostkey("[default]", 0, options,
      "/usr/local/etc" "/ssh_host_ed25519_key", 0);




 }

 if (options->num_ports == 0)
  options->ports[options->num_ports++] = 22;
 if (options->address_family == -1)
  options->address_family = 
                           0
                                    ;
 if (options->listen_addrs == 
                             ((void *)0)
                                 )
  add_listen_addr(options, 
                          ((void *)0)
                              , 
                                ((void *)0)
                                    , 0);
 if (options->pid_file == 
                         ((void *)0)
                             )
  options->pid_file = xstrdup("/var/run" "/sshd.pid");
 if (options->moduli_file == 
                            ((void *)0)
                                )
  options->moduli_file = xstrdup("/usr/local/etc" "/moduli");
 if (options->login_grace_time == -1)
  options->login_grace_time = 120;
 if (options->permit_root_login == -1)
  options->permit_root_login = 2;
 if (options->ignore_rhosts == -1)
  options->ignore_rhosts = 1;
 if (options->ignore_user_known_hosts == -1)
  options->ignore_user_known_hosts = 0;
 if (options->print_motd == -1)
  options->print_motd = 1;
 if (options->print_lastlog == -1)
  options->print_lastlog = 1;
 if (options->x11_forwarding == -1)
  options->x11_forwarding = 0;
 if (options->x11_display_offset == -1)
  options->x11_display_offset = 10;
 if (options->x11_use_localhost == -1)
  options->x11_use_localhost = 1;
 if (options->xauth_location == 
                               ((void *)0)
                                   )
  options->xauth_location = xstrdup("/usr/bin/xauth");
 if (options->permit_tty == -1)
  options->permit_tty = 1;
 if (options->permit_user_rc == -1)
  options->permit_user_rc = 1;
 if (options->strict_modes == -1)
  options->strict_modes = 1;
 if (options->tcp_keep_alive == -1)
  options->tcp_keep_alive = 1;
 if (options->log_facility == SYSLOG_FACILITY_NOT_SET)
  options->log_facility = SYSLOG_FACILITY_AUTH;
 if (options->log_level == SYSLOG_LEVEL_NOT_SET)
  options->log_level = SYSLOG_LEVEL_INFO;
 if (options->hostbased_authentication == -1)
  options->hostbased_authentication = 0;
 if (options->hostbased_uses_name_from_packet_only == -1)
  options->hostbased_uses_name_from_packet_only = 0;
 if (options->pubkey_authentication == -1)
  options->pubkey_authentication = 1;
 if (options->pubkey_auth_options == -1)
  options->pubkey_auth_options = 0;
 if (options->kerberos_authentication == -1)
  options->kerberos_authentication = 0;
 if (options->kerberos_or_local_passwd == -1)
  options->kerberos_or_local_passwd = 1;
 if (options->kerberos_ticket_cleanup == -1)
  options->kerberos_ticket_cleanup = 1;
 if (options->kerberos_get_afs_token == -1)
  options->kerberos_get_afs_token = 0;
 if (options->gss_authentication == -1)
  options->gss_authentication = 0;
 if (options->gss_cleanup_creds == -1)
  options->gss_cleanup_creds = 1;
 if (options->gss_strict_acceptor == -1)
  options->gss_strict_acceptor = 1;
 if (options->password_authentication == -1)
  options->password_authentication = 1;
 if (options->kbd_interactive_authentication == -1)
  options->kbd_interactive_authentication = 1;
 if (options->permit_empty_passwd == -1)
  options->permit_empty_passwd = 0;
 if (options->permit_user_env == -1) {
  options->permit_user_env = 0;
  options->permit_user_env_allowlist = 
                                      ((void *)0)
                                          ;
 }
 if (options->compression == -1)

  options->compression = 2;




 if (options->rekey_limit == -1)
  options->rekey_limit = 0;
 if (options->rekey_interval == -1)
  options->rekey_interval = 0;
 if (options->allow_tcp_forwarding == -1)
  options->allow_tcp_forwarding = ((1)|(1<<1));
 if (options->allow_streamlocal_forwarding == -1)
  options->allow_streamlocal_forwarding = ((1)|(1<<1));
 if (options->allow_agent_forwarding == -1)
  options->allow_agent_forwarding = 1;
 if (options->fwd_opts.gateway_ports == -1)
  options->fwd_opts.gateway_ports = 0;
 if (options->max_startups == -1)
  options->max_startups = 100;
 if (options->max_startups_rate == -1)
  options->max_startups_rate = 30;
 if (options->max_startups_begin == -1)
  options->max_startups_begin = 10;
 if (options->per_source_max_startups == -1)
  options->per_source_max_startups = 0x7fffffff;
 if (options->per_source_masklen_ipv4 == -1)
  options->per_source_masklen_ipv4 = 32;
 if (options->per_source_masklen_ipv6 == -1)
  options->per_source_masklen_ipv6 = 128;
 if (options->max_authtries == -1)
  options->max_authtries = 6;
 if (options->max_sessions == -1)
  options->max_sessions = 10;
 if (options->use_dns == -1)
  options->use_dns = 0;
 if (options->client_alive_interval == -1)
  options->client_alive_interval = 0;
 if (options->client_alive_count_max == -1)
  options->client_alive_count_max = 3;
 if (options->num_authkeys_files == 0) {
  opt_array_append("[default]", 0, "AuthorizedKeysFiles",
      &options->authorized_keys_files,
      &options->num_authkeys_files,
      ".ssh" "/authorized_keys");
  opt_array_append("[default]", 0, "AuthorizedKeysFiles",
      &options->authorized_keys_files,
      &options->num_authkeys_files,
      ".ssh" "/authorized_keys2");
 }
 if (options->permit_tun == -1)
  options->permit_tun = 0x00;
 if (options->ip_qos_interactive == -1)
  options->ip_qos_interactive = 
                               0x48
                                              ;
 if (options->ip_qos_bulk == -1)
  options->ip_qos_bulk = 0x20;
 if (options->version_addendum == 
                                 ((void *)0)
                                     )
  options->version_addendum = xstrdup("");
 if (options->fwd_opts.streamlocal_bind_mask == (mode_t)-1)
  options->fwd_opts.streamlocal_bind_mask = 0177;
 if (options->fwd_opts.streamlocal_bind_unlink == -1)
  options->fwd_opts.streamlocal_bind_unlink = 0;
 if (options->fingerprint_hash == -1)
  options->fingerprint_hash = 2;
 if (options->disable_forwarding == -1)
  options->disable_forwarding = 0;
 if (options->expose_userauth_info == -1)
  options->expose_userauth_info = 0;
 if (options->sk_provider == 
                            ((void *)0)
                                )
  options->sk_provider = xstrdup("internal");
 if (options->required_rsa_size == -1)
  options->required_rsa_size = 1024;

 assemble_algorithms(options);


 if (use_privsep == -1)
  use_privsep = 1;
 do { if (option_clear_or_none(options->pid_file)) { free(options->pid_file); options->pid_file = 
((void *)0)
; } } while(0);
 do { if (option_clear_or_none(options->xauth_location)) { free(options->xauth_location); options->xauth_location = 
((void *)0)
; } } while(0);
 do { if (option_clear_or_none(options->banner)) { free(options->banner); options->banner = 
((void *)0)
; } } while(0);
 do { if (option_clear_or_none(options->trusted_user_ca_keys)) { free(options->trusted_user_ca_keys); options->trusted_user_ca_keys = 
((void *)0)
; } } while(0);
 do { if (option_clear_or_none(options->revoked_keys_file)) { free(options->revoked_keys_file); options->revoked_keys_file = 
((void *)0)
; } } while(0);
 do { if (option_clear_or_none(options->sk_provider)) { free(options->sk_provider); options->sk_provider = 
((void *)0)
; } } while(0);
 do { if (option_clear_or_none(options->authorized_principals_file)) { free(options->authorized_principals_file); options->authorized_principals_file = 
((void *)0)
; } } while(0);
 do { if (option_clear_or_none(options->adm_forced_command)) { free(options->adm_forced_command); options->adm_forced_command = 
((void *)0)
; } } while(0);
 do { if (option_clear_or_none(options->chroot_directory)) { free(options->chroot_directory); options->chroot_directory = 
((void *)0)
; } } while(0);
 do { if (option_clear_or_none(options->routing_domain)) { free(options->routing_domain); options->routing_domain = 
((void *)0)
; } } while(0);
 do { if (option_clear_or_none(options->host_key_agent)) { free(options->host_key_agent); options->host_key_agent = 
((void *)0)
; } } while(0);
 for (i = 0; i < options->num_host_key_files; i++)
  do { if (option_clear_or_none(options->host_key_files[i])) { free(options->host_key_files[i]); options->host_key_files[i] = 
 ((void *)0)
 ; } } while(0);
 for (i = 0; i < options->num_host_cert_files; i++)
  do { if (option_clear_or_none(options->host_cert_files[i])) { free(options->host_cert_files[i]); options->host_cert_files[i] = 
 ((void *)0)
 ; } } while(0);



 if (options->num_auth_methods == 1 &&
     strcmp(options->auth_methods[0], "any") == 0) {
  free(options->auth_methods[0]);
  options->auth_methods[0] = 
                            ((void *)0)
                                ;
  options->num_auth_methods = 0;
 }
}


typedef enum {
 sBadOption,

 sUsePAM,

 sPort, sHostKeyFile, sLoginGraceTime,
 sPermitRootLogin, sLogFacility, sLogLevel, sLogVerbose,
 sKerberosAuthentication, sKerberosOrLocalPasswd, sKerberosTicketCleanup,
 sKerberosGetAFSToken, sPasswordAuthentication,
 sKbdInteractiveAuthentication, sListenAddress, sAddressFamily,
 sPrintMotd, sPrintLastLog, sIgnoreRhosts,
 sX11Forwarding, sX11DisplayOffset, sX11UseLocalhost,
 sPermitTTY, sStrictModes, sEmptyPasswd, sTCPKeepAlive,
 sPermitUserEnvironment, sAllowTcpForwarding, sCompression,
 sRekeyLimit, sAllowUsers, sDenyUsers, sAllowGroups, sDenyGroups,
 sIgnoreUserKnownHosts, sCiphers, sMacs, sPidFile, sModuliFile,
 sGatewayPorts, sPubkeyAuthentication, sPubkeyAcceptedAlgorithms,
 sXAuthLocation, sSubsystem, sMaxStartups, sMaxAuthTries, sMaxSessions,
 sBanner, sUseDNS, sHostbasedAuthentication,
 sHostbasedUsesNameFromPacketOnly, sHostbasedAcceptedAlgorithms,
 sHostKeyAlgorithms, sPerSourceMaxStartups, sPerSourceNetBlockSize,
 sClientAliveInterval, sClientAliveCountMax, sAuthorizedKeysFile,
 sGssAuthentication, sGssCleanupCreds, sGssStrictAcceptor,
 sAcceptEnv, sSetEnv, sPermitTunnel,
 sMatch, sPermitOpen, sPermitListen, sForceCommand, sChrootDirectory,
 sUsePrivilegeSeparation, sAllowAgentForwarding,
 sHostCertificate, sInclude,
 sRevokedKeys, sTrustedUserCAKeys, sAuthorizedPrincipalsFile,
 sAuthorizedPrincipalsCommand, sAuthorizedPrincipalsCommandUser,
 sKexAlgorithms, sCASignatureAlgorithms, sIPQoS, sVersionAddendum,
 sAuthorizedKeysCommand, sAuthorizedKeysCommandUser,
 sAuthenticationMethods, sHostKeyAgent, sPermitUserRC,
 sStreamLocalBindMask, sStreamLocalBindUnlink,
 sAllowStreamLocalForwarding, sFingerprintHash, sDisableForwarding,
 sExposeAuthInfo, sRDomain, sPubkeyAuthOptions, sSecurityKeyProvider,
 sRequiredRSASize,
 sDeprecated, sIgnore, sUnsupported
} ServerOpCodes;
static struct {
 const char *name;
 ServerOpCodes opcode;
 u_int flags;
} keywords[] = {




 { "usepam", sUnsupported, 0x01 },

 { "pamauthenticationviakbdint", sDeprecated, 0x01 },

 { "port", sPort, 0x01 },
 { "hostkey", sHostKeyFile, 0x01 },
 { "hostdsakey", sHostKeyFile, 0x01 },
 { "hostkeyagent", sHostKeyAgent, 0x01 },
 { "pidfile", sPidFile, 0x01 },
 { "modulifile", sModuliFile, 0x01 },
 { "serverkeybits", sDeprecated, 0x01 },
 { "logingracetime", sLoginGraceTime, 0x01 },
 { "keyregenerationinterval", sDeprecated, 0x01 },
 { "permitrootlogin", sPermitRootLogin, (0x01|0x02) },
 { "syslogfacility", sLogFacility, 0x01 },
 { "loglevel", sLogLevel, (0x01|0x02) },
 { "logverbose", sLogVerbose, (0x01|0x02) },
 { "rhostsauthentication", sDeprecated, 0x01 },
 { "rhostsrsaauthentication", sDeprecated, (0x01|0x02) },
 { "hostbasedauthentication", sHostbasedAuthentication, (0x01|0x02) },
 { "hostbasedusesnamefrompacketonly", sHostbasedUsesNameFromPacketOnly, (0x01|0x02) },
 { "hostbasedacceptedalgorithms", sHostbasedAcceptedAlgorithms, (0x01|0x02) },
 { "hostbasedacceptedkeytypes", sHostbasedAcceptedAlgorithms, (0x01|0x02) },
 { "hostkeyalgorithms", sHostKeyAlgorithms, 0x01 },
 { "rsaauthentication", sDeprecated, (0x01|0x02) },
 { "pubkeyauthentication", sPubkeyAuthentication, (0x01|0x02) },
 { "pubkeyacceptedalgorithms", sPubkeyAcceptedAlgorithms, (0x01|0x02) },
 { "pubkeyacceptedkeytypes", sPubkeyAcceptedAlgorithms, (0x01|0x02) },
 { "pubkeyauthoptions", sPubkeyAuthOptions, (0x01|0x02) },
 { "dsaauthentication", sPubkeyAuthentication, 0x01 },
 { "kerberosauthentication", sUnsupported, (0x01|0x02) },
 { "kerberosorlocalpasswd", sUnsupported, 0x01 },
 { "kerberosticketcleanup", sUnsupported, 0x01 },
 { "kerberosgetafstoken", sUnsupported, 0x01 },

 { "kerberostgtpassing", sUnsupported, 0x01 },
 { "afstokenpassing", sUnsupported, 0x01 },





 { "gssapiauthentication", sUnsupported, (0x01|0x02) },
 { "gssapicleanupcredentials", sUnsupported, 0x01 },
 { "gssapistrictacceptorcheck", sUnsupported, 0x01 },

 { "passwordauthentication", sPasswordAuthentication, (0x01|0x02) },
 { "kbdinteractiveauthentication", sKbdInteractiveAuthentication, (0x01|0x02) },
 { "challengeresponseauthentication", sKbdInteractiveAuthentication, (0x01|0x02) },
 { "skeyauthentication", sKbdInteractiveAuthentication, (0x01|0x02) },
 { "checkmail", sDeprecated, 0x01 },
 { "listenaddress", sListenAddress, 0x01 },
 { "addressfamily", sAddressFamily, 0x01 },
 { "printmotd", sPrintMotd, 0x01 },



 { "printlastlog", sPrintLastLog, 0x01 },

 { "ignorerhosts", sIgnoreRhosts, (0x01|0x02) },
 { "ignoreuserknownhosts", sIgnoreUserKnownHosts, 0x01 },
 { "x11forwarding", sX11Forwarding, (0x01|0x02) },
 { "x11displayoffset", sX11DisplayOffset, (0x01|0x02) },
 { "x11uselocalhost", sX11UseLocalhost, (0x01|0x02) },
 { "xauthlocation", sXAuthLocation, 0x01 },
 { "strictmodes", sStrictModes, 0x01 },
 { "permitemptypasswords", sEmptyPasswd, (0x01|0x02) },
 { "permituserenvironment", sPermitUserEnvironment, 0x01 },
 { "uselogin", sDeprecated, 0x01 },
 { "compression", sCompression, 0x01 },
 { "rekeylimit", sRekeyLimit, (0x01|0x02) },
 { "tcpkeepalive", sTCPKeepAlive, 0x01 },
 { "keepalive", sTCPKeepAlive, 0x01 },
 { "allowtcpforwarding", sAllowTcpForwarding, (0x01|0x02) },
 { "allowagentforwarding", sAllowAgentForwarding, (0x01|0x02) },
 { "allowusers", sAllowUsers, (0x01|0x02) },
 { "denyusers", sDenyUsers, (0x01|0x02) },
 { "allowgroups", sAllowGroups, (0x01|0x02) },
 { "denygroups", sDenyGroups, (0x01|0x02) },
 { "ciphers", sCiphers, 0x01 },
 { "macs", sMacs, 0x01 },
 { "protocol", sIgnore, 0x01 },
 { "gatewayports", sGatewayPorts, (0x01|0x02) },
 { "subsystem", sSubsystem, 0x01 },
 { "maxstartups", sMaxStartups, 0x01 },
 { "persourcemaxstartups", sPerSourceMaxStartups, 0x01 },
 { "persourcenetblocksize", sPerSourceNetBlockSize, 0x01 },
 { "maxauthtries", sMaxAuthTries, (0x01|0x02) },
 { "maxsessions", sMaxSessions, (0x01|0x02) },
 { "banner", sBanner, (0x01|0x02) },
 { "usedns", sUseDNS, 0x01 },
 { "verifyreversemapping", sDeprecated, 0x01 },
 { "reversemappingcheck", sDeprecated, 0x01 },
 { "clientaliveinterval", sClientAliveInterval, (0x01|0x02) },
 { "clientalivecountmax", sClientAliveCountMax, (0x01|0x02) },
 { "authorizedkeysfile", sAuthorizedKeysFile, (0x01|0x02) },
 { "authorizedkeysfile2", sDeprecated, (0x01|0x02) },
 { "useprivilegeseparation", sDeprecated, 0x01},
 { "acceptenv", sAcceptEnv, (0x01|0x02) },
 { "setenv", sSetEnv, (0x01|0x02) },
 { "permittunnel", sPermitTunnel, (0x01|0x02) },
 { "permittty", sPermitTTY, (0x01|0x02) },
 { "permituserrc", sPermitUserRC, (0x01|0x02) },
 { "match", sMatch, (0x01|0x02) },
 { "permitopen", sPermitOpen, (0x01|0x02) },
 { "permitlisten", sPermitListen, (0x01|0x02) },
 { "forcecommand", sForceCommand, (0x01|0x02) },
 { "chrootdirectory", sChrootDirectory, (0x01|0x02) },
 { "hostcertificate", sHostCertificate, 0x01 },
 { "revokedkeys", sRevokedKeys, (0x01|0x02) },
 { "trustedusercakeys", sTrustedUserCAKeys, (0x01|0x02) },
 { "authorizedprincipalsfile", sAuthorizedPrincipalsFile, (0x01|0x02) },
 { "kexalgorithms", sKexAlgorithms, 0x01 },
 { "include", sInclude, (0x01|0x02) },
 { "ipqos", sIPQoS, (0x01|0x02) },
 { "authorizedkeyscommand", sAuthorizedKeysCommand, (0x01|0x02) },
 { "authorizedkeyscommanduser", sAuthorizedKeysCommandUser, (0x01|0x02) },
 { "authorizedprincipalscommand", sAuthorizedPrincipalsCommand, (0x01|0x02) },
 { "authorizedprincipalscommanduser", sAuthorizedPrincipalsCommandUser, (0x01|0x02) },
 { "versionaddendum", sVersionAddendum, 0x01 },
 { "authenticationmethods", sAuthenticationMethods, (0x01|0x02) },
 { "streamlocalbindmask", sStreamLocalBindMask, (0x01|0x02) },
 { "streamlocalbindunlink", sStreamLocalBindUnlink, (0x01|0x02) },
 { "allowstreamlocalforwarding", sAllowStreamLocalForwarding, (0x01|0x02) },
 { "fingerprinthash", sFingerprintHash, 0x01 },
 { "disableforwarding", sDisableForwarding, (0x01|0x02) },
 { "exposeauthinfo", sExposeAuthInfo, (0x01|0x02) },
 { "rdomain", sRDomain, (0x01|0x02) },
 { "casignaturealgorithms", sCASignatureAlgorithms, (0x01|0x02) },
 { "securitykeyprovider", sSecurityKeyProvider, 0x01 },
 { "requiredrsasize", sRequiredRSASize, (0x01|0x02) },
 { 
  ((void *)0)
      , sBadOption, 0 }
};

static struct {
 int val;
 char *text;
} tunmode_desc[] = {
 { 0x00, "no" },
 { 0x01, "point-to-point" },
 { 0x02, "ethernet" },
 { (0x01|0x02), "yes" },
 { -1, 
      ((void *)0) 
           }
};



static const char *
lookup_opcode_name(ServerOpCodes code)
{
 u_int i;

 for (i = 0; keywords[i].name != 
                                ((void *)0)
                                    ; i++)
  if (keywords[i].opcode == code)
   return(keywords[i].name);
 return "UNKNOWN";
}






static ServerOpCodes
parse_token(const char *cp, const char *filename,
     int linenum, u_int *flags)
{
 u_int i;

 for (i = 0; keywords[i].name; i++)
  if (strcasecmp(cp, keywords[i].name) == 0) {
   *flags = keywords[i].flags;
   return keywords[i].opcode;
  }

 sshlog("servconf.c", __func__, 728, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "%s: line %d: Bad configuration option: %s", filename, linenum, cp)
                           ;
 return sBadOption;
}

char *
derelativise_path(const char *path)
{
 char *expanded, *ret, cwd[
                          4096
                                  ];

 if (strcasecmp(path, "none") == 0)
  return xstrdup("none");
 expanded = tilde_expand_filename(path, getuid());
 if (path_absolute(expanded))
  return expanded;
 if (getcwd(cwd, sizeof(cwd)) == 
                                ((void *)0)
                                    )
  sshfatal("servconf.c", __func__, 744, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "getcwd: %s", strerror(
 (*__errno_location ())
 ));
 xasprintf(&ret, "%s/%s", cwd, expanded);
 free(expanded);
 return ret;
}

static void
add_listen_addr(ServerOptions *options, const char *addr,
    const char *rdomain, int port)
{
 u_int i;

 if (port > 0)
  add_one_listen_addr(options, addr, rdomain, port);
 else {
  for (i = 0; i < options->num_ports; i++) {
   add_one_listen_addr(options, addr, rdomain,
       options->ports[i]);
  }
 }
}

static void
add_one_listen_addr(ServerOptions *options, const char *addr,
    const char *rdomain, int port)
{
 struct addrinfo hints, *ai, *aitop;
 char strport[
             32
                       ];
 int gaierr;
 u_int i;


 for (i = 0; i < options->num_listen_addrs; i++) {
  if (rdomain == 
                ((void *)0) 
                     && options->listen_addrs[i].rdomain == 
                                                            ((void *)0)
                                                                )
   break;
  if (rdomain == 
                ((void *)0) 
                     || options->listen_addrs[i].rdomain == 
                                                            ((void *)0)
                                                                )
   continue;
  if (strcmp(rdomain, options->listen_addrs[i].rdomain) == 0)
   break;
 }
 if (i >= options->num_listen_addrs) {

  if (i >= 0x7fffffff)
   sshfatal("servconf.c", __func__, 787, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "too many listen addresses");
  options->listen_addrs = xrecallocarray(options->listen_addrs,
      options->num_listen_addrs, options->num_listen_addrs + 1,
      sizeof(*options->listen_addrs));
  i = options->num_listen_addrs++;
  if (rdomain != 
                ((void *)0)
                    )
   options->listen_addrs[i].rdomain = xstrdup(rdomain);
 }


 memset(&hints, 0, sizeof(hints));
 hints.ai_family = options->address_family;
 hints.ai_socktype = 
                    SOCK_STREAM
                               ;
 hints.ai_flags = (addr == 
                          ((void *)0)
                              ) ? 
                                  0x0001 
                                             : 0;
 snprintf(strport, sizeof strport, "%d", port);
 if ((gaierr = getaddrinfo(addr, strport, &hints, &aitop)) != 0)
  sshfatal("servconf.c", __func__, 803, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "bad addr or host: %s (%s)", addr ? addr : "<NULL>", ssh_gai_strerror(gaierr))

                               ;
 for (ai = aitop; ai->ai_next; ai = ai->ai_next)
  ;
 ai->ai_next = options->listen_addrs[i].addrs;
 options->listen_addrs[i].addrs = aitop;
}


static int
valid_rdomain(const char *name)
{

 return sys_valid_rdomain(name);
}





static void
queue_listen_addr(ServerOptions *options, const char *addr,
    const char *rdomain, int port)
{
 struct queued_listenaddr *qla;

 options->queued_listen_addrs = xrecallocarray(
     options->queued_listen_addrs,
     options->num_queued_listens, options->num_queued_listens + 1,
     sizeof(*options->queued_listen_addrs));
 qla = &options->queued_listen_addrs[options->num_queued_listens++];
 qla->addr = xstrdup(addr);
 qla->port = port;
 qla->rdomain = rdomain == 
                          ((void *)0) 
                               ? 
                                 ((void *)0) 
                                      : xstrdup(rdomain);
}




static void
process_queued_listen_addrs(ServerOptions *options)
{
 u_int i;
 struct queued_listenaddr *qla;

 if (options->num_ports == 0)
  options->ports[options->num_ports++] = 22;
 if (options->address_family == -1)
  options->address_family = 
                           0
                                    ;

 for (i = 0; i < options->num_queued_listens; i++) {
  qla = &options->queued_listen_addrs[i];
  add_listen_addr(options, qla->addr, qla->rdomain, qla->port);
  free(qla->addr);
  free(qla->rdomain);
 }
 free(options->queued_listen_addrs);
 options->queued_listen_addrs = 
                               ((void *)0)
                                   ;
 options->num_queued_listens = 0;
}





static void
process_permitopen_list(struct ssh *ssh, ServerOpCodes opcode,
    char **opens, u_int num_opens)
{
 u_int i;
 int port;
 char *host, *arg, *oarg;
 int where = opcode == sPermitOpen ? (1<<1) : (1);
 const char *what = lookup_opcode_name(opcode);

 channel_clear_permission(ssh, 0x100, where);
 if (num_opens == 0)
  return;


 if (num_opens == 1 && strcmp(opens[0], "any") == 0)
  return;
 if (num_opens == 1 && strcmp(opens[0], "none") == 0) {
  channel_disable_admin(ssh, where);
  return;
 }

 for (i = 0; i < num_opens; i++) {
  oarg = arg = xstrdup(opens[i]);
  host = hpdelim(&arg);
  if (host == 
             ((void *)0)
                 )
   sshfatal("servconf.c", __func__, 923, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "missing host in %s", what);
  host = cleanhostname(host);
  if (arg == 
            ((void *)0) 
                 || ((port = permitopen_port(arg)) < 0))
   sshfatal("servconf.c", __func__, 926, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "bad port number in %s", what);

  channel_add_permission(ssh, 0x100,
      where, host, port);
  free(oarg);
 }
}




void
process_permitopen(struct ssh *ssh, ServerOptions *options)
{
 process_permitopen_list(ssh, sPermitOpen,
     options->permitted_opens, options->num_permitted_opens);
 process_permitopen_list(ssh, sPermitListen,
     options->permitted_listens,
     options->num_permitted_listens);
}

struct connection_info *
get_connection_info(struct ssh *ssh, int populate, int use_dns)
{
 static struct connection_info ci;

 if (ssh == 
           ((void *)0) 
                || !populate)
  return &ci;
 ci.host = auth_get_canonical_hostname(ssh, use_dns);
 ci.address = ssh_remote_ipaddr(ssh);
 ci.laddress = ssh_local_ipaddr(ssh);
 ci.lport = ssh_local_port(ssh);
 ci.rdomain = ssh_packet_rdomain_in(ssh);
 return &ci;
}
static int
match_cfg_line_group(const char *grps, int line, const char *user)
{
 int result = 0;
 struct passwd *pw;

 if (user == 
            ((void *)0)
                )
  goto out;

 if ((pw = getpwnam(user)) == 
                             ((void *)0)
                                 ) {
  sshlog("servconf.c", __func__, 1005, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Can't match group at line %d because user %.100s does " "not exist", line, user)
                              ;
 } else if (ga_init(pw->pw_name, pw->pw_gid) == 0) {
  sshlog("servconf.c", __func__, 1008, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Can't Match group because user %.100s not in any group " "at line %d", user, line)
                               ;
 } else if (ga_match_pattern_list(grps) != 1) {
  sshlog("servconf.c", __func__, 1011, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "user %.100s does not match group list %.100s at line %d", user, grps, line)
                       ;
 } else {
  sshlog("servconf.c", __func__, 1014, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "user %.100s matched group list %.100s at line %d", user, grps, line)
                 ;
  result = 1;
 }
out:
 ga_free();
 return result;
}

static void
match_test_missing_fatal(const char *criteria, const char *attrib)
{
 sshfatal("servconf.c", __func__, 1026, 0, SYSLOG_LEVEL_FATAL, 
((void *)0)
, "'Match %s' in configuration but '%s' not in connection " "test specification.", criteria, attrib)
                                             ;
}






static int
match_cfg_line(char **condition, int line, struct connection_info *ci)
{
 int result = 1, attributes = 0, port;
 char *arg, *attrib, *cp = *condition;

 if (ci == 
          ((void *)0)
              )
  sshlog("servconf.c", __func__, 1042, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "checking syntax for 'Match %s'", cp);
 else
  sshlog("servconf.c", __func__, 1044, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "checking match for '%s' user %s host %s addr %s " "laddr %s lport %d", cp, ci->user ? ci->user : "(null)", ci->host ? ci->host : "(null)", ci->address ? ci->address : "(null)", ci->laddress ? ci->laddress : "(null)", ci->lport)



                                                        ;

 while ((attrib = strdelim(&cp)) && *attrib != '\0') {

  if (*attrib == '#') {
   cp = 
       ((void *)0)
           ;
   break;
  }
  arg = 
       ((void *)0)
           ;
  attributes++;

  if (strcasecmp(attrib, "all") == 0) {
   if (attributes > 1 || ((arg = strdelim(&cp)) != 
                                                  ((void *)0) 
                                                       &&
       *arg != '\0' && *arg != '#')) {
    sshlog("servconf.c", __func__, 1062, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "'all' cannot be combined with other " "Match attributes")
                           ;
    return -1;
   }
   if (arg != 
             ((void *)0) 
                  && *arg == '#')
    cp = 
        ((void *)0)
            ;
   *condition = cp;
   return 1;
  }

  if ((arg = strdelim(&cp)) == 
                              ((void *)0) 
                                   ||
      *arg == '\0' || *arg == '#') {
   sshlog("servconf.c", __func__, 1074, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Missing Match criteria for %s", attrib);
   return -1;
  }
  if (strcasecmp(attrib, "user") == 0) {
   if (ci == 
            ((void *)0) 
                 || (ci->test && ci->user == 
                                             ((void *)0)
                                                 )) {
    result = 0;
    continue;
   }
   if (ci->user == 
                  ((void *)0)
                      )
    match_test_missing_fatal("User", "user");
   if (match_usergroup_pattern_list(ci->user, arg) != 1)
    result = 0;
   else
    sshlog("servconf.c", __func__, 1087, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "user %.100s matched 'User %.100s' at " "line %d", ci->user, arg, line)
                                       ;
  } else if (strcasecmp(attrib, "group") == 0) {
   if (ci == 
            ((void *)0) 
                 || (ci->test && ci->user == 
                                             ((void *)0)
                                                 )) {
    result = 0;
    continue;
   }
   if (ci->user == 
                  ((void *)0)
                      )
    match_test_missing_fatal("Group", "user");
   switch (match_cfg_line_group(arg, line, ci->user)) {
   case -1:
    return -1;
   case 0:
    result = 0;
   }
  } else if (strcasecmp(attrib, "host") == 0) {
   if (ci == 
            ((void *)0) 
                 || (ci->test && ci->host == 
                                             ((void *)0)
                                                 )) {
    result = 0;
    continue;
   }
   if (ci->host == 
                  ((void *)0)
                      )
    match_test_missing_fatal("Host", "host");
   if (match_hostname(ci->host, arg) != 1)
    result = 0;
   else
    sshlog("servconf.c", __func__, 1112, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "connection from %.100s matched 'Host " "%.100s' at line %d", ci->host, arg, line)
                                                  ;
  } else if (strcasecmp(attrib, "address") == 0) {
   if (ci == 
            ((void *)0) 
                 || (ci->test && ci->address == 
                                                ((void *)0)
                                                    )) {
    if (addr_match_list(
                       ((void *)0)
                           , arg) != 0)
     sshfatal("servconf.c", __func__, 1117, 0, SYSLOG_LEVEL_FATAL, 
    ((void *)0)
    , "Invalid Match address argument " "'%s' at line %d", arg, line)
                                      ;
    result = 0;
    continue;
   }
   if (ci->address == 
                     ((void *)0)
                         )
    match_test_missing_fatal("Address", "addr");
   switch (addr_match_list(ci->address, arg)) {
   case 1:
    sshlog("servconf.c", __func__, 1126, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "connection from %.100s matched 'Address " "%.100s' at line %d", ci->address, arg, line)
                                                     ;
    break;
   case 0:
   case -1:
    result = 0;
    break;
   case -2:
    return -1;
   }
  } else if (strcasecmp(attrib, "localaddress") == 0){
   if (ci == 
            ((void *)0) 
                 || (ci->test && ci->laddress == 
                                                 ((void *)0)
                                                     )) {
    if (addr_match_list(
                       ((void *)0)
                           , arg) != 0)
     sshfatal("servconf.c", __func__, 1139, 0, SYSLOG_LEVEL_FATAL, 
    ((void *)0)
    , "Invalid Match localaddress " "argument '%s' at line %d", arg, line)

              ;
    result = 0;
    continue;
   }
   if (ci->laddress == 
                      ((void *)0)
                          )
    match_test_missing_fatal("LocalAddress",
        "laddr");
   switch (addr_match_list(ci->laddress, arg)) {
   case 1:
    sshlog("servconf.c", __func__, 1150, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "connection from %.100s matched " "'LocalAddress %.100s' at line %d", ci->laddress, arg, line)

                                ;
    break;
   case 0:
   case -1:
    result = 0;
    break;
   case -2:
    return -1;
   }
  } else if (strcasecmp(attrib, "localport") == 0) {
   if ((port = a2port(arg)) == -1) {
    sshlog("servconf.c", __func__, 1163, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Invalid LocalPort '%s' on Match line", arg)
            ;
    return -1;
   }
   if (ci == 
            ((void *)0) 
                 || (ci->test && ci->lport == -1)) {
    result = 0;
    continue;
   }
   if (ci->lport == 0)
    match_test_missing_fatal("LocalPort", "lport");

   if (port == ci->lport)
    sshlog("servconf.c", __func__, 1175, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "connection from %.100s matched " "'LocalPort %d' at line %d", ci->laddress, port, line)

                                 ;
   else
    result = 0;
  } else if (strcasecmp(attrib, "rdomain") == 0) {
   if (ci == 
            ((void *)0) 
                 || (ci->test && ci->rdomain == 
                                                ((void *)0)
                                                    )) {
    result = 0;
    continue;
   }
   if (ci->rdomain == 
                     ((void *)0)
                         )
    match_test_missing_fatal("RDomain", "rdomain");
   if (match_pattern_list(ci->rdomain, arg, 0) != 1)
    result = 0;
   else
    sshlog("servconf.c", __func__, 1190, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "user %.100s matched 'RDomain %.100s' at " "line %d", ci->rdomain, arg, line)
                                          ;
  } else {
   sshlog("servconf.c", __func__, 1193, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Unsupported Match attribute %s", attrib);
   return -1;
  }
 }
 if (attributes == 0) {
  sshlog("servconf.c", __func__, 1198, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "One or more attributes required for Match");
  return -1;
 }
 if (ci != 
          ((void *)0)
              )
  sshlog("servconf.c", __func__, 1202, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "match %sfound", result ? "" : "not ");
 *condition = cp;
 return result;
}




struct multistate {
 char *key;
 int value;
};
static const struct multistate multistate_flag[] = {
 { "yes", 1 },
 { "no", 0 },
 { 
  ((void *)0)
      , -1 }
};
static const struct multistate multistate_ignore_rhosts[] = {
 { "yes", 1 },
 { "no", 0 },
 { "shosts-only", 2 },
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
static const struct multistate multistate_permitrootlogin[] = {
 { "without-password", 2 },
 { "prohibit-password", 2 },
 { "forced-commands-only", 1 },
 { "yes", 3 },
 { "no", 0 },
 { 
  ((void *)0)
      , -1 }
};
static const struct multistate multistate_compression[] = {

 { "yes", 2 },
 { "delayed", 2 },

 { "no", 0 },
 { 
  ((void *)0)
      , -1 }
};
static const struct multistate multistate_gatewayports[] = {
 { "clientspecified", 2 },
 { "yes", 1 },
 { "no", 0 },
 { 
  ((void *)0)
      , -1 }
};
static const struct multistate multistate_tcpfwd[] = {
 { "yes", ((1)|(1<<1)) },
 { "all", ((1)|(1<<1)) },
 { "no", 0 },
 { "remote", (1) },
 { "local", (1<<1) },
 { 
  ((void *)0)
      , -1 }
};

static int
process_server_config_line_depth(ServerOptions *options, char *line,
    const char *filename, int linenum, int *activep,
    struct connection_info *connectinfo, int *inc_flags, int depth,
    struct include_list *includes)
{
 char *str, ***chararrayptr, **charptr, *arg, *arg2, *p, *keyword;
 int cmdline = 0, *intptr, value, value2, n, port, oactive, r, found;
 SyslogFacility *log_facility_ptr;
 LogLevel *log_level_ptr;
 ServerOpCodes opcode;
 u_int i, *uintptr, uvalue, flags = 0;
 size_t len;
 long long val64;
 const struct multistate *multistate_ptr;
 const char *errstr;
 struct include_item *item;
 _ssh_compat_glob_t gbuf;
 char **oav = 
             ((void *)0)
                 , **av;
 int oac = 0, ac;
 int ret = -1;


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
 if (!keyword || !*keyword || *keyword == '#')
  return 0;
 if (str == 
           ((void *)0) 
                || *str == '\0') {
  sshlog("servconf.c", __func__, 1302, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s line %d: no argument after keyword \"%s\"", filename, linenum, keyword)
                                 ;
  return -1;
 }
 intptr = 
         ((void *)0)
             ;
 charptr = 
          ((void *)0)
              ;
 opcode = parse_token(keyword, filename, linenum, &flags);

 if (argv_split(str, &oac, &oav, 1) != 0) {
  sshlog("servconf.c", __func__, 1311, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s line %d: invalid quotes", filename, linenum);
  return -1;
 }
 ac = oac;
 av = oav;

 if (activep == 
               ((void *)0)
                   ) {
  cmdline = 1;
  activep = &cmdline;
 }
 if (*activep && opcode != sMatch && opcode != sInclude)
  sshlog("servconf.c", __func__, 1322, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "%s:%d setting %s %s", filename, linenum, keyword, str);
 if (*activep == 0 && !(flags & 0x02)) {
  if (connectinfo == 
                    ((void *)0)
                        ) {
   sshfatal("servconf.c", __func__, 1325, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: Directive '%s' is not allowed " "within a Match block", filename, linenum, keyword)
                                                          ;
  } else {
   ret = 0;
   goto out;
  }
 }

 switch (opcode) {

 case sUsePAM:
  intptr = &options->use_pam;
  goto parse_flag;


 case sBadOption:
  goto out;
 case sPort:

  if (options->ports_from_cmdline) {
   argv_consume(&ac);
   break;
  }
  if (options->num_ports >= 256)
   sshfatal("servconf.c", __func__, 1349, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: too many ports.", filename, linenum)
                         ;
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 1353, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: missing port number.", filename, linenum)
                         ;
  options->ports[options->num_ports++] = a2port(arg);
  if (options->ports[options->num_ports-1] <= 0)
   sshfatal("servconf.c", __func__, 1357, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: Badly formatted port number.", filename, linenum)
                         ;
  break;

 case sLoginGraceTime:
  intptr = &options->login_grace_time;
 parse_time:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 1366, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: missing time value.", filename, linenum)
                         ;
  if ((value = convtime(arg)) == -1)
   sshfatal("servconf.c", __func__, 1369, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: invalid time value.", filename, linenum)
                         ;
  if (*activep && *intptr == -1)
   *intptr = value;
  break;

 case sListenAddress:
  arg = argv_next(&ac, &av);
  if (arg == 
            ((void *)0) 
                 || *arg == '\0')
   sshfatal("servconf.c", __func__, 1378, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: missing address", filename, linenum)
                         ;

  if (strchr(arg, '[') == 
                         ((void *)0) 
                              && (p = strchr(arg, ':')) != 
                                                           ((void *)0)
      
     && strchr(p+1, ':') != 
                            ((void *)0)
                                ) {
   port = 0;
   p = arg;
  } else {
   arg2 = 
         ((void *)0)
             ;
   p = hpdelim(&arg);
   if (p == 
           ((void *)0)
               )
    sshfatal("servconf.c", __func__, 1389, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s line %d: bad address:port usage", filename, linenum)
                          ;
   p = cleanhostname(p);
   if (arg == 
             ((void *)0)
                 )
    port = 0;
   else if ((port = a2port(arg)) <= 0)
    sshfatal("servconf.c", __func__, 1395, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s line %d: bad port number", filename, linenum)
                          ;
  }

  arg2 = 
        ((void *)0)
            ;
  if ((arg = argv_next(&ac, &av)) != 
                                    ((void *)0)
                                        ) {
   if (strcmp(arg, "rdomain") != 0 ||
       (arg2 = argv_next(&ac, &av)) == 
                                      ((void *)0)
                                          )
    sshfatal("servconf.c", __func__, 1403, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s line %d: bad ListenAddress syntax", filename, linenum)
                          ;
   if (!valid_rdomain(arg2))
    sshfatal("servconf.c", __func__, 1406, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s line %d: bad routing domain", filename, linenum)
                          ;
  }
  queue_listen_addr(options, p, arg2, port);

  break;

 case sAddressFamily:
  intptr = &options->address_family;
  multistate_ptr = multistate_addressfamily;
 parse_multistate:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 1419, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: missing argument.", filename, linenum)
                         ;
  value = -1;
  for (i = 0; multistate_ptr[i].key != 
                                      ((void *)0)
                                          ; i++) {
   if (strcasecmp(arg, multistate_ptr[i].key) == 0) {
    value = multistate_ptr[i].value;
    break;
   }
  }
  if (value == -1)
   sshfatal("servconf.c", __func__, 1429, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: unsupported option \"%s\".", filename, linenum, arg)
                              ;
  if (*activep && *intptr == -1)
   *intptr = value;
  break;

 case sHostKeyFile:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 1438, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: missing file name.", filename, linenum)
                         ;
  if (*activep) {
   servconf_add_hostkey(filename, linenum,
       options, arg, 1);
  }
  break;

 case sHostKeyAgent:
  charptr = &options->host_key_agent;
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 1450, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: missing socket name.", filename, linenum)
                         ;
  if (*activep && *charptr == 
                             ((void *)0)
                                 )
   *charptr = !strcmp(arg, "SSH_AUTH_SOCK") ?
       xstrdup(arg) : derelativise_path(arg);
  break;

 case sHostCertificate:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 1460, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: missing file name.", filename, linenum)
                         ;
  if (*activep)
   servconf_add_hostcert(filename, linenum, options, arg);
  break;

 case sPidFile:
  charptr = &options->pid_file;
 parse_filename:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 1471, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: missing file name.", filename, linenum)
                         ;
  if (*activep && *charptr == 
                             ((void *)0)
                                 ) {
   *charptr = derelativise_path(arg);

   if (intptr != 
                ((void *)0)
                    )
    *intptr = *intptr + 1;
  }
  break;

 case sModuliFile:
  charptr = &options->moduli_file;
  goto parse_filename;

 case sPermitRootLogin:
  intptr = &options->permit_root_login;
  multistate_ptr = multistate_permitrootlogin;
  goto parse_multistate;

 case sIgnoreRhosts:
  intptr = &options->ignore_rhosts;
  multistate_ptr = multistate_ignore_rhosts;
  goto parse_multistate;

 case sIgnoreUserKnownHosts:
  intptr = &options->ignore_user_known_hosts;
 parse_flag:
  multistate_ptr = multistate_flag;
  goto parse_multistate;

 case sHostbasedAuthentication:
  intptr = &options->hostbased_authentication;
  goto parse_flag;

 case sHostbasedUsesNameFromPacketOnly:
  intptr = &options->hostbased_uses_name_from_packet_only;
  goto parse_flag;

 case sHostbasedAcceptedAlgorithms:
  charptr = &options->hostbased_accepted_algos;
 parse_pubkey_algos:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 1514, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: Missing argument.", filename, linenum)
                         ;
  if (*arg != '-' &&
      !sshkey_names_valid2(*arg == '+' || *arg == '^' ?
      arg + 1 : arg, 1))
   sshfatal("servconf.c", __func__, 1519, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: Bad key types '%s'.", filename, linenum, arg ? arg : "<NONE>")
                                               ;
  if (*activep && *charptr == 
                             ((void *)0)
                                 )
   *charptr = xstrdup(arg);
  break;

 case sHostKeyAlgorithms:
  charptr = &options->hostkeyalgorithms;
  goto parse_pubkey_algos;

 case sCASignatureAlgorithms:
  charptr = &options->ca_sign_algorithms;
  goto parse_pubkey_algos;

 case sPubkeyAuthentication:
  intptr = &options->pubkey_authentication;
  goto parse_flag;

 case sPubkeyAcceptedAlgorithms:
  charptr = &options->pubkey_accepted_algos;
  goto parse_pubkey_algos;

 case sPubkeyAuthOptions:
  intptr = &options->pubkey_auth_options;
  value = 0;
  while ((arg = argv_next(&ac, &av)) != 
                                       ((void *)0)
                                           ) {
   if (strcasecmp(arg, "none") == 0)
    continue;
   if (strcasecmp(arg, "touch-required") == 0)
    value |= (1);
   else if (strcasecmp(arg, "verify-required") == 0)
    value |= (1<<1);
   else {
    sshlog("servconf.c", __func__, 1552, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%s line %d: unsupported %s option %s", filename, linenum, keyword, arg)
                                        ;
    goto out;
   }
  }
  if (*activep && *intptr == -1)
   *intptr = value;
  break;

 case sKerberosAuthentication:
  intptr = &options->kerberos_authentication;
  goto parse_flag;

 case sKerberosOrLocalPasswd:
  intptr = &options->kerberos_or_local_passwd;
  goto parse_flag;

 case sKerberosTicketCleanup:
  intptr = &options->kerberos_ticket_cleanup;
  goto parse_flag;

 case sKerberosGetAFSToken:
  intptr = &options->kerberos_get_afs_token;
  goto parse_flag;

 case sGssAuthentication:
  intptr = &options->gss_authentication;
  goto parse_flag;

 case sGssCleanupCreds:
  intptr = &options->gss_cleanup_creds;
  goto parse_flag;

 case sGssStrictAcceptor:
  intptr = &options->gss_strict_acceptor;
  goto parse_flag;

 case sPasswordAuthentication:
  intptr = &options->password_authentication;
  goto parse_flag;

 case sKbdInteractiveAuthentication:
  intptr = &options->kbd_interactive_authentication;
  goto parse_flag;

 case sPrintMotd:
  intptr = &options->print_motd;
  goto parse_flag;

 case sPrintLastLog:
  intptr = &options->print_lastlog;
  goto parse_flag;

 case sX11Forwarding:
  intptr = &options->x11_forwarding;
  goto parse_flag;

 case sX11DisplayOffset:
  intptr = &options->x11_display_offset;
 parse_int:
  arg = argv_next(&ac, &av);
  if ((errstr = atoi_err(arg, &value)) != 
                                         ((void *)0)
                                             )
   sshfatal("servconf.c", __func__, 1614, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s integer value %s.", filename, linenum, keyword, errstr)
                                          ;
  if (*activep && *intptr == -1)
   *intptr = value;
  break;

 case sX11UseLocalhost:
  intptr = &options->x11_use_localhost;
  goto parse_flag;

 case sXAuthLocation:
  charptr = &options->xauth_location;
  goto parse_filename;

 case sPermitTTY:
  intptr = &options->permit_tty;
  goto parse_flag;

 case sPermitUserRC:
  intptr = &options->permit_user_rc;
  goto parse_flag;

 case sStrictModes:
  intptr = &options->strict_modes;
  goto parse_flag;

 case sTCPKeepAlive:
  intptr = &options->tcp_keep_alive;
  goto parse_flag;

 case sEmptyPasswd:
  intptr = &options->permit_empty_passwd;
  goto parse_flag;

 case sPermitUserEnvironment:
  intptr = &options->permit_user_env;
  charptr = &options->permit_user_env_allowlist;
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 1653, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  value = 0;
  p = 
     ((void *)0)
         ;
  if (strcmp(arg, "yes") == 0)
   value = 1;
  else if (strcmp(arg, "no") == 0)
   value = 0;
  else {

   value = 1;
   p = xstrdup(arg);
  }
  if (*activep && *intptr == -1) {
   *intptr = value;
   *charptr = p;
   p = 
      ((void *)0)
          ;
  }
  free(p);
  break;

 case sCompression:
  intptr = &options->compression;
  multistate_ptr = multistate_compression;
  goto parse_multistate;

 case sRekeyLimit:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 1682, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  if (strcmp(arg, "default") == 0) {
   val64 = 0;
  } else {
   if (scan_scaled(arg, &val64) == -1)
    sshfatal("servconf.c", __func__, 1688, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%.200s line %d: Bad %s number '%s': %s", filename, linenum, keyword, arg, strerror(
   (*__errno_location ())
   ))

                             ;
   if (val64 != 0 && val64 < 16)
    sshfatal("servconf.c", __func__, 1692, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%.200s line %d: %s too small", filename, linenum, keyword)
                                   ;
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

 case sGatewayPorts:
  intptr = &options->fwd_opts.gateway_ports;
  multistate_ptr = multistate_gatewayports;
  goto parse_multistate;

 case sUseDNS:
  intptr = &options->use_dns;
  goto parse_flag;

 case sLogFacility:
  log_facility_ptr = &options->log_facility;
  arg = argv_next(&ac, &av);
  value = log_facility_number(arg);
  if (value == SYSLOG_FACILITY_NOT_SET)
   sshfatal("servconf.c", __func__, 1721, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%.200s line %d: unsupported log facility '%s'", filename, linenum, arg ? arg : "<NONE>")
                                               ;
  if (*log_facility_ptr == -1)
   *log_facility_ptr = (SyslogFacility) value;
  break;

 case sLogLevel:
  log_level_ptr = &options->log_level;
  arg = argv_next(&ac, &av);
  value = log_level_number(arg);
  if (value == SYSLOG_LEVEL_NOT_SET)
   sshfatal("servconf.c", __func__, 1732, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%.200s line %d: unsupported log level '%s'", filename, linenum, arg ? arg : "<NONE>")
                                               ;
  if (*activep && *log_level_ptr == -1)
   *log_level_ptr = (LogLevel) value;
  break;

 case sLogVerbose:
  found = options->num_log_verbose == 0;
  i = 0;
  while ((arg = argv_next(&ac, &av)) != 
                                       ((void *)0)
                                           ) {
   if (*arg == '\0') {
    sshlog("servconf.c", __func__, 1743, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%s line %d: keyword %s empty argument", filename, linenum, keyword)
                                   ;
    goto out;
   }

   if (strcasecmp(arg, "none") == 0) {
    if (i > 0 || ac > 0) {
     sshlog("servconf.c", __func__, 1750, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "%s line %d: keyword %s \"none\" " "argument must appear alone.", filename, linenum, keyword)

                                    ;
     goto out;
    }
   }
   i++;
   if (!found || !*activep)
    continue;
   opt_array_append(filename, linenum, keyword,
       &options->log_verbose, &options->num_log_verbose,
       arg);
  }
  break;

 case sAllowTcpForwarding:
  intptr = &options->allow_tcp_forwarding;
  multistate_ptr = multistate_tcpfwd;
  goto parse_multistate;

 case sAllowStreamLocalForwarding:
  intptr = &options->allow_streamlocal_forwarding;
  multistate_ptr = multistate_tcpfwd;
  goto parse_multistate;

 case sAllowAgentForwarding:
  intptr = &options->allow_agent_forwarding;
  goto parse_flag;

 case sDisableForwarding:
  intptr = &options->disable_forwarding;
  goto parse_flag;

 case sAllowUsers:
  chararrayptr = &options->allow_users;
  uintptr = &options->num_allow_users;
 parse_allowdenyusers:
  while ((arg = argv_next(&ac, &av)) != 
                                       ((void *)0)
                                           ) {
   if (*arg == '\0' ||
       match_user(
                 ((void *)0)
                     , 
                       ((void *)0)
                           , 
                             ((void *)0)
                                 , arg) == -1)
    sshfatal("servconf.c", __func__, 1790, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s line %d: invalid %s pattern: \"%s\"", filename, linenum, keyword, arg)
                                        ;
   if (!*activep)
    continue;
   opt_array_append(filename, linenum, keyword,
       chararrayptr, uintptr, arg);
  }
  break;

 case sDenyUsers:
  chararrayptr = &options->deny_users;
  uintptr = &options->num_deny_users;
  goto parse_allowdenyusers;

 case sAllowGroups:
  chararrayptr = &options->allow_groups;
  uintptr = &options->num_allow_groups;
 parse_allowdenygroups:
  while ((arg = argv_next(&ac, &av)) != 
                                       ((void *)0)
                                           ) {
   if (*arg == '\0')
    sshfatal("servconf.c", __func__, 1810, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s line %d: empty %s pattern", filename, linenum, keyword)
                                   ;
   if (!*activep)
    continue;
   opt_array_append(filename, linenum, keyword,
       chararrayptr, uintptr, arg);
  }
  break;

 case sDenyGroups:
  chararrayptr = &options->deny_groups;
  uintptr = &options->num_deny_groups;
  goto parse_allowdenygroups;

 case sCiphers:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 1827, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  if (*arg != '-' &&
      !ciphers_valid(*arg == '+' || *arg == '^' ? arg + 1 : arg))
   sshfatal("servconf.c", __func__, 1831, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: Bad SSH2 cipher spec '%s'.", filename, linenum, arg ? arg : "<NONE>")
                                               ;
  if (options->ciphers == 
                         ((void *)0)
                             )
   options->ciphers = xstrdup(arg);
  break;

 case sMacs:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 1840, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  if (*arg != '-' &&
      !mac_valid(*arg == '+' || *arg == '^' ? arg + 1 : arg))
   sshfatal("servconf.c", __func__, 1844, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: Bad SSH2 mac spec '%s'.", filename, linenum, arg ? arg : "<NONE>")
                                               ;
  if (options->macs == 
                      ((void *)0)
                          )
   options->macs = xstrdup(arg);
  break;

 case sKexAlgorithms:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 1853, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  if (*arg != '-' &&
      !kex_names_valid(*arg == '+' || *arg == '^' ?
      arg + 1 : arg))
   sshfatal("servconf.c", __func__, 1858, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: Bad SSH2 KexAlgorithms '%s'.", filename, linenum, arg ? arg : "<NONE>")
                                               ;
  if (options->kex_algorithms == 
                                ((void *)0)
                                    )
   options->kex_algorithms = xstrdup(arg);
  break;

 case sSubsystem:
  if (options->num_subsystems >= 256) {
   sshfatal("servconf.c", __func__, 1866, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: too many subsystems defined.", filename, linenum)
                         ;
  }
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 1871, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  if (!*activep) {
   arg = argv_next(&ac, &av);
   break;
  }
  for (i = 0; i < options->num_subsystems; i++)
   if (strcmp(arg, options->subsystem_name[i]) == 0)
    sshfatal("servconf.c", __func__, 1879, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s line %d: Subsystem '%s' " "already defined.", filename, linenum, arg)
                                                   ;
  options->subsystem_name[options->num_subsystems] = xstrdup(arg);
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 1884, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: Missing subsystem command.", filename, linenum)
                         ;
  options->subsystem_command[options->num_subsystems] = xstrdup(arg);


  p = xstrdup(arg);
  len = strlen(p) + 1;
  while ((arg = argv_next(&ac, &av)) != 
                                       ((void *)0)
                                           ) {
   len += 1 + strlen(arg);
   p = xreallocarray(p, 1, len);
   strlcat(p, " ", len);
   strlcat(p, arg, len);
  }
  options->subsystem_args[options->num_subsystems] = p;
  options->num_subsystems++;
  break;

 case sMaxStartups:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 1904, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  if ((n = sscanf(arg, "%d:%d:%d",
      &options->max_startups_begin,
      &options->max_startups_rate,
      &options->max_startups)) == 3) {
   if (options->max_startups_begin >
       options->max_startups ||
       options->max_startups_rate > 100 ||
       options->max_startups_rate < 1)
    sshfatal("servconf.c", __func__, 1914, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s line %d: Invalid %s spec.", filename, linenum, keyword)
                                   ;
  } else if (n != 1)
   sshfatal("servconf.c", __func__, 1917, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: Invalid %s spec.", filename, linenum, keyword)
                                  ;
  else
   options->max_startups = options->max_startups_begin;
  break;

 case sPerSourceNetBlockSize:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 1926, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  switch (n = sscanf(arg, "%d:%d", &value, &value2)) {
  case 2:
   if (value2 < 0 || value2 > 128)
    n = -1;

  case 1:
   if (value < 0 || value > 32)
    n = -1;
  }
  if (n != 1 && n != 2)
   sshfatal("servconf.c", __func__, 1938, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: Invalid %s spec.", filename, linenum, keyword)
                                  ;
  if (*activep) {
   options->per_source_masklen_ipv4 = value;
   options->per_source_masklen_ipv6 = value2;
  }
  break;

 case sPerSourceMaxStartups:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 1949, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  if (strcmp(arg, "none") == 0) {
   value = 0x7fffffff;
  } else {
   if ((errstr = atoi_err(arg, &value)) != 
                                          ((void *)0)
                                              )
    sshfatal("servconf.c", __func__, 1955, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s line %d: %s integer value %s.", filename, linenum, keyword, errstr)
                                           ;
  }
  if (*activep)
   options->per_source_max_startups = value;
  break;

 case sMaxAuthTries:
  intptr = &options->max_authtries;
  goto parse_int;

 case sMaxSessions:
  intptr = &options->max_sessions;
  goto parse_int;

 case sBanner:
  charptr = &options->banner;
  goto parse_filename;







 case sAuthorizedKeysFile:
  uvalue = options->num_authkeys_files;
  while ((arg = argv_next(&ac, &av)) != 
                                       ((void *)0)
                                           ) {
   if (*arg == '\0') {
    sshlog("servconf.c", __func__, 1984, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%s line %d: keyword %s empty argument", filename, linenum, keyword)
                                   ;
    goto out;
   }
   arg2 = tilde_expand_filename(arg, getuid());
   if (*activep && uvalue == 0) {
    opt_array_append(filename, linenum, keyword,
        &options->authorized_keys_files,
        &options->num_authkeys_files, arg2);
   }
   free(arg2);
  }
  break;

 case sAuthorizedPrincipalsFile:
  charptr = &options->authorized_principals_file;
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 2002, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  if (*activep && *charptr == 
                             ((void *)0)
                                 ) {
   *charptr = tilde_expand_filename(arg, getuid());

   if (intptr != 
                ((void *)0)
                    )
    *intptr = *intptr + 1;
  }
  break;

 case sClientAliveInterval:
  intptr = &options->client_alive_interval;
  goto parse_time;

 case sClientAliveCountMax:
  intptr = &options->client_alive_count_max;
  goto parse_int;

 case sAcceptEnv:
  while ((arg = argv_next(&ac, &av)) != 
                                       ((void *)0)
                                           ) {
   if (*arg == '\0' || strchr(arg, '=') != 
                                          ((void *)0)
                                              )
    sshfatal("servconf.c", __func__, 2023, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s line %d: Invalid environment name.", filename, linenum)
                          ;
   if (!*activep)
    continue;
   opt_array_append(filename, linenum, keyword,
       &options->accept_env, &options->num_accept_env,
       arg);
  }
  break;

 case sSetEnv:
  uvalue = options->num_setenv;
  while ((arg = argv_next(&ac, &av)) != 
                                       ((void *)0)
                                           ) {
   if (*arg == '\0' || strchr(arg, '=') == 
                                          ((void *)0)
                                              )
    sshfatal("servconf.c", __func__, 2037, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s line %d: Invalid environment.", filename, linenum)
                          ;
   if (!*activep || uvalue != 0)
    continue;
   if (lookup_setenv_in_list(arg, options->setenv,
       options->num_setenv) != 
                              ((void *)0)
                                  ) {
    sshlog("servconf.c", __func__, 2043, 0, SYSLOG_LEVEL_DEBUG2, 
   ((void *)0)
   , "%s line %d: ignoring duplicate env " "name \"%.64s\"", filename, linenum, arg)
                                                 ;
    continue;
   }
   opt_array_append(filename, linenum, keyword,
       &options->setenv, &options->num_setenv, arg);
  }
  break;

 case sPermitTunnel:
  intptr = &options->permit_tun;
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 2056, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  value = -1;
  for (i = 0; tunmode_desc[i].val != -1; i++)
   if (strcmp(tunmode_desc[i].text, arg) == 0) {
    value = tunmode_desc[i].val;
    break;
   }
  if (value == -1)
   sshfatal("servconf.c", __func__, 2065, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: bad %s argument %s", filename, linenum, keyword, arg)
                                       ;
  if (*activep && *intptr == -1)
   *intptr = value;
  break;

 case sInclude:
  if (cmdline) {
   sshfatal("servconf.c", __func__, 2073, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Include directive not supported as a " "command-line option")
                             ;
  }
  value = 0;
  while ((arg2 = argv_next(&ac, &av)) != 
                                        ((void *)0)
                                            ) {
   if (*arg2 == '\0') {
    sshlog("servconf.c", __func__, 2079, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%s line %d: keyword %s empty argument", filename, linenum, keyword)
                                   ;
    goto out;
   }
   value++;
   found = 0;
   if (*arg2 != '/' && *arg2 != '~') {
    xasprintf(&arg, "%s/%s", "/usr/local/etc", arg2);
   } else
    arg = xstrdup(arg2);





   oactive = *activep;


   for((item) = ((includes)->tqh_first); (item) != 
  ((void *)0)
  ; (item) = ((item)->entry.tqe_next)) {
    if (strcmp(item->selector, arg) != 0)
     continue;
    if (item->filename != 
                         ((void *)0)
                             ) {
     parse_server_config_depth(options,
         item->filename, item->contents,
         includes, connectinfo,
         (*inc_flags & 0x08
             ? 0x08 : (oactive
                 ? 0 : 0x04)),
         activep, depth + 1);
    }
    found = 1;
    *activep = oactive;
   }
   if (found != 0) {
    free(arg);
    continue;
   }


   sshlog("servconf.c", __func__, 2118, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "%s line %d: new include %s", filename, linenum, arg)
                              ;
   if ((r = _ssh__compat_glob(arg, 0, 
           ((void *)0)
           , &gbuf)) != 0) {
    if (r != (-3)) {
     sshfatal("servconf.c", __func__, 2122, 0, SYSLOG_LEVEL_FATAL, 
    ((void *)0)
    , "%s line %d: include \"%s\" glob " "failed", filename, linenum, arg)
                                          ;
    }




    sshlog("servconf.c", __func__, 2129, 0, SYSLOG_LEVEL_DEBUG2, 
   ((void *)0)
   , "%s line %d: no match for %s", filename, linenum, arg)
                               ;
    item = xcalloc(1, sizeof(*item));
    item->selector = strdup(arg);
    do { (item)->entry.tqe_next = 
   ((void *)0)
   ; (item)->entry.tqe_prev = (includes)->tqh_last; *(includes)->tqh_last = (item); (includes)->tqh_last = &(item)->entry.tqe_next; } while (0)
                    ;
   }
   if (gbuf.gl_pathc > 0x7fffffff)
    sshfatal("servconf.c", __func__, 2137, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "too many glob results");
   for (n = 0; n < (int)gbuf.gl_pathc; n++) {
    sshlog("servconf.c", __func__, 2139, 0, SYSLOG_LEVEL_DEBUG2, 
   ((void *)0)
   , "%s line %d: including %s", filename, linenum, gbuf.gl_pathv[n])
                                            ;
    item = xcalloc(1, sizeof(*item));
    item->selector = strdup(arg);
    item->filename = strdup(gbuf.gl_pathv[n]);
    if ((item->contents = sshbuf_new()) == 
                                          ((void *)0)
                                              )
     sshfatal("servconf.c", __func__, 2145, 1, SYSLOG_LEVEL_FATAL, 
    ((void *)0)
    , "sshbuf_new failed");
    load_server_config(item->filename,
        item->contents);
    parse_server_config_depth(options,
        item->filename, item->contents,
        includes, connectinfo,
        (*inc_flags & 0x08
            ? 0x08 : (oactive
                ? 0 : 0x04)),
        activep, depth + 1);
    *activep = oactive;
    do { (item)->entry.tqe_next = 
   ((void *)0)
   ; (item)->entry.tqe_prev = (includes)->tqh_last; *(includes)->tqh_last = (item); (includes)->tqh_last = &(item)->entry.tqe_next; } while (0);
   }
   _ssh__compat_globfree(&gbuf);
   free(arg);
  }
  if (value == 0) {
   sshfatal("servconf.c", __func__, 2162, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing filename argument", filename, linenum, keyword)
                                  ;
  }
  break;

 case sMatch:
  if (cmdline)
   sshfatal("servconf.c", __func__, 2169, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Match directive not supported as a command-line " "option")
                ;
  value = match_cfg_line(&str, linenum,
      (*inc_flags & 0x04 ? 
                                       ((void *)0) 
                                            : connectinfo));
  if (value < 0)
   sshfatal("servconf.c", __func__, 2174, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: Bad Match condition", filename, linenum)
               ;
  *activep = (*inc_flags & 0x04) ? 0 : value;




  *inc_flags &= ~0x08;




  if (str == 
            ((void *)0) 
                 || *str == '\0')
   argv_consume(&ac);
  break;

 case sPermitListen:
 case sPermitOpen:
  if (opcode == sPermitListen) {
   uintptr = &options->num_permitted_listens;
   chararrayptr = &options->permitted_listens;
  } else {
   uintptr = &options->num_permitted_opens;
   chararrayptr = &options->permitted_opens;
  }
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 2201, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  uvalue = *uintptr;
  if (strcmp(arg, "any") == 0 || strcmp(arg, "none") == 0) {
   if (*activep && uvalue == 0) {
    *uintptr = 1;
    *chararrayptr = xcalloc(1,
        sizeof(**chararrayptr));
    (*chararrayptr)[0] = xstrdup(arg);
   }
   break;
  }
  for (; arg != 
               ((void *)0) 
                    && *arg != '\0'; arg = argv_next(&ac, &av)) {
   if (opcode == sPermitListen &&
       strchr(arg, ':') == 
                          ((void *)0)
                              ) {




    xasprintf(&arg2, "*:%s", arg);
   } else {
    arg2 = xstrdup(arg);
    p = hpdelim(&arg);
    if (p == 
            ((void *)0)
                ) {
     sshfatal("servconf.c", __func__, 2225, 0, SYSLOG_LEVEL_FATAL, 
    ((void *)0)
    , "%s line %d: %s missing host", filename, linenum, keyword)
                                    ;
    }
    p = cleanhostname(p);
   }
   if (arg == 
             ((void *)0) 
                  ||
       ((port = permitopen_port(arg)) < 0)) {
    sshfatal("servconf.c", __func__, 2232, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s line %d: %s bad port number", filename, linenum, keyword)
                                   ;
   }
   if (*activep && uvalue == 0) {
    opt_array_append(filename, linenum, keyword,
        chararrayptr, uintptr, arg2);
   }
   free(arg2);
  }
  break;

 case sForceCommand:
  if (str == 
            ((void *)0) 
                 || *str == '\0')
   sshfatal("servconf.c", __func__, 2245, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  len = strspn(str, " \t\r\n");
  if (*activep && options->adm_forced_command == 
                                                ((void *)0)
                                                    )
   options->adm_forced_command = xstrdup(str + len);
  argv_consume(&ac);
  break;

 case sChrootDirectory:
  charptr = &options->chroot_directory;

  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 2258, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  if (*activep && *charptr == 
                             ((void *)0)
                                 )
   *charptr = xstrdup(arg);
  break;

 case sTrustedUserCAKeys:
  charptr = &options->trusted_user_ca_keys;
  goto parse_filename;

 case sRevokedKeys:
  charptr = &options->revoked_keys_file;
  goto parse_filename;

 case sSecurityKeyProvider:
  charptr = &options->sk_provider;
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 2276, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  if (*activep && *charptr == 
                             ((void *)0)
                                 ) {
   *charptr = strcasecmp(arg, "internal") == 0 ?
       xstrdup(arg) : derelativise_path(arg);

   if (intptr != 
                ((void *)0)
                    )
    *intptr = *intptr + 1;
  }
  break;

 case sIPQoS:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 2290, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  if ((value = parse_ipqos(arg)) == -1)
   sshfatal("servconf.c", __func__, 2293, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: Bad %s value: %s", filename, linenum, keyword, arg)
                                       ;
  arg = argv_next(&ac, &av);
  if (arg == 
            ((void *)0)
                )
   value2 = value;
  else if ((value2 = parse_ipqos(arg)) == -1)
   sshfatal("servconf.c", __func__, 2299, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: Bad %s value: %s", filename, linenum, keyword, arg)
                                       ;
  if (*activep) {
   options->ip_qos_interactive = value;
   options->ip_qos_bulk = value2;
  }
  break;

 case sVersionAddendum:
  if (str == 
            ((void *)0) 
                 || *str == '\0')
   sshfatal("servconf.c", __func__, 2309, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  len = strspn(str, " \t\r\n");
  if (strchr(str + len, '\r') != 
                                ((void *)0)
                                    ) {
   sshfatal("servconf.c", __func__, 2313, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%.200s line %d: Invalid %s argument", filename, linenum, keyword)
                                  ;
  }
  if ((arg = strchr(line, '#')) != 
                                  ((void *)0)
                                      ) {
   *arg = '\0';
   rtrim(line);
  }
  if (*activep && options->version_addendum == 
                                              ((void *)0)
                                                  ) {
   if (strcasecmp(str + len, "none") == 0)
    options->version_addendum = xstrdup("");
   else
    options->version_addendum = xstrdup(str + len);
  }
  argv_consume(&ac);
  break;

 case sAuthorizedKeysCommand:
  charptr = &options->authorized_keys_command;
 parse_command:
  len = strspn(str, " \t\r\n");
  if (str[len] != '/' && strcasecmp(str + len, "none") != 0) {
   sshfatal("servconf.c", __func__, 2334, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%.200s line %d: %s must be an absolute path", filename, linenum, keyword)
                                  ;
  }
  if (*activep && options->authorized_keys_command == 
                                                     ((void *)0)
                                                         )
   *charptr = xstrdup(str + len);
  argv_consume(&ac);
  break;

 case sAuthorizedKeysCommandUser:
  charptr = &options->authorized_keys_command_user;
 parse_localuser:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0') {
   sshfatal("servconf.c", __func__, 2347, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: missing %s argument.", filename, linenum, keyword)
                                  ;
  }
  if (*activep && *charptr == 
                             ((void *)0)
                                 )
   *charptr = xstrdup(arg);
  break;

 case sAuthorizedPrincipalsCommand:
  charptr = &options->authorized_principals_command;
  goto parse_command;

 case sAuthorizedPrincipalsCommandUser:
  charptr = &options->authorized_principals_command_user;
  goto parse_localuser;

 case sAuthenticationMethods:
  found = options->num_auth_methods == 0;
  value = 0;
  value2 = 0;
  while ((arg = argv_next(&ac, &av)) != 
                                       ((void *)0)
                                           ) {
   if (strcmp(arg, "any") == 0) {
    if (options->num_auth_methods > 0) {
     sshfatal("servconf.c", __func__, 2369, 0, SYSLOG_LEVEL_FATAL, 
    ((void *)0)
    , "%s line %d: \"any\" must " "appear alone in %s", filename, linenum, keyword)

                                    ;
    }
    value = 1;
   } else if (value) {
    sshfatal("servconf.c", __func__, 2375, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s line %d: \"any\" must appear " "alone in %s", filename, linenum, keyword)
                                                  ;
   } else if (auth2_methods_valid(arg, 0) != 0) {
    sshfatal("servconf.c", __func__, 2378, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s line %d: invalid %s method list.", filename, linenum, keyword)
                                   ;
   }
   value2 = 1;
   if (!found || !*activep)
    continue;
   opt_array_append(filename, linenum, keyword,
       &options->auth_methods,
       &options->num_auth_methods, arg);
  }
  if (value2 == 0) {
   sshfatal("servconf.c", __func__, 2389, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: no %s specified", filename, linenum, keyword)
                                  ;
  }
  break;

 case sStreamLocalBindMask:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 2397, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;

  value = strtol(arg, &p, 8);
  if (arg == p || value < 0 || value > 0777)
   sshfatal("servconf.c", __func__, 2402, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: Invalid %s.", filename, linenum, keyword)
                                  ;
  if (*activep)
   options->fwd_opts.streamlocal_bind_mask = (mode_t)value;
  break;

 case sStreamLocalBindUnlink:
  intptr = &options->fwd_opts.streamlocal_bind_unlink;
  goto parse_flag;

 case sFingerprintHash:
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 2415, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  if ((value = ssh_digest_alg_by_name(arg)) == -1)
   sshfatal("servconf.c", __func__, 2418, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%.200s line %d: Invalid %s algorithm \"%s\".", filename, linenum, keyword, arg)
                                       ;
  if (*activep)
   options->fingerprint_hash = value;
  break;

 case sExposeAuthInfo:
  intptr = &options->expose_userauth_info;
  goto parse_flag;

 case sRDomain:

  sshfatal("servconf.c", __func__, 2430, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s line %d: setting RDomain not supported on this " "platform.", filename, linenum)
                                     ;

  charptr = &options->routing_domain;
  arg = argv_next(&ac, &av);
  if (!arg || *arg == '\0')
   sshfatal("servconf.c", __func__, 2436, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: %s missing argument.", filename, linenum, keyword)
                                  ;
  if (strcasecmp(arg, "none") != 0 && strcmp(arg, "%D") != 0 &&
      !valid_rdomain(arg))
   sshfatal("servconf.c", __func__, 2440, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s line %d: invalid routing domain", filename, linenum)
                         ;
  if (*activep && *charptr == 
                             ((void *)0)
                                 )
   *charptr = xstrdup(arg);
  break;

 case sRequiredRSASize:
  intptr = &options->required_rsa_size;
  goto parse_int;

 case sDeprecated:
 case sIgnore:
 case sUnsupported:
  sshlog("servconf.c", __func__, 2453, 0, opcode == sIgnore ? SYSLOG_LEVEL_DEBUG2 : SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "%s line %d: %s option %s", filename, linenum, opcode == sUnsupported ? "Unsupported" : "Deprecated", keyword)



              ;
  argv_consume(&ac);
  break;

 default:
  sshfatal("servconf.c", __func__, 2462, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s line %d: Missing handler for opcode %s (%d)", filename, linenum, keyword, opcode)
                                         ;
 }

 if (ac > 0) {
  sshlog("servconf.c", __func__, 2467, 0, SYSLOG_LEVEL_ERROR, 
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
process_server_config_line(ServerOptions *options, char *line,
    const char *filename, int linenum, int *activep,
    struct connection_info *connectinfo, struct include_list *includes)
{
 int inc_flags = 0;

 return process_server_config_line_depth(options, line, filename,
     linenum, activep, connectinfo, &inc_flags, 0, includes);
}




void
load_server_config(const char *filename, struct sshbuf *conf)
{
 struct stat st;
 char *line = 
             ((void *)0)
                 , *cp;
 size_t linesize = 0;
 FILE *f;
 int r, lineno = 0;

 sshlog("servconf.c", __func__, 2502, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "filename %s", filename);
 if ((f = fopen(filename, "r")) == 
                                  ((void *)0)
                                      ) {
  perror(filename);
  exit(1);
 }
 sshbuf_reset(conf);

 if (fstat(fileno(f), &st) == 0 && st.st_size > 0 &&
     (r = sshbuf_allocate(conf, st.st_size)) != 0)
  sshfatal("servconf.c", __func__, 2511, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "allocate");
 while (getline(&line, &linesize, f) != -1) {
  lineno++;





  cp = line + strspn(line, " \t\r");
  if ((r = sshbuf_put(conf, cp, strlen(cp))) != 0)
   sshfatal("servconf.c", __func__, 2521, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_put");
 }
 free(line);
 if ((r = sshbuf_put_u8(conf, 0)) != 0)
  sshfatal("servconf.c", __func__, 2525, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_put_u8");
 fclose(f);
 sshlog("servconf.c", __func__, 2527, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "done config len = %zu", sshbuf_len(conf));
}

void
parse_server_match_config(ServerOptions *options,
   struct include_list *includes, struct connection_info *connectinfo)
{
 ServerOptions mo;

 initialize_server_options(&mo);
 parse_server_config(&mo, "reprocess config", cfg, includes,
     connectinfo, 0);
 copy_set_server_options(options, &mo, 0);
}

int parse_server_match_testspec(struct connection_info *ci, char *spec)
{
 char *p;

 while ((p = strsep(&spec, ",")) && *p != '\0') {
  if (strncmp(p, "addr=", 5) == 0) {
   ci->address = xstrdup(p + 5);
  } else if (strncmp(p, "host=", 5) == 0) {
   ci->host = xstrdup(p + 5);
  } else if (strncmp(p, "user=", 5) == 0) {
   ci->user = xstrdup(p + 5);
  } else if (strncmp(p, "laddr=", 6) == 0) {
   ci->laddress = xstrdup(p + 6);
  } else if (strncmp(p, "rdomain=", 8) == 0) {
   ci->rdomain = xstrdup(p + 8);
  } else if (strncmp(p, "lport=", 6) == 0) {
   ci->lport = a2port(p + 6);
   if (ci->lport == -1) {
    fprintf(
           stderr
                 , "Invalid port '%s' in test mode"
        " specification %s\n", p+6, p);
    return -1;
   }
  } else {
   fprintf(
          stderr
                , "Invalid test mode specification %s\n",
       p);
   return -1;
  }
 }
 return 0;
}
void
copy_set_server_options(ServerOptions *dst, ServerOptions *src, int preauth)
{





 do { if (src->password_authentication != -1) dst->password_authentication = src->password_authentication; } while (0);
 do { if (src->gss_authentication != -1) dst->gss_authentication = src->gss_authentication; } while (0);
 do { if (src->pubkey_authentication != -1) dst->pubkey_authentication = src->pubkey_authentication; } while (0);
 do { if (src->pubkey_auth_options != -1) dst->pubkey_auth_options = src->pubkey_auth_options; } while (0);
 do { if (src->kerberos_authentication != -1) dst->kerberos_authentication = src->kerberos_authentication; } while (0);
 do { if (src->hostbased_authentication != -1) dst->hostbased_authentication = src->hostbased_authentication; } while (0);
 do { if (src->hostbased_uses_name_from_packet_only != -1) dst->hostbased_uses_name_from_packet_only = src->hostbased_uses_name_from_packet_only; } while (0);
 do { if (src->kbd_interactive_authentication != -1) dst->kbd_interactive_authentication = src->kbd_interactive_authentication; } while (0);
 do { if (src->permit_root_login != -1) dst->permit_root_login = src->permit_root_login; } while (0);
 do { if (src->permit_empty_passwd != -1) dst->permit_empty_passwd = src->permit_empty_passwd; } while (0);
 do { if (src->ignore_rhosts != -1) dst->ignore_rhosts = src->ignore_rhosts; } while (0);

 do { if (src->allow_tcp_forwarding != -1) dst->allow_tcp_forwarding = src->allow_tcp_forwarding; } while (0);
 do { if (src->allow_streamlocal_forwarding != -1) dst->allow_streamlocal_forwarding = src->allow_streamlocal_forwarding; } while (0);
 do { if (src->allow_agent_forwarding != -1) dst->allow_agent_forwarding = src->allow_agent_forwarding; } while (0);
 do { if (src->disable_forwarding != -1) dst->disable_forwarding = src->disable_forwarding; } while (0);
 do { if (src->expose_userauth_info != -1) dst->expose_userauth_info = src->expose_userauth_info; } while (0);
 do { if (src->permit_tun != -1) dst->permit_tun = src->permit_tun; } while (0);
 do { if (src->fwd_opts.gateway_ports != -1) dst->fwd_opts.gateway_ports = src->fwd_opts.gateway_ports; } while (0);
 do { if (src->fwd_opts.streamlocal_bind_unlink != -1) dst->fwd_opts.streamlocal_bind_unlink = src->fwd_opts.streamlocal_bind_unlink; } while (0);
 do { if (src->x11_display_offset != -1) dst->x11_display_offset = src->x11_display_offset; } while (0);
 do { if (src->x11_forwarding != -1) dst->x11_forwarding = src->x11_forwarding; } while (0);
 do { if (src->x11_use_localhost != -1) dst->x11_use_localhost = src->x11_use_localhost; } while (0);
 do { if (src->permit_tty != -1) dst->permit_tty = src->permit_tty; } while (0);
 do { if (src->permit_user_rc != -1) dst->permit_user_rc = src->permit_user_rc; } while (0);
 do { if (src->max_sessions != -1) dst->max_sessions = src->max_sessions; } while (0);
 do { if (src->max_authtries != -1) dst->max_authtries = src->max_authtries; } while (0);
 do { if (src->client_alive_count_max != -1) dst->client_alive_count_max = src->client_alive_count_max; } while (0);
 do { if (src->client_alive_interval != -1) dst->client_alive_interval = src->client_alive_interval; } while (0);
 do { if (src->ip_qos_interactive != -1) dst->ip_qos_interactive = src->ip_qos_interactive; } while (0);
 do { if (src->ip_qos_bulk != -1) dst->ip_qos_bulk = src->ip_qos_bulk; } while (0);
 do { if (src->rekey_limit != -1) dst->rekey_limit = src->rekey_limit; } while (0);
 do { if (src->rekey_interval != -1) dst->rekey_interval = src->rekey_interval; } while (0);
 do { if (src->log_level != -1) dst->log_level = src->log_level; } while (0);
 do { if (src->required_rsa_size != -1) dst->required_rsa_size = src->required_rsa_size; } while (0);






 if (src->fwd_opts.streamlocal_bind_mask != (mode_t)-1) {
  dst->fwd_opts.streamlocal_bind_mask =
      src->fwd_opts.streamlocal_bind_mask;
 }
 do { do { if (src->banner != 
((void *)0) 
&& dst->banner != src->banner) { free(dst->banner); dst->banner = src->banner; } } while(0); do { if (src->trusted_user_ca_keys != 
((void *)0) 
&& dst->trusted_user_ca_keys != src->trusted_user_ca_keys) { free(dst->trusted_user_ca_keys); dst->trusted_user_ca_keys = src->trusted_user_ca_keys; } } while(0); do { if (src->revoked_keys_file != 
((void *)0) 
&& dst->revoked_keys_file != src->revoked_keys_file) { free(dst->revoked_keys_file); dst->revoked_keys_file = src->revoked_keys_file; } } while(0); do { if (src->authorized_keys_command != 
((void *)0) 
&& dst->authorized_keys_command != src->authorized_keys_command) { free(dst->authorized_keys_command); dst->authorized_keys_command = src->authorized_keys_command; } } while(0); do { if (src->authorized_keys_command_user != 
((void *)0) 
&& dst->authorized_keys_command_user != src->authorized_keys_command_user) { free(dst->authorized_keys_command_user); dst->authorized_keys_command_user = src->authorized_keys_command_user; } } while(0); do { if (src->authorized_principals_file != 
((void *)0) 
&& dst->authorized_principals_file != src->authorized_principals_file) { free(dst->authorized_principals_file); dst->authorized_principals_file = src->authorized_principals_file; } } while(0); do { if (src->authorized_principals_command != 
((void *)0) 
&& dst->authorized_principals_command != src->authorized_principals_command) { free(dst->authorized_principals_command); dst->authorized_principals_command = src->authorized_principals_command; } } while(0); do { if (src->authorized_principals_command_user != 
((void *)0) 
&& dst->authorized_principals_command_user != src->authorized_principals_command_user) { free(dst->authorized_principals_command_user); dst->authorized_principals_command_user = src->authorized_principals_command_user; } } while(0); do { if (src->hostbased_accepted_algos != 
((void *)0) 
&& dst->hostbased_accepted_algos != src->hostbased_accepted_algos) { free(dst->hostbased_accepted_algos); dst->hostbased_accepted_algos = src->hostbased_accepted_algos; } } while(0); do { if (src->pubkey_accepted_algos != 
((void *)0) 
&& dst->pubkey_accepted_algos != src->pubkey_accepted_algos) { free(dst->pubkey_accepted_algos); dst->pubkey_accepted_algos = src->pubkey_accepted_algos; } } while(0); do { if (src->ca_sign_algorithms != 
((void *)0) 
&& dst->ca_sign_algorithms != src->ca_sign_algorithms) { free(dst->ca_sign_algorithms); dst->ca_sign_algorithms = src->ca_sign_algorithms; } } while(0); do { if (src->routing_domain != 
((void *)0) 
&& dst->routing_domain != src->routing_domain) { free(dst->routing_domain); dst->routing_domain = src->routing_domain; } } while(0); do { if (src->permit_user_env_allowlist != 
((void *)0) 
&& dst->permit_user_env_allowlist != src->permit_user_env_allowlist) { free(dst->permit_user_env_allowlist); dst->permit_user_env_allowlist = src->permit_user_env_allowlist; } } while(0); do { u_int i; if (src->num_authkeys_files != 0) { for (i = 0; i < dst->num_authkeys_files; i++) free(dst->authorized_keys_files[i]); free(dst->authorized_keys_files); dst->authorized_keys_files = xcalloc(src->num_authkeys_files, sizeof(*dst->authorized_keys_files)); for (i = 0; i < src->num_authkeys_files; i++) dst->authorized_keys_files[i] = xstrdup(src->authorized_keys_files[i]); dst->num_authkeys_files = src->num_authkeys_files; } } while(0); do { u_int i; if (src->num_allow_users != 0) { for (i = 0; i < dst->num_allow_users; i++) free(dst->allow_users[i]); free(dst->allow_users); dst->allow_users = xcalloc(src->num_allow_users, sizeof(*dst->allow_users)); for (i = 0; i < src->num_allow_users; i++) dst->allow_users[i] = xstrdup(src->allow_users[i]); dst->num_allow_users = src->num_allow_users; } } while(0); do { u_int i; if (src->num_deny_users != 0) { for (i = 0; i < dst->num_deny_users; i++) free(dst->deny_users[i]); free(dst->deny_users); dst->deny_users = xcalloc(src->num_deny_users, sizeof(*dst->deny_users)); for (i = 0; i < src->num_deny_users; i++) dst->deny_users[i] = xstrdup(src->deny_users[i]); dst->num_deny_users = src->num_deny_users; } } while(0); do { u_int i; if (src->num_allow_groups != 0) { for (i = 0; i < dst->num_allow_groups; i++) free(dst->allow_groups[i]); free(dst->allow_groups); dst->allow_groups = xcalloc(src->num_allow_groups, sizeof(*dst->allow_groups)); for (i = 0; i < src->num_allow_groups; i++) dst->allow_groups[i] = xstrdup(src->allow_groups[i]); dst->num_allow_groups = src->num_allow_groups; } } while(0); do { u_int i; if (src->num_deny_groups != 0) { for (i = 0; i < dst->num_deny_groups; i++) free(dst->deny_groups[i]); free(dst->deny_groups); dst->deny_groups = xcalloc(src->num_deny_groups, sizeof(*dst->deny_groups)); for (i = 0; i < src->num_deny_groups; i++) dst->deny_groups[i] = xstrdup(src->deny_groups[i]); dst->num_deny_groups = src->num_deny_groups; } } while(0); do { u_int i; if (src->num_accept_env != 0) { for (i = 0; i < dst->num_accept_env; i++) free(dst->accept_env[i]); free(dst->accept_env); dst->accept_env = xcalloc(src->num_accept_env, sizeof(*dst->accept_env)); for (i = 0; i < src->num_accept_env; i++) dst->accept_env[i] = xstrdup(src->accept_env[i]); dst->num_accept_env = src->num_accept_env; } } while(0); do { u_int i; if (src->num_setenv != 0) { for (i = 0; i < dst->num_setenv; i++) free(dst->setenv[i]); free(dst->setenv); dst->setenv = xcalloc(src->num_setenv, sizeof(*dst->setenv)); for (i = 0; i < src->num_setenv; i++) dst->setenv[i] = xstrdup(src->setenv[i]); dst->num_setenv = src->num_setenv; } } while(0); do { u_int i; if (src->num_auth_methods != 0) { for (i = 0; i < dst->num_auth_methods; i++) free(dst->auth_methods[i]); free(dst->auth_methods); dst->auth_methods = xcalloc(src->num_auth_methods, sizeof(*dst->auth_methods)); for (i = 0; i < src->num_auth_methods; i++) dst->auth_methods[i] = xstrdup(src->auth_methods[i]); dst->num_auth_methods = src->num_auth_methods; } } while(0); do { u_int i; if (src->num_permitted_opens != 0) { for (i = 0; i < dst->num_permitted_opens; i++) free(dst->permitted_opens[i]); free(dst->permitted_opens); dst->permitted_opens = xcalloc(src->num_permitted_opens, sizeof(*dst->permitted_opens)); for (i = 0; i < src->num_permitted_opens; i++) dst->permitted_opens[i] = xstrdup(src->permitted_opens[i]); dst->num_permitted_opens = src->num_permitted_opens; } } while(0); do { u_int i; if (src->num_permitted_listens != 0) { for (i = 0; i < dst->num_permitted_listens; i++) free(dst->permitted_listens[i]); free(dst->permitted_listens); dst->permitted_listens = xcalloc(src->num_permitted_listens, sizeof(*dst->permitted_listens)); for (i = 0; i < src->num_permitted_listens; i++) dst->permitted_listens[i] = xstrdup(src->permitted_listens[i]); dst->num_permitted_listens = src->num_permitted_listens; } } while(0); do { u_int i; if (src->num_log_verbose != 0) { for (i = 0; i < dst->num_log_verbose; i++) free(dst->log_verbose[i]); free(dst->log_verbose); dst->log_verbose = xcalloc(src->num_log_verbose, sizeof(*dst->log_verbose)); for (i = 0; i < src->num_log_verbose; i++) dst->log_verbose[i] = xstrdup(src->log_verbose[i]); dst->num_log_verbose = src->num_log_verbose; } } while(0); } while (0);


 assemble_algorithms(dst);





 if (preauth)
  return;


 do { if (src->adm_forced_command != 
((void *)0) 
&& dst->adm_forced_command != src->adm_forced_command) { free(dst->adm_forced_command); dst->adm_forced_command = src->adm_forced_command; } } while(0);
 if (option_clear_or_none(dst->adm_forced_command)) {
  free(dst->adm_forced_command);
  dst->adm_forced_command = 
                           ((void *)0)
                               ;
 }
 do { if (src->chroot_directory != 
((void *)0) 
&& dst->chroot_directory != src->chroot_directory) { free(dst->chroot_directory); dst->chroot_directory = src->chroot_directory; } } while(0);
 if (option_clear_or_none(dst->chroot_directory)) {
  free(dst->chroot_directory);
  dst->chroot_directory = 
                         ((void *)0)
                             ;
 }
}






static void
parse_server_config_depth(ServerOptions *options, const char *filename,
    struct sshbuf *conf, struct include_list *includes,
    struct connection_info *connectinfo, int flags, int *activep, int depth)
{
 int linenum, bad_options = 0;
 char *cp, *obuf, *cbuf;

 if (depth < 0 || depth > 16)
  sshfatal("servconf.c", __func__, 2694, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Too many recursive configuration includes");

 sshlog("servconf.c", __func__, 2696, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "config %s len %zu%s", filename, sshbuf_len(conf), (flags & 0x04 ? " [checking syntax only]" : ""))
                                                                  ;

 if ((obuf = cbuf = sshbuf_dup_string(conf)) == 
                                               ((void *)0)
                                                   )
  sshfatal("servconf.c", __func__, 2700, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_dup_string failed");
 linenum = 1;
 while ((cp = strsep(&cbuf, "\n")) != 
                                     ((void *)0)
                                         ) {
  if (process_server_config_line_depth(options, cp,
      filename, linenum++, activep, connectinfo, &flags,
      depth, includes) != 0)
   bad_options++;
 }
 free(obuf);
 if (bad_options > 0)
  sshfatal("servconf.c", __func__, 2710, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: terminating, %d bad configuration options", filename, bad_options)
                            ;
}

void
parse_server_config(ServerOptions *options, const char *filename,
    struct sshbuf *conf, struct include_list *includes,
    struct connection_info *connectinfo, int reexec)
{
 int active = connectinfo ? 0 : 1;
 parse_server_config_depth(options, filename, conf, includes,
     connectinfo, (connectinfo ? 0x08 : 0), &active, 0);
 if (!reexec)
  process_queued_listen_addrs(options);
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
fmt_intarg(ServerOpCodes code, int val)
{
 if (val == -1)
  return "unset";
 switch (code) {
 case sAddressFamily:
  return fmt_multistate_int(val, multistate_addressfamily);
 case sPermitRootLogin:
  return fmt_multistate_int(val, multistate_permitrootlogin);
 case sGatewayPorts:
  return fmt_multistate_int(val, multistate_gatewayports);
 case sCompression:
  return fmt_multistate_int(val, multistate_compression);
 case sAllowTcpForwarding:
  return fmt_multistate_int(val, multistate_tcpfwd);
 case sAllowStreamLocalForwarding:
  return fmt_multistate_int(val, multistate_tcpfwd);
 case sIgnoreRhosts:
  return fmt_multistate_int(val, multistate_ignore_rhosts);
 case sFingerprintHash:
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

static void
dump_cfg_int(ServerOpCodes code, int val)
{
 printf("%s %d\n", lookup_opcode_name(code), val);
}

static void
dump_cfg_oct(ServerOpCodes code, int val)
{
 printf("%s 0%o\n", lookup_opcode_name(code), val);
}

static void
dump_cfg_fmtint(ServerOpCodes code, int val)
{
 printf("%s %s\n", lookup_opcode_name(code), fmt_intarg(code, val));
}

static void
dump_cfg_string(ServerOpCodes code, const char *val)
{
 printf("%s %s\n", lookup_opcode_name(code),
     val == 
           ((void *)0) 
                ? "none" : val);
}

static void
dump_cfg_strarray(ServerOpCodes code, u_int count, char **vals)
{
 u_int i;

 for (i = 0; i < count; i++)
  printf("%s %s\n", lookup_opcode_name(code), vals[i]);
}

static void
dump_cfg_strarray_oneline(ServerOpCodes code, u_int count, char **vals)
{
 u_int i;

 if (count <= 0 && code != sAuthenticationMethods)
  return;
 printf("%s", lookup_opcode_name(code));
 for (i = 0; i < count; i++)
  printf(" %s", vals[i]);
 if (code == sAuthenticationMethods && count == 0)
  printf(" any");
 printf("\n");
}

static char *
format_listen_addrs(struct listenaddr *la)
{
 int r;
 struct addrinfo *ai;
 char addr[
          1025
                    ], port[
                            32
                                      ];
 char *laddr1 = xstrdup(""), *laddr2 = 
                                      ((void *)0)
                                          ;






 for (ai = la->addrs; ai; ai = ai->ai_next) {
  if ((r = getnameinfo(ai->ai_addr, ai->ai_addrlen, addr,
      sizeof(addr), port, sizeof(port),
      
     1
                   |
                    2
                                  )) != 0) {
   sshlog("servconf.c", __func__, 2838, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "getnameinfo: %.100s", ssh_gai_strerror(r));
   continue;
  }
  laddr2 = laddr1;
  if (ai->ai_family == 
                      10
                              ) {
   xasprintf(&laddr1, "listenaddress [%s]:%s%s%s\n%s",
       addr, port,
       la->rdomain == 
                     ((void *)0) 
                          ? "" : " rdomain ",
       la->rdomain == 
                     ((void *)0) 
                          ? "" : la->rdomain,
       laddr2);
  } else {
   xasprintf(&laddr1, "listenaddress %s:%s%s%s\n%s",
       addr, port,
       la->rdomain == 
                     ((void *)0) 
                          ? "" : " rdomain ",
       la->rdomain == 
                     ((void *)0) 
                          ? "" : la->rdomain,
       laddr2);
  }
  free(laddr2);
 }
 return laddr1;
}

void
dump_config(ServerOptions *o)
{
 char *s;
 u_int i;


 for (i = 0; i < o->num_ports; i++)
  printf("port %d\n", o->ports[i]);
 dump_cfg_fmtint(sAddressFamily, o->address_family);

 for (i = 0; i < o->num_listen_addrs; i++) {
  s = format_listen_addrs(&o->listen_addrs[i]);
  printf("%s", s);
  free(s);
 }





 dump_cfg_int(sLoginGraceTime, o->login_grace_time);
 dump_cfg_int(sX11DisplayOffset, o->x11_display_offset);
 dump_cfg_int(sMaxAuthTries, o->max_authtries);
 dump_cfg_int(sMaxSessions, o->max_sessions);
 dump_cfg_int(sClientAliveInterval, o->client_alive_interval);
 dump_cfg_int(sClientAliveCountMax, o->client_alive_count_max);
 dump_cfg_int(sRequiredRSASize, o->required_rsa_size);
 dump_cfg_oct(sStreamLocalBindMask, o->fwd_opts.streamlocal_bind_mask);


 dump_cfg_fmtint(sPermitRootLogin, o->permit_root_login);
 dump_cfg_fmtint(sIgnoreRhosts, o->ignore_rhosts);
 dump_cfg_fmtint(sIgnoreUserKnownHosts, o->ignore_user_known_hosts);
 dump_cfg_fmtint(sHostbasedAuthentication, o->hostbased_authentication);
 dump_cfg_fmtint(sHostbasedUsesNameFromPacketOnly,
     o->hostbased_uses_name_from_packet_only);
 dump_cfg_fmtint(sPubkeyAuthentication, o->pubkey_authentication);
 dump_cfg_fmtint(sPasswordAuthentication, o->password_authentication);
 dump_cfg_fmtint(sKbdInteractiveAuthentication,
     o->kbd_interactive_authentication);
 dump_cfg_fmtint(sPrintMotd, o->print_motd);

 dump_cfg_fmtint(sPrintLastLog, o->print_lastlog);

 dump_cfg_fmtint(sX11Forwarding, o->x11_forwarding);
 dump_cfg_fmtint(sX11UseLocalhost, o->x11_use_localhost);
 dump_cfg_fmtint(sPermitTTY, o->permit_tty);
 dump_cfg_fmtint(sPermitUserRC, o->permit_user_rc);
 dump_cfg_fmtint(sStrictModes, o->strict_modes);
 dump_cfg_fmtint(sTCPKeepAlive, o->tcp_keep_alive);
 dump_cfg_fmtint(sEmptyPasswd, o->permit_empty_passwd);
 dump_cfg_fmtint(sCompression, o->compression);
 dump_cfg_fmtint(sGatewayPorts, o->fwd_opts.gateway_ports);
 dump_cfg_fmtint(sUseDNS, o->use_dns);
 dump_cfg_fmtint(sAllowTcpForwarding, o->allow_tcp_forwarding);
 dump_cfg_fmtint(sAllowAgentForwarding, o->allow_agent_forwarding);
 dump_cfg_fmtint(sDisableForwarding, o->disable_forwarding);
 dump_cfg_fmtint(sAllowStreamLocalForwarding, o->allow_streamlocal_forwarding);
 dump_cfg_fmtint(sStreamLocalBindUnlink, o->fwd_opts.streamlocal_bind_unlink);
 dump_cfg_fmtint(sFingerprintHash, o->fingerprint_hash);
 dump_cfg_fmtint(sExposeAuthInfo, o->expose_userauth_info);


 dump_cfg_string(sPidFile, o->pid_file);
 dump_cfg_string(sModuliFile, o->moduli_file);
 dump_cfg_string(sXAuthLocation, o->xauth_location);
 dump_cfg_string(sCiphers, o->ciphers);
 dump_cfg_string(sMacs, o->macs);
 dump_cfg_string(sBanner, o->banner);
 dump_cfg_string(sForceCommand, o->adm_forced_command);
 dump_cfg_string(sChrootDirectory, o->chroot_directory);
 dump_cfg_string(sTrustedUserCAKeys, o->trusted_user_ca_keys);
 dump_cfg_string(sRevokedKeys, o->revoked_keys_file);
 dump_cfg_string(sSecurityKeyProvider, o->sk_provider);
 dump_cfg_string(sAuthorizedPrincipalsFile,
     o->authorized_principals_file);
 dump_cfg_string(sVersionAddendum, *o->version_addendum == '\0'
     ? "none" : o->version_addendum);
 dump_cfg_string(sAuthorizedKeysCommand, o->authorized_keys_command);
 dump_cfg_string(sAuthorizedKeysCommandUser, o->authorized_keys_command_user);
 dump_cfg_string(sAuthorizedPrincipalsCommand, o->authorized_principals_command);
 dump_cfg_string(sAuthorizedPrincipalsCommandUser, o->authorized_principals_command_user);
 dump_cfg_string(sHostKeyAgent, o->host_key_agent);
 dump_cfg_string(sKexAlgorithms, o->kex_algorithms);
 dump_cfg_string(sCASignatureAlgorithms, o->ca_sign_algorithms);
 dump_cfg_string(sHostbasedAcceptedAlgorithms, o->hostbased_accepted_algos);
 dump_cfg_string(sHostKeyAlgorithms, o->hostkeyalgorithms);
 dump_cfg_string(sPubkeyAcceptedAlgorithms, o->pubkey_accepted_algos);





 dump_cfg_string(sLogLevel, log_level_name(o->log_level));
 dump_cfg_string(sLogFacility, log_facility_name(o->log_facility));


 dump_cfg_strarray_oneline(sAuthorizedKeysFile, o->num_authkeys_files,
     o->authorized_keys_files);
 dump_cfg_strarray(sHostKeyFile, o->num_host_key_files,
     o->host_key_files);
 dump_cfg_strarray(sHostCertificate, o->num_host_cert_files,
     o->host_cert_files);
 dump_cfg_strarray(sAllowUsers, o->num_allow_users, o->allow_users);
 dump_cfg_strarray(sDenyUsers, o->num_deny_users, o->deny_users);
 dump_cfg_strarray(sAllowGroups, o->num_allow_groups, o->allow_groups);
 dump_cfg_strarray(sDenyGroups, o->num_deny_groups, o->deny_groups);
 dump_cfg_strarray(sAcceptEnv, o->num_accept_env, o->accept_env);
 dump_cfg_strarray(sSetEnv, o->num_setenv, o->setenv);
 dump_cfg_strarray_oneline(sAuthenticationMethods,
     o->num_auth_methods, o->auth_methods);
 dump_cfg_strarray_oneline(sLogVerbose,
     o->num_log_verbose, o->log_verbose);


 for (i = 0; i < o->num_subsystems; i++)
  printf("subsystem %s %s\n", o->subsystem_name[i],
      o->subsystem_args[i]);

 printf("maxstartups %d:%d:%d\n", o->max_startups_begin,
     o->max_startups_rate, o->max_startups);
 printf("persourcemaxstartups ");
 if (o->per_source_max_startups == 0x7fffffff)
  printf("none\n");
 else
  printf("%d\n", o->per_source_max_startups);
 printf("persourcenetblocksize %d:%d\n", o->per_source_masklen_ipv4,
     o->per_source_masklen_ipv6);

 s = 
    ((void *)0)
        ;
 for (i = 0; tunmode_desc[i].val != -1; i++) {
  if (tunmode_desc[i].val == o->permit_tun) {
   s = tunmode_desc[i].text;
   break;
  }
 }
 dump_cfg_string(sPermitTunnel, s);

 printf("ipqos %s ", iptos2str(o->ip_qos_interactive));
 printf("%s\n", iptos2str(o->ip_qos_bulk));

 printf("rekeylimit %llu %d\n", (unsigned long long)o->rekey_limit,
     o->rekey_interval);

 printf("permitopen");
 if (o->num_permitted_opens == 0)
  printf(" any");
 else {
  for (i = 0; i < o->num_permitted_opens; i++)
   printf(" %s", o->permitted_opens[i]);
 }
 printf("\n");
 printf("permitlisten");
 if (o->num_permitted_listens == 0)
  printf(" any");
 else {
  for (i = 0; i < o->num_permitted_listens; i++)
   printf(" %s", o->permitted_listens[i]);
 }
 printf("\n");

 if (o->permit_user_env_allowlist == 
                                    ((void *)0)
                                        ) {
  dump_cfg_fmtint(sPermitUserEnvironment, o->permit_user_env);
 } else {
  printf("permituserenvironment %s\n",
      o->permit_user_env_allowlist);
 }

 printf("pubkeyauthoptions");
 if (o->pubkey_auth_options == 0)
  printf(" none");
 if (o->pubkey_auth_options & (1))
  printf(" touch-required");
 if (o->pubkey_auth_options & (1<<1))
  printf(" verify-required");
 printf("\n");
}
