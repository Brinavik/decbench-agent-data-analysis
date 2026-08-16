











































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






struct sshbuf;
struct ssh_digest_ctx;


int ssh_digest_alg_by_name(const char *name);


const char *ssh_digest_alg_name(int alg);


size_t ssh_digest_bytes(int alg);


size_t ssh_digest_blocksize(struct ssh_digest_ctx *ctx);


int ssh_digest_copy_state(struct ssh_digest_ctx *from,
    struct ssh_digest_ctx *to);


int ssh_digest_memory(int alg, const void *m, size_t mlen,
    u_char *d, size_t dlen)
 __attribute__(())
 __attribute__(());
int ssh_digest_buffer(int alg, const struct sshbuf *b, u_char *d, size_t dlen)
 __attribute__(());


struct ssh_digest_ctx *ssh_digest_start(int alg);
int ssh_digest_update(struct ssh_digest_ctx *ctx, const void *m, size_t mlen)
 __attribute__(());
int ssh_digest_update_buffer(struct ssh_digest_ctx *ctx,
    const struct sshbuf *b);
int ssh_digest_final(struct ssh_digest_ctx *ctx, u_char *d, size_t dlen)
 __attribute__(());
void ssh_digest_free(struct ssh_digest_ctx *ctx);
size_t ssh_hmac_bytes(int alg);

struct sshbuf;
struct ssh_hmac_ctx;
struct ssh_hmac_ctx *ssh_hmac_start(int alg);


int ssh_hmac_init(struct ssh_hmac_ctx *ctx, const void *key, size_t klen)
 __attribute__(());
int ssh_hmac_update(struct ssh_hmac_ctx *ctx, const void *m, size_t mlen)
 __attribute__(());
int ssh_hmac_update_buffer(struct ssh_hmac_ctx *ctx, const struct sshbuf *b);
int ssh_hmac_final(struct ssh_hmac_ctx *ctx, u_char *d, size_t dlen)
 __attribute__(());
void ssh_hmac_free(struct ssh_hmac_ctx *ctx);
struct umac_ctx *umac_new(const u_char key[]);
int umac_update(struct umac_ctx *ctx, const u_char *input, long len);


int umac_final(struct umac_ctx *ctx, u_char tag[], const u_char nonce[8]);




int umac_delete(struct umac_ctx *ctx);
struct umac_ctx *umac128_new(const u_char key[]);
int umac128_update(struct umac_ctx *ctx, const u_char *input, long len);
int umac128_final(struct umac_ctx *ctx, u_char tag[], const u_char nonce[8]);
int umac128_delete(struct umac_ctx *ctx);
struct sshmac {
 char *name;
 int enabled;
 u_int mac_len;
 u_char *key;
 u_int key_len;
 int type;
 int etm;
 struct ssh_hmac_ctx *hmac_ctx;
 struct umac_ctx *umac_ctx;
};

int mac_valid(const char *);
char *mac_alg_list(char);
int mac_setup(struct sshmac *, char *);
int mac_init(struct sshmac *);
int mac_compute(struct sshmac *, u_int32_t, const u_char *, int,
    u_char *, size_t);
int mac_check(struct sshmac *, u_int32_t, const u_char *, size_t,
    const u_char *, size_t);
void mac_clear(struct sshmac *);
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
const char *ssh_err(int n);




struct sshbuf {
 u_char *d;
 const u_char *cd;
 size_t off;
 size_t size;
 size_t max_size;
 size_t alloc;
 int readonly;
 int dont_free;
 u_int refcount;
 struct sshbuf *parent;
};





struct sshbuf *sshbuf_new(void);





struct sshbuf *sshbuf_from(const void *blob, size_t len);







struct sshbuf *sshbuf_fromb(struct sshbuf *buf);
int sshbuf_froms(struct sshbuf *buf, struct sshbuf **bufp);




void sshbuf_free(struct sshbuf *buf);




void sshbuf_reset(struct sshbuf *buf);




size_t sshbuf_max_size(const struct sshbuf *buf);





int sshbuf_set_max_size(struct sshbuf *buf, size_t max_size);




size_t sshbuf_len(const struct sshbuf *buf);




size_t sshbuf_avail(const struct sshbuf *buf);




const u_char *sshbuf_ptr(const struct sshbuf *buf);





u_char *sshbuf_mutable_ptr(const struct sshbuf *buf);







int sshbuf_check_reserve(const struct sshbuf *buf, size_t len);







int sshbuf_allocate(struct sshbuf *buf, size_t len);






int sshbuf_reserve(struct sshbuf *buf, size_t len, u_char **dpp);





