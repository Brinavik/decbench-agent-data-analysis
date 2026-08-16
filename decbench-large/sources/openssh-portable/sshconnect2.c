











































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
struct dhgroup {
 int size;
 BIGNUM *g;
 BIGNUM *p;
};

DH *choose_dh(int, int, int);
DH *dh_new_group_asc(const char *, const char *);
DH *dh_new_group(BIGNUM *, BIGNUM *);
DH *dh_new_group1(void);
DH *dh_new_group14(void);
DH *dh_new_group16(void);
DH *dh_new_group18(void);
DH *dh_new_group_fallback(int);

int dh_gen_key(DH *, int);
int dh_pub_is_valid(const DH *, const BIGNUM *);

u_int dh_estimate(int);
void dh_set_moduli_file(const char *);
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

char *get_peer_ipaddr(int);
int get_peer_port(int);
char *get_local_ipaddr(int);
char *get_local_name(int);
int get_local_port(int);



void ipv64_normalise_mapped(struct sockaddr_storage *, socklen_t *);
struct sshbuf;
int ssh_msg_send(int, u_char, struct sshbuf *);
int ssh_msg_recv(int, struct sshbuf *);
void temporarily_use_uid(struct passwd *);
void restore_uid(void);
void permanently_set_uid(struct passwd *);
typedef enum {
 HOST_OK, HOST_NEW, HOST_CHANGED, HOST_REVOKED, HOST_FOUND
} HostStatus;

typedef enum {
 MRK_ERROR, MRK_NONE, MRK_REVOKE, MRK_CA
} HostkeyMarker;

struct hostkey_entry {
 char *host;
 char *file;
 u_long line;
 struct sshkey *key;
 HostkeyMarker marker;
 u_int note;
};
struct hostkeys {
 struct hostkey_entry *entries;
 u_int num_entries;
};

struct hostkeys *init_hostkeys(void);
void load_hostkeys(struct hostkeys *, const char *,
    const char *, u_int);
void load_hostkeys_file(struct hostkeys *, const char *,
    const char *, FILE *, u_int note);
void free_hostkeys(struct hostkeys *);

HostStatus check_key_in_hostkeys(struct hostkeys *, struct sshkey *,
    const struct hostkey_entry **);
int lookup_key_in_hostkeys_by_type(struct hostkeys *, int, int,
    const struct hostkey_entry **);
int lookup_marker_in_hostkeys(struct hostkeys *, int);

int hostfile_read_key(char **, u_int *, struct sshkey *);
int add_host_to_hostfile(const char *, const char *,
    const struct sshkey *, int);

int hostfile_replace_entries(const char *filename,
    const char *host, const char *ip, struct sshkey **keys, size_t nkeys,
    int store_hash, int quiet, int hash_alg);







char *host_hash(const char *, const char *, u_int);
struct hostkey_foreach_line {
 const char *path;
 u_long linenum;
 u_int status;
 u_int match;
 char *line;
 int marker;
 const char *hosts;
 const char *rawkey;
 int keytype;
 struct sshkey *key;
 const char *comment;
 u_int note;
};






typedef int hostkeys_foreach_fn(struct hostkey_foreach_line *l, void *ctx);


int hostkeys_foreach(const char *path,
    hostkeys_foreach_fn *callback, void *ctx,
    const char *host, const char *ip, u_int options, u_int note);
int hostkeys_foreach_file(const char *path, FILE *f,
    hostkeys_foreach_fn *callback, void *ctx,
    const char *host, const char *ip, u_int options, u_int note);

void hostfile_create_user_ssh_dir(const char *, int);

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
struct sshbuf;
struct sshkey;
struct sk_option;
struct sshsk_resident_key {
 struct sshkey *key;
 uint8_t *user_id;
 size_t user_id_len;
};
int sshsk_enroll(int type, const char *provider_path, const char *device,
    const char *application, const char *userid, uint8_t flags,
    const char *pin, struct sshbuf *challenge_buf,
    struct sshkey **keyp, struct sshbuf *attest);







int sshsk_sign(const char *provider_path, struct sshkey *key,
    u_char **sigp, size_t *lenp, const u_char *data, size_t datalen,
    u_int compat, const char *pin);







int sshsk_load_resident(const char *provider_path, const char *device,
    const char *pin, u_int flags, struct sshsk_resident_key ***srksp,
    size_t *nsrksp);


void sshsk_free_resident_keys(struct sshsk_resident_key **srks, size_t nsrks);
struct sk_enroll_response {
 uint8_t flags;
 uint8_t *public_key;
 size_t public_key_len;
 uint8_t *key_handle;
 size_t key_handle_len;
 uint8_t *signature;
 size_t signature_len;
 uint8_t *attestation_cert;
 size_t attestation_cert_len;
 uint8_t *authdata;
 size_t authdata_len;
};

struct sk_sign_response {
 uint8_t flags;
 uint32_t counter;
 uint8_t *sig_r;
 size_t sig_r_len;
 uint8_t *sig_s;
 size_t sig_s_len;
};

struct sk_resident_key {
 uint32_t alg;
 size_t slot;
 char *application;
 struct sk_enroll_response key;
 uint8_t flags;
 uint8_t *user_id;
 size_t user_id_len;
};

struct sk_option {
 char *name;
 char *value;
 uint8_t required;
};





uint32_t sk_api_version(void);


int sk_enroll(uint32_t alg, const uint8_t *challenge, size_t challenge_len,
    const char *application, uint8_t flags, const char *pin,
    struct sk_option **options, struct sk_enroll_response **enroll_response);


int sk_sign(uint32_t alg, const uint8_t *data, size_t data_len,
    const char *application, const uint8_t *key_handle, size_t key_handle_len,
    uint8_t flags, const char *pin, struct sk_option **options,
    struct sk_sign_response **sign_response);


int sk_load_resident_keys(const char *pin, struct sk_option **options,
    struct sk_resident_key ***rks, size_t *nrks);






extern char *client_version_string;
extern char *server_version_string;
extern Options options;





static char *xxx_host;
static struct sockaddr *xxx_hostaddr;
static const struct ssh_conn_info *xxx_conn_info;

