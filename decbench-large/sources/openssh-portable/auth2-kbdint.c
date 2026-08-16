











































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



struct kex;
struct sshkey;
struct sshbuf;
struct session_state;

enum {
 DISPATCH_BLOCK,
 DISPATCH_NONBLOCK
};

struct ssh;

typedef int dispatch_fn(int, u_int32_t, struct ssh *);

int dispatch_protocol_error(int, u_int32_t, struct ssh *);
int dispatch_protocol_ignore(int, u_int32_t, struct ssh *);
void ssh_dispatch_init(struct ssh *, dispatch_fn *);
void ssh_dispatch_set(struct ssh *, int, dispatch_fn *);
void ssh_dispatch_range(struct ssh *, u_int, u_int, dispatch_fn *);
int ssh_dispatch_run(struct ssh *, int, volatile sig_atomic_t *);
void ssh_dispatch_run_fatal(struct ssh *, int, volatile sig_atomic_t *);

struct key_entry {
 struct { struct key_entry *tqe_next; struct key_entry **tqe_prev; } next;
 struct sshkey *key;
};

struct ssh {

 struct session_state *state;


 struct kex *kex;


 char *remote_ipaddr;
 int remote_port;
 char *local_ipaddr;
 int local_port;
 char *rdomain_in;


 char *log_preamble;


 dispatch_fn *dispatch[255];

 int dispatch_skip_packets;


 int compat;


 struct { struct key_entry *tqh_first; struct key_entry **tqh_last; } private_keys;
 struct { struct key_entry *tqh_first; struct key_entry **tqh_last; } public_keys;


 void *authctxt;


 struct ssh_channels *chanctxt;


 void *app_data;
};

typedef int (ssh_packet_hook_fn)(struct ssh *, struct sshbuf *,
    u_char *, void *);

struct ssh *ssh_alloc_session_state(void);
struct ssh *ssh_packet_set_connection(struct ssh *, int, int);
void ssh_packet_set_timeout(struct ssh *, int, int);
int ssh_packet_stop_discard(struct ssh *);
int ssh_packet_connection_af(struct ssh *);
void ssh_packet_set_nonblocking(struct ssh *);
int ssh_packet_get_connection_in(struct ssh *);
int ssh_packet_get_connection_out(struct ssh *);
void ssh_packet_close(struct ssh *);
void ssh_packet_set_input_hook(struct ssh *, ssh_packet_hook_fn *, void *);
void ssh_packet_clear_keys(struct ssh *);
void ssh_clear_newkeys(struct ssh *, int);

int ssh_packet_is_rekeying(struct ssh *);
int ssh_packet_check_rekey(struct ssh *);
void ssh_packet_set_protocol_flags(struct ssh *, u_int);
u_int ssh_packet_get_protocol_flags(struct ssh *);
void ssh_packet_set_tos(struct ssh *, int);
void ssh_packet_set_interactive(struct ssh *, int, int, int);
int ssh_packet_is_interactive(struct ssh *);
void ssh_packet_set_server(struct ssh *);
void ssh_packet_set_authenticated(struct ssh *);
void ssh_packet_set_mux(struct ssh *);
int ssh_packet_get_mux(struct ssh *);
int ssh_packet_set_log_preamble(struct ssh *, const char *, ...)
    __attribute__((format(printf, 2, 3)));

int ssh_packet_log_type(u_char);

int ssh_packet_send2_wrapped(struct ssh *);
int ssh_packet_send2(struct ssh *);

int ssh_packet_read(struct ssh *);
int ssh_packet_read_expect(struct ssh *, u_int type);
int ssh_packet_read_poll(struct ssh *);
int ssh_packet_read_poll2(struct ssh *, u_char *, u_int32_t *seqnr_p);
int ssh_packet_process_incoming(struct ssh *, const char *buf, u_int len);
int ssh_packet_process_read(struct ssh *, int);
int ssh_packet_read_seqnr(struct ssh *, u_char *, u_int32_t *seqnr_p);
int ssh_packet_read_poll_seqnr(struct ssh *, u_char *, u_int32_t *seqnr_p);

const void *ssh_packet_get_string_ptr(struct ssh *, u_int *length_ptr);
void ssh_packet_disconnect(struct ssh *, const char *fmt, ...)
 __attribute__((format(printf, 2, 3)))
 __attribute__((noreturn));
void ssh_packet_send_debug(struct ssh *, const char *fmt, ...) __attribute__((format(printf, 2, 3)));

int ssh_set_newkeys(struct ssh *, int mode);
void ssh_packet_get_bytes(struct ssh *, u_int64_t *, u_int64_t *);

int ssh_packet_write_poll(struct ssh *);
int ssh_packet_write_wait(struct ssh *);
int ssh_packet_have_data_to_write(struct ssh *);
int ssh_packet_not_very_much_data_to_write(struct ssh *);

int ssh_packet_connection_is_on_socket(struct ssh *);
int ssh_packet_remaining(struct ssh *);

