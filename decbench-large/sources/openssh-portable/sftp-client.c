











































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
void start_progress_meter(const char *, off_t, off_t *);
void refresh_progress_meter(int);
void stop_progress_meter(void);
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
int vasnmprintf(char **, size_t, int *, const char *, va_list);
int mprintf(const char *, ...)
     __attribute__((format(printf, 1, 2)));
int fmprintf(FILE *, const char *, ...)
     __attribute__((format(printf, 2, 3)));
int vfmprintf(FILE *, const char *, va_list);
int snmprintf(char *, size_t, int *, const char *, ...)
     __attribute__((format(printf, 4, 5)));
int asmprintf(char **, size_t, int *, const char *, ...)
     __attribute__((format(printf, 4, 5)));
void msetlocale(void);

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


typedef struct SFTP_DIRENT SFTP_DIRENT;

struct SFTP_DIRENT {
 char *filename;
 char *longname;
 Attrib a;
};





struct sftp_statvfs {
 u_int64_t f_bsize;
 u_int64_t f_frsize;
 u_int64_t f_blocks;
 u_int64_t f_bfree;
 u_int64_t f_bavail;
 u_int64_t f_files;
 u_int64_t f_ffree;
 u_int64_t f_favail;
 u_int64_t f_fsid;
 u_int64_t f_flag;
 u_int64_t f_namemax;
};


struct sftp_limits {
 u_int64_t packet_length;
 u_int64_t read_length;
 u_int64_t write_length;
 u_int64_t open_handles;
};
struct sftp_conn *do_init(int, int, u_int, u_int, u_int64_t);

u_int sftp_proto_version(struct sftp_conn *);


int do_limits(struct sftp_conn *, struct sftp_limits *);


int do_close(struct sftp_conn *, const u_char *, u_int);


int do_readdir(struct sftp_conn *, const char *, SFTP_DIRENT ***);


void free_sftp_dirents(SFTP_DIRENT **);


int do_rm(struct sftp_conn *, const char *);


int do_mkdir(struct sftp_conn *, const char *, Attrib *, int);


int do_rmdir(struct sftp_conn *, const char *);


Attrib *do_stat(struct sftp_conn *, const char *, int);


Attrib *do_lstat(struct sftp_conn *, const char *, int);


int do_setstat(struct sftp_conn *, const char *, Attrib *);


int do_fsetstat(struct sftp_conn *, const u_char *, u_int, Attrib *);


int do_lsetstat(struct sftp_conn *conn, const char *path, Attrib *a);


char *do_realpath(struct sftp_conn *, const char *);


char *do_expand_path(struct sftp_conn *, const char *);


int can_expand_path(struct sftp_conn *);


int do_statvfs(struct sftp_conn *, const char *, struct sftp_statvfs *, int);


int do_rename(struct sftp_conn *, const char *, const char *, int);


int do_copy(struct sftp_conn *, const char *, const char *);


int do_hardlink(struct sftp_conn *, const char *, const char *);


int do_symlink(struct sftp_conn *, const char *, const char *);


int do_fsync(struct sftp_conn *conn, u_char *, u_int);





int do_download(struct sftp_conn *, const char *, const char *, Attrib *,
    int, int, int, int);





int download_dir(struct sftp_conn *, const char *, const char *, Attrib *,
    int, int, int, int, int, int);





int do_upload(struct sftp_conn *, const char *, const char *,
    int, int, int, int);





int upload_dir(struct sftp_conn *, const char *, const char *,
    int, int, int, int, int, int);





int
do_crossload(struct sftp_conn *from, struct sftp_conn *to,
    const char *from_path, const char *to_path,
    Attrib *a, int preserve_flag);





int crossload_dir(struct sftp_conn *from, struct sftp_conn *to,
    const char *from_path, const char *to_path,
    Attrib *dirattrib, int preserve_flag, int print_flag,
    int follow_link_flag);




int can_get_users_groups_by_id(struct sftp_conn *conn);
int do_get_users_groups_by_id(struct sftp_conn *conn,
    const u_int *uids, u_int nuids,
    const u_int *gids, u_int ngids,
    char ***usernamesp, char ***groupnamesp);


char *path_append(const char *, const char *);



char *make_absolute(char *, const char *);


int remote_is_dir(struct sftp_conn *conn, const char *path);


int local_is_dir(const char *path);


int globpath_is_dir(const char *pathname);

extern volatile sig_atomic_t interrupted;
extern int showprogress;
struct sftp_conn {
 int fd_in;
 int fd_out;
 u_int download_buflen;
 u_int upload_buflen;
 u_int num_requests;
 u_int version;
 u_int msg_id;
 u_int exts;
 u_int64_t limit_kbps;
 struct bwlimit bwlimit_in, bwlimit_out;
};


struct request {
 u_int id;
 size_t len;
 u_int64_t offset;
 struct { struct request *tqe_next; struct request **tqe_prev; } tq;
};
struct requests { struct request *tqh_first; struct request **tqh_last; };

static u_char *
get_handle(struct sftp_conn *conn, u_int expected_id, size_t *len,
    const char *errfmt, ...) __attribute__((format(printf, 4, 5)));

static struct request *
request_enqueue(struct requests *requests, u_int id, size_t len,
    uint64_t offset)
{
 struct request *req;

 req = xcalloc(1, sizeof(*req));
 req->id = id;
 req->len = len;
 req->offset = offset;
 do { (req)->tq.tqe_next = 
((void *)0)
; (req)->tq.tqe_prev = (requests)->tqh_last; *(requests)->tqh_last = (req); (requests)->tqh_last = &(req)->tq.tqe_next; } while (0);
 return req;
}

static struct request *
request_find(struct requests *requests, u_int id)
{
 struct request *req;

 for (req = ((requests)->tqh_first);
     req != 
           ((void *)0) 
                && req->id != id;
     req = ((req)->tq.tqe_next))
  ;
 return req;
}


static int
sftpio(void *_bwlimit, size_t amount)
{
 struct bwlimit *bwlimit = (struct bwlimit *)_bwlimit;

 refresh_progress_meter(0);
 if (bwlimit != 
               ((void *)0)
                   )
  bandwidth_limit(bwlimit, amount);
 return 0;
}

static void
send_msg(struct sftp_conn *conn, struct sshbuf *m)
{
 u_char mlen[4];
 struct iovec iov[2];

 if (sshbuf_len(m) > (256 * 1024))
  sshfatal("sftp-client.c", __func__, 171, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Outbound message too long %zu", sshbuf_len(m));


 put_u32(mlen, sshbuf_len(m));
 iov[0].iov_base = mlen;
 iov[0].iov_len = sizeof(mlen);
 iov[1].iov_base = (u_char *)sshbuf_ptr(m);
 iov[1].iov_len = sshbuf_len(m);

 if (atomiciov6(writev, conn->fd_out, iov, 2, sftpio,
     conn->limit_kbps > 0 ? &conn->bwlimit_out : 
                                                ((void *)0)
                                                    ) !=
     sshbuf_len(m) + sizeof(mlen))
  sshfatal("sftp-client.c", __func__, 183, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Couldn't send packet: %s", strerror(
 (*__errno_location ())
 ));

 sshbuf_reset(m);
}

