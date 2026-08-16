











































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












static const char Base64[] =
 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static const char Pad64 = '=';
int

__b64_ntop
(u_char const *src,size_t srclength,char *target,size_t targsize)
{
 size_t datalength = 0;
 u_char input[3];
 u_char output[4];
 u_int i;

 while (2 < srclength) {
  input[0] = *src++;
  input[1] = *src++;
  input[2] = *src++;
  srclength -= 3;

  output[0] = input[0] >> 2;
  output[1] = ((input[0] & 0x03) << 4) + (input[1] >> 4);
  output[2] = ((input[1] & 0x0f) << 2) + (input[2] >> 6);
  output[3] = input[2] & 0x3f;

  if (datalength + 4 > targsize)
   return (-1);
  target[datalength++] = Base64[output[0]];
  target[datalength++] = Base64[output[1]];
  target[datalength++] = Base64[output[2]];
  target[datalength++] = Base64[output[3]];
 }


 if (0 != srclength) {

  input[0] = input[1] = input[2] = '\0';
  for (i = 0; i < srclength; i++)
   input[i] = *src++;

  output[0] = input[0] >> 2;
  output[1] = ((input[0] & 0x03) << 4) + (input[1] >> 4);
  output[2] = ((input[1] & 0x0f) << 2) + (input[2] >> 6);

  if (datalength + 4 > targsize)
   return (-1);
  target[datalength++] = Base64[output[0]];
  target[datalength++] = Base64[output[1]];
  if (srclength == 1)
   target[datalength++] = Pad64;
  else
   target[datalength++] = Base64[output[2]];
  target[datalength++] = Pad64;
 }
 if (datalength >= targsize)
  return (-1);
 target[datalength] = '\0';
 return (datalength);
}
int

__b64_pton
(char const *src,u_char *target,size_t targsize)
{
 u_int tarindex, state;
 int ch;
 char *pos;

 state = 0;
 tarindex = 0;

 while ((ch = *src++) != '\0') {
  if (
     ((*__ctype_b_loc ())[(int) ((
     ch
     ))] & (unsigned short int) _ISspace)
                )
   continue;

  if (ch == Pad64)
   break;

  pos = strchr(Base64, ch);
  if (pos == 0)
   return (-1);

  switch (state) {
  case 0:
   if (target) {
    if (tarindex >= targsize)
     return (-1);
    target[tarindex] = (pos - Base64) << 2;
   }
   state = 1;
   break;
  case 1:
   if (target) {
    if (tarindex + 1 >= targsize)
     return (-1);
    target[tarindex] |= (pos - Base64) >> 4;
    target[tarindex+1] = ((pos - Base64) & 0x0f)
       << 4 ;
   }
   tarindex++;
   state = 2;
   break;
  case 2:
   if (target) {
    if (tarindex + 1 >= targsize)
     return (-1);
    target[tarindex] |= (pos - Base64) >> 2;
    target[tarindex+1] = ((pos - Base64) & 0x03)
       << 6;
   }
   tarindex++;
   state = 3;
   break;
  case 3:
   if (target) {
    if (tarindex >= targsize)
     return (-1);
    target[tarindex] |= (pos - Base64);
   }
   tarindex++;
   state = 0;
   break;
  }
 }






 if (ch == Pad64) {
  ch = *src++;
  switch (state) {
  case 0:
  case 1:
   return (-1);

  case 2:

   for (; ch != '\0'; ch = *src++)
    if (!
        ((*__ctype_b_loc ())[(int) ((
        ch
        ))] & (unsigned short int) _ISspace)
                   )
     break;

   if (ch != Pad64)
    return (-1);
   ch = *src++;



  case 3:




   for (; ch != '\0'; ch = *src++)
    if (!
        ((*__ctype_b_loc ())[(int) ((
        ch
        ))] & (unsigned short int) _ISspace)
                   )
     return (-1);







   if (target && target[tarindex] != 0)
    return (-1);
  }
 } else {




  if (state != 0)
   return (-1);
 }

 return (tarindex);
}
