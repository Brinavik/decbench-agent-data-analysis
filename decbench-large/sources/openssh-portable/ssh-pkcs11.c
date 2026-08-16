











































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




typedef unsigned long CK_FLAGS;

struct _CK_VERSION
{
  unsigned char major;
  unsigned char minor;
};


struct _CK_INFO
{
  struct _CK_VERSION cryptokiVersion;
  unsigned char manufacturerID[32];
  CK_FLAGS flags;
  unsigned char libraryDescription[32];
  struct _CK_VERSION libraryVersion;
};


typedef unsigned long CK_NOTIFICATION;




typedef unsigned long CK_SLOT_ID;


struct _CK_SLOT_INFO
{
  unsigned char slotDescription[64];
  unsigned char manufacturerID[32];
  CK_FLAGS flags;
  struct _CK_VERSION hardwareVersion;
  struct _CK_VERSION firmwareVersion;
};
struct _CK_TOKEN_INFO
{
  unsigned char label[32];
  unsigned char manufacturerID[32];
  unsigned char model[16];
  unsigned char serialNumber[16];
  CK_FLAGS flags;
  unsigned long ulMaxSessionCount;
  unsigned long ulSessionCount;
  unsigned long ulMaxRwSessionCount;
  unsigned long ulRwSessionCount;
  unsigned long ulMaxPinLen;
  unsigned long ulMinPinLen;
  unsigned long ulTotalPublicMemory;
  unsigned long ulFreePublicMemory;
  unsigned long ulTotalPrivateMemory;
  unsigned long ulFreePrivateMemory;
  struct _CK_VERSION hardwareVersion;
  struct _CK_VERSION firmwareVersion;
  unsigned char utcTime[16];
};
typedef unsigned long CK_SESSION_HANDLE;




typedef unsigned long CK_USER_TYPE;






typedef unsigned long CK_STATE;
struct _CK_SESSION_INFO
{
  CK_SLOT_ID slotID;
  CK_STATE state;
  CK_FLAGS flags;
  unsigned long ulDeviceError;
};





typedef unsigned long CK_OBJECT_HANDLE;


typedef unsigned long CK_OBJECT_CLASS;
typedef unsigned long CK_HW_FEATURE_TYPE;







typedef unsigned long CK_KEY_TYPE;
typedef unsigned long CK_CERTIFICATE_TYPE;







typedef unsigned long CK_ATTRIBUTE_TYPE;
struct _CK_ATTRIBUTE
{
  CK_ATTRIBUTE_TYPE type;
  void *pValue;
  unsigned long ulValueLen;
};


struct _CK_DATE
{
  unsigned char year[4];
  unsigned char month[2];
  unsigned char day[2];
};


typedef unsigned long CK_MECHANISM_TYPE;
struct _CK_MECHANISM
{
  CK_MECHANISM_TYPE mechanism;
  void *pParameter;
  unsigned long ulParameterLen;
};


struct _CK_MECHANISM_INFO
{
  unsigned long ulMinKeySize;
  unsigned long ulMaxKeySize;
  CK_FLAGS flags;
};
typedef unsigned long CK_RV;


typedef CK_RV (*CK_NOTIFY) (CK_SESSION_HANDLE session,
    CK_NOTIFICATION event, void *application);


struct _CK_FUNCTION_LIST;





typedef CK_RV (*CK_C_Initialize) (void *init_args); CK_RV C_Initialize (void *init_args);
typedef CK_RV (*CK_C_Finalize) (void *pReserved); CK_RV C_Finalize (void *pReserved);
typedef CK_RV (*CK_C_GetInfo) (struct _CK_INFO *info); CK_RV C_GetInfo (struct _CK_INFO *info);
typedef CK_RV (*CK_C_GetFunctionList) (struct _CK_FUNCTION_LIST **function_list); CK_RV C_GetFunctionList (struct _CK_FUNCTION_LIST **function_list)
                                                  ;

typedef CK_RV (*CK_C_GetSlotList) (unsigned char token_present, CK_SLOT_ID *slot_list, unsigned long *count); CK_RV C_GetSlotList (unsigned char token_present, CK_SLOT_ID *slot_list, unsigned long *count)

                               ;
typedef CK_RV (*CK_C_GetSlotInfo) (CK_SLOT_ID slotID, struct _CK_SLOT_INFO *info); CK_RV C_GetSlotInfo (CK_SLOT_ID slotID, struct _CK_SLOT_INFO *info)
                                                          ;
typedef CK_RV (*CK_C_GetTokenInfo) (CK_SLOT_ID slotID, struct _CK_TOKEN_INFO *info); CK_RV C_GetTokenInfo (CK_SLOT_ID slotID, struct _CK_TOKEN_INFO *info)
                                                           ;
typedef CK_RV (*CK_C_WaitForSlotEvent) (CK_FLAGS flags, CK_SLOT_ID *slot, void *pReserved); CK_RV C_WaitForSlotEvent (CK_FLAGS flags, CK_SLOT_ID *slot, void *pReserved)
                                                               ;
typedef CK_RV (*CK_C_GetMechanismList) (CK_SLOT_ID slotID, CK_MECHANISM_TYPE *mechanism_list, unsigned long *count); CK_RV C_GetMechanismList (CK_SLOT_ID slotID, CK_MECHANISM_TYPE *mechanism_list, unsigned long *count)


                               ;
typedef CK_RV (*CK_C_GetMechanismInfo) (CK_SLOT_ID slotID, CK_MECHANISM_TYPE type, struct _CK_MECHANISM_INFO *info); CK_RV C_GetMechanismInfo (CK_SLOT_ID slotID, CK_MECHANISM_TYPE type, struct _CK_MECHANISM_INFO *info)

                                         ;
typedef CK_RV (*CK_C_InitToken) (CK_SLOT_ID slotID, unsigned char *pin, unsigned long pin_len, unsigned char *label); CK_RV C_InitToken (CK_SLOT_ID slotID, unsigned char *pin, unsigned long pin_len, unsigned char *label)

                                                      ;
typedef CK_RV (*CK_C_InitPIN) (CK_SESSION_HANDLE session, unsigned char *pin, unsigned long pin_len); CK_RV C_InitPIN (CK_SESSION_HANDLE session, unsigned char *pin, unsigned long pin_len)

                                ;
typedef CK_RV (*CK_C_SetPIN) (CK_SESSION_HANDLE session, unsigned char *old_pin, unsigned long old_len, unsigned char *new_pin, unsigned long new_len); CK_RV C_SetPIN (CK_SESSION_HANDLE session, unsigned char *old_pin, unsigned long old_len, unsigned char *new_pin, unsigned long new_len)


                                ;

typedef CK_RV (*CK_C_OpenSession) (CK_SLOT_ID slotID, CK_FLAGS flags, void *application, CK_NOTIFY notify, CK_SESSION_HANDLE *session); CK_RV C_OpenSession (CK_SLOT_ID slotID, CK_FLAGS flags, void *application, CK_NOTIFY notify, CK_SESSION_HANDLE *session)


                                       ;
typedef CK_RV (*CK_C_CloseSession) (CK_SESSION_HANDLE session); CK_RV C_CloseSession (CK_SESSION_HANDLE session);
typedef CK_RV (*CK_C_CloseAllSessions) (CK_SLOT_ID slotID); CK_RV C_CloseAllSessions (CK_SLOT_ID slotID);
typedef CK_RV (*CK_C_GetSessionInfo) (CK_SESSION_HANDLE session, struct _CK_SESSION_INFO *info); CK_RV C_GetSessionInfo (CK_SESSION_HANDLE session, struct _CK_SESSION_INFO *info)

                                       ;
typedef CK_RV (*CK_C_GetOperationState) (CK_SESSION_HANDLE session, unsigned char *operation_state, unsigned long *operation_state_len); CK_RV C_GetOperationState (CK_SESSION_HANDLE session, unsigned char *operation_state, unsigned long *operation_state_len)


                                             ;
typedef CK_RV (*CK_C_SetOperationState) (CK_SESSION_HANDLE session, unsigned char *operation_state, unsigned long operation_state_len, CK_OBJECT_HANDLE encryption_key, CK_OBJECT_HANDLE authentiation_key); CK_RV C_SetOperationState (CK_SESSION_HANDLE session, unsigned char *operation_state, unsigned long operation_state_len, CK_OBJECT_HANDLE encryption_key, CK_OBJECT_HANDLE authentiation_key)




                                               ;
typedef CK_RV (*CK_C_Login) (CK_SESSION_HANDLE session, CK_USER_TYPE user_type, unsigned char *pin, unsigned long pin_len); CK_RV C_Login (CK_SESSION_HANDLE session, CK_USER_TYPE user_type, unsigned char *pin, unsigned long pin_len)

                                                    ;
typedef CK_RV (*CK_C_Logout) (CK_SESSION_HANDLE session); CK_RV C_Logout (CK_SESSION_HANDLE session);

typedef CK_RV (*CK_C_CreateObject) (CK_SESSION_HANDLE session, struct _CK_ATTRIBUTE *templ, unsigned long count, CK_OBJECT_HANDLE *object); CK_RV C_CreateObject (CK_SESSION_HANDLE session, struct _CK_ATTRIBUTE *templ, unsigned long count, CK_OBJECT_HANDLE *object)


                                                          ;
typedef CK_RV (*CK_C_CopyObject) (CK_SESSION_HANDLE session, CK_OBJECT_HANDLE object, struct _CK_ATTRIBUTE *templ, unsigned long count, CK_OBJECT_HANDLE *new_object); CK_RV C_CopyObject (CK_SESSION_HANDLE session, CK_OBJECT_HANDLE object, struct _CK_ATTRIBUTE *templ, unsigned long count, CK_OBJECT_HANDLE *new_object)


                                         ;
typedef CK_RV (*CK_C_DestroyObject) (CK_SESSION_HANDLE session, CK_OBJECT_HANDLE object); CK_RV C_DestroyObject (CK_SESSION_HANDLE session, CK_OBJECT_HANDLE object)

                                    ;
typedef CK_RV (*CK_C_GetObjectSize) (CK_SESSION_HANDLE session, CK_OBJECT_HANDLE object, unsigned long *size); CK_RV C_GetObjectSize (CK_SESSION_HANDLE session, CK_OBJECT_HANDLE object, unsigned long *size)


                              ;
typedef CK_RV (*CK_C_GetAttributeValue) (CK_SESSION_HANDLE session, CK_OBJECT_HANDLE object, struct _CK_ATTRIBUTE *templ, unsigned long count); CK_RV C_GetAttributeValue (CK_SESSION_HANDLE session, CK_OBJECT_HANDLE object, struct _CK_ATTRIBUTE *templ, unsigned long count)



                              ;
