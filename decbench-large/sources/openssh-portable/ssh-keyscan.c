











































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
struct ssh;

void compat_banner(struct ssh *, const char *);
char *compat_cipher_proposal(struct ssh *, char *);
char *compat_pkalg_proposal(struct ssh *, char *);
char *compat_kex_proposal(struct ssh *, char *);
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



struct kex_params {
 char *proposal[PROPOSAL_MAX];
};







int ssh_init(struct ssh **, int is_server, struct kex_params *kex_params);




void ssh_free(struct ssh *);




void ssh_set_app_data(struct ssh *, void *);
void *ssh_get_app_data(struct ssh *);
int ssh_add_hostkey(struct ssh *ssh, struct sshkey *key);







int ssh_set_verify_host_key_callback(struct ssh *ssh,
    int (*cb)(struct sshkey *, struct ssh *));
int ssh_packet_next(struct ssh *ssh, u_char *typep);






const u_char *ssh_packet_payload(struct ssh *ssh, size_t *lenp);






int ssh_packet_put(struct ssh *ssh, int type, const u_char *data,
    size_t len);





int ssh_input_space(struct ssh *ssh, size_t len);




int ssh_input_append(struct ssh *ssh, const u_char *data, size_t len);





int ssh_output_space(struct ssh *ssh, size_t len);







const u_char *ssh_output_ptr(struct ssh *ssh, size_t *len);





int ssh_output_consume(struct ssh *ssh, size_t len);
enum sshfp_types {
 SSHFP_KEY_RESERVED = 0,
 SSHFP_KEY_RSA = 1,
 SSHFP_KEY_DSA = 2,
 SSHFP_KEY_ECDSA = 3,
 SSHFP_KEY_ED25519 = 4,
 SSHFP_KEY_XMSS = 5
};

enum sshfp_hashes {
 SSHFP_HASH_RESERVED = 0,
 SSHFP_HASH_SHA1 = 1,
 SSHFP_HASH_SHA256 = 2,
 SSHFP_HASH_MAX = 3
};
int verify_host_key_dns(const char *, struct sockaddr *,
    struct sshkey *, int *);
int export_dns_rr(const char *, struct sshkey *, FILE *, int);



int IPv4or6 = 
             0
                      ;

int ssh_port = 22;
int get_cert = 0;
int get_keytypes = (1<<1)|(1<<2)|(1<<3)|(1<<5)|(1<<6);

int hash_hosts = 0;

int print_sshfp = 0;

int found_one = 0;




int timeout = 5;

int maxfd;


extern char *__progname;
struct pollfd *read_wait;
int ncon;





typedef struct Connection {
 u_char c_status;




 int c_fd;
 int c_plen;
 int c_len;
 int c_off;
 int c_keytype;
 sig_atomic_t c_done;
 char *c_namebase;
 char *c_name;
 char *c_namelist;
 char *c_output_name;
 char *c_data;
 struct ssh *c_ssh;
 struct timespec c_ts;
 struct { struct Connection *tqe_next; struct Connection **tqe_prev; } c_link;
} con;

struct conlist { struct Connection *tqh_first; struct Connection **tqh_last; } tq;
con *fdcon;

static void keyprint(con *c, struct sshkey *key);

static int
fdlim_get(int hard)
{

 struct rlimit rlfd;

 if (getrlimit(
              RLIMIT_NOFILE
                           , &rlfd) == -1)
  return (-1);
 if ((hard ? rlfd.rlim_max : rlfd.rlim_cur) == 
                                              ((__rlim_t) -1)
                                                           )
  return sysconf(
        _SC_OPEN_MAX
        );
 else
  return hard ? rlfd.rlim_max : rlfd.rlim_cur;



}

static int
fdlim_set(int lim)
{

 struct rlimit rlfd;


 if (lim <= 0)
  return (-1);

 if (getrlimit(
              RLIMIT_NOFILE
                           , &rlfd) == -1)
  return (-1);
 rlfd.rlim_cur = lim;
 if (setrlimit(
              RLIMIT_NOFILE
                           , &rlfd) == -1)
  return (-1);



 return (0);
}






