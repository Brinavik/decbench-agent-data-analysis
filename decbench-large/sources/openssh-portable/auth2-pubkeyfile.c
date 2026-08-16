











































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

void compat_banner(struct ssh *, const char *);
char *compat_cipher_proposal(struct ssh *, char *);
char *compat_pkalg_proposal(struct ssh *, char *);
char *compat_kex_proposal(struct ssh *, char *);


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


int
auth_authorise_keyopts(struct passwd *pw, struct sshauthopt *opts,
    int allow_cert_authority, const char *remote_ip, const char *remote_host,
    const char *loc)
{
 time_t now = time(
                  ((void *)0)
                      );
 char buf[64];





 if (opts->valid_before && now > 0 &&
     opts->valid_before < (uint64_t)now) {
  format_absolute_time(opts->valid_before, buf, sizeof(buf));
  sshlog("auth2-pubkeyfile.c", __func__, 70, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%s: entry expired at %s", loc, buf);
  auth_debug_add("%s: entry expired at %s", loc, buf);
  return -1;
 }

 if (opts->cert_principals != 
                             ((void *)0) 
                                  && !opts->cert_authority) {
  sshlog("auth2-pubkeyfile.c", __func__, 76, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%s: principals on non-CA key", loc);
  auth_debug_add("%s: principals on non-CA key", loc);

  return -1;
 }

 if (!allow_cert_authority && opts->cert_authority) {
  sshlog("auth2-pubkeyfile.c", __func__, 83, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%s: cert-authority flag invalid here", loc);
  auth_debug_add("%s: cert-authority flag invalid here", loc);

  return -1;
 }


 if (opts->required_from_host_keys != 
                                     ((void *)0)
                                         ) {
  switch (match_host_and_ip(remote_host, remote_ip,
      opts->required_from_host_keys )) {
  case 1:

   break;
  case -1:
  default:
   sshlog("auth2-pubkeyfile.c", __func__, 98, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "%s: invalid from criteria", loc);
   auth_debug_add("%s: invalid from criteria", loc);

  case 0:
   sshlog("auth2-pubkeyfile.c", __func__, 102, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "%s: Authentication tried for %.100s with " "correct key but not from a permitted " "host (host=%.200s, ip=%.200s, required=%.200s).", loc, pw->pw_name, remote_host, remote_ip, opts->required_from_host_keys)



                                     ;
   auth_debug_add("%s: Your host '%.200s' is not "
       "permitted to use this key for login.",
       loc, remote_host);

   return -1;
  }
 }

 if (opts->required_from_host_cert != 
                                     ((void *)0)
                                         ) {
  switch (addr_match_cidr_list(remote_ip,
      opts->required_from_host_cert)) {
  case 1:

   break;
  case -1:
  default:

   sshlog("auth2-pubkeyfile.c", __func__, 124, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s: Certificate source-address invalid", loc);

  case 0:
   sshlog("auth2-pubkeyfile.c", __func__, 127, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "%s: Authentication tried for %.100s with valid " "certificate but not from a permitted source " "address (%.200s).", loc, pw->pw_name, remote_ip)

                                                        ;
   auth_debug_add("%s: Your address '%.200s' is not "
       "permitted to use this certificate for login.",
       loc, remote_ip);
   return -1;
  }
 }






 auth_log_authopts(loc, opts, 1);

 return 0;
}

static int
match_principals_option(const char *principal_list, struct sshkey_cert *cert)
{
 char *result;
 u_int i;



 for (i = 0; i < cert->nprincipals; i++) {
  if ((result = match_list(cert->principals[i],
      principal_list, 
                     ((void *)0)
                         )) != 
                               ((void *)0)
                                   ) {
   sshlog("auth2-pubkeyfile.c", __func__, 158, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "matched principal from key options \"%.100s\"", result)
              ;
   free(result);
   return 1;
  }
 }
 return 0;
}






int
auth_check_principals_line(char *cp, const struct sshkey_cert *cert,
    const char *loc, struct sshauthopt **authoptsp)
{
 u_int i, found = 0;
 char *ep, *line_opts;
 const char *reason = 
                     ((void *)0)
                         ;
 struct sshauthopt *opts = 
                          ((void *)0)
                              ;

 if (authoptsp != 
                 ((void *)0)
                     )
  *authoptsp = 
              ((void *)0)
                  ;


 ep = cp + strlen(cp) - 1;
 while (ep > cp && (*ep == '\n' || *ep == ' ' || *ep == '\t'))
  *ep-- = '\0';





 line_opts = 
            ((void *)0)
                ;
 if ((ep = strrchr(cp, ' ')) != 
                               ((void *)0) 
                                    ||
     (ep = strrchr(cp, '\t')) != 
                                ((void *)0)
                                    ) {
  for (; *ep == ' ' || *ep == '\t'; ep++)
   ;
  line_opts = cp;
  cp = ep;
 }
 if ((opts = sshauthopt_parse(line_opts, &reason)) == 
                                                     ((void *)0)
                                                         ) {
  sshlog("auth2-pubkeyfile.c", __func__, 202, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%s: bad principals options: %s", loc, reason);
  auth_debug_add("%s: bad principals options: %s", loc, reason);
  return -1;
 }

 for (i = 0; i < cert->nprincipals; i++) {
  if (strcmp(cp, cert->principals[i]) != 0)
   continue;
  sshlog("auth2-pubkeyfile.c", __func__, 210, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "%s: matched principal \"%.100s\"", loc, cert->principals[i])
                               ;
  found = 1;
 }
 if (found && authoptsp != 
                          ((void *)0)
                              ) {
  *authoptsp = opts;
  opts = 
        ((void *)0)
            ;
 }
 sshauthopt_free(opts);
 return found ? 0 : -1;
}

int
auth_process_principals(FILE *f, const char *file,
    const struct sshkey_cert *cert, struct sshauthopt **authoptsp)
{
 char loc[256], *line = 
                       ((void *)0)
                           , *cp, *ep;
 size_t linesize = 0;
 u_long linenum = 0, nonblank = 0;
 u_int found_principal = 0;

 if (authoptsp != 
                 ((void *)0)
                     )
  *authoptsp = 
              ((void *)0)
                  ;

 while (getline(&line, &linesize, f) != -1) {
  linenum++;

  if (found_principal)
   continue;


  for (cp = line; *cp == ' ' || *cp == '\t'; cp++)
   ;

  if ((ep = strchr(cp, '#')) != 
                               ((void *)0)
                                   )
   *ep = '\0';
  if (!*cp || *cp == '\n')
   continue;

  nonblank++;
  snprintf(loc, sizeof(loc), "%.200s:%lu", file, linenum);
  if (auth_check_principals_line(cp, cert, loc, authoptsp) == 0)
   found_principal = 1;
 }
 sshlog("auth2-pubkeyfile.c", __func__, 254, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "%s: processed %lu/%lu lines", file, nonblank, linenum);
 free(line);
 return found_principal;
}






int
auth_check_authkey_line(struct passwd *pw, struct sshkey *key,
    char *cp, const char *remote_ip, const char *remote_host, const char *loc,
    struct sshauthopt **authoptsp)
{
 int want_keytype = sshkey_is_cert(key) ? KEY_UNSPEC : key->type;
 struct sshkey *found = 
                       ((void *)0)
                           ;
 struct sshauthopt *keyopts = 
                             ((void *)0)
                                 , *certopts = 
                                               ((void *)0)
                                                   , *finalopts = 
                                                                  ((void *)0)
                                                                      ;
 char *key_options = 
                    ((void *)0)
                        , *fp = 
                                ((void *)0)
                                    ;
 const char *reason = 
                     ((void *)0)
                         ;
 int ret = -1;

 if (authoptsp != 
                 ((void *)0)
                     )
  *authoptsp = 
              ((void *)0)
                  ;

 if ((found = sshkey_new(want_keytype)) == 
                                          ((void *)0)
                                              ) {
  sshlog("auth2-pubkeyfile.c", __func__, 280, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "keytype %d failed", want_keytype);
  goto out;
 }



 if (sshkey_read(found, &cp) != 0) {

  sshlog("auth2-pubkeyfile.c", __func__, 288, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "%s: check options: '%s'", loc, cp);
  key_options = cp;
  if (sshkey_advance_past_options(&cp) != 0) {
   reason = "invalid key option string";
   goto fail_reason;
  }
  skip_space(&cp);
  if (sshkey_read(found, &cp) != 0) {

   sshlog("auth2-pubkeyfile.c", __func__, 297, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "%s: advance: '%s'", loc, cp);
   goto out;
  }
 }

 if ((keyopts = sshauthopt_parse(key_options, &reason)) == 
                                                          ((void *)0)
                                                              ) {
  sshlog("auth2-pubkeyfile.c", __func__, 303, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%s: bad key options: %s", loc, reason);
  auth_debug_add("%s: bad key options: %s", loc, reason);
  goto out;
 }

 if (sshkey_is_cert(key)) {

  if (!sshkey_equal(found, key->cert->signature_key) ||
      !keyopts->cert_authority)
   goto out;
 } else {

  if (!sshkey_equal(found, key) || keyopts->cert_authority)
   goto out;
 }


 if ((fp = sshkey_fingerprint(found,
     2, SSH_FP_DEFAULT)) == 
                                             ((void *)0)
                                                 )
  sshfatal("auth2-pubkeyfile.c", __func__, 322, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "fingerprint failed");

 sshlog("auth2-pubkeyfile.c", __func__, 324, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "%s: matching %s found: %s %s", loc, sshkey_is_cert(key) ? "CA" : "key", sshkey_type(found), fp)
                                                                ;

 if (auth_authorise_keyopts(pw, keyopts,
     sshkey_is_cert(key), remote_ip, remote_host, loc) != 0) {
  reason = "Refused by key options";
  goto fail_reason;
 }

 if (!sshkey_is_cert(key)) {
  sshlog("auth2-pubkeyfile.c", __func__, 334, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "Accepted key %s %s found at %s", sshkey_type(found), fp, loc)
                                  ;
  finalopts = keyopts;
  keyopts = 
           ((void *)0)
               ;
  goto success;
 }






 if ((certopts = sshauthopt_from_cert(key)) == 
                                              ((void *)0)
                                                  ) {
  reason = "Invalid certificate options";
  goto fail_reason;
 }
 if (auth_authorise_keyopts(pw, certopts, 0,
     remote_ip, remote_host, loc) != 0) {
  reason = "Refused by certificate options";
  goto fail_reason;
 }
 if ((finalopts = sshauthopt_merge(keyopts, certopts, &reason)) == 
                                                                  ((void *)0)
                                                                      )
  goto fail_reason;






 if (keyopts->cert_principals != 
                                ((void *)0) 
                                     &&
     !match_principals_option(keyopts->cert_principals, key->cert)) {
  reason = "Certificate does not contain an authorized principal";
  goto fail_reason;
 }
 if (sshkey_cert_check_authority_now(key, 0, 0, 0,
     keyopts->cert_principals == 
                                ((void *)0) 
                                     ? pw->pw_name : 
                                                     ((void *)0)
                                                         ,
     &reason) != 0)
  goto fail_reason;

 sshlog("auth2-pubkeyfile.c", __func__, 373, 0, SYSLOG_LEVEL_VERBOSE, 
((void *)0)
, "Accepted certificate ID \"%s\" (serial %llu) " "signed by CA %s %s found at %s", key->cert->key_id, (unsigned long long)key->cert->serial, sshkey_type(found), fp, loc)



                                 ;

 success:
 if (finalopts == 
                 ((void *)0)
                     )
  sshfatal("auth2-pubkeyfile.c", __func__, 381, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "internal error: missing options");
 if (authoptsp != 
                 ((void *)0)
                     ) {
  *authoptsp = finalopts;
  finalopts = 
             ((void *)0)
                 ;
 }

 ret = 0;
 goto out;

 fail_reason:
 sshlog("auth2-pubkeyfile.c", __func__, 391, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "%s", reason);
 auth_debug_add("%s", reason);
 out:
 free(fp);
 sshauthopt_free(keyopts);
 sshauthopt_free(certopts);
 sshauthopt_free(finalopts);
 sshkey_free(found);
 return ret;
}





int
auth_check_authkeys_file(struct passwd *pw, FILE *f, char *file,
    struct sshkey *key, const char *remote_ip,
    const char *remote_host, struct sshauthopt **authoptsp)
{
 char *cp, *line = 
                  ((void *)0)
                      , loc[256];
 size_t linesize = 0;
 int found_key = 0;
 u_long linenum = 0, nonblank = 0;

 if (authoptsp != 
                 ((void *)0)
                     )
  *authoptsp = 
              ((void *)0)
                  ;

 while (getline(&line, &linesize, f) != -1) {
  linenum++;

  if (found_key)
   continue;


  cp = line;
  skip_space(&cp);
  if (!*cp || *cp == '\n' || *cp == '#')
   continue;

  nonblank++;
  snprintf(loc, sizeof(loc), "%.200s:%lu", file, linenum);
  if (auth_check_authkey_line(pw, key, cp,
      remote_ip, remote_host, loc, authoptsp) == 0)
   found_key = 1;
 }
 free(line);
 sshlog("auth2-pubkeyfile.c", __func__, 438, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "%s: processed %lu/%lu lines", file, nonblank, linenum);
 return found_key;
}

static FILE *
auth_openfile(const char *file, struct passwd *pw, int strict_modes,
    int log_missing, char *file_type)
{
 char line[1024];
 struct stat st;
 int fd;
 FILE *f;

 if ((fd = open(file, 
                     00
                             |
                              04000
                                        )) == -1) {
  if (
     (*__errno_location ()) 
           != 
              2
                    ) {
   sshlog("auth2-pubkeyfile.c", __func__, 453, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Could not open user '%s' %s '%s': %s", pw->pw_name, file_type, file, strerror(
  (*__errno_location ())
  ))
                                                     ;
  } else if (log_missing) {
   sshlog("auth2-pubkeyfile.c", __func__, 456, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Could not open user '%s' %s '%s': %s", pw->pw_name, file_type, file, strerror(
  (*__errno_location ())
  ))
                                                     ;
  }
  return 
        ((void *)0)
            ;
 }

 if (fstat(fd, &st) == -1) {
  close(fd);
  return 
        ((void *)0)
            ;
 }
 if (!
     ((((
     st.st_mode
     )) & 0170000) == (0100000))
                        ) {
  sshlog("auth2-pubkeyfile.c", __func__, 467, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "User '%s' %s '%s' is not a regular file", pw->pw_name, file_type, file)
                                   ;
  close(fd);
  return 
        ((void *)0)
            ;
 }
 unset_nonblock(fd);
 if ((f = fdopen(fd, "r")) == 
                             ((void *)0)
                                 ) {
  close(fd);
  return 
        ((void *)0)
            ;
 }
 if (strict_modes &&
     safe_path_fd(fileno(f), file, pw, line, sizeof(line)) != 0) {
  fclose(f);
  sshlog("auth2-pubkeyfile.c", __func__, 480, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Authentication refused: %s", line);
  auth_debug_add("Ignored %s: %s", file_type, line);
  return 
        ((void *)0)
            ;
 }

 return f;
}


FILE *
auth_openkeyfile(const char *file, struct passwd *pw, int strict_modes)
{
 return auth_openfile(file, pw, strict_modes, 1, "authorized keys");
}

FILE *
auth_openprincipals(const char *file, struct passwd *pw, int strict_modes)
{
 return auth_openfile(file, pw, strict_modes, 0,
     "authorized principals");
}
