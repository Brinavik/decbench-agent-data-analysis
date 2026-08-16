











































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
void start_progress_meter(const char *, off_t, off_t *);
void refresh_progress_meter(int);
void stop_progress_meter(void);
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

extern char *__progname;



int do_cmd(char *, char *, char *, int, int, char *, int *, int *, pid_t *);
int do_cmd2(char *, char *, int, char *, int, int);


arglist args;
arglist remote_remote_args;


long long limit_kbps = 0;
struct bwlimit bwlimit;


char *curfile;


int verbose_mode = 0;
LogLevel log_level = SYSLOG_LEVEL_INFO;


int showprogress = 1;





int throughlocal = 1;


int sshport = -1;


char *ssh_program = "/usr/local/bin/ssh";


pid_t do_cmd_pid = -1;
pid_t do_cmd_pid2 = -1;


volatile sig_atomic_t interrupted = 0;

int remote_glob(struct sftp_conn *, const char *, int,
    int (*)(const char *, int), _ssh_compat_glob_t *);

static void
killchild(int signo)
{
 if (do_cmd_pid > 1) {
  kill(do_cmd_pid, signo ? signo : 
                                  15
                                         );
  waitpid(do_cmd_pid, 
                     ((void *)0)
                         , 0);
 }
 if (do_cmd_pid2 > 1) {
  kill(do_cmd_pid2, signo ? signo : 
                                   15
                                          );
  waitpid(do_cmd_pid2, 
                      ((void *)0)
                          , 0);
 }

 if (signo)
  _exit(1);
 exit(1);
}

static void
suspone(int pid, int signo)
{
 int status;

 if (pid > 1) {
  kill(pid, signo);
  while (waitpid(pid, &status, 
                              2
                                       ) == -1 &&
      
     (*__errno_location ()) 
           == 
              4
                   )
   ;
 }
}

static void
suspchild(int signo)
{
 suspone(do_cmd_pid, signo);
 suspone(do_cmd_pid2, signo);
 kill(getpid(), 
               19
                      );
}

static int
do_local_cmd(arglist *a)
{
 u_int i;
 int status;
 pid_t pid;

 if (a->num == 0)
  sshfatal("scp.c", __func__, 231, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "do_local_cmd: no arguments");

 if (verbose_mode) {
  fprintf(
         stderr
               , "Executing:");
  for (i = 0; i < a->num; i++)
   fmprintf(
           stderr
                 , " %s", a->list[i]);
  fprintf(
         stderr
               , "\n");
 }
 if ((pid = fork()) == -1)
  sshfatal("scp.c", __func__, 240, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "do_local_cmd: fork: %s", strerror(
 (*__errno_location ())
 ));

 if (pid == 0) {
  execvp(a->list[0], a->list);
  perror(a->list[0]);
  exit(1);
 }

 do_cmd_pid = pid;
 ssh_signal(
           15
                  , killchild);
 ssh_signal(
           2
                 , killchild);
 ssh_signal(
           1
                 , killchild);

 while (waitpid(pid, &status, 0) == -1)
  if (
     (*__errno_location ()) 
           != 
              4
                   )
   sshfatal("scp.c", __func__, 255, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "do_local_cmd: waitpid: %s", strerror(
  (*__errno_location ())
  ));

 do_cmd_pid = -1;

 if (!
     (((
     status
     ) & 0x7f) == 0) 
                       || 
                          (((
                          status
                          ) & 0xff00) >> 8) 
                                              != 0)
  return (-1);

 return (0);
}







int
do_cmd(char *program, char *host, char *remuser, int port, int subsystem,
    char *cmd, int *fdin, int *fdout, pid_t *pid)
{
 int pin[2], pout[2], reserved[2];

 if (verbose_mode)
  fmprintf(
          stderr
                ,
      "Executing: program %s host %s, user %s, command %s\n",
      program, host,
      remuser ? remuser : "(unspecified)", cmd);

 if (port == -1)
  port = sshport;





 if (pipe(reserved) == -1)
  sshfatal("scp.c", __func__, 291, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "pipe: %s", strerror(
 (*__errno_location ())
 ));


 if (pipe(pin) == -1)
  sshfatal("scp.c", __func__, 295, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "pipe: %s", strerror(
 (*__errno_location ())
 ));
 if (pipe(pout) == -1)
  sshfatal("scp.c", __func__, 297, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "pipe: %s", strerror(
 (*__errno_location ())
 ));


 close(reserved[0]);
 close(reserved[1]);

 ssh_signal(
           20
                  , suspchild);
 ssh_signal(
           21
                  , suspchild);
 ssh_signal(
           22
                  , suspchild);


 *pid = fork();
 if (*pid == 0) {

  close(pin[1]);
  close(pout[0]);
  dup2(pin[0], 0);
  dup2(pout[1], 1);
  close(pin[0]);
  close(pout[1]);

  replacearg(&args, 0, "%s", program);
  if (port != -1) {
   addargs(&args, "-p");
   addargs(&args, "%d", port);
  }
  if (remuser != 
                ((void *)0)
                    ) {
   addargs(&args, "-l");
   addargs(&args, "%s", remuser);
  }
  if (subsystem)
   addargs(&args, "-s");
  addargs(&args, "--");
  addargs(&args, "%s", host);
  addargs(&args, "%s", cmd);

  execvp(program, args.list);
  perror(program);
  exit(1);
 } else if (*pid == -1) {
  sshfatal("scp.c", __func__, 337, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "fork: %s", strerror(
 (*__errno_location ())
 ));
 }

 close(pin[0]);
 *fdout = pin[1];
 close(pout[1]);
 *fdin = pout[0];
 ssh_signal(
           15
                  , killchild);
 ssh_signal(
           2
                 , killchild);
 ssh_signal(
           1
                 , killchild);
 return 0;
}






int
do_cmd2(char *host, char *remuser, int port, char *cmd,
    int fdin, int fdout)
{
 int status;
 pid_t pid;

 if (verbose_mode)
  fmprintf(
          stderr
                ,
      "Executing: 2nd program %s host %s, user %s, command %s\n",
      ssh_program, host,
      remuser ? remuser : "(unspecified)", cmd);

 if (port == -1)
  port = sshport;


 pid = fork();
 if (pid == 0) {
  dup2(fdin, 0);
  dup2(fdout, 1);

  replacearg(&args, 0, "%s", ssh_program);
  if (port != -1) {
   addargs(&args, "-p");
   addargs(&args, "%d", port);
  }
  if (remuser != 
                ((void *)0)
                    ) {
   addargs(&args, "-l");
   addargs(&args, "%s", remuser);
  }
  addargs(&args, "-oBatchMode=yes");
  addargs(&args, "--");
  addargs(&args, "%s", host);
  addargs(&args, "%s", cmd);

  execvp(ssh_program, args.list);
  perror(ssh_program);
  exit(1);
 } else if (pid == -1) {
  sshfatal("scp.c", __func__, 395, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "fork: %s", strerror(
 (*__errno_location ())
 ));
 }
 while (waitpid(pid, &status, 0) == -1)
  if (
     (*__errno_location ()) 
           != 
              4
                   )
   sshfatal("scp.c", __func__, 399, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "do_cmd2: waitpid: %s", strerror(
  (*__errno_location ())
  ));
 return 0;
}

typedef struct {
 size_t cnt;
 char *buf;
} BUF;

BUF *allocbuf(BUF *, int, int);
void lostconn(int);
int okname(char *);
void run_err(const char *,...)
    __attribute__((__format__ (printf, 1, 2)))
    __attribute__((__nonnull__ (1)));
int note_err(const char *,...)
    __attribute__((__format__ (printf, 1, 2)));
void verifydir(char *);

struct passwd *pwd;
uid_t userid;
int errs, remin, remout, remin2, remout2;
int Tflag, pflag, iamremote, iamrecursive, targetshouldbedirectory;


char cmd[64];

enum scp_mode_e {
 MODE_SCP,
 MODE_SFTP
};

