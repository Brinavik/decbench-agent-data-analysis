











































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
void temporarily_use_uid(struct passwd *);
void restore_uid(void);
void permanently_set_uid(struct passwd *);

static char *
ssh_askpass(char *askpass, const char *msg, const char *env_hint)
{
 pid_t pid, ret;
 size_t len;
 char *pass;
 int p[2], status;
 char buf[1024];
 void (*osigchld)(int);

 if (fflush(
           stdout
                 ) != 0)
  sshlog("readpass.c", __func__, 61, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "fflush: %s", strerror(
 (*__errno_location ())
 ));
 if (askpass == 
               ((void *)0)
                   )
  sshfatal("readpass.c", __func__, 63, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "internal error: askpass undefined");
 if (pipe(p) == -1) {
  sshlog("readpass.c", __func__, 65, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "pipe: %s", strerror(
 (*__errno_location ())
 ));
  return 
        ((void *)0)
            ;
 }
 osigchld = ssh_signal(
                      17
                             , 
                               ((__sighandler_t) 0)
                                      );
 if ((pid = fork()) == -1) {
  sshlog("readpass.c", __func__, 70, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "fork: %s", strerror(
 (*__errno_location ())
 ));
  ssh_signal(
            17
                   , osigchld);
  return 
        ((void *)0)
            ;
 }
 if (pid == 0) {
  close(p[0]);
  if (dup2(p[1], 
                1
                             ) == -1)
   sshfatal("readpass.c", __func__, 77, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "dup2: %s", strerror(
  (*__errno_location ())
  ));
  if (env_hint != 
                 ((void *)0)
                     )
   setenv("SSH_ASKPASS_PROMPT", env_hint, 1);
  execlp(askpass, askpass, msg, (char *)
                                       ((void *)0)
                                           );
  sshfatal("readpass.c", __func__, 81, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "exec(%s): %s", askpass, strerror(
 (*__errno_location ())
 ));
 }
 close(p[1]);

 len = 0;
 do {
  ssize_t r = read(p[0], buf + len, sizeof(buf) - 1 - len);

  if (r == -1 && 
                (*__errno_location ()) 
                      == 
                         4
                              )
   continue;
  if (r <= 0)
   break;
  len += r;
 } while (sizeof(buf) - 1 - len > 0);
 buf[len] = '\0';

 close(p[0]);
 while ((ret = waitpid(pid, &status, 0)) == -1)
  if (
     (*__errno_location ()) 
           != 
              4
                   )
   break;
 ssh_signal(
           17
                  , osigchld);
 if (ret == -1 || !
                  (((
                  status
                  ) & 0x7f) == 0) 
                                    || 
                                       (((
                                       status
                                       ) & 0xff00) >> 8) 
                                                           != 0) {
  explicit_bzero(buf, sizeof(buf));
  return 
        ((void *)0)
            ;
 }

 buf[strcspn(buf, "\r\n")] = '\0';
 pass = xstrdup(buf);
 explicit_bzero(buf, sizeof(buf));
 return pass;
}
char *
read_passphrase(const char *prompt, int flags)
{
 char cr = '\r', *askpass = 
                           ((void *)0)
                               , *ret, buf[1024];
 int rppflags, ttyfd, use_askpass = 0, allow_askpass = 0;
 const char *askpass_hint = 
                           ((void *)0)
                               ;
 const char *s;

 if ((s = getenv("DISPLAY")) != 
                               ((void *)0)
                                   )
  allow_askpass = *s != '\0';
 if ((s = getenv("SSH_ASKPASS_REQUIRE")) != 
                                             ((void *)0)
                                                 ) {
  if (strcasecmp(s, "force") == 0) {
   use_askpass = 1;
   allow_askpass = 1;
  } else if (strcasecmp(s, "prefer") == 0)
   use_askpass = allow_askpass;
  else if (strcasecmp(s, "never") == 0)
   allow_askpass = 0;
 }

 rppflags = (flags & 0x0001) ? 0x01 : 0x00;
 if (use_askpass)
  sshlog("readpass.c", __func__, 144, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "requested to askpass");
 else if (flags & 0x0008)
  use_askpass = 1;
 else if (flags & 0x0002) {
  if (!isatty(
             0
                         )) {
   sshlog("readpass.c", __func__, 149, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "stdin is not a tty");
   use_askpass = 1;
  }
 } else {
  rppflags |= 0x02;
  ttyfd = open(
              "/dev/tty"
                       , 
                         02
                               );
  if (ttyfd >= 0) {






   (void)write(ttyfd, &cr, 1);
   close(ttyfd);
  } else {
   sshlog("readpass.c", __func__, 165, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "can't open %s: %s", 
  "/dev/tty"
  , strerror(
  (*__errno_location ())
  ))
                       ;
   use_askpass = 1;
  }
 }

 if ((flags & 0x0008) && !allow_askpass)
  return (flags & 0x0004) ? 
                                 ((void *)0) 
                                      : xstrdup("");

 if (use_askpass && allow_askpass) {
  if (getenv("SSH_ASKPASS"))
   askpass = getenv("SSH_ASKPASS");
  else
   askpass = "/usr/local/libexec/ssh-askpass";
  if ((flags & 0x8000) != 0)
   askpass_hint = "confirm";
  if ((ret = ssh_askpass(askpass, prompt, askpass_hint)) == 
                                                           ((void *)0)
                                                               )
   if (!(flags & 0x0004))
    return xstrdup("");
  return ret;
 }

 if (readpassphrase(prompt, buf, sizeof buf, rppflags) == 
                                                         ((void *)0)
                                                             ) {
  if (flags & 0x0004)
   return 
         ((void *)0)
             ;
  return xstrdup("");
 }

 ret = xstrdup(buf);
 explicit_bzero(buf, sizeof(buf));
 return ret;
}

