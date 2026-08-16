











































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
struct termios *get_saved_tio(void);
void leave_raw_mode(int);
void enter_raw_mode(int);

int pty_allocate(int *, int *, char *, size_t);
void pty_release(const char *);
void pty_make_controlling_tty(int *, const char *);
void pty_change_window_size(int, u_int, u_int, u_int, u_int);
void pty_setowner(struct passwd *, const char *);
void disconnect_controlling_tty(void);
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
void temporarily_use_uid(struct passwd *);
void restore_uid(void);
void permanently_set_uid(struct passwd *);
struct ssh;

void compat_banner(struct ssh *, const char *);
char *compat_cipher_proposal(struct ssh *, char *);
char *compat_pkalg_proposal(struct ssh *, char *);
char *compat_kex_proposal(struct ssh *, char *);
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
struct sshmac {
 char *name;
 int enabled;
 u_int mac_len;
 u_char *key;
 u_int key_len;
 int type;
 int etm;
 struct ssh_hmac_ctx *hmac_ctx;
 struct umac_ctx *umac_ctx;
};

int mac_valid(const char *);
char *mac_alg_list(char);
int mac_setup(struct sshmac *, char *);
int mac_init(struct sshmac *);
int mac_compute(struct sshmac *, u_int32_t, const u_char *, int,
    u_char *, size_t);
int mac_check(struct sshmac *, u_int32_t, const u_char *, size_t,
    const u_char *, size_t);
void mac_clear(struct sshmac *);
typedef int8_t crypto_int8;
typedef uint8_t crypto_uint8;
typedef int16_t crypto_int16;
typedef uint16_t crypto_uint16;
typedef int32_t crypto_int32;
typedef uint32_t crypto_uint32;
typedef int64_t crypto_int64;
typedef uint64_t crypto_uint64;






int crypto_hash_sha512(unsigned char *, const unsigned char *,
    unsigned long long);

int crypto_verify_32(const unsigned char *, const unsigned char *);





int crypto_sign_ed25519(unsigned char *, unsigned long long *,
    const unsigned char *, unsigned long long, const unsigned char *);
int crypto_sign_ed25519_open(unsigned char *, unsigned long long *,
    const unsigned char *, unsigned long long, const unsigned char *);
int crypto_sign_ed25519_keypair(unsigned char *, unsigned char *);






int crypto_kem_sntrup761_enc(unsigned char *cstr, unsigned char *k,
    const unsigned char *pk);
int crypto_kem_sntrup761_dec(unsigned char *k,
    const unsigned char *cstr, const unsigned char *sk);
int crypto_kem_sntrup761_keypair(unsigned char *pk, unsigned char *sk);




enum kex_init_proposals {
 PROPOSAL_KEX_ALGS,
 PROPOSAL_SERVER_HOST_KEY_ALGS,
 PROPOSAL_ENC_ALGS_CTOS,
 PROPOSAL_ENC_ALGS_STOC,
 PROPOSAL_MAC_ALGS_CTOS,
 PROPOSAL_MAC_ALGS_STOC,
 PROPOSAL_COMP_ALGS_CTOS,
 PROPOSAL_COMP_ALGS_STOC,
 PROPOSAL_LANG_CTOS,
 PROPOSAL_LANG_STOC,
 PROPOSAL_MAX
};

enum kex_modes {
 MODE_IN,
 MODE_OUT,
 MODE_MAX
};

enum kex_exchange {
 KEX_DH_GRP1_SHA1,
 KEX_DH_GRP14_SHA1,
 KEX_DH_GRP14_SHA256,
 KEX_DH_GRP16_SHA512,
 KEX_DH_GRP18_SHA512,
 KEX_DH_GEX_SHA1,
 KEX_DH_GEX_SHA256,
 KEX_ECDH_SHA2,
 KEX_C25519_SHA256,
 KEX_KEM_SNTRUP761X25519_SHA512,
 KEX_MAX
};
struct sshenc {
 char *name;
 const struct sshcipher *cipher;
 int enabled;
 u_int key_len;
 u_int iv_len;
 u_int block_size;
 u_char *key;
 u_char *iv;
};
struct sshcomp {
 u_int type;
 int enabled;
 char *name;
};
struct newkeys {
 struct sshenc enc;
 struct sshmac mac;
 struct sshcomp comp;
};

struct ssh;
struct sshbuf;

struct kex {
 struct newkeys *newkeys[MODE_MAX];
 u_int we_need;
 u_int dh_need;
 int server;
 char *name;
 char *hostkey_alg;
 int hostkey_type;
 int hostkey_nid;
 u_int kex_type;
 char *server_sig_algs;
 int ext_info_c;
 struct sshbuf *my;
 struct sshbuf *peer;
 struct sshbuf *client_version;
 struct sshbuf *server_version;
 struct sshbuf *session_id;
 struct sshbuf *initial_sig;
 struct sshkey *initial_hostkey;
 sig_atomic_t done;
 u_int flags;
 int hash_alg;
 int ec_nid;
 char *failed_choice;
 int (*verify_host_key)(struct sshkey *, struct ssh *);
 struct sshkey *(*load_host_public_key)(int, int, struct ssh *);
 struct sshkey *(*load_host_private_key)(int, int, struct ssh *);
 int (*host_key_index)(struct sshkey *, int, struct ssh *);
 int (*sign)(struct ssh *, struct sshkey *, struct sshkey *,
     u_char **, size_t *, const u_char *, size_t, const char *);
 int (*kex[KEX_MAX])(struct ssh *);

 DH *dh;
 u_int min, max, nbits;
 EC_KEY *ec_client_key;
 const EC_GROUP *ec_group;
 u_char c25519_client_key[32];
 u_char c25519_client_pubkey[32];
 u_char sntrup761_client_key[1763];
 struct sshbuf *client_pub;
};

int kex_names_valid(const char *);
char *kex_alg_list(char);
char *kex_names_cat(const char *, const char *);
int kex_assemble_names(char **, const char *, const char *);

int kex_exchange_identification(struct ssh *, int, const char *);

struct kex *kex_new(void);
int kex_ready(struct ssh *, char *[PROPOSAL_MAX]);
int kex_setup(struct ssh *, char *[PROPOSAL_MAX]);
void kex_free_newkeys(struct newkeys *);
void kex_free(struct kex *);

int kex_buf2prop(struct sshbuf *, int *, char ***);
int kex_prop2buf(struct sshbuf *, char *proposal[PROPOSAL_MAX]);
void kex_prop_free(char **);
int kex_load_hostkey(struct ssh *, struct sshkey **, struct sshkey **);
int kex_verify_host_key(struct ssh *, struct sshkey *);

int kex_send_kexinit(struct ssh *);
int kex_input_kexinit(int, u_int32_t, struct ssh *);
int kex_input_ext_info(int, u_int32_t, struct ssh *);
int kex_protocol_error(int, u_int32_t, struct ssh *);
int kex_derive_keys(struct ssh *, u_char *, u_int, const struct sshbuf *);
int kex_send_newkeys(struct ssh *);
int kex_start_rekex(struct ssh *);

int kexgex_client(struct ssh *);
int kexgex_server(struct ssh *);
int kex_gen_client(struct ssh *);
int kex_gen_server(struct ssh *);

int kex_dh_keypair(struct kex *);
int kex_dh_enc(struct kex *, const struct sshbuf *, struct sshbuf **,
    struct sshbuf **);
int kex_dh_dec(struct kex *, const struct sshbuf *, struct sshbuf **);

int kex_ecdh_keypair(struct kex *);
int kex_ecdh_enc(struct kex *, const struct sshbuf *, struct sshbuf **,
    struct sshbuf **);
int kex_ecdh_dec(struct kex *, const struct sshbuf *, struct sshbuf **);

int kex_c25519_keypair(struct kex *);
int kex_c25519_enc(struct kex *, const struct sshbuf *, struct sshbuf **,
    struct sshbuf **);
int kex_c25519_dec(struct kex *, const struct sshbuf *, struct sshbuf **);

int kex_kem_sntrup761x25519_keypair(struct kex *);
int kex_kem_sntrup761x25519_enc(struct kex *, const struct sshbuf *,
    struct sshbuf **, struct sshbuf **);
int kex_kem_sntrup761x25519_dec(struct kex *, const struct sshbuf *,
    struct sshbuf **);

int kex_dh_keygen(struct kex *);
int kex_dh_compute_key(struct kex *, BIGNUM *, struct sshbuf *);

int kexgex_hash(int, const struct sshbuf *, const struct sshbuf *,
    const struct sshbuf *, const struct sshbuf *, const struct sshbuf *,
    int, int, int,
    const BIGNUM *, const BIGNUM *, const BIGNUM *,
    const BIGNUM *, const u_char *, size_t,
    u_char *, size_t *);

void kexc25519_keygen(u_char key[32], u_char pub[32])
 __attribute__(())
 __attribute__(());
int kexc25519_shared_key(const u_char key[32],
    const u_char pub[32], struct sshbuf *out)
 __attribute__(())
 __attribute__(());
int kexc25519_shared_key_ext(const u_char key[32],
    const u_char pub[32], struct sshbuf *out, int)
 __attribute__(())
 __attribute__(());
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
char *get_peer_ipaddr(int);
int get_peer_port(int);
char *get_local_ipaddr(int);
char *get_local_name(int);
int get_local_port(int);



void ipv64_normalise_mapped(struct sockaddr_storage *, socklen_t *);
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
int ssh_msg_send(int, u_char, struct sshbuf *);
int ssh_msg_recv(int, struct sshbuf *);

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
typedef struct Session Session;
struct Session {
 int used;
 int self;
 int next_unused;
 struct passwd *pw;
 Authctxt *authctxt;
 pid_t pid;
 int forced;


 char *term;
 int ptyfd, ttyfd, ptymaster;
 u_int row, col, xpixel, ypixel;
 char tty[64];


 u_int display_number;
 char *display;
 u_int screen;
 char *auth_display;
 char *auth_proto;
 char *auth_data;
 int single_connection;

 int chanid;
 int *x11_chanids;
 int is_subsystem;
 char *subsys;
 u_int num_env;
 struct {
  char *name;
  char *val;
 } *env;
};

void do_authenticated(struct ssh *, Authctxt *);
void do_cleanup(struct ssh *, Authctxt *);

int session_open(Authctxt *, int);
void session_unused(int);
int session_input_channel_req(struct ssh *, Channel *, const char *);
void session_close_by_pid(struct ssh *ssh, pid_t, int);
void session_close_by_channel(struct ssh *, int, void *);
void session_destroy_all(struct ssh *, void (*)(Session *));
void session_pty_cleanup2(Session *);

Session *session_new(void);
Session *session_by_tty(char *);
void session_close(struct ssh *, Session *);
void do_setusercontext(struct passwd *);