int response(void);
void rsource(char *, struct stat *);
void sink(int, char *[], const char *);
void source(int, char *[]);
void tolocal(int, char *[], enum scp_mode_e, char *sftp_direct);
void toremote(int, char *[], enum scp_mode_e, char *sftp_direct);
void usage(void);

void source_sftp(int, char *, char *, struct sftp_conn *);
void sink_sftp(int, char *, const char *, struct sftp_conn *);
void throughlocal_sftp(struct sftp_conn *, struct sftp_conn *,
    char *, char *);

int
main(int argc, char **argv)
{
 int ch, fflag, tflag, status, n;
 char **newargv, *argv0;
 const char *errstr;
 extern char *BSDoptarg;
 extern int BSDoptind;
 enum scp_mode_e mode = MODE_SFTP;
 char *sftp_direct = 
                    ((void *)0)
                        ;


 sanitise_stdfd();

 msetlocale();


 argv0 = argv[0];
 newargv = xcalloc((((argc + 1) > (1)) ? (argc + 1) : (1)), sizeof(*newargv));
 for (n = 0; n < argc; n++)
  newargv[n] = xstrdup(argv[n]);
 argv = newargv;

 __progname = ssh_get_progname(argv[0]);

 log_init(argv0, log_level, SYSLOG_FACILITY_USER, 2);

 memset(&args, '\0', sizeof(args));
 memset(&remote_remote_args, '\0', sizeof(remote_remote_args));
 args.list = remote_remote_args.list = 
                                      ((void *)0)
                                          ;
 addargs(&args, "%s", ssh_program);
 addargs(&args, "-x");
 addargs(&args, "-oPermitLocalCommand=no");
 addargs(&args, "-oClearAllForwardings=yes");
 addargs(&args, "-oRemoteCommand=none");
 addargs(&args, "-oRequestTTY=no");

 fflag = Tflag = tflag = 0;
 while ((ch = BSDgetopt(argc, argv, "12346ABCTdfOpqRrstvD:F:J:M:P:S:c:i:l:o:")
                                               ) != -1) {
  switch (ch) {

  case '1':
   sshfatal("scp.c", __func__, 487, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "SSH protocol v.1 is no longer supported");
   break;
  case '2':

   break;
  case 'A':
  case '4':
  case '6':
  case 'C':
   addargs(&args, "-%c", ch);
   addargs(&remote_remote_args, "-%c", ch);
   break;
  case 'D':
   sftp_direct = BSDoptarg;
   break;
  case '3':
   throughlocal = 1;
   break;
  case 'R':
   throughlocal = 0;
   break;
  case 'o':
  case 'c':
  case 'i':
  case 'F':
  case 'J':
   addargs(&remote_remote_args, "-%c", ch);
   addargs(&remote_remote_args, "%s", BSDoptarg);
   addargs(&args, "-%c", ch);
   addargs(&args, "%s", BSDoptarg);
   break;
  case 'O':
   mode = MODE_SCP;
   break;
  case 's':
   mode = MODE_SFTP;
   break;
  case 'P':
   sshport = a2port(BSDoptarg);
   if (sshport <= 0)
    sshfatal("scp.c", __func__, 527, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "bad port \"%s\"\n", BSDoptarg);
   break;
  case 'B':
   addargs(&remote_remote_args, "-oBatchmode=yes");
   addargs(&args, "-oBatchmode=yes");
   break;
  case 'l':
   limit_kbps = strtonum(BSDoptarg, 1, 100 * 1024 * 1024,
       &errstr);
   if (errstr != 
                ((void *)0)
                    )
    usage();
   limit_kbps *= 1024;
   bandwidth_limit_init(&bwlimit, limit_kbps, 16384);
   break;
  case 'p':
   pflag = 1;
   break;
  case 'r':
   iamrecursive = 1;
   break;
  case 'S':
   ssh_program = xstrdup(BSDoptarg);
   break;
  case 'v':
   addargs(&args, "-v");
   addargs(&remote_remote_args, "-v");
   if (verbose_mode == 0)
    log_level = SYSLOG_LEVEL_DEBUG1;
   else if (log_level < SYSLOG_LEVEL_DEBUG3)
    log_level++;
   verbose_mode = 1;
   break;
  case 'q':
   addargs(&args, "-q");
   addargs(&remote_remote_args, "-q");
   showprogress = 0;
   break;


  case 'd':
   targetshouldbedirectory = 1;
   break;
  case 'f':
   iamremote = 1;
   fflag = 1;
   break;
  case 't':
   iamremote = 1;
   tflag = 1;



   break;
  case 'T':
   Tflag = 1;
   break;
  default:
   usage();
  }
 }
 argc -= BSDoptind;
 argv += BSDoptind;

 log_init(argv0, log_level, SYSLOG_FACILITY_USER, 2);


 addargs(&args, "-oForwardAgent=no");

 if (iamremote)
  mode = MODE_SCP;

 if ((pwd = getpwuid(userid = getuid())) == 
                                           ((void *)0)
                                               )
  sshfatal("scp.c", __func__, 599, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "unknown user %u", (u_int) userid);

 if (!isatty(
            1
                         ))
  showprogress = 0;

 if (pflag) {

 } else {
  if (pledge("stdio rpath wpath cpath fattr tty proc exec",
      
     ((void *)0)
         ) == -1) {
   perror("pledge");
   exit(1);
  }
 }

 remin = 
        0
                    ;
 remout = 
         1
                      ;

 if (fflag) {

  (void) response();
  source(argc, argv);
  exit(errs != 0);
 }
 if (tflag) {

  sink(argc, argv, 
                  ((void *)0)
                      );
  exit(errs != 0);
 }
 if (argc < 2)
  usage();
 if (argc > 2)
  targetshouldbedirectory = 1;

 remin = remout = -1;
 do_cmd_pid = -1;

 (void) snprintf(cmd, sizeof cmd, "scp%s%s%s%s",
     verbose_mode ? " -v" : "",
     iamrecursive ? " -r" : "", pflag ? " -p" : "",
     targetshouldbedirectory ? " -d" : "");

 (void) ssh_signal(
                  13
                         , lostconn);

 if (colon(argv[argc - 1]))
  toremote(argc, argv, mode, sftp_direct);
 else {
  if (targetshouldbedirectory)
   verifydir(argv[argc - 1]);
  tolocal(argc, argv, mode, sftp_direct);
 }




 if (do_cmd_pid != -1 && (mode == MODE_SFTP || errs == 0)) {
  if (remin != -1)
      (void) close(remin);
  if (remout != -1)
      (void) close(remout);
  if (waitpid(do_cmd_pid, &status, 0) == -1)
   errs = 1;
  else {
   if (!
       (((
       status
       ) & 0x7f) == 0) 
                         || 
                            (((
                            status
                            ) & 0xff00) >> 8) 
                                                != 0)
    errs = 1;
  }
 }
 exit(errs != 0);
}


static int
scpio(void *_cnt, size_t s)
{
 off_t *cnt = (off_t *)_cnt;

 *cnt += s;
 refresh_progress_meter(0);
 if (limit_kbps > 0)
  bandwidth_limit(&bwlimit, s);
 return 0;
}

static int
do_times(int fd, int verb, const struct stat *sb)
{

 char buf[(20 + 7 + 2) * 2 + 2];

 (void)snprintf(buf, sizeof(buf), "T%llu 0 %llu 0\n",
     (unsigned long long) (sb->
                              st_mtim.tv_sec 
                                       < 0 ? 0 : sb->
                                                     st_mtim.tv_sec
                                                             ),
     (unsigned long long) (sb->
                              st_atim.tv_sec 
                                       < 0 ? 0 : sb->
                                                     st_atim.tv_sec
                                                             ));
 if (verb) {
  fprintf(
         stderr
               , "File mtime %lld atime %lld\n",
      (long long)sb->
                    st_mtim.tv_sec
                            , (long long)sb->
                                             st_atim.tv_sec
                                                     );
  fprintf(
         stderr
               , "Sending file timestamps: %s", buf);
 }
 (void) atomicio((ssize_t (*)(int, void *, size_t))write, fd, buf, strlen(buf));
 return (response());
}

