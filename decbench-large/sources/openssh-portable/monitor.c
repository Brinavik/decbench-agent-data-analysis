











































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
void *xmalloc(size_t);
void *xcalloc(size_t, size_t);
void *xreallocarray(void *, size_t, size_t);
void *xrecallocarray(void *, size_t, size_t, size_t);
char *xstrdup(const char *);
int xasprintf(char **, const char *, ...)
    __attribute__((__format__ (printf, 2, 3))) __attribute__((__nonnull__ (2)));
int xvasprintf(char **, const char *, va_list)
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
struct passwd;
struct ssh;
struct sshbuf;
struct sshkey;
struct sshkey_cert;
struct sshauthopt;

typedef struct Authctxt Authctxt;
typedef struct Authmethod Authmethod;
typedef struct KbdintDevice KbdintDevice;

struct Authctxt {
 sig_atomic_t success;
 int authenticated;
 int postponed;
 int valid;
 int attempt;
 int failures;
 int server_caused_failure;
 int force_pwchange;
 char *user;
 char *service;
 struct passwd *pw;
 char *style;


 char **auth_methods;
 u_int num_auth_methods;


 void *methoddata;
 void *kbdintctxt;
 struct sshbuf *loginmsg;


 struct sshkey **prev_keys;
 u_int nprev_keys;


 struct sshkey *auth_method_key;
 char *auth_method_info;


 struct sshbuf *session_info;
};
struct Authmethod {
 char *name;
 char *synonym;
 int (*userauth)(struct ssh *, const char *);
 int *enabled;
};
struct KbdintDevice
{
 const char *name;
 void* (*init_ctx)(Authctxt*);
 int (*query)(void *ctx, char **name, char **infotxt,
      u_int *numprompts, char ***prompts, u_int **echo_on);
 int (*respond)(void *ctx, u_int numresp, char **responses);
 void (*free_ctx)(void *ctx);
};

int
auth_rhosts2(struct passwd *, const char *, const char *, const char *);

int auth_password(struct ssh *, const char *);

int hostbased_key_allowed(struct ssh *, struct passwd *,
     const char *, char *, struct sshkey *);
int user_key_allowed(struct ssh *ssh, struct passwd *, struct sshkey *,
    int, struct sshauthopt **);
int auth2_key_already_used(Authctxt *, const struct sshkey *);





void auth2_authctxt_reset_info(Authctxt *);
void auth2_record_key(Authctxt *, int, const struct sshkey *);
void auth2_record_info(Authctxt *authctxt, const char *, ...)
     __attribute__((__format__ (printf, 2, 3)))
     __attribute__((__nonnull__ (2)));
void auth2_update_session_info(Authctxt *, const char *, const char *);

int auth_shadow_acctexpired(struct spwd *);
int auth_shadow_pwexpired(Authctxt *);


struct ssh;
union login_netinfo {
 struct sockaddr sa;
 struct sockaddr_in sa_in;
 struct sockaddr_storage sa_storage;
};
struct logininfo {
 char progname[64];
 int progname_null;
 short int type;
 pid_t pid;
 uid_t uid;
 char line[64];
 char username[512];
 char hostname[256];

 int exit;
 int termination;



 unsigned int tv_sec;
 unsigned int tv_usec;
 union login_netinfo hostaddr;
};
struct logininfo *login_alloc_entry(pid_t pid, const char *username,
        const char *hostname, const char *line);

void login_free_entry(struct logininfo *li);

int login_init_entry(struct logininfo *li, pid_t pid, const char *username,
    const char *hostname, const char *line);

void login_set_current_time(struct logininfo *li);


int login_login (struct logininfo *li);
int login_logout(struct logininfo *li);







int login_write (struct logininfo *li);
int login_log_entry(struct logininfo *li);


void login_set_addr(struct logininfo *li, const struct sockaddr *sa,
      const unsigned int sa_size);





struct logininfo *login_get_lastlog(struct logininfo *li, const uid_t uid);

unsigned int login_get_lastlog_time(const uid_t uid);


char *line_fullname(char *dst, const char *src, u_int dstsize);
char *line_stripname(char *dst, const char *src, int dstsize);
char *line_abbrevname(char *dst, const char *src, int dstsize);

void record_failed_login(struct ssh *, const char *, const char *,
    const char *);

struct ssh;

enum ssh_audit_event_type {
 SSH_LOGIN_EXCEED_MAXTRIES,
 SSH_LOGIN_ROOT_DENIED,
 SSH_AUTH_SUCCESS,
 SSH_AUTH_FAIL_NONE,
 SSH_AUTH_FAIL_PASSWD,
 SSH_AUTH_FAIL_KBDINT,
 SSH_AUTH_FAIL_PUBKEY,
 SSH_AUTH_FAIL_HOSTBASED,
 SSH_AUTH_FAIL_GSSAPI,
 SSH_INVALID_USER,
 SSH_NOLOGIN,
 SSH_CONNECTION_CLOSE,
 SSH_CONNECTION_ABANDON,
 SSH_AUDIT_UNKNOWN
};
typedef enum ssh_audit_event_type ssh_audit_event_t;

void audit_connection_from(const char *, int);
void audit_event(struct ssh *, ssh_audit_event_t);
void audit_session_open(struct logininfo *);
void audit_session_close(struct logininfo *);
void audit_run_command(const char *);
ssh_audit_event_t audit_classify_auth(const char *);
void remove_kbdint_device(const char *);

void do_authentication2(struct ssh *);

void auth_log(struct ssh *, int, int, const char *, const char *);
void auth_maxtries_exceeded(struct ssh *) __attribute__((noreturn));
void userauth_finish(struct ssh *, int, const char *, const char *);
int auth_root_allowed(struct ssh *, const char *);

char *auth2_read_banner(void);
int auth2_methods_valid(const char *, int);
int auth2_update_methods_lists(Authctxt *, const char *, const char *);
int auth2_setup_methods_lists(Authctxt *);
int auth2_method_allowed(Authctxt *, const char *, const char *);

void privsep_challenge_enable(void);

int auth2_challenge(struct ssh *, char *);
void auth2_challenge_stop(struct ssh *);
int bsdauth_query(void *, char **, char **, u_int *, char ***, u_int **);
int bsdauth_respond(void *, u_int, char **);

int allowed_user(struct ssh *, struct passwd *);
struct passwd * getpwnamallow(struct ssh *, const char *user);

char *expand_authorized_keys(const char *, struct passwd *pw);
char *authorized_principals_file(struct passwd *);

int auth_key_is_revoked(struct sshkey *);

const char *auth_get_canonical_hostname(struct ssh *, int);

HostStatus
check_key_in_hostfiles(struct passwd *, struct sshkey *, const char *,
    const char *, const char *);


struct sshkey *get_hostkey_by_index(int);
struct sshkey *get_hostkey_public_by_index(int, struct ssh *);
struct sshkey *get_hostkey_public_by_type(int, int, struct ssh *);
struct sshkey *get_hostkey_private_by_type(int, int, struct ssh *);
int get_hostkey_index(struct sshkey *, int, struct ssh *);
int sshd_hostkey_sign(struct ssh *, struct sshkey *, struct sshkey *,
    u_char **, size_t *, const u_char *, size_t, const char *);


const struct sshauthopt *auth_options(struct ssh *);
int auth_activate_options(struct ssh *, struct sshauthopt *);
void auth_restrict_session(struct ssh *);
void auth_log_authopts(const char *, const struct sshauthopt *, int);


void auth_debug_add(const char *fmt,...)
    __attribute__((format(printf, 1, 2)));
void auth_debug_send(struct ssh *);
void auth_debug_reset(void);

struct passwd *fakepw(void);


int auth_authorise_keyopts(struct passwd *, struct sshauthopt *, int,
    const char *, const char *, const char *);
int auth_check_principals_line(char *, const struct sshkey_cert *,
    const char *, struct sshauthopt **);
int auth_process_principals(FILE *, const char *,
    const struct sshkey_cert *, struct sshauthopt **);
int auth_check_authkey_line(struct passwd *, struct sshkey *,
    char *, const char *, const char *, const char *, struct sshauthopt **);
int auth_check_authkeys_file(struct passwd *, FILE *, char *,
    struct sshkey *, const char *, const char *, struct sshauthopt **);
FILE *auth_openkeyfile(const char *, struct passwd *, int);
FILE *auth_openprincipals(const char *, struct passwd *, int);

int sys_auth_passwd(struct ssh *, const char *);
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
struct passwd;
struct sshkey;
struct sshauthopt {

 int permit_port_forwarding_flag;
 int permit_agent_forwarding_flag;
 int permit_x11_forwarding_flag;
 int permit_pty_flag;
 int permit_user_rc;


 int restricted;


 uint64_t valid_before;


 int cert_authority;
 char *cert_principals;

 int force_tun_device;
 char *force_command;


 size_t nenv;
 char **env;


 size_t npermitopen;
 char **permitopen;


 size_t npermitlisten;
 char **permitlisten;





 char *required_from_host_cert;
 char *required_from_host_keys;


 int no_require_user_presence;

 int require_verify;
};

struct sshauthopt *sshauthopt_new(void);
struct sshauthopt *sshauthopt_new_with_keys_defaults(void);
void sshauthopt_free(struct sshauthopt *opts);
struct sshauthopt *sshauthopt_copy(const struct sshauthopt *orig);
int sshauthopt_serialise(const struct sshauthopt *opts, struct sshbuf *m, int);
int sshauthopt_deserialise(struct sshbuf *m, struct sshauthopt **opts);





