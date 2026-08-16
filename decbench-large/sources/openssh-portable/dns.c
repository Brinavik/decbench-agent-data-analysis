











































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
const char *ssh_err(int n);
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

static const char * const errset_text[] = {
 "success",
 "out of memory",
 "general failure",
 "invalid parameter",
 "name does not exist",
 "data does not exist",
};

static const char *
dns_result_totext(unsigned int res)
{
 switch (res) {
 case 0:
  return errset_text[0];
 case 1:
  return errset_text[1];
 case 2:
  return errset_text[2];
 case 3:
  return errset_text[3];
 case 4:
  return errset_text[4];
 case 5:
  return errset_text[5];
 default:
  return "unknown error";
 }
}





static int
dns_read_key(u_int8_t *algorithm, u_int8_t *digest_type,
    u_char **digest, size_t *digest_len, struct sshkey *key)
{
 int r, success = 0;
 int fp_alg = -1;

 switch (key->type) {
 case KEY_RSA:
  *algorithm = SSHFP_KEY_RSA;
  break;
 case KEY_DSA:
  *algorithm = SSHFP_KEY_DSA;
  break;
 case KEY_ECDSA:
  *algorithm = SSHFP_KEY_ECDSA;
  break;
 case KEY_ED25519:
  *algorithm = SSHFP_KEY_ED25519;
  break;
 case KEY_XMSS:
  *algorithm = SSHFP_KEY_XMSS;
  break;
 default:
  *algorithm = SSHFP_KEY_RESERVED;
 }

 switch (*digest_type) {
 case SSHFP_HASH_SHA1:
  fp_alg = 1;
  break;
 case SSHFP_HASH_SHA256:
  fp_alg = 2;
  break;
 default:
  *digest_type = SSHFP_HASH_RESERVED;
 }

 if (*algorithm && *digest_type) {
  if ((r = sshkey_fingerprint_raw(key, fp_alg, digest,
      digest_len)) != 0)
   sshfatal("dns.c", __func__, 121, 1, SYSLOG_LEVEL_FATAL, ssh_err(r), "sshkey_fingerprint_raw");
  success = 1;
 } else {
  *digest = 
           ((void *)0)
               ;
  *digest_len = 0;
 }

 return success;
}




static int
dns_read_rdata(u_int8_t *algorithm, u_int8_t *digest_type,
    u_char **digest, size_t *digest_len, u_char *rdata, int rdata_len)
{
 int success = 0;

 *algorithm = SSHFP_KEY_RESERVED;
 *digest_type = SSHFP_HASH_RESERVED;

 if (rdata_len >= 2) {
  *algorithm = rdata[0];
  *digest_type = rdata[1];
  *digest_len = rdata_len - 2;

  if (*digest_len > 0) {
   *digest = xmalloc(*digest_len);
   memcpy(*digest, rdata + 2, *digest_len);
  } else {
   *digest = (u_char *)xstrdup("");
  }

  success = 1;
 }

 return success;
}





static int
is_numeric_hostname(const char *hostname)
{
 struct addrinfo hints, *ai;





 if (hostname == 
                ((void *)0)
                    ) {
  sshlog("dns.c", __func__, 175, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "is_numeric_hostname called with NULL hostname");
  return -1;
 }

 memset(&hints, 0, sizeof(hints));
 hints.ai_socktype = 
                    SOCK_DGRAM
                              ;
 hints.ai_flags = 
                 0x0004
                               ;

 if (getaddrinfo(hostname, 
                          ((void *)0)
                              , &hints, &ai) == 0) {
  freeaddrinfo(ai);
  return -1;
 }

 return 0;
}





int
verify_host_key_dns(const char *hostname, struct sockaddr *address,
    struct sshkey *hostkey, int *flags)
{
 u_int counter;
 int result;
 struct rrsetinfo *fingerprints = 
                                 ((void *)0)
                                     ;

 u_int8_t hostkey_algorithm;
 u_char *hostkey_digest;
 size_t hostkey_digest_len;

 u_int8_t dnskey_algorithm;
 u_int8_t dnskey_digest_type;
 u_char *dnskey_digest;
 size_t dnskey_digest_len;

 *flags = 0;

 sshlog("dns.c", __func__, 214, 0, SYSLOG_LEVEL_DEBUG3, 
((void *)0)
, "verify_host_key_dns");
 if (hostkey == 
               ((void *)0)
                   )
  sshfatal("dns.c", __func__, 216, 0, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "No key to look up!");

