











































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
struct allowed_cname {
 char *source_list;
 char *target_list;
};

typedef struct {
 int forward_agent;
 char *forward_agent_sock_path;
 int forward_x11;
 int forward_x11_timeout;
 int forward_x11_trusted;
 int exit_on_forward_failure;
 char *xauth_location;
 struct ForwardOptions fwd_opts;
 int pubkey_authentication;
 int hostbased_authentication;
 int gss_authentication;
 int gss_deleg_creds;
 int password_authentication;

 int kbd_interactive_authentication;
 char *kbd_interactive_devices;
 int batch_mode;
 int check_host_ip;
 int strict_host_key_checking;
 int compression;
 int tcp_keep_alive;
 int ip_qos_interactive;
 int ip_qos_bulk;
 SyslogFacility log_facility;
 LogLevel log_level;
 u_int num_log_verbose;
 char **log_verbose;
 int port;
 int address_family;
 int connection_attempts;

 int connection_timeout;

 int number_of_password_prompts;

 char *ciphers;
 char *macs;
 char *hostkeyalgorithms;
 char *kex_algorithms;
 char *ca_sign_algorithms;
 char *hostname;
 char *host_key_alias;
 char *proxy_command;
 char *user;
 int escape_char;

 u_int num_system_hostfiles;
 char *system_hostfiles[32];
 u_int num_user_hostfiles;
 char *user_hostfiles[32];
 char *preferred_authentications;
 char *bind_address;
 char *bind_interface;
 char *pkcs11_provider;
 char *sk_provider;
 int verify_host_key_dns;

 int num_identity_files;
 char *identity_files[100];
 int identity_file_userprovided[100];
 struct sshkey *identity_keys[100];

 int num_certificate_files;
 char *certificate_files[100];
 int certificate_file_userprovided[100];
 struct sshkey *certificates[100];

 int add_keys_to_agent;
 int add_keys_to_agent_lifespan;
 char *identity_agent;


 int num_local_forwards;
 struct Forward *local_forwards;


 int num_remote_forwards;
 struct Forward *remote_forwards;
 int clear_forwardings;


 char **permitted_remote_opens;
 u_int num_permitted_remote_opens;


 char *stdio_forward_host;
 int stdio_forward_port;

 int enable_ssh_keysign;
 int64_t rekey_limit;
 int rekey_interval;
 int no_host_authentication_for_localhost;
 int identities_only;
 int server_alive_interval;
 int server_alive_count_max;

 u_int num_send_env;
 char **send_env;
 u_int num_setenv;
 char **setenv;

 char *control_path;
 int control_master;
 int control_persist;
 int control_persist_timeout;

 int hash_known_hosts;

 int tun_open;
 int tun_local;
 int tun_remote;

 char *local_command;
 int permit_local_command;
 char *remote_command;
 int visual_host_key;

 int request_tty;
 int session_type;
 int stdin_null;
 int fork_after_authentication;

 int proxy_use_fdpass;

 int num_canonical_domains;
 char *canonical_domains[32];
 int canonicalize_hostname;
 int canonicalize_max_dots;
 int canonicalize_fallback_local;
 int num_permitted_cnames;
 struct allowed_cname permitted_cnames[32];

 char *revoked_host_keys;

 int fingerprint_hash;

 int update_hostkeys;

 char *hostbased_accepted_algos;
 char *pubkey_accepted_algos;

 char *jump_user;
 char *jump_host;
 int jump_port;
 char *jump_extra;

 char *known_hosts_command;

 int required_rsa_size;

 char *ignored_unknown;
} Options;
const char *kex_default_pk_alg(void);
char *ssh_connection_hash(const char *thishost, const char *host,
    const char *portstr, const char *user);
void initialize_options(Options *);
int fill_default_options(Options *);
void fill_default_options_for_canonicalization(Options *);
void free_options(Options *o);
int process_config_line(Options *, struct passwd *, const char *,
    const char *, char *, const char *, int, int *, int);
int read_config_file(const char *, struct passwd *, const char *,
    const char *, Options *, int, int *);
int parse_forward(struct Forward *, const char *, int, int);
int parse_jump(const char *, Options *, int);
int parse_ssh_uri(const char *, char **, char **, int *);
int default_ssh_port(void);
int option_clear_or_none(const char *);
int config_has_permitted_cnames(Options *);
void dump_client_config(Options *o, const char *host);

void add_local_forward(Options *, const struct Forward *);
void add_remote_forward(Options *, const struct Forward *);
void add_identity_file(Options *, const char *, const char *, int);
void add_certificate_file(Options *, const char *, int);
struct ssh;


int client_loop(struct ssh *, int, int, int);
int client_x11_get_proto(struct ssh *, const char *, const char *,
     u_int, u_int, char **, char **);
void client_global_request_reply_fwd(int, u_int32_t, void *);
void client_session2_setup(struct ssh *, int, int, int,
     const char *, struct termios *, int, struct sshbuf *, char **);
char *client_request_tun_fwd(struct ssh *, int, int, int,
    channel_open_fn *, void *);
void client_stop_mux(void);


void *client_new_escape_filter_ctx(int);
void client_filter_cleanup(struct ssh *, int, void *);
int client_simple_escape_filter(struct ssh *, Channel *, char *, int);


typedef void global_confirm_cb(struct ssh *, int, u_int32_t, void *);
void client_register_global_confirm(global_confirm_cb *, void *);


enum confirm_action { CONFIRM_WARN = 0, CONFIRM_CLOSE, CONFIRM_TTY };
void client_expect_confirm(struct ssh *, int, const char *,
    enum confirm_action);
void muxserver_listen(struct ssh *);
int muxclient(const char *);
void mux_exit_message(struct ssh *, Channel *, int);
void mux_tty_alloc_failed(struct ssh *ssh, Channel *);
typedef struct Sensitive Sensitive;
struct Sensitive {
 struct sshkey **keys;
 int nkeys;
};

struct ssh_conn_info {
 char *conn_hash_hex;
 char *shorthost;
 char *uidstr;
 char *keyalias;
 char *thishost;
 char *host_arg;
 char *portstr;
 char *remhost;
 char *remuser;
 char *homedir;
 char *locuser;
};

struct addrinfo;
struct ssh;
struct hostkeys;
struct ssh_conn_info;
int ssh_connect(struct ssh *, const char *, const char *,
     struct addrinfo *, struct sockaddr_storage *, u_short,
     int, int *, int);
void ssh_kill_proxy_command(void);

void ssh_login(struct ssh *, Sensitive *, const char *,
    struct sockaddr *, u_short, struct passwd *, int,
    const struct ssh_conn_info *);

int verify_host_key(char *, struct sockaddr *, struct sshkey *,
    const struct ssh_conn_info *);

void get_hostfile_hostname_ipaddr(char *, struct sockaddr *, u_short,
    char **, char **);

void ssh_kex2(struct ssh *ssh, char *, struct sockaddr *, u_short,
    const struct ssh_conn_info *);

void ssh_userauth2(struct ssh *ssh, const char *, const char *,
    char *, Sensitive *);

int ssh_local_cmd(const char *);

void maybe_add_key_to_agent(const char *, struct sshkey *,
    const char *, const char *);

void load_hostkeys_command(struct hostkeys *, const char *,
    const char *, const struct ssh_conn_info *,
    const struct sshkey *, const char *);
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
struct termios *get_saved_tio(void);
void leave_raw_mode(int);
void enter_raw_mode(int);

int pty_allocate(int *, int *, char *, size_t);
void pty_release(const char *);
void pty_make_controlling_tty(int *, const char *);
void pty_change_window_size(int, u_int, u_int, u_int, u_int);
void pty_setowner(struct passwd *, const char *);
void disconnect_controlling_tty(void);
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
int ssh_msg_send(int, u_char, struct sshbuf *);
int ssh_msg_recv(int, struct sshbuf *);

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





extern Options options;


extern int muxserver_sock;






extern char *host;





extern char *forward_agent_sock_path;







static volatile sig_atomic_t received_window_change_signal = 0;
static volatile sig_atomic_t received_signal = 0;


static time_t control_persist_exit_time = 0;


volatile sig_atomic_t quit_pending;
static int last_was_cr;
static int exit_status;
static struct sshbuf *stderr_buffer;
static int connection_in;
static int connection_out;
static int need_rekeying;
static int session_closed;
static u_int x11_refuse_time;
static time_t server_alive_time;

static void client_init_dispatch(struct ssh *ssh);
int session_ident = -1;


struct escape_filter_ctx {
 int escape_pending;
 int escape_char;
};


struct channel_reply_ctx {
 const char *request_type;
 int id;
 enum confirm_action action;
};



struct global_confirm {
 struct { struct global_confirm *tqe_next; struct global_confirm **tqe_prev; } entry;
 global_confirm_cb *cb;
 void *ctx;
 int ref_count;
};
struct global_confirms { struct global_confirm *tqh_first; struct global_confirm **tqh_last; };
static struct global_confirms global_confirms =
    { 
   ((void *)0)
   , &(global_confirms).tqh_first };

void ssh_process_session2_setup(int, int, int, struct sshbuf *);
static void quit_message(const char *fmt, ...)
    __attribute__((__format__ (printf, 1, 2)));

