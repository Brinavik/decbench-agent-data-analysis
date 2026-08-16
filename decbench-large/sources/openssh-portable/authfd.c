











































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
struct ssh;

void compat_banner(struct ssh *, const char *);
char *compat_cipher_proposal(struct ssh *, char *);
char *compat_pkalg_proposal(struct ssh *, char *);
char *compat_kex_proposal(struct ssh *, char *);
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
static int
decode_reply(u_char type)
{
 if (((type == 5) || (type == 102) || (type == 30)))
  return -27;
 else if (type == 6)
  return 0;
 else
  return -4;
}





int
ssh_get_authentication_socket_path(const char *authsocket, int *fdp)
{
 int sock, oerrno;
 struct sockaddr_un sunaddr;

 sshlog("authfd.c", __func__, 95, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "path '%s'", authsocket);
 memset(&sunaddr, 0, sizeof(sunaddr));
 sunaddr.sun_family = 
                     1
                            ;
 strlcpy(sunaddr.sun_path, authsocket, sizeof(sunaddr.sun_path));

 if ((sock = socket(
                   1
                          , 
                            SOCK_STREAM
                                       , 0)) == -1)
  return -24;


 if (fcntl(sock, 
                2
                       , 
                         1
                                   ) == -1 ||
     connect(sock, (struct sockaddr *)&sunaddr, sizeof(sunaddr)) == -1) {
  oerrno = 
          (*__errno_location ())
               ;
  close(sock);
  
 (*__errno_location ()) 
       = oerrno;
  return -24;
 }
 if (fdp != 
           ((void *)0)
               )
  *fdp = sock;
 else
  close(sock);
 return 0;
}





int
ssh_get_authentication_socket(int *fdp)
{
 const char *authsocket;

 if (fdp != 
           ((void *)0)
               )
  *fdp = -1;

 authsocket = getenv("SSH_AUTH_SOCK");
 if (authsocket == 
                  ((void *)0) 
                       || *authsocket == '\0')
  return -47;

 return ssh_get_authentication_socket_path(authsocket, fdp);
}


static int
ssh_request_reply(int sock, struct sshbuf *request, struct sshbuf *reply)
{
 int r;
 size_t l, len;
 char buf[1024];


 len = sshbuf_len(request);
 do { const u_int32_t __v = (len); ((u_char *)(buf))[0] = (__v >> 24) & 0xff; ((u_char *)(buf))[1] = (__v >> 16) & 0xff; ((u_char *)(buf))[2] = (__v >> 8) & 0xff; ((u_char *)(buf))[3] = __v & 0xff; } while (0);


 if (atomicio((ssize_t (*)(int, void *, size_t))write, sock, buf, 4) != 4 ||
     atomicio((ssize_t (*)(int, void *, size_t))write, sock, sshbuf_mutable_ptr(request),
     sshbuf_len(request)) != sshbuf_len(request))
  return -26;




 if (atomicio(read, sock, buf, 4) != 4)
     return -26;


 len = (((u_int32_t)(((const u_char *)(buf))[0]) << 24) | ((u_int32_t)(((const u_char *)(buf))[1]) << 16) | ((u_int32_t)(((const u_char *)(buf))[2]) << 8) | (u_int32_t)(((const u_char *)(buf))[3]));
 if (len > (256 * 1024))
  return -4;


 sshbuf_reset(reply);
 while (len > 0) {
  l = len;
  if (l > sizeof(buf))
   l = sizeof(buf);
  if (atomicio(read, sock, buf, l) != l)
   return -26;
  if ((r = sshbuf_put(reply, buf, l)) != 0)
   return r;
  len -= l;
 }
 return 0;
}


static int
ssh_request_reply_decode(int sock, struct sshbuf *request)
{
 struct sshbuf *reply;
 int r;
 u_char type;

 if ((reply = sshbuf_new()) == 
                              ((void *)0)
                                  )
  return -2;
 if ((r = ssh_request_reply(sock, request, reply)) != 0 ||
     (r = sshbuf_get_u8(reply, &type)) != 0 ||
     (r = decode_reply(type)) != 0)
  goto out;

 r = 0;
 out:
 sshbuf_free(reply);
 return r;
}






void
ssh_close_authentication_socket(int sock)
{
 if (getenv("SSH_AUTH_SOCK"))
  close(sock);
}


int
ssh_lock_agent(int sock, int lock, const char *password)
{
 int r;
 u_char type = lock ? 22 : 23;
 struct sshbuf *msg;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  return -2;
 if ((r = sshbuf_put_u8(msg, type)) != 0 ||
     (r = sshbuf_put_cstring(msg, password)) != 0 ||
     (r = ssh_request_reply_decode(sock, msg)) != 0)
  goto out;

 r = 0;
 out:
 sshbuf_free(msg);
 return r;
}