void ssh_tty_make_modes(struct ssh *, int, struct termios *);
void ssh_tty_parse_modes(struct ssh *, int);

void ssh_packet_set_alive_timeouts(struct ssh *, int);
int ssh_packet_inc_alive_timeouts(struct ssh *);
int ssh_packet_set_maxsize(struct ssh *, u_int);
u_int ssh_packet_get_maxsize(struct ssh *);

int ssh_packet_get_state(struct ssh *, struct sshbuf *);
int ssh_packet_set_state(struct ssh *, struct sshbuf *);

const char *ssh_remote_ipaddr(struct ssh *);
int ssh_remote_port(struct ssh *);
const char *ssh_local_ipaddr(struct ssh *);
int ssh_local_port(struct ssh *);
const char *ssh_packet_rdomain_in(struct ssh *);

void ssh_packet_set_rekey_limits(struct ssh *, u_int64_t, u_int32_t);
time_t ssh_packet_get_rekey_timeout(struct ssh *);

void *ssh_packet_get_input(struct ssh *);
void *ssh_packet_get_output(struct ssh *);


int sshpkt_start(struct ssh *ssh, u_char type);
int sshpkt_send(struct ssh *ssh);
int sshpkt_disconnect(struct ssh *, const char *fmt, ...)
     __attribute__((format(printf, 2, 3)));
int sshpkt_add_padding(struct ssh *, u_char);
void sshpkt_fatal(struct ssh *ssh, int r, const char *fmt, ...)
     __attribute__((format(printf, 3, 4)))
     __attribute__((noreturn));
int sshpkt_msg_ignore(struct ssh *, u_int);

int sshpkt_put(struct ssh *ssh, const void *v, size_t len);
int sshpkt_putb(struct ssh *ssh, const struct sshbuf *b);
int sshpkt_put_u8(struct ssh *ssh, u_char val);
int sshpkt_put_u32(struct ssh *ssh, u_int32_t val);
int sshpkt_put_u64(struct ssh *ssh, u_int64_t val);
int sshpkt_put_string(struct ssh *ssh, const void *v, size_t len);
int sshpkt_put_cstring(struct ssh *ssh, const void *v);
int sshpkt_put_stringb(struct ssh *ssh, const struct sshbuf *v);
int sshpkt_put_ec(struct ssh *ssh, const EC_POINT *v, const EC_GROUP *g);
int sshpkt_put_bignum2(struct ssh *ssh, const BIGNUM *v);

int sshpkt_get(struct ssh *ssh, void *valp, size_t len);
int sshpkt_get_u8(struct ssh *ssh, u_char *valp);
int sshpkt_get_u32(struct ssh *ssh, u_int32_t *valp);
int sshpkt_get_u64(struct ssh *ssh, u_int64_t *valp);
int sshpkt_get_string(struct ssh *ssh, u_char **valp, size_t *lenp);
int sshpkt_get_string_direct(struct ssh *ssh, const u_char **valp, size_t *lenp);
int sshpkt_peek_string_direct(struct ssh *ssh, const u_char **valp, size_t *lenp);
int sshpkt_get_cstring(struct ssh *ssh, char **valp, size_t *lenp);
int sshpkt_getb_froms(struct ssh *ssh, struct sshbuf **valp);
int sshpkt_get_ec(struct ssh *ssh, EC_POINT *v, const EC_GROUP *g);
int sshpkt_get_bignum2(struct ssh *ssh, BIGNUM **valp);
int sshpkt_get_end(struct ssh *ssh);
void sshpkt_fmt_connection_id(struct ssh *ssh, char *s, size_t l);
const u_char *sshpkt_ptr(struct ssh *, size_t *lenp);
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
struct fwd_perm_list;






struct queued_listenaddr {
 char *addr;
 int port;
 char *rdomain;
};


struct listenaddr {
 char *rdomain;
 struct addrinfo *addrs;
};

