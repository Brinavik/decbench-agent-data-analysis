











































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

 SYSLOG_FACILITY_AUTHPRIV,

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

static LogLevel log_level = SYSLOG_LEVEL_INFO;
static int log_on_stderr = 1;
static int log_stderr_fd = 
                          2
                                       ;
static int log_facility = 
                         (4<<3)
                                 ;
static const char *argv0;
static log_handler_fn *log_handler;
static void *log_handler_ctx;
static char **log_verbose;
static size_t nlog_verbose;

extern char *__progname;






static struct {
 const char *name;
 SyslogFacility val;
} log_facilities[] = {
 { "DAEMON", SYSLOG_FACILITY_DAEMON },
 { "USER", SYSLOG_FACILITY_USER },
 { "AUTH", SYSLOG_FACILITY_AUTH },

 { "AUTHPRIV", SYSLOG_FACILITY_AUTHPRIV },

 { "LOCAL0", SYSLOG_FACILITY_LOCAL0 },
 { "LOCAL1", SYSLOG_FACILITY_LOCAL1 },
 { "LOCAL2", SYSLOG_FACILITY_LOCAL2 },
 { "LOCAL3", SYSLOG_FACILITY_LOCAL3 },
 { "LOCAL4", SYSLOG_FACILITY_LOCAL4 },
 { "LOCAL5", SYSLOG_FACILITY_LOCAL5 },
 { "LOCAL6", SYSLOG_FACILITY_LOCAL6 },
 { "LOCAL7", SYSLOG_FACILITY_LOCAL7 },
 { 
  ((void *)0)
      , SYSLOG_FACILITY_NOT_SET }
};

static struct {
 const char *name;
 LogLevel val;
} log_levels[] =
{
 { "QUIET", SYSLOG_LEVEL_QUIET },
 { "FATAL", SYSLOG_LEVEL_FATAL },
 { "ERROR", SYSLOG_LEVEL_ERROR },
 { "INFO", SYSLOG_LEVEL_INFO },
 { "VERBOSE", SYSLOG_LEVEL_VERBOSE },
 { "DEBUG", SYSLOG_LEVEL_DEBUG1 },
 { "DEBUG1", SYSLOG_LEVEL_DEBUG1 },
 { "DEBUG2", SYSLOG_LEVEL_DEBUG2 },
 { "DEBUG3", SYSLOG_LEVEL_DEBUG3 },
 { 
  ((void *)0)
      , SYSLOG_LEVEL_NOT_SET }
};

LogLevel
log_level_get(void)
{
 return log_level;
}

SyslogFacility
log_facility_number(char *name)
{
 int i;

 if (name != 
            ((void *)0)
                )
  for (i = 0; log_facilities[i].name; i++)
   if (strcasecmp(log_facilities[i].name, name) == 0)
    return log_facilities[i].val;
 return SYSLOG_FACILITY_NOT_SET;
}

const char *
log_facility_name(SyslogFacility facility)
{
 u_int i;

 for (i = 0; log_facilities[i].name; i++)
  if (log_facilities[i].val == facility)
   return log_facilities[i].name;
 return 
       ((void *)0)
           ;
}

LogLevel
log_level_number(char *name)
{
 int i;

 if (name != 
            ((void *)0)
                )
  for (i = 0; log_levels[i].name; i++)
   if (strcasecmp(log_levels[i].name, name) == 0)
    return log_levels[i].val;
 return SYSLOG_LEVEL_NOT_SET;
}

const char *
log_level_name(LogLevel level)
{
 u_int i;

 for (i = 0; log_levels[i].name != 
                                  ((void *)0)
                                      ; i++)
  if (log_levels[i].val == level)
   return log_levels[i].name;
 return 
       ((void *)0)
           ;
}

void
log_verbose_add(const char *s)
{
 char **tmp;


 if ((tmp = recallocarray(log_verbose, nlog_verbose, nlog_verbose + 1,
     sizeof(*log_verbose))) != 
                              ((void *)0)
                                  ) {
  log_verbose = tmp;
  if ((log_verbose[nlog_verbose] = strdup(s)) != 
                                                ((void *)0)
                                                    )
   nlog_verbose++;
 }
}

void
log_verbose_reset(void)
{
 size_t i;

 for (i = 0; i < nlog_verbose; i++)
  free(log_verbose[i]);
 free(log_verbose);
 log_verbose = 
              ((void *)0)
                  ;
 nlog_verbose = 0;
}