const char *session_get_remote_name_or_ip(struct ssh *, u_int, int);
enum monitor_reqtype {
 MONITOR_REQ_MODULI = 0, MONITOR_ANS_MODULI = 1,
 MONITOR_REQ_FREE = 2,
 MONITOR_REQ_AUTHSERV = 4,
 MONITOR_REQ_SIGN = 6, MONITOR_ANS_SIGN = 7,
 MONITOR_REQ_PWNAM = 8, MONITOR_ANS_PWNAM = 9,
 MONITOR_REQ_AUTH2_READ_BANNER = 10, MONITOR_ANS_AUTH2_READ_BANNER = 11,
 MONITOR_REQ_AUTHPASSWORD = 12, MONITOR_ANS_AUTHPASSWORD = 13,
 MONITOR_REQ_BSDAUTHQUERY = 14, MONITOR_ANS_BSDAUTHQUERY = 15,
 MONITOR_REQ_BSDAUTHRESPOND = 16, MONITOR_ANS_BSDAUTHRESPOND = 17,
 MONITOR_REQ_KEYALLOWED = 22, MONITOR_ANS_KEYALLOWED = 23,
 MONITOR_REQ_KEYVERIFY = 24, MONITOR_ANS_KEYVERIFY = 25,
 MONITOR_REQ_KEYEXPORT = 26,
 MONITOR_REQ_PTY = 28, MONITOR_ANS_PTY = 29,
 MONITOR_REQ_PTYCLEANUP = 30,
 MONITOR_REQ_SESSKEY = 32, MONITOR_ANS_SESSKEY = 33,
 MONITOR_REQ_SESSID = 34,
 MONITOR_REQ_RSAKEYALLOWED = 36, MONITOR_ANS_RSAKEYALLOWED = 37,
 MONITOR_REQ_RSACHALLENGE = 38, MONITOR_ANS_RSACHALLENGE = 39,
 MONITOR_REQ_RSARESPONSE = 40, MONITOR_ANS_RSARESPONSE = 41,
 MONITOR_REQ_GSSSETUP = 42, MONITOR_ANS_GSSSETUP = 43,
 MONITOR_REQ_GSSSTEP = 44, MONITOR_ANS_GSSSTEP = 45,
 MONITOR_REQ_GSSUSEROK = 46, MONITOR_ANS_GSSUSEROK = 47,
 MONITOR_REQ_GSSCHECKMIC = 48, MONITOR_ANS_GSSCHECKMIC = 49,
 MONITOR_REQ_TERM = 50,

 MONITOR_REQ_PAM_START = 100,
 MONITOR_REQ_PAM_ACCOUNT = 102, MONITOR_ANS_PAM_ACCOUNT = 103,
 MONITOR_REQ_PAM_INIT_CTX = 104, MONITOR_ANS_PAM_INIT_CTX = 105,
 MONITOR_REQ_PAM_QUERY = 106, MONITOR_ANS_PAM_QUERY = 107,
 MONITOR_REQ_PAM_RESPOND = 108, MONITOR_ANS_PAM_RESPOND = 109,
 MONITOR_REQ_PAM_FREE_CTX = 110, MONITOR_ANS_PAM_FREE_CTX = 111,
 MONITOR_REQ_AUDIT_EVENT = 112, MONITOR_REQ_AUDIT_COMMAND = 113,

};

struct ssh;

struct monitor {
 int m_recvfd;
 int m_sendfd;
 int m_log_recvfd;
 int m_log_sendfd;
 struct kex **m_pkex;
 pid_t m_pid;
};

struct monitor *monitor_init(void);
void monitor_reinit(struct monitor *);

struct Authctxt;
void monitor_child_preauth(struct ssh *, struct monitor *);
void monitor_child_postauth(struct ssh *, struct monitor *);

void monitor_clear_keystate(struct ssh *, struct monitor *);
void monitor_apply_keystate(struct ssh *, struct monitor *);


void mm_request_send(int, enum monitor_reqtype, struct sshbuf *);
void mm_request_receive(int, struct sshbuf *);
void mm_request_receive_expect(int, enum monitor_reqtype, struct sshbuf *);
void mm_get_keystate(struct ssh *, struct monitor *);



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
struct monitor;
struct ssh_sandbox;

struct ssh_sandbox *ssh_sandbox_init(struct monitor *);
void ssh_sandbox_child(struct ssh_sandbox *);
void ssh_sandbox_parent_finish(struct ssh_sandbox *);
void ssh_sandbox_parent_preauth(struct ssh_sandbox *, pid_t);
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
void srclimit_init(int, int, int, int);
int srclimit_check_allow(int, int);
void srclimit_done(int);
struct dhgroup {
 int size;
 BIGNUM *g;
 BIGNUM *p;
};

DH *choose_dh(int, int, int);
DH *dh_new_group_asc(const char *, const char *);
DH *dh_new_group(BIGNUM *, BIGNUM *);
DH *dh_new_group1(void);
DH *dh_new_group14(void);
DH *dh_new_group16(void);
DH *dh_new_group18(void);
DH *dh_new_group_fallback(int);

int dh_gen_key(DH *, int);
int dh_pub_is_valid(const DH *, const BIGNUM *);

u_int dh_estimate(int);
void dh_set_moduli_file(const char *);







extern char *__progname;


ServerOptions options;


char *config_file_name = "/usr/local/etc" "/sshd_config";







int debug_flag = 0;







static int test_flag = 0;


static int inetd_flag = 0;


static int no_daemon_flag = 0;


static int log_stderr = 0;


static char **saved_argv;
static int saved_argc;


static int rexeced_flag = 0;
static int rexec_flag = 1;
static int rexec_argc = 0;
static char **rexec_argv;






static int listen_socks[16];
static int num_listen_socks = 0;


int auth_sock = -1;
static int have_agent = 0;
struct {
 struct sshkey **host_keys;
 struct sshkey **host_pubkeys;
 struct sshkey **host_certificates;
 int have_ssh2_key;
} sensitive_data;


static volatile sig_atomic_t received_sighup = 0;
static volatile sig_atomic_t received_sigterm = 0;


u_int utmp_len = 
                64
                             +1;
static int *startup_pipes = 
                           ((void *)0)
                               ;
static int *startup_flags = 
                           ((void *)0)
                               ;
static int startup_pipe = -1;


int use_privsep = -1;
struct monitor *pmonitor = 
                          ((void *)0)
                              ;
int privsep_is_preauth = 1;
static int privsep_chroot = 1;


Authctxt *the_authctxt = 
                        ((void *)0)
                            ;
struct ssh *the_active_state;


struct sshauthopt *auth_opts = 
                              ((void *)0)
                                  ;


struct sshbuf *cfg;


struct include_list includes = { 
                              ((void *)0)
                              , &(includes).tqh_first };


struct sshbuf *loginmsg;


struct passwd *privsep_pw = 
                           ((void *)0)
                               ;


void destroy_sensitive_data(void);
void demote_sensitive_data(void);
static void do_ssh2_kex(struct ssh *);

static char *listener_proctitle;




static void
close_listen_socks(void)
{
 int i;

 for (i = 0; i < num_listen_socks; i++)
  close(listen_socks[i]);
 num_listen_socks = 0;
}

static void
close_startup_pipes(void)
{
 int i;

 if (startup_pipes)
  for (i = 0; i < options.max_startups; i++)
   if (startup_pipes[i] != -1)
    close(startup_pipes[i]);
}
static void
sighup_handler(int sig)
{
 received_sighup = 1;
}





static void
sighup_restart(void)
{
 sshlog("sshd.c", __func__, 312, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "Received SIGHUP; restarting.");
 if (options.pid_file != 
                        ((void *)0)
                            )
  unlink(options.pid_file);
 platform_pre_restart();
 close_listen_socks();
 close_startup_pipes();
 ssh_signal(
           1
                 , 
                   ((__sighandler_t) 1)
                          );
 execv(saved_argv[0], saved_argv);
 sshlog("sshd.c", __func__, 320, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "RESTART FAILED: av[0]='%.100s', error: %.100s.", saved_argv[0], strerror(
(*__errno_location ())
))
                     ;
 exit(1);
}





static void
sigterm_handler(int sig)
{
 received_sigterm = sig;
}






static void
main_sigchld_handler(int sig)
{
 int save_errno = 
                 (*__errno_location ())
                      ;
 pid_t pid;
 int status;

 while ((pid = waitpid(-1, &status, 
                                   1
                                          )) > 0 ||
     (pid == -1 && 
                  (*__errno_location ()) 
                        == 
                           4
                                ))
  ;
 
(*__errno_location ()) 
      = save_errno;
}





static void
grace_alarm_handler(int sig)
{




 if (getpgid(0) == getpid()) {
  ssh_signal(
            15
                   , 
                     ((__sighandler_t) 1)
                            );
  kill(0, 
         15
                );
 }


 sshsigdie("sshd.c", __func__, 370, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "Timeout before authentication for %s port %d", ssh_remote_ipaddr(the_active_state), ssh_remote_port(the_active_state))

                                       ;
}


void
destroy_sensitive_data(void)
{
 u_int i;

 for (i = 0; i < options.num_host_key_files; i++) {
  if (sensitive_data.host_keys[i]) {
   sshkey_free(sensitive_data.host_keys[i]);
   sensitive_data.host_keys[i] = 
                                ((void *)0)
                                    ;
  }
  if (sensitive_data.host_certificates[i]) {
   sshkey_free(sensitive_data.host_certificates[i]);
   sensitive_data.host_certificates[i] = 
                                        ((void *)0)
                                            ;
  }
 }
}


void
demote_sensitive_data(void)
{
 struct sshkey *tmp;
 u_int i;
 int r;

 for (i = 0; i < options.num_host_key_files; i++) {
  if (sensitive_data.host_keys[i]) {
   if ((r = sshkey_from_private(
       sensitive_data.host_keys[i], &tmp)) != 0)
    sshfatal("sshd.c", __func__, 405, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "could not demote host %s key", sshkey_type(sensitive_data.host_keys[i]))
                                                 ;
   sshkey_free(sensitive_data.host_keys[i]);
   sensitive_data.host_keys[i] = tmp;
  }

 }
}

static void
reseed_prngs(void)
{
 u_int32_t rnd[256];


 RAND_poll();

 ;
 arc4random_buf(rnd, sizeof(rnd));


 RAND_seed(rnd, sizeof(rnd));

 if ((RAND_bytes((u_char *)rnd, 1)) != 1)
  sshfatal("sshd.c", __func__, 429, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "%s: RAND_bytes failed", __func__);


 explicit_bzero(rnd, sizeof(rnd));
}

static void
privsep_preauth_child(void)
{
 gid_t gidset[1];


 privsep_challenge_enable();






 reseed_prngs();


 demote_sensitive_data();


 if (privsep_chroot) {

  if (chroot("/var/empty") == -1)
   sshfatal("sshd.c", __func__, 457, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "chroot(\"%s\"): %s", "/var/empty", strerror(
  (*__errno_location ())
  ))
                       ;
  if (chdir("/") == -1)
   sshfatal("sshd.c", __func__, 460, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "chdir(\"/\"): %s", strerror(
  (*__errno_location ())
  ));


  sshlog("sshd.c", __func__, 463, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "privsep user:group %u:%u", (u_int)privsep_pw->pw_uid, (u_int)privsep_pw->pw_gid)
                                ;
  gidset[0] = privsep_pw->pw_gid;
  if (setgroups(1, gidset) == -1)
   sshfatal("sshd.c", __func__, 467, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "setgroups: %.100s", strerror(
  (*__errno_location ())
  ));
  permanently_set_uid(privsep_pw);
 }
}

