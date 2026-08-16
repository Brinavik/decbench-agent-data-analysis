











































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

static const char *moduli_filename;

void dh_set_moduli_file(const char *filename)
{
 moduli_filename = filename;
}

static const char * get_moduli_filename(void)
{
 return moduli_filename ? moduli_filename : "/usr/local/etc" "/moduli";
}

static int
parse_prime(int linenum, char *line, struct dhgroup *dhg)
{
 char *cp, *arg;
 char *strsize, *gen, *prime;
 const char *errstr = 
                     ((void *)0)
                         ;
 long long n;

 dhg->p = dhg->g = 
                  ((void *)0)
                      ;
 cp = line;
 if ((arg = strdelim(&cp)) == 
                             ((void *)0)
                                 )
  return 0;

 if (*arg == '\0')
  arg = strdelim(&cp);
 if (!arg || !*arg || *arg == '#')
  return 0;


 if (cp == 
          ((void *)0) 
               || *arg == '\0')
  goto truncated;
 arg = strsep(&cp, " ");
 if (cp == 
          ((void *)0) 
               || *arg == '\0')
  goto truncated;

 n = strtonum(arg, 0, 5, &errstr);
 if (errstr != 
              ((void *)0) 
                   || n != (2)) {
  sshlog("dh.c", __func__, 87, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "moduli:%d: type is not %d", linenum, (2));
  goto fail;
 }
 arg = strsep(&cp, " ");
 if (cp == 
          ((void *)0) 
               || *arg == '\0')
  goto truncated;

 n = strtonum(arg, 0, 0x1f, &errstr);
 if (errstr != 
              ((void *)0) 
                   ||
     (n & (0x01)) || !(n & ~(0x01))) {
  sshlog("dh.c", __func__, 97, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "moduli:%d: invalid moduli tests flag", linenum);
  goto fail;
 }
 arg = strsep(&cp, " ");
 if (cp == 
          ((void *)0) 
               || *arg == '\0')
  goto truncated;
 n = strtonum(arg, 0, 1<<30, &errstr);
 if (errstr != 
              ((void *)0) 
                   || n == 0) {
  sshlog("dh.c", __func__, 105, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "moduli:%d: invalid primality trial count", linenum);
  goto fail;
 }
 strsize = strsep(&cp, " ");
 if (cp == 
          ((void *)0) 
               || *strsize == '\0' ||
     (dhg->size = (int)strtonum(strsize, 0, 64*1024, &errstr)) == 0 ||
     errstr) {
  sshlog("dh.c", __func__, 112, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "moduli:%d: invalid prime length", linenum);
  goto fail;
 }

 dhg->size++;
 gen = strsep(&cp, " ");
 if (cp == 
          ((void *)0) 
               || *gen == '\0')
  goto truncated;
 prime = strsep(&cp, " ");
 if (cp != 
          ((void *)0) 
               || *prime == '\0') {
 truncated:
  sshlog("dh.c", __func__, 123, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "moduli:%d: truncated", linenum);
  goto fail;
 }

 if ((dhg->g = BN_new()) == 
                           ((void *)0) 
                                ||
     (dhg->p = BN_new()) == 
                           ((void *)0)
                               ) {
  sshlog("dh.c", __func__, 129, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "parse_prime: BN_new failed");
  goto fail;
 }
 if (BN_hex2bn(&dhg->g, gen) == 0) {
  sshlog("dh.c", __func__, 133, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "moduli:%d: could not parse generator value", linenum);
  goto fail;
 }
 if (BN_hex2bn(&dhg->p, prime) == 0) {
  sshlog("dh.c", __func__, 137, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "moduli:%d: could not parse prime value", linenum);
  goto fail;
 }
 if (BN_num_bits(dhg->p) != dhg->size) {
  sshlog("dh.c", __func__, 141, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "moduli:%d: prime has wrong size: actual %d listed %d", linenum, BN_num_bits(dhg->p), dhg->size - 1)
                                                  ;
  goto fail;
 }
 if (BN_cmp(dhg->g, BN_value_one()) <= 0) {
  sshlog("dh.c", __func__, 146, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "moduli:%d: generator is invalid", linenum);
  goto fail;
 }
 return 1;

 fail:
 BN_clear_free(dhg->g);
 BN_clear_free(dhg->p);
 dhg->g = dhg->p = 
                  ((void *)0)
                      ;
 return 0;
}

