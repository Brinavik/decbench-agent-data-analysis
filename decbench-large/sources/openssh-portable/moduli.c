











































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
struct dhgroup {
 int size;
 BIGNUM *g;
 BIGNUM *p;
};

DH *choose_dh(int, int, int);
DH *dh_new_group_asc(const char *, const char *);
DH *dh_new_group(BIGNUM *, BIGNUM *);
DH *dh_new_group1(void);
DH *dh_new_group14(void);
DH *dh_new_group16(void);
DH *dh_new_group18(void);
DH *dh_new_group_fallback(int);

int dh_gen_key(DH *, int);
int dh_pub_is_valid(const DH *, const BIGNUM *);

u_int dh_estimate(int);
void dh_set_moduli_file(const char *);
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






int ssh_compatible_openssl(long, long);
void ssh_libcrypto_init(void);
int EVP_CIPHER_CTX_set_iv(EVP_CIPHER_CTX *ctx,
    const unsigned char *iv, size_t len);
void DSA_SIG_get0(const DSA_SIG *sig, const BIGNUM **pr, const BIGNUM **ps);



int DSA_SIG_set0(DSA_SIG *sig, BIGNUM *r, BIGNUM *s);
EVP_MD_CTX *EVP_MD_CTX_new(void);



void EVP_MD_CTX_free(EVP_MD_CTX *ctx);
static u_int32_t *TinySieve, tinybits;


static u_int32_t *SmallSieve, smallbits, smallbase;


static u_int32_t *LargeSieve, largewords, largetries, largenumbers;
static u_int32_t largebits, largememory;
static BIGNUM *largebase;

int gen_candidates(FILE *, u_int32_t, u_int32_t, BIGNUM *);
int prime_test(FILE *, FILE *, u_int32_t, u_int32_t, char *, unsigned long,
    unsigned long);




static int
qfileout(FILE * ofile, u_int32_t otype, u_int32_t otests, u_int32_t otries,
    u_int32_t osize, u_int32_t ogenerator, BIGNUM * omodulus)
{
 struct tm *gtm;
 time_t time_now;
 int res;

 time(&time_now);
 gtm = gmtime(&time_now);
 if (gtm == 
           ((void *)0)
               )
  return -1;

 res = fprintf(ofile, "%04d%02d%02d%02d%02d%02d %u %u %u %u %x ",
     gtm->tm_year + 1900, gtm->tm_mon + 1, gtm->tm_mday,
     gtm->tm_hour, gtm->tm_min, gtm->tm_sec,
     otype, otests, otries, osize, ogenerator);

 if (res < 0)
  return (-1);

 if (BN_print_fp(ofile, omodulus) < 1)
  return (-1);

 res = fprintf(ofile, "\n");
 fflush(ofile);

 return (res > 0 ? 0 : -1);
}





static void
sieve_large(u_int32_t s32)
{
 u_int64_t r, u, s = s32;

 sshlog("moduli.c", __func__, 191, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "sieve_large %u", s32);
 largetries++;

 r = BN_mod_word(largebase, s32);
 if (r == 0)
  u = 0;
 else
  u = s - r;

 if (u < largebits * 2ULL) {





  if (u & 0x1)
   u += s;


  for (u /= 2; u < largebits; u += s)
   ((LargeSieve)[(u)>>((3)+(2))] |= (1L << ((u) & 31)));
 }


 r = (2 * r + 1) % s;
 if (r == 0)
  u = 0;
 else
  u = s - r;

 if (u < largebits * 4ULL) {





  while (u & 0x3) {
   if ((0xffffffffUL) - u < s)
    return;
   u += s;
  }


  for (u /= 4; u < largebits; u += s)
   ((LargeSieve)[(u)>>((3)+(2))] |= (1L << ((u) & 31)));
 }
}






