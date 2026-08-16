











































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


char *
chop(char *s)
{
 char *t = s;
 while (*t) {
  if (*t == '\n' || *t == '\r') {
   *t = '\0';
   return s;
  }
  t++;
 }
 return s;

}


void
rtrim(char *s)
{
 size_t i;

 if ((i = strlen(s)) == 0)
  return;
 for (i--; i > 0; i--) {
  if (
     ((*__ctype_b_loc ())[(int) ((
     (int)s[i]
     ))] & (unsigned short int) _ISspace)
                       )
   s[i] = '\0';
 }
}


int
set_nonblock(int fd)
{
 int val;

 val = fcntl(fd, 
                3
                       );
 if (val == -1) {
  sshlog("misc.c", __func__, 111, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "fcntl(%d, F_GETFL): %s", fd, strerror(
 (*__errno_location ())
 ));
  return (-1);
 }
 if (val & 
          04000
                    ) {
  sshlog("misc.c", __func__, 115, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "fd %d is O_NONBLOCK", fd);
  return (0);
 }
 sshlog("misc.c", __func__, 118, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "fd %d setting O_NONBLOCK", fd);
 val |= 
       04000
                 ;
 if (fcntl(fd, 
              4
                     , val) == -1) {
  sshlog("misc.c", __func__, 121, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "fcntl(%d, F_SETFL, O_NONBLOCK): %s", fd, strerror(
 (*__errno_location ())
 ))
                      ;
  return (-1);
 }
 return (0);
}

int
unset_nonblock(int fd)
{
 int val;

 val = fcntl(fd, 
                3
                       );
 if (val == -1) {
  sshlog("misc.c", __func__, 135, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "fcntl(%d, F_GETFL): %s", fd, strerror(
 (*__errno_location ())
 ));
  return (-1);
 }
 if (!(val & 
            04000
                      )) {
  sshlog("misc.c", __func__, 139, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "fd %d is not O_NONBLOCK", fd);
  return (0);
 }
 sshlog("misc.c", __func__, 142, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "fd %d clearing O_NONBLOCK", fd);
 val &= ~
        04000
                  ;
 if (fcntl(fd, 
              4
                     , val) == -1) {
  sshlog("misc.c", __func__, 145, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "fcntl(%d, F_SETFL, ~O_NONBLOCK): %s", fd, strerror(
 (*__errno_location ())
 ))
                          ;
  return (-1);
 }
 return (0);
}

const char *
ssh_gai_strerror(int gaierr)
{
 if (gaierr == 
              -11 
                         && 
                            (*__errno_location ()) 
                                  != 0)
  return strerror(
                 (*__errno_location ())
                      );
 return gai_strerror(gaierr);
}


void
set_nodelay(int fd)
{
 int opt;
 socklen_t optlen;

 optlen = sizeof opt;
 if (getsockopt(fd, 
                   IPPROTO_TCP
                              , 
                                1
                                           , &opt, &optlen) == -1) {
  sshlog("misc.c", __func__, 169, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "getsockopt TCP_NODELAY: %.100s", strerror(
 (*__errno_location ())
 ));
  return;
 }
 if (opt == 1) {
  sshlog("misc.c", __func__, 173, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "fd %d is TCP_NODELAY", fd);
  return;
 }
 opt = 1;
 sshlog("misc.c", __func__, 177, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "fd %d setting TCP_NODELAY", fd);
 if (setsockopt(fd, 
                   IPPROTO_TCP
                              , 
                                1
                                           , &opt, sizeof opt) == -1)
  sshlog("misc.c", __func__, 179, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "setsockopt TCP_NODELAY: %.100s", strerror(
 (*__errno_location ())
 ));
}


int
set_reuseaddr(int fd)
{
 int on = 1;

 if (setsockopt(fd, 
                   1
                             , 
                               2
                                           , &on, sizeof(on)) == -1) {
  sshlog("misc.c", __func__, 189, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "setsockopt SO_REUSEADDR fd %d: %s", fd, strerror(
 (*__errno_location ())
 ));
  return -1;
 }
 return 0;
}


char *
get_rdomain(int fd)
{

 return sys_get_rdomain(fd);
}

int
set_rdomain(int fd, const char *name)
{

 return sys_set_rdomain(fd, name);
}

int
get_sock_af(int fd)
{
 struct sockaddr_storage to;
 socklen_t tolen = sizeof(to);

 memset(&to, 0, sizeof(to));
 if (getsockname(fd, (struct sockaddr *)&to, &tolen) == -1)
  return -1;

 if (to.ss_family == 
                    10 
                             &&
     
    (__extension__ ({ const struct in6_addr *__a = (const struct in6_addr *) (
    &((struct sockaddr_in6 *)&to)->sin6_addr
    ); __a->__in6_u.__u6_addr32[0] == 0 && __a->__in6_u.__u6_addr32[1] == 0 && __a->__in6_u.__u6_addr32[2] == htonl (0xffff); }))
                                                                  )
  return 
        2
               ;

 return to.ss_family;
}

void
set_sock_tos(int fd, int tos)
{

 int af;

 switch ((af = get_sock_af(fd))) {
 case -1:

  break;
 case 
     2
            :

  sshlog("misc.c", __func__, 278, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "set socket %d IP_TOS 0x%02x", fd, tos);
  if (setsockopt(fd, 
                    IPPROTO_IP
                              , 
                                1
                                      ,
      &tos, sizeof(tos)) == -1) {
   sshlog("misc.c", __func__, 281, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "setsockopt socket %d IP_TOS %d: %s:", fd, tos, strerror(
  (*__errno_location ())
  ))
                                ;
  }

  break;
 case 
     10
             :

  sshlog("misc.c", __func__, 288, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "set socket %d IPV6_TCLASS 0x%02x", fd, tos);
  if (setsockopt(fd, 
                    IPPROTO_IPV6
                                , 
                                  67
                                             ,
      &tos, sizeof(tos)) == -1) {
   sshlog("misc.c", __func__, 291, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "setsockopt socket %d IPV6_TCLASS %d: %.100s:", fd, tos, strerror(
  (*__errno_location ())
  ))
                                ;
  }

  break;
 default:
  sshlog("misc.c", __func__, 297, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "unsupported socket family %d", af);
  break;
 }

}






static int
waitfd(int fd, int *timeoutp, short events)
{
 struct pollfd pfd;
 struct timeval t_start;
 int oerrno, r;

 pfd.fd = fd;
 pfd.events = events;
 for (; *timeoutp >= 0;) {
  monotime_tv(&t_start);
  r = poll(&pfd, 1, *timeoutp);
  oerrno = 
          (*__errno_location ())
               ;
  ms_subtract_diff(&t_start, timeoutp);
  
 (*__errno_location ()) 
       = oerrno;
  if (r > 0)
   return 0;
  else if (r == -1 && 
                     (*__errno_location ()) 
                           != 
                              11 
                                     && 
                                        (*__errno_location ()) 
                                              != 
                                                 4
                                                      )
   return -1;
  else if (r == 0)
   break;
 }

 
(*__errno_location ()) 
      = 
        110
                 ;
 return -1;
}






int
waitrfd(int fd, int *timeoutp) {
 return waitfd(fd, timeoutp, 
                            0x001
                                  );
}
int
timeout_connect(int sockfd, const struct sockaddr *serv_addr,
    socklen_t addrlen, int *timeoutp)
{
 int optval = 0;
 socklen_t optlen = sizeof(optval);


 if (timeoutp == 
                ((void *)0) 
                     || *timeoutp <= 0)
  return connect(sockfd, serv_addr, addrlen);

 set_nonblock(sockfd);
 for (;;) {
  if (connect(sockfd, serv_addr, addrlen) == 0) {

   unset_nonblock(sockfd);
   return 0;
  } else if (
            (*__errno_location ()) 
                  == 
                     4
                          )
   continue;
  else if (
          (*__errno_location ()) 
                != 
                   115
                              )
   return -1;
  break;
 }

 if (waitfd(sockfd, timeoutp, 
                             0x001 
                                    | 
                                      0x004
                                             ) == -1)
  return -1;


 if (getsockopt(sockfd, 
                       1
                                 , 
                                   4
                                           , &optval, &optlen) == -1) {
  sshlog("misc.c", __func__, 381, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "getsockopt: %s", strerror(
 (*__errno_location ())
 ));
  return -1;
 }
 if (optval != 0) {
  
 (*__errno_location ()) 
       = optval;
  return -1;
 }
 unset_nonblock(sockfd);
 return 0;
}






static char *
strdelim_internal(char **s, int split_equals)
{
 char *old;
 int wspace = 0;

 if (*s == 
          ((void *)0)
              )
  return 
        ((void *)0)
            ;

 old = *s;

 *s = strpbrk(*s,
     split_equals ? " \t\r\n" "\"" "=" : " \t\r\n" "\"");
 if (*s == 
          ((void *)0)
              )
  return (old);

 if (*s[0] == '\"') {
  memmove(*s, *s + 1, strlen(*s));

  if ((*s = strpbrk(*s, "\"")) == 
                                  ((void *)0)
                                      ) {
   return (
          ((void *)0)
              );
  } else {
   *s[0] = '\0';
   *s += strspn(*s + 1, " \t\r\n") + 1;
   return (old);
  }
 }


 if (split_equals && *s[0] == '=')
  wspace = 1;
 *s[0] = '\0';


 *s += strspn(*s + 1, " \t\r\n") + 1;
 if (split_equals && *s[0] == '=' && !wspace)
  *s += strspn(*s + 1, " \t\r\n") + 1;

 return (old);
}





char *
strdelim(char **s)
{
 return strdelim_internal(s, 1);
}




