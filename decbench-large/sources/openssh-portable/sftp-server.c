











































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
void temporarily_use_uid(struct passwd *);
void restore_uid(void);
void permanently_set_uid(struct passwd *);

struct passwd;

int sftp_server_main(int, char **, struct passwd *);
void sftp_server_cleanup_exit(int) __attribute__((noreturn));
struct sshbuf;
typedef struct Attrib Attrib;


struct Attrib {
 u_int32_t flags;
 u_int64_t size;
 u_int32_t uid;
 u_int32_t gid;
 u_int32_t perm;
 u_int32_t atime;
 u_int32_t mtime;
};

void attrib_clear(Attrib *);
void stat_to_attrib(const struct stat *, Attrib *);
void attrib_to_stat(const Attrib *, struct stat *);
int decode_attrib(struct sshbuf *, Attrib *);
int encode_attrib(struct sshbuf *, const Attrib *);
char *ls_file(const char *, const struct stat *, int, int,
    const char *, const char *);

const char *fx2txt(int);

char *sftp_realpath(const char *, char *);





static LogLevel log_level = SYSLOG_LEVEL_ERROR;


static struct passwd *pw = 
                          ((void *)0)
                              ;
static char *client_addr = 
                          ((void *)0)
                              ;


struct sshbuf *iqueue;
struct sshbuf *oqueue;


static u_int version;


static int init_done;


static int readonly;


static char *request_allowlist, *request_denylist;


typedef struct Stat Stat;

struct Stat {
 char *name;
 char *long_name;
 Attrib attrib;
};


static void process_open(u_int32_t id);
static void process_close(u_int32_t id);
static void process_read(u_int32_t id);
static void process_write(u_int32_t id);
static void process_stat(u_int32_t id);
static void process_lstat(u_int32_t id);
static void process_fstat(u_int32_t id);
static void process_setstat(u_int32_t id);
static void process_fsetstat(u_int32_t id);
static void process_opendir(u_int32_t id);
static void process_readdir(u_int32_t id);
static void process_remove(u_int32_t id);
static void process_mkdir(u_int32_t id);
static void process_rmdir(u_int32_t id);
static void process_realpath(u_int32_t id);
static void process_rename(u_int32_t id);
static void process_readlink(u_int32_t id);
static void process_symlink(u_int32_t id);
static void process_extended_posix_rename(u_int32_t id);
static void process_extended_statvfs(u_int32_t id);
static void process_extended_fstatvfs(u_int32_t id);
static void process_extended_hardlink(u_int32_t id);
static void process_extended_fsync(u_int32_t id);
static void process_extended_lsetstat(u_int32_t id);
static void process_extended_limits(u_int32_t id);
static void process_extended_expand(u_int32_t id);
static void process_extended_copy_data(u_int32_t id);
static void process_extended_home_directory(u_int32_t id);
static void process_extended_get_users_groups_by_id(u_int32_t id);
static void process_extended(u_int32_t id);

struct sftp_handler {
 const char *name;
 const char *ext_name;
 u_int type;
 void (*handler)(u_int32_t);
 int does_write;
};

static const struct sftp_handler handlers[] = {

 { "open", 
          ((void *)0)
              , 3, process_open, 0 },
 { "close", 
           ((void *)0)
               , 4, process_close, 0 },
 { "read", 
          ((void *)0)
              , 5, process_read, 0 },
 { "write", 
           ((void *)0)
               , 6, process_write, 1 },
 { "lstat", 
           ((void *)0)
               , 7, process_lstat, 0 },
 { "fstat", 
           ((void *)0)
               , 8, process_fstat, 0 },
 { "setstat", 
             ((void *)0)
                 , 9, process_setstat, 1 },
 { "fsetstat", 
              ((void *)0)
                  , 10, process_fsetstat, 1 },
 { "opendir", 
             ((void *)0)
                 , 11, process_opendir, 0 },
 { "readdir", 
             ((void *)0)
                 , 12, process_readdir, 0 },
 { "remove", 
            ((void *)0)
                , 13, process_remove, 1 },
 { "mkdir", 
           ((void *)0)
               , 14, process_mkdir, 1 },
 { "rmdir", 
           ((void *)0)
               , 15, process_rmdir, 1 },
 { "realpath", 
              ((void *)0)
                  , 16, process_realpath, 0 },
 { "stat", 
          ((void *)0)
              , 17, process_stat, 0 },
 { "rename", 
            ((void *)0)
                , 18, process_rename, 1 },
 { "readlink", 
              ((void *)0)
                  , 19, process_readlink, 0 },
 { "symlink", 
             ((void *)0)
                 , 20, process_symlink, 1 },
 { 
  ((void *)0)
      , 
        ((void *)0)
            , 0, 
                 ((void *)0)
                     , 0 }
};


static const struct sftp_handler extended_handlers[] = {
 { "posix-rename", "posix-rename@openssh.com", 0,
     process_extended_posix_rename, 1 },
 { "statvfs", "statvfs@openssh.com", 0, process_extended_statvfs, 0 },
 { "fstatvfs", "fstatvfs@openssh.com", 0, process_extended_fstatvfs, 0 },
 { "hardlink", "hardlink@openssh.com", 0, process_extended_hardlink, 1 },
 { "fsync", "fsync@openssh.com", 0, process_extended_fsync, 1 },
 { "lsetstat", "lsetstat@openssh.com", 0, process_extended_lsetstat, 1 },
 { "limits", "limits@openssh.com", 0, process_extended_limits, 0 },
 { "expand-path", "expand-path@openssh.com", 0,
     process_extended_expand, 0 },
 { "copy-data", "copy-data", 0, process_extended_copy_data, 1 },
 { "home-directory", "home-directory", 0,
     process_extended_home_directory, 0 },
 { "users-groups-by-id", "users-groups-by-id@openssh.com", 0,
     process_extended_get_users_groups_by_id, 0 },
 { 
  ((void *)0)
      , 
        ((void *)0)
            , 0, 
                 ((void *)0)
                     , 0 }
};

static const struct sftp_handler *
extended_handler_byname(const char *name)
{
 int i;

 for (i = 0; extended_handlers[i].handler != 
                                            ((void *)0)
                                                ; i++) {
  if (strcmp(name, extended_handlers[i].ext_name) == 0)
   return &extended_handlers[i];
 }
 return 
       ((void *)0)
           ;
}

static int
request_permitted(const struct sftp_handler *h)
{
 char *result;

 if (readonly && h->does_write) {
  sshlog("sftp-server.c", __func__, 198, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "Refusing %s request in read-only mode", h->name);
  return 0;
 }
 if (request_denylist != 
                        ((void *)0) 
                             &&
     ((result = match_list(h->name, request_denylist, 
                                                     ((void *)0)
                                                         ))) != 
                                                                ((void *)0)
                                                                    ) {
  free(result);
  sshlog("sftp-server.c", __func__, 204, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "Refusing denylisted %s request", h->name);
  return 0;
 }
 if (request_allowlist != 
                         ((void *)0) 
                              &&
     ((result = match_list(h->name, request_allowlist, 
                                                      ((void *)0)
                                                          ))) != 
                                                                 ((void *)0)
                                                                     ) {
  free(result);
  sshlog("sftp-server.c", __func__, 210, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "Permitting allowlisted %s request", h->name);
  return 1;
 }
 if (request_allowlist != 
                         ((void *)0)
                             ) {
  sshlog("sftp-server.c", __func__, 214, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "Refusing non-allowlisted %s request", h->name);
  return 0;
 }
 return 1;
}

static int
errno_to_portable(int unixerrno)
{
 int ret = 0;

 switch (unixerrno) {
 case 0:
  ret = 0;
  break;
 case 
     2
           :
 case 
     20
            :
 case 
     9
          :
 case 
     40
          :
  ret = 2;
  break;
 case 
     1
          :
 case 
     13
           :
 case 
     14
           :
  ret = 3;
  break;
 case 
     36
                 :
 case 
     22
           :
  ret = 5;
  break;
 case 
     38
           :
  ret = 8;
  break;
 default:
  ret = 4;
  break;
 }
 return ret;
}

static int
flags_from_portable(int pflags)
{
 int flags = 0;

 if ((pflags & 0x00000001) &&
     (pflags & 0x00000002)) {
  flags = 
         02
               ;
 } else if (pflags & 0x00000001) {
  flags = 
         00
                 ;
 } else if (pflags & 0x00000002) {
  flags = 
         01
                 ;
 }
 if (pflags & 0x00000004)
  flags |= 
          02000
                  ;
 if (pflags & 0x00000008)
  flags |= 
          0100
                 ;
 if (pflags & 0x00000010)
  flags |= 
          01000
                 ;
 if (pflags & 0x00000020)
  flags |= 
          0200
                ;
 return flags;
}