int
gen_candidates(FILE *out, u_int32_t memory, u_int32_t power, BIGNUM *start)
{
 BIGNUM *q;
 u_int32_t j, r, s, t;
 u_int32_t smallwords = (1UL<<16) >> 6;
 u_int32_t tinywords = (1UL<<16) >> 6;
 time_t time_start, time_stop;
 u_int32_t i;
 int ret = 0;

 largememory = memory;

 if (memory != 0 &&
     (memory < (8UL) || memory > (127UL))) {
  sshlog("moduli.c", __func__, 259, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Invalid memory amount (min %ld, max %ld)", (8UL), (127UL))
                                   ;
  return (-1);
 }





 if (power > (1UL<<16)) {
  sshlog("moduli.c", __func__, 269, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Too many bits: %u > %lu", power, (1UL<<16));
  return (-1);
 } else if (power < ((511) + 1)) {
  sshlog("moduli.c", __func__, 272, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Too few bits: %u < %u", power, ((511) + 1));
  return (-1);
 }
 power--;







 largewords = ((power * power) >> (((3)+(2)) - (3)));





 if (largememory > (127UL)) {
  sshlog("moduli.c", __func__, 290, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Limited memory: %u MB; limit %lu MB", largememory, (127UL))
                                 ;
  largememory = (127UL);
 }

 if (largewords <= (largememory << ((20)-(2)))) {
  sshlog("moduli.c", __func__, 296, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Increased memory: %u MB; need %u bytes", largememory, (largewords << (2)))
                                              ;
  largewords = (largememory << ((20)-(2)));
 } else if (largememory > 0) {
  sshlog("moduli.c", __func__, 300, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Decreased memory: %u MB; want %u bytes", largememory, (largewords << (2)))
                                              ;
  largewords = (largememory << ((20)-(2)));
 }

 TinySieve = xcalloc(tinywords, sizeof(u_int32_t));
 tinybits = tinywords << ((3)+(2));

 SmallSieve = xcalloc(smallwords, sizeof(u_int32_t));
 smallbits = smallwords << ((3)+(2));




 while ((LargeSieve = calloc(largewords, sizeof(u_int32_t))) == 
                                                               ((void *)0)
                                                                   )
  largewords -= (1L << (((20)-(2)) - 2));

 largebits = largewords << ((3)+(2));
 largenumbers = largebits * 2;


 largetries = 0;
 if ((q = BN_new()) == 
                      ((void *)0)
                          )
  sshfatal("moduli.c", __func__, 323, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "BN_new failed");





 if ((largebase = BN_new()) == 
                              ((void *)0)
                                  )
  sshfatal("moduli.c", __func__, 330, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "BN_new failed");
 if (start == 
             ((void *)0)
                 ) {
  if (BN_rand(largebase, power, 1, 1) == 0)
   sshfatal("moduli.c", __func__, 333, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "BN_rand failed");
 } else {
  if (BN_copy(largebase, start) == 
                                  ((void *)0)
                                      )
   sshfatal("moduli.c", __func__, 336, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "BN_copy: failed");
 }


 if (BN_set_bit(largebase, 0) == 0)
  sshfatal("moduli.c", __func__, 341, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "BN_set_bit: failed");

 time(&time_start);

 sshlog("moduli.c", __func__, 345, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "%.24s Sieve next %u plus %u-bit", ctime(&time_start), largenumbers, power)
                         ;
 sshlog("moduli.c", __func__, 347, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "start point: 0x%s", BN_bn2hex(largebase));




 for (i = 0; i < tinybits; i++) {
  if (((TinySieve)[(i)>>((3)+(2))] & (1L << ((i) & 31))))
   continue;


  t = 2 * i + 3;


  for (j = i + t; j < tinybits; j += t)
   ((TinySieve)[(j)>>((3)+(2))] |= (1L << ((j) & 31)));

  sieve_large(t);
 }





 for (smallbase = (1UL<<16) + 3;
     smallbase < ((0xffffffffUL) - (1UL<<16));
     smallbase += (1UL<<16)) {
  for (i = 0; i < tinybits; i++) {
   if (((TinySieve)[(i)>>((3)+(2))] & (1L << ((i) & 31))))
    continue;


   t = 2 * i + 3;
   r = smallbase % t;

   if (r == 0) {
    s = 0;
   } else {

    s = t - r;
   }






   if (s & 1)
    s += t;


   for (s /= 2; s < smallbits; s += t)
    ((SmallSieve)[(s)>>((3)+(2))] |= (1L << ((s) & 31)));
  }




  for (i = 0; i < smallbits; i++) {
   if (((SmallSieve)[(i)>>((3)+(2))] & (1L << ((i) & 31))))
    continue;


   sieve_large((2 * i) + smallbase);
  }

  memset(SmallSieve, 0, smallwords << (2));
 }

 time(&time_stop);

 sshlog("moduli.c", __func__, 417, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "%.24s Sieved with %u small primes in %lld seconds", ctime(&time_stop), largetries, (long long)(time_stop - time_start))
                                                                        ;

 for (j = r = 0; j < largebits; j++) {
  if (((LargeSieve)[(j)>>((3)+(2))] & (1L << ((j) & 31))))
   continue;

  sshlog("moduli.c", __func__, 424, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "test q = largebase+%u", 2 * j);
  if (BN_set_word(q, 2 * j) == 0)
   sshfatal("moduli.c", __func__, 426, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "BN_set_word failed");
  if (BN_add(q, q, largebase) == 0)
   sshfatal("moduli.c", __func__, 428, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "BN_add failed");
  if (qfileout(out, (4),
      (0x02), largetries,
      (power - 1) , (0), q) == -1) {
   ret = -1;
   break;
  }

  r++;
 }

 time(&time_stop);

 free(LargeSieve);
 free(SmallSieve);
 free(TinySieve);

 sshlog("moduli.c", __func__, 445, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "%.24s Found %u candidates", ctime(&time_stop), r);

 return (ret);
}

static void
write_checkpoint(char *cpfile, u_int32_t lineno)
{
 FILE *fp;
 char tmp[
         4096
                 ];
 int r;

 r = snprintf(tmp, sizeof(tmp), "%s.XXXXXXXXXX", cpfile);
 if (r < 0 || r >= 
                  4096
                          ) {
  sshlog("moduli.c", __func__, 459, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "write_checkpoint: temp pathname too long");
  return;
 }
 if ((r = mkstemp(tmp)) == -1) {
  sshlog("moduli.c", __func__, 463, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "mkstemp(%s): %s", tmp, strerror(
 (*__errno_location ())
 ));
  return;
 }
 if ((fp = fdopen(r, "w")) == 
                             ((void *)0)
                                 ) {
  sshlog("moduli.c", __func__, 467, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "write_checkpoint: fdopen: %s", strerror(
 (*__errno_location ())
 ));
  unlink(tmp);
  close(r);
  return;
 }
 if (fprintf(fp, "%lu\n", (unsigned long)lineno) > 0 && fclose(fp) == 0
     && rename(tmp, cpfile) == 0)
  sshlog("moduli.c", __func__, 474, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "wrote checkpoint line %lu to '%s'", (unsigned long)lineno, cpfile)
                                    ;
 else
  sshlog("moduli.c", __func__, 477, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "failed to write to checkpoint file '%s': %s", cpfile, strerror(
 (*__errno_location ())
 ))
                      ;
}

static unsigned long
read_checkpoint(char *cpfile)
{
 FILE *fp;
 unsigned long lineno = 0;

 if ((fp = fopen(cpfile, "r")) == 
                                 ((void *)0)
                                     )
  return 0;
 if (fscanf(fp, "%lu\n", &lineno) < 1)
  sshlog("moduli.c", __func__, 490, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Failed to load checkpoint from '%s'", cpfile);
 else
  sshlog("moduli.c", __func__, 492, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Loaded checkpoint from '%s' line %lu", cpfile, lineno);
 fclose(fp);
 return lineno;
}

static unsigned long
count_lines(FILE *f)
{
 unsigned long count = 0;
 char lp[(100+8192) + 1];

 if (fseek(f, 0, 
                0
                        ) != 0) {
  sshlog("moduli.c", __func__, 504, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "input file is not seekable");
  return 
        (0x7fffffffffffffffL * 2UL + 1UL)
                 ;
 }
 while (fgets(lp, (100+8192) + 1, f) != 
                                      ((void *)0)
                                          )
  count++;
 rewind(f);
 sshlog("moduli.c", __func__, 510, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "input file has %lu lines", count);
 return count;
}

static char *
fmt_time(time_t seconds)
{
 int day, hr, min;
 static char buf[128];

 min = (seconds / 60) % 60;
 hr = (seconds / 60 / 60) % 24;
 day = seconds / 60 / 60 / 24;
 if (day > 0)
  snprintf(buf, sizeof buf, "%dd %d:%02d", day, hr, min);
 else
  snprintf(buf, sizeof buf, "%d:%02d", hr, min);
 return buf;
}

static void
print_progress(unsigned long start_lineno, unsigned long current_lineno,
    unsigned long end_lineno)
{
 static time_t time_start, time_prev;
 time_t time_now, elapsed;
 unsigned long num_to_process, processed, remaining, percent, eta;
 double time_per_line;
 char *eta_str;

 time_now = monotime();
 if (time_start == 0) {
  time_start = time_prev = time_now;
  return;
 }

 if (time_now - time_prev < 5 * 60)
  return;
 time_prev = time_now;
 elapsed = time_now - time_start;
 processed = current_lineno - start_lineno;
 remaining = end_lineno - current_lineno;
 num_to_process = end_lineno - start_lineno;
 time_per_line = (double)elapsed / processed;

 time(&time_now);
 if (end_lineno == 
                  (0x7fffffffffffffffL * 2UL + 1UL)
                           ) {
  sshlog("moduli.c", __func__, 557, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "%.24s processed %lu in %s", ctime(&time_now), processed, fmt_time(elapsed))
                                   ;
  return;
 }
 percent = 100 * processed / num_to_process;
 eta = time_per_line * remaining;
 eta_str = xstrdup(fmt_time(eta));
 sshlog("moduli.c", __func__, 564, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "%.24s processed %lu of %lu (%lu%%) in %s, ETA %s", ctime(&time_now), processed, num_to_process, percent, fmt_time(elapsed), eta_str)

                                ;
 free(eta_str);
}







int
prime_test(FILE *in, FILE *out, u_int32_t trials, u_int32_t generator_wanted,
    char *checkpoint_file, unsigned long start_lineno, unsigned long num_lines)
{
 BIGNUM *q, *p, *a;
 char *cp, *lp;
 u_int32_t count_in = 0, count_out = 0, count_possible = 0;
 u_int32_t generator_known, in_tests, in_tries, in_type, in_size;
 unsigned long last_processed = 0, end_lineno;
 time_t time_start, time_stop;
 int res, is_prime;

 if (trials < (4)) {
  sshlog("moduli.c", __func__, 589, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Minimum primality trials is %d", (4));
  return (-1);
 }

 if (num_lines == 0)
  end_lineno = count_lines(in);
 else
  end_lineno = start_lineno + num_lines;

 time(&time_start);

 if ((p = BN_new()) == 
                      ((void *)0)
                          )
  sshfatal("moduli.c", __func__, 601, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "BN_new failed");
 if ((q = BN_new()) == 
                      ((void *)0)
                          )
  sshfatal("moduli.c", __func__, 603, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "BN_new failed");

 sshlog("moduli.c", __func__, 605, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "%.24s Final %u Miller-Rabin trials (%x generator)", ctime(&time_start), trials, generator_wanted)
                                                  ;

 if (checkpoint_file != 
                       ((void *)0)
                           )
  last_processed = read_checkpoint(checkpoint_file);
 last_processed = start_lineno = (((last_processed) > (start_lineno)) ? (last_processed) : (start_lineno));
 if (end_lineno == 
                  (0x7fffffffffffffffL * 2UL + 1UL)
                           )
  sshlog("moduli.c", __func__, 612, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "process from line %lu from pipe", last_processed);
 else
  sshlog("moduli.c", __func__, 614, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "process from line %lu to line %lu", last_processed, end_lineno)
                 ;

 res = 0;
 lp = xmalloc((100+8192) + 1);
 while (fgets(lp, (100+8192) + 1, in) != 
                                       ((void *)0) 
                                            && count_in < end_lineno) {
  count_in++;
  if (count_in <= last_processed) {
   sshlog("moduli.c", __func__, 622, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "skipping line %u, before checkpoint or " "specified start line", count_in)
                                        ;
   continue;
  }
  if (checkpoint_file != 
                        ((void *)0)
                            )
   write_checkpoint(checkpoint_file, count_in);
  print_progress(start_lineno, count_in, end_lineno);
  if (strlen(lp) < 14 || *lp == '!' || *lp == '#') {
   sshlog("moduli.c", __func__, 630, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "%10u: comment or short line", count_in);
   continue;
  }



  cp = &lp[14];


  in_type = strtoul(cp, &cp, 10);


  in_tests = strtoul(cp, &cp, 10);

  if (in_tests & (0x01)) {
   sshlog("moduli.c", __func__, 645, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "%10u: known composite", count_in);
   continue;
  }


  in_tries = strtoul(cp, &cp, 10);


  in_size = strtoul(cp, &cp, 10);


  generator_known = strtoul(cp, &cp, 16);


  cp += strspn(cp, " ");


  switch (in_type) {
  case (4):
   sshlog("moduli.c", __func__, 664, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "%10u: (%u) Sophie-Germain", count_in, in_type);
   a = q;
   if (BN_hex2bn(&a, cp) == 0)
    sshfatal("moduli.c", __func__, 667, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "BN_hex2bn failed");

   if (BN_lshift(p, q, 1) == 0)
    sshfatal("moduli.c", __func__, 670, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "BN_lshift failed");
   if (BN_add_word(p, 1) == 0)
    sshfatal("moduli.c", __func__, 672, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "BN_add_word failed");
   in_size += 1;
   generator_known = 0;
   break;
  case (1):
  case (2):
  case (3):
  case (5):
  case (0):
   sshlog("moduli.c", __func__, 681, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "%10u: (%u)", count_in, in_type);
   a = p;
   if (BN_hex2bn(&a, cp) == 0)
    sshfatal("moduli.c", __func__, 684, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "BN_hex2bn failed");

   if (BN_rshift(q, p, 1) == 0)
    sshfatal("moduli.c", __func__, 687, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "BN_rshift failed");
   break;
  default:
   sshlog("moduli.c", __func__, 690, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "Unknown prime type");
   break;
  }





  if ((u_int32_t)BN_num_bits(p) != (in_size + 1)) {
   sshlog("moduli.c", __func__, 699, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "%10u: bit size %u mismatch", count_in, in_size);
   continue;
  }
  if (in_size < (511)) {
   sshlog("moduli.c", __func__, 703, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "%10u: bit size %u too short", count_in, in_size);
   continue;
  }

  if (in_tests & (0x04))
   in_tries += trials;
  else
   in_tries = trials;




  if (generator_known == 0) {
   if (BN_mod_word(p, 24) == 11)
    generator_known = 2;
   else {
    u_int32_t r = BN_mod_word(p, 10);

    if (r == 3 || r == 7)
     generator_known = 5;
   }
  }



  if (generator_wanted > 0 &&
      generator_wanted != generator_known) {
   sshlog("moduli.c", __func__, 730, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "%10u: generator %d != %d", count_in, generator_known, generator_wanted)
                                                   ;
   continue;
  }





  if (generator_known == 0) {
   sshlog("moduli.c", __func__, 740, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "%10u: no known generator", count_in);
   continue;
  }

  count_possible++;
  is_prime = BN_is_prime_ex(q, 1, 
                                 ((void *)0)
                                     , 
                                       ((void *)0)
                                           );
  if (is_prime < 0)
   sshfatal("moduli.c", __func__, 755, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "BN_is_prime_ex failed");
  if (is_prime == 0) {
   sshlog("moduli.c", __func__, 757, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "%10u: q failed first possible prime test", count_in)
                ;
   continue;
  }
  is_prime = BN_is_prime_ex(p, trials, 
                                      ((void *)0)
                                          , 
                                            ((void *)0)
                                                );
  if (is_prime < 0)
   sshfatal("moduli.c", __func__, 771, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "BN_is_prime_ex failed");
  if (is_prime == 0) {
   sshlog("moduli.c", __func__, 773, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "%10u: p is not prime", count_in);
   continue;
  }
  sshlog("moduli.c", __func__, 776, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%10u: p is almost certainly prime", count_in);


  is_prime = BN_is_prime_ex(q, trials - 1, 
                                          ((void *)0)
                                              , 
                                                ((void *)0)
                                                    );
  if (is_prime < 0)
   sshfatal("moduli.c", __func__, 781, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "BN_is_prime_ex failed");
  if (is_prime == 0) {
   sshlog("moduli.c", __func__, 783, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "%10u: q is not prime", count_in);
   continue;
  }
  sshlog("moduli.c", __func__, 786, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%10u: q is almost certainly prime", count_in);

  if (qfileout(out, (2),
      in_tests | (0x04),
      in_tries, in_size, generator_known, p)) {
   res = -1;
   break;
  }

  count_out++;
 }

 time(&time_stop);
 free(lp);
 BN_free(p);
 BN_free(q);

 if (checkpoint_file != 
                       ((void *)0)
                           )
  unlink(checkpoint_file);

 sshlog("moduli.c", __func__, 806, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "%.24s Found %u safe primes of %u candidates in %ld seconds", ctime(&time_stop), count_out, count_possible, (long) (time_stop - time_start))

                                     ;

 return (res);
}
