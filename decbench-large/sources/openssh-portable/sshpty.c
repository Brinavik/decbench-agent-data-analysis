











































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


















struct termios *get_saved_tio(void);
void leave_raw_mode(int);
void enter_raw_mode(int);

int pty_allocate(int *, int *, char *, size_t);
void pty_release(const char *);
void pty_make_controlling_tty(int *, const char *);
void pty_change_window_size(int, u_int, u_int, u_int, u_int);
void pty_setowner(struct passwd *, const char *);
void disconnect_controlling_tty(void);
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



int
pty_allocate(int *ptyfd, int *ttyfd, char *namebuf, size_t namebuflen)
{

 char *name;
 int i;

 i = openpty(ptyfd, ttyfd, 
                          ((void *)0)
                              , 
                                ((void *)0)
                                    , 
                                      ((void *)0)
                                          );
 if (i == -1) {
  sshlog("sshpty.c", __func__, 73, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "openpty: %.100s", strerror(
 (*__errno_location ())
 ));
  return 0;
 }
 name = ttyname(*ttyfd);
 if (!name)
  sshfatal("sshpty.c", __func__, 78, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "openpty returns device for which ttyname fails.");

 strlcpy(namebuf, name, namebuflen);
 return 1;
}



void
pty_release(const char *tty)
{






}



void
pty_make_controlling_tty(int *ttyfd, const char *tty)
{
 int fd;



 fd = open(
          "/dev/tty"
                   , 
                     02 
                            | 
                              0400
                                      );
 if (fd >= 0) {
  (void) ioctl(fd, 
                  0x5422
                           , 
                             ((void *)0)
                                 );
  close(fd);
 }

 if (setsid() == -1)
  sshlog("sshpty.c", __func__, 113, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "setsid: %.100s", strerror(
 (*__errno_location ())
 ));





 fd = open(
          "/dev/tty"
                   , 
                     02 
                            | 
                              0400
                                      );
 if (fd >= 0) {
  sshlog("sshpty.c", __func__, 121, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Failed to disconnect from controlling tty.");
  close(fd);
 }


 sshlog("sshpty.c", __func__, 126, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Setting controlling tty using TIOCSCTTY.");
 if (ioctl(*ttyfd, 
                  0x540E
                           , 
                             ((void *)0)
                                 ) < 0)
  sshlog("sshpty.c", __func__, 128, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "ioctl(TIOCSCTTY): %.100s", strerror(
 (*__errno_location ())
 ));





 fd = open(tty, 
               02
                     );
 if (fd == -1)
  sshlog("sshpty.c", __func__, 136, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%.100s: %.100s", tty, strerror(
 (*__errno_location ())
 ));
 else
  close(fd);


 fd = open(
          "/dev/tty"
                   , 
                     01
                             );
 if (fd == -1)
  sshlog("sshpty.c", __func__, 143, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "open /dev/tty failed - could not set controlling tty: %.100s", strerror(
 (*__errno_location ())
 ))
                      ;
 else
  close(fd);
}



void
pty_change_window_size(int ptyfd, u_int row, u_int col,
 u_int xpixel, u_int ypixel)
{
 struct winsize w;


 w.ws_row = row;
 w.ws_col = col;
 w.ws_xpixel = xpixel;
 w.ws_ypixel = ypixel;
 (void) ioctl(ptyfd, 
                    0x5414
                              , &w);
}

void
pty_setowner(struct passwd *pw, const char *tty)
{
 struct group *grp;
 gid_t gid;
 mode_t mode;
 struct stat st;


 grp = getgrnam("tty");
 if (grp == 
           ((void *)0)
               )
  sshlog("sshpty.c", __func__, 176, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%s: no tty group", __func__);
 gid = (grp != 
              ((void *)0)
                  ) ? grp->gr_gid : pw->pw_gid;
 mode = (grp != 
               ((void *)0)
                   ) ? 0620 : 0600;






 if (stat(tty, &st) == -1)
  sshfatal("sshpty.c", __func__, 186, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "stat(%.100s) failed: %.100s", tty, strerror(
 (*__errno_location ())
 ))
                      ;





 if (st.st_uid != pw->pw_uid || st.st_gid != gid) {
  if (chown(tty, pw->pw_uid, gid) == -1) {
   if (
      (*__errno_location ()) 
            == 
               30 
                     &&
       (st.st_uid == pw->pw_uid || st.st_uid == 0))
    sshlog("sshpty.c", __func__, 197, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "chown(%.100s, %u, %u) failed: %.100s", tty, (u_int)pw->pw_uid, (u_int)gid, strerror(
   (*__errno_location ())
   ))

                        ;
   else
    sshfatal("sshpty.c", __func__, 201, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "chown(%.100s, %u, %u) failed: %.100s", tty, (u_int)pw->pw_uid, (u_int)gid, strerror(
   (*__errno_location ())
   ))

                        ;
  }
 }

 if ((st.st_mode & (
                   (0400|0200|0100)
                          |
                           ((0400|0200|0100) >> 3)
                                  |
                                   (((0400|0200|0100) >> 3) >> 3)
                                          )) != mode) {
  if (chmod(tty, mode) == -1) {
   if (
      (*__errno_location ()) 
            == 
               30 
                     &&
       (st.st_mode & (
                     (0400 >> 3) 
                             | 
                               ((0400 >> 3) >> 3)
                                      )) == 0)
    sshlog("sshpty.c", __func__, 211, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "chmod(%.100s, 0%o) failed: %.100s", tty, (u_int)mode, strerror(
   (*__errno_location ())
   ))
                                          ;
   else
    sshfatal("sshpty.c", __func__, 214, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "chmod(%.100s, 0%o) failed: %.100s", tty, (u_int)mode, strerror(
   (*__errno_location ())
   ))
                                          ;
  }
 }
}


void
disconnect_controlling_tty(void)
{

 int fd;

 if ((fd = open(
               "/dev/tty"
                        , 
                          02 
                                 | 
                                   0400
                                           )) >= 0) {
  (void) ioctl(fd, 
                  0x5422
                           , 
                             ((void *)0)
                                 );
  close(fd);
 }

}