int sshbuf_consume(struct sshbuf *buf, size_t len);





int sshbuf_consume_end(struct sshbuf *buf, size_t len);


int sshbuf_get(struct sshbuf *buf, void *v, size_t len);
int sshbuf_put(struct sshbuf *buf, const void *v, size_t len);
int sshbuf_putb(struct sshbuf *buf, const struct sshbuf *v);


int sshbuf_putf(struct sshbuf *buf, const char *fmt, ...)
     __attribute__((format(printf, 2, 3)));
int sshbuf_putfv(struct sshbuf *buf, const char *fmt, va_list ap);


int sshbuf_get_u64(struct sshbuf *buf, u_int64_t *valp);
int sshbuf_get_u32(struct sshbuf *buf, u_int32_t *valp);
int sshbuf_get_u16(struct sshbuf *buf, u_int16_t *valp);
int sshbuf_get_u8(struct sshbuf *buf, u_char *valp);
int sshbuf_put_u64(struct sshbuf *buf, u_int64_t val);
int sshbuf_put_u32(struct sshbuf *buf, u_int32_t val);
int sshbuf_put_u16(struct sshbuf *buf, u_int16_t val);
int sshbuf_put_u8(struct sshbuf *buf, u_char val);


int sshbuf_peek_u64(const struct sshbuf *buf, size_t offset,
    u_int64_t *valp);
int sshbuf_peek_u32(const struct sshbuf *buf, size_t offset,
    u_int32_t *valp);
int sshbuf_peek_u16(const struct sshbuf *buf, size_t offset,
    u_int16_t *valp);
int sshbuf_peek_u8(const struct sshbuf *buf, size_t offset,
    u_char *valp);





int sshbuf_poke_u64(struct sshbuf *buf, size_t offset, u_int64_t val);
int sshbuf_poke_u32(struct sshbuf *buf, size_t offset, u_int32_t val);
int sshbuf_poke_u16(struct sshbuf *buf, size_t offset, u_int16_t val);
int sshbuf_poke_u8(struct sshbuf *buf, size_t offset, u_char val);
int sshbuf_poke(struct sshbuf *buf, size_t offset, void *v, size_t len);






int sshbuf_get_string(struct sshbuf *buf, u_char **valp, size_t *lenp);
int sshbuf_get_cstring(struct sshbuf *buf, char **valp, size_t *lenp);
int sshbuf_get_stringb(struct sshbuf *buf, struct sshbuf *v);
int sshbuf_put_string(struct sshbuf *buf, const void *v, size_t len);
int sshbuf_put_cstring(struct sshbuf *buf, const char *v);
int sshbuf_put_stringb(struct sshbuf *buf, const struct sshbuf *v);






int sshbuf_get_string_direct(struct sshbuf *buf, const u_char **valp,
     size_t *lenp);





int sshbuf_peek_string_direct(const struct sshbuf *buf, const u_char **valp,
     size_t *lenp);





int sshbuf_put_bignum2_bytes(struct sshbuf *buf, const void *v, size_t len);
int sshbuf_get_bignum2_bytes_direct(struct sshbuf *buf,
     const u_char **valp, size_t *lenp);

int sshbuf_get_bignum2(struct sshbuf *buf, BIGNUM **valp);
int sshbuf_put_bignum2(struct sshbuf *buf, const BIGNUM *v);

int sshbuf_get_ec(struct sshbuf *buf, EC_POINT *v, const EC_GROUP *g);
int sshbuf_get_eckey(struct sshbuf *buf, EC_KEY *v);
int sshbuf_put_ec(struct sshbuf *buf, const EC_POINT *v, const EC_GROUP *g);
int sshbuf_put_eckey(struct sshbuf *buf, const EC_KEY *v);




void sshbuf_dump(const struct sshbuf *buf, FILE *f);


void sshbuf_dump_data(const void *s, size_t len, FILE *f);


char *sshbuf_dtob16(struct sshbuf *buf);


char *sshbuf_dtob64_string(const struct sshbuf *buf, int wrap);
int sshbuf_dtob64(const struct sshbuf *d, struct sshbuf *b64, int wrap);

int sshbuf_dtourlb64(const struct sshbuf *d, struct sshbuf *b64, int wrap);


int sshbuf_b64tod(struct sshbuf *buf, const char *b64);
int sshbuf_cmp(const struct sshbuf *b, size_t offset,
    const void *s, size_t len);
int
sshbuf_find(const struct sshbuf *b, size_t start_offset,
    const void *s, size_t len, size_t *offsetp);






char *sshbuf_dup_string(struct sshbuf *buf);





