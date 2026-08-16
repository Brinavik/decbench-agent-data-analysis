











































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



























int ssh_compatible_openssl(long, long);
void ssh_libcrypto_init(void);
int EVP_CIPHER_CTX_set_iv(EVP_CIPHER_CTX *ctx,
    const unsigned char *iv, size_t len);
void DSA_SIG_get0(const DSA_SIG *sig, const BIGNUM **pr, const BIGNUM **ps);



int DSA_SIG_set0(DSA_SIG *sig, BIGNUM *r, BIGNUM *s);
EVP_MD_CTX *EVP_MD_CTX_new(void);



void EVP_MD_CTX_free(EVP_MD_CTX *ctx);

void *xmalloc(size_t);
void *xcalloc(size_t, size_t);
void *xreallocarray(void *, size_t, size_t);
void *xrecallocarray(void *, size_t, size_t, size_t);
char *xstrdup(const char *);
int xasprintf(char **, const char *, ...)
    __attribute__((__format__ (printf, 2, 3))) __attribute__((__nonnull__ (2)));
int xvasprintf(char **, const char *, va_list)
    __attribute__((__nonnull__ (2)));
char *get_peer_ipaddr(int);
int get_peer_port(int);
char *get_local_ipaddr(int);
char *get_local_name(int);
int get_local_port(int);



void ipv64_normalise_mapped(struct sockaddr_storage *, socklen_t *);
struct ssh;

void compat_banner(struct ssh *, const char *);
char *compat_cipher_proposal(struct ssh *, char *);
char *compat_pkalg_proposal(struct ssh *, char *);
char *compat_kex_proposal(struct ssh *, char *);
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
void poly1305_auth(u_char out[16], const u_char *m, size_t inlen,
    const u_char key[32])
    __attribute__(())
    __attribute__(())
    __attribute__(());



struct chachapoly_ctx;

struct chachapoly_ctx *chachapoly_new(const u_char *key, u_int keylen)
    __attribute__(());
void chachapoly_free(struct chachapoly_ctx *cpctx);

int chachapoly_crypt(struct chachapoly_ctx *cpctx, u_int seqnr,
    u_char *dest, const u_char *src, u_int len, u_int aadlen, u_int authlen,
    int do_encrypt);
int chachapoly_get_length(struct chachapoly_ctx *cpctx,
    u_int *plenp, u_int seqnr, const u_char *cp, u_int len)
    __attribute__(());
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int rijndaelKeySetupEnc(unsigned int [], const unsigned char [], int);
void rijndaelEncrypt(const unsigned int [], int, const u8 [16], u8 [16]);


typedef struct {
 int decrypt;
 int Nr;
 u32 ek[4*(14 + 1)];
 u32 dk[4*(14 + 1)];
} rijndael_ctx;

void rijndael_set_key(rijndael_ctx *, u_char *, int, int);
void rijndael_decrypt(rijndael_ctx *, u_char *, u_char *);
void rijndael_encrypt(rijndael_ctx *, u_char *, u_char *);



typedef struct aesctr_ctx {
 int rounds;
 u32 ek[4*(14 + 1)];
 u8 ctr[16];
} aesctr_ctx;

void aesctr_keysetup(aesctr_ctx *x,const u8 *k,u32 kbits,u32 ivbits);
void aesctr_ivsetup(aesctr_ctx *x,const u8 *iv);
void aesctr_encrypt_bytes(aesctr_ctx *x,const u8 *m,u8 *c,u32 bytes);




struct sshcipher;
struct sshcipher_ctx;

const struct sshcipher *cipher_by_name(const char *);
const char *cipher_warning_message(const struct sshcipher_ctx *);
int ciphers_valid(const char *);
char *cipher_alg_list(char, int);
const char *compression_alg_list(int);
int cipher_init(struct sshcipher_ctx **, const struct sshcipher *,
    const u_char *, u_int, const u_char *, u_int, int);
int cipher_crypt(struct sshcipher_ctx *, u_int, u_char *, const u_char *,
    u_int, u_int, u_int);
int cipher_get_length(struct sshcipher_ctx *, u_int *, u_int,
    const u_char *, u_int);
void cipher_free(struct sshcipher_ctx *);
u_int cipher_blocksize(const struct sshcipher *);
u_int cipher_keylen(const struct sshcipher *);
u_int cipher_seclen(const struct sshcipher *);
u_int cipher_authlen(const struct sshcipher *);
u_int cipher_ivlen(const struct sshcipher *);
u_int cipher_is_cbc(const struct sshcipher *);

u_int cipher_ctx_is_plaintext(struct sshcipher_ctx *);

int cipher_get_keyiv(struct sshcipher_ctx *, u_char *, size_t);
int cipher_set_keyiv(struct sshcipher_ctx *, const u_char *, size_t);
int cipher_get_keyiv_len(const struct sshcipher_ctx *);
struct kex;
struct sshkey;
struct sshbuf;
struct session_state;

enum {
 DISPATCH_BLOCK,
 DISPATCH_NONBLOCK
};

struct ssh;

typedef int dispatch_fn(int, u_int32_t, struct ssh *);

int dispatch_protocol_error(int, u_int32_t, struct ssh *);
int dispatch_protocol_ignore(int, u_int32_t, struct ssh *);
void ssh_dispatch_init(struct ssh *, dispatch_fn *);
void ssh_dispatch_set(struct ssh *, int, dispatch_fn *);
void ssh_dispatch_range(struct ssh *, u_int, u_int, dispatch_fn *);
int ssh_dispatch_run(struct ssh *, int, volatile sig_atomic_t *);
void ssh_dispatch_run_fatal(struct ssh *, int, volatile sig_atomic_t *);

struct key_entry {
 struct { struct key_entry *tqe_next; struct key_entry **tqe_prev; } next;
 struct sshkey *key;
};

struct ssh {

 struct session_state *state;


 struct kex *kex;


 char *remote_ipaddr;
 int remote_port;
 char *local_ipaddr;
 int local_port;
 char *rdomain_in;


 char *log_preamble;


 dispatch_fn *dispatch[255];

 int dispatch_skip_packets;


 int compat;


 struct { struct key_entry *tqh_first; struct key_entry **tqh_last; } private_keys;
 struct { struct key_entry *tqh_first; struct key_entry **tqh_last; } public_keys;


 void *authctxt;


 struct ssh_channels *chanctxt;


 void *app_data;
};

typedef int (ssh_packet_hook_fn)(struct ssh *, struct sshbuf *,
    u_char *, void *);

struct ssh *ssh_alloc_session_state(void);
struct ssh *ssh_packet_set_connection(struct ssh *, int, int);
void ssh_packet_set_timeout(struct ssh *, int, int);
int ssh_packet_stop_discard(struct ssh *);
int ssh_packet_connection_af(struct ssh *);
void ssh_packet_set_nonblocking(struct ssh *);
int ssh_packet_get_connection_in(struct ssh *);
int ssh_packet_get_connection_out(struct ssh *);
void ssh_packet_close(struct ssh *);
void ssh_packet_set_input_hook(struct ssh *, ssh_packet_hook_fn *, void *);
void ssh_packet_clear_keys(struct ssh *);
void ssh_clear_newkeys(struct ssh *, int);

int ssh_packet_is_rekeying(struct ssh *);
int ssh_packet_check_rekey(struct ssh *);
void ssh_packet_set_protocol_flags(struct ssh *, u_int);
u_int ssh_packet_get_protocol_flags(struct ssh *);
void ssh_packet_set_tos(struct ssh *, int);
void ssh_packet_set_interactive(struct ssh *, int, int, int);
int ssh_packet_is_interactive(struct ssh *);
void ssh_packet_set_server(struct ssh *);
void ssh_packet_set_authenticated(struct ssh *);
void ssh_packet_set_mux(struct ssh *);
int ssh_packet_get_mux(struct ssh *);
int ssh_packet_set_log_preamble(struct ssh *, const char *, ...)
    __attribute__((format(printf, 2, 3)));

int ssh_packet_log_type(u_char);

int ssh_packet_send2_wrapped(struct ssh *);
int ssh_packet_send2(struct ssh *);

int ssh_packet_read(struct ssh *);
int ssh_packet_read_expect(struct ssh *, u_int type);
int ssh_packet_read_poll(struct ssh *);
int ssh_packet_read_poll2(struct ssh *, u_char *, u_int32_t *seqnr_p);
int ssh_packet_process_incoming(struct ssh *, const char *buf, u_int len);
int ssh_packet_process_read(struct ssh *, int);
int ssh_packet_read_seqnr(struct ssh *, u_char *, u_int32_t *seqnr_p);
int ssh_packet_read_poll_seqnr(struct ssh *, u_char *, u_int32_t *seqnr_p);

const void *ssh_packet_get_string_ptr(struct ssh *, u_int *length_ptr);
void ssh_packet_disconnect(struct ssh *, const char *fmt, ...)
 __attribute__((format(printf, 2, 3)))
 __attribute__((noreturn));
void ssh_packet_send_debug(struct ssh *, const char *fmt, ...) __attribute__((format(printf, 2, 3)));

int ssh_set_newkeys(struct ssh *, int mode);
void ssh_packet_get_bytes(struct ssh *, u_int64_t *, u_int64_t *);

int ssh_packet_write_poll(struct ssh *);
int ssh_packet_write_wait(struct ssh *);
int ssh_packet_have_data_to_write(struct ssh *);
int ssh_packet_not_very_much_data_to_write(struct ssh *);

int ssh_packet_connection_is_on_socket(struct ssh *);
int ssh_packet_remaining(struct ssh *);

void ssh_tty_make_modes(struct ssh *, int, struct termios *);
void ssh_tty_parse_modes(struct ssh *, int);

void ssh_packet_set_alive_timeouts(struct ssh *, int);
int ssh_packet_inc_alive_timeouts(struct ssh *);
int ssh_packet_set_maxsize(struct ssh *, u_int);
u_int ssh_packet_get_maxsize(struct ssh *);

int ssh_packet_get_state(struct ssh *, struct sshbuf *);
int ssh_packet_set_state(struct ssh *, struct sshbuf *);

const char *ssh_remote_ipaddr(struct ssh *);
int ssh_remote_port(struct ssh *);
const char *ssh_local_ipaddr(struct ssh *);
int ssh_local_port(struct ssh *);
const char *ssh_packet_rdomain_in(struct ssh *);

void ssh_packet_set_rekey_limits(struct ssh *, u_int64_t, u_int32_t);
time_t ssh_packet_get_rekey_timeout(struct ssh *);

void *ssh_packet_get_input(struct ssh *);
void *ssh_packet_get_output(struct ssh *);


int sshpkt_start(struct ssh *ssh, u_char type);
int sshpkt_send(struct ssh *ssh);
int sshpkt_disconnect(struct ssh *, const char *fmt, ...)
     __attribute__((format(printf, 2, 3)));
int sshpkt_add_padding(struct ssh *, u_char);
void sshpkt_fatal(struct ssh *ssh, int r, const char *fmt, ...)
     __attribute__((format(printf, 3, 4)))
     __attribute__((noreturn));
int sshpkt_msg_ignore(struct ssh *, u_int);

int sshpkt_put(struct ssh *ssh, const void *v, size_t len);
int sshpkt_putb(struct ssh *ssh, const struct sshbuf *b);
int sshpkt_put_u8(struct ssh *ssh, u_char val);
int sshpkt_put_u32(struct ssh *ssh, u_int32_t val);
int sshpkt_put_u64(struct ssh *ssh, u_int64_t val);
int sshpkt_put_string(struct ssh *ssh, const void *v, size_t len);
int sshpkt_put_cstring(struct ssh *ssh, const void *v);
int sshpkt_put_stringb(struct ssh *ssh, const struct sshbuf *v);
int sshpkt_put_ec(struct ssh *ssh, const EC_POINT *v, const EC_GROUP *g);
int sshpkt_put_bignum2(struct ssh *ssh, const BIGNUM *v);

int sshpkt_get(struct ssh *ssh, void *valp, size_t len);
int sshpkt_get_u8(struct ssh *ssh, u_char *valp);
int sshpkt_get_u32(struct ssh *ssh, u_int32_t *valp);
int sshpkt_get_u64(struct ssh *ssh, u_int64_t *valp);
int sshpkt_get_string(struct ssh *ssh, u_char **valp, size_t *lenp);
int sshpkt_get_string_direct(struct ssh *ssh, const u_char **valp, size_t *lenp);
int sshpkt_peek_string_direct(struct ssh *ssh, const u_char **valp, size_t *lenp);
int sshpkt_get_cstring(struct ssh *ssh, char **valp, size_t *lenp);
int sshpkt_getb_froms(struct ssh *ssh, struct sshbuf **valp);
int sshpkt_get_ec(struct ssh *ssh, EC_POINT *v, const EC_GROUP *g);
int sshpkt_get_bignum2(struct ssh *ssh, BIGNUM **valp);
int sshpkt_get_end(struct ssh *ssh);
void sshpkt_fmt_connection_id(struct ssh *ssh, char *s, size_t l);
const u_char *sshpkt_ptr(struct ssh *, size_t *lenp);
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
struct ssh;
struct Channel;
typedef struct Channel Channel;
struct fwd_perm_list;

typedef void channel_open_fn(struct ssh *, int, int, void *);
typedef void channel_callback_fn(struct ssh *, int, void *);
typedef int channel_infilter_fn(struct ssh *, struct Channel *, char *, int);
typedef void channel_filter_cleanup_fn(struct ssh *, int, void *);
typedef u_char *channel_outfilter_fn(struct ssh *, struct Channel *,
    u_char **, size_t *);


typedef void channel_confirm_cb(struct ssh *, int, struct Channel *, void *);
typedef void channel_confirm_abandon_cb(struct ssh *, struct Channel *, void *);
struct channel_confirm {
 struct { struct channel_confirm *tqe_next; struct channel_confirm **tqe_prev; } entry;
 channel_confirm_cb *cb;
 channel_confirm_abandon_cb *abandon_cb;
 void *ctx;
};
struct channel_confirms { struct channel_confirm *tqh_first; struct channel_confirm **tqh_last; };


struct channel_connect {
 char *host;
 int port;
 struct addrinfo *ai, *aitop;
};


typedef int mux_callback_fn(struct ssh *, struct Channel *);
struct Channel {
 int type;

 int self;
 uint32_t remote_id;
 int have_remote_id;

 u_int istate;
 u_int ostate;
 int flags;
 int rfd;
 int wfd;
 int efd;
 int sock;
 u_int io_want;
 u_int io_ready;
 int pfds[4];
 int ctl_chan;
 int isatty;



 int client_tty;
 int force_drain;
 time_t notbefore;
 int delayed;




 int restore_block;
 struct sshbuf *input;

 struct sshbuf *output;

 struct sshbuf *extended;

 char *path;

 int listening_port;
 char *listening_addr;
 int host_port;
 char *remote_name;

 u_int remote_window;
 u_int remote_maxpacket;
 u_int local_window;
 u_int local_window_max;
 u_int local_consumed;
 u_int local_maxpacket;
 int extended_usage;
 int single_connection;

 char *ctype;


 channel_open_fn *open_confirm;
 void *open_confirm_ctx;
 channel_callback_fn *detach_user;
 int detach_close;
 struct channel_confirms status_confirms;


 channel_infilter_fn *input_filter;
 channel_outfilter_fn *output_filter;
 void *filter_ctx;
 channel_filter_cleanup_fn *filter_cleanup;


 int datagram;



 struct channel_connect connect_ctx;


 mux_callback_fn *mux_rcb;
 void *mux_ctx;
 int mux_pause;
 int mux_downstream_id;
};
void channel_init_channels(struct ssh *ssh);



Channel *channel_by_id(struct ssh *, int);
Channel *channel_by_remote_id(struct ssh *, u_int);
Channel *channel_lookup(struct ssh *, int);
Channel *channel_new(struct ssh *, char *, int, int, int, int,
     u_int, u_int, int, const char *, int);
void channel_set_fds(struct ssh *, int, int, int, int, int,
     int, int, u_int);
void channel_free(struct ssh *, Channel *);
void channel_free_all(struct ssh *);
void channel_stop_listening(struct ssh *);

void channel_send_open(struct ssh *, int);
void channel_request_start(struct ssh *, int, char *, int);
void channel_register_cleanup(struct ssh *, int,
     channel_callback_fn *, int);
