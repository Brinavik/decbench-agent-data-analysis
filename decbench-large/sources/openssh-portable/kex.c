











































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

enum monitor_reqtype {
 MONITOR_REQ_MODULI = 0, MONITOR_ANS_MODULI = 1,
 MONITOR_REQ_FREE = 2,
 MONITOR_REQ_AUTHSERV = 4,
 MONITOR_REQ_SIGN = 6, MONITOR_ANS_SIGN = 7,
 MONITOR_REQ_PWNAM = 8, MONITOR_ANS_PWNAM = 9,
 MONITOR_REQ_AUTH2_READ_BANNER = 10, MONITOR_ANS_AUTH2_READ_BANNER = 11,
 MONITOR_REQ_AUTHPASSWORD = 12, MONITOR_ANS_AUTHPASSWORD = 13,
 MONITOR_REQ_BSDAUTHQUERY = 14, MONITOR_ANS_BSDAUTHQUERY = 15,
 MONITOR_REQ_BSDAUTHRESPOND = 16, MONITOR_ANS_BSDAUTHRESPOND = 17,
 MONITOR_REQ_KEYALLOWED = 22, MONITOR_ANS_KEYALLOWED = 23,
 MONITOR_REQ_KEYVERIFY = 24, MONITOR_ANS_KEYVERIFY = 25,
 MONITOR_REQ_KEYEXPORT = 26,
 MONITOR_REQ_PTY = 28, MONITOR_ANS_PTY = 29,
 MONITOR_REQ_PTYCLEANUP = 30,
 MONITOR_REQ_SESSKEY = 32, MONITOR_ANS_SESSKEY = 33,
 MONITOR_REQ_SESSID = 34,
 MONITOR_REQ_RSAKEYALLOWED = 36, MONITOR_ANS_RSAKEYALLOWED = 37,
 MONITOR_REQ_RSACHALLENGE = 38, MONITOR_ANS_RSACHALLENGE = 39,
 MONITOR_REQ_RSARESPONSE = 40, MONITOR_ANS_RSARESPONSE = 41,
 MONITOR_REQ_GSSSETUP = 42, MONITOR_ANS_GSSSETUP = 43,
 MONITOR_REQ_GSSSTEP = 44, MONITOR_ANS_GSSSTEP = 45,
 MONITOR_REQ_GSSUSEROK = 46, MONITOR_ANS_GSSUSEROK = 47,
 MONITOR_REQ_GSSCHECKMIC = 48, MONITOR_ANS_GSSCHECKMIC = 49,
 MONITOR_REQ_TERM = 50,

 MONITOR_REQ_PAM_START = 100,
 MONITOR_REQ_PAM_ACCOUNT = 102, MONITOR_ANS_PAM_ACCOUNT = 103,
 MONITOR_REQ_PAM_INIT_CTX = 104, MONITOR_ANS_PAM_INIT_CTX = 105,
 MONITOR_REQ_PAM_QUERY = 106, MONITOR_ANS_PAM_QUERY = 107,
 MONITOR_REQ_PAM_RESPOND = 108, MONITOR_ANS_PAM_RESPOND = 109,
 MONITOR_REQ_PAM_FREE_CTX = 110, MONITOR_ANS_PAM_FREE_CTX = 111,
 MONITOR_REQ_AUDIT_EVENT = 112, MONITOR_REQ_AUDIT_COMMAND = 113,

};

struct ssh;

struct monitor {
 int m_recvfd;
 int m_sendfd;
 int m_log_recvfd;
 int m_log_sendfd;
 struct kex **m_pkex;
 pid_t m_pid;
};

struct monitor *monitor_init(void);
void monitor_reinit(struct monitor *);

struct Authctxt;
void monitor_child_preauth(struct ssh *, struct monitor *);
void monitor_child_postauth(struct ssh *, struct monitor *);

void monitor_clear_keystate(struct ssh *, struct monitor *);
void monitor_apply_keystate(struct ssh *, struct monitor *);


void mm_request_send(int, enum monitor_reqtype, struct sshbuf *);
void mm_request_receive(int, struct sshbuf *);
void mm_request_receive_expect(int, enum monitor_reqtype, struct sshbuf *);
void mm_get_keystate(struct ssh *, struct monitor *);


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


static int kex_choose_conf(struct ssh *);
static int kex_input_newkeys(int, u_int32_t, struct ssh *);

static const char * const proposal_names[PROPOSAL_MAX] = {
 "KEX algorithms",
 "host key algorithms",
 "ciphers ctos",
 "ciphers stoc",
 "MACs ctos",
 "MACs stoc",
 "compression ctos",
 "compression stoc",
 "languages ctos",
 "languages stoc",
};

struct kexalg {
 char *name;
 u_int type;
 int ec_nid;
 int hash_alg;
};
static const struct kexalg kexalgs[] = {

 { "diffie-hellman-group1-sha1", KEX_DH_GRP1_SHA1, 0, 1 },
 { "diffie-hellman-group14-sha1", KEX_DH_GRP14_SHA1, 0, 1 },
 { "diffie-hellman-group14-sha256", KEX_DH_GRP14_SHA256, 0, 2 },
 { "diffie-hellman-group16-sha512", KEX_DH_GRP16_SHA512, 0, 4 },
 { "diffie-hellman-group18-sha512", KEX_DH_GRP18_SHA512, 0, 4 },
 { "diffie-hellman-group-exchange-sha1", KEX_DH_GEX_SHA1, 0, 1 },

 { "diffie-hellman-group-exchange-sha256", KEX_DH_GEX_SHA256, 0, 2 },


 { "ecdh-sha2-nistp256", KEX_ECDH_SHA2,
     
    415
                        , 2 },
 { "ecdh-sha2-nistp384", KEX_ECDH_SHA2, 
                                         715
                                                      ,
     3 },

 { "ecdh-sha2-nistp521", KEX_ECDH_SHA2, 
                                         716
                                                      ,
     4 },




 { "curve25519-sha256", KEX_C25519_SHA256, 0, 2 },
 { "curve25519-sha256@libssh.org", KEX_C25519_SHA256, 0, 2 },

 { "sntrup761x25519-sha512@openssh.com", KEX_KEM_SNTRUP761X25519_SHA512, 0,
     4 },


 { 
  ((void *)0)
      , 0, -1, -1},
};

