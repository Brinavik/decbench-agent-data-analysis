











































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
match_pattern(const char *s, const char *pattern)
{
 for (;;) {

  if (!*pattern)
   return !*s;

  if (*pattern == '*') {

   while (*pattern == '*')
    pattern++;


   if (!*pattern)
    return 1;


   if (*pattern != '?' && *pattern != '*') {





    for (; *s; s++)
     if (*s == *pattern &&
         match_pattern(s + 1, pattern + 1))
      return 1;

    return 0;
   }




   for (; *s; s++)
    if (match_pattern(s, pattern))
     return 1;

   return 0;
  }




  if (!*s)
   return 0;


  if (*pattern != '?' && *pattern != *s)
   return 0;


  s++;
  pattern++;
 }

}







int
match_pattern_list(const char *string, const char *pattern, int dolower)
{
 char sub[1024];
 int negated;
 int got_positive;
 u_int i, subi, len = strlen(pattern);

 got_positive = 0;
 for (i = 0; i < len;) {

  if (pattern[i] == '!') {
   negated = 1;
   i++;
  } else
   negated = 0;





  for (subi = 0;
      i < len && subi < sizeof(sub) - 1 && pattern[i] != ',';
      subi++, i++)
   sub[subi] = dolower && 
                         ((*__ctype_b_loc ())[(int) ((
                         (u_char)pattern[i]
                         ))] & (unsigned short int) _ISupper) 
                                                     ?
       tolower((u_char)pattern[i]) : pattern[i];

  if (subi >= sizeof(sub) - 1)
   return 0;


  if (i < len && pattern[i] == ',')
   i++;


  sub[subi] = '\0';


  if (match_pattern(string, sub)) {
   if (negated)
    return -1;
   else
    got_positive = 1;
  }
 }





 return got_positive;
}


int
match_usergroup_pattern_list(const char *string, const char *pattern)
{





 return match_pattern_list(string, pattern, 0);

}







int
match_hostname(const char *host, const char *pattern)
{
 char *hostcopy = xstrdup(host);
 int r;

 lowercase(hostcopy);
 r = match_pattern_list(hostcopy, pattern, 1);
 free(hostcopy);
 return r;
}






int
match_host_and_ip(const char *host, const char *ipaddr,
    const char *patterns)
{
 int mhost, mip;

 if ((mip = addr_match_list(ipaddr, patterns)) == -2)
  return -1;
 else if (host == 
                 ((void *)0) 
                      || ipaddr == 
                                   ((void *)0) 
                                        || mip == -1)
  return 0;


 if ((mhost = match_hostname(host, patterns)) == -1)
  return 0;

 if (mhost == 0 && mip == 0)
  return 0;
 return 1;
}






int
match_user(const char *user, const char *host, const char *ipaddr,
    const char *pattern)
{
 char *p, *pat;
 int ret;


 if (user == 
            ((void *)0) 
                 && host == 
                            ((void *)0) 
                                 && ipaddr == 
                                              ((void *)0)
                                                  ) {
  if ((p = strchr(pattern, '@')) != 
                                   ((void *)0) 
                                        &&
      match_host_and_ip(
                       ((void *)0)
                           , 
                             ((void *)0)
                                 , p + 1) < 0)
   return -1;
  return 0;
 }

 if ((p = strchr(pattern, '@')) == 
                                  ((void *)0)
                                      )
  return match_pattern(user, pattern);

 pat = xstrdup(pattern);
 p = strchr(pat, '@');
 *p++ = '\0';

 if ((ret = match_pattern(user, pat)) == 1)
  ret = match_host_and_ip(host, ipaddr, p);
 free(pat);

 return ret;
}







char *
match_list(const char *client, const char *server, u_int *next)
{
 char *sproposals[40];
 char *c, *s, *p, *ret, *cp, *sp;
 int i, j, nproposals;

 c = cp = xstrdup(client);
 s = sp = xstrdup(server);

 for ((p = strsep(&sp, ",")), i=0; p && *p != '\0';
     (p = strsep(&sp, ",")), i++) {
  if (i < 40)
   sproposals[i] = p;
  else
   break;
 }
 nproposals = i;

 for ((p = strsep(&cp, ",")), i=0; p && *p != '\0';
     (p = strsep(&cp, ",")), i++) {
  for (j = 0; j < nproposals; j++) {
   if (strcmp(p, sproposals[j]) == 0) {
    ret = xstrdup(p);
    if (next != 
               ((void *)0)
                   )
     *next = (cp == 
                   ((void *)0)
                       ) ?
         strlen(c) : (u_int)(cp - c);
    free(c);
    free(s);
    return ret;
   }
  }
 }
 if (next != 
            ((void *)0)
                )
  *next = strlen(c);
 free(c);
 free(s);
 return 
       ((void *)0)
           ;
}
static char *
filter_list(const char *proposal, const char *filter, int denylist)
{
 size_t len = strlen(proposal) + 1;
 char *fix_prop = malloc(len);
 char *orig_prop = strdup(proposal);
 char *cp, *tmp;
 int r;

 if (fix_prop == 
                ((void *)0) 
                     || orig_prop == 
                                     ((void *)0)
                                         ) {
  free(orig_prop);
  free(fix_prop);
  return 
        ((void *)0)
            ;
 }

 tmp = orig_prop;
 *fix_prop = '\0';
 while ((cp = strsep(&tmp, ",")) != 
                                   ((void *)0)
                                       ) {
  r = match_pattern_list(cp, filter, 0);
  if ((denylist && r != 1) || (!denylist && r == 1)) {
   if (*fix_prop != '\0')
    strlcat(fix_prop, ",", len);
   strlcat(fix_prop, cp, len);
  }
 }
 free(orig_prop);
 return fix_prop;
}





char *
match_filter_denylist(const char *proposal, const char *filter)
{
 return filter_list(proposal, filter, 1);
}





char *
match_filter_allowlist(const char *proposal, const char *filter)
{
 return filter_list(proposal, filter, 0);
}
