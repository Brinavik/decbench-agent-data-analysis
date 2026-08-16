











































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
struct Channel;
typedef struct Channel Channel;
struct fwd_perm_list;

typedef void channel_open_fn(struct ssh *, int, int, void *);
typedef void channel_callback_fn(struct ssh *, int, void *);
typedef int channel_infilter_fn(struct ssh *, struct Channel *, char *, int);
typedef void channel_filter_cleanup_fn(struct ssh *, int, void *);
typedef u_char *channel_outfilter_fn(struct ssh *, struct Channel *,
    u_char **, size_t *);


typedef void channel_confirm_cb(struct ssh *, int, struct Channel *, void *);
typedef void channel_confirm_abandon_cb(struct ssh *, struct Channel *, void *);
struct channel_confirm {
 struct { struct channel_confirm *tqe_next; struct channel_confirm **tqe_prev; } entry;
 channel_confirm_cb *cb;
 channel_confirm_abandon_cb *abandon_cb;
 void *ctx;
};
struct channel_confirms { struct channel_confirm *tqh_first; struct channel_confirm **tqh_last; };


struct channel_connect {
 char *host;
 int port;
 struct addrinfo *ai, *aitop;
};


typedef int mux_callback_fn(struct ssh *, struct Channel *);
struct Channel {
 int type;

 int self;
 uint32_t remote_id;
 int have_remote_id;

 u_int istate;
 u_int ostate;
 int flags;
 int rfd;
 int wfd;
 int efd;
 int sock;
 u_int io_want;
 u_int io_ready;
 int pfds[4];
 int ctl_chan;
 int isatty;



 int client_tty;
 int force_drain;
 time_t notbefore;
 int delayed;




 int restore_block;
 struct sshbuf *input;

 struct sshbuf *output;

 struct sshbuf *extended;

 char *path;

 int listening_port;
 char *listening_addr;
 int host_port;
 char *remote_name;

 u_int remote_window;
 u_int remote_maxpacket;
 u_int local_window;
 u_int local_window_max;
 u_int local_consumed;
 u_int local_maxpacket;
 int extended_usage;
 int single_connection;

 char *ctype;


 channel_open_fn *open_confirm;
 void *open_confirm_ctx;
 channel_callback_fn *detach_user;
 int detach_close;
 struct channel_confirms status_confirms;


 channel_infilter_fn *input_filter;
 channel_outfilter_fn *output_filter;
 void *filter_ctx;
 channel_filter_cleanup_fn *filter_cleanup;


 int datagram;



 struct channel_connect connect_ctx;


 mux_callback_fn *mux_rcb;
 void *mux_ctx;
 int mux_pause;
 int mux_downstream_id;
};
void channel_init_channels(struct ssh *ssh);



Channel *channel_by_id(struct ssh *, int);
Channel *channel_by_remote_id(struct ssh *, u_int);
Channel *channel_lookup(struct ssh *, int);
Channel *channel_new(struct ssh *, char *, int, int, int, int,
     u_int, u_int, int, const char *, int);
void channel_set_fds(struct ssh *, int, int, int, int, int,
     int, int, u_int);
void channel_free(struct ssh *, Channel *);
void channel_free_all(struct ssh *);
void channel_stop_listening(struct ssh *);

void channel_send_open(struct ssh *, int);
void channel_request_start(struct ssh *, int, char *, int);
void channel_register_cleanup(struct ssh *, int,
     channel_callback_fn *, int);
void channel_register_open_confirm(struct ssh *, int,
     channel_open_fn *, void *);
void channel_register_filter(struct ssh *, int, channel_infilter_fn *,
     channel_outfilter_fn *, channel_filter_cleanup_fn *, void *);
void channel_register_status_confirm(struct ssh *, int,
     channel_confirm_cb *, channel_confirm_abandon_cb *, void *);
void channel_cancel_cleanup(struct ssh *, int);
int channel_close_fd(struct ssh *, Channel *, int *);
void channel_send_window_changes(struct ssh *);



int channel_proxy_downstream(struct ssh *, Channel *mc);
int channel_proxy_upstream(Channel *, int, u_int32_t, struct ssh *);



int channel_input_data(int, u_int32_t, struct ssh *);
int channel_input_extended_data(int, u_int32_t, struct ssh *);
int channel_input_ieof(int, u_int32_t, struct ssh *);
int channel_input_oclose(int, u_int32_t, struct ssh *);
int channel_input_open_confirmation(int, u_int32_t, struct ssh *);
int channel_input_open_failure(int, u_int32_t, struct ssh *);
int channel_input_port_open(int, u_int32_t, struct ssh *);
int channel_input_window_adjust(int, u_int32_t, struct ssh *);
int channel_input_status_confirm(int, u_int32_t, struct ssh *);


struct pollfd;

void channel_prepare_poll(struct ssh *, struct pollfd **,
     u_int *, u_int *, u_int, time_t *);
void channel_after_poll(struct ssh *, struct pollfd *, u_int);
void channel_output_poll(struct ssh *);

int channel_not_very_much_buffered_data(struct ssh *);
void channel_close_all(struct ssh *);
int channel_still_open(struct ssh *);
const char *channel_format_extended_usage(const Channel *);
char *channel_open_message(struct ssh *);
int channel_find_open(struct ssh *);


struct Forward;
struct ForwardOptions;
void channel_set_af(struct ssh *, int af);
void channel_permit_all(struct ssh *, int);
void channel_add_permission(struct ssh *, int, int, char *, int);
void channel_clear_permission(struct ssh *, int, int);
void channel_disable_admin(struct ssh *, int);
void channel_update_permission(struct ssh *, int, int);
Channel *channel_connect_to_port(struct ssh *, const char *, u_short,
     char *, char *, int *, const char **);
Channel *channel_connect_to_path(struct ssh *, const char *, char *, char *);
Channel *channel_connect_stdio_fwd(struct ssh *, const char*,
     u_short, int, int, int);
Channel *channel_connect_by_listen_address(struct ssh *, const char *,
     u_short, char *, char *);
Channel *channel_connect_by_listen_path(struct ssh *, const char *,
     char *, char *);
int channel_request_remote_forwarding(struct ssh *, struct Forward *);
int channel_setup_local_fwd_listener(struct ssh *, struct Forward *,
     struct ForwardOptions *);
int channel_request_rforward_cancel(struct ssh *, struct Forward *);
int channel_setup_remote_fwd_listener(struct ssh *, struct Forward *,
     int *, struct ForwardOptions *);
int channel_cancel_rport_listener(struct ssh *, struct Forward *);
int channel_cancel_lport_listener(struct ssh *, struct Forward *,
     int, struct ForwardOptions *);
int permitopen_port(const char *);



void channel_set_x11_refuse_time(struct ssh *, u_int);
int x11_connect_display(struct ssh *);
int x11_create_display_inet(struct ssh *, int, int, int, u_int *, int **);
void x11_request_forwarding_with_spoofing(struct ssh *, int,
     const char *, const char *, const char *, int);



int chan_is_dead(struct ssh *, Channel *, int);
void chan_mark_dead(struct ssh *, Channel *);



void chan_rcvd_oclose(struct ssh *, Channel *);
void chan_rcvd_eow(struct ssh *, Channel *);
void chan_read_failed(struct ssh *, Channel *);
void chan_ibuf_empty(struct ssh *, Channel *);
void chan_rcvd_ieof(struct ssh *, Channel *);
void chan_write_failed(struct ssh *, Channel *);
void chan_obuf_empty(struct ssh *, Channel *);
struct ssh;

void compat_banner(struct ssh *, const char *);
char *compat_cipher_proposal(struct ssh *, char *);
char *compat_pkalg_proposal(struct ssh *, char *);
char *compat_kex_proposal(struct ssh *, char *);
char *get_peer_ipaddr(int);
int get_peer_port(int);
char *get_local_ipaddr(int);
char *get_local_name(int);
int get_local_port(int);



void ipv64_normalise_mapped(struct sockaddr_storage *, socklen_t *);



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
typedef void chan_fn(struct ssh *, Channel *c);
struct permission {
 char *host_to_connect;
 int port_to_connect;
 char *listen_host;
 char *listen_path;
 int listen_port;
 Channel *downstream;
};





struct permission_set {




 u_int num_permitted_user;
 struct permission *permitted_user;




 u_int num_permitted_admin;
 struct permission *permitted_admin;






 int all_permitted;
};


struct ssh_channels {




 Channel **channels;





 u_int channels_alloc;
 chan_fn **channel_pre;
 chan_fn **channel_post;


 struct permission_set local_perms;
 struct permission_set remote_perms;




 char *x11_saved_display;


 char *x11_saved_proto;


 char *x11_saved_data;
 u_int x11_saved_data_len;


 u_int x11_refuse_time;






 u_char *x11_fake_data;
 u_int x11_fake_data_len;


 int IPv4or6;
};


static void port_open_helper(struct ssh *ssh, Channel *c, char *rtype);
static const char *channel_rfwd_bind_host(const char *listen_host);


static int connect_next(struct channel_connect *);
static void channel_connect_ctx_free(struct channel_connect *);
static Channel *rdynamic_connect_prepare(struct ssh *, char *, char *);
static int rdynamic_connect_finish(struct ssh *, Channel *);


static void channel_handler_init(struct ssh_channels *sc);



void
channel_init_channels(struct ssh *ssh)
{
 struct ssh_channels *sc;

 if ((sc = calloc(1, sizeof(*sc))) == 
                                     ((void *)0)
                                         )
  sshfatal("channels.c", __func__, 230, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "allocation failed");
 sc->channels_alloc = 10;
 sc->channels = xcalloc(sc->channels_alloc, sizeof(*sc->channels));
 sc->IPv4or6 = 
              0
                       ;
 channel_handler_init(sc);

 ssh->chanctxt = sc;
}

Channel *
channel_by_id(struct ssh *ssh, int id)
{
 Channel *c;

 if (id < 0 || (u_int)id >= ssh->chanctxt->channels_alloc) {
  sshlog("channels.c", __func__, 245, 1, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "%d: bad id", id);
  return 
        ((void *)0)
            ;
 }
 c = ssh->chanctxt->channels[id];
 if (c == 
         ((void *)0)
             ) {
  sshlog("channels.c", __func__, 250, 1, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "%d: bad id: channel free", id);
  return 
        ((void *)0)
            ;
 }
 return c;
}

Channel *
channel_by_remote_id(struct ssh *ssh, u_int remote_id)
{
 Channel *c;
 u_int i;

 for (i = 0; i < ssh->chanctxt->channels_alloc; i++) {
  c = ssh->chanctxt->channels[i];
  if (c != 
          ((void *)0) 
               && c->have_remote_id && c->remote_id == remote_id)
   return c;
 }
 return 
       ((void *)0)
           ;
}





Channel *
channel_lookup(struct ssh *ssh, int id)
{
 Channel *c;

 if ((c = channel_by_id(ssh, id)) == 
                                    ((void *)0)
                                        )
  return 
        ((void *)0)
            ;

 switch (c->type) {
 case 7:
 case 10:
 case 12:
 case 13:
 case 21:
 case 22:
 case 3:
 case 4:
 case 17:
 case 20:
  return c;
 }
 sshlog("channels.c", __func__, 295, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "Non-public channel %d, type %d.", id, c->type);
 return 
       ((void *)0)
           ;
}





