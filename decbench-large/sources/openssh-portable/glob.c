











































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
struct stat;
typedef struct {
 size_t gl_pathc;
 size_t gl_matchc;
 size_t gl_offs;
 int gl_flags;
 char **gl_pathv;
 struct stat **gl_statv;

 int (*gl_errfunc)(const char *, int);






 void (*gl_closedir)(void *);
 struct dirent *(*gl_readdir)(void *);
 void *(*gl_opendir)(const char *);
 int (*gl_lstat)(const char *, struct stat *);
 int (*gl_stat)(const char *, struct stat *);
} _ssh_compat_glob_t;
int _ssh__compat_glob(const char *, int, int (*)(const char *, int), _ssh_compat_glob_t *);
void _ssh__compat_globfree(_ssh_compat_glob_t *);

















static struct cclass {
 const char *name;
 int (*isctype)(int);
} cclasses[] = {
 { "alnum", isalnum },
 { "alpha", isalpha },
 { "blank", isblank },
 { "cntrl", iscntrl },
 { "digit", isdigit },
 { "graph", isgraph },
 { "lower", islower },
 { "print", isprint },
 { "punct", ispunct },
 { "space", isspace },
 { "upper", isupper },
 { "xdigit", isxdigit },
 { 
  ((void *)0)
      , 
         ((void *)0) 
              }
};
typedef u_short Char;
struct glob_lim {
 size_t glim_malloc;
 size_t glim_stat;
 size_t glim_readdir;
};

struct glob_path_stat {
 char *gps_path;
 struct stat *gps_stat;
};

static int compare(const void *, const void *);
static int compare_gps(const void *, const void *);
static int g_Ctoc(const Char *, char *, size_t);
static int g_lstat(Char *, struct stat *, _ssh_compat_glob_t *);
static DIR *g_opendir(Char *, _ssh_compat_glob_t *);
static Char *g_strchr(const Char *, int);
static int g_strncmp(const Char *, const char *, size_t);
static int g_stat(Char *, struct stat *, _ssh_compat_glob_t *);
static int glob0(const Char *, _ssh_compat_glob_t *, struct glob_lim *);
static int glob1(Char *, Char *, _ssh_compat_glob_t *, struct glob_lim *);
static int glob2(Char *, Char *, Char *, Char *, Char *, Char *,
      _ssh_compat_glob_t *, struct glob_lim *);
static int glob3(Char *, Char *, Char *, Char *, Char *,
      Char *, Char *, _ssh_compat_glob_t *, struct glob_lim *);
static int globextend(const Char *, _ssh_compat_glob_t *, struct glob_lim *,
      struct stat *);
static const Char *
   globtilde(const Char *, Char *, size_t, _ssh_compat_glob_t *);
static int globexp1(const Char *, _ssh_compat_glob_t *, struct glob_lim *);
static int globexp2(const Char *, const Char *, _ssh_compat_glob_t *,
      struct glob_lim *);
static int match(Char *, Char *, Char *);




int
_ssh__compat_glob(const char *pattern, int flags, int (*errfunc)(const char *, int), _ssh_compat_glob_t *pglob)

