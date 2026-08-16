











































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




size_t
atomicio6(ssize_t (*f) (int, void *, size_t), int fd, void *_s, size_t n,
    int (*cb)(void *, size_t), void *cb_arg)
{
 char *s = _s;
 size_t pos = 0;
 ssize_t res;
 struct pollfd pfd;

 pfd.fd = fd;

 pfd.events = f == read ? 
                         0x001 
                                : 
                                  0x004
                                         ;



 while (n > pos) {
  res = (f) (fd, s + pos, n - pos);
  switch (res) {
  case -1:
   if (
      (*__errno_location ()) 
            == 
               4
                    ) {

    if (cb != 
             ((void *)0) 
                  && cb(cb_arg, 0) == -1) {
     
    (*__errno_location ()) 
          = 
            4
                 ;
     return pos;
    }
    continue;
   } else if (
             (*__errno_location ()) 
                   == 
                      11 
                             || 
                                (*__errno_location ()) 
                                      == 
                                         11
                                                    ) {
    (void)poll(&pfd, 1, -1);
    continue;
   }
   return 0;
  case 0:
   
  (*__errno_location ()) 
        = 
          32
               ;
   return pos;
  default:
   pos += (size_t)res;
   if (cb != 
            ((void *)0) 
                 && cb(cb_arg, (size_t)res) == -1) {
    
   (*__errno_location ()) 
         = 
           4
                ;
    return pos;
   }
  }
 }
 return pos;
}

size_t
atomicio(ssize_t (*f) (int, void *, size_t), int fd, void *_s, size_t n)
{
 return atomicio6(f, fd, _s, n, 
                               ((void *)0)
                                   , 
                                     ((void *)0)
                                         );
}




size_t
atomiciov6(ssize_t (*f) (int, const struct iovec *, int), int fd,
    const struct iovec *_iov, int iovcnt,
    int (*cb)(void *, size_t), void *cb_arg)
{
 size_t pos = 0, rem;
 ssize_t res;
 struct iovec iov_array[
                       1024
                              ], *iov = iov_array;
 struct pollfd pfd;

 if (iovcnt < 0 || iovcnt > 
                           1024
                                  ) {
  
 (*__errno_location ()) 
       = 
         22
               ;
  return 0;
 }

 memcpy(iov, _iov, (size_t)iovcnt * sizeof(*_iov));

 pfd.fd = fd;

 pfd.events = f == readv ? 
                          0x001 
                                 : 
                                   0x004
                                          ;



 for (; iovcnt > 0 && iov[0].iov_len > 0;) {
  res = (f) (fd, iov, iovcnt);
  switch (res) {
  case -1:
   if (
      (*__errno_location ()) 
            == 
               4
                    ) {

    if (cb != 
             ((void *)0) 
                  && cb(cb_arg, 0) == -1) {
     
    (*__errno_location ()) 
          = 
            4
                 ;
     return pos;
    }
    continue;
   } else if (
             (*__errno_location ()) 
                   == 
                      11 
                             || 
                                (*__errno_location ()) 
                                      == 
                                         11
                                                    ) {
    (void)poll(&pfd, 1, -1);
    continue;
   }
   return 0;
  case 0:
   
  (*__errno_location ()) 
        = 
          32
               ;
   return pos;
  default:
   rem = (size_t)res;
   pos += rem;

   while (iovcnt > 0 && rem >= iov[0].iov_len) {
    rem -= iov[0].iov_len;
    iov++;
    iovcnt--;
   }

   if (rem > 0 && (iovcnt <= 0 || rem > iov[0].iov_len)) {
    
   (*__errno_location ()) 
         = 
           14
                 ;
    return 0;
   }
   if (iovcnt == 0)
    break;

   iov[0].iov_base = ((char *)iov[0].iov_base) + rem;
   iov[0].iov_len -= rem;
  }
  if (cb != 
           ((void *)0) 
                && cb(cb_arg, (size_t)res) == -1) {
   
  (*__errno_location ()) 
        = 
          4
               ;
   return pos;
  }
 }
 return pos;
}

size_t
atomiciov(ssize_t (*f) (int, const struct iovec *, int), int fd,
    const struct iovec *_iov, int iovcnt)
{
 return atomiciov6(f, fd, _iov, iovcnt, 
                                       ((void *)0)
                                           , 
                                             ((void *)0)
                                                 );
}
