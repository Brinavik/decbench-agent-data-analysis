











































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

void compat_banner(struct ssh *, const char *);
char *compat_cipher_proposal(struct ssh *, char *);
char *compat_pkalg_proposal(struct ssh *, char *);
char *compat_kex_proposal(struct ssh *, char *);
const char *ssh_err(int n);




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


int ssh_rsa_sign(const struct sshkey *key,
    u_char **sigp, size_t *lenp, const u_char *data, size_t datalen,
    const char *ident);
int ssh_rsa_verify(const struct sshkey *key,
    const u_char *sig, size_t siglen, const u_char *data, size_t datalen,
    const char *alg);
int ssh_dss_sign(const struct sshkey *key, u_char **sigp, size_t *lenp,
    const u_char *data, size_t datalen, u_int compat);
int ssh_dss_verify(const struct sshkey *key,
    const u_char *signature, size_t signaturelen,
    const u_char *data, size_t datalen, u_int compat);
int ssh_ecdsa_sign(const struct sshkey *key, u_char **sigp, size_t *lenp,
    const u_char *data, size_t datalen, u_int compat);
int ssh_ecdsa_verify(const struct sshkey *key,
    const u_char *signature, size_t signaturelen,
    const u_char *data, size_t datalen, u_int compat);
int ssh_ecdsa_sk_verify(const struct sshkey *key,
    const u_char *signature, size_t signaturelen,
    const u_char *data, size_t datalen, u_int compat,
    struct sshkey_sig_details **detailsp);
int ssh_ed25519_sign(const struct sshkey *key, u_char **sigp, size_t *lenp,
    const u_char *data, size_t datalen, u_int compat);
int ssh_ed25519_verify(const struct sshkey *key,
    const u_char *signature, size_t signaturelen,
    const u_char *data, size_t datalen, u_int compat);
int ssh_ed25519_sk_verify(const struct sshkey *key,
    const u_char *signature, size_t signaturelen,
    const u_char *data, size_t datalen, u_int compat,
    struct sshkey_sig_details **detailsp);
int ssh_xmss_sign(const struct sshkey *key, u_char **sigp, size_t *lenp,
    const u_char *data, size_t datalen, u_int compat);
int ssh_xmss_verify(const struct sshkey *key,
    const u_char *signature, size_t signaturelen,
    const u_char *data, size_t datalen, u_int compat);
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




int ssh_compatible_openssl(long, long);
void ssh_libcrypto_init(void);
int EVP_CIPHER_CTX_set_iv(EVP_CIPHER_CTX *ctx,
    const unsigned char *iv, size_t len);
void DSA_SIG_get0(const DSA_SIG *sig, const BIGNUM **pr, const BIGNUM **ps);



int DSA_SIG_set0(DSA_SIG *sig, BIGNUM *r, BIGNUM *s);
EVP_MD_CTX *EVP_MD_CTX_new(void);



void EVP_MD_CTX_free(EVP_MD_CTX *ctx);

static int openssh_RSA_verify(int, u_char *, size_t, u_char *, size_t, RSA *);

static const char *
rsa_hash_alg_ident(int hash_alg)
{
 switch (hash_alg) {
 case 1:
  return "ssh-rsa";
 case 2:
  return "rsa-sha2-256";
 case 4:
  return "rsa-sha2-512";
 }
 return 
       ((void *)0)
           ;
}





static int
rsa_hash_id_from_ident(const char *ident)
{
 if (strcmp(ident, "ssh-rsa") == 0)
  return 1;
 if (strcmp(ident, "rsa-sha2-256") == 0)
  return 2;
 if (strcmp(ident, "rsa-sha2-512") == 0)
  return 4;
 return -1;
}






static int
rsa_hash_id_from_keyname(const char *alg)
{
 int r;

 if ((r = rsa_hash_id_from_ident(alg)) != -1)
  return r;
 if (strcmp(alg, "ssh-rsa-cert-v01@openssh.com") == 0)
  return 1;
 if (strcmp(alg, "rsa-sha2-256-cert-v01@openssh.com") == 0)
  return 2;
 if (strcmp(alg, "rsa-sha2-512-cert-v01@openssh.com") == 0)
  return 4;
 return -1;
}