struct sshauthopt *sshauthopt_parse(const char *s, const char **errstr);





struct sshauthopt *sshauthopt_from_cert(struct sshkey *k);




struct sshauthopt *sshauthopt_merge(const struct sshauthopt *primary,
    const struct sshauthopt *additional, const char **errstrp);
struct termios *get_saved_tio(void);
void leave_raw_mode(int);
void enter_raw_mode(int);

int pty_allocate(int *, int *, char *, size_t);
void pty_release(const char *);
void pty_make_controlling_tty(int *, const char *);
void pty_change_window_size(int, u_int, u_int, u_int, u_int);
void pty_setowner(struct passwd *, const char *);
void disconnect_controlling_tty(void);
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
typedef struct Session Session;
struct Session {
 int used;
 int self;
 int next_unused;
 struct passwd *pw;
 Authctxt *authctxt;
 pid_t pid;
 int forced;


 char *term;
 int ptyfd, ttyfd, ptymaster;
 u_int row, col, xpixel, ypixel;
 char tty[64];


 u_int display_number;
 char *display;
 u_int screen;
 char *auth_display;
 char *auth_proto;
 char *auth_data;
 int single_connection;

 int chanid;
 int *x11_chanids;
 int is_subsystem;
 char *subsys;
 u_int num_env;
 struct {
  char *name;
  char *val;
 } *env;
};

void do_authenticated(struct ssh *, Authctxt *);
void do_cleanup(struct ssh *, Authctxt *);

int session_open(Authctxt *, int);
void session_unused(int);
int session_input_channel_req(struct ssh *, Channel *, const char *);
void session_close_by_pid(struct ssh *ssh, pid_t, int);
void session_close_by_channel(struct ssh *, int, void *);
void session_destroy_all(struct ssh *, void (*)(Session *));
void session_pty_cleanup2(Session *);

Session *session_new(void);
Session *session_by_tty(char *);
void session_close(struct ssh *, Session *);
void do_setusercontext(struct passwd *);

const char *session_get_remote_name_or_ip(struct ssh *, u_int, int);
void record_login(pid_t, const char *, const char *, uid_t,
    const char *, struct sockaddr *, socklen_t);
void record_logout(pid_t, const char *, const char *);
time_t get_last_login_time(uid_t, const char *, char *, size_t);
char *get_peer_ipaddr(int);
int get_peer_port(int);
char *get_local_ipaddr(int);
char *get_local_name(int);
int get_local_port(int);



void ipv64_normalise_mapped(struct sockaddr_storage *, socklen_t *);
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
struct ssh;
struct fwd_perm_list;






struct queued_listenaddr {
 char *addr;
 int port;
 char *rdomain;
};


struct listenaddr {
 char *rdomain;
 struct addrinfo *addrs;
};

typedef struct {
 u_int num_ports;
 u_int ports_from_cmdline;
 int ports[256];
 struct queued_listenaddr *queued_listen_addrs;
 u_int num_queued_listens;
 struct listenaddr *listen_addrs;
 u_int num_listen_addrs;
 int address_family;

 char *routing_domain;

 char **host_key_files;
 int *host_key_file_userprovided;
 u_int num_host_key_files;
 char **host_cert_files;
 u_int num_host_cert_files;

 char *host_key_agent;
 char *pid_file;
 char *moduli_file;
 int login_grace_time;

 int permit_root_login;
 int ignore_rhosts;
 int ignore_user_known_hosts;

 int print_motd;
 int print_lastlog;
 int x11_forwarding;
 int x11_display_offset;

 int x11_use_localhost;
 char *xauth_location;
 int permit_tty;
 int permit_user_rc;
 int strict_modes;
 int tcp_keep_alive;
 int ip_qos_interactive;
 int ip_qos_bulk;
 char *ciphers;
 char *macs;
 char *kex_algorithms;
 struct ForwardOptions fwd_opts;
 SyslogFacility log_facility;
 LogLevel log_level;
 u_int num_log_verbose;
 char **log_verbose;
 int hostbased_authentication;
 int hostbased_uses_name_from_packet_only;
 char *hostbased_accepted_algos;
 char *hostkeyalgorithms;
 char *ca_sign_algorithms;
 int pubkey_authentication;
 char *pubkey_accepted_algos;
 int pubkey_auth_options;
 int kerberos_authentication;

 int kerberos_or_local_passwd;




 int kerberos_ticket_cleanup;

 int kerberos_get_afs_token;

 int gss_authentication;
 int gss_cleanup_creds;
 int gss_strict_acceptor;
 int password_authentication;

 int kbd_interactive_authentication;
 int permit_empty_passwd;

 int permit_user_env;
 char *permit_user_env_allowlist;
 int compression;
 int allow_tcp_forwarding;
 int allow_streamlocal_forwarding;
 int allow_agent_forwarding;
 int disable_forwarding;
 u_int num_allow_users;
 char **allow_users;
 u_int num_deny_users;
 char **deny_users;
 u_int num_allow_groups;
 char **allow_groups;
 u_int num_deny_groups;
 char **deny_groups;

 u_int num_subsystems;
 char *subsystem_name[256];
 char *subsystem_command[256];
 char *subsystem_args[256];

 u_int num_accept_env;
 char **accept_env;
 u_int num_setenv;
 char **setenv;

 int max_startups_begin;
 int max_startups_rate;
 int max_startups;
 int per_source_max_startups;
 int per_source_masklen_ipv4;
 int per_source_masklen_ipv6;
 int max_authtries;
 int max_sessions;
 char *banner;
 int use_dns;
 int client_alive_interval;



 int client_alive_count_max;





 u_int num_authkeys_files;
 char **authorized_keys_files;

 char *adm_forced_command;

 int use_pam;

 int permit_tun;

 char **permitted_opens;
 u_int num_permitted_opens;
 char **permitted_listens;
 u_int num_permitted_listens;

 char *chroot_directory;
 char *revoked_keys_file;
 char *trusted_user_ca_keys;
 char *authorized_keys_command;
 char *authorized_keys_command_user;
 char *authorized_principals_file;
 char *authorized_principals_command;
 char *authorized_principals_command_user;

 int64_t rekey_limit;
 int rekey_interval;

 char *version_addendum;

 u_int num_auth_methods;
 char **auth_methods;

 int fingerprint_hash;
 int expose_userauth_info;
 u_int64_t timing_secret;
 char *sk_provider;
 int required_rsa_size;
} ServerOptions;


struct connection_info {
 const char *user;
 const char *host;
 const char *address;
 const char *laddress;
 int lport;
 const char *rdomain;
 int test;

};


struct include_item {
 char *selector;
 char *filename;
 struct sshbuf *contents;
 struct { struct include_item *tqe_next; struct include_item **tqe_prev; } entry;
};
struct include_list { struct include_item *tqh_first; struct include_item **tqh_last; };
struct connection_info *get_connection_info(struct ssh *, int, int);
void initialize_server_options(ServerOptions *);
void fill_default_server_options(ServerOptions *);
int process_server_config_line(ServerOptions *, char *, const char *, int,
     int *, struct connection_info *, struct include_list *includes);
void process_permitopen(struct ssh *ssh, ServerOptions *options);
void load_server_config(const char *, struct sshbuf *);
void parse_server_config(ServerOptions *, const char *, struct sshbuf *,
     struct include_list *includes, struct connection_info *, int);
void parse_server_match_config(ServerOptions *,
     struct include_list *includes, struct connection_info *);
int parse_server_match_testspec(struct connection_info *, char *);
int server_match_spec_complete(struct connection_info *);
void copy_set_server_options(ServerOptions *, ServerOptions *, int);
void dump_config(ServerOptions *);
char *derelativise_path(const char *);
void servconf_add_hostkey(const char *, const int,
     ServerOptions *, const char *path, int);
void servconf_add_hostcert(const char *, const int,
     ServerOptions *, const char *path);
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



extern int use_privsep;


enum mm_keytype { MM_NOKEY, MM_HOSTKEY, MM_USERKEY };

struct ssh;
struct monitor;
struct Authctxt;
struct sshkey;
struct sshauthopt;
struct sshkey_sig_details;

void mm_log_handler(LogLevel, int, const char *, void *);
int mm_is_monitor(void);

DH *mm_choose_dh(int, int, int);

int mm_sshkey_sign(struct ssh *, struct sshkey *, u_char **, size_t *,
    const u_char *, size_t, const char *, const char *,
    const char *, u_int compat);
void mm_inform_authserv(char *, char *);
struct passwd *mm_getpwnamallow(struct ssh *, const char *);
char *mm_auth2_read_banner(void);
int mm_auth_password(struct ssh *, char *);
int mm_key_allowed(enum mm_keytype, const char *, const char *, struct sshkey *,
    int, struct sshauthopt **);
int mm_user_key_allowed(struct ssh *ssh, struct passwd *, struct sshkey *, int,
    struct sshauthopt **);
int mm_hostbased_key_allowed(struct ssh *, struct passwd *, const char *,
    const char *, struct sshkey *);
int mm_sshkey_verify(const struct sshkey *, const u_char *, size_t,
    const u_char *, size_t, const char *, u_int, struct sshkey_sig_details **);
struct Session;
void mm_terminate(void);
int mm_pty_allocate(int *, int *, char *, size_t);
void mm_session_pty_cleanup2(struct Session *);


