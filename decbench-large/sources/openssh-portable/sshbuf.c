











































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
size_t sshbuf_alloc(const struct sshbuf *buf);




int sshbuf_set_parent(struct sshbuf *child, struct sshbuf *parent);




const struct sshbuf *sshbuf_parent(const struct sshbuf *buf);




u_int sshbuf_refcount(const struct sshbuf *buf);
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

static inline int
sshbuf_check_sanity(const struct sshbuf *buf)
{
 ;
 if (__builtin_expect(((buf == 
    ((void *)0) 
    || (!buf->readonly && buf->d != buf->cd) || buf->refcount < 1 || buf->refcount > 0x100000 || buf->cd == 
    ((void *)0) 
    || buf->max_size > 0x8000000 || buf->alloc > buf->max_size || buf->size > buf->alloc || buf->off > buf->size) != 0), 0)






                          ) {

  ;
  ssh_signal(
            11
                   , 
                     ((__sighandler_t) 0)
                            );
  raise(
       11
              );
  return -1;
 }
 return 0;
}

static void
sshbuf_maybe_pack(struct sshbuf *buf, int force)
{
 ;
 ;
 if (buf->off == 0 || buf->readonly || buf->refcount > 1)
  return;
 if (force ||
     (buf->off >= 8192 && buf->off >= buf->size / 2)) {
  memmove(buf->d, buf->d + buf->off, buf->size - buf->off);
  buf->size -= buf->off;
  buf->off = 0;
  ;
 }
}

struct sshbuf *
sshbuf_new(void)
{
 struct sshbuf *ret;

 if ((ret = calloc(sizeof(*ret), 1)) == 
                                       ((void *)0)
                                           )
  return 
        ((void *)0)
            ;
 ret->alloc = 256;
 ret->max_size = 0x8000000;
 ret->readonly = 0;
 ret->refcount = 1;
 ret->parent = 
              ((void *)0)
                  ;
 if ((ret->cd = ret->d = calloc(1, ret->alloc)) == 
                                                  ((void *)0)
                                                      ) {
  free(ret);
  return 
        ((void *)0)
            ;
 }
 return ret;
}

struct sshbuf *
sshbuf_from(const void *blob, size_t len)
{
 struct sshbuf *ret;

 if (blob == 
            ((void *)0) 
                 || len > 0x8000000 ||
     (ret = calloc(sizeof(*ret), 1)) == 
                                       ((void *)0)
                                           )
  return 
        ((void *)0)
            ;
 ret->alloc = ret->size = ret->max_size = len;
 ret->readonly = 1;
 ret->refcount = 1;
 ret->parent = 
              ((void *)0)
                  ;
 ret->cd = blob;
 ret->d = 
         ((void *)0)
             ;
 return ret;
}

int
sshbuf_set_parent(struct sshbuf *child, struct sshbuf *parent)
{
 int r;

 if ((r = sshbuf_check_sanity(child)) != 0 ||
     (r = sshbuf_check_sanity(parent)) != 0)
  return r;
 if (child->parent != 
                     ((void *)0) 
                          && child->parent != parent)
  return -1;
 child->parent = parent;
 child->parent->refcount++;
 return 0;
}

struct sshbuf *
sshbuf_fromb(struct sshbuf *buf)
{
 struct sshbuf *ret;

 if (sshbuf_check_sanity(buf) != 0)
  return 
        ((void *)0)
            ;
 if ((ret = sshbuf_from(sshbuf_ptr(buf), sshbuf_len(buf))) == 
                                                             ((void *)0)
                                                                 )
  return 
        ((void *)0)
            ;
 if (sshbuf_set_parent(ret, buf) != 0) {
  sshbuf_free(ret);
  return 
        ((void *)0)
            ;
 }
 return ret;
}

void
sshbuf_free(struct sshbuf *buf)
{
 if (buf == 
           ((void *)0)
               )
  return;






 if (sshbuf_check_sanity(buf) != 0)
  return;






 buf->refcount--;
 if (buf->refcount > 0)
  return;





 sshbuf_free(buf->parent);
 buf->parent = 
              ((void *)0)
                  ;

 if (!buf->readonly) {
  explicit_bzero(buf->d, buf->alloc);
  free(buf->d);
 }
 freezero(buf, sizeof(*buf));
}

void
sshbuf_reset(struct sshbuf *buf)
{
 u_char *d;

 if (buf->readonly || buf->refcount > 1) {

  buf->off = buf->size;
  return;
 }
 if (sshbuf_check_sanity(buf) != 0)
  return;
 buf->off = buf->size = 0;
 if (buf->alloc != 256) {
  if ((d = recallocarray(buf->d, buf->alloc, 256,
      1)) != 
            ((void *)0)
                ) {
   buf->cd = buf->d = d;
   buf->alloc = 256;
  }
 }
 explicit_bzero(buf->d, buf->alloc);
}

size_t
sshbuf_max_size(const struct sshbuf *buf)
{
 return buf->max_size;
}