static int
deserialise_identity2(struct sshbuf *ids, struct sshkey **keyp, char **commentp)
{
 int r;
 char *comment = 
                ((void *)0)
                    ;
 const u_char *blob;
 size_t blen;

 if ((r = sshbuf_get_string_direct(ids, &blob, &blen)) != 0 ||
     (r = sshbuf_get_cstring(ids, &comment, 
                                           ((void *)0)
                                               )) != 0)
  goto out;
 if ((r = sshkey_from_blob(blob, blen, keyp)) != 0)
  goto out;
 if (commentp != 
                ((void *)0)
                    ) {
  *commentp = comment;
  comment = 
           ((void *)0)
               ;
 }
 r = 0;
 out:
 free(comment);
 return r;
}




int
ssh_fetch_identitylist(int sock, struct ssh_identitylist **idlp)
{
 u_char type;
 u_int32_t num, i;
 struct sshbuf *msg;
 struct ssh_identitylist *idl = 
                               ((void *)0)
                                   ;
 int r;





 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  return -2;
 if ((r = sshbuf_put_u8(msg, 11)) != 0)
  goto out;

 if ((r = ssh_request_reply(sock, msg, msg)) != 0)
  goto out;


 if ((r = sshbuf_get_u8(msg, &type)) != 0)
  goto out;
 if (((type == 5) || (type == 102) || (type == 30))) {
  r = -27;
  goto out;
 } else if (type != 12) {
  r = -4;
  goto out;
 }


 if ((r = sshbuf_get_u32(msg, &num)) != 0)
  goto out;
 if (num > 2048) {
  r = -4;
  goto out;
 }
 if (num == 0) {
  r = -48;
  goto out;
 }


 if ((idl = calloc(1, sizeof(*idl))) == 
                                       ((void *)0) 
                                            ||
     (idl->keys = calloc(num, sizeof(*idl->keys))) == 
                                                     ((void *)0) 
                                                          ||
     (idl->comments = calloc(num, sizeof(*idl->comments))) == 
                                                             ((void *)0)
                                                                 ) {
  r = -2;
  goto out;
 }
 for (i = 0; i < num;) {
  if ((r = deserialise_identity2(msg, &(idl->keys[i]),
      &(idl->comments[i]))) != 0) {
   if (r == -14) {

    num--;
    continue;
   } else
    goto out;
  }
  i++;
 }
 idl->nkeys = num;
 *idlp = idl;
 idl = 
      ((void *)0)
          ;
 r = 0;
 out:
 sshbuf_free(msg);
 if (idl != 
           ((void *)0)
               )
  ssh_free_identitylist(idl);
 return r;
}

void
ssh_free_identitylist(struct ssh_identitylist *idl)
{
 size_t i;

 if (idl == 
           ((void *)0)
               )
  return;
 for (i = 0; i < idl->nkeys; i++) {
  if (idl->keys != 
                  ((void *)0)
                      )
   sshkey_free(idl->keys[i]);
  if (idl->comments != 
                      ((void *)0)
                          )
   free(idl->comments[i]);
 }
 free(idl->keys);
 free(idl->comments);
 free(idl);
}





int
ssh_agent_has_key(int sock, const struct sshkey *key)
{
 int r, ret = -46;
 size_t i;
 struct ssh_identitylist *idlist = 
                                  ((void *)0)
                                      ;

 if ((r = ssh_fetch_identitylist(sock, &idlist)) != 0) {
  return r;
 }

 for (i = 0; i < idlist->nkeys; i++) {
  if (sshkey_equal_public(idlist->keys[i], key)) {
   ret = 0;
   break;
  }
 }

 ssh_free_identitylist(idlist);
 return ret;
}
static u_int
agent_encode_alg(const struct sshkey *key, const char *alg)
{
 if (alg != 
           ((void *)0) 
                && sshkey_type_plain(key->type) == KEY_RSA) {
  if (strcmp(alg, "rsa-sha2-256") == 0 ||
      strcmp(alg, "rsa-sha2-256-cert-v01@openssh.com") == 0)
   return 0x02;
  if (strcmp(alg, "rsa-sha2-512") == 0 ||
      strcmp(alg, "rsa-sha2-512-cert-v01@openssh.com") == 0)
   return 0x04;
 }
 return 0;
}