struct newkeys *mm_newkeys_from_blob(u_char *, int);
int mm_newkeys_to_blob(int, u_char **, u_int *);

void mm_send_keystate(struct ssh *, struct monitor*);


int mm_bsdauth_query(void *, char **, char **, u_int *, char ***, u_int **);
int mm_bsdauth_respond(void *, u_int, char **);
int mm_send_fd(int, int);
int mm_receive_fd(int);
struct ssh;

void compat_banner(struct ssh *, const char *);
char *compat_cipher_proposal(struct ssh *, char *);
char *compat_pkalg_proposal(struct ssh *, char *);
char *compat_kex_proposal(struct ssh *, char *);
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






extern ServerOptions options;
extern u_int utmp_len;
extern struct sshbuf *loginmsg;
extern struct sshauthopt *auth_opts;


static struct sshbuf *child_state;



int mm_answer_moduli(struct ssh *, int, struct sshbuf *);
int mm_answer_sign(struct ssh *, int, struct sshbuf *);
int mm_answer_pwnamallow(struct ssh *, int, struct sshbuf *);
int mm_answer_auth2_read_banner(struct ssh *, int, struct sshbuf *);
int mm_answer_authserv(struct ssh *, int, struct sshbuf *);
int mm_answer_authpassword(struct ssh *, int, struct sshbuf *);
int mm_answer_bsdauthquery(struct ssh *, int, struct sshbuf *);
int mm_answer_bsdauthrespond(struct ssh *, int, struct sshbuf *);
int mm_answer_keyallowed(struct ssh *, int, struct sshbuf *);
int mm_answer_keyverify(struct ssh *, int, struct sshbuf *);
int mm_answer_pty(struct ssh *, int, struct sshbuf *);
int mm_answer_pty_cleanup(struct ssh *, int, struct sshbuf *);
int mm_answer_term(struct ssh *, int, struct sshbuf *);
int mm_answer_rsa_keyallowed(struct ssh *, int, struct sshbuf *);
int mm_answer_rsa_challenge(struct ssh *, int, struct sshbuf *);
int mm_answer_rsa_response(struct ssh *, int, struct sshbuf *);
int mm_answer_sesskey(struct ssh *, int, struct sshbuf *);
int mm_answer_sessid(struct ssh *, int, struct sshbuf *);
static Authctxt *authctxt;


static u_char *key_blob = 
                         ((void *)0)
                             ;
static size_t key_bloblen = 0;
static u_int key_blobtype = MM_NOKEY;
static struct sshauthopt *key_opts = 
                                    ((void *)0)
                                        ;
static char *hostbased_cuser = 
                              ((void *)0)
                                  ;
static char *hostbased_chost = 
                              ((void *)0)
                                  ;
static char *auth_method = "unknown";
static char *auth_submethod = 
                             ((void *)0)
                                 ;
static u_int session_id2_len = 0;
static u_char *session_id2 = 
                            ((void *)0)
                                ;
static pid_t monitor_child_pid;

struct mon_table {
 enum monitor_reqtype type;
 int flags;
 int (*f)(struct ssh *, int, struct sshbuf *);
};
static int monitor_read(struct ssh *, struct monitor *, struct mon_table *,
    struct mon_table **);
static int monitor_read_log(struct monitor *);

struct mon_table mon_dispatch_proto20[] = {

    {MONITOR_REQ_MODULI, 0x0010, mm_answer_moduli},

    {MONITOR_REQ_SIGN, 0x0010, mm_answer_sign},
    {MONITOR_REQ_PWNAM, 0x0010, mm_answer_pwnamallow},
    {MONITOR_REQ_AUTHSERV, 0x0010, mm_answer_authserv},
    {MONITOR_REQ_AUTH2_READ_BANNER, 0x0010, mm_answer_auth2_read_banner},
    {MONITOR_REQ_AUTHPASSWORD, (0x0004|0x0008), mm_answer_authpassword},
    {MONITOR_REQ_KEYALLOWED, 0x0004, mm_answer_keyallowed},
    {MONITOR_REQ_KEYVERIFY, (0x0004|0x0008), mm_answer_keyverify},






    {0, 0, 
          ((void *)0)
              }
};

struct mon_table mon_dispatch_postauth20[] = {

    {MONITOR_REQ_MODULI, 0, mm_answer_moduli},

    {MONITOR_REQ_SIGN, 0, mm_answer_sign},
    {MONITOR_REQ_PTY, 0, mm_answer_pty},
    {MONITOR_REQ_PTYCLEANUP, 0, mm_answer_pty_cleanup},
    {MONITOR_REQ_TERM, 0, mm_answer_term},




    {0, 0, 
          ((void *)0)
              }
};

struct mon_table *mon_dispatch;


static void
monitor_permit(struct mon_table *ent, enum monitor_reqtype type, int permit)
{
 while (ent->f != 
                 ((void *)0)
                     ) {
  if (ent->type == type) {
   ent->flags &= ~0x1000;
   ent->flags |= permit ? 0x1000 : 0;
   return;
  }
  ent++;
 }
}

static void
monitor_permit_authentications(int permit)
{
 struct mon_table *ent = mon_dispatch;

 while (ent->f != 
                 ((void *)0)
                     ) {
  if (ent->flags & (0x0004|0x0008)) {
   ent->flags &= ~0x1000;
   ent->flags |= permit ? 0x1000 : 0;
  }
  ent++;
 }
}

void
monitor_child_preauth(struct ssh *ssh, struct monitor *pmonitor)
{
 struct mon_table *ent;
 int authenticated = 0, partial = 0;

 sshlog("monitor.c", __func__, 275, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "preauth child monitor started");

 if (pmonitor->m_recvfd >= 0)
  close(pmonitor->m_recvfd);
 if (pmonitor->m_log_sendfd >= 0)
  close(pmonitor->m_log_sendfd);
 pmonitor->m_log_sendfd = pmonitor->m_recvfd = -1;

 authctxt = (Authctxt *)ssh->authctxt;
 memset(authctxt, 0, sizeof(*authctxt));
 ssh->authctxt = authctxt;

 authctxt->loginmsg = loginmsg;

 mon_dispatch = mon_dispatch_proto20;

 monitor_permit(mon_dispatch, MONITOR_REQ_MODULI, 1);
 monitor_permit(mon_dispatch, MONITOR_REQ_SIGN, 1);


 while (!authenticated) {
  partial = 0;
  auth_method = "unknown";
  auth_submethod = 
                  ((void *)0)
                      ;
  auth2_authctxt_reset_info(authctxt);

  authenticated = (monitor_read(ssh, pmonitor,
      mon_dispatch, &ent) == 1);


  if (options.num_auth_methods != 0) {
   if (authenticated &&
       !auth2_update_methods_lists(authctxt,
       auth_method, auth_submethod)) {
    sshlog("monitor.c", __func__, 309, 1, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "method %s: partial", auth_method);
    authenticated = 0;
    partial = 1;
   }
  }

  if (authenticated) {
   if (!(ent->flags & 0x0008))
    sshfatal("monitor.c", __func__, 317, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "unexpected authentication from %d", ent->type)
                  ;
   if (authctxt->pw->pw_uid == 0 &&
       !auth_root_allowed(ssh, auth_method))
    authenticated = 0;
  }
  if (ent->flags & (0x0008|0x0020)) {
   auth_log(ssh, authenticated, partial,
       auth_method, auth_submethod);
   if (!partial && !authenticated)
    authctxt->failures++;
   if (authenticated || partial) {
    auth2_update_session_info(authctxt,
        auth_method, auth_submethod);
   }
  }
 }

 if (!authctxt->valid)
  sshfatal("monitor.c", __func__, 351, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "authenticated invalid user");
 if (strcmp(auth_method, "unknown") == 0)
  sshfatal("monitor.c", __func__, 353, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "authentication method name unknown");

 sshlog("monitor.c", __func__, 355, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "user %s authenticated by privileged process", authctxt->user);
 ssh->authctxt = 
                ((void *)0)
                    ;
 ssh_packet_set_log_preamble(ssh, "user %s", authctxt->user);

 mm_get_keystate(ssh, pmonitor);


 while (pmonitor->m_log_recvfd != -1 && monitor_read_log(pmonitor) == 0)
  ;

 if (pmonitor->m_recvfd >= 0)
  close(pmonitor->m_recvfd);
 if (pmonitor->m_log_sendfd >= 0)
  close(pmonitor->m_log_sendfd);
 pmonitor->m_sendfd = pmonitor->m_log_recvfd = -1;
}

static void
monitor_set_child_handler(pid_t pid)
{
 monitor_child_pid = pid;
}

static void
monitor_child_handler(int sig)
{
 kill(monitor_child_pid, sig);
}

void
monitor_child_postauth(struct ssh *ssh, struct monitor *pmonitor)
{
 close(pmonitor->m_recvfd);
 pmonitor->m_recvfd = -1;

 monitor_set_child_handler(pmonitor->m_pid);
 ssh_signal(
           1
                 , &monitor_child_handler);
 ssh_signal(
           15
                  , &monitor_child_handler);
 ssh_signal(
           2
                 , &monitor_child_handler);

 ssh_signal(
           25
                  , 
                    ((__sighandler_t) 1)
                           );


 mon_dispatch = mon_dispatch_postauth20;


 monitor_permit(mon_dispatch, MONITOR_REQ_MODULI, 1);
 monitor_permit(mon_dispatch, MONITOR_REQ_SIGN, 1);
 monitor_permit(mon_dispatch, MONITOR_REQ_TERM, 1);

 if (auth_opts->permit_pty_flag) {
  monitor_permit(mon_dispatch, MONITOR_REQ_PTY, 1);
  monitor_permit(mon_dispatch, MONITOR_REQ_PTYCLEANUP, 1);
 }

 for (;;)
  monitor_read(ssh, pmonitor, mon_dispatch, 
                                           ((void *)0)
                                               );
}

