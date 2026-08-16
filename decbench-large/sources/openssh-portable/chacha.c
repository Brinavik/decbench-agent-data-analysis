

















































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



struct chacha_ctx {
 u_int input[16];
};







void chacha_keysetup(struct chacha_ctx *x, const u_char *k, u_int kbits)
    __attribute__(());
void chacha_ivsetup(struct chacha_ctx *x, const u_char *iv, const u_char *ctr)
    __attribute__(())
    __attribute__(());
void chacha_encrypt_bytes(struct chacha_ctx *x, const u_char *m,
    u_char *c, u_int bytes)
    __attribute__(())
    __attribute__(());



typedef unsigned char u8;
typedef unsigned int u32;

typedef struct chacha_ctx chacha_ctx;
static const char sigma[16] = "expand 32-byte k";
static const char tau[16] = "expand 16-byte k";

void
chacha_keysetup(chacha_ctx *x,const u8 *k,u32 kbits)
{
  const char *constants;

  x->input[4] = (((u32)((k + 0)[0]) ) | ((u32)((k + 0)[1]) << 8) | ((u32)((k + 0)[2]) << 16) | ((u32)((k + 0)[3]) << 24));
  x->input[5] = (((u32)((k + 4)[0]) ) | ((u32)((k + 4)[1]) << 8) | ((u32)((k + 4)[2]) << 16) | ((u32)((k + 4)[3]) << 24));
  x->input[6] = (((u32)((k + 8)[0]) ) | ((u32)((k + 8)[1]) << 8) | ((u32)((k + 8)[2]) << 16) | ((u32)((k + 8)[3]) << 24));
  x->input[7] = (((u32)((k + 12)[0]) ) | ((u32)((k + 12)[1]) << 8) | ((u32)((k + 12)[2]) << 16) | ((u32)((k + 12)[3]) << 24));
  if (kbits == 256) {
    k += 16;
    constants = sigma;
  } else {
    constants = tau;
  }
  x->input[8] = (((u32)((k + 0)[0]) ) | ((u32)((k + 0)[1]) << 8) | ((u32)((k + 0)[2]) << 16) | ((u32)((k + 0)[3]) << 24));
  x->input[9] = (((u32)((k + 4)[0]) ) | ((u32)((k + 4)[1]) << 8) | ((u32)((k + 4)[2]) << 16) | ((u32)((k + 4)[3]) << 24));
  x->input[10] = (((u32)((k + 8)[0]) ) | ((u32)((k + 8)[1]) << 8) | ((u32)((k + 8)[2]) << 16) | ((u32)((k + 8)[3]) << 24));
  x->input[11] = (((u32)((k + 12)[0]) ) | ((u32)((k + 12)[1]) << 8) | ((u32)((k + 12)[2]) << 16) | ((u32)((k + 12)[3]) << 24));
  x->input[0] = (((u32)((constants + 0)[0]) ) | ((u32)((constants + 0)[1]) << 8) | ((u32)((constants + 0)[2]) << 16) | ((u32)((constants + 0)[3]) << 24));
  x->input[1] = (((u32)((constants + 4)[0]) ) | ((u32)((constants + 4)[1]) << 8) | ((u32)((constants + 4)[2]) << 16) | ((u32)((constants + 4)[3]) << 24));
  x->input[2] = (((u32)((constants + 8)[0]) ) | ((u32)((constants + 8)[1]) << 8) | ((u32)((constants + 8)[2]) << 16) | ((u32)((constants + 8)[3]) << 24));
  x->input[3] = (((u32)((constants + 12)[0]) ) | ((u32)((constants + 12)[1]) << 8) | ((u32)((constants + 12)[2]) << 16) | ((u32)((constants + 12)[3]) << 24));
}

void
chacha_ivsetup(chacha_ctx *x, const u8 *iv, const u8 *counter)
{
  x->input[12] = counter == 
                           ((void *)0) 
                                ? 0 : (((u32)((counter + 0)[0]) ) | ((u32)((counter + 0)[1]) << 8) | ((u32)((counter + 0)[2]) << 16) | ((u32)((counter + 0)[3]) << 24));
  x->input[13] = counter == 
                           ((void *)0) 
                                ? 0 : (((u32)((counter + 4)[0]) ) | ((u32)((counter + 4)[1]) << 8) | ((u32)((counter + 4)[2]) << 16) | ((u32)((counter + 4)[3]) << 24));
  x->input[14] = (((u32)((iv + 0)[0]) ) | ((u32)((iv + 0)[1]) << 8) | ((u32)((iv + 0)[2]) << 16) | ((u32)((iv + 0)[3]) << 24));
  x->input[15] = (((u32)((iv + 4)[0]) ) | ((u32)((iv + 4)[1]) << 8) | ((u32)((iv + 4)[2]) << 16) | ((u32)((iv + 4)[3]) << 24));
}