void channel_register_open_confirm(struct ssh *, int,
     channel_open_fn *, void *);
void channel_register_filter(struct ssh *, int, channel_infilter_fn *,
     channel_outfilter_fn *, channel_filter_cleanup_fn *, void *);
void channel_register_status_confirm(struct ssh *, int,
     channel_confirm_cb *, channel_confirm_abandon_cb *, void *);
void channel_cancel_cleanup(struct ssh *, int);
int channel_close_fd(struct ssh *, Channel *, int *);
void channel_send_window_changes(struct ssh *);



int channel_proxy_downstream(struct ssh *, Channel *mc);
int channel_proxy_upstream(Channel *, int, u_int32_t, struct ssh *);



int channel_input_data(int, u_int32_t, struct ssh *);
int channel_input_extended_data(int, u_int32_t, struct ssh *);
int channel_input_ieof(int, u_int32_t, struct ssh *);
int channel_input_oclose(int, u_int32_t, struct ssh *);
int channel_input_open_confirmation(int, u_int32_t, struct ssh *);
int channel_input_open_failure(int, u_int32_t, struct ssh *);
int channel_input_port_open(int, u_int32_t, struct ssh *);
int channel_input_window_adjust(int, u_int32_t, struct ssh *);
int channel_input_status_confirm(int, u_int32_t, struct ssh *);


struct pollfd;

void channel_prepare_poll(struct ssh *, struct pollfd **,
     u_int *, u_int *, u_int, time_t *);
void channel_after_poll(struct ssh *, struct pollfd *, u_int);
void channel_output_poll(struct ssh *);

int channel_not_very_much_buffered_data(struct ssh *);
void channel_close_all(struct ssh *);
int channel_still_open(struct ssh *);
const char *channel_format_extended_usage(const Channel *);
char *channel_open_message(struct ssh *);
int channel_find_open(struct ssh *);


struct Forward;
struct ForwardOptions;
void channel_set_af(struct ssh *, int af);
void channel_permit_all(struct ssh *, int);
void channel_add_permission(struct ssh *, int, int, char *, int);
void channel_clear_permission(struct ssh *, int, int);
void channel_disable_admin(struct ssh *, int);
void channel_update_permission(struct ssh *, int, int);
Channel *channel_connect_to_port(struct ssh *, const char *, u_short,
     char *, char *, int *, const char **);
Channel *channel_connect_to_path(struct ssh *, const char *, char *, char *);
Channel *channel_connect_stdio_fwd(struct ssh *, const char*,
     u_short, int, int, int);
Channel *channel_connect_by_listen_address(struct ssh *, const char *,
     u_short, char *, char *);
Channel *channel_connect_by_listen_path(struct ssh *, const char *,
     char *, char *);
int channel_request_remote_forwarding(struct ssh *, struct Forward *);
int channel_setup_local_fwd_listener(struct ssh *, struct Forward *,
     struct ForwardOptions *);
int channel_request_rforward_cancel(struct ssh *, struct Forward *);
int channel_setup_remote_fwd_listener(struct ssh *, struct Forward *,
     int *, struct ForwardOptions *);
int channel_cancel_rport_listener(struct ssh *, struct Forward *);
int channel_cancel_lport_listener(struct ssh *, struct Forward *,
     int, struct ForwardOptions *);
int permitopen_port(const char *);



void channel_set_x11_refuse_time(struct ssh *, u_int);
int x11_connect_display(struct ssh *);
int x11_create_display_inet(struct ssh *, int, int, int, u_int *, int **);
void x11_request_forwarding_with_spoofing(struct ssh *, int,
     const char *, const char *, const char *, int);



int chan_is_dead(struct ssh *, Channel *, int);
void chan_mark_dead(struct ssh *, Channel *);



void chan_rcvd_oclose(struct ssh *, Channel *);
void chan_rcvd_eow(struct ssh *, Channel *);
void chan_read_failed(struct ssh *, Channel *);
void chan_ibuf_empty(struct ssh *, Channel *);
void chan_rcvd_ieof(struct ssh *, Channel *);
void chan_write_failed(struct ssh *, Channel *);
void chan_obuf_empty(struct ssh *, Channel *);
struct sshbuf;


enum sshkey_types {
 KEY_RSA,
 KEY_DSA,
 KEY_ECDSA,
 KEY_ED25519,
 KEY_RSA_CERT,
 KEY_DSA_CERT,
 KEY_ECDSA_CERT,
 KEY_ED25519_CERT,
 KEY_XMSS,
 KEY_XMSS_CERT,
 KEY_ECDSA_SK,
 KEY_ECDSA_SK_CERT,
 KEY_ED25519_SK,
 KEY_ED25519_SK_CERT,
 KEY_UNSPEC
};





enum sshkey_fp_rep {
 SSH_FP_DEFAULT = 0,
 SSH_FP_HEX,
 SSH_FP_BASE64,
 SSH_FP_BUBBLEBABBLE,
 SSH_FP_RANDOMART
};


enum sshkey_serialize_rep {
 SSHKEY_SERIALIZE_DEFAULT = 0,
 SSHKEY_SERIALIZE_STATE = 1,
 SSHKEY_SERIALIZE_FULL = 2,
 SSHKEY_SERIALIZE_SHIELD = 3,
 SSHKEY_SERIALIZE_INFO = 254,
};


enum sshkey_private_format {
 SSHKEY_PRIVATE_OPENSSH = 0,
 SSHKEY_PRIVATE_PEM = 1,
 SSHKEY_PRIVATE_PKCS8 = 2,
};






struct sshkey_cert {
 struct sshbuf *certblob;
 u_int type;
 u_int64_t serial;
 char *key_id;
 u_int nprincipals;
 char **principals;
 u_int64_t valid_after, valid_before;
 struct sshbuf *critical;
 struct sshbuf *extensions;
 struct sshkey *signature_key;
 char *signature_type;
};


struct sshkey {
 int type;
 int flags;

 RSA *rsa;

 DSA *dsa;

 int ecdsa_nid;
 EC_KEY *ecdsa;

 u_char *ed25519_sk;
 u_char *ed25519_pk;

 char *xmss_name;
 char *xmss_filename;
 void *xmss_state;
 u_char *xmss_sk;
 u_char *xmss_pk;

 char *sk_application;
 uint8_t sk_flags;
 struct sshbuf *sk_key_handle;
 struct sshbuf *sk_reserved;

 struct sshkey_cert *cert;

 u_char *shielded_private;
 size_t shielded_len;
 u_char *shield_prekey;
 size_t shield_prekey_len;
};





struct sshkey_sig_details {
 uint32_t sk_counter;
 uint8_t sk_flags;
};

struct sshkey *sshkey_new(int);
void sshkey_free(struct sshkey *);
int sshkey_equal_public(const struct sshkey *,
    const struct sshkey *);
int sshkey_equal(const struct sshkey *, const struct sshkey *);
char *sshkey_fingerprint(const struct sshkey *,
    int, enum sshkey_fp_rep);
int sshkey_fingerprint_raw(const struct sshkey *k,
    int, u_char **retp, size_t *lenp);
const char *sshkey_type(const struct sshkey *);
const char *sshkey_cert_type(const struct sshkey *);
int sshkey_format_text(const struct sshkey *, struct sshbuf *);
int sshkey_write(const struct sshkey *, FILE *);
int sshkey_read(struct sshkey *, char **);
u_int sshkey_size(const struct sshkey *);

int sshkey_generate(int type, u_int bits, struct sshkey **keyp);
int sshkey_from_private(const struct sshkey *, struct sshkey **);

int sshkey_is_shielded(struct sshkey *);
int sshkey_shield_private(struct sshkey *);
int sshkey_unshield_private(struct sshkey *);

int sshkey_type_from_name(const char *);
int sshkey_is_cert(const struct sshkey *);
int sshkey_is_sk(const struct sshkey *);
int sshkey_type_is_cert(int);
int sshkey_type_plain(int);


int sshkey_match_keyname_to_sigalgs(const char *, const char *);

int sshkey_to_certified(struct sshkey *);
int sshkey_drop_cert(struct sshkey *);
int sshkey_cert_copy(const struct sshkey *, struct sshkey *);
int sshkey_cert_check_authority(const struct sshkey *, int, int, int,
    uint64_t, const char *, const char **);
int sshkey_cert_check_authority_now(const struct sshkey *, int, int, int,
    const char *, const char **);
int sshkey_cert_check_host(const struct sshkey *, const char *,
    int , const char *, const char **);
size_t sshkey_format_cert_validity(const struct sshkey_cert *,
    char *, size_t) __attribute__(());
int sshkey_check_cert_sigtype(const struct sshkey *, const char *);

int sshkey_certify(struct sshkey *, struct sshkey *,
    const char *, const char *, const char *);

typedef int sshkey_certify_signer(struct sshkey *, u_char **, size_t *,
    const u_char *, size_t, const char *, const char *, const char *,
    u_int, void *);
int sshkey_certify_custom(struct sshkey *, struct sshkey *, const char *,
    const char *, const char *, sshkey_certify_signer *, void *);

int sshkey_ecdsa_nid_from_name(const char *);
int sshkey_curve_name_to_nid(const char *);
const char * sshkey_curve_nid_to_name(int);
u_int sshkey_curve_nid_to_bits(int);
int sshkey_ecdsa_bits_to_nid(int);
int sshkey_ecdsa_key_to_nid(EC_KEY *);
int sshkey_ec_nid_to_hash_alg(int nid);
int sshkey_ec_validate_public(const EC_GROUP *, const EC_POINT *);
int sshkey_ec_validate_private(const EC_KEY *);
const char *sshkey_ssh_name(const struct sshkey *);
const char *sshkey_ssh_name_plain(const struct sshkey *);
int sshkey_names_valid2(const char *, int);
char *sshkey_alg_list(int, int, int, char);

int sshkey_from_blob(const u_char *, size_t, struct sshkey **);
int sshkey_fromb(struct sshbuf *, struct sshkey **);
int sshkey_froms(struct sshbuf *, struct sshkey **);
int sshkey_to_blob(const struct sshkey *, u_char **, size_t *);
int sshkey_to_base64(const struct sshkey *, char **);
int sshkey_putb(const struct sshkey *, struct sshbuf *);
int sshkey_puts(const struct sshkey *, struct sshbuf *);
int sshkey_puts_opts(const struct sshkey *, struct sshbuf *,
    enum sshkey_serialize_rep);
int sshkey_plain_to_blob(const struct sshkey *, u_char **, size_t *);
int sshkey_putb_plain(const struct sshkey *, struct sshbuf *);

int sshkey_sign(struct sshkey *, u_char **, size_t *,
    const u_char *, size_t, const char *, const char *, const char *, u_int);
int sshkey_verify(const struct sshkey *, const u_char *, size_t,
    const u_char *, size_t, const char *, u_int, struct sshkey_sig_details **);
int sshkey_check_sigtype(const u_char *, size_t, const char *);
const char *sshkey_sigalg_by_name(const char *);
int sshkey_get_sigtype(const u_char *, size_t, char **);


void sshkey_dump_ec_point(const EC_GROUP *, const EC_POINT *);
void sshkey_dump_ec_key(const EC_KEY *);


int sshkey_private_serialize(struct sshkey *key, struct sshbuf *buf);
int sshkey_private_serialize_opt(struct sshkey *key, struct sshbuf *buf,
    enum sshkey_serialize_rep);
int sshkey_private_deserialize(struct sshbuf *buf, struct sshkey **keyp);


int sshkey_private_to_fileblob(struct sshkey *key, struct sshbuf *blob,
    const char *passphrase, const char *comment,
    int format, const char *openssh_format_cipher, int openssh_format_rounds);
int sshkey_parse_private_fileblob(struct sshbuf *buffer,
    const char *passphrase, struct sshkey **keyp, char **commentp);
int sshkey_parse_private_fileblob_type(struct sshbuf *blob, int type,
    const char *passphrase, struct sshkey **keyp, char **commentp);
int sshkey_parse_pubkey_from_private_fileblob_type(struct sshbuf *blob,
    int type, struct sshkey **pubkeyp);

int sshkey_check_rsa_length(const struct sshkey *, int);

int ssh_rsa_complete_crt_parameters(struct sshkey *, const BIGNUM *);


int sshkey_set_filename(struct sshkey *, const char *);
int sshkey_enable_maxsign(struct sshkey *, u_int32_t);
u_int32_t sshkey_signatures_left(const struct sshkey *);
int sshkey_forward_state(const struct sshkey *, u_int32_t, int);
int sshkey_private_serialize_maxsign(struct sshkey *key,
    struct sshbuf *buf, u_int32_t maxsign, int);

void sshkey_sig_details_free(struct sshkey_sig_details *);
struct sshbuf;
struct sshkey;


struct ssh_identitylist {
 size_t nkeys;
 struct sshkey **keys;
 char **comments;
};


struct dest_constraint_hop {
 char *user;
 char *hostname;
 int is_ca;
 u_int nkeys;
 struct sshkey **keys;
 int *key_is_ca;
};
struct dest_constraint {
 struct dest_constraint_hop from;
 struct dest_constraint_hop to;
};

int ssh_get_authentication_socket(int *fdp);
int ssh_get_authentication_socket_path(const char *authsocket, int *fdp);
void ssh_close_authentication_socket(int sock);

int ssh_lock_agent(int sock, int lock, const char *password);
int ssh_fetch_identitylist(int sock, struct ssh_identitylist **idlp);
void ssh_free_identitylist(struct ssh_identitylist *idl);
int ssh_add_identity_constrained(int sock, struct sshkey *key,
    const char *comment, u_int life, u_int confirm, u_int maxsign,
    const char *provider, struct dest_constraint **dest_constraints,
    size_t ndest_constraints);
int ssh_agent_has_key(int sock, const struct sshkey *key);
int ssh_remove_identity(int sock, const struct sshkey *key);
int ssh_update_card(int sock, int add, const char *reader_id,
     const char *pin, u_int life, u_int confirm,
     struct dest_constraint **dest_constraints,
     size_t ndest_constraints);
int ssh_remove_all_identities(int sock, int version);

int ssh_agent_sign(int sock, const struct sshkey *key,
     u_char **sigp, size_t *lenp,
     const u_char *data, size_t datalen, const char *alg, u_int compat);

int ssh_agent_bind_hostkey(int sock, const struct sshkey *key,
    const struct sshbuf *session_id, const struct sshbuf *signature,
    int forwarding);
struct sshbuf;
struct sshkey;




int sshkey_save_private(struct sshkey *, const char *,
    const char *, const char *, int, const char *, int);
int sshkey_load_cert(const char *, struct sshkey **);
int sshkey_load_public(const char *, struct sshkey **, char **);
int sshkey_load_private(const char *, const char *, struct sshkey **, char **);
int sshkey_load_private_cert(int, const char *, const char *,
    struct sshkey **);
int sshkey_load_private_type(int, const char *, const char *,
    struct sshkey **, char **);
int sshkey_load_private_type_fd(int fd, int type, const char *passphrase,
    struct sshkey **keyp, char **commentp);
int sshkey_perm_ok(int, const char *);
int sshkey_in_file(struct sshkey *, const char *, int, int);
int sshkey_check_revoked(struct sshkey *key, const char *revoked_keys_file);
int sshkey_advance_past_options(char **cpp);
int sshkey_save_public(const struct sshkey *key, const char *path,
    const char *comment);

struct ssh;


int client_loop(struct ssh *, int, int, int);
int client_x11_get_proto(struct ssh *, const char *, const char *,
     u_int, u_int, char **, char **);
void client_global_request_reply_fwd(int, u_int32_t, void *);
void client_session2_setup(struct ssh *, int, int, int,
     const char *, struct termios *, int, struct sshbuf *, char **);
char *client_request_tun_fwd(struct ssh *, int, int, int,
    channel_open_fn *, void *);
void client_stop_mux(void);


void *client_new_escape_filter_ctx(int);
void client_filter_cleanup(struct ssh *, int, void *);
int client_simple_escape_filter(struct ssh *, Channel *, char *, int);


typedef void global_confirm_cb(struct ssh *, int, u_int32_t, void *);
void client_register_global_confirm(global_confirm_cb *, void *);


enum confirm_action { CONFIRM_WARN = 0, CONFIRM_CLOSE, CONFIRM_TTY };
void client_expect_confirm(struct ssh *, int, const char *,
    enum confirm_action);