static int
monitor_read_log(struct monitor *pmonitor)
{
 struct sshbuf *logmsg;
 u_int len, level, forced;
 char *msg;
 u_char *p;
 int r;

 if ((logmsg = sshbuf_new()) == 
                               ((void *)0)
                                   )
  sshfatal("monitor.c", __func__, 424, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");


 if ((r = sshbuf_reserve(logmsg, 4, &p)) != 0)
  sshfatal("monitor.c", __func__, 428, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reserve len");
 if (atomicio(read, pmonitor->m_log_recvfd, p, 4) != 4) {
  if (
     (*__errno_location ()) 
           == 
              32
                   ) {
   sshbuf_free(logmsg);
   sshlog("monitor.c", __func__, 432, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "child log fd closed");
   close(pmonitor->m_log_recvfd);
   pmonitor->m_log_recvfd = -1;
   return -1;
  }
  sshfatal("monitor.c", __func__, 437, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "log fd read: %s", strerror(
 (*__errno_location ())
 ));
 }
 if ((r = sshbuf_get_u32(logmsg, &len)) != 0)
  sshfatal("monitor.c", __func__, 440, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse len");
 if (len <= 4 || len > 8192)
  sshfatal("monitor.c", __func__, 442, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "invalid log message length %u", len);


 sshbuf_reset(logmsg);
 if ((r = sshbuf_reserve(logmsg, len, &p)) != 0)
  sshfatal("monitor.c", __func__, 447, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reserve msg");
 if (atomicio(read, pmonitor->m_log_recvfd, p, len) != len)
  sshfatal("monitor.c", __func__, 449, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "log fd read: %s", strerror(
 (*__errno_location ())
 ));
 if ((r = sshbuf_get_u32(logmsg, &level)) != 0 ||
     (r = sshbuf_get_u32(logmsg, &forced)) != 0 ||
     (r = sshbuf_get_cstring(logmsg, &msg, 
                                          ((void *)0)
                                              )) != 0)
  sshfatal("monitor.c", __func__, 453, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");


 if (log_level_name(level) == 
                             ((void *)0)
                                 )
  sshfatal("monitor.c", __func__, 457, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "invalid log level %u (corrupted message?)", level);
 sshlogdirect(level, forced, "%s [preauth]", msg);

 sshbuf_free(logmsg);
 free(msg);

 return 0;
}

static int
monitor_read(struct ssh *ssh, struct monitor *pmonitor, struct mon_table *ent,
    struct mon_table **pent)
{
 struct sshbuf *m;
 int r, ret;
 u_char type;
 struct pollfd pfd[2];

 for (;;) {
  memset(&pfd, 0, sizeof(pfd));
  pfd[0].fd = pmonitor->m_sendfd;
  pfd[0].events = 
                 0x001
                       ;
  pfd[1].fd = pmonitor->m_log_recvfd;
  pfd[1].events = pfd[1].fd == -1 ? 0 : 
                                       0x001
                                             ;
  if (poll(pfd, pfd[1].fd == -1 ? 1 : 2, -1) == -1) {
   if (
      (*__errno_location ()) 
            == 
               4 
                     || 
                        (*__errno_location ()) 
                              == 
                                 11
                                       )
    continue;
   sshfatal("monitor.c", __func__, 484, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "poll: %s", strerror(
  (*__errno_location ())
  ));
  }
  if (pfd[1].revents) {




   monitor_read_log(pmonitor);
   continue;
  }
  if (pfd[0].revents)
   break;
 }

 if ((m = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("monitor.c", __func__, 499, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");

 mm_request_receive(pmonitor->m_sendfd, m);
 if ((r = sshbuf_get_u8(m, &type)) != 0)
  sshfatal("monitor.c", __func__, 503, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse type");

 sshlog("monitor.c", __func__, 505, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "checking request %d", type);

 while (ent->f != 
                 ((void *)0)
                     ) {
  if (ent->type == type)
   break;
  ent++;
 }

 if (ent->f != 
              ((void *)0)
                  ) {
  if (!(ent->flags & 0x1000))
   sshfatal("monitor.c", __func__, 515, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "unpermitted request %d", type);
  ret = (*ent->f)(ssh, pmonitor->m_sendfd, m);
  sshbuf_free(m);


  if (ent->flags & 0x0010) {
   sshlog("monitor.c", __func__, 521, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "%d used once, disabling now", type);
   ent->flags &= ~0x1000;
  }

  if (pent != 
             ((void *)0)
                 )
   *pent = ent;

  return ret;
 }

 sshfatal("monitor.c", __func__, 531, 1, SYSLOG_LEVEL_FATAL, 
((void *)0)
, "unsupported request: %d", type);


 return (-1);
}


static int
monitor_allowed_key(const u_char *blob, u_int bloblen)
{

 if (key_blob == 
                ((void *)0) 
                     || key_bloblen != bloblen ||
     timingsafe_bcmp(key_blob, blob, key_bloblen))
  return (0);
 return (1);
}

static void
monitor_reset_key_state(void)
{

 free(key_blob);
 free(hostbased_cuser);
 free(hostbased_chost);
 sshauthopt_free(key_opts);
 key_blob = 
           ((void *)0)
               ;
 key_bloblen = 0;
 key_blobtype = MM_NOKEY;
 key_opts = 
           ((void *)0)
               ;
 hostbased_cuser = 
                  ((void *)0)
                      ;
 hostbased_chost = 
                  ((void *)0)
                      ;
}


int
mm_answer_moduli(struct ssh *ssh, int sock, struct sshbuf *m)
{
 DH *dh;
 const BIGNUM *dh_p, *dh_g;
 int r;
 u_int min, want, max;

 if ((r = sshbuf_get_u32(m, &min)) != 0 ||
     (r = sshbuf_get_u32(m, &want)) != 0 ||
     (r = sshbuf_get_u32(m, &max)) != 0)
  sshfatal("monitor.c", __func__, 576, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 sshlog("monitor.c", __func__, 578, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "got parameters: %d %d %d", min, want, max);

 if (max < min || want < min || max < want)
  sshfatal("monitor.c", __func__, 581, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "bad parameters: %d %d %d", min, want, max);

 sshbuf_reset(m);

 dh = choose_dh(min, want, max);
 if (dh == 
          ((void *)0)
              ) {
  if ((r = sshbuf_put_u8(m, 0)) != 0)
   sshfatal("monitor.c", __func__, 588, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble empty");
  return (0);
 } else {

  DH_get0_pqg(dh, &dh_p, 
                        ((void *)0)
                            , &dh_g);
  if ((r = sshbuf_put_u8(m, 1)) != 0 ||
      (r = sshbuf_put_bignum2(m, dh_p)) != 0 ||
      (r = sshbuf_put_bignum2(m, dh_g)) != 0)
   sshfatal("monitor.c", __func__, 596, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble");

  DH_free(dh);
 }
 mm_request_send(sock, MONITOR_ANS_MODULI, m);
 return (0);
}


int
mm_answer_sign(struct ssh *ssh, int sock, struct sshbuf *m)
{
 extern int auth_sock;
 struct sshkey *key;
 struct sshbuf *sigbuf = 
                        ((void *)0)
                            ;
 u_char *p = 
            ((void *)0)
                , *signature = 
                               ((void *)0)
                                   ;
 char *alg = 
            ((void *)0)
                ;
 size_t datlen, siglen, alglen;
 int r, is_proof = 0;
 u_int keyid, compat;
 const char proof_req[] = "hostkeys-prove-00@openssh.com";

 sshlog("monitor.c", __func__, 618, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "entering");

 if ((r = sshbuf_get_u32(m, &keyid)) != 0 ||
     (r = sshbuf_get_string(m, &p, &datlen)) != 0 ||
     (r = sshbuf_get_cstring(m, &alg, &alglen)) != 0 ||
     (r = sshbuf_get_u32(m, &compat)) != 0)
  sshfatal("monitor.c", __func__, 624, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 if (keyid > 0x7fffffff)
  sshfatal("monitor.c", __func__, 626, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "invalid key ID");
 if (datlen != 20 && datlen != 32 && datlen != 48 && datlen != 64) {




  if (session_id2_len == 0)
   sshfatal("monitor.c", __func__, 645, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "bad data length: %zu", datlen);
  if ((key = get_hostkey_public_by_index(keyid, ssh)) == 
                                                        ((void *)0)
                                                            )
   sshfatal("monitor.c", __func__, 647, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "no hostkey for index %d", keyid);
  if ((sigbuf = sshbuf_new()) == 
                                ((void *)0)
                                    )
   sshfatal("monitor.c", __func__, 649, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshbuf_new");
  if ((r = sshbuf_put_cstring(sigbuf, proof_req)) != 0 ||
      (r = sshbuf_put_string(sigbuf, session_id2,
      session_id2_len)) != 0 ||
      (r = sshkey_puts(key, sigbuf)) != 0)
   sshfatal("monitor.c", __func__, 654, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble private key proof");
  if (datlen != sshbuf_len(sigbuf) ||
      memcmp(p, sshbuf_ptr(sigbuf), sshbuf_len(sigbuf)) != 0)
   sshfatal("monitor.c", __func__, 657, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "bad data length: %zu, hostkey proof len %zu", datlen, sshbuf_len(sigbuf))
                                  ;
  sshbuf_free(sigbuf);
  is_proof = 1;
 }


 if (session_id2_len == 0) {
  session_id2_len = datlen;
  session_id2 = xmalloc(session_id2_len);
  memcpy(session_id2, p, session_id2_len);
 }

 if ((key = get_hostkey_by_index(keyid)) != 
                                           ((void *)0)
                                               ) {
  if ((r = sshkey_sign(key, &signature, &siglen, p, datlen, alg,
      options.sk_provider, 
                          ((void *)0)
                              , compat)) != 0)
   sshfatal("monitor.c", __func__, 673, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sign");
 } else if ((key = get_hostkey_public_by_index(keyid, ssh)) != 
                                                              ((void *)0) 
                                                                   &&
     auth_sock > 0) {
  if ((r = ssh_agent_sign(auth_sock, key, &signature, &siglen,
      p, datlen, alg, compat)) != 0)
   sshfatal("monitor.c", __func__, 678, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "agent sign");
 } else
  sshfatal("monitor.c", __func__, 680, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "no hostkey from index %d", keyid);

 sshlog("monitor.c", __func__, 682, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s %s signature len=%zu", alg, is_proof ? "hostkey proof" : "KEX", siglen)
                                                ;

 sshbuf_reset(m);
 if ((r = sshbuf_put_string(m, signature, siglen)) != 0)
  sshfatal("monitor.c", __func__, 687, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble");

 free(alg);
 free(p);
 free(signature);

 mm_request_send(sock, MONITOR_ANS_SIGN, m);


 monitor_permit(mon_dispatch, MONITOR_REQ_PWNAM, 1);

 return (0);
}
int
mm_answer_pwnamallow(struct ssh *ssh, int sock, struct sshbuf *m)
{
 struct passwd *pwent;
 int r, allowed = 0;
 u_int i;

 sshlog("monitor.c", __func__, 716, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "entering");

 if (authctxt->attempt++ != 0)
  sshfatal("monitor.c", __func__, 719, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "multiple attempts for getpwnam");

 if ((r = sshbuf_get_cstring(m, &authctxt->user, 
                                                ((void *)0)
                                                    )) != 0)
  sshfatal("monitor.c", __func__, 722, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 pwent = getpwnamallow(ssh, authctxt->user);

 setproctitle("%s [priv]", pwent ? authctxt->user : "unknown");

 sshbuf_reset(m);

 if (pwent == 
             ((void *)0)
                 ) {
  if ((r = sshbuf_put_u8(m, 0)) != 0)
   sshfatal("monitor.c", __func__, 732, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble fakepw");
  authctxt->pw = fakepw();
  goto out;
 }

 allowed = 1;
 authctxt->pw = pwent;
 authctxt->valid = 1;


 if ((r = sshbuf_put_u8(m, 1)) != 0)
  sshfatal("monitor.c", __func__, 743, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble ok");
 do { if ((r = sshbuf_put_string(m, &pwent->pw_uid, sizeof(pwent->pw_uid))) != 0) sshfatal("monitor.c", __func__, 744, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "pw_uid"); } while (0);
 do { if ((r = sshbuf_put_string(m, &pwent->pw_gid, sizeof(pwent->pw_gid))) != 0) sshfatal("monitor.c", __func__, 745, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "pw_gid"); } while (0);






 if ((r = sshbuf_put_cstring(m, pwent->pw_name)) != 0 ||
     (r = sshbuf_put_cstring(m, "*")) != 0 ||

     (r = sshbuf_put_cstring(m, pwent->pw_gecos)) != 0 ||




     (r = sshbuf_put_cstring(m, pwent->pw_dir)) != 0 ||
     (r = sshbuf_put_cstring(m, pwent->pw_shell)) != 0)
  sshfatal("monitor.c", __func__, 762, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble pw");

 out:
 ssh_packet_set_log_preamble(ssh, "%suser %s",
     authctxt->valid ? "authenticating" : "invalid ", authctxt->user);
 if ((r = sshbuf_put_string(m, &options, sizeof(options))) != 0)
  sshfatal("monitor.c", __func__, 768, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble options");
 do { do { if (options.banner != 
((void *)0) 
&& (r = sshbuf_put_cstring(m, options.banner)) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "banner"); } while (0); do { if (options.trusted_user_ca_keys != 
((void *)0) 
&& (r = sshbuf_put_cstring(m, options.trusted_user_ca_keys)) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "trusted_user_ca_keys"); } while (0); do { if (options.revoked_keys_file != 
((void *)0) 
&& (r = sshbuf_put_cstring(m, options.revoked_keys_file)) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "revoked_keys_file"); } while (0); do { if (options.authorized_keys_command != 
((void *)0) 
&& (r = sshbuf_put_cstring(m, options.authorized_keys_command)) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "authorized_keys_command"); } while (0); do { if (options.authorized_keys_command_user != 
((void *)0) 
&& (r = sshbuf_put_cstring(m, options.authorized_keys_command_user)) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "authorized_keys_command_user"); } while (0); do { if (options.authorized_principals_file != 
((void *)0) 
&& (r = sshbuf_put_cstring(m, options.authorized_principals_file)) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "authorized_principals_file"); } while (0); do { if (options.authorized_principals_command != 
((void *)0) 
&& (r = sshbuf_put_cstring(m, options.authorized_principals_command)) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "authorized_principals_command"); } while (0); do { if (options.authorized_principals_command_user != 
((void *)0) 
&& (r = sshbuf_put_cstring(m, options.authorized_principals_command_user)) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "authorized_principals_command_user"); } while (0); do { if (options.hostbased_accepted_algos != 
((void *)0) 
&& (r = sshbuf_put_cstring(m, options.hostbased_accepted_algos)) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "hostbased_accepted_algos"); } while (0); do { if (options.pubkey_accepted_algos != 
((void *)0) 
&& (r = sshbuf_put_cstring(m, options.pubkey_accepted_algos)) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "pubkey_accepted_algos"); } while (0); do { if (options.ca_sign_algorithms != 
((void *)0) 
&& (r = sshbuf_put_cstring(m, options.ca_sign_algorithms)) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "ca_sign_algorithms"); } while (0); do { if (options.routing_domain != 
((void *)0) 
&& (r = sshbuf_put_cstring(m, options.routing_domain)) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "routing_domain"); } while (0); do { if (options.permit_user_env_allowlist != 
((void *)0) 
&& (r = sshbuf_put_cstring(m, options.permit_user_env_allowlist)) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "permit_user_env_allowlist"); } while (0); do { for (i = 0; i < options.num_authkeys_files; i++) { if ((r = sshbuf_put_cstring(m, options.authorized_keys_files[i])) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "authorized_keys_files"); } } while (0); do { for (i = 0; i < options.num_allow_users; i++) { if ((r = sshbuf_put_cstring(m, options.allow_users[i])) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "allow_users"); } } while (0); do { for (i = 0; i < options.num_deny_users; i++) { if ((r = sshbuf_put_cstring(m, options.deny_users[i])) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "deny_users"); } } while (0); do { for (i = 0; i < options.num_allow_groups; i++) { if ((r = sshbuf_put_cstring(m, options.allow_groups[i])) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "allow_groups"); } } while (0); do { for (i = 0; i < options.num_deny_groups; i++) { if ((r = sshbuf_put_cstring(m, options.deny_groups[i])) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "deny_groups"); } } while (0); do { for (i = 0; i < options.num_accept_env; i++) { if ((r = sshbuf_put_cstring(m, options.accept_env[i])) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "accept_env"); } } while (0); do { for (i = 0; i < options.num_setenv; i++) { if ((r = sshbuf_put_cstring(m, options.setenv[i])) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "setenv"); } } while (0); do { for (i = 0; i < options.num_auth_methods; i++) { if ((r = sshbuf_put_cstring(m, options.auth_methods[i])) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "auth_methods"); } } while (0); do { for (i = 0; i < options.num_permitted_opens; i++) { if ((r = sshbuf_put_cstring(m, options.permitted_opens[i])) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "permitted_opens"); } } while (0); do { for (i = 0; i < options.num_permitted_listens; i++) { if ((r = sshbuf_put_cstring(m, options.permitted_listens[i])) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "permitted_listens"); } } while (0); do { for (i = 0; i < options.num_log_verbose; i++) { if ((r = sshbuf_put_cstring(m, options.log_verbose[i])) != 0) sshfatal("monitor.c", __func__, 782, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble %s", "log_verbose"); } } while (0); } while (0);




 if (auth2_setup_methods_lists(authctxt) != 0) {





  sshlog("monitor.c", __func__, 793, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "no valid authentication method lists");
 }

 sshlog("monitor.c", __func__, 796, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "sending MONITOR_ANS_PWNAM: %d", allowed);
 mm_request_send(sock, MONITOR_ANS_PWNAM, m);


 monitor_permit(mon_dispatch, MONITOR_REQ_AUTHSERV, 1);
 monitor_permit(mon_dispatch, MONITOR_REQ_AUTH2_READ_BANNER, 1);






 return (0);
}

int mm_answer_auth2_read_banner(struct ssh *ssh, int sock, struct sshbuf *m)
{
 char *banner;
 int r;

 sshbuf_reset(m);
 banner = auth2_read_banner();
 if ((r = sshbuf_put_cstring(m, banner != 
                                         ((void *)0) 
                                              ? banner : "")) != 0)
  sshfatal("monitor.c", __func__, 819, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble");
 mm_request_send(sock, MONITOR_ANS_AUTH2_READ_BANNER, m);
 free(banner);

 return (0);
}

int
mm_answer_authserv(struct ssh *ssh, int sock, struct sshbuf *m)
{
 int r;

 monitor_permit_authentications(1);

 if ((r = sshbuf_get_cstring(m, &authctxt->service, 
                                                   ((void *)0)
                                                       )) != 0 ||
     (r = sshbuf_get_cstring(m, &authctxt->style, 
                                                 ((void *)0)
                                                     )) != 0)
  sshfatal("monitor.c", __func__, 835, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 sshlog("monitor.c", __func__, 836, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "service=%s, style=%s", authctxt->service, authctxt->style);

 if (strlen(authctxt->style) == 0) {
  free(authctxt->style);
  authctxt->style = 
                   ((void *)0)
                       ;
 }

 return (0);
}







static int
key_base_type_match(const char *method, const struct sshkey *key,
    const char *list)
{
 char *s, *l, *ol = xstrdup(list);
 int found = 0;

 l = ol;
 for ((s = strsep(&l, ",")); s && *s != '\0'; (s = strsep(&l, ","))) {
  if (sshkey_type_from_name(s) == key->type) {
   found = 1;
   break;
  }
 }
 if (!found) {
  sshlog("monitor.c", __func__, 867, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s key type %s is not in permitted list %s", method, sshkey_ssh_name(key), list)
                                 ;
 }

 free(ol);
 return found;
}

int
mm_answer_authpassword(struct ssh *ssh, int sock, struct sshbuf *m)
{
 static int call_count;
 char *passwd;
 int r, authenticated;
 size_t plen;

 if (!options.password_authentication)
  sshfatal("monitor.c", __func__, 884, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "password authentication not enabled");
 if ((r = sshbuf_get_cstring(m, &passwd, &plen)) != 0)
  sshfatal("monitor.c", __func__, 886, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 authenticated = options.password_authentication &&
     auth_password(ssh, passwd);
 freezero(passwd, plen);

 sshbuf_reset(m);
 if ((r = sshbuf_put_u32(m, authenticated)) != 0)
  sshfatal("monitor.c", __func__, 894, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble");





 sshlog("monitor.c", __func__, 900, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s: sending result %d", __func__, authenticated);
 sshlog("monitor.c", __func__, 901, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "sending result %d", authenticated);
 mm_request_send(sock, MONITOR_ANS_AUTHPASSWORD, m);

 call_count++;
 if (plen == 0 && call_count == 1)
  auth_method = "none";
 else
  auth_method = "password";


 return (authenticated);
}
int
mm_answer_keyallowed(struct ssh *ssh, int sock, struct sshbuf *m)
{
 struct sshkey *key = 
                     ((void *)0)
                         ;
 char *cuser, *chost;
 u_int pubkey_auth_attempt;
 u_int type = 0;
 int r, allowed = 0;
 struct sshauthopt *opts = 
                          ((void *)0)
                              ;

 sshlog("monitor.c", __func__, 1155, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "entering");
 if ((r = sshbuf_get_u32(m, &type)) != 0 ||
     (r = sshbuf_get_cstring(m, &cuser, 
                                       ((void *)0)
                                           )) != 0 ||
     (r = sshbuf_get_cstring(m, &chost, 
                                       ((void *)0)
                                           )) != 0 ||
     (r = sshkey_froms(m, &key)) != 0 ||
     (r = sshbuf_get_u32(m, &pubkey_auth_attempt)) != 0)
  sshfatal("monitor.c", __func__, 1161, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 if (key != 
           ((void *)0) 
                && authctxt->valid) {

  if (sshkey_type_plain(key->type) == KEY_RSA &&
      (ssh->compat & 0x00002000) != 0)
   sshfatal("monitor.c", __func__, 1167, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "passed a SSH_BUG_RSASIGMD5 key");

  switch (type) {
  case MM_USERKEY:
   auth_method = "publickey";
   if (!options.pubkey_authentication)
    break;
   if (auth2_key_already_used(authctxt, key))
    break;
   if (!key_base_type_match(auth_method, key,
       options.pubkey_accepted_algos))
    break;
   allowed = user_key_allowed(ssh, authctxt->pw, key,
       pubkey_auth_attempt, &opts);
   break;
  case MM_HOSTKEY:
   auth_method = "hostbased";
   if (!options.hostbased_authentication)
    break;
   if (auth2_key_already_used(authctxt, key))
    break;
   if (!key_base_type_match(auth_method, key,
       options.hostbased_accepted_algos))
    break;
   allowed = hostbased_key_allowed(ssh, authctxt->pw,
       cuser, chost, key);
   auth2_record_info(authctxt,
       "client user \"%.100s\", client host \"%.100s\"",
       cuser, chost);
   break;
  default:
   sshfatal("monitor.c", __func__, 1198, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "unknown key type %u", type);
   break;
  }
 }

 sshlog("monitor.c", __func__, 1203, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s authentication%s: %s key is %s", auth_method, pubkey_auth_attempt ? "" : " test", (key == 
((void *)0) 
|| !authctxt->valid) ? "invalid" : sshkey_type(key), allowed ? "allowed" : "not allowed")


                                         ;

 auth2_record_key(authctxt, 0, key);


 monitor_reset_key_state();

 if (allowed) {

  if ((r = sshkey_to_blob(key, &key_blob, &key_bloblen)) != 0)
   sshfatal("monitor.c", __func__, 1216, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshkey_to_blob");
  key_blobtype = type;
  key_opts = opts;
  hostbased_cuser = cuser;
  hostbased_chost = chost;
 } else {

  auth_log(ssh, 0, 0, auth_method, 
                                  ((void *)0)
                                      );
  free(cuser);
  free(chost);
 }
 sshkey_free(key);

 sshbuf_reset(m);
 if ((r = sshbuf_put_u32(m, allowed)) != 0)
  sshfatal("monitor.c", __func__, 1231, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble");
 if (opts != 
            ((void *)0) 
                 && (r = sshauthopt_serialise(opts, m, 1)) != 0)
  sshfatal("monitor.c", __func__, 1233, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshauthopt_serialise");
 mm_request_send(sock, MONITOR_ANS_KEYALLOWED, m);

 if (!allowed)
  sshauthopt_free(opts);

 return (0);
}

static int
monitor_valid_userblob(struct ssh *ssh, const u_char *data, u_int datalen)
{
 struct sshbuf *b;
 struct sshkey *hostkey = 
                         ((void *)0)
                             ;
 const u_char *p;
 char *userstyle, *cp;
 size_t len;
 u_char type;
 int hostbound = 0, r, fail = 0;

 if ((b = sshbuf_from(data, datalen)) == 
                                        ((void *)0)
                                            )
  sshfatal("monitor.c", __func__, 1254, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_from");

 if (ssh->compat & 0x00000010) {
  p = sshbuf_ptr(b);
  len = sshbuf_len(b);
  if ((session_id2 == 
                     ((void *)0)
                         ) ||
      (len < session_id2_len) ||
      (timingsafe_bcmp(p, session_id2, session_id2_len) != 0))
   fail++;
  if ((r = sshbuf_consume(b, session_id2_len)) != 0)
   sshfatal("monitor.c", __func__, 1264, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "consume");
 } else {
  if ((r = sshbuf_get_string_direct(b, &p, &len)) != 0)
   sshfatal("monitor.c", __func__, 1267, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse sessionid");
  if ((session_id2 == 
                     ((void *)0)
                         ) ||
      (len != session_id2_len) ||
      (timingsafe_bcmp(p, session_id2, session_id2_len) != 0))
   fail++;
 }
 if ((r = sshbuf_get_u8(b, &type)) != 0)
  sshfatal("monitor.c", __func__, 1274, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse type");
 if (type != 50)
  fail++;
 if ((r = sshbuf_get_cstring(b, &cp, 
                                    ((void *)0)
                                        )) != 0)
  sshfatal("monitor.c", __func__, 1278, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse userstyle");
 xasprintf(&userstyle, "%s%s%s", authctxt->user,
     authctxt->style ? ":" : "",
     authctxt->style ? authctxt->style : "");
 if (strcmp(userstyle, cp) != 0) {
  sshlog("monitor.c", __func__, 1283, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "wrong user name passed to monitor: " "expected %s != %.100s", userstyle, cp)
                                             ;
  fail++;
 }
 free(userstyle);
 free(cp);
 if ((r = sshbuf_get_string_direct(b, 
         ((void *)0)
         , 
         ((void *)0)
         )) != 0 ||
     (r = sshbuf_get_cstring(b, &cp, 
                                    ((void *)0)
                                        )) != 0)
  sshfatal("monitor.c", __func__, 1291, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse method");
 if (strcmp("publickey", cp) != 0) {
  if (strcmp("publickey-hostbound-v00@openssh.com", cp) == 0)
   hostbound = 1;
  else
   fail++;
 }
 free(cp);
 if ((r = sshbuf_get_u8(b, &type)) != 0)
  sshfatal("monitor.c", __func__, 1300, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse pktype");
 if (type == 0)
  fail++;
 if ((r = sshbuf_get_string_direct(b, 
         ((void *)0)
         , 
         ((void *)0)
         )) != 0 ||
     (r = sshbuf_get_string_direct(b, 
         ((void *)0)
         , 
         ((void *)0)
         )) != 0 ||
     (hostbound && (r = sshkey_froms(b, &hostkey)) != 0))
  sshfatal("monitor.c", __func__, 1306, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse pk");
 if (sshbuf_len(b) != 0)
  fail++;
 sshbuf_free(b);
 if (hostkey != 
               ((void *)0)
                   ) {





  if (get_hostkey_index(hostkey, 1, ssh) == -1)
   sshfatal("monitor.c", __func__, 1317, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "hostbound hostkey does not match");
  sshkey_free(hostkey);
 }
 return (fail == 0);
}

static int
monitor_valid_hostbasedblob(const u_char *data, u_int datalen,
    const char *cuser, const char *chost)
{
 struct sshbuf *b;
 const u_char *p;
 char *cp, *userstyle;
 size_t len;
 int r, fail = 0;
 u_char type;

 if ((b = sshbuf_from(data, datalen)) == 
                                        ((void *)0)
                                            )
  sshfatal("monitor.c", __func__, 1335, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 if ((r = sshbuf_get_string_direct(b, &p, &len)) != 0)
  sshfatal("monitor.c", __func__, 1337, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse sessionid");

 if ((session_id2 == 
                    ((void *)0)
                        ) ||
     (len != session_id2_len) ||
     (timingsafe_bcmp(p, session_id2, session_id2_len) != 0))
  fail++;

 if ((r = sshbuf_get_u8(b, &type)) != 0)
  sshfatal("monitor.c", __func__, 1345, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse type");
 if (type != 50)
  fail++;
 if ((r = sshbuf_get_cstring(b, &cp, 
                                    ((void *)0)
                                        )) != 0)
  sshfatal("monitor.c", __func__, 1349, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse userstyle");
 xasprintf(&userstyle, "%s%s%s", authctxt->user,
     authctxt->style ? ":" : "",
     authctxt->style ? authctxt->style : "");
 if (strcmp(userstyle, cp) != 0) {
  sshlog("monitor.c", __func__, 1354, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "wrong user name passed to monitor: " "expected %s != %.100s", userstyle, cp)
                                             ;
  fail++;
 }
 free(userstyle);
 free(cp);
 if ((r = sshbuf_get_string_direct(b, 
         ((void *)0)
         , 
         ((void *)0)
         )) != 0 ||
     (r = sshbuf_get_cstring(b, &cp, 
                                    ((void *)0)
                                        )) != 0)
  sshfatal("monitor.c", __func__, 1362, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse method");
 if (strcmp(cp, "hostbased") != 0)
  fail++;
 free(cp);
 if ((r = sshbuf_get_string_direct(b, 
         ((void *)0)
         , 
         ((void *)0)
         )) != 0 ||
     (r = sshbuf_get_string_direct(b, 
         ((void *)0)
         , 
         ((void *)0)
         )) != 0)
  sshfatal("monitor.c", __func__, 1368, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse pk");


 if ((r = sshbuf_get_cstring(b, &cp, 
                                    ((void *)0)
                                        )) != 0)
  sshfatal("monitor.c", __func__, 1372, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse host");
 if (((len = strlen(cp)) > 0) && cp[len - 1] == '.')
  cp[len - 1] = '\0';
 if (strcmp(cp, chost) != 0)
  fail++;
 free(cp);


 if ((r = sshbuf_get_cstring(b, &cp, 
                                    ((void *)0)
                                        )) != 0)
  sshfatal("monitor.c", __func__, 1381, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse ruser");
 if (strcmp(cp, cuser) != 0)
  fail++;
 free(cp);

 if (sshbuf_len(b) != 0)
  fail++;
 sshbuf_free(b);
 return (fail == 0);
}

int
mm_answer_keyverify(struct ssh *ssh, int sock, struct sshbuf *m)
{
 struct sshkey *key;
 const u_char *signature, *data, *blob;
 char *sigalg = 
               ((void *)0)
                   , *fp = 
                           ((void *)0)
                               ;
 size_t signaturelen, datalen, bloblen;
 int r, ret, req_presence = 0, req_verify = 0, valid_data = 0;
 int encoded_ret;
 struct sshkey_sig_details *sig_details = 
                                         ((void *)0)
                                             ;

 if ((r = sshbuf_get_string_direct(m, &blob, &bloblen)) != 0 ||
     (r = sshbuf_get_string_direct(m, &signature, &signaturelen)) != 0 ||
     (r = sshbuf_get_string_direct(m, &data, &datalen)) != 0 ||
     (r = sshbuf_get_cstring(m, &sigalg, 
                                        ((void *)0)
                                            )) != 0)
  sshfatal("monitor.c", __func__, 1407, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");

 if (hostbased_cuser == 
                       ((void *)0) 
                            || hostbased_chost == 
                                                  ((void *)0) 
                                                       ||
   !monitor_allowed_key(blob, bloblen))
  sshfatal("monitor.c", __func__, 1411, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "bad key, not previously allowed");


 if (*sigalg == '\0') {
  free(sigalg);
  sigalg = 
          ((void *)0)
              ;
 }


 if ((r = sshkey_from_blob(blob, bloblen, &key)) != 0)
  sshfatal("monitor.c", __func__, 1421, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse key");

 switch (key_blobtype) {
 case MM_USERKEY:
  valid_data = monitor_valid_userblob(ssh, data, datalen);
  auth_method = "publickey";
  break;
 case MM_HOSTKEY:
  valid_data = monitor_valid_hostbasedblob(data, datalen,
      hostbased_cuser, hostbased_chost);
  auth_method = "hostbased";
  break;
 default:
  valid_data = 0;
  break;
 }
 if (!valid_data)
  sshfatal("monitor.c", __func__, 1438, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "bad %s signature data blob", key_blobtype == MM_USERKEY ? "userkey" : (key_blobtype == MM_HOSTKEY ? "hostkey" : "unknown"))

                                                           ;

 if ((fp = sshkey_fingerprint(key, options.fingerprint_hash,
     SSH_FP_DEFAULT)) == 
                        ((void *)0)
                            )
  sshfatal("monitor.c", __func__, 1444, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshkey_fingerprint failed");

 ret = sshkey_verify(key, signature, signaturelen, data, datalen,
     sigalg, ssh->compat, &sig_details);
 sshlog("monitor.c", __func__, 1448, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s %s signature using %s %s%s%s", auth_method, sshkey_type(key), sigalg == 
((void *)0) 
? "default" : sigalg, (ret == 0) ? "verified" : "unverified", (ret != 0) ? ": " : "", (ret != 0) ? ssh_err(ret) : "")


                                                            ;

 if (ret == 0 && key_blobtype == MM_USERKEY && sig_details != 
                                                             ((void *)0)
                                                                 ) {
  req_presence = (options.pubkey_auth_options &
      (1)) ||
      !key_opts->no_require_user_presence;
  if (req_presence &&
      (sig_details->sk_flags & 0x01) == 0) {
   sshlog("monitor.c", __func__, 1459, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "public key %s %s signature for %s%s from %.128s " "port %d rejected: user presence " "(authenticator touch) requirement not met ", sshkey_type(key), fp, authctxt->valid ? "" : "invalid user ", authctxt->user, ssh_remote_ipaddr(ssh), ssh_remote_port(ssh))





                            ;
   ret = -21;
  }
  req_verify = (options.pubkey_auth_options &
      (1<<1)) || key_opts->require_verify;
  if (req_verify &&
      (sig_details->sk_flags & 0x04) == 0) {
   sshlog("monitor.c", __func__, 1472, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "public key %s %s signature for %s%s from %.128s " "port %d rejected: user verification requirement " "not met ", sshkey_type(key), fp, authctxt->valid ? "" : "invalid user ", authctxt->user, ssh_remote_ipaddr(ssh), ssh_remote_port(ssh))




                            ;
   ret = -21;
  }
 }
 auth2_record_key(authctxt, ret == 0, key);

 if (key_blobtype == MM_USERKEY)
  auth_activate_options(ssh, key_opts);
 monitor_reset_key_state();

 sshbuf_reset(m);


 encoded_ret = (ret != 0);
 if ((r = sshbuf_put_u32(m, encoded_ret)) != 0 ||
     (r = sshbuf_put_u8(m, sig_details != 
                                         ((void *)0)
                                             )) != 0)
  sshfatal("monitor.c", __func__, 1493, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble");
 if (sig_details != 
                   ((void *)0)
                       ) {
  if ((r = sshbuf_put_u32(m, sig_details->sk_counter)) != 0 ||
      (r = sshbuf_put_u8(m, sig_details->sk_flags)) != 0)
   sshfatal("monitor.c", __func__, 1497, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble sk");
 }
 sshkey_sig_details_free(sig_details);
 mm_request_send(sock, MONITOR_ANS_KEYVERIFY, m);

 free(sigalg);
 free(fp);
 sshkey_free(key);

 return ret == 0;
}

static void
mm_record_login(struct ssh *ssh, Session *s, struct passwd *pw)
{
 socklen_t fromlen;
 struct sockaddr_storage from;





 memset(&from, 0, sizeof(from));
 fromlen = sizeof(from);
 if (ssh_packet_connection_is_on_socket(ssh)) {
  if (getpeername(ssh_packet_get_connection_in(ssh),
      (struct sockaddr *)&from, &fromlen) == -1) {
   sshlog("monitor.c", __func__, 1524, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "getpeername: %.100s", strerror(
  (*__errno_location ())
  ));
   cleanup_exit(255);
  }
 }

 record_login(s->pid, s->tty, pw->pw_name, pw->pw_uid,
     session_get_remote_name_or_ip(ssh, utmp_len, options.use_dns),
     (struct sockaddr *)&from, fromlen);
}

static void
mm_session_close(Session *s)
{
 sshlog("monitor.c", __func__, 1537, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "session %d pid %ld", s->self, (long)s->pid);
 if (s->ttyfd != -1) {
  sshlog("monitor.c", __func__, 1539, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "tty %s ptyfd %d", s->tty, s->ptyfd);
  session_pty_cleanup2(s);
 }
 session_unused(s->self);
}

int
mm_answer_pty(struct ssh *ssh, int sock, struct sshbuf *m)
{
 extern struct monitor *pmonitor;
 Session *s;
 int r, res, fd0;

 sshlog("monitor.c", __func__, 1552, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "entering");

 sshbuf_reset(m);
 s = session_new();
 if (s == 
         ((void *)0)
             )
  goto error;
 s->authctxt = authctxt;
 s->pw = authctxt->pw;
 s->pid = pmonitor->m_pid;
 res = pty_allocate(&s->ptyfd, &s->ttyfd, s->tty, sizeof(s->tty));
 if (res == 0)
  goto error;
 pty_setowner(authctxt->pw, s->tty);

 if ((r = sshbuf_put_u32(m, 1)) != 0 ||
     (r = sshbuf_put_cstring(m, s->tty)) != 0)
  sshfatal("monitor.c", __func__, 1568, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble");


 if (dup2(s->ttyfd, 0) == -1)
  sshfatal("monitor.c", __func__, 1572, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "dup2");

 mm_record_login(ssh, s, authctxt->pw);


 close(0);


 if ((r = sshbuf_put_stringb(m, loginmsg)) != 0)
  sshfatal("monitor.c", __func__, 1581, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble loginmsg");
 sshbuf_reset(loginmsg);

 mm_request_send(sock, MONITOR_ANS_PTY, m);

 if (mm_send_fd(sock, s->ptyfd) == -1 ||
     mm_send_fd(sock, s->ttyfd) == -1)
  sshfatal("monitor.c", __func__, 1588, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "send fds failed");


 if ((fd0 = open(
                "/dev/null"
                             , 
                               00
                                       )) == -1)
  sshfatal("monitor.c", __func__, 1592, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "open(/dev/null): %s", strerror(
 (*__errno_location ())
 ));
 if (fd0 != 0)
  sshlog("monitor.c", __func__, 1594, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "fd0 %d != 0", fd0);


 close(s->ttyfd);
 s->ttyfd = s->ptyfd;

 s->ptymaster = s->ptyfd;

 sshlog("monitor.c", __func__, 1602, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "tty %s ptyfd %d", s->tty, s->ttyfd);

 return (0);

 error:
 if (s != 
         ((void *)0)
             )
  mm_session_close(s);
 if ((r = sshbuf_put_u32(m, 0)) != 0)
  sshfatal("monitor.c", __func__, 1610, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble 0");
 mm_request_send(sock, MONITOR_ANS_PTY, m);
 return (0);
}

int
mm_answer_pty_cleanup(struct ssh *ssh, int sock, struct sshbuf *m)
{
 Session *s;
 char *tty;
 int r;

 sshlog("monitor.c", __func__, 1622, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "entering");

 if ((r = sshbuf_get_cstring(m, &tty, 
                                     ((void *)0)
                                         )) != 0)
  sshfatal("monitor.c", __func__, 1625, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse tty");
 if ((s = session_by_tty(tty)) != 
                                 ((void *)0)
                                     )
  mm_session_close(s);
 sshbuf_reset(m);
 free(tty);
 return (0);
}

int
mm_answer_term(struct ssh *ssh, int sock, struct sshbuf *req)
{
 extern struct monitor *pmonitor;
 int res, status;

 sshlog("monitor.c", __func__, 1639, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "tearing down sessions");


 session_destroy_all(ssh, &mm_session_close);






 while (waitpid(pmonitor->m_pid, &status, 0) == -1)
  if (
     (*__errno_location ()) 
           != 
              4
                   )
   exit(1);

 res = 
      (((
      status
      ) & 0x7f) == 0) 
                        ? 
                          (((
                          status
                          ) & 0xff00) >> 8) 
                                              : 1;


 exit(res);
}
void
monitor_clear_keystate(struct ssh *ssh, struct monitor *pmonitor)
{
 ssh_clear_newkeys(ssh, MODE_IN);
 ssh_clear_newkeys(ssh, MODE_OUT);
 sshbuf_free(child_state);
 child_state = 
              ((void *)0)
                  ;
}

void
monitor_apply_keystate(struct ssh *ssh, struct monitor *pmonitor)
{
 struct kex *kex;
 int r;

 sshlog("monitor.c", __func__, 1721, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "packet_set_state");
 if ((r = ssh_packet_set_state(ssh, child_state)) != 0)
  sshfatal("monitor.c", __func__, 1723, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "packet_set_state");
 sshbuf_free(child_state);
 child_state = 
              ((void *)0)
                  ;
 if ((kex = ssh->kex) == 
                        ((void *)0)
                            )
  sshfatal("monitor.c", __func__, 1727, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "internal error: ssh->kex == NULL");
 if (session_id2_len != sshbuf_len(ssh->kex->session_id)) {
  sshfatal("monitor.c", __func__, 1729, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "incorrect session id length %zu (expected %u)", sshbuf_len(ssh->kex->session_id), session_id2_len)
                                                        ;
 }
 if (memcmp(sshbuf_ptr(ssh->kex->session_id), session_id2,
     session_id2_len) != 0)
  sshfatal("monitor.c", __func__, 1734, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "session ID mismatch");


 kex->kex[KEX_DH_GRP1_SHA1] = kex_gen_server;
 kex->kex[KEX_DH_GRP14_SHA1] = kex_gen_server;
 kex->kex[KEX_DH_GRP14_SHA256] = kex_gen_server;
 kex->kex[KEX_DH_GRP16_SHA512] = kex_gen_server;
 kex->kex[KEX_DH_GRP18_SHA512] = kex_gen_server;
 kex->kex[KEX_DH_GEX_SHA1] = kexgex_server;
 kex->kex[KEX_DH_GEX_SHA256] = kexgex_server;

 kex->kex[KEX_ECDH_SHA2] = kex_gen_server;


 kex->kex[KEX_C25519_SHA256] = kex_gen_server;
 kex->kex[KEX_KEM_SNTRUP761X25519_SHA512] = kex_gen_server;
 kex->load_host_public_key=&get_hostkey_public_by_type;
 kex->load_host_private_key=&get_hostkey_private_by_type;
 kex->host_key_index=&get_hostkey_index;
 kex->sign = sshd_hostkey_sign;
}



void
mm_get_keystate(struct ssh *ssh, struct monitor *pmonitor)
{
 sshlog("monitor.c", __func__, 1761, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "Waiting for new keys");

 if ((child_state = sshbuf_new()) == 
                                    ((void *)0)
                                        )
  sshfatal("monitor.c", __func__, 1764, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 mm_request_receive_expect(pmonitor->m_sendfd, MONITOR_REQ_KEYEXPORT,
     child_state);
 sshlog("monitor.c", __func__, 1767, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "GOT new keys");
}
static void
monitor_openfds(struct monitor *mon, int do_logfds)
{
 int pair[2];




 if (socketpair(
               1
                      , 
                        SOCK_STREAM
                                   , 0, pair) == -1)
  sshfatal("monitor.c", __func__, 1787, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "socketpair: %s", strerror(
 (*__errno_location ())
 ));






 do { if (fcntl(pair[0], 
2
, 
1
) == -1) sshfatal("monitor.c", __func__, 1794, 0, SYSLOG_LEVEL_FATAL, 
((void *)0)
, "fcntl(%d, F_SETFD)", pair[0]); } while (0);
 do { if (fcntl(pair[1], 
2
, 
1
) == -1) sshfatal("monitor.c", __func__, 1795, 0, SYSLOG_LEVEL_FATAL, 
((void *)0)
, "fcntl(%d, F_SETFD)", pair[1]); } while (0);
 mon->m_recvfd = pair[0];
 mon->m_sendfd = pair[1];

 if (do_logfds) {
  if (pipe(pair) == -1)
   sshfatal("monitor.c", __func__, 1801, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "pipe: %s", strerror(
  (*__errno_location ())
  ));
  do { if (fcntl(pair[0], 
 2
 , 
 1
 ) == -1) sshfatal("monitor.c", __func__, 1802, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "fcntl(%d, F_SETFD)", pair[0]); } while (0);
  do { if (fcntl(pair[1], 
 2
 , 
 1
 ) == -1) sshfatal("monitor.c", __func__, 1803, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "fcntl(%d, F_SETFD)", pair[1]); } while (0);
  mon->m_log_recvfd = pair[0];
  mon->m_log_sendfd = pair[1];
 } else
  mon->m_log_recvfd = mon->m_log_sendfd = -1;
}



struct monitor *
monitor_init(void)
{
 struct monitor *mon;

 mon = xcalloc(1, sizeof(*mon));
 monitor_openfds(mon, 1);

 return mon;
}

void
monitor_reinit(struct monitor *mon)
{
 monitor_openfds(mon, 0);
}
