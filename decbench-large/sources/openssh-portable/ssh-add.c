











































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


extern char *__progname;


static char *default_files[] = {

 ".ssh" "/id_rsa",

 ".ssh" "/id_ecdsa",
 ".ssh" "/id_ecdsa_sk",


 ".ssh" "/id_ed25519",
 ".ssh" "/id_ed25519_sk",
 ".ssh" "/id_xmss",
 ".ssh" "/id_dsa",
 
((void *)0)

};

static int fingerprint_hash = 2;


static int lifetime = 0;


static int confirm = 0;


static u_int maxsign = 0;
static u_int minleft = 0;


static char *pass = 
                   ((void *)0)
                       ;
static void
clear_pass(void)
{
 if (pass) {
  freezero(pass, strlen(pass));
  pass = 
        ((void *)0)
            ;
 }
}

static int
delete_one(int agent_fd, const struct sshkey *key, const char *comment,
    const char *path, int qflag)
{
 int r;

 if ((r = ssh_remove_identity(agent_fd, key)) != 0) {
  fprintf(
         stderr
               , "Could not remove identity \"%s\": %s\n",
      path, ssh_err(r));
  return r;
 }
 if (!qflag) {
  fprintf(
         stderr
               , "Identity removed: %s %s (%s)\n", path,
      sshkey_type(key), comment ? comment : "no comment");
 }
 return 0;
}