{
 const u_char *patnext;
 int c;
 Char *bufnext, *bufend, patbuf[
                               4096
                                       ];
 struct glob_lim limit = { 0, 0, 0 };

 patnext = (u_char *) pattern;
 if (!(flags & 0x0001)) {
  pglob->gl_pathc = 0;
  pglob->gl_pathv = 
                   ((void *)0)
                       ;
  pglob->gl_statv = 
                   ((void *)0)
                       ;
  if (!(flags & 0x0002))
   pglob->gl_offs = 0;
 }
 pglob->gl_flags = flags & ~0x0100;
 pglob->gl_errfunc = errfunc;
 pglob->gl_matchc = 0;

 if (strnlen(pattern, 
                     4096
                             ) == 
                                  4096
                                          )
  return((-3));

 if (pglob->gl_offs >= 0x7fffffffffffffffL || pglob->gl_pathc >= 0x7fffffffffffffffL ||
     pglob->gl_pathc >= 0x7fffffffffffffffL - pglob->gl_offs - 1)
  return (-1);

 bufnext = patbuf;
 bufend = bufnext + 
                   4096 
                            - 1;
 if (flags & 0x1000)
  while (bufnext < bufend && (c = *patnext++) != '\0')
   *bufnext++ = c;
 else {

  while (bufnext < bufend && (c = *patnext++) != '\0')
   if (c == '\\') {
    if ((c = *patnext++) == '\0') {
     c = '\\';
     --patnext;
    }
    *bufnext++ = c | 0x4000;
   } else
    *bufnext++ = c;
 }
 *bufnext = '\0';

 if (flags & 0x0080)
  return globexp1(patbuf, pglob, &limit);
 else
  return glob0(patbuf, pglob, &limit);
}






static int
globexp1(const Char *pattern, _ssh_compat_glob_t *pglob, struct glob_lim *limitp)
{
 const Char* ptr = pattern;


 if (pattern[0] == '{' && pattern[1] == '}' && pattern[2] == '\0')
  return glob0(pattern, pglob, limitp);

 if ((ptr = (const Char *) g_strchr(ptr, '{')) != 
                                                    ((void *)0)
                                                        )
  return globexp2(ptr, pattern, pglob, limitp);

 return glob0(pattern, pglob, limitp);
}







static int
globexp2(const Char *ptr, const Char *pattern, _ssh_compat_glob_t *pglob,
    struct glob_lim *limitp)
{
 int i, rv;
 Char *lm, *ls;
 const Char *pe, *pm, *pl;
 Char patbuf[
               4096
                       ];


 for (lm = patbuf, pm = pattern; pm != ptr; *lm++ = *pm++)
  ;
 *lm = '\0';
 ls = lm;


 for (i = 0, pe = ++ptr; *pe; pe++)
  if (*pe == '[') {

   for (pm = pe++; *pe != ']' && *pe != '\0'; pe++)
    ;
   if (*pe == '\0') {




    pe = pm;
   }
  } else if (*pe == '{')
   i++;
  else if (*pe == '}') {
   if (i == 0)
    break;
   i--;
  }


 if (i != 0 || *pe == '\0')
  return glob0(patbuf, pglob, limitp);

 for (i = 0, pl = pm = ptr; pm <= pe; pm++) {
  switch (*pm) {
  case '[':

   for (pl = pm++; *pm != ']' && *pm != '\0'; pm++)
    ;
   if (*pm == '\0') {




    pm = pl;
   }
   break;

  case '{':
   i++;
   break;

  case '}':
   if (i) {
    i--;
    break;
   }

  case ',':
   if (i && *pm == ',')
    break;
   else {

    for (lm = ls; (pl < pm); *lm++ = *pl++)
     ;





    for (pl = pe + 1; (*lm++ = *pl++) != '\0'; )
     ;





    rv = globexp1(patbuf, pglob, limitp);
    if (rv && rv != (-3))
     return rv;


    pl = pm + 1;
   }
   break;

  default:
   break;
  }
 }
 return 0;
}