void
log_init(const char *av0, LogLevel level, SyslogFacility facility,
    int on_stderr)
{




 argv0 = av0;

 if (log_change_level(level) != 0) {
  fprintf(
         stderr
               , "Unrecognized internal syslog level code %d\n",
      (int) level);
  exit(1);
 }

 log_handler = 
              ((void *)0)
                  ;
 log_handler_ctx = 
                  ((void *)0)
                      ;

 log_on_stderr = on_stderr;
 if (on_stderr)
  return;

 switch (facility) {
 case SYSLOG_FACILITY_DAEMON:
  log_facility = 
                (3<<3)
                          ;
  break;
 case SYSLOG_FACILITY_USER:
  log_facility = 
                (1<<3)
                        ;
  break;
 case SYSLOG_FACILITY_AUTH:
  log_facility = 
                (4<<3)
                        ;
  break;

 case SYSLOG_FACILITY_AUTHPRIV:
  log_facility = 
                (10<<3)
                            ;
  break;

 case SYSLOG_FACILITY_LOCAL0:
  log_facility = 
                (16<<3)
                          ;
  break;
 case SYSLOG_FACILITY_LOCAL1:
  log_facility = 
                (17<<3)
                          ;
  break;
 case SYSLOG_FACILITY_LOCAL2:
  log_facility = 
                (18<<3)
                          ;
  break;
 case SYSLOG_FACILITY_LOCAL3:
  log_facility = 
                (19<<3)
                          ;
  break;
 case SYSLOG_FACILITY_LOCAL4:
  log_facility = 
                (20<<3)
                          ;
  break;
 case SYSLOG_FACILITY_LOCAL5:
  log_facility = 
                (21<<3)
                          ;
  break;
 case SYSLOG_FACILITY_LOCAL6:
  log_facility = 
                (22<<3)
                          ;
  break;
 case SYSLOG_FACILITY_LOCAL7:
  log_facility = 
                (23<<3)
                          ;
  break;
 default:
  fprintf(
         stderr
               ,
      "Unrecognized internal syslog facility code %d\n",
      (int) facility);
  exit(1);
 }
 openlog(argv0 ? argv0 : __progname, 
                                    0x01
                                           , log_facility);
 closelog();

}

int
log_change_level(LogLevel new_log_level)
{

 if (argv0 == 
             ((void *)0)
                 )
  return 0;

 switch (new_log_level) {
 case SYSLOG_LEVEL_QUIET:
 case SYSLOG_LEVEL_FATAL:
 case SYSLOG_LEVEL_ERROR:
 case SYSLOG_LEVEL_INFO:
 case SYSLOG_LEVEL_VERBOSE:
 case SYSLOG_LEVEL_DEBUG1:
 case SYSLOG_LEVEL_DEBUG2:
 case SYSLOG_LEVEL_DEBUG3:
  log_level = new_log_level;
  return 0;
 default:
  return -1;
 }
}

int
log_is_on_stderr(void)
{
 return log_on_stderr && log_stderr_fd == 
                                         2
                                                      ;
}


void
log_redirect_stderr_to(const char *logfile)
{
 int fd;

 if (logfile == 
               ((void *)0)
                   ) {
  if (log_stderr_fd != 
                      2
                                   ) {
   close(log_stderr_fd);
   log_stderr_fd = 
                  2
                               ;
  }
  return;
 }

 if ((fd = open(logfile, 
                        01
                                |
                                 0100
                                        |
                                         02000
                                                 , 0600)) == -1) {
  fprintf(
         stderr
               , "Couldn't open logfile %s: %s\n", logfile,
      strerror(
              (*__errno_location ())
                   ));
  exit(1);
 }
 log_stderr_fd = fd;
}



void
set_log_handler(log_handler_fn *handler, void *ctx)
{
 log_handler = handler;
 log_handler_ctx = ctx;
}

