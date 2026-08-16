











































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
int ssh_msg_send(int, u_char, struct sshbuf *);
int ssh_msg_recv(int, struct sshbuf *);
void temporarily_use_uid(struct passwd *);
void restore_uid(void);
void permanently_set_uid(struct passwd *);


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


extern char *__progname;

static struct sshbuf *reply_error(int r, char *fmt, ...)
    __attribute__((__format__ (printf, 2, 3)));

static struct sshbuf *
reply_error(int r, char *fmt, ...)
{
 char *msg;
 va_list ap;
 struct sshbuf *resp;

 
__builtin_va_start(
ap
,
fmt
)
                 ;
 xvasprintf(&msg, fmt, ap);
 
__builtin_va_end(
ap
)
          ;
 sshlog("ssh-sk-helper.c", __func__, 66, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "%s: %s", __progname, msg);
 free(msg);

 if (r >= 0)
  sshfatal("ssh-sk-helper.c", __func__, 70, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "invalid error code %d", r);

 if ((resp = sshbuf_new()) == 
                             ((void *)0)
                                 )
  sshfatal("ssh-sk-helper.c", __func__, 73, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: sshbuf_new failed", __progname);
 if (sshbuf_put_u32(resp, 0) != 0 ||
     sshbuf_put_u32(resp, (u_int)-r) != 0)
  sshfatal("ssh-sk-helper.c", __func__, 76, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: buffer error", __progname);
 return resp;
}


static void
null_empty(char **s)
{
 if (s == 
         ((void *)0) 
              || *s == 
                       ((void *)0) 
                            || **s != '\0')
  return;

 free(*s);
 *s = 
     ((void *)0)
         ;
}

static struct sshbuf *
process_sign(struct sshbuf *req)
{
 int r = -1;
 struct sshbuf *resp, *kbuf;
 struct sshkey *key = 
                     ((void *)0)
                         ;
 uint32_t compat;
 const u_char *message;
 u_char *sig = 
              ((void *)0)
                  ;
 size_t msglen, siglen = 0;
 char *provider = 
                 ((void *)0)
                     , *pin = 
                              ((void *)0)
                                  ;

 if ((r = sshbuf_froms(req, &kbuf)) != 0 ||
     (r = sshbuf_get_cstring(req, &provider, 
                                            ((void *)0)
                                                )) != 0 ||
     (r = sshbuf_get_string_direct(req, &message, &msglen)) != 0 ||
     (r = sshbuf_get_cstring(req, 
                                 ((void *)0)
                                     , 
                                       ((void *)0)
                                           )) != 0 ||
     (r = sshbuf_get_u32(req, &compat)) != 0 ||
     (r = sshbuf_get_cstring(req, &pin, 
                                       ((void *)0)
                                           )) != 0)
  sshfatal("ssh-sk-helper.c", __func__, 109, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s: parse", __progname);
 if (sshbuf_len(req) != 0)
  sshfatal("ssh-sk-helper.c", __func__, 111, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: trailing data in request", __progname);

 if ((r = sshkey_private_deserialize(kbuf, &key)) != 0)
  sshfatal("ssh-sk-helper.c", __func__, 114, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s: Unable to parse private key", __progname);
 if (!sshkey_is_sk(key)) {
  sshfatal("ssh-sk-helper.c", __func__, 116, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: Unsupported key type %s", __progname, sshkey_ssh_name(key))
                                       ;
 }

 sshlog("ssh-sk-helper.c", __func__, 120, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "ready to sign with key %s, provider %s: " "msg len %zu, compat 0x%lx", sshkey_type(key), provider, msglen, (u_long)compat)

                                      ;

 null_empty(&pin);

 if ((r = sshsk_sign(provider, key, &sig, &siglen,
     message, msglen, compat, pin)) != 0) {
  resp = reply_error(r, "Signing failed: %s", ssh_err(r));
  goto out;
 }

 if ((resp = sshbuf_new()) == 
                             ((void *)0)
                                 )
  sshfatal("ssh-sk-helper.c", __func__, 133, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: sshbuf_new failed", __progname);

 if ((r = sshbuf_put_u32(resp, 1)) != 0 ||
     (r = sshbuf_put_string(resp, sig, siglen)) != 0)
  sshfatal("ssh-sk-helper.c", __func__, 137, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s: compose", __progname);
 out:
 sshkey_free(key);
 sshbuf_free(kbuf);
 free(provider);
 if (sig != 
           ((void *)0)
               )
  freezero(sig, siglen);
 if (pin != 
           ((void *)0)
               )
  freezero(pin, strlen(pin));
 return resp;
}

static struct sshbuf *
process_enroll(struct sshbuf *req)
{
 int r;
 u_int type;
 char *provider, *application, *pin, *device, *userid;
 uint8_t flags;
 struct sshbuf *challenge, *attest, *kbuf, *resp;
 struct sshkey *key;

 if ((attest = sshbuf_new()) == 
                               ((void *)0) 
                                    ||
     (kbuf = sshbuf_new()) == 
                             ((void *)0)
                                 )
  sshfatal("ssh-sk-helper.c", __func__, 161, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: sshbuf_new failed", __progname);

 if ((r = sshbuf_get_u32(req, &type)) != 0 ||
     (r = sshbuf_get_cstring(req, &provider, 
                                            ((void *)0)
                                                )) != 0 ||
     (r = sshbuf_get_cstring(req, &device, 
                                          ((void *)0)
                                              )) != 0 ||
     (r = sshbuf_get_cstring(req, &application, 
                                               ((void *)0)
                                                   )) != 0 ||
     (r = sshbuf_get_cstring(req, &userid, 
                                          ((void *)0)
                                              )) != 0 ||
     (r = sshbuf_get_u8(req, &flags)) != 0 ||
     (r = sshbuf_get_cstring(req, &pin, 
                                       ((void *)0)
                                           )) != 0 ||
     (r = sshbuf_froms(req, &challenge)) != 0)
  sshfatal("ssh-sk-helper.c", __func__, 171, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s: parse", __progname);
 if (sshbuf_len(req) != 0)
  sshfatal("ssh-sk-helper.c", __func__, 173, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: trailing data in request", __progname);

 if (type > 0x7fffffff)
  sshfatal("ssh-sk-helper.c", __func__, 176, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: bad type %u", __progname, type);
 if (sshbuf_len(challenge) == 0) {
  sshbuf_free(challenge);
  challenge = 
             ((void *)0)
                 ;
 }
 null_empty(&device);
 null_empty(&userid);
 null_empty(&pin);

 if ((r = sshsk_enroll((int)type, provider, device, application, userid,
     flags, pin, challenge, &key, attest)) != 0) {
  resp = reply_error(r, "Enrollment failed: %s", ssh_err(r));
  goto out;
 }

 if ((resp = sshbuf_new()) == 
                             ((void *)0)
                                 )
  sshfatal("ssh-sk-helper.c", __func__, 192, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: sshbuf_new failed", __progname);
 if ((r = sshkey_private_serialize(key, kbuf)) != 0)
  sshfatal("ssh-sk-helper.c", __func__, 194, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s: encode key", __progname);
 if ((r = sshbuf_put_u32(resp, 2)) != 0 ||
     (r = sshbuf_put_stringb(resp, kbuf)) != 0 ||
     (r = sshbuf_put_stringb(resp, attest)) != 0)
  sshfatal("ssh-sk-helper.c", __func__, 198, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s: compose", __progname);

 out:
 sshkey_free(key);
 sshbuf_free(kbuf);
 sshbuf_free(attest);
 sshbuf_free(challenge);
 free(provider);
 free(application);
 if (pin != 
           ((void *)0)
               )
  freezero(pin, strlen(pin));

 return resp;
}

static struct sshbuf *
process_load_resident(struct sshbuf *req)
{
 int r;
 char *provider, *pin, *device;
 struct sshbuf *kbuf, *resp;
 struct sshsk_resident_key **srks = 
                                   ((void *)0)
                                       ;
 size_t nsrks = 0, i;
 u_int flags;

 if ((kbuf = sshbuf_new()) == 
                             ((void *)0)
                                 )
  sshfatal("ssh-sk-helper.c", __func__, 224, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: sshbuf_new failed", __progname);

 if ((r = sshbuf_get_cstring(req, &provider, 
                                            ((void *)0)
                                                )) != 0 ||
     (r = sshbuf_get_cstring(req, &device, 
                                          ((void *)0)
                                              )) != 0 ||
     (r = sshbuf_get_cstring(req, &pin, 
                                       ((void *)0)
                                           )) != 0 ||
     (r = sshbuf_get_u32(req, &flags)) != 0)
  sshfatal("ssh-sk-helper.c", __func__, 230, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s: parse", __progname);
 if (sshbuf_len(req) != 0)
  sshfatal("ssh-sk-helper.c", __func__, 232, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: trailing data in request", __progname);

 null_empty(&device);
 null_empty(&pin);

 if ((r = sshsk_load_resident(provider, device, pin, flags,
     &srks, &nsrks)) != 0) {
  resp = reply_error(r, "sshsk_load_resident failed: %s",
      ssh_err(r));
  goto out;
 }

 if ((resp = sshbuf_new()) == 
                             ((void *)0)
                                 )
  sshfatal("ssh-sk-helper.c", __func__, 245, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: sshbuf_new failed", __progname);

 if ((r = sshbuf_put_u32(resp, 3)) != 0)
  sshfatal("ssh-sk-helper.c", __func__, 248, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s: compose", __progname);

 for (i = 0; i < nsrks; i++) {
  sshlog("ssh-sk-helper.c", __func__, 251, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "key %zu %s %s uidlen %zu", i, sshkey_type(srks[i]->key), srks[i]->key->sk_application, srks[i]->user_id_len)

                           ;
  sshbuf_reset(kbuf);
  if ((r = sshkey_private_serialize(srks[i]->key, kbuf)) != 0)
   sshfatal("ssh-sk-helper.c", __func__, 256, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s: encode key", __progname);
  if ((r = sshbuf_put_stringb(resp, kbuf)) != 0 ||
      (r = sshbuf_put_cstring(resp, "")) != 0 ||
      (r = sshbuf_put_string(resp, srks[i]->user_id,
      srks[i]->user_id_len)) != 0)
   sshfatal("ssh-sk-helper.c", __func__, 261, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s: compose key", __progname);
 }

 out:
 sshsk_free_resident_keys(srks, nsrks);
 sshbuf_free(kbuf);
 free(provider);
 free(device);
 if (pin != 
           ((void *)0)
               )
  freezero(pin, strlen(pin));
 return resp;
}

int
main(int argc, char **argv)
{
 SyslogFacility log_facility = SYSLOG_FACILITY_AUTH;
 LogLevel log_level = SYSLOG_LEVEL_ERROR;
 struct sshbuf *req, *resp;
 int in, out, ch, r, vflag = 0;
 u_int rtype, ll = 0;
 uint8_t version, log_stderr = 0;

 sanitise_stdfd();
 log_init(__progname, log_level, log_facility, log_stderr);

 while ((ch = BSDgetopt(argc, argv, "v")) != -1) {
  switch (ch) {
  case 'v':
   vflag = 1;
   if (log_level == SYSLOG_LEVEL_ERROR)
    log_level = SYSLOG_LEVEL_DEBUG1;
   else if (log_level < SYSLOG_LEVEL_DEBUG3)
    log_level++;
   break;
  default:
   fprintf(
          stderr
                , "usage: %s [-v]\n", __progname);
   exit(1);
  }
 }
 log_init(__progname, log_level, log_facility, vflag);





 closefrom(
          2 
                        + 1);
 if ((in = dup(
              0
                          )) == -1 || (out = dup(
                                                 1
                                                              )) == -1)
  sshfatal("ssh-sk-helper.c", __func__, 309, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: dup: %s", __progname, strerror(
 (*__errno_location ())
 ));
 close(
      0
                  );
 close(
      1
                   );
 sanitise_stdfd();

 if ((req = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("ssh-sk-helper.c", __func__, 315, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: sshbuf_new failed", __progname);
 if (ssh_msg_recv(in, req) < 0)
  sshfatal("ssh-sk-helper.c", __func__, 317, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ssh_msg_recv failed");
 close(in);
 sshlog("ssh-sk-helper.c", __func__, 319, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "received message len %zu", sshbuf_len(req));

 if ((r = sshbuf_get_u8(req, &version)) != 0)
  sshfatal("ssh-sk-helper.c", __func__, 322, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s: parse version", __progname);
 if (version != 5) {
  sshfatal("ssh-sk-helper.c", __func__, 324, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "unsupported version: received %d, expected %d", version, 5)
                                     ;
 }

 if ((r = sshbuf_get_u32(req, &rtype)) != 0 ||
     (r = sshbuf_get_u8(req, &log_stderr)) != 0 ||
     (r = sshbuf_get_u32(req, &ll)) != 0)
  sshfatal("ssh-sk-helper.c", __func__, 331, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s: parse", __progname);

 if (!vflag && log_level_name((LogLevel)ll) != 
                                              ((void *)0)
                                                  )
  log_init(__progname, (LogLevel)ll, log_facility, log_stderr);

 switch (rtype) {
 case 1:
  resp = process_sign(req);
  break;
 case 2:
  resp = process_enroll(req);
  break;
 case 3:
  resp = process_load_resident(req);
  break;
 default:
  sshfatal("ssh-sk-helper.c", __func__, 347, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: unsupported request type %u", __progname, rtype);
 }
 sshbuf_free(req);
 sshlog("ssh-sk-helper.c", __func__, 350, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "reply len %zu", sshbuf_len(resp));

 if (ssh_msg_send(out, 5, resp) == -1)
  sshfatal("ssh-sk-helper.c", __func__, 353, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ssh_msg_send failed");
 sshbuf_free(resp);
 close(out);

 return (0);
}