void
chacha_encrypt_bytes(chacha_ctx *x,const u8 *m,u8 *c,u32 bytes)
{
  u32 x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15;
  u32 j0, j1, j2, j3, j4, j5, j6, j7, j8, j9, j10, j11, j12, j13, j14, j15;
  u8 *ctarget = 
               ((void *)0)
                   ;
  u8 tmp[64];
  u_int i;

  if (!bytes) return;

  j0 = x->input[0];
  j1 = x->input[1];
  j2 = x->input[2];
  j3 = x->input[3];
  j4 = x->input[4];
  j5 = x->input[5];
  j6 = x->input[6];
  j7 = x->input[7];
  j8 = x->input[8];
  j9 = x->input[9];
  j10 = x->input[10];
  j11 = x->input[11];
  j12 = x->input[12];
  j13 = x->input[13];
  j14 = x->input[14];
  j15 = x->input[15];

  for (;;) {
    if (bytes < 64) {
      for (i = 0;i < bytes;++i) tmp[i] = m[i];
      m = tmp;
      ctarget = c;
      c = tmp;
    }
    x0 = j0;
    x1 = j1;
    x2 = j2;
    x3 = j3;
    x4 = j4;
    x5 = j5;
    x6 = j6;
    x7 = j7;
    x8 = j8;
    x9 = j9;
    x10 = j10;
    x11 = j11;
    x12 = j12;
    x13 = j13;
    x14 = j14;
    x15 = j15;
    for (i = 20;i > 0;i -= 2) {
      x0 = (((u32)((x0) + (x4)) & (0xFFFFFFFFU))); x12 = ((((u32)((((x12) ^ (x0))) << (16)) & (0xFFFFFFFFU)) | ((((x12) ^ (x0))) >> (32 - (16))))); x8 = (((u32)((x8) + (x12)) & (0xFFFFFFFFU))); x4 = ((((u32)((((x4) ^ (x8))) << (12)) & (0xFFFFFFFFU)) | ((((x4) ^ (x8))) >> (32 - (12))))); x0 = (((u32)((x0) + (x4)) & (0xFFFFFFFFU))); x12 = ((((u32)((((x12) ^ (x0))) << (8)) & (0xFFFFFFFFU)) | ((((x12) ^ (x0))) >> (32 - (8))))); x8 = (((u32)((x8) + (x12)) & (0xFFFFFFFFU))); x4 = ((((u32)((((x4) ^ (x8))) << (7)) & (0xFFFFFFFFU)) | ((((x4) ^ (x8))) >> (32 - (7)))));
      x1 = (((u32)((x1) + (x5)) & (0xFFFFFFFFU))); x13 = ((((u32)((((x13) ^ (x1))) << (16)) & (0xFFFFFFFFU)) | ((((x13) ^ (x1))) >> (32 - (16))))); x9 = (((u32)((x9) + (x13)) & (0xFFFFFFFFU))); x5 = ((((u32)((((x5) ^ (x9))) << (12)) & (0xFFFFFFFFU)) | ((((x5) ^ (x9))) >> (32 - (12))))); x1 = (((u32)((x1) + (x5)) & (0xFFFFFFFFU))); x13 = ((((u32)((((x13) ^ (x1))) << (8)) & (0xFFFFFFFFU)) | ((((x13) ^ (x1))) >> (32 - (8))))); x9 = (((u32)((x9) + (x13)) & (0xFFFFFFFFU))); x5 = ((((u32)((((x5) ^ (x9))) << (7)) & (0xFFFFFFFFU)) | ((((x5) ^ (x9))) >> (32 - (7)))));
      x2 = (((u32)((x2) + (x6)) & (0xFFFFFFFFU))); x14 = ((((u32)((((x14) ^ (x2))) << (16)) & (0xFFFFFFFFU)) | ((((x14) ^ (x2))) >> (32 - (16))))); x10 = (((u32)((x10) + (x14)) & (0xFFFFFFFFU))); x6 = ((((u32)((((x6) ^ (x10))) << (12)) & (0xFFFFFFFFU)) | ((((x6) ^ (x10))) >> (32 - (12))))); x2 = (((u32)((x2) + (x6)) & (0xFFFFFFFFU))); x14 = ((((u32)((((x14) ^ (x2))) << (8)) & (0xFFFFFFFFU)) | ((((x14) ^ (x2))) >> (32 - (8))))); x10 = (((u32)((x10) + (x14)) & (0xFFFFFFFFU))); x6 = ((((u32)((((x6) ^ (x10))) << (7)) & (0xFFFFFFFFU)) | ((((x6) ^ (x10))) >> (32 - (7)))));
      x3 = (((u32)((x3) + (x7)) & (0xFFFFFFFFU))); x15 = ((((u32)((((x15) ^ (x3))) << (16)) & (0xFFFFFFFFU)) | ((((x15) ^ (x3))) >> (32 - (16))))); x11 = (((u32)((x11) + (x15)) & (0xFFFFFFFFU))); x7 = ((((u32)((((x7) ^ (x11))) << (12)) & (0xFFFFFFFFU)) | ((((x7) ^ (x11))) >> (32 - (12))))); x3 = (((u32)((x3) + (x7)) & (0xFFFFFFFFU))); x15 = ((((u32)((((x15) ^ (x3))) << (8)) & (0xFFFFFFFFU)) | ((((x15) ^ (x3))) >> (32 - (8))))); x11 = (((u32)((x11) + (x15)) & (0xFFFFFFFFU))); x7 = ((((u32)((((x7) ^ (x11))) << (7)) & (0xFFFFFFFFU)) | ((((x7) ^ (x11))) >> (32 - (7)))));
      x0 = (((u32)((x0) + (x5)) & (0xFFFFFFFFU))); x15 = ((((u32)((((x15) ^ (x0))) << (16)) & (0xFFFFFFFFU)) | ((((x15) ^ (x0))) >> (32 - (16))))); x10 = (((u32)((x10) + (x15)) & (0xFFFFFFFFU))); x5 = ((((u32)((((x5) ^ (x10))) << (12)) & (0xFFFFFFFFU)) | ((((x5) ^ (x10))) >> (32 - (12))))); x0 = (((u32)((x0) + (x5)) & (0xFFFFFFFFU))); x15 = ((((u32)((((x15) ^ (x0))) << (8)) & (0xFFFFFFFFU)) | ((((x15) ^ (x0))) >> (32 - (8))))); x10 = (((u32)((x10) + (x15)) & (0xFFFFFFFFU))); x5 = ((((u32)((((x5) ^ (x10))) << (7)) & (0xFFFFFFFFU)) | ((((x5) ^ (x10))) >> (32 - (7)))));
      x1 = (((u32)((x1) + (x6)) & (0xFFFFFFFFU))); x12 = ((((u32)((((x12) ^ (x1))) << (16)) & (0xFFFFFFFFU)) | ((((x12) ^ (x1))) >> (32 - (16))))); x11 = (((u32)((x11) + (x12)) & (0xFFFFFFFFU))); x6 = ((((u32)((((x6) ^ (x11))) << (12)) & (0xFFFFFFFFU)) | ((((x6) ^ (x11))) >> (32 - (12))))); x1 = (((u32)((x1) + (x6)) & (0xFFFFFFFFU))); x12 = ((((u32)((((x12) ^ (x1))) << (8)) & (0xFFFFFFFFU)) | ((((x12) ^ (x1))) >> (32 - (8))))); x11 = (((u32)((x11) + (x12)) & (0xFFFFFFFFU))); x6 = ((((u32)((((x6) ^ (x11))) << (7)) & (0xFFFFFFFFU)) | ((((x6) ^ (x11))) >> (32 - (7)))));
      x2 = (((u32)((x2) + (x7)) & (0xFFFFFFFFU))); x13 = ((((u32)((((x13) ^ (x2))) << (16)) & (0xFFFFFFFFU)) | ((((x13) ^ (x2))) >> (32 - (16))))); x8 = (((u32)((x8) + (x13)) & (0xFFFFFFFFU))); x7 = ((((u32)((((x7) ^ (x8))) << (12)) & (0xFFFFFFFFU)) | ((((x7) ^ (x8))) >> (32 - (12))))); x2 = (((u32)((x2) + (x7)) & (0xFFFFFFFFU))); x13 = ((((u32)((((x13) ^ (x2))) << (8)) & (0xFFFFFFFFU)) | ((((x13) ^ (x2))) >> (32 - (8))))); x8 = (((u32)((x8) + (x13)) & (0xFFFFFFFFU))); x7 = ((((u32)((((x7) ^ (x8))) << (7)) & (0xFFFFFFFFU)) | ((((x7) ^ (x8))) >> (32 - (7)))));
      x3 = (((u32)((x3) + (x4)) & (0xFFFFFFFFU))); x14 = ((((u32)((((x14) ^ (x3))) << (16)) & (0xFFFFFFFFU)) | ((((x14) ^ (x3))) >> (32 - (16))))); x9 = (((u32)((x9) + (x14)) & (0xFFFFFFFFU))); x4 = ((((u32)((((x4) ^ (x9))) << (12)) & (0xFFFFFFFFU)) | ((((x4) ^ (x9))) >> (32 - (12))))); x3 = (((u32)((x3) + (x4)) & (0xFFFFFFFFU))); x14 = ((((u32)((((x14) ^ (x3))) << (8)) & (0xFFFFFFFFU)) | ((((x14) ^ (x3))) >> (32 - (8))))); x9 = (((u32)((x9) + (x14)) & (0xFFFFFFFFU))); x4 = ((((u32)((((x4) ^ (x9))) << (7)) & (0xFFFFFFFFU)) | ((((x4) ^ (x9))) >> (32 - (7)))));
    }
    x0 = (((u32)((x0) + (j0)) & (0xFFFFFFFFU)));
    x1 = (((u32)((x1) + (j1)) & (0xFFFFFFFFU)));
    x2 = (((u32)((x2) + (j2)) & (0xFFFFFFFFU)));
    x3 = (((u32)((x3) + (j3)) & (0xFFFFFFFFU)));
    x4 = (((u32)((x4) + (j4)) & (0xFFFFFFFFU)));
    x5 = (((u32)((x5) + (j5)) & (0xFFFFFFFFU)));
    x6 = (((u32)((x6) + (j6)) & (0xFFFFFFFFU)));
    x7 = (((u32)((x7) + (j7)) & (0xFFFFFFFFU)));
    x8 = (((u32)((x8) + (j8)) & (0xFFFFFFFFU)));
    x9 = (((u32)((x9) + (j9)) & (0xFFFFFFFFU)));
    x10 = (((u32)((x10) + (j10)) & (0xFFFFFFFFU)));
    x11 = (((u32)((x11) + (j11)) & (0xFFFFFFFFU)));
    x12 = (((u32)((x12) + (j12)) & (0xFFFFFFFFU)));
    x13 = (((u32)((x13) + (j13)) & (0xFFFFFFFFU)));
    x14 = (((u32)((x14) + (j14)) & (0xFFFFFFFFU)));
    x15 = (((u32)((x15) + (j15)) & (0xFFFFFFFFU)));

    x0 = ((x0) ^ ((((u32)((m + 0)[0]) ) | ((u32)((m + 0)[1]) << 8) | ((u32)((m + 0)[2]) << 16) | ((u32)((m + 0)[3]) << 24))));
    x1 = ((x1) ^ ((((u32)((m + 4)[0]) ) | ((u32)((m + 4)[1]) << 8) | ((u32)((m + 4)[2]) << 16) | ((u32)((m + 4)[3]) << 24))));
    x2 = ((x2) ^ ((((u32)((m + 8)[0]) ) | ((u32)((m + 8)[1]) << 8) | ((u32)((m + 8)[2]) << 16) | ((u32)((m + 8)[3]) << 24))));
    x3 = ((x3) ^ ((((u32)((m + 12)[0]) ) | ((u32)((m + 12)[1]) << 8) | ((u32)((m + 12)[2]) << 16) | ((u32)((m + 12)[3]) << 24))));
    x4 = ((x4) ^ ((((u32)((m + 16)[0]) ) | ((u32)((m + 16)[1]) << 8) | ((u32)((m + 16)[2]) << 16) | ((u32)((m + 16)[3]) << 24))));
    x5 = ((x5) ^ ((((u32)((m + 20)[0]) ) | ((u32)((m + 20)[1]) << 8) | ((u32)((m + 20)[2]) << 16) | ((u32)((m + 20)[3]) << 24))));
    x6 = ((x6) ^ ((((u32)((m + 24)[0]) ) | ((u32)((m + 24)[1]) << 8) | ((u32)((m + 24)[2]) << 16) | ((u32)((m + 24)[3]) << 24))));
    x7 = ((x7) ^ ((((u32)((m + 28)[0]) ) | ((u32)((m + 28)[1]) << 8) | ((u32)((m + 28)[2]) << 16) | ((u32)((m + 28)[3]) << 24))));
    x8 = ((x8) ^ ((((u32)((m + 32)[0]) ) | ((u32)((m + 32)[1]) << 8) | ((u32)((m + 32)[2]) << 16) | ((u32)((m + 32)[3]) << 24))));
    x9 = ((x9) ^ ((((u32)((m + 36)[0]) ) | ((u32)((m + 36)[1]) << 8) | ((u32)((m + 36)[2]) << 16) | ((u32)((m + 36)[3]) << 24))));
    x10 = ((x10) ^ ((((u32)((m + 40)[0]) ) | ((u32)((m + 40)[1]) << 8) | ((u32)((m + 40)[2]) << 16) | ((u32)((m + 40)[3]) << 24))));
    x11 = ((x11) ^ ((((u32)((m + 44)[0]) ) | ((u32)((m + 44)[1]) << 8) | ((u32)((m + 44)[2]) << 16) | ((u32)((m + 44)[3]) << 24))));
    x12 = ((x12) ^ ((((u32)((m + 48)[0]) ) | ((u32)((m + 48)[1]) << 8) | ((u32)((m + 48)[2]) << 16) | ((u32)((m + 48)[3]) << 24))));
    x13 = ((x13) ^ ((((u32)((m + 52)[0]) ) | ((u32)((m + 52)[1]) << 8) | ((u32)((m + 52)[2]) << 16) | ((u32)((m + 52)[3]) << 24))));
    x14 = ((x14) ^ ((((u32)((m + 56)[0]) ) | ((u32)((m + 56)[1]) << 8) | ((u32)((m + 56)[2]) << 16) | ((u32)((m + 56)[3]) << 24))));
    x15 = ((x15) ^ ((((u32)((m + 60)[0]) ) | ((u32)((m + 60)[1]) << 8) | ((u32)((m + 60)[2]) << 16) | ((u32)((m + 60)[3]) << 24))));

    j12 = ((((u32)(((j12)) + (1)) & (0xFFFFFFFFU))));
    if (!j12) {
      j13 = ((((u32)(((j13)) + (1)) & (0xFFFFFFFFU))));

    }

    do { (c + 0)[0] = ((u8)((x0)) & (0xFFU)); (c + 0)[1] = ((u8)((x0) >> 8) & (0xFFU)); (c + 0)[2] = ((u8)((x0) >> 16) & (0xFFU)); (c + 0)[3] = ((u8)((x0) >> 24) & (0xFFU)); } while (0);
    do { (c + 4)[0] = ((u8)((x1)) & (0xFFU)); (c + 4)[1] = ((u8)((x1) >> 8) & (0xFFU)); (c + 4)[2] = ((u8)((x1) >> 16) & (0xFFU)); (c + 4)[3] = ((u8)((x1) >> 24) & (0xFFU)); } while (0);
    do { (c + 8)[0] = ((u8)((x2)) & (0xFFU)); (c + 8)[1] = ((u8)((x2) >> 8) & (0xFFU)); (c + 8)[2] = ((u8)((x2) >> 16) & (0xFFU)); (c + 8)[3] = ((u8)((x2) >> 24) & (0xFFU)); } while (0);
    do { (c + 12)[0] = ((u8)((x3)) & (0xFFU)); (c + 12)[1] = ((u8)((x3) >> 8) & (0xFFU)); (c + 12)[2] = ((u8)((x3) >> 16) & (0xFFU)); (c + 12)[3] = ((u8)((x3) >> 24) & (0xFFU)); } while (0);
    do { (c + 16)[0] = ((u8)((x4)) & (0xFFU)); (c + 16)[1] = ((u8)((x4) >> 8) & (0xFFU)); (c + 16)[2] = ((u8)((x4) >> 16) & (0xFFU)); (c + 16)[3] = ((u8)((x4) >> 24) & (0xFFU)); } while (0);
    do { (c + 20)[0] = ((u8)((x5)) & (0xFFU)); (c + 20)[1] = ((u8)((x5) >> 8) & (0xFFU)); (c + 20)[2] = ((u8)((x5) >> 16) & (0xFFU)); (c + 20)[3] = ((u8)((x5) >> 24) & (0xFFU)); } while (0);
    do { (c + 24)[0] = ((u8)((x6)) & (0xFFU)); (c + 24)[1] = ((u8)((x6) >> 8) & (0xFFU)); (c + 24)[2] = ((u8)((x6) >> 16) & (0xFFU)); (c + 24)[3] = ((u8)((x6) >> 24) & (0xFFU)); } while (0);
    do { (c + 28)[0] = ((u8)((x7)) & (0xFFU)); (c + 28)[1] = ((u8)((x7) >> 8) & (0xFFU)); (c + 28)[2] = ((u8)((x7) >> 16) & (0xFFU)); (c + 28)[3] = ((u8)((x7) >> 24) & (0xFFU)); } while (0);
    do { (c + 32)[0] = ((u8)((x8)) & (0xFFU)); (c + 32)[1] = ((u8)((x8) >> 8) & (0xFFU)); (c + 32)[2] = ((u8)((x8) >> 16) & (0xFFU)); (c + 32)[3] = ((u8)((x8) >> 24) & (0xFFU)); } while (0);
    do { (c + 36)[0] = ((u8)((x9)) & (0xFFU)); (c + 36)[1] = ((u8)((x9) >> 8) & (0xFFU)); (c + 36)[2] = ((u8)((x9) >> 16) & (0xFFU)); (c + 36)[3] = ((u8)((x9) >> 24) & (0xFFU)); } while (0);
    do { (c + 40)[0] = ((u8)((x10)) & (0xFFU)); (c + 40)[1] = ((u8)((x10) >> 8) & (0xFFU)); (c + 40)[2] = ((u8)((x10) >> 16) & (0xFFU)); (c + 40)[3] = ((u8)((x10) >> 24) & (0xFFU)); } while (0);
    do { (c + 44)[0] = ((u8)((x11)) & (0xFFU)); (c + 44)[1] = ((u8)((x11) >> 8) & (0xFFU)); (c + 44)[2] = ((u8)((x11) >> 16) & (0xFFU)); (c + 44)[3] = ((u8)((x11) >> 24) & (0xFFU)); } while (0);
    do { (c + 48)[0] = ((u8)((x12)) & (0xFFU)); (c + 48)[1] = ((u8)((x12) >> 8) & (0xFFU)); (c + 48)[2] = ((u8)((x12) >> 16) & (0xFFU)); (c + 48)[3] = ((u8)((x12) >> 24) & (0xFFU)); } while (0);
    do { (c + 52)[0] = ((u8)((x13)) & (0xFFU)); (c + 52)[1] = ((u8)((x13) >> 8) & (0xFFU)); (c + 52)[2] = ((u8)((x13) >> 16) & (0xFFU)); (c + 52)[3] = ((u8)((x13) >> 24) & (0xFFU)); } while (0);
    do { (c + 56)[0] = ((u8)((x14)) & (0xFFU)); (c + 56)[1] = ((u8)((x14) >> 8) & (0xFFU)); (c + 56)[2] = ((u8)((x14) >> 16) & (0xFFU)); (c + 56)[3] = ((u8)((x14) >> 24) & (0xFFU)); } while (0);
    do { (c + 60)[0] = ((u8)((x15)) & (0xFFU)); (c + 60)[1] = ((u8)((x15) >> 8) & (0xFFU)); (c + 60)[2] = ((u8)((x15) >> 16) & (0xFFU)); (c + 60)[3] = ((u8)((x15) >> 24) & (0xFFU)); } while (0);

    if (bytes <= 64) {
      if (bytes < 64) {
        for (i = 0;i < bytes;++i) ctarget[i] = c[i];
      }
      x->input[12] = j12;
      x->input[13] = j13;
      return;
    }
    bytes -= 64;
    c += 64;
    m += 64;
  }
}