typedef CK_RV (*CK_C_SetAttributeValue) (CK_SESSION_HANDLE session, CK_OBJECT_HANDLE object, struct _CK_ATTRIBUTE *templ, unsigned long count); CK_RV C_SetAttributeValue (CK_SESSION_HANDLE session, CK_OBJECT_HANDLE object, struct _CK_ATTRIBUTE *templ, unsigned long count)



                              ;
typedef CK_RV (*CK_C_FindObjectsInit) (CK_SESSION_HANDLE session, struct _CK_ATTRIBUTE *templ, unsigned long count); CK_RV C_FindObjectsInit (CK_SESSION_HANDLE session, struct _CK_ATTRIBUTE *templ, unsigned long count)


                              ;
typedef CK_RV (*CK_C_FindObjects) (CK_SESSION_HANDLE session, CK_OBJECT_HANDLE *object, unsigned long max_object_count, unsigned long *object_count); CK_RV C_FindObjects (CK_SESSION_HANDLE session, CK_OBJECT_HANDLE *object, unsigned long max_object_count, unsigned long *object_count)



                                      ;
typedef CK_RV (*CK_C_FindObjectsFinal) (CK_SESSION_HANDLE session); CK_RV C_FindObjectsFinal (CK_SESSION_HANDLE session)
                                      ;

typedef CK_RV (*CK_C_EncryptInit) (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, CK_OBJECT_HANDLE key); CK_RV C_EncryptInit (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, CK_OBJECT_HANDLE key)


                                 ;
typedef CK_RV (*CK_C_Encrypt) (CK_SESSION_HANDLE session, unsigned char *data, unsigned long data_len, unsigned char *encrypted_data, unsigned long *encrypted_data_len); CK_RV C_Encrypt (CK_SESSION_HANDLE session, unsigned char *data, unsigned long data_len, unsigned char *encrypted_data, unsigned long *encrypted_data_len)



                                            ;
typedef CK_RV (*CK_C_EncryptUpdate) (CK_SESSION_HANDLE session, unsigned char *part, unsigned long part_len, unsigned char *encrypted_part, unsigned long *encrypted_part_len); CK_RV C_EncryptUpdate (CK_SESSION_HANDLE session, unsigned char *part, unsigned long part_len, unsigned char *encrypted_part, unsigned long *encrypted_part_len)



                                            ;
typedef CK_RV (*CK_C_EncryptFinal) (CK_SESSION_HANDLE session, unsigned char *last_encrypted_part, unsigned long *last_encrypted_part_len); CK_RV C_EncryptFinal (CK_SESSION_HANDLE session, unsigned char *last_encrypted_part, unsigned long *last_encrypted_part_len)


                                                 ;

typedef CK_RV (*CK_C_DecryptInit) (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, CK_OBJECT_HANDLE key); CK_RV C_DecryptInit (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, CK_OBJECT_HANDLE key)


                                 ;
typedef CK_RV (*CK_C_Decrypt) (CK_SESSION_HANDLE session, unsigned char *encrypted_data, unsigned long encrypted_data_len, unsigned char *data, unsigned long *data_len); CK_RV C_Decrypt (CK_SESSION_HANDLE session, unsigned char *encrypted_data, unsigned long encrypted_data_len, unsigned char *data, unsigned long *data_len)



                                                       ;
typedef CK_RV (*CK_C_DecryptUpdate) (CK_SESSION_HANDLE session, unsigned char *encrypted_part, unsigned long encrypted_part_len, unsigned char *part, unsigned long *part_len); CK_RV C_DecryptUpdate (CK_SESSION_HANDLE session, unsigned char *encrypted_part, unsigned long encrypted_part_len, unsigned char *part, unsigned long *part_len)



                                                       ;
typedef CK_RV (*CK_C_DecryptFinal) (CK_SESSION_HANDLE session, unsigned char *last_part, unsigned long *last_part_len); CK_RV C_DecryptFinal (CK_SESSION_HANDLE session, unsigned char *last_part, unsigned long *last_part_len)


                                       ;

typedef CK_RV (*CK_C_DigestInit) (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism); CK_RV C_DigestInit (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism)

                                         ;
typedef CK_RV (*CK_C_Digest) (CK_SESSION_HANDLE session, unsigned char *data, unsigned long data_len, unsigned char *digest, unsigned long *digest_len); CK_RV C_Digest (CK_SESSION_HANDLE session, unsigned char *data, unsigned long data_len, unsigned char *digest, unsigned long *digest_len)



                                    ;
typedef CK_RV (*CK_C_DigestUpdate) (CK_SESSION_HANDLE session, unsigned char *part, unsigned long part_len); CK_RV C_DigestUpdate (CK_SESSION_HANDLE session, unsigned char *part, unsigned long part_len)

                                                      ;
typedef CK_RV (*CK_C_DigestKey) (CK_SESSION_HANDLE session, CK_OBJECT_HANDLE key); CK_RV C_DigestKey (CK_SESSION_HANDLE session, CK_OBJECT_HANDLE key)
                                                              ;
typedef CK_RV (*CK_C_DigestFinal) (CK_SESSION_HANDLE session, unsigned char *digest, unsigned long *digest_len); CK_RV C_DigestFinal (CK_SESSION_HANDLE session, unsigned char *digest, unsigned long *digest_len)


                                    ;

typedef CK_RV (*CK_C_SignInit) (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, CK_OBJECT_HANDLE key); CK_RV C_SignInit (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, CK_OBJECT_HANDLE key)


                                 ;
typedef CK_RV (*CK_C_Sign) (CK_SESSION_HANDLE session, unsigned char *data, unsigned long data_len, unsigned char *signature, unsigned long *signature_len); CK_RV C_Sign (CK_SESSION_HANDLE session, unsigned char *data, unsigned long data_len, unsigned char *signature, unsigned long *signature_len)



                                       ;
typedef CK_RV (*CK_C_SignUpdate) (CK_SESSION_HANDLE session, unsigned char *part, unsigned long part_len); CK_RV C_SignUpdate (CK_SESSION_HANDLE session, unsigned char *part, unsigned long part_len)

                                                      ;
typedef CK_RV (*CK_C_SignFinal) (CK_SESSION_HANDLE session, unsigned char *signature, unsigned long *signature_len); CK_RV C_SignFinal (CK_SESSION_HANDLE session, unsigned char *signature, unsigned long *signature_len)


                                       ;
typedef CK_RV (*CK_C_SignRecoverInit) (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, CK_OBJECT_HANDLE key); CK_RV C_SignRecoverInit (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, CK_OBJECT_HANDLE key)


                                 ;
typedef CK_RV (*CK_C_SignRecover) (CK_SESSION_HANDLE session, unsigned char *data, unsigned long data_len, unsigned char *signature, unsigned long *signature_len); CK_RV C_SignRecover (CK_SESSION_HANDLE session, unsigned char *data, unsigned long data_len, unsigned char *signature, unsigned long *signature_len)



                                       ;

typedef CK_RV (*CK_C_VerifyInit) (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, CK_OBJECT_HANDLE key); CK_RV C_VerifyInit (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, CK_OBJECT_HANDLE key)


                                 ;
typedef CK_RV (*CK_C_Verify) (CK_SESSION_HANDLE session, unsigned char *data, unsigned long data_len, unsigned char *signature, unsigned long signature_len); CK_RV C_Verify (CK_SESSION_HANDLE session, unsigned char *data, unsigned long data_len, unsigned char *signature, unsigned long signature_len)



                                      ;
typedef CK_RV (*CK_C_VerifyUpdate) (CK_SESSION_HANDLE session, unsigned char *part, unsigned long part_len); CK_RV C_VerifyUpdate (CK_SESSION_HANDLE session, unsigned char *part, unsigned long part_len)

                                                      ;
typedef CK_RV (*CK_C_VerifyFinal) (CK_SESSION_HANDLE session, unsigned char *signature, unsigned long signature_len); CK_RV C_VerifyFinal (CK_SESSION_HANDLE session, unsigned char *signature, unsigned long signature_len)


                                      ;
typedef CK_RV (*CK_C_VerifyRecoverInit) (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, CK_OBJECT_HANDLE key); CK_RV C_VerifyRecoverInit (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, CK_OBJECT_HANDLE key)


                                 ;
typedef CK_RV (*CK_C_VerifyRecover) (CK_SESSION_HANDLE session, unsigned char *signature, unsigned long signature_len, unsigned char *data, unsigned long *data_len); CK_RV C_VerifyRecover (CK_SESSION_HANDLE session, unsigned char *signature, unsigned long signature_len, unsigned char *data, unsigned long *data_len)




                                  ;

typedef CK_RV (*CK_C_DigestEncryptUpdate) (CK_SESSION_HANDLE session, unsigned char *part, unsigned long part_len, unsigned char *encrypted_part, unsigned long *encrypted_part_len); CK_RV C_DigestEncryptUpdate (CK_SESSION_HANDLE session, unsigned char *part, unsigned long part_len, unsigned char *encrypted_part, unsigned long *encrypted_part_len)



                                            ;
typedef CK_RV (*CK_C_DecryptDigestUpdate) (CK_SESSION_HANDLE session, unsigned char *encrypted_part, unsigned long encrypted_part_len, unsigned char *part, unsigned long *part_len); CK_RV C_DecryptDigestUpdate (CK_SESSION_HANDLE session, unsigned char *encrypted_part, unsigned long encrypted_part_len, unsigned char *part, unsigned long *part_len)




                                  ;
typedef CK_RV (*CK_C_SignEncryptUpdate) (CK_SESSION_HANDLE session, unsigned char *part, unsigned long part_len, unsigned char *encrypted_part, unsigned long *encrypted_part_len); CK_RV C_SignEncryptUpdate (CK_SESSION_HANDLE session, unsigned char *part, unsigned long part_len, unsigned char *encrypted_part, unsigned long *encrypted_part_len)



                                            ;
typedef CK_RV (*CK_C_DecryptVerifyUpdate) (CK_SESSION_HANDLE session, unsigned char *encrypted_part, unsigned long encrypted_part_len, unsigned char *part, unsigned long *part_len); CK_RV C_DecryptVerifyUpdate (CK_SESSION_HANDLE session, unsigned char *encrypted_part, unsigned long encrypted_part_len, unsigned char *part, unsigned long *part_len)




                                  ;

typedef CK_RV (*CK_C_GenerateKey) (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, struct _CK_ATTRIBUTE *templ, unsigned long count, CK_OBJECT_HANDLE *key); CK_RV C_GenerateKey (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, struct _CK_ATTRIBUTE *templ, unsigned long count, CK_OBJECT_HANDLE *key)




                                  ;