static void
quit_message(const char *fmt, ...)
{
 char *msg;
 va_list args;
 int r;

 
__builtin_va_start(
args
,
fmt
)
                   ;
 xvasprintf(&msg, fmt, args);
 
__builtin_va_end(
args
)
            ;

 if ((r = sshbuf_putf(stderr_buffer, "%s\r\n", msg)) != 0)
  sshfatal("clientloop.c", __func__, 208, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_putf");
 quit_pending = 1;
}






static void
window_change_handler(int sig)
{
 received_window_change_signal = 1;
}






static void
signal_handler(int sig)
{
 received_signal = sig;
 quit_pending = 1;
}







static void
set_control_persist_exit_time(struct ssh *ssh)
{
 if (muxserver_sock == -1 || !options.control_persist
     || options.control_persist_timeout == 0) {

  control_persist_exit_time = 0;
 } else if (channel_still_open(ssh)) {

  if (control_persist_exit_time > 0)
   sshlog("clientloop.c", __func__, 251, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "cancel scheduled exit");
  control_persist_exit_time = 0;
 } else if (control_persist_exit_time <= 0) {

  control_persist_exit_time = monotime() +
   (time_t)options.control_persist_timeout;
  sshlog("clientloop.c", __func__, 257, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "schedule exit in %d seconds", options.control_persist_timeout)
                                      ;
 }

}


static int
client_x11_display_valid(const char *display)
{
 size_t i, dlen;

 if (display == 
               ((void *)0)
                   )
  return 0;

 dlen = strlen(display);
 for (i = 0; i < dlen; i++) {
  if (!
      ((*__ctype_b_loc ())[(int) ((
      (u_char)display[i]
      ))] & (unsigned short int) _ISalnum) 
                                  &&
      strchr(":/.-_", display[i]) == 
                                                        ((void *)0)
                                                            ) {
   sshlog("clientloop.c", __func__, 276, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Invalid character '%c' in DISPLAY", display[i]);
   return 0;
  }
 }
 return 1;
}



int
client_x11_get_proto(struct ssh *ssh, const char *display,
    const char *xauth_path, u_int trusted, u_int timeout,
    char **_proto, char **_data)
{
 char *cmd, line[512], xdisplay[512];
 char xauthfile[
               4096
                       ], xauthdir[
                                   4096
                                           ];
 static char proto[512], data[512];
 FILE *f;
 int got_data = 0, generated = 0, do_unlink = 0, r;
 struct stat st;
 u_int now, x11_timeout_real;

 *_proto = proto;
 *_data = data;
 proto[0] = data[0] = xauthfile[0] = xauthdir[0] = '\0';

 if (!client_x11_display_valid(display)) {
  if (display != 
                ((void *)0)
                    )
   sshlog("clientloop.c", __func__, 304, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "DISPLAY \"%s\" invalid; disabling X11 forwarding", display)
               ;
  return -1;
 }
 if (xauth_path != 
                  ((void *)0) 
                       && stat(xauth_path, &st) == -1) {
  sshlog("clientloop.c", __func__, 309, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "No xauth program.");
  xauth_path = 
              ((void *)0)
                  ;
 }

 if (xauth_path != 
                  ((void *)0)
                      ) {







  if (strncmp(display, "localhost:", 10) == 0) {
   if ((r = snprintf(xdisplay, sizeof(xdisplay), "unix:%s",
       display + 10)) < 0 ||
       (size_t)r >= sizeof(xdisplay)) {
    sshlog("clientloop.c", __func__, 325, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "display name too long");
    return -1;
   }
   display = xdisplay;
  }
  if (trusted == 0) {







   mktemp_proto(xauthdir, sizeof(xauthdir));
   if (mkdtemp(xauthdir) == 
                           ((void *)0)
                               ) {
    sshlog("clientloop.c", __func__, 340, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "mkdtemp: %s", strerror(
   (*__errno_location ())
   ));
    return -1;
   }
   do_unlink = 1;
   if ((r = snprintf(xauthfile, sizeof(xauthfile),
       "%s/xauthfile", xauthdir)) < 0 ||
       (size_t)r >= sizeof(xauthfile)) {
    sshlog("clientloop.c", __func__, 347, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "xauthfile path too long");
    rmdir(xauthdir);
    return -1;
   }

   if (timeout == 0) {

    xasprintf(&cmd, "%s -f %s generate %s %s "
        "untrusted 2>%s",
        xauth_path, xauthfile, display,
        "MIT-MAGIC-COOKIE-1", 
                      "/dev/null"
                                   );
   } else {

    if (timeout < 
                 (0x7fffffff * 2U + 1U) 
                          - 60)
     x11_timeout_real = timeout +
         60;
    else {

     x11_timeout_real = 
                       (0x7fffffff * 2U + 1U)
                               ;
    }
    xasprintf(&cmd, "%s -f %s generate %s %s "
        "untrusted timeout %u 2>%s",
        xauth_path, xauthfile, display,
        "MIT-MAGIC-COOKIE-1", x11_timeout_real,
        
       "/dev/null"
                    );
   }
   sshlog("clientloop.c", __func__, 373, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "xauth command: %s", cmd);

   if (timeout != 0 && x11_refuse_time == 0) {
    now = monotime() + 1;
    if (
       (0x7fffffff * 2U + 1U) 
                - timeout < now)
     x11_refuse_time = 
                      (0x7fffffff * 2U + 1U)
                              ;
    else
     x11_refuse_time = now + timeout;
    channel_set_x11_refuse_time(ssh,
        x11_refuse_time);
   }
   if (system(cmd) == 0)
    generated = 1;
   free(cmd);
  }






  if (trusted || generated) {
   xasprintf(&cmd,
       "%s %s%s list %s 2>" 
                           "/dev/null"
                                        ,
       xauth_path,
       generated ? "-f " : "" ,
       generated ? xauthfile : "",
       display);
   sshlog("clientloop.c", __func__, 401, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "x11_get_proto: %s", cmd);
   f = popen(cmd, "r");
   if (f && fgets(line, sizeof(line), f) &&
       sscanf(line, "%*s %511s %511s", proto, data) == 2)
    got_data = 1;
   if (f)
    pclose(f);
   free(cmd);
  }
 }

 if (do_unlink) {
  unlink(xauthfile);
  rmdir(xauthdir);
 }


 if (!trusted && !got_data) {
  sshlog("clientloop.c", __func__, 419, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Warning: untrusted X11 forwarding setup failed: " "xauth key data not generated")
                                     ;
  return -1;
 }
 if (!got_data) {
  u_int8_t rnd[16];
  u_int i;

  sshlog("clientloop.c", __func__, 436, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Warning: No xauth data; " "using fake authentication data for X11 forwarding.")
                                                           ;
  strlcpy(proto, "MIT-MAGIC-COOKIE-1", sizeof proto);
  arc4random_buf(rnd, sizeof(rnd));
  for (i = 0; i < sizeof(rnd); i++) {
   snprintf(data + 2 * i, sizeof data - 2 * i, "%02x",
       rnd[i]);
  }
 }

 return 0;
}
static void
client_check_window_change(struct ssh *ssh)
{
 if (!received_window_change_signal)
  return;
 received_window_change_signal = 0;
 sshlog("clientloop.c", __func__, 462, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "changed");
 channel_send_window_changes(ssh);
}

static int
client_global_request_reply(int type, u_int32_t seq, struct ssh *ssh)
{
 struct global_confirm *gc;

 if ((gc = ((&global_confirms)->tqh_first)) == 
                                            ((void *)0)
                                                )
  return 0;
 if (gc->cb != 
              ((void *)0)
                  )
  gc->cb(ssh, type, seq, gc->ctx);
 if (--gc->ref_count <= 0) {
  do { if (((gc)->entry.tqe_next) != 
 ((void *)0)
 ) (gc)->entry.tqe_next->entry.tqe_prev = (gc)->entry.tqe_prev; else (&global_confirms)->tqh_last = (gc)->entry.tqe_prev; *(gc)->entry.tqe_prev = (gc)->entry.tqe_next; ; ; } while (0);
  freezero(gc, sizeof(*gc));
 }

 ssh_packet_set_alive_timeouts(ssh, 0);
 return 0;
}

static void
schedule_server_alive_check(void)
{
 if (options.server_alive_interval > 0)
  server_alive_time = monotime() + options.server_alive_interval;
}

static void
server_alive_check(struct ssh *ssh)
{
 int r;

 if (ssh_packet_inc_alive_timeouts(ssh) > options.server_alive_count_max) {
  sshlog("clientloop.c", __func__, 497, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Timeout, server %s not responding.", host);
  cleanup_exit(255);
 }
 if ((r = sshpkt_start(ssh, 80)) != 0 ||
     (r = sshpkt_put_cstring(ssh, "keepalive@openssh.com")) != 0 ||
     (r = sshpkt_put_u8(ssh, 1)) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  sshfatal("clientloop.c", __func__, 504, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send packet");

 client_register_global_confirm(
                               ((void *)0)
                                   , 
                                     ((void *)0)
                                         );
 schedule_server_alive_check();
}





static void
client_wait_until_can_do_something(struct ssh *ssh, struct pollfd **pfdp,
    u_int *npfd_allocp, u_int *npfd_activep, int rekeying,
    int *conn_in_readyp, int *conn_out_readyp)
{
 int timeout_secs, pollwait;
 time_t minwait_secs = 0, now = monotime();
 int ret;
 u_int p;

 *conn_in_readyp = *conn_out_readyp = 0;


 channel_prepare_poll(ssh, pfdp, npfd_allocp, npfd_activep, 2,
     &minwait_secs);
 if (*npfd_activep < 2)
  sshfatal("clientloop.c", __func__, 530, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "bad npfd %u", *npfd_activep);


 if (session_closed && !channel_still_open(ssh) &&
     !ssh_packet_have_data_to_write(ssh)) {

  for (p = 0; p < *npfd_activep; p++)
   (*pfdp)[p].revents = 0;
  return;
 }


 (*pfdp)[0].fd = connection_in;
 (*pfdp)[0].events = 
                    0x001
                          ;
 (*pfdp)[1].fd = connection_out;
 (*pfdp)[1].events = ssh_packet_have_data_to_write(ssh) ? 
                                                         0x004 
                                                                 : 0;







 timeout_secs = 0x7fffffff;
 if (options.server_alive_interval > 0)
  timeout_secs = (((server_alive_time - now) > (0)) ? (server_alive_time - now) : (0));
 if (options.rekey_interval > 0 && !rekeying)
  timeout_secs = (((timeout_secs) < (ssh_packet_get_rekey_timeout(ssh))) ? (timeout_secs) : (ssh_packet_get_rekey_timeout(ssh)))
                                        ;
 set_control_persist_exit_time(ssh);
 if (control_persist_exit_time > 0) {
  timeout_secs = (((timeout_secs) < (control_persist_exit_time - now)) ? (timeout_secs) : (control_persist_exit_time - now))
                                   ;
  if (timeout_secs < 0)
   timeout_secs = 0;
 }
 if (minwait_secs != 0)
  timeout_secs = (((timeout_secs) < ((int)minwait_secs)) ? (timeout_secs) : ((int)minwait_secs));
 if (timeout_secs == 0x7fffffff)
  pollwait = -1;
 else if (timeout_secs >= 0x7fffffff / 1000)
  pollwait = 0x7fffffff;
 else
  pollwait = timeout_secs * 1000;

 ret = poll(*pfdp, *npfd_activep, pollwait);

 if (ret == -1) {





  for (p = 0; p < *npfd_activep; p++)
   (*pfdp)[p].revents = 0;
  if (
     (*__errno_location ()) 
           == 
              4
                   )
   return;

  quit_message("poll: %s", strerror(
                                   (*__errno_location ())
                                        ));
  return;
 }

 *conn_in_readyp = (*pfdp)[0].revents != 0;
 *conn_out_readyp = (*pfdp)[1].revents != 0;

 if (options.server_alive_interval > 0 && !*conn_in_readyp &&
     monotime() >= server_alive_time) {





  server_alive_check(ssh);
 }
}

static void
client_suspend_self(struct sshbuf *bin, struct sshbuf *bout, struct sshbuf *berr)
{

 if (sshbuf_len(bout) > 0)
  atomicio((ssize_t (*)(int, void *, size_t))write, fileno(
                         stdout
                               ), sshbuf_mutable_ptr(bout),
      sshbuf_len(bout));
 if (sshbuf_len(berr) > 0)
  atomicio((ssize_t (*)(int, void *, size_t))write, fileno(
                         stderr
                               ), sshbuf_mutable_ptr(berr),
      sshbuf_len(berr));

 leave_raw_mode(options.request_tty == 3);

 sshbuf_reset(bin);
 sshbuf_reset(bout);
 sshbuf_reset(berr);


 kill(getpid(), 
               20
                      );


 received_window_change_signal = 1;

 enter_raw_mode(options.request_tty == 3);
}

static void
client_process_net_input(struct ssh *ssh)
{
 int r;





 schedule_server_alive_check();
 if ((r = ssh_packet_process_read(ssh, connection_in)) == 0)
  return;
 if (r == -24) {
  if (
     (*__errno_location ()) 
           == 
              11 
                     || 
                        (*__errno_location ()) 
                              == 
                                 4 
                                       || 
                                          (*__errno_location ()) 
                                                == 
                                                   11
                                                              )
   return;
  if (
     (*__errno_location ()) 
           == 
              32
                   ) {
   quit_message("Connection to %s closed by remote host.",
       host);
   return;
  }
 }
 quit_message("Read from remote host %s: %s", host, ssh_err(r));
}

static void
client_status_confirm(struct ssh *ssh, int type, Channel *c, void *ctx)
{
 struct channel_reply_ctx *cr = (struct channel_reply_ctx *)ctx;
 char errmsg[256];
 int r, tochan;





 if (cr->action == CONFIRM_TTY &&
     (options.request_tty == 3 ||
     options.request_tty == 2))
  cr->action = CONFIRM_CLOSE;


 tochan = options.log_level >= SYSLOG_LEVEL_ERROR &&
     c->ctl_chan != -1 && c->extended_usage == 2;

 if (type == 99) {
  sshlog("clientloop.c", __func__, 677, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "%s request accepted on channel %d", cr->request_type, c->self)
                                ;
 } else if (type == 100) {
  if (tochan) {
   snprintf(errmsg, sizeof(errmsg),
       "%s request failed\r\n", cr->request_type);
  } else {
   snprintf(errmsg, sizeof(errmsg),
       "%s request failed on channel %d",
       cr->request_type, c->self);
  }

  if (cr->action == CONFIRM_CLOSE && c->self == session_ident)
   sshfatal("clientloop.c", __func__, 690, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s", errmsg);




  if (tochan) {
   sshlog("clientloop.c", __func__, 696, 1, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "channel %d: mux request: %s", c->self, cr->request_type)
                        ;
   if ((r = sshbuf_put(c->extended, errmsg,
       strlen(errmsg))) != 0)
    sshfatal("clientloop.c", __func__, 700, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_put");
  } else
   sshlog("clientloop.c", __func__, 702, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s", errmsg);
  if (cr->action == CONFIRM_TTY) {




   if (c->self == session_ident)
    leave_raw_mode(0);
   else
    mux_tty_alloc_failed(ssh, c);
  } else if (cr->action == CONFIRM_CLOSE) {
   chan_read_failed(ssh, c);
   chan_write_failed(ssh, c);
  }
 }
 free(cr);
}

static void
client_abandon_status_confirm(struct ssh *ssh, Channel *c, void *ctx)
{
 free(ctx);
}

void
client_expect_confirm(struct ssh *ssh, int id, const char *request,
    enum confirm_action action)
{
 struct channel_reply_ctx *cr = xcalloc(1, sizeof(*cr));

 cr->request_type = request;
 cr->action = action;

 channel_register_status_confirm(ssh, id, client_status_confirm,
     client_abandon_status_confirm, cr);
}

void
client_register_global_confirm(global_confirm_cb *cb, void *ctx)
{
 struct global_confirm *gc, *last_gc;


 last_gc = (*(((struct global_confirms *)((&global_confirms)->tqh_last))->tqh_last));
 if (last_gc && last_gc->cb == cb && last_gc->ctx == ctx) {
  if (++last_gc->ref_count >= 0x7fffffff)
   sshfatal("clientloop.c", __func__, 748, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "last_gc->ref_count = %d", last_gc->ref_count)
                          ;
  return;
 }

 gc = xcalloc(1, sizeof(*gc));
 gc->cb = cb;
 gc->ctx = ctx;
 gc->ref_count = 1;
 do { (gc)->entry.tqe_next = 
((void *)0)
; (gc)->entry.tqe_prev = (&global_confirms)->tqh_last; *(&global_confirms)->tqh_last = (gc); (&global_confirms)->tqh_last = &(gc)->entry.tqe_next; } while (0);
}

static void
process_cmdline(struct ssh *ssh)
{
 void (*handler)(int);
 char *s, *cmd;
 int ok, delete = 0, local = 0, remote = 0, dynamic = 0;
 struct Forward fwd;

 memset(&fwd, 0, sizeof(fwd));

 leave_raw_mode(options.request_tty == 3);
 handler = ssh_signal(
                     2
                           , 
                             ((__sighandler_t) 1)
                                    );
 cmd = s = read_passphrase("\r\nssh> ", 0x0001);
 if (s == 
         ((void *)0)
             )
  goto out;
 while (
       ((*__ctype_b_loc ())[(int) ((
       (u_char)*s
       ))] & (unsigned short int) _ISspace)
                          )
  s++;
 if (*s == '-')
  s++;
 if (*s == '\0')
  goto out;

 if (*s == 'h' || *s == 'H' || *s == '?') {
  sshlog("clientloop.c", __func__, 783, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Commands:");
  sshlog("clientloop.c", __func__, 784, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "      -L[bind_address:]port:host:hostport    " "Request local forward")
                              ;
  sshlog("clientloop.c", __func__, 786, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "      -R[bind_address:]port:host:hostport    " "Request remote forward")
                               ;
  sshlog("clientloop.c", __func__, 788, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "      -D[bind_address:]port                  " "Request dynamic forward")
                                ;
  sshlog("clientloop.c", __func__, 790, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "      -KL[bind_address:]port                 " "Cancel local forward")
                             ;
  sshlog("clientloop.c", __func__, 792, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "      -KR[bind_address:]port                 " "Cancel remote forward")
                              ;
  sshlog("clientloop.c", __func__, 794, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "      -KD[bind_address:]port                 " "Cancel dynamic forward")
                               ;
  if (!options.permit_local_command)
   goto out;
  sshlog("clientloop.c", __func__, 798, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "      !args                                  " "Execute local command")
                              ;
  goto out;
 }

 if (*s == '!' && options.permit_local_command) {
  s++;
  ssh_local_cmd(s);
  goto out;
 }

 if (*s == 'K') {
  delete = 1;
  s++;
 }
 if (*s == 'L')
  local = 1;
 else if (*s == 'R')
  remote = 1;
 else if (*s == 'D')
  dynamic = 1;
 else {
  sshlog("clientloop.c", __func__, 820, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Invalid command.");
  goto out;
 }

 while (
       ((*__ctype_b_loc ())[(int) ((
       (u_char)*++s
       ))] & (unsigned short int) _ISspace)
                            )
  ;


 if (delete) {

  if (!parse_forward(&fwd, s, 1, 0)) {
   sshlog("clientloop.c", __func__, 831, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Bad forwarding close specification.");
   goto out;
  }
  if (remote)
   ok = channel_request_rforward_cancel(ssh, &fwd) == 0;
  else if (dynamic)
   ok = channel_cancel_lport_listener(ssh, &fwd,
       0, &options.fwd_opts) > 0;
  else
   ok = channel_cancel_lport_listener(ssh, &fwd,
       -1,
       &options.fwd_opts) > 0;
  if (!ok) {
   sshlog("clientloop.c", __func__, 844, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Unknown port forwarding.");
   goto out;
  }
  sshlog("clientloop.c", __func__, 847, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Canceled forwarding.");
 } else {
  if (!parse_forward(&fwd, s, dynamic, remote)) {
   sshlog("clientloop.c", __func__, 850, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Bad forwarding specification.");
   goto out;
  }
  if (local || dynamic) {
   if (!channel_setup_local_fwd_listener(ssh, &fwd,
       &options.fwd_opts)) {
    sshlog("clientloop.c", __func__, 856, 0, SYSLOG_LEVEL_INFO, 
   ((void *)0)
   , "Port forwarding failed.");
    goto out;
   }
  } else {
   if (channel_request_remote_forwarding(ssh, &fwd) < 0) {
    sshlog("clientloop.c", __func__, 861, 0, SYSLOG_LEVEL_INFO, 
   ((void *)0)
   , "Port forwarding failed.");
    goto out;
   }
  }
  sshlog("clientloop.c", __func__, 865, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Forwarding port.");
 }

out:
 ssh_signal(
           2
                 , handler);
 enter_raw_mode(options.request_tty == 3);
 free(cmd);
 free(fwd.listen_host);
 free(fwd.listen_path);
 free(fwd.connect_host);
 free(fwd.connect_path);
}






struct escape_help_text {
 const char *cmd;
 const char *text;
 unsigned int flags;
};
static struct escape_help_text esc_txt[] = {
    {".", "terminate session", 2},
    {".", "terminate connection (and any multiplexed sessions)",
 1},
    {"B", "send a BREAK to the remote system", 0},
    {"C", "open a command line", 1},
    {"R", "request rekey", 0},
    {"V/v", "decrease/increase verbosity (LogLevel)", 1},
    {"^Z", "suspend ssh", 1},
    {"#", "list forwarded connections", 0},
    {"&", "background ssh (when waiting for connections to terminate)",
 1},
    {"?", "this message", 0},
};

static void
print_escape_help(struct sshbuf *b, int escape_char, int mux_client,
    int using_stderr)
{
 unsigned int i, suppress_flags;
 int r;

 if ((r = sshbuf_putf(b,
     "%c?\r\nSupported escape sequences:\r\n", escape_char)) != 0)
  sshfatal("clientloop.c", __func__, 912, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_putf");

 suppress_flags =
     (mux_client ? 1 : 0) |
     (mux_client ? 0 : 2) |
     (using_stderr ? 0 : 4);

 for (i = 0; i < sizeof(esc_txt)/sizeof(esc_txt[0]); i++) {
  if (esc_txt[i].flags & suppress_flags)
   continue;
  if ((r = sshbuf_putf(b, " %c%-3s - %s\r\n",
      escape_char, esc_txt[i].cmd, esc_txt[i].text)) != 0)
   sshfatal("clientloop.c", __func__, 924, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_putf");
 }

 if ((r = sshbuf_putf(b,
     " %c%c   - send the escape character by typing it twice\r\n"
     "(Note that escapes are only recognized immediately after "
     "newline.)\r\n", escape_char, escape_char)) != 0)
  sshfatal("clientloop.c", __func__, 931, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_putf");
}




static int
process_escapes(struct ssh *ssh, Channel *c,
    struct sshbuf *bin, struct sshbuf *bout, struct sshbuf *berr,
    char *buf, int len)
{
 pid_t pid;
 int r, bytes = 0;
 u_int i;
 u_char ch;
 char *s;
 struct escape_filter_ctx *efc = c->filter_ctx == 
                                                 ((void *)0) 
                                                      ?
     
    ((void *)0) 
         : (struct escape_filter_ctx *)c->filter_ctx;

 if (c->filter_ctx == 
                     ((void *)0)
                         )
  return 0;

 if (len <= 0)
  return (0);

 for (i = 0; i < (u_int)len; i++) {

  ch = buf[i];

  if (efc->escape_pending) {


   efc->escape_pending = 0;


   switch (ch) {
   case '.':

    if ((r = sshbuf_putf(berr, "%c.\r\n",
        efc->escape_char)) != 0)
     sshfatal("clientloop.c", __func__, 971, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_putf");
    if (c && c->ctl_chan != -1) {
     chan_read_failed(ssh, c);
     chan_write_failed(ssh, c);
     if (c->detach_user) {
      c->detach_user(ssh,
          c->self, 
                  ((void *)0)
                      );
     }
     c->type = 17;
     sshbuf_reset(c->input);
     chan_ibuf_empty(ssh, c);
     return 0;
    } else
     quit_pending = 1;
    return -1;

   case 'Z' - 64:

    if (c && c->ctl_chan != -1) {
     char b[16];
 noescape:
     if (ch == 'Z' - 64)
      snprintf(b, sizeof b, "^Z");
     else
      snprintf(b, sizeof b, "%c", ch);
     if ((r = sshbuf_putf(berr,
         "%c%s escape not available to "
         "multiplexed sessions\r\n",
         efc->escape_char, b)) != 0)
      sshfatal("clientloop.c", __func__, 1000, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_putf");
     continue;
    }

    if ((r = sshbuf_putf(berr,
        "%c^Z [suspend ssh]\r\n",
        efc->escape_char)) != 0)
     sshfatal("clientloop.c", __func__, 1007, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_putf");


    client_suspend_self(bin, bout, berr);


    continue;

   case 'B':
    if ((r = sshbuf_putf(berr,
        "%cB\r\n", efc->escape_char)) != 0)
     sshfatal("clientloop.c", __func__, 1018, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_putf");
    channel_request_start(ssh, c->self, "break", 0);
    if ((r = sshpkt_put_u32(ssh, 1000)) != 0 ||
        (r = sshpkt_send(ssh)) != 0)
     sshfatal("clientloop.c", __func__, 1022, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send packet");
    continue;

   case 'R':
    if (ssh->compat & 0x00008000)
     sshlog("clientloop.c", __func__, 1027, 0, SYSLOG_LEVEL_INFO, 
    ((void *)0)
    , "Server does not " "support re-keying")
                             ;
    else
     need_rekeying = 1;
    continue;

   case 'V':

   case 'v':
    if (c && c->ctl_chan != -1)
     goto noescape;
    if (!log_is_on_stderr()) {
     if ((r = sshbuf_putf(berr,
         "%c%c [Logging to syslog]\r\n",
         efc->escape_char, ch)) != 0)
      sshfatal("clientloop.c", __func__, 1042, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_putf");
     continue;
    }
    if (ch == 'V' && options.log_level >
        SYSLOG_LEVEL_QUIET)
     log_change_level(--options.log_level);
    if (ch == 'v' && options.log_level <
        SYSLOG_LEVEL_DEBUG3)
     log_change_level(++options.log_level);
    if ((r = sshbuf_putf(berr,
        "%c%c [LogLevel %s]\r\n",
        efc->escape_char, ch,
        log_level_name(options.log_level))) != 0)
     sshfatal("clientloop.c", __func__, 1055, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_putf");
    continue;

   case '&':
    if (c && c->ctl_chan != -1)
     goto noescape;






    leave_raw_mode(
        options.request_tty == 3);


    channel_stop_listening(ssh);

    if ((r = sshbuf_putf(berr, "%c& "
        "[backgrounded]\n", efc->escape_char)) != 0)
     sshfatal("clientloop.c", __func__, 1075, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_putf");


    pid = fork();
    if (pid == -1) {
     sshlog("clientloop.c", __func__, 1080, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "fork: %.100s", strerror(
    (*__errno_location ())
    ));
     continue;
    }
    if (pid != 0) {

     exit(0);
    }


    if ((r = sshbuf_put_u8(bin, 4)) != 0)
     sshfatal("clientloop.c", __func__, 1090, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_put_u8");
    return -1;
   case '?':
    print_escape_help(berr, efc->escape_char,
        (c && c->ctl_chan != -1),
        log_is_on_stderr());
    continue;

   case '#':
    if ((r = sshbuf_putf(berr, "%c#\r\n",
        efc->escape_char)) != 0)
     sshfatal("clientloop.c", __func__, 1101, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_putf");
    s = channel_open_message(ssh);
    if ((r = sshbuf_put(berr, s, strlen(s))) != 0)
     sshfatal("clientloop.c", __func__, 1104, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_put");
    free(s);
    continue;

   case 'C':
    if (c && c->ctl_chan != -1)
     goto noescape;
    process_cmdline(ssh);
    continue;

   default:
    if (ch != efc->escape_char) {
     if ((r = sshbuf_put_u8(bin,
         efc->escape_char)) != 0)
      sshfatal("clientloop.c", __func__, 1118, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_put_u8");
     bytes++;
    }

    break;
   }
  } else {




   if (last_was_cr && ch == efc->escape_char) {




    efc->escape_pending = 1;
    continue;
   }
  }





  last_was_cr = (ch == '\r' || ch == '\n');
  if ((r = sshbuf_put_u8(bin, ch)) != 0)
   sshfatal("clientloop.c", __func__, 1145, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_put_u8");
  bytes++;
 }
 return bytes;
}
static void
client_process_buffered_input_packets(struct ssh *ssh)
{
 ssh_dispatch_run_fatal(ssh, DISPATCH_NONBLOCK, &quit_pending);
}




void *
client_new_escape_filter_ctx(int escape_char)
{
 struct escape_filter_ctx *ret;

 ret = xcalloc(1, sizeof(*ret));
 ret->escape_pending = 0;
 ret->escape_char = escape_char;
 return (void *)ret;
}


void
client_filter_cleanup(struct ssh *ssh, int cid, void *ctx)
{
 free(ctx);
}

int
client_simple_escape_filter(struct ssh *ssh, Channel *c, char *buf, int len)
{
 if (c->extended_usage != 2)
  return 0;

 return process_escapes(ssh, c, c->input, c->output, c->extended,
     buf, len);
}

static void
client_channel_closed(struct ssh *ssh, int id, void *arg)
{
 channel_cancel_cleanup(ssh, id);
 session_closed = 1;
 leave_raw_mode(options.request_tty == 3);
}







int
client_loop(struct ssh *ssh, int have_pty, int escape_char_arg,
    int ssh2_chan_id)
{
 struct pollfd *pfd = 
                     ((void *)0)
                         ;
 u_int npfd_alloc = 0, npfd_active = 0;
 double start_time, total_time;
 int r, len;
 u_int64_t ibytes, obytes;
 int conn_in_ready, conn_out_ready;

 sshlog("clientloop.c", __func__, 1225, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Entering interactive session.");

 if (options.control_master &&
     !option_clear_or_none(options.control_path)) {
  sshlog("clientloop.c", __func__, 1229, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "pledge: id");
  if (pledge("stdio rpath wpath cpath unix inet dns recvfd sendfd proc exec id tty",
      
     ((void *)0)
         ) == -1)
   sshfatal("clientloop.c", __func__, 1232, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "pledge(): %s", strerror(
  (*__errno_location ())
  ));

 } else if (options.forward_x11 || options.permit_local_command) {
  sshlog("clientloop.c", __func__, 1235, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "pledge: exec");
  if (pledge("stdio rpath wpath cpath unix inet dns proc exec tty",
      
     ((void *)0)
         ) == -1)
   sshfatal("clientloop.c", __func__, 1238, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "pledge(): %s", strerror(
  (*__errno_location ())
  ));

 } else if (options.update_hostkeys) {
  sshlog("clientloop.c", __func__, 1241, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "pledge: filesystem");
  if (pledge("stdio rpath wpath cpath unix inet dns proc tty",
      
     ((void *)0)
         ) == -1)
   sshfatal("clientloop.c", __func__, 1244, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "pledge(): %s", strerror(
  (*__errno_location ())
  ));

 } else if (!option_clear_or_none(options.proxy_command) ||
     options.fork_after_authentication) {
  sshlog("clientloop.c", __func__, 1248, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "pledge: proc");
  if (pledge("stdio cpath unix inet dns proc tty", 
                                                  ((void *)0)
                                                      ) == -1)
   sshfatal("clientloop.c", __func__, 1250, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "pledge(): %s", strerror(
  (*__errno_location ())
  ));

 } else {
  sshlog("clientloop.c", __func__, 1253, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "pledge: network");
  if (pledge("stdio unix inet dns proc tty", 
                                            ((void *)0)
                                                ) == -1)
   sshfatal("clientloop.c", __func__, 1255, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "pledge(): %s", strerror(
  (*__errno_location ())
  ));
 }

 start_time = monotime_double();


 last_was_cr = 1;
 exit_status = -1;
 connection_in = ssh_packet_get_connection_in(ssh);
 connection_out = ssh_packet_get_connection_out(ssh);

 quit_pending = 0;


 if ((stderr_buffer = sshbuf_new()) == 
                                      ((void *)0)
                                          )
  sshfatal("clientloop.c", __func__, 1270, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");

 client_init_dispatch(ssh);





 if (ssh_signal(
               1
                     , 
                       ((__sighandler_t) 1)
                              ) != 
                                   ((__sighandler_t) 1)
                                          )
  ssh_signal(
            1
                  , signal_handler);
 if (ssh_signal(
               2
                     , 
                       ((__sighandler_t) 1)
                              ) != 
                                   ((__sighandler_t) 1)
                                          )
  ssh_signal(
            2
                  , signal_handler);
 if (ssh_signal(
               3
                      , 
                        ((__sighandler_t) 1)
                               ) != 
                                    ((__sighandler_t) 1)
                                           )
  ssh_signal(
            3
                   , signal_handler);
 if (ssh_signal(
               15
                      , 
                        ((__sighandler_t) 1)
                               ) != 
                                    ((__sighandler_t) 1)
                                           )
  ssh_signal(
            15
                   , signal_handler);
 ssh_signal(
           28
                   , window_change_handler);

 if (have_pty)
  enter_raw_mode(options.request_tty == 3);

 session_ident = ssh2_chan_id;
 if (session_ident != -1) {
  if (escape_char_arg != -2) {
   channel_register_filter(ssh, session_ident,
       client_simple_escape_filter, 
                                   ((void *)0)
                                       ,
       client_filter_cleanup,
       client_new_escape_filter_ctx(
       escape_char_arg));
  }
  channel_register_cleanup(ssh, session_ident,
      client_channel_closed, 0);
 }

 schedule_server_alive_check();


 while (!quit_pending) {


  client_process_buffered_input_packets(ssh);

  if (session_closed && !channel_still_open(ssh))
   break;

  if (ssh_packet_is_rekeying(ssh)) {
   sshlog("clientloop.c", __func__, 1316, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "rekeying in progress");
  } else if (need_rekeying) {

   sshlog("clientloop.c", __func__, 1319, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "need rekeying");
   if ((r = kex_start_rekex(ssh)) != 0)
    sshfatal("clientloop.c", __func__, 1321, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "kex_start_rekex");
   need_rekeying = 0;
  } else {




   if (ssh_packet_not_very_much_data_to_write(ssh))
    channel_output_poll(ssh);





   client_check_window_change(ssh);

   if (quit_pending)
    break;
  }




  client_wait_until_can_do_something(ssh, &pfd, &npfd_alloc,
      &npfd_active, ssh_packet_is_rekeying(ssh),
      &conn_in_ready, &conn_out_ready);

  if (quit_pending)
   break;


  channel_after_poll(ssh, pfd, npfd_active);


  if (conn_in_ready)
   client_process_net_input(ssh);

  if (quit_pending)
   break;


  if ((r = ssh_packet_check_rekey(ssh)) != 0)
   sshfatal("clientloop.c", __func__, 1363, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "cannot start rekeying");





  if (conn_out_ready) {
   if ((r = ssh_packet_write_poll(ssh)) != 0) {
    sshpkt_fatal(ssh, r,
        "%s: ssh_packet_write_poll", __func__);
   }
  }






  if (control_persist_exit_time > 0) {
   if (monotime() >= control_persist_exit_time) {
    sshlog("clientloop.c", __func__, 1383, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "ControlPersist timeout expired");
    break;
   }
  }
 }
 free(pfd);




 ssh_signal(
           28
                   , 
                     ((__sighandler_t) 0)
                            );

 if ((r = sshpkt_start(ssh, 1)) != 0 ||
     (r = sshpkt_put_u32(ssh, 11)) != 0 ||
     (r = sshpkt_put_cstring(ssh, "disconnected by user")) != 0 ||
     (r = sshpkt_put_cstring(ssh, "")) != 0 ||
     (r = sshpkt_send(ssh)) != 0 ||
     (r = ssh_packet_write_wait(ssh)) != 0)
  sshfatal("clientloop.c", __func__, 1401, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send disconnect");

 channel_free_all(ssh);

 if (have_pty)
  leave_raw_mode(options.request_tty == 3);






 if (options.session_type == 0 &&
     received_signal == 
                       15
                              ) {
  received_signal = 0;
  exit_status = 0;
 }

 if (received_signal) {
  sshlog("clientloop.c", __func__, 1420, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "Killed by signal %d.", (int) received_signal);
  cleanup_exit(255);
 }





 if (have_pty && options.log_level >= SYSLOG_LEVEL_INFO)
  quit_message("Connection to %s closed.", host);


 if (sshbuf_len(stderr_buffer) > 0) {
  len = atomicio((ssize_t (*)(int, void *, size_t))write, fileno(
                               stderr
                                     ),
      (u_char *)sshbuf_ptr(stderr_buffer),
      sshbuf_len(stderr_buffer));
  if (len < 0 || (u_int)len != sshbuf_len(stderr_buffer))
   sshlog("clientloop.c", __func__, 1437, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Write failed flushing stderr buffer.");
  else if ((r = sshbuf_consume(stderr_buffer, len)) != 0)
   sshfatal("clientloop.c", __func__, 1439, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshbuf_consume");
 }


 sshbuf_free(stderr_buffer);


 total_time = monotime_double() - start_time;
 ssh_packet_get_bytes(ssh, &ibytes, &obytes);
 sshlog("clientloop.c", __func__, 1448, 0, SYSLOG_LEVEL_VERBOSE, 
((void *)0)
, "Transferred: sent %llu, received %llu bytes, in %.1f seconds", (unsigned long long)obytes, (unsigned long long)ibytes, total_time)
                                                                        ;
 if (total_time > 0)
  sshlog("clientloop.c", __func__, 1451, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "Bytes per second: sent %.1f, received %.1f", obytes / total_time, ibytes / total_time)
                                               ;

 sshlog("clientloop.c", __func__, 1454, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Exit status %d", exit_status);
 return exit_status;
}



static Channel *
client_request_forwarded_tcpip(struct ssh *ssh, const char *request_type,
    int rchan, u_int rwindow, u_int rmaxpack)
{
 Channel *c = 
             ((void *)0)
                 ;
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 char *listen_address, *originator_address;
 u_int listen_port, originator_port;
 int r;


 if ((r = sshpkt_get_cstring(ssh, &listen_address, 
                                                  ((void *)0)
                                                      )) != 0 ||
     (r = sshpkt_get_u32(ssh, &listen_port)) != 0 ||
     (r = sshpkt_get_cstring(ssh, &originator_address, 
                                                      ((void *)0)
                                                          )) != 0 ||
     (r = sshpkt_get_u32(ssh, &originator_port)) != 0 ||
     (r = sshpkt_get_end(ssh)) != 0)
  sshfatal("clientloop.c", __func__, 1476, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse packet");

 sshlog("clientloop.c", __func__, 1478, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "listen %s port %d, originator %s port %d", listen_address, listen_port, originator_address, originator_port)
                                                                      ;

 if (listen_port > 0xffff)
  sshlog("clientloop.c", __func__, 1482, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "invalid listen port");
 else if (originator_port > 0xffff)
  sshlog("clientloop.c", __func__, 1484, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "invalid originator port");
 else {
  c = channel_connect_by_listen_address(ssh,
      listen_address, listen_port, "forwarded-tcpip",
      originator_address);
 }

 if (c != 
         ((void *)0) 
              && c->type == 16) {
  if ((b = sshbuf_new()) == 
                           ((void *)0)
                               ) {
   sshlog("clientloop.c", __func__, 1493, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "alloc reply");
   goto out;
  }

  if ((r = sshbuf_put_u8(b, 0)) != 0 ||
      (r = sshbuf_put_u8(b, 90)) != 0 ||
      (r = sshbuf_put_cstring(b, request_type)) != 0 ||
      (r = sshbuf_put_u32(b, rchan)) != 0 ||
      (r = sshbuf_put_u32(b, rwindow)) != 0 ||
      (r = sshbuf_put_u32(b, rmaxpack)) != 0 ||
      (r = sshbuf_put_cstring(b, listen_address)) != 0 ||
      (r = sshbuf_put_u32(b, listen_port)) != 0 ||
      (r = sshbuf_put_cstring(b, originator_address)) != 0 ||
      (r = sshbuf_put_u32(b, originator_port)) != 0 ||
      (r = sshbuf_put_stringb(c->output, b)) != 0) {
   sshlog("clientloop.c", __func__, 1508, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "compose for muxclient");
   goto out;
  }
 }

 out:
 sshbuf_free(b);
 free(originator_address);
 free(listen_address);
 return c;
}

static Channel *
client_request_forwarded_streamlocal(struct ssh *ssh,
    const char *request_type, int rchan)
{
 Channel *c = 
             ((void *)0)
                 ;
 char *listen_path;
 int r;


 if ((r = sshpkt_get_cstring(ssh, &listen_path, 
                                               ((void *)0)
                                                   )) != 0 ||
     (r = sshpkt_get_string(ssh, 
                                ((void *)0)
                                    , 
                                      ((void *)0)
                                          )) != 0 ||
     (r = sshpkt_get_end(ssh)) != 0)
  sshfatal("clientloop.c", __func__, 1532, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse packet");

 sshlog("clientloop.c", __func__, 1534, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "request: %s", listen_path);

 c = channel_connect_by_listen_path(ssh, listen_path,
     "forwarded-streamlocal@openssh.com", "forwarded-streamlocal");
 free(listen_path);
 return c;
}

static Channel *
client_request_x11(struct ssh *ssh, const char *request_type, int rchan)
{
 Channel *c = 
             ((void *)0)
                 ;
 char *originator;
 u_int originator_port;
 int r, sock;

 if (!options.forward_x11) {
  sshlog("clientloop.c", __func__, 1551, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Warning: ssh server tried X11 forwarding.");
  sshlog("clientloop.c", __func__, 1552, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Warning: this is probably a break-in attempt by a " "malicious server.")
                          ;
  return 
        ((void *)0)
            ;
 }
 if (x11_refuse_time != 0 && (u_int)monotime() >= x11_refuse_time) {
  sshlog("clientloop.c", __func__, 1557, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "Rejected X11 connection after ForwardX11Timeout " "expired")
                ;
  return 
        ((void *)0)
            ;
 }
 if ((r = sshpkt_get_cstring(ssh, &originator, 
                                              ((void *)0)
                                                  )) != 0 ||
     (r = sshpkt_get_u32(ssh, &originator_port)) != 0 ||
     (r = sshpkt_get_end(ssh)) != 0)
  sshfatal("clientloop.c", __func__, 1564, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse packet");


 sshlog("clientloop.c", __func__, 1567, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "client_request_x11: request from %s %u", originator, originator_port)
                     ;
 free(originator);
 sock = x11_connect_display(ssh);
 if (sock < 0)
  return 
        ((void *)0)
            ;
 c = channel_new(ssh, "x11",
     7, sock, sock, -1,
     (64*(32*1024)), (16*1024), 0, "x11", 1);
 c->force_drain = 1;
 return c;
}

static Channel *
client_request_agent(struct ssh *ssh, const char *request_type, int rchan)
{
 Channel *c = 
             ((void *)0)
                 ;
 int r, sock;

 if (!options.forward_agent) {
  sshlog("clientloop.c", __func__, 1587, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Warning: ssh server tried agent forwarding.");
  sshlog("clientloop.c", __func__, 1588, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Warning: this is probably a break-in attempt by a " "malicious server.")
                          ;
  return 
        ((void *)0)
            ;
 }
 if (forward_agent_sock_path == 
                               ((void *)0)
                                   ) {
  r = ssh_get_authentication_socket(&sock);
 } else {
  r = ssh_get_authentication_socket_path(forward_agent_sock_path, &sock);
 }
 if (r != 0) {
  if (r != -47)
   sshlog("clientloop.c", __func__, 1599, 1, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "ssh_get_authentication_socket");
  return 
        ((void *)0)
            ;
 }
 if ((r = ssh_agent_bind_hostkey(sock, ssh->kex->initial_hostkey,
     ssh->kex->session_id, ssh->kex->initial_sig, 1)) == 0)
  sshlog("clientloop.c", __func__, 1604, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "bound agent to hostkey");
 else
  sshlog("clientloop.c", __func__, 1606, 1, SYSLOG_LEVEL_DEBUG2, ssh_err(r), "ssh_agent_bind_hostkey");

 c = channel_new(ssh, "authentication agent connection",
     4, sock, sock, -1,
     (4*(16*1024)), (32*1024), 0,
     "authentication agent connection", 1);
 c->force_drain = 1;
 return c;
}

char *
client_request_tun_fwd(struct ssh *ssh, int tun_mode,
    int local_tun, int remote_tun, channel_open_fn *cb, void *cbctx)
{
 Channel *c;
 int r, fd;
 char *ifname = 
               ((void *)0)
                   ;

 if (tun_mode == 0x00)
  return 0;

 sshlog("clientloop.c", __func__, 1627, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Requesting tun unit %d in mode %d", local_tun, tun_mode);


 if ((fd = tun_open(local_tun, tun_mode, &ifname)) == -1) {
  sshlog("clientloop.c", __func__, 1631, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Tunnel device open failed.");
  return 
        ((void *)0)
            ;
 }
 sshlog("clientloop.c", __func__, 1634, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Tunnel forwarding using interface %s", ifname);

 c = channel_new(ssh, "tun", 3, fd, fd, -1,
     (64*(32*1024)), (32*1024), 0, "tun", 1);
 c->datagram = 1;


 if (options.tun_open == 0x01)
  channel_register_filter(ssh, c->self, sys_tun_infilter,
      sys_tun_outfilter, 
                        ((void *)0)
                            , 
                              ((void *)0)
                                  );


 if (cb != 
          ((void *)0)
              )
  channel_register_open_confirm(ssh, c->self, cb, cbctx);

 if ((r = sshpkt_start(ssh, 90)) != 0 ||
     (r = sshpkt_put_cstring(ssh, "tun@openssh.com")) != 0 ||
     (r = sshpkt_put_u32(ssh, c->self)) != 0 ||
     (r = sshpkt_put_u32(ssh, c->local_window_max)) != 0 ||
     (r = sshpkt_put_u32(ssh, c->local_maxpacket)) != 0 ||
     (r = sshpkt_put_u32(ssh, tun_mode)) != 0 ||
     (r = sshpkt_put_u32(ssh, remote_tun)) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  sshpkt_fatal(ssh, r, "%s: send reply", __func__);

 return ifname;
}


static int
client_input_channel_open(int type, u_int32_t seq, struct ssh *ssh)
{
 Channel *c = 
             ((void *)0)
                 ;
 char *ctype = 
              ((void *)0)
                  ;
 int r;
 u_int rchan;
 size_t len;
 u_int rmaxpack, rwindow;

 if ((r = sshpkt_get_cstring(ssh, &ctype, &len)) != 0 ||
     (r = sshpkt_get_u32(ssh, &rchan)) != 0 ||
     (r = sshpkt_get_u32(ssh, &rwindow)) != 0 ||
     (r = sshpkt_get_u32(ssh, &rmaxpack)) != 0)
  goto out;

 sshlog("clientloop.c", __func__, 1679, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "client_input_channel_open: ctype %s rchan %d win %d max %d", ctype, rchan, rwindow, rmaxpack)
                                     ;

 if (strcmp(ctype, "forwarded-tcpip") == 0) {
  c = client_request_forwarded_tcpip(ssh, ctype, rchan, rwindow,
      rmaxpack);
 } else if (strcmp(ctype, "forwarded-streamlocal@openssh.com") == 0) {
  c = client_request_forwarded_streamlocal(ssh, ctype, rchan);
 } else if (strcmp(ctype, "x11") == 0) {
  c = client_request_x11(ssh, ctype, rchan);
 } else if (strcmp(ctype, "auth-agent@openssh.com") == 0) {
  c = client_request_agent(ssh, ctype, rchan);
 }
 if (c != 
         ((void *)0) 
              && c->type == 16) {
  sshlog("clientloop.c", __func__, 1693, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "proxied to downstream: %s", ctype);
 } else if (c != 
                ((void *)0)
                    ) {
  sshlog("clientloop.c", __func__, 1695, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "confirm %s", ctype);
  c->remote_id = rchan;
  c->have_remote_id = 1;
  c->remote_window = rwindow;
  c->remote_maxpacket = rmaxpack;
  if (c->type != 12) {
   if ((r = sshpkt_start(ssh, 91)) != 0 ||
       (r = sshpkt_put_u32(ssh, c->remote_id)) != 0 ||
       (r = sshpkt_put_u32(ssh, c->self)) != 0 ||
       (r = sshpkt_put_u32(ssh, c->local_window)) != 0 ||
       (r = sshpkt_put_u32(ssh, c->local_maxpacket)) != 0 ||
       (r = sshpkt_send(ssh)) != 0)
    sshpkt_fatal(ssh, r, "%s: send reply", __func__);
  }
 } else {
  sshlog("clientloop.c", __func__, 1710, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "failure %s", ctype);
  if ((r = sshpkt_start(ssh, 92)) != 0 ||
      (r = sshpkt_put_u32(ssh, rchan)) != 0 ||
      (r = sshpkt_put_u32(ssh, 1)) != 0 ||
      (r = sshpkt_put_cstring(ssh, "open failed")) != 0 ||
      (r = sshpkt_put_cstring(ssh, "")) != 0 ||
      (r = sshpkt_send(ssh)) != 0)
   sshpkt_fatal(ssh, r, "%s: send failure", __func__);
 }
 r = 0;
 out:
 free(ctype);
 return r;
}

static int
client_input_channel_req(int type, u_int32_t seq, struct ssh *ssh)
{
 Channel *c = 
             ((void *)0)
                 ;
 char *rtype = 
              ((void *)0)
                  ;
 u_char reply;
 u_int id, exitval;
 int r, success = 0;

 if ((r = sshpkt_get_u32(ssh, &id)) != 0)
  return r;
 if (id <= 0x7fffffff)
  c = channel_lookup(ssh, id);
 if (channel_proxy_upstream(c, type, seq, ssh))
  return 0;
 if ((r = sshpkt_get_cstring(ssh, &rtype, 
                                         ((void *)0)
                                             )) != 0 ||
     (r = sshpkt_get_u8(ssh, &reply)) != 0)
  goto out;

 sshlog("clientloop.c", __func__, 1744, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "client_input_channel_req: channel %u rtype %s reply %d", id, rtype, reply)
                      ;

 if (c == 
         ((void *)0)
             ) {
  sshlog("clientloop.c", __func__, 1748, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "client_input_channel_req: channel %d: " "unknown channel", id)
                            ;
 } else if (strcmp(rtype, "eow@openssh.com") == 0) {
  if ((r = sshpkt_get_end(ssh)) != 0)
   goto out;
  chan_rcvd_eow(ssh, c);
 } else if (strcmp(rtype, "exit-status") == 0) {
  if ((r = sshpkt_get_u32(ssh, &exitval)) != 0)
   goto out;
  if (c->ctl_chan != -1) {
   mux_exit_message(ssh, c, exitval);
   success = 1;
  } else if ((int)id == session_ident) {

   success = 1;
   exit_status = exitval;
  } else {

   sshlog("clientloop.c", __func__, 1766, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "no sink for exit-status on channel %d", id)
          ;
  }
  if ((r = sshpkt_get_end(ssh)) != 0)
   goto out;
 }
 if (reply && c != 
                  ((void *)0) 
                       && !(c->flags & 0x01)) {
  if (!c->have_remote_id)
   sshfatal("clientloop.c", __func__, 1774, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "channel %d: no remote_id", c->self);
  if ((r = sshpkt_start(ssh, success ?
      99 : 100)) != 0 ||
      (r = sshpkt_put_u32(ssh, c->remote_id)) != 0 ||
      (r = sshpkt_send(ssh)) != 0)
   sshpkt_fatal(ssh, r, "%s: send failure", __func__);
 }
 r = 0;
 out:
 free(rtype);
 return r;
}

struct hostkeys_update_ctx {

 char *host_str, *ip_str;







 struct sshkey **keys;
 u_int *keys_match;
 int *keys_verified;
 size_t nkeys, nnew, nincomplete;






 struct sshkey **old_keys;
 size_t nold;


 int complex_hostspec;
 int ca_available;
 int old_key_seen;
 int other_name_seen;
};

static void
hostkeys_update_ctx_free(struct hostkeys_update_ctx *ctx)
{
 size_t i;

 if (ctx == 
           ((void *)0)
               )
  return;
 for (i = 0; i < ctx->nkeys; i++)
  sshkey_free(ctx->keys[i]);
 free(ctx->keys);
 free(ctx->keys_match);
 free(ctx->keys_verified);
 for (i = 0; i < ctx->nold; i++)
  sshkey_free(ctx->old_keys[i]);
 free(ctx->old_keys);
 free(ctx->host_str);
 free(ctx->ip_str);
 free(ctx);
}






static int
hostspec_is_complex(const char *hosts)
{
 char *cp;


 if (strchr(hosts, '*') != 
                          ((void *)0) 
                               || strchr(hosts, '?') != 
                                                        ((void *)0)
                                                            )
  return 1;

 if ((cp = strchr(hosts, ',')) == 
                                 ((void *)0)
                                     )
  return 0;

 if (strchr(cp + 1, ',') != 
                           ((void *)0)
                               )
  return 1;

 return 0;
}


static int
hostkeys_find(struct hostkey_foreach_line *l, void *_ctx)
{
 struct hostkeys_update_ctx *ctx = (struct hostkeys_update_ctx *)_ctx;
 size_t i;
 struct sshkey **tmp;

 if (l->key == 
              ((void *)0)
                  )
  return 0;
 if (l->status != 3) {

  for (i = 0; i < ctx->nkeys; i++) {
   if (sshkey_equal(l->key, ctx->keys[i])) {
    ctx->other_name_seen = 1;
    sshlog("clientloop.c", __func__, 1875, 1, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "found %s key under different " "name/addr at %s:%ld", sshkey_ssh_name(ctx->keys[i]), l->path, l->linenum)


                            ;
    return 0;
   }
  }
  return 0;
 }


 if (l->marker != MRK_NONE) {
  sshlog("clientloop.c", __func__, 1887, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "hostkeys file %s:%ld has CA/revocation marker", l->path, l->linenum)
                          ;
  ctx->complex_hostspec = 1;
  return 0;
 }


 if (ctx->ip_str != 
                   ((void *)0) 
                        && strchr(l->hosts, ',') != 
                                                    ((void *)0)
                                                        ) {
  if ((l->match & (1)) == 0) {

   ctx->other_name_seen = 1;
   sshlog("clientloop.c", __func__, 1898, 1, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "found address %s against different hostname " "at %s:%ld", ctx->ip_str, l->path, l->linenum)
                                                     ;
   return 0;
  } else if ((l->match & (1<<1)) == 0) {

   ctx->other_name_seen = 1;
   sshlog("clientloop.c", __func__, 1904, 1, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "found hostname %s against different address " "at %s:%ld", ctx->host_str, l->path, l->linenum)
                                                       ;
  }
 }





 if (hostspec_is_complex(l->hosts)) {
  sshlog("clientloop.c", __func__, 1914, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "hostkeys file %s:%ld complex host specification", l->path, l->linenum)
                          ;
  ctx->complex_hostspec = 1;
  return 0;
 }


 for (i = 0; i < ctx->nkeys; i++) {
  if (!sshkey_equal(l->key, ctx->keys[i]))
   continue;
  sshlog("clientloop.c", __func__, 1924, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "found %s key at %s:%ld", sshkey_ssh_name(ctx->keys[i]), l->path, l->linenum)
                                                         ;
  ctx->keys_match[i] |= l->match;
  return 0;
 }

 sshlog("clientloop.c", __func__, 1930, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "deprecated %s key at %s:%ld", sshkey_ssh_name(l->key), l->path, l->linenum)
                         ;
 if ((tmp = recallocarray(ctx->old_keys, ctx->nold, ctx->nold + 1,
     sizeof(*ctx->old_keys))) == 
                                ((void *)0)
                                    )
  sshfatal("clientloop.c", __func__, 1934, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "recallocarray failed nold = %zu", ctx->nold);
 ctx->old_keys = tmp;
 ctx->old_keys[ctx->nold++] = l->key;
 l->key = 
         ((void *)0)
             ;

 return 0;
}


static int
hostkeys_check_old(struct hostkey_foreach_line *l, void *_ctx)
{
 struct hostkeys_update_ctx *ctx = (struct hostkeys_update_ctx *)_ctx;
 size_t i;
 int hashed;


 if (l->status == 3 || l->key == 
                                                 ((void *)0)
                                                     )
  return 0;

 hashed = l->match & ((1<<2)|(1<<3));
 for (i = 0; i < ctx->nold; i++) {
  if (!sshkey_equal(l->key, ctx->old_keys[i]))
   continue;
  sshlog("clientloop.c", __func__, 1958, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "found deprecated %s key at %s:%ld as %s", sshkey_ssh_name(ctx->old_keys[i]), l->path, l->linenum, hashed ? "[HASHED]" : l->hosts)

                                     ;
  ctx->old_key_seen = 1;
  break;
 }
 return 0;
}






static int
check_old_keys_othernames(struct hostkeys_update_ctx *ctx)
{
 size_t i;
 int r;

 sshlog("clientloop.c", __func__, 1978, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "checking for %zu deprecated keys", ctx->nold);
 for (i = 0; i < options.num_user_hostfiles; i++) {
  sshlog("clientloop.c", __func__, 1980, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "searching %s for %s / %s", options.user_hostfiles[i], ctx->host_str, ctx->ip_str ? ctx->ip_str : "(none)")

                                           ;
  if ((r = hostkeys_foreach(options.user_hostfiles[i],
      hostkeys_check_old, ctx, ctx->host_str, ctx->ip_str,
      (1<<1), 0)) != 0) {
   if (r == -24 && 
                                   (*__errno_location ()) 
                                         == 
                                            2
                                                  ) {
    sshlog("clientloop.c", __func__, 1987, 1, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "hostkeys file %s does not exist", options.user_hostfiles[i])
                                  ;
    continue;
   }
   sshlog("clientloop.c", __func__, 1991, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "hostkeys_foreach failed for %s", options.user_hostfiles[i])
                                 ;
   return -1;
  }
 }
 return 0;
}

static void
hostkey_change_preamble(LogLevel loglevel)
{
 sshlog("clientloop.c", __func__, 2002, 0, loglevel, 
((void *)0)
, "The server has updated its host keys.");
 sshlog("clientloop.c", __func__, 2003, 0, loglevel, 
((void *)0)
, "These changes were verified by the server's " "existing trusted key.")
                             ;
}

static void
update_known_hosts(struct hostkeys_update_ctx *ctx)
{
 int r, was_raw = 0, first = 1;
 int asking = options.update_hostkeys == 2;
 LogLevel loglevel = asking ? SYSLOG_LEVEL_INFO : SYSLOG_LEVEL_VERBOSE;
 char *fp, *response;
 size_t i;
 struct stat sb;

 for (i = 0; i < ctx->nkeys; i++) {
  if (!ctx->keys_verified[i])
   continue;
  if ((fp = sshkey_fingerprint(ctx->keys[i],
      options.fingerprint_hash, SSH_FP_DEFAULT)) == 
                                                   ((void *)0)
                                                       )
   sshfatal("clientloop.c", __func__, 2022, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshkey_fingerprint failed");
  if (first && asking)
   hostkey_change_preamble(loglevel);
  sshlog("clientloop.c", __func__, 2025, 0, loglevel, 
 ((void *)0)
 , "Learned new hostkey: %s %s", sshkey_type(ctx->keys[i]), fp)
                                    ;
  first = 0;
  free(fp);
 }
 for (i = 0; i < ctx->nold; i++) {
  if ((fp = sshkey_fingerprint(ctx->old_keys[i],
      options.fingerprint_hash, SSH_FP_DEFAULT)) == 
                                                   ((void *)0)
                                                       )
   sshfatal("clientloop.c", __func__, 2033, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshkey_fingerprint failed");
  if (first && asking)
   hostkey_change_preamble(loglevel);
  sshlog("clientloop.c", __func__, 2036, 0, loglevel, 
 ((void *)0)
 , "Deprecating obsolete hostkey: %s %s", sshkey_type(ctx->old_keys[i]), fp)
                                        ;
  first = 0;
  free(fp);
 }
 if (options.update_hostkeys == 2) {
  if (get_saved_tio() != 
                        ((void *)0)
                            ) {
   leave_raw_mode(1);
   was_raw = 1;
  }
  response = 
            ((void *)0)
                ;
  for (i = 0; !quit_pending && i < 3; i++) {
   free(response);
   response = read_passphrase("Accept updated hostkeys? "
       "(yes/no): ", 0x0001);
   if (strcasecmp(response, "yes") == 0)
    break;
   else if (quit_pending || response == 
                                       ((void *)0) 
                                            ||
       strcasecmp(response, "no") == 0) {
    options.update_hostkeys = 0;
    break;
   } else {
    sshlog("clientloop.c", __func__, 2058, 0, loglevel, 
   ((void *)0)
   , "Please enter " "\"yes\" or \"no\"")
                            ;
   }
  }
  if (quit_pending || i >= 3 || response == 
                                           ((void *)0)
                                               )
   options.update_hostkeys = 0;
  free(response);
  if (was_raw)
   enter_raw_mode(1);
 }
 if (options.update_hostkeys == 0)
  return;





 for (i = 0; i < options.num_user_hostfiles; i++) {




  if (stat(options.user_hostfiles[i], &sb) != 0) {
   if (
      (*__errno_location ()) 
            == 
               2
                     ) {
    sshlog("clientloop.c", __func__, 2082, 1, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "known hosts file %s does not " "exist", options.user_hostfiles[i])
                                           ;
   } else {
    sshlog("clientloop.c", __func__, 2085, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "known hosts file %s " "inaccessible: %s", options.user_hostfiles[i], strerror(
   (*__errno_location ())
   ))

                                                   ;
   }
   continue;
  }
  if ((r = hostfile_replace_entries(options.user_hostfiles[i],
      ctx->host_str, ctx->ip_str,
      i == 0 ? ctx->keys : 
                          ((void *)0)
                              , i == 0 ? ctx->nkeys : 0,
      options.hash_known_hosts, 0,
      options.fingerprint_hash)) != 0) {
   sshlog("clientloop.c", __func__, 2096, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "hostfile_replace_entries failed for %s", options.user_hostfiles[i])
                                 ;
  }
 }
}

static void
client_global_hostkeys_private_confirm(struct ssh *ssh, int type,
    u_int32_t seq, void *_ctx)
{
 struct hostkeys_update_ctx *ctx = (struct hostkeys_update_ctx *)_ctx;
 size_t i, ndone;
 struct sshbuf *signdata;
 int r, plaintype;
 const u_char *sig;
 const char *rsa_kexalg = 
                         ((void *)0)
                             ;
 char *alg = 
            ((void *)0)
                ;
 size_t siglen;

 if (ctx->nnew == 0)
  sshfatal("clientloop.c", __func__, 2116, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ctx->nnew == 0");
 if (type != 81) {
  sshlog("clientloop.c", __func__, 2118, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Server failed to confirm ownership of " "private host keys")
                          ;
  hostkeys_update_ctx_free(ctx);
  return;
 }
 if (sshkey_type_plain(sshkey_type_from_name(
     ssh->kex->hostkey_alg)) == KEY_RSA)
  rsa_kexalg = ssh->kex->hostkey_alg;
 if ((signdata = sshbuf_new()) == 
                                 ((void *)0)
                                     )
  sshfatal("clientloop.c", __func__, 2127, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new failed");





 for (ndone = i = 0; i < ctx->nkeys; i++) {
  if (ctx->keys_match[i])
   continue;
  plaintype = sshkey_type_plain(ctx->keys[i]->type);

  sshbuf_reset(signdata);
  if ( (r = sshbuf_put_cstring(signdata,
      "hostkeys-prove-00@openssh.com")) != 0 ||
      (r = sshbuf_put_stringb(signdata,
      ssh->kex->session_id)) != 0 ||
      (r = sshkey_puts(ctx->keys[i], signdata)) != 0)
   sshfatal("clientloop.c", __func__, 2144, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "compose signdata");

  if ((r = sshpkt_get_string_direct(ssh, &sig, &siglen)) != 0) {
   sshlog("clientloop.c", __func__, 2147, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse sig");
   goto out;
  }
  if ((r = sshkey_get_sigtype(sig, siglen, &alg)) != 0) {
   sshlog("clientloop.c", __func__, 2151, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "server gave unintelligible signature " "for %s key %zu", sshkey_type(ctx->keys[i]), i)
                                                      ;
   goto out;
  }





  if (plaintype == KEY_RSA && rsa_kexalg == 
                                           ((void *)0) 
                                                &&
      match_pattern_list(alg, "rsa-sha2-512,rsa-sha2-256", 0) != 1) {
   sshlog("clientloop.c", __func__, 2162, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "server used untrusted RSA signature algorithm " "%s for key %zu, disregarding", alg, i)
                                              ;
   free(alg);

   sshkey_free(ctx->keys[i]);
   ctx->keys[i] = 
                 ((void *)0)
                     ;
   ndone++;
   continue;
  }
  sshlog("clientloop.c", __func__, 2171, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "verify %s key %zu using sigalg %s", sshkey_type(ctx->keys[i]), i, alg)
                                        ;
  free(alg);
  if ((r = sshkey_verify(ctx->keys[i], sig, siglen,
      sshbuf_ptr(signdata), sshbuf_len(signdata),
      plaintype == KEY_RSA ? rsa_kexalg : 
                                         ((void *)0)
                                             , 0, 
                                                  ((void *)0)
                                                      )) != 0) {
   sshlog("clientloop.c", __func__, 2177, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "server gave bad signature for %s key %zu", sshkey_type(ctx->keys[i]), i)
                                    ;
   goto out;
  }

  ctx->keys_verified[i] = 1;
  ndone++;
 }

 if (ndone != ctx->nnew)
  sshfatal("clientloop.c", __func__, 2187, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "ndone != ctx->nnew (%zu / %zu)", ndone, ctx->nnew);
 if ((r = sshpkt_get_end(ssh)) != 0) {
  sshlog("clientloop.c", __func__, 2189, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "protocol error");
  goto out;
 }


 update_known_hosts(ctx);
 out:
 hostkeys_update_ctx_free(ctx);
}





static int
key_accepted_by_hostkeyalgs(const struct sshkey *key)
{
 const char *ktype = sshkey_ssh_name(key);
 const char *hostkeyalgs = options.hostkeyalgorithms;

 if (key == 
           ((void *)0) 
                || key->type == KEY_UNSPEC)
  return 0;
 if (key->type == KEY_RSA &&
     (match_pattern_list("rsa-sha2-256", hostkeyalgs, 0) == 1 ||
     match_pattern_list("rsa-sha2-512", hostkeyalgs, 0) == 1))
  return 1;
 return match_pattern_list(ktype, hostkeyalgs, 0) == 1;
}






static int
client_input_hostkeys(struct ssh *ssh)
{
 const u_char *blob = 
                     ((void *)0)
                         ;
 size_t i, len = 0;
 struct sshbuf *buf = 
                     ((void *)0)
                         ;
 struct sshkey *key = 
                     ((void *)0)
                         , **tmp;
 int r;
 char *fp;
 static int hostkeys_seen = 0;
 extern struct sockaddr_storage hostaddr;
 struct hostkeys_update_ctx *ctx = 
                                  ((void *)0)
                                      ;
 u_int want;

 if (hostkeys_seen)
  sshfatal("clientloop.c", __func__, 2238, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "server already sent hostkeys");
 if (options.update_hostkeys == 2 &&
     options.batch_mode)
  return 1;
 if (!options.update_hostkeys || options.num_user_hostfiles <= 0)
  return 1;

 ctx = xcalloc(1, sizeof(*ctx));
 while (ssh_packet_remaining(ssh) > 0) {
  sshkey_free(key);
  key = 
       ((void *)0)
           ;
  if ((r = sshpkt_get_string_direct(ssh, &blob, &len)) != 0) {
   sshlog("clientloop.c", __func__, 2250, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse key");
   goto out;
  }
  if ((r = sshkey_from_blob(blob, len, &key)) != 0) {
   sshlog("clientloop.c", __func__, 2254, 1, r == -14 ? SYSLOG_LEVEL_DEBUG1 : SYSLOG_LEVEL_ERROR, ssh_err(r), "convert key")

                     ;
   continue;
  }
  fp = sshkey_fingerprint(key, options.fingerprint_hash,
      SSH_FP_DEFAULT);
  sshlog("clientloop.c", __func__, 2261, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "received %s key %s", sshkey_type(key), fp);
  free(fp);

  if (!key_accepted_by_hostkeyalgs(key)) {
   sshlog("clientloop.c", __func__, 2265, 1, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "%s key not permitted by " "HostkeyAlgorithms", sshkey_ssh_name(key))
                                                 ;
   continue;
  }

  if (sshkey_is_cert(key)) {
   sshlog("clientloop.c", __func__, 2271, 1, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "%s key is a certificate; skipping", sshkey_ssh_name(key))
                            ;
   continue;
  }

  for (i = 0; i < ctx->nkeys; i++) {
   if (sshkey_equal(key, ctx->keys[i])) {
    sshlog("clientloop.c", __func__, 2278, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "received duplicated %s host key", sshkey_ssh_name(key))
                             ;
    goto out;
   }
  }

  if ((tmp = recallocarray(ctx->keys, ctx->nkeys, ctx->nkeys + 1,
      sizeof(*ctx->keys))) == 
                             ((void *)0)
                                 )
   sshfatal("clientloop.c", __func__, 2286, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "recallocarray failed nkeys = %zu", ctx->nkeys)
                  ;
  ctx->keys = tmp;
  ctx->keys[ctx->nkeys++] = key;
  key = 
       ((void *)0)
           ;
 }

 if (ctx->nkeys == 0) {
  sshlog("clientloop.c", __func__, 2294, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "server sent no hostkeys");
  goto out;
 }

 if ((ctx->keys_match = calloc(ctx->nkeys,
     sizeof(*ctx->keys_match))) == 
                                  ((void *)0) 
                                       ||
     (ctx->keys_verified = calloc(ctx->nkeys,
     sizeof(*ctx->keys_verified))) == 
                                     ((void *)0)
                                         )
  sshfatal("clientloop.c", __func__, 2302, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "calloc failed");

 get_hostfile_hostname_ipaddr(host,
     options.check_host_ip ? (struct sockaddr *)&hostaddr : 
                                                           ((void *)0)
                                                               ,
     options.port, &ctx->host_str,
     options.check_host_ip ? &ctx->ip_str : 
                                           ((void *)0)
                                               );


 for (i = 0; i < options.num_user_hostfiles; i++) {
  sshlog("clientloop.c", __func__, 2311, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "searching %s for %s / %s", options.user_hostfiles[i], ctx->host_str, ctx->ip_str ? ctx->ip_str : "(none)")

                                           ;
  if ((r = hostkeys_foreach(options.user_hostfiles[i],
      hostkeys_find, ctx, ctx->host_str, ctx->ip_str,
      (1<<1), 0)) != 0) {
   if (r == -24 && 
                                   (*__errno_location ()) 
                                         == 
                                            2
                                                  ) {
    sshlog("clientloop.c", __func__, 2318, 1, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "hostkeys file %s does not exist", options.user_hostfiles[i])
                                  ;
    continue;
   }
   sshlog("clientloop.c", __func__, 2322, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "hostkeys_foreach failed for %s", options.user_hostfiles[i])
                                 ;
   goto out;
  }
 }


 ctx->nnew = ctx->nincomplete = 0;
 want = (1) | ( options.check_host_ip ? (1<<1) : 0);
 for (i = 0; i < ctx->nkeys; i++) {
  if (ctx->keys_match[i] == 0)
   ctx->nnew++;
  if ((ctx->keys_match[i] & want) != want)
   ctx->nincomplete++;
 }

 sshlog("clientloop.c", __func__, 2338, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "%zu server keys: %zu new, %zu retained, " "%zu incomplete match. %zu to remove", ctx->nkeys, ctx->nnew, ctx->nkeys - ctx->nnew - ctx->nincomplete, ctx->nincomplete, ctx->nold)


                                 ;

 if (ctx->nnew == 0 && ctx->nold == 0) {
  sshlog("clientloop.c", __func__, 2344, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "no new or deprecated keys from server");
  goto out;
 }


 if (ctx->complex_hostspec) {
  sshlog("clientloop.c", __func__, 2350, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "CA/revocation marker, manual host list or wildcard " "host pattern found, skipping UserKnownHostsFile update")
                                                               ;
  goto out;
 }
 if (ctx->other_name_seen) {
  sshlog("clientloop.c", __func__, 2355, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "host key found matching a different name/address, " "skipping UserKnownHostsFile update")
                                           ;
  goto out;
 }







 if (ctx->nold != 0) {
  if (check_old_keys_othernames(ctx) != 0)
   goto out;
  if (ctx->old_key_seen) {
   sshlog("clientloop.c", __func__, 2370, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "key(s) for %s%s%s exist under other names; " "skipping UserKnownHostsFile update", ctx->host_str, ctx->ip_str == 
  ((void *)0) 
  ? "" : ",", ctx->ip_str == 
  ((void *)0) 
  ? "" : ctx->ip_str)


                                              ;
   goto out;
  }
 }

 if (ctx->nnew == 0) {





  update_known_hosts(ctx);
  goto out;
 }




 sshlog("clientloop.c", __func__, 2391, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "asking server to prove ownership for %zu keys", ctx->nnew);
 if ((r = sshpkt_start(ssh, 80)) != 0 ||
     (r = sshpkt_put_cstring(ssh,
     "hostkeys-prove-00@openssh.com")) != 0 ||
     (r = sshpkt_put_u8(ssh, 1)) != 0)
  sshfatal("clientloop.c", __func__, 2396, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "prepare hostkeys-prove");
 if ((buf = sshbuf_new()) == 
                            ((void *)0)
                                )
  sshfatal("clientloop.c", __func__, 2398, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshbuf_new");
 for (i = 0; i < ctx->nkeys; i++) {
  if (ctx->keys_match[i])
   continue;
  sshbuf_reset(buf);
  if ((r = sshkey_putb(ctx->keys[i], buf)) != 0 ||
      (r = sshpkt_put_stringb(ssh, buf)) != 0)
   sshfatal("clientloop.c", __func__, 2405, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "assemble hostkeys-prove");
 }
 if ((r = sshpkt_send(ssh)) != 0)
  sshfatal("clientloop.c", __func__, 2408, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send hostkeys-prove");
 client_register_global_confirm(
     client_global_hostkeys_private_confirm, ctx);
 ctx = 
      ((void *)0)
          ;


 out:
 hostkeys_update_ctx_free(ctx);
 sshkey_free(key);
 sshbuf_free(buf);




 return 1;
}

static int
client_input_global_request(int type, u_int32_t seq, struct ssh *ssh)
{
 char *rtype;
 u_char want_reply;
 int r, success = 0;

 if ((r = sshpkt_get_cstring(ssh, &rtype, 
                                         ((void *)0)
                                             )) != 0 ||
     (r = sshpkt_get_u8(ssh, &want_reply)) != 0)
  goto out;
 sshlog("clientloop.c", __func__, 2435, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "client_input_global_request: rtype %s want_reply %d", rtype, want_reply)
                       ;
 if (strcmp(rtype, "hostkeys-00@openssh.com") == 0)
  success = client_input_hostkeys(ssh);
 if (want_reply) {
  if ((r = sshpkt_start(ssh, success ? 81 :
      82)) != 0 ||
      (r = sshpkt_send(ssh)) != 0 ||
      (r = ssh_packet_write_wait(ssh)) != 0)
   goto out;
 }
 r = 0;
 out:
 free(rtype);
 return r;
}

static void
client_send_env(struct ssh *ssh, int id, const char *name, const char *val)
{
 int r;

 sshlog("clientloop.c", __func__, 2457, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "channel %d: setting env %s = \"%s\"", id, name, val);
 channel_request_start(ssh, id, "env", 0);
 if ((r = sshpkt_put_cstring(ssh, name)) != 0 ||
     (r = sshpkt_put_cstring(ssh, val)) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  sshfatal("clientloop.c", __func__, 2462, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send setenv");
}

void
client_session2_setup(struct ssh *ssh, int id, int want_tty, int want_subsystem,
    const char *term, struct termios *tiop, int in_fd, struct sshbuf *cmd,
    char **env)
{
 size_t i, j, len;
 int matched, r;
 char *name, *val;
 Channel *c = 
             ((void *)0)
                 ;

 sshlog("clientloop.c", __func__, 2475, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "id %d", id);

 if ((c = channel_lookup(ssh, id)) == 
                                     ((void *)0)
                                         )
  sshfatal("clientloop.c", __func__, 2478, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel %d: unknown channel", id);

 ssh_packet_set_interactive(ssh, want_tty,
     options.ip_qos_interactive, options.ip_qos_bulk);

 if (want_tty) {
  struct winsize ws;


  if (ioctl(in_fd, 
                  0x5413
                            , &ws) == -1)
   memset(&ws, 0, sizeof(ws));

  channel_request_start(ssh, id, "pty-req", 1);
  client_expect_confirm(ssh, id, "PTY allocation", CONFIRM_TTY);
  if ((r = sshpkt_put_cstring(ssh, term != 
                                          ((void *)0) 
                                               ? term : ""))
      != 0 ||
      (r = sshpkt_put_u32(ssh, (u_int)ws.ws_col)) != 0 ||
      (r = sshpkt_put_u32(ssh, (u_int)ws.ws_row)) != 0 ||
      (r = sshpkt_put_u32(ssh, (u_int)ws.ws_xpixel)) != 0 ||
      (r = sshpkt_put_u32(ssh, (u_int)ws.ws_ypixel)) != 0)
   sshfatal("clientloop.c", __func__, 2498, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "build pty-req");
  if (tiop == 
             ((void *)0)
                 )
   tiop = get_saved_tio();
  ssh_tty_make_modes(ssh, -1, tiop);
  if ((r = sshpkt_send(ssh)) != 0)
   sshfatal("clientloop.c", __func__, 2503, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send pty-req");

  c->client_tty = 1;
 }


 if (options.num_send_env != 0 && env != 
                                        ((void *)0)
                                            ) {
  sshlog("clientloop.c", __func__, 2510, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Sending environment.");
  for (i = 0; env[i] != 
                       ((void *)0)
                           ; i++) {

   name = xstrdup(env[i]);
   if ((val = strchr(name, '=')) == 
                                   ((void *)0)
                                       ) {
    free(name);
    continue;
   }
   *val++ = '\0';

   matched = 0;
   for (j = 0; j < options.num_send_env; j++) {
    if (match_pattern(name, options.send_env[j])) {
     matched = 1;
     break;
    }
   }
   if (!matched) {
    sshlog("clientloop.c", __func__, 2528, 0, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "Ignored env %s", name);
    free(name);
    continue;
   }
   client_send_env(ssh, id, name, val);
   free(name);
  }
 }
 for (i = 0; i < options.num_setenv; i++) {

  name = xstrdup(options.setenv[i]);
  if ((val = strchr(name, '=')) == 
                                  ((void *)0)
                                      ) {
   free(name);
   continue;
  }
  *val++ = '\0';
  client_send_env(ssh, id, name, val);
  free(name);
 }

 len = sshbuf_len(cmd);
 if (len > 0) {
  if (len > 900)
   len = 900;
  if (want_subsystem) {
   sshlog("clientloop.c", __func__, 2553, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Sending subsystem: %.*s", (int)len, (const u_char*)sshbuf_ptr(cmd))
                                                ;
   channel_request_start(ssh, id, "subsystem", 1);
   client_expect_confirm(ssh, id, "subsystem",
       CONFIRM_CLOSE);
  } else {
   sshlog("clientloop.c", __func__, 2559, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Sending command: %.*s", (int)len, (const u_char*)sshbuf_ptr(cmd))
                                                ;
   channel_request_start(ssh, id, "exec", 1);
   client_expect_confirm(ssh, id, "exec", CONFIRM_CLOSE);
  }
  if ((r = sshpkt_put_stringb(ssh, cmd)) != 0 ||
      (r = sshpkt_send(ssh)) != 0)
   sshfatal("clientloop.c", __func__, 2566, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send command");
 } else {
  channel_request_start(ssh, id, "shell", 1);
  client_expect_confirm(ssh, id, "shell", CONFIRM_CLOSE);
  if ((r = sshpkt_send(ssh)) != 0)
   sshfatal("clientloop.c", __func__, 2571, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send shell");
 }
}

static void
client_init_dispatch(struct ssh *ssh)
{
 ssh_dispatch_init(ssh, &dispatch_protocol_error);

 ssh_dispatch_set(ssh, 97, &channel_input_oclose);
 ssh_dispatch_set(ssh, 94, &channel_input_data);
 ssh_dispatch_set(ssh, 96, &channel_input_ieof);
 ssh_dispatch_set(ssh, 95, &channel_input_extended_data);
 ssh_dispatch_set(ssh, 90, &client_input_channel_open);
 ssh_dispatch_set(ssh, 91, &channel_input_open_confirmation);
 ssh_dispatch_set(ssh, 92, &channel_input_open_failure);
 ssh_dispatch_set(ssh, 98, &client_input_channel_req);
 ssh_dispatch_set(ssh, 93, &channel_input_window_adjust);
 ssh_dispatch_set(ssh, 99, &channel_input_status_confirm);
 ssh_dispatch_set(ssh, 100, &channel_input_status_confirm);
 ssh_dispatch_set(ssh, 80, &client_input_global_request);


 ssh_dispatch_set(ssh, 20, &kex_input_kexinit);


 ssh_dispatch_set(ssh, 82, &client_global_request_reply);
 ssh_dispatch_set(ssh, 81, &client_global_request_reply);
}

void
client_stop_mux(void)
{
 if (options.control_path != 
                            ((void *)0) 
                                 && muxserver_sock != -1)
  unlink(options.control_path);




 if (options.control_persist || options.session_type == 0) {
  session_closed = 1;
  setproctitle("[stopped mux]");
 }
}


void
cleanup_exit(int i)
{
 leave_raw_mode(options.request_tty == 3);
 if (options.control_path != 
                            ((void *)0) 
                                 && muxserver_sock != -1)
  unlink(options.control_path);
 ssh_kill_proxy_command();
 _exit(i);
}