static const char *
string_from_portable(int pflags)
{
 static char ret[128];

 *ret = '\0';







 if (pflags & 0x00000001)
  { if (*ret != '\0') strlcat(ret, ",", sizeof(ret)); strlcat(ret, "READ", sizeof(ret)); }
 if (pflags & 0x00000002)
  { if (*ret != '\0') strlcat(ret, ",", sizeof(ret)); strlcat(ret, "WRITE", sizeof(ret)); }
 if (pflags & 0x00000004)
  { if (*ret != '\0') strlcat(ret, ",", sizeof(ret)); strlcat(ret, "APPEND", sizeof(ret)); }
 if (pflags & 0x00000008)
  { if (*ret != '\0') strlcat(ret, ",", sizeof(ret)); strlcat(ret, "CREATE", sizeof(ret)); }
 if (pflags & 0x00000010)
  { if (*ret != '\0') strlcat(ret, ",", sizeof(ret)); strlcat(ret, "TRUNCATE", sizeof(ret)); }
 if (pflags & 0x00000020)
  { if (*ret != '\0') strlcat(ret, ",", sizeof(ret)); strlcat(ret, "EXCL", sizeof(ret)); }

 return ret;
}



typedef struct Handle Handle;
struct Handle {
 int use;
 DIR *dirp;
 int fd;
 int flags;
 char *name;
 u_int64_t bytes_read, bytes_write;
 int next_unused;
};

enum {
 HANDLE_UNUSED,
 HANDLE_DIR,
 HANDLE_FILE
};

static Handle *handles = 
                        ((void *)0)
                            ;
static u_int num_handles = 0;
static int first_unused_handle = -1;

static void handle_unused(int i)
{
 handles[i].use = HANDLE_UNUSED;
 handles[i].next_unused = first_unused_handle;
 first_unused_handle = i;
}

static int
handle_new(int use, const char *name, int fd, int flags, DIR *dirp)
{
 int i;

 if (first_unused_handle == -1) {
  if (num_handles + 1 <= num_handles)
   return -1;
  num_handles++;
  handles = xreallocarray(handles, num_handles, sizeof(Handle));
  handle_unused(num_handles - 1);
 }

 i = first_unused_handle;
 first_unused_handle = handles[i].next_unused;

 handles[i].use = use;
 handles[i].dirp = dirp;
 handles[i].fd = fd;
 handles[i].flags = flags;
 handles[i].name = xstrdup(name);
 handles[i].bytes_read = handles[i].bytes_write = 0;

 return i;
}

static int
handle_is_ok(int i, int type)
{
 return i >= 0 && (u_int)i < num_handles && handles[i].use == type;
}

static int
handle_to_string(int handle, u_char **stringp, int *hlenp)
{
 if (stringp == 
               ((void *)0) 
                    || hlenp == 
                                ((void *)0)
                                    )
  return -1;
 *stringp = xmalloc(sizeof(int32_t));
 put_u32(*stringp, handle);
 *hlenp = sizeof(int32_t);
 return 0;
}

static int
handle_from_string(const u_char *handle, u_int hlen)
{
 int val;

 if (hlen != sizeof(int32_t))
  return -1;
 val = get_u32(handle);
 if (handle_is_ok(val, HANDLE_FILE) ||
     handle_is_ok(val, HANDLE_DIR))
  return val;
 return -1;
}

static char *
handle_to_name(int handle)
{
 if (handle_is_ok(handle, HANDLE_DIR)||
     handle_is_ok(handle, HANDLE_FILE))
  return handles[handle].name;
 return 
       ((void *)0)
           ;
}

static DIR *
handle_to_dir(int handle)
{
 if (handle_is_ok(handle, HANDLE_DIR))
  return handles[handle].dirp;
 return 
       ((void *)0)
           ;
}

static int
handle_to_fd(int handle)
{
 if (handle_is_ok(handle, HANDLE_FILE))
  return handles[handle].fd;
 return -1;
}

static int
handle_to_flags(int handle)
{
 if (handle_is_ok(handle, HANDLE_FILE))
  return handles[handle].flags;
 return 0;
}

static void
handle_update_read(int handle, ssize_t bytes)
{
 if (handle_is_ok(handle, HANDLE_FILE) && bytes > 0)
  handles[handle].bytes_read += bytes;
}

static void
handle_update_write(int handle, ssize_t bytes)
{
 if (handle_is_ok(handle, HANDLE_FILE) && bytes > 0)
  handles[handle].bytes_write += bytes;
}

static u_int64_t
handle_bytes_read(int handle)
{
 if (handle_is_ok(handle, HANDLE_FILE))
  return (handles[handle].bytes_read);
 return 0;
}

static u_int64_t
handle_bytes_write(int handle)
{
 if (handle_is_ok(handle, HANDLE_FILE))
  return (handles[handle].bytes_write);
 return 0;
}

static int
handle_close(int handle)
{
 int ret = -1;

 if (handle_is_ok(handle, HANDLE_FILE)) {
  ret = close(handles[handle].fd);
  free(handles[handle].name);
  handle_unused(handle);
 } else if (handle_is_ok(handle, HANDLE_DIR)) {
  ret = closedir(handles[handle].dirp);
  free(handles[handle].name);
  handle_unused(handle);
 } else {
  
 (*__errno_location ()) 
       = 
         2
               ;
 }
 return ret;
}

static void
handle_log_close(int handle, char *emsg)
{
 if (handle_is_ok(handle, HANDLE_FILE)) {
  sshlog("sftp-server.c", __func__, 480, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "%s%sclose \"%s\" bytes read %llu written %llu", emsg == 
 ((void *)0) 
 ? "" : emsg, emsg == 
 ((void *)0) 
 ? "" : " ", handle_to_name(handle), (unsigned long long)handle_bytes_read(handle), (unsigned long long)handle_bytes_write(handle))



                                                     ;
 } else {
  sshlog("sftp-server.c", __func__, 486, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "%s%sclosedir \"%s\"", emsg == 
 ((void *)0) 
 ? "" : emsg, emsg == 
 ((void *)0) 
 ? "" : " ", handle_to_name(handle))

                             ;
 }
}

static void
handle_log_exit(void)
{
 u_int i;

 for (i = 0; i < num_handles; i++)
  if (handles[i].use != HANDLE_UNUSED)
   handle_log_close(i, "forced");
}

static int
get_handle(struct sshbuf *queue, int *hp)
{
 u_char *handle;
 int r;
 size_t hlen;

 *hp = -1;
 if ((r = sshbuf_get_string(queue, &handle, &hlen)) != 0)
  return r;
 if (hlen < 256)
  *hp = handle_from_string(handle, hlen);
 free(handle);
 return 0;
}



static void
send_msg(struct sshbuf *m)
{
 int r;

 if ((r = sshbuf_put_stringb(oqueue, m)) != 0)
  sshfatal("sftp-server.c", __func__, 526, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "enqueue");
 sshbuf_reset(m);
}

static const char *
status_to_message(u_int32_t status)
{
 static const char * const status_messages[] = {
  "Success",
  "End of file",
  "No such file",
  "Permission denied",
  "Failure",
  "Bad message",
  "No connection",
  "Connection lost",
  "Operation unsupported",
  "Unknown error"
 };
 return (status_messages[(((status) < (8)) ? (status) : (8))]);
}

