


















































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






void poly1305_auth(u_char out[16], const u_char *m, size_t inlen,
    const u_char key[32])
    __attribute__(())
    __attribute__(())
    __attribute__(());
void
poly1305_auth(unsigned char out[16], const unsigned char *m, size_t inlen, const unsigned char key[32]) {
 uint32_t t0,t1,t2,t3;
 uint32_t h0,h1,h2,h3,h4;
 uint32_t r0,r1,r2,r3,r4;
 uint32_t s1,s2,s3,s4;
 uint32_t b, nb;
 size_t j;
 uint64_t t[5];
 uint64_t f0,f1,f2,f3;
 uint32_t g0,g1,g2,g3,g4;
 uint64_t c;
 unsigned char mp[16];


 t0 = (((uint32_t)((key+0)[0])) | ((uint32_t)((key+0)[1]) << 8) | ((uint32_t)((key+0)[2]) << 16) | ((uint32_t)((key+0)[3]) << 24));
 t1 = (((uint32_t)((key+4)[0])) | ((uint32_t)((key+4)[1]) << 8) | ((uint32_t)((key+4)[2]) << 16) | ((uint32_t)((key+4)[3]) << 24));
 t2 = (((uint32_t)((key+8)[0])) | ((uint32_t)((key+8)[1]) << 8) | ((uint32_t)((key+8)[2]) << 16) | ((uint32_t)((key+8)[3]) << 24));
 t3 = (((uint32_t)((key+12)[0])) | ((uint32_t)((key+12)[1]) << 8) | ((uint32_t)((key+12)[2]) << 16) | ((uint32_t)((key+12)[3]) << 24));


 r0 = t0 & 0x3ffffff; t0 >>= 26; t0 |= t1 << 6;
 r1 = t0 & 0x3ffff03; t1 >>= 20; t1 |= t2 << 12;
 r2 = t1 & 0x3ffc0ff; t2 >>= 14; t2 |= t3 << 18;
 r3 = t2 & 0x3f03fff; t3 >>= 8;
 r4 = t3 & 0x00fffff;

 s1 = r1 * 5;
 s2 = r2 * 5;
 s3 = r3 * 5;
 s4 = r4 * 5;


 h0 = 0;
 h1 = 0;
 h2 = 0;
 h3 = 0;
 h4 = 0;


 if (inlen < 16) goto poly1305_donna_atmost15bytes;
poly1305_donna_16bytes:
 m += 16;
 inlen -= 16;

 t0 = (((uint32_t)((m-16)[0])) | ((uint32_t)((m-16)[1]) << 8) | ((uint32_t)((m-16)[2]) << 16) | ((uint32_t)((m-16)[3]) << 24));
 t1 = (((uint32_t)((m-12)[0])) | ((uint32_t)((m-12)[1]) << 8) | ((uint32_t)((m-12)[2]) << 16) | ((uint32_t)((m-12)[3]) << 24));
 t2 = (((uint32_t)((m-8)[0])) | ((uint32_t)((m-8)[1]) << 8) | ((uint32_t)((m-8)[2]) << 16) | ((uint32_t)((m-8)[3]) << 24));
 t3 = (((uint32_t)((m-4)[0])) | ((uint32_t)((m-4)[1]) << 8) | ((uint32_t)((m-4)[2]) << 16) | ((uint32_t)((m-4)[3]) << 24));

 h0 += t0 & 0x3ffffff;
 h1 += ((((uint64_t)t1 << 32) | t0) >> 26) & 0x3ffffff;
 h2 += ((((uint64_t)t2 << 32) | t1) >> 20) & 0x3ffffff;
 h3 += ((((uint64_t)t3 << 32) | t2) >> 14) & 0x3ffffff;
 h4 += (t3 >> 8) | (1 << 24);


poly1305_donna_mul:
 t[0] = ((uint64_t)(h0) * (r0)) + ((uint64_t)(h1) * (s4)) + ((uint64_t)(h2) * (s3)) + ((uint64_t)(h3) * (s2)) + ((uint64_t)(h4) * (s1));
 t[1] = ((uint64_t)(h0) * (r1)) + ((uint64_t)(h1) * (r0)) + ((uint64_t)(h2) * (s4)) + ((uint64_t)(h3) * (s3)) + ((uint64_t)(h4) * (s2));
 t[2] = ((uint64_t)(h0) * (r2)) + ((uint64_t)(h1) * (r1)) + ((uint64_t)(h2) * (r0)) + ((uint64_t)(h3) * (s4)) + ((uint64_t)(h4) * (s3));
 t[3] = ((uint64_t)(h0) * (r3)) + ((uint64_t)(h1) * (r2)) + ((uint64_t)(h2) * (r1)) + ((uint64_t)(h3) * (r0)) + ((uint64_t)(h4) * (s4));
 t[4] = ((uint64_t)(h0) * (r4)) + ((uint64_t)(h1) * (r3)) + ((uint64_t)(h2) * (r2)) + ((uint64_t)(h3) * (r1)) + ((uint64_t)(h4) * (r0));

                 h0 = (uint32_t)t[0] & 0x3ffffff; c = (t[0] >> 26);
 t[1] += c; h1 = (uint32_t)t[1] & 0x3ffffff; b = (uint32_t)(t[1] >> 26);
 t[2] += b; h2 = (uint32_t)t[2] & 0x3ffffff; b = (uint32_t)(t[2] >> 26);
 t[3] += b; h3 = (uint32_t)t[3] & 0x3ffffff; b = (uint32_t)(t[3] >> 26);
 t[4] += b; h4 = (uint32_t)t[4] & 0x3ffffff; b = (uint32_t)(t[4] >> 26);
 h0 += b * 5;

 if (inlen >= 16) goto poly1305_donna_16bytes;


poly1305_donna_atmost15bytes:
 if (!inlen) goto poly1305_donna_finish;

 for (j = 0; j < inlen; j++) mp[j] = m[j];
 mp[j++] = 1;
 for (; j < 16; j++) mp[j] = 0;
 inlen = 0;

 t0 = (((uint32_t)((mp+0)[0])) | ((uint32_t)((mp+0)[1]) << 8) | ((uint32_t)((mp+0)[2]) << 16) | ((uint32_t)((mp+0)[3]) << 24));
 t1 = (((uint32_t)((mp+4)[0])) | ((uint32_t)((mp+4)[1]) << 8) | ((uint32_t)((mp+4)[2]) << 16) | ((uint32_t)((mp+4)[3]) << 24));
 t2 = (((uint32_t)((mp+8)[0])) | ((uint32_t)((mp+8)[1]) << 8) | ((uint32_t)((mp+8)[2]) << 16) | ((uint32_t)((mp+8)[3]) << 24));
 t3 = (((uint32_t)((mp+12)[0])) | ((uint32_t)((mp+12)[1]) << 8) | ((uint32_t)((mp+12)[2]) << 16) | ((uint32_t)((mp+12)[3]) << 24));

 h0 += t0 & 0x3ffffff;
 h1 += ((((uint64_t)t1 << 32) | t0) >> 26) & 0x3ffffff;
 h2 += ((((uint64_t)t2 << 32) | t1) >> 20) & 0x3ffffff;
 h3 += ((((uint64_t)t3 << 32) | t2) >> 14) & 0x3ffffff;
 h4 += (t3 >> 8);

 goto poly1305_donna_mul;

poly1305_donna_finish:
              b = h0 >> 26; h0 = h0 & 0x3ffffff;
 h1 += b; b = h1 >> 26; h1 = h1 & 0x3ffffff;
 h2 += b; b = h2 >> 26; h2 = h2 & 0x3ffffff;
 h3 += b; b = h3 >> 26; h3 = h3 & 0x3ffffff;
 h4 += b; b = h4 >> 26; h4 = h4 & 0x3ffffff;
 h0 += b * 5; b = h0 >> 26; h0 = h0 & 0x3ffffff;
 h1 += b;

 g0 = h0 + 5; b = g0 >> 26; g0 &= 0x3ffffff;
 g1 = h1 + b; b = g1 >> 26; g1 &= 0x3ffffff;
 g2 = h2 + b; b = g2 >> 26; g2 &= 0x3ffffff;
 g3 = h3 + b; b = g3 >> 26; g3 &= 0x3ffffff;
 g4 = h4 + b - (1 << 26);

 b = (g4 >> 31) - 1;
 nb = ~b;
 h0 = (h0 & nb) | (g0 & b);
 h1 = (h1 & nb) | (g1 & b);
 h2 = (h2 & nb) | (g2 & b);
 h3 = (h3 & nb) | (g3 & b);
 h4 = (h4 & nb) | (g4 & b);

 f0 = ((h0 ) | (h1 << 26)) + (uint64_t)(((uint32_t)((&key[16])[0])) | ((uint32_t)((&key[16])[1]) << 8) | ((uint32_t)((&key[16])[2]) << 16) | ((uint32_t)((&key[16])[3]) << 24));
 f1 = ((h1 >> 6) | (h2 << 20)) + (uint64_t)(((uint32_t)((&key[20])[0])) | ((uint32_t)((&key[20])[1]) << 8) | ((uint32_t)((&key[20])[2]) << 16) | ((uint32_t)((&key[20])[3]) << 24));
 f2 = ((h2 >> 12) | (h3 << 14)) + (uint64_t)(((uint32_t)((&key[24])[0])) | ((uint32_t)((&key[24])[1]) << 8) | ((uint32_t)((&key[24])[2]) << 16) | ((uint32_t)((&key[24])[3]) << 24));
 f3 = ((h3 >> 18) | (h4 << 8)) + (uint64_t)(((uint32_t)((&key[28])[0])) | ((uint32_t)((&key[28])[1]) << 8) | ((uint32_t)((&key[28])[2]) << 16) | ((uint32_t)((&key[28])[3]) << 24));

 do { (&out[ 0])[0] = (uint8_t)((f0)); (&out[ 0])[1] = (uint8_t)((f0) >> 8); (&out[ 0])[2] = (uint8_t)((f0) >> 16); (&out[ 0])[3] = (uint8_t)((f0) >> 24); } while (0); f1 += (f0 >> 32);
 do { (&out[ 4])[0] = (uint8_t)((f1)); (&out[ 4])[1] = (uint8_t)((f1) >> 8); (&out[ 4])[2] = (uint8_t)((f1) >> 16); (&out[ 4])[3] = (uint8_t)((f1) >> 24); } while (0); f2 += (f1 >> 32);
 do { (&out[ 8])[0] = (uint8_t)((f2)); (&out[ 8])[1] = (uint8_t)((f2) >> 8); (&out[ 8])[2] = (uint8_t)((f2) >> 16); (&out[ 8])[3] = (uint8_t)((f2) >> 24); } while (0); f3 += (f2 >> 32);
 do { (&out[12])[0] = (uint8_t)((f3)); (&out[12])[1] = (uint8_t)((f3) >> 8); (&out[12])[2] = (uint8_t)((f3) >> 16); (&out[12])[3] = (uint8_t)((f3) >> 24); } while (0);
}