static int
parse_scp_uri(const char *uri, char **userp, char **hostp, int *portp,
    char **pathp)
{
 int r;

 r = parse_uri("scp", uri, userp, hostp, portp, pathp);
 if (r == 0 && *pathp == 
                        ((void *)0)
                            )
  *pathp = xstrdup(".");
 return r;
}


static int
append(char *cp, char ***ap, size_t *np)
{
 char **tmp;

 if ((tmp = reallocarray(*ap, *np + 1, sizeof(*tmp))) == 
                                                        ((void *)0)
                                                            )
  return -1;
 tmp[(*np)] = cp;
 (*np)++;
 *ap = tmp;
 return 0;
}





static int
find_brace(const char *pattern, int *startp, int *endp)
{
 int i;
 int in_bracket, brace_level;

 *startp = *endp = -1;
 in_bracket = brace_level = 0;
 for (i = 0; i < 0x7fffffff && *endp < 0 && pattern[i] != '\0'; i++) {
  switch (pattern[i]) {
  case '\\':

   if (pattern[i + 1] != '\0')
    i++;
   break;
  case '[':
   in_bracket = 1;
   break;
  case ']':
   in_bracket = 0;
   break;
  case '{':
   if (in_bracket)
    break;
   if (pattern[i + 1] == '}') {

    i++;
    break;
   }
   if (*startp == -1)
    *startp = i;
   brace_level++;
   break;
  case '}':
   if (in_bracket)
    break;
   if (*startp < 0) {

    return -1;
   }
   if (--brace_level <= 0)
    *endp = i;
   break;
  }
 }

 if (*endp < 0 && (*startp >= 0 || in_bracket))
  return -1;
 return 0;
}





static int
emit_expansion(const char *pattern, int brace_start, int brace_end,
    int sel_start, int sel_end, char ***patternsp, size_t *npatternsp)
{
 char *cp;
 int o = 0, tail_len = strlen(pattern + brace_end + 1);

 if ((cp = malloc(brace_start + (sel_end - sel_start) +
     tail_len + 1)) == 
                      ((void *)0)
                          )
  return -1;


 if (brace_start > 0) {
  memcpy(cp, pattern, brace_start);
  o = brace_start;
 }

 if (sel_end - sel_start > 0) {
  memcpy(cp + o, pattern + sel_start,
      sel_end - sel_start);
  o += sel_end - sel_start;
 }

 if (tail_len > 0) {
  memcpy(cp + o, pattern + brace_end + 1, tail_len);
  o += tail_len;
 }
 cp[o] = '\0';
 if (append(cp, patternsp, npatternsp) != 0) {
  free(cp);
  return -1;
 }
 return 0;
}
static int
brace_expand_one(const char *pattern, char ***patternsp, size_t *npatternsp,
    int *expanded, int *invalid)
{
 int i;
 int in_bracket, brace_start, brace_end, brace_level;
 int sel_start, sel_end;

 *invalid = *expanded = 0;

 if (find_brace(pattern, &brace_start, &brace_end) != 0) {
  *invalid = 1;
  return 0;
 } else if (brace_start == -1)
  return 0;

 in_bracket = brace_level = 0;
 for (i = sel_start = brace_start + 1; i < brace_end; i++) {
  switch (pattern[i]) {
  case '{':
   if (in_bracket)
    break;
   brace_level++;
   break;
  case '}':
   if (in_bracket)
    break;
   brace_level--;
   break;
  case '[':
   in_bracket = 1;
   break;
  case ']':
   in_bracket = 0;
   break;
  case '\\':
   if (i < brace_end - 1)
    i++;
   break;
  }
  if (pattern[i] == ',' || i == brace_end - 1) {
   if (in_bracket || brace_level > 0)
    continue;



   sel_end = (i == brace_end - 1) ? brace_end : i;
   if (emit_expansion(pattern, brace_start, brace_end,
       sel_start, sel_end, patternsp, npatternsp) != 0)
    return -1;

   sel_start = i + 1;
   continue;
  }
 }
 if (in_bracket || brace_level > 0) {
  *invalid = 1;
  return 0;
 }

 *expanded = 1;
 return 0;
}


static int
brace_expand(const char *pattern, char ***patternsp, size_t *npatternsp)
{
 char *cp, *cp2, **active = 
                           ((void *)0)
                               , **done = 
                                          ((void *)0)
                                              ;
 size_t i, nactive = 0, ndone = 0;
 int ret = -1, invalid = 0, expanded = 0;

 *patternsp = 
             ((void *)0)
                 ;
 *npatternsp = 0;


 if ((cp = strdup(pattern)) == 
                              ((void *)0)
                                  )
  return -1;
 if (append(cp, &active, &nactive) != 0) {
  free(cp);
  return -1;
 }
 while (nactive > 0) {
  cp = active[nactive - 1];
  nactive--;
  if (brace_expand_one(cp, &active, &nactive,
      &expanded, &invalid) == -1) {
   free(cp);
   goto fail;
  }
  if (invalid)
   sshfatal("scp.c", __func__, 920, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "invalid brace pattern \"%s\"", cp);
  if (expanded) {




   free(cp);
   continue;
  }




  if ((cp2 = strrchr(cp, '/')) != 
                                 ((void *)0)
                                     )
   *cp2++ = '\0';
  else
   cp2 = cp;
  if (append(xstrdup(cp2), &done, &ndone) != 0) {
   free(cp);
   goto fail;
  }
  free(cp);
 }

 *patternsp = done;
 *npatternsp = ndone;
 done = 
       ((void *)0)
           ;
 ndone = 0;
 ret = 0;
 fail:
 for (i = 0; i < nactive; i++)
  free(active[i]);
 free(active);
 for (i = 0; i < ndone; i++)
  free(done[i]);
 free(done);
 return ret;
}

static struct sftp_conn *
do_sftp_connect(char *host, char *user, int port, char *sftp_direct,
   int *reminp, int *remoutp, int *pidp)
{
 if (sftp_direct == 
                   ((void *)0)
                       ) {
  if (do_cmd(ssh_program, host, user, port, 1, "sftp",
      reminp, remoutp, pidp) < 0)
   return 
         ((void *)0)
             ;

 } else {
  freeargs(&args);
  addargs(&args, "sftp-server");
  if (do_cmd(sftp_direct, host, 
                               ((void *)0)
                                   , -1, 0, "sftp",
      reminp, remoutp, pidp) < 0)
   return 
         ((void *)0)
             ;
 }
 return do_init(*reminp, *remoutp, 32768, 64, limit_kbps);
}