static char *
xstrsep(char **str, const char *delim)
{
 char *s, *e;

 if (!**str)
  return (
         ((void *)0)
             );

 s = *str;
 e = s + strcspn(s, delim);

 if (*e != '\0')
  *e++ = '\0';
 *str = e;

 return (s);
}





static char *
strnnsep(char **stringp, char *delim)
{
 char *tok;

 do {
  tok = xstrsep(stringp, delim);
 } while (tok && *tok == '\0');
 return (tok);
}


static int
key_print_wrapper(struct sshkey *hostkey, struct ssh *ssh)
{
 con *c;

 if ((c = ssh_get_app_data(ssh)) != 
                                   ((void *)0)
                                       )
  keyprint(c, hostkey);

 return -1;
}

static int
ssh2_capable(int remote_major, int remote_minor)
{
 switch (remote_major) {
 case 1:
  if (remote_minor == 99)
   return 1;
  break;
 case 2:
  return 1;
 default:
  break;
 }
 return 0;
}

static void
keygrab_ssh2(con *c)
{
 char *myproposal[PROPOSAL_MAX] = { "sntrup761x25519-sha512@openssh.com," "curve25519-sha256," "curve25519-sha256@libssh.org," "ecdh-sha2-nistp256," "ecdh-sha2-nistp384," "ecdh-sha2-nistp521," "diffie-hellman-group-exchange-sha256," "diffie-hellman-group16-sha512," "diffie-hellman-group18-sha512," "diffie-hellman-group14-sha256", "ssh-ed25519-cert-v01@openssh.com," "ecdsa-sha2-nistp256-cert-v01@openssh.com," "ecdsa-sha2-nistp384-cert-v01@openssh.com," "ecdsa-sha2-nistp521-cert-v01@openssh.com," "sk-ssh-ed25519-cert-v01@openssh.com," "sk-ecdsa-sha2-nistp256-cert-v01@openssh.com," "rsa-sha2-512-cert-v01@openssh.com," "rsa-sha2-256-cert-v01@openssh.com," "ssh-ed25519," "ecdsa-sha2-nistp256," "ecdsa-sha2-nistp384," "ecdsa-sha2-nistp521," "sk-ssh-ed25519@openssh.com," "sk-ecdsa-sha2-nistp256@openssh.com," "rsa-sha2-512," "rsa-sha2-256", "chacha20-poly1305@openssh.com," "aes128-ctr,aes192-ctr,aes256-ctr," "aes128-gcm@openssh.com,aes256-gcm@openssh.com", "chacha20-poly1305@openssh.com," "aes128-ctr,aes192-ctr,aes256-ctr," "aes128-gcm@openssh.com,aes256-gcm@openssh.com", "umac-64-etm@openssh.com," "umac-128-etm@openssh.com," "hmac-sha2-256-etm@openssh.com," "hmac-sha2-512-etm@openssh.com," "hmac-sha1-etm@openssh.com," "umac-64@openssh.com," "umac-128@openssh.com," "hmac-sha2-256," "hmac-sha2-512," "hmac-sha1", "umac-64-etm@openssh.com," "umac-128-etm@openssh.com," "hmac-sha2-256-etm@openssh.com," "hmac-sha2-512-etm@openssh.com," "hmac-sha1-etm@openssh.com," "umac-64@openssh.com," "umac-128@openssh.com," "hmac-sha2-256," "hmac-sha2-512," "hmac-sha1", "none,zlib@openssh.com", "none,zlib@openssh.com", "", "" };
 int r;

 switch (c->c_keytype) {
 case (1):
  myproposal[PROPOSAL_SERVER_HOST_KEY_ALGS] = get_cert ?
      "ssh-dss-cert-v01@openssh.com" : "ssh-dss";
  break;
 case (1<<1):
  myproposal[PROPOSAL_SERVER_HOST_KEY_ALGS] = get_cert ?
      "rsa-sha2-512-cert-v01@openssh.com,"
      "rsa-sha2-256-cert-v01@openssh.com,"
      "ssh-rsa-cert-v01@openssh.com" :
      "rsa-sha2-512,"
      "rsa-sha2-256,"
      "ssh-rsa";
  break;
 case (1<<3):
  myproposal[PROPOSAL_SERVER_HOST_KEY_ALGS] = get_cert ?
      "ssh-ed25519-cert-v01@openssh.com" : "ssh-ed25519";
  break;
 case (1<<4):
  myproposal[PROPOSAL_SERVER_HOST_KEY_ALGS] = get_cert ?
      "ssh-xmss-cert-v01@openssh.com" : "ssh-xmss@openssh.com";
  break;
 case (1<<2):
  myproposal[PROPOSAL_SERVER_HOST_KEY_ALGS] = get_cert ?
      "ecdsa-sha2-nistp256-cert-v01@openssh.com,"
      "ecdsa-sha2-nistp384-cert-v01@openssh.com,"
      "ecdsa-sha2-nistp521-cert-v01@openssh.com" :
      "ecdsa-sha2-nistp256,"
      "ecdsa-sha2-nistp384,"
      "ecdsa-sha2-nistp521";
  break;
 case (1<<5):
  myproposal[PROPOSAL_SERVER_HOST_KEY_ALGS] = get_cert ?
      "sk-ecdsa-sha2-nistp256-cert-v01@openssh.com" :
      "sk-ecdsa-sha2-nistp256@openssh.com";
  break;
 case (1<<6):
  myproposal[PROPOSAL_SERVER_HOST_KEY_ALGS] = get_cert ?
      "sk-ssh-ed25519-cert-v01@openssh.com" :
      "sk-ssh-ed25519@openssh.com";
  break;
 default:
  sshfatal("ssh-keyscan.c", __func__, 277, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "unknown key type %d", c->c_keytype);
  break;
 }
 if ((r = kex_setup(c->c_ssh, myproposal)) != 0) {
  free(c->c_ssh);
  fprintf(
         stderr
               , "kex_setup: %s\n", ssh_err(r));
  exit(1);
 }

 c->c_ssh->kex->kex[KEX_DH_GRP1_SHA1] = kex_gen_client;
 c->c_ssh->kex->kex[KEX_DH_GRP14_SHA1] = kex_gen_client;
 c->c_ssh->kex->kex[KEX_DH_GRP14_SHA256] = kex_gen_client;
 c->c_ssh->kex->kex[KEX_DH_GRP16_SHA512] = kex_gen_client;
 c->c_ssh->kex->kex[KEX_DH_GRP18_SHA512] = kex_gen_client;
 c->c_ssh->kex->kex[KEX_DH_GEX_SHA1] = kexgex_client;
 c->c_ssh->kex->kex[KEX_DH_GEX_SHA256] = kexgex_client;

 c->c_ssh->kex->kex[KEX_ECDH_SHA2] = kex_gen_client;


 c->c_ssh->kex->kex[KEX_C25519_SHA256] = kex_gen_client;
 c->c_ssh->kex->kex[KEX_KEM_SNTRUP761X25519_SHA512] = kex_gen_client;
 ssh_set_verify_host_key_callback(c->c_ssh, key_print_wrapper);




 ssh_dispatch_run(c->c_ssh, DISPATCH_BLOCK, &c->c_done);
}

