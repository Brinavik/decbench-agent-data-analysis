











































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







static volatile sig_atomic_t signo[
                                  (64 + 1)
                                       ];

static void handler(int);

char *
readpassphrase(const char *prompt, char *buf, size_t bufsiz, int flags)
{
 ssize_t nr;
 int input, output, save_errno, i, need_restart;
 char ch, *p, *end;
 struct termios term, oterm;
 struct sigaction sa, savealrm, saveint, savehup, savequit, saveterm;
 struct sigaction savetstp, savettin, savettou, savepipe;


 if (bufsiz == 0) {
  
 (*__errno_location ()) 
       = 
         22
               ;
  return(
        ((void *)0)
            );
 }

restart:
 for (i = 0; i < 
                (64 + 1)
                     ; i++)
  signo[i] = 0;
 nr = -1;
 save_errno = 0;
 need_restart = 0;




 if ((flags & 0x20) ||
     (input = output = open(
                           "/dev/tty"
                                    , 
                                      02
                                            )) == -1) {
  if (flags & 0x02) {
   
  (*__errno_location ()) 
        = 
          25
                ;
   return(
         ((void *)0)
             );
  }
  input = 
         0
                     ;
  output = 
          2
                       ;
 }






 if (input != 
             0 
                          && tcgetattr(input, &oterm) == 0) {
  memcpy(&term, &oterm, sizeof(term));
  if (!(flags & 0x01))
   term.c_lflag &= ~(
                    0000010 
                         | 
                           0000100
                                 );




  (void)tcsetattr(input, 
                        2
                                 |0, &term);
 } else {
  memset(&term, 0, sizeof(term));
  term.c_lflag |= 
                 0000010
                     ;
  memset(&oterm, 0, sizeof(oterm));
  oterm.c_lflag |= 
                  0000010
                      ;
 }






 sigemptyset(&sa.sa_mask);
 sa.sa_flags = 0;
 sa.
   __sigaction_handler.sa_handler 
              = handler;
 (void)sigaction(
                14
                       , &sa, &savealrm);
 (void)sigaction(
                1
                      , &sa, &savehup);
 (void)sigaction(
                2
                      , &sa, &saveint);
 (void)sigaction(
                13
                       , &sa, &savepipe);
 (void)sigaction(
                3
                       , &sa, &savequit);
 (void)sigaction(
                15
                       , &sa, &saveterm);
 (void)sigaction(
                20
                       , &sa, &savetstp);
 (void)sigaction(
                21
                       , &sa, &savettin);
 (void)sigaction(
                22
                       , &sa, &savettou);

 if (!(flags & 0x20))
  (void)write(output, prompt, strlen(prompt));
 end = buf + bufsiz - 1;
 p = buf;
 while ((nr = read(input, &ch, 1)) == 1 && ch != '\n' && ch != '\r') {
  if (p < end) {
   if ((flags & 0x10))
    ch &= 0x7f;
   if (
      ((*__ctype_b_loc ())[(int) ((
      (unsigned char)ch
      ))] & (unsigned short int) _ISalpha)
                                ) {
    if ((flags & 0x04))
     ch = (char)tolower((unsigned char)ch);
    if ((flags & 0x08))
     ch = (char)toupper((unsigned char)ch);
   }
   *p++ = ch;
  }
 }
 *p = '\0';
 save_errno = 
             (*__errno_location ())
                  ;
 if (!(term.c_lflag & 
                     0000010
                         ))
  (void)write(output, "\n", 1);


 if (memcmp(&term, &oterm, sizeof(term)) != 0) {
  const int sigttou = signo[
                           22
                                  ];


  while (tcsetattr(input, 
                         2
                                  |0, &oterm) == -1 &&
      
     (*__errno_location ()) 
           == 
              4 
                    && !signo[
                              22
                                     ])
   continue;
  signo[
       22
              ] = sigttou;
 }
 (void)sigaction(
                14
                       , &savealrm, 
                                    ((void *)0)
                                        );
 (void)sigaction(
                1
                      , &savehup, 
                                  ((void *)0)
                                      );
 (void)sigaction(
                2
                      , &saveint, 
                                  ((void *)0)
                                      );
 (void)sigaction(
                3
                       , &savequit, 
                                    ((void *)0)
                                        );
 (void)sigaction(
                13
                       , &savepipe, 
                                    ((void *)0)
                                        );
 (void)sigaction(
                15
                       , &saveterm, 
                                    ((void *)0)
                                        );
 (void)sigaction(
                20
                       , &savetstp, 
                                    ((void *)0)
                                        );
 (void)sigaction(
                21
                       , &savettin, 
                                    ((void *)0)
                                        );
 (void)sigaction(
                22
                       , &savettou, 
                                    ((void *)0)
                                        );
 if (input != 
             0
                         )
  (void)close(input);





 for (i = 0; i < 
                (64 + 1)
                     ; i++) {
  if (signo[i]) {
   kill(getpid(), i);
   switch (i) {
   case 
       20
              :
   case 
       21
              :
   case 
       22
              :
    need_restart = 1;
   }
  }
 }
 if (need_restart)
  goto restart;

 if (save_errno)
  
 (*__errno_location ()) 
       = save_errno;
 return(nr == -1 ? 
                  ((void *)0) 
                       : buf);
}
void __ssh_compat_weak_readpassphrase(void);
static void handler(int s)
{

 signo[s] = 1;
}
