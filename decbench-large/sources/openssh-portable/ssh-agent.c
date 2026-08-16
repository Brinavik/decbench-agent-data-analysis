











































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

int pkcs11_init(int);
void pkcs11_terminate(void);
int pkcs11_add_provider(char *, char *, struct sshkey ***, char ***);
int pkcs11_del_provider(char *);
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
typedef enum {
 AUTH_UNUSED = 0,
 AUTH_SOCKET = 1,
 AUTH_CONNECTION = 2,
} sock_type;

struct hostkey_sid {
 struct sshkey *key;
 struct sshbuf *sid;
 int forwarded;
};

typedef struct socket_entry {
 int fd;
 sock_type type;
 struct sshbuf *input;
 struct sshbuf *output;
 struct sshbuf *request;
 size_t nsession_ids;
 struct hostkey_sid *session_ids;
} SocketEntry;

u_int sockets_alloc = 0;
SocketEntry *sockets = 
                      ((void *)0)
                          ;

typedef struct identity {
 struct { struct identity *tqe_next; struct identity **tqe_prev; } next;
 struct sshkey *key;
 char *comment;
 char *provider;
 time_t death;
 u_int confirm;
 char *sk_provider;
 struct dest_constraint *dest_constraints;
 size_t ndest_constraints;
} Identity;

struct idtable {
 int nentries;
 struct idqueue { struct identity *tqh_first; struct identity **tqh_last; } idlist;
};


struct idtable *idtab;

int max_fd = 0;


pid_t parent_pid = -1;
time_t parent_alive_interval = 0;


pid_t cleanup_pid = 0;


char socket_name[
                4096
                        ];
char socket_dir[
               4096
                       ];


static char *allowed_providers;





int locked = 0;
u_char lock_pwhash[32];
u_char lock_salt[16];

extern char *__progname;


static int lifetime = 0;

static int fingerprint_hash = 2;


static int restrict_websafe = 1;

static void
close_socket(SocketEntry *e)
{
 size_t i;

 close(e->fd);
 sshbuf_free(e->input);
 sshbuf_free(e->output);
 sshbuf_free(e->request);
 for (i = 0; i < e->nsession_ids; i++) {
  sshkey_free(e->session_ids[i].key);
  sshbuf_free(e->session_ids[i].sid);
 }
 free(e->session_ids);
 memset(e, '\0', sizeof(*e));
 e->fd = -1;
 e->type = AUTH_UNUSED;
}

static void
idtab_init(void)
{
 idtab = xcalloc(1, sizeof(*idtab));
 do { (&idtab->idlist)->tqh_first = 
((void *)0)
; (&idtab->idlist)->tqh_last = &(&idtab->idlist)->tqh_first; } while (0);
 idtab->nentries = 0;
}

static void
free_dest_constraint_hop(struct dest_constraint_hop *dch)
{
 u_int i;

 if (dch == 
           ((void *)0)
               )
  return;
 free(dch->user);
 free(dch->hostname);
 for (i = 0; i < dch->nkeys; i++)
  sshkey_free(dch->keys[i]);
 free(dch->keys);
 free(dch->key_is_ca);
}

static void
free_dest_constraints(struct dest_constraint *dcs, size_t ndcs)
{
 size_t i;

 for (i = 0; i < ndcs; i++) {
  free_dest_constraint_hop(&dcs[i].from);
  free_dest_constraint_hop(&dcs[i].to);
 }
 free(dcs);
}

static void
free_identity(Identity *id)
{
 sshkey_free(id->key);
 free(id->provider);
 free(id->comment);
 free(id->sk_provider);
 free_dest_constraints(id->dest_constraints, id->ndest_constraints);
 free(id);
}