static void
keyprint_one(const char *host, struct sshkey *key)
{
 char *hostport = 
                 ((void *)0)
                     , *hashed = 
                                 ((void *)0)
                                     ;
 const char *known_host;

 found_one = 1;

 if (print_sshfp) {
  export_dns_rr(host, key, 
                          stdout
                                , 0);
  return;
 }

 hostport = put_host_port(host, ssh_port);
 lowercase(hostport);
 if (hash_hosts && (hashed = host_hash(hostport, 
                                                ((void *)0)
                                                    , 0)) == 
                                                             ((void *)0)
                                                                 )
  sshfatal("ssh-keyscan.c", __func__, 323, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "host_hash failed");
 known_host = hash_hosts ? hashed : hostport;
 if (!get_cert)
  fprintf(
         stdout
               , "%s ", known_host);
 sshkey_write(key, 
                  stdout
                        );
 fputs("\n", 
            stdout
                  );
 free(hashed);
 free(hostport);
}

static void
keyprint(con *c, struct sshkey *key)
{
 char *hosts = c->c_output_name ? c->c_output_name : c->c_name;
 char *host, *ohosts;

 if (key == 
           ((void *)0)
               )
  return;
 if (get_cert || (!hash_hosts && ssh_port == 22)) {
  keyprint_one(hosts, key);
  return;
 }
 ohosts = hosts = xstrdup(hosts);
 while ((host = strsep(&hosts, ",")) != 
                                       ((void *)0)
                                           )
  keyprint_one(host, key);
 free(ohosts);
}

