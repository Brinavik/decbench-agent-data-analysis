











































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
struct monitor;
struct ssh_sandbox;

struct ssh_sandbox *ssh_sandbox_init(struct monitor *);
void ssh_sandbox_child(struct ssh_sandbox *);
void ssh_sandbox_parent_finish(struct ssh_sandbox *);
void ssh_sandbox_parent_preauth(struct ssh_sandbox *, pid_t);
void *xmalloc(size_t);
void *xcalloc(size_t, size_t);
void *xreallocarray(void *, size_t, size_t);
void *xrecallocarray(void *, size_t, size_t, size_t);
char *xstrdup(const char *);
int xasprintf(char **, const char *, ...)
    __attribute__((__format__ (printf, 2, 3))) __attribute__((__nonnull__ (2)));
int xvasprintf(char **, const char *, va_list)
    __attribute__((__nonnull__ (2)));
static const struct sock_filter preauth_insns[] = {

 
{ (unsigned short)(0x00 
+
0x00
+
0x20), 0, 0, __builtin_offsetof (
struct seccomp_data
, 
arch
) }
                                      
                                     ,
 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
1
, 
0
, (62|0x80000000|0x40000000) }
                                                         ,
 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x00030000U }
                                            ,

 
{ (unsigned short)(0x00 
+
0x00
+
0x20), 0, 0, __builtin_offsetof (
struct seccomp_data
, 
nr
) }
                                    
                                   ,



 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
6
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x00050000U
|(
13
) 
}
                           ,





 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
5
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x00050000U
|(
13
) 
}
                           ,
 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
2
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x00050000U
|(
13
) 
}
                          ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
257
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x00050000U
|(
13
) 
}
                            ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
262
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x00050000U
|(
13
) 
}
                                ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
4
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x00050000U
|(
13
) 
}
                          ,





 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
29
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x00050000U
|(
13
) 
}
                            ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
30
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x00050000U
|(
13
) 
}
                           ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
67
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x00050000U
|(
13
) 
}
                           ,





 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
332
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x00050000U
|(
13
) 
}
                           ,




 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
12
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                  ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
228
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                            ,





 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
3
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                    ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
60
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                   ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
231
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                         ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
202
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                    ,





 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
107
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                      ,





 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
121
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                      ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
39
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                     ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
318
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                        ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
186
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                     ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
96
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                           ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
102
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                     ,





 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
28
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                      ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
8
, 
(
9
) 
}
, 
{ (unsigned short)(0x00 
+
0x00
+
0x20), 0, 0, __builtin_offsetof (
struct seccomp_data
, 
args[(2)]
) 
+ 0 
}
, 
{ (unsigned short)(0x04 
+
0x50
+
0x00), 0, 0, 
~((
0x1
|
0x2
|
0x0
) & 0xFFFFFFFF) 
}
, 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
4
, 
0 
}
, 
{ (unsigned short)(0x00 
+
0x00
+
0x20), 0, 0, __builtin_offsetof (
struct seccomp_data
, 
args[(2)]
) 
+ sizeof(uint32_t) 
}
, 
{ (unsigned short)(0x04 
+
0x50
+
0x00), 0, 0, 
~(((uint32_t)((uint64_t)(
0x1
|
0x2
|
0x0
) >> 32)) & 0xFFFFFFFF) 
}
, 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
0 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
, 
{ (unsigned short)(0x00 
+
0x00
+
0x20), 0, 0, __builtin_offsetof (
struct seccomp_data
, 
nr
) }
                                                               ,





 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
8
, 
(
10
) 
}
, 
{ (unsigned short)(0x00 
+
0x00
+
0x20), 0, 0, __builtin_offsetof (
struct seccomp_data
, 
args[(2)]
) 
+ 0 
}
, 
{ (unsigned short)(0x04 
+
0x50
+
0x00), 0, 0, 
~((
0x1
|
0x2
|
0x0
) & 0xFFFFFFFF) 
}
, 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
4
, 
0 
}
, 
{ (unsigned short)(0x00 
+
0x00
+
0x20), 0, 0, __builtin_offsetof (
struct seccomp_data
, 
args[(2)]
) 
+ sizeof(uint32_t) 
}
, 
{ (unsigned short)(0x04 
+
0x50
+
0x00), 0, 0, 
~(((uint32_t)((uint64_t)(
0x1
|
0x2
|
0x0
) >> 32)) & 0xFFFFFFFF) 
}
, 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
0 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
, 
{ (unsigned short)(0x00 
+
0x00
+
0x20), 0, 0, __builtin_offsetof (
struct seccomp_data
, 
nr
) }
                                                                   ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
25
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                     ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
11
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                     ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
35
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                        ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
230
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                              ,
 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
271
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                    ,





 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
7
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                   ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
270
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                       ,





 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
0
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                   ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
14
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                             ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
23
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                     ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
48
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                       ,





 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
201
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                   ,


 
{ (unsigned short)(0x05 
+
0x10
+
0x00), 
0
, 
1
, 
(
1
) 
}
, 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x7fff0000U }
                    ,
 
{ (unsigned short)(0x06 
+
0x00), 0, 0, 0x00030000U }
                                            ,
};