char *
kex_alg_list(char sep)
{
 char *ret = 
            ((void *)0)
                , *tmp;
 size_t nlen, rlen = 0;
 const struct kexalg *k;

 for (k = kexalgs; k->name != 
                             ((void *)0)
                                 ; k++) {
  if (ret != 
            ((void *)0)
                )
   ret[rlen++] = sep;
  nlen = strlen(k->name);
  if ((tmp = realloc(ret, rlen + nlen + 2)) == 
                                              ((void *)0)
                                                  ) {
   free(ret);
   return 
         ((void *)0)
             ;
  }
  ret = tmp;
  memcpy(ret + rlen, k->name, nlen + 1);
  rlen += nlen;
 }
 return ret;
}

static const struct kexalg *
kex_alg_by_name(const char *name)
{
 const struct kexalg *k;

 for (k = kexalgs; k->name != 
                             ((void *)0)
                                 ; k++) {
  if (strcmp(k->name, name) == 0)
   return k;
 }
 return 
       ((void *)0)
           ;
}


int
kex_names_valid(const char *names)
{
 char *s, *cp, *p;

 if (names == 
             ((void *)0) 
                  || strcmp(names, "") == 0)
  return 0;
 if ((s = cp = strdup(names)) == 
                                ((void *)0)
                                    )
  return 0;
 for ((p = strsep(&cp, ",")); p && *p != '\0';
     (p = strsep(&cp, ","))) {
  if (kex_alg_by_name(p) == 
                           ((void *)0)
                               ) {
   sshlog("kex.c", __func__, 168, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Unsupported KEX algorithm \"%.100s\"", p);
   free(s);
   return 0;
  }
 }
 sshlog("kex.c", __func__, 173, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "kex names ok: [%s]", names);
 free(s);
 return 1;
}





char *
kex_names_cat(const char *a, const char *b)
{
 char *ret = 
            ((void *)0)
                , *tmp = 
                         ((void *)0)
                             , *cp, *p, *m;
 size_t len;

 if (a == 
         ((void *)0) 
              || *a == '\0')
  return strdup(b);
 if (b == 
         ((void *)0) 
              || *b == '\0')
  return strdup(a);
 if (strlen(b) > 1024*1024)
  return 
        ((void *)0)
            ;
 len = strlen(a) + strlen(b) + 2;
 if ((tmp = cp = strdup(b)) == 
                              ((void *)0) 
                                   ||
     (ret = calloc(1, len)) == 
                              ((void *)0)
                                  ) {
  free(tmp);
  return 
        ((void *)0)
            ;
 }
 strlcpy(ret, a, len);
 for ((p = strsep(&cp, ",")); p && *p != '\0'; (p = strsep(&cp, ","))) {
  if ((m = match_list(ret, p, 
                             ((void *)0)
                                 )) != 
                                       ((void *)0)
                                           ) {
   free(m);
   continue;
  }
  if (strlcat(ret, ",", len) >= len ||
      strlcat(ret, p, len) >= len) {
   free(tmp);
   free(ret);
   return 
         ((void *)0)
             ;
  }
 }
 free(tmp);
 return ret;
}
int
kex_assemble_names(char **listp, const char *def, const char *all)
{
 char *cp, *tmp, *patterns;
 char *list = 
             ((void *)0)
                 , *ret = 
                          ((void *)0)
                              , *matching = 
                                            ((void *)0)
                                                , *opatterns = 
                                                               ((void *)0)
                                                                   ;
 int r = -1;

 if (listp == 
             ((void *)0) 
                  || def == 
                            ((void *)0) 
                                 || all == 
                                           ((void *)0)
                                               )
  return -10;

 if (*listp == 
              ((void *)0) 
                   || **listp == '\0') {
  if ((*listp = strdup(def)) == 
                               ((void *)0)
                                   )
   return -2;
  return 0;
 }

 list = *listp;
 *listp = 
         ((void *)0)
             ;
 if (*list == '+') {

  if ((tmp = kex_names_cat(def, list + 1)) == 
                                             ((void *)0)
                                                 ) {
   r = -2;
   goto fail;
  }
  free(list);
  list = tmp;
 } else if (*list == '-') {

  if ((*listp = match_filter_denylist(def, list + 1)) == 
                                                        ((void *)0)
                                                            ) {
   r = -2;
   goto fail;
  }
  free(list);

  return 0;
 } else if (*list == '^') {

  if ((tmp = kex_names_cat(list + 1, def)) == 
                                             ((void *)0)
                                                 ) {
   r = -2;
   goto fail;
  }
  free(list);
  list = tmp;
 } else {

 }






 ret = 
      ((void *)0)
          ;
 if ((patterns = opatterns = strdup(list)) == 
                                             ((void *)0)
                                                 ) {
  r = -2;
  goto fail;
 }

 while ((cp = strsep(&patterns, ",")) != 
                                        ((void *)0)
                                            ) {
  if (*cp == '!') {

   r = -10;
   goto fail;
  }
  free(matching);
  if ((matching = match_filter_allowlist(all, cp)) == 
                                                     ((void *)0)
                                                         ) {
   r = -2;
   goto fail;
  }
  if ((tmp = kex_names_cat(ret, matching)) == 
                                             ((void *)0)
                                                 ) {
   r = -2;
   goto fail;
  }
  free(ret);
  ret = tmp;
 }
 if (ret == 
           ((void *)0) 
                || *ret == '\0') {


  r = -10;
  goto fail;
 }


 *listp = ret;
 ret = 
      ((void *)0)
          ;
 r = 0;

 fail:
 free(matching);
 free(opatterns);
 free(list);
 free(ret);
 return r;
}


int
kex_prop2buf(struct sshbuf *b, char *proposal[PROPOSAL_MAX])
{
 u_int i;
 int r;

 sshbuf_reset(b);





 for (i = 0; i < 16; i++) {
  if ((r = sshbuf_put_u8(b, 0)) != 0)
   return r;
 }
 for (i = 0; i < PROPOSAL_MAX; i++) {
  if ((r = sshbuf_put_cstring(b, proposal[i])) != 0)
   return r;
 }
 if ((r = sshbuf_put_u8(b, 0)) != 0 ||
     (r = sshbuf_put_u32(b, 0)) != 0)
  return r;
 return 0;
}