int
ask_permission(const char *fmt, ...)
{
 va_list args;
 char *p, prompt[1024];
 int allowed = 0;

 
__builtin_va_start(
args
,
fmt
)
                   ;
 vsnprintf(prompt, sizeof(prompt), fmt, args);
 
__builtin_va_end(
args
)
            ;

 p = read_passphrase(prompt,
     0x0008|0x0004|0x8000);
 if (p != 
         ((void *)0)
             ) {




  if (*p == '\0' || *p == '\n' ||
      strcasecmp(p, "yes") == 0)
   allowed = 1;
  free(p);
 }

 return (allowed);
}

static void
writemsg(const char *msg)
{
 (void)write(
            2
                         , "\r", 1);
 (void)write(
            2
                         , msg, strlen(msg));
 (void)write(
            2
                         , "\r\n", 2);
}

struct notifier_ctx {
 pid_t pid;
 void (*osigchld)(int);
};

struct notifier_ctx *
notify_start(int force_askpass, const char *fmt, ...)
{
 va_list args;
 char *prompt = 
               ((void *)0)
                   ;
 pid_t pid = -1;
 void (*osigchld)(int) = 
                        ((void *)0)
                            ;
 const char *askpass, *s;
 struct notifier_ctx *ret = 
                           ((void *)0)
                               ;

 
__builtin_va_start(
args
,
fmt
)
                   ;
 xvasprintf(&prompt, fmt, args);
 
__builtin_va_end(
args
)
            ;

 if (fflush(
           ((void *)0)
               ) != 0)
  sshlog("readpass.c", __func__, 253, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "fflush: %s", strerror(
 (*__errno_location ())
 ));
 if (!force_askpass && isatty(
                             2
                                          )) {
  writemsg(prompt);
  goto out_ctx;
 }
 if ((askpass = getenv("SSH_ASKPASS")) == 
                                         ((void *)0)
                                             )
  askpass = "/usr/local/libexec/ssh-askpass";
 if (*askpass == '\0') {
  sshlog("readpass.c", __func__, 261, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "cannot notify: no askpass");
  goto out;
 }
 if (getenv("DISPLAY") == 
                         ((void *)0) 
                              &&
     ((s = getenv("SSH_ASKPASS_REQUIRE")) == 
                                              ((void *)0) 
                                                   ||
     strcmp(s, "force") != 0)) {
  sshlog("readpass.c", __func__, 267, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "cannot notify: no display");
  goto out;
 }
 osigchld = ssh_signal(
                      17
                             , 
                               ((__sighandler_t) 0)
                                      );
 if ((pid = fork()) == -1) {
  sshlog("readpass.c", __func__, 272, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "fork: %s", strerror(
 (*__errno_location ())
 ));
  ssh_signal(
            17
                   , osigchld);
  free(prompt);
  return 
        ((void *)0)
            ;
 }
 if (pid == 0) {
  if (stdfd_devnull(1, 1, 0) == -1)
   sshfatal("readpass.c", __func__, 279, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "stdfd_devnull failed");
  closefrom(
           2 
                         + 1);
  setenv("SSH_ASKPASS_PROMPT", "none", 1);
  execlp(askpass, askpass, prompt, (char *)
                                          ((void *)0)
                                              );
  sshlog("readpass.c", __func__, 283, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "exec(%s): %s", askpass, strerror(
 (*__errno_location ())
 ));
  _exit(1);

 }
 out_ctx:
 if ((ret = calloc(1, sizeof(*ret))) == 
                                       ((void *)0)
                                           ) {
  if (pid != -1)
   kill(pid, 
            15
                   );
  sshfatal("readpass.c", __func__, 291, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "calloc failed");
 }
 ret->pid = pid;
 ret->osigchld = osigchld;
 out:
 free(prompt);
 return ret;
}

void
notify_complete(struct notifier_ctx *ctx, const char *fmt, ...)
{
 int ret;
 char *msg = 
            ((void *)0)
                ;
 va_list args;

 if (ctx != 
           ((void *)0) 
                && fmt != 
                          ((void *)0) 
                               && ctx->pid == -1) {




  
 __builtin_va_start(
 args
 ,
 fmt
 )
                    ;
  xvasprintf(&msg, fmt, args);
  
 __builtin_va_end(
 args
 )
             ;
  writemsg(msg);
  free(msg);
 }

 if (ctx == 
           ((void *)0) 
                || ctx->pid <= 0) {
  free(ctx);
  return;
 }
 kill(ctx->pid, 
               15
                      );
 while ((ret = waitpid(ctx->pid, 
                                ((void *)0)
                                    , 0)) == -1) {
  if (
     (*__errno_location ()) 
           != 
              4
                   )
   break;
 }
 if (ret == -1)
  sshfatal("readpass.c", __func__, 329, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "waitpid: %s", strerror(
 (*__errno_location ())
 ));
 ssh_signal(
           17
                  , ctx->osigchld);
 free(ctx);
}
