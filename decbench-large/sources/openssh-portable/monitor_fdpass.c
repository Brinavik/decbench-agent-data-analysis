











































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
int mm_send_fd(int, int);
int mm_receive_fd(int);

int
mm_send_fd(int sock, int fd)
{

 struct msghdr msg;

 union {
  struct cmsghdr hdr;
  char buf[
          ((((
          sizeof(int)
          ) + sizeof (size_t) - 1) & (size_t) ~(sizeof (size_t) - 1)) + (((sizeof (struct cmsghdr)) + sizeof (size_t) - 1) & (size_t) ~(sizeof (size_t) - 1)))
                                 ];
 } cmsgbuf;
 struct cmsghdr *cmsg;

 struct iovec vec;
 char ch = '\0';
 ssize_t n;
 struct pollfd pfd;

 memset(&msg, 0, sizeof(msg));




 memset(&cmsgbuf, 0, sizeof(cmsgbuf));
 msg.msg_control = (caddr_t)&cmsgbuf.buf;
 msg.msg_controllen = sizeof(cmsgbuf.buf);
 cmsg = 
       ((size_t) (
       &msg
       )->msg_controllen >= sizeof (struct cmsghdr) ? (struct cmsghdr *) (
       &msg
       )->msg_control : (struct cmsghdr *) 0)
                          ;
 cmsg->cmsg_len = 
                 ((((sizeof (struct cmsghdr)) + sizeof (size_t) - 1) & (size_t) ~(sizeof (size_t) - 1)) + (
                 sizeof(int)
                 ))
                                      ;
 cmsg->cmsg_level = 
                   1
                             ;
 cmsg->cmsg_type = 
                  SCM_RIGHTS
                            ;
 *(int *)
        ((
        cmsg
        )->__cmsg_data) 
                        = fd;


 vec.iov_base = &ch;
 vec.iov_len = 1;
 msg.msg_iov = &vec;
 msg.msg_iovlen = 1;

 pfd.fd = sock;
 pfd.events = 
             0x004
                    ;
 while ((n = sendmsg(sock, &msg, 0)) == -1 &&
     (
     (*__errno_location ()) 
           == 
              11 
                     || 
                        (*__errno_location ()) 
                              == 
                                 4
                                      )) {
  sshlog("monitor_fdpass.c", __func__, 92, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "sendmsg(%d): %s", fd, strerror(
 (*__errno_location ())
 ));
  (void)poll(&pfd, 1, -1);
 }
 if (n == -1) {
  sshlog("monitor_fdpass.c", __func__, 96, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sendmsg(%d): %s", fd, strerror(
 (*__errno_location ())
 ));
  return -1;
 }

 if (n != 1) {
  sshlog("monitor_fdpass.c", __func__, 101, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sendmsg: expected sent 1 got %zd", n);
  return -1;
 }
 return 0;




}

int
mm_receive_fd(int sock)
{

 struct msghdr msg;

 union {
  struct cmsghdr hdr;
  char buf[
          ((((
          sizeof(int)
          ) + sizeof (size_t) - 1) & (size_t) ~(sizeof (size_t) - 1)) + (((sizeof (struct cmsghdr)) + sizeof (size_t) - 1) & (size_t) ~(sizeof (size_t) - 1)))
                                 ];
 } cmsgbuf;
 struct cmsghdr *cmsg;

 struct iovec vec;
 ssize_t n;
 char ch;
 int fd;
 struct pollfd pfd;

 memset(&msg, 0, sizeof(msg));
 vec.iov_base = &ch;
 vec.iov_len = 1;
 msg.msg_iov = &vec;
 msg.msg_iovlen = 1;




 memset(&cmsgbuf, 0, sizeof(cmsgbuf));
 msg.msg_control = &cmsgbuf.buf;
 msg.msg_controllen = sizeof(cmsgbuf.buf);


 pfd.fd = sock;
 pfd.events = 
             0x001
                   ;
 while ((n = recvmsg(sock, &msg, 0)) == -1 &&
     (
     (*__errno_location ()) 
           == 
              11 
                     || 
                        (*__errno_location ()) 
                              == 
                                 4
                                      )) {
  sshlog("monitor_fdpass.c", __func__, 147, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "recvmsg: %s", strerror(
 (*__errno_location ())
 ));
  (void)poll(&pfd, 1, -1);
 }
 if (n == -1) {
  sshlog("monitor_fdpass.c", __func__, 151, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "recvmsg: %s", strerror(
 (*__errno_location ())
 ));
  return -1;
 }

 if (n != 1) {
  sshlog("monitor_fdpass.c", __func__, 156, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "recvmsg: expected received 1 got %zd", n);
  return -1;
 }







 cmsg = 
       ((size_t) (
       &msg
       )->msg_controllen >= sizeof (struct cmsghdr) ? (struct cmsghdr *) (
       &msg
       )->msg_control : (struct cmsghdr *) 0)
                          ;
 if (cmsg == 
            ((void *)0)
                ) {
  sshlog("monitor_fdpass.c", __func__, 168, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "no message header");
  return -1;
 }


 if (cmsg->cmsg_type != 
                       SCM_RIGHTS
                                 ) {
  sshlog("monitor_fdpass.c", __func__, 174, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "expected %d got %d", 
 SCM_RIGHTS
 , cmsg->cmsg_type);
  return -1;
 }

 fd = (*(int *)
              ((
              cmsg
              )->__cmsg_data)
                             );

 return fd;




}