void muxserver_listen(struct ssh *);
int muxclient(const char *);
void mux_exit_message(struct ssh *, Channel *, int);
void mux_tty_alloc_failed(struct ssh *ssh, Channel *);
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
struct allowed_cname {
 char *source_list;
 char *target_list;
};

typedef struct {
 int forward_agent;
 char *forward_agent_sock_path;
 int forward_x11;
 int forward_x11_timeout;
 int forward_x11_trusted;
 int exit_on_forward_failure;
 char *xauth_location;
 struct ForwardOptions fwd_opts;
 int pubkey_authentication;
 int hostbased_authentication;
 int gss_authentication;
 int gss_deleg_creds;
 int password_authentication;

 int kbd_interactive_authentication;
 char *kbd_interactive_devices;
 int batch_mode;
 int check_host_ip;
 int strict_host_key_checking;
 int compression;
 int tcp_keep_alive;
 int ip_qos_interactive;
 int ip_qos_bulk;
 SyslogFacility log_facility;
 LogLevel log_level;
 u_int num_log_verbose;
 char **log_verbose;
 int port;
 int address_family;
 int connection_attempts;

 int connection_timeout;

 int number_of_password_prompts;

 char *ciphers;
 char *macs;
 char *hostkeyalgorithms;
 char *kex_algorithms;
 char *ca_sign_algorithms;
 char *hostname;
 char *host_key_alias;
 char *proxy_command;
 char *user;
 int escape_char;

 u_int num_system_hostfiles;
 char *system_hostfiles[32];
 u_int num_user_hostfiles;
 char *user_hostfiles[32];
 char *preferred_authentications;
 char *bind_address;
 char *bind_interface;
 char *pkcs11_provider;
 char *sk_provider;
 int verify_host_key_dns;

 int num_identity_files;
 char *identity_files[100];
 int identity_file_userprovided[100];
 struct sshkey *identity_keys[100];

 int num_certificate_files;
 char *certificate_files[100];
 int certificate_file_userprovided[100];
 struct sshkey *certificates[100];

 int add_keys_to_agent;
 int add_keys_to_agent_lifespan;
 char *identity_agent;


 int num_local_forwards;
 struct Forward *local_forwards;


 int num_remote_forwards;
 struct Forward *remote_forwards;
 int clear_forwardings;


 char **permitted_remote_opens;
 u_int num_permitted_remote_opens;


 char *stdio_forward_host;
 int stdio_forward_port;

 int enable_ssh_keysign;
 int64_t rekey_limit;
 int rekey_interval;
 int no_host_authentication_for_localhost;
 int identities_only;
 int server_alive_interval;
 int server_alive_count_max;

 u_int num_send_env;
 char **send_env;
 u_int num_setenv;
 char **setenv;

 char *control_path;
 int control_master;
 int control_persist;
 int control_persist_timeout;

 int hash_known_hosts;

 int tun_open;
 int tun_local;
 int tun_remote;

 char *local_command;
 int permit_local_command;
 char *remote_command;
 int visual_host_key;

 int request_tty;
 int session_type;
 int stdin_null;
 int fork_after_authentication;

 int proxy_use_fdpass;

 int num_canonical_domains;
 char *canonical_domains[32];
 int canonicalize_hostname;
 int canonicalize_max_dots;
 int canonicalize_fallback_local;
 int num_permitted_cnames;
 struct allowed_cname permitted_cnames[32];

 char *revoked_host_keys;

 int fingerprint_hash;

 int update_hostkeys;

 char *hostbased_accepted_algos;
 char *pubkey_accepted_algos;

 char *jump_user;
 char *jump_host;
 int jump_port;
 char *jump_extra;

 char *known_hosts_command;

 int required_rsa_size;

 char *ignored_unknown;
} Options;
const char *kex_default_pk_alg(void);
char *ssh_connection_hash(const char *thishost, const char *host,
    const char *portstr, const char *user);
void initialize_options(Options *);
int fill_default_options(Options *);
void fill_default_options_for_canonicalization(Options *);
void free_options(Options *o);
int process_config_line(Options *, struct passwd *, const char *,
    const char *, char *, const char *, int, int *, int);
int read_config_file(const char *, struct passwd *, const char *,
    const char *, Options *, int, int *);
int parse_forward(struct Forward *, const char *, int, int);
int parse_jump(const char *, Options *, int);
int parse_ssh_uri(const char *, char **, char **, int *);
int default_ssh_port(void);
int option_clear_or_none(const char *);
int config_has_permitted_cnames(Options *);
void dump_client_config(Options *o, const char *host);

void add_local_forward(Options *, const struct Forward *);
void add_remote_forward(Options *, const struct Forward *);
void add_identity_file(Options *, const char *, const char *, int);
void add_certificate_file(Options *, const char *, int);
typedef struct Sensitive Sensitive;
struct Sensitive {
 struct sshkey **keys;
 int nkeys;
};

struct ssh_conn_info {
 char *conn_hash_hex;
 char *shorthost;
 char *uidstr;
 char *keyalias;
 char *thishost;
 char *host_arg;
 char *portstr;
 char *remhost;
 char *remuser;
 char *homedir;
 char *locuser;
};

struct addrinfo;
struct ssh;
struct hostkeys;
struct ssh_conn_info;
int ssh_connect(struct ssh *, const char *, const char *,
     struct addrinfo *, struct sockaddr_storage *, u_short,
     int, int *, int);
void ssh_kill_proxy_command(void);

void ssh_login(struct ssh *, Sensitive *, const char *,
    struct sockaddr *, u_short, struct passwd *, int,
    const struct ssh_conn_info *);

int verify_host_key(char *, struct sockaddr *, struct sshkey *,
    const struct ssh_conn_info *);

void get_hostfile_hostname_ipaddr(char *, struct sockaddr *, u_short,
    char **, char **);

void ssh_kex2(struct ssh *ssh, char *, struct sockaddr *, u_short,
    const struct ssh_conn_info *);

void ssh_userauth2(struct ssh *ssh, const char *, const char *,
    char *, Sensitive *);

int ssh_local_cmd(const char *);

void maybe_add_key_to_agent(const char *, struct sshkey *,
    const char *, const char *);

void load_hostkeys_command(struct hostkeys *, const char *,
    const char *, const struct ssh_conn_info *,
    const struct sshkey *, const char *);
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
typedef int8_t crypto_int8;
typedef uint8_t crypto_uint8;
typedef int16_t crypto_int16;
typedef uint16_t crypto_uint16;
typedef int32_t crypto_int32;
typedef uint32_t crypto_uint32;
typedef int64_t crypto_int64;
typedef uint64_t crypto_uint64;






int crypto_hash_sha512(unsigned char *, const unsigned char *,
    unsigned long long);

int crypto_verify_32(const unsigned char *, const unsigned char *);





int crypto_sign_ed25519(unsigned char *, unsigned long long *,
    const unsigned char *, unsigned long long, const unsigned char *);
int crypto_sign_ed25519_open(unsigned char *, unsigned long long *,
    const unsigned char *, unsigned long long, const unsigned char *);
int crypto_sign_ed25519_keypair(unsigned char *, unsigned char *);






int crypto_kem_sntrup761_enc(unsigned char *cstr, unsigned char *k,
    const unsigned char *pk);
int crypto_kem_sntrup761_dec(unsigned char *k,
    const unsigned char *cstr, const unsigned char *sk);
int crypto_kem_sntrup761_keypair(unsigned char *pk, unsigned char *sk);




enum kex_init_proposals {
 PROPOSAL_KEX_ALGS,
 PROPOSAL_SERVER_HOST_KEY_ALGS,
 PROPOSAL_ENC_ALGS_CTOS,
 PROPOSAL_ENC_ALGS_STOC,
 PROPOSAL_MAC_ALGS_CTOS,
 PROPOSAL_MAC_ALGS_STOC,
 PROPOSAL_COMP_ALGS_CTOS,
 PROPOSAL_COMP_ALGS_STOC,
 PROPOSAL_LANG_CTOS,
 PROPOSAL_LANG_STOC,
 PROPOSAL_MAX
};

enum kex_modes {
 MODE_IN,
 MODE_OUT,
 MODE_MAX
};

enum kex_exchange {
 KEX_DH_GRP1_SHA1,
 KEX_DH_GRP14_SHA1,
 KEX_DH_GRP14_SHA256,
 KEX_DH_GRP16_SHA512,
 KEX_DH_GRP18_SHA512,
 KEX_DH_GEX_SHA1,
 KEX_DH_GEX_SHA256,
 KEX_ECDH_SHA2,
 KEX_C25519_SHA256,
 KEX_KEM_SNTRUP761X25519_SHA512,
 KEX_MAX
};
struct sshenc {
 char *name;
 const struct sshcipher *cipher;
 int enabled;
 u_int key_len;
 u_int iv_len;
 u_int block_size;
 u_char *key;
 u_char *iv;
};
struct sshcomp {
 u_int type;
 int enabled;
 char *name;
};
struct newkeys {
 struct sshenc enc;
 struct sshmac mac;
 struct sshcomp comp;
};

struct ssh;
struct sshbuf;

struct kex {
 struct newkeys *newkeys[MODE_MAX];
 u_int we_need;
 u_int dh_need;
 int server;
 char *name;
 char *hostkey_alg;
 int hostkey_type;
 int hostkey_nid;
 u_int kex_type;
 char *server_sig_algs;
 int ext_info_c;
 struct sshbuf *my;
 struct sshbuf *peer;
 struct sshbuf *client_version;
 struct sshbuf *server_version;
 struct sshbuf *session_id;
 struct sshbuf *initial_sig;
 struct sshkey *initial_hostkey;
 sig_atomic_t done;
 u_int flags;
 int hash_alg;
 int ec_nid;
 char *failed_choice;
 int (*verify_host_key)(struct sshkey *, struct ssh *);
 struct sshkey *(*load_host_public_key)(int, int, struct ssh *);
 struct sshkey *(*load_host_private_key)(int, int, struct ssh *);
 int (*host_key_index)(struct sshkey *, int, struct ssh *);
 int (*sign)(struct ssh *, struct sshkey *, struct sshkey *,
     u_char **, size_t *, const u_char *, size_t, const char *);
 int (*kex[KEX_MAX])(struct ssh *);

 DH *dh;
 u_int min, max, nbits;
 EC_KEY *ec_client_key;
 const EC_GROUP *ec_group;
 u_char c25519_client_key[32];
 u_char c25519_client_pubkey[32];
 u_char sntrup761_client_key[1763];
 struct sshbuf *client_pub;
};

int kex_names_valid(const char *);
char *kex_alg_list(char);
char *kex_names_cat(const char *, const char *);
int kex_assemble_names(char **, const char *, const char *);

int kex_exchange_identification(struct ssh *, int, const char *);

struct kex *kex_new(void);
int kex_ready(struct ssh *, char *[PROPOSAL_MAX]);
int kex_setup(struct ssh *, char *[PROPOSAL_MAX]);
void kex_free_newkeys(struct newkeys *);
void kex_free(struct kex *);

int kex_buf2prop(struct sshbuf *, int *, char ***);
int kex_prop2buf(struct sshbuf *, char *proposal[PROPOSAL_MAX]);
void kex_prop_free(char **);
int kex_load_hostkey(struct ssh *, struct sshkey **, struct sshkey **);
int kex_verify_host_key(struct ssh *, struct sshkey *);

int kex_send_kexinit(struct ssh *);
int kex_input_kexinit(int, u_int32_t, struct ssh *);
int kex_input_ext_info(int, u_int32_t, struct ssh *);
int kex_protocol_error(int, u_int32_t, struct ssh *);
int kex_derive_keys(struct ssh *, u_char *, u_int, const struct sshbuf *);
int kex_send_newkeys(struct ssh *);
int kex_start_rekex(struct ssh *);

int kexgex_client(struct ssh *);
int kexgex_server(struct ssh *);
int kex_gen_client(struct ssh *);
int kex_gen_server(struct ssh *);

int kex_dh_keypair(struct kex *);
int kex_dh_enc(struct kex *, const struct sshbuf *, struct sshbuf **,
    struct sshbuf **);
int kex_dh_dec(struct kex *, const struct sshbuf *, struct sshbuf **);

int kex_ecdh_keypair(struct kex *);
int kex_ecdh_enc(struct kex *, const struct sshbuf *, struct sshbuf **,
    struct sshbuf **);
int kex_ecdh_dec(struct kex *, const struct sshbuf *, struct sshbuf **);

int kex_c25519_keypair(struct kex *);
int kex_c25519_enc(struct kex *, const struct sshbuf *, struct sshbuf **,
    struct sshbuf **);
int kex_c25519_dec(struct kex *, const struct sshbuf *, struct sshbuf **);

int kex_kem_sntrup761x25519_keypair(struct kex *);
int kex_kem_sntrup761x25519_enc(struct kex *, const struct sshbuf *,
    struct sshbuf **, struct sshbuf **);
int kex_kem_sntrup761x25519_dec(struct kex *, const struct sshbuf *,
    struct sshbuf **);

int kex_dh_keygen(struct kex *);
int kex_dh_compute_key(struct kex *, BIGNUM *, struct sshbuf *);

int kexgex_hash(int, const struct sshbuf *, const struct sshbuf *,
    const struct sshbuf *, const struct sshbuf *, const struct sshbuf *,
    int, int, int,
    const BIGNUM *, const BIGNUM *, const BIGNUM *,
    const BIGNUM *, const u_char *, size_t,
    u_char *, size_t *);

void kexc25519_keygen(u_char key[32], u_char pub[32])
 __attribute__(())
 __attribute__(());
int kexc25519_shared_key(const u_char key[32],
    const u_char pub[32], struct sshbuf *out)
 __attribute__(())
 __attribute__(());
int kexc25519_shared_key_ext(const u_char key[32],
    const u_char pub[32], struct sshbuf *out, int)
 __attribute__(())
 __attribute__(());

struct termios *get_saved_tio(void);
void leave_raw_mode(int);
void enter_raw_mode(int);

int pty_allocate(int *, int *, char *, size_t);
void pty_release(const char *);
void pty_make_controlling_tty(int *, const char *);
void pty_change_window_size(int, u_int, u_int, u_int, u_int);
void pty_setowner(struct passwd *, const char *);
void disconnect_controlling_tty(void);
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
struct sshbuf;
int ssh_msg_send(int, u_char, struct sshbuf *);
int ssh_msg_recv(int, struct sshbuf *);

int vasnmprintf(char **, size_t, int *, const char *, va_list);
int mprintf(const char *, ...)
     __attribute__((format(printf, 1, 2)));
int fmprintf(FILE *, const char *, ...)
     __attribute__((format(printf, 2, 3)));
int vfmprintf(FILE *, const char *, va_list);
int snmprintf(char *, size_t, int *, const char *, ...)
     __attribute__((format(printf, 4, 5)));
int asmprintf(char **, size_t, int *, const char *, ...)
     __attribute__((format(printf, 4, 5)));
void msetlocale(void);


int pkcs11_init(int);
void pkcs11_terminate(void);
int pkcs11_add_provider(char *, char *, struct sshkey ***, char ***);
int pkcs11_del_provider(char *);


extern char *__progname;



static char **saved_av;



int debug_flag = 0;


int tty_flag = 0;





int need_controlpersist_detach = 0;


int ostdin_null_flag, osession_type, otty_flag, orequest_tty;





Options options;


char *config = 
              ((void *)0)
                  ;






char *host;





char *forward_agent_sock_path = 
                               ((void *)0)
                                   ;


struct sockaddr_storage hostaddr;


Sensitive sensitive_data;


struct sshbuf *command;


static int forward_confirms_pending = -1;


extern int muxserver_sock;
extern u_int muxclient_command;



static void
usage(void)
{
 fprintf(
        stderr
              ,
"usage: ssh [-46AaCfGgKkMNnqsTtVvXxYy] [-B bind_interface]\n"
"           [-b bind_address] [-c cipher_spec] [-D [bind_address:]port]\n"
"           [-E log_file] [-e escape_char] [-F configfile] [-I pkcs11]\n"
"           [-i identity_file] [-J [user@]host[:port]] [-L address]\n"
"           [-l login_name] [-m mac_spec] [-O ctl_cmd] [-o option] [-p port]\n"
"           [-Q query_option] [-R address] [-S ctl_path] [-W host:port]\n"
"           [-w local_tun[:remote_tun]] destination [command [argument ...]]\n"
 );
 exit(255);
}

