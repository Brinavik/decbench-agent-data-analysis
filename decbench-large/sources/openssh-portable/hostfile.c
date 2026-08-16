











































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
size_t ssh_hmac_bytes(int alg);

struct sshbuf;
struct ssh_hmac_ctx;
struct ssh_hmac_ctx *ssh_hmac_start(int alg);


int ssh_hmac_init(struct ssh_hmac_ctx *ctx, const void *key, size_t klen)
 __attribute__(());
int ssh_hmac_update(struct ssh_hmac_ctx *ctx, const void *m, size_t mlen)
 __attribute__(());
int ssh_hmac_update_buffer(struct ssh_hmac_ctx *ctx, const struct sshbuf *b);
int ssh_hmac_final(struct ssh_hmac_ctx *ctx, u_char *d, size_t dlen)
 __attribute__(());
void ssh_hmac_free(struct ssh_hmac_ctx *ctx);
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



static int
extract_salt(const char *s, u_int l, u_char *salt, size_t salt_len)
{
 char *p, *b64salt;
 u_int b64len;
 int ret;

 if (l < sizeof("|1|") - 1) {
  sshlog("hostfile.c", __func__, 76, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "extract_salt: string too short");
  return (-1);
 }
 if (strncmp(s, "|1|", sizeof("|1|") - 1) != 0) {
  sshlog("hostfile.c", __func__, 80, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "extract_salt: invalid magic identifier");
  return (-1);
 }
 s += sizeof("|1|") - 1;
 l -= sizeof("|1|") - 1;
 if ((p = memchr(s, '|', l)) == 
                                      ((void *)0)
                                          ) {
  sshlog("hostfile.c", __func__, 86, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "extract_salt: missing salt termination character");
  return (-1);
 }

 b64len = p - s;

 if (b64len == 0 || b64len > 1024) {
  sshlog("hostfile.c", __func__, 93, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "extract_salt: bad encoded salt length %u", b64len);
  return (-1);
 }
 b64salt = xmalloc(1 + b64len);
 memcpy(b64salt, s, b64len);
 b64salt[b64len] = '\0';

 ret = 
      __b64_pton
      (b64salt,salt,salt_len);
 free(b64salt);
 if (ret == -1) {
  sshlog("hostfile.c", __func__, 103, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "extract_salt: salt decode error");
  return (-1);
 }
 if (ret != (int)ssh_hmac_bytes(1)) {
  sshlog("hostfile.c", __func__, 107, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "extract_salt: expected salt len %zd, got %d", ssh_hmac_bytes(1), ret)
                                           ;
  return (-1);
 }

 return (0);
}

