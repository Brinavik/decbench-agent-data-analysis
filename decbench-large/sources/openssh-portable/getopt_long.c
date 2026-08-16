











































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

int BSDopterr = 1;
int BSDoptind = 1;
int BSDoptopt = '?';
int BSDoptreset;
char *BSDoptarg;
static int getopt_internal(int, char * const *, const char *,
      const struct option *, int *, int);
static int parse_long_options(char * const *, const char *,
         const struct option *, int *, int);
static int gcd(int, int);
static void permute_args(int, int, int, char * const *);

static char *place = "";


static int nonopt_start = -1;
static int nonopt_end = -1;


static const char recargchar[] = "option requires an argument -- %c";
static const char recargstring[] = "option requires an argument -- %s";
static const char ambig[] = "ambiguous option -- %.*s";
static const char noarg[] = "option doesn't take an argument -- %.*s";
static const char illoptchar[] = "unknown option -- %c";
static const char illoptstring[] = "unknown option -- %s";




static int
gcd(int a, int b)
{
 int c;

 c = a % b;
 while (c != 0) {
  a = b;
  b = c;
  c = a % b;
 }

 return (b);
}






static void
permute_args(int panonopt_start, int panonopt_end, int opt_end,
 char * const *nargv)
{
 int cstart, cyclelen, i, j, ncycle, nnonopts, nopts, pos;
 char *swap;




 nnonopts = panonopt_end - panonopt_start;
 nopts = opt_end - panonopt_end;
 ncycle = gcd(nnonopts, nopts);
 cyclelen = (opt_end - panonopt_start) / ncycle;

 for (i = 0; i < ncycle; i++) {
  cstart = panonopt_end+i;
  pos = cstart;
  for (j = 0; j < cyclelen; j++) {
   if (pos >= panonopt_end)
    pos -= nnonopts;
   else
    pos += nopts;
   swap = nargv[pos];

   ((char **) nargv)[pos] = nargv[cstart];

   ((char **)nargv)[cstart] = swap;
  }
 }
}






static int
parse_long_options(char * const *nargv, const char *options,
 const struct option *long_options, int *idx, int short_too)
{
 char *current_argv, *has_equal;
 size_t current_argv_len;
 int i, match;

 current_argv = place;
 match = -1;

 BSDoptind++;

 if ((has_equal = strchr(current_argv, '=')) != 
                                               ((void *)0)
                                                   ) {

  current_argv_len = has_equal - current_argv;
  has_equal++;
 } else
  current_argv_len = strlen(current_argv);

 for (i = 0; long_options[i].name; i++) {

  if (strncmp(current_argv, long_options[i].name,
      current_argv_len))
   continue;

  if (strlen(long_options[i].name) == current_argv_len) {

   match = i;
   break;
  }




  if (short_too && current_argv_len == 1)
   continue;

  if (match == -1)
   match = i;
  else {

   if (((BSDopterr) && (*options != ':')))
    sshlog("getopt_long.c", __func__, 218, 0, SYSLOG_LEVEL_INFO, 
   ((void *)0)
   , ambig, (int)current_argv_len, current_argv)
                      ;
   BSDoptopt = 0;
   return ((int)'?');
  }
 }
 if (match != -1) {
  if (long_options[match].has_arg == 0
      && has_equal) {
   if (((BSDopterr) && (*options != ':')))
    sshlog("getopt_long.c", __func__, 228, 0, SYSLOG_LEVEL_INFO, 
   ((void *)0)
   , noarg, (int)current_argv_len, current_argv)
                      ;



   if (long_options[match].flag == 
                                  ((void *)0)
                                      )
    BSDoptopt = long_options[match].val;
   else
    BSDoptopt = 0;
   return (((*options == ':') ? (int)':' : (int)'?'));
  }
  if (long_options[match].has_arg == 1 ||
      long_options[match].has_arg == 2) {
   if (has_equal)
    BSDoptarg = has_equal;
   else if (long_options[match].has_arg ==
       1) {



    BSDoptarg = nargv[BSDoptind++];
   }
  }
  if ((long_options[match].has_arg == 1)
      && (BSDoptarg == 
                   ((void *)0)
                       )) {




   if (((BSDopterr) && (*options != ':')))
    sshlog("getopt_long.c", __func__, 258, 0, SYSLOG_LEVEL_INFO, 
   ((void *)0)
   , recargstring, current_argv)
                     ;



   if (long_options[match].flag == 
                                  ((void *)0)
                                      )
    BSDoptopt = long_options[match].val;
   else
    BSDoptopt = 0;
   --BSDoptind;
   return (((*options == ':') ? (int)':' : (int)'?'));
  }
 } else {
  if (short_too) {
   --BSDoptind;
   return (-1);
  }
  if (((BSDopterr) && (*options != ':')))
   sshlog("getopt_long.c", __func__, 276, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , illoptstring, current_argv);
  BSDoptopt = 0;
  return ((int)'?');
 }
 if (idx)
  *idx = match;
 if (long_options[match].flag) {
  *long_options[match].flag = long_options[match].val;
  return (0);
 } else
  return (long_options[match].val);
}