typedef CK_RV (*CK_C_GenerateKeyPair) (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, struct _CK_ATTRIBUTE *public_key_template, unsigned long public_key_attribute_count, struct _CK_ATTRIBUTE *private_key_template, unsigned long private_key_attribute_count, CK_OBJECT_HANDLE *public_key, CK_OBJECT_HANDLE *private_key); CK_RV C_GenerateKeyPair (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, struct _CK_ATTRIBUTE *public_key_template, unsigned long public_key_attribute_count, struct _CK_ATTRIBUTE *private_key_template, unsigned long private_key_attribute_count, CK_OBJECT_HANDLE *public_key, CK_OBJECT_HANDLE *private_key)







                                          ;
typedef CK_RV (*CK_C_WrapKey) (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, CK_OBJECT_HANDLE wrapping_key, CK_OBJECT_HANDLE key, unsigned char *wrapped_key, unsigned long *wrapped_key_len); CK_RV C_WrapKey (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, CK_OBJECT_HANDLE wrapping_key, CK_OBJECT_HANDLE key, unsigned char *wrapped_key, unsigned long *wrapped_key_len)





                                         ;
typedef CK_RV (*CK_C_UnwrapKey) (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, CK_OBJECT_HANDLE unwrapping_key, unsigned char *wrapped_key, unsigned long wrapped_key_len, struct _CK_ATTRIBUTE *templ, unsigned long attribute_count, CK_OBJECT_HANDLE *key); CK_RV C_UnwrapKey (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, CK_OBJECT_HANDLE unwrapping_key, unsigned char *wrapped_key, unsigned long wrapped_key_len, struct _CK_ATTRIBUTE *templ, unsigned long attribute_count, CK_OBJECT_HANDLE *key)







                                  ;
typedef CK_RV (*CK_C_DeriveKey) (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, CK_OBJECT_HANDLE base_key, struct _CK_ATTRIBUTE *templ, unsigned long attribute_count, CK_OBJECT_HANDLE *key); CK_RV C_DeriveKey (CK_SESSION_HANDLE session, struct _CK_MECHANISM *mechanism, CK_OBJECT_HANDLE base_key, struct _CK_ATTRIBUTE *templ, unsigned long attribute_count, CK_OBJECT_HANDLE *key)





                                  ;

typedef CK_RV (*CK_C_SeedRandom) (CK_SESSION_HANDLE session, unsigned char *seed, unsigned long seed_len); CK_RV C_SeedRandom (CK_SESSION_HANDLE session, unsigned char *seed, unsigned long seed_len)

                                 ;
typedef CK_RV (*CK_C_GenerateRandom) (CK_SESSION_HANDLE session, unsigned char *random_data, unsigned long random_len); CK_RV C_GenerateRandom (CK_SESSION_HANDLE session, unsigned char *random_data, unsigned long random_len)


                                   ;

typedef CK_RV (*CK_C_GetFunctionStatus) (CK_SESSION_HANDLE session); CK_RV C_GetFunctionStatus (CK_SESSION_HANDLE session);
typedef CK_RV (*CK_C_CancelFunction) (CK_SESSION_HANDLE session); CK_RV C_CancelFunction (CK_SESSION_HANDLE session);


struct _CK_FUNCTION_LIST
{
  struct _CK_VERSION version;
  CK_C_Initialize C_Initialize;
  CK_C_Finalize C_Finalize;
  CK_C_GetInfo C_GetInfo;
  CK_C_GetFunctionList C_GetFunctionList;
  CK_C_GetSlotList C_GetSlotList;
  CK_C_GetSlotInfo C_GetSlotInfo;
  CK_C_GetTokenInfo C_GetTokenInfo;
  CK_C_GetMechanismList C_GetMechanismList;
  CK_C_GetMechanismInfo C_GetMechanismInfo;
  CK_C_InitToken C_InitToken;
  CK_C_InitPIN C_InitPIN;
  CK_C_SetPIN C_SetPIN;
  CK_C_OpenSession C_OpenSession;
  CK_C_CloseSession C_CloseSession;
  CK_C_CloseAllSessions C_CloseAllSessions;
  CK_C_GetSessionInfo C_GetSessionInfo;
  CK_C_GetOperationState C_GetOperationState;
  CK_C_SetOperationState C_SetOperationState;
  CK_C_Login C_Login;
  CK_C_Logout C_Logout;
  CK_C_CreateObject C_CreateObject;
  CK_C_CopyObject C_CopyObject;
  CK_C_DestroyObject C_DestroyObject;
  CK_C_GetObjectSize C_GetObjectSize;
  CK_C_GetAttributeValue C_GetAttributeValue;
  CK_C_SetAttributeValue C_SetAttributeValue;
  CK_C_FindObjectsInit C_FindObjectsInit;
  CK_C_FindObjects C_FindObjects;
  CK_C_FindObjectsFinal C_FindObjectsFinal;
  CK_C_EncryptInit C_EncryptInit;
  CK_C_Encrypt C_Encrypt;
  CK_C_EncryptUpdate C_EncryptUpdate;
  CK_C_EncryptFinal C_EncryptFinal;
  CK_C_DecryptInit C_DecryptInit;
  CK_C_Decrypt C_Decrypt;
  CK_C_DecryptUpdate C_DecryptUpdate;
  CK_C_DecryptFinal C_DecryptFinal;
  CK_C_DigestInit C_DigestInit;
  CK_C_Digest C_Digest;
  CK_C_DigestUpdate C_DigestUpdate;
  CK_C_DigestKey C_DigestKey;
  CK_C_DigestFinal C_DigestFinal;
  CK_C_SignInit C_SignInit;
  CK_C_Sign C_Sign;
  CK_C_SignUpdate C_SignUpdate;
  CK_C_SignFinal C_SignFinal;
  CK_C_SignRecoverInit C_SignRecoverInit;
  CK_C_SignRecover C_SignRecover;
  CK_C_VerifyInit C_VerifyInit;
  CK_C_Verify C_Verify;
  CK_C_VerifyUpdate C_VerifyUpdate;
  CK_C_VerifyFinal C_VerifyFinal;
  CK_C_VerifyRecoverInit C_VerifyRecoverInit;
  CK_C_VerifyRecover C_VerifyRecover;
  CK_C_DigestEncryptUpdate C_DigestEncryptUpdate;
  CK_C_DecryptDigestUpdate C_DecryptDigestUpdate;
  CK_C_SignEncryptUpdate C_SignEncryptUpdate;
  CK_C_DecryptVerifyUpdate C_DecryptVerifyUpdate;
  CK_C_GenerateKey C_GenerateKey;
  CK_C_GenerateKeyPair C_GenerateKeyPair;
  CK_C_WrapKey C_WrapKey;
  CK_C_UnwrapKey C_UnwrapKey;
  CK_C_DeriveKey C_DeriveKey;
  CK_C_SeedRandom C_SeedRandom;
  CK_C_GenerateRandom C_GenerateRandom;
  CK_C_GetFunctionStatus C_GetFunctionStatus;
  CK_C_CancelFunction C_CancelFunction;
  CK_C_WaitForSlotEvent C_WaitForSlotEvent;
};


typedef CK_RV (*CK_CREATEMUTEX) (void **mutex);
typedef CK_RV (*CK_DESTROYMUTEX) (void *mutex);
typedef CK_RV (*CK_LOCKMUTEX) (void *mutex);
typedef CK_RV (*CK_UNLOCKMUTEX) (void *mutex);


struct _CK_C_INITIALIZE_ARGS
{
  CK_CREATEMUTEX CreateMutex;
  CK_DESTROYMUTEX DestroyMutex;
  CK_LOCKMUTEX LockMutex;
  CK_UNLOCKMUTEX UnlockMutex;
  CK_FLAGS flags;
  void *pReserved;
};

typedef unsigned char CK_BYTE;
typedef unsigned char CK_CHAR;
typedef unsigned char CK_UTF8CHAR;
typedef unsigned char CK_BBOOL;
typedef unsigned long int CK_ULONG;
typedef long int CK_LONG;
typedef CK_BYTE *CK_BYTE_PTR;
typedef CK_CHAR *CK_CHAR_PTR;
typedef CK_UTF8CHAR *CK_UTF8CHAR_PTR;
typedef CK_ULONG *CK_ULONG_PTR;
typedef void *CK_VOID_PTR;
typedef void **CK_VOID_PTR_PTR;
typedef struct _CK_VERSION CK_VERSION;
typedef struct _CK_VERSION *CK_VERSION_PTR;

typedef struct _CK_INFO CK_INFO;
typedef struct _CK_INFO *CK_INFO_PTR;

typedef CK_SLOT_ID *CK_SLOT_ID_PTR;

typedef struct _CK_SLOT_INFO CK_SLOT_INFO;
typedef struct _CK_SLOT_INFO *CK_SLOT_INFO_PTR;

typedef struct _CK_TOKEN_INFO CK_TOKEN_INFO;
typedef struct _CK_TOKEN_INFO *CK_TOKEN_INFO_PTR;

typedef CK_SESSION_HANDLE *CK_SESSION_HANDLE_PTR;

typedef struct _CK_SESSION_INFO CK_SESSION_INFO;
typedef struct _CK_SESSION_INFO *CK_SESSION_INFO_PTR;

typedef CK_OBJECT_HANDLE *CK_OBJECT_HANDLE_PTR;

typedef CK_OBJECT_CLASS *CK_OBJECT_CLASS_PTR;

typedef struct _CK_ATTRIBUTE CK_ATTRIBUTE;
typedef struct _CK_ATTRIBUTE *CK_ATTRIBUTE_PTR;

typedef struct _CK_DATE CK_DATE;
typedef struct _CK_DATE *CK_DATE_PTR;

typedef CK_MECHANISM_TYPE *CK_MECHANISM_TYPE_PTR;

typedef struct _CK_MECHANISM CK_MECHANISM;
typedef struct _CK_MECHANISM *CK_MECHANISM_PTR;

typedef struct _CK_MECHANISM_INFO CK_MECHANISM_INFO;
typedef struct _CK_MECHANISM_INFO *CK_MECHANISM_INFO_PTR;

typedef struct _CK_FUNCTION_LIST CK_FUNCTION_LIST;
typedef struct _CK_FUNCTION_LIST *CK_FUNCTION_LIST_PTR;
typedef struct _CK_FUNCTION_LIST **CK_FUNCTION_LIST_PTR_PTR;

typedef struct _CK_C_INITIALIZE_ARGS CK_C_INITIALIZE_ARGS;
typedef struct _CK_C_INITIALIZE_ARGS *CK_C_INITIALIZE_ARGS_PTR;

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
int pkcs11_init(int);
void pkcs11_terminate(void);
int pkcs11_add_provider(char *, char *, struct sshkey ***, char ***);
int pkcs11_del_provider(char *);
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
void *xmalloc(size_t);
void *xcalloc(size_t, size_t);
void *xreallocarray(void *, size_t, size_t);
void *xrecallocarray(void *, size_t, size_t, size_t);
char *xstrdup(const char *);
int xasprintf(char **, const char *, ...)
    __attribute__((__format__ (printf, 2, 3))) __attribute__((__nonnull__ (2)));