static const Char *
globtilde(const Char *pattern, Char *patbuf, size_t patbuf_len, _ssh_compat_glob_t *pglob)
{
 struct passwd *pwd;
 char *h;
 const Char *p;
 Char *b, *eb;

 if (*pattern != '~' || !(pglob->gl_flags & 0x0800))
  return pattern;


 eb = &patbuf[patbuf_len - 1];
 for (p = pattern + 1, h = (char *) patbuf;
     h < (char *)eb && *p && *p != '/'; *h++ = *p++)
  ;

 *h = '\0';






 if (((char *) patbuf)[0] == '\0') {







  if ((getuid() != geteuid()) || (h = getenv("HOME")) == 
                                                        ((void *)0)
                                                            ) {
   if ((pwd = getpwuid(getuid())) == 
                                    ((void *)0)
                                        )
    return pattern;
   else
    h = pwd->pw_dir;
  }
 } else {



  if ((pwd = getpwnam((char*) patbuf)) == 
                                         ((void *)0)
                                             )
   return pattern;
  else
   h = pwd->pw_dir;
 }


 for (b = patbuf; b < eb && *h; *b++ = *h++)
  ;


 while (b < eb && (*b++ = *p++) != '\0')
  ;
 *b = '\0';

 return patbuf;
}

static int
g_strncmp(const Char *s1, const char *s2, size_t n)
{
 int rv = 0;

 while (n--) {
  rv = *(Char *)s1 - *(const unsigned char *)s2++;
  if (rv)
   break;
  if (*s1++ == '\0')
   break;
 }
 return rv;
}

static int
g_charclass(const Char **patternp, Char **bufnextp)
{
 const Char *pattern = *patternp + 1;
 Char *bufnext = *bufnextp;
 const Char *colon;
 struct cclass *cc;
 size_t len;

 if ((colon = g_strchr(pattern, ':')) == 
                                        ((void *)0) 
                                             || colon[1] != ']')
  return 1;

 len = (size_t)(colon - pattern);
 for (cc = cclasses; cc->name != 
                                ((void *)0)
                                    ; cc++) {
  if (!g_strncmp(pattern, cc->name, len) && cc->name[len] == '\0')
   break;
 }
 if (cc->name == 
                ((void *)0)
                    )
  return -1;
 *bufnext++ = ((Char)((':')|0x8000));
 *bufnext++ = (Char)(cc - &cclasses[0]);
 *bufnextp = bufnext;
 *patternp += len + 3;

 return 0;
}
static int
glob0(const Char *pattern, _ssh_compat_glob_t *pglob, struct glob_lim *limitp)
{
 const Char *qpatnext;
 int c, err;
 size_t oldpathc;
 Char *bufnext, patbuf[
                      4096
                              ];

 qpatnext = globtilde(pattern, patbuf, 
                                      4096
                                              , pglob);
 oldpathc = pglob->gl_pathc;
 bufnext = patbuf;


 while ((c = *qpatnext++) != '\0') {
  switch (c) {
  case '[':
   c = *qpatnext;
   if (c == '!')
    ++qpatnext;
   if (*qpatnext == '\0' ||
       g_strchr(qpatnext+1, ']') == 
                                        ((void *)0)
                                            ) {
    *bufnext++ = '[';
    if (c == '!')
     --qpatnext;
    break;
   }
   *bufnext++ = ((Char)(('[')|0x8000));
   if (c == '!')
    *bufnext++ = ((Char)(('!')|0x8000));
   c = *qpatnext++;
   do {
    if (c == '[' && *qpatnext == ':') {
     do {
      err = g_charclass(&qpatnext,
          &bufnext);
      if (err)
       break;
      c = *qpatnext++;
     } while (c == '[' && *qpatnext == ':');
     if (err == -1 &&
         !(pglob->gl_flags & 0x0010))
      return (-3);
     if (c == ']')
      break;
    }
    *bufnext++ = ((Char)((c)&0x00ff));
    if (*qpatnext == '-' &&
        (c = qpatnext[1]) != ']') {
     *bufnext++ = ((Char)(('-')|0x8000));
     *bufnext++ = ((Char)((c)&0x00ff));
     qpatnext += 2;
    }
   } while ((c = *qpatnext++) != ']');
   pglob->gl_flags |= 0x0100;
   *bufnext++ = ((Char)((']')|0x8000));
   break;
  case '?':
   pglob->gl_flags |= 0x0100;
   *bufnext++ = ((Char)(('?')|0x8000));
   break;
  case '*':
   pglob->gl_flags |= 0x0100;



   if (bufnext == patbuf || bufnext[-1] != ((Char)(('*')|0x8000)))
    *bufnext++ = ((Char)(('*')|0x8000));
   break;
  default:
   *bufnext++ = ((Char)((c)&0x00ff));
   break;
  }
 }
 *bufnext = '\0';




 if ((err = glob1(patbuf, patbuf+
                                4096
                                        -1, pglob, limitp)) != 0)
  return(err);







 if (pglob->gl_pathc == oldpathc) {
  if ((pglob->gl_flags & 0x0010) ||
      ((pglob->gl_flags & 0x0200) &&
      !(pglob->gl_flags & 0x0100)))
   return(globextend(pattern, pglob, limitp, 
                                            ((void *)0)
                                                ));
  else
   return((-3));
 }
 if (!(pglob->gl_flags & 0x0020)) {
  if ((pglob->gl_flags & 0x4000)) {

   struct glob_path_stat *path_stat;
   size_t i;
   size_t n = pglob->gl_pathc - oldpathc;
   size_t o = pglob->gl_offs + oldpathc;

   if ((path_stat = calloc(n, sizeof(*path_stat))) == 
                                                     ((void *)0)
                                                         )
    return (-1);
   for (i = 0; i < n; i++) {
    path_stat[i].gps_path = pglob->gl_pathv[o + i];
    path_stat[i].gps_stat = pglob->gl_statv[o + i];
   }
   qsort(path_stat, n, sizeof(*path_stat), compare_gps);
   for (i = 0; i < n; i++) {
    pglob->gl_pathv[o + i] = path_stat[i].gps_path;
    pglob->gl_statv[o + i] = path_stat[i].gps_stat;
   }
   free(path_stat);
  } else {
   qsort(pglob->gl_pathv + pglob->gl_offs + oldpathc,
       pglob->gl_pathc - oldpathc, sizeof(char *),
       compare);
  }
 }
 return(0);
}

