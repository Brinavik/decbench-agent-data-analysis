











































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






















typedef void EditLine;










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
void get_remote_user_groups_from_glob(struct sftp_conn *conn, _ssh_compat_glob_t *g);
void get_remote_user_groups_from_dirents(struct sftp_conn *conn, SFTP_DIRENT **d);


const char *ruser_name(uid_t uid);
const char *rgroup_name(uid_t gid);


FILE* infile;


int batchmode = 0;


static volatile pid_t sshpid = -1;


int quiet = 0;


int showprogress = 1;


int global_rflag = 0;


int global_aflag = 0;


int global_pflag = 0;


int global_fflag = 0;


volatile sig_atomic_t interrupted = 0;


int sort_flag;
_ssh_compat_glob_t *sort_glob;


struct complete_ctx {
 struct sftp_conn *conn;
 char **remote_pathp;
};

int remote_glob(struct sftp_conn *, const char *, int,
    int (*)(const char *, int), _ssh_compat_glob_t *);

extern char *__progname;
enum sftp_command {
 I_CHDIR = 1,
 I_CHGRP,
 I_CHMOD,
 I_CHOWN,
 I_COPY,
 I_DF,
 I_GET,
 I_HELP,
 I_LCHDIR,
 I_LINK,
 I_LLS,
 I_LMKDIR,
 I_LPWD,
 I_LS,
 I_LUMASK,
 I_MKDIR,
 I_PUT,
 I_PWD,
 I_QUIT,
 I_REGET,
 I_RENAME,
 I_REPUT,
 I_RM,
 I_RMDIR,
 I_SHELL,
 I_SYMLINK,
 I_VERSION,
 I_PROGRESS,
};

struct CMD {
 const char *c;
 const int n;
 const int t;
 const int t2;
};






static const struct CMD cmds[] = {
 { "bye", I_QUIT, 0, 0 },
 { "cd", I_CHDIR, 1, 0 },
 { "chdir", I_CHDIR, 1, 0 },
 { "chgrp", I_CHGRP, 1, 0 },
 { "chmod", I_CHMOD, 1, 0 },
 { "chown", I_CHOWN, 1, 0 },
 { "copy", I_COPY, 1, 2 },
 { "cp", I_COPY, 1, 2 },
 { "df", I_DF, 1, 0 },
 { "dir", I_LS, 1, 0 },
 { "exit", I_QUIT, 0, 0 },
 { "get", I_GET, 1, 2 },
 { "help", I_HELP, 0, 0 },
 { "lcd", I_LCHDIR, 2, 0 },
 { "lchdir", I_LCHDIR, 2, 0 },
 { "lls", I_LLS, 2, 0 },
 { "lmkdir", I_LMKDIR, 2, 0 },
 { "ln", I_LINK, 1, 1 },
 { "lpwd", I_LPWD, 2, 0 },
 { "ls", I_LS, 1, 0 },
 { "lumask", I_LUMASK, 0, 0 },
 { "mkdir", I_MKDIR, 1, 0 },
 { "mget", I_GET, 1, 2 },
 { "mput", I_PUT, 2, 1 },
 { "progress", I_PROGRESS, 0, 0 },
 { "put", I_PUT, 2, 1 },
 { "pwd", I_PWD, 1, 0 },
 { "quit", I_QUIT, 0, 0 },
 { "reget", I_REGET, 1, 2 },
 { "rename", I_RENAME, 1, 1 },
 { "reput", I_REPUT, 2, 1 },
 { "rm", I_RM, 1, 0 },
 { "rmdir", I_RMDIR, 1, 0 },
 { "symlink", I_SYMLINK, 1, 1 },
 { "version", I_VERSION, 0, 0 },
 { "!", I_SHELL, 0, 0 },
 { "?", I_HELP, 0, 0 },
 { 
  ((void *)0)
      , -1, -1, -1 }
};


static void
killchild(int signo)
{
 pid_t pid;

 pid = sshpid;
 if (pid > 1) {
  kill(pid, 
           15
                  );
  waitpid(pid, 
              ((void *)0)
                  , 0);
 }

 _exit(1);
}


static void
suspchild(int signo)
{
 if (sshpid > 1) {
  kill(sshpid, signo);
  while (waitpid(sshpid, 
                        ((void *)0)
                            , 
                              2
                                       ) == -1 && 
                                                  (*__errno_location ()) 
                                                        == 
                                                           4
                                                                )
   continue;
 }
 kill(getpid(), 
               19
                      );
}


static void
cmd_interrupt(int signo)
{
 const char msg[] = "\rInterrupt  \n";
 int olderrno = 
               (*__errno_location ())
                    ;

 (void)write(
            2
                         , msg, sizeof(msg) - 1);
 interrupted = 1;
 
(*__errno_location ()) 
      = olderrno;
}


static void
read_interrupt(int signo)
{
 interrupted = 1;
}


static void
sigchld_handler(int sig)
{
 int save_errno = 
                 (*__errno_location ())
                      ;
 pid_t pid;
 const char msg[] = "\rConnection closed.  \n";


 while ((pid = waitpid(sshpid, 
                              ((void *)0)
                                  , 
                                    1
                                           )) == -1 && 
                                                       (*__errno_location ()) 
                                                             == 
                                                                4
                                                                     )
  continue;
 if (pid == sshpid) {
  (void)write(
             2
                          , msg, sizeof(msg) - 1);
  sshpid = -1;
 }

 
(*__errno_location ()) 
      = save_errno;
}

static void
help(void)
{
 printf("Available commands:\n"
     "bye                                Quit sftp\n"
     "cd path                            Change remote directory to 'path'\n"
     "chgrp [-h] grp path                Change group of file 'path' to 'grp'\n"
     "chmod [-h] mode path               Change permissions of file 'path' to 'mode'\n"
     "chown [-h] own path                Change owner of file 'path' to 'own'\n"
     "copy oldpath newpath               Copy remote file\n"
     "cp oldpath newpath                 Copy remote file\n"
     "df [-hi] [path]                    Display statistics for current directory or\n"
     "                                   filesystem containing 'path'\n"
     "exit                               Quit sftp\n"
     "get [-afpR] remote [local]         Download file\n"
     "help                               Display this help text\n"
     "lcd path                           Change local directory to 'path'\n"
     "lls [ls-options [path]]            Display local directory listing\n"
     "lmkdir path                        Create local directory\n"
     "ln [-s] oldpath newpath            Link remote file (-s for symlink)\n"
     "lpwd                               Print local working directory\n"
     "ls [-1afhlnrSt] [path]             Display remote directory listing\n"
     "lumask umask                       Set local umask to 'umask'\n"
     "mkdir path                         Create remote directory\n"
     "progress                           Toggle display of progress meter\n"
     "put [-afpR] local [remote]         Upload file\n"
     "pwd                                Display remote working directory\n"
     "quit                               Quit sftp\n"
     "reget [-fpR] remote [local]        Resume download file\n"
     "rename oldpath newpath             Rename remote file\n"
     "reput [-fpR] local [remote]        Resume upload file\n"
     "rm path                            Delete remote file\n"
     "rmdir path                         Remove remote directory\n"
     "symlink oldpath newpath            Symlink remote file\n"
     "version                            Show SFTP version\n"
     "!command                           Execute 'command' in local shell\n"
     "!                                  Escape to local shell\n"
     "?                                  Synonym for help\n");
}

static void
local_do_shell(const char *args)
{
 int status;
 char *shell;
 pid_t pid;

 if (!*args)
  args = 
        ((void *)0)
            ;

 if ((shell = getenv("SHELL")) == 
                                 ((void *)0) 
                                      || *shell == '\0')
  shell = 
         "/bin/sh"
                     ;

 if ((pid = fork()) == -1)
  sshfatal("sftp.c", __func__, 339, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Couldn't fork: %s", strerror(
 (*__errno_location ())
 ));

 if (pid == 0) {

  if (args) {
   sshlog("sftp.c", __func__, 344, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "Executing %s -c \"%s\"", shell, args);
   execl(shell, shell, "-c", args, (char *)
                                          ((void *)0)
                                              );
  } else {
   sshlog("sftp.c", __func__, 347, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "Executing %s", shell);
   execl(shell, shell, (char *)
                              ((void *)0)
                                  );
  }
  fprintf(
         stderr
               , "Couldn't execute \"%s\": %s\n", shell,
      strerror(
              (*__errno_location ())
                   ));
  _exit(1);
 }
 while (waitpid(pid, &status, 0) == -1)
  if (
     (*__errno_location ()) 
           != 
              4
                   )
   sshfatal("sftp.c", __func__, 356, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Couldn't wait for child: %s", strerror(
  (*__errno_location ())
  ));
 if (!
     (((
     status
     ) & 0x7f) == 0)
                      )
  sshlog("sftp.c", __func__, 358, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Shell exited abnormally");
 else if (
         (((
         status
         ) & 0xff00) >> 8)
                            )
  sshlog("sftp.c", __func__, 360, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Shell exited with status %d", 
 (((
 status
 ) & 0xff00) >> 8)
 );
}

