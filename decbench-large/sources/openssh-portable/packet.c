











































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
char *get_peer_ipaddr(int);
int get_peer_port(int);
char *get_local_ipaddr(int);
char *get_local_name(int);
int get_local_port(int);



void ipv64_normalise_mapped(struct sockaddr_storage *, socklen_t *);
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
struct packet_state {
 u_int32_t seqnr;
 u_int32_t packets;
 u_int64_t blocks;
 u_int64_t bytes;
};

struct packet {
 struct { struct packet *tqe_next; struct packet **tqe_prev; } next;
 u_char type;
 struct sshbuf *payload;
};

struct session_state {






 int connection_in;
 int connection_out;


 u_int remote_protocol_flags;


 struct sshcipher_ctx *receive_context;


 struct sshcipher_ctx *send_context;


 struct sshbuf *input;


 struct sshbuf *output;


 struct sshbuf *outgoing_packet;


 struct sshbuf *incoming_packet;


 struct sshbuf *compression_buffer;



 z_stream compression_in_stream;
 z_stream compression_out_stream;

 int compression_in_started;
 int compression_out_started;
 int compression_in_failures;
 int compression_out_failures;


 u_int max_packet_size;


 int initialized;


 int interactive_mode;


 int server_side;


 int after_authentication;

 int keep_alive_timeouts;


 int packet_timeout_ms;


 struct newkeys *newkeys[MODE_MAX];
 struct packet_state p_read, p_send;


 u_int64_t max_blocks_in, max_blocks_out, rekey_limit;


 u_int32_t rekey_interval;
 time_t rekey_time;


 u_char extra_pad;


 u_int packet_discard;
 size_t packet_discard_mac_already;
 struct sshmac *packet_discard_mac;


 u_int packlen;


 int rekeying;


 int mux;


 int set_interactive_called;


 int set_maxsize_called;


 int cipher_warning_done;


 ssh_packet_hook_fn *hook_in;
 void *hook_in_ctx;

 struct { struct packet *tqh_first; struct packet **tqh_last; } outgoing;
};

struct ssh *
ssh_alloc_session_state(void)
{
 struct ssh *ssh = 
                  ((void *)0)
                      ;
 struct session_state *state = 
                              ((void *)0)
                                  ;

 if ((ssh = calloc(1, sizeof(*ssh))) == 
                                       ((void *)0) 
                                            ||
     (state = calloc(1, sizeof(*state))) == 
                                           ((void *)0) 
                                                ||
     (ssh->kex = kex_new()) == 
                              ((void *)0) 
                                   ||
     (state->input = sshbuf_new()) == 
                                     ((void *)0) 
                                          ||
     (state->output = sshbuf_new()) == 
                                      ((void *)0) 
                                           ||
     (state->outgoing_packet = sshbuf_new()) == 
                                               ((void *)0) 
                                                    ||
     (state->incoming_packet = sshbuf_new()) == 
                                               ((void *)0)
                                                   )
  goto fail;
 do { (&state->outgoing)->tqh_first = 
((void *)0)
; (&state->outgoing)->tqh_last = &(&state->outgoing)->tqh_first; } while (0);
 do { (&ssh->private_keys)->tqh_first = 
((void *)0)
; (&ssh->private_keys)->tqh_last = &(&ssh->private_keys)->tqh_first; } while (0);
 do { (&ssh->public_keys)->tqh_first = 
((void *)0)
; (&ssh->public_keys)->tqh_last = &(&ssh->public_keys)->tqh_first; } while (0);
 state->connection_in = -1;
 state->connection_out = -1;
 state->max_packet_size = 32768;
 state->packet_timeout_ms = -1;
 state->p_send.packets = state->p_read.packets = 0;
 state->initialized = 1;




 state->rekeying = 1;
 ssh->state = state;
 return ssh;
 fail:
 if (ssh) {
  kex_free(ssh->kex);
  free(ssh);
 }
 if (state) {
  sshbuf_free(state->input);
  sshbuf_free(state->output);
  sshbuf_free(state->incoming_packet);
  sshbuf_free(state->outgoing_packet);
  free(state);
 }
 return 
       ((void *)0)
           ;
}

void
ssh_packet_set_input_hook(struct ssh *ssh, ssh_packet_hook_fn *hook, void *ctx)
{
 ssh->state->hook_in = hook;
 ssh->state->hook_in_ctx = ctx;
}


int
ssh_packet_is_rekeying(struct ssh *ssh)
{
 return ssh->state->rekeying ||
     (ssh->kex != 
                 ((void *)0) 
                      && ssh->kex->done == 0);
}




struct ssh *
ssh_packet_set_connection(struct ssh *ssh, int fd_in, int fd_out)
{
 struct session_state *state;
 const struct sshcipher *none = cipher_by_name("none");
 int r;

 if (none == 
            ((void *)0)
                ) {
  sshlog("packet.c", __func__, 300, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "cannot load cipher 'none'");
  return 
        ((void *)0)
            ;
 }
 if (ssh == 
           ((void *)0)
               )
  ssh = ssh_alloc_session_state();
 if (ssh == 
           ((void *)0)
               ) {
  sshlog("packet.c", __func__, 306, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "could not allocate state");
  return 
        ((void *)0)
            ;
 }
 state = ssh->state;
 state->connection_in = fd_in;
 state->connection_out = fd_out;
 if ((r = cipher_init(&state->send_context, none,
     (const u_char *)"", 0, 
                           ((void *)0)
                               , 0, 1)) != 0 ||
     (r = cipher_init(&state->receive_context, none,
     (const u_char *)"", 0, 
                           ((void *)0)
                               , 0, 0)) != 0) {
  sshlog("packet.c", __func__, 316, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "cipher_init failed");
  free(ssh);
  return 
        ((void *)0)
            ;
 }
 state->newkeys[MODE_IN] = state->newkeys[MODE_OUT] = 
                                                     ((void *)0)
                                                         ;




 (void)ssh_remote_ipaddr(ssh);
 return ssh;
}

void
ssh_packet_set_timeout(struct ssh *ssh, int timeout, int count)
{
 struct session_state *state = ssh->state;

 if (timeout <= 0 || count <= 0) {
  state->packet_timeout_ms = -1;
  return;
 }
 if ((0x7fffffff / 1000) / count < timeout)
  state->packet_timeout_ms = 0x7fffffff;
 else
  state->packet_timeout_ms = timeout * count * 1000;
}

void
ssh_packet_set_mux(struct ssh *ssh)
{
 ssh->state->mux = 1;
 ssh->state->rekeying = 0;
 kex_free(ssh->kex);
 ssh->kex = 
           ((void *)0)
               ;
}

int
ssh_packet_get_mux(struct ssh *ssh)
{
 return ssh->state->mux;
}

int
ssh_packet_set_log_preamble(struct ssh *ssh, const char *fmt, ...)
{
 va_list args;
 int r;

 free(ssh->log_preamble);
 if (fmt == 
           ((void *)0)
               )
  ssh->log_preamble = 
                     ((void *)0)
                         ;
 else {
  
 __builtin_va_start(
 args
 ,
 fmt
 )
                    ;
  r = vasprintf(&ssh->log_preamble, fmt, args);
  
 __builtin_va_end(
 args
 )
             ;
  if (r < 0 || ssh->log_preamble == 
                                   ((void *)0)
                                       )
   return -2;
 }
 return 0;
}

int
ssh_packet_stop_discard(struct ssh *ssh)
{
 struct session_state *state = ssh->state;
 int r;

 if (state->packet_discard_mac) {
  char buf[1024];
  size_t dlen = (256 * 1024);

  if (dlen > state->packet_discard_mac_already)
   dlen -= state->packet_discard_mac_already;
  memset(buf, 'a', sizeof(buf));
  while (sshbuf_len(state->incoming_packet) < dlen)
   if ((r = sshbuf_put(state->incoming_packet, buf,
       sizeof(buf))) != 0)
    return r;
  (void) mac_compute(state->packet_discard_mac,
      state->p_read.seqnr,
      sshbuf_ptr(state->incoming_packet), dlen,
      
     ((void *)0)
         , 0);
 }
 sshlog("packet.c", __func__, 400, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "Finished discarding for %.200s port %d", ssh_remote_ipaddr(ssh), ssh_remote_port(ssh))
                                                  ;
 return -30;
}

static int
ssh_packet_start_discard(struct ssh *ssh, struct sshenc *enc,
    struct sshmac *mac, size_t mac_already, u_int discard)
{
 struct session_state *state = ssh->state;
 int r;

 if (enc == 
           ((void *)0) 
                || !cipher_is_cbc(enc->cipher) || (mac && mac->etm)) {
  if ((r = sshpkt_disconnect(ssh, "Packet corrupt")) != 0)
   return r;
  return -30;
 }




 if (mac && mac->enabled) {
  state->packet_discard_mac = mac;
  state->packet_discard_mac_already = mac_already;
 }
 if (sshbuf_len(state->input) >= discard)
  return ssh_packet_stop_discard(ssh);
 state->packet_discard = discard - sshbuf_len(state->input);
 return 0;
}



int
ssh_packet_connection_is_on_socket(struct ssh *ssh)
{
 struct session_state *state;
 struct sockaddr_storage from, to;
 socklen_t fromlen, tolen;

 if (ssh == 
           ((void *)0) 
                || ssh->state == 
                                 ((void *)0)
                                     )
  return 0;

 state = ssh->state;
 if (state->connection_in == -1 || state->connection_out == -1)
  return 0;

 if (state->connection_in == state->connection_out)
  return 1;
 fromlen = sizeof(from);
 memset(&from, 0, sizeof(from));
 if (getpeername(state->connection_in, (struct sockaddr *)&from,
     &fromlen) == -1)
  return 0;
 tolen = sizeof(to);
 memset(&to, 0, sizeof(to));
 if (getpeername(state->connection_out, (struct sockaddr *)&to,
     &tolen) == -1)
  return 0;
 if (fromlen != tolen || memcmp(&from, &to, fromlen) != 0)
  return 0;
 if (from.ss_family != 
                      2 
                              && from.ss_family != 
                                                   10
                                                           )
  return 0;
 return 1;
}