static int
rsa_hash_alg_nid(int type)
{
 switch (type) {
 case 1:
  return 
        64
                ;
 case 2:
  return 
        672
                  ;
 case 4:
  return 
        674
                  ;
 default:
  return -1;
 }
}

int
ssh_rsa_complete_crt_parameters(struct sshkey *key, const BIGNUM *iqmp)
{
 const BIGNUM *rsa_p, *rsa_q, *rsa_d;
 BIGNUM *aux = 
              ((void *)0)
                  , *d_consttime = 
                                   ((void *)0)
                                       ;
 BIGNUM *rsa_dmq1 = 
                   ((void *)0)
                       , *rsa_dmp1 = 
                                     ((void *)0)
                                         , *rsa_iqmp = 
                                                       ((void *)0)
                                                           ;
 BN_CTX *ctx = 
              ((void *)0)
                  ;
 int r;

 if (key == 
           ((void *)0) 
                || key->rsa == 
                               ((void *)0) 
                                    ||
     sshkey_type_plain(key->type) != KEY_RSA)
  return -10;

 RSA_get0_key(key->rsa, 
                       ((void *)0)
                           , 
                             ((void *)0)
                                 , &rsa_d);
 RSA_get0_factors(key->rsa, &rsa_p, &rsa_q);

 if ((ctx = BN_CTX_new()) == 
                            ((void *)0)
                                )
  return -2;
 if ((aux = BN_new()) == 
                        ((void *)0) 
                             ||
     (rsa_dmq1 = BN_new()) == 
                             ((void *)0) 
                                  ||
     (rsa_dmp1 = BN_new()) == 
                             ((void *)0)
                                 )
  return -2;
 if ((d_consttime = BN_dup(rsa_d)) == 
                                     ((void *)0) 
                                          ||
     (rsa_iqmp = BN_dup(iqmp)) == 
                                 ((void *)0)
                                     ) {
  r = -2;
  goto out;
 }
 BN_set_flags(aux, 
                  0x04
                                  );
 BN_set_flags(d_consttime, 
                          0x04
                                          );

 if ((BN_sub(aux, rsa_q, BN_value_one()) == 0) ||
     (
     BN_div(((void *)0),(
     rsa_dmq1
     ),(
     d_consttime
     ),(
     aux
     ),(
     ctx
     )) 
                                             == 0) ||
     (BN_sub(aux, rsa_p, BN_value_one()) == 0) ||
     (
     BN_div(((void *)0),(
     rsa_dmp1
     ),(
     d_consttime
     ),(
     aux
     ),(
     ctx
     )) 
                                             == 0)) {
  r = -22;
  goto out;
 }
 if (!RSA_set0_crt_params(key->rsa, rsa_dmp1, rsa_dmq1, rsa_iqmp)) {
  r = -22;
  goto out;
 }
 rsa_dmp1 = rsa_dmq1 = rsa_iqmp = 
                                 ((void *)0)
                                     ;

 r = 0;
 out:
 BN_clear_free(aux);
 BN_clear_free(d_consttime);
 BN_clear_free(rsa_dmp1);
 BN_clear_free(rsa_dmq1);
 BN_clear_free(rsa_iqmp);
 BN_CTX_free(ctx);
 return r;
}