DH *
choose_dh(int min, int wantbits, int max)
{
 FILE *f;
 char *line = 
             ((void *)0)
                 ;
 size_t linesize = 0;
 int best, bestcount, which, linenum;
 struct dhgroup dhg;

 if ((f = fopen(get_moduli_filename(), "r")) == 
                                               ((void *)0)
                                                   ) {
  sshlog("dh.c", __func__, 168, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "WARNING: could not open %s (%s), using fixed modulus", get_moduli_filename(), strerror(
 (*__errno_location ())
 ))
                                             ;
  return (dh_new_group_fallback(max));
 }

 linenum = 0;
 best = bestcount = 0;
 while (getline(&line, &linesize, f) != -1) {
  linenum++;
  if (!parse_prime(linenum, line, &dhg))
   continue;
  BN_clear_free(dhg.g);
  BN_clear_free(dhg.p);

  if (dhg.size > max || dhg.size < min)
   continue;

  if ((dhg.size > wantbits && dhg.size < best) ||
      (dhg.size > best && best < wantbits)) {
   best = dhg.size;
   bestcount = 0;
  }
  if (dhg.size == best)
   bestcount++;
 }
 free(line);
 line = 
       ((void *)0)
           ;
 linesize = 0;
 rewind(f);

 if (bestcount == 0) {
  fclose(f);
  sshlog("dh.c", __func__, 200, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "WARNING: no suitable primes in %s", get_moduli_filename())
                            ;
  return (dh_new_group_fallback(max));
 }
 which = arc4random_uniform(bestcount);

 linenum = 0;
 bestcount = 0;
 while (getline(&line, &linesize, f) != -1) {
  linenum++;
  if (!parse_prime(linenum, line, &dhg))
   continue;
  if ((dhg.size > max || dhg.size < min) ||
      dhg.size != best ||
      bestcount++ != which) {
   BN_clear_free(dhg.g);
   BN_clear_free(dhg.p);
   continue;
  }
  break;
 }
 free(line);
 line = 
       ((void *)0)
           ;
 fclose(f);
 if (bestcount != which + 1) {
  sshlog("dh.c", __func__, 225, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "WARNING: selected prime disappeared in %s, giving up", get_moduli_filename())
                            ;
  return (dh_new_group_fallback(max));
 }

 return (dh_new_group(dhg.g, dhg.p));
}



int
dh_pub_is_valid(const DH *dh, const BIGNUM *dh_pub)
{
 int i;
 int n = BN_num_bits(dh_pub);
 int bits_set = 0;
 BIGNUM *tmp;
 const BIGNUM *dh_p;

 DH_get0_pqg(dh, &dh_p, 
                       ((void *)0)
                           , 
                             ((void *)0)
                                 );

 if (BN_is_negative(dh_pub)) {
  sshlog("dh.c", __func__, 247, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "invalid public DH value: negative");
  return 0;
 }
 if (BN_cmp(dh_pub, BN_value_one()) != 1) {
  sshlog("dh.c", __func__, 251, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "invalid public DH value: <= 1");
  return 0;
 }

 if ((tmp = BN_new()) == 
                        ((void *)0)
                            ) {
  sshlog("dh.c", __func__, 256, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "BN_new failed");
  return 0;
 }
 if (!BN_sub(tmp, dh_p, BN_value_one()) ||
     BN_cmp(dh_pub, tmp) != -1) {
  BN_clear_free(tmp);
  sshlog("dh.c", __func__, 262, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "invalid public DH value: >= p-1");
  return 0;
 }
 BN_clear_free(tmp);

 for (i = 0; i <= n; i++)
  if (BN_is_bit_set(dh_pub, i))
   bits_set++;
 sshlog("dh.c", __func__, 270, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "bits set: %d/%d", bits_set, BN_num_bits(dh_p));




 if (bits_set < 4) {
  sshlog("dh.c", __func__, 276, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "invalid public DH value (%d/%d)", bits_set, BN_num_bits(dh_p))
                                  ;
  return 0;
 }
 return 1;
}