void
ssh_packet_get_bytes(struct ssh *ssh, u_int64_t *ibytes, u_int64_t *obytes)
{
 if (ibytes)
  *ibytes = ssh->state->p_read.bytes;
 if (obytes)
  *obytes = ssh->state->p_send.bytes;
}

int
ssh_packet_connection_af(struct ssh *ssh)
{
 return get_sock_af(ssh->state->connection_out);
}



void
ssh_packet_set_nonblocking(struct ssh *ssh)
{

 set_nonblock(ssh->state->connection_in);

 if (ssh->state->connection_out != ssh->state->connection_in)
  set_nonblock(ssh->state->connection_out);
}



int
ssh_packet_get_connection_in(struct ssh *ssh)
{
 return ssh->state->connection_in;
}



int
ssh_packet_get_connection_out(struct ssh *ssh)
{
 return ssh->state->connection_out;
}






const char *
ssh_remote_ipaddr(struct ssh *ssh)
{
 int sock;


 if (ssh->remote_ipaddr == 
                          ((void *)0)
                              ) {
  if (ssh_packet_connection_is_on_socket(ssh)) {
   sock = ssh->state->connection_in;
   ssh->remote_ipaddr = get_peer_ipaddr(sock);
   ssh->remote_port = get_peer_port(sock);
   ssh->local_ipaddr = get_local_ipaddr(sock);
   ssh->local_port = get_local_port(sock);
  } else {
   ssh->remote_ipaddr = xstrdup("UNKNOWN");
   ssh->remote_port = 65535;
   ssh->local_ipaddr = xstrdup("UNKNOWN");
   ssh->local_port = 65535;
  }
 }
 return ssh->remote_ipaddr;
}



int
ssh_remote_port(struct ssh *ssh)
{
 (void)ssh_remote_ipaddr(ssh);
 return ssh->remote_port;
}






const char *
ssh_local_ipaddr(struct ssh *ssh)
{
 (void)ssh_remote_ipaddr(ssh);
 return ssh->local_ipaddr;
}



int
ssh_local_port(struct ssh *ssh)
{
 (void)ssh_remote_ipaddr(ssh);
 return ssh->local_port;
}


const char *
ssh_packet_rdomain_in(struct ssh *ssh)
{
 if (ssh->rdomain_in != 
                       ((void *)0)
                           )
  return ssh->rdomain_in;
 if (!ssh_packet_connection_is_on_socket(ssh))
  return 
        ((void *)0)
            ;
 ssh->rdomain_in = get_rdomain(ssh->state->connection_in);
 return ssh->rdomain_in;
}



static void
ssh_packet_close_internal(struct ssh *ssh, int do_close)
{
 struct session_state *state = ssh->state;
 u_int mode;

 if (!state->initialized)
  return;
 state->initialized = 0;
 if (do_close) {
  if (state->connection_in == state->connection_out) {
   close(state->connection_out);
  } else {
   close(state->connection_in);
   close(state->connection_out);
  }
 }
 sshbuf_free(state->input);
 sshbuf_free(state->output);
 sshbuf_free(state->outgoing_packet);
 sshbuf_free(state->incoming_packet);
 for (mode = 0; mode < MODE_MAX; mode++) {
  kex_free_newkeys(state->newkeys[mode]);
  state->newkeys[mode] = 
                        ((void *)0)
                            ;
  ssh_clear_newkeys(ssh, mode);
 }


 if (do_close && state->compression_buffer) {
  sshbuf_free(state->compression_buffer);
  if (state->compression_out_started) {
   z_streamp stream = &state->compression_out_stream;
   sshlog("packet.c", __func__, 613, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "compress outgoing: " "raw data %llu, compressed %llu, factor %.2f", (unsigned long long)stream->total_in, (unsigned long long)stream->total_out, stream->total_in == 0 ? 0.0 : (double) stream->total_out / stream->total_in)




                                                  ;
   if (state->compression_out_failures == 0)
    deflateEnd(stream);
  }
  if (state->compression_in_started) {
   z_streamp stream = &state->compression_in_stream;
   sshlog("packet.c", __func__, 624, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "compress incoming: " "raw data %llu, compressed %llu, factor %.2f", (unsigned long long)stream->total_out, (unsigned long long)stream->total_in, stream->total_out == 0 ? 0.0 : (double) stream->total_in / stream->total_out)




                                                     ;
   if (state->compression_in_failures == 0)
    inflateEnd(stream);
  }
 }

 cipher_free(state->send_context);
 cipher_free(state->receive_context);
 state->send_context = state->receive_context = 
                                               ((void *)0)
                                                   ;
 if (do_close) {
  free(ssh->local_ipaddr);
  ssh->local_ipaddr = 
                     ((void *)0)
                         ;
  free(ssh->remote_ipaddr);
  ssh->remote_ipaddr = 
                      ((void *)0)
                          ;
  free(ssh->state);
  ssh->state = 
              ((void *)0)
                  ;
  kex_free(ssh->kex);
  ssh->kex = 
            ((void *)0)
                ;
 }
}

void
ssh_packet_close(struct ssh *ssh)
{
 ssh_packet_close_internal(ssh, 1);
}

void
ssh_packet_clear_keys(struct ssh *ssh)
{
 ssh_packet_close_internal(ssh, 0);
}



void
ssh_packet_set_protocol_flags(struct ssh *ssh, u_int protocol_flags)
{
 ssh->state->remote_protocol_flags = protocol_flags;
}



u_int
ssh_packet_get_protocol_flags(struct ssh *ssh)
{
 return ssh->state->remote_protocol_flags;
}






static int
ssh_packet_init_compression(struct ssh *ssh)
{
 if (!ssh->state->compression_buffer &&
     ((ssh->state->compression_buffer = sshbuf_new()) == 
                                                        ((void *)0)
                                                            ))
  return -2;
 return 0;
}


