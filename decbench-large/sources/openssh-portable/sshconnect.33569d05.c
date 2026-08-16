











































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
enum sshfp_types {
 SSHFP_KEY_RESERVED = 0,
 SSHFP_KEY_RSA = 1,
 SSHFP_KEY_DSA = 2,
 SSHFP_KEY_ECDSA = 3,
 SSHFP_KEY_ED25519 = 4,
 SSHFP_KEY_XMSS = 5
};

enum sshfp_hashes {
 SSHFP_HASH_RESERVED = 0,
 SSHFP_HASH_SHA1 = 1,
 SSHFP_HASH_SHA256 = 2,
 SSHFP_HASH_MAX = 3
};
int verify_host_key_dns(const char *, struct sockaddr *,
    struct sshkey *, int *);
int export_dns_rr(const char *, struct sshkey *, FILE *, int);
int mm_send_fd(int, int);
int mm_receive_fd(int);
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

struct sshkey *previous_host_key = 
                                  ((void *)0)
                                      ;

static int matching_host_key_dns = 0;

static pid_t proxy_command_pid = 0;


extern int debug_flag;
extern Options options;
extern char *__progname;

static int show_other_keys(struct hostkeys *, struct sshkey *);
static void warn_changed_key(struct sshkey *);


static char *
expand_proxy_command(const char *proxy_command, const char *user,
    const char *host, const char *host_arg, int port)
{
 char *tmp, *ret, strport[
                         32
                                   ];
 const char *keyalias = options.host_key_alias ?
     options.host_key_alias : host_arg;

 snprintf(strport, sizeof strport, "%d", port);
 xasprintf(&tmp, "exec %s", proxy_command);
 ret = percent_expand(tmp,
     "h", host,
     "k", keyalias,
     "n", host_arg,
     "p", strport,
     "r", options.user,
     (char *)
            ((void *)0)
                );
 free(tmp);
 return ret;
}





static int
ssh_proxy_fdpass_connect(struct ssh *ssh, const char *host,
    const char *host_arg, u_short port, const char *proxy_command)
{
 char *command_string;
 int sp[2], sock;
 pid_t pid;
 char *shell;

 if ((shell = getenv("SHELL")) == 
                                 ((void *)0)
                                     )
  shell = 
         "/bin/sh"
                     ;

 if (socketpair(
               1
                      , 
                        SOCK_STREAM
                                   , 0, sp) == -1)
  sshfatal("sshconnect.c", __func__, 126, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Could not create socketpair to communicate with " "proxy dialer: %.100s", strerror(
 (*__errno_location ())
 ))
                                              ;

 command_string = expand_proxy_command(proxy_command, options.user,
     host, host_arg, port);
 sshlog("sshconnect.c", __func__, 131, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Executing proxy dialer command: %.500s", command_string);


 if ((pid = fork()) == 0) {
  char *argv[10];

  close(sp[1]);

  if (sp[0] != 0) {
   if (dup2(sp[0], 0) == -1)
    perror("dup2 stdin");
  }
  if (sp[0] != 1) {
   if (dup2(sp[0], 1) == -1)
    perror("dup2 stdout");
  }
  if (sp[0] >= 2)
   close(sp[0]);





  if (!debug_flag && options.control_path != 
                                            ((void *)0) 
                                                 &&
      options.control_persist && stdfd_devnull(0, 0, 1) == -1)
   sshlog("sshconnect.c", __func__, 156, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "stdfd_devnull failed");

  argv[0] = shell;
  argv[1] = "-c";
  argv[2] = command_string;
  argv[3] = 
           ((void *)0)
               ;





  execv(argv[0], argv);
  perror(argv[0]);
  exit(1);
 }

 if (pid == -1)
  sshfatal("sshconnect.c", __func__, 173, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "fork failed: %.100s", strerror(
 (*__errno_location ())
 ));
 close(sp[0]);
 free(command_string);

 if ((sock = mm_receive_fd(sp[1])) == -1)
  sshfatal("sshconnect.c", __func__, 178, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "proxy dialer did not pass back a connection");
 close(sp[1]);

 while (waitpid(pid, 
                    ((void *)0)
                        , 0) == -1)
  if (
     (*__errno_location ()) 
           != 
              4
                   )
   sshfatal("sshconnect.c", __func__, 183, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Couldn't wait for child: %s", strerror(
  (*__errno_location ())
  ));


 if (ssh_packet_set_connection(ssh, sock, sock) == 
                                                  ((void *)0)
                                                      )
  return -1;

 return 0;
}