int xvasprintf(char **, const char *, va_list)
    __attribute__((__nonnull__ (2)));

struct pkcs11_slotinfo {
 CK_TOKEN_INFO token;
 CK_SESSION_HANDLE session;
 int logged_in;
};

struct pkcs11_provider {
 char *name;
 void *handle;
 CK_FUNCTION_LIST *function_list;
 CK_INFO info;
 CK_ULONG nslots;
 CK_SLOT_ID *slotlist;
 struct pkcs11_slotinfo *slotinfo;
 int valid;
 int refcount;
 struct { struct pkcs11_provider *tqe_next; struct pkcs11_provider **tqe_prev; } next;
};

struct { struct pkcs11_provider *tqh_first; struct pkcs11_provider **tqh_last; } pkcs11_providers;

struct pkcs11_key {
 struct pkcs11_provider *provider;
 CK_ULONG slotidx;
 char *keyid;
 int keyid_len;
};

int pkcs11_interactive = 0;


static void
ossl_error(const char *msg)
{
 unsigned long e;

 sshlog("ssh-pkcs11.c", __func__, 88, 1, SYSLOG_LEVEL_ERROR, 
((void *)0)
, "%s", msg);
 while ((e = ERR_get_error()) != 0)
  sshlog("ssh-pkcs11.c", __func__, 90, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "libcrypto error: %s", ERR_error_string(e, 
 ((void *)0)
 ));
}


int
pkcs11_init(int interactive)
{
 pkcs11_interactive = interactive;
 do { (&pkcs11_providers)->tqh_first = 
((void *)0)
; (&pkcs11_providers)->tqh_last = &(&pkcs11_providers)->tqh_first; } while (0);
 return (0);
}