int sshbuf_load_fd(int, struct sshbuf **)
    __attribute__((__nonnull__ (2)));
int sshbuf_load_file(const char *, struct sshbuf **)
    __attribute__((__nonnull__ (2)));





int sshbuf_write_file(const char *path, struct sshbuf *buf)
    __attribute__((__nonnull__ (2)));


int sshbuf_read(int, struct sshbuf *, size_t, size_t *)
    __attribute__((__nonnull__ (2)));






int ssh_compatible_openssl(long, long);
void ssh_libcrypto_init(void);
int EVP_CIPHER_CTX_set_iv(EVP_CIPHER_CTX *ctx,
    const unsigned char *iv, size_t len);
void DSA_SIG_get0(const DSA_SIG *sig, const BIGNUM **pr, const BIGNUM **ps);



int DSA_SIG_set0(DSA_SIG *sig, BIGNUM *r, BIGNUM *s);
EVP_MD_CTX *EVP_MD_CTX_new(void);



void EVP_MD_CTX_free(EVP_MD_CTX *ctx);





struct macalg {
 char *name;
 int type;
 int alg;
 int truncatebits;
 int key_len;
 int len;
 int etm;
};

static const struct macalg macs[] = {

 { "hmac-sha1", 1, 1, 0, 0, 0, 0 },
 { "hmac-sha1-96", 1, 1, 96, 0, 0, 0 },
 { "hmac-sha2-256", 1, 2, 0, 0, 0, 0 },
 { "hmac-sha2-512", 1, 4, 0, 0, 0, 0 },
 { "hmac-md5", 1, 0, 0, 0, 0, 0 },
 { "hmac-md5-96", 1, 0, 96, 0, 0, 0 },
 { "umac-64@openssh.com", 2, 0, 0, 128, 64, 0 },
 { "umac-128@openssh.com", 3, 0, 0, 128, 128, 0 },


 { "hmac-sha1-etm@openssh.com", 1, 1, 0, 0, 0, 1 },
 { "hmac-sha1-96-etm@openssh.com", 1, 1, 96, 0, 0, 1 },
 { "hmac-sha2-256-etm@openssh.com", 1, 2, 0, 0, 0, 1 },
 { "hmac-sha2-512-etm@openssh.com", 1, 4, 0, 0, 0, 1 },
 { "hmac-md5-etm@openssh.com", 1, 0, 0, 0, 0, 1 },
 { "hmac-md5-96-etm@openssh.com", 1, 0, 96, 0, 0, 1 },
 { "umac-64-etm@openssh.com", 2, 0, 0, 128, 64, 1 },
 { "umac-128-etm@openssh.com", 3, 0, 0, 128, 128, 1 },

 { 
  ((void *)0)
      , 0, 0, 0, 0, 0, 0 }
};


char *
mac_alg_list(char sep)
{
 char *ret = 
            ((void *)0)
                , *tmp;
 size_t nlen, rlen = 0;
 const struct macalg *m;

 for (m = macs; m->name != 
                          ((void *)0)
                              ; m++) {
  if (ret != 
            ((void *)0)
                )
   ret[rlen++] = sep;
  nlen = strlen(m->name);
  if ((tmp = realloc(ret, rlen + nlen + 2)) == 
                                              ((void *)0)
                                                  ) {
   free(ret);
   return 
         ((void *)0)
             ;
  }
  ret = tmp;
  memcpy(ret + rlen, m->name, nlen + 1);
  rlen += nlen;
 }
 return ret;
}

static int
mac_setup_by_alg(struct sshmac *mac, const struct macalg *macalg)
{
 mac->type = macalg->type;
 if (mac->type == 1) {
  if ((mac->hmac_ctx = ssh_hmac_start(macalg->alg)) == 
                                                      ((void *)0)
                                                          )
   return -2;
  mac->key_len = mac->mac_len = ssh_hmac_bytes(macalg->alg);
 } else {
  mac->mac_len = macalg->len / 8;
  mac->key_len = macalg->key_len / 8;
  mac->umac_ctx = 
                 ((void *)0)
                     ;
 }
 if (macalg->truncatebits != 0)
  mac->mac_len = macalg->truncatebits / 8;
 mac->etm = macalg->etm;
 return 0;
}

int
mac_setup(struct sshmac *mac, char *name)
{
 const struct macalg *m;

 for (m = macs; m->name != 
                          ((void *)0)
                              ; m++) {
  if (strcmp(name, m->name) != 0)
   continue;
  if (mac != 
            ((void *)0)
                )
   return mac_setup_by_alg(mac, m);
  return 0;
 }
 return -10;
}