void
toremote(int argc, char **argv, enum scp_mode_e mode, char *sftp_direct)
{
 char *suser = 
              ((void *)0)
                  , *host = 
                            ((void *)0)
                                , *src = 
                                         ((void *)0)
                                             ;
 char *bp, *tuser, *thost, *targ;
 int sport = -1, tport = -1;
 struct sftp_conn *conn = 
                         ((void *)0)
                             , *conn2 = 
                                        ((void *)0)
                                            ;
 arglist alist;
 int i, r, status;
 u_int j;

 memset(&alist, '\0', sizeof(alist));
 alist.list = 
             ((void *)0)
                 ;


 r = parse_scp_uri(argv[argc - 1], &tuser, &thost, &tport, &targ);
 if (r == -1) {
  fmprintf(
          stderr
                , "%s: invalid uri\n", argv[argc - 1]);
  ++errs;
  goto out;
 }
 if (r != 0) {
  if (parse_user_host_path(argv[argc - 1], &tuser, &thost,
      &targ) == -1) {
   fmprintf(
           stderr
                 , "%s: invalid target\n", argv[argc - 1]);
   ++errs;
   goto out;
  }
 }


 for (i = 0; i < argc - 1; i++) {
  free(suser);
  free(host);
  free(src);
  r = parse_scp_uri(argv[i], &suser, &host, &sport, &src);
  if (r == -1) {
   fmprintf(
           stderr
                 , "%s: invalid uri\n", argv[i]);
   ++errs;
   continue;
  }
  if (r != 0) {
   parse_user_host_path(argv[i], &suser, &host, &src);
  }
  if (suser != 
              ((void *)0) 
                   && !okname(suser)) {
   ++errs;
   continue;
  }
  if (host && throughlocal) {
   if (mode == MODE_SFTP) {
    if (remin == -1) {

     conn = do_sftp_connect(thost, tuser,
         tport, sftp_direct,
         &remin, &remout, &do_cmd_pid);
     if (conn == 
                ((void *)0)
                    ) {
      sshfatal("scp.c", __func__, 1034, 0, SYSLOG_LEVEL_FATAL, 
     ((void *)0)
     , "Unable to open " "destination connection")
                                   ;
     }
     sshlog("scp.c", __func__, 1037, 1, SYSLOG_LEVEL_DEBUG3, 
    ((void *)0)
    , "origin in %d out %d pid %ld", remin, remout, (long)do_cmd_pid)
                                         ;
    }







    conn2 = do_sftp_connect(host, suser,
        sport, sftp_direct,
        &remin2, &remout2, &do_cmd_pid2);
    if (conn2 == 
                ((void *)0)
                    ) {
     sshfatal("scp.c", __func__, 1051, 0, SYSLOG_LEVEL_FATAL, 
    ((void *)0)
    , "Unable to open " "source connection")
                             ;
    }
    sshlog("scp.c", __func__, 1054, 1, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "destination in %d out %d pid %ld", remin2, remout2, (long)do_cmd_pid2)
                                           ;
    throughlocal_sftp(conn2, conn, src, targ);
    (void) close(remin2);
    (void) close(remout2);
    remin2 = remout2 = -1;
    if (waitpid(do_cmd_pid2, &status, 0) == -1)
     ++errs;
    else if (!
             (((
             status
             ) & 0x7f) == 0) 
                               ||
        
       (((
       status
       ) & 0xff00) >> 8) 
                           != 0)
     ++errs;
    do_cmd_pid2 = -1;
    continue;
   } else {
    xasprintf(&bp, "%s -f %s%s", cmd,
        *src == '-' ? "-- " : "", src);
    if (do_cmd(ssh_program, host, suser, sport, 0,
        bp, &remin, &remout, &do_cmd_pid) < 0)
     exit(1);
    free(bp);
    xasprintf(&bp, "%s -t %s%s", cmd,
        *targ == '-' ? "-- " : "", targ);
    if (do_cmd2(thost, tuser, tport, bp,
        remin, remout) < 0)
     exit(1);
    free(bp);
    (void) close(remin);
    (void) close(remout);
    remin = remout = -1;
   }
  } else if (host) {





   if (tuser != 
               ((void *)0) 
                    && !okname(tuser)) {
    ++errs;
    continue;
   }
   if (tport != -1 && tport != 22) {

    sshfatal("scp.c", __func__, 1096, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "target port not supported with two " "remote hosts and the -R option")
                                         ;
   }

   freeargs(&alist);
   addargs(&alist, "%s", ssh_program);
   addargs(&alist, "-x");
   addargs(&alist, "-oClearAllForwardings=yes");
   addargs(&alist, "-n");
   for (j = 0; j < remote_remote_args.num; j++) {
    addargs(&alist, "%s",
        remote_remote_args.list[j]);
   }

   if (sport != -1) {
    addargs(&alist, "-p");
    addargs(&alist, "%d", sport);
   }
   if (suser) {
    addargs(&alist, "-l");
    addargs(&alist, "%s", suser);
   }
   addargs(&alist, "--");
   addargs(&alist, "%s", host);
   addargs(&alist, "%s", cmd);
   addargs(&alist, "%s", src);
   addargs(&alist, "%s%s%s:%s",
       tuser ? tuser : "", tuser ? "@" : "",
       thost, targ);
   if (do_local_cmd(&alist) != 0)
    errs = 1;
  } else {
   if (mode == MODE_SFTP) {
    if (remin == -1) {

     conn = do_sftp_connect(thost, tuser,
         tport, sftp_direct,
         &remin, &remout, &do_cmd_pid);
     if (conn == 
                ((void *)0)
                    ) {
      sshfatal("scp.c", __func__, 1135, 0, SYSLOG_LEVEL_FATAL, 
     ((void *)0)
     , "Unable to open sftp " "connection")
                       ;
     }
    }


    source_sftp(1, argv[i], targ, conn);
    continue;
   }

   if (remin == -1) {
    xasprintf(&bp, "%s -t %s%s", cmd,
        *targ == '-' ? "-- " : "", targ);
    if (do_cmd(ssh_program, thost, tuser, tport, 0,
        bp, &remin, &remout, &do_cmd_pid) < 0)
     exit(1);
    if (response() < 0)
     exit(1);
    free(bp);
   }
   source(1, argv + i);
  }
 }
out:
 if (mode == MODE_SFTP)
  free(conn);
 free(tuser);
 free(thost);
 free(targ);
 free(suser);
 free(host);
 free(src);
}

void
tolocal(int argc, char **argv, enum scp_mode_e mode, char *sftp_direct)
{
 char *bp, *host = 
                  ((void *)0)
                      , *src = 
                               ((void *)0)
                                   , *suser = 
                                              ((void *)0)
                                                  ;
 arglist alist;
 struct sftp_conn *conn = 
                         ((void *)0)
                             ;
 int i, r, sport = -1;

 memset(&alist, '\0', sizeof(alist));
 alist.list = 
             ((void *)0)
                 ;

 for (i = 0; i < argc - 1; i++) {
  free(suser);
  free(host);
  free(src);
  r = parse_scp_uri(argv[i], &suser, &host, &sport, &src);
  if (r == -1) {
   fmprintf(
           stderr
                 , "%s: invalid uri\n", argv[i]);
   ++errs;
   continue;
  }
  if (r != 0)
   parse_user_host_path(argv[i], &suser, &host, &src);
  if (suser != 
              ((void *)0) 
                   && !okname(suser)) {
   ++errs;
   continue;
  }
  if (!host) {
   freeargs(&alist);
   addargs(&alist, "%s", "cp");
   if (iamrecursive)
    addargs(&alist, "-r");
   if (pflag)
    addargs(&alist, "-p");
   addargs(&alist, "--");
   addargs(&alist, "%s", argv[i]);
   addargs(&alist, "%s", argv[argc-1]);
   if (do_local_cmd(&alist))
    ++errs;
   continue;
  }

  if (mode == MODE_SFTP) {
   conn = do_sftp_connect(host, suser, sport,
       sftp_direct, &remin, &remout, &do_cmd_pid);
   if (conn == 
              ((void *)0)
                  ) {
    sshlog("scp.c", __func__, 1215, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "sftp connection failed");
    ++errs;
    continue;
   }


   sink_sftp(1, argv[argc - 1], src, conn);

   free(conn);
   (void) close(remin);
   (void) close(remout);
   remin = remout = -1;
   continue;
  }

  xasprintf(&bp, "%s -f %s%s",
      cmd, *src == '-' ? "-- " : "", src);
  if (do_cmd(ssh_program, host, suser, sport, 0, bp,
      &remin, &remout, &do_cmd_pid) < 0) {
   free(bp);
   ++errs;
   continue;
  }
  free(bp);
  sink(1, argv + argc - 1, src);
  (void) close(remin);
  remin = remout = -1;
 }
 free(suser);
 free(host);
 free(src);
}


static char *
prepare_remote_path(struct sftp_conn *conn, const char *path)
{
 size_t nslash;


 if (*path == '\0' || strcmp(path, "~") == 0)
  return xstrdup(".");
 if (*path != '~')
  return xstrdup(path);
 if (strncmp(path, "~/", 2) == 0) {
  if ((nslash = strspn(path + 2, "/")) == strlen(path + 2))
   return xstrdup(".");
  return xstrdup(path + 2 + nslash);
 }
 if (can_expand_path(conn))
  return do_expand_path(conn, path);

 sshlog("scp.c", __func__, 1267, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "server expand-path extension is required " "for ~user paths in SFTP mode")
                                    ;
 return 
       ((void *)0)
           ;
}

