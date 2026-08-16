











































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





extern int use_privsep;


enum mm_keytype { MM_NOKEY, MM_HOSTKEY, MM_USERKEY };

struct ssh;
struct monitor;
struct Authctxt;
struct sshkey;
struct sshauthopt;
struct sshkey_sig_details;

void mm_log_handler(LogLevel, int, const char *, void *);
int mm_is_monitor(void);

DH *mm_choose_dh(int, int, int);

int mm_sshkey_sign(struct ssh *, struct sshkey *, u_char **, size_t *,
    const u_char *, size_t, const char *, const char *,
    const char *, u_int compat);
void mm_inform_authserv(char *, char *);
struct passwd *mm_getpwnamallow(struct ssh *, const char *);
char *mm_auth2_read_banner(void);
int mm_auth_password(struct ssh *, char *);
int mm_key_allowed(enum mm_keytype, const char *, const char *, struct sshkey *,
    int, struct sshauthopt **);
int mm_user_key_allowed(struct ssh *ssh, struct passwd *, struct sshkey *, int,
    struct sshauthopt **);
int mm_hostbased_key_allowed(struct ssh *, struct passwd *, const char *,
    const char *, struct sshkey *);
int mm_sshkey_verify(const struct sshkey *, const u_char *, size_t,
    const u_char *, size_t, const char *, u_int, struct sshkey_sig_details **);
struct Session;
void mm_terminate(void);
int mm_pty_allocate(int *, int *, char *, size_t);
void mm_session_pty_cleanup2(struct Session *);


struct newkeys *mm_newkeys_from_blob(u_char *, int);
int mm_newkeys_to_blob(int, u_char **, u_int *);

void mm_send_keystate(struct ssh *, struct monitor*);


int mm_bsdauth_query(void *, char **, char **, u_int *, char ***, u_int **);
int mm_bsdauth_respond(void *, u_int, char **);
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


extern ServerOptions options;
extern struct sshbuf *loginmsg;



extern Authmethod method_none;
extern Authmethod method_pubkey;
extern Authmethod method_passwd;
extern Authmethod method_kbdint;
extern Authmethod method_hostbased;




Authmethod *authmethods[] = {
 &method_none,
 &method_pubkey,



 &method_passwd,
 &method_kbdint,
 &method_hostbased,
 
((void *)0)

};



static int input_service_request(int, u_int32_t, struct ssh *);
static int input_userauth_request(int, u_int32_t, struct ssh *);


static Authmethod *authmethod_byname(const char *);
static Authmethod *authmethod_lookup(Authctxt *, const char *);
static char *authmethods_get(Authctxt *authctxt);





static int list_starts_with(const char *, const char *, const char *);

char *
auth2_read_banner(void)
{
 struct stat st;
 char *banner = 
               ((void *)0)
                   ;
 size_t len, n;
 int fd;

 if ((fd = open(options.banner, 
                               00
                                       )) == -1)
  return (
         ((void *)0)
             );
 if (fstat(fd, &st) == -1) {
  close(fd);
  return (
         ((void *)0)
             );
 }
 if (st.st_size <= 0 || st.st_size > 1*1024*1024) {
  close(fd);
  return (
         ((void *)0)
             );
 }

 len = (size_t)st.st_size;
 banner = xmalloc(len + 1);
 n = atomicio(read, fd, banner, len);
 close(fd);

 if (n != len) {
  free(banner);
  return (
         ((void *)0)
             );
 }
 banner[n] = '\0';

 return (banner);
}