int
dh_gen_key(DH *dh, int need)
{
 int pbits;
 const BIGNUM *dh_p, *pub_key;

 DH_get0_pqg(dh, &dh_p, 
                       ((void *)0)
                           , 
                             ((void *)0)
                                 );

 if (need < 0 || dh_p == 
                        ((void *)0) 
                             ||
     (pbits = BN_num_bits(dh_p)) <= 0 ||
     need > 0x7fffffff / 2 || 2 * need > pbits)
  return -10;
 if (need < 256)
  need = 256;




 if (!DH_set_length(dh, (((need * 2) < (pbits - 1)) ? (need * 2) : (pbits - 1))))
  return -22;

 if (DH_generate_key(dh) == 0)
  return -22;
 DH_get0_key(dh, &pub_key, 
                          ((void *)0)
                              );
 if (!dh_pub_is_valid(dh, pub_key))
  return -4;
 return 0;
}

DH *
dh_new_group_asc(const char *gen, const char *modulus)
{
 DH *dh;
 BIGNUM *dh_p = 
               ((void *)0)
                   , *dh_g = 
                             ((void *)0)
                                 ;

 if ((dh = DH_new()) == 
                       ((void *)0)
                           )
  return 
        ((void *)0)
            ;
 if (BN_hex2bn(&dh_p, modulus) == 0 ||
     BN_hex2bn(&dh_g, gen) == 0)
  goto fail;
 if (!DH_set0_pqg(dh, dh_p, 
                           ((void *)0)
                               , dh_g))
  goto fail;
 return dh;
 fail:
 DH_free(dh);
 BN_clear_free(dh_p);
 BN_clear_free(dh_g);
 return 
       ((void *)0)
           ;
}





DH *
dh_new_group(BIGNUM *gen, BIGNUM *modulus)
{
 DH *dh;

 if ((dh = DH_new()) == 
                       ((void *)0)
                           )
  return 
        ((void *)0)
            ;
 if (!DH_set0_pqg(dh, modulus, 
                              ((void *)0)
                                  , gen)) {
  DH_free(dh);
  return 
        ((void *)0)
            ;
 }

 return dh;
}


DH *
dh_new_group1(void)
{
 static char *gen = "2", *group1 =
     "FFFFFFFF" "FFFFFFFF" "C90FDAA2" "2168C234" "C4C6628B" "80DC1CD1"
     "29024E08" "8A67CC74" "020BBEA6" "3B139B22" "514A0879" "8E3404DD"
     "EF9519B3" "CD3A431B" "302B0A6D" "F25F1437" "4FE1356D" "6D51C245"
     "E485B576" "625E7EC6" "F44C42E9" "A637ED6B" "0BFF5CB6" "F406B7ED"
     "EE386BFB" "5A899FA5" "AE9F2411" "7C4B1FE6" "49286651" "ECE65381"
     "FFFFFFFF" "FFFFFFFF";

 return (dh_new_group_asc(gen, group1));
}


DH *
dh_new_group14(void)
{
 static char *gen = "2", *group14 =
     "FFFFFFFF" "FFFFFFFF" "C90FDAA2" "2168C234" "C4C6628B" "80DC1CD1"
     "29024E08" "8A67CC74" "020BBEA6" "3B139B22" "514A0879" "8E3404DD"
     "EF9519B3" "CD3A431B" "302B0A6D" "F25F1437" "4FE1356D" "6D51C245"
     "E485B576" "625E7EC6" "F44C42E9" "A637ED6B" "0BFF5CB6" "F406B7ED"
     "EE386BFB" "5A899FA5" "AE9F2411" "7C4B1FE6" "49286651" "ECE45B3D"
     "C2007CB8" "A163BF05" "98DA4836" "1C55D39A" "69163FA8" "FD24CF5F"
     "83655D23" "DCA3AD96" "1C62F356" "208552BB" "9ED52907" "7096966D"
     "670C354E" "4ABC9804" "F1746C08" "CA18217C" "32905E46" "2E36CE3B"
     "E39E772C" "180E8603" "9B2783A2" "EC07A28F" "B5C55DF0" "6F4C52C9"
     "DE2BCBF6" "95581718" "3995497C" "EA956AE5" "15D22618" "98FA0510"
     "15728E5A" "8AACAA68" "FFFFFFFF" "FFFFFFFF";

 return (dh_new_group_asc(gen, group14));
}


