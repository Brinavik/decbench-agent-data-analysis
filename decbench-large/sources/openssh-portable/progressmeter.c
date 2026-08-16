











































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









void start_progress_meter(const char *, off_t, off_t *);
void refresh_progress_meter(int);
void stop_progress_meter(void);
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
static int can_output(void);


static void format_size(char *, int, off_t);
static void format_rate(char *, int, off_t);


static void sig_winch(int);
static void setscreensize(void);


static void sig_alarm(int);

static double start;
static double last_update;
static const char *file;
static off_t start_pos;
static off_t end_pos;
static off_t cur_pos;
static volatile off_t *counter;
static long stalled;
static int bytes_per_second;
static int win_size;
static volatile sig_atomic_t win_resized;
static volatile sig_atomic_t alarm_fired;


static const char unit[] = " KMGT";

static int
can_output(void)
{
 return (getpgrp() == tcgetpgrp(
                               1
                                            ));
}

static void
format_rate(char *buf, int size, off_t bytes)
{
 int i;

 bytes *= 100;
 for (i = 0; bytes >= 100*1000 && unit[i] != 'T'; i++)
  bytes = (bytes + 512) / 1024;
 if (i == 0) {
  i++;
  bytes = (bytes + 512) / 1024;
 }
 snprintf(buf, size, "%3lld.%1lld%c%s",
     (long long) (bytes + 5) / 100,
     (long long) (bytes + 5) / 10 % 10,
     unit[i],
     i ? "B" : " ");
}

static void
format_size(char *buf, int size, off_t bytes)
{
 int i;

 for (i = 0; bytes >= 10000 && unit[i] != 'T'; i++)
  bytes = (bytes + 512) / 1024;
 snprintf(buf, size, "%4lld%c%s",
     (long long) bytes,
     unit[i],
     i ? "B" : " ");
}

void
refresh_progress_meter(int force_update)
{
 char buf[512 + 1];
 off_t transferred;
 double elapsed, now;
 int percent;
 off_t bytes_left;
 int cur_speed;
 int hours, minutes, seconds;
 int file_len;

 if ((!force_update && !alarm_fired && !win_resized) || !can_output())
  return;
 alarm_fired = 0;

 if (win_resized) {
  setscreensize();
  win_resized = 0;
 }

 transferred = *counter - (cur_pos ? cur_pos : start_pos);
 cur_pos = *counter;
 now = monotime_double();
 bytes_left = end_pos - cur_pos;

 if (bytes_left > 0)
  elapsed = now - last_update;
 else {
  elapsed = now - start;

  transferred = end_pos - start_pos;
  bytes_per_second = 0;
 }


 if (elapsed != 0)
  cur_speed = (transferred / elapsed);
 else
  cur_speed = transferred;


 if (bytes_per_second != 0) {
  bytes_per_second = (bytes_per_second * 0.9) +
      (cur_speed * (1.0 - 0.9));
 } else
  bytes_per_second = cur_speed;


 buf[0] = '\0';
 file_len = win_size - 36;
 if (file_len > 0) {
  buf[0] = '\r';
  snmprintf(buf+1, sizeof(buf)-1, &file_len, "%-*s",
      file_len, file);
 }


 if (end_pos == 0 || cur_pos == end_pos)
  percent = 100;
 else
  percent = ((float)cur_pos / end_pos) * 100;
 snprintf(buf + strlen(buf), win_size - strlen(buf),
     " %3d%% ", percent);


 format_size(buf + strlen(buf), win_size - strlen(buf),
     cur_pos);
 strlcat(buf, " ", win_size);


 format_rate(buf + strlen(buf), win_size - strlen(buf),
     (off_t)bytes_per_second);
 strlcat(buf, "/s ", win_size);


 if (!transferred)
  stalled += elapsed;
 else
  stalled = 0;

 if (stalled >= 5)
  strlcat(buf, "- stalled -", win_size);
 else if (bytes_per_second == 0 && bytes_left)
  strlcat(buf, "  --:-- ETA", win_size);
 else {
  if (bytes_left > 0)
   seconds = bytes_left / bytes_per_second;
  else
   seconds = elapsed;

  hours = seconds / 3600;
  seconds -= hours * 3600;
  minutes = seconds / 60;
  seconds -= minutes * 60;

  if (hours != 0)
   snprintf(buf + strlen(buf), win_size - strlen(buf),
       "%d:%02d:%02d", hours, minutes, seconds);
  else
   snprintf(buf + strlen(buf), win_size - strlen(buf),
       "  %02d:%02d", minutes, seconds);

  if (bytes_left > 0)
   strlcat(buf, " ETA", win_size);
  else
   strlcat(buf, "    ", win_size);
 }

 atomicio((ssize_t (*)(int, void *, size_t))write, 
                 1
                              , buf, win_size - 1);
 last_update = now;
}


static void
sig_alarm(int ignore)
{
 alarm_fired = 1;
 alarm(1);
}

void
start_progress_meter(const char *f, off_t filesize, off_t *ctr)
{
 start = last_update = monotime_double();
 file = f;
 start_pos = *ctr;
 end_pos = filesize;
 cur_pos = 0;
 counter = ctr;
 stalled = 0;
 bytes_per_second = 0;

 setscreensize();
 refresh_progress_meter(1);

 ssh_signal(
           14
                  , sig_alarm);
 ssh_signal(
           28
                   , sig_winch);
 alarm(1);
}

void
stop_progress_meter(void)
{
 alarm(0);

 if (!can_output())
  return;


 if (cur_pos != end_pos)
  refresh_progress_meter(1);

 atomicio((ssize_t (*)(int, void *, size_t))write, 
                 1
                              , "\n", 1);
}


static void
sig_winch(int sig)
{
 win_resized = 1;
}

static void
setscreensize(void)
{
 struct winsize winsize;

 if (ioctl(
          1
                       , 
                         0x5413
                                   , &winsize) != -1 &&
     winsize.ws_col != 0) {
  if (winsize.ws_col > 512)
   win_size = 512;
  else
   win_size = winsize.ws_col;
 } else
  win_size = 80;
 win_size += 1;
}