static int
tcpconnect(char *host)
{
 struct addrinfo hints, *ai, *aitop;
 char strport[
             32
                       ];
 int gaierr, s = -1;

 snprintf(strport, sizeof strport, "%d", ssh_port);
 memset(&hints, 0, sizeof(hints));
 hints.ai_family = IPv4or6;
 hints.ai_socktype = 
                    SOCK_STREAM
                               ;
 if ((gaierr = getaddrinfo(host, strport, &hints, &aitop)) != 0) {
  sshlog("ssh-keyscan.c", __func__, 363, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "getaddrinfo %s: %s", host, ssh_gai_strerror(gaierr));
  return -1;
 }
 for (ai = aitop; ai; ai = ai->ai_next) {
  s = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
  if (s == -1) {
   sshlog("ssh-keyscan.c", __func__, 369, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "socket: %s", strerror(
  (*__errno_location ())
  ));
   continue;
  }
  if (set_nonblock(s) == -1)
   sshfatal("ssh-keyscan.c", __func__, 373, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "set_nonblock(%d)", s);
  if (connect(s, ai->ai_addr, ai->ai_addrlen) == -1 &&
      
     (*__errno_location ()) 
           != 
              115
                         )
   sshlog("ssh-keyscan.c", __func__, 376, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "connect (`%s'): %s", host, strerror(
  (*__errno_location ())
  ));
  else
   break;
  close(s);
  s = -1;
 }
 freeaddrinfo(aitop);
 return s;
}

static int
conalloc(char *iname, char *oname, int keytype)
{
 char *namebase, *name, *namelist;
 int s;

 namebase = namelist = xstrdup(iname);

 do {
  name = xstrsep(&namelist, ",");
  if (!name) {
   free(namebase);
   return (-1);
  }
 } while ((s = tcpconnect(name)) < 0);

 if (s >= maxfd)
  sshfatal("ssh-keyscan.c", __func__, 403, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "conalloc: fdno %d too high", s);
 if (fdcon[s].c_status)
  sshfatal("ssh-keyscan.c", __func__, 405, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "conalloc: attempt to reuse fdno %d", s);

 sshlog("ssh-keyscan.c", __func__, 407, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "oname %s kt %d", oname, keytype);
 fdcon[s].c_fd = s;
 fdcon[s].c_status = 1;
 fdcon[s].c_namebase = namebase;
 fdcon[s].c_name = name;
 fdcon[s].c_namelist = namelist;
 fdcon[s].c_output_name = xstrdup(oname);
 fdcon[s].c_data = (char *) &fdcon[s].c_plen;
 fdcon[s].c_len = 4;
 fdcon[s].c_off = 0;
 fdcon[s].c_keytype = keytype;
 monotime_ts(&fdcon[s].c_ts);
 fdcon[s].c_ts.tv_sec += timeout;
 do { (&fdcon[s])->c_link.tqe_next = 
((void *)0)
; (&fdcon[s])->c_link.tqe_prev = (&tq)->tqh_last; *(&tq)->tqh_last = (&fdcon[s]); (&tq)->tqh_last = &(&fdcon[s])->c_link.tqe_next; } while (0);
 read_wait[s].fd = s;
 read_wait[s].events = 
                      0x001
                            ;
 ncon++;
 return (s);
}