static int
start_compression_out(struct ssh *ssh, int level)
{
 if (level < 1 || level > 9)
  return -10;
 sshlog("packet.c", __func__, 698, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Enabling compression at level %d.", level);
 if (ssh->state->compression_out_started == 1)
  deflateEnd(&ssh->state->compression_out_stream);
 switch (
        deflateInit_((
        &ssh->state->compression_out_stream
        ), (
        level
        ), "1.2.11", (int)sizeof(z_stream))
                                                               ) {
 case 
     0
         :
  ssh->state->compression_out_started = 1;
  break;
 case 
     (-4)
                :
  return -2;
 default:
  return -1;
 }
 return 0;
}

static int
start_compression_in(struct ssh *ssh)
{
 if (ssh->state->compression_in_started == 1)
  inflateEnd(&ssh->state->compression_in_stream);
 switch (
        inflateInit_((
        &ssh->state->compression_in_stream
        ), "1.2.11", (int)sizeof(z_stream))
                                                       ) {
 case 
     0
         :
  ssh->state->compression_in_started = 1;
  break;
 case 
     (-4)
                :
  return -2;
 default:
  return -1;
 }
 return 0;
}


static int
compress_buffer(struct ssh *ssh, struct sshbuf *in, struct sshbuf *out)
{
 u_char buf[4096];
 int r, status;

 if (ssh->state->compression_out_started != 1)
  return -1;


 if (sshbuf_len(in) == 0)
  return 0;


 if ((ssh->state->compression_out_stream.next_in =
     sshbuf_mutable_ptr(in)) == 
                               ((void *)0)
                                   )
  return -1;
 ssh->state->compression_out_stream.avail_in = sshbuf_len(in);


 do {

  ssh->state->compression_out_stream.next_out = buf;
  ssh->state->compression_out_stream.avail_out = sizeof(buf);


  status = deflate(&ssh->state->compression_out_stream,
      
     1
                    );
  switch (status) {
  case 
      (-4)
                 :
   return -2;
  case 
      0
          :

   if ((r = sshbuf_put(out, buf, sizeof(buf) -
       ssh->state->compression_out_stream.avail_out)) != 0)
    return r;
   break;
  case 
      (-2)
                    :
  default:
   ssh->state->compression_out_failures++;
   return -4;
  }
 } while (ssh->state->compression_out_stream.avail_out == 0);
 return 0;
}

static int
uncompress_buffer(struct ssh *ssh, struct sshbuf *in, struct sshbuf *out)
{
 u_char buf[4096];
 int r, status;

 if (ssh->state->compression_in_started != 1)
  return -1;

 if ((ssh->state->compression_in_stream.next_in =
     sshbuf_mutable_ptr(in)) == 
                               ((void *)0)
                                   )
  return -1;
 ssh->state->compression_in_stream.avail_in = sshbuf_len(in);

 for (;;) {

  ssh->state->compression_in_stream.next_out = buf;
  ssh->state->compression_in_stream.avail_out = sizeof(buf);

  status = inflate(&ssh->state->compression_in_stream,
      
     2
                 );
  switch (status) {
  case 
      0
          :
   if ((r = sshbuf_put(out, buf, sizeof(buf) -
       ssh->state->compression_in_stream.avail_out)) != 0)
    return r;
   break;
  case 
      (-5)
                 :





   return 0;
  case 
      (-3)
                  :
   return -4;
  case 
      (-4)
                 :
   return -2;
  case 
      (-2)
                    :
  default:
   ssh->state->compression_in_failures++;
   return -1;
  }
 }

}
void
ssh_clear_newkeys(struct ssh *ssh, int mode)
{
 if (ssh->kex && ssh->kex->newkeys[mode]) {
  kex_free_newkeys(ssh->kex->newkeys[mode]);
  ssh->kex->newkeys[mode] = 
                           ((void *)0)
                               ;
 }
}

int
ssh_set_newkeys(struct ssh *ssh, int mode)
{
 struct session_state *state = ssh->state;
 struct sshenc *enc;
 struct sshmac *mac;
 struct sshcomp *comp;
 struct sshcipher_ctx **ccp;
 struct packet_state *ps;
 u_int64_t *max_blocks;
 const char *wmsg;
 int r, crypt_type;
 const char *dir = mode == MODE_OUT ? "out" : "in";

 sshlog("packet.c", __func__, 874, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "mode %d", mode);

 if (mode == MODE_OUT) {
  ccp = &state->send_context;
  crypt_type = 1;
  ps = &state->p_send;
  max_blocks = &state->max_blocks_out;
 } else {
  ccp = &state->receive_context;
  crypt_type = 0;
  ps = &state->p_read;
  max_blocks = &state->max_blocks_in;
 }
 if (state->newkeys[mode] != 
                            ((void *)0)
                                ) {
  sshlog("packet.c", __func__, 888, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "rekeying %s, input %llu bytes %llu blocks, " "output %llu bytes %llu blocks", dir, (unsigned long long)state->p_read.bytes, (unsigned long long)state->p_read.blocks, (unsigned long long)state->p_send.bytes, (unsigned long long)state->p_send.blocks)




                                               ;
  kex_free_newkeys(state->newkeys[mode]);
  state->newkeys[mode] = 
                        ((void *)0)
                            ;
 }

 ps->packets = ps->blocks = 0;

 if ((state->newkeys[mode] = ssh->kex->newkeys[mode]) == 
                                                        ((void *)0)
                                                            )
  return -1;
 ssh->kex->newkeys[mode] = 
                          ((void *)0)
                              ;
 enc = &state->newkeys[mode]->enc;
 mac = &state->newkeys[mode]->mac;
 comp = &state->newkeys[mode]->comp;
 if (cipher_authlen(enc->cipher) == 0) {
  if ((r = mac_init(mac)) != 0)
   return r;
 }
 mac->enabled = 1;
 ;
 cipher_free(*ccp);
 *ccp = 
       ((void *)0)
           ;
 if ((r = cipher_init(ccp, enc->cipher, enc->key, enc->key_len,
     enc->iv, enc->iv_len, crypt_type)) != 0)
  return r;
 if (!state->cipher_warning_done &&
     (wmsg = cipher_warning_message(*ccp)) != 
                                             ((void *)0)
                                                 ) {
  sshlog("packet.c", __func__, 919, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Warning: %s", wmsg);
  state->cipher_warning_done = 1;
 }




 if ((comp->type == 1 ||
     (comp->type == 2 &&
     state->after_authentication)) && comp->enabled == 0) {
  if ((r = ssh_packet_init_compression(ssh)) < 0)
   return r;
  if (mode == MODE_OUT) {
   if ((r = start_compression_out(ssh, 6)) != 0)
    return r;
  } else {
   if ((r = start_compression_in(ssh)) != 0)
    return r;
  }
  comp->enabled = 1;
 }





 if (enc->block_size >= 16)
  *max_blocks = (u_int64_t)1 << (enc->block_size*2);
 else
  *max_blocks = ((u_int64_t)1 << 30) / enc->block_size;
 if (state->rekey_limit)
  *max_blocks = (((*max_blocks) < (state->rekey_limit / enc->block_size)) ? (*max_blocks) : (state->rekey_limit / enc->block_size))
                                           ;
 sshlog("packet.c", __func__, 952, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "rekey %s after %llu blocks", dir, (unsigned long long)*max_blocks)
                                     ;
 return 0;
}


static int
ssh_packet_need_rekeying(struct ssh *ssh, u_int outbound_packet_len)
{
 struct session_state *state = ssh->state;
 u_int32_t out_blocks;


 if (!state->after_authentication)
  return 0;


 if (ssh_packet_is_rekeying(ssh))
  return 0;


 if (ssh->compat & 0x00008000)
  return 0;





 if (state->p_send.packets == 0 && state->p_read.packets == 0)
  return 0;


 if (state->rekey_interval != 0 &&
     (int64_t)state->rekey_time + state->rekey_interval <= monotime())
  return 1;





 if (state->p_send.packets > (1U<<31) ||
     state->p_read.packets > (1U<<31))
  return 1;


 out_blocks = ((((outbound_packet_len)+((state->newkeys[MODE_OUT]->enc.block_size)-1))/(state->newkeys[MODE_OUT]->enc.block_size))*(state->newkeys[MODE_OUT]->enc.block_size))
                                              ;
 return (state->max_blocks_out &&
     (state->p_send.blocks + out_blocks > state->max_blocks_out)) ||
     (state->max_blocks_in &&
     (state->p_read.blocks > state->max_blocks_in));
}

int
ssh_packet_check_rekey(struct ssh *ssh)
{
 if (!ssh_packet_need_rekeying(ssh, 0))
  return 0;
 sshlog("packet.c", __func__, 1010, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "rekex triggered");
 return kex_start_rekex(ssh);
}






static int
ssh_packet_enable_delayed_compress(struct ssh *ssh)
{
 struct session_state *state = ssh->state;
 struct sshcomp *comp = 
                       ((void *)0)
                           ;
 int r, mode;





 state->after_authentication = 1;
 for (mode = 0; mode < MODE_MAX; mode++) {

  if (state->newkeys[mode] == 
                             ((void *)0)
                                 )
   continue;
  comp = &state->newkeys[mode]->comp;
  if (comp && !comp->enabled && comp->type == 2) {
   if ((r = ssh_packet_init_compression(ssh)) != 0)
    return r;
   if (mode == MODE_OUT) {
    if ((r = start_compression_out(ssh, 6)) != 0)
     return r;
   } else {
    if ((r = start_compression_in(ssh)) != 0)
     return r;
   }
   comp->enabled = 1;
  }
 }
 return 0;
}


int
ssh_packet_log_type(u_char type)
{
 switch (type) {
 case 94:
 case 95:
 case 93:
  return 0;
 default:
  return 1;
 }
}




int
ssh_packet_send2_wrapped(struct ssh *ssh)
{
 struct session_state *state = ssh->state;
 u_char type, *cp, macbuf[64];
 u_char tmp, padlen, pad = 0;
 u_int authlen = 0, aadlen = 0;
 u_int len;
 struct sshenc *enc = 
                       ((void *)0)
                           ;
 struct sshmac *mac = 
                       ((void *)0)
                           ;
 struct sshcomp *comp = 
                       ((void *)0)
                           ;
 int r, block_size;

 if (state->newkeys[MODE_OUT] != 
                                ((void *)0)
                                    ) {
  enc = &state->newkeys[MODE_OUT]->enc;
  mac = &state->newkeys[MODE_OUT]->mac;
  comp = &state->newkeys[MODE_OUT]->comp;

  if ((authlen = cipher_authlen(enc->cipher)) != 0)
   mac = 
        ((void *)0)
            ;
 }
 block_size = enc ? enc->block_size : 8;
 aadlen = (mac && mac->enabled && mac->etm) || authlen ? 4 : 0;

 type = (sshbuf_ptr(state->outgoing_packet))[5];
 if (ssh_packet_log_type(type))
  sshlog("packet.c", __func__, 1095, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "send packet: type %u", type);





 if (comp && comp->enabled) {
  len = sshbuf_len(state->outgoing_packet);

  if ((r = sshbuf_consume(state->outgoing_packet, 5)) != 0)
   goto out;
  sshbuf_reset(state->compression_buffer);
  if ((r = compress_buffer(ssh, state->outgoing_packet,
      state->compression_buffer)) != 0)
   goto out;
  sshbuf_reset(state->outgoing_packet);
  if ((r = sshbuf_put(state->outgoing_packet,
      "\0\0\0\0\0", 5)) != 0 ||
      (r = sshbuf_putb(state->outgoing_packet,
      state->compression_buffer)) != 0)
   goto out;
 
                                          ;
 }


 len = sshbuf_len(state->outgoing_packet);





 len -= aadlen;
 padlen = block_size - (len % block_size);
 if (padlen < 4)
  padlen += block_size;
 if (state->extra_pad) {
  tmp = state->extra_pad;
  state->extra_pad =
      ((((state->extra_pad)+((block_size)-1))/(block_size))*(block_size));

  if (state->extra_pad < tmp)
   return -10;
  tmp = (len + padlen) % state->extra_pad;

  if (tmp > state->extra_pad)
   return -10;
  pad = state->extra_pad - tmp;
 
                                          ;
  tmp = padlen;
  padlen += pad;

  if (padlen < tmp)
   return -10;
  state->extra_pad = 0;
 }
 if ((r = sshbuf_reserve(state->outgoing_packet, padlen, &cp)) != 0)
  goto out;
 if (enc && !cipher_ctx_is_plaintext(state->send_context)) {

  arc4random_buf(cp, padlen);
 } else {

  explicit_bzero(cp, padlen);
 }

 len = sshbuf_len(state->outgoing_packet);
 cp = sshbuf_mutable_ptr(state->outgoing_packet);
 if (cp == 
          ((void *)0)
              ) {
  r = -1;
  goto out;
 }

 do { const u_int32_t __v = (len - 4); ((u_char *)(cp))[0] = (__v >> 24) & 0xff; ((u_char *)(cp))[1] = (__v >> 16) & 0xff; ((u_char *)(cp))[2] = (__v >> 8) & 0xff; ((u_char *)(cp))[3] = __v & 0xff; } while (0);
 cp[4] = padlen;

                          ;


 if (mac && mac->enabled && !mac->etm) {
  if ((r = mac_compute(mac, state->p_send.seqnr,
      sshbuf_ptr(state->outgoing_packet), len,
      macbuf, sizeof(macbuf))) != 0)
   goto out;
  ;
 }

 if ((r = sshbuf_reserve(state->output,
     sshbuf_len(state->outgoing_packet) + authlen, &cp)) != 0)
  goto out;
 if ((r = cipher_crypt(state->send_context, state->p_send.seqnr, cp,
     sshbuf_ptr(state->outgoing_packet),
     len - aadlen, aadlen, authlen)) != 0)
  goto out;

 if (mac && mac->enabled) {
  if (mac->etm) {

   if ((r = mac_compute(mac, state->p_send.seqnr,
       cp, len, macbuf, sizeof(macbuf))) != 0)
    goto out;
  
                            ;
  }
  if ((r = sshbuf_put(state->output, macbuf, mac->mac_len)) != 0)
   goto out;
 }





 if (++state->p_send.seqnr == 0)
  sshlog("packet.c", __func__, 1209, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "outgoing seqnr wraps around");
 if (++state->p_send.packets == 0)
  if (!(ssh->compat & 0x00008000))
   return -39;
 state->p_send.blocks += len / block_size;
 state->p_send.bytes += len;
 sshbuf_reset(state->outgoing_packet);

 if (type == 21)
  r = ssh_set_newkeys(ssh, MODE_OUT);
 else if (type == 52 && state->server_side)
  r = ssh_packet_enable_delayed_compress(ssh);
 else
  r = 0;
 out:
 return r;
}


static int
ssh_packet_type_is_kex(u_char type)
{
 return
     type >= 1 &&
     type <= 49 &&
     type != 5 &&
     type != 6 &&
     type != 7;
}

int
ssh_packet_send2(struct ssh *ssh)
{
 struct session_state *state = ssh->state;
 struct packet *p;
 u_char type;
 int r, need_rekey;

 if (sshbuf_len(state->outgoing_packet) < 6)
  return -1;
 type = sshbuf_ptr(state->outgoing_packet)[5];
 need_rekey = !ssh_packet_type_is_kex(type) &&
     ssh_packet_need_rekeying(ssh, sshbuf_len(state->outgoing_packet));





 if ((need_rekey || state->rekeying) && !ssh_packet_type_is_kex(type)) {
  if (need_rekey)
   sshlog("packet.c", __func__, 1259, 1, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "rekex triggered");
  sshlog("packet.c", __func__, 1260, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "enqueue packet: %u", type);
  p = calloc(1, sizeof(*p));
  if (p == 
          ((void *)0)
              )
   return -2;
  p->type = type;
  p->payload = state->outgoing_packet;
  do { (p)->next.tqe_next = 
 ((void *)0)
 ; (p)->next.tqe_prev = (&state->outgoing)->tqh_last; *(&state->outgoing)->tqh_last = (p); (&state->outgoing)->tqh_last = &(p)->next.tqe_next; } while (0);
  state->outgoing_packet = sshbuf_new();
  if (state->outgoing_packet == 
                               ((void *)0)
                                   )
   return -2;
  if (need_rekey) {





   return kex_start_rekex(ssh);
  }
  return 0;
 }


 if (type == 20)
  state->rekeying = 1;

 if ((r = ssh_packet_send2_wrapped(ssh)) != 0)
  return r;


 if (type == 21) {
  state->rekeying = 0;
  state->rekey_time = monotime();
  while ((p = ((&state->outgoing)->tqh_first))) {
   type = p->type;





   if (ssh_packet_need_rekeying(ssh,
       sshbuf_len(p->payload))) {
    sshlog("packet.c", __func__, 1301, 1, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "queued packet triggered rekex");
    return kex_start_rekex(ssh);
   }
   sshlog("packet.c", __func__, 1304, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "dequeue packet: %u", type);
   sshbuf_free(state->outgoing_packet);
   state->outgoing_packet = p->payload;
   do { if (((p)->next.tqe_next) != 
  ((void *)0)
  ) (p)->next.tqe_next->next.tqe_prev = (p)->next.tqe_prev; else (&state->outgoing)->tqh_last = (p)->next.tqe_prev; *(p)->next.tqe_prev = (p)->next.tqe_next; ; ; } while (0);
   memset(p, 0, sizeof(*p));
   free(p);
   if ((r = ssh_packet_send2_wrapped(ssh)) != 0)
    return r;
  }
 }
 return 0;
}







int
ssh_packet_read_seqnr(struct ssh *ssh, u_char *typep, u_int32_t *seqnr_p)
{
 struct session_state *state = ssh->state;
 int len, r, ms_remain;
 struct pollfd pfd;
 char buf[8192];
 struct timeval start;
 struct timespec timespec, *timespecp = 
                                       ((void *)0)
                                           ;

 ;





 if ((r = ssh_packet_write_wait(ssh)) != 0)
  goto out;


 for (;;) {

  r = ssh_packet_read_poll_seqnr(ssh, typep, seqnr_p);
  if (r != 0)
   break;

  if (*typep != 0)
   break;




  pfd.fd = state->connection_in;
  pfd.events = 
              0x001
                    ;

  if (state->packet_timeout_ms > 0) {
   ms_remain = state->packet_timeout_ms;
   timespecp = &timespec;
  }

  for (;;) {
   if (state->packet_timeout_ms > 0) {
    ms_to_timespec(&timespec, ms_remain);
    monotime_tv(&start);
   }
   if ((r = ppoll(&pfd, 1, timespecp, 
                                     ((void *)0)
                                         )) >= 0)
    break;
   if (
      (*__errno_location ()) 
            != 
               11 
                      && 
                         (*__errno_location ()) 
                               != 
                                  4 
                                        &&
       
      (*__errno_location ()) 
            != 
               11
                          ) {
    r = -24;
    goto out;
   }
   if (state->packet_timeout_ms <= 0)
    continue;
   ms_subtract_diff(&start, &ms_remain);
   if (ms_remain <= 0) {
    r = 0;
    break;
   }
  }
  if (r == 0) {
   r = -53;
   goto out;
  }

  len = read(state->connection_in, buf, sizeof(buf));
  if (len == 0) {
   r = -52;
   goto out;
  }
  if (len == -1) {
   r = -24;
   goto out;
  }


  if ((r = ssh_packet_process_incoming(ssh, buf, len)) != 0)
   goto out;
 }
 out:
 return r;
}

int
ssh_packet_read(struct ssh *ssh)
{
 u_char type;
 int r;

 if ((r = ssh_packet_read_seqnr(ssh, &type, 
                                           ((void *)0)
                                               )) != 0)
  sshfatal("packet.c", __func__, 1413, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "read");
 return type;
}






int
ssh_packet_read_expect(struct ssh *ssh, u_int expected_type)
{
 int r;
 u_char type;

 if ((r = ssh_packet_read_seqnr(ssh, &type, 
                                           ((void *)0)
                                               )) != 0)
  return r;
 if (type != expected_type) {
  if ((r = sshpkt_disconnect(ssh,
      "Protocol error: expected packet type %d, got %d",
      expected_type, type)) != 0)
   return r;
  return -55;
 }
 return 0;
}

static int
ssh_packet_read_poll2_mux(struct ssh *ssh, u_char *typep, u_int32_t *seqnr_p)
{
 struct session_state *state = ssh->state;
 const u_char *cp;
 size_t need;
 int r;

 if (ssh->kex)
  return -1;
 *typep = 0;
 cp = sshbuf_ptr(state->input);
 if (state->packlen == 0) {
  if (sshbuf_len(state->input) < 4 + 1)
   return 0;
  state->packlen = (((u_int32_t)(((const u_char *)(cp))[0]) << 24) | ((u_int32_t)(((const u_char *)(cp))[1]) << 16) | ((u_int32_t)(((const u_char *)(cp))[2]) << 8) | (u_int32_t)(((const u_char *)(cp))[3]));
  if (state->packlen < 4 + 1 ||
      state->packlen > (256 * 1024))
   return -3;
 }
 need = state->packlen + 4;
 if (sshbuf_len(state->input) < need)
  return 0;
 sshbuf_reset(state->incoming_packet);
 if ((r = sshbuf_put(state->incoming_packet, cp + 4,
     state->packlen)) != 0 ||
     (r = sshbuf_consume(state->input, need)) != 0 ||
     (r = sshbuf_get_u8(state->incoming_packet, 
                                               ((void *)0)
                                                   )) != 0 ||
     (r = sshbuf_get_u8(state->incoming_packet, typep)) != 0)
  return r;
 if (ssh_packet_log_type(*typep))
  sshlog("packet.c", __func__, 1471, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "type %u", *typep);


 state->packlen = 0;
 return r;
}

int
ssh_packet_read_poll2(struct ssh *ssh, u_char *typep, u_int32_t *seqnr_p)
{
 struct session_state *state = ssh->state;
 u_int padlen, need;
 u_char *cp;
 u_int maclen, aadlen = 0, authlen = 0, block_size;
 struct sshenc *enc = 
                       ((void *)0)
                           ;
 struct sshmac *mac = 
                       ((void *)0)
                           ;
 struct sshcomp *comp = 
                       ((void *)0)
                           ;
 int r;

 if (state->mux)
  return ssh_packet_read_poll2_mux(ssh, typep, seqnr_p);

 *typep = 0;

 if (state->packet_discard)
  return 0;

 if (state->newkeys[MODE_IN] != 
                               ((void *)0)
                                   ) {
  enc = &state->newkeys[MODE_IN]->enc;
  mac = &state->newkeys[MODE_IN]->mac;
  comp = &state->newkeys[MODE_IN]->comp;

  if ((authlen = cipher_authlen(enc->cipher)) != 0)
   mac = 
        ((void *)0)
            ;
 }
 maclen = mac && mac->enabled ? mac->mac_len : 0;
 block_size = enc ? enc->block_size : 8;
 aadlen = (mac && mac->enabled && mac->etm) || authlen ? 4 : 0;

 if (aadlen && state->packlen == 0) {
  if (cipher_get_length(state->receive_context,
      &state->packlen, state->p_read.seqnr,
      sshbuf_ptr(state->input), sshbuf_len(state->input)) != 0)
   return 0;
  if (state->packlen < 1 + 4 ||
      state->packlen > (256 * 1024)) {



   sshlog("packet.c", __func__, 1520, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Bad packet length %u.", state->packlen);
   if ((r = sshpkt_disconnect(ssh, "Packet corrupt")) != 0)
    return r;
   return -54;
  }
  sshbuf_reset(state->incoming_packet);
 } else if (state->packlen == 0) {




  if (sshbuf_len(state->input) < block_size)
   return 0;
  sshbuf_reset(state->incoming_packet);
  if ((r = sshbuf_reserve(state->incoming_packet, block_size,
      &cp)) != 0)
   goto out;
  if ((r = cipher_crypt(state->receive_context,
      state->p_send.seqnr, cp, sshbuf_ptr(state->input),
      block_size, 0, 0)) != 0)
   goto out;
  state->packlen = (((u_int32_t)(((const u_char *)(sshbuf_ptr(state->incoming_packet)))[0]) << 24) | ((u_int32_t)(((const u_char *)(sshbuf_ptr(state->incoming_packet)))[1]) << 16) | ((u_int32_t)(((const u_char *)(sshbuf_ptr(state->incoming_packet)))[2]) << 8) | (u_int32_t)(((const u_char *)(sshbuf_ptr(state->incoming_packet)))[3]));
  if (state->packlen < 1 + 4 ||
      state->packlen > (256 * 1024)) {






   sshlog("packet.c", __func__, 1550, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Bad packet length %u.", state->packlen);
   return ssh_packet_start_discard(ssh, enc, mac, 0,
       (256 * 1024));
  }
  if ((r = sshbuf_consume(state->input, block_size)) != 0)
   goto out;
 }
 ;

 if (aadlen) {

  need = state->packlen;
 } else {




  need = 4 + state->packlen - block_size;
 }

                                                              ;
 if (need % block_size != 0) {
  sshlog("packet.c", __func__, 1572, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "padding error: need %d block %d mod %d", need, block_size, need % block_size)
                                          ;
  return ssh_packet_start_discard(ssh, enc, mac, 0,
      (256 * 1024) - block_size);
 }
 if (sshbuf_len(state->input) < aadlen + need + authlen + maclen)
  return 0;





 if (mac && mac->enabled && mac->etm) {
  if ((r = mac_check(mac, state->p_read.seqnr,
      sshbuf_ptr(state->input), aadlen + need,
      sshbuf_ptr(state->input) + aadlen + need + authlen,
      maclen)) != 0) {
   if (r == -30)
    sshlog("packet.c", __func__, 1598, 0, SYSLOG_LEVEL_INFO, 
   ((void *)0)
   , "Corrupted MAC on input.");
   goto out;
  }
 }
 if ((r = sshbuf_reserve(state->incoming_packet, aadlen + need,
     &cp)) != 0)
  goto out;
 if ((r = cipher_crypt(state->receive_context, state->p_read.seqnr, cp,
     sshbuf_ptr(state->input), need, aadlen, authlen)) != 0)
  goto out;
 if ((r = sshbuf_consume(state->input, aadlen + need + authlen)) != 0)
  goto out;
 if (mac && mac->enabled) {

  if (!mac->etm && (r = mac_check(mac, state->p_read.seqnr,
      sshbuf_ptr(state->incoming_packet),
      sshbuf_len(state->incoming_packet),
      sshbuf_ptr(state->input), maclen)) != 0) {
   if (r != -30)
    goto out;
   sshlog("packet.c", __func__, 1618, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Corrupted MAC on input.");
   if (need + block_size > (256 * 1024))
    return -1;
   return ssh_packet_start_discard(ssh, enc, mac,
       sshbuf_len(state->incoming_packet),
       (256 * 1024) - need - block_size);
  }

  ;
  if ((r = sshbuf_consume(state->input, mac->mac_len)) != 0)
   goto out;
 }
 if (seqnr_p != 
               ((void *)0)
                   )
  *seqnr_p = state->p_read.seqnr;
 if (++state->p_read.seqnr == 0)
  sshlog("packet.c", __func__, 1633, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "incoming seqnr wraps around");
 if (++state->p_read.packets == 0)
  if (!(ssh->compat & 0x00008000))
   return -39;
 state->p_read.blocks += (state->packlen + 4) / block_size;
 state->p_read.bytes += state->packlen + 4;


 padlen = sshbuf_ptr(state->incoming_packet)[4];
 ;
 if (padlen < 4) {
  if ((r = sshpkt_disconnect(ssh,
      "Corrupted padlen %d on input.", padlen)) != 0 ||
      (r = ssh_packet_write_wait(ssh)) != 0)
   return r;
  return -54;
 }


 if ((r = sshbuf_consume(state->incoming_packet, 4 + 1)) != 0 ||
     ((r = sshbuf_consume_end(state->incoming_packet, padlen)) != 0))
  goto out;


                                         ;
 if (comp && comp->enabled) {
  sshbuf_reset(state->compression_buffer);
  if ((r = uncompress_buffer(ssh, state->incoming_packet,
      state->compression_buffer)) != 0)
   goto out;
  sshbuf_reset(state->incoming_packet);
  if ((r = sshbuf_putb(state->incoming_packet,
      state->compression_buffer)) != 0)
   goto out;
 
                                          ;
 }




 if ((r = sshbuf_get_u8(state->incoming_packet, typep)) != 0)
  goto out;
 if (ssh_packet_log_type(*typep))
  sshlog("packet.c", __func__, 1677, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "receive packet: type %u", *typep);
 if (*typep < 1 || *typep >= 192) {
  if ((r = sshpkt_disconnect(ssh,
      "Invalid ssh2 packet type: %d", *typep)) != 0 ||
      (r = ssh_packet_write_wait(ssh)) != 0)
   return r;
  return -55;
 }
 if (state->hook_in != 
                      ((void *)0) 
                           &&
     (r = state->hook_in(ssh, state->incoming_packet, typep,
     state->hook_in_ctx)) != 0)
  return r;
 if (*typep == 52 && !state->server_side)
  r = ssh_packet_enable_delayed_compress(ssh);
 else
  r = 0;





 state->packlen = 0;

 if ((r = ssh_packet_check_rekey(ssh)) != 0)
  return r;
 out:
 return r;
}

int
ssh_packet_read_poll_seqnr(struct ssh *ssh, u_char *typep, u_int32_t *seqnr_p)
{
 struct session_state *state = ssh->state;
 u_int reason, seqnr;
 int r;
 u_char *msg;

 for (;;) {
  msg = 
       ((void *)0)
           ;
  r = ssh_packet_read_poll2(ssh, typep, seqnr_p);
  if (r != 0)
   return r;
  if (*typep) {
   state->keep_alive_timeouts = 0;
   ;
  }
  switch (*typep) {
  case 2:
   sshlog("packet.c", __func__, 1725, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "Received SSH2_MSG_IGNORE");
   break;
  case 4:
   if ((r = sshpkt_get_u8(ssh, 
                              ((void *)0)
                                  )) != 0 ||
       (r = sshpkt_get_string(ssh, &msg, 
                                        ((void *)0)
                                            )) != 0 ||
       (r = sshpkt_get_string(ssh, 
                                  ((void *)0)
                                      , 
                                        ((void *)0)
                                            )) != 0) {
    free(msg);
    return r;
   }
   sshlog("packet.c", __func__, 1734, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Remote: %.900s", msg);
   free(msg);
   break;
  case 1:
   if ((r = sshpkt_get_u32(ssh, &reason)) != 0 ||
       (r = sshpkt_get_string(ssh, &msg, 
                                        ((void *)0)
                                            )) != 0)
    return r;

   sshlog("packet.c", __func__, 1742, 0, ssh->state->server_side && reason == 11 ? SYSLOG_LEVEL_INFO : SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Received disconnect from %s port %d:" "%u: %.400s", ssh_remote_ipaddr(ssh), ssh_remote_port(ssh), reason, msg)




                                         ;
   free(msg);
   return -29;
  case 3:
   if ((r = sshpkt_get_u32(ssh, &seqnr)) != 0)
    return r;
   sshlog("packet.c", __func__, 1753, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Received SSH2_MSG_UNIMPLEMENTED for %u", seqnr)
             ;
   break;
  default:
   return 0;
  }
 }
}





int
ssh_packet_process_incoming(struct ssh *ssh, const char *buf, u_int len)
{
 struct session_state *state = ssh->state;
 int r;

 if (state->packet_discard) {
  state->keep_alive_timeouts = 0;
  if (len >= state->packet_discard) {
   if ((r = ssh_packet_stop_discard(ssh)) != 0)
    return r;
  }
  state->packet_discard -= len;
  return 0;
 }
 if ((r = sshbuf_put(state->input, buf, len)) != 0)
  return r;

 return 0;
}


int
ssh_packet_process_read(struct ssh *ssh, int fd)
{
 struct session_state *state = ssh->state;
 int r;
 size_t rlen;

 if ((r = sshbuf_read(fd, state->input, (256 * 1024), &rlen)) != 0)
  return r;

 if (state->packet_discard) {
  if ((r = sshbuf_consume_end(state->input, rlen)) != 0)
   return r;
  state->keep_alive_timeouts = 0;
  if (rlen >= state->packet_discard) {
   if ((r = ssh_packet_stop_discard(ssh)) != 0)
    return r;
  }
  state->packet_discard -= rlen;
  return 0;
 }
 return 0;
}

int
ssh_packet_remaining(struct ssh *ssh)
{
 return sshbuf_len(ssh->state->incoming_packet);
}
void
ssh_packet_send_debug(struct ssh *ssh, const char *fmt,...)
{
 char buf[1024];
 va_list args;
 int r;

 if ((ssh->compat & 0x00000040))
  return;

 
__builtin_va_start(
args
,
fmt
)
                   ;
 vsnprintf(buf, sizeof(buf), fmt, args);
 
__builtin_va_end(
args
)
            ;

 sshlog("packet.c", __func__, 1840, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "sending debug message: %s", buf);

 if ((r = sshpkt_start(ssh, 4)) != 0 ||
     (r = sshpkt_put_u8(ssh, 0)) != 0 ||
     (r = sshpkt_put_cstring(ssh, buf)) != 0 ||
     (r = sshpkt_put_cstring(ssh, "")) != 0 ||
     (r = sshpkt_send(ssh)) != 0 ||
     (r = ssh_packet_write_wait(ssh)) != 0)
  sshfatal("packet.c", __func__, 1848, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send DEBUG");
}

void
sshpkt_fmt_connection_id(struct ssh *ssh, char *s, size_t l)
{
 snprintf(s, l, "%.200s%s%s port %d",
     ssh->log_preamble ? ssh->log_preamble : "",
     ssh->log_preamble ? " " : "",
     ssh_remote_ipaddr(ssh), ssh_remote_port(ssh));
}




static void
sshpkt_vfatal(struct ssh *ssh, int r, const char *fmt, va_list ap)
{
 char *tag = 
            ((void *)0)
                , remote_id[512];
 int oerrno = 
             (*__errno_location ())
                  ;

 sshpkt_fmt_connection_id(ssh, remote_id, sizeof(remote_id));

 switch (r) {
 case -52:
  ssh_packet_clear_keys(ssh);
  sshlogdie("packet.c", __func__, 1874, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Connection closed by %s", remote_id);
 case -53:
  ssh_packet_clear_keys(ssh);
  sshlogdie("packet.c", __func__, 1877, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Connection %s %s timed out", ssh->state->server_side ? "from" : "to", remote_id)
                                                         ;
 case -29:
  ssh_packet_clear_keys(ssh);
  sshlogdie("packet.c", __func__, 1881, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Disconnected from %s", remote_id);
 case -24:
  if (
     (*__errno_location ()) 
           == 
              104
                        ) {
   ssh_packet_clear_keys(ssh);
   sshlogdie("packet.c", __func__, 1885, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Connection reset by %s", remote_id);
  }

 case -31:
 case -32:
 case -33:
 case -34:
 case -35:
  if (ssh && ssh->kex && ssh->kex->failed_choice) {
   ssh_packet_clear_keys(ssh);
   
  (*__errno_location ()) 
        = oerrno;
   sshlogdie("packet.c", __func__, 1896, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Unable to negotiate with %s: %s. " "Their offer: %s", remote_id, ssh_err(r), ssh->kex->failed_choice)

                               ;
  }

 default:
  if (vasprintf(&tag, fmt, ap) == -1) {
   ssh_packet_clear_keys(ssh);
   sshlogdie("packet.c", __func__, 1904, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "could not allocate failure message");
  }
  ssh_packet_clear_keys(ssh);
  
 (*__errno_location ()) 
       = oerrno;
  sshlogdie("packet.c", __func__, 1908, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "%s%sConnection %s %s", tag != 
 ((void *)0) 
 ? tag : "", tag != 
 ((void *)0) 
 ? ": " : "", ssh->state->server_side ? "from" : "to", remote_id)

                                                         ;
 }
}

void
sshpkt_fatal(struct ssh *ssh, int r, const char *fmt, ...)
{
 va_list ap;

 
__builtin_va_start(
ap
,
fmt
)
                 ;
 sshpkt_vfatal(ssh, r, fmt, ap);

 
__builtin_va_end(
ap
)
          ;
 sshlogdie("packet.c", __func__, 1923, 1, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "should have exited");
}







void
ssh_packet_disconnect(struct ssh *ssh, const char *fmt,...)
{
 char buf[1024], remote_id[512];
 va_list args;
 static int disconnecting = 0;
 int r;

 if (disconnecting)
  sshfatal("packet.c", __func__, 1941, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "packet_disconnect called recursively.");
 disconnecting = 1;





 sshpkt_fmt_connection_id(ssh, remote_id, sizeof(remote_id));
 
__builtin_va_start(
args
,
fmt
)
                   ;
 vsnprintf(buf, sizeof(buf), fmt, args);
 
__builtin_va_end(
args
)
            ;


 sshlog("packet.c", __func__, 1954, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "Disconnecting %s: %.100s", remote_id, buf);





 if ((r = sshpkt_disconnect(ssh, "%s", buf)) != 0)
  sshpkt_fatal(ssh, r, "%s", __func__);

 if ((r = ssh_packet_write_wait(ssh)) != 0)
  sshpkt_fatal(ssh, r, "%s", __func__);


 ssh_packet_close(ssh);
 cleanup_exit(255);
}





int
ssh_packet_write_poll(struct ssh *ssh)
{
 struct session_state *state = ssh->state;
 int len = sshbuf_len(state->output);
 int r;

 if (len > 0) {
  len = write(state->connection_out,
      sshbuf_ptr(state->output), len);
  if (len == -1) {
   if (
      (*__errno_location ()) 
            == 
               4 
                     || 
                        (*__errno_location ()) 
                              == 
                                 11 
                                        ||
       
      (*__errno_location ()) 
            == 
               11
                          )
    return 0;
   return -24;
  }
  if (len == 0)
   return -52;
  if ((r = sshbuf_consume(state->output, len)) != 0)
   return r;
 }
 return 0;
}





int
ssh_packet_write_wait(struct ssh *ssh)
{
 int ret, r, ms_remain = 0;
 struct timeval start;
 struct timespec timespec, *timespecp = 
                                       ((void *)0)
                                           ;
 struct session_state *state = ssh->state;
 struct pollfd pfd;

 if ((r = ssh_packet_write_poll(ssh)) != 0)
  return r;
 while (ssh_packet_have_data_to_write(ssh)) {
  pfd.fd = state->connection_out;
  pfd.events = 
              0x004
                     ;

  if (state->packet_timeout_ms > 0) {
   ms_remain = state->packet_timeout_ms;
   timespecp = &timespec;
  }
  for (;;) {
   if (state->packet_timeout_ms > 0) {
    ms_to_timespec(&timespec, ms_remain);
    monotime_tv(&start);
   }
   if ((ret = ppoll(&pfd, 1, timespecp, 
                                       ((void *)0)
                                           )) >= 0)
    break;
   if (
      (*__errno_location ()) 
            != 
               11 
                      && 
                         (*__errno_location ()) 
                               != 
                                  4 
                                        &&
       
      (*__errno_location ()) 
            != 
               11
                          )
    break;
   if (state->packet_timeout_ms <= 0)
    continue;
   ms_subtract_diff(&start, &ms_remain);
   if (ms_remain <= 0) {
    ret = 0;
    break;
   }
  }
  if (ret == 0)
   return -53;
  if ((r = ssh_packet_write_poll(ssh)) != 0)
   return r;
 }
 return 0;
}



int
ssh_packet_have_data_to_write(struct ssh *ssh)
{
 return sshbuf_len(ssh->state->output) != 0;
}



int
ssh_packet_not_very_much_data_to_write(struct ssh *ssh)
{
 if (ssh->state->interactive_mode)
  return sshbuf_len(ssh->state->output) < 16384;
 else
  return sshbuf_len(ssh->state->output) < 128 * 1024;
}

void
ssh_packet_set_tos(struct ssh *ssh, int tos)
{
 if (!ssh_packet_connection_is_on_socket(ssh) || tos == 0x7fffffff)
  return;
 set_sock_tos(ssh->state->connection_in, tos);
}



void
ssh_packet_set_interactive(struct ssh *ssh, int interactive, int qos_interactive, int qos_bulk)
{
 struct session_state *state = ssh->state;

 if (state->set_interactive_called)
  return;
 state->set_interactive_called = 1;


 state->interactive_mode = interactive;


 if (!ssh_packet_connection_is_on_socket(ssh))
  return;
 set_nodelay(state->connection_in);
 ssh_packet_set_tos(ssh, interactive ? qos_interactive : qos_bulk);
}



int
ssh_packet_is_interactive(struct ssh *ssh)
{
 return ssh->state->interactive_mode;
}

int
ssh_packet_set_maxsize(struct ssh *ssh, u_int s)
{
 struct session_state *state = ssh->state;

 if (state->set_maxsize_called) {
  sshlog("packet.c", __func__, 2110, 1, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "called twice: old %d new %d", state->max_packet_size, s)
                                ;
  return -1;
 }
 if (s < 4 * 1024 || s > 1024 * 1024) {
  sshlog("packet.c", __func__, 2115, 1, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "bad size %d", s);
  return -1;
 }
 state->set_maxsize_called = 1;
 sshlog("packet.c", __func__, 2119, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "setting to %d", s);
 state->max_packet_size = s;
 return s;
}

int
ssh_packet_inc_alive_timeouts(struct ssh *ssh)
{
 return ++ssh->state->keep_alive_timeouts;
}

void
ssh_packet_set_alive_timeouts(struct ssh *ssh, int ka)
{
 ssh->state->keep_alive_timeouts = ka;
}

u_int
ssh_packet_get_maxsize(struct ssh *ssh)
{
 return ssh->state->max_packet_size;
}

void
ssh_packet_set_rekey_limits(struct ssh *ssh, u_int64_t bytes, u_int32_t seconds)
{
 sshlog("packet.c", __func__, 2145, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "rekey after %llu bytes, %u seconds", (unsigned long long)bytes, (unsigned int)seconds)
                           ;
 ssh->state->rekey_limit = bytes;
 ssh->state->rekey_interval = seconds;
}

time_t
ssh_packet_get_rekey_timeout(struct ssh *ssh)
{
 time_t seconds;

 seconds = ssh->state->rekey_time + ssh->state->rekey_interval -
     monotime();
 return (seconds <= 0 ? 1 : seconds);
}

void
ssh_packet_set_server(struct ssh *ssh)
{
 ssh->state->server_side = 1;
 ssh->kex->server = 1;
}

void
ssh_packet_set_authenticated(struct ssh *ssh)
{
 ssh->state->after_authentication = 1;
}

void *
ssh_packet_get_input(struct ssh *ssh)
{
 return (void *)ssh->state->input;
}

void *
ssh_packet_get_output(struct ssh *ssh)
{
 return (void *)ssh->state->output;
}


static int
ssh_packet_set_postauth(struct ssh *ssh)
{
 int r;

 sshlog("packet.c", __func__, 2192, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "called");

 ssh->state->after_authentication = 1;
 ssh->state->rekeying = 0;
 if ((r = ssh_packet_enable_delayed_compress(ssh)) != 0)
  return r;
 return 0;
}




static int
kex_to_blob(struct sshbuf *m, struct kex *kex)
{
 int r;

 if ((r = sshbuf_put_u32(m, kex->we_need)) != 0 ||
     (r = sshbuf_put_cstring(m, kex->hostkey_alg)) != 0 ||
     (r = sshbuf_put_u32(m, kex->hostkey_type)) != 0 ||
     (r = sshbuf_put_u32(m, kex->hostkey_nid)) != 0 ||
     (r = sshbuf_put_u32(m, kex->kex_type)) != 0 ||
     (r = sshbuf_put_stringb(m, kex->my)) != 0 ||
     (r = sshbuf_put_stringb(m, kex->peer)) != 0 ||
     (r = sshbuf_put_stringb(m, kex->client_version)) != 0 ||
     (r = sshbuf_put_stringb(m, kex->server_version)) != 0 ||
     (r = sshbuf_put_stringb(m, kex->session_id)) != 0 ||
     (r = sshbuf_put_u32(m, kex->flags)) != 0)
  return r;
 return 0;
}


static int
newkeys_to_blob(struct sshbuf *m, struct ssh *ssh, int mode)
{
 struct sshbuf *b;
 struct sshcipher_ctx *cc;
 struct sshcomp *comp;
 struct sshenc *enc;
 struct sshmac *mac;
 struct newkeys *newkey;
 int r;

 if ((newkey = ssh->state->newkeys[mode]) == 
                                            ((void *)0)
                                                )
  return -1;
 enc = &newkey->enc;
 mac = &newkey->mac;
 comp = &newkey->comp;
 cc = (mode == MODE_OUT) ? ssh->state->send_context :
     ssh->state->receive_context;
 if ((r = cipher_get_keyiv(cc, enc->iv, enc->iv_len)) != 0)
  return r;
 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              )
  return -2;
 if ((r = sshbuf_put_cstring(b, enc->name)) != 0 ||
     (r = sshbuf_put_u32(b, enc->enabled)) != 0 ||
     (r = sshbuf_put_u32(b, enc->block_size)) != 0 ||
     (r = sshbuf_put_string(b, enc->key, enc->key_len)) != 0 ||
     (r = sshbuf_put_string(b, enc->iv, enc->iv_len)) != 0)
  goto out;
 if (cipher_authlen(enc->cipher) == 0) {
  if ((r = sshbuf_put_cstring(b, mac->name)) != 0 ||
      (r = sshbuf_put_u32(b, mac->enabled)) != 0 ||
      (r = sshbuf_put_string(b, mac->key, mac->key_len)) != 0)
   goto out;
 }
 if ((r = sshbuf_put_u32(b, comp->type)) != 0 ||
     (r = sshbuf_put_cstring(b, comp->name)) != 0)
  goto out;
 r = sshbuf_put_stringb(m, b);
 out:
 sshbuf_free(b);
 return r;
}


int
ssh_packet_get_state(struct ssh *ssh, struct sshbuf *m)
{
 struct session_state *state = ssh->state;
 int r;

 if ((r = kex_to_blob(m, ssh->kex)) != 0 ||
     (r = newkeys_to_blob(m, ssh, MODE_OUT)) != 0 ||
     (r = newkeys_to_blob(m, ssh, MODE_IN)) != 0 ||
     (r = sshbuf_put_u64(m, state->rekey_limit)) != 0 ||
     (r = sshbuf_put_u32(m, state->rekey_interval)) != 0 ||
     (r = sshbuf_put_u32(m, state->p_send.seqnr)) != 0 ||
     (r = sshbuf_put_u64(m, state->p_send.blocks)) != 0 ||
     (r = sshbuf_put_u32(m, state->p_send.packets)) != 0 ||
     (r = sshbuf_put_u64(m, state->p_send.bytes)) != 0 ||
     (r = sshbuf_put_u32(m, state->p_read.seqnr)) != 0 ||
     (r = sshbuf_put_u64(m, state->p_read.blocks)) != 0 ||
     (r = sshbuf_put_u32(m, state->p_read.packets)) != 0 ||
     (r = sshbuf_put_u64(m, state->p_read.bytes)) != 0 ||
     (r = sshbuf_put_stringb(m, state->input)) != 0 ||
     (r = sshbuf_put_stringb(m, state->output)) != 0)
  return r;

 return 0;
}


static int
newkeys_from_blob(struct sshbuf *m, struct ssh *ssh, int mode)
{
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 struct sshcomp *comp;
 struct sshenc *enc;
 struct sshmac *mac;
 struct newkeys *newkey = 
                         ((void *)0)
                             ;
 size_t keylen, ivlen, maclen;
 int r;

 if ((newkey = calloc(1, sizeof(*newkey))) == 
                                             ((void *)0)
                                                 ) {
  r = -2;
  goto out;
 }
 if ((r = sshbuf_froms(m, &b)) != 0)
  goto out;



 enc = &newkey->enc;
 mac = &newkey->mac;
 comp = &newkey->comp;

 if ((r = sshbuf_get_cstring(b, &enc->name, 
                                           ((void *)0)
                                               )) != 0 ||
     (r = sshbuf_get_u32(b, (u_int *)&enc->enabled)) != 0 ||
     (r = sshbuf_get_u32(b, &enc->block_size)) != 0 ||
     (r = sshbuf_get_string(b, &enc->key, &keylen)) != 0 ||
     (r = sshbuf_get_string(b, &enc->iv, &ivlen)) != 0)
  goto out;
 if ((enc->cipher = cipher_by_name(enc->name)) == 
                                                 ((void *)0)
                                                     ) {
  r = -4;
  goto out;
 }
 if (cipher_authlen(enc->cipher) == 0) {
  if ((r = sshbuf_get_cstring(b, &mac->name, 
                                            ((void *)0)
                                                )) != 0)
   goto out;
  if ((r = mac_setup(mac, mac->name)) != 0)
   goto out;
  if ((r = sshbuf_get_u32(b, (u_int *)&mac->enabled)) != 0 ||
      (r = sshbuf_get_string(b, &mac->key, &maclen)) != 0)
   goto out;
  if (maclen > mac->key_len) {
   r = -4;
   goto out;
  }
  mac->key_len = maclen;
 }
 if ((r = sshbuf_get_u32(b, &comp->type)) != 0 ||
     (r = sshbuf_get_cstring(b, &comp->name, 
                                            ((void *)0)
                                                )) != 0)
  goto out;
 if (sshbuf_len(b) != 0) {
  r = -4;
  goto out;
 }
 enc->key_len = keylen;
 enc->iv_len = ivlen;
 ssh->kex->newkeys[mode] = newkey;
 newkey = 
         ((void *)0)
             ;
 r = 0;
 out:
 free(newkey);
 sshbuf_free(b);
 return r;
}


static int
kex_from_blob(struct sshbuf *m, struct kex **kexp)
{
 struct kex *kex;
 int r;

 if ((kex = kex_new()) == 
                         ((void *)0)
                             )
  return -2;
 if ((r = sshbuf_get_u32(m, &kex->we_need)) != 0 ||
     (r = sshbuf_get_cstring(m, &kex->hostkey_alg, 
                                                  ((void *)0)
                                                      )) != 0 ||
     (r = sshbuf_get_u32(m, (u_int *)&kex->hostkey_type)) != 0 ||
     (r = sshbuf_get_u32(m, (u_int *)&kex->hostkey_nid)) != 0 ||
     (r = sshbuf_get_u32(m, &kex->kex_type)) != 0 ||
     (r = sshbuf_get_stringb(m, kex->my)) != 0 ||
     (r = sshbuf_get_stringb(m, kex->peer)) != 0 ||
     (r = sshbuf_get_stringb(m, kex->client_version)) != 0 ||
     (r = sshbuf_get_stringb(m, kex->server_version)) != 0 ||
     (r = sshbuf_get_stringb(m, kex->session_id)) != 0 ||
     (r = sshbuf_get_u32(m, &kex->flags)) != 0)
  goto out;
 kex->server = 1;
 kex->done = 1;
 r = 0;
 out:
 if (r != 0 || kexp == 
                      ((void *)0)
                          ) {
  kex_free(kex);
  if (kexp != 
             ((void *)0)
                 )
   *kexp = 
          ((void *)0)
              ;
 } else {
  kex_free(*kexp);
  *kexp = kex;
 }
 return r;
}





int
ssh_packet_set_state(struct ssh *ssh, struct sshbuf *m)
{
 struct session_state *state = ssh->state;
 const u_char *input, *output;
 size_t ilen, olen;
 int r;

 if ((r = kex_from_blob(m, &ssh->kex)) != 0 ||
     (r = newkeys_from_blob(m, ssh, MODE_OUT)) != 0 ||
     (r = newkeys_from_blob(m, ssh, MODE_IN)) != 0 ||
     (r = sshbuf_get_u64(m, &state->rekey_limit)) != 0 ||
     (r = sshbuf_get_u32(m, &state->rekey_interval)) != 0 ||
     (r = sshbuf_get_u32(m, &state->p_send.seqnr)) != 0 ||
     (r = sshbuf_get_u64(m, &state->p_send.blocks)) != 0 ||
     (r = sshbuf_get_u32(m, &state->p_send.packets)) != 0 ||
     (r = sshbuf_get_u64(m, &state->p_send.bytes)) != 0 ||
     (r = sshbuf_get_u32(m, &state->p_read.seqnr)) != 0 ||
     (r = sshbuf_get_u64(m, &state->p_read.blocks)) != 0 ||
     (r = sshbuf_get_u32(m, &state->p_read.packets)) != 0 ||
     (r = sshbuf_get_u64(m, &state->p_read.bytes)) != 0)
  return r;




 state->rekey_time = monotime();

 if ((r = ssh_set_newkeys(ssh, MODE_IN)) != 0 ||
     (r = ssh_set_newkeys(ssh, MODE_OUT)) != 0)
  return r;

 if ((r = ssh_packet_set_postauth(ssh)) != 0)
  return r;

 sshbuf_reset(state->input);
 sshbuf_reset(state->output);
 if ((r = sshbuf_get_string_direct(m, &input, &ilen)) != 0 ||
     (r = sshbuf_get_string_direct(m, &output, &olen)) != 0 ||
     (r = sshbuf_put(state->input, input, ilen)) != 0 ||
     (r = sshbuf_put(state->output, output, olen)) != 0)
  return r;

 if (sshbuf_len(m))
  return -4;
 sshlog("packet.c", __func__, 2447, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "done");
 return 0;
}





int
sshpkt_put(struct ssh *ssh, const void *v, size_t len)
{
 return sshbuf_put(ssh->state->outgoing_packet, v, len);
}

int
sshpkt_putb(struct ssh *ssh, const struct sshbuf *b)
{
 return sshbuf_putb(ssh->state->outgoing_packet, b);
}

int
sshpkt_put_u8(struct ssh *ssh, u_char val)
{
 return sshbuf_put_u8(ssh->state->outgoing_packet, val);
}

int
sshpkt_put_u32(struct ssh *ssh, u_int32_t val)
{
 return sshbuf_put_u32(ssh->state->outgoing_packet, val);
}

int
sshpkt_put_u64(struct ssh *ssh, u_int64_t val)
{
 return sshbuf_put_u64(ssh->state->outgoing_packet, val);
}

int
sshpkt_put_string(struct ssh *ssh, const void *v, size_t len)
{
 return sshbuf_put_string(ssh->state->outgoing_packet, v, len);
}

int
sshpkt_put_cstring(struct ssh *ssh, const void *v)
{
 return sshbuf_put_cstring(ssh->state->outgoing_packet, v);
}

int
sshpkt_put_stringb(struct ssh *ssh, const struct sshbuf *v)
{
 return sshbuf_put_stringb(ssh->state->outgoing_packet, v);
}

int
sshpkt_getb_froms(struct ssh *ssh, struct sshbuf **valp)
{
 return sshbuf_froms(ssh->state->incoming_packet, valp);
}



int
sshpkt_put_ec(struct ssh *ssh, const EC_POINT *v, const EC_GROUP *g)
{
 return sshbuf_put_ec(ssh->state->outgoing_packet, v, g);
}



int
sshpkt_put_bignum2(struct ssh *ssh, const BIGNUM *v)
{
 return sshbuf_put_bignum2(ssh->state->outgoing_packet, v);
}




int
sshpkt_get(struct ssh *ssh, void *valp, size_t len)
{
 return sshbuf_get(ssh->state->incoming_packet, valp, len);
}

int
sshpkt_get_u8(struct ssh *ssh, u_char *valp)
{
 return sshbuf_get_u8(ssh->state->incoming_packet, valp);
}

int
sshpkt_get_u32(struct ssh *ssh, u_int32_t *valp)
{
 return sshbuf_get_u32(ssh->state->incoming_packet, valp);
}

int
sshpkt_get_u64(struct ssh *ssh, u_int64_t *valp)
{
 return sshbuf_get_u64(ssh->state->incoming_packet, valp);
}

int
sshpkt_get_string(struct ssh *ssh, u_char **valp, size_t *lenp)
{
 return sshbuf_get_string(ssh->state->incoming_packet, valp, lenp);
}

int
sshpkt_get_string_direct(struct ssh *ssh, const u_char **valp, size_t *lenp)
{
 return sshbuf_get_string_direct(ssh->state->incoming_packet, valp, lenp);
}

int
sshpkt_peek_string_direct(struct ssh *ssh, const u_char **valp, size_t *lenp)
{
 return sshbuf_peek_string_direct(ssh->state->incoming_packet, valp, lenp);
}

int
sshpkt_get_cstring(struct ssh *ssh, char **valp, size_t *lenp)
{
 return sshbuf_get_cstring(ssh->state->incoming_packet, valp, lenp);
}



int
sshpkt_get_ec(struct ssh *ssh, EC_POINT *v, const EC_GROUP *g)
{
 return sshbuf_get_ec(ssh->state->incoming_packet, v, g);
}


int
sshpkt_get_bignum2(struct ssh *ssh, BIGNUM **valp)
{
 return sshbuf_get_bignum2(ssh->state->incoming_packet, valp);
}


int
sshpkt_get_end(struct ssh *ssh)
{
 if (sshbuf_len(ssh->state->incoming_packet) > 0)
  return -23;
 return 0;
}

const u_char *
sshpkt_ptr(struct ssh *ssh, size_t *lenp)
{
 if (lenp != 
            ((void *)0)
                )
  *lenp = sshbuf_len(ssh->state->incoming_packet);
 return sshbuf_ptr(ssh->state->incoming_packet);
}



int
sshpkt_start(struct ssh *ssh, u_char type)
{
 u_char buf[6];

 ;
 memset(buf, 0, sizeof(buf));
 buf[sizeof(buf) - 1] = type;
 sshbuf_reset(ssh->state->outgoing_packet);
 return sshbuf_put(ssh->state->outgoing_packet, buf, sizeof(buf));
}

static int
ssh_packet_send_mux(struct ssh *ssh)
{
 struct session_state *state = ssh->state;
 u_char type, *cp;
 size_t len;
 int r;

 if (ssh->kex)
  return -1;
 len = sshbuf_len(state->outgoing_packet);
 if (len < 6)
  return -1;
 cp = sshbuf_mutable_ptr(state->outgoing_packet);
 type = cp[5];
 if (ssh_packet_log_type(type))
  sshlog("packet.c", __func__, 2638, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "type %u", type);

 if (type >= 80 &&
     type <= 127) {
  do { const u_int32_t __v = (len - 4); ((u_char *)(cp))[0] = (__v >> 24) & 0xff; ((u_char *)(cp))[1] = (__v >> 16) & 0xff; ((u_char *)(cp))[2] = (__v >> 8) & 0xff; ((u_char *)(cp))[3] = __v & 0xff; } while (0);
  if ((r = sshbuf_putb(state->output,
      state->outgoing_packet)) != 0)
   return r;

 }
 sshbuf_reset(state->outgoing_packet);
 return 0;
}
int
sshpkt_msg_ignore(struct ssh *ssh, u_int nbytes)
{
 u_int32_t rnd = 0;
 int r;
 u_int i;

 if ((r = sshpkt_start(ssh, 2)) != 0 ||
     (r = sshpkt_put_u32(ssh, nbytes)) != 0)
  return r;
 for (i = 0; i < nbytes; i++) {
  if (i % 4 == 0)
   rnd = arc4random();
  if ((r = sshpkt_put_u8(ssh, (u_char)rnd & 0xff)) != 0)
   return r;
  rnd >>= 8;
 }
 return 0;
}



int
sshpkt_send(struct ssh *ssh)
{
 if (ssh->state && ssh->state->mux)
  return ssh_packet_send_mux(ssh);
 return ssh_packet_send2(ssh);
}

int
sshpkt_disconnect(struct ssh *ssh, const char *fmt,...)
{
 char buf[1024];
 va_list args;
 int r;

 
__builtin_va_start(
args
,
fmt
)
                   ;
 vsnprintf(buf, sizeof(buf), fmt, args);
 
__builtin_va_end(
args
)
            ;

 if ((r = sshpkt_start(ssh, 1)) != 0 ||
     (r = sshpkt_put_u32(ssh, 2)) != 0 ||
     (r = sshpkt_put_cstring(ssh, buf)) != 0 ||
     (r = sshpkt_put_cstring(ssh, "")) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  return r;
 return 0;
}


int
sshpkt_add_padding(struct ssh *ssh, u_char pad)
{
 ssh->state->extra_pad = pad;
 return 0;
}