int
ssh_agent_sign(int sock, const struct sshkey *key,
    u_char **sigp, size_t *lenp,
    const u_char *data, size_t datalen, const char *alg, u_int compat)
{
 struct sshbuf *msg;
 u_char *sig = 
              ((void *)0)
                  , type = 0;
 size_t len = 0;
 u_int flags = 0;
 int r = -1;

 *sigp = 
        ((void *)0)
            ;
 *lenp = 0;

 if (datalen > (1 << 20))
  return -10;
 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  return -2;
 flags |= agent_encode_alg(key, alg);
 if ((r = sshbuf_put_u8(msg, 13)) != 0 ||
     (r = sshkey_puts(key, msg)) != 0 ||
     (r = sshbuf_put_string(msg, data, datalen)) != 0 ||
     (r = sshbuf_put_u32(msg, flags)) != 0)
  goto out;
 if ((r = ssh_request_reply(sock, msg, msg)) != 0)
  goto out;
 if ((r = sshbuf_get_u8(msg, &type)) != 0)
  goto out;
 if (((type == 5) || (type == 102) || (type == 30))) {
  r = -27;
  goto out;
 } else if (type != 14) {
  r = -4;
  goto out;
 }
 if ((r = sshbuf_get_string(msg, &sig, &len)) != 0)
  goto out;

 if ((r = sshkey_check_sigtype(sig, len, alg)) != 0)
  goto out;

 *sigp = sig;
 *lenp = len;
 sig = 
      ((void *)0)
          ;
 len = 0;
 r = 0;
 out:
 freezero(sig, len);
 sshbuf_free(msg);
 return r;
}



static int
encode_dest_constraint_hop(struct sshbuf *m,
    const struct dest_constraint_hop *dch)
{
 struct sshbuf *b;
 u_int i;
 int r;

 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              )
  return -2;
 if ((r = sshbuf_put_cstring(b, dch->user)) != 0 ||
     (r = sshbuf_put_cstring(b, dch->hostname)) != 0 ||
     (r = sshbuf_put_string(b, 
                              ((void *)0)
                                  , 0)) != 0)
  goto out;
 for (i = 0; i < dch->nkeys; i++) {
  if ((r = sshkey_puts(dch->keys[i], b)) != 0 ||
      (r = sshbuf_put_u8(b, dch->key_is_ca[i] != 0)) != 0)
   goto out;
 }
 if ((r = sshbuf_put_stringb(m, b)) != 0)
  goto out;

 r = 0;
 out:
 sshbuf_free(b);
 return r;
}

static int
encode_dest_constraint(struct sshbuf *m, const struct dest_constraint *dc)
{
 struct sshbuf *b;
 int r;

 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              )
  return -2;
 if ((r = encode_dest_constraint_hop(b, &dc->from) != 0) ||
     (r = encode_dest_constraint_hop(b, &dc->to) != 0) ||
     (r = sshbuf_put_string(b, 
                              ((void *)0)
                                  , 0)) != 0)
  goto out;
 if ((r = sshbuf_put_stringb(m, b)) != 0)
  goto out;

 r = 0;
 out:
 sshbuf_free(b);
 return r;
}

static int
encode_constraints(struct sshbuf *m, u_int life, u_int confirm, u_int maxsign,
    const char *provider, struct dest_constraint **dest_constraints,
    size_t ndest_constraints)
{
 int r;
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 size_t i;

 if (life != 0) {
  if ((r = sshbuf_put_u8(m, 1)) != 0 ||
      (r = sshbuf_put_u32(m, life)) != 0)
   goto out;
 }
 if (confirm != 0) {
  if ((r = sshbuf_put_u8(m, 2)) != 0)
   goto out;
 }
 if (maxsign != 0) {
  if ((r = sshbuf_put_u8(m, 3)) != 0 ||
      (r = sshbuf_put_u32(m, maxsign)) != 0)
   goto out;
 }
 if (provider != 
                ((void *)0)
                    ) {
  if ((r = sshbuf_put_u8(m,
      255)) != 0 ||
      (r = sshbuf_put_cstring(m,
      "sk-provider@openssh.com")) != 0 ||
      (r = sshbuf_put_cstring(m, provider)) != 0)
   goto out;
 }
 if (dest_constraints != 
                        ((void *)0) 
                             && ndest_constraints > 0) {
  if ((b = sshbuf_new()) == 
                           ((void *)0)
                               ) {
   r = -2;
   goto out;
  }
  for (i = 0; i < ndest_constraints; i++) {
   if ((r = encode_dest_constraint(b,
       dest_constraints[i])) != 0)
    goto out;
  }
  if ((r = sshbuf_put_u8(m,
      255)) != 0 ||
      (r = sshbuf_put_cstring(m,
      "restrict-destination-v00@openssh.com")) != 0 ||
      (r = sshbuf_put_stringb(m, b)) != 0)
   goto out;
 }
 r = 0;
 out:
 sshbuf_free(b);
 return r;
}





