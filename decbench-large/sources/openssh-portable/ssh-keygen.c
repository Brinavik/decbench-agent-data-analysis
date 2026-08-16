











































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

int pkcs11_init(int);
void pkcs11_terminate(void);
int pkcs11_add_provider(char *, char *, struct sshkey ***, char ***);
int pkcs11_del_provider(char *);
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
struct sshkey;
struct sshbuf;
struct ssh_krl;

struct ssh_krl *ssh_krl_init(void);
void ssh_krl_free(struct ssh_krl *krl);
void ssh_krl_set_version(struct ssh_krl *krl, u_int64_t version);
int ssh_krl_set_comment(struct ssh_krl *krl, const char *comment);
int ssh_krl_revoke_cert_by_serial(struct ssh_krl *krl,
    const struct sshkey *ca_key, u_int64_t serial);
int ssh_krl_revoke_cert_by_serial_range(struct ssh_krl *krl,
    const struct sshkey *ca_key, u_int64_t lo, u_int64_t hi);
int ssh_krl_revoke_cert_by_key_id(struct ssh_krl *krl,
    const struct sshkey *ca_key, const char *key_id);
int ssh_krl_revoke_key_explicit(struct ssh_krl *krl, const struct sshkey *key);
int ssh_krl_revoke_key_sha1(struct ssh_krl *krl, const u_char *p, size_t len);
int ssh_krl_revoke_key_sha256(struct ssh_krl *krl, const u_char *p, size_t len);
int ssh_krl_revoke_key(struct ssh_krl *krl, const struct sshkey *key);
int ssh_krl_to_blob(struct ssh_krl *krl, struct sshbuf *buf,
    struct sshkey **sign_keys, u_int nsign_keys);
int ssh_krl_from_blob(struct sshbuf *buf, struct ssh_krl **krlp,
    const struct sshkey **sign_ca_keys, size_t nsign_ca_keys);
int ssh_krl_check_key(struct ssh_krl *krl, const struct sshkey *key);
int ssh_krl_file_contains_key(const char *path, const struct sshkey *key);
int krl_dump(struct ssh_krl *krl, FILE *f);
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
struct sshsigopt;
struct sshkey_sig_details;

typedef int sshsig_signer(struct sshkey *, u_char **, size_t *,
    const u_char *, size_t, const char *, const char *, const char *,
    u_int, void *);
int sshsig_signb(struct sshkey *key, const char *hashalg,
    const char *sk_provider, const char *sk_pin, const struct sshbuf *message,
    const char *sig_namespace, struct sshbuf **out,
    sshsig_signer *signer, void *signer_ctx);






int sshsig_verifyb(struct sshbuf *signature,
    const struct sshbuf *message, const char *sig_namespace,
    struct sshkey **sign_keyp, struct sshkey_sig_details **sig_details);
int sshsig_sign_fd(struct sshkey *key, const char *hashalg,
    const char *sk_provider, const char *sk_pin,
    int fd, const char *sig_namespace,
    struct sshbuf **out, sshsig_signer *signer, void *signer_ctx);






int sshsig_verify_fd(struct sshbuf *signature, int fd,
    const char *sig_namespace, struct sshkey **sign_keyp,
    struct sshkey_sig_details **sig_details);






int sshsig_armor(const struct sshbuf *blob, struct sshbuf **out);




int sshsig_dearmor(struct sshbuf *sig, struct sshbuf **out);





int sshsig_check_allowed_keys(const char *path, const struct sshkey *sign_key,
    const char *principal, const char *ns, uint64_t verify_time);


struct sshsigopt *sshsigopt_parse(const char *opts,
    const char *path, u_long linenum, const char **errstrp);


void sshsigopt_free(struct sshsigopt *opts);


int sshsig_get_pubkey(struct sshbuf *signature, struct sshkey **pubkey);




int sshsig_find_principals(const char *path, const struct sshkey *sign_key,
    uint64_t verify_time, char **principal);


int sshsig_match_principals(const char *path,
 const char *principal, char ***principalsp, size_t *nprincipalsp);
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
static int quiet = 0;


static int print_fingerprint = 0;
static int print_bubblebabble = 0;


static int fingerprint_hash = 2;


static char identity_file[
                         4096
                                 ];
static int have_identity = 0;


static char *identity_passphrase = 
                                  ((void *)0)
                                      ;


static char *identity_new_passphrase = 
                                      ((void *)0)
                                          ;


static u_int cert_key_type = 1;


static char *cert_key_id = 
                          ((void *)0)
                              ;


static char *cert_principals = 
                              ((void *)0)
                                  ;


static u_int64_t cert_valid_from = 0;
static u_int64_t cert_valid_to = ~0ULL;
static u_int32_t certflags_flags = ((1)|(1<<1)| (1<<2)|(1<<3)|(1<<4));
static char *certflags_command = 
                                ((void *)0)
                                    ;
static char *certflags_src_addr = 
                                 ((void *)0)
                                     ;


struct cert_ext {
 char *key;
 char *val;
 int crit;
};
static struct cert_ext *cert_ext;
static size_t ncert_ext;


enum {
 FMT_RFC4716,
 FMT_PKCS8,
 FMT_PEM
} convert_format = FMT_RFC4716;

static char *key_type_name = 
                            ((void *)0)
                                ;


static char *pkcs11provider = 
                             ((void *)0)
                                 ;


static char *sk_provider = 
                          ((void *)0)
                              ;


static int private_key_format = SSHKEY_PRIVATE_OPENSSH;


static char *openssh_format_cipher = 
                                    ((void *)0)
                                        ;


static int rounds = 0;


extern char *__progname;

static char hostname[
                    1025
                              ];



int gen_candidates(FILE *, u_int32_t, u_int32_t, BIGNUM *);
int prime_test(FILE *, FILE *, u_int32_t, u_int32_t, char *, unsigned long,
    unsigned long);


