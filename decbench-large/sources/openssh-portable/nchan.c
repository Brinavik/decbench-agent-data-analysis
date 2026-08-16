











































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
static void chan_send_eof2(struct ssh *, Channel *);
static void chan_send_eow2(struct ssh *, Channel *);


static void chan_shutdown_write(struct ssh *, Channel *);
static void chan_shutdown_read(struct ssh *, Channel *);
static void chan_shutdown_extended_read(struct ssh *, Channel *);

static const char * const ostates[] = {
 "open", "drain", "wait_ieof", "closed",
};
static const char * const istates[] = {
 "open", "drain", "wait_oclose", "closed",
};

static void
chan_set_istate(Channel *c, u_int next)
{
 if (c->istate > 3 || next > 3)
  sshfatal("nchan.c", __func__, 96, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "chan_set_istate: bad state %d -> %d", c->istate, next);
 sshlog("nchan.c", __func__, 97, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: input %s -> %s", c->self, istates[c->istate], istates[next])
                   ;
 c->istate = next;
}

static void
chan_set_ostate(Channel *c, u_int next)
{
 if (c->ostate > 3 || next > 3)
  sshfatal("nchan.c", __func__, 106, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "chan_set_ostate: bad state %d -> %d", c->ostate, next);
 sshlog("nchan.c", __func__, 107, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: output %s -> %s", c->self, ostates[c->ostate], ostates[next])
                   ;
 c->ostate = next;
}

void
chan_read_failed(struct ssh *ssh, Channel *c)
{
 sshlog("nchan.c", __func__, 115, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: read failed", c->self);
 switch (c->istate) {
 case 0:
  chan_shutdown_read(ssh, c);
  chan_set_istate(c, 1);
  break;
 default:
  sshlog("nchan.c", __func__, 122, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "channel %d: chan_read_failed for istate %d", c->self, c->istate)
                         ;
  break;
 }
}

void
chan_ibuf_empty(struct ssh *ssh, Channel *c)
{
 sshlog("nchan.c", __func__, 131, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: ibuf empty", c->self);
 if (sshbuf_len(c->input)) {
  sshlog("nchan.c", __func__, 133, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "channel %d: chan_ibuf_empty for non empty buffer", c->self)
              ;
  return;
 }
 switch (c->istate) {
 case 1:
  if (!(c->flags & (0x01|0x10)))
   chan_send_eof2(ssh, c);
  chan_set_istate(c, 3);
  break;
 default:
  sshlog("nchan.c", __func__, 144, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "channel %d: chan_ibuf_empty for istate %d", c->self, c->istate)
                         ;
  break;
 }
}

void
chan_obuf_empty(struct ssh *ssh, Channel *c)
{
 sshlog("nchan.c", __func__, 153, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: obuf empty", c->self);
 if (sshbuf_len(c->output)) {
  sshlog("nchan.c", __func__, 155, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "channel %d: chan_obuf_empty for non empty buffer", c->self)
              ;
  return;
 }
 switch (c->ostate) {
 case 1:
  chan_shutdown_write(ssh, c);
  chan_set_ostate(c, 3);
  break;
 default:
  sshlog("nchan.c", __func__, 165, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "channel %d: internal error: obuf_empty for ostate %d", c->self, c->ostate)
                         ;
  break;
 }
}

void
chan_rcvd_eow(struct ssh *ssh, Channel *c)
{
 sshlog("nchan.c", __func__, 174, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: rcvd eow", c->self);
 switch (c->istate) {
 case 0:
  chan_shutdown_read(ssh, c);
  chan_set_istate(c, 3);
  break;
 }
}

static void
chan_send_eof2(struct ssh *ssh, Channel *c)
{
 int r;

 sshlog("nchan.c", __func__, 188, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: send eof", c->self);
 switch (c->istate) {
 case 1:
  if (!c->have_remote_id)
   sshfatal("nchan.c", __func__, 192, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "channel %d: no remote_id", c->self);
  if ((r = sshpkt_start(ssh, 96)) != 0 ||
      (r = sshpkt_put_u32(ssh, c->remote_id)) != 0 ||
      (r = sshpkt_send(ssh)) != 0)
   sshfatal("nchan.c", __func__, 196, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send CHANNEL_EOF");
  c->flags |= 0x04;
  break;
 default:
  sshlog("nchan.c", __func__, 200, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "channel %d: cannot send eof for istate %d", c->self, c->istate)
                         ;
  break;
 }
}

static void
chan_send_close2(struct ssh *ssh, Channel *c)
{
 int r;

 sshlog("nchan.c", __func__, 211, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: send close", c->self);
 if (c->ostate != 3 ||
     c->istate != 3) {
  sshlog("nchan.c", __func__, 214, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "channel %d: cannot send close for istate/ostate %d/%d", c->self, c->istate, c->ostate)
                                    ;
 } else if (c->flags & 0x01) {
  sshlog("nchan.c", __func__, 217, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "channel %d: already sent close", c->self);
 } else {
  if (!c->have_remote_id)
   sshfatal("nchan.c", __func__, 220, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "channel %d: no remote_id", c->self);
  if ((r = sshpkt_start(ssh, 97)) != 0 ||
      (r = sshpkt_put_u32(ssh, c->remote_id)) != 0 ||
      (r = sshpkt_send(ssh)) != 0)
   sshfatal("nchan.c", __func__, 224, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send CHANNEL_EOF");
  c->flags |= 0x01;
 }
}

static void
chan_send_eow2(struct ssh *ssh, Channel *c)
{
 int r;

 sshlog("nchan.c", __func__, 234, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: send eow", c->self);
 if (c->ostate == 3) {
  sshlog("nchan.c", __func__, 236, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "channel %d: must not sent eow on closed output", c->self)
              ;
  return;
 }
 if (!(ssh->compat & 0x04000000))
  return;
 if (!c->have_remote_id)
  sshfatal("nchan.c", __func__, 243, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "channel %d: no remote_id", c->self);
 if ((r = sshpkt_start(ssh, 98)) != 0 ||
     (r = sshpkt_put_u32(ssh, c->remote_id)) != 0 ||
     (r = sshpkt_put_cstring(ssh, "eow@openssh.com")) != 0 ||
     (r = sshpkt_put_u8(ssh, 0)) != 0 ||
     (r = sshpkt_send(ssh)) != 0)
  sshfatal("nchan.c", __func__, 249, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send CHANNEL_EOF");
}



void
chan_rcvd_ieof(struct ssh *ssh, Channel *c)
{
 sshlog("nchan.c", __func__, 257, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: rcvd eof", c->self);
 c->flags |= 0x08;
 if (c->ostate == 0)
  chan_set_ostate(c, 1);
 if (c->ostate == 1 &&
     sshbuf_len(c->output) == 0 &&
     !(c->extended_usage == 2 && c->efd != -1 && (!(c->flags & (0x08|0x02)) || sshbuf_len(c->extended) > 0)))
  chan_obuf_empty(ssh, c);
}

void
chan_rcvd_oclose(struct ssh *ssh, Channel *c)
{
 sshlog("nchan.c", __func__, 270, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: rcvd close", c->self);
 if (!(c->flags & 0x10)) {
  if (c->flags & 0x02)
   sshlog("nchan.c", __func__, 273, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "channel %d: protocol error: close rcvd twice", c->self)
               ;
  c->flags |= 0x02;
 }
 if (c->type == 10) {

  chan_set_ostate(c, 3);
  chan_set_istate(c, 3);
  return;
 }
 switch (c->ostate) {
 case 0:




  chan_set_ostate(c, 1);
  break;
 }
 switch (c->istate) {
 case 0:
  chan_shutdown_read(ssh, c);
  chan_shutdown_extended_read(ssh, c);
  chan_set_istate(c, 3);
  break;
 case 1:
  if (!(c->flags & 0x10))
   chan_send_eof2(ssh, c);
  chan_shutdown_extended_read(ssh, c);
  chan_set_istate(c, 3);
  break;
 }
}

void
chan_write_failed(struct ssh *ssh, Channel *c)
{
 sshlog("nchan.c", __func__, 310, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: write failed", c->self);
 switch (c->ostate) {
 case 0:
 case 1:
  chan_shutdown_write(ssh, c);
  if (strcmp(c->ctype, "session") == 0)
   chan_send_eow2(ssh, c);
  chan_set_ostate(c, 3);
  break;
 default:
  sshlog("nchan.c", __func__, 320, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "channel %d: chan_write_failed for ostate %d", c->self, c->ostate)
                         ;
  break;
 }
}

void
chan_mark_dead(struct ssh *ssh, Channel *c)
{
 c->type = 14;
}

int
chan_is_dead(struct ssh *ssh, Channel *c, int do_send)
{
 if (c->type == 14) {
  sshlog("nchan.c", __func__, 336, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: zombie", c->self);
  return 1;
 }
 if (c->istate != 3 || c->ostate != 3)
  return 0;
 if ((ssh->compat & 0x00200000) &&
     c->extended_usage == 2 &&
     c->efd != -1 &&
     sshbuf_len(c->extended) > 0) {
  sshlog("nchan.c", __func__, 345, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: active efd: %d len %zu", c->self, c->efd, sshbuf_len(c->extended))
                                               ;
  return 0;
 }
 if (c->flags & 0x10) {
  sshlog("nchan.c", __func__, 350, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: is dead (local)", c->self);
  return 1;
 }
 if (!(c->flags & 0x01)) {
  if (do_send) {
   chan_send_close2(ssh, c);
  } else {

   if (c->flags & 0x02) {
    sshlog("nchan.c", __func__, 359, 0, SYSLOG_LEVEL_DEBUG2, 
   ((void *)0)
   , "channel %d: almost dead", c->self)
                ;
    return 1;
   }
  }
 }
 if ((c->flags & 0x01) &&
     (c->flags & 0x02)) {
  sshlog("nchan.c", __func__, 367, 0, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "channel %d: is dead", c->self);
  return 1;
 }
 return 0;
}


static void
chan_shutdown_write(struct ssh *ssh, Channel *c)
{
 sshbuf_reset(c->output);
 if (c->type == 10)
  return;

 sshlog("nchan.c", __func__, 381, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: (i%d o%d sock %d wfd %d efd %d [%s])", c->self, c->istate, c->ostate, c->sock, c->wfd, c->efd, channel_format_extended_usage(c))

                                      ;
 if (c->sock != -1) {
  if (shutdown(c->sock, 
                       SHUT_WR
                              ) == -1) {
   sshlog("nchan.c", __func__, 386, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "channel %d: shutdown() failed for " "fd %d [i%d o%d]: %.100s", c->self, c->sock, c->istate, c->ostate, strerror(
  (*__errno_location ())
  ))

                                             ;
  }
 } else {
  if (channel_close_fd(ssh, c, &c->wfd) < 0) {
   sshlog("nchan.c", __func__, 392, 1, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "channel %d: close() failed for " "fd %d [i%d o%d]: %.100s", c->self, c->wfd, c->istate, c->ostate, strerror(
  (*__errno_location ())
  ))

                                             ;
  }
 }
}

static void
chan_shutdown_read(struct ssh *ssh, Channel *c)
{
 if (c->type == 10)
  return;
 sshlog("nchan.c", __func__, 404, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "channel %d: (i%d o%d sock %d wfd %d efd %d [%s])", c->self, c->istate, c->ostate, c->sock, c->rfd, c->efd, channel_format_extended_usage(c))

                                      ;
 if (c->sock != -1) {





  if (shutdown(c->sock, 
                       SHUT_RD
                              ) == -1 && 
                                         (*__errno_location ()) 
                                               != 
                                                  107
                                                          ) {
   sshlog("nchan.c", __func__, 414, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "channel %d: shutdown() failed for " "fd %d [i%d o%d]: %.100s", c->self, c->sock, c->istate, c->ostate, strerror(
  (*__errno_location ())
  ))

                                             ;
  }
 } else {
  if (channel_close_fd(ssh, c, &c->rfd) < 0) {
   sshlog("nchan.c", __func__, 420, 1, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "channel %d: close() failed for " "fd %d [i%d o%d]: %.100s", c->self, c->rfd, c->istate, c->ostate, strerror(
  (*__errno_location ())
  ))

                                             ;
  }
 }
}

static void
chan_shutdown_extended_read(struct ssh *ssh, Channel *c)
{
 if (c->type == 10 || c->efd == -1)
  return;
 if (c->extended_usage != 1 &&
     c->extended_usage != 0)
  return;
 sshlog("nchan.c", __func__, 435, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "channel %d: (i%d o%d sock %d wfd %d efd %d [%s])", c->self, c->istate, c->ostate, c->sock, c->rfd, c->efd, channel_format_extended_usage(c))

                                      ;
 if (channel_close_fd(ssh, c, &c->efd) < 0) {
  sshlog("nchan.c", __func__, 439, 1, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "channel %d: close() failed for " "extended fd %d [i%d o%d]: %.100s", c->self, c->efd, c->istate, c->ostate, strerror(
 (*__errno_location ())
 ))

                                            ;
 }
}