size_t
sshbuf_alloc(const struct sshbuf *buf)
{
 return buf->alloc;
}

const struct sshbuf *
sshbuf_parent(const struct sshbuf *buf)
{
 return buf->parent;
}

u_int
sshbuf_refcount(const struct sshbuf *buf)
{
 return buf->refcount;
}

int
sshbuf_set_max_size(struct sshbuf *buf, size_t max_size)
{
 size_t rlen;
 u_char *dp;
 int r;

 ;
 if ((r = sshbuf_check_sanity(buf)) != 0)
  return r;
 if (max_size == buf->max_size)
  return 0;
 if (buf->readonly || buf->refcount > 1)
  return -49;
 if (max_size > 0x8000000)
  return -9;

 sshbuf_maybe_pack(buf, max_size < buf->size);
 if (max_size < buf->alloc && max_size > buf->size) {
  if (buf->size < 256)
   rlen = 256;
  else
   rlen = ((((buf->size)+((256)-1))/(256))*(256));
  if (rlen > max_size)
   rlen = max_size;
  ;
  if ((dp = recallocarray(buf->d, buf->alloc, rlen, 1)) == 
                                                          ((void *)0)
                                                              )
   return -2;
  buf->cd = buf->d = dp;
  buf->alloc = rlen;
 }
 ;
 if (max_size < buf->alloc)
  return -9;
 buf->max_size = max_size;
 return 0;
}

size_t
sshbuf_len(const struct sshbuf *buf)
{
 if (sshbuf_check_sanity(buf) != 0)
  return 0;
 return buf->size - buf->off;
}

size_t
sshbuf_avail(const struct sshbuf *buf)
{
 if (sshbuf_check_sanity(buf) != 0 || buf->readonly || buf->refcount > 1)
  return 0;
 return buf->max_size - (buf->size - buf->off);
}

const u_char *
sshbuf_ptr(const struct sshbuf *buf)
{
 if (sshbuf_check_sanity(buf) != 0)
  return 
        ((void *)0)
            ;
 return buf->cd + buf->off;
}

u_char *
sshbuf_mutable_ptr(const struct sshbuf *buf)
{
 if (sshbuf_check_sanity(buf) != 0 || buf->readonly || buf->refcount > 1)
  return 
        ((void *)0)
            ;
 return buf->d + buf->off;
}

int
sshbuf_check_reserve(const struct sshbuf *buf, size_t len)
{
 int r;

 if ((r = sshbuf_check_sanity(buf)) != 0)
  return r;
 if (buf->readonly || buf->refcount > 1)
  return -49;
 ;

 if (len > buf->max_size || buf->max_size - len < buf->size - buf->off)
  return -9;
 return 0;
}

int
sshbuf_allocate(struct sshbuf *buf, size_t len)
{
 size_t rlen, need;
 u_char *dp;
 int r;

 ;
 if ((r = sshbuf_check_reserve(buf, len)) != 0)
  return r;




 sshbuf_maybe_pack(buf, buf->size + len > buf->max_size);
 ;
 if (len + buf->size <= buf->alloc)
  return 0;





 need = len + buf->size - buf->alloc;
 rlen = ((((buf->alloc + need)+((256)-1))/(256))*(256));
 ;
 if (rlen > buf->max_size)
  rlen = buf->alloc + need;
 ;
 if ((dp = recallocarray(buf->d, buf->alloc, rlen, 1)) == 
                                                         ((void *)0)
                                                             ) {
  ;
  return -2;
 }
 buf->alloc = rlen;
 buf->cd = buf->d = dp;
 if ((r = sshbuf_check_reserve(buf, len)) < 0) {

  return r;
 }
 ;
 return 0;
}

int
sshbuf_reserve(struct sshbuf *buf, size_t len, u_char **dpp)
{
 u_char *dp;
 int r;

 if (dpp != 
           ((void *)0)
               )
  *dpp = 
        ((void *)0)
            ;

 ;
 if ((r = sshbuf_allocate(buf, len)) != 0)
  return r;

 dp = buf->d + buf->size;
 buf->size += len;
 if (dpp != 
           ((void *)0)
               )
  *dpp = dp;
 return 0;
}

int
sshbuf_consume(struct sshbuf *buf, size_t len)
{
 int r;

 ;
 if ((r = sshbuf_check_sanity(buf)) != 0)
  return r;
 if (len == 0)
  return 0;
 if (len > sshbuf_len(buf))
  return -3;
 buf->off += len;

 if (buf->off == buf->size)
  buf->off = buf->size = 0;
 ;
 return 0;
}

int
sshbuf_consume_end(struct sshbuf *buf, size_t len)
{
 int r;

 ;
 if ((r = sshbuf_check_sanity(buf)) != 0)
  return r;
 if (len == 0)
  return 0;
 if (len > sshbuf_len(buf))
  return -3;
 buf->size -= len;
 ;
 return 0;
}