char *
strdelimw(char **s)
{
 return strdelim_internal(s, 0);
}

struct passwd *
pwcopy(struct passwd *pw)
{
 struct passwd *copy = xcalloc(1, sizeof(*copy));

 copy->pw_name = xstrdup(pw->pw_name);
 copy->pw_passwd = xstrdup(pw->pw_passwd == 
                                           ((void *)0) 
                                                ? "*" : pw->pw_passwd);

 copy->pw_gecos = xstrdup(pw->pw_gecos);

 copy->pw_uid = pw->pw_uid;
 copy->pw_gid = pw->pw_gid;
 copy->pw_dir = xstrdup(pw->pw_dir);
 copy->pw_shell = xstrdup(pw->pw_shell);
 return copy;
}






int
a2port(const char *s)
{
 struct servent *se;
 long long port;
 const char *errstr;

 port = strtonum(s, 0, 65535, &errstr);
 if (errstr == 
              ((void *)0)
                  )
  return (int)port;
 if ((se = getservbyname(s, "tcp")) != 
                                      ((void *)0)
                                          )
  return ntohs(se->s_port);
 return -1;
}

int
a2tun(const char *s, int *remote)
{
 const char *errstr = 
                     ((void *)0)
                         ;
 char *sp, *ep;
 int tun;

 if (remote != 
              ((void *)0)
                  ) {
  *remote = 0x7fffffff;
  sp = xstrdup(s);
  if ((ep = strchr(sp, ':')) == 
                               ((void *)0)
                                   ) {
   free(sp);
   return (a2tun(s, 
                   ((void *)0)
                       ));
  }
  ep[0] = '\0'; ep++;
  *remote = a2tun(ep, 
                     ((void *)0)
                         );
  tun = a2tun(sp, 
                 ((void *)0)
                     );
  free(sp);
  return (*remote == (0x7fffffff - 1) ? *remote : tun);
 }

 if (strcasecmp(s, "any") == 0)
  return (0x7fffffff);

 tun = strtonum(s, 0, (0x7fffffff - 2), &errstr);
 if (errstr != 
              ((void *)0)
                  )
  return ((0x7fffffff - 1));

 return (tun);
}
int
convtime(const char *s)
{
 long total, secs, multiplier;
 const char *p;
 char *endp;

 
(*__errno_location ()) 
      = 0;
 total = 0;
 p = s;

 if (p == 
         ((void *)0) 
              || *p == '\0')
  return -1;

 while (*p) {
  secs = strtol(p, &endp, 10);
  if (p == endp ||
      (
      (*__errno_location ()) 
            == 
               34 
                      && (secs == 
                                  (-0x7fffffff - 1) 
                                          || secs == 0x7fffffff)) ||
      secs < 0)
   return -1;

  multiplier = 1;
  switch (*endp++) {
  case '\0':
   endp--;
   break;
  case 's':
  case 'S':
   break;
  case 'm':
  case 'M':
   multiplier = (1 * 60);
   break;
  case 'h':
  case 'H':
   multiplier = ((1 * 60) * 60);
   break;
  case 'd':
  case 'D':
   multiplier = (((1 * 60) * 60) * 24);
   break;
  case 'w':
  case 'W':
   multiplier = ((((1 * 60) * 60) * 24) * 7);
   break;
  default:
   return -1;
  }
  if (secs > 0x7fffffff / multiplier)
   return -1;
  secs *= multiplier;
  if (total > 0x7fffffff - secs)
   return -1;
  total += secs;
  if (total < 0)
   return -1;
  p = endp;
 }

 return total;
}




const char *
fmt_timeframe(time_t t)
{
 char *buf;
 static char tfbuf[8][9];
 static int idx = 0;
 unsigned int sec, min, hrs, day;
 unsigned long long week;

 buf = tfbuf[idx++];
 if (idx == 8)
  idx = 0;

 week = t;

 sec = week % 60;
 week /= 60;
 min = week % 60;
 week /= 60;
 hrs = week % 24;
 week /= 24;
 day = week % 7;
 week /= 7;

 if (week > 0)
  snprintf(buf, 9, "%02lluw%01ud%02uh", week, day, hrs);
 else if (day > 0)
  snprintf(buf, 9, "%01ud%02uh%02um", day, hrs, min);
 else
  snprintf(buf, 9, "%02u:%02u:%02u", hrs, min, sec);

 return (buf);
}





char *
put_host_port(const char *host, u_short port)
{
 char *hoststr;

 if (port == 0 || port == 22)
  return(xstrdup(host));
 if (asprintf(&hoststr, "[%s]:%d", host, (int)port) == -1)
  sshfatal("misc.c", __func__, 672, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "put_host_port: asprintf: %s", strerror(
 (*__errno_location ())
 ));
 sshlog("misc.c", __func__, 673, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "put_host_port: %s", hoststr);
 return hoststr;
}
char *
hpdelim2(char **cp, char *delim)
{
 char *s, *old;

 if (cp == 
          ((void *)0) 
               || *cp == 
                         ((void *)0)
                             )
  return 
        ((void *)0)
            ;

 old = s = *cp;
 if (*s == '[') {
  if ((s = strchr(s, ']')) == 
                             ((void *)0)
                                 )
   return 
         ((void *)0)
             ;
  else
   s++;
 } else if ((s = strpbrk(s, ":/")) == 
                                     ((void *)0)
                                         )
  s = *cp + strlen(*cp);

 switch (*s) {
 case '\0':
  *cp = 
       ((void *)0)
           ;
  break;

 case ':':
 case '/':
  if (delim != 
              ((void *)0)
                  )
   *delim = *s;
  *s = '\0';
  *cp = s + 1;
  break;

 default:
  return 
        ((void *)0)
            ;
 }

 return old;
}


char *
hpdelim(char **cp)
{
 char *r, delim = '\0';

 r = hpdelim2(cp, &delim);
 if (delim == '/')
  return 
        ((void *)0)
            ;
 return r;
}

char *
cleanhostname(char *host)
{
 if (*host == '[' && host[strlen(host) - 1] == ']') {
  host[strlen(host) - 1] = '\0';
  return (host + 1);
 } else
  return host;
}

char *
colon(char *cp)
{
 int flag = 0;

 if (*cp == ':')
  return 
        ((void *)0)
            ;
 if (*cp == '[')
  flag = 1;

 for (; *cp; ++cp) {
  if (*cp == '@' && *(cp+1) == '[')
   flag = 1;
  if (*cp == ']' && *(cp+1) == ':' && flag)
   return (cp+1);
  if (*cp == ':' && !flag)
   return (cp);
  if (*cp == '/')
   return 
         ((void *)0)
             ;
 }
 return 
       ((void *)0)
           ;
}
int
parse_user_host_path(const char *s, char **userp, char **hostp, char **pathp)
{
 char *user = 
             ((void *)0)
                 , *host = 
                           ((void *)0)
                               , *path = 
                                         ((void *)0)
                                             ;
 char *sdup, *tmp;
 int ret = -1;

 if (userp != 
             ((void *)0)
                 )
  *userp = 
          ((void *)0)
              ;
 if (hostp != 
             ((void *)0)
                 )
  *hostp = 
          ((void *)0)
              ;
 if (pathp != 
             ((void *)0)
                 )
  *pathp = 
          ((void *)0)
              ;

 sdup = xstrdup(s);


 if ((tmp = colon(sdup)) == 
                           ((void *)0)
                               )
  goto out;


 *tmp++ = '\0';
 if (*tmp == '\0')
  tmp = ".";
 path = xstrdup(tmp);


 tmp = strrchr(sdup, '@');
 if (tmp != 
           ((void *)0)
               ) {
  *tmp++ = '\0';
  host = xstrdup(cleanhostname(tmp));
  if (*sdup != '\0')
   user = xstrdup(sdup);
 } else {
  host = xstrdup(cleanhostname(sdup));
  user = 
        ((void *)0)
            ;
 }


 if (userp != 
             ((void *)0)
                 ) {
  *userp = user;
  user = 
        ((void *)0)
            ;
 }
 if (hostp != 
             ((void *)0)
                 ) {
  *hostp = host;
  host = 
        ((void *)0)
            ;
 }
 if (pathp != 
             ((void *)0)
                 ) {
  *pathp = path;
  path = 
        ((void *)0)
            ;
 }
 ret = 0;
out:
 free(sdup);
 free(user);
 free(host);
 free(path);
 return ret;
}
int
parse_user_host_port(const char *s, char **userp, char **hostp, int *portp)
{
 char *sdup, *cp, *tmp;
 char *user = 
             ((void *)0)
                 , *host = 
                           ((void *)0)
                               ;
 int port = -1, ret = -1;

 if (userp != 
             ((void *)0)
                 )
  *userp = 
          ((void *)0)
              ;
 if (hostp != 
             ((void *)0)
                 )
  *hostp = 
          ((void *)0)
              ;
 if (portp != 
             ((void *)0)
                 )
  *portp = -1;

 if ((sdup = tmp = strdup(s)) == 
                                ((void *)0)
                                    )
  return -1;

 if ((cp = strrchr(tmp, '@')) != 
                                ((void *)0)
                                    ) {
  *cp = '\0';
  if (*tmp == '\0')
   goto out;
  if ((user = strdup(tmp)) == 
                             ((void *)0)
                                 )
   goto out;
  tmp = cp + 1;
 }

 if ((cp = hpdelim(&tmp)) == 
                            ((void *)0) 
                                 || *cp == '\0')
  goto out;
 host = xstrdup(cleanhostname(cp));

 if (tmp != 
           ((void *)0) 
                && *tmp != '\0') {
  if ((port = a2port(tmp)) <= 0)
   goto out;
 }

 if (userp != 
             ((void *)0)
                 ) {
  *userp = user;
  user = 
        ((void *)0)
            ;
 }
 if (hostp != 
             ((void *)0)
                 ) {
  *hostp = host;
  host = 
        ((void *)0)
            ;
 }
 if (portp != 
             ((void *)0)
                 )
  *portp = port;
 ret = 0;
 out:
 free(sdup);
 free(user);
 free(host);
 return ret;
}