static void
get_msg_extended(struct sftp_conn *conn, struct sshbuf *m, int initial)
{
 u_int msg_len;
 u_char *p;
 int r;

 sshbuf_reset(m);
 if ((r = sshbuf_reserve(m, 4, &p)) != 0)
  sshfatal("sftp-client.c", __func__, 197, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reserve");
 if (atomicio6(read, conn->fd_in, p, 4, sftpio,
     conn->limit_kbps > 0 ? &conn->bwlimit_in : 
                                               ((void *)0)
                                                   ) != 4) {
  if (
     (*__errno_location ()) 
           == 
              32 
                    || 
                       (*__errno_location ()) 
                             == 
                                104
                                          )
   sshfatal("sftp-client.c", __func__, 201, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Connection closed");
  else
   sshfatal("sftp-client.c", __func__, 203, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Couldn't read packet: %s", strerror(
  (*__errno_location ())
  ));
 }

 if ((r = sshbuf_get_u32(m, &msg_len)) != 0)
  sshfatal("sftp-client.c", __func__, 207, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_get_u32");
 if (msg_len > (256 * 1024)) {
  sshlog("sftp-client.c", __func__, 209, 0, initial ? SYSLOG_LEVEL_ERROR : SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Received message too long %u", msg_len)
                                              ;
  sshfatal("sftp-client.c", __func__, 211, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Ensure the remote shell produces no output " "for non-interactive sessions.")
                                      ;
 }

 if ((r = sshbuf_reserve(m, msg_len, &p)) != 0)
  sshfatal("sftp-client.c", __func__, 216, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reserve");
 if (atomicio6(read, conn->fd_in, p, msg_len, sftpio,
     conn->limit_kbps > 0 ? &conn->bwlimit_in : 
                                               ((void *)0)
                                                   )
     != msg_len) {
  if (
     (*__errno_location ()) 
           == 
              32
                   )
   sshfatal("sftp-client.c", __func__, 221, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Connection closed");
  else
   sshfatal("sftp-client.c", __func__, 223, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Read packet: %s", strerror(
  (*__errno_location ())
  ));
 }
}

static void
get_msg(struct sftp_conn *conn, struct sshbuf *m)
{
 get_msg_extended(conn, m, 0);
}

static void
send_string_request(struct sftp_conn *conn, u_int id, u_int code, const char *s,
    u_int len)
{
 struct sshbuf *msg;
 int r;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 241, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, code)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_string(msg, s, len)) != 0)
  sshfatal("sftp-client.c", __func__, 245, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(conn, msg);
 sshlog("sftp-client.c", __func__, 247, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "Sent message fd %d T:%u I:%u", conn->fd_out, code, id);
 sshbuf_free(msg);
}

static void
send_string_attrs_request(struct sftp_conn *conn, u_int id, u_int code,
    const void *s, u_int len, Attrib *a)
{
 struct sshbuf *msg;
 int r;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 259, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, code)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_string(msg, s, len)) != 0 ||
     (r = encode_attrib(msg, a)) != 0)
  sshfatal("sftp-client.c", __func__, 264, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(conn, msg);
 sshlog("sftp-client.c", __func__, 266, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "Sent message fd %d T:%u I:%u F:0x%04x M:%05o", conn->fd_out, code, id, a->flags, a->perm)
                                               ;
 sshbuf_free(msg);
}

static u_int
get_status(struct sftp_conn *conn, u_int expected_id)
{
 struct sshbuf *msg;
 u_char type;
 u_int id, status;
 int r;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 280, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 get_msg(conn, msg);
 if ((r = sshbuf_get_u8(msg, &type)) != 0 ||
     (r = sshbuf_get_u32(msg, &id)) != 0)
  sshfatal("sftp-client.c", __func__, 284, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");

 if (id != expected_id)
  sshfatal("sftp-client.c", __func__, 287, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ID mismatch (%u != %u)", id, expected_id);
 if (type != 101)
  sshfatal("sftp-client.c", __func__, 289, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Expected SSH2_FXP_STATUS(%u) packet, got %u", 101, type)
                            ;

 if ((r = sshbuf_get_u32(msg, &status)) != 0)
  sshfatal("sftp-client.c", __func__, 293, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 sshbuf_free(msg);

 sshlog("sftp-client.c", __func__, 296, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "SSH2_FXP_STATUS %u", status);

 return status;
}

static u_char *
get_handle(struct sftp_conn *conn, u_int expected_id, size_t *len,
    const char *errfmt, ...)
{
 struct sshbuf *msg;
 u_int id, status;
 u_char type;
 u_char *handle;
 char errmsg[256];
 va_list args;
 int r;

 
__builtin_va_start(
args
,
errfmt
)
                      ;
 if (errfmt != 
              ((void *)0)
                  )
  vsnprintf(errmsg, sizeof(errmsg), errfmt, args);
 
__builtin_va_end(
args
)
            ;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 319, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 get_msg(conn, msg);
 if ((r = sshbuf_get_u8(msg, &type)) != 0 ||
     (r = sshbuf_get_u32(msg, &id)) != 0)
  sshfatal("sftp-client.c", __func__, 323, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 if (id != expected_id)
  sshfatal("sftp-client.c", __func__, 326, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: ID mismatch (%u != %u)", errfmt == 
 ((void *)0) 
 ? __func__ : errmsg, id, expected_id)
                                                          ;
 if (type == 101) {
  if ((r = sshbuf_get_u32(msg, &status)) != 0)
   sshfatal("sftp-client.c", __func__, 330, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse status");
  if (errfmt != 
               ((void *)0)
                   )
   sshlog("sftp-client.c", __func__, 332, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: %s", errmsg, fx2txt(status));
  sshbuf_free(msg);
  return(
        ((void *)0)
            );
 } else if (type != 102)
  sshfatal("sftp-client.c", __func__, 336, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: Expected SSH2_FXP_HANDLE(%u) packet, got %u", errfmt == 
 ((void *)0) 
 ? __func__ : errmsg, 102, type)
                                                                ;

 if ((r = sshbuf_get_string(msg, &handle, len)) != 0)
  sshfatal("sftp-client.c", __func__, 340, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse handle");
 sshbuf_free(msg);

 return handle;
}


static Attrib *
get_decode_stat(struct sftp_conn *conn, u_int expected_id, int quiet)
{
 struct sshbuf *msg;
 u_int id;
 u_char type;
 int r;
 static Attrib a;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 357, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 get_msg(conn, msg);

 if ((r = sshbuf_get_u8(msg, &type)) != 0 ||
     (r = sshbuf_get_u32(msg, &id)) != 0)
  sshfatal("sftp-client.c", __func__, 362, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 if (id != expected_id)
  sshfatal("sftp-client.c", __func__, 365, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ID mismatch (%u != %u)", id, expected_id);
 if (type == 101) {
  u_int status;

  if ((r = sshbuf_get_u32(msg, &status)) != 0)
   sshfatal("sftp-client.c", __func__, 370, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse status");
  if (quiet)
   sshlog("sftp-client.c", __func__, 372, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "stat remote: %s", fx2txt(status));
  else
   sshlog("sftp-client.c", __func__, 374, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "stat remote: %s", fx2txt(status));
  sshbuf_free(msg);
  return(
        ((void *)0)
            );
 } else if (type != 105) {
  sshfatal("sftp-client.c", __func__, 378, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Expected SSH2_FXP_ATTRS(%u) packet, got %u", 105, type)
                           ;
 }
 if ((r = decode_attrib(msg, &a)) != 0) {
  sshlog("sftp-client.c", __func__, 382, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "decode_attrib");
  sshbuf_free(msg);
  return 
        ((void *)0)
            ;
 }
 sshlog("sftp-client.c", __func__, 386, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "Received stat reply T:%u I:%u F:0x%04x M:%05o", type, id, a.flags, a.perm)
                               ;
 sshbuf_free(msg);

 return &a;
}

static int
get_decode_statvfs(struct sftp_conn *conn, struct sftp_statvfs *st,
    u_int expected_id, int quiet)
{
 struct sshbuf *msg;
 u_char type;
 u_int id;
 u_int64_t flag;
 int r;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 404, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 get_msg(conn, msg);

 if ((r = sshbuf_get_u8(msg, &type)) != 0 ||
     (r = sshbuf_get_u32(msg, &id)) != 0)
  sshfatal("sftp-client.c", __func__, 409, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-client.c", __func__, 411, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "Received statvfs reply T:%u I:%u", type, id);
 if (id != expected_id)
  sshfatal("sftp-client.c", __func__, 413, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ID mismatch (%u != %u)", id, expected_id);
 if (type == 101) {
  u_int status;

  if ((r = sshbuf_get_u32(msg, &status)) != 0)
   sshfatal("sftp-client.c", __func__, 418, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse status");
  if (quiet)
   sshlog("sftp-client.c", __func__, 420, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "remote statvfs: %s", fx2txt(status));
  else
   sshlog("sftp-client.c", __func__, 422, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "remote statvfs: %s", fx2txt(status));
  sshbuf_free(msg);
  return -1;
 } else if (type != 201) {
  sshfatal("sftp-client.c", __func__, 426, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Expected SSH2_FXP_EXTENDED_REPLY(%u) packet, got %u", 201, type)
                                    ;
 }

 memset(st, 0, sizeof(*st));
 if ((r = sshbuf_get_u64(msg, &st->f_bsize)) != 0 ||
     (r = sshbuf_get_u64(msg, &st->f_frsize)) != 0 ||
     (r = sshbuf_get_u64(msg, &st->f_blocks)) != 0 ||
     (r = sshbuf_get_u64(msg, &st->f_bfree)) != 0 ||
     (r = sshbuf_get_u64(msg, &st->f_bavail)) != 0 ||
     (r = sshbuf_get_u64(msg, &st->f_files)) != 0 ||
     (r = sshbuf_get_u64(msg, &st->f_ffree)) != 0 ||
     (r = sshbuf_get_u64(msg, &st->f_favail)) != 0 ||
     (r = sshbuf_get_u64(msg, &st->f_fsid)) != 0 ||
     (r = sshbuf_get_u64(msg, &flag)) != 0 ||
     (r = sshbuf_get_u64(msg, &st->f_namemax)) != 0)
  sshfatal("sftp-client.c", __func__, 442, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse statvfs");

 st->f_flag = (flag & 0x00000001) ? 
                                                   ST_RDONLY 
                                                             : 0;
 st->f_flag |= (flag & 0x00000002) ? 
                                                    ST_NOSUID 
                                                              : 0;

 sshbuf_free(msg);

 return 0;
}

struct sftp_conn *
do_init(int fd_in, int fd_out, u_int transfer_buflen, u_int num_requests,
    u_int64_t limit_kbps)
{
 u_char type;
 struct sshbuf *msg;
 struct sftp_conn *ret;
 int r;

 ret = xcalloc(1, sizeof(*ret));
 ret->msg_id = 1;
 ret->fd_in = fd_in;
 ret->fd_out = fd_out;
 ret->download_buflen = ret->upload_buflen =
     transfer_buflen ? transfer_buflen : 32768;
 ret->num_requests =
     num_requests ? num_requests : 64;
 ret->exts = 0;
 ret->limit_kbps = 0;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 473, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, 1)) != 0 ||
     (r = sshbuf_put_u32(msg, 3)) != 0)
  sshfatal("sftp-client.c", __func__, 476, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 send_msg(ret, msg);

 get_msg_extended(ret, msg, 1);


 if ((r = sshbuf_get_u8(msg, &type)) != 0)
  sshfatal("sftp-client.c", __func__, 484, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse type");
 if (type != 2) {
  sshlog("sftp-client.c", __func__, 486, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Invalid packet back from SSH2_FXP_INIT (type %u)", type)
           ;
  sshbuf_free(msg);
  free(ret);
  return(
        ((void *)0)
            );
 }
 if ((r = sshbuf_get_u32(msg, &ret->version)) != 0)
  sshfatal("sftp-client.c", __func__, 493, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse version");

 sshlog("sftp-client.c", __func__, 495, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "Remote version: %u", ret->version);


 while (sshbuf_len(msg) > 0) {
  char *name;
  u_char *value;
  size_t vlen;
  int known = 0;

  if ((r = sshbuf_get_cstring(msg, &name, 
                                         ((void *)0)
                                             )) != 0 ||
      (r = sshbuf_get_string(msg, &value, &vlen)) != 0)
   sshfatal("sftp-client.c", __func__, 506, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse extension");
  if (strcmp(name, "posix-rename@openssh.com") == 0 &&
      strcmp((char *)value, "1") == 0) {
   ret->exts |= 0x00000001;
   known = 1;
  } else if (strcmp(name, "statvfs@openssh.com") == 0 &&
      strcmp((char *)value, "2") == 0) {
   ret->exts |= 0x00000002;
   known = 1;
  } else if (strcmp(name, "fstatvfs@openssh.com") == 0 &&
      strcmp((char *)value, "2") == 0) {
   ret->exts |= 0x00000004;
   known = 1;
  } else if (strcmp(name, "hardlink@openssh.com") == 0 &&
      strcmp((char *)value, "1") == 0) {
   ret->exts |= 0x00000008;
   known = 1;
  } else if (strcmp(name, "fsync@openssh.com") == 0 &&
      strcmp((char *)value, "1") == 0) {
   ret->exts |= 0x00000010;
   known = 1;
  } else if (strcmp(name, "lsetstat@openssh.com") == 0 &&
      strcmp((char *)value, "1") == 0) {
   ret->exts |= 0x00000020;
   known = 1;
  } else if (strcmp(name, "limits@openssh.com") == 0 &&
      strcmp((char *)value, "1") == 0) {
   ret->exts |= 0x00000040;
   known = 1;
  } else if (strcmp(name, "expand-path@openssh.com") == 0 &&
      strcmp((char *)value, "1") == 0) {
   ret->exts |= 0x00000080;
   known = 1;
  } else if (strcmp(name, "copy-data") == 0 &&
      strcmp((char *)value, "1") == 0) {
   ret->exts |= 0x00000100;
   known = 1;
  } else if (strcmp(name,
      "users-groups-by-id@openssh.com") == 0 &&
      strcmp((char *)value, "1") == 0) {
   ret->exts |= 0x00000200;
   known = 1;
  }
  if (known) {
   sshlog("sftp-client.c", __func__, 550, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "Server supports extension \"%s\" revision %s", name, value)
                   ;
  } else {
   sshlog("sftp-client.c", __func__, 553, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "Unrecognised server extension \"%s\"", name);
  }
  free(name);
  free(value);
 }

 sshbuf_free(msg);


 if (ret->exts & 0x00000040) {
  struct sftp_limits limits;
  if (do_limits(ret, &limits) != 0)
   sshfatal("sftp-client.c", __func__, 565, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "limits failed");


  if (transfer_buflen == 0) {
   ret->download_buflen = limits.read_length;
   ret->upload_buflen = limits.write_length;
   sshlog("sftp-client.c", __func__, 571, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Using server download size %u", ret->download_buflen);
   sshlog("sftp-client.c", __func__, 572, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Using server upload size %u", ret->upload_buflen);
  }


  if (num_requests == 0 && limits.open_handles) {
   ret->num_requests =
       (((64) < (limits.open_handles)) ? (64) : (limits.open_handles));
   sshlog("sftp-client.c", __func__, 579, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Server handle limit %llu; using %u", (unsigned long long)limits.open_handles, ret->num_requests)

                         ;
  }
 }


 if (ret->version == 0) {
  ret->download_buflen = (((ret->download_buflen) < (20480)) ? (ret->download_buflen) : (20480));
  ret->upload_buflen = (((ret->upload_buflen) < (20480)) ? (ret->upload_buflen) : (20480));
 }

 ret->limit_kbps = limit_kbps;
 if (ret->limit_kbps > 0) {
  bandwidth_limit_init(&ret->bwlimit_in, ret->limit_kbps,
      ret->download_buflen);
  bandwidth_limit_init(&ret->bwlimit_out, ret->limit_kbps,
      ret->upload_buflen);
 }

 return ret;
}

u_int
sftp_proto_version(struct sftp_conn *conn)
{
 return conn->version;
}

int
do_limits(struct sftp_conn *conn, struct sftp_limits *limits)
{
 u_int id, msg_id;
 u_char type;
 struct sshbuf *msg;
 int r;

 if ((conn->exts & 0x00000040) == 0) {
  sshlog("sftp-client.c", __func__, 617, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Server does not support limits@openssh.com extension");
  return -1;
 }

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 622, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");

 id = conn->msg_id++;
 if ((r = sshbuf_put_u8(msg, 200)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_cstring(msg, "limits@openssh.com")) != 0)
  sshfatal("sftp-client.c", __func__, 628, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(conn, msg);
 sshlog("sftp-client.c", __func__, 630, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "Sent message limits@openssh.com I:%u", id);

 get_msg(conn, msg);

 if ((r = sshbuf_get_u8(msg, &type)) != 0 ||
     (r = sshbuf_get_u32(msg, &msg_id)) != 0)
  sshfatal("sftp-client.c", __func__, 636, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("sftp-client.c", __func__, 638, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "Received limits reply T:%u I:%u", type, msg_id);
 if (id != msg_id)
  sshfatal("sftp-client.c", __func__, 640, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ID mismatch (%u != %u)", msg_id, id);
 if (type != 201) {
  sshlog("sftp-client.c", __func__, 642, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "expected SSH2_FXP_EXTENDED_REPLY(%u) packet, got %u", 201, type)
                                    ;

  conn->exts &= ~0x00000040;
  sshbuf_free(msg);
  return 0;
 }

 memset(limits, 0, sizeof(*limits));
 if ((r = sshbuf_get_u64(msg, &limits->packet_length)) != 0 ||
     (r = sshbuf_get_u64(msg, &limits->read_length)) != 0 ||
     (r = sshbuf_get_u64(msg, &limits->write_length)) != 0 ||
     (r = sshbuf_get_u64(msg, &limits->open_handles)) != 0)
  sshfatal("sftp-client.c", __func__, 655, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse limits");

 sshbuf_free(msg);

 return 0;
}

int
do_close(struct sftp_conn *conn, const u_char *handle, u_int handle_len)
{
 u_int id, status;
 struct sshbuf *msg;
 int r;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 670, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");

 id = conn->msg_id++;
 if ((r = sshbuf_put_u8(msg, 4)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_string(msg, handle, handle_len)) != 0)
  sshfatal("sftp-client.c", __func__, 676, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 send_msg(conn, msg);
 sshlog("sftp-client.c", __func__, 678, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "Sent message SSH2_FXP_CLOSE I:%u", id);

 status = get_status(conn, id);
 if (status != 0)
  sshlog("sftp-client.c", __func__, 682, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "close remote: %s", fx2txt(status));

 sshbuf_free(msg);

 return status == 0 ? 0 : -1;
}


static int
do_lsreaddir(struct sftp_conn *conn, const char *path, int print_flag,
    SFTP_DIRENT ***dir)
{
 struct sshbuf *msg;
 u_int count, id, i, expected_id, ents = 0;
 size_t handle_len;
 u_char type, *handle;
 int status = 4;
 int r;

 if (dir)
  *dir = 
        ((void *)0)
            ;

 id = conn->msg_id++;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 707, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, 11)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_cstring(msg, path)) != 0)
  sshfatal("sftp-client.c", __func__, 711, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose OPENDIR");
 send_msg(conn, msg);

 handle = get_handle(conn, id, &handle_len,
     "remote readdir(\"%s\")", path);
 if (handle == 
              ((void *)0)
                  ) {
  sshbuf_free(msg);
  return -1;
 }

 if (dir) {
  ents = 0;
  *dir = xcalloc(1, sizeof(**dir));
  (*dir)[0] = 
             ((void *)0)
                 ;
 }

 for (; !interrupted;) {
  id = expected_id = conn->msg_id++;

  sshlog("sftp-client.c", __func__, 730, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "Sending SSH2_FXP_READDIR I:%u", id);

  sshbuf_reset(msg);
  if ((r = sshbuf_put_u8(msg, 12)) != 0 ||
      (r = sshbuf_put_u32(msg, id)) != 0 ||
      (r = sshbuf_put_string(msg, handle, handle_len)) != 0)
   sshfatal("sftp-client.c", __func__, 736, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose READDIR");
  send_msg(conn, msg);

  sshbuf_reset(msg);

  get_msg(conn, msg);

  if ((r = sshbuf_get_u8(msg, &type)) != 0 ||
      (r = sshbuf_get_u32(msg, &id)) != 0)
   sshfatal("sftp-client.c", __func__, 745, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

  sshlog("sftp-client.c", __func__, 747, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "Received reply T:%u I:%u", type, id);

  if (id != expected_id)
   sshfatal("sftp-client.c", __func__, 750, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "ID mismatch (%u != %u)", id, expected_id);

  if (type == 101) {
   u_int rstatus;

   if ((r = sshbuf_get_u32(msg, &rstatus)) != 0)
    sshfatal("sftp-client.c", __func__, 756, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse status");
   sshlog("sftp-client.c", __func__, 757, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "Received SSH2_FXP_STATUS %d", rstatus);
   if (rstatus == 1)
    break;
   sshlog("sftp-client.c", __func__, 760, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Couldn't read directory: %s", fx2txt(rstatus));
   goto out;
  } else if (type != 104)
   sshfatal("sftp-client.c", __func__, 763, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Expected SSH2_FXP_NAME(%u) packet, got %u", 104, type)
                           ;

  if ((r = sshbuf_get_u32(msg, &count)) != 0)
   sshfatal("sftp-client.c", __func__, 767, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse count");
  if (count > 0x8000000)
   sshfatal("sftp-client.c", __func__, 769, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "nonsensical number of entries");
  if (count == 0)
   break;
  sshlog("sftp-client.c", __func__, 772, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "Received %d SSH2_FXP_NAME responses", count);
  for (i = 0; i < count; i++) {
   char *filename, *longname;
   Attrib a;

   if ((r = sshbuf_get_cstring(msg, &filename,
       
      ((void *)0)
          )) != 0 ||
       (r = sshbuf_get_cstring(msg, &longname,
       
      ((void *)0)
          )) != 0)
    sshfatal("sftp-client.c", __func__, 781, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse filenames");
   if ((r = decode_attrib(msg, &a)) != 0) {
    sshlog("sftp-client.c", __func__, 783, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "couldn't decode attrib");
    free(filename);
    free(longname);
    goto out;
   }

   if (print_flag)
    mprintf("%s\n", longname);






   if (strpbrk(filename, "/") != 
                                                 ((void *)0)
                                                     ) {
    sshlog("sftp-client.c", __func__, 798, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Server sent suspect path \"%s\" " "during readdir of \"%s\"", filename, path)
                                                   ;
   } else if (dir) {
    *dir = xreallocarray(*dir, ents + 2, sizeof(**dir));
    (*dir)[ents] = xcalloc(1, sizeof(***dir));
    (*dir)[ents]->filename = xstrdup(filename);
    (*dir)[ents]->longname = xstrdup(longname);
    memcpy(&(*dir)[ents]->a, &a, sizeof(a));
    (*dir)[++ents] = 
                    ((void *)0)
                        ;
   }
   free(filename);
   free(longname);
  }
 }
 status = 0;

 out:
 sshbuf_free(msg);
 do_close(conn, handle, handle_len);
 free(handle);

 if (status != 0 && dir != 
                          ((void *)0)
                              ) {

  free_sftp_dirents(*dir);
  *dir = 
        ((void *)0)
            ;
 } else if (interrupted && dir != 
                                 ((void *)0) 
                                      && *dir != 
                                                 ((void *)0)
                                                     ) {

  free_sftp_dirents(*dir);
  *dir = xcalloc(1, sizeof(**dir));
  **dir = 
         ((void *)0)
             ;
 }

 return status == 0 ? 0 : -1;
}

int
do_readdir(struct sftp_conn *conn, const char *path, SFTP_DIRENT ***dir)
{
 return(do_lsreaddir(conn, path, 0, dir));
}

void free_sftp_dirents(SFTP_DIRENT **s)
{
 int i;

 if (s == 
         ((void *)0)
             )
  return;
 for (i = 0; s[i]; i++) {
  free(s[i]->filename);
  free(s[i]->longname);
  free(s[i]);
 }
 free(s);
}

int
do_rm(struct sftp_conn *conn, const char *path)
{
 u_int status, id;

 sshlog("sftp-client.c", __func__, 858, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "Sending SSH2_FXP_REMOVE \"%s\"", path);

 id = conn->msg_id++;
 send_string_request(conn, id, 13, path, strlen(path));
 status = get_status(conn, id);
 if (status != 0)
  sshlog("sftp-client.c", __func__, 864, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "remote delete %s: %s", path, fx2txt(status));
 return status == 0 ? 0 : -1;
}

int
do_mkdir(struct sftp_conn *conn, const char *path, Attrib *a, int print_flag)
{
 u_int status, id;

 sshlog("sftp-client.c", __func__, 873, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "Sending SSH2_FXP_MKDIR \"%s\"", path);

 id = conn->msg_id++;
 send_string_attrs_request(conn, id, 14, path,
     strlen(path), a);

 status = get_status(conn, id);
 if (status != 0 && print_flag)
  sshlog("sftp-client.c", __func__, 881, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "remote mkdir \"%s\": %s", path, fx2txt(status));

 return status == 0 ? 0 : -1;
}

int
do_rmdir(struct sftp_conn *conn, const char *path)
{
 u_int status, id;

 sshlog("sftp-client.c", __func__, 891, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "Sending SSH2_FXP_RMDIR \"%s\"", path);

 id = conn->msg_id++;
 send_string_request(conn, id, 15, path,
     strlen(path));

 status = get_status(conn, id);
 if (status != 0)
  sshlog("sftp-client.c", __func__, 899, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "remote rmdir \"%s\": %s", path, fx2txt(status));

 return status == 0 ? 0 : -1;
}

Attrib *
do_stat(struct sftp_conn *conn, const char *path, int quiet)
{
 u_int id;

 sshlog("sftp-client.c", __func__, 909, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "Sending SSH2_FXP_STAT \"%s\"", path);

 id = conn->msg_id++;

 send_string_request(conn, id,
     conn->version == 0 ? 7 : 17,
     path, strlen(path));

 return(get_decode_stat(conn, id, quiet));
}

Attrib *
do_lstat(struct sftp_conn *conn, const char *path, int quiet)
{
 u_int id;

 if (conn->version == 0) {
  if (quiet)
   sshlog("sftp-client.c", __func__, 927, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Server version does not support lstat operation");
  else
   sshlog("sftp-client.c", __func__, 929, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Server version does not support lstat operation");
  return(do_stat(conn, path, quiet));
 }

 id = conn->msg_id++;
 send_string_request(conn, id, 7, path,
     strlen(path));

 return(get_decode_stat(conn, id, quiet));
}
int
do_setstat(struct sftp_conn *conn, const char *path, Attrib *a)
{
 u_int status, id;

 sshlog("sftp-client.c", __func__, 962, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "Sending SSH2_FXP_SETSTAT \"%s\"", path);

 id = conn->msg_id++;
 send_string_attrs_request(conn, id, 9, path,
     strlen(path), a);

 status = get_status(conn, id);
 if (status != 0)
  sshlog("sftp-client.c", __func__, 970, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "remote setstat \"%s\": %s", path, fx2txt(status));

 return status == 0 ? 0 : -1;
}

int
do_fsetstat(struct sftp_conn *conn, const u_char *handle, u_int handle_len,
    Attrib *a)
{
 u_int status, id;

 sshlog("sftp-client.c", __func__, 981, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "Sending SSH2_FXP_FSETSTAT");

 id = conn->msg_id++;
 send_string_attrs_request(conn, id, 10, handle,
     handle_len, a);

 status = get_status(conn, id);
 if (status != 0)
  sshlog("sftp-client.c", __func__, 989, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "remote fsetstat: %s", fx2txt(status));

 return status == 0 ? 0 : -1;
}


static char *
do_realpath_expand(struct sftp_conn *conn, const char *path, int expand)
{
 struct sshbuf *msg;
 u_int expected_id, count, id;
 char *filename, *longname;
 Attrib a;
 u_char type;
 int r;
 const char *what = "SSH2_FXP_REALPATH";

 if (expand)
  what = "expand-path@openssh.com";
 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 1009, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");

 expected_id = id = conn->msg_id++;
 if (expand) {
  sshlog("sftp-client.c", __func__, 1013, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "Sending SSH2_FXP_EXTENDED(expand-path@openssh.com) " "\"%s\"", path)
                     ;
  if ((r = sshbuf_put_u8(msg, 200)) != 0 ||
      (r = sshbuf_put_u32(msg, id)) != 0 ||
      (r = sshbuf_put_cstring(msg,
      "expand-path@openssh.com")) != 0 ||
      (r = sshbuf_put_cstring(msg, path)) != 0)
   sshfatal("sftp-client.c", __func__, 1020, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose %s", what);
  send_msg(conn, msg);
 } else {
  sshlog("sftp-client.c", __func__, 1023, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "Sending SSH2_FXP_REALPATH \"%s\"", path);
  send_string_request(conn, id, 16,
      path, strlen(path));
 }
 get_msg(conn, msg);
 if ((r = sshbuf_get_u8(msg, &type)) != 0 ||
     (r = sshbuf_get_u32(msg, &id)) != 0)
  sshfatal("sftp-client.c", __func__, 1030, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 if (id != expected_id)
  sshfatal("sftp-client.c", __func__, 1033, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ID mismatch (%u != %u)", id, expected_id);

 if (type == 101) {
  u_int status;
  char *errmsg;

  if ((r = sshbuf_get_u32(msg, &status)) != 0 ||
      (r = sshbuf_get_cstring(msg, &errmsg, 
                                           ((void *)0)
                                               )) != 0)
   sshfatal("sftp-client.c", __func__, 1041, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse status");
  sshlog("sftp-client.c", __func__, 1042, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s %s: %s", expand ? "expand" : "realpath", path, *errmsg == '\0' ? fx2txt(status) : errmsg)
                                                      ;
  free(errmsg);
  sshbuf_free(msg);
  return 
        ((void *)0)
            ;
 } else if (type != 104)
  sshfatal("sftp-client.c", __func__, 1048, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Expected SSH2_FXP_NAME(%u) packet, got %u", 104, type)
                          ;

 if ((r = sshbuf_get_u32(msg, &count)) != 0)
  sshfatal("sftp-client.c", __func__, 1052, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse count");
 if (count != 1)
  sshfatal("sftp-client.c", __func__, 1054, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Got multiple names (%d) from %s", count, what);

 if ((r = sshbuf_get_cstring(msg, &filename, 
                                            ((void *)0)
                                                )) != 0 ||
     (r = sshbuf_get_cstring(msg, &longname, 
                                            ((void *)0)
                                                )) != 0 ||
     (r = decode_attrib(msg, &a)) != 0)
  sshfatal("sftp-client.c", __func__, 1059, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse filename/attrib");

 sshlog("sftp-client.c", __func__, 1061, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s %s -> %s", what, path, filename);

 free(longname);

 sshbuf_free(msg);

 return(filename);
}

char *
do_realpath(struct sftp_conn *conn, const char *path)
{
 return do_realpath_expand(conn, path, 0);
}

int
can_expand_path(struct sftp_conn *conn)
{
 return (conn->exts & 0x00000080) != 0;
}

char *
do_expand_path(struct sftp_conn *conn, const char *path)
{
 if (!can_expand_path(conn)) {
  sshlog("sftp-client.c", __func__, 1086, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "no server support, fallback to realpath");
  return do_realpath_expand(conn, path, 0);
 }
 return do_realpath_expand(conn, path, 1);
}

int
do_copy(struct sftp_conn *conn, const char *oldpath, const char *newpath)
{
 Attrib junk, *a;
 struct sshbuf *msg;
 u_char *old_handle, *new_handle;
 u_int mode, status, id;
 size_t old_handle_len, new_handle_len;
 int r;


 if ((conn->exts & 0x00000100) == 0) {
  sshlog("sftp-client.c", __func__, 1104, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Server does not support copy-data extension");
  return -1;
 }


 if ((a = do_stat(conn, oldpath, 0)) == 
                                       ((void *)0)
                                           )
  return -1;


 if (a->flags & 0x00000004) {
  mode = a->perm & 0777;

  if (!
      ((((
      a->perm
      )) & 0170000) == (0100000))
                      ) {
   sshlog("sftp-client.c", __func__, 1117, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Cannot copy non-regular file: %s", oldpath);
   return -1;
  }
 } else {

  mode = 0666;
 }


 attrib_clear(a);
 a->perm = mode;
 a->flags |= 0x00000004;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 1131, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: sshbuf_new failed", __func__);

 attrib_clear(&junk);


 id = conn->msg_id++;
 if ((r = sshbuf_put_u8(msg, 3)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_cstring(msg, oldpath)) != 0 ||
     (r = sshbuf_put_u32(msg, 0x00000001)) != 0 ||
     (r = encode_attrib(msg, &junk)) != 0)
  sshfatal("sftp-client.c", __func__, 1142, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: buffer error: %s", __func__, ssh_err(r));
 send_msg(conn, msg);
 sshlog("sftp-client.c", __func__, 1144, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "Sent message SSH2_FXP_OPEN I:%u P:%s", id, oldpath);

 sshbuf_reset(msg);

 old_handle = get_handle(conn, id, &old_handle_len,
     "remote open(\"%s\")", oldpath);
 if (old_handle == 
                  ((void *)0)
                      ) {
  sshbuf_free(msg);
  return -1;
 }


 id = conn->msg_id++;
 if ((r = sshbuf_put_u8(msg, 3)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_cstring(msg, newpath)) != 0 ||
     (r = sshbuf_put_u32(msg, 0x00000002|0x00000008|
     0x00000010)) != 0 ||
     (r = encode_attrib(msg, a)) != 0)
  sshfatal("sftp-client.c", __func__, 1163, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: buffer error: %s", __func__, ssh_err(r));
 send_msg(conn, msg);
 sshlog("sftp-client.c", __func__, 1165, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "Sent message SSH2_FXP_OPEN I:%u P:%s", id, newpath);

 sshbuf_reset(msg);

 new_handle = get_handle(conn, id, &new_handle_len,
     "remote open(\"%s\")", newpath);
 if (new_handle == 
                  ((void *)0)
                      ) {
  sshbuf_free(msg);
  free(old_handle);
  return -1;
 }


 id = conn->msg_id++;
 if ((r = sshbuf_put_u8(msg, 200)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_cstring(msg, "copy-data")) != 0 ||
     (r = sshbuf_put_string(msg, old_handle, old_handle_len)) != 0 ||
     (r = sshbuf_put_u64(msg, 0)) != 0 ||
     (r = sshbuf_put_u64(msg, 0)) != 0 ||
     (r = sshbuf_put_string(msg, new_handle, new_handle_len)) != 0 ||
     (r = sshbuf_put_u64(msg, 0)) != 0)
  sshfatal("sftp-client.c", __func__, 1187, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: buffer error: %s", __func__, ssh_err(r));
 send_msg(conn, msg);
 sshlog("sftp-client.c", __func__, 1189, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "Sent message copy-data \"%s\" 0 0 -> \"%s\" 0", oldpath, newpath)
                         ;

 status = get_status(conn, id);
 if (status != 0)
  sshlog("sftp-client.c", __func__, 1194, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Couldn't copy file \"%s\" to \"%s\": %s", oldpath, newpath, fx2txt(status))
                              ;


 sshbuf_free(msg);
 do_close(conn, old_handle, old_handle_len);
 do_close(conn, new_handle, new_handle_len);
 free(old_handle);
 free(new_handle);

 return status == 0 ? 0 : -1;
}

int
do_rename(struct sftp_conn *conn, const char *oldpath, const char *newpath,
    int force_legacy)
{
 struct sshbuf *msg;
 u_int status, id;
 int r, use_ext = (conn->exts & 0x00000001) && !force_legacy;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 1216, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");


 id = conn->msg_id++;
 if (use_ext) {
  sshlog("sftp-client.c", __func__, 1221, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "Sending SSH2_FXP_EXTENDED(posix-rename@openssh.com) " "\"%s\" to \"%s\"", oldpath, newpath)
                                           ;
  if ((r = sshbuf_put_u8(msg, 200)) != 0 ||
      (r = sshbuf_put_u32(msg, id)) != 0 ||
      (r = sshbuf_put_cstring(msg,
      "posix-rename@openssh.com")) != 0)
   sshfatal("sftp-client.c", __func__, 1227, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose posix-rename");
 } else {
  sshlog("sftp-client.c", __func__, 1229, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "Sending SSH2_FXP_RENAME \"%s\" to \"%s\"", oldpath, newpath)
                       ;
  if ((r = sshbuf_put_u8(msg, 18)) != 0 ||
      (r = sshbuf_put_u32(msg, id)) != 0)
   sshfatal("sftp-client.c", __func__, 1233, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose rename");
 }
 if ((r = sshbuf_put_cstring(msg, oldpath)) != 0 ||
     (r = sshbuf_put_cstring(msg, newpath)) != 0)
  sshfatal("sftp-client.c", __func__, 1237, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose paths");
 send_msg(conn, msg);
 sshlog("sftp-client.c", __func__, 1239, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "Sent message %s \"%s\" -> \"%s\"", use_ext ? "posix-rename@openssh.com" : "SSH2_FXP_RENAME", oldpath, newpath)

                                         ;
 sshbuf_free(msg);

 status = get_status(conn, id);
 if (status != 0)
  sshlog("sftp-client.c", __func__, 1246, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "remote rename \"%s\" to \"%s\": %s", oldpath, newpath, fx2txt(status))
                              ;

 return status == 0 ? 0 : -1;
}

int
do_hardlink(struct sftp_conn *conn, const char *oldpath, const char *newpath)
{
 struct sshbuf *msg;
 u_int status, id;
 int r;

 if ((conn->exts & 0x00000008) == 0) {
  sshlog("sftp-client.c", __func__, 1260, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Server does not support hardlink@openssh.com extension");
  return -1;
 }
 sshlog("sftp-client.c", __func__, 1263, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "Sending SSH2_FXP_EXTENDED(hardlink@openssh.com) " "\"%s\" to \"%s\"", oldpath, newpath)
                                          ;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 1267, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");


 id = conn->msg_id++;
 if ((r = sshbuf_put_u8(msg, 200)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_cstring(msg, "hardlink@openssh.com")) != 0 ||
     (r = sshbuf_put_cstring(msg, oldpath)) != 0 ||
     (r = sshbuf_put_cstring(msg, newpath)) != 0)
  sshfatal("sftp-client.c", __func__, 1276, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(conn, msg);
 sshlog("sftp-client.c", __func__, 1278, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "Sent message hardlink@openssh.com \"%s\" -> \"%s\"", oldpath, newpath)
                      ;
 sshbuf_free(msg);

 status = get_status(conn, id);
 if (status != 0)
  sshlog("sftp-client.c", __func__, 1284, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "remote link \"%s\" to \"%s\": %s", oldpath, newpath, fx2txt(status))
                              ;

 return status == 0 ? 0 : -1;
}

int
do_symlink(struct sftp_conn *conn, const char *oldpath, const char *newpath)
{
 struct sshbuf *msg;
 u_int status, id;
 int r;

 if (conn->version < 3) {
  sshlog("sftp-client.c", __func__, 1298, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "This server does not support the symlink operation");
  return(8);
 }
 sshlog("sftp-client.c", __func__, 1301, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "Sending SSH2_FXP_SYMLINK \"%s\" to \"%s\"", oldpath, newpath);

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 1304, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");


 id = conn->msg_id++;
 if ((r = sshbuf_put_u8(msg, 20)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_cstring(msg, oldpath)) != 0 ||
     (r = sshbuf_put_cstring(msg, newpath)) != 0)
  sshfatal("sftp-client.c", __func__, 1312, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(conn, msg);
 sshlog("sftp-client.c", __func__, 1314, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "Sent message SSH2_FXP_SYMLINK \"%s\" -> \"%s\"", oldpath, newpath)
             ;
 sshbuf_free(msg);

 status = get_status(conn, id);
 if (status != 0)
  sshlog("sftp-client.c", __func__, 1320, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "remote symlink file \"%s\" to \"%s\": %s", oldpath, newpath, fx2txt(status))
                              ;

 return status == 0 ? 0 : -1;
}

int
do_fsync(struct sftp_conn *conn, u_char *handle, u_int handle_len)
{
 struct sshbuf *msg;
 u_int status, id;
 int r;


 if ((conn->exts & 0x00000010) == 0)
  return -1;
 sshlog("sftp-client.c", __func__, 1336, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "Sending SSH2_FXP_EXTENDED(fsync@openssh.com)");


 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 1340, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 id = conn->msg_id++;
 if ((r = sshbuf_put_u8(msg, 200)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_cstring(msg, "fsync@openssh.com")) != 0 ||
     (r = sshbuf_put_string(msg, handle, handle_len)) != 0)
  sshfatal("sftp-client.c", __func__, 1346, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(conn, msg);
 sshlog("sftp-client.c", __func__, 1348, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "Sent message fsync@openssh.com I:%u", id);
 sshbuf_free(msg);

 status = get_status(conn, id);
 if (status != 0)
  sshlog("sftp-client.c", __func__, 1353, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "remote fsync: %s", fx2txt(status));

 return status == 0 ? 0 : -1;
}
int
do_statvfs(struct sftp_conn *conn, const char *path, struct sftp_statvfs *st,
    int quiet)
{
 struct sshbuf *msg;
 u_int id;
 int r;

 if ((conn->exts & 0x00000002) == 0) {
  sshlog("sftp-client.c", __func__, 1426, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Server does not support statvfs@openssh.com extension");
  return -1;
 }

 sshlog("sftp-client.c", __func__, 1430, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "Sending SSH2_FXP_EXTENDED(statvfs@openssh.com) \"%s\"", path);

 id = conn->msg_id++;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 1435, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, 200)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_cstring(msg, "statvfs@openssh.com")) != 0 ||
     (r = sshbuf_put_cstring(msg, path)) != 0)
  sshfatal("sftp-client.c", __func__, 1440, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(conn, msg);
 sshbuf_free(msg);

 return get_decode_statvfs(conn, st, id, quiet);
}
int
do_lsetstat(struct sftp_conn *conn, const char *path, Attrib *a)
{
 struct sshbuf *msg;
 u_int status, id;
 int r;

 if ((conn->exts & 0x00000020) == 0) {
  sshlog("sftp-client.c", __func__, 1486, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Server does not support lsetstat@openssh.com extension");
  return -1;
 }

 sshlog("sftp-client.c", __func__, 1490, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "Sending SSH2_FXP_EXTENDED(lsetstat@openssh.com) \"%s\"", path);

 id = conn->msg_id++;
 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 1494, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, 200)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_cstring(msg, "lsetstat@openssh.com")) != 0 ||
     (r = sshbuf_put_cstring(msg, path)) != 0 ||
     (r = encode_attrib(msg, a)) != 0)
  sshfatal("sftp-client.c", __func__, 1500, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(conn, msg);
 sshbuf_free(msg);

 status = get_status(conn, id);
 if (status != 0)
  sshlog("sftp-client.c", __func__, 1506, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "remote lsetstat \"%s\": %s", path, fx2txt(status));

 return status == 0 ? 0 : -1;
}

static void
send_read_request(struct sftp_conn *conn, u_int id, u_int64_t offset,
    u_int len, const u_char *handle, u_int handle_len)
{
 struct sshbuf *msg;
 int r;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 1519, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, 5)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_string(msg, handle, handle_len)) != 0 ||
     (r = sshbuf_put_u64(msg, offset)) != 0 ||
     (r = sshbuf_put_u32(msg, len)) != 0)
  sshfatal("sftp-client.c", __func__, 1525, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(conn, msg);
 sshbuf_free(msg);
}

static int
send_open(struct sftp_conn *conn, const char *path, const char *tag,
    u_int openmode, Attrib *a, u_char **handlep, size_t *handle_lenp)
{
 Attrib junk;
 u_char *handle;
 size_t handle_len;
 struct sshbuf *msg;
 int r;
 u_int id;

 sshlog("sftp-client.c", __func__, 1541, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "Sending SSH2_FXP_OPEN \"%s\"", path);

 *handlep = 
           ((void *)0)
               ;
 *handle_lenp = 0;

 if (a == 
         ((void *)0)
             ) {
  attrib_clear(&junk);
  a = &junk;
 }

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 1552, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 id = conn->msg_id++;
 if ((r = sshbuf_put_u8(msg, 3)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_cstring(msg, path)) != 0 ||
     (r = sshbuf_put_u32(msg, openmode)) != 0 ||
     (r = encode_attrib(msg, a)) != 0)
  sshfatal("sftp-client.c", __func__, 1559, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose %s open", tag);
 send_msg(conn, msg);
 sshbuf_free(msg);
 sshlog("sftp-client.c", __func__, 1562, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "Sent %s message SSH2_FXP_OPEN I:%u P:%s M:0x%04x", tag, id, path, openmode)
                             ;
 if ((handle = get_handle(conn, id, &handle_len,
     "%s open \"%s\"", tag, path)) == 
                                     ((void *)0)
                                         )
  return -1;

 *handlep = handle;
 *handle_lenp = handle_len;
 return 0;
}

static const char *
progress_meter_path(const char *path)
{
 const char *progresspath;

 if ((progresspath = strrchr(path, '/')) == 
                                           ((void *)0)
                                               )
  return path;
 progresspath++;
 if (*progresspath == '\0')
  return path;
 return progresspath;
}

int
do_download(struct sftp_conn *conn, const char *remote_path,
    const char *local_path, Attrib *a, int preserve_flag, int resume_flag,
    int fsync_flag, int inplace_flag)
{
 struct sshbuf *msg;
 u_char *handle;
 int local_fd = -1, write_error;
 int read_error, write_errno, lmodified = 0, reordered = 0, r;
 u_int64_t offset = 0, size, highwater;
 u_int mode, id, buflen, num_req, max_req, status = 0;
 off_t progress_counter;
 size_t handle_len;
 struct stat st;
 struct requests requests;
 struct request *req;
 u_char type;

 sshlog("sftp-client.c", __func__, 1604, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "download remote \"%s\" to local \"%s\"", remote_path, local_path)
                             ;

 do { (&requests)->tqh_first = 
((void *)0)
; (&requests)->tqh_last = &(&requests)->tqh_first; } while (0);

 if (a == 
         ((void *)0) 
              && (a = do_stat(conn, remote_path, 0)) == 
                                                        ((void *)0)
                                                            )
  return -1;


 if (a->flags & 0x00000004)
  mode = a->perm & 0777;
 else
  mode = 0666;

 if ((a->flags & 0x00000004) &&
     (!
      ((((
      a->perm
      )) & 0170000) == (0100000))
                      )) {
  sshlog("sftp-client.c", __func__, 1620, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "download %s: not a regular file", remote_path);
  return(-1);
 }

 if (a->flags & 0x00000001)
  size = a->size;
 else
  size = 0;

 buflen = conn->download_buflen;


 if (send_open(conn, remote_path, "remote", 0x00000001, 
                                                          ((void *)0)
                                                              ,
     &handle, &handle_len) != 0)
  return -1;

 local_fd = open(local_path, 
                            01 
                                     | 
                                       0100 
                                               |
 ((resume_flag || inplace_flag) ? 0 : 
                                     01000
                                            ), mode | 
                                                      0200
                                                             );
 if (local_fd == -1) {
  sshlog("sftp-client.c", __func__, 1639, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "open local \"%s\": %s", local_path, strerror(
 (*__errno_location ())
 ));
  goto fail;
 }
 offset = highwater = 0;
 if (resume_flag) {
  if (fstat(local_fd, &st) == -1) {
   sshlog("sftp-client.c", __func__, 1645, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "stat local \"%s\": %s", local_path, strerror(
  (*__errno_location ())
  ))
                                   ;
   goto fail;
  }
  if (st.st_size < 0) {
   sshlog("sftp-client.c", __func__, 1650, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "\"%s\" has negative size", local_path);
   goto fail;
  }
  if ((u_int64_t)st.st_size > size) {
   sshlog("sftp-client.c", __func__, 1654, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Unable to resume download of \"%s\": " "local file is larger than remote", local_path)
                                                      ;
 fail:
   do_close(conn, handle, handle_len);
   free(handle);
   if (local_fd != -1)
    close(local_fd);
   return -1;
  }
  offset = highwater = st.st_size;
 }


 write_error = read_error = write_errno = num_req = 0;
 max_req = 1;
 progress_counter = offset;

 if (showprogress && size != 0) {
  start_progress_meter(progress_meter_path(remote_path),
      size, &progress_counter);
 }

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 1677, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");

 while (num_req > 0 || max_req > 0) {
  u_char *data;
  size_t len;





  if (interrupted) {
   if (num_req == 0)
    break;
   max_req = 0;
  }


  while (num_req < max_req) {
   sshlog("sftp-client.c", __func__, 1695, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "Request range %llu -> %llu (%d/%d)", (unsigned long long)offset, (unsigned long long)offset + buflen - 1, num_req, max_req)


                        ;
   req = request_enqueue(&requests, conn->msg_id++,
       buflen, offset);
   offset += buflen;
   num_req++;
   send_read_request(conn, req->id, req->offset,
       req->len, handle, handle_len);
  }

  sshbuf_reset(msg);
  get_msg(conn, msg);
  if ((r = sshbuf_get_u8(msg, &type)) != 0 ||
      (r = sshbuf_get_u32(msg, &id)) != 0)
   sshfatal("sftp-client.c", __func__, 1711, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
  sshlog("sftp-client.c", __func__, 1712, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "Received reply T:%u I:%u R:%d", type, id, max_req);


  if ((req = request_find(&requests, id)) == 
                                            ((void *)0)
                                                )
   sshfatal("sftp-client.c", __func__, 1716, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Unexpected reply %u", id);

  switch (type) {
  case 101:
   if ((r = sshbuf_get_u32(msg, &status)) != 0)
    sshfatal("sftp-client.c", __func__, 1721, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse status");
   if (status != 1)
    read_error = 1;
   max_req = 0;
   do { if (((req)->tq.tqe_next) != 
  ((void *)0)
  ) (req)->tq.tqe_next->tq.tqe_prev = (req)->tq.tqe_prev; else (&requests)->tqh_last = (req)->tq.tqe_prev; *(req)->tq.tqe_prev = (req)->tq.tqe_next; ; ; } while (0);
   free(req);
   num_req--;
   break;
  case 103:
   if ((r = sshbuf_get_string(msg, &data, &len)) != 0)
    sshfatal("sftp-client.c", __func__, 1731, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse data");
   sshlog("sftp-client.c", __func__, 1732, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "Received data %llu -> %llu", (unsigned long long)req->offset, (unsigned long long)req->offset + len - 1)

                                                 ;
   if (len > req->len)
    sshfatal("sftp-client.c", __func__, 1736, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Received more data than asked for " "%zu > %zu", len, req->len)
                                   ;
   lmodified = 1;
   if ((lseek(local_fd, req->offset, 
                                    0
                                            ) == -1 ||
       atomicio((ssize_t (*)(int, void *, size_t))write, local_fd, data, len) != len) &&
       !write_error) {
    write_errno = 
                 (*__errno_location ())
                      ;
    write_error = 1;
    max_req = 0;
   }
   else if (!reordered && req->offset <= highwater)
    highwater = req->offset + len;
   else if (!reordered && req->offset > highwater)
    reordered = 1;
   progress_counter += len;
   free(data);

   if (len == req->len) {
    do { if (((req)->tq.tqe_next) != 
   ((void *)0)
   ) (req)->tq.tqe_next->tq.tqe_prev = (req)->tq.tqe_prev; else (&requests)->tqh_last = (req)->tq.tqe_prev; *(req)->tq.tqe_prev = (req)->tq.tqe_next; ; ; } while (0);
    free(req);
    num_req--;
   } else {

    sshlog("sftp-client.c", __func__, 1759, 0, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "Short data block, re-requesting " "%llu -> %llu (%2d)", (unsigned long long)req->offset + len, (unsigned long long)req->offset + req->len - 1, num_req)



                              ;
    req->id = conn->msg_id++;
    req->len -= len;
    req->offset += len;
    send_read_request(conn, req->id,
        req->offset, req->len, handle, handle_len);

    if (len < buflen)
     buflen = (((512) > (len)) ? (512) : (len));
   }
   if (max_req > 0) {
    if (size > 0 && offset > size) {


     sshlog("sftp-client.c", __func__, 1777, 0, SYSLOG_LEVEL_DEBUG3, 
    ((void *)0)
    , "Finish at %llu (%2d)", (unsigned long long)offset, num_req)

                 ;
     max_req = 1;
    } else if (max_req < conn->num_requests) {
     ++max_req;
    }
   }
   break;
  default:
   sshfatal("sftp-client.c", __func__, 1787, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Expected SSH2_FXP_DATA(%u) packet, got %u", 103, type)
                           ;
  }
 }

 if (showprogress && size)
  stop_progress_meter();


 if (((&requests)->tqh_first) != 
                              ((void *)0)
                                  )
  sshfatal("sftp-client.c", __func__, 1797, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Transfer complete, but requests still in queue");




 if (inplace_flag || read_error || write_error || interrupted) {
  if (reordered && resume_flag) {
   sshlog("sftp-client.c", __func__, 1804, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Unable to resume download of \"%s\": " "server reordered requests", local_path)
                                               ;
  }
  sshlog("sftp-client.c", __func__, 1807, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "truncating at %llu", (unsigned long long)highwater);
  if (ftruncate(local_fd, highwater) == -1)
   sshlog("sftp-client.c", __func__, 1809, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "local ftruncate \"%s\": %s", local_path, strerror(
  (*__errno_location ())
  ))
                       ;
 }
 if (read_error) {
  sshlog("sftp-client.c", __func__, 1813, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "read remote \"%s\" : %s", remote_path, fx2txt(status));
  status = -1;
  do_close(conn, handle, handle_len);
 } else if (write_error) {
  sshlog("sftp-client.c", __func__, 1817, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "write local \"%s\": %s", local_path, strerror(write_errno))
                            ;
  status = 4;
  do_close(conn, handle, handle_len);
 } else {
  if (do_close(conn, handle, handle_len) != 0 || interrupted)
   status = 4;
  else
   status = 0;


  if (preserve_flag && fchmod(local_fd, mode) == -1)



   sshlog("sftp-client.c", __func__, 1832, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "local chmod \"%s\": %s", local_path, strerror(
  (*__errno_location ())
  ))
                       ;
  if (preserve_flag &&
      (a->flags & 0x00000008)) {
   struct timeval tv[2];
   tv[0].tv_sec = a->atime;
   tv[1].tv_sec = a->mtime;
   tv[0].tv_usec = tv[1].tv_usec = 0;
   if (utimes(local_path, tv) == -1)
    sshlog("sftp-client.c", __func__, 1841, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "local set times \"%s\": %s", local_path, strerror(
   (*__errno_location ())
   ))
                                    ;
  }
  if (resume_flag && !lmodified)
   sshlog("sftp-client.c", __func__, 1845, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "File \"%s\" was not modified", local_path);
  else if (fsync_flag) {
   sshlog("sftp-client.c", __func__, 1847, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "syncing \"%s\"", local_path);
   if (fsync(local_fd) == -1)
    sshlog("sftp-client.c", __func__, 1849, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "local sync \"%s\": %s", local_path, strerror(
   (*__errno_location ())
   ))
                                    ;
  }
 }
 close(local_fd);
 sshbuf_free(msg);
 free(handle);

 return status == 0 ? 0 : -1;
}

static int
download_dir_internal(struct sftp_conn *conn, const char *src, const char *dst,
    int depth, Attrib *dirattrib, int preserve_flag, int print_flag,
    int resume_flag, int fsync_flag, int follow_link_flag, int inplace_flag)
{
 int i, ret = 0;
 SFTP_DIRENT **dir_entries;
 char *filename, *new_src = 
                           ((void *)0)
                               , *new_dst = 
                                            ((void *)0)
                                                ;
 mode_t mode = 0777, tmpmode = mode;

 if (depth >= 64) {
  sshlog("sftp-client.c", __func__, 1871, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Maximum directory depth exceeded: %d levels", depth);
  return -1;
 }

 sshlog("sftp-client.c", __func__, 1875, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "download dir remote \"%s\" to local \"%s\"", src, dst);

 if (dirattrib == 
                 ((void *)0) 
                      &&
     (dirattrib = do_stat(conn, src, 1)) == 
                                           ((void *)0)
                                               ) {
  sshlog("sftp-client.c", __func__, 1879, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "stat remote \"%s\" directory failed", src);
  return -1;
 }
 if (!
     ((((
     dirattrib->perm
     )) & 0170000) == (0040000))
                             ) {
  sshlog("sftp-client.c", __func__, 1883, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "\"%s\" is not a directory", src);
  return -1;
 }
 if (print_flag && print_flag != 2)
  mprintf("Retrieving %s\n", src);

 if (dirattrib->flags & 0x00000004) {
  mode = dirattrib->perm & 01777;
  tmpmode = mode | (
                   0200
                          |
                           0100
                                  );
 } else {
  sshlog("sftp-client.c", __func__, 1893, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "download remote \"%s\": server " "did not send permissions", dst)
                                      ;
 }

 if (mkdir(dst, tmpmode) == -1 && 
                                 (*__errno_location ()) 
                                       != 
                                          17
                                                ) {
  sshlog("sftp-client.c", __func__, 1898, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "mkdir %s: %s", dst, strerror(
 (*__errno_location ())
 ));
  return -1;
 }

 if (do_readdir(conn, src, &dir_entries) == -1) {
  sshlog("sftp-client.c", __func__, 1903, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "remote readdir \"%s\" failed", src);
  return -1;
 }

 for (i = 0; dir_entries[i] != 
                              ((void *)0) 
                                   && !interrupted; i++) {
  free(new_dst);
  free(new_src);

  filename = dir_entries[i]->filename;
  new_dst = path_append(dst, filename);
  new_src = path_append(src, filename);

  if (
     ((((
     dir_entries[i]->a.perm
     )) & 0170000) == (0040000))
                                    ) {
   if (strcmp(filename, ".") == 0 ||
       strcmp(filename, "..") == 0)
    continue;
   if (download_dir_internal(conn, new_src, new_dst,
       depth + 1, &(dir_entries[i]->a), preserve_flag,
       print_flag, resume_flag,
       fsync_flag, follow_link_flag, inplace_flag) == -1)
    ret = -1;
  } else if (
            ((((
            dir_entries[i]->a.perm
            )) & 0170000) == (0100000)) 
                                            ||
      (follow_link_flag && 
                          ((((
                          dir_entries[i]->a.perm
                          )) & 0170000) == (0120000))
                                                         )) {





   if (do_download(conn, new_src, new_dst,
       
      ((((
      dir_entries[i]->a.perm
      )) & 0170000) == (0120000)) 
                                      ? 
                                        ((void *)0) 
                                             :
       &(dir_entries[i]->a),
       preserve_flag, resume_flag, fsync_flag,
       inplace_flag) == -1) {
    sshlog("sftp-client.c", __func__, 1936, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Download of file %s to %s failed", new_src, new_dst)
                         ;
    ret = -1;
   }
  } else
   sshlog("sftp-client.c", __func__, 1941, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "download \"%s\": not a regular file", new_src);

 }
 free(new_dst);
 free(new_src);

 if (preserve_flag) {
  if (dirattrib->flags & 0x00000008) {
   struct timeval tv[2];
   tv[0].tv_sec = dirattrib->atime;
   tv[1].tv_sec = dirattrib->mtime;
   tv[0].tv_usec = tv[1].tv_usec = 0;
   if (utimes(dst, tv) == -1)
    sshlog("sftp-client.c", __func__, 1954, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "local set times on \"%s\": %s", dst, strerror(
   (*__errno_location ())
   ))
                             ;
  } else
   sshlog("sftp-client.c", __func__, 1957, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Server did not send times for directory " "\"%s\"", dst)
                     ;
 }

 if (mode != tmpmode && chmod(dst, mode) == -1)
  sshlog("sftp-client.c", __func__, 1962, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "local chmod directory \"%s\": %s", dst, strerror(
 (*__errno_location ())
 ))
                      ;

 free_sftp_dirents(dir_entries);

 return ret;
}

int
download_dir(struct sftp_conn *conn, const char *src, const char *dst,
    Attrib *dirattrib, int preserve_flag, int print_flag, int resume_flag,
    int fsync_flag, int follow_link_flag, int inplace_flag)
{
 char *src_canon;
 int ret;

 if ((src_canon = do_realpath(conn, src)) == 
                                            ((void *)0)
                                                ) {
  sshlog("sftp-client.c", __func__, 1979, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "download \"%s\": path canonicalization failed", src);
  return -1;
 }

 ret = download_dir_internal(conn, src_canon, dst, 0,
     dirattrib, preserve_flag, print_flag, resume_flag, fsync_flag,
     follow_link_flag, inplace_flag);
 free(src_canon);
 return ret;
}

int
do_upload(struct sftp_conn *conn, const char *local_path,
    const char *remote_path, int preserve_flag, int resume,
    int fsync_flag, int inplace_flag)
{
 int r, local_fd;
 u_int openmode, id, status = 0, reordered = 0;
 off_t offset, progress_counter;
 u_char type, *handle, *data;
 struct sshbuf *msg;
 struct stat sb;
 Attrib a, t, *c = 
                  ((void *)0)
                      ;
 u_int32_t startid, ackid;
 u_int64_t highwater = 0;
 struct request *ack = 
                      ((void *)0)
                          ;
 struct requests acks;
 size_t handle_len;

 sshlog("sftp-client.c", __func__, 2008, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "upload local \"%s\" to remote \"%s\"", local_path, remote_path)
                             ;

 do { (&acks)->tqh_first = 
((void *)0)
; (&acks)->tqh_last = &(&acks)->tqh_first; } while (0);

 if ((local_fd = open(local_path, 
                                 00
                                         )) == -1) {
  sshlog("sftp-client.c", __func__, 2014, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "open local \"%s\": %s", local_path, strerror(
 (*__errno_location ())
 ));
  return(-1);
 }
 if (fstat(local_fd, &sb) == -1) {
  sshlog("sftp-client.c", __func__, 2018, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "fstat local \"%s\": %s", local_path, strerror(
 (*__errno_location ())
 ));
  close(local_fd);
  return(-1);
 }
 if (!
     ((((
     sb.st_mode
     )) & 0170000) == (0100000))
                        ) {
  sshlog("sftp-client.c", __func__, 2023, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "local \"%s\" is not a regular file", local_path);
  close(local_fd);
  return(-1);
 }
 stat_to_attrib(&sb, &a);

 a.flags &= ~0x00000001;
 a.flags &= ~0x00000002;
 a.perm &= 0777;
 if (!preserve_flag)
  a.flags &= ~0x00000008;

 if (resume) {

  if ((c = do_stat(conn, remote_path, 0)) == 
                                            ((void *)0)
                                                ) {
   close(local_fd);
   return -1;
  }

  if ((off_t)c->size >= sb.st_size) {
   sshlog("sftp-client.c", __func__, 2043, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "resume \"%s\": destination file " "same size or larger", local_path)
                                         ;
   close(local_fd);
   return -1;
  }

  if (lseek(local_fd, (off_t)c->size, 
                                     0
                                             ) == -1) {
   close(local_fd);
   return -1;
  }
 }

 openmode = 0x00000002|0x00000008;
 if (resume)
  openmode |= 0x00000004;
 else if (!inplace_flag)
  openmode |= 0x00000010;


 if (send_open(conn, remote_path, "dest", openmode, &a,
     &handle, &handle_len) != 0) {
  close(local_fd);
  return -1;
 }

 id = conn->msg_id;
 startid = ackid = id + 1;
 data = xmalloc(conn->upload_buflen);


 offset = progress_counter = (resume ? c->size : 0);
 if (showprogress) {
  start_progress_meter(progress_meter_path(local_path),
      sb.st_size, &progress_counter);
 }

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 2080, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 for (;;) {
  int len;







  if (interrupted || status != 0)
   len = 0;
  else do
   len = read(local_fd, data, conn->upload_buflen);
  while ((len == -1) &&
      (
      (*__errno_location ()) 
            == 
               4 
                     || 
                        (*__errno_location ()) 
                              == 
                                 11 
                                        || 
                                           (*__errno_location ()) 
                                                 == 
                                                    11
                                                               ));

  if (len == -1) {
   sshfatal("sftp-client.c", __func__, 2098, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "read local \"%s\": %s", local_path, strerror(
  (*__errno_location ())
  ))
                                   ;
  } else if (len != 0) {
   ack = request_enqueue(&acks, ++id, len, offset);
   sshbuf_reset(msg);
   if ((r = sshbuf_put_u8(msg, 6)) != 0 ||
       (r = sshbuf_put_u32(msg, ack->id)) != 0 ||
       (r = sshbuf_put_string(msg, handle,
       handle_len)) != 0 ||
       (r = sshbuf_put_u64(msg, offset)) != 0 ||
       (r = sshbuf_put_string(msg, data, len)) != 0)
    sshfatal("sftp-client.c", __func__, 2109, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
   send_msg(conn, msg);
   sshlog("sftp-client.c", __func__, 2111, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "Sent message SSH2_FXP_WRITE I:%u O:%llu S:%u", id, (unsigned long long)offset, len)
                                           ;
  } else if (((&acks)->tqh_first) == 
                                  ((void *)0)
                                      )
   break;

  if (ack == 
            ((void *)0)
                )
   sshfatal("sftp-client.c", __func__, 2117, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Unexpected ACK %u", id);

  if (id == startid || len == 0 ||
      id - ackid >= conn->num_requests) {
   u_int rid;

   sshbuf_reset(msg);
   get_msg(conn, msg);
   if ((r = sshbuf_get_u8(msg, &type)) != 0 ||
       (r = sshbuf_get_u32(msg, &rid)) != 0)
    sshfatal("sftp-client.c", __func__, 2127, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

   if (type != 101)
    sshfatal("sftp-client.c", __func__, 2130, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Expected SSH2_FXP_STATUS(%d) packet, " "got %d", 101, type)
                                        ;

   if ((r = sshbuf_get_u32(msg, &status)) != 0)
    sshfatal("sftp-client.c", __func__, 2134, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse status");
   sshlog("sftp-client.c", __func__, 2135, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "SSH2_FXP_STATUS %u", status);


   if ((ack = request_find(&acks, rid)) == 
                                          ((void *)0)
                                              )
    sshfatal("sftp-client.c", __func__, 2139, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Can't find request for ID %u", rid);
   do { if (((ack)->tq.tqe_next) != 
  ((void *)0)
  ) (ack)->tq.tqe_next->tq.tqe_prev = (ack)->tq.tqe_prev; else (&acks)->tqh_last = (ack)->tq.tqe_prev; *(ack)->tq.tqe_prev = (ack)->tq.tqe_next; ; ; } while (0);
   sshlog("sftp-client.c", __func__, 2141, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "In write loop, ack for %u %zu bytes at %lld", ack->id, ack->len, (unsigned long long)ack->offset)
                                                          ;
   ++ackid;
   progress_counter += ack->len;
   if (!reordered && ack->offset <= highwater)
    highwater = ack->offset + ack->len;
   else if (!reordered && ack->offset > highwater) {
    sshlog("sftp-client.c", __func__, 2148, 1, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "server reordered ACKs");
    reordered = 1;
   }
   free(ack);
  }
  offset += len;
  if (offset < 0)
   sshfatal("sftp-client.c", __func__, 2155, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "offset < 0");
 }
 sshbuf_free(msg);

 if (showprogress)
  stop_progress_meter();
 free(data);

 if (status != 0) {
  sshlog("sftp-client.c", __func__, 2164, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "write remote \"%s\": %s", remote_path, fx2txt(status));
  status = 4;
 }

 if (inplace_flag || (resume && (status != 0 || interrupted))) {
  sshlog("sftp-client.c", __func__, 2169, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "truncating at %llu", (unsigned long long)highwater);
  attrib_clear(&t);
  t.flags = 0x00000001;
  t.size = highwater;
  do_fsetstat(conn, handle, handle_len, &t);
 }

 if (close(local_fd) == -1) {
  sshlog("sftp-client.c", __func__, 2177, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "close local \"%s\": %s", local_path, strerror(
 (*__errno_location ())
 ));
  status = 4;
 }


 if (preserve_flag)
  do_fsetstat(conn, handle, handle_len, &a);

 if (fsync_flag)
  (void)do_fsync(conn, handle, handle_len);

 if (do_close(conn, handle, handle_len) != 0)
  status = 4;

 free(handle);

 return status == 0 ? 0 : -1;
}

static int
upload_dir_internal(struct sftp_conn *conn, const char *src, const char *dst,
    int depth, int preserve_flag, int print_flag, int resume, int fsync_flag,
    int follow_link_flag, int inplace_flag)
{
 int ret = 0;
 DIR *dirp;
 struct dirent *dp;
 char *filename, *new_src = 
                           ((void *)0)
                               , *new_dst = 
                                            ((void *)0)
                                                ;
 struct stat sb;
 Attrib a, *dirattrib;
 u_int32_t saved_perm;

 sshlog("sftp-client.c", __func__, 2209, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "upload local dir \"%s\" to remote \"%s\"", src, dst);

 if (depth >= 64) {
  sshlog("sftp-client.c", __func__, 2212, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Maximum directory depth exceeded: %d levels", depth);
  return -1;
 }

 if (stat(src, &sb) == -1) {
  sshlog("sftp-client.c", __func__, 2217, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "stat local \"%s\": %s", src, strerror(
 (*__errno_location ())
 ));
  return -1;
 }
 if (!
     ((((
     sb.st_mode
     )) & 0170000) == (0040000))
                        ) {
  sshlog("sftp-client.c", __func__, 2221, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "\"%s\" is not a directory", src);
  return -1;
 }
 if (print_flag && print_flag != 2)
  mprintf("Entering %s\n", src);

 stat_to_attrib(&sb, &a);
 a.flags &= ~0x00000001;
 a.flags &= ~0x00000002;
 a.perm &= 01777;
 if (!preserve_flag)
  a.flags &= ~0x00000008;







 saved_perm = a.perm;
 a.perm |= (
           0200
                  |
                   0100
                          );
 if (do_mkdir(conn, dst, &a, 0) != 0) {
  if ((dirattrib = do_stat(conn, dst, 0)) == 
                                            ((void *)0)
                                                )
   return -1;
  if (!
      ((((
      dirattrib->perm
      )) & 0170000) == (0040000))
                              ) {
   sshlog("sftp-client.c", __func__, 2246, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "\"%s\" exists but is not a directory", dst);
   return -1;
  }
 }
 a.perm = saved_perm;

 if ((dirp = opendir(src)) == 
                             ((void *)0)
                                 ) {
  sshlog("sftp-client.c", __func__, 2253, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "local opendir \"%s\": %s", src, strerror(
 (*__errno_location ())
 ));
  return -1;
 }

 while (((dp = readdir(dirp)) != 
                                ((void *)0)
                                    ) && !interrupted) {
  if (dp->d_ino == 0)
   continue;
  free(new_dst);
  free(new_src);
  filename = dp->d_name;
  new_dst = path_append(dst, filename);
  new_src = path_append(src, filename);

  if (lstat(new_src, &sb) == -1) {
   sshlog("sftp-client.c", __func__, 2267, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "local lstat \"%s\": %s", filename, strerror(
  (*__errno_location ())
  ))
                       ;
   ret = -1;
  } else if (
            ((((
            sb.st_mode
            )) & 0170000) == (0040000))
                               ) {
   if (strcmp(filename, ".") == 0 ||
       strcmp(filename, "..") == 0)
    continue;

   if (upload_dir_internal(conn, new_src, new_dst,
       depth + 1, preserve_flag, print_flag, resume,
       fsync_flag, follow_link_flag, inplace_flag) == -1)
    ret = -1;
  } else if (
            ((((
            sb.st_mode
            )) & 0170000) == (0100000)) 
                                ||
      (follow_link_flag && 
                          ((((
                          sb.st_mode
                          )) & 0170000) == (0120000))
                                             )) {
   if (do_upload(conn, new_src, new_dst,
       preserve_flag, resume, fsync_flag,
       inplace_flag) == -1) {
    sshlog("sftp-client.c", __func__, 2284, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "upload \"%s\" to \"%s\" failed", new_src, new_dst)
                         ;
    ret = -1;
   }
  } else
   sshlog("sftp-client.c", __func__, 2289, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "%s: not a regular file", filename);
 }
 free(new_dst);
 free(new_src);

 do_setstat(conn, dst, &a);

 (void) closedir(dirp);
 return ret;
}

int
upload_dir(struct sftp_conn *conn, const char *src, const char *dst,
    int preserve_flag, int print_flag, int resume, int fsync_flag,
    int follow_link_flag, int inplace_flag)
{
 char *dst_canon;
 int ret;

 if ((dst_canon = do_realpath(conn, dst)) == 
                                            ((void *)0)
                                                ) {
  sshlog("sftp-client.c", __func__, 2309, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "upload \"%s\": path canonicalization failed", dst);
  return -1;
 }

 ret = upload_dir_internal(conn, src, dst_canon, 0, preserve_flag,
     print_flag, resume, fsync_flag, follow_link_flag, inplace_flag);

 free(dst_canon);
 return ret;
}

static void
handle_dest_replies(struct sftp_conn *to, const char *to_path, int synchronous,
    u_int *nreqsp, u_int *write_errorp)
{
 struct sshbuf *msg;
 u_char type;
 u_int id, status;
 int r;
 struct pollfd pfd;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 2331, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");


 while (*nreqsp > 0) {
  sshlog("sftp-client.c", __func__, 2335, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "%u outstanding replies", *nreqsp);
  if (!synchronous) {

   pfd.fd = to->fd_in;
   pfd.events = 
               0x001
                     ;
   if ((r = poll(&pfd, 1, 0)) == -1) {
    if (
       (*__errno_location ()) 
             == 
                4
                     )
     break;
    sshfatal("sftp-client.c", __func__, 2343, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "poll: %s", strerror(
   (*__errno_location ())
   ));
   } else if (r == 0)
    break;
  }
  sshbuf_reset(msg);
  get_msg(to, msg);

  if ((r = sshbuf_get_u8(msg, &type)) != 0 ||
      (r = sshbuf_get_u32(msg, &id)) != 0)
   sshfatal("sftp-client.c", __func__, 2352, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "dest parse");
  sshlog("sftp-client.c", __func__, 2353, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "Received dest reply T:%u I:%u R:%u", type, id, *nreqsp);
  if (type != 101) {
   sshfatal("sftp-client.c", __func__, 2355, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Expected SSH2_FXP_STATUS(%d) packet, got %d", 101, type)
                             ;
  }
  if ((r = sshbuf_get_u32(msg, &status)) != 0)
   sshfatal("sftp-client.c", __func__, 2359, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse dest status");
  sshlog("sftp-client.c", __func__, 2360, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "dest SSH2_FXP_STATUS %u", status);
  if (status != 0) {

   if (*write_errorp == 0)
    *write_errorp = status;
  }
  (*nreqsp)--;
 }
 sshlog("sftp-client.c", __func__, 2383, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "done: %u outstanding replies", *nreqsp);
 sshbuf_free(msg);
}

int
do_crossload(struct sftp_conn *from, struct sftp_conn *to,
    const char *from_path, const char *to_path,
    Attrib *a, int preserve_flag)
{
 struct sshbuf *msg;
 int write_error, read_error, r;
 u_int64_t offset = 0, size;
 u_int id, buflen, num_req, max_req, status = 0;
 u_int num_upload_req;
 off_t progress_counter;
 u_char *from_handle, *to_handle;
 size_t from_handle_len, to_handle_len;
 struct requests requests;
 struct request *req;
 u_char type;

 sshlog("sftp-client.c", __func__, 2404, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "crossload src \"%s\" to dst \"%s\"", from_path, to_path);

 do { (&requests)->tqh_first = 
((void *)0)
; (&requests)->tqh_last = &(&requests)->tqh_first; } while (0);

 if (a == 
         ((void *)0) 
              && (a = do_stat(from, from_path, 0)) == 
                                                      ((void *)0)
                                                          )
  return -1;

 if ((a->flags & 0x00000004) &&
     (!
      ((((
      a->perm
      )) & 0170000) == (0100000))
                      )) {
  sshlog("sftp-client.c", __func__, 2413, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "download \"%s\": not a regular file", from_path);
  return(-1);
 }
 if (a->flags & 0x00000001)
  size = a->size;
 else
  size = 0;

 buflen = from->download_buflen;
 if (buflen > to->upload_buflen)
  buflen = to->upload_buflen;


 if (send_open(from, from_path, "origin", 0x00000001, 
                                                        ((void *)0)
                                                            ,
     &from_handle, &from_handle_len) != 0)
  return -1;


 a->flags &= ~0x00000001;
 a->flags &= ~0x00000002;
 a->perm &= 0777;
 if (!preserve_flag)
  a->flags &= ~0x00000008;
 if (send_open(to, to_path, "dest",
     0x00000002|0x00000008|0x00000010, a,
     &to_handle, &to_handle_len) != 0) {
  do_close(from, from_handle, from_handle_len);
  return -1;
 }


 offset = 0;
 write_error = read_error = num_req = num_upload_req = 0;
 max_req = 1;
 progress_counter = 0;

 if (showprogress && size != 0) {
  start_progress_meter(progress_meter_path(from_path),
      size, &progress_counter);
 }
 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sftp-client.c", __func__, 2454, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 while (num_req > 0 || max_req > 0) {
  u_char *data;
  size_t len;





  if (interrupted) {
   if (num_req == 0)
    break;
   max_req = 0;
  }


  while (num_req < max_req) {
   sshlog("sftp-client.c", __func__, 2471, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "Request range %llu -> %llu (%d/%d)", (unsigned long long)offset, (unsigned long long)offset + buflen - 1, num_req, max_req)


                        ;
   req = request_enqueue(&requests, from->msg_id++,
       buflen, offset);
   offset += buflen;
   num_req++;
   send_read_request(from, req->id, req->offset,
       req->len, from_handle, from_handle_len);
  }


  handle_dest_replies(to, to_path, 0,
      &num_upload_req, &write_error);

  sshbuf_reset(msg);
  get_msg(from, msg);
  if ((r = sshbuf_get_u8(msg, &type)) != 0 ||
      (r = sshbuf_get_u32(msg, &id)) != 0)
   sshfatal("sftp-client.c", __func__, 2491, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
  sshlog("sftp-client.c", __func__, 2492, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "Received origin reply T:%u I:%u R:%d", type, id, max_req)
                        ;


  if ((req = request_find(&requests, id)) == 
                                            ((void *)0)
                                                )
   sshfatal("sftp-client.c", __func__, 2497, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Unexpected reply %u", id);

  switch (type) {
  case 101:
   if ((r = sshbuf_get_u32(msg, &status)) != 0)
    sshfatal("sftp-client.c", __func__, 2502, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse status");
   if (status != 1)
    read_error = 1;
   max_req = 0;
   do { if (((req)->tq.tqe_next) != 
  ((void *)0)
  ) (req)->tq.tqe_next->tq.tqe_prev = (req)->tq.tqe_prev; else (&requests)->tqh_last = (req)->tq.tqe_prev; *(req)->tq.tqe_prev = (req)->tq.tqe_next; ; ; } while (0);
   free(req);
   num_req--;
   break;
  case 103:
   if ((r = sshbuf_get_string(msg, &data, &len)) != 0)
    sshfatal("sftp-client.c", __func__, 2512, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse data");
   sshlog("sftp-client.c", __func__, 2513, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "Received data %llu -> %llu", (unsigned long long)req->offset, (unsigned long long)req->offset + len - 1)

                                                 ;
   if (len > req->len)
    sshfatal("sftp-client.c", __func__, 2517, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Received more data than asked for " "%zu > %zu", len, req->len)
                                   ;


   sshbuf_reset(msg);
   if ((r = sshbuf_put_u8(msg, 6)) != 0 ||
       (r = sshbuf_put_u32(msg, to->msg_id++)) != 0 ||
       (r = sshbuf_put_string(msg, to_handle,
       to_handle_len)) != 0 ||
       (r = sshbuf_put_u64(msg, req->offset)) != 0 ||
       (r = sshbuf_put_string(msg, data, len)) != 0)
    sshfatal("sftp-client.c", __func__, 2528, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose write");
   send_msg(to, msg);
   sshlog("sftp-client.c", __func__, 2530, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "Sent message SSH2_FXP_WRITE I:%u O:%llu S:%zu", id, (unsigned long long)offset, len)
                                           ;
   num_upload_req++;
   progress_counter += len;
   free(data);

   if (len == req->len) {
    do { if (((req)->tq.tqe_next) != 
   ((void *)0)
   ) (req)->tq.tqe_next->tq.tqe_prev = (req)->tq.tqe_prev; else (&requests)->tqh_last = (req)->tq.tqe_prev; *(req)->tq.tqe_prev = (req)->tq.tqe_next; ; ; } while (0);
    free(req);
    num_req--;
   } else {

    sshlog("sftp-client.c", __func__, 2542, 0, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "Short data block, re-requesting " "%llu -> %llu (%2d)", (unsigned long long)req->offset + len, (unsigned long long)req->offset + req->len - 1, num_req)



                              ;
    req->id = from->msg_id++;
    req->len -= len;
    req->offset += len;
    send_read_request(from, req->id,
        req->offset, req->len,
        from_handle, from_handle_len);

    if (len < buflen)
     buflen = (((512) > (len)) ? (512) : (len));
   }
   if (max_req > 0) {
    if (size > 0 && offset > size) {


     sshlog("sftp-client.c", __func__, 2561, 0, SYSLOG_LEVEL_DEBUG3, 
    ((void *)0)
    , "Finish at %llu (%2d)", (unsigned long long)offset, num_req)

                 ;
     max_req = 1;
    } else if (max_req < from->num_requests) {
     ++max_req;
    }
   }
   break;
  default:
   sshfatal("sftp-client.c", __func__, 2571, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Expected SSH2_FXP_DATA(%u) packet, got %u", 103, type)
                           ;
  }
 }

 if (showprogress && size)
  stop_progress_meter();


 sshlog("sftp-client.c", __func__, 2580, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "waiting for %u replies from destination", num_upload_req);
 handle_dest_replies(to, to_path, 1, &num_upload_req, &write_error);


 if (((&requests)->tqh_first) != 
                              ((void *)0)
                                  )
  sshfatal("sftp-client.c", __func__, 2585, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Transfer complete, but requests still in queue");

 if (read_error || write_error || interrupted) {
  sshlog("sftp-client.c", __func__, 2588, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "truncating \"%s\" at 0", to_path);
  do_close(to, to_handle, to_handle_len);
  free(to_handle);
  if (send_open(to, to_path, "dest",
      0x00000002|0x00000008|0x00000010, a,
      &to_handle, &to_handle_len) != 0) {
   sshlog("sftp-client.c", __func__, 2594, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "dest truncate \"%s\" failed", to_path);
   to_handle = 
              ((void *)0)
                  ;
  }
 }
 if (read_error) {
  sshlog("sftp-client.c", __func__, 2599, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "read origin \"%s\": %s", from_path, fx2txt(status));
  status = -1;
  do_close(from, from_handle, from_handle_len);
  if (to_handle != 
                  ((void *)0)
                      )
   do_close(to, to_handle, to_handle_len);
 } else if (write_error) {
  sshlog("sftp-client.c", __func__, 2605, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "write dest \"%s\": %s", to_path, fx2txt(write_error));
  status = 4;
  do_close(from, from_handle, from_handle_len);
  if (to_handle != 
                  ((void *)0)
                      )
   do_close(to, to_handle, to_handle_len);
 } else {
  if (do_close(from, from_handle, from_handle_len) != 0 ||
      interrupted)
   status = -1;
  else
   status = 0;
  if (to_handle != 
                  ((void *)0)
                      ) {

   if (preserve_flag)
    do_fsetstat(to, to_handle, to_handle_len, a);
   do_close(to, to_handle, to_handle_len);
  }
 }
 sshbuf_free(msg);
 free(from_handle);
 free(to_handle);

 return status == 0 ? 0 : -1;
}

static int
crossload_dir_internal(struct sftp_conn *from, struct sftp_conn *to,
    const char *from_path, const char *to_path,
    int depth, Attrib *dirattrib, int preserve_flag, int print_flag,
    int follow_link_flag)
{
 int i, ret = 0;
 SFTP_DIRENT **dir_entries;
 char *filename, *new_from_path = 
                                 ((void *)0)
                                     , *new_to_path = 
                                                      ((void *)0)
                                                          ;
 mode_t mode = 0777;
 Attrib curdir;

 sshlog("sftp-client.c", __func__, 2642, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "crossload dir src \"%s\" to dst \"%s\"", from_path, to_path);

 if (depth >= 64) {
  sshlog("sftp-client.c", __func__, 2645, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Maximum directory depth exceeded: %d levels", depth);
  return -1;
 }

 if (dirattrib == 
                 ((void *)0) 
                      &&
     (dirattrib = do_stat(from, from_path, 1)) == 
                                                 ((void *)0)
                                                     ) {
  sshlog("sftp-client.c", __func__, 2651, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "stat remote \"%s\" failed", from_path);
  return -1;
 }
 if (!
     ((((
     dirattrib->perm
     )) & 0170000) == (0040000))
                             ) {
  sshlog("sftp-client.c", __func__, 2655, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "\"%s\" is not a directory", from_path);
  return -1;
 }
 if (print_flag && print_flag != 2)
  mprintf("Retrieving %s\n", from_path);

 curdir = *dirattrib;
 curdir.flags &= ~0x00000001;
 curdir.flags &= ~0x00000002;
 if ((curdir.flags & 0x00000004) == 0) {
  sshlog("sftp-client.c", __func__, 2665, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Origin did not send permissions for " "directory \"%s\"", to_path)
                                  ;
  curdir.perm = 
               0200
                      |
                       0100
                              ;
  curdir.flags |= 0x00000004;
 }

 mode = curdir.perm & 01777;
 curdir.perm = mode | (
                      0200
                             |
                              0100
                                     );







 if (do_mkdir(to, to_path, &curdir, 0) != 0) {
  if ((dirattrib = do_stat(to, to_path, 0)) == 
                                              ((void *)0)
                                                  )
   return -1;
  if (!
      ((((
      dirattrib->perm
      )) & 0170000) == (0040000))
                              ) {
   sshlog("sftp-client.c", __func__, 2684, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "\"%s\" exists but is not a directory", to_path);
   return -1;
  }
 }
 curdir.perm = mode;

 if (do_readdir(from, from_path, &dir_entries) == -1) {
  sshlog("sftp-client.c", __func__, 2691, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "origin readdir \"%s\" failed", from_path);
  return -1;
 }

 for (i = 0; dir_entries[i] != 
                              ((void *)0) 
                                   && !interrupted; i++) {
  free(new_from_path);
  free(new_to_path);

  filename = dir_entries[i]->filename;
  new_from_path = path_append(from_path, filename);
  new_to_path = path_append(to_path, filename);

  if (
     ((((
     dir_entries[i]->a.perm
     )) & 0170000) == (0040000))
                                    ) {
   if (strcmp(filename, ".") == 0 ||
       strcmp(filename, "..") == 0)
    continue;
   if (crossload_dir_internal(from, to,
       new_from_path, new_to_path,
       depth + 1, &(dir_entries[i]->a), preserve_flag,
       print_flag, follow_link_flag) == -1)
    ret = -1;
  } else if (
            ((((
            dir_entries[i]->a.perm
            )) & 0170000) == (0100000)) 
                                            ||
      (follow_link_flag && 
                          ((((
                          dir_entries[i]->a.perm
                          )) & 0170000) == (0120000))
                                                         )) {





   if (do_crossload(from, to, new_from_path, new_to_path,
       
      ((((
      dir_entries[i]->a.perm
      )) & 0170000) == (0120000)) 
                                      ? 
                                        ((void *)0) 
                                             :
       &(dir_entries[i]->a), preserve_flag) == -1) {
    sshlog("sftp-client.c", __func__, 2722, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "crossload \"%s\" to \"%s\" failed", new_from_path, new_to_path)
                                   ;
    ret = -1;
   }
  } else {
   sshlog("sftp-client.c", __func__, 2727, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "origin \"%s\": not a regular file", new_from_path)
                     ;
  }
 }
 free(new_to_path);
 free(new_from_path);

 do_setstat(to, to_path, &curdir);

 free_sftp_dirents(dir_entries);

 return ret;
}

int
crossload_dir(struct sftp_conn *from, struct sftp_conn *to,
    const char *from_path, const char *to_path,
    Attrib *dirattrib, int preserve_flag, int print_flag, int follow_link_flag)
{
 char *from_path_canon;
 int ret;

 if ((from_path_canon = do_realpath(from, from_path)) == 
                                                        ((void *)0)
                                                            ) {
  sshlog("sftp-client.c", __func__, 2750, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "crossload \"%s\": path canonicalization failed", from_path)
                ;
  return -1;
 }

 ret = crossload_dir_internal(from, to, from_path_canon, to_path, 0,
     dirattrib, preserve_flag, print_flag, follow_link_flag);
 free(from_path_canon);
 return ret;
}

int
can_get_users_groups_by_id(struct sftp_conn *conn)
{
 return (conn->exts & 0x00000200) != 0;
}

int
do_get_users_groups_by_id(struct sftp_conn *conn,
    const u_int *uids, u_int nuids,
    const u_int *gids, u_int ngids,
    char ***usernamesp, char ***groupnamesp)
{
 struct sshbuf *msg, *uidbuf, *gidbuf;
 u_int i, expected_id, id;
 char *name, **usernames = 
                          ((void *)0)
                              , **groupnames = 
                                               ((void *)0)
                                                   ;
 u_char type;
 int r;

 *usernamesp = *groupnamesp = 
                             ((void *)0)
                                 ;
 if (!can_get_users_groups_by_id(conn))
  return -59;

 if ((msg = sshbuf_new()) == 
                            ((void *)0) 
                                 ||
     (uidbuf = sshbuf_new()) == 
                               ((void *)0) 
                                    ||
     (gidbuf = sshbuf_new()) == 
                               ((void *)0)
                                   )
  sshfatal("sftp-client.c", __func__, 2786, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 expected_id = id = conn->msg_id++;
 sshlog("sftp-client.c", __func__, 2788, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "Sending SSH2_FXP_EXTENDED(users-groups-by-id@openssh.com)");
 for (i = 0; i < nuids; i++) {
  if ((r = sshbuf_put_u32(uidbuf, uids[i])) != 0)
   sshfatal("sftp-client.c", __func__, 2791, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose uids");
 }
 for (i = 0; i < ngids; i++) {
  if ((r = sshbuf_put_u32(gidbuf, gids[i])) != 0)
   sshfatal("sftp-client.c", __func__, 2795, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose gids");
 }
 if ((r = sshbuf_put_u8(msg, 200)) != 0 ||
     (r = sshbuf_put_u32(msg, id)) != 0 ||
     (r = sshbuf_put_cstring(msg,
     "users-groups-by-id@openssh.com")) != 0 ||
     (r = sshbuf_put_stringb(msg, uidbuf)) != 0 ||
     (r = sshbuf_put_stringb(msg, gidbuf)) != 0)
  sshfatal("sftp-client.c", __func__, 2803, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 send_msg(conn, msg);
 get_msg(conn, msg);
 if ((r = sshbuf_get_u8(msg, &type)) != 0 ||
     (r = sshbuf_get_u32(msg, &id)) != 0)
  sshfatal("sftp-client.c", __func__, 2808, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 if (id != expected_id)
  sshfatal("sftp-client.c", __func__, 2810, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ID mismatch (%u != %u)", id, expected_id);
 if (type == 101) {
  u_int status;
  char *errmsg;

  if ((r = sshbuf_get_u32(msg, &status)) != 0 ||
      (r = sshbuf_get_cstring(msg, &errmsg, 
                                           ((void *)0)
                                               )) != 0)
   sshfatal("sftp-client.c", __func__, 2817, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse status");
  sshlog("sftp-client.c", __func__, 2818, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "users-groups-by-id %s", *errmsg == '\0' ? fx2txt(status) : errmsg)
                                                ;
  free(errmsg);
  sshbuf_free(msg);
  sshbuf_free(uidbuf);
  sshbuf_free(gidbuf);
  return -1;
 } else if (type != 201)
  sshfatal("sftp-client.c", __func__, 2826, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Expected SSH2_FXP_EXTENDED_REPLY(%u) packet, got %u", 201, type)
                                    ;


 sshbuf_free(uidbuf);
 sshbuf_free(gidbuf);
 uidbuf = gidbuf = 
                  ((void *)0)
                      ;
 if ((r = sshbuf_froms(msg, &uidbuf)) != 0 ||
     (r = sshbuf_froms(msg, &gidbuf)) != 0)
  sshfatal("sftp-client.c", __func__, 2835, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse response");
 if (nuids > 0) {
  usernames = xcalloc(nuids, sizeof(*usernames));
  for (i = 0; i < nuids; i++) {
   if ((r = sshbuf_get_cstring(uidbuf, &name, 
                                             ((void *)0)
                                                 )) != 0)
    sshfatal("sftp-client.c", __func__, 2840, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse user name");

   if (*name == '\0') {
    free(name);
    name = 
          ((void *)0)
              ;
   }
   usernames[i] = name;
  }
 }
 if (ngids > 0) {
  groupnames = xcalloc(ngids, sizeof(*groupnames));
  for (i = 0; i < ngids; i++) {
   if ((r = sshbuf_get_cstring(gidbuf, &name, 
                                             ((void *)0)
                                                 )) != 0)
    sshfatal("sftp-client.c", __func__, 2853, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse user name");

   if (*name == '\0') {
    free(name);
    name = 
          ((void *)0)
              ;
   }
   groupnames[i] = name;
  }
 }
 if (sshbuf_len(uidbuf) != 0)
  sshfatal("sftp-client.c", __func__, 2863, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "unexpected extra username data");
 if (sshbuf_len(gidbuf) != 0)
  sshfatal("sftp-client.c", __func__, 2865, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "unexpected extra groupname data");
 sshbuf_free(uidbuf);
 sshbuf_free(gidbuf);
 sshbuf_free(msg);

 *usernamesp = usernames;
 *groupnamesp = groupnames;
 return 0;
}

char *
path_append(const char *p1, const char *p2)
{
 char *ret;
 size_t len = strlen(p1) + strlen(p2) + 2;

 ret = xmalloc(len);
 strlcpy(ret, p1, len);
 if (p1[0] != '\0' && p1[strlen(p1) - 1] != '/')
  strlcat(ret, "/", len);
 strlcat(ret, p2, len);

 return(ret);
}

char *
make_absolute(char *p, const char *pwd)
{
 char *abs_str;


 if (p && !path_absolute(p)) {
  abs_str = path_append(pwd, p);
  free(p);
  return(abs_str);
 } else
  return(p);
}

int
remote_is_dir(struct sftp_conn *conn, const char *path)
{
 Attrib *a;


 if ((a = do_stat(conn, path, 1)) == 
                                    ((void *)0)
                                        )
  return(0);
 if (!(a->flags & 0x00000004))
  return(0);
 return(
       ((((
       a->perm
       )) & 0170000) == (0040000))
                       );
}


int
local_is_dir(const char *path)
{
 struct stat sb;


 if (stat(path, &sb) == -1)
  return(0);

 return(
       ((((
       sb.st_mode
       )) & 0170000) == (0040000))
                          );
}


int
globpath_is_dir(const char *pathname)
{
 size_t l = strlen(pathname);

 return l > 0 && pathname[l - 1] == '/';
}