typedef struct {
 u_int num_ports;
 u_int ports_from_cmdline;
 int ports[256];
 struct queued_listenaddr *queued_listen_addrs;
 u_int num_queued_listens;
 struct listenaddr *listen_addrs;
 u_int num_listen_addrs;
 int address_family;

 char *routing_domain;

 char **host_key_files;
 int *host_key_file_userprovided;
 u_int num_host_key_files;
 char **host_cert_files;
 u_int num_host_cert_files;

 char *host_key_agent;
 char *pid_file;
 char *moduli_file;
 int login_grace_time;

 int permit_root_login;
 int ignore_rhosts;
 int ignore_user_known_hosts;

 int print_motd;
 int print_lastlog;
 int x11_forwarding;
 int x11_display_offset;

 int x11_use_localhost;
 char *xauth_location;
 int permit_tty;
 int permit_user_rc;
 int strict_modes;
 int tcp_keep_alive;
 int ip_qos_interactive;
 int ip_qos_bulk;
 char *ciphers;
 char *macs;
 char *kex_algorithms;
 struct ForwardOptions fwd_opts;
 SyslogFacility log_facility;
 LogLevel log_level;
 u_int num_log_verbose;
 char **log_verbose;
 int hostbased_authentication;
 int hostbased_uses_name_from_packet_only;
 char *hostbased_accepted_algos;
 char *hostkeyalgorithms;
 char *ca_sign_algorithms;
 int pubkey_authentication;
 char *pubkey_accepted_algos;
 int pubkey_auth_options;
 int kerberos_authentication;

 int kerberos_or_local_passwd;




 int kerberos_ticket_cleanup;

 int kerberos_get_afs_token;

 int gss_authentication;
 int gss_cleanup_creds;
 int gss_strict_acceptor;
 int password_authentication;

 int kbd_interactive_authentication;
 int permit_empty_passwd;

 int permit_user_env;
 char *permit_user_env_allowlist;
 int compression;
 int allow_tcp_forwarding;
 int allow_streamlocal_forwarding;
 int allow_agent_forwarding;
 int disable_forwarding;
 u_int num_allow_users;
 char **allow_users;
 u_int num_deny_users;
 char **deny_users;
 u_int num_allow_groups;
 char **allow_groups;
 u_int num_deny_groups;
 char **deny_groups;

 u_int num_subsystems;
 char *subsystem_name[256];
 char *subsystem_command[256];
 char *subsystem_args[256];

 u_int num_accept_env;
 char **accept_env;
 u_int num_setenv;
 char **setenv;

 int max_startups_begin;
 int max_startups_rate;
 int max_startups;
 int per_source_max_startups;
 int per_source_masklen_ipv4;
 int per_source_masklen_ipv6;
 int max_authtries;
 int max_sessions;
 char *banner;
 int use_dns;
 int client_alive_interval;



 int client_alive_count_max;





 u_int num_authkeys_files;
 char **authorized_keys_files;

 char *adm_forced_command;

 int use_pam;

 int permit_tun;

 char **permitted_opens;
 u_int num_permitted_opens;
 char **permitted_listens;
 u_int num_permitted_listens;

 char *chroot_directory;
 char *revoked_keys_file;
 char *trusted_user_ca_keys;
 char *authorized_keys_command;
 char *authorized_keys_command_user;
 char *authorized_principals_file;
 char *authorized_principals_command;
 char *authorized_principals_command_user;

 int64_t rekey_limit;
 int rekey_interval;

 char *version_addendum;

 u_int num_auth_methods;
 char **auth_methods;

 int fingerprint_hash;
 int expose_userauth_info;
 u_int64_t timing_secret;
 char *sk_provider;
 int required_rsa_size;
} ServerOptions;


struct connection_info {
 const char *user;
 const char *host;
 const char *address;
 const char *laddress;
 int lport;
 const char *rdomain;
 int test;

};


struct include_item {
 char *selector;
 char *filename;
 struct sshbuf *contents;
 struct { struct include_item *tqe_next; struct include_item **tqe_prev; } entry;
};
struct include_list { struct include_item *tqh_first; struct include_item **tqh_last; };
struct connection_info *get_connection_info(struct ssh *, int, int);
void initialize_server_options(ServerOptions *);
void fill_default_server_options(ServerOptions *);
int process_server_config_line(ServerOptions *, char *, const char *, int,
     int *, struct connection_info *, struct include_list *includes);
void process_permitopen(struct ssh *ssh, ServerOptions *options);
void load_server_config(const char *, struct sshbuf *);
void parse_server_config(ServerOptions *, const char *, struct sshbuf *,
     struct include_list *includes, struct connection_info *, int);
void parse_server_match_config(ServerOptions *,
     struct include_list *includes, struct connection_info *);
int parse_server_match_testspec(struct connection_info *, char *);
int server_match_spec_complete(struct connection_info *);
void copy_set_server_options(ServerOptions *, ServerOptions *, int);
void dump_config(ServerOptions *);
char *derelativise_path(const char *);
void servconf_add_hostkey(const char *, const int,
     ServerOptions *, const char *path, int);
void servconf_add_hostcert(const char *, const int,
     ServerOptions *, const char *path);



extern ServerOptions options;

static int
userauth_kbdint(struct ssh *ssh, const char *method)
{
 int r, authenticated = 0;
 char *lang, *devs;

 if ((r = sshpkt_get_cstring(ssh, &lang, 
                                        ((void *)0)
                                            )) != 0 ||
     (r = sshpkt_get_cstring(ssh, &devs, 
                                        ((void *)0)
                                            )) != 0 ||
     (r = sshpkt_get_end(ssh)) != 0)
  sshfatal("auth2-kbdint.c", __func__, 55, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse packet");

 sshlog("auth2-kbdint.c", __func__, 57, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "keyboard-interactive devs %s", devs);

 if (options.kbd_interactive_authentication)
  authenticated = auth2_challenge(ssh, devs);

 free(devs);
 free(lang);
 return authenticated;
}

Authmethod method_kbdint = {
 "keyboard-interactive",
 
((void *)0)
    ,
 userauth_kbdint,
 &options.kbd_interactive_authentication
};
