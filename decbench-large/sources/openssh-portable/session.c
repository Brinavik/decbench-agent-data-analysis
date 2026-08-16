











































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
void temporarily_use_uid(struct passwd *);
void restore_uid(void);
void permanently_set_uid(struct passwd *);
struct ssh;

void compat_banner(struct ssh *, const char *);
char *compat_cipher_proposal(struct ssh *, char *);
char *compat_pkalg_proposal(struct ssh *, char *);
char *compat_kex_proposal(struct ssh *, char *);
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
void record_login(pid_t, const char *, const char *, uid_t,
    const char *, struct sockaddr *, socklen_t);
void record_logout(pid_t, const char *, const char *);
time_t get_last_login_time(uid_t, const char *, char *, size_t);
struct ssh;

void server_loop2(struct ssh *, Authctxt *);
char *get_peer_ipaddr(int);
int get_peer_port(int);
char *get_local_ipaddr(int);
char *get_local_name(int);
int get_local_port(int);



void ipv64_normalise_mapped(struct sockaddr_storage *, socklen_t *);
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
struct passwd;

int sftp_server_main(int, char **, struct passwd *);
void sftp_server_cleanup_exit(int) __attribute__((noreturn));
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
Session *session_new(void);
void session_set_fds(struct ssh *, Session *, int, int, int, int, int);
void session_pty_cleanup(Session *);
void session_proctitle(Session *);
int session_setup_x11fwd(struct ssh *, Session *);
int do_exec_pty(struct ssh *, Session *, const char *);
int do_exec_no_pty(struct ssh *, Session *, const char *);
int do_exec(struct ssh *, Session *, const char *);
void do_login(struct ssh *, Session *, const char *);
void do_child(struct ssh *, Session *, const char *);
void do_motd(void);
int check_quietlogin(Session *, const char *);

static void do_authenticated2(struct ssh *, Authctxt *);

static int session_pty_req(struct ssh *, Session *);


extern ServerOptions options;
extern char *__progname;
extern int debug_flag;
extern u_int utmp_len;
extern int startup_pipe;
extern void destroy_sensitive_data(void);
extern struct sshbuf *loginmsg;
extern struct sshauthopt *auth_opts;
extern char *tun_fwd_ifnames;


const char *original_command = 
                              ((void *)0)
                                  ;


static int sessions_first_unused = -1;
static int sessions_nalloc = 0;
static Session *sessions = 
                          ((void *)0)
                              ;
static int is_child = 0;
static int in_chroot = 0;


static char *auth_info_file = 
                             ((void *)0)
                                 ;


static char *auth_sock_name = 
                             ((void *)0)
                                 ;
static char *auth_sock_dir = 
                            ((void *)0)
                                ;



static void
auth_sock_cleanup_proc(struct passwd *pw)
{
 if (auth_sock_name != 
                      ((void *)0)
                          ) {
  temporarily_use_uid(pw);
  unlink(auth_sock_name);
  rmdir(auth_sock_dir);
  auth_sock_name = 
                  ((void *)0)
                      ;
  restore_uid();
 }
}

static int
auth_input_request_forwarding(struct ssh *ssh, struct passwd * pw)
{
 Channel *nc;
 int sock = -1;

 if (auth_sock_name != 
                      ((void *)0)
                          ) {
  sshlog("session.c", __func__, 191, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "authentication forwarding requested twice.");
  return 0;
 }


 temporarily_use_uid(pw);


 auth_sock_dir = xstrdup("/tmp/ssh-XXXXXXXXXX");


 if (mkdtemp(auth_sock_dir) == 
                              ((void *)0)
                                  ) {
  ssh_packet_send_debug(ssh, "Agent forwarding disabled: "
      "mkdtemp() failed: %.100s", strerror(
                                          (*__errno_location ())
                                               ));
  restore_uid();
  free(auth_sock_dir);
  auth_sock_dir = 
                 ((void *)0)
                     ;
  goto authsock_err;
 }

 xasprintf(&auth_sock_name, "%s/agent.%ld",
     auth_sock_dir, (long) getpid());


 sock = unix_listener(auth_sock_name, 128, 0);


 restore_uid();


 if (sock < 0)
  goto authsock_err;


 nc = channel_new(ssh, "auth socket",
     6, sock, sock, -1,
     (4*(16*1024)), (16*1024),
     0, "auth socket", 1);
 nc->path = xstrdup(auth_sock_name);
 return 1;

 authsock_err:
 free(auth_sock_name);
 if (auth_sock_dir != 
                     ((void *)0)
                         ) {
  temporarily_use_uid(pw);
  rmdir(auth_sock_dir);
  restore_uid();
  free(auth_sock_dir);
 }
 if (sock != -1)
  close(sock);
 auth_sock_name = 
                 ((void *)0)
                     ;
 auth_sock_dir = 
                ((void *)0)
                    ;
 return 0;
}