static void
do_log(LogLevel level, int force, const char *suffix, const char *fmt,
    va_list args)
{



 char msgbuf[1024];
 char fmtbuf[1024];
 char *txt = 
            ((void *)0)
                ;
 int pri = 
          6
                  ;
 int saved_errno = 
                  (*__errno_location ())
                       ;
 log_handler_fn *tmp_handler;
 const char *progname = argv0 != 
                                ((void *)0) 
                                     ? argv0 : __progname;

 if (!force && level > log_level)
  return;

 switch (level) {
 case SYSLOG_LEVEL_FATAL:
  if (!log_on_stderr)
   txt = "fatal";
  pri = 
       2
               ;
  break;
 case SYSLOG_LEVEL_ERROR:
  if (!log_on_stderr)
   txt = "error";
  pri = 
       3
              ;
  break;
 case SYSLOG_LEVEL_INFO:
  pri = 
       6
               ;
  break;
 case SYSLOG_LEVEL_VERBOSE:
  pri = 
       6
               ;
  break;
 case SYSLOG_LEVEL_DEBUG1:
  txt = "debug1";
  pri = 
       7
                ;
  break;
 case SYSLOG_LEVEL_DEBUG2:
  txt = "debug2";
  pri = 
       7
                ;
  break;
 case SYSLOG_LEVEL_DEBUG3:
  txt = "debug3";
  pri = 
       7
                ;
  break;
 default:
  txt = "internal error";
  pri = 
       3
              ;
  break;
 }
 if (txt != 
           ((void *)0) 
                && log_handler == 
                                  ((void *)0)
                                      ) {
  snprintf(fmtbuf, sizeof(fmtbuf), "%s: %s", txt, fmt);
  vsnprintf(msgbuf, sizeof(msgbuf), fmtbuf, args);
 } else {
  vsnprintf(msgbuf, sizeof(msgbuf), fmt, args);
 }
 if (suffix != 
              ((void *)0)
                  ) {
  snprintf(fmtbuf, sizeof(fmtbuf), "%s: %s", msgbuf, suffix);
  strlcpy(msgbuf, fmtbuf, sizeof(msgbuf));
 }
 strnvis(fmtbuf, msgbuf, sizeof(fmtbuf),
     log_on_stderr ? (0x20|0x01) : (0x02|0x10|0x08|0x01));
 if (log_handler != 
                   ((void *)0)
                       ) {

  tmp_handler = log_handler;
  log_handler = 
               ((void *)0)
                   ;
  tmp_handler(level, force, fmtbuf, log_handler_ctx);
  log_handler = tmp_handler;
 } else if (log_on_stderr) {
  snprintf(msgbuf, sizeof msgbuf, "%s%s%.*s\r\n",
      (log_on_stderr > 1) ? progname : "",
      (log_on_stderr > 1) ? ": " : "",
      (int)sizeof msgbuf - 3, fmtbuf);
  (void)write(log_stderr_fd, msgbuf, strlen(msgbuf));
 } else {





  openlog(progname, 
                   0x01
                          , log_facility);
  syslog(pri, "%.500s", fmtbuf);
  closelog();

 }
 
(*__errno_location ()) 
      = saved_errno;
}

void
sshlog(const char *file, const char *func, int line, int showfunc,
    LogLevel level, const char *suffix, const char *fmt, ...)
{
 va_list args;

 
__builtin_va_start(
args
,
fmt
)
                   ;
 sshlogv(file, func, line, showfunc, level, suffix, fmt, args);
 
__builtin_va_end(
args
)
            ;
}

void
sshlogdie(const char *file, const char *func, int line, int showfunc,
    LogLevel level, const char *suffix, const char *fmt, ...)
{
 va_list args;

 
__builtin_va_start(
args
,
fmt
)
                   ;
 sshlogv(file, func, line, showfunc, SYSLOG_LEVEL_INFO,
     suffix, fmt, args);
 
__builtin_va_end(
args
)
            ;
 cleanup_exit(255);
}

void
sshsigdie(const char *file, const char *func, int line, int showfunc,
    LogLevel level, const char *suffix, const char *fmt, ...)
{
 va_list args;

 
__builtin_va_start(
args
,
fmt
)
                   ;
 sshlogv(file, func, line, showfunc, SYSLOG_LEVEL_FATAL,
     suffix, fmt, args);
 
__builtin_va_end(
args
)
            ;
 _exit(1);
}

void
sshlogv(const char *file, const char *func, int line, int showfunc,
    LogLevel level, const char *suffix, const char *fmt, va_list args)
{
 char tag[128], fmt2[1024 + 128];
 int forced = 0;
 const char *cp;
 size_t i;

 snprintf(tag, sizeof(tag), "%.48s:%.48s():%d (pid=%ld)",
     (cp = strrchr(file, '/')) == 
                                 ((void *)0) 
                                      ? file : cp + 1, func, line,
     (long)getpid());
 for (i = 0; i < nlog_verbose; i++) {
  if (match_pattern_list(tag, log_verbose[i], 0) == 1) {
   forced = 1;
   break;
  }
 }

 if (forced)
  snprintf(fmt2, sizeof(fmt2), "%s: %s", tag, fmt);
 else if (showfunc)
  snprintf(fmt2, sizeof(fmt2), "%s: %s", func, fmt);
 else
  strlcpy(fmt2, fmt, sizeof(fmt2));

 do_log(level, forced, suffix, fmt2, args);
}

void
sshlogdirect(LogLevel level, int forced, const char *fmt, ...)
{
 va_list args;

 
__builtin_va_start(
args
,
fmt
)
                   ;
 do_log(level, forced, 
                      ((void *)0)
                          , fmt, args);
 
__builtin_va_end(
args
)
            ;
}