int
kex_buf2prop(struct sshbuf *raw, int *first_kex_follows, char ***propp)
{
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 u_char v;
 u_int i;
 char **proposal = 
                  ((void *)0)
                      ;
 int r;

 *propp = 
         ((void *)0)
             ;
 if ((proposal = calloc(PROPOSAL_MAX, sizeof(char *))) == 
                                                         ((void *)0)
                                                             )
  return -2;
 if ((b = sshbuf_fromb(raw)) == 
                               ((void *)0)
                                   ) {
  r = -2;
  goto out;
 }
 if ((r = sshbuf_consume(b, 16)) != 0) {
  sshlog("kex.c", __func__, 365, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "consume cookie");
  goto out;
 }

 for (i = 0; i < PROPOSAL_MAX; i++) {
  if ((r = sshbuf_get_cstring(b, &(proposal[i]), 
                                                ((void *)0)
                                                    )) != 0) {
   sshlog("kex.c", __func__, 371, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse proposal %u", i);
   goto out;
  }
  sshlog("kex.c", __func__, 374, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "%s: %s", proposal_names[i], proposal[i]);
 }

 if ((r = sshbuf_get_u8(b, &v)) != 0 ||
     (r = sshbuf_get_u32(b, &i)) != 0) {
  sshlog("kex.c", __func__, 379, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse");
  goto out;
 }
 if (first_kex_follows != 
                         ((void *)0)
                             )
  *first_kex_follows = v;
 sshlog("kex.c", __func__, 384, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "first_kex_follows %d ", v);
 sshlog("kex.c", __func__, 385, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "reserved %u ", i);
 r = 0;
 *propp = proposal;
 out:
 if (r != 0 && proposal != 
                          ((void *)0)
                              )
  kex_prop_free(proposal);
 sshbuf_free(b);
 return r;
}

void
kex_prop_free(char **proposal)
{
 u_int i;

 if (proposal == 
                ((void *)0)
                    )
  return;
 for (i = 0; i < PROPOSAL_MAX; i++)
  free(proposal[i]);
 free(proposal);
}


int
kex_protocol_error(int type, u_int32_t seq, struct ssh *ssh)
{
 int r;

 sshlog("kex.c", __func__, 413, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "kex protocol error: type %d seq %u", type, seq);
 if ((r = sshpkt_start(ssh, 3)) != 0 ||
     (r = sshpkt_put_u32(ssh, seq)) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  return r;
 return 0;
}

static void
kex_reset_dispatch(struct ssh *ssh)
{
 ssh_dispatch_range(ssh, 1,
     49, &kex_protocol_error);
}

static int
kex_send_ext_info(struct ssh *ssh)
{
 int r;
 char *algs;

 sshlog("kex.c", __func__, 434, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Sending SSH2_MSG_EXT_INFO");
 if ((algs = sshkey_alg_list(0, 1, 1, ',')) == 
                                              ((void *)0)
                                                  )
  return -2;

 if ((r = sshpkt_start(ssh, 7)) != 0 ||
     (r = sshpkt_put_u32(ssh, 2)) != 0 ||
     (r = sshpkt_put_cstring(ssh, "server-sig-algs")) != 0 ||
     (r = sshpkt_put_cstring(ssh, algs)) != 0 ||
     (r = sshpkt_put_cstring(ssh,
     "publickey-hostbound@openssh.com")) != 0 ||
     (r = sshpkt_put_cstring(ssh, "0")) != 0 ||
     (r = sshpkt_send(ssh)) != 0) {
  sshlog("kex.c", __func__, 446, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "compose");
  goto out;
 }

 r = 0;
 out:
 free(algs);
 return r;
}

int
kex_send_newkeys(struct ssh *ssh)
{
 int r;

 kex_reset_dispatch(ssh);
 if ((r = sshpkt_start(ssh, 21)) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  return r;
 sshlog("kex.c", __func__, 465, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "SSH2_MSG_NEWKEYS sent");
 ssh_dispatch_set(ssh, 21, &kex_input_newkeys);
 if (ssh->kex->ext_info_c && (ssh->kex->flags & 0x0002) != 0)
  if ((r = kex_send_ext_info(ssh)) != 0)
   return r;
 sshlog("kex.c", __func__, 470, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "expecting SSH2_MSG_NEWKEYS");
 return 0;
}

int
kex_input_ext_info(int type, u_int32_t seq, struct ssh *ssh)
{
 struct kex *kex = ssh->kex;
 u_int32_t i, ninfo;
 char *name;
 u_char *val;
 size_t vlen;
 int r;

 sshlog("kex.c", __func__, 484, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "SSH2_MSG_EXT_INFO received");
 ssh_dispatch_set(ssh, 7, &kex_protocol_error);
 if ((r = sshpkt_get_u32(ssh, &ninfo)) != 0)
  return r;
 for (i = 0; i < ninfo; i++) {
  if ((r = sshpkt_get_cstring(ssh, &name, 
                                         ((void *)0)
                                             )) != 0)
   return r;
  if ((r = sshpkt_get_string(ssh, &val, &vlen)) != 0) {
   free(name);
   return r;
  }
  if (strcmp(name, "server-sig-algs") == 0) {

   if (memchr(val, '\0', vlen) != 
                                 ((void *)0)
                                     ) {
    sshlog("kex.c", __func__, 498, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "nul byte in %s", name);
    return -4;
   }
   sshlog("kex.c", __func__, 501, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "%s=<%s>", name, val);
   kex->server_sig_algs = val;
   val = 
        ((void *)0)
            ;
  } else if (strcmp(name,
      "publickey-hostbound@openssh.com") == 0) {


   if (memchr(val, '\0', vlen) != 
                                 ((void *)0)
                                     ) {
    sshlog("kex.c", __func__, 509, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "nul byte in %s", name);
    return -4;
   }
   sshlog("kex.c", __func__, 512, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "%s=<%s>", name, val);
   if (strcmp(val, "0") == 0)
    kex->flags |= 0x0004;
   else {
    sshlog("kex.c", __func__, 516, 1, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "unsupported version of %s extension", name)
             ;
   }
  } else
   sshlog("kex.c", __func__, 520, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "%s (unrecognised)", name);
  free(name);
  free(val);
 }
 return sshpkt_get_end(ssh);
}

static int
kex_input_newkeys(int type, u_int32_t seq, struct ssh *ssh)
{
 struct kex *kex = ssh->kex;
 int r;

 sshlog("kex.c", __func__, 533, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "SSH2_MSG_NEWKEYS received");
 ssh_dispatch_set(ssh, 21, &kex_protocol_error);
 ssh_dispatch_set(ssh, 20, &kex_input_kexinit);
 if ((r = sshpkt_get_end(ssh)) != 0)
  return r;
 if ((r = ssh_set_newkeys(ssh, MODE_IN)) != 0)
  return r;
 kex->done = 1;
 kex->flags &= ~0x0002;
 sshbuf_reset(kex->peer);

 kex->flags &= ~0x0001;
 free(kex->name);
 kex->name = 
            ((void *)0)
                ;
 return 0;
}

int
kex_send_kexinit(struct ssh *ssh)
{
 u_char *cookie;
 struct kex *kex = ssh->kex;
 int r;

 if (kex == 
           ((void *)0)
               ) {
  sshlog("kex.c", __func__, 558, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "no kex");
  return -1;
 }
 if (kex->flags & 0x0001)
  return 0;
 kex->done = 0;


 if (sshbuf_len(kex->my) < 16) {
  sshlog("kex.c", __func__, 567, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "bad kex length: %zu < %d", sshbuf_len(kex->my), 16)
                                          ;
  return -4;
 }
 if ((cookie = sshbuf_mutable_ptr(kex->my)) == 
                                              ((void *)0)
                                                  ) {
  sshlog("kex.c", __func__, 572, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "buffer error");
  return -1;
 }
 arc4random_buf(cookie, 16);

 if ((r = sshpkt_start(ssh, 20)) != 0 ||
     (r = sshpkt_putb(ssh, kex->my)) != 0 ||
     (r = sshpkt_send(ssh)) != 0) {
  sshlog("kex.c", __func__, 580, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "compose reply");
  return r;
 }
 sshlog("kex.c", __func__, 583, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "SSH2_MSG_KEXINIT sent");
 kex->flags |= 0x0001;
 return 0;
}


int
kex_input_kexinit(int type, u_int32_t seq, struct ssh *ssh)
{
 struct kex *kex = ssh->kex;
 const u_char *ptr;
 u_int i;
 size_t dlen;
 int r;

 sshlog("kex.c", __func__, 598, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "SSH2_MSG_KEXINIT received");
 if (kex == 
           ((void *)0)
               ) {
  sshlog("kex.c", __func__, 600, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "no kex");
  return -1;
 }
 ssh_dispatch_set(ssh, 20, 
                                        ((void *)0)
                                            );
 ptr = sshpkt_ptr(ssh, &dlen);
 if ((r = sshbuf_put(kex->peer, ptr, dlen)) != 0)
  return r;


 for (i = 0; i < 16; i++) {
  if ((r = sshpkt_get_u8(ssh, 
                             ((void *)0)
                                 )) != 0) {
   sshlog("kex.c", __func__, 611, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "discard cookie");
   return r;
  }
 }
 for (i = 0; i < PROPOSAL_MAX; i++) {
  if ((r = sshpkt_get_string(ssh, 
                                 ((void *)0)
                                     , 
                                       ((void *)0)
                                           )) != 0) {
   sshlog("kex.c", __func__, 617, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "discard proposal");
   return r;
  }
 }
 if ((r = sshpkt_get_u8(ssh, 
                            ((void *)0)
                                )) != 0 ||
     (r = sshpkt_get_u32(ssh, 
                             ((void *)0)
                                 )) != 0 ||
     (r = sshpkt_get_end(ssh)) != 0)
   return r;

 if (!(kex->flags & 0x0001))
  if ((r = kex_send_kexinit(ssh)) != 0)
   return r;
 if ((r = kex_choose_conf(ssh)) != 0)
  return r;

 if (kex->kex_type < KEX_MAX && kex->kex[kex->kex_type] != 
                                                          ((void *)0)
                                                              )
  return (kex->kex[kex->kex_type])(ssh);

 sshlog("kex.c", __func__, 645, 1, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "unknown kex type %u", kex->kex_type);
 return -1;
}

struct kex *
kex_new(void)
{
 struct kex *kex;

 if ((kex = calloc(1, sizeof(*kex))) == 
                                       ((void *)0) 
                                            ||
     (kex->peer = sshbuf_new()) == 
                                  ((void *)0) 
                                       ||
     (kex->my = sshbuf_new()) == 
                                ((void *)0) 
                                     ||
     (kex->client_version = sshbuf_new()) == 
                                            ((void *)0) 
                                                 ||
     (kex->server_version = sshbuf_new()) == 
                                            ((void *)0) 
                                                 ||
     (kex->session_id = sshbuf_new()) == 
                                        ((void *)0)
                                            ) {
  kex_free(kex);
  return 
        ((void *)0)
            ;
 }
 return kex;
}

void
kex_free_newkeys(struct newkeys *newkeys)
{
 if (newkeys == 
               ((void *)0)
                   )
  return;
 if (newkeys->enc.key) {
  explicit_bzero(newkeys->enc.key, newkeys->enc.key_len);
  free(newkeys->enc.key);
  newkeys->enc.key = 
                    ((void *)0)
                        ;
 }
 if (newkeys->enc.iv) {
  explicit_bzero(newkeys->enc.iv, newkeys->enc.iv_len);
  free(newkeys->enc.iv);
  newkeys->enc.iv = 
                   ((void *)0)
                       ;
 }
 free(newkeys->enc.name);
 explicit_bzero(&newkeys->enc, sizeof(newkeys->enc));
 free(newkeys->comp.name);
 explicit_bzero(&newkeys->comp, sizeof(newkeys->comp));
 mac_clear(&newkeys->mac);
 if (newkeys->mac.key) {
  explicit_bzero(newkeys->mac.key, newkeys->mac.key_len);
  free(newkeys->mac.key);
  newkeys->mac.key = 
                    ((void *)0)
                        ;
 }
 free(newkeys->mac.name);
 explicit_bzero(&newkeys->mac, sizeof(newkeys->mac));
 freezero(newkeys, sizeof(*newkeys));
}

void
kex_free(struct kex *kex)
{
 u_int mode;

 if (kex == 
           ((void *)0)
               )
  return;


 DH_free(kex->dh);

 EC_KEY_free(kex->ec_client_key);


 for (mode = 0; mode < MODE_MAX; mode++) {
  kex_free_newkeys(kex->newkeys[mode]);
  kex->newkeys[mode] = 
                      ((void *)0)
                          ;
 }
 sshbuf_free(kex->peer);
 sshbuf_free(kex->my);
 sshbuf_free(kex->client_version);
 sshbuf_free(kex->server_version);
 sshbuf_free(kex->client_pub);
 sshbuf_free(kex->session_id);
 sshbuf_free(kex->initial_sig);
 sshkey_free(kex->initial_hostkey);
 free(kex->failed_choice);
 free(kex->hostkey_alg);
 free(kex->name);
 free(kex);
}

int
kex_ready(struct ssh *ssh, char *proposal[PROPOSAL_MAX])
{
 int r;

 if ((r = kex_prop2buf(ssh->kex->my, proposal)) != 0)
  return r;
 ssh->kex->flags = 0x0002;
 kex_reset_dispatch(ssh);
 ssh_dispatch_set(ssh, 20, &kex_input_kexinit);
 return 0;
}

int
kex_setup(struct ssh *ssh, char *proposal[PROPOSAL_MAX])
{
 int r;

 if ((r = kex_ready(ssh, proposal)) != 0)
  return r;
 if ((r = kex_send_kexinit(ssh)) != 0) {
  kex_free(ssh->kex);
  ssh->kex = 
            ((void *)0)
                ;
  return r;
 }
 return 0;
}





int
kex_start_rekex(struct ssh *ssh)
{
 if (ssh->kex == 
                ((void *)0)
                    ) {
  sshlog("kex.c", __func__, 764, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "no kex");
  return -1;
 }
 if (ssh->kex->done == 0) {
  sshlog("kex.c", __func__, 768, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "requested twice");
  return -1;
 }
 ssh->kex->done = 0;
 return kex_send_kexinit(ssh);
}

static int
choose_enc(struct sshenc *enc, char *client, char *server)
{
 char *name = match_list(client, server, 
                                        ((void *)0)
                                            );

 if (name == 
            ((void *)0)
                )
  return -31;
 if ((enc->cipher = cipher_by_name(name)) == 
                                            ((void *)0)
                                                ) {
  sshlog("kex.c", __func__, 783, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unsupported cipher %s", name);
  free(name);
  return -1;
 }
 enc->name = name;
 enc->enabled = 0;
 enc->iv = 
          ((void *)0)
              ;
 enc->iv_len = cipher_ivlen(enc->cipher);
 enc->key = 
           ((void *)0)
               ;
 enc->key_len = cipher_keylen(enc->cipher);
 enc->block_size = cipher_blocksize(enc->cipher);
 return 0;
}

static int
choose_mac(struct ssh *ssh, struct sshmac *mac, char *client, char *server)
{
 char *name = match_list(client, server, 
                                        ((void *)0)
                                            );

 if (name == 
            ((void *)0)
                )
  return -32;
 if (mac_setup(mac, name) < 0) {
  sshlog("kex.c", __func__, 805, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unsupported MAC %s", name);
  free(name);
  return -1;
 }
 mac->name = name;
 mac->key = 
           ((void *)0)
               ;
 mac->enabled = 0;
 return 0;
}

static int
choose_comp(struct sshcomp *comp, char *client, char *server)
{
 char *name = match_list(client, server, 
                                        ((void *)0)
                                            );

 if (name == 
            ((void *)0)
                )
  return -33;

 if (strcmp(name, "zlib@openssh.com") == 0) {
  comp->type = 2;
 } else if (strcmp(name, "zlib") == 0) {
  comp->type = 1;
 } else

 if (strcmp(name, "none") == 0) {
  comp->type = 0;
 } else {
  sshlog("kex.c", __func__, 832, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unsupported compression scheme %s", name);
  free(name);
  return -1;
 }
 comp->name = name;
 return 0;
}

static int
choose_kex(struct kex *k, char *client, char *server)
{
 const struct kexalg *kexalg;

 k->name = match_list(client, server, 
                                     ((void *)0)
                                         );

 sshlog("kex.c", __func__, 847, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "kex: algorithm: %s", k->name ? k->name : "(no match)");
 if (k->name == 
               ((void *)0)
                   )
  return -34;
 if ((kexalg = kex_alg_by_name(k->name)) == 
                                           ((void *)0)
                                               ) {
  sshlog("kex.c", __func__, 851, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unsupported KEX method %s", k->name);
  return -1;
 }
 k->kex_type = kexalg->type;
 k->hash_alg = kexalg->hash_alg;
 k->ec_nid = kexalg->ec_nid;
 return 0;
}

static int
choose_hostkeyalg(struct kex *k, char *client, char *server)
{
 free(k->hostkey_alg);
 k->hostkey_alg = match_list(client, server, 
                                            ((void *)0)
                                                );

 sshlog("kex.c", __func__, 866, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "kex: host key algorithm: %s", k->hostkey_alg ? k->hostkey_alg : "(no match)")
                                                    ;
 if (k->hostkey_alg == 
                      ((void *)0)
                          )
  return -35;
 k->hostkey_type = sshkey_type_from_name(k->hostkey_alg);
 if (k->hostkey_type == KEY_UNSPEC) {
  sshlog("kex.c", __func__, 872, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unsupported hostkey algorithm %s", k->hostkey_alg);
  return -1;
 }
 k->hostkey_nid = sshkey_ecdsa_nid_from_name(k->hostkey_alg);
 return 0;
}

static int
proposals_match(char *my[PROPOSAL_MAX], char *peer[PROPOSAL_MAX])
{
 static int check[] = {
  PROPOSAL_KEX_ALGS, PROPOSAL_SERVER_HOST_KEY_ALGS, -1
 };
 int *idx;
 char *p;

 for (idx = &check[0]; *idx != -1; idx++) {
  if ((p = strchr(my[*idx], ',')) != 
                                    ((void *)0)
                                        )
   *p = '\0';
  if ((p = strchr(peer[*idx], ',')) != 
                                      ((void *)0)
                                          )
   *p = '\0';
  if (strcmp(my[*idx], peer[*idx]) != 0) {
   sshlog("kex.c", __func__, 894, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "proposal mismatch: my %s peer %s", my[*idx], peer[*idx])
                            ;
   return (0);
  }
 }
 sshlog("kex.c", __func__, 899, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "proposals match");
 return (1);
}


static int
has_any_alg(const char *proposal, const char *algs)
{
 char *cp;

 if ((cp = match_list(proposal, algs, 
                                     ((void *)0)
                                         )) == 
                                               ((void *)0)
                                                   )
  return 0;
 free(cp);
 return 1;
}

static int
kex_choose_conf(struct ssh *ssh)
{
 struct kex *kex = ssh->kex;
 struct newkeys *newkeys;
 char **my = 
            ((void *)0)
                , **peer = 
                           ((void *)0)
                               ;
 char **cprop, **sprop;
 int nenc, nmac, ncomp;
 u_int mode, ctos, need, dh_need, authlen;
 int r, first_kex_follows;

 sshlog("kex.c", __func__, 926, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "local %s KEXINIT proposal", kex->server ? "server" : "client");
 if ((r = kex_buf2prop(kex->my, 
                               ((void *)0)
                                   , &my)) != 0)
  goto out;
 sshlog("kex.c", __func__, 929, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "peer %s KEXINIT proposal", kex->server ? "client" : "server");
 if ((r = kex_buf2prop(kex->peer, &first_kex_follows, &peer)) != 0)
  goto out;

 if (kex->server) {
  cprop=peer;
  sprop=my;
 } else {
  cprop=my;
  sprop=peer;
 }


 if (kex->server && (kex->flags & 0x0002)) {
  char *ext;

  ext = match_list("ext-info-c", peer[PROPOSAL_KEX_ALGS], 
                                                         ((void *)0)
                                                             );
  kex->ext_info_c = (ext != 
                           ((void *)0)
                               );
  free(ext);
 }


 if (kex->server && (kex->flags & 0x0002)) {
  if (has_any_alg(peer[PROPOSAL_SERVER_HOST_KEY_ALGS],
      "rsa-sha2-256,rsa-sha2-256-cert-v01@openssh.com"))
   kex->flags |= 0x0008;
  if (has_any_alg(peer[PROPOSAL_SERVER_HOST_KEY_ALGS],
      "rsa-sha2-512,rsa-sha2-512-cert-v01@openssh.com"))
   kex->flags |= 0x0010;
 }


 if ((r = choose_kex(kex, cprop[PROPOSAL_KEX_ALGS],
     sprop[PROPOSAL_KEX_ALGS])) != 0) {
  kex->failed_choice = peer[PROPOSAL_KEX_ALGS];
  peer[PROPOSAL_KEX_ALGS] = 
                           ((void *)0)
                               ;
  goto out;
 }
 if ((r = choose_hostkeyalg(kex, cprop[PROPOSAL_SERVER_HOST_KEY_ALGS],
     sprop[PROPOSAL_SERVER_HOST_KEY_ALGS])) != 0) {
  kex->failed_choice = peer[PROPOSAL_SERVER_HOST_KEY_ALGS];
  peer[PROPOSAL_SERVER_HOST_KEY_ALGS] = 
                                       ((void *)0)
                                           ;
  goto out;
 }
 for (mode = 0; mode < MODE_MAX; mode++) {
  if ((newkeys = calloc(1, sizeof(*newkeys))) == 
                                                ((void *)0)
                                                    ) {
   r = -2;
   goto out;
  }
  kex->newkeys[mode] = newkeys;
  ctos = (!kex->server && mode == MODE_OUT) ||
      (kex->server && mode == MODE_IN);
  nenc = ctos ? PROPOSAL_ENC_ALGS_CTOS : PROPOSAL_ENC_ALGS_STOC;
  nmac = ctos ? PROPOSAL_MAC_ALGS_CTOS : PROPOSAL_MAC_ALGS_STOC;
  ncomp = ctos ? PROPOSAL_COMP_ALGS_CTOS : PROPOSAL_COMP_ALGS_STOC;
  if ((r = choose_enc(&newkeys->enc, cprop[nenc],
      sprop[nenc])) != 0) {
   kex->failed_choice = peer[nenc];
   peer[nenc] = 
               ((void *)0)
                   ;
   goto out;
  }
  authlen = cipher_authlen(newkeys->enc.cipher);

  if (authlen == 0 &&
      (r = choose_mac(ssh, &newkeys->mac, cprop[nmac],
      sprop[nmac])) != 0) {
   kex->failed_choice = peer[nmac];
   peer[nmac] = 
               ((void *)0)
                   ;
   goto out;
  }
  if ((r = choose_comp(&newkeys->comp, cprop[ncomp],
      sprop[ncomp])) != 0) {
   kex->failed_choice = peer[ncomp];
   peer[ncomp] = 
                ((void *)0)
                    ;
   goto out;
  }
  sshlog("kex.c", __func__, 1005, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "kex: %s cipher: %s MAC: %s compression: %s", ctos ? "client->server" : "server->client", newkeys->enc.name, authlen == 0 ? newkeys->mac.name : "<implicit>", newkeys->comp.name)



                         ;
 }
 need = dh_need = 0;
 for (mode = 0; mode < MODE_MAX; mode++) {
  newkeys = kex->newkeys[mode];
  need = (((need) > (newkeys->enc.key_len)) ? (need) : (newkeys->enc.key_len));
  need = (((need) > (newkeys->enc.block_size)) ? (need) : (newkeys->enc.block_size));
  need = (((need) > (newkeys->enc.iv_len)) ? (need) : (newkeys->enc.iv_len));
  need = (((need) > (newkeys->mac.key_len)) ? (need) : (newkeys->mac.key_len));
  dh_need = (((dh_need) > (cipher_seclen(newkeys->enc.cipher))) ? (dh_need) : (cipher_seclen(newkeys->enc.cipher)));
  dh_need = (((dh_need) > (newkeys->enc.block_size)) ? (dh_need) : (newkeys->enc.block_size));
  dh_need = (((dh_need) > (newkeys->enc.iv_len)) ? (dh_need) : (newkeys->enc.iv_len));
  dh_need = (((dh_need) > (newkeys->mac.key_len)) ? (dh_need) : (newkeys->mac.key_len));
 }

 kex->we_need = need;
 kex->dh_need = dh_need;


 if (first_kex_follows && !proposals_match(my, peer))
  ssh->dispatch_skip_packets = 1;
 r = 0;
 out:
 kex_prop_free(my);
 kex_prop_free(peer);
 return r;
}

static int
derive_key(struct ssh *ssh, int id, u_int need, u_char *hash, u_int hashlen,
    const struct sshbuf *shared_secret, u_char **keyp)
{
 struct kex *kex = ssh->kex;
 struct ssh_digest_ctx *hashctx = 
                                 ((void *)0)
                                     ;
 char c = id;
 u_int have;
 size_t mdsz;
 u_char *digest;
 int r;

 if ((mdsz = ssh_digest_bytes(kex->hash_alg)) == 0)
  return -10;
 if ((digest = calloc(1, ((((need)+((mdsz)-1))/(mdsz))*(mdsz)))) == 
                                                 ((void *)0)
                                                     ) {
  r = -2;
  goto out;
 }


 if ((hashctx = ssh_digest_start(kex->hash_alg)) == 
                                                   ((void *)0) 
                                                        ||
     ssh_digest_update_buffer(hashctx, shared_secret) != 0 ||
     ssh_digest_update(hashctx, hash, hashlen) != 0 ||
     ssh_digest_update(hashctx, &c, 1) != 0 ||
     ssh_digest_update_buffer(hashctx, kex->session_id) != 0 ||
     ssh_digest_final(hashctx, digest, mdsz) != 0) {
  r = -22;
  sshlog("kex.c", __func__, 1064, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "KEX hash failed");
  goto out;
 }
 ssh_digest_free(hashctx);
 hashctx = 
          ((void *)0)
              ;






 for (have = mdsz; need > have; have += mdsz) {
  if ((hashctx = ssh_digest_start(kex->hash_alg)) == 
                                                    ((void *)0) 
                                                         ||
      ssh_digest_update_buffer(hashctx, shared_secret) != 0 ||
      ssh_digest_update(hashctx, hash, hashlen) != 0 ||
      ssh_digest_update(hashctx, digest, have) != 0 ||
      ssh_digest_final(hashctx, digest + have, mdsz) != 0) {
   sshlog("kex.c", __func__, 1081, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "KDF failed");
   r = -22;
   goto out;
  }
  ssh_digest_free(hashctx);
  hashctx = 
           ((void *)0)
               ;
 }




 *keyp = digest;
 digest = 
         ((void *)0)
             ;
 r = 0;
 out:
 free(digest);
 ssh_digest_free(hashctx);
 return r;
}


int
kex_derive_keys(struct ssh *ssh, u_char *hash, u_int hashlen,
    const struct sshbuf *shared_secret)
{
 struct kex *kex = ssh->kex;
 u_char *keys[6];
 u_int i, j, mode, ctos;
 int r;


 if ((kex->flags & 0x0002) != 0) {
  if (sshbuf_len(kex->session_id) != 0) {
   sshlog("kex.c", __func__, 1114, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "already have session ID at kex");
   return -1;
  }
  if ((r = sshbuf_put(kex->session_id, hash, hashlen)) != 0)
   return r;
 } else if (sshbuf_len(kex->session_id) == 0) {
  sshlog("kex.c", __func__, 1120, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "no session ID in rekex");
  return -1;
 }
 for (i = 0; i < 6; i++) {
  if ((r = derive_key(ssh, 'A'+i, kex->we_need, hash, hashlen,
      shared_secret, &keys[i])) != 0) {
   for (j = 0; j < i; j++)
    free(keys[j]);
   return r;
  }
 }
 for (mode = 0; mode < MODE_MAX; mode++) {
  ctos = (!kex->server && mode == MODE_OUT) ||
      (kex->server && mode == MODE_IN);
  kex->newkeys[mode]->enc.iv = keys[ctos ? 0 : 1];
  kex->newkeys[mode]->enc.key = keys[ctos ? 2 : 3];
  kex->newkeys[mode]->mac.key = keys[ctos ? 4 : 5];
 }
 return 0;
}

int
kex_load_hostkey(struct ssh *ssh, struct sshkey **prvp, struct sshkey **pubp)
{
 struct kex *kex = ssh->kex;

 *pubp = 
        ((void *)0)
            ;
 *prvp = 
        ((void *)0)
            ;
 if (kex->load_host_public_key == 
                                 ((void *)0) 
                                      ||
     kex->load_host_private_key == 
                                  ((void *)0)
                                      ) {
  sshlog("kex.c", __func__, 1150, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "missing hostkey loader");
  return -10;
 }
 *pubp = kex->load_host_public_key(kex->hostkey_type,
     kex->hostkey_nid, ssh);
 *prvp = kex->load_host_private_key(kex->hostkey_type,
     kex->hostkey_nid, ssh);
 if (*pubp == 
             ((void *)0)
                 )
  return -36;
 return 0;
}

int
kex_verify_host_key(struct ssh *ssh, struct sshkey *server_host_key)
{
 struct kex *kex = ssh->kex;

 if (kex->verify_host_key == 
                            ((void *)0)
                                ) {
  sshlog("kex.c", __func__, 1168, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "missing hostkey verifier");
  return -10;
 }
 if (server_host_key->type != kex->hostkey_type ||
     (kex->hostkey_type == KEY_ECDSA &&
     server_host_key->ecdsa_nid != kex->hostkey_nid))
  return -13;
 if (kex->verify_host_key(server_host_key, ssh) == -1)
  return -21;
 return 0;
}
static void
send_error(struct ssh *ssh, char *msg)
{
 char *crnl = "\r\n";

 if (!ssh->kex->server)
  return;

 if (atomicio((ssize_t (*)(int, void *, size_t))write, ssh_packet_get_connection_out(ssh),
     msg, strlen(msg)) != strlen(msg) ||
     atomicio((ssize_t (*)(int, void *, size_t))write, ssh_packet_get_connection_out(ssh),
     crnl, strlen(crnl)) != strlen(crnl))
  sshlog("kex.c", __func__, 1205, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "write: %.100s", strerror(
 (*__errno_location ())
 ));
}






int
kex_exchange_identification(struct ssh *ssh, int timeout_ms,
    const char *version_addendum)
{
 int remote_major, remote_minor, mismatch, oerrno = 0;
 size_t len, i, n;
 int r, expect_nl;
 u_char c;
 struct sshbuf *our_version = ssh->kex->server ?
     ssh->kex->server_version : ssh->kex->client_version;
 struct sshbuf *peer_version = ssh->kex->server ?
     ssh->kex->client_version : ssh->kex->server_version;
 char *our_version_string = 
                           ((void *)0)
                               , *peer_version_string = 
                                                        ((void *)0)
                                                            ;
 char *cp, *remote_version = 
                            ((void *)0)
                                ;


 sshbuf_reset(our_version);
 if (version_addendum != 
                        ((void *)0) 
                             && *version_addendum == '\0')
  version_addendum = 
                    ((void *)0)
                        ;
 if ((r = sshbuf_putf(our_version, "SSH-%d.%d-%.100s%s%s\r\n",
     2, 0, "OpenSSH_9.1",
     version_addendum == 
                        ((void *)0) 
                             ? "" : " ",
     version_addendum == 
                        ((void *)0) 
                             ? "" : version_addendum)) != 0) {
  oerrno = 
          (*__errno_location ())
               ;
  sshlog("kex.c", __func__, 1237, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshbuf_putf");
  goto out;
 }

 if (atomicio((ssize_t (*)(int, void *, size_t))write, ssh_packet_get_connection_out(ssh),
     sshbuf_mutable_ptr(our_version),
     sshbuf_len(our_version)) != sshbuf_len(our_version)) {
  oerrno = 
          (*__errno_location ())
               ;
  sshlog("kex.c", __func__, 1245, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "write: %.100s", strerror(
 (*__errno_location ())
 ));
  r = -24;
  goto out;
 }
 if ((r = sshbuf_consume_end(our_version, 2)) != 0) {
  oerrno = 
          (*__errno_location ())
               ;
  sshlog("kex.c", __func__, 1251, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshbuf_consume_end");
  goto out;
 }
 our_version_string = sshbuf_dup_string(our_version);
 if (our_version_string == 
                          ((void *)0)
                              ) {
  sshlog("kex.c", __func__, 1256, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshbuf_dup_string failed");
  r = -2;
  goto out;
 }
 sshlog("kex.c", __func__, 1260, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Local version string %.100s", our_version_string);


 for (n = 0; ; n++) {
  if (n >= 1024) {
   send_error(ssh, "No SSH identification string "
       "received.");
   sshlog("kex.c", __func__, 1267, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "No SSH version received in first %u lines " "from server", 1024)
                                               ;
   r = -4;
   goto out;
  }
  sshbuf_reset(peer_version);
  expect_nl = 0;
  for (i = 0; ; i++) {
   if (timeout_ms > 0) {
    r = waitrfd(ssh_packet_get_connection_in(ssh),
        &timeout_ms);
    if (r == -1 && 
                  (*__errno_location ()) 
                        == 
                           110
                                    ) {
     send_error(ssh, "Timed out waiting "
         "for SSH identification string.");
     sshlog("kex.c", __func__, 1281, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "Connection timed out during " "banner exchange")
                           ;
     r = -53;
     goto out;
    } else if (r == -1) {
     oerrno = 
             (*__errno_location ())
                  ;
     sshlog("kex.c", __func__, 1287, 1, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "%s", strerror(
    (*__errno_location ())
    ));
     r = -24;
     goto out;
    }
   }

   len = atomicio(read, ssh_packet_get_connection_in(ssh),
       &c, 1);
   if (len != 1 && 
                  (*__errno_location ()) 
                        == 
                           32
                                ) {
    sshlog("kex.c", __func__, 1296, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Connection closed by remote host");
    r = -52;
    goto out;
   } else if (len != 1) {
    oerrno = 
            (*__errno_location ())
                 ;
    sshlog("kex.c", __func__, 1301, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "read: %.100s", strerror(
   (*__errno_location ())
   ));
    r = -24;
    goto out;
   }
   if (c == '\r') {
    expect_nl = 1;
    continue;
   }
   if (c == '\n')
    break;
   if (c == '\0' || expect_nl) {
    sshlog("kex.c", __func__, 1312, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "banner line contains invalid " "characters")
                     ;
    goto invalid;
   }
   if ((r = sshbuf_put_u8(peer_version, c)) != 0) {
    oerrno = 
            (*__errno_location ())
                 ;
    sshlog("kex.c", __func__, 1318, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshbuf_put");
    goto out;
   }
   if (sshbuf_len(peer_version) > 8192) {
    sshlog("kex.c", __func__, 1322, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "banner line too long");
    goto invalid;
   }
  }

  if (sshbuf_len(peer_version) > 4 &&
      memcmp(sshbuf_ptr(peer_version), "SSH-", 4) == 0)
   break;

  if ((cp = sshbuf_dup_string(peer_version)) == 
                                               ((void *)0)
                                                   ) {
   sshlog("kex.c", __func__, 1332, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "sshbuf_dup_string failed");
   r = -2;
   goto out;
  }

  if (ssh->kex->server) {
   sshlog("kex.c", __func__, 1338, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "client sent invalid protocol identifier " "\"%.256s\"", cp)
                        ;
   free(cp);
   goto invalid;
  }
  sshlog("kex.c", __func__, 1343, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "banner line %zu: %s", n, cp);
  free(cp);
 }
 peer_version_string = sshbuf_dup_string(peer_version);
 if (peer_version_string == 
                           ((void *)0)
                               )
  sshlog("kex.c", __func__, 1348, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshbuf_dup_string failed");

 if ((remote_version = calloc(1, sshbuf_len(peer_version))) == 
                                                              ((void *)0)
                                                                  ) {
  sshlog("kex.c", __func__, 1351, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "calloc failed");
  r = -2;
  goto out;
 }





 if (sscanf(peer_version_string, "SSH-%d.%d-%[^\n]\n",
     &remote_major, &remote_minor, remote_version) != 3) {
  sshlog("kex.c", __func__, 1362, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Bad remote protocol version identification: '%.100s'", peer_version_string)
                          ;
 invalid:
  send_error(ssh, "Invalid SSH identification string.");
  r = -4;
  goto out;
 }
 sshlog("kex.c", __func__, 1369, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Remote protocol version %d.%d, remote software version %.100s", remote_major, remote_minor, remote_version)
                                                ;
 compat_banner(ssh, remote_version);

 mismatch = 0;
 switch (remote_major) {
 case 2:
  break;
 case 1:
  if (remote_minor != 99)
   mismatch = 1;
  break;
 default:
  mismatch = 1;
  break;
 }
 if (mismatch) {
  sshlog("kex.c", __func__, 1386, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Protocol major versions differ: %d vs. %d", 2, remote_major)
                                     ;
  send_error(ssh, "Protocol major versions differ.");
  r = -38;
  goto out;
 }

 if (ssh->kex->server && (ssh->compat & 0x00400000) != 0) {
  sshlog("kex.c", __func__, 1394, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "probed from %s port %d with %s.  Don't panic.", ssh_remote_ipaddr(ssh), ssh_remote_port(ssh), peer_version_string)

                          ;
  r = -52;
  goto out;
 }
 if (ssh->kex->server && (ssh->compat & 0x00000800) != 0) {
  sshlog("kex.c", __func__, 1401, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "scanned from %s port %d with %s.  Don't panic.", ssh_remote_ipaddr(ssh), ssh_remote_port(ssh), peer_version_string)

                          ;
  r = -52;
  goto out;
 }
 if ((ssh->compat & 0x00002000) != 0) {
  sshlog("kex.c", __func__, 1408, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Remote version \"%.100s\" uses unsafe RSA signature " "scheme; disabling use of RSA keys", remote_version)
                                                          ;
 }

 r = 0;
 out:
 free(our_version_string);
 free(peer_version_string);
 free(remote_version);
 if (r == -24)
  
 (*__errno_location ()) 
       = oerrno;
 return r;
}