static int
ssh_proxy_connect(struct ssh *ssh, const char *host, const char *host_arg,
    u_short port, const char *proxy_command)
{
 char *command_string;
 int pin[2], pout[2];
 pid_t pid;
 char *shell;

 if ((shell = getenv("SHELL")) == 
                                 ((void *)0) 
                                      || *shell == '\0')
  shell = 
         "/bin/sh"
                     ;


 if (pipe(pin) == -1 || pipe(pout) == -1)
  sshfatal("sshconnect.c", __func__, 209, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "Could not create pipes to communicate with the proxy: %.100s", strerror(
 (*__errno_location ())
 ))
                      ;

 command_string = expand_proxy_command(proxy_command, options.user,
     host, host_arg, port);
 sshlog("sshconnect.c", __func__, 214, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Executing proxy command: %.500s", command_string);


 if ((pid = fork()) == 0) {
  char *argv[10];


  close(pin[1]);
  if (pin[0] != 0) {
   if (dup2(pin[0], 0) == -1)
    perror("dup2 stdin");
   close(pin[0]);
  }
  close(pout[0]);
  if (dup2(pout[1], 1) == -1)
   perror("dup2 stdout");

  close(pout[1]);





  if (!debug_flag && options.control_path != 
                                            ((void *)0) 
                                                 &&
      options.control_persist && stdfd_devnull(0, 0, 1) == -1)
   sshlog("sshconnect.c", __func__, 239, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "stdfd_devnull failed");

  argv[0] = shell;
  argv[1] = "-c";
  argv[2] = command_string;
  argv[3] = 
           ((void *)0)
               ;





  ssh_signal(
            13
                   , 
                     ((__sighandler_t) 0)
                            );
  execv(argv[0], argv);
  perror(argv[0]);
  exit(1);
 }

 if (pid == -1)
  sshfatal("sshconnect.c", __func__, 257, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "fork failed: %.100s", strerror(
 (*__errno_location ())
 ));
 else
  proxy_command_pid = pid;


 close(pin[0]);
 close(pout[1]);


 free(command_string);


 if (ssh_packet_set_connection(ssh, pout[0], pin[1]) == 
                                                       ((void *)0)
                                                           )
  return -1;

 return 0;
}

void
ssh_kill_proxy_command(void)
{




 if (proxy_command_pid > 1)
  kill(proxy_command_pid, 
                         1
                               );
}







static int
check_ifaddrs(const char *ifname, int af, const struct ifaddrs *ifaddrs,
    struct sockaddr_storage *resultp, socklen_t *rlenp)
{
 struct sockaddr_in6 *sa6;
 struct sockaddr_in *sa;
 struct in6_addr *v6addr;
 const struct ifaddrs *ifa;
 int allow_local;





 for (allow_local = 0; allow_local < 2; allow_local++) {
  for (ifa = ifaddrs; ifa != 
                            ((void *)0)
                                ; ifa = ifa->ifa_next) {
   if (ifa->ifa_addr == 
                       ((void *)0) 
                            || ifa->ifa_name == 
                                                ((void *)0) 
                                                     ||
       (ifa->ifa_flags & 
                        IFF_UP
                              ) == 0 ||
       ifa->ifa_addr->sa_family != af ||
       strcmp(ifa->ifa_name, options.bind_interface) != 0)
    continue;
   switch (ifa->ifa_addr->sa_family) {
   case 
       2
              :
    sa = (struct sockaddr_in *)ifa->ifa_addr;
    if (!allow_local && sa->sin_addr.s_addr ==
        
       __bswap_32 (((in_addr_t) 0x7f000001))
                             )
     continue;
    if (*rlenp < sizeof(struct sockaddr_in)) {
     sshlog("sshconnect.c", __func__, 320, 1, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "v4 addr doesn't fit");
     return -1;
    }
    *rlenp = sizeof(struct sockaddr_in);
    memcpy(resultp, sa, *rlenp);
    return 0;
   case 
       10
               :
    sa6 = (struct sockaddr_in6 *)ifa->ifa_addr;
    v6addr = &sa6->sin6_addr;
    if (!allow_local &&
        (
        (__extension__ ({ const struct in6_addr *__a = (const struct in6_addr *) (
        v6addr
        ); (__a->__in6_u.__u6_addr32[0] & __bswap_32 (0xffc00000)) == __bswap_32 (0xfe800000); })) 
                                      ||
        
       (__extension__ ({ const struct in6_addr *__a = (const struct in6_addr *) (
       v6addr
       ); __a->__in6_u.__u6_addr32[0] == 0 && __a->__in6_u.__u6_addr32[1] == 0 && __a->__in6_u.__u6_addr32[2] == 0 && __a->__in6_u.__u6_addr32[3] == __bswap_32 (1); }))
                                   ))
     continue;
    if (*rlenp < sizeof(struct sockaddr_in6)) {
     sshlog("sshconnect.c", __func__, 334, 1, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "v6 addr doesn't fit");
     return -1;
    }
    *rlenp = sizeof(struct sockaddr_in6);
    memcpy(resultp, sa6, *rlenp);
    return 0;
   }
  }
 }
 return -1;
}





static int
ssh_create_socket(struct addrinfo *ai)
{
 int sock, r;
 struct sockaddr_storage bindaddr;
 socklen_t bindaddrlen = 0;
 struct addrinfo hints, *res = 
                              ((void *)0)
                                  ;

 struct ifaddrs *ifaddrs = 
                          ((void *)0)
                              ;

 char ntop[
          1025
                    ];

 sock = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
 if (sock == -1) {
  sshlog("sshconnect.c", __func__, 364, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "socket: %s", strerror(
 (*__errno_location ())
 ));
  return -1;
 }
 fcntl(sock, 
            2
                   , 
                     1
                               );


 if (options.ip_qos_interactive != 0x7fffffff)
  set_sock_tos(sock, options.ip_qos_interactive);


 if (options.bind_address == 
                            ((void *)0) 
                                 && options.bind_interface == 
                                                              ((void *)0)
                                                                  )
  return sock;

 if (options.bind_address != 
                            ((void *)0)
                                ) {
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = ai->ai_family;
  hints.ai_socktype = ai->ai_socktype;
  hints.ai_protocol = ai->ai_protocol;
  hints.ai_flags = 
                  0x0001
                            ;
  if ((r = getaddrinfo(options.bind_address, 
                                            ((void *)0)
                                                ,
      &hints, &res)) != 0) {
   sshlog("sshconnect.c", __func__, 385, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "getaddrinfo: %s: %s", options.bind_address, ssh_gai_strerror(r))
                           ;
   goto fail;
  }
  if (res == 
            ((void *)0)
                ) {
   sshlog("sshconnect.c", __func__, 390, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "getaddrinfo: no addrs");
   goto fail;
  }
  memcpy(&bindaddr, res->ai_addr, res->ai_addrlen);
  bindaddrlen = res->ai_addrlen;
 } else if (options.bind_interface != 
                                     ((void *)0)
                                         ) {

  if ((r = getifaddrs(&ifaddrs)) != 0) {
   sshlog("sshconnect.c", __func__, 398, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "getifaddrs: %s: %s", options.bind_interface, strerror(
  (*__errno_location ())
  ))
                       ;
   goto fail;
  }
  bindaddrlen = sizeof(bindaddr);
  if (check_ifaddrs(options.bind_interface, ai->ai_family,
      ifaddrs, &bindaddr, &bindaddrlen) != 0) {
   sshlog("sshconnect.c", __func__, 405, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "getifaddrs: %s: no suitable addresses", options.bind_interface)
                              ;
   goto fail;
  }



 }
 if ((r = getnameinfo((struct sockaddr *)&bindaddr, bindaddrlen,
     ntop, sizeof(ntop), 
                        ((void *)0)
                            , 0, 
                                 1
                                               )) != 0) {
  sshlog("sshconnect.c", __func__, 415, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "getnameinfo failed: %s", ssh_gai_strerror(r));
  goto fail;
 }
 if (bind(sock, (struct sockaddr *)&bindaddr, bindaddrlen) != 0) {
  sshlog("sshconnect.c", __func__, 419, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "bind %s: %s", ntop, strerror(
 (*__errno_location ())
 ));
  goto fail;
 }
 sshlog("sshconnect.c", __func__, 422, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "bound to %s", ntop);

 goto out;
fail:
 close(sock);
 sock = -1;
 out:
 if (res != 
           ((void *)0)
               )
  freeaddrinfo(res);

 if (ifaddrs != 
               ((void *)0)
                   )
  freeifaddrs(ifaddrs);

 return sock;
}
static int
ssh_connect_direct(struct ssh *ssh, const char *host, struct addrinfo *aitop,
    struct sockaddr_storage *hostaddr, u_short port, int connection_attempts,
    int *timeout_ms, int want_keepalive)
{
 int on = 1, saved_timeout_ms = *timeout_ms;
 int oerrno, sock = -1, attempt;
 char ntop[
          1025
                    ], strport[
                               32
                                         ];
 struct addrinfo *ai;

 sshlog("sshconnect.c", __func__, 457, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "entering");
 memset(ntop, 0, sizeof(ntop));
 memset(strport, 0, sizeof(strport));

 for (attempt = 0; attempt < connection_attempts; attempt++) {
  if (attempt > 0) {

   sleep(1);
   sshlog("sshconnect.c", __func__, 465, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Trying again...");
  }




  for (ai = aitop; ai; ai = ai->ai_next) {
   if (ai->ai_family != 
                       2 
                               &&
       ai->ai_family != 
                       10
                               ) {
    
   (*__errno_location ()) 
         = 
           97
                       ;
    continue;
   }
   if (getnameinfo(ai->ai_addr, ai->ai_addrlen,
       ntop, sizeof(ntop), strport, sizeof(strport),
       
      1
                    |
                     2
                                   ) != 0) {
    oerrno = 
            (*__errno_location ())
                 ;
    sshlog("sshconnect.c", __func__, 481, 1, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "getnameinfo failed");
    
   (*__errno_location ()) 
         = oerrno;
    continue;
   }
   sshlog("sshconnect.c", __func__, 485, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Connecting to %.200s [%.100s] port %s.", host, ntop, strport)
                        ;


   sock = ssh_create_socket(ai);
   if (sock < 0) {

    
   (*__errno_location ()) 
         = 0;
    continue;
   }

   *timeout_ms = saved_timeout_ms;
   if (timeout_connect(sock, ai->ai_addr, ai->ai_addrlen,
       timeout_ms) >= 0) {

    memcpy(hostaddr, ai->ai_addr, ai->ai_addrlen);
    break;
   } else {
    oerrno = 
            (*__errno_location ())
                 ;
    sshlog("sshconnect.c", __func__, 504, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "connect to address %s port %s: %s", ntop, strport, strerror(
   (*__errno_location ())
   ))
                                       ;
    close(sock);
    sock = -1;
    
   (*__errno_location ()) 
         = oerrno;
   }
  }
  if (sock != -1)
   break;
 }


 if (sock == -1) {
  sshlog("sshconnect.c", __func__, 517, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "ssh: connect to host %s port %s: %s", host, strport, 
 (*__errno_location ()) 
 == 0 ? "failure" : strerror(
 (*__errno_location ())
 ))
                                                              ;
  return -1;
 }

 sshlog("sshconnect.c", __func__, 522, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Connection established.");


 if (want_keepalive &&
     setsockopt(sock, 
                     1
                               , 
                                 9
                                             , (void *)&on,
     sizeof(on)) == -1)
  sshlog("sshconnect.c", __func__, 528, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "setsockopt SO_KEEPALIVE: %.100s", strerror(
 (*__errno_location ())
 ));


 if (ssh_packet_set_connection(ssh, sock, sock) == 
                                                  ((void *)0)
                                                      )
  return -1;

 return 0;
}

int
ssh_connect(struct ssh *ssh, const char *host, const char *host_arg,
    struct addrinfo *addrs, struct sockaddr_storage *hostaddr, u_short port,
    int connection_attempts, int *timeout_ms, int want_keepalive)
{
 int in, out;

 if (options.proxy_command == 
                             ((void *)0)
                                 ) {
  return ssh_connect_direct(ssh, host, addrs, hostaddr, port,
      connection_attempts, timeout_ms, want_keepalive);
 } else if (strcmp(options.proxy_command, "-") == 0) {
  if ((in = dup(
               0
                           )) == -1 ||
      (out = dup(
                1
                             )) == -1) {
   if (in >= 0)
    close(in);
   sshlog("sshconnect.c", __func__, 552, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "dup() in/out failed");
   return -1;
  }
  if ((ssh_packet_set_connection(ssh, in, out)) == 
                                                  ((void *)0)
                                                      )
   return -1;
  return 0;
 } else if (options.proxy_use_fdpass) {
  return ssh_proxy_fdpass_connect(ssh, host, host_arg, port,
      options.proxy_command);
 }
 return ssh_proxy_connect(ssh, host, host_arg, port,
     options.proxy_command);
}


static int
confirm(const char *prompt, const char *fingerprint)
{
 const char *msg, *again = "Please type 'yes' or 'no': ";
 const char *again_fp = "Please type 'yes', 'no' or the fingerprint: ";
 char *p, *cp;
 int ret = -1;

 if (options.batch_mode)
  return 0;
 for (msg = prompt;;msg = fingerprint ? again_fp : again) {
  cp = p = read_passphrase(msg, 0x0001);
  if (p == 
          ((void *)0)
              )
   return 0;
  p += strspn(p, " \t");
  p[strcspn(p, " \t\n")] = '\0';
  if (p[0] == '\0' || strcasecmp(p, "no") == 0)
   ret = 0;
  else if (strcasecmp(p, "yes") == 0 || (fingerprint != 
                                                       ((void *)0) 
                                                            &&
      strcmp(p, fingerprint) == 0))
   ret = 1;
  free(cp);
  if (ret != -1)
   return ret;
 }
}

static int
sockaddr_is_local(struct sockaddr *hostaddr)
{
 switch (hostaddr->sa_family) {
 case 
     2
            :
  return (
         __bswap_32 (
         ((struct sockaddr_in *)hostaddr)-> sin_addr.s_addr
         )
                       
                      >> 24) == 
                                127
                                              ;
 case 
     10
             :
  return 
        (__extension__ ({ const struct in6_addr *__a = (const struct in6_addr *) (
        &(((struct sockaddr_in6 *)hostaddr)->sin6_addr)
        ); __a->__in6_u.__u6_addr32[0] == 0 && __a->__in6_u.__u6_addr32[1] == 0 && __a->__in6_u.__u6_addr32[2] == 0 && __a->__in6_u.__u6_addr32[3] == __bswap_32 (1); }))
                                                      
                                                     ;
 default:
  return 0;
 }
}





void
get_hostfile_hostname_ipaddr(char *hostname, struct sockaddr *hostaddr,
    u_short port, char **hostfile_hostname, char **hostfile_ipaddr)
{
 char ntop[
          1025
                    ];
 socklen_t addrlen;

 switch (hostaddr == 
                    ((void *)0) 
                         ? -1 : hostaddr->sa_family) {
 case -1:
  addrlen = 0;
  break;
 case 
     2
            :
  addrlen = sizeof(struct sockaddr_in);
  break;
 case 
     10
             :
  addrlen = sizeof(struct sockaddr_in6);
  break;
 default:
  addrlen = sizeof(struct sockaddr);
  break;
 }





 if (hostfile_ipaddr != 
                       ((void *)0)
                           ) {
  if (options.proxy_command == 
                              ((void *)0)
                                  ) {
   if (getnameinfo(hostaddr, addrlen,
       ntop, sizeof(ntop), 
                          ((void *)0)
                              , 0, 
                                   1
                                                 ) != 0)
   sshfatal("sshconnect.c", __func__, 643, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "getnameinfo failed");
   *hostfile_ipaddr = put_host_port(ntop, port);
  } else {
   *hostfile_ipaddr = xstrdup("<no hostip for proxy "
       "command>");
  }
 }







 if (hostfile_hostname != 
                         ((void *)0)
                             ) {
  if (options.host_key_alias != 
                               ((void *)0)
                                   ) {
   *hostfile_hostname = xstrdup(options.host_key_alias);
   sshlog("sshconnect.c", __func__, 660, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "using hostkeyalias: %s", *hostfile_hostname);
  } else {
   *hostfile_hostname = put_host_port(hostname, port);
  }
 }
}


static int
path_in_hostfiles(const char *path, char **hostfiles, u_int num_hostfiles)
{
 u_int i;

 for (i = 0; i < num_hostfiles; i++) {
  if (strcmp(path, hostfiles[i]) == 0)
   return 1;
 }
 return 0;
}

struct find_by_key_ctx {
 const char *host, *ip;
 const struct sshkey *key;
 char **names;
 u_int nnames;
};


static char *
try_tilde_unexpand(const char *path)
{
 char *home, *ret = 
                   ((void *)0)
                       ;
 size_t l;

 if (*path != '/')
  return xstrdup(path);
 if ((home = getenv("HOME")) == 
                               ((void *)0) 
                                    || (l = strlen(home)) == 0)
  return xstrdup(path);
 if (strncmp(path, home, l) != 0)
  return xstrdup(path);





 if (home[l - 1] != '/' && path[l] != '/')
  return xstrdup(path);
 if (path[l] == '/')
  l++;
 xasprintf(&ret, "~/%s", path + l);
 return ret;
}

static int
hostkeys_find_by_key_cb(struct hostkey_foreach_line *l, void *_ctx)
{
 struct find_by_key_ctx *ctx = (struct find_by_key_ctx *)_ctx;
 char *path;


 if ((l->match & (1)) != 0)
  return 0;

 if (l->marker != MRK_NONE)
  return 0;

 if (l->key == 
              ((void *)0) 
                   || !sshkey_equal(ctx->key, l->key))
  return 0;
 path = try_tilde_unexpand(l->path);
 sshlog("sshconnect.c", __func__, 729, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "found matching key in %s:%lu", path, l->linenum);
 ctx->names = xrecallocarray(ctx->names,
     ctx->nnames, ctx->nnames + 1, sizeof(*ctx->names));
 xasprintf(&ctx->names[ctx->nnames], "%s:%lu: %s", path, l->linenum,
     strncmp(l->hosts, "|1|", strlen("|1|")) == 0 ?
     "[hashed name]" : l->hosts);
 ctx->nnames++;
 free(path);
 return 0;
}

static int
hostkeys_find_by_key_hostfile(const char *file, const char *which,
    struct find_by_key_ctx *ctx)
{
 int r;

 sshlog("sshconnect.c", __func__, 746, 1, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "trying %s hostfile \"%s\"", which, file);
 if ((r = hostkeys_foreach(file, hostkeys_find_by_key_cb, ctx,
     ctx->host, ctx->ip, (1<<1), 0)) != 0) {
  if (r == -24 && 
                                  (*__errno_location ()) 
                                        == 
                                           2
                                                 ) {
   sshlog("sshconnect.c", __func__, 750, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "hostkeys file %s does not exist", file);
   return 0;
  }
  sshlog("sshconnect.c", __func__, 753, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "hostkeys_foreach failed for %s", file);
  return r;
 }
 return 0;
}





static void
hostkeys_find_by_key(const char *host, const char *ip, const struct sshkey *key,
    char **user_hostfiles, u_int num_user_hostfiles,
    char **system_hostfiles, u_int num_system_hostfiles,
    char ***names, u_int *nnames)
{
 struct find_by_key_ctx ctx = {0, 0, 0, 0, 0};
 u_int i;

 *names = 
         ((void *)0)
             ;
 *nnames = 0;

 if (key == 
           ((void *)0) 
                || sshkey_is_cert(key))
  return;

 ctx.host = host;
 ctx.ip = ip;
 ctx.key = key;

 for (i = 0; i < num_user_hostfiles; i++) {
  if (hostkeys_find_by_key_hostfile(user_hostfiles[i],
      "user", &ctx) != 0)
   goto fail;
 }
 for (i = 0; i < num_system_hostfiles; i++) {
  if (hostkeys_find_by_key_hostfile(system_hostfiles[i],
      "system", &ctx) != 0)
   goto fail;
 }

 *names = ctx.names;
 *nnames = ctx.nnames;
 ctx.names = 
            ((void *)0)
                ;
 ctx.nnames = 0;
 return;
 fail:
 for (i = 0; i < ctx.nnames; i++)
  free(ctx.names[i]);
 free(ctx.names);
}


static char *
other_hostkeys_message(const char *host, const char *ip,
    const struct sshkey *key,
    char **user_hostfiles, u_int num_user_hostfiles,
    char **system_hostfiles, u_int num_system_hostfiles)
{
 char *ret = 
            ((void *)0)
                , **othernames = 
                                 ((void *)0)
                                     ;
 u_int i, n, num_othernames = 0;

 hostkeys_find_by_key(host, ip, key,
     user_hostfiles, num_user_hostfiles,
     system_hostfiles, num_system_hostfiles,
     &othernames, &num_othernames);
 if (num_othernames == 0)
  return xstrdup("This key is not known by any other names.");

 xasprintf(&ret, "This host key is known by the following other "
     "names/addresses:");

 n = num_othernames;
 if (n > 8)
  n = 8;
 for (i = 0; i < n; i++) {
  xextendf(&ret, "\n", "    %s", othernames[i]);
 }
 if (n < num_othernames) {
  xextendf(&ret, "\n", "    (%d additional names omitted)",
      num_othernames - n);
 }
 for (i = 0; i < num_othernames; i++)
  free(othernames[i]);
 free(othernames);
 return ret;
}

void
load_hostkeys_command(struct hostkeys *hostkeys, const char *command_template,
    const char *invocation, const struct ssh_conn_info *cinfo,
    const struct sshkey *host_key, const char *hostfile_hostname)
{
 int r, i, ac = 0;
 char *key_fp = 
               ((void *)0)
                   , *keytext = 
                                ((void *)0)
                                    , *tmp;
 char *command = 
                ((void *)0)
                    , *tag = 
                             ((void *)0)
                                 , **av = 
                                          ((void *)0)
                                              ;
 FILE *f = 
          ((void *)0)
              ;
 pid_t pid;
 void (*osigchld)(int);

 xasprintf(&tag, "KnownHostsCommand-%s", invocation);

 if (host_key != 
                ((void *)0)
                    ) {
  if ((key_fp = sshkey_fingerprint(host_key,
      options.fingerprint_hash, SSH_FP_DEFAULT)) == 
                                                   ((void *)0)
                                                       )
   sshfatal("sshconnect.c", __func__, 857, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshkey_fingerprint failed");
  if ((r = sshkey_to_base64(host_key, &keytext)) != 0)
   sshfatal("sshconnect.c", __func__, 859, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshkey_to_base64 failed");
 }




 osigchld = ssh_signal(
                      17
                             , 
                               ((__sighandler_t) 0)
                                      );


 if (argv_split(command_template, &ac, &av, 0) != 0) {
  sshlog("sshconnect.c", __func__, 869, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s \"%s\" contains invalid quotes", tag, command_template)
                       ;
  goto out;
 }
 if (ac == 0) {
  sshlog("sshconnect.c", __func__, 874, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "%s \"%s\" yielded no arguments", tag, command_template)
                       ;
  goto out;
 }
 for (i = 1; i < ac; i++) {
  tmp = percent_dollar_expand(av[i],
      "C", cinfo->conn_hash_hex, "L", cinfo->shorthost, "i", cinfo->uidstr, "k", cinfo->keyalias, "l", cinfo->thishost, "n", cinfo->host_arg, "p", cinfo->portstr, "d", cinfo->homedir, "h", cinfo->remhost, "r", cinfo->remuser, "u", cinfo->locuser,
      "H", hostfile_hostname,
      "I", invocation,
      "t", host_key == 
                      ((void *)0) 
                           ? "NONE" : sshkey_ssh_name(host_key),
      "f", key_fp == 
                    ((void *)0) 
                         ? "NONE" : key_fp,
      "K", keytext == 
                     ((void *)0) 
                          ? "NONE" : keytext,
      (char *)
             ((void *)0)
                 );
  if (tmp == 
            ((void *)0)
                )
   sshfatal("sshconnect.c", __func__, 888, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "percent_expand failed");
  free(av[i]);
  av[i] = tmp;
 }

 command = argv_assemble(ac, av);

 if ((pid = subprocess(tag, command, ac, av, &f,
     (1<<1)|(1<<3)|
     (1<<4), 
                                 ((void *)0)
                                     , 
                                       ((void *)0)
                                           , 
                                             ((void *)0)
                                                 )) == 0)
  goto out;

 load_hostkeys_file(hostkeys, hostfile_hostname, tag, f, 1);

 if (exited_cleanly(pid, tag, command, 0) != 0)
  sshfatal("sshconnect.c", __func__, 903, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "KnownHostsCommand failed");

 out:
 if (f != 
         ((void *)0)
             )
  fclose(f);
 ssh_signal(
           17
                  , osigchld);
 for (i = 0; i < ac; i++)
  free(av[i]);
 free(av);
 free(tag);
 free(command);
 free(key_fp);
 free(keytext);
}
static int
check_host_key(char *hostname, const struct ssh_conn_info *cinfo,
    struct sockaddr *hostaddr, u_short port,
    struct sshkey *host_key, int readonly, int clobber_port,
    char **user_hostfiles, u_int num_user_hostfiles,
    char **system_hostfiles, u_int num_system_hostfiles,
    const char *hostfile_command)
{
 HostStatus host_status = -1, ip_status = -1;
 struct sshkey *raw_key = 
                         ((void *)0)
                             ;
 char *ip = 
           ((void *)0)
               , *host = 
                         ((void *)0)
                             ;
 char hostline[1000], *hostp, *fp, *ra;
 char msg[1024];
 const char *type, *fail_reason;
 const struct hostkey_entry *host_found = 
                                         ((void *)0)
                                             , *ip_found = 
                                                           ((void *)0)
                                                               ;
 int len, cancelled_forwarding = 0, confirmed;
 int local = sockaddr_is_local(hostaddr);
 int r, want_cert = sshkey_is_cert(host_key), host_ip_differ = 0;
 int hostkey_trusted = 0;
 struct hostkeys *host_hostkeys, *ip_hostkeys;
 u_int i;
 if (options.no_host_authentication_for_localhost == 1 && local &&
     options.host_key_alias == 
                              ((void *)0)
                                  ) {
  sshlog("sshconnect.c", __func__, 957, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Forcing accepting of host key for " "loopback/localhost.")
                            ;
  options.update_hostkeys = 0;
  return 0;
 }





 get_hostfile_hostname_ipaddr(hostname, hostaddr,
     clobber_port ? 0 : port, &host, &ip);





 if (options.check_host_ip && (local ||
     strcmp(hostname, ip) == 0 || options.proxy_command != 
                                                          ((void *)0)
                                                              ))
  options.check_host_ip = 0;

 host_hostkeys = init_hostkeys();
 for (i = 0; i < num_user_hostfiles; i++)
  load_hostkeys(host_hostkeys, host, user_hostfiles[i], 0);
 for (i = 0; i < num_system_hostfiles; i++)
  load_hostkeys(host_hostkeys, host, system_hostfiles[i], 0);
 if (hostfile_command != 
                        ((void *)0) 
                             && !clobber_port) {
  load_hostkeys_command(host_hostkeys, hostfile_command,
      "HOSTNAME", cinfo, host_key, host);
 }

 ip_hostkeys = 
              ((void *)0)
                  ;
 if (!want_cert && options.check_host_ip) {
  ip_hostkeys = init_hostkeys();
  for (i = 0; i < num_user_hostfiles; i++)
   load_hostkeys(ip_hostkeys, ip, user_hostfiles[i], 0);
  for (i = 0; i < num_system_hostfiles; i++)
   load_hostkeys(ip_hostkeys, ip, system_hostfiles[i], 0);
  if (hostfile_command != 
                         ((void *)0) 
                              && !clobber_port) {
   load_hostkeys_command(ip_hostkeys, hostfile_command,
       "ADDRESS", cinfo, host_key, ip);
  }
 }

 retry:

 want_cert = sshkey_is_cert(host_key);
 type = sshkey_type(host_key);





 host_status = check_key_in_hostkeys(host_hostkeys, host_key,
     &host_found);





 if (!readonly && (num_user_hostfiles == 0 ||
     (host_found != 
                   ((void *)0) 
                        && host_found->note != 0)))
  readonly = 1;






 if (!want_cert && ip_hostkeys != 
                                 ((void *)0)
                                     ) {
  ip_status = check_key_in_hostkeys(ip_hostkeys, host_key,
      &ip_found);
  if (host_status == HOST_CHANGED &&
      (ip_status != HOST_CHANGED ||
      (ip_found != 
                  ((void *)0) 
                       &&
      !sshkey_equal(ip_found->key, host_found->key))))
   host_ip_differ = 1;
 } else
  ip_status = host_status;

 switch (host_status) {
 case HOST_OK:

  sshlog("sshconnect.c", __func__, 1040, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Host '%.200s' is known and matches the %s host %s.", host, type, want_cert ? "certificate" : "key")
                                                    ;
  sshlog("sshconnect.c", __func__, 1042, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Found %s in %s:%lu", want_cert ? "CA key" : "key", host_found->file, host_found->line)
                                         ;
  if (want_cert) {
   if (sshkey_cert_check_host(host_key,
       options.host_key_alias == 
                                ((void *)0) 
                                     ?
       hostname : options.host_key_alias, 0,
       options.ca_sign_algorithms, &fail_reason) != 0) {
    sshlog("sshconnect.c", __func__, 1049, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "%s", fail_reason);
    goto fail;
   }




   if (options.update_hostkeys != 0) {
    options.update_hostkeys = 0;
    sshlog("sshconnect.c", __func__, 1058, 1, SYSLOG_LEVEL_DEBUG3, 
   ((void *)0)
   , "certificate host key in use; " "disabling UpdateHostkeys")
                                   ;
   }
  }

  if (options.update_hostkeys != 0 &&
      (path_in_hostfiles(host_found->file,
      system_hostfiles, num_system_hostfiles) ||
      (ip_status == HOST_OK && ip_found != 
                                          ((void *)0) 
                                               &&
      path_in_hostfiles(ip_found->file,
      system_hostfiles, num_system_hostfiles)))) {
   options.update_hostkeys = 0;
   sshlog("sshconnect.c", __func__, 1070, 1, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "host key found in GlobalKnownHostsFile; " "disabling UpdateHostkeys")
                                  ;
  }
  if (options.update_hostkeys != 0 && host_found->note) {
   options.update_hostkeys = 0;
   sshlog("sshconnect.c", __func__, 1075, 1, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "host key found via KnownHostsCommand; " "disabling UpdateHostkeys")
                                  ;
  }
  if (options.check_host_ip && ip_status == HOST_NEW) {
   if (readonly || want_cert)
    sshlog("sshconnect.c", __func__, 1080, 0, SYSLOG_LEVEL_INFO, 
   ((void *)0)
   , "%s host key for IP address " "'%.128s' not in list of known hosts.", type, ip)

                 ;
   else if (!add_host_to_hostfile(user_hostfiles[0], ip,
       host_key, options.hash_known_hosts))
    sshlog("sshconnect.c", __func__, 1085, 0, SYSLOG_LEVEL_INFO, 
   ((void *)0)
   , "Failed to add the %s host key for IP " "address '%.128s' to the list of known " "hosts (%.500s).", type, ip, user_hostfiles[0])


                          ;
   else
    sshlog("sshconnect.c", __func__, 1090, 0, SYSLOG_LEVEL_INFO, 
   ((void *)0)
   , "Warning: Permanently added the %s host " "key for IP address '%.128s' to the list " "of known hosts.", type, ip)

                                    ;
  } else if (options.visual_host_key) {
   fp = sshkey_fingerprint(host_key,
       options.fingerprint_hash, SSH_FP_DEFAULT);
   ra = sshkey_fingerprint(host_key,
       options.fingerprint_hash, SSH_FP_RANDOMART);
   if (fp == 
            ((void *)0) 
                 || ra == 
                          ((void *)0)
                              )
    sshfatal("sshconnect.c", __func__, 1099, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "sshkey_fingerprint failed");
   sshlog("sshconnect.c", __func__, 1100, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Host key fingerprint is %s\n%s", fp, ra);
   free(ra);
   free(fp);
  }
  hostkey_trusted = 1;
  break;
 case HOST_NEW:
  if (options.host_key_alias == 
                               ((void *)0) 
                                    && port != 0 &&
      port != 22 && !clobber_port) {
   sshlog("sshconnect.c", __func__, 1109, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "checking without port identifier");
   if (check_host_key(hostname, cinfo, hostaddr, 0,
       host_key, 2, 1,
       user_hostfiles, num_user_hostfiles,
       system_hostfiles, num_system_hostfiles,
       hostfile_command) == 0) {
    sshlog("sshconnect.c", __func__, 1115, 0, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "found matching key w/out port");
    break;
   }
  }
  if (readonly || want_cert)
   goto fail;

  if (options.strict_host_key_checking ==
      2) {





   sshlog("sshconnect.c", __func__, 1129, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "No %s host key is known for %.200s and you " "have requested strict checking.", type, host)
                                                     ;
   goto fail;
  } else if (options.strict_host_key_checking ==
      3) {
   char *msg1 = 
               ((void *)0)
                   , *msg2 = 
                             ((void *)0)
                                 ;

   xasprintf(&msg1, "The authenticity of host "
       "'%.200s (%s)' can't be established", host, ip);

   if (show_other_keys(host_hostkeys, host_key)) {
    xextendf(&msg1, "\n", "but keys of different "
        "type are already known for this host.");
   } else
    xextendf(&msg1, "", ".");

   fp = sshkey_fingerprint(host_key,
       options.fingerprint_hash, SSH_FP_DEFAULT);
   ra = sshkey_fingerprint(host_key,
       options.fingerprint_hash, SSH_FP_RANDOMART);
   if (fp == 
            ((void *)0) 
                 || ra == 
                          ((void *)0)
                              )
    sshfatal("sshconnect.c", __func__, 1150, 1, SYSLOG_LEVEL_FATAL, 
   ((void *)0)
   , "sshkey_fingerprint failed");
   xextendf(&msg1, "\n", "%s key fingerprint is %s.",
       type, fp);
   if (options.visual_host_key)
    xextendf(&msg1, "\n", "%s", ra);
   if (options.verify_host_key_dns) {
    xextendf(&msg1, "\n",
        "%s host key fingerprint found in DNS.",
        matching_host_key_dns ?
        "Matching" : "No matching");
   }

   if ((msg2 = other_hostkeys_message(host, ip, host_key,
       user_hostfiles, num_user_hostfiles,
       system_hostfiles, num_system_hostfiles)) != 
                                                  ((void *)0)
                                                      )
    xextendf(&msg1, "\n", "%s", msg2);

   xextendf(&msg1, "\n",
       "Are you sure you want to continue connecting "
       "(yes/no/[fingerprint])? ");

   confirmed = confirm(msg1, fp);
   free(ra);
   free(fp);
   free(msg1);
   free(msg2);
   if (!confirmed)
    goto fail;
   hostkey_trusted = 1;
  }




  if (options.check_host_ip && ip_status == HOST_NEW) {
   snprintf(hostline, sizeof(hostline), "%s,%s", host, ip);
   hostp = hostline;
   if (options.hash_known_hosts) {

    r = add_host_to_hostfile(user_hostfiles[0],
        host, host_key, options.hash_known_hosts) &&
        add_host_to_hostfile(user_hostfiles[0], ip,
        host_key, options.hash_known_hosts);
   } else {

    r = add_host_to_hostfile(user_hostfiles[0],
        hostline, host_key,
        options.hash_known_hosts);
   }
  } else {
   r = add_host_to_hostfile(user_hostfiles[0], host,
       host_key, options.hash_known_hosts);
   hostp = host;
  }

  if (!r)
   sshlog("sshconnect.c", __func__, 1206, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Failed to add the host to the list of known " "hosts (%.500s).", user_hostfiles[0])
                                            ;
  else
   sshlog("sshconnect.c", __func__, 1209, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "Warning: Permanently added '%.200s' (%s) to the " "list of known hosts.", hostp, type)
                                           ;
  break;
 case HOST_REVOKED:
  sshlog("sshconnect.c", __func__, 1213, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
  sshlog("sshconnect.c", __func__, 1214, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "@       WARNING: REVOKED HOST KEY DETECTED!               @");
  sshlog("sshconnect.c", __func__, 1215, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
  sshlog("sshconnect.c", __func__, 1216, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "The %s host key for %s is marked as revoked.", type, host);
  sshlog("sshconnect.c", __func__, 1217, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "This could mean that a stolen key is being used to");
  sshlog("sshconnect.c", __func__, 1218, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "impersonate this host.");





  if (options.strict_host_key_checking !=
      0) {
   sshlog("sshconnect.c", __func__, 1226, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s host key for %.200s was revoked and you have " "requested strict checking.", type, host)
                                                ;
   goto fail;
  }
  goto continue_unsafe;

 case HOST_CHANGED:
  if (want_cert) {





   sshlog("sshconnect.c", __func__, 1239, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "Host certificate authority does not " "match %s in %s:%lu", "@cert-authority", host_found->file, host_found->line)

                                          ;
   goto fail;
  }
  if (readonly == 2)
   goto fail;
  if (options.check_host_ip && host_ip_differ) {
   char *key_msg;
   if (ip_status == HOST_NEW)
    key_msg = "is unknown";
   else if (ip_status == HOST_OK)
    key_msg = "is unchanged";
   else
    key_msg = "has a different value";
   sshlog("sshconnect.c", __func__, 1254, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
   sshlog("sshconnect.c", __func__, 1255, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "@       WARNING: POSSIBLE DNS SPOOFING DETECTED!          @");
   sshlog("sshconnect.c", __func__, 1256, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
   sshlog("sshconnect.c", __func__, 1257, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "The %s host key for %s has changed,", type, host);
   sshlog("sshconnect.c", __func__, 1258, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "and the key for the corresponding IP address %s", ip);
   sshlog("sshconnect.c", __func__, 1259, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s. This could either mean that", key_msg);
   sshlog("sshconnect.c", __func__, 1260, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "DNS SPOOFING is happening or the IP address for the host");
   sshlog("sshconnect.c", __func__, 1261, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "and its host key have changed at the same time.");
   if (ip_status != HOST_NEW)
    sshlog("sshconnect.c", __func__, 1263, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "Offending key for IP in %s:%lu", ip_found->file, ip_found->line)
                                       ;
  }

  warn_changed_key(host_key);
  sshlog("sshconnect.c", __func__, 1268, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Add correct host key in %.100s to get rid of this message.", user_hostfiles[0])
                        ;
  sshlog("sshconnect.c", __func__, 1270, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Offending %s key in %s:%lu", sshkey_type(host_found->key), host_found->file, host_found->line)

                                         ;





  if (options.strict_host_key_checking !=
      0) {
   sshlog("sshconnect.c", __func__, 1280, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Host key for %.200s has changed and you have " "requested strict checking.", host)
                                          ;
   goto fail;
  }

 continue_unsafe:





  if (options.password_authentication) {
   sshlog("sshconnect.c", __func__, 1292, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Password authentication is disabled to avoid " "man-in-the-middle attacks.")
                                    ;
   options.password_authentication = 0;
   cancelled_forwarding = 1;
  }
  if (options.kbd_interactive_authentication) {
   sshlog("sshconnect.c", __func__, 1298, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Keyboard-interactive authentication is disabled" " to avoid man-in-the-middle attacks.")
                                              ;
   options.kbd_interactive_authentication = 0;
   cancelled_forwarding = 1;
  }
  if (options.forward_agent) {
   sshlog("sshconnect.c", __func__, 1304, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Agent forwarding is disabled to avoid " "man-in-the-middle attacks.")
                                    ;
   options.forward_agent = 0;
   cancelled_forwarding = 1;
  }
  if (options.forward_x11) {
   sshlog("sshconnect.c", __func__, 1310, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "X11 forwarding is disabled to avoid " "man-in-the-middle attacks.")
                                    ;
   options.forward_x11 = 0;
   cancelled_forwarding = 1;
  }
  if (options.num_local_forwards > 0 ||
      options.num_remote_forwards > 0) {
   sshlog("sshconnect.c", __func__, 1317, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Port forwarding is disabled to avoid " "man-in-the-middle attacks.")
                                    ;
   options.num_local_forwards =
       options.num_remote_forwards = 0;
   cancelled_forwarding = 1;
  }
  if (options.tun_open != 0x00) {
   sshlog("sshconnect.c", __func__, 1324, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Tunnel forwarding is disabled to avoid " "man-in-the-middle attacks.")
                                    ;
   options.tun_open = 0x00;
   cancelled_forwarding = 1;
  }
  if (options.update_hostkeys != 0) {
   sshlog("sshconnect.c", __func__, 1330, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "UpdateHostkeys is disabled because the host " "key is not trusted.")
                             ;
   options.update_hostkeys = 0;
  }
  if (options.exit_on_forward_failure && cancelled_forwarding)
   sshfatal("sshconnect.c", __func__, 1335, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Error: forwarding disabled due to host key " "check failure")
                       ;
  break;
 case HOST_FOUND:
  sshfatal("sshconnect.c", __func__, 1347, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "internal error");
  break;
 }

 if (options.check_host_ip && host_status != HOST_CHANGED &&
     ip_status == HOST_CHANGED) {
  snprintf(msg, sizeof(msg),
      "Warning: the %s host key for '%.200s' "
      "differs from the key for the IP address '%.128s'"
      "\nOffending key for IP in %s:%lu",
      type, host, ip, ip_found->file, ip_found->line);
  if (host_status == HOST_OK) {
   len = strlen(msg);
   snprintf(msg + len, sizeof(msg) - len,
       "\nMatching host key in %s:%lu",
       host_found->file, host_found->line);
  }
  if (options.strict_host_key_checking ==
      3) {
   strlcat(msg, "\nAre you sure you want "
       "to continue connecting (yes/no)? ", sizeof(msg));
   if (!confirm(msg, 
                    ((void *)0)
                        ))
    goto fail;
  } else if (options.strict_host_key_checking !=
      0) {
   sshlog("sshconnect.c", __func__, 1372, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "%s", msg);
   sshlog("sshconnect.c", __func__, 1373, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Exiting, you have requested strict checking.");
   goto fail;
  } else {
   sshlog("sshconnect.c", __func__, 1376, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "%s", msg);
  }
 }

 if (!hostkey_trusted && options.update_hostkeys) {
  sshlog("sshconnect.c", __func__, 1381, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "hostkey not known or explicitly trusted: " "disabling UpdateHostkeys")
                                 ;
  options.update_hostkeys = 0;
 }

 free(ip);
 free(host);
 if (host_hostkeys != 
                     ((void *)0)
                         )
  free_hostkeys(host_hostkeys);
 if (ip_hostkeys != 
                   ((void *)0)
                       )
  free_hostkeys(ip_hostkeys);
 return 0;

fail:
 if (want_cert && host_status != HOST_REVOKED) {




  sshlog("sshconnect.c", __func__, 1400, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "No matching CA found. Retry with plain key");
  if ((r = sshkey_from_private(host_key, &raw_key)) != 0)
   sshfatal("sshconnect.c", __func__, 1402, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "decode key");
  if ((r = sshkey_drop_cert(raw_key)) != 0)
   sshfatal("sshconnect.c", __func__, 1404, 0, SYSLOG_LEVEL_FATAL, ssh_err(r), "Couldn't drop certificate");
  host_key = raw_key;
  goto retry;
 }
 sshkey_free(raw_key);
 free(ip);
 free(host);
 if (host_hostkeys != 
                     ((void *)0)
                         )
  free_hostkeys(host_hostkeys);
 if (ip_hostkeys != 
                   ((void *)0)
                       )
  free_hostkeys(ip_hostkeys);
 return -1;
}


int
verify_host_key(char *host, struct sockaddr *hostaddr, struct sshkey *host_key,
    const struct ssh_conn_info *cinfo)
{
 u_int i;
 int r = -1, flags = 0;
 char valid[64], *fp = 
                      ((void *)0)
                          , *cafp = 
                                    ((void *)0)
                                        ;
 struct sshkey *plain = 
                       ((void *)0)
                           ;

 if ((fp = sshkey_fingerprint(host_key,
     options.fingerprint_hash, SSH_FP_DEFAULT)) == 
                                                  ((void *)0)
                                                      ) {
  sshlog("sshconnect.c", __func__, 1430, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "fingerprint host key");
  r = -1;
  goto out;
 }

 if (sshkey_is_cert(host_key)) {
  if ((cafp = sshkey_fingerprint(host_key->cert->signature_key,
      options.fingerprint_hash, SSH_FP_DEFAULT)) == 
                                                   ((void *)0)
                                                       ) {
   sshlog("sshconnect.c", __func__, 1438, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "fingerprint CA key");
   r = -1;
   goto out;
  }
  sshkey_format_cert_validity(host_key->cert,
      valid, sizeof(valid));
  sshlog("sshconnect.c", __func__, 1444, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Server host certificate: %s %s, serial %llu " "ID \"%s\" CA %s %s valid %s", sshkey_ssh_name(host_key), fp, (unsigned long long)host_key->cert->serial, host_key->cert->key_id, sshkey_ssh_name(host_key->cert->signature_key), cafp, valid)





            ;
  for (i = 0; i < host_key->cert->nprincipals; i++) {
   sshlog("sshconnect.c", __func__, 1452, 0, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "Server host certificate hostname: %s", host_key->cert->principals[i])
                                     ;
  }
 } else {
  sshlog("sshconnect.c", __func__, 1456, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "Server host key: %s %s", sshkey_ssh_name(host_key), fp);
 }

 if (sshkey_equal(previous_host_key, host_key)) {
  sshlog("sshconnect.c", __func__, 1460, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "server host key %s %s matches cached key", sshkey_type(host_key), fp)
                                ;
  r = 0;
  goto out;
 }


 if (options.revoked_host_keys != 
                                 ((void *)0)
                                     ) {
  r = sshkey_check_revoked(host_key, options.revoked_host_keys);
  switch (r) {
  case 0:
   break;
  case -51:
   sshlog("sshconnect.c", __func__, 1473, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Host key %s %s revoked by file %s", sshkey_type(host_key), fp, options.revoked_host_keys)

                                 ;
   r = -1;
   goto out;
  default:
   sshlog("sshconnect.c", __func__, 1479, 0, SYSLOG_LEVEL_ERROR, ssh_err(r), "Error checking host key %s %s in " "revoked keys file %s", sshkey_type(host_key), fp, options.revoked_host_keys)

                                     ;
   r = -1;
   goto out;
  }
 }

 if (options.verify_host_key_dns) {




  if ((r = sshkey_from_private(host_key, &plain)) != 0)
   goto out;
  if (sshkey_is_cert(plain))
   sshkey_drop_cert(plain);
  if (verify_host_key_dns(host, hostaddr, plain, &flags) == 0) {
   if (flags & 0x00000001) {
    if (options.verify_host_key_dns == 1 &&
        flags & 0x00000002 &&
        flags & 0x00000004) {
     r = 0;
     goto out;
    }
    if (flags & 0x00000002) {
     matching_host_key_dns = 1;
    } else {
     warn_changed_key(plain);
     sshlog("sshconnect.c", __func__, 1508, 0, SYSLOG_LEVEL_ERROR, 
    ((void *)0)
    , "Update the SSHFP RR in DNS " "with the new host key to get rid " "of this message.")

                            ;
    }
   }
  }
 }
 r = check_host_key(host, cinfo, hostaddr, options.port, host_key,
     0, 0, options.user_hostfiles, options.num_user_hostfiles,
     options.system_hostfiles, options.num_system_hostfiles,
     options.known_hosts_command);

out:
 sshkey_free(plain);
 free(fp);
 free(cafp);
 if (r == 0 && host_key != 
                          ((void *)0)
                              ) {
  sshkey_free(previous_host_key);
  r = sshkey_from_private(host_key, &previous_host_key);
 }

 return r;
}
void
ssh_login(struct ssh *ssh, Sensitive *sensitive, const char *orighost,
    struct sockaddr *hostaddr, u_short port, struct passwd *pw, int timeout_ms,
    const struct ssh_conn_info *cinfo)
{
 char *host;
 char *server_user, *local_user;
 int r;

 local_user = xstrdup(pw->pw_name);
 server_user = options.user ? options.user : local_user;


 host = xstrdup(orighost);
 lowercase(host);


 if ((r = kex_exchange_identification(ssh, timeout_ms, 
                                                      ((void *)0)
                                                          )) != 0)
  sshpkt_fatal(ssh, r, "banner exchange");


 ssh_packet_set_nonblocking(ssh);



 sshlog("sshconnect.c", __func__, 1564, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "Authenticating to %s:%d as '%s'", host, port, server_user);
 ssh_kex2(ssh, host, hostaddr, port, cinfo);
 ssh_userauth2(ssh, local_user, server_user, host, sensitive);
 free(local_user);
 free(host);
}


static int
show_other_keys(struct hostkeys *hostkeys, struct sshkey *key)
{
 int type[] = {
  KEY_RSA,
  KEY_DSA,
  KEY_ECDSA,
  KEY_ED25519,
  KEY_XMSS,
  -1
 };
 int i, ret = 0;
 char *fp, *ra;
 const struct hostkey_entry *found;

 for (i = 0; type[i] != -1; i++) {
  if (type[i] == key->type)
   continue;
  if (!lookup_key_in_hostkeys_by_type(hostkeys, type[i],
      -1, &found))
   continue;
  fp = sshkey_fingerprint(found->key,
      options.fingerprint_hash, SSH_FP_DEFAULT);
  ra = sshkey_fingerprint(found->key,
      options.fingerprint_hash, SSH_FP_RANDOMART);
  if (fp == 
           ((void *)0) 
                || ra == 
                         ((void *)0)
                             )
   sshfatal("sshconnect.c", __func__, 1598, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshkey_fingerprint fail");
  sshlog("sshconnect.c", __func__, 1599, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "WARNING: %s key found for host %s\n" "in %s:%lu\n" "%s key fingerprint %s.", sshkey_type(found->key), found->host, found->file, found->line, sshkey_type(found->key), fp)




                                  ;
  if (options.visual_host_key)
   sshlog("sshconnect.c", __func__, 1606, 0, SYSLOG_LEVEL_INFO, 
  ((void *)0)
  , "%s", ra);
  free(ra);
  free(fp);
  ret = 1;
 }
 return ret;
}

static void
warn_changed_key(struct sshkey *host_key)
{
 char *fp;

 fp = sshkey_fingerprint(host_key, options.fingerprint_hash,
     SSH_FP_DEFAULT);
 if (fp == 
          ((void *)0)
              )
  sshfatal("sshconnect.c", __func__, 1622, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "sshkey_fingerprint fail");

 sshlog("sshconnect.c", __func__, 1624, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
 sshlog("sshconnect.c", __func__, 1625, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "@    WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED!     @");
 sshlog("sshconnect.c", __func__, 1626, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
 sshlog("sshconnect.c", __func__, 1627, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "IT IS POSSIBLE THAT SOMEONE IS DOING SOMETHING NASTY!");
 sshlog("sshconnect.c", __func__, 1628, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "Someone could be eavesdropping on you right now (man-in-the-middle attack)!");
 sshlog("sshconnect.c", __func__, 1629, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "It is also possible that a host key has just been changed.");
 sshlog("sshconnect.c", __func__, 1630, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "The fingerprint for the %s key sent by the remote host is\n%s.", sshkey_type(host_key), fp)
                               ;
 sshlog("sshconnect.c", __func__, 1632, 0, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "Please contact your system administrator.");

 free(fp);
}




int
ssh_local_cmd(const char *args)
{
 char *shell;
 pid_t pid;
 int status;
 void (*osighand)(int);

 if (!options.permit_local_command ||
     args == 
            ((void *)0) 
                 || !*args)
  return (1);

 if ((shell = getenv("SHELL")) == 
                                 ((void *)0) 
                                      || *shell == '\0')
  shell = 
         "/bin/sh"
                     ;

 osighand = ssh_signal(
                      17
                             , 
                               ((__sighandler_t) 0)
                                      );
 pid = fork();
 if (pid == 0) {
  ssh_signal(
            13
                   , 
                     ((__sighandler_t) 0)
                            );
  sshlog("sshconnect.c", __func__, 1659, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "Executing %s -c \"%s\"", shell, args);
  execl(shell, shell, "-c", args, (char *)
                                         ((void *)0)
                                             );
  sshlog("sshconnect.c", __func__, 1661, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "Couldn't execute %s -c \"%s\": %s", shell, args, strerror(
 (*__errno_location ())
 ))
                                   ;
  _exit(1);
 } else if (pid == -1)
  sshfatal("sshconnect.c", __func__, 1665, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "fork failed: %.100s", strerror(
 (*__errno_location ())
 ));
 while (waitpid(pid, &status, 0) == -1)
  if (
     (*__errno_location ()) 
           != 
              4
                   )
   sshfatal("sshconnect.c", __func__, 1668, 0, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "Couldn't wait for child: %s", strerror(
  (*__errno_location ())
  ));
 ssh_signal(
           17
                  , osighand);

 if (!
     (((
     status
     ) & 0x7f) == 0)
                      )
  return (1);

 return (
        (((
        status
        ) & 0xff00) >> 8)
                           );
}

void
maybe_add_key_to_agent(const char *authfile, struct sshkey *private,
    const char *comment, const char *passphrase)
{
 int auth_sock = -1, r;
 const char *skprovider = 
                         ((void *)0)
                             ;

 if (options.add_keys_to_agent == 0)
  return;

 if ((r = ssh_get_authentication_socket(&auth_sock)) != 0) {
  sshlog("sshconnect.c", __func__, 1688, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "no authentication agent, not adding key");
  return;
 }

 if (options.add_keys_to_agent == 2 &&
     !ask_permission("Add key %s (%s) to agent?", authfile, comment)) {
  sshlog("sshconnect.c", __func__, 1694, 0, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "user denied adding this key");
  close(auth_sock);
  return;
 }
 if (sshkey_is_sk(private))
  skprovider = options.sk_provider;
 if ((r = ssh_add_identity_constrained(auth_sock, private,
     comment == 
               ((void *)0) 
                    ? authfile : comment,
     options.add_keys_to_agent_lifespan,
     (options.add_keys_to_agent == 3), 0, skprovider, 
                                                     ((void *)0)
                                                         , 0)) == 0)
  sshlog("sshconnect.c", __func__, 1704, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "identity added to agent: %s", authfile);
 else
  sshlog("sshconnect.c", __func__, 1706, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "could not add identity to agent: %s (%d)", authfile, r);
 close(auth_sock);
}