static int
delete_stdin(int agent_fd, int qflag)
{
 char *line = 
             ((void *)0)
                 , *cp;
 size_t linesize = 0;
 struct sshkey *key = 
                     ((void *)0)
                         ;
 int lnum = 0, r, ret = -1;

 while (getline(&line, &linesize, 
                                 stdin
                                      ) != -1) {
  lnum++;
  sshkey_free(key);
  key = 
       ((void *)0)
           ;
  line[strcspn(line, "\n")] = '\0';
  cp = line + strspn(line, " \t");
  if (*cp == '#' || *cp == '\0')
   continue;
  if ((key = sshkey_new(KEY_UNSPEC)) == 
                                       ((void *)0)
                                           )
   sshfatal("ssh-add.c", __func__, 150, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshkey_new");
  if ((r = sshkey_read(key, &cp)) != 0) {
   sshlog("ssh-add.c", __func__, 152, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "(stdin):%d: invalid key", lnum);
   continue;
  }
  if (delete_one(agent_fd, key, cp, "(stdin)", qflag) == 0)
   ret = 0;
 }
 sshkey_free(key);
 free(line);
 return ret;
}

static int
delete_file(int agent_fd, const char *filename, int key_only, int qflag)
{
 struct sshkey *public, *cert = 
                               ((void *)0)
                                   ;
 char *certpath = 
                 ((void *)0)
                     , *comment = 
                                  ((void *)0)
                                      ;
 int r, ret = -1;

 if (strcmp(filename, "-") == 0)
  return delete_stdin(agent_fd, qflag);

 if ((r = sshkey_load_public(filename, &public, &comment)) != 0) {
  printf("Bad key file %s: %s\n", filename, ssh_err(r));
  return -1;
 }
 if (delete_one(agent_fd, public, comment, filename, qflag) == 0)
  ret = 0;

 if (key_only)
  goto out;


 free(comment);
 comment = 
          ((void *)0)
              ;
 xasprintf(&certpath, "%s-cert.pub", filename);
 if ((r = sshkey_load_public(certpath, &cert, &comment)) != 0) {
  if (r != -24 || 
                                  (*__errno_location ()) 
                                        != 
                                           2
                                                 )
   sshlog("ssh-add.c", __func__, 189, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Failed to load certificate \"%s\"", certpath);
  goto out;
 }

 if (!sshkey_equal_public(cert, public))
  sshfatal("ssh-add.c", __func__, 194, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Certificate %s does not match private key %s", certpath, filename)
                         ;

 if (delete_one(agent_fd, cert, comment, certpath, qflag) == 0)
  ret = 0;

 out:
 sshkey_free(cert);
 sshkey_free(public);
 free(certpath);
 free(comment);

 return ret;
}


static int
delete_all(int agent_fd, int qflag)
{
 int ret = -1;






 if (ssh_remove_all_identities(agent_fd, 2) == 0)
  ret = 0;

 ssh_remove_all_identities(agent_fd, 1);

 if (ret != 0)
  fprintf(
         stderr
               , "Failed to remove all identities.\n");
 else if (!qflag)
  fprintf(
         stderr
               , "All identities removed.\n");

 return ret;
}

static int
add_file(int agent_fd, const char *filename, int key_only, int qflag,
    const char *skprovider, struct dest_constraint **dest_constraints,
    size_t ndest_constraints)
{
 struct sshkey *private, *cert;
 char *comment = 
                ((void *)0)
                    ;
 char msg[1024], *certpath = 
                            ((void *)0)
                                ;
 int r, fd, ret = -1;
 size_t i;
 u_int32_t left;
 struct sshbuf *keyblob;
 struct ssh_identitylist *idlist;

 if (strcmp(filename, "-") == 0) {
  fd = 
      0
                  ;
  filename = "(stdin)";
 } else if ((fd = open(filename, 
                                00
                                        )) == -1) {
  perror(filename);
  return -1;
 }





 if (fd != 
          0
                      ) {
  if (sshkey_perm_ok(fd, filename) != 0) {
   close(fd);
   return -1;
  }
 }
 if ((r = sshbuf_load_fd(fd, &keyblob)) != 0) {
  fprintf(
         stderr
               , "Error loading key \"%s\": %s\n",
      filename, ssh_err(r));
  sshbuf_free(keyblob);
  close(fd);
  return -1;
 }
 close(fd);


 if ((r = sshkey_parse_private_fileblob(keyblob, "", &private,
     &comment)) != 0 && r != -43) {
  fprintf(
         stderr
               , "Error loading key \"%s\": %s\n",
      filename, ssh_err(r));
  goto fail_load;
 }

 if (private == 
               ((void *)0) 
                    && pass != 
                               ((void *)0)
                                   ) {
  if ((r = sshkey_parse_private_fileblob(keyblob, pass, &private,
      &comment)) != 0 && r != -43) {
   fprintf(
          stderr
                , "Error loading key \"%s\": %s\n",
       filename, ssh_err(r));
   goto fail_load;
  }
 }
 if (private == 
               ((void *)0)
                   ) {

  clear_pass();
  snprintf(msg, sizeof msg, "Enter passphrase for %s%s: ",
      filename, confirm ? " (will confirm each use)" : "");
  for (;;) {
   pass = read_passphrase(msg, 0x0002);
   if (strcmp(pass, "") == 0)
    goto fail_load;
   if ((r = sshkey_parse_private_fileblob(keyblob, pass,
       &private, &comment)) == 0)
    break;
   else if (r != -43) {
    fprintf(
           stderr
                 ,
        "Error loading key \"%s\": %s\n",
        filename, ssh_err(r));
 fail_load:
    clear_pass();
    sshbuf_free(keyblob);
    return -1;
   }
   clear_pass();
   snprintf(msg, sizeof msg,
       "Bad passphrase, try again for %s%s: ", filename,
       confirm ? " (will confirm each use)" : "");
  }
 }
 if (comment == 
               ((void *)0) 
                    || *comment == '\0')
  comment = xstrdup(filename);
 sshbuf_free(keyblob);


 if ((r = sshkey_set_filename(private, filename)) != 0) {
  fprintf(
         stderr
               , "Could not add filename to private key: %s (%s)\n",
      filename, comment);
  goto out;
 }
 if (maxsign && minleft &&
     (r = ssh_fetch_identitylist(agent_fd, &idlist)) == 0) {
  for (i = 0; i < idlist->nkeys; i++) {
   if (!sshkey_equal_public(idlist->keys[i], private))
    continue;
   left = sshkey_signatures_left(idlist->keys[i]);
   if (left < minleft) {
    fprintf(
           stderr
                 ,
        "Only %d signatures left.\n", left);
    break;
   }
   fprintf(
          stderr
                , "Skipping update: ");
   if (left == minleft) {
    fprintf(
           stderr
                 ,
        "required signatures left (%d).\n", left);
   } else {
    fprintf(
           stderr
                 ,
        "more signatures left (%d) than"
        " required (%d).\n", left, minleft);
   }
   ssh_free_identitylist(idlist);
   goto out;
  }
  ssh_free_identitylist(idlist);
 }

 if (sshkey_is_sk(private)) {
  if (skprovider == 
                   ((void *)0)
                       ) {
   fprintf(
          stderr
                , "Cannot load FIDO key %s "
       "without provider\n", filename);
   goto out;
  }
 } else {

  skprovider = 
              ((void *)0)
                  ;
 }

 if ((r = ssh_add_identity_constrained(agent_fd, private, comment,
     lifetime, confirm, maxsign, skprovider,
     dest_constraints, ndest_constraints)) == 0) {
  ret = 0;
  if (!qflag) {
   fprintf(
          stderr
                , "Identity added: %s (%s)\n",
       filename, comment);
   if (lifetime != 0) {
    fprintf(
           stderr
                 ,
        "Lifetime set to %d seconds\n", lifetime);
   }
   if (confirm != 0) {
    fprintf(
           stderr
                 , "The user must confirm "
        "each use of the key\n");
   }
  }
 } else {
  fprintf(
         stderr
               , "Could not add identity \"%s\": %s\n",
      filename, ssh_err(r));
 }


 if (key_only)
  goto out;


 xasprintf(&certpath, "%s-cert.pub", filename);
 if ((r = sshkey_load_public(certpath, &cert, 
                                             ((void *)0)
                                                 )) != 0) {
  if (r != -24 || 
                                  (*__errno_location ()) 
                                        != 
                                           2
                                                 )
   sshlog("ssh-add.c", __func__, 393, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Failed to load certificate \"%s\"", certpath);
  goto out;
 }

 if (!sshkey_equal_public(cert, private)) {
  sshlog("ssh-add.c", __func__, 398, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Certificate %s does not match private key %s", certpath, filename)
                         ;
  sshkey_free(cert);
  goto out;
 }


 if ((r = sshkey_to_certified(private)) != 0) {
  sshlog("ssh-add.c", __func__, 406, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshkey_to_certified");
  sshkey_free(cert);
  goto out;
 }
 if ((r = sshkey_cert_copy(cert, private)) != 0) {
  sshlog("ssh-add.c", __func__, 411, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshkey_cert_copy");
  sshkey_free(cert);
  goto out;
 }
 sshkey_free(cert);

 if ((r = ssh_add_identity_constrained(agent_fd, private, comment,
     lifetime, confirm, maxsign, skprovider,
     dest_constraints, ndest_constraints)) != 0) {
  sshlog("ssh-add.c", __func__, 420, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Certificate %s (%s) add failed", certpath, private->cert->key_id)
                            ;
  goto out;
 }

 if (!qflag) {
  fprintf(
         stderr
               , "Certificate added: %s (%s)\n", certpath,
      private->cert->key_id);
  if (lifetime != 0) {
   fprintf(
          stderr
                , "Lifetime set to %d seconds\n",
       lifetime);
  }
  if (confirm != 0) {
   fprintf(
          stderr
                , "The user must confirm each use "
       "of the key\n");
  }
 }

 out:
 free(certpath);
 free(comment);
 sshkey_free(private);

 return ret;
}

static int
update_card(int agent_fd, int add, const char *id, int qflag,
    struct dest_constraint **dest_constraints, size_t ndest_constraints)
{
 char *pin = 
            ((void *)0)
                ;
 int r, ret = -1;

 if (add) {
  if ((pin = read_passphrase("Enter passphrase for PKCS#11: ",
      0x0002)) == 
                         ((void *)0)
                             )
   return -1;
 }

 if ((r = ssh_update_card(agent_fd, add, id, pin == 
                                                   ((void *)0) 
                                                        ? "" : pin,
     lifetime, confirm, dest_constraints, ndest_constraints)) == 0) {
  ret = 0;
  if (!qflag) {
   fprintf(
          stderr
                , "Card %s: %s\n",
       add ? "added" : "removed", id);
  }
 } else {
  fprintf(
         stderr
               , "Could not %s card \"%s\": %s\n",
      add ? "add" : "remove", id, ssh_err(r));
  ret = -1;
 }
 free(pin);
 return ret;
}

static int
test_key(int agent_fd, const char *filename)
{
 struct sshkey *key = 
                     ((void *)0)
                         ;
 u_char *sig = 
              ((void *)0)
                  ;
 size_t slen = 0;
 int r, ret = -1;
 char data[1024];

 if ((r = sshkey_load_public(filename, &key, 
                                            ((void *)0)
                                                )) != 0) {
  sshlog("ssh-add.c", __func__, 485, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Couldn't read public key %s", filename);
  return -1;
 }
 arc4random_buf(data, sizeof(data));
 if ((r = ssh_agent_sign(agent_fd, key, &sig, &slen, data, sizeof(data),
     
    ((void *)0)
        , 0)) != 0) {
  sshlog("ssh-add.c", __func__, 491, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Agent signature failed for %s", filename);
  goto done;
 }
 if ((r = sshkey_verify(key, sig, slen, data, sizeof(data),
     
    ((void *)0)
        , 0, 
             ((void *)0)
                 )) != 0) {
  sshlog("ssh-add.c", __func__, 496, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Signature verification failed for %s", filename);
  goto done;
 }

 ret = 0;
 done:
 free(sig);
 sshkey_free(key);
 return ret;
}

static int
list_identities(int agent_fd, int do_fp)
{
 char *fp;
 int r;
 struct ssh_identitylist *idlist;
 u_int32_t left;
 size_t i;

 if ((r = ssh_fetch_identitylist(agent_fd, &idlist)) != 0) {
  if (r != -48)
   fprintf(
          stderr
                , "error fetching identities: %s\n",
       ssh_err(r));
  else
   printf("The agent has no identities.\n");
  return -1;
 }
 for (i = 0; i < idlist->nkeys; i++) {
  if (do_fp) {
   fp = sshkey_fingerprint(idlist->keys[i],
       fingerprint_hash, SSH_FP_DEFAULT);
   printf("%u %s %s (%s)\n", sshkey_size(idlist->keys[i]),
       fp == 
            ((void *)0) 
                 ? "(null)" : fp, idlist->comments[i],
       sshkey_type(idlist->keys[i]));
   free(fp);
  } else {
   if ((r = sshkey_write(idlist->keys[i], 
                                         stdout
                                               )) != 0) {
    fprintf(
           stderr
                 , "sshkey_write: %s\n",
        ssh_err(r));
    continue;
   }
   fprintf(
          stdout
                , " %s", idlist->comments[i]);
   left = sshkey_signatures_left(idlist->keys[i]);
   if (left > 0)
    fprintf(
           stdout
                 ,
        " [signatures left %d]", left);
   fprintf(
          stdout
                , "\n");
  }
 }
 ssh_free_identitylist(idlist);
 return 0;
}

static int
lock_agent(int agent_fd, int lock)
{
 char prompt[100], *p1, *p2;
 int r, passok = 1, ret = -1;

 strlcpy(prompt, "Enter lock password: ", sizeof(prompt));
 p1 = read_passphrase(prompt, 0x0002);
 if (lock) {
  strlcpy(prompt, "Again: ", sizeof prompt);
  p2 = read_passphrase(prompt, 0x0002);
  if (strcmp(p1, p2) != 0) {
   fprintf(
          stderr
                , "Passwords do not match.\n");
   passok = 0;
  }
  freezero(p2, strlen(p2));
 }
 if (passok) {
  if ((r = ssh_lock_agent(agent_fd, lock, p1)) == 0) {
   fprintf(
          stderr
                , "Agent %slocked.\n", lock ? "" : "un");
   ret = 0;
  } else {
   fprintf(
          stderr
                , "Failed to %slock agent: %s\n",
       lock ? "" : "un", ssh_err(r));
  }
 }
 freezero(p1, strlen(p1));
 return (ret);
}

static int
load_resident_keys(int agent_fd, const char *skprovider, int qflag,
    struct dest_constraint **dest_constraints, size_t ndest_constraints)
{
 struct sshsk_resident_key **srks;
 size_t nsrks, i;
 struct sshkey *key;
 int r, ok = 0;
 char *fp;

 pass = read_passphrase("Enter PIN for authenticator: ", 0x0002);
 if ((r = sshsk_load_resident(skprovider, 
                                         ((void *)0)
                                             , pass, 0,
     &srks, &nsrks)) != 0) {
  sshlog("ssh-add.c", __func__, 593, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Unable to load resident keys");
  return r;
 }
 for (i = 0; i < nsrks; i++) {
  key = srks[i]->key;
  if ((fp = sshkey_fingerprint(key,
      fingerprint_hash, SSH_FP_DEFAULT)) == 
                                           ((void *)0)
                                               )
   sshfatal("ssh-add.c", __func__, 600, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshkey_fingerprint failed");
  if ((r = ssh_add_identity_constrained(agent_fd, key, "",
      lifetime, confirm, maxsign, skprovider,
      dest_constraints, ndest_constraints)) != 0) {
   sshlog("ssh-add.c", __func__, 604, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Unable to add key %s %s", sshkey_type(key), fp)
                            ;
   free(fp);
   ok = r;
   continue;
  }
  if (ok == 0)
   ok = 1;
  if (!qflag) {
   fprintf(
          stderr
                , "Resident identity added: %s %s\n",
       sshkey_type(key), fp);
   if (lifetime != 0) {
    fprintf(
           stderr
                 ,
        "Lifetime set to %d seconds\n", lifetime);
   }
   if (confirm != 0) {
    fprintf(
           stderr
                 , "The user must confirm "
        "each use of the key\n");
   }
  }
  free(fp);
 }
 sshsk_free_resident_keys(srks, nsrks);
 if (nsrks == 0)
  return -46;
 return ok == 1 ? 0 : ok;
}

static int
do_file(int agent_fd, int deleting, int key_only, char *file, int qflag,
    const char *skprovider, struct dest_constraint **dest_constraints,
    size_t ndest_constraints)
{
 if (deleting) {
  if (delete_file(agent_fd, file, key_only, qflag) == -1)
   return -1;
 } else {
  if (add_file(agent_fd, file, key_only, qflag, skprovider,
      dest_constraints, ndest_constraints) == -1)
   return -1;
 }
 return 0;
}


static void
stringlist_append(char ***listp, const char *s)
{
 size_t i = 0;

 if (*listp == 
              ((void *)0)
                  )
  *listp = xcalloc(2, sizeof(**listp));
 else {
  for (i = 0; (*listp)[i] != 
                            ((void *)0)
                                ; i++)
   ;
  *listp = xrecallocarray(*listp, i + 1, i + 2, sizeof(**listp));
 }
 (*listp)[i] = xstrdup(s);
}

static void
parse_dest_constraint_hop(const char *s, struct dest_constraint_hop *dch,
    char **hostkey_files)
{
 char *user = 
             ((void *)0)
                 , *host, *os, *path;
 size_t i;
 struct hostkeys *hostkeys;
 const struct hostkey_entry *hke;
 int r, want_ca;

 memset(dch, '\0', sizeof(*dch));
 os = xstrdup(s);
 if ((host = strchr(os, '@')) == 
                                ((void *)0)
                                    )
  host = os;
 else {
  *host++ = '\0';
  user = os;
 }
 cleanhostname(host);

 if (*host == '\0') {
  if (user == 
             ((void *)0)
                 ) {
   sshfatal("ssh-add.c", __func__, 686, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Invalid key destination constraint \"%s\": " "does not specify user or host", s)
                                          ;
  }
  dch->user = xstrdup(user);

  free(os);
  return;
 }
 if (hostkey_files == 
                     ((void *)0)
                         )
  sshfatal("ssh-add.c", __func__, 695, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "no hostkey files");

 hostkeys = init_hostkeys();
 for (i = 0; hostkey_files[i]; i++) {
  path = tilde_expand_filename(hostkey_files[i], getuid());
  sshlog("ssh-add.c", __func__, 700, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "looking up host keys for \"%s\" in %s", host, path);
                load_hostkeys(hostkeys, host, path, 0);
  free(path);
 }
 dch->user = user == 
                    ((void *)0) 
                         ? 
                           ((void *)0) 
                                : xstrdup(user);
 dch->hostname = xstrdup(host);
 for (i = 0; i < hostkeys->num_entries; i++) {
  hke = hostkeys->entries + i;
  want_ca = hke->marker == MRK_CA;
  if (hke->marker != MRK_NONE && !want_ca)
   continue;
  sshlog("ssh-add.c", __func__, 711, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "%s%s%s: adding %s %skey from %s:%lu as key %u", user == 
 ((void *)0) 
 ? "": user, user == 
 ((void *)0) 
 ? "" : "@", host, sshkey_type(hke->key), want_ca ? "CA " : "", hke->file, hke->line, dch->nkeys)


                                       ;
  dch->keys = xrecallocarray(dch->keys, dch->nkeys,
      dch->nkeys + 1, sizeof(*dch->keys));
  dch->key_is_ca = xrecallocarray(dch->key_is_ca, dch->nkeys,
      dch->nkeys + 1, sizeof(*dch->key_is_ca));
  if ((r = sshkey_from_private(hke->key,
      &(dch->keys[dch->nkeys]))) != 0)
   sshfatal("ssh-add.c", __func__, 721, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshkey_from_private");
  dch->key_is_ca[dch->nkeys] = want_ca;
  dch->nkeys++;
 }
 if (dch->nkeys == 0)
  sshfatal("ssh-add.c", __func__, 726, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "No host keys found for destination \"%s\"", host);
 free_hostkeys(hostkeys);
 free(os);
 return;
}

static void
parse_dest_constraint(const char *s, struct dest_constraint ***dcp,
    size_t *ndcp, char **hostkey_files)
{
 struct dest_constraint *dc;
 char *os, *cp;

 dc = xcalloc(1, sizeof(*dc));
 os = xstrdup(s);
 if ((cp = strchr(os, '>')) == 
                              ((void *)0)
                                  ) {

  parse_dest_constraint_hop(os, &dc->to, hostkey_files);
 } else {

  *(cp++) = '\0';
  parse_dest_constraint_hop(os, &dc->from, hostkey_files);
  parse_dest_constraint_hop(cp, &dc->to, hostkey_files);
  if (dc->from.user != 
                      ((void *)0)
                          ) {
   sshfatal("ssh-add.c", __func__, 750, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Invalid key constraint %s: cannot specify " "user on 'from' host", os)
                                 ;
  }
 }

 sshlog("ssh-add.c", __func__, 755, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "constraint %zu: %s%s%s (%u keys) > %s%s%s (%u keys)", *ndcp, dc->from.user ? dc->from.user : "", dc->from.user ? "@" : "", dc->from.hostname ? dc->from.hostname : "(ORIGIN)", dc->from.nkeys, dc->to.user ? dc->to.user : "", dc->to.user ? "@" : "", dc->to.hostname ? dc->to.hostname : "(ANY)", dc->to.nkeys)



                                                               ;
 *dcp = xrecallocarray(*dcp, *ndcp, *ndcp + 1, sizeof(**dcp));
 (*dcp)[(*ndcp)++] = dc;
 free(os);
}


static void
usage(void)
{
 fprintf(
        stderr
              ,
"usage: ssh-add [-cDdKkLlqvXx] [-E fingerprint_hash] [-H hostkey_file]\n"
"               [-h destination_constraint] [-S provider] [-t life]\n"



"               [file ...]\n"
"       ssh-add -s pkcs11\n"
"       ssh-add -e pkcs11\n"
"       ssh-add -T pubkey ...\n"
 );
}

int
main(int argc, char **argv)
{
 extern char *BSDoptarg;
 extern int BSDoptind;
 int agent_fd;
 char *pkcs11provider = 
                       ((void *)0)
                           , *skprovider = 
                                           ((void *)0)
                                               ;
 char **dest_constraint_strings = 
                                 ((void *)0)
                                     , **hostkey_files = 
                                                         ((void *)0)
                                                             ;
 int r, i, ch, deleting = 0, ret = 0, key_only = 0, do_download = 0;
 int xflag = 0, lflag = 0, Dflag = 0, qflag = 0, Tflag = 0;
 SyslogFacility log_facility = SYSLOG_FACILITY_AUTH;
 LogLevel log_level = SYSLOG_LEVEL_INFO;
 struct dest_constraint **dest_constraints = 
                                            ((void *)0)
                                                ;
 size_t ndest_constraints = 0;


 sanitise_stdfd();

 __progname = ssh_get_progname(argv[0]);
 seed_rng();

 log_init(__progname, log_level, log_facility, 1);

 setvbuf(
        stdout
              , 
                ((void *)0)
                    , 
                      1
                            , 0);


 switch (r = ssh_get_authentication_socket(&agent_fd)) {
 case 0:
  break;
 case -47:
  fprintf(
         stderr
               , "Could not open a connection to your "
      "authentication agent.\n");
  exit(2);
 default:
  fprintf(
         stderr
               , "Error connecting to agent: %s\n", ssh_err(r));
  exit(2);
 }

 skprovider = getenv("SSH_SK_PROVIDER");

 while ((ch = BSDgetopt(argc, argv, "vkKlLcdDTxXE:e:h:H:M:m:qs:S:t:")) != -1) {
  switch (ch) {
  case 'v':
   if (log_level == SYSLOG_LEVEL_INFO)
    log_level = SYSLOG_LEVEL_DEBUG1;
   else if (log_level < SYSLOG_LEVEL_DEBUG3)
    log_level++;
   break;
  case 'E':
   fingerprint_hash = ssh_digest_alg_by_name(BSDoptarg);
   if (fingerprint_hash == -1)
    sshfatal("ssh-add.c", __func__, 833, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Invalid hash algorithm \"%s\"", BSDoptarg);
   break;
  case 'H':
   stringlist_append(&hostkey_files, BSDoptarg);
   break;
  case 'h':
   stringlist_append(&dest_constraint_strings, BSDoptarg);
   break;
  case 'k':
   key_only = 1;
   break;
  case 'K':
   do_download = 1;
   break;
  case 'l':
  case 'L':
   if (lflag != 0)
    sshfatal("ssh-add.c", __func__, 850, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "-%c flag already specified", lflag);
   lflag = ch;
   break;
  case 'x':
  case 'X':
   if (xflag != 0)
    sshfatal("ssh-add.c", __func__, 856, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "-%c flag already specified", xflag);
   xflag = ch;
   break;
  case 'c':
   confirm = 1;
   break;
  case 'm':
   minleft = (int)strtonum(BSDoptarg, 1, 
                                     (0x7fffffff * 2U + 1U)
                                             , 
                                               ((void *)0)
                                                   );
   if (minleft == 0) {
    usage();
    ret = 1;
    goto done;
   }
   break;
  case 'M':
   maxsign = (int)strtonum(BSDoptarg, 1, 
                                     (0x7fffffff * 2U + 1U)
                                             , 
                                               ((void *)0)
                                                   );
   if (maxsign == 0) {
    usage();
    ret = 1;
    goto done;
   }
   break;
  case 'd':
   deleting = 1;
   break;
  case 'D':
   Dflag = 1;
   break;
  case 's':
   pkcs11provider = BSDoptarg;
   break;
  case 'S':
   skprovider = BSDoptarg;
   break;
  case 'e':
   deleting = 1;
   pkcs11provider = BSDoptarg;
   break;
  case 't':
   if ((lifetime = convtime(BSDoptarg)) == -1 ||
       lifetime < 0 || (u_long)lifetime > 
                                         (4294967295U)
                                                   ) {
    fprintf(
           stderr
                 , "Invalid lifetime\n");
    ret = 1;
    goto done;
   }
   break;
  case 'q':
   qflag = 1;
   break;
  case 'T':
   Tflag = 1;
   break;
  default:
   usage();
   ret = 1;
   goto done;
  }
 }
 log_init(__progname, log_level, log_facility, 1);

 if ((xflag != 0) + (lflag != 0) + (Dflag != 0) > 1)
  sshfatal("ssh-add.c", __func__, 917, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Invalid combination of actions");
 else if (xflag) {
  if (lock_agent(agent_fd, xflag == 'x' ? 1 : 0) == -1)
   ret = 1;
  goto done;
 } else if (lflag) {
  if (list_identities(agent_fd, lflag == 'l' ? 1 : 0) == -1)
   ret = 1;
  goto done;
 } else if (Dflag) {
  if (delete_all(agent_fd, qflag) == -1)
   ret = 1;
  goto done;
 }






 if (hostkey_files == 
                     ((void *)0)
                         ) {

  stringlist_append(&hostkey_files, "~/" ".ssh" "/known_hosts");
  stringlist_append(&hostkey_files, "~/" ".ssh" "/known_hosts2");
  stringlist_append(&hostkey_files, "/usr/local/etc" "/ssh_known_hosts");
  stringlist_append(&hostkey_files, "/usr/local/etc" "/ssh_known_hosts2");
 }
 if (dest_constraint_strings != 
                               ((void *)0)
                                   ) {
  for (i = 0; dest_constraint_strings[i] != 
                                           ((void *)0)
                                               ; i++) {
   parse_dest_constraint(dest_constraint_strings[i],
     &dest_constraints, &ndest_constraints, hostkey_files);
  }
 }

 argc -= BSDoptind;
 argv += BSDoptind;
 if (Tflag) {
  if (argc <= 0)
   sshfatal("ssh-add.c", __func__, 955, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "no keys to test");
  for (r = i = 0; i < argc; i++)
   r |= test_key(agent_fd, argv[i]);
  ret = r == 0 ? 0 : 1;
  goto done;
 }
 if (pkcs11provider != 
                      ((void *)0)
                          ) {
  if (update_card(agent_fd, !deleting, pkcs11provider,
      qflag, dest_constraints, ndest_constraints) == -1)
   ret = 1;
  goto done;
 }
 if (do_download) {
  if (skprovider == 
                   ((void *)0)
                       )
   sshfatal("ssh-add.c", __func__, 969, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Cannot download keys without provider");
  if (load_resident_keys(agent_fd, skprovider, qflag,
      dest_constraints, ndest_constraints) != 0)
   ret = 1;
  goto done;
 }
 if (argc == 0) {
  char buf[
          4096
                  ];
  struct passwd *pw;
  struct stat st;
  int count = 0;

  if ((pw = getpwuid(getuid())) == 
                                  ((void *)0)
                                      ) {
   fprintf(
          stderr
                , "No user found with uid %u\n",
       (u_int)getuid());
   ret = 1;
   goto done;
  }

  for (i = 0; default_files[i]; i++) {
   snprintf(buf, sizeof(buf), "%s/%s", pw->pw_dir,
       default_files[i]);
   if (stat(buf, &st) == -1)
    continue;
   if (do_file(agent_fd, deleting, key_only, buf,
       qflag, skprovider,
       dest_constraints, ndest_constraints) == -1)
    ret = 1;
   else
    count++;
  }
  if (count == 0)
   ret = 1;
 } else {
  for (i = 0; i < argc; i++) {
   if (do_file(agent_fd, deleting, key_only,
       argv[i], qflag, skprovider,
       dest_constraints, ndest_constraints) == -1)
    ret = 1;
  }
 }
done:
 clear_pass();
 ssh_close_authentication_socket(agent_fd);
 return ret;
}