static int
compare(const void *p, const void *q)
{
 return(strcmp(*(char **)p, *(char **)q));
}

static int
compare_gps(const void *_p, const void *_q)
{
 const struct glob_path_stat *p = (const struct glob_path_stat *)_p;
 const struct glob_path_stat *q = (const struct glob_path_stat *)_q;

 return(strcmp(p->gps_path, q->gps_path));
}

static int
glob1(Char *pattern, Char *pattern_last, _ssh_compat_glob_t *pglob, struct glob_lim *limitp)
{
 Char pathbuf[
             4096
                     ];


 if (*pattern == '\0')
  return(0);
 return(glob2(pathbuf, pathbuf+
                              4096
                                      -1,
     pathbuf, pathbuf+
                     4096
                             -1,
     pattern, pattern_last, pglob, limitp));
}






static int
glob2(Char *pathbuf, Char *pathbuf_last, Char *pathend, Char *pathend_last,
    Char *pattern, Char *pattern_last, _ssh_compat_glob_t *pglob, struct glob_lim *limitp)
{
 struct stat sb;
 Char *p, *q;
 int anymeta;





 for (anymeta = 0;;) {
  if (*pattern == '\0') {
   *pathend = '\0';

   if ((pglob->gl_flags & 0x2000) &&
       limitp->glim_stat++ >= 2048) {
    
   (*__errno_location ()) 
         = 0;
    *pathend++ = '/';
    *pathend = '\0';
    return((-1));
   }
   if (g_lstat(pathbuf, &sb, pglob))
    return(0);

   if (((pglob->gl_flags & 0x0008) &&
       pathend[-1] != '/') && (
                              ((((
                              sb.st_mode
                              )) & 0170000) == (0040000)) 
                                                  ||
       (
       ((((
       sb.st_mode
       )) & 0170000) == (0120000)) 
                           &&
       (g_stat(pathbuf, &sb, pglob) == 0) &&
       
      ((((
      sb.st_mode
      )) & 0170000) == (0040000))
                         ))) {
    if (pathend+1 > pathend_last)
     return (1);
    *pathend++ = '/';
    *pathend = '\0';
   }
   ++pglob->gl_matchc;
   return(globextend(pathbuf, pglob, limitp, &sb));
  }


  q = pathend;
  p = pattern;
  while (*p != '\0' && *p != '/') {
   if ((((*p)&0x8000) != 0))
    anymeta = 1;
   if (q+1 > pathend_last)
    return (1);
   *q++ = *p++;
  }

  if (!anymeta) {
   pathend = q;
   pattern = p;
   while (*pattern == '/') {
    if (pathend+1 > pathend_last)
     return (1);
    *pathend++ = *pattern++;
   }
  } else

   return(glob3(pathbuf, pathbuf_last, pathend,
       pathend_last, pattern, p, pattern_last,
       pglob, limitp));
 }

}