int
ssh_rsa_sign(const struct sshkey *key, u_char **sigp, size_t *lenp,
    const u_char *data, size_t datalen, const char *alg_ident)
{
 const BIGNUM *rsa_n;
 u_char digest[64], *sig = 
                                             ((void *)0)
                                                 ;
 size_t slen = 0;
 u_int dlen, len;
 int nid, hash_alg, ret = -1;
 struct sshbuf *b = 
                   ((void *)0)
                       ;

 if (lenp != 
            ((void *)0)
                )
  *lenp = 0;
 if (sigp != 
            ((void *)0)
                )
  *sigp = 
         ((void *)0)
             ;

 if (alg_ident == 
                 ((void *)0) 
                      || strlen(alg_ident) == 0)
  hash_alg = 1;
 else
  hash_alg = rsa_hash_id_from_keyname(alg_ident);
 if (key == 
           ((void *)0) 
                || key->rsa == 
                               ((void *)0) 
                                    || hash_alg == -1 ||
     sshkey_type_plain(key->type) != KEY_RSA)
  return -10;
 RSA_get0_key(key->rsa, &rsa_n, 
                               ((void *)0)
                                   , 
                                     ((void *)0)
                                         );
 if (BN_num_bits(rsa_n) < 1024)
  return -56;
 slen = RSA_size(key->rsa);
 if (slen <= 0 || slen > (16384 / 8))
  return -10;


 nid = rsa_hash_alg_nid(hash_alg);
 if ((dlen = ssh_digest_bytes(hash_alg)) == 0)
  return -1;
 if ((ret = ssh_digest_memory(hash_alg, data, datalen,
     digest, sizeof(digest))) != 0)
  goto out;

 if ((sig = malloc(slen)) == 
                            ((void *)0)
                                ) {
  ret = -2;
  goto out;
 }

 if (RSA_sign(nid, digest, dlen, sig, &len, key->rsa) != 1) {
  ret = -22;
  goto out;
 }
 if (len < slen) {
  size_t diff = slen - len;
  memmove(sig + diff, sig, len);
  explicit_bzero(sig, diff);
 } else if (len > slen) {
  ret = -1;
  goto out;
 }

 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              ) {
  ret = -2;
  goto out;
 }
 if ((ret = sshbuf_put_cstring(b, rsa_hash_alg_ident(hash_alg))) != 0 ||
     (ret = sshbuf_put_string(b, sig, slen)) != 0)
  goto out;
 len = sshbuf_len(b);
 if (sigp != 
            ((void *)0)
                ) {
  if ((*sigp = malloc(len)) == 
                              ((void *)0)
                                  ) {
   ret = -2;
   goto out;
  }
  memcpy(*sigp, sshbuf_ptr(b), len);
 }
 if (lenp != 
            ((void *)0)
                )
  *lenp = len;
 ret = 0;
 out:
 explicit_bzero(digest, sizeof(digest));
 freezero(sig, slen);
 sshbuf_free(b);
 return ret;
}

int
ssh_rsa_verify(const struct sshkey *key,
    const u_char *sig, size_t siglen, const u_char *data, size_t datalen,
    const char *alg)
{
 const BIGNUM *rsa_n;
 char *sigtype = 
                ((void *)0)
                    ;
 int hash_alg, want_alg, ret = -1;
 size_t len = 0, diff, modlen, dlen;
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 u_char digest[64], *osigblob, *sigblob = 
                                                            ((void *)0)
                                                                ;

 if (key == 
           ((void *)0) 
                || key->rsa == 
                               ((void *)0) 
                                    ||
     sshkey_type_plain(key->type) != KEY_RSA ||
     sig == 
           ((void *)0) 
                || siglen == 0)
  return -10;
 RSA_get0_key(key->rsa, &rsa_n, 
                               ((void *)0)
                                   , 
                                     ((void *)0)
                                         );
 if (BN_num_bits(rsa_n) < 1024)
  return -56;

 if ((b = sshbuf_from(sig, siglen)) == 
                                      ((void *)0)
                                          )
  return -2;
 if (sshbuf_get_cstring(b, &sigtype, 
                                    ((void *)0)
                                        ) != 0) {
  ret = -4;
  goto out;
 }
 if ((hash_alg = rsa_hash_id_from_ident(sigtype)) == -1) {
  ret = -13;
  goto out;
 }




 if (alg != 
           ((void *)0) 
                && strcmp(alg, "ssh-rsa-cert-v01@openssh.com") != 0) {
  if ((want_alg = rsa_hash_id_from_keyname(alg)) == -1) {
   ret = -10;
   goto out;
  }
  if (hash_alg != want_alg) {
   ret = -21;
   goto out;
  }
 }
 if (sshbuf_get_string(b, &sigblob, &len) != 0) {
  ret = -4;
  goto out;
 }
 if (sshbuf_len(b) != 0) {
  ret = -23;
  goto out;
 }

 modlen = RSA_size(key->rsa);
 if (len > modlen) {
  ret = -11;
  goto out;
 } else if (len < modlen) {
  diff = modlen - len;
  osigblob = sigblob;
  if ((sigblob = realloc(sigblob, modlen)) == 
                                             ((void *)0)
                                                 ) {
   sigblob = osigblob;
   ret = -2;
   goto out;
  }
  memmove(sigblob + diff, sigblob, len);
  explicit_bzero(sigblob, diff);
  len = modlen;
 }
 if ((dlen = ssh_digest_bytes(hash_alg)) == 0) {
  ret = -1;
  goto out;
 }
 if ((ret = ssh_digest_memory(hash_alg, data, datalen,
     digest, sizeof(digest))) != 0)
  goto out;

 ret = openssh_RSA_verify(hash_alg, digest, dlen, sigblob, len,
     key->rsa);
 out:
 freezero(sigblob, len);
 free(sigtype);
 sshbuf_free(b);
 explicit_bzero(digest, sizeof(digest));
 return ret;
}
static const u_char id_sha1[] = {
 0x30, 0x21,
 0x30, 0x09,
 0x06, 0x05,
 0x2b, 0x0e, 0x03, 0x02, 0x1a,
 0x05, 0x00,
 0x04, 0x14
};