static int
getopt_internal(int nargc, char * const *nargv, const char *options,
 const struct option *long_options, int *idx, int flags)
{
 char *oli;
 int optchar, short_too;
 static int posixly_correct = -1;

 if (options == 
               ((void *)0)
                   )
  return (-1);





 if (BSDoptind == 0)
  BSDoptind = BSDoptreset = 1;





 if (posixly_correct == -1 || BSDoptreset)
  posixly_correct = (getenv("POSIXLY_CORRECT") != 
                                                 ((void *)0)
                                                     );
 if (*options == '-')
  flags |= 0x02;
 else if (posixly_correct || *options == '+')
  flags &= ~0x01;
 if (*options == '+' || *options == '-')
  options++;

 BSDoptarg = 
         ((void *)0)
             ;
 if (BSDoptreset)
  nonopt_start = nonopt_end = -1;
start:
 if (BSDoptreset || !*place) {
  BSDoptreset = 0;
  if (BSDoptind >= nargc) {
   place = "";
   if (nonopt_end != -1) {

    permute_args(nonopt_start, nonopt_end,
        BSDoptind, nargv);
    BSDoptind -= nonopt_end - nonopt_start;
   }
   else if (nonopt_start != -1) {




    BSDoptind = nonopt_start;
   }
   nonopt_start = nonopt_end = -1;
   return (-1);
  }
  if (*(place = nargv[BSDoptind]) != '-' ||
      (place[1] == '\0' && strchr(options, '-') == 
                                                  ((void *)0)
                                                      )) {
   place = "";
   if (flags & 0x02) {




    BSDoptarg = nargv[BSDoptind++];
    return ((int)1);
   }
   if (!(flags & 0x01)) {




    return (-1);
   }

   if (nonopt_start == -1)
    nonopt_start = BSDoptind;
   else if (nonopt_end != -1) {
    permute_args(nonopt_start, nonopt_end,
        BSDoptind, nargv);
    nonopt_start = BSDoptind -
        (nonopt_end - nonopt_start);
    nonopt_end = -1;
   }
   BSDoptind++;

   goto start;
  }
  if (nonopt_start != -1 && nonopt_end == -1)
   nonopt_end = BSDoptind;




  if (place[1] != '\0' && *++place == '-' && place[1] == '\0') {
   BSDoptind++;
   place = "";




   if (nonopt_end != -1) {
    permute_args(nonopt_start, nonopt_end,
        BSDoptind, nargv);
    BSDoptind -= nonopt_end - nonopt_start;
   }
   nonopt_start = nonopt_end = -1;
   return (-1);
  }
 }







 if (long_options != 
                    ((void *)0) 
                         && place != nargv[BSDoptind] &&
     (*place == '-' || (flags & 0x04))) {
  short_too = 0;
  if (*place == '-')
   place++;
  else if (*place != ':' && strchr(options, *place) != 
                                                      ((void *)0)
                                                          )
   short_too = 1;

  optchar = parse_long_options(nargv, options, long_options,
      idx, short_too);
  if (optchar != -1) {
   place = "";
   return (optchar);
  }
 }

 if ((optchar = (int)*place++) == (int)':' ||
     (optchar == (int)'-' && *place != '\0') ||
     (oli = strchr(options, optchar)) == 
                                        ((void *)0)
                                            ) {





  if (optchar == (int)'-' && *place == '\0')
   return (-1);
  if (!*place)
   ++BSDoptind;
  if (((BSDopterr) && (*options != ':')))
   sshlog("getopt_long.c", __func__, 438, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , illoptchar, optchar);
  BSDoptopt = optchar;
  return ((int)'?');
 }
 if (long_options != 
                    ((void *)0) 
                         && optchar == 'W' && oli[1] == ';') {

  if (*place)
                ;
  else if (++BSDoptind >= nargc) {
   place = "";
   if (((BSDopterr) && (*options != ':')))
    sshlog("getopt_long.c", __func__, 449, 0, SYSLOG_LEVEL_INFO, 
   ((void *)0)
   , recargchar, optchar);
   BSDoptopt = optchar;
   return (((*options == ':') ? (int)':' : (int)'?'));
  } else
   place = nargv[BSDoptind];
  optchar = parse_long_options(nargv, options, long_options,
      idx, 0);
  place = "";
  return (optchar);
 }
 if (*++oli != ':') {
  if (!*place)
   ++BSDoptind;
 } else {
  BSDoptarg = 
          ((void *)0)
              ;
  if (*place)
   BSDoptarg = place;
  else if (oli[1] != ':') {
   if (++BSDoptind >= nargc) {
    place = "";
    if (((BSDopterr) && (*options != ':')))
     sshlog("getopt_long.c", __func__, 470, 0, SYSLOG_LEVEL_INFO, 
    ((void *)0)
    , recargchar, optchar);
    BSDoptopt = optchar;
    return (((*options == ':') ? (int)':' : (int)'?'));
   } else
    BSDoptarg = nargv[BSDoptind];
  }
  place = "";
  ++BSDoptind;
 }

 return (optchar);
}







int
BSDgetopt(int nargc, char * const *nargv, const char *options)
{
 return (getopt_internal(nargc, nargv, options, 
                                               ((void *)0)
                                                   , 
                                                     ((void *)0)
                                                         , 0));
}