static int
glob3(Char *pathbuf, Char *pathbuf_last, Char *pathend, Char *pathend_last,
    Char *pattern, Char *restpattern, Char *restpattern_last, _ssh_compat_glob_t *pglob,
    struct glob_lim *limitp)
{
 struct dirent *dp;
 DIR *dirp;
 int err;
 char buf[
         4096
                 ];







 struct dirent *(*readdirfunc)(void *);

 if (pathend > pathend_last)
  return (1);
 *pathend = '\0';
 
(*__errno_location ()) 
      = 0;

 if ((dirp = g_opendir(pathbuf, pglob)) == 
                                          ((void *)0)
                                              ) {

  if (pglob->gl_errfunc) {
   if (g_Ctoc(pathbuf, buf, sizeof(buf)))
    return((-2));
   if (pglob->gl_errfunc(buf, 
                             (*__errno_location ())
                                  ) ||
       pglob->gl_flags & 0x0004)
    return((-2));
  }
  return(0);
 }

 err = 0;


 if (pglob->gl_flags & 0x0040)
  readdirfunc = pglob->gl_readdir;
 else
  readdirfunc = (struct dirent *(*)(void *))readdir;
 while ((dp = (*readdirfunc)(dirp))) {
  u_char *sc;
  Char *dc;

  if ((pglob->gl_flags & 0x2000) &&
      limitp->glim_readdir++ >= 16384) {
   
  (*__errno_location ()) 
        = 0;
   *pathend++ = '/';
   *pathend = '\0';
   err = (-1);
   break;
  }


  if (dp->d_name[0] == '.' && *pattern != '.')
   continue;
  dc = pathend;
  sc = (u_char *) dp->d_name;
  while (dc < pathend_last && (*dc++ = *sc++) != '\0')
   ;
  if (dc >= pathend_last) {
   *dc = '\0';
   err = 1;
   break;
  }

  if (!match(pathend, pattern, restpattern)) {
   *pathend = '\0';
   continue;
  }
  err = glob2(pathbuf, pathbuf_last, --dc, pathend_last,
      restpattern, restpattern_last, pglob, limitp);
  if (err)
   break;
 }

 if (pglob->gl_flags & 0x0040)
  (*pglob->gl_closedir)(dirp);
 else
  closedir(dirp);
 return(err);
}
static int
globextend(const Char *path, _ssh_compat_glob_t *pglob, struct glob_lim *limitp,
    struct stat *sb)
{
 char **pathv;
 size_t i, newn, len;
 char *copy = 
             ((void *)0)
                 ;
 const Char *p;
 struct stat **statv;