static int ssh_session2(struct ssh *, const struct ssh_conn_info *);
static void load_public_identity_files(const struct ssh_conn_info *);
static void main_sigchld_handler(int);


static void
tilde_expand_paths(char **paths, u_int num_paths)
{
 u_int i;
 char *cp;

 for (i = 0; i < num_paths; i++) {
  cp = tilde_expand_filename(paths[i], getuid());
  free(paths[i]);
  paths[i] = cp;
 }
}






static char *
default_client_percent_expand(const char *str,
    const struct ssh_conn_info *cinfo)
{
 return percent_expand(str,
     "C", cinfo->conn_hash_hex, "L", cinfo->shorthost, "i", cinfo->uidstr, "k", cinfo->keyalias, "l", cinfo->thishost, "n", cinfo->host_arg, "p", cinfo->portstr, "d", cinfo->homedir, "h", cinfo->remhost, "r", cinfo->remuser, "u", cinfo->locuser,
     (char *)
            ((void *)0)
                );
}






static char *
default_client_percent_dollar_expand(const char *str,
    const struct ssh_conn_info *cinfo)
{
 char *ret;

 ret = percent_dollar_expand(str,
     "C", cinfo->conn_hash_hex, "L", cinfo->shorthost, "i", cinfo->uidstr, "k", cinfo->keyalias, "l", cinfo->thishost, "n", cinfo->host_arg, "p", cinfo->portstr, "d", cinfo->homedir, "h", cinfo->remhost, "r", cinfo->remuser, "u", cinfo->locuser,
     (char *)
            ((void *)0)
                );
 if (ret == 
           ((void *)0)
               )
  sshfatal("ssh.c", __func__, 240, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "invalid environment variable expansion");
 return ret;
}







static struct addrinfo *
resolve_host(const char *name, int port, int logerr, char *cname, size_t clen)
{
 char strport[
             32
                       ];
 struct addrinfo hints, *res;
 int gaierr;
 LogLevel loglevel = SYSLOG_LEVEL_DEBUG1;

 if (port <= 0)
  port = default_ssh_port();
 if (cname != 
             ((void *)0)
                 )
  *cname = '\0';
 sshlog("ssh.c", __func__, 262, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "lookup %s:%d", name, port);

 snprintf(strport, sizeof strport, "%d", port);
 memset(&hints, 0, sizeof(hints));
 hints.ai_family = options.address_family == -1 ?
     
    0 
              : options.address_family;
 hints.ai_socktype = 
                    SOCK_STREAM
                               ;
 if (cname != 
             ((void *)0)
                 )
  hints.ai_flags = 
                  0x0002
                              ;
 if ((gaierr = getaddrinfo(name, strport, &hints, &res)) != 0) {
  if (logerr || (gaierr != 
                          -2 
                                     && gaierr != 
                                                  -5
                                                            ))
   loglevel = SYSLOG_LEVEL_ERROR;
  sshlog("ssh.c", __func__, 274, 0, loglevel, 
 ((void *)0)
 , "%s: Could not resolve hostname %.100s: %s", __progname, name, ssh_gai_strerror(gaierr))
                                                 ;
  return 
        ((void *)0)
            ;
 }
 if (cname != 
             ((void *)0) 
                  && res->ai_canonname != 
                                          ((void *)0)
                                              ) {
  if (strlcpy(cname, res->ai_canonname, clen) >= clen) {
   sshlog("ssh.c", __func__, 280, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "host \"%s\" cname \"%s\" too long (max %lu)", name, res->ai_canonname, (u_long)clen)
                                              ;
   if (clen > 0)
    *cname = '\0';
  }
 }
 return res;
}


static int
is_addr_fast(const char *name)
{
 return (strchr(name, '%') != 
                             ((void *)0) 
                                  || strchr(name, ':') != 
                                                          ((void *)0) 
                                                               ||
     strspn(name, "0123456789.") == strlen(name));
}


static int
is_addr(const char *name)
{
 char strport[
             32
                       ];
 struct addrinfo hints, *res;

 if (is_addr_fast(name))
  return 1;

 snprintf(strport, sizeof strport, "%u", default_ssh_port());
 memset(&hints, 0, sizeof(hints));
 hints.ai_family = options.address_family == -1 ?
     
    0 
              : options.address_family;
 hints.ai_socktype = 
                    SOCK_STREAM
                               ;
 hints.ai_flags = 
                 0x0004
                               |
                                0x0400
                                              ;
 if (getaddrinfo(name, strport, &hints, &res) != 0)
  return 0;
 if (res == 
           ((void *)0) 
                || res->ai_next != 
                                   ((void *)0)
                                       ) {
  freeaddrinfo(res);
  return 0;
 }
 freeaddrinfo(res);
 return 1;
}







static struct addrinfo *
resolve_addr(const char *name, int port, char *caddr, size_t clen)
{
 char addr[
          1025
                    ], strport[
                               32
                                         ];
 struct addrinfo hints, *res;
 int gaierr;

 if (port <= 0)
  port = default_ssh_port();
 snprintf(strport, sizeof strport, "%u", port);
 memset(&hints, 0, sizeof(hints));
 hints.ai_family = options.address_family == -1 ?
     
    0 
              : options.address_family;
 hints.ai_socktype = 
                    SOCK_STREAM
                               ;
 hints.ai_flags = 
                 0x0004
                               |
                                0x0400
                                              ;
 if ((gaierr = getaddrinfo(name, strport, &hints, &res)) != 0) {
  sshlog("ssh.c", __func__, 345, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "could not resolve name %.100s as address: %s", name, ssh_gai_strerror(gaierr))
                                     ;
  return 
        ((void *)0)
            ;
 }
 if (res == 
           ((void *)0)
               ) {
  sshlog("ssh.c", __func__, 350, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "getaddrinfo %.100s returned no addresses", name);
  return 
        ((void *)0)
            ;
 }
 if (res->ai_next != 
                    ((void *)0)
                        ) {
  sshlog("ssh.c", __func__, 354, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "getaddrinfo %.100s returned multiple addresses", name);
  goto fail;
 }
 if ((gaierr = getnameinfo(res->ai_addr, res->ai_addrlen,
     addr, sizeof(addr), 
                        ((void *)0)
                            , 0, 
                                 1
                                               )) != 0) {
  sshlog("ssh.c", __func__, 359, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Could not format address for name %.100s: %s", name, ssh_gai_strerror(gaierr))
                                     ;
  goto fail;
 }
 if (strlcpy(caddr, addr, clen) >= clen) {
  sshlog("ssh.c", __func__, 364, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "host \"%s\" addr \"%s\" too long (max %lu)", name, addr, (u_long)clen)
                                ;
  if (clen > 0)
   *caddr = '\0';
 fail:
  freeaddrinfo(res);
  return 
        ((void *)0)
            ;
 }
 return res;
}






static int
check_follow_cname(int direct, char **namep, const char *cname)
{
 int i;
 struct allowed_cname *rule;

 if (*cname == '\0' || !config_has_permitted_cnames(&options) ||
     strcmp(*namep, cname) == 0)
  return 0;
 if (options.canonicalize_hostname == 0)
  return 0;




 if (!direct &&
     options.canonicalize_hostname != 2)
  return 0;
 sshlog("ssh.c", __func__, 398, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "check \"%s\" CNAME \"%s\"", *namep, cname);
 for (i = 0; i < options.num_permitted_cnames; i++) {
  rule = options.permitted_cnames + i;
  if (match_pattern_list(*namep, rule->source_list, 1) != 1 ||
      match_pattern_list(cname, rule->target_list, 1) != 1)
   continue;
  sshlog("ssh.c", __func__, 404, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "Canonicalized DNS aliased hostname " "\"%s\" => \"%s\"", *namep, cname)
                                        ;
  free(*namep);
  *namep = xstrdup(cname);
  return 1;
 }
 return 0;
}







static struct addrinfo *
resolve_canonicalize(char **hostp, int port)
{
 int i, direct, ndots;
 char *cp, *fullhost, newname[
                             1025
                                       ];
 struct addrinfo *addrs;





 if ((addrs = resolve_addr(*hostp, port,
     newname, sizeof(newname))) != 
                                  ((void *)0)
                                      ) {
  sshlog("ssh.c", __func__, 432, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "hostname %.100s is address", *hostp);
  if (strcasecmp(*hostp, newname) != 0) {
   sshlog("ssh.c", __func__, 434, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "canonicalised address \"%s\" => \"%s\"", *hostp, newname)
                       ;
   free(*hostp);
   *hostp = xstrdup(newname);
  }
  return addrs;
 }






 if (is_addr_fast(*hostp)) {
  sshlog("ssh.c", __func__, 448, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "hostname %.100s is an unrecognised address", *hostp);
  return 
        ((void *)0)
            ;
 }

 if (options.canonicalize_hostname == 0)
  return 
        ((void *)0)
            ;





 direct = option_clear_or_none(options.proxy_command) &&
     options.jump_host == 
                         ((void *)0)
                             ;
 if (!direct &&
     options.canonicalize_hostname != 2)
  return 
        ((void *)0)
            ;


 if ((*hostp)[strlen(*hostp) - 1] == '.') {
  sshlog("ssh.c", __func__, 467, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "name is fully qualified");
  fullhost = xstrdup(*hostp);
  if ((addrs = resolve_host(fullhost, port, 0,
      newname, sizeof(newname))) != 
                                   ((void *)0)
                                       )
   goto found;
  free(fullhost);
  goto notfound;
 }


 ndots = 0;
 for (cp = *hostp; *cp != '\0'; cp++) {
  if (*cp == '.')
   ndots++;
 }
 if (ndots > options.canonicalize_max_dots) {
  sshlog("ssh.c", __func__, 483, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "not canonicalizing hostname \"%s\" (max dots %d)", *hostp, options.canonicalize_max_dots)
                                            ;
  return 
        ((void *)0)
            ;
 }

 for (i = 0; i < options.num_canonical_domains; i++) {
  if (strcasecmp(options.canonical_domains[i], "none") == 0)
   break;
  xasprintf(&fullhost, "%s.%s.", *hostp,
      options.canonical_domains[i]);
  sshlog("ssh.c", __func__, 493, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "attempting \"%s\" => \"%s\"", *hostp, fullhost);
  if ((addrs = resolve_host(fullhost, port, 0,
      newname, sizeof(newname))) == 
                                   ((void *)0)
                                       ) {
   free(fullhost);
   continue;
  }
 found:

  fullhost[strlen(fullhost) - 1] = '\0';

  if (!check_follow_cname(direct, &fullhost, newname)) {
   sshlog("ssh.c", __func__, 504, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Canonicalized hostname \"%s\" => \"%s\"", *hostp, fullhost)
                        ;
  }
  free(*hostp);
  *hostp = fullhost;
  return addrs;
 }
 notfound:
 if (!options.canonicalize_fallback_local)
  sshfatal("ssh.c", __func__, 513, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: Could not resolve host \"%s\"", __progname, *hostp);
 sshlog("ssh.c", __func__, 514, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "host %s not found in any suffix", *hostp);
 return 
       ((void *)0)
           ;
}





static void
check_load(int r, struct sshkey **k, const char *path, const char *message)
{
 switch (r) {
 case 0:

  if (k != 
          ((void *)0) 
               && *k != 
                        ((void *)0) 
                             &&
      (r = sshkey_check_rsa_length(*k,
      options.required_rsa_size)) != 0) {
   sshlog("ssh.c", __func__, 531, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "load %s \"%s\"", message, path);
   free(*k);
   *k = 
       ((void *)0)
           ;
  }
  break;
 case -1:
 case -2:
  sshfatal("ssh.c", __func__, 538, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "load %s \"%s\"", message, path);
 case -24:

  if (
     (*__errno_location ()) 
           == 
              2
                    )
   break;

 default:
  sshlog("ssh.c", __func__, 545, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "load %s \"%s\"", message, path);
  break;
 }
}





static void
process_config_files(const char *host_name, struct passwd *pw, int final_pass,
    int *want_final_pass)
{
 char buf[
         4096
                 ];
 int r;

 if (config != 
              ((void *)0)
                  ) {
  if (strcasecmp(config, "none") != 0 &&
      !read_config_file(config, pw, host, host_name, &options,
      2 | (final_pass ? 4 : 0),
      want_final_pass))
   sshfatal("ssh.c", __func__, 566, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Can't open user config file %.100s: " "%.100s", config, strerror(
  (*__errno_location ())
  ))
                                         ;
 } else {
  r = snprintf(buf, sizeof buf, "%s/%s", pw->pw_dir,
      ".ssh" "/config");
  if (r > 0 && (size_t)r < sizeof(buf))
   (void)read_config_file(buf, pw, host, host_name,
       &options, 1 | 2 |
       (final_pass ? 4 : 0), want_final_pass);


  (void)read_config_file("/usr/local/etc" "/ssh_config", pw,
      host, host_name, &options,
      final_pass ? 4 : 0, want_final_pass);
 }
}


static void
set_addrinfo_port(struct addrinfo *addrs, int port)
{
 struct addrinfo *addr;

 for (addr = addrs; addr != 
                           ((void *)0)
                               ; addr = addr->ai_next) {
  switch (addr->ai_family) {
  case 
      2
             :
   ((struct sockaddr_in *)addr->ai_addr)->
       sin_port = 
                 __bswap_16 (
                 port
                 )
                            ;
   break;
  case 
      10
              :
   ((struct sockaddr_in6 *)addr->ai_addr)->
       sin6_port = 
                  __bswap_16 (
                  port
                  )
                             ;
   break;
  }
 }
}

static void
ssh_conn_info_free(struct ssh_conn_info *cinfo)
{
 if (cinfo == 
             ((void *)0)
                 )
  return;
 free(cinfo->conn_hash_hex);
 free(cinfo->shorthost);
 free(cinfo->uidstr);
 free(cinfo->keyalias);
 free(cinfo->thishost);
 free(cinfo->host_arg);
 free(cinfo->portstr);
 free(cinfo->remhost);
 free(cinfo->remuser);
 free(cinfo->homedir);
 free(cinfo->locuser);
 free(cinfo);
}