static int
match_key_hop(const char *tag, const struct sshkey *key,
    const struct dest_constraint_hop *dch)
{
 const char *reason = 
                     ((void *)0)
                         ;
 const char *hostname = dch->hostname ? dch->hostname : "(ORIGIN)";
 u_int i;
 char *fp;

 if (key == 
           ((void *)0)
               )
  return -1;

 if ((fp = sshkey_fingerprint(key, 2,
     SSH_FP_DEFAULT)) == 
                        ((void *)0)
                            )
  sshfatal("ssh-agent.c", __func__, 275, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "fingerprint failed");
 sshlog("ssh-agent.c", __func__, 276, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s: entering hostname %s, requested key %s %s, %u keys avail", tag, hostname, sshkey_type(key), fp, dch->nkeys)
                                                     ;
 free(fp);
 for (i = 0; i < dch->nkeys; i++) {
  if (dch->keys[i] == 
                     ((void *)0)
                         )
   return -1;

  if ((fp = sshkey_fingerprint(dch->keys[i], 2,
      SSH_FP_DEFAULT)) == 
                         ((void *)0)
                             )
   sshfatal("ssh-agent.c", __func__, 285, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "fingerprint failed");
  sshlog("ssh-agent.c", __func__, 286, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "%s: key %u: %s%s %s", tag, i, dch->key_is_ca[i] ? "CA " : "", sshkey_type(dch->keys[i]), fp)

                                    ;
  free(fp);
  if (!sshkey_is_cert(key)) {

   if (dch->key_is_ca[i] ||
       !sshkey_equal(key, dch->keys[i]))
    continue;
   return 0;
  }

  if (!dch->key_is_ca[i])
   continue;
  if (key->cert == 
                  ((void *)0) 
                       || key->cert->signature_key == 
                                                      ((void *)0)
                                                          )
   return -1;
  if (!sshkey_equal(key->cert->signature_key, dch->keys[i]))
   continue;
  if (sshkey_cert_check_host(key, hostname, 1,
      "ssh-ed25519," "ecdsa-sha2-nistp256," "ecdsa-sha2-nistp384," "ecdsa-sha2-nistp521," "sk-ssh-ed25519@openssh.com," "sk-ecdsa-sha2-nistp256@openssh.com," "rsa-sha2-512," "rsa-sha2-256", &reason) != 0) {
   sshlog("ssh-agent.c", __func__, 306, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "cert %s / hostname %s rejected: %s", key->cert->key_id, hostname, reason)
                                           ;
   continue;
  }
  return 0;
 }
 return -1;
}


static int
permitted_by_dest_constraints(const struct sshkey *fromkey,
    const struct sshkey *tokey, Identity *id, const char *user,
    const char **hostnamep)
{
 size_t i;
 struct dest_constraint *d;

 if (hostnamep != 
                 ((void *)0)
                     )
  *hostnamep = 
              ((void *)0)
                  ;
 for (i = 0; i < id->ndest_constraints; i++) {
  d = id->dest_constraints + i;

  sshlog("ssh-agent.c", __func__, 329, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "constraint %zu %s%s%s (%u keys) > %s%s%s (%u keys)", i, d->from.user ? d->from.user : "", d->from.user ? "@" : "", d->from.hostname ? d->from.hostname : "(ORIGIN)", d->from.nkeys, d->to.user ? d->to.user : "", d->to.user ? "@" : "", d->to.hostname ? d->to.hostname : "(ANY)", d->to.nkeys)





                                                             ;


  if (fromkey == 
                ((void *)0)
                    ) {

   if (d->from.hostname != 
                          ((void *)0) 
                               || d->from.nkeys != 0)
    continue;
  } else if (match_key_hop("from", fromkey, &d->from) != 0)
   continue;


  if (tokey != 
              ((void *)0) 
                   && match_key_hop("to", tokey, &d->to) != 0)
   continue;


  if (d->to.user != 
                   ((void *)0) 
                        && user != 
                                   ((void *)0) 
                                        &&
      !match_pattern(user, d->to.user))
   continue;


  if (hostnamep != 
                  ((void *)0)
                      )
   *hostnamep = d->to.hostname;
  sshlog("ssh-agent.c", __func__, 357, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "allowed for hostname %s", d->to.hostname == 
 ((void *)0) 
 ? "*" : d->to.hostname)
                                                    ;
  return 0;
 }

 sshlog("ssh-agent.c", __func__, 362, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "%s identity \"%s\" not permitted for this destination", sshkey_type(id->key), id->comment)
                                       ;
 return -1;
}






static int
identity_permitted(Identity *id, SocketEntry *e, char *user,
    const char **forward_hostnamep, const char **last_hostnamep)
{
 size_t i;
 const char **hp;
 struct hostkey_sid *hks;
 const struct sshkey *fromkey = 
                               ((void *)0)
                                   ;
 const char *test_user;
 char *fp1, *fp2;


 sshlog("ssh-agent.c", __func__, 384, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "entering: key %s comment \"%s\", %zu socket bindings, " "%zu constraints", sshkey_type(id->key), id->comment, e->nsession_ids, id->ndest_constraints)

                                            ;
 if (id->ndest_constraints == 0)
  return 0;
 if (e->nsession_ids == 0)
  return 0;




 for (i = 0; i < e->nsession_ids; i++) {
  hks = e->session_ids + i;
  if (hks->key == 
                 ((void *)0)
                     )
   sshfatal("ssh-agent.c", __func__, 398, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "internal error: no bound key");

  fp1 = fp2 = 
             ((void *)0)
                 ;
  if (fromkey != 
                ((void *)0) 
                     &&
      (fp1 = sshkey_fingerprint(fromkey, 2,
      SSH_FP_DEFAULT)) == 
                         ((void *)0)
                             )
   sshfatal("ssh-agent.c", __func__, 404, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "fingerprint failed");
  if ((fp2 = sshkey_fingerprint(hks->key, 2,
      SSH_FP_DEFAULT)) == 
                         ((void *)0)
                             )
   sshfatal("ssh-agent.c", __func__, 407, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "fingerprint failed");
  sshlog("ssh-agent.c", __func__, 408, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "socketentry fd=%d, entry %zu %s, " "from hostkey %s %s to user %s hostkey %s %s", e->fd, i, hks->forwarded ? "FORWARD" : "AUTH", fromkey ? sshkey_type(fromkey) : "(ORIGIN)", fromkey ? fp1 : "", user ? user : "(ANY)", sshkey_type(hks->key), fp2)




                                 ;
  free(fp1);
  free(fp2);




  hp = 
      ((void *)0)
          ;
  if (i == e->nsession_ids - 1)
   hp = last_hostnamep;
  else if (i == 0)
   hp = forward_hostnamep;

  test_user = 
             ((void *)0)
                 ;
  if (i == e->nsession_ids - 1) {

   test_user = user;





   if (hks->forwarded && user != 
                                ((void *)0)
                                    ) {
    sshlog("ssh-agent.c", __func__, 436, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "tried to sign on forwarding hop");
    return -1;
   }
  } else if (!hks->forwarded) {
   sshlog("ssh-agent.c", __func__, 440, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "tried to forward though signing bind");
   return -1;
  }
  if (permitted_by_dest_constraints(fromkey, hks->key, id,
      test_user, hp) != 0)
   return -1;
  fromkey = hks->key;
 }
 hks = &e->session_ids[e->nsession_ids - 1];
 if (hks->forwarded && user == 
                              ((void *)0) 
                                   &&
     permitted_by_dest_constraints(hks->key, 
                                            ((void *)0)
                                                , id,
     
    ((void *)0)
        , 
          ((void *)0)
              ) != 0) {
  sshlog("ssh-agent.c", __func__, 460, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "key permitted at host but not after");
  return -1;
 }


 return 0;
}


static Identity *
lookup_identity(struct sshkey *key)
{
 Identity *id;

 for((id) = ((&idtab->idlist)->tqh_first); (id) != 
((void *)0)
; (id) = ((id)->next.tqe_next)) {
  if (sshkey_equal(key, id->key))
   return (id);
 }
 return (
        ((void *)0)
            );
}


static int
confirm_key(Identity *id, const char *extra)
{
 char *p;
 int ret = -1;

 p = sshkey_fingerprint(id->key, fingerprint_hash, SSH_FP_DEFAULT);
 if (p != 
         ((void *)0) 
              &&
     ask_permission("Allow use of key %s?\nKey fingerprint %s.%s%s",
     id->comment, p,
     extra == 
             ((void *)0) 
                  ? "" : "\n", extra == 
                                        ((void *)0) 
                                             ? "" : extra))
  ret = 0;
 free(p);

 return (ret);
}

static void
send_status(SocketEntry *e, int success)
{
 int r;

 if ((r = sshbuf_put_u32(e->output, 1)) != 0 ||
     (r = sshbuf_put_u8(e->output, success ?
     6 : 5)) != 0)
  sshfatal("ssh-agent.c", __func__, 507, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
}


static void
process_request_identities(SocketEntry *e)
{
 Identity *id;
 struct sshbuf *msg, *keys;
 int r;
 u_int nentries = 0;

 sshlog("ssh-agent.c", __func__, 519, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "entering");

 if ((msg = sshbuf_new()) == 
                            ((void *)0) 
                                 || (keys = sshbuf_new()) == 
                                                             ((void *)0)
                                                                 )
  sshfatal("ssh-agent.c", __func__, 522, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 for((id) = ((&idtab->idlist)->tqh_first); (id) != 
((void *)0)
; (id) = ((id)->next.tqe_next)) {

  if (identity_permitted(id, e, 
                               ((void *)0)
                                   , 
                                     ((void *)0)
                                         , 
                                           ((void *)0)
                                               ) != 0)
   continue;
  if ((r = sshkey_puts_opts(id->key, keys,
      SSHKEY_SERIALIZE_INFO)) != 0 ||
      (r = sshbuf_put_cstring(keys, id->comment)) != 0) {
   sshlog("ssh-agent.c", __func__, 530, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "compose key/comment");
   continue;
  }
  nentries++;
 }
 sshlog("ssh-agent.c", __func__, 535, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "replying with %u allowed of %u available keys", nentries, idtab->nentries)
                               ;
 if ((r = sshbuf_put_u8(msg, 12)) != 0 ||
     (r = sshbuf_put_u32(msg, nentries)) != 0 ||
     (r = sshbuf_putb(msg, keys)) != 0)
  sshfatal("ssh-agent.c", __func__, 540, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 if ((r = sshbuf_put_stringb(e->output, msg)) != 0)
  sshfatal("ssh-agent.c", __func__, 542, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "enqueue");
 sshbuf_free(msg);
 sshbuf_free(keys);
}


static char *
agent_decode_alg(struct sshkey *key, u_int flags)
{
 if (key->type == KEY_RSA) {
  if (flags & 0x02)
   return "rsa-sha2-256";
  else if (flags & 0x04)
   return "rsa-sha2-512";
 } else if (key->type == KEY_RSA_CERT) {
  if (flags & 0x02)
   return "rsa-sha2-256-cert-v01@openssh.com";
  else if (flags & 0x04)
   return "rsa-sha2-512-cert-v01@openssh.com";
 }
 return 
       ((void *)0)
           ;
}
static int
parse_userauth_request(struct sshbuf *msg, const struct sshkey *expected_key,
    char **userp, struct sshbuf **sess_idp, struct sshkey **hostkeyp)
{
 struct sshbuf *b = 
                   ((void *)0)
                       , *sess_id = 
                                    ((void *)0)
                                        ;
 char *user = 
             ((void *)0)
                 , *service = 
                              ((void *)0)
                                  , *method = 
                                              ((void *)0)
                                                  , *pkalg = 
                                                             ((void *)0)
                                                                 ;
 int r;
 u_char t, sig_follows;
 struct sshkey *mkey = 
                      ((void *)0)
                          , *hostkey = 
                                       ((void *)0)
                                           ;

 if (userp != 
             ((void *)0)
                 )
  *userp = 
          ((void *)0)
              ;
 if (sess_idp != 
                ((void *)0)
                    )
  *sess_idp = 
             ((void *)0)
                 ;
 if (hostkeyp != 
                ((void *)0)
                    )
  *hostkeyp = 
             ((void *)0)
                 ;
 if ((b = sshbuf_fromb(msg)) == 
                               ((void *)0)
                                   )
  sshfatal("ssh-agent.c", __func__, 589, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_fromb");


 if ((r = sshbuf_froms(b, &sess_id)) != 0)
  goto out;
 if (sshbuf_len(sess_id) == 0) {
  r = -4;
  goto out;
 }
 if ((r = sshbuf_get_u8(b, &t)) != 0 ||
     (r = sshbuf_get_cstring(b, &user, 
                                      ((void *)0)
                                          )) != 0 ||
     (r = sshbuf_get_cstring(b, &service, 
                                         ((void *)0)
                                             )) != 0 ||
     (r = sshbuf_get_cstring(b, &method, 
                                        ((void *)0)
                                            )) != 0 ||
     (r = sshbuf_get_u8(b, &sig_follows)) != 0 ||
     (r = sshbuf_get_cstring(b, &pkalg, 
                                       ((void *)0)
                                           )) != 0 ||
     (r = sshkey_froms(b, &mkey)) != 0)
  goto out;
 if (t != 50 ||
     sig_follows != 1 ||
     strcmp(service, "ssh-connection") != 0 ||
     !sshkey_equal(expected_key, mkey) ||
     sshkey_type_from_name(pkalg) != expected_key->type) {
  r = -4;
  goto out;
 }
 if (strcmp(method, "publickey-hostbound-v00@openssh.com") == 0) {
  if ((r = sshkey_froms(b, &hostkey)) != 0)
   goto out;
 } else if (strcmp(method, "publickey") != 0) {
  r = -4;
  goto out;
 }
 if (sshbuf_len(b) != 0) {
  r = -4;
  goto out;
 }

 r = 0;
 sshlog("ssh-agent.c", __func__, 627, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "well formed userauth");
 if (userp != 
             ((void *)0)
                 ) {
  *userp = user;
  user = 
        ((void *)0)
            ;
 }
 if (sess_idp != 
                ((void *)0)
                    ) {
  *sess_idp = sess_id;
  sess_id = 
           ((void *)0)
               ;
 }
 if (hostkeyp != 
                ((void *)0)
                    ) {
  *hostkeyp = hostkey;
  hostkey = 
           ((void *)0)
               ;
 }
 out:
 sshbuf_free(b);
 sshbuf_free(sess_id);
 free(user);
 free(service);
 free(method);
 free(pkalg);
 sshkey_free(mkey);
 sshkey_free(hostkey);
 return r;
}





static int
parse_sshsig_request(struct sshbuf *msg)
{
 int r;
 struct sshbuf *b;

 if ((b = sshbuf_fromb(msg)) == 
                               ((void *)0)
                                   )
  sshfatal("ssh-agent.c", __func__, 663, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_fromb");

 if ((r = sshbuf_cmp(b, 0, "SSHSIG", 6)) != 0 ||
     (r = sshbuf_consume(b, 6)) != 0 ||
     (r = sshbuf_get_cstring(b, 
                               ((void *)0)
                                   , 
                                     ((void *)0)
                                         )) != 0 ||
     (r = sshbuf_get_string_direct(b, 
                                     ((void *)0)
                                         , 
                                           ((void *)0)
                                               )) != 0 ||
     (r = sshbuf_get_cstring(b, 
                               ((void *)0)
                                   , 
                                     ((void *)0)
                                         )) != 0 ||
     (r = sshbuf_get_string_direct(b, 
                                     ((void *)0)
                                         , 
                                           ((void *)0)
                                               )) != 0)
  goto out;
 if (sshbuf_len(b) != 0) {
  r = -4;
  goto out;
 }

 r = 0;
 out:
 sshbuf_free(b);
 return r;
}
static int
check_websafe_message_contents(struct sshkey *key, struct sshbuf *data)
{
 if (parse_userauth_request(data, key, 
                                      ((void *)0)
                                          , 
                                            ((void *)0)
                                                , 
                                                  ((void *)0)
                                                      ) == 0) {
  sshlog("ssh-agent.c", __func__, 694, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "signed data matches public key userauth request");
  return 1;
 }
 if (parse_sshsig_request(data) == 0) {
  sshlog("ssh-agent.c", __func__, 698, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "signed data matches SSHSIG signature request");
  return 1;
 }



 sshlog("ssh-agent.c", __func__, 704, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "web-origin key attempting to sign non-SSH message");
 return 0;
}

static int
buf_equal(const struct sshbuf *a, const struct sshbuf *b)
{
 if (sshbuf_ptr(a) == 
                     ((void *)0) 
                          || sshbuf_ptr(b) == 
                                              ((void *)0)
                                                  )
  return -10;
 if (sshbuf_len(a) != sshbuf_len(b))
  return -4;
 if (timingsafe_bcmp(sshbuf_ptr(a), sshbuf_ptr(b), sshbuf_len(a)) != 0)
  return -4;
 return 0;
}


static void
process_sign_request2(SocketEntry *e)
{
 u_char *signature = 
                    ((void *)0)
                        ;
 size_t slen = 0;
 u_int compat = 0, flags;
 int r, ok = -1, retried = 0;
 char *fp = 
           ((void *)0)
               , *pin = 
                        ((void *)0)
                            , *prompt = 
                                        ((void *)0)
                                            ;
 char *user = 
             ((void *)0)
                 , *sig_dest = 
                               ((void *)0)
                                   ;
 const char *fwd_host = 
                       ((void *)0)
                           , *dest_host = 
                                          ((void *)0)
                                              ;
 struct sshbuf *msg = 
                     ((void *)0)
                         , *data = 
                                   ((void *)0)
                                       , *sid = 
                                                ((void *)0)
                                                    ;
 struct sshkey *key = 
                     ((void *)0)
                         , *hostkey = 
                                      ((void *)0)
                                          ;
 struct identity *id;
 struct notifier_ctx *notifier = 
                                ((void *)0)
                                    ;

 sshlog("ssh-agent.c", __func__, 736, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "entering");

 if ((msg = sshbuf_new()) == 
                            ((void *)0) 
                                 || (data = sshbuf_new()) == 
                                                             ((void *)0)
                                                                 )
  sshfatal("ssh-agent.c", __func__, 739, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshkey_froms(e->request, &key)) != 0 ||
     (r = sshbuf_get_stringb(e->request, data)) != 0 ||
     (r = sshbuf_get_u32(e->request, &flags)) != 0) {
  sshlog("ssh-agent.c", __func__, 743, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse");
  goto send;
 }

 if ((id = lookup_identity(key)) == 
                                   ((void *)0)
                                       ) {
  sshlog("ssh-agent.c", __func__, 748, 1, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "%s key not found", sshkey_type(key));
  goto send;
 }
 if ((fp = sshkey_fingerprint(key, 2,
     SSH_FP_DEFAULT)) == 
                        ((void *)0)
                            )
  sshfatal("ssh-agent.c", __func__, 753, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "fingerprint failed");

 if (id->ndest_constraints != 0) {
  if (e->nsession_ids == 0) {
   sshlog("ssh-agent.c", __func__, 757, 1, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "refusing use of destination-constrained key " "to sign on unbound connection")
                                       ;
   goto send;
  }
  if (parse_userauth_request(data, key, &user, &sid,
      &hostkey) != 0) {
   sshlog("ssh-agent.c", __func__, 763, 1, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "refusing use of destination-constrained key " "to sign an unidentified signature")
                                          ;
   goto send;
  }

  sshlog("ssh-agent.c", __func__, 768, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "user=%s", user);
  if (identity_permitted(id, e, user, &fwd_host, &dest_host) != 0)
   goto send;






  if (buf_equal(sid,
      e->session_ids[e->nsession_ids - 1].sid) != 0) {
   sshlog("ssh-agent.c", __func__, 779, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "unexpected session ID (%zu listed) on " "signature request for target user %s with " "key %s %s", e->nsession_ids, user, sshkey_type(id->key), fp)


                                ;
   goto send;
  }





  if (e->nsession_ids > 1 && hostkey == 
                                       ((void *)0)
                                           ) {
   sshlog("ssh-agent.c", __func__, 791, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "refusing use of destination-constrained key: " "no hostkey recorded in signature for forwarded " "connection")

                    ;
   goto send;
  }
  if (hostkey != 
                ((void *)0) 
                     && !sshkey_equal(hostkey,
      e->session_ids[e->nsession_ids - 1].key)) {
   sshlog("ssh-agent.c", __func__, 798, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "refusing use of destination-constrained key: " "mismatch between hostkey in request and most " "recently bound session")

                                ;
   goto send;
  }
  xasprintf(&sig_dest, "public key authentication request for "
      "user \"%s\" to listed host", user);
 }
 if (id->confirm && confirm_key(id, sig_dest) != 0) {
  sshlog("ssh-agent.c", __func__, 807, 1, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "user refused key");
  goto send;
 }
 if (sshkey_is_sk(id->key)) {
  if (restrict_websafe &&
      strncmp(id->key->sk_application, "ssh:", 4) != 0 &&
      !check_websafe_message_contents(key, data)) {

   goto send;
  }
  if (id->key->sk_flags & 0x01) {
   notifier = notify_start(0,
       "Confirm user presence for key %s %s%s%s",
       sshkey_type(id->key), fp,
       sig_dest == 
                  ((void *)0) 
                       ? "" : "\n",
       sig_dest == 
                  ((void *)0) 
                       ? "" : sig_dest);
  }
 }
 retry_pin:
 if ((r = sshkey_sign(id->key, &signature, &slen,
     sshbuf_ptr(data), sshbuf_len(data), agent_decode_alg(key, flags),
     id->sk_provider, pin, compat)) != 0) {
  sshlog("ssh-agent.c", __func__, 829, 1, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "sshkey_sign");
  if (pin == 
            ((void *)0) 
                 && !retried && sshkey_is_sk(id->key) &&
      r == -43) {
   notify_complete(notifier, 
                            ((void *)0)
                                );
   notifier = 
             ((void *)0)
                 ;

   xasprintf(&prompt, "Enter PIN%sfor %s key %s: ",
       (id->key->sk_flags & 0x01) ?
       " and confirm user presence " : " ",
       sshkey_type(id->key), fp);
   pin = read_passphrase(prompt, 0x0008);
   retried = 1;
   goto retry_pin;
  }
  sshlog("ssh-agent.c", __func__, 843, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshkey_sign");
  goto send;
 }

 ok = 0;
 send:
 sshlog("ssh-agent.c", __func__, 849, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "good signature");
 notify_complete(notifier, "User presence confirmed");

 if (ok == 0) {
  if ((r = sshbuf_put_u8(msg, 14)) != 0 ||
      (r = sshbuf_put_string(msg, signature, slen)) != 0)
   sshfatal("ssh-agent.c", __func__, 855, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 } else if ((r = sshbuf_put_u8(msg, 5)) != 0)
  sshfatal("ssh-agent.c", __func__, 857, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose failure");

 if ((r = sshbuf_put_stringb(e->output, msg)) != 0)
  sshfatal("ssh-agent.c", __func__, 860, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "enqueue");

 sshbuf_free(sid);
 sshbuf_free(data);
 sshbuf_free(msg);
 sshkey_free(key);
 sshkey_free(hostkey);
 free(fp);
 free(signature);
 free(sig_dest);
 free(user);
 free(prompt);
 if (pin != 
           ((void *)0)
               )
  freezero(pin, strlen(pin));
}


static void
process_remove_identity(SocketEntry *e)
{
 int r, success = 0;
 struct sshkey *key = 
                     ((void *)0)
                         ;
 Identity *id;

 sshlog("ssh-agent.c", __func__, 884, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "entering");
 if ((r = sshkey_froms(e->request, &key)) != 0) {
  sshlog("ssh-agent.c", __func__, 886, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse key");
  goto done;
 }
 if ((id = lookup_identity(key)) == 
                                   ((void *)0)
                                       ) {
  sshlog("ssh-agent.c", __func__, 890, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "key not found");
  goto done;
 }

 if (identity_permitted(id, e, 
                              ((void *)0)
                                  , 
                                    ((void *)0)
                                        , 
                                          ((void *)0)
                                              ) != 0)
  goto done;

 if (idtab->nentries < 1)
  sshfatal("ssh-agent.c", __func__, 898, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "internal error: nentries %d", idtab->nentries);
 do { if (((id)->next.tqe_next) != 
((void *)0)
) (id)->next.tqe_next->next.tqe_prev = (id)->next.tqe_prev; else (&idtab->idlist)->tqh_last = (id)->next.tqe_prev; *(id)->next.tqe_prev = (id)->next.tqe_next; ; ; } while (0);
 free_identity(id);
 idtab->nentries--;
 success = 1;
 done:
 sshkey_free(key);
 send_status(e, success);
}

static void
process_remove_all_identities(SocketEntry *e)
{
 Identity *id;

 sshlog("ssh-agent.c", __func__, 913, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "entering");

 for (id = ((&idtab->idlist)->tqh_first); id;
     id = ((&idtab->idlist)->tqh_first)) {
  do { if (((id)->next.tqe_next) != 
 ((void *)0)
 ) (id)->next.tqe_next->next.tqe_prev = (id)->next.tqe_prev; else (&idtab->idlist)->tqh_last = (id)->next.tqe_prev; *(id)->next.tqe_prev = (id)->next.tqe_next; ; ; } while (0);
  free_identity(id);
 }


 idtab->nentries = 0;


 send_status(e, 1);
}


static time_t
reaper(void)
{
 time_t deadline = 0, now = monotime();
 Identity *id, *nxt;

 for (id = ((&idtab->idlist)->tqh_first); id; id = nxt) {
  nxt = ((id)->next.tqe_next);
  if (id->death == 0)
   continue;
  if (now >= id->death) {
   sshlog("ssh-agent.c", __func__, 940, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "expiring key '%s'", id->comment);
   do { if (((id)->next.tqe_next) != 
  ((void *)0)
  ) (id)->next.tqe_next->next.tqe_prev = (id)->next.tqe_prev; else (&idtab->idlist)->tqh_last = (id)->next.tqe_prev; *(id)->next.tqe_prev = (id)->next.tqe_next; ; ; } while (0);
   free_identity(id);
   idtab->nentries--;
  } else
   deadline = (deadline == 0) ? id->death :
       (((deadline) < (id->death)) ? (deadline) : (id->death));
 }
 if (deadline == 0 || deadline <= now)
  return 0;
 else
  return (deadline - now);
}

static int
parse_dest_constraint_hop(struct sshbuf *b, struct dest_constraint_hop *dch)
{
 u_char key_is_ca;
 size_t elen = 0;
 int r;
 struct sshkey *k = 
                   ((void *)0)
                       ;
 char *fp;

 memset(dch, '\0', sizeof(*dch));
 if ((r = sshbuf_get_cstring(b, &dch->user, 
                                           ((void *)0)
                                               )) != 0 ||
     (r = sshbuf_get_cstring(b, &dch->hostname, 
                                               ((void *)0)
                                                   )) != 0 ||
     (r = sshbuf_get_string_direct(b, 
                                     ((void *)0)
                                         , &elen)) != 0) {
  sshlog("ssh-agent.c", __func__, 967, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse");
  goto out;
 }
 if (elen != 0) {
  sshlog("ssh-agent.c", __func__, 971, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unsupported extensions (len %zu)", elen);
  r = -59;
  goto out;
 }
 if (*dch->hostname == '\0') {
  free(dch->hostname);
  dch->hostname = 
                 ((void *)0)
                     ;
 }
 if (*dch->user == '\0') {
  free(dch->user);
  dch->user = 
             ((void *)0)
                 ;
 }
 while (sshbuf_len(b) != 0) {
  dch->keys = xrecallocarray(dch->keys, dch->nkeys,
      dch->nkeys + 1, sizeof(*dch->keys));
  dch->key_is_ca = xrecallocarray(dch->key_is_ca, dch->nkeys,
      dch->nkeys + 1, sizeof(*dch->key_is_ca));
  if ((r = sshkey_froms(b, &k)) != 0 ||
      (r = sshbuf_get_u8(b, &key_is_ca)) != 0)
   goto out;
  if ((fp = sshkey_fingerprint(k, 2,
      SSH_FP_DEFAULT)) == 
                         ((void *)0)
                             )
   sshfatal("ssh-agent.c", __func__, 993, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "fingerprint failed");
  sshlog("ssh-agent.c", __func__, 994, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "%s%s%s: adding %skey %s %s", dch->user == 
 ((void *)0) 
 ? "" : dch->user, dch->user == 
 ((void *)0) 
 ? "" : "@", dch->hostname, key_is_ca ? "CA " : "", sshkey_type(k), fp)


                                                                ;
  free(fp);
  dch->keys[dch->nkeys] = k;
  dch->key_is_ca[dch->nkeys] = key_is_ca != 0;
  dch->nkeys++;
  k = 
     ((void *)0)
         ;
 }

 r = 0;
 out:
 sshkey_free(k);
 return r;
}

static int
parse_dest_constraint(struct sshbuf *m, struct dest_constraint *dc)
{
 struct sshbuf *b = 
                   ((void *)0)
                       , *frombuf = 
                                    ((void *)0)
                                        , *tobuf = 
                                                   ((void *)0)
                                                       ;
 int r;
 size_t elen = 0;

 sshlog("ssh-agent.c", __func__, 1018, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "entering");

 memset(dc, '\0', sizeof(*dc));
 if ((r = sshbuf_froms(m, &b)) != 0 ||
     (r = sshbuf_froms(b, &frombuf)) != 0 ||
     (r = sshbuf_froms(b, &tobuf)) != 0 ||
     (r = sshbuf_get_string_direct(b, 
                                     ((void *)0)
                                         , &elen)) != 0) {
  sshlog("ssh-agent.c", __func__, 1025, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse");
  goto out;
 }
 if ((r = parse_dest_constraint_hop(frombuf, &dc->from) != 0) ||
     (r = parse_dest_constraint_hop(tobuf, &dc->to) != 0))
  goto out;
 if (elen != 0) {
  sshlog("ssh-agent.c", __func__, 1032, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unsupported extensions (len %zu)", elen);
  r = -59;
  goto out;
 }
 sshlog("ssh-agent.c", __func__, 1036, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "parsed %s (%u keys) > %s%s%s (%u keys)", dc->from.hostname ? dc->from.hostname : "(ORIGIN)", dc->from.nkeys, dc->to.user ? dc->to.user : "", dc->to.user ? "@" : "", dc->to.hostname ? dc->to.hostname : "(ANY)", dc->to.nkeys)


                                                               ;

 if ((dc->from.hostname == 
                          ((void *)0)
                              ) != (dc->from.nkeys == 0) ||
     dc->from.user != 
                     ((void *)0)
                         ) {
  sshlog("ssh-agent.c", __func__, 1043, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "inconsistent \"from\" specification");
  r = -4;
  goto out;
 }
 if (dc->to.hostname == 
                       ((void *)0) 
                            || dc->to.nkeys == 0) {
  sshlog("ssh-agent.c", __func__, 1048, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "incomplete \"to\" specification");
  r = -4;
  goto out;
 }

 r = 0;
 out:
 sshbuf_free(b);
 sshbuf_free(frombuf);
 sshbuf_free(tobuf);
 return r;
}

static int
parse_key_constraint_extension(struct sshbuf *m, char **sk_providerp,
    struct dest_constraint **dcsp, size_t *ndcsp)
{
 char *ext_name = 
                 ((void *)0)
                     ;
 int r;
 struct sshbuf *b = 
                   ((void *)0)
                       ;

 if ((r = sshbuf_get_cstring(m, &ext_name, 
                                          ((void *)0)
                                              )) != 0) {
  sshlog("ssh-agent.c", __func__, 1070, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse constraint extension");
  goto out;
 }
 sshlog("ssh-agent.c", __func__, 1073, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "constraint ext %s", ext_name);
 if (strcmp(ext_name, "sk-provider@openssh.com") == 0) {
  if (sk_providerp == 
                     ((void *)0)
                         ) {
   sshlog("ssh-agent.c", __func__, 1076, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s not valid here", ext_name);
   r = -4;
   goto out;
  }
  if (*sk_providerp != 
                      ((void *)0)
                          ) {
   sshlog("ssh-agent.c", __func__, 1081, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s already set", ext_name);
   r = -4;
   goto out;
  }
  if ((r = sshbuf_get_cstring(m, sk_providerp, 
                                              ((void *)0)
                                                  )) != 0) {
   sshlog("ssh-agent.c", __func__, 1086, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse %s", ext_name);
   goto out;
  }
 } else if (strcmp(ext_name,
     "restrict-destination-v00@openssh.com") == 0) {
  if (*dcsp != 
              ((void *)0)
                  ) {
   sshlog("ssh-agent.c", __func__, 1092, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s already set", ext_name);
   goto out;
  }
  if ((r = sshbuf_froms(m, &b)) != 0) {
   sshlog("ssh-agent.c", __func__, 1096, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse %s outer", ext_name);
   goto out;
  }
  while (sshbuf_len(b) != 0) {
   if (*ndcsp >= 1024) {
    sshlog("ssh-agent.c", __func__, 1101, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "too many %s constraints", ext_name);
    goto out;
   }
   *dcsp = xrecallocarray(*dcsp, *ndcsp, *ndcsp + 1,
       sizeof(**dcsp));
   if ((r = parse_dest_constraint(b,
       *dcsp + (*ndcsp)++)) != 0)
    goto out;
  }
 } else {
  sshlog("ssh-agent.c", __func__, 1111, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unsupported constraint \"%s\"", ext_name);
  r = -59;
  goto out;
 }

 r = 0;
 out:
 free(ext_name);
 sshbuf_free(b);
 return r;
}

static int
parse_key_constraints(struct sshbuf *m, struct sshkey *k, time_t *deathp,
    u_int *secondsp, int *confirmp, char **sk_providerp,
    struct dest_constraint **dcsp, size_t *ndcsp)
{
 u_char ctype;
 int r;
 u_int seconds, maxsign = 0;

 while (sshbuf_len(m)) {
  if ((r = sshbuf_get_u8(m, &ctype)) != 0) {
   sshlog("ssh-agent.c", __func__, 1134, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse constraint type");
   goto out;
  }
  switch (ctype) {
  case 1:
   if (*deathp != 0) {
    sshlog("ssh-agent.c", __func__, 1140, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "lifetime already set");
    r = -4;
    goto out;
   }
   if ((r = sshbuf_get_u32(m, &seconds)) != 0) {
    sshlog("ssh-agent.c", __func__, 1145, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse lifetime constraint");
    goto out;
   }
   *deathp = monotime() + seconds;
   *secondsp = seconds;
   break;
  case 2:
   if (*confirmp != 0) {
    sshlog("ssh-agent.c", __func__, 1153, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "confirm already set");
    r = -4;
    goto out;
   }
   *confirmp = 1;
   break;
  case 3:
   if (k == 
           ((void *)0)
               ) {
    sshlog("ssh-agent.c", __func__, 1161, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "maxsign not valid here");
    r = -4;
    goto out;
   }
   if (maxsign != 0) {
    sshlog("ssh-agent.c", __func__, 1166, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "maxsign already set");
    r = -4;
    goto out;
   }
   if ((r = sshbuf_get_u32(m, &maxsign)) != 0) {
    sshlog("ssh-agent.c", __func__, 1171, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse maxsign constraint");
    goto out;
   }
   if ((r = sshkey_enable_maxsign(k, maxsign)) != 0) {
    sshlog("ssh-agent.c", __func__, 1175, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "enable maxsign");
    goto out;
   }
   break;
  case 255:
   if ((r = parse_key_constraint_extension(m,
       sk_providerp, dcsp, ndcsp)) != 0)
    goto out;
   break;
  default:
   sshlog("ssh-agent.c", __func__, 1185, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Unknown constraint %d", ctype);
   r = -59;
   goto out;
  }
 }

 r = 0;
 out:
 return r;
}

static void
process_add_identity(SocketEntry *e)
{
 Identity *id;
 int success = 0, confirm = 0;
 char *fp, *comment = 
                     ((void *)0)
                         , *sk_provider = 
                                          ((void *)0)
                                              ;
 char canonical_provider[
                        4096
                                ];
 time_t death = 0;
 u_int seconds = 0;
 struct dest_constraint *dest_constraints = 
                                           ((void *)0)
                                               ;
 size_t ndest_constraints = 0;
 struct sshkey *k = 
                   ((void *)0)
                       ;
 int r = -1;

 sshlog("ssh-agent.c", __func__, 1210, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "entering");
 if ((r = sshkey_private_deserialize(e->request, &k)) != 0 ||
     k == 
         ((void *)0) 
              ||
     (r = sshbuf_get_cstring(e->request, &comment, 
                                                  ((void *)0)
                                                      )) != 0) {
  sshlog("ssh-agent.c", __func__, 1214, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse");
  goto out;
 }
 if (parse_key_constraints(e->request, k, &death, &seconds, &confirm,
     &sk_provider, &dest_constraints, &ndest_constraints) != 0) {
  sshlog("ssh-agent.c", __func__, 1219, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "failed to parse constraints");
  sshbuf_reset(e->request);
  goto out;
 }

 if (sk_provider != 
                   ((void *)0)
                       ) {
  if (!sshkey_is_sk(k)) {
   sshlog("ssh-agent.c", __func__, 1226, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Cannot add provider: %s is not an " "authenticator-hosted key", sshkey_type(k))
                                                  ;
   goto out;
  }
  if (strcasecmp(sk_provider, "internal") == 0) {
   sshlog("ssh-agent.c", __func__, 1231, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "internal provider");
  } else {
   if (realpath(sk_provider, canonical_provider) == 
                                                   ((void *)0)
                                                       ) {
    sshlog("ssh-agent.c", __func__, 1234, 0, SYSLOG_LEVEL_VERBOSE, 
   ((void *)0)
   , "failed provider \"%.100s\": " "realpath: %s", sk_provider, strerror(
   (*__errno_location ())
   ))

                        ;
    goto out;
   }
   free(sk_provider);
   sk_provider = xstrdup(canonical_provider);
   if (match_pattern_list(sk_provider,
       allowed_providers, 0) != 1) {
    sshlog("ssh-agent.c", __func__, 1243, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Refusing add key: " "provider %s not allowed", sk_provider)
                                               ;
    goto out;
   }
  }
 }
 if ((r = sshkey_shield_private(k)) != 0) {
  sshlog("ssh-agent.c", __func__, 1250, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "shield private");
  goto out;
 }
 if (lifetime && !death)
  death = monotime() + lifetime;
 if ((id = lookup_identity(k)) == 
                                 ((void *)0)
                                     ) {
  id = xcalloc(1, sizeof(Identity));
  do { (id)->next.tqe_next = 
 ((void *)0)
 ; (id)->next.tqe_prev = (&idtab->idlist)->tqh_last; *(&idtab->idlist)->tqh_last = (id); (&idtab->idlist)->tqh_last = &(id)->next.tqe_next; } while (0);

  idtab->nentries++;
 } else {

  if (identity_permitted(id, e, 
                               ((void *)0)
                                   , 
                                     ((void *)0)
                                         , 
                                           ((void *)0)
                                               ) != 0)
   goto out;

  sshkey_free(id->key);
  free(id->comment);
  free(id->sk_provider);
  free_dest_constraints(id->dest_constraints,
      id->ndest_constraints);
 }

 id->key = k;
 id->comment = comment;
 id->death = death;
 id->confirm = confirm;
 id->sk_provider = sk_provider;
 id->dest_constraints = dest_constraints;
 id->ndest_constraints = ndest_constraints;

 if ((fp = sshkey_fingerprint(k, 2,
     SSH_FP_DEFAULT)) == 
                        ((void *)0)
                            )
  sshfatal("ssh-agent.c", __func__, 1282, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshkey_fingerprint failed");
 sshlog("ssh-agent.c", __func__, 1283, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "add %s %s \"%.100s\" (life: %u) (confirm: %u) " "(provider: %s) (destination constraints: %zu)", sshkey_ssh_name(k), fp, comment, seconds, confirm, sk_provider == 
((void *)0) 
? "none" : sk_provider, ndest_constraints)


                                                                   ;
 free(fp);

 k = 
    ((void *)0)
        ;
 comment = 
          ((void *)0)
              ;
 sk_provider = 
              ((void *)0)
                  ;
 dest_constraints = 
                   ((void *)0)
                       ;
 ndest_constraints = 0;
 success = 1;
 out:
 free(sk_provider);
 free(comment);
 sshkey_free(k);
 free_dest_constraints(dest_constraints, ndest_constraints);
 send_status(e, success);
}


static void
process_lock_agent(SocketEntry *e, int lock)
{
 int r, success = 0, delay;
 char *passwd;
 u_char passwdhash[32];
 static u_int fail_count = 0;
 size_t pwlen;

 sshlog("ssh-agent.c", __func__, 1313, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "entering");





 if ((r = sshbuf_get_cstring(e->request, &passwd, &pwlen)) != 0)
  sshfatal("ssh-agent.c", __func__, 1320, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 if (pwlen == 0) {
  sshlog("ssh-agent.c", __func__, 1322, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "empty password not supported");
 } else if (locked && !lock) {
  if (bcrypt_pbkdf(passwd, pwlen, lock_salt, sizeof(lock_salt),
      passwdhash, sizeof(passwdhash), 1) < 0)
   sshfatal("ssh-agent.c", __func__, 1326, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "bcrypt_pbkdf");
  if (timingsafe_bcmp(passwdhash, lock_pwhash, 32) == 0) {
   sshlog("ssh-agent.c", __func__, 1328, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "agent unlocked");
   locked = 0;
   fail_count = 0;
   explicit_bzero(lock_pwhash, sizeof(lock_pwhash));
   success = 1;
  } else {

   if (fail_count < 100)
    fail_count++;
   delay = 100000 * fail_count;
   sshlog("ssh-agent.c", __func__, 1338, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "unlock failed, delaying %0.1lf seconds", (double)delay/1000000)
                             ;
   usleep(delay);
  }
  explicit_bzero(passwdhash, sizeof(passwdhash));
 } else if (!locked && lock) {
  sshlog("ssh-agent.c", __func__, 1344, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "agent locked");
  locked = 1;
  arc4random_buf(lock_salt, sizeof(lock_salt));
  if (bcrypt_pbkdf(passwd, pwlen, lock_salt, sizeof(lock_salt),
      lock_pwhash, sizeof(lock_pwhash), 1) < 0)
   sshfatal("ssh-agent.c", __func__, 1349, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "bcrypt_pbkdf");
  success = 1;
 }
 freezero(passwd, pwlen);
 send_status(e, success);
}

static void
no_identities(SocketEntry *e)
{
 struct sshbuf *msg;
 int r;

 if ((msg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("ssh-agent.c", __func__, 1363, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_put_u8(msg, 12)) != 0 ||
     (r = sshbuf_put_u32(msg, 0)) != 0 ||
     (r = sshbuf_put_stringb(e->output, msg)) != 0)
  sshfatal("ssh-agent.c", __func__, 1367, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 sshbuf_free(msg);
}


static void
process_add_smartcard_key(SocketEntry *e)
{
 char *provider = 
                 ((void *)0)
                     , *pin = 
                              ((void *)0)
                                  , canonical_provider[
                                                       4096
                                                               ];
 char **comments = 
                  ((void *)0)
                      ;
 int r, i, count = 0, success = 0, confirm = 0;
 u_int seconds = 0;
 time_t death = 0;
 struct sshkey **keys = 
                       ((void *)0)
                           , *k;
 Identity *id;
 struct dest_constraint *dest_constraints = 
                                           ((void *)0)
                                               ;
 size_t ndest_constraints = 0;

 sshlog("ssh-agent.c", __func__, 1385, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "entering");
 if ((r = sshbuf_get_cstring(e->request, &provider, 
                                                   ((void *)0)
                                                       )) != 0 ||
     (r = sshbuf_get_cstring(e->request, &pin, 
                                              ((void *)0)
                                                  )) != 0) {
  sshlog("ssh-agent.c", __func__, 1388, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse");
  goto send;
 }
 if (parse_key_constraints(e->request, 
                                      ((void *)0)
                                          , &death, &seconds, &confirm,
     
    ((void *)0)
        , &dest_constraints, &ndest_constraints) != 0) {
  sshlog("ssh-agent.c", __func__, 1393, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "failed to parse constraints");
  goto send;
 }
 if (realpath(provider, canonical_provider) == 
                                              ((void *)0)
                                                  ) {
  sshlog("ssh-agent.c", __func__, 1397, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "failed PKCS#11 add of \"%.100s\": realpath: %s", provider, strerror(
 (*__errno_location ())
 ))
                                ;
  goto send;
 }
 if (match_pattern_list(canonical_provider, allowed_providers, 0) != 1) {
  sshlog("ssh-agent.c", __func__, 1402, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "refusing PKCS#11 add of \"%.100s\": " "provider not allowed", canonical_provider)
                                                 ;
  goto send;
 }
 sshlog("ssh-agent.c", __func__, 1406, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "add %.100s", canonical_provider);
 if (lifetime && !death)
  death = monotime() + lifetime;

 count = pkcs11_add_provider(canonical_provider, pin, &keys, &comments);
 for (i = 0; i < count; i++) {
  k = keys[i];
  if (lookup_identity(k) == 
                           ((void *)0)
                               ) {
   id = xcalloc(1, sizeof(Identity));
   id->key = k;
   keys[i] = 
            ((void *)0)
                ;
   id->provider = xstrdup(canonical_provider);
   if (*comments[i] != '\0') {
    id->comment = comments[i];
    comments[i] = 
                 ((void *)0)
                     ;
   } else {
    id->comment = xstrdup(canonical_provider);
   }
   id->death = death;
   id->confirm = confirm;
   id->dest_constraints = dest_constraints;
   id->ndest_constraints = ndest_constraints;
   dest_constraints = 
                     ((void *)0)
                         ;
   ndest_constraints = 0;
   do { (id)->next.tqe_next = 
  ((void *)0)
  ; (id)->next.tqe_prev = (&idtab->idlist)->tqh_last; *(&idtab->idlist)->tqh_last = (id); (&idtab->idlist)->tqh_last = &(id)->next.tqe_next; } while (0);
   idtab->nentries++;
   success = 1;
  }

  sshkey_free(keys[i]);
  free(comments[i]);
 }
send:
 free(pin);
 free(provider);
 free(keys);
 free(comments);
 free_dest_constraints(dest_constraints, ndest_constraints);
 send_status(e, success);
}

static void
process_remove_smartcard_key(SocketEntry *e)
{
 char *provider = 
                 ((void *)0)
                     , *pin = 
                              ((void *)0)
                                  , canonical_provider[
                                                       4096
                                                               ];
 int r, success = 0;
 Identity *id, *nxt;

 sshlog("ssh-agent.c", __func__, 1454, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "entering");
 if ((r = sshbuf_get_cstring(e->request, &provider, 
                                                   ((void *)0)
                                                       )) != 0 ||
     (r = sshbuf_get_cstring(e->request, &pin, 
                                              ((void *)0)
                                                  )) != 0) {
  sshlog("ssh-agent.c", __func__, 1457, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse");
  goto send;
 }
 free(pin);

 if (realpath(provider, canonical_provider) == 
                                              ((void *)0)
                                                  ) {
  sshlog("ssh-agent.c", __func__, 1463, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "failed PKCS#11 add of \"%.100s\": realpath: %s", provider, strerror(
 (*__errno_location ())
 ))
                                ;
  goto send;
 }

 sshlog("ssh-agent.c", __func__, 1468, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "remove %.100s", canonical_provider);
 for (id = ((&idtab->idlist)->tqh_first); id; id = nxt) {
  nxt = ((id)->next.tqe_next);

  if (id->provider == 
                     ((void *)0)
                         )
   continue;
  if (!strcmp(canonical_provider, id->provider)) {
   do { if (((id)->next.tqe_next) != 
  ((void *)0)
  ) (id)->next.tqe_next->next.tqe_prev = (id)->next.tqe_prev; else (&idtab->idlist)->tqh_last = (id)->next.tqe_prev; *(id)->next.tqe_prev = (id)->next.tqe_next; ; ; } while (0);
   free_identity(id);
   idtab->nentries--;
  }
 }
 if (pkcs11_del_provider(canonical_provider) == 0)
  success = 1;
 else
  sshlog("ssh-agent.c", __func__, 1483, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "pkcs11_del_provider failed");
send:
 free(provider);
 send_status(e, success);
}


static int
process_ext_session_bind(SocketEntry *e)
{
 int r, sid_match, key_match;
 struct sshkey *key = 
                     ((void *)0)
                         ;
 struct sshbuf *sid = 
                     ((void *)0)
                         , *sig = 
                                  ((void *)0)
                                      ;
 char *fp = 
           ((void *)0)
               ;
 size_t i;
 u_char fwd = 0;

 sshlog("ssh-agent.c", __func__, 1500, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "entering");
 if ((r = sshkey_froms(e->request, &key)) != 0 ||
     (r = sshbuf_froms(e->request, &sid)) != 0 ||
     (r = sshbuf_froms(e->request, &sig)) != 0 ||
     (r = sshbuf_get_u8(e->request, &fwd)) != 0) {
  sshlog("ssh-agent.c", __func__, 1505, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse");
  goto out;
 }
 if ((fp = sshkey_fingerprint(key, 2,
     SSH_FP_DEFAULT)) == 
                        ((void *)0)
                            )
  sshfatal("ssh-agent.c", __func__, 1510, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "fingerprint failed");

 if ((r = sshkey_verify(key, sshbuf_ptr(sig), sshbuf_len(sig),
     sshbuf_ptr(sid), sshbuf_len(sid), 
                                      ((void *)0)
                                          , 0, 
                                               ((void *)0)
                                                   )) != 0) {
  sshlog("ssh-agent.c", __func__, 1514, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshkey_verify for %s %s", sshkey_type(key), fp);
  goto out;
 }

 for (i = 0; i < e->nsession_ids; i++) {
  if (!e->session_ids[i].forwarded) {
   sshlog("ssh-agent.c", __func__, 1520, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "attempt to bind session ID to socket " "previously bound for authentication attempt")
                                                     ;
   r = -1;
   goto out;
  }
  sid_match = buf_equal(sid, e->session_ids[i].sid) == 0;
  key_match = sshkey_equal(key, e->session_ids[i].key);
  if (sid_match && key_match) {
   sshlog("ssh-agent.c", __func__, 1528, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "session ID already recorded for %s %s", sshkey_type(key), fp)
                            ;
   r = 0;
   goto out;
  } else if (sid_match) {
   sshlog("ssh-agent.c", __func__, 1533, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "session ID recorded against different key " "for %s %s", sshkey_type(key), fp)
                                         ;
   r = -1;
   goto out;
  }




 }

 if (e->nsession_ids >= 16) {
  sshlog("ssh-agent.c", __func__, 1545, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "too many session IDs recorded");
  goto out;
 }
 e->session_ids = xrecallocarray(e->session_ids, e->nsession_ids,
     e->nsession_ids + 1, sizeof(*e->session_ids));
 i = e->nsession_ids++;
 sshlog("ssh-agent.c", __func__, 1551, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "recorded %s %s (slot %zu of %d)", sshkey_type(key), fp, i, 16)
                           ;
 e->session_ids[i].key = key;
 e->session_ids[i].forwarded = fwd != 0;
 key = 
      ((void *)0)
          ;

 if ((e->session_ids[i].sid = sshbuf_new()) == 
                                              ((void *)0)
                                                  )
  sshfatal("ssh-agent.c", __func__, 1558, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 if ((r = sshbuf_putb(e->session_ids[i].sid, sid)) != 0)
  sshfatal("ssh-agent.c", __func__, 1560, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_putb session ID");

 r = 0;
 out:
 free(fp);
 sshkey_free(key);
 sshbuf_free(sid);
 sshbuf_free(sig);
 return r == 0 ? 1 : 0;
}

static void
process_extension(SocketEntry *e)
{
 int r, success = 0;
 char *name;

 sshlog("ssh-agent.c", __func__, 1577, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "entering");
 if ((r = sshbuf_get_cstring(e->request, &name, 
                                               ((void *)0)
                                                   )) != 0) {
  sshlog("ssh-agent.c", __func__, 1579, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse");
  goto send;
 }
 if (strcmp(name, "session-bind@openssh.com") == 0)
  success = process_ext_session_bind(e);
 else
  sshlog("ssh-agent.c", __func__, 1585, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "unsupported extension \"%s\"", name);
 free(name);
send:
 send_status(e, success);
}




static int
process_message(u_int socknum)
{
 u_int msg_len;
 u_char type;
 const u_char *cp;
 int r;
 SocketEntry *e;

 if (socknum >= sockets_alloc)
  sshfatal("ssh-agent.c", __func__, 1604, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sock %u >= allocated %u", socknum, sockets_alloc);
 e = &sockets[socknum];

 if (sshbuf_len(e->input) < 5)
  return 0;
 cp = sshbuf_ptr(e->input);
 msg_len = (((u_int32_t)(((const u_char *)(cp))[0]) << 24) | ((u_int32_t)(((const u_char *)(cp))[1]) << 16) | ((u_int32_t)(((const u_char *)(cp))[2]) << 8) | (u_int32_t)(((const u_char *)(cp))[3]));
 if (msg_len > (256*1024)) {
  sshlog("ssh-agent.c", __func__, 1612, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "socket %u (fd=%d) message too long %u > %u", socknum, e->fd, msg_len, (256*1024))
                                             ;
  return -1;
 }
 if (sshbuf_len(e->input) < msg_len + 4)
  return 0;


 sshbuf_reset(e->request);
 if ((r = sshbuf_get_stringb(e->input, e->request)) != 0 ||
     (r = sshbuf_get_u8(e->request, &type)) != 0) {
  if (r == -3 ||
      r == -6) {
   sshlog("ssh-agent.c", __func__, 1625, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse");
   return -1;
  }
  sshfatal("ssh-agent.c", __func__, 1628, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 }

 sshlog("ssh-agent.c", __func__, 1631, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "socket %u (fd=%d) type %d", socknum, e->fd, type);


 if (locked && type != 23) {
  sshbuf_reset(e->request);
  switch (type) {
  case 11:

   no_identities(e);
   break;
  default:

   send_status(e, 0);
  }
  return 1;
 }

 switch (type) {
 case 22:
 case 23:
  process_lock_agent(e, type == 22);
  break;
 case 9:
  process_remove_all_identities(e);
  break;

 case 13:
  process_sign_request2(e);
  break;
 case 11:
  process_request_identities(e);
  break;
 case 17:
 case 25:
  process_add_identity(e);
  break;
 case 18:
  process_remove_identity(e);
  break;
 case 19:
  process_remove_all_identities(e);
  break;

 case 20:
 case 26:
  process_add_smartcard_key(e);
  break;
 case 21:
  process_remove_smartcard_key(e);
  break;

 case 27:
  process_extension(e);
  break;
 default:

  sshlog("ssh-agent.c", __func__, 1687, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Unknown message %d", type);
  sshbuf_reset(e->request);
  send_status(e, 0);
  break;
 }
 return 1;
}

static void
new_socket(sock_type type, int fd)
{
 u_int i, old_alloc, new_alloc;

 sshlog("ssh-agent.c", __func__, 1700, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "type = %s", type == AUTH_CONNECTION ? "CONNECTION" : (type == AUTH_SOCKET ? "SOCKET" : "UNKNOWN"))
                                                  ;
 set_nonblock(fd);

 if (fd > max_fd)
  max_fd = fd;

 for (i = 0; i < sockets_alloc; i++)
  if (sockets[i].type == AUTH_UNUSED) {
   sockets[i].fd = fd;
   if ((sockets[i].input = sshbuf_new()) == 
                                           ((void *)0) 
                                                ||
       (sockets[i].output = sshbuf_new()) == 
                                            ((void *)0) 
                                                 ||
       (sockets[i].request = sshbuf_new()) == 
                                             ((void *)0)
                                                 )
    sshfatal("ssh-agent.c", __func__, 1713, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "sshbuf_new failed");
   sockets[i].type = type;
   return;
  }
 old_alloc = sockets_alloc;
 new_alloc = sockets_alloc + 10;
 sockets = xrecallocarray(sockets, old_alloc, new_alloc,
     sizeof(sockets[0]));
 for (i = old_alloc; i < new_alloc; i++)
  sockets[i].type = AUTH_UNUSED;
 sockets_alloc = new_alloc;
 sockets[old_alloc].fd = fd;
 if ((sockets[old_alloc].input = sshbuf_new()) == 
                                                 ((void *)0) 
                                                      ||
     (sockets[old_alloc].output = sshbuf_new()) == 
                                                  ((void *)0) 
                                                       ||
     (sockets[old_alloc].request = sshbuf_new()) == 
                                                   ((void *)0)
                                                       )
  sshfatal("ssh-agent.c", __func__, 1728, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 sockets[old_alloc].type = type;
}

static int
handle_socket_read(u_int socknum)
{
 struct sockaddr_un sunaddr;
 socklen_t slen;
 uid_t euid;
 gid_t egid;
 int fd;

 slen = sizeof(sunaddr);
 fd = accept(sockets[socknum].fd, (struct sockaddr *)&sunaddr, &slen);
 if (fd == -1) {
  sshlog("ssh-agent.c", __func__, 1744, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "accept from AUTH_SOCKET: %s", strerror(
 (*__errno_location ())
 ));
  return -1;
 }
 if (getpeereid(fd, &euid, &egid) == -1) {
  sshlog("ssh-agent.c", __func__, 1748, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "getpeereid %d failed: %s", fd, strerror(
 (*__errno_location ())
 ));
  close(fd);
  return -1;
 }
 if ((euid != 0) && (getuid() != euid)) {
  sshlog("ssh-agent.c", __func__, 1753, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "uid mismatch: peer euid %u != uid %u", (u_int) euid, (u_int) getuid())
                                     ;
  close(fd);
  return -1;
 }
 new_socket(AUTH_CONNECTION, fd);
 return 0;
}

static int
handle_conn_read(u_int socknum)
{
 char buf[(4096)];
 ssize_t len;
 int r;

 if ((len = read(sockets[socknum].fd, buf, sizeof(buf))) <= 0) {
  if (len == -1) {
   if (
      (*__errno_location ()) 
            == 
               11 
                      || 
                         (*__errno_location ()) 
                               == 
                                  4
                                       )
    return 0;
   sshlog("ssh-agent.c", __func__, 1773, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "read error on socket %u (fd %d): %s", socknum, sockets[socknum].fd, strerror(
  (*__errno_location ())
  ))
                                                     ;
  }
  return -1;
 }
 if ((r = sshbuf_put(sockets[socknum].input, buf, len)) != 0)
  sshfatal("ssh-agent.c", __func__, 1779, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose");
 explicit_bzero(buf, sizeof(buf));
 for (;;) {
  if ((r = process_message(socknum)) == -1)
   return -1;
  else if (r == 0)
   break;
 }
 return 0;
}

static int
handle_conn_write(u_int socknum)
{
 ssize_t len;
 int r;

 if (sshbuf_len(sockets[socknum].output) == 0)
  return 0;
 if ((len = write(sockets[socknum].fd,
     sshbuf_ptr(sockets[socknum].output),
     sshbuf_len(sockets[socknum].output))) <= 0) {
  if (len == -1) {
   if (
      (*__errno_location ()) 
            == 
               11 
                      || 
                         (*__errno_location ()) 
                               == 
                                  4
                                       )
    return 0;
   sshlog("ssh-agent.c", __func__, 1804, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "read error on socket %u (fd %d): %s", socknum, sockets[socknum].fd, strerror(
  (*__errno_location ())
  ))
                                                     ;
  }
  return -1;
 }
 if ((r = sshbuf_consume(sockets[socknum].output, len)) != 0)
  sshfatal("ssh-agent.c", __func__, 1810, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "consume");
 return 0;
}

static void
after_poll(struct pollfd *pfd, size_t npfd, u_int maxfds)
{
 size_t i;
 u_int socknum, activefds = npfd;

 for (i = 0; i < npfd; i++) {
  if (pfd[i].revents == 0)
   continue;

  for (socknum = 0; socknum < sockets_alloc; socknum++) {
   if (sockets[socknum].type != AUTH_SOCKET &&
       sockets[socknum].type != AUTH_CONNECTION)
    continue;
   if (pfd[i].fd == sockets[socknum].fd)
    break;
  }
  if (socknum >= sockets_alloc) {
   sshlog("ssh-agent.c", __func__, 1832, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "no socket for fd %d", pfd[i].fd);
   continue;
  }

  switch (sockets[socknum].type) {
  case AUTH_SOCKET:
   if ((pfd[i].revents & (
                         0x001
                               |
                                0x008
                                       )) == 0)
    break;
   if (npfd > maxfds) {
    sshlog("ssh-agent.c", __func__, 1841, 0, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "out of fds (active %u >= limit %u); " "skipping accept", activefds, maxfds)
                                             ;
    break;
   }
   if (handle_socket_read(socknum) == 0)
    activefds++;
   break;
  case AUTH_CONNECTION:
   if ((pfd[i].revents & (
                         0x001
                               |
                                0x010
                                       |
                                        0x008
                                               )) != 0 &&
       handle_conn_read(socknum) != 0)
    goto close_sock;
   if ((pfd[i].revents & (
                         0x004
                                |
                                 0x010
                                        )) != 0 &&
       handle_conn_write(socknum) != 0) {
 close_sock:
    if (activefds == 0)
     sshfatal("ssh-agent.c", __func__, 1856, 0, SYSLOG_LEVEL_FATAL, 
    ((void *)0)
    , "activefds == 0 at close_sock");
    close_socket(&sockets[socknum]);
    activefds--;
    break;
   }
   break;
  default:
   break;
  }
 }
}

static int
prepare_poll(struct pollfd **pfdp, size_t *npfdp, int *timeoutp, u_int maxfds)
{
 struct pollfd *pfd = *pfdp;
 size_t i, j, npfd = 0;
 time_t deadline;
 int r;


 for (i = 0; i < sockets_alloc; i++) {
  switch (sockets[i].type) {
  case AUTH_SOCKET:
  case AUTH_CONNECTION:
   npfd++;
   break;
  case AUTH_UNUSED:
   break;
  default:
   sshfatal("ssh-agent.c", __func__, 1886, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Unknown socket type %d", sockets[i].type);
   break;
  }
 }
 if (npfd != *npfdp &&
     (pfd = recallocarray(pfd, *npfdp, npfd, sizeof(*pfd))) == 
                                                              ((void *)0)
                                                                  )
  sshfatal("ssh-agent.c", __func__, 1892, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "recallocarray failed");
 *pfdp = pfd;
 *npfdp = npfd;

 for (i = j = 0; i < sockets_alloc; i++) {
  switch (sockets[i].type) {
  case AUTH_SOCKET:
   if (npfd > maxfds) {
    sshlog("ssh-agent.c", __func__, 1900, 0, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "out of fds (active %zu >= limit %u); " "skipping arming listener", npfd, maxfds)
                                                 ;
    break;
   }
   pfd[j].fd = sockets[i].fd;
   pfd[j].revents = 0;
   pfd[j].events = 
                  0x001
                        ;
   j++;
   break;
  case AUTH_CONNECTION:
   pfd[j].fd = sockets[i].fd;
   pfd[j].revents = 0;




   if ((r = sshbuf_check_reserve(sockets[i].input,
       (4096))) == 0 &&
       (r = sshbuf_check_reserve(sockets[i].output,
       (256*1024))) == 0)
    pfd[j].events = 
                   0x001
                         ;
   else if (r != -9)
    sshfatal("ssh-agent.c", __func__, 1922, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reserve");
   if (sshbuf_len(sockets[i].output) > 0)
    pfd[j].events |= 
                    0x004
                           ;
   j++;
   break;
  default:
   break;
  }
 }
 deadline = reaper();
 if (parent_alive_interval != 0)
  deadline = (deadline == 0) ? parent_alive_interval :
      (((deadline) < (parent_alive_interval)) ? (deadline) : (parent_alive_interval));
 if (deadline == 0) {
  *timeoutp = -1;
 } else {
  if (deadline > 0x7fffffff / 1000)
   *timeoutp = 0x7fffffff / 1000;
  else
   *timeoutp = deadline * 1000;
 }
 return (1);
}

static void
cleanup_socket(void)
{
 if (cleanup_pid != 0 && getpid() != cleanup_pid)
  return;
 sshlog("ssh-agent.c", __func__, 1951, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "cleanup");
 if (socket_name[0])
  unlink(socket_name);
 if (socket_dir[0])
  rmdir(socket_dir);
}

void
cleanup_exit(int i)
{
 cleanup_socket();
 _exit(i);
}


static void
cleanup_handler(int sig)
{
 cleanup_socket();

 pkcs11_terminate();

 _exit(2);
}

static void
check_parent_exists(void)
{




 if (parent_pid != -1 && getppid() != parent_pid) {

  cleanup_socket();
  _exit(2);
 }
}

static void
usage(void)
{
 fprintf(
        stderr
              ,
     "usage: ssh-agent [-c | -s] [-Dd] [-a bind_address] [-E fingerprint_hash]\n"
     "                 [-P allowed_providers] [-t life]\n"
     "       ssh-agent [-a bind_address] [-E fingerprint_hash] [-P allowed_providers]\n"
     "                 [-t life] command [arg ...]\n"
     "       ssh-agent [-c | -s] -k\n");
 exit(1);
}

int
main(int ac, char **av)
{
 int c_flag = 0, d_flag = 0, D_flag = 0, k_flag = 0, s_flag = 0;
 int sock, ch, result, saved_errno;
 char *shell, *format, *pidstr, *agentsocket = 
                                              ((void *)0)
                                                  ;

 struct rlimit rlim;

 extern int BSDoptind;
 extern char *BSDoptarg;
 pid_t pid;
 char pidstrbuf[1 + 3 * sizeof pid];
 size_t len;
 mode_t prev_mask;
 int timeout = -1;
 struct pollfd *pfd = 
                     ((void *)0)
                         ;
 size_t npfd = 0;
 u_int maxfds;


 sanitise_stdfd();


 setegid(getgid());
 setgid(getgid());

 platform_disable_tracing(0);


 if (getrlimit(
              RLIMIT_NOFILE
                           , &rlim) == -1)
  sshfatal("ssh-agent.c", __func__, 2033, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: getrlimit: %s", __progname, strerror(
 (*__errno_location ())
 ));


 __progname = ssh_get_progname(av[0]);
 seed_rng();

 while ((ch = BSDgetopt(ac, av, "cDdksE:a:O:P:t:")) != -1) {
  switch (ch) {
  case 'E':
   fingerprint_hash = ssh_digest_alg_by_name(BSDoptarg);
   if (fingerprint_hash == -1)
    sshfatal("ssh-agent.c", __func__, 2044, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Invalid hash algorithm \"%s\"", BSDoptarg);
   break;
  case 'c':
   if (s_flag)
    usage();
   c_flag++;
   break;
  case 'k':
   k_flag++;
   break;
  case 'O':
   if (strcmp(BSDoptarg, "no-restrict-websafe") == 0)
    restrict_websafe = 0;
   else
    sshfatal("ssh-agent.c", __func__, 2058, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Unknown -O option");
   break;
  case 'P':
   if (allowed_providers != 
                           ((void *)0)
                               )
    sshfatal("ssh-agent.c", __func__, 2062, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "-P option already specified");
   allowed_providers = xstrdup(BSDoptarg);
   break;
  case 's':
   if (c_flag)
    usage();
   s_flag++;
   break;
  case 'd':
   if (d_flag || D_flag)
    usage();
   d_flag++;
   break;
  case 'D':
   if (d_flag || D_flag)
    usage();
   D_flag++;
   break;
  case 'a':
   agentsocket = BSDoptarg;
   break;
  case 't':
   if ((lifetime = convtime(BSDoptarg)) == -1) {
    fprintf(
           stderr
                 , "Invalid lifetime\n");
    usage();
   }
   break;
  default:
   usage();
  }
 }
 ac -= BSDoptind;
 av += BSDoptind;

 if (ac > 0 && (c_flag || k_flag || s_flag || d_flag || D_flag))
  usage();

 if (allowed_providers == 
                         ((void *)0)
                             )
  allowed_providers = xstrdup("/usr/lib*/*,/usr/local/lib*/*");

 if (ac == 0 && !c_flag && !s_flag) {
  shell = getenv("SHELL");
  if (shell != 
              ((void *)0) 
                   && (len = strlen(shell)) > 2 &&
      strncmp(shell + len - 3, "csh", 3) == 0)
   c_flag = 1;
 }
 if (k_flag) {
  const char *errstr = 
                      ((void *)0)
                          ;

  pidstr = getenv("SSH_AGENT_PID");
  if (pidstr == 
               ((void *)0)
                   ) {
   fprintf(
          stderr
                , "%s not set, cannot kill agent\n",
       "SSH_AGENT_PID");
   exit(1);
  }
  pid = (int)strtonum(pidstr, 2, 0x7fffffff, &errstr);
  if (errstr) {
   fprintf(
          stderr
                ,
       "%s=\"%s\", which is not a good PID: %s\n",
       "SSH_AGENT_PID", pidstr, errstr);
   exit(1);
  }
  if (kill(pid, 
               15
                      ) == -1) {
   perror("kill");
   exit(1);
  }
  format = c_flag ? "unsetenv %s;\n" : "unset %s;\n";
  printf(format, "SSH_AUTH_SOCK");
  printf(format, "SSH_AGENT_PID");
  printf("echo Agent pid %ld killed;\n", (long)pid);
  exit(0);
 }







 if (rlim.rlim_cur < (3+1+1+1+4))
  sshfatal("ssh-agent.c", __func__, 2142, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: file descriptor rlimit %lld too low (minimum %u)", __progname, (long long)rlim.rlim_cur, (3+1+1+1+4))
                                                              ;
 maxfds = rlim.rlim_cur - (3+1+1+1+4);

 parent_pid = getpid();

 if (agentsocket == 
                   ((void *)0)
                       ) {

  mktemp_proto(socket_dir, sizeof(socket_dir));
  if (mkdtemp(socket_dir) == 
                            ((void *)0)
                                ) {
   perror("mkdtemp: private socket dir");
   exit(1);
  }
  snprintf(socket_name, sizeof socket_name, "%s/agent.%ld", socket_dir,
      (long)parent_pid);
 } else {

  socket_dir[0] = '\0';
  strlcpy(socket_name, agentsocket, sizeof socket_name);
 }





 prev_mask = umask(0177);
 sock = unix_listener(socket_name, 128, 0);
 if (sock < 0) {

  *socket_name = '\0';
  cleanup_exit(1);
 }
 umask(prev_mask);





 if (D_flag || d_flag) {
  log_init(__progname,
      d_flag ? SYSLOG_LEVEL_DEBUG3 : SYSLOG_LEVEL_INFO,
      SYSLOG_FACILITY_AUTH, 1);
  format = c_flag ? "setenv %s %s;\n" : "%s=%s; export %s;\n";
  printf(format, "SSH_AUTH_SOCK", socket_name,
      "SSH_AUTH_SOCK");
  printf("echo Agent pid %ld;\n", (long)parent_pid);
  fflush(
        stdout
              );
  goto skip;
 }
 pid = fork();
 if (pid == -1) {
  perror("fork");
  cleanup_exit(1);
 }
 if (pid != 0) {
  close(sock);
  snprintf(pidstrbuf, sizeof pidstrbuf, "%ld", (long)pid);
  if (ac == 0) {
   format = c_flag ? "setenv %s %s;\n" : "%s=%s; export %s;\n";
   printf(format, "SSH_AUTH_SOCK", socket_name,
       "SSH_AUTH_SOCK");
   printf(format, "SSH_AGENT_PID", pidstrbuf,
       "SSH_AGENT_PID");
   printf("echo Agent pid %ld;\n", (long)pid);
   exit(0);
  }
  if (setenv("SSH_AUTH_SOCK", socket_name, 1) == -1 ||
      setenv("SSH_AGENT_PID", pidstrbuf, 1) == -1) {
   perror("setenv");
   exit(1);
  }
  execvp(av[0], av);
  perror(av[0]);
  exit(1);
 }

 log_init(__progname, SYSLOG_LEVEL_INFO, SYSLOG_FACILITY_AUTH, 0);

 if (setsid() == -1) {
  sshlog("ssh-agent.c", __func__, 2221, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "setsid: %s", strerror(
 (*__errno_location ())
 ));
  cleanup_exit(1);
 }

 (void)chdir("/");
 if (stdfd_devnull(1, 1, 1) == -1)
  sshlog("ssh-agent.c", __func__, 2227, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "stdfd_devnull failed");



 rlim.rlim_cur = rlim.rlim_max = 0;
 if (setrlimit(
              RLIMIT_CORE
                         , &rlim) == -1) {
  sshlog("ssh-agent.c", __func__, 2233, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "setrlimit RLIMIT_CORE: %s", strerror(
 (*__errno_location ())
 ));
  cleanup_exit(1);
 }


skip:

 cleanup_pid = getpid();


 pkcs11_init(0);

 new_socket(AUTH_SOCKET, sock);
 if (ac > 0)
  parent_alive_interval = 10;
 idtab_init();
 ssh_signal(
           13
                  , 
                    ((__sighandler_t) 1)
                           );
 ssh_signal(
           2
                 , (d_flag | D_flag) ? cleanup_handler : 
                                                         ((__sighandler_t) 1)
                                                                );
 ssh_signal(
           1
                 , cleanup_handler);
 ssh_signal(
           15
                  , cleanup_handler);

 if (pledge("stdio rpath cpath unix id proc exec", 
                                                  ((void *)0)
                                                      ) == -1)
  sshfatal("ssh-agent.c", __func__, 2255, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: pledge: %s", __progname, strerror(
 (*__errno_location ())
 ));
 platform_pledge_agent();

 while (1) {
  prepare_poll(&pfd, &npfd, &timeout, maxfds);
  result = poll(pfd, npfd, timeout);
  saved_errno = 
               (*__errno_location ())
                    ;
  if (parent_alive_interval != 0)
   check_parent_exists();
  (void) reaper();
  if (result == -1) {
   if (saved_errno == 
                     4
                          )
    continue;
   sshfatal("ssh-agent.c", __func__, 2268, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "poll: %s", strerror(saved_errno));
  } else if (result > 0)
   after_poll(pfd, npfd, maxfds);
 }

}