 newn = 2 + pglob->gl_pathc + pglob->gl_offs;
 if (pglob->gl_offs >= 0x7fffffffffffffffL ||
     pglob->gl_pathc >= 0x7fffffffffffffffL ||
     newn >= 0x7fffffffffffffffL ||
     
    (18446744073709551615UL) 
             / sizeof(*pathv) <= newn ||
     
    (18446744073709551615UL) 
             / sizeof(*statv) <= newn) {
 nospace:
  for (i = pglob->gl_offs; i < newn - 2; i++) {
   if (pglob->gl_pathv && pglob->gl_pathv[i])
    free(pglob->gl_pathv[i]);
   if ((pglob->gl_flags & 0x4000) != 0 &&
       pglob->gl_pathv && pglob->gl_pathv[i])
    free(pglob->gl_statv[i]);
  }
  free(pglob->gl_pathv);
  pglob->gl_pathv = 
                   ((void *)0)
                       ;
  free(pglob->gl_statv);
  pglob->gl_statv = 
                   ((void *)0)
                       ;
  return((-1));
 }

 pathv = reallocarray(pglob->gl_pathv, newn, sizeof(*pathv));
 if (pathv == 
             ((void *)0)
                 )
  goto nospace;
 if (pglob->gl_pathv == 
                       ((void *)0) 
                            && pglob->gl_offs > 0) {

  pathv += pglob->gl_offs;
  for (i = pglob->gl_offs; i > 0; i--)
   *--pathv = 
             ((void *)0)
                 ;
 }
 pglob->gl_pathv = pathv;

 if ((pglob->gl_flags & 0x4000) != 0) {
  statv = reallocarray(pglob->gl_statv, newn, sizeof(*statv));
  if (statv == 
              ((void *)0)
                  )
   goto nospace;
  if (pglob->gl_statv == 
                        ((void *)0) 
                             && pglob->gl_offs > 0) {

   statv += pglob->gl_offs;
   for (i = pglob->gl_offs; i > 0; i--)
    *--statv = 
              ((void *)0)
                  ;
  }
  pglob->gl_statv = statv;
  if (sb == 
           ((void *)0)
               )
   statv[pglob->gl_offs + pglob->gl_pathc] = 
                                            ((void *)0)
                                                ;
  else {
   limitp->glim_malloc += sizeof(**statv);
   if ((pglob->gl_flags & 0x2000) &&
       limitp->glim_malloc >= 65536) {
    
   (*__errno_location ()) 
         = 0;
    return((-1));
   }
   if ((statv[pglob->gl_offs + pglob->gl_pathc] =
       malloc(sizeof(**statv))) == 
                                  ((void *)0)
                                      )
    goto copy_error;
   memcpy(statv[pglob->gl_offs + pglob->gl_pathc], sb,
       sizeof(*sb));
  }
  statv[pglob->gl_offs + pglob->gl_pathc + 1] = 
                                               ((void *)0)
                                                   ;
 }

 for (p = path; *p++;)
  ;
 len = (size_t)(p - path);
 limitp->glim_malloc += len;
 if ((copy = malloc(len)) != 
                            ((void *)0)
                                ) {
  if (g_Ctoc(path, copy, len)) {
   free(copy);
   return((-1));
  }
  pathv[pglob->gl_offs + pglob->gl_pathc++] = copy;
 }
 pathv[pglob->gl_offs + pglob->gl_pathc] = 
                                          ((void *)0)
                                              ;