char *
host_hash(const char *host, const char *name_from_hostfile, u_int src_len)
{
 struct ssh_hmac_ctx *ctx;
 u_char salt[256], result[256];
 char uu_salt[512], uu_result[512];
 char *encoded = 
                ((void *)0)
                    ;
 u_int len;

 len = ssh_digest_bytes(1);

 if (name_from_hostfile == 
                          ((void *)0)
                              ) {

  arc4random_buf(salt, len);
 } else {

  if (extract_salt(name_from_hostfile, src_len, salt,
      sizeof(salt)) == -1)
   return (
          ((void *)0)
              );
 }

 if ((ctx = ssh_hmac_start(1)) == 
                                               ((void *)0) 
                                                    ||
     ssh_hmac_init(ctx, salt, len) < 0 ||
     ssh_hmac_update(ctx, host, strlen(host)) < 0 ||
     ssh_hmac_final(ctx, result, sizeof(result)))
  sshfatal("hostfile.c", __func__, 140, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ssh_hmac failed");
 ssh_hmac_free(ctx);

 if (
    __b64_ntop
    (salt,len,uu_salt,sizeof(uu_salt)) == -1 ||
     
    __b64_ntop
    (result,len,uu_result,sizeof(uu_result)) == -1)
  sshfatal("hostfile.c", __func__, 145, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "__b64_ntop failed");
 xasprintf(&encoded, "%s%s%c%s", "|1|", uu_salt, '|',
     uu_result);

 return (encoded);
}






int
hostfile_read_key(char **cpp, u_int *bitsp, struct sshkey *ret)
{
 char *cp;


 for (cp = *cpp; *cp == ' ' || *cp == '\t'; cp++)
  ;

 if (sshkey_read(ret, &cp) != 0)
  return 0;


 for (; *cp == ' ' || *cp == '\t'; cp++)
  ;


 *cpp = cp;
 if (bitsp != 
             ((void *)0)
                 )
  *bitsp = sshkey_size(ret);
 return 1;
}

static HostkeyMarker
check_markers(char **cpp)
{
 char marker[32], *sp, *cp = *cpp;
 int ret = MRK_NONE;

 while (*cp == '@') {

  if (ret != MRK_NONE)
   return MRK_ERROR;

  if ((sp = strchr(cp, ' ')) == 
                               ((void *)0) 
                                    &&
      (sp = strchr(cp, '\t')) == 
                                ((void *)0)
                                    )
   return MRK_ERROR;

  if (sp <= cp + 1 || sp >= cp + sizeof(marker))
   return MRK_ERROR;
  memcpy(marker, cp, sp - cp);
  marker[sp - cp] = '\0';
  if (strcmp(marker, "@cert-authority") == 0)
   ret = MRK_CA;
  else if (strcmp(marker, "@revoked") == 0)
   ret = MRK_REVOKE;
  else
   return MRK_ERROR;


  cp = sp;
  for (; *cp == ' ' || *cp == '\t'; cp++)
   ;
 }
 *cpp = cp;
 return ret;
}

struct hostkeys *
init_hostkeys(void)
{
 struct hostkeys *ret = xcalloc(1, sizeof(*ret));

 ret->entries = 
               ((void *)0)
                   ;
 return ret;
}

struct load_callback_ctx {
 const char *host;
 u_long num_loaded;
 struct hostkeys *hostkeys;
};

static int
record_hostkey(struct hostkey_foreach_line *l, void *_ctx)
{
 struct load_callback_ctx *ctx = (struct load_callback_ctx *)_ctx;
 struct hostkeys *hostkeys = ctx->hostkeys;
 struct hostkey_entry *tmp;

 if (l->status == 1) {

  sshlog("hostfile.c", __func__, 239, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%s:%ld: parse error in hostkeys file", l->path, l->linenum)
                          ;
  return 0;
 }

 sshlog("hostfile.c", __func__, 244, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "found %skey type %s in file %s:%lu", l->marker == MRK_NONE ? "" : (l->marker == MRK_CA ? "ca " : "revoked "), sshkey_type(l->key), l->path, l->linenum)


                                              ;
 if ((tmp = recallocarray(hostkeys->entries, hostkeys->num_entries,
     hostkeys->num_entries + 1, sizeof(*hostkeys->entries))) == 
                                                               ((void *)0)
                                                                   )
  return -2;
 hostkeys->entries = tmp;
 hostkeys->entries[hostkeys->num_entries].host = xstrdup(ctx->host);
 hostkeys->entries[hostkeys->num_entries].file = xstrdup(l->path);
 hostkeys->entries[hostkeys->num_entries].line = l->linenum;
 hostkeys->entries[hostkeys->num_entries].key = l->key;
 l->key = 
         ((void *)0)
             ;
 hostkeys->entries[hostkeys->num_entries].marker = l->marker;
 hostkeys->entries[hostkeys->num_entries].note = l->note;
 hostkeys->num_entries++;
 ctx->num_loaded++;

 return 0;
}

void
load_hostkeys_file(struct hostkeys *hostkeys, const char *host,
    const char *path, FILE *f, u_int note)
{
 int r;
 struct load_callback_ctx ctx;

 ctx.host = host;
 ctx.num_loaded = 0;
 ctx.hostkeys = hostkeys;

 if ((r = hostkeys_foreach_file(path, f, record_hostkey, &ctx, host,
     
    ((void *)0)
        , (1)|(1<<1), note)) != 0) {
  if (r != -24 && 
                                  (*__errno_location ()) 
                                        != 
                                           2
                                                 )
   sshlog("hostfile.c", __func__, 279, 1, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "hostkeys_foreach failed for %s", path);
 }
 if (ctx.num_loaded != 0)
  sshlog("hostfile.c", __func__, 282, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "loaded %lu keys from %s", ctx.num_loaded, host);
}

void
load_hostkeys(struct hostkeys *hostkeys, const char *host, const char *path,
    u_int note)
{
 FILE *f;

 if ((f = fopen(path, "r")) == 
                              ((void *)0)
                                  ) {
  sshlog("hostfile.c", __func__, 292, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "fopen %s: %s", path, strerror(
 (*__errno_location ())
 ));
  return;
 }

 load_hostkeys_file(hostkeys, host, path, f, note);
 fclose(f);
}

void
free_hostkeys(struct hostkeys *hostkeys)
{
 u_int i;

 for (i = 0; i < hostkeys->num_entries; i++) {
  free(hostkeys->entries[i].host);
  free(hostkeys->entries[i].file);
  sshkey_free(hostkeys->entries[i].key);
  explicit_bzero(hostkeys->entries + i, sizeof(*hostkeys->entries));
 }
 free(hostkeys->entries);
 freezero(hostkeys, sizeof(*hostkeys));
}

static int
check_key_not_revoked(struct hostkeys *hostkeys, struct sshkey *k)
{
 int is_cert = sshkey_is_cert(k);
 u_int i;

 for (i = 0; i < hostkeys->num_entries; i++) {
  if (hostkeys->entries[i].marker != MRK_REVOKE)
   continue;
  if (sshkey_equal_public(k, hostkeys->entries[i].key))
   return -1;
  if (is_cert && k != 
                     ((void *)0) 
                          &&
      sshkey_equal_public(k->cert->signature_key,
      hostkeys->entries[i].key))
   return -1;
 }
 return 0;
}
static HostStatus
check_hostkeys_by_key_or_type(struct hostkeys *hostkeys,
    struct sshkey *k, int keytype, int nid, const struct hostkey_entry **found)
{
 u_int i;
 HostStatus end_return = HOST_NEW;
 int want_cert = sshkey_is_cert(k);
 HostkeyMarker want_marker = want_cert ? MRK_CA : MRK_NONE;

 if (found != 
             ((void *)0)
                 )
  *found = 
          ((void *)0)
              ;

 for (i = 0; i < hostkeys->num_entries; i++) {
  if (hostkeys->entries[i].marker != want_marker)
   continue;
  if (k == 
          ((void *)0)
              ) {
   if (hostkeys->entries[i].key->type != keytype)
    continue;
   if (nid != -1 &&
       sshkey_type_plain(keytype) == KEY_ECDSA &&
       hostkeys->entries[i].key->ecdsa_nid != nid)
    continue;
   end_return = HOST_FOUND;
   if (found != 
               ((void *)0)
                   )
    *found = hostkeys->entries + i;
   k = hostkeys->entries[i].key;
   break;
  }
  if (want_cert) {
   if (sshkey_equal_public(k->cert->signature_key,
       hostkeys->entries[i].key)) {

    end_return = HOST_OK;
    if (found != 
                ((void *)0)
                    )
     *found = hostkeys->entries + i;
    break;
   }
  } else {
   if (sshkey_equal(k, hostkeys->entries[i].key)) {
    end_return = HOST_OK;
    if (found != 
                ((void *)0)
                    )
     *found = hostkeys->entries + i;
    break;
   }

   end_return = HOST_CHANGED;
   if (found != 
               ((void *)0)
                   )
    *found = hostkeys->entries + i;
  }
 }
 if (check_key_not_revoked(hostkeys, k) != 0) {
  end_return = HOST_REVOKED;
  if (found != 
              ((void *)0)
                  )
   *found = 
           ((void *)0)
               ;
 }
 return end_return;
}

HostStatus
check_key_in_hostkeys(struct hostkeys *hostkeys, struct sshkey *key,
    const struct hostkey_entry **found)
{
 if (key == 
           ((void *)0)
               )
  sshfatal("hostfile.c", __func__, 412, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "no key to look up");
 return check_hostkeys_by_key_or_type(hostkeys, key, 0, -1, found);
}

int
lookup_key_in_hostkeys_by_type(struct hostkeys *hostkeys, int keytype, int nid,
    const struct hostkey_entry **found)
{
 return (check_hostkeys_by_key_or_type(hostkeys, 
                                                ((void *)0)
                                                    , keytype, nid,
     found) == HOST_FOUND);
}

int
lookup_marker_in_hostkeys(struct hostkeys *hostkeys, int want_marker)
{
 u_int i;

 for (i = 0; i < hostkeys->num_entries; i++) {
  if (hostkeys->entries[i].marker == (HostkeyMarker)want_marker)
   return 1;
 }
 return 0;
}

static int
write_host_entry(FILE *f, const char *host, const char *ip,
    const struct sshkey *key, int store_hash)
{
 int r, success = 0;
 char *hashed_host = 
                    ((void *)0)
                        , *lhost;

 lhost = xstrdup(host);
 lowercase(lhost);

 if (store_hash) {
  if ((hashed_host = host_hash(lhost, 
                                     ((void *)0)
                                         , 0)) == 
                                                  ((void *)0)
                                                      ) {
   sshlog("hostfile.c", __func__, 448, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "host_hash failed");
   free(lhost);
   return 0;
  }
  fprintf(f, "%s ", hashed_host);
 } else if (ip != 
                 ((void *)0)
                     )
  fprintf(f, "%s,%s ", lhost, ip);
 else {
  fprintf(f, "%s ", lhost);
 }
 free(hashed_host);
 free(lhost);
 if ((r = sshkey_write(key, f)) == 0)
  success = 1;
 else
  sshlog("hostfile.c", __func__, 463, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshkey_write");
 fputc('\n', f);

 if (success && store_hash && ip != 
                                   ((void *)0)
                                       )
  success = write_host_entry(f, ip, 
                                   ((void *)0)
                                       , key, 1);
 return success;
}





void
hostfile_create_user_ssh_dir(const char *filename, int notify)
{
 char *dotsshdir = 
                  ((void *)0)
                      , *p;
 size_t len;
 struct stat st;

 if ((p = strrchr(filename, '/')) == 
                                    ((void *)0)
                                        )
  return;
 len = p - filename;
 dotsshdir = tilde_expand_filename("~/" ".ssh", getuid());
 if (strlen(dotsshdir) > len || strncmp(filename, dotsshdir, len) != 0)
  goto out;
 if (stat(dotsshdir, &st) == 0)
  goto out;
 else if (
         (*__errno_location ()) 
               != 
                  2
                        )
  sshlog("hostfile.c", __func__, 491, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Could not stat %s: %s", dotsshdir, strerror(
 (*__errno_location ())
 ));
 else {



  if (mkdir(dotsshdir, 0700) == -1)
   sshlog("hostfile.c", __func__, 497, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Could not create directory '%.200s' (%s).", dotsshdir, strerror(
  (*__errno_location ())
  ))
                                  ;
  else if (notify)
   sshlog("hostfile.c", __func__, 500, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Created directory '%s'.", dotsshdir);



 }
 out:
 free(dotsshdir);
}





int
add_host_to_hostfile(const char *filename, const char *host,
    const struct sshkey *key, int store_hash)
{
 FILE *f;
 int success;

 if (key == 
           ((void *)0)
               )
  return 1;
 hostfile_create_user_ssh_dir(filename, 0);
 f = fopen(filename, "a");
 if (!f)
  return 0;
 success = write_host_entry(f, host, 
                                    ((void *)0)
                                        , key, store_hash);
 fclose(f);
 return success;
}

struct host_delete_ctx {
 FILE *out;
 int quiet;
 const char *host, *ip;
 u_int *match_keys;
 struct sshkey * const *keys;
 size_t nkeys;
 int modified;
};

static int
host_delete(struct hostkey_foreach_line *l, void *_ctx)
{
 struct host_delete_ctx *ctx = (struct host_delete_ctx *)_ctx;
 int loglevel = ctx->quiet ? SYSLOG_LEVEL_DEBUG1 : SYSLOG_LEVEL_VERBOSE;
 size_t i;


 if (l->status == 3 && l->marker == MRK_NONE) {





  for (i = 0; i < ctx->nkeys; i++) {
   if (!sshkey_equal(ctx->keys[i], l->key))
    continue;
   ctx->match_keys[i] |= l->match;
   fprintf(ctx->out, "%s\n", l->line);
   sshlog("hostfile.c", __func__, 560, 1, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "%s key already at %s:%ld", sshkey_type(l->key), l->path, l->linenum)
                                                ;
   return 0;
  }





  sshlog("hostfile.c", __func__, 569, 0, loglevel, 
 ((void *)0)
 , "%s%s%s:%ld: Removed %s key for host %s", ctx->quiet ? __func__ : "", ctx->quiet ? ": " : "", l->path, l->linenum, sshkey_type(l->key), ctx->host)

                                                          ;
  ctx->modified = 1;
  return 0;
 }

 if (l->status == 1) {
  sshlog("hostfile.c", __func__, 577, 0, loglevel, 
 ((void *)0)
 , "%s%s%s:%ld: invalid known_hosts entry", ctx->quiet ? __func__ : "", ctx->quiet ? ": " : "", l->path, l->linenum)

                          ;
 }
 fprintf(ctx->out, "%s\n", l->line);
 return 0;
}

int
hostfile_replace_entries(const char *filename, const char *host, const char *ip,
    struct sshkey **keys, size_t nkeys, int store_hash, int quiet, int hash_alg)
{
 int r, fd, oerrno = 0;
 int loglevel = quiet ? SYSLOG_LEVEL_DEBUG1 : SYSLOG_LEVEL_VERBOSE;
 struct host_delete_ctx ctx;
 char *fp, *temp = 
                  ((void *)0)
                      , *back = 
                                ((void *)0)
                                    ;
 const char *what;
 mode_t omask;
 size_t i;
 u_int want;

 omask = umask(077);

 memset(&ctx, 0, sizeof(ctx));
 ctx.host = host;
 ctx.ip = ip;
 ctx.quiet = quiet;

 if ((ctx.match_keys = calloc(nkeys, sizeof(*ctx.match_keys))) == 
                                                                 ((void *)0)
                                                                     )
  return -2;
 ctx.keys = keys;
 ctx.nkeys = nkeys;
 ctx.modified = 0;




 if ((r = asprintf(&temp, "%s.XXXXXXXXXXX", filename)) == -1 ||
     (r = asprintf(&back, "%s.old", filename)) == -1) {
  r = -2;
  goto fail;
 }

 if ((fd = mkstemp(temp)) == -1) {
  oerrno = 
          (*__errno_location ())
               ;
  sshlog("hostfile.c", __func__, 622, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "mkstemp: %s", strerror(oerrno));
  r = -24;
  goto fail;
 }
 if ((ctx.out = fdopen(fd, "w")) == 
                                   ((void *)0)
                                       ) {
  oerrno = 
          (*__errno_location ())
               ;
  close(fd);
  sshlog("hostfile.c", __func__, 629, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "fdopen: %s", strerror(oerrno));
  r = -24;
  goto fail;
 }


 if ((r = hostkeys_foreach(filename, host_delete, &ctx, host, ip,
     (1<<1), 0)) != 0) {
  oerrno = 
          (*__errno_location ())
               ;
  sshlog("hostfile.c", __func__, 638, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "hostkeys_foreach");
  goto fail;
 }


 want = (1) | (ip == 
                               ((void *)0) 
                                    ? 0 : (1<<1));
 for (i = 0; i < nkeys; i++) {
  if (keys[i] == 
                ((void *)0) 
                     || (want & ctx.match_keys[i]) == want)
   continue;
  if ((fp = sshkey_fingerprint(keys[i], hash_alg,
      SSH_FP_DEFAULT)) == 
                         ((void *)0)
                             ) {
   r = -2;
   goto fail;
  }

  what = "";
  if (ctx.match_keys[i] == 0) {
   what = "Adding new key";
   if (!write_host_entry(ctx.out, host, ip,
       keys[i], store_hash)) {
    r = -1;
    goto fail;
   }
  } else if ((want & ~ctx.match_keys[i]) == (1)) {
   what = "Fixing match (hostname)";
   if (!write_host_entry(ctx.out, host, 
                                       ((void *)0)
                                           ,
       keys[i], store_hash)) {
    r = -1;
    goto fail;
   }
  } else if ((want & ~ctx.match_keys[i]) == (1<<1)) {
   what = "Fixing match (address)";
   if (!write_host_entry(ctx.out, ip, 
                                     ((void *)0)
                                         ,
       keys[i], store_hash)) {
    r = -1;
    goto fail;
   }
  }
  sshlog("hostfile.c", __func__, 676, 0, loglevel, 
 ((void *)0)
 , "%s%s%s for %s%s%s to %s: %s %s", quiet ? __func__ : "", quiet ? ": " : "", what, host, ip == 
 ((void *)0) 
 ? "" : ",", ip == 
 ((void *)0) 
 ? "" : ip, filename, sshkey_ssh_name(keys[i]), fp)


                                   ;
  free(fp);
  ctx.modified = 1;
 }
 fclose(ctx.out);
 ctx.out = 
          ((void *)0)
              ;

 if (ctx.modified) {

  if (unlink(back) == -1 && 
                           (*__errno_location ()) 
                                 != 
                                    2
                                          ) {
   oerrno = 
           (*__errno_location ())
                ;
   sshlog("hostfile.c", __func__, 690, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "unlink %.100s: %s", back, strerror(
  (*__errno_location ())
  ));
   r = -24;
   goto fail;
  }
  if (link(filename, back) == -1) {
   oerrno = 
           (*__errno_location ())
                ;
   sshlog("hostfile.c", __func__, 696, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "link %.100s to %.100s: %s", filename, back, strerror(
  (*__errno_location ())
  ))
                             ;
   r = -24;
   goto fail;
  }
  if (rename(temp, filename) == -1) {
   oerrno = 
           (*__errno_location ())
                ;
   sshlog("hostfile.c", __func__, 703, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "rename \"%s\" to \"%s\": %s", temp, filename, strerror(
  (*__errno_location ())
  ))
                                 ;
   r = -24;
   goto fail;
  }
 } else {

  if (unlink(temp) != 0)
   sshlog("hostfile.c", __func__, 711, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "unlink \"%s\": %s", temp, strerror(
  (*__errno_location ())
  ));
 }


 r = 0;
 fail:
 if (temp != 
            ((void *)0) 
                 && r != 0)
  unlink(temp);
 free(temp);
 free(back);
 if (ctx.out != 
               ((void *)0)
                   )
  fclose(ctx.out);
 free(ctx.match_keys);
 umask(omask);
 if (r == -24)
  
 (*__errno_location ()) 
       = oerrno;
 return r;
}

static int
match_maybe_hashed(const char *host, const char *names, int *was_hashed)
{
 int hashed = *names == '|', ret;
 char *hashed_host = 
                    ((void *)0)
                        ;
 size_t nlen = strlen(names);

 if (was_hashed != 
                  ((void *)0)
                      )
  *was_hashed = hashed;
 if (hashed) {
  if ((hashed_host = host_hash(host, names, nlen)) == 
                                                     ((void *)0)
                                                         )
   return -1;
  ret = (nlen == strlen(hashed_host) &&
      strncmp(hashed_host, names, nlen) == 0);
  free(hashed_host);
  return ret;
 }
 return match_hostname(host, names) == 1;
}

int
hostkeys_foreach_file(const char *path, FILE *f, hostkeys_foreach_fn *callback,
    void *ctx, const char *host, const char *ip, u_int options, u_int note)
{
 char *line = 
             ((void *)0)
                 , ktype[128];
 u_long linenum = 0;
 char *cp, *cp2;
 u_int kbits;
 int hashed;
 int s, r = 0;
 struct hostkey_foreach_line lineinfo;
 size_t linesize = 0, l;

 memset(&lineinfo, 0, sizeof(lineinfo));
 if (host == 
            ((void *)0) 
                 && (options & (1)) != 0)
  return -10;

 while (getline(&line, &linesize, f) != -1) {
  linenum++;
  line[strcspn(line, "\n")] = '\0';

  free(lineinfo.line);
  sshkey_free(lineinfo.key);
  memset(&lineinfo, 0, sizeof(lineinfo));
  lineinfo.path = path;
  lineinfo.linenum = linenum;
  lineinfo.line = xstrdup(line);
  lineinfo.marker = MRK_NONE;
  lineinfo.status = 0;
  lineinfo.keytype = KEY_UNSPEC;
  lineinfo.note = note;


  for (cp = line; *cp == ' ' || *cp == '\t'; cp++)
   ;
  if (!*cp || *cp == '#' || *cp == '\n') {
   if ((options & (1)) == 0) {
    lineinfo.status = 2;
    if ((r = callback(&lineinfo, ctx)) != 0)
     break;
   }
   continue;
  }

  if ((lineinfo.marker = check_markers(&cp)) == MRK_ERROR) {
   sshlog("hostfile.c", __func__, 795, 1, SYSLOG_LEVEL_VERBOSE, 
  ((void *)0)
  , "invalid marker at %s:%lu", path, linenum);
   if ((options & (1)) == 0)
    goto bad;
   continue;
  }


  for (cp2 = cp; *cp2 && *cp2 != ' ' && *cp2 != '\t'; cp2++)
   ;
  lineinfo.hosts = cp;
  *cp2++ = '\0';


  if (host != 
             ((void *)0)
                 ) {
   if ((s = match_maybe_hashed(host, lineinfo.hosts,
       &hashed)) == -1) {
    sshlog("hostfile.c", __func__, 811, 1, SYSLOG_LEVEL_DEBUG2, 
   ((void *)0)
   , "%s:%ld: bad host hash \"%.32s\"", path, linenum, lineinfo.hosts)
                                      ;
    goto bad;
   }
   if (s == 1) {
    lineinfo.status = 3;
    lineinfo.match |= (1) |
        (hashed ? (1<<2) : 0);
   }

   if (ip != 
            ((void *)0)
                ) {
    if ((s = match_maybe_hashed(ip, lineinfo.hosts,
        &hashed)) == -1) {
     sshlog("hostfile.c", __func__, 824, 1, SYSLOG_LEVEL_DEBUG2, 
    ((void *)0)
    , "%s:%ld: bad ip hash " "\"%.32s\"", path, linenum, lineinfo.hosts)

                        ;
     goto bad;
    }
    if (s == 1) {
     lineinfo.status = 3;
     lineinfo.match |= (1<<1) |
         (hashed ? (1<<3) : 0);
    }
   }




   if ((options & (1)) != 0 &&
       lineinfo.status != 3)
    continue;
  }


  for (; *cp2 == ' ' || *cp2 == '\t'; cp2++)
   ;
  if (*cp2 == '\0' || *cp2 == '#') {
   sshlog("hostfile.c", __func__, 848, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "%s:%ld: truncated before key type", path, linenum)
                     ;
   goto bad;
  }
  lineinfo.rawkey = cp = cp2;

  if ((options & (1<<1)) != 0) {





   if ((lineinfo.key = sshkey_new(KEY_UNSPEC)) == 
                                                 ((void *)0)
                                                     ) {
    sshlog("hostfile.c", __func__, 861, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "sshkey_new failed");
    r = -2;
    break;
   }
   if (!hostfile_read_key(&cp, &kbits, lineinfo.key)) {
    goto bad;
   }
   lineinfo.keytype = lineinfo.key->type;
   lineinfo.comment = cp;
  } else {

   l = strcspn(lineinfo.rawkey, " \t");
   if (l <= 1 || l >= sizeof(ktype) ||
       lineinfo.rawkey[l] == '\0')
    goto bad;
   memcpy(ktype, lineinfo.rawkey, l);
   ktype[l] = '\0';
   lineinfo.keytype = sshkey_type_from_name(ktype);





   if (lineinfo.keytype == KEY_UNSPEC && l < 8 &&
       strspn(ktype, "0123456789") == l)
    goto bad;






   cp2 += l;
   for (; *cp2 == ' ' || *cp2 == '\t'; cp2++)
    ;
   if (*cp2 == '\0' || *cp2 == '#') {
    sshlog("hostfile.c", __func__, 897, 0, SYSLOG_LEVEL_DEBUG2, 
   ((void *)0)
   , "%s:%ld: truncated after key type", path, linenum)
                      ;
    lineinfo.keytype = KEY_UNSPEC;
   }
   if (lineinfo.keytype == KEY_UNSPEC) {
 bad:
    sshkey_free(lineinfo.key);
    lineinfo.key = 
                  ((void *)0)
                      ;
    lineinfo.status = 1;
    if ((r = callback(&lineinfo, ctx)) != 0)
     break;
    continue;
   }
  }
  if ((r = callback(&lineinfo, ctx)) != 0)
   break;
 }
 sshkey_free(lineinfo.key);
 free(lineinfo.line);
 free(line);
 return r;
}

int
hostkeys_foreach(const char *path, hostkeys_foreach_fn *callback, void *ctx,
    const char *host, const char *ip, u_int options, u_int note)
{
 FILE *f;
 int r, oerrno;

 if ((f = fopen(path, "r")) == 
                              ((void *)0)
                                  )
  return -24;

 sshlog("hostfile.c", __func__, 930, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "reading file \"%s\"", path);
 r = hostkeys_foreach_file(path, f, callback, ctx, host, ip,
     options, note);
 oerrno = 
         (*__errno_location ())
              ;
 fclose(f);
 
(*__errno_location ()) 
      = oerrno;
 return r;
}