static int
verify_host_key_callback(struct sshkey *hostkey, struct ssh *ssh)
{
 int r;

 if ((r = sshkey_check_rsa_length(hostkey,
     options.required_rsa_size)) != 0)
  sshfatal("sshconnect2.c", __func__, 103, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Bad server host key");
 if (verify_host_key(xxx_host, xxx_hostaddr, hostkey,
     xxx_conn_info) == -1)
  sshfatal("sshconnect2.c", __func__, 106, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Host key verification failed.");
 return 0;
}


static char *
first_alg(const char *algs)
{
 char *ret, *cp;

 ret = xstrdup(algs);
 if ((cp = strchr(ret, ',')) != 
                               ((void *)0)
                                   )
  *cp = '\0';
 return ret;
}

static char *
order_hostkeyalgs(char *host, struct sockaddr *hostaddr, u_short port,
    const struct ssh_conn_info *cinfo)
{
 char *oavail = 
               ((void *)0)
                   , *avail = 
                              ((void *)0)
                                  , *first = 
                                             ((void *)0)
                                                 , *last = 
                                                           ((void *)0)
                                                               ;
 char *alg = 
            ((void *)0)
                , *hostname = 
                              ((void *)0)
                                  , *ret = 
                                           ((void *)0)
                                               , *best = 
                                                         ((void *)0)
                                                             ;
 size_t maxlen;
 struct hostkeys *hostkeys = 
                            ((void *)0)
                                ;
 int ktype;
 u_int i;


 get_hostfile_hostname_ipaddr(host, hostaddr, port, &hostname, 
                                                              ((void *)0)
                                                                  );
 hostkeys = init_hostkeys();
 for (i = 0; i < options.num_user_hostfiles; i++)
  load_hostkeys(hostkeys, hostname, options.user_hostfiles[i], 0);
 for (i = 0; i < options.num_system_hostfiles; i++) {
  load_hostkeys(hostkeys, hostname,
      options.system_hostfiles[i], 0);
 }
 if (options.known_hosts_command != 
                                   ((void *)0)
                                       ) {
  load_hostkeys_command(hostkeys, options.known_hosts_command,
      "ORDER", cinfo, 
                     ((void *)0)
                         , host);
 }







 best = first_alg(options.hostkeyalgorithms);
 if (lookup_key_in_hostkeys_by_type(hostkeys,
     sshkey_type_plain(sshkey_type_from_name(best)),
     sshkey_ecdsa_nid_from_name(best), 
                                      ((void *)0)
                                          )) {
  sshlog("sshconnect2.c", __func__, 157, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "have matching best-preference key type %s, " "using HostkeyAlgorithms verbatim", best)
                                               ;
  ret = xstrdup(options.hostkeyalgorithms);
  goto out;
 }





 oavail = avail = xstrdup(options.hostkeyalgorithms);
 maxlen = strlen(avail) + 1;
 first = xmalloc(maxlen);
 last = xmalloc(maxlen);
 *first = *last = '\0';
 while ((alg = strsep(&avail, ",")) && *alg != '\0') {
  if ((ktype = sshkey_type_from_name(alg)) == KEY_UNSPEC)
   sshfatal("sshconnect2.c", __func__, 182, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "unknown alg %s", alg);




  if (sshkey_type_is_cert(ktype) &&
      lookup_marker_in_hostkeys(hostkeys, MRK_CA)) {
   do { if (*first != '\0') strlcat(first, ",", maxlen); strlcat(first, alg, maxlen); } while (0);
   continue;
  }

  if (lookup_key_in_hostkeys_by_type(hostkeys,
      sshkey_type_plain(ktype),
      sshkey_ecdsa_nid_from_name(alg), 
                                      ((void *)0)
                                          )) {
   do { if (*first != '\0') strlcat(first, ",", maxlen); strlcat(first, alg, maxlen); } while (0);
   continue;
  }

  do { if (*last != '\0') strlcat(last, ",", maxlen); strlcat(last, alg, maxlen); } while (0);
 }

 xasprintf(&ret, "%s%s%s", first,
     (*first == '\0' || *last == '\0') ? "" : ",", last);
 if (*first != '\0')
  sshlog("sshconnect2.c", __func__, 206, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "prefer hostkeyalgs: %s", first);
 else
  sshlog("sshconnect2.c", __func__, 208, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "no algorithms matched; accept original");
 out:
 free(best);
 free(first);
 free(last);
 free(hostname);
 free(oavail);
 free_hostkeys(hostkeys);

 return ret;
}

void
ssh_kex2(struct ssh *ssh, char *host, struct sockaddr *hostaddr, u_short port,
    const struct ssh_conn_info *cinfo)
{
 char *myproposal[PROPOSAL_MAX] = { "sntrup761x25519-sha512@openssh.com," "curve25519-sha256," "curve25519-sha256@libssh.org," "ecdh-sha2-nistp256," "ecdh-sha2-nistp384," "ecdh-sha2-nistp521," "diffie-hellman-group-exchange-sha256," "diffie-hellman-group16-sha512," "diffie-hellman-group18-sha512," "diffie-hellman-group14-sha256", "ssh-ed25519-cert-v01@openssh.com," "ecdsa-sha2-nistp256-cert-v01@openssh.com," "ecdsa-sha2-nistp384-cert-v01@openssh.com," "ecdsa-sha2-nistp521-cert-v01@openssh.com," "sk-ssh-ed25519-cert-v01@openssh.com," "sk-ecdsa-sha2-nistp256-cert-v01@openssh.com," "rsa-sha2-512-cert-v01@openssh.com," "rsa-sha2-256-cert-v01@openssh.com," "ssh-ed25519," "ecdsa-sha2-nistp256," "ecdsa-sha2-nistp384," "ecdsa-sha2-nistp521," "sk-ssh-ed25519@openssh.com," "sk-ecdsa-sha2-nistp256@openssh.com," "rsa-sha2-512," "rsa-sha2-256", "chacha20-poly1305@openssh.com," "aes128-ctr,aes192-ctr,aes256-ctr," "aes128-gcm@openssh.com,aes256-gcm@openssh.com", "chacha20-poly1305@openssh.com," "aes128-ctr,aes192-ctr,aes256-ctr," "aes128-gcm@openssh.com,aes256-gcm@openssh.com", "umac-64-etm@openssh.com," "umac-128-etm@openssh.com," "hmac-sha2-256-etm@openssh.com," "hmac-sha2-512-etm@openssh.com," "hmac-sha1-etm@openssh.com," "umac-64@openssh.com," "umac-128@openssh.com," "hmac-sha2-256," "hmac-sha2-512," "hmac-sha1", "umac-64-etm@openssh.com," "umac-128-etm@openssh.com," "hmac-sha2-256-etm@openssh.com," "hmac-sha2-512-etm@openssh.com," "hmac-sha1-etm@openssh.com," "umac-64@openssh.com," "umac-128@openssh.com," "hmac-sha2-256," "hmac-sha2-512," "hmac-sha1", "none,zlib@openssh.com", "none,zlib@openssh.com", "", "" };
 char *s, *all_key;
 char *prop_kex = 
                 ((void *)0)
                     , *prop_enc = 
                                   ((void *)0)
                                       , *prop_hostkey = 
                                                         ((void *)0)
                                                             ;
 int r, use_known_hosts_order = 0;

 xxx_host = host;
 xxx_hostaddr = hostaddr;
 xxx_conn_info = cinfo;






 if (options.hostkeyalgorithms == 
                                 ((void *)0) 
                                      ||
     options.hostkeyalgorithms[0] == '-' ||
     options.hostkeyalgorithms[0] == '+')
  use_known_hosts_order = 1;


 all_key = sshkey_alg_list(0, 0, 1, ',');
 if ((r = kex_assemble_names(&options.hostkeyalgorithms,
     kex_default_pk_alg(), all_key)) != 0)
  sshfatal("sshconnect2.c", __func__, 247, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "kex_assemble_namelist");
 free(all_key);

 if ((s = kex_names_cat(options.kex_algorithms, "ext-info-c")) == 
                                                                 ((void *)0)
                                                                     )
  sshfatal("sshconnect2.c", __func__, 251, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "kex_names_cat");
 myproposal[PROPOSAL_KEX_ALGS] = prop_kex = compat_kex_proposal(ssh, s);
 myproposal[PROPOSAL_ENC_ALGS_CTOS] =
     myproposal[PROPOSAL_ENC_ALGS_STOC] = prop_enc =
     compat_cipher_proposal(ssh, options.ciphers);
 myproposal[PROPOSAL_COMP_ALGS_CTOS] =
     myproposal[PROPOSAL_COMP_ALGS_STOC] =
     (char *)compression_alg_list(options.compression);
 myproposal[PROPOSAL_MAC_ALGS_CTOS] =
     myproposal[PROPOSAL_MAC_ALGS_STOC] = options.macs;
 if (use_known_hosts_order) {

  myproposal[PROPOSAL_SERVER_HOST_KEY_ALGS] = prop_hostkey =
      compat_pkalg_proposal(ssh,
      order_hostkeyalgs(host, hostaddr, port, cinfo));
 } else {

  myproposal[PROPOSAL_SERVER_HOST_KEY_ALGS] = prop_hostkey =
      compat_pkalg_proposal(ssh, options.hostkeyalgorithms);
 }

 if (options.rekey_limit || options.rekey_interval)
  ssh_packet_set_rekey_limits(ssh, options.rekey_limit,
      options.rekey_interval);


 if ((r = kex_setup(ssh, myproposal)) != 0)
  sshfatal("sshconnect2.c", __func__, 278, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "kex_setup");

 ssh->kex->kex[KEX_DH_GRP1_SHA1] = kex_gen_client;
 ssh->kex->kex[KEX_DH_GRP14_SHA1] = kex_gen_client;
 ssh->kex->kex[KEX_DH_GRP14_SHA256] = kex_gen_client;
 ssh->kex->kex[KEX_DH_GRP16_SHA512] = kex_gen_client;
 ssh->kex->kex[KEX_DH_GRP18_SHA512] = kex_gen_client;
 ssh->kex->kex[KEX_DH_GEX_SHA1] = kexgex_client;
 ssh->kex->kex[KEX_DH_GEX_SHA256] = kexgex_client;

 ssh->kex->kex[KEX_ECDH_SHA2] = kex_gen_client;


 ssh->kex->kex[KEX_C25519_SHA256] = kex_gen_client;
 ssh->kex->kex[KEX_KEM_SNTRUP761X25519_SHA512] = kex_gen_client;
 ssh->kex->verify_host_key=&verify_host_key_callback;

 ssh_dispatch_run_fatal(ssh, DISPATCH_BLOCK, &ssh->kex->done);


 myproposal[PROPOSAL_KEX_ALGS] =
     compat_kex_proposal(ssh, options.kex_algorithms);
 if ((r = kex_prop2buf(ssh->kex->my, myproposal)) != 0)
  sshfatal("sshconnect2.c", __func__, 301, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "kex_prop2buf");
 free(prop_kex);
 free(prop_enc);
 free(prop_hostkey);
}





typedef struct cauthctxt Authctxt;
typedef struct cauthmethod Authmethod;
typedef struct identity Identity;
typedef struct idlist Idlist;

struct identity {
 struct { struct identity *tqe_next; struct identity **tqe_prev; } next;
 int agent_fd;
 struct sshkey *key;
 char *filename;
 int tried;
 int isprivate;
 int userprovided;
};
struct idlist { struct identity *tqh_first; struct identity **tqh_last; };

struct cauthctxt {
 const char *server_user;
 const char *local_user;
 const char *host;
 const char *service;
 struct cauthmethod *method;
 sig_atomic_t success;
 char *authlist;






 struct idlist keys;
 int agent_fd;

 Sensitive *sensitive;
 char *oktypes, *ktypes;
 const char *active_ktype;

 int info_req_seen;
 int attempt_kbdint;

 int attempt_passwd;

 void *methoddata;
};

struct cauthmethod {
 char *name;
 int (*userauth)(struct ssh *ssh);
 void (*cleanup)(struct ssh *ssh);
 int *enabled;
 int *batch_flag;
};

static int input_userauth_service_accept(int, u_int32_t, struct ssh *);
static int input_userauth_ext_info(int, u_int32_t, struct ssh *);
static int input_userauth_success(int, u_int32_t, struct ssh *);
static int input_userauth_failure(int, u_int32_t, struct ssh *);
static int input_userauth_banner(int, u_int32_t, struct ssh *);
static int input_userauth_error(int, u_int32_t, struct ssh *);
static int input_userauth_info_req(int, u_int32_t, struct ssh *);
static int input_userauth_pk_ok(int, u_int32_t, struct ssh *);
static int input_userauth_passwd_changereq(int, u_int32_t, struct ssh *);

static int userauth_none(struct ssh *);
static int userauth_pubkey(struct ssh *);
static int userauth_passwd(struct ssh *);
static int userauth_kbdint(struct ssh *);
static int userauth_hostbased(struct ssh *);
void userauth(struct ssh *, char *);

static void pubkey_cleanup(struct ssh *);
static int sign_and_send_pubkey(struct ssh *ssh, Identity *);
static void pubkey_prepare(struct ssh *, Authctxt *);
static void pubkey_reset(Authctxt *);
static struct sshkey *load_identity_file(Identity *);

static Authmethod *authmethod_get(char *authlist);
static Authmethod *authmethod_lookup(const char *name);
static char *authmethods_get(void);

Authmethod authmethods[] = {







 {"hostbased",
  userauth_hostbased,
  
 ((void *)0)
     ,
  &options.hostbased_authentication,
  
 ((void *)0)
     },
 {"publickey",
  userauth_pubkey,
  
 ((void *)0)
     ,
  &options.pubkey_authentication,
  
 ((void *)0)
     },
 {"keyboard-interactive",
  userauth_kbdint,
  
 ((void *)0)
     ,
  &options.kbd_interactive_authentication,
  &options.batch_mode},
 {"password",
  userauth_passwd,
  
 ((void *)0)
     ,
  &options.password_authentication,
  &options.batch_mode},
 {"none",
  userauth_none,
  
 ((void *)0)
     ,
  
 ((void *)0)
     ,
  
 ((void *)0)
     },
 {
 ((void *)0)
     , 
       ((void *)0)
           , 
             ((void *)0)
                 , 
                   ((void *)0)
                       , 
                         ((void *)0)
                             }
};

void
ssh_userauth2(struct ssh *ssh, const char *local_user,
    const char *server_user, char *host, Sensitive *sensitive)
{
 Authctxt authctxt;
 int r;

 if (options.preferred_authentications == 
                                         ((void *)0)
                                             )
  options.preferred_authentications = authmethods_get();


 memset(&authctxt, 0, sizeof(authctxt));
 authctxt.server_user = server_user;
 authctxt.local_user = local_user;
 authctxt.host = host;
 authctxt.service = "ssh-connection";
 authctxt.success = 0;
 authctxt.method = authmethod_lookup("none");
 authctxt.authlist = 
                    ((void *)0)
                        ;
 authctxt.methoddata = 
                      ((void *)0)
                          ;
 authctxt.sensitive = sensitive;
 authctxt.active_ktype = authctxt.oktypes = authctxt.ktypes = 
                                                             ((void *)0)
                                                                 ;
 authctxt.info_req_seen = 0;
 authctxt.attempt_kbdint = 0;
 authctxt.attempt_passwd = 0;




 authctxt.agent_fd = -1;
 pubkey_prepare(ssh, &authctxt);
 if (authctxt.method == 
                       ((void *)0)
                           ) {
  sshfatal("sshconnect2.c", __func__, 479, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "internal error: cannot send userauth none request");
 }

 if ((r = sshpkt_start(ssh, 5)) != 0 ||
     (r = sshpkt_put_cstring(ssh, "ssh-userauth")) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  sshfatal("sshconnect2.c", __func__, 485, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send packet");

 ssh->authctxt = &authctxt;
 ssh_dispatch_init(ssh, &input_userauth_error);
 ssh_dispatch_set(ssh, 7, &input_userauth_ext_info);
 ssh_dispatch_set(ssh, 6, &input_userauth_service_accept);
 ssh_dispatch_run_fatal(ssh, DISPATCH_BLOCK, &authctxt.success);
 pubkey_cleanup(ssh);
 ssh->authctxt = 
                ((void *)0)
                    ;

 ssh_dispatch_range(ssh, 50, 79, 
                                                                      ((void *)0)
                                                                          );

 if (!authctxt.success)
  sshfatal("sshconnect2.c", __func__, 498, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Authentication failed.");
 if (ssh_packet_connection_is_on_socket(ssh)) {
  sshlog("sshconnect2.c", __func__, 500, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "Authenticated to %s ([%s]:%d) using \"%s\".", host, ssh_remote_ipaddr(ssh), ssh_remote_port(ssh), authctxt.method->name)

                            ;
 } else {
  sshlog("sshconnect2.c", __func__, 504, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "Authenticated to %s (via proxy) using \"%s\".", host, authctxt.method->name)
                            ;
 }
}


static int
input_userauth_service_accept(int type, u_int32_t seq, struct ssh *ssh)
{
 int r;

 if (ssh_packet_remaining(ssh) > 0) {
  char *reply;

  if ((r = sshpkt_get_cstring(ssh, &reply, 
                                          ((void *)0)
                                              )) != 0)
   goto out;
  sshlog("sshconnect2.c", __func__, 520, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "service_accept: %s", reply);
  free(reply);
 } else {
  sshlog("sshconnect2.c", __func__, 523, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "buggy server: service_accept w/o service");
 }
 if ((r = sshpkt_get_end(ssh)) != 0)
  goto out;
 sshlog("sshconnect2.c", __func__, 527, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "SSH2_MSG_SERVICE_ACCEPT received");


 userauth_none(ssh);

 ssh_dispatch_set(ssh, 7, &input_userauth_error);
 ssh_dispatch_set(ssh, 52, &input_userauth_success);
 ssh_dispatch_set(ssh, 51, &input_userauth_failure);
 ssh_dispatch_set(ssh, 53, &input_userauth_banner);
 r = 0;
 out:
 return r;
}


static int
input_userauth_ext_info(int type, u_int32_t seqnr, struct ssh *ssh)
{
 return kex_input_ext_info(type, seqnr, ssh);
}

void
userauth(struct ssh *ssh, char *authlist)
{
 Authctxt *authctxt = (Authctxt *)ssh->authctxt;

 if (authctxt->method != 
                        ((void *)0) 
                             && authctxt->method->cleanup != 
                                                             ((void *)0)
                                                                 )
  authctxt->method->cleanup(ssh);

 free(authctxt->methoddata);
 authctxt->methoddata = 
                       ((void *)0)
                           ;
 if (authlist == 
                ((void *)0)
                    ) {
  authlist = authctxt->authlist;
 } else {
  free(authctxt->authlist);
  authctxt->authlist = authlist;
 }
 for (;;) {
  Authmethod *method = authmethod_get(authlist);
  if (method == 
               ((void *)0)
                   )
   sshfatal("sshconnect2.c", __func__, 567, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s@%s: Permission denied (%s).", authctxt->server_user, authctxt->host, authlist)
                                                       ;
  authctxt->method = method;


  ssh_dispatch_range(ssh, 60,
      79, 
                                       ((void *)0)
                                           );


  if (method->userauth(ssh) != 0) {
   sshlog("sshconnect2.c", __func__, 577, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "we sent a %s packet, wait for reply", method->name);
   break;
  } else {
   sshlog("sshconnect2.c", __func__, 580, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "we did not send a packet, disable method");
   method->enabled = 
                    ((void *)0)
                        ;
  }
 }
}


static int
input_userauth_error(int type, u_int32_t seq, struct ssh *ssh)
{
 sshfatal("sshconnect2.c", __func__, 590, 1, SYSLOG_LEVEL_FATAL, 
((void *)0)
, "bad message during authentication: type %d", type);
 return 0;
}


static int
input_userauth_banner(int type, u_int32_t seq, struct ssh *ssh)
{
 char *msg = 
            ((void *)0)
                ;
 size_t len;
 int r;

 sshlog("sshconnect2.c", __func__, 602, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "entering");
 if ((r = sshpkt_get_cstring(ssh, &msg, &len)) != 0 ||
     (r = sshpkt_get_cstring(ssh, 
                                 ((void *)0)
                                     , 
                                       ((void *)0)
                                           )) != 0)
  goto out;
 if (len > 0 && options.log_level >= SYSLOG_LEVEL_INFO)
  fmprintf(
          stderr
                , "%s", msg);
 r = 0;
 out:
 free(msg);
 return r;
}


static int
input_userauth_success(int type, u_int32_t seq, struct ssh *ssh)
{
 Authctxt *authctxt = ssh->authctxt;

 if (authctxt == 
                ((void *)0)
                    )
  sshfatal("sshconnect2.c", __func__, 621, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "no authentication context");
 free(authctxt->authlist);
 authctxt->authlist = 
                     ((void *)0)
                         ;
 if (authctxt->method != 
                        ((void *)0) 
                             && authctxt->method->cleanup != 
                                                             ((void *)0)
                                                                 )
  authctxt->method->cleanup(ssh);
 free(authctxt->methoddata);
 authctxt->methoddata = 
                       ((void *)0)
                           ;
 authctxt->success = 1;
 return 0;
}
static int
input_userauth_failure(int type, u_int32_t seq, struct ssh *ssh)
{
 Authctxt *authctxt = ssh->authctxt;
 char *authlist = 
                 ((void *)0)
                     ;
 u_char partial;

 if (authctxt == 
                ((void *)0)
                    )
  sshfatal("sshconnect2.c", __func__, 656, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "input_userauth_failure: no authentication context");

 if (sshpkt_get_cstring(ssh, &authlist, 
                                       ((void *)0)
                                           ) != 0 ||
     sshpkt_get_u8(ssh, &partial) != 0 ||
     sshpkt_get_end(ssh) != 0)
  goto out;

 if (partial != 0) {
  sshlog("sshconnect2.c", __func__, 664, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "Authenticated using \"%s\" with partial success.", authctxt->method->name)
                             ;

  pubkey_reset(authctxt);
 }
 sshlog("sshconnect2.c", __func__, 669, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Authentications that can continue: %s", authlist);

 userauth(ssh, authlist);
 authlist = 
           ((void *)0)
               ;
 out:
 free(authlist);
 return 0;
}





static char *
format_identity(Identity *id)
{
 char *fp = 
           ((void *)0)
               , *ret = 
                        ((void *)0)
                            ;
 const char *note = "";

 if (id->key != 
               ((void *)0)
                   ) {
  fp = sshkey_fingerprint(id->key, options.fingerprint_hash,
      SSH_FP_DEFAULT);
 }
 if (id->key) {
  if ((id->key->flags & 0x0001) != 0)
   note = " token";
  else if (sshkey_is_sk(id->key))
   note = " authenticator";
 }
 xasprintf(&ret, "%s %s%s%s%s%s%s",
     id->filename,
     id->key ? sshkey_type(id->key) : "", id->key ? " " : "",
     fp ? fp : "",
     id->userprovided ? " explicit" : "", note,
     id->agent_fd != -1 ? " agent" : "");
 free(fp);
 return ret;
}


static int
input_userauth_pk_ok(int type, u_int32_t seq, struct ssh *ssh)
{
 Authctxt *authctxt = ssh->authctxt;
 struct sshkey *key = 
                     ((void *)0)
                         ;
 Identity *id = 
               ((void *)0)
                   ;
 int pktype, found = 0, sent = 0;
 size_t blen;
 char *pkalg = 
              ((void *)0)
                  , *fp = 
                          ((void *)0)
                              , *ident = 
                                         ((void *)0)
                                             ;
 u_char *pkblob = 
                 ((void *)0)
                     ;
 int r;

 if (authctxt == 
                ((void *)0)
                    )
  sshfatal("sshconnect2.c", __func__, 722, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "input_userauth_pk_ok: no authentication context");

 if ((r = sshpkt_get_cstring(ssh, &pkalg, 
                                         ((void *)0)
                                             )) != 0 ||
     (r = sshpkt_get_string(ssh, &pkblob, &blen)) != 0 ||
     (r = sshpkt_get_end(ssh)) != 0)
  goto done;

 if ((pktype = sshkey_type_from_name(pkalg)) == KEY_UNSPEC) {
  sshlog("sshconnect2.c", __func__, 730, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "server sent unknown pkalg %s", pkalg);
  goto done;
 }
 if ((r = sshkey_from_blob(pkblob, blen, &key)) != 0) {
  sshlog("sshconnect2.c", __func__, 734, 0, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "no key from blob. pkalg %s", pkalg);
  goto done;
 }
 if (key->type != pktype) {
  sshlog("sshconnect2.c", __func__, 738, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "input_userauth_pk_ok: type mismatch " "for decoded key (received %d, expected %d)", key->type, pktype)

                        ;
  goto done;
 }






 for((id) = (*(((struct idlist *)((&authctxt->keys)->tqh_last))->tqh_last)); (id) != 
((void *)0)
; (id) = (*(((struct idlist *)((id)->next.tqe_prev))->tqh_last))) {
  if (sshkey_equal(key, id->key)) {
   found = 1;
   break;
  }
 }
 if (!found || id == 
                    ((void *)0)
                        ) {
  fp = sshkey_fingerprint(key, options.fingerprint_hash,
      SSH_FP_DEFAULT);
  sshlog("sshconnect2.c", __func__, 758, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "server replied with unknown key: %s %s", sshkey_type(key), fp == 
 ((void *)0) 
 ? "<ERROR>" : fp)
                                                    ;
  goto done;
 }
 ident = format_identity(id);
 sshlog("sshconnect2.c", __func__, 763, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Server accepts key: %s", ident);
 sent = sign_and_send_pubkey(ssh, id);
 r = 0;
 done:
 sshkey_free(key);
 free(ident);
 free(fp);
 free(pkalg);
 free(pkblob);


 if (r == 0 && sent == 0)
  userauth(ssh, 
               ((void *)0)
                   );
 return r;
}
static int
userauth_none(struct ssh *ssh)
{
 Authctxt *authctxt = (Authctxt *)ssh->authctxt;
 int r;


 if ((r = sshpkt_start(ssh, 50)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->server_user)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->service)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->method->name)) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  sshfatal("sshconnect2.c", __func__, 1063, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send packet");
 return 1;
}

static int
userauth_passwd(struct ssh *ssh)
{
 Authctxt *authctxt = (Authctxt *)ssh->authctxt;
 char *password, *prompt = 
                          ((void *)0)
                              ;
 const char *host = options.host_key_alias ? options.host_key_alias :
     authctxt->host;
 int r;

 if (authctxt->attempt_passwd++ >= options.number_of_password_prompts)
  return 0;

 if (authctxt->attempt_passwd != 1)
  sshlog("sshconnect2.c", __func__, 1080, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Permission denied, please try again.");

 xasprintf(&prompt, "%s@%s's password: ", authctxt->server_user, host);
 password = read_passphrase(prompt, 0);
 if ((r = sshpkt_start(ssh, 50)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->server_user)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->service)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->method->name)) != 0 ||
     (r = sshpkt_put_u8(ssh, 0)) != 0 ||
     (r = sshpkt_put_cstring(ssh, password)) != 0 ||
     (r = sshpkt_add_padding(ssh, 64)) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  sshfatal("sshconnect2.c", __func__, 1092, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send packet");

 free(prompt);
 if (password != 
                ((void *)0)
                    )
  freezero(password, strlen(password));

 ssh_dispatch_set(ssh, 60,
     &input_userauth_passwd_changereq);

 return 1;
}





static int
input_userauth_passwd_changereq(int type, u_int32_t seqnr, struct ssh *ssh)
{
 Authctxt *authctxt = ssh->authctxt;
 char *info = 
             ((void *)0)
                 , *lang = 
                           ((void *)0)
                               , *password = 
                                             ((void *)0)
                                                 , *retype = 
                                                             ((void *)0)
                                                                 ;
 char prompt[256];
 const char *host;
 int r;

 sshlog("sshconnect2.c", __func__, 1117, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "input_userauth_passwd_changereq");

 if (authctxt == 
                ((void *)0)
                    )
  sshfatal("sshconnect2.c", __func__, 1120, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "input_userauth_passwd_changereq: " "no authentication context")
                                  ;
 host = options.host_key_alias ? options.host_key_alias : authctxt->host;

 if ((r = sshpkt_get_cstring(ssh, &info, 
                                        ((void *)0)
                                            )) != 0 ||
     (r = sshpkt_get_cstring(ssh, &lang, 
                                        ((void *)0)
                                            )) != 0)
  goto out;
 if (strlen(info) > 0)
  sshlog("sshconnect2.c", __func__, 1128, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "%s", info);
 if ((r = sshpkt_start(ssh, 50)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->server_user)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->service)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->method->name)) != 0 ||
     (r = sshpkt_put_u8(ssh, 1)) != 0)
  goto out;

 snprintf(prompt, sizeof(prompt),
     "Enter %.30s@%.128s's old password: ",
     authctxt->server_user, host);
 password = read_passphrase(prompt, 0);
 if ((r = sshpkt_put_cstring(ssh, password)) != 0)
  goto out;

 freezero(password, strlen(password));
 password = 
           ((void *)0)
               ;
 while (password == 
                   ((void *)0)
                       ) {
  snprintf(prompt, sizeof(prompt),
      "Enter %.30s@%.128s's new password: ",
      authctxt->server_user, host);
  password = read_passphrase(prompt, 0x0004);
  if (password == 
                 ((void *)0)
                     ) {

   r = 0;
   goto out;
  }
  snprintf(prompt, sizeof(prompt),
      "Retype %.30s@%.128s's new password: ",
      authctxt->server_user, host);
  retype = read_passphrase(prompt, 0);
  if (strcmp(password, retype) != 0) {
   freezero(password, strlen(password));
   sshlog("sshconnect2.c", __func__, 1161, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Mismatch; try again, EOF to quit.");
   password = 
             ((void *)0)
                 ;
  }
  freezero(retype, strlen(retype));
 }
 if ((r = sshpkt_put_cstring(ssh, password)) != 0 ||
     (r = sshpkt_add_padding(ssh, 64)) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  goto out;

 ssh_dispatch_set(ssh, 60,
     &input_userauth_passwd_changereq);
 r = 0;
 out:
 if (password)
  freezero(password, strlen(password));
 free(info);
 free(lang);
 return r;
}
static char *
key_sig_algorithm(struct ssh *ssh, const struct sshkey *key)
{
 char *allowed, *oallowed, *cp, *tmp, *alg = 
                                            ((void *)0)
                                                ;
 const char *server_sig_algs;






 if (ssh == 
           ((void *)0) 
                || ssh->kex->server_sig_algs == 
                                                ((void *)0) 
                                                     ||
     (key->type != KEY_RSA && key->type != KEY_RSA_CERT) ||
     (key->type == KEY_RSA_CERT && (ssh->compat & 0x00000002))) {

  return match_list(sshkey_ssh_name(key),
      options.pubkey_accepted_algos, 
                                    ((void *)0)
                                        );
 }





 server_sig_algs = ssh->kex->server_sig_algs;
 if (key->type == KEY_RSA && (ssh->compat & 0x00000004))
  server_sig_algs = "rsa-sha2-256,rsa-sha2-512";







 oallowed = allowed = xstrdup(options.pubkey_accepted_algos);
 while ((cp = strsep(&allowed, ",")) != 
                                       ((void *)0)
                                           ) {
  if (sshkey_type_from_name(cp) != key->type)
   continue;
  tmp = match_list(sshkey_sigalg_by_name(cp),
      server_sig_algs, 
                      ((void *)0)
                          );
  if (tmp != 
            ((void *)0)
                )
   alg = xstrdup(cp);
  free(tmp);
  if (alg != 
            ((void *)0)
                )
   break;
 }
 free(oallowed);
 return alg;
}

static int
identity_sign(struct identity *id, u_char **sigp, size_t *lenp,
    const u_char *data, size_t datalen, u_int compat, const char *alg)
{
 struct sshkey *sign_key = 
                          ((void *)0)
                              , *prv = 
                                       ((void *)0)
                                           ;
 int is_agent = 0, retried = 0, r = -1;
 struct notifier_ctx *notifier = 
                                ((void *)0)
                                    ;
 char *fp = 
           ((void *)0)
               , *pin = 
                        ((void *)0)
                            , *prompt = 
                                        ((void *)0)
                                            ;

 *sigp = 
        ((void *)0)
            ;
 *lenp = 0;


 if (id->key != 
               ((void *)0) 
                    && id->agent_fd != -1) {
  return ssh_agent_sign(id->agent_fd, id->key, sigp, lenp,
      data, datalen, alg, compat);
 }





 if (id->key != 
               ((void *)0) 
                    &&
     (id->isprivate || (id->key->flags & 0x0001))) {
  sign_key = id->key;
  is_agent = 1;
 } else {

  if ((prv = load_identity_file(id)) == 
                                       ((void *)0)
                                           )
   return -46;
  if (id->key != 
                ((void *)0) 
                     && !sshkey_equal_public(prv, id->key)) {
   sshlog("sshconnect2.c", __func__, 1269, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "private key %s contents do not match public", id->filename)
                    ;
   r = -46;
   goto out;
  }
  sign_key = prv;
 }
 retry_pin:

 if (!is_agent && sshkey_is_sk(sign_key) &&
     (sign_key->sk_flags & 0x01)) {

  if ((fp = sshkey_fingerprint(sign_key,
      options.fingerprint_hash, SSH_FP_DEFAULT)) == 
                                                   ((void *)0)
                                                       )
   sshfatal("sshconnect2.c", __func__, 1283, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "fingerprint failed");
  notifier = notify_start(options.batch_mode,
      "Confirm user presence for key %s %s",
      sshkey_type(sign_key), fp);
  free(fp);
 }
 if ((r = sshkey_sign(sign_key, sigp, lenp, data, datalen,
     alg, options.sk_provider, pin, compat)) != 0) {
  sshlog("sshconnect2.c", __func__, 1291, 1, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "sshkey_sign");
  if (!retried && pin == 
                        ((void *)0) 
                             && !is_agent &&
      sshkey_is_sk(sign_key) &&
      r == -43) {
   notify_complete(notifier, 
                            ((void *)0)
                                );
   notifier = 
             ((void *)0)
                 ;
   xasprintf(&prompt, "Enter PIN for %s key %s: ",
       sshkey_type(sign_key), id->filename);
   pin = read_passphrase(prompt, 0);
   retried = 1;
   goto retry_pin;
  }
  goto out;
 }





 if ((r = sshkey_check_sigtype(*sigp, *lenp, alg)) != 0) {
  sshlog("sshconnect2.c", __func__, 1311, 1, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "sshkey_check_sigtype");
  goto out;
 }

 r = 0;
 out:
 free(prompt);
 if (pin != 
           ((void *)0)
               )
  freezero(pin, strlen(pin));
 notify_complete(notifier, r == 0 ? "User presence confirmed" : 
                                                               ((void *)0)
                                                                   );
 sshkey_free(prv);
 return r;
}

static int
id_filename_matches(Identity *id, Identity *private_id)
{
 static const char * const suffixes[] = { ".pub", "-cert.pub", 
                                                              ((void *)0) 
                                                                   };
 size_t len = strlen(id->filename), plen = strlen(private_id->filename);
 size_t i, slen;

 if (strcmp(id->filename, private_id->filename) == 0)
  return 1;
 for (i = 0; suffixes[i]; i++) {
  slen = strlen(suffixes[i]);
  if (len > slen && plen == len - slen &&
      strcmp(id->filename + (len - slen), suffixes[i]) == 0 &&
      memcmp(id->filename, private_id->filename, plen) == 0)
   return 1;
 }
 return 0;
}

static int
sign_and_send_pubkey(struct ssh *ssh, Identity *id)
{
 Authctxt *authctxt = (Authctxt *)ssh->authctxt;
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 Identity *private_id, *sign_id = 
                                 ((void *)0)
                                     ;
 u_char *signature = 
                    ((void *)0)
                        ;
 size_t slen = 0, skip = 0;
 int r, fallback_sigtype, sent = 0;
 char *alg = 
            ((void *)0)
                , *fp = 
                        ((void *)0)
                            ;
 const char *loc = "", *method = "publickey";
 int hostbound = 0;


 if ((ssh->kex->flags & 0x0004) != 0 &&
     (options.pubkey_authentication & 0x02) != 0) {
  hostbound = 1;
  method = "publickey-hostbound-v00@openssh.com";
 }

 if ((fp = sshkey_fingerprint(id->key, options.fingerprint_hash,
     SSH_FP_DEFAULT)) == 
                        ((void *)0)
                            )
  return 0;

 sshlog("sshconnect2.c", __func__, 1368, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "using %s with %s %s", method, sshkey_type(id->key), fp);
 if (sshkey_is_cert(id->key)) {
  for((private_id) = ((&authctxt->keys)->tqh_first); (private_id) != 
 ((void *)0)
 ; (private_id) = ((private_id)->next.tqe_next)) {
   if (sshkey_equal_public(id->key, private_id->key) &&
       id->key->type != private_id->key->type) {
    sign_id = private_id;
    break;
   }
  }







  if (sign_id == 
                ((void *)0) 
                     &&
      !id->isprivate && id->agent_fd == -1 &&
      (id->key->flags & 0x0001) == 0) {
   for((private_id) = ((&authctxt->keys)->tqh_first); (private_id) != 
  ((void *)0)
  ; (private_id) = ((private_id)->next.tqe_next)) {
    if (private_id->key == 
                          ((void *)0) 
                               &&
        id_filename_matches(id, private_id)) {
     sign_id = private_id;
     break;
    }
   }
  }
  if (sign_id != 
                ((void *)0)
                    ) {
   sshlog("sshconnect2.c", __func__, 1405, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "using private key \"%s\"%s for " "certificate", sign_id->filename, sign_id->agent_fd != -1 ? " from agent" : "")

                                                    ;
  } else {
   sshlog("sshconnect2.c", __func__, 1409, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "no separate private key for certificate " "\"%s\"", id->filename)
                              ;
  }
 }





 if (sign_id == 
               ((void *)0)
                   )
  sign_id = id;


 for (fallback_sigtype = 0; fallback_sigtype <= 1; fallback_sigtype++) {
  free(alg);
  slen = 0;
  signature = 
             ((void *)0)
                 ;
  if ((alg = key_sig_algorithm(fallback_sigtype ? 
                                                 ((void *)0) 
                                                      : ssh,
      id->key)) == 
                  ((void *)0)
                      ) {
   sshlog("sshconnect2.c", __func__, 1428, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "no mutual signature supported");
   goto out;
  }
  sshlog("sshconnect2.c", __func__, 1431, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "signing using %s %s", alg, fp);

  sshbuf_free(b);
  if ((b = sshbuf_new()) == 
                           ((void *)0)
                               )
   sshfatal("sshconnect2.c", __func__, 1435, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshbuf_new failed");
  if (ssh->compat & 0x00000010) {
   if ((r = sshbuf_putb(b, ssh->kex->session_id)) != 0)
    sshfatal("sshconnect2.c", __func__, 1438, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_putb");
  } else {
   if ((r = sshbuf_put_stringb(b,
       ssh->kex->session_id)) != 0)
    sshfatal("sshconnect2.c", __func__, 1442, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_put_stringb");
  }
  skip = sshbuf_len(b);
  if ((r = sshbuf_put_u8(b, 50)) != 0 ||
      (r = sshbuf_put_cstring(b, authctxt->server_user)) != 0 ||
      (r = sshbuf_put_cstring(b, authctxt->service)) != 0 ||
      (r = sshbuf_put_cstring(b, method)) != 0 ||
      (r = sshbuf_put_u8(b, 1)) != 0 ||
      (r = sshbuf_put_cstring(b, alg)) != 0 ||
      (r = sshkey_puts(id->key, b)) != 0) {
   sshfatal("sshconnect2.c", __func__, 1452, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble signed data");
  }
  if (hostbound) {
   if (ssh->kex->initial_hostkey == 
                                   ((void *)0)
                                       ) {
    sshfatal("sshconnect2.c", __func__, 1456, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "internal error: initial hostkey " "not recorded")
                       ;
   }
   if ((r = sshkey_puts(ssh->kex->initial_hostkey, b)) != 0)
    sshfatal("sshconnect2.c", __func__, 1460, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s hostkey", method);
  }

  r = identity_sign(sign_id, &signature, &slen,
      sshbuf_ptr(b), sshbuf_len(b), ssh->compat, alg);
  if (r == 0)
   break;
  else if (r == -46)
   goto out;
  else if (r == -58 &&
      !fallback_sigtype) {
   if (sign_id->agent_fd != -1)
    loc = "agent ";
   else if ((sign_id->key->flags & 0x0001) != 0)
    loc = "token ";
   sshlog("sshconnect2.c", __func__, 1475, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "%skey %s %s returned incorrect signature type", loc, sshkey_type(id->key), fp)
                                     ;
   continue;
  }
  sshlog("sshconnect2.c", __func__, 1479, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "signing failed for %s \"%s\"%s", sshkey_type(sign_id->key), sign_id->filename, id->agent_fd != -1 ? " from agent" : "")

                                              ;
  goto out;
 }
 if (slen == 0 || signature == 
                              ((void *)0)
                                  )
  sshfatal("sshconnect2.c", __func__, 1485, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "no signature");


 if ((r = sshbuf_put_string(b, signature, slen)) != 0)
  sshfatal("sshconnect2.c", __func__, 1489, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "append signature");





 if ((r = sshbuf_consume(b, skip + 1)) != 0)
  sshfatal("sshconnect2.c", __func__, 1496, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "consume");


 if ((r = sshpkt_start(ssh, 50)) != 0 ||
     (r = sshpkt_putb(ssh, b)) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  sshfatal("sshconnect2.c", __func__, 1502, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "enqueue request");


 sent = 1;

 out:
 free(fp);
 free(alg);
 sshbuf_free(b);
 freezero(signature, slen);
 return sent;
}

static int
send_pubkey_test(struct ssh *ssh, Identity *id)
{
 Authctxt *authctxt = (Authctxt *)ssh->authctxt;
 u_char *blob = 
               ((void *)0)
                   ;
 char *alg = 
            ((void *)0)
                ;
 size_t bloblen;
 u_int have_sig = 0;
 int sent = 0, r;

 if ((alg = key_sig_algorithm(ssh, id->key)) == 
                                               ((void *)0)
                                                   ) {
  sshlog("sshconnect2.c", __func__, 1526, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "no mutual signature algorithm");
  goto out;
 }

 if ((r = sshkey_to_blob(id->key, &blob, &bloblen)) != 0) {

  sshlog("sshconnect2.c", __func__, 1532, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "cannot handle key");
  goto out;
 }

 ssh_dispatch_set(ssh, 60, &input_userauth_pk_ok);

 if ((r = sshpkt_start(ssh, 50)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->server_user)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->service)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->method->name)) != 0 ||
     (r = sshpkt_put_u8(ssh, have_sig)) != 0 ||
     (r = sshpkt_put_cstring(ssh, alg)) != 0 ||
     (r = sshpkt_put_string(ssh, blob, bloblen)) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  sshfatal("sshconnect2.c", __func__, 1546, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send packet");
 sent = 1;

 out:
 free(alg);
 free(blob);
 return sent;
}

static struct sshkey *
load_identity_file(Identity *id)
{
 struct sshkey *private = 
                         ((void *)0)
                             ;
 char prompt[300], *passphrase, *comment;
 int r, quit = 0, i;
 struct stat st;

 if (stat(id->filename, &st) == -1) {
  sshlog("sshconnect2.c", __func__, 1564, 0, id->userprovided ? SYSLOG_LEVEL_INFO : SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "no such identity: %s: %s", id->filename, strerror(
 (*__errno_location ())
 ))

                                                                ;
  return 
        ((void *)0)
            ;
 }
 snprintf(prompt, sizeof prompt,
     "Enter passphrase for key '%.100s': ", id->filename);
 for (i = 0; i <= options.number_of_password_prompts; i++) {
  if (i == 0)
   passphrase = "";
  else {
   passphrase = read_passphrase(prompt, 0);
   if (*passphrase == '\0') {
    sshlog("sshconnect2.c", __func__, 1577, 0, SYSLOG_LEVEL_DEBUG2, 
   ((void *)0)
   , "no passphrase given, try next key");
    free(passphrase);
    break;
   }
  }
  switch ((r = sshkey_load_private_type(KEY_UNSPEC, id->filename,
      passphrase, &private, &comment))) {
  case 0:
   break;
  case -43:
   if (options.batch_mode) {
    quit = 1;
    break;
   }
   if (i != 0)
    sshlog("sshconnect2.c", __func__, 1592, 0, SYSLOG_LEVEL_DEBUG2, 
   ((void *)0)
   , "bad passphrase given, try again...");
   break;
  case -24:
   if (
      (*__errno_location ()) 
            == 
               2
                     ) {
    sshlog("sshconnect2.c", __func__, 1596, 0, SYSLOG_LEVEL_DEBUG2, ssh_err(r), "Load key \"%s\"", id->filename);
    quit = 1;
    break;
   }

  default:
   sshlog("sshconnect2.c", __func__, 1602, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Load key \"%s\"", id->filename);
   quit = 1;
   break;
  }
  if (private != 
                ((void *)0) 
                     && sshkey_is_sk(private) &&
      options.sk_provider == 
                            ((void *)0)
                                ) {
   sshlog("sshconnect2.c", __func__, 1608, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "key \"%s\" is an authenticator-hosted key, " "but no provider specified", id->filename)
                                                 ;
   sshkey_free(private);
   private = 
            ((void *)0)
                ;
   quit = 1;
  }
  if (!quit && (r = sshkey_check_rsa_length(private,
      options.required_rsa_size)) != 0) {
   sshlog("sshconnect2.c", __func__, 1616, 1, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "Skipping key %s", id->filename);
   sshkey_free(private);
   private = 
            ((void *)0)
                ;
   quit = 1;
  }
  if (!quit && private != 
                         ((void *)0) 
                              && id->agent_fd == -1 &&
      !(id->key && id->isprivate))
   maybe_add_key_to_agent(id->filename, private, comment,
       passphrase);
  if (i > 0)
   freezero(passphrase, strlen(passphrase));
  free(comment);
  if (private != 
                ((void *)0) 
                     || quit)
   break;
 }
 return private;
}

static int
key_type_allowed_by_config(struct sshkey *key)
{
 if (match_pattern_list(sshkey_ssh_name(key),
     options.pubkey_accepted_algos, 0) == 1)
  return 1;


 switch (key->type) {
 case KEY_RSA:
  if (match_pattern_list("rsa-sha2-512",
      options.pubkey_accepted_algos, 0) == 1)
   return 1;
  if (match_pattern_list("rsa-sha2-256",
      options.pubkey_accepted_algos, 0) == 1)
   return 1;
  break;
 case KEY_RSA_CERT:
  if (match_pattern_list("rsa-sha2-512-cert-v01@openssh.com",
      options.pubkey_accepted_algos, 0) == 1)
   return 1;
  if (match_pattern_list("rsa-sha2-256-cert-v01@openssh.com",
      options.pubkey_accepted_algos, 0) == 1)
   return 1;
  break;
 }
 return 0;
}


static int
get_agent_identities(struct ssh *ssh, int *agent_fdp,
    struct ssh_identitylist **idlistp)
{
 int r, agent_fd;
 struct ssh_identitylist *idlist;

 if ((r = ssh_get_authentication_socket(&agent_fd)) != 0) {
  if (r != -47)
   sshlog("sshconnect2.c", __func__, 1673, 1, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "ssh_get_authentication_socket");
  return r;
 }
 if ((r = ssh_agent_bind_hostkey(agent_fd, ssh->kex->initial_hostkey,
     ssh->kex->session_id, ssh->kex->initial_sig, 0)) == 0)
  sshlog("sshconnect2.c", __func__, 1678, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "bound agent to hostkey");
 else
  sshlog("sshconnect2.c", __func__, 1680, 1, SYSLOG_LEVEL_DEBUG2, ssh_err(r), "ssh_agent_bind_hostkey");

 if ((r = ssh_fetch_identitylist(agent_fd, &idlist)) != 0) {
  sshlog("sshconnect2.c", __func__, 1683, 1, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "ssh_fetch_identitylist");
  close(agent_fd);
  return r;
 }

 *agent_fdp = agent_fd;
 *idlistp = idlist;
 sshlog("sshconnect2.c", __func__, 1690, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "agent returned %zu keys", idlist->nkeys);
 return 0;
}
static void
pubkey_prepare(struct ssh *ssh, Authctxt *authctxt)
{
 struct identity *id, *id2, *tmp;
 struct idlist agent, files, *preferred;
 struct sshkey *key;
 int agent_fd = -1, i, r, found;
 size_t j;
 struct ssh_identitylist *idlist;
 char *ident;

 do { (&agent)->tqh_first = 
((void *)0)
; (&agent)->tqh_last = &(&agent)->tqh_first; } while (0);
 do { (&files)->tqh_first = 
((void *)0)
; (&files)->tqh_last = &(&files)->tqh_first; } while (0);
 preferred = &authctxt->keys;
 do { (preferred)->tqh_first = 
((void *)0)
; (preferred)->tqh_last = &(preferred)->tqh_first; } while (0);


 for (i = 0; i < options.num_identity_files; i++) {
  key = options.identity_keys[i];
  if (key && key->cert &&
      key->cert->type != 1) {
   sshlog("sshconnect2.c", __func__, 1723, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "ignoring certificate %s: not a user " "certificate", options.identity_files[i])
                                                ;
   continue;
  }
  if (key && sshkey_is_sk(key) && options.sk_provider == 
                                                        ((void *)0)
                                                            ) {
   sshlog("sshconnect2.c", __func__, 1728, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "ignoring authenticator-hosted key %s as no " "SecurityKeyProvider has been specified", options.identity_files[i])

                                 ;
   continue;
  }
  options.identity_keys[i] = 
                            ((void *)0)
                                ;
  id = xcalloc(1, sizeof(*id));
  id->agent_fd = -1;
  id->key = key;
  id->filename = xstrdup(options.identity_files[i]);
  id->userprovided = options.identity_file_userprovided[i];
  do { (id)->next.tqe_next = 
 ((void *)0)
 ; (id)->next.tqe_prev = (&files)->tqh_last; *(&files)->tqh_last = (id); (&files)->tqh_last = &(id)->next.tqe_next; } while (0);
 }

 for (i = 0; i < options.num_certificate_files; i++) {
  key = options.certificates[i];
  if (!sshkey_is_cert(key) || key->cert == 
                                          ((void *)0) 
                                               ||
      key->cert->type != 1) {
   sshlog("sshconnect2.c", __func__, 1746, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "ignoring certificate %s: not a user " "certificate", options.identity_files[i])
                                                ;
   continue;
  }
  if (key && sshkey_is_sk(key) && options.sk_provider == 
                                                        ((void *)0)
                                                            ) {
   sshlog("sshconnect2.c", __func__, 1751, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "ignoring authenticator-hosted key " "certificate %s as no " "SecurityKeyProvider has been specified", options.identity_files[i])


                                 ;
   continue;
  }
  id = xcalloc(1, sizeof(*id));
  id->agent_fd = -1;
  id->key = key;
  id->filename = xstrdup(options.certificate_files[i]);
  id->userprovided = options.certificate_file_userprovided[i];
  do { (id)->next.tqe_next = 
 ((void *)0)
 ; (id)->next.tqe_prev = (preferred)->tqh_last; *(preferred)->tqh_last = (id); (preferred)->tqh_last = &(id)->next.tqe_next; } while (0);
 }

 if ((r = get_agent_identities(ssh, &agent_fd, &idlist)) == 0) {
  for (j = 0; j < idlist->nkeys; j++) {
   if ((r = sshkey_check_rsa_length(idlist->keys[j],
       options.required_rsa_size)) != 0) {
    sshlog("sshconnect2.c", __func__, 1769, 1, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "ignoring %s agent key", sshkey_ssh_name(idlist->keys[j]))
                                         ;
    continue;
   }
   found = 0;
   for((id) = ((&files)->tqh_first); (id) != 
  ((void *)0)
  ; (id) = ((id)->next.tqe_next)) {




    if (sshkey_equal(idlist->keys[j], id->key)) {
     do { if (((id)->next.tqe_next) != 
    ((void *)0)
    ) (id)->next.tqe_next->next.tqe_prev = (id)->next.tqe_prev; else (&files)->tqh_last = (id)->next.tqe_prev; *(id)->next.tqe_prev = (id)->next.tqe_next; ; ; } while (0);
     do { (id)->next.tqe_next = 
    ((void *)0)
    ; (id)->next.tqe_prev = (preferred)->tqh_last; *(preferred)->tqh_last = (id); (preferred)->tqh_last = &(id)->next.tqe_next; } while (0);
     id->agent_fd = agent_fd;
     found = 1;
     break;
    }
   }
   if (!found && !options.identities_only) {
    id = xcalloc(1, sizeof(*id));

    id->key = idlist->keys[j];
    id->filename = idlist->comments[j];
    idlist->keys[j] = 
                     ((void *)0)
                         ;
    idlist->comments[j] = 
                         ((void *)0)
                             ;
    id->agent_fd = agent_fd;
    do { (id)->next.tqe_next = 
   ((void *)0)
   ; (id)->next.tqe_prev = (&agent)->tqh_last; *(&agent)->tqh_last = (id); (&agent)->tqh_last = &(id)->next.tqe_next; } while (0);
   }
  }
  ssh_free_identitylist(idlist);

  do { if (!(((&agent)->tqh_first) == 
 ((void *)0)
 )) { *(preferred)->tqh_last = (&agent)->tqh_first; (&agent)->tqh_first->next.tqe_prev = (preferred)->tqh_last; (preferred)->tqh_last = (&agent)->tqh_last; do { ((&agent))->tqh_first = 
 ((void *)0)
 ; ((&agent))->tqh_last = &((&agent))->tqh_first; } while (0); } } while (0);
  authctxt->agent_fd = agent_fd;
 }

 for ((id) = ((&files)->tqh_first); (id) != 
((void *)0) 
&& ((tmp) = ((id)->next.tqe_next), 1); (id) = (tmp)) {
  if (id->key == 
                ((void *)0) 
                     || (id->key->flags & 0x0001) == 0)
   continue;
  found = 0;
  for((id2) = ((&files)->tqh_first); (id2) != 
 ((void *)0)
 ; (id2) = ((id2)->next.tqe_next)) {
   if (id2->key == 
                  ((void *)0) 
                       ||
       (id2->key->flags & 0x0001) != 0)
    continue;
   if (sshkey_equal(id->key, id2->key)) {
    do { if (((id)->next.tqe_next) != 
   ((void *)0)
   ) (id)->next.tqe_next->next.tqe_prev = (id)->next.tqe_prev; else (&files)->tqh_last = (id)->next.tqe_prev; *(id)->next.tqe_prev = (id)->next.tqe_next; ; ; } while (0);
    do { (id)->next.tqe_next = 
   ((void *)0)
   ; (id)->next.tqe_prev = (preferred)->tqh_last; *(preferred)->tqh_last = (id); (preferred)->tqh_last = &(id)->next.tqe_next; } while (0);
    found = 1;
    break;
   }
  }

  if (!found && options.identities_only) {
   do { if (((id)->next.tqe_next) != 
  ((void *)0)
  ) (id)->next.tqe_next->next.tqe_prev = (id)->next.tqe_prev; else (&files)->tqh_last = (id)->next.tqe_prev; *(id)->next.tqe_prev = (id)->next.tqe_next; ; ; } while (0);
   freezero(id, sizeof(*id));
  }
 }

 do { if (!(((&files)->tqh_first) == 
((void *)0)
)) { *(preferred)->tqh_last = (&files)->tqh_first; (&files)->tqh_first->next.tqe_prev = (preferred)->tqh_last; (preferred)->tqh_last = (&files)->tqh_last; do { ((&files))->tqh_first = 
((void *)0)
; ((&files))->tqh_last = &((&files))->tqh_first; } while (0); } } while (0);

 for ((id) = ((preferred)->tqh_first); (id) != 
((void *)0) 
&& ((id2) = ((id)->next.tqe_next), 1); (id) = (id2)) {
  if (id->key != 
                ((void *)0) 
                     && !key_type_allowed_by_config(id->key)) {
   sshlog("sshconnect2.c", __func__, 1830, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Skipping %s key %s - " "corresponding algo not in PubkeyAcceptedAlgorithms", sshkey_ssh_name(id->key), id->filename)

                                              ;
   do { if (((id)->next.tqe_next) != 
  ((void *)0)
  ) (id)->next.tqe_next->next.tqe_prev = (id)->next.tqe_prev; else (preferred)->tqh_last = (id)->next.tqe_prev; *(id)->next.tqe_prev = (id)->next.tqe_next; ; ; } while (0);
   sshkey_free(id->key);
   free(id->filename);
   memset(id, 0, sizeof(*id));
   continue;
  }
 }

 for ((id) = ((preferred)->tqh_first); (id) != 
((void *)0) 
&& ((id2) = ((id)->next.tqe_next), 1); (id) = (id2)) {
  ident = format_identity(id);
  sshlog("sshconnect2.c", __func__, 1843, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Will attempt key: %s", ident);
  free(ident);
 }
 sshlog("sshconnect2.c", __func__, 1846, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "done");
}

static void
pubkey_cleanup(struct ssh *ssh)
{
 Authctxt *authctxt = (Authctxt *)ssh->authctxt;
 Identity *id;

 if (authctxt->agent_fd != -1) {
  ssh_close_authentication_socket(authctxt->agent_fd);
  authctxt->agent_fd = -1;
 }
 for (id = ((&authctxt->keys)->tqh_first); id;
     id = ((&authctxt->keys)->tqh_first)) {
  do { if (((id)->next.tqe_next) != 
 ((void *)0)
 ) (id)->next.tqe_next->next.tqe_prev = (id)->next.tqe_prev; else (&authctxt->keys)->tqh_last = (id)->next.tqe_prev; *(id)->next.tqe_prev = (id)->next.tqe_next; ; ; } while (0);
  sshkey_free(id->key);
  free(id->filename);
  free(id);
 }
}

static void
pubkey_reset(Authctxt *authctxt)
{
 Identity *id;

 for((id) = ((&authctxt->keys)->tqh_first); (id) != 
((void *)0)
; (id) = ((id)->next.tqe_next))
  id->tried = 0;
}

static int
try_identity(struct ssh *ssh, Identity *id)
{
 if (!id->key)
  return (0);
 if (sshkey_type_plain(id->key->type) == KEY_RSA &&
     (ssh->compat & 0x00002000) != 0) {
  sshlog("sshconnect2.c", __func__, 1884, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Skipped %s key %s for RSA/MD5 server", sshkey_type(id->key), id->filename)
                                         ;
  return (0);
 }
 return 1;
}

static int
userauth_pubkey(struct ssh *ssh)
{
 Authctxt *authctxt = (Authctxt *)ssh->authctxt;
 Identity *id;
 int sent = 0;
 char *ident;

 while ((id = ((&authctxt->keys)->tqh_first))) {
  if (id->tried++)
   return (0);

  do { if (((id)->next.tqe_next) != 
 ((void *)0)
 ) (id)->next.tqe_next->next.tqe_prev = (id)->next.tqe_prev; else (&authctxt->keys)->tqh_last = (id)->next.tqe_prev; *(id)->next.tqe_prev = (id)->next.tqe_next; ; ; } while (0);
  do { (id)->next.tqe_next = 
 ((void *)0)
 ; (id)->next.tqe_prev = (&authctxt->keys)->tqh_last; *(&authctxt->keys)->tqh_last = (id); (&authctxt->keys)->tqh_last = &(id)->next.tqe_next; } while (0);





  if (id->key != 
                ((void *)0)
                    ) {
   if (try_identity(ssh, id)) {
    ident = format_identity(id);
    sshlog("sshconnect2.c", __func__, 1913, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "Offering public key: %s", ident);
    free(ident);
    sent = send_pubkey_test(ssh, id);
   }
  } else {
   sshlog("sshconnect2.c", __func__, 1918, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Trying private key: %s", id->filename);
   id->key = load_identity_file(id);
   if (id->key != 
                 ((void *)0)
                     ) {
    if (try_identity(ssh, id)) {
     id->isprivate = 1;
     sent = sign_and_send_pubkey(ssh, id);
    }
    sshkey_free(id->key);
    id->key = 
             ((void *)0)
                 ;
    id->isprivate = 0;
   }
  }
  if (sent)
   return (sent);
 }
 return (0);
}




static int
userauth_kbdint(struct ssh *ssh)
{
 Authctxt *authctxt = (Authctxt *)ssh->authctxt;
 int r;

 if (authctxt->attempt_kbdint++ >= options.number_of_password_prompts)
  return 0;

 if (authctxt->attempt_kbdint > 1 && !authctxt->info_req_seen) {
  sshlog("sshconnect2.c", __func__, 1949, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "userauth_kbdint: disable: no info_req_seen");
  ssh_dispatch_set(ssh, 60, 
                                                       ((void *)0)
                                                           );
  return 0;
 }

 sshlog("sshconnect2.c", __func__, 1954, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "userauth_kbdint");
 if ((r = sshpkt_start(ssh, 50)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->server_user)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->service)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->method->name)) != 0 ||
     (r = sshpkt_put_cstring(ssh, "")) != 0 ||
     (r = sshpkt_put_cstring(ssh, options.kbd_interactive_devices ?
     options.kbd_interactive_devices : "")) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  sshfatal("sshconnect2.c", __func__, 1963, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send packet");

 ssh_dispatch_set(ssh, 60, &input_userauth_info_req);
 return 1;
}




static int
input_userauth_info_req(int type, u_int32_t seq, struct ssh *ssh)
{
 Authctxt *authctxt = ssh->authctxt;
 char *name = 
             ((void *)0)
                 , *inst = 
                           ((void *)0)
                               , *lang = 
                                         ((void *)0)
                                             , *prompt = 
                                                         ((void *)0)
                                                             ;
 char *display_prompt = 
                       ((void *)0)
                           , *response = 
                                         ((void *)0)
                                             ;
 u_char echo = 0;
 u_int num_prompts, i;
 int r;

 sshlog("sshconnect2.c", __func__, 1982, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "entering");

 if (authctxt == 
                ((void *)0)
                    )
  sshfatal("sshconnect2.c", __func__, 1985, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "no authentication context");

 authctxt->info_req_seen = 1;

 if ((r = sshpkt_get_cstring(ssh, &name, 
                                        ((void *)0)
                                            )) != 0 ||
     (r = sshpkt_get_cstring(ssh, &inst, 
                                        ((void *)0)
                                            )) != 0 ||
     (r = sshpkt_get_cstring(ssh, &lang, 
                                        ((void *)0)
                                            )) != 0)
  goto out;
 if (strlen(name) > 0)
  sshlog("sshconnect2.c", __func__, 1994, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "%s", name);
 if (strlen(inst) > 0)
  sshlog("sshconnect2.c", __func__, 1996, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "%s", inst);

 if ((r = sshpkt_get_u32(ssh, &num_prompts)) != 0)
  goto out;






 if ((r = sshpkt_start(ssh, 61)) != 0 ||
     (r = sshpkt_put_u32(ssh, num_prompts)) != 0)
  goto out;

 sshlog("sshconnect2.c", __func__, 2010, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "num_prompts %d", num_prompts);
 for (i = 0; i < num_prompts; i++) {
  if ((r = sshpkt_get_cstring(ssh, &prompt, 
                                           ((void *)0)
                                               )) != 0 ||
      (r = sshpkt_get_u8(ssh, &echo)) != 0)
   goto out;
  if (asmprintf(&display_prompt, 0x7fffffff, 
                                         ((void *)0)
                                             , "(%s@%s) %s",
      authctxt->server_user, options.host_key_alias ?
      options.host_key_alias : authctxt->host, prompt) == -1)
   sshfatal("sshconnect2.c", __func__, 2018, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "asmprintf failed");
  response = read_passphrase(display_prompt, echo ? 0x0001 : 0);
  if ((r = sshpkt_put_cstring(ssh, response)) != 0)
   goto out;
  freezero(response, strlen(response));
  free(prompt);
  free(display_prompt);
  display_prompt = response = prompt = 
                                      ((void *)0)
                                          ;
 }

 if ((r = sshpkt_get_end(ssh)) != 0 ||
     (r = sshpkt_add_padding(ssh, 64)) != 0)
  goto out;
 r = sshpkt_send(ssh);
 out:
 if (response)
  freezero(response, strlen(response));
 free(prompt);
 free(display_prompt);
 free(name);
 free(inst);
 free(lang);
 return r;
}

static int
ssh_keysign(struct ssh *ssh, struct sshkey *key, u_char **sigp, size_t *lenp,
    const u_char *data, size_t datalen)
{
 struct sshbuf *b;
 struct stat st;
 pid_t pid;
 int r, to[2], from[2], status;
 int sock = ssh_packet_get_connection_in(ssh);
 u_char rversion = 0, version = 2;
 void (*osigchld)(int);

 *sigp = 
        ((void *)0)
            ;
 *lenp = 0;

 if (stat("/usr/local/libexec/ssh-keysign", &st) == -1) {
  sshlog("sshconnect2.c", __func__, 2059, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "not installed: %s", strerror(
 (*__errno_location ())
 ));
  return -1;
 }
 if (fflush(
           stdout
                 ) != 0) {
  sshlog("sshconnect2.c", __func__, 2063, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "fflush: %s", strerror(
 (*__errno_location ())
 ));
  return -1;
 }
 if (pipe(to) == -1) {
  sshlog("sshconnect2.c", __func__, 2067, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "pipe: %s", strerror(
 (*__errno_location ())
 ));
  return -1;
 }
 if (pipe(from) == -1) {
  sshlog("sshconnect2.c", __func__, 2071, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "pipe: %s", strerror(
 (*__errno_location ())
 ));
  return -1;
 }
 if ((pid = fork()) == -1) {
  sshlog("sshconnect2.c", __func__, 2075, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "fork: %s", strerror(
 (*__errno_location ())
 ));
  return -1;
 }
 osigchld = ssh_signal(
                      17
                             , 
                               ((__sighandler_t) 0)
                                      );
 if (pid == 0) {
  close(from[0]);
  if (dup2(from[1], 
                   1
                                ) == -1)
   sshfatal("sshconnect2.c", __func__, 2082, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "dup2: %s", strerror(
  (*__errno_location ())
  ));
  close(to[1]);
  if (dup2(to[0], 
                 0
                             ) == -1)
   sshfatal("sshconnect2.c", __func__, 2085, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "dup2: %s", strerror(
  (*__errno_location ())
  ));
  close(from[1]);
  close(to[0]);

  if (dup2(sock, 
                2 
                              + 1) == -1)
   sshfatal("sshconnect2.c", __func__, 2090, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "dup2: %s", strerror(
  (*__errno_location ())
  ));
  sock = 
        2 
                      + 1;
  fcntl(sock, 
             2
                    , 0);
  closefrom(sock + 1);

  sshlog("sshconnect2.c", __func__, 2095, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "[child] pid=%ld, exec %s", (long)getpid(), "/usr/local/libexec/ssh-keysign")
                                         ;
  execl("/usr/local/libexec/ssh-keysign", "/usr/local/libexec/ssh-keysign", (char *)
                                                       ((void *)0)
                                                           );
  sshfatal("sshconnect2.c", __func__, 2098, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "exec(%s): %s", "/usr/local/libexec/ssh-keysign", strerror(
 (*__errno_location ())
 ))
                      ;
 }
 close(from[1]);
 close(to[0]);
 sock = 
       2 
                     + 1;

 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("sshconnect2.c", __func__, 2106, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");

 if ((r = sshbuf_put_u32(b, sock)) != 0 ||
     (r = sshbuf_put_string(b, data, datalen)) != 0)
  sshfatal("sshconnect2.c", __func__, 2110, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "buffer error");
 if (ssh_msg_send(to[1], version, b) == -1)
  sshfatal("sshconnect2.c", __func__, 2112, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "couldn't send request");
 sshbuf_reset(b);
 r = ssh_msg_recv(from[0], b);
 close(from[0]);
 close(to[1]);
 if (r < 0) {
  sshlog("sshconnect2.c", __func__, 2118, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "no reply");
  goto fail;
 }

 
(*__errno_location ()) 
      = 0;
 while (waitpid(pid, &status, 0) == -1) {
  if (
     (*__errno_location ()) 
           != 
              4
                   ) {
   sshlog("sshconnect2.c", __func__, 2125, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "waitpid %ld: %s", (long)pid, strerror(
  (*__errno_location ())
  ));
   goto fail;
  }
 }
 if (!
     (((
     status
     ) & 0x7f) == 0)
                      ) {
  sshlog("sshconnect2.c", __func__, 2130, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "exited abnormally");
  goto fail;
 }
 if (
    (((
    status
    ) & 0xff00) >> 8) 
                        != 0) {
  sshlog("sshconnect2.c", __func__, 2134, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "exited with status %d", 
 (((
 status
 ) & 0xff00) >> 8)
 );
  goto fail;
 }
 if ((r = sshbuf_get_u8(b, &rversion)) != 0) {
  sshlog("sshconnect2.c", __func__, 2138, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "buffer error");
  goto fail;
 }
 if (rversion != version) {
  sshlog("sshconnect2.c", __func__, 2142, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "bad version");
  goto fail;
 }
 if ((r = sshbuf_get_string(b, sigp, lenp)) != 0) {
  sshlog("sshconnect2.c", __func__, 2146, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "buffer error");
 fail:
  ssh_signal(
            17
                   , osigchld);
  sshbuf_free(b);
  return -1;
 }
 ssh_signal(
           17
                  , osigchld);
 sshbuf_free(b);

 return 0;
}

static int
userauth_hostbased(struct ssh *ssh)
{
 Authctxt *authctxt = (Authctxt *)ssh->authctxt;
 struct sshkey *private = 
                         ((void *)0)
                             ;
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 u_char *sig = 
              ((void *)0)
                  , *keyblob = 
                               ((void *)0)
                                   ;
 char *fp = 
           ((void *)0)
               , *chost = 
                          ((void *)0)
                              , *lname = 
                                         ((void *)0)
                                             ;
 size_t siglen = 0, keylen = 0;
 int i, r, success = 0;

 if (authctxt->ktypes == 
                        ((void *)0)
                            ) {
  authctxt->oktypes = xstrdup(options.hostbased_accepted_algos);
  authctxt->ktypes = authctxt->oktypes;
 }





 for (;;) {
  if (authctxt->active_ktype == 
                               ((void *)0)
                                   )
   authctxt->active_ktype = strsep(&authctxt->ktypes, ",");
  if (authctxt->active_ktype == 
                               ((void *)0) 
                                    ||
      *authctxt->active_ktype == '\0')
   break;
  sshlog("sshconnect2.c", __func__, 2184, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "trying key type %s", authctxt->active_ktype);


  private = 
           ((void *)0)
               ;
  for (i = 0; i < authctxt->sensitive->nkeys; i++) {
   if (authctxt->sensitive->keys[i] == 
                                      ((void *)0) 
                                           ||
       authctxt->sensitive->keys[i]->type == KEY_UNSPEC)
    continue;
   if (!sshkey_match_keyname_to_sigalgs(
       sshkey_ssh_name(authctxt->sensitive->keys[i]),
       authctxt->active_ktype))
    continue;

   private = authctxt->sensitive->keys[i];
   authctxt->sensitive->keys[i] = 
                                 ((void *)0)
                                     ;
   break;
  }

  if (private != 
                ((void *)0)
                    )
   break;

  authctxt->active_ktype = 
                          ((void *)0)
                              ;
 }
 if (private == 
               ((void *)0)
                   ) {
  free(authctxt->oktypes);
  authctxt->oktypes = authctxt->ktypes = 
                                        ((void *)0)
                                            ;
  authctxt->active_ktype = 
                          ((void *)0)
                              ;
  sshlog("sshconnect2.c", __func__, 2211, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "No more client hostkeys for hostbased authentication.");
  goto out;
 }

 if ((fp = sshkey_fingerprint(private, options.fingerprint_hash,
     SSH_FP_DEFAULT)) == 
                        ((void *)0)
                            ) {
  sshlog("sshconnect2.c", __func__, 2217, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshkey_fingerprint failed");
  goto out;
 }
 sshlog("sshconnect2.c", __func__, 2220, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "trying hostkey %s %s using sigalg %s", sshkey_ssh_name(private), fp, authctxt->active_ktype)
                                                          ;


 lname = get_local_name(ssh_packet_get_connection_in(ssh));
 if (lname == 
             ((void *)0)
                 ) {
  sshlog("sshconnect2.c", __func__, 2226, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "cannot get local ipaddr/name");
  goto out;
 }


 xasprintf(&chost, "%s.", lname);
 sshlog("sshconnect2.c", __func__, 2232, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "chost %s", chost);


 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              ) {
  sshlog("sshconnect2.c", __func__, 2236, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshbuf_new failed");
  goto out;
 }
 if ((r = sshkey_to_blob(private, &keyblob, &keylen)) != 0) {
  sshlog("sshconnect2.c", __func__, 2240, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshkey_to_blob");
  goto out;
 }
 if ((r = sshbuf_put_stringb(b, ssh->kex->session_id)) != 0 ||
     (r = sshbuf_put_u8(b, 50)) != 0 ||
     (r = sshbuf_put_cstring(b, authctxt->server_user)) != 0 ||
     (r = sshbuf_put_cstring(b, authctxt->service)) != 0 ||
     (r = sshbuf_put_cstring(b, authctxt->method->name)) != 0 ||
     (r = sshbuf_put_cstring(b, authctxt->active_ktype)) != 0 ||
     (r = sshbuf_put_string(b, keyblob, keylen)) != 0 ||
     (r = sshbuf_put_cstring(b, chost)) != 0 ||
     (r = sshbuf_put_cstring(b, authctxt->local_user)) != 0) {
  sshlog("sshconnect2.c", __func__, 2252, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "buffer error");
  goto out;
 }




 if ((r = ssh_keysign(ssh, private, &sig, &siglen,
     sshbuf_ptr(b), sshbuf_len(b))) != 0) {
  sshlog("sshconnect2.c", __func__, 2261, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sign using hostkey %s %s failed", sshkey_ssh_name(private), fp)
                                   ;
  goto out;
 }
 if ((r = sshpkt_start(ssh, 50)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->server_user)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->service)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->method->name)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->active_ktype)) != 0 ||
     (r = sshpkt_put_string(ssh, keyblob, keylen)) != 0 ||
     (r = sshpkt_put_cstring(ssh, chost)) != 0 ||
     (r = sshpkt_put_cstring(ssh, authctxt->local_user)) != 0 ||
     (r = sshpkt_put_string(ssh, sig, siglen)) != 0 ||
     (r = sshpkt_send(ssh)) != 0) {
  sshlog("sshconnect2.c", __func__, 2275, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "packet error");
  goto out;
 }
 success = 1;

 out:
 if (sig != 
           ((void *)0)
               )
  freezero(sig, siglen);
 free(keyblob);
 free(lname);
 free(fp);
 free(chost);
 sshkey_free(private);
 sshbuf_free(b);

 return success;
}







static int
authmethod_is_enabled(Authmethod *method)
{
 if (method == 
              ((void *)0)
                  )
  return 0;

 if (method->enabled == 
                        ((void *)0) 
                             || *method->enabled == 0)
  return 0;

 if (method->batch_flag != 
                           ((void *)0) 
                                && *method->batch_flag != 0)
  return 0;
 return 1;
}

static Authmethod *
authmethod_lookup(const char *name)
{
 Authmethod *method = 
                     ((void *)0)
                         ;
 if (name != 
            ((void *)0)
                )
  for (method = authmethods; method->name != 
                                            ((void *)0)
                                                ; method++)
   if (strcmp(name, method->name) == 0)
    return method;
 sshlog("sshconnect2.c", __func__, 2321, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "Unrecognized authentication method name: %s", name ? name : "NULL");
 return 
       ((void *)0)
           ;
}


static Authmethod *current = 
                            ((void *)0)
                                ;
static char *supported = 
                        ((void *)0)
                            ;
static char *preferred = 
                        ((void *)0)
                            ;






static Authmethod *
authmethod_get(char *authlist)
{
 char *name = 
             ((void *)0)
                 ;
 u_int next;


 if (authlist == 
                ((void *)0) 
                     || strlen(authlist) == 0)
  authlist = options.preferred_authentications;

 if (supported == 
                 ((void *)0) 
                      || strcmp(authlist, supported) != 0) {
  sshlog("sshconnect2.c", __func__, 2346, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "start over, passed a different list %s", authlist);
  free(supported);
  supported = xstrdup(authlist);
  preferred = options.preferred_authentications;
  sshlog("sshconnect2.c", __func__, 2350, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "preferred %s", preferred);
  current = 
           ((void *)0)
               ;
 } else if (current != 
                      ((void *)0) 
                           && authmethod_is_enabled(current))
  return current;

 for (;;) {
  if ((name = match_list(preferred, supported, &next)) == 
                                                         ((void *)0)
                                                             ) {
   sshlog("sshconnect2.c", __func__, 2357, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "No more authentication methods to try.");
   current = 
            ((void *)0)
                ;
   return 
         ((void *)0)
             ;
  }
  preferred += next;
  sshlog("sshconnect2.c", __func__, 2362, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "authmethod_lookup %s", name);
  sshlog("sshconnect2.c", __func__, 2363, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "remaining preferred: %s", preferred);
  if ((current = authmethod_lookup(name)) != 
                                            ((void *)0) 
                                                 &&
      authmethod_is_enabled(current)) {
   sshlog("sshconnect2.c", __func__, 2366, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "authmethod_is_enabled %s", name);
   sshlog("sshconnect2.c", __func__, 2367, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Next authentication method: %s", name);
   free(name);
   return current;
  }
  free(name);
 }
}

static char *
authmethods_get(void)
{
 Authmethod *method = 
                     ((void *)0)
                         ;
 struct sshbuf *b;
 char *list;
 int r;

 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("sshconnect2.c", __func__, 2384, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 for (method = authmethods; method->name != 
                                           ((void *)0)
                                               ; method++) {
  if (authmethod_is_enabled(method)) {
   if ((r = sshbuf_putf(b, "%s%s",
       sshbuf_len(b) ? "," : "", method->name)) != 0)
    sshfatal("sshconnect2.c", __func__, 2389, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "buffer error");
  }
 }
 if ((list = sshbuf_dup_string(b)) == 
                                     ((void *)0)
                                         )
  sshfatal("sshconnect2.c", __func__, 2393, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_dup_string failed");
 sshbuf_free(b);
 return list;
}