DH *
dh_new_group16(void)
{
 static char *gen = "2", *group16 =
     "FFFFFFFF" "FFFFFFFF" "C90FDAA2" "2168C234" "C4C6628B" "80DC1CD1"
     "29024E08" "8A67CC74" "020BBEA6" "3B139B22" "514A0879" "8E3404DD"
     "EF9519B3" "CD3A431B" "302B0A6D" "F25F1437" "4FE1356D" "6D51C245"
     "E485B576" "625E7EC6" "F44C42E9" "A637ED6B" "0BFF5CB6" "F406B7ED"
     "EE386BFB" "5A899FA5" "AE9F2411" "7C4B1FE6" "49286651" "ECE45B3D"
     "C2007CB8" "A163BF05" "98DA4836" "1C55D39A" "69163FA8" "FD24CF5F"
     "83655D23" "DCA3AD96" "1C62F356" "208552BB" "9ED52907" "7096966D"
     "670C354E" "4ABC9804" "F1746C08" "CA18217C" "32905E46" "2E36CE3B"
     "E39E772C" "180E8603" "9B2783A2" "EC07A28F" "B5C55DF0" "6F4C52C9"
     "DE2BCBF6" "95581718" "3995497C" "EA956AE5" "15D22618" "98FA0510"
     "15728E5A" "8AAAC42D" "AD33170D" "04507A33" "A85521AB" "DF1CBA64"
     "ECFB8504" "58DBEF0A" "8AEA7157" "5D060C7D" "B3970F85" "A6E1E4C7"
     "ABF5AE8C" "DB0933D7" "1E8C94E0" "4A25619D" "CEE3D226" "1AD2EE6B"
     "F12FFA06" "D98A0864" "D8760273" "3EC86A64" "521F2B18" "177B200C"
     "BBE11757" "7A615D6C" "770988C0" "BAD946E2" "08E24FA0" "74E5AB31"
     "43DB5BFC" "E0FD108E" "4B82D120" "A9210801" "1A723C12" "A787E6D7"
     "88719A10" "BDBA5B26" "99C32718" "6AF4E23C" "1A946834" "B6150BDA"
     "2583E9CA" "2AD44CE8" "DBBBC2DB" "04DE8EF9" "2E8EFC14" "1FBECAA6"
     "287C5947" "4E6BC05D" "99B2964F" "A090C3A2" "233BA186" "515BE7ED"
     "1F612970" "CEE2D7AF" "B81BDD76" "2170481C" "D0069127" "D5B05AA9"
     "93B4EA98" "8D8FDDC1" "86FFB7DC" "90A6C08F" "4DF435C9" "34063199"
     "FFFFFFFF" "FFFFFFFF";

 return (dh_new_group_asc(gen, group16));
}


