











































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
struct sshbuf;
int ssh_msg_send(int, u_char, struct sshbuf *);
int ssh_msg_recv(int, struct sshbuf *);
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
int mm_send_fd(int, int);
int mm_receive_fd(int);
struct termios *get_saved_tio(void);
void leave_raw_mode(int);
void enter_raw_mode(int);

int pty_allocate(int *, int *, char *, size_t);
void pty_release(const char *);
void pty_make_controlling_tty(int *, const char *);
void pty_change_window_size(int, u_int, u_int, u_int, u_int);
void pty_setowner(struct passwd *, const char *);
void disconnect_controlling_tty(void);



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
struct ssh;


int client_loop(struct ssh *, int, int, int);
int client_x11_get_proto(struct ssh *, const char *, const char *,
     u_int, u_int, char **, char **);
void client_global_request_reply_fwd(int, u_int32_t, void *);
void client_session2_setup(struct ssh *, int, int, int,
     const char *, struct termios *, int, struct sshbuf *, char **);
char *client_request_tun_fwd(struct ssh *, int, int, int,
    channel_open_fn *, void *);
void client_stop_mux(void);


void *client_new_escape_filter_ctx(int);
void client_filter_cleanup(struct ssh *, int, void *);
int client_simple_escape_filter(struct ssh *, Channel *, char *, int);


typedef void global_confirm_cb(struct ssh *, int, u_int32_t, void *);
void client_register_global_confirm(global_confirm_cb *, void *);


enum confirm_action { CONFIRM_WARN = 0, CONFIRM_CLOSE, CONFIRM_TTY };
void client_expect_confirm(struct ssh *, int, const char *,
    enum confirm_action);
void muxserver_listen(struct ssh *);
int muxclient(const char *);
void mux_exit_message(struct ssh *, Channel *, int);
void mux_tty_alloc_failed(struct ssh *ssh, Channel *);



extern int tty_flag;
extern Options options;
extern char *host;
extern struct sshbuf *command;
extern volatile sig_atomic_t quit_pending;


struct mux_session_confirm_ctx {
 u_int want_tty;
 u_int want_subsys;
 u_int want_x_fwd;
 u_int want_agent_fwd;
 struct sshbuf *cmd;
 char *term;
 struct termios tio;
 char **env;
 u_int rid;
};


struct mux_stdio_confirm_ctx {
 u_int rid;
};


struct mux_channel_confirm_ctx {
 u_int cid;
 u_int rid;
 int fid;
};


int muxserver_sock = -1;


u_int muxclient_request_id = 0;


u_int muxclient_command = 0;


static volatile sig_atomic_t muxclient_terminate = 0;


static u_int muxserver_pid = 0;

static Channel *mux_listener_channel = 
                                      ((void *)0)
                                          ;

struct mux_master_state {
 int hello_rcvd;
};
static void mux_session_confirm(struct ssh *, int, int, void *);
static void mux_stdio_confirm(struct ssh *, int, int, void *);

static int mux_master_process_hello(struct ssh *, u_int,
     Channel *, struct sshbuf *, struct sshbuf *);
static int mux_master_process_new_session(struct ssh *, u_int,
     Channel *, struct sshbuf *, struct sshbuf *);
static int mux_master_process_alive_check(struct ssh *, u_int,
     Channel *, struct sshbuf *, struct sshbuf *);
static int mux_master_process_terminate(struct ssh *, u_int,
     Channel *, struct sshbuf *, struct sshbuf *);
static int mux_master_process_open_fwd(struct ssh *, u_int,
     Channel *, struct sshbuf *, struct sshbuf *);
static int mux_master_process_close_fwd(struct ssh *, u_int,
     Channel *, struct sshbuf *, struct sshbuf *);
static int mux_master_process_stdio_fwd(struct ssh *, u_int,
     Channel *, struct sshbuf *, struct sshbuf *);
static int mux_master_process_stop_listening(struct ssh *, u_int,
     Channel *, struct sshbuf *, struct sshbuf *);
static int mux_master_process_proxy(struct ssh *, u_int,
     Channel *, struct sshbuf *, struct sshbuf *);

static const struct {
 u_int type;
 int (*handler)(struct ssh *, u_int, Channel *,
     struct sshbuf *, struct sshbuf *);
} mux_master_handlers[] = {
 { 0x00000001, mux_master_process_hello },
 { 0x10000002, mux_master_process_new_session },
 { 0x10000004, mux_master_process_alive_check },
 { 0x10000005, mux_master_process_terminate },
 { 0x10000006, mux_master_process_open_fwd },
 { 0x10000007, mux_master_process_close_fwd },
 { 0x10000008, mux_master_process_stdio_fwd },
 { 0x10000009, mux_master_process_stop_listening },
 { 0x1000000f, mux_master_process_proxy },
 { 0, 
     ((void *)0) 
          }
};



