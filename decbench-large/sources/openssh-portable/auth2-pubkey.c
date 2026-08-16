











































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
void temporarily_use_uid(struct passwd *);
void restore_uid(void);
void permanently_set_uid(struct passwd *);
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
char *get_peer_ipaddr(int);
int get_peer_port(int);
char *get_local_ipaddr(int);
char *get_local_name(int);
int get_local_port(int);



void ipv64_normalise_mapped(struct sockaddr_storage *, socklen_t *);



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


extern ServerOptions options;

static char *
format_key(const struct sshkey *key)
{
 char *ret, *fp = sshkey_fingerprint(key,
     options.fingerprint_hash, SSH_FP_DEFAULT);

 xasprintf(&ret, "%s %s", sshkey_type(key), fp);
 free(fp);
 return ret;
}

static int
userauth_pubkey(struct ssh *ssh, const char *method)
{
 Authctxt *authctxt = ssh->authctxt;
 struct passwd *pw = authctxt->pw;
 struct sshbuf *b = 
                   ((void *)0)
                       ;
 struct sshkey *key = 
                     ((void *)0)
                         , *hostkey = 
                                      ((void *)0)
                                          ;
 char *pkalg = 
              ((void *)0)
                  , *userstyle = 
                                 ((void *)0)
                                     , *key_s = 
                                                ((void *)0)
                                                    , *ca_s = 
                                                              ((void *)0)
                                                                  ;
 u_char *pkblob = 
                 ((void *)0)
                     , *sig = 
                              ((void *)0)
                                  , have_sig;
 size_t blen, slen;
 int hostbound, r, pktype;
 int req_presence = 0, req_verify = 0, authenticated = 0;
 struct sshauthopt *authopts = 
                              ((void *)0)
                                  ;
 struct sshkey_sig_details *sig_details = 
                                         ((void *)0)
                                             ;

 hostbound = strcmp(method, "publickey-hostbound-v00@openssh.com") == 0;

 if ((r = sshpkt_get_u8(ssh, &have_sig)) != 0 ||
     (r = sshpkt_get_cstring(ssh, &pkalg, 
                                         ((void *)0)
                                             )) != 0 ||
     (r = sshpkt_get_string(ssh, &pkblob, &blen)) != 0)
  sshfatal("auth2-pubkey.c", __func__, 107, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse %s packet", method);


 if (hostbound) {
  if ((r = sshpkt_getb_froms(ssh, &b)) != 0 ||
      (r = sshkey_fromb(b, &hostkey)) != 0)
   sshfatal("auth2-pubkey.c", __func__, 113, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse %s hostkey", method);
  if (ssh->kex->initial_hostkey == 
                                  ((void *)0)
                                      )
   sshfatal("auth2-pubkey.c", __func__, 115, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "internal error: initial hostkey not recorded");
  if (!sshkey_equal(hostkey, ssh->kex->initial_hostkey))
   sshfatal("auth2-pubkey.c", __func__, 117, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "%s packet contained wrong host key", method);
  sshbuf_free(b);
  b = 
     ((void *)0)
         ;
 }

 if (log_level_get() >= SYSLOG_LEVEL_DEBUG2) {
  char *keystring;
  struct sshbuf *pkbuf;

  if ((pkbuf = sshbuf_from(pkblob, blen)) == 
                                            ((void *)0)
                                                )
   sshfatal("auth2-pubkey.c", __func__, 127, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshbuf_from failed");
  if ((keystring = sshbuf_dtob64_string(pkbuf, 0)) == 
                                                     ((void *)0)
                                                         )
   sshfatal("auth2-pubkey.c", __func__, 129, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshbuf_dtob64 failed");
  sshlog("auth2-pubkey.c", __func__, 130, 1, SYSLOG_LEVEL_DEBUG2, 
 ((void *)0)
 , "%s user %s %s public key %s %s", authctxt->valid ? "valid" : "invalid", authctxt->user, have_sig ? "attempting" : "querying", pkalg, keystring)

                                                             ;
  sshbuf_free(pkbuf);
  free(keystring);
 }

 pktype = sshkey_type_from_name(pkalg);
 if (pktype == KEY_UNSPEC) {

  sshlog("auth2-pubkey.c", __func__, 140, 1, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "unsupported public key algorithm: %s", pkalg);
  goto done;
 }
 if ((r = sshkey_from_blob(pkblob, blen, &key)) != 0) {
  sshlog("auth2-pubkey.c", __func__, 144, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "parse key");
  goto done;
 }
 if (key == 
           ((void *)0)
               ) {
  sshlog("auth2-pubkey.c", __func__, 148, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "cannot decode key: %s", pkalg);
  goto done;
 }
 if (key->type != pktype) {
  sshlog("auth2-pubkey.c", __func__, 152, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "type mismatch for decoded key " "(received %d, expected %d)", key->type, pktype)
                                                      ;
  goto done;
 }
 if (sshkey_type_plain(key->type) == KEY_RSA &&
     (ssh->compat & 0x00002000) != 0) {
  sshlog("auth2-pubkey.c", __func__, 158, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "Refusing RSA key because client uses unsafe " "signature scheme")
                         ;
  goto done;
 }
 if (auth2_key_already_used(authctxt, key)) {
  sshlog("auth2-pubkey.c", __func__, 163, 0, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "refusing previously-used %s key", sshkey_type(key));
  goto done;
 }
 if (match_pattern_list(pkalg, options.pubkey_accepted_algos, 0) != 1) {
  sshlog("auth2-pubkey.c", __func__, 167, 1, SYSLOG_LEVEL_INFO, 
 ((void *)0)
 , "signature algorithm %s not in " "PubkeyAcceptedAlgorithms", pkalg)
                                        ;
  goto done;
 }
 if ((r = sshkey_check_cert_sigtype(key,
     options.ca_sign_algorithms)) != 0) {
  sshlog("auth2-pubkey.c", __func__, 173, 1, SYSLOG_LEVEL_INFO, ssh_err(r), "certificate signature algorithm %s", (key->cert == 
 ((void *)0) 
 || key->cert->signature_type == 
 ((void *)0)
 ) ? "(null)" : key->cert->signature_type)

                                           ;
  goto done;
 }
 if ((r = sshkey_check_rsa_length(key,
     options.required_rsa_size)) != 0) {
  sshlog("auth2-pubkey.c", __func__, 180, 0, SYSLOG_LEVEL_INFO, ssh_err(r), "refusing %s key", sshkey_type(key));
  goto done;
 }
 key_s = format_key(key);
 if (sshkey_is_cert(key))
  ca_s = format_key(key->cert->signature_key);

 if (have_sig) {
  sshlog("auth2-pubkey.c", __func__, 188, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "%s have %s signature for %s%s%s", method, pkalg, key_s, ca_s == 
 ((void *)0) 
 ? "" : " CA ", ca_s == 
 ((void *)0) 
 ? "" : ca_s)

                                                           ;
  if ((r = sshpkt_get_string(ssh, &sig, &slen)) != 0 ||
      (r = sshpkt_get_end(ssh)) != 0)
   sshfatal("auth2-pubkey.c", __func__, 193, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse signature packet");
  if ((b = sshbuf_new()) == 
                           ((void *)0)
                               )
   sshfatal("auth2-pubkey.c", __func__, 195, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "sshbuf_new failed");
  if (ssh->compat & 0x00000010) {
   if ((r = sshbuf_putb(b, ssh->kex->session_id)) != 0)
    sshfatal("auth2-pubkey.c", __func__, 198, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "put old session id");
  } else {
   if ((r = sshbuf_put_stringb(b,
       ssh->kex->session_id)) != 0)
    sshfatal("auth2-pubkey.c", __func__, 202, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "put session id");
  }
  if (!authctxt->valid || authctxt->user == 
                                           ((void *)0)
                                               ) {
   sshlog("auth2-pubkey.c", __func__, 205, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "disabled because of invalid user");
   goto done;
  }

  xasprintf(&userstyle, "%s%s%s", authctxt->user,
      authctxt->style ? ":" : "",
      authctxt->style ? authctxt->style : "");
  if ((r = sshbuf_put_u8(b, 50)) != 0 ||
      (r = sshbuf_put_cstring(b, userstyle)) != 0 ||
      (r = sshbuf_put_cstring(b, authctxt->service)) != 0 ||
      (r = sshbuf_put_cstring(b, method)) != 0 ||
      (r = sshbuf_put_u8(b, have_sig)) != 0 ||
      (r = sshbuf_put_cstring(b, pkalg)) != 0 ||
      (r = sshbuf_put_string(b, pkblob, blen)) != 0)
   sshfatal("auth2-pubkey.c", __func__, 219, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reconstruct %s packet", method);
  if (hostbound &&
      (r = sshkey_puts(ssh->kex->initial_hostkey, b)) != 0)
   sshfatal("auth2-pubkey.c", __func__, 222, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "reconstruct %s packet", method);




  authenticated = 0;
  if ((use_privsep ? mm_user_key_allowed(ssh, pw, key, 1, &authopts) : user_key_allowed(ssh, pw, key, 1, &authopts)) &&
      (use_privsep ? mm_sshkey_verify(key, sig, slen, sshbuf_ptr(b), sshbuf_len(b), (ssh->compat & 0x00000002) == 0 ? pkalg : 
     ((void *)0)
     , ssh->compat, &sig_details) : sshkey_verify(key, sig, slen, sshbuf_ptr(b), sshbuf_len(b), (ssh->compat & 0x00000002) == 0 ? pkalg : 
     ((void *)0)
     , ssh->compat, &sig_details))


                                  == 0) {
   authenticated = 1;
  }
  if (authenticated == 1 && sig_details != 
                                          ((void *)0)
                                              ) {
   auth2_record_info(authctxt, "signature count = %u",
       sig_details->sk_counter);
   sshlog("auth2-pubkey.c", __func__, 238, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "sk_counter = %u, sk_flags = 0x%02x", sig_details->sk_counter, sig_details->sk_flags)
                                                      ;
   req_presence = (options.pubkey_auth_options &
       (1)) ||
       !authopts->no_require_user_presence;
   if (req_presence && (sig_details->sk_flags &
       0x01) == 0) {
    sshlog("auth2-pubkey.c", __func__, 245, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "public key %s signature for %s%s from " "%.128s port %d rejected: user presence " "(authenticator touch) requirement " "not met ", key_s, authctxt->valid ? "" : "invalid user ", authctxt->user, ssh_remote_ipaddr(ssh), ssh_remote_port(ssh))





                             ;
    authenticated = 0;
    goto done;
   }
   req_verify = (options.pubkey_auth_options &
       (1<<1)) ||
       authopts->require_verify;
   if (req_verify && (sig_details->sk_flags &
       0x04) == 0) {
    sshlog("auth2-pubkey.c", __func__, 260, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "public key %s signature for %s%s from " "%.128s port %d rejected: user " "verification requirement not met ", key_s, authctxt->valid ? "" : "invalid user ", authctxt->user, ssh_remote_ipaddr(ssh), ssh_remote_port(ssh))




                             ;
    authenticated = 0;
    goto done;
   }
  }
  auth2_record_key(authctxt, authenticated, key);
 } else {
  sshlog("auth2-pubkey.c", __func__, 272, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "%s test pkalg %s pkblob %s%s%s", method, pkalg, key_s, ca_s == 
 ((void *)0) 
 ? "" : " CA ", ca_s == 
 ((void *)0) 
 ? "" : ca_s)
                                                           ;

  if ((r = sshpkt_get_end(ssh)) != 0)
   sshfatal("auth2-pubkey.c", __func__, 276, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "parse packet");

  if (!authctxt->valid || authctxt->user == 
                                           ((void *)0)
                                               ) {
   sshlog("auth2-pubkey.c", __func__, 279, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "disabled because of invalid user");
   goto done;
  }
  if ((use_privsep ? mm_user_key_allowed(ssh, pw, key, 0, 
     ((void *)0)
     ) : user_key_allowed(ssh, pw, key, 0, 
     ((void *)0)
     ))) {
   if ((r = sshpkt_start(ssh, 60))
       != 0 ||
       (r = sshpkt_put_cstring(ssh, pkalg)) != 0 ||
       (r = sshpkt_put_string(ssh, pkblob, blen)) != 0 ||
       (r = sshpkt_send(ssh)) != 0 ||
       (r = ssh_packet_write_wait(ssh)) != 0)
    sshfatal("auth2-pubkey.c", __func__, 297, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "send packet");
   authctxt->postponed = 1;
  }
 }
done:
 if (authenticated == 1 && auth_activate_options(ssh, authopts) != 0) {
  sshlog("auth2-pubkey.c", __func__, 303, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "key options inconsistent with existing");
  authenticated = 0;
 }
 sshlog("auth2-pubkey.c", __func__, 306, 1, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "authenticated %d pkalg %s", authenticated, pkalg);

 sshbuf_free(b);
 sshauthopt_free(authopts);
 sshkey_free(key);
 sshkey_free(hostkey);
 free(userstyle);
 free(pkalg);
 free(pkblob);
 free(key_s);
 free(ca_s);
 free(sig);
 sshkey_sig_details_free(sig_details);
 return authenticated;
}

static int
match_principals_file(struct passwd *pw, char *file,
    struct sshkey_cert *cert, struct sshauthopt **authoptsp)
{
 FILE *f;
 int success;

 if (authoptsp != 
                 ((void *)0)
                     )
  *authoptsp = 
              ((void *)0)
                  ;

 temporarily_use_uid(pw);
 sshlog("auth2-pubkey.c", __func__, 333, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "trying authorized principals file %s", file);
 if ((f = auth_openprincipals(file, pw, options.strict_modes)) == 
                                                                 ((void *)0)
                                                                     ) {
  restore_uid();
  return 0;
 }
 success = auth_process_principals(f, file, cert, authoptsp);
 fclose(f);
 restore_uid();
 return success;
}





static int
match_principals_command(struct passwd *user_pw,
    const struct sshkey *key, struct sshauthopt **authoptsp)
{
 struct passwd *runas_pw = 
                          ((void *)0)
                              ;
 const struct sshkey_cert *cert = key->cert;
 FILE *f = 
          ((void *)0)
              ;
 int r, ok, found_principal = 0;
 int i, ac = 0, uid_swapped = 0;
 pid_t pid;
 char *tmp, *username = 
                       ((void *)0)
                           , *command = 
                                        ((void *)0)
                                            , **av = 
                                                     ((void *)0)
                                                         ;
 char *ca_fp = 
              ((void *)0)
                  , *key_fp = 
                              ((void *)0)
                                  , *catext = 
                                              ((void *)0)
                                                  , *keytext = 
                                                               ((void *)0)
                                                                   ;
 char serial_s[32], uidstr[32];
 void (*osigchld)(int);

 if (authoptsp != 
                 ((void *)0)
                     )
  *authoptsp = 
              ((void *)0)
                  ;
 if (options.authorized_principals_command == 
                                             ((void *)0)
                                                 )
  return 0;
 if (options.authorized_principals_command_user == 
                                                  ((void *)0)
                                                      ) {
  sshlog("auth2-pubkey.c", __func__, 368, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "No user for AuthorizedPrincipalsCommand specified, " "skipping")
                 ;
  return 0;
 }





 osigchld = ssh_signal(
                      17
                             , 
                               ((__sighandler_t) 0)
                                      );


 username = percent_expand(options.authorized_principals_command_user,
     "u", user_pw->pw_name, (char *)
                                   ((void *)0)
                                       );
 runas_pw = getpwnam(username);
 if (runas_pw == 
                ((void *)0)
                    ) {
  sshlog("auth2-pubkey.c", __func__, 384, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "AuthorizedPrincipalsCommandUser \"%s\" not found: %s", username, strerror(
 (*__errno_location ())
 ))
                                ;
  goto out;
 }


 if (argv_split(options.authorized_principals_command,
     &ac, &av, 0) != 0) {
  sshlog("auth2-pubkey.c", __func__, 392, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "AuthorizedPrincipalsCommand \"%s\" contains " "invalid quotes", options.authorized_principals_command)
                                                              ;
  goto out;
 }
 if (ac == 0) {
  sshlog("auth2-pubkey.c", __func__, 397, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "AuthorizedPrincipalsCommand \"%s\" yielded no arguments", options.authorized_principals_command)
                                            ;
  goto out;
 }
 if ((ca_fp = sshkey_fingerprint(cert->signature_key,
     options.fingerprint_hash, SSH_FP_DEFAULT)) == 
                                                  ((void *)0)
                                                      ) {
  sshlog("auth2-pubkey.c", __func__, 403, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshkey_fingerprint failed");
  goto out;
 }
 if ((key_fp = sshkey_fingerprint(key,
     options.fingerprint_hash, SSH_FP_DEFAULT)) == 
                                                  ((void *)0)
                                                      ) {
  sshlog("auth2-pubkey.c", __func__, 408, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshkey_fingerprint failed");
  goto out;
 }
 if ((r = sshkey_to_base64(cert->signature_key, &catext)) != 0) {
  sshlog("auth2-pubkey.c", __func__, 412, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshkey_to_base64 failed");
  goto out;
 }
 if ((r = sshkey_to_base64(key, &keytext)) != 0) {
  sshlog("auth2-pubkey.c", __func__, 416, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshkey_to_base64 failed");
  goto out;
 }
 snprintf(serial_s, sizeof(serial_s), "%llu",
     (unsigned long long)cert->serial);
 snprintf(uidstr, sizeof(uidstr), "%llu",
     (unsigned long long)user_pw->pw_uid);
 for (i = 1; i < ac; i++) {
  tmp = percent_expand(av[i],
      "U", uidstr,
      "u", user_pw->pw_name,
      "h", user_pw->pw_dir,
      "t", sshkey_ssh_name(key),
      "T", sshkey_ssh_name(cert->signature_key),
      "f", key_fp,
      "F", ca_fp,
      "k", keytext,
      "K", catext,
      "i", cert->key_id,
      "s", serial_s,
      (char *)
             ((void *)0)
                 );
  if (tmp == 
            ((void *)0)
                )
   sshfatal("auth2-pubkey.c", __func__, 438, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "percent_expand failed");
  free(av[i]);
  av[i] = tmp;
 }

 command = argv_assemble(ac, av);

 if ((pid = subprocess("AuthorizedPrincipalsCommand", command,
     ac, av, &f,
     (1<<1)|(1<<2),
     runas_pw, temporarily_use_uid, restore_uid)) == 0)
  goto out;

 uid_swapped = 1;
 temporarily_use_uid(runas_pw);

 ok = auth_process_principals(f, "(command)", cert, authoptsp);

 fclose(f);
 f = 
    ((void *)0)
        ;

 if (exited_cleanly(pid, "AuthorizedPrincipalsCommand", command, 0) != 0)
  goto out;


 found_principal = ok;
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
 if (uid_swapped)
  restore_uid();
 free(command);
 free(username);
 free(ca_fp);
 free(key_fp);
 free(catext);
 free(keytext);
 return found_principal;
}


static int
user_cert_trusted_ca(struct passwd *pw, struct sshkey *key,
    const char *remote_ip, const char *remote_host,
    struct sshauthopt **authoptsp)
{
 char *ca_fp, *principals_file = 
                                ((void *)0)
                                    ;
 const char *reason;
 struct sshauthopt *principals_opts = 
                                     ((void *)0)
                                         , *cert_opts = 
                                                        ((void *)0)
                                                            ;
 struct sshauthopt *final_opts = 
                                ((void *)0)
                                    ;
 int r, ret = 0, found_principal = 0, use_authorized_principals;

 if (authoptsp != 
                 ((void *)0)
                     )
  *authoptsp = 
              ((void *)0)
                  ;

 if (!sshkey_is_cert(key) || options.trusted_user_ca_keys == 
                                                            ((void *)0)
                                                                )
  return 0;

 if ((ca_fp = sshkey_fingerprint(key->cert->signature_key,
     options.fingerprint_hash, SSH_FP_DEFAULT)) == 
                                                  ((void *)0)
                                                      )
  return 0;

 if ((r = sshkey_in_file(key->cert->signature_key,
     options.trusted_user_ca_keys, 1, 0)) != 0) {
  sshlog("auth2-pubkey.c", __func__, 506, 1, SYSLOG_LEVEL_DEBUG2, ssh_err(r), "CA %s %s is not listed in %s", sshkey_type(key->cert->signature_key), ca_fp, options.trusted_user_ca_keys)

                                   ;
  goto out;
 }





 if ((principals_file = authorized_principals_file(pw)) != 
                                                          ((void *)0)
                                                              ) {
  if (match_principals_file(pw, principals_file,
      key->cert, &principals_opts))
   found_principal = 1;
 }

 if (!found_principal && match_principals_command(pw, key,
     &principals_opts))
  found_principal = 1;

 use_authorized_principals = principals_file != 
                                               ((void *)0) 
                                                    ||
     options.authorized_principals_command != 
                                             ((void *)0)
                                                 ;
 if (!found_principal && use_authorized_principals) {
  reason = "Certificate does not contain an authorized principal";
  goto fail_reason;
 }
 if (use_authorized_principals && principals_opts == 
                                                    ((void *)0)
                                                        )
  sshfatal("auth2-pubkey.c", __func__, 533, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "internal error: missing principals_opts");
 if (sshkey_cert_check_authority_now(key, 0, 1, 0,
     use_authorized_principals ? 
                                ((void *)0) 
                                     : pw->pw_name, &reason) != 0)
  goto fail_reason;


 if ((cert_opts = sshauthopt_from_cert(key)) == 
                                               ((void *)0)
                                                   ) {
  reason = "Invalid certificate options";
  goto fail_reason;
 }
 if (auth_authorise_keyopts(pw, cert_opts, 0,
     remote_ip, remote_host, "cert") != 0) {
  reason = "Refused by certificate options";
  goto fail_reason;
 }
 if (principals_opts == 
                       ((void *)0)
                           ) {
  final_opts = cert_opts;
  cert_opts = 
             ((void *)0)
                 ;
 } else {
  if (auth_authorise_keyopts(pw, principals_opts, 0,
      remote_ip, remote_host, "principals") != 0) {
   reason = "Refused by certificate principals options";
   goto fail_reason;
  }
  if ((final_opts = sshauthopt_merge(principals_opts,
      cert_opts, &reason)) == 
                             ((void *)0)
                                 ) {
 fail_reason:
   sshlog("auth2-pubkey.c", __func__, 560, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "%s", reason);
   auth_debug_add("%s", reason);
   goto out;
  }
 }


 sshlog("auth2-pubkey.c", __func__, 567, 0, SYSLOG_LEVEL_VERBOSE, 
((void *)0)
, "Accepted certificate ID \"%s\" (serial %llu) signed by " "%s CA %s via %s", key->cert->key_id, (unsigned long long)key->cert->serial, sshkey_type(key->cert->signature_key), ca_fp, options.trusted_user_ca_keys)



                                  ;
 if (authoptsp != 
                 ((void *)0)
                     ) {
  *authoptsp = final_opts;
  final_opts = 
              ((void *)0)
                  ;
 }
 ret = 1;
 out:
 sshauthopt_free(principals_opts);
 sshauthopt_free(cert_opts);
 sshauthopt_free(final_opts);
 free(principals_file);
 free(ca_fp);
 return ret;
}





static int
user_key_allowed2(struct passwd *pw, struct sshkey *key,
    char *file, const char *remote_ip, const char *remote_host,
    struct sshauthopt **authoptsp)
{
 FILE *f;
 int found_key = 0;

 if (authoptsp != 
                 ((void *)0)
                     )
  *authoptsp = 
              ((void *)0)
                  ;


 temporarily_use_uid(pw);

 sshlog("auth2-pubkey.c", __func__, 604, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "trying public key file %s", file);
 if ((f = auth_openkeyfile(file, pw, options.strict_modes)) != 
                                                              ((void *)0)
                                                                  ) {
  found_key = auth_check_authkeys_file(pw, f, file,
      key, remote_ip, remote_host, authoptsp);
  fclose(f);
 }

 restore_uid();
 return found_key;
}





static int
user_key_command_allowed2(struct passwd *user_pw, struct sshkey *key,
    const char *remote_ip, const char *remote_host,
    struct sshauthopt **authoptsp)
{
 struct passwd *runas_pw = 
                          ((void *)0)
                              ;
 FILE *f = 
          ((void *)0)
              ;
 int r, ok, found_key = 0;
 int i, uid_swapped = 0, ac = 0;
 pid_t pid;
 char *username = 
                 ((void *)0)
                     , *key_fp = 
                                 ((void *)0)
                                     , *keytext = 
                                                  ((void *)0)
                                                      ;
 char uidstr[32], *tmp, *command = 
                                  ((void *)0)
                                      , **av = 
                                               ((void *)0)
                                                   ;
 void (*osigchld)(int);

 if (authoptsp != 
                 ((void *)0)
                     )
  *authoptsp = 
              ((void *)0)
                  ;
 if (options.authorized_keys_command == 
                                       ((void *)0)
                                           )
  return 0;
 if (options.authorized_keys_command_user == 
                                            ((void *)0)
                                                ) {
  sshlog("auth2-pubkey.c", __func__, 638, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "No user for AuthorizedKeysCommand specified, skipping");
  return 0;
 }





 osigchld = ssh_signal(
                      17
                             , 
                               ((__sighandler_t) 0)
                                      );


 username = percent_expand(options.authorized_keys_command_user,
     "u", user_pw->pw_name, (char *)
                                   ((void *)0)
                                       );
 runas_pw = getpwnam(username);
 if (runas_pw == 
                ((void *)0)
                    ) {
  sshlog("auth2-pubkey.c", __func__, 653, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "AuthorizedKeysCommandUser \"%s\" not found: %s", username, strerror(
 (*__errno_location ())
 ))
                                ;
  goto out;
 }


 if ((key_fp = sshkey_fingerprint(key, options.fingerprint_hash,
     SSH_FP_DEFAULT)) == 
                        ((void *)0)
                            ) {
  sshlog("auth2-pubkey.c", __func__, 661, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshkey_fingerprint failed");
  goto out;
 }
 if ((r = sshkey_to_base64(key, &keytext)) != 0) {
  sshlog("auth2-pubkey.c", __func__, 665, 1, SYSLOG_LEVEL_ERROR, ssh_err(r), "sshkey_to_base64 failed");
  goto out;
 }


 if (argv_split(options.authorized_keys_command, &ac, &av, 0) != 0) {
  sshlog("auth2-pubkey.c", __func__, 671, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "AuthorizedKeysCommand \"%s\" contains invalid quotes", options.authorized_keys_command)
                                      ;
  goto out;
 }
 if (ac == 0) {
  sshlog("auth2-pubkey.c", __func__, 676, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "AuthorizedKeysCommand \"%s\" yielded no arguments", options.authorized_keys_command)
                                      ;
  goto out;
 }
 snprintf(uidstr, sizeof(uidstr), "%llu",
     (unsigned long long)user_pw->pw_uid);
 for (i = 1; i < ac; i++) {
  tmp = percent_expand(av[i],
      "U", uidstr,
      "u", user_pw->pw_name,
      "h", user_pw->pw_dir,
      "t", sshkey_ssh_name(key),
      "f", key_fp,
      "k", keytext,
      (char *)
             ((void *)0)
                 );
  if (tmp == 
            ((void *)0)
                )
   sshfatal("auth2-pubkey.c", __func__, 692, 1, SYSLOG_LEVEL_FATAL, 
  ((void *)0)
  , "percent_expand failed");
  free(av[i]);
  av[i] = tmp;
 }

 command = argv_assemble(ac, av);






 if (ac == 1) {
  av = xreallocarray(av, ac + 2, sizeof(*av));
  av[1] = xstrdup(user_pw->pw_name);
  av[2] = 
         ((void *)0)
             ;

  free(command);
  xasprintf(&command, "%s %s", av[0], av[1]);
 }

 if ((pid = subprocess("AuthorizedKeysCommand", command,
     ac, av, &f,
     (1<<1)|(1<<2),
     runas_pw, temporarily_use_uid, restore_uid)) == 0)
  goto out;

 uid_swapped = 1;
 temporarily_use_uid(runas_pw);

 ok = auth_check_authkeys_file(user_pw, f,
     options.authorized_keys_command, key, remote_ip,
     remote_host, authoptsp);

 fclose(f);
 f = 
    ((void *)0)
        ;

 if (exited_cleanly(pid, "AuthorizedKeysCommand", command, 0) != 0)
  goto out;


 found_key = ok;
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
 if (uid_swapped)
  restore_uid();
 free(command);
 free(username);
 free(key_fp);
 free(keytext);
 return found_key;
}




int
user_key_allowed(struct ssh *ssh, struct passwd *pw, struct sshkey *key,
    int auth_attempt, struct sshauthopt **authoptsp)
{
 u_int success = 0, i;
 char *file;
 struct sshauthopt *opts = 
                          ((void *)0)
                              ;
 const char *remote_ip = ssh_remote_ipaddr(ssh);
 const char *remote_host = auth_get_canonical_hostname(ssh,
     options.use_dns);

 if (authoptsp != 
                 ((void *)0)
                     )
  *authoptsp = 
              ((void *)0)
                  ;

 if (auth_key_is_revoked(key))
  return 0;
 if (sshkey_is_cert(key) &&
     auth_key_is_revoked(key->cert->signature_key))
  return 0;

 for (i = 0; !success && i < options.num_authkeys_files; i++) {
  if (strcasecmp(options.authorized_keys_files[i], "none") == 0)
   continue;
  file = expand_authorized_keys(
      options.authorized_keys_files[i], pw);
  success = user_key_allowed2(pw, key, file,
      remote_ip, remote_host, &opts);
  free(file);
  if (!success) {
   sshauthopt_free(opts);
   opts = 
         ((void *)0)
             ;
  }
 }
 if (success)
  goto out;

 if ((success = user_cert_trusted_ca(pw, key, remote_ip, remote_host,
     &opts)) != 0)
  goto out;
 sshauthopt_free(opts);
 opts = 
       ((void *)0)
           ;

 if ((success = user_key_command_allowed2(pw, key, remote_ip,
     remote_host, &opts)) != 0)
  goto out;
 sshauthopt_free(opts);
 opts = 
       ((void *)0)
           ;

 out:
 if (success && authoptsp != 
                            ((void *)0)
                                ) {
  *authoptsp = opts;
  opts = 
        ((void *)0)
            ;
 }
 sshauthopt_free(opts);
 return success;
}

Authmethod method_pubkey = {
 "publickey",
 "publickey-hostbound-v00@openssh.com",
 userauth_pubkey,
 &options.pubkey_authentication
};
