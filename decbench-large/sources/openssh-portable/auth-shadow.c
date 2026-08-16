











































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






extern struct sshbuf *loginmsg;
int
auth_shadow_acctexpired(struct spwd *spw)
{
 time_t today;
 int daysleft;
 int r;

 today = time(
             ((void *)0)
                 ) / (24L * 60 * 60);
 daysleft = spw->sp_expire - today;
 sshlog("auth-shadow.c", __func__, 64, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s: today %d sp_expire %d days left %d", __func__, (int)today, (int)spw->sp_expire, daysleft)
                                   ;

 if (spw->sp_expire == -1) {
  sshlog("auth-shadow.c", __func__, 68, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "account expiration disabled");
 } else if (daysleft < 0) {
  sshlog("auth-shadow.c", __func__, 70, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Account %.100s has expired", spw->sp_namp);
  return 1;
 } else if (daysleft <= spw->sp_warn) {
  sshlog("auth-shadow.c", __func__, 73, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "account will expire in %d days", daysleft);
  if ((r = sshbuf_putf(loginmsg,
      "Your account will expire in %d day%s.\n", daysleft,
      daysleft == 1 ? "" : "s")) != 0)
   sshfatal("auth-shadow.c", __func__, 77, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s: buffer error: %s", __func__, ssh_err(r));
 }

 return 0;
}





int
auth_shadow_pwexpired(Authctxt *ctxt)
{
 struct spwd *spw = 
                   ((void *)0)
                       ;
 const char *user = ctxt->pw->pw_name;
 time_t today;
 int r, daysleft, disabled = 0;

 if ((spw = getspnam((char *)user)) == 
                                      ((void *)0)
                                          ) {
  sshlog("auth-shadow.c", __func__, 96, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Could not get shadow information for %.100s", user);
  return 0;
 }

 today = time(
             ((void *)0)
                 ) / (24L * 60 * 60);
 sshlog("auth-shadow.c", __func__, 101, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%s: today %d sp_lstchg %d sp_max %d", __func__, (int)today, (int)spw->sp_lstchg, (int)spw->sp_max)
                                           ;
 daysleft = spw->sp_lstchg + spw->sp_max - today;
 if (disabled) {
  sshlog("auth-shadow.c", __func__, 122, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "password expiration disabled");
 } else if (spw->sp_lstchg == 0) {
  sshlog("auth-shadow.c", __func__, 124, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "User %.100s password has expired (root forced)", user);
  return 1;
 } else if (spw->sp_max == -1) {
  sshlog("auth-shadow.c", __func__, 127, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "password expiration disabled");
 } else if (daysleft < 0) {
  sshlog("auth-shadow.c", __func__, 129, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "User %.100s password has expired (password aged)", user);
  return 1;
 } else if (daysleft <= spw->sp_warn) {
  sshlog("auth-shadow.c", __func__, 132, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "password will expire in %d days", daysleft);
  if ((r = sshbuf_putf(loginmsg,
      "Your password will expire in %d day%s.\n", daysleft,
      daysleft == 1 ? "" : "s")) != 0)
   sshfatal("auth-shadow.c", __func__, 136, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s: buffer error: %s", __func__, ssh_err(r));
 }

 return 0;
}