static void
pkcs11_provider_finalize(struct pkcs11_provider *p)
{
 CK_RV rv;
 CK_ULONG i;

 sshlog("ssh-pkcs11.c", __func__, 114, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "provider \"%s\" refcount %d valid %d", p->name, p->refcount, p->valid)
                                    ;
 if (!p->valid)
  return;
 for (i = 0; i < p->nslots; i++) {
  if (p->slotinfo[i].session &&
      (rv = p->function_list->C_CloseSession(
      p->slotinfo[i].session)) != (0))
   sshlog("ssh-pkcs11.c", __func__, 122, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "C_CloseSession failed: %lu", rv);
 }
 if ((rv = p->function_list->C_Finalize(
                                       ((void *)0)
                                           )) != (0))
  sshlog("ssh-pkcs11.c", __func__, 125, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_Finalize failed: %lu", rv);
 p->valid = 0;
 p->function_list = 
                   ((void *)0)
                       ;
 dlclose(p->handle);
}





static void
pkcs11_provider_unref(struct pkcs11_provider *p)
{
 sshlog("ssh-pkcs11.c", __func__, 138, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "provider \"%s\" refcount %d", p->name, p->refcount);
 if (--p->refcount <= 0) {
  if (p->valid)
   sshlog("ssh-pkcs11.c", __func__, 141, 1, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "provider \"%s\" still valid", p->name);
  free(p->name);
  free(p->slotlist);
  free(p->slotinfo);
  free(p);
 }
}


void
pkcs11_terminate(void)
{
 struct pkcs11_provider *p;

 while ((p = ((&pkcs11_providers)->tqh_first)) != 
                                               ((void *)0)
                                                   ) {
  do { if (((p)->next.tqe_next) != 
 ((void *)0)
 ) (p)->next.tqe_next->next.tqe_prev = (p)->next.tqe_prev; else (&pkcs11_providers)->tqh_last = (p)->next.tqe_prev; *(p)->next.tqe_prev = (p)->next.tqe_next; ; ; } while (0);
  pkcs11_provider_finalize(p);
  pkcs11_provider_unref(p);
 }
}


static struct pkcs11_provider *
pkcs11_provider_lookup(char *provider_id)
{
 struct pkcs11_provider *p;

 for((p) = ((&pkcs11_providers)->tqh_first); (p) != 
((void *)0)
; (p) = ((p)->next.tqe_next)) {
  sshlog("ssh-pkcs11.c", __func__, 169, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "check provider \"%s\"", p->name);
  if (!strcmp(provider_id, p->name))
   return (p);
 }
 return (
        ((void *)0)
            );
}


int
pkcs11_del_provider(char *provider_id)
{
 struct pkcs11_provider *p;

 if ((p = pkcs11_provider_lookup(provider_id)) != 
                                                 ((void *)0)
                                                     ) {
  do { if (((p)->next.tqe_next) != 
 ((void *)0)
 ) (p)->next.tqe_next->next.tqe_prev = (p)->next.tqe_prev; else (&pkcs11_providers)->tqh_last = (p)->next.tqe_prev; *(p)->next.tqe_prev = (p)->next.tqe_next; ; ; } while (0);
  pkcs11_provider_finalize(p);
  pkcs11_provider_unref(p);
  return (0);
 }
 return (-1);
}

static RSA_METHOD *rsa_method;
static int rsa_idx = 0;

static EC_KEY_METHOD *ec_key_method;
static int ec_key_idx = 0;



static void
pkcs11_k11_free(void *parent, void *ptr, CRYPTO_EX_DATA *ad, int idx,
    long argl, void *argp)
{
 struct pkcs11_key *k11 = ptr;

 sshlog("ssh-pkcs11.c", __func__, 205, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "parent %p ptr %p idx %d", parent, ptr, idx);
 if (k11 == 
           ((void *)0)
               )
  return;
 if (k11->provider)
  pkcs11_provider_unref(k11->provider);
 free(k11->keyid);
 free(k11);
}


static int
pkcs11_find(struct pkcs11_provider *p, CK_ULONG slotidx, CK_ATTRIBUTE *attr,
    CK_ULONG nattr, CK_OBJECT_HANDLE *obj)
{
 CK_FUNCTION_LIST *f;
 CK_SESSION_HANDLE session;
 CK_ULONG nfound = 0;
 CK_RV rv;
 int ret = -1;

 f = p->function_list;
 session = p->slotinfo[slotidx].session;
 if ((rv = f->C_FindObjectsInit(session, attr, nattr)) != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 228, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_FindObjectsInit failed (nattr %lu): %lu", nattr, rv);
  return (-1);
 }
 if ((rv = f->C_FindObjects(session, obj, 1, &nfound)) != (0) ||
     nfound != 1) {
  sshlog("ssh-pkcs11.c", __func__, 233, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "C_FindObjects failed (nfound %lu nattr %lu): %lu", nfound, nattr, rv)
                        ;
 } else
  ret = 0;
 if ((rv = f->C_FindObjectsFinal(session)) != (0))
  sshlog("ssh-pkcs11.c", __func__, 238, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_FindObjectsFinal failed: %lu", rv);
 return (ret);
}

static int
pkcs11_login_slot(struct pkcs11_provider *provider, struct pkcs11_slotinfo *si,
    CK_USER_TYPE type)
{
 char *pin = 
              ((void *)0)
                  , prompt[1024];
 CK_RV rv;

 if (provider == 
                ((void *)0) 
                     || si == 
                              ((void *)0) 
                                   || !provider->valid) {
  sshlog("ssh-pkcs11.c", __func__, 250, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "no pkcs11 (valid) provider found");
  return (-1);
 }

 if (!pkcs11_interactive) {
  sshlog("ssh-pkcs11.c", __func__, 255, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "need pin entry%s", (si->token.flags & (1 << 8)) ? " on reader keypad" : "")

                               ;
  return (-1);
 }
 if (si->token.flags & (1 << 8))
  sshlog("ssh-pkcs11.c", __func__, 261, 0, SYSLOG_LEVEL_VERBOSE, 
 ((void *)0)
 , "Deferring PIN entry to reader keypad.");
 else {
  snprintf(prompt, sizeof(prompt), "Enter PIN for '%s': ",
      si->token.label);
  if ((pin = read_passphrase(prompt, 0x0004)) == 
                                                      ((void *)0)
                                                          ) {
   sshlog("ssh-pkcs11.c", __func__, 266, 1, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "no pin specified");
   return (-1);
  }
 }
 rv = provider->function_list->C_Login(si->session, type, (u_char *)pin,
     (pin != 
            ((void *)0)
                ) ? strlen(pin) : 0);
 if (pin != 
           ((void *)0)
               )
  freezero(pin, strlen(pin));

 switch (rv) {
 case (0):
 case (0x100):

  break;
 case (0xa2):
  sshlog("ssh-pkcs11.c", __func__, 281, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "PKCS#11 login failed: PIN length out of range");
  return -1;
 case (0xa0):
  sshlog("ssh-pkcs11.c", __func__, 284, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "PKCS#11 login failed: PIN incorrect");
  return -1;
 case (0xa4):
  sshlog("ssh-pkcs11.c", __func__, 287, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "PKCS#11 login failed: PIN locked");
  return -1;
 default:
  sshlog("ssh-pkcs11.c", __func__, 290, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "PKCS#11 login failed: error %lu", rv);
  return -1;
 }
 si->logged_in = 1;
 return (0);
}

static int
pkcs11_login(struct pkcs11_key *k11, CK_USER_TYPE type)
{
 if (k11 == 
           ((void *)0) 
                || k11->provider == 
                                    ((void *)0) 
                                         || !k11->provider->valid) {
  sshlog("ssh-pkcs11.c", __func__, 301, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "no pkcs11 (valid) provider found");
  return (-1);
 }

 return pkcs11_login_slot(k11->provider,
     &k11->provider->slotinfo[k11->slotidx], type);
}


static int
pkcs11_check_obj_bool_attrib(struct pkcs11_key *k11, CK_OBJECT_HANDLE obj,
    CK_ATTRIBUTE_TYPE type, int *val)
{
 struct pkcs11_slotinfo *si;
 CK_FUNCTION_LIST *f;
 CK_BBOOL flag = 0;
 CK_ATTRIBUTE attr;
 CK_RV rv;

 *val = 0;

 if (!k11->provider || !k11->provider->valid) {
  sshlog("ssh-pkcs11.c", __func__, 323, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "no pkcs11 (valid) provider found");
  return (-1);
 }

 f = k11->provider->function_list;
 si = &k11->provider->slotinfo[k11->slotidx];

 attr.type = type;
 attr.pValue = &flag;
 attr.ulValueLen = sizeof(flag);

 rv = f->C_GetAttributeValue(si->session, obj, &attr, 1);
 if (rv != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 336, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_GetAttributeValue failed: %lu", rv);
  return (-1);
 }
 *val = flag != 0;
 sshlog("ssh-pkcs11.c", __func__, 340, 1, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "provider \"%s\" slot %lu object %lu: attrib %lu = %d", k11->provider->name, k11->slotidx, obj, type, *val)
                                                        ;
 return (0);
}

static int
pkcs11_get_key(struct pkcs11_key *k11, CK_MECHANISM_TYPE mech_type)
{
 struct pkcs11_slotinfo *si;
 CK_FUNCTION_LIST *f;
 CK_OBJECT_HANDLE obj;
 CK_RV rv;
 CK_OBJECT_CLASS private_key_class;
 CK_BBOOL true_val;
 CK_MECHANISM mech;
 CK_ATTRIBUTE key_filter[3];
 int always_auth = 0;
 int did_login = 0;

 if (!k11->provider || !k11->provider->valid) {
  sshlog("ssh-pkcs11.c", __func__, 360, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "no pkcs11 (valid) provider found");
  return (-1);
 }

 f = k11->provider->function_list;
 si = &k11->provider->slotinfo[k11->slotidx];

 if ((si->token.flags & (1 << 2)) && !si->logged_in) {
  if (pkcs11_login(k11, (1)) < 0) {
   sshlog("ssh-pkcs11.c", __func__, 369, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "login failed");
   return (-1);
  }
  did_login = 1;
 }

 memset(&key_filter, 0, sizeof(key_filter));
 private_key_class = (3);
 key_filter[0].type = (0);
 key_filter[0].pValue = &private_key_class;
 key_filter[0].ulValueLen = sizeof(private_key_class);

 key_filter[1].type = (0x102);
 key_filter[1].pValue = k11->keyid;
 key_filter[1].ulValueLen = k11->keyid_len;

 true_val = 1;
 key_filter[2].type = (0x108);
 key_filter[2].pValue = &true_val;
 key_filter[2].ulValueLen = sizeof(true_val);


 if (pkcs11_find(k11->provider, k11->slotidx, key_filter, 3, &obj) < 0 &&
     pkcs11_find(k11->provider, k11->slotidx, key_filter, 2, &obj) < 0) {
  sshlog("ssh-pkcs11.c", __func__, 393, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "cannot find private key");
  return (-1);
 }

 memset(&mech, 0, sizeof(mech));
 mech.mechanism = mech_type;
 mech.pParameter = 
                  ((void *)0)
                          ;
 mech.ulParameterLen = 0;

 if ((rv = f->C_SignInit(si->session, &mech, obj)) != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 403, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_SignInit failed: %lu", rv);
  return (-1);
 }

 pkcs11_check_obj_bool_attrib(k11, obj, (0x202),
     &always_auth);
 if (always_auth && !did_login) {
  sshlog("ssh-pkcs11.c", __func__, 410, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "always-auth key");
  if (pkcs11_login(k11, (2)) < 0) {
   sshlog("ssh-pkcs11.c", __func__, 412, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "login failed for always-auth key");
   return (-1);
  }
 }

 return (0);
}


static int
pkcs11_rsa_private_encrypt(int flen, const u_char *from, u_char *to, RSA *rsa,
    int padding)
{
 struct pkcs11_key *k11;
 struct pkcs11_slotinfo *si;
 CK_FUNCTION_LIST *f;
 CK_ULONG tlen = 0;
 CK_RV rv;
 int rval = -1;

 if ((k11 = RSA_get_ex_data(rsa, rsa_idx)) == 
                                             ((void *)0)
                                                 ) {
  sshlog("ssh-pkcs11.c", __func__, 433, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "RSA_get_ex_data failed");
  return (-1);
 }

 if (pkcs11_get_key(k11, (1)) == -1) {
  sshlog("ssh-pkcs11.c", __func__, 438, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "pkcs11_get_key failed");
  return (-1);
 }

 f = k11->provider->function_list;
 si = &k11->provider->slotinfo[k11->slotidx];
 tlen = RSA_size(rsa);


 rv = f->C_Sign(si->session, (CK_BYTE *)from, flen, to, &tlen);
 if (rv == (0))
  rval = tlen;
 else
  sshlog("ssh-pkcs11.c", __func__, 451, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_Sign failed: %lu", rv);

 return (rval);
}

static int
pkcs11_rsa_private_decrypt(int flen, const u_char *from, u_char *to, RSA *rsa,
    int padding)
{
 return (-1);
}

static int
pkcs11_rsa_start_wrapper(void)
{
 if (rsa_method != 
                  ((void *)0)
                      )
  return (0);
 rsa_method = RSA_meth_dup(RSA_get_default_method());
 if (rsa_method == 
                  ((void *)0)
                      )
  return (-1);
 rsa_idx = 
          CRYPTO_get_ex_new_index(9, 
          0
          , 
          "ssh-pkcs11-rsa"
          , ((void *)0), ((void *)0), 
          pkcs11_k11_free
          )
                                 
                                ;
 if (rsa_idx == -1)
  return (-1);
 if (!RSA_meth_set1_name(rsa_method, "pkcs11") ||
     !RSA_meth_set_priv_enc(rsa_method, pkcs11_rsa_private_encrypt) ||
     !RSA_meth_set_priv_dec(rsa_method, pkcs11_rsa_private_decrypt)) {
  sshlog("ssh-pkcs11.c", __func__, 478, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "setup pkcs11 method failed");
  return (-1);
 }
 return (0);
}


static int
pkcs11_rsa_wrap(struct pkcs11_provider *provider, CK_ULONG slotidx,
    CK_ATTRIBUTE *keyid_attrib, RSA *rsa)
{
 struct pkcs11_key *k11;

 if (pkcs11_rsa_start_wrapper() == -1)
  return (-1);

 k11 = xcalloc(1, sizeof(*k11));
 k11->provider = provider;
 provider->refcount++;
 k11->slotidx = slotidx;

 k11->keyid_len = keyid_attrib->ulValueLen;
 if (k11->keyid_len > 0) {
  k11->keyid = xmalloc(k11->keyid_len);
  memcpy(k11->keyid, keyid_attrib->pValue, k11->keyid_len);
 }

 RSA_set_method(rsa, rsa_method);
 RSA_set_ex_data(rsa, rsa_idx, k11);
 return (0);
}



static ECDSA_SIG *
ecdsa_do_sign(const unsigned char *dgst, int dgst_len, const BIGNUM *inv,
    const BIGNUM *rp, EC_KEY *ec)
{
 struct pkcs11_key *k11;
 struct pkcs11_slotinfo *si;
 CK_FUNCTION_LIST *f;
 CK_ULONG siglen = 0, bnlen;
 CK_RV rv;
 ECDSA_SIG *ret = 
                  ((void *)0)
                      ;
 u_char *sig;
 BIGNUM *r = 
              ((void *)0)
                  , *s = 
                         ((void *)0)
                             ;

 if ((k11 = EC_KEY_get_ex_data(ec, ec_key_idx)) == 
                                                  ((void *)0)
                                                      ) {
  ossl_error("EC_KEY_get_key_method_data failed for ec");
  return (
         ((void *)0)
             );
 }

 if (pkcs11_get_key(k11, (0x1041)) == -1) {
  sshlog("ssh-pkcs11.c", __func__, 531, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "pkcs11_get_key failed");
  return (
         ((void *)0)
             );
 }

 f = k11->provider->function_list;
 si = &k11->provider->slotinfo[k11->slotidx];

 siglen = ECDSA_size(ec);
 sig = xmalloc(siglen);


 rv = f->C_Sign(si->session, (CK_BYTE *)dgst, dgst_len, sig, &siglen);
 if (rv != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 544, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_Sign failed: %lu", rv);
  goto done;
 }
 if (siglen < 64 || siglen > 132 || siglen % 2) {
  ossl_error("d2i_ECDSA_SIG failed");
  goto done;
 }
 bnlen = siglen/2;
 if ((ret = ECDSA_SIG_new()) == 
                               ((void *)0)
                                   ) {
  sshlog("ssh-pkcs11.c", __func__, 553, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "ECDSA_SIG_new failed");
  goto done;
 }
 if ((r = BN_bin2bn(sig, bnlen, 
                               ((void *)0)
                                   )) == 
                                         ((void *)0) 
                                              ||
     (s = BN_bin2bn(sig+bnlen, bnlen, 
                                     ((void *)0)
                                         )) == 
                                               ((void *)0)
                                                   ) {
  ossl_error("d2i_ECDSA_SIG failed");
  ECDSA_SIG_free(ret);
  ret = 
       ((void *)0)
           ;
  goto done;
 }
 if (!ECDSA_SIG_set0(ret, r, s)) {
  sshlog("ssh-pkcs11.c", __func__, 564, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "ECDSA_SIG_set0 failed");
  ECDSA_SIG_free(ret);
  ret = 
       ((void *)0)
           ;
  goto done;
 }
 r = s = 
        ((void *)0)
            ;

 done:
 BN_free(r);
 BN_free(s);
 free(sig);

 return (ret);
}

static int
pkcs11_ecdsa_start_wrapper(void)
{
 int (*orig_sign)(int, const unsigned char *, int, unsigned char *,
     unsigned int *, const BIGNUM *, const BIGNUM *, EC_KEY *) = 
                                                                ((void *)0)
                                                                    ;

 if (ec_key_method != 
                     ((void *)0)
                         )
  return (0);
 ec_key_idx = 
             CRYPTO_get_ex_new_index(8, 
             0
             , 
             "ssh-pkcs11-ecdsa"
             , ((void *)0), ((void *)0), 
             pkcs11_k11_free
             )
                                 
                                ;
 if (ec_key_idx == -1)
  return (-1);
 ec_key_method = EC_KEY_METHOD_new(EC_KEY_OpenSSL());
 if (ec_key_method == 
                     ((void *)0)
                         )
  return (-1);
 EC_KEY_METHOD_get_sign(ec_key_method, &orig_sign, 
                                                  ((void *)0)
                                                      , 
                                                        ((void *)0)
                                                            );
 EC_KEY_METHOD_set_sign(ec_key_method, orig_sign, 
                                                 ((void *)0)
                                                     , ecdsa_do_sign);
 return (0);
}

static int
pkcs11_ecdsa_wrap(struct pkcs11_provider *provider, CK_ULONG slotidx,
    CK_ATTRIBUTE *keyid_attrib, EC_KEY *ec)
{
 struct pkcs11_key *k11;

 if (pkcs11_ecdsa_start_wrapper() == -1)
  return (-1);

 k11 = xcalloc(1, sizeof(*k11));
 k11->provider = provider;
 provider->refcount++;
 k11->slotidx = slotidx;

 k11->keyid_len = keyid_attrib->ulValueLen;
 if (k11->keyid_len > 0) {
  k11->keyid = xmalloc(k11->keyid_len);
  memcpy(k11->keyid, keyid_attrib->pValue, k11->keyid_len);
 }
 EC_KEY_set_method(ec, ec_key_method);
 EC_KEY_set_ex_data(ec, ec_key_idx, k11);

 return (0);
}



static void
rmspace(u_char *buf, size_t len)
{
 size_t i;

 if (!len)
  return;
 for (i = len - 1; i > 0; i--)
  if (i == len - 1 || buf[i] == ' ')
   buf[i] = '\0';
  else
   break;
}





static int
pkcs11_open_session(struct pkcs11_provider *p, CK_ULONG slotidx, char *pin,
    CK_ULONG user)
{
 struct pkcs11_slotinfo *si;
 CK_FUNCTION_LIST *f;
 CK_RV rv;
 CK_SESSION_HANDLE session;
 int login_required, ret;

 f = p->function_list;
 si = &p->slotinfo[slotidx];

 login_required = si->token.flags & (1 << 2);


 if (login_required && !pkcs11_interactive &&
     (pin == 
            ((void *)0) 
                 || strlen(pin) == 0)) {
  sshlog("ssh-pkcs11.c", __func__, 662, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "pin required");
  return (-4);
 }
 if ((rv = f->C_OpenSession(p->slotlist[slotidx], (1 << 1)|
     (1 << 2), 
                        ((void *)0)
                            , 
                              ((void *)0)
                                  , &session)) != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 667, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_OpenSession failed: %lu", rv);
  return (-1);
 }
 if (login_required && pin != 
                             ((void *)0) 
                                  && strlen(pin) != 0) {
  rv = f->C_Login(session, user, (u_char *)pin, strlen(pin));
  if (rv != (0) && rv != (0x100)) {
   sshlog("ssh-pkcs11.c", __func__, 673, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "C_Login failed: %lu", rv);
   ret = (rv == (0xa4)) ?
       -5 :
       -2;
   if ((rv = f->C_CloseSession(session)) != (0))
    sshlog("ssh-pkcs11.c", __func__, 678, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "C_CloseSession failed: %lu", rv);
   return (ret);
  }
  si->logged_in = 1;
 }
 si->session = session;
 return (0);
}

static int
pkcs11_key_included(struct sshkey ***keysp, int *nkeys, struct sshkey *key)
{
 int i;

 for (i = 0; i < *nkeys; i++)
  if (sshkey_equal(key, (*keysp)[i]))
   return (1);
 return (0);
}


static struct sshkey *
pkcs11_fetch_ecdsa_pubkey(struct pkcs11_provider *p, CK_ULONG slotidx,
    CK_OBJECT_HANDLE *obj)
{
 CK_ATTRIBUTE key_attr[3];
 CK_SESSION_HANDLE session;
 CK_FUNCTION_LIST *f = 
                      ((void *)0)
                          ;
 CK_RV rv;
 ASN1_OCTET_STRING *octet = 
                           ((void *)0)
                               ;
 EC_KEY *ec = 
               ((void *)0)
                   ;
 EC_GROUP *group = 
                   ((void *)0)
                       ;
 struct sshkey *key = 
                      ((void *)0)
                          ;
 const unsigned char *attrp = 
                             ((void *)0)
                                 ;
 int i;
 int nid;

 memset(&key_attr, 0, sizeof(key_attr));
 key_attr[0].type = (0x102);
 key_attr[1].type = (0x181);
 key_attr[2].type = (0x180);

 session = p->slotinfo[slotidx].session;
 f = p->function_list;


 rv = f->C_GetAttributeValue(session, *obj, key_attr, 3);
 if (rv != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 726, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_GetAttributeValue failed: %lu", rv);
  return (
         ((void *)0)
             );
 }






 if (key_attr[1].ulValueLen == 0 ||
     key_attr[2].ulValueLen == 0) {
  sshlog("ssh-pkcs11.c", __func__, 737, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "invalid attribute length");
  return (
         ((void *)0)
             );
 }


 for (i = 0; i < 3; i++)
  if (key_attr[i].ulValueLen > 0)
   key_attr[i].pValue = xcalloc(1, key_attr[i].ulValueLen);


 rv = f->C_GetAttributeValue(session, *obj, key_attr, 3);
 if (rv != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 749, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_GetAttributeValue failed: %lu", rv);
  goto fail;
 }

 ec = EC_KEY_new();
 if (ec == 
          ((void *)0)
              ) {
  sshlog("ssh-pkcs11.c", __func__, 755, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "EC_KEY_new failed");
  goto fail;
 }

 attrp = key_attr[2].pValue;
 group = d2i_ECPKParameters(
                           ((void *)0)
                               , &attrp, key_attr[2].ulValueLen);
 if (group == 
             ((void *)0)
                 ) {
  ossl_error("d2i_ECPKParameters failed");
  goto fail;
 }

 if (EC_KEY_set_group(ec, group) == 0) {
  ossl_error("EC_KEY_set_group failed");
  goto fail;
 }

 if (key_attr[1].ulValueLen <= 2) {
  sshlog("ssh-pkcs11.c", __func__, 772, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "CKA_EC_POINT too small");
  goto fail;
 }

 attrp = key_attr[1].pValue;
 octet = d2i_ASN1_OCTET_STRING(
                              ((void *)0)
                                  , &attrp, key_attr[1].ulValueLen);
 if (octet == 
             ((void *)0)
                 ) {
  ossl_error("d2i_ASN1_OCTET_STRING failed");
  goto fail;
 }
 attrp = octet->data;
 if (o2i_ECPublicKey(&ec, &attrp, octet->length) == 
                                                   ((void *)0)
                                                       ) {
  ossl_error("o2i_ECPublicKey failed");
  goto fail;
 }

 nid = sshkey_ecdsa_key_to_nid(ec);
 if (nid < 0) {
  sshlog("ssh-pkcs11.c", __func__, 790, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "couldn't get curve nid");
  goto fail;
 }

 if (pkcs11_ecdsa_wrap(p, slotidx, &key_attr[0], ec))
  goto fail;

 key = sshkey_new(KEY_UNSPEC);
 if (key == 
           ((void *)0)
               ) {
  sshlog("ssh-pkcs11.c", __func__, 799, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshkey_new failed");
  goto fail;
 }

 key->ecdsa = ec;
 key->ecdsa_nid = nid;
 key->type = KEY_ECDSA;
 key->flags |= 0x0001;
 ec = 
     ((void *)0)
         ;

fail:
 for (i = 0; i < 3; i++)
  free(key_attr[i].pValue);
 if (ec)
  EC_KEY_free(ec);
 if (group)
  EC_GROUP_free(group);
 if (octet)
  ASN1_OCTET_STRING_free(octet);

 return (key);
}


static struct sshkey *
pkcs11_fetch_rsa_pubkey(struct pkcs11_provider *p, CK_ULONG slotidx,
    CK_OBJECT_HANDLE *obj)
{
 CK_ATTRIBUTE key_attr[3];
 CK_SESSION_HANDLE session;
 CK_FUNCTION_LIST *f = 
                      ((void *)0)
                          ;
 CK_RV rv;
 RSA *rsa = 
             ((void *)0)
                 ;
 BIGNUM *rsa_n, *rsa_e;
 struct sshkey *key = 
                      ((void *)0)
                          ;
 int i;

 memset(&key_attr, 0, sizeof(key_attr));
 key_attr[0].type = (0x102);
 key_attr[1].type = (0x120);
 key_attr[2].type = (0x122);

 session = p->slotinfo[slotidx].session;
 f = p->function_list;


 rv = f->C_GetAttributeValue(session, *obj, key_attr, 3);
 if (rv != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 847, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_GetAttributeValue failed: %lu", rv);
  return (
         ((void *)0)
             );
 }






 if (key_attr[1].ulValueLen == 0 ||
     key_attr[2].ulValueLen == 0) {
  sshlog("ssh-pkcs11.c", __func__, 858, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "invalid attribute length");
  return (
         ((void *)0)
             );
 }


 for (i = 0; i < 3; i++)
  if (key_attr[i].ulValueLen > 0)
   key_attr[i].pValue = xcalloc(1, key_attr[i].ulValueLen);


 rv = f->C_GetAttributeValue(session, *obj, key_attr, 3);
 if (rv != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 870, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_GetAttributeValue failed: %lu", rv);
  goto fail;
 }

 rsa = RSA_new();
 if (rsa == 
           ((void *)0)
               ) {
  sshlog("ssh-pkcs11.c", __func__, 876, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "RSA_new failed");
  goto fail;
 }

 rsa_n = BN_bin2bn(key_attr[1].pValue, key_attr[1].ulValueLen, 
                                                              ((void *)0)
                                                                  );
 rsa_e = BN_bin2bn(key_attr[2].pValue, key_attr[2].ulValueLen, 
                                                              ((void *)0)
                                                                  );
 if (rsa_n == 
             ((void *)0) 
                  || rsa_e == 
                              ((void *)0)
                                  ) {
  sshlog("ssh-pkcs11.c", __func__, 883, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "BN_bin2bn failed");
  goto fail;
 }
 if (!RSA_set0_key(rsa, rsa_n, rsa_e, 
                                     ((void *)0)
                                         ))
  sshfatal("ssh-pkcs11.c", __func__, 887, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "set key");
 rsa_n = rsa_e = 
                ((void *)0)
                    ;

 if (pkcs11_rsa_wrap(p, slotidx, &key_attr[0], rsa))
  goto fail;

 key = sshkey_new(KEY_UNSPEC);
 if (key == 
           ((void *)0)
               ) {
  sshlog("ssh-pkcs11.c", __func__, 895, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshkey_new failed");
  goto fail;
 }

 key->rsa = rsa;
 key->type = KEY_RSA;
 key->flags |= 0x0001;
 rsa = 
      ((void *)0)
          ;

fail:
 for (i = 0; i < 3; i++)
  free(key_attr[i].pValue);
 RSA_free(rsa);

 return (key);
}

static int
pkcs11_fetch_x509_pubkey(struct pkcs11_provider *p, CK_ULONG slotidx,
    CK_OBJECT_HANDLE *obj, struct sshkey **keyp, char **labelp)
{
 CK_ATTRIBUTE cert_attr[3];
 CK_SESSION_HANDLE session;
 CK_FUNCTION_LIST *f = 
                      ((void *)0)
                          ;
 CK_RV rv;
 X509 *x509 = 
               ((void *)0)
                   ;
 X509_NAME *x509_name = 
                        ((void *)0)
                            ;
 EVP_PKEY *evp;
 RSA *rsa = 
             ((void *)0)
                 ;

 EC_KEY *ec = 
               ((void *)0)
                   ;

 struct sshkey *key = 
                      ((void *)0)
                          ;
 int i;

 int nid;

 const u_char *cp;
 char *subject = 
                  ((void *)0)
                      ;

 *keyp = 
        ((void *)0)
            ;
 *labelp = 
          ((void *)0)
              ;

 memset(&cert_attr, 0, sizeof(cert_attr));
 cert_attr[0].type = (0x102);
 cert_attr[1].type = (0x101);
 cert_attr[2].type = (0x11);

 session = p->slotinfo[slotidx].session;
 f = p->function_list;


 rv = f->C_GetAttributeValue(session, *obj, cert_attr, 3);
 if (rv != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 949, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_GetAttributeValue failed: %lu", rv);
  return -1;
 }






 if (cert_attr[1].ulValueLen == 0 ||
     cert_attr[2].ulValueLen == 0) {
  sshlog("ssh-pkcs11.c", __func__, 960, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "invalid attribute length");
  return -1;
 }


 for (i = 0; i < 3; i++)
  if (cert_attr[i].ulValueLen > 0)
   cert_attr[i].pValue = xcalloc(1, cert_attr[i].ulValueLen);


 rv = f->C_GetAttributeValue(session, *obj, cert_attr, 3);
 if (rv != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 972, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_GetAttributeValue failed: %lu", rv);
  goto out;
 }


 cp = cert_attr[1].pValue;
 if ((x509_name = d2i_X509_NAME(
                               ((void *)0)
                                   , &cp,
     cert_attr[1].ulValueLen)) == 
                                 ((void *)0) 
                                      ||
     (subject = X509_NAME_oneline(x509_name, 
                                            ((void *)0)
                                                , 0)) == 
                                                         ((void *)0)
                                                             )
  subject = xstrdup("invalid subject");
 X509_NAME_free(x509_name);

 cp = cert_attr[2].pValue;
 if ((x509 = d2i_X509(
                     ((void *)0)
                         , &cp, cert_attr[2].ulValueLen)) == 
                                                             ((void *)0)
                                                                 ) {
  sshlog("ssh-pkcs11.c", __func__, 986, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "d2i_x509 failed");
  goto out;
 }

 if ((evp = X509_get_pubkey(x509)) == 
                                     ((void *)0)
                                         ) {
  sshlog("ssh-pkcs11.c", __func__, 991, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "X509_get_pubkey failed");
  goto out;
 }

 if (
    EVP_PKEY_get_base_id
                    (evp) == 
                             6
                                         ) {
  if (EVP_PKEY_get0_RSA(evp) == 
                               ((void *)0)
                                   ) {
   sshlog("ssh-pkcs11.c", __func__, 997, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "invalid x509; no rsa key");
   goto out;
  }
  if ((rsa = RSAPublicKey_dup(EVP_PKEY_get0_RSA(evp))) == 
                                                         ((void *)0)
                                                             ) {
   sshlog("ssh-pkcs11.c", __func__, 1001, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "RSAPublicKey_dup failed");
   goto out;
  }

  if (pkcs11_rsa_wrap(p, slotidx, &cert_attr[0], rsa))
   goto out;

  key = sshkey_new(KEY_UNSPEC);
  if (key == 
            ((void *)0)
                ) {
   sshlog("ssh-pkcs11.c", __func__, 1010, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "sshkey_new failed");
   goto out;
  }

  key->rsa = rsa;
  key->type = KEY_RSA;
  key->flags |= 0x0001;
  rsa = 
       ((void *)0)
           ;

 } else if (
           EVP_PKEY_get_base_id
                           (evp) == 
                                    408
                                               ) {
  if (EVP_PKEY_get0_EC_KEY(evp) == 
                                  ((void *)0)
                                      ) {
   sshlog("ssh-pkcs11.c", __func__, 1021, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "invalid x509; no ec key");
   goto out;
  }
  if ((ec = EC_KEY_dup(EVP_PKEY_get0_EC_KEY(evp))) == 
                                                     ((void *)0)
                                                         ) {
   sshlog("ssh-pkcs11.c", __func__, 1025, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "EC_KEY_dup failed");
   goto out;
  }

  nid = sshkey_ecdsa_key_to_nid(ec);
  if (nid < 0) {
   sshlog("ssh-pkcs11.c", __func__, 1031, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "couldn't get curve nid");
   goto out;
  }

  if (pkcs11_ecdsa_wrap(p, slotidx, &cert_attr[0], ec))
   goto out;

  key = sshkey_new(KEY_UNSPEC);
  if (key == 
            ((void *)0)
                ) {
   sshlog("ssh-pkcs11.c", __func__, 1040, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "sshkey_new failed");
   goto out;
  }

  key->ecdsa = ec;
  key->ecdsa_nid = nid;
  key->type = KEY_ECDSA;
  key->flags |= 0x0001;
  ec = 
      ((void *)0)
          ;

 } else {
  sshlog("ssh-pkcs11.c", __func__, 1051, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "unknown certificate key type");
  goto out;
 }
 out:
 for (i = 0; i < 3; i++)
  free(cert_attr[i].pValue);
 X509_free(x509);
 RSA_free(rsa);

 EC_KEY_free(ec);

 if (key == 
           ((void *)0)
               ) {
  free(subject);
  return -1;
 }

 *keyp = key;
 *labelp = subject;
 return 0;
}
static void
note_key(struct pkcs11_provider *p, CK_ULONG slotidx, const char *context,
    struct sshkey *key)
{
 char *fp;

 if ((fp = sshkey_fingerprint(key, 2,
     SSH_FP_DEFAULT)) == 
                        ((void *)0)
                            ) {
  sshlog("ssh-pkcs11.c", __func__, 1091, 1, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "sshkey_fingerprint failed");
  return;
 }
 sshlog("ssh-pkcs11.c", __func__, 1094, 0, SYSLOG_LEVEL_DEBUG2, 
((void *)0)
, "%s: provider %s slot %lu: %s %s", context, p->name, (u_long)slotidx, sshkey_type(key), fp)
                                           ;
 free(fp);
}






static int
pkcs11_fetch_certs(struct pkcs11_provider *p, CK_ULONG slotidx,
    struct sshkey ***keysp, char ***labelsp, int *nkeys)
{
 struct sshkey *key = 
                      ((void *)0)
                          ;
 CK_OBJECT_CLASS key_class;
 CK_ATTRIBUTE key_attr[1];
 CK_SESSION_HANDLE session;
 CK_FUNCTION_LIST *f = 
                      ((void *)0)
                          ;
 CK_RV rv;
 CK_OBJECT_HANDLE obj;
 CK_ULONG n = 0;
 int ret = -1;
 char *label;

 memset(&key_attr, 0, sizeof(key_attr));
 memset(&obj, 0, sizeof(obj));

 key_class = (1);
 key_attr[0].type = (0);
 key_attr[0].pValue = &key_class;
 key_attr[0].ulValueLen = sizeof(key_class);

 session = p->slotinfo[slotidx].session;
 f = p->function_list;

 rv = f->C_FindObjectsInit(session, key_attr, 1);
 if (rv != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 1132, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_FindObjectsInit failed: %lu", rv);
  goto fail;
 }

 while (1) {
  CK_CERTIFICATE_TYPE ck_cert_type;

  rv = f->C_FindObjects(session, &obj, 1, &n);
  if (rv != (0)) {
   sshlog("ssh-pkcs11.c", __func__, 1141, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "C_FindObjects failed: %lu", rv);
   goto fail;
  }
  if (n == 0)
   break;

  memset(&ck_cert_type, 0, sizeof(ck_cert_type));
  memset(&key_attr, 0, sizeof(key_attr));
  key_attr[0].type = (0x80);
  key_attr[0].pValue = &ck_cert_type;
  key_attr[0].ulValueLen = sizeof(ck_cert_type);

  rv = f->C_GetAttributeValue(session, obj, key_attr, 1);
  if (rv != (0)) {
   sshlog("ssh-pkcs11.c", __func__, 1155, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "C_GetAttributeValue failed: %lu", rv);
   goto fail;
  }

  key = 
       ((void *)0)
           ;
  label = 
         ((void *)0)
             ;
  switch (ck_cert_type) {
  case (0):
   if (pkcs11_fetch_x509_pubkey(p, slotidx, &obj,
       &key, &label) != 0) {
    sshlog("ssh-pkcs11.c", __func__, 1165, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "failed to fetch key");
    continue;
   }
   break;
  default:
   sshlog("ssh-pkcs11.c", __func__, 1170, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "skipping unsupported certificate type %lu", ck_cert_type)
                    ;
   continue;
  }
  note_key(p, slotidx, __func__, key);
  if (pkcs11_key_included(keysp, nkeys, key)) {
   sshlog("ssh-pkcs11.c", __func__, 1176, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "key already included");;
   sshkey_free(key);
  } else {

   *keysp = xrecallocarray(*keysp, *nkeys,
       *nkeys + 1, sizeof(struct sshkey *));
   (*keysp)[*nkeys] = key;
   if (labelsp != 
                 ((void *)0)
                     ) {
    *labelsp = xrecallocarray(*labelsp, *nkeys,
        *nkeys + 1, sizeof(char *));
    (*labelsp)[*nkeys] = xstrdup((char *)label);
   }
   *nkeys = *nkeys + 1;
   sshlog("ssh-pkcs11.c", __func__, 1189, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "have %d keys", *nkeys);
  }
 }

 ret = 0;
fail:
 rv = f->C_FindObjectsFinal(session);
 if (rv != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 1197, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_FindObjectsFinal failed: %lu", rv);
  ret = -1;
 }

 return (ret);
}






static int
pkcs11_fetch_keys(struct pkcs11_provider *p, CK_ULONG slotidx,
    struct sshkey ***keysp, char ***labelsp, int *nkeys)
{
 struct sshkey *key = 
                      ((void *)0)
                          ;
 CK_OBJECT_CLASS key_class;
 CK_ATTRIBUTE key_attr[2];
 CK_SESSION_HANDLE session;
 CK_FUNCTION_LIST *f = 
                      ((void *)0)
                          ;
 CK_RV rv;
 CK_OBJECT_HANDLE obj;
 CK_ULONG n = 0;
 int ret = -1;

 memset(&key_attr, 0, sizeof(key_attr));
 memset(&obj, 0, sizeof(obj));

 key_class = (2);
 key_attr[0].type = (0);
 key_attr[0].pValue = &key_class;
 key_attr[0].ulValueLen = sizeof(key_class);

 session = p->slotinfo[slotidx].session;
 f = p->function_list;

 rv = f->C_FindObjectsInit(session, key_attr, 1);
 if (rv != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 1236, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_FindObjectsInit failed: %lu", rv);
  goto fail;
 }

 while (1) {
  CK_KEY_TYPE ck_key_type;
  CK_UTF8CHAR label[256];

  rv = f->C_FindObjects(session, &obj, 1, &n);
  if (rv != (0)) {
   sshlog("ssh-pkcs11.c", __func__, 1246, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "C_FindObjects failed: %lu", rv);
   goto fail;
  }
  if (n == 0)
   break;

  memset(&ck_key_type, 0, sizeof(ck_key_type));
  memset(&key_attr, 0, sizeof(key_attr));
  key_attr[0].type = (0x100);
  key_attr[0].pValue = &ck_key_type;
  key_attr[0].ulValueLen = sizeof(ck_key_type);
  key_attr[1].type = (3);
  key_attr[1].pValue = &label;
  key_attr[1].ulValueLen = sizeof(label) - 1;

  rv = f->C_GetAttributeValue(session, obj, key_attr, 2);
  if (rv != (0)) {
   sshlog("ssh-pkcs11.c", __func__, 1263, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "C_GetAttributeValue failed: %lu", rv);
   goto fail;
  }

  label[key_attr[1].ulValueLen] = '\0';

  switch (ck_key_type) {
  case (0):
   key = pkcs11_fetch_rsa_pubkey(p, slotidx, &obj);
   break;

  case (3):
   key = pkcs11_fetch_ecdsa_pubkey(p, slotidx, &obj);
   break;

  default:

   key = 
        ((void *)0)
            ;
   sshlog("ssh-pkcs11.c", __func__, 1281, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "skipping unsupported key type");
  }

  if (key == 
            ((void *)0)
                ) {
   sshlog("ssh-pkcs11.c", __func__, 1285, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "failed to fetch key");
   continue;
  }
  note_key(p, slotidx, __func__, key);
  if (pkcs11_key_included(keysp, nkeys, key)) {
   sshlog("ssh-pkcs11.c", __func__, 1290, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "key already included");;
   sshkey_free(key);
  } else {

   *keysp = xrecallocarray(*keysp, *nkeys,
       *nkeys + 1, sizeof(struct sshkey *));
   (*keysp)[*nkeys] = key;
   if (labelsp != 
                 ((void *)0)
                     ) {
    *labelsp = xrecallocarray(*labelsp, *nkeys,
        *nkeys + 1, sizeof(char *));
    (*labelsp)[*nkeys] = xstrdup((char *)label);
   }
   *nkeys = *nkeys + 1;
   sshlog("ssh-pkcs11.c", __func__, 1303, 0, SYSLOG_LEVEL_DEBUG1, 
  ((void *)0)
  , "have %d keys", *nkeys);
  }
 }

 ret = 0;
fail:
 rv = f->C_FindObjectsFinal(session);
 if (rv != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 1311, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_FindObjectsFinal failed: %lu", rv);
  ret = -1;
 }

 return (ret);
}
static int
pkcs11_register_provider(char *provider_id, char *pin,
    struct sshkey ***keyp, char ***labelsp,
    struct pkcs11_provider **providerp, CK_ULONG user)
{
 int nkeys, need_finalize = 0;
 int ret = -1;
 struct pkcs11_provider *p = 
                            ((void *)0)
                                ;
 void *handle = 
               ((void *)0)
                   ;
 CK_RV (*getfunctionlist)(CK_FUNCTION_LIST **);
 CK_RV rv;
 CK_FUNCTION_LIST *f = 
                      ((void *)0)
                          ;
 CK_TOKEN_INFO *token;
 CK_ULONG i;

 if (providerp == 
                 ((void *)0)
                     )
  goto fail;
 *providerp = 
             ((void *)0)
                 ;

 if (keyp != 
            ((void *)0)
                )
  *keyp = 
         ((void *)0)
             ;
 if (labelsp != 
               ((void *)0)
                   )
  *labelsp = 
            ((void *)0)
                ;

 if (pkcs11_provider_lookup(provider_id) != 
                                           ((void *)0)
                                               ) {
  sshlog("ssh-pkcs11.c", __func__, 1532, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "provider already registered: %s", provider_id);
  goto fail;
 }

 if ((handle = dlopen(provider_id, 
                                  0x00002
                                          )) == 
                                                ((void *)0)
                                                    ) {
  sshlog("ssh-pkcs11.c", __func__, 1537, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "dlopen %s failed: %s", provider_id, dlerror());
  goto fail;
 }
 if ((getfunctionlist = dlsym(handle, "C_GetFunctionList")) == 
                                                              ((void *)0)
                                                                  ) {
  sshlog("ssh-pkcs11.c", __func__, 1541, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "dlsym(C_GetFunctionList) failed: %s", dlerror());
  goto fail;
 }
 p = xcalloc(1, sizeof(*p));
 p->name = xstrdup(provider_id);
 p->handle = handle;

 if ((rv = (*getfunctionlist)(&f)) != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 1549, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_GetFunctionList for provider %s failed: %lu", provider_id, rv)
                      ;
  goto fail;
 }
 p->function_list = f;
 if ((rv = f->C_Initialize(
                          ((void *)0)
                              )) != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 1555, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_Initialize for provider %s failed: %lu", provider_id, rv)
                      ;
  goto fail;
 }
 need_finalize = 1;
 if ((rv = f->C_GetInfo(&p->info)) != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 1561, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_GetInfo for provider %s failed: %lu", provider_id, rv)
                      ;
  goto fail;
 }
 rmspace(p->info.manufacturerID, sizeof(p->info.manufacturerID));
 rmspace(p->info.libraryDescription, sizeof(p->info.libraryDescription));
 sshlog("ssh-pkcs11.c", __func__, 1567, 0, SYSLOG_LEVEL_DEBUG1, 
((void *)0)
, "provider %s: manufacturerID <%s> cryptokiVersion %d.%d" " libraryDescription <%s> libraryVersion %d.%d", provider_id, p->info.manufacturerID, p->info.cryptokiVersion.major, p->info.cryptokiVersion.minor, p->info.libraryDescription, p->info.libraryVersion.major, p->info.libraryVersion.minor)







                                  ;
 if ((rv = f->C_GetSlotList(1, 
                                    ((void *)0)
                                        , &p->nslots)) != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 1577, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_GetSlotList failed: %lu", rv);
  goto fail;
 }
 if (p->nslots == 0) {
  sshlog("ssh-pkcs11.c", __func__, 1581, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "provider %s returned no slots", provider_id);
  ret = -3;
  goto fail;
 }
 p->slotlist = xcalloc(p->nslots, sizeof(CK_SLOT_ID));
 if ((rv = f->C_GetSlotList(1, p->slotlist, &p->nslots))
     != (0)) {
  sshlog("ssh-pkcs11.c", __func__, 1588, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_GetSlotList for provider %s failed: %lu", provider_id, rv)
                      ;
  goto fail;
 }
 p->slotinfo = xcalloc(p->nslots, sizeof(struct pkcs11_slotinfo));
 p->valid = 1;
 nkeys = 0;
 for (i = 0; i < p->nslots; i++) {
  token = &p->slotinfo[i].token;
  if ((rv = f->C_GetTokenInfo(p->slotlist[i], token))
      != (0)) {
   sshlog("ssh-pkcs11.c", __func__, 1599, 0, SYSLOG_LEVEL_ERROR, 
  ((void *)0)
  , "C_GetTokenInfo for provider %s slot %lu " "failed: %lu", provider_id, (u_long)i, rv)
                                                 ;
   continue;
  }
  if ((token->flags & (1 << 10)) == 0) {
   sshlog("ssh-pkcs11.c", __func__, 1604, 1, SYSLOG_LEVEL_DEBUG2, 
  ((void *)0)
  , "ignoring uninitialised token in " "provider %s slot %lu", provider_id, (u_long)i)
                                                      ;
   continue;
  }
  rmspace(token->label, sizeof(token->label));
  rmspace(token->manufacturerID, sizeof(token->manufacturerID));
  rmspace(token->model, sizeof(token->model));
  rmspace(token->serialNumber, sizeof(token->serialNumber));
  sshlog("ssh-pkcs11.c", __func__, 1612, 0, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "provider %s slot %lu: label <%s> manufacturerID <%s> " "model <%s> serial <%s> flags 0x%lx", provider_id, (unsigned long)i, token->label, token->manufacturerID, token->model, token->serialNumber, token->flags)



                                        ;




  if ((ret = pkcs11_open_session(p, i, pin, user)) != 0 ||
      keyp == 
             ((void *)0)
                 )
   continue;
  pkcs11_fetch_keys(p, i, keyp, labelsp, &nkeys);
  pkcs11_fetch_certs(p, i, keyp, labelsp, &nkeys);
  if (nkeys == 0 && !p->slotinfo[i].logged_in &&
      pkcs11_interactive) {




   if (pkcs11_login_slot(p, &p->slotinfo[i],
       (1)) < 0) {
    sshlog("ssh-pkcs11.c", __func__, 1634, 0, SYSLOG_LEVEL_ERROR, 
   ((void *)0)
   , "login failed");
    continue;
   }
   pkcs11_fetch_keys(p, i, keyp, labelsp, &nkeys);
   pkcs11_fetch_certs(p, i, keyp, labelsp, &nkeys);
  }
 }


 *providerp = p;

 do { (p)->next.tqe_next = 
((void *)0)
; (p)->next.tqe_prev = (&pkcs11_providers)->tqh_last; *(&pkcs11_providers)->tqh_last = (p); (&pkcs11_providers)->tqh_last = &(p)->next.tqe_next; } while (0);
 p->refcount++;

 return (nkeys);
fail:
 if (need_finalize && (rv = f->C_Finalize(
                                         ((void *)0)
                                             )) != (0))
  sshlog("ssh-pkcs11.c", __func__, 1651, 0, SYSLOG_LEVEL_ERROR, 
 ((void *)0)
 , "C_Finalize for provider %s failed: %lu", provider_id, rv)
                      ;
 if (p) {
  free(p->name);
  free(p->slotlist);
  free(p->slotinfo);
  free(p);
 }
 if (handle)
  dlclose(handle);
 if (ret > 0)
  ret = -1;
 return (ret);
}





int
pkcs11_add_provider(char *provider_id, char *pin, struct sshkey ***keyp,
    char ***labelsp)
{
 struct pkcs11_provider *p = 
                            ((void *)0)
                                ;
 int nkeys;

 nkeys = pkcs11_register_provider(provider_id, pin, keyp, labelsp,
     &p, (1));


 if (nkeys <= 0 && p != 
                       ((void *)0)
                           ) {
  do { if (((p)->next.tqe_next) != 
 ((void *)0)
 ) (p)->next.tqe_next->next.tqe_prev = (p)->next.tqe_prev; else (&pkcs11_providers)->tqh_last = (p)->next.tqe_prev; *(p)->next.tqe_prev = (p)->next.tqe_next; ; ; } while (0);
  pkcs11_provider_finalize(p);
  pkcs11_provider_unref(p);
 }
 if (nkeys == 0)
  sshlog("ssh-pkcs11.c", __func__, 1687, 1, SYSLOG_LEVEL_DEBUG1, 
 ((void *)0)
 , "provider %s returned no keys", provider_id);

 return (nkeys);
}