static void
type_bits_valid(int type, const char *name, u_int32_t *bitsp)
{
 if (type == KEY_UNSPEC)
  sshfatal("ssh-keygen.c", __func__, 186, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "unknown key type %s", key_type_name);
 if (*bitsp == 0) {

  int nid;

  switch(type) {
  case KEY_DSA:
   *bitsp = 1024;
   break;
  case KEY_ECDSA:
   if (name != 
              ((void *)0) 
                   &&
       (nid = sshkey_ecdsa_nid_from_name(name)) > 0)
    *bitsp = sshkey_curve_nid_to_bits(nid);
   if (*bitsp == 0)
    *bitsp = 256;
   break;
  case KEY_RSA:
   *bitsp = 3072;
   break;
  }

 }

 switch (type) {
 case KEY_DSA:
  if (*bitsp != 1024)
   sshfatal("ssh-keygen.c", __func__, 212, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Invalid DSA key length: must be 1024 bits");
  break;
 case KEY_RSA:
  if (*bitsp < 1024)
   sshfatal("ssh-keygen.c", __func__, 216, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Invalid RSA key length: minimum is %d bits", 1024)
                                    ;
  else if (*bitsp > 
                   16384
                                               )
   sshfatal("ssh-keygen.c", __func__, 219, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Invalid RSA key length: maximum is %d bits", 
  16384
  )
                                    ;
  break;
 case KEY_ECDSA:
  if (sshkey_ecdsa_bits_to_nid(*bitsp) == -1)

   sshfatal("ssh-keygen.c", __func__, 225, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Invalid ECDSA key length: valid lengths are " "256, 384 or 521 bits")
                              ;




 }

}







static int
confirm_overwrite(const char *filename)
{
 char yesno[3];
 struct stat st;

 if (stat(filename, &st) != 0)
  return 1;
 printf("%s already exists.\n", filename);
 printf("Overwrite (y/n)? ");
 fflush(
       stdout
             );
 if (fgets(yesno, sizeof(yesno), 
                                stdin
                                     ) == 
                                          ((void *)0)
                                              )
  return 0;
 if (yesno[0] != 'y' && yesno[0] != 'Y')
  return 0;
 return 1;
}

static void
ask_filename(struct passwd *pw, const char *prompt)
{
 char buf[1024];
 char *name = 
             ((void *)0)
                 ;

 if (key_type_name == 
                     ((void *)0)
                         )
  name = ".ssh" "/id_rsa";
 else {
  switch (sshkey_type_from_name(key_type_name)) {
  case KEY_DSA_CERT:
  case KEY_DSA:
   name = ".ssh" "/id_dsa";
   break;

  case KEY_ECDSA_CERT:
  case KEY_ECDSA:
   name = ".ssh" "/id_ecdsa";
   break;
  case KEY_ECDSA_SK_CERT:
  case KEY_ECDSA_SK:
   name = ".ssh" "/id_ecdsa_sk";
   break;

  case KEY_RSA_CERT:
  case KEY_RSA:
   name = ".ssh" "/id_rsa";
   break;
  case KEY_ED25519:
  case KEY_ED25519_CERT:
   name = ".ssh" "/id_ed25519";
   break;
  case KEY_ED25519_SK:
  case KEY_ED25519_SK_CERT:
   name = ".ssh" "/id_ed25519_sk";
   break;
  case KEY_XMSS:
  case KEY_XMSS_CERT:
   name = ".ssh" "/id_xmss";
   break;
  default:
   sshfatal("ssh-keygen.c", __func__, 300, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "bad key type");
  }
 }
 snprintf(identity_file, sizeof(identity_file),
     "%s/%s", pw->pw_dir, name);
 printf("%s (%s): ", prompt, identity_file);
 fflush(
       stdout
             );
 if (fgets(buf, sizeof(buf), 
                            stdin
                                 ) == 
                                      ((void *)0)
                                          )
  exit(1);
 buf[strcspn(buf, "\n")] = '\0';
 if (strcmp(buf, "") != 0)
  strlcpy(identity_file, buf, sizeof(identity_file));
 have_identity = 1;
}

static struct sshkey *
load_identity(const char *filename, char **commentp)
{
 char *pass;
 struct sshkey *prv;
 int r;

 if (commentp != 
                ((void *)0)
                    )
  *commentp = 
             ((void *)0)
                 ;
 if ((r = sshkey_load_private(filename, "", &prv, commentp)) == 0)
  return prv;
 if (r != -43)
  sshfatal("ssh-keygen.c", __func__, 327, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Load key \"%s\"", filename);
 if (identity_passphrase)
  pass = xstrdup(identity_passphrase);
 else
  pass = read_passphrase("Enter passphrase: ", 0x0002);
 r = sshkey_load_private(filename, pass, &prv, commentp);
 freezero(pass, strlen(pass));
 if (r != 0)
  sshfatal("ssh-keygen.c", __func__, 335, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Load key \"%s\"", filename);
 return prv;
}







static void
do_convert_to_ssh2(struct passwd *pw, struct sshkey *k)
{
 struct sshbuf *b;
 char comment[61], *b64;
 int r;

 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("ssh-keygen.c", __func__, 353, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshkey_putb(k, b)) != 0)
  sshfatal("ssh-keygen.c", __func__, 355, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "put key");
 if ((b64 = sshbuf_dtob64_string(b, 1)) == 
                                          ((void *)0)
                                              )
  sshfatal("ssh-keygen.c", __func__, 357, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_dtob64_string failed");


 snprintf(comment, sizeof(comment),
     "%u-bit %s, converted by %s@%s from OpenSSH",
     sshkey_size(k), sshkey_type(k),
     pw->pw_name, hostname);

 sshkey_free(k);
 sshbuf_free(b);

 fprintf(
        stdout
              , "%s\n", "---- BEGIN SSH2 PUBLIC KEY ----");
 fprintf(
        stdout
              , "Comment: \"%s\"\n%s", comment, b64);
 fprintf(
        stdout
              , "%s\n", "---- END SSH2 PUBLIC KEY ----");
 free(b64);
 exit(0);
}

static void
do_convert_to_pkcs8(struct sshkey *k)
{
 switch (sshkey_type_plain(k->type)) {
 case KEY_RSA:
  if (!PEM_write_RSA_PUBKEY(
                           stdout
                                 , k->rsa))
   sshfatal("ssh-keygen.c", __func__, 381, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "PEM_write_RSA_PUBKEY failed");
  break;
 case KEY_DSA:
  if (!PEM_write_DSA_PUBKEY(
                           stdout
                                 , k->dsa))
   sshfatal("ssh-keygen.c", __func__, 385, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "PEM_write_DSA_PUBKEY failed");
  break;

 case KEY_ECDSA:
  if (!PEM_write_EC_PUBKEY(
                          stdout
                                , k->ecdsa))
   sshfatal("ssh-keygen.c", __func__, 390, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "PEM_write_EC_PUBKEY failed");
  break;

 default:
  sshfatal("ssh-keygen.c", __func__, 394, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "unsupported key type %s", sshkey_type(k));
 }
 exit(0);
}

static void
do_convert_to_pem(struct sshkey *k)
{
 switch (sshkey_type_plain(k->type)) {
 case KEY_RSA:
  if (!PEM_write_RSAPublicKey(
                             stdout
                                   , k->rsa))
   sshfatal("ssh-keygen.c", __func__, 405, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "PEM_write_RSAPublicKey failed");
  break;
 case KEY_DSA:
  if (!PEM_write_DSA_PUBKEY(
                           stdout
                                 , k->dsa))
   sshfatal("ssh-keygen.c", __func__, 409, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "PEM_write_DSA_PUBKEY failed");
  break;

 case KEY_ECDSA:
  if (!PEM_write_EC_PUBKEY(
                          stdout
                                , k->ecdsa))
   sshfatal("ssh-keygen.c", __func__, 414, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "PEM_write_EC_PUBKEY failed");
  break;

 default:
  sshfatal("ssh-keygen.c", __func__, 418, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "unsupported key type %s", sshkey_type(k));
 }
 exit(0);
}

static void
do_convert_to(struct passwd *pw)
{
 struct sshkey *k;
 struct stat st;
 int r;

 if (!have_identity)
  ask_filename(pw, "Enter file in which the key is");
 if (stat(identity_file, &st) == -1)
  sshfatal("ssh-keygen.c", __func__, 433, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: %s: %s", __progname, identity_file, strerror(
 (*__errno_location ())
 ));
 if ((r = sshkey_load_public(identity_file, &k, 
                                               ((void *)0)
                                                   )) != 0)
  k = load_identity(identity_file, 
                                  ((void *)0)
                                      );
 switch (convert_format) {
 case FMT_RFC4716:
  do_convert_to_ssh2(pw, k);
  break;
 case FMT_PKCS8:
  do_convert_to_pkcs8(k);
  break;
 case FMT_PEM:
  do_convert_to_pem(k);
  break;
 default:
  sshfatal("ssh-keygen.c", __func__, 447, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "unknown key format %d", convert_format);
 }
 exit(0);
}





static void
buffer_get_bignum_bits(struct sshbuf *b, BIGNUM *value)
{
 u_int bytes, bignum_bits;
 int r;

 if ((r = sshbuf_get_u32(b, &bignum_bits)) != 0)
  sshfatal("ssh-keygen.c", __func__, 463, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 bytes = (bignum_bits + 7) / 8;
 if (sshbuf_len(b) < bytes)
  sshfatal("ssh-keygen.c", __func__, 466, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "input buffer too small: need %d have %zu", bytes, sshbuf_len(b))
                           ;
 if (BN_bin2bn(sshbuf_ptr(b), bytes, value) == 
                                              ((void *)0)
                                                  )
  sshfatal("ssh-keygen.c", __func__, 469, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "BN_bin2bn failed");
 if ((r = sshbuf_consume(b, bytes)) != 0)
  sshfatal("ssh-keygen.c", __func__, 471, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "consume");
}

static struct sshkey *
do_convert_private_ssh2(struct sshbuf *b)
{
 struct sshkey *key = 
                     ((void *)0)
                         ;
 char *type, *cipher;
 u_char e1, e2, e3, *sig = 
                          ((void *)0)
                              , data[] = "abcde12345";
 int r, rlen, ktype;
 u_int magic, i1, i2, i3, i4;
 size_t slen;
 u_long e;
 BIGNUM *dsa_p = 
                ((void *)0)
                    , *dsa_q = 
                               ((void *)0)
                                   , *dsa_g = 
                                              ((void *)0)
                                                  ;
 BIGNUM *dsa_pub_key = 
                      ((void *)0)
                          , *dsa_priv_key = 
                                            ((void *)0)
                                                ;
 BIGNUM *rsa_n = 
                ((void *)0)
                    , *rsa_e = 
                               ((void *)0)
                                   , *rsa_d = 
                                              ((void *)0)
                                                  ;
 BIGNUM *rsa_p = 
                ((void *)0)
                    , *rsa_q = 
                               ((void *)0)
                                   , *rsa_iqmp = 
                                                 ((void *)0)
                                                     ;

 if ((r = sshbuf_get_u32(b, &magic)) != 0)
  sshfatal("ssh-keygen.c", __func__, 490, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse magic");

 if (magic != 0x3f6ff9eb) {
  sshlog("ssh-keygen.c", __func__, 493, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "bad magic 0x%x != 0x%x", magic, 0x3f6ff9eb)
                                ;
  return 
        ((void *)0)
            ;
 }
 if ((r = sshbuf_get_u32(b, &i1)) != 0 ||
     (r = sshbuf_get_cstring(b, &type, 
                                      ((void *)0)
                                          )) != 0 ||
     (r = sshbuf_get_cstring(b, &cipher, 
                                        ((void *)0)
                                            )) != 0 ||
     (r = sshbuf_get_u32(b, &i2)) != 0 ||
     (r = sshbuf_get_u32(b, &i3)) != 0 ||
     (r = sshbuf_get_u32(b, &i4)) != 0)
  sshfatal("ssh-keygen.c", __func__, 503, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse");
 sshlog("ssh-keygen.c", __func__, 504, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "ignore (%d %d %d %d)", i1, i2, i3, i4);
 if (strcmp(cipher, "none") != 0) {
  sshlog("ssh-keygen.c", __func__, 506, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unsupported cipher %s", cipher);
  free(cipher);
  free(type);
  return 
        ((void *)0)
            ;
 }
 free(cipher);

 if (strstr(type, "dsa")) {
  ktype = KEY_DSA;
 } else if (strstr(type, "rsa")) {
  ktype = KEY_RSA;
 } else {
  free(type);
  return 
        ((void *)0)
            ;
 }
 if ((key = sshkey_new(ktype)) == 
                                 ((void *)0)
                                     )
  sshfatal("ssh-keygen.c", __func__, 522, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshkey_new failed");
 free(type);

 switch (key->type) {
 case KEY_DSA:
  if ((dsa_p = BN_new()) == 
                           ((void *)0) 
                                ||
      (dsa_q = BN_new()) == 
                           ((void *)0) 
                                ||
      (dsa_g = BN_new()) == 
                           ((void *)0) 
                                ||
      (dsa_pub_key = BN_new()) == 
                                 ((void *)0) 
                                      ||
      (dsa_priv_key = BN_new()) == 
                                  ((void *)0)
                                      )
   sshfatal("ssh-keygen.c", __func__, 532, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "BN_new");
  buffer_get_bignum_bits(b, dsa_p);
  buffer_get_bignum_bits(b, dsa_g);
  buffer_get_bignum_bits(b, dsa_q);
  buffer_get_bignum_bits(b, dsa_pub_key);
  buffer_get_bignum_bits(b, dsa_priv_key);
  if (!DSA_set0_pqg(key->dsa, dsa_p, dsa_q, dsa_g))
   sshfatal("ssh-keygen.c", __func__, 539, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "DSA_set0_pqg failed");
  dsa_p = dsa_q = dsa_g = 
                         ((void *)0)
                             ;
  if (!DSA_set0_key(key->dsa, dsa_pub_key, dsa_priv_key))
   sshfatal("ssh-keygen.c", __func__, 542, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "DSA_set0_key failed");
  dsa_pub_key = dsa_priv_key = 
                              ((void *)0)
                                  ;
  break;
 case KEY_RSA:
  if ((r = sshbuf_get_u8(b, &e1)) != 0 ||
      (e1 < 30 && (r = sshbuf_get_u8(b, &e2)) != 0) ||
      (e1 < 30 && (r = sshbuf_get_u8(b, &e3)) != 0))
   sshfatal("ssh-keygen.c", __func__, 549, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse RSA");
  e = e1;
  sshlog("ssh-keygen.c", __func__, 551, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "e %lx", e);
  if (e < 30) {
   e <<= 8;
   e += e2;
   sshlog("ssh-keygen.c", __func__, 555, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "e %lx", e);
   e <<= 8;
   e += e3;
   sshlog("ssh-keygen.c", __func__, 558, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "e %lx", e);
  }
  if ((rsa_e = BN_new()) == 
                           ((void *)0)
                               )
   sshfatal("ssh-keygen.c", __func__, 561, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "BN_new");
  if (!BN_set_word(rsa_e, e)) {
   BN_clear_free(rsa_e);
   sshkey_free(key);
   return 
         ((void *)0)
             ;
  }
  if ((rsa_n = BN_new()) == 
                           ((void *)0) 
                                ||
      (rsa_d = BN_new()) == 
                           ((void *)0) 
                                ||
      (rsa_p = BN_new()) == 
                           ((void *)0) 
                                ||
      (rsa_q = BN_new()) == 
                           ((void *)0) 
                                ||
      (rsa_iqmp = BN_new()) == 
                              ((void *)0)
                                  )
   sshfatal("ssh-keygen.c", __func__, 572, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "BN_new");
  buffer_get_bignum_bits(b, rsa_d);
  buffer_get_bignum_bits(b, rsa_n);
  buffer_get_bignum_bits(b, rsa_iqmp);
  buffer_get_bignum_bits(b, rsa_q);
  buffer_get_bignum_bits(b, rsa_p);
  if (!RSA_set0_key(key->rsa, rsa_n, rsa_e, rsa_d))
   sshfatal("ssh-keygen.c", __func__, 579, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "RSA_set0_key failed");
  rsa_n = rsa_e = rsa_d = 
                         ((void *)0)
                             ;
  if (!RSA_set0_factors(key->rsa, rsa_p, rsa_q))
   sshfatal("ssh-keygen.c", __func__, 582, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "RSA_set0_factors failed");
  rsa_p = rsa_q = 
                 ((void *)0)
                     ;
  if ((r = ssh_rsa_complete_crt_parameters(key, rsa_iqmp)) != 0)
   sshfatal("ssh-keygen.c", __func__, 585, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "generate RSA parameters");
  BN_clear_free(rsa_iqmp);
  break;
 }
 rlen = sshbuf_len(b);
 if (rlen != 0)
  sshlog("ssh-keygen.c", __func__, 591, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "remaining bytes in key blob %d", rlen);


 if ((r = sshkey_sign(key, &sig, &slen, data, sizeof(data),
     
    ((void *)0)
        , 
          ((void *)0)
              , 
                ((void *)0)
                    , 0)) != 0)
  sshlog("ssh-keygen.c", __func__, 596, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "signing with converted key failed");
 else if ((r = sshkey_verify(key, sig, slen, data, sizeof(data),
     
    ((void *)0)
        , 0, 
             ((void *)0)
                 )) != 0)
  sshlog("ssh-keygen.c", __func__, 599, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "verification with converted key failed");
 if (r != 0) {
  sshkey_free(key);
  free(sig);
  return 
        ((void *)0)
            ;
 }
 free(sig);
 return key;
}

static int
get_line(FILE *fp, char *line, size_t len)
{
 int c;
 size_t pos = 0;

 line[0] = '\0';
 while ((c = fgetc(fp)) != 
                          (-1)
                             ) {
  if (pos >= len - 1)
   sshfatal("ssh-keygen.c", __func__, 618, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "input line too long.");
  switch (c) {
  case '\r':
   c = fgetc(fp);
   if (c != 
           (-1) 
               && c != '\n' && ungetc(c, fp) == 
                                                (-1)
                                                   )
    sshfatal("ssh-keygen.c", __func__, 623, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "unget: %s", strerror(
   (*__errno_location ())
   ));
   return pos;
  case '\n':
   return pos;
  }
  line[pos++] = c;
  line[pos] = '\0';
 }

 return -1;
}

static void
do_convert_from_ssh2(struct passwd *pw, struct sshkey **k, int *private)
{
 int r, blen, escaped = 0;
 u_int len;
 char line[1024];
 struct sshbuf *buf;
 char encoded[8096];
 FILE *fp;

 if ((buf = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("ssh-keygen.c", __func__, 646, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((fp = fopen(identity_file, "r")) == 
                                        ((void *)0)
                                            )
  sshfatal("ssh-keygen.c", __func__, 648, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: %s: %s", __progname, identity_file, strerror(
 (*__errno_location ())
 ));
 encoded[0] = '\0';
 while ((blen = get_line(fp, line, sizeof(line))) != -1) {
  if (blen > 0 && line[blen - 1] == '\\')
   escaped++;
  if (strncmp(line, "----", 4) == 0 ||
      strstr(line, ": ") != 
                           ((void *)0)
                               ) {
   if (strstr(line, "---- BEGIN SSH2 ENCRYPTED PRIVATE KEY ----") != 
                                             ((void *)0)
                                                 )
    *private = 1;
   if (strstr(line, " END ") != 
                               ((void *)0)
                                   ) {
    break;
   }

   continue;
  }
  if (escaped) {
   escaped--;

   continue;
  }
  strlcat(encoded, line, sizeof(encoded));
 }
 len = strlen(encoded);
 if (((len % 4) == 3) &&
     (encoded[len-1] == '=') &&
     (encoded[len-2] == '=') &&
     (encoded[len-3] == '='))
  encoded[len-3] = '\0';
 if ((r = sshbuf_b64tod(buf, encoded)) != 0)
  sshfatal("ssh-keygen.c", __func__, 677, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "base64 decode");
 if (*private) {
  if ((*k = do_convert_private_ssh2(buf)) == 
                                            ((void *)0)
                                                )
   sshfatal("ssh-keygen.c", __func__, 680, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "private key conversion failed");
 } else if ((r = sshkey_fromb(buf, k)) != 0)
  sshfatal("ssh-keygen.c", __func__, 682, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse key");
 sshbuf_free(buf);
 fclose(fp);
}

static void
do_convert_from_pkcs8(struct sshkey **k, int *private)
{
 EVP_PKEY *pubkey;
 FILE *fp;

 if ((fp = fopen(identity_file, "r")) == 
                                        ((void *)0)
                                            )
  sshfatal("ssh-keygen.c", __func__, 694, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: %s: %s", __progname, identity_file, strerror(
 (*__errno_location ())
 ));
 if ((pubkey = PEM_read_PUBKEY(fp, 
                                  ((void *)0)
                                      , 
                                        ((void *)0)
                                            , 
                                              ((void *)0)
                                                  )) == 
                                                        ((void *)0)
                                                            ) {
  sshfatal("ssh-keygen.c", __func__, 696, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s is not a recognised public key format", identity_file)
                    ;
 }
 fclose(fp);
 switch (
        EVP_PKEY_get_base_id
                        (pubkey)) {
 case 
     6
                 :
  if ((*k = sshkey_new(KEY_UNSPEC)) == 
                                      ((void *)0)
                                          )
   sshfatal("ssh-keygen.c", __func__, 703, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshkey_new failed");
  (*k)->type = KEY_RSA;
  (*k)->rsa = EVP_PKEY_get1_RSA(pubkey);
  break;
 case 
     116
                 :
  if ((*k = sshkey_new(KEY_UNSPEC)) == 
                                      ((void *)0)
                                          )
   sshfatal("ssh-keygen.c", __func__, 709, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshkey_new failed");
  (*k)->type = KEY_DSA;
  (*k)->dsa = EVP_PKEY_get1_DSA(pubkey);
  break;

 case 
     408
                :
  if ((*k = sshkey_new(KEY_UNSPEC)) == 
                                      ((void *)0)
                                          )
   sshfatal("ssh-keygen.c", __func__, 716, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshkey_new failed");
  (*k)->type = KEY_ECDSA;
  (*k)->ecdsa = EVP_PKEY_get1_EC_KEY(pubkey);
  (*k)->ecdsa_nid = sshkey_ecdsa_key_to_nid((*k)->ecdsa);
  break;

 default:
  sshfatal("ssh-keygen.c", __func__, 723, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "unsupported pubkey type %d", 
 EVP_PKEY_get_base_id
 (pubkey))
                               ;
 }
 EVP_PKEY_free(pubkey);
 return;
}

static void
do_convert_from_pem(struct sshkey **k, int *private)
{
 FILE *fp;
 RSA *rsa;

 if ((fp = fopen(identity_file, "r")) == 
                                        ((void *)0)
                                            )
  sshfatal("ssh-keygen.c", __func__, 737, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: %s: %s", __progname, identity_file, strerror(
 (*__errno_location ())
 ));
 if ((rsa = PEM_read_RSAPublicKey(fp, 
                                     ((void *)0)
                                         , 
                                           ((void *)0)
                                               , 
                                                 ((void *)0)
                                                     )) != 
                                                           ((void *)0)
                                                               ) {
  if ((*k = sshkey_new(KEY_UNSPEC)) == 
                                      ((void *)0)
                                          )
   sshfatal("ssh-keygen.c", __func__, 740, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshkey_new failed");
  (*k)->type = KEY_RSA;
  (*k)->rsa = rsa;
  fclose(fp);
  return;
 }
 sshfatal("ssh-keygen.c", __func__, 746, 1, SYSLOG_LEVEL_FATAL, 
((void *)0)
, "unrecognised raw private key format");
}

static void
do_convert_from(struct passwd *pw)
{
 struct sshkey *k = 
                   ((void *)0)
                       ;
 int r, private = 0, ok = 0;
 struct stat st;

 if (!have_identity)
  ask_filename(pw, "Enter file in which the key is");
 if (stat(identity_file, &st) == -1)
  sshfatal("ssh-keygen.c", __func__, 759, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: %s: %s", __progname, identity_file, strerror(
 (*__errno_location ())
 ));

 switch (convert_format) {
 case FMT_RFC4716:
  do_convert_from_ssh2(pw, &k, &private);
  break;
 case FMT_PKCS8:
  do_convert_from_pkcs8(&k, &private);
  break;
 case FMT_PEM:
  do_convert_from_pem(&k, &private);
  break;
 default:
  sshfatal("ssh-keygen.c", __func__, 772, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "unknown key format %d", convert_format);
 }

 if (!private) {
  if ((r = sshkey_write(k, 
                          stdout
                                )) == 0)
   ok = 1;
  if (ok)
   fprintf(
          stdout
                , "\n");
 } else {
  switch (k->type) {
  case KEY_DSA:
   ok = PEM_write_DSAPrivateKey(
                               stdout
                                     , k->dsa, 
                                               ((void *)0)
                                                   ,
       
      ((void *)0)
          , 0, 
               ((void *)0)
                   , 
                     ((void *)0)
                         );
   break;

  case KEY_ECDSA:
   ok = PEM_write_ECPrivateKey(
                              stdout
                                    , k->ecdsa, 
                                                ((void *)0)
                                                    ,
       
      ((void *)0)
          , 0, 
               ((void *)0)
                   , 
                     ((void *)0)
                         );
   break;

  case KEY_RSA:
   ok = PEM_write_RSAPrivateKey(
                               stdout
                                     , k->rsa, 
                                               ((void *)0)
                                                   ,
       
      ((void *)0)
          , 0, 
               ((void *)0)
                   , 
                     ((void *)0)
                         );
   break;
  default:
   sshfatal("ssh-keygen.c", __func__, 797, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "unsupported key type %s", sshkey_type(k));
  }
 }

 if (!ok)
  sshfatal("ssh-keygen.c", __func__, 802, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "key write failed");
 sshkey_free(k);
 exit(0);
}


static void
do_print_public(struct passwd *pw)
{
 struct sshkey *prv;
 struct stat st;
 int r;
 char *comment = 
                ((void *)0)
                    ;

 if (!have_identity)
  ask_filename(pw, "Enter file in which the key is");
 if (stat(identity_file, &st) == -1)
  sshfatal("ssh-keygen.c", __func__, 819, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: %s", identity_file, strerror(
 (*__errno_location ())
 ));
 prv = load_identity(identity_file, &comment);
 if ((r = sshkey_write(prv, 
                           stdout
                                 )) != 0)
  sshfatal("ssh-keygen.c", __func__, 822, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "write key");
 if (comment != 
               ((void *)0) 
                    && *comment != '\0')
  fprintf(
         stdout
               , " %s", comment);
 fprintf(
        stdout
              , "\n");
 if (sshkey_is_sk(prv)) {
  sshlog("ssh-keygen.c", __func__, 827, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "sk_application: \"%s\", sk_flags 0x%02x", prv->sk_application, prv->sk_flags)
                                      ;
 }
 sshkey_free(prv);
 free(comment);
 exit(0);
}

static void
do_download(struct passwd *pw)
{

 struct sshkey **keys = 
                       ((void *)0)
                           ;
 int i, nkeys;
 enum sshkey_fp_rep rep;
 int fptype;
 char *fp, *ra, **comments = 
                            ((void *)0)
                                ;

 fptype = print_bubblebabble ? 1 : fingerprint_hash;
 rep = print_bubblebabble ? SSH_FP_BUBBLEBABBLE : SSH_FP_DEFAULT;

 pkcs11_init(1);
 nkeys = pkcs11_add_provider(pkcs11provider, 
                                            ((void *)0)
                                                , &keys, &comments);
 if (nkeys <= 0)
  sshfatal("ssh-keygen.c", __func__, 851, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "cannot read public key from pkcs11");
 for (i = 0; i < nkeys; i++) {
  if (print_fingerprint) {
   fp = sshkey_fingerprint(keys[i], fptype, rep);
   ra = sshkey_fingerprint(keys[i], fingerprint_hash,
       SSH_FP_RANDOMART);
   if (fp == 
            ((void *)0) 
                 || ra == 
                          ((void *)0)
                              )
    sshfatal("ssh-keygen.c", __func__, 858, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "sshkey_fingerprint fail");
   printf("%u %s %s (PKCS11 key)\n", sshkey_size(keys[i]),
       fp, sshkey_type(keys[i]));
   if (log_level_get() >= SYSLOG_LEVEL_VERBOSE)
    printf("%s\n", ra);
   free(ra);
   free(fp);
  } else {
   (void) sshkey_write(keys[i], 
                               stdout
                                     );
   fprintf(
          stdout
                , "%s%s\n",
       *(comments[i]) == '\0' ? "" : " ", comments[i]);
  }
  free(comments[i]);
  sshkey_free(keys[i]);
 }
 free(comments);
 free(keys);
 pkcs11_terminate();
 exit(0);



}

static struct sshkey *
try_read_key(char **cpp)
{
 struct sshkey *ret;
 int r;

 if ((ret = sshkey_new(KEY_UNSPEC)) == 
                                      ((void *)0)
                                          )
  sshfatal("ssh-keygen.c", __func__, 889, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshkey_new failed");
 if ((r = sshkey_read(ret, cpp)) == 0)
  return ret;

 sshkey_free(ret);
 return 
       ((void *)0)
           ;
}

static void
fingerprint_one_key(const struct sshkey *public, const char *comment)
{
 char *fp = 
           ((void *)0)
               , *ra = 
                       ((void *)0)
                           ;
 enum sshkey_fp_rep rep;
 int fptype;

 fptype = print_bubblebabble ? 1 : fingerprint_hash;
 rep = print_bubblebabble ? SSH_FP_BUBBLEBABBLE : SSH_FP_DEFAULT;
 fp = sshkey_fingerprint(public, fptype, rep);
 ra = sshkey_fingerprint(public, fingerprint_hash, SSH_FP_RANDOMART);
 if (fp == 
          ((void *)0) 
               || ra == 
                        ((void *)0)
                            )
  sshfatal("ssh-keygen.c", __func__, 909, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshkey_fingerprint failed");
 mprintf("%u %s %s (%s)\n", sshkey_size(public), fp,
     comment ? comment : "no comment", sshkey_type(public));
 if (log_level_get() >= SYSLOG_LEVEL_VERBOSE)
  printf("%s\n", ra);
 free(ra);
 free(fp);
}

static void
fingerprint_private(const char *path)
{
 struct stat st;
 char *comment = 
                ((void *)0)
                    ;
 struct sshkey *privkey = 
                         ((void *)0)
                             , *pubkey = 
                                         ((void *)0)
                                             ;
 int r;

 if (stat(identity_file, &st) == -1)
  sshfatal("ssh-keygen.c", __func__, 927, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: %s", path, strerror(
 (*__errno_location ())
 ));
 if ((r = sshkey_load_public(path, &pubkey, &comment)) != 0)
  sshlog("ssh-keygen.c", __func__, 929, 0, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "load public \"%s\"", path);
 if (pubkey == 
              ((void *)0) 
                   || comment == 
                                 ((void *)0) 
                                      || *comment == '\0') {
  free(comment);
  if ((r = sshkey_load_private(path, 
                                    ((void *)0)
                                        ,
      &privkey, &comment)) != 0)
   sshlog("ssh-keygen.c", __func__, 934, 0, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "load private \"%s\"", path);
 }
 if (pubkey == 
              ((void *)0) 
                   && privkey == 
                                 ((void *)0)
                                     )
  sshfatal("ssh-keygen.c", __func__, 937, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s is not a key file.", path);

 fingerprint_one_key(pubkey == 
                              ((void *)0) 
                                   ? privkey : pubkey, comment);
 sshkey_free(pubkey);
 sshkey_free(privkey);
 free(comment);
}

static void
do_fingerprint(struct passwd *pw)
{
 FILE *f;
 struct sshkey *public = 
                        ((void *)0)
                            ;
 char *comment = 
                ((void *)0)
                    , *cp, *ep, *line = 
                                        ((void *)0)
                                            ;
 size_t linesize = 0;
 int i, invalid = 1;
 const char *path;
 u_long lnum = 0;

 if (!have_identity)
  ask_filename(pw, "Enter file in which the key is");
 path = identity_file;

 if (strcmp(identity_file, "-") == 0) {
  f = 
     stdin
          ;
  path = "(stdin)";
 } else if ((f = fopen(path, "r")) == 
                                     ((void *)0)
                                         )
  sshfatal("ssh-keygen.c", __func__, 964, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: %s: %s", __progname, path, strerror(
 (*__errno_location ())
 ));

 while (getline(&line, &linesize, f) != -1) {
  lnum++;
  cp = line;
  cp[strcspn(cp, "\n")] = '\0';

  cp = line + strspn(line, " \t");
  if (*cp == '#' || *cp == '\0')
   continue;
  if (lnum == 1 && strcmp(identity_file, "-") != 0 &&
      strstr(cp, "PRIVATE KEY") != 
                                  ((void *)0)
                                      ) {
   free(line);
   fclose(f);
   fingerprint_private(path);
   exit(0);
  }






  if ((public = try_read_key(&cp)) == 
                                     ((void *)0)
                                         ) {
   i = strtol(cp, &ep, 10);
   if (i == 0 || ep == 
                      ((void *)0) 
                           ||
       (*ep != ' ' && *ep != '\t')) {
    int quoted = 0;

    comment = cp;
    for (; *cp && (quoted || (*cp != ' ' &&
        *cp != '\t')); cp++) {
     if (*cp == '\\' && cp[1] == '"')
      cp++;
     else if (*cp == '"')
      quoted = !quoted;
    }
    if (!*cp)
     continue;
    *cp++ = '\0';
   }
  }

  if (public == 
               ((void *)0) 
                    && (public = try_read_key(&cp)) == 
                                                       ((void *)0)
                                                           ) {
   sshlog("ssh-keygen.c", __func__, 1019, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "%s:%lu: not a public key", path, lnum);
   continue;
  }


  for (; *cp == ' ' || *cp == '\t'; cp++)
   ;
  if (*cp != '\0' && *cp != '#')
   comment = cp;

  fingerprint_one_key(public, comment);
  sshkey_free(public);
  invalid = 0;
 }
 fclose(f);
 free(line);

 if (invalid)
  sshfatal("ssh-keygen.c", __func__, 1037, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s is not a public key file.", path);
 exit(0);
}

static void
do_gen_all_hostkeys(struct passwd *pw)
{
 struct {
  char *key_type;
  char *key_type_display;
  char *path;
 } key_types[] = {

  { "rsa", "RSA" ,"/usr/local/etc" "/ssh_host_rsa_key" },

  { "ecdsa", "ECDSA","/usr/local/etc" "/ssh_host_ecdsa_key" },


  { "ed25519", "ED25519","/usr/local/etc" "/ssh_host_ed25519_key" },



  { 
   ((void *)0)
       , 
         ((void *)0)
             , 
               ((void *)0) 
                    }
 };

 u_int32_t bits = 0;
 int first = 0;
 struct stat st;
 struct sshkey *private, *public;
 char comment[1024], *prv_tmp, *pub_tmp, *prv_file, *pub_file;
 int i, type, fd, r;

 for (i = 0; key_types[i].key_type; i++) {
  public = private = 
                    ((void *)0)
                        ;
  prv_tmp = pub_tmp = prv_file = pub_file = 
                                           ((void *)0)
                                               ;

  xasprintf(&prv_file, "%s%s",
      identity_file, key_types[i].path);


  if (stat(prv_file, &st) == 0) {
   if (st.st_size != 0)
    goto next;
  } else if (
            (*__errno_location ()) 
                  != 
                     2
                           ) {
   sshlog("ssh-keygen.c", __func__, 1081, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Could not stat %s: %s", key_types[i].path, strerror(
  (*__errno_location ())
  ))
                       ;
   goto failnext;
  }





  xasprintf(&prv_tmp, "%s%s.XXXXXXXXXX",
      identity_file, key_types[i].path);
  xasprintf(&pub_tmp, "%s%s.pub.XXXXXXXXXX",
      identity_file, key_types[i].path);
  xasprintf(&pub_file, "%s%s.pub",
      identity_file, key_types[i].path);

  if (first == 0) {
   first = 1;
   printf("%s: generating new host keys: ", __progname);
  }
  printf("%s ", key_types[i].key_type_display);
  fflush(
        stdout
              );
  type = sshkey_type_from_name(key_types[i].key_type);
  if ((fd = mkstemp(prv_tmp)) == -1) {
   sshlog("ssh-keygen.c", __func__, 1105, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Could not save your private key in %s: %s", prv_tmp, strerror(
  (*__errno_location ())
  ))
                                ;
   goto failnext;
  }
  (void)close(fd);
  bits = 0;
  type_bits_valid(type, 
                       ((void *)0)
                           , &bits);
  if ((r = sshkey_generate(type, bits, &private)) != 0) {
   sshlog("ssh-keygen.c", __func__, 1113, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshkey_generate failed");
   goto failnext;
  }
  if ((r = sshkey_from_private(private, &public)) != 0)
   sshfatal("ssh-keygen.c", __func__, 1117, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshkey_from_private");
  snprintf(comment, sizeof comment, "%s@%s", pw->pw_name,
      hostname);
  if ((r = sshkey_save_private(private, prv_tmp, "",
      comment, private_key_format, openssh_format_cipher,
      rounds)) != 0) {
   sshlog("ssh-keygen.c", __func__, 1123, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Saving key \"%s\" failed", prv_tmp);
   goto failnext;
  }
  if ((fd = mkstemp(pub_tmp)) == -1) {
   sshlog("ssh-keygen.c", __func__, 1127, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Could not save your public key in %s: %s", pub_tmp, strerror(
  (*__errno_location ())
  ))
                                ;
   goto failnext;
  }
  (void)fchmod(fd, 0644);
  (void)close(fd);
  if ((r = sshkey_save_public(public, pub_tmp, comment)) != 0) {
   sshlog("ssh-keygen.c", __func__, 1134, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Unable to save public key to %s", identity_file)
                     ;
   goto failnext;
  }


  if (rename(pub_tmp, pub_file) != 0) {
   sshlog("ssh-keygen.c", __func__, 1141, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Unable to move %s into position: %s", pub_file, strerror(
  (*__errno_location ())
  ))
                                 ;
   goto failnext;
  }
  if (rename(prv_tmp, prv_file) != 0) {
   sshlog("ssh-keygen.c", __func__, 1146, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Unable to move %s into position: %s", key_types[i].path, strerror(
  (*__errno_location ())
  ))
                                          ;
 failnext:
   first = 0;
   goto next;
  }
 next:
  sshkey_free(private);
  sshkey_free(public);
  free(prv_tmp);
  free(pub_tmp);
  free(prv_file);
  free(pub_file);
 }
 if (first != 0)
  printf("\n");
}

struct known_hosts_ctx {
 const char *host;
 FILE *out;
 int has_unhashed;
 int found_key;
 int invalid;
 int hash_hosts;
 int find_host;
 int delete_host;
};

static int
known_hosts_hash(struct hostkey_foreach_line *l, void *_ctx)
{
 struct known_hosts_ctx *ctx = (struct known_hosts_ctx *)_ctx;
 char *hashed, *cp, *hosts, *ohosts;
 int has_wild = l->hosts && strcspn(l->hosts, "*?!") != strlen(l->hosts);
 int was_hashed = l->hosts && l->hosts[0] == '|';

 switch (l->status) {
 case 0:
 case 3:




  if (was_hashed || has_wild || l->marker != MRK_NONE) {
   fprintf(ctx->out, "%s\n", l->line);
   if (has_wild && !ctx->find_host) {
    sshlog("ssh-keygen.c", __func__, 1193, 0, SYSLOG_LEVEL_INFO, 
   ((void *)0)
   , "%s:%lu: ignoring host name " "with wildcard: %.64s", l->path, l->linenum, l->hosts)

                             ;
   }
   return 0;
  }




  ohosts = hosts = xstrdup(l->hosts);
  while ((cp = strsep(&hosts, ",")) != 
                                      ((void *)0) 
                                           && *cp != '\0') {
   lowercase(cp);
   if ((hashed = host_hash(cp, 
                              ((void *)0)
                                  , 0)) == 
                                           ((void *)0)
                                               )
    sshfatal("ssh-keygen.c", __func__, 1207, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "hash_host failed");
   fprintf(ctx->out, "%s %s\n", hashed, l->rawkey);
   free(hashed);
   ctx->has_unhashed = 1;
  }
  free(ohosts);
  return 0;
 case 1:

  ctx->invalid = 1;
  sshlog("ssh-keygen.c", __func__, 1217, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "%s:%lu: invalid line", l->path, l->linenum);

 default:
  fprintf(ctx->out, "%s\n", l->line);
  return 0;
 }

 return -1;
}

static int
known_hosts_find_delete(struct hostkey_foreach_line *l, void *_ctx)
{
 struct known_hosts_ctx *ctx = (struct known_hosts_ctx *)_ctx;
 enum sshkey_fp_rep rep;
 int fptype;
 char *fp = 
           ((void *)0)
               , *ra = 
                       ((void *)0)
                           ;

 fptype = print_bubblebabble ? 1 : fingerprint_hash;
 rep = print_bubblebabble ? SSH_FP_BUBBLEBABBLE : SSH_FP_DEFAULT;

 if (l->status == 3) {
  if (ctx->delete_host) {
   if (l->marker != MRK_NONE) {

    fprintf(ctx->out, "%s\n", l->line);
   } else {





    ctx->found_key = 1;
    if (!quiet)
     printf("# Host %s found: line %lu\n",
         ctx->host, l->linenum);
   }
   return 0;
  } else if (ctx->find_host) {
   ctx->found_key = 1;
   if (!quiet) {
    printf("# Host %s found: line %lu %s\n",
        ctx->host,
        l->linenum, l->marker == MRK_CA ? "CA" :
        (l->marker == MRK_REVOKE ? "REVOKED" : ""));
   }
   if (ctx->hash_hosts)
    known_hosts_hash(l, ctx);
   else if (print_fingerprint) {
    fp = sshkey_fingerprint(l->key, fptype, rep);
    ra = sshkey_fingerprint(l->key,
        fingerprint_hash, SSH_FP_RANDOMART);
    if (fp == 
             ((void *)0) 
                  || ra == 
                           ((void *)0)
                               )
     sshfatal("ssh-keygen.c", __func__, 1270, 1, SYSLOG_LEVEL_FATAL, 
    ((void *)0)
    , "sshkey_fingerprint failed");
    mprintf("%s %s %s%s%s\n", ctx->host,
        sshkey_type(l->key), fp,
        l->comment[0] ? " " : "",
        l->comment);
    if (log_level_get() >= SYSLOG_LEVEL_VERBOSE)
     printf("%s\n", ra);
    free(ra);
    free(fp);
   } else
    fprintf(ctx->out, "%s\n", l->line);
   return 0;
  }
 } else if (ctx->delete_host) {

  if (l->status == 1) {
   ctx->invalid = 1;
   sshlog("ssh-keygen.c", __func__, 1287, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "%s:%lu: invalid line", l->path, l->linenum);
  }
  fprintf(ctx->out, "%s\n", l->line);
 }
 return 0;
}

static void
do_known_hosts(struct passwd *pw, const char *name, int find_host,
    int delete_host, int hash_hosts)
{
 char *cp, tmp[
              4096
                      ], old[
                             4096
                                     ];
 int r, fd, oerrno, inplace = 0;
 struct known_hosts_ctx ctx;
 u_int foreach_options;
 struct stat sb;

 if (!have_identity) {
  cp = tilde_expand_filename("~/" ".ssh" "/known_hosts", pw->pw_uid);
  if (strlcpy(identity_file, cp, sizeof(identity_file)) >=
      sizeof(identity_file))
   sshfatal("ssh-keygen.c", __func__, 1308, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Specified known hosts path too long");
  free(cp);
  have_identity = 1;
 }
 if (stat(identity_file, &sb) != 0)
  sshfatal("ssh-keygen.c", __func__, 1313, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Cannot stat %s: %s", identity_file, strerror(
 (*__errno_location ())
 ));

 memset(&ctx, 0, sizeof(ctx));
 ctx.out = 
          stdout
                ;
 ctx.host = name;
 ctx.hash_hosts = hash_hosts;
 ctx.find_host = find_host;
 ctx.delete_host = delete_host;





 if (!find_host && (hash_hosts || delete_host)) {
  if (strlcpy(tmp, identity_file, sizeof(tmp)) >= sizeof(tmp) ||
      strlcat(tmp, ".XXXXXXXXXX", sizeof(tmp)) >= sizeof(tmp) ||
      strlcpy(old, identity_file, sizeof(old)) >= sizeof(old) ||
      strlcat(old, ".old", sizeof(old)) >= sizeof(old))
   sshfatal("ssh-keygen.c", __func__, 1331, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "known_hosts path too long");
  umask(077);
  if ((fd = mkstemp(tmp)) == -1)
   sshfatal("ssh-keygen.c", __func__, 1334, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "mkstemp: %s", strerror(
  (*__errno_location ())
  ));
  if ((ctx.out = fdopen(fd, "w")) == 
                                    ((void *)0)
                                        ) {
   oerrno = 
           (*__errno_location ())
                ;
   unlink(tmp);
   sshfatal("ssh-keygen.c", __func__, 1338, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "fdopen: %s", strerror(oerrno));
  }
  fchmod(fd, sb.st_mode & 0644);
  inplace = 1;
 }

 foreach_options = find_host ? (1) : 0;
 foreach_options |= print_fingerprint ? (1<<1) : 0;
 if ((r = hostkeys_foreach(identity_file, (find_host || !hash_hosts) ?
     known_hosts_find_delete : known_hosts_hash, &ctx, name, 
                                                            ((void *)0)
                                                                ,
     foreach_options, 0)) != 0) {
  if (inplace)
   unlink(tmp);
  sshfatal("ssh-keygen.c", __func__, 1351, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "hostkeys_foreach");
 }

 if (inplace)
  fclose(ctx.out);

 if (ctx.invalid) {
  sshlog("ssh-keygen.c", __func__, 1358, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s is not a valid known_hosts file.", identity_file);
  if (inplace) {
   sshlog("ssh-keygen.c", __func__, 1360, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Not replacing existing known_hosts " "file because of errors")
                                ;
   unlink(tmp);
  }
  exit(1);
 } else if (delete_host && !ctx.found_key) {
  sshlog("ssh-keygen.c", __func__, 1366, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Host %s not found in %s", name, identity_file);
  if (inplace)
   unlink(tmp);
 } else if (inplace) {

  if (unlink(old) == -1 && 
                          (*__errno_location ()) 
                                != 
                                   2
                                         )
   sshfatal("ssh-keygen.c", __func__, 1372, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "unlink %.100s: %s", old, strerror(
  (*__errno_location ())
  ));
  if (link(identity_file, old) == -1)
   sshfatal("ssh-keygen.c", __func__, 1374, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "link %.100s to %.100s: %s", identity_file, old, strerror(
  (*__errno_location ())
  ))
                       ;

  if (rename(tmp, identity_file) == -1) {
   sshlog("ssh-keygen.c", __func__, 1378, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "rename\"%s\" to \"%s\": %s", tmp, identity_file, strerror(
  (*__errno_location ())
  ))
                       ;
   unlink(tmp);
   unlink(old);
   exit(1);
  }

  printf("%s updated.\n", identity_file);
  printf("Original contents retained as %s\n", old);
  if (ctx.has_unhashed) {
   sshlog("ssh-keygen.c", __func__, 1388, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "WARNING: %s contains unhashed entries", old);
   sshlog("ssh-keygen.c", __func__, 1389, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Delete this file to ensure privacy " "of hostnames")
                      ;
  }
 }

 exit (find_host && !ctx.found_key);
}





static void
do_change_passphrase(struct passwd *pw)
{
 char *comment;
 char *old_passphrase, *passphrase1, *passphrase2;
 struct stat st;
 struct sshkey *private;
 int r;

 if (!have_identity)
  ask_filename(pw, "Enter file in which the key is");
 if (stat(identity_file, &st) == -1)
  sshfatal("ssh-keygen.c", __func__, 1413, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: %s", identity_file, strerror(
 (*__errno_location ())
 ));

 r = sshkey_load_private(identity_file, "", &private, &comment);
 if (r == -43) {
  if (identity_passphrase)
   old_passphrase = xstrdup(identity_passphrase);
  else
   old_passphrase =
       read_passphrase("Enter old passphrase: ",
       0x0002);
  r = sshkey_load_private(identity_file, old_passphrase,
      &private, &comment);
  freezero(old_passphrase, strlen(old_passphrase));
  if (r != 0)
   goto badkey;
 } else if (r != 0) {
 badkey:
  sshfatal("ssh-keygen.c", __func__, 1430, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Failed to load key %s", identity_file);
 }
 if (comment)
  mprintf("Key has comment '%s'\n", comment);


 if (identity_new_passphrase) {
  passphrase1 = xstrdup(identity_new_passphrase);
  passphrase2 = 
               ((void *)0)
                   ;
 } else {
  passphrase1 =
   read_passphrase("Enter new passphrase (empty for no "
       "passphrase): ", 0x0002);
  passphrase2 = read_passphrase("Enter same passphrase again: ",
      0x0002);


  if (strcmp(passphrase1, passphrase2) != 0) {
   explicit_bzero(passphrase1, strlen(passphrase1));
   explicit_bzero(passphrase2, strlen(passphrase2));
   free(passphrase1);
   free(passphrase2);
   printf("Pass phrases do not match.  Try again.\n");
   exit(1);
  }

  freezero(passphrase2, strlen(passphrase2));
 }


 if ((r = sshkey_save_private(private, identity_file, passphrase1,
     comment, private_key_format, openssh_format_cipher, rounds)) != 0) {
  sshlog("ssh-keygen.c", __func__, 1462, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Saving key \"%s\" failed", identity_file);
  freezero(passphrase1, strlen(passphrase1));
  sshkey_free(private);
  free(comment);
  exit(1);
 }

 freezero(passphrase1, strlen(passphrase1));
 sshkey_free(private);
 free(comment);

 printf("Your identification has been saved with the new passphrase.\n");
 exit(0);
}




static int
do_print_resource_record(struct passwd *pw, char *fname, char *hname,
    int print_generic)
{
 struct sshkey *public;
 char *comment = 
                ((void *)0)
                    ;
 struct stat st;
 int r;

 if (fname == 
             ((void *)0)
                 )
  sshfatal("ssh-keygen.c", __func__, 1490, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "no filename");
 if (stat(fname, &st) == -1) {
  if (
     (*__errno_location ()) 
           == 
              2
                    )
   return 0;
  sshfatal("ssh-keygen.c", __func__, 1494, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: %s", fname, strerror(
 (*__errno_location ())
 ));
 }
 if ((r = sshkey_load_public(fname, &public, &comment)) != 0)
  sshfatal("ssh-keygen.c", __func__, 1497, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Failed to read v2 public key from \"%s\"", fname);
 export_dns_rr(hname, public, 
                             stdout
                                   , print_generic);
 sshkey_free(public);
 free(comment);
 return 1;
}




static void
do_change_comment(struct passwd *pw, const char *identity_comment)
{
 char new_comment[1024], *comment, *passphrase;
 struct sshkey *private;
 struct sshkey *public;
 struct stat st;
 int r;

 if (!have_identity)
  ask_filename(pw, "Enter file in which the key is");
 if (stat(identity_file, &st) == -1)
  sshfatal("ssh-keygen.c", __func__, 1519, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: %s", identity_file, strerror(
 (*__errno_location ())
 ));
 if ((r = sshkey_load_private(identity_file, "",
     &private, &comment)) == 0)
  passphrase = xstrdup("");
 else if (r != -43)
  sshfatal("ssh-keygen.c", __func__, 1524, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Cannot load private key \"%s\"", identity_file);
 else {
  if (identity_passphrase)
   passphrase = xstrdup(identity_passphrase);
  else if (identity_new_passphrase)
   passphrase = xstrdup(identity_new_passphrase);
  else
   passphrase = read_passphrase("Enter passphrase: ",
       0x0002);

  if ((r = sshkey_load_private(identity_file, passphrase,
      &private, &comment)) != 0) {
   freezero(passphrase, strlen(passphrase));
   sshfatal("ssh-keygen.c", __func__, 1537, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Cannot load private key \"%s\"", identity_file)
                     ;
  }
 }

 if (private->type != KEY_ED25519 && private->type != KEY_XMSS &&
     private_key_format != SSHKEY_PRIVATE_OPENSSH) {
  sshlog("ssh-keygen.c", __func__, 1544, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Comments are only supported for keys stored in " "the new format (-o).")
                             ;
  explicit_bzero(passphrase, strlen(passphrase));
  sshkey_free(private);
  exit(1);
 }
 if (comment)
  printf("Old comment: %s\n", comment);
 else
  printf("No existing comment\n");

 if (identity_comment) {
  strlcpy(new_comment, identity_comment, sizeof(new_comment));
 } else {
  printf("New comment: ");
  fflush(
        stdout
              );
  if (!fgets(new_comment, sizeof(new_comment), 
                                              stdin
                                                   )) {
   explicit_bzero(passphrase, strlen(passphrase));
   sshkey_free(private);
   exit(1);
  }
  new_comment[strcspn(new_comment, "\n")] = '\0';
 }
 if (comment != 
               ((void *)0) 
                    && strcmp(comment, new_comment) == 0) {
  printf("No change to comment\n");
  free(passphrase);
  sshkey_free(private);
  free(comment);
  exit(0);
 }


 if ((r = sshkey_save_private(private, identity_file, passphrase,
     new_comment, private_key_format, openssh_format_cipher,
     rounds)) != 0) {
  sshlog("ssh-keygen.c", __func__, 1579, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Saving key \"%s\" failed", identity_file);
  freezero(passphrase, strlen(passphrase));
  sshkey_free(private);
  free(comment);
  exit(1);
 }
 freezero(passphrase, strlen(passphrase));
 if ((r = sshkey_from_private(private, &public)) != 0)
  sshfatal("ssh-keygen.c", __func__, 1587, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshkey_from_private");
 sshkey_free(private);

 strlcat(identity_file, ".pub", sizeof(identity_file));
 if ((r = sshkey_save_public(public, identity_file, new_comment)) != 0)
  sshfatal("ssh-keygen.c", __func__, 1592, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Unable to save public key to %s", identity_file);
 sshkey_free(public);
 free(comment);

 if (strlen(new_comment) > 0)
  printf("Comment '%s' applied\n", new_comment);
 else
  printf("Comment removed\n");

 exit(0);
}

static void
cert_ext_add(const char *key, const char *value, int iscrit)
{
 cert_ext = xreallocarray(cert_ext, ncert_ext + 1, sizeof(*cert_ext));
 cert_ext[ncert_ext].key = xstrdup(key);
 cert_ext[ncert_ext].val = value == 
                                   ((void *)0) 
                                        ? 
                                          ((void *)0) 
                                               : xstrdup(value);
 cert_ext[ncert_ext].crit = iscrit;
 ncert_ext++;
}


static int
cert_ext_cmp(const void *_a, const void *_b)
{
 const struct cert_ext *a = (const struct cert_ext *)_a;
 const struct cert_ext *b = (const struct cert_ext *)_b;
 int r;

 if (a->crit != b->crit)
  return (a->crit < b->crit) ? -1 : 1;
 if ((r = strcmp(a->key, b->key)) != 0)
  return r;
 if ((a->val == 
               ((void *)0)
                   ) != (b->val == 
                                   ((void *)0)
                                       ))
  return (a->val == 
                   ((void *)0)
                       ) ? -1 : 1;
 if (a->val != 
              ((void *)0) 
                   && (r = strcmp(a->val, b->val)) != 0)
  return r;
 return 0;
}



static void
prepare_options_buf(struct sshbuf *c, int which)
{
 struct sshbuf *b;
 size_t i;
 int r;
 const struct cert_ext *ext;

 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("ssh-keygen.c", __func__, 1644, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 sshbuf_reset(c);
 for (i = 0; i < ncert_ext; i++) {
  ext = &cert_ext[i];
  if ((ext->crit && (which & 2)) ||
      (!ext->crit && (which & 1)))
   continue;
  if (ext->val == 
                 ((void *)0)
                     ) {

   sshlog("ssh-keygen.c", __func__, 1653, 1, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "%s", ext->key);
   if ((r = sshbuf_put_cstring(c, ext->key)) != 0 ||
       (r = sshbuf_put_string(c, 
                                ((void *)0)
                                    , 0)) != 0)
    sshfatal("ssh-keygen.c", __func__, 1656, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "prepare flag");
  } else {

   sshlog("ssh-keygen.c", __func__, 1659, 1, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "%s=%s", ext->key, ext->val);
   sshbuf_reset(b);
   if ((r = sshbuf_put_cstring(c, ext->key)) != 0 ||
       (r = sshbuf_put_cstring(b, ext->val)) != 0 ||
       (r = sshbuf_put_stringb(c, b)) != 0)
    sshfatal("ssh-keygen.c", __func__, 1664, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "prepare k/v");
  }
 }
 sshbuf_free(b);
}

static void
finalise_cert_exts(void)
{

 if (certflags_command != 
                         ((void *)0)
                             )
  cert_ext_add("force-command", certflags_command, 1);
 if (certflags_src_addr != 
                          ((void *)0)
                              )
  cert_ext_add("source-address", certflags_src_addr, 1);
 if ((certflags_flags & (1<<6)) != 0)
  cert_ext_add("verify-required", 
                                 ((void *)0)
                                     , 1);

 if ((certflags_flags & (1)) != 0)
  cert_ext_add("permit-X11-forwarding", 
                                       ((void *)0)
                                           , 0);
 if ((certflags_flags & (1<<1)) != 0)
  cert_ext_add("permit-agent-forwarding", 
                                         ((void *)0)
                                             , 0);
 if ((certflags_flags & (1<<2)) != 0)
  cert_ext_add("permit-port-forwarding", 
                                        ((void *)0)
                                            , 0);
 if ((certflags_flags & (1<<3)) != 0)
  cert_ext_add("permit-pty", 
                            ((void *)0)
                                , 0);
 if ((certflags_flags & (1<<4)) != 0)
  cert_ext_add("permit-user-rc", 
                                ((void *)0)
                                    , 0);
 if ((certflags_flags & (1<<5)) != 0)
  cert_ext_add("no-touch-required", 
                                   ((void *)0)
                                       , 0);

 if (ncert_ext > 0)
  qsort(cert_ext, ncert_ext, sizeof(*cert_ext), cert_ext_cmp);
}

static struct sshkey *
load_pkcs11_key(char *path)
{

 struct sshkey **keys = 
                       ((void *)0)
                           , *public, *private = 
                                                 ((void *)0)
                                                     ;
 int r, i, nkeys;

 if ((r = sshkey_load_public(path, &public, 
                                           ((void *)0)
                                               )) != 0)
  sshfatal("ssh-keygen.c", __func__, 1706, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Couldn't load CA public key \"%s\"", path);

 nkeys = pkcs11_add_provider(pkcs11provider, identity_passphrase,
     &keys, 
           ((void *)0)
               );
 sshlog("ssh-keygen.c", __func__, 1710, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%d keys", nkeys);
 if (nkeys <= 0)
  sshfatal("ssh-keygen.c", __func__, 1712, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "cannot read public key from pkcs11");
 for (i = 0; i < nkeys; i++) {
  if (sshkey_equal_public(public, keys[i])) {
   private = keys[i];
   continue;
  }
  sshkey_free(keys[i]);
 }
 free(keys);
 sshkey_free(public);
 return private;



}


static int
agent_signer(struct sshkey *key, u_char **sigp, size_t *lenp,
    const u_char *data, size_t datalen,
    const char *alg, const char *provider, const char *pin,
    u_int compat, void *ctx)
{
 int *agent_fdp = (int *)ctx;

 return ssh_agent_sign(*agent_fdp, key, sigp, lenp,
     data, datalen, alg, compat);
}

static void
do_ca_sign(struct passwd *pw, const char *ca_key_path, int prefer_agent,
    unsigned long long cert_serial, int cert_serial_autoinc,
    int argc, char **argv)
{
 int r, i, found, agent_fd = -1;
 u_int n;
 struct sshkey *ca, *public;
 char valid[64], *otmp, *tmp, *cp, *out, *comment;
 char *ca_fp = 
              ((void *)0)
                  , **plist = 
                              ((void *)0)
                                  , *pin = 
                                           ((void *)0)
                                               ;
 struct ssh_identitylist *agent_ids;
 size_t j;
 struct notifier_ctx *notifier = 
                                ((void *)0)
                                    ;


 pkcs11_init(1);

 tmp = tilde_expand_filename(ca_key_path, pw->pw_uid);
 if (pkcs11provider != 
                      ((void *)0)
                          ) {

  if ((ca = load_pkcs11_key(tmp)) == 
                                    ((void *)0)
                                        )
   sshfatal("ssh-keygen.c", __func__, 1762, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "No PKCS#11 key matching %s found", ca_key_path);
 } else if (prefer_agent) {





  if ((r = sshkey_load_public(tmp, &ca, 
                                       ((void *)0)
                                           )) != 0)
   sshfatal("ssh-keygen.c", __func__, 1770, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Cannot load CA public key %s", tmp);
  if ((r = ssh_get_authentication_socket(&agent_fd)) != 0)
   sshfatal("ssh-keygen.c", __func__, 1772, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Cannot use public key for CA signature");
  if ((r = ssh_fetch_identitylist(agent_fd, &agent_ids)) != 0)
   sshfatal("ssh-keygen.c", __func__, 1774, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Retrieve agent key list");
  found = 0;
  for (j = 0; j < agent_ids->nkeys; j++) {
   if (sshkey_equal(ca, agent_ids->keys[j])) {
    found = 1;
    break;
   }
  }
  if (!found)
   sshfatal("ssh-keygen.c", __func__, 1783, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "CA key %s not found in agent", tmp);
  ssh_free_identitylist(agent_ids);
  ca->flags |= 0x0001;
 } else {

  ca = load_identity(tmp, 
                         ((void *)0)
                             );
  if (sshkey_is_sk(ca) &&
      (ca->sk_flags & 0x04)) {
   if ((pin = read_passphrase("Enter PIN for CA key: ",
       0x0002)) == 
                          ((void *)0)
                              )
    sshfatal("ssh-keygen.c", __func__, 1793, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "couldn't read PIN");
  }
 }
 free(tmp);

 if (key_type_name != 
                     ((void *)0)
                         ) {
  if (sshkey_type_from_name(key_type_name) != ca->type) {
   sshfatal("ssh-keygen.c", __func__, 1800, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "CA key type %s doesn't match specified %s", sshkey_ssh_name(ca), key_type_name)
                                          ;
  }
 } else if (ca->type == KEY_RSA) {

  key_type_name = "rsa-sha2-512";
 }
 ca_fp = sshkey_fingerprint(ca, fingerprint_hash, SSH_FP_DEFAULT);

 finalise_cert_exts();
 for (i = 0; i < argc; i++) {

  n = 0;
  if (cert_principals != 
                        ((void *)0)
                            ) {
   otmp = tmp = xstrdup(cert_principals);
   plist = 
          ((void *)0)
              ;
   for (; (cp = strsep(&tmp, ",")) != 
                                     ((void *)0)
                                         ; n++) {
    plist = xreallocarray(plist, n + 1, sizeof(*plist));
    if (*(plist[n] = xstrdup(cp)) == '\0')
     sshfatal("ssh-keygen.c", __func__, 1819, 0, SYSLOG_LEVEL_FATAL, 
    ((void *)0)
    , "Empty principal name");
   }
   free(otmp);
  }
  if (n > 256)
   sshfatal("ssh-keygen.c", __func__, 1824, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Too many certificate principals specified");

  tmp = tilde_expand_filename(argv[i], pw->pw_uid);
  if ((r = sshkey_load_public(tmp, &public, &comment)) != 0)
   sshfatal("ssh-keygen.c", __func__, 1828, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "load pubkey \"%s\"", tmp);
  if (sshkey_is_cert(public))
   sshfatal("ssh-keygen.c", __func__, 1830, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "key \"%s\" type %s cannot be certified", tmp, sshkey_type(public))
                                ;


  if ((r = sshkey_to_certified(public)) != 0)
   sshfatal("ssh-keygen.c", __func__, 1835, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Could not upgrade key %s to certificate", tmp);
  public->cert->type = cert_key_type;
  public->cert->serial = (u_int64_t)cert_serial;
  public->cert->key_id = xstrdup(cert_key_id);
  public->cert->nprincipals = n;
  public->cert->principals = plist;
  public->cert->valid_after = cert_valid_from;
  public->cert->valid_before = cert_valid_to;
  prepare_options_buf(public->cert->critical, 1);
  prepare_options_buf(public->cert->extensions,
      2);
  if ((r = sshkey_from_private(ca,
      &public->cert->signature_key)) != 0)
   sshfatal("ssh-keygen.c", __func__, 1848, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshkey_from_private (ca key)");

  if (agent_fd != -1 && (ca->flags & 0x0001) != 0) {
   if ((r = sshkey_certify_custom(public, ca,
       key_type_name, sk_provider, 
                                  ((void *)0)
                                      , agent_signer,
       &agent_fd)) != 0)
    sshfatal("ssh-keygen.c", __func__, 1854, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Couldn't certify %s via agent", tmp);
  } else {
   if (sshkey_is_sk(ca) &&
       (ca->sk_flags & 0x01)) {
    notifier = notify_start(0,
        "Confirm user presence for key %s %s",
        sshkey_type(ca), ca_fp);
   }
   r = sshkey_certify(public, ca, key_type_name,
       sk_provider, pin);
   notify_complete(notifier, "User presence confirmed");
   if (r != 0)
    sshfatal("ssh-keygen.c", __func__, 1866, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Couldn't certify key %s", tmp);
  }

  if ((cp = strrchr(tmp, '.')) != 
                                 ((void *)0) 
                                      && strcmp(cp, ".pub") == 0)
   *cp = '\0';
  xasprintf(&out, "%s-cert.pub", tmp);
  free(tmp);

  if ((r = sshkey_save_public(public, out, comment)) != 0) {
   sshfatal("ssh-keygen.c", __func__, 1875, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Unable to save public key to %s", identity_file)
                     ;
  }

  if (!quiet) {
   sshkey_format_cert_validity(public->cert,
       valid, sizeof(valid));
   sshlog("ssh-keygen.c", __func__, 1882, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Signed %s key %s: id \"%s\" serial %llu%s%s " "valid %s", sshkey_cert_type(public), out, public->cert->key_id, (unsigned long long)public->cert->serial, cert_principals != 
  ((void *)0) 
  ? " for " : "", cert_principals != 
  ((void *)0) 
  ? cert_principals : "", valid)





             ;
  }

  sshkey_free(public);
  free(out);
  if (cert_serial_autoinc)
   cert_serial++;
 }
 if (pin != 
           ((void *)0)
               )
  freezero(pin, strlen(pin));
 free(ca_fp);

 pkcs11_terminate();

 exit(0);
}

static u_int64_t
parse_relative_time(const char *s, time_t now)
{
 int64_t mul, secs;

 mul = *s == '-' ? -1 : 1;

 if ((secs = convtime(s + 1)) == -1)
  sshfatal("ssh-keygen.c", __func__, 1913, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Invalid relative certificate time %s", s);
 if (mul == -1 && secs > now)
  sshfatal("ssh-keygen.c", __func__, 1915, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Certificate time %s cannot be represented", s);
 return now + (u_int64_t)(secs * mul);
}

static void
parse_hex_u64(const char *s, uint64_t *up)
{
 char *ep;
 unsigned long long ull;

 
(*__errno_location ()) 
      = 0;
 ull = strtoull(s, &ep, 16);
 if (*s == '\0' || *ep != '\0')
  sshfatal("ssh-keygen.c", __func__, 1928, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Invalid certificate time: not a number");
 if (
    (*__errno_location ()) 
          == 
             34 
                    && ull == 
                              (0x7fffffffffffffffL * 2UL + 1UL)
                                       )
  sshfatal("ssh-keygen.c", __func__, 1930, 1, SYSLOG_LEVEL_FATAL, ssh_err(-24), "Invalid certificate time");
 *up = (uint64_t)ull;
}

static void
parse_cert_times(char *timespec)
{
 char *from, *to;
 time_t now = time(
                  ((void *)0)
                      );
 int64_t secs;


 if (*timespec == '+' && strchr(timespec, ':') == 
                                                 ((void *)0)
                                                     ) {
  if ((secs = convtime(timespec + 1)) == -1)
   sshfatal("ssh-keygen.c", __func__, 1944, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Invalid relative certificate life %s", timespec);
  cert_valid_to = now + secs;




  cert_valid_from = ((now - 59)/ 60) * 60;
  return;
 }






 from = xstrdup(timespec);
 to = strchr(from, ':');
 if (to == 
          ((void *)0) 
               || from == to || *(to + 1) == '\0')
  sshfatal("ssh-keygen.c", __func__, 1962, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Invalid certificate life specification %s", timespec);
 *to++ = '\0';

 if (*from == '-' || *from == '+')
  cert_valid_from = parse_relative_time(from, now);
 else if (strcmp(from, "always") == 0)
  cert_valid_from = 0;
 else if (strncmp(from, "0x", 2) == 0)
  parse_hex_u64(from, &cert_valid_from);
 else if (parse_absolute_time(from, &cert_valid_from) != 0)
  sshfatal("ssh-keygen.c", __func__, 1972, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Invalid from time \"%s\"", from);

 if (*to == '-' || *to == '+')
  cert_valid_to = parse_relative_time(to, now);
 else if (strcmp(to, "forever") == 0)
  cert_valid_to = ~(u_int64_t)0;
 else if (strncmp(from, "0x", 2) == 0)
  parse_hex_u64(to, &cert_valid_to);
 else if (parse_absolute_time(to, &cert_valid_to) != 0)
  sshfatal("ssh-keygen.c", __func__, 1981, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Invalid to time \"%s\"", to);

 if (cert_valid_to <= cert_valid_from)
  sshfatal("ssh-keygen.c", __func__, 1984, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Empty certificate validity interval");
 free(from);
}

static void
add_cert_option(char *opt)
{
 char *val, *cp;
 int iscrit = 0;

 if (strcasecmp(opt, "clear") == 0)
  certflags_flags = 0;
 else if (strcasecmp(opt, "no-x11-forwarding") == 0)
  certflags_flags &= ~(1);
 else if (strcasecmp(opt, "permit-x11-forwarding") == 0)
  certflags_flags |= (1);
 else if (strcasecmp(opt, "no-agent-forwarding") == 0)
  certflags_flags &= ~(1<<1);
 else if (strcasecmp(opt, "permit-agent-forwarding") == 0)
  certflags_flags |= (1<<1);
 else if (strcasecmp(opt, "no-port-forwarding") == 0)
  certflags_flags &= ~(1<<2);
 else if (strcasecmp(opt, "permit-port-forwarding") == 0)
  certflags_flags |= (1<<2);
 else if (strcasecmp(opt, "no-pty") == 0)
  certflags_flags &= ~(1<<3);
 else if (strcasecmp(opt, "permit-pty") == 0)
  certflags_flags |= (1<<3);
 else if (strcasecmp(opt, "no-user-rc") == 0)
  certflags_flags &= ~(1<<4);
 else if (strcasecmp(opt, "permit-user-rc") == 0)
  certflags_flags |= (1<<4);
 else if (strcasecmp(opt, "touch-required") == 0)
  certflags_flags &= ~(1<<5);
 else if (strcasecmp(opt, "no-touch-required") == 0)
  certflags_flags |= (1<<5);
 else if (strcasecmp(opt, "no-verify-required") == 0)
  certflags_flags &= ~(1<<6);
 else if (strcasecmp(opt, "verify-required") == 0)
  certflags_flags |= (1<<6);
 else if (strncasecmp(opt, "force-command=", 14) == 0) {
  val = opt + 14;
  if (*val == '\0')
   sshfatal("ssh-keygen.c", __func__, 2027, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Empty force-command option");
  if (certflags_command != 
                          ((void *)0)
                              )
   sshfatal("ssh-keygen.c", __func__, 2029, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "force-command already specified");
  certflags_command = xstrdup(val);
 } else if (strncasecmp(opt, "source-address=", 15) == 0) {
  val = opt + 15;
  if (*val == '\0')
   sshfatal("ssh-keygen.c", __func__, 2034, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Empty source-address option");
  if (certflags_src_addr != 
                           ((void *)0)
                               )
   sshfatal("ssh-keygen.c", __func__, 2036, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "source-address already specified");
  if (addr_match_cidr_list(
                          ((void *)0)
                              , val) != 0)
   sshfatal("ssh-keygen.c", __func__, 2038, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Invalid source-address list");
  certflags_src_addr = xstrdup(val);
 } else if (strncasecmp(opt, "extension:", 10) == 0 ||
      (iscrit = (strncasecmp(opt, "critical:", 9) == 0))) {
  val = xstrdup(strchr(opt, ':') + 1);
  if ((cp = strchr(val, '=')) != 
                                ((void *)0)
                                    )
   *cp++ = '\0';
  cert_ext_add(val, cp, iscrit);
  free(val);
 } else
  sshfatal("ssh-keygen.c", __func__, 2048, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Unsupported certificate option \"%s\"", opt);
}

static void
show_options(struct sshbuf *optbuf, int in_critical)
{
 char *name, *arg, *hex;
 struct sshbuf *options, *option = 
                                  ((void *)0)
                                      ;
 int r;

 if ((options = sshbuf_fromb(optbuf)) == 
                                        ((void *)0)
                                            )
  sshfatal("ssh-keygen.c", __func__, 2059, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_fromb failed");
 while (sshbuf_len(options) != 0) {
  sshbuf_free(option);
  option = 
          ((void *)0)
              ;
  if ((r = sshbuf_get_cstring(options, &name, 
                                             ((void *)0)
                                                 )) != 0 ||
      (r = sshbuf_froms(options, &option)) != 0)
   sshfatal("ssh-keygen.c", __func__, 2065, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse option");
  printf("                %s", name);
  if (!in_critical &&
      (strcmp(name, "permit-X11-forwarding") == 0 ||
      strcmp(name, "permit-agent-forwarding") == 0 ||
      strcmp(name, "permit-port-forwarding") == 0 ||
      strcmp(name, "permit-pty") == 0 ||
      strcmp(name, "permit-user-rc") == 0 ||
      strcmp(name, "no-touch-required") == 0)) {
   printf("\n");
  } else if (in_critical &&
      (strcmp(name, "force-command") == 0 ||
      strcmp(name, "source-address") == 0)) {
   if ((r = sshbuf_get_cstring(option, &arg, 
                                            ((void *)0)
                                                )) != 0)
    sshfatal("ssh-keygen.c", __func__, 2079, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse critical");
   printf(" %s\n", arg);
   free(arg);
  } else if (in_critical &&
      strcmp(name, "verify-required") == 0) {
   printf("\n");
  } else if (sshbuf_len(option) > 0) {
   hex = sshbuf_dtob16(option);
   printf(" UNKNOWN OPTION: %s (len %zu)\n",
       hex, sshbuf_len(option));
   sshbuf_reset(option);
   free(hex);
  } else
   printf(" UNKNOWN FLAG OPTION\n");
  free(name);
  if (sshbuf_len(option) != 0)
   sshfatal("ssh-keygen.c", __func__, 2095, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Option corrupt: extra data at end");
 }
 sshbuf_free(option);
 sshbuf_free(options);
}

static void
print_cert(struct sshkey *key)
{
 char valid[64], *key_fp, *ca_fp;
 u_int i;

 key_fp = sshkey_fingerprint(key, fingerprint_hash, SSH_FP_DEFAULT);
 ca_fp = sshkey_fingerprint(key->cert->signature_key,
     fingerprint_hash, SSH_FP_DEFAULT);
 if (key_fp == 
              ((void *)0) 
                   || ca_fp == 
                               ((void *)0)
                                   )
  sshfatal("ssh-keygen.c", __func__, 2111, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshkey_fingerprint fail");
 sshkey_format_cert_validity(key->cert, valid, sizeof(valid));

 printf("        Type: %s %s certificate\n", sshkey_ssh_name(key),
     sshkey_cert_type(key));
 printf("        Public key: %s %s\n", sshkey_type(key), key_fp);
 printf("        Signing CA: %s %s (using %s)\n",
     sshkey_type(key->cert->signature_key), ca_fp,
     key->cert->signature_type);
 printf("        Key ID: \"%s\"\n", key->cert->key_id);
 printf("        Serial: %llu\n", (unsigned long long)key->cert->serial);
 printf("        Valid: %s\n", valid);
 printf("        Principals: ");
 if (key->cert->nprincipals == 0)
  printf("(none)\n");
 else {
  for (i = 0; i < key->cert->nprincipals; i++)
   printf("\n                %s",
       key->cert->principals[i]);
  printf("\n");
 }
 printf("        Critical Options: ");
 if (sshbuf_len(key->cert->critical) == 0)
  printf("(none)\n");
 else {
  printf("\n");
  show_options(key->cert->critical, 1);
 }
 printf("        Extensions: ");
 if (sshbuf_len(key->cert->extensions) == 0)
  printf("(none)\n");
 else {
  printf("\n");
  show_options(key->cert->extensions, 0);
 }
}

static void
do_show_cert(struct passwd *pw)
{
 struct sshkey *key = 
                     ((void *)0)
                         ;
 struct stat st;
 int r, is_stdin = 0, ok = 0;
 FILE *f;
 char *cp, *line = 
                  ((void *)0)
                      ;
 const char *path;
 size_t linesize = 0;
 u_long lnum = 0;

 if (!have_identity)
  ask_filename(pw, "Enter file in which the key is");
 if (strcmp(identity_file, "-") != 0 && stat(identity_file, &st) == -1)
  sshfatal("ssh-keygen.c", __func__, 2163, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: %s: %s", __progname, identity_file, strerror(
 (*__errno_location ())
 ));

 path = identity_file;
 if (strcmp(path, "-") == 0) {
  f = 
     stdin
          ;
  path = "(stdin)";
  is_stdin = 1;
 } else if ((f = fopen(identity_file, "r")) == 
                                              ((void *)0)
                                                  )
  sshfatal("ssh-keygen.c", __func__, 2171, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "fopen %s: %s", identity_file, strerror(
 (*__errno_location ())
 ));

 while (getline(&line, &linesize, f) != -1) {
  lnum++;
  sshkey_free(key);
  key = 
       ((void *)0)
           ;

  cp = line + strspn(line, " \t");
  if (*cp == '#' || *cp == '\0')
   continue;
  if ((key = sshkey_new(KEY_UNSPEC)) == 
                                       ((void *)0)
                                           )
   sshfatal("ssh-keygen.c", __func__, 2182, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshkey_new");
  if ((r = sshkey_read(key, &cp)) != 0) {
   sshlog("ssh-keygen.c", __func__, 2184, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "%s:%lu: invalid key", path, lnum);
   continue;
  }
  if (!sshkey_is_cert(key)) {
   sshlog("ssh-keygen.c", __func__, 2188, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s:%lu is not a certificate", path, lnum);
   continue;
  }
  ok = 1;
  if (!is_stdin && lnum == 1)
   printf("%s:\n", path);
  else
   printf("%s:%lu:\n", path, lnum);
  print_cert(key);
 }
 free(line);
 sshkey_free(key);
 fclose(f);
 exit(ok ? 0 : 1);
}

static void
load_krl(const char *path, struct ssh_krl **krlp)
{
 struct sshbuf *krlbuf;
 int r;

 if ((r = sshbuf_load_file(path, &krlbuf)) != 0)
  sshfatal("ssh-keygen.c", __func__, 2211, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Unable to load KRL %s", path);

 if ((r = ssh_krl_from_blob(krlbuf, krlp, 
                                         ((void *)0)
                                             , 0)) != 0 ||
     *krlp == 
             ((void *)0)
                 )
  sshfatal("ssh-keygen.c", __func__, 2215, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Invalid KRL file %s", path);
 sshbuf_free(krlbuf);
}

static void
hash_to_blob(const char *cp, u_char **blobp, size_t *lenp,
    const char *file, u_long lnum)
{
 char *tmp;
 size_t tlen;
 struct sshbuf *b;
 int r;

 if (strncmp(cp, "SHA256:", 7) != 0)
  sshfatal("ssh-keygen.c", __func__, 2229, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s:%lu: unsupported hash algorithm", file, lnum);
 cp += 7;





 tlen = strlen(cp);
 tmp = xmalloc(tlen + 4 + 1);
 strlcpy(tmp, cp, tlen + 1);
 while ((tlen % 4) != 0) {
  tmp[tlen++] = '=';
  tmp[tlen] = '\0';
 }
 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("ssh-keygen.c", __func__, 2244, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_b64tod(b, tmp)) != 0)
  sshfatal("ssh-keygen.c", __func__, 2246, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s:%lu: decode hash failed", file, lnum);
 free(tmp);
 *lenp = sshbuf_len(b);
 *blobp = xmalloc(*lenp);
 memcpy(*blobp, sshbuf_ptr(b), *lenp);
 sshbuf_free(b);
}

static void
update_krl_from_file(struct passwd *pw, const char *file, int wild_ca,
    const struct sshkey *ca, struct ssh_krl *krl)
{
 struct sshkey *key = 
                     ((void *)0)
                         ;
 u_long lnum = 0;
 char *path, *cp, *ep, *line = 
                              ((void *)0)
                                  ;
 u_char *blob = 
               ((void *)0)
                   ;
 size_t blen = 0, linesize = 0;
 unsigned long long serial, serial2;
 int i, was_explicit_key, was_sha1, was_sha256, was_hash, r;
 FILE *krl_spec;

 path = tilde_expand_filename(file, pw->pw_uid);
 if (strcmp(path, "-") == 0) {
  krl_spec = 
            stdin
                 ;
  free(path);
  path = xstrdup("(standard input)");
 } else if ((krl_spec = fopen(path, "r")) == 
                                            ((void *)0)
                                                )
  sshfatal("ssh-keygen.c", __func__, 2273, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "fopen %s: %s", path, strerror(
 (*__errno_location ())
 ));

 if (!quiet)
  printf("Revoking from %s\n", path);
 while (getline(&line, &linesize, krl_spec) != -1) {
  lnum++;
  was_explicit_key = was_sha1 = was_sha256 = was_hash = 0;
  cp = line + strspn(line, " \t");

  for (i = 0, r = -1; cp[i] != '\0'; i++) {
   if (cp[i] == '#' || cp[i] == '\n') {
    cp[i] = '\0';
    break;
   }
   if (cp[i] == ' ' || cp[i] == '\t') {

    if (r == -1)
     r = i;
   } else
    r = -1;
  }
  if (r != -1)
   cp[r] = '\0';
  if (*cp == '\0')
   continue;
  if (strncasecmp(cp, "serial:", 7) == 0) {
   if (ca == 
            ((void *)0) 
                 && !wild_ca) {
    sshfatal("ssh-keygen.c", __func__, 2300, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "revoking certificates by serial number " "requires specification of a CA key")
                                             ;
   }
   cp += 7;
   cp = cp + strspn(cp, " \t");
   
  (*__errno_location ()) 
        = 0;
   serial = strtoull(cp, &ep, 0);
   if (*cp == '\0' || (*ep != '\0' && *ep != '-'))
    sshfatal("ssh-keygen.c", __func__, 2308, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s:%lu: invalid serial \"%s\"", path, lnum, cp)
                       ;
   if (
      (*__errno_location ()) 
            == 
               34 
                      && serial == 
                                   (0x7fffffffffffffffLL * 2ULL + 1ULL)
                                             )
    sshfatal("ssh-keygen.c", __func__, 2311, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s:%lu: serial out of range", path, lnum)
                   ;
   serial2 = serial;
   if (*ep == '-') {
    cp = ep + 1;
    
   (*__errno_location ()) 
         = 0;
    serial2 = strtoull(cp, &ep, 0);
    if (*cp == '\0' || *ep != '\0')
     sshfatal("ssh-keygen.c", __func__, 2319, 0, SYSLOG_LEVEL_FATAL, 
    ((void *)0)
    , "%s:%lu: invalid serial \"%s\"", path, lnum, cp)
                        ;
    if (
       (*__errno_location ()) 
             == 
                34 
                       && serial2 == 
                                     (0x7fffffffffffffffLL * 2ULL + 1ULL)
                                               )
     sshfatal("ssh-keygen.c", __func__, 2322, 0, SYSLOG_LEVEL_FATAL, 
    ((void *)0)
    , "%s:%lu: serial out of range", path, lnum)
                    ;
    if (serial2 <= serial)
     sshfatal("ssh-keygen.c", __func__, 2325, 0, SYSLOG_LEVEL_FATAL, 
    ((void *)0)
    , "%s:%lu: invalid serial range " "%llu:%llu", path, lnum, (unsigned long long)serial, (unsigned long long)serial2)


                                     ;
   }
   if (ssh_krl_revoke_cert_by_serial_range(krl,
       ca, serial, serial2) != 0) {
    sshfatal("ssh-keygen.c", __func__, 2332, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "revoke serial failed");
   }
  } else if (strncasecmp(cp, "id:", 3) == 0) {
   if (ca == 
            ((void *)0) 
                 && !wild_ca) {
    sshfatal("ssh-keygen.c", __func__, 2336, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "revoking certificates by key ID " "requires specification of a CA key")
                                             ;
   }
   cp += 3;
   cp = cp + strspn(cp, " \t");
   if (ssh_krl_revoke_cert_by_key_id(krl, ca, cp) != 0)
    sshfatal("ssh-keygen.c", __func__, 2342, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "revoke key ID failed");
  } else if (strncasecmp(cp, "hash:", 5) == 0) {
   cp += 5;
   cp = cp + strspn(cp, " \t");
   hash_to_blob(cp, &blob, &blen, file, lnum);
   r = ssh_krl_revoke_key_sha256(krl, blob, blen);
   if (r != 0)
    sshfatal("ssh-keygen.c", __func__, 2349, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "revoke key failed");
  } else {
   if (strncasecmp(cp, "key:", 4) == 0) {
    cp += 4;
    cp = cp + strspn(cp, " \t");
    was_explicit_key = 1;
   } else if (strncasecmp(cp, "sha1:", 5) == 0) {
    cp += 5;
    cp = cp + strspn(cp, " \t");
    was_sha1 = 1;
   } else if (strncasecmp(cp, "sha256:", 7) == 0) {
    cp += 7;
    cp = cp + strspn(cp, " \t");
    was_sha256 = 1;




   }
   if ((key = sshkey_new(KEY_UNSPEC)) == 
                                        ((void *)0)
                                            )
    sshfatal("ssh-keygen.c", __func__, 2369, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "sshkey_new");
   if ((r = sshkey_read(key, &cp)) != 0)
    sshfatal("ssh-keygen.c", __func__, 2371, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s:%lu: invalid key", path, lnum);
   if (was_explicit_key)
    r = ssh_krl_revoke_key_explicit(krl, key);
   else if (was_sha1) {
    if (sshkey_fingerprint_raw(key,
        1, &blob, &blen) != 0) {
     sshfatal("ssh-keygen.c", __func__, 2377, 0, SYSLOG_LEVEL_FATAL, 
    ((void *)0)
    , "%s:%lu: fingerprint failed", file, lnum)
                    ;
    }
    r = ssh_krl_revoke_key_sha1(krl, blob, blen);
   } else if (was_sha256) {
    if (sshkey_fingerprint_raw(key,
        2, &blob, &blen) != 0) {
     sshfatal("ssh-keygen.c", __func__, 2384, 0, SYSLOG_LEVEL_FATAL, 
    ((void *)0)
    , "%s:%lu: fingerprint failed", file, lnum)
                    ;
    }
    r = ssh_krl_revoke_key_sha256(krl, blob, blen);
   } else
    r = ssh_krl_revoke_key(krl, key);
   if (r != 0)
    sshfatal("ssh-keygen.c", __func__, 2391, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "revoke key failed");
   freezero(blob, blen);
   blob = 
         ((void *)0)
             ;
   blen = 0;
   sshkey_free(key);
  }
 }
 if (strcmp(path, "-") != 0)
  fclose(krl_spec);
 free(line);
 free(path);
}

static void
do_gen_krl(struct passwd *pw, int updating, const char *ca_key_path,
    unsigned long long krl_version, const char *krl_comment,
    int argc, char **argv)
{
 struct ssh_krl *krl;
 struct stat sb;
 struct sshkey *ca = 
                    ((void *)0)
                        ;
 int i, r, wild_ca = 0;
 char *tmp;
 struct sshbuf *kbuf;

 if (*identity_file == '\0')
  sshfatal("ssh-keygen.c", __func__, 2417, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "KRL generation requires an output file");
 if (stat(identity_file, &sb) == -1) {
  if (
     (*__errno_location ()) 
           != 
              2
                    )
   sshfatal("ssh-keygen.c", __func__, 2420, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Cannot access KRL \"%s\": %s", identity_file, strerror(
  (*__errno_location ())
  ))
                                      ;
  if (updating)
   sshfatal("ssh-keygen.c", __func__, 2423, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "KRL \"%s\" does not exist", identity_file);
 }
 if (ca_key_path != 
                   ((void *)0)
                       ) {
  if (strcasecmp(ca_key_path, "none") == 0)
   wild_ca = 1;
  else {
   tmp = tilde_expand_filename(ca_key_path, pw->pw_uid);
   if ((r = sshkey_load_public(tmp, &ca, 
                                        ((void *)0)
                                            )) != 0)
    sshfatal("ssh-keygen.c", __func__, 2431, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Cannot load CA public key %s", tmp);
   free(tmp);
  }
 }

 if (updating)
  load_krl(identity_file, &krl);
 else if ((krl = ssh_krl_init()) == 
                                   ((void *)0)
                                       )
  sshfatal("ssh-keygen.c", __func__, 2439, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "couldn't create KRL");

 if (krl_version != 0)
  ssh_krl_set_version(krl, krl_version);
 if (krl_comment != 
                   ((void *)0)
                       )
  ssh_krl_set_comment(krl, krl_comment);

 for (i = 0; i < argc; i++)
  update_krl_from_file(pw, argv[i], wild_ca, ca, krl);

 if ((kbuf = sshbuf_new()) == 
                             ((void *)0)
                                 )
  sshfatal("ssh-keygen.c", __func__, 2450, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if (ssh_krl_to_blob(krl, kbuf, 
                               ((void *)0)
                                   , 0) != 0)
  sshfatal("ssh-keygen.c", __func__, 2452, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Couldn't generate KRL");
 if ((r = sshbuf_write_file(identity_file, kbuf)) != 0)
  sshfatal("ssh-keygen.c", __func__, 2454, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "write %s: %s", identity_file, strerror(
 (*__errno_location ())
 ));
 sshbuf_free(kbuf);
 ssh_krl_free(krl);
 sshkey_free(ca);
}

static void
do_check_krl(struct passwd *pw, int print_krl, int argc, char **argv)
{
 int i, r, ret = 0;
 char *comment;
 struct ssh_krl *krl;
 struct sshkey *k;

 if (*identity_file == '\0')
  sshfatal("ssh-keygen.c", __func__, 2469, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "KRL checking requires an input file");
 load_krl(identity_file, &krl);
 if (print_krl)
  krl_dump(krl, 
               stdout
                     );
 for (i = 0; i < argc; i++) {
  if ((r = sshkey_load_public(argv[i], &k, &comment)) != 0)
   sshfatal("ssh-keygen.c", __func__, 2475, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Cannot load public key %s", argv[i]);
  r = ssh_krl_check_key(krl, k);
  printf("%s%s%s%s: %s\n", argv[i],
      *comment ? " (" : "", comment, *comment ? ")" : "",
      r == 0 ? "ok" : "REVOKED");
  if (r != 0)
   ret = 1;
  sshkey_free(k);
  free(comment);
 }
 ssh_krl_free(krl);
 exit(ret);
}

static struct sshkey *
load_sign_key(const char *keypath, const struct sshkey *pubkey)
{
 size_t i, slen, plen = strlen(keypath);
 char *privpath = xstrdup(keypath);
 static const char * const suffixes[] = { "-cert.pub", ".pub", 
                                                              ((void *)0) 
                                                                   };
 struct sshkey *ret = 
                     ((void *)0)
                         , *privkey = 
                                      ((void *)0)
                                          ;
 int r, waspub = 0;
 struct stat st;






 for (i = 0; suffixes[i]; i++) {
  slen = strlen(suffixes[i]);
  if (plen <= slen ||
      strcmp(privpath + plen - slen, suffixes[i]) != 0)
   continue;
  privpath[plen - slen] = '\0';
  sshlog("ssh-keygen.c", __func__, 2510, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%s looks like a public key, using private key " "path %s instead", keypath, privpath)
                                           ;
  waspub = 1;
 }
 if (waspub && stat(privpath, &st) != 0 && 
                                          (*__errno_location ()) 
                                                == 
                                                   2
                                                         )
  sshfatal("ssh-keygen.c", __func__, 2515, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "No private key found for public key \"%s\"", keypath);
 if ((r = sshkey_load_private(privpath, "", &privkey, 
                                                     ((void *)0)
                                                         )) != 0 &&
     (r != -43)) {
  sshlog("ssh-keygen.c", __func__, 2518, 1, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "load private key \"%s\"", privpath);
  sshfatal("ssh-keygen.c", __func__, 2519, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "No private key found for \"%s\"", privpath);
 } else if (privkey == 
                      ((void *)0)
                          )
  privkey = load_identity(privpath, 
                                   ((void *)0)
                                       );

 if (!sshkey_equal_public(pubkey, privkey)) {
  sshlog("ssh-keygen.c", __func__, 2524, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Public key %s doesn't match private %s", keypath, privpath)
                        ;
  goto done;
 }
 if (sshkey_is_cert(pubkey) && !sshkey_is_cert(privkey)) {




  if ((r = sshkey_to_certified(privkey)) != 0) {
   sshlog("ssh-keygen.c", __func__, 2534, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshkey_to_certified");
   goto done;
  }
  if ((r = sshkey_cert_copy(pubkey, privkey)) != 0) {
   sshlog("ssh-keygen.c", __func__, 2538, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshkey_cert_copy");
   goto done;
  }
 }

 ret = privkey;
 privkey = 
          ((void *)0)
              ;
 done:
 sshkey_free(privkey);
 free(privpath);
 return ret;
}

static int
sign_one(struct sshkey *signkey, const char *filename, int fd,
    const char *sig_namespace, const char *hashalg, sshsig_signer *signer,
    void *signer_ctx)
{
 struct sshbuf *sigbuf = 
                        ((void *)0)
                            , *abuf = 
                                      ((void *)0)
                                          ;
 int r = -1, wfd = -1, oerrno;
 char *wfile = 
              ((void *)0)
                  , *asig = 
                            ((void *)0)
                                , *fp = 
                                        ((void *)0)
                                            ;
 char *pin = 
            ((void *)0)
                , *prompt = 
                            ((void *)0)
                                ;

 if (!quiet) {
  if (fd == 
           0
                       )
   fprintf(
          stderr
                , "Signing data on standard input\n");
  else
   fprintf(
          stderr
                , "Signing file %s\n", filename);
 }
 if (signer == 
              ((void *)0) 
                   && sshkey_is_sk(signkey)) {
  if ((signkey->sk_flags & 0x04)) {
   xasprintf(&prompt, "Enter PIN for %s key: ",
       sshkey_type(signkey));
   if ((pin = read_passphrase(prompt,
       0x0002)) == 
                          ((void *)0)
                              )
    sshfatal("ssh-keygen.c", __func__, 2573, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "couldn't read PIN");
  }
  if ((signkey->sk_flags & 0x01)) {
   if ((fp = sshkey_fingerprint(signkey, fingerprint_hash,
       SSH_FP_DEFAULT)) == 
                          ((void *)0)
                              )
    sshfatal("ssh-keygen.c", __func__, 2578, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "fingerprint failed");
   fprintf(
          stderr
                , "Confirm user presence for key %s %s\n",
       sshkey_type(signkey), fp);
   free(fp);
  }
 }
 if ((r = sshsig_sign_fd(signkey, hashalg, sk_provider, pin,
     fd, sig_namespace, &sigbuf, signer, signer_ctx)) != 0) {
  sshlog("ssh-keygen.c", __func__, 2586, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Signing %s failed", filename);
  goto out;
 }
 if ((r = sshsig_armor(sigbuf, &abuf)) != 0) {
  sshlog("ssh-keygen.c", __func__, 2590, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshsig_armor");
  goto out;
 }
 if ((asig = sshbuf_dup_string(abuf)) == 
                                        ((void *)0)
                                            ) {
  sshlog("ssh-keygen.c", __func__, 2594, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "buffer error");
  r = -2;
  goto out;
 }

 if (fd == 
          0
                      ) {
  fputs(asig, 
             stdout
                   );
  fflush(
        stdout
              );
 } else {
  xasprintf(&wfile, "%s.sig", filename);
  if (confirm_overwrite(wfile)) {
   if ((wfd = open(wfile, 
                         01
                                 |
                                  0100
                                         |
                                          01000
                                                 ,
       0666)) == -1) {
    oerrno = 
            (*__errno_location ())
                 ;
    sshlog("ssh-keygen.c", __func__, 2608, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Cannot open %s: %s", wfile, strerror(
   (*__errno_location ())
   ))
                               ;
    
   (*__errno_location ()) 
         = oerrno;
    r = -24;
    goto out;
   }
   if (atomicio((ssize_t (*)(int, void *, size_t))write, wfd, asig,
       strlen(asig)) != strlen(asig)) {
    oerrno = 
            (*__errno_location ())
                 ;
    sshlog("ssh-keygen.c", __func__, 2617, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Cannot write to %s: %s", wfile, strerror(
   (*__errno_location ())
   ))
                               ;
    
   (*__errno_location ()) 
         = oerrno;
    r = -24;
    goto out;
   }
   if (!quiet) {
    fprintf(
           stderr
                 , "Write signature to %s\n",
        wfile);
   }
  }
 }

 r = 0;
 out:
 free(wfile);
 free(prompt);
 free(asig);
 if (pin != 
           ((void *)0)
               )
  freezero(pin, strlen(pin));
 sshbuf_free(abuf);
 sshbuf_free(sigbuf);
 if (wfd != -1)
  close(wfd);
 return r;
}

static int
sig_process_opts(char * const *opts, size_t nopts, char **hashalgp,
    uint64_t *verify_timep, int *print_pubkey)
{
 size_t i;
 time_t now;

 if (verify_timep != 
                    ((void *)0)
                        )
  *verify_timep = 0;
 if (print_pubkey != 
                    ((void *)0)
                        )
  *print_pubkey = 0;
 if (hashalgp != 
                ((void *)0)
                    )
  *hashalgp = 
             ((void *)0)
                 ;
 for (i = 0; i < nopts; i++) {
  if (hashalgp != 
                 ((void *)0) 
                      &&
      strncasecmp(opts[i], "hashalg=", 8) == 0) {
   *hashalgp = xstrdup(opts[i] + 8);
  } else if (verify_timep &&
      strncasecmp(opts[i], "verify-time=", 12) == 0) {
   if (parse_absolute_time(opts[i] + 12,
       verify_timep) != 0 || *verify_timep == 0) {
    sshlog("ssh-keygen.c", __func__, 2665, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Invalid \"verify-time\" option");
    return -10;
   }
  } else if (print_pubkey &&
      strcasecmp(opts[i], "print-pubkey") == 0) {
   *print_pubkey = 1;
  } else {
   sshlog("ssh-keygen.c", __func__, 2672, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Invalid option \"%s\"", opts[i]);
   return -10;
  }
 }
 if (verify_timep && *verify_timep == 0) {
  if ((now = time(
                 ((void *)0)
                     )) < 0) {
   sshlog("ssh-keygen.c", __func__, 2678, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Time is before epoch");
   return -10;
  }
  *verify_timep = (uint64_t)now;
 }
 return 0;
}


static int
sig_sign(const char *keypath, const char *sig_namespace, int require_agent,
    int argc, char **argv, char * const *opts, size_t nopts)
{
 int i, fd = -1, r, ret = -1;
 int agent_fd = -1;
 struct sshkey *pubkey = 
                        ((void *)0)
                            , *privkey = 
                                         ((void *)0)
                                             , *signkey = 
                                                          ((void *)0)
                                                              ;
 sshsig_signer *signer = 
                        ((void *)0)
                            ;
 char *hashalg = 
                ((void *)0)
                    ;


 for (i = 0; i < argc; i++) {
  if (strcmp(argv[i], "-") != 0)
   continue;
  if (i > 0 || argc > 1)
   sshfatal("ssh-keygen.c", __func__, 2702, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Cannot sign mix of paths and standard input");
 }

 if (sig_process_opts(opts, nopts, &hashalg, 
                                            ((void *)0)
                                                , 
                                                  ((void *)0)
                                                      ) != 0)
  goto done;

 if ((r = sshkey_load_public(keypath, &pubkey, 
                                              ((void *)0)
                                                  )) != 0) {
  sshlog("ssh-keygen.c", __func__, 2709, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Couldn't load public key %s", keypath);
  goto done;
 }

 if ((r = ssh_get_authentication_socket(&agent_fd)) != 0) {
  if (require_agent)
   sshfatal("ssh-keygen.c", __func__, 2715, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Couldn't get agent socket");
  sshlog("ssh-keygen.c", __func__, 2716, 0, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "Couldn't get agent socket");
 } else {
  if ((r = ssh_agent_has_key(agent_fd, pubkey)) == 0)
   signer = agent_signer;
  else {
   if (require_agent)
    sshfatal("ssh-keygen.c", __func__, 2722, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Couldn't find key in agent");
   sshlog("ssh-keygen.c", __func__, 2723, 0, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "Couldn't find key in agent");
  }
 }

 if (signer == 
              ((void *)0)
                  ) {

  if ((privkey = load_sign_key(keypath, pubkey)) == 
                                                   ((void *)0)
                                                       )
   goto done;
  signkey = privkey;
 } else {

  signkey = pubkey;
 }

 if (argc == 0) {
  if ((r = sign_one(signkey, "(stdin)", 
                                       0
                                                   ,
      sig_namespace, hashalg, signer, &agent_fd)) != 0)
   goto done;
 } else {
  for (i = 0; i < argc; i++) {
   if (strcmp(argv[i], "-") == 0)
    fd = 
        0
                    ;
   else if ((fd = open(argv[i], 
                               00
                                       )) == -1) {
    sshlog("ssh-keygen.c", __func__, 2746, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Cannot open %s for signing: %s", argv[i], strerror(
   (*__errno_location ())
   ))
                                 ;
    goto done;
   }
   if ((r = sign_one(signkey, argv[i], fd, sig_namespace,
       hashalg, signer, &agent_fd)) != 0)
    goto done;
   if (fd != 
            0
                        )
    close(fd);
   fd = -1;
  }
 }

 ret = 0;
done:
 if (fd != -1 && fd != 
                      0
                                  )
  close(fd);
 sshkey_free(pubkey);
 sshkey_free(privkey);
 free(hashalg);
 return ret;
}

static int
sig_verify(const char *signature, const char *sig_namespace,
    const char *principal, const char *allowed_keys, const char *revoked_keys,
    char * const *opts, size_t nopts)
{
 int r, ret = -1;
 int print_pubkey = 0;
 struct sshbuf *sigbuf = 
                        ((void *)0)
                            , *abuf = 
                                      ((void *)0)
                                          ;
 struct sshkey *sign_key = 
                          ((void *)0)
                              ;
 char *fp = 
           ((void *)0)
               ;
 struct sshkey_sig_details *sig_details = 
                                         ((void *)0)
                                             ;
 uint64_t verify_time = 0;

 if (sig_process_opts(opts, nopts, 
                                  ((void *)0)
                                      , &verify_time,
     &print_pubkey) != 0)
  goto done;

 memset(&sig_details, 0, sizeof(sig_details));
 if ((r = sshbuf_load_file(signature, &abuf)) != 0) {
  sshlog("ssh-keygen.c", __func__, 2788, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Couldn't read signature file");
  goto done;
 }

 if ((r = sshsig_dearmor(abuf, &sigbuf)) != 0) {
  sshlog("ssh-keygen.c", __func__, 2793, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshsig_armor");
  goto done;
 }
 if ((r = sshsig_verify_fd(sigbuf, 
                                  0
                                              , sig_namespace,
     &sign_key, &sig_details)) != 0)
  goto done;

 if ((fp = sshkey_fingerprint(sign_key, fingerprint_hash,
     SSH_FP_DEFAULT)) == 
                        ((void *)0)
                            )
  sshfatal("ssh-keygen.c", __func__, 2802, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshkey_fingerprint failed");
 sshlog("ssh-keygen.c", __func__, 2803, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Valid (unverified) signature from key %s", fp);
 if (sig_details != 
                   ((void *)0)
                       ) {
  sshlog("ssh-keygen.c", __func__, 2805, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "signature details: counter = %u, flags = 0x%02x", sig_details->sk_counter, sig_details->sk_flags)
                                                     ;
 }
 free(fp);
 fp = 
     ((void *)0)
         ;

 if (revoked_keys != 
                    ((void *)0)
                        ) {
  if ((r = sshkey_check_revoked(sign_key, revoked_keys)) != 0) {
   sshlog("ssh-keygen.c", __func__, 2813, 1, SYSLOG_LEVEL_DEBUG3, ssh_err(r), "sshkey_check_revoked");
   goto done;
  }
 }

 if (allowed_keys != 
                    ((void *)0) 
                         && (r = sshsig_check_allowed_keys(allowed_keys,
     sign_key, principal, sig_namespace, verify_time)) != 0) {
  sshlog("ssh-keygen.c", __func__, 2820, 1, SYSLOG_LEVEL_DEBUG3, ssh_err(r), "sshsig_check_allowed_keys");
  goto done;
 }

 ret = 0;
done:
 if (!quiet) {
  if (ret == 0) {
   if ((fp = sshkey_fingerprint(sign_key, fingerprint_hash,
       SSH_FP_DEFAULT)) == 
                          ((void *)0)
                              )
    sshfatal("ssh-keygen.c", __func__, 2830, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "sshkey_fingerprint failed");
   if (principal == 
                   ((void *)0)
                       ) {
    printf("Good \"%s\" signature with %s key %s\n",
        sig_namespace, sshkey_type(sign_key), fp);

   } else {
    printf("Good \"%s\" signature for %s with %s key %s\n",
        sig_namespace, principal,
        sshkey_type(sign_key), fp);
   }
  } else {
   printf("Could not verify signature.\n");
  }
 }

 if (ret == 0 && print_pubkey && sign_key != 
                                            ((void *)0)
                                                ) {
  if ((r = sshkey_write(sign_key, 
                                 stdout
                                       )) == 0)
   fputc('\n', 
              stdout
                    );
  else {
   sshlog("ssh-keygen.c", __func__, 2849, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Could not print public key.\n");
   ret = -1;
  }
 }
 sshbuf_free(sigbuf);
 sshbuf_free(abuf);
 sshkey_free(sign_key);
 sshkey_sig_details_free(sig_details);
 free(fp);
 return ret;
}

static int
sig_find_principals(const char *signature, const char *allowed_keys,
    char * const *opts, size_t nopts)
{
 int r, ret = -1;
 struct sshbuf *sigbuf = 
                        ((void *)0)
                            , *abuf = 
                                      ((void *)0)
                                          ;
 struct sshkey *sign_key = 
                          ((void *)0)
                              ;
 char *principals = 
                   ((void *)0)
                       , *cp, *tmp;
 uint64_t verify_time = 0;

 if (sig_process_opts(opts, nopts, 
                                  ((void *)0)
                                      , &verify_time, 
                                                      ((void *)0)
                                                          ) != 0)
  goto done;

 if ((r = sshbuf_load_file(signature, &abuf)) != 0) {
  sshlog("ssh-keygen.c", __func__, 2875, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Couldn't read signature file");
  goto done;
 }
 if ((r = sshsig_dearmor(abuf, &sigbuf)) != 0) {
  sshlog("ssh-keygen.c", __func__, 2879, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshsig_armor");
  goto done;
 }
 if ((r = sshsig_get_pubkey(sigbuf, &sign_key)) != 0) {
  sshlog("ssh-keygen.c", __func__, 2883, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshsig_get_pubkey");
  goto done;
 }
 if ((r = sshsig_find_principals(allowed_keys, sign_key,
     verify_time, &principals)) != 0) {
  if (r != -46)
   sshlog("ssh-keygen.c", __func__, 2889, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshsig_find_principal");
  goto done;
 }
 ret = 0;
done:
 if (ret == 0 ) {

  tmp = principals;
  while ((cp = strsep(&tmp, ",")) != 
                                    ((void *)0) 
                                         && *cp != '\0')
   puts(cp);
 } else {
  fprintf(
         stderr
               , "No principal matched.\n");
 }
 sshbuf_free(sigbuf);
 sshbuf_free(abuf);
 sshkey_free(sign_key);
 free(principals);
 return ret;
}

static int
sig_match_principals(const char *allowed_keys, char *principal,
 char * const *opts, size_t nopts)
{
 int r;
 char **principals = 
                    ((void *)0)
                        ;
 size_t i, nprincipals = 0;

 if ((r = sig_process_opts(opts, nopts, 
                                       ((void *)0)
                                           , 
                                             ((void *)0)
                                                 , 
                                                   ((void *)0)
                                                       )) != 0)
  return r;

 if ((r = sshsig_match_principals(allowed_keys, principal,
     &principals, &nprincipals)) != 0) {
  sshlog("ssh-keygen.c", __func__, 2922, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "match: %s", ssh_err(r));
  fprintf(
         stderr
               , "No principal matched.\n");
  return r;
 }
 for (i = 0; i < nprincipals; i++) {
  printf("%s\n", principals[i]);
  free(principals[i]);
 }
 free(principals);

 return 0;
}

static void
do_moduli_gen(const char *out_file, char **opts, size_t nopts)
{


 u_int32_t memory = 0;
 BIGNUM *start = 
                ((void *)0)
                    ;
 int moduli_bits = 0;
 FILE *out;
 size_t i;
 const char *errstr;


 for (i = 0; i < nopts; i++) {
  if (strncmp(opts[i], "memory=", 7) == 0) {
   memory = (u_int32_t)strtonum(opts[i]+7, 1,
       
      (0x7fffffff * 2U + 1U)
              , &errstr);
   if (errstr) {
    sshfatal("ssh-keygen.c", __func__, 2953, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Memory limit is %s: %s", errstr, opts[i]+7)
                          ;
   }
  } else if (strncmp(opts[i], "start=", 6) == 0) {

   if (BN_hex2bn(&start, opts[i]+6) == 0)
    sshfatal("ssh-keygen.c", __func__, 2959, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Invalid start point.");
  } else if (strncmp(opts[i], "bits=", 5) == 0) {
   moduli_bits = (int)strtonum(opts[i]+5, 1,
       0x7fffffff, &errstr);
   if (errstr) {
    sshfatal("ssh-keygen.c", __func__, 2964, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Invalid number: %s (%s)", opts[i]+12, errstr)
                        ;
   }
  } else {
   sshfatal("ssh-keygen.c", __func__, 2968, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Option \"%s\" is unsupported for moduli " "generation", opts[i])
                             ;
  }
 }

 if ((out = fopen(out_file, "w")) == 
                                    ((void *)0)
                                        ) {
  sshfatal("ssh-keygen.c", __func__, 2974, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Couldn't open modulus candidate file \"%s\": %s", out_file, strerror(
 (*__errno_location ())
 ))
                                ;
 }
 setvbuf(out, 
             ((void *)0)
                 , 
                   1
                         , 0);

 if (moduli_bits == 0)
  moduli_bits = 3072;
 if (gen_candidates(out, memory, moduli_bits, start) != 0)
  sshfatal("ssh-keygen.c", __func__, 2982, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "modulus candidate generation failed");



}

static void
do_moduli_screen(const char *out_file, char **opts, size_t nopts)
{


 char *checkpoint = 
                   ((void *)0)
                       ;
 u_int32_t generator_wanted = 0;
 unsigned long start_lineno = 0, lines_to_process = 0;
 int prime_tests = 0;
 FILE *out, *in = 
                 stdin
                      ;
 size_t i;
 const char *errstr;


 for (i = 0; i < nopts; i++) {
  if (strncmp(opts[i], "lines=", 6) == 0) {
   lines_to_process = strtoul(opts[i]+6, 
                                        ((void *)0)
                                            , 10);
  } else if (strncmp(opts[i], "start-line=", 11) == 0) {
   start_lineno = strtoul(opts[i]+11, 
                                     ((void *)0)
                                         , 10);
  } else if (strncmp(opts[i], "checkpoint=", 11) == 0) {
   checkpoint = xstrdup(opts[i]+11);
  } else if (strncmp(opts[i], "generator=", 10) == 0) {
   generator_wanted = (u_int32_t)strtonum(
       opts[i]+10, 1, 
                     (0x7fffffff * 2U + 1U)
                             , &errstr);
   if (errstr != 
                ((void *)0)
                    ) {
    sshfatal("ssh-keygen.c", __func__, 3013, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Generator invalid: %s (%s)", opts[i]+10, errstr)
                           ;
   }
  } else if (strncmp(opts[i], "prime-tests=", 12) == 0) {
   prime_tests = (int)strtonum(opts[i]+12, 1,
       0x7fffffff, &errstr);
   if (errstr) {
    sshfatal("ssh-keygen.c", __func__, 3020, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Invalid number: %s (%s)", opts[i]+12, errstr)
                        ;
   }
  } else {
   sshfatal("ssh-keygen.c", __func__, 3024, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Option \"%s\" is unsupported for moduli " "screening", opts[i])
                            ;
  }
 }

 if (have_identity && strcmp(identity_file, "-") != 0) {
  if ((in = fopen(identity_file, "r")) == 
                                         ((void *)0)
                                             ) {
   sshfatal("ssh-keygen.c", __func__, 3031, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Couldn't open modulus candidate " "file \"%s\": %s", identity_file, strerror(
  (*__errno_location ())
  ))

                       ;
  }
 }

 if ((out = fopen(out_file, "a")) == 
                                    ((void *)0)
                                        ) {
  sshfatal("ssh-keygen.c", __func__, 3038, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Couldn't open moduli file \"%s\": %s", out_file, strerror(
 (*__errno_location ())
 ))
                                ;
 }
 setvbuf(out, 
             ((void *)0)
                 , 
                   1
                         , 0);
 if (prime_test(in, out, prime_tests == 0 ? 100 : prime_tests,
     generator_wanted, checkpoint,
     start_lineno, lines_to_process) != 0)
  sshfatal("ssh-keygen.c", __func__, 3045, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "modulus screening failed");



}


static char *
read_check_passphrase(const char *prompt1, const char *prompt2,
    const char *retry_prompt)
{
 char *passphrase1, *passphrase2;

 for (;;) {
  passphrase1 = read_passphrase(prompt1, 0x0002);
  passphrase2 = read_passphrase(prompt2, 0x0002);
  if (strcmp(passphrase1, passphrase2) == 0) {
   freezero(passphrase2, strlen(passphrase2));
   return passphrase1;
  }

  freezero(passphrase1, strlen(passphrase1));
  freezero(passphrase2, strlen(passphrase2));
  fputs(retry_prompt, 
                     stdout
                           );
  fputc('\n', 
             stdout
                   );
  fflush(
        stdout
              );
 }

 return 
       ((void *)0)
           ;
}

static char *
private_key_passphrase(void)
{
 if (identity_passphrase)
  return xstrdup(identity_passphrase);
 if (identity_new_passphrase)
  return xstrdup(identity_new_passphrase);

 return read_check_passphrase(
     "Enter passphrase (empty for no passphrase): ",
     "Enter same passphrase again: ",
     "Passphrases do not match.  Try again.");
}

static char *
sk_suffix(const char *application, const uint8_t *user, size_t userlen)
{
 char *ret, *cp;
 size_t slen, i;


 if (strncmp(application, "ssh://", 6) == 0)
  ret = xstrdup(application + 6);
 else if (strncmp(application, "ssh:", 4) == 0)
  ret = xstrdup(application + 4);
 else
  ret = xstrdup(application);


 for (i = 0; i < userlen; i++) {
  if (user[userlen - i - 1] != 0)
   break;
 }
 if (i >= userlen)
  return ret;


 slen = userlen - i;
 if (asmprintf(&cp, 0x7fffffff, 
                            ((void *)0)
                                , "%.*s", (int)slen, user) == -1)
  sshfatal("ssh-keygen.c", __func__, 3115, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "asmprintf failed");

 if (strchr(cp, '/') != 
                       ((void *)0) 
                            || strstr(cp, "..") != 
                                                   ((void *)0) 
                                                        ||
     strchr(cp, '\\') != 
                        ((void *)0)
                            ) {
  free(cp);
  cp = tohex(user, slen);
 }
 xextendf(&ret, "_", "%s", cp);
 free(cp);
 return ret;
}

static int
do_download_sk(const char *skprovider, const char *device)
{
 struct sshsk_resident_key **srks;
 size_t nsrks, i;
 int r, ret = -1;
 char *fp, *pin = 
                 ((void *)0)
                     , *pass = 
                               ((void *)0)
                                   , *path, *pubpath;
 const char *ext;
 struct sshkey *key;

 if (skprovider == 
                  ((void *)0)
                      )
  sshfatal("ssh-keygen.c", __func__, 3138, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Cannot download keys without provider");

 pin = read_passphrase("Enter PIN for authenticator: ", 0x0002);
 if (!quiet) {
  printf("You may need to touch your authenticator "
      "to authorize key download.\n");
 }
 if ((r = sshsk_load_resident(skprovider, device, pin, 0,
     &srks, &nsrks)) != 0) {
  if (pin != 
            ((void *)0)
                )
   freezero(pin, strlen(pin));
  sshlog("ssh-keygen.c", __func__, 3149, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Unable to load resident keys");
  return -1;
 }
 if (nsrks == 0)
  sshlog("ssh-keygen.c", __func__, 3153, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "No keys to download");
 if (pin != 
           ((void *)0)
               )
  freezero(pin, strlen(pin));

 for (i = 0; i < nsrks; i++) {
  key = srks[i]->key;
  if (key->type != KEY_ECDSA_SK && key->type != KEY_ED25519_SK) {
   sshlog("ssh-keygen.c", __func__, 3160, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Unsupported key type %s (%d)", sshkey_type(key), key->type)
                                   ;
   continue;
  }
  if ((fp = sshkey_fingerprint(key, fingerprint_hash,
      SSH_FP_DEFAULT)) == 
                         ((void *)0)
                             )
   sshfatal("ssh-keygen.c", __func__, 3166, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshkey_fingerprint failed");
  sshlog("ssh-keygen.c", __func__, 3167, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "key %zu: %s %s %s (flags 0x%02x)", i, sshkey_type(key), fp, key->sk_application, key->sk_flags)
                                                               ;
  ext = sk_suffix(key->sk_application,
      srks[i]->user_id, srks[i]->user_id_len);
  xasprintf(&path, "id_%s_rk%s%s",
      key->type == KEY_ECDSA_SK ? "ecdsa_sk" : "ed25519_sk",
      *ext == '\0' ? "" : "_", ext);


  if (!confirm_overwrite(path)) {
   free(path);
   break;
  }


  if (pass == 
             ((void *)0)
                 )
   pass = private_key_passphrase();
  if ((r = sshkey_save_private(key, path, pass,
      key->sk_application, private_key_format,
      openssh_format_cipher, rounds)) != 0) {
   sshlog("ssh-keygen.c", __func__, 3187, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Saving key \"%s\" failed", path);
   free(path);
   break;
  }
  if (!quiet) {
   printf("Saved %s key%s%s to %s\n", sshkey_type(key),
       *ext != '\0' ? " " : "",
       *ext != '\0' ? key->sk_application : "",
       path);
  }


  xasprintf(&pubpath, "%s.pub", path);
  free(path);
  if ((r = sshkey_save_public(key, pubpath,
      key->sk_application)) != 0) {
   sshlog("ssh-keygen.c", __func__, 3203, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Saving public key \"%s\" failed", pubpath);
   free(pubpath);
   break;
  }
  free(pubpath);
 }

 if (i >= nsrks)
  ret = 0;
 if (pass != 
            ((void *)0)
                )
  freezero(pass, strlen(pass));
 sshsk_free_resident_keys(srks, nsrks);
 return ret;
}

static void
save_attestation(struct sshbuf *attest, const char *path)
{
 mode_t omask;
 int r;

 if (path == 
            ((void *)0)
                )
  return;
 if (attest == 
              ((void *)0) 
                   || sshbuf_len(attest) == 0)
  sshfatal("ssh-keygen.c", __func__, 3227, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Enrollment did not return attestation data");
 omask = umask(077);
 r = sshbuf_write_file(path, attest);
 umask(omask);
 if (r != 0)
  sshfatal("ssh-keygen.c", __func__, 3232, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Unable to write attestation data \"%s\"", path);
 if (!quiet)
  printf("Your FIDO attestation certificate has been saved in "
      "%s\n", path);
}

static int
confirm_sk_overwrite(const char *application, const char *user)
{
 char yesno[3];

 printf("A resident key scoped to '%s' with user id '%s' already "
     "exists.\n", application == 
                                ((void *)0) 
                                     ? "ssh:" : application,
     user == 
            ((void *)0) 
                 ? "null" : user);
 printf("Overwrite key in token (y/n)? ");
 fflush(
       stdout
             );
 if (fgets(yesno, sizeof(yesno), 
                                stdin
                                     ) == 
                                          ((void *)0)
                                              )
  return 0;
 if (yesno[0] != 'y' && yesno[0] != 'Y')
  return 0;
 return 1;
}

static void
usage(void)
{
 fprintf(
        stderr
              ,
     "usage: ssh-keygen [-q] [-a rounds] [-b bits] [-C comment] [-f output_keyfile]\n"
     "                  [-m format] [-N new_passphrase] [-O option]\n"
     "                  [-t dsa | ecdsa | ecdsa-sk | ed25519 | ed25519-sk | rsa]\n"
     "                  [-w provider] [-Z cipher]\n"
     "       ssh-keygen -p [-a rounds] [-f keyfile] [-m format] [-N new_passphrase]\n"
     "                   [-P old_passphrase] [-Z cipher]\n"

     "       ssh-keygen -i [-f input_keyfile] [-m key_format]\n"
     "       ssh-keygen -e [-f input_keyfile] [-m key_format]\n"

     "       ssh-keygen -y [-f input_keyfile]\n"
     "       ssh-keygen -c [-a rounds] [-C comment] [-f keyfile] [-P passphrase]\n"
     "       ssh-keygen -l [-v] [-E fingerprint_hash] [-f input_keyfile]\n"
     "       ssh-keygen -B [-f input_keyfile]\n");

 fprintf(
        stderr
              ,
     "       ssh-keygen -D pkcs11\n");

 fprintf(
        stderr
              ,
     "       ssh-keygen -F hostname [-lv] [-f known_hosts_file]\n"
     "       ssh-keygen -H [-f known_hosts_file]\n"
     "       ssh-keygen -K [-a rounds] [-w provider]\n"
     "       ssh-keygen -R hostname [-f known_hosts_file]\n"
     "       ssh-keygen -r hostname [-g] [-f input_keyfile]\n"

     "       ssh-keygen -M generate [-O option] output_file\n"
     "       ssh-keygen -M screen [-f input_file] [-O option] output_file\n"

     "       ssh-keygen -I certificate_identity -s ca_key [-hU] [-D pkcs11_provider]\n"
     "                  [-n principals] [-O option] [-V validity_interval]\n"
     "                  [-z serial_number] file ...\n"
     "       ssh-keygen -L [-f input_keyfile]\n"
     "       ssh-keygen -A [-a rounds] [-f prefix_path]\n"
     "       ssh-keygen -k -f krl_file [-u] [-s ca_public] [-z version_number]\n"
     "                  file ...\n"
     "       ssh-keygen -Q [-l] -f krl_file [file ...]\n"
     "       ssh-keygen -Y find-principals -s signature_file -f allowed_signers_file\n"
     "       ssh-keygen -Y match-principals -I signer_identity -f allowed_signers_file\n"
     "       ssh-keygen -Y check-novalidate -n namespace -s signature_file\n"
     "       ssh-keygen -Y sign -f key_file -n namespace file [-O option] ...\n"
     "       ssh-keygen -Y verify -f allowed_signers_file -I signer_identity\n"
     "                  -n namespace -s signature_file [-r krl_file] [-O option]\n");
 exit(1);
}




int
main(int argc, char **argv)
{
 char comment[1024], *passphrase = 
                                  ((void *)0)
                                      ;
 char *rr_hostname = 
                    ((void *)0)
                        , *ep, *fp, *ra;
 struct sshkey *private, *public;
 struct passwd *pw;
 int r, opt, type;
 int change_passphrase = 0, change_comment = 0, show_cert = 0;
 int find_host = 0, delete_host = 0, hash_hosts = 0;
 int gen_all_hostkeys = 0, gen_krl = 0, update_krl = 0, check_krl = 0;
 int prefer_agent = 0, convert_to = 0, convert_from = 0;
 int print_public = 0, print_generic = 0, cert_serial_autoinc = 0;
 int do_gen_candidates = 0, do_screen_candidates = 0, download_sk = 0;
 unsigned long long cert_serial = 0;
 char *identity_comment = 
                         ((void *)0)
                             , *ca_key_path = 
                                              ((void *)0)
                                                  , **opts = 
                                                             ((void *)0)
                                                                 ;
 char *sk_application = 
                       ((void *)0)
                           , *sk_device = 
                                          ((void *)0)
                                              , *sk_user = 
                                                           ((void *)0)
                                                               ;
 char *sk_attestation_path = 
                            ((void *)0)
                                ;
 struct sshbuf *challenge = 
                           ((void *)0)
                               , *attest = 
                                           ((void *)0)
                                               ;
 size_t i, nopts = 0;
 u_int32_t bits = 0;
 uint8_t sk_flags = 0x01;
 const char *errstr;
 int log_level = SYSLOG_LEVEL_INFO;
 char *sign_op = 
                ((void *)0)
                    ;

 extern int BSDoptind;
 extern char *BSDoptarg;


 sanitise_stdfd();

 __progname = ssh_get_progname(argv[0]);

 seed_rng();

 log_init(argv[0], SYSLOG_LEVEL_INFO, SYSLOG_FACILITY_USER, 1);

 msetlocale();


 pw = getpwuid(getuid());
 if (!pw)
  sshfatal("ssh-keygen.c", __func__, 3350, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "No user exists for uid %lu", (u_long)getuid());
 pw = pwcopy(pw);
 if (gethostname(hostname, sizeof(hostname)) == -1)
  sshfatal("ssh-keygen.c", __func__, 3353, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "gethostname: %s", strerror(
 (*__errno_location ())
 ));

 sk_provider = getenv("SSH_SK_PROVIDER");


 while ((opt = BSDgetopt(argc, argv, "ABHKLQUXceghiklopquvy" "C:D:E:F:I:M:N:O:P:R:V:Y:Z:" "a:b:f:g:m:n:r:s:t:w:z:")

                              ) != -1) {
  switch (opt) {
  case 'A':
   gen_all_hostkeys = 1;
   break;
  case 'b':
   bits = (u_int32_t)strtonum(BSDoptarg, 1, 
                                        (4294967295U)
                                                  ,
       &errstr);
   if (errstr)
    sshfatal("ssh-keygen.c", __func__, 3369, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Bits has bad value %s (%s)", BSDoptarg, errstr)
                    ;
   break;
  case 'E':
   fingerprint_hash = ssh_digest_alg_by_name(BSDoptarg);
   if (fingerprint_hash == -1)
    sshfatal("ssh-keygen.c", __func__, 3375, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Invalid hash algorithm \"%s\"", BSDoptarg);
   break;
  case 'F':
   find_host = 1;
   rr_hostname = BSDoptarg;
   break;
  case 'H':
   hash_hosts = 1;
   break;
  case 'I':
   cert_key_id = BSDoptarg;
   break;
  case 'R':
   delete_host = 1;
   rr_hostname = BSDoptarg;
   break;
  case 'L':
   show_cert = 1;
   break;
  case 'l':
   print_fingerprint = 1;
   break;
  case 'B':
   print_bubblebabble = 1;
   break;
  case 'm':
   if (strcasecmp(BSDoptarg, "RFC4716") == 0 ||
       strcasecmp(BSDoptarg, "ssh2") == 0) {
    convert_format = FMT_RFC4716;
    break;
   }
   if (strcasecmp(BSDoptarg, "PKCS8") == 0) {
    convert_format = FMT_PKCS8;
    private_key_format = SSHKEY_PRIVATE_PKCS8;
    break;
   }
   if (strcasecmp(BSDoptarg, "PEM") == 0) {
    convert_format = FMT_PEM;
    private_key_format = SSHKEY_PRIVATE_PEM;
    break;
   }
   sshfatal("ssh-keygen.c", __func__, 3416, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Unsupported conversion format \"%s\"", BSDoptarg);
  case 'n':
   cert_principals = BSDoptarg;
   break;
  case 'o':

   break;
  case 'p':
   change_passphrase = 1;
   break;
  case 'c':
   change_comment = 1;
   break;
  case 'f':
   if (strlcpy(identity_file, BSDoptarg,
       sizeof(identity_file)) >= sizeof(identity_file))
    sshfatal("ssh-keygen.c", __func__, 3432, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Identity filename too long");
   have_identity = 1;
   break;
  case 'g':
   print_generic = 1;
   break;
  case 'K':
   download_sk = 1;
   break;
  case 'P':
   identity_passphrase = BSDoptarg;
   break;
  case 'N':
   identity_new_passphrase = BSDoptarg;
   break;
  case 'Q':
   check_krl = 1;
   break;
  case 'O':
   opts = xrecallocarray(opts, nopts, nopts + 1,
       sizeof(*opts));
   opts[nopts++] = xstrdup(BSDoptarg);
   break;
  case 'Z':
   openssh_format_cipher = BSDoptarg;
   if (cipher_by_name(openssh_format_cipher) == 
                                               ((void *)0)
                                                   )
    sshfatal("ssh-keygen.c", __func__, 3458, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Invalid OpenSSH-format cipher '%s'", openssh_format_cipher)
                              ;
   break;
  case 'C':
   identity_comment = BSDoptarg;
   break;
  case 'q':
   quiet = 1;
   break;
  case 'e':

   convert_to = 1;
   break;
  case 'h':
   cert_key_type = 2;
   certflags_flags = 0;
   break;
  case 'k':
   gen_krl = 1;
   break;
  case 'i':
  case 'X':

   convert_from = 1;
   break;
  case 'y':
   print_public = 1;
   break;
  case 's':
   ca_key_path = BSDoptarg;
   break;
  case 't':
   key_type_name = BSDoptarg;
   break;
  case 'D':
   pkcs11provider = BSDoptarg;
   break;
  case 'U':
   prefer_agent = 1;
   break;
  case 'u':
   update_krl = 1;
   break;
  case 'v':
   if (log_level == SYSLOG_LEVEL_INFO)
    log_level = SYSLOG_LEVEL_DEBUG1;
   else {
    if (log_level >= SYSLOG_LEVEL_DEBUG1 &&
        log_level < SYSLOG_LEVEL_DEBUG3)
     log_level++;
   }
   break;
  case 'r':
   rr_hostname = BSDoptarg;
   break;
  case 'a':
   rounds = (int)strtonum(BSDoptarg, 1, 0x7fffffff, &errstr);
   if (errstr)
    sshfatal("ssh-keygen.c", __func__, 3516, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Invalid number: %s (%s)", BSDoptarg, errstr)
                    ;
   break;
  case 'V':
   parse_cert_times(BSDoptarg);
   break;
  case 'Y':
   sign_op = BSDoptarg;
   break;
  case 'w':
   sk_provider = BSDoptarg;
   break;
  case 'z':
   
  (*__errno_location ()) 
        = 0;
   if (*BSDoptarg == '+') {
    cert_serial_autoinc = 1;
    BSDoptarg++;
   }
   cert_serial = strtoull(BSDoptarg, &ep, 10);
   if (*BSDoptarg < '0' || *BSDoptarg > '9' || *ep != '\0' ||
       (
       (*__errno_location ()) 
             == 
                34 
                       && cert_serial == 
                                         (0x7fffffffffffffffLL * 2ULL + 1ULL)
                                                   ))
    sshfatal("ssh-keygen.c", __func__, 3537, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Invalid serial number \"%s\"", BSDoptarg);
   break;
  case 'M':
   if (strcmp(BSDoptarg, "generate") == 0)
    do_gen_candidates = 1;
   else if (strcmp(BSDoptarg, "screen") == 0)
    do_screen_candidates = 1;
   else
    sshfatal("ssh-keygen.c", __func__, 3545, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Unsupported moduli option %s", BSDoptarg);
   break;
  case '?':
  default:
   usage();
  }
 }







 log_init(argv[0], log_level, SYSLOG_FACILITY_USER, 1);

 argv += BSDoptind;
 argc -= BSDoptind;

 if (sign_op != 
               ((void *)0)
                   ) {
  if (strncmp(sign_op, "find-principals", 15) == 0) {
   if (ca_key_path == 
                     ((void *)0)
                         ) {
    sshlog("ssh-keygen.c", __func__, 3567, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Too few arguments for find-principals:" "missing signature file")
                                 ;
    exit(1);
   }
   if (!have_identity) {
    sshlog("ssh-keygen.c", __func__, 3572, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Too few arguments for find-principals:" "missing allowed keys file")
                                    ;
    exit(1);
   }
   return sig_find_principals(ca_key_path, identity_file,
       opts, nopts);
  } else if (strncmp(sign_op, "match-principals", 16) == 0) {
   if (!have_identity) {
    sshlog("ssh-keygen.c", __func__, 3580, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Too few arguments for match-principals:" "missing allowed keys file")
                                    ;
    exit(1);
   }
   if (cert_key_id == 
                     ((void *)0)
                         ) {
    sshlog("ssh-keygen.c", __func__, 3585, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Too few arguments for match-principals: " "missing principal ID")
                               ;
    exit(1);
   }
   return sig_match_principals(identity_file, cert_key_id,
       opts, nopts);
  } else if (strncmp(sign_op, "sign", 4) == 0) {

   if (cert_principals == 
                         ((void *)0) 
                              ||
       *cert_principals == '\0') {
    sshlog("ssh-keygen.c", __func__, 3595, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Too few arguments for sign: " "missing namespace")
                            ;
    exit(1);
   }
   if (!have_identity) {
    sshlog("ssh-keygen.c", __func__, 3600, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Too few arguments for sign: " "missing key")
                      ;
    exit(1);
   }
   return sig_sign(identity_file, cert_principals,
       prefer_agent, argc, argv, opts, nopts);
  } else if (strncmp(sign_op, "check-novalidate", 16) == 0) {

   if (cert_principals == 
                         ((void *)0) 
                              ||
       *cert_principals == '\0') {
    sshlog("ssh-keygen.c", __func__, 3610, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Too few arguments for check-novalidate: " "missing namespace")
                            ;
    exit(1);
   }
   if (ca_key_path == 
                     ((void *)0)
                         ) {
    sshlog("ssh-keygen.c", __func__, 3615, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Too few arguments for check-novalidate: " "missing signature file")
                                 ;
    exit(1);
   }
   return sig_verify(ca_key_path, cert_principals,
       
      ((void *)0)
          , 
            ((void *)0)
                , 
                  ((void *)0)
                      , opts, nopts);
  } else if (strncmp(sign_op, "verify", 6) == 0) {

   if (cert_principals == 
                         ((void *)0) 
                              ||
       *cert_principals == '\0') {
    sshlog("ssh-keygen.c", __func__, 3625, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Too few arguments for verify: " "missing namespace")
                            ;
    exit(1);
   }
   if (ca_key_path == 
                     ((void *)0)
                         ) {
    sshlog("ssh-keygen.c", __func__, 3630, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Too few arguments for verify: " "missing signature file")
                                 ;
    exit(1);
   }
   if (!have_identity) {
    sshlog("ssh-keygen.c", __func__, 3635, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Too few arguments for sign: " "missing allowed keys file")
                                    ;
    exit(1);
   }
   if (cert_key_id == 
                     ((void *)0)
                         ) {
    sshlog("ssh-keygen.c", __func__, 3640, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Too few arguments for verify: " "missing principal identity")
                                     ;
    exit(1);
   }
   return sig_verify(ca_key_path, cert_principals,
       cert_key_id, identity_file, rr_hostname,
       opts, nopts);
  }
  sshlog("ssh-keygen.c", __func__, 3648, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Unsupported operation for -Y: \"%s\"", sign_op);
  usage();

 }

 if (ca_key_path != 
                   ((void *)0)
                       ) {
  if (argc < 1 && !gen_krl) {
   sshlog("ssh-keygen.c", __func__, 3655, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Too few arguments.");
   usage();
  }
 } else if (argc > 0 && !gen_krl && !check_krl &&
     !do_gen_candidates && !do_screen_candidates) {
  sshlog("ssh-keygen.c", __func__, 3660, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Too many arguments.");
  usage();
 }
 if (change_passphrase && change_comment) {
  sshlog("ssh-keygen.c", __func__, 3664, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Can only have one of -p and -c.");
  usage();
 }
 if (print_fingerprint && (delete_host || hash_hosts)) {
  sshlog("ssh-keygen.c", __func__, 3668, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Cannot use -l with -H or -R.");
  usage();
 }
 if (gen_krl) {
  do_gen_krl(pw, update_krl, ca_key_path,
      cert_serial, identity_comment, argc, argv);
  return (0);
 }
 if (check_krl) {
  do_check_krl(pw, print_fingerprint, argc, argv);
  return (0);
 }
 if (ca_key_path != 
                   ((void *)0)
                       ) {
  if (cert_key_id == 
                    ((void *)0)
                        )
   sshfatal("ssh-keygen.c", __func__, 3682, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Must specify key id (-I) when certifying");
  for (i = 0; i < nopts; i++)
   add_cert_option(opts[i]);
  do_ca_sign(pw, ca_key_path, prefer_agent,
      cert_serial, cert_serial_autoinc, argc, argv);
 }
 if (show_cert)
  do_show_cert(pw);
 if (delete_host || hash_hosts || find_host) {
  do_known_hosts(pw, rr_hostname, find_host,
      delete_host, hash_hosts);
 }
 if (pkcs11provider != 
                      ((void *)0)
                          )
  do_download(pw);
 if (download_sk) {
  for (i = 0; i < nopts; i++) {
   if (strncasecmp(opts[i], "device=", 7) == 0) {
    sk_device = xstrdup(opts[i] + 7);
   } else {
    sshfatal("ssh-keygen.c", __func__, 3701, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Option \"%s\" is unsupported for " "FIDO authenticator download", opts[i])
                                               ;
   }
  }
  return do_download_sk(sk_provider, sk_device);
 }
 if (print_fingerprint || print_bubblebabble)
  do_fingerprint(pw);
 if (change_passphrase)
  do_change_passphrase(pw);
 if (change_comment)
  do_change_comment(pw, identity_comment);

 if (convert_to)
  do_convert_to(pw);
 if (convert_from)
  do_convert_from(pw);




 if (print_public)
  do_print_public(pw);
 if (rr_hostname != 
                   ((void *)0)
                       ) {
  unsigned int n = 0;

  if (have_identity) {
   n = do_print_resource_record(pw, identity_file,
       rr_hostname, print_generic);
   if (n == 0)
    sshfatal("ssh-keygen.c", __func__, 3731, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s: %s", identity_file, strerror(
   (*__errno_location ())
   ));
   exit(0);
  } else {

   n += do_print_resource_record(pw,
       "/usr/local/etc" "/ssh_host_rsa_key", rr_hostname,
       print_generic);
   n += do_print_resource_record(pw,
       "/usr/local/etc" "/ssh_host_dsa_key", rr_hostname,
       print_generic);
   n += do_print_resource_record(pw,
       "/usr/local/etc" "/ssh_host_ecdsa_key", rr_hostname,
       print_generic);
   n += do_print_resource_record(pw,
       "/usr/local/etc" "/ssh_host_ed25519_key", rr_hostname,
       print_generic);
   n += do_print_resource_record(pw,
       "/usr/local/etc" "/ssh_host_xmss_key", rr_hostname,
       print_generic);
   if (n == 0)
    sshfatal("ssh-keygen.c", __func__, 3751, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "no keys found.");
   exit(0);
  }
 }

 if (do_gen_candidates || do_screen_candidates) {
  if (argc <= 0)
   sshfatal("ssh-keygen.c", __func__, 3758, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "No output file specified");
  else if (argc > 1)
   sshfatal("ssh-keygen.c", __func__, 3760, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Too many output files specified");
 }
 if (do_gen_candidates) {
  do_moduli_gen(argv[0], opts, nopts);
  return 0;
 }
 if (do_screen_candidates) {
  do_moduli_screen(argv[0], opts, nopts);
  return 0;
 }

 if (gen_all_hostkeys) {
  do_gen_all_hostkeys(pw);
  return (0);
 }

 if (key_type_name == 
                     ((void *)0)
                         )
  key_type_name = "rsa";

 type = sshkey_type_from_name(key_type_name);
 type_bits_valid(type, key_type_name, &bits);

 if (!quiet)
  printf("Generating public/private %s key pair.\n",
      key_type_name);
 switch (type) {
 case KEY_ECDSA_SK:
 case KEY_ED25519_SK:
  for (i = 0; i < nopts; i++) {
   if (strcasecmp(opts[i], "no-touch-required") == 0) {
    sk_flags &= ~0x01;
   } else if (strcasecmp(opts[i], "verify-required") == 0) {
    sk_flags |= 0x04;
   } else if (strcasecmp(opts[i], "resident") == 0) {
    sk_flags |= 0x20;
   } else if (strncasecmp(opts[i], "device=", 7) == 0) {
    sk_device = xstrdup(opts[i] + 7);
   } else if (strncasecmp(opts[i], "user=", 5) == 0) {
    sk_user = xstrdup(opts[i] + 5);
   } else if (strncasecmp(opts[i], "challenge=", 10) == 0) {
    if ((r = sshbuf_load_file(opts[i] + 10,
        &challenge)) != 0) {
     sshfatal("ssh-keygen.c", __func__, 3802, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Unable to load FIDO " "enrollment challenge \"%s\"", opts[i] + 10)

                      ;
    }
   } else if (strncasecmp(opts[i],
       "write-attestation=", 18) == 0) {
    sk_attestation_path = opts[i] + 18;
   } else if (strncasecmp(opts[i],
       "application=", 12) == 0) {
    sk_application = xstrdup(opts[i] + 12);
    if (strncmp(sk_application, "ssh:", 4) != 0) {
     sshfatal("ssh-keygen.c", __func__, 3813, 0, SYSLOG_LEVEL_FATAL, 
    ((void *)0)
    , "FIDO application string must " "begin with \"ssh:\"")
                               ;
    }
   } else {
    sshfatal("ssh-keygen.c", __func__, 3817, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Option \"%s\" is unsupported for " "FIDO authenticator enrollment", opts[i])
                                                 ;
   }
  }
  if ((attest = sshbuf_new()) == 
                                ((void *)0)
                                    )
   sshfatal("ssh-keygen.c", __func__, 3822, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshbuf_new failed");
  r = 0;
  for (i = 0 ;;) {
   if (!quiet) {
    printf("You may need to touch your "
        "authenticator%s to authorize key "
        "generation.\n",
        r == 0 ? "" : " again");
   }
   fflush(
         stdout
               );
   r = sshsk_enroll(type, sk_provider, sk_device,
       sk_application == 
                        ((void *)0) 
                             ? "ssh:" : sk_application,
       sk_user, sk_flags, passphrase, challenge,
       &private, attest);
   if (r == 0)
    break;
   if (r == -44 &&
       (sk_flags & 0x20) != 0 &&
       (sk_flags & 0x10) == 0 &&
       confirm_sk_overwrite(sk_application, sk_user)) {
    sk_flags |= 0x10;
    continue;
   }
   if (r != -43)
    sshfatal("ssh-keygen.c", __func__, 3846, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Key enrollment failed");
   else if (passphrase != 
                         ((void *)0)
                             ) {
    sshlog("ssh-keygen.c", __func__, 3848, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "PIN incorrect");
    freezero(passphrase, strlen(passphrase));
    passphrase = 
                ((void *)0)
                    ;
   }
   if (++i >= 3)
    sshfatal("ssh-keygen.c", __func__, 3853, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "Too many incorrect PINs");
   passphrase = read_passphrase("Enter PIN for "
       "authenticator: ", 0x0002);
  }
  if (passphrase != 
                   ((void *)0)
                       ) {
   freezero(passphrase, strlen(passphrase));
   passphrase = 
               ((void *)0)
                   ;
  }
  break;
 default:
  if ((r = sshkey_generate(type, bits, &private)) != 0)
   sshfatal("ssh-keygen.c", __func__, 3864, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshkey_generate failed");
  break;
 }
 if ((r = sshkey_from_private(private, &public)) != 0)
  sshfatal("ssh-keygen.c", __func__, 3868, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshkey_from_private");

 if (!have_identity)
  ask_filename(pw, "Enter file in which to save the key");


 hostfile_create_user_ssh_dir(identity_file, !quiet);


 if (!confirm_overwrite(identity_file))
  exit(1);


 passphrase = private_key_passphrase();
 if (identity_comment) {
  strlcpy(comment, identity_comment, sizeof(comment));
 } else {

  snprintf(comment, sizeof comment, "%s@%s", pw->pw_name, hostname);
 }


 if ((r = sshkey_save_private(private, identity_file, passphrase,
     comment, private_key_format, openssh_format_cipher, rounds)) != 0) {
  sshlog("ssh-keygen.c", __func__, 3892, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Saving key \"%s\" failed", identity_file);
  freezero(passphrase, strlen(passphrase));
  exit(1);
 }
 freezero(passphrase, strlen(passphrase));
 sshkey_free(private);

 if (!quiet) {
  printf("Your identification has been saved in %s\n",
      identity_file);
 }

 strlcat(identity_file, ".pub", sizeof(identity_file));
 if ((r = sshkey_save_public(public, identity_file, comment)) != 0)
  sshfatal("ssh-keygen.c", __func__, 3906, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Unable to save public key to %s", identity_file);

 if (!quiet) {
  fp = sshkey_fingerprint(public, fingerprint_hash,
      SSH_FP_DEFAULT);
  ra = sshkey_fingerprint(public, fingerprint_hash,
      SSH_FP_RANDOMART);
  if (fp == 
           ((void *)0) 
                || ra == 
                         ((void *)0)
                             )
   sshfatal("ssh-keygen.c", __func__, 3914, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshkey_fingerprint failed");
  printf("Your public key has been saved in %s\n",
      identity_file);
  printf("The key fingerprint is:\n");
  printf("%s %s\n", fp, comment);
  printf("The key's randomart image is:\n");
  printf("%s\n", ra);
  free(ra);
  free(fp);
 }

 if (sk_attestation_path != 
                           ((void *)0)
                               )
  save_attestation(attest, sk_attestation_path);

 sshbuf_free(attest);
 sshkey_free(public);

 exit(0);
}