 if ((pglob->gl_flags & 0x2000) &&
     (newn * sizeof(*pathv)) + limitp->glim_malloc >
     65536) {
  
 (*__errno_location ()) 
       = 0;
  return((-1));
 }
 copy_error:
 return(copy == 
               ((void *)0) 
                    ? (-1) : 0);
}
static int
match(Char *name, Char *pat, Char *patend)
{
 int ok, negate_range;
 Char c, k;
 Char *nextp = 
              ((void *)0)
                  ;
 Char *nextn = 
              ((void *)0)
                  ;

loop:
 while (pat < patend) {
  c = *pat++;
  switch (c & 0xffff) {
  case ((Char)(('*')|0x8000)):
   while (pat < patend && (*pat & 0xffff) == ((Char)(('*')|0x8000)))
    pat++;
   if (pat == patend)
    return(1);
   if (*name == '\0')
    return(0);
   nextn = name + 1;
   nextp = pat - 1;
   break;
  case ((Char)(('?')|0x8000)):
   if (*name++ == '\0')
    goto fail;
   break;
  case ((Char)(('[')|0x8000)):
   ok = 0;
   if ((k = *name++) == '\0')
    goto fail;
   if ((negate_range = ((*pat & 0xffff) == ((Char)(('!')|0x8000)))) != '\0')
    ++pat;
   while (((c = *pat++) & 0xffff) != ((Char)((']')|0x8000))) {
    if ((c & 0xffff) == ((Char)((':')|0x8000))) {
     Char idx = *pat & 0xffff;
     if (idx < (sizeof(cclasses) / sizeof(cclasses[0]) - 1) &&
         cclasses[idx].isctype(k))
      ok = 1;
     ++pat;
    }
    if ((*pat & 0xffff) == ((Char)(('-')|0x8000))) {
     if (c <= k && k <= pat[1])
      ok = 1;
     pat += 2;
    } else if (c == k)
     ok = 1;
   }
   if (ok == negate_range)
    goto fail;
   break;
  default:
   if (*name++ != c)
    goto fail;
   break;
  }
 }
 if (*name == '\0')
  return(1);

fail:
 if (nextn) {
  pat = nextp;
  name = nextn;
  goto loop;
 }
 return(0);
}


void
_ssh__compat_globfree(_ssh_compat_glob_t *pglob)
{
 size_t i;
 char **pp;

 if (pglob->gl_pathv != 
                       ((void *)0)
                           ) {
  pp = pglob->gl_pathv + pglob->gl_offs;
  for (i = pglob->gl_pathc; i--; ++pp)
   free(*pp);
  free(pglob->gl_pathv);
  pglob->gl_pathv = 
                   ((void *)0)
                       ;
 }
 if (pglob->gl_statv != 
                       ((void *)0)
                           ) {
  for (i = 0; i < pglob->gl_pathc; i++) {
   free(pglob->gl_statv[i]);
  }
  free(pglob->gl_statv);
  pglob->gl_statv = 
                   ((void *)0)
                       ;
 }
}

static DIR *
g_opendir(Char *str, _ssh_compat_glob_t *pglob)
{
 char buf[
         4096
                 ];

 if (!*str)
  strlcpy(buf, ".", sizeof buf);
 else {
  if (g_Ctoc(str, buf, sizeof(buf)))
   return(
         ((void *)0)
             );
 }

 if (pglob->gl_flags & 0x0040)
  return((*pglob->gl_opendir)(buf));

 return(opendir(buf));
}

static int
g_lstat(Char *fn, struct stat *sb, _ssh_compat_glob_t *pglob)
{
 char buf[
         4096
                 ];

 if (g_Ctoc(fn, buf, sizeof(buf)))
  return(-1);
 if (pglob->gl_flags & 0x0040)
  return((*pglob->gl_lstat)(buf, sb));
 return(lstat(buf, sb));
}

static int
g_stat(Char *fn, struct stat *sb, _ssh_compat_glob_t *pglob)
{
 char buf[
         4096
                 ];

 if (g_Ctoc(fn, buf, sizeof(buf)))
  return(-1);
 if (pglob->gl_flags & 0x0040)
  return((*pglob->gl_stat)(buf, sb));
 return(stat(buf, sb));
}

static Char *
g_strchr(const Char *str, int ch)
{
 do {
  if (*str == ch)
   return ((Char *)str);
 } while (*str++);
 return (
        ((void *)0)
            );
}

static int
g_Ctoc(const Char *str, char *buf, size_t len)
{

 while (len--) {
  if ((*buf++ = *str++) == '\0')
   return (0);
 }
 return (1);
}