static void
channel_register_fds(struct ssh *ssh, Channel *c, int rfd, int wfd, int efd,
    int extusage, int nonblock, int is_tty)
{
 int val;

 if (rfd != -1)
  fcntl(rfd, 
            2
                   , 
                     1
                               );
 if (wfd != -1 && wfd != rfd)
  fcntl(wfd, 
            2
                   , 
                     1
                               );
 if (efd != -1 && efd != rfd && efd != wfd)
  fcntl(efd, 
            2
                   , 
                     1
                               );

 c->rfd = rfd;
 c->wfd = wfd;
 c->sock = (rfd == wfd) ? rfd : -1;
 c->efd = efd;
 c->extended_usage = extusage;

 if ((c->isatty = is_tty) != 0)
  sshlog("channels.c", __func__, 323, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: rfd %d isatty", c->self, c->rfd);






 c->restore_block = 0;
 if (nonblock == 2) {






  if (rfd != -1 && !isatty(rfd) &&
      (val = fcntl(rfd, 
                       3
                              )) != -1 && !(val & 
                                                  04000
                                                            )) {
   c->restore_block |= 0x01;
   set_nonblock(rfd);
  }
  if (wfd != -1 && !isatty(wfd) &&
      (val = fcntl(wfd, 
                       3
                              )) != -1 && !(val & 
                                                  04000
                                                            )) {
   c->restore_block |= 0x02;
   set_nonblock(wfd);
  }
  if (efd != -1 && !isatty(efd) &&
      (val = fcntl(efd, 
                       3
                              )) != -1 && !(val & 
                                                  04000
                                                            )) {
   c->restore_block |= 0x04;
   set_nonblock(efd);
  }
 } else if (nonblock) {
  if (rfd != -1)
   set_nonblock(rfd);
  if (wfd != -1)
   set_nonblock(wfd);
  if (efd != -1)
   set_nonblock(efd);
 }
}




Channel *
channel_new(struct ssh *ssh, char *ctype, int type, int rfd, int wfd, int efd,
    u_int window, u_int maxpack, int extusage, const char *remote_name,
    int nonblock)
{
 struct ssh_channels *sc = ssh->chanctxt;
 u_int i, found = 0;
 Channel *c;
 int r;


 for (i = 0; i < sc->channels_alloc; i++) {
  if (sc->channels[i] == 
                        ((void *)0)
                            ) {

   found = i;
   break;
  }
 }
 if (i >= sc->channels_alloc) {




  found = sc->channels_alloc;
  if (sc->channels_alloc > (16*1024))
   sshfatal("channels.c", __func__, 391, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "internal error: channels_alloc %d too big", sc->channels_alloc)
                          ;
  sc->channels = xrecallocarray(sc->channels, sc->channels_alloc,
      sc->channels_alloc + 10, sizeof(*sc->channels));
  sc->channels_alloc += 10;
  sshlog("channels.c", __func__, 396, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel: expanding %d", sc->channels_alloc);
 }

 c = sc->channels[found] = xcalloc(1, sizeof(Channel));
 if ((c->input = sshbuf_new()) == 
                                 ((void *)0) 
                                      ||
     (c->output = sshbuf_new()) == 
                                  ((void *)0) 
                                       ||
     (c->extended = sshbuf_new()) == 
                                    ((void *)0)
                                        )
  sshfatal("channels.c", __func__, 403, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if ((r = sshbuf_set_max_size(c->input, (16*1024*1024))) != 0)
  sshfatal("channels.c", __func__, 405, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_set_max_size");
 c->ostate = 0;
 c->istate = 0;
 channel_register_fds(ssh, c, rfd, wfd, efd, extusage, nonblock, 0);
 c->self = found;
 c->type = type;
 c->ctype = ctype;
 c->local_window = window;
 c->local_window_max = window;
 c->local_maxpacket = maxpack;
 c->remote_name = xstrdup(remote_name);
 c->ctl_chan = -1;
 c->delayed = 1;
 do { (&c->status_confirms)->tqh_first = 
((void *)0)
; (&c->status_confirms)->tqh_last = &(&c->status_confirms)->tqh_first; } while (0);
 sshlog("channels.c", __func__, 419, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "channel %d: new [%s]", found, remote_name);
 return c;
}

int
channel_close_fd(struct ssh *ssh, Channel *c, int *fdp)
{
 int ret, fd = *fdp;

 if (fd == -1)
  return 0;

 if ((*fdp == c->rfd && (c->restore_block & 0x01) != 0) ||
    (*fdp == c->wfd && (c->restore_block & 0x02) != 0) ||
    (*fdp == c->efd && (c->restore_block & 0x04) != 0))
  (void)fcntl(*fdp, 
                   4
                          , 0);

 if (*fdp == c->rfd) {
  c->io_want &= ~0x01;
  c->io_ready &= ~0x01;
  c->rfd = -1;
  c->pfds[0] = -1;
 }
 if (*fdp == c->wfd) {
  c->io_want &= ~0x02;
  c->io_ready &= ~0x02;
  c->wfd = -1;
  c->pfds[1] = -1;
 }
 if (*fdp == c->efd) {
  c->io_want &= ~(0x04|0x08);
  c->io_ready &= ~(0x04|0x08);
  c->efd = -1;
  c->pfds[2] = -1;
 }
 if (*fdp == c->sock) {
  c->io_want &= ~(0x10|0x20);
  c->io_ready &= ~(0x10|0x20);
  c->sock = -1;
  c->pfds[3] = -1;
 }

 ret = close(fd);
 *fdp = -1;
 return ret;
}


static void
channel_close_fds(struct ssh *ssh, Channel *c)
{
 int sock = c->sock, rfd = c->rfd, wfd = c->wfd, efd = c->efd;

 channel_close_fd(ssh, c, &c->sock);
 if (rfd != sock)
  channel_close_fd(ssh, c, &c->rfd);
 if (wfd != sock && wfd != rfd)
  channel_close_fd(ssh, c, &c->wfd);
 if (efd != sock && efd != rfd && efd != wfd)
  channel_close_fd(ssh, c, &c->efd);
}

static void
fwd_perm_clear(struct permission *perm)
{
 free(perm->host_to_connect);
 free(perm->listen_host);
 free(perm->listen_path);
 memset(perm, 0, sizeof(*perm));
}


static const char *
fwd_ident(int who, int where)
{
 if (who == 0x100) {
  if (where == (1<<1))
   return "admin local";
  else if (where == (1))
   return "admin remote";
 } else if (who == 0x101) {
  if (where == (1<<1))
   return "user local";
  else if (where == (1))
   return "user remote";
 }
 sshfatal("channels.c", __func__, 505, 0, SYSLOG_LEVEL_FATAL, 
((void *)0)
, "Unknown forward permission list %d/%d", who, where);
}


static struct permission_set *
permission_set_get(struct ssh *ssh, int where)
{
 struct ssh_channels *sc = ssh->chanctxt;

 switch (where) {
 case (1<<1):
  return &sc->local_perms;
  break;
 case (1):
  return &sc->remote_perms;
  break;
 default:
  sshfatal("channels.c", __func__, 522, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "invalid forwarding direction %d", where);
 }
}


static void
permission_set_get_array(struct ssh *ssh, int who, int where,
    struct permission ***permpp, u_int **npermpp)
{
 struct permission_set *pset = permission_set_get(ssh, where);

 switch (who) {
 case 0x101:
  *permpp = &pset->permitted_user;
  *npermpp = &pset->num_permitted_user;
  break;
 case 0x100:
  *permpp = &pset->permitted_admin;
  *npermpp = &pset->num_permitted_admin;
  break;
 default:
  sshfatal("channels.c", __func__, 543, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "invalid forwarding client %d", who);
 }
}


static int
permission_set_add(struct ssh *ssh, int who, int where,
    const char *host_to_connect, int port_to_connect,
    const char *listen_host, const char *listen_path, int listen_port,
    Channel *downstream)
{
 struct permission **permp;
 u_int n, *npermp;

 permission_set_get_array(ssh, who, where, &permp, &npermp);

 if (*npermp >= 0x7fffffff)
  sshfatal("channels.c", __func__, 560, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s overflow", fwd_ident(who, where));

 *permp = xrecallocarray(*permp, *npermp, *npermp + 1, sizeof(**permp));
 n = (*npermp)++;

 (*permp)[n].host_to_connect = ((host_to_connect == 
                              ((void *)0)
                              ) ? 
                              ((void *)0) 
                              : xstrdup(host_to_connect));
 (*permp)[n].port_to_connect = port_to_connect;
 (*permp)[n].listen_host = ((listen_host == 
                          ((void *)0)
                          ) ? 
                          ((void *)0) 
                          : xstrdup(listen_host));
 (*permp)[n].listen_path = ((listen_path == 
                          ((void *)0)
                          ) ? 
                          ((void *)0) 
                          : xstrdup(listen_path));
 (*permp)[n].listen_port = listen_port;
 (*permp)[n].downstream = downstream;

 return (int)n;
}

static void
mux_remove_remote_forwardings(struct ssh *ssh, Channel *c)
{
 struct ssh_channels *sc = ssh->chanctxt;
 struct permission_set *pset = &sc->local_perms;
 struct permission *perm;
 int r;
 u_int i;

 for (i = 0; i < pset->num_permitted_user; i++) {
  perm = &pset->permitted_user[i];
  if (perm->downstream != c)
   continue;


  sshlog("channels.c", __func__, 590, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "channel %d: cleanup remote forward for %s:%u", c->self, perm->listen_host, perm->listen_port)
                                                    ;
  if ((r = sshpkt_start(ssh, 80)) != 0 ||
      (r = sshpkt_put_cstring(ssh,
      "cancel-tcpip-forward")) != 0 ||
      (r = sshpkt_put_u8(ssh, 0)) != 0 ||
      (r = sshpkt_put_cstring(ssh,
      channel_rfwd_bind_host(perm->listen_host))) != 0 ||
      (r = sshpkt_put_u32(ssh, perm->listen_port)) != 0 ||
      (r = sshpkt_send(ssh)) != 0) {
   sshfatal("channels.c", __func__, 600, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i", c->self);
  }
  fwd_perm_clear(perm);
 }
}


void
channel_free(struct ssh *ssh, Channel *c)
{
 struct ssh_channels *sc = ssh->chanctxt;
 char *s;
 u_int i, n;
 Channel *other;
 struct channel_confirm *cc;

 for (n = 0, i = 0; i < sc->channels_alloc; i++) {
  if ((other = sc->channels[i]) == 
                                  ((void *)0)
                                      )
   continue;
  n++;

  if (c->type == 16 &&
      other->type == 20 &&
      other->mux_ctx == c) {
   other->mux_ctx = 
                   ((void *)0)
                       ;
   other->type = 4;
   other->istate = 3;
   other->ostate = 3;
  }
 }
 sshlog("channels.c", __func__, 630, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "channel %d: free: %s, nchannels %u", c->self, c->remote_name ? c->remote_name : "???", n)
                                                ;

 if (c->type == 16) {
  mux_remove_remote_forwardings(ssh, c);
  free(c->mux_ctx);
  c->mux_ctx = 
              ((void *)0)
                  ;
 } else if (c->type == 15) {
  free(c->mux_ctx);
  c->mux_ctx = 
              ((void *)0)
                  ;
 }

 if (log_level_get() >= SYSLOG_LEVEL_DEBUG3) {
  s = channel_open_message(ssh);
  sshlog("channels.c", __func__, 644, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "channel %d: status: %s", c->self, s);
  free(s);
 }

 channel_close_fds(ssh, c);
 sshbuf_free(c->input);
 sshbuf_free(c->output);
 sshbuf_free(c->extended);
 c->input = c->output = c->extended = 
                                     ((void *)0)
                                         ;
 free(c->remote_name);
 c->remote_name = 
                 ((void *)0)
                     ;
 free(c->path);
 c->path = 
          ((void *)0)
              ;
 free(c->listening_addr);
 c->listening_addr = 
                    ((void *)0)
                        ;
 while ((cc = ((&c->status_confirms)->tqh_first)) != 
                                                  ((void *)0)
                                                      ) {
  if (cc->abandon_cb != 
                       ((void *)0)
                           )
   cc->abandon_cb(ssh, c, cc->ctx);
  do { if (((cc)->entry.tqe_next) != 
 ((void *)0)
 ) (cc)->entry.tqe_next->entry.tqe_prev = (cc)->entry.tqe_prev; else (&c->status_confirms)->tqh_last = (cc)->entry.tqe_prev; *(cc)->entry.tqe_prev = (cc)->entry.tqe_next; ; ; } while (0);
  freezero(cc, sizeof(*cc));
 }
 if (c->filter_cleanup != 
                         ((void *)0) 
                              && c->filter_ctx != 
                                                  ((void *)0)
                                                      )
  c->filter_cleanup(ssh, c->self, c->filter_ctx);
 sc->channels[c->self] = 
                        ((void *)0)
                            ;
 freezero(c, sizeof(*c));
}

void
channel_free_all(struct ssh *ssh)
{
 u_int i;
 struct ssh_channels *sc = ssh->chanctxt;

 for (i = 0; i < sc->channels_alloc; i++)
  if (sc->channels[i] != 
                        ((void *)0)
                            )
   channel_free(ssh, sc->channels[i]);

 free(sc->channels);
 sc->channels = 
               ((void *)0)
                   ;
 sc->channels_alloc = 0;

 free(sc->x11_saved_display);
 sc->x11_saved_display = 
                        ((void *)0)
                            ;

 free(sc->x11_saved_proto);
 sc->x11_saved_proto = 
                      ((void *)0)
                          ;

 free(sc->x11_saved_data);
 sc->x11_saved_data = 
                     ((void *)0)
                         ;
 sc->x11_saved_data_len = 0;

 free(sc->x11_fake_data);
 sc->x11_fake_data = 
                    ((void *)0)
                        ;
 sc->x11_fake_data_len = 0;
}





void
channel_close_all(struct ssh *ssh)
{
 u_int i;

 for (i = 0; i < ssh->chanctxt->channels_alloc; i++)
  if (ssh->chanctxt->channels[i] != 
                                   ((void *)0)
                                       )
   channel_close_fds(ssh, ssh->chanctxt->channels[i]);
}




void
channel_stop_listening(struct ssh *ssh)
{
 u_int i;
 Channel *c;

 for (i = 0; i < ssh->chanctxt->channels_alloc; i++) {
  c = ssh->chanctxt->channels[i];
  if (c != 
          ((void *)0)
              ) {
   switch (c->type) {
   case 6:
   case 2:
   case 11:
   case 1:
   case 18:
   case 19:
    channel_close_fd(ssh, c, &c->sock);
    channel_free(ssh, c);
    break;
   }
  }
 }
}





int
channel_not_very_much_buffered_data(struct ssh *ssh)
{
 u_int i;
 u_int maxsize = ssh_packet_get_maxsize(ssh);
 Channel *c;

 for (i = 0; i < ssh->chanctxt->channels_alloc; i++) {
  c = ssh->chanctxt->channels[i];
  if (c == 
          ((void *)0) 
               || c->type != 4)
   continue;
  if (sshbuf_len(c->output) > maxsize) {
   sshlog("channels.c", __func__, 757, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "channel %d: big output buffer %zu > %u", c->self, sshbuf_len(c->output), maxsize)
                                               ;
   return 0;
  }
 }
 return 1;
}


int
channel_still_open(struct ssh *ssh)
{
 u_int i;
 Channel *c;

 for (i = 0; i < ssh->chanctxt->channels_alloc; i++) {
  c = ssh->chanctxt->channels[i];
  if (c == 
          ((void *)0)
              )
   continue;
  switch (c->type) {
  case 1:
  case 2:
  case 11:
  case 15:
  case 5:
  case 6:
  case 13:
  case 21:
  case 12:
  case 14:
  case 17:
  case 18:
  case 19:
   continue;
  case 10:
   continue;
  case 3:
  case 4:
  case 22:
  case 7:
  case 16:
  case 20:
   return 1;
  default:
   sshfatal("channels.c", __func__, 801, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "bad channel type %d", c->type);

  }
 }
 return 0;
}


int
channel_find_open(struct ssh *ssh)
{
 u_int i;
 Channel *c;

 for (i = 0; i < ssh->chanctxt->channels_alloc; i++) {
  c = ssh->chanctxt->channels[i];
  if (c == 
          ((void *)0) 
               || !c->have_remote_id)
   continue;
  switch (c->type) {
  case 5:
  case 13:
  case 21:
  case 22:
  case 1:
  case 2:
  case 11:
  case 15:
  case 16:
  case 20:
  case 3:
  case 12:
  case 14:
  case 17:
  case 18:
  case 19:
   continue;
  case 10:
  case 6:
  case 4:
  case 7:
   return i;
  default:
   sshfatal("channels.c", __func__, 843, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "bad channel type %d", c->type);

  }
 }
 return -1;
}


const char *
channel_format_extended_usage(const Channel *c)
{
 if (c->efd == -1)
  return "closed";

 switch (c->extended_usage) {
 case 2:
  return "write";
 case 1:
  return "read";
 case 0:
  return "ignore";
 default:
  return "UNKNOWN";
 }
}

static char *
channel_format_status(const Channel *c)
{
 char *ret = 
            ((void *)0)
                ;

 xasprintf(&ret, "t%d %s%u i%u/%zu o%u/%zu e[%s]/%zu "
     "fd %d/%d/%d sock %d cc %d io 0x%02x/0x%02x",
     c->type,
     c->have_remote_id ? "r" : "nr", c->remote_id,
     c->istate, sshbuf_len(c->input),
     c->ostate, sshbuf_len(c->output),
     channel_format_extended_usage(c), sshbuf_len(c->extended),
     c->rfd, c->wfd, c->efd, c->sock, c->ctl_chan,
     c->io_want, c->io_ready);
 return ret;
}






char *
channel_open_message(struct ssh *ssh)
{
 struct sshbuf *buf;
 Channel *c;
 u_int i;
 int r;
 char *cp, *ret;

 if ((buf = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("channels.c", __func__, 901, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 if ((r = sshbuf_putf(buf,
     "The following connections are open:\r\n")) != 0)
  sshfatal("channels.c", __func__, 904, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_putf");
 for (i = 0; i < ssh->chanctxt->channels_alloc; i++) {
  c = ssh->chanctxt->channels[i];
  if (c == 
          ((void *)0)
              )
   continue;
  switch (c->type) {
  case 1:
  case 2:
  case 11:
  case 5:
  case 6:
  case 14:
  case 17:
  case 15:
  case 18:
  case 19:
   continue;
  case 10:
  case 3:
  case 12:
  case 13:
  case 21:
  case 22:
  case 4:
  case 7:
  case 20:
  case 16:
   cp = channel_format_status(c);
   if ((r = sshbuf_putf(buf, "  #%d %.300s (%s)\r\n",
       c->self, c->remote_name, cp)) != 0) {
    free(cp);
    sshfatal("channels.c", __func__, 935, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_putf");
   }
   free(cp);
   continue;
  default:
   sshfatal("channels.c", __func__, 940, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "bad channel type %d", c->type);

  }
 }
 if ((ret = sshbuf_dup_string(buf)) == 
                                      ((void *)0)
                                          )
  sshfatal("channels.c", __func__, 945, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_dup_string");
 sshbuf_free(buf);
 return ret;
}

static void
open_preamble(struct ssh *ssh, const char *where, Channel *c, const char *type)
{
 int r;

 if ((r = sshpkt_start(ssh, 90)) != 0 ||
     (r = sshpkt_put_cstring(ssh, type)) != 0 ||
     (r = sshpkt_put_u32(ssh, c->self)) != 0 ||
     (r = sshpkt_put_u32(ssh, c->local_window)) != 0 ||
     (r = sshpkt_put_u32(ssh, c->local_maxpacket)) != 0) {
  sshfatal("channels.c", __func__, 960, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "%s: channel %i: open", where, c->self);
 }
}

void
channel_send_open(struct ssh *ssh, int id)
{
 Channel *c = channel_lookup(ssh, id);
 int r;

 if (c == 
         ((void *)0)
             ) {
  sshlog("channels.c", __func__, 971, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "channel_send_open: %d: bad id", id);
  return;
 }
 sshlog("channels.c", __func__, 974, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: send open", id);
 open_preamble(ssh, __func__, c, c->ctype);
 if ((r = sshpkt_send(ssh)) != 0)
  sshfatal("channels.c", __func__, 977, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i", c->self);
}

void
channel_request_start(struct ssh *ssh, int id, char *service, int wantconfirm)
{
 Channel *c = channel_lookup(ssh, id);
 int r;

 if (c == 
         ((void *)0)
             ) {
  sshlog("channels.c", __func__, 987, 1, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "%d: unknown channel id", id);
  return;
 }
 if (!c->have_remote_id)
  sshfatal("channels.c", __func__, 991, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel %d: no remote id", c->self);

 sshlog("channels.c", __func__, 993, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: request %s confirm %d", id, service, wantconfirm);
 if ((r = sshpkt_start(ssh, 98)) != 0 ||
     (r = sshpkt_put_u32(ssh, c->remote_id)) != 0 ||
     (r = sshpkt_put_cstring(ssh, service)) != 0 ||
     (r = sshpkt_put_u8(ssh, wantconfirm)) != 0) {
  sshfatal("channels.c", __func__, 998, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i", c->self);
 }
}

void
channel_register_status_confirm(struct ssh *ssh, int id,
    channel_confirm_cb *cb, channel_confirm_abandon_cb *abandon_cb, void *ctx)
{
 struct channel_confirm *cc;
 Channel *c;

 if ((c = channel_lookup(ssh, id)) == 
                                     ((void *)0)
                                         )
  sshfatal("channels.c", __func__, 1010, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%d: bad id", id);

 cc = xcalloc(1, sizeof(*cc));
 cc->cb = cb;
 cc->abandon_cb = abandon_cb;
 cc->ctx = ctx;
 do { (cc)->entry.tqe_next = 
((void *)0)
; (cc)->entry.tqe_prev = (&c->status_confirms)->tqh_last; *(&c->status_confirms)->tqh_last = (cc); (&c->status_confirms)->tqh_last = &(cc)->entry.tqe_next; } while (0);
}

void
channel_register_open_confirm(struct ssh *ssh, int id,
    channel_open_fn *fn, void *ctx)
{
 Channel *c = channel_lookup(ssh, id);

 if (c == 
         ((void *)0)
             ) {
  sshlog("channels.c", __func__, 1026, 1, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "%d: bad id", id);
  return;
 }
 c->open_confirm = fn;
 c->open_confirm_ctx = ctx;
}

void
channel_register_cleanup(struct ssh *ssh, int id,
    channel_callback_fn *fn, int do_close)
{
 Channel *c = channel_by_id(ssh, id);

 if (c == 
         ((void *)0)
             ) {
  sshlog("channels.c", __func__, 1040, 1, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "%d: bad id", id);
  return;
 }
 c->detach_user = fn;
 c->detach_close = do_close;
}

void
channel_cancel_cleanup(struct ssh *ssh, int id)
{
 Channel *c = channel_by_id(ssh, id);

 if (c == 
         ((void *)0)
             ) {
  sshlog("channels.c", __func__, 1053, 1, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "%d: bad id", id);
  return;
 }
 c->detach_user = 
                 ((void *)0)
                     ;
 c->detach_close = 0;
}

void
channel_register_filter(struct ssh *ssh, int id, channel_infilter_fn *ifn,
    channel_outfilter_fn *ofn, channel_filter_cleanup_fn *cfn, void *ctx)
{
 Channel *c = channel_lookup(ssh, id);

 if (c == 
         ((void *)0)
             ) {
  sshlog("channels.c", __func__, 1067, 1, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "%d: bad id", id);
  return;
 }
 c->input_filter = ifn;
 c->output_filter = ofn;
 c->filter_ctx = ctx;
 c->filter_cleanup = cfn;
}

void
channel_set_fds(struct ssh *ssh, int id, int rfd, int wfd, int efd,
    int extusage, int nonblock, int is_tty, u_int window_max)
{
 Channel *c = channel_lookup(ssh, id);
 int r;

 if (c == 
         ((void *)0) 
              || c->type != 10)
  sshfatal("channels.c", __func__, 1084, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel_activate for non-larval channel %d.", id);
 if (!c->have_remote_id)
  sshfatal("channels.c", __func__, 1086, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel %d: no remote id", c->self);

 channel_register_fds(ssh, c, rfd, wfd, efd, extusage, nonblock, is_tty);
 c->type = 4;
 c->local_window = c->local_window_max = window_max;

 if ((r = sshpkt_start(ssh, 93)) != 0 ||
     (r = sshpkt_put_u32(ssh, c->remote_id)) != 0 ||
     (r = sshpkt_put_u32(ssh, c->local_window)) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  sshfatal("channels.c", __func__, 1096, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i", c->self);
}

static void
channel_pre_listener(struct ssh *ssh, Channel *c)
{
 c->io_want = 0x10;
}

static void
channel_pre_connecting(struct ssh *ssh, Channel *c)
{
 sshlog("channels.c", __func__, 1108, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "channel %d: waiting for connection", c->self);
 c->io_want = 0x20;
}

static void
channel_pre_open(struct ssh *ssh, Channel *c)
{
 c->io_want = 0;
 if (c->istate == 0 &&
     c->remote_window > 0 &&
     sshbuf_len(c->input) < c->remote_window &&
     sshbuf_check_reserve(c->input, (16*1024)) == 0)
  c->io_want |= 0x01;
 if (c->ostate == 0 ||
     c->ostate == 1) {
  if (sshbuf_len(c->output) > 0) {
   c->io_want |= 0x02;
  } else if (c->ostate == 1) {
   if ((c->extended_usage == 2 && c->efd != -1 && (!(c->flags & (0x08|0x02)) || sshbuf_len(c->extended) > 0)))
    sshlog("channels.c", __func__, 1127, 0, SYSLOG_LEVEL_DEBUG2, 
   ((void *)0)
   , "channel %d: " "obuf_empty delayed efd %d/(%zu)", c->self, c->efd, sshbuf_len(c->extended))

                                        ;
   else
    chan_obuf_empty(ssh, c);
  }
 }

 if (c->efd != -1 && !(c->istate == 3 &&
     c->ostate == 3)) {
  if (c->extended_usage == 2 &&
      sshbuf_len(c->extended) > 0)
   c->io_want |= 0x08;
  else if (c->efd != -1 && !(c->flags & 0x04) &&
      (c->extended_usage == 1 ||
      c->extended_usage == 0) &&
      sshbuf_len(c->extended) < c->remote_window)
   c->io_want |= 0x04;
 }

}
static int
x11_open_helper(struct ssh *ssh, struct sshbuf *b)
{
 struct ssh_channels *sc = ssh->chanctxt;
 u_char *ucp;
 u_int proto_len, data_len;


 if (sc->x11_refuse_time != 0 &&
     (u_int)monotime() >= sc->x11_refuse_time) {
  sshlog("channels.c", __func__, 1168, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "Rejected X11 connection after ForwardX11Timeout " "expired")
                ;
  return -1;
 }


 if (sshbuf_len(b) < 12)
  return 0;


 ucp = sshbuf_mutable_ptr(b);
 if (ucp[0] == 0x42) {
  proto_len = 256 * ucp[6] + ucp[7];
  data_len = 256 * ucp[8] + ucp[9];
 } else if (ucp[0] == 0x6c) {
  proto_len = ucp[6] + 256 * ucp[7];
  data_len = ucp[8] + 256 * ucp[9];
 } else {
  sshlog("channels.c", __func__, 1186, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "Initial X11 packet contains bad byte order byte: 0x%x", ucp[0])
             ;
  return -1;
 }


 if (sshbuf_len(b) <
     12 + ((proto_len + 3) & ~3) + ((data_len + 3) & ~3))
  return 0;


 if (proto_len != strlen(sc->x11_saved_proto) ||
     memcmp(ucp + 12, sc->x11_saved_proto, proto_len) != 0) {
  sshlog("channels.c", __func__, 1199, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "X11 connection uses different authentication protocol.");
  return -1;
 }

 if (data_len != sc->x11_fake_data_len ||
     timingsafe_bcmp(ucp + 12 + ((proto_len + 3) & ~3),
  sc->x11_fake_data, sc->x11_fake_data_len) != 0) {
  sshlog("channels.c", __func__, 1206, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "X11 auth data does not match fake data.");
  return -1;
 }

 if (sc->x11_fake_data_len != sc->x11_saved_data_len) {
  sshlog("channels.c", __func__, 1211, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "X11 fake_data_len %d != saved_data_len %d", sc->x11_fake_data_len, sc->x11_saved_data_len)
                                                    ;
  return -1;
 }





 memcpy(ucp + 12 + ((proto_len + 3) & ~3),
     sc->x11_saved_data, sc->x11_saved_data_len);
 return 1;
}

static void
channel_pre_x11_open(struct ssh *ssh, Channel *c)
{
 int ret = x11_open_helper(ssh, c->output);



 if (ret == 1) {
  c->type = 4;
  channel_pre_open(ssh, c);
 } else if (ret == -1) {
  sshlog("channels.c", __func__, 1236, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "X11 connection rejected because of wrong authentication.");
  sshlog("channels.c", __func__, 1237, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "X11 rejected %d i%d/o%d", c->self, c->istate, c->ostate)
                                    ;
  chan_read_failed(ssh, c);
  sshbuf_reset(c->input);
  chan_ibuf_empty(ssh, c);
  sshbuf_reset(c->output);
  chan_write_failed(ssh, c);
  sshlog("channels.c", __func__, 1244, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "X11 closed %d i%d/o%d", c->self, c->istate, c->ostate);
 }
}

static void
channel_pre_mux_client(struct ssh *ssh, Channel *c)
{
 c->io_want = 0;
 if (c->istate == 0 && !c->mux_pause &&
     sshbuf_check_reserve(c->input, (16*1024)) == 0)
  c->io_want |= 0x01;
 if (c->istate == 1) {

  sshbuf_reset(c->input);
  chan_ibuf_empty(ssh, c);

  chan_rcvd_oclose(ssh, c);
 }
 if (c->ostate == 0 ||
     c->ostate == 1) {
  if (sshbuf_len(c->output) > 0)
   c->io_want |= 0x02;
  else if (c->ostate == 1)
   chan_obuf_empty(ssh, c);
 }
}


static int
channel_decode_socks4(Channel *c, struct sshbuf *input, struct sshbuf *output)
{
 const u_char *p;
 char *host;
 u_int len, have, i, found, need;
 char username[256];
 struct {
  u_int8_t version;
  u_int8_t command;
  u_int16_t dest_port;
  struct in_addr dest_addr;
 } s4_req, s4_rsp;
 int r;

 sshlog("channels.c", __func__, 1287, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: decode socks4", c->self);

 have = sshbuf_len(input);
 len = sizeof(s4_req);
 if (have < len)
  return 0;
 p = sshbuf_ptr(input);

 need = 1;

 if (p[4] == 0 && p[5] == 0 && p[6] == 0 && p[7] != 0) {
  sshlog("channels.c", __func__, 1298, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: socks4a request", c->self);

  need = 2;
 }

 for (found = 0, i = len; i < have; i++) {
  if (p[i] == '\0') {
   found++;
   if (found == need)
    break;
  }
  if (i > 1024) {

   sshlog("channels.c", __func__, 1311, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "channel %d: decode socks4: too long", c->self)
               ;
   return -1;
  }
 }
 if (found < need)
  return 0;
 if ((r = sshbuf_get(input, &s4_req.version, 1)) != 0 ||
     (r = sshbuf_get(input, &s4_req.command, 1)) != 0 ||
     (r = sshbuf_get(input, &s4_req.dest_port, 2)) != 0 ||
     (r = sshbuf_get(input, &s4_req.dest_addr, 4)) != 0) {
  sshlog("channels.c", __func__, 1322, 0, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "channels %d: decode socks4", c->self);
  return -1;
 }
 have = sshbuf_len(input);
 p = sshbuf_ptr(input);
 if (memchr(p, '\0', have) == 
                             ((void *)0)
                                 ) {
  sshlog("channels.c", __func__, 1328, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "channel %d: decode socks4: unterminated user", c->self);
  return -1;
 }
 len = strlen(p);
 sshlog("channels.c", __func__, 1332, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: decode socks4: user %s/%d", c->self, p, len);
 len++;
 strlcpy(username, p, sizeof(username));
 if ((r = sshbuf_consume(input, len)) != 0)
  sshfatal("channels.c", __func__, 1336, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %d: consume", c->self);
 free(c->path);
 c->path = 
          ((void *)0)
              ;
 if (need == 1) {
  host = inet_ntoa(s4_req.dest_addr);
  c->path = xstrdup(host);
 } else {
  have = sshbuf_len(input);
  p = sshbuf_ptr(input);
  if (memchr(p, '\0', have) == 
                              ((void *)0)
                                  ) {
   sshlog("channels.c", __func__, 1346, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "channel %d: decode socks4a: host not nul " "terminated", c->self)
                             ;
   return -1;
  }
  len = strlen(p);
  sshlog("channels.c", __func__, 1351, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: decode socks4a: host %s/%d", c->self, p, len)
                      ;
  len++;
  if (len > 
           1025
                     ) {
   sshlog("channels.c", __func__, 1355, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "channel %d: hostname \"%.100s\" too long", c->self, p)
                  ;
   return -1;
  }
  c->path = xstrdup(p);
  if ((r = sshbuf_consume(input, len)) != 0)
   sshfatal("channels.c", __func__, 1361, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %d: consume", c->self);
 }
 c->host_port = ntohs(s4_req.dest_port);

 sshlog("channels.c", __func__, 1365, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: dynamic request: socks4 host %s port %u command %u", c->self, c->path, c->host_port, s4_req.command)
                                                    ;

 if (s4_req.command != 1) {
  sshlog("channels.c", __func__, 1369, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "channel %d: cannot handle: %s cn %d", c->self, need == 1 ? "SOCKS4" : "SOCKS4A", s4_req.command)
                                                                ;
  return -1;
 }
 s4_rsp.version = 0;
 s4_rsp.command = 90;
 s4_rsp.dest_port = 0;
 s4_rsp.dest_addr.s_addr = 
                          ((in_addr_t) 0x00000000)
                                    ;
 if ((r = sshbuf_put(output, &s4_rsp, sizeof(s4_rsp))) != 0)
  sshfatal("channels.c", __func__, 1378, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %d: append reply", c->self);
 return 1;
}
static int
channel_decode_socks5(Channel *c, struct sshbuf *input, struct sshbuf *output)
{

 struct {
  u_int8_t version;
  u_int8_t command;
  u_int8_t reserved;
  u_int8_t atyp;
 } s5_req, s5_rsp;
 u_int16_t dest_port;
 char dest_addr[255+1], ntop[
                            46
                                            ];
 const u_char *p;
 u_int have, need, i, found, nmethods, addrlen, af;
 int r;

 sshlog("channels.c", __func__, 1407, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: decode socks5", c->self);
 p = sshbuf_ptr(input);
 if (p[0] != 0x05)
  return -1;
 have = sshbuf_len(input);
 if (!(c->flags & 0x1000)) {

  if (have < 2)
   return 0;
  nmethods = p[1];
  if (have < nmethods + 2)
   return 0;

  for (found = 0, i = 2; i < nmethods + 2; i++) {
   if (p[i] == 0x00) {
    found = 1;
    break;
   }
  }
  if (!found) {
   sshlog("channels.c", __func__, 1427, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "channel %d: method SSH_SOCKS5_NOAUTH not found", c->self)
               ;
   return -1;
  }
  if ((r = sshbuf_consume(input, nmethods + 2)) != 0)
   sshfatal("channels.c", __func__, 1432, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %d: consume", c->self);

  if ((r = sshbuf_put_u8(output, 0x05)) != 0 ||
      (r = sshbuf_put_u8(output, 0x00)) != 0)
   sshfatal("channels.c", __func__, 1436, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %d: append reply", c->self);
  c->flags |= 0x1000;
  sshlog("channels.c", __func__, 1438, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: socks5 auth done", c->self);
  return 0;
 }
 sshlog("channels.c", __func__, 1441, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: socks5 post auth", c->self);
 if (have < sizeof(s5_req)+1)
  return 0;
 memcpy(&s5_req, p, sizeof(s5_req));
 if (s5_req.version != 0x05 ||
     s5_req.command != 0x01 ||
     s5_req.reserved != 0x00) {
  sshlog("channels.c", __func__, 1448, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: only socks5 connect supported", c->self);
  return -1;
 }
 switch (s5_req.atyp){
 case 0x01:
  addrlen = 4;
  af = 
      2
             ;
  break;
 case 0x03:
  addrlen = p[sizeof(s5_req)];
  af = -1;
  break;
 case 0x04:
  addrlen = 16;
  af = 
      10
              ;
  break;
 default:
  sshlog("channels.c", __func__, 1465, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: bad socks5 atyp %d", c->self, s5_req.atyp);
  return -1;
 }
 need = sizeof(s5_req) + addrlen + 2;
 if (s5_req.atyp == 0x03)
  need++;
 if (have < need)
  return 0;
 if ((r = sshbuf_consume(input, sizeof(s5_req))) != 0)
  sshfatal("channels.c", __func__, 1474, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %d: consume", c->self);
 if (s5_req.atyp == 0x03) {

  if ((r = sshbuf_consume(input, 1)) != 0)
   sshfatal("channels.c", __func__, 1478, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %d: consume", c->self);
 }
 if ((r = sshbuf_get(input, &dest_addr, addrlen)) != 0 ||
     (r = sshbuf_get(input, &dest_port, 2)) != 0) {
  sshlog("channels.c", __func__, 1482, 0, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "channel %d: parse addr/port", c->self);
  return -1;
 }
 dest_addr[addrlen] = '\0';
 free(c->path);
 c->path = 
          ((void *)0)
              ;
 if (s5_req.atyp == 0x03) {
  if (addrlen >= 
                1025
                          ) {
   sshlog("channels.c", __func__, 1490, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "channel %d: dynamic request: socks5 hostname " "\"%.100s\" too long", c->self, dest_addr)
                                                 ;
   return -1;
  }
  c->path = xstrdup(dest_addr);
 } else {
  if (inet_ntop(af, dest_addr, ntop, sizeof(ntop)) == 
                                                     ((void *)0)
                                                         )
   return -1;
  c->path = xstrdup(ntop);
 }
 c->host_port = ntohs(dest_port);

 sshlog("channels.c", __func__, 1502, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: dynamic request: socks5 host %s port %u command %u", c->self, c->path, c->host_port, s5_req.command)
                                                    ;

 s5_rsp.version = 0x05;
 s5_rsp.command = 0x00;
 s5_rsp.reserved = 0;
 s5_rsp.atyp = 0x01;
 dest_port = 0;

 if ((r = sshbuf_put(output, &s5_rsp, sizeof(s5_rsp))) != 0 ||
     (r = sshbuf_put_u32(output, ntohl(
                                      ((in_addr_t) 0x00000000)
                                                ))) != 0 ||
     (r = sshbuf_put(output, &dest_port, sizeof(dest_port))) != 0)
  sshfatal("channels.c", __func__, 1514, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %d: append reply", c->self);
 return 1;
}

Channel *
channel_connect_stdio_fwd(struct ssh *ssh,
    const char *host_to_connect, u_short port_to_connect,
    int in, int out, int nonblock)
{
 Channel *c;

 sshlog("channels.c", __func__, 1525, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "%s:%d", host_to_connect, port_to_connect);

 c = channel_new(ssh, "stdio-forward", 3, in, out,
     -1, (64*(32*1024)), (32*1024),
     0, "stdio-forward", nonblock);

 c->path = xstrdup(host_to_connect);
 c->host_port = port_to_connect;
 c->listening_port = 0;
 c->force_drain = 1;

 channel_register_fds(ssh, c, in, out, -1, 0, 1, 0);
 port_open_helper(ssh, c, "direct-tcpip");

 return c;
}


static void
channel_pre_dynamic(struct ssh *ssh, Channel *c)
{
 const u_char *p;
 u_int have;
 int ret;

 c->io_want = 0;
 have = sshbuf_len(c->input);
 sshlog("channels.c", __func__, 1552, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: pre_dynamic: have %d", c->self, have);


 if (have < 3) {

  c->io_want |= 0x01;
  return;
 }

 p = sshbuf_ptr(c->input);

 switch (p[0]) {
 case 0x04:
  ret = channel_decode_socks4(c, c->input, c->output);
  break;
 case 0x05:
  ret = channel_decode_socks5(c, c->input, c->output);
  break;
 default:
  ret = -1;
  break;
 }
 if (ret < 0) {
  chan_mark_dead(ssh, c);
 } else if (ret == 0) {
  sshlog("channels.c", __func__, 1577, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: pre_dynamic: need more", c->self);

  c->io_want |= 0x01;
  if (sshbuf_len(c->output))
   c->io_want |= 0x02;
 } else {

  c->type = 3;
  port_open_helper(ssh, c, "direct-tcpip");
 }
}


static void
rdynamic_close(struct ssh *ssh, Channel *c)
{
 c->type = 4;
 chan_read_failed(ssh, c);
 sshbuf_reset(c->input);
 chan_ibuf_empty(ssh, c);
 sshbuf_reset(c->output);
 chan_write_failed(ssh, c);
}


static void
channel_before_prepare_io_rdynamic(struct ssh *ssh, Channel *c)
{
 const u_char *p;
 u_int have, len;
 int r, ret;

 have = sshbuf_len(c->output);
 sshlog("channels.c", __func__, 1610, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: pre_rdynamic: have %d", c->self, have);


 if (c->flags & 0x08) {
  if ((r = sshbuf_consume(c->output, have)) != 0)
   sshfatal("channels.c", __func__, 1615, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %d: consume", c->self);
  rdynamic_close(ssh, c);
  return;
 }

 if (have < 3)
  return;

 p = sshbuf_ptr(c->output);
 switch (p[0]) {
 case 0x04:

  ret = channel_decode_socks4(c, c->output, c->input);
  break;
 case 0x05:
  ret = channel_decode_socks5(c, c->output, c->input);
  break;
 default:
  ret = -1;
  break;
 }
 if (ret < 0) {
  rdynamic_close(ssh, c);
 } else if (ret == 0) {
  sshlog("channels.c", __func__, 1639, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: pre_rdynamic: need more", c->self);

  len = sshbuf_len(c->input);
  if (len > 0 && len < c->remote_window) {
   if ((r = sshpkt_start(ssh, 94)) != 0 ||
       (r = sshpkt_put_u32(ssh, c->remote_id)) != 0 ||
       (r = sshpkt_put_stringb(ssh, c->input)) != 0 ||
       (r = sshpkt_send(ssh)) != 0) {
    sshfatal("channels.c", __func__, 1647, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: rdynamic", c->self);
   }
   if ((r = sshbuf_consume(c->input, len)) != 0)
    sshfatal("channels.c", __func__, 1650, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %d: consume", c->self);
   c->remote_window -= len;
  }
 } else if (rdynamic_connect_finish(ssh, c) < 0) {

  rdynamic_close(ssh, c);
 }
}


static void
channel_post_x11_listener(struct ssh *ssh, Channel *c)
{
 Channel *nc;
 struct sockaddr_storage addr;
 int r, newsock, oerrno, remote_port;
 socklen_t addrlen;
 char buf[16384], *remote_ipaddr;

 if ((c->io_ready & 0x10) == 0)
  return;

 sshlog("channels.c", __func__, 1672, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "X11 connection requested.");
 addrlen = sizeof(addr);
 newsock = accept(c->sock, (struct sockaddr *)&addr, &addrlen);
 if (c->single_connection) {
  oerrno = 
          (*__errno_location ())
               ;
  sshlog("channels.c", __func__, 1677, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "single_connection: closing X11 listener.");
  channel_close_fd(ssh, c, &c->sock);
  chan_mark_dead(ssh, c);
  
 (*__errno_location ()) 
       = oerrno;
 }
 if (newsock == -1) {
  if (
     (*__errno_location ()) 
           != 
              4 
                    && 
                       (*__errno_location ()) 
                             != 
                                11 
                                            &&
      
     (*__errno_location ()) 
           != 
              103
                          )
   sshlog("channels.c", __func__, 1685, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "accept: %.100s", strerror(
  (*__errno_location ())
  ));
  if (
     (*__errno_location ()) 
           == 
              24 
                     || 
                        (*__errno_location ()) 
                              == 
                                 23
                                       )
   c->notbefore = monotime() + 1;
  return;
 }
 set_nodelay(newsock);
 remote_ipaddr = get_peer_ipaddr(newsock);
 remote_port = get_peer_port(newsock);
 snprintf(buf, sizeof buf, "X11 connection from %.200s port %d",
     remote_ipaddr, remote_port);

 nc = channel_new(ssh, "accepted x11 socket",
     3, newsock, newsock, -1,
     c->local_window_max, c->local_maxpacket, 0, buf, 1);
 open_preamble(ssh, __func__, nc, "x11");
 if ((r = sshpkt_put_cstring(ssh, remote_ipaddr)) != 0 ||
     (r = sshpkt_put_u32(ssh, remote_port)) != 0) {
  sshfatal("channels.c", __func__, 1702, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: reply", c->self);
 }
 if ((r = sshpkt_send(ssh)) != 0)
  sshfatal("channels.c", __func__, 1705, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: send", c->self);
 free(remote_ipaddr);
}

static void
port_open_helper(struct ssh *ssh, Channel *c, char *rtype)
{
 char *local_ipaddr = get_local_ipaddr(c->sock);
 int local_port = c->sock == -1 ? 65536 : get_local_port(c->sock);
 char *remote_ipaddr = get_peer_ipaddr(c->sock);
 int remote_port = get_peer_port(c->sock);
 int r;

 if (remote_port == -1) {

  free(remote_ipaddr);
  remote_ipaddr = xstrdup("127.0.0.1");
  remote_port = 65535;
 }

 free(c->remote_name);
 xasprintf(&c->remote_name,
     "%s: listening port %d for %.100s port %d, "
     "connect from %.200s port %d to %.100s port %d",
     rtype, c->listening_port, c->path, c->host_port,
     remote_ipaddr, remote_port, local_ipaddr, local_port);

 open_preamble(ssh, __func__, c, rtype);
 if (strcmp(rtype, "direct-tcpip") == 0) {

  if ((r = sshpkt_put_cstring(ssh, c->path)) != 0 ||
      (r = sshpkt_put_u32(ssh, c->host_port)) != 0)
   sshfatal("channels.c", __func__, 1737, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: reply", c->self);
 } else if (strcmp(rtype, "direct-streamlocal@openssh.com") == 0) {

  if ((r = sshpkt_put_cstring(ssh, c->path)) != 0)
   sshfatal("channels.c", __func__, 1741, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: reply", c->self);
 } else if (strcmp(rtype, "forwarded-streamlocal@openssh.com") == 0) {

  if ((r = sshpkt_put_cstring(ssh, c->path)) != 0)
   sshfatal("channels.c", __func__, 1745, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: reply", c->self);
 } else {

  if ((r = sshpkt_put_cstring(ssh, c->path)) != 0 ||
      (r = sshpkt_put_u32(ssh, local_port)) != 0)
   sshfatal("channels.c", __func__, 1750, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: reply", c->self);
 }
 if (strcmp(rtype, "forwarded-streamlocal@openssh.com") == 0) {

  if ((r = sshpkt_put_cstring(ssh, "")) != 0)
   sshfatal("channels.c", __func__, 1755, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: reply", c->self);
 } else {

  if ((r = sshpkt_put_cstring(ssh, remote_ipaddr)) != 0 ||
      (r = sshpkt_put_u32(ssh, (u_int)remote_port)) != 0)
   sshfatal("channels.c", __func__, 1760, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: reply", c->self);
 }
 if ((r = sshpkt_send(ssh)) != 0)
  sshfatal("channels.c", __func__, 1763, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: send", c->self);
 free(remote_ipaddr);
 free(local_ipaddr);
}

void
channel_set_x11_refuse_time(struct ssh *ssh, u_int refuse_time)
{
 ssh->chanctxt->x11_refuse_time = refuse_time;
}




static void
channel_post_port_listener(struct ssh *ssh, Channel *c)
{
 Channel *nc;
 struct sockaddr_storage addr;
 int newsock, nextstate;
 socklen_t addrlen;
 char *rtype;

 if ((c->io_ready & 0x10) == 0)
  return;

 sshlog("channels.c", __func__, 1789, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Connection to port %d forwarding to %.100s port %d requested.", c->listening_port, c->path, c->host_port)
                                              ;

 if (c->type == 11) {
  nextstate = 3;
  rtype = "forwarded-tcpip";
 } else if (c->type == 19) {
  nextstate = 3;
  rtype = "forwarded-streamlocal@openssh.com";
 } else if (c->host_port == -2) {
  nextstate = 3;
  rtype = "direct-streamlocal@openssh.com";
 } else if (c->host_port == 0) {
  nextstate = 13;
  rtype = "dynamic-tcpip";
 } else {
  nextstate = 3;
  rtype = "direct-tcpip";
 }

 addrlen = sizeof(addr);
 newsock = accept(c->sock, (struct sockaddr *)&addr, &addrlen);
 if (newsock == -1) {
  if (
     (*__errno_location ()) 
           != 
              4 
                    && 
                       (*__errno_location ()) 
                             != 
                                11 
                                            &&
      
     (*__errno_location ()) 
           != 
              103
                          )
   sshlog("channels.c", __func__, 1814, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "accept: %.100s", strerror(
  (*__errno_location ())
  ));
  if (
     (*__errno_location ()) 
           == 
              24 
                     || 
                        (*__errno_location ()) 
                              == 
                                 23
                                       )
   c->notbefore = monotime() + 1;
  return;
 }
 if (c->host_port != -2)
  set_nodelay(newsock);
 nc = channel_new(ssh, rtype, nextstate, newsock, newsock, -1,
     c->local_window_max, c->local_maxpacket, 0, rtype, 1);
 nc->listening_port = c->listening_port;
 nc->host_port = c->host_port;
 if (c->path != 
               ((void *)0)
                   )
  nc->path = xstrdup(c->path);

 if (nextstate != 13)
  port_open_helper(ssh, nc, rtype);
}





static void
channel_post_auth_listener(struct ssh *ssh, Channel *c)
{
 Channel *nc;
 int r, newsock;
 struct sockaddr_storage addr;
 socklen_t addrlen;

 if ((c->io_ready & 0x10) == 0)
  return;

 addrlen = sizeof(addr);
 newsock = accept(c->sock, (struct sockaddr *)&addr, &addrlen);
 if (newsock == -1) {
  sshlog("channels.c", __func__, 1850, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "accept from auth socket: %.100s", strerror(
 (*__errno_location ())
 ));
  if (
     (*__errno_location ()) 
           == 
              24 
                     || 
                        (*__errno_location ()) 
                              == 
                                 23
                                       )
   c->notbefore = monotime() + 1;
  return;
 }
 nc = channel_new(ssh, "accepted auth socket",
     3, newsock, newsock, -1,
     c->local_window_max, c->local_maxpacket,
     0, "accepted auth socket", 1);
 open_preamble(ssh, __func__, nc, "auth-agent@openssh.com");
 if ((r = sshpkt_send(ssh)) != 0)
  sshfatal("channels.c", __func__, 1861, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i", c->self);
}

static void
channel_post_connecting(struct ssh *ssh, Channel *c)
{
 int err = 0, sock, isopen, r;
 socklen_t sz = sizeof(err);

 if ((c->io_ready & 0x20) == 0)
  return;
 if (!c->have_remote_id)
  sshfatal("channels.c", __func__, 1873, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel %d: no remote id", c->self);

 isopen = (c->type == 22);
 if (getsockopt(c->sock, 
                        1
                                  , 
                                    4
                                            , &err, &sz) == -1) {
  err = 
       (*__errno_location ())
            ;
  sshlog("channels.c", __func__, 1878, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "getsockopt SO_ERROR failed");
 }
 if (err == 0) {
  sshlog("channels.c", __func__, 1881, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "channel %d: connected to %s port %d", c->self, c->connect_ctx.host, c->connect_ctx.port)
                                                        ;
  channel_connect_ctx_free(&c->connect_ctx);
  c->type = 4;
  if (isopen) {

  } else {
   if ((r = sshpkt_start(ssh,
       91)) != 0 ||
       (r = sshpkt_put_u32(ssh, c->remote_id)) != 0 ||
       (r = sshpkt_put_u32(ssh, c->self)) != 0 ||
       (r = sshpkt_put_u32(ssh, c->local_window)) != 0 ||
       (r = sshpkt_put_u32(ssh, c->local_maxpacket)) != 0 ||
       (r = sshpkt_send(ssh)) != 0)
    sshfatal("channels.c", __func__, 1895, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i open confirm", c->self);
  }
 } else {
  sshlog("channels.c", __func__, 1898, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "channel %d: connection failed: %s", c->self, strerror(err))
                             ;

  if ((sock = connect_next(&c->connect_ctx)) > 0) {
   close(c->sock);
   c->sock = c->rfd = c->wfd = sock;
   return;
  }

  sshlog("channels.c", __func__, 1907, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "connect_to %.100s port %d: failed.", c->connect_ctx.host, c->connect_ctx.port)
                                               ;
  channel_connect_ctx_free(&c->connect_ctx);
  if (isopen) {
   rdynamic_close(ssh, c);
  } else {
   if ((r = sshpkt_start(ssh,
       92)) != 0 ||
       (r = sshpkt_put_u32(ssh, c->remote_id)) != 0 ||
       (r = sshpkt_put_u32(ssh,
       2)) != 0 ||
       (r = sshpkt_put_cstring(ssh, strerror(err))) != 0 ||
       (r = sshpkt_put_cstring(ssh, "")) != 0 ||
       (r = sshpkt_send(ssh)) != 0)
    sshfatal("channels.c", __func__, 1921, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: failure", c->self);
   chan_mark_dead(ssh, c);
  }
 }
}

static int
channel_handle_rfd(struct ssh *ssh, Channel *c)
{
 char buf[(16*1024)];
 ssize_t len;
 int r, force;
 size_t have, avail, maxlen = (32*1024);
 int pty_zeroread = 0;






 force = c->isatty && c->detach_close && c->istate != 3;

 if (!force && (c->io_ready & 0x01) == 0)
  return 1;
 if ((avail = sshbuf_avail(c->input)) == 0)
  return 1;





 if (!pty_zeroread && c->input_filter == 
                                        ((void *)0) 
                                             && !c->datagram) {

  if (c->type == 4) {
   if ((have = sshbuf_len(c->input)) >= c->remote_window)
    return 1;
   if (maxlen > c->remote_window - have)
    maxlen = c->remote_window - have;
  }
  if (maxlen > avail)
   maxlen = avail;
  if ((r = sshbuf_read(c->rfd, c->input, maxlen, 
                                                ((void *)0)
                                                    )) != 0) {
   if (
      (*__errno_location ()) 
            == 
               4 
                     || (!force &&
       (
       (*__errno_location ()) 
             == 
                11 
                       || 
                          (*__errno_location ()) 
                                == 
                                   11
                                              )))
    return 1;
   sshlog("channels.c", __func__, 1966, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "channel %d: read failed rfd %d maxlen %zu: %s", c->self, c->rfd, maxlen, ssh_err(r))
                                           ;
   goto rfail;
  }
  return 1;
 }

 
(*__errno_location ()) 
      = 0;
 len = read(c->rfd, buf, sizeof(buf));

 if (pty_zeroread && len == 0 && 
                                (*__errno_location ()) 
                                      != 0)
  len = -1;
 if (len == -1 && (
                  (*__errno_location ()) 
                        == 
                           4 
                                 ||
     ((
      (*__errno_location ()) 
            == 
               11 
                      || 
                         (*__errno_location ()) 
                               == 
                                  11
                                             ) && !force)))
  return 1;
 if (len < 0 || (!pty_zeroread && len == 0)) {
  sshlog("channels.c", __func__, 1982, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: read<=0 rfd %d len %zd: %s", c->self, c->rfd, len, len == 0 ? "closed" : strerror(
 (*__errno_location ())
 ))

                                            ;
 rfail:
  if (c->type != 4) {
   sshlog("channels.c", __func__, 1987, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "channel %d: not open", c->self);
   chan_mark_dead(ssh, c);
   return -1;
  } else {
   chan_read_failed(ssh, c);
  }
  return -1;
 }
 if (c->input_filter != 
                       ((void *)0)
                           ) {
  if (c->input_filter(ssh, c, buf, len) == -1) {
   sshlog("channels.c", __func__, 1997, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "channel %d: filter stops", c->self);
   chan_read_failed(ssh, c);
  }
 } else if (c->datagram) {
  if ((r = sshbuf_put_string(c->input, buf, len)) != 0)
   sshfatal("channels.c", __func__, 2002, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: put datagram", c->self);
 } else if ((r = sshbuf_put(c->input, buf, len)) != 0)
  sshfatal("channels.c", __func__, 2004, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: put data", c->self);

 return 1;
}

static int
channel_handle_wfd(struct ssh *ssh, Channel *c)
{
 struct termios tio;
 u_char *data = 
               ((void *)0)
                   , *buf;
 size_t dlen, olen = 0;
 int r, len;

 if ((c->io_ready & 0x02) == 0)
  return 1;
 if (sshbuf_len(c->output) == 0)
  return 1;


 olen = sshbuf_len(c->output);
 if (c->output_filter != 
                        ((void *)0)
                            ) {
  if ((buf = c->output_filter(ssh, c, &data, &dlen)) == 
                                                       ((void *)0)
                                                           ) {
   sshlog("channels.c", __func__, 2026, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "channel %d: filter stops", c->self);
   if (c->type != 4)
    chan_mark_dead(ssh, c);
   else
    chan_write_failed(ssh, c);
   return -1;
  }
 } else if (c->datagram) {
  if ((r = sshbuf_get_string(c->output, &data, &dlen)) != 0)
   sshfatal("channels.c", __func__, 2035, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: get datagram", c->self);
  buf = data;
 } else {
  buf = data = sshbuf_mutable_ptr(c->output);
  dlen = sshbuf_len(c->output);
 }

 if (c->datagram) {

  len = write(c->wfd, buf, dlen);
  free(data);
  if (len == -1 && (
                   (*__errno_location ()) 
                         == 
                            4 
                                  || 
                                     (*__errno_location ()) 
                                           == 
                                              11 
                                                     ||
      
     (*__errno_location ()) 
           == 
              11
                         ))
   return 1;
  if (len <= 0)
   goto write_fail;
  goto out;
 }







 len = write(c->wfd, buf, dlen);
 if (len == -1 &&
     (
     (*__errno_location ()) 
           == 
              4 
                    || 
                       (*__errno_location ()) 
                             == 
                                11 
                                       || 
                                          (*__errno_location ()) 
                                                == 
                                                   11
                                                              ))
  return 1;
 if (len <= 0) {
 write_fail:
  if (c->type != 4) {
   sshlog("channels.c", __func__, 2067, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "channel %d: not open", c->self);
   chan_mark_dead(ssh, c);
   return -1;
  } else {
   chan_write_failed(ssh, c);
  }
  return -1;
 }

 if (c->isatty && dlen >= 1 && buf[0] != '\r') {
  if (tcgetattr(c->wfd, &tio) == 0 &&
      !(tio.c_lflag & 
                     0000010
                         ) && (tio.c_lflag & 
                                             0000002
                                                   )) {






   if ((r = sshpkt_msg_ignore(ssh, 4+len)) != 0 ||
       (r = sshpkt_send(ssh)) != 0)
    sshfatal("channels.c", __func__, 2087, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: ignore", c->self);
  }
 }

 if ((r = sshbuf_consume(c->output, len)) != 0)
  sshfatal("channels.c", __func__, 2092, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: consume", c->self);
 out:
 c->local_consumed += olen - sshbuf_len(c->output);

 return 1;
}

static int
channel_handle_efd_write(struct ssh *ssh, Channel *c)
{
 int r;
 ssize_t len;

 if ((c->io_ready & 0x08) == 0)
  return 1;
 if (sshbuf_len(c->extended) == 0)
  return 1;

 len = write(c->efd, sshbuf_ptr(c->extended),
     sshbuf_len(c->extended));
 sshlog("channels.c", __func__, 2112, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: written %zd to efd %d", c->self, len, c->efd);
 if (len == -1 && (
                  (*__errno_location ()) 
                        == 
                           4 
                                 || 
                                    (*__errno_location ()) 
                                          == 
                                             11 
                                                    ||
     
    (*__errno_location ()) 
          == 
             11
                        ))
  return 1;
 if (len <= 0) {
  sshlog("channels.c", __func__, 2117, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: closing write-efd %d", c->self, c->efd);
  channel_close_fd(ssh, c, &c->efd);
 } else {
  if ((r = sshbuf_consume(c->extended, len)) != 0)
   sshfatal("channels.c", __func__, 2121, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: consume", c->self);
  c->local_consumed += len;
 }
 return 1;
}

static int
channel_handle_efd_read(struct ssh *ssh, Channel *c)
{
 char buf[(16*1024)];
 ssize_t len;
 int r, force;

 force = c->isatty && c->detach_close && c->istate != 3;

 if (!force && (c->io_ready & 0x04) == 0)
  return 1;

 len = read(c->efd, buf, sizeof(buf));
 sshlog("channels.c", __func__, 2140, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: read %zd from efd %d", c->self, len, c->efd);
 if (len == -1 && (
                  (*__errno_location ()) 
                        == 
                           4 
                                 || ((
                                      (*__errno_location ()) 
                                            == 
                                               11 
                                                      ||
     
    (*__errno_location ()) 
          == 
             11
                        ) && !force)))
  return 1;
 if (len <= 0) {
  sshlog("channels.c", __func__, 2145, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: closing read-efd %d", c->self, c->efd);
  channel_close_fd(ssh, c, &c->efd);
 } else if (c->extended_usage == 0)
  sshlog("channels.c", __func__, 2148, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "channel %d: discard efd", c->self);
 else if ((r = sshbuf_put(c->extended, buf, len)) != 0)
  sshfatal("channels.c", __func__, 2150, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: append", c->self);
 return 1;
}

static int
channel_handle_efd(struct ssh *ssh, Channel *c)
{
 if (c->efd == -1)
  return 1;



 if (c->extended_usage == 2)
  return channel_handle_efd_write(ssh, c);
 else if (c->extended_usage == 1 ||
     c->extended_usage == 0)
  return channel_handle_efd_read(ssh, c);

 return 1;
}

static int
channel_check_window(struct ssh *ssh, Channel *c)
{
 int r;

 if (c->type == 4 &&
     !(c->flags & (0x01|0x02)) &&
     ((c->local_window_max - c->local_window >
     c->local_maxpacket*3) ||
     c->local_window < c->local_window_max/2) &&
     c->local_consumed > 0) {
  if (!c->have_remote_id)
   sshfatal("channels.c", __func__, 2183, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "channel %d: no remote id", c->self);
  if ((r = sshpkt_start(ssh,
      93)) != 0 ||
      (r = sshpkt_put_u32(ssh, c->remote_id)) != 0 ||
      (r = sshpkt_put_u32(ssh, c->local_consumed)) != 0 ||
      (r = sshpkt_send(ssh)) != 0) {
   sshfatal("channels.c", __func__, 2189, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i", c->self);
  }
  sshlog("channels.c", __func__, 2191, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: window %d sent adjust %d", c->self, c->local_window, c->local_consumed)
                                         ;
  c->local_window += c->local_consumed;
  c->local_consumed = 0;
 }
 return 1;
}

static void
channel_post_open(struct ssh *ssh, Channel *c)
{
 channel_handle_rfd(ssh, c);
 channel_handle_wfd(ssh, c);
 channel_handle_efd(ssh, c);
 channel_check_window(ssh, c);
}

static u_int
read_mux(struct ssh *ssh, Channel *c, u_int need)
{
 char buf[(16*1024)];
 ssize_t len;
 u_int rlen;
 int r;

 if (sshbuf_len(c->input) < need) {
  rlen = need - sshbuf_len(c->input);
  len = read(c->rfd, buf, (((rlen) < ((16*1024))) ? (rlen) : ((16*1024))));
  if (len == -1 && (
                   (*__errno_location ()) 
                         == 
                            4 
                                  || 
                                     (*__errno_location ()) 
                                           == 
                                              11
                                                    ))
   return sshbuf_len(c->input);
  if (len <= 0) {
   sshlog("channels.c", __func__, 2222, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "channel %d: ctl read<=0 rfd %d len %zd", c->self, c->rfd, len)
                            ;
   chan_read_failed(ssh, c);
   return 0;
  } else if ((r = sshbuf_put(c->input, buf, len)) != 0)
   sshfatal("channels.c", __func__, 2227, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: append", c->self);
 }
 return sshbuf_len(c->input);
}

static void
channel_post_mux_client_read(struct ssh *ssh, Channel *c)
{
 u_int need;

 if ((c->io_ready & 0x01) == 0)
  return;
 if (c->istate != 0 && c->istate != 1)
  return;
 if (c->mux_pause)
  return;





 if (read_mux(ssh, c, 4) < 4)
  return;

 need = (((u_int32_t)(((const u_char *)(sshbuf_ptr(c->input)))[0]) << 24) | ((u_int32_t)(((const u_char *)(sshbuf_ptr(c->input)))[1]) << 16) | ((u_int32_t)(((const u_char *)(sshbuf_ptr(c->input)))[2]) << 8) | (u_int32_t)(((const u_char *)(sshbuf_ptr(c->input)))[3]));

 if (need > (256 * 1024)) {
  sshlog("channels.c", __func__, 2254, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: packet too big %u > %u", c->self, (256 * 1024), need)
                                            ;
  chan_rcvd_oclose(ssh, c);
  return;
 }
 if (read_mux(ssh, c, need + 4) < need + 4)
  return;
 if (c->mux_rcb(ssh, c) != 0) {
  sshlog("channels.c", __func__, 2262, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "channel %d: mux_rcb failed", c->self);
  chan_mark_dead(ssh, c);
  return;
 }
}

static void
channel_post_mux_client_write(struct ssh *ssh, Channel *c)
{
 ssize_t len;
 int r;

 if ((c->io_ready & 0x02) == 0)
  return;
 if (sshbuf_len(c->output) == 0)
  return;

 len = write(c->wfd, sshbuf_ptr(c->output), sshbuf_len(c->output));
 if (len == -1 && (
                  (*__errno_location ()) 
                        == 
                           4 
                                 || 
                                    (*__errno_location ()) 
                                          == 
                                             11
                                                   ))
  return;
 if (len <= 0) {
  chan_mark_dead(ssh, c);
  return;
 }
 if ((r = sshbuf_consume(c->output, len)) != 0)
  sshfatal("channels.c", __func__, 2287, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: consume", c->self);
}

static void
channel_post_mux_client(struct ssh *ssh, Channel *c)
{
 channel_post_mux_client_read(ssh, c);
 channel_post_mux_client_write(ssh, c);
}

static void
channel_post_mux_listener(struct ssh *ssh, Channel *c)
{
 Channel *nc;
 struct sockaddr_storage addr;
 socklen_t addrlen;
 int newsock;
 uid_t euid;
 gid_t egid;

 if ((c->io_ready & 0x10) == 0)
  return;

 sshlog("channels.c", __func__, 2310, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "multiplexing control connection");




 memset(&addr, 0, sizeof(addr));
 addrlen = sizeof(addr);
 if ((newsock = accept(c->sock, (struct sockaddr*)&addr,
     &addrlen)) == -1) {
  sshlog("channels.c", __func__, 2319, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "accept: %s", strerror(
 (*__errno_location ())
 ));
  if (
     (*__errno_location ()) 
           == 
              24 
                     || 
                        (*__errno_location ()) 
                              == 
                                 23
                                       )
   c->notbefore = monotime() + 1;
  return;
 }

 if (getpeereid(newsock, &euid, &egid) == -1) {
  sshlog("channels.c", __func__, 2326, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "getpeereid failed: %s", strerror(
 (*__errno_location ())
 ));
  close(newsock);
  return;
 }
 if ((euid != 0) && (getuid() != euid)) {
  sshlog("channels.c", __func__, 2331, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "multiplex uid mismatch: peer euid %u != uid %u", (u_int)euid, (u_int)getuid())
                                   ;
  close(newsock);
  return;
 }
 nc = channel_new(ssh, "multiplex client", 16,
     newsock, newsock, -1, c->local_window_max,
     c->local_maxpacket, 0, "mux-control", 1);
 nc->mux_rcb = c->mux_rcb;
 sshlog("channels.c", __func__, 2340, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "new mux channel %d fd %d", nc->self, nc->sock);

 nc->mux_rcb(ssh, nc);

 nc->flags |= 0x10;
}

static void
channel_handler_init(struct ssh_channels *sc)
{
 chan_fn **pre, **post;

 if ((pre = calloc(23, sizeof(*pre))) == 
                                                          ((void *)0) 
                                                               ||
     (post = calloc(23, sizeof(*post))) == 
                                                            ((void *)0)
                                                                )
  sshfatal("channels.c", __func__, 2354, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "allocation failed");

 pre[4] = &channel_pre_open;
 pre[7] = &channel_pre_x11_open;
 pre[2] = &channel_pre_listener;
 pre[11] = &channel_pre_listener;
 pre[18] = &channel_pre_listener;
 pre[19] = &channel_pre_listener;
 pre[1] = &channel_pre_listener;
 pre[6] = &channel_pre_listener;
 pre[12] = &channel_pre_connecting;
 pre[13] = &channel_pre_dynamic;
 pre[22] = &channel_pre_connecting;
 pre[15] = &channel_pre_listener;
 pre[16] = &channel_pre_mux_client;

 post[4] = &channel_post_open;
 post[2] = &channel_post_port_listener;
 post[11] = &channel_post_port_listener;
 post[18] = &channel_post_port_listener;
 post[19] = &channel_post_port_listener;
 post[1] = &channel_post_x11_listener;
 post[6] = &channel_post_auth_listener;
 post[12] = &channel_post_connecting;
 post[13] = &channel_post_open;
 post[22] = &channel_post_connecting;
 post[15] = &channel_post_mux_listener;
 post[16] = &channel_post_mux_client;

 sc->channel_pre = pre;
 sc->channel_post = post;
}


static void
channel_garbage_collect(struct ssh *ssh, Channel *c)
{
 if (c == 
         ((void *)0)
             )
  return;
 if (c->detach_user != 
                      ((void *)0)
                          ) {
  if (!chan_is_dead(ssh, c, c->detach_close))
   return;

  sshlog("channels.c", __func__, 2397, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: gc: notify user", c->self);
  c->detach_user(ssh, c->self, 
                              ((void *)0)
                                  );

  if (c->detach_user != 
                       ((void *)0)
                           )
   return;
  sshlog("channels.c", __func__, 2402, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: gc: user detached", c->self);
 }
 if (!chan_is_dead(ssh, c, 1))
  return;
 sshlog("channels.c", __func__, 2406, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: garbage collecting", c->self);
 channel_free(ssh, c);
}

enum channel_table { CHAN_PRE, CHAN_POST };

static void
channel_handler(struct ssh *ssh, int table, time_t *unpause_secs)
{
 struct ssh_channels *sc = ssh->chanctxt;
 chan_fn **ftab = table == CHAN_PRE ? sc->channel_pre : sc->channel_post;
 u_int i, oalloc;
 Channel *c;
 time_t now;

 now = monotime();
 if (unpause_secs != 
                    ((void *)0)
                        )
  *unpause_secs = 0;
 for (i = 0, oalloc = sc->channels_alloc; i < oalloc; i++) {
  c = sc->channels[i];
  if (c == 
          ((void *)0)
              )
   continue;

  if (ssh_packet_is_rekeying(ssh) && c->type != 4)
   continue;
  if (c->delayed) {
   if (table == CHAN_PRE)
    c->delayed = 0;
   else
    continue;
  }
  if (ftab[c->type] != 
                      ((void *)0)
                          ) {



   if (c->notbefore <= now)
    (*ftab[c->type])(ssh, c);
   else if (unpause_secs != 
                           ((void *)0)
                               ) {




    sshlog("channels.c", __func__, 2448, 1, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "chan %d: skip for %d more " "seconds", c->self, (int)(c->notbefore - now))

                                  ;
    if (*unpause_secs == 0 ||
        (c->notbefore - now) < *unpause_secs)
     *unpause_secs = c->notbefore - now;
   }
  }
  channel_garbage_collect(ssh, c);
 }
 if (unpause_secs != 
                    ((void *)0) 
                         && *unpause_secs != 0)
  sshlog("channels.c", __func__, 2459, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "first channel unpauses in %d seconds", (int)*unpause_secs)
                         ;
}







static void
channel_before_prepare_io(struct ssh *ssh)
{
 struct ssh_channels *sc = ssh->chanctxt;
 Channel *c;
 u_int i, oalloc;

 for (i = 0, oalloc = sc->channels_alloc; i < oalloc; i++) {
  c = sc->channels[i];
  if (c == 
          ((void *)0)
              )
   continue;
  if (c->type == 21)
   channel_before_prepare_io_rdynamic(ssh, c);
 }
}

static void
dump_channel_poll(const char *func, const char *what, Channel *c,
    u_int pollfd_offset, struct pollfd *pfd)
{
}


static void
channel_prepare_pollfd(Channel *c, u_int *next_pollfd,
    struct pollfd *pfd, u_int npfd)
{
 u_int ev, p = *next_pollfd;

 if (c == 
         ((void *)0)
             )
  return;
 if (p + 4 > npfd) {

  sshfatal("channels.c", __func__, 2511, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel %d: bad pfd offset %u (max %u)", c->self, p, npfd)
                       ;
 }
 c->pfds[0] = c->pfds[1] = c->pfds[2] = c->pfds[3] = -1;







 if (c->rfd != -1) {
  ev = 0;
  if ((c->io_want & 0x01) != 0)
   ev |= 
        0x001
              ;

  if (c->wfd == c->rfd) {
   if ((c->io_want & 0x02) != 0)
    ev |= 
         0x004
                ;
  }

  if (c->efd == c->rfd) {
   if ((c->io_want & 0x04) != 0)
    ev |= 
         0x001
               ;
   if ((c->io_want & 0x08) != 0)
    ev |= 
         0x004
                ;
  }

  if (c->sock == c->rfd) {
   if ((c->io_want & 0x10) != 0)
    ev |= 
         0x001
               ;
   if ((c->io_want & 0x20) != 0)
    ev |= 
         0x004
                ;
  }

  if (ev != 0) {
   c->pfds[0] = p;
   pfd[p].fd = c->rfd;
   pfd[p].events = ev;
   dump_channel_poll(__func__, "rfd", c, p, &pfd[p]);
   p++;
  }
 }

 if (c->wfd != -1 && c->rfd != c->wfd) {
  ev = 0;
  if ((c->io_want & 0x02))
   ev |= 
        0x004
               ;

  if (ev != 0) {
   c->pfds[1] = p;
   pfd[p].fd = c->wfd;
   pfd[p].events = ev;
   dump_channel_poll(__func__, "wfd", c, p, &pfd[p]);
   p++;
  }
 }

 if (c->efd != -1 && c->rfd != c->efd) {
  ev = 0;
  if ((c->io_want & 0x04) != 0)
   ev |= 
        0x001
              ;
  if ((c->io_want & 0x08) != 0)
   ev |= 
        0x004
               ;

  if (ev != 0) {
   c->pfds[2] = p;
   pfd[p].fd = c->efd;
   pfd[p].events = ev;
   dump_channel_poll(__func__, "efd", c, p, &pfd[p]);
   p++;
  }
 }

 if (c->sock != -1 && c->rfd != c->sock) {
  ev = 0;
  if ((c->io_want & 0x10) != 0)
   ev |= 
        0x001
              ;
  if ((c->io_want & 0x20) != 0)
   ev |= 
        0x004
               ;

  if (ev != 0) {
   c->pfds[3] = p;
   pfd[p].fd = c->sock;
   pfd[p].events = 0;
   dump_channel_poll(__func__, "sock", c, p, &pfd[p]);
   p++;
  }
 }
 *next_pollfd = p;
}


void
channel_prepare_poll(struct ssh *ssh, struct pollfd **pfdp, u_int *npfd_allocp,
    u_int *npfd_activep, u_int npfd_reserved, time_t *minwait_secs)
{
 struct ssh_channels *sc = ssh->chanctxt;
 u_int i, oalloc, p, npfd = npfd_reserved;

 channel_before_prepare_io(ssh);

 for (i = 0; i < sc->channels_alloc; i++) {
  if (sc->channels[i] == 
                        ((void *)0)
                            )
   continue;
  sc->channels[i]->io_want = sc->channels[i]->io_ready = 0;
 }

 if (sc->channels_alloc >= (0x7fffffff / 4) - npfd_reserved)
  sshfatal("channels.c", __func__, 2620, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "too many channels");
 npfd += sc->channels_alloc * 4;
 if (npfd > *npfd_allocp) {
  *pfdp = xrecallocarray(*pfdp, *npfd_allocp,
      npfd, sizeof(**pfdp));
  *npfd_allocp = npfd;
 }
 *npfd_activep = npfd_reserved;
 oalloc = sc->channels_alloc;

 channel_handler(ssh, CHAN_PRE, minwait_secs);

 if (oalloc != sc->channels_alloc) {

  sshfatal("channels.c", __func__, 2634, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channels_alloc changed during CHAN_PRE " "(was %u, now %u)", oalloc, sc->channels_alloc)
                                                     ;
 }


 p = npfd_reserved;
 for (i = 0; i < sc->channels_alloc; i++)
  channel_prepare_pollfd(sc->channels[i], &p, *pfdp, npfd);
 *npfd_activep = p;
}

static void
fd_ready(Channel *c, int p, struct pollfd *pfds, u_int npfd, int fd,
    const char *what, u_int revents_mask, u_int ready)
{
 struct pollfd *pfd = &pfds[p];

 if (fd == -1)
  return;
 if (p == -1 || (u_int)p >= npfd)
  sshfatal("channels.c", __func__, 2654, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel %d: bad pfd %d (max %u)", c->self, p, npfd);
 dump_channel_poll(__func__, what, c, p, pfd);
 if (pfd->fd != fd) {
  sshfatal("channels.c", __func__, 2657, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel %d: inconsistent %s fd=%d pollfd[%u].fd %d " "r%d w%d e%d s%d", c->self, what, fd, p, pfd->fd, c->rfd, c->wfd, c->efd, c->sock)

                                      ;
 }
 if ((pfd->revents & 
                    0x020
                            ) != 0) {
  sshfatal("channels.c", __func__, 2662, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel %d: invalid %s pollfd[%u].fd %d r%d w%d e%d s%d", c->self, what, p, pfd->fd, c->rfd, c->wfd, c->efd, c->sock)
                                                                 ;
 }
 if ((pfd->revents & (revents_mask|
                                  0x010
                                         |
                                          0x008
                                                 )) != 0)
  c->io_ready |= ready & c->io_want;
}





void
channel_after_poll(struct ssh *ssh, struct pollfd *pfd, u_int npfd)
{
 struct ssh_channels *sc = ssh->chanctxt;
 u_int i;
 int p;
 Channel *c;
 for (i = 0; i < sc->channels_alloc; i++) {
  c = sc->channels[i];
  if (c == 
          ((void *)0)
              )
   continue;

  if (c->rfd != -1 && c->wfd != -1 && c->rfd != c->wfd &&
      (c->rfd == c->efd || c->rfd == c->sock)) {

   sshfatal("channels.c", __func__, 2699, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "channel %d: unexpected fds r%d w%d e%d s%d", c->self, c->rfd, c->wfd, c->efd, c->sock)
                                                ;
  }
  c->io_ready = 0;

  if (c->rfd != -1 && (p = c->pfds[0]) != -1) {
   fd_ready(c, p, pfd, npfd, c->rfd,
       "rfd", 
             0x001
                   , 0x01);
   if (c->rfd == c->wfd) {
    fd_ready(c, p, pfd, npfd, c->wfd,
        "wfd/r", 
                0x004
                       , 0x02);
   }
   if (c->rfd == c->efd) {
    fd_ready(c, p, pfd, npfd, c->efd,
        "efdr/r", 
                 0x001
                       , 0x04);
    fd_ready(c, p, pfd, npfd, c->efd,
        "efdw/r", 
                 0x004
                        , 0x08);
   }
   if (c->rfd == c->sock) {
    fd_ready(c, p, pfd, npfd, c->sock,
        "sockr/r", 
                  0x001
                        , 0x10);
    fd_ready(c, p, pfd, npfd, c->sock,
        "sockw/r", 
                  0x004
                         , 0x20);
   }
   dump_channel_poll(__func__, "rfd", c, p, pfd);
  }

  if (c->wfd != -1 && c->wfd != c->rfd &&
      (p = c->pfds[1]) != -1) {
   fd_ready(c, p, pfd, npfd, c->wfd,
       "wfd", 
             0x004
                    , 0x02);
   dump_channel_poll(__func__, "wfd", c, p, pfd);
  }

  if (c->efd != -1 && c->efd != c->rfd &&
      (p = c->pfds[2]) != -1) {
   fd_ready(c, p, pfd, npfd, c->efd,
       "efdr", 
              0x001
                    , 0x04);
   fd_ready(c, p, pfd, npfd, c->efd,
       "efdw", 
              0x004
                     , 0x08);
   dump_channel_poll(__func__, "efd", c, p, pfd);
  }

  if (c->sock != -1 && c->sock != c->rfd &&
      (p = c->pfds[3]) != -1) {
   fd_ready(c, p, pfd, npfd, c->sock,
       "sockr", 
               0x001
                     , 0x10);
   fd_ready(c, p, pfd, npfd, c->sock,
       "sockw", 
               0x004
                      , 0x20);
   dump_channel_poll(__func__, "sock", c, p, pfd);
  }
 }
 channel_handler(ssh, CHAN_POST, 
                                ((void *)0)
                                    );
}




static void
channel_output_poll_input_open(struct ssh *ssh, Channel *c)
{
 size_t len, plen;
 const u_char *pkt;
 int r;

 if ((len = sshbuf_len(c->input)) == 0) {
  if (c->istate == 1) {







   if ((c->extended_usage == 1 && (c->efd != -1 || sshbuf_len(c->extended) > 0)))
    sshlog("channels.c", __func__, 2774, 0, SYSLOG_LEVEL_DEBUG2, 
   ((void *)0)
   , "channel %d: " "ibuf_empty delayed efd %d/(%zu)", c->self, c->efd, sshbuf_len(c->extended))

                                                 ;
   else
    chan_ibuf_empty(ssh, c);
  }
  return;
 }

 if (!c->have_remote_id)
  sshfatal("channels.c", __func__, 2784, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel %d: no remote id", c->self);

 if (c->datagram) {

  if ((r = sshbuf_get_string_direct(c->input, &pkt, &plen)) != 0)
   sshfatal("channels.c", __func__, 2789, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: get datagram", c->self);





  if (plen > c->remote_window || plen > c->remote_maxpacket) {
   sshlog("channels.c", __func__, 2796, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "channel %d: datagram too big", c->self);
   return;
  }

  if ((r = sshpkt_start(ssh, 94)) != 0 ||
      (r = sshpkt_put_u32(ssh, c->remote_id)) != 0 ||
      (r = sshpkt_put_string(ssh, pkt, plen)) != 0 ||
      (r = sshpkt_send(ssh)) != 0)
   sshfatal("channels.c", __func__, 2804, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: send datagram", c->self);
  c->remote_window -= plen;
  return;
 }


 if (len > c->remote_window)
  len = c->remote_window;
 if (len > c->remote_maxpacket)
  len = c->remote_maxpacket;
 if (len == 0)
  return;
 if ((r = sshpkt_start(ssh, 94)) != 0 ||
     (r = sshpkt_put_u32(ssh, c->remote_id)) != 0 ||
     (r = sshpkt_put_string(ssh, sshbuf_ptr(c->input), len)) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  sshfatal("channels.c", __func__, 2820, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: send data", c->self);
 if ((r = sshbuf_consume(c->input, len)) != 0)
  sshfatal("channels.c", __func__, 2822, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: consume", c->self);
 c->remote_window -= len;
}




static void
channel_output_poll_extended_read(struct ssh *ssh, Channel *c)
{
 size_t len;
 int r;

 if ((len = sshbuf_len(c->extended)) == 0)
  return;

 sshlog("channels.c", __func__, 2838, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: rwin %u elen %zu euse %d", c->self, c->remote_window, sshbuf_len(c->extended), c->extended_usage)
                                                                  ;
 if (len > c->remote_window)
  len = c->remote_window;
 if (len > c->remote_maxpacket)
  len = c->remote_maxpacket;
 if (len == 0)
  return;
 if (!c->have_remote_id)
  sshfatal("channels.c", __func__, 2847, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel %d: no remote id", c->self);
 if ((r = sshpkt_start(ssh, 95)) != 0 ||
     (r = sshpkt_put_u32(ssh, c->remote_id)) != 0 ||
     (r = sshpkt_put_u32(ssh, 1)) != 0 ||
     (r = sshpkt_put_string(ssh, sshbuf_ptr(c->extended), len)) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  sshfatal("channels.c", __func__, 2853, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: data", c->self);
 if ((r = sshbuf_consume(c->extended, len)) != 0)
  sshfatal("channels.c", __func__, 2855, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: consume", c->self);
 c->remote_window -= len;
 sshlog("channels.c", __func__, 2857, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: sent ext data %zu", c->self, len);
}


void
channel_output_poll(struct ssh *ssh)
{
 struct ssh_channels *sc = ssh->chanctxt;
 Channel *c;
 u_int i;

 for (i = 0; i < sc->channels_alloc; i++) {
  c = sc->channels[i];
  if (c == 
          ((void *)0)
              )
   continue;





  if (c->type != 4)
   continue;
  if ((c->flags & (0x01|0x02))) {

   sshlog("channels.c", __func__, 2881, 0, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "channel %d: will not send data after close", c->self)
               ;
   continue;
  }


  if (c->istate == 0 ||
      c->istate == 1)
   channel_output_poll_input_open(ssh, c);

  if (!(c->flags & 0x04) &&
      c->extended_usage == 1)
   channel_output_poll_extended_read(ssh, c);
 }
}
int
channel_proxy_downstream(struct ssh *ssh, Channel *downstream)
{
 Channel *c = 
             ((void *)0)
                 ;
 struct sshbuf *original = 
                          ((void *)0)
                              , *modified = 
                                            ((void *)0)
                                                ;
 const u_char *cp;
 char *ctype = 
              ((void *)0)
                  , *listen_host = 
                                   ((void *)0)
                                       ;
 u_char type;
 size_t have;
 int ret = -1, r;
 u_int id, remote_id, listen_port;


 if ((r = sshbuf_get_string_direct(downstream->input, &cp, &have))
     != 0) {
  sshlog("channels.c", __func__, 2952, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse");
  return -1;
 }
 if (have < 2) {
  sshlog("channels.c", __func__, 2956, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "short message");
  return -1;
 }
 type = cp[1];

 cp += 2;
 have -= 2;
 if (ssh_packet_log_type(type))
  sshlog("channels.c", __func__, 2964, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "channel %u: down->up: type %u", downstream->self, type)
                             ;

 switch (type) {
 case 90:
  if ((original = sshbuf_from(cp, have)) == 
                                           ((void *)0) 
                                                ||
      (modified = sshbuf_new()) == 
                                  ((void *)0)
                                      ) {
   sshlog("channels.c", __func__, 2971, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "alloc");
   goto out;
  }
  if ((r = sshbuf_get_cstring(original, &ctype, 
                                               ((void *)0)
                                                   )) != 0 ||
      (r = sshbuf_get_u32(original, &id)) != 0) {
   sshlog("channels.c", __func__, 2976, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse");
   goto out;
  }
  c = channel_new(ssh, "mux proxy", 20,
      -1, -1, -1, 0, 0, 0, ctype, 1);
  c->mux_ctx = downstream;
  c->mux_downstream_id = id;
  if ((r = sshbuf_put_cstring(modified, ctype)) != 0 ||
      (r = sshbuf_put_u32(modified, c->self)) != 0 ||
      (r = sshbuf_putb(modified, original)) != 0) {
   sshlog("channels.c", __func__, 2986, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "compose");
   channel_free(ssh, c);
   goto out;
  }
  break;
 case 91:




  if ((original = sshbuf_from(cp, have)) == 
                                           ((void *)0) 
                                                ||
      (modified = sshbuf_new()) == 
                                  ((void *)0)
                                      ) {
   sshlog("channels.c", __func__, 2998, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "alloc");
   goto out;
  }
  if ((r = sshbuf_get_u32(original, &remote_id)) != 0 ||
      (r = sshbuf_get_u32(original, &id)) != 0) {
   sshlog("channels.c", __func__, 3003, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse");
   goto out;
  }
  c = channel_new(ssh, "mux proxy", 20,
      -1, -1, -1, 0, 0, 0, "mux-down-connect", 1);
  c->mux_ctx = downstream;
  c->mux_downstream_id = id;
  c->remote_id = remote_id;
  c->have_remote_id = 1;
  if ((r = sshbuf_put_u32(modified, remote_id)) != 0 ||
      (r = sshbuf_put_u32(modified, c->self)) != 0 ||
      (r = sshbuf_putb(modified, original)) != 0) {
   sshlog("channels.c", __func__, 3015, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "compose");
   channel_free(ssh, c);
   goto out;
  }
  break;
 case 80:
  if ((original = sshbuf_from(cp, have)) == 
                                           ((void *)0)
                                               ) {
   sshlog("channels.c", __func__, 3022, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "alloc");
   goto out;
  }
  if ((r = sshbuf_get_cstring(original, &ctype, 
                                               ((void *)0)
                                                   )) != 0) {
   sshlog("channels.c", __func__, 3026, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse");
   goto out;
  }
  if (strcmp(ctype, "tcpip-forward") != 0) {
   sshlog("channels.c", __func__, 3030, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "unsupported request %s", ctype);
   goto out;
  }
  if ((r = sshbuf_get_u8(original, 
                                  ((void *)0)
                                      )) != 0 ||
      (r = sshbuf_get_cstring(original, &listen_host, 
                                                     ((void *)0)
                                                         )) != 0 ||
      (r = sshbuf_get_u32(original, &listen_port)) != 0) {
   sshlog("channels.c", __func__, 3036, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse");
   goto out;
  }
  if (listen_port > 65535) {
   sshlog("channels.c", __func__, 3040, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "tcpip-forward for %s: bad port %u", listen_host, listen_port)
                                ;
   goto out;
  }

  permission_set_add(ssh, 0x101, (1<<1), "<mux>", -1,
      listen_host, 
                  ((void *)0)
                      , (int)listen_port, downstream);
  listen_host = 
               ((void *)0)
                   ;
  break;
 case 97:
  if (have < 4)
   break;
  remote_id = (((u_int32_t)(((const u_char *)(cp))[0]) << 24) | ((u_int32_t)(((const u_char *)(cp))[1]) << 16) | ((u_int32_t)(((const u_char *)(cp))[2]) << 8) | (u_int32_t)(((const u_char *)(cp))[3]));
  if ((c = channel_by_remote_id(ssh, remote_id)) != 
                                                   ((void *)0)
                                                       ) {
   if (c->flags & 0x02)
    channel_free(ssh, c);
   else
    c->flags |= 0x01;
  }
  break;
 }
 if (modified) {
  if ((r = sshpkt_start(ssh, type)) != 0 ||
      (r = sshpkt_putb(ssh, modified)) != 0 ||
      (r = sshpkt_send(ssh)) != 0) {
   sshlog("channels.c", __func__, 3065, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "send");
   goto out;
  }
 } else {
  if ((r = sshpkt_start(ssh, type)) != 0 ||
      (r = sshpkt_put(ssh, cp, have)) != 0 ||
      (r = sshpkt_send(ssh)) != 0) {
   sshlog("channels.c", __func__, 3072, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "send");
   goto out;
  }
 }
 ret = 0;
 out:
 free(ctype);
 free(listen_host);
 sshbuf_free(original);
 sshbuf_free(modified);
 return ret;
}







int
channel_proxy_upstream(Channel *c, int type, u_int32_t seq, struct ssh *ssh)
{
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 Channel *downstream;
 const u_char *cp = 
                   ((void *)0)
                       ;
 size_t len;
 int r;







 if (c == 
         ((void *)0) 
              || c->type != 20)
  return 0;
 if ((downstream = c->mux_ctx) == 
                                 ((void *)0)
                                     )
  return 0;
 switch (type) {
 case 97:
 case 94:
 case 96:
 case 95:
 case 91:
 case 92:
 case 93:
 case 99:
 case 100:
 case 98:
  break;
 default:
  sshlog("channels.c", __func__, 3123, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %u: unsupported type %u", c->self, type);
  return 0;
 }
 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              ) {
  sshlog("channels.c", __func__, 3127, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "alloc reply");
  goto out;
 }

 cp = sshpkt_ptr(ssh, &len);
 if (cp == 
          ((void *)0)
              ) {
  sshlog("channels.c", __func__, 3133, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "no packet");
  goto out;
 }

 if ((r = sshbuf_put_u8(b, 0)) != 0 ||
     (r = sshbuf_put_u8(b, type)) != 0 ||
     (r = sshbuf_put_u32(b, c->mux_downstream_id)) != 0 ||
     (r = sshbuf_put(b, cp, len)) != 0 ||
     (r = sshbuf_put_stringb(downstream->output, b)) != 0) {
  sshlog("channels.c", __func__, 3142, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "compose muxclient");
  goto out;
 }

 if (ssh_packet_log_type(type))
  sshlog("channels.c", __func__, 3147, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "channel %u: up->down: type %u", c->self, type);
 out:

 switch (type) {
 case 91:

  if (cp && len > 4) {
   c->remote_id = (((u_int32_t)(((const u_char *)(cp))[0]) << 24) | ((u_int32_t)(((const u_char *)(cp))[1]) << 16) | ((u_int32_t)(((const u_char *)(cp))[2]) << 8) | (u_int32_t)(((const u_char *)(cp))[3]));
   c->have_remote_id = 1;
  }
  break;
 case 97:
  if (c->flags & 0x01)
   channel_free(ssh, c);
  else
   c->flags |= 0x02;
  break;
 }
 sshbuf_free(b);
 return 1;
}




static int
channel_parse_id(struct ssh *ssh, const char *where, const char *what)
{
 u_int32_t id;
 int r;

 if ((r = sshpkt_get_u32(ssh, &id)) != 0) {
  sshlog("channels.c", __func__, 3179, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "%s: parse id", where);
  ssh_packet_disconnect(ssh, "Invalid %s message", what);
 }
 if (id > 0x7fffffff) {
  sshlog("channels.c", __func__, 3183, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "%s: bad channel id %u", where, id);
  ssh_packet_disconnect(ssh, "Invalid %s channel id", what);
 }
 return (int)id;
}


static Channel *
channel_from_packet_id(struct ssh *ssh, const char *where, const char *what)
{
 int id = channel_parse_id(ssh, where, what);
 Channel *c;

 if ((c = channel_lookup(ssh, id)) == 
                                     ((void *)0)
                                         ) {
  ssh_packet_disconnect(ssh,
      "%s packet referred to nonexistent channel %d", what, id);
 }
 return c;
}

int
channel_input_data(int type, u_int32_t seq, struct ssh *ssh)
{
 const u_char *data;
 size_t data_len, win_len;
 Channel *c = channel_from_packet_id(ssh, __func__, "data");
 int r;

 if (channel_proxy_upstream(c, type, seq, ssh))
  return 0;


 if (c->type != 4 &&
     c->type != 21 &&
     c->type != 22 &&
     c->type != 7)
  return 0;


 if ((r = sshpkt_get_string_direct(ssh, &data, &data_len)) != 0 ||
            (r = sshpkt_get_end(ssh)) != 0)
  sshfatal("channels.c", __func__, 3224, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: get data", c->self);

 win_len = data_len;
 if (c->datagram)
  win_len += 4;






 if (c->ostate != 0) {
  c->local_window -= win_len;
  c->local_consumed += win_len;
  return 0;
 }

 if (win_len > c->local_maxpacket) {
  sshlog("channels.c", __func__, 3242, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "channel %d: rcvd big packet %zu, maxpack %u", c->self, win_len, c->local_maxpacket)
                                           ;
  return 0;
 }
 if (win_len > c->local_window) {
  sshlog("channels.c", __func__, 3247, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "channel %d: rcvd too much data %zu, win %u", c->self, win_len, c->local_window)
                                        ;
  return 0;
 }
 c->local_window -= win_len;

 if (c->datagram) {
  if ((r = sshbuf_put_string(c->output, data, data_len)) != 0)
   sshfatal("channels.c", __func__, 3255, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: append datagram", c->self);
 } else if ((r = sshbuf_put(c->output, data, data_len)) != 0)
  sshfatal("channels.c", __func__, 3257, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i: append data", c->self);

 return 0;
}

int
channel_input_extended_data(int type, u_int32_t seq, struct ssh *ssh)
{
 const u_char *data;
 size_t data_len;
 u_int32_t tcode;
 Channel *c = channel_from_packet_id(ssh, __func__, "extended data");
 int r;

 if (channel_proxy_upstream(c, type, seq, ssh))
  return 0;
 if (c->type != 4) {
  sshlog("channels.c", __func__, 3274, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "channel %d: ext data for non open", c->self);
  return 0;
 }
 if (c->flags & 0x08) {
  if (ssh->compat & 0x00200000)
   sshlog("channels.c", __func__, 3279, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "channel %d: accepting ext data after eof", c->self)
               ;
  else
   ssh_packet_disconnect(ssh, "Received extended_data "
       "after EOF on channel %d.", c->self);
 }

 if ((r = sshpkt_get_u32(ssh, &tcode)) != 0) {
  sshlog("channels.c", __func__, 3287, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse tcode");
  ssh_packet_disconnect(ssh, "Invalid extended_data message");
 }
 if (c->efd == -1 ||
     c->extended_usage != 2 ||
     tcode != 1) {
  sshlog("channels.c", __func__, 3293, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "channel %d: bad ext data", c->self);
  return 0;
 }
 if ((r = sshpkt_get_string_direct(ssh, &data, &data_len)) != 0 ||
            (r = sshpkt_get_end(ssh)) != 0) {
  sshlog("channels.c", __func__, 3298, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse data");
  ssh_packet_disconnect(ssh, "Invalid extended_data message");
 }

 if (data_len > c->local_window) {
  sshlog("channels.c", __func__, 3303, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "channel %d: rcvd too much extended_data %zu, win %u", c->self, data_len, c->local_window)
                                         ;
  return 0;
 }
 sshlog("channels.c", __func__, 3307, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: rcvd ext data %zu", c->self, data_len);

 if ((r = sshbuf_put(c->extended, data, data_len)) != 0)
  sshlog("channels.c", __func__, 3310, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "append");
 c->local_window -= data_len;
 return 0;
}

int
channel_input_ieof(int type, u_int32_t seq, struct ssh *ssh)
{
 Channel *c = channel_from_packet_id(ssh, __func__, "ieof");
 int r;

        if ((r = sshpkt_get_end(ssh)) != 0) {
  sshlog("channels.c", __func__, 3322, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse data");
  ssh_packet_disconnect(ssh, "Invalid ieof message");
 }

 if (channel_proxy_upstream(c, type, seq, ssh))
  return 0;
 chan_rcvd_ieof(ssh, c);


 if (c->force_drain && c->istate == 0) {
  sshlog("channels.c", __func__, 3332, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "channel %d: FORCE input drain", c->self);
  c->istate = 1;
  if (sshbuf_len(c->input) == 0)
   chan_ibuf_empty(ssh, c);
 }
 return 0;
}

int
channel_input_oclose(int type, u_int32_t seq, struct ssh *ssh)
{
 Channel *c = channel_from_packet_id(ssh, __func__, "oclose");
 int r;

 if (channel_proxy_upstream(c, type, seq, ssh))
  return 0;
        if ((r = sshpkt_get_end(ssh)) != 0) {
  sshlog("channels.c", __func__, 3349, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse data");
  ssh_packet_disconnect(ssh, "Invalid oclose message");
 }
 chan_rcvd_oclose(ssh, c);
 return 0;
}

int
channel_input_open_confirmation(int type, u_int32_t seq, struct ssh *ssh)
{
 Channel *c = channel_from_packet_id(ssh, __func__, "open confirmation");
 u_int32_t remote_window, remote_maxpacket;
 int r;

 if (channel_proxy_upstream(c, type, seq, ssh))
  return 0;
 if (c->type != 3)
  ssh_packet_disconnect(ssh, "Received open confirmation for "
      "non-opening channel %d.", c->self);




 if ((r = sshpkt_get_u32(ssh, &c->remote_id)) != 0 ||
     (r = sshpkt_get_u32(ssh, &remote_window)) != 0 ||
     (r = sshpkt_get_u32(ssh, &remote_maxpacket)) != 0 ||
            (r = sshpkt_get_end(ssh)) != 0) {
  sshlog("channels.c", __func__, 3376, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "window/maxpacket");
  ssh_packet_disconnect(ssh, "Invalid open confirmation message");
 }

 c->have_remote_id = 1;
 c->remote_window = remote_window;
 c->remote_maxpacket = remote_maxpacket;
 c->type = 4;
 if (c->open_confirm) {
  sshlog("channels.c", __func__, 3385, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: callback start", c->self);
  c->open_confirm(ssh, c->self, 1, c->open_confirm_ctx);
  sshlog("channels.c", __func__, 3387, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: callback done", c->self);
 }
 sshlog("channels.c", __func__, 3389, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: open confirm rwindow %u rmax %u", c->self, c->remote_window, c->remote_maxpacket)
                                           ;
 return 0;
}

static char *
reason2txt(int reason)
{
 switch (reason) {
 case 1:
  return "administratively prohibited";
 case 2:
  return "connect failed";
 case 3:
  return "unknown channel type";
 case 4:
  return "resource shortage";
 }
 return "unknown reason";
}

int
channel_input_open_failure(int type, u_int32_t seq, struct ssh *ssh)
{
 Channel *c = channel_from_packet_id(ssh, __func__, "open failure");
 u_int32_t reason;
 char *msg = 
            ((void *)0)
                ;
 int r;

 if (channel_proxy_upstream(c, type, seq, ssh))
  return 0;
 if (c->type != 3)
  ssh_packet_disconnect(ssh, "Received open failure for "
      "non-opening channel %d.", c->self);
 if ((r = sshpkt_get_u32(ssh, &reason)) != 0) {
  sshlog("channels.c", __func__, 3424, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse reason");
  ssh_packet_disconnect(ssh, "Invalid open failure message");
 }

 if ((r = sshpkt_get_cstring(ssh, &msg, 
                                       ((void *)0)
                                           )) != 0 ||
     (r = sshpkt_get_string_direct(ssh, 
                                       ((void *)0)
                                           , 
                                             ((void *)0)
                                                 )) != 0 ||
            (r = sshpkt_get_end(ssh)) != 0) {
  sshlog("channels.c", __func__, 3431, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse msg/lang");
  ssh_packet_disconnect(ssh, "Invalid open failure message");
 }
 sshlog("channels.c", __func__, 3434, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "channel %d: open failed: %s%s%s", c->self, reason2txt(reason), msg ? ": ": "", msg ? msg : "")
                                                        ;
 free(msg);
 if (c->open_confirm) {
  sshlog("channels.c", __func__, 3438, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: callback start", c->self);
  c->open_confirm(ssh, c->self, 0, c->open_confirm_ctx);
  sshlog("channels.c", __func__, 3440, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: callback done", c->self);
 }

 chan_mark_dead(ssh, c);
 return 0;
}

int
channel_input_window_adjust(int type, u_int32_t seq, struct ssh *ssh)
{
 int id = channel_parse_id(ssh, __func__, "window adjust");
 Channel *c;
 u_int32_t adjust;
 u_int new_rwin;
 int r;

 if ((c = channel_lookup(ssh, id)) == 
                                     ((void *)0)
                                         ) {
  sshlog("channels.c", __func__, 3457, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Received window adjust for non-open channel %d.", id);
  return 0;
 }

 if (channel_proxy_upstream(c, type, seq, ssh))
  return 0;
 if ((r = sshpkt_get_u32(ssh, &adjust)) != 0 ||
            (r = sshpkt_get_end(ssh)) != 0) {
  sshlog("channels.c", __func__, 3465, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse adjust");
  ssh_packet_disconnect(ssh, "Invalid window adjust message");
 }
 sshlog("channels.c", __func__, 3468, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: rcvd adjust %u", c->self, adjust);
 if ((new_rwin = c->remote_window + adjust) < c->remote_window) {
  sshfatal("channels.c", __func__, 3470, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel %d: adjust %u overflows remote window %u", c->self, adjust, c->remote_window)
                                        ;
 }
 c->remote_window = new_rwin;
 return 0;
}

int
channel_input_status_confirm(int type, u_int32_t seq, struct ssh *ssh)
{
 int id = channel_parse_id(ssh, __func__, "status confirm");
 Channel *c;
 struct channel_confirm *cc;


 ssh_packet_set_alive_timeouts(ssh, 0);

 sshlog("channels.c", __func__, 3487, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "type %d id %d", type, id);

 if ((c = channel_lookup(ssh, id)) == 
                                     ((void *)0)
                                         ) {
  sshlog("channels.c", __func__, 3490, 1, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "%d: unknown", id);
  return 0;
 }
 if (channel_proxy_upstream(c, type, seq, ssh))
  return 0;
        if (sshpkt_get_end(ssh) != 0)
  ssh_packet_disconnect(ssh, "Invalid status confirm message");
 if ((cc = ((&c->status_confirms)->tqh_first)) == 
                                               ((void *)0)
                                                   )
  return 0;
 cc->cb(ssh, type, c, cc->ctx);
 do { if (((cc)->entry.tqe_next) != 
((void *)0)
) (cc)->entry.tqe_next->entry.tqe_prev = (cc)->entry.tqe_prev; else (&c->status_confirms)->tqh_last = (cc)->entry.tqe_prev; *(cc)->entry.tqe_prev = (cc)->entry.tqe_next; ; ; } while (0);
 freezero(cc, sizeof(*cc));
 return 0;
}



void
channel_set_af(struct ssh *ssh, int af)
{
 ssh->chanctxt->IPv4or6 = af;
}
static const char *
channel_fwd_bind_addr(struct ssh *ssh, const char *listen_addr, int *wildcardp,
    int is_client, struct ForwardOptions *fwd_opts)
{
 const char *addr = 
                   ((void *)0)
                       ;
 int wildcard = 0;

 if (listen_addr == 
                   ((void *)0)
                       ) {

  if (fwd_opts->gateway_ports)
   wildcard = 1;
 } else if (fwd_opts->gateway_ports || is_client) {
  if (((ssh->compat & 0x01000000) &&
      strcmp(listen_addr, "0.0.0.0") == 0 && is_client == 0) ||
      *listen_addr == '\0' || strcmp(listen_addr, "*") == 0 ||
      (!is_client && fwd_opts->gateway_ports == 1)) {
   wildcard = 1;




   if (*listen_addr != '\0' &&
       strcmp(listen_addr, "0.0.0.0") != 0 &&
       strcmp(listen_addr, "*") != 0) {
    ssh_packet_send_debug(ssh,
        "Forwarding listen address "
        "\"%s\" overridden by server "
        "GatewayPorts", listen_addr);
   }
  } else if (strcmp(listen_addr, "localhost") != 0 ||
      strcmp(listen_addr, "127.0.0.1") == 0 ||
      strcmp(listen_addr, "::1") == 0) {






   addr = listen_addr;
  }
 } else if (strcmp(listen_addr, "127.0.0.1") == 0 ||
     strcmp(listen_addr, "::1") == 0) {





  addr = listen_addr;
 }
 if (wildcardp != 
                 ((void *)0)
                     )
  *wildcardp = wildcard;
 return addr;
}

static int
channel_setup_fwd_listener_tcpip(struct ssh *ssh, int type,
    struct Forward *fwd, int *allocated_listen_port,
    struct ForwardOptions *fwd_opts)
{
 Channel *c;
 int sock, r, success = 0, wildcard = 0, is_client;
 struct addrinfo hints, *ai, *aitop;
 const char *host, *addr;
 char ntop[
          1025
                    ], strport[
                               32
                                         ];
 in_port_t *lport_p;

 is_client = (type == 2);

 if (is_client && fwd->connect_path != 
                                      ((void *)0)
                                          ) {
  host = fwd->connect_path;
 } else {
  host = (type == 11) ?
      fwd->listen_host : fwd->connect_host;
  if (host == 
             ((void *)0)
                 ) {
   sshlog("channels.c", __func__, 3603, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "No forward host name.");
   return 0;
  }
  if (strlen(host) >= 
                     1025
                               ) {
   sshlog("channels.c", __func__, 3607, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Forward host name too long.");
   return 0;
  }
 }


 addr = channel_fwd_bind_addr(ssh, fwd->listen_host, &wildcard,
     is_client, fwd_opts);
 sshlog("channels.c", __func__, 3615, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "type %d wildcard %d addr %s", type, wildcard, (addr == 
((void *)0)
) ? "NULL" : addr)
                                    ;





 memset(&hints, 0, sizeof(hints));
 hints.ai_family = ssh->chanctxt->IPv4or6;
 hints.ai_flags = wildcard ? 
                            0x0001 
                                       : 0;
 hints.ai_socktype = 
                    SOCK_STREAM
                               ;
 snprintf(strport, sizeof strport, "%d", fwd->listen_port);
 if ((r = getaddrinfo(addr, strport, &hints, &aitop)) != 0) {
  if (addr == 
             ((void *)0)
                 ) {

   ssh_packet_disconnect(ssh, "getaddrinfo: fatal error: %s",
       ssh_gai_strerror(r));
  } else {
   sshlog("channels.c", __func__, 3633, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "getaddrinfo(%.64s): %s", addr, ssh_gai_strerror(r))
                           ;
  }
  return 0;
 }
 if (allocated_listen_port != 
                             ((void *)0)
                                 )
  *allocated_listen_port = 0;
 for (ai = aitop; ai; ai = ai->ai_next) {
  switch (ai->ai_family) {
  case 
      2
             :
   lport_p = &((struct sockaddr_in *)ai->ai_addr)->
       sin_port;
   break;
  case 
      10
              :
   lport_p = &((struct sockaddr_in6 *)ai->ai_addr)->
       sin6_port;
   break;
  default:
   continue;
  }




  if (type == 11 &&
      fwd->listen_port == 0 && allocated_listen_port != 
                                                       ((void *)0) 
                                                            &&
      *allocated_listen_port > 0)
   *lport_p = htons(*allocated_listen_port);

  if (getnameinfo(ai->ai_addr, ai->ai_addrlen, ntop, sizeof(ntop),
      strport, sizeof(strport),
      
     1
                   |
                    2
                                  ) != 0) {
   sshlog("channels.c", __func__, 3665, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "getnameinfo failed");
   continue;
  }

  sock = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
  if (sock == -1) {

   sshlog("channels.c", __func__, 3672, 0, SYSLOG_LEVEL_VERBOSE, 
  ((void *)0)
  , "socket [%s]:%s: %.100s", ntop, strport, strerror(
  (*__errno_location ())
  ))
                       ;
   continue;
  }

  set_reuseaddr(sock);
  if (ai->ai_family == 
                      10
                              )
   sock_set_v6only(sock);

  sshlog("channels.c", __func__, 3681, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Local forwarding listening on %s port %s.", ntop, strport)
                    ;


  if (bind(sock, ai->ai_addr, ai->ai_addrlen) == -1) {




   if (!ai->ai_next)
    sshlog("channels.c", __func__, 3691, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "bind [%s]:%s: %.100s", ntop, strport, strerror(
   (*__errno_location ())
   ))
                                       ;
   else
    sshlog("channels.c", __func__, 3694, 0, SYSLOG_LEVEL_VERBOSE, 
   ((void *)0)
   , "bind [%s]:%s: %.100s", ntop, strport, strerror(
   (*__errno_location ())
   ))
                                       ;

   close(sock);
   continue;
  }

  if (listen(sock, 128) == -1) {
   sshlog("channels.c", __func__, 3702, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "listen [%s]:%s: %.100s", ntop, strport, strerror(
  (*__errno_location ())
  ))
                       ;
   close(sock);
   continue;
  }





  if (type == 11 &&
      fwd->listen_port == 0 &&
      allocated_listen_port != 
                              ((void *)0) 
                                   &&
      *allocated_listen_port == 0) {
   *allocated_listen_port = get_local_port(sock);
   sshlog("channels.c", __func__, 3717, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Allocated listen port %d", *allocated_listen_port)
                              ;
  }


  c = channel_new(ssh, "port listener", type, sock, sock, -1,
      (64*(32*1024)), (32*1024),
      0, "port listener", 1);
  c->path = xstrdup(host);
  c->host_port = fwd->connect_port;
  c->listening_addr = addr == 
                             ((void *)0) 
                                  ? 
                                    ((void *)0) 
                                         : xstrdup(addr);
  if (fwd->listen_port == 0 && allocated_listen_port != 
                                                       ((void *)0) 
                                                            &&
      !(ssh->compat & 0x08000000))
   c->listening_port = *allocated_listen_port;
  else
   c->listening_port = fwd->listen_port;
  success = 1;
 }
 if (success == 0)
  sshlog("channels.c", __func__, 3736, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "cannot listen to port: %d", fwd->listen_port);
 freeaddrinfo(aitop);
 return success;
}

static int
channel_setup_fwd_listener_streamlocal(struct ssh *ssh, int type,
    struct Forward *fwd, struct ForwardOptions *fwd_opts)
{
 struct sockaddr_un sunaddr;
 const char *path;
 Channel *c;
 int port, sock;
 mode_t omask;

 switch (type) {
 case 18:
  if (fwd->connect_path != 
                          ((void *)0)
                              ) {
   if (strlen(fwd->connect_path) > sizeof(sunaddr.sun_path)) {
    sshlog("channels.c", __func__, 3755, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Local connecting path too long: %s", fwd->connect_path)
                          ;
    return 0;
   }
   path = fwd->connect_path;
   port = -2;
  } else {
   if (fwd->connect_host == 
                           ((void *)0)
                               ) {
    sshlog("channels.c", __func__, 3763, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "No forward host name.");
    return 0;
   }
   if (strlen(fwd->connect_host) >= 
                                   1025
                                             ) {
    sshlog("channels.c", __func__, 3767, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Forward host name too long.");
    return 0;
   }
   path = fwd->connect_host;
   port = fwd->connect_port;
  }
  break;
 case 19:
  path = fwd->listen_path;
  port = -2;
  break;
 default:
  sshlog("channels.c", __func__, 3779, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unexpected channel type %d", type);
  return 0;
 }

 if (fwd->listen_path == 
                        ((void *)0)
                            ) {
  sshlog("channels.c", __func__, 3784, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "No forward path name.");
  return 0;
 }
 if (strlen(fwd->listen_path) > sizeof(sunaddr.sun_path)) {
  sshlog("channels.c", __func__, 3788, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Local listening path too long: %s", fwd->listen_path);
  return 0;
 }

 sshlog("channels.c", __func__, 3792, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "type %d path %s", type, fwd->listen_path);


 omask = umask(fwd_opts->streamlocal_bind_mask);
 sock = unix_listener(fwd->listen_path, 128,
     fwd_opts->streamlocal_bind_unlink);
 umask(omask);
 if (sock < 0)
  return 0;

 sshlog("channels.c", __func__, 3802, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Local forwarding listening on path %s.", fwd->listen_path);


 c = channel_new(ssh, "unix listener", type, sock, sock, -1,
     (64*(32*1024)), (32*1024),
     0, "unix listener", 1);
 c->path = xstrdup(path);
 c->host_port = port;
 c->listening_port = -2;
 c->listening_addr = xstrdup(fwd->listen_path);
 return 1;
}

static int
channel_cancel_rport_listener_tcpip(struct ssh *ssh,
    const char *host, u_short port)
{
 u_int i;
 int found = 0;

 for (i = 0; i < ssh->chanctxt->channels_alloc; i++) {
  Channel *c = ssh->chanctxt->channels[i];
  if (c == 
          ((void *)0) 
               || c->type != 11)
   continue;
  if (strcmp(c->path, host) == 0 && c->listening_port == port) {
   sshlog("channels.c", __func__, 3827, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "close channel %d", i);
   channel_free(ssh, c);
   found = 1;
  }
 }

 return found;
}

static int
channel_cancel_rport_listener_streamlocal(struct ssh *ssh, const char *path)
{
 u_int i;
 int found = 0;

 for (i = 0; i < ssh->chanctxt->channels_alloc; i++) {
  Channel *c = ssh->chanctxt->channels[i];
  if (c == 
          ((void *)0) 
               || c->type != 19)
   continue;
  if (c->path == 
                ((void *)0)
                    )
   continue;
  if (strcmp(c->path, path) == 0) {
   sshlog("channels.c", __func__, 3849, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "close channel %d", i);
   channel_free(ssh, c);
   found = 1;
  }
 }

 return found;
}

int
channel_cancel_rport_listener(struct ssh *ssh, struct Forward *fwd)
{
 if (fwd->listen_path != 
                        ((void *)0)
                            ) {
  return channel_cancel_rport_listener_streamlocal(ssh,
      fwd->listen_path);
 } else {
  return channel_cancel_rport_listener_tcpip(ssh,
      fwd->listen_host, fwd->listen_port);
 }
}

static int
channel_cancel_lport_listener_tcpip(struct ssh *ssh,
    const char *lhost, u_short lport, int cport,
    struct ForwardOptions *fwd_opts)
{
 u_int i;
 int found = 0;
 const char *addr = channel_fwd_bind_addr(ssh, lhost, 
                                                     ((void *)0)
                                                         , 1, fwd_opts);

 for (i = 0; i < ssh->chanctxt->channels_alloc; i++) {
  Channel *c = ssh->chanctxt->channels[i];
  if (c == 
          ((void *)0) 
               || c->type != 2)
   continue;
  if (c->listening_port != lport)
   continue;
  if (cport == -1) {

   if (c->host_port == 0)
    continue;
  } else {
   if (c->host_port != cport)
    continue;
  }
  if ((c->listening_addr == 
                           ((void *)0) 
                                && addr != 
                                           ((void *)0)
                                               ) ||
      (c->listening_addr != 
                           ((void *)0) 
                                && addr == 
                                           ((void *)0)
                                               ))
   continue;
  if (addr == 
             ((void *)0) 
                  || strcmp(c->listening_addr, addr) == 0) {
   sshlog("channels.c", __func__, 3897, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "close channel %d", i);
   channel_free(ssh, c);
   found = 1;
  }
 }

 return found;
}

static int
channel_cancel_lport_listener_streamlocal(struct ssh *ssh, const char *path)
{
 u_int i;
 int found = 0;

 if (path == 
            ((void *)0)
                ) {
  sshlog("channels.c", __func__, 3913, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "no path specified.");
  return 0;
 }

 for (i = 0; i < ssh->chanctxt->channels_alloc; i++) {
  Channel *c = ssh->chanctxt->channels[i];
  if (c == 
          ((void *)0) 
               || c->type != 18)
   continue;
  if (c->listening_addr == 
                          ((void *)0)
                              )
   continue;
  if (strcmp(c->listening_addr, path) == 0) {
   sshlog("channels.c", __func__, 3924, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "close channel %d", i);
   channel_free(ssh, c);
   found = 1;
  }
 }

 return found;
}

int
channel_cancel_lport_listener(struct ssh *ssh,
    struct Forward *fwd, int cport, struct ForwardOptions *fwd_opts)
{
 if (fwd->listen_path != 
                        ((void *)0)
                            ) {
  return channel_cancel_lport_listener_streamlocal(ssh,
      fwd->listen_path);
 } else {
  return channel_cancel_lport_listener_tcpip(ssh,
      fwd->listen_host, fwd->listen_port, cport, fwd_opts);
 }
}


int
channel_setup_local_fwd_listener(struct ssh *ssh,
    struct Forward *fwd, struct ForwardOptions *fwd_opts)
{
 if (fwd->listen_path != 
                        ((void *)0)
                            ) {
  return channel_setup_fwd_listener_streamlocal(ssh,
      18, fwd, fwd_opts);
 } else {
  return channel_setup_fwd_listener_tcpip(ssh,
      2, fwd, 
                                     ((void *)0)
                                         , fwd_opts);
 }
}


static int
remote_open_match(struct permission *allowed_open, struct Forward *fwd)
{
 int ret;
 char *lhost;


 if (fwd->listen_path != 
                        ((void *)0)
                            )
  return 1;

 if (fwd->listen_host == 
                        ((void *)0) 
                             || allowed_open->listen_host == 
                                                             ((void *)0)
                                                                 )
  return 0;

 if (allowed_open->listen_port != 0 &&
     allowed_open->listen_port != fwd->listen_port)
  return 0;


 lhost = xstrdup(fwd->listen_host);
 lowercase(lhost);
 ret = match_pattern(lhost, allowed_open->listen_host);
 free(lhost);

 return ret;
}


static int
check_rfwd_permission(struct ssh *ssh, struct Forward *fwd)
{
 struct ssh_channels *sc = ssh->chanctxt;
 struct permission_set *pset = &sc->remote_perms;
 u_int i, permit, permit_adm = 1;
 struct permission *perm;



 permit = pset->all_permitted;
 if (!permit) {
  for (i = 0; i < pset->num_permitted_user; i++) {
   perm = &pset->permitted_user[i];
   if (remote_open_match(perm, fwd)) {
    permit = 1;
    break;
   }
  }
 }

 if (pset->num_permitted_admin > 0) {
  permit_adm = 0;
  for (i = 0; i < pset->num_permitted_admin; i++) {
   perm = &pset->permitted_admin[i];
   if (remote_open_match(perm, fwd)) {
    permit_adm = 1;
    break;
   }
  }
 }

 return permit && permit_adm;
}


int
channel_setup_remote_fwd_listener(struct ssh *ssh, struct Forward *fwd,
    int *allocated_listen_port, struct ForwardOptions *fwd_opts)
{
 if (!check_rfwd_permission(ssh, fwd)) {
  ssh_packet_send_debug(ssh, "port forwarding refused");
  if (fwd->listen_path != 
                         ((void *)0)
                             )

   sshlog("channels.c", __func__, 4032, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Received request from %.100s port %d to " "remote forward to path \"%.100s\", " "but the request was denied.", ssh_remote_ipaddr(ssh), ssh_remote_port(ssh), fwd->listen_path)



                        ;
  else if(fwd->listen_host != 
                             ((void *)0)
                                 )
   sshlog("channels.c", __func__, 4038, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Received request from %.100s port %d to " "remote forward to host %.100s port %d, " "but the request was denied.", ssh_remote_ipaddr(ssh), ssh_remote_port(ssh), fwd->listen_host, fwd->listen_port)



                                           ;
  else
   sshlog("channels.c", __func__, 4044, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Received request from %.100s port %d to remote " "forward, but the request was denied.", ssh_remote_ipaddr(ssh), ssh_remote_port(ssh))

                                                    ;
  return 0;
 }
 if (fwd->listen_path != 
                        ((void *)0)
                            ) {
  return channel_setup_fwd_listener_streamlocal(ssh,
      19, fwd, fwd_opts);
 } else {
  return channel_setup_fwd_listener_tcpip(ssh,
      11, fwd, allocated_listen_port,
      fwd_opts);
 }
}





static const char *
channel_rfwd_bind_host(const char *listen_host)
{
 if (listen_host == 
                   ((void *)0)
                       ) {
  return "localhost";
 } else if (*listen_host == '\0' || strcmp(listen_host, "*") == 0) {
  return "";
 } else
  return listen_host;
}







int
channel_request_remote_forwarding(struct ssh *ssh, struct Forward *fwd)
{
 int r, success = 0, idx = -1;
 char *host_to_connect, *listen_host, *listen_path;
 int port_to_connect, listen_port;


 if (fwd->listen_path != 
                        ((void *)0)
                            ) {
  if ((r = sshpkt_start(ssh, 80)) != 0 ||
      (r = sshpkt_put_cstring(ssh,
      "streamlocal-forward@openssh.com")) != 0 ||
      (r = sshpkt_put_u8(ssh, 1)) != 0 ||
      (r = sshpkt_put_cstring(ssh, fwd->listen_path)) != 0 ||
      (r = sshpkt_send(ssh)) != 0 ||
      (r = ssh_packet_write_wait(ssh)) != 0)
   sshfatal("channels.c", __func__, 4096, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "request streamlocal");
 } else {
  if ((r = sshpkt_start(ssh, 80)) != 0 ||
      (r = sshpkt_put_cstring(ssh, "tcpip-forward")) != 0 ||
      (r = sshpkt_put_u8(ssh, 1)) != 0 ||
      (r = sshpkt_put_cstring(ssh,
      channel_rfwd_bind_host(fwd->listen_host))) != 0 ||
      (r = sshpkt_put_u32(ssh, fwd->listen_port)) != 0 ||
      (r = sshpkt_send(ssh)) != 0 ||
      (r = ssh_packet_write_wait(ssh)) != 0)
   sshfatal("channels.c", __func__, 4106, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "request tcpip-forward");
 }

 success = 1;
 if (success) {

  host_to_connect = listen_host = listen_path = 
                                               ((void *)0)
                                                   ;
  port_to_connect = listen_port = 0;
  if (fwd->connect_path != 
                          ((void *)0)
                              ) {
   host_to_connect = xstrdup(fwd->connect_path);
   port_to_connect = -2;
  } else {
   host_to_connect = xstrdup(fwd->connect_host);
   port_to_connect = fwd->connect_port;
  }
  if (fwd->listen_path != 
                         ((void *)0)
                             ) {
   listen_path = xstrdup(fwd->listen_path);
   listen_port = -2;
  } else {
   if (fwd->listen_host != 
                          ((void *)0)
                              )
    listen_host = xstrdup(fwd->listen_host);
   listen_port = fwd->listen_port;
  }
  idx = permission_set_add(ssh, 0x101, (1<<1),
      host_to_connect, port_to_connect,
      listen_host, listen_path, listen_port, 
                                            ((void *)0)
                                                );
 }
 return idx;
}

static int
open_match(struct permission *allowed_open, const char *requestedhost,
    int requestedport)
{
 if (allowed_open->host_to_connect == 
                                     ((void *)0)
                                         )
  return 0;
 if (allowed_open->port_to_connect != 0 &&
     allowed_open->port_to_connect != requestedport)
  return 0;
 if (strcmp(allowed_open->host_to_connect, "*") != 0 &&
     strcmp(allowed_open->host_to_connect, requestedhost) != 0)
  return 0;
 return 1;
}







static int
open_listen_match_tcpip(struct permission *allowed_open,
    const char *requestedhost, u_short requestedport, int translate)
{
 const char *allowed_host;

 if (allowed_open->host_to_connect == 
                                     ((void *)0)
                                         )
  return 0;
 if (allowed_open->listen_port != requestedport)
  return 0;
 if (!translate && allowed_open->listen_host == 
                                               ((void *)0) 
                                                    &&
     requestedhost == 
                     ((void *)0)
                         )
  return 1;
 allowed_host = translate ?
     channel_rfwd_bind_host(allowed_open->listen_host) :
     allowed_open->listen_host;
 if (allowed_host == 
                    ((void *)0) 
                         || requestedhost == 
                                             ((void *)0) 
                                                  ||
     strcmp(allowed_host, requestedhost) != 0)
  return 0;
 return 1;
}

static int
open_listen_match_streamlocal(struct permission *allowed_open,
    const char *requestedpath)
{
 if (allowed_open->host_to_connect == 
                                     ((void *)0)
                                         )
  return 0;
 if (allowed_open->listen_port != -2)
  return 0;
 if (allowed_open->listen_path == 
                                 ((void *)0) 
                                      ||
     strcmp(allowed_open->listen_path, requestedpath) != 0)
  return 0;
 return 1;
}





static int
channel_request_rforward_cancel_tcpip(struct ssh *ssh,
    const char *host, u_short port)
{
 struct ssh_channels *sc = ssh->chanctxt;
 struct permission_set *pset = &sc->local_perms;
 int r;
 u_int i;
 struct permission *perm = 
                          ((void *)0)
                              ;

 for (i = 0; i < pset->num_permitted_user; i++) {
  perm = &pset->permitted_user[i];
  if (open_listen_match_tcpip(perm, host, port, 0))
   break;
  perm = 
        ((void *)0)
            ;
 }
 if (perm == 
            ((void *)0)
                ) {
  sshlog("channels.c", __func__, 4214, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "requested forward not found");
  return -1;
 }
 if ((r = sshpkt_start(ssh, 80)) != 0 ||
     (r = sshpkt_put_cstring(ssh, "cancel-tcpip-forward")) != 0 ||
     (r = sshpkt_put_u8(ssh, 0)) != 0 ||
     (r = sshpkt_put_cstring(ssh, channel_rfwd_bind_host(host))) != 0 ||
     (r = sshpkt_put_u32(ssh, port)) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  sshfatal("channels.c", __func__, 4223, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send cancel");

 fwd_perm_clear(perm);

 return 0;
}





static int
channel_request_rforward_cancel_streamlocal(struct ssh *ssh, const char *path)
{
 struct ssh_channels *sc = ssh->chanctxt;
 struct permission_set *pset = &sc->local_perms;
 int r;
 u_int i;
 struct permission *perm = 
                          ((void *)0)
                              ;

 for (i = 0; i < pset->num_permitted_user; i++) {
  perm = &pset->permitted_user[i];
  if (open_listen_match_streamlocal(perm, path))
   break;
  perm = 
        ((void *)0)
            ;
 }
 if (perm == 
            ((void *)0)
                ) {
  sshlog("channels.c", __func__, 4250, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "requested forward not found");
  return -1;
 }
 if ((r = sshpkt_start(ssh, 80)) != 0 ||
     (r = sshpkt_put_cstring(ssh,
     "cancel-streamlocal-forward@openssh.com")) != 0 ||
     (r = sshpkt_put_u8(ssh, 0)) != 0 ||
     (r = sshpkt_put_cstring(ssh, path)) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  sshfatal("channels.c", __func__, 4259, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send cancel");

 fwd_perm_clear(perm);

 return 0;
}




int
channel_request_rforward_cancel(struct ssh *ssh, struct Forward *fwd)
{
 if (fwd->listen_path != 
                        ((void *)0)
                            ) {
  return channel_request_rforward_cancel_streamlocal(ssh,
      fwd->listen_path);
 } else {
  return channel_request_rforward_cancel_tcpip(ssh,
      fwd->listen_host,
      fwd->listen_port ? fwd->listen_port : fwd->allocated_port);
 }
}






void
channel_permit_all(struct ssh *ssh, int where)
{
 struct permission_set *pset = permission_set_get(ssh, where);

 if (pset->num_permitted_user == 0)
  pset->all_permitted = 1;
}




void
channel_add_permission(struct ssh *ssh, int who, int where,
    char *host, int port)
{
 int local = where == (1<<1);
 struct permission_set *pset = permission_set_get(ssh, where);

 sshlog("channels.c", __func__, 4306, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "allow %s forwarding to host %s port %d", fwd_ident(who, where), host, port)
                                       ;




 permission_set_add(ssh, who, where,
     local ? host : 0, local ? port : 0,
     local ? 
            ((void *)0) 
                 : host, 
                         ((void *)0)
                             , local ? 0 : port, 
                                                 ((void *)0)
                                                     );
 pset->all_permitted = 0;
}




void
channel_disable_admin(struct ssh *ssh, int where)
{
 channel_clear_permission(ssh, 0x100, where);
 permission_set_add(ssh, 0x100, where,
     
    ((void *)0)
        , 0, 
             ((void *)0)
                 , 
                   ((void *)0)
                       , 0, 
                            ((void *)0)
                                );
}




void
channel_clear_permission(struct ssh *ssh, int who, int where)
{
 struct permission **permp;
 u_int *npermp;

 permission_set_get_array(ssh, who, where, &permp, &npermp);
 *permp = xrecallocarray(*permp, *npermp, 0, sizeof(**permp));
 *npermp = 0;
}






void
channel_update_permission(struct ssh *ssh, int idx, int newport)
{
 struct permission_set *pset = &ssh->chanctxt->local_perms;

 if (idx < 0 || (u_int)idx >= pset->num_permitted_user) {
  sshlog("channels.c", __func__, 4354, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "index out of range: %d num_permitted_user %d", idx, pset->num_permitted_user)
                                    ;
  return;
 }
 sshlog("channels.c", __func__, 4358, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "%s allowed port %d for forwarding to host %s port %d", newport > 0 ? "Updating" : "Removing", newport, pset->permitted_user[idx].host_to_connect, pset->permitted_user[idx].port_to_connect)



                                               ;
 if (newport <= 0)
  fwd_perm_clear(&pset->permitted_user[idx]);
 else {
  pset->permitted_user[idx].listen_port =
      (ssh->compat & 0x08000000) ? 0 : newport;
 }
}


int
permitopen_port(const char *p)
{
 int port;

 if (strcmp(p, "*") == 0)
  return 0;
 if ((port = a2port(p)) > 0)
  return port;
 return -1;
}


static int
connect_next(struct channel_connect *cctx)
{
 int sock, saved_errno;
 struct sockaddr_un *sunaddr;
 char ntop[
          1025
                    ];
 char strport[(((
             32
             ) > (sizeof(sunaddr->sun_path))) ? (
             32
             ) : (sizeof(sunaddr->sun_path)))];

 for (; cctx->ai; cctx->ai = cctx->ai->ai_next) {
  switch (cctx->ai->ai_family) {
  case 
      1
             :

   sunaddr = (struct sockaddr_un *)cctx->ai->ai_addr;
   strlcpy(ntop, "unix", sizeof(ntop));
   strlcpy(strport, sunaddr->sun_path, sizeof(strport));
   break;
  case 
      2
             :
  case 
      10
              :
   if (getnameinfo(cctx->ai->ai_addr, cctx->ai->ai_addrlen,
       ntop, sizeof(ntop), strport, sizeof(strport),
       
      1
                    |
                     2
                                   ) != 0) {
    sshlog("channels.c", __func__, 4406, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "getnameinfo failed");
    continue;
   }
   break;
  default:
   continue;
  }
  sshlog("channels.c", __func__, 4413, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "start for host %.100s ([%.100s]:%s)", cctx->host, ntop, strport)
                                ;
  if ((sock = socket(cctx->ai->ai_family, cctx->ai->ai_socktype,
      cctx->ai->ai_protocol)) == -1) {
   if (cctx->ai->ai_next == 
                           ((void *)0)
                               )
    sshlog("channels.c", __func__, 4418, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "socket: %.100s", strerror(
   (*__errno_location ())
   ));
   else
    sshlog("channels.c", __func__, 4420, 0, SYSLOG_LEVEL_VERBOSE, 
   ((void *)0)
   , "socket: %.100s", strerror(
   (*__errno_location ())
   ));
   continue;
  }
  if (set_nonblock(sock) == -1)
   sshfatal("channels.c", __func__, 4424, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "set_nonblock(%d)", sock);
  if (connect(sock, cctx->ai->ai_addr,
      cctx->ai->ai_addrlen) == -1 && 
                                    (*__errno_location ()) 
                                          != 
                                             115
                                                        ) {
   sshlog("channels.c", __func__, 4427, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "host %.100s ([%.100s]:%s): %.100s", cctx->host, ntop, strport, strerror(
  (*__errno_location ())
  ))
                                                  ;
   saved_errno = 
                (*__errno_location ())
                     ;
   close(sock);
   
  (*__errno_location ()) 
        = saved_errno;
   continue;
  }
  if (cctx->ai->ai_family != 
                            1
                                   )
   set_nodelay(sock);
  sshlog("channels.c", __func__, 4436, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "connect host %.100s ([%.100s]:%s) in progress, fd=%d", cctx->host, ntop, strport, sock)
                                      ;
  cctx->ai = cctx->ai->ai_next;
  return sock;
 }
 return -1;
}

static void
channel_connect_ctx_free(struct channel_connect *cctx)
{
 free(cctx->host);
 if (cctx->aitop) {
  if (cctx->aitop->ai_family == 
                               1
                                      )
   free(cctx->aitop);
  else
   freeaddrinfo(cctx->aitop);
 }
 memset(cctx, 0, sizeof(*cctx));
}





static int
connect_to_helper(struct ssh *ssh, const char *name, int port, int socktype,
    char *ctype, char *rname, struct channel_connect *cctx,
    int *reason, const char **errmsg)
{
 struct addrinfo hints;
 int gaierr;
 int sock = -1;
 char strport[
             32
                       ];

 if (port == -2) {
  struct sockaddr_un *sunaddr;
  struct addrinfo *ai;

  if (strlen(name) > sizeof(sunaddr->sun_path)) {
   sshlog("channels.c", __func__, 4476, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%.100s: %.100s", name, strerror(
  36
  ));
   return -1;
  }






  ai = xmalloc(sizeof(*ai) + sizeof(*sunaddr));
  memset(ai, 0, sizeof(*ai) + sizeof(*sunaddr));
  ai->ai_addr = (struct sockaddr *)(ai + 1);
  ai->ai_addrlen = sizeof(*sunaddr);
  ai->ai_family = 
                 1
                        ;
  ai->ai_socktype = socktype;
  ai->ai_protocol = 
                   0
                            ;
  sunaddr = (struct sockaddr_un *)ai->ai_addr;
  sunaddr->sun_family = 
                       1
                              ;
  strlcpy(sunaddr->sun_path, name, sizeof(sunaddr->sun_path));
  cctx->aitop = ai;
 } else {
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = ssh->chanctxt->IPv4or6;
  hints.ai_socktype = socktype;
  snprintf(strport, sizeof strport, "%d", port);
  if ((gaierr = getaddrinfo(name, strport, &hints, &cctx->aitop))
      != 0) {
   if (errmsg != 
                ((void *)0)
                    )
    *errmsg = ssh_gai_strerror(gaierr);
   if (reason != 
                ((void *)0)
                    )
    *reason = 2;
   sshlog("channels.c", __func__, 4507, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "connect_to %.100s: unknown host (%s)", name, ssh_gai_strerror(gaierr))
                                ;
   return -1;
  }
 }

 cctx->host = xstrdup(name);
 cctx->port = port;
 cctx->ai = cctx->aitop;

 if ((sock = connect_next(cctx)) == -1) {
  sshlog("channels.c", __func__, 4518, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "connect to %.100s port %d failed: %s", name, port, strerror(
 (*__errno_location ())
 ))
                                  ;
  return -1;
 }

 return sock;
}


static Channel *
connect_to(struct ssh *ssh, const char *host, int port,
    char *ctype, char *rname)
{
 struct channel_connect cctx;
 Channel *c;
 int sock;

 memset(&cctx, 0, sizeof(cctx));
 sock = connect_to_helper(ssh, host, port, 
                                          SOCK_STREAM
                                                     , ctype, rname,
     &cctx, 
           ((void *)0)
               , 
                 ((void *)0)
                     );
 if (sock == -1) {
  channel_connect_ctx_free(&cctx);
  return 
        ((void *)0)
            ;
 }
 c = channel_new(ssh, ctype, 12, sock, sock, -1,
     (64*(32*1024)), (32*1024), 0, rname, 1);
 c->host_port = port;
 c->path = xstrdup(host);
 c->connect_ctx = cctx;

 return c;
}





Channel *
channel_connect_by_listen_address(struct ssh *ssh, const char *listen_host,
    u_short listen_port, char *ctype, char *rname)
{
 struct ssh_channels *sc = ssh->chanctxt;
 struct permission_set *pset = &sc->local_perms;
 u_int i;
 struct permission *perm;

 for (i = 0; i < pset->num_permitted_user; i++) {
  perm = &pset->permitted_user[i];
  if (open_listen_match_tcpip(perm,
      listen_host, listen_port, 1)) {
   if (perm->downstream)
    return perm->downstream;
   if (perm->port_to_connect == 0)
    return rdynamic_connect_prepare(ssh,
        ctype, rname);
   return connect_to(ssh,
       perm->host_to_connect, perm->port_to_connect,
       ctype, rname);
  }
 }
 sshlog("channels.c", __func__, 4578, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "WARNING: Server requests forwarding for unknown listen_port %d", listen_port)
                 ;
 return 
       ((void *)0)
           ;
}

Channel *
channel_connect_by_listen_path(struct ssh *ssh, const char *path,
    char *ctype, char *rname)
{
 struct ssh_channels *sc = ssh->chanctxt;
 struct permission_set *pset = &sc->local_perms;
 u_int i;
 struct permission *perm;

 for (i = 0; i < pset->num_permitted_user; i++) {
  perm = &pset->permitted_user[i];
  if (open_listen_match_streamlocal(perm, path)) {
   return connect_to(ssh,
       perm->host_to_connect, perm->port_to_connect,
       ctype, rname);
  }
 }
 sshlog("channels.c", __func__, 4600, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "WARNING: Server requests forwarding for unknown path %.100s", path)
          ;
 return 
       ((void *)0)
           ;
}


Channel *
channel_connect_to_port(struct ssh *ssh, const char *host, u_short port,
    char *ctype, char *rname, int *reason, const char **errmsg)
{
 struct ssh_channels *sc = ssh->chanctxt;
 struct permission_set *pset = &sc->local_perms;
 struct channel_connect cctx;
 Channel *c;
 u_int i, permit, permit_adm = 1;
 int sock;
 struct permission *perm;

 permit = pset->all_permitted;
 if (!permit) {
  for (i = 0; i < pset->num_permitted_user; i++) {
   perm = &pset->permitted_user[i];
   if (open_match(perm, host, port)) {
    permit = 1;
    break;
   }
  }
 }

 if (pset->num_permitted_admin > 0) {
  permit_adm = 0;
  for (i = 0; i < pset->num_permitted_admin; i++) {
   perm = &pset->permitted_admin[i];
   if (open_match(perm, host, port)) {
    permit_adm = 1;
    break;
   }
  }
 }

 if (!permit || !permit_adm) {
  sshlog("channels.c", __func__, 4641, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Received request from %.100s port %d to connect to " "host %.100s port %d, but the request was denied.", ssh_remote_ipaddr(ssh), ssh_remote_port(ssh), host, port)

                                                               ;
  if (reason != 
               ((void *)0)
                   )
   *reason = 1;
  return 
        ((void *)0)
            ;
 }

 memset(&cctx, 0, sizeof(cctx));
 sock = connect_to_helper(ssh, host, port, 
                                          SOCK_STREAM
                                                     , ctype, rname,
     &cctx, reason, errmsg);
 if (sock == -1) {
  channel_connect_ctx_free(&cctx);
  return 
        ((void *)0)
            ;
 }

 c = channel_new(ssh, ctype, 12, sock, sock, -1,
     (64*(32*1024)), (32*1024), 0, rname, 1);
 c->host_port = port;
 c->path = xstrdup(host);
 c->connect_ctx = cctx;

 return c;
}


Channel *
channel_connect_to_path(struct ssh *ssh, const char *path,
    char *ctype, char *rname)
{
 struct ssh_channels *sc = ssh->chanctxt;
 struct permission_set *pset = &sc->local_perms;
 u_int i, permit, permit_adm = 1;
 struct permission *perm;

 permit = pset->all_permitted;
 if (!permit) {
  for (i = 0; i < pset->num_permitted_user; i++) {
   perm = &pset->permitted_user[i];
   if (open_match(perm, path, -2)) {
    permit = 1;
    break;
   }
  }
 }

 if (pset->num_permitted_admin > 0) {
  permit_adm = 0;
  for (i = 0; i < pset->num_permitted_admin; i++) {
   perm = &pset->permitted_admin[i];
   if (open_match(perm, path, -2)) {
    permit_adm = 1;
    break;
   }
  }
 }

 if (!permit || !permit_adm) {
  sshlog("channels.c", __func__, 4699, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Received request to connect to path %.100s, " "but the request was denied.", path)
                                          ;
  return 
        ((void *)0)
            ;
 }
 return connect_to(ssh, path, -2, ctype, rname);
}

void
channel_send_window_changes(struct ssh *ssh)
{
 struct ssh_channels *sc = ssh->chanctxt;
 struct winsize ws;
 int r;
 u_int i;

 for (i = 0; i < sc->channels_alloc; i++) {
  if (sc->channels[i] == 
                        ((void *)0) 
                             || !sc->channels[i]->client_tty ||
      sc->channels[i]->type != 4)
   continue;
  if (ioctl(sc->channels[i]->rfd, 
                                 0x5413
                                           , &ws) == -1)
   continue;
  channel_request_start(ssh, i, "window-change", 0);
  if ((r = sshpkt_put_u32(ssh, (u_int)ws.ws_col)) != 0 ||
      (r = sshpkt_put_u32(ssh, (u_int)ws.ws_row)) != 0 ||
      (r = sshpkt_put_u32(ssh, (u_int)ws.ws_xpixel)) != 0 ||
      (r = sshpkt_put_u32(ssh, (u_int)ws.ws_ypixel)) != 0 ||
      (r = sshpkt_send(ssh)) != 0)
   sshfatal("channels.c", __func__, 4726, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %u; send window-change", i);
 }
}


static Channel *
rdynamic_connect_prepare(struct ssh *ssh, char *ctype, char *rname)
{
 Channel *c;
 int r;

 c = channel_new(ssh, ctype, 21, -1, -1, -1,
     (64*(32*1024)), (32*1024), 0, rname, 1);
 c->host_port = 0;
 c->path = 
          ((void *)0)
              ;





 if ((r = sshpkt_start(ssh, 91)) != 0 ||
     (r = sshpkt_put_u32(ssh, c->remote_id)) != 0 ||
     (r = sshpkt_put_u32(ssh, c->self)) != 0 ||
     (r = sshpkt_put_u32(ssh, c->local_window)) != 0 ||
     (r = sshpkt_put_u32(ssh, c->local_maxpacket)) != 0)
  sshfatal("channels.c", __func__, 4751, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "channel %i; confirm", c->self);
 return c;
}


static int
rdynamic_connect_finish(struct ssh *ssh, Channel *c)
{
 struct ssh_channels *sc = ssh->chanctxt;
 struct permission_set *pset = &sc->local_perms;
 struct permission *perm;
 struct channel_connect cctx;
 u_int i, permit_adm = 1;
 int sock;

 if (pset->num_permitted_admin > 0) {
  permit_adm = 0;
  for (i = 0; i < pset->num_permitted_admin; i++) {
   perm = &pset->permitted_admin[i];
   if (open_match(perm, c->path, c->host_port)) {
    permit_adm = 1;
    break;
   }
  }
 }
 if (!permit_adm) {
  sshlog("channels.c", __func__, 4777, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "requested forward not permitted");
  return -1;
 }

 memset(&cctx, 0, sizeof(cctx));
 sock = connect_to_helper(ssh, c->path, c->host_port, 
                                                     SOCK_STREAM
                                                                , 
                                                                  ((void *)0)
                                                                      ,
     
    ((void *)0)
        , &cctx, 
                 ((void *)0)
                     , 
                       ((void *)0)
                           );
 if (sock == -1)
  channel_connect_ctx_free(&cctx);
 else {

  c->type = 22;
  c->connect_ctx = cctx;
  channel_register_fds(ssh, c, sock, sock, -1, 0, 1, 0);
 }
 return sock;
}
int
x11_create_display_inet(struct ssh *ssh, int x11_display_offset,
    int x11_use_localhost, int single_connection,
    u_int *display_numberp, int **chanids)
{
 Channel *nc = 
              ((void *)0)
                  ;
 int display_number, sock;
 u_short port;
 struct addrinfo hints, *ai, *aitop;
 char strport[
             32
                       ];
 int gaierr, n, num_socks = 0, socks[10];

 if (chanids == 
               ((void *)0)
                   )
  return -1;

 for (display_number = x11_display_offset;
     display_number < 1000;
     display_number++) {
  port = 6000 + display_number;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = ssh->chanctxt->IPv4or6;
  hints.ai_flags = x11_use_localhost ? 0: 
                                         0x0001
                                                   ;
  hints.ai_socktype = 
                     SOCK_STREAM
                                ;
  snprintf(strport, sizeof strport, "%d", port);
  if ((gaierr = getaddrinfo(
                           ((void *)0)
                               , strport,
      &hints, &aitop)) != 0) {
   sshlog("channels.c", __func__, 4828, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "getaddrinfo: %.100s", ssh_gai_strerror(gaierr));
   return -1;
  }
  for (ai = aitop; ai; ai = ai->ai_next) {
   if (ai->ai_family != 
                       2 
                               &&
       ai->ai_family != 
                       10
                               )
    continue;
   sock = socket(ai->ai_family, ai->ai_socktype,
       ai->ai_protocol);
   if (sock == -1) {
    if ((
        (*__errno_location ()) 
              != 
                 22
                       ) && (
                             (*__errno_location ()) 
                                   != 
                                      97
                                                  )

        && (
           (*__errno_location ()) 
                 != 
                    96
                                )

        ) {
     sshlog("channels.c", __func__, 4843, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "socket: %.100s", strerror(
    (*__errno_location ())
    ));
     freeaddrinfo(aitop);
     return -1;
    } else {
     sshlog("channels.c", __func__, 4847, 0, SYSLOG_LEVEL_DEBUG1, 
    ((void *)0)
    , "x11_create_display_inet: Socket family %d not supported", ai->ai_family)
                     ;
     continue;
    }
   }
   if (ai->ai_family == 
                       10
                               )
    sock_set_v6only(sock);
   if (x11_use_localhost)
    set_reuseaddr(sock);
   if (bind(sock, ai->ai_addr, ai->ai_addrlen) == -1) {
    sshlog("channels.c", __func__, 4857, 1, SYSLOG_LEVEL_DEBUG2, 
   ((void *)0)
   , "bind port %d: %.100s", port, strerror(
   (*__errno_location ())
   ))
                        ;
    close(sock);
    for (n = 0; n < num_socks; n++)
     close(socks[n]);
    num_socks = 0;
    break;
   }
   socks[num_socks++] = sock;
   if (num_socks == 10)
    break;
  }
  freeaddrinfo(aitop);
  if (num_socks > 0)
   break;
 }
 if (display_number >= 1000) {
  sshlog("channels.c", __func__, 4874, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Failed to allocate internet-domain X11 display socket.");
  return -1;
 }

 for (n = 0; n < num_socks; n++) {
  sock = socks[n];
  if (listen(sock, 128) == -1) {
   sshlog("channels.c", __func__, 4881, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "listen: %.100s", strerror(
  (*__errno_location ())
  ));
   close(sock);
   return -1;
  }
 }


 *chanids = xcalloc(num_socks + 1, sizeof(**chanids));
 for (n = 0; n < num_socks; n++) {
  sock = socks[n];
  nc = channel_new(ssh, "x11 listener",
      1, sock, sock, -1,
      (4*(16*1024)), (16*1024),
      0, "X11 inet listener", 1);
  nc->single_connection = single_connection;
  (*chanids)[n] = nc->self;
 }
 (*chanids)[n] = -1;


 *display_numberp = display_number;
 return 0;
}

static int
connect_local_xsocket_path(const char *pathname)
{
 int sock;
 struct sockaddr_un addr;

 sock = socket(
              1
                     , 
                       SOCK_STREAM
                                  , 0);
 if (sock == -1)
  sshlog("channels.c", __func__, 4913, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "socket: %.100s", strerror(
 (*__errno_location ())
 ));
 memset(&addr, 0, sizeof(addr));
 addr.sun_family = 
                  1
                         ;
 strlcpy(addr.sun_path, pathname, sizeof addr.sun_path);
 if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0)
  return sock;
 close(sock);
 sshlog("channels.c", __func__, 4920, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "connect %.100s: %.100s", addr.sun_path, strerror(
(*__errno_location ())
));
 return -1;
}

static int
connect_local_xsocket(u_int dnr)
{
 char buf[1024];
 snprintf(buf, sizeof buf, "/tmp/.X11-unix/X%u", dnr);
 return connect_local_xsocket_path(buf);
}
int
x11_connect_display(struct ssh *ssh)
{
 u_int display_number;
 const char *display;
 char buf[1024], *cp;
 struct addrinfo hints, *ai, *aitop;
 char strport[
             32
                       ];
 int gaierr, sock = 0;


 display = getenv("DISPLAY");
 if (!display) {
  sshlog("channels.c", __func__, 4972, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "DISPLAY not set.");
  return -1;
 }
 if (strncmp(display, "unix:", 5) == 0 ||
     display[0] == ':') {

  if (sscanf(strrchr(display, ':') + 1, "%u",
      &display_number) != 1) {
   sshlog("channels.c", __func__, 5007, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Could not parse display number from DISPLAY: " "%.100s", display)
                         ;
   return -1;
  }

  sock = connect_local_xsocket(display_number);
  if (sock < 0)
   return -1;


  return sock;
 }




 strlcpy(buf, display, sizeof(buf));
 cp = strchr(buf, ':');
 if (!cp) {
  sshlog("channels.c", __func__, 5026, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Could not find ':' in DISPLAY: %.100s", display);
  return -1;
 }
 *cp = 0;




 if (sscanf(cp + 1, "%u", &display_number) != 1) {
  sshlog("channels.c", __func__, 5035, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Could not parse display number from DISPLAY: %.100s", display)
              ;
  return -1;
 }


 memset(&hints, 0, sizeof(hints));
 hints.ai_family = ssh->chanctxt->IPv4or6;
 hints.ai_socktype = 
                    SOCK_STREAM
                               ;
 snprintf(strport, sizeof strport, "%u", 6000 + display_number);
 if ((gaierr = getaddrinfo(buf, strport, &hints, &aitop)) != 0) {
  sshlog("channels.c", __func__, 5046, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%.100s: unknown host. (%s)", buf, ssh_gai_strerror(gaierr))
                           ;
  return -1;
 }
 for (ai = aitop; ai; ai = ai->ai_next) {

  sock = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
  if (sock == -1) {
   sshlog("channels.c", __func__, 5054, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "socket: %.100s", strerror(
  (*__errno_location ())
  ));
   continue;
  }

  if (connect(sock, ai->ai_addr, ai->ai_addrlen) == -1) {
   sshlog("channels.c", __func__, 5059, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "connect %.100s port %u: %.100s", buf, 6000 + display_number, strerror(
  (*__errno_location ())
  ))
                                              ;
   close(sock);
   continue;
  }

  break;
 }
 freeaddrinfo(aitop);
 if (!ai) {
  sshlog("channels.c", __func__, 5069, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "connect %.100s port %u: %.100s", buf, 6000 + display_number, strerror(
 (*__errno_location ())
 ))
                                             ;
  return -1;
 }
 set_nodelay(sock);
 return sock;
}






void
x11_request_forwarding_with_spoofing(struct ssh *ssh, int client_session_id,
    const char *disp, const char *proto, const char *data, int want_reply)
{
 struct ssh_channels *sc = ssh->chanctxt;
 u_int data_len = (u_int) strlen(data) / 2;
 u_int i, value;
 const char *cp;
 char *new_data;
 int r, screen_number;

 if (sc->x11_saved_display == 
                             ((void *)0)
                                 )
  sc->x11_saved_display = xstrdup(disp);
 else if (strcmp(disp, sc->x11_saved_display) != 0) {
  sshlog("channels.c", __func__, 5096, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "x11_request_forwarding_with_spoofing: different " "$DISPLAY already forwarded")
                                   ;
  return;
 }

 cp = strchr(disp, ':');
 if (cp)
  cp = strchr(cp, '.');
 if (cp)
  screen_number = (u_int)strtonum(cp + 1, 0, 400, 
                                                 ((void *)0)
                                                     );
 else
  screen_number = 0;

 if (sc->x11_saved_proto == 
                           ((void *)0)
                               ) {

  sc->x11_saved_proto = xstrdup(proto);


  sc->x11_saved_data = xmalloc(data_len);
  for (i = 0; i < data_len; i++) {
   if (sscanf(data + 2 * i, "%2x", &value) != 1) {
    sshfatal("channels.c", __func__, 5117, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "x11_request_forwarding: bad " "authentication data: %.100s", data)
                                            ;
   }
   sc->x11_saved_data[i] = value;
  }
  sc->x11_saved_data_len = data_len;


  sc->x11_fake_data = xmalloc(data_len);
  arc4random_buf(sc->x11_fake_data, data_len);
  sc->x11_fake_data_len = data_len;
 }


 new_data = tohex(sc->x11_fake_data, data_len);


 channel_request_start(ssh, client_session_id, "x11-req", want_reply);
 if ((r = sshpkt_put_u8(ssh, 0)) != 0 ||
     (r = sshpkt_put_cstring(ssh, proto)) != 0 ||
     (r = sshpkt_put_cstring(ssh, new_data)) != 0 ||
     (r = sshpkt_put_u32(ssh, screen_number)) != 0 ||
     (r = sshpkt_send(ssh)) != 0 ||
     (r = ssh_packet_write_wait(ssh)) != 0)
  sshfatal("channels.c", __func__, 5141, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send x11-req");
 free(new_data);
}