static void
confree(int s)
{
 if (s >= maxfd || fdcon[s].c_status == 0)
  sshfatal("ssh-keyscan.c", __func__, 431, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "confree: attempt to free bad fdno %d", s);
 free(fdcon[s].c_namebase);
 free(fdcon[s].c_output_name);
 if (fdcon[s].c_status == 3)
  free(fdcon[s].c_data);
 fdcon[s].c_status = 0;
 fdcon[s].c_keytype = 0;
 if (fdcon[s].c_ssh) {
  ssh_packet_close(fdcon[s].c_ssh);
  free(fdcon[s].c_ssh);
  fdcon[s].c_ssh = 
                  ((void *)0)
                      ;
 } else
  close(s);
 do { if (((&fdcon[s])->c_link.tqe_next) != 
((void *)0)
) (&fdcon[s])->c_link.tqe_next->c_link.tqe_prev = (&fdcon[s])->c_link.tqe_prev; else (&tq)->tqh_last = (&fdcon[s])->c_link.tqe_prev; *(&fdcon[s])->c_link.tqe_prev = (&fdcon[s])->c_link.tqe_next; ; ; } while (0);
 read_wait[s].fd = -1;
 read_wait[s].events = 0;
 ncon--;
}

static void
contouch(int s)
{
 do { if (((&fdcon[s])->c_link.tqe_next) != 
((void *)0)
) (&fdcon[s])->c_link.tqe_next->c_link.tqe_prev = (&fdcon[s])->c_link.tqe_prev; else (&tq)->tqh_last = (&fdcon[s])->c_link.tqe_prev; *(&fdcon[s])->c_link.tqe_prev = (&fdcon[s])->c_link.tqe_next; ; ; } while (0);
 monotime_ts(&fdcon[s].c_ts);
 fdcon[s].c_ts.tv_sec += timeout;
 do { (&fdcon[s])->c_link.tqe_next = 
((void *)0)
; (&fdcon[s])->c_link.tqe_prev = (&tq)->tqh_last; *(&tq)->tqh_last = (&fdcon[s]); (&tq)->tqh_last = &(&fdcon[s])->c_link.tqe_next; } while (0);
}

static int
conrecycle(int s)
{
 con *c = &fdcon[s];
 int ret;

 ret = conalloc(c->c_namelist, c->c_output_name, c->c_keytype);
 confree(s);
 return (ret);
}