static void
display_loginmsg(void)
{
 int r;

 if (sshbuf_len(loginmsg) == 0)
  return;
 if ((r = sshbuf_put_u8(loginmsg, 0)) != 0)
  sshfatal("session.c", __func__, 255, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_put_u8");
 printf("%s", (char *)sshbuf_ptr(loginmsg));
 sshbuf_reset(loginmsg);
}

static void
prepare_auth_info_file(struct passwd *pw, struct sshbuf *info)
{
 int fd = -1, success = 0;

 if (!options.expose_userauth_info || info == 
                                             ((void *)0)
                                                 )
  return;

 temporarily_use_uid(pw);
 auth_info_file = xstrdup("/tmp/sshauth.XXXXXXXXXXXXXXX");
 if ((fd = mkstemp(auth_info_file)) == -1) {
  sshlog("session.c", __func__, 271, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "mkstemp: %s", strerror(
 (*__errno_location ())
 ));
  goto out;
 }
 if (atomicio((ssize_t (*)(int, void *, size_t))write, fd, sshbuf_mutable_ptr(info),
     sshbuf_len(info)) != sshbuf_len(info)) {
  sshlog("session.c", __func__, 276, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "write: %s", strerror(
 (*__errno_location ())
 ));
  goto out;
 }
 if (close(fd) != 0) {
  sshlog("session.c", __func__, 280, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "close: %s", strerror(
 (*__errno_location ())
 ));
  goto out;
 }
 success = 1;
 out:
 if (!success) {
  if (fd != -1)
   close(fd);
  free(auth_info_file);
  auth_info_file = 
                  ((void *)0)
                      ;
 }
 restore_uid();
}

static void
set_fwdpermit_from_authopts(struct ssh *ssh, const struct sshauthopt *opts)
{
 char *tmp, *cp, *host;
 int port;
 size_t i;

 if ((options.allow_tcp_forwarding & (1<<1)) != 0) {
  channel_clear_permission(ssh, 0x101, (1<<1));
  for (i = 0; i < auth_opts->npermitopen; i++) {
   tmp = cp = xstrdup(auth_opts->permitopen[i]);

   if ((host = hpdelim2(&cp, 
                            ((void *)0)
                                )) == 
                                      ((void *)0)
                                          )
    sshfatal("session.c", __func__, 307, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "internal error: hpdelim");
   host = cleanhostname(host);
   if (cp == 
            ((void *)0) 
                 || (port = permitopen_port(cp)) < 0)
    sshfatal("session.c", __func__, 310, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "internal error: permitopen port");
   channel_add_permission(ssh,
       0x101, (1<<1), host, port);
   free(tmp);
  }
 }
 if ((options.allow_tcp_forwarding & (1)) != 0) {
  channel_clear_permission(ssh, 0x101, (1));
  for (i = 0; i < auth_opts->npermitlisten; i++) {
   tmp = cp = xstrdup(auth_opts->permitlisten[i]);

   if ((host = hpdelim(&cp)) == 
                               ((void *)0)
                                   )
    sshfatal("session.c", __func__, 322, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "internal error: hpdelim");
   host = cleanhostname(host);
   if (cp == 
            ((void *)0) 
                 || (port = permitopen_port(cp)) < 0)
    sshfatal("session.c", __func__, 325, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "internal error: permitlisten port");
   channel_add_permission(ssh,
       0x101, (1), host, port);
   free(tmp);
  }
 }
}

void
do_authenticated(struct ssh *ssh, Authctxt *authctxt)
{
 setproctitle("%s", authctxt->pw->pw_name);

 auth_log_authopts("active", auth_opts, 0);



 set_fwdpermit_from_authopts(ssh, auth_opts);

 if (!auth_opts->permit_port_forwarding_flag ||
     options.disable_forwarding) {
  channel_disable_admin(ssh, (1<<1));
  channel_disable_admin(ssh, (1));
 } else {
  if ((options.allow_tcp_forwarding & (1<<1)) == 0)
   channel_disable_admin(ssh, (1<<1));
  else
   channel_permit_all(ssh, (1<<1));
  if ((options.allow_tcp_forwarding & (1)) == 0)
   channel_disable_admin(ssh, (1));
  else
   channel_permit_all(ssh, (1));
 }
 auth_debug_send(ssh);

 prepare_auth_info_file(authctxt->pw, authctxt->session_info);

 do_authenticated2(ssh, authctxt);

 do_cleanup(ssh, authctxt);
}


static int
xauth_valid_string(const char *s)
{
 size_t i;

 for (i = 0; s[i] != '\0'; i++) {
  if (!
      ((*__ctype_b_loc ())[(int) ((
      (u_char)s[i]
      ))] & (unsigned short int) _ISalnum) 
                            &&
      s[i] != '.' && s[i] != ':' && s[i] != '/' &&
      s[i] != '-' && s[i] != '_')
   return 0;
 }
 return 1;
}







int
do_exec_no_pty(struct ssh *ssh, Session *s, const char *command)
{
 pid_t pid;

 int pin[2], pout[2], perr[2];

 if (s == 
         ((void *)0)
             )
  sshfatal("session.c", __func__, 396, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "do_exec_no_pty: no session");


 if (pipe(pin) == -1) {
  sshlog("session.c", __func__, 400, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "pipe in: %.100s", strerror(
 (*__errno_location ())
 ));
  return -1;
 }
 if (pipe(pout) == -1) {
  sshlog("session.c", __func__, 404, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "pipe out: %.100s", strerror(
 (*__errno_location ())
 ));
  close(pin[0]);
  close(pin[1]);
  return -1;
 }
 if (pipe(perr) == -1) {
  sshlog("session.c", __func__, 410, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "pipe err: %.100s", strerror(
 (*__errno_location ())
 ));
  close(pin[0]);
  close(pin[1]);
  close(pout[0]);
  close(pout[1]);
  return -1;
 }
 session_proctitle(s);


 switch ((pid = fork())) {
 case -1:
  sshlog("session.c", __func__, 441, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "fork: %.100s", strerror(
 (*__errno_location ())
 ));

  close(pin[0]);
  close(pin[1]);
  close(pout[0]);
  close(pout[1]);
  close(perr[0]);
  close(perr[1]);






  return -1;
 case 0:
  is_child = 1;





  if (setsid() == -1)
   sshlog("session.c", __func__, 464, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "setsid failed: %.100s", strerror(
  (*__errno_location ())
  ));






  close(pin[1]);
  if (dup2(pin[0], 0) == -1)
   perror("dup2 stdin");
  close(pin[0]);


  close(pout[0]);
  if (dup2(pout[1], 1) == -1)
   perror("dup2 stdout");
  close(pout[1]);


  close(perr[0]);
  if (dup2(perr[1], 2) == -1)
   perror("dup2 stderr");
  close(perr[1]);
  do_child(ssh, s, command);

 default:
  break;
 }





 s->pid = pid;

 ssh_packet_set_interactive(ssh, s->display != 
                                              ((void *)0)
                                                  ,
     options.ip_qos_interactive, options.ip_qos_bulk);






 sshbuf_reset(loginmsg);



 close(pin[0]);
 close(pout[1]);
 close(perr[1]);

 session_set_fds(ssh, s, pin[1], pout[0], perr[0],
     s->is_subsystem, 0);
 return 0;
}







int
do_exec_pty(struct ssh *ssh, Session *s, const char *command)
{
 int fdout, ptyfd, ttyfd, ptymaster;
 pid_t pid;

 if (s == 
         ((void *)0)
             )
  sshfatal("session.c", __func__, 564, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "do_exec_pty: no session");
 ptyfd = s->ptyfd;
 ttyfd = s->ttyfd;
 if ((fdout = dup(ptyfd)) == -1) {
  sshlog("session.c", __func__, 576, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "dup #1: %s", strerror(
 (*__errno_location ())
 ));
  close(ttyfd);
  close(ptyfd);
  return -1;
 }

 if ((ptymaster = dup(ptyfd)) == -1) {
  sshlog("session.c", __func__, 583, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "dup #2: %s", strerror(
 (*__errno_location ())
 ));
  close(ttyfd);
  close(ptyfd);
  close(fdout);
  return -1;
 }


 switch ((pid = fork())) {
 case -1:
  sshlog("session.c", __func__, 593, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "fork: %.100s", strerror(
 (*__errno_location ())
 ));
  close(fdout);
  close(ptymaster);
  close(ttyfd);
  close(ptyfd);
  return -1;
 case 0:
  is_child = 1;

  close(fdout);
  close(ptymaster);


  close(ptyfd);


  pty_make_controlling_tty(&ttyfd, s->tty);


  if (dup2(ttyfd, 0) == -1)
   sshlog("session.c", __func__, 613, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "dup2 stdin: %s", strerror(
  (*__errno_location ())
  ));
  if (dup2(ttyfd, 1) == -1)
   sshlog("session.c", __func__, 615, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "dup2 stdout: %s", strerror(
  (*__errno_location ())
  ));
  if (dup2(ttyfd, 2) == -1)
   sshlog("session.c", __func__, 617, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "dup2 stderr: %s", strerror(
  (*__errno_location ())
  ));


  close(ttyfd);



  do_login(ssh, s, command);





  do_child(ssh, s, command);

 default:
  break;
 }





 s->pid = pid;


 close(ttyfd);


 s->ptymaster = ptymaster;
 ssh_packet_set_interactive(ssh, 1,
     options.ip_qos_interactive, options.ip_qos_bulk);
 session_set_fds(ssh, s, ptyfd, fdout, -1, 1, 1);
 return 0;
}





int
do_exec(struct ssh *ssh, Session *s, const char *command)
{
 int ret;
 const char *forced = 
                     ((void *)0)
                         , *tty = 
                                  ((void *)0)
                                      ;
 char session_type[1024];

 if (options.adm_forced_command) {
  original_command = command;
  command = options.adm_forced_command;
  forced = "(config)";
 } else if (auth_opts->force_command != 
                                       ((void *)0)
                                           ) {
  original_command = command;
  command = auth_opts->force_command;
  forced = "(key-option)";
 }
 s->forced = 0;
 if (forced != 
              ((void *)0)
                  ) {
  s->forced = 1;
  if ((!strncmp(command, "internal-sftp", sizeof("internal-sftp") - 1) && (command[sizeof("internal-sftp") - 1] == '\0' || command[sizeof("internal-sftp") - 1] == ' ' || command[sizeof("internal-sftp") - 1] == '\t'))) {
   s->is_subsystem = s->is_subsystem ?
       2 : 3;
  } else if (s->is_subsystem)
   s->is_subsystem = 1;
  snprintf(session_type, sizeof(session_type),
      "forced-command %s '%.900s'", forced, command);
 } else if (s->is_subsystem) {
  snprintf(session_type, sizeof(session_type),
      "subsystem '%.900s'", s->subsys);
 } else if (command == 
                      ((void *)0)
                          ) {
  snprintf(session_type, sizeof(session_type), "shell");
 } else {

  snprintf(session_type, sizeof(session_type), "command");
 }

 if (s->ttyfd != -1) {
  tty = s->tty;
  if (strncmp(tty, "/dev/", 5) == 0)
   tty += 5;
 }

 sshlog("session.c", __func__, 699, 0, SYSLOG_LEVEL_VERBOSE, 
((void *)0)
, "Starting session: %s%s%s for %s from %.200s port %d id %d", session_type, tty == 
((void *)0) 
? "" : " on ", tty == 
((void *)0) 
? "" : tty, s->pw->pw_name, ssh_remote_ipaddr(ssh), ssh_remote_port(ssh), s->self)






             ;
 if (s->ttyfd != -1)
  ret = do_exec_pty(ssh, s, command);
 else
  ret = do_exec_no_pty(ssh, s, command);

 original_command = 
                   ((void *)0)
                       ;






 sshbuf_reset(loginmsg);

 return ret;
}


void
do_login(struct ssh *ssh, Session *s, const char *command)
{
 socklen_t fromlen;
 struct sockaddr_storage from;
 struct passwd * pw = s->pw;
 pid_t pid = getpid();





 memset(&from, 0, sizeof(from));
 fromlen = sizeof(from);
 if (ssh_packet_connection_is_on_socket(ssh)) {
  if (getpeername(ssh_packet_get_connection_in(ssh),
      (struct sockaddr *)&from, &fromlen) == -1) {
   sshlog("session.c", __func__, 754, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "getpeername: %.100s", strerror(
  (*__errno_location ())
  ));
   cleanup_exit(255);
  }
 }


 if (!use_privsep)
  record_login(pid, s->tty, pw->pw_name, pw->pw_uid,
      session_get_remote_name_or_ip(ssh, utmp_len,
      options.use_dns),
      (struct sockaddr *)&from, fromlen);
 if (check_quietlogin(s, command))
  return;

 display_loginmsg();

 do_motd();
}




void
do_motd(void)
{
 FILE *f;
 char buf[256];

 if (options.print_motd) {




  f = fopen("/etc/motd", "r");

  if (f) {
   while (fgets(buf, sizeof(buf), f))
    fputs(buf, 
              stdout
                    );
   fclose(f);
  }
 }
}





int
check_quietlogin(Session *s, const char *command)
{
 char buf[256];
 struct passwd *pw = s->pw;
 struct stat st;


 if (command != 
               ((void *)0)
                   )
  return 1;
 snprintf(buf, sizeof(buf), "%.200s/.hushlogin", pw->pw_dir);




 if (stat(buf, &st) >= 0)
  return 1;

 return 0;
}
static void
read_environment_file(char ***env, u_int *envsize,
 const char *filename, const char *allowlist)
{
 FILE *f;
 char *line = 
             ((void *)0)
                 , *cp, *value;
 size_t linesize = 0;
 u_int lineno = 0;

 f = fopen(filename, "r");
 if (!f)
  return;

 while (getline(&line, &linesize, f) != -1) {
  if (++lineno > 1000)
   sshfatal("session.c", __func__, 859, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Too many lines in environment file %s", filename);
  for (cp = line; *cp == ' ' || *cp == '\t'; cp++)
   ;
  if (!*cp || *cp == '#' || *cp == '\n')
   continue;

  cp[strcspn(cp, "\n")] = '\0';

  value = strchr(cp, '=');
  if (value == 
              ((void *)0)
                  ) {
   fprintf(
          stderr
                , "Bad line %u in %.100s\n", lineno,
       filename);
   continue;
  }




  *value = '\0';
  value++;
  if (allowlist != 
                  ((void *)0) 
                       &&
      match_pattern_list(cp, allowlist, 0) != 1)
   continue;
  child_set_env(env, envsize, cp, value);
 }
 free(line);
 fclose(f);
}
static char **
do_setup_env(struct ssh *ssh, Session *s, const char *shell)
{
 char buf[256];
 size_t n;
 u_int i, envsize;
 char *ocp, *cp, *value, **env, *laddr;
 struct passwd *pw = s->pw;

 char *path = 
             ((void *)0)
                 ;



 envsize = 100;
 env = xcalloc(envsize, sizeof(char *));
 env[0] = 
         ((void *)0)
             ;
 for (i = 0; i < s->num_env; i++)
  child_set_env(&env, &envsize, s->env[i].name, s->env[i].val);

 child_set_env(&env, &envsize, "USER", pw->pw_name);
 child_set_env(&env, &envsize, "LOGNAME", pw->pw_name);



 child_set_env(&env, &envsize, "HOME", pw->pw_dir);
 if (path == 
            ((void *)0) 
                 || *path == '\0') {
  child_set_env(&env, &envsize, "PATH",
      s->pw->pw_uid == 0 ? "/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin" : "/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin");
 }



 if (!options.use_pam) {
  snprintf(buf, sizeof buf, "%.200s/%.50s",
      
     "/var/mail"
                  , pw->pw_name);
  child_set_env(&env, &envsize, "MAIL", buf);
 }


 child_set_env(&env, &envsize, "SHELL", shell);

 if (getenv("TZ"))
  child_set_env(&env, &envsize, "TZ", getenv("TZ"));
 if (s->term)
  child_set_env(&env, &envsize, "TERM", s->term);
 if (s->display)
  child_set_env(&env, &envsize, "DISPLAY", s->display);






 {
  char *cp;

  if ((cp = getenv("KRB5CCNAME")) != 
                                    ((void *)0)
                                        )
   child_set_env(&env, &envsize, "KRB5CCNAME", cp);
 }
 if (auth_sock_name != 
                      ((void *)0)
                          )
  child_set_env(&env, &envsize, "SSH_AUTH_SOCK",
      auth_sock_name);



 if (options.permit_user_env) {
  for (n = 0 ; n < auth_opts->nenv; n++) {
   ocp = xstrdup(auth_opts->env[n]);
   cp = strchr(ocp, '=');
   if (cp != 
            ((void *)0)
                ) {
    *cp = '\0';

    if (options.permit_user_env_allowlist == 
                                            ((void *)0) 
                                                 ||
        match_pattern_list(ocp,
        options.permit_user_env_allowlist, 0) == 1)
     child_set_env(&env, &envsize,
         ocp, cp + 1);
   }
   free(ocp);
  }
 }


 if (options.permit_user_env) {
  snprintf(buf, sizeof buf, "%.200s/%s/environment",
      pw->pw_dir, ".ssh");
  read_environment_file(&env, &envsize, buf,
      options.permit_user_env_allowlist);
 }
 for (i = 0; i < options.num_setenv; i++) {
  cp = xstrdup(options.setenv[i]);
  if ((value = strchr(cp, '=')) == 
                                  ((void *)0)
                                      ) {

   sshfatal("session.c", __func__, 1158, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Invalid config SetEnv: %s", options.setenv[i]);
  }
  *value++ = '\0';
  child_set_env(&env, &envsize, cp, value);
 }


 snprintf(buf, sizeof buf, "%.50s %d %d",
     ssh_remote_ipaddr(ssh), ssh_remote_port(ssh),
     ssh_local_port(ssh));
 child_set_env(&env, &envsize, "SSH_CLIENT", buf);

 laddr = get_local_ipaddr(ssh_packet_get_connection_in(ssh));
 snprintf(buf, sizeof buf, "%.50s %d %.50s %d",
     ssh_remote_ipaddr(ssh), ssh_remote_port(ssh),
     laddr, ssh_local_port(ssh));
 free(laddr);
 child_set_env(&env, &envsize, "SSH_CONNECTION", buf);

 if (tun_fwd_ifnames != 
                       ((void *)0)
                           )
  child_set_env(&env, &envsize, "SSH_TUNNEL", tun_fwd_ifnames);
 if (auth_info_file != 
                      ((void *)0)
                          )
  child_set_env(&env, &envsize, "SSH_USER_AUTH", auth_info_file);
 if (s->ttyfd != -1)
  child_set_env(&env, &envsize, "SSH_TTY", s->tty);
 if (original_command)
  child_set_env(&env, &envsize, "SSH_ORIGINAL_COMMAND",
      original_command);

 if (debug_flag) {

  fprintf(
         stderr
               , "Environment:\n");
  for (i = 0; env[i]; i++)
   fprintf(
          stderr
                , "  %.200s\n", env[i]);
 }
 return env;
}





static void
do_rc_files(struct ssh *ssh, Session *s, const char *shell)
{
 FILE *f = 
          ((void *)0)
              ;
 char *cmd = 
            ((void *)0)
                , *user_rc = 
                             ((void *)0)
                                 ;
 int do_xauth;
 struct stat st;

 do_xauth =
     s->display != 
                  ((void *)0) 
                       && s->auth_proto != 
                                           ((void *)0) 
                                                && s->auth_data != 
                                                                   ((void *)0)
                                                                       ;
 xasprintf(&user_rc, "%s/%s", s->pw->pw_dir, ".ssh" "/rc");


 if (!s->is_subsystem && options.adm_forced_command == 
                                                      ((void *)0) 
                                                           &&
     auth_opts->permit_user_rc && options.permit_user_rc &&
     stat(user_rc, &st) >= 0) {
  if (xasprintf(&cmd, "%s -c '%s %s'", shell, 
                                             "/bin/sh"
                                                         ,
      user_rc) == -1)
   sshfatal("session.c", __func__, 1218, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "xasprintf: %s", strerror(
  (*__errno_location ())
  ));
  if (debug_flag)
   fprintf(
          stderr
                , "Running %s\n", cmd);
  f = popen(cmd, "w");
  if (f) {
   if (do_xauth)
    fprintf(f, "%s %s\n", s->auth_proto,
        s->auth_data);
   pclose(f);
  } else
   fprintf(
          stderr
                , "Could not run %s\n",
       user_rc);
 } else if (stat("/usr/local/etc" "/sshrc", &st) >= 0) {
  if (debug_flag)
   fprintf(
          stderr
                , "Running %s %s\n", 
                                     "/bin/sh"
                                                 ,
       "/usr/local/etc" "/sshrc");
  f = popen(
           "/bin/sh" 
                        " " "/usr/local/etc" "/sshrc", "w");
  if (f) {
   if (do_xauth)
    fprintf(f, "%s %s\n", s->auth_proto,
        s->auth_data);
   pclose(f);
  } else
   fprintf(
          stderr
                , "Could not run %s\n",
       "/usr/local/etc" "/sshrc");
 } else if (do_xauth && options.xauth_location != 
                                                 ((void *)0)
                                                     ) {

  if (debug_flag) {
   fprintf(
          stderr
                ,
       "Running %.500s remove %.100s\n",
       options.xauth_location, s->auth_display);
   fprintf(
          stderr
                ,
       "%.500s add %.100s %.100s %.100s\n",
       options.xauth_location, s->auth_display,
       s->auth_proto, s->auth_data);
  }
  if (xasprintf(&cmd, "%s -q -", options.xauth_location) == -1)
   sshfatal("session.c", __func__, 1255, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "xasprintf: %s", strerror(
  (*__errno_location ())
  ));
  f = popen(cmd, "w");
  if (f) {
   fprintf(f, "remove %s\n",
       s->auth_display);
   fprintf(f, "add %s %s %s\n",
       s->auth_display, s->auth_proto,
       s->auth_data);
   pclose(f);
  } else {
   fprintf(
          stderr
                , "Could not run %s\n",
       cmd);
  }
 }
 free(cmd);
 free(user_rc);
}

static void
do_nologin(struct passwd *pw)
{
 FILE *f = 
          ((void *)0)
              ;
 char buf[1024], *nl, *def_nl = 
                               "/etc/nologin"
                                            ;
 struct stat sb;






 if (pw->pw_uid == 0)
  return;
 nl = def_nl;

 if (stat(nl, &sb) == -1)
  return;


 sshlog("session.c", __func__, 1293, 0, SYSLOG_LEVEL_INFO, 
((void *)0)
, "User %.100s not allowed because %s exists", pw->pw_name, nl);
 if ((f = fopen(nl, "r")) != 
                            ((void *)0)
                                ) {
  while (fgets(buf, sizeof(buf), f))
   fputs(buf, 
             stderr
                   );
  fclose(f);
 }
 exit(254);
}





static void
safely_chroot(const char *path, uid_t uid)
{
 const char *cp;
 char component[
               4096
                       ];
 struct stat st;

 if (!path_absolute(path))
  sshfatal("session.c", __func__, 1314, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "chroot path does not begin at root");
 if (strlen(path) >= sizeof(component))
  sshfatal("session.c", __func__, 1316, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "chroot path too long");





 for (cp = path; cp != 
                      ((void *)0)
                          ;) {
  if ((cp = strchr(cp, '/')) == 
                               ((void *)0)
                                   )
   strlcpy(component, path, sizeof(component));
  else {
   cp++;
   memcpy(component, path, cp - path);
   component[cp - path] = '\0';
  }

  sshlog("session.c", __func__, 1331, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "checking '%s'", component);

  if (stat(component, &st) != 0)
   sshfatal("session.c", __func__, 1334, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "stat(\"%s\"): %s", component, strerror(
  (*__errno_location ())
  ))
                                  ;
  if (st.st_uid != 0 || (st.st_mode & 022) != 0)
   sshfatal("session.c", __func__, 1337, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "bad ownership or modes for chroot " "directory %s\"%s\"", cp == 
  ((void *)0) 
  ? "" : "component ", component)

                                                 ;
  if (!
      ((((
      st.st_mode
      )) & 0170000) == (0040000))
                         )
   sshfatal("session.c", __func__, 1341, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "chroot path %s\"%s\" is not a directory", cp == 
  ((void *)0) 
  ? "" : "component ", component)
                                                 ;

 }

 if (chdir(path) == -1)
  sshfatal("session.c", __func__, 1347, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Unable to chdir to chroot path \"%s\": " "%s", path, strerror(
 (*__errno_location ())
 ))
                                  ;
 if (chroot(path) == -1)
  sshfatal("session.c", __func__, 1350, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "chroot(\"%s\"): %s", path, strerror(
 (*__errno_location ())
 ));
 if (chdir("/") == -1)
  sshfatal("session.c", __func__, 1352, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "chdir(/) after chroot: %s", strerror(
 (*__errno_location ())
 ));
 sshlog("session.c", __func__, 1353, 0, SYSLOG_LEVEL_VERBOSE, 
((void *)0)
, "Changed root directory to \"%s\"", path);
}


void
do_setusercontext(struct passwd *pw)
{
 char uidstr[32], *chroot_path, *tmp;

 platform_setusercontext(pw);

 if (platform_privileged_uidswap()) {







  if (setlogin(pw->pw_name) < 0)
   sshlog("session.c", __func__, 1373, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "setlogin failed: %s", strerror(
  (*__errno_location ())
  ));
  if (setgid(pw->pw_gid) < 0) {
   perror("setgid");
   exit(1);
  }

  if (initgroups(pw->pw_name, pw->pw_gid) < 0) {
   perror("initgroups");
   exit(1);
  }
  endgrent();


  platform_setusercontext_post_groups(pw);

  if (!in_chroot && options.chroot_directory != 
                                               ((void *)0) 
                                                    &&
      strcasecmp(options.chroot_directory, "none") != 0) {
   tmp = tilde_expand_filename(options.chroot_directory,
       pw->pw_uid);
   snprintf(uidstr, sizeof(uidstr), "%llu",
       (unsigned long long)pw->pw_uid);
   chroot_path = percent_expand(tmp, "h", pw->pw_dir,
       "u", pw->pw_name, "U", uidstr, (char *)
                                             ((void *)0)
                                                 );
   safely_chroot(chroot_path, pw->pw_uid);
   free(tmp);
   free(chroot_path);

   free(options.chroot_directory);
   options.chroot_directory = 
                             ((void *)0)
                                 ;
   in_chroot = 1;
  }
  permanently_set_uid(pw);

 } else if (options.chroot_directory != 
                                       ((void *)0) 
                                            &&
     strcasecmp(options.chroot_directory, "none") != 0) {
  sshfatal("session.c", __func__, 1433, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "server lacks privileges to chroot to ChrootDirectory");
 }

 if (getuid() != pw->pw_uid || geteuid() != pw->pw_uid)
  sshfatal("session.c", __func__, 1437, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Failed to set uids to %u.", (u_int) pw->pw_uid);
}

static void
do_pwchange(Session *s)
{
 fflush(
       ((void *)0)
           );
 fprintf(
        stderr
              , "WARNING: Your password has expired.\n");
 if (s->ttyfd != -1) {
  fprintf(
         stderr
               ,
      "You must change your password now and login again!\n");







  execl("/usr/bin/passwd", "passwd", (char *)
                                            ((void *)0)
                                                );

  perror("passwd");
 } else {
  fprintf(
         stderr
               ,
      "Password change required but no TTY available.\n");
 }
 exit(1);
}

static void
child_close_fds(struct ssh *ssh)
{
 extern int auth_sock;

 if (auth_sock != -1) {
  close(auth_sock);
  auth_sock = -1;
 }

 if (ssh_packet_get_connection_in(ssh) ==
     ssh_packet_get_connection_out(ssh))
  close(ssh_packet_get_connection_in(ssh));
 else {
  close(ssh_packet_get_connection_in(ssh));
  close(ssh_packet_get_connection_out(ssh));
 }





 channel_close_all(ssh);





 endpwent();


 log_redirect_stderr_to(
                       ((void *)0)
                           );







 closefrom(
          2 
                        + 1);
}







void
do_child(struct ssh *ssh, Session *s, const char *command)
{
 extern char **environ;
 char **env, *argv[10], remote_id[512];
 const char *shell, *shell0;
 struct passwd *pw = s->pw;
 int r = 0;

 sshpkt_fmt_connection_id(ssh, remote_id, sizeof(remote_id));


 destroy_sensitive_data();
 ssh_packet_clear_keys(ssh);


 if (s->authctxt->force_pwchange) {
  do_setusercontext(pw);
  child_close_fds(ssh);
  do_pwchange(s);
  exit(1);
 }
 if (!options.use_pam)
  do_nologin(pw);
 do_setusercontext(pw);





 if (!check_quietlogin(s, command))
  display_loginmsg();
 shell = (pw->pw_shell[0] == '\0') ? 
                                    "/bin/sh" 
                                                 : pw->pw_shell;





 env = do_setup_env(ssh, s, shell);
 child_close_fds(ssh);





 environ = env;
 if (chdir(pw->pw_dir) == -1) {




  if (r || !in_chroot) {
   fprintf(
          stderr
                , "Could not chdir to home "
       "directory %s: %s\n", pw->pw_dir,
       strerror(
               (*__errno_location ())
                    ));
  }
  if (r)
   exit(1);
 }

 closefrom(
          2 
                        + 1);

 do_rc_files(ssh, s, shell);


 ssh_signal(
           13
                  , 
                    ((__sighandler_t) 0)
                           );

 if (s->is_subsystem == 3) {
  sshlog("session.c", __func__, 1646, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Connection from %s: refusing non-sftp session", remote_id)
                ;
  printf("This service allows sftp connections only.\n");
  fflush(
        ((void *)0)
            );
  exit(1);
 } else if (s->is_subsystem == 2) {
  extern int BSDoptind, BSDoptreset;
  int i;
  char *p, *args;

  setproctitle("%s@%s", s->pw->pw_name, "internal-sftp");
  args = xstrdup(command ? command : "sftp-server");
  for (i = 0, (p = strtok(args, " ")); p; (p = strtok(
                                                     ((void *)0)
                                                         , " ")))
   if (i < 10 - 1)
    argv[i++] = p;
  argv[i] = 
           ((void *)0)
               ;
  BSDoptind = BSDoptreset = 1;
  __progname = argv[0];



  exit(sftp_server_main(i, argv, s->pw));
 }

 fflush(
       ((void *)0)
           );


 if ((shell0 = strrchr(shell, '/')) != 
                                      ((void *)0)
                                          )
  shell0++;
 else
  shell0 = shell;






 if (!command) {
  char argv0[256];


  argv0[0] = '-';

  if (strlcpy(argv0 + 1, shell0, sizeof(argv0) - 1)
      >= sizeof(argv0) - 1) {
   
  (*__errno_location ()) 
        = 
          22
                ;
   perror(shell);
   exit(1);
  }


  argv[0] = argv0;
  argv[1] = 
           ((void *)0)
               ;
  execve(shell, argv, env);


  perror(shell);
  exit(1);
 }




 argv[0] = (char *) shell0;
 argv[1] = "-c";
 argv[2] = (char *) command;
 argv[3] = 
          ((void *)0)
              ;
 execve(shell, argv, env);
 perror(shell);
 exit(1);
}

void
session_unused(int id)
{
 sshlog("session.c", __func__, 1721, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "session id %d unused", id);
 if (id >= options.max_sessions ||
     id >= sessions_nalloc) {
  sshfatal("session.c", __func__, 1724, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "insane session id %d (max %d nalloc %d)", id, options.max_sessions, sessions_nalloc)
                                                ;
 }
 memset(&sessions[id], 0, sizeof(*sessions));
 sessions[id].self = id;
 sessions[id].used = 0;
 sessions[id].chanid = -1;
 sessions[id].ptyfd = -1;
 sessions[id].ttyfd = -1;
 sessions[id].ptymaster = -1;
 sessions[id].x11_chanids = 
                           ((void *)0)
                               ;
 sessions[id].next_unused = sessions_first_unused;
 sessions_first_unused = id;
}

Session *
session_new(void)
{
 Session *s, *tmp;

 if (sessions_first_unused == -1) {
  if (sessions_nalloc >= options.max_sessions)
   return 
         ((void *)0)
             ;
  sshlog("session.c", __func__, 1747, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "allocate (allocated %d max %d)", sessions_nalloc, options.max_sessions)
                                            ;
  tmp = xrecallocarray(sessions, sessions_nalloc,
      sessions_nalloc + 1, sizeof(*sessions));
  if (tmp == 
            ((void *)0)
                ) {
   sshlog("session.c", __func__, 1752, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "cannot allocate %d sessions", sessions_nalloc + 1)
                           ;
   return 
         ((void *)0)
             ;
  }
  sessions = tmp;
  session_unused(sessions_nalloc++);
 }

 if (sessions_first_unused >= sessions_nalloc ||
     sessions_first_unused < 0) {
  sshfatal("session.c", __func__, 1762, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "insane first_unused %d max %d nalloc %d", sessions_first_unused, options.max_sessions, sessions_nalloc)

                      ;
 }

 s = &sessions[sessions_first_unused];
 if (s->used)
  sshfatal("session.c", __func__, 1769, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "session %d already used", sessions_first_unused);
 sessions_first_unused = s->next_unused;
 s->used = 1;
 s->next_unused = -1;
 sshlog("session.c", __func__, 1773, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "session_new: session %d", s->self);

 return s;
}

static void
session_dump(void)
{
 int i;
 for (i = 0; i < sessions_nalloc; i++) {
  Session *s = &sessions[i];

  sshlog("session.c", __func__, 1785, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "dump: used %d next_unused %d session %d " "channel %d pid %ld", s->used, s->next_unused, s->self, s->chanid, (long)s->pid)





                   ;
 }
}

int
session_open(Authctxt *authctxt, int chanid)
{
 Session *s = session_new();
 sshlog("session.c", __func__, 1799, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "session_open: channel %d", chanid);
 if (s == 
         ((void *)0)
             ) {
  sshlog("session.c", __func__, 1801, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "no more sessions");
  return 0;
 }
 s->authctxt = authctxt;
 s->pw = authctxt->pw;
 if (s->pw == 
             ((void *)0) 
                  || !authctxt->valid)
  sshfatal("session.c", __func__, 1807, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "no user for session %d", s->self);
 sshlog("session.c", __func__, 1808, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "session_open: session %d: link with channel %d", s->self, chanid);
 s->chanid = chanid;
 return 1;
}

Session *
session_by_tty(char *tty)
{
 int i;
 for (i = 0; i < sessions_nalloc; i++) {
  Session *s = &sessions[i];
  if (s->used && s->ttyfd != -1 && strcmp(s->tty, tty) == 0) {
   sshlog("session.c", __func__, 1820, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "session_by_tty: session %d tty %s", i, tty);
   return s;
  }
 }
 sshlog("session.c", __func__, 1824, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "session_by_tty: unknown tty %.100s", tty);
 session_dump();
 return 
       ((void *)0)
           ;
}

static Session *
session_by_channel(int id)
{
 int i;
 for (i = 0; i < sessions_nalloc; i++) {
  Session *s = &sessions[i];
  if (s->used && s->chanid == id) {
   sshlog("session.c", __func__, 1836, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "session_by_channel: session %d channel %d", i, id)
             ;
   return s;
  }
 }
 sshlog("session.c", __func__, 1841, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "session_by_channel: unknown channel %d", id);
 session_dump();
 return 
       ((void *)0)
           ;
}

static Session *
session_by_x11_channel(int id)
{
 int i, j;

 for (i = 0; i < sessions_nalloc; i++) {
  Session *s = &sessions[i];

  if (s->x11_chanids == 
                       ((void *)0) 
                            || !s->used)
   continue;
  for (j = 0; s->x11_chanids[j] != -1; j++) {
   if (s->x11_chanids[j] == id) {
    sshlog("session.c", __func__, 1858, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "session_by_x11_channel: session %d " "channel %d", s->self, id)
                                  ;
    return s;
   }
  }
 }
 sshlog("session.c", __func__, 1864, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "session_by_x11_channel: unknown channel %d", id);
 session_dump();
 return 
       ((void *)0)
           ;
}

static Session *
session_by_pid(pid_t pid)
{
 int i;
 sshlog("session.c", __func__, 1873, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "session_by_pid: pid %ld", (long)pid);
 for (i = 0; i < sessions_nalloc; i++) {
  Session *s = &sessions[i];
  if (s->used && s->pid == pid)
   return s;
 }
 sshlog("session.c", __func__, 1879, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "session_by_pid: unknown pid %ld", (long)pid);
 session_dump();
 return 
       ((void *)0)
           ;
}

static int
session_window_change_req(struct ssh *ssh, Session *s)
{
 int r;

 if ((r = sshpkt_get_u32(ssh, &s->col)) != 0 ||
     (r = sshpkt_get_u32(ssh, &s->row)) != 0 ||
     (r = sshpkt_get_u32(ssh, &s->xpixel)) != 0 ||
     (r = sshpkt_get_u32(ssh, &s->ypixel)) != 0 ||
     (r = sshpkt_get_end(ssh)) != 0)
  sshpkt_fatal(ssh, r, "%s: parse packet", __func__);
 pty_change_window_size(s->ptyfd, s->row, s->col, s->xpixel, s->ypixel);
 return 1;
}

static int
session_pty_req(struct ssh *ssh, Session *s)
{
 int r;

 if (!auth_opts->permit_pty_flag || !options.permit_tty) {
  sshlog("session.c", __func__, 1905, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Allocating a pty not permitted for this connection.");
  return 0;
 }
 if (s->ttyfd != -1) {
  ssh_packet_disconnect(ssh, "Protocol error: you already have a pty.");
  return 0;
 }

 if ((r = sshpkt_get_cstring(ssh, &s->term, 
                                           ((void *)0)
                                               )) != 0 ||
     (r = sshpkt_get_u32(ssh, &s->col)) != 0 ||
     (r = sshpkt_get_u32(ssh, &s->row)) != 0 ||
     (r = sshpkt_get_u32(ssh, &s->xpixel)) != 0 ||
     (r = sshpkt_get_u32(ssh, &s->ypixel)) != 0)
  sshpkt_fatal(ssh, r, "%s: parse packet", __func__);

 if (strcmp(s->term, "") == 0) {
  free(s->term);
  s->term = 
           ((void *)0)
               ;
 }


 sshlog("session.c", __func__, 1926, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Allocating pty.");
 if (!(use_privsep ? mm_pty_allocate(&s->ptyfd, &s->ttyfd, s->tty, sizeof(s->tty)) : pty_allocate(&s->ptyfd, &s->ttyfd, s->tty, sizeof(s->tty)))
                     ) {
  free(s->term);
  s->term = 
           ((void *)0)
               ;
  s->ptyfd = -1;
  s->ttyfd = -1;
  sshlog("session.c", __func__, 1933, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "session_pty_req: session %d alloc failed", s->self);
  return 0;
 }
 sshlog("session.c", __func__, 1936, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "session_pty_req: session %d alloc %s", s->self, s->tty);

 ssh_tty_parse_modes(ssh, s->ttyfd);

 if ((r = sshpkt_get_end(ssh)) != 0)
  sshpkt_fatal(ssh, r, "%s: parse packet", __func__);

 if (!use_privsep)
  pty_setowner(s->pw, s->tty);


 pty_change_window_size(s->ptyfd, s->row, s->col, s->xpixel, s->ypixel);

 session_proctitle(s);
 return 1;
}

static int
session_subsystem_req(struct ssh *ssh, Session *s)
{
 struct stat st;
 int r, success = 0;
 char *prog, *cmd;
 u_int i;

 if ((r = sshpkt_get_cstring(ssh, &s->subsys, 
                                             ((void *)0)
                                                 )) != 0 ||
     (r = sshpkt_get_end(ssh)) != 0)
  sshpkt_fatal(ssh, r, "%s: parse packet", __func__);
 sshlog("session.c", __func__, 1964, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "subsystem request for %.100s by user %s", s->subsys, s->pw->pw_name)
                    ;

 for (i = 0; i < options.num_subsystems; i++) {
  if (strcmp(s->subsys, options.subsystem_name[i]) == 0) {
   prog = options.subsystem_command[i];
   cmd = options.subsystem_args[i];
   if (strcmp("internal-sftp", prog) == 0) {
    s->is_subsystem = 2;
    sshlog("session.c", __func__, 1973, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "subsystem: %s", prog);
   } else {
    if (stat(prog, &st) == -1)
     sshlog("session.c", __func__, 1976, 0, SYSLOG_LEVEL_DEBUG1, 
    ((void *)0)
    , "subsystem: cannot stat %s: %s", prog, strerror(
    (*__errno_location ())
    ))
                               ;
    s->is_subsystem = 1;
    sshlog("session.c", __func__, 1979, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "subsystem: exec() %s", cmd);
   }
   success = do_exec(ssh, s, cmd) == 0;
   break;
  }
 }

 if (!success)
  sshlog("session.c", __func__, 1987, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "subsystem request for %.100s by user %s failed, " "subsystem not found", s->subsys, s->pw->pw_name)
                                                       ;

 return success;
}

static int
session_x11_req(struct ssh *ssh, Session *s)
{
 int r, success;
 u_char single_connection = 0;

 if (s->auth_proto != 
                     ((void *)0) 
                          || s->auth_data != 
                                             ((void *)0)
                                                 ) {
  sshlog("session.c", __func__, 2000, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "session_x11_req: session %d: " "x11 forwarding already active", s->self)
                                               ;
  return 0;
 }
 if ((r = sshpkt_get_u8(ssh, &single_connection)) != 0 ||
     (r = sshpkt_get_cstring(ssh, &s->auth_proto, 
                                                 ((void *)0)
                                                     )) != 0 ||
     (r = sshpkt_get_cstring(ssh, &s->auth_data, 
                                                ((void *)0)
                                                    )) != 0 ||
     (r = sshpkt_get_u32(ssh, &s->screen)) != 0 ||
     (r = sshpkt_get_end(ssh)) != 0)
  sshpkt_fatal(ssh, r, "%s: parse packet", __func__);

 s->single_connection = single_connection;

 if (xauth_valid_string(s->auth_proto) &&
     xauth_valid_string(s->auth_data))
  success = session_setup_x11fwd(ssh, s);
 else {
  success = 0;
  sshlog("session.c", __func__, 2018, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Invalid X11 forwarding data");
 }
 if (!success) {
  free(s->auth_proto);
  free(s->auth_data);
  s->auth_proto = 
                 ((void *)0)
                     ;
  s->auth_data = 
                ((void *)0)
                    ;
 }
 return success;
}

static int
session_shell_req(struct ssh *ssh, Session *s)
{
 int r;

 if ((r = sshpkt_get_end(ssh)) != 0)
  sshpkt_fatal(ssh, r, "%s: parse packet", __func__);
 return do_exec(ssh, s, 
                       ((void *)0)
                           ) == 0;
}

static int
session_exec_req(struct ssh *ssh, Session *s)
{
 u_int success;
 int r;
 char *command = 
                ((void *)0)
                    ;

 if ((r = sshpkt_get_cstring(ssh, &command, 
                                           ((void *)0)
                                               )) != 0 ||
     (r = sshpkt_get_end(ssh)) != 0)
  sshpkt_fatal(ssh, r, "%s: parse packet", __func__);

 success = do_exec(ssh, s, command) == 0;
 free(command);
 return success;
}

static int
session_break_req(struct ssh *ssh, Session *s)
{
 int r;

 if ((r = sshpkt_get_u32(ssh, 
                             ((void *)0)
                                 )) != 0 ||
     (r = sshpkt_get_end(ssh)) != 0)
  sshpkt_fatal(ssh, r, "%s: parse packet", __func__);

 if (s->ptymaster == -1 || tcsendbreak(s->ptymaster, 0) == -1)
  return 0;
 return 1;
}

static int
session_env_req(struct ssh *ssh, Session *s)
{
 char *name, *val;
 u_int i;
 int r;

 if ((r = sshpkt_get_cstring(ssh, &name, 
                                        ((void *)0)
                                            )) != 0 ||
     (r = sshpkt_get_cstring(ssh, &val, 
                                       ((void *)0)
                                           )) != 0 ||
     (r = sshpkt_get_end(ssh)) != 0)
  sshpkt_fatal(ssh, r, "%s: parse packet", __func__);


 if (s->num_env > 128) {
  sshlog("session.c", __func__, 2083, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "Ignoring env request %s: too many env vars", name);
  goto fail;
 }

 for (i = 0; i < options.num_accept_env; i++) {
  if (match_pattern(name, options.accept_env[i])) {
   sshlog("session.c", __func__, 2089, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "Setting env %d: %s=%s", s->num_env, name, val);
   s->env = xrecallocarray(s->env, s->num_env,
       s->num_env + 1, sizeof(*s->env));
   s->env[s->num_env].name = name;
   s->env[s->num_env].val = val;
   s->num_env++;
   return (1);
  }
 }
 sshlog("session.c", __func__, 2098, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "Ignoring env request %s: disallowed name", name);

 fail:
 free(name);
 free(val);
 return (0);
}






static int
name2sig(char *name)
{

 if (strcmp(name, "HUP") == 0) return 
1
            ;
 if (strcmp(name, "INT") == 0) return 
2
            ;
 if (strcmp(name, "KILL") == 0) return 
9
             ;
 if (strcmp(name, "QUIT") == 0) return 
3
             ;
 if (strcmp(name, "TERM") == 0) return 
15
             ;
 if (strcmp(name, "USR1") == 0) return 
10
             ;
 if (strcmp(name, "USR2") == 0) return 
12
             ;





 return -1;
}

static int
session_signal_req(struct ssh *ssh, Session *s)
{
 char *signame = 
                ((void *)0)
                    ;
 int r, sig, success = 0;

 if ((r = sshpkt_get_cstring(ssh, &signame, 
                                           ((void *)0)
                                               )) != 0 ||
     (r = sshpkt_get_end(ssh)) != 0) {
  sshlog("session.c", __func__, 2138, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse");
  goto out;
 }
 if ((sig = name2sig(signame)) == -1) {
  sshlog("session.c", __func__, 2142, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unsupported signal \"%s\"", signame);
  goto out;
 }
 if (s->pid <= 0) {
  sshlog("session.c", __func__, 2146, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "no pid for session %d", s->self);
  goto out;
 }
 if (s->forced || s->is_subsystem) {
  sshlog("session.c", __func__, 2150, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "refusing to send signal %s to %s session", signame, s->forced ? "forced-command" : "subsystem")
                                                          ;
  goto out;
 }
 if (!use_privsep || mm_is_monitor()) {
  sshlog("session.c", __func__, 2155, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "session signalling requires privilege separation");
  goto out;
 }

 sshlog("session.c", __func__, 2159, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "signal %s, killpg(%ld, %d)", signame, (long)s->pid, sig);
 temporarily_use_uid(s->pw);
 r = killpg(s->pid, sig);
 restore_uid();
 if (r != 0) {
  sshlog("session.c", __func__, 2164, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "killpg(%ld, %d): %s", (long)s->pid, sig, strerror(
 (*__errno_location ())
 ))
                           ;
  goto out;
 }


 success = 1;
 out:
 free(signame);
 return success;
}

static int
session_auth_agent_req(struct ssh *ssh, Session *s)
{
 static int called = 0;
 int r;

 if ((r = sshpkt_get_end(ssh)) != 0)
  sshpkt_fatal(ssh, r, "%s: parse packet", __func__);
 if (!auth_opts->permit_agent_forwarding_flag ||
     !options.allow_agent_forwarding) {
  sshlog("session.c", __func__, 2186, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "agent forwarding disabled");
  return 0;
 }
 if (called) {
  return 0;
 } else {
  called = 1;
  return auth_input_request_forwarding(ssh, s->pw);
 }
}

int
session_input_channel_req(struct ssh *ssh, Channel *c, const char *rtype)
{
 int success = 0;
 Session *s;

 if ((s = session_by_channel(c->self)) == 
                                         ((void *)0)
                                             ) {
  sshlog("session.c", __func__, 2204, 1, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "no session %d req %.100s", c->self, rtype);
  return 0;
 }
 sshlog("session.c", __func__, 2207, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "session %d req %s", s->self, rtype);





 if (c->type == 10) {
  if (strcmp(rtype, "shell") == 0) {
   success = session_shell_req(ssh, s);
  } else if (strcmp(rtype, "exec") == 0) {
   success = session_exec_req(ssh, s);
  } else if (strcmp(rtype, "pty-req") == 0) {
   success = session_pty_req(ssh, s);
  } else if (strcmp(rtype, "x11-req") == 0) {
   success = session_x11_req(ssh, s);
  } else if (strcmp(rtype, "auth-agent-req@openssh.com") == 0) {
   success = session_auth_agent_req(ssh, s);
  } else if (strcmp(rtype, "subsystem") == 0) {
   success = session_subsystem_req(ssh, s);
  } else if (strcmp(rtype, "env") == 0) {
   success = session_env_req(ssh, s);
  }
 }
 if (strcmp(rtype, "window-change") == 0) {
  success = session_window_change_req(ssh, s);
 } else if (strcmp(rtype, "break") == 0) {
  success = session_break_req(ssh, s);
 } else if (strcmp(rtype, "signal") == 0) {
  success = session_signal_req(ssh, s);
 }

 return success;
}

void
session_set_fds(struct ssh *ssh, Session *s,
    int fdin, int fdout, int fderr, int ignore_fderr, int is_tty)
{




 if (s->chanid == -1)
  sshfatal("session.c", __func__, 2250, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "no channel for session %d", s->self);
 channel_set_fds(ssh, s->chanid,
     fdout, fdin, fderr,
     ignore_fderr ? 0 : 1,
     1, is_tty, (64*(32*1024)));
}





void
session_pty_cleanup2(Session *s)
{
 if (s == 
         ((void *)0)
             ) {
  sshlog("session.c", __func__, 2265, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "no session");
  return;
 }
 if (s->ttyfd == -1)
  return;

 sshlog("session.c", __func__, 2271, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "session %d release %s", s->self, s->tty);


 if (s->pid != 0)
  record_logout(s->pid, s->tty, s->pw->pw_name);


 if (getuid() == 0)
  pty_release(s->tty);






 if (s->ptymaster != -1 && close(s->ptymaster) == -1)
  sshlog("session.c", __func__, 2287, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "close(s->ptymaster/%d): %s", s->ptymaster, strerror(
 (*__errno_location ())
 ))
                                    ;


 s->ttyfd = -1;
}

void
session_pty_cleanup(Session *s)
{
 (use_privsep ? mm_session_pty_cleanup2(s) : session_pty_cleanup2(s));
}

static char *
sig2name(int sig)
{

 if (sig == 
6
) return "ABRT";
 if (sig == 
14
) return "ALRM";
 if (sig == 
8
) return "FPE";
 if (sig == 
1
) return "HUP";
 if (sig == 
4
) return "ILL";
 if (sig == 
2
) return "INT";
 if (sig == 
9
) return "KILL";
 if (sig == 
13
) return "PIPE";
 if (sig == 
3
) return "QUIT";
 if (sig == 
11
) return "SEGV";
 if (sig == 
15
) return "TERM";
 if (sig == 
10
) return "USR1";
 if (sig == 
12
) return "USR2";

 return "SIG@openssh.com";
}

static void
session_close_x11(struct ssh *ssh, int id)
{
 Channel *c;

 if ((c = channel_by_id(ssh, id)) == 
                                    ((void *)0)
                                        ) {
  sshlog("session.c", __func__, 2327, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "x11 channel %d missing", id);
 } else {

  sshlog("session.c", __func__, 2330, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "detach x11 channel %d", id);
  channel_cancel_cleanup(ssh, id);
  if (c->ostate != 3)
   chan_mark_dead(ssh, c);
 }
}

static void
session_close_single_x11(struct ssh *ssh, int id, void *arg)
{
 Session *s;
 u_int i;

 sshlog("session.c", __func__, 2343, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "channel %d", id);
 channel_cancel_cleanup(ssh, id);
 if ((s = session_by_x11_channel(id)) == 
                                        ((void *)0)
                                            )
  sshfatal("session.c", __func__, 2346, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "no x11 channel %d", id);
 for (i = 0; s->x11_chanids[i] != -1; i++) {
  sshlog("session.c", __func__, 2348, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "session %d: closing channel %d", s->self, s->x11_chanids[i])
                                 ;




  if (s->x11_chanids[i] != id)
   session_close_x11(ssh, s->x11_chanids[i]);
 }
 free(s->x11_chanids);
 s->x11_chanids = 
                 ((void *)0)
                     ;
 free(s->display);
 s->display = 
             ((void *)0)
                 ;
 free(s->auth_proto);
 s->auth_proto = 
                ((void *)0)
                    ;
 free(s->auth_data);
 s->auth_data = 
               ((void *)0)
                   ;
 free(s->auth_display);
 s->auth_display = 
                  ((void *)0)
                      ;
}

static void
session_exit_message(struct ssh *ssh, Session *s, int status)
{
 Channel *c;
 int r;

 if ((c = channel_lookup(ssh, s->chanid)) == 
                                            ((void *)0)
                                                )
  sshfatal("session.c", __func__, 2376, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "session %d: no channel %d", s->self, s->chanid);
 sshlog("session.c", __func__, 2377, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "session %d channel %d pid %ld", s->self, s->chanid, (long)s->pid)
                                      ;

 if (
    (((
    status
    ) & 0x7f) == 0)
                     ) {
  channel_request_start(ssh, s->chanid, "exit-status", 0);
  if ((r = sshpkt_put_u32(ssh, 
                              (((
                              status
                              ) & 0xff00) >> 8)
                                                 )) != 0 ||
      (r = sshpkt_send(ssh)) != 0)
   sshpkt_fatal(ssh, r, "%s: exit reply", __func__);
 } else if (
           (((signed char) (((
           status
           ) & 0x7f) + 1) >> 1) > 0)
                              ) {
  channel_request_start(ssh, s->chanid, "exit-signal", 0);



  if ((r = sshpkt_put_cstring(ssh, sig2name(
                                           ((
                                           status
                                           ) & 0x7f)
                                                           ))) != 0 ||
      (r = sshpkt_put_u8(ssh, 
                             ((
                             status
                             ) & 0x80)
                                              ? 1 : 0)) != 0 ||
      (r = sshpkt_put_cstring(ssh, "")) != 0 ||
      (r = sshpkt_put_cstring(ssh, "")) != 0 ||
      (r = sshpkt_send(ssh)) != 0)
   sshpkt_fatal(ssh, r, "%s: exit reply", __func__);
 } else {

  ssh_packet_disconnect(ssh, "wait returned status %04x.", status);
 }


 sshlog("session.c", __func__, 2402, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "release channel %d", s->chanid);






 channel_register_cleanup(ssh, c->self, session_close_by_channel, 1);







 if (c->ostate != 3)
  chan_write_failed(ssh, c);
}

void
session_close(struct ssh *ssh, Session *s)
{
 u_int i;

 sshlog("session.c", __func__, 2426, 0, SYSLOG_LEVEL_VERBOSE, 
((void *)0)
, "Close session: user %s from %.200s port %d id %d", s->pw->pw_name, ssh_remote_ipaddr(ssh), ssh_remote_port(ssh), s->self)



             ;

 if (s->ttyfd != -1)
  session_pty_cleanup(s);
 free(s->term);
 free(s->display);
 free(s->x11_chanids);
 free(s->auth_display);
 free(s->auth_data);
 free(s->auth_proto);
 free(s->subsys);
 if (s->env != 
              ((void *)0)
                  ) {
  for (i = 0; i < s->num_env; i++) {
   free(s->env[i].name);
   free(s->env[i].val);
  }
  free(s->env);
 }
 session_proctitle(s);
 session_unused(s->self);
}

void
session_close_by_pid(struct ssh *ssh, pid_t pid, int status)
{
 Session *s = session_by_pid(pid);
 if (s == 
         ((void *)0)
             ) {
  sshlog("session.c", __func__, 2457, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "no session for pid %ld", (long)pid);
  return;
 }
 if (s->chanid != -1)
  session_exit_message(ssh, s, status);
 if (s->ttyfd != -1)
  session_pty_cleanup(s);
 s->pid = 0;
}





void
session_close_by_channel(struct ssh *ssh, int id, void *arg)
{
 Session *s = session_by_channel(id);
 u_int i;

 if (s == 
         ((void *)0)
             ) {
  sshlog("session.c", __func__, 2478, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "no session for id %d", id);
  return;
 }
 sshlog("session.c", __func__, 2481, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "channel %d child %ld", id, (long)s->pid);
 if (s->pid != 0) {
  sshlog("session.c", __func__, 2483, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "channel %d: has child, ttyfd %d", id, s->ttyfd);




  if (s->ttyfd != -1)
   session_pty_cleanup(s);
  return;
 }

 channel_cancel_cleanup(ssh, s->chanid);


 if (s->x11_chanids != 
                      ((void *)0)
                          ) {
  for (i = 0; s->x11_chanids[i] != -1; i++) {
   session_close_x11(ssh, s->x11_chanids[i]);
   s->x11_chanids[i] = -1;
  }
 }

 s->chanid = -1;
 session_close(ssh, s);
}

void
session_destroy_all(struct ssh *ssh, void (*closefunc)(Session *))
{
 int i;
 for (i = 0; i < sessions_nalloc; i++) {
  Session *s = &sessions[i];
  if (s->used) {
   if (closefunc != 
                   ((void *)0)
                       )
    closefunc(s);
   else
    session_close(ssh, s);
  }
 }
}

static char *
session_tty_list(void)
{
 static char buf[1024];
 int i;
 char *cp;

 buf[0] = '\0';
 for (i = 0; i < sessions_nalloc; i++) {
  Session *s = &sessions[i];
  if (s->used && s->ttyfd != -1) {

   if (strncmp(s->tty, "/dev/", 5) != 0) {
    cp = strrchr(s->tty, '/');
    cp = (cp == 
               ((void *)0)
                   ) ? s->tty : cp + 1;
   } else
    cp = s->tty + 5;

   if (buf[0] != '\0')
    strlcat(buf, ",", sizeof buf);
   strlcat(buf, cp, sizeof buf);
  }
 }
 if (buf[0] == '\0')
  strlcpy(buf, "notty", sizeof buf);
 return buf;
}

void
session_proctitle(Session *s)
{
 if (s->pw == 
             ((void *)0)
                 )
  sshlog("session.c", __func__, 2554, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "no user for session %d", s->self);
 else
  setproctitle("%s@%s", s->pw->pw_name, session_tty_list());
}

int
session_setup_x11fwd(struct ssh *ssh, Session *s)
{
 struct stat st;
 char display[512], auth_display[512];
 char hostname[
              1025
                        ];
 u_int i;

 if (!auth_opts->permit_x11_forwarding_flag) {
  ssh_packet_send_debug(ssh, "X11 forwarding disabled by key options.");
  return 0;
 }
 if (!options.x11_forwarding) {
  sshlog("session.c", __func__, 2572, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "X11 forwarding disabled in server configuration file.");
  return 0;
 }
 if (options.xauth_location == 
                              ((void *)0) 
                                   ||
     (stat(options.xauth_location, &st) == -1)) {
  ssh_packet_send_debug(ssh, "No xauth program; cannot forward X11.");
  return 0;
 }
 if (s->display != 
                  ((void *)0)
                      ) {
  sshlog("session.c", __func__, 2581, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "X11 display already set.");
  return 0;
 }
 if (x11_create_display_inet(ssh, options.x11_display_offset,
     options.x11_use_localhost, s->single_connection,
     &s->display_number, &s->x11_chanids) == -1) {
  sshlog("session.c", __func__, 2587, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "x11_create_display_inet failed.");
  return 0;
 }
 for (i = 0; s->x11_chanids[i] != -1; i++) {
  channel_register_cleanup(ssh, s->x11_chanids[i],
      session_close_single_x11, 0);
 }


 if (gethostname(hostname, sizeof(hostname)) == -1)
  sshfatal("session.c", __func__, 2597, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "gethostname: %.100s", strerror(
 (*__errno_location ())
 ));





 if (options.x11_use_localhost) {
  snprintf(display, sizeof display, "localhost:%u.%u",
      s->display_number, s->screen);
  snprintf(auth_display, sizeof auth_display, "unix:%u.%u",
      s->display_number, s->screen);
  s->display = xstrdup(display);
  s->auth_display = xstrdup(auth_display);
 } else {
  snprintf(display, sizeof display, "%.400s:%u.%u", hostname,
      s->display_number, s->screen);

  s->display = xstrdup(display);
  s->auth_display = xstrdup(display);
 }

 return 1;
}

static void
do_authenticated2(struct ssh *ssh, Authctxt *authctxt)
{
 server_loop2(ssh, authctxt);
}

void
do_cleanup(struct ssh *ssh, Authctxt *authctxt)
{
 static int called = 0;

 sshlog("session.c", __func__, 2646, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "do_cleanup");


 if (is_child)
  return;


 if (called)
  return;
 called = 1;

 if (authctxt == 
                ((void *)0)
                    )
  return;
 if (!authctxt->authenticated)
  return;
 auth_sock_cleanup_proc(authctxt->pw);


 if (auth_info_file != 
                      ((void *)0)
                          ) {
  temporarily_use_uid(authctxt->pw);
  unlink(auth_info_file);
  restore_uid();
  free(auth_info_file);
  auth_info_file = 
                  ((void *)0)
                      ;
 }





 if (!use_privsep || mm_is_monitor())
  session_destroy_all(ssh, session_pty_cleanup2);
}



const char *
session_get_remote_name_or_ip(struct ssh *ssh, u_int utmp_size, int use_dns)
{
 const char *remote = "";

 if (utmp_size > 0)
  remote = auth_get_canonical_hostname(ssh, use_dns);
 if (utmp_size == 0 || strlen(remote) > utmp_size)
  remote = ssh_remote_ipaddr(ssh);
 return remote;
}