DH *
dh_new_group18(void)
{
 static char *gen = "2", *group18 =
     "FFFFFFFF" "FFFFFFFF" "C90FDAA2" "2168C234" "C4C6628B" "80DC1CD1"
     "29024E08" "8A67CC74" "020BBEA6" "3B139B22" "514A0879" "8E3404DD"
     "EF9519B3" "CD3A431B" "302B0A6D" "F25F1437" "4FE1356D" "6D51C245"
     "E485B576" "625E7EC6" "F44C42E9" "A637ED6B" "0BFF5CB6" "F406B7ED"
     "EE386BFB" "5A899FA5" "AE9F2411" "7C4B1FE6" "49286651" "ECE45B3D"
     "C2007CB8" "A163BF05" "98DA4836" "1C55D39A" "69163FA8" "FD24CF5F"
     "83655D23" "DCA3AD96" "1C62F356" "208552BB" "9ED52907" "7096966D"
     "670C354E" "4ABC9804" "F1746C08" "CA18217C" "32905E46" "2E36CE3B"
     "E39E772C" "180E8603" "9B2783A2" "EC07A28F" "B5C55DF0" "6F4C52C9"
     "DE2BCBF6" "95581718" "3995497C" "EA956AE5" "15D22618" "98FA0510"
     "15728E5A" "8AAAC42D" "AD33170D" "04507A33" "A85521AB" "DF1CBA64"
     "ECFB8504" "58DBEF0A" "8AEA7157" "5D060C7D" "B3970F85" "A6E1E4C7"
     "ABF5AE8C" "DB0933D7" "1E8C94E0" "4A25619D" "CEE3D226" "1AD2EE6B"
     "F12FFA06" "D98A0864" "D8760273" "3EC86A64" "521F2B18" "177B200C"
     "BBE11757" "7A615D6C" "770988C0" "BAD946E2" "08E24FA0" "74E5AB31"
     "43DB5BFC" "E0FD108E" "4B82D120" "A9210801" "1A723C12" "A787E6D7"
     "88719A10" "BDBA5B26" "99C32718" "6AF4E23C" "1A946834" "B6150BDA"
     "2583E9CA" "2AD44CE8" "DBBBC2DB" "04DE8EF9" "2E8EFC14" "1FBECAA6"
     "287C5947" "4E6BC05D" "99B2964F" "A090C3A2" "233BA186" "515BE7ED"
     "1F612970" "CEE2D7AF" "B81BDD76" "2170481C" "D0069127" "D5B05AA9"
     "93B4EA98" "8D8FDDC1" "86FFB7DC" "90A6C08F" "4DF435C9" "34028492"
     "36C3FAB4" "D27C7026" "C1D4DCB2" "602646DE" "C9751E76" "3DBA37BD"
     "F8FF9406" "AD9E530E" "E5DB382F" "413001AE" "B06A53ED" "9027D831"
     "179727B0" "865A8918" "DA3EDBEB" "CF9B14ED" "44CE6CBA" "CED4BB1B"
     "DB7F1447" "E6CC254B" "33205151" "2BD7AF42" "6FB8F401" "378CD2BF"
     "5983CA01" "C64B92EC" "F032EA15" "D1721D03" "F482D7CE" "6E74FEF6"
     "D55E702F" "46980C82" "B5A84031" "900B1C9E" "59E7C97F" "BEC7E8F3"
     "23A97A7E" "36CC88BE" "0F1D45B7" "FF585AC5" "4BD407B2" "2B4154AA"
     "CC8F6D7E" "BF48E1D8" "14CC5ED2" "0F8037E0" "A79715EE" "F29BE328"
     "06A1D58B" "B7C5DA76" "F550AA3D" "8A1FBFF0" "EB19CCB1" "A313D55C"
     "DA56C9EC" "2EF29632" "387FE8D7" "6E3C0468" "043E8F66" "3F4860EE"
     "12BF2D5B" "0B7474D6" "E694F91E" "6DBE1159" "74A3926F" "12FEE5E4"
     "38777CB6" "A932DF8C" "D8BEC4D0" "73B931BA" "3BC832B6" "8D9DD300"
     "741FA7BF" "8AFC47ED" "2576F693" "6BA42466" "3AAB639C" "5AE4F568"
     "3423B474" "2BF1C978" "238F16CB" "E39D652D" "E3FDB8BE" "FC848AD9"
     "22222E04" "A4037C07" "13EB57A8" "1A23F0C7" "3473FC64" "6CEA306B"
     "4BCBC886" "2F8385DD" "FA9D4B7F" "A2C087E8" "79683303" "ED5BDD3A"
     "062B3CF5" "B3A278A6" "6D2A13F8" "3F44F82D" "DF310EE0" "74AB6A36"
     "4597E899" "A0255DC1" "64F31CC5" "0846851D" "F9AB4819" "5DED7EA1"
     "B1D510BD" "7EE74D73" "FAF36BC3" "1ECFA268" "359046F4" "EB879F92"
     "4009438B" "481C6CD7" "889A002E" "D5EE382B" "C9190DA6" "FC026E47"
     "9558E447" "5677E9AA" "9E3050E2" "765694DF" "C81F56E8" "80B96E71"
     "60C980DD" "98EDD3DF" "FFFFFFFF" "FFFFFFFF";

 return (dh_new_group_asc(gen, group18));
}


DH *
dh_new_group_fallback(int max)
{
 sshlog("dh.c", __func__, 474, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "requested max size %d", max);
 if (max < 3072) {
  sshlog("dh.c", __func__, 476, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "using 2k bit group 14");
  return dh_new_group14();
 } else if (max < 6144) {
  sshlog("dh.c", __func__, 479, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "using 4k bit group 16");
  return dh_new_group16();
 }
 sshlog("dh.c", __func__, 482, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "using 8k bit group 18");
 return dh_new_group18();
}
u_int
dh_estimate(int bits)
{
 if (bits <= 112)
  return 2048;
 if (bits <= 128)
  return 3072;
 if (bits <= 192)
  return 7680;
 return 8192;
}