static void
congreet(int s)
{
 int n = 0, remote_major = 0, remote_minor = 0;
 char buf[256], *cp;
 char remote_version[sizeof buf];
 size_t bufsiz;
 con *c = &fdcon[s];


 n = snprintf(buf, sizeof buf, "SSH-%d.%d-OpenSSH-keyscan\r\n",
     2, 0);
 if (n < 0 || (size_t)n >= sizeof(buf)) {
  sshlog("ssh-keyscan.c", __func__, 483, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "snprintf: buffer too small");
  confree(s);
  return;
 }
 if (atomicio((ssize_t (*)(int, void *, size_t))write, s, buf, n) != (size_t)n) {
  sshlog("ssh-keyscan.c", __func__, 488, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "write (%s): %s", c->c_name, strerror(
 (*__errno_location ())
 ));
  confree(s);
  return;
 }
 for (;;) {
  memset(buf, '\0', sizeof(buf));
  bufsiz = sizeof(buf);
  cp = buf;
  while (bufsiz-- &&
      (n = atomicio(read, s, cp, 1)) == 1 && *cp != '\n') {
   if (*cp == '\r')
    *cp = '\n';
   cp++;
  }
  if (n != 1 || strncmp(buf, "SSH-", 4) == 0)
   break;
 }
 if (n == 0) {
  switch (
         (*__errno_location ())
              ) {
  case 
      32
           :
   sshlog("ssh-keyscan.c", __func__, 518, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: Connection closed by remote host", c->c_name);
   break;
  case 
      111
                  :
   break;
  default:
   sshlog("ssh-keyscan.c", __func__, 523, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "read (%s): %s", c->c_name, strerror(
  (*__errno_location ())
  ));
   break;
  }
  conrecycle(s);
  return;
 }
 if (cp >= buf + sizeof(buf)) {
  sshlog("ssh-keyscan.c", __func__, 530, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s: greeting exceeds allowable length", c->c_name);
  confree(s);
  return;
 }
 if (*cp != '\n' && *cp != '\r') {
  sshlog("ssh-keyscan.c", __func__, 535, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s: bad greeting", c->c_name);
  confree(s);
  return;
 }
 *cp = '\0';
 if ((c->c_ssh = ssh_packet_set_connection(
                                          ((void *)0)
                                              , s, s)) == 
                                                          ((void *)0)
                                                              )
  sshfatal("ssh-keyscan.c", __func__, 541, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ssh_packet_set_connection failed");
 ssh_packet_set_timeout(c->c_ssh, timeout, 1);
 ssh_set_app_data(c->c_ssh, c);
 c->c_ssh->compat = 0;
 if (sscanf(buf, "SSH-%d.%d-%[^\n]\n",
     &remote_major, &remote_minor, remote_version) == 3)
  compat_banner(c->c_ssh, remote_version);
 if (!ssh2_capable(remote_major, remote_minor)) {
  sshlog("ssh-keyscan.c", __func__, 549, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%s doesn't support ssh2", c->c_name);
  confree(s);
  return;
 }
 fprintf(
        stderr
              , "%c %s:%d %s\n", print_sshfp ? ';' : '#',
     c->c_name, ssh_port, chop(buf));
 keygrab_ssh2(c);
 confree(s);
}

static void
conread(int s)
{
 con *c = &fdcon[s];
 size_t n;

 if (c->c_status == 1) {
  congreet(s);
  return;
 }
 n = atomicio(read, s, c->c_data + c->c_off, c->c_len - c->c_off);
 if (n == 0) {
  sshlog("ssh-keyscan.c", __func__, 571, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "read (%s): %s", c->c_name, strerror(
 (*__errno_location ())
 ));
  confree(s);
  return;
 }
 c->c_off += n;

 if (c->c_off == c->c_len)
  switch (c->c_status) {
  case 2:
   c->c_plen = htonl(c->c_plen);
   c->c_len = c->c_plen + 8 - (c->c_plen & 7);
   c->c_off = 0;
   c->c_data = xmalloc(c->c_len);
   c->c_status = 3;
   break;
  default:
   sshfatal("ssh-keyscan.c", __func__, 587, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "conread: invalid status %d", c->c_status);
   break;
  }

 contouch(s);
}

static void
conloop(void)
{
 struct timespec seltime, now;
 con *c;
 int i;

 monotime_ts(&now);
 c = ((&tq)->tqh_first);

 if (c && (((&c->c_ts)->tv_sec == (&now)->tv_sec) ? ((&c->c_ts)->tv_nsec > (&now)->tv_nsec) : ((&c->c_ts)->tv_sec > (&now)->tv_sec)))
  do { (&seltime)->tv_sec = (&c->c_ts)->tv_sec - (&now)->tv_sec; (&seltime)->tv_nsec = (&c->c_ts)->tv_nsec - (&now)->tv_nsec; if ((&seltime)->tv_nsec < 0) { (&seltime)->tv_sec--; (&seltime)->tv_nsec += 1000000000L; } } while (0);
 else
  (&seltime)->tv_sec = (&seltime)->tv_nsec = 0;

 while (ppoll(read_wait, maxfd, &seltime, 
                                         ((void *)0)
                                             ) == -1) {
  if (
     (*__errno_location ()) 
           == 
              11 
                     || 
                        (*__errno_location ()) 
                              == 
                                 4 
                                       || 
                                          (*__errno_location ()) 
                                                == 
                                                   11
                                                              )
   continue;
  sshlog("ssh-keyscan.c", __func__, 612, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "poll error");
 }

 for (i = 0; i < maxfd; i++) {
  if (read_wait[i].revents & (
                             0x010
                                    |
                                     0x008
                                            |
                                             0x020
                                                     ))
   confree(i);
  else if (read_wait[i].revents & (
                                  0x001
                                        |
                                         0x010
                                                ))
   conread(i);
 }

 c = ((&tq)->tqh_first);
 while (c && (((&c->c_ts)->tv_sec == (&now)->tv_sec) ? ((&c->c_ts)->tv_nsec < (&now)->tv_nsec) : ((&c->c_ts)->tv_sec < (&now)->tv_sec))) {
  int s = c->c_fd;

  c = ((c)->c_link.tqe_next);
  conrecycle(s);
 }
}

static void
do_host(char *host)
{
 char *name = strnnsep(&host, " \t\n");
 int j;

 if (name == 
            ((void *)0)
                )
  return;
 for (j = (1); j <= (1<<6); j *= 2) {
  if (get_keytypes & j) {
   while (ncon >= (maxfd - 10))
    conloop();
   conalloc(name, *host ? host : name, j);
  }
 }
}

void
sshfatal(const char *file, const char *func, int line, int showfunc,
    LogLevel level, const char *suffix, const char *fmt, ...)
{
 va_list args;

 
__builtin_va_start(
args
,
fmt
)
                   ;
 sshlogv(file, func, line, showfunc, level, suffix, fmt, args);
 
__builtin_va_end(
args
)
            ;
 cleanup_exit(255);
}

static void
usage(void)
{
 fprintf(
        stderr
              ,
     "usage: %s [-46cDHv] [-f file] [-p port] [-T timeout] [-t type]\n"
     "\t\t   [host | addrlist namelist]\n",
     __progname);
 exit(1);
}

int
main(int argc, char **argv)
{
 int debug_flag = 0, log_level = SYSLOG_LEVEL_INFO;
 int opt, fopt_count = 0, j;
 char *tname, *cp, *line = 
                          ((void *)0)
                              ;
 size_t linesize = 0;
 FILE *fp;

 extern int BSDoptind;
 extern char *BSDoptarg;

 __progname = ssh_get_progname(argv[0]);
 seed_rng();
 do { (&tq)->tqh_first = 
((void *)0)
; (&tq)->tqh_last = &(&tq)->tqh_first; } while (0);


 sanitise_stdfd();

 if (argc <= 1)
  usage();

 while ((opt = BSDgetopt(argc, argv, "cDHv46p:T:t:f:")) != -1) {
  switch (opt) {
  case 'H':
   hash_hosts = 1;
   break;
  case 'c':
   get_cert = 1;
   break;
  case 'D':
   print_sshfp = 1;
   break;
  case 'p':
   ssh_port = a2port(BSDoptarg);
   if (ssh_port <= 0) {
    fprintf(
           stderr
                 , "Bad port '%s'\n", BSDoptarg);
    exit(1);
   }
   break;
  case 'T':
   timeout = convtime(BSDoptarg);
   if (timeout == -1 || timeout == 0) {
    fprintf(
           stderr
                 , "Bad timeout '%s'\n", BSDoptarg);
    usage();
   }
   break;
  case 'v':
   if (!debug_flag) {
    debug_flag = 1;
    log_level = SYSLOG_LEVEL_DEBUG1;
   }
   else if (log_level < SYSLOG_LEVEL_DEBUG3)
    log_level++;
   else
    sshfatal("ssh-keyscan.c", __func__, 725, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Too high debugging level.");
   break;
  case 'f':
   if (strcmp(BSDoptarg, "-") == 0)
    BSDoptarg = 
            ((void *)0)
                ;
   argv[fopt_count++] = BSDoptarg;
   break;
  case 't':
   get_keytypes = 0;
   tname = strtok(BSDoptarg, ",");
   while (tname) {
    int type = sshkey_type_from_name(tname);

    switch (type) {
    case KEY_DSA:
     get_keytypes |= (1);
     break;
    case KEY_ECDSA:
     get_keytypes |= (1<<2);
     break;
    case KEY_RSA:
     get_keytypes |= (1<<1);
     break;
    case KEY_ED25519:
     get_keytypes |= (1<<3);
     break;
    case KEY_XMSS:
     get_keytypes |= (1<<4);
     break;
    case KEY_ED25519_SK:
     get_keytypes |= (1<<6);
     break;
    case KEY_ECDSA_SK:
     get_keytypes |= (1<<5);
     break;
    case KEY_UNSPEC:
    default:
     sshfatal("ssh-keyscan.c", __func__, 762, 0, SYSLOG_LEVEL_FATAL, 
    ((void *)0)
    , "Unknown key type \"%s\"", tname);
    }
    tname = strtok(
                  ((void *)0)
                      , ",");
   }
   break;
  case '4':
   IPv4or6 = 
            2
                   ;
   break;
  case '6':
   IPv4or6 = 
            10
                    ;
   break;
  case '?':
  default:
   usage();
  }
 }
 if (BSDoptind == argc && !fopt_count)
  usage();

 log_init("ssh-keyscan", log_level, SYSLOG_FACILITY_USER, 1);

 maxfd = fdlim_get(1);
 if (maxfd < 0)
  sshfatal("ssh-keyscan.c", __func__, 785, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: fdlim_get: bad value", __progname);
 if (maxfd > 256)
  maxfd = 256;
 if ((maxfd - 10) <= 0)
  sshfatal("ssh-keyscan.c", __func__, 789, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: not enough file descriptors", __progname);
 if (maxfd > fdlim_get(0))
  fdlim_set(maxfd);
 fdcon = xcalloc(maxfd, sizeof(con));
 read_wait = xcalloc(maxfd, sizeof(struct pollfd));
 for (j = 0; j < maxfd; j++)
  read_wait[j].fd = -1;

 for (j = 0; j < fopt_count; j++) {
  if (argv[j] == 
                ((void *)0)
                    )
   fp = 
       stdin
            ;
  else if ((fp = fopen(argv[j], "r")) == 
                                        ((void *)0)
                                            )
   sshfatal("ssh-keyscan.c", __func__, 801, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s: %s: %s", __progname, argv[j], strerror(
  (*__errno_location ())
  ));

  while (getline(&line, &linesize, fp) != -1) {

   if ((cp = strchr(line, '#')) == 
                                  ((void *)0)
                                      )
    cp = line + strlen(line) - 1;
   while (cp >= line) {
    if (*cp == ' ' || *cp == '\t' ||
        *cp == '\n' || *cp == '#')
     *cp-- = '\0';
    else
     break;
   }


   if (*line == '\0')
    continue;

   do_host(line);
  }

  if (ferror(fp))
   sshfatal("ssh-keyscan.c", __func__, 823, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s: %s: %s", __progname, argv[j], strerror(
  (*__errno_location ())
  ));

  fclose(fp);
 }
 free(line);

 while (BSDoptind < argc)
  do_host(argv[BSDoptind++]);

 while (ncon > 0)
  conloop();

 return found_one ? 0 : 1;
}