int
mac_init(struct sshmac *mac)
{
 if (mac->key == 
                ((void *)0)
                    )
  return -10;
 switch (mac->type) {
 case 1:
  if (mac->hmac_ctx == 
                      ((void *)0) 
                           ||
      ssh_hmac_init(mac->hmac_ctx, mac->key, mac->key_len) < 0)
   return -10;
  return 0;
 case 2:
  if ((mac->umac_ctx = umac_new(mac->key)) == 
                                             ((void *)0)
                                                 )
   return -2;
  return 0;
 case 3:
  if ((mac->umac_ctx = umac128_new(mac->key)) == 
                                                ((void *)0)
                                                    )
   return -2;
  return 0;
 default:
  return -10;
 }
}

int
mac_compute(struct sshmac *mac, u_int32_t seqno,
    const u_char *data, int datalen,
    u_char *digest, size_t dlen)
{
 static union {
  u_char m[64];
  u_int64_t for_align;
 } u;
 u_char b[4];
 u_char nonce[8];

 if (mac->mac_len > sizeof(u))
  return -1;

 switch (mac->type) {
 case 1:
  put_u32(b, seqno);

  if (ssh_hmac_init(mac->hmac_ctx, 
                                  ((void *)0)
                                      , 0) < 0 ||
      ssh_hmac_update(mac->hmac_ctx, b, sizeof(b)) < 0 ||
      ssh_hmac_update(mac->hmac_ctx, data, datalen) < 0 ||
      ssh_hmac_final(mac->hmac_ctx, u.m, sizeof(u.m)) < 0)
   return -22;
  break;
 case 2:
  do { const u_int64_t __v = (seqno); ((u_char *)(nonce))[0] = (__v >> 56) & 0xff; ((u_char *)(nonce))[1] = (__v >> 48) & 0xff; ((u_char *)(nonce))[2] = (__v >> 40) & 0xff; ((u_char *)(nonce))[3] = (__v >> 32) & 0xff; ((u_char *)(nonce))[4] = (__v >> 24) & 0xff; ((u_char *)(nonce))[5] = (__v >> 16) & 0xff; ((u_char *)(nonce))[6] = (__v >> 8) & 0xff; ((u_char *)(nonce))[7] = __v & 0xff; } while (0);
  umac_update(mac->umac_ctx, data, datalen);
  umac_final(mac->umac_ctx, u.m, nonce);
  break;
 case 3:
  put_u64(nonce, seqno);
  umac128_update(mac->umac_ctx, data, datalen);
  umac128_final(mac->umac_ctx, u.m, nonce);
  break;
 default:
  return -10;
 }
 if (digest != 
              ((void *)0)
                  ) {
  if (dlen > mac->mac_len)
   dlen = mac->mac_len;
  memcpy(digest, u.m, dlen);
 }
 return 0;
}

int
mac_check(struct sshmac *mac, u_int32_t seqno,
    const u_char *data, size_t dlen,
    const u_char *theirmac, size_t mlen)
{
 u_char ourmac[64];
 int r;

 if (mac->mac_len > mlen)
  return -10;
 if ((r = mac_compute(mac, seqno, data, dlen,
     ourmac, sizeof(ourmac))) != 0)
  return r;
 if (timingsafe_bcmp(ourmac, theirmac, mac->mac_len) != 0)
  return -30;
 return 0;
}

void
mac_clear(struct sshmac *mac)
{
 if (mac->type == 2) {
  if (mac->umac_ctx != 
                      ((void *)0)
                          )
   umac_delete(mac->umac_ctx);
 } else if (mac->type == 3) {
  if (mac->umac_ctx != 
                      ((void *)0)
                          )
   umac128_delete(mac->umac_ctx);
 } else if (mac->hmac_ctx != 
                            ((void *)0)
                                )
  ssh_hmac_free(mac->hmac_ctx);
 mac->hmac_ctx = 
                ((void *)0)
                    ;
 mac->umac_ctx = 
                ((void *)0)
                    ;
}



int
mac_valid(const char *names)
{
 char *maclist, *cp, *p;

 if (names == 
             ((void *)0) 
                  || strcmp(names, "") == 0)
  return 0;
 if ((maclist = cp = strdup(names)) == 
                                      ((void *)0)
                                          )
  return 0;
 for ((p = strsep(&cp, ",")); p && *p != '\0';
     (p = strsep(&cp, ","))) {
  if (mac_setup(
               ((void *)0)
                   , p) < 0) {
   free(maclist);
   return 0;
  }
 }
 free(maclist);
 return 1;
}