static int
privsep_preauth(struct ssh *ssh)
{
 int status, r;
 pid_t pid;
 struct ssh_sandbox *box = 
                          ((void *)0)
                              ;


 pmonitor = monitor_init();

 pmonitor->m_pkex = &ssh->kex;

 if (use_privsep == 1)
  box = ssh_sandbox_init(pmonitor);
 pid = fork();
 if (pid == -1) {
  sshfatal("sshd.c", __func__, 488, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "fork of unprivileged child failed");
 } else if (pid != 0) {
  sshlog("sshd.c", __func__, 490, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "Network child is on pid %ld", (long)pid);

  pmonitor->m_pid = pid;
  if (have_agent) {
   r = ssh_get_authentication_socket(&auth_sock);
   if (r != 0) {
    sshlog("sshd.c", __func__, 496, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Could not get agent socket");
    have_agent = 0;
   }
  }
  if (box != 
            ((void *)0)
                )
   ssh_sandbox_parent_preauth(box, pid);
  monitor_child_preauth(ssh, pmonitor);


  while (waitpid(pid, &status, 0) == -1) {
   if (
      (*__errno_location ()) 
            == 
               4
                    )
    continue;
   pmonitor->m_pid = -1;
   sshfatal("sshd.c", __func__, 509, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "waitpid: %s", strerror(
  (*__errno_location ())
  ));
  }
  privsep_is_preauth = 0;
  pmonitor->m_pid = -1;
  if (
     (((
     status
     ) & 0x7f) == 0)
                      ) {
   if (
      (((
      status
      ) & 0xff00) >> 8) 
                          != 0)
    sshfatal("sshd.c", __func__, 515, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "preauth child exited with status %d", 
   (((
   status
   ) & 0xff00) >> 8)
   )
                            ;
  } else if (
            (((signed char) (((
            status
            ) & 0x7f) + 1) >> 1) > 0)
                               )
   sshfatal("sshd.c", __func__, 518, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "preauth child terminated by signal %d", 
  ((
  status
  ) & 0x7f)
  )
                        ;
  if (box != 
            ((void *)0)
                )
   ssh_sandbox_parent_finish(box);
  return 1;
 } else {

  close(pmonitor->m_sendfd);
  close(pmonitor->m_log_recvfd);


  set_log_handler(mm_log_handler, pmonitor);

  privsep_preauth_child();
  setproctitle("%s", "[net]");
  if (box != 
            ((void *)0)
                )
   ssh_sandbox_child(box);

  return 0;
 }
}

static void
privsep_postauth(struct ssh *ssh, Authctxt *authctxt)
{



 if (authctxt->pw->pw_uid == 0) {


  use_privsep = 0;
  goto skip;
 }


 monitor_reinit(pmonitor);

 pmonitor->m_pid = fork();
 if (pmonitor->m_pid == -1)
  sshfatal("sshd.c", __func__, 558, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "fork of unprivileged child failed");
 else if (pmonitor->m_pid != 0) {
  sshlog("sshd.c", __func__, 560, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "User child is on pid %ld", (long)pmonitor->m_pid);
  sshbuf_reset(loginmsg);
  monitor_clear_keystate(ssh, pmonitor);
  monitor_child_postauth(ssh, pmonitor);


  exit(0);
 }



 close(pmonitor->m_sendfd);
 pmonitor->m_sendfd = -1;


 demote_sensitive_data();

 reseed_prngs();


 do_setusercontext(authctxt->pw);

 skip:

 monitor_apply_keystate(ssh, pmonitor);





 ssh_packet_set_authenticated(ssh);
}

static void
append_hostkey_type(struct sshbuf *b, const char *s)
{
 int r;

 if (match_pattern_list(s, options.hostkeyalgorithms, 0) != 1) {
  sshlog("sshd.c", __func__, 599, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "%s key not permitted by HostkeyAlgorithms", s);
  return;
 }
 if ((r = sshbuf_putf(b, "%s%s", sshbuf_len(b) > 0 ? "," : "", s)) != 0)
  sshfatal("sshd.c", __func__, 603, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_putf");
}

static char *
list_hostkey_types(void)
{
 struct sshbuf *b;
 struct sshkey *key;
 char *ret;
 u_int i;

 if ((b = sshbuf_new()) == 
                          ((void *)0)
                              )
  sshfatal("sshd.c", __func__, 615, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 for (i = 0; i < options.num_host_key_files; i++) {
  key = sensitive_data.host_keys[i];
  if (key == 
            ((void *)0)
                )
   key = sensitive_data.host_pubkeys[i];
  if (key == 
            ((void *)0)
                )
   continue;
  switch (key->type) {
  case KEY_RSA:

   append_hostkey_type(b, "rsa-sha2-512");
   append_hostkey_type(b, "rsa-sha2-256");

  case KEY_DSA:
  case KEY_ECDSA:
  case KEY_ED25519:
  case KEY_ECDSA_SK:
  case KEY_ED25519_SK:
  case KEY_XMSS:
   append_hostkey_type(b, sshkey_ssh_name(key));
   break;
  }

  key = sensitive_data.host_certificates[i];
  if (key == 
            ((void *)0)
                )
   continue;
  switch (key->type) {
  case KEY_RSA_CERT:

   append_hostkey_type(b,
       "rsa-sha2-512-cert-v01@openssh.com");
   append_hostkey_type(b,
       "rsa-sha2-256-cert-v01@openssh.com");

  case KEY_DSA_CERT:
  case KEY_ECDSA_CERT:
  case KEY_ED25519_CERT:
  case KEY_ECDSA_SK_CERT:
  case KEY_ED25519_SK_CERT:
  case KEY_XMSS_CERT:
   append_hostkey_type(b, sshkey_ssh_name(key));
   break;
  }
 }
 if ((ret = sshbuf_dup_string(b)) == 
                                    ((void *)0)
                                        )
  sshfatal("sshd.c", __func__, 660, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_dup_string failed");
 sshbuf_free(b);
 sshlog("sshd.c", __func__, 662, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "%s", ret);
 return ret;
}

static struct sshkey *
get_hostkey_by_type(int type, int nid, int need_private, struct ssh *ssh)
{
 u_int i;
 struct sshkey *key;

 for (i = 0; i < options.num_host_key_files; i++) {
  switch (type) {
  case KEY_RSA_CERT:
  case KEY_DSA_CERT:
  case KEY_ECDSA_CERT:
  case KEY_ED25519_CERT:
  case KEY_ECDSA_SK_CERT:
  case KEY_ED25519_SK_CERT:
  case KEY_XMSS_CERT:
   key = sensitive_data.host_certificates[i];
   break;
  default:
   key = sensitive_data.host_keys[i];
   if (key == 
             ((void *)0) 
                  && !need_private)
    key = sensitive_data.host_pubkeys[i];
   break;
  }
  if (key == 
            ((void *)0) 
                 || key->type != type)
   continue;
  switch (type) {
  case KEY_ECDSA:
  case KEY_ECDSA_SK:
  case KEY_ECDSA_CERT:
  case KEY_ECDSA_SK_CERT:
   if (key->ecdsa_nid != nid)
    continue;

  default:
   return need_private ?
       sensitive_data.host_keys[i] : key;
  }
 }
 return 
       ((void *)0)
           ;
}

struct sshkey *
get_hostkey_public_by_type(int type, int nid, struct ssh *ssh)
{
 return get_hostkey_by_type(type, nid, 0, ssh);
}

struct sshkey *
get_hostkey_private_by_type(int type, int nid, struct ssh *ssh)
{
 return get_hostkey_by_type(type, nid, 1, ssh);
}

struct sshkey *
get_hostkey_by_index(int ind)
{
 if (ind < 0 || (u_int)ind >= options.num_host_key_files)
  return (
         ((void *)0)
             );
 return (sensitive_data.host_keys[ind]);
}

struct sshkey *
get_hostkey_public_by_index(int ind, struct ssh *ssh)
{
 if (ind < 0 || (u_int)ind >= options.num_host_key_files)
  return (
         ((void *)0)
             );
 return (sensitive_data.host_pubkeys[ind]);
}

int
get_hostkey_index(struct sshkey *key, int compare, struct ssh *ssh)
{
 u_int i;

 for (i = 0; i < options.num_host_key_files; i++) {
  if (sshkey_is_cert(key)) {
   if (key == sensitive_data.host_certificates[i] ||
       (compare && sensitive_data.host_certificates[i] &&
       sshkey_equal(key,
       sensitive_data.host_certificates[i])))
    return (i);
  } else {
   if (key == sensitive_data.host_keys[i] ||
       (compare && sensitive_data.host_keys[i] &&
       sshkey_equal(key, sensitive_data.host_keys[i])))
    return (i);
   if (key == sensitive_data.host_pubkeys[i] ||
       (compare && sensitive_data.host_pubkeys[i] &&
       sshkey_equal(key, sensitive_data.host_pubkeys[i])))
    return (i);
  }
 }
 return (-1);
}


static void
notify_hostkeys(struct ssh *ssh)
{
 struct sshbuf *buf;
 struct sshkey *key;
 u_int i, nkeys;
 int r;
 char *fp;


 if (ssh->compat & 0x20000000)
  return;

 if ((buf = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sshd.c", __func__, 776, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 for (i = nkeys = 0; i < options.num_host_key_files; i++) {
  key = get_hostkey_public_by_index(i, ssh);
  if (key == 
            ((void *)0) 
                 || key->type == KEY_UNSPEC ||
      sshkey_is_cert(key))
   continue;
  fp = sshkey_fingerprint(key, options.fingerprint_hash,
      SSH_FP_DEFAULT);
  sshlog("sshd.c", __func__, 784, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "key %d: %s %s", i, sshkey_ssh_name(key), fp);
  free(fp);
  if (nkeys == 0) {




   if ((r = sshpkt_start(ssh, 80)) != 0 ||
       (r = sshpkt_put_cstring(ssh, "hostkeys-00@openssh.com")) != 0 ||
       (r = sshpkt_put_u8(ssh, 0)) != 0)
    sshpkt_fatal(ssh, r, "%s: start request", __func__);
  }

  sshbuf_reset(buf);
  if ((r = sshkey_putb(key, buf)) != 0)
   sshfatal("sshd.c", __func__, 799, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "couldn't put hostkey %d", i);
  if ((r = sshpkt_put_stringb(ssh, buf)) != 0)
   sshpkt_fatal(ssh, r, "%s: append key", __func__);
  nkeys++;
 }
 sshlog("sshd.c", __func__, 804, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "sent %u hostkeys", nkeys);
 if (nkeys == 0)
  sshfatal("sshd.c", __func__, 806, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "no hostkeys");
 if ((r = sshpkt_send(ssh)) != 0)
  sshpkt_fatal(ssh, r, "%s: send", __func__);
 sshbuf_free(buf);
}







static int
should_drop_connection(int startups)
{
 int p, r;

 if (startups < options.max_startups_begin)
  return 0;
 if (startups >= options.max_startups)
  return 1;
 if (options.max_startups_rate == 100)
  return 1;

 p = 100 - options.max_startups_rate;
 p *= startups - options.max_startups_begin;
 p /= options.max_startups - options.max_startups_begin;
 p += options.max_startups_rate;
 r = arc4random_uniform(100);

 sshlog("sshd.c", __func__, 836, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "p %d, r %d", p, r);
 return (r < p) ? 1 : 0;
}
static int
drop_connection(int sock, int startups, int notify_pipe)
{
 char *laddr, *raddr;
 const char msg[] = "Exceeded MaxStartups\r\n";
 static time_t last_drop, first_drop;
 static u_int ndropped;
 LogLevel drop_level = SYSLOG_LEVEL_VERBOSE;
 time_t now;

 now = monotime();
 if (!should_drop_connection(startups) &&
     srclimit_check_allow(sock, notify_pipe) == 1) {
  if (last_drop != 0 &&
      startups < options.max_startups_begin - 1) {

   sshlog("sshd.c", __func__, 863, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "exited MaxStartups throttling after %s, " "%u connections dropped", fmt_timeframe(now - first_drop), ndropped)

                                                 ;
   last_drop = 0;
  }
  return 0;
 }


 if (last_drop == 0) {
  sshlog("sshd.c", __func__, 873, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "beginning MaxStartups throttling");
  drop_level = SYSLOG_LEVEL_INFO;
  first_drop = now;
  ndropped = 0;
 } else if (last_drop + (5 * 60) < now) {

  sshlog("sshd.c", __func__, 879, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "in MaxStartups throttling for %s, " "%u connections dropped", fmt_timeframe(now - first_drop), ndropped + 1)

                                                    ;
  drop_level = SYSLOG_LEVEL_INFO;
 }
 last_drop = now;
 ndropped++;

 laddr = get_local_ipaddr(sock);
 raddr = get_peer_ipaddr(sock);
 sshlog("sshd.c", __func__, 889, 0, drop_level, 
((void *)0)
, "drop connection #%d from [%s]:%d on [%s]:%d " "past MaxStartups", startups, raddr, get_peer_port(sock), laddr, get_local_port(sock))

                                 ;
 free(laddr);
 free(raddr);

 (void)write(sock, msg, sizeof(msg) - 1);
 return 1;
}

static void
usage(void)
{
 fprintf(
        stderr
              , "%s, %s\n", "OpenSSH_9.1" "p1", OpenSSL_version(
                                         0
                                         ));
 fprintf(
        stderr
              ,
"usage: sshd [-46DdeiqTt] [-C connection_spec] [-c host_cert_file]\n"
"            [-E log_file] [-f config_file] [-g login_grace_time]\n"
"            [-h host_key_file] [-o option] [-p port] [-u len]\n"
 );
 exit(1);
}

static void
send_rexec_state(int fd, struct sshbuf *conf)
{
 struct sshbuf *m = 
                   ((void *)0)
                       , *inc = 
                                ((void *)0)
                                    ;
 struct include_item *item = 
                            ((void *)0)
                                ;
 int r;

 sshlog("sshd.c", __func__, 918, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "entering fd = %d config len %zu", fd, sshbuf_len(conf))
                      ;

 if ((m = sshbuf_new()) == 
                          ((void *)0) 
                               || (inc = sshbuf_new()) == 
                                                          ((void *)0)
                                                              )
  sshfatal("sshd.c", __func__, 922, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");


 for((item) = ((&includes)->tqh_first); (item) != 
((void *)0)
; (item) = ((item)->entry.tqe_next)) {
  if ((r = sshbuf_put_cstring(inc, item->selector)) != 0 ||
      (r = sshbuf_put_cstring(inc, item->filename)) != 0 ||
      (r = sshbuf_put_stringb(inc, item->contents)) != 0)
   sshfatal("sshd.c", __func__, 929, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose includes");
 }
 if ((r = sshbuf_put_stringb(m, conf)) != 0 ||
     (r = sshbuf_put_stringb(m, inc)) != 0)
  sshfatal("sshd.c", __func__, 944, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose config");



 if (ssh_msg_send(fd, 0, m) == -1)
  sshlog("sshd.c", __func__, 949, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "ssh_msg_send failed");

 sshbuf_free(m);
 sshbuf_free(inc);

 sshlog("sshd.c", __func__, 954, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "done");
}

static void
recv_rexec_state(int fd, struct sshbuf *conf)
{
 struct sshbuf *m, *inc;
 u_char *cp, ver;
 size_t len;
 int r;
 struct include_item *item;

 sshlog("sshd.c", __func__, 966, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "entering fd = %d", fd);

 if ((m = sshbuf_new()) == 
                          ((void *)0) 
                               || (inc = sshbuf_new()) == 
                                                          ((void *)0)
                                                              )
  sshfatal("sshd.c", __func__, 969, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if (ssh_msg_recv(fd, m) == -1)
  sshfatal("sshd.c", __func__, 971, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ssh_msg_recv failed");
 if ((r = sshbuf_get_u8(m, &ver)) != 0)
  sshfatal("sshd.c", __func__, 973, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse version");
 if (ver != 0)
  sshfatal("sshd.c", __func__, 975, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "rexec version mismatch");
 if ((r = sshbuf_get_string(m, &cp, &len)) != 0 ||
     (r = sshbuf_get_stringb(m, inc)) != 0)
  sshfatal("sshd.c", __func__, 978, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse config");





 if (conf != 
            ((void *)0) 
                 && (r = sshbuf_put(conf, cp, len)))
  sshfatal("sshd.c", __func__, 985, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_put");

 while (sshbuf_len(inc) != 0) {
  item = xcalloc(1, sizeof(*item));
  if ((item->contents = sshbuf_new()) == 
                                        ((void *)0)
                                            )
   sshfatal("sshd.c", __func__, 990, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshbuf_new failed");
  if ((r = sshbuf_get_cstring(inc, &item->selector, 
                                                   ((void *)0)
                                                       )) != 0 ||
      (r = sshbuf_get_cstring(inc, &item->filename, 
                                                   ((void *)0)
                                                       )) != 0 ||
      (r = sshbuf_get_stringb(inc, item->contents)) != 0)
   sshfatal("sshd.c", __func__, 994, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse includes");
  do { (item)->entry.tqe_next = 
 ((void *)0)
 ; (item)->entry.tqe_prev = (&includes)->tqh_last; *(&includes)->tqh_last = (item); (&includes)->tqh_last = &(item)->entry.tqe_next; } while (0);
 }

 free(cp);
 sshbuf_free(m);

 sshlog("sshd.c", __func__, 1001, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "done");
}


static void
server_accept_inetd(int *sock_in, int *sock_out)
{
 if (rexeced_flag) {
  close((
       2 
       + 3));
  *sock_in = *sock_out = dup(
                            0
                                        );
 } else {
  *sock_in = dup(
                0
                            );
  *sock_out = dup(
                 1
                              );
 }





 if (stdfd_devnull(1, 1, !log_stderr) == -1)
  sshlog("sshd.c", __func__, 1021, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "stdfd_devnull failed");
 sshlog("sshd.c", __func__, 1022, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "inetd sockets after dupping: %d, %d", *sock_in, *sock_out);
}




static void
listen_on_addrs(struct listenaddr *la)
{
 int ret, listen_sock;
 struct addrinfo *ai;
 char ntop[
          1025
                    ], strport[
                               32
                                         ];

 for (ai = la->addrs; ai; ai = ai->ai_next) {
  if (ai->ai_family != 
                      2 
                              && ai->ai_family != 
                                                  10
                                                          )
   continue;
  if (num_listen_socks >= 16)
   sshfatal("sshd.c", __func__, 1039, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Too many listen sockets. " "Enlarge MAX_LISTEN_SOCKS")
                                  ;
  if ((ret = getnameinfo(ai->ai_addr, ai->ai_addrlen,
      ntop, sizeof(ntop), strport, sizeof(strport),
      
     1
                   |
                    2
                                  )) != 0) {
   sshlog("sshd.c", __func__, 1044, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "getnameinfo failed: %.100s", ssh_gai_strerror(ret))
                             ;
   continue;
  }

  listen_sock = socket(ai->ai_family, ai->ai_socktype,
      ai->ai_protocol);
  if (listen_sock == -1) {

   sshlog("sshd.c", __func__, 1053, 0, SYSLOG_LEVEL_VERBOSE, 
  ((void *)0)
  , "socket: %.100s", strerror(
  (*__errno_location ())
  ));
   continue;
  }
  if (set_nonblock(listen_sock) == -1) {
   close(listen_sock);
   continue;
  }
  if (fcntl(listen_sock, 
                        2
                               , 
                                 1
                                           ) == -1) {
   sshlog("sshd.c", __func__, 1061, 0, SYSLOG_LEVEL_VERBOSE, 
  ((void *)0)
  , "socket: CLOEXEC: %s", strerror(
  (*__errno_location ())
  ));
   close(listen_sock);
   continue;
  }

  set_reuseaddr(listen_sock);
  if (la->rdomain != 
                    ((void *)0) 
                         &&
      set_rdomain(listen_sock, la->rdomain) == -1) {
   close(listen_sock);
   continue;
  }


  if (ai->ai_family == 
                      10
                              )
   sock_set_v6only(listen_sock);

  sshlog("sshd.c", __func__, 1077, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Bind to port %s on %s.", strport, ntop);


  if (bind(listen_sock, ai->ai_addr, ai->ai_addrlen) == -1) {
   sshlog("sshd.c", __func__, 1081, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Bind to port %s on %s failed: %.200s.", strport, ntop, strerror(
  (*__errno_location ())
  ))
                                      ;
   close(listen_sock);
   continue;
  }
  listen_socks[num_listen_socks] = listen_sock;
  num_listen_socks++;


  if (listen(listen_sock, 128) == -1)
   sshfatal("sshd.c", __func__, 1091, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "listen on [%s]:%s: %.100s", ntop, strport, strerror(
  (*__errno_location ())
  ))
                                      ;
  sshlog("sshd.c", __func__, 1093, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Server listening on %s port %s%s%s.", ntop, strport, la->rdomain == 
 ((void *)0) 
 ? "" : " rdomain ", la->rdomain == 
 ((void *)0) 
 ? "" : la->rdomain)


                                             ;
 }
}

static void
server_listen(void)
{
 u_int i;


 srclimit_init(options.max_startups, options.per_source_max_startups,
     options.per_source_masklen_ipv4, options.per_source_masklen_ipv6);

 for (i = 0; i < options.num_listen_addrs; i++) {
  listen_on_addrs(&options.listen_addrs[i]);
  freeaddrinfo(options.listen_addrs[i].addrs);
  free(options.listen_addrs[i].rdomain);
  memset(&options.listen_addrs[i], 0,
      sizeof(options.listen_addrs[i]));
 }
 free(options.listen_addrs);
 options.listen_addrs = 
                       ((void *)0)
                           ;
 options.num_listen_addrs = 0;

 if (!num_listen_socks)
  sshfatal("sshd.c", __func__, 1121, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Cannot bind any address.");
}





static void
server_accept_loop(int *sock_in, int *sock_out, int *newsock, int *config_s)
{
 struct pollfd *pfd = 
                     ((void *)0)
                         ;
 int i, j, ret, npfd;
 int ostartups = -1, startups = 0, listening = 0, lameduck = 0;
 int startup_p[2] = { -1 , -1 }, *startup_pollfd;
 char c = 0;
 struct sockaddr_storage from;
 socklen_t fromlen;
 pid_t pid;
 u_char rnd[256];
 sigset_t nsigset, osigset;


 startup_pipes = xcalloc(options.max_startups, sizeof(int));
 startup_flags = xcalloc(options.max_startups, sizeof(int));
 startup_pollfd = xcalloc(options.max_startups, sizeof(int));
 for (i = 0; i < options.max_startups; i++)
  startup_pipes[i] = -1;







 sigemptyset(&nsigset);
 sigaddset(&nsigset, 
                    1
                          );
 sigaddset(&nsigset, 
                    17
                           );
 sigaddset(&nsigset, 
                    15
                           );
 sigaddset(&nsigset, 
                    3
                           );


 pfd = xcalloc(num_listen_socks + options.max_startups,
     sizeof(struct pollfd));





 for (;;) {
  sigprocmask(
             0
                      , &nsigset, &osigset);
  if (received_sigterm) {
   sshlog("sshd.c", __func__, 1172, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Received signal %d; terminating.", (int) received_sigterm)
                              ;
   close_listen_socks();
   if (options.pid_file != 
                          ((void *)0)
                              )
    unlink(options.pid_file);
   exit(received_sigterm == 
                           15 
                                   ? 0 : 255);
  }
  if (ostartups != startups) {
   setproctitle("%s [listener] %d of %d-%d startups",
       listener_proctitle, startups,
       options.max_startups_begin, options.max_startups);
   ostartups = startups;
  }
  if (received_sighup) {
   if (!lameduck) {
    sshlog("sshd.c", __func__, 1187, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "Received SIGHUP; waiting for children");
    close_listen_socks();
    lameduck = 1;
   }
   if (listening <= 0) {
    sigprocmask(
               2
                          , &osigset, 
                                      ((void *)0)
                                          );
    sighup_restart();
   }
  }

  for (i = 0; i < num_listen_socks; i++) {
   pfd[i].fd = listen_socks[i];
   pfd[i].events = 
                  0x001
                        ;
  }
  npfd = num_listen_socks;
  for (i = 0; i < options.max_startups; i++) {
   startup_pollfd[i] = -1;
   if (startup_pipes[i] != -1) {
    pfd[npfd].fd = startup_pipes[i];
    pfd[npfd].events = 
                      0x001
                            ;
    startup_pollfd[i] = npfd++;
   }
  }


  ret = ppoll(pfd, npfd, 
                        ((void *)0)
                            , &osigset);
  if (ret == -1 && 
                  (*__errno_location ()) 
                        != 
                           4
                                ) {
   sshlog("sshd.c", __func__, 1214, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "ppoll: %.100s", strerror(
  (*__errno_location ())
  ));
   if (
      (*__errno_location ()) 
            == 
               22
                     )
    cleanup_exit(1);
  }
  sigprocmask(
             2
                        , &osigset, 
                                    ((void *)0)
                                        );
  if (ret == -1)
   continue;

  for (i = 0; i < options.max_startups; i++) {
   if (startup_pipes[i] == -1 ||
       startup_pollfd[i] == -1 ||
       !(pfd[startup_pollfd[i]].revents & (
                                          0x001
                                                |
                                                 0x010
                                                        )))
    continue;
   switch (read(startup_pipes[i], &c, sizeof(c))) {
   case -1:
    if (
       (*__errno_location ()) 
             == 
                4 
                      || 
                         (*__errno_location ()) 
                               == 
                                  11
                                        )
     continue;
    if (
       (*__errno_location ()) 
             != 
                32
                     ) {
     sshlog("sshd.c", __func__, 1232, 1, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "startup pipe %d (fd=%d): " "read %s", i, startup_pipes[i], strerror(
    (*__errno_location ())
    ))

                         ;
    }

   case 0:

    close(startup_pipes[i]);
    srclimit_done(startup_pipes[i]);
    startup_pipes[i] = -1;
    startups--;
    if (startup_flags[i])
     listening--;
    break;
   case 1:

    if (startup_flags[i]) {
     listening--;
     startup_flags[i] = 0;
    }
    break;
   }
  }
  for (i = 0; i < num_listen_socks; i++) {
   if (!(pfd[i].revents & 
                         0x001
                               ))
    continue;
   fromlen = sizeof(from);
   *newsock = accept(listen_socks[i],
       (struct sockaddr *)&from, &fromlen);
   if (*newsock == -1) {
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
                             && 
                                (*__errno_location ()) 
                                      != 
                                         11
                                               )
     sshlog("sshd.c", __func__, 1264, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "accept: %.100s", strerror(
    (*__errno_location ())
    ))
                         ;
    if (
       (*__errno_location ()) 
             == 
                24 
                       || 
                          (*__errno_location ()) 
                                == 
                                   23
                                         )
     usleep(100 * 1000);
    continue;
   }
   if (unset_nonblock(*newsock) == -1) {
    close(*newsock);
    continue;
   }
   if (pipe(startup_p) == -1) {
    sshlog("sshd.c", __func__, 1275, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "pipe(startup_p): %s", strerror(
   (*__errno_location ())
   ));
    close(*newsock);
    continue;
   }
   if (drop_connection(*newsock, startups, startup_p[0])) {
    close(*newsock);
    close(startup_p[0]);
    close(startup_p[1]);
    continue;
   }

   if (rexec_flag && socketpair(
                               1
                                      ,
       
      SOCK_STREAM
                 , 0, config_s) == -1) {
    sshlog("sshd.c", __func__, 1288, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "reexec socketpair: %s", strerror(
   (*__errno_location ())
   ))
                        ;
    close(*newsock);
    close(startup_p[0]);
    close(startup_p[1]);
    continue;
   }

   for (j = 0; j < options.max_startups; j++)
    if (startup_pipes[j] == -1) {
     startup_pipes[j] = startup_p[0];
     startups++;
     startup_flags[j] = 1;
     break;
    }





   if (debug_flag) {





    sshlog("sshd.c", __func__, 1314, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "Server will not fork when running in debugging mode.");
    close_listen_socks();
    *sock_in = *newsock;
    *sock_out = *newsock;
    close(startup_p[0]);
    close(startup_p[1]);
    startup_pipe = -1;
    pid = getpid();
    if (rexec_flag) {
     send_rexec_state(config_s[0], cfg);
     close(config_s[0]);
    }
    free(pfd);
    return;
   }






   platform_pre_fork();
   listening++;
   if ((pid = fork()) == 0) {
    platform_post_fork_child();
    startup_pipe = startup_p[1];
    close_startup_pipes();
    close_listen_socks();
    *sock_in = *newsock;
    *sock_out = *newsock;
    log_init(__progname,
        options.log_level,
        options.log_facility,
        log_stderr);
    if (rexec_flag)
     close(config_s[0]);
    else {







     (void)atomicio((ssize_t (*)(int, void *, size_t))write, startup_pipe,
         "\0", 1);
    }
    free(pfd);
    return;
   }


   platform_post_fork_parent(pid);
   if (pid == -1)
    sshlog("sshd.c", __func__, 1376, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "fork: %.100s", strerror(
   (*__errno_location ())
   ));
   else
    sshlog("sshd.c", __func__, 1378, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "Forked child %ld.", (long)pid);

   close(startup_p[1]);

   if (rexec_flag) {
    close(config_s[1]);
    send_rexec_state(config_s[0], cfg);
    close(config_s[0]);
   }
   close(*newsock);





   ;
   arc4random_buf(rnd, sizeof(rnd));

   RAND_seed(rnd, sizeof(rnd));
   if ((RAND_bytes((u_char *)rnd, 1)) != 1)
    sshfatal("sshd.c", __func__, 1398, 0, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "%s: RAND_bytes failed", __func__);

   explicit_bzero(rnd, sizeof(rnd));
  }
 }
}
static void
check_ip_options(struct ssh *ssh)
{

 int sock_in = ssh_packet_get_connection_in(ssh);
 struct sockaddr_storage from;
 u_char opts[200];
 socklen_t i, option_size = sizeof(opts), fromlen = sizeof(from);
 char text[sizeof(opts) * 3 + 1];

 memset(&from, 0, sizeof(from));
 if (getpeername(sock_in, (struct sockaddr *)&from,
     &fromlen) == -1)
  return;
 if (from.ss_family != 
                      2
                             )
  return;


 if (getsockopt(sock_in, 
                        IPPROTO_IP
                                  , 
                                    4
                                              , opts,
     &option_size) >= 0 && option_size != 0) {
  text[0] = '\0';
  for (i = 0; i < option_size; i++)
   snprintf(text + i*3, sizeof(text) - i*3,
       " %2.2x", opts[i]);
  sshfatal("sshd.c", __func__, 1440, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Connection from %.100s port %d with IP opts: %.800s", ssh_remote_ipaddr(ssh), ssh_remote_port(ssh), text)
                                                         ;
 }
 return;

}


static void
set_process_rdomain(struct ssh *ssh, const char *name)
{
 sshfatal("sshd.c", __func__, 1483, 0, SYSLOG_LEVEL_FATAL, 
((void *)0)
, "Unable to set routing domain: not supported in this platform");

}

static void
accumulate_host_timing_secret(struct sshbuf *server_cfg,
    struct sshkey *key)
{
 static struct ssh_digest_ctx *ctx;
 u_char *hash;
 size_t len;
 struct sshbuf *buf;
 int r;

 if (ctx == 
           ((void *)0) 
                && (ctx = ssh_digest_start(4)) == 
                                                                  ((void *)0)
                                                                      )
  sshfatal("sshd.c", __func__, 1498, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ssh_digest_start");
 if (key == 
           ((void *)0)
               ) {

  if (ssh_digest_update(ctx, sshbuf_ptr(server_cfg),
      sshbuf_len(server_cfg)) != 0)
   sshfatal("sshd.c", __func__, 1503, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "ssh_digest_update");
  len = ssh_digest_bytes(4);
  hash = xmalloc(len);
  if (ssh_digest_final(ctx, hash, len) != 0)
   sshfatal("sshd.c", __func__, 1507, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "ssh_digest_final");
  options.timing_secret = (((u_int64_t)(((const u_char *)(hash))[0]) << 56) | ((u_int64_t)(((const u_char *)(hash))[1]) << 48) | ((u_int64_t)(((const u_char *)(hash))[2]) << 40) | ((u_int64_t)(((const u_char *)(hash))[3]) << 32) | ((u_int64_t)(((const u_char *)(hash))[4]) << 24) | ((u_int64_t)(((const u_char *)(hash))[5]) << 16) | ((u_int64_t)(((const u_char *)(hash))[6]) << 8) | (u_int64_t)(((const u_char *)(hash))[7]));
  freezero(hash, len);
  ssh_digest_free(ctx);
  ctx = 
       ((void *)0)
           ;
  return;
 }
 if ((buf = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sshd.c", __func__, 1515, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "could not allocate buffer");
 if ((r = sshkey_private_serialize(key, buf)) != 0)
  sshfatal("sshd.c", __func__, 1517, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "decode key");
 if (ssh_digest_update(ctx, sshbuf_ptr(buf), sshbuf_len(buf)) != 0)
  sshfatal("sshd.c", __func__, 1519, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ssh_digest_update");
 sshbuf_reset(buf);
 sshbuf_free(buf);
}

static char *
prepare_proctitle(int ac, char **av)
{
 char *ret = 
            ((void *)0)
                ;
 int i;

 for (i = 0; i < ac; i++)
  xextendf(&ret, " ", "%s", av[i]);
 return ret;
}




int
main(int ac, char **av)
{
 struct ssh *ssh = 
                  ((void *)0)
                      ;
 extern char *BSDoptarg;
 extern int BSDoptind;
 int r, opt, on = 1, already_daemon, remote_port;
 int sock_in = -1, sock_out = -1, newsock = -1;
 const char *remote_ip, *rdomain;
 char *fp, *line, *laddr, *logfile = 
                                    ((void *)0)
                                        ;
 int config_s[2] = { -1 , -1 };
 u_int i, j;
 u_int64_t ibytes, obytes;
 mode_t new_umask;
 struct sshkey *key;
 struct sshkey *pubkey;
 int keytype;
 Authctxt *authctxt;
 struct connection_info *connection_info = 
                                          ((void *)0)
                                              ;




 __progname = ssh_get_progname(av[0]);


 saved_argc = ac;
 rexec_argc = ac;
 saved_argv = xcalloc(ac + 1, sizeof(*saved_argv));
 for (i = 0; (int)i < ac; i++)
  saved_argv[i] = xstrdup(av[i]);
 saved_argv[i] = 
                ((void *)0)
                    ;



 compat_init_setproctitle(ac, av);
 av = saved_argv;


 if (geteuid() == 0 && setgroups(0, 
                                   ((void *)0)
                                       ) == -1)
  sshlog("sshd.c", __func__, 1578, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "setgroups(): %.200s", strerror(
 (*__errno_location ())
 ));


 sanitise_stdfd();

 seed_rng();


 initialize_server_options(&options);


 while ((opt = BSDgetopt(ac, av, "C:E:b:c:f:g:h:k:o:p:u:46DQRTdeiqrt")
                                          ) != -1) {
  switch (opt) {
  case '4':
   options.address_family = 
                           2
                                  ;
   break;
  case '6':
   options.address_family = 
                           10
                                   ;
   break;
  case 'f':
   config_file_name = BSDoptarg;
   break;
  case 'c':
   servconf_add_hostcert("[command-line]", 0,
       &options, BSDoptarg);
   break;
  case 'd':
   if (debug_flag == 0) {
    debug_flag = 1;
    options.log_level = SYSLOG_LEVEL_DEBUG1;
   } else if (options.log_level < SYSLOG_LEVEL_DEBUG3)
    options.log_level++;
   break;
  case 'D':
   no_daemon_flag = 1;
   break;
  case 'E':
   logfile = BSDoptarg;

  case 'e':
   log_stderr = 1;
   break;
  case 'i':
   inetd_flag = 1;
   break;
  case 'r':
   rexec_flag = 0;
   break;
  case 'R':
   rexeced_flag = 1;
   inetd_flag = 1;
   break;
  case 'Q':

   break;
  case 'q':
   options.log_level = SYSLOG_LEVEL_QUIET;
   break;
  case 'b':

   break;
  case 'p':
   options.ports_from_cmdline = 1;
   if (options.num_ports >= 256) {
    fprintf(
           stderr
                 , "too many ports.\n");
    exit(1);
   }
   options.ports[options.num_ports++] = a2port(BSDoptarg);
   if (options.ports[options.num_ports-1] <= 0) {
    fprintf(
           stderr
                 , "Bad port number.\n");
    exit(1);
   }
   break;
  case 'g':
   if ((options.login_grace_time = convtime(BSDoptarg)) == -1) {
    fprintf(
           stderr
                 , "Invalid login grace time.\n");
    exit(1);
   }
   break;
  case 'k':

   break;
  case 'h':
   servconf_add_hostkey("[command-line]", 0,
       &options, BSDoptarg, 1);
   break;
  case 't':
   test_flag = 1;
   break;
  case 'T':
   test_flag = 2;
   break;
  case 'C':
   connection_info = get_connection_info(ssh, 0, 0);
   if (parse_server_match_testspec(connection_info,
       BSDoptarg) == -1)
    exit(1);
   break;
  case 'u':
   utmp_len = (u_int)strtonum(BSDoptarg, 0, 
                                        64
                                                     +1+1, 
                                                           ((void *)0)
                                                               );
   if (utmp_len > 
                 64
                              +1) {
    fprintf(
           stderr
                 , "Invalid utmp length.\n");
    exit(1);
   }
   break;
  case 'o':
   line = xstrdup(BSDoptarg);
   if (process_server_config_line(&options, line,
       "command-line", 0, 
                         ((void *)0)
                             , 
                               ((void *)0)
                                   , &includes) != 0)
    exit(1);
   free(line);
   break;
  case '?':
  default:
   usage();
   break;
  }
 }
 if (rexeced_flag || inetd_flag)
  rexec_flag = 0;
 if (!test_flag && rexec_flag && !path_absolute(av[0]))
  sshfatal("sshd.c", __func__, 1700, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshd re-exec requires execution with an absolute path");
 if (rexeced_flag)
  closefrom((
           2 
           + 4));
 else
  closefrom((
           2 
           + 1));


 if (logfile != 
               ((void *)0)
                   )
  log_redirect_stderr_to(logfile);




 log_init(__progname,
     options.log_level == SYSLOG_LEVEL_NOT_SET ?
     SYSLOG_LEVEL_INFO : options.log_level,
     options.log_facility == SYSLOG_FACILITY_NOT_SET ?
     SYSLOG_FACILITY_AUTH : options.log_facility,
     log_stderr || !inetd_flag || debug_flag);





 if (getenv("KRB5CCNAME") != 
                            ((void *)0)
                                )
  (void) unsetenv("KRB5CCNAME");

 sensitive_data.have_ssh2_key = 0;





 if (test_flag < 2 && connection_info != 
                                        ((void *)0)
                                            )
  sshfatal("sshd.c", __func__, 1734, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Config test connection parameter (-C) provided without " "test mode (-T)")
                       ;


 if ((cfg = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("sshd.c", __func__, 1739, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 if (rexeced_flag) {
  setproctitle("%s", "[rexeced]");
  recv_rexec_state((
                  2 
                  + 3), cfg);
  if (!debug_flag) {
   startup_pipe = dup((
                     2 
                     + 2));
   close((
        2 
        + 2));




   (void)atomicio((ssize_t (*)(int, void *, size_t))write, startup_pipe, "\0", 1);
  }
 } else if (strcasecmp(config_file_name, "none") != 0)
  load_server_config(config_file_name, cfg);

 parse_server_config(&options, rexeced_flag ? "rexec" : config_file_name,
     cfg, &includes, 
                    ((void *)0)
                        , rexeced_flag);


 if (options.moduli_file != 
                           ((void *)0)
                               )
  dh_set_moduli_file(options.moduli_file);



 fill_default_server_options(&options);


 if (options.authorized_keys_command_user == 
                                            ((void *)0) 
                                                 &&
     (options.authorized_keys_command != 
                                        ((void *)0) 
                                             &&
     strcasecmp(options.authorized_keys_command, "none") != 0))
  sshfatal("sshd.c", __func__, 1770, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "AuthorizedKeysCommand set without " "AuthorizedKeysCommandUser")
                                  ;
 if (options.authorized_principals_command_user == 
                                                  ((void *)0) 
                                                       &&
     (options.authorized_principals_command != 
                                              ((void *)0) 
                                                   &&
     strcasecmp(options.authorized_principals_command, "none") != 0))
  sshfatal("sshd.c", __func__, 1775, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "AuthorizedPrincipalsCommand set without " "AuthorizedPrincipalsCommandUser")
                                        ;







 if (options.num_auth_methods != 0) {
  for (i = 0; i < options.num_auth_methods; i++) {
   if (auth2_methods_valid(options.auth_methods[i],
       1) == 0)
    break;
  }
  if (i >= options.num_auth_methods)
   sshfatal("sshd.c", __func__, 1791, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "AuthenticationMethods cannot be satisfied by " "enabled authentication methods")
                                        ;
 }


 if (BSDoptind < ac) {
  fprintf(
         stderr
               , "Extra argument %s.\n", av[BSDoptind]);
  exit(1);
 }

 sshlog("sshd.c", __func__, 1801, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "sshd version %s, %s", "OpenSSH_9.1", OpenSSL_version(
0
));


 privsep_chroot = use_privsep && (getuid() == 0 || geteuid() == 0);
 if ((privsep_pw = getpwnam("sshd")) == 
                                                 ((void *)0)
                                                     ) {
  if (privsep_chroot || options.kerberos_authentication)
   sshfatal("sshd.c", __func__, 1807, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Privilege separation user %s does not exist", "sshd")
                        ;
 } else {
  privsep_pw = pwcopy(privsep_pw);
  freezero(privsep_pw->pw_passwd, strlen(privsep_pw->pw_passwd));
  privsep_pw->pw_passwd = xstrdup("*");
 }
 endpwent();


 sensitive_data.host_keys = xcalloc(options.num_host_key_files,
     sizeof(struct sshkey *));
 sensitive_data.host_pubkeys = xcalloc(options.num_host_key_files,
     sizeof(struct sshkey *));

 if (options.host_key_agent) {
  if (strcmp(options.host_key_agent, "SSH_AUTH_SOCK"))
   setenv("SSH_AUTH_SOCK",
       options.host_key_agent, 1);
  if ((r = ssh_get_authentication_socket(
                                        ((void *)0)
                                            )) == 0)
   have_agent = 1;
  else
   sshlog("sshd.c", __func__, 1829, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Could not connect to agent \"%s\"", options.host_key_agent)
                              ;
 }

 for (i = 0; i < options.num_host_key_files; i++) {
  int ll = options.host_key_file_userprovided[i] ?
      SYSLOG_LEVEL_ERROR : SYSLOG_LEVEL_DEBUG1;

  if (options.host_key_files[i] == 
                                  ((void *)0)
                                      )
   continue;
  if ((r = sshkey_load_private(options.host_key_files[i], "",
      &key, 
           ((void *)0)
               )) != 0 && r != -24)
   sshlog("sshd.c", __func__, 1841, 0, ll, ssh_err(r), "Unable to load host key \"%s\"", options.host_key_files[i])
                                 ;
  if (sshkey_is_sk(key) &&
      key->sk_flags & 0x01) {
   sshlog("sshd.c", __func__, 1845, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "host key %s requires user presence, ignoring", options.host_key_files[i])
                                 ;
   key->sk_flags &= ~0x01;
  }
  if (r == 0 && key != 
                      ((void *)0) 
                           &&
      (r = sshkey_shield_private(key)) != 0) {
   sshlog("sshd.c", __func__, 1851, 0, ll, ssh_err(r), "Unable to shield host key \"%s\"", options.host_key_files[i])
                                 ;
   sshkey_free(key);
   key = 
        ((void *)0)
            ;
  }
  if ((r = sshkey_load_public(options.host_key_files[i],
      &pubkey, 
              ((void *)0)
                  )) != 0 && r != -24)
   sshlog("sshd.c", __func__, 1858, 0, ll, ssh_err(r), "Unable to load host key \"%s\"", options.host_key_files[i])
                                 ;
  if (pubkey != 
               ((void *)0) 
                    && key != 
                              ((void *)0)
                                  ) {
   if (!sshkey_equal(pubkey, key)) {
    sshlog("sshd.c", __func__, 1862, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Public key for %s does not match " "private key", options.host_key_files[i])
                                                 ;
    sshkey_free(pubkey);
    pubkey = 
            ((void *)0)
                ;
   }
  }
  if (pubkey == 
               ((void *)0) 
                    && key != 
                              ((void *)0)
                                  ) {
   if ((r = sshkey_from_private(key, &pubkey)) != 0)
    sshfatal("sshd.c", __func__, 1870, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Could not demote key: \"%s\"", options.host_key_files[i])
                                  ;
  }
  if (pubkey != 
               ((void *)0) 
                    && (r = sshkey_check_rsa_length(pubkey,
      options.required_rsa_size)) != 0) {
   sshlog("sshd.c", __func__, 1875, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "Host key %s", options.host_key_files[i]);
   sshkey_free(pubkey);
   sshkey_free(key);
   continue;
  }
  sensitive_data.host_keys[i] = key;
  sensitive_data.host_pubkeys[i] = pubkey;

  if (key == 
            ((void *)0) 
                 && pubkey != 
                              ((void *)0) 
                                   && have_agent) {
   sshlog("sshd.c", __func__, 1884, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "will rely on agent for hostkey %s", options.host_key_files[i])
                                 ;
   keytype = pubkey->type;
  } else if (key != 
                   ((void *)0)
                       ) {
   keytype = key->type;
   accumulate_host_timing_secret(cfg, key);
  } else {
   sshlog("sshd.c", __func__, 1891, 0, ll, 
  ((void *)0)
  , "Unable to load host key: %s", options.host_key_files[i])
                                 ;
   sensitive_data.host_keys[i] = 
                                ((void *)0)
                                    ;
   sensitive_data.host_pubkeys[i] = 
                                   ((void *)0)
                                       ;
   continue;
  }

  switch (keytype) {
  case KEY_RSA:
  case KEY_DSA:
  case KEY_ECDSA:
  case KEY_ED25519:
  case KEY_ECDSA_SK:
  case KEY_ED25519_SK:
  case KEY_XMSS:
   if (have_agent || key != 
                           ((void *)0)
                               )
    sensitive_data.have_ssh2_key = 1;
   break;
  }
  if ((fp = sshkey_fingerprint(pubkey, options.fingerprint_hash,
      SSH_FP_DEFAULT)) == 
                         ((void *)0)
                             )
   sshfatal("sshd.c", __func__, 1912, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshkey_fingerprint failed");
  sshlog("sshd.c", __func__, 1913, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%s host key #%d: %s %s", key ? "private" : "agent", i, sshkey_ssh_name(pubkey), fp)
                                                                ;
  free(fp);
 }
 accumulate_host_timing_secret(cfg, 
                                   ((void *)0)
                                       );
 if (!sensitive_data.have_ssh2_key) {
  sshlog("sshd.c", __func__, 1919, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "sshd: no hostkeys available -- exiting.");
  exit(1);
 }





 sensitive_data.host_certificates = xcalloc(options.num_host_key_files,
     sizeof(struct sshkey *));
 for (i = 0; i < options.num_host_key_files; i++)
  sensitive_data.host_certificates[i] = 
                                       ((void *)0)
                                           ;

 for (i = 0; i < options.num_host_cert_files; i++) {
  if (options.host_cert_files[i] == 
                                   ((void *)0)
                                       )
   continue;
  if ((r = sshkey_load_public(options.host_cert_files[i],
      &key, 
           ((void *)0)
               )) != 0) {
   sshlog("sshd.c", __func__, 1937, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Could not load host certificate \"%s\"", options.host_cert_files[i])
                                  ;
   continue;
  }
  if (!sshkey_is_cert(key)) {
   sshlog("sshd.c", __func__, 1942, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Certificate file is not a certificate: %s", options.host_cert_files[i])
                                  ;
   sshkey_free(key);
   continue;
  }

  for (j = 0; j < options.num_host_key_files; j++) {
   if (sshkey_equal_public(key,
       sensitive_data.host_pubkeys[j])) {
    sensitive_data.host_certificates[j] = key;
    break;
   }
  }
  if (j >= options.num_host_key_files) {
   sshlog("sshd.c", __func__, 1956, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "No matching private key for certificate: %s", options.host_cert_files[i])
                                  ;
   sshkey_free(key);
   continue;
  }
  sensitive_data.host_certificates[j] = key;
  sshlog("sshd.c", __func__, 1962, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "host certificate: #%u type %d %s", j, key->type, sshkey_type(key))
                       ;
 }

 if (privsep_chroot) {
  struct stat st;

  if ((stat("/var/empty", &st) == -1) ||
      (
      ((((
      st.st_mode
      )) & 0170000) == (0040000)) 
                          == 0))
   sshfatal("sshd.c", __func__, 1971, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Missing privilege separation directory: %s", "/var/empty")
                                ;






  if (st.st_uid != 0 || (st.st_mode & (
                                      (0200 >> 3)
                                             |
                                              ((0200 >> 3) >> 3)
                                                     )) != 0)

   sshfatal("sshd.c", __func__, 1981, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s must be owned by root and not group or " "world-writable.", "/var/empty")
                                                   ;
 }

 if (test_flag > 1) {




  if (connection_info == 
                        ((void *)0)
                            )
   connection_info = get_connection_info(ssh, 0, 0);
  connection_info->test = 1;
  parse_server_match_config(&options, &includes, connection_info);
  dump_config(&options);
 }


 if (test_flag)
  exit(0);
 if (setgroups(0, 
                 ((void *)0)
                     ) < 0)
  sshlog("sshd.c", __func__, 2009, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "setgroups() failed: %.200s", strerror(
 (*__errno_location ())
 ));

 if (rexec_flag) {
  if (rexec_argc < 0)
   sshfatal("sshd.c", __func__, 2013, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "rexec_argc %d < 0", rexec_argc);
  rexec_argv = xcalloc(rexec_argc + 2, sizeof(char *));
  for (i = 0; i < (u_int)rexec_argc; i++) {
   sshlog("sshd.c", __func__, 2016, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "rexec_argv[%d]='%s'", i, saved_argv[i]);
   rexec_argv[i] = saved_argv[i];
  }
  rexec_argv[rexec_argc] = "-R";
  rexec_argv[rexec_argc + 1] = 
                              ((void *)0)
                                  ;
 }
 listener_proctitle = prepare_proctitle(ac, av);


 new_umask = umask(0077) | 0022;
 (void) umask(new_umask);


 if (debug_flag && (!inetd_flag || rexeced_flag))
  log_stderr = 1;
 log_init(__progname, options.log_level,
     options.log_facility, log_stderr);
 for (i = 0; i < options.num_log_verbose; i++)
  log_verbose_add(options.log_verbose[i]);






 already_daemon = daemonized();
 if (!(debug_flag || inetd_flag || no_daemon_flag || already_daemon)) {

  if (daemon(0, 0) == -1)
   sshfatal("sshd.c", __func__, 2045, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "daemon() failed: %.200s", strerror(
  (*__errno_location ())
  ));

  disconnect_controlling_tty();
 }

 log_init(__progname, options.log_level, options.log_facility, log_stderr);





 if (chdir("/") == -1)
  sshlog("sshd.c", __func__, 2057, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "chdir(\"/\"): %s", strerror(
 (*__errno_location ())
 ));


 ssh_signal(
           13
                  , 
                    ((__sighandler_t) 1)
                           );


 if (inetd_flag) {
  server_accept_inetd(&sock_in, &sock_out);
 } else {
  platform_pre_listen();
  server_listen();

  ssh_signal(
            1
                  , sighup_handler);
  ssh_signal(
            17
                   , main_sigchld_handler);
  ssh_signal(
            15
                   , sigterm_handler);
  ssh_signal(
            3
                   , sigterm_handler);





  if (options.pid_file != 
                         ((void *)0) 
                              && !debug_flag) {
   FILE *f = fopen(options.pid_file, "w");

   if (f == 
           ((void *)0)
               ) {
    sshlog("sshd.c", __func__, 2082, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Couldn't create pid file \"%s\": %s", options.pid_file, strerror(
   (*__errno_location ())
   ))
                                          ;
   } else {
    fprintf(f, "%ld\n", (long) getpid());
    fclose(f);
   }
  }


  server_accept_loop(&sock_in, &sock_out,
      &newsock, config_s);
 }


 setproctitle("%s", "[accepted]");






 if (!debug_flag && !inetd_flag && setsid() == -1)
  sshlog("sshd.c", __func__, 2104, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "setsid: %.100s", strerror(
 (*__errno_location ())
 ));

 if (rexec_flag) {
  sshlog("sshd.c", __func__, 2107, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "rexec start in %d out %d newsock %d pipe %d sock %d", sock_in, sock_out, newsock, startup_pipe, config_s[0])
                                                            ;
  dup2(newsock, 
               0
                           );
  dup2(
      0
                  , 
                    1
                                 );
  if (startup_pipe == -1)
   close((
        2 
        + 2));
  else if (startup_pipe != (
                          2 
                          + 2)) {
   dup2(startup_pipe, (
                     2 
                     + 2));
   close(startup_pipe);
   startup_pipe = (
                 2 
                 + 2);
  }

  dup2(config_s[1], (
                   2 
                   + 3));
  close(config_s[1]);

  ssh_signal(
            1
                  , 
                    ((__sighandler_t) 1)
                           );
  execv(rexec_argv[0], rexec_argv);


  sshlog("sshd.c", __func__, 2126, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "rexec of %s failed: %s", rexec_argv[0], strerror(
 (*__errno_location ())
 ));
  recv_rexec_state((
                  2 
                  + 3), 
                                         ((void *)0)
                                             );
  log_init(__progname, options.log_level,
      options.log_facility, log_stderr);


  close((
       2 
       + 3));
  newsock = sock_out = sock_in = dup(
                                    0
                                                );
  if (stdfd_devnull(1, 1, 0) == -1)
   sshlog("sshd.c", __func__, 2135, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "stdfd_devnull failed");
  sshlog("sshd.c", __func__, 2136, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "rexec cleanup in %d out %d newsock %d pipe %d sock %d", sock_in, sock_out, newsock, startup_pipe, config_s[0])
                                                            ;
 }


 fcntl(sock_out, 
                2
                       , 
                         1
                                   );
 fcntl(sock_in, 
               2
                      , 
                        1
                                  );


 ssh_signal(
           14
                  , 
                    ((__sighandler_t) 0)
                           );
 ssh_signal(
           1
                 , 
                   ((__sighandler_t) 0)
                          );
 ssh_signal(
           15
                  , 
                    ((__sighandler_t) 0)
                           );
 ssh_signal(
           3
                  , 
                    ((__sighandler_t) 0)
                           );
 ssh_signal(
           17
                  , 
                    ((__sighandler_t) 0)
                           );
 ssh_signal(
           2
                 , 
                   ((__sighandler_t) 0)
                          );





 if ((ssh = ssh_packet_set_connection(
                                     ((void *)0)
                                         , sock_in, sock_out)) == 
                                                                  ((void *)0)
                                                                      )
  sshfatal("sshd.c", __func__, 2157, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Unable to create connection");
 the_active_state = ssh;
 ssh_packet_set_server(ssh);

 check_ip_options(ssh);


 channel_init_channels(ssh);
 channel_set_af(ssh, options.address_family);
 process_permitopen(ssh, &options);


 if (options.tcp_keep_alive && ssh_packet_connection_is_on_socket(ssh) &&
     setsockopt(sock_in, 
                        1
                                  , 
                                    9
                                                , &on, sizeof(on)) == -1)
  sshlog("sshd.c", __func__, 2171, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "setsockopt SO_KEEPALIVE: %.100s", strerror(
 (*__errno_location ())
 ));

 if ((remote_port = ssh_remote_port(ssh)) < 0) {
  sshlog("sshd.c", __func__, 2174, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "ssh_remote_port failed");
  cleanup_exit(255);
 }

 if (options.routing_domain != 
                              ((void *)0)
                                  )
  set_process_rdomain(ssh, options.routing_domain);






 remote_ip = ssh_remote_ipaddr(ssh);





 rdomain = ssh_packet_rdomain_in(ssh);


 laddr = get_local_ipaddr(sock_in);
 sshlog("sshd.c", __func__, 2196, 0, SYSLOG_LEVEL_VERBOSE, 
((void *)0)
, "Connection from %s port %d on %s port %d%s%s%s", remote_ip, remote_port, laddr, ssh_local_port(ssh), rdomain == 
((void *)0) 
? "" : " rdomain \"", rdomain == 
((void *)0) 
? "" : rdomain, rdomain == 
((void *)0) 
? "" : "\"")



                                 ;
 free(laddr);
 ssh_signal(
           14
                  , grace_alarm_handler);
 if (!debug_flag)
  alarm(options.login_grace_time);

 if ((r = kex_exchange_identification(ssh, -1,
     options.version_addendum)) != 0)
  sshpkt_fatal(ssh, r, "banner exchange");

 ssh_packet_set_nonblocking(ssh);


 authctxt = xcalloc(1, sizeof(*authctxt));
 ssh->authctxt = authctxt;

 authctxt->loginmsg = loginmsg;


 the_authctxt = authctxt;


 if ((auth_opts = sshauthopt_new_with_keys_defaults()) == 
                                                         ((void *)0)
                                                             )
  sshfatal("sshd.c", __func__, 2232, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "allocation failed");


 if ((loginmsg = sshbuf_new()) == 
                                 ((void *)0)
                                     )
  sshfatal("sshd.c", __func__, 2236, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");
 auth_debug_reset();

 if (use_privsep) {
  if (privsep_preauth(ssh) == 1)
   goto authenticated;
 } else if (have_agent) {
  if ((r = ssh_get_authentication_socket(&auth_sock)) != 0) {
   sshlog("sshd.c", __func__, 2244, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Unable to get agent socket");
   have_agent = 0;
  }
 }



 do_ssh2_kex(ssh);
 do_authentication2(ssh);





 if (use_privsep) {
  mm_send_keystate(ssh, pmonitor);
  ssh_packet_clear_keys(ssh);
  exit(0);
 }

 authenticated:




 alarm(0);
 ssh_signal(
           14
                  , 
                    ((__sighandler_t) 0)
                           );
 authctxt->authenticated = 1;
 if (startup_pipe != -1) {
  close(startup_pipe);
  startup_pipe = -1;
 }
 if (use_privsep) {
  privsep_postauth(ssh, authctxt);

 }

 ssh_packet_set_timeout(ssh, options.client_alive_interval,
     options.client_alive_count_max);


 notify_hostkeys(ssh);


 do_authenticated(ssh, authctxt);


 ssh_packet_get_bytes(ssh, &ibytes, &obytes);
 sshlog("sshd.c", __func__, 2315, 0, SYSLOG_LEVEL_VERBOSE, 
((void *)0)
, "Transferred: sent %llu, received %llu bytes", (unsigned long long)obytes, (unsigned long long)ibytes)
                                                            ;

 sshlog("sshd.c", __func__, 2318, 0, SYSLOG_LEVEL_VERBOSE, 
((void *)0)
, "Closing connection to %.500s port %d", remote_ip, remote_port);
 ssh_packet_close(ssh);

 if (use_privsep)
  mm_terminate();

 exit(0);
}

int
sshd_hostkey_sign(struct ssh *ssh, struct sshkey *privkey,
    struct sshkey *pubkey, u_char **signature, size_t *slenp,
    const u_char *data, size_t dlen, const char *alg)
{
 int r;

 if (use_privsep) {
  if (privkey) {
   if (mm_sshkey_sign(ssh, privkey, signature, slenp,
       data, dlen, alg, options.sk_provider, 
                                            ((void *)0)
                                                ,
       ssh->compat) < 0)
    sshfatal("sshd.c", __func__, 2349, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "privkey sign failed");
  } else {
   if (mm_sshkey_sign(ssh, pubkey, signature, slenp,
       data, dlen, alg, options.sk_provider, 
                                            ((void *)0)
                                                ,
       ssh->compat) < 0)
    sshfatal("sshd.c", __func__, 2354, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "pubkey sign failed");
  }
 } else {
  if (privkey) {
   if (sshkey_sign(privkey, signature, slenp, data, dlen,
       alg, options.sk_provider, 
                                ((void *)0)
                                    , ssh->compat) < 0)
    sshfatal("sshd.c", __func__, 2360, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "privkey sign failed");
  } else {
   if ((r = ssh_agent_sign(auth_sock, pubkey,
       signature, slenp, data, dlen, alg,
       ssh->compat)) != 0) {
    sshfatal("sshd.c", __func__, 2365, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "agent sign failed");
   }
  }
 }
 return 0;
}


static void
do_ssh2_kex(struct ssh *ssh)
{
 char *myproposal[PROPOSAL_MAX] = { "sntrup761x25519-sha512@openssh.com," "curve25519-sha256," "curve25519-sha256@libssh.org," "ecdh-sha2-nistp256," "ecdh-sha2-nistp384," "ecdh-sha2-nistp521," "diffie-hellman-group-exchange-sha256," "diffie-hellman-group16-sha512," "diffie-hellman-group18-sha512," "diffie-hellman-group14-sha256", "ssh-ed25519-cert-v01@openssh.com," "ecdsa-sha2-nistp256-cert-v01@openssh.com," "ecdsa-sha2-nistp384-cert-v01@openssh.com," "ecdsa-sha2-nistp521-cert-v01@openssh.com," "sk-ssh-ed25519-cert-v01@openssh.com," "sk-ecdsa-sha2-nistp256-cert-v01@openssh.com," "rsa-sha2-512-cert-v01@openssh.com," "rsa-sha2-256-cert-v01@openssh.com," "ssh-ed25519," "ecdsa-sha2-nistp256," "ecdsa-sha2-nistp384," "ecdsa-sha2-nistp521," "sk-ssh-ed25519@openssh.com," "sk-ecdsa-sha2-nistp256@openssh.com," "rsa-sha2-512," "rsa-sha2-256", "chacha20-poly1305@openssh.com," "aes128-ctr,aes192-ctr,aes256-ctr," "aes128-gcm@openssh.com,aes256-gcm@openssh.com", "chacha20-poly1305@openssh.com," "aes128-ctr,aes192-ctr,aes256-ctr," "aes128-gcm@openssh.com,aes256-gcm@openssh.com", "umac-64-etm@openssh.com," "umac-128-etm@openssh.com," "hmac-sha2-256-etm@openssh.com," "hmac-sha2-512-etm@openssh.com," "hmac-sha1-etm@openssh.com," "umac-64@openssh.com," "umac-128@openssh.com," "hmac-sha2-256," "hmac-sha2-512," "hmac-sha1", "umac-64-etm@openssh.com," "umac-128-etm@openssh.com," "hmac-sha2-256-etm@openssh.com," "hmac-sha2-512-etm@openssh.com," "hmac-sha1-etm@openssh.com," "umac-64@openssh.com," "umac-128@openssh.com," "hmac-sha2-256," "hmac-sha2-512," "hmac-sha1", "none,zlib@openssh.com", "none,zlib@openssh.com", "", "" };
 struct kex *kex;
 char *prop_kex = 
                 ((void *)0)
                     , *prop_enc = 
                                   ((void *)0)
                                       , *prop_hostkey = 
                                                         ((void *)0)
                                                             ;
 int r;

 myproposal[PROPOSAL_KEX_ALGS] = prop_kex = compat_kex_proposal(ssh,
     options.kex_algorithms);
 myproposal[PROPOSAL_ENC_ALGS_CTOS] =
     myproposal[PROPOSAL_ENC_ALGS_STOC] = prop_enc =
     compat_cipher_proposal(ssh, options.ciphers);
 myproposal[PROPOSAL_MAC_ALGS_CTOS] =
     myproposal[PROPOSAL_MAC_ALGS_STOC] = options.macs;

 if (options.compression == 0) {
  myproposal[PROPOSAL_COMP_ALGS_CTOS] =
      myproposal[PROPOSAL_COMP_ALGS_STOC] = "none";
 }

 if (options.rekey_limit || options.rekey_interval)
  ssh_packet_set_rekey_limits(ssh, options.rekey_limit,
      options.rekey_interval);

 myproposal[PROPOSAL_SERVER_HOST_KEY_ALGS] = prop_hostkey =
    compat_pkalg_proposal(ssh, list_hostkey_types());


 if ((r = kex_setup(ssh, myproposal)) != 0)
  sshfatal("sshd.c", __func__, 2403, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "kex_setup");
 kex = ssh->kex;

 kex->kex[KEX_DH_GRP1_SHA1] = kex_gen_server;
 kex->kex[KEX_DH_GRP14_SHA1] = kex_gen_server;
 kex->kex[KEX_DH_GRP14_SHA256] = kex_gen_server;
 kex->kex[KEX_DH_GRP16_SHA512] = kex_gen_server;
 kex->kex[KEX_DH_GRP18_SHA512] = kex_gen_server;
 kex->kex[KEX_DH_GEX_SHA1] = kexgex_server;
 kex->kex[KEX_DH_GEX_SHA256] = kexgex_server;

 kex->kex[KEX_ECDH_SHA2] = kex_gen_server;


 kex->kex[KEX_C25519_SHA256] = kex_gen_server;
 kex->kex[KEX_KEM_SNTRUP761X25519_SHA512] = kex_gen_server;
 kex->load_host_public_key=&get_hostkey_public_by_type;
 kex->load_host_private_key=&get_hostkey_private_by_type;
 kex->host_key_index=&get_hostkey_index;
 kex->sign = sshd_hostkey_sign;

 ssh_dispatch_run_fatal(ssh, DISPATCH_BLOCK, &kex->done);
 free(prop_kex);
 free(prop_enc);
 free(prop_hostkey);
 sshlog("sshd.c", __func__, 2437, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "KEX done");
}


void
cleanup_exit(int i)
{
 if (the_active_state != 
                        ((void *)0) 
                             && the_authctxt != 
                                                ((void *)0)
                                                    ) {
  do_cleanup(the_active_state, the_authctxt);
  if (use_privsep && privsep_is_preauth &&
      pmonitor != 
                 ((void *)0) 
                      && pmonitor->m_pid > 1) {
   sshlog("sshd.c", __func__, 2448, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Killing privsep child %d", pmonitor->m_pid);
   if (kill(pmonitor->m_pid, 
                            9
                                   ) != 0 &&
       
      (*__errno_location ()) 
            != 
               3
                    ) {
    sshlog("sshd.c", __func__, 2451, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "kill(%d): %s", pmonitor->m_pid, strerror(
   (*__errno_location ())
   ))
                        ;
   }
  }
 }





 _exit(i);
}