static void
local_do_ls(const char *args)
{
 if (!args || !*args)
  local_do_shell("ls");
 else {
  int len = strlen("ls" " ") + strlen(args) + 1;
  char *buf = xmalloc(len);


  snprintf(buf, len, "ls" " %s", args);
  local_do_shell(buf);
  free(buf);
 }
}


static char *
path_strip(const char *path, const char *strip)
{
 size_t len;

 if (strip == 
             ((void *)0)
                 )
  return (xstrdup(path));

 len = strlen(strip);
 if (strncmp(path, strip, len) == 0) {
  if (strip[len - 1] != '/' && path[len] == '/')
   len++;
  return (xstrdup(path + len));
 }

 return (xstrdup(path));
}

static int
parse_getput_flags(const char *cmd, char **argv, int argc,
    int *aflag, int *fflag, int *pflag, int *rflag)
{
 extern int BSDopterr, BSDoptind, BSDoptopt, BSDoptreset;
 int ch;

 BSDoptind = BSDoptreset = 1;
 BSDopterr = 0;

 *aflag = *fflag = *rflag = *pflag = 0;
 while ((ch = BSDgetopt(argc, argv, "afPpRr")) != -1) {
  switch (ch) {
  case 'a':
   *aflag = 1;
   break;
  case 'f':
   *fflag = 1;
   break;
  case 'p':
  case 'P':
   *pflag = 1;
   break;
  case 'r':
  case 'R':
   *rflag = 1;
   break;
  default:
   sshlog("sftp.c", __func__, 426, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: Invalid flag -%c", cmd, BSDoptopt);
   return -1;
  }
 }

 return BSDoptind;
}

static int
parse_link_flags(const char *cmd, char **argv, int argc, int *sflag)
{
 extern int BSDopterr, BSDoptind, BSDoptopt, BSDoptreset;
 int ch;

 BSDoptind = BSDoptreset = 1;
 BSDopterr = 0;

 *sflag = 0;
 while ((ch = BSDgetopt(argc, argv, "s")) != -1) {
  switch (ch) {
  case 's':
   *sflag = 1;
   break;
  default:
   sshlog("sftp.c", __func__, 450, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: Invalid flag -%c", cmd, BSDoptopt);
   return -1;
  }
 }

 return BSDoptind;
}

static int
parse_rename_flags(const char *cmd, char **argv, int argc, int *lflag)
{
 extern int BSDopterr, BSDoptind, BSDoptopt, BSDoptreset;
 int ch;

 BSDoptind = BSDoptreset = 1;
 BSDopterr = 0;

 *lflag = 0;
 while ((ch = BSDgetopt(argc, argv, "l")) != -1) {
  switch (ch) {
  case 'l':
   *lflag = 1;
   break;
  default:
   sshlog("sftp.c", __func__, 474, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: Invalid flag -%c", cmd, BSDoptopt);
   return -1;
  }
 }

 return BSDoptind;
}

static int
parse_ls_flags(char **argv, int argc, int *lflag)
{
 extern int BSDopterr, BSDoptind, BSDoptopt, BSDoptreset;
 int ch;

 BSDoptind = BSDoptreset = 1;
 BSDopterr = 0;

 *lflag = 0x0008;
 while ((ch = BSDgetopt(argc, argv, "1Safhlnrt")) != -1) {
  switch (ch) {
  case '1':
   *lflag &= ~(0x0001|0x0002|0x0004|0x0100);
   *lflag |= 0x0002;
   break;
  case 'S':
   *lflag &= ~(0x0008|0x0010|0x0020);
   *lflag |= 0x0020;
   break;
  case 'a':
   *lflag |= 0x0080;
   break;
  case 'f':
   *lflag &= ~(0x0008|0x0010|0x0020);
   break;
  case 'h':
   *lflag |= 0x0100;
   break;
  case 'l':
   *lflag &= ~0x0002;
   *lflag |= 0x0001;
   break;
  case 'n':
   *lflag &= ~0x0002;
   *lflag |= 0x0004|0x0001;
   break;
  case 'r':
   *lflag |= 0x0040;
   break;
  case 't':
   *lflag &= ~(0x0008|0x0010|0x0020);
   *lflag |= 0x0010;
   break;
  default:
   sshlog("sftp.c", __func__, 527, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "ls: Invalid flag -%c", BSDoptopt);
   return -1;
  }
 }

 return BSDoptind;
}

static int
parse_df_flags(const char *cmd, char **argv, int argc, int *hflag, int *iflag)
{
 extern int BSDopterr, BSDoptind, BSDoptopt, BSDoptreset;
 int ch;

 BSDoptind = BSDoptreset = 1;
 BSDopterr = 0;

 *hflag = *iflag = 0;
 while ((ch = BSDgetopt(argc, argv, "hi")) != -1) {
  switch (ch) {
  case 'h':
   *hflag = 1;
   break;
  case 'i':
   *iflag = 1;
   break;
  default:
   sshlog("sftp.c", __func__, 554, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: Invalid flag -%c", cmd, BSDoptopt);
   return -1;
  }
 }

 return BSDoptind;
}

static int
parse_ch_flags(const char *cmd, char **argv, int argc, int *hflag)
{
 extern int BSDopterr, BSDoptind, BSDoptopt, BSDoptreset;
 int ch;

 BSDoptind = BSDoptreset = 1;
 BSDopterr = 0;

 *hflag = 0;
 while ((ch = BSDgetopt(argc, argv, "h")) != -1) {
  switch (ch) {
  case 'h':
   *hflag = 1;
   break;
  default:
   sshlog("sftp.c", __func__, 578, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: Invalid flag -%c", cmd, BSDoptopt);
   return -1;
  }
 }

 return BSDoptind;
}

static int
parse_no_flags(const char *cmd, char **argv, int argc)
{
 extern int BSDopterr, BSDoptind, BSDoptopt, BSDoptreset;
 int ch;

 BSDoptind = BSDoptreset = 1;
 BSDopterr = 0;

 while ((ch = BSDgetopt(argc, argv, "")) != -1) {
  switch (ch) {
  default:
   sshlog("sftp.c", __func__, 598, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: Invalid flag -%c", cmd, BSDoptopt);
   return -1;
  }
 }

 return BSDoptind;
}

static char *
escape_glob(const char *s)
{
 size_t i, o, len;
 char *ret;

 len = strlen(s);
 ret = xcalloc(2, len + 1);
 for (i = o = 0; i < len; i++) {
  if (strchr("[]?*\\", s[i]) != 
                               ((void *)0)
                                   )
   ret[o++] = '\\';
  ret[o++] = s[i];
 }
 ret[o++] = '\0';
 return ret;
}

static char *
make_absolute_pwd_glob(const char *p, const char *pwd)
{
 char *ret, *escpwd;

 escpwd = escape_glob(pwd);
 if (p == 
         ((void *)0)
             )
  return escpwd;
 ret = make_absolute(xstrdup(p), escpwd);
 free(escpwd);
 return ret;
}

static int
process_get(struct sftp_conn *conn, const char *src, const char *dst,
    const char *pwd, int pflag, int rflag, int resume, int fflag)
{
 char *filename, *abs_src = 
                           ((void *)0)
                               , *abs_dst = 
                                            ((void *)0)
                                                , *tmp = 
                                                         ((void *)0)
                                                             ;
 _ssh_compat_glob_t g;
 int i, r, err = 0;

 abs_src = make_absolute_pwd_glob(src, pwd);
 memset(&g, 0, sizeof(g));

 sshlog("sftp.c", __func__, 647, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "Looking up %s", abs_src);
 if ((r = remote_glob(conn, abs_src, 0x0008, 
                                               ((void *)0)
                                                   , &g)) != 0) {
  if (r == (-1)) {
   sshlog("sftp.c", __func__, 650, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Too many matches for \"%s\".", abs_src);
  } else {
   sshlog("sftp.c", __func__, 652, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "File \"%s\" not found.", abs_src);
  }
  err = -1;
  goto out;
 }





 if (g.gl_matchc > 1 && dst != 
                              ((void *)0) 
                                   && !local_is_dir(dst)) {
  sshlog("sftp.c", __func__, 663, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Multiple source paths, but destination " "\"%s\" is not a directory", dst)
                                       ;
  err = -1;
  goto out;
 }

 for (i = 0; g.gl_pathv[i] && !interrupted; i++) {
  tmp = xstrdup(g.gl_pathv[i]);
  if ((filename = 
                 __xpg_basename
                         (tmp)) == 
                                   ((void *)0)
                                       ) {
   sshlog("sftp.c", __func__, 672, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "basename %s: %s", tmp, strerror(
  (*__errno_location ())
  ));
   free(tmp);
   err = -1;
   goto out;
  }

  if (g.gl_matchc == 1 && dst) {
   if (local_is_dir(dst)) {
    abs_dst = path_append(dst, filename);
   } else {
    abs_dst = xstrdup(dst);
   }
  } else if (dst) {
   abs_dst = path_append(dst, filename);
  } else {
   abs_dst = xstrdup(filename);
  }
  free(tmp);

  resume |= global_aflag;
  if (!quiet && resume)
   mprintf("Resuming %s to %s\n",
       g.gl_pathv[i], abs_dst);
  else if (!quiet && !resume)
   mprintf("Fetching %s to %s\n",
       g.gl_pathv[i], abs_dst);

  if (globpath_is_dir(g.gl_pathv[i]) && (rflag || global_rflag)) {
   if (download_dir(conn, g.gl_pathv[i], abs_dst, 
                                                 ((void *)0)
                                                     ,
       pflag || global_pflag, 1, resume,
       fflag || global_fflag, 0, 0) == -1)
    err = -1;
  } else {
   if (do_download(conn, g.gl_pathv[i], abs_dst, 
                                                ((void *)0)
                                                    ,
       pflag || global_pflag, resume,
       fflag || global_fflag, 0) == -1)
    err = -1;
  }
  free(abs_dst);
  abs_dst = 
           ((void *)0)
               ;
 }

out:
 free(abs_src);
 _ssh__compat_globfree(&g);
 return(err);
}

static int
process_put(struct sftp_conn *conn, const char *src, const char *dst,
    const char *pwd, int pflag, int rflag, int resume, int fflag)
{
 char *tmp_dst = 
                ((void *)0)
                    ;
 char *abs_dst = 
                ((void *)0)
                    ;
 char *tmp = 
            ((void *)0)
                , *filename = 
                              ((void *)0)
                                  ;
 _ssh_compat_glob_t g;
 int err = 0;
 int i, dst_is_dir = 1;
 struct stat sb;

 if (dst) {
  tmp_dst = xstrdup(dst);
  tmp_dst = make_absolute(tmp_dst, pwd);
 }

 memset(&g, 0, sizeof(g));
 sshlog("sftp.c", __func__, 738, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "Looking up %s", src);
 if (_ssh__compat_glob(src, 0x0010 | 0x0008, 
    ((void *)0)
    , &g)) {
  sshlog("sftp.c", __func__, 740, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "File \"%s\" not found.", src);
  err = -1;
  goto out;
 }


 if (tmp_dst != 
               ((void *)0)
                   )
  dst_is_dir = remote_is_dir(conn, tmp_dst);


 if (g.gl_matchc > 1 && tmp_dst && !dst_is_dir) {
  sshlog("sftp.c", __func__, 751, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Multiple paths match, but destination " "\"%s\" is not a directory", tmp_dst)
                                           ;
  err = -1;
  goto out;
 }

 for (i = 0; g.gl_pathv[i] && !interrupted; i++) {
  if (stat(g.gl_pathv[i], &sb) == -1) {
   err = -1;
   sshlog("sftp.c", __func__, 760, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "stat %s: %s", g.gl_pathv[i], strerror(
  (*__errno_location ())
  ));
   continue;
  }

  tmp = xstrdup(g.gl_pathv[i]);
  if ((filename = 
                 __xpg_basename
                         (tmp)) == 
                                   ((void *)0)
                                       ) {
   sshlog("sftp.c", __func__, 766, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "basename %s: %s", tmp, strerror(
  (*__errno_location ())
  ));
   free(tmp);
   err = -1;
   goto out;
  }

  if (g.gl_matchc == 1 && tmp_dst) {

   if (dst_is_dir)
    abs_dst = path_append(tmp_dst, filename);
   else
    abs_dst = xstrdup(tmp_dst);
  } else if (tmp_dst) {
   abs_dst = path_append(tmp_dst, filename);
  } else {
   abs_dst = make_absolute(xstrdup(filename), pwd);
  }
  free(tmp);

  resume |= global_aflag;
  if (!quiet && resume)
   mprintf("Resuming upload of %s to %s\n",
       g.gl_pathv[i], abs_dst);
  else if (!quiet && !resume)
   mprintf("Uploading %s to %s\n",
       g.gl_pathv[i], abs_dst);

  if (globpath_is_dir(g.gl_pathv[i]) && (rflag || global_rflag)) {
   if (upload_dir(conn, g.gl_pathv[i], abs_dst,
       pflag || global_pflag, 1, resume,
       fflag || global_fflag, 0, 0) == -1)
    err = -1;
  } else {
   if (do_upload(conn, g.gl_pathv[i], abs_dst,
       pflag || global_pflag, resume,
       fflag || global_fflag, 0) == -1)
    err = -1;
  }
 }

out:
 free(abs_dst);
 free(tmp_dst);
 _ssh__compat_globfree(&g);
 return(err);
}

static int
sdirent_comp(const void *aa, const void *bb)
{
 SFTP_DIRENT *a = *(SFTP_DIRENT **)aa;
 SFTP_DIRENT *b = *(SFTP_DIRENT **)bb;
 int rmul = sort_flag & 0x0040 ? -1 : 1;


 if (sort_flag & 0x0008)
  return (rmul * strcmp(a->filename, b->filename));
 else if (sort_flag & 0x0010)
  return (rmul * (a->a.mtime == b->a.mtime ? 0 : (a->a.mtime < b->a.mtime ? 1 : -1)));
 else if (sort_flag & 0x0020)
  return (rmul * (a->a.size == b->a.size ? 0 : (a->a.size < b->a.size ? 1 : -1)));

 sshfatal("sftp.c", __func__, 828, 0, SYSLOG_LEVEL_FATAL, 
((void *)0)
, "Unknown ls sort type");
}


static int
do_ls_dir(struct sftp_conn *conn, const char *path,
    const char *strip_path, int lflag)
{
 int n;
 u_int c = 1, colspace = 0, columns = 1;
 SFTP_DIRENT **d;

 if ((n = do_readdir(conn, path, &d)) != 0)
  return (n);

 if (!(lflag & 0x0002)) {
  u_int m = 0, width = 80;
  struct winsize ws;
  char *tmp;


  for (n = 0; d[n] != 
                     ((void *)0)
                         ; n++) {
   if (d[n]->filename[0] != '.' || (lflag & 0x0080))
    m = (((m) > (strlen(d[n]->filename))) ? (m) : (strlen(d[n]->filename)));
  }


  tmp = path_strip(path, strip_path);
  m += strlen(tmp);
  free(tmp);

  if (ioctl(fileno(
                  stdin
                       ), 
                          0x5413
                                    , &ws) != -1)
   width = ws.ws_col;

  columns = width / (m + 2);
  columns = (((columns) > (1)) ? (columns) : (1));
  colspace = width / columns;
  colspace = (((colspace) < (width)) ? (colspace) : (width));
 }

 if (lflag & (0x0008|0x0010|0x0020)) {
  for (n = 0; d[n] != 
                     ((void *)0)
                         ; n++)
   ;
  sort_flag = lflag & ((0x0008|0x0010|0x0020)|0x0040);
  qsort(d, n, sizeof(*d), sdirent_comp);
 }

 get_remote_user_groups_from_dirents(conn, d);
 for (n = 0; d[n] != 
                    ((void *)0) 
                         && !interrupted; n++) {
  char *tmp, *fname;

  if (d[n]->filename[0] == '.' && !(lflag & 0x0080))
   continue;

  tmp = path_append(path, d[n]->filename);
  fname = path_strip(tmp, strip_path);
  free(tmp);

  if (lflag & 0x0001) {
   if ((lflag & (0x0004|0x0100)) != 0 ||
       can_get_users_groups_by_id(conn)) {
    char *lname;
    struct stat sb;

    memset(&sb, 0, sizeof(sb));
    attrib_to_stat(&d[n]->a, &sb);
    lname = ls_file(fname, &sb, 1,
        (lflag & 0x0100),
        ruser_name(sb.st_uid),
        rgroup_name(sb.st_gid));
    mprintf("%s\n", lname);
    free(lname);
   } else
    mprintf("%s\n", d[n]->longname);
  } else {
   mprintf("%-*s", colspace, fname);
   if (c >= columns) {
    printf("\n");
    c = 1;
   } else
    c++;
  }

  free(fname);
 }

 if (!(lflag & 0x0001) && (c != 1))
  printf("\n");

 free_sftp_dirents(d);
 return (0);
}

static int
sglob_comp(const void *aa, const void *bb)
{
 u_int a = *(const u_int *)aa;
 u_int b = *(const u_int *)bb;
 const char *ap = sort_glob->gl_pathv[a];
 const char *bp = sort_glob->gl_pathv[b];
 const struct stat *as = sort_glob->gl_statv[a];
 const struct stat *bs = sort_glob->gl_statv[b];
 int rmul = sort_flag & 0x0040 ? -1 : 1;


 if (sort_flag & 0x0008)
  return (rmul * strcmp(ap, bp));
 else if (sort_flag & 0x0010) {

  if ((((&as->st_mtim)->tv_sec == (&bs->st_mtim)->tv_sec) ? ((&as->st_mtim)->tv_nsec == (&bs->st_mtim)->tv_nsec) : ((&as->st_mtim)->tv_sec == (&bs->st_mtim)->tv_sec)))
   return 0;
  return (((&as->st_mtim)->tv_sec == (&bs->st_mtim)->tv_sec) ? ((&as->st_mtim)->tv_nsec < (&bs->st_mtim)->tv_nsec) : ((&as->st_mtim)->tv_sec < (&bs->st_mtim)->tv_sec)) ?
      rmul : -rmul;





 } else if (sort_flag & 0x0020)
  return (rmul * (as->st_size == bs->st_size ? 0 : (as->st_size < bs->st_size ? 1 : -1)));

 sshfatal("sftp.c", __func__, 949, 0, SYSLOG_LEVEL_FATAL, 
((void *)0)
, "Unknown ls sort type");
}


static int
do_globbed_ls(struct sftp_conn *conn, const char *path,
    const char *strip_path, int lflag)
{
 char *fname, *lname;
 _ssh_compat_glob_t g;
 int err, r;
 struct winsize ws;
 u_int i, j, nentries, *indices = 
                                 ((void *)0)
                                     , c = 1;
 u_int colspace = 0, columns = 1, m = 0, width = 80;

 memset(&g, 0, sizeof(g));

 if ((r = remote_glob(conn, path,
     0x0008|0x0010|0x0080|0x4000|0x0020,
     
    ((void *)0)
        , &g)) != 0 ||
     (g.gl_pathc && !g.gl_matchc)) {
  if (g.gl_pathc)
   _ssh__compat_globfree(&g);
  if (r == (-1)) {
   sshlog("sftp.c", __func__, 973, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Can't ls: Too many matches for \"%s\"", path);
  } else {
   sshlog("sftp.c", __func__, 975, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Can't ls: \"%s\" not found", path);
  }
  return -1;
 }

 if (interrupted)
  goto out;





 if (g.gl_matchc == 1 && g.gl_statv[0] != 
                                         ((void *)0) 
                                              &&
     
    ((((
    g.gl_statv[0]->st_mode
    )) & 0170000) == (0040000))
                                   ) {
  err = do_ls_dir(conn, g.gl_pathv[0], strip_path, lflag);
  _ssh__compat_globfree(&g);
  return err;
 }

 if (ioctl(fileno(
                 stdin
                      ), 
                         0x5413
                                   , &ws) != -1)
  width = ws.ws_col;

 if (!(lflag & 0x0002)) {

  for (i = 0; g.gl_pathv[i]; i++)
   m = (((m) > (strlen(g.gl_pathv[i]))) ? (m) : (strlen(g.gl_pathv[i])));

  columns = width / (m + 2);
  columns = (((columns) > (1)) ? (columns) : (1));
  colspace = width / columns;
 }






 for (nentries = 0; g.gl_pathv[nentries] != 
                                           ((void *)0)
                                               ; nentries++)
  ;
 indices = calloc(nentries, sizeof(*indices));
 for (i = 0; i < nentries; i++)
  indices[i] = i;

 if (lflag & (0x0008|0x0010|0x0020)) {
  sort_glob = &g;
  sort_flag = lflag & ((0x0008|0x0010|0x0020)|0x0040);
  qsort(indices, nentries, sizeof(*indices), sglob_comp);
  sort_glob = 
             ((void *)0)
                 ;
 }

 get_remote_user_groups_from_glob(conn, &g);
 for (j = 0; j < nentries && !interrupted; j++) {
  i = indices[j];
  fname = path_strip(g.gl_pathv[i], strip_path);
  if (lflag & 0x0001) {
   if (g.gl_statv[i] == 
                       ((void *)0)
                           ) {
    sshlog("sftp.c", __func__, 1031, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "no stat information for %s", fname);
    continue;
   }
   lname = ls_file(fname, g.gl_statv[i], 1,
       (lflag & 0x0100),
       ruser_name(g.gl_statv[i]->st_uid),
       rgroup_name(g.gl_statv[i]->st_gid));
   mprintf("%s\n", lname);
   free(lname);
  } else {
   mprintf("%-*s", colspace, fname);
   if (c >= columns) {
    printf("\n");
    c = 1;
   } else
    c++;
  }
  free(fname);
 }

 if (!(lflag & 0x0001) && (c != 1))
  printf("\n");

 out:
 if (g.gl_pathc)
  _ssh__compat_globfree(&g);
 free(indices);

 return 0;
}

static int
do_df(struct sftp_conn *conn, const char *path, int hflag, int iflag)
{
 struct sftp_statvfs st;
 char s_used[7], s_avail[7];
 char s_root[7], s_total[7];
 char s_icapacity[16], s_dcapacity[16];

 if (do_statvfs(conn, path, &st, 1) == -1)
  return -1;
 if (st.f_files == 0)
  strlcpy(s_icapacity, "ERR", sizeof(s_icapacity));
 else {
  snprintf(s_icapacity, sizeof(s_icapacity), "%3llu%%",
      (unsigned long long)(100 * (st.f_files - st.f_ffree) /
      st.f_files));
 }
 if (st.f_blocks == 0)
  strlcpy(s_dcapacity, "ERR", sizeof(s_dcapacity));
 else {
  snprintf(s_dcapacity, sizeof(s_dcapacity), "%3llu%%",
      (unsigned long long)(100 * (st.f_blocks - st.f_bfree) /
      st.f_blocks));
 }
 if (iflag) {
  printf("     Inodes        Used       Avail      "
      "(root)    %%Capacity\n");
  printf("%11llu %11llu %11llu %11llu         %s\n",
      (unsigned long long)st.f_files,
      (unsigned long long)(st.f_files - st.f_ffree),
      (unsigned long long)st.f_favail,
      (unsigned long long)st.f_ffree, s_icapacity);
 } else if (hflag) {
  strlcpy(s_used, "error", sizeof(s_used));
  strlcpy(s_avail, "error", sizeof(s_avail));
  strlcpy(s_root, "error", sizeof(s_root));
  strlcpy(s_total, "error", sizeof(s_total));
  fmt_scaled((st.f_blocks - st.f_bfree) * st.f_frsize, s_used);
  fmt_scaled(st.f_bavail * st.f_frsize, s_avail);
  fmt_scaled(st.f_bfree * st.f_frsize, s_root);
  fmt_scaled(st.f_blocks * st.f_frsize, s_total);
  printf("    Size     Used    Avail   (root)    %%Capacity\n");
  printf("%7sB %7sB %7sB %7sB         %s\n",
      s_total, s_used, s_avail, s_root, s_dcapacity);
 } else {
  printf("        Size         Used        Avail       "
      "(root)    %%Capacity\n");
  printf("%12llu %12llu %12llu %12llu         %s\n",
      (unsigned long long)(st.f_frsize * st.f_blocks / 1024),
      (unsigned long long)(st.f_frsize *
      (st.f_blocks - st.f_bfree) / 1024),
      (unsigned long long)(st.f_frsize * st.f_bavail / 1024),
      (unsigned long long)(st.f_frsize * st.f_bfree / 1024),
      s_dcapacity);
 }
 return 0;
}






static void
undo_glob_escape(char *s)
{
 size_t i, j;

 for (i = j = 0;;) {
  if (s[i] == '\0') {
   s[j] = '\0';
   return;
  }
  if (s[i] != '\\') {
   s[j++] = s[i++];
   continue;
  }

  ++i;
  switch (s[i]) {
  case '?':
  case '[':
  case '*':
  case '\\':
   s[j++] = s[i++];
   break;
  case '\0':
   s[j++] = '\\';
   s[j] = '\0';
   return;
  default:
   s[j++] = '\\';
   s[j++] = s[i++];
   break;
  }
 }
}
static char **
makeargv(const char *arg, int *argcp, int sloppy, char *lastquote,
    u_int *terminated)
{
 int argc, quot;
 size_t i, j;
 static char argvs[8192];
 static char *argv[128 + 1];
 enum { MA_START, MA_SQUOTE, MA_DQUOTE, MA_UNQUOTED } state, q;

 *argcp = argc = 0;
 if (strlen(arg) > sizeof(argvs) - 1) {
 args_too_longs:
  sshlog("sftp.c", __func__, 1191, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "string too long");
  return 
        ((void *)0)
            ;
 }
 if (terminated != 
                  ((void *)0)
                      )
  *terminated = 1;
 if (lastquote != 
                 ((void *)0)
                     )
  *lastquote = '\0';
 state = MA_START;
 i = j = 0;
 for (;;) {
  if ((size_t)argc >= sizeof(argv) / sizeof(*argv)){
   sshlog("sftp.c", __func__, 1202, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Too many arguments.");
   return 
         ((void *)0)
             ;
  }
  if (
     ((*__ctype_b_loc ())[(int) ((
     (unsigned char)arg[i]
     ))] & (unsigned short int) _ISspace)
                                   ) {
   if (state == MA_UNQUOTED) {

    argvs[j++] = '\0';
    argc++;
    state = MA_START;
   } else if (state != MA_START)
    argvs[j++] = arg[i];
  } else if (arg[i] == '"' || arg[i] == '\'') {
   q = arg[i] == '"' ? MA_DQUOTE : MA_SQUOTE;
   if (state == MA_START) {
    argv[argc] = argvs + j;
    state = q;
    if (lastquote != 
                    ((void *)0)
                        )
     *lastquote = arg[i];
   } else if (state == MA_UNQUOTED)
    state = q;
   else if (state == q)
    state = MA_UNQUOTED;
   else
    argvs[j++] = arg[i];
  } else if (arg[i] == '\\') {
   if (state == MA_SQUOTE || state == MA_DQUOTE) {
    quot = state == MA_SQUOTE ? '\'' : '"';


    if (arg[i + 1] == quot) {
     i++;
     argvs[j++] = arg[i];
    } else if (arg[i + 1] == '?' ||
        arg[i + 1] == '[' || arg[i + 1] == '*') {






     if (j >= sizeof(argvs) - 5)
      goto args_too_longs;
     argvs[j++] = '\\';
     argvs[j++] = arg[i++];
     argvs[j++] = '\\';
     argvs[j++] = arg[i];
    } else {
     argvs[j++] = arg[i++];
     argvs[j++] = arg[i];
    }
   } else {
    if (state == MA_START) {
     argv[argc] = argvs + j;
     state = MA_UNQUOTED;
     if (lastquote != 
                     ((void *)0)
                         )
      *lastquote = '\0';
    }
    if (arg[i + 1] == '?' || arg[i + 1] == '[' ||
        arg[i + 1] == '*' || arg[i + 1] == '\\') {






     argvs[j++] = arg[i++];
     argvs[j++] = arg[i];
    } else {


     i++;
     argvs[j++] = arg[i];
    }
   }
  } else if (arg[i] == '#') {
   if (state == MA_SQUOTE || state == MA_DQUOTE)
    argvs[j++] = arg[i];
   else
    goto string_done;
  } else if (arg[i] == '\0') {
   if (state == MA_SQUOTE || state == MA_DQUOTE) {
    if (sloppy) {
     state = MA_UNQUOTED;
     if (terminated != 
                      ((void *)0)
                          )
      *terminated = 0;
     goto string_done;
    }
    sshlog("sftp.c", __func__, 1289, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Unterminated quoted argument");
    return 
          ((void *)0)
              ;
   }
 string_done:
   if (state == MA_UNQUOTED) {
    argvs[j++] = '\0';
    argc++;
   }
   break;
  } else {
   if (state == MA_START) {
    argv[argc] = argvs + j;
    state = MA_UNQUOTED;
    if (lastquote != 
                    ((void *)0)
                        )
     *lastquote = '\0';
   }
   if ((state == MA_SQUOTE || state == MA_DQUOTE) &&
       (arg[i] == '?' || arg[i] == '[' || arg[i] == '*')) {





    if (j >= sizeof(argvs) - 3)
     goto args_too_longs;
    argvs[j++] = '\\';
    argvs[j++] = arg[i];
   } else
    argvs[j++] = arg[i];
  }
  i++;
 }
 *argcp = argc;
 return argv;
}

static int
parse_args(const char **cpp, int *ignore_errors, int *disable_echo, int *aflag,
   int *fflag, int *hflag, int *iflag, int *lflag, int *pflag,
   int *rflag, int *sflag,
    unsigned long *n_arg, char **path1, char **path2)
{
 const char *cmd, *cp = *cpp;
 char *cp2, **argv;
 int base = 0;
 long long ll;
 int path1_mandatory = 0, i, cmdnum, optidx, argc;


 cp = cp + strspn(cp, " \t\r\n");





 *ignore_errors = 0;
 *disable_echo = 0;
 for (;*cp != '\0'; cp++) {
  if (*cp == '-') {
   *ignore_errors = 1;
  } else if (*cp == '@') {
   *disable_echo = 1;
  } else {

   break;
  }
 }
 cp = cp + strspn(cp, " \t\r\n");


 if (*cp == '\0' || *cp == '#')
  return (0);

 if ((argv = makeargv(cp, &argc, 0, 
                                   ((void *)0)
                                       , 
                                         ((void *)0)
                                             )) == 
                                                   ((void *)0)
                                                       )
  return -1;


 for (i = 0; cmds[i].c != 
                         ((void *)0)
                             ; i++) {
  if (argv[0] != 
                ((void *)0) 
                     && strcasecmp(cmds[i].c, argv[0]) == 0)
   break;
 }
 cmdnum = cmds[i].n;
 cmd = cmds[i].c;


 if (*cp == '!') {
  cp++;
  cmdnum = I_SHELL;
 } else if (cmdnum == -1) {
  sshlog("sftp.c", __func__, 1378, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Invalid command.");
  return -1;
 }


 *aflag = *fflag = *hflag = *iflag = *lflag = *pflag = 0;
 *rflag = *sflag = 0;
 *path1 = *path2 = 
                  ((void *)0)
                      ;
 optidx = 1;
 switch (cmdnum) {
 case I_GET:
 case I_REGET:
 case I_REPUT:
 case I_PUT:
  if ((optidx = parse_getput_flags(cmd, argv, argc,
      aflag, fflag, pflag, rflag)) == -1)
   return -1;

  if (argc - optidx < 1) {
   sshlog("sftp.c", __func__, 1397, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "You must specify at least one path after a " "%s command.", cmd)
                          ;
   return -1;
  }
  *path1 = xstrdup(argv[optidx]);

  if (argc - optidx > 1) {
   *path2 = xstrdup(argv[optidx + 1]);

   undo_glob_escape(*path2);
  }
  break;
 case I_LINK:
  if ((optidx = parse_link_flags(cmd, argv, argc, sflag)) == -1)
   return -1;
  goto parse_two_paths;
 case I_COPY:
  if ((optidx = parse_no_flags(cmd, argv, argc)) == -1)
   return -1;
  goto parse_two_paths;
 case I_RENAME:
  if ((optidx = parse_rename_flags(cmd, argv, argc, lflag)) == -1)
   return -1;
  goto parse_two_paths;
 case I_SYMLINK:
  if ((optidx = parse_no_flags(cmd, argv, argc)) == -1)
   return -1;
 parse_two_paths:
  if (argc - optidx < 2) {
   sshlog("sftp.c", __func__, 1426, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "You must specify two paths after a %s " "command.", cmd)
                       ;
   return -1;
  }
  *path1 = xstrdup(argv[optidx]);
  *path2 = xstrdup(argv[optidx + 1]);

  undo_glob_escape(*path1);
  undo_glob_escape(*path2);
  break;
 case I_RM:
 case I_MKDIR:
 case I_RMDIR:
 case I_LMKDIR:
  path1_mandatory = 1;

 case I_CHDIR:
 case I_LCHDIR:
  if ((optidx = parse_no_flags(cmd, argv, argc)) == -1)
   return -1;

  if (argc - optidx < 1) {
   if (!path1_mandatory)
    break;
   sshlog("sftp.c", __func__, 1450, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "You must specify a path after a %s command.", cmd)
           ;
   return -1;
  }
  *path1 = xstrdup(argv[optidx]);

  if (cmdnum != I_RM)
   undo_glob_escape(*path1);
  break;
 case I_DF:
  if ((optidx = parse_df_flags(cmd, argv, argc, hflag,
      iflag)) == -1)
   return -1;

  if (argc - optidx < 1)
   *path1 = 
           ((void *)0)
               ;
  else {
   *path1 = xstrdup(argv[optidx]);
   undo_glob_escape(*path1);
  }
  break;
 case I_LS:
  if ((optidx = parse_ls_flags(argv, argc, lflag)) == -1)
   return(-1);

  if (argc - optidx > 0)
   *path1 = xstrdup(argv[optidx]);
  break;
 case I_LLS:

  cp = cp + strlen(cmd) + strspn(cp, " \t\r\n");
 case I_SHELL:

  break;
 case I_LUMASK:
 case I_CHMOD:
  base = 8;

 case I_CHOWN:
 case I_CHGRP:
  if ((optidx = parse_ch_flags(cmd, argv, argc, hflag)) == -1)
   return -1;

  if (argc - optidx < 1)
   goto need_num_arg;
  
 (*__errno_location ()) 
       = 0;
  ll = strtoll(argv[optidx], &cp2, base);
  if (cp2 == argv[optidx] || *cp2 != '\0' ||
      ((ll == 
             (-0x7fffffffffffffffLL - 1LL) 
                       || ll == 0x7fffffffffffffffLL) && 
                                              (*__errno_location ()) 
                                                    == 
                                                       34
                                                             ) ||
      ll < 0 || ll > 
                    (4294967295U)
                              ) {
 need_num_arg:
   sshlog("sftp.c", __func__, 1501, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "You must supply a numeric argument " "to the %s command.", cmd)
                                 ;
   return -1;
  }
  *n_arg = ll;
  if (cmdnum == I_LUMASK)
   break;

  if (argc - optidx < 2) {
   sshlog("sftp.c", __func__, 1510, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "You must specify a path after a %s command.", cmd)
           ;
   return -1;
  }
  *path1 = xstrdup(argv[optidx + 1]);
  break;
 case I_QUIT:
 case I_PWD:
 case I_LPWD:
 case I_HELP:
 case I_VERSION:
 case I_PROGRESS:
  if ((optidx = parse_no_flags(cmd, argv, argc)) == -1)
   return -1;
  break;
 default:
  sshfatal("sftp.c", __func__, 1526, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Command not implemented");
 }

 *cpp = cp;
 return(cmdnum);
}

static int
parse_dispatch_command(struct sftp_conn *conn, const char *cmd, char **pwd,
    const char *startdir, int err_abort, int echo_command)
{
 const char *ocmd = cmd;
 char *path1, *path2, *tmp;
 int ignore_errors = 0, disable_echo = 1;
 int aflag = 0, fflag = 0, hflag = 0, iflag = 0;
 int lflag = 0, pflag = 0, rflag = 0, sflag = 0;
 int cmdnum, i;
 unsigned long n_arg = 0;
 Attrib a, *aa;
 char path_buf[
              4096
                      ];
 int err = 0;
 _ssh_compat_glob_t g;

 path1 = path2 = 
                ((void *)0)
                    ;
 cmdnum = parse_args(&cmd, &ignore_errors, &disable_echo, &aflag, &fflag,
     &hflag, &iflag, &lflag, &pflag, &rflag, &sflag, &n_arg,
     &path1, &path2);
 if (ignore_errors != 0)
  err_abort = 0;

 if (echo_command && !disable_echo)
  mprintf("sftp> %s\n", ocmd);

 memset(&g, 0, sizeof(g));


 switch (cmdnum) {
 case 0:

  break;
 case -1:

  err = -1;
  break;
 case I_REGET:
  aflag = 1;

 case I_GET:
  err = process_get(conn, path1, path2, *pwd, pflag,
      rflag, aflag, fflag);
  break;
 case I_REPUT:
  aflag = 1;

 case I_PUT:
  err = process_put(conn, path1, path2, *pwd, pflag,
      rflag, aflag, fflag);
  break;
 case I_COPY:
  path1 = make_absolute(path1, *pwd);
  path2 = make_absolute(path2, *pwd);
  err = do_copy(conn, path1, path2);
  break;
 case I_RENAME:
  path1 = make_absolute(path1, *pwd);
  path2 = make_absolute(path2, *pwd);
  err = do_rename(conn, path1, path2, lflag);
  break;
 case I_SYMLINK:
  sflag = 1;

 case I_LINK:
  if (!sflag)
   path1 = make_absolute(path1, *pwd);
  path2 = make_absolute(path2, *pwd);
  err = (sflag ? do_symlink : do_hardlink)(conn, path1, path2);
  break;
 case I_RM:
  path1 = make_absolute_pwd_glob(path1, *pwd);
  remote_glob(conn, path1, 0x0010, 
                                        ((void *)0)
                                            , &g);
  for (i = 0; g.gl_pathv[i] && !interrupted; i++) {
   if (!quiet)
    mprintf("Removing %s\n", g.gl_pathv[i]);
   err = do_rm(conn, g.gl_pathv[i]);
   if (err != 0 && err_abort)
    break;
  }
  break;
 case I_MKDIR:
  path1 = make_absolute(path1, *pwd);
  attrib_clear(&a);
  a.flags |= 0x00000004;
  a.perm = 0777;
  err = do_mkdir(conn, path1, &a, 1);
  break;
 case I_RMDIR:
  path1 = make_absolute(path1, *pwd);
  err = do_rmdir(conn, path1);
  break;
 case I_CHDIR:
  if (path1 == 
              ((void *)0) 
                   || *path1 == '\0')
   path1 = xstrdup(startdir);
  path1 = make_absolute(path1, *pwd);
  if ((tmp = do_realpath(conn, path1)) == 
                                         ((void *)0)
                                             ) {
   err = 1;
   break;
  }
  if ((aa = do_stat(conn, tmp, 0)) == 
                                     ((void *)0)
                                         ) {
   free(tmp);
   err = 1;
   break;
  }
  if (!(aa->flags & 0x00000004)) {
   sshlog("sftp.c", __func__, 1639, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Can't change directory: Can't check target");
   free(tmp);
   err = 1;
   break;
  }
  if (!
      ((((
      aa->perm
      )) & 0170000) == (0040000))
                       ) {
   sshlog("sftp.c", __func__, 1645, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Can't change directory: \"%s\" is not " "a directory", tmp)
                          ;
   free(tmp);
   err = 1;
   break;
  }
  free(*pwd);
  *pwd = tmp;
  break;
 case I_LS:
  if (!path1) {
   do_ls_dir(conn, *pwd, *pwd, lflag);
   break;
  }


  tmp = 
       ((void *)0)
           ;
  if (!path_absolute(path1))
   tmp = *pwd;

  path1 = make_absolute_pwd_glob(path1, *pwd);
  err = do_globbed_ls(conn, path1, tmp, lflag);
  break;
 case I_DF:

  if (path1 == 
              ((void *)0)
                  )
   path1 = xstrdup(*pwd);
  path1 = make_absolute(path1, *pwd);
  err = do_df(conn, path1, hflag, iflag);
  break;
 case I_LCHDIR:
  if (path1 == 
              ((void *)0) 
                   || *path1 == '\0')
   path1 = xstrdup("~");
  tmp = tilde_expand_filename(path1, getuid());
  free(path1);
  path1 = tmp;
  if (chdir(path1) == -1) {
   sshlog("sftp.c", __func__, 1682, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Couldn't change local directory to " "\"%s\": %s", path1, strerror(
  (*__errno_location ())
  ))
                                            ;
   err = 1;
  }
  break;
 case I_LMKDIR:
  if (mkdir(path1, 0777) == -1) {
   sshlog("sftp.c", __func__, 1689, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Couldn't create local directory " "\"%s\": %s", path1, strerror(
  (*__errno_location ())
  ))
                                            ;
   err = 1;
  }
  break;
 case I_LLS:
  local_do_ls(cmd);
  break;
 case I_SHELL:
  local_do_shell(cmd);
  break;
 case I_LUMASK:
  umask(n_arg);
  printf("Local umask: %03lo\n", n_arg);
  break;
 case I_CHMOD:
  path1 = make_absolute_pwd_glob(path1, *pwd);
  attrib_clear(&a);
  a.flags |= 0x00000004;
  a.perm = n_arg;
  remote_glob(conn, path1, 0x0010, 
                                        ((void *)0)
                                            , &g);
  for (i = 0; g.gl_pathv[i] && !interrupted; i++) {
   if (!quiet)
    mprintf("Changing mode on %s\n",
        g.gl_pathv[i]);
   err = (hflag ? do_lsetstat : do_setstat)(conn,
       g.gl_pathv[i], &a);
   if (err != 0 && err_abort)
    break;
  }
  break;
 case I_CHOWN:
 case I_CHGRP:
  path1 = make_absolute_pwd_glob(path1, *pwd);
  remote_glob(conn, path1, 0x0010, 
                                        ((void *)0)
                                            , &g);
  for (i = 0; g.gl_pathv[i] && !interrupted; i++) {
   if (!(aa = (hflag ? do_lstat : do_stat)(conn,
       g.gl_pathv[i], 0))) {
    if (err_abort) {
     err = -1;
     break;
    } else
     continue;
   }
   if (!(aa->flags & 0x00000002)) {
    sshlog("sftp.c", __func__, 1734, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Can't get current ownership of " "remote file \"%s\"", g.gl_pathv[i])
                                            ;
    if (err_abort) {
     err = -1;
     break;
    } else
     continue;
   }
   aa->flags &= 0x00000002;
   if (cmdnum == I_CHOWN) {
    if (!quiet)
     mprintf("Changing owner on %s\n",
         g.gl_pathv[i]);
    aa->uid = n_arg;
   } else {
    if (!quiet)
     mprintf("Changing group on %s\n",
         g.gl_pathv[i]);
    aa->gid = n_arg;
   }
   err = (hflag ? do_lsetstat : do_setstat)(conn,
       g.gl_pathv[i], aa);
   if (err != 0 && err_abort)
    break;
  }
  break;
 case I_PWD:
  mprintf("Remote working directory: %s\n", *pwd);
  break;
 case I_LPWD:
  if (!getcwd(path_buf, sizeof(path_buf))) {
   sshlog("sftp.c", __func__, 1765, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Couldn't get local cwd: %s", strerror(
  (*__errno_location ())
  ));
   err = -1;
   break;
  }
  mprintf("Local working directory: %s\n", path_buf);
  break;
 case I_QUIT:

  break;
 case I_HELP:
  help();
  break;
 case I_VERSION:
  printf("SFTP protocol version %u\n", sftp_proto_version(conn));
  break;
 case I_PROGRESS:
  showprogress = !showprogress;
  if (showprogress)
   printf("Progress meter enabled\n");
  else
   printf("Progress meter disabled\n");
  break;
 default:
  sshfatal("sftp.c", __func__, 1788, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%d is not implemented", cmdnum);
 }

 if (g.gl_pathc)
  _ssh__compat_globfree(&g);
 free(path1);
 free(path2);


 if (err_abort && err != 0)
  return (-1);
 else if (cmdnum == I_QUIT)
  return (1);

 return (0);
}
static int
interactive_loop(struct sftp_conn *conn, char *file1, char *file2)
{
 char *remote_path;
 char *dir = 
            ((void *)0)
                , *startdir = 
                              ((void *)0)
                                  ;
 char cmd[2048];
 int err, interactive;
 EditLine *el = 
               ((void *)0)
                   ;
 remote_path = do_realpath(conn, ".");
 if (remote_path == 
                   ((void *)0)
                       )
  sshfatal("sftp.c", __func__, 2236, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Need cwd");
 startdir = xstrdup(remote_path);

 if (file1 != 
             ((void *)0)
                 ) {
  dir = xstrdup(file1);
  dir = make_absolute(dir, remote_path);

  if (remote_is_dir(conn, dir) && file2 == 
                                          ((void *)0)
                                              ) {
   if (!quiet)
    mprintf("Changing to: %s\n", dir);
   snprintf(cmd, sizeof cmd, "cd \"%s\"", dir);
   if (parse_dispatch_command(conn, cmd,
       &remote_path, startdir, 1, 0) != 0) {
    free(dir);
    free(startdir);
    free(remote_path);
    free(conn);
    return (-1);
   }
  } else {

   snprintf(cmd, sizeof cmd, "get%s %s%s%s",
       global_aflag ? " -a" : "", dir,
       file2 == 
               ((void *)0) 
                    ? "" : " ",
       file2 == 
               ((void *)0) 
                    ? "" : file2);
   err = parse_dispatch_command(conn, cmd,
       &remote_path, startdir, 1, 0);
   free(dir);
   free(startdir);
   free(remote_path);
   free(conn);
   return (err);
  }
  free(dir);
 }

 setvbuf(
        stdout
              , 
                ((void *)0)
                    , 
                      1
                            , 0);
 setvbuf(infile, 
                ((void *)0)
                    , 
                      1
                            , 0);

 interactive = !batchmode && isatty(
                                   0
                                               );
 err = 0;
 for (;;) {
  struct sigaction sa;

  interrupted = 0;
  memset(&sa, 0, sizeof(sa));
  sa.
    __sigaction_handler.sa_handler 
               = interactive ? read_interrupt : killchild;
  if (sigaction(
               2
                     , &sa, 
                            ((void *)0)
                                ) == -1) {
   sshlog("sftp.c", __func__, 2284, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "sigaction(%s): %s", strsignal(
  2
  ), strerror(
  (*__errno_location ())
  ))
                       ;
   break;
  }
  if (el == 
           ((void *)0)
               ) {
   if (interactive)
    printf("sftp> ");
   if (fgets(cmd, sizeof(cmd), infile) == 
                                         ((void *)0)
                                             ) {
    if (interactive)
     printf("\n");
    if (interrupted)
     continue;
    break;
   }
  } else {
  }

  cmd[strcspn(cmd, "\n")] = '\0';


  interrupted = 0;
  ssh_signal(
            2
                  , cmd_interrupt);

  err = parse_dispatch_command(conn, cmd, &remote_path,
      startdir, batchmode, !interactive && el == 
                                                ((void *)0)
                                                    );
  if (err != 0)
   break;
 }
 ssh_signal(
           17
                  , 
                    ((__sighandler_t) 0)
                           );
 free(remote_path);
 free(startdir);
 free(conn);







 return (err >= 0 ? 0 : -1);
}

static void
connect_to_server(char *path, char **args, int *in, int *out)
{
 int c_in, c_out;
 int inout[2];

 if (socketpair(
               1
                      , 
                        SOCK_STREAM
                                   , 0, inout) == -1)
  sshfatal("sftp.c", __func__, 2360, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "socketpair: %s", strerror(
 (*__errno_location ())
 ));
 *in = *out = inout[0];
 c_in = c_out = inout[1];


 if ((sshpid = fork()) == -1)
  sshfatal("sftp.c", __func__, 2366, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "fork: %s", strerror(
 (*__errno_location ())
 ));
 else if (sshpid == 0) {
  if ((dup2(c_in, 
                 0
                             ) == -1) ||
      (dup2(c_out, 
                  1
                               ) == -1)) {
   fprintf(
          stderr
                , "dup2: %s\n", strerror(
                                         (*__errno_location ())
                                              ));
   _exit(1);
  }
  close(*in);
  close(*out);
  close(c_in);
  close(c_out);
  ssh_signal(
            2
                  , 
                    ((__sighandler_t) 1)
                           );
  ssh_signal(
            15
                   , 
                     ((__sighandler_t) 0)
                            );
  execvp(path, args);
  fprintf(
         stderr
               , "exec: %s: %s\n", path, strerror(
                                                  (*__errno_location ())
                                                       ));
  _exit(1);
 }

 ssh_signal(
           15
                  , killchild);
 ssh_signal(
           2
                 , killchild);
 ssh_signal(
           1
                 , killchild);
 ssh_signal(
           20
                  , suspchild);
 ssh_signal(
           21
                  , suspchild);
 ssh_signal(
           22
                  , suspchild);
 ssh_signal(
           17
                  , sigchld_handler);
 close(c_in);
 close(c_out);
}

static void
usage(void)
{
 extern char *__progname;

 fprintf(
        stderr
              ,
     "usage: %s [-46AaCfNpqrv] [-B buffer_size] [-b batchfile] [-c cipher]\n"
     "          [-D sftp_server_command] [-F ssh_config] [-i identity_file]\n"
     "          [-J destination] [-l limit] [-o ssh_option] [-P port]\n"
     "          [-R num_requests] [-S program] [-s subsystem | sftp_server]\n"
     "          destination\n",
     __progname);
 exit(1);
}

int
main(int argc, char **argv)
{
 int r, in, out, ch, err, tmp, port = -1, noisy = 0;
 char *host = 
             ((void *)0)
                 , *user, *cp, **cpp, *file2 = 
                                               ((void *)0)
                                                   ;
 int debug_level = 0;
 char *file1 = 
              ((void *)0)
                  , *sftp_server = 
                                   ((void *)0)
                                       ;
 char *ssh_program = "/usr/local/bin/ssh", *sftp_direct = 
                                                      ((void *)0)
                                                          ;
 const char *errstr;
 LogLevel ll = SYSLOG_LEVEL_INFO;
 arglist args;
 extern int BSDoptind;
 extern char *BSDoptarg;
 struct sftp_conn *conn;
 size_t copy_buffer_len = 0;
 size_t num_requests = 0;
 long long limit_kbps = 0;


 sanitise_stdfd();
 msetlocale();

 __progname = ssh_get_progname(argv[0]);
 memset(&args, '\0', sizeof(args));
 args.list = 
            ((void *)0)
                ;
 addargs(&args, "%s", ssh_program);
 addargs(&args, "-oForwardX11 no");
 addargs(&args, "-oPermitLocalCommand no");
 addargs(&args, "-oClearAllForwardings yes");

 ll = SYSLOG_LEVEL_INFO;
 infile = 
         stdin
              ;

 while ((ch = BSDgetopt(argc, argv, "1246AafhNpqrvCc:D:i:l:o:s:S:b:B:F:J:P:R:")
                                                ) != -1) {
  switch (ch) {

  case 'A':
  case '4':
  case '6':
  case 'C':
   addargs(&args, "-%c", ch);
   break;

  case 'F':
  case 'J':
  case 'c':
  case 'i':
  case 'o':
   addargs(&args, "-%c", ch);
   addargs(&args, "%s", BSDoptarg);
   break;
  case 'q':
   ll = SYSLOG_LEVEL_ERROR;
   quiet = 1;
   showprogress = 0;
   addargs(&args, "-%c", ch);
   break;
  case 'P':
   port = a2port(BSDoptarg);
   if (port <= 0)
    sshfatal("sftp.c", __func__, 2479, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Bad port \"%s\"\n", BSDoptarg);
   break;
  case 'v':
   if (debug_level < 3) {
    addargs(&args, "-v");
    ll = SYSLOG_LEVEL_DEBUG1 + debug_level;
   }
   debug_level++;
   break;
  case '1':
   sshfatal("sftp.c", __func__, 2489, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "SSH protocol v.1 is no longer supported");
   break;
  case '2':

   break;
  case 'a':
   global_aflag = 1;
   break;
  case 'B':
   copy_buffer_len = strtol(BSDoptarg, &cp, 10);
   if (copy_buffer_len == 0 || *cp != '\0')
    sshfatal("sftp.c", __func__, 2500, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Invalid buffer size \"%s\"", BSDoptarg);
   break;
  case 'b':
   if (batchmode)
    sshfatal("sftp.c", __func__, 2504, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Batch file already specified.");


   if (strcmp(BSDoptarg, "-") != 0 &&
       (infile = fopen(BSDoptarg, "r")) == 
                                       ((void *)0)
                                           )
    sshfatal("sftp.c", __func__, 2509, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s (%s).", strerror(
   (*__errno_location ())
   ), BSDoptarg);
   showprogress = 0;
   quiet = batchmode = 1;
   addargs(&args, "-obatchmode yes");
   break;
  case 'f':
   global_fflag = 1;
   break;
  case 'N':
   noisy = 1;
   break;
  case 'p':
   global_pflag = 1;
   break;
  case 'D':
   sftp_direct = BSDoptarg;
   break;
  case 'l':
   limit_kbps = strtonum(BSDoptarg, 1, 100 * 1024 * 1024,
       &errstr);
   if (errstr != 
                ((void *)0)
                    )
    usage();
   limit_kbps *= 1024;
   break;
  case 'r':
   global_rflag = 1;
   break;
  case 'R':
   num_requests = strtol(BSDoptarg, &cp, 10);
   if (num_requests == 0 || *cp != '\0')
    sshfatal("sftp.c", __func__, 2539, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Invalid number of requests \"%s\"", BSDoptarg)
               ;
   break;
  case 's':
   sftp_server = BSDoptarg;
   break;
  case 'S':
   ssh_program = BSDoptarg;
   replacearg(&args, 0, "%s", ssh_program);
   break;
  case 'h':
  default:
   usage();
  }
 }


 addargs(&args, "-oForwardAgent no");

 if (!isatty(
            2
                         ))
  showprogress = 0;

 if (noisy)
  quiet = 0;

 log_init(argv[0], ll, SYSLOG_FACILITY_USER, 1);

 if (sftp_direct == 
                   ((void *)0)
                       ) {
  if (BSDoptind == argc || argc > (BSDoptind + 2))
   usage();
  argv += BSDoptind;

  switch (parse_uri("sftp", *argv, &user, &host, &tmp, &file1)) {
  case -1:
   usage();
   break;
  case 0:
   if (tmp != -1)
    port = tmp;
   break;
  default:

   if (parse_user_host_path(*argv, &user, &host,
       &file1) == 0)
    break;

   if (parse_user_host_port(*argv, &user, &host, 
                                                ((void *)0)
                                                    )
       == 0)
    break;

   host = xstrdup(*argv);
   host = cleanhostname(host);
   break;
  }
  file2 = *(argv + 1);

  if (!*host) {
   fprintf(
          stderr
                , "Missing hostname\n");
   usage();
  }

  if (port != -1)
   addargs(&args, "-oPort %d", port);
  if (user != 
             ((void *)0)
                 ) {
   addargs(&args, "-l");
   addargs(&args, "%s", user);
  }


  if (sftp_server == 
                    ((void *)0) 
                         || strchr(sftp_server, '/') == 
                                                        ((void *)0)
                                                            )
   addargs(&args, "-s");

  addargs(&args, "--");
  addargs(&args, "%s", host);
  addargs(&args, "%s", (sftp_server != 
                                      ((void *)0) 
                                           ?
      sftp_server : "sftp"));

  connect_to_server(ssh_program, args.list, &in, &out);
 } else {
  if ((r = argv_split(sftp_direct, &tmp, &cpp, 1)) != 0)
   sshfatal("sftp.c", __func__, 2619, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Parse -D arguments");
  if (cpp[0] == 0)
   sshfatal("sftp.c", __func__, 2621, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "No sftp server specified via -D");
  connect_to_server(cpp[0], cpp, &in, &out);
  argv_free(cpp, tmp);
 }
 freeargs(&args);

 conn = do_init(in, out, copy_buffer_len, num_requests, limit_kbps);
 if (conn == 
            ((void *)0)
                )
  sshfatal("sftp.c", __func__, 2629, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Couldn't initialise connection to server");

 if (!quiet) {
  if (sftp_direct == 
                    ((void *)0)
                        )
   fprintf(
          stderr
                , "Connected to %s.\n", host);
  else
   fprintf(
          stderr
                , "Attached to %s.\n", sftp_direct);
 }

 err = interactive_loop(conn, file1, file2);


 shutdown(in, 
             SHUT_RDWR
                      );
 shutdown(out, 
              SHUT_RDWR
                       );


 close(in);
 close(out);
 if (batchmode)
  fclose(infile);

 while (waitpid(sshpid, 
                       ((void *)0)
                           , 0) == -1 && sshpid > 1)
  if (
     (*__errno_location ()) 
           != 
              4
                   )
   sshfatal("sftp.c", __func__, 2652, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Couldn't wait for ssh process: %s", strerror(
  (*__errno_location ())
  ))
                       ;

 exit(err == 0 ? 0 : 1);
}