static void
mux_master_session_cleanup_cb(struct ssh *ssh, int cid, void *unused)
{
 Channel *cc, *c = channel_by_id(ssh, cid);

 sshlog("mux.c", __func__, 195, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "entering for channel %d", cid);
 if (c == 
         ((void *)0)
             )
  sshfatal("mux.c", __func__, 197, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel_by_id(%i) == NULL", cid);
 if (c->ctl_chan != -1) {
  if ((cc = channel_by_id(ssh, c->ctl_chan)) == 
                                               ((void *)0)
                                                   )
   sshfatal("mux.c", __func__, 200, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "channel %d missing control channel %d", c->self, c->ctl_chan)
                            ;
  c->ctl_chan = -1;
  cc->remote_id = 0;
  cc->have_remote_id = 0;
  chan_rcvd_oclose(ssh, cc);
 }
 channel_cancel_cleanup(ssh, c->self);
}



static void
mux_master_control_cleanup_cb(struct ssh *ssh, int cid, void *unused)
{
 Channel *sc, *c = channel_by_id(ssh, cid);

 sshlog("mux.c", __func__, 217, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "entering for channel %d", cid);
 if (c == 
         ((void *)0)
             )
  sshfatal("mux.c", __func__, 219, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel_by_id(%i) == NULL", cid);
 if (c->have_remote_id) {
  if ((sc = channel_by_id(ssh, c->remote_id)) == 
                                                ((void *)0)
                                                    )
   sshfatal("mux.c", __func__, 222, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "channel %d missing session channel %u", c->self, c->remote_id)
                             ;
  c->remote_id = 0;
  c->have_remote_id = 0;
  sc->ctl_chan = -1;
  if (sc->type != 4 &&
      sc->type != 3) {
   sshlog("mux.c", __func__, 229, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "channel %d: not open", sc->self);
   chan_mark_dead(ssh, sc);
  } else {
   if (sc->istate == 0)
    chan_read_failed(ssh, sc);
   if (sc->ostate == 0)
    chan_write_failed(ssh, sc);
  }
 }
 channel_cancel_cleanup(ssh, c->self);
}


static int
env_permitted(const char *env)
{
 u_int i;
 int ret;
 char name[1024], *cp;

 if ((cp = strchr(env, '=')) == 
                               ((void *)0) 
                                    || cp == env)
  return 0;
 ret = snprintf(name, sizeof(name), "%.*s", (int)(cp - env), env);
 if (ret <= 0 || (size_t)ret >= sizeof(name)) {
  sshlog("mux.c", __func__, 253, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "name '%.100s...' too long", env);
  return 0;
 }

 for (i = 0; i < options.num_send_env; i++)
  if (match_pattern(name, options.send_env[i]))
   return 1;

 return 0;
}



static int
mux_master_process_hello(struct ssh *ssh, u_int rid,
    Channel *c, struct sshbuf *m, struct sshbuf *reply)
{
 u_int ver;
 struct mux_master_state *state = (struct mux_master_state *)c->mux_ctx;
 int r;

 if (state == 
             ((void *)0)
                 )
  sshfatal("mux.c", __func__, 275, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel %d: c->mux_ctx == NULL", c->self);
 if (state->hello_rcvd) {
  sshlog("mux.c", __func__, 277, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "HELLO received twice");
  return -1;
 }
 if ((r = sshbuf_get_u32(m, &ver)) != 0) {
  sshlog("mux.c", __func__, 281, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse");
  return -1;
 }
 if (ver != 4) {
  sshlog("mux.c", __func__, 285, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unsupported multiplexing protocol version %u " "(expected %u)", ver, 4)
                                       ;
  return -1;
 }
 sshlog("mux.c", __func__, 289, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d client version %u", c->self, ver);


 while (sshbuf_len(m) > 0) {
  char *name = 
              ((void *)0)
                  ;
  size_t value_len = 0;

  if ((r = sshbuf_get_cstring(m, &name, 
                                       ((void *)0)
                                           )) != 0 ||
      (r = sshbuf_get_string_direct(m, 
                                      ((void *)0)
                                          , &value_len)) != 0) {
   sshlog("mux.c", __func__, 298, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse extension");
   return -1;
  }
  sshlog("mux.c", __func__, 301, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "Unrecognised extension \"%s\" length %zu", name, value_len)
                      ;
  free(name);
 }
 state->hello_rcvd = 1;
 return 0;
}


static void
reply_ok(struct sshbuf *reply, u_int rid)
{
 int r;

 if ((r = sshbuf_put_u32(reply, 0x80000001)) != 0 ||
     (r = sshbuf_put_u32(reply, rid)) != 0)
  sshfatal("mux.c", __func__, 317, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reply");
}


static void
reply_error(struct sshbuf *reply, u_int type, u_int rid, const char *msg)
{
 int r;

 if ((r = sshbuf_put_u32(reply, type)) != 0 ||
     (r = sshbuf_put_u32(reply, rid)) != 0 ||
     (r = sshbuf_put_cstring(reply, msg)) != 0)
  sshfatal("mux.c", __func__, 329, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reply");
}

static int
mux_master_process_new_session(struct ssh *ssh, u_int rid,
    Channel *c, struct sshbuf *m, struct sshbuf *reply)
{
 Channel *nc;
 struct mux_session_confirm_ctx *cctx;
 char *cmd, *cp;
 u_int i, j, env_len, escape_char, window, packetmax;
 int r, new_fd[3];


 cctx = xcalloc(1, sizeof(*cctx));
 cctx->term = 
             ((void *)0)
                 ;
 cctx->rid = rid;
 cmd = 
      ((void *)0)
          ;
 cctx->env = 
            ((void *)0)
                ;
 env_len = 0;
 if ((r = sshbuf_get_string_direct(m, 
         ((void *)0)
         , 
         ((void *)0)
         )) != 0 ||
     (r = sshbuf_get_u32(m, &cctx->want_tty)) != 0 ||
     (r = sshbuf_get_u32(m, &cctx->want_x_fwd)) != 0 ||
     (r = sshbuf_get_u32(m, &cctx->want_agent_fwd)) != 0 ||
     (r = sshbuf_get_u32(m, &cctx->want_subsys)) != 0 ||
     (r = sshbuf_get_u32(m, &escape_char)) != 0 ||
     (r = sshbuf_get_cstring(m, &cctx->term, 
                                            ((void *)0)
                                                )) != 0 ||
     (r = sshbuf_get_cstring(m, &cmd, 
                                     ((void *)0)
                                         )) != 0) {
 malf:
  free(cmd);
  for (j = 0; j < env_len; j++)
   free(cctx->env[j]);
  free(cctx->env);
  free(cctx->term);
  free(cctx);
  sshlog("mux.c", __func__, 364, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "malformed message");
  return -1;
 }


 while (sshbuf_len(m) > 0) {
  if ((r = sshbuf_get_cstring(m, &cp, 
                                     ((void *)0)
                                         )) != 0)
   goto malf;
  if (!env_permitted(cp)) {
   free(cp);
   continue;
  }
  cctx->env = xreallocarray(cctx->env, env_len + 2,
      sizeof(*cctx->env));
  cctx->env[env_len++] = cp;
  cctx->env[env_len] = 
                      ((void *)0)
                          ;
  if (env_len > 4096) {
   sshlog("mux.c", __func__, 381, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , ">%d environment variables received, " "ignoring additional", 4096)
                                               ;
   break;
  }
 }

 sshlog("mux.c", __func__, 387, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: request tty %d, X %d, agent %d, subsys %d, " "term \"%s\", cmd \"%s\", env %u", c->self, cctx->want_tty, cctx->want_x_fwd, cctx->want_agent_fwd, cctx->want_subsys, cctx->term, cmd, env_len)


                                                 ;

 if ((cctx->cmd = sshbuf_new()) == 
                                  ((void *)0)
                                      )
  sshfatal("mux.c", __func__, 393, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 if ((r = sshbuf_put(cctx->cmd, cmd, strlen(cmd))) != 0)
  sshfatal("mux.c", __func__, 395, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_put");
 free(cmd);
 cmd = 
      ((void *)0)
          ;


 for(i = 0; i < 3; i++) {
  if ((new_fd[i] = mm_receive_fd(c->sock)) == -1) {
   sshlog("mux.c", __func__, 402, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "failed to receive fd %d from client", i);
   for (j = 0; j < i; j++)
    close(new_fd[j]);
   for (j = 0; j < env_len; j++)
    free(cctx->env[j]);
   free(cctx->env);
   free(cctx->term);
   sshbuf_free(cctx->cmd);
   free(cctx);
   reply_error(reply, 0x80000003, rid,
       "did not receive file descriptors");
   return -1;
  }
 }

 sshlog("mux.c", __func__, 417, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "got fds stdin %d, stdout %d, stderr %d", new_fd[0], new_fd[1], new_fd[2])
                                     ;


 if (c->have_remote_id) {
  sshlog("mux.c", __func__, 422, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "session already open");
  reply_error(reply, 0x80000003, rid,
      "Multiple sessions not supported");
 cleanup:
  close(new_fd[0]);
  close(new_fd[1]);
  close(new_fd[2]);
  free(cctx->term);
  if (env_len != 0) {
   for (i = 0; i < env_len; i++)
    free(cctx->env[i]);
   free(cctx->env);
  }
  sshbuf_free(cctx->cmd);
  free(cctx);
  return 0;
 }

 if (options.control_master == 3 ||
     options.control_master == 4) {
  if (!ask_permission("Allow shared connection to %s? ", host)) {
   sshlog("mux.c", __func__, 443, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "session refused by user");
   reply_error(reply, 0x80000002, rid,
       "Permission denied");
   goto cleanup;
  }
 }


 if (cctx->want_tty && tcgetattr(new_fd[0], &cctx->tio) == -1)
  sshlog("mux.c", __func__, 452, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "tcgetattr: %s", strerror(
 (*__errno_location ())
 ));

 window = (64*(32*1024));
 packetmax = (32*1024);
 if (cctx->want_tty) {
  window >>= 1;
  packetmax >>= 1;
 }

 nc = channel_new(ssh, "session", 3,
     new_fd[0], new_fd[1], new_fd[2], window, packetmax,
     2, "client-session", 2);

 nc->ctl_chan = c->self;
 c->remote_id = nc->self;
 c->have_remote_id = 1;

 if (cctx->want_tty && escape_char != 0xffffffff) {
  channel_register_filter(ssh, nc->self,
      client_simple_escape_filter, 
                                  ((void *)0)
                                      ,
      client_filter_cleanup,
      client_new_escape_filter_ctx((int)escape_char));
 }

 sshlog("mux.c", __func__, 476, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel_new: %d linked to control channel %d", nc->self, nc->ctl_chan)
                            ;

 channel_send_open(ssh, nc->self);
 channel_register_open_confirm(ssh, nc->self, mux_session_confirm, cctx);
 c->mux_pause = 1;
 channel_register_cleanup(ssh, nc->self,
     mux_master_session_cleanup_cb, 1);


 return 0;
}

static int
mux_master_process_alive_check(struct ssh *ssh, u_int rid,
    Channel *c, struct sshbuf *m, struct sshbuf *reply)
{
 int r;

 sshlog("mux.c", __func__, 495, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: alive check", c->self);


 if ((r = sshbuf_put_u32(reply, 0x80000005)) != 0 ||
     (r = sshbuf_put_u32(reply, rid)) != 0 ||
     (r = sshbuf_put_u32(reply, (u_int)getpid())) != 0)
  sshfatal("mux.c", __func__, 501, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reply");

 return 0;
}

static int
mux_master_process_terminate(struct ssh *ssh, u_int rid,
    Channel *c, struct sshbuf *m, struct sshbuf *reply)
{
 sshlog("mux.c", __func__, 510, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: terminate request", c->self);

 if (options.control_master == 3 ||
     options.control_master == 4) {
  if (!ask_permission("Terminate shared connection to %s? ",
      host)) {
   sshlog("mux.c", __func__, 516, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "termination refused by user");
   reply_error(reply, 0x80000002, rid,
       "Permission denied");
   return 0;
  }
 }

 quit_pending = 1;
 reply_ok(reply, rid);

 return 0;
}

static char *
format_forward(u_int ftype, struct Forward *fwd)
{
 char *ret;

 switch (ftype) {
 case 1:
  xasprintf(&ret, "local forward %.200s:%d -> %.200s:%d",
      (fwd->listen_path != 
                          ((void *)0)
                              ) ? fwd->listen_path :
      (fwd->listen_host == 
                          ((void *)0)
                              ) ?
      (options.fwd_opts.gateway_ports ? "*" : "LOCALHOST") :
      fwd->listen_host, fwd->listen_port,
      (fwd->connect_path != 
                           ((void *)0)
                               ) ? fwd->connect_path :
      fwd->connect_host, fwd->connect_port);
  break;
 case 3:
  xasprintf(&ret, "dynamic forward %.200s:%d -> *",
      (fwd->listen_host == 
                          ((void *)0)
                              ) ?
      (options.fwd_opts.gateway_ports ? "*" : "LOCALHOST") :
      fwd->listen_host, fwd->listen_port);
  break;
 case 2:
  xasprintf(&ret, "remote forward %.200s:%d -> %.200s:%d",
      (fwd->listen_path != 
                          ((void *)0)
                              ) ? fwd->listen_path :
      (fwd->listen_host == 
                          ((void *)0)
                              ) ?
      "LOCALHOST" : fwd->listen_host,
      fwd->listen_port,
      (fwd->connect_path != 
                           ((void *)0)
                               ) ? fwd->connect_path :
      fwd->connect_host, fwd->connect_port);
  break;
 default:
  sshfatal("mux.c", __func__, 560, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "unknown forward type %u", ftype);
 }
 return ret;
}

static int
compare_host(const char *a, const char *b)
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
 return strcmp(a, b) == 0;
}

static int
compare_forward(struct Forward *a, struct Forward *b)
{
 if (!compare_host(a->listen_host, b->listen_host))
  return 0;
 if (!compare_host(a->listen_path, b->listen_path))
  return 0;
 if (a->listen_port != b->listen_port)
  return 0;
 if (!compare_host(a->connect_host, b->connect_host))
  return 0;
 if (!compare_host(a->connect_path, b->connect_path))
  return 0;
 if (a->connect_port != b->connect_port)
  return 0;

 return 1;
}

static void
mux_confirm_remote_forward(struct ssh *ssh, int type, u_int32_t seq, void *ctxt)
{
 struct mux_channel_confirm_ctx *fctx = ctxt;
 char *failmsg = 
                ((void *)0)
                    ;
 struct Forward *rfwd;
 Channel *c;
 struct sshbuf *out;
 u_int port;
 int r;

 if ((c = channel_by_id(ssh, fctx->cid)) == 
                                           ((void *)0)
                                               ) {

  sshlog("mux.c", __func__, 607, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unknown channel");
  return;
 }
 if ((out = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("mux.c", __func__, 611, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 if (fctx->fid >= options.num_remote_forwards ||
     (options.remote_forwards[fctx->fid].connect_path == 
                                                        ((void *)0) 
                                                             &&
     options.remote_forwards[fctx->fid].connect_host == 
                                                       ((void *)0)
                                                           )) {
  xasprintf(&failmsg, "unknown forwarding id %d", fctx->fid);
  goto fail;
 }
 rfwd = &options.remote_forwards[fctx->fid];
 sshlog("mux.c", __func__, 619, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "%s for: listen %d, connect %s:%d", type == 81 ? "success" : "failure", rfwd->listen_port, rfwd->connect_path ? rfwd->connect_path : rfwd->connect_host, rfwd->connect_port)


                                            ;
 if (type == 81) {
  if (rfwd->listen_port == 0) {
   if ((r = sshpkt_get_u32(ssh, &port)) != 0)
    sshfatal("mux.c", __func__, 626, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse port");
   if (port > 65535) {
    sshfatal("mux.c", __func__, 628, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Invalid allocated port %u for " "mux remote forward to %s:%d", port, rfwd->connect_host, rfwd->connect_port)

                                               ;
   }
   rfwd->allocated_port = (int)port;
   sshlog("mux.c", __func__, 633, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Allocated port %u for mux remote forward" " to %s:%d", rfwd->allocated_port, rfwd->connect_host, rfwd->connect_port)

                                              ;
   if ((r = sshbuf_put_u32(out,
       0x80000007)) != 0 ||
       (r = sshbuf_put_u32(out, fctx->rid)) != 0 ||
       (r = sshbuf_put_u32(out,
       rfwd->allocated_port)) != 0)
    sshfatal("mux.c", __func__, 641, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reply");
   channel_update_permission(ssh, rfwd->handle,
       rfwd->allocated_port);
  } else {
   reply_ok(out, fctx->rid);
  }
  goto out;
 } else {
  if (rfwd->listen_port == 0)
   channel_update_permission(ssh, rfwd->handle, -1);
  if (rfwd->listen_path != 
                          ((void *)0)
                              )
   xasprintf(&failmsg, "remote port forwarding failed for "
       "listen path %s", rfwd->listen_path);
  else
   xasprintf(&failmsg, "remote port forwarding failed for "
       "listen port %d", rfwd->listen_port);

  sshlog("mux.c", __func__, 658, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "clearing registered forwarding for listen %d, " "connect %s:%d", rfwd->listen_port, rfwd->connect_path ? rfwd->connect_path : rfwd->connect_host, rfwd->connect_port)


                                             ;

  free(rfwd->listen_host);
  free(rfwd->listen_path);
  free(rfwd->connect_host);
  free(rfwd->connect_path);
  memset(rfwd, 0, sizeof(*rfwd));
 }
 fail:
 sshlog("mux.c", __func__, 670, 1, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "%s", failmsg);
 reply_error(out, 0x80000003, fctx->rid, failmsg);
 free(failmsg);
 out:
 if ((r = sshbuf_put_stringb(c->output, out)) != 0)
  sshfatal("mux.c", __func__, 675, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "enqueue");
 sshbuf_free(out);
 if (c->mux_pause <= 0)
  sshfatal("mux.c", __func__, 678, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "mux_pause %d", c->mux_pause);
 c->mux_pause = 0;
}

static int
mux_master_process_open_fwd(struct ssh *ssh, u_int rid,
    Channel *c, struct sshbuf *m, struct sshbuf *reply)
{
 struct Forward fwd;
 char *fwd_desc = 
                 ((void *)0)
                     ;
 char *listen_addr, *connect_addr;
 u_int ftype;
 u_int lport, cport;
 int r, i, ret = 0, freefwd = 1;

 memset(&fwd, 0, sizeof(fwd));


 if ((r = sshbuf_get_u32(m, &ftype)) != 0 ||
     (r = sshbuf_get_cstring(m, &listen_addr, 
                                             ((void *)0)
                                                 )) != 0 ||
     (r = sshbuf_get_u32(m, &lport)) != 0 ||
     (r = sshbuf_get_cstring(m, &connect_addr, 
                                              ((void *)0)
                                                  )) != 0 ||
     (r = sshbuf_get_u32(m, &cport)) != 0 ||
     (lport != (u_int)-2 && lport > 65535) ||
     (cport != (u_int)-2 && cport > 65535)) {
  sshlog("mux.c", __func__, 703, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "malformed message");
  ret = -1;
  goto out;
 }
 if (*listen_addr == '\0') {
  free(listen_addr);
  listen_addr = 
               ((void *)0)
                   ;
 }
 if (*connect_addr == '\0') {
  free(connect_addr);
  connect_addr = 
                ((void *)0)
                    ;
 }

 memset(&fwd, 0, sizeof(fwd));
 fwd.listen_port = lport;
 if (fwd.listen_port == -2)
  fwd.listen_path = listen_addr;
 else
  fwd.listen_host = listen_addr;
 fwd.connect_port = cport;
 if (fwd.connect_port == -2)
  fwd.connect_path = connect_addr;
 else
  fwd.connect_host = connect_addr;

 sshlog("mux.c", __func__, 728, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: request %s", c->self, (fwd_desc = format_forward(ftype, &fwd)))
                                              ;

 if (ftype != 1 && ftype != 2 &&
     ftype != 3) {
  sshlog("mux.c", __func__, 733, 1, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "invalid forwarding type %u", ftype);
 invalid:
  free(listen_addr);
  free(connect_addr);
  reply_error(reply, 0x80000003, rid,
      "Invalid forwarding request");
  return 0;
 }
 if (ftype == 3 && fwd.listen_path) {
  sshlog("mux.c", __func__, 742, 1, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "streamlocal and dynamic forwards " "are mutually exclusive")
                               ;
  goto invalid;
 }
 if (fwd.listen_port != -2 && fwd.listen_port >= 65536) {
  sshlog("mux.c", __func__, 747, 1, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "invalid listen port %u", fwd.listen_port);
  goto invalid;
 }
 if ((fwd.connect_port != -2 &&
     fwd.connect_port >= 65536) ||
     (ftype != 3 && ftype != 2 &&
     fwd.connect_port == 0)) {
  sshlog("mux.c", __func__, 754, 1, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "invalid connect port %u", fwd.connect_port)
                       ;
  goto invalid;
 }
 if (ftype != 3 && fwd.connect_host == 
                                                    ((void *)0) 
                                                         &&
     fwd.connect_path == 
                        ((void *)0)
                            ) {
  sshlog("mux.c", __func__, 760, 1, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "missing connect host");
  goto invalid;
 }


 switch (ftype) {
 case 1:
 case 3:
  for (i = 0; i < options.num_local_forwards; i++) {
   if (compare_forward(&fwd,
       options.local_forwards + i)) {
 exists:
    sshlog("mux.c", __func__, 772, 1, SYSLOG_LEVEL_DEBUG2, 
   ((void *)0)
   , "found existing forwarding");
    reply_ok(reply, rid);
    goto out;
   }
  }
  break;
 case 2:
  for (i = 0; i < options.num_remote_forwards; i++) {
   if (!compare_forward(&fwd, options.remote_forwards + i))
    continue;
   if (fwd.listen_port != 0)
    goto exists;
   sshlog("mux.c", __func__, 784, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "found allocated port");
   if ((r = sshbuf_put_u32(reply,
       0x80000007)) != 0 ||
       (r = sshbuf_put_u32(reply, rid)) != 0 ||
       (r = sshbuf_put_u32(reply,
       options.remote_forwards[i].allocated_port)) != 0)
    sshfatal("mux.c", __func__, 790, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reply FWD_REMOTE");
   goto out;
  }
  break;
 }

 if (options.control_master == 3 ||
     options.control_master == 4) {
  if (!ask_permission("Open %s on %s?", fwd_desc, host)) {
   sshlog("mux.c", __func__, 799, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "forwarding refused by user");
   reply_error(reply, 0x80000002, rid,
       "Permission denied");
   goto out;
  }
 }

 if (ftype == 1 || ftype == 3) {
  if (!channel_setup_local_fwd_listener(ssh, &fwd,
      &options.fwd_opts)) {
 fail:
   sshlog("mux.c", __func__, 810, 1, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "requested %s failed", fwd_desc);
   reply_error(reply, 0x80000003, rid,
       "Port forwarding failed");
   goto out;
  }
  add_local_forward(&options, &fwd);
  freefwd = 0;
 } else {
  struct mux_channel_confirm_ctx *fctx;

  fwd.handle = channel_request_remote_forwarding(ssh, &fwd);
  if (fwd.handle < 0)
   goto fail;
  add_remote_forward(&options, &fwd);
  fctx = xcalloc(1, sizeof(*fctx));
  fctx->cid = c->self;
  fctx->rid = rid;
  fctx->fid = options.num_remote_forwards - 1;
  client_register_global_confirm(mux_confirm_remote_forward,
      fctx);
  freefwd = 0;
  c->mux_pause = 1;

  goto out;
 }
 reply_ok(reply, rid);
 out:
 free(fwd_desc);
 if (freefwd) {
  free(fwd.listen_host);
  free(fwd.listen_path);
  free(fwd.connect_host);
  free(fwd.connect_path);
 }
 return ret;
}

static int
mux_master_process_close_fwd(struct ssh *ssh, u_int rid,
    Channel *c, struct sshbuf *m, struct sshbuf *reply)
{
 struct Forward fwd, *found_fwd;
 char *fwd_desc = 
                 ((void *)0)
                     ;
 const char *error_reason = 
                           ((void *)0)
                               ;
 char *listen_addr = 
                    ((void *)0)
                        , *connect_addr = 
                                          ((void *)0)
                                              ;
 u_int ftype;
 int r, i, ret = 0;
 u_int lport, cport;

 memset(&fwd, 0, sizeof(fwd));

 if ((r = sshbuf_get_u32(m, &ftype)) != 0 ||
     (r = sshbuf_get_cstring(m, &listen_addr, 
                                             ((void *)0)
                                                 )) != 0 ||
     (r = sshbuf_get_u32(m, &lport)) != 0 ||
     (r = sshbuf_get_cstring(m, &connect_addr, 
                                              ((void *)0)
                                                  )) != 0 ||
     (r = sshbuf_get_u32(m, &cport)) != 0 ||
     (lport != (u_int)-2 && lport > 65535) ||
     (cport != (u_int)-2 && cport > 65535)) {
  sshlog("mux.c", __func__, 868, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "malformed message");
  ret = -1;
  goto out;
 }

 if (*listen_addr == '\0') {
  free(listen_addr);
  listen_addr = 
               ((void *)0)
                   ;
 }
 if (*connect_addr == '\0') {
  free(connect_addr);
  connect_addr = 
                ((void *)0)
                    ;
 }

 memset(&fwd, 0, sizeof(fwd));
 fwd.listen_port = lport;
 if (fwd.listen_port == -2)
  fwd.listen_path = listen_addr;
 else
  fwd.listen_host = listen_addr;
 fwd.connect_port = cport;
 if (fwd.connect_port == -2)
  fwd.connect_path = connect_addr;
 else
  fwd.connect_host = connect_addr;

 sshlog("mux.c", __func__, 894, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: request cancel %s", c->self, (fwd_desc = format_forward(ftype, &fwd)))
                                              ;


 found_fwd = 
            ((void *)0)
                ;
 switch (ftype) {
 case 1:
 case 3:
  for (i = 0; i < options.num_local_forwards; i++) {
   if (compare_forward(&fwd,
       options.local_forwards + i)) {
    found_fwd = options.local_forwards + i;
    break;
   }
  }
  break;
 case 2:
  for (i = 0; i < options.num_remote_forwards; i++) {
   if (compare_forward(&fwd,
       options.remote_forwards + i)) {
    found_fwd = options.remote_forwards + i;
    break;
   }
  }
  break;
 }

 if (found_fwd == 
                 ((void *)0)
                     )
  error_reason = "port not forwarded";
 else if (ftype == 2) {






  if (channel_request_rforward_cancel(ssh, found_fwd) == -1)
   error_reason = "port not in permitted opens";
 } else {

  if (channel_cancel_lport_listener(ssh, &fwd, fwd.connect_port,
      &options.fwd_opts) == -1)
   error_reason = "port not found";
 }

 if (error_reason != 
                    ((void *)0)
                        )
  reply_error(reply, 0x80000003, rid, error_reason);
 else {
  reply_ok(reply, rid);
  free(found_fwd->listen_host);
  free(found_fwd->listen_path);
  free(found_fwd->connect_host);
  free(found_fwd->connect_path);
  found_fwd->listen_host = found_fwd->connect_host = 
                                                    ((void *)0)
                                                        ;
  found_fwd->listen_path = found_fwd->connect_path = 
                                                    ((void *)0)
                                                        ;
  found_fwd->listen_port = found_fwd->connect_port = 0;
 }
 out:
 free(fwd_desc);
 free(listen_addr);
 free(connect_addr);

 return ret;
}

static int
mux_master_process_stdio_fwd(struct ssh *ssh, u_int rid,
    Channel *c, struct sshbuf *m, struct sshbuf *reply)
{
 Channel *nc;
 char *chost = 
              ((void *)0)
                  ;
 u_int cport, i, j;
 int r, new_fd[2];
 struct mux_stdio_confirm_ctx *cctx;

 if ((r = sshbuf_get_string_direct(m, 
         ((void *)0)
         , 
         ((void *)0)
         )) != 0 ||
     (r = sshbuf_get_cstring(m, &chost, 
                                       ((void *)0)
                                           )) != 0 ||
     (r = sshbuf_get_u32(m, &cport)) != 0) {
  free(chost);
  sshlog("mux.c", __func__, 973, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "malformed message");
  return -1;
 }

 sshlog("mux.c", __func__, 977, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: stdio fwd to %s:%u", c->self, chost, cport);


 for(i = 0; i < 2; i++) {
  if ((new_fd[i] = mm_receive_fd(c->sock)) == -1) {
   sshlog("mux.c", __func__, 982, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "failed to receive fd %d from client", i);
   for (j = 0; j < i; j++)
    close(new_fd[j]);
   free(chost);


   reply_error(reply, 0x80000003, rid,
       "did not receive file descriptors");
   return -1;
  }
 }

 sshlog("mux.c", __func__, 994, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "got fds stdin %d, stdout %d", new_fd[0], new_fd[1]);


 if (c->have_remote_id) {
  sshlog("mux.c", __func__, 998, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "session already open");
  reply_error(reply, 0x80000003, rid,
      "Multiple sessions not supported");
 cleanup:
  close(new_fd[0]);
  close(new_fd[1]);
  free(chost);
  return 0;
 }

 if (options.control_master == 3 ||
     options.control_master == 4) {
  if (!ask_permission("Allow forward to %s:%u? ",
      chost, cport)) {
   sshlog("mux.c", __func__, 1012, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "stdio fwd refused by user");
   reply_error(reply, 0x80000002, rid,
       "Permission denied");
   goto cleanup;
  }
 }

 nc = channel_connect_stdio_fwd(ssh, chost, cport, new_fd[0], new_fd[1],
     2);
 free(chost);

 nc->ctl_chan = c->self;
 c->remote_id = nc->self;
 c->have_remote_id = 1;

 sshlog("mux.c", __func__, 1027, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel_new: %d control %d", nc->self, nc->ctl_chan);

 channel_register_cleanup(ssh, nc->self,
     mux_master_session_cleanup_cb, 1);

 cctx = xcalloc(1, sizeof(*cctx));
 cctx->rid = rid;
 channel_register_open_confirm(ssh, nc->self, mux_stdio_confirm, cctx);
 c->mux_pause = 1;


 return 0;
}


static void
mux_stdio_confirm(struct ssh *ssh, int id, int success, void *arg)
{
 struct mux_stdio_confirm_ctx *cctx = arg;
 Channel *c, *cc;
 struct sshbuf *reply;
 int r;

 if (cctx == 
            ((void *)0)
                )
  sshfatal("mux.c", __func__, 1051, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "cctx == NULL");
 if ((c = channel_by_id(ssh, id)) == 
                                    ((void *)0)
                                        )
  sshfatal("mux.c", __func__, 1053, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "no channel for id %d", id);
 if ((cc = channel_by_id(ssh, c->ctl_chan)) == 
                                              ((void *)0)
                                                  )
  sshfatal("mux.c", __func__, 1055, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel %d lacks control channel %d", id, c->ctl_chan)
                      ;
 if ((reply = sshbuf_new()) == 
                              ((void *)0)
                                  )
  sshfatal("mux.c", __func__, 1058, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");

 if (!success) {
  sshlog("mux.c", __func__, 1061, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "sending failure reply");
  reply_error(reply, 0x80000003, cctx->rid,
      "Session open refused by peer");

  goto done;
 }

 sshlog("mux.c", __func__, 1068, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "sending success reply");

 if ((r = sshbuf_put_u32(reply, 0x80000006)) != 0 ||
     (r = sshbuf_put_u32(reply, cctx->rid)) != 0 ||
     (r = sshbuf_put_u32(reply, c->self)) != 0)
  sshfatal("mux.c", __func__, 1073, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reply");

 done:

 if ((r = sshbuf_put_stringb(cc->output, reply)) != 0)
  sshfatal("mux.c", __func__, 1078, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "enqueue");
 sshbuf_free(reply);

 if (cc->mux_pause <= 0)
  sshfatal("mux.c", __func__, 1082, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "mux_pause %d", cc->mux_pause);
 cc->mux_pause = 0;
 c->open_confirm_ctx = 
                      ((void *)0)
                          ;
 free(cctx);
}

static int
mux_master_process_stop_listening(struct ssh *ssh, u_int rid,
    Channel *c, struct sshbuf *m, struct sshbuf *reply)
{
 sshlog("mux.c", __func__, 1092, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "channel %d: stop listening", c->self);

 if (options.control_master == 3 ||
     options.control_master == 4) {
  if (!ask_permission("Disable further multiplexing on shared "
      "connection to %s? ", host)) {
   sshlog("mux.c", __func__, 1098, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "stop listen refused by user");
   reply_error(reply, 0x80000002, rid,
       "Permission denied");
   return 0;
  }
 }

 if (mux_listener_channel != 
                            ((void *)0)
                                ) {
  channel_free(ssh, mux_listener_channel);
  client_stop_mux();
  free(options.control_path);
  options.control_path = 
                        ((void *)0)
                            ;
  mux_listener_channel = 
                        ((void *)0)
                            ;
  muxserver_sock = -1;
 }

 reply_ok(reply, rid);
 return 0;
}

static int
mux_master_process_proxy(struct ssh *ssh, u_int rid,
    Channel *c, struct sshbuf *m, struct sshbuf *reply)
{
 int r;

 sshlog("mux.c", __func__, 1124, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "channel %d: proxy request", c->self);

 c->mux_rcb = channel_proxy_downstream;
 if ((r = sshbuf_put_u32(reply, 0x8000000f)) != 0 ||
     (r = sshbuf_put_u32(reply, rid)) != 0)
  sshfatal("mux.c", __func__, 1129, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reply");

 return 0;
}


static int
mux_master_read_cb(struct ssh *ssh, Channel *c)
{
 struct mux_master_state *state = (struct mux_master_state *)c->mux_ctx;
 struct sshbuf *in = 
                    ((void *)0)
                        , *out = 
                                 ((void *)0)
                                     ;
 u_int type, rid, i;
 int r, ret = -1;

 if ((out = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("mux.c", __func__, 1144, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");


 if (c->mux_ctx == 
                  ((void *)0)
                      ) {
  state = xcalloc(1, sizeof(*state));
  c->mux_ctx = state;
  channel_register_cleanup(ssh, c->self,
      mux_master_control_cleanup_cb, 0);


  if ((r = sshbuf_put_u32(out, 0x00000001)) != 0 ||
      (r = sshbuf_put_u32(out, 4)) != 0)
   sshfatal("mux.c", __func__, 1156, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reply");

  if ((r = sshbuf_put_stringb(c->output, out)) != 0)
   sshfatal("mux.c", __func__, 1159, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "enqueue");
  sshlog("mux.c", __func__, 1160, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "channel %d: hello sent", c->self);
  ret = 0;
  goto out;
 }


 if ((r = sshbuf_froms(c->input, &in)) != 0) {
 malf:
  sshlog("mux.c", __func__, 1168, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "malformed message");
  goto out;
 }

 if ((r = sshbuf_get_u32(in, &type)) != 0)
  goto malf;
 sshlog("mux.c", __func__, 1174, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "channel %d packet type 0x%08x len %zu", c->self, type, sshbuf_len(in))
                          ;

 if (type == 0x00000001)
  rid = 0;
 else {
  if (!state->hello_rcvd) {
   sshlog("mux.c", __func__, 1181, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "expected MUX_MSG_HELLO(0x%08x), " "received 0x%08x", 0x00000001, type)
                                              ;
   goto out;
  }
  if ((r = sshbuf_get_u32(in, &rid)) != 0)
   goto malf;
 }

 for (i = 0; mux_master_handlers[i].handler != 
                                              ((void *)0)
                                                  ; i++) {
  if (type == mux_master_handlers[i].type) {
   ret = mux_master_handlers[i].handler(ssh, rid,
       c, in, out);
   break;
  }
 }
 if (mux_master_handlers[i].handler == 
                                      ((void *)0)
                                          ) {
  sshlog("mux.c", __func__, 1197, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unsupported mux message 0x%08x", type);
  reply_error(out, 0x80000003, rid, "unsupported request");
  ret = 0;
 }

 if (sshbuf_len(out) != 0 &&
     (r = sshbuf_put_stringb(c->output, out)) != 0)
  sshfatal("mux.c", __func__, 1204, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "enqueue");
 out:
 sshbuf_free(in);
 sshbuf_free(out);
 return ret;
}

void
mux_exit_message(struct ssh *ssh, Channel *c, int exitval)
{
 struct sshbuf *m;
 Channel *mux_chan;
 int r;

 sshlog("mux.c", __func__, 1218, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "channel %d: exit message, exitval %d", c->self, exitval);

 if ((mux_chan = channel_by_id(ssh, c->ctl_chan)) == 
                                                    ((void *)0)
                                                        )
  sshfatal("mux.c", __func__, 1221, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel %d missing mux %d", c->self, c->ctl_chan);


 if ((m = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("mux.c", __func__, 1225, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 if ((r = sshbuf_put_u32(m, 0x80000004)) != 0 ||
     (r = sshbuf_put_u32(m, c->self)) != 0 ||
     (r = sshbuf_put_u32(m, exitval)) != 0 ||
     (r = sshbuf_put_stringb(mux_chan->output, m)) != 0)
  sshfatal("mux.c", __func__, 1230, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reply");
 sshbuf_free(m);
}

void
mux_tty_alloc_failed(struct ssh *ssh, Channel *c)
{
 struct sshbuf *m;
 Channel *mux_chan;
 int r;

 sshlog("mux.c", __func__, 1241, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "channel %d: TTY alloc failed", c->self);

 if ((mux_chan = channel_by_id(ssh, c->ctl_chan)) == 
                                                    ((void *)0)
                                                        )
  sshfatal("mux.c", __func__, 1244, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel %d missing mux %d", c->self, c->ctl_chan);


 if ((m = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("mux.c", __func__, 1248, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 if ((r = sshbuf_put_u32(m, 0x80000008)) != 0 ||
     (r = sshbuf_put_u32(m, c->self)) != 0 ||
     (r = sshbuf_put_stringb(mux_chan->output, m)) != 0)
  sshfatal("mux.c", __func__, 1252, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reply");
 sshbuf_free(m);
}


void
muxserver_listen(struct ssh *ssh)
{
 mode_t old_umask;
 char *orig_control_path = options.control_path;
 char rbuf[16+1];
 u_int i, r;
 int oerrno;

 if (options.control_path == 
                            ((void *)0) 
                                 ||
     options.control_master == 0)
  return;

 sshlog("mux.c", __func__, 1270, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "setting up multiplex master socket");







 for (i = 0; i < sizeof(rbuf) - 1; i++) {
  r = arc4random_uniform(26+26+10);
  rbuf[i] = (r < 26) ? 'a' + r :
      (r < 26*2) ? 'A' + r - 26 :
      '0' + r - 26 - 26;
 }
 rbuf[sizeof(rbuf) - 1] = '\0';
 options.control_path = 
                       ((void *)0)
                           ;
 xasprintf(&options.control_path, "%s.%s", orig_control_path, rbuf);
 sshlog("mux.c", __func__, 1287, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "temporary control path %s", options.control_path);

 old_umask = umask(0177);
 muxserver_sock = unix_listener(options.control_path, 64, 0);
 oerrno = 
         (*__errno_location ())
              ;
 umask(old_umask);
 if (muxserver_sock < 0) {
  if (oerrno == 
               22 
                      || oerrno == 
                                   98
                                             ) {
   sshlog("mux.c", __func__, 1295, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "ControlSocket %s already exists, " "disabling multiplexing", options.control_path)
                                                      ;
 disable_mux_master:
   if (muxserver_sock != -1) {
    close(muxserver_sock);
    muxserver_sock = -1;
   }
   free(orig_control_path);
   free(options.control_path);
   options.control_path = 
                         ((void *)0)
                             ;
   options.control_master = 0;
   return;
  } else {

   cleanup_exit(255);
  }
 }


 if (link(options.control_path, orig_control_path) != 0) {
  if (
     (*__errno_location ()) 
           != 
              17
                    ) {
   sshfatal("mux.c", __func__, 1316, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "link mux listener %s => %s: %s", options.control_path, orig_control_path, strerror(
  (*__errno_location ())
  ))

                       ;
  }
  sshlog("mux.c", __func__, 1320, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "ControlSocket %s already exists, disabling multiplexing", orig_control_path)
                        ;
  unlink(options.control_path);
  goto disable_mux_master;
 }
 unlink(options.control_path);
 free(options.control_path);
 options.control_path = orig_control_path;

 set_nonblock(muxserver_sock);

 mux_listener_channel = channel_new(ssh, "mux listener",
     15, muxserver_sock, muxserver_sock, -1,
     (64*(32*1024)), (32*1024),
     0, options.control_path, 1);
 mux_listener_channel->mux_rcb = mux_master_read_cb;
 sshlog("mux.c", __func__, 1336, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "mux listener channel %d fd %d", mux_listener_channel->self, mux_listener_channel->sock)
                                                            ;
}


static void
mux_session_confirm(struct ssh *ssh, int id, int success, void *arg)
{
 struct mux_session_confirm_ctx *cctx = arg;
 const char *display;
 Channel *c, *cc;
 int i, r;
 struct sshbuf *reply;

 if (cctx == 
            ((void *)0)
                )
  sshfatal("mux.c", __func__, 1351, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "cctx == NULL");
 if ((c = channel_by_id(ssh, id)) == 
                                    ((void *)0)
                                        )
  sshfatal("mux.c", __func__, 1353, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "no channel for id %d", id);
 if ((cc = channel_by_id(ssh, c->ctl_chan)) == 
                                              ((void *)0)
                                                  )
  sshfatal("mux.c", __func__, 1355, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel %d lacks control channel %d", id, c->ctl_chan)
                      ;
 if ((reply = sshbuf_new()) == 
                              ((void *)0)
                                  )
  sshfatal("mux.c", __func__, 1358, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");

 if (!success) {
  sshlog("mux.c", __func__, 1361, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "sending failure reply");
  reply_error(reply, 0x80000003, cctx->rid,
      "Session open refused by peer");
  goto done;
 }

 display = getenv("DISPLAY");
 if (cctx->want_x_fwd && options.forward_x11 && display != 
                                                          ((void *)0)
                                                              ) {
  char *proto, *data;


  if (client_x11_get_proto(ssh, display, options.xauth_location,
      options.forward_x11_trusted, options.forward_x11_timeout,
      &proto, &data) == 0) {

   sshlog("mux.c", __func__, 1376, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Requesting X11 forwarding with authentication " "spoofing.")
                   ;
   x11_request_forwarding_with_spoofing(ssh, id,
       display, proto, data, 1);

   client_expect_confirm(ssh, id, "X11 forwarding",
       CONFIRM_WARN);
  }
 }

 if (cctx->want_agent_fwd && options.forward_agent) {
  sshlog("mux.c", __func__, 1387, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Requesting authentication agent forwarding.");
  channel_request_start(ssh, id, "auth-agent-req@openssh.com", 0);
  if ((r = sshpkt_send(ssh)) != 0)
   sshfatal("mux.c", __func__, 1390, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send");
 }

 client_session2_setup(ssh, id, cctx->want_tty, cctx->want_subsys,
     cctx->term, &cctx->tio, c->rfd, cctx->cmd, cctx->env);

 sshlog("mux.c", __func__, 1396, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "sending success reply");

 if ((r = sshbuf_put_u32(reply, 0x80000006)) != 0 ||
     (r = sshbuf_put_u32(reply, cctx->rid)) != 0 ||
     (r = sshbuf_put_u32(reply, c->self)) != 0)
  sshfatal("mux.c", __func__, 1401, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reply");

 done:

 if ((r = sshbuf_put_stringb(cc->output, reply)) != 0)
  sshfatal("mux.c", __func__, 1406, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "enqueue");
 sshbuf_free(reply);

 if (cc->mux_pause <= 0)
  sshfatal("mux.c", __func__, 1410, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "mux_pause %d", cc->mux_pause);
 cc->mux_pause = 0;
 c->open_confirm_ctx = 
                      ((void *)0)
                          ;
 sshbuf_free(cctx->cmd);
 free(cctx->term);
 if (cctx->env != 
                 ((void *)0)
                     ) {
  for (i = 0; cctx->env[i] != 
                             ((void *)0)
                                 ; i++)
   free(cctx->env[i]);
  free(cctx->env);
 }
 free(cctx);
}




static void
control_client_sighandler(int signo)
{
 muxclient_terminate = signo;
}





static void
control_client_sigrelay(int signo)
{
 int save_errno = 
                 (*__errno_location ())
                      ;

 if (muxserver_pid > 1)
  kill(muxserver_pid, signo);

 
(*__errno_location ()) 
      = save_errno;
}

static int
mux_client_read(int fd, struct sshbuf *b, size_t need)
{
 size_t have;
 ssize_t len;
 u_char *p;
 struct pollfd pfd;
 int r;

 pfd.fd = fd;
 pfd.events = 
             0x001
                   ;
 if ((r = sshbuf_reserve(b, need, &p)) != 0)
  sshfatal("mux.c", __func__, 1459, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reserve");
 for (have = 0; have < need; ) {
  if (muxclient_terminate) {
   
  (*__errno_location ()) 
        = 
          4
               ;
   return -1;
  }
  len = read(fd, p + have, need - have);
  if (len == -1) {
   switch (
          (*__errno_location ())
               ) {



   case 
       11
             :
    (void)poll(&pfd, 1, -1);

   case 
       4
            :
    continue;
   default:
    return -1;
   }
  }
  if (len == 0) {
   
  (*__errno_location ()) 
        = 
          32
               ;
   return -1;
  }
  have += (size_t)len;
 }
 return 0;
}

static int
mux_client_write_packet(int fd, struct sshbuf *m)
{
 struct sshbuf *queue;
 u_int have, need;
 int r, oerrno, len;
 const u_char *ptr;
 struct pollfd pfd;

 pfd.fd = fd;
 pfd.events = 
             0x004
                    ;
 if ((queue = sshbuf_new()) == 
                              ((void *)0)
                                  )
  sshfatal("mux.c", __func__, 1501, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 if ((r = sshbuf_put_stringb(queue, m)) != 0)
  sshfatal("mux.c", __func__, 1503, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "enqueue");

 need = sshbuf_len(queue);
 ptr = sshbuf_ptr(queue);

 for (have = 0; have < need; ) {
  if (muxclient_terminate) {
   sshbuf_free(queue);
   
  (*__errno_location ()) 
        = 
          4
               ;
   return -1;
  }
  len = write(fd, ptr + have, need - have);
  if (len == -1) {
   switch (
          (*__errno_location ())
               ) {



   case 
       11
             :
    (void)poll(&pfd, 1, -1);

   case 
       4
            :
    continue;
   default:
    oerrno = 
            (*__errno_location ())
                 ;
    sshbuf_free(queue);
    
   (*__errno_location ()) 
         = oerrno;
    return -1;
   }
  }
  if (len == 0) {
   sshbuf_free(queue);
   
  (*__errno_location ()) 
        = 
          32
               ;
   return -1;
  }
  have += (u_int)len;
 }
 sshbuf_free(queue);
 return 0;
}

static int
mux_client_read_packet(int fd, struct sshbuf *m)
{
 struct sshbuf *queue;
 size_t need, have;
 const u_char *ptr;
 int r, oerrno;

 if ((queue = sshbuf_new()) == 
                              ((void *)0)
                                  )
  sshfatal("mux.c", __func__, 1552, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 if (mux_client_read(fd, queue, 4) != 0) {
  if ((oerrno = 
               (*__errno_location ())
                    ) == 
                         32
                              )
   sshlog("mux.c", __func__, 1555, 1, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "read header failed: %s", strerror(
  (*__errno_location ())
  ))
                       ;
  sshbuf_free(queue);
  
 (*__errno_location ()) 
       = oerrno;
  return -1;
 }
 need = (((u_int32_t)(((const u_char *)(sshbuf_ptr(queue)))[0]) << 24) | ((u_int32_t)(((const u_char *)(sshbuf_ptr(queue)))[1]) << 16) | ((u_int32_t)(((const u_char *)(sshbuf_ptr(queue)))[2]) << 8) | (u_int32_t)(((const u_char *)(sshbuf_ptr(queue)))[3]));
 if (mux_client_read(fd, queue, need) != 0) {
  oerrno = 
          (*__errno_location ())
               ;
  sshlog("mux.c", __func__, 1564, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "read body failed: %s", strerror(
 (*__errno_location ())
 ));
  sshbuf_free(queue);
  
 (*__errno_location ()) 
       = oerrno;
  return -1;
 }
 if ((r = sshbuf_get_string_direct(queue, &ptr, &have)) != 0 ||
     (r = sshbuf_put(m, ptr, have)) != 0)
  sshfatal("mux.c", __func__, 1571, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "dequeue");
 sshbuf_free(queue);
 return 0;
}

static int
mux_client_hello_exchange(int fd)
{
 struct sshbuf *m;
 u_int type, ver;
 int r, ret = -1;

 if ((m = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("mux.c", __func__, 1584, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 if ((r = sshbuf_put_u32(m, 0x00000001)) != 0 ||
     (r = sshbuf_put_u32(m, 4)) != 0)
  sshfatal("mux.c", __func__, 1587, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble hello");


 if (mux_client_write_packet(fd, m) != 0) {
  sshlog("mux.c", __func__, 1591, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "write packet: %s", strerror(
 (*__errno_location ())
 ));
  goto out;
 }

 sshbuf_reset(m);


 if (mux_client_read_packet(fd, m) != 0) {
  sshlog("mux.c", __func__, 1599, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "read packet failed");
  goto out;
 }

 if ((r = sshbuf_get_u32(m, &type)) != 0)
  sshfatal("mux.c", __func__, 1604, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse type");
 if (type != 0x00000001) {
  sshlog("mux.c", __func__, 1606, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "expected HELLO (%u) got %u", 0x00000001, type);
  goto out;
 }
 if ((r = sshbuf_get_u32(m, &ver)) != 0)
  sshfatal("mux.c", __func__, 1610, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse version");
 if (ver != 4) {
  sshlog("mux.c", __func__, 1612, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Unsupported multiplexing protocol version %d " "(expected %d)", ver, 4)
                                       ;
  goto out;
 }
 sshlog("mux.c", __func__, 1616, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "master version %u", ver);

 while (sshbuf_len(m) > 0) {
  char *name = 
              ((void *)0)
                  ;

  if ((r = sshbuf_get_cstring(m, &name, 
                                       ((void *)0)
                                           )) != 0 ||
      (r = sshbuf_get_string_direct(m, 
          ((void *)0)
          , 
          ((void *)0)
          )) != 0) {
   sshlog("mux.c", __func__, 1623, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse extension");
   goto out;
  }
  sshlog("mux.c", __func__, 1626, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "Unrecognised master extension \"%s\"", name);
  free(name);
 }

 ret = 0;
 out:
 sshbuf_free(m);
 return ret;
}

static u_int
mux_client_request_alive(int fd)
{
 struct sshbuf *m;
 char *e;
 u_int pid, type, rid;
 int r;

 sshlog("mux.c", __func__, 1644, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "entering");

 if ((m = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("mux.c", __func__, 1647, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 if ((r = sshbuf_put_u32(m, 0x10000004)) != 0 ||
     (r = sshbuf_put_u32(m, muxclient_request_id)) != 0)
  sshfatal("mux.c", __func__, 1650, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble");

 if (mux_client_write_packet(fd, m) != 0)
  sshfatal("mux.c", __func__, 1653, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "write packet: %s", strerror(
 (*__errno_location ())
 ));

 sshbuf_reset(m);


 if (mux_client_read_packet(fd, m) != 0) {
  sshbuf_free(m);
  return 0;
 }

 if ((r = sshbuf_get_u32(m, &type)) != 0)
  sshfatal("mux.c", __func__, 1664, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse type");
 if (type != 0x80000005) {
  if ((r = sshbuf_get_cstring(m, &e, 
                                    ((void *)0)
                                        )) != 0)
   sshfatal("mux.c", __func__, 1667, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse error message");
  sshfatal("mux.c", __func__, 1668, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "master returned error: %s", e);
 }

 if ((r = sshbuf_get_u32(m, &rid)) != 0)
  sshfatal("mux.c", __func__, 1672, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse remote ID");
 if (rid != muxclient_request_id)
  sshfatal("mux.c", __func__, 1674, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "out of sequence reply: my id %u theirs %u", muxclient_request_id, rid)
                                ;
 if ((r = sshbuf_get_u32(m, &pid)) != 0)
  sshfatal("mux.c", __func__, 1677, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse PID");
 sshbuf_free(m);

 sshlog("mux.c", __func__, 1680, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "done pid = %u", pid);

 muxclient_request_id++;

 return pid;
}

static void
mux_client_request_terminate(int fd)
{
 struct sshbuf *m;
 char *e;
 u_int type, rid;
 int r;

 sshlog("mux.c", __func__, 1695, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "entering");

 if ((m = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("mux.c", __func__, 1698, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 if ((r = sshbuf_put_u32(m, 0x10000005)) != 0 ||
     (r = sshbuf_put_u32(m, muxclient_request_id)) != 0)
  sshfatal("mux.c", __func__, 1701, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "request");

 if (mux_client_write_packet(fd, m) != 0)
  sshfatal("mux.c", __func__, 1704, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "write packet: %s", strerror(
 (*__errno_location ())
 ));

 sshbuf_reset(m);


 if (mux_client_read_packet(fd, m) != 0) {

  if (
     (*__errno_location ()) 
           == 
              32
                   ) {
   sshbuf_free(m);
   return;
  }
  sshfatal("mux.c", __func__, 1715, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "read from master failed: %s", strerror(
 (*__errno_location ())
 ));
 }

 if ((r = sshbuf_get_u32(m, &type)) != 0 ||
     (r = sshbuf_get_u32(m, &rid)) != 0)
  sshfatal("mux.c", __func__, 1720, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 if (rid != muxclient_request_id)
  sshfatal("mux.c", __func__, 1722, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "out of sequence reply: my id %u theirs %u", muxclient_request_id, rid)
                                ;
 switch (type) {
 case 0x80000001:
  break;
 case 0x80000002:
  if ((r = sshbuf_get_cstring(m, &e, 
                                    ((void *)0)
                                        )) != 0)
   sshfatal("mux.c", __func__, 1729, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse error message");
  sshfatal("mux.c", __func__, 1730, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Master refused termination request: %s", e);
 case 0x80000003:
  if ((r = sshbuf_get_cstring(m, &e, 
                                    ((void *)0)
                                        )) != 0)
   sshfatal("mux.c", __func__, 1733, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse error message");
  sshfatal("mux.c", __func__, 1734, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "termination request failed: %s", e);
 default:
  sshfatal("mux.c", __func__, 1736, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "unexpected response from master 0x%08x", type);
 }
 sshbuf_free(m);
 muxclient_request_id++;
}

static int
mux_client_forward(int fd, int cancel_flag, u_int ftype, struct Forward *fwd)
{
 struct sshbuf *m;
 char *e, *fwd_desc;
 const char *lhost, *chost;
 u_int type, rid;
 int r;

 fwd_desc = format_forward(ftype, fwd);
 sshlog("mux.c", __func__, 1752, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Requesting %s %s", cancel_flag ? "cancellation of" : "forwarding of", fwd_desc)
                                                                 ;
 free(fwd_desc);

 type = cancel_flag ? 0x10000007 : 0x10000006;
 if (fwd->listen_path != 
                        ((void *)0)
                            )
  lhost = fwd->listen_path;
 else if (fwd->listen_host == 
                             ((void *)0)
                                 )
  lhost = "";
 else if (*fwd->listen_host == '\0')
  lhost = "*";
 else
  lhost = fwd->listen_host;

 if (fwd->connect_path != 
                         ((void *)0)
                             )
  chost = fwd->connect_path;
 else if (fwd->connect_host == 
                              ((void *)0)
                                  )
  chost = "";
 else
  chost = fwd->connect_host;

 if ((m = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("mux.c", __func__, 1774, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 if ((r = sshbuf_put_u32(m, type)) != 0 ||
     (r = sshbuf_put_u32(m, muxclient_request_id)) != 0 ||
     (r = sshbuf_put_u32(m, ftype)) != 0 ||
     (r = sshbuf_put_cstring(m, lhost)) != 0 ||
     (r = sshbuf_put_u32(m, fwd->listen_port)) != 0 ||
     (r = sshbuf_put_cstring(m, chost)) != 0 ||
     (r = sshbuf_put_u32(m, fwd->connect_port)) != 0)
  sshfatal("mux.c", __func__, 1782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "request");

 if (mux_client_write_packet(fd, m) != 0)
  sshfatal("mux.c", __func__, 1785, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "write packet: %s", strerror(
 (*__errno_location ())
 ));

 sshbuf_reset(m);


 if (mux_client_read_packet(fd, m) != 0) {
  sshbuf_free(m);
  return -1;
 }

 if ((r = sshbuf_get_u32(m, &type)) != 0 ||
     (r = sshbuf_get_u32(m, &rid)) != 0)
  sshfatal("mux.c", __func__, 1797, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 if (rid != muxclient_request_id)
  sshfatal("mux.c", __func__, 1799, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "out of sequence reply: my id %u theirs %u", muxclient_request_id, rid)
                                ;

 switch (type) {
 case 0x80000001:
  break;
 case 0x80000007:
  if (cancel_flag)
   sshfatal("mux.c", __func__, 1807, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "got MUX_S_REMOTE_PORT for cancel");
  if ((r = sshbuf_get_u32(m, &fwd->allocated_port)) != 0)
   sshfatal("mux.c", __func__, 1809, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse port");
  sshlog("mux.c", __func__, 1810, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "Allocated port %u for remote forward to %s:%d", fwd->allocated_port, fwd->connect_host ? fwd->connect_host : "", fwd->connect_port)


                        ;
  if (muxclient_command == 5)
   fprintf(
          stdout
                , "%i\n", fwd->allocated_port);
  break;
 case 0x80000002:
  if ((r = sshbuf_get_cstring(m, &e, 
                                    ((void *)0)
                                        )) != 0)
   sshfatal("mux.c", __func__, 1819, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse error message");
  sshbuf_free(m);
  sshlog("mux.c", __func__, 1821, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Master refused forwarding request: %s", e);
  return -1;
 case 0x80000003:
  if ((r = sshbuf_get_cstring(m, &e, 
                                    ((void *)0)
                                        )) != 0)
   sshfatal("mux.c", __func__, 1825, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse error message");
  sshbuf_free(m);
  sshlog("mux.c", __func__, 1827, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "forwarding request failed: %s", e);
  return -1;
 default:
  sshfatal("mux.c", __func__, 1830, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "unexpected response from master 0x%08x", type);
 }
 sshbuf_free(m);

 muxclient_request_id++;
 return 0;
}

static int
mux_client_forwards(int fd, int cancel_flag)
{
 int i, ret = 0;

 sshlog("mux.c", __func__, 1843, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s forwardings: %d local, %d remote", cancel_flag ? "cancel" : "request", options.num_local_forwards, options.num_remote_forwards)

                                                             ;


 for (i = 0; i < options.num_local_forwards; i++) {
  if (mux_client_forward(fd, cancel_flag,
      options.local_forwards[i].connect_port == 0 ?
      3 : 1,
      options.local_forwards + i) != 0)
   ret = -1;
 }
 for (i = 0; i < options.num_remote_forwards; i++) {
  if (mux_client_forward(fd, cancel_flag, 2,
      options.remote_forwards + i) != 0)
   ret = -1;
 }
 return ret;
}

static int
mux_client_request_session(int fd)
{
 struct sshbuf *m;
 char *e;
 const char *term = 
                   ((void *)0)
                       ;
 u_int i, echar, rid, sid, esid, exitval, type, exitval_seen;
 extern char **environ;
 int r, rawmode;

 sshlog("mux.c", __func__, 1873, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "entering");

 if ((muxserver_pid = mux_client_request_alive(fd)) == 0) {
  sshlog("mux.c", __func__, 1876, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "master alive request failed");
  return -1;
 }

 ssh_signal(
           13
                  , 
                    ((__sighandler_t) 1)
                           );

 if (options.stdin_null && stdfd_devnull(1, 0, 0) == -1)
  sshfatal("mux.c", __func__, 1883, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "stdfd_devnull failed");

 if ((term = lookup_env_in_list("TERM", options.setenv,
     options.num_setenv)) == 
                            ((void *)0) 
                                 || *term == '\0')
  term = getenv("TERM");

 echar = 0xffffffff;
 if (options.escape_char != -2)
     echar = (u_int)options.escape_char;

 if ((m = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("mux.c", __func__, 1894, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 if ((r = sshbuf_put_u32(m, 0x10000002)) != 0 ||
     (r = sshbuf_put_u32(m, muxclient_request_id)) != 0 ||
     (r = sshbuf_put_string(m, 
                              ((void *)0)
                                  , 0)) != 0 ||
     (r = sshbuf_put_u32(m, tty_flag)) != 0 ||
     (r = sshbuf_put_u32(m, options.forward_x11)) != 0 ||
     (r = sshbuf_put_u32(m, options.forward_agent)) != 0 ||
     (r = sshbuf_put_u32(m, options.session_type == 1)) != 0 ||
     (r = sshbuf_put_u32(m, echar)) != 0 ||
     (r = sshbuf_put_cstring(m, term == 
                                       ((void *)0) 
                                            ? "" : term)) != 0 ||
     (r = sshbuf_put_stringb(m, command)) != 0)
  sshfatal("mux.c", __func__, 1905, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "request");


 if (options.num_send_env > 0 && environ != 
                                           ((void *)0)
                                               ) {
  for (i = 0; environ[i] != 
                           ((void *)0)
                               ; i++) {
   if (!env_permitted(environ[i]))
    continue;
   if ((r = sshbuf_put_cstring(m, environ[i])) != 0)
    sshfatal("mux.c", __func__, 1913, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "request sendenv");
  }
 }
 for (i = 0; i < options.num_setenv; i++) {
  if ((r = sshbuf_put_cstring(m, options.setenv[i])) != 0)
   sshfatal("mux.c", __func__, 1918, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "request setenv");
 }

 if (mux_client_write_packet(fd, m) != 0)
  sshfatal("mux.c", __func__, 1922, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "write packet: %s", strerror(
 (*__errno_location ())
 ));


 if (mm_send_fd(fd, 
                   0
                               ) == -1 ||
     mm_send_fd(fd, 
                   1
                                ) == -1 ||
     mm_send_fd(fd, 
                   2
                                ) == -1)
  sshfatal("mux.c", __func__, 1928, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "send fds failed");

 sshlog("mux.c", __func__, 1930, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "session request sent");


 sshbuf_reset(m);
 if (mux_client_read_packet(fd, m) != 0) {
  sshlog("mux.c", __func__, 1935, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "read from master failed: %s", strerror(
 (*__errno_location ())
 ));
  sshbuf_free(m);
  return -1;
 }

 if ((r = sshbuf_get_u32(m, &type)) != 0 ||
     (r = sshbuf_get_u32(m, &rid)) != 0)
  sshfatal("mux.c", __func__, 1942, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 if (rid != muxclient_request_id)
  sshfatal("mux.c", __func__, 1944, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "out of sequence reply: my id %u theirs %u", muxclient_request_id, rid)
                                ;

 switch (type) {
 case 0x80000006:
  if ((r = sshbuf_get_u32(m, &sid)) != 0)
   sshfatal("mux.c", __func__, 1950, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse session ID");
  sshlog("mux.c", __func__, 1951, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "master session id: %u", sid);
  break;
 case 0x80000002:
  if ((r = sshbuf_get_cstring(m, &e, 
                                    ((void *)0)
                                        )) != 0)
   sshfatal("mux.c", __func__, 1955, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse error message");
  sshlog("mux.c", __func__, 1956, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Master refused session request: %s", e);
  sshbuf_free(m);
  return -1;
 case 0x80000003:
  if ((r = sshbuf_get_cstring(m, &e, 
                                    ((void *)0)
                                        )) != 0)
   sshfatal("mux.c", __func__, 1961, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse error message");
  sshlog("mux.c", __func__, 1962, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "session request failed: %s", e);
  sshbuf_free(m);
  return -1;
 default:
  sshbuf_free(m);
  sshlog("mux.c", __func__, 1967, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unexpected response from master 0x%08x", type);
  return -1;
 }
 muxclient_request_id++;

 if (pledge("stdio proc tty", 
                             ((void *)0)
                                 ) == -1)
  sshfatal("mux.c", __func__, 1973, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "pledge(): %s", strerror(
 (*__errno_location ())
 ));
 platform_pledge_mux();

 ssh_signal(
           1
                 , control_client_sighandler);
 ssh_signal(
           2
                 , control_client_sighandler);
 ssh_signal(
           15
                  , control_client_sighandler);
 ssh_signal(
           28
                   , control_client_sigrelay);

 rawmode = tty_flag;
 if (tty_flag)
  enter_raw_mode(options.request_tty == 3);
 for (exitval = 255, exitval_seen = 0;;) {
  sshbuf_reset(m);
  if (mux_client_read_packet(fd, m) != 0)
   break;
  if ((r = sshbuf_get_u32(m, &type)) != 0)
   sshfatal("mux.c", __func__, 1997, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse type");
  switch (type) {
  case 0x80000008:
   if ((r = sshbuf_get_u32(m, &esid)) != 0)
    sshfatal("mux.c", __func__, 2001, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse session ID");
   if (esid != sid)
    sshfatal("mux.c", __func__, 2003, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "tty alloc fail on unknown session: " "my id %u theirs %u", sid, esid)
                                        ;
   leave_raw_mode(options.request_tty ==
       3);
   rawmode = 0;
   continue;
  case 0x80000004:
   if ((r = sshbuf_get_u32(m, &esid)) != 0)
    sshfatal("mux.c", __func__, 2011, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse session ID");
   if (esid != sid)
    sshfatal("mux.c", __func__, 2013, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "exit on unknown session: " "my id %u theirs %u", sid, esid)
                                        ;
   if (exitval_seen)
    sshfatal("mux.c", __func__, 2016, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "exitval sent twice");
   if ((r = sshbuf_get_u32(m, &exitval)) != 0)
    sshfatal("mux.c", __func__, 2018, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse exitval");
   exitval_seen = 1;
   continue;
  default:
   if ((r = sshbuf_get_cstring(m, &e, 
                                     ((void *)0)
                                         )) != 0)
    sshfatal("mux.c", __func__, 2023, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse error message");
   sshfatal("mux.c", __func__, 2024, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "master returned error: %s", e);
  }
 }

 close(fd);
 if (rawmode)
  leave_raw_mode(options.request_tty == 3);

 if (muxclient_terminate) {
  sshlog("mux.c", __func__, 2033, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "Exiting on signal: %s", strsignal(muxclient_terminate));
  exitval = 255;
 } else if (!exitval_seen) {
  sshlog("mux.c", __func__, 2036, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "Control master terminated unexpectedly");
  exitval = 255;
 } else
  sshlog("mux.c", __func__, 2039, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "Received exit status from master %d", exitval);

 if (tty_flag && options.log_level >= SYSLOG_LEVEL_INFO)
  fprintf(
         stderr
               , "Shared connection to %s closed.\r\n", host);

 exit(exitval);
}

static int
mux_client_proxy(int fd)
{
 struct sshbuf *m;
 char *e;
 u_int type, rid;
 int r;

 if ((m = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("mux.c", __func__, 2056, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 if ((r = sshbuf_put_u32(m, 0x1000000f)) != 0 ||
     (r = sshbuf_put_u32(m, muxclient_request_id)) != 0)
  sshfatal("mux.c", __func__, 2059, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "request");
 if (mux_client_write_packet(fd, m) != 0)
  sshfatal("mux.c", __func__, 2061, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "write packet: %s", strerror(
 (*__errno_location ())
 ));

 sshbuf_reset(m);


 if (mux_client_read_packet(fd, m) != 0) {
  sshbuf_free(m);
  return 0;
 }
 if ((r = sshbuf_get_u32(m, &type)) != 0 ||
     (r = sshbuf_get_u32(m, &rid)) != 0)
  sshfatal("mux.c", __func__, 2072, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 if (rid != muxclient_request_id)
  sshfatal("mux.c", __func__, 2074, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "out of sequence reply: my id %u theirs %u", muxclient_request_id, rid)
                                ;
 if (type != 0x8000000f) {
  if ((r = sshbuf_get_cstring(m, &e, 
                                    ((void *)0)
                                        )) != 0)
   sshfatal("mux.c", __func__, 2078, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse error message");
  sshfatal("mux.c", __func__, 2079, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "master returned error: %s", e);
 }
 sshbuf_free(m);

 sshlog("mux.c", __func__, 2083, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "done");
 muxclient_request_id++;
 return 0;
}

static int
mux_client_request_stdio_fwd(int fd)
{
 struct sshbuf *m;
 char *e;
 u_int type, rid, sid;
 int r;

 sshlog("mux.c", __func__, 2096, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "entering");

 if ((muxserver_pid = mux_client_request_alive(fd)) == 0) {
  sshlog("mux.c", __func__, 2099, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "master alive request failed");
  return -1;
 }

 ssh_signal(
           13
                  , 
                    ((__sighandler_t) 1)
                           );

 if (options.stdin_null && stdfd_devnull(1, 0, 0) == -1)
  sshfatal("mux.c", __func__, 2106, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "stdfd_devnull failed");

 if ((m = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("mux.c", __func__, 2109, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 if ((r = sshbuf_put_u32(m, 0x10000008)) != 0 ||
     (r = sshbuf_put_u32(m, muxclient_request_id)) != 0 ||
     (r = sshbuf_put_string(m, 
                              ((void *)0)
                                  , 0)) != 0 ||
     (r = sshbuf_put_cstring(m, options.stdio_forward_host)) != 0 ||
     (r = sshbuf_put_u32(m, options.stdio_forward_port)) != 0)
  sshfatal("mux.c", __func__, 2115, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "request");

 if (mux_client_write_packet(fd, m) != 0)
  sshfatal("mux.c", __func__, 2118, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "write packet: %s", strerror(
 (*__errno_location ())
 ));


 if (mm_send_fd(fd, 
                   0
                               ) == -1 ||
     mm_send_fd(fd, 
                   1
                                ) == -1)
  sshfatal("mux.c", __func__, 2123, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "send fds failed");

 if (pledge("stdio proc tty", 
                             ((void *)0)
                                 ) == -1)
  sshfatal("mux.c", __func__, 2126, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "pledge(): %s", strerror(
 (*__errno_location ())
 ));
 platform_pledge_mux();

 sshlog("mux.c", __func__, 2129, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "stdio forward request sent");


 sshbuf_reset(m);

 if (mux_client_read_packet(fd, m) != 0) {
  sshlog("mux.c", __func__, 2135, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "read from master failed: %s", strerror(
 (*__errno_location ())
 ));
  sshbuf_free(m);
  return -1;
 }

 if ((r = sshbuf_get_u32(m, &type)) != 0 ||
     (r = sshbuf_get_u32(m, &rid)) != 0)
  sshfatal("mux.c", __func__, 2142, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 if (rid != muxclient_request_id)
  sshfatal("mux.c", __func__, 2144, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "out of sequence reply: my id %u theirs %u", muxclient_request_id, rid)
                                ;
 switch (type) {
 case 0x80000006:
  if ((r = sshbuf_get_u32(m, &sid)) != 0)
   sshfatal("mux.c", __func__, 2149, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse session ID");
  sshlog("mux.c", __func__, 2150, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "master session id: %u", sid);
  break;
 case 0x80000002:
  if ((r = sshbuf_get_cstring(m, &e, 
                                    ((void *)0)
                                        )) != 0)
   sshfatal("mux.c", __func__, 2154, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse error message");
  sshbuf_free(m);
  sshfatal("mux.c", __func__, 2156, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Master refused stdio forwarding request: %s", e);
 case 0x80000003:
  if ((r = sshbuf_get_cstring(m, &e, 
                                    ((void *)0)
                                        )) != 0)
   sshfatal("mux.c", __func__, 2159, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse error message");
  sshbuf_free(m);
  sshfatal("mux.c", __func__, 2161, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Stdio forwarding request failed: %s", e);
 default:
  sshbuf_free(m);
  sshlog("mux.c", __func__, 2164, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unexpected response from master 0x%08x", type);
  return -1;
 }
 muxclient_request_id++;

 ssh_signal(
           1
                 , control_client_sighandler);
 ssh_signal(
           2
                 , control_client_sighandler);
 ssh_signal(
           15
                  , control_client_sighandler);
 ssh_signal(
           28
                   , control_client_sigrelay);




 sshbuf_reset(m);
 if (mux_client_read_packet(fd, m) != 0) {
  if (
     (*__errno_location ()) 
           == 
              32 
                    ||
      (
      (*__errno_location ()) 
            == 
               4 
                     && muxclient_terminate != 0))
   return 0;
  sshfatal("mux.c", __func__, 2182, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "mux_client_read_packet: %s", strerror(
 (*__errno_location ())
 ));
 }
 sshfatal("mux.c", __func__, 2184, 1, SYSLOG_LEVEL_FATAL, 
((void *)0)
, "master returned unexpected message %u", type);
}

static void
mux_client_request_stop_listening(int fd)
{
 struct sshbuf *m;
 char *e;
 u_int type, rid;
 int r;

 sshlog("mux.c", __func__, 2195, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "entering");

 if ((m = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("mux.c", __func__, 2198, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 if ((r = sshbuf_put_u32(m, 0x10000009)) != 0 ||
     (r = sshbuf_put_u32(m, muxclient_request_id)) != 0)
  sshfatal("mux.c", __func__, 2201, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "request");

 if (mux_client_write_packet(fd, m) != 0)
  sshfatal("mux.c", __func__, 2204, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "write packet: %s", strerror(
 (*__errno_location ())
 ));

 sshbuf_reset(m);


 if (mux_client_read_packet(fd, m) != 0)
  sshfatal("mux.c", __func__, 2210, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "read from master failed: %s", strerror(
 (*__errno_location ())
 ));

 if ((r = sshbuf_get_u32(m, &type)) != 0 ||
     (r = sshbuf_get_u32(m, &rid)) != 0)
  sshfatal("mux.c", __func__, 2214, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 if (rid != muxclient_request_id)
  sshfatal("mux.c", __func__, 2216, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "out of sequence reply: my id %u theirs %u", muxclient_request_id, rid)
                                ;

 switch (type) {
 case 0x80000001:
  break;
 case 0x80000002:
  if ((r = sshbuf_get_cstring(m, &e, 
                                    ((void *)0)
                                        )) != 0)
   sshfatal("mux.c", __func__, 2224, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse error message");
  sshfatal("mux.c", __func__, 2225, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Master refused stop listening request: %s", e);
 case 0x80000003:
  if ((r = sshbuf_get_cstring(m, &e, 
                                    ((void *)0)
                                        )) != 0)
   sshfatal("mux.c", __func__, 2228, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse error message");
  sshfatal("mux.c", __func__, 2229, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "stop listening request failed: %s", e);
 default:
  sshfatal("mux.c", __func__, 2231, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "unexpected response from master 0x%08x", type);
 }
 sshbuf_free(m);
 muxclient_request_id++;
}


int
muxclient(const char *path)
{
 struct sockaddr_un addr;
 int sock;
 u_int pid;

 if (muxclient_command == 0) {
  if (options.stdio_forward_host != 
                                   ((void *)0)
                                       )
   muxclient_command = 4;
  else
   muxclient_command = 1;
 }

 switch (options.control_master) {
 case 2:
 case 4:
  sshlog("mux.c", __func__, 2255, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "auto-mux: Trying existing master");

 case 0:
  break;
 default:
  return -1;
 }

 memset(&addr, '\0', sizeof(addr));
 addr.sun_family = 
                  1
                         ;

 if (strlcpy(addr.sun_path, path,
     sizeof(addr.sun_path)) >= sizeof(addr.sun_path))
  sshfatal("mux.c", __func__, 2268, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ControlPath too long ('%s' >= %u bytes)", path, (unsigned int)sizeof(addr.sun_path))
                                          ;

 if ((sock = socket(
                   1
                          , 
                            SOCK_STREAM
                                       , 0)) == -1)
  sshfatal("mux.c", __func__, 2272, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "socket(): %s", strerror(
 (*__errno_location ())
 ));

 if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
  switch (muxclient_command) {
  case 1:
  case 4:
   break;
  default:
   sshfatal("mux.c", __func__, 2280, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Control socket connect(%.100s): %s", path, strerror(
  (*__errno_location ())
  ))
                       ;
  }
  if (
     (*__errno_location ()) 
           == 
              111 
                           &&
      options.control_master != 0) {
   sshlog("mux.c", __func__, 2285, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Stale control socket %.100s, unlinking", path);
   unlink(path);
  } else if (
            (*__errno_location ()) 
                  == 
                     2
                           ) {
   sshlog("mux.c", __func__, 2288, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Control socket \"%.100s\" does not exist", path);
  } else {
   sshlog("mux.c", __func__, 2290, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Control socket connect(%.100s): %s", path, strerror(
  (*__errno_location ())
  ))
                       ;
  }
  close(sock);
  return -1;
 }
 set_nonblock(sock);

 if (mux_client_hello_exchange(sock) != 0) {
  sshlog("mux.c", __func__, 2299, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "master hello exchange failed");
  close(sock);
  return -1;
 }

 switch (muxclient_command) {
 case 2:
  if ((pid = mux_client_request_alive(sock)) == 0)
   sshfatal("mux.c", __func__, 2307, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "master alive check failed");
  fprintf(
         stderr
               , "Master running (pid=%u)\r\n", pid);
  exit(0);
 case 3:
  mux_client_request_terminate(sock);
  if (options.log_level != SYSLOG_LEVEL_QUIET)
   fprintf(
          stderr
                , "Exit request sent.\r\n");
  exit(0);
 case 5:
  if (mux_client_forwards(sock, 0) != 0)
   sshfatal("mux.c", __func__, 2317, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "master forward request failed");
  exit(0);
 case 1:
  if (mux_client_forwards(sock, 0) != 0) {
   sshlog("mux.c", __func__, 2321, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "master forward request failed");
   return -1;
  }
  mux_client_request_session(sock);
  return -1;
 case 4:
  mux_client_request_stdio_fwd(sock);
  exit(0);
 case 6:
  mux_client_request_stop_listening(sock);
  if (options.log_level != SYSLOG_LEVEL_QUIET)
   fprintf(
          stderr
                , "Stop listening request sent.\r\n");
  exit(0);
 case 7:
  if (mux_client_forwards(sock, 1) != 0)
   sshlog("mux.c", __func__, 2336, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "master cancel forward request failed");
  exit(0);
 case 8:
  mux_client_proxy(sock);
  return (sock);
 default:
  sshfatal("mux.c", __func__, 2342, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "unrecognised muxclient_command %d", muxclient_command);
 }
}