static const struct sock_fprog preauth_program = {
 .len = (unsigned short)(sizeof(preauth_insns)/sizeof(preauth_insns[0])),
 .filter = (struct sock_filter *)preauth_insns,
};

struct ssh_sandbox {
 pid_t child_pid;
};

struct ssh_sandbox *
ssh_sandbox_init(struct monitor *monitor)
{
 struct ssh_sandbox *box;





 sshlog("sandbox-seccomp-filter.c", __func__, 359, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s: preparing seccomp filter sandbox", __func__);
 box = xcalloc(1, sizeof(*box));
 box->child_pid = 0;

 return box;
}


extern struct monitor *pmonitor;
void mm_log_handler(LogLevel level, int forced, const char *msg, void *ctx);

static void
ssh_sandbox_violation(int signum, siginfo_t *info, void *void_context)
{
 char msg[256];

 snprintf(msg, sizeof(msg),
     "%s: unexpected system call (arch:0x%x,syscall:%d @ %p)",
     __func__, info->
                    _sifields._sigsys._arch
                           , info->
                                   _sifields._sigsys._syscall
                                             , info->
                                                     _sifields._sigsys._call_addr
                                                                 );
 mm_log_handler(SYSLOG_LEVEL_FATAL, 0, msg, pmonitor);
 _exit(1);
}

static void
ssh_sandbox_child_debugging(void)
{
 struct sigaction act;
 sigset_t mask;

 sshlog("sandbox-seccomp-filter.c", __func__, 388, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s: installing SIGSYS handler", __func__);
 memset(&act, 0, sizeof(act));
 sigemptyset(&mask);
 sigaddset(&mask, 
                 31
                       );

 act.
    __sigaction_handler.sa_sigaction 
                 = &ssh_sandbox_violation;
 act.sa_flags = 
               4
                         ;
 if (sigaction(
              31
                    , &act, 
                            ((void *)0)
                                ) == -1)
  sshfatal("sandbox-seccomp-filter.c", __func__, 396, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: sigaction(SIGSYS): %s", __func__, strerror(
 (*__errno_location ())
 ));
 if (sigprocmask(
                1
                           , &mask, 
                                    ((void *)0)
                                        ) == -1)
  sshfatal("sandbox-seccomp-filter.c", __func__, 398, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: sigprocmask(SIGSYS): %s", __func__, strerror(
 (*__errno_location ())
 ))
                                ;
}


void
ssh_sandbox_child(struct ssh_sandbox *box)
{
 struct rlimit rl_zero, rl_one = {.rlim_cur = 1, .rlim_max = 1};
 int nnp_failed = 0;


 rl_zero.rlim_cur = rl_zero.rlim_max = 0;
 if (setrlimit(
              RLIMIT_FSIZE
                          , &rl_zero) == -1)
  sshfatal("sandbox-seccomp-filter.c", __func__, 412, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: setrlimit(RLIMIT_FSIZE, { 0, 0 }): %s", __func__, strerror(
 (*__errno_location ())
 ))
                             ;




 if (setrlimit(
              RLIMIT_NOFILE
                           , &rl_one) == -1)
  sshfatal("sandbox-seccomp-filter.c", __func__, 419, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: setrlimit(RLIMIT_NOFILE, { 0, 0 }): %s", __func__, strerror(
 (*__errno_location ())
 ))
                             ;
 if (setrlimit(
              __RLIMIT_NPROC
                          , &rl_zero) == -1)
  sshfatal("sandbox-seccomp-filter.c", __func__, 422, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: setrlimit(RLIMIT_NPROC, { 0, 0 }): %s", __func__, strerror(
 (*__errno_location ())
 ))
                             ;


 ssh_sandbox_child_debugging();


 sshlog("sandbox-seccomp-filter.c", __func__, 429, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s: setting PR_SET_NO_NEW_PRIVS", __func__);
 if (prctl(
          38
                             , 1, 0, 0, 0) == -1) {
  sshlog("sandbox-seccomp-filter.c", __func__, 431, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%s: prctl(PR_SET_NO_NEW_PRIVS): %s", __func__, strerror(
 (*__errno_location ())
 ))
                                ;
  nnp_failed = 1;
 }
 sshlog("sandbox-seccomp-filter.c", __func__, 435, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s: attaching seccomp filter program", __func__);
 if (prctl(
          22
                        , 
                          2
                                             , &preauth_program) == -1)
  sshlog("sandbox-seccomp-filter.c", __func__, 437, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%s: prctl(PR_SET_SECCOMP): %s", __func__, strerror(
 (*__errno_location ())
 ))
                                ;
 else if (nnp_failed)
  sshfatal("sandbox-seccomp-filter.c", __func__, 440, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: SECCOMP_MODE_FILTER activated but " "PR_SET_NO_NEW_PRIVS failed", __func__)
                                             ;
}

void
ssh_sandbox_parent_finish(struct ssh_sandbox *box)
{
 free(box);
 sshlog("sandbox-seccomp-filter.c", __func__, 448, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s: finished", __func__);
}

void
ssh_sandbox_parent_preauth(struct ssh_sandbox *box, pid_t child_pid)
{
 box->child_pid = child_pid;
}