 if (is_numeric_hostname(hostname)) {
  sshlog("dns.c", __func__, 219, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "skipped DNS lookup for numerical hostname");
  return -1;
 }

 result = getrrsetbyname(hostname, 1,
     44, 0, &fingerprints);
 if (result) {
  sshlog("dns.c", __func__, 226, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "DNS lookup error: %s", dns_result_totext(result));
  return -1;
 }

 if (fingerprints->rri_flags & 1) {
  *flags |= 0x00000004;
  sshlog("dns.c", __func__, 232, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "found %d secure fingerprints in DNS", fingerprints->rri_nrdatas)
                                ;
 } else {
  sshlog("dns.c", __func__, 235, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "found %d insecure fingerprints in DNS", fingerprints->rri_nrdatas)
                                ;
 }

 if (fingerprints->rri_nrdatas)
  *flags |= 0x00000001;

 for (counter = 0; counter < fingerprints->rri_nrdatas; counter++) {




  if (!dns_read_rdata(&dnskey_algorithm, &dnskey_digest_type,
      &dnskey_digest, &dnskey_digest_len,
      fingerprints->rri_rdatas[counter].rdi_data,
      fingerprints->rri_rdatas[counter].rdi_length)) {
   sshlog("dns.c", __func__, 251, 0, SYSLOG_LEVEL_VERBOSE, 
  ((void *)0)
  , "Error parsing fingerprint from DNS.");
   continue;
  }
  sshlog("dns.c", __func__, 254, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "checking SSHFP type %d fptype %d", dnskey_algorithm, dnskey_digest_type)
                         ;


  if (!dns_read_key(&hostkey_algorithm, &dnskey_digest_type,
      &hostkey_digest, &hostkey_digest_len, hostkey)) {
   sshlog("dns.c", __func__, 260, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "Error calculating key fingerprint.");
   freerrset(fingerprints);
   return -1;
  }


  if (hostkey_algorithm == dnskey_algorithm &&
      hostkey_digest_len == dnskey_digest_len) {
   if (timingsafe_bcmp(hostkey_digest, dnskey_digest,
       hostkey_digest_len) == 0) {
    sshlog("dns.c", __func__, 270, 1, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "matched SSHFP type %d fptype %d", dnskey_algorithm, dnskey_digest_type)
                                             ;
    *flags |= 0x00000002;
   } else {
    sshlog("dns.c", __func__, 274, 1, SYSLOG_LEVEL_DEBUG1, 
   ((void *)0)
   , "failed SSHFP type %d fptype %d", dnskey_algorithm, dnskey_digest_type)
                                             ;
    *flags |= 0x00000008;
   }
  }
  free(dnskey_digest);
  free(hostkey_digest);
 }

 freerrset(fingerprints);


 if (*flags & 0x00000008)
  *flags &= ~0x00000002;

 if (*flags & 0x00000001)
  if (*flags & 0x00000002)
   sshlog("dns.c", __func__, 291, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "matching host key fingerprint found in DNS");
  else
   sshlog("dns.c", __func__, 293, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "mismatching host key fingerprint found in DNS");
 else
  sshlog("dns.c", __func__, 295, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "no host key fingerprint found in DNS");

 return 0;
}




int
export_dns_rr(const char *hostname, struct sshkey *key, FILE *f, int generic)
{
 u_int8_t rdata_pubkey_algorithm = 0;
 u_int8_t rdata_digest_type = SSHFP_HASH_RESERVED;
 u_int8_t dtype;
 u_char *rdata_digest;
 size_t i, rdata_digest_len;
 int success = 0;

 for (dtype = SSHFP_HASH_SHA1; dtype < SSHFP_HASH_MAX; dtype++) {
  rdata_digest_type = dtype;
  if (dns_read_key(&rdata_pubkey_algorithm, &rdata_digest_type,
      &rdata_digest, &rdata_digest_len, key)) {
   if (generic) {
    fprintf(f, "%s IN TYPE%d \\# %zu %02x %02x ",
        hostname, 44,
        2 + rdata_digest_len,
        rdata_pubkey_algorithm, rdata_digest_type);
   } else {
    fprintf(f, "%s IN SSHFP %d %d ", hostname,
        rdata_pubkey_algorithm, rdata_digest_type);
   }
   for (i = 0; i < rdata_digest_len; i++)
    fprintf(f, "%02x", rdata_digest[i]);
   fprintf(f, "\n");
   free(rdata_digest);
   success = 1;
  }
 }


 if (success == 0) {
  sshlog("dns.c", __func__, 336, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unsupported algorithm and/or digest_type");
 }

 return success;
}