static void
userauth_send_banner(struct ssh *ssh, const char *msg)
{
 int r;

 if ((r = sshpkt_start(ssh, 53)) != 0 ||
     (r = sshpkt_put_cstring(ssh, msg)) != 0 ||
     (r = sshpkt_put_cstring(ssh, "")) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  sshfatal("auth2.c", __func__, 147, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send packet");
 sshlog("auth2.c", __func__, 148, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "%s: sent", __func__);
}

static void
userauth_banner(struct ssh *ssh)
{
 char *banner = 
               ((void *)0)
                   ;

 if (options.banner == 
                      ((void *)0)
                          )
  return;

 if ((banner = (use_privsep ? mm_auth2_read_banner() : auth2_read_banner())) == 
                                               ((void *)0)
                                                   )
  goto done;
 userauth_send_banner(ssh, banner);

done:
 free(banner);
}




void
do_authentication2(struct ssh *ssh)
{
 Authctxt *authctxt = ssh->authctxt;

 ssh_dispatch_init(ssh, &dispatch_protocol_error);
 ssh_dispatch_set(ssh, 5, &input_service_request);
 ssh_dispatch_run_fatal(ssh, DISPATCH_BLOCK, &authctxt->success);
 ssh->authctxt = 
                ((void *)0)
                    ;
}


static int
input_service_request(int type, u_int32_t seq, struct ssh *ssh)
{
 Authctxt *authctxt = ssh->authctxt;
 char *service = 
                ((void *)0)
                    ;
 int r, acceptit = 0;

 if ((r = sshpkt_get_cstring(ssh, &service, 
                                           ((void *)0)
                                               )) != 0 ||
     (r = sshpkt_get_end(ssh)) != 0)
  goto out;

 if (authctxt == 
                ((void *)0)
                    )
  sshfatal("auth2.c", __func__, 194, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "input_service_request: no authctxt");

 if (strcmp(service, "ssh-userauth") == 0) {
  if (!authctxt->success) {
   acceptit = 1;

   ssh_dispatch_set(ssh, 50,
       &input_userauth_request);
  }
 }


 if (acceptit) {
  if ((r = sshpkt_start(ssh, 6)) != 0 ||
      (r = sshpkt_put_cstring(ssh, service)) != 0 ||
      (r = sshpkt_send(ssh)) != 0 ||
      (r = ssh_packet_write_wait(ssh)) != 0)
   goto out;
 } else {
  sshlog("auth2.c", __func__, 213, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "bad service request %s", service);
  ssh_packet_disconnect(ssh, "bad service request %s", service);
 }
 r = 0;
 out:
 free(service);
 return r;
}


static double
user_specific_delay(const char *user)
{
 char b[512];
 size_t len = ssh_digest_bytes(4);
 u_char *hash = xmalloc(len);
 double delay;

 (void)snprintf(b, sizeof b, "%llu%s",
     (unsigned long long)options.timing_secret, user);
 if (ssh_digest_memory(4, b, strlen(b), hash, len) != 0)
  sshfatal("auth2.c", __func__, 234, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ssh_digest_memory");

 delay = (double)(((u_int32_t)(((const u_char *)(hash))[0]) << 24) | ((u_int32_t)(((const u_char *)(hash))[1]) << 16) | ((u_int32_t)(((const u_char *)(hash))[2]) << 8) | (u_int32_t)(((const u_char *)(hash))[3])) / 1000 / 1000 / 1000 / 1000;
 freezero(hash, len);
 sshlog("auth2.c", __func__, 238, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "user specific delay %0.3lfms", delay/1000);
 return 0.005 + delay;
}

static void
ensure_minimum_time_since(double start, double seconds)
{
 struct timespec ts;
 double elapsed = monotime_double() - start, req = seconds, remain;


 while ((remain = seconds - elapsed) < 0.0)
  seconds *= 2;

 ts.tv_sec = remain;
 ts.tv_nsec = (remain - ts.tv_sec) * 1000000000;
 sshlog("auth2.c", __func__, 254, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "elapsed %0.3lfms, delaying %0.3lfms (requested %0.3lfms)", elapsed*1000, remain*1000, req*1000)
                                         ;
 nanosleep(&ts, 
               ((void *)0)
                   );
}


static int
input_userauth_request(int type, u_int32_t seq, struct ssh *ssh)
{
 Authctxt *authctxt = ssh->authctxt;
 Authmethod *m = 
                ((void *)0)
                    ;
 char *user = 
             ((void *)0)
                 , *service = 
                              ((void *)0)
                                  , *method = 
                                              ((void *)0)
                                                  , *style = 
                                                             ((void *)0)
                                                                 ;
 int r, authenticated = 0;
 double tstart = monotime_double();

 if (authctxt == 
                ((void *)0)
                    )
  sshfatal("auth2.c", __func__, 270, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "input_userauth_request: no authctxt");

 if ((r = sshpkt_get_cstring(ssh, &user, 
                                        ((void *)0)
                                            )) != 0 ||
     (r = sshpkt_get_cstring(ssh, &service, 
                                           ((void *)0)
                                               )) != 0 ||
     (r = sshpkt_get_cstring(ssh, &method, 
                                          ((void *)0)
                                              )) != 0)
  goto out;
 sshlog("auth2.c", __func__, 276, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "userauth-request for user %s service %s method %s", user, service, method);
 sshlog("auth2.c", __func__, 277, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "attempt %d failures %d", authctxt->attempt, authctxt->failures);

 if ((style = strchr(user, ':')) != 
                                   ((void *)0)
                                       )
  *style++ = 0;

 if (authctxt->attempt >= 1024)
  auth_maxtries_exceeded(ssh);
 if (authctxt->attempt++ == 0) {

  authctxt->pw = (use_privsep ? mm_getpwnamallow(ssh, user) : getpwnamallow(ssh, user));
  authctxt->user = xstrdup(user);
  if (authctxt->pw && strcmp(service, "ssh-connection")==0) {
   authctxt->valid = 1;
   sshlog("auth2.c", __func__, 290, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "setting up authctxt for %s", user);
  } else {
   authctxt->valid = 0;

   authctxt->pw = fakepw();



  }




  ssh_packet_set_log_preamble(ssh, "%suser %s",
      authctxt->valid ? "authenticating " : "invalid ", user);
  setproctitle("%s%s", authctxt->valid ? user : "unknown",
      use_privsep ? " [net]" : "");
  authctxt->service = xstrdup(service);
  authctxt->style = style ? xstrdup(style) : 
                                            ((void *)0)
                                                ;
  if (use_privsep)
   mm_inform_authserv(service, style);
  userauth_banner(ssh);
  if (auth2_setup_methods_lists(authctxt) != 0)
   ssh_packet_disconnect(ssh,
       "no authentication methods enabled");
 } else if (strcmp(user, authctxt->user) != 0 ||
     strcmp(service, authctxt->service) != 0) {
  ssh_packet_disconnect(ssh, "Change of username or service "
      "not allowed: (%s,%s) -> (%s,%s)",
      authctxt->user, authctxt->service, user, service);
 }

 auth2_challenge_stop(ssh);







 auth2_authctxt_reset_info(authctxt);
 authctxt->postponed = 0;
 authctxt->server_caused_failure = 0;


 m = authmethod_lookup(authctxt, method);
 if (m != 
         ((void *)0) 
              && authctxt->failures < options.max_authtries) {
  sshlog("auth2.c", __func__, 337, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "input_userauth_request: try method %s", method);
  authenticated = m->userauth(ssh, method);
 }
 if (!authctxt->authenticated)
  ensure_minimum_time_since(tstart,
      user_specific_delay(authctxt->user));
 userauth_finish(ssh, authenticated, method, 
                                            ((void *)0)
                                                );
 r = 0;
 out:
 free(service);
 free(user);
 free(method);
 return r;
}

void
userauth_finish(struct ssh *ssh, int authenticated, const char *packet_method,
    const char *submethod)
{
 Authctxt *authctxt = ssh->authctxt;
 Authmethod *m = 
                ((void *)0)
                    ;
 const char *method = packet_method;
 char *methods;
 int r, partial = 0;

 if (authenticated) {
  if (!authctxt->valid) {
   sshfatal("auth2.c", __func__, 364, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "INTERNAL ERROR: authenticated invalid user %s", authctxt->user)
                      ;
  }
  if (authctxt->postponed)
   sshfatal("auth2.c", __func__, 368, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "INTERNAL ERROR: authenticated and postponed");

  if ((m = authmethod_byname(method)) == 
                                        ((void *)0)
                                            )
   sshfatal("auth2.c", __func__, 371, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "INTERNAL ERROR: bad method %s", method);
  method = m->name;
 }


 if (authenticated && authctxt->pw->pw_uid == 0 &&
     !auth_root_allowed(ssh, method)) {
  authenticated = 0;



 }

 if (authenticated && options.num_auth_methods != 0) {
  if (!auth2_update_methods_lists(authctxt, method, submethod)) {
   authenticated = 0;
   partial = 1;
  }
 }


 auth_log(ssh, authenticated, partial, method, submethod);


 if (authenticated || partial)
  auth2_update_session_info(authctxt, method, submethod);

 if (authctxt->postponed)
  return;
 if (authenticated == 1) {

  ssh_dispatch_set(ssh, 50,
      &dispatch_protocol_ignore);
  if ((r = sshpkt_start(ssh, 52)) != 0 ||
      (r = sshpkt_send(ssh)) != 0 ||
      (r = ssh_packet_write_wait(ssh)) != 0)
   sshfatal("auth2.c", __func__, 430, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send success packet");

  authctxt->success = 1;
  ssh_packet_set_log_preamble(ssh, "user %s", authctxt->user);
 } else {

  if (!partial && !authctxt->server_caused_failure &&
      (authctxt->attempt > 1 || strcmp(method, "none") != 0))
   authctxt->failures++;
  if (authctxt->failures >= options.max_authtries) {



   auth_maxtries_exceeded(ssh);
  }
  methods = authmethods_get(authctxt);
  sshlog("auth2.c", __func__, 446, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "failure partial=%d next methods=\"%s\"", partial, methods)
                       ;
  if ((r = sshpkt_start(ssh, 51)) != 0 ||
      (r = sshpkt_put_cstring(ssh, methods)) != 0 ||
      (r = sshpkt_put_u8(ssh, partial)) != 0 ||
      (r = sshpkt_send(ssh)) != 0 ||
      (r = ssh_packet_write_wait(ssh)) != 0)
   sshfatal("auth2.c", __func__, 453, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send failure packet");
  free(methods);
 }
}






int
auth2_method_allowed(Authctxt *authctxt, const char *method,
    const char *submethod)
{
 u_int i;





 if (options.num_auth_methods == 0)
  return 1;
 for (i = 0; i < authctxt->num_auth_methods; i++) {
  if (list_starts_with(authctxt->auth_methods[i], method,
      submethod) != 0)
   return 1;
 }
 return 0;
}

static char *
authmethods_get(Authctxt *authctxt)
{
 struct sshbuf *b;
 char *list;
 int i, r;

 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("auth2.c", __func__, 491, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 for (i = 0; authmethods[i] != 
                              ((void *)0)
                                  ; i++) {
  if (strcmp(authmethods[i]->name, "none") == 0)
   continue;
  if (authmethods[i]->enabled == 
                                ((void *)0) 
                                     ||
      *(authmethods[i]->enabled) == 0)
   continue;
  if (!auth2_method_allowed(authctxt, authmethods[i]->name,
      
     ((void *)0)
         ))
   continue;
  if ((r = sshbuf_putf(b, "%s%s", sshbuf_len(b) ? "," : "",
      authmethods[i]->name)) != 0)
   sshfatal("auth2.c", __func__, 503, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "buffer error");
 }
 if ((list = sshbuf_dup_string(b)) == 
                                     ((void *)0)
                                         )
  sshfatal("auth2.c", __func__, 506, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_dup_string failed");
 sshbuf_free(b);
 return list;
}

static Authmethod *
authmethod_byname(const char *name)
{
 int i;

 if (name == 
            ((void *)0)
                )
  sshfatal("auth2.c", __func__, 517, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "NULL authentication method name");
 for (i = 0; authmethods[i] != 
                              ((void *)0)
                                  ; i++) {
  if (strcmp(name, authmethods[i]->name) == 0 ||
      (authmethods[i]->synonym != 
                                 ((void *)0) 
                                      &&
      strcmp(name, authmethods[i]->synonym) == 0))
   return authmethods[i];
 }
 sshlog("auth2.c", __func__, 524, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "unrecognized authentication method name: %s", name);
 return 
       ((void *)0)
           ;
}

static Authmethod *
authmethod_lookup(Authctxt *authctxt, const char *name)
{
 Authmethod *method;

 if ((method = authmethod_byname(name)) == 
                                          ((void *)0)
                                              )
  return 
        ((void *)0)
            ;

 if (method->enabled == 
                       ((void *)0) 
                            || *(method->enabled) == 0) {
  sshlog("auth2.c", __func__, 537, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "method %s not enabled", name);
  return 
        ((void *)0)
            ;
 }
 if (!auth2_method_allowed(authctxt, method->name, 
                                                  ((void *)0)
                                                      )) {
  sshlog("auth2.c", __func__, 541, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "method %s not allowed " "by AuthenticationMethods", name)
                                       ;
  return 
        ((void *)0)
            ;
 }
 return method;
}






int
auth2_methods_valid(const char *_methods, int need_enable)
{
 char *methods, *omethods, *method, *p;
 u_int i, found;
 int ret = -1;

 if (*_methods == '\0') {
  sshlog("auth2.c", __func__, 561, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "empty authentication method list");
  return -1;
 }
 omethods = methods = xstrdup(_methods);
 while ((method = strsep(&methods, ",")) != 
                                           ((void *)0)
                                               ) {
  for (found = i = 0; !found && authmethods[i] != 
                                                 ((void *)0)
                                                     ; i++) {
   if ((p = strchr(method, ':')) != 
                                   ((void *)0)
                                       )
    *p = '\0';
   if (strcmp(method, authmethods[i]->name) != 0)
    continue;
   if (need_enable) {
    if (authmethods[i]->enabled == 
                                  ((void *)0) 
                                       ||
        *(authmethods[i]->enabled) == 0) {
     sshlog("auth2.c", __func__, 574, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "Disabled method \"%s\" in " "AuthenticationMethods list \"%s\"", method, _methods)

                          ;
     goto out;
    }
   }
   found = 1;
   break;
  }
  if (!found) {
   sshlog("auth2.c", __func__, 584, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Unknown authentication method \"%s\" in list", method)
              ;
   goto out;
  }
 }
 ret = 0;
 out:
 free(omethods);
 return ret;
}
int
auth2_setup_methods_lists(Authctxt *authctxt)
{
 u_int i;


 if (options.num_auth_methods == 1 &&
     strcmp(options.auth_methods[0], "any") == 0) {
  free(options.auth_methods[0]);
  options.auth_methods[0] = 
                           ((void *)0)
                               ;
  options.num_auth_methods = 0;
 }

 if (options.num_auth_methods == 0)
  return 0;
 sshlog("auth2.c", __func__, 617, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "checking methods");
 authctxt->auth_methods = xcalloc(options.num_auth_methods,
     sizeof(*authctxt->auth_methods));
 authctxt->num_auth_methods = 0;
 for (i = 0; i < options.num_auth_methods; i++) {
  if (auth2_methods_valid(options.auth_methods[i], 1) != 0) {
   sshlog("auth2.c", __func__, 623, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Authentication methods list \"%s\" contains " "disabled method, skipping", options.auth_methods[i])

                               ;
   continue;
  }
  sshlog("auth2.c", __func__, 628, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "authentication methods list %d: %s", authctxt->num_auth_methods, options.auth_methods[i])
                                                          ;
  authctxt->auth_methods[authctxt->num_auth_methods++] =
      xstrdup(options.auth_methods[i]);
 }
 if (authctxt->num_auth_methods == 0) {
  sshlog("auth2.c", __func__, 634, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "No AuthenticationMethods left after eliminating " "disabled methods")
                         ;
  return -1;
 }
 return 0;
}

static int
list_starts_with(const char *methods, const char *method,
    const char *submethod)
{
 size_t l = strlen(method);
 int match;
 const char *p;

 if (strncmp(methods, method, l) != 0)
  return 0;
 p = methods + l;
 match = 1;
 if (*p == ':') {
  if (!submethod)
   return 3;
  l = strlen(submethod);
  p += 1;
  if (strncmp(submethod, p, l))
   return 0;
  p += l;
  match = 2;
 }
 if (*p != ',' && *p != '\0')
  return 0;
 return match;
}






static int
remove_method(char **methods, const char *method, const char *submethod)
{
 char *omethods = *methods, *p;
 size_t l = strlen(method);
 int match;

 match = list_starts_with(omethods, method, submethod);
 if (match != 1 && match != 2)
  return 0;
 p = omethods + l;
 if (submethod && match == 2)
  p += 1 + strlen(submethod);
 if (*p == ',')
  p++;
 *methods = xstrdup(p);
 free(omethods);
 return 1;
}







int
auth2_update_methods_lists(Authctxt *authctxt, const char *method,
    const char *submethod)
{
 u_int i, found = 0;

 sshlog("auth2.c", __func__, 705, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "updating methods list after \"%s\"", method);
 for (i = 0; i < authctxt->num_auth_methods; i++) {
  if (!remove_method(&(authctxt->auth_methods[i]), method,
      submethod))
   continue;
  found = 1;
  if (*authctxt->auth_methods[i] == '\0') {
   sshlog("auth2.c", __func__, 712, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "authentication methods list %d complete", i);
   return 1;
  }
  sshlog("auth2.c", __func__, 715, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "authentication methods list %d remaining: \"%s\"", i, authctxt->auth_methods[i])
                                   ;
 }

 if (!found)
  sshfatal("auth2.c", __func__, 720, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "method not in AuthenticationMethods");
 return 0;
}


void auth2_authctxt_reset_info(Authctxt *authctxt)
{
 sshkey_free(authctxt->auth_method_key);
 free(authctxt->auth_method_info);
 authctxt->auth_method_key = 
                            ((void *)0)
                                ;
 authctxt->auth_method_info = 
                             ((void *)0)
                                 ;
}


void
auth2_record_info(Authctxt *authctxt, const char *fmt, ...)
{
 va_list ap;
 int i;

 free(authctxt->auth_method_info);
 authctxt->auth_method_info = 
                             ((void *)0)
                                 ;

 
__builtin_va_start(
ap
,
fmt
)
                 ;
 i = vasprintf(&authctxt->auth_method_info, fmt, ap);
 
__builtin_va_end(
ap
)
          ;

 if (i == -1)
  sshfatal("auth2.c", __func__, 748, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "vasprintf failed");
}






void
auth2_record_key(Authctxt *authctxt, int authenticated,
    const struct sshkey *key)
{
 struct sshkey **tmp, *dup;
 int r;

 if ((r = sshkey_from_private(key, &dup)) != 0)
  sshfatal("auth2.c", __func__, 764, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "copy key");
 sshkey_free(authctxt->auth_method_key);
 authctxt->auth_method_key = dup;

 if (!authenticated)
  return;


 if ((r = sshkey_from_private(key, &dup)) != 0)
  sshfatal("auth2.c", __func__, 773, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "copy key");
 if (authctxt->nprev_keys >= 0x7fffffff ||
     (tmp = recallocarray(authctxt->prev_keys, authctxt->nprev_keys,
     authctxt->nprev_keys + 1, sizeof(*authctxt->prev_keys))) == 
                                                                ((void *)0)
                                                                    )
  sshfatal("auth2.c", __func__, 777, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "reallocarray failed");
 authctxt->prev_keys = tmp;
 authctxt->prev_keys[authctxt->nprev_keys] = dup;
 authctxt->nprev_keys++;

}


int
auth2_key_already_used(Authctxt *authctxt, const struct sshkey *key)
{
 u_int i;
 char *fp;

 for (i = 0; i < authctxt->nprev_keys; i++) {
  if (sshkey_equal_public(key, authctxt->prev_keys[i])) {
   fp = sshkey_fingerprint(authctxt->prev_keys[i],
       options.fingerprint_hash, SSH_FP_DEFAULT);
   sshlog("auth2.c", __func__, 795, 1, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "key already used: %s %s", sshkey_type(authctxt->prev_keys[i]), fp == 
  ((void *)0) 
  ? "UNKNOWN" : fp)

                                   ;
   free(fp);
   return 1;
  }
 }
 return 0;
}





void
auth2_update_session_info(Authctxt *authctxt, const char *method,
    const char *submethod)
{
 int r;

 if (authctxt->session_info == 
                              ((void *)0)
                                  ) {
  if ((authctxt->session_info = sshbuf_new()) == 
                                                ((void *)0)
                                                    )
   sshfatal("auth2.c", __func__, 817, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshbuf_new");
 }


 if ((r = sshbuf_putf(authctxt->session_info, "%s%s%s",
     method, submethod == 
                         ((void *)0) 
                              ? "" : "/",
     submethod == 
                 ((void *)0) 
                      ? "" : submethod)) != 0)
  sshfatal("auth2.c", __func__, 824, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "append method");


 if (authctxt->auth_method_key != 
                                 ((void *)0)
                                     ) {
  if ((r = sshbuf_put_u8(authctxt->session_info, ' ')) != 0 ||
      (r = sshkey_format_text(authctxt->auth_method_key,
      authctxt->session_info)) != 0)
   sshfatal("auth2.c", __func__, 831, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "append key");
 }

 if (authctxt->auth_method_info != 
                                  ((void *)0)
                                      ) {

  if (strchr(authctxt->auth_method_info, '\n') != 
                                                 ((void *)0)
                                                     )
   sshfatal("auth2.c", __func__, 837, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "auth_method_info contains \\n");
  if ((r = sshbuf_put_u8(authctxt->session_info, ' ')) != 0 ||
      (r = sshbuf_putf(authctxt->session_info, "%s",
      authctxt->auth_method_info)) != 0) {
   sshfatal("auth2.c", __func__, 841, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "append method info");
  }
 }
 if ((r = sshbuf_put_u8(authctxt->session_info, '\n')) != 0)
  sshfatal("auth2.c", __func__, 845, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "append");
}