void
source_sftp(int argc, char *src, char *targ, struct sftp_conn *conn)
{
 char *target = 
               ((void *)0)
                   , *filename = 
                                 ((void *)0)
                                     , *abs_dst = 
                                                  ((void *)0)
                                                      ;
 int src_is_dir, target_is_dir;
 Attrib a;
 struct stat st;

 memset(&a, '\0', sizeof(a));
 if (stat(src, &st) != 0)
  sshfatal("scp.c", __func__, 1282, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "stat local \"%s\": %s", src, strerror(
 (*__errno_location ())
 ));
 src_is_dir = 
             ((((
             st.st_mode
             )) & 0170000) == (0040000))
                                ;
 if ((filename = 
                __xpg_basename
                        (src)) == 
                                  ((void *)0)
                                      )
  sshfatal("scp.c", __func__, 1285, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "basename \"%s\": %s", src, strerror(
 (*__errno_location ())
 ));





 if ((target = prepare_remote_path(conn, targ)) == 
                                                  ((void *)0)
                                                      )
  cleanup_exit(255);
 target_is_dir = remote_is_dir(conn, target);
 if (targetshouldbedirectory && !target_is_dir) {
  sshlog("scp.c", __func__, 1295, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "target directory \"%s\" does not exist", target);
  a.flags = 0x00000004;
  a.perm = st.st_mode | 0700;
  if (do_mkdir(conn, target, &a, 1) != 0)
   cleanup_exit(255);
  target_is_dir = 1;
 }
 if (target_is_dir)
  abs_dst = path_append(target, filename);
 else {
  abs_dst = target;
  target = 
          ((void *)0)
              ;
 }
 sshlog("scp.c", __func__, 1308, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "copying local %s to remote %s", src, abs_dst);

 if (src_is_dir && iamrecursive) {
  if (upload_dir(conn, src, abs_dst, pflag,
      2, 0, 0, 1, 1) != 0) {
   sshlog("scp.c", __func__, 1313, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "failed to upload directory %s to %s", src, targ);
   errs = 1;
  }
 } else if (do_upload(conn, src, abs_dst, pflag, 0, 0, 1) != 0) {
  sshlog("scp.c", __func__, 1317, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "failed to upload file %s to %s", src, targ);
  errs = 1;
 }

 free(abs_dst);
 free(target);
}

void
source(int argc, char **argv)
{
 struct stat stb;
 static BUF buffer;
 BUF *bp;
 off_t i, statbytes;
 size_t amt, nr;
 int fd = -1, haderr, indx;
 char *last, *name, buf[
                       4096 
                                + 128], encname[
                                                4096
                                                        ];
 int len;

 for (indx = 0; indx < argc; ++indx) {
  name = argv[indx];
  statbytes = 0;
  len = strlen(name);
  while (len > 1 && name[len-1] == '/')
   name[--len] = '\0';
  if ((fd = open(name, 
                      00
                              |
                               04000
                                         )) == -1)
   goto syserr;
  if (strchr(name, '\n') != 
                           ((void *)0)
                               ) {
   strnvis(encname, name, sizeof(encname), 0x10);
   name = encname;
  }
  if (fstat(fd, &stb) == -1) {
syserr: run_err("%s: %s", name, strerror(
                                          (*__errno_location ())
                                               ));
   goto next;
  }
  if (stb.st_size < 0) {
   run_err("%s: %s", name, "Negative file size");
   goto next;
  }
  unset_nonblock(fd);
  switch (stb.st_mode & 
                       0170000
                             ) {
  case 
      0100000
             :
   break;
  case 
      0040000
             :
   if (iamrecursive) {
    rsource(name, &stb);
    goto next;
   }

  default:
   run_err("%s: not a regular file", name);
   goto next;
  }
  if ((last = strrchr(name, '/')) == 
                                    ((void *)0)
                                        )
   last = name;
  else
   ++last;
  curfile = last;
  if (pflag) {
   if (do_times(remout, verbose_mode, &stb) < 0)
    goto next;
  }

  snprintf(buf, sizeof buf, "C%04o %lld %s\n",
      (u_int) (stb.st_mode & (
                            04000
                            |
                            02000
                            |
                            (0400|0200|0100)
                            |
                            ((0400|0200|0100) >> 3)
                            |
                            (((0400|0200|0100) >> 3) >> 3)
                            )),
      (long long)stb.st_size, last);
  if (verbose_mode)
   fmprintf(
           stderr
                 , "Sending file modes: %s", buf);
  (void) atomicio((ssize_t (*)(int, void *, size_t))write, remout, buf, strlen(buf));
  if (response() < 0)
   goto next;
  if ((bp = allocbuf(&buffer, fd, 16384)) == 
                                                  ((void *)0)
                                                      ) {
next: if (fd != -1) {
    (void) close(fd);
    fd = -1;
   }
   continue;
  }
  if (showprogress)
   start_progress_meter(curfile, stb.st_size, &statbytes);
  set_nonblock(remout);
  for (haderr = i = 0; i < stb.st_size; i += bp->cnt) {
   amt = bp->cnt;
   if (i + (off_t)amt > stb.st_size)
    amt = stb.st_size - i;
   if (!haderr) {
    if ((nr = atomicio(read, fd,
        bp->buf, amt)) != amt) {
     haderr = 
             (*__errno_location ())
                  ;
     memset(bp->buf + nr, 0, amt - nr);
    }
   }

   if (haderr) {
    (void)atomicio((ssize_t (*)(int, void *, size_t))write, remout, bp->buf, amt);
    memset(bp->buf, 0, amt);
    continue;
   }
   if (atomicio6((ssize_t (*)(int, void *, size_t))write, remout, bp->buf, amt, scpio,
       &statbytes) != amt)
    haderr = 
            (*__errno_location ())
                 ;
  }
  unset_nonblock(remout);

  if (fd != -1) {
   if (close(fd) == -1 && !haderr)
    haderr = 
            (*__errno_location ())
                 ;
   fd = -1;
  }
  if (!haderr)
   (void) atomicio((ssize_t (*)(int, void *, size_t))write, remout, "", 1);
  else
   run_err("%s: %s", name, strerror(haderr));
  (void) response();
  if (showprogress)
   stop_progress_meter();
 }
}

void
rsource(char *name, struct stat *statp)
{
 DIR *dirp;
 struct dirent *dp;
 char *last, *vect[1], path[
                           4096
                                   ];

 if (!(dirp = opendir(name))) {
  run_err("%s: %s", name, strerror(
                                  (*__errno_location ())
                                       ));
  return;
 }
 last = strrchr(name, '/');
 if (last == 
            ((void *)0)
                )
  last = name;
 else
  last++;
 if (pflag) {
  if (do_times(remout, verbose_mode, statp) < 0) {
   closedir(dirp);
   return;
  }
 }
 (void) snprintf(path, sizeof path, "D%04o %d %.1024s\n",
     (u_int) (statp->st_mode & (
                              04000
                              |
                              02000
                              |
                              (0400|0200|0100)
                              |
                              ((0400|0200|0100) >> 3)
                              |
                              (((0400|0200|0100) >> 3) >> 3)
                              )), 0, last);
 if (verbose_mode)
  fmprintf(
          stderr
                , "Entering directory: %s", path);
 (void) atomicio((ssize_t (*)(int, void *, size_t))write, remout, path, strlen(path));
 if (response() < 0) {
  closedir(dirp);
  return;
 }
 while ((dp = readdir(dirp)) != 
                               ((void *)0)
                                   ) {
  if (dp->d_ino == 0)
   continue;
  if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
   continue;
  if (strlen(name) + 1 + strlen(dp->d_name) >= sizeof(path) - 1) {
   run_err("%s/%s: name too long", name, dp->d_name);
   continue;
  }
  (void) snprintf(path, sizeof path, "%s/%s", name, dp->d_name);
  vect[0] = path;
  source(1, vect);
 }
 (void) closedir(dirp);
 (void) atomicio((ssize_t (*)(int, void *, size_t))write, remout, "E\n", 2);
 (void) response();
}