static int
hexchar(const char *s)
{
 unsigned char result[2];
 int i;

 for (i = 0; i < 2; i++) {
  if (s[i] >= '0' && s[i] <= '9')
   result[i] = (unsigned char)(s[i] - '0');
  else if (s[i] >= 'a' && s[i] <= 'f')
   result[i] = (unsigned char)(s[i] - 'a') + 10;
  else if (s[i] >= 'A' && s[i] <= 'F')
   result[i] = (unsigned char)(s[i] - 'A') + 10;
  else
   return -1;
 }
 return (result[0] << 4) | result[1];
}





static char *
urldecode(const char *src)
{
 char *ret, *dst;
 int ch;

 ret = xmalloc(strlen(src) + 1);
 for (dst = ret; *src != '\0'; src++) {
  switch (*src) {
  case '+':
   *dst++ = ' ';
   break;
  case '%':
   if (!
       ((*__ctype_b_loc ())[(int) ((
       (unsigned char)src[1]
       ))] & (unsigned short int) _ISxdigit) 
                                       ||
       !
       ((*__ctype_b_loc ())[(int) ((
       (unsigned char)src[2]
       ))] & (unsigned short int) _ISxdigit) 
                                       ||
       (ch = hexchar(src + 1)) == -1) {
    free(ret);
    return 
          ((void *)0)
              ;
   }
   *dst++ = ch;
   src += 2;
   break;
  default:
   *dst++ = *src;
   break;
  }
 }
 *dst = '\0';

 return ret;
}
int
parse_uri(const char *scheme, const char *uri, char **userp, char **hostp,
    int *portp, char **pathp)
{
 char *uridup, *cp, *tmp, ch;
 char *user = 
             ((void *)0)
                 , *host = 
                           ((void *)0)
                               , *path = 
                                         ((void *)0)
                                             ;
 int port = -1, ret = -1;
 size_t len;

 len = strlen(scheme);
 if (strncmp(uri, scheme, len) != 0 || strncmp(uri + len, "://", 3) != 0)
  return 1;
 uri += len + 3;

 if (userp != 
             ((void *)0)
                 )
  *userp = 
          ((void *)0)
              ;
 if (hostp != 
             ((void *)0)
                 )
  *hostp = 
          ((void *)0)
              ;
 if (portp != 
             ((void *)0)
                 )
  *portp = -1;
 if (pathp != 
             ((void *)0)
                 )
  *pathp = 
          ((void *)0)
              ;

 uridup = tmp = xstrdup(uri);


 if ((cp = strchr(tmp, '@')) != 
                               ((void *)0)
                                   ) {
  char *delim;

  *cp = '\0';

  if ((delim = strchr(tmp, ';')) != 
                                   ((void *)0)
                                       ) {

   *delim = '\0';
  }
  if (*tmp == '\0') {

   goto out;
  }
  if ((user = urldecode(tmp)) == 
                                ((void *)0)
                                    )
   goto out;
  tmp = cp + 1;
 }


 if ((cp = hpdelim2(&tmp, &ch)) == 
                                  ((void *)0) 
                                       || *cp == '\0')
  goto out;
 host = xstrdup(cleanhostname(cp));
 if (!valid_domain(host, 0, 
                           ((void *)0)
                               ))
  goto out;

 if (tmp != 
           ((void *)0) 
                && *tmp != '\0') {
  if (ch == ':') {

   if ((cp = strchr(tmp, '/')) != 
                                 ((void *)0)
                                     )
    *cp = '\0';
   if ((port = a2port(tmp)) <= 0)
    goto out;
   tmp = cp ? cp + 1 : 
                      ((void *)0)
                          ;
  }
  if (tmp != 
            ((void *)0) 
                 && *tmp != '\0') {

   if ((path = urldecode(tmp)) == 
                                 ((void *)0)
                                     )
    goto out;
  }
 }


 if (userp != 
             ((void *)0)
                 ) {
  *userp = user;
  user = 
        ((void *)0)
            ;
 }
 if (hostp != 
             ((void *)0)
                 ) {
  *hostp = host;
  host = 
        ((void *)0)
            ;
 }
 if (portp != 
             ((void *)0)
                 )
  *portp = port;
 if (pathp != 
             ((void *)0)
                 ) {
  *pathp = path;
  path = 
        ((void *)0)
            ;
 }
 ret = 0;
 out:
 free(uridup);
 free(user);
 free(host);
 free(path);
 return ret;
}


void
addargs(arglist *args, char *fmt, ...)
{
 va_list ap;
 char *cp;
 u_int nalloc;
 int r;

 
__builtin_va_start(
ap
,
fmt
)
                 ;
 r = vasprintf(&cp, fmt, ap);
 
__builtin_va_end(
ap
)
          ;
 if (r == -1)
  sshfatal("misc.c", __func__, 1072, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "argument too long");

 nalloc = args->nalloc;
 if (args->list == 
                  ((void *)0)
                      ) {
  nalloc = 32;
  args->num = 0;
 } else if (args->num > (256 * 1024))
  sshfatal("misc.c", __func__, 1079, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "too many arguments");
 else if (args->num >= args->nalloc)
  sshfatal("misc.c", __func__, 1081, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "arglist corrupt");
 else if (args->num+2 >= nalloc)
  nalloc *= 2;

 args->list = xrecallocarray(args->list, args->nalloc,
     nalloc, sizeof(char *));
 args->nalloc = nalloc;
 args->list[args->num++] = cp;
 args->list[args->num] = 
                        ((void *)0)
                            ;
}

void
replacearg(arglist *args, u_int which, char *fmt, ...)
{
 va_list ap;
 char *cp;
 int r;

 
__builtin_va_start(
ap
,
fmt
)
                 ;
 r = vasprintf(&cp, fmt, ap);
 
__builtin_va_end(
ap
)
          ;
 if (r == -1)
  sshfatal("misc.c", __func__, 1103, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "argument too long");
 if (args->list == 
                  ((void *)0) 
                       || args->num >= args->nalloc)
  sshfatal("misc.c", __func__, 1105, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "arglist corrupt");

 if (which >= args->num)
  sshfatal("misc.c", __func__, 1108, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "tried to replace invalid arg %d >= %d", which, args->num)
                       ;
 free(args->list[which]);
 args->list[which] = cp;
}

void
freeargs(arglist *args)
{
 u_int i;

 if (args == 
            ((void *)0)
                )
  return;
 if (args->list != 
                  ((void *)0) 
                       && args->num < args->nalloc) {
  for (i = 0; i < args->num; i++)
   free(args->list[i]);
  free(args->list);
 }
 args->nalloc = args->num = 0;
 args->list = 
             ((void *)0)
                 ;
}