static void
send_status_errmsg(u_int32_t id, u_int32_t status, const char *errmsg)
{
 struct sshbuf *msg;
 int r;

 sshlog("sftp-server.c", __func__, 554, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "request %u: sent status %u", id, status);
 if (log_level > SYSLOG_LEVEL_VERBOSE ||
     (status != 0 && status != 1))
  sshlog("sftp-server.c", __func__, 557, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "sent status %s", status_to_message(status));
 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-server.c", __func__, 559, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, 101)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_u32(msg, status)) != 0)
  sshfatal("sftp-server.c", __func__, 563, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 if (version >= 3) {
  if ((r = sshbuf_put_cstring(msg, errmsg == 
                                            ((void *)0) 
                                                 ?
      status_to_message(status) : errmsg)) != 0 ||
      (r = sshbuf_put_cstring(msg, "")) != 0)
   sshfatal("sftp-server.c", __func__, 568, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose message");
 }
 send_msg(msg);
 sshbuf_free(msg);
}

static void
send_status(u_int32_t id, u_int32_t status)
{
 send_status_errmsg(id, status, 
                               ((void *)0)
                                   );
}

static void
send_data_or_handle(char type, u_int32_t id, const u_char *data, int dlen)
{
 struct sshbuf *msg;
 int r;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-server.c", __func__, 587, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, type)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_string(msg, data, dlen)) != 0)
  sshfatal("sftp-server.c", __func__, 591, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(msg);
 sshbuf_free(msg);
}

static void
send_data(u_int32_t id, const u_char *data, int dlen)
{
 sshlog("sftp-server.c", __func__, 599, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "request %u: sent data len %d", id, dlen);
 send_data_or_handle(103, id, data, dlen);
}

static void
send_handle(u_int32_t id, int handle)
{
 u_char *string;
 int hlen;

 handle_to_string(handle, &string, &hlen);
 sshlog("sftp-server.c", __func__, 610, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "request %u: sent handle handle %d", id, handle);
 send_data_or_handle(102, id, string, hlen);
 free(string);
}

static void
send_names(u_int32_t id, int count, const Stat *stats)
{
 struct sshbuf *msg;
 int i, r;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-server.c", __func__, 622, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, 104)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_u32(msg, count)) != 0)
  sshfatal("sftp-server.c", __func__, 626, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 sshlog("sftp-server.c", __func__, 627, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "request %u: sent names count %d", id, count);
 for (i = 0; i < count; i++) {
  if ((r = sshbuf_put_cstring(msg, stats[i].name)) != 0 ||
      (r = sshbuf_put_cstring(msg, stats[i].long_name)) != 0 ||
      (r = encode_attrib(msg, &stats[i].attrib)) != 0)
   sshfatal("sftp-server.c", __func__, 632, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose filenames/attrib");
 }
 send_msg(msg);
 sshbuf_free(msg);
}

static void
send_attrib(u_int32_t id, const Attrib *a)
{
 struct sshbuf *msg;
 int r;

 sshlog("sftp-server.c", __func__, 644, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "request %u: sent attrib have 0x%x", id, a->flags);
 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-server.c", __func__, 646, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, 105)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = encode_attrib(msg, a)) != 0)
  sshfatal("sftp-server.c", __func__, 650, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(msg);
 sshbuf_free(msg);
}

static void
send_statvfs(u_int32_t id, struct statvfs *st)
{
 struct sshbuf *msg;
 u_int64_t flag;
 int r;

 flag = (st->f_flag & 
                     ST_RDONLY
                              ) ? 0x00000001 : 0;
 flag |= (st->f_flag & 
                      ST_NOSUID
                               ) ? 0x00000002 : 0;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-server.c", __func__, 666, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, 201)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_u64(msg, st->f_bsize)) != 0 ||
     (r = sshbuf_put_u64(msg, st->f_frsize)) != 0 ||
     (r = sshbuf_put_u64(msg, st->f_blocks)) != 0 ||
     (r = sshbuf_put_u64(msg, st->f_bfree)) != 0 ||
     (r = sshbuf_put_u64(msg, st->f_bavail)) != 0 ||
     (r = sshbuf_put_u64(msg, st->f_files)) != 0 ||
     (r = sshbuf_put_u64(msg, st->f_ffree)) != 0 ||
     (r = sshbuf_put_u64(msg, st->f_favail)) != 0 ||
     (r = sshbuf_put_u64(msg, ((st->f_fsid)))) != 0 ||
     (r = sshbuf_put_u64(msg, flag)) != 0 ||
     (r = sshbuf_put_u64(msg, st->f_namemax)) != 0)
  sshfatal("sftp-server.c", __func__, 680, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(msg);
 sshbuf_free(msg);
}





static int
compose_extension(struct sshbuf *msg, const char *name, const char *ver)
{
 int r;
 const struct sftp_handler *exthnd;

 if ((exthnd = extended_handler_byname(name)) == 
                                                ((void *)0)
                                                    )
  sshfatal("sftp-server.c", __func__, 696, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "internal error: no handler for %s", name);
 if (!request_permitted(exthnd)) {
  sshlog("sftp-server.c", __func__, 698, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "refusing to advertise disallowed extension %s", name);
  return 0;
 }
 if ((r = sshbuf_put_cstring(msg, name)) != 0 ||
     (r = sshbuf_put_cstring(msg, ver)) != 0)
  sshfatal("sftp-server.c", __func__, 703, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose %s", name);
 return 0;
}



static void
process_init(void)
{
 struct sshbuf *msg;
 int r;

 if ((r = sshbuf_get_u32(iqueue, &version)) != 0)
  sshfatal("sftp-server.c", __func__, 716, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 sshlog("sftp-server.c", __func__, 717, 0, SYSLOG_LEVEL_VERBOSE, 
((void *)0)
, "received client version %u", version);
 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-server.c", __func__, 719, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, 2)) != 0 ||
     (r = sshbuf_put_u32(msg, 3)) != 0)
  sshfatal("sftp-server.c", __func__, 722, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");


 compose_extension(msg, "posix-rename@openssh.com", "1");
 compose_extension(msg, "statvfs@openssh.com", "2");
 compose_extension(msg, "fstatvfs@openssh.com", "2");
 compose_extension(msg, "hardlink@openssh.com", "1");
 compose_extension(msg, "fsync@openssh.com", "1");
 compose_extension(msg, "lsetstat@openssh.com", "1");
 compose_extension(msg, "limits@openssh.com", "1");
 compose_extension(msg, "expand-path@openssh.com", "1");
 compose_extension(msg, "copy-data", "1");
 compose_extension(msg, "home-directory", "1");
 compose_extension(msg, "users-groups-by-id@openssh.com", "1");

 send_msg(msg);
 sshbuf_free(msg);
}

static void
process_open(u_int32_t id)
{
 u_int32_t pflags;
 Attrib a;
 char *name;
 int r, handle, fd, flags, mode, status = 4;

 if ((r = sshbuf_get_cstring(iqueue, &name, 
                                           ((void *)0)
                                               )) != 0 ||
     (r = sshbuf_get_u32(iqueue, &pflags)) != 0 ||
     (r = decode_attrib(iqueue, &a)) != 0)
  sshfatal("sftp-server.c", __func__, 752, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-server.c", __func__, 754, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "request %u: open flags %d", id, pflags);
 flags = flags_from_portable(pflags);
 mode = (a.flags & 0x00000004) ? a.perm : 0666;
 sshlog("sftp-server.c", __func__, 757, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "open \"%s\" flags %s mode 0%o", name, string_from_portable(pflags), mode)
                                              ;
 if (readonly &&
     ((flags & 
              0003
                       ) != 
                            00 
                                     ||
     (flags & (
              0100
                     |
                      01000
                             )) != 0)) {
  sshlog("sftp-server.c", __func__, 762, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "Refusing open request in read-only mode");
  status = 3;
 } else {
  fd = open(name, flags, mode);
  if (fd == -1) {
   status = errno_to_portable(
                             (*__errno_location ())
                                  );
  } else {
   handle = handle_new(HANDLE_FILE, name, fd, flags, 
                                                    ((void *)0)
                                                        );
   if (handle < 0) {
    close(fd);
   } else {
    send_handle(id, handle);
    status = 0;
   }
  }
 }
 if (status != 0)
  send_status(id, status);
 free(name);
}

static void
process_close(u_int32_t id)
{
 int r, handle, ret, status = 4;

 if ((r = get_handle(iqueue, &handle)) != 0)
  sshfatal("sftp-server.c", __func__, 789, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-server.c", __func__, 791, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "request %u: close handle %u", id, handle);
 handle_log_close(handle, 
                         ((void *)0)
                             );
 ret = handle_close(handle);
 status = (ret == -1) ? errno_to_portable(
                                         (*__errno_location ())
                                              ) : 0;
 send_status(id, status);
}

static void
process_read(u_int32_t id)
{
 static u_char *buf;
 static size_t buflen;
 u_int32_t len;
 int r, handle, fd, ret, status = 4;
 u_int64_t off;

 if ((r = get_handle(iqueue, &handle)) != 0 ||
     (r = sshbuf_get_u64(iqueue, &off)) != 0 ||
     (r = sshbuf_get_u32(iqueue, &len)) != 0)
  sshfatal("sftp-server.c", __func__, 810, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-server.c", __func__, 812, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "request %u: read \"%s\" (handle %d) off %llu len %u", id, handle_to_name(handle), handle, (unsigned long long)off, len)
                                                                      ;
 if ((fd = handle_to_fd(handle)) == -1)
  goto out;
 if (len > ((256 * 1024) - 1024)) {
  sshlog("sftp-server.c", __func__, 817, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "read change len %u to %u", len, ((256 * 1024) - 1024));
  len = ((256 * 1024) - 1024);
 }
 if (len > buflen) {
  sshlog("sftp-server.c", __func__, 821, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "allocate %zu => %u", buflen, len);
  if ((buf = realloc(
                    ((void *)0)
                        , len)) == 
                                   ((void *)0)
                                       )
   sshfatal("sftp-server.c", __func__, 823, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "realloc failed");
  buflen = len;
 }
 if (lseek(fd, off, 
                   0
                           ) == -1) {
  status = errno_to_portable(
                            (*__errno_location ())
                                 );
  sshlog("sftp-server.c", __func__, 828, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "seek \"%.100s\": %s", handle_to_name(handle), strerror(
 (*__errno_location ())
 ))
                      ;
  goto out;
 }
 if (len == 0) {

  ret = 0;
 } else if ((ret = read(fd, buf, len)) == -1) {
  status = errno_to_portable(
                            (*__errno_location ())
                                 );
  sshlog("sftp-server.c", __func__, 837, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "read \"%.100s\": %s", handle_to_name(handle), strerror(
 (*__errno_location ())
 ))
                      ;
  goto out;
 } else if (ret == 0) {
  status = 1;
  goto out;
 }
 send_data(id, buf, ret);
 handle_update_read(handle, ret);

 status = 0;
 out:
 if (status != 0)
  send_status(id, status);
}

static void
process_write(u_int32_t id)
{
 u_int64_t off;
 size_t len;
 int r, handle, fd, ret, status;
 u_char *data;

 if ((r = get_handle(iqueue, &handle)) != 0 ||
     (r = sshbuf_get_u64(iqueue, &off)) != 0 ||
     (r = sshbuf_get_string(iqueue, &data, &len)) != 0)
  sshfatal("sftp-server.c", __func__, 864, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-server.c", __func__, 866, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "request %u: write \"%s\" (handle %d) off %llu len %zu", id, handle_to_name(handle), handle, (unsigned long long)off, len)
                                                                      ;
 fd = handle_to_fd(handle);

 if (fd < 0)
  status = 4;
 else {
  if (!(handle_to_flags(handle) & 
                                 02000
                                         ) &&
      lseek(fd, off, 
                    0
                            ) == -1) {
   status = errno_to_portable(
                             (*__errno_location ())
                                  );
   sshlog("sftp-server.c", __func__, 876, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "seek \"%.100s\": %s", handle_to_name(handle), strerror(
  (*__errno_location ())
  ))
                       ;
  } else {

   ret = write(fd, data, len);
   if (ret == -1) {
    status = errno_to_portable(
                              (*__errno_location ())
                                   );
    sshlog("sftp-server.c", __func__, 883, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "write \"%.100s\": %s", handle_to_name(handle), strerror(
   (*__errno_location ())
   ))
                                                ;
   } else if ((size_t)ret == len) {
    status = 0;
    handle_update_write(handle, ret);
   } else {
    sshlog("sftp-server.c", __func__, 889, 1, SYSLOG_LEVEL_DEBUG2, 
   ((void *)0)
   , "nothing at all written");
    status = 4;
   }
  }
 }
 send_status(id, status);
 free(data);
}

static void
process_do_stat(u_int32_t id, int do_lstat)
{
 Attrib a;
 struct stat st;
 char *name;
 int r, status = 4;

 if ((r = sshbuf_get_cstring(iqueue, &name, 
                                           ((void *)0)
                                               )) != 0)
  sshfatal("sftp-server.c", __func__, 907, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-server.c", __func__, 909, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "request %u: %sstat", id, do_lstat ? "l" : "");
 sshlog("sftp-server.c", __func__, 910, 0, SYSLOG_LEVEL_VERBOSE, 
((void *)0)
, "%sstat name \"%s\"", do_lstat ? "l" : "", name);
 r = do_lstat ? lstat(name, &st) : stat(name, &st);
 if (r == -1) {
  status = errno_to_portable(
                            (*__errno_location ())
                                 );
 } else {
  stat_to_attrib(&st, &a);
  send_attrib(id, &a);
  status = 0;
 }
 if (status != 0)
  send_status(id, status);
 free(name);
}

static void
process_stat(u_int32_t id)
{
 process_do_stat(id, 0);
}

static void
process_lstat(u_int32_t id)
{
 process_do_stat(id, 1);
}

static void
process_fstat(u_int32_t id)
{
 Attrib a;
 struct stat st;
 int fd, r, handle, status = 4;

 if ((r = get_handle(iqueue, &handle)) != 0)
  sshfatal("sftp-server.c", __func__, 944, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 sshlog("sftp-server.c", __func__, 945, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "request %u: fstat \"%s\" (handle %u)", id, handle_to_name(handle), handle)
                                        ;
 fd = handle_to_fd(handle);
 if (fd >= 0) {
  r = fstat(fd, &st);
  if (r == -1) {
   status = errno_to_portable(
                             (*__errno_location ())
                                  );
  } else {
   stat_to_attrib(&st, &a);
   send_attrib(id, &a);
   status = 0;
  }
 }
 if (status != 0)
  send_status(id, status);
}

static struct timeval *
attrib_to_tv(const Attrib *a)
{
 static struct timeval tv[2];

 tv[0].tv_sec = a->atime;
 tv[0].tv_usec = 0;
 tv[1].tv_sec = a->mtime;
 tv[1].tv_usec = 0;
 return tv;
}

static struct timespec *
attrib_to_ts(const Attrib *a)
{
 static struct timespec ts[2];

 ts[0].tv_sec = a->atime;
 ts[0].tv_nsec = 0;
 ts[1].tv_sec = a->mtime;
 ts[1].tv_nsec = 0;
 return ts;
}

static void
process_setstat(u_int32_t id)
{
 Attrib a;
 char *name;
 int r, status = 0;

 if ((r = sshbuf_get_cstring(iqueue, &name, 
                                           ((void *)0)
                                               )) != 0 ||
     (r = decode_attrib(iqueue, &a)) != 0)
  sshfatal("sftp-server.c", __func__, 995, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-server.c", __func__, 997, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "request %u: setstat name \"%s\"", id, name);
 if (a.flags & 0x00000001) {
  sshlog("sftp-server.c", __func__, 999, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "set \"%s\" size %llu", name, (unsigned long long)a.size)
                                       ;
  r = truncate(name, a.size);
  if (r == -1)
   status = errno_to_portable(
                             (*__errno_location ())
                                  );
 }
 if (a.flags & 0x00000004) {
  sshlog("sftp-server.c", __func__, 1006, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "set \"%s\" mode %04o", name, a.perm);
  r = chmod(name, a.perm & 07777);
  if (r == -1)
   status = errno_to_portable(
                             (*__errno_location ())
                                  );
 }
 if (a.flags & 0x00000008) {
  char buf[64];
  time_t t = a.mtime;

  strftime(buf, sizeof(buf), "%Y%m%d-%H:%M:%S",
      localtime(&t));
  sshlog("sftp-server.c", __func__, 1017, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "set \"%s\" modtime %s", name, buf);
  r = utimes(name, attrib_to_tv(&a));
  if (r == -1)
   status = errno_to_portable(
                             (*__errno_location ())
                                  );
 }
 if (a.flags & 0x00000002) {
  sshlog("sftp-server.c", __func__, 1023, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "set \"%s\" owner %lu group %lu", name, (u_long)a.uid, (u_long)a.gid)
                                   ;
  r = chown(name, a.uid, a.gid);
  if (r == -1)
   status = errno_to_portable(
                             (*__errno_location ())
                                  );
 }
 send_status(id, status);
 free(name);
}

static void
process_fsetstat(u_int32_t id)
{
 Attrib a;
 int handle, fd, r;
 int status = 0;

 if ((r = get_handle(iqueue, &handle)) != 0 ||
     (r = decode_attrib(iqueue, &a)) != 0)
  sshfatal("sftp-server.c", __func__, 1042, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-server.c", __func__, 1044, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "request %u: fsetstat handle %d", id, handle);
 fd = handle_to_fd(handle);
 if (fd < 0)
  status = 4;
 else {
  char *name = handle_to_name(handle);

  if (a.flags & 0x00000001) {
   sshlog("sftp-server.c", __func__, 1052, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "set \"%s\" size %llu", name, (unsigned long long)a.size)
                                        ;
   r = ftruncate(fd, a.size);
   if (r == -1)
    status = errno_to_portable(
                              (*__errno_location ())
                                   );
  }
  if (a.flags & 0x00000004) {
   sshlog("sftp-server.c", __func__, 1059, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "set \"%s\" mode %04o", name, a.perm);

   r = fchmod(fd, a.perm & 07777);



   if (r == -1)
    status = errno_to_portable(
                              (*__errno_location ())
                                   );
  }
  if (a.flags & 0x00000008) {
   char buf[64];
   time_t t = a.mtime;

   strftime(buf, sizeof(buf), "%Y%m%d-%H:%M:%S",
       localtime(&t));
   sshlog("sftp-server.c", __func__, 1074, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "set \"%s\" modtime %s", name, buf);

   r = futimes(fd, attrib_to_tv(&a));



   if (r == -1)
    status = errno_to_portable(
                              (*__errno_location ())
                                   );
  }
  if (a.flags & 0x00000002) {
   sshlog("sftp-server.c", __func__, 1084, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "set \"%s\" owner %lu group %lu", name, (u_long)a.uid, (u_long)a.gid)
                                    ;

   r = fchown(fd, a.uid, a.gid);



   if (r == -1)
    status = errno_to_portable(
                              (*__errno_location ())
                                   );
  }
 }
 send_status(id, status);
}

static void
process_opendir(u_int32_t id)
{
 DIR *dirp = 
            ((void *)0)
                ;
 char *path;
 int r, handle, status = 4;

 if ((r = sshbuf_get_cstring(iqueue, &path, 
                                           ((void *)0)
                                               )) != 0)
  sshfatal("sftp-server.c", __func__, 1106, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-server.c", __func__, 1108, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "request %u: opendir", id);
 sshlog("sftp-server.c", __func__, 1109, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "opendir \"%s\"", path);
 dirp = opendir(path);
 if (dirp == 
            ((void *)0)
                ) {
  status = errno_to_portable(
                            (*__errno_location ())
                                 );
 } else {
  handle = handle_new(HANDLE_DIR, path, 0, 0, dirp);
  if (handle < 0) {
   closedir(dirp);
  } else {
   send_handle(id, handle);
   status = 0;
  }

 }
 if (status != 0)
  send_status(id, status);
 free(path);
}

static void
process_readdir(u_int32_t id)
{
 DIR *dirp;
 struct dirent *dp;
 char *path;
 int r, handle;

 if ((r = get_handle(iqueue, &handle)) != 0)
  sshfatal("sftp-server.c", __func__, 1137, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-server.c", __func__, 1139, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "request %u: readdir \"%s\" (handle %d)", id, handle_to_name(handle), handle)
                                    ;
 dirp = handle_to_dir(handle);
 path = handle_to_name(handle);
 if (dirp == 
            ((void *)0) 
                 || path == 
                            ((void *)0)
                                ) {
  send_status(id, 4);
 } else {
  struct stat st;
  char pathname[
               4096
                       ];
  Stat *stats;
  int nstats = 10, count = 0, i;

  stats = xcalloc(nstats, sizeof(Stat));
  while ((dp = readdir(dirp)) != 
                                ((void *)0)
                                    ) {
   if (count >= nstats) {
    nstats *= 2;
    stats = xreallocarray(stats, nstats, sizeof(Stat));
   }

   snprintf(pathname, sizeof pathname, "%s%s%s", path,
       strcmp(path, "/") ? "/" : "", dp->d_name);
   if (lstat(pathname, &st) == -1)
    continue;
   stat_to_attrib(&st, &(stats[count].attrib));
   stats[count].name = xstrdup(dp->d_name);
   stats[count].long_name = ls_file(dp->d_name, &st,
       0, 0, 
            ((void *)0)
                , 
                  ((void *)0)
                      );
   count++;


   if (count == 100)
    break;
  }
  if (count > 0) {
   send_names(id, count, stats);
   for (i = 0; i < count; i++) {
    free(stats[i].name);
    free(stats[i].long_name);
   }
  } else {
   send_status(id, 1);
  }
  free(stats);
 }
}

static void
process_remove(u_int32_t id)
{
 char *name;
 int r, status = 4;

 if ((r = sshbuf_get_cstring(iqueue, &name, 
                                           ((void *)0)
                                               )) != 0)
  sshfatal("sftp-server.c", __func__, 1192, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-server.c", __func__, 1194, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "request %u: remove", id);
 sshlog("sftp-server.c", __func__, 1195, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "remove name \"%s\"", name);
 r = unlink(name);
 status = (r == -1) ? errno_to_portable(
                                       (*__errno_location ())
                                            ) : 0;
 send_status(id, status);
 free(name);
}

static void
process_mkdir(u_int32_t id)
{
 Attrib a;
 char *name;
 int r, mode, status = 4;

 if ((r = sshbuf_get_cstring(iqueue, &name, 
                                           ((void *)0)
                                               )) != 0 ||
     (r = decode_attrib(iqueue, &a)) != 0)
  sshfatal("sftp-server.c", __func__, 1211, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 mode = (a.flags & 0x00000004) ?
     a.perm & 07777 : 0777;
 sshlog("sftp-server.c", __func__, 1215, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "request %u: mkdir", id);
 sshlog("sftp-server.c", __func__, 1216, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "mkdir name \"%s\" mode 0%o", name, mode);
 r = mkdir(name, mode);
 status = (r == -1) ? errno_to_portable(
                                       (*__errno_location ())
                                            ) : 0;
 send_status(id, status);
 free(name);
}

static void
process_rmdir(u_int32_t id)
{
 char *name;
 int r, status;

 if ((r = sshbuf_get_cstring(iqueue, &name, 
                                           ((void *)0)
                                               )) != 0)
  sshfatal("sftp-server.c", __func__, 1230, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-server.c", __func__, 1232, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "request %u: rmdir", id);
 sshlog("sftp-server.c", __func__, 1233, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "rmdir name \"%s\"", name);
 r = rmdir(name);
 status = (r == -1) ? errno_to_portable(
                                       (*__errno_location ())
                                            ) : 0;
 send_status(id, status);
 free(name);
}

static void
process_realpath(u_int32_t id)
{
 char resolvedname[
                  4096
                          ];
 char *path;
 int r;

 if ((r = sshbuf_get_cstring(iqueue, &path, 
                                           ((void *)0)
                                               )) != 0)
  sshfatal("sftp-server.c", __func__, 1248, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 if (path[0] == '\0') {
  free(path);
  path = xstrdup(".");
 }
 sshlog("sftp-server.c", __func__, 1254, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "request %u: realpath", id);
 sshlog("sftp-server.c", __func__, 1255, 0, SYSLOG_LEVEL_VERBOSE, 
((void *)0)
, "realpath \"%s\"", path);
 if (sftp_realpath(path, resolvedname) == 
                                         ((void *)0)
                                             ) {
  send_status(id, errno_to_portable(
                                   (*__errno_location ())
                                        ));
 } else {
  Stat s;
  attrib_clear(&s.attrib);
  s.name = s.long_name = resolvedname;
  send_names(id, 1, &s);
 }
 free(path);
}

static void
process_rename(u_int32_t id)
{
 char *oldpath, *newpath;
 int r, status;
 struct stat sb;

 if ((r = sshbuf_get_cstring(iqueue, &oldpath, 
                                              ((void *)0)
                                                  )) != 0 ||
     (r = sshbuf_get_cstring(iqueue, &newpath, 
                                              ((void *)0)
                                                  )) != 0)
  sshfatal("sftp-server.c", __func__, 1276, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-server.c", __func__, 1278, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "request %u: rename", id);
 sshlog("sftp-server.c", __func__, 1279, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "rename old \"%s\" new \"%s\"", oldpath, newpath);
 status = 4;
 if (lstat(oldpath, &sb) == -1)
  status = errno_to_portable(
                            (*__errno_location ())
                                 );
 else if (
         ((((
         sb.st_mode
         )) & 0170000) == (0100000))
                            ) {

  if (link(oldpath, newpath) == -1) {
   if (
      (*__errno_location ()) 
            == 
               95 
                          || 
                             (*__errno_location ()) 
                                   == 
                                      38

       
      || 
         (*__errno_location ()) 
               == 
                  18


       
      || 
         (*__errno_location ()) 
               == 
                  1

       
      ) {
    struct stat st;





    if (stat(newpath, &st) == -1) {
     if (rename(oldpath, newpath) == -1)
      status =
          errno_to_portable(
                           (*__errno_location ())
                                );
     else
      status = 0;
    }
   } else {
    status = errno_to_portable(
                              (*__errno_location ())
                                   );
   }
  } else if (unlink(oldpath) == -1) {
   status = errno_to_portable(
                             (*__errno_location ())
                                  );

   unlink(newpath);
  } else
   status = 0;
 } else if (stat(newpath, &sb) == -1) {
  if (rename(oldpath, newpath) == -1)
   status = errno_to_portable(
                             (*__errno_location ())
                                  );
  else
   status = 0;
 }
 send_status(id, status);
 free(oldpath);
 free(newpath);
}

static void
process_readlink(u_int32_t id)
{
 int r, len;
 char buf[
         4096
                 ];
 char *path;

 if ((r = sshbuf_get_cstring(iqueue, &path, 
                                           ((void *)0)
                                               )) != 0)
  sshfatal("sftp-server.c", __func__, 1335, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-server.c", __func__, 1337, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "request %u: readlink", id);
 sshlog("sftp-server.c", __func__, 1338, 0, SYSLOG_LEVEL_VERBOSE, 
((void *)0)
, "readlink \"%s\"", path);
 if ((len = readlink(path, buf, sizeof(buf) - 1)) == -1)
  send_status(id, errno_to_portable(
                                   (*__errno_location ())
                                        ));
 else {
  Stat s;

  buf[len] = '\0';
  attrib_clear(&s.attrib);
  s.name = s.long_name = buf;
  send_names(id, 1, &s);
 }
 free(path);
}

static void
process_symlink(u_int32_t id)
{
 char *oldpath, *newpath;
 int r, status;

 if ((r = sshbuf_get_cstring(iqueue, &oldpath, 
                                              ((void *)0)
                                                  )) != 0 ||
     (r = sshbuf_get_cstring(iqueue, &newpath, 
                                              ((void *)0)
                                                  )) != 0)
  sshfatal("sftp-server.c", __func__, 1360, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-server.c", __func__, 1362, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "request %u: symlink", id);
 sshlog("sftp-server.c", __func__, 1363, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "symlink old \"%s\" new \"%s\"", oldpath, newpath);

 r = symlink(oldpath, newpath);
 status = (r == -1) ? errno_to_portable(
                                       (*__errno_location ())
                                            ) : 0;
 send_status(id, status);
 free(oldpath);
 free(newpath);
}

static void
process_extended_posix_rename(u_int32_t id)
{
 char *oldpath, *newpath;
 int r, status;

 if ((r = sshbuf_get_cstring(iqueue, &oldpath, 
                                              ((void *)0)
                                                  )) != 0 ||
     (r = sshbuf_get_cstring(iqueue, &newpath, 
                                              ((void *)0)
                                                  )) != 0)
  sshfatal("sftp-server.c", __func__, 1380, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-server.c", __func__, 1382, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "request %u: posix-rename", id);
 sshlog("sftp-server.c", __func__, 1383, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "posix-rename old \"%s\" new \"%s\"", oldpath, newpath);
 r = rename(oldpath, newpath);
 status = (r == -1) ? errno_to_portable(
                                       (*__errno_location ())
                                            ) : 0;
 send_status(id, status);
 free(oldpath);
 free(newpath);
}

static void
process_extended_statvfs(u_int32_t id)
{
 char *path;
 struct statvfs st;
 int r;

 if ((r = sshbuf_get_cstring(iqueue, &path, 
                                           ((void *)0)
                                               )) != 0)
  sshfatal("sftp-server.c", __func__, 1399, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 sshlog("sftp-server.c", __func__, 1400, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "request %u: statvfs", id);
 sshlog("sftp-server.c", __func__, 1401, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "statvfs \"%s\"", path);

 if (statvfs(path, &st) != 0)
  send_status(id, errno_to_portable(
                                   (*__errno_location ())
                                        ));
 else
  send_statvfs(id, &st);
 free(path);
}

static void
process_extended_fstatvfs(u_int32_t id)
{
 int r, handle, fd;
 struct statvfs st;

 if ((r = get_handle(iqueue, &handle)) != 0)
  sshfatal("sftp-server.c", __func__, 1417, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 sshlog("sftp-server.c", __func__, 1418, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "request %u: fstatvfs \"%s\" (handle %u)", id, handle_to_name(handle), handle)
                                        ;
 if ((fd = handle_to_fd(handle)) < 0) {
  send_status(id, 4);
  return;
 }
 if (fstatvfs(fd, &st) != 0)
  send_status(id, errno_to_portable(
                                   (*__errno_location ())
                                        ));
 else
  send_statvfs(id, &st);
}

static void
process_extended_hardlink(u_int32_t id)
{
 char *oldpath, *newpath;
 int r, status;

 if ((r = sshbuf_get_cstring(iqueue, &oldpath, 
                                              ((void *)0)
                                                  )) != 0 ||
     (r = sshbuf_get_cstring(iqueue, &newpath, 
                                              ((void *)0)
                                                  )) != 0)
  sshfatal("sftp-server.c", __func__, 1438, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-server.c", __func__, 1440, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "request %u: hardlink", id);
 sshlog("sftp-server.c", __func__, 1441, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "hardlink old \"%s\" new \"%s\"", oldpath, newpath);
 r = link(oldpath, newpath);
 status = (r == -1) ? errno_to_portable(
                                       (*__errno_location ())
                                            ) : 0;
 send_status(id, status);
 free(oldpath);
 free(newpath);
}

static void
process_extended_fsync(u_int32_t id)
{
 int handle, fd, r, status = 8;

 if ((r = get_handle(iqueue, &handle)) != 0)
  sshfatal("sftp-server.c", __func__, 1455, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 sshlog("sftp-server.c", __func__, 1456, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "request %u: fsync (handle %u)", id, handle);
 sshlog("sftp-server.c", __func__, 1457, 0, SYSLOG_LEVEL_VERBOSE, 
((void *)0)
, "fsync \"%s\"", handle_to_name(handle));
 if ((fd = handle_to_fd(handle)) < 0)
  status = 2;
 else if (handle_is_ok(handle, HANDLE_FILE)) {
  r = fsync(fd);
  status = (r == -1) ? errno_to_portable(
                                        (*__errno_location ())
                                             ) : 0;
 }
 send_status(id, status);
}

static void
process_extended_lsetstat(u_int32_t id)
{
 Attrib a;
 char *name;
 int r, status = 0;

 if ((r = sshbuf_get_cstring(iqueue, &name, 
                                           ((void *)0)
                                               )) != 0 ||
     (r = decode_attrib(iqueue, &a)) != 0)
  sshfatal("sftp-server.c", __func__, 1476, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-server.c", __func__, 1478, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "request %u: lsetstat name \"%s\"", id, name);
 if (a.flags & 0x00000001) {

  status = 5;
  goto out;
 }
 if (a.flags & 0x00000004) {
  sshlog("sftp-server.c", __func__, 1485, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "set \"%s\" mode %04o", name, a.perm);
  r = fchmodat(
              -100
                      , name,
      a.perm & 07777, 
                     0x100
                                        );
  if (r == -1)
   status = errno_to_portable(
                             (*__errno_location ())
                                  );
 }
 if (a.flags & 0x00000008) {
  char buf[64];
  time_t t = a.mtime;

  strftime(buf, sizeof(buf), "%Y%m%d-%H:%M:%S",
      localtime(&t));
  sshlog("sftp-server.c", __func__, 1497, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "set \"%s\" modtime %s", name, buf);
  r = utimensat(
               -100
                       , name,
      attrib_to_ts(&a), 
                       0x100
                                          );
  if (r == -1)
   status = errno_to_portable(
                             (*__errno_location ())
                                  );
 }
 if (a.flags & 0x00000002) {
  sshlog("sftp-server.c", __func__, 1504, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "set \"%s\" owner %lu group %lu", name, (u_long)a.uid, (u_long)a.gid)
                                   ;
  r = fchownat(
              -100
                      , name, a.uid, a.gid,
      
     0x100
                        );
  if (r == -1)
   status = errno_to_portable(
                             (*__errno_location ())
                                  );
 }
 out:
 send_status(id, status);
 free(name);
}

static void
process_extended_limits(u_int32_t id)
{
 struct sshbuf *msg;
 int r;
 uint64_t nfiles = 0;

 struct rlimit rlim;


 sshlog("sftp-server.c", __func__, 1526, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "request %u: limits", id);


 if (getrlimit(
              RLIMIT_NOFILE
                           , &rlim) != -1 && rlim.rlim_cur > 5)
  nfiles = rlim.rlim_cur - 5;


 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-server.c", __func__, 1534, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, 201)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||

     (r = sshbuf_put_u64(msg, (256 * 1024))) != 0 ||

     (r = sshbuf_put_u64(msg, ((256 * 1024) - 1024))) != 0 ||

     (r = sshbuf_put_u64(msg, (256 * 1024) - 1024)) != 0 ||

     (r = sshbuf_put_u64(msg, nfiles)) != 0)
  sshfatal("sftp-server.c", __func__, 1545, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(msg);
 sshbuf_free(msg);
}

static void
process_extended_expand(u_int32_t id)
{
 char cwd[
         4096
                 ], resolvedname[
                                 4096
                                         ];
 char *path, *npath;
 int r;
 Stat s;

 if ((r = sshbuf_get_cstring(iqueue, &path, 
                                           ((void *)0)
                                               )) != 0)
  sshfatal("sftp-server.c", __func__, 1559, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 if (getcwd(cwd, sizeof(cwd)) == 
                                ((void *)0)
                                    ) {
  send_status(id, errno_to_portable(
                                   (*__errno_location ())
                                        ));
  goto out;
 }

 sshlog("sftp-server.c", __func__, 1565, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "request %u: expand, original \"%s\"", id, path);
 if (path[0] == '\0') {

  free(path);
  path = xstrdup(".");
 } else if (*path == '~') {


  if (strcmp(path, "~") == 0) {
   free(path);
   path = xstrdup(cwd);
  } else if (strncmp(path, "~/", 2) == 0) {
   npath = xstrdup(path + 2);
   free(path);
   xasprintf(&path, "%s/%s", cwd, npath);
   free(npath);
  } else {

   if (tilde_expand(path, pw->pw_uid, &npath) != 0) {
    send_status_errmsg(id,
        errno_to_portable(
                         2
                               ), "no such user");
    goto out;
   }
   free(path);
   path = npath;
  }
 } else if (*path != '/') {

  xasprintf(&npath, "%s/%s", cwd, path);
  free(path);
  path = npath;
 }
 sshlog("sftp-server.c", __func__, 1597, 0, SYSLOG_LEVEL_VERBOSE, 
((void *)0)
, "expand \"%s\"", path);
 if (sftp_realpath(path, resolvedname) == 
                                         ((void *)0)
                                             ) {
  send_status(id, errno_to_portable(
                                   (*__errno_location ())
                                        ));
  goto out;
 }
 attrib_clear(&s.attrib);
 s.name = s.long_name = resolvedname;
 send_names(id, 1, &s);
 out:
 free(path);
}

static void
process_extended_copy_data(u_int32_t id)
{
 u_char buf[64*1024];
 int read_handle, read_fd, write_handle, write_fd;
 u_int64_t len, read_off, read_len, write_off;
 int r, copy_until_eof, status = 8;
 size_t ret;

 if ((r = get_handle(iqueue, &read_handle)) != 0 ||
     (r = sshbuf_get_u64(iqueue, &read_off)) != 0 ||
     (r = sshbuf_get_u64(iqueue, &read_len)) != 0 ||
     (r = get_handle(iqueue, &write_handle)) != 0 ||
     (r = sshbuf_get_u64(iqueue, &write_off)) != 0)
  sshfatal("sftp-server.c", __func__, 1623, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: buffer error: %s", __func__, ssh_err(r));

 sshlog("sftp-server.c", __func__, 1625, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "request %u: copy-data from \"%s\" (handle %d) off %llu len %llu " "to \"%s\" (handle %d) off %llu", id, handle_to_name(read_handle), read_handle, (unsigned long long)read_off, (unsigned long long)read_len, handle_to_name(write_handle), write_handle, (unsigned long long)write_off)




                                   ;


 if (read_len == 0) {
  read_len = (u_int64_t)-1 - read_off;
  copy_until_eof = 1;
 } else
  copy_until_eof = 0;

 read_fd = handle_to_fd(read_handle);
 write_fd = handle_to_fd(write_handle);


 if (read_handle == write_handle || read_fd < 0 || write_fd < 0 ||
     !strcmp(handle_to_name(read_handle), handle_to_name(write_handle))) {
  status = 4;
  goto out;
 }

 if (lseek(read_fd, read_off, 
                             0
                                     ) < 0) {
  status = errno_to_portable(
                            (*__errno_location ())
                                 );
  sshlog("sftp-server.c", __func__, 1651, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s: read_seek failed", __func__);
  goto out;
 }

 if ((handle_to_flags(write_handle) & 
                                     02000
                                             ) == 0 &&
     lseek(write_fd, write_off, 
                               0
                                       ) < 0) {
  status = errno_to_portable(
                            (*__errno_location ())
                                 );
  sshlog("sftp-server.c", __func__, 1658, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s: write_seek failed", __func__);
  goto out;
 }


 while (read_len > 0 || copy_until_eof) {
  len = (((sizeof(buf)) < (read_len)) ? (sizeof(buf)) : (read_len));
  read_len -= len;

  ret = atomicio(read, read_fd, buf, len);
  if (ret == 0 && 
                 (*__errno_location ()) 
                       == 
                          32
                               ) {
   status = copy_until_eof ? 0 : 1;
   break;
  } else if (ret == 0) {
   status = errno_to_portable(
                             (*__errno_location ())
                                  );
   sshlog("sftp-server.c", __func__, 1673, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: read failed: %s", __func__, strerror(
  (*__errno_location ())
  ));
   break;
  }
  len = ret;
  handle_update_read(read_handle, len);

  ret = atomicio((ssize_t (*)(int, void *, size_t))write, write_fd, buf, len);
  if (ret != len) {
   status = errno_to_portable(
                             (*__errno_location ())
                                  );
   sshlog("sftp-server.c", __func__, 1682, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: write failed: %llu != %llu: %s", __func__, (unsigned long long)ret, (unsigned long long)len, strerror(
  (*__errno_location ())
  ))

                       ;
   break;
  }
  handle_update_write(write_handle, len);
 }

 if (read_len == 0)
  status = 0;

 out:
 send_status(id, status);
}

static void
process_extended_home_directory(u_int32_t id)
{
 char *username;
 struct passwd *user_pw;
 int r;
 Stat s;

 if ((r = sshbuf_get_cstring(iqueue, &username, 
                                               ((void *)0)
                                                   )) != 0)
  sshfatal("sftp-server.c", __func__, 1706, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-server.c", __func__, 1708, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "request %u: home-directory \"%s\"", id, username);
 if ((user_pw = getpwnam(username)) == 
                                      ((void *)0)
                                          ) {
  send_status(id, 4);
  goto out;
 }

 sshlog("sftp-server.c", __func__, 1714, 0, SYSLOG_LEVEL_VERBOSE, 
((void *)0)
, "home-directory \"%s\"", pw->pw_dir);
 attrib_clear(&s.attrib);
 s.name = s.long_name = pw->pw_dir;
 send_names(id, 1, &s);
 out:
 free(username);
}

static void
process_extended_get_users_groups_by_id(u_int32_t id)
{
 struct passwd *user_pw;
 struct group *gr;
 struct sshbuf *uids, *gids, *usernames, *groupnames, *msg;
 int r;
 u_int n, nusers = 0, ngroups = 0;
 const char *name;

 if ((usernames = sshbuf_new()) == 
                                  ((void *)0) 
                                       ||
     (groupnames = sshbuf_new()) == 
                                   ((void *)0) 
                                        ||
     (msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-server.c", __func__, 1735, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_froms(iqueue, &uids)) != 0 ||
     (r = sshbuf_froms(iqueue, &gids)) != 0)
  sshfatal("sftp-server.c", __func__, 1738, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 sshlog("sftp-server.c", __func__, 1739, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "uids len = %zu, gids len = %zu", sshbuf_len(uids), sshbuf_len(gids))
                                        ;
 while (sshbuf_len(uids) != 0) {
  if ((r = sshbuf_get_u32(uids, &n)) != 0)
   sshfatal("sftp-server.c", __func__, 1743, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse inner uid");
  user_pw = getpwuid((uid_t)n);
  name = user_pw == 
                   ((void *)0) 
                        ? "" : user_pw->pw_name;
  sshlog("sftp-server.c", __func__, 1746, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "uid %u => \"%s\"", n, name);
  if ((r = sshbuf_put_cstring(usernames, name)) != 0)
   sshfatal("sftp-server.c", __func__, 1748, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble gid reply");
  nusers++;
 }
 while (sshbuf_len(gids) != 0) {
  if ((r = sshbuf_get_u32(gids, &n)) != 0)
   sshfatal("sftp-server.c", __func__, 1753, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse inner gid");
  gr = getgrgid((gid_t)n);
  name = gr == 
              ((void *)0) 
                   ? "" : gr->gr_name;
  sshlog("sftp-server.c", __func__, 1756, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "gid %u => \"%s\"", n, name);
  if ((r = sshbuf_put_cstring(groupnames, name)) != 0)
   sshfatal("sftp-server.c", __func__, 1758, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble gid reply");
  nusers++;
 }
 sshlog("sftp-server.c", __func__, 1761, 0, SYSLOG_LEVEL_VERBOSE, 
((void *)0)
, "users-groups-by-id: %u users, %u groups", nusers, ngroups);

 if ((r = sshbuf_put_u8(msg, 201)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_stringb(msg, usernames)) != 0 ||
     (r = sshbuf_put_stringb(msg, groupnames)) != 0)
  sshfatal("sftp-server.c", __func__, 1767, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(msg);

 sshbuf_free(uids);
 sshbuf_free(gids);
 sshbuf_free(usernames);
 sshbuf_free(groupnames);
 sshbuf_free(msg);
}

static void
process_extended(u_int32_t id)
{
 char *request;
 int r;
 const struct sftp_handler *exthand;

 if ((r = sshbuf_get_cstring(iqueue, &request, 
                                              ((void *)0)
                                                  )) != 0)
  sshfatal("sftp-server.c", __func__, 1785, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 if ((exthand = extended_handler_byname(request)) == 
                                                    ((void *)0)
                                                        ) {
  sshlog("sftp-server.c", __func__, 1787, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Unknown extended request \"%.100s\"", request);
  send_status(id, 8);
 } else {
  if (!request_permitted(exthand))
   send_status(id, 3);
  else
   exthand->handler(id);
 }
 free(request);
}



static void
process(void)
{
 u_int msg_len;
 u_int buf_len;
 u_int consumed;
 u_char type;
 const u_char *cp;
 int i, r;
 u_int32_t id;

 buf_len = sshbuf_len(iqueue);
 if (buf_len < 5)
  return;
 cp = sshbuf_ptr(iqueue);
 msg_len = get_u32(cp);
 if (msg_len > (256 * 1024)) {
  sshlog("sftp-server.c", __func__, 1817, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "bad message from %s local user %s", client_addr, pw->pw_name)
                               ;
  sftp_server_cleanup_exit(11);
 }
 if (buf_len < msg_len + 4)
  return;
 if ((r = sshbuf_consume(iqueue, 4)) != 0)
  sshfatal("sftp-server.c", __func__, 1824, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "consume");
 buf_len -= 4;
 if ((r = sshbuf_get_u8(iqueue, &type)) != 0)
  sshfatal("sftp-server.c", __func__, 1827, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse type");

 switch (type) {
 case 1:
  process_init();
  init_done = 1;
  break;
 case 200:
  if (!init_done)
   sshfatal("sftp-server.c", __func__, 1836, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Received extended request before init");
  if ((r = sshbuf_get_u32(iqueue, &id)) != 0)
   sshfatal("sftp-server.c", __func__, 1838, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse extended ID");
  process_extended(id);
  break;
 default:
  if (!init_done)
   sshfatal("sftp-server.c", __func__, 1843, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Received %u request before init", type);
  if ((r = sshbuf_get_u32(iqueue, &id)) != 0)
   sshfatal("sftp-server.c", __func__, 1845, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse ID");
  for (i = 0; handlers[i].handler != 
                                    ((void *)0)
                                        ; i++) {
   if (type == handlers[i].type) {
    if (!request_permitted(&handlers[i])) {
     send_status(id,
         3);
    } else {
     handlers[i].handler(id);
    }
    break;
   }
  }
  if (handlers[i].handler == 
                            ((void *)0)
                                )
   sshlog("sftp-server.c", __func__, 1858, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Unknown message %u", type);
 }

 if (buf_len < sshbuf_len(iqueue)) {
  sshlog("sftp-server.c", __func__, 1862, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "iqueue grew unexpectedly");
  sftp_server_cleanup_exit(255);
 }
 consumed = buf_len - sshbuf_len(iqueue);
 if (msg_len < consumed) {
  sshlog("sftp-server.c", __func__, 1867, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "msg_len %u < consumed %u", msg_len, consumed);
  sftp_server_cleanup_exit(255);
 }
 if (msg_len > consumed &&
     (r = sshbuf_consume(iqueue, msg_len - consumed)) != 0)
  sshfatal("sftp-server.c", __func__, 1872, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "consume");
}


void
sftp_server_cleanup_exit(int i)
{
 if (pw != 
          ((void *)0) 
               && client_addr != 
                                 ((void *)0)
                                     ) {
  handle_log_exit();
  sshlog("sftp-server.c", __func__, 1881, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "session closed for local user %s from [%s]", pw->pw_name, client_addr)
                               ;
 }
 _exit(i);
}

static void
sftp_server_usage(void)
{
 extern char *__progname;

 fprintf(
        stderr
              ,
     "usage: %s [-ehR] [-d start_directory] [-f log_facility] "
     "[-l log_level]\n\t[-P denied_requests] "
     "[-p allowed_requests] [-u umask]\n"
     "       %s -Q protocol_feature\n",
     __progname, __progname);
 exit(1);
}

int
sftp_server_main(int argc, char **argv, struct passwd *user_pw)
{
 int i, r, in, out, ch, skipargs = 0, log_stderr = 0;
 ssize_t len, olen;
 SyslogFacility log_facility = SYSLOG_FACILITY_AUTH;
 char *cp, *homedir = 
                     ((void *)0)
                         , uidstr[32], buf[4*4096];
 long mask;

 extern char *BSDoptarg;
 extern char *__progname;

 __progname = ssh_get_progname(argv[0]);
 log_init(__progname, log_level, log_facility, log_stderr);

 pw = pwcopy(user_pw);

 while (!skipargs && (ch = BSDgetopt(argc, argv, "d:f:l:P:p:Q:u:cehR")
                          ) != -1) {
  switch (ch) {
  case 'Q':
   if (strcasecmp(BSDoptarg, "requests") != 0) {
    fprintf(
           stderr
                 , "Invalid query type\n");
    exit(1);
   }
   for (i = 0; handlers[i].handler != 
                                     ((void *)0)
                                         ; i++)
    printf("%s\n", handlers[i].name);
   for (i = 0; extended_handlers[i].handler != 
                                              ((void *)0)
                                                  ; i++)
    printf("%s\n", extended_handlers[i].name);
   exit(0);
   break;
  case 'R':
   readonly = 1;
   break;
  case 'c':




   skipargs = 1;
   break;
  case 'e':
   log_stderr = 1;
   break;
  case 'l':
   log_level = log_level_number(BSDoptarg);
   if (log_level == SYSLOG_LEVEL_NOT_SET)
    sshlog("sftp-server.c", __func__, 1948, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Invalid log level \"%s\"", BSDoptarg);
   break;
  case 'f':
   log_facility = log_facility_number(BSDoptarg);
   if (log_facility == SYSLOG_FACILITY_NOT_SET)
    sshlog("sftp-server.c", __func__, 1953, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Invalid log facility \"%s\"", BSDoptarg);
   break;
  case 'd':
   cp = tilde_expand_filename(BSDoptarg, user_pw->pw_uid);
   snprintf(uidstr, sizeof(uidstr), "%llu",
       (unsigned long long)pw->pw_uid);
   homedir = percent_expand(cp, "d", user_pw->pw_dir,
       "u", user_pw->pw_name, "U", uidstr, (char *)
                                                  ((void *)0)
                                                      );
   free(cp);
   break;
  case 'p':
   if (request_allowlist != 
                           ((void *)0)
                               )
    sshfatal("sftp-server.c", __func__, 1965, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Permitted requests already set");
   request_allowlist = xstrdup(BSDoptarg);
   break;
  case 'P':
   if (request_denylist != 
                          ((void *)0)
                              )
    sshfatal("sftp-server.c", __func__, 1970, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Refused requests already set");
   request_denylist = xstrdup(BSDoptarg);
   break;
  case 'u':
   
  (*__errno_location ()) 
        = 0;
   mask = strtol(BSDoptarg, &cp, 8);
   if (mask < 0 || mask > 0777 || *cp != '\0' ||
       cp == BSDoptarg || (mask == 0 && 
                                    (*__errno_location ()) 
                                          != 0))
    sshfatal("sftp-server.c", __func__, 1978, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Invalid umask \"%s\"", BSDoptarg);
   (void)umask((mode_t)mask);
   break;
  case 'h':
  default:
   sftp_server_usage();
  }
 }

 log_init(__progname, log_level, log_facility, log_stderr);







 platform_disable_tracing(1);


 platform_pledge_sftp_server();

 if ((cp = getenv("SSH_CONNECTION")) != 
                                       ((void *)0)
                                           ) {
  client_addr = xstrdup(cp);
  if ((cp = strchr(client_addr, ' ')) == 
                                        ((void *)0)
                                            ) {
   sshlog("sftp-server.c", __func__, 2003, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Malformed SSH_CONNECTION variable: \"%s\"", getenv("SSH_CONNECTION"))
                                ;
   sftp_server_cleanup_exit(255);
  }
  *cp = '\0';
 } else
  client_addr = xstrdup("UNKNOWN");

 sshlog("sftp-server.c", __func__, 2011, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "session opened for local user %s from [%s]", pw->pw_name, client_addr)
                              ;

 in = 
     0
                 ;
 out = 
      1
                   ;






 if ((iqueue = sshbuf_new()) == 
                               ((void *)0)
                                   )
  sshfatal("sftp-server.c", __func__, 2023, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((oqueue = sshbuf_new()) == 
                               ((void *)0)
                                   )
  sshfatal("sftp-server.c", __func__, 2025, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");

 if (homedir != 
               ((void *)0)
                   ) {
  if (chdir(homedir) != 0) {
   sshlog("sftp-server.c", __func__, 2029, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "chdir to \"%s\" failed: %s", homedir, strerror(
  (*__errno_location ())
  ))
                       ;
  }
 }

 for (;;) {
  struct pollfd pfd[2];

  memset(pfd, 0, sizeof pfd);
  pfd[0].fd = pfd[1].fd = -1;






  if ((r = sshbuf_check_reserve(iqueue, sizeof(buf))) == 0 &&
      (r = sshbuf_check_reserve(oqueue,
      (256 * 1024))) == 0) {
   pfd[0].fd = in;
   pfd[0].events = 
                  0x001
                        ;
  }
  else if (r != -9)
   sshfatal("sftp-server.c", __func__, 2052, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reserve");

  olen = sshbuf_len(oqueue);
  if (olen > 0) {
   pfd[1].fd = out;
   pfd[1].events = 
                  0x004
                         ;
  }

  if (poll(pfd, 2, -1) == -1) {
   if (
      (*__errno_location ()) 
            == 
               4
                    )
    continue;
   sshlog("sftp-server.c", __func__, 2063, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "poll: %s", strerror(
  (*__errno_location ())
  ));
   sftp_server_cleanup_exit(2);
  }


  if (pfd[0].revents & (
                       0x001
                             |
                              0x010
                                     )) {
   len = read(in, buf, sizeof buf);
   if (len == 0) {
    sshlog("sftp-server.c", __func__, 2071, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "read eof");
    sftp_server_cleanup_exit(0);
   } else if (len == -1) {
    if (
       (*__errno_location ()) 
             != 
                11 
                       && 
                          (*__errno_location ()) 
                                != 
                                   4
                                        ) {
     sshlog("sftp-server.c", __func__, 2075, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "read: %s", strerror(
    (*__errno_location ())
    ));
     sftp_server_cleanup_exit(1);
    }
   } else if ((r = sshbuf_put(iqueue, buf, len)) != 0)
    sshfatal("sftp-server.c", __func__, 2079, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_put");
  }

  if (pfd[1].revents & (
                       0x004
                              |
                               0x010
                                      )) {
   len = write(out, sshbuf_ptr(oqueue), olen);
   if (len == 0 || (len == -1 && 
                                (*__errno_location ()) 
                                      == 
                                         32
                                              )) {
    sshlog("sftp-server.c", __func__, 2085, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "write eof");
    sftp_server_cleanup_exit(0);
   } else if (len == -1) {
    sftp_server_cleanup_exit(1);
    if (
       (*__errno_location ()) 
             != 
                11 
                       && 
                          (*__errno_location ()) 
                                != 
                                   4
                                        ) {
     sshlog("sftp-server.c", __func__, 2090, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "write: %s", strerror(
    (*__errno_location ())
    ));
     sftp_server_cleanup_exit(1);
    }
   } else if ((r = sshbuf_consume(oqueue, len)) != 0)
    sshfatal("sftp-server.c", __func__, 2094, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "consume");
  }






  r = sshbuf_check_reserve(oqueue, (256 * 1024));
  if (r == 0)
   process();
  else if (r != -9)
   sshfatal("sftp-server.c", __func__, 2106, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reserve");
 }
}