void
sink_sftp(int argc, char *dst, const char *src, struct sftp_conn *conn)
{
 char *abs_src = 
                ((void *)0)
                    ;
 char *abs_dst = 
                ((void *)0)
                    ;
 _ssh_compat_glob_t g;
 char *filename, *tmp = 
                       ((void *)0)
                           ;
 int i, r, err = 0, dst_is_dir;
 struct stat st;

 memset(&g, 0, sizeof(g));





 if ((abs_src = prepare_remote_path(conn, src)) == 
                                                  ((void *)0)
                                                      ) {
  err = -1;
  goto out;
 }

 sshlog("scp.c", __func__, 1507, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "copying remote %s to local %s", abs_src, dst);
 if ((r = remote_glob(conn, abs_src, 0x0008, 
                                               ((void *)0)
                                                   , &g)) != 0) {
  if (r == (-1))
   sshlog("scp.c", __func__, 1510, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: too many glob matches", src);
  else
   sshlog("scp.c", __func__, 1512, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: %s", src, strerror(
  2
  ));
  err = -1;
  goto out;
 }

 if ((r = stat(dst, &st)) != 0)
  sshlog("scp.c", __func__, 1518, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "stat local \"%s\": %s", dst, strerror(
 (*__errno_location ())
 ));
 dst_is_dir = r == 0 && 
                       ((((
                       st.st_mode
                       )) & 0170000) == (0040000))
                                          ;

 if (g.gl_matchc > 1 && !dst_is_dir) {
  if (r == 0) {
   sshlog("scp.c", __func__, 1523, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Multiple files match pattern, but destination " "\"%s\" is not a directory", dst)
                                        ;
   err = -1;
   goto out;
  }
  sshlog("scp.c", __func__, 1528, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "creating destination \"%s\"", dst);
  if (mkdir(dst, 0777) != 0) {
   sshlog("scp.c", __func__, 1530, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "local mkdir \"%s\": %s", dst, strerror(
  (*__errno_location ())
  ));
   err = -1;
   goto out;
  }
  dst_is_dir = 1;
 }

 for (i = 0; g.gl_pathv[i] && !interrupted; i++) {
  tmp = xstrdup(g.gl_pathv[i]);
  if ((filename = 
                 __xpg_basename
                         (tmp)) == 
                                   ((void *)0)
                                       ) {
   sshlog("scp.c", __func__, 1540, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "basename %s: %s", tmp, strerror(
  (*__errno_location ())
  ));
   err = -1;
   goto out;
  }

  if (dst_is_dir)
   abs_dst = path_append(dst, filename);
  else
   abs_dst = xstrdup(dst);

  sshlog("scp.c", __func__, 1550, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Fetching %s to %s\n", g.gl_pathv[i], abs_dst);
  if (globpath_is_dir(g.gl_pathv[i]) && iamrecursive) {
   if (download_dir(conn, g.gl_pathv[i], abs_dst, 
                                                 ((void *)0)
                                                     ,
       pflag, 2, 0, 0, 1, 1) == -1)
    err = -1;
  } else {
   if (do_download(conn, g.gl_pathv[i], abs_dst, 
                                                ((void *)0)
                                                    ,
       pflag, 0, 0, 1) == -1)
    err = -1;
  }
  free(abs_dst);
  abs_dst = 
           ((void *)0)
               ;
  free(tmp);
  tmp = 
       ((void *)0)
           ;
 }

out:
 free(abs_src);
 free(tmp);
 _ssh__compat_globfree(&g);
 if (err == -1)
  errs = 1;
}







void
sink(int argc, char **argv, const char *src)
{
 static BUF buffer;
 struct stat stb;
 BUF *bp;
 off_t i;
 size_t j, count;
 int amt, exists, first, ofd;
 mode_t mode, omode, mask;
 off_t size, statbytes;
 unsigned long long ull;
 int setimes, targisdir, wrerr;
 char ch, *cp, *np, *targ, *why, *vect[1], buf[2048], visbuf[2048];
 char **patterns = 
                  ((void *)0)
                      ;
 size_t n, npatterns = 0;
 struct timeval tv[2];





 if (((sizeof(time_t) == 4 && (0) > 
    (2147483647)
    ) || (sizeof(time_t) == 8 && (0) > 
    (9223372036854775807L)
    ) || (sizeof(time_t) != 4 && sizeof(time_t) != 8)) || ((sizeof(off_t) == 4 && (0) > 
                                (2147483647)
                                ) || (sizeof(off_t) == 8 && (0) > 
                                (9223372036854775807L)
                                ) || (sizeof(off_t) != 4 && sizeof(off_t) != 8)))
  { why = "Unexpected off_t/time_t size"; goto screwup; };

 setimes = targisdir = 0;
 mask = umask(0);
 if (!pflag)
  (void) umask(mask);
 if (argc != 1) {
  run_err("ambiguous target");
  exit(1);
 }
 targ = *argv;
 if (targetshouldbedirectory)
  verifydir(targ);

 (void) atomicio((ssize_t (*)(int, void *, size_t))write, remout, "", 1);
 if (stat(targ, &stb) == 0 && 
                             ((((
                             stb.st_mode
                             )) & 0170000) == (0040000))
                                                 )
  targisdir = 1;
 if (src != 
           ((void *)0) 
                && !iamrecursive && !Tflag) {




  if (brace_expand(src, &patterns, &npatterns) != 0)
   sshfatal("scp.c", __func__, 1626, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "could not expand pattern");
 }
 for (first = 1;; first = 0) {
  cp = buf;
  if (atomicio(read, remin, cp, 1) != 1)
   goto done;
  if (*cp++ == '\n')
   { why = "unexpected <newline>"; goto screwup; };
  do {
   if (atomicio(read, remin, &ch, sizeof(ch)) != sizeof(ch))
    { why = "lost connection"; goto screwup; };
   *cp++ = ch;
  } while (cp < &buf[sizeof(buf) - 1] && ch != '\n');
  *cp = 0;
  if (verbose_mode)
   fmprintf(
           stderr
                 , "Sink: %s", buf);

  if (buf[0] == '\01' || buf[0] == '\02') {
   if (iamremote == 0) {
    (void) snmprintf(visbuf, sizeof(visbuf),
        
       ((void *)0)
           , "%s", buf + 1);
    (void) atomicio((ssize_t (*)(int, void *, size_t))write, 
                           2
                                        ,
        visbuf, strlen(visbuf));
   }
   if (buf[0] == '\02')
    exit(1);
   ++errs;
   continue;
  }
  if (buf[0] == 'E') {
   (void) atomicio((ssize_t (*)(int, void *, size_t))write, remout, "", 1);
   goto done;
  }
  if (ch == '\n')
   *--cp = 0;

  cp = buf;
  if (*cp == 'T') {
   setimes++;
   cp++;
   if (!
       ((*__ctype_b_loc ())[(int) ((
       (unsigned char)*cp
       ))] & (unsigned short int) _ISdigit)
                                  )
    { why = "mtime.sec not present"; goto screwup; };
   ull = strtoull(cp, &cp, 10);
   if (!cp || *cp++ != ' ')
    { why = "mtime.sec not delimited"; goto screwup; };
   if (((sizeof(time_t) == 4 && (ull) > 
      (2147483647)
      ) || (sizeof(time_t) == 8 && (ull) > 
      (9223372036854775807L)
      ) || (sizeof(time_t) != 4 && sizeof(time_t) != 8)))
    setimes = 0;
   tv[1].tv_sec = ull;
   tv[1].tv_usec = strtol(cp, &cp, 10);
   if (!cp || *cp++ != ' ' || tv[1].tv_usec < 0 ||
       tv[1].tv_usec > 999999)
    { why = "mtime.usec not delimited"; goto screwup; };
   if (!
       ((*__ctype_b_loc ())[(int) ((
       (unsigned char)*cp
       ))] & (unsigned short int) _ISdigit)
                                  )
    { why = "atime.sec not present"; goto screwup; };
   ull = strtoull(cp, &cp, 10);
   if (!cp || *cp++ != ' ')
    { why = "atime.sec not delimited"; goto screwup; };
   if (((sizeof(time_t) == 4 && (ull) > 
      (2147483647)
      ) || (sizeof(time_t) == 8 && (ull) > 
      (9223372036854775807L)
      ) || (sizeof(time_t) != 4 && sizeof(time_t) != 8)))
    setimes = 0;
   tv[0].tv_sec = ull;
   tv[0].tv_usec = strtol(cp, &cp, 10);
   if (!cp || *cp++ != '\0' || tv[0].tv_usec < 0 ||
       tv[0].tv_usec > 999999)
    { why = "atime.usec not delimited"; goto screwup; };
   (void) atomicio((ssize_t (*)(int, void *, size_t))write, remout, "", 1);
   continue;
  }
  if (*cp != 'C' && *cp != 'D') {







   if (first) {
    run_err("%s", cp);
    exit(1);
   }
   { why = "expected control record"; goto screwup; };
  }
  mode = 0;
  for (++cp; cp < buf + 5; cp++) {
   if (*cp < '0' || *cp > '7')
    { why = "bad mode"; goto screwup; };
   mode = (mode << 3) | (*cp - '0');
  }
  if (!pflag)
   mode &= ~mask;
  if (*cp++ != ' ')
   { why = "mode not delimited"; goto screwup; };

  if (!
      ((*__ctype_b_loc ())[(int) ((
      (unsigned char)*cp
      ))] & (unsigned short int) _ISdigit)
                                 )
   { why = "size not present"; goto screwup; };
  ull = strtoull(cp, &cp, 10);
  if (!cp || *cp++ != ' ')
   { why = "size not delimited"; goto screwup; };
  if (((sizeof(off_t) == 4 && (ull) > 
     (2147483647)
     ) || (sizeof(off_t) == 8 && (ull) > 
     (9223372036854775807L)
     ) || (sizeof(off_t) != 4 && sizeof(off_t) != 8)))
   { why = "size out of range"; goto screwup; };
  size = (off_t)ull;

  if (*cp == '\0' || strchr(cp, '/') != 
                                       ((void *)0) 
                                            ||
      strcmp(cp, ".") == 0 || strcmp(cp, "..") == 0) {
   run_err("error: unexpected filename: %s", cp);
   exit(1);
  }
  if (npatterns > 0) {
   for (n = 0; n < npatterns; n++) {
    if (fnmatch(patterns[n], cp, 0) == 0)
     break;
   }
   if (n >= npatterns)
    { why = "filename does not match request"; goto screwup; };
  }
  if (targisdir) {
   static char *namebuf;
   static size_t cursize;
   size_t need;

   need = strlen(targ) + strlen(cp) + 250;
   if (need > cursize) {
    free(namebuf);
    namebuf = xmalloc(need);
    cursize = need;
   }
   (void) snprintf(namebuf, need, "%s%s%s", targ,
       strcmp(targ, "/") ? "/" : "", cp);
   np = namebuf;
  } else
   np = targ;
  curfile = cp;
  exists = stat(np, &stb) == 0;
  if (buf[0] == 'D') {
   int mod_flag = pflag;
   if (!iamrecursive)
    { why = "received directory without -r"; goto screwup; };
   if (exists) {
    if (!
        ((((
        stb.st_mode
        )) & 0170000) == (0040000))
                            ) {
     
    (*__errno_location ()) 
          = 
            20
                   ;
     goto bad;
    }
    if (pflag)
     (void) chmod(np, mode);
   } else {

    mod_flag = 1;
    if (mkdir(np, mode | 
                        (0400|0200|0100)
                               ) == -1)
     goto bad;
   }
   vect[0] = xstrdup(np);
   sink(1, vect, src);
   if (setimes) {
    setimes = 0;
    (void) utimes(vect[0], tv);
   }
   if (mod_flag)
    (void) chmod(vect[0], mode);
   free(vect[0]);
   continue;
  }
  omode = mode;
  mode |= 
         0200
                ;
  if ((ofd = open(np, 
                     01
                             |
                              0100
                                     , mode)) == -1) {
bad: run_err("%s: %s", np, strerror(
                                     (*__errno_location ())
                                          ));
   continue;
  }
  (void) atomicio((ssize_t (*)(int, void *, size_t))write, remout, "", 1);
  if ((bp = allocbuf(&buffer, ofd, 16384)) == 
                                                   ((void *)0)
                                                       ) {
   (void) close(ofd);
   continue;
  }
  cp = bp->buf;
  wrerr = 0;






  statbytes = 0;
  if (showprogress)
   start_progress_meter(curfile, size, &statbytes);
  set_nonblock(remin);
  for (count = i = 0; i < size; i += bp->cnt) {
   amt = bp->cnt;
   if (i + amt > size)
    amt = size - i;
   count += amt;
   do {
    j = atomicio6(read, remin, cp, amt,
        scpio, &statbytes);
    if (j == 0) {
     run_err("%s", j != 
                       32 
                             ?
         strerror(
                 (*__errno_location ())
                      ) :
         "dropped connection");
     exit(1);
    }
    amt -= j;
    cp += j;
   } while (amt > 0);

   if (count == bp->cnt) {

    if (!wrerr) {
     if (atomicio((ssize_t (*)(int, void *, size_t))write, ofd, bp->buf,
         count) != count) {
      note_err("%s: %s", np,
          strerror(
                  (*__errno_location ())
                       ));
      wrerr = 1;
     }
    }
    count = 0;
    cp = bp->buf;
   }
  }
  unset_nonblock(remin);
  if (count != 0 && !wrerr &&
      atomicio((ssize_t (*)(int, void *, size_t))write, ofd, bp->buf, count) != count) {
   note_err("%s: %s", np, strerror(
                                  (*__errno_location ())
                                       ));
   wrerr = 1;
  }
  if (!wrerr && (!exists || 
                           ((((
                           stb.st_mode
                           )) & 0170000) == (0100000))
                                               ) &&
      ftruncate(ofd, size) != 0)
   note_err("%s: truncate: %s", np, strerror(
                                            (*__errno_location ())
                                                 ));
  if (pflag) {
   if (exists || omode != mode)

    if (fchmod(ofd, omode)) {



     note_err("%s: set mode: %s",
         np, strerror(
                     (*__errno_location ())
                          ));
    }
  } else {
   if (!exists && omode != mode)

    if (fchmod(ofd, omode & ~mask)) {



     note_err("%s: set mode: %s",
         np, strerror(
                     (*__errno_location ())
                          ));
    }
  }
  if (close(ofd) == -1)
   note_err("%s: close: %s", np, strerror(
                                         (*__errno_location ())
                                              ));
  (void) response();
  if (showprogress)
   stop_progress_meter();
  if (setimes && !wrerr) {
   setimes = 0;
   if (utimes(np, tv) == -1) {
    note_err("%s: set times: %s",
        np, strerror(
                    (*__errno_location ())
                         ));
   }
  }

  if (note_err(
              ((void *)0)
                  ) == 0)
   (void) atomicio((ssize_t (*)(int, void *, size_t))write, remout, "", 1);
 }
done:
 for (n = 0; n < npatterns; n++)
  free(patterns[n]);
 free(patterns);
 return;
screwup:
 for (n = 0; n < npatterns; n++)
  free(patterns[n]);
 free(patterns);
 run_err("protocol error: %s", why);
 exit(1);
}

void
throughlocal_sftp(struct sftp_conn *from, struct sftp_conn *to,
    char *src, char *targ)
{
 char *target = 
               ((void *)0)
                   , *filename = 
                                 ((void *)0)
                                     , *abs_dst = 
                                                  ((void *)0)
                                                      ;
 char *abs_src = 
                ((void *)0)
                    , *tmp = 
                             ((void *)0)
                                 ;
 _ssh_compat_glob_t g;
 int i, r, targetisdir, err = 0;

 if ((filename = 
                __xpg_basename
                        (src)) == 
                                  ((void *)0)
                                      )
  sshfatal("scp.c", __func__, 1910, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "basename %s: %s", src, strerror(
 (*__errno_location ())
 ));

 if ((abs_src = prepare_remote_path(from, src)) == 
                                                  ((void *)0) 
                                                       ||
     (target = prepare_remote_path(to, targ)) == 
                                                ((void *)0)
                                                    )
  cleanup_exit(255);
 memset(&g, 0, sizeof(g));

 targetisdir = remote_is_dir(to, target);
 if (!targetisdir && targetshouldbedirectory) {
  sshlog("scp.c", __func__, 1919, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s: destination is not a directory", targ);
  err = -1;
  goto out;
 }

 sshlog("scp.c", __func__, 1924, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "copying remote %s to remote %s", abs_src, target);
 if ((r = remote_glob(from, abs_src, 0x0008, 
                                               ((void *)0)
                                                   , &g)) != 0) {
  if (r == (-1))
   sshlog("scp.c", __func__, 1927, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: too many glob matches", src);
  else
   sshlog("scp.c", __func__, 1929, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: %s", src, strerror(
  2
  ));
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
   sshlog("scp.c", __func__, 1937, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "basename %s: %s", tmp, strerror(
  (*__errno_location ())
  ));
   err = -1;
   goto out;
  }

  if (targetisdir)
   abs_dst = path_append(target, filename);
  else
   abs_dst = xstrdup(target);

  sshlog("scp.c", __func__, 1947, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Fetching %s to %s\n", g.gl_pathv[i], abs_dst);
  if (globpath_is_dir(g.gl_pathv[i]) && iamrecursive) {
   if (crossload_dir(from, to, g.gl_pathv[i], abs_dst,
       
      ((void *)0)
          , pflag, 2, 1) == -1)
    err = -1;
  } else {
   if (do_crossload(from, to, g.gl_pathv[i], abs_dst, 
                                                     ((void *)0)
                                                         ,
       pflag) == -1)
    err = -1;
  }
  free(abs_dst);
  abs_dst = 
           ((void *)0)
               ;
  free(tmp);
  tmp = 
       ((void *)0)
           ;
 }

out:
 free(abs_src);
 free(abs_dst);
 free(target);
 free(tmp);
 _ssh__compat_globfree(&g);
 if (err == -1)
  errs = 1;
}

int
response(void)
{
 char ch, *cp, resp, rbuf[2048], visbuf[2048];

 if (atomicio(read, remin, &resp, sizeof(resp)) != sizeof(resp))
  lostconn(0);

 cp = rbuf;
 switch (resp) {
 case 0:
  return (0);
 default:
  *cp++ = resp;

 case 1:
 case 2:
  do {
   if (atomicio(read, remin, &ch, sizeof(ch)) != sizeof(ch))
    lostconn(0);
   *cp++ = ch;
  } while (cp < &rbuf[sizeof(rbuf) - 1] && ch != '\n');

  if (!iamremote) {
   cp[-1] = '\0';
   (void) snmprintf(visbuf, sizeof(visbuf),
       
      ((void *)0)
          , "%s\n", rbuf);
   (void) atomicio((ssize_t (*)(int, void *, size_t))write, 
                          2
                                       ,
       visbuf, strlen(visbuf));
  }
  ++errs;
  if (resp == 1)
   return (-1);
  exit(1);
 }

}

void
usage(void)
{
 (void) fprintf(
               stderr
                     ,
     "usage: scp [-346ABCOpqRrsTv] [-c cipher] [-D sftp_server_path] [-F ssh_config]\n"
     "           [-i identity_file] [-J destination] [-l limit]\n"
     "           [-o ssh_option] [-P port] [-S program] source ... target\n");
 exit(1);
}

void
run_err(const char *fmt,...)
{
 static FILE *fp;
 va_list ap;

 ++errs;
 if (fp != 
          ((void *)0) 
               || (remout != -1 && (fp = fdopen(remout, "w")))) {
  (void) fprintf(fp, "%c", 0x01);
  (void) fprintf(fp, "scp: ");
  
 __builtin_va_start(
 ap
 ,
 fmt
 )
                  ;
  (void) vfprintf(fp, fmt, ap);
  
 __builtin_va_end(
 ap
 )
           ;
  (void) fprintf(fp, "\n");
  (void) fflush(fp);
 }

 if (!iamremote) {
  
 __builtin_va_start(
 ap
 ,
 fmt
 )
                  ;
  vfmprintf(
           stderr
                 , fmt, ap);
  
 __builtin_va_end(
 ap
 )
           ;
  fprintf(
         stderr
               , "\n");
 }
}






int
note_err(const char *fmt, ...)
{
 static char *emsg;
 va_list ap;


 if (fmt == 
           ((void *)0)
               ) {
  if (emsg == 
             ((void *)0)
                 )
   return 0;
  run_err("%s", emsg);
  free(emsg);
  emsg = 
        ((void *)0)
            ;
  return -1;
 }

 errs++;

 if (emsg != 
            ((void *)0)
                )
  return -1;

 
__builtin_va_start(
ap
,
fmt
)
                 ;
 vasnmprintf(&emsg, 0x7fffffff, 
                            ((void *)0)
                                , fmt, ap);
 
__builtin_va_end(
ap
)
          ;
 return -1;
}

void
verifydir(char *cp)
{
 struct stat stb;

 if (!stat(cp, &stb)) {
  if (
     ((((
     stb.st_mode
     )) & 0170000) == (0040000))
                         )
   return;
  
 (*__errno_location ()) 
       = 
         20
                ;
 }
 run_err("%s: %s", cp, strerror(
                               (*__errno_location ())
                                    ));
 killchild(0);
}

int
okname(char *cp0)
{
 int c;
 char *cp;

 cp = cp0;
 do {
  c = (int)*cp;
  if (c & 0200)
   goto bad;
  if (!
      ((*__ctype_b_loc ())[(int) ((
      c
      ))] & (unsigned short int) _ISalpha) 
                 && !
                     ((*__ctype_b_loc ())[(int) ((
                     (unsigned char)c
                     ))] & (unsigned short int) _ISdigit)
                                              ) {
   switch (c) {
   case '\'':
   case '"':
   case '`':
   case ' ':
   case '#':
    goto bad;
   default:
    break;
   }
  }
 } while (*++cp);
 return (1);

bad: fmprintf(
             stderr
                   , "%s: invalid user name\n", cp0);
 return (0);
}

BUF *
allocbuf(BUF *bp, int fd, int blksize)
{
 size_t size;

 struct stat stb;

 if (fstat(fd, &stb) == -1) {
  run_err("fstat: %s", strerror(
                               (*__errno_location ())
                                    ));
  return (0);
 }
 size = ((((stb.st_blksize)+((blksize)-1))/(blksize))*(blksize));
 if (size == 0)
  size = blksize;



 if (bp->cnt >= size)
  return (bp);
 bp->buf = xrecallocarray(bp->buf, bp->cnt, size, 1);
 bp->cnt = size;
 return (bp);
}

void
lostconn(int signo)
{
 if (!iamremote)
  (void)write(
             2
                          , "lost connection\n", 16);
 if (signo)
  _exit(1);
 else
  exit(1);
}

void
cleanup_exit(int i)
{
 if (remin > 0)
  close(remin);
 if (remout > 0)
  close(remout);
 if (remin2 > 0)
  close(remin2);
 if (remout2 > 0)
  close(remout2);
 if (do_cmd_pid > 0)
  waitpid(do_cmd_pid, 
                     ((void *)0)
                         , 0);
 if (do_cmd_pid2 > 0)
  waitpid(do_cmd_pid2, 
                      ((void *)0)
                          , 0);
 exit(i);
}