int
tilde_expand(const char *filename, uid_t uid, char **retp)
{
 char *ocopy = 
              ((void *)0)
                  , *copy, *s = 
                                ((void *)0)
                                    ;
 const char *path = 
                   ((void *)0)
                       , *user = 
                                 ((void *)0)
                                     ;
 struct passwd *pw;
 size_t len;
 int ret = -1, r, slash;

 *retp = 
        ((void *)0)
            ;
 if (*filename != '~') {
  *retp = xstrdup(filename);
  return 0;
 }
 ocopy = copy = xstrdup(filename + 1);

 if (*copy == '\0')
  path = 
        ((void *)0)
            ;
 else if (*copy == '/') {
  copy += strspn(copy, "/");
  if (*copy == '\0')
   path = 
         ((void *)0)
             ;
  else
   path = copy;
 } else {
  user = copy;
  if ((path = strchr(copy, '/')) != 
                                   ((void *)0)
                                       ) {
   copy[path - copy] = '\0';
   path++;
   path += strspn(path, "/");
   if (*path == '\0')
    path = 
          ((void *)0)
              ;

  }

 }
 if (user != 
            ((void *)0)
                ) {
  if ((pw = getpwnam(user)) == 
                              ((void *)0)
                                  ) {
   sshlog("misc.c", __func__, 1172, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "No such user %s", user);
   goto out;
  }
 } else if ((pw = getpwuid(uid)) == 
                                   ((void *)0)
                                       ) {
  sshlog("misc.c", __func__, 1176, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "No such uid %ld", (long)uid);
  goto out;
 }


 slash = (len = strlen(pw->pw_dir)) == 0 || pw->pw_dir[len - 1] != '/';

 if ((r = xasprintf(&s, "%s%s%s", pw->pw_dir,
     slash ? "/" : "", path != 
                              ((void *)0) 
                                   ? path : "")) <= 0) {
  sshlog("misc.c", __func__, 1185, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "xasprintf failed");
  goto out;
 }
 if (r >= 
         4096
                 ) {
  sshlog("misc.c", __func__, 1189, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Path too long");
  goto out;
 }

 ret = 0;
 *retp = s;
 s = 
    ((void *)0)
        ;
 out:
 free(s);
 free(ocopy);
 return ret;
}

char *
tilde_expand_filename(const char *filename, uid_t uid)
{
 char *ret;

 if (tilde_expand(filename, uid, &ret) != 0)
  cleanup_exit(255);
 return ret;
}
static char *
vdollar_percent_expand(int *parseerror, int dollar, int percent,
    const char *string, va_list ap)
{

 u_int num_keys = 0, i;
 struct {
  const char *key;
  const char *repl;
 } keys[16];
 struct sshbuf *buf;
 int r, missingvar = 0;
 char *ret = 
            ((void *)0)
                , *var, *varend, *val;
 size_t len;

 if ((buf = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("misc.c", __func__, 1235, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if (parseerror == 
                  ((void *)0)
                      )
  sshfatal("misc.c", __func__, 1237, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "null parseerror arg");
 *parseerror = 1;


 if (percent) {
  for (num_keys = 0; num_keys < 16; num_keys++) {
   keys[num_keys].key = 
                       __builtin_va_arg(
                       ap
                       ,
                       char *
                       )
                                         ;
   if (keys[num_keys].key == 
                            ((void *)0)
                                )
    break;
   keys[num_keys].repl = 
                        __builtin_va_arg(
                        ap
                        ,
                        char *
                        )
                                          ;
   if (keys[num_keys].repl == 
                             ((void *)0)
                                 ) {
    sshfatal("misc.c", __func__, 1248, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "NULL replacement for token %s", keys[num_keys].key)
                           ;
   }
  }
  if (num_keys == 16 && 
                                    __builtin_va_arg(
                                    ap
                                    ,
                                    char *
                                    ) 
                                                       != 
                                                          ((void *)0)
                                                              )
   sshfatal("misc.c", __func__, 1253, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "too many keys");
  if (num_keys == 0)
   sshfatal("misc.c", __func__, 1255, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "percent expansion without token list");
 }


 for (i = 0; *string != '\0'; string++) {

  if (dollar && string[0] == '$' && string[1] == '{') {
   string += 2;
   if ((varend = strchr(string, '}')) == 
                                        ((void *)0)
                                            ) {
    sshlog("misc.c", __func__, 1264, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "environment variable '%s' missing " "closing '}'", string)
                              ;
    goto out;
   }
   len = varend - string;
   if (len == 0) {
    sshlog("misc.c", __func__, 1270, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "zero-length environment variable");
    goto out;
   }
   var = xmalloc(len + 1);
   (void)strlcpy(var, string, len + 1);
   if ((val = getenv(var)) == 
                             ((void *)0)
                                 ) {
    sshlog("misc.c", __func__, 1276, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "env var ${%s} has no value", var);
    missingvar = 1;
   } else {
    sshlog("misc.c", __func__, 1279, 1, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "expand ${%s} -> '%s'", var, val);
    if ((r = sshbuf_put(buf, val, strlen(val))) !=0)
     sshfatal("misc.c", __func__, 1281, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_put ${}");
   }
   free(var);
   string += len;
   continue;
  }






  if (*string != '%' || !percent) {
 append:
   if ((r = sshbuf_put_u8(buf, *string)) != 0)
    sshfatal("misc.c", __func__, 1296, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_put_u8 %%");
   continue;
  }
  string++;

  if (*string == '%')
   goto append;
  if (*string == '\0') {
   sshlog("misc.c", __func__, 1304, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "invalid format");
   goto out;
  }
  for (i = 0; i < num_keys; i++) {
   if (strchr(keys[i].key, *string) != 
                                      ((void *)0)
                                          ) {
    if ((r = sshbuf_put(buf, keys[i].repl,
        strlen(keys[i].repl))) != 0)
     sshfatal("misc.c", __func__, 1311, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_put %%-repl");
    break;
   }
  }
  if (i >= num_keys) {
   sshlog("misc.c", __func__, 1316, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "unknown key %%%c", *string);
   goto out;
  }
 }
 if (!missingvar && (ret = sshbuf_dup_string(buf)) == 
                                                     ((void *)0)
                                                         )
  sshfatal("misc.c", __func__, 1321, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_dup_string failed");
 *parseerror = 0;
 out:
 sshbuf_free(buf);
 return *parseerror ? 
                     ((void *)0) 
                          : ret;

}







char *
dollar_expand(int *parseerr, const char *string, ...)
{
 char *ret;
 int err;
 va_list ap;

 
__builtin_va_start(
ap
,
string
)
                    ;
 ret = vdollar_percent_expand(&err, 1, 0, string, ap);
 
__builtin_va_end(
ap
)
          ;
 if (parseerr != 
                ((void *)0)
                    )
  *parseerr = err;
 return ret;
}





char *
percent_expand(const char *string, ...)
{
 char *ret;
 int err;
 va_list ap;

 
__builtin_va_start(
ap
,
string
)
                    ;
 ret = vdollar_percent_expand(&err, 0, 1, string, ap);
 
__builtin_va_end(
ap
)
          ;
 if (err)
  sshfatal("misc.c", __func__, 1365, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "failed");
 return ret;
}





char *
percent_dollar_expand(const char *string, ...)
{
 char *ret;
 int err;
 va_list ap;

 
__builtin_va_start(
ap
,
string
)
                    ;
 ret = vdollar_percent_expand(&err, 1, 1, string, ap);
 
__builtin_va_end(
ap
)
          ;
 if (err)
  sshfatal("misc.c", __func__, 1384, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "failed");
 return ret;
}

int
tun_open(int tun, int mode, char **ifname)
{

 return (sys_tun_open(tun, mode, ifname));
}

void
sanitise_stdfd(void)
{
 int nullfd, dupfd;

 if ((nullfd = dupfd = open(
                           "/dev/null"
                                        , 
                                          02
                                                )) == -1) {
  fprintf(
         stderr
               , "Couldn't open /dev/null: %s\n",
      strerror(
              (*__errno_location ())
                   ));
  exit(1);
 }
 while (++dupfd <= 
                  2
                               ) {

  if (fcntl(dupfd, 
                  3
                         ) == -1 && 
                                    (*__errno_location ()) 
                                          == 
                                             9
                                                  ) {
   if (dup2(nullfd, dupfd) == -1) {
    fprintf(
           stderr
                 , "dup2: %s\n", strerror(
                                          (*__errno_location ())
                                               ));
    exit(1);
   }
  }
 }
 if (nullfd > 
             2
                          )
  close(nullfd);
}

char *
tohex(const void *vp, size_t l)
{
 const u_char *p = (const u_char *)vp;
 char b[3], *r;
 size_t i, hl;

 if (l > 65536)
  return xstrdup("tohex: length > 65536");

 hl = l * 2 + 1;
 r = xcalloc(1, hl);
 for (i = 0; i < l; i++) {
  snprintf(b, sizeof(b), "%02x", p[i]);
  strlcat(r, b, hl);
 }
 return (r);
}






void
xextendf(char **sp, const char *sep, const char *fmt, ...)
{
 va_list ap;
 char *tmp1, *tmp2;

 
__builtin_va_start(
ap
,
fmt
)
                 ;
 xvasprintf(&tmp1, fmt, ap);
 
__builtin_va_end(
ap
)
          ;

 if (*sp == 
           ((void *)0) 
                || **sp == '\0') {
  free(*sp);
  *sp = tmp1;
  return;
 }
 xasprintf(&tmp2, "%s%s%s", *sp, sep == 
                                       ((void *)0) 
                                            ? "" : sep, tmp1);
 free(tmp1);
 free(*sp);
 *sp = tmp2;
}


u_int64_t
get_u64(const void *vp)
{
 const u_char *p = (const u_char *)vp;
 u_int64_t v;

 v = (u_int64_t)p[0] << 56;
 v |= (u_int64_t)p[1] << 48;
 v |= (u_int64_t)p[2] << 40;
 v |= (u_int64_t)p[3] << 32;
 v |= (u_int64_t)p[4] << 24;
 v |= (u_int64_t)p[5] << 16;
 v |= (u_int64_t)p[6] << 8;
 v |= (u_int64_t)p[7];

 return (v);
}

u_int32_t
get_u32(const void *vp)
{
 const u_char *p = (const u_char *)vp;
 u_int32_t v;

 v = (u_int32_t)p[0] << 24;
 v |= (u_int32_t)p[1] << 16;
 v |= (u_int32_t)p[2] << 8;
 v |= (u_int32_t)p[3];

 return (v);
}

u_int32_t
get_u32_le(const void *vp)
{
 const u_char *p = (const u_char *)vp;
 u_int32_t v;

 v = (u_int32_t)p[0];
 v |= (u_int32_t)p[1] << 8;
 v |= (u_int32_t)p[2] << 16;
 v |= (u_int32_t)p[3] << 24;

 return (v);
}

u_int16_t
get_u16(const void *vp)
{
 const u_char *p = (const u_char *)vp;
 u_int16_t v;

 v = (u_int16_t)p[0] << 8;
 v |= (u_int16_t)p[1];

 return (v);
}

void
put_u64(void *vp, u_int64_t v)
{
 u_char *p = (u_char *)vp;

 p[0] = (u_char)(v >> 56) & 0xff;
 p[1] = (u_char)(v >> 48) & 0xff;
 p[2] = (u_char)(v >> 40) & 0xff;
 p[3] = (u_char)(v >> 32) & 0xff;
 p[4] = (u_char)(v >> 24) & 0xff;
 p[5] = (u_char)(v >> 16) & 0xff;
 p[6] = (u_char)(v >> 8) & 0xff;
 p[7] = (u_char)v & 0xff;
}

void
put_u32(void *vp, u_int32_t v)
{
 u_char *p = (u_char *)vp;

 p[0] = (u_char)(v >> 24) & 0xff;
 p[1] = (u_char)(v >> 16) & 0xff;
 p[2] = (u_char)(v >> 8) & 0xff;
 p[3] = (u_char)v & 0xff;
}

void
put_u32_le(void *vp, u_int32_t v)
{
 u_char *p = (u_char *)vp;

 p[0] = (u_char)v & 0xff;
 p[1] = (u_char)(v >> 8) & 0xff;
 p[2] = (u_char)(v >> 16) & 0xff;
 p[3] = (u_char)(v >> 24) & 0xff;
}

void
put_u16(void *vp, u_int16_t v)
{
 u_char *p = (u_char *)vp;

 p[0] = (u_char)(v >> 8) & 0xff;
 p[1] = (u_char)v & 0xff;
}

void
ms_subtract_diff(struct timeval *start, int *ms)
{
 struct timeval diff, finish;

 monotime_tv(&finish);
 
do { (
&diff
)->tv_sec = (
&finish
)->tv_sec - (
start
)->tv_sec; (
&diff
)->tv_usec = (
&finish
)->tv_usec - (
start
)->tv_usec; if ((
&diff
)->tv_usec < 0) { --(
&diff
)->tv_sec; (
&diff
)->tv_usec += 1000000; } } while (0)
                               ;
 *ms -= (diff.tv_sec * 1000) + (diff.tv_usec / 1000);
}

void
ms_to_timespec(struct timespec *ts, int ms)
{
 if (ms < 0)
  ms = 0;
 ts->tv_sec = ms / 1000;
 ts->tv_nsec = (ms % 1000) * 1000 * 1000;
}

void
monotime_ts(struct timespec *ts)
{
 struct timeval tv;


 static int gettime_failed = 0;

 if (!gettime_failed) {

  if (clock_gettime(
                   7
                                 , ts) == 0)
   return;


  if (clock_gettime(
                   1
                                  , ts) == 0)
   return;



  if (clock_gettime(
                   0
                                 , ts) == 0)
   return;

  sshlog("misc.c", __func__, 1680, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "clock_gettime: %s", strerror(
 (*__errno_location ())
 ));
  gettime_failed = 1;
 }

 gettimeofday(&tv, 
                  ((void *)0)
                      );
 ts->tv_sec = tv.tv_sec;
 ts->tv_nsec = (long)tv.tv_usec * 1000;
}

void
monotime_tv(struct timeval *tv)
{
 struct timespec ts;

 monotime_ts(&ts);
 tv->tv_sec = ts.tv_sec;
 tv->tv_usec = ts.tv_nsec / 1000;
}

time_t
monotime(void)
{
 struct timespec ts;

 monotime_ts(&ts);
 return ts.tv_sec;
}

double
monotime_double(void)
{
 struct timespec ts;

 monotime_ts(&ts);
 return ts.tv_sec + ((double)ts.tv_nsec / 1000000000);
}

void
bandwidth_limit_init(struct bwlimit *bw, u_int64_t kbps, size_t buflen)
{
 bw->buflen = buflen;
 bw->rate = kbps;
 bw->thresh = buflen;
 bw->lamt = 0;
 
((
&bw->bwstart
)->tv_sec = (
&bw->bwstart
)->tv_usec = 0)
                        ;
 
((
&bw->bwend
)->tv_sec = (
&bw->bwend
)->tv_usec = 0)
                      ;
}


void
bandwidth_limit(struct bwlimit *bw, size_t read_len)
{
 u_int64_t waitlen;
 struct timespec ts, rm;

 bw->lamt += read_len;
 if (!
     ((
     &bw->bwstart
     )->tv_sec || (
     &bw->bwstart
     )->tv_usec)
                             ) {
  monotime_tv(&bw->bwstart);
  return;
 }
 if (bw->lamt < bw->thresh)
  return;

 monotime_tv(&bw->bwend);
 
do { (
&bw->bwend
)->tv_sec = (
&bw->bwend
)->tv_sec - (
&bw->bwstart
)->tv_sec; (
&bw->bwend
)->tv_usec = (
&bw->bwend
)->tv_usec - (
&bw->bwstart
)->tv_usec; if ((
&bw->bwend
)->tv_usec < 0) { --(
&bw->bwend
)->tv_sec; (
&bw->bwend
)->tv_usec += 1000000; } } while (0)
                                              ;
 if (!
     ((
     &bw->bwend
     )->tv_sec || (
     &bw->bwend
     )->tv_usec)
                           )
  return;

 bw->lamt *= 8;
 waitlen = (double)1000000L * bw->lamt / bw->rate;

 bw->bwstart.tv_sec = waitlen / 1000000L;
 bw->bwstart.tv_usec = waitlen % 1000000L;

 if (
    (((
    &bw->bwstart
    )->tv_sec == (
    &bw->bwend
    )->tv_sec) ? ((
    &bw->bwstart
    )->tv_usec 
    > 
    (
    &bw->bwend
    )->tv_usec) : ((
    &bw->bwstart
    )->tv_sec 
    > 
    (
    &bw->bwend
    )->tv_sec))
                                         ) {
  
 do { (
 &bw->bwend
 )->tv_sec = (
 &bw->bwstart
 )->tv_sec - (
 &bw->bwend
 )->tv_sec; (
 &bw->bwend
 )->tv_usec = (
 &bw->bwstart
 )->tv_usec - (
 &bw->bwend
 )->tv_usec; if ((
 &bw->bwend
 )->tv_usec < 0) { --(
 &bw->bwend
 )->tv_sec; (
 &bw->bwend
 )->tv_usec += 1000000; } } while (0)
                                               ;


  if (bw->bwend.tv_sec) {
   bw->thresh /= 2;
   if (bw->thresh < bw->buflen / 4)
    bw->thresh = bw->buflen / 4;
  } else if (bw->bwend.tv_usec < 10000) {
   bw->thresh *= 2;
   if (bw->thresh > bw->buflen * 8)
    bw->thresh = bw->buflen * 8;
  }

  
 { (
 &ts
 )->tv_sec = (
 &bw->bwend
 )->tv_sec; (
 &ts
 )->tv_nsec = (
 &bw->bwend
 )->tv_usec * 1000; }
                                     ;
  while (nanosleep(&ts, &rm) == -1) {
   if (
      (*__errno_location ()) 
            != 
               4
                    )
    break;
   ts = rm;
  }
 }

 bw->lamt = 0;
 monotime_tv(&bw->bwstart);
}


void
mktemp_proto(char *s, size_t len)
{
 const char *tmpdir;
 int r;

 if ((tmpdir = getenv("TMPDIR")) != 
                                   ((void *)0)
                                       ) {
  r = snprintf(s, len, "%s/ssh-XXXXXXXXXXXX", tmpdir);
  if (r > 0 && (size_t)r < len)
   return;
 }
 r = snprintf(s, len, "/tmp/ssh-XXXXXXXXXXXX");
 if (r < 0 || (size_t)r >= len)
  sshfatal("misc.c", __func__, 1794, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "template string too short");
}

static const struct {
 const char *name;
 int value;
} ipqos[] = {
 { "none", 0x7fffffff },
 { "af11", 
          0x28 
                          },
 { "af12", 
          0x30 
                          },
 { "af13", 
          0x38 
                          },
 { "af21", 
          0x48 
                          },
 { "af22", 
          0x50 
                          },
 { "af23", 
          0x58 
                          },
 { "af31", 
          0x68 
                          },
 { "af32", 
          0x70 
                          },
 { "af33", 
          0x78 
                          },
 { "af41", 
          0x88 
                          },
 { "af42", 
          0x90 
                          },
 { "af43", 
          0x98 
                          },
 { "cs0", 0x00 },
 { "cs1", 0x20 },
 { "cs2", 0x40 },
 { "cs3", 0x60 },
 { "cs4", 0x80 },
 { "cs5", 0xa0 },
 { "cs6", 0xc0 },
 { "cs7", 0xe0 },
 { "ef", 
        0xb8 
                      },
 { "le", 0x04 },
 { "lowdelay", 
              0x10 
                             },
 { "throughput", 
                0x08 
                                 },
 { "reliability", 
                 0x04 
                                   },
 { 
  ((void *)0)
      , -1 }
};

int
parse_ipqos(const char *cp)
{
 u_int i;
 char *ep;
 long val;

 if (cp == 
          ((void *)0)
              )
  return -1;
 for (i = 0; ipqos[i].name != 
                             ((void *)0)
                                 ; i++) {
  if (strcasecmp(cp, ipqos[i].name) == 0)
   return ipqos[i].value;
 }

 val = strtol(cp, &ep, 0);
 if (*cp == '\0' || *ep != '\0' || val < 0 || val > 255)
  return -1;
 return val;
}

const char *
iptos2str(int iptos)
{
 int i;
 static char iptos_str[sizeof "0xff"];

 for (i = 0; ipqos[i].name != 
                             ((void *)0)
                                 ; i++) {
  if (ipqos[i].value == iptos)
   return ipqos[i].name;
 }
 snprintf(iptos_str, sizeof iptos_str, "0x%02x", iptos);
 return iptos_str;
}

void
lowercase(char *s)
{
 for (; *s; s++)
  *s = tolower((u_char)*s);
}

int
unix_listener(const char *path, int backlog, int unlink_first)
{
 struct sockaddr_un sunaddr;
 int saved_errno, sock;

 memset(&sunaddr, 0, sizeof(sunaddr));
 sunaddr.sun_family = 
                     1
                            ;
 if (strlcpy(sunaddr.sun_path, path,
     sizeof(sunaddr.sun_path)) >= sizeof(sunaddr.sun_path)) {
  sshlog("misc.c", __func__, 1881, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "path \"%s\" too long for Unix domain socket", path);
  
 (*__errno_location ()) 
       = 
         36
                     ;
  return -1;
 }

 sock = socket(
              1
                     , 
                       SOCK_STREAM
                                  , 0);
 if (sock == -1) {
  saved_errno = 
               (*__errno_location ())
                    ;
  sshlog("misc.c", __func__, 1889, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "socket: %.100s", strerror(
 (*__errno_location ())
 ));
  
 (*__errno_location ()) 
       = saved_errno;
  return -1;
 }
 if (unlink_first == 1) {
  if (unlink(path) != 0 && 
                          (*__errno_location ()) 
                                != 
                                   2
                                         )
   sshlog("misc.c", __func__, 1895, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "unlink(%s): %.100s", path, strerror(
  (*__errno_location ())
  ));
 }
 if (bind(sock, (struct sockaddr *)&sunaddr, sizeof(sunaddr)) == -1) {
  saved_errno = 
               (*__errno_location ())
                    ;
  sshlog("misc.c", __func__, 1899, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "cannot bind to path %s: %s", path, strerror(
 (*__errno_location ())
 ));
  close(sock);
  
 (*__errno_location ()) 
       = saved_errno;
  return -1;
 }
 if (listen(sock, backlog) == -1) {
  saved_errno = 
               (*__errno_location ())
                    ;
  sshlog("misc.c", __func__, 1906, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "cannot listen on path %s: %s", path, strerror(
 (*__errno_location ())
 ));
  close(sock);
  unlink(path);
  
 (*__errno_location ()) 
       = saved_errno;
  return -1;
 }
 return sock;
}

void
sock_set_v6only(int s)
{

 int on = 1;

 sshlog("misc.c", __func__, 1921, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s: set socket %d IPV6_V6ONLY", __func__, s);
 if (setsockopt(s, 
                  IPPROTO_IPV6
                              , 
                                26
                                           , &on, sizeof(on)) == -1)
  sshlog("misc.c", __func__, 1923, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "setsockopt IPV6_V6ONLY: %s", strerror(
 (*__errno_location ())
 ));

}





static int
strcmp_maybe_null(const char *a, const char *b)
{
 if ((a == 
          ((void *)0) 
               && b != 
                       ((void *)0)
                           ) || (a != 
                                      ((void *)0) 
                                           && b == 
                                                   ((void *)0)
                                                       ))
  return 0;
 if (a != 
         ((void *)0) 
              && strcmp(a, b) != 0)
  return 0;
 return 1;
}





int
forward_equals(const struct Forward *a, const struct Forward *b)
{
 if (strcmp_maybe_null(a->listen_host, b->listen_host) == 0)
  return 0;
 if (a->listen_port != b->listen_port)
  return 0;
 if (strcmp_maybe_null(a->listen_path, b->listen_path) == 0)
  return 0;
 if (strcmp_maybe_null(a->connect_host, b->connect_host) == 0)
  return 0;
 if (a->connect_port != b->connect_port)
  return 0;
 if (strcmp_maybe_null(a->connect_path, b->connect_path) == 0)
  return 0;

 return 1;
}


int
daemonized(void)
{
 int fd;

 if ((fd = open(
               "/dev/tty"
                        , 
                          00 
                                   | 
                                     0400
                                             )) >= 0) {
  close(fd);
  return 0;
 }
 if (getppid() != 1)
  return 0;
 if (getsid(0) != getpid())
  return 0;
 sshlog("misc.c", __func__, 1978, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "already daemonized");
 return 1;
}






int
argv_split(const char *s, int *argcp, char ***argvp, int terminate_on_comment)
{
 int r = -1;
 int argc = 0, quote, i, j;
 char *arg, **argv = xcalloc(1, sizeof(*argv));

 *argvp = 
         ((void *)0)
             ;
 *argcp = 0;

 for (i = 0; s[i] != '\0'; i++) {

  if (s[i] == ' ' || s[i] == '\t')
   continue;
  if (terminate_on_comment && s[i] == '#')
   break;

  quote = 0;

  argv = xreallocarray(argv, (argc + 2), sizeof(*argv));
  arg = argv[argc++] = xcalloc(1, strlen(s + i) + 1);
  argv[argc] = 
              ((void *)0)
                  ;


  for (j = 0; s[i] != '\0'; i++) {
   if (s[i] == '\\') {
    if (s[i + 1] == '\'' ||
        s[i + 1] == '\"' ||
        s[i + 1] == '\\' ||
        (quote == 0 && s[i + 1] == ' ')) {
     i++;
     arg[j++] = s[i];
    } else {

     arg[j++] = s[i];
    }
   } else if (quote == 0 && (s[i] == ' ' || s[i] == '\t'))
    break;
   else if (quote == 0 && (s[i] == '\"' || s[i] == '\''))
    quote = s[i];
   else if (quote != 0 && s[i] == quote)
    quote = 0;
   else
    arg[j++] = s[i];
  }
  if (s[i] == '\0') {
   if (quote != 0) {

    r = -4;
    goto out;
   }
   break;
  }
 }

 *argcp = argc;
 *argvp = argv;
 argc = 0;
 argv = 
       ((void *)0)
           ;
 r = 0;
 out:
 if (argc != 0 && argv != 
                         ((void *)0)
                             ) {
  for (i = 0; i < argc; i++)
   free(argv[i]);
  free(argv);
 }
 return r;
}





char *
argv_assemble(int argc, char **argv)
{
 int i, j, ws, r;
 char c, *ret;
 struct sshbuf *buf, *arg;

 if ((buf = sshbuf_new()) == 
                            ((void *)0) 
                                 || (arg = sshbuf_new()) == 
                                                            ((void *)0)
                                                                )
  sshfatal("misc.c", __func__, 2068, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");

 for (i = 0; i < argc; i++) {
  ws = 0;
  sshbuf_reset(arg);
  for (j = 0; argv[i][j] != '\0'; j++) {
   r = 0;
   c = argv[i][j];
   switch (c) {
   case ' ':
   case '\t':
    ws = 1;
    r = sshbuf_put_u8(arg, c);
    break;
   case '\\':
   case '\'':
   case '"':
    if ((r = sshbuf_put_u8(arg, '\\')) != 0)
     break;

   default:
    r = sshbuf_put_u8(arg, c);
    break;
   }
   if (r != 0)
    sshfatal("misc.c", __func__, 2093, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_put_u8");
  }
  if ((i != 0 && (r = sshbuf_put_u8(buf, ' ')) != 0) ||
      (ws != 0 && (r = sshbuf_put_u8(buf, '"')) != 0) ||
      (r = sshbuf_putb(buf, arg)) != 0 ||
      (ws != 0 && (r = sshbuf_put_u8(buf, '"')) != 0))
   sshfatal("misc.c", __func__, 2099, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble");
 }
 if ((ret = malloc(sshbuf_len(buf) + 1)) == 
                                           ((void *)0)
                                               )
  sshfatal("misc.c", __func__, 2102, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "malloc failed");
 memcpy(ret, sshbuf_ptr(buf), sshbuf_len(buf));
 ret[sshbuf_len(buf)] = '\0';
 sshbuf_free(buf);
 sshbuf_free(arg);
 return ret;
}

char *
argv_next(int *argcp, char ***argvp)
{
 char *ret = (*argvp)[0];

 if (*argcp > 0 && ret != 
                         ((void *)0)
                             ) {
  (*argcp)--;
  (*argvp)++;
 }
 return ret;
}

void
argv_consume(int *argcp)
{
 *argcp = 0;
}

void
argv_free(char **av, int ac)
{
 int i;

 if (av == 
          ((void *)0)
              )
  return;
 for (i = 0; i < ac; i++)
  free(av[i]);
 free(av);
}


int
exited_cleanly(pid_t pid, const char *tag, const char *cmd, int quiet)
{
 int status;

 while (waitpid(pid, &status, 0) == -1) {
  if (
     (*__errno_location ()) 
           != 
              4
                   ) {
   sshlog("misc.c", __func__, 2148, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s waitpid: %s", tag, strerror(
  (*__errno_location ())
  ));
   return -1;
  }
 }
 if (
    (((signed char) (((
    status
    ) & 0x7f) + 1) >> 1) > 0)
                       ) {
  sshlog("misc.c", __func__, 2153, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s %s exited on signal %d", tag, cmd, 
 ((
 status
 ) & 0x7f)
 );
  return -1;
 } else if (
           (((
           status
           ) & 0xff00) >> 8) 
                               != 0) {
  sshlog("misc.c", __func__, 2156, 0, quiet ? SYSLOG_LEVEL_DEBUG1 : SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "%s %s failed, status %d", tag, cmd, 
 (((
 status
 ) & 0xff00) >> 8)
 )
                                                               ;
  return -1;
 }
 return 0;
}
int
safe_path(const char *name, struct stat *stp, const char *pw_dir,
    uid_t uid, char *err, size_t errlen)
{
 char buf[
         4096
                 ], homedir[
                            4096
                                    ];
 char *cp;
 int comparehome = 0;
 struct stat st;

 if (realpath(name, buf) == 
                           ((void *)0)
                               ) {
  snprintf(err, errlen, "realpath %s failed: %s", name,
      strerror(
              (*__errno_location ())
                   ));
  return -1;
 }
 if (pw_dir != 
              ((void *)0) 
                   && realpath(pw_dir, homedir) != 
                                                   ((void *)0)
                                                       )
  comparehome = 1;

 if (!
     ((((
     stp->st_mode
     )) & 0170000) == (0100000))
                          ) {
  snprintf(err, errlen, "%s is not a regular file", buf);
  return -1;
 }
 if ((!platform_sys_dir_uid(stp->st_uid) && stp->st_uid != uid) ||
     (stp->st_mode & 022) != 0) {
  snprintf(err, errlen, "bad ownership or modes for file %s",
      buf);
  return -1;
 }


 for (;;) {
  if ((cp = dirname(buf)) == 
                            ((void *)0)
                                ) {
   snprintf(err, errlen, "dirname() failed");
   return -1;
  }
  strlcpy(buf, cp, sizeof(buf));

  if (stat(buf, &st) == -1 ||
      (!platform_sys_dir_uid(st.st_uid) && st.st_uid != uid) ||
      (st.st_mode & 022) != 0) {
   snprintf(err, errlen,
       "bad ownership or modes for directory %s", buf);
   return -1;
  }


  if (comparehome && strcmp(homedir, buf) == 0)
   break;





  if ((strcmp("/", buf) == 0) || (strcmp(".", buf) == 0))
   break;
 }
 return 0;
}







int
safe_path_fd(int fd, const char *file, struct passwd *pw,
    char *err, size_t errlen)
{
 struct stat st;


 if (fstat(fd, &st) == -1) {
  snprintf(err, errlen, "cannot stat file %s: %s",
      file, strerror(
                    (*__errno_location ())
                         ));
  return -1;
 }
 return safe_path(file, &st, pw->pw_dir, pw->pw_uid, err, errlen);
}





void
child_set_env(char ***envp, u_int *envsizep, const char *name,
 const char *value)
{
 char **env;
 u_int envsize;
 u_int i, namelen;

 if (strchr(name, '=') != 
                         ((void *)0)
                             ) {
  sshlog("misc.c", __func__, 2268, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Invalid environment variable \"%.100s\"", name);
  return;
 }





 if (*envp == 
             ((void *)0) 
                  && *envsizep == 0) {
  *envp = xmalloc(sizeof(char *));
  *envp[0] = 
            ((void *)0)
                ;
  *envsizep = 1;
 }






 env = *envp;
 namelen = strlen(name);
 for (i = 0; env[i]; i++)
  if (strncmp(env[i], name, namelen) == 0 && env[i][namelen] == '=')
   break;
 if (env[i]) {

  free(env[i]);
 } else {

  envsize = *envsizep;
  if (i >= envsize - 1) {
   if (envsize >= 1000)
    sshfatal("misc.c", __func__, 2300, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "child_set_env: too many env vars");
   envsize += 50;
   env = (*envp) = xreallocarray(env, envsize, sizeof(char *));
   *envsizep = envsize;
  }

  env[i + 1] = 
              ((void *)0)
                  ;
 }



 env[i] = xmalloc(strlen(name) + 1 + strlen(value) + 1);
 snprintf(env[i], strlen(name) + 1 + strlen(value) + 1, "%s=%s", name, value);
}





int
valid_domain(char *name, int makelower, const char **errstr)
{
 size_t i, l = strlen(name);
 u_char c, last = '\0';
 static char errbuf[256];

 if (l == 0) {
  strlcpy(errbuf, "empty domain name", sizeof(errbuf));
  goto bad;
 }
 if (!
     ((*__ctype_b_loc ())[(int) ((
     (u_char)name[0]
     ))] & (unsigned short int) _ISalpha) 
                              && !
                                  ((*__ctype_b_loc ())[(int) ((
                                  (u_char)name[0]
                                  ))] & (unsigned short int) _ISdigit)
                                                          ) {
  snprintf(errbuf, sizeof(errbuf), "domain name \"%.100s\" "
      "starts with invalid character", name);
  goto bad;
 }
 for (i = 0; i < l; i++) {
  c = tolower((u_char)name[i]);
  if (makelower)
   name[i] = (char)c;
  if (last == '.' && c == '.') {
   snprintf(errbuf, sizeof(errbuf), "domain name "
       "\"%.100s\" contains consecutive separators", name);
   goto bad;
  }
  if (c != '.' && c != '-' && !
                              ((*__ctype_b_loc ())[(int) ((
                              c
                              ))] & (unsigned short int) _ISalnum) 
                                         &&
      c != '_') {
   snprintf(errbuf, sizeof(errbuf), "domain name "
       "\"%.100s\" contains invalid characters", name);
   goto bad;
  }
  last = c;
 }
 if (name[l - 1] == '.')
  name[l - 1] = '\0';
 if (errstr != 
              ((void *)0)
                  )
  *errstr = 
           ((void *)0)
               ;
 return 1;
bad:
 if (errstr != 
              ((void *)0)
                  )
  *errstr = errbuf;
 return 0;
}






int
valid_env_name(const char *name)
{
 const char *cp;

 if (name[0] == '\0')
  return 0;
 for (cp = name; *cp != '\0'; cp++) {
  if (!
      ((*__ctype_b_loc ())[(int) ((
      (u_char)*cp
      ))] & (unsigned short int) _ISalnum) 
                           && *cp != '_')
   return 0;
 }
 return 1;
}

const char *
atoi_err(const char *nptr, int *val)
{
 const char *errstr = 
                     ((void *)0)
                         ;
 long long num;

 if (nptr == 
            ((void *)0) 
                 || *nptr == '\0')
  return "missing";
 num = strtonum(nptr, 0, 0x7fffffff, &errstr);
 if (errstr == 
              ((void *)0)
                  )
  *val = (int)num;
 return errstr;
}

int
parse_absolute_time(const char *s, uint64_t *tp)
{
 struct tm tm;
 time_t tt;
 char buf[32], *fmt;
 const char *cp;
 size_t l;
 int is_utc = 0;

 *tp = 0;

 l = strlen(s);
 if (l > 1 && strcasecmp(s + l - 1, "Z") == 0) {
  is_utc = 1;
  l--;
 } else if (l > 3 && strcasecmp(s + l - 3, "UTC") == 0) {
  is_utc = 1;
  l -= 3;
 }





 switch (l) {
 case 8:
  fmt = "%Y-%m-%d";
  snprintf(buf, sizeof(buf), "%.4s-%.2s-%.2s", s, s + 4, s + 6);
  break;
 case 12:
  fmt = "%Y-%m-%dT%H:%M";
  snprintf(buf, sizeof(buf), "%.4s-%.2s-%.2sT%.2s:%.2s",
      s, s + 4, s + 6, s + 8, s + 10);
  break;
 case 14:
  fmt = "%Y-%m-%dT%H:%M:%S";
  snprintf(buf, sizeof(buf), "%.4s-%.2s-%.2sT%.2s:%.2s:%.2s",
      s, s + 4, s + 6, s + 8, s + 10, s + 12);
  break;
 default:
  return -4;
 }

 memset(&tm, 0, sizeof(tm));
 if ((cp = strptime(buf, fmt, &tm)) == 
                                      ((void *)0) 
                                           || *cp != '\0')
  return -4;
 if (is_utc) {
  if ((tt = timegm(&tm)) < 0)
   return -4;
 } else {
  if ((tt = mktime(&tm)) < 0)
   return -4;
 }

 *tp = (uint64_t)tt;
 return 0;
}




void
format_absolute_time(uint64_t t, char *buf, size_t len)
{
 time_t tt = t > 0x7fffffffffffffffLL ? 0x7fffffffffffffffLL : t;
 struct tm tm;

 localtime_r(&tt, &tm);
 strftime(buf, len, "%Y-%m-%dT%H:%M:%S", &tm);
}


int
path_absolute(const char *path)
{
 return (*path == '/') ? 1 : 0;
}

void
skip_space(char **cpp)
{
 char *cp;

 for (cp = *cpp; *cp == ' ' || *cp == '\t'; cp++)
  ;
 *cpp = cp;
}
int
opt_flag(const char *opt, int allow_negate, const char **optsp)
{
 size_t opt_len = strlen(opt);
 const char *opts = *optsp;
 int negate = 0;

 if (allow_negate && strncasecmp(opts, "no-", 3) == 0) {
  opts += 3;
  negate = 1;
 }
 if (strncasecmp(opts, opt, opt_len) == 0) {
  *optsp = opts + opt_len;
  return negate ? 0 : 1;
 }
 return -1;
}

char *
opt_dequote(const char **sp, const char **errstrp)
{
 const char *s = *sp;
 char *ret;
 size_t i;

 *errstrp = 
           ((void *)0)
               ;
 if (*s != '"') {
  *errstrp = "missing start quote";
  return 
        ((void *)0)
            ;
 }
 s++;
 if ((ret = malloc(strlen((s)) + 1)) == 
                                       ((void *)0)
                                           ) {
  *errstrp = "memory allocation failed";
  return 
        ((void *)0)
            ;
 }
 for (i = 0; *s != '\0' && *s != '"';) {
  if (s[0] == '\\' && s[1] == '"')
   s++;
  ret[i++] = *s++;
 }
 if (*s == '\0') {
  *errstrp = "missing end quote";
  free(ret);
  return 
        ((void *)0)
            ;
 }
 ret[i] = '\0';
 s++;
 *sp = s;
 return ret;
}

int
opt_match(const char **opts, const char *term)
{
 if (strncasecmp((*opts), term, strlen(term)) == 0 &&
     (*opts)[strlen(term)] == '=') {
  *opts += strlen(term) + 1;
  return 1;
 }
 return 0;
}

void
opt_array_append2(const char *file, const int line, const char *directive,
    char ***array, int **iarray, u_int *lp, const char *s, int i)
{

 if (*lp >= 0x7fffffff)
  sshfatal("misc.c", __func__, 2562, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s line %d: Too many %s entries", file, line, directive);

 if (iarray != 
              ((void *)0)
                  ) {
  *iarray = xrecallocarray(*iarray, *lp, *lp + 1,
      sizeof(**iarray));
  (*iarray)[*lp] = i;
 }

 *array = xrecallocarray(*array, *lp, *lp + 1, sizeof(**array));
 (*array)[*lp] = xstrdup(s);
 (*lp)++;
}

void
opt_array_append(const char *file, const int line, const char *directive,
    char ***array, u_int *lp, const char *s)
{
 opt_array_append2(file, line, directive, array, 
                                                ((void *)0)
                                                    , lp, s, 0);
}

sshsig_t
ssh_signal(int signum, sshsig_t handler)
{
 struct sigaction sa, osa;


 memset(&sa, 0, sizeof(sa));
 sa.
   __sigaction_handler.sa_handler 
              = handler;
 sigfillset(&sa.sa_mask);

 if (signum != 
              14
                     )
  sa.sa_flags = 
               0x10000000
                         ;

 if (sigaction(signum, &sa, &osa) == -1) {
  sshlog("misc.c", __func__, 2596, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "sigaction(%s): %s", strsignal(signum), strerror(
 (*__errno_location ())
 ));
  return 
        ((__sighandler_t) -1)
               ;
 }
 return osa.
           __sigaction_handler.sa_handler
                     ;
}

int
stdfd_devnull(int do_stdin, int do_stdout, int do_stderr)
{
 int devnull, ret = 0;

 if ((devnull = open(
                    "/dev/null"
                                 , 
                                   02
                                         )) == -1) {
  sshlog("misc.c", __func__, 2608, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "open %s: %s", 
 "/dev/null"
 , strerror(
 (*__errno_location ())
 ))
                      ;
  return -1;
 }
 if ((do_stdin && dup2(devnull, 
                               0
                                           ) == -1) ||
     (do_stdout && dup2(devnull, 
                                1
                                             ) == -1) ||
     (do_stderr && dup2(devnull, 
                                2
                                             ) == -1)) {
  sshlog("misc.c", __func__, 2615, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "dup2: %s", strerror(
 (*__errno_location ())
 ));
  ret = -1;
 }
 if (devnull > 
              2
                           )
  close(devnull);
 return ret;
}
pid_t
subprocess(const char *tag, const char *command,
    int ac, char **av, FILE **child, u_int flags,
    struct passwd *pw, privdrop_fn *drop_privs, privrestore_fn *restore_privs)
{
 FILE *f = 
          ((void *)0)
              ;
 struct stat st;
 int fd, devnull, p[2], i;
 pid_t pid;
 char *cp, errmsg[512];
 u_int nenv = 0;
 char **env = 
             ((void *)0)
                 ;


 if (drop_privs != 
                  ((void *)0) 
                       && (pw == 
                                 ((void *)0) 
                                      || restore_privs == 
                                                          ((void *)0)
                                                              )) {
  sshlog("misc.c", __func__, 2647, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s: inconsistent arguments", tag);
  return 0;
 }
 if (pw == 
          ((void *)0) 
               && (pw = getpwuid(getuid())) == 
                                               ((void *)0)
                                                   ) {
  sshlog("misc.c", __func__, 2651, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s: no user for current uid", tag);
  return 0;
 }
 if (child != 
             ((void *)0)
                 )
  *child = 
          ((void *)0)
              ;

 sshlog("misc.c", __func__, 2657, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s command \"%s\" running as %s (flags 0x%x)", tag, command, pw->pw_name, flags)
                                      ;


 if ((flags & (1)) != 0 &&
     (flags & (1<<1)) != 0) {
  sshlog("misc.c", __func__, 2663, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "inconsistent flags");
  return 0;
 }
 if (((flags & (1<<1)) == 0) != (child == 
                                                                ((void *)0)
                                                                    )) {
  sshlog("misc.c", __func__, 2667, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "inconsistent flags/output");
  return 0;
 }





 if (!path_absolute(av[0])) {
  sshlog("misc.c", __func__, 2676, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s path is not absolute", tag);
  return 0;
 }
 if (drop_privs != 
                  ((void *)0)
                      )
  drop_privs(pw);
 if (stat(av[0], &st) == -1) {
  sshlog("misc.c", __func__, 2682, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Could not stat %s \"%s\": %s", tag, av[0], strerror(
 (*__errno_location ())
 ))
                             ;
  goto restore_return;
 }
 if ((flags & (1<<3)) == 0 &&
     safe_path(av[0], &st, 
                          ((void *)0)
                              , 0, errmsg, sizeof(errmsg)) != 0) {
  sshlog("misc.c", __func__, 2688, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Unsafe %s \"%s\": %s", tag, av[0], errmsg);
  goto restore_return;
 }

 if (pipe(p) == -1) {
  sshlog("misc.c", __func__, 2693, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s: pipe: %s", tag, strerror(
 (*__errno_location ())
 ));
 restore_return:
  if (restore_privs != 
                      ((void *)0)
                          )
   restore_privs();
  return 0;
 }
 if (restore_privs != 
                     ((void *)0)
                         )
  restore_privs();

 switch ((pid = fork())) {
 case -1:
  sshlog("misc.c", __func__, 2704, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s: fork: %s", tag, strerror(
 (*__errno_location ())
 ));
  close(p[0]);
  close(p[1]);
  return 0;
 case 0:

  if ((flags & (1<<4)) == 0) {
   nenv = 5;
   env = xcalloc(sizeof(*env), nenv);
   child_set_env(&env, &nenv, "PATH", "/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin");
   child_set_env(&env, &nenv, "USER", pw->pw_name);
   child_set_env(&env, &nenv, "LOGNAME", pw->pw_name);
   child_set_env(&env, &nenv, "HOME", pw->pw_dir);
   if ((cp = getenv("LANG")) != 
                               ((void *)0)
                                   )
    child_set_env(&env, &nenv, "LANG", cp);
  }

  for (i = 1; i < 
                 (64 + 1)
                     ; i++)
   ssh_signal(i, 
                ((__sighandler_t) 0)
                       );

  if ((devnull = open(
                     "/dev/null"
                                  , 
                                    02
                                          )) == -1) {
   sshlog("misc.c", __func__, 2725, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: open %s: %s", tag, 
  "/dev/null"
  , strerror(
  (*__errno_location ())
  ))
                       ;
   _exit(1);
  }
  if (dup2(devnull, 
                   0
                               ) == -1) {
   sshlog("misc.c", __func__, 2730, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: dup2: %s", tag, strerror(
  (*__errno_location ())
  ));
   _exit(1);
  }


  fd = -1;
  if ((flags & (1<<1)) != 0)
   fd = p[1];
  else if ((flags & (1)) != 0)
   fd = devnull;
  if (fd != -1 && dup2(fd, 
                          1
                                       ) == -1) {
   sshlog("misc.c", __func__, 2741, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: dup2: %s", tag, strerror(
  (*__errno_location ())
  ));
   _exit(1);
  }
  closefrom(
           2 
                         + 1);

  if (geteuid() == 0 &&
      initgroups(pw->pw_name, pw->pw_gid) == -1) {
   sshlog("misc.c", __func__, 2748, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: initgroups(%s, %u): %s", tag, pw->pw_name, (u_int)pw->pw_gid, strerror(
  (*__errno_location ())
  ))
                                                       ;
   _exit(1);
  }
  if (setresgid(pw->pw_gid, pw->pw_gid, pw->pw_gid) == -1) {
   sshlog("misc.c", __func__, 2753, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: setresgid %u: %s", tag, (u_int)pw->pw_gid, strerror(
  (*__errno_location ())
  ))
                       ;
   _exit(1);
  }
  if (setresuid(pw->pw_uid, pw->pw_uid, pw->pw_uid) == -1) {
   sshlog("misc.c", __func__, 2758, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: setresuid %u: %s", tag, (u_int)pw->pw_uid, strerror(
  (*__errno_location ())
  ))
                       ;
   _exit(1);
  }

  if ((flags & (1)) != 0 &&
      dup2(
          0
                      , 
                        2
                                     ) == -1) {
   sshlog("misc.c", __func__, 2765, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: dup2: %s", tag, strerror(
  (*__errno_location ())
  ));
   _exit(1);
  }
  if (env != 
            ((void *)0)
                )
   execve(av[0], av, env);
  else
   execv(av[0], av);
  sshlog("misc.c", __func__, 2772, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s %s \"%s\": %s", tag, env == 
 ((void *)0) 
 ? "execv" : "execve", command, strerror(
 (*__errno_location ())
 ))
                               ;
  _exit(127);
 default:
  break;
 }

 close(p[1]);
 if ((flags & (1<<1)) == 0)
  close(p[0]);
 else if ((f = fdopen(p[0], "r")) == 
                                    ((void *)0)
                                        ) {
  sshlog("misc.c", __func__, 2783, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s: fdopen: %s", tag, strerror(
 (*__errno_location ())
 ));
  close(p[0]);

  kill(pid, 
           15
                  );
  while (waitpid(pid, 
                     ((void *)0)
                         , 0) == -1 && 
                                       (*__errno_location ()) 
                                             == 
                                                4
                                                     )
   ;
  return 0;
 }

 sshlog("misc.c", __func__, 2792, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s pid %ld", tag, (long)pid);
 if (child != 
             ((void *)0)
                 )
  *child = f;
 return pid;
}

const char *
lookup_env_in_list(const char *env, char * const *envs, size_t nenvs)
{
 size_t i, envlen;

 envlen = strlen(env);
 for (i = 0; i < nenvs; i++) {
  if (strncmp(envs[i], env, envlen) == 0 &&
      envs[i][envlen] == '=') {
   return envs[i] + envlen + 1;
  }
 }
 return 
       ((void *)0)
           ;
}

const char *
lookup_setenv_in_list(const char *env, char * const *envs, size_t nenvs)
{
 char *name, *cp;
 const char *ret;

 name = xstrdup(env);
 if ((cp = strchr(name, '=')) == 
                                ((void *)0)
                                    ) {
  free(name);
  return 
        ((void *)0)
            ;
 }
 *cp = '\0';
 ret = lookup_env_in_list(name, envs, nenvs);
 free(name);
 return ret;
}
