











































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
struct bitmap;


struct bitmap *bitmap_new(void);


void bitmap_free(struct bitmap *b);


void bitmap_zero(struct bitmap *b);


int bitmap_test_bit(struct bitmap *b, u_int n);


int bitmap_set_bit(struct bitmap *b, u_int n);


void bitmap_clear_bit(struct bitmap *b, u_int n);


size_t bitmap_nbits(struct bitmap *b);


size_t bitmap_nbytes(struct bitmap *b);


int bitmap_to_string(struct bitmap *b, void *p, size_t l);


int bitmap_from_string(struct bitmap *b, const void *p, size_t l);
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
struct revoked_serial {
 u_int64_t lo, hi;
 struct { struct revoked_serial *rbe_left; struct revoked_serial *rbe_right; struct revoked_serial *rbe_parent; int rbe_color; } tree_entry;
};
static int serial_cmp(struct revoked_serial *a, struct revoked_serial *b);
struct revoked_serial_tree { struct revoked_serial *rbh_root; };
__attribute__((__unused__)) static void revoked_serial_tree_RB_INSERT_COLOR(struct revoked_serial_tree *head, struct revoked_serial *elm) { struct revoked_serial *parent, *gparent, *tmp; while ((parent = (elm)->tree_entry.rbe_parent) && (parent)->tree_entry.rbe_color == 1) { gparent = (parent)->tree_entry.rbe_parent; if (parent == (gparent)->tree_entry.rbe_left) { tmp = (gparent)->tree_entry.rbe_right; if (tmp && (tmp)->tree_entry.rbe_color == 1) { (tmp)->tree_entry.rbe_color = 0; do { (parent)->tree_entry.rbe_color = 0; (gparent)->tree_entry.rbe_color = 1; } while (0); elm = gparent; continue; } if ((parent)->tree_entry.rbe_right == elm) { do { (tmp) = (parent)->tree_entry.rbe_right; if (((parent)->tree_entry.rbe_right = (tmp)->tree_entry.rbe_left)) { ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (parent)->tree_entry.rbe_parent)) { if ((parent) == ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_left = (parent); (parent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); tmp = parent; parent = elm; elm = tmp; } do { (parent)->tree_entry.rbe_color = 0; (gparent)->tree_entry.rbe_color = 1; } while (0); do { (tmp) = (gparent)->tree_entry.rbe_left; if (((gparent)->tree_entry.rbe_left = (tmp)->tree_entry.rbe_right)) { ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_parent = (gparent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (gparent)->tree_entry.rbe_parent)) { if ((gparent) == ((gparent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((gparent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((gparent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_right = (gparent); (gparent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); } else { tmp = (gparent)->tree_entry.rbe_left; if (tmp && (tmp)->tree_entry.rbe_color == 1) { (tmp)->tree_entry.rbe_color = 0; do { (parent)->tree_entry.rbe_color = 0; (gparent)->tree_entry.rbe_color = 1; } while (0); elm = gparent; continue; } if ((parent)->tree_entry.rbe_left == elm) { do { (tmp) = (parent)->tree_entry.rbe_left; if (((parent)->tree_entry.rbe_left = (tmp)->tree_entry.rbe_right)) { ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (parent)->tree_entry.rbe_parent)) { if ((parent) == ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_right = (parent); (parent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); tmp = parent; parent = elm; elm = tmp; } do { (parent)->tree_entry.rbe_color = 0; (gparent)->tree_entry.rbe_color = 1; } while (0); do { (tmp) = (gparent)->tree_entry.rbe_right; if (((gparent)->tree_entry.rbe_right = (tmp)->tree_entry.rbe_left)) { ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_parent = (gparent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (gparent)->tree_entry.rbe_parent)) { if ((gparent) == ((gparent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((gparent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((gparent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_left = (gparent); (gparent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); } } (head->rbh_root)->tree_entry.rbe_color = 0; } __attribute__((__unused__)) static void revoked_serial_tree_RB_REMOVE_COLOR(struct revoked_serial_tree *head, struct revoked_serial *parent, struct revoked_serial *elm) { struct revoked_serial *tmp; while ((elm == 
((void *)0) 
|| (elm)->tree_entry.rbe_color == 0) && elm != (head)->rbh_root) { if ((parent)->tree_entry.rbe_left == elm) { tmp = (parent)->tree_entry.rbe_right; if ((tmp)->tree_entry.rbe_color == 1) { do { (tmp)->tree_entry.rbe_color = 0; (parent)->tree_entry.rbe_color = 1; } while (0); do { (tmp) = (parent)->tree_entry.rbe_right; if (((parent)->tree_entry.rbe_right = (tmp)->tree_entry.rbe_left)) { ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (parent)->tree_entry.rbe_parent)) { if ((parent) == ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_left = (parent); (parent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); tmp = (parent)->tree_entry.rbe_right; } if (((tmp)->tree_entry.rbe_left == 
((void *)0) 
|| ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_color == 0) && ((tmp)->tree_entry.rbe_right == 
((void *)0) 
|| ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_color == 0)) { (tmp)->tree_entry.rbe_color = 1; elm = parent; parent = (elm)->tree_entry.rbe_parent; } else { if ((tmp)->tree_entry.rbe_right == 
((void *)0) 
|| ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_color == 0) { struct revoked_serial *oleft; if ((oleft = (tmp)->tree_entry.rbe_left)) (oleft)->tree_entry.rbe_color = 0; (tmp)->tree_entry.rbe_color = 1; do { (oleft) = (tmp)->tree_entry.rbe_left; if (((tmp)->tree_entry.rbe_left = (oleft)->tree_entry.rbe_right)) { ((oleft)->tree_entry.rbe_right)->tree_entry.rbe_parent = (tmp); } do {} while (0); if (((oleft)->tree_entry.rbe_parent = (tmp)->tree_entry.rbe_parent)) { if ((tmp) == ((tmp)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((tmp)->tree_entry.rbe_parent)->tree_entry.rbe_left = (oleft); else ((tmp)->tree_entry.rbe_parent)->tree_entry.rbe_right = (oleft); } else (head)->rbh_root = (oleft); (oleft)->tree_entry.rbe_right = (tmp); (tmp)->tree_entry.rbe_parent = (oleft); do {} while (0); if (((oleft)->tree_entry.rbe_parent)) do {} while (0); } while (0); tmp = (parent)->tree_entry.rbe_right; } (tmp)->tree_entry.rbe_color = (parent)->tree_entry.rbe_color; (parent)->tree_entry.rbe_color = 0; if ((tmp)->tree_entry.rbe_right) ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_color = 0; do { (tmp) = (parent)->tree_entry.rbe_right; if (((parent)->tree_entry.rbe_right = (tmp)->tree_entry.rbe_left)) { ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (parent)->tree_entry.rbe_parent)) { if ((parent) == ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_left = (parent); (parent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); elm = (head)->rbh_root; break; } } else { tmp = (parent)->tree_entry.rbe_left; if ((tmp)->tree_entry.rbe_color == 1) { do { (tmp)->tree_entry.rbe_color = 0; (parent)->tree_entry.rbe_color = 1; } while (0); do { (tmp) = (parent)->tree_entry.rbe_left; if (((parent)->tree_entry.rbe_left = (tmp)->tree_entry.rbe_right)) { ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (parent)->tree_entry.rbe_parent)) { if ((parent) == ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_right = (parent); (parent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); tmp = (parent)->tree_entry.rbe_left; } if (((tmp)->tree_entry.rbe_left == 
((void *)0) 
|| ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_color == 0) && ((tmp)->tree_entry.rbe_right == 
((void *)0) 
|| ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_color == 0)) { (tmp)->tree_entry.rbe_color = 1; elm = parent; parent = (elm)->tree_entry.rbe_parent; } else { if ((tmp)->tree_entry.rbe_left == 
((void *)0) 
|| ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_color == 0) { struct revoked_serial *oright; if ((oright = (tmp)->tree_entry.rbe_right)) (oright)->tree_entry.rbe_color = 0; (tmp)->tree_entry.rbe_color = 1; do { (oright) = (tmp)->tree_entry.rbe_right; if (((tmp)->tree_entry.rbe_right = (oright)->tree_entry.rbe_left)) { ((oright)->tree_entry.rbe_left)->tree_entry.rbe_parent = (tmp); } do {} while (0); if (((oright)->tree_entry.rbe_parent = (tmp)->tree_entry.rbe_parent)) { if ((tmp) == ((tmp)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((tmp)->tree_entry.rbe_parent)->tree_entry.rbe_left = (oright); else ((tmp)->tree_entry.rbe_parent)->tree_entry.rbe_right = (oright); } else (head)->rbh_root = (oright); (oright)->tree_entry.rbe_left = (tmp); (tmp)->tree_entry.rbe_parent = (oright); do {} while (0); if (((oright)->tree_entry.rbe_parent)) do {} while (0); } while (0); tmp = (parent)->tree_entry.rbe_left; } (tmp)->tree_entry.rbe_color = (parent)->tree_entry.rbe_color; (parent)->tree_entry.rbe_color = 0; if ((tmp)->tree_entry.rbe_left) ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_color = 0; do { (tmp) = (parent)->tree_entry.rbe_left; if (((parent)->tree_entry.rbe_left = (tmp)->tree_entry.rbe_right)) { ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (parent)->tree_entry.rbe_parent)) { if ((parent) == ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_right = (parent); (parent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); elm = (head)->rbh_root; break; } } } if (elm) (elm)->tree_entry.rbe_color = 0; } __attribute__((__unused__)) static struct revoked_serial * revoked_serial_tree_RB_REMOVE(struct revoked_serial_tree *head, struct revoked_serial *elm) { struct revoked_serial *child, *parent, *old = elm; int color; if ((elm)->tree_entry.rbe_left == 
((void *)0)
) child = (elm)->tree_entry.rbe_right; else if ((elm)->tree_entry.rbe_right == 
((void *)0)
) child = (elm)->tree_entry.rbe_left; else { struct revoked_serial *left; elm = (elm)->tree_entry.rbe_right; while ((left = (elm)->tree_entry.rbe_left)) elm = left; child = (elm)->tree_entry.rbe_right; parent = (elm)->tree_entry.rbe_parent; color = (elm)->tree_entry.rbe_color; if (child) (child)->tree_entry.rbe_parent = parent; if (parent) { if ((parent)->tree_entry.rbe_left == elm) (parent)->tree_entry.rbe_left = child; else (parent)->tree_entry.rbe_right = child; do {} while (0); } else (head)->rbh_root = child; if ((elm)->tree_entry.rbe_parent == old) parent = elm; (elm)->tree_entry = (old)->tree_entry; if ((old)->tree_entry.rbe_parent) { if (((old)->tree_entry.rbe_parent)->tree_entry.rbe_left == old) ((old)->tree_entry.rbe_parent)->tree_entry.rbe_left = elm; else ((old)->tree_entry.rbe_parent)->tree_entry.rbe_right = elm; do {} while (0); } else (head)->rbh_root = elm; ((old)->tree_entry.rbe_left)->tree_entry.rbe_parent = elm; if ((old)->tree_entry.rbe_right) ((old)->tree_entry.rbe_right)->tree_entry.rbe_parent = elm; if (parent) { left = parent; do { do {} while (0); } while ((left = (left)->tree_entry.rbe_parent)); } goto color; } parent = (elm)->tree_entry.rbe_parent; color = (elm)->tree_entry.rbe_color; if (child) (child)->tree_entry.rbe_parent = parent; if (parent) { if ((parent)->tree_entry.rbe_left == elm) (parent)->tree_entry.rbe_left = child; else (parent)->tree_entry.rbe_right = child; do {} while (0); } else (head)->rbh_root = child; color: if (color == 0) revoked_serial_tree_RB_REMOVE_COLOR(head, parent, child); return (old); } __attribute__((__unused__)) static struct revoked_serial * revoked_serial_tree_RB_INSERT(struct revoked_serial_tree *head, struct revoked_serial *elm) { struct revoked_serial *tmp; struct revoked_serial *parent = 
((void *)0)
; int comp = 0; tmp = (head)->rbh_root; while (tmp) { parent = tmp; comp = (serial_cmp)(elm, parent); if (comp < 0) tmp = (tmp)->tree_entry.rbe_left; else if (comp > 0) tmp = (tmp)->tree_entry.rbe_right; else return (tmp); } do { (elm)->tree_entry.rbe_parent = parent; (elm)->tree_entry.rbe_left = (elm)->tree_entry.rbe_right = 
((void *)0)
; (elm)->tree_entry.rbe_color = 1; } while (0); if (parent != 
((void *)0)
) { if (comp < 0) (parent)->tree_entry.rbe_left = elm; else (parent)->tree_entry.rbe_right = elm; do {} while (0); } else (head)->rbh_root = elm; revoked_serial_tree_RB_INSERT_COLOR(head, elm); return (
((void *)0)
); } __attribute__((__unused__)) static struct revoked_serial * revoked_serial_tree_RB_FIND(struct revoked_serial_tree *head, struct revoked_serial *elm) { struct revoked_serial *tmp = (head)->rbh_root; int comp; while (tmp) { comp = serial_cmp(elm, tmp); if (comp < 0) tmp = (tmp)->tree_entry.rbe_left; else if (comp > 0) tmp = (tmp)->tree_entry.rbe_right; else return (tmp); } return (
((void *)0)
); } __attribute__((__unused__)) static struct revoked_serial * revoked_serial_tree_RB_NFIND(struct revoked_serial_tree *head, struct revoked_serial *elm) { struct revoked_serial *tmp = (head)->rbh_root; struct revoked_serial *res = 
((void *)0)
; int comp; while (tmp) { comp = serial_cmp(elm, tmp); if (comp < 0) { res = tmp; tmp = (tmp)->tree_entry.rbe_left; } else if (comp > 0) tmp = (tmp)->tree_entry.rbe_right; else return (tmp); } return (res); } __attribute__((__unused__)) static struct revoked_serial * revoked_serial_tree_RB_NEXT(struct revoked_serial *elm) { if ((elm)->tree_entry.rbe_right) { elm = (elm)->tree_entry.rbe_right; while ((elm)->tree_entry.rbe_left) elm = (elm)->tree_entry.rbe_left; } else { if ((elm)->tree_entry.rbe_parent && (elm == ((elm)->tree_entry.rbe_parent)->tree_entry.rbe_left)) elm = (elm)->tree_entry.rbe_parent; else { while ((elm)->tree_entry.rbe_parent && (elm == ((elm)->tree_entry.rbe_parent)->tree_entry.rbe_right)) elm = (elm)->tree_entry.rbe_parent; elm = (elm)->tree_entry.rbe_parent; } } return (elm); } __attribute__((__unused__)) static struct revoked_serial * revoked_serial_tree_RB_PREV(struct revoked_serial *elm) { if ((elm)->tree_entry.rbe_left) { elm = (elm)->tree_entry.rbe_left; while ((elm)->tree_entry.rbe_right) elm = (elm)->tree_entry.rbe_right; } else { if ((elm)->tree_entry.rbe_parent && (elm == ((elm)->tree_entry.rbe_parent)->tree_entry.rbe_right)) elm = (elm)->tree_entry.rbe_parent; else { while ((elm)->tree_entry.rbe_parent && (elm == ((elm)->tree_entry.rbe_parent)->tree_entry.rbe_left)) elm = (elm)->tree_entry.rbe_parent; elm = (elm)->tree_entry.rbe_parent; } } return (elm); } __attribute__((__unused__)) static struct revoked_serial * revoked_serial_tree_RB_MINMAX(struct revoked_serial_tree *head, int val) { struct revoked_serial *tmp = (head)->rbh_root; struct revoked_serial *parent = 
((void *)0)
; while (tmp) { parent = tmp; if (val < 0) tmp = (tmp)->tree_entry.rbe_left; else tmp = (tmp)->tree_entry.rbe_right; } return (parent); }


struct revoked_key_id {
 char *key_id;
 struct { struct revoked_key_id *rbe_left; struct revoked_key_id *rbe_right; struct revoked_key_id *rbe_parent; int rbe_color; } tree_entry;
};
static int key_id_cmp(struct revoked_key_id *a, struct revoked_key_id *b);
struct revoked_key_id_tree { struct revoked_key_id *rbh_root; };
__attribute__((__unused__)) static void revoked_key_id_tree_RB_INSERT_COLOR(struct revoked_key_id_tree *head, struct revoked_key_id *elm) { struct revoked_key_id *parent, *gparent, *tmp; while ((parent = (elm)->tree_entry.rbe_parent) && (parent)->tree_entry.rbe_color == 1) { gparent = (parent)->tree_entry.rbe_parent; if (parent == (gparent)->tree_entry.rbe_left) { tmp = (gparent)->tree_entry.rbe_right; if (tmp && (tmp)->tree_entry.rbe_color == 1) { (tmp)->tree_entry.rbe_color = 0; do { (parent)->tree_entry.rbe_color = 0; (gparent)->tree_entry.rbe_color = 1; } while (0); elm = gparent; continue; } if ((parent)->tree_entry.rbe_right == elm) { do { (tmp) = (parent)->tree_entry.rbe_right; if (((parent)->tree_entry.rbe_right = (tmp)->tree_entry.rbe_left)) { ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (parent)->tree_entry.rbe_parent)) { if ((parent) == ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_left = (parent); (parent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); tmp = parent; parent = elm; elm = tmp; } do { (parent)->tree_entry.rbe_color = 0; (gparent)->tree_entry.rbe_color = 1; } while (0); do { (tmp) = (gparent)->tree_entry.rbe_left; if (((gparent)->tree_entry.rbe_left = (tmp)->tree_entry.rbe_right)) { ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_parent = (gparent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (gparent)->tree_entry.rbe_parent)) { if ((gparent) == ((gparent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((gparent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((gparent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_right = (gparent); (gparent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); } else { tmp = (gparent)->tree_entry.rbe_left; if (tmp && (tmp)->tree_entry.rbe_color == 1) { (tmp)->tree_entry.rbe_color = 0; do { (parent)->tree_entry.rbe_color = 0; (gparent)->tree_entry.rbe_color = 1; } while (0); elm = gparent; continue; } if ((parent)->tree_entry.rbe_left == elm) { do { (tmp) = (parent)->tree_entry.rbe_left; if (((parent)->tree_entry.rbe_left = (tmp)->tree_entry.rbe_right)) { ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (parent)->tree_entry.rbe_parent)) { if ((parent) == ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_right = (parent); (parent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); tmp = parent; parent = elm; elm = tmp; } do { (parent)->tree_entry.rbe_color = 0; (gparent)->tree_entry.rbe_color = 1; } while (0); do { (tmp) = (gparent)->tree_entry.rbe_right; if (((gparent)->tree_entry.rbe_right = (tmp)->tree_entry.rbe_left)) { ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_parent = (gparent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (gparent)->tree_entry.rbe_parent)) { if ((gparent) == ((gparent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((gparent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((gparent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_left = (gparent); (gparent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); } } (head->rbh_root)->tree_entry.rbe_color = 0; } __attribute__((__unused__)) static void revoked_key_id_tree_RB_REMOVE_COLOR(struct revoked_key_id_tree *head, struct revoked_key_id *parent, struct revoked_key_id *elm) { struct revoked_key_id *tmp; while ((elm == 
((void *)0) 
|| (elm)->tree_entry.rbe_color == 0) && elm != (head)->rbh_root) { if ((parent)->tree_entry.rbe_left == elm) { tmp = (parent)->tree_entry.rbe_right; if ((tmp)->tree_entry.rbe_color == 1) { do { (tmp)->tree_entry.rbe_color = 0; (parent)->tree_entry.rbe_color = 1; } while (0); do { (tmp) = (parent)->tree_entry.rbe_right; if (((parent)->tree_entry.rbe_right = (tmp)->tree_entry.rbe_left)) { ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (parent)->tree_entry.rbe_parent)) { if ((parent) == ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_left = (parent); (parent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); tmp = (parent)->tree_entry.rbe_right; } if (((tmp)->tree_entry.rbe_left == 
((void *)0) 
|| ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_color == 0) && ((tmp)->tree_entry.rbe_right == 
((void *)0) 
|| ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_color == 0)) { (tmp)->tree_entry.rbe_color = 1; elm = parent; parent = (elm)->tree_entry.rbe_parent; } else { if ((tmp)->tree_entry.rbe_right == 
((void *)0) 
|| ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_color == 0) { struct revoked_key_id *oleft; if ((oleft = (tmp)->tree_entry.rbe_left)) (oleft)->tree_entry.rbe_color = 0; (tmp)->tree_entry.rbe_color = 1; do { (oleft) = (tmp)->tree_entry.rbe_left; if (((tmp)->tree_entry.rbe_left = (oleft)->tree_entry.rbe_right)) { ((oleft)->tree_entry.rbe_right)->tree_entry.rbe_parent = (tmp); } do {} while (0); if (((oleft)->tree_entry.rbe_parent = (tmp)->tree_entry.rbe_parent)) { if ((tmp) == ((tmp)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((tmp)->tree_entry.rbe_parent)->tree_entry.rbe_left = (oleft); else ((tmp)->tree_entry.rbe_parent)->tree_entry.rbe_right = (oleft); } else (head)->rbh_root = (oleft); (oleft)->tree_entry.rbe_right = (tmp); (tmp)->tree_entry.rbe_parent = (oleft); do {} while (0); if (((oleft)->tree_entry.rbe_parent)) do {} while (0); } while (0); tmp = (parent)->tree_entry.rbe_right; } (tmp)->tree_entry.rbe_color = (parent)->tree_entry.rbe_color; (parent)->tree_entry.rbe_color = 0; if ((tmp)->tree_entry.rbe_right) ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_color = 0; do { (tmp) = (parent)->tree_entry.rbe_right; if (((parent)->tree_entry.rbe_right = (tmp)->tree_entry.rbe_left)) { ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (parent)->tree_entry.rbe_parent)) { if ((parent) == ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_left = (parent); (parent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); elm = (head)->rbh_root; break; } } else { tmp = (parent)->tree_entry.rbe_left; if ((tmp)->tree_entry.rbe_color == 1) { do { (tmp)->tree_entry.rbe_color = 0; (parent)->tree_entry.rbe_color = 1; } while (0); do { (tmp) = (parent)->tree_entry.rbe_left; if (((parent)->tree_entry.rbe_left = (tmp)->tree_entry.rbe_right)) { ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (parent)->tree_entry.rbe_parent)) { if ((parent) == ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_right = (parent); (parent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); tmp = (parent)->tree_entry.rbe_left; } if (((tmp)->tree_entry.rbe_left == 
((void *)0) 
|| ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_color == 0) && ((tmp)->tree_entry.rbe_right == 
((void *)0) 
|| ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_color == 0)) { (tmp)->tree_entry.rbe_color = 1; elm = parent; parent = (elm)->tree_entry.rbe_parent; } else { if ((tmp)->tree_entry.rbe_left == 
((void *)0) 
|| ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_color == 0) { struct revoked_key_id *oright; if ((oright = (tmp)->tree_entry.rbe_right)) (oright)->tree_entry.rbe_color = 0; (tmp)->tree_entry.rbe_color = 1; do { (oright) = (tmp)->tree_entry.rbe_right; if (((tmp)->tree_entry.rbe_right = (oright)->tree_entry.rbe_left)) { ((oright)->tree_entry.rbe_left)->tree_entry.rbe_parent = (tmp); } do {} while (0); if (((oright)->tree_entry.rbe_parent = (tmp)->tree_entry.rbe_parent)) { if ((tmp) == ((tmp)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((tmp)->tree_entry.rbe_parent)->tree_entry.rbe_left = (oright); else ((tmp)->tree_entry.rbe_parent)->tree_entry.rbe_right = (oright); } else (head)->rbh_root = (oright); (oright)->tree_entry.rbe_left = (tmp); (tmp)->tree_entry.rbe_parent = (oright); do {} while (0); if (((oright)->tree_entry.rbe_parent)) do {} while (0); } while (0); tmp = (parent)->tree_entry.rbe_left; } (tmp)->tree_entry.rbe_color = (parent)->tree_entry.rbe_color; (parent)->tree_entry.rbe_color = 0; if ((tmp)->tree_entry.rbe_left) ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_color = 0; do { (tmp) = (parent)->tree_entry.rbe_left; if (((parent)->tree_entry.rbe_left = (tmp)->tree_entry.rbe_right)) { ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (parent)->tree_entry.rbe_parent)) { if ((parent) == ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_right = (parent); (parent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); elm = (head)->rbh_root; break; } } } if (elm) (elm)->tree_entry.rbe_color = 0; } __attribute__((__unused__)) static struct revoked_key_id * revoked_key_id_tree_RB_REMOVE(struct revoked_key_id_tree *head, struct revoked_key_id *elm) { struct revoked_key_id *child, *parent, *old = elm; int color; if ((elm)->tree_entry.rbe_left == 
((void *)0)
) child = (elm)->tree_entry.rbe_right; else if ((elm)->tree_entry.rbe_right == 
((void *)0)
) child = (elm)->tree_entry.rbe_left; else { struct revoked_key_id *left; elm = (elm)->tree_entry.rbe_right; while ((left = (elm)->tree_entry.rbe_left)) elm = left; child = (elm)->tree_entry.rbe_right; parent = (elm)->tree_entry.rbe_parent; color = (elm)->tree_entry.rbe_color; if (child) (child)->tree_entry.rbe_parent = parent; if (parent) { if ((parent)->tree_entry.rbe_left == elm) (parent)->tree_entry.rbe_left = child; else (parent)->tree_entry.rbe_right = child; do {} while (0); } else (head)->rbh_root = child; if ((elm)->tree_entry.rbe_parent == old) parent = elm; (elm)->tree_entry = (old)->tree_entry; if ((old)->tree_entry.rbe_parent) { if (((old)->tree_entry.rbe_parent)->tree_entry.rbe_left == old) ((old)->tree_entry.rbe_parent)->tree_entry.rbe_left = elm; else ((old)->tree_entry.rbe_parent)->tree_entry.rbe_right = elm; do {} while (0); } else (head)->rbh_root = elm; ((old)->tree_entry.rbe_left)->tree_entry.rbe_parent = elm; if ((old)->tree_entry.rbe_right) ((old)->tree_entry.rbe_right)->tree_entry.rbe_parent = elm; if (parent) { left = parent; do { do {} while (0); } while ((left = (left)->tree_entry.rbe_parent)); } goto color; } parent = (elm)->tree_entry.rbe_parent; color = (elm)->tree_entry.rbe_color; if (child) (child)->tree_entry.rbe_parent = parent; if (parent) { if ((parent)->tree_entry.rbe_left == elm) (parent)->tree_entry.rbe_left = child; else (parent)->tree_entry.rbe_right = child; do {} while (0); } else (head)->rbh_root = child; color: if (color == 0) revoked_key_id_tree_RB_REMOVE_COLOR(head, parent, child); return (old); } __attribute__((__unused__)) static struct revoked_key_id * revoked_key_id_tree_RB_INSERT(struct revoked_key_id_tree *head, struct revoked_key_id *elm) { struct revoked_key_id *tmp; struct revoked_key_id *parent = 
((void *)0)
; int comp = 0; tmp = (head)->rbh_root; while (tmp) { parent = tmp; comp = (key_id_cmp)(elm, parent); if (comp < 0) tmp = (tmp)->tree_entry.rbe_left; else if (comp > 0) tmp = (tmp)->tree_entry.rbe_right; else return (tmp); } do { (elm)->tree_entry.rbe_parent = parent; (elm)->tree_entry.rbe_left = (elm)->tree_entry.rbe_right = 
((void *)0)
; (elm)->tree_entry.rbe_color = 1; } while (0); if (parent != 
((void *)0)
) { if (comp < 0) (parent)->tree_entry.rbe_left = elm; else (parent)->tree_entry.rbe_right = elm; do {} while (0); } else (head)->rbh_root = elm; revoked_key_id_tree_RB_INSERT_COLOR(head, elm); return (
((void *)0)
); } __attribute__((__unused__)) static struct revoked_key_id * revoked_key_id_tree_RB_FIND(struct revoked_key_id_tree *head, struct revoked_key_id *elm) { struct revoked_key_id *tmp = (head)->rbh_root; int comp; while (tmp) { comp = key_id_cmp(elm, tmp); if (comp < 0) tmp = (tmp)->tree_entry.rbe_left; else if (comp > 0) tmp = (tmp)->tree_entry.rbe_right; else return (tmp); } return (
((void *)0)
); } __attribute__((__unused__)) static struct revoked_key_id * revoked_key_id_tree_RB_NFIND(struct revoked_key_id_tree *head, struct revoked_key_id *elm) { struct revoked_key_id *tmp = (head)->rbh_root; struct revoked_key_id *res = 
((void *)0)
; int comp; while (tmp) { comp = key_id_cmp(elm, tmp); if (comp < 0) { res = tmp; tmp = (tmp)->tree_entry.rbe_left; } else if (comp > 0) tmp = (tmp)->tree_entry.rbe_right; else return (tmp); } return (res); } __attribute__((__unused__)) static struct revoked_key_id * revoked_key_id_tree_RB_NEXT(struct revoked_key_id *elm) { if ((elm)->tree_entry.rbe_right) { elm = (elm)->tree_entry.rbe_right; while ((elm)->tree_entry.rbe_left) elm = (elm)->tree_entry.rbe_left; } else { if ((elm)->tree_entry.rbe_parent && (elm == ((elm)->tree_entry.rbe_parent)->tree_entry.rbe_left)) elm = (elm)->tree_entry.rbe_parent; else { while ((elm)->tree_entry.rbe_parent && (elm == ((elm)->tree_entry.rbe_parent)->tree_entry.rbe_right)) elm = (elm)->tree_entry.rbe_parent; elm = (elm)->tree_entry.rbe_parent; } } return (elm); } __attribute__((__unused__)) static struct revoked_key_id * revoked_key_id_tree_RB_PREV(struct revoked_key_id *elm) { if ((elm)->tree_entry.rbe_left) { elm = (elm)->tree_entry.rbe_left; while ((elm)->tree_entry.rbe_right) elm = (elm)->tree_entry.rbe_right; } else { if ((elm)->tree_entry.rbe_parent && (elm == ((elm)->tree_entry.rbe_parent)->tree_entry.rbe_right)) elm = (elm)->tree_entry.rbe_parent; else { while ((elm)->tree_entry.rbe_parent && (elm == ((elm)->tree_entry.rbe_parent)->tree_entry.rbe_left)) elm = (elm)->tree_entry.rbe_parent; elm = (elm)->tree_entry.rbe_parent; } } return (elm); } __attribute__((__unused__)) static struct revoked_key_id * revoked_key_id_tree_RB_MINMAX(struct revoked_key_id_tree *head, int val) { struct revoked_key_id *tmp = (head)->rbh_root; struct revoked_key_id *parent = 
((void *)0)
; while (tmp) { parent = tmp; if (val < 0) tmp = (tmp)->tree_entry.rbe_left; else tmp = (tmp)->tree_entry.rbe_right; } return (parent); }


struct revoked_blob {
 u_char *blob;
 size_t len;
 struct { struct revoked_blob *rbe_left; struct revoked_blob *rbe_right; struct revoked_blob *rbe_parent; int rbe_color; } tree_entry;
};
static int blob_cmp(struct revoked_blob *a, struct revoked_blob *b);
struct revoked_blob_tree { struct revoked_blob *rbh_root; };
__attribute__((__unused__)) static void revoked_blob_tree_RB_INSERT_COLOR(struct revoked_blob_tree *head, struct revoked_blob *elm) { struct revoked_blob *parent, *gparent, *tmp; while ((parent = (elm)->tree_entry.rbe_parent) && (parent)->tree_entry.rbe_color == 1) { gparent = (parent)->tree_entry.rbe_parent; if (parent == (gparent)->tree_entry.rbe_left) { tmp = (gparent)->tree_entry.rbe_right; if (tmp && (tmp)->tree_entry.rbe_color == 1) { (tmp)->tree_entry.rbe_color = 0; do { (parent)->tree_entry.rbe_color = 0; (gparent)->tree_entry.rbe_color = 1; } while (0); elm = gparent; continue; } if ((parent)->tree_entry.rbe_right == elm) { do { (tmp) = (parent)->tree_entry.rbe_right; if (((parent)->tree_entry.rbe_right = (tmp)->tree_entry.rbe_left)) { ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (parent)->tree_entry.rbe_parent)) { if ((parent) == ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_left = (parent); (parent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); tmp = parent; parent = elm; elm = tmp; } do { (parent)->tree_entry.rbe_color = 0; (gparent)->tree_entry.rbe_color = 1; } while (0); do { (tmp) = (gparent)->tree_entry.rbe_left; if (((gparent)->tree_entry.rbe_left = (tmp)->tree_entry.rbe_right)) { ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_parent = (gparent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (gparent)->tree_entry.rbe_parent)) { if ((gparent) == ((gparent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((gparent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((gparent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_right = (gparent); (gparent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); } else { tmp = (gparent)->tree_entry.rbe_left; if (tmp && (tmp)->tree_entry.rbe_color == 1) { (tmp)->tree_entry.rbe_color = 0; do { (parent)->tree_entry.rbe_color = 0; (gparent)->tree_entry.rbe_color = 1; } while (0); elm = gparent; continue; } if ((parent)->tree_entry.rbe_left == elm) { do { (tmp) = (parent)->tree_entry.rbe_left; if (((parent)->tree_entry.rbe_left = (tmp)->tree_entry.rbe_right)) { ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (parent)->tree_entry.rbe_parent)) { if ((parent) == ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_right = (parent); (parent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); tmp = parent; parent = elm; elm = tmp; } do { (parent)->tree_entry.rbe_color = 0; (gparent)->tree_entry.rbe_color = 1; } while (0); do { (tmp) = (gparent)->tree_entry.rbe_right; if (((gparent)->tree_entry.rbe_right = (tmp)->tree_entry.rbe_left)) { ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_parent = (gparent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (gparent)->tree_entry.rbe_parent)) { if ((gparent) == ((gparent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((gparent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((gparent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_left = (gparent); (gparent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); } } (head->rbh_root)->tree_entry.rbe_color = 0; } __attribute__((__unused__)) static void revoked_blob_tree_RB_REMOVE_COLOR(struct revoked_blob_tree *head, struct revoked_blob *parent, struct revoked_blob *elm) { struct revoked_blob *tmp; while ((elm == 
((void *)0) 
|| (elm)->tree_entry.rbe_color == 0) && elm != (head)->rbh_root) { if ((parent)->tree_entry.rbe_left == elm) { tmp = (parent)->tree_entry.rbe_right; if ((tmp)->tree_entry.rbe_color == 1) { do { (tmp)->tree_entry.rbe_color = 0; (parent)->tree_entry.rbe_color = 1; } while (0); do { (tmp) = (parent)->tree_entry.rbe_right; if (((parent)->tree_entry.rbe_right = (tmp)->tree_entry.rbe_left)) { ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (parent)->tree_entry.rbe_parent)) { if ((parent) == ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_left = (parent); (parent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); tmp = (parent)->tree_entry.rbe_right; } if (((tmp)->tree_entry.rbe_left == 
((void *)0) 
|| ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_color == 0) && ((tmp)->tree_entry.rbe_right == 
((void *)0) 
|| ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_color == 0)) { (tmp)->tree_entry.rbe_color = 1; elm = parent; parent = (elm)->tree_entry.rbe_parent; } else { if ((tmp)->tree_entry.rbe_right == 
((void *)0) 
|| ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_color == 0) { struct revoked_blob *oleft; if ((oleft = (tmp)->tree_entry.rbe_left)) (oleft)->tree_entry.rbe_color = 0; (tmp)->tree_entry.rbe_color = 1; do { (oleft) = (tmp)->tree_entry.rbe_left; if (((tmp)->tree_entry.rbe_left = (oleft)->tree_entry.rbe_right)) { ((oleft)->tree_entry.rbe_right)->tree_entry.rbe_parent = (tmp); } do {} while (0); if (((oleft)->tree_entry.rbe_parent = (tmp)->tree_entry.rbe_parent)) { if ((tmp) == ((tmp)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((tmp)->tree_entry.rbe_parent)->tree_entry.rbe_left = (oleft); else ((tmp)->tree_entry.rbe_parent)->tree_entry.rbe_right = (oleft); } else (head)->rbh_root = (oleft); (oleft)->tree_entry.rbe_right = (tmp); (tmp)->tree_entry.rbe_parent = (oleft); do {} while (0); if (((oleft)->tree_entry.rbe_parent)) do {} while (0); } while (0); tmp = (parent)->tree_entry.rbe_right; } (tmp)->tree_entry.rbe_color = (parent)->tree_entry.rbe_color; (parent)->tree_entry.rbe_color = 0; if ((tmp)->tree_entry.rbe_right) ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_color = 0; do { (tmp) = (parent)->tree_entry.rbe_right; if (((parent)->tree_entry.rbe_right = (tmp)->tree_entry.rbe_left)) { ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (parent)->tree_entry.rbe_parent)) { if ((parent) == ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_left = (parent); (parent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); elm = (head)->rbh_root; break; } } else { tmp = (parent)->tree_entry.rbe_left; if ((tmp)->tree_entry.rbe_color == 1) { do { (tmp)->tree_entry.rbe_color = 0; (parent)->tree_entry.rbe_color = 1; } while (0); do { (tmp) = (parent)->tree_entry.rbe_left; if (((parent)->tree_entry.rbe_left = (tmp)->tree_entry.rbe_right)) { ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (parent)->tree_entry.rbe_parent)) { if ((parent) == ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_right = (parent); (parent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); tmp = (parent)->tree_entry.rbe_left; } if (((tmp)->tree_entry.rbe_left == 
((void *)0) 
|| ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_color == 0) && ((tmp)->tree_entry.rbe_right == 
((void *)0) 
|| ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_color == 0)) { (tmp)->tree_entry.rbe_color = 1; elm = parent; parent = (elm)->tree_entry.rbe_parent; } else { if ((tmp)->tree_entry.rbe_left == 
((void *)0) 
|| ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_color == 0) { struct revoked_blob *oright; if ((oright = (tmp)->tree_entry.rbe_right)) (oright)->tree_entry.rbe_color = 0; (tmp)->tree_entry.rbe_color = 1; do { (oright) = (tmp)->tree_entry.rbe_right; if (((tmp)->tree_entry.rbe_right = (oright)->tree_entry.rbe_left)) { ((oright)->tree_entry.rbe_left)->tree_entry.rbe_parent = (tmp); } do {} while (0); if (((oright)->tree_entry.rbe_parent = (tmp)->tree_entry.rbe_parent)) { if ((tmp) == ((tmp)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((tmp)->tree_entry.rbe_parent)->tree_entry.rbe_left = (oright); else ((tmp)->tree_entry.rbe_parent)->tree_entry.rbe_right = (oright); } else (head)->rbh_root = (oright); (oright)->tree_entry.rbe_left = (tmp); (tmp)->tree_entry.rbe_parent = (oright); do {} while (0); if (((oright)->tree_entry.rbe_parent)) do {} while (0); } while (0); tmp = (parent)->tree_entry.rbe_left; } (tmp)->tree_entry.rbe_color = (parent)->tree_entry.rbe_color; (parent)->tree_entry.rbe_color = 0; if ((tmp)->tree_entry.rbe_left) ((tmp)->tree_entry.rbe_left)->tree_entry.rbe_color = 0; do { (tmp) = (parent)->tree_entry.rbe_left; if (((parent)->tree_entry.rbe_left = (tmp)->tree_entry.rbe_right)) { ((tmp)->tree_entry.rbe_right)->tree_entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->tree_entry.rbe_parent = (parent)->tree_entry.rbe_parent)) { if ((parent) == ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left) ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_left = (tmp); else ((parent)->tree_entry.rbe_parent)->tree_entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->tree_entry.rbe_right = (parent); (parent)->tree_entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->tree_entry.rbe_parent)) do {} while (0); } while (0); elm = (head)->rbh_root; break; } } } if (elm) (elm)->tree_entry.rbe_color = 0; } __attribute__((__unused__)) static struct revoked_blob * revoked_blob_tree_RB_REMOVE(struct revoked_blob_tree *head, struct revoked_blob *elm) { struct revoked_blob *child, *parent, *old = elm; int color; if ((elm)->tree_entry.rbe_left == 
((void *)0)
) child = (elm)->tree_entry.rbe_right; else if ((elm)->tree_entry.rbe_right == 
((void *)0)
) child = (elm)->tree_entry.rbe_left; else { struct revoked_blob *left; elm = (elm)->tree_entry.rbe_right; while ((left = (elm)->tree_entry.rbe_left)) elm = left; child = (elm)->tree_entry.rbe_right; parent = (elm)->tree_entry.rbe_parent; color = (elm)->tree_entry.rbe_color; if (child) (child)->tree_entry.rbe_parent = parent; if (parent) { if ((parent)->tree_entry.rbe_left == elm) (parent)->tree_entry.rbe_left = child; else (parent)->tree_entry.rbe_right = child; do {} while (0); } else (head)->rbh_root = child; if ((elm)->tree_entry.rbe_parent == old) parent = elm; (elm)->tree_entry = (old)->tree_entry; if ((old)->tree_entry.rbe_parent) { if (((old)->tree_entry.rbe_parent)->tree_entry.rbe_left == old) ((old)->tree_entry.rbe_parent)->tree_entry.rbe_left = elm; else ((old)->tree_entry.rbe_parent)->tree_entry.rbe_right = elm; do {} while (0); } else (head)->rbh_root = elm; ((old)->tree_entry.rbe_left)->tree_entry.rbe_parent = elm; if ((old)->tree_entry.rbe_right) ((old)->tree_entry.rbe_right)->tree_entry.rbe_parent = elm; if (parent) { left = parent; do { do {} while (0); } while ((left = (left)->tree_entry.rbe_parent)); } goto color; } parent = (elm)->tree_entry.rbe_parent; color = (elm)->tree_entry.rbe_color; if (child) (child)->tree_entry.rbe_parent = parent; if (parent) { if ((parent)->tree_entry.rbe_left == elm) (parent)->tree_entry.rbe_left = child; else (parent)->tree_entry.rbe_right = child; do {} while (0); } else (head)->rbh_root = child; color: if (color == 0) revoked_blob_tree_RB_REMOVE_COLOR(head, parent, child); return (old); } __attribute__((__unused__)) static struct revoked_blob * revoked_blob_tree_RB_INSERT(struct revoked_blob_tree *head, struct revoked_blob *elm) { struct revoked_blob *tmp; struct revoked_blob *parent = 
((void *)0)
; int comp = 0; tmp = (head)->rbh_root; while (tmp) { parent = tmp; comp = (blob_cmp)(elm, parent); if (comp < 0) tmp = (tmp)->tree_entry.rbe_left; else if (comp > 0) tmp = (tmp)->tree_entry.rbe_right; else return (tmp); } do { (elm)->tree_entry.rbe_parent = parent; (elm)->tree_entry.rbe_left = (elm)->tree_entry.rbe_right = 
((void *)0)
; (elm)->tree_entry.rbe_color = 1; } while (0); if (parent != 
((void *)0)
) { if (comp < 0) (parent)->tree_entry.rbe_left = elm; else (parent)->tree_entry.rbe_right = elm; do {} while (0); } else (head)->rbh_root = elm; revoked_blob_tree_RB_INSERT_COLOR(head, elm); return (
((void *)0)
); } __attribute__((__unused__)) static struct revoked_blob * revoked_blob_tree_RB_FIND(struct revoked_blob_tree *head, struct revoked_blob *elm) { struct revoked_blob *tmp = (head)->rbh_root; int comp; while (tmp) { comp = blob_cmp(elm, tmp); if (comp < 0) tmp = (tmp)->tree_entry.rbe_left; else if (comp > 0) tmp = (tmp)->tree_entry.rbe_right; else return (tmp); } return (
((void *)0)
); } __attribute__((__unused__)) static struct revoked_blob * revoked_blob_tree_RB_NFIND(struct revoked_blob_tree *head, struct revoked_blob *elm) { struct revoked_blob *tmp = (head)->rbh_root; struct revoked_blob *res = 
((void *)0)
; int comp; while (tmp) { comp = blob_cmp(elm, tmp); if (comp < 0) { res = tmp; tmp = (tmp)->tree_entry.rbe_left; } else if (comp > 0) tmp = (tmp)->tree_entry.rbe_right; else return (tmp); } return (res); } __attribute__((__unused__)) static struct revoked_blob * revoked_blob_tree_RB_NEXT(struct revoked_blob *elm) { if ((elm)->tree_entry.rbe_right) { elm = (elm)->tree_entry.rbe_right; while ((elm)->tree_entry.rbe_left) elm = (elm)->tree_entry.rbe_left; } else { if ((elm)->tree_entry.rbe_parent && (elm == ((elm)->tree_entry.rbe_parent)->tree_entry.rbe_left)) elm = (elm)->tree_entry.rbe_parent; else { while ((elm)->tree_entry.rbe_parent && (elm == ((elm)->tree_entry.rbe_parent)->tree_entry.rbe_right)) elm = (elm)->tree_entry.rbe_parent; elm = (elm)->tree_entry.rbe_parent; } } return (elm); } __attribute__((__unused__)) static struct revoked_blob * revoked_blob_tree_RB_PREV(struct revoked_blob *elm) { if ((elm)->tree_entry.rbe_left) { elm = (elm)->tree_entry.rbe_left; while ((elm)->tree_entry.rbe_right) elm = (elm)->tree_entry.rbe_right; } else { if ((elm)->tree_entry.rbe_parent && (elm == ((elm)->tree_entry.rbe_parent)->tree_entry.rbe_right)) elm = (elm)->tree_entry.rbe_parent; else { while ((elm)->tree_entry.rbe_parent && (elm == ((elm)->tree_entry.rbe_parent)->tree_entry.rbe_left)) elm = (elm)->tree_entry.rbe_parent; elm = (elm)->tree_entry.rbe_parent; } } return (elm); } __attribute__((__unused__)) static struct revoked_blob * revoked_blob_tree_RB_MINMAX(struct revoked_blob_tree *head, int val) { struct revoked_blob *tmp = (head)->rbh_root; struct revoked_blob *parent = 
((void *)0)
; while (tmp) { parent = tmp; if (val < 0) tmp = (tmp)->tree_entry.rbe_left; else tmp = (tmp)->tree_entry.rbe_right; } return (parent); }


struct revoked_certs {
 struct sshkey *ca_key;
 struct revoked_serial_tree revoked_serials;
 struct revoked_key_id_tree revoked_key_ids;
 struct { struct revoked_certs *tqe_next; struct revoked_certs **tqe_prev; } entry;
};
struct revoked_certs_list { struct revoked_certs *tqh_first; struct revoked_certs **tqh_last; };

struct ssh_krl {
 u_int64_t krl_version;
 u_int64_t generated_date;
 u_int64_t flags;
 char *comment;
 struct revoked_blob_tree revoked_keys;
 struct revoked_blob_tree revoked_sha1s;
 struct revoked_blob_tree revoked_sha256s;
 struct revoked_certs_list revoked_certs;
};


static int
serial_cmp(struct revoked_serial *a, struct revoked_serial *b)
{
 if (a->hi >= b->lo && a->lo <= b->hi)
  return 0;
 return a->lo < b->lo ? -1 : 1;
}

static int
key_id_cmp(struct revoked_key_id *a, struct revoked_key_id *b)
{
 return strcmp(a->key_id, b->key_id);
}

static int
blob_cmp(struct revoked_blob *a, struct revoked_blob *b)
{
 int r;

 if (a->len != b->len) {
  if ((r = memcmp(a->blob, b->blob, (((a->len) < (b->len)) ? (a->len) : (b->len)))) != 0)
   return r;
  return a->len > b->len ? 1 : -1;
 } else
  return memcmp(a->blob, b->blob, a->len);
}

struct ssh_krl *
ssh_krl_init(void)
{
 struct ssh_krl *krl;

 if ((krl = calloc(1, sizeof(*krl))) == 
                                       ((void *)0)
                                           )
  return 
        ((void *)0)
            ;
 do { (&krl->revoked_keys)->rbh_root = 
((void *)0)
; } while (0);
 do { (&krl->revoked_sha1s)->rbh_root = 
((void *)0)
; } while (0);
 do { (&krl->revoked_sha256s)->rbh_root = 
((void *)0)
; } while (0);
 do { (&krl->revoked_certs)->tqh_first = 
((void *)0)
; (&krl->revoked_certs)->tqh_last = &(&krl->revoked_certs)->tqh_first; } while (0);
 return krl;
}

static void
revoked_certs_free(struct revoked_certs *rc)
{
 struct revoked_serial *rs, *trs;
 struct revoked_key_id *rki, *trki;

 for ((rs) = revoked_serial_tree_RB_MINMAX(&rc->revoked_serials, -1); ((rs) != 
((void *)0)
) && ((trs) = revoked_serial_tree_RB_NEXT(rs), 1); (rs) = (trs)) {
  revoked_serial_tree_RB_REMOVE(&rc->revoked_serials, rs);
  free(rs);
 }
 for ((rki) = revoked_key_id_tree_RB_MINMAX(&rc->revoked_key_ids, -1); ((rki) != 
((void *)0)
) && ((trki) = revoked_key_id_tree_RB_NEXT(rki), 1); (rki) = (trki)) {
  revoked_key_id_tree_RB_REMOVE(&rc->revoked_key_ids, rki);
  free(rki->key_id);
  free(rki);
 }
 sshkey_free(rc->ca_key);
}

void
ssh_krl_free(struct ssh_krl *krl)
{
 struct revoked_blob *rb, *trb;
 struct revoked_certs *rc, *trc;

 if (krl == 
           ((void *)0)
               )
  return;

 free(krl->comment);
 for ((rb) = revoked_blob_tree_RB_MINMAX(&krl->revoked_keys, -1); ((rb) != 
((void *)0)
) && ((trb) = revoked_blob_tree_RB_NEXT(rb), 1); (rb) = (trb)) {
  revoked_blob_tree_RB_REMOVE(&krl->revoked_keys, rb);
  free(rb->blob);
  free(rb);
 }
 for ((rb) = revoked_blob_tree_RB_MINMAX(&krl->revoked_sha1s, -1); ((rb) != 
((void *)0)
) && ((trb) = revoked_blob_tree_RB_NEXT(rb), 1); (rb) = (trb)) {
  revoked_blob_tree_RB_REMOVE(&krl->revoked_sha1s, rb);
  free(rb->blob);
  free(rb);
 }
 for ((rb) = revoked_blob_tree_RB_MINMAX(&krl->revoked_sha256s, -1); ((rb) != 
((void *)0)
) && ((trb) = revoked_blob_tree_RB_NEXT(rb), 1); (rb) = (trb)) {
  revoked_blob_tree_RB_REMOVE(&krl->revoked_sha256s, rb);
  free(rb->blob);
  free(rb);
 }
 for ((rc) = ((&krl->revoked_certs)->tqh_first); (rc) != 
((void *)0) 
&& ((trc) = ((rc)->entry.tqe_next), 1); (rc) = (trc)) {
  do { if (((rc)->entry.tqe_next) != 
 ((void *)0)
 ) (rc)->entry.tqe_next->entry.tqe_prev = (rc)->entry.tqe_prev; else (&krl->revoked_certs)->tqh_last = (rc)->entry.tqe_prev; *(rc)->entry.tqe_prev = (rc)->entry.tqe_next; ; ; } while (0);
  revoked_certs_free(rc);
 }
}

void
ssh_krl_set_version(struct ssh_krl *krl, u_int64_t version)
{
 krl->krl_version = version;
}

int
ssh_krl_set_comment(struct ssh_krl *krl, const char *comment)
{
 free(krl->comment);
 if ((krl->comment = strdup(comment)) == 
                                        ((void *)0)
                                            )
  return -2;
 return 0;
}





static int
revoked_certs_for_ca_key(struct ssh_krl *krl, const struct sshkey *ca_key,
    struct revoked_certs **rcp, int allow_create)
{
 struct revoked_certs *rc;
 int r;

 *rcp = 
       ((void *)0)
           ;
 for((rc) = ((&krl->revoked_certs)->tqh_first); (rc) != 
((void *)0)
; (rc) = ((rc)->entry.tqe_next)) {
  if ((ca_key == 
                ((void *)0) 
                     && rc->ca_key == 
                                      ((void *)0)
                                          ) ||
      sshkey_equal(rc->ca_key, ca_key)) {
   *rcp = rc;
   return 0;
  }
 }
 if (!allow_create)
  return 0;

 if ((rc = calloc(1, sizeof(*rc))) == 
                                     ((void *)0)
                                         )
  return -2;
 if (ca_key == 
              ((void *)0)
                  )
  rc->ca_key = 
              ((void *)0)
                  ;
 else if ((r = sshkey_from_private(ca_key, &rc->ca_key)) != 0) {
  free(rc);
  return r;
 }
 do { (&rc->revoked_serials)->rbh_root = 
((void *)0)
; } while (0);
 do { (&rc->revoked_key_ids)->rbh_root = 
((void *)0)
; } while (0);
 do { (rc)->entry.tqe_next = 
((void *)0)
; (rc)->entry.tqe_prev = (&krl->revoked_certs)->tqh_last; *(&krl->revoked_certs)->tqh_last = (rc); (&krl->revoked_certs)->tqh_last = &(rc)->entry.tqe_next; } while (0);
 ;
 *rcp = rc;
 return 0;
}

static int
insert_serial_range(struct revoked_serial_tree *rt, u_int64_t lo, u_int64_t hi)
{
 struct revoked_serial rs, *ers, *crs, *irs;

 ;
 memset(&rs, 0, sizeof(rs));
 rs.lo = lo;
 rs.hi = hi;
 ers = revoked_serial_tree_RB_NFIND(rt, &rs);
 if (ers == 
           ((void *)0) 
                || serial_cmp(ers, &rs) != 0) {

  if ((irs = malloc(sizeof(rs))) == 
                                   ((void *)0)
                                       )
   return -2;
  memcpy(irs, &rs, sizeof(*irs));
  ers = revoked_serial_tree_RB_INSERT(rt, irs);
  if (ers != 
            ((void *)0)
                ) {
   ;

   free(irs);
   return -1;
  }
  ers = irs;
 } else {
  ;




  if (ers->lo > lo)
   ers->lo = lo;
  if (ers->hi < hi)
   ers->hi = hi;
 }







 while ((crs = revoked_serial_tree_RB_PREV(ers)) != 
                                                        ((void *)0)
                                                            ) {
  ;
  if (ers->lo != 0 && crs->hi < ers->lo - 1)
   break;

  if (crs->lo < ers->lo) {
   ers->lo = crs->lo;
   ;
  }
  revoked_serial_tree_RB_REMOVE(rt, crs);
  free(crs);
 }

 while ((crs = revoked_serial_tree_RB_NEXT(ers)) != 
                                                        ((void *)0)
                                                            ) {
  ;
  if (ers->hi != (u_int64_t)-1 && crs->lo > ers->hi + 1)
   break;

  if (crs->hi > ers->hi) {
   ers->hi = crs->hi;
   ;
  }
  revoked_serial_tree_RB_REMOVE(rt, crs);
  free(crs);
 }
 ;
 return 0;
}

int
ssh_krl_revoke_cert_by_serial(struct ssh_krl *krl, const struct sshkey *ca_key,
    u_int64_t serial)
{
 return ssh_krl_revoke_cert_by_serial_range(krl, ca_key, serial, serial);
}

int
ssh_krl_revoke_cert_by_serial_range(struct ssh_krl *krl,
    const struct sshkey *ca_key, u_int64_t lo, u_int64_t hi)
{
 struct revoked_certs *rc;
 int r;

 if (lo > hi || lo == 0)
  return -10;
 if ((r = revoked_certs_for_ca_key(krl, ca_key, &rc, 1)) != 0)
  return r;
 return insert_serial_range(&rc->revoked_serials, lo, hi);
}

int
ssh_krl_revoke_cert_by_key_id(struct ssh_krl *krl, const struct sshkey *ca_key,
    const char *key_id)
{
 struct revoked_key_id *rki, *erki;
 struct revoked_certs *rc;
 int r;

 if ((r = revoked_certs_for_ca_key(krl, ca_key, &rc, 1)) != 0)
  return r;

 ;
 if ((rki = calloc(1, sizeof(*rki))) == 
                                       ((void *)0) 
                                            ||
     (rki->key_id = strdup(key_id)) == 
                                      ((void *)0)
                                          ) {
  free(rki);
  return -2;
 }
 erki = revoked_key_id_tree_RB_INSERT(&rc->revoked_key_ids, rki);
 if (erki != 
            ((void *)0)
                ) {
  free(rki->key_id);
  free(rki);
 }
 return 0;
}


static int
plain_key_blob(const struct sshkey *key, u_char **blob, size_t *blen)
{
 struct sshkey *kcopy;
 int r;

 if ((r = sshkey_from_private(key, &kcopy)) != 0)
  return r;
 if (sshkey_is_cert(kcopy)) {
  if ((r = sshkey_drop_cert(kcopy)) != 0) {
   sshkey_free(kcopy);
   return r;
  }
 }
 r = sshkey_to_blob(kcopy, blob, blen);
 sshkey_free(kcopy);
 return r;
}


static int
revoke_blob(struct revoked_blob_tree *rbt, u_char *blob, size_t len)
{
 struct revoked_blob *rb, *erb;

 if ((rb = calloc(1, sizeof(*rb))) == 
                                     ((void *)0)
                                         )
  return -2;
 rb->blob = blob;
 rb->len = len;
 erb = revoked_blob_tree_RB_INSERT(rbt, rb);
 if (erb != 
           ((void *)0)
               ) {
  free(rb->blob);
  free(rb);
 }
 return 0;
}

int
ssh_krl_revoke_key_explicit(struct ssh_krl *krl, const struct sshkey *key)
{
 u_char *blob;
 size_t len;
 int r;

 sshlog("krl.c", __func__, 410, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "revoke type %s", sshkey_type(key));
 if ((r = plain_key_blob(key, &blob, &len)) != 0)
  return r;
 return revoke_blob(&krl->revoked_keys, blob, len);
}

static int
revoke_by_hash(struct revoked_blob_tree *target, const u_char *p, size_t len)
{
 u_char *blob;
 int r;


 if ((blob = malloc(len)) == 
                            ((void *)0)
                                )
  return -24;
 memcpy(blob, p, len);
 if ((r = revoke_blob(target, blob, len)) != 0) {
  free(blob);
  return r;
 }
 return 0;
}

int
ssh_krl_revoke_key_sha1(struct ssh_krl *krl, const u_char *p, size_t len)
{
 sshlog("krl.c", __func__, 436, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "revoke by sha1");
 if (len != 20)
  return -4;
 return revoke_by_hash(&krl->revoked_sha1s, p, len);
}

int
ssh_krl_revoke_key_sha256(struct ssh_krl *krl, const u_char *p, size_t len)
{
 sshlog("krl.c", __func__, 445, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "revoke by sha256");
 if (len != 32)
  return -4;
 return revoke_by_hash(&krl->revoked_sha256s, p, len);
}

int
ssh_krl_revoke_key(struct ssh_krl *krl, const struct sshkey *key)
{

 if (!sshkey_is_cert(key))
  return ssh_krl_revoke_key_explicit(krl, key);

 if (key->cert->serial == 0) {
  return ssh_krl_revoke_cert_by_key_id(krl,
      key->cert->signature_key,
      key->cert->key_id);
 } else {
  return ssh_krl_revoke_cert_by_serial(krl,
      key->cert->signature_key,
      key->cert->serial);
 }
}
static int
choose_next_state(int current_state, u_int64_t contig, int final,
    u_int64_t last_gap, u_int64_t next_gap, int *force_new_section)
{
 int new_state;
 u_int64_t cost, cost_list, cost_range, cost_bitmap, cost_bitmap_restart;





 contig = (((contig) < (1ULL<<31)) ? (contig) : (1ULL<<31));
 last_gap = (((last_gap) < (1ULL<<31)) ? (last_gap) : (1ULL<<31));
 next_gap = (((next_gap) < (1ULL<<31)) ? (next_gap) : (1ULL<<31));






 cost_list = cost_bitmap = cost_bitmap_restart = 0;
 cost_range = 8;
 switch (current_state) {
 case 0x20:
  cost_bitmap_restart = cost_bitmap = 8 + 64;
  break;
 case 0x22:
  cost_list = 8;
  cost_bitmap_restart = 8 + 64;
  break;
 case 0x21:
 case 0:
  cost_bitmap_restart = cost_bitmap = 8 + 64;
  cost_list = 8;
 }


 cost_list += 64 * contig + (final ? 0 : 8+64);
 cost_range += (2 * 64) + (final ? 0 : 8+64);
 cost_bitmap += last_gap + contig + (final ? 0 : (((next_gap) < (8+64)) ? (next_gap) : (8+64)));
 cost_bitmap_restart += contig + (final ? 0 : (((next_gap) < (8+64)) ? (next_gap) : (8+64)));


 cost_list = (cost_list + 7) / 8;
 cost_bitmap = (cost_bitmap + 7) / 8;
 cost_bitmap_restart = (cost_bitmap_restart + 7) / 8;
 cost_range = (cost_range + 7) / 8;


 *force_new_section = 0;
 new_state = 0x22;
 cost = cost_bitmap;
 if (cost_range < cost) {
  new_state = 0x21;
  cost = cost_range;
 }
 if (cost_list < cost) {
  new_state = 0x20;
  cost = cost_list;
 }
 if (cost_bitmap_restart < cost) {
  new_state = 0x22;
  *force_new_section = 1;
  cost = cost_bitmap_restart;
 }







                                           ;
 return new_state;
}

static int
put_bitmap(struct sshbuf *buf, struct bitmap *bitmap)
{
 size_t len;
 u_char *blob;
 int r;

 len = bitmap_nbytes(bitmap);
 if ((blob = malloc(len)) == 
                            ((void *)0)
                                )
  return -2;
 if (bitmap_to_string(bitmap, blob, len) != 0) {
  free(blob);
  return -1;
 }
 r = sshbuf_put_bignum2_bytes(buf, blob, len);
 free(blob);
 return r;
}


static int
revoked_certs_generate(struct revoked_certs *rc, struct sshbuf *buf)
{
 int final, force_new_sect, r = -1;
 u_int64_t i, contig, gap, last = 0, bitmap_start = 0;
 struct revoked_serial *rs, *nrs;
 struct revoked_key_id *rki;
 int next_state, state = 0;
 struct sshbuf *sect;
 struct bitmap *bitmap = 
                        ((void *)0)
                            ;

 if ((sect = sshbuf_new()) == 
                             ((void *)0)
                                 )
  return -2;


 if (rc->ca_key == 
                  ((void *)0)
                      ) {
  if ((r = sshbuf_put_string(buf, 
                                 ((void *)0)
                                     , 0)) != 0)
   goto out;
 } else {
  if ((r = sshkey_puts(rc->ca_key, buf)) != 0)
   goto out;
 }
 if ((r = sshbuf_put_string(buf, 
                                ((void *)0)
                                    , 0)) != 0)
  goto out;


 for (rs = revoked_serial_tree_RB_MINMAX(&rc->revoked_serials, -1);
      rs != 
           ((void *)0)
               ;
      rs = revoked_serial_tree_RB_NEXT(rs)) {
 

             ;


  nrs = revoked_serial_tree_RB_NEXT(rs);
  final = nrs == 
                ((void *)0)
                    ;
  gap = nrs == 
              ((void *)0) 
                   ? 0 : nrs->lo - rs->hi;
  contig = 1 + (rs->hi - rs->lo);


  next_state = choose_next_state(state, contig, final,
      state == 0 ? 0 : rs->lo - last, gap, &force_new_sect);





  if (state != 0 && (force_new_sect || next_state != state ||
      state == 0x21)) {
   ;
   switch (state) {
   case 0x20:
   case 0x21:
    break;
   case 0x22:
    if ((r = put_bitmap(sect, bitmap)) != 0)
     goto out;
    bitmap_free(bitmap);
    bitmap = 
            ((void *)0)
                ;
    break;
   }
   if ((r = sshbuf_put_u8(buf, state)) != 0 ||
       (r = sshbuf_put_stringb(buf, sect)) != 0)
    goto out;
   sshbuf_reset(sect);
  }


  if (next_state != state || force_new_sect) {
  
                   ;
   state = next_state;
   sshbuf_reset(sect);
   switch (state) {
   case 0x20:
   case 0x21:
    break;
   case 0x22:
    if ((bitmap = bitmap_new()) == 
                                  ((void *)0)
                                      ) {
     r = -2;
     goto out;
    }
    bitmap_start = rs->lo;
    if ((r = sshbuf_put_u64(sect,
        bitmap_start)) != 0)
     goto out;
    break;
   }
  }


  switch (state) {
  case 0x20:
   for (i = 0; i < contig; i++) {
    if ((r = sshbuf_put_u64(sect, rs->lo + i)) != 0)
     goto out;
   }
   break;
  case 0x21:
   if ((r = sshbuf_put_u64(sect, rs->lo)) != 0 ||
       (r = sshbuf_put_u64(sect, rs->hi)) != 0)
    goto out;
   break;
  case 0x22:
   if (rs->lo - bitmap_start > 0x7fffffff) {
    sshlog("krl.c", __func__, 677, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "insane bitmap gap");
    goto out;
   }
   for (i = 0; i < contig; i++) {
    if (bitmap_set_bit(bitmap,
        rs->lo + i - bitmap_start) != 0) {
     r = -2;
     goto out;
    }
   }
   break;
  }
  last = rs->hi;
 }

 if (state != 0) {
  ;
  switch (state) {
  case 0x20:
  case 0x21:
   break;
  case 0x22:
   if ((r = put_bitmap(sect, bitmap)) != 0)
    goto out;
   bitmap_free(bitmap);
   bitmap = 
           ((void *)0)
               ;
   break;
  }
  if ((r = sshbuf_put_u8(buf, state)) != 0 ||
      (r = sshbuf_put_stringb(buf, sect)) != 0)
   goto out;
 }
 ;


 sshbuf_reset(sect);
 for ((rki) = revoked_key_id_tree_RB_MINMAX(&rc->revoked_key_ids, -1); (rki) != 
((void *)0)
; (rki) = revoked_key_id_tree_RB_NEXT(rki)) {
  ;
  if ((r = sshbuf_put_cstring(sect, rki->key_id)) != 0)
   goto out;
 }
 if (sshbuf_len(sect) != 0) {
  if ((r = sshbuf_put_u8(buf, 0x23)) != 0 ||
      (r = sshbuf_put_stringb(buf, sect)) != 0)
   goto out;
 }
 r = 0;
 out:
 bitmap_free(bitmap);
 sshbuf_free(sect);
 return r;
}

int
ssh_krl_to_blob(struct ssh_krl *krl, struct sshbuf *buf,
    struct sshkey **sign_keys, u_int nsign_keys)
{
 int r = -1;
 struct revoked_certs *rc;
 struct revoked_blob *rb;
 struct sshbuf *sect;
 u_char *sblob = 
                ((void *)0)
                    ;
 size_t slen, i;

 if (krl->generated_date == 0)
  krl->generated_date = time(
                            ((void *)0)
                                );

 if ((sect = sshbuf_new()) == 
                             ((void *)0)
                                 )
  return -2;


 if ((r = sshbuf_put(buf, "SSHKRL\n\0", sizeof("SSHKRL\n\0") - 1)) != 0 ||
     (r = sshbuf_put_u32(buf, 1)) != 0 ||
     (r = sshbuf_put_u64(buf, krl->krl_version)) != 0 ||
     (r = sshbuf_put_u64(buf, krl->generated_date)) != 0 ||
     (r = sshbuf_put_u64(buf, krl->flags)) != 0 ||
     (r = sshbuf_put_string(buf, 
                                ((void *)0)
                                    , 0)) != 0 ||
     (r = sshbuf_put_cstring(buf, krl->comment)) != 0)
  goto out;


 for((rc) = ((&krl->revoked_certs)->tqh_first); (rc) != 
((void *)0)
; (rc) = ((rc)->entry.tqe_next)) {
  sshbuf_reset(sect);
  if ((r = revoked_certs_generate(rc, sect)) != 0)
   goto out;
  if ((r = sshbuf_put_u8(buf, 1)) != 0 ||
      (r = sshbuf_put_stringb(buf, sect)) != 0)
   goto out;
 }


 sshbuf_reset(sect);
 for ((rb) = revoked_blob_tree_RB_MINMAX(&krl->revoked_keys, -1); (rb) != 
((void *)0)
; (rb) = revoked_blob_tree_RB_NEXT(rb)) {
  ;
  if ((r = sshbuf_put_string(sect, rb->blob, rb->len)) != 0)
   goto out;
 }
 if (sshbuf_len(sect) != 0) {
  if ((r = sshbuf_put_u8(buf, 2)) != 0 ||
      (r = sshbuf_put_stringb(buf, sect)) != 0)
   goto out;
 }
 sshbuf_reset(sect);
 for ((rb) = revoked_blob_tree_RB_MINMAX(&krl->revoked_sha1s, -1); (rb) != 
((void *)0)
; (rb) = revoked_blob_tree_RB_NEXT(rb)) {
  ;
  if ((r = sshbuf_put_string(sect, rb->blob, rb->len)) != 0)
   goto out;
 }
 if (sshbuf_len(sect) != 0) {
  if ((r = sshbuf_put_u8(buf,
      3)) != 0 ||
      (r = sshbuf_put_stringb(buf, sect)) != 0)
   goto out;
 }
 sshbuf_reset(sect);
 for ((rb) = revoked_blob_tree_RB_MINMAX(&krl->revoked_sha256s, -1); (rb) != 
((void *)0)
; (rb) = revoked_blob_tree_RB_NEXT(rb)) {
  ;
  if ((r = sshbuf_put_string(sect, rb->blob, rb->len)) != 0)
   goto out;
 }
 if (sshbuf_len(sect) != 0) {
  if ((r = sshbuf_put_u8(buf,
      5)) != 0 ||
      (r = sshbuf_put_stringb(buf, sect)) != 0)
   goto out;
 }

 for (i = 0; i < nsign_keys; i++) {
  ;
  if ((r = sshbuf_put_u8(buf, 4)) != 0 ||
      (r = sshkey_puts(sign_keys[i], buf)) != 0)
   goto out;

  if ((r = sshkey_sign(sign_keys[i], &sblob, &slen,
      sshbuf_ptr(buf), sshbuf_len(buf), 
                                       ((void *)0)
                                           , 
                                             ((void *)0)
                                                 ,
      
     ((void *)0)
         , 0)) != 0)
   goto out;
  ;
  if ((r = sshbuf_put_string(buf, sblob, slen)) != 0)
   goto out;
 }

 r = 0;
 out:
 free(sblob);
 sshbuf_free(sect);
 return r;
}

static void
format_timestamp(u_int64_t timestamp, char *ts, size_t nts)
{
 time_t t;
 struct tm *tm;

 t = timestamp;
 tm = localtime(&t);
 if (tm == 
          ((void *)0)
              )
  strlcpy(ts, "<INVALID>", nts);
 else {
  *ts = '\0';
  strftime(ts, nts, "%Y%m%dT%H%M%S", tm);
 }
}

static int
parse_revoked_certs(struct sshbuf *buf, struct ssh_krl *krl)
{
 int r = -1;
 u_char type;
 const u_char *blob;
 size_t blen, nbits;
 struct sshbuf *subsect = 
                         ((void *)0)
                             ;
 u_int64_t serial, serial_lo, serial_hi;
 struct bitmap *bitmap = 
                        ((void *)0)
                            ;
 char *key_id = 
               ((void *)0)
                   ;
 struct sshkey *ca_key = 
                        ((void *)0)
                            ;

 if ((subsect = sshbuf_new()) == 
                                ((void *)0)
                                    )
  return -2;


 if ((r = sshbuf_get_string_direct(buf, &blob, &blen)) != 0 ||
     (r = sshbuf_get_string_direct(buf, 
         ((void *)0)
         , 
         ((void *)0)
         )) != 0)
  goto out;
 if (blen != 0 && (r = sshkey_from_blob(blob, blen, &ca_key)) != 0)
  goto out;

 while (sshbuf_len(buf) > 0) {
  sshbuf_free(subsect);
  subsect = 
           ((void *)0)
               ;
  if ((r = sshbuf_get_u8(buf, &type)) != 0 ||
      (r = sshbuf_froms(buf, &subsect)) != 0)
   goto out;
  ;


  switch (type) {
  case 0x20:
   while (sshbuf_len(subsect) > 0) {
    if ((r = sshbuf_get_u64(subsect, &serial)) != 0)
     goto out;
    if ((r = ssh_krl_revoke_cert_by_serial(krl,
        ca_key, serial)) != 0)
     goto out;
   }
   break;
  case 0x21:
   if ((r = sshbuf_get_u64(subsect, &serial_lo)) != 0 ||
       (r = sshbuf_get_u64(subsect, &serial_hi)) != 0)
    goto out;
   if ((r = ssh_krl_revoke_cert_by_serial_range(krl,
       ca_key, serial_lo, serial_hi)) != 0)
    goto out;
   break;
  case 0x22:
   if ((bitmap = bitmap_new()) == 
                                 ((void *)0)
                                     ) {
    r = -2;
    goto out;
   }
   if ((r = sshbuf_get_u64(subsect, &serial_lo)) != 0 ||
       (r = sshbuf_get_bignum2_bytes_direct(subsect,
       &blob, &blen)) != 0)
    goto out;
   if (bitmap_from_string(bitmap, blob, blen) != 0) {
    r = -4;
    goto out;
   }
   nbits = bitmap_nbits(bitmap);
   for (serial = 0; serial < (u_int64_t)nbits; serial++) {
    if (serial > 0 && serial_lo + serial == 0) {
     sshlog("krl.c", __func__, 908, 1, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "bitmap wraps u64");
     r = -4;
     goto out;
    }
    if (!bitmap_test_bit(bitmap, serial))
     continue;
    if ((r = ssh_krl_revoke_cert_by_serial(krl,
        ca_key, serial_lo + serial)) != 0)
     goto out;
   }
   bitmap_free(bitmap);
   bitmap = 
           ((void *)0)
               ;
   break;
  case 0x23:
   while (sshbuf_len(subsect) > 0) {
    if ((r = sshbuf_get_cstring(subsect,
        &key_id, 
                ((void *)0)
                    )) != 0)
     goto out;
    if ((r = ssh_krl_revoke_cert_by_key_id(krl,
        ca_key, key_id)) != 0)
     goto out;
    free(key_id);
    key_id = 
            ((void *)0)
                ;
   }
   break;
  default:
   sshlog("krl.c", __func__, 934, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Unsupported KRL certificate section %u", type);
   r = -4;
   goto out;
  }
  if (sshbuf_len(subsect) > 0) {
   sshlog("krl.c", __func__, 939, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "KRL certificate section contains unparsed data");
   r = -4;
   goto out;
  }
 }

 r = 0;
 out:
 if (bitmap != 
              ((void *)0)
                  )
  bitmap_free(bitmap);
 free(key_id);
 sshkey_free(ca_key);
 sshbuf_free(subsect);
 return r;
}

static int
blob_section(struct sshbuf *sect, struct revoked_blob_tree *target_tree,
    size_t expected_len)
{
 u_char *rdata = 
                ((void *)0)
                    ;
 size_t rlen = 0;
 int r;

 while (sshbuf_len(sect) > 0) {
  if ((r = sshbuf_get_string(sect, &rdata, &rlen)) != 0)
   return r;
  if (expected_len != 0 && rlen != expected_len) {
   sshlog("krl.c", __func__, 967, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "bad length");
   free(rdata);
   return -4;
  }
  if ((r = revoke_blob(target_tree, rdata, rlen)) != 0) {
   free(rdata);
   return r;
  }
 }
 return 0;
}


int
ssh_krl_from_blob(struct sshbuf *buf, struct ssh_krl **krlp,
    const struct sshkey **sign_ca_keys, size_t nsign_ca_keys)
{
 struct sshbuf *copy = 
                      ((void *)0)
                          , *sect = 
                                    ((void *)0)
                                        ;
 struct ssh_krl *krl = 
                      ((void *)0)
                          ;
 char timestamp[64];
 int r = -1, sig_seen;
 struct sshkey *key = 
                     ((void *)0)
                         , **ca_used = 
                                       ((void *)0)
                                           , **tmp_ca_used;
 u_char type;
 const u_char *blob;
 size_t i, j, sig_off, sects_off, blen, nca_used;
 u_int format_version;

 nca_used = 0;
 *krlp = 
        ((void *)0)
            ;
 if (sshbuf_len(buf) < sizeof("SSHKRL\n\0") - 1 ||
     memcmp(sshbuf_ptr(buf), "SSHKRL\n\0", sizeof("SSHKRL\n\0") - 1) != 0) {
  sshlog("krl.c", __func__, 998, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "not a KRL");
  return -50;
 }


 if ((copy = sshbuf_fromb(buf)) == 
                                  ((void *)0)
                                      ) {
  r = -2;
  goto out;
 }
 if ((r = sshbuf_consume(copy, sizeof("SSHKRL\n\0") - 1)) != 0)
  goto out;

 if ((krl = ssh_krl_init()) == 
                              ((void *)0)
                                  ) {
  sshlog("krl.c", __func__, 1011, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "alloc failed");
  goto out;
 }

 if ((r = sshbuf_get_u32(copy, &format_version)) != 0)
  goto out;
 if (format_version != 1) {
  r = -4;
  goto out;
 }
 if ((r = sshbuf_get_u64(copy, &krl->krl_version)) != 0 ||
     (r = sshbuf_get_u64(copy, &krl->generated_date)) != 0 ||
     (r = sshbuf_get_u64(copy, &krl->flags)) != 0 ||
     (r = sshbuf_get_string_direct(copy, 
         ((void *)0)
         , 
         ((void *)0)
         )) != 0 ||
     (r = sshbuf_get_cstring(copy, &krl->comment, 
                                                 ((void *)0)
                                                     )) != 0)
  goto out;

 format_timestamp(krl->generated_date, timestamp, sizeof(timestamp));
 sshlog("krl.c", __func__, 1029, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "KRL version %llu generated at %s%s%s", (long long unsigned)krl->krl_version, timestamp, *krl->comment ? ": " : "", krl->comment)

                                             ;





 sig_seen = 0;
 if (sshbuf_len(buf) < sshbuf_len(copy)) {

  r = -1;
  goto out;
 }
 sects_off = sshbuf_len(buf) - sshbuf_len(copy);
 while (sshbuf_len(copy) > 0) {
  if ((r = sshbuf_get_u8(copy, &type)) != 0 ||
      (r = sshbuf_get_string_direct(copy, &blob, &blen)) != 0)
   goto out;
  ;
  if (type != 4) {
   if (sig_seen) {
    sshlog("krl.c", __func__, 1051, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "KRL contains non-signature section " "after signature")
                          ;
    r = -4;
    goto out;
   }

   continue;
  }
  sig_seen = 1;

  if ((r = sshkey_from_blob(blob, blen, &key)) != 0) {
   r = -4;
   goto out;
  }
  if (sshbuf_len(buf) < sshbuf_len(copy)) {

   r = -1;
   goto out;
  }
  sig_off = sshbuf_len(buf) - sshbuf_len(copy);

  if ((r = sshbuf_get_string_direct(copy, &blob, &blen)) != 0) {
   r = -4;
   goto out;
  }

  if ((r = sshkey_verify(key, blob, blen,
      sshbuf_ptr(buf), sig_off, 
                               ((void *)0)
                                   , 0, 
                                        ((void *)0)
                                            )) != 0)
   goto out;

  for (i = 0; i < nca_used; i++) {
   if (sshkey_equal(ca_used[i], key)) {
    sshlog("krl.c", __func__, 1083, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "KRL signed more than once with " "the same key")
                       ;
    r = -4;
    goto out;
   }
  }

  tmp_ca_used = recallocarray(ca_used, nca_used, nca_used + 1,
      sizeof(*ca_used));
  if (tmp_ca_used == 
                    ((void *)0)
                        ) {
   r = -2;
   goto out;
  }
  ca_used = tmp_ca_used;
  ca_used[nca_used++] = key;
  key = 
       ((void *)0)
           ;
 }

 if (sshbuf_len(copy) != 0) {

  r = -1;
  goto out;
 }





 sshbuf_free(copy);
 if ((copy = sshbuf_fromb(buf)) == 
                                  ((void *)0)
                                      ) {
  r = -2;
  goto out;
 }
 if ((r = sshbuf_consume(copy, sects_off)) != 0)
  goto out;
 while (sshbuf_len(copy) > 0) {
  sshbuf_free(sect);
  sect = 
        ((void *)0)
            ;
  if ((r = sshbuf_get_u8(copy, &type)) != 0 ||
      (r = sshbuf_froms(copy, &sect)) != 0)
   goto out;
  ;

  switch (type) {
  case 1:
   if ((r = parse_revoked_certs(sect, krl)) != 0)
    goto out;
   break;
  case 2:
   if ((r = blob_section(sect,
       &krl->revoked_keys, 0)) != 0)
    goto out;
   break;
  case 3:
   if ((r = blob_section(sect,
       &krl->revoked_sha1s, 20)) != 0)
    goto out;
   break;
  case 5:
   if ((r = blob_section(sect,
       &krl->revoked_sha256s, 32)) != 0)
    goto out;
   break;
  case 4:

   sshbuf_free(sect);
   sect = 
         ((void *)0)
             ;
   if ((r = sshbuf_get_string_direct(copy, 
           ((void *)0)
           , 
           ((void *)0)
           )) != 0)
    goto out;
   break;
  default:
   sshlog("krl.c", __func__, 1154, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Unsupported KRL section %u", type);
   r = -4;
   goto out;
  }
  if (sect != 
             ((void *)0) 
                  && sshbuf_len(sect) > 0) {
   sshlog("krl.c", __func__, 1159, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "KRL section contains unparsed data");
   r = -4;
   goto out;
  }
 }


 sig_seen = 0;
 for (i = 0; i < nca_used; i++) {
  if (ssh_krl_check_key(krl, ca_used[i]) == 0)
   sig_seen = 1;
  else {
   sshkey_free(ca_used[i]);
   ca_used[i] = 
               ((void *)0)
                   ;
  }
 }
 if (nca_used && !sig_seen) {
  sshlog("krl.c", __func__, 1176, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "All keys used to sign KRL were revoked");
  r = -51;
  goto out;
 }


 if (sig_seen && nsign_ca_keys != 0) {
  sig_seen = 0;
  for (i = 0; !sig_seen && i < nsign_ca_keys; i++) {
   for (j = 0; j < nca_used; j++) {
    if (ca_used[j] == 
                     ((void *)0)
                         )
     continue;
    if (sshkey_equal(ca_used[j], sign_ca_keys[i])) {
     sig_seen = 1;
     break;
    }
   }
  }
  if (!sig_seen) {
   r = -21;
   sshlog("krl.c", __func__, 1196, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "KRL not signed with any trusted key");
   goto out;
  }
 }

 *krlp = krl;
 r = 0;
 out:
 if (r != 0)
  ssh_krl_free(krl);
 for (i = 0; i < nca_used; i++)
  sshkey_free(ca_used[i]);
 free(ca_used);
 sshkey_free(key);
 sshbuf_free(copy);
 sshbuf_free(sect);
 return r;
}


static int
is_cert_revoked(const struct sshkey *key, struct revoked_certs *rc)
{
 struct revoked_serial rs, *ers;
 struct revoked_key_id rki, *erki;


 memset(&rki, 0, sizeof(rki));
 rki.key_id = key->cert->key_id;
 erki = revoked_key_id_tree_RB_FIND(&rc->revoked_key_ids, &rki);
 if (erki != 
            ((void *)0)
                ) {
  ;
  return -51;
 }





 if (key->cert->serial == 0)
  return 0;

 memset(&rs, 0, sizeof(rs));
 rs.lo = rs.hi = key->cert->serial;
 ers = revoked_serial_tree_RB_FIND(&rc->revoked_serials, &rs);
 if (ers != 
           ((void *)0)
               ) {
 
                                           ;
  return -51;
 }
 return 0;
}


static int
is_key_revoked(struct ssh_krl *krl, const struct sshkey *key)
{
 struct revoked_blob rb, *erb;
 struct revoked_certs *rc;
 int r;


 memset(&rb, 0, sizeof(rb));
 if ((r = sshkey_fingerprint_raw(key, 1,
     &rb.blob, &rb.len)) != 0)
  return r;
 erb = revoked_blob_tree_RB_FIND(&krl->revoked_sha1s, &rb);
 free(rb.blob);
 if (erb != 
           ((void *)0)
               ) {
  ;
  return -51;
 }
 memset(&rb, 0, sizeof(rb));
 if ((r = sshkey_fingerprint_raw(key, 2,
     &rb.blob, &rb.len)) != 0)
  return r;
 erb = revoked_blob_tree_RB_FIND(&krl->revoked_sha256s, &rb);
 free(rb.blob);
 if (erb != 
           ((void *)0)
               ) {
  ;
  return -51;
 }


 memset(&rb, 0, sizeof(rb));
 if ((r = plain_key_blob(key, &rb.blob, &rb.len)) != 0)
  return r;
 erb = revoked_blob_tree_RB_FIND(&krl->revoked_keys, &rb);
 free(rb.blob);
 if (erb != 
           ((void *)0)
               ) {
  ;
  return -51;
 }

 if (!sshkey_is_cert(key))
  return 0;


 if ((r = revoked_certs_for_ca_key(krl, key->cert->signature_key,
     &rc, 0)) != 0)
  return r;
 if (rc != 
          ((void *)0)
              ) {
  if ((r = is_cert_revoked(key, rc)) != 0)
   return r;
 }

 if ((r = revoked_certs_for_ca_key(krl, 
                                       ((void *)0)
                                           , &rc, 0)) != 0)
  return r;
 if (rc != 
          ((void *)0)
              ) {
  if ((r = is_cert_revoked(key, rc)) != 0)
   return r;
 }

 ;
 return 0;
}

int
ssh_krl_check_key(struct ssh_krl *krl, const struct sshkey *key)
{
 int r;

 ;
 if ((r = is_key_revoked(krl, key)) != 0)
  return r;
 if (sshkey_is_cert(key)) {
  sshlog("krl.c", __func__, 1322, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "checking CA key");
  if ((r = is_key_revoked(krl, key->cert->signature_key)) != 0)
   return r;
 }
 ;
 return 0;
}

int
ssh_krl_file_contains_key(const char *path, const struct sshkey *key)
{
 struct sshbuf *krlbuf = 
                        ((void *)0)
                            ;
 struct ssh_krl *krl = 
                      ((void *)0)
                          ;
 int oerrno = 0, r;

 if (path == 
            ((void *)0)
                )
  return 0;
 if ((r = sshbuf_load_file(path, &krlbuf)) != 0) {
  oerrno = 
          (*__errno_location ())
               ;
  goto out;
 }
 if ((r = ssh_krl_from_blob(krlbuf, &krl, 
                                         ((void *)0)
                                             , 0)) != 0)
  goto out;
 sshlog("krl.c", __func__, 1345, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "checking KRL %s", path);
 r = ssh_krl_check_key(krl, key);
 out:
 sshbuf_free(krlbuf);
 ssh_krl_free(krl);
 if (r != 0)
  
 (*__errno_location ()) 
       = oerrno;
 return r;
}

int
krl_dump(struct ssh_krl *krl, FILE *f)
{
 struct sshkey *key = 
                     ((void *)0)
                         ;
 struct revoked_blob *rb;
 struct revoked_certs *rc;
 struct revoked_serial *rs;
 struct revoked_key_id *rki;
 int r, ret = 0;
 char *fp, timestamp[64];


 format_timestamp(krl->generated_date, timestamp, sizeof(timestamp));
 fprintf(f, "# KRL version %llu\n",
     (unsigned long long)krl->krl_version);
 fprintf(f, "# Generated at %s\n", timestamp);
 if (krl->comment != 
                    ((void *)0) 
                         && *krl->comment != '\0') {
  r = 0x7fffffff;
  asmprintf(&fp, 0x7fffffff, &r, "%s", krl->comment);
  fprintf(f, "# Comment: %s\n", fp);
  free(fp);
 }
 fputc('\n', f);

 for ((rb) = revoked_blob_tree_RB_MINMAX(&krl->revoked_keys, -1); (rb) != 
((void *)0)
; (rb) = revoked_blob_tree_RB_NEXT(rb)) {
  if ((r = sshkey_from_blob(rb->blob, rb->len, &key)) != 0) {
   ret = -4;
   sshlog("krl.c", __func__, 1382, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse KRL key");
   continue;
  }
  if ((fp = sshkey_fingerprint(key, 2,
      SSH_FP_DEFAULT)) == 
                         ((void *)0)
                             ) {
   ret = -4;
   sshlog("krl.c", __func__, 1388, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "sshkey_fingerprint failed");
   continue;
  }
  fprintf(f, "hash: %s # %s\n", fp, sshkey_ssh_name(key));
  free(fp);
  free(key);
 }
 for ((rb) = revoked_blob_tree_RB_MINMAX(&krl->revoked_sha256s, -1); (rb) != 
((void *)0)
; (rb) = revoked_blob_tree_RB_NEXT(rb)) {
  fp = tohex(rb->blob, rb->len);
  fprintf(f, "hash: SHA256:%s\n", fp);
  free(fp);
 }
 for ((rb) = revoked_blob_tree_RB_MINMAX(&krl->revoked_sha1s, -1); (rb) != 
((void *)0)
; (rb) = revoked_blob_tree_RB_NEXT(rb)) {




  fp = tohex(rb->blob, rb->len);
  fprintf(f, "# hash SHA1:%s\n", fp);
  free(fp);
 }

 for((rc) = ((&krl->revoked_certs)->tqh_first); (rc) != 
((void *)0)
; (rc) = ((rc)->entry.tqe_next)) {
  fputc('\n', f);
  if (rc->ca_key == 
                   ((void *)0)
                       )
   fprintf(f, "# Wildcard CA\n");
  else {
   if ((fp = sshkey_fingerprint(rc->ca_key,
       2, SSH_FP_DEFAULT)) == 
                                               ((void *)0)
                                                   ) {
    ret = -4;
    sshlog("krl.c", __func__, 1418, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "sshkey_fingerprint failed");
    continue;
   }
   fprintf(f, "# CA key %s %s\n",
       sshkey_ssh_name(rc->ca_key), fp);
   free(fp);
  }
  for ((rs) = revoked_serial_tree_RB_MINMAX(&rc->revoked_serials, -1); (rs) != 
 ((void *)0)
 ; (rs) = revoked_serial_tree_RB_NEXT(rs)) {
   if (rs->lo == rs->hi) {
    fprintf(f, "serial: %llu\n",
        (unsigned long long)rs->lo);
   } else {
    fprintf(f, "serial: %llu-%llu\n",
        (unsigned long long)rs->lo,
        (unsigned long long)rs->hi);
   }
  }
  for ((rki) = revoked_key_id_tree_RB_MINMAX(&rc->revoked_key_ids, -1); (rki) != 
 ((void *)0)
 ; (rki) = revoked_key_id_tree_RB_NEXT(rki)) {




   r = 0x7fffffff;
   asmprintf(&fp, 0x7fffffff, &r, "%s", rki->key_id);
   fprintf(f, "id: %s\n", fp);
   free(fp);
  }
 }
 return ret;
}