int
ssh_add_identity_constrained(int sock, struct sshkey *key,
    const char *comment, u_int life, u_int confirm, u_int maxsign,
    const char *provider, struct dest_constraint **dest_constraints,
    size_t ndest_constraints)
{
 struct sshbuf *msg;
 int r, constrained = (life || confirm || maxsign ||
     provider || dest_constraints);
 u_char type;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  return -2;

 switch (key->type) {

 case KEY_RSA:
 case KEY_RSA_CERT:
 case KEY_DSA:
 case KEY_DSA_CERT:
 case KEY_ECDSA:
 case KEY_ECDSA_CERT:
 case KEY_ECDSA_SK:
 case KEY_ECDSA_SK_CERT:

 case KEY_ED25519:
 case KEY_ED25519_CERT:
 case KEY_ED25519_SK:
 case KEY_ED25519_SK_CERT:
 case KEY_XMSS:
 case KEY_XMSS_CERT:
  type = constrained ?
      25 :
      17;
  if ((r = sshbuf_put_u8(msg, type)) != 0 ||
      (r = sshkey_private_serialize_maxsign(key, msg, maxsign,
      0)) != 0 ||
      (r = sshbuf_put_cstring(msg, comment)) != 0)
   goto out;
  break;
 default:
  r = -10;
  goto out;
 }
 if (constrained &&
     (r = encode_constraints(msg, life, confirm, maxsign,
     provider, dest_constraints, ndest_constraints)) != 0)
  goto out;
 if ((r = ssh_request_reply_decode(sock, msg)) != 0)
  goto out;

 r = 0;
 out:
 sshbuf_free(msg);
 return r;
}





int
ssh_remove_identity(int sock, const struct sshkey *key)
{
 struct sshbuf *msg;
 int r;
 u_char *blob = 
               ((void *)0)
                   ;
 size_t blen;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  return -2;

 if (key->type != KEY_UNSPEC) {
  if ((r = sshkey_to_blob(key, &blob, &blen)) != 0)
   goto out;
  if ((r = sshbuf_put_u8(msg,
      18)) != 0 ||
      (r = sshbuf_put_string(msg, blob, blen)) != 0)
   goto out;
 } else {
  r = -10;
  goto out;
 }
 if ((r = ssh_request_reply_decode(sock, msg)) != 0)
  goto out;

 r = 0;
 out:
 if (blob != 
            ((void *)0)
                )
  freezero(blob, blen);
 sshbuf_free(msg);
 return r;
}





int
ssh_update_card(int sock, int add, const char *reader_id, const char *pin,
    u_int life, u_int confirm,
    struct dest_constraint **dest_constraints, size_t ndest_constraints)
{
 struct sshbuf *msg;
 int r, constrained = (life || confirm);
 u_char type;

 if (add) {
  type = constrained ?
      26 :
      20;
 } else
  type = 21;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  return -2;
 if ((r = sshbuf_put_u8(msg, type)) != 0 ||
     (r = sshbuf_put_cstring(msg, reader_id)) != 0 ||
     (r = sshbuf_put_cstring(msg, pin)) != 0)
  goto out;
 if (constrained &&
     (r = encode_constraints(msg, life, confirm, 0, 
                                                   ((void *)0)
                                                       ,
     dest_constraints, ndest_constraints)) != 0)
  goto out;
 if ((r = ssh_request_reply_decode(sock, msg)) != 0)
  goto out;

 r = 0;
 out:
 sshbuf_free(msg);
 return r;
}
int
ssh_remove_all_identities(int sock, int version)
{
 struct sshbuf *msg;
 u_char type = (version == 1) ?
     9 :
     19;
 int r;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  return -2;
 if ((r = sshbuf_put_u8(msg, type)) != 0)
  goto out;
 if ((r = ssh_request_reply_decode(sock, msg)) != 0)
  goto out;

 r = 0;
 out:
 sshbuf_free(msg);
 return r;
}


int
ssh_agent_bind_hostkey(int sock, const struct sshkey *key,
    const struct sshbuf *session_id, const struct sshbuf *signature,
    int forwarding)
{
 struct sshbuf *msg;
 int r;

 if (key == 
           ((void *)0) 
                || session_id == 
                                 ((void *)0) 
                                      || signature == 
                                                      ((void *)0)
                                                          )
  return -10;
 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  return -2;
 if ((r = sshbuf_put_u8(msg, 27)) != 0 ||
     (r = sshbuf_put_cstring(msg, "session-bind@openssh.com")) != 0 ||
     (r = sshkey_puts(key, msg)) != 0 ||
     (r = sshbuf_put_stringb(msg, session_id)) != 0 ||
     (r = sshbuf_put_stringb(msg, signature)) != 0 ||
     (r = sshbuf_put_u8(msg, forwarding ? 1 : 0)) != 0)
  goto out;
 if ((r = ssh_request_reply_decode(sock, msg)) != 0)
  goto out;

 r = 0;
 out:
 sshbuf_free(msg);
 return r;
}