static const u_char id_sha256[] = {
 0x30, 0x31,
 0x30, 0x0d,
 0x06, 0x09,
 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01,
 0x05, 0x00,
 0x04, 0x20
};







static const u_char id_sha512[] = {
 0x30, 0x51,
 0x30, 0x0d,
 0x06, 0x09,
 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x03,
 0x05, 0x00,
 0x04, 0x40
};

static int
rsa_hash_alg_oid(int hash_alg, const u_char **oidp, size_t *oidlenp)
{
 switch (hash_alg) {
 case 1:
  *oidp = id_sha1;
  *oidlenp = sizeof(id_sha1);
  break;
 case 2:
  *oidp = id_sha256;
  *oidlenp = sizeof(id_sha256);
  break;
 case 4:
  *oidp = id_sha512;
  *oidlenp = sizeof(id_sha512);
  break;
 default:
  return -10;
 }
 return 0;
}

static int
openssh_RSA_verify(int hash_alg, u_char *hash, size_t hashlen,
    u_char *sigbuf, size_t siglen, RSA *rsa)
{
 size_t rsasize = 0, oidlen = 0, hlen = 0;
 int ret, len, oidmatch, hashmatch;
 const u_char *oid = 
                    ((void *)0)
                        ;
 u_char *decrypted = 
                    ((void *)0)
                        ;

 if ((ret = rsa_hash_alg_oid(hash_alg, &oid, &oidlen)) != 0)
  return ret;
 ret = -1;
 hlen = ssh_digest_bytes(hash_alg);
 if (hashlen != hlen) {
  ret = -10;
  goto done;
 }
 rsasize = RSA_size(rsa);
 if (rsasize <= 0 || rsasize > (16384 / 8) ||
     siglen == 0 || siglen > rsasize) {
  ret = -10;
  goto done;
 }
 if ((decrypted = malloc(rsasize)) == 
                                     ((void *)0)
                                         ) {
  ret = -2;
  goto done;
 }
 if ((len = RSA_public_decrypt(siglen, sigbuf, decrypted, rsa,
     
    1
                     )) < 0) {
  ret = -22;
  goto done;
 }
 if (len < 0 || (size_t)len != hlen + oidlen) {
  ret = -4;
  goto done;
 }
 oidmatch = timingsafe_bcmp(decrypted, oid, oidlen) == 0;
 hashmatch = timingsafe_bcmp(decrypted + oidlen, hash, hlen) == 0;
 if (!oidmatch || !hashmatch) {
  ret = -21;
  goto done;
 }
 ret = 0;
done:
 freezero(decrypted, rsasize);
 return ret;
}