int
main(int ac, char **av)
{
 struct ssh *ssh = 
                  ((void *)0)
                      ;
 int i, r, opt, exit_status, use_syslog, direct, timeout_ms;
 int was_addr, config_test = 0, opt_terminated = 0, want_final_pass = 0;
 char *p, *cp, *line, *argv0, *logfile, *host_arg;
 char cname[
           1025
                     ], thishost[
                                 1025
                                           ];
 struct stat st;
 struct passwd *pw;
 extern int BSDoptind, BSDoptreset;
 extern char *BSDoptarg;
 struct Forward fwd;
 struct addrinfo *addrs = 
                         ((void *)0)
                             ;
 size_t n, len;
 u_int j;
 struct ssh_conn_info *cinfo = 
                              ((void *)0)
                                  ;


 sanitise_stdfd();





 closefrom(
          2 
                        + 1);

 __progname = ssh_get_progname(av[0]);




 saved_av = xcalloc(ac + 1, sizeof(*saved_av));
 for (i = 0; i < ac; i++)
  saved_av[i] = xstrdup(av[i]);
 saved_av[i] = 
              ((void *)0)
                  ;
 compat_init_setproctitle(ac, av);
 av = saved_av;


 seed_rng();


 pw = getpwuid(getuid());
 if (!pw) {
  sshlog("ssh.c", __func__, 670, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "No user exists for uid %lu", (u_long)getuid());
  exit(255);
 }

 pw = pwcopy(pw);







 umask(022);

 msetlocale();





 initialize_options(&options);




 if ((ssh = ssh_alloc_session_state()) == 
                                         ((void *)0)
                                             )
  sshfatal("ssh.c", __func__, 696, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Couldn't allocate session state");
 channel_init_channels(ssh);


 host = 
       ((void *)0)
           ;
 use_syslog = 0;
 logfile = 
          ((void *)0)
              ;
 argv0 = av[0];

 again:
 while ((opt = BSDgetopt(ac, av, "1246ab:c:e:fgi:kl:m:no:p:qstvx" "AB:CD:E:F:GI:J:KL:MNO:PQ:R:S:TVw:W:XYy")
                                              ) != -1) {
  switch (opt) {
  case '1':
   sshfatal("ssh.c", __func__, 710, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "SSH protocol v.1 is no longer supported");
   break;
  case '2':

   break;
  case '4':
   options.address_family = 
                           2
                                  ;
   break;
  case '6':
   options.address_family = 
                           10
                                   ;
   break;
  case 'n':
   options.stdin_null = 1;
   break;
  case 'f':
   options.fork_after_authentication = 1;
   options.stdin_null = 1;
   break;
  case 'x':
   options.forward_x11 = 0;
   break;
  case 'X':
   options.forward_x11 = 1;
   break;
  case 'y':
   use_syslog = 1;
   break;
  case 'E':
   logfile = BSDoptarg;
   break;
  case 'G':
   config_test = 1;
   break;
  case 'Y':
   options.forward_x11 = 1;
   options.forward_x11_trusted = 1;
   break;
  case 'g':
   options.fwd_opts.gateway_ports = 1;
   break;
  case 'O':
   if (options.stdio_forward_host != 
                                    ((void *)0)
                                        )
    sshfatal("ssh.c", __func__, 752, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Cannot specify multiplexing " "command with -W")
                          ;
   else if (muxclient_command != 0)
    sshfatal("ssh.c", __func__, 755, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Multiplexing command already specified");
   if (strcmp(BSDoptarg, "check") == 0)
    muxclient_command = 2;
   else if (strcmp(BSDoptarg, "forward") == 0)
    muxclient_command = 5;
   else if (strcmp(BSDoptarg, "exit") == 0)
    muxclient_command = 3;
   else if (strcmp(BSDoptarg, "stop") == 0)
    muxclient_command = 6;
   else if (strcmp(BSDoptarg, "cancel") == 0)
    muxclient_command = 7;
   else if (strcmp(BSDoptarg, "proxy") == 0)
    muxclient_command = 8;
   else
    sshfatal("ssh.c", __func__, 769, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Invalid multiplex command.");
   break;
  case 'P':
   break;
  case 'Q':
   cp = 
       ((void *)0)
           ;
   if (strcmp(BSDoptarg, "cipher") == 0 ||
       strcasecmp(BSDoptarg, "Ciphers") == 0)
    cp = cipher_alg_list('\n', 0);
   else if (strcmp(BSDoptarg, "cipher-auth") == 0)
    cp = cipher_alg_list('\n', 1);
   else if (strcmp(BSDoptarg, "mac") == 0 ||
       strcasecmp(BSDoptarg, "MACs") == 0)
    cp = mac_alg_list('\n');
   else if (strcmp(BSDoptarg, "kex") == 0 ||
       strcasecmp(BSDoptarg, "KexAlgorithms") == 0)
    cp = kex_alg_list('\n');
   else if (strcmp(BSDoptarg, "key") == 0)
    cp = sshkey_alg_list(0, 0, 0, '\n');
   else if (strcmp(BSDoptarg, "key-cert") == 0)
    cp = sshkey_alg_list(1, 0, 0, '\n');
   else if (strcmp(BSDoptarg, "key-plain") == 0)
    cp = sshkey_alg_list(0, 1, 0, '\n');
   else if (strcmp(BSDoptarg, "key-sig") == 0 ||
       strcasecmp(BSDoptarg, "PubkeyAcceptedKeyTypes") == 0 ||
       strcasecmp(BSDoptarg, "PubkeyAcceptedAlgorithms") == 0 ||
       strcasecmp(BSDoptarg, "HostKeyAlgorithms") == 0 ||
       strcasecmp(BSDoptarg, "HostbasedKeyTypes") == 0 ||
       strcasecmp(BSDoptarg, "HostbasedAcceptedKeyTypes") == 0 ||
       strcasecmp(BSDoptarg, "HostbasedAcceptedAlgorithms") == 0)
    cp = sshkey_alg_list(0, 0, 1, '\n');
   else if (strcmp(BSDoptarg, "sig") == 0)
    cp = sshkey_alg_list(0, 1, 1, '\n');
   else if (strcmp(BSDoptarg, "protocol-version") == 0)
    cp = xstrdup("2");
   else if (strcmp(BSDoptarg, "compression") == 0) {
    cp = xstrdup(compression_alg_list(0));
    len = strlen(cp);
    for (n = 0; n < len; n++)
     if (cp[n] == ',')
      cp[n] = '\n';
   } else if (strcmp(BSDoptarg, "help") == 0) {
    cp = xstrdup(
        "cipher\ncipher-auth\ncompression\nkex\n"
        "key\nkey-cert\nkey-plain\nkey-sig\nmac\n"
        "protocol-version\nsig");
   }
   if (cp == 
            ((void *)0)
                )
    sshfatal("ssh.c", __func__, 817, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Unsupported query \"%s\"", BSDoptarg);
   printf("%s\n", cp);
   free(cp);
   exit(0);
   break;
  case 'a':
   options.forward_agent = 0;
   break;
  case 'A':
   options.forward_agent = 1;
   break;
  case 'k':
   options.gss_deleg_creds = 0;
   break;
  case 'K':
   options.gss_authentication = 1;
   options.gss_deleg_creds = 1;
   break;
  case 'i':
   p = tilde_expand_filename(BSDoptarg, getuid());
   if (stat(p, &st) == -1)
    fprintf(
           stderr
                 , "Warning: Identity file %s "
        "not accessible: %s.\n", p,
        strerror(
                (*__errno_location ())
                     ));
   else
    add_identity_file(&options, 
                               ((void *)0)
                                   , p, 1);
   free(p);
   break;
  case 'I':

   free(options.pkcs11_provider);
   options.pkcs11_provider = xstrdup(BSDoptarg);



   break;
  case 'J':
   if (options.jump_host != 
                           ((void *)0)
                               ) {
    sshfatal("ssh.c", __func__, 855, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Only a single -J option is permitted " "(use commas to separate multiple " "jump hops)")

                     ;
   }
   if (options.proxy_command != 
                               ((void *)0)
                                   )
    sshfatal("ssh.c", __func__, 860, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Cannot specify -J with ProxyCommand");
   if (parse_jump(BSDoptarg, &options, 1) == -1)
    sshfatal("ssh.c", __func__, 862, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Invalid -J argument");
   options.proxy_command = xstrdup("none");
   break;
  case 't':
   if (options.request_tty == 2)
    options.request_tty = 3;
   else
    options.request_tty = 2;
   break;
  case 'v':
   if (debug_flag == 0) {
    debug_flag = 1;
    options.log_level = SYSLOG_LEVEL_DEBUG1;
   } else {
    if (options.log_level < SYSLOG_LEVEL_DEBUG3) {
     debug_flag++;
     options.log_level++;
    }
   }
   break;
  case 'V':
   fprintf(
          stderr
                , "%s, %s\n",
       "OpenSSH_9.1" "p1", OpenSSL_version(
                   0
                   ));
   if (opt == 'V')
    exit(0);
   break;
  case 'w':
   if (options.tun_open == -1)
    options.tun_open = 0x01;
   options.tun_local = a2tun(BSDoptarg, &options.tun_remote);
   if (options.tun_local == (0x7fffffff - 1)) {
    fprintf(
           stderr
                 ,
        "Bad tun device '%s'\n", BSDoptarg);
    exit(255);
   }
   break;
  case 'W':
   if (options.stdio_forward_host != 
                                    ((void *)0)
                                        )
    sshfatal("ssh.c", __func__, 900, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "stdio forward already specified");
   if (muxclient_command != 0)
    sshfatal("ssh.c", __func__, 902, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Cannot specify stdio forward with -O");
   if (parse_forward(&fwd, BSDoptarg, 1, 0)) {
    options.stdio_forward_host = fwd.listen_host;
    options.stdio_forward_port = fwd.listen_port;
    free(fwd.connect_host);
   } else {
    fprintf(
           stderr
                 ,
        "Bad stdio forwarding specification '%s'\n",
        BSDoptarg);
    exit(255);
   }
   options.request_tty = 1;
   options.session_type = 0;
   break;
  case 'q':
   options.log_level = SYSLOG_LEVEL_QUIET;
   break;
  case 'e':
   if (BSDoptarg[0] == '^' && BSDoptarg[2] == 0 &&
       (u_char) BSDoptarg[1] >= 64 &&
       (u_char) BSDoptarg[1] < 128)
    options.escape_char = (u_char) BSDoptarg[1] & 31;
   else if (strlen(BSDoptarg) == 1)
    options.escape_char = (u_char) BSDoptarg[0];
   else if (strcmp(BSDoptarg, "none") == 0)
    options.escape_char = -2;
   else {
    fprintf(
           stderr
                 , "Bad escape character '%s'.\n",
        BSDoptarg);
    exit(255);
   }
   break;
  case 'c':
   if (!ciphers_valid(*BSDoptarg == '+' || *BSDoptarg == '^' ?
       BSDoptarg + 1 : BSDoptarg)) {
    fprintf(
           stderr
                 , "Unknown cipher type '%s'\n",
        BSDoptarg);
    exit(255);
   }
   free(options.ciphers);
   options.ciphers = xstrdup(BSDoptarg);
   break;
  case 'm':
   if (mac_valid(BSDoptarg)) {
    free(options.macs);
    options.macs = xstrdup(BSDoptarg);
   } else {
    fprintf(
           stderr
                 , "Unknown mac type '%s'\n",
        BSDoptarg);
    exit(255);
   }
   break;
  case 'M':
   if (options.control_master == 1)
    options.control_master = 3;
   else
    options.control_master = 1;
   break;
  case 'p':
   if (options.port == -1) {
    options.port = a2port(BSDoptarg);
    if (options.port <= 0) {
     fprintf(
            stderr
                  , "Bad port '%s'\n",
         BSDoptarg);
     exit(255);
    }
   }
   break;
  case 'l':
   if (options.user == 
                      ((void *)0)
                          )
    options.user = BSDoptarg;
   break;

  case 'L':
   if (parse_forward(&fwd, BSDoptarg, 0, 0))
    add_local_forward(&options, &fwd);
   else {
    fprintf(
           stderr
                 ,
        "Bad local forwarding specification '%s'\n",
        BSDoptarg);
    exit(255);
   }
   break;

  case 'R':
   if (parse_forward(&fwd, BSDoptarg, 0, 1) ||
       parse_forward(&fwd, BSDoptarg, 1, 1)) {
    add_remote_forward(&options, &fwd);
   } else {
    fprintf(
           stderr
                 ,
        "Bad remote forwarding specification "
        "'%s'\n", BSDoptarg);
    exit(255);
   }
   break;

  case 'D':
   if (parse_forward(&fwd, BSDoptarg, 1, 0)) {
    add_local_forward(&options, &fwd);
   } else {
    fprintf(
           stderr
                 ,
        "Bad dynamic forwarding specification "
        "'%s'\n", BSDoptarg);
    exit(255);
   }
   break;

  case 'C':

   options.compression = 1;



   break;
  case 'N':
   if (options.session_type != -1 &&
       options.session_type != 0)
    sshfatal("ssh.c", __func__, 1019, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Cannot specify -N with -s/SessionType");
   options.session_type = 0;
   options.request_tty = 1;
   break;
  case 'T':
   options.request_tty = 1;
   break;
  case 'o':
   line = xstrdup(BSDoptarg);
   if (process_config_line(&options, pw,
       host ? host : "", host ? host : "", line,
       "command-line", 0, 
                         ((void *)0)
                             , 2) != 0)
    exit(255);
   free(line);
   break;
  case 's':
   if (options.session_type != -1 &&
       options.session_type != 1)
    sshfatal("ssh.c", __func__, 1037, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Cannot specify -s with -N/SessionType");
   options.session_type = 1;
   break;
  case 'S':
   free(options.control_path);
   options.control_path = xstrdup(BSDoptarg);
   break;
  case 'b':
   options.bind_address = BSDoptarg;
   break;
  case 'B':
   options.bind_interface = BSDoptarg;
   break;
  case 'F':
   config = BSDoptarg;
   break;
  default:
   usage();
  }
 }

 if (BSDoptind > 1 && strcmp(av[BSDoptind - 1], "--") == 0)
  opt_terminated = 1;

 ac -= BSDoptind;
 av += BSDoptind;

 if (ac > 0 && !host) {
  int tport;
  char *tuser;
  switch (parse_ssh_uri(*av, &tuser, &host, &tport)) {
  case -1:
   usage();
   break;
  case 0:
   if (options.user == 
                      ((void *)0)
                          ) {
    options.user = tuser;
    tuser = 
           ((void *)0)
               ;
   }
   free(tuser);
   if (options.port == -1 && tport != -1)
    options.port = tport;
   break;
  default:
   p = xstrdup(*av);
   cp = strrchr(p, '@');
   if (cp != 
            ((void *)0)
                ) {
    if (cp == p)
     usage();
    if (options.user == 
                       ((void *)0)
                           ) {
     options.user = p;
     p = 
        ((void *)0)
            ;
    }
    *cp++ = '\0';
    host = xstrdup(cp);
    free(p);
   } else
    host = p;
   break;
  }
  if (ac > 1 && !opt_terminated) {
   BSDoptind = BSDoptreset = 1;
   goto again;
  }
  ac--, av++;
 }


 if (!host)
  usage();

 host_arg = xstrdup(host);


 if ((command = sshbuf_new()) == 
                                ((void *)0)
                                    )
  sshfatal("ssh.c", __func__, 1112, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");






 if (!ac) {

  if (options.session_type == 1) {
   fprintf(
          stderr
                ,
       "You must specify a subsystem to invoke.\n");
   usage();
  }
 } else {

  for (i = 0; i < ac; i++) {
   if ((r = sshbuf_putf(command, "%s%s",
       i ? " " : "", av[i])) != 0)
    sshfatal("ssh.c", __func__, 1131, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "buffer error");
  }
 }

 ssh_signal(
           13
                  , 
                    ((__sighandler_t) 1)
                           );





 if (use_syslog && logfile != 
                             ((void *)0)
                                 )
  sshfatal("ssh.c", __func__, 1142, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Can't specify both -y and -E");
 if (logfile != 
               ((void *)0)
                   )
  log_redirect_stderr_to(logfile);
 log_init(argv0,
     options.log_level == SYSLOG_LEVEL_NOT_SET ?
     SYSLOG_LEVEL_INFO : options.log_level,
     options.log_facility == SYSLOG_FACILITY_NOT_SET ?
     SYSLOG_FACILITY_USER : options.log_facility,
     !use_syslog);

 if (debug_flag)
  sshlog("ssh.c", __func__, 1153, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "%s, %s", "OpenSSH_9.1" "p1", OpenSSL_version(
 0
 ));


 process_config_files(host_arg, pw, 0, &want_final_pass);
 if (want_final_pass)
  sshlog("ssh.c", __func__, 1158, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "configuration requests final Match pass");


 fill_default_options_for_canonicalization(&options);


 if (options.hostname != 
                        ((void *)0)
                            ) {

  cp = percent_expand(options.hostname,
      "h", host, (char *)
                        ((void *)0)
                            );
  free(host);
  host = cp;
  free(options.hostname);
  options.hostname = xstrdup(host);
 }


 if ((was_addr = is_addr(host)) == 0)
  lowercase(host);





 if (options.canonicalize_hostname != 0 || was_addr)
  addrs = resolve_canonicalize(&host, options.port);
 direct = option_clear_or_none(options.proxy_command) &&
     options.jump_host == 
                         ((void *)0)
                             ;
 if (addrs == 
             ((void *)0) 
                  && config_has_permitted_cnames(&options) && (direct ||
     options.canonicalize_hostname == 2)) {
  if ((addrs = resolve_host(host, options.port,
      direct, cname, sizeof(cname))) == 
                                       ((void *)0)
                                           ) {

   if (direct)
    cleanup_exit(255);
  } else
   check_follow_cname(direct, &host, cname);
 }





 if (options.canonicalize_hostname != 0 && !want_final_pass) {
  sshlog("ssh.c", __func__, 1216, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "hostname canonicalisation enabled, " "will re-parse configuration")
                                    ;
  want_final_pass = 1;
 }

 if (want_final_pass) {
  sshlog("ssh.c", __func__, 1222, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "re-parsing configuration");
  free(options.hostname);
  options.hostname = xstrdup(host);
  process_config_files(host_arg, pw, 1, 
                                       ((void *)0)
                                           );





  if (addrs != 
              ((void *)0) 
                   && options.port > 0)
   set_addrinfo_port(addrs, options.port);
 }


 if (fill_default_options(&options) != 0)
  cleanup_exit(255);

 if (options.user == 
                    ((void *)0)
                        )
  options.user = xstrdup(pw->pw_name);




 if (options.jump_host != 
                         ((void *)0)
                             ) {
  char port_s[8];
  const char *jumpuser = options.jump_user, *sshbin = argv0;
  int port = options.port, jumpport = options.jump_port;

  if (port <= 0)
   port = default_ssh_port();
  if (jumpport <= 0)
   jumpport = default_ssh_port();
  if (jumpuser == 
                 ((void *)0)
                     )
   jumpuser = options.user;
  if (strcmp(options.jump_host, host) == 0 && port == jumpport &&
      strcmp(options.user, jumpuser) == 0)
   sshfatal("ssh.c", __func__, 1258, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "jumphost loop via %s", options.jump_host);





  if (strchr(argv0, '/') != 
                           ((void *)0) 
                                && access(argv0, 
                                                 1
                                                     ) != 0)
   sshbin = "ssh";


  if (options.proxy_command != 
                              ((void *)0)
                                  )
   sshfatal("ssh.c", __func__, 1269, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "inconsistent options: ProxyCommand+ProxyJump");

  options.proxy_use_fdpass = 0;
  snprintf(port_s, sizeof(port_s), "%d", options.jump_port);
  xasprintf(&options.proxy_command,
      "%s%s%s%s%s%s%s%s%s%s%.*s -W '[%%h]:%%p' %s",
      sshbin,

      options.jump_user == 
                          ((void *)0) 
                               ? "" : " -l ",
      options.jump_user == 
                          ((void *)0) 
                               ? "" : options.jump_user,

      options.jump_port <= 0 ? "" : " -p ",
      options.jump_port <= 0 ? "" : port_s,

      options.jump_extra == 
                           ((void *)0) 
                                ? "" : " -J ",
      options.jump_extra == 
                           ((void *)0) 
                                ? "" : options.jump_extra,

      config == 
               ((void *)0) 
                    ? "" : " -F ",
      config == 
               ((void *)0) 
                    ? "" : config,

      debug_flag ? " -" : "",
      debug_flag, "vvv",

      options.jump_host);
  sshlog("ssh.c", __func__, 1293, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Setting implicit ProxyCommand from ProxyJump: %s", options.proxy_command)
                            ;
 }

 if (options.port == 0)
  options.port = default_ssh_port();
 channel_set_af(ssh, options.address_family);


 if (options.host_key_alias != 
                              ((void *)0)
                                  )
  lowercase(options.host_key_alias);
 if (options.proxy_command != 
                             ((void *)0) 
                                  &&
     strcmp(options.proxy_command, "-") == 0 &&
     options.proxy_use_fdpass)
  sshfatal("ssh.c", __func__, 1307, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ProxyCommand=- and ProxyUseFDPass are incompatible");
 if (options.update_hostkeys == 2) {
  if (options.control_persist && options.control_path != 
                                                        ((void *)0)
                                                            ) {
   sshlog("ssh.c", __func__, 1310, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "UpdateHostKeys=ask is incompatible with " "ControlPersist; disabling")
                                   ;
   options.update_hostkeys = 0;
  } else if (sshbuf_len(command) != 0 ||
      options.remote_command != 
                               ((void *)0) 
                                    ||
      options.request_tty == 1) {
   sshlog("ssh.c", __func__, 1316, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "UpdateHostKeys=ask is incompatible with " "remote command execution; disabling")
                                             ;
   options.update_hostkeys = 0;
  } else if (options.log_level < SYSLOG_LEVEL_INFO) {

   options.update_hostkeys = 0;
  }
 }
 if (options.connection_attempts <= 0)
  sshfatal("ssh.c", __func__, 1325, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Invalid number of ConnectionAttempts");

 if (sshbuf_len(command) != 0 && options.remote_command != 
                                                          ((void *)0)
                                                              )
  sshfatal("ssh.c", __func__, 1328, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Cannot execute command-line and remote command.");


 if (options.fork_after_authentication && sshbuf_len(command) == 0 &&
     options.remote_command == 
                              ((void *)0) 
                                   &&
     options.session_type != 0)
  sshfatal("ssh.c", __func__, 1334, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Cannot fork into background without a command " "to execute.")
                    ;


 log_init(argv0, options.log_level, options.log_facility, !use_syslog);
 for (j = 0; j < options.num_log_verbose; j++) {
  if (strcasecmp(options.log_verbose[j], "none") == 0)
   break;
  log_verbose_add(options.log_verbose[j]);
 }

 if (options.request_tty == 2 ||
     options.request_tty == 3)
  tty_flag = 1;


 if (sshbuf_len(command) == 0 && options.remote_command == 
                                                          ((void *)0)
                                                              )
  tty_flag = options.request_tty != 1;


 if (options.request_tty == 1 ||
     (muxclient_command && muxclient_command != 8) ||
     options.session_type == 0)
  tty_flag = 0;

 if ((!isatty(fileno(
                    stdin
                         )) || options.stdin_null) &&
     options.request_tty != 3) {
  if (tty_flag)
   sshlog("ssh.c", __func__, 1362, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Pseudo-terminal will not be allocated because " "stdin is not a terminal.")
                                  ;
  tty_flag = 0;
 }


 cinfo = xcalloc(1, sizeof(*cinfo));
 if (gethostname(thishost, sizeof(thishost)) == -1)
  sshfatal("ssh.c", __func__, 1370, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "gethostname: %s", strerror(
 (*__errno_location ())
 ));
 cinfo->thishost = xstrdup(thishost);
 thishost[strcspn(thishost, ".")] = '\0';
 cinfo->shorthost = xstrdup(thishost);
 xasprintf(&cinfo->portstr, "%d", options.port);
 xasprintf(&cinfo->uidstr, "%llu",
     (unsigned long long)pw->pw_uid);
 cinfo->keyalias = xstrdup(options.host_key_alias ?
     options.host_key_alias : host_arg);
 cinfo->conn_hash_hex = ssh_connection_hash(cinfo->thishost, host,
     cinfo->portstr, options.user);
 cinfo->host_arg = xstrdup(host_arg);
 cinfo->remhost = xstrdup(host);
 cinfo->remuser = xstrdup(options.user);
 cinfo->homedir = xstrdup(pw->pw_dir);
 cinfo->locuser = xstrdup(pw->pw_name);






 if (options.remote_command != 
                              ((void *)0)
                                  ) {
  sshlog("ssh.c", __func__, 1393, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "expanding RemoteCommand: %s", options.remote_command);
  cp = options.remote_command;
  options.remote_command = default_client_percent_expand(cp,
      cinfo);
  sshlog("ssh.c", __func__, 1397, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "expanded RemoteCommand: %s", options.remote_command);
  free(cp);
  if ((r = sshbuf_put(command, options.remote_command,
      strlen(options.remote_command))) != 0)
   sshfatal("ssh.c", __func__, 1401, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "buffer error");
 }

 if (options.control_path != 
                            ((void *)0)
                                ) {
  cp = tilde_expand_filename(options.control_path, getuid());
  free(options.control_path);
  options.control_path = default_client_percent_dollar_expand(cp,
      cinfo);
  free(cp);
 }

 if (options.identity_agent != 
                              ((void *)0)
                                  ) {
  p = tilde_expand_filename(options.identity_agent, getuid());
  cp = default_client_percent_dollar_expand(p, cinfo);
  free(p);
  free(options.identity_agent);
  options.identity_agent = cp;
 }

 if (options.forward_agent_sock_path != 
                                       ((void *)0)
                                           ) {
  p = tilde_expand_filename(options.forward_agent_sock_path,
      getuid());
  cp = default_client_percent_dollar_expand(p, cinfo);
  free(p);
  free(options.forward_agent_sock_path);
  options.forward_agent_sock_path = cp;
  if (stat(options.forward_agent_sock_path, &st) != 0) {
   sshlog("ssh.c", __func__, 1428, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Cannot forward agent socket path \"%s\": %s", options.forward_agent_sock_path, strerror(
  (*__errno_location ())
  ))
                                                        ;
   if (options.exit_on_forward_failure)
    cleanup_exit(255);
  }
 }

 if (options.num_system_hostfiles > 0 &&
     strcasecmp(options.system_hostfiles[0], "none") == 0) {
  if (options.num_system_hostfiles > 1)
   sshfatal("ssh.c", __func__, 1438, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Invalid GlobalKnownHostsFiles: \"none\" " "appears with other entries")
                                    ;
  free(options.system_hostfiles[0]);
  options.system_hostfiles[0] = 
                               ((void *)0)
                                   ;
  options.num_system_hostfiles = 0;
 }

 if (options.num_user_hostfiles > 0 &&
     strcasecmp(options.user_hostfiles[0], "none") == 0) {
  if (options.num_user_hostfiles > 1)
   sshfatal("ssh.c", __func__, 1448, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Invalid UserKnownHostsFiles: \"none\" " "appears with other entries")
                                    ;
  free(options.user_hostfiles[0]);
  options.user_hostfiles[0] = 
                             ((void *)0)
                                 ;
  options.num_user_hostfiles = 0;
 }
 for (j = 0; j < options.num_user_hostfiles; j++) {
  if (options.user_hostfiles[j] == 
                                  ((void *)0)
                                      )
   continue;
  cp = tilde_expand_filename(options.user_hostfiles[j], getuid());
  p = default_client_percent_dollar_expand(cp, cinfo);
  if (strcmp(options.user_hostfiles[j], p) != 0)
   sshlog("ssh.c", __func__, 1460, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "expanded UserKnownHostsFile '%s' -> " "'%s'", options.user_hostfiles[j], p)
                                            ;
  free(options.user_hostfiles[j]);
  free(cp);
  options.user_hostfiles[j] = p;
 }

 for (i = 0; i < options.num_local_forwards; i++) {
  if (options.local_forwards[i].listen_path != 
                                              ((void *)0)
                                                  ) {
   cp = options.local_forwards[i].listen_path;
   p = options.local_forwards[i].listen_path =
       default_client_percent_expand(cp, cinfo);
   if (strcmp(cp, p) != 0)
    sshlog("ssh.c", __func__, 1473, 0, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "expanded LocalForward listen path " "'%s' -> '%s'", cp, p)
                              ;
   free(cp);
  }
  if (options.local_forwards[i].connect_path != 
                                               ((void *)0)
                                                   ) {
   cp = options.local_forwards[i].connect_path;
   p = options.local_forwards[i].connect_path =
       default_client_percent_expand(cp, cinfo);
   if (strcmp(cp, p) != 0)
    sshlog("ssh.c", __func__, 1482, 0, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "expanded LocalForward connect path " "'%s' -> '%s'", cp, p)
                              ;
   free(cp);
  }
 }

 for (i = 0; i < options.num_remote_forwards; i++) {
  if (options.remote_forwards[i].listen_path != 
                                               ((void *)0)
                                                   ) {
   cp = options.remote_forwards[i].listen_path;
   p = options.remote_forwards[i].listen_path =
       default_client_percent_expand(cp, cinfo);
   if (strcmp(cp, p) != 0)
    sshlog("ssh.c", __func__, 1494, 0, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "expanded RemoteForward listen path " "'%s' -> '%s'", cp, p)
                              ;
   free(cp);
  }
  if (options.remote_forwards[i].connect_path != 
                                                ((void *)0)
                                                    ) {
   cp = options.remote_forwards[i].connect_path;
   p = options.remote_forwards[i].connect_path =
       default_client_percent_expand(cp, cinfo);
   if (strcmp(cp, p) != 0)
    sshlog("ssh.c", __func__, 1503, 0, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "expanded RemoteForward connect path " "'%s' -> '%s'", cp, p)
                              ;
   free(cp);
  }
 }

 if (config_test) {
  dump_client_config(&options, host);
  exit(0);
 }


 if (options.sk_provider != 
                           ((void *)0) 
                                && *options.sk_provider == '$' &&
     strlen(options.sk_provider) > 1) {
  if ((cp = getenv(options.sk_provider + 1)) == 
                                               ((void *)0)
                                                   ) {
   sshlog("ssh.c", __func__, 1518, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Authenticator provider %s did not resolve; " "disabling", options.sk_provider)
                                        ;
   free(options.sk_provider);
   options.sk_provider = 
                        ((void *)0)
                            ;
  } else {
   sshlog("ssh.c", __func__, 1523, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "resolved SecurityKeyProvider %s => %s", options.sk_provider, cp)
                               ;
   free(options.sk_provider);
   options.sk_provider = xstrdup(cp);
  }
 }

 if (muxclient_command != 0 && options.control_path == 
                                                      ((void *)0)
                                                          )
  sshfatal("ssh.c", __func__, 1531, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "No ControlPath specified for \"-O\" command");
 if (options.control_path != 
                            ((void *)0)
                                ) {
  int sock;
  if ((sock = muxclient(options.control_path)) >= 0) {
   ssh_packet_set_connection(ssh, sock, sock);
   ssh_packet_set_mux(ssh);
   goto skip_connect;
  }
 }





 if (addrs == 
             ((void *)0) 
                  && options.proxy_command == 
                                              ((void *)0)
                                                  ) {
  sshlog("ssh.c", __func__, 1546, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "resolving \"%s\" port %d", host, options.port);
  if ((addrs = resolve_host(host, options.port, 1,
      cname, sizeof(cname))) == 
                               ((void *)0)
                                   )
   cleanup_exit(255);
 }

 if (options.connection_timeout >= 0x7fffffff/1000)
  timeout_ms = 0x7fffffff;
 else
  timeout_ms = options.connection_timeout * 1000;


 if (ssh_connect(ssh, host, host_arg, addrs, &hostaddr, options.port,
     options.connection_attempts,
     &timeout_ms, options.tcp_keep_alive) != 0)
  exit(255);

 if (addrs != 
             ((void *)0)
                 )
  freeaddrinfo(addrs);

 ssh_packet_set_timeout(ssh, options.server_alive_interval,
     options.server_alive_count_max);

 if (timeout_ms > 0)
  sshlog("ssh.c", __func__, 1570, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "timeout: %d ms remain after connect", timeout_ms);






 sensitive_data.nkeys = 0;
 sensitive_data.keys = 
                      ((void *)0)
                          ;
 if (options.hostbased_authentication) {
  sensitive_data.nkeys = 10;
  sensitive_data.keys = xcalloc(sensitive_data.nkeys,
      sizeof(struct sshkey));
  if (options.hostbased_authentication == 1) {
   do { if ((0) >= sensitive_data.nkeys) sshfatal("ssh.c", __func__, 1605, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "cert out of array bounds"); check_load(sshkey_load_cert("/usr/local/etc" "/ssh_host_ecdsa_key", &(sensitive_data.keys[0])), &(sensitive_data.keys[0]), "/usr/local/etc" "/ssh_host_ecdsa_key", "cert"); if (sensitive_data.keys[0] != 
  ((void *)0)
  ) sshlog("ssh.c", __func__, 1605, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "hostbased key %d: %s cert from \"%s\"", 0, sshkey_ssh_name(sensitive_data.keys[0]), "/usr/local/etc" "/ssh_host_ecdsa_key"); } while (0);
   do { if ((1) >= sensitive_data.nkeys) sshfatal("ssh.c", __func__, 1606, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "cert out of array bounds"); check_load(sshkey_load_cert("/usr/local/etc" "/ssh_host_ed25519_key", &(sensitive_data.keys[1])), &(sensitive_data.keys[1]), "/usr/local/etc" "/ssh_host_ed25519_key", "cert"); if (sensitive_data.keys[1] != 
  ((void *)0)
  ) sshlog("ssh.c", __func__, 1606, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "hostbased key %d: %s cert from \"%s\"", 1, sshkey_ssh_name(sensitive_data.keys[1]), "/usr/local/etc" "/ssh_host_ed25519_key"); } while (0);
   do { if ((2) >= sensitive_data.nkeys) sshfatal("ssh.c", __func__, 1607, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "cert out of array bounds"); check_load(sshkey_load_cert("/usr/local/etc" "/ssh_host_rsa_key", &(sensitive_data.keys[2])), &(sensitive_data.keys[2]), "/usr/local/etc" "/ssh_host_rsa_key", "cert"); if (sensitive_data.keys[2] != 
  ((void *)0)
  ) sshlog("ssh.c", __func__, 1607, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "hostbased key %d: %s cert from \"%s\"", 2, sshkey_ssh_name(sensitive_data.keys[2]), "/usr/local/etc" "/ssh_host_rsa_key"); } while (0);
   do { if ((3) >= sensitive_data.nkeys) sshfatal("ssh.c", __func__, 1608, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "cert out of array bounds"); check_load(sshkey_load_cert("/usr/local/etc" "/ssh_host_dsa_key", &(sensitive_data.keys[3])), &(sensitive_data.keys[3]), "/usr/local/etc" "/ssh_host_dsa_key", "cert"); if (sensitive_data.keys[3] != 
  ((void *)0)
  ) sshlog("ssh.c", __func__, 1608, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "hostbased key %d: %s cert from \"%s\"", 3, sshkey_ssh_name(sensitive_data.keys[3]), "/usr/local/etc" "/ssh_host_dsa_key"); } while (0);
   do { if ((4) >= sensitive_data.nkeys) sshfatal("ssh.c", __func__, 1609, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "pubkey out of array bounds"); check_load(sshkey_load_public("/usr/local/etc" "/ssh_host_ecdsa_key", &(sensitive_data.keys[4]), 
  ((void *)0)
  ), &(sensitive_data.keys[4]), "/usr/local/etc" "/ssh_host_ecdsa_key", "pubkey"); if (sensitive_data.keys[4] != 
  ((void *)0)
  ) sshlog("ssh.c", __func__, 1609, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "hostbased key %d: %s key from \"%s\"", 4, sshkey_ssh_name(sensitive_data.keys[4]), "/usr/local/etc" "/ssh_host_ecdsa_key"); } while (0);
   do { if ((5) >= sensitive_data.nkeys) sshfatal("ssh.c", __func__, 1610, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "pubkey out of array bounds"); check_load(sshkey_load_public("/usr/local/etc" "/ssh_host_ed25519_key", &(sensitive_data.keys[5]), 
  ((void *)0)
  ), &(sensitive_data.keys[5]), "/usr/local/etc" "/ssh_host_ed25519_key", "pubkey"); if (sensitive_data.keys[5] != 
  ((void *)0)
  ) sshlog("ssh.c", __func__, 1610, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "hostbased key %d: %s key from \"%s\"", 5, sshkey_ssh_name(sensitive_data.keys[5]), "/usr/local/etc" "/ssh_host_ed25519_key"); } while (0);
   do { if ((6) >= sensitive_data.nkeys) sshfatal("ssh.c", __func__, 1611, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "pubkey out of array bounds"); check_load(sshkey_load_public("/usr/local/etc" "/ssh_host_rsa_key", &(sensitive_data.keys[6]), 
  ((void *)0)
  ), &(sensitive_data.keys[6]), "/usr/local/etc" "/ssh_host_rsa_key", "pubkey"); if (sensitive_data.keys[6] != 
  ((void *)0)
  ) sshlog("ssh.c", __func__, 1611, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "hostbased key %d: %s key from \"%s\"", 6, sshkey_ssh_name(sensitive_data.keys[6]), "/usr/local/etc" "/ssh_host_rsa_key"); } while (0);
   do { if ((7) >= sensitive_data.nkeys) sshfatal("ssh.c", __func__, 1612, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "pubkey out of array bounds"); check_load(sshkey_load_public("/usr/local/etc" "/ssh_host_dsa_key", &(sensitive_data.keys[7]), 
  ((void *)0)
  ), &(sensitive_data.keys[7]), "/usr/local/etc" "/ssh_host_dsa_key", "pubkey"); if (sensitive_data.keys[7] != 
  ((void *)0)
  ) sshlog("ssh.c", __func__, 1612, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "hostbased key %d: %s key from \"%s\"", 7, sshkey_ssh_name(sensitive_data.keys[7]), "/usr/local/etc" "/ssh_host_dsa_key"); } while (0);
   do { if ((8) >= sensitive_data.nkeys) sshfatal("ssh.c", __func__, 1613, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "cert out of array bounds"); check_load(sshkey_load_cert("/usr/local/etc" "/ssh_host_xmss_key", &(sensitive_data.keys[8])), &(sensitive_data.keys[8]), "/usr/local/etc" "/ssh_host_xmss_key", "cert"); if (sensitive_data.keys[8] != 
  ((void *)0)
  ) sshlog("ssh.c", __func__, 1613, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "hostbased key %d: %s cert from \"%s\"", 8, sshkey_ssh_name(sensitive_data.keys[8]), "/usr/local/etc" "/ssh_host_xmss_key"); } while (0);
   do { if ((9) >= sensitive_data.nkeys) sshfatal("ssh.c", __func__, 1614, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "pubkey out of array bounds"); check_load(sshkey_load_public("/usr/local/etc" "/ssh_host_xmss_key", &(sensitive_data.keys[9]), 
  ((void *)0)
  ), &(sensitive_data.keys[9]), "/usr/local/etc" "/ssh_host_xmss_key", "pubkey"); if (sensitive_data.keys[9] != 
  ((void *)0)
  ) sshlog("ssh.c", __func__, 1614, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "hostbased key %d: %s key from \"%s\"", 9, sshkey_ssh_name(sensitive_data.keys[9]), "/usr/local/etc" "/ssh_host_xmss_key"); } while (0);
  }
 }


 load_public_identity_files(cinfo);


 if (options.identity_agent &&
     strcmp(options.identity_agent, "SSH_AUTH_SOCK") != 0) {
  if (strcmp(options.identity_agent, "none") == 0) {
   unsetenv("SSH_AUTH_SOCK");
  } else {
   cp = options.identity_agent;

   if (cp[0] == '$' && cp[1] != '{') {
    if (!valid_env_name(cp + 1)) {
     sshfatal("ssh.c", __func__, 1631, 0, SYSLOG_LEVEL_FATAL, 
    ((void *)0)
    , "Invalid IdentityAgent " "environment variable name %s", cp)
                                            ;
    }
    if ((p = getenv(cp + 1)) == 
                               ((void *)0)
                                   )
     unsetenv("SSH_AUTH_SOCK");
    else
     setenv("SSH_AUTH_SOCK", p, 1);
   } else {

    setenv("SSH_AUTH_SOCK", cp, 1);
   }
  }
 }

 if (options.forward_agent && options.forward_agent_sock_path != 
                                                                ((void *)0)
                                                                    ) {
  cp = options.forward_agent_sock_path;
  if (cp[0] == '$') {
   if (!valid_env_name(cp + 1)) {
    sshfatal("ssh.c", __func__, 1649, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Invalid ForwardAgent environment variable name %s", cp);
   }
   if ((p = getenv(cp + 1)) != 
                              ((void *)0)
                                  )
    forward_agent_sock_path = xstrdup(p);
   else
    options.forward_agent = 0;
   free(cp);
  } else {
   forward_agent_sock_path = cp;
  }
 }


 tilde_expand_paths(options.system_hostfiles,
     options.num_system_hostfiles);
 tilde_expand_paths(options.user_hostfiles, options.num_user_hostfiles);

 ssh_signal(
           17
                  , main_sigchld_handler);


 ssh_login(ssh, &sensitive_data, host, (struct sockaddr *)&hostaddr,
     options.port, pw, timeout_ms, cinfo);


 if (sensitive_data.nkeys != 0) {
  for (i = 0; i < sensitive_data.nkeys; i++) {
   if (sensitive_data.keys[i] != 
                                ((void *)0)
                                    ) {

    sshlog("ssh.c", __func__, 1677, 0, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "clear hostkey %d", i);
    sshkey_free(sensitive_data.keys[i]);
    sensitive_data.keys[i] = 
                            ((void *)0)
                                ;
   }
  }
  free(sensitive_data.keys);
 }
 for (i = 0; i < options.num_identity_files; i++) {
  free(options.identity_files[i]);
  options.identity_files[i] = 
                             ((void *)0)
                                 ;
  if (options.identity_keys[i]) {
   sshkey_free(options.identity_keys[i]);
   options.identity_keys[i] = 
                             ((void *)0)
                                 ;
  }
 }
 for (i = 0; i < options.num_certificate_files; i++) {
  free(options.certificate_files[i]);
  options.certificate_files[i] = 
                                ((void *)0)
                                    ;
 }


 (void)pkcs11_del_provider(options.pkcs11_provider);


 skip_connect:
 exit_status = ssh_session2(ssh, cinfo);
 ssh_conn_info_free(cinfo);
 ssh_packet_close(ssh);

 if (options.control_path != 
                            ((void *)0) 
                                 && muxserver_sock != -1)
  unlink(options.control_path);


 ssh_kill_proxy_command();

 return exit_status;
}

static void
control_persist_detach(void)
{
 pid_t pid;

 sshlog("ssh.c", __func__, 1720, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "backgrounding master process");





 switch ((pid = fork())) {
 case -1:
  sshfatal("ssh.c", __func__, 1728, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "fork: %s", strerror(
 (*__errno_location ())
 ));
 case 0:

  break;
 default:

  sshlog("ssh.c", __func__, 1734, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "background process is %ld", (long)pid);
  options.stdin_null = ostdin_null_flag;
  options.request_tty = orequest_tty;
  tty_flag = otty_flag;
  options.session_type = osession_type;
  close(muxserver_sock);
  muxserver_sock = -1;
  options.control_master = 0;
  muxclient(options.control_path);

  sshfatal("ssh.c", __func__, 1744, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Failed to connect to new control master");
 }
 if (stdfd_devnull(1, 1, !(log_is_on_stderr() && debug_flag)) == -1)
  sshlog("ssh.c", __func__, 1747, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "stdfd_devnull failed");
 daemon(1, 1);
 setproctitle("%s [mux]", options.control_path);
}


static void
fork_postauth(void)
{
 if (need_controlpersist_detach)
  control_persist_detach();
 sshlog("ssh.c", __func__, 1758, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "forking to background");
 options.fork_after_authentication = 0;
 if (daemon(1, 1) == -1)
  sshfatal("ssh.c", __func__, 1761, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "daemon() failed: %.200s", strerror(
 (*__errno_location ())
 ));
 if (stdfd_devnull(1, 1, !(log_is_on_stderr() && debug_flag)) == -1)
  sshlog("ssh.c", __func__, 1763, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "stdfd_devnull failed");
}

static void
forwarding_success(void)
{
 if (forward_confirms_pending == -1)
  return;
 if (--forward_confirms_pending == 0) {
  sshlog("ssh.c", __func__, 1772, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "all expected forwarding replies received");
  if (options.fork_after_authentication)
   fork_postauth();
 } else {
  sshlog("ssh.c", __func__, 1776, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "%d expected forwarding replies remaining", forward_confirms_pending)
                               ;
 }
}


static void
ssh_confirm_remote_forward(struct ssh *ssh, int type, u_int32_t seq, void *ctxt)
{
 struct Forward *rfwd = (struct Forward *)ctxt;
 u_int port;
 int r;


 sshlog("ssh.c", __func__, 1790, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "remote forward %s for: listen %s%s%d, connect %s:%d", type == 81 ? "success" : "failure", rfwd->listen_path ? rfwd->listen_path : rfwd->listen_host ? rfwd->listen_host : "", (rfwd->listen_path || rfwd->listen_host) ? ":" : "", rfwd->listen_port, rfwd->connect_path ? rfwd->connect_path : rfwd->connect_host, rfwd->connect_port)





                                            ;
 if (rfwd->listen_path == 
                         ((void *)0) 
                              && rfwd->listen_port == 0) {
  if (type == 81) {
   if ((r = sshpkt_get_u32(ssh, &port)) != 0)
    sshfatal("ssh.c", __func__, 1800, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse packet");
   if (port > 65535) {
    sshlog("ssh.c", __func__, 1802, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Invalid allocated port %u for remote " "forward to %s:%d", port, rfwd->connect_host, rfwd->connect_port)

                                               ;

    type = 82;
    channel_update_permission(ssh,
        rfwd->handle, -1);
   } else {
    rfwd->allocated_port = (int)port;
    sshlog("ssh.c", __func__, 1811, 0, SYSLOG_LEVEL_INFO, 
   ((void *)0)
   , "Allocated port %u for remote " "forward to %s:%d", rfwd->allocated_port, rfwd->connect_path ? rfwd->connect_path : rfwd->connect_host, rfwd->connect_port)



                           ;
    channel_update_permission(ssh,
        rfwd->handle, rfwd->allocated_port);
   }
  } else {
   channel_update_permission(ssh, rfwd->handle, -1);
  }
 }

 if (type == 82) {
  if (options.exit_on_forward_failure) {
   if (rfwd->listen_path != 
                           ((void *)0)
                               )
    sshfatal("ssh.c", __func__, 1827, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Error: remote port forwarding failed " "for listen path %s", rfwd->listen_path)
                                                ;
   else
    sshfatal("ssh.c", __func__, 1830, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Error: remote port forwarding failed " "for listen port %d", rfwd->listen_port)
                                                ;
  } else {
   if (rfwd->listen_path != 
                           ((void *)0)
                               )
    sshlog("ssh.c", __func__, 1834, 0, SYSLOG_LEVEL_INFO, 
   ((void *)0)
   , "Warning: remote port forwarding failed " "for listen path %s", rfwd->listen_path)
                                                ;
   else
    sshlog("ssh.c", __func__, 1837, 0, SYSLOG_LEVEL_INFO, 
   ((void *)0)
   , "Warning: remote port forwarding failed " "for listen port %d", rfwd->listen_port)
                                                ;
  }
 }
 forwarding_success();
}

static void
client_cleanup_stdio_fwd(struct ssh *ssh, int id, void *arg)
{
 sshlog("ssh.c", __func__, 1847, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "stdio forwarding: done");
 cleanup_exit(0);
}

static void
ssh_stdio_confirm(struct ssh *ssh, int id, int success, void *arg)
{
 if (!success)
  sshfatal("ssh.c", __func__, 1855, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "stdio forwarding failed");
}

static void
ssh_tun_confirm(struct ssh *ssh, int id, int success, void *arg)
{
 if (!success) {
  sshlog("ssh.c", __func__, 1862, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Tunnel forwarding failed");
  if (options.exit_on_forward_failure)
   cleanup_exit(255);
 }

 sshlog("ssh.c", __func__, 1867, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "tunnel forward established, id=%d", id);
 forwarding_success();
}

static void
ssh_init_stdio_forwarding(struct ssh *ssh)
{
 Channel *c;
 int in, out;

 if (options.stdio_forward_host == 
                                  ((void *)0)
                                      )
  return;

 sshlog("ssh.c", __func__, 1880, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s:%d", options.stdio_forward_host, options.stdio_forward_port)
                                ;

 if ((in = dup(
              0
                          )) == -1 ||
     (out = dup(
               1
                            )) == -1)
  sshfatal("ssh.c", __func__, 1885, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "dup() in/out failed");
 if ((c = channel_connect_stdio_fwd(ssh, options.stdio_forward_host,
     options.stdio_forward_port, in, out,
     2)) == 
                                ((void *)0)
                                    )
  sshfatal("ssh.c", __func__, 1889, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel_connect_stdio_fwd failed");
 channel_register_cleanup(ssh, c->self, client_cleanup_stdio_fwd, 0);
 channel_register_open_confirm(ssh, c->self, ssh_stdio_confirm, 
                                                               ((void *)0)
                                                                   );
}

static void
ssh_init_forward_permissions(struct ssh *ssh, const char *what, char **opens,
    u_int num_opens)
{
 u_int i;
 int port;
 char *addr, *arg, *oarg;
 int where = (1<<1);

 channel_clear_permission(ssh, 0x100, where);
 if (num_opens == 0)
  return;


 if (num_opens == 1 && strcmp(opens[0], "any") == 0)
  return;
 if (num_opens == 1 && strcmp(opens[0], "none") == 0) {
  channel_disable_admin(ssh, where);
  return;
 }

 for (i = 0; i < num_opens; i++) {
  oarg = arg = xstrdup(opens[i]);
  addr = hpdelim(&arg);
  if (addr == 
             ((void *)0)
                 )
   sshfatal("ssh.c", __func__, 1919, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "missing host in %s", what);
  addr = cleanhostname(addr);
  if (arg == 
            ((void *)0) 
                 || ((port = permitopen_port(arg)) < 0))
   sshfatal("ssh.c", __func__, 1922, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "bad port number in %s", what);

  channel_add_permission(ssh, 0x100,
      where, addr, port);
  free(oarg);
 }
}

static void
ssh_init_forwarding(struct ssh *ssh, char **ifname)
{
 int success = 0;
 int i;

 ssh_init_forward_permissions(ssh, "permitremoteopen",
     options.permitted_remote_opens,
     options.num_permitted_remote_opens);

 if (options.exit_on_forward_failure)
  forward_confirms_pending = 0;

 for (i = 0; i < options.num_local_forwards; i++) {
  sshlog("ssh.c", __func__, 1944, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Local connections to %.200s:%d forwarded to remote " "address %.200s:%d", (options.local_forwards[i].listen_path != 
 ((void *)0)
 ) ? options.local_forwards[i].listen_path : (options.local_forwards[i].listen_host == 
 ((void *)0)
 ) ? (options.fwd_opts.gateway_ports ? "*" : "LOCALHOST") : options.local_forwards[i].listen_host, options.local_forwards[i].listen_port, (options.local_forwards[i].connect_path != 
 ((void *)0)
 ) ? options.local_forwards[i].connect_path : options.local_forwards[i].connect_host, options.local_forwards[i].connect_port)
                                             ;
  success += channel_setup_local_fwd_listener(ssh,
      &options.local_forwards[i], &options.fwd_opts);
 }
 if (i > 0 && success != i && options.exit_on_forward_failure)
  sshfatal("ssh.c", __func__, 1960, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Could not request local forwarding.");
 if (i > 0 && success == 0)
  sshlog("ssh.c", __func__, 1962, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Could not request local forwarding.");


 for (i = 0; i < options.num_remote_forwards; i++) {
  sshlog("ssh.c", __func__, 1966, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Remote connections from %.200s:%d forwarded to " "local address %.200s:%d", (options.remote_forwards[i].listen_path != 
 ((void *)0)
 ) ? options.remote_forwards[i].listen_path : (options.remote_forwards[i].listen_host == 
 ((void *)0)
 ) ? "LOCALHOST" : options.remote_forwards[i].listen_host, options.remote_forwards[i].listen_port, (options.remote_forwards[i].connect_path != 
 ((void *)0)
 ) ? options.remote_forwards[i].connect_path : options.remote_forwards[i].connect_host, options.remote_forwards[i].connect_port)
                                              ;
  if ((options.remote_forwards[i].handle =
      channel_request_remote_forwarding(ssh,
      &options.remote_forwards[i])) >= 0) {
   client_register_global_confirm(
       ssh_confirm_remote_forward,
       &options.remote_forwards[i]);
   forward_confirms_pending++;
  } else if (options.exit_on_forward_failure)
   sshfatal("ssh.c", __func__, 1985, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Could not request remote forwarding.");
  else
   sshlog("ssh.c", __func__, 1987, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Warning: Could not request remote forwarding.");
 }


 if (options.tun_open != 0x00) {
  if ((*ifname = client_request_tun_fwd(ssh,
      options.tun_open, options.tun_local,
      options.tun_remote, ssh_tun_confirm, 
                                          ((void *)0)
                                              )) != 
                                                    ((void *)0)
                                                        )
   forward_confirms_pending++;
  else if (options.exit_on_forward_failure)
   sshfatal("ssh.c", __func__, 1997, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Could not request tunnel forwarding.");
  else
   sshlog("ssh.c", __func__, 1999, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Could not request tunnel forwarding.");
 }
 if (forward_confirms_pending > 0) {
  sshlog("ssh.c", __func__, 2002, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "expecting replies for %d forwards", forward_confirms_pending)
                               ;
 }
}

static void
check_agent_present(void)
{
 int r;

 if (options.forward_agent) {

  if ((r = ssh_get_authentication_socket(
                                        ((void *)0)
                                            )) != 0) {
   options.forward_agent = 0;
   if (r != -47)
    sshlog("ssh.c", __func__, 2017, 0, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "ssh_get_authentication_socket");
  }
 }
}

static void
ssh_session2_setup(struct ssh *ssh, int id, int success, void *arg)
{
 extern char **environ;
 const char *display, *term;
 int r, interactive = tty_flag;
 char *proto = 
              ((void *)0)
                  , *data = 
                            ((void *)0)
                                ;

 if (!success)
  return;

 display = getenv("DISPLAY");
 if (display == 
               ((void *)0) 
                    && options.forward_x11)
  sshlog("ssh.c", __func__, 2035, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "X11 forwarding requested but DISPLAY not set");
 if (options.forward_x11 && client_x11_get_proto(ssh, display,
     options.xauth_location, options.forward_x11_trusted,
     options.forward_x11_timeout, &proto, &data) == 0) {

  sshlog("ssh.c", __func__, 2040, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Requesting X11 forwarding with authentication " "spoofing.")
                  ;
  x11_request_forwarding_with_spoofing(ssh, id, display, proto,
      data, 1);
  client_expect_confirm(ssh, id, "X11 forwarding", CONFIRM_WARN);

  interactive = 1;
 }

 check_agent_present();
 if (options.forward_agent) {
  sshlog("ssh.c", __func__, 2051, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Requesting authentication agent forwarding.");
  channel_request_start(ssh, id, "auth-agent-req@openssh.com", 0);
  if ((r = sshpkt_send(ssh)) != 0)
   sshfatal("ssh.c", __func__, 2054, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send packet");
 }


 ssh_packet_set_interactive(ssh, interactive,
     options.ip_qos_interactive, options.ip_qos_bulk);

 if ((term = lookup_env_in_list("TERM", options.setenv,
     options.num_setenv)) == 
                            ((void *)0) 
                                 || *term == '\0')
  term = getenv("TERM");
 client_session2_setup(ssh, id, tty_flag,
     options.session_type == 1, term,
     
    ((void *)0)
        , fileno(
                 stdin
                      ), command, environ);
}


static int
ssh_session2_open(struct ssh *ssh)
{
 Channel *c;
 int window, packetmax, in, out, err;

 if (options.stdin_null) {
  in = open(
           "/dev/null"
                        , 
                          00
                                  );
 } else {
  in = dup(
          0
                      );
 }
 out = dup(
          1
                       );
 err = dup(
          2
                       );

 if (in == -1 || out == -1 || err == -1)
  sshfatal("ssh.c", __func__, 2085, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "dup() in/out/err failed");

 window = (64*(32*1024));
 packetmax = (32*1024);
 if (tty_flag) {
  window >>= 1;
  packetmax >>= 1;
 }
 c = channel_new(ssh,
     "session", 3, in, out, err,
     window, packetmax, 2,
     "client-session", 2);

 sshlog("ssh.c", __func__, 2098, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "channel_new: %d", c->self);

 channel_send_open(ssh, c->self);
 if (options.session_type != 0)
  channel_register_open_confirm(ssh, c->self,
      ssh_session2_setup, 
                         ((void *)0)
                             );

 return c->self;
}

static int
ssh_session2(struct ssh *ssh, const struct ssh_conn_info *cinfo)
{
 int r, id = -1;
 char *cp, *tun_fwd_ifname = 
                            ((void *)0)
                                ;


 if (!options.control_persist)
  ssh_init_stdio_forwarding(ssh);

 ssh_init_forwarding(ssh, &tun_fwd_ifname);

 if (options.local_command != 
                             ((void *)0)
                                 ) {
  sshlog("ssh.c", __func__, 2121, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "expanding LocalCommand: %s", options.local_command);
  cp = options.local_command;
  options.local_command = percent_expand(cp,
      "C", cinfo->conn_hash_hex, "L", cinfo->shorthost, "i", cinfo->uidstr, "k", cinfo->keyalias, "l", cinfo->thishost, "n", cinfo->host_arg, "p", cinfo->portstr, "d", cinfo->homedir, "h", cinfo->remhost, "r", cinfo->remuser, "u", cinfo->locuser,
      "T", tun_fwd_ifname == 
                            ((void *)0) 
                                 ? "NONE" : tun_fwd_ifname,
      (char *)
             ((void *)0)
                 );
  sshlog("ssh.c", __func__, 2127, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "expanded LocalCommand: %s", options.local_command);
  free(cp);
 }


 if (!ssh_packet_get_mux(ssh))
  muxserver_listen(ssh);
 if (options.control_persist && muxserver_sock != -1) {
  ostdin_null_flag = options.stdin_null;
  osession_type = options.session_type;
  orequest_tty = options.request_tty;
  otty_flag = tty_flag;
  options.stdin_null = 1;
  options.session_type = 0;
  tty_flag = 0;
  if (!options.fork_after_authentication &&
      (osession_type != 0 ||
      options.stdio_forward_host != 
                                   ((void *)0)
                                       ))
   need_controlpersist_detach = 1;
  options.fork_after_authentication = 1;
 }




 if (options.control_persist && muxserver_sock == -1)
  ssh_init_stdio_forwarding(ssh);

 if (options.session_type != 0)
  id = ssh_session2_open(ssh);
 else {
  ssh_packet_set_interactive(ssh,
      options.control_master == 0,
      options.ip_qos_interactive, options.ip_qos_bulk);
 }


 if (options.control_master == 0 &&
     (ssh->compat & 0x04000000)) {
  sshlog("ssh.c", __func__, 2176, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Requesting no-more-sessions@openssh.com");
  if ((r = sshpkt_start(ssh, 80)) != 0 ||
      (r = sshpkt_put_cstring(ssh,
      "no-more-sessions@openssh.com")) != 0 ||
      (r = sshpkt_put_u8(ssh, 0)) != 0 ||
      (r = sshpkt_send(ssh)) != 0)
   sshfatal("ssh.c", __func__, 2182, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send packet");
 }


 if (options.local_command != 
                             ((void *)0) 
                                  &&
     options.permit_local_command)
  ssh_local_cmd(options.local_command);







 if (!need_controlpersist_detach && stdfd_devnull(0, 1, 0) == -1)
  sshlog("ssh.c", __func__, 2197, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "stdfd_devnull failed");





 if (options.fork_after_authentication) {
  if (options.exit_on_forward_failure &&
      options.num_remote_forwards > 0) {
   sshlog("ssh.c", __func__, 2206, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "deferring postauth fork until remote forward " "confirmation received")
                               ;
  } else
   fork_postauth();
 }

 return client_loop(ssh, tty_flag, tty_flag ?
     options.escape_char : -2, id);
}


static void
load_public_identity_files(const struct ssh_conn_info *cinfo)
{
 char *filename, *cp;
 struct sshkey *public;
 int i;
 u_int n_ids, n_certs;
 char *identity_files[100];
 struct sshkey *identity_keys[100];
 int identity_file_userprovided[100];
 char *certificate_files[100];
 struct sshkey *certificates[100];
 int certificate_file_userprovided[100];

 struct sshkey **keys = 
                       ((void *)0)
                           ;
 char **comments = 
                  ((void *)0)
                      ;
 int nkeys;


 n_ids = n_certs = 0;
 memset(identity_files, 0, sizeof(identity_files));
 memset(identity_keys, 0, sizeof(identity_keys));
 memset(identity_file_userprovided, 0,
     sizeof(identity_file_userprovided));
 memset(certificate_files, 0, sizeof(certificate_files));
 memset(certificates, 0, sizeof(certificates));
 memset(certificate_file_userprovided, 0,
     sizeof(certificate_file_userprovided));


 if (options.pkcs11_provider != 
                               ((void *)0) 
                                    &&
     options.num_identity_files < 100 &&
     (pkcs11_init(!options.batch_mode) == 0) &&
     (nkeys = pkcs11_add_provider(options.pkcs11_provider, 
                                                          ((void *)0)
                                                              ,
     &keys, &comments)) > 0) {
  for (i = 0; i < nkeys; i++) {
   if (n_ids >= 100) {
    sshkey_free(keys[i]);
    free(comments[i]);
    continue;
   }
   identity_keys[n_ids] = keys[i];
   identity_files[n_ids] = comments[i];
   n_ids++;
  }
  free(keys);
  free(comments);
 }

 for (i = 0; i < options.num_identity_files; i++) {
  if (n_ids >= 100 ||
      strcasecmp(options.identity_files[i], "none") == 0) {
   free(options.identity_files[i]);
   options.identity_files[i] = 
                              ((void *)0)
                                  ;
   continue;
  }
  cp = tilde_expand_filename(options.identity_files[i], getuid());
  filename = default_client_percent_dollar_expand(cp, cinfo);
  free(cp);
  check_load(sshkey_load_public(filename, &public, 
                                                  ((void *)0)
                                                      ),
      &public, filename, "pubkey");
  sshlog("ssh.c", __func__, 2278, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "identity file %s type %d", filename, public ? public->type : -1)
                                 ;
  free(options.identity_files[i]);
  identity_files[n_ids] = filename;
  identity_keys[n_ids] = public;
  identity_file_userprovided[n_ids] =
      options.identity_file_userprovided[i];
  if (++n_ids >= 100)
   continue;





  if (options.num_certificate_files != 0)
   continue;
  xasprintf(&cp, "%s-cert", filename);
  check_load(sshkey_load_public(cp, &public, 
                                            ((void *)0)
                                                ),
      &public, filename, "pubkey");
  sshlog("ssh.c", __func__, 2297, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "identity file %s type %d", cp, public ? public->type : -1)
                                 ;
  if (public == 
               ((void *)0)
                   ) {
   free(cp);
   continue;
  }
  if (!sshkey_is_cert(public)) {
   sshlog("ssh.c", __func__, 2304, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "key %s type %s is not a certificate", cp, sshkey_type(public))
                               ;
   sshkey_free(public);
   free(cp);
   continue;
  }

  identity_files[n_ids] = xstrdup(filename);
  identity_keys[n_ids] = public;
  identity_file_userprovided[n_ids] =
      options.identity_file_userprovided[i];
  n_ids++;
 }

 if (options.num_certificate_files > 100)
  sshfatal("ssh.c", __func__, 2319, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "too many certificates");
 for (i = 0; i < options.num_certificate_files; i++) {
  cp = tilde_expand_filename(options.certificate_files[i],
      getuid());
  filename = default_client_percent_dollar_expand(cp, cinfo);
  free(cp);

  check_load(sshkey_load_public(filename, &public, 
                                                  ((void *)0)
                                                      ),
      &public, filename, "certificate");
  sshlog("ssh.c", __func__, 2328, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "certificate file %s type %d", filename, public ? public->type : -1)
                                 ;
  free(options.certificate_files[i]);
  options.certificate_files[i] = 
                                ((void *)0)
                                    ;
  if (public == 
               ((void *)0)
                   ) {
   free(filename);
   continue;
  }
  if (!sshkey_is_cert(public)) {
   sshlog("ssh.c", __func__, 2337, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "key %s type %s is not a certificate", filename, sshkey_type(public))
                                     ;
   sshkey_free(public);
   free(filename);
   continue;
  }
  certificate_files[n_certs] = filename;
  certificates[n_certs] = public;
  certificate_file_userprovided[n_certs] =
      options.certificate_file_userprovided[i];
  ++n_certs;
 }

 options.num_identity_files = n_ids;
 memcpy(options.identity_files, identity_files, sizeof(identity_files));
 memcpy(options.identity_keys, identity_keys, sizeof(identity_keys));
 memcpy(options.identity_file_userprovided,
     identity_file_userprovided, sizeof(identity_file_userprovided));

 options.num_certificate_files = n_certs;
 memcpy(options.certificate_files,
     certificate_files, sizeof(certificate_files));
 memcpy(options.certificates, certificates, sizeof(certificates));
 memcpy(options.certificate_file_userprovided,
     certificate_file_userprovided,
     sizeof(certificate_file_userprovided));
}

static void
main_sigchld_handler(int sig)
{
 int save_errno = 
                 (*__errno_location ())
                      ;
 pid_t pid;
 int status;

 while ((pid = waitpid(-1, &status, 
                                   1
                                          )) > 0 ||
     (pid == -1 && 
                  (*__errno_location ()) 
                        == 
                           4
                                ))
  ;
 
(*__errno_location ()) 
      = save_errno;
}
