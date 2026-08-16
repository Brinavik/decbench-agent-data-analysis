
       
       
       
extern int _gl_cxxalias_dummy

                                      ;

extern int _gl_cxxalias_dummy;




       


struct __time_t_must_be_integral {
  unsigned int __floating_time_t_unsupported : (time_t) 1;
};
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                           ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                        ;


extern int _gl_cxxalias_dummy;
typedef struct tm_zone *timezone_t;
extern timezone_t tzalloc (char const *__name);
extern int _gl_cxxalias_dummy;




extern void tzfree (timezone_t __tz);
extern int _gl_cxxalias_dummy;






extern struct tm * localtime_rz (timezone_t __tz, time_t const *
__restrict__ 
__timer, struct tm *
__restrict__ 
__result) __attribute__ ((__nonnull__ (2, 3)))

                                                                          ;
extern int _gl_cxxalias_dummy

                                                 ;






extern time_t mktime_z (timezone_t __tz, struct tm *
__restrict__ 
__tm) __attribute__ ((__nonnull__ (2)))

                                        ;
extern int _gl_cxxalias_dummy
                                                              ;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;

typedef enum gnutls_cipher_algorithm {
 GNUTLS_CIPHER_UNKNOWN = 0,
 GNUTLS_CIPHER_NULL = 1,
 GNUTLS_CIPHER_ARCFOUR_128 = 2,
 GNUTLS_CIPHER_3DES_CBC = 3,
 GNUTLS_CIPHER_AES_128_CBC = 4,
 GNUTLS_CIPHER_AES_256_CBC = 5,
 GNUTLS_CIPHER_ARCFOUR_40 = 6,
 GNUTLS_CIPHER_CAMELLIA_128_CBC = 7,
 GNUTLS_CIPHER_CAMELLIA_256_CBC = 8,
 GNUTLS_CIPHER_AES_192_CBC = 9,
 GNUTLS_CIPHER_AES_128_GCM = 10,
 GNUTLS_CIPHER_AES_256_GCM = 11,
 GNUTLS_CIPHER_CAMELLIA_192_CBC = 12,
 GNUTLS_CIPHER_SALSA20_256 = 13,
 GNUTLS_CIPHER_ESTREAM_SALSA20_256 = 14,
 GNUTLS_CIPHER_CAMELLIA_128_GCM = 15,
 GNUTLS_CIPHER_CAMELLIA_256_GCM = 16,
 GNUTLS_CIPHER_RC2_40_CBC = 17,
 GNUTLS_CIPHER_DES_CBC = 18,
 GNUTLS_CIPHER_AES_128_CCM = 19,
 GNUTLS_CIPHER_AES_256_CCM = 20,
 GNUTLS_CIPHER_AES_128_CCM_8 = 21,
 GNUTLS_CIPHER_AES_256_CCM_8 = 22,
 GNUTLS_CIPHER_CHACHA20_POLY1305 = 23,
 GNUTLS_CIPHER_GOST28147_TC26Z_CFB = 24,
 GNUTLS_CIPHER_GOST28147_CPA_CFB = 25,
 GNUTLS_CIPHER_GOST28147_CPB_CFB = 26,
 GNUTLS_CIPHER_GOST28147_CPC_CFB = 27,
 GNUTLS_CIPHER_GOST28147_CPD_CFB = 28,
 GNUTLS_CIPHER_AES_128_CFB8 = 29,
 GNUTLS_CIPHER_AES_192_CFB8 = 30,
 GNUTLS_CIPHER_AES_256_CFB8 = 31,
 GNUTLS_CIPHER_AES_128_XTS = 32,
 GNUTLS_CIPHER_AES_256_XTS = 33,
 GNUTLS_CIPHER_GOST28147_TC26Z_CNT = 34,
 GNUTLS_CIPHER_CHACHA20_64 = 35,
 GNUTLS_CIPHER_CHACHA20_32 = 36,
 GNUTLS_CIPHER_AES_128_SIV = 37,
 GNUTLS_CIPHER_AES_256_SIV = 38,
 GNUTLS_CIPHER_AES_192_GCM = 39,
 GNUTLS_CIPHER_MAGMA_CTR_ACPKM = 40,
 GNUTLS_CIPHER_KUZNYECHIK_CTR_ACPKM = 41,



 GNUTLS_CIPHER_IDEA_PGP_CFB = 200,
 GNUTLS_CIPHER_3DES_PGP_CFB = 201,
 GNUTLS_CIPHER_CAST5_PGP_CFB = 202,
 GNUTLS_CIPHER_BLOWFISH_PGP_CFB = 203,
 GNUTLS_CIPHER_SAFER_SK128_PGP_CFB = 204,
 GNUTLS_CIPHER_AES128_PGP_CFB = 205,
 GNUTLS_CIPHER_AES192_PGP_CFB = 206,
 GNUTLS_CIPHER_AES256_PGP_CFB = 207,
 GNUTLS_CIPHER_TWOFISH_PGP_CFB = 208
} gnutls_cipher_algorithm_t;
typedef enum {
 GNUTLS_KX_UNKNOWN = 0,
 GNUTLS_KX_RSA = 1,
 GNUTLS_KX_DHE_DSS = 2,
 GNUTLS_KX_DHE_RSA = 3,
 GNUTLS_KX_ANON_DH = 4,
 GNUTLS_KX_SRP = 5,
 GNUTLS_KX_RSA_EXPORT = 6,
 GNUTLS_KX_SRP_RSA = 7,
 GNUTLS_KX_SRP_DSS = 8,
 GNUTLS_KX_PSK = 9,
 GNUTLS_KX_DHE_PSK = 10,
 GNUTLS_KX_ANON_ECDH = 11,
 GNUTLS_KX_ECDHE_RSA = 12,
 GNUTLS_KX_ECDHE_ECDSA = 13,
 GNUTLS_KX_ECDHE_PSK = 14,
 GNUTLS_KX_RSA_PSK = 15,
 GNUTLS_KX_VKO_GOST_12 = 16
} gnutls_kx_algorithm_t;
typedef enum {
 GNUTLS_PARAMS_RSA_EXPORT = 1,
 GNUTLS_PARAMS_DH = 2,
 GNUTLS_PARAMS_ECDH = 3
} gnutls_params_type_t;
typedef enum {
 GNUTLS_CRD_CERTIFICATE = 1,
 GNUTLS_CRD_ANON,
 GNUTLS_CRD_SRP,
 GNUTLS_CRD_PSK,
 GNUTLS_CRD_IA
} gnutls_credentials_type_t;
typedef enum {
 GNUTLS_MAC_UNKNOWN = 0,
 GNUTLS_MAC_NULL = 1,
 GNUTLS_MAC_MD5 = 2,
 GNUTLS_MAC_SHA1 = 3,
 GNUTLS_MAC_RMD160 = 4,
 GNUTLS_MAC_MD2 = 5,
 GNUTLS_MAC_SHA256 = 6,
 GNUTLS_MAC_SHA384 = 7,
 GNUTLS_MAC_SHA512 = 8,
 GNUTLS_MAC_SHA224 = 9,
 GNUTLS_MAC_SHA3_224 = 10,
 GNUTLS_MAC_SHA3_256 = 11,
 GNUTLS_MAC_SHA3_384 = 12,
 GNUTLS_MAC_SHA3_512 = 13,
 GNUTLS_MAC_MD5_SHA1 = 14,
 GNUTLS_MAC_GOSTR_94 = 15,
 GNUTLS_MAC_STREEBOG_256 = 16,
 GNUTLS_MAC_STREEBOG_512 = 17,


 GNUTLS_MAC_AEAD = 200,
 GNUTLS_MAC_UMAC_96 = 201,
 GNUTLS_MAC_UMAC_128 = 202,
 GNUTLS_MAC_AES_CMAC_128 = 203,
 GNUTLS_MAC_AES_CMAC_256 = 204,
 GNUTLS_MAC_AES_GMAC_128 = 205,
 GNUTLS_MAC_AES_GMAC_192 = 206,
 GNUTLS_MAC_AES_GMAC_256 = 207,
 GNUTLS_MAC_GOST28147_TC26Z_IMIT = 208,
 GNUTLS_MAC_SHAKE_128 = 209,
 GNUTLS_MAC_SHAKE_256 = 210,
 GNUTLS_MAC_MAGMA_OMAC = 211,
 GNUTLS_MAC_KUZNYECHIK_OMAC = 212
} gnutls_mac_algorithm_t;
typedef enum {
 GNUTLS_DIG_UNKNOWN = GNUTLS_MAC_UNKNOWN,
 GNUTLS_DIG_NULL = GNUTLS_MAC_NULL,
 GNUTLS_DIG_MD5 = GNUTLS_MAC_MD5,
 GNUTLS_DIG_SHA1 = GNUTLS_MAC_SHA1,
 GNUTLS_DIG_RMD160 = GNUTLS_MAC_RMD160,
 GNUTLS_DIG_MD2 = GNUTLS_MAC_MD2,
 GNUTLS_DIG_SHA256 = GNUTLS_MAC_SHA256,
 GNUTLS_DIG_SHA384 = GNUTLS_MAC_SHA384,
 GNUTLS_DIG_SHA512 = GNUTLS_MAC_SHA512,
 GNUTLS_DIG_SHA224 = GNUTLS_MAC_SHA224,
 GNUTLS_DIG_SHA3_224 = GNUTLS_MAC_SHA3_224,
 GNUTLS_DIG_SHA3_256 = GNUTLS_MAC_SHA3_256,
 GNUTLS_DIG_SHA3_384 = GNUTLS_MAC_SHA3_384,
 GNUTLS_DIG_SHA3_512 = GNUTLS_MAC_SHA3_512,
 GNUTLS_DIG_MD5_SHA1 = GNUTLS_MAC_MD5_SHA1,
 GNUTLS_DIG_GOSTR_94 = GNUTLS_MAC_GOSTR_94,
 GNUTLS_DIG_STREEBOG_256 = GNUTLS_MAC_STREEBOG_256,
 GNUTLS_DIG_STREEBOG_512 = GNUTLS_MAC_STREEBOG_512,
 GNUTLS_DIG_SHAKE_128 = GNUTLS_MAC_SHAKE_128,
 GNUTLS_DIG_SHAKE_256 = GNUTLS_MAC_SHAKE_256


} gnutls_digest_algorithm_t;
typedef enum {
 GNUTLS_COMP_UNKNOWN = 0,
 GNUTLS_COMP_NULL = 1,
 GNUTLS_COMP_DEFLATE = 2,
 GNUTLS_COMP_ZLIB = GNUTLS_COMP_DEFLATE,
 GNUTLS_COMP_BROTLI = 3,
 GNUTLS_COMP_ZSTD = 4
} gnutls_compression_method_t;
typedef enum {
 GNUTLS_SERVER = 1,
 GNUTLS_CLIENT = (1<<1),
 GNUTLS_DATAGRAM = (1<<2),
 GNUTLS_NONBLOCK = (1<<3),
 GNUTLS_NO_EXTENSIONS = (1<<4),
 GNUTLS_NO_REPLAY_PROTECTION = (1<<5),
 GNUTLS_NO_SIGNAL = (1<<6),
 GNUTLS_ALLOW_ID_CHANGE = (1<<7),
 GNUTLS_ENABLE_FALSE_START = (1<<8),
 GNUTLS_FORCE_CLIENT_CERT = (1<<9),
 GNUTLS_NO_TICKETS = (1<<10),
 GNUTLS_KEY_SHARE_TOP = (1<<11),
 GNUTLS_KEY_SHARE_TOP2 = (1<<12),
 GNUTLS_KEY_SHARE_TOP3 = (1<<13),
 GNUTLS_POST_HANDSHAKE_AUTH = (1<<14),
 GNUTLS_NO_AUTO_REKEY = (1<<15),
 GNUTLS_SAFE_PADDING_CHECK = (1<<16),
 GNUTLS_ENABLE_EARLY_START = (1<<17),
 GNUTLS_ENABLE_RAWPK = (1<<18),
 GNUTLS_AUTO_REAUTH = (1<<19),
 GNUTLS_ENABLE_EARLY_DATA = (1<<20),
 GNUTLS_NO_AUTO_SEND_TICKET = (1<<21),
 GNUTLS_NO_END_OF_EARLY_DATA = (1<<22),
 GNUTLS_NO_TICKETS_TLS12 = (1<<23)
} gnutls_init_flags_t;
typedef enum {
 GNUTLS_AL_WARNING = 1,
 GNUTLS_AL_FATAL
} gnutls_alert_level_t;
typedef enum {
 GNUTLS_A_CLOSE_NOTIFY,
 GNUTLS_A_UNEXPECTED_MESSAGE = 10,
 GNUTLS_A_BAD_RECORD_MAC = 20,
 GNUTLS_A_DECRYPTION_FAILED,
 GNUTLS_A_RECORD_OVERFLOW,
 GNUTLS_A_DECOMPRESSION_FAILURE = 30,
 GNUTLS_A_HANDSHAKE_FAILURE = 40,
 GNUTLS_A_SSL3_NO_CERTIFICATE = 41,
 GNUTLS_A_BAD_CERTIFICATE = 42,
 GNUTLS_A_UNSUPPORTED_CERTIFICATE,
 GNUTLS_A_CERTIFICATE_REVOKED,
 GNUTLS_A_CERTIFICATE_EXPIRED,
 GNUTLS_A_CERTIFICATE_UNKNOWN,
 GNUTLS_A_ILLEGAL_PARAMETER,
 GNUTLS_A_UNKNOWN_CA,
 GNUTLS_A_ACCESS_DENIED,
 GNUTLS_A_DECODE_ERROR = 50,
 GNUTLS_A_DECRYPT_ERROR,
 GNUTLS_A_EXPORT_RESTRICTION = 60,
 GNUTLS_A_PROTOCOL_VERSION = 70,
 GNUTLS_A_INSUFFICIENT_SECURITY,
 GNUTLS_A_INTERNAL_ERROR = 80,
 GNUTLS_A_INAPPROPRIATE_FALLBACK = 86,
 GNUTLS_A_USER_CANCELED = 90,
 GNUTLS_A_NO_RENEGOTIATION = 100,
 GNUTLS_A_MISSING_EXTENSION = 109,
 GNUTLS_A_UNSUPPORTED_EXTENSION = 110,
 GNUTLS_A_CERTIFICATE_UNOBTAINABLE = 111,
 GNUTLS_A_UNRECOGNIZED_NAME = 112,
 GNUTLS_A_UNKNOWN_PSK_IDENTITY = 115,
 GNUTLS_A_CERTIFICATE_REQUIRED = 116,
 GNUTLS_A_NO_APPLICATION_PROTOCOL = 120,
 GNUTLS_A_MAX = GNUTLS_A_NO_APPLICATION_PROTOCOL
} gnutls_alert_description_t;
typedef enum {
 GNUTLS_HANDSHAKE_HELLO_REQUEST = 0,
 GNUTLS_HANDSHAKE_CLIENT_HELLO = 1,
 GNUTLS_HANDSHAKE_SERVER_HELLO = 2,
 GNUTLS_HANDSHAKE_HELLO_VERIFY_REQUEST = 3,
 GNUTLS_HANDSHAKE_NEW_SESSION_TICKET = 4,
 GNUTLS_HANDSHAKE_END_OF_EARLY_DATA = 5,
 GNUTLS_HANDSHAKE_ENCRYPTED_EXTENSIONS = 8,
 GNUTLS_HANDSHAKE_CERTIFICATE_PKT = 11,
 GNUTLS_HANDSHAKE_SERVER_KEY_EXCHANGE = 12,
 GNUTLS_HANDSHAKE_CERTIFICATE_REQUEST = 13,
 GNUTLS_HANDSHAKE_SERVER_HELLO_DONE = 14,
 GNUTLS_HANDSHAKE_CERTIFICATE_VERIFY = 15,
 GNUTLS_HANDSHAKE_CLIENT_KEY_EXCHANGE = 16,
 GNUTLS_HANDSHAKE_FINISHED = 20,
 GNUTLS_HANDSHAKE_CERTIFICATE_STATUS = 22,
 GNUTLS_HANDSHAKE_SUPPLEMENTAL = 23,
 GNUTLS_HANDSHAKE_KEY_UPDATE = 24,
 GNUTLS_HANDSHAKE_COMPRESSED_CERTIFICATE_PKT = 25,
 GNUTLS_HANDSHAKE_CHANGE_CIPHER_SPEC = 254,
 GNUTLS_HANDSHAKE_CLIENT_HELLO_V2 = 1024,
 GNUTLS_HANDSHAKE_HELLO_RETRY_REQUEST = 1025,
} gnutls_handshake_description_t;



const char
    *gnutls_handshake_description_get_name(gnutls_handshake_description_t
        type);
typedef enum {
 GNUTLS_CERT_INVALID = 1 << 1,
 GNUTLS_CERT_REVOKED = 1 << 5,
 GNUTLS_CERT_SIGNER_NOT_FOUND = 1 << 6,
 GNUTLS_CERT_SIGNER_NOT_CA = 1 << 7,
 GNUTLS_CERT_INSECURE_ALGORITHM = 1 << 8,
 GNUTLS_CERT_NOT_ACTIVATED = 1 << 9,
 GNUTLS_CERT_EXPIRED = 1 << 10,
 GNUTLS_CERT_SIGNATURE_FAILURE = 1 << 11,
 GNUTLS_CERT_REVOCATION_DATA_SUPERSEDED = 1 << 12,
 GNUTLS_CERT_UNEXPECTED_OWNER = 1 << 14,
 GNUTLS_CERT_REVOCATION_DATA_ISSUED_IN_FUTURE = 1 << 15,
 GNUTLS_CERT_SIGNER_CONSTRAINTS_FAILURE = 1 << 16,
 GNUTLS_CERT_MISMATCH = 1 << 17,
 GNUTLS_CERT_PURPOSE_MISMATCH = 1 << 18,
 GNUTLS_CERT_MISSING_OCSP_STATUS = 1 << 19,
 GNUTLS_CERT_INVALID_OCSP_STATUS = 1 << 20,
 GNUTLS_CERT_UNKNOWN_CRIT_EXTENSIONS = 1 << 21
} gnutls_certificate_status_t;
typedef enum {
 GNUTLS_CERT_IGNORE = 0,
 GNUTLS_CERT_REQUEST = 1,
 GNUTLS_CERT_REQUIRE = 2
} gnutls_certificate_request_t;
typedef enum {
 GNUTLS_OPENPGP_CERT = 0,
 GNUTLS_OPENPGP_CERT_FINGERPRINT = 1
} gnutls_openpgp_crt_status_t;
typedef enum {
 GNUTLS_SHUT_RDWR = 0,
 GNUTLS_SHUT_WR = 1
} gnutls_close_request_t;
typedef enum {
 GNUTLS_SSL3 = 1,
 GNUTLS_TLS1_0 = 2,
 GNUTLS_TLS1 = GNUTLS_TLS1_0,
 GNUTLS_TLS1_1 = 3,
 GNUTLS_TLS1_2 = 4,
 GNUTLS_TLS1_3 = 5,

 GNUTLS_DTLS0_9 = 200,
 GNUTLS_DTLS1_0 = 201,
 GNUTLS_DTLS1_2 = 202,
 GNUTLS_DTLS_VERSION_MIN = GNUTLS_DTLS0_9,
 GNUTLS_DTLS_VERSION_MAX = GNUTLS_DTLS1_2,
 GNUTLS_TLS_VERSION_MAX = GNUTLS_TLS1_3,
 GNUTLS_VERSION_UNKNOWN = 0xff
} gnutls_protocol_t;
typedef enum {
 GNUTLS_CRT_UNKNOWN = 0,
 GNUTLS_CRT_X509 = 1,
 GNUTLS_CRT_OPENPGP = 2,
 GNUTLS_CRT_RAWPK = 3,
 GNUTLS_CRT_MAX = GNUTLS_CRT_RAWPK
} gnutls_certificate_type_t;
typedef enum {
 GNUTLS_X509_FMT_DER = 0,
 GNUTLS_X509_FMT_PEM = 1
} gnutls_x509_crt_fmt_t;
typedef enum gnutls_certificate_print_formats {
 GNUTLS_CRT_PRINT_FULL = 0,
 GNUTLS_CRT_PRINT_ONELINE = 1,
 GNUTLS_CRT_PRINT_UNSIGNED_FULL = 2,
 GNUTLS_CRT_PRINT_COMPACT = 3,
 GNUTLS_CRT_PRINT_FULL_NUMBERS = 4
} gnutls_certificate_print_formats_t;
typedef enum {
 GNUTLS_PK_UNKNOWN = 0,
 GNUTLS_PK_RSA = 1,
 GNUTLS_PK_DSA = 2,
 GNUTLS_PK_DH = 3,
 GNUTLS_PK_ECDSA = 4,
 GNUTLS_PK_ECDH_X25519 = 5,
 GNUTLS_PK_RSA_PSS = 6,
 GNUTLS_PK_EDDSA_ED25519 = 7,
 GNUTLS_PK_GOST_01 = 8,
 GNUTLS_PK_GOST_12_256 = 9,
 GNUTLS_PK_GOST_12_512 = 10,
 GNUTLS_PK_ECDH_X448 = 11,
 GNUTLS_PK_EDDSA_ED448 = 12,
 GNUTLS_PK_MAX = GNUTLS_PK_EDDSA_ED448
} gnutls_pk_algorithm_t;


const char *gnutls_pk_algorithm_get_name(gnutls_pk_algorithm_t algorithm);
typedef enum {
 GNUTLS_SIGN_UNKNOWN = 0,
 GNUTLS_SIGN_RSA_SHA1 = 1,
 GNUTLS_SIGN_RSA_SHA = GNUTLS_SIGN_RSA_SHA1,
 GNUTLS_SIGN_DSA_SHA1 = 2,
 GNUTLS_SIGN_DSA_SHA = GNUTLS_SIGN_DSA_SHA1,
 GNUTLS_SIGN_RSA_MD5 = 3,
 GNUTLS_SIGN_RSA_MD2 = 4,
 GNUTLS_SIGN_RSA_RMD160 = 5,
 GNUTLS_SIGN_RSA_SHA256 = 6,
 GNUTLS_SIGN_RSA_SHA384 = 7,
 GNUTLS_SIGN_RSA_SHA512 = 8,
 GNUTLS_SIGN_RSA_SHA224 = 9,
 GNUTLS_SIGN_DSA_SHA224 = 10,
 GNUTLS_SIGN_DSA_SHA256 = 11,
 GNUTLS_SIGN_ECDSA_SHA1 = 12,
 GNUTLS_SIGN_ECDSA_SHA224 = 13,
 GNUTLS_SIGN_ECDSA_SHA256 = 14,
 GNUTLS_SIGN_ECDSA_SHA384 = 15,
 GNUTLS_SIGN_ECDSA_SHA512 = 16,
 GNUTLS_SIGN_DSA_SHA384 = 17,
 GNUTLS_SIGN_DSA_SHA512 = 18,
 GNUTLS_SIGN_ECDSA_SHA3_224 = 20,
 GNUTLS_SIGN_ECDSA_SHA3_256 = 21,
 GNUTLS_SIGN_ECDSA_SHA3_384 = 22,
 GNUTLS_SIGN_ECDSA_SHA3_512 = 23,

 GNUTLS_SIGN_DSA_SHA3_224 = 24,
 GNUTLS_SIGN_DSA_SHA3_256 = 25,
 GNUTLS_SIGN_DSA_SHA3_384 = 26,
 GNUTLS_SIGN_DSA_SHA3_512 = 27,
 GNUTLS_SIGN_RSA_SHA3_224 = 28,
 GNUTLS_SIGN_RSA_SHA3_256 = 29,
 GNUTLS_SIGN_RSA_SHA3_384 = 30,
 GNUTLS_SIGN_RSA_SHA3_512 = 31,

 GNUTLS_SIGN_RSA_PSS_SHA256 = 32,
 GNUTLS_SIGN_RSA_PSS_SHA384 = 33,
 GNUTLS_SIGN_RSA_PSS_SHA512 = 34,
 GNUTLS_SIGN_EDDSA_ED25519 = 35,
 GNUTLS_SIGN_RSA_RAW = 36,

 GNUTLS_SIGN_ECDSA_SECP256R1_SHA256 = 37,
 GNUTLS_SIGN_ECDSA_SECP384R1_SHA384 = 38,
 GNUTLS_SIGN_ECDSA_SECP521R1_SHA512 = 39,

 GNUTLS_SIGN_RSA_PSS_RSAE_SHA256 = 40,
 GNUTLS_SIGN_RSA_PSS_RSAE_SHA384 = 41,
 GNUTLS_SIGN_RSA_PSS_RSAE_SHA512 = 42,

 GNUTLS_SIGN_GOST_94 = 43,
 GNUTLS_SIGN_GOST_256 = 44,
 GNUTLS_SIGN_GOST_512 = 45,
 GNUTLS_SIGN_EDDSA_ED448 = 46,
 GNUTLS_SIGN_MAX = GNUTLS_SIGN_EDDSA_ED448
} gnutls_sign_algorithm_t;
typedef enum {
 GNUTLS_ECC_CURVE_INVALID = 0,
 GNUTLS_ECC_CURVE_SECP224R1,
 GNUTLS_ECC_CURVE_SECP256R1,
 GNUTLS_ECC_CURVE_SECP384R1,
 GNUTLS_ECC_CURVE_SECP521R1,
 GNUTLS_ECC_CURVE_SECP192R1,
 GNUTLS_ECC_CURVE_X25519,
 GNUTLS_ECC_CURVE_ED25519,
 GNUTLS_ECC_CURVE_GOST256CPA,
 GNUTLS_ECC_CURVE_GOST256CPB,
 GNUTLS_ECC_CURVE_GOST256CPC,
 GNUTLS_ECC_CURVE_GOST256CPXA,
 GNUTLS_ECC_CURVE_GOST256CPXB,
 GNUTLS_ECC_CURVE_GOST512A,
 GNUTLS_ECC_CURVE_GOST512B,
 GNUTLS_ECC_CURVE_GOST512C,
 GNUTLS_ECC_CURVE_GOST256A,
 GNUTLS_ECC_CURVE_GOST256B,
 GNUTLS_ECC_CURVE_GOST256C,
 GNUTLS_ECC_CURVE_GOST256D,
 GNUTLS_ECC_CURVE_X448,
 GNUTLS_ECC_CURVE_ED448,
 GNUTLS_ECC_CURVE_MAX = GNUTLS_ECC_CURVE_ED448
} gnutls_ecc_curve_t;
typedef enum {
 GNUTLS_GROUP_INVALID = 0,
 GNUTLS_GROUP_SECP192R1 = GNUTLS_ECC_CURVE_SECP192R1,
 GNUTLS_GROUP_SECP224R1 = GNUTLS_ECC_CURVE_SECP224R1,
 GNUTLS_GROUP_SECP256R1 = GNUTLS_ECC_CURVE_SECP256R1,
 GNUTLS_GROUP_SECP384R1 = GNUTLS_ECC_CURVE_SECP384R1,
 GNUTLS_GROUP_SECP521R1 = GNUTLS_ECC_CURVE_SECP521R1,
 GNUTLS_GROUP_X25519 = GNUTLS_ECC_CURVE_X25519,
 GNUTLS_GROUP_X448 = GNUTLS_ECC_CURVE_X448,

 GNUTLS_GROUP_GC256A = GNUTLS_ECC_CURVE_GOST256A,
 GNUTLS_GROUP_GC256B = GNUTLS_ECC_CURVE_GOST256B,
 GNUTLS_GROUP_GC256C = GNUTLS_ECC_CURVE_GOST256C,
 GNUTLS_GROUP_GC256D = GNUTLS_ECC_CURVE_GOST256D,
 GNUTLS_GROUP_GC512A = GNUTLS_ECC_CURVE_GOST512A,
 GNUTLS_GROUP_GC512B = GNUTLS_ECC_CURVE_GOST512B,
 GNUTLS_GROUP_GC512C = GNUTLS_ECC_CURVE_GOST512C,

 GNUTLS_GROUP_FFDHE2048 = 256,
 GNUTLS_GROUP_FFDHE3072,
 GNUTLS_GROUP_FFDHE4096,
 GNUTLS_GROUP_FFDHE8192,
 GNUTLS_GROUP_FFDHE6144,
 GNUTLS_GROUP_MAX = GNUTLS_GROUP_FFDHE6144,
} gnutls_group_t;
typedef enum {
 GNUTLS_SEC_PARAM_UNKNOWN = 0,
 GNUTLS_SEC_PARAM_INSECURE = 5,
 GNUTLS_SEC_PARAM_EXPORT = 10,
 GNUTLS_SEC_PARAM_VERY_WEAK = 15,
 GNUTLS_SEC_PARAM_WEAK = 20,
 GNUTLS_SEC_PARAM_LOW = 25,
 GNUTLS_SEC_PARAM_LEGACY = 30,
 GNUTLS_SEC_PARAM_MEDIUM = 35,
 GNUTLS_SEC_PARAM_HIGH = 40,
 GNUTLS_SEC_PARAM_ULTRA = 45,
 GNUTLS_SEC_PARAM_FUTURE = 50,
 GNUTLS_SEC_PARAM_MAX = GNUTLS_SEC_PARAM_FUTURE
} gnutls_sec_param_t;
typedef enum {
 GNUTLS_CB_TLS_UNIQUE,
 GNUTLS_CB_TLS_SERVER_END_POINT,
 GNUTLS_CB_TLS_EXPORTER
} gnutls_channel_binding_t;
typedef enum {
 GNUTLS_GOST_PARAMSET_UNKNOWN = 0,
 GNUTLS_GOST_PARAMSET_TC26_Z,
 GNUTLS_GOST_PARAMSET_CP_A,
 GNUTLS_GOST_PARAMSET_CP_B,
 GNUTLS_GOST_PARAMSET_CP_C,
 GNUTLS_GOST_PARAMSET_CP_D
} gnutls_gost_paramset_t;
typedef enum {
 GNUTLS_CTYPE_CLIENT,
 GNUTLS_CTYPE_SERVER,
 GNUTLS_CTYPE_OURS,
 GNUTLS_CTYPE_PEERS
} gnutls_ctype_target_t;




typedef void *gnutls_transport_ptr_t;

struct gnutls_session_int;
typedef struct gnutls_session_int *gnutls_session_t;

struct gnutls_dh_params_int;
typedef struct gnutls_dh_params_int *gnutls_dh_params_t;


struct gnutls_x509_privkey_int;
typedef struct gnutls_x509_privkey_int *gnutls_rsa_params_t;

struct gnutls_priority_st;
typedef struct gnutls_priority_st *gnutls_priority_t;

typedef struct {
 unsigned char *data;
 unsigned int size;
} gnutls_datum_t;

typedef struct gnutls_library_config_st {
 const char *name;
 const char *value;
} gnutls_library_config_st;


typedef struct gnutls_params_st {
 gnutls_params_type_t type;
 union params {
  gnutls_dh_params_t dh;
  gnutls_rsa_params_t rsa_export;
 } params;
 int deinit;
} gnutls_params_st;

typedef int gnutls_params_function(gnutls_session_t, gnutls_params_type_t,
       gnutls_params_st *);



int gnutls_init(gnutls_session_t * session, unsigned int flags);
void gnutls_deinit(gnutls_session_t session);


int gnutls_bye(gnutls_session_t session, gnutls_close_request_t how);

int gnutls_handshake(gnutls_session_t session);

int gnutls_reauth(gnutls_session_t session, unsigned int flags);



void gnutls_handshake_set_timeout(gnutls_session_t session,
      unsigned int ms);
int gnutls_rehandshake(gnutls_session_t session);


int gnutls_session_key_update(gnutls_session_t session, unsigned flags);

gnutls_alert_description_t gnutls_alert_get(gnutls_session_t session);
int gnutls_alert_send(gnutls_session_t session,
        gnutls_alert_level_t level,
        gnutls_alert_description_t desc);
int gnutls_alert_send_appropriate(gnutls_session_t session, int err);
const char *gnutls_alert_get_name(gnutls_alert_description_t alert);
const char *gnutls_alert_get_strname(gnutls_alert_description_t alert);

gnutls_sec_param_t gnutls_pk_bits_to_sec_param(gnutls_pk_algorithm_t algo,
            unsigned int bits);
const char *gnutls_sec_param_get_name(gnutls_sec_param_t param);
unsigned int gnutls_sec_param_to_pk_bits(gnutls_pk_algorithm_t algo,
      gnutls_sec_param_t param);
unsigned int
 gnutls_sec_param_to_symmetric_bits(gnutls_sec_param_t param) __attribute__((const));


const char *
 gnutls_ecc_curve_get_name(gnutls_ecc_curve_t curve) __attribute__((const));
const char *
 gnutls_ecc_curve_get_oid(gnutls_ecc_curve_t curve) __attribute__((const));

const char *
 gnutls_group_get_name(gnutls_group_t group) __attribute__((const));

int
 gnutls_ecc_curve_get_size(gnutls_ecc_curve_t curve) __attribute__((const));
gnutls_ecc_curve_t gnutls_ecc_curve_get(gnutls_session_t session);

gnutls_group_t gnutls_group_get(gnutls_session_t session);


gnutls_cipher_algorithm_t gnutls_cipher_get(gnutls_session_t session);
gnutls_cipher_algorithm_t gnutls_early_cipher_get(gnutls_session_t session);
gnutls_kx_algorithm_t gnutls_kx_get(gnutls_session_t session);
gnutls_mac_algorithm_t gnutls_mac_get(gnutls_session_t session);
gnutls_digest_algorithm_t gnutls_prf_hash_get(const gnutls_session_t session);
gnutls_digest_algorithm_t
gnutls_early_prf_hash_get(const gnutls_session_t session);
gnutls_certificate_type_t
gnutls_certificate_type_get(gnutls_session_t session);
gnutls_certificate_type_t
gnutls_certificate_type_get2(gnutls_session_t session,
        gnutls_ctype_target_t target);

int gnutls_sign_algorithm_get(gnutls_session_t session);
int gnutls_sign_algorithm_get_client(gnutls_session_t session);

int gnutls_sign_algorithm_get_requested(gnutls_session_t session,
     size_t indx,
     gnutls_sign_algorithm_t * algo);


const char *
 gnutls_cipher_get_name(gnutls_cipher_algorithm_t algorithm) __attribute__((const));
const char *
 gnutls_mac_get_name(gnutls_mac_algorithm_t algorithm) __attribute__((const));

const char *
 gnutls_digest_get_name(gnutls_digest_algorithm_t algorithm) __attribute__((const));
const char *
 gnutls_digest_get_oid(gnutls_digest_algorithm_t algorithm) __attribute__((const));

const char *
 gnutls_kx_get_name(gnutls_kx_algorithm_t algorithm) __attribute__((const));
const char *
 gnutls_certificate_type_get_name(gnutls_certificate_type_t
          type) __attribute__((const));
const char *
 gnutls_pk_get_name(gnutls_pk_algorithm_t algorithm) __attribute__((const));
const char *
 gnutls_pk_get_oid(gnutls_pk_algorithm_t algorithm) __attribute__((const));

const char *
 gnutls_sign_get_name(gnutls_sign_algorithm_t algorithm) __attribute__((const));

const char *gnutls_sign_get_oid(gnutls_sign_algorithm_t sign) __attribute__((const));

const char *
 gnutls_gost_paramset_get_name(gnutls_gost_paramset_t param) __attribute__((const));
const char *
 gnutls_gost_paramset_get_oid(gnutls_gost_paramset_t param) __attribute__((const));

size_t
 gnutls_cipher_get_key_size(gnutls_cipher_algorithm_t algorithm) __attribute__((const));
size_t
 gnutls_mac_get_key_size(gnutls_mac_algorithm_t algorithm) __attribute__((const));

unsigned gnutls_sign_is_secure(gnutls_sign_algorithm_t algorithm) __attribute__((const));






unsigned gnutls_sign_is_secure2(gnutls_sign_algorithm_t algorithm, unsigned int flags) __attribute__((const));

gnutls_digest_algorithm_t
 gnutls_sign_get_hash_algorithm(gnutls_sign_algorithm_t sign) __attribute__((const));
gnutls_pk_algorithm_t
 gnutls_sign_get_pk_algorithm(gnutls_sign_algorithm_t sign) __attribute__((const));
gnutls_sign_algorithm_t
 gnutls_pk_to_sign(gnutls_pk_algorithm_t pk,
    gnutls_digest_algorithm_t hash) __attribute__((const));

unsigned
gnutls_sign_supports_pk_algorithm(gnutls_sign_algorithm_t sign, gnutls_pk_algorithm_t pk) __attribute__((const));



gnutls_mac_algorithm_t gnutls_mac_get_id(const char *name) __attribute__((const));
gnutls_digest_algorithm_t gnutls_digest_get_id(const char *name) __attribute__((const));

gnutls_cipher_algorithm_t
 gnutls_cipher_get_id(const char *name) __attribute__((const));

gnutls_kx_algorithm_t
 gnutls_kx_get_id(const char *name) __attribute__((const));
gnutls_protocol_t
 gnutls_protocol_get_id(const char *name) __attribute__((const));
gnutls_certificate_type_t
 gnutls_certificate_type_get_id(const char *name) __attribute__((const));
gnutls_pk_algorithm_t
 gnutls_pk_get_id(const char *name) __attribute__((const));
gnutls_sign_algorithm_t
 gnutls_sign_get_id(const char *name) __attribute__((const));
gnutls_ecc_curve_t gnutls_ecc_curve_get_id(const char *name) __attribute__((const));
gnutls_pk_algorithm_t gnutls_ecc_curve_get_pk(gnutls_ecc_curve_t curve) __attribute__((const));
gnutls_group_t gnutls_group_get_id(const char *name);

gnutls_digest_algorithm_t
 gnutls_oid_to_digest(const char *oid) __attribute__((const));
gnutls_mac_algorithm_t
 gnutls_oid_to_mac(const char *oid) __attribute__((const));
gnutls_pk_algorithm_t
 gnutls_oid_to_pk(const char *oid) __attribute__((const));
gnutls_sign_algorithm_t
 gnutls_oid_to_sign(const char *oid) __attribute__((const));
gnutls_ecc_curve_t
 gnutls_oid_to_ecc_curve(const char *oid) __attribute__((const));
gnutls_gost_paramset_t
 gnutls_oid_to_gost_paramset(const char *oid) __attribute__((const));


const gnutls_ecc_curve_t *
 gnutls_ecc_curve_list(void) __attribute__((pure));
const gnutls_group_t *
 gnutls_group_list(void) __attribute__((pure));
const gnutls_cipher_algorithm_t *
 gnutls_cipher_list(void) __attribute__((pure));
const gnutls_mac_algorithm_t *
 gnutls_mac_list(void) __attribute__((pure));
const gnutls_digest_algorithm_t *
 gnutls_digest_list(void) __attribute__((pure));
const gnutls_protocol_t *
 gnutls_protocol_list(void) __attribute__((pure));
const gnutls_certificate_type_t *
 gnutls_certificate_type_list(void) __attribute__((pure));
const gnutls_kx_algorithm_t *
 gnutls_kx_list(void) __attribute__((pure));
const gnutls_pk_algorithm_t *
 gnutls_pk_list(void) __attribute__((pure));
const gnutls_sign_algorithm_t *
 gnutls_sign_list(void) __attribute__((pure));
const char *
 gnutls_cipher_suite_info(size_t idx,
            unsigned char *cs_id,
     gnutls_kx_algorithm_t * kx,
     gnutls_cipher_algorithm_t * cipher,
     gnutls_mac_algorithm_t * mac,
     gnutls_protocol_t * min_version);


int gnutls_ecc_curve_set_enabled(gnutls_ecc_curve_t curve,
     unsigned int enabled);
int gnutls_sign_set_secure(gnutls_sign_algorithm_t sign, unsigned int secure);
int gnutls_sign_set_secure_for_certs(gnutls_sign_algorithm_t sign,
         unsigned int secure);
int gnutls_digest_set_secure(gnutls_digest_algorithm_t dig,
        unsigned int secure);
int gnutls_protocol_set_enabled(gnutls_protocol_t version,
    unsigned int enabled);


int gnutls_error_is_fatal(int error) __attribute__((const));
int gnutls_error_to_alert(int err, int *level);

void gnutls_perror(int error);
const char * gnutls_strerror(int error) __attribute__((const));
const char * gnutls_strerror_name(int error) __attribute__((const));



void gnutls_handshake_set_private_extensions(gnutls_session_t session,
          int allow);
int gnutls_handshake_set_random(gnutls_session_t session,
    const gnutls_datum_t * random);

gnutls_handshake_description_t
gnutls_handshake_get_last_out(gnutls_session_t session);
gnutls_handshake_description_t
gnutls_handshake_get_last_in(gnutls_session_t session);




int gnutls_heartbeat_ping(gnutls_session_t session, size_t data_size,
     unsigned int max_tries, unsigned int flags);
int gnutls_heartbeat_pong(gnutls_session_t session, unsigned int flags);

void gnutls_record_set_timeout(gnutls_session_t session, unsigned int ms);
void gnutls_record_disable_padding(gnutls_session_t session);

void gnutls_record_cork(gnutls_session_t session);

int gnutls_record_uncork(gnutls_session_t session, unsigned int flags);
size_t gnutls_record_discard_queued(gnutls_session_t session);

int
gnutls_record_get_state(gnutls_session_t session,
   unsigned read,
   gnutls_datum_t *mac_key,
   gnutls_datum_t *IV,
   gnutls_datum_t *cipher_key,
   unsigned char seq_number[8]);

int
gnutls_record_set_state(gnutls_session_t session,
   unsigned read,
   const unsigned char seq_number[8]);

typedef struct {
 size_t low;
 size_t high;
} gnutls_range_st;

int gnutls_range_split(gnutls_session_t session,
         const gnutls_range_st * orig,
         gnutls_range_st * small_range,
         gnutls_range_st * rem_range);

ssize_t gnutls_record_send(gnutls_session_t session, const void *data,
      size_t data_size);
ssize_t gnutls_record_send2(gnutls_session_t session, const void *data,
       size_t data_size, size_t pad, unsigned flags);
ssize_t gnutls_record_send_range(gnutls_session_t session,
     const void *data, size_t data_size,
     const gnutls_range_st * range);
ssize_t gnutls_record_send_file(gnutls_session_t session, int fd,
  off_t *offset, size_t count);
ssize_t gnutls_record_recv(gnutls_session_t session, void *data,
      size_t data_size);

typedef struct mbuffer_st *gnutls_packet_t;

ssize_t
gnutls_record_recv_packet(gnutls_session_t session,
     gnutls_packet_t *packet);

void gnutls_packet_get(gnutls_packet_t packet, gnutls_datum_t *data, unsigned char *sequence);
void gnutls_packet_deinit(gnutls_packet_t packet);



ssize_t gnutls_record_recv_seq(gnutls_session_t session, void *data,
          size_t data_size, unsigned char *seq);

size_t gnutls_record_overhead_size(gnutls_session_t session);

size_t
 gnutls_est_record_overhead_size(gnutls_protocol_t version,
            gnutls_cipher_algorithm_t cipher,
            gnutls_mac_algorithm_t mac,
            gnutls_compression_method_t comp,
            unsigned int flags) __attribute__((const));

void gnutls_session_enable_compatibility_mode(gnutls_session_t session);


unsigned gnutls_record_can_use_length_hiding(gnutls_session_t session);

int gnutls_record_get_direction(gnutls_session_t session);

size_t gnutls_record_get_max_size(gnutls_session_t session);
ssize_t gnutls_record_set_max_size(gnutls_session_t session, size_t size);
ssize_t gnutls_record_set_max_recv_size(gnutls_session_t session, size_t size);

size_t gnutls_record_check_pending(gnutls_session_t session);
size_t gnutls_record_check_corked(gnutls_session_t session);

size_t gnutls_record_get_max_early_data_size(gnutls_session_t session);
int gnutls_record_set_max_early_data_size(gnutls_session_t session, size_t size);
ssize_t gnutls_record_send_early_data(gnutls_session_t session,
          const void *data,
          size_t length);
ssize_t gnutls_record_recv_early_data(gnutls_session_t session,
          void *data,
          size_t data_size);

void gnutls_session_force_valid(gnutls_session_t session);

int gnutls_prf(gnutls_session_t session,
        size_t label_size, const char *label,
        int server_random_first,
        size_t extra_size, const char *extra,
        size_t outsize, char *out);
int gnutls_prf_rfc5705(gnutls_session_t session,
        size_t label_size, const char *label,
        size_t context_size, const char *context,
        size_t outsize, char *out);
int gnutls_prf_early(gnutls_session_t session,
       size_t label_size, const char *label,
       size_t context_size, const char *context,
       size_t outsize, char *out);

int gnutls_prf_raw(gnutls_session_t session,
     size_t label_size, const char *label,
     size_t seed_size, const char *seed,
     size_t outsize, char *out);







typedef enum {
 GNUTLS_NAME_DNS = 1
} gnutls_server_name_type_t;

int gnutls_server_name_set(gnutls_session_t session,
      gnutls_server_name_type_t type,
      const void *name, size_t name_length);

int gnutls_server_name_get(gnutls_session_t session,
      void *data, size_t * data_length,
      unsigned int *type, unsigned int indx);

unsigned int gnutls_heartbeat_get_timeout(gnutls_session_t session);
void gnutls_heartbeat_set_timeouts(gnutls_session_t session,
       unsigned int retrans_timeout,
       unsigned int total_timeout);





void gnutls_heartbeat_enable(gnutls_session_t session, unsigned int type);


unsigned gnutls_heartbeat_allowed(gnutls_session_t session, unsigned int type);


unsigned gnutls_safe_renegotiation_status(gnutls_session_t session);
unsigned gnutls_session_ext_master_secret_status(gnutls_session_t session);
unsigned gnutls_session_etm_status(gnutls_session_t session);
typedef enum {
 GNUTLS_SFLAGS_SAFE_RENEGOTIATION = 1,
 GNUTLS_SFLAGS_EXT_MASTER_SECRET = 1<<1,
 GNUTLS_SFLAGS_ETM = 1<<2,
 GNUTLS_SFLAGS_HB_LOCAL_SEND = 1<<3,
 GNUTLS_SFLAGS_HB_PEER_SEND = 1<<4,
 GNUTLS_SFLAGS_FALSE_START = 1<<5,
 GNUTLS_SFLAGS_RFC7919 = 1<<6,
 GNUTLS_SFLAGS_SESSION_TICKET = 1<<7,
 GNUTLS_SFLAGS_POST_HANDSHAKE_AUTH = 1<<8,
 GNUTLS_SFLAGS_EARLY_START = 1<<9,
 GNUTLS_SFLAGS_EARLY_DATA = 1<<10,
 GNUTLS_SFLAGS_CLI_REQUESTED_OCSP = 1<<11,
 GNUTLS_SFLAGS_SERV_REQUESTED_OCSP = 1<<12
} gnutls_session_flags_t;

unsigned gnutls_session_get_flags(gnutls_session_t session);







typedef enum {
 GNUTLS_SUPPLEMENTAL_UNKNOWN = 0,
} gnutls_supplemental_data_format_type_t;

const char
*gnutls_supplemental_get_name(gnutls_supplemental_data_format_type_t type);


int gnutls_session_ticket_key_generate(gnutls_datum_t * key);
int gnutls_session_ticket_enable_client(gnutls_session_t session);
int gnutls_session_ticket_enable_server(gnutls_session_t session,
     const gnutls_datum_t * key);

int gnutls_session_ticket_send(gnutls_session_t session, unsigned nr, unsigned flags);
typedef enum {
 GNUTLS_SRTP_AES128_CM_HMAC_SHA1_80 = 0x0001,
 GNUTLS_SRTP_AES128_CM_HMAC_SHA1_32 = 0x0002,
 GNUTLS_SRTP_NULL_HMAC_SHA1_80 = 0x0005,
 GNUTLS_SRTP_NULL_HMAC_SHA1_32 = 0x0006
} gnutls_srtp_profile_t;

int gnutls_srtp_set_profile(gnutls_session_t session,
       gnutls_srtp_profile_t profile);
int gnutls_srtp_set_profile_direct(gnutls_session_t session,
       const char *profiles,
       const char **err_pos);
int gnutls_srtp_get_selected_profile(gnutls_session_t session,
         gnutls_srtp_profile_t * profile);

const char *gnutls_srtp_get_profile_name(gnutls_srtp_profile_t profile);
int gnutls_srtp_get_profile_id(const char *name,
          gnutls_srtp_profile_t * profile);
int gnutls_srtp_get_keys(gnutls_session_t session,
    void *key_material,
    unsigned int key_material_size,
    gnutls_datum_t * client_key,
    gnutls_datum_t * client_salt,
    gnutls_datum_t * server_key,
    gnutls_datum_t * server_salt);

int gnutls_srtp_set_mki(gnutls_session_t session,
   const gnutls_datum_t * mki);
int gnutls_srtp_get_mki(gnutls_session_t session, gnutls_datum_t * mki);


gnutls_compression_method_t
gnutls_compress_certificate_get_selected_method(gnutls_session_t session);
int gnutls_compress_certificate_set_methods(gnutls_session_t session,
         const gnutls_compression_method_t * methods,
         size_t methods_len);
typedef enum {
 GNUTLS_ALPN_MANDATORY = 1,
 GNUTLS_ALPN_SERVER_PRECEDENCE = (1<<1)
} gnutls_alpn_flags_t;


int gnutls_alpn_get_selected_protocol(gnutls_session_t session,
          gnutls_datum_t * protocol);
int gnutls_alpn_set_protocols(gnutls_session_t session,
         const gnutls_datum_t * protocols,
         unsigned protocols_size, unsigned flags);

int gnutls_key_generate(gnutls_datum_t * key, unsigned int key_size);



int gnutls_priority_init(gnutls_priority_t * priority_cache,
    const char *priorities, const char **err_pos);
int gnutls_priority_init2(gnutls_priority_t * priority_cache,
     const char *priorities, const char **err_pos,
     unsigned flags);
void gnutls_priority_deinit(gnutls_priority_t priority_cache);
int gnutls_priority_get_cipher_suite_index(gnutls_priority_t pcache,
        unsigned int idx,
        unsigned int *sidx);



const char *
gnutls_priority_string_list(unsigned iter, unsigned int flags);

int gnutls_priority_set(gnutls_session_t session,
   gnutls_priority_t priority);

int gnutls_priority_set_direct(gnutls_session_t session,
          const char *priorities,
          const char **err_pos);

int gnutls_priority_certificate_type_list(gnutls_priority_t pcache,
       const unsigned int **list);
int gnutls_priority_certificate_type_list2(gnutls_priority_t pcache,
       const unsigned int **list,
       gnutls_ctype_target_t target);
int gnutls_priority_sign_list(gnutls_priority_t pcache,
         const unsigned int **list);
int gnutls_priority_protocol_list(gnutls_priority_t pcache,
      const unsigned int **list);
int gnutls_priority_ecc_curve_list(gnutls_priority_t pcache,
       const unsigned int **list);
int
gnutls_priority_group_list(gnutls_priority_t pcache,
      const unsigned int **list);

int gnutls_priority_kx_list(gnutls_priority_t pcache,
       const unsigned int **list);
int gnutls_priority_cipher_list(gnutls_priority_t pcache,
    const unsigned int **list);
int gnutls_priority_mac_list(gnutls_priority_t pcache,
        const unsigned int **list);

const char *gnutls_get_system_config_file(void);

int gnutls_set_default_priority(gnutls_session_t session);
int gnutls_set_default_priority_append(gnutls_session_t session,
           const char *add_prio,
           const char **err_pos,
           unsigned flags);


const char *
 gnutls_cipher_suite_get_name(gnutls_kx_algorithm_t kx_algorithm,
         gnutls_cipher_algorithm_t cipher_algorithm,
         gnutls_mac_algorithm_t mac_algorithm) __attribute__((const));

const char *
gnutls_ciphersuite_get(gnutls_session_t session) __attribute__((const));


gnutls_protocol_t gnutls_protocol_get_version(gnutls_session_t session);

const char *
 gnutls_protocol_get_name(gnutls_protocol_t version) __attribute__((const));




int gnutls_session_set_data(gnutls_session_t session,
       const void *session_data,
       size_t session_data_size);
int gnutls_session_get_data(gnutls_session_t session, void *session_data,
       size_t * session_data_size);
int gnutls_session_get_data2(gnutls_session_t session,
        gnutls_datum_t * data);
void gnutls_session_get_random(gnutls_session_t session,
          gnutls_datum_t * client,
          gnutls_datum_t * server);

void gnutls_session_get_master_secret(gnutls_session_t session,
                 gnutls_datum_t * secret);

char *gnutls_session_get_desc(gnutls_session_t session);

typedef int gnutls_certificate_verify_function(gnutls_session_t);
void gnutls_session_set_verify_function(gnutls_session_t session, gnutls_certificate_verify_function * func);
typedef enum {
 GNUTLS_DT_UNKNOWN = 0,
 GNUTLS_DT_DNS_HOSTNAME = 1,
 GNUTLS_DT_KEY_PURPOSE_OID = 2,
 GNUTLS_DT_RFC822NAME = 3,
 GNUTLS_DT_IP_ADDRESS = 4
} gnutls_vdata_types_t;

typedef struct {
 gnutls_vdata_types_t type;
 unsigned char *data;
 unsigned int size;
} gnutls_typed_vdata_st;

void gnutls_session_set_verify_cert(gnutls_session_t session,
          const char *hostname, unsigned flags);

void
gnutls_session_set_verify_cert2(gnutls_session_t session,
    gnutls_typed_vdata_st * data,
    unsigned elements, unsigned flags);

unsigned int gnutls_session_get_verify_cert_status(gnutls_session_t);

int gnutls_session_set_premaster(gnutls_session_t session,
     unsigned int entity,
     gnutls_protocol_t version,
     gnutls_kx_algorithm_t kx,
     gnutls_cipher_algorithm_t cipher,
     gnutls_mac_algorithm_t mac,
     gnutls_compression_method_t comp,
     const gnutls_datum_t * master,
     const gnutls_datum_t * session_id);



int gnutls_session_get_id(gnutls_session_t session, void *session_id,
     size_t * session_id_size);
int gnutls_session_get_id2(gnutls_session_t session,
      gnutls_datum_t * session_id);

int gnutls_session_set_id(gnutls_session_t session,
     const gnutls_datum_t * sid);

int gnutls_session_channel_binding(gnutls_session_t session,
       gnutls_channel_binding_t cbtype,
       gnutls_datum_t * cb);



int gnutls_session_is_resumed(gnutls_session_t session);
int gnutls_session_resumption_requested(gnutls_session_t session);

typedef int (*gnutls_db_store_func) (void *, gnutls_datum_t key,
         gnutls_datum_t data);
typedef int (*gnutls_db_remove_func) (void *, gnutls_datum_t key);
typedef gnutls_datum_t(*gnutls_db_retr_func) (void *, gnutls_datum_t key);

void gnutls_db_set_cache_expiration(gnutls_session_t session, int seconds);
unsigned gnutls_db_get_default_cache_expiration(void);

void gnutls_db_remove_session(gnutls_session_t session);
void gnutls_db_set_retrieve_function(gnutls_session_t session,
         gnutls_db_retr_func retr_func);
void gnutls_db_set_remove_function(gnutls_session_t session,
       gnutls_db_remove_func rem_func);
void gnutls_db_set_store_function(gnutls_session_t session,
      gnutls_db_store_func store_func);
void gnutls_db_set_ptr(gnutls_session_t session, void *ptr);
void *gnutls_db_get_ptr(gnutls_session_t session);
int gnutls_db_check_entry(gnutls_session_t session,
     gnutls_datum_t session_entry);
time_t gnutls_db_check_entry_time(gnutls_datum_t * entry);
time_t gnutls_db_check_entry_expire_time(gnutls_datum_t * entry);
typedef int (*gnutls_handshake_hook_func) (gnutls_session_t,
        unsigned int htype,
        unsigned when,
        unsigned int incoming,
        const gnutls_datum_t *msg);
void gnutls_handshake_set_hook_function(gnutls_session_t session,
     unsigned int htype, int when,
     gnutls_handshake_hook_func func);


typedef int (*gnutls_handshake_simple_hook_func) (gnutls_session_t);
void
gnutls_handshake_set_post_client_hello_function(gnutls_session_t session,
      gnutls_handshake_simple_hook_func func);

void gnutls_handshake_set_max_packet_length(gnutls_session_t session,
         size_t max);



const char * gnutls_check_version(const char *req_version) __attribute__((const));
void gnutls_credentials_clear(gnutls_session_t session);



int gnutls_credentials_set(gnutls_session_t session,
      gnutls_credentials_type_t type, void *cred);
int gnutls_credentials_get(gnutls_session_t session,
      gnutls_credentials_type_t type, void **cred);




struct gnutls_pubkey_st;
typedef struct gnutls_pubkey_st *gnutls_pubkey_t;

struct gnutls_privkey_st;
typedef struct gnutls_privkey_st *gnutls_privkey_t;

struct gnutls_x509_privkey_int;
typedef struct gnutls_x509_privkey_int *gnutls_x509_privkey_t;

struct gnutls_x509_crl_int;
typedef struct gnutls_x509_crl_int *gnutls_x509_crl_t;

struct gnutls_x509_crt_int;
typedef struct gnutls_x509_crt_int *gnutls_x509_crt_t;

struct gnutls_x509_crq_int;
typedef struct gnutls_x509_crq_int *gnutls_x509_crq_t;

struct gnutls_openpgp_keyring_int;
typedef struct gnutls_openpgp_keyring_int *gnutls_openpgp_keyring_t;




struct gnutls_certificate_credentials_st;
typedef struct gnutls_certificate_credentials_st
*gnutls_certificate_credentials_t;
typedef gnutls_certificate_credentials_t
    gnutls_certificate_server_credentials;
typedef gnutls_certificate_credentials_t
    gnutls_certificate_client_credentials;

typedef struct gnutls_anon_server_credentials_st
*gnutls_anon_server_credentials_t;
typedef struct gnutls_anon_client_credentials_st
*gnutls_anon_client_credentials_t;

void gnutls_anon_free_server_credentials(gnutls_anon_server_credentials_t
      sc);
int
gnutls_anon_allocate_server_credentials(gnutls_anon_server_credentials_t
     * sc);

void gnutls_anon_set_server_dh_params(gnutls_anon_server_credentials_t res,
          gnutls_dh_params_t dh_params);

int
gnutls_anon_set_server_known_dh_params(gnutls_anon_server_credentials_t res,
     gnutls_sec_param_t sec_param);

void
gnutls_anon_set_server_params_function(gnutls_anon_server_credentials_t
           res, gnutls_params_function * func);

void
gnutls_anon_free_client_credentials(gnutls_anon_client_credentials_t sc);
int
gnutls_anon_allocate_client_credentials(gnutls_anon_client_credentials_t
     * sc);




void
gnutls_certificate_free_credentials(gnutls_certificate_credentials_t sc);
int
gnutls_certificate_allocate_credentials(gnutls_certificate_credentials_t
     * res);

int
gnutls_certificate_get_issuer(gnutls_certificate_credentials_t sc,
         gnutls_x509_crt_t cert,
         gnutls_x509_crt_t * issuer,
         unsigned int flags);

int gnutls_certificate_get_crt_raw(gnutls_certificate_credentials_t sc,
       unsigned idx1, unsigned idx2,
       gnutls_datum_t * cert);

void gnutls_certificate_free_keys(gnutls_certificate_credentials_t sc);
void gnutls_certificate_free_cas(gnutls_certificate_credentials_t sc);
void gnutls_certificate_free_ca_names(gnutls_certificate_credentials_t sc);
void gnutls_certificate_free_crls(gnutls_certificate_credentials_t sc);

void gnutls_certificate_set_dh_params(gnutls_certificate_credentials_t res,
          gnutls_dh_params_t dh_params);

int gnutls_certificate_set_known_dh_params(gnutls_certificate_credentials_t res,
        gnutls_sec_param_t sec_param);
void gnutls_certificate_set_verify_flags(gnutls_certificate_credentials_t
      res, unsigned int flags);
unsigned int
gnutls_certificate_get_verify_flags(gnutls_certificate_credentials_t res);
typedef enum gnutls_certificate_flags {
 GNUTLS_CERTIFICATE_SKIP_KEY_CERT_MATCH = 1,
 GNUTLS_CERTIFICATE_API_V2 = (1<<1),
 GNUTLS_CERTIFICATE_SKIP_OCSP_RESPONSE_CHECK = (1<<2),
 GNUTLS_CERTIFICATE_VERIFY_CRLS = (1<<3)
} gnutls_certificate_flags;

void gnutls_certificate_set_flags(gnutls_certificate_credentials_t,
      unsigned flags);

void gnutls_certificate_set_verify_limits(gnutls_certificate_credentials_t
       res, unsigned int max_bits,
       unsigned int max_depth);

int
gnutls_certificate_set_x509_system_trust(gnutls_certificate_credentials_t
      cred);

int
gnutls_certificate_set_x509_trust_file(gnutls_certificate_credentials_t
           cred, const char *cafile,
           gnutls_x509_crt_fmt_t type);
int
gnutls_certificate_set_x509_trust_dir(gnutls_certificate_credentials_t cred,
          const char *ca_dir,
          gnutls_x509_crt_fmt_t type);

int gnutls_certificate_set_x509_trust_mem(gnutls_certificate_credentials_t
       res, const gnutls_datum_t * ca,
       gnutls_x509_crt_fmt_t type);

int
gnutls_certificate_set_x509_crl_file(gnutls_certificate_credentials_t
         res, const char *crlfile,
         gnutls_x509_crt_fmt_t type);
int gnutls_certificate_set_x509_crl_mem(gnutls_certificate_credentials_t
     res, const gnutls_datum_t * CRL,
     gnutls_x509_crt_fmt_t type);

int
gnutls_certificate_set_x509_key_file(gnutls_certificate_credentials_t
         res, const char *certfile,
         const char *keyfile,
         gnutls_x509_crt_fmt_t type);

int
gnutls_certificate_set_x509_key_file2(gnutls_certificate_credentials_t
          res, const char *certfile,
          const char *keyfile,
          gnutls_x509_crt_fmt_t type,
          const char *pass,
          unsigned int flags);

int gnutls_certificate_set_x509_key_mem(gnutls_certificate_credentials_t
     res, const gnutls_datum_t * cert,
     const gnutls_datum_t * key,
     gnutls_x509_crt_fmt_t type);

int gnutls_certificate_set_x509_key_mem2(gnutls_certificate_credentials_t
      res, const gnutls_datum_t * cert,
      const gnutls_datum_t * key,
      gnutls_x509_crt_fmt_t type,
      const char *pass,
      unsigned int flags);

void gnutls_certificate_send_x509_rdn_sequence(gnutls_session_t session,
            int status);

int
gnutls_certificate_set_x509_simple_pkcs12_file
(gnutls_certificate_credentials_t res, const char *pkcs12file,
 gnutls_x509_crt_fmt_t type, const char *password);
int
gnutls_certificate_set_x509_simple_pkcs12_mem
(gnutls_certificate_credentials_t res, const gnutls_datum_t * p12blob,
 gnutls_x509_crt_fmt_t type, const char *password);




int gnutls_certificate_set_x509_key(gnutls_certificate_credentials_t res,
        gnutls_x509_crt_t * cert_list,
        int cert_list_size,
        gnutls_x509_privkey_t key);
int gnutls_certificate_set_x509_trust(gnutls_certificate_credentials_t res,
          gnutls_x509_crt_t * ca_list,
          int ca_list_size);
int gnutls_certificate_set_x509_crl(gnutls_certificate_credentials_t res,
        gnutls_x509_crl_t * crl_list,
        int crl_list_size);

int gnutls_certificate_get_x509_key(gnutls_certificate_credentials_t res,
                                    unsigned index,
                                    gnutls_x509_privkey_t *key);
int gnutls_certificate_get_x509_crt(gnutls_certificate_credentials_t res,
                                    unsigned index,
                                    gnutls_x509_crt_t **crt_list,
                                    unsigned *crt_list_size);


typedef int (*gnutls_status_request_ocsp_func)
 (gnutls_session_t session, void *ptr, gnutls_datum_t *ocsp_response);

void
gnutls_certificate_set_ocsp_status_request_function
(gnutls_certificate_credentials_t res,
gnutls_status_request_ocsp_func ocsp_func, void *ptr);

int
gnutls_certificate_set_ocsp_status_request_function2
(gnutls_certificate_credentials_t res, unsigned idx,
gnutls_status_request_ocsp_func ocsp_func, void *ptr);

int
gnutls_certificate_set_ocsp_status_request_file
(gnutls_certificate_credentials_t res, const char *response_file,
 unsigned idx);

int
gnutls_certificate_set_ocsp_status_request_file2
(gnutls_certificate_credentials_t res, const char *response_file,
 unsigned idx, gnutls_x509_crt_fmt_t fmt);

int
gnutls_certificate_set_ocsp_status_request_mem
(gnutls_certificate_credentials_t res, const gnutls_datum_t *resp,
 unsigned idx, gnutls_x509_crt_fmt_t fmt);

typedef struct gnutls_ocsp_data_st {
 unsigned int version;
 gnutls_datum_t response;
 time_t exptime;
 unsigned char padding[32];
} gnutls_ocsp_data_st;

time_t
gnutls_certificate_get_ocsp_expiration(gnutls_certificate_credentials_t sc,
           unsigned idx,
           int oidx,
           unsigned flags);

int gnutls_ocsp_status_request_enable_client(gnutls_session_t session,
          gnutls_datum_t * responder_id,
          size_t responder_id_size,
          gnutls_datum_t *
          request_extensions);

int gnutls_ocsp_status_request_get(gnutls_session_t session,
       gnutls_datum_t * response);


unsigned gnutls_ocsp_status_request_is_checked(gnutls_session_t session,
            unsigned int flags);

int
gnutls_ocsp_status_request_get2(gnutls_session_t session,
           unsigned idx,
           gnutls_datum_t * response);


int gnutls_certificate_set_rawpk_key_mem(gnutls_certificate_credentials_t cred,
        const gnutls_datum_t* spki,
        const gnutls_datum_t* pkey,
        gnutls_x509_crt_fmt_t format,
        const char* pass,
        unsigned int key_usage,
        const char **names,
        unsigned int names_length,
        unsigned int flags);

int gnutls_certificate_set_rawpk_key_file(gnutls_certificate_credentials_t cred,
          const char* rawpkfile,
          const char* privkeyfile,
          gnutls_x509_crt_fmt_t format,
          const char *pass,
          unsigned int key_usage,
          const char **names,
          unsigned int names_length,
          unsigned int privkey_flags,
          unsigned int pkcs11_flags);




int gnutls_global_init(void);
void gnutls_global_deinit(void);

const gnutls_library_config_st *gnutls_get_library_config(void);
typedef time_t(*gnutls_time_func) (time_t * t);

typedef int (*mutex_init_func) (void **mutex);
typedef int (*mutex_lock_func) (void **mutex);
typedef int (*mutex_unlock_func) (void **mutex);
typedef int (*mutex_deinit_func) (void **mutex);

void gnutls_global_set_mutex(mutex_init_func init,
        mutex_deinit_func deinit,
        mutex_lock_func lock,
        mutex_unlock_func unlock);

typedef void *(*gnutls_alloc_function) (size_t);
typedef void *(*gnutls_calloc_function) (size_t, size_t);
typedef int (*gnutls_is_secure_function) (const void *);
typedef void (*gnutls_free_function) (void *);
typedef void *(*gnutls_realloc_function) (void *, size_t);

void gnutls_global_set_time_function(gnutls_time_func time_func);


extern gnutls_alloc_function gnutls_malloc;
extern gnutls_realloc_function gnutls_realloc;
extern gnutls_calloc_function gnutls_calloc;
extern gnutls_free_function gnutls_free;





extern char *(*gnutls_strdup) (const char *);


void gnutls_memset(void *data, int c, size_t size);


int gnutls_memcmp(const void *s1, const void *s2, size_t n);

typedef void (*gnutls_log_func) (int, const char *);
typedef void (*gnutls_audit_log_func) (gnutls_session_t, const char *);
void gnutls_global_set_log_function(gnutls_log_func log_func);
void gnutls_global_set_audit_log_function(gnutls_audit_log_func log_func);
void gnutls_global_set_log_level(int level);
typedef int (*gnutls_keylog_func) (gnutls_session_t session,
       const char *label,
       const gnutls_datum_t *secret);
gnutls_keylog_func gnutls_session_get_keylog_function(const gnutls_session_t session);
void gnutls_session_set_keylog_function(gnutls_session_t session,
     gnutls_keylog_func func);



int gnutls_dh_params_init(gnutls_dh_params_t * dh_params);
void gnutls_dh_params_deinit(gnutls_dh_params_t dh_params);
int gnutls_dh_params_import_raw(gnutls_dh_params_t dh_params,
    const gnutls_datum_t * prime,
    const gnutls_datum_t * generator);
int gnutls_dh_params_import_dsa(gnutls_dh_params_t dh_params, gnutls_x509_privkey_t key);
int gnutls_dh_params_import_raw2(gnutls_dh_params_t dh_params,
     const gnutls_datum_t * prime,
     const gnutls_datum_t * generator,
     unsigned key_bits);
int gnutls_dh_params_import_raw3(gnutls_dh_params_t dh_params,
     const gnutls_datum_t * prime,
     const gnutls_datum_t * q,
     const gnutls_datum_t * generator);
int gnutls_dh_params_import_pkcs3(gnutls_dh_params_t params,
      const gnutls_datum_t * pkcs3_params,
      gnutls_x509_crt_fmt_t format);
int gnutls_dh_params_generate2(gnutls_dh_params_t params,
          unsigned int bits);
int gnutls_dh_params_export_pkcs3(gnutls_dh_params_t params,
      gnutls_x509_crt_fmt_t format,
      unsigned char *params_data,
      size_t * params_data_size);
int gnutls_dh_params_export2_pkcs3(gnutls_dh_params_t params,
       gnutls_x509_crt_fmt_t format,
       gnutls_datum_t * out);
int gnutls_dh_params_export_raw(gnutls_dh_params_t params,
    gnutls_datum_t * prime,
    gnutls_datum_t * generator,
    unsigned int *bits);
int gnutls_dh_params_cpy(gnutls_dh_params_t dst, gnutls_dh_params_t src);





       
       


       

typedef struct iovec giovec_t;

typedef ssize_t(*gnutls_pull_func) (gnutls_transport_ptr_t, void *,
        size_t);
typedef ssize_t(*gnutls_push_func) (gnutls_transport_ptr_t, const void *,
        size_t);

int gnutls_system_recv_timeout(gnutls_transport_ptr_t ptr, unsigned int ms);
typedef int (*gnutls_pull_timeout_func) (gnutls_transport_ptr_t,
      unsigned int ms);

typedef ssize_t(*gnutls_vec_push_func) (gnutls_transport_ptr_t,
     const giovec_t * iov, int iovcnt);

typedef int (*gnutls_errno_func) (gnutls_transport_ptr_t);






void gnutls_transport_set_int2(gnutls_session_t session, int r, int s);


void gnutls_transport_get_int2(gnutls_session_t session, int *r, int *s);
int gnutls_transport_get_int(gnutls_session_t session);

void gnutls_transport_set_ptr(gnutls_session_t session,
         gnutls_transport_ptr_t ptr);
void gnutls_transport_set_ptr2(gnutls_session_t session,
          gnutls_transport_ptr_t recv_ptr,
          gnutls_transport_ptr_t send_ptr);

gnutls_transport_ptr_t gnutls_transport_get_ptr(gnutls_session_t session);
void gnutls_transport_get_ptr2(gnutls_session_t session,
          gnutls_transport_ptr_t * recv_ptr,
          gnutls_transport_ptr_t * send_ptr);

void gnutls_transport_set_vec_push_function(gnutls_session_t session,
         gnutls_vec_push_func vec_func);
void gnutls_transport_set_push_function(gnutls_session_t session,
     gnutls_push_func push_func);
void gnutls_transport_set_pull_function(gnutls_session_t session,
     gnutls_pull_func pull_func);

void gnutls_transport_set_pull_timeout_function(gnutls_session_t session,
      gnutls_pull_timeout_func
      func);

void gnutls_transport_set_errno_function(gnutls_session_t session,
      gnutls_errno_func errno_func);

void gnutls_transport_set_errno(gnutls_session_t session, int err);



void gnutls_session_set_ptr(gnutls_session_t session, void *ptr);
void *gnutls_session_get_ptr(gnutls_session_t session);

void gnutls_openpgp_send_cert(gnutls_session_t session,
         gnutls_openpgp_crt_status_t status);



int gnutls_fingerprint(gnutls_digest_algorithm_t algo,
         const gnutls_datum_t * data, void *result,
         size_t * result_size);







typedef enum gnutls_random_art {
 GNUTLS_RANDOM_ART_OPENSSH = 1
} gnutls_random_art_t;

int gnutls_random_art(gnutls_random_art_t type,
        const char *key_type, unsigned int key_size,
        void *fpr, size_t fpr_size, gnutls_datum_t * art);



int gnutls_idna_map(const char * input, unsigned ilen, gnutls_datum_t *out, unsigned flags);
int gnutls_idna_reverse_map(const char *input, unsigned ilen, gnutls_datum_t *out, unsigned flags);




typedef struct gnutls_srp_server_credentials_st
*gnutls_srp_server_credentials_t;
typedef struct gnutls_srp_client_credentials_st
*gnutls_srp_client_credentials_t;

void
gnutls_srp_free_client_credentials(gnutls_srp_client_credentials_t sc);
int
gnutls_srp_allocate_client_credentials(gnutls_srp_client_credentials_t *
           sc);
int gnutls_srp_set_client_credentials(gnutls_srp_client_credentials_t res,
          const char *username,
          const char *password);

void
gnutls_srp_free_server_credentials(gnutls_srp_server_credentials_t sc);
int
gnutls_srp_allocate_server_credentials(gnutls_srp_server_credentials_t *
           sc);
int gnutls_srp_set_server_credentials_file(gnutls_srp_server_credentials_t
        res, const char *password_file,
        const char *password_conf_file);

const char *gnutls_srp_server_get_username(gnutls_session_t session);

void gnutls_srp_set_prime_bits(gnutls_session_t session,
                               unsigned int bits);

int gnutls_srp_verifier(const char *username,
   const char *password,
   const gnutls_datum_t * salt,
   const gnutls_datum_t * generator,
   const gnutls_datum_t * prime,
   gnutls_datum_t * res);




extern const gnutls_datum_t gnutls_srp_8192_group_prime;
extern const gnutls_datum_t gnutls_srp_8192_group_generator;

extern const gnutls_datum_t gnutls_srp_4096_group_prime;
extern const gnutls_datum_t gnutls_srp_4096_group_generator;

extern const gnutls_datum_t gnutls_srp_3072_group_prime;
extern const gnutls_datum_t gnutls_srp_3072_group_generator;

extern const gnutls_datum_t gnutls_srp_2048_group_prime;
extern const gnutls_datum_t gnutls_srp_2048_group_generator;

extern const gnutls_datum_t gnutls_srp_1536_group_prime;
extern const gnutls_datum_t gnutls_srp_1536_group_generator;

extern const gnutls_datum_t gnutls_srp_1024_group_prime;
extern const gnutls_datum_t gnutls_srp_1024_group_generator;




extern const gnutls_datum_t gnutls_ffdhe_8192_group_prime;
extern const gnutls_datum_t gnutls_ffdhe_8192_group_q;
extern const gnutls_datum_t gnutls_ffdhe_8192_group_generator;
extern const unsigned int gnutls_ffdhe_8192_key_bits;

extern const gnutls_datum_t gnutls_ffdhe_6144_group_prime;
extern const gnutls_datum_t gnutls_ffdhe_6144_group_q;
extern const gnutls_datum_t gnutls_ffdhe_6144_group_generator;
extern const unsigned int gnutls_ffdhe_6144_key_bits;

extern const gnutls_datum_t gnutls_ffdhe_4096_group_prime;
extern const gnutls_datum_t gnutls_ffdhe_4096_group_q;
extern const gnutls_datum_t gnutls_ffdhe_4096_group_generator;
extern const unsigned int gnutls_ffdhe_4096_key_bits;

extern const gnutls_datum_t gnutls_ffdhe_3072_group_prime;
extern const gnutls_datum_t gnutls_ffdhe_3072_group_q;
extern const gnutls_datum_t gnutls_ffdhe_3072_group_generator;
extern const unsigned int gnutls_ffdhe_3072_key_bits;

extern const gnutls_datum_t gnutls_ffdhe_2048_group_prime;
extern const gnutls_datum_t gnutls_ffdhe_2048_group_q;
extern const gnutls_datum_t gnutls_ffdhe_2048_group_generator;
extern const unsigned int gnutls_ffdhe_2048_key_bits;

typedef int gnutls_srp_server_credentials_function(gnutls_session_t,
         const char *username,
         gnutls_datum_t * salt,
         gnutls_datum_t *
         verifier,
         gnutls_datum_t *
         generator,
         gnutls_datum_t * prime);
void
gnutls_srp_set_server_credentials_function(gnutls_srp_server_credentials_t
        cred,
        gnutls_srp_server_credentials_function
        * func);

typedef int gnutls_srp_client_credentials_function(gnutls_session_t,
         char **, char **);
void
gnutls_srp_set_client_credentials_function(gnutls_srp_client_credentials_t
        cred,
        gnutls_srp_client_credentials_function
        * func);

int gnutls_srp_base64_encode(const gnutls_datum_t * data, char *result,
        size_t * result_size);
int gnutls_srp_base64_encode2(const gnutls_datum_t * data,
       gnutls_datum_t * result);

int gnutls_srp_base64_decode(const gnutls_datum_t * b64_data, char *result,
        size_t * result_size);
int gnutls_srp_base64_decode2(const gnutls_datum_t * b64_data,
       gnutls_datum_t * result);




void
gnutls_srp_set_server_fake_salt_seed(gnutls_srp_server_credentials_t
         sc,
         const gnutls_datum_t * seed,
         unsigned int salt_length);


typedef struct gnutls_psk_server_credentials_st
*gnutls_psk_server_credentials_t;
typedef struct gnutls_psk_client_credentials_st
*gnutls_psk_client_credentials_t;
typedef enum gnutls_psk_key_flags {
 GNUTLS_PSK_KEY_RAW = 0,
 GNUTLS_PSK_KEY_HEX
} gnutls_psk_key_flags;

void
gnutls_psk_free_client_credentials(gnutls_psk_client_credentials_t sc);
int
gnutls_psk_allocate_client_credentials(gnutls_psk_client_credentials_t *
           sc);
int gnutls_psk_set_client_credentials(gnutls_psk_client_credentials_t res,
          const char *username,
          const gnutls_datum_t * key,
          gnutls_psk_key_flags flags);
int gnutls_psk_set_client_credentials2(gnutls_psk_client_credentials_t res,
           const gnutls_datum_t *username,
           const gnutls_datum_t *key,
           gnutls_psk_key_flags flags);

void
gnutls_psk_free_server_credentials(gnutls_psk_server_credentials_t sc);
int
gnutls_psk_allocate_server_credentials(gnutls_psk_server_credentials_t *
           sc);
int gnutls_psk_set_server_credentials_file(gnutls_psk_server_credentials_t
        res, const char *password_file);

int
gnutls_psk_set_server_credentials_hint(gnutls_psk_server_credentials_t
           res, const char *hint);

const char *gnutls_psk_server_get_username(gnutls_session_t session);
int gnutls_psk_server_get_username2(gnutls_session_t session,
        gnutls_datum_t *out);
const char *gnutls_psk_client_get_hint(gnutls_session_t session);

typedef int gnutls_psk_server_credentials_function(gnutls_session_t,
         const char *username,
         gnutls_datum_t * key);
typedef int gnutls_psk_server_credentials_function2(gnutls_session_t,
          const gnutls_datum_t *username,
          gnutls_datum_t *key);
void
gnutls_psk_set_server_credentials_function(gnutls_psk_server_credentials_t
        cred,
        gnutls_psk_server_credentials_function
        * func);
void
gnutls_psk_set_server_credentials_function2(gnutls_psk_server_credentials_t cred,
         gnutls_psk_server_credentials_function2 *func);

typedef int gnutls_psk_client_credentials_function(gnutls_session_t,
         char **username,
         gnutls_datum_t * key);
typedef int gnutls_psk_client_credentials_function2(gnutls_session_t,
          gnutls_datum_t *username,
          gnutls_datum_t *key);
void
gnutls_psk_set_client_credentials_function(gnutls_psk_client_credentials_t
        cred,
        gnutls_psk_client_credentials_function
        * func);
void
gnutls_psk_set_client_credentials_function2(gnutls_psk_client_credentials_t cred,
         gnutls_psk_client_credentials_function2 *func);

int gnutls_hex_encode(const gnutls_datum_t * data, char *result,
        size_t * result_size);
int gnutls_hex_decode(const gnutls_datum_t * hex_data, void *result,
        size_t * result_size);

int gnutls_hex_encode2(const gnutls_datum_t * data, gnutls_datum_t *result);
int gnutls_hex_decode2(const gnutls_datum_t * data, gnutls_datum_t *result);

void
gnutls_psk_set_server_dh_params(gnutls_psk_server_credentials_t res,
    gnutls_dh_params_t dh_params);

int
gnutls_psk_set_server_known_dh_params(gnutls_psk_server_credentials_t res,
          gnutls_sec_param_t sec_param);

void
gnutls_psk_set_server_params_function(gnutls_psk_server_credentials_t
          res, gnutls_params_function * func);
typedef enum gnutls_x509_subject_alt_name_t {
 GNUTLS_SAN_DNSNAME = 1,
 GNUTLS_SAN_RFC822NAME = 2,
 GNUTLS_SAN_URI = 3,
 GNUTLS_SAN_IPADDRESS = 4,
 GNUTLS_SAN_OTHERNAME = 5,
 GNUTLS_SAN_DN = 6,
 GNUTLS_SAN_REGISTERED_ID = 7,
 GNUTLS_SAN_MAX = GNUTLS_SAN_REGISTERED_ID,



 GNUTLS_SAN_OTHERNAME_XMPP = 1000,
 GNUTLS_SAN_OTHERNAME_KRB5PRINCIPAL,
 GNUTLS_SAN_OTHERNAME_MSUSERPRINCIPAL
} gnutls_x509_subject_alt_name_t;

struct gnutls_openpgp_crt_int;
typedef struct gnutls_openpgp_crt_int *gnutls_openpgp_crt_t;

struct gnutls_openpgp_privkey_int;
typedef struct gnutls_openpgp_privkey_int *gnutls_openpgp_privkey_t;

struct gnutls_pkcs11_privkey_st;
typedef struct gnutls_pkcs11_privkey_st *gnutls_pkcs11_privkey_t;
typedef enum {
 GNUTLS_PRIVKEY_X509,
 GNUTLS_PRIVKEY_OPENPGP,
 GNUTLS_PRIVKEY_PKCS11,
 GNUTLS_PRIVKEY_EXT
} gnutls_privkey_type_t;

typedef struct gnutls_retr2_st {
 gnutls_certificate_type_t cert_type;
 gnutls_privkey_type_t key_type;

 union {
  gnutls_x509_crt_t *x509;
  gnutls_openpgp_crt_t pgp;
 } cert;
 unsigned int ncerts;

 union {
  gnutls_x509_privkey_t x509;
  gnutls_openpgp_privkey_t pgp;
  gnutls_pkcs11_privkey_t pkcs11;
 } key;

 unsigned int deinit_all;
} gnutls_retr2_st;





gnutls_credentials_type_t gnutls_auth_get_type(gnutls_session_t session);
gnutls_credentials_type_t
gnutls_auth_server_get_type(gnutls_session_t session);
gnutls_credentials_type_t
gnutls_auth_client_get_type(gnutls_session_t session);



void gnutls_dh_set_prime_bits(gnutls_session_t session, unsigned int bits);
int gnutls_dh_get_secret_bits(gnutls_session_t session);
int gnutls_dh_get_peers_public_bits(gnutls_session_t session);
int gnutls_dh_get_prime_bits(gnutls_session_t session);

int gnutls_dh_get_group(gnutls_session_t session, gnutls_datum_t * raw_gen,
   gnutls_datum_t * raw_prime);
int gnutls_dh_get_pubkey(gnutls_session_t session,
    gnutls_datum_t * raw_key);
typedef int gnutls_certificate_retrieve_function(gnutls_session_t,
       const
       gnutls_datum_t *
       req_ca_rdn,
       int nreqs,
       const
       gnutls_pk_algorithm_t
       * pk_algos,
       int
       pk_algos_length,
       gnutls_retr2_st *);


void
gnutls_certificate_set_retrieve_function(gnutls_certificate_credentials_t
      cred,
      gnutls_certificate_retrieve_function
      * func);

void
gnutls_certificate_set_verify_function(gnutls_certificate_credentials_t
           cred,
           gnutls_certificate_verify_function
           * func);

void
gnutls_certificate_server_set_request(gnutls_session_t session,
          gnutls_certificate_request_t req);



const gnutls_datum_t *gnutls_certificate_get_peers(gnutls_session_t
         session, unsigned int
         *list_size);
const gnutls_datum_t *gnutls_certificate_get_ours(gnutls_session_t
        session);

int gnutls_certificate_get_peers_subkey_id(gnutls_session_t session,
        gnutls_datum_t * id);

time_t gnutls_certificate_activation_time_peers(gnutls_session_t session);
time_t gnutls_certificate_expiration_time_peers(gnutls_session_t session);

unsigned gnutls_certificate_client_get_request_status(gnutls_session_t session);
int gnutls_certificate_verify_peers2(gnutls_session_t session,
         unsigned int *status);
int gnutls_certificate_verify_peers3(gnutls_session_t session,
         const char *hostname,
         unsigned int *status);

int
gnutls_certificate_verify_peers(gnutls_session_t session,
    gnutls_typed_vdata_st * data,
    unsigned int elements,
    unsigned int *status);

int gnutls_certificate_verification_status_print(unsigned int status,
       gnutls_certificate_type_t
       type,
       gnutls_datum_t * out,
       unsigned int flags);

int gnutls_pem_base64_encode(const char *msg, const gnutls_datum_t * data,
        char *result, size_t * result_size);
int gnutls_pem_base64_decode(const char *header,
        const gnutls_datum_t * b64_data,
        unsigned char *result, size_t * result_size);

int gnutls_pem_base64_encode2(const char *msg,
       const gnutls_datum_t * data,
       gnutls_datum_t * result);
int gnutls_pem_base64_decode2(const char *header,
       const gnutls_datum_t * b64_data,
       gnutls_datum_t * result);

int gnutls_base64_encode2(const gnutls_datum_t * data,
     gnutls_datum_t * result);
int gnutls_base64_decode2(const gnutls_datum_t * b64_data,
     gnutls_datum_t * result);
void
gnutls_certificate_set_params_function(gnutls_certificate_credentials_t
           res, gnutls_params_function * func);
void gnutls_anon_set_params_function(gnutls_anon_server_credentials_t res,
         gnutls_params_function * func);
void gnutls_psk_set_params_function(gnutls_psk_server_credentials_t res,
        gnutls_params_function * func);

int gnutls_hex2bin(const char *hex_data, size_t hex_size,
     void *bin_data, size_t * bin_size);





typedef int (*gnutls_tdb_store_func) (const char *db_name,
          const char *host,
          const char *service,
          time_t expiration,
          const gnutls_datum_t * pubkey);

typedef int (*gnutls_tdb_store_commitment_func) (const char *db_name,
       const char *host,
       const char *service,
       time_t expiration,
       gnutls_digest_algorithm_t
       hash_algo,
       const gnutls_datum_t *
       hash);



typedef int (*gnutls_tdb_verify_func) (const char *db_name,
           const char *host,
           const char *service,
           const gnutls_datum_t * pubkey);


struct gnutls_tdb_int;
typedef struct gnutls_tdb_int *gnutls_tdb_t;

int gnutls_tdb_init(gnutls_tdb_t * tdb);
void gnutls_tdb_set_store_func(gnutls_tdb_t tdb,
          gnutls_tdb_store_func store);
void gnutls_tdb_set_store_commitment_func(gnutls_tdb_t tdb,
       gnutls_tdb_store_commitment_func
       cstore);
void gnutls_tdb_set_verify_func(gnutls_tdb_t tdb,
    gnutls_tdb_verify_func verify);
void gnutls_tdb_deinit(gnutls_tdb_t tdb);

int gnutls_verify_stored_pubkey(const char *db_name,
    gnutls_tdb_t tdb,
    const char *host,
    const char *service,
    gnutls_certificate_type_t cert_type,
    const gnutls_datum_t * cert,
    unsigned int flags);


int gnutls_store_commitment(const char *db_name,
       gnutls_tdb_t tdb,
       const char *host,
       const char *service,
       gnutls_digest_algorithm_t hash_algo,
       const gnutls_datum_t * hash,
       time_t expiration, unsigned int flags);

int gnutls_store_pubkey(const char *db_name,
   gnutls_tdb_t tdb,
   const char *host,
   const char *service,
   gnutls_certificate_type_t cert_type,
   const gnutls_datum_t * cert,
   time_t expiration, unsigned int flags);


int gnutls_load_file(const char *filename, gnutls_datum_t * data);

unsigned gnutls_url_is_supported(const char *url);
typedef enum {
 GNUTLS_PIN_USER = (1 << 0),
 GNUTLS_PIN_SO = (1 << 1),
 GNUTLS_PIN_FINAL_TRY = (1 << 2),
 GNUTLS_PIN_COUNT_LOW = (1 << 3),
 GNUTLS_PIN_CONTEXT_SPECIFIC = (1 << 4),
 GNUTLS_PIN_WRONG = (1 << 5)
} gnutls_pin_flag_t;
typedef int (*gnutls_pin_callback_t) (void *userdata, int attempt,
          const char *token_url,
          const char *token_label,
          unsigned int flags,
          char *pin, size_t pin_max);

void gnutls_certificate_set_pin_function(gnutls_certificate_credentials_t,
      gnutls_pin_callback_t fn,
      void *userdata);


typedef struct gnutls_buffer_st *gnutls_buffer_t;

int gnutls_buffer_append_data(gnutls_buffer_t, const void *data, size_t data_size);


int gnutls_utf8_password_normalize(const unsigned char *password, unsigned password_len,
       gnutls_datum_t *out, unsigned flags);



typedef void *gnutls_ext_priv_data_t;

void gnutls_ext_set_data(gnutls_session_t session, unsigned type,
    gnutls_ext_priv_data_t);
int gnutls_ext_get_data(gnutls_session_t session, unsigned type,
   gnutls_ext_priv_data_t *);

unsigned gnutls_ext_get_current_msg(gnutls_session_t session);

typedef int (*gnutls_ext_recv_func) (gnutls_session_t session,
         const unsigned char *data,
         size_t len);

typedef int (*gnutls_ext_send_func) (gnutls_session_t session,
         gnutls_buffer_t extdata);

typedef void (*gnutls_ext_deinit_data_func) (gnutls_ext_priv_data_t data);

typedef int (*gnutls_ext_pack_func) (gnutls_ext_priv_data_t data,
         gnutls_buffer_t packed_data);

typedef int (*gnutls_ext_unpack_func) (gnutls_buffer_t packed_data,
           gnutls_ext_priv_data_t *data);



typedef int (*gnutls_ext_raw_process_func)(void *ctx, unsigned tls_id, const unsigned char *data, unsigned data_size);
int gnutls_ext_raw_parse(void *ctx, gnutls_ext_raw_process_func cb,
    const gnutls_datum_t *data, unsigned int flags);
typedef enum {
  GNUTLS_EXT_ANY = 0,
  GNUTLS_EXT_APPLICATION = 1,
  GNUTLS_EXT_TLS = 2,
  GNUTLS_EXT_MANDATORY = 3,
  GNUTLS_EXT_NONE = 4,
  GNUTLS_EXT_VERSION_NEG = 5
} gnutls_ext_parse_type_t;
typedef enum {
  GNUTLS_EXT_FLAG_OVERRIDE_INTERNAL = 1,
  GNUTLS_EXT_FLAG_CLIENT_HELLO = (1<<1),
  GNUTLS_EXT_FLAG_TLS12_SERVER_HELLO = (1<<2),
  GNUTLS_EXT_FLAG_TLS13_SERVER_HELLO = (1<<3),
  GNUTLS_EXT_FLAG_EE = (1<<4),
  GNUTLS_EXT_FLAG_HRR = (1<<5),
  GNUTLS_EXT_FLAG_IGNORE_CLIENT_REQUEST = (1<<6),
  GNUTLS_EXT_FLAG_TLS = (1<<7),
  GNUTLS_EXT_FLAG_DTLS = (1<<8)
} gnutls_ext_flags_t;



int gnutls_ext_register(const char *name, int type, gnutls_ext_parse_type_t parse_point,
    gnutls_ext_recv_func recv_func, gnutls_ext_send_func send_func,
    gnutls_ext_deinit_data_func deinit_func, gnutls_ext_pack_func pack_func,
    gnutls_ext_unpack_func unpack_func);

int gnutls_session_ext_register(gnutls_session_t, const char *name, int type, gnutls_ext_parse_type_t parse_point,
    gnutls_ext_recv_func recv_func, gnutls_ext_send_func send_func,
    gnutls_ext_deinit_data_func deinit_func, gnutls_ext_pack_func pack_func,
    gnutls_ext_unpack_func unpack_func, unsigned flags);

const char *gnutls_ext_get_name(unsigned int ext);
const char *gnutls_ext_get_name2(gnutls_session_t session, unsigned int tls_id,
     gnutls_ext_parse_type_t parse_point);



typedef int (*gnutls_supp_recv_func) (gnutls_session_t session,
          const unsigned char * data, size_t data_size);
typedef int (*gnutls_supp_send_func) (gnutls_session_t session,
          gnutls_buffer_t buf);

int gnutls_supplemental_register(const char *name,
    gnutls_supplemental_data_format_type_t type,
    gnutls_supp_recv_func supp_recv_func,
    gnutls_supp_send_func supp_send_func);

int gnutls_session_supplemental_register(gnutls_session_t session, const char *name,
    gnutls_supplemental_data_format_type_t type,
    gnutls_supp_recv_func supp_recv_func,
    gnutls_supp_send_func supp_send_func,
    unsigned int flags);

void gnutls_supplemental_recv(gnutls_session_t session, unsigned do_recv_supplemental);

void gnutls_supplemental_send(gnutls_session_t session, unsigned do_send_supplemental);



typedef struct gnutls_anti_replay_st *gnutls_anti_replay_t;

int gnutls_anti_replay_init(gnutls_anti_replay_t *anti_replay);
void gnutls_anti_replay_deinit(gnutls_anti_replay_t anti_replay);
void gnutls_anti_replay_set_window(gnutls_anti_replay_t anti_replay,
       unsigned int window);
void gnutls_anti_replay_enable(gnutls_session_t session,
          gnutls_anti_replay_t anti_replay);

typedef int (*gnutls_db_add_func) (void *, time_t exp_time, const gnutls_datum_t *key,
       const gnutls_datum_t *data);

void gnutls_anti_replay_set_add_function(gnutls_anti_replay_t,
      gnutls_db_add_func add_func);

void gnutls_anti_replay_set_ptr(gnutls_anti_replay_t, void *ptr);
typedef enum {
 GNUTLS_ENCRYPTION_LEVEL_INITIAL,
 GNUTLS_ENCRYPTION_LEVEL_EARLY,
 GNUTLS_ENCRYPTION_LEVEL_HANDSHAKE,
 GNUTLS_ENCRYPTION_LEVEL_APPLICATION
} gnutls_record_encryption_level_t;
typedef int (*gnutls_handshake_read_func) (gnutls_session_t session,
        gnutls_record_encryption_level_t level,
        gnutls_handshake_description_t htype,
        const void *data, size_t data_size);

void
gnutls_handshake_set_read_function(gnutls_session_t session,
       gnutls_handshake_read_func func);

int
gnutls_handshake_write(gnutls_session_t session,
         gnutls_record_encryption_level_t level,
         const void *data, size_t data_size);
typedef int (*gnutls_handshake_secret_func) (gnutls_session_t session,
          gnutls_record_encryption_level_t level,
          const void *secret_read,
          const void *secret_write,
          size_t secret_size);

void
gnutls_handshake_set_secret_function(gnutls_session_t session,
         gnutls_handshake_secret_func func);
typedef int (*gnutls_alert_read_func) (gnutls_session_t session,
           gnutls_record_encryption_level_t level,
           gnutls_alert_level_t alert_level,
           gnutls_alert_description_t alert_desc);

void
gnutls_alert_set_read_function(gnutls_session_t session,
          gnutls_alert_read_func func);


unsigned gnutls_fips140_mode_enabled(void);
typedef enum gnutls_fips_mode_t {
  GNUTLS_FIPS140_DISABLED = 0,
  GNUTLS_FIPS140_STRICT = 1,
  GNUTLS_FIPS140_SELFTESTS = 2,
  GNUTLS_FIPS140_LAX = 3,
  GNUTLS_FIPS140_LOG = 4
} gnutls_fips_mode_t;



void gnutls_fips140_set_mode(gnutls_fips_mode_t mode, unsigned flags);
typedef struct gnutls_fips140_context_st *gnutls_fips140_context_t;

int gnutls_fips140_context_init(gnutls_fips140_context_t *context);
void gnutls_fips140_context_deinit(gnutls_fips140_context_t context);
typedef enum {
        GNUTLS_FIPS140_OP_INITIAL,
        GNUTLS_FIPS140_OP_APPROVED,
        GNUTLS_FIPS140_OP_NOT_APPROVED,
        GNUTLS_FIPS140_OP_ERROR
} gnutls_fips140_operation_state_t;

gnutls_fips140_operation_state_t
gnutls_fips140_get_operation_state(gnutls_fips140_context_t context);

int gnutls_fips140_push_context(gnutls_fips140_context_t context);
int gnutls_fips140_pop_context(void);

int gnutls_fips140_run_self_tests(void);
typedef unsigned int gnutls_connection_end_t ;


typedef gnutls_cipher_algorithm_t gnutls_cipher_algorithm
    ;
typedef gnutls_kx_algorithm_t gnutls_kx_algorithm
    ;
typedef gnutls_mac_algorithm_t gnutls_mac_algorithm
    ;
typedef gnutls_digest_algorithm_t gnutls_digest_algorithm
    ;
typedef gnutls_compression_method_t gnutls_compression_method
    ;
typedef gnutls_connection_end_t gnutls_connection_end
    ;
typedef gnutls_x509_crt_fmt_t gnutls_x509_crt_fmt
    ;
typedef gnutls_pk_algorithm_t gnutls_pk_algorithm
    ;
typedef gnutls_sign_algorithm_t gnutls_sign_algorithm
    ;
typedef gnutls_close_request_t gnutls_close_request
    ;
typedef gnutls_certificate_request_t gnutls_certificate_request
    ;
typedef gnutls_certificate_status_t gnutls_certificate_status
    ;
typedef gnutls_session_t gnutls_session ;
typedef gnutls_alert_level_t gnutls_alert_level
    ;
typedef gnutls_alert_description_t gnutls_alert_description
    ;
typedef gnutls_x509_subject_alt_name_t gnutls_x509_subject_alt_name
    ;
typedef gnutls_openpgp_privkey_t gnutls_openpgp_privkey
    ;
typedef gnutls_openpgp_keyring_t gnutls_openpgp_keyring
    ;
typedef gnutls_x509_crt_t gnutls_x509_crt ;
typedef gnutls_x509_privkey_t gnutls_x509_privkey
    ;
typedef gnutls_x509_crl_t gnutls_x509_crl ;
typedef gnutls_x509_crq_t gnutls_x509_crq ;
typedef gnutls_certificate_credentials_t
    gnutls_certificate_credentials ;
typedef gnutls_anon_server_credentials_t
    gnutls_anon_server_credentials ;
typedef gnutls_anon_client_credentials_t
    gnutls_anon_client_credentials ;
typedef gnutls_srp_client_credentials_t
    gnutls_srp_client_credentials ;
typedef gnutls_srp_server_credentials_t
    gnutls_srp_server_credentials ;
typedef gnutls_dh_params_t gnutls_dh_params ;
typedef gnutls_rsa_params_t gnutls_rsa_params ;
typedef gnutls_params_type_t gnutls_params_type
    ;
typedef gnutls_credentials_type_t gnutls_credentials_type
    ;
typedef gnutls_certificate_type_t gnutls_certificate_type
    ;
typedef gnutls_datum_t gnutls_datum ;
typedef gnutls_transport_ptr_t gnutls_transport_ptr
    ;
typedef gnutls_openpgp_crt_status_t gnutls_openpgp_key_status_t
    ;
typedef gnutls_openpgp_crt_t gnutls_openpgp_key_t
    ;
int gnutls_x509_privkey_sign_hash(gnutls_x509_privkey_t key,
      const gnutls_datum_t * hash,
      gnutls_datum_t * signature)
    ;

int gnutls_openpgp_privkey_sign_hash(gnutls_openpgp_privkey_t key,
         const gnutls_datum_t * hash,
         gnutls_datum_t * signature)
    ;


int gnutls_x509_crt_get_preferred_hash_algorithm(gnutls_x509_crt_t
       crt,
       gnutls_digest_algorithm_t
       * hash, unsigned int
       *mand)
    ;







static inline const void
*gnutls_session_get_server_random(gnutls_session_t session)
    ;
static inline const void
*gnutls_session_get_server_random(gnutls_session_t session)
{
 gnutls_datum_t rnd;
 gnutls_session_get_random(session, 
                                   ((void *)0)
                                       , &rnd);
 return rnd.data;
}

static inline const void
*gnutls_session_get_client_random(gnutls_session_t session)
    ;
static inline const void
*gnutls_session_get_client_random(gnutls_session_t session)
{
 gnutls_datum_t rnd;
 gnutls_session_get_random(session, &rnd, 
                                         ((void *)0)
                                             );
 return rnd.data;
}


void
gnutls_global_set_mem_functions(gnutls_alloc_function alloc_func,
    gnutls_alloc_function secure_alloc_func,
    gnutls_is_secure_function is_secure_func,
    gnutls_realloc_function realloc_func,
    gnutls_free_function free_func) ;





gnutls_compression_method_t
gnutls_compression_get(gnutls_session_t session) ;

const char *
gnutls_compression_get_name(gnutls_compression_method_t
       algorithm) __attribute__((const)) ;

gnutls_compression_method_t
 gnutls_compression_get_id(const char *name) __attribute__((const)) ;

const gnutls_compression_method_t *
 gnutls_compression_list(void) __attribute__((pure)) ;

int gnutls_priority_compression_list(gnutls_priority_t pcache,
         const unsigned int **list) ;
typedef enum gnutls_certificate_import_flags {
 GNUTLS_X509_CRT_LIST_IMPORT_FAIL_IF_EXCEED = 1,
 GNUTLS_X509_CRT_LIST_FAIL_IF_UNSORTED = 1<<1,
 GNUTLS_X509_CRT_LIST_SORT = 1<<2
} gnutls_certificate_import_flags;

int gnutls_x509_crt_init(gnutls_x509_crt_t * cert);
void gnutls_x509_crt_deinit(gnutls_x509_crt_t cert);
typedef enum gnutls_x509_crt_flags {
 GNUTLS_X509_CRT_FLAG_IGNORE_SANITY = 1
} gnutls_x509_crt_flags;
void gnutls_x509_crt_set_flags(gnutls_x509_crt_t cert, unsigned flags);

unsigned gnutls_x509_crt_equals(gnutls_x509_crt_t cert1, gnutls_x509_crt_t cert2);
unsigned gnutls_x509_crt_equals2(gnutls_x509_crt_t cert1, const gnutls_datum_t * der);

int gnutls_x509_crt_import(gnutls_x509_crt_t cert,
      const gnutls_datum_t * data,
      gnutls_x509_crt_fmt_t format);
int gnutls_x509_crt_list_import2(gnutls_x509_crt_t ** certs,
     unsigned int *size,
     const gnutls_datum_t * data,
     gnutls_x509_crt_fmt_t format,
     unsigned int flags);
int gnutls_x509_crt_list_import(gnutls_x509_crt_t * certs,
    unsigned int *cert_max,
    const gnutls_datum_t * data,
    gnutls_x509_crt_fmt_t format,
    unsigned int flags);

int gnutls_x509_crt_import_url(gnutls_x509_crt_t crt,
          const char *url, unsigned int flags

    );

int
gnutls_x509_crt_list_import_url(gnutls_x509_crt_t **certs,
    unsigned int *size,
    const char *url,
    gnutls_pin_callback_t pin_fn,
    void *pin_fn_userdata,
    unsigned int flags);

int gnutls_x509_crt_export(gnutls_x509_crt_t cert,
      gnutls_x509_crt_fmt_t format,
      void *output_data, size_t * output_data_size);
int gnutls_x509_crt_export2(gnutls_x509_crt_t cert,
       gnutls_x509_crt_fmt_t format,
       gnutls_datum_t * out);
int gnutls_x509_crt_get_private_key_usage_period(gnutls_x509_crt_t
       cert,
       time_t *
       activation,
       time_t *
       expiration, unsigned int
       *critical);

int gnutls_x509_crt_get_issuer_dn(gnutls_x509_crt_t cert,
      char *buf, size_t * buf_size);
int gnutls_x509_crt_get_issuer_dn2(gnutls_x509_crt_t cert,
       gnutls_datum_t * dn);
int gnutls_x509_crt_get_issuer_dn3(gnutls_x509_crt_t cert,
       gnutls_datum_t * dn, unsigned flags);
int gnutls_x509_crt_get_issuer_dn_oid(gnutls_x509_crt_t cert,
          unsigned indx, void *oid,
          size_t * oid_size);
int gnutls_x509_crt_get_issuer_dn_by_oid(gnutls_x509_crt_t cert,
      const char *oid, unsigned indx,
      unsigned int raw_flag,
      void *buf, size_t * buf_size);

int gnutls_x509_crt_get_dn(gnutls_x509_crt_t cert, char *buf,
      size_t * buf_size);
int gnutls_x509_crt_get_dn2(gnutls_x509_crt_t cert, gnutls_datum_t * dn);
int gnutls_x509_crt_get_dn3(gnutls_x509_crt_t cert, gnutls_datum_t * dn, unsigned flags);

int gnutls_x509_crt_get_dn_oid(gnutls_x509_crt_t cert, unsigned indx,
          void *oid, size_t * oid_size);
int gnutls_x509_crt_get_dn_by_oid(gnutls_x509_crt_t cert,
      const char *oid, unsigned indx,
      unsigned int raw_flag, void *buf,
      size_t * buf_size);
unsigned gnutls_x509_crt_check_hostname(gnutls_x509_crt_t cert,
       const char *hostname);
unsigned gnutls_x509_crt_check_hostname2(gnutls_x509_crt_t cert,
      const char *hostname, unsigned int flags);
unsigned
gnutls_x509_crt_check_email(gnutls_x509_crt_t cert,
       const char *email, unsigned int flags);

unsigned
gnutls_x509_crt_check_ip(gnutls_x509_crt_t cert,
    const unsigned char *ip, unsigned int ip_size,
    unsigned int flags);

int gnutls_x509_crt_get_signature_algorithm(gnutls_x509_crt_t cert);
int gnutls_x509_crt_get_signature(gnutls_x509_crt_t cert,
      char *sig, size_t * sizeof_sig);
int gnutls_x509_crt_get_version(gnutls_x509_crt_t cert);

int gnutls_x509_crt_get_pk_oid(gnutls_x509_crt_t cert, char *oid, size_t *oid_size);
int gnutls_x509_crt_get_signature_oid(gnutls_x509_crt_t cert, char *oid, size_t *oid_size);
typedef enum {
 GNUTLS_KEYID_USE_SHA1 = 0,
 GNUTLS_KEYID_USE_SHA256 = (1<<0),
 GNUTLS_KEYID_USE_SHA512 = (1<<1),
 GNUTLS_KEYID_USE_BEST_KNOWN = (1<<30)
} gnutls_keyid_flags_t;
int gnutls_x509_crt_get_key_id(gnutls_x509_crt_t crt,
          unsigned int flags,
          unsigned char *output_data,
          size_t * output_data_size);

int gnutls_x509_crt_set_private_key_usage_period(gnutls_x509_crt_t
       crt,
       time_t activation,
       time_t expiration);
int gnutls_x509_crt_set_authority_key_id(gnutls_x509_crt_t cert,
      const void *id, size_t id_size);
int gnutls_x509_crt_get_authority_key_id(gnutls_x509_crt_t cert,
      void *id,
      size_t * id_size,
      unsigned int *critical);
int gnutls_x509_crt_get_authority_key_gn_serial(gnutls_x509_crt_t
      cert,
      unsigned int seq,
      void *alt,
      size_t * alt_size,
      unsigned int
      *alt_type,
      void *serial,
      size_t *
      serial_size, unsigned int
      *critical);

int gnutls_x509_crt_get_subject_key_id(gnutls_x509_crt_t cert,
           void *ret,
           size_t * ret_size,
           unsigned int *critical);

int gnutls_x509_crt_get_subject_unique_id(gnutls_x509_crt_t crt,
       char *buf, size_t * buf_size);

int gnutls_x509_crt_get_issuer_unique_id(gnutls_x509_crt_t crt,
      char *buf, size_t * buf_size);

void gnutls_x509_crt_set_pin_function(gnutls_x509_crt_t crt,
          gnutls_pin_callback_t fn,
          void *userdata);
typedef enum gnutls_info_access_what_t {
 GNUTLS_IA_ACCESSMETHOD_OID = 1,
 GNUTLS_IA_ACCESSLOCATION_GENERALNAME_TYPE = 2,

 GNUTLS_IA_URI = 106,

 GNUTLS_IA_UNKNOWN = 10000,
 GNUTLS_IA_OCSP_URI = 10006,
 GNUTLS_IA_CAISSUERS_URI = 10106
} gnutls_info_access_what_t;

int gnutls_x509_crt_get_authority_info_access(gnutls_x509_crt_t
           crt,
           unsigned int seq,
           int what,
           gnutls_datum_t *
           data, unsigned int
           *critical);

typedef struct gnutls_name_constraints_st *gnutls_x509_name_constraints_t;

unsigned gnutls_x509_name_constraints_check(gnutls_x509_name_constraints_t nc,
           gnutls_x509_subject_alt_name_t type,
           const gnutls_datum_t * name);
unsigned gnutls_x509_name_constraints_check_crt(gnutls_x509_name_constraints_t nc,
           gnutls_x509_subject_alt_name_t type,
           gnutls_x509_crt_t crt);

int gnutls_x509_name_constraints_init(gnutls_x509_name_constraints_t *nc);
void gnutls_x509_name_constraints_deinit(gnutls_x509_name_constraints_t nc);




int gnutls_x509_crt_get_name_constraints(gnutls_x509_crt_t crt,
      gnutls_x509_name_constraints_t nc,
      unsigned int flags,
      unsigned int *critical);
int gnutls_x509_name_constraints_add_permitted(gnutls_x509_name_constraints_t nc,
            gnutls_x509_subject_alt_name_t type,
            const gnutls_datum_t * name);
int gnutls_x509_name_constraints_add_excluded(gnutls_x509_name_constraints_t nc,
           gnutls_x509_subject_alt_name_t type,
           const gnutls_datum_t * name);
int gnutls_x509_crt_set_name_constraints(gnutls_x509_crt_t crt,
      gnutls_x509_name_constraints_t nc,
      unsigned int critical);
int gnutls_x509_name_constraints_get_permitted(gnutls_x509_name_constraints_t nc,
         unsigned idx,
         unsigned *type, gnutls_datum_t * name);
int gnutls_x509_name_constraints_get_excluded(gnutls_x509_name_constraints_t nc,
         unsigned idx,
         unsigned *type, gnutls_datum_t * name);
int gnutls_x509_cidr_to_rfc5280(const char *cidr, gnutls_datum_t *cidr_rfc5280);
typedef enum gnutls_x509_crl_reason_flags_t {
 GNUTLS_CRL_REASON_UNSPECIFIED = 0,
 GNUTLS_CRL_REASON_PRIVILEGE_WITHDRAWN = 1,
 GNUTLS_CRL_REASON_CERTIFICATE_HOLD = 2,
 GNUTLS_CRL_REASON_CESSATION_OF_OPERATION = 4,
 GNUTLS_CRL_REASON_SUPERSEDED = 8,
 GNUTLS_CRL_REASON_AFFILIATION_CHANGED = 16,
 GNUTLS_CRL_REASON_CA_COMPROMISE = 32,
 GNUTLS_CRL_REASON_KEY_COMPROMISE = 64,
 GNUTLS_CRL_REASON_UNUSED = 128,
 GNUTLS_CRL_REASON_AA_COMPROMISE = 32768
} gnutls_x509_crl_reason_flags_t;

int gnutls_x509_crt_get_crl_dist_points(gnutls_x509_crt_t cert,
     unsigned int seq,
     void *ret,
     size_t * ret_size,
     unsigned int *reason_flags,
     unsigned int *critical);
int gnutls_x509_crt_set_crl_dist_points2(gnutls_x509_crt_t crt,
      gnutls_x509_subject_alt_name_t
      type, const void *data,
      unsigned int data_size,
      unsigned int reason_flags);
int gnutls_x509_crt_set_crl_dist_points(gnutls_x509_crt_t crt,
     gnutls_x509_subject_alt_name_t
     type,
     const void *data_string,
     unsigned int reason_flags);
int gnutls_x509_crt_cpy_crl_dist_points(gnutls_x509_crt_t dst,
     gnutls_x509_crt_t src);

int gnutls_x509_crl_sign(gnutls_x509_crl_t crl,
    gnutls_x509_crt_t issuer,
    gnutls_x509_privkey_t issuer_key);

int gnutls_x509_crl_sign2(gnutls_x509_crl_t crl,
     gnutls_x509_crt_t issuer,
     gnutls_x509_privkey_t issuer_key,
     gnutls_digest_algorithm_t dig,
     unsigned int flags);

time_t gnutls_x509_crt_get_activation_time(gnutls_x509_crt_t cert);




time_t gnutls_x509_crt_get_expiration_time(gnutls_x509_crt_t cert);
int gnutls_x509_crt_get_serial(gnutls_x509_crt_t cert,
          void *result, size_t * result_size);

typedef struct gnutls_x509_spki_st *gnutls_x509_spki_t;

int gnutls_x509_spki_init(gnutls_x509_spki_t *spki);
void gnutls_x509_spki_deinit(gnutls_x509_spki_t spki);

int gnutls_x509_spki_get_rsa_pss_params(gnutls_x509_spki_t spki,
   gnutls_digest_algorithm_t *dig, unsigned int *salt_size);

void gnutls_x509_spki_set_rsa_pss_params(gnutls_x509_spki_t spki,
   gnutls_digest_algorithm_t dig, unsigned int salt_size);

int gnutls_x509_crt_get_pk_algorithm(gnutls_x509_crt_t cert,
         unsigned int *bits);
int gnutls_x509_crt_set_spki(gnutls_x509_crt_t crt, const gnutls_x509_spki_t spki,
        unsigned int flags);
int gnutls_x509_crt_get_spki(gnutls_x509_crt_t cert, gnutls_x509_spki_t spki,
        unsigned int flags);

int gnutls_x509_crt_get_pk_rsa_raw(gnutls_x509_crt_t crt,
       gnutls_datum_t * m, gnutls_datum_t * e);
int gnutls_x509_crt_get_pk_dsa_raw(gnutls_x509_crt_t crt,
       gnutls_datum_t * p,
       gnutls_datum_t * q,
       gnutls_datum_t * g, gnutls_datum_t * y);
int gnutls_x509_crt_get_pk_ecc_raw(gnutls_x509_crt_t crt,
       gnutls_ecc_curve_t * curve,
       gnutls_datum_t * x,
       gnutls_datum_t * y);
int gnutls_x509_crt_get_pk_gost_raw(gnutls_x509_crt_t crt,
        gnutls_ecc_curve_t * curve,
        gnutls_digest_algorithm_t * digest,
        gnutls_gost_paramset_t *paramset,
        gnutls_datum_t * x, gnutls_datum_t * y);

int gnutls_x509_crt_get_subject_alt_name(gnutls_x509_crt_t cert,
      unsigned int seq,
      void *san,
      size_t * san_size,
      unsigned int *critical);
int gnutls_x509_crt_get_subject_alt_name2(gnutls_x509_crt_t cert,
       unsigned int seq,
       void *san,
       size_t * san_size,
       unsigned int *san_type,
       unsigned int *critical);

int gnutls_x509_crt_get_subject_alt_othername_oid(gnutls_x509_crt_t
        cert,
        unsigned int seq,
        void *oid,
        size_t * oid_size);

int gnutls_x509_crt_get_issuer_alt_name(gnutls_x509_crt_t cert,
     unsigned int seq,
     void *ian,
     size_t * ian_size,
     unsigned int *critical);
int gnutls_x509_crt_get_issuer_alt_name2(gnutls_x509_crt_t cert,
      unsigned int seq,
      void *ian,
      size_t * ian_size,
      unsigned int *ian_type,
      unsigned int *critical);

int gnutls_x509_crt_get_issuer_alt_othername_oid(gnutls_x509_crt_t
       cert,
       unsigned int seq,
       void *ret,
       size_t * ret_size);

int gnutls_x509_crt_get_ca_status(gnutls_x509_crt_t cert,
      unsigned int *critical);
int gnutls_x509_crt_get_basic_constraints(gnutls_x509_crt_t cert,
       unsigned int *critical,
       unsigned int *ca, int *pathlen);




int gnutls_x509_crt_get_key_usage(gnutls_x509_crt_t cert,
      unsigned int *key_usage,
      unsigned int *critical);
int gnutls_x509_crt_set_key_usage(gnutls_x509_crt_t crt,
      unsigned int usage);
int gnutls_x509_crt_set_authority_info_access(gnutls_x509_crt_t
           crt, int what,
           gnutls_datum_t * data);

int gnutls_x509_crt_get_inhibit_anypolicy(gnutls_x509_crt_t cert,
      unsigned int *skipcerts,
      unsigned int *critical);
int
gnutls_x509_crt_set_inhibit_anypolicy(gnutls_x509_crt_t crt, unsigned int skipcerts);

int gnutls_x509_crt_get_proxy(gnutls_x509_crt_t cert,
         unsigned int *critical,
         int *pathlen,
         char **policyLanguage,
         char **policy, size_t * sizeof_policy);


typedef struct gnutls_x509_tlsfeatures_st *gnutls_x509_tlsfeatures_t;

int gnutls_x509_tlsfeatures_init(gnutls_x509_tlsfeatures_t *features);
void gnutls_x509_tlsfeatures_deinit(gnutls_x509_tlsfeatures_t);
int gnutls_x509_tlsfeatures_get(gnutls_x509_tlsfeatures_t f, unsigned idx, unsigned int *feature);

int gnutls_x509_crt_set_tlsfeatures(gnutls_x509_crt_t crt,
        gnutls_x509_tlsfeatures_t features);

int gnutls_x509_crt_get_tlsfeatures(gnutls_x509_crt_t cert,
        gnutls_x509_tlsfeatures_t features,
        unsigned int flags,
        unsigned int *critical);

unsigned gnutls_x509_tlsfeatures_check_crt(gnutls_x509_tlsfeatures_t feat,
               gnutls_x509_crt_t crt);
typedef enum gnutls_x509_qualifier_t {
 GNUTLS_X509_QUALIFIER_UNKNOWN = 0, GNUTLS_X509_QUALIFIER_URI,
 GNUTLS_X509_QUALIFIER_NOTICE
} gnutls_x509_qualifier_t;

typedef struct gnutls_x509_policy_st {
 char *oid;
 unsigned int qualifiers;
 struct {
  gnutls_x509_qualifier_t type;
  char *data;
  unsigned int size;
 } qualifier[8];
} gnutls_x509_policy_st;

void gnutls_x509_policy_release(struct gnutls_x509_policy_st
    *policy);
int gnutls_x509_crt_get_policy(gnutls_x509_crt_t crt, unsigned indx, struct gnutls_x509_policy_st
          *policy, unsigned int *critical);
int gnutls_x509_crt_set_policy(gnutls_x509_crt_t crt, const struct gnutls_x509_policy_st
          *policy, unsigned int critical);

int gnutls_x509_dn_oid_known(const char *oid);


const char *gnutls_x509_dn_oid_name(const char *oid, unsigned int flags);


int gnutls_x509_crt_get_extension_oid(gnutls_x509_crt_t cert,
          unsigned indx, void *oid,
          size_t * oid_size);
int gnutls_x509_crt_get_extension_by_oid(gnutls_x509_crt_t cert,
      const char *oid, unsigned indx,
      void *buf,
      size_t * buf_size,
      unsigned int *critical);

int gnutls_x509_crq_get_signature_algorithm(gnutls_x509_crq_t crq);
int
gnutls_x509_crq_get_extension_by_oid2(gnutls_x509_crq_t crq,
         const char *oid, unsigned indx,
         gnutls_datum_t *output,
         unsigned int *critical);


int gnutls_x509_crt_get_extension_info(gnutls_x509_crt_t cert,
           unsigned indx, void *oid,
           size_t * oid_size,
           unsigned int *critical);
int gnutls_x509_crt_get_extension_data(gnutls_x509_crt_t cert,
           unsigned indx, void *data,
           size_t * sizeof_data);
int
gnutls_x509_crt_get_extension_data2(gnutls_x509_crt_t cert,
          unsigned indx, gnutls_datum_t * data);


int gnutls_x509_crt_set_extension_by_oid(gnutls_x509_crt_t crt,
      const char *oid,
      const void *buf,
      size_t sizeof_buf,
      unsigned int critical);



int gnutls_x509_crt_set_dn(gnutls_x509_crt_t crt, const char *dn,
      const char **err);

int gnutls_x509_crt_set_dn_by_oid(gnutls_x509_crt_t crt,
      const char *oid,
      unsigned int raw_flag,
      const void *name,
      unsigned int sizeof_name);
int gnutls_x509_crt_set_issuer_dn_by_oid(gnutls_x509_crt_t crt,
      const char *oid,
      unsigned int raw_flag,
      const void *name,
      unsigned int sizeof_name);
int gnutls_x509_crt_set_issuer_dn(gnutls_x509_crt_t crt,
      const char *dn, const char **err);

int gnutls_x509_crt_set_version(gnutls_x509_crt_t crt,
    unsigned int version);
int gnutls_x509_crt_set_key(gnutls_x509_crt_t crt,
       gnutls_x509_privkey_t key);
int gnutls_x509_crt_set_ca_status(gnutls_x509_crt_t crt, unsigned int ca);
int gnutls_x509_crt_set_basic_constraints(gnutls_x509_crt_t crt,
       unsigned int ca,
       int pathLenConstraint);

int
gnutls_x509_crt_set_subject_unique_id(gnutls_x509_crt_t cert, const void *id,
      size_t id_size);
int
gnutls_x509_crt_set_issuer_unique_id(gnutls_x509_crt_t cert, const void *id,
      size_t id_size);

int gnutls_x509_crt_set_subject_alternative_name(gnutls_x509_crt_t
       crt,
       gnutls_x509_subject_alt_name_t
       type, const char
       *data_string);
int gnutls_x509_crt_set_subject_alt_name(gnutls_x509_crt_t crt,
      gnutls_x509_subject_alt_name_t
      type, const void *data,
      unsigned int data_size,
      unsigned int flags);

int
gnutls_x509_crt_set_subject_alt_othername(gnutls_x509_crt_t crt,
         const char *oid,
         const void *data,
         unsigned int data_size,
         unsigned int flags);

int gnutls_x509_crt_set_issuer_alt_name(gnutls_x509_crt_t crt,
      gnutls_x509_subject_alt_name_t
      type, const void *data,
      unsigned int data_size,
      unsigned int flags);

int
gnutls_x509_crt_set_issuer_alt_othername(gnutls_x509_crt_t crt,
         const char *oid,
         const void *data,
         unsigned int data_size,
         unsigned int flags);

int gnutls_x509_crt_sign(gnutls_x509_crt_t crt,
    gnutls_x509_crt_t issuer,
    gnutls_x509_privkey_t issuer_key);
int gnutls_x509_crt_sign2(gnutls_x509_crt_t crt,
     gnutls_x509_crt_t issuer,
     gnutls_x509_privkey_t issuer_key,
     gnutls_digest_algorithm_t dig,
     unsigned int flags);
int gnutls_x509_crt_set_activation_time(gnutls_x509_crt_t cert,
     time_t act_time);
int gnutls_x509_crt_set_expiration_time(gnutls_x509_crt_t cert,
     time_t exp_time);
int gnutls_x509_crt_set_serial(gnutls_x509_crt_t cert,
          const void *serial, size_t serial_size);

int gnutls_x509_crt_set_subject_key_id(gnutls_x509_crt_t cert,
           const void *id, size_t id_size);

int gnutls_x509_crt_set_proxy_dn(gnutls_x509_crt_t crt,
     gnutls_x509_crt_t eecrt,
     unsigned int raw_flag,
     const void *name,
     unsigned int sizeof_name);
int gnutls_x509_crt_set_proxy(gnutls_x509_crt_t crt,
         int pathLenConstraint,
         const char *policyLanguage,
         const char *policy, size_t sizeof_policy);

int gnutls_x509_crt_print(gnutls_x509_crt_t cert,
     gnutls_certificate_print_formats_t
     format, gnutls_datum_t * out);
int gnutls_x509_crl_print(gnutls_x509_crl_t crl,
     gnutls_certificate_print_formats_t
     format, gnutls_datum_t * out);



int gnutls_x509_crt_get_raw_issuer_dn(gnutls_x509_crt_t cert,
          gnutls_datum_t * start);
int gnutls_x509_crt_get_raw_dn(gnutls_x509_crt_t cert,
          gnutls_datum_t * start);



int gnutls_x509_rdn_get(const gnutls_datum_t * idn,
   char *buf, size_t * sizeof_buf);
int
gnutls_x509_rdn_get2(const gnutls_datum_t * idn,
                     gnutls_datum_t *str, unsigned flags);

int gnutls_x509_rdn_get_oid(const gnutls_datum_t * idn,
       unsigned indx, void *buf, size_t * sizeof_buf);

int gnutls_x509_rdn_get_by_oid(const gnutls_datum_t * idn,
          const char *oid, unsigned indx,
          unsigned int raw_flag, void *buf,
          size_t * sizeof_buf);

typedef struct gnutls_x509_dn_st *gnutls_x509_dn_t;

typedef struct gnutls_x509_ava_st {
 gnutls_datum_t oid;
 gnutls_datum_t value;
 unsigned long value_tag;
} gnutls_x509_ava_st;

int gnutls_x509_crt_get_subject(gnutls_x509_crt_t cert,
    gnutls_x509_dn_t * dn);
int gnutls_x509_crt_get_issuer(gnutls_x509_crt_t cert,
          gnutls_x509_dn_t * dn);
int gnutls_x509_dn_get_rdn_ava(gnutls_x509_dn_t dn, int irdn,
          int iava, gnutls_x509_ava_st * ava);

int gnutls_x509_dn_get_str(gnutls_x509_dn_t dn, gnutls_datum_t *str);


int gnutls_x509_dn_get_str2(gnutls_x509_dn_t dn, gnutls_datum_t *str, unsigned flags);

int
gnutls_x509_dn_set_str(gnutls_x509_dn_t dn, const char *str, const char **err);

int gnutls_x509_dn_init(gnutls_x509_dn_t * dn);

int gnutls_x509_dn_import(gnutls_x509_dn_t dn,
     const gnutls_datum_t * data);

int gnutls_x509_dn_export(gnutls_x509_dn_t dn,
     gnutls_x509_crt_fmt_t format,
     void *output_data, size_t * output_data_size);
int gnutls_x509_dn_export2(gnutls_x509_dn_t dn,
      gnutls_x509_crt_fmt_t format,
      gnutls_datum_t * out);

void gnutls_x509_dn_deinit(gnutls_x509_dn_t dn);




int gnutls_x509_crl_init(gnutls_x509_crl_t * crl);
void gnutls_x509_crl_deinit(gnutls_x509_crl_t crl);

int gnutls_x509_crl_import(gnutls_x509_crl_t crl,
      const gnutls_datum_t * data,
      gnutls_x509_crt_fmt_t format);
int gnutls_x509_crl_export(gnutls_x509_crl_t crl,
      gnutls_x509_crt_fmt_t format,
      void *output_data, size_t * output_data_size);
int gnutls_x509_crl_export2(gnutls_x509_crl_t crl,
       gnutls_x509_crt_fmt_t format,
       gnutls_datum_t * out);

int
gnutls_x509_crl_get_raw_issuer_dn(gnutls_x509_crl_t crl,
      gnutls_datum_t * dn);

int gnutls_x509_crl_get_issuer_dn(gnutls_x509_crl_t crl,
      char *buf, size_t * sizeof_buf);
int gnutls_x509_crl_get_issuer_dn2(gnutls_x509_crl_t crl,
       gnutls_datum_t * dn);
int gnutls_x509_crl_get_issuer_dn3(gnutls_x509_crl_t crl,
       gnutls_datum_t * dn, unsigned flags);

int gnutls_x509_crl_get_issuer_dn_by_oid(gnutls_x509_crl_t crl,
      const char *oid, unsigned indx,
      unsigned int raw_flag,
      void *buf, size_t * sizeof_buf);
int gnutls_x509_crl_get_dn_oid(gnutls_x509_crl_t crl, unsigned indx,
          void *oid, size_t * sizeof_oid);

int gnutls_x509_crl_get_signature_algorithm(gnutls_x509_crl_t crl);
int gnutls_x509_crl_get_signature(gnutls_x509_crl_t crl,
      char *sig, size_t * sizeof_sig);
int gnutls_x509_crl_get_version(gnutls_x509_crl_t crl);

int gnutls_x509_crl_get_signature_oid(gnutls_x509_crl_t crl, char *oid, size_t *oid_size);

time_t gnutls_x509_crl_get_this_update(gnutls_x509_crl_t crl);
time_t gnutls_x509_crl_get_next_update(gnutls_x509_crl_t crl);

int gnutls_x509_crl_get_crt_count(gnutls_x509_crl_t crl);
int gnutls_x509_crl_get_crt_serial(gnutls_x509_crl_t crl, unsigned indx,
       unsigned char *serial,
       size_t * serial_size, time_t * t);

typedef struct gnutls_x509_crl_iter * gnutls_x509_crl_iter_t;

int gnutls_x509_crl_iter_crt_serial(gnutls_x509_crl_t crl,
        gnutls_x509_crl_iter_t *,
        unsigned char *serial,
        size_t * serial_size, time_t * t);

void gnutls_x509_crl_iter_deinit(gnutls_x509_crl_iter_t);




unsigned gnutls_x509_crl_check_issuer(gnutls_x509_crl_t crl,
     gnutls_x509_crt_t issuer);

int gnutls_x509_crl_list_import2(gnutls_x509_crl_t ** crls,
     unsigned int *size,
     const gnutls_datum_t * data,
     gnutls_x509_crt_fmt_t format,
     unsigned int flags);

int gnutls_x509_crl_list_import(gnutls_x509_crl_t * crls,
    unsigned int *crl_max,
    const gnutls_datum_t * data,
    gnutls_x509_crt_fmt_t format,
    unsigned int flags);


int gnutls_x509_crl_set_version(gnutls_x509_crl_t crl,
    unsigned int version);
int gnutls_x509_crl_set_this_update(gnutls_x509_crl_t crl,
        time_t act_time);
int gnutls_x509_crl_set_next_update(gnutls_x509_crl_t crl,
        time_t exp_time);
int gnutls_x509_crl_set_crt_serial(gnutls_x509_crl_t crl,
       const void *serial,
       size_t serial_size,
       time_t revocation_time);
int gnutls_x509_crl_set_crt(gnutls_x509_crl_t crl,
       gnutls_x509_crt_t crt, time_t revocation_time);

int gnutls_x509_crl_get_authority_key_id(gnutls_x509_crl_t crl,
      void *id,
      size_t * id_size,
      unsigned int *critical);
int gnutls_x509_crl_get_authority_key_gn_serial(gnutls_x509_crl_t
      crl,
      unsigned int seq,
      void *alt,
      size_t * alt_size,
      unsigned int
      *alt_type,
      void *serial,
      size_t *
      serial_size, unsigned int
      *critical);

int gnutls_x509_crl_get_number(gnutls_x509_crl_t crl, void *ret,
          size_t * ret_size, unsigned int *critical);

int gnutls_x509_crl_get_extension_oid(gnutls_x509_crl_t crl,
          unsigned indx, void *oid,
          size_t * sizeof_oid);

int gnutls_x509_crl_get_extension_info(gnutls_x509_crl_t crl,
           unsigned indx, void *oid,
           size_t * sizeof_oid,
           unsigned int *critical);

int gnutls_x509_crl_get_extension_data(gnutls_x509_crl_t crl,
           unsigned indx, void *data,
           size_t * sizeof_data);
int
gnutls_x509_crl_get_extension_data2(gnutls_x509_crl_t crl,
          unsigned indx, gnutls_datum_t * data);

int gnutls_x509_crl_set_authority_key_id(gnutls_x509_crl_t crl,
      const void *id, size_t id_size);

int gnutls_x509_crl_set_number(gnutls_x509_crl_t crl,
          const void *nr, size_t nr_size);
typedef enum gnutls_certificate_verify_flags {
 GNUTLS_VERIFY_DISABLE_CA_SIGN = 1 << 0,
 GNUTLS_VERIFY_DO_NOT_ALLOW_IP_MATCHES = 1<<1,
 GNUTLS_VERIFY_DO_NOT_ALLOW_SAME = 1 << 2,
 GNUTLS_VERIFY_ALLOW_ANY_X509_V1_CA_CRT = 1 << 3,
 GNUTLS_VERIFY_ALLOW_SIGN_RSA_MD2 = 1 << 4,
 GNUTLS_VERIFY_ALLOW_SIGN_RSA_MD5 = 1 << 5,
 GNUTLS_VERIFY_DISABLE_TIME_CHECKS = 1 << 6,
 GNUTLS_VERIFY_DISABLE_TRUSTED_TIME_CHECKS = 1 << 7,
 GNUTLS_VERIFY_DO_NOT_ALLOW_X509_V1_CA_CRT = 1 << 8,
 GNUTLS_VERIFY_DISABLE_CRL_CHECKS = 1 << 9,
 GNUTLS_VERIFY_ALLOW_UNSORTED_CHAIN = 1 << 10,
 GNUTLS_VERIFY_DO_NOT_ALLOW_UNSORTED_CHAIN = 1 << 11,
 GNUTLS_VERIFY_DO_NOT_ALLOW_WILDCARDS = 1 << 12,
 GNUTLS_VERIFY_USE_TLS1_RSA = 1 << 13,
 GNUTLS_VERIFY_IGNORE_UNKNOWN_CRIT_EXTENSIONS = 1 << 14,
 GNUTLS_VERIFY_ALLOW_SIGN_WITH_SHA1 = 1 << 15,
 GNUTLS_VERIFY_RSA_PSS_FIXED_SALT_LENGTH = 1 << 16

} gnutls_certificate_verify_flags;
typedef enum gnutls_certificate_verification_profiles_t {
 GNUTLS_PROFILE_UNKNOWN = 0,
 GNUTLS_PROFILE_VERY_WEAK = 1,
 GNUTLS_PROFILE_LOW = 2,
 GNUTLS_PROFILE_LEGACY = 4,
 GNUTLS_PROFILE_MEDIUM = 5,
 GNUTLS_PROFILE_HIGH = 6,
 GNUTLS_PROFILE_ULTRA = 7,
 GNUTLS_PROFILE_FUTURE = 8,

 GNUTLS_PROFILE_SUITEB128=32,
 GNUTLS_PROFILE_SUITEB192=33

} gnutls_certificate_verification_profiles_t;
const char *
 gnutls_certificate_verification_profile_get_name(gnutls_certificate_verification_profiles_t id) __attribute__((const));
gnutls_certificate_verification_profiles_t gnutls_certificate_verification_profile_get_id(const char *name) __attribute__((const));

unsigned gnutls_x509_crt_check_issuer(gnutls_x509_crt_t cert,
     gnutls_x509_crt_t issuer);

int gnutls_x509_crt_list_verify(const gnutls_x509_crt_t *
    cert_list, unsigned cert_list_length,
    const gnutls_x509_crt_t * CA_list,
    unsigned CA_list_length,
    const gnutls_x509_crl_t * CRL_list,
    unsigned CRL_list_length,
    unsigned int flags, unsigned int *verify);

int gnutls_x509_crt_verify(gnutls_x509_crt_t cert,
      const gnutls_x509_crt_t * CA_list,
      unsigned CA_list_length, unsigned int flags,
      unsigned int *verify);
int gnutls_x509_crl_verify(gnutls_x509_crl_t crl,
      const gnutls_x509_crt_t * CA_list,
      unsigned CA_list_length, unsigned int flags,
      unsigned int *verify);

int
gnutls_x509_crt_verify_data2(gnutls_x509_crt_t crt,
      gnutls_sign_algorithm_t algo,
      unsigned int flags,
      const gnutls_datum_t * data,
      const gnutls_datum_t * signature);

int gnutls_x509_crt_check_revocation(gnutls_x509_crt_t cert,
         const gnutls_x509_crl_t *
         crl_list, unsigned crl_list_length);

int gnutls_x509_crt_get_fingerprint(gnutls_x509_crt_t cert,
        gnutls_digest_algorithm_t algo,
        void *buf, size_t * buf_size);

int gnutls_x509_crt_get_key_purpose_oid(gnutls_x509_crt_t cert,
     unsigned indx, void *oid,
     size_t * oid_size,
     unsigned int *critical);
int gnutls_x509_crt_set_key_purpose_oid(gnutls_x509_crt_t cert,
     const void *oid,
     unsigned int critical);

unsigned gnutls_x509_crt_check_key_purpose(gnutls_x509_crt_t cert,
  const char *purpose, unsigned flags);
typedef enum gnutls_pkcs_encrypt_flags_t {
 GNUTLS_PKCS_PLAIN = 1,
 GNUTLS_PKCS_PKCS12_3DES = 1<<1,
 GNUTLS_PKCS_PKCS12_ARCFOUR = 1<<2,
 GNUTLS_PKCS_PKCS12_RC2_40 = 1<<3,
 GNUTLS_PKCS_PBES2_3DES = 1<<4,
 GNUTLS_PKCS_PBES2_AES_128 = 1<<5,
 GNUTLS_PKCS_PBES2_AES_192 = 1<<6,
 GNUTLS_PKCS_PBES2_AES_256 = 1<<7,
 GNUTLS_PKCS_NULL_PASSWORD = 1<<8,
 GNUTLS_PKCS_PBES2_DES = 1<<9,
 GNUTLS_PKCS_PBES1_DES_MD5 = 1<<10,
 GNUTLS_PKCS_PBES2_GOST_TC26Z = 1<<11,
 GNUTLS_PKCS_PBES2_GOST_CPA = 1<<12,
 GNUTLS_PKCS_PBES2_GOST_CPB = 1<<13,
 GNUTLS_PKCS_PBES2_GOST_CPC = 1<<14,
 GNUTLS_PKCS_PBES2_GOST_CPD = 1<<15
} gnutls_pkcs_encrypt_flags_t;
const char *gnutls_pkcs_schema_get_name(unsigned int schema);
const char *gnutls_pkcs_schema_get_oid(unsigned int schema);

int gnutls_x509_privkey_init(gnutls_x509_privkey_t * key);
void gnutls_x509_privkey_deinit(gnutls_x509_privkey_t key);
gnutls_sec_param_t
gnutls_x509_privkey_sec_param(gnutls_x509_privkey_t key);

void gnutls_x509_privkey_set_pin_function(gnutls_x509_privkey_t key,
          gnutls_pin_callback_t fn,
          void *userdata);

int gnutls_x509_privkey_cpy(gnutls_x509_privkey_t dst,
       gnutls_x509_privkey_t src);
int gnutls_x509_privkey_import(gnutls_x509_privkey_t key,
          const gnutls_datum_t * data,
          gnutls_x509_crt_fmt_t format);
int gnutls_x509_privkey_import_pkcs8(gnutls_x509_privkey_t key,
         const gnutls_datum_t * data,
         gnutls_x509_crt_fmt_t format,
         const char *password,
         unsigned int flags);
int gnutls_x509_privkey_import_openssl(gnutls_x509_privkey_t key,
           const gnutls_datum_t * data,
           const char *password);

int
gnutls_pkcs8_info(const gnutls_datum_t * data, gnutls_x509_crt_fmt_t format,
    unsigned int *schema, unsigned int *cipher,
    void *salt, unsigned int *salt_size,
    unsigned int *iter_count, char **oid);

int gnutls_x509_privkey_import2(gnutls_x509_privkey_t key,
    const gnutls_datum_t * data,
    gnutls_x509_crt_fmt_t format,
    const char *password, unsigned int flags);

int gnutls_x509_privkey_import_rsa_raw(gnutls_x509_privkey_t key,
           const gnutls_datum_t * m,
           const gnutls_datum_t * e,
           const gnutls_datum_t * d,
           const gnutls_datum_t * p,
           const gnutls_datum_t * q,
           const gnutls_datum_t * u);
int gnutls_x509_privkey_import_rsa_raw2(gnutls_x509_privkey_t key,
     const gnutls_datum_t * m,
     const gnutls_datum_t * e,
     const gnutls_datum_t * d,
     const gnutls_datum_t * p,
     const gnutls_datum_t * q,
     const gnutls_datum_t * u,
     const gnutls_datum_t * e1,
     const gnutls_datum_t * e2);
int gnutls_x509_privkey_import_ecc_raw(gnutls_x509_privkey_t key,
           gnutls_ecc_curve_t curve,
           const gnutls_datum_t * x,
           const gnutls_datum_t * y,
           const gnutls_datum_t * k);
int gnutls_x509_privkey_import_gost_raw(gnutls_x509_privkey_t key,
           gnutls_ecc_curve_t curve,
           gnutls_digest_algorithm_t digest,
           gnutls_gost_paramset_t paramset,
           const gnutls_datum_t * x,
           const gnutls_datum_t * y,
           const gnutls_datum_t * k);

int gnutls_x509_privkey_fix(gnutls_x509_privkey_t key);

int gnutls_x509_privkey_export_dsa_raw(gnutls_x509_privkey_t key,
           gnutls_datum_t * p,
           gnutls_datum_t * q,
           gnutls_datum_t * g,
           gnutls_datum_t * y,
           gnutls_datum_t * x);
int gnutls_x509_privkey_import_dsa_raw(gnutls_x509_privkey_t key,
           const gnutls_datum_t * p,
           const gnutls_datum_t * q,
           const gnutls_datum_t * g,
           const gnutls_datum_t * y,
           const gnutls_datum_t * x);

int gnutls_x509_privkey_get_pk_algorithm(gnutls_x509_privkey_t key);
int gnutls_x509_privkey_get_pk_algorithm2(gnutls_x509_privkey_t
       key, unsigned int *bits);
int gnutls_x509_privkey_get_spki(gnutls_x509_privkey_t key,
     gnutls_x509_spki_t spki,
     unsigned int flags);
int
gnutls_x509_privkey_set_spki(gnutls_x509_privkey_t key,
        const gnutls_x509_spki_t spki,
        unsigned int flags);

int gnutls_x509_privkey_get_key_id(gnutls_x509_privkey_t key,
       unsigned int flags,
       unsigned char *output_data,
       size_t * output_data_size);

int gnutls_x509_privkey_generate(gnutls_x509_privkey_t key,
     gnutls_pk_algorithm_t algo,
     unsigned int bits, unsigned int flags);

void gnutls_x509_privkey_set_flags(gnutls_x509_privkey_t key, unsigned int flags);
typedef enum {
 GNUTLS_KEYGEN_SEED = 1,
 GNUTLS_KEYGEN_DIGEST = 2,
 GNUTLS_KEYGEN_SPKI = 3
} gnutls_keygen_types_t;

typedef struct {
 gnutls_keygen_types_t type;
 unsigned char *data;
 unsigned int size;
} gnutls_keygen_data_st;

int
gnutls_x509_privkey_generate2(gnutls_x509_privkey_t key,
         gnutls_pk_algorithm_t algo, unsigned int bits,
         unsigned int flags, const gnutls_keygen_data_st *data, unsigned data_size);

int gnutls_x509_privkey_verify_seed(gnutls_x509_privkey_t key, gnutls_digest_algorithm_t, const void *seed, size_t seed_size);
int gnutls_x509_privkey_get_seed(gnutls_x509_privkey_t key, gnutls_digest_algorithm_t*, void *seed, size_t *seed_size);

int gnutls_x509_privkey_verify_params(gnutls_x509_privkey_t key);

int gnutls_x509_privkey_export(gnutls_x509_privkey_t key,
          gnutls_x509_crt_fmt_t format,
          void *output_data,
          size_t * output_data_size);
int gnutls_x509_privkey_export2(gnutls_x509_privkey_t key,
    gnutls_x509_crt_fmt_t format,
    gnutls_datum_t * out);
int gnutls_x509_privkey_export_pkcs8(gnutls_x509_privkey_t key,
         gnutls_x509_crt_fmt_t format,
         const char *password,
         unsigned int flags,
         void *output_data,
         size_t * output_data_size);
int gnutls_x509_privkey_export2_pkcs8(gnutls_x509_privkey_t key,
          gnutls_x509_crt_fmt_t format,
          const char *password,
          unsigned int flags,
          gnutls_datum_t * out);
int gnutls_x509_privkey_export_rsa_raw2(gnutls_x509_privkey_t key,
     gnutls_datum_t * m,
     gnutls_datum_t * e,
     gnutls_datum_t * d,
     gnutls_datum_t * p,
     gnutls_datum_t * q,
     gnutls_datum_t * u,
     gnutls_datum_t * e1,
     gnutls_datum_t * e2);
int gnutls_x509_privkey_export_rsa_raw(gnutls_x509_privkey_t key,
           gnutls_datum_t * m,
           gnutls_datum_t * e,
           gnutls_datum_t * d,
           gnutls_datum_t * p,
           gnutls_datum_t * q,
           gnutls_datum_t * u);
int gnutls_x509_privkey_export_ecc_raw(gnutls_x509_privkey_t key,
           gnutls_ecc_curve_t * curve,
           gnutls_datum_t * x,
           gnutls_datum_t * y,
           gnutls_datum_t * k);
int gnutls_x509_privkey_export_gost_raw(gnutls_x509_privkey_t key,
           gnutls_ecc_curve_t * curve,
           gnutls_digest_algorithm_t * digest,
           gnutls_gost_paramset_t * paramset,
           gnutls_datum_t * x,
           gnutls_datum_t * y,
           gnutls_datum_t * k);

int gnutls_x509_privkey_sign_data(gnutls_x509_privkey_t key,
      gnutls_digest_algorithm_t digest,
      unsigned int flags,
      const gnutls_datum_t * data,
      void *signature,
      size_t * signature_size);



int gnutls_x509_crq_sign(gnutls_x509_crq_t crq,
    gnutls_x509_privkey_t key);

int gnutls_x509_crq_sign2(gnutls_x509_crq_t crq,
     gnutls_x509_privkey_t key,
     gnutls_digest_algorithm_t dig,
     unsigned int flags);

int gnutls_x509_crq_print(gnutls_x509_crq_t crq,
     gnutls_certificate_print_formats_t
     format, gnutls_datum_t * out);

int gnutls_x509_crq_verify(gnutls_x509_crq_t crq, unsigned int flags);

int gnutls_x509_crq_init(gnutls_x509_crq_t * crq);
void gnutls_x509_crq_deinit(gnutls_x509_crq_t crq);
int gnutls_x509_crq_import(gnutls_x509_crq_t crq,
      const gnutls_datum_t * data,
      gnutls_x509_crt_fmt_t format);

int gnutls_x509_crq_get_private_key_usage_period(gnutls_x509_crq_t
       cert,
       time_t *
       activation,
       time_t *
       expiration, unsigned int
       *critical);

int gnutls_x509_crq_get_dn(gnutls_x509_crq_t crq, char *buf,
      size_t * sizeof_buf);
int gnutls_x509_crq_get_dn2(gnutls_x509_crq_t crq, gnutls_datum_t * dn);
int gnutls_x509_crq_get_dn3(gnutls_x509_crq_t crq, gnutls_datum_t * dn, unsigned flags);
int gnutls_x509_crq_get_dn_oid(gnutls_x509_crq_t crq, unsigned indx,
          void *oid, size_t * sizeof_oid);
int gnutls_x509_crq_get_dn_by_oid(gnutls_x509_crq_t crq,
      const char *oid, unsigned indx,
      unsigned int raw_flag, void *buf,
      size_t * sizeof_buf);
int gnutls_x509_crq_set_dn(gnutls_x509_crq_t crq, const char *dn,
      const char **err);
int gnutls_x509_crq_set_dn_by_oid(gnutls_x509_crq_t crq,
      const char *oid,
      unsigned int raw_flag,
      const void *data,
      unsigned int sizeof_data);
int gnutls_x509_crq_set_version(gnutls_x509_crq_t crq,
    unsigned int version);
int gnutls_x509_crq_get_version(gnutls_x509_crq_t crq);
int gnutls_x509_crq_set_key(gnutls_x509_crq_t crq,
       gnutls_x509_privkey_t key);

int
gnutls_x509_crq_set_extension_by_oid(gnutls_x509_crq_t crq,
         const char *oid, const void *buf,
         size_t sizeof_buf,
         unsigned int critical);

int gnutls_x509_crq_set_challenge_password(gnutls_x509_crq_t crq,
        const char *pass);
int gnutls_x509_crq_get_challenge_password(gnutls_x509_crq_t crq,
        char *pass,
        size_t * sizeof_pass);

int gnutls_x509_crq_set_attribute_by_oid(gnutls_x509_crq_t crq,
      const char *oid,
      void *buf, size_t sizeof_buf);
int gnutls_x509_crq_get_attribute_by_oid(gnutls_x509_crq_t crq,
      const char *oid, unsigned indx,
      void *buf, size_t * sizeof_buf);

int gnutls_x509_crq_export(gnutls_x509_crq_t crq,
      gnutls_x509_crt_fmt_t format,
      void *output_data, size_t * output_data_size);
int gnutls_x509_crq_export2(gnutls_x509_crq_t crq,
       gnutls_x509_crt_fmt_t format,
       gnutls_datum_t * out);

int gnutls_x509_crt_set_crq(gnutls_x509_crt_t crt, gnutls_x509_crq_t crq);
int gnutls_x509_crt_set_crq_extensions(gnutls_x509_crt_t crt,
           gnutls_x509_crq_t crq);

int
gnutls_x509_crt_set_crq_extension_by_oid(gnutls_x509_crt_t crt,
             gnutls_x509_crq_t crq, const char *oid,
             unsigned flags);

int gnutls_x509_crq_set_private_key_usage_period(gnutls_x509_crq_t
       crq,
       time_t activation,
       time_t expiration);
int gnutls_x509_crq_set_key_rsa_raw(gnutls_x509_crq_t crq,
        const gnutls_datum_t * m,
        const gnutls_datum_t * e);
int gnutls_x509_crq_set_subject_alt_name(gnutls_x509_crq_t crq,
      gnutls_x509_subject_alt_name_t
      nt, const void *data,
      unsigned int data_size,
      unsigned int flags);

int
gnutls_x509_crq_set_subject_alt_othername(gnutls_x509_crq_t crq,
         const char *oid,
         const void *data,
         unsigned int data_size,
         unsigned int flags);

int gnutls_x509_crq_set_key_usage(gnutls_x509_crq_t crq,
      unsigned int usage);
int gnutls_x509_crq_set_basic_constraints(gnutls_x509_crq_t crq,
       unsigned int ca,
       int pathLenConstraint);
int gnutls_x509_crq_set_key_purpose_oid(gnutls_x509_crq_t crq,
     const void *oid,
     unsigned int critical);
int gnutls_x509_crq_get_key_purpose_oid(gnutls_x509_crq_t crq,
     unsigned indx, void *oid,
     size_t * sizeof_oid,
     unsigned int *critical);

int gnutls_x509_crq_get_extension_data(gnutls_x509_crq_t crq,
           unsigned indx, void *data,
           size_t * sizeof_data);
int
gnutls_x509_crq_get_extension_data2(gnutls_x509_crq_t crq,
          unsigned indx,
          gnutls_datum_t * data);
int gnutls_x509_crq_get_extension_info(gnutls_x509_crq_t crq,
           unsigned indx, void *oid,
           size_t * sizeof_oid,
           unsigned int *critical);
int gnutls_x509_crq_get_attribute_data(gnutls_x509_crq_t crq,
           unsigned indx, void *data,
           size_t * sizeof_data);
int gnutls_x509_crq_get_attribute_info(gnutls_x509_crq_t crq,
           unsigned indx, void *oid,
           size_t * sizeof_oid);
int gnutls_x509_crq_get_pk_algorithm(gnutls_x509_crq_t crq,
         unsigned int *bits);
int gnutls_x509_crq_get_spki(gnutls_x509_crq_t crq, gnutls_x509_spki_t spki,
        unsigned int flags);

int gnutls_x509_crq_set_spki(gnutls_x509_crq_t crq, const gnutls_x509_spki_t spki,
        unsigned int flags);

int gnutls_x509_crq_get_signature_oid(gnutls_x509_crq_t crq, char *oid, size_t *oid_size);
int gnutls_x509_crq_get_pk_oid(gnutls_x509_crq_t crq, char *oid, size_t *oid_size);

int gnutls_x509_crq_get_key_id(gnutls_x509_crq_t crq,
          unsigned int flags,
          unsigned char *output_data,
          size_t * output_data_size);
int gnutls_x509_crq_get_key_rsa_raw(gnutls_x509_crq_t crq,
        gnutls_datum_t * m,
        gnutls_datum_t * e);

int gnutls_x509_crq_get_key_usage(gnutls_x509_crq_t crq,
      unsigned int *key_usage,
      unsigned int *critical);
int gnutls_x509_crq_get_basic_constraints(gnutls_x509_crq_t crq,
       unsigned int *critical,
       unsigned int *ca, int *pathlen);
int gnutls_x509_crq_get_subject_alt_name(gnutls_x509_crq_t crq,
      unsigned int seq,
      void *ret,
      size_t * ret_size,
      unsigned int *ret_type,
      unsigned int *critical);
int gnutls_x509_crq_get_subject_alt_othername_oid(gnutls_x509_crq_t
        crq,
        unsigned int seq,
        void *ret,
        size_t * ret_size);

int gnutls_x509_crq_get_extension_by_oid(gnutls_x509_crq_t crq,
      const char *oid, unsigned indx,
      void *buf,
      size_t * sizeof_buf,
      unsigned int *critical);

int gnutls_x509_crq_get_tlsfeatures(gnutls_x509_crq_t crq,
        gnutls_x509_tlsfeatures_t features,
        unsigned flags,
        unsigned int *critical);
int gnutls_x509_crq_set_tlsfeatures(gnutls_x509_crq_t crq,
        gnutls_x509_tlsfeatures_t features);

int
gnutls_x509_crt_get_extension_by_oid2(gnutls_x509_crt_t cert,
         const char *oid, unsigned indx,
         gnutls_datum_t *output,
         unsigned int *critical);

typedef struct gnutls_x509_trust_list_st *gnutls_x509_trust_list_t;
typedef struct gnutls_x509_trust_list_iter *gnutls_x509_trust_list_iter_t;

int
gnutls_x509_trust_list_init(gnutls_x509_trust_list_t * list,
       unsigned int size);

void
gnutls_x509_trust_list_deinit(gnutls_x509_trust_list_t list,
         unsigned int all);

int gnutls_x509_trust_list_get_issuer(gnutls_x509_trust_list_t
          list, gnutls_x509_crt_t cert,
          gnutls_x509_crt_t * issuer,
          unsigned int flags);

int gnutls_x509_trust_list_get_issuer_by_dn(gnutls_x509_trust_list_t list,
          const gnutls_datum_t *dn,
          gnutls_x509_crt_t *issuer,
          unsigned int flags);

int gnutls_x509_trust_list_get_issuer_by_subject_key_id(gnutls_x509_trust_list_t list,
          const gnutls_datum_t *dn,
          const gnutls_datum_t *spki,
          gnutls_x509_crt_t *issuer,
          unsigned int flags);
typedef enum gnutls_trust_list_flags_t {
 GNUTLS_TL_VERIFY_CRL = 1,

 GNUTLS_TL_USE_IN_TLS = (1<<1),

 GNUTLS_TL_NO_DUPLICATES = (1<<2),

 GNUTLS_TL_NO_DUPLICATE_KEY = (1<<3),

 GNUTLS_TL_GET_COPY = (1<<4),

 GNUTLS_TL_FAIL_ON_INVALID_CRL = (1<<5)

} gnutls_trust_list_flags_t;

int
gnutls_x509_trust_list_add_cas(gnutls_x509_trust_list_t list,
          const gnutls_x509_crt_t * clist,
          unsigned clist_size, unsigned int flags);
int gnutls_x509_trust_list_remove_cas(gnutls_x509_trust_list_t
          list,
          const gnutls_x509_crt_t *
          clist, unsigned clist_size);

int gnutls_x509_trust_list_add_named_crt(gnutls_x509_trust_list_t
      list,
      gnutls_x509_crt_t cert,
      const void *name,
      size_t name_size,
      unsigned int flags);

int
gnutls_x509_trust_list_add_crls(gnutls_x509_trust_list_t list,
    const gnutls_x509_crl_t *
    crl_list, unsigned crl_size,
    unsigned int flags,
    unsigned int verification_flags);


int
gnutls_x509_trust_list_iter_get_ca(gnutls_x509_trust_list_t list,
                                   gnutls_x509_trust_list_iter_t *iter,
                                   gnutls_x509_crt_t *crt);

void gnutls_x509_trust_list_iter_deinit(gnutls_x509_trust_list_iter_t iter);

typedef int gnutls_verify_output_function(gnutls_x509_crt_t cert, gnutls_x509_crt_t issuer,



       gnutls_x509_crl_t crl,


       unsigned int
       verification_output);

void gnutls_session_set_verify_output_function(gnutls_session_t session,
  gnutls_verify_output_function * func);

int gnutls_x509_trust_list_verify_named_crt
    (gnutls_x509_trust_list_t list, gnutls_x509_crt_t cert,
     const void *name, size_t name_size, unsigned int flags,
     unsigned int *verify, gnutls_verify_output_function func);

int
gnutls_x509_trust_list_verify_crt2(gnutls_x509_trust_list_t list,
      gnutls_x509_crt_t * cert_list,
      unsigned int cert_list_size,
      gnutls_typed_vdata_st * data,
      unsigned int elements,
      unsigned int flags,
      unsigned int *voutput,
      gnutls_verify_output_function func);

int
gnutls_x509_trust_list_verify_crt(gnutls_x509_trust_list_t list,
      gnutls_x509_crt_t * cert_list,
      unsigned int cert_list_size,
      unsigned int flags,
      unsigned int *verify,
      gnutls_verify_output_function func);


int
gnutls_x509_trust_list_add_trust_mem(gnutls_x509_trust_list_t
         list,
         const gnutls_datum_t * cas,
         const gnutls_datum_t * crls,
         gnutls_x509_crt_fmt_t type,
         unsigned int tl_flags,
         unsigned int tl_vflags);

int
gnutls_x509_trust_list_add_trust_file(gnutls_x509_trust_list_t
          list, const char *ca_file,
          const char *crl_file,
          gnutls_x509_crt_fmt_t type,
          unsigned int tl_flags,
          unsigned int tl_vflags);

int
gnutls_x509_trust_list_add_trust_dir(gnutls_x509_trust_list_t list,
          const char *ca_dir,
          const char *crl_dir,
          gnutls_x509_crt_fmt_t type,
          unsigned int tl_flags,
          unsigned int tl_vflags);

int
gnutls_x509_trust_list_remove_trust_file(gnutls_x509_trust_list_t
      list,
      const char *ca_file,
      gnutls_x509_crt_fmt_t type);

int
gnutls_x509_trust_list_remove_trust_mem(gnutls_x509_trust_list_t
     list,
     const gnutls_datum_t *
     cas, gnutls_x509_crt_fmt_t type);

int
gnutls_x509_trust_list_add_system_trust(gnutls_x509_trust_list_t
     list,
     unsigned int tl_flags,
     unsigned int tl_vflags);

typedef int gnutls_x509_trust_list_getissuer_function(gnutls_x509_trust_list_t list,
            const gnutls_x509_crt_t cert,
            gnutls_x509_crt_t **issuers,
            unsigned int *issuers_size);

void gnutls_x509_trust_list_set_getissuer_function(gnutls_x509_trust_list_t tlist,
    gnutls_x509_trust_list_getissuer_function *func);

void gnutls_x509_trust_list_set_ptr(gnutls_x509_trust_list_t tlist, void *ptr);

void *gnutls_x509_trust_list_get_ptr(gnutls_x509_trust_list_t tlist);

void gnutls_certificate_set_trust_list
    (gnutls_certificate_credentials_t res,
     gnutls_x509_trust_list_t tlist, unsigned flags);
void gnutls_certificate_get_trust_list
    (gnutls_certificate_credentials_t res,
     gnutls_x509_trust_list_t *tlist);

typedef struct gnutls_x509_ext_st {
 char *oid;
 unsigned int critical;
 gnutls_datum_t data;
} gnutls_x509_ext_st;

void gnutls_x509_ext_deinit(gnutls_x509_ext_st *ext);

int
gnutls_x509_ext_print(gnutls_x509_ext_st *exts, unsigned int exts_size,
        gnutls_certificate_print_formats_t format,
        gnutls_datum_t * out);

struct gnutls_pkcs7_int;
typedef struct gnutls_pkcs7_int *gnutls_pkcs7_t;

int gnutls_pkcs7_init(gnutls_pkcs7_t * pkcs7);
void gnutls_pkcs7_deinit(gnutls_pkcs7_t pkcs7);
int gnutls_pkcs7_import(gnutls_pkcs7_t pkcs7,
   const gnutls_datum_t * data,
   gnutls_x509_crt_fmt_t format);
int gnutls_pkcs7_export(gnutls_pkcs7_t pkcs7,
   gnutls_x509_crt_fmt_t format,
   void *output_data, size_t * output_data_size);
int gnutls_pkcs7_export2(gnutls_pkcs7_t pkcs7,
    gnutls_x509_crt_fmt_t format,
    gnutls_datum_t * out);

int gnutls_pkcs7_get_signature_count(gnutls_pkcs7_t pkcs7);


int gnutls_pkcs7_get_embedded_data(gnutls_pkcs7_t pkcs7, unsigned flags, gnutls_datum_t *data);

const char *
gnutls_pkcs7_get_embedded_data_oid(gnutls_pkcs7_t pkcs7);

int gnutls_pkcs7_get_crt_count(gnutls_pkcs7_t pkcs7);
int gnutls_pkcs7_get_crt_raw(gnutls_pkcs7_t pkcs7, unsigned indx,
        void *certificate, size_t * certificate_size);

int gnutls_pkcs7_set_crt_raw(gnutls_pkcs7_t pkcs7,
        const gnutls_datum_t * crt);
int gnutls_pkcs7_set_crt(gnutls_pkcs7_t pkcs7, gnutls_x509_crt_t crt);
int gnutls_pkcs7_delete_crt(gnutls_pkcs7_t pkcs7, int indx);

int gnutls_pkcs7_get_crl_raw(gnutls_pkcs7_t pkcs7,
        unsigned indx, void *crl, size_t * crl_size);
int gnutls_pkcs7_get_crl_count(gnutls_pkcs7_t pkcs7);

int gnutls_pkcs7_set_crl_raw(gnutls_pkcs7_t pkcs7,
        const gnutls_datum_t * crl);
int gnutls_pkcs7_set_crl(gnutls_pkcs7_t pkcs7, gnutls_x509_crl_t crl);
int gnutls_pkcs7_delete_crl(gnutls_pkcs7_t pkcs7, int indx);

typedef struct gnutls_pkcs7_attrs_st *gnutls_pkcs7_attrs_t;

typedef struct gnutls_pkcs7_signature_info_st {
 gnutls_sign_algorithm_t algo;
 gnutls_datum_t sig;
 gnutls_datum_t issuer_dn;
 gnutls_datum_t signer_serial;
 gnutls_datum_t issuer_keyid;
 time_t signing_time;
 gnutls_pkcs7_attrs_t signed_attrs;
 gnutls_pkcs7_attrs_t unsigned_attrs;
 char pad[64];
} gnutls_pkcs7_signature_info_st;

void gnutls_pkcs7_signature_info_deinit(gnutls_pkcs7_signature_info_st *info);
int gnutls_pkcs7_get_signature_info(gnutls_pkcs7_t pkcs7, unsigned idx, gnutls_pkcs7_signature_info_st *info);

int gnutls_pkcs7_verify_direct(gnutls_pkcs7_t pkcs7, gnutls_x509_crt_t signer,
          unsigned idx, const gnutls_datum_t *data, unsigned flags);
int gnutls_pkcs7_verify(gnutls_pkcs7_t pkcs7, gnutls_x509_trust_list_t tl,
   gnutls_typed_vdata_st * vdata, unsigned int vdata_size,
   unsigned idx, const gnutls_datum_t *data, unsigned flags);


int gnutls_pkcs7_add_attr(gnutls_pkcs7_attrs_t *list, const char *oid, gnutls_datum_t *data, unsigned flags);
void gnutls_pkcs7_attrs_deinit(gnutls_pkcs7_attrs_t list);
int gnutls_pkcs7_get_attr(gnutls_pkcs7_attrs_t list, unsigned idx, char **oid, gnutls_datum_t *data, unsigned flags);
typedef enum gnutls_pkcs7_sign_flags {
 GNUTLS_PKCS7_EMBED_DATA = 1,
 GNUTLS_PKCS7_INCLUDE_TIME = (1<<1),
 GNUTLS_PKCS7_INCLUDE_CERT = (1<<2),
 GNUTLS_PKCS7_WRITE_SPKI = (1<<3)
} gnutls_pkcs7_sign_flags;

int gnutls_pkcs7_sign(gnutls_pkcs7_t pkcs7,
        gnutls_x509_crt_t signer,
        gnutls_privkey_t signer_key,
        const gnutls_datum_t *data,
        gnutls_pkcs7_attrs_t signed_attrs,
        gnutls_pkcs7_attrs_t unsigned_attrs,
        gnutls_digest_algorithm_t dig,
        unsigned flags);

int
gnutls_pkcs7_get_crt_raw2(gnutls_pkcs7_t pkcs7,
     unsigned indx, gnutls_datum_t *cert);
int
gnutls_pkcs7_get_crl_raw2(gnutls_pkcs7_t pkcs7,
     unsigned indx, gnutls_datum_t *crl);

int gnutls_pkcs7_print(gnutls_pkcs7_t pkcs7,
         gnutls_certificate_print_formats_t format,
         gnutls_datum_t * out);

int gnutls_pkcs7_print_signature_info(gnutls_pkcs7_signature_info_st * info,
          gnutls_certificate_print_formats_t format,
          gnutls_datum_t * out);
       
       

typedef enum gnutls_openpgp_crt_fmt {
 GNUTLS_OPENPGP_FMT_RAW,
 GNUTLS_OPENPGP_FMT_BASE64
} gnutls_openpgp_crt_fmt_t;



typedef unsigned char
 gnutls_openpgp_keyid_t[8];





int gnutls_openpgp_crt_init(gnutls_openpgp_crt_t * key) ;

void gnutls_openpgp_crt_deinit(gnutls_openpgp_crt_t key) ;

int gnutls_openpgp_crt_import(gnutls_openpgp_crt_t key,
         const gnutls_datum_t * data,
         gnutls_openpgp_crt_fmt_t format) ;
int gnutls_openpgp_crt_export(gnutls_openpgp_crt_t key,
         gnutls_openpgp_crt_fmt_t format,
         void *output_data,
         size_t * output_data_size) ;
int gnutls_openpgp_crt_export2(gnutls_openpgp_crt_t key,
          gnutls_openpgp_crt_fmt_t format,
          gnutls_datum_t * out) ;

int gnutls_openpgp_crt_print(gnutls_openpgp_crt_t cert,
        gnutls_certificate_print_formats_t
        format, gnutls_datum_t * out) ;






int gnutls_openpgp_crt_get_key_usage(gnutls_openpgp_crt_t key,
         unsigned int *key_usage) ;
int gnutls_openpgp_crt_get_fingerprint(gnutls_openpgp_crt_t key,
           void *fpr, size_t * fprlen) ;
int gnutls_openpgp_crt_get_subkey_fingerprint(gnutls_openpgp_crt_t
           key,
           unsigned int idx,
           void *fpr, size_t * fprlen) ;

int gnutls_openpgp_crt_get_name(gnutls_openpgp_crt_t key,
    int idx, char *buf, size_t * sizeof_buf) ;

gnutls_pk_algorithm_t
gnutls_openpgp_crt_get_pk_algorithm(gnutls_openpgp_crt_t key,
        unsigned int *bits) ;

int gnutls_openpgp_crt_get_version(gnutls_openpgp_crt_t key) ;

time_t gnutls_openpgp_crt_get_creation_time(gnutls_openpgp_crt_t key) ;
time_t gnutls_openpgp_crt_get_expiration_time(gnutls_openpgp_crt_t key) ;

int gnutls_openpgp_crt_get_key_id(gnutls_openpgp_crt_t key,
      gnutls_openpgp_keyid_t keyid) ;

int gnutls_openpgp_crt_check_hostname(gnutls_openpgp_crt_t key,
          const char *hostname) ;
int gnutls_openpgp_crt_check_hostname2(gnutls_openpgp_crt_t key,
          const char *hostname, unsigned int flags) ;
int
gnutls_openpgp_crt_check_email(gnutls_openpgp_crt_t key, const char *email, unsigned flags) ;

int gnutls_openpgp_crt_get_revoked_status(gnutls_openpgp_crt_t key) ;

int gnutls_openpgp_crt_get_subkey_count(gnutls_openpgp_crt_t key) ;
int gnutls_openpgp_crt_get_subkey_idx(gnutls_openpgp_crt_t key,
          const gnutls_openpgp_keyid_t keyid) ;
int gnutls_openpgp_crt_get_subkey_revoked_status
    (gnutls_openpgp_crt_t key, unsigned int idx) ;
gnutls_pk_algorithm_t
gnutls_openpgp_crt_get_subkey_pk_algorithm(gnutls_openpgp_crt_t
        key,
        unsigned int idx,
        unsigned int *bits) ;
time_t
    gnutls_openpgp_crt_get_subkey_creation_time
    (gnutls_openpgp_crt_t key, unsigned int idx) ;
time_t
    gnutls_openpgp_crt_get_subkey_expiration_time
    (gnutls_openpgp_crt_t key, unsigned int idx) ;
int gnutls_openpgp_crt_get_subkey_id(gnutls_openpgp_crt_t key,
         unsigned int idx,
         gnutls_openpgp_keyid_t keyid) ;
int gnutls_openpgp_crt_get_subkey_usage(gnutls_openpgp_crt_t key,
     unsigned int idx,
     unsigned int *key_usage) ;

int gnutls_openpgp_crt_get_subkey_pk_dsa_raw(gnutls_openpgp_crt_t
          crt, unsigned int idx,
          gnutls_datum_t * p,
          gnutls_datum_t * q,
          gnutls_datum_t * g,
          gnutls_datum_t * y) ;
int gnutls_openpgp_crt_get_subkey_pk_rsa_raw(gnutls_openpgp_crt_t
          crt, unsigned int idx,
          gnutls_datum_t * m,
          gnutls_datum_t * e) ;
int gnutls_openpgp_crt_get_pk_dsa_raw(gnutls_openpgp_crt_t crt,
          gnutls_datum_t * p,
          gnutls_datum_t * q,
          gnutls_datum_t * g,
          gnutls_datum_t * y) ;
int gnutls_openpgp_crt_get_pk_rsa_raw(gnutls_openpgp_crt_t crt,
          gnutls_datum_t * m,
          gnutls_datum_t * e) ;

int gnutls_openpgp_crt_get_preferred_key_id(gnutls_openpgp_crt_t
         key,
         gnutls_openpgp_keyid_t keyid) ;
int
gnutls_openpgp_crt_set_preferred_key_id(gnutls_openpgp_crt_t key,
     const
     gnutls_openpgp_keyid_t keyid) ;



int gnutls_openpgp_privkey_init(gnutls_openpgp_privkey_t * key) ;
void gnutls_openpgp_privkey_deinit(gnutls_openpgp_privkey_t key) ;
gnutls_pk_algorithm_t
    gnutls_openpgp_privkey_get_pk_algorithm
    (gnutls_openpgp_privkey_t key, unsigned int *bits) ;

gnutls_sec_param_t
gnutls_openpgp_privkey_sec_param(gnutls_openpgp_privkey_t key) ;
int gnutls_openpgp_privkey_import(gnutls_openpgp_privkey_t key,
      const gnutls_datum_t * data,
      gnutls_openpgp_crt_fmt_t format,
      const char *password,
      unsigned int flags) ;

int gnutls_openpgp_privkey_get_fingerprint(gnutls_openpgp_privkey_t
        key, void *fpr,
        size_t * fprlen) ;
int gnutls_openpgp_privkey_get_subkey_fingerprint
    (gnutls_openpgp_privkey_t key, unsigned int idx, void *fpr,
     size_t * fprlen) ;
int gnutls_openpgp_privkey_get_key_id(gnutls_openpgp_privkey_t key,
          gnutls_openpgp_keyid_t keyid) ;
int gnutls_openpgp_privkey_get_subkey_count(gnutls_openpgp_privkey_t key) ;
int gnutls_openpgp_privkey_get_subkey_idx(gnutls_openpgp_privkey_t
       key,
       const
       gnutls_openpgp_keyid_t keyid) ;

int gnutls_openpgp_privkey_get_subkey_revoked_status
    (gnutls_openpgp_privkey_t key, unsigned int idx) ;

int gnutls_openpgp_privkey_get_revoked_status
    (gnutls_openpgp_privkey_t key) ;

gnutls_pk_algorithm_t
    gnutls_openpgp_privkey_get_subkey_pk_algorithm
    (gnutls_openpgp_privkey_t key, unsigned int idx, unsigned int *bits) ;

time_t
    gnutls_openpgp_privkey_get_subkey_expiration_time
    (gnutls_openpgp_privkey_t key, unsigned int idx) ;

int gnutls_openpgp_privkey_get_subkey_id(gnutls_openpgp_privkey_t
      key, unsigned int idx,
      gnutls_openpgp_keyid_t keyid) ;

time_t
    gnutls_openpgp_privkey_get_subkey_creation_time
    (gnutls_openpgp_privkey_t key, unsigned int idx) ;

int gnutls_openpgp_privkey_export_subkey_dsa_raw
    (gnutls_openpgp_privkey_t pkey, unsigned int idx,
     gnutls_datum_t * p, gnutls_datum_t * q, gnutls_datum_t * g,
     gnutls_datum_t * y, gnutls_datum_t * x) ;
int gnutls_openpgp_privkey_export_subkey_rsa_raw
    (gnutls_openpgp_privkey_t pkey, unsigned int idx,
     gnutls_datum_t * m, gnutls_datum_t * e, gnutls_datum_t * d,
     gnutls_datum_t * p, gnutls_datum_t * q, gnutls_datum_t * u) ;

int gnutls_openpgp_privkey_export_dsa_raw(gnutls_openpgp_privkey_t
       pkey, gnutls_datum_t * p,
       gnutls_datum_t * q,
       gnutls_datum_t * g,
       gnutls_datum_t * y,
       gnutls_datum_t * x) ;
int gnutls_openpgp_privkey_export_rsa_raw(gnutls_openpgp_privkey_t
       pkey, gnutls_datum_t * m,
       gnutls_datum_t * e,
       gnutls_datum_t * d,
       gnutls_datum_t * p,
       gnutls_datum_t * q,
       gnutls_datum_t * u) ;

int gnutls_openpgp_privkey_export(gnutls_openpgp_privkey_t key,
      gnutls_openpgp_crt_fmt_t format,
      const char *password,
      unsigned int flags,
      void *output_data,
      size_t * output_data_size) ;
int gnutls_openpgp_privkey_export2(gnutls_openpgp_privkey_t key,
       gnutls_openpgp_crt_fmt_t format,
       const char *password,
       unsigned int flags,
       gnutls_datum_t * out) ;

int gnutls_openpgp_privkey_set_preferred_key_id
    (gnutls_openpgp_privkey_t key, const gnutls_openpgp_keyid_t keyid) ;
int gnutls_openpgp_privkey_get_preferred_key_id
    (gnutls_openpgp_privkey_t key, gnutls_openpgp_keyid_t keyid) ;

int gnutls_openpgp_crt_get_auth_subkey(gnutls_openpgp_crt_t crt,
           gnutls_openpgp_keyid_t
           keyid, unsigned int flag) ;




int gnutls_openpgp_keyring_init(gnutls_openpgp_keyring_t * keyring) ;
void gnutls_openpgp_keyring_deinit(gnutls_openpgp_keyring_t keyring) ;

int gnutls_openpgp_keyring_import(gnutls_openpgp_keyring_t keyring,
      const gnutls_datum_t * data,
      gnutls_openpgp_crt_fmt_t format) ;

int gnutls_openpgp_keyring_check_id(gnutls_openpgp_keyring_t ring,
        const gnutls_openpgp_keyid_t
        keyid, unsigned int flags) ;


int gnutls_openpgp_crt_verify_ring(gnutls_openpgp_crt_t key,
       gnutls_openpgp_keyring_t
       keyring, unsigned int flags,
       unsigned int *verify

    ) ;

int gnutls_openpgp_crt_verify_self(gnutls_openpgp_crt_t key,
       unsigned int flags,
       unsigned int *verify) ;

int gnutls_openpgp_keyring_get_crt(gnutls_openpgp_keyring_t ring,
       unsigned int idx,
       gnutls_openpgp_crt_t * cert) ;

int gnutls_openpgp_keyring_get_crt_count(gnutls_openpgp_keyring_t ring) ;
typedef int (*gnutls_openpgp_recv_key_func) (gnutls_session_t
          session,
          const unsigned char
          *keyfpr,
          unsigned int
          keyfpr_length,
          gnutls_datum_t * key);

void
gnutls_openpgp_set_recv_key_function(gnutls_session_t session,
         gnutls_openpgp_recv_key_func func) ;





int gnutls_certificate_set_openpgp_key
    (gnutls_certificate_credentials_t res,
     gnutls_openpgp_crt_t crt, gnutls_openpgp_privkey_t pkey) ;

int
gnutls_certificate_get_openpgp_key(gnutls_certificate_credentials_t res,
                                   unsigned index,
                                   gnutls_openpgp_privkey_t *key) ;
int
gnutls_certificate_get_openpgp_crt(gnutls_certificate_credentials_t res,
                                   unsigned index,
                                   gnutls_openpgp_crt_t **crt_list,
                                   unsigned *crt_list_size) ;

int
 gnutls_certificate_set_openpgp_key_file
    (gnutls_certificate_credentials_t res, const char *certfile,
     const char *keyfile, gnutls_openpgp_crt_fmt_t format) ;
int gnutls_certificate_set_openpgp_key_mem
    (gnutls_certificate_credentials_t res,
     const gnutls_datum_t * cert, const gnutls_datum_t * key,
     gnutls_openpgp_crt_fmt_t format) ;

int
 gnutls_certificate_set_openpgp_key_file2
    (gnutls_certificate_credentials_t res, const char *certfile,
     const char *keyfile, const char *subkey_id,
     gnutls_openpgp_crt_fmt_t format) ;
int
 gnutls_certificate_set_openpgp_key_mem2
    (gnutls_certificate_credentials_t res,
     const gnutls_datum_t * cert, const gnutls_datum_t * key,
     const char *subkey_id, gnutls_openpgp_crt_fmt_t format) ;

int gnutls_certificate_set_openpgp_keyring_mem
    (gnutls_certificate_credentials_t c, const unsigned char *data,
     size_t dlen, gnutls_openpgp_crt_fmt_t format) ;

int gnutls_certificate_set_openpgp_keyring_file
    (gnutls_certificate_credentials_t c, const char *file,
     gnutls_openpgp_crt_fmt_t format) ;
struct gnutls_pkcs12_int;
typedef struct gnutls_pkcs12_int *gnutls_pkcs12_t;

struct gnutls_pkcs12_bag_int;
typedef struct gnutls_pkcs12_bag_int *gnutls_pkcs12_bag_t;

int gnutls_pkcs12_init(gnutls_pkcs12_t * pkcs12);
void gnutls_pkcs12_deinit(gnutls_pkcs12_t pkcs12);
int gnutls_pkcs12_import(gnutls_pkcs12_t pkcs12,
    const gnutls_datum_t * data,
    gnutls_x509_crt_fmt_t format, unsigned int flags);
int gnutls_pkcs12_export(gnutls_pkcs12_t pkcs12,
    gnutls_x509_crt_fmt_t format,
    void *output_data, size_t * output_data_size);
int gnutls_pkcs12_export2(gnutls_pkcs12_t pkcs12,
     gnutls_x509_crt_fmt_t format,
     gnutls_datum_t * out);

int gnutls_pkcs12_get_bag(gnutls_pkcs12_t pkcs12,
     int indx, gnutls_pkcs12_bag_t bag);
int gnutls_pkcs12_set_bag(gnutls_pkcs12_t pkcs12, gnutls_pkcs12_bag_t bag);

int gnutls_pkcs12_generate_mac(gnutls_pkcs12_t pkcs12, const char *pass);
int gnutls_pkcs12_generate_mac2(gnutls_pkcs12_t pkcs12, gnutls_mac_algorithm_t mac, const char *pass);
int gnutls_pkcs12_verify_mac(gnutls_pkcs12_t pkcs12, const char *pass);

int gnutls_pkcs12_bag_decrypt(gnutls_pkcs12_bag_t bag, const char *pass);
int gnutls_pkcs12_bag_encrypt(gnutls_pkcs12_bag_t bag,
         const char *pass, unsigned int flags);

int
gnutls_pkcs12_bag_enc_info(gnutls_pkcs12_bag_t bag, unsigned int *schema, unsigned int *cipher,
 void *salt, unsigned int *salt_size, unsigned int *iter_count, char **oid);
int
gnutls_pkcs12_mac_info(gnutls_pkcs12_t pkcs12, unsigned int *mac,
 void *salt, unsigned int *salt_size, unsigned int *iter_count, char **oid);


int gnutls_pkcs12_simple_parse(gnutls_pkcs12_t p12,
          const char *password,
          gnutls_x509_privkey_t * key,
          gnutls_x509_crt_t ** chain,
          unsigned int *chain_len,
          gnutls_x509_crt_t ** extra_certs,
          unsigned int *extra_certs_len,
          gnutls_x509_crl_t * crl,
          unsigned int flags);
typedef enum gnutls_pkcs12_bag_type_t {
 GNUTLS_BAG_EMPTY = 0,
 GNUTLS_BAG_PKCS8_ENCRYPTED_KEY = 1,
 GNUTLS_BAG_PKCS8_KEY = 2,
 GNUTLS_BAG_CERTIFICATE = 3,
 GNUTLS_BAG_CRL = 4,
 GNUTLS_BAG_SECRET = 5,




 GNUTLS_BAG_ENCRYPTED = 10,
 GNUTLS_BAG_UNKNOWN = 20
} gnutls_pkcs12_bag_type_t;

int
gnutls_pkcs12_bag_get_type(gnutls_pkcs12_bag_t bag, unsigned indx);
int gnutls_pkcs12_bag_get_data(gnutls_pkcs12_bag_t bag, unsigned indx,
          gnutls_datum_t * data);
int gnutls_pkcs12_bag_set_data(gnutls_pkcs12_bag_t bag,
          gnutls_pkcs12_bag_type_t type,
          const gnutls_datum_t * data);
int gnutls_pkcs12_bag_set_crl(gnutls_pkcs12_bag_t bag,
         gnutls_x509_crl_t crl);
int gnutls_pkcs12_bag_set_crt(gnutls_pkcs12_bag_t bag,
         gnutls_x509_crt_t crt);

int
gnutls_pkcs12_bag_set_privkey(gnutls_pkcs12_bag_t bag,
         gnutls_x509_privkey_t privkey,
         const char *password, unsigned flags);

int gnutls_pkcs12_bag_init(gnutls_pkcs12_bag_t * bag);
void gnutls_pkcs12_bag_deinit(gnutls_pkcs12_bag_t bag);
int gnutls_pkcs12_bag_get_count(gnutls_pkcs12_bag_t bag);

int gnutls_pkcs12_bag_get_key_id(gnutls_pkcs12_bag_t bag, unsigned indx,
     gnutls_datum_t * id);
int gnutls_pkcs12_bag_set_key_id(gnutls_pkcs12_bag_t bag, unsigned indx,
     const gnutls_datum_t * id);

int gnutls_pkcs12_bag_get_friendly_name(gnutls_pkcs12_bag_t bag,
     unsigned indx, char **name);
int gnutls_pkcs12_bag_set_friendly_name(gnutls_pkcs12_bag_t bag,
     unsigned indx, const char *name);

typedef int (*gnutls_pkcs11_token_callback_t) (void *const
            userdata,
            const char *const
            label, unsigned retry);


struct gnutls_pkcs11_obj_st;
typedef struct gnutls_pkcs11_obj_st *gnutls_pkcs11_obj_t;
int gnutls_pkcs11_init(unsigned int flags,
         const char *deprecated_config_file);
int gnutls_pkcs11_reinit(void);
void gnutls_pkcs11_deinit(void);
void gnutls_pkcs11_set_token_function
    (gnutls_pkcs11_token_callback_t fn, void *userdata);

void gnutls_pkcs11_set_pin_function(gnutls_pin_callback_t fn,
        void *userdata);

gnutls_pin_callback_t gnutls_pkcs11_get_pin_function(void
           **userdata);

int gnutls_pkcs11_add_provider(const char *name, const char *params);
int gnutls_pkcs11_obj_init(gnutls_pkcs11_obj_t * obj);
void gnutls_pkcs11_obj_set_pin_function(gnutls_pkcs11_obj_t obj,
     gnutls_pin_callback_t fn,
     void *userdata);
typedef enum gnutls_pkcs11_obj_flags {
 GNUTLS_PKCS11_OBJ_FLAG_LOGIN = (1<<0),
 GNUTLS_PKCS11_OBJ_FLAG_MARK_TRUSTED = (1<<1),
 GNUTLS_PKCS11_OBJ_FLAG_MARK_SENSITIVE = (1<<2),
 GNUTLS_PKCS11_OBJ_FLAG_LOGIN_SO = (1<<3),
 GNUTLS_PKCS11_OBJ_FLAG_MARK_PRIVATE = (1<<4),
 GNUTLS_PKCS11_OBJ_FLAG_MARK_NOT_PRIVATE = (1<<5),
 GNUTLS_PKCS11_OBJ_FLAG_RETRIEVE_ANY = (1<<6),
 GNUTLS_PKCS11_OBJ_FLAG_RETRIEVE_TRUSTED = GNUTLS_PKCS11_OBJ_FLAG_MARK_TRUSTED,
 GNUTLS_PKCS11_OBJ_FLAG_MARK_DISTRUSTED = (1<<8),
 GNUTLS_PKCS11_OBJ_FLAG_RETRIEVE_DISTRUSTED = GNUTLS_PKCS11_OBJ_FLAG_MARK_DISTRUSTED,
 GNUTLS_PKCS11_OBJ_FLAG_COMPARE = (1<<9),
 GNUTLS_PKCS11_OBJ_FLAG_PRESENT_IN_TRUSTED_MODULE = (1<<10),
 GNUTLS_PKCS11_OBJ_FLAG_MARK_CA = (1<<11),
 GNUTLS_PKCS11_OBJ_FLAG_MARK_KEY_WRAP = (1<<12),
 GNUTLS_PKCS11_OBJ_FLAG_COMPARE_KEY = (1<<13),
 GNUTLS_PKCS11_OBJ_FLAG_OVERWRITE_TRUSTMOD_EXT = (1<<14),
 GNUTLS_PKCS11_OBJ_FLAG_MARK_ALWAYS_AUTH = (1<<15),
 GNUTLS_PKCS11_OBJ_FLAG_MARK_EXTRACTABLE = (1<<16),
 GNUTLS_PKCS11_OBJ_FLAG_NEVER_EXTRACTABLE = (1<<17),
 GNUTLS_PKCS11_OBJ_FLAG_CRT = (1<<18),
 GNUTLS_PKCS11_OBJ_FLAG_WITH_PRIVKEY = (1<<19),
 GNUTLS_PKCS11_OBJ_FLAG_PUBKEY = (1<<20),
 GNUTLS_PKCS11_OBJ_FLAG_NO_STORE_PUBKEY = GNUTLS_PKCS11_OBJ_FLAG_PUBKEY,
 GNUTLS_PKCS11_OBJ_FLAG_PRIVKEY = (1<<21),
 GNUTLS_PKCS11_OBJ_FLAG_MARK_NOT_SENSITIVE = (1<<22),

} gnutls_pkcs11_obj_flags;
typedef enum {
 GNUTLS_PKCS11_URL_GENERIC,
 GNUTLS_PKCS11_URL_LIB,
 GNUTLS_PKCS11_URL_LIB_VERSION
} gnutls_pkcs11_url_type_t;

int gnutls_pkcs11_obj_import_url(gnutls_pkcs11_obj_t obj,
     const char *url, unsigned int flags
                                    );
int gnutls_pkcs11_obj_export_url(gnutls_pkcs11_obj_t obj,
     gnutls_pkcs11_url_type_t detailed,
     char **url);
void gnutls_pkcs11_obj_deinit(gnutls_pkcs11_obj_t obj);

int gnutls_pkcs11_obj_export(gnutls_pkcs11_obj_t obj,
        void *output_data, size_t * output_data_size);
int gnutls_pkcs11_obj_export2(gnutls_pkcs11_obj_t obj,
         gnutls_datum_t * out);

int gnutls_pkcs11_obj_export3(gnutls_pkcs11_obj_t obj, gnutls_x509_crt_fmt_t fmt,
         gnutls_datum_t * out);

int gnutls_pkcs11_get_raw_issuer(const char *url, gnutls_x509_crt_t cert,
        gnutls_datum_t * issuer,
        gnutls_x509_crt_fmt_t fmt,
        unsigned int flags);

int gnutls_pkcs11_get_raw_issuer_by_dn (const char *url, const gnutls_datum_t *dn,
     gnutls_datum_t *issuer,
     gnutls_x509_crt_fmt_t fmt,
     unsigned int flags);

int gnutls_pkcs11_get_raw_issuer_by_subject_key_id (const char *url,
     const gnutls_datum_t *dn,
     const gnutls_datum_t *spki,
     gnutls_datum_t *issuer,
     gnutls_x509_crt_fmt_t fmt,
     unsigned int flags);

unsigned gnutls_pkcs11_crt_is_known(const char *url, gnutls_x509_crt_t cert,
        unsigned int flags);
int
gnutls_pkcs11_copy_pubkey(const char *token_url,
     gnutls_pubkey_t crt, const char *label,
     const gnutls_datum_t *cid,
     unsigned int key_usage, unsigned int flags);




int gnutls_pkcs11_copy_x509_crt2(const char *token_url,
    gnutls_x509_crt_t crt,
    const char *label,
    const gnutls_datum_t *id,
    unsigned int flags );



int gnutls_pkcs11_copy_x509_privkey2(const char *token_url,
        gnutls_x509_privkey_t key,
        const char *label,
        const gnutls_datum_t *cid,
        unsigned int key_usage
                          ,
        unsigned int flags

);

int gnutls_pkcs11_delete_url(const char *object_url, unsigned int flags
                                       );

int gnutls_pkcs11_copy_secret_key(const char *token_url,
      gnutls_datum_t * key,
      const char *label, unsigned int key_usage
                         ,
      unsigned int flags
                                     );
typedef enum {
 GNUTLS_PKCS11_OBJ_ID_HEX = 1,
 GNUTLS_PKCS11_OBJ_LABEL,
 GNUTLS_PKCS11_OBJ_TOKEN_LABEL,
 GNUTLS_PKCS11_OBJ_TOKEN_SERIAL,
 GNUTLS_PKCS11_OBJ_TOKEN_MANUFACTURER,
 GNUTLS_PKCS11_OBJ_TOKEN_MODEL,
 GNUTLS_PKCS11_OBJ_ID,

 GNUTLS_PKCS11_OBJ_LIBRARY_VERSION,
 GNUTLS_PKCS11_OBJ_LIBRARY_DESCRIPTION,
 GNUTLS_PKCS11_OBJ_LIBRARY_MANUFACTURER
} gnutls_pkcs11_obj_info_t;

int
gnutls_pkcs11_obj_get_ptr(gnutls_pkcs11_obj_t obj, void **ptr,
     void **session, void **ohandle,
     unsigned long *slot_id,
     unsigned int flags);

int gnutls_pkcs11_obj_get_info(gnutls_pkcs11_obj_t obj,
          gnutls_pkcs11_obj_info_t itype,
          void *output, size_t * output_size);
int gnutls_pkcs11_obj_set_info(gnutls_pkcs11_obj_t obj,
          gnutls_pkcs11_obj_info_t itype,
          const void *data, size_t data_size,
          unsigned flags);
typedef enum {
 GNUTLS_PKCS11_TOKEN_LABEL,
 GNUTLS_PKCS11_TOKEN_SERIAL,
 GNUTLS_PKCS11_TOKEN_MANUFACTURER,
 GNUTLS_PKCS11_TOKEN_MODEL,
 GNUTLS_PKCS11_TOKEN_MODNAME
} gnutls_pkcs11_token_info_t;
typedef enum {
 GNUTLS_PKCS11_OBJ_UNKNOWN,
 GNUTLS_PKCS11_OBJ_X509_CRT,
 GNUTLS_PKCS11_OBJ_PUBKEY,
 GNUTLS_PKCS11_OBJ_PRIVKEY,
 GNUTLS_PKCS11_OBJ_SECRET_KEY,
 GNUTLS_PKCS11_OBJ_DATA,
 GNUTLS_PKCS11_OBJ_X509_CRT_EXTENSION
} gnutls_pkcs11_obj_type_t;

int
gnutls_pkcs11_token_init(const char *token_url,
    const char *so_pin, const char *label);

int
gnutls_pkcs11_token_get_ptr(const char *url, void **ptr, unsigned long *slot_id,
       unsigned int flags);

int
gnutls_pkcs11_token_get_mechanism(const char *url,
      unsigned int idx,
      unsigned long *mechanism);

unsigned
gnutls_pkcs11_token_check_mechanism(const char *url,
        unsigned long mechanism,
        void *ptr, unsigned psize, unsigned flags);

int gnutls_pkcs11_token_set_pin(const char *token_url, const char *oldpin, const char *newpin, unsigned int flags );

int gnutls_pkcs11_token_get_url(unsigned int seq,
    gnutls_pkcs11_url_type_t detailed,
    char **url);
int gnutls_pkcs11_token_get_info(const char *url,
     gnutls_pkcs11_token_info_t ttype,
     void *output, size_t * output_size);
int gnutls_pkcs11_token_get_flags(const char *url, unsigned int *flags);




int gnutls_pkcs11_obj_list_import_url3(gnutls_pkcs11_obj_t * p_list,
          unsigned int *const n_list,
          const char *url,
          unsigned int flags

    );

int
gnutls_pkcs11_obj_list_import_url4(gnutls_pkcs11_obj_t ** p_list,
       unsigned int *n_list,
       const char *url,
       unsigned int flags

    );

int gnutls_x509_crt_import_pkcs11(gnutls_x509_crt_t crt,
      gnutls_pkcs11_obj_t pkcs11_crt);

gnutls_pkcs11_obj_type_t
gnutls_pkcs11_obj_get_type(gnutls_pkcs11_obj_t obj);
const char *gnutls_pkcs11_type_get_name(gnutls_pkcs11_obj_type_t type);

int
gnutls_pkcs11_obj_get_exts(gnutls_pkcs11_obj_t obj,
      struct gnutls_x509_ext_st **exts, unsigned int *exts_size,
      unsigned int flags);

int
gnutls_pkcs11_obj_get_flags(gnutls_pkcs11_obj_t obj, unsigned int *oflags);
char *gnutls_pkcs11_obj_flags_get_str(unsigned int flags);

int gnutls_x509_crt_list_import_pkcs11(gnutls_x509_crt_t * certs,
           unsigned int cert_max,
           gnutls_pkcs11_obj_t *
           const objs, unsigned int flags
                              );


int gnutls_pkcs11_privkey_init(gnutls_pkcs11_privkey_t * key);

int
gnutls_pkcs11_privkey_cpy(gnutls_pkcs11_privkey_t dst,
     gnutls_pkcs11_privkey_t src);

void gnutls_pkcs11_privkey_set_pin_function(gnutls_pkcs11_privkey_t
         key,
         gnutls_pin_callback_t
         fn, void *userdata);
void gnutls_pkcs11_privkey_deinit(gnutls_pkcs11_privkey_t key);
int gnutls_pkcs11_privkey_get_pk_algorithm(gnutls_pkcs11_privkey_t
        key, unsigned int *bits);
int gnutls_pkcs11_privkey_get_info(gnutls_pkcs11_privkey_t pkey,
       gnutls_pkcs11_obj_info_t itype,
       void *output, size_t * output_size);

int gnutls_pkcs11_privkey_import_url(gnutls_pkcs11_privkey_t pkey,
         const char *url, unsigned int flags);

int gnutls_pkcs11_privkey_export_url(gnutls_pkcs11_privkey_t key,
         gnutls_pkcs11_url_type_t
         detailed, char **url);
unsigned gnutls_pkcs11_privkey_status(gnutls_pkcs11_privkey_t key);







int
gnutls_pkcs11_privkey_generate3(const char *url,
    gnutls_pk_algorithm_t pk,
    unsigned int bits,
    const char *label,
    const gnutls_datum_t *cid,
    gnutls_x509_crt_fmt_t fmt,
    gnutls_datum_t * pubkey,
    unsigned int key_usage,
    unsigned int flags);

int
gnutls_pkcs11_privkey_export_pubkey(gnutls_pkcs11_privkey_t pkey,
         gnutls_x509_crt_fmt_t fmt,
         gnutls_datum_t * pubkey,
         unsigned int flags);

int
gnutls_pkcs11_token_get_random(const char *token_url,
          void *data, size_t len);

int
gnutls_pkcs11_copy_attached_extension(const char *token_url,
          gnutls_x509_crt_t crt,
          gnutls_datum_t *data,
          const char *label,
          unsigned int flags);
struct tpm_key_list_st;
typedef struct tpm_key_list_st *gnutls_tpm_key_list_t;
typedef enum {
 GNUTLS_TPMKEY_FMT_RAW = 0,
 GNUTLS_TPMKEY_FMT_DER = GNUTLS_TPMKEY_FMT_RAW,
 GNUTLS_TPMKEY_FMT_CTK_PEM = 1
} gnutls_tpmkey_fmt_t;

int
gnutls_tpm_privkey_generate(gnutls_pk_algorithm_t pk,
       unsigned int bits,
       const char *srk_password,
       const char *key_password,
       gnutls_tpmkey_fmt_t format,
       gnutls_x509_crt_fmt_t pub_format,
       gnutls_datum_t * privkey,
       gnutls_datum_t * pubkey, unsigned int flags);

void gnutls_tpm_key_list_deinit(gnutls_tpm_key_list_t list);
int gnutls_tpm_key_list_get_url(gnutls_tpm_key_list_t list,
    unsigned int idx, char **url,
    unsigned int flags);
int gnutls_tpm_get_registered(gnutls_tpm_key_list_t * list);
int gnutls_tpm_privkey_delete(const char *url, const char *srk_password);
typedef enum gnutls_pubkey_flags {
 GNUTLS_PUBKEY_DISABLE_CALLBACKS = 1 << 2,
 GNUTLS_PUBKEY_GET_OPENPGP_FINGERPRINT = 1 << 3
} gnutls_pubkey_flags_t;







typedef enum gnutls_abstract_export_flags {
 GNUTLS_EXPORT_FLAG_NO_LZ = 1
} gnutls_abstract_export_flags_t;



typedef int (*gnutls_privkey_sign_func) (gnutls_privkey_t key,
      void *userdata,
      const gnutls_datum_t *raw_data,
      gnutls_datum_t * signature);


typedef int (*gnutls_privkey_decrypt_func) (gnutls_privkey_t key,
         void *userdata,
         const gnutls_datum_t *ciphertext,
         gnutls_datum_t * plaintext);

typedef int (*gnutls_privkey_decrypt_func2) (gnutls_privkey_t key,
          void *userdata,
          const gnutls_datum_t *ciphertext,
          unsigned char * plaintext,
          size_t plaintext_size);







typedef int (*gnutls_privkey_sign_hash_func) (gnutls_privkey_t key,
           gnutls_sign_algorithm_t algo,
           void *userdata,
           unsigned int flags,
           const gnutls_datum_t *hash,
           gnutls_datum_t * signature);






typedef int (*gnutls_privkey_sign_data_func) (gnutls_privkey_t key,
           gnutls_sign_algorithm_t algo,
           void *userdata,
           unsigned int flags,
           const gnutls_datum_t *data,
           gnutls_datum_t * signature);

typedef void (*gnutls_privkey_deinit_func) (gnutls_privkey_t key,
         void *userdata);
typedef int (*gnutls_privkey_info_func) (gnutls_privkey_t key, unsigned int flags, void *userdata);

int gnutls_pubkey_init(gnutls_pubkey_t * key);
void gnutls_pubkey_deinit(gnutls_pubkey_t key);

int gnutls_pubkey_verify_params(gnutls_pubkey_t key);

void gnutls_pubkey_set_pin_function(gnutls_pubkey_t key,
        gnutls_pin_callback_t fn,
        void *userdata);

int gnutls_pubkey_get_pk_algorithm(gnutls_pubkey_t key,
       unsigned int *bits);

int
gnutls_pubkey_set_spki(gnutls_pubkey_t key,
   const gnutls_x509_spki_t spki,
   unsigned int flags);

int
gnutls_pubkey_get_spki(gnutls_pubkey_t key,
   const gnutls_x509_spki_t spki,
   unsigned int flags);

int gnutls_pubkey_import_x509(gnutls_pubkey_t key,
         gnutls_x509_crt_t crt, unsigned int flags);
int gnutls_pubkey_import_x509_crq(gnutls_pubkey_t key,
      gnutls_x509_crq_t crq,
      unsigned int flags);
int gnutls_pubkey_import_pkcs11(gnutls_pubkey_t key,
    gnutls_pkcs11_obj_t obj,
    unsigned int flags);
int gnutls_pubkey_import_openpgp(gnutls_pubkey_t key,
     gnutls_openpgp_crt_t crt,
     unsigned int flags);

int gnutls_pubkey_import_openpgp_raw(gnutls_pubkey_t pkey,
         const gnutls_datum_t * data,
         gnutls_openpgp_crt_fmt_t
         format,
         const gnutls_openpgp_keyid_t
         keyid, unsigned int flags);
int gnutls_pubkey_import_x509_raw(gnutls_pubkey_t pkey,
      const gnutls_datum_t * data,
      gnutls_x509_crt_fmt_t format,
      unsigned int flags);

int
gnutls_pubkey_import_privkey(gnutls_pubkey_t key,
        gnutls_privkey_t pkey,
        unsigned int usage, unsigned int flags);

int
gnutls_pubkey_import_tpm_url(gnutls_pubkey_t pkey,
        const char *url,
        const char *srk_password, unsigned int flags);

int
gnutls_pubkey_import_url(gnutls_pubkey_t key, const char *url,
    unsigned int flags);

int
gnutls_pubkey_import_tpm_raw(gnutls_pubkey_t pkey,
        const gnutls_datum_t * fdata,
        gnutls_tpmkey_fmt_t format,
        const char *srk_password, unsigned int flags);

int gnutls_pubkey_get_preferred_hash_algorithm(gnutls_pubkey_t key,
            gnutls_digest_algorithm_t
            * hash, unsigned int *mand);


int gnutls_pubkey_export_rsa_raw(gnutls_pubkey_t key,
     gnutls_datum_t * m, gnutls_datum_t * e);

int gnutls_pubkey_export_rsa_raw2(gnutls_pubkey_t key,
      gnutls_datum_t * m, gnutls_datum_t * e,
      unsigned flags);


int gnutls_pubkey_export_dsa_raw(gnutls_pubkey_t key,
     gnutls_datum_t * p,
     gnutls_datum_t * q,
     gnutls_datum_t * g, gnutls_datum_t * y);

int gnutls_pubkey_export_dsa_raw2(gnutls_pubkey_t key,
     gnutls_datum_t * p,
     gnutls_datum_t * q,
     gnutls_datum_t * g, gnutls_datum_t * y,
     unsigned flags);

int gnutls_pubkey_export_ecc_raw2(gnutls_pubkey_t key,
     gnutls_ecc_curve_t * curve,
     gnutls_datum_t * x, gnutls_datum_t * y,
     unsigned flags);

int gnutls_pubkey_export_gost_raw2(gnutls_pubkey_t key,
       gnutls_ecc_curve_t * curve,
       gnutls_digest_algorithm_t * digest,
       gnutls_gost_paramset_t * paramset,
       gnutls_datum_t * x, gnutls_datum_t * y,
       unsigned int flags);


int gnutls_pubkey_export_ecc_raw(gnutls_pubkey_t key,
     gnutls_ecc_curve_t * curve,
     gnutls_datum_t * x, gnutls_datum_t * y);


int gnutls_pubkey_export_ecc_x962(gnutls_pubkey_t key,
      gnutls_datum_t * parameters,
      gnutls_datum_t * ecpoint);

int gnutls_pubkey_export(gnutls_pubkey_t key,
    gnutls_x509_crt_fmt_t format,
    void *output_data, size_t * output_data_size);

int gnutls_pubkey_export2(gnutls_pubkey_t key,
     gnutls_x509_crt_fmt_t format,
     gnutls_datum_t * out);

int gnutls_pubkey_get_key_id(gnutls_pubkey_t key,
        unsigned int flags,
        unsigned char *output_data,
        size_t * output_data_size);

int
gnutls_pubkey_get_openpgp_key_id(gnutls_pubkey_t key,
     unsigned int flags,
     unsigned char *output_data,
     size_t * output_data_size,
     unsigned int *subkey);

int gnutls_pubkey_get_key_usage(gnutls_pubkey_t key, unsigned int *usage);
int gnutls_pubkey_set_key_usage(gnutls_pubkey_t key, unsigned int usage);

int gnutls_pubkey_import(gnutls_pubkey_t key,
    const gnutls_datum_t * data,
    gnutls_x509_crt_fmt_t format);




int gnutls_pubkey_import_dsa_raw(gnutls_pubkey_t key,
     const gnutls_datum_t * p,
     const gnutls_datum_t * q,
     const gnutls_datum_t * g,
     const gnutls_datum_t * y);
int gnutls_pubkey_import_rsa_raw(gnutls_pubkey_t key,
     const gnutls_datum_t * m,
     const gnutls_datum_t * e);

int
gnutls_pubkey_import_ecc_x962(gnutls_pubkey_t key,
         const gnutls_datum_t * parameters,
         const gnutls_datum_t * ecpoint);

int
gnutls_pubkey_import_ecc_raw(gnutls_pubkey_t key,
        gnutls_ecc_curve_t curve,
        const gnutls_datum_t * x,
        const gnutls_datum_t * y);

int
gnutls_pubkey_import_gost_raw(gnutls_pubkey_t key,
        gnutls_ecc_curve_t curve,
        gnutls_digest_algorithm_t digest,
        gnutls_gost_paramset_t paramset,
        const gnutls_datum_t * x,
        const gnutls_datum_t * y);

int
gnutls_pubkey_encrypt_data(gnutls_pubkey_t key,
      unsigned int flags,
      const gnutls_datum_t * plaintext,
      gnutls_datum_t * ciphertext);

int gnutls_x509_crt_set_pubkey(gnutls_x509_crt_t crt, gnutls_pubkey_t key);

int gnutls_x509_crq_set_pubkey(gnutls_x509_crq_t crq, gnutls_pubkey_t key);

int
gnutls_pubkey_verify_hash2(gnutls_pubkey_t key,
      gnutls_sign_algorithm_t algo,
      unsigned int flags,
      const gnutls_datum_t * hash,
      const gnutls_datum_t * signature);

int
gnutls_pubkey_verify_data2(gnutls_pubkey_t pubkey,
      gnutls_sign_algorithm_t algo,
      unsigned int flags,
      const gnutls_datum_t * data,
      const gnutls_datum_t * signature);



int gnutls_privkey_init(gnutls_privkey_t * key);
void gnutls_privkey_deinit(gnutls_privkey_t key);
int
gnutls_privkey_generate (gnutls_privkey_t key,
                         gnutls_pk_algorithm_t algo, unsigned int bits,
                         unsigned int flags);
int
gnutls_privkey_generate2(gnutls_privkey_t pkey,
    gnutls_pk_algorithm_t algo, unsigned int bits,
    unsigned int flags, const gnutls_keygen_data_st *data, unsigned data_size);

int
gnutls_privkey_set_spki(gnutls_privkey_t key,
   const gnutls_x509_spki_t spki,
   unsigned int flags);

int
gnutls_privkey_get_spki(gnutls_privkey_t key,
   const gnutls_x509_spki_t spki,
   unsigned int flags);

int gnutls_privkey_verify_seed(gnutls_privkey_t key, gnutls_digest_algorithm_t, const void *seed, size_t seed_size);
int gnutls_privkey_get_seed(gnutls_privkey_t key, gnutls_digest_algorithm_t*, void *seed, size_t *seed_size);

int gnutls_privkey_verify_params(gnutls_privkey_t key);

void gnutls_privkey_set_flags(gnutls_privkey_t key, unsigned int flags);

void gnutls_privkey_set_pin_function (gnutls_privkey_t key,
                                      gnutls_pin_callback_t fn, void *userdata);

int gnutls_privkey_get_pk_algorithm(gnutls_privkey_t key,
        unsigned int *bits);
gnutls_privkey_type_t gnutls_privkey_get_type(gnutls_privkey_t key);
int gnutls_privkey_status(gnutls_privkey_t key);
typedef enum gnutls_privkey_flags {
 GNUTLS_PRIVKEY_IMPORT_AUTO_RELEASE = 1,
 GNUTLS_PRIVKEY_IMPORT_COPY = 1 << 1,
 GNUTLS_PRIVKEY_DISABLE_CALLBACKS = 1 << 2,
 GNUTLS_PRIVKEY_SIGN_FLAG_TLS1_RSA = 1 << 4,
 GNUTLS_PRIVKEY_FLAG_PROVABLE = 1 << 5,
 GNUTLS_PRIVKEY_FLAG_EXPORT_COMPAT = 1 << 6,
 GNUTLS_PRIVKEY_SIGN_FLAG_RSA_PSS = 1 << 7,
 GNUTLS_PRIVKEY_FLAG_REPRODUCIBLE = 1 << 8,
 GNUTLS_PRIVKEY_FLAG_CA = 1 << 9,
 GNUTLS_PRIVKEY_FLAG_RSA_PSS_FIXED_SALT_LENGTH = 1 << 10
} gnutls_privkey_flags_t;

int gnutls_privkey_import_pkcs11(gnutls_privkey_t pkey,
     gnutls_pkcs11_privkey_t key,
     unsigned int flags);
int gnutls_privkey_import_x509(gnutls_privkey_t pkey,
          gnutls_x509_privkey_t key,
          unsigned int flags);
int gnutls_privkey_import_openpgp(gnutls_privkey_t pkey,
      gnutls_openpgp_privkey_t key,
      unsigned int flags);

int gnutls_privkey_export_x509(gnutls_privkey_t pkey,
                               gnutls_x509_privkey_t * key);
int gnutls_privkey_export_openpgp(gnutls_privkey_t pkey,
                                  gnutls_openpgp_privkey_t * key);
int
gnutls_privkey_export_pkcs11(gnutls_privkey_t pkey,
                             gnutls_pkcs11_privkey_t *key);

int gnutls_privkey_import_openpgp_raw(gnutls_privkey_t pkey,
          const gnutls_datum_t * data,
          gnutls_openpgp_crt_fmt_t
          format,
          const gnutls_openpgp_keyid_t
          keyid, const char *password);

int gnutls_privkey_import_x509_raw(gnutls_privkey_t pkey,
       const gnutls_datum_t * data,
       gnutls_x509_crt_fmt_t format,
       const char *password,
       unsigned int flags);

int
gnutls_privkey_import_tpm_raw(gnutls_privkey_t pkey,
         const gnutls_datum_t * fdata,
         gnutls_tpmkey_fmt_t format,
         const char *srk_password,
         const char *key_password,
         unsigned int flags);

int
gnutls_privkey_import_tpm_url(gnutls_privkey_t pkey,
         const char *url,
         const char *srk_password,
         const char *key_password,
         unsigned int flags);

int gnutls_privkey_import_url(gnutls_privkey_t key,
         const char *url, unsigned int flags);
int
gnutls_privkey_import_ext(gnutls_privkey_t pkey,
     gnutls_pk_algorithm_t pk,
     void *userdata,
     gnutls_privkey_sign_func sign_func,
     gnutls_privkey_decrypt_func
     decrypt_func, unsigned int flags);

int
gnutls_privkey_import_ext2(gnutls_privkey_t pkey,
      gnutls_pk_algorithm_t pk,
      void *userdata,
      gnutls_privkey_sign_func sign_func,
      gnutls_privkey_decrypt_func
      decrypt_func,
      gnutls_privkey_deinit_func deinit_func,
      unsigned int flags);

int
gnutls_privkey_import_ext3(gnutls_privkey_t pkey,
                           void *userdata,
                           gnutls_privkey_sign_func sign_func,
                           gnutls_privkey_decrypt_func decrypt_func,
                           gnutls_privkey_deinit_func deinit_func,
                           gnutls_privkey_info_func info_func,
                           unsigned int flags);

int
gnutls_privkey_import_ext4(gnutls_privkey_t pkey,
                           void *userdata,
                           gnutls_privkey_sign_data_func sign_data_func,
                           gnutls_privkey_sign_hash_func sign_hash_func,
                           gnutls_privkey_decrypt_func decrypt_func,
                           gnutls_privkey_deinit_func deinit_func,
                           gnutls_privkey_info_func info_func,
                           unsigned int flags);

int gnutls_privkey_import_dsa_raw(gnutls_privkey_t key,
           const gnutls_datum_t * p,
           const gnutls_datum_t * q,
           const gnutls_datum_t * g,
           const gnutls_datum_t * y,
           const gnutls_datum_t * x);

int gnutls_privkey_import_rsa_raw(gnutls_privkey_t key,
     const gnutls_datum_t * m,
     const gnutls_datum_t * e,
     const gnutls_datum_t * d,
     const gnutls_datum_t * p,
     const gnutls_datum_t * q,
     const gnutls_datum_t * u,
     const gnutls_datum_t * e1,
     const gnutls_datum_t * e2);
int gnutls_privkey_import_ecc_raw(gnutls_privkey_t key,
           gnutls_ecc_curve_t curve,
           const gnutls_datum_t * x,
           const gnutls_datum_t * y,
           const gnutls_datum_t * k);

int gnutls_privkey_import_gost_raw(gnutls_privkey_t key,
           gnutls_ecc_curve_t curve,
           gnutls_digest_algorithm_t digest,
           gnutls_gost_paramset_t paramset,
           const gnutls_datum_t * x,
           const gnutls_datum_t * y,
           const gnutls_datum_t * k);


int gnutls_privkey_sign_data(gnutls_privkey_t signer,
        gnutls_digest_algorithm_t hash,
        unsigned int flags,
        const gnutls_datum_t * data,
        gnutls_datum_t * signature);

int gnutls_privkey_sign_data2(gnutls_privkey_t signer,
         gnutls_sign_algorithm_t algo,
         unsigned int flags,
         const gnutls_datum_t * data,
         gnutls_datum_t * signature);




int gnutls_privkey_sign_hash(gnutls_privkey_t signer,
        gnutls_digest_algorithm_t hash_algo,
        unsigned int flags,
        const gnutls_datum_t * hash_data,
        gnutls_datum_t * signature);

int gnutls_privkey_sign_hash2(gnutls_privkey_t signer,
         gnutls_sign_algorithm_t algo,
         unsigned int flags,
         const gnutls_datum_t * hash_data,
         gnutls_datum_t * signature);

int gnutls_privkey_decrypt_data(gnutls_privkey_t key,
    unsigned int flags,
    const gnutls_datum_t * ciphertext,
    gnutls_datum_t * plaintext);

int gnutls_privkey_decrypt_data2(gnutls_privkey_t key,
     unsigned int flags,
     const gnutls_datum_t * ciphertext,
     unsigned char * plaintext,
                                 size_t plaintext_size);

int
gnutls_privkey_export_rsa_raw(gnutls_privkey_t key,
        gnutls_datum_t * m, gnutls_datum_t * e,
        gnutls_datum_t * d, gnutls_datum_t * p,
        gnutls_datum_t * q, gnutls_datum_t * u,
        gnutls_datum_t * e1,
        gnutls_datum_t * e2);

int
gnutls_privkey_export_rsa_raw2(gnutls_privkey_t key,
        gnutls_datum_t * m, gnutls_datum_t * e,
        gnutls_datum_t * d, gnutls_datum_t * p,
        gnutls_datum_t * q, gnutls_datum_t * u,
        gnutls_datum_t * e1,
        gnutls_datum_t * e2, unsigned flags);

int
gnutls_privkey_export_dsa_raw(gnutls_privkey_t key,
        gnutls_datum_t * p, gnutls_datum_t * q,
        gnutls_datum_t * g, gnutls_datum_t * y,
        gnutls_datum_t * x);

int
gnutls_privkey_export_dsa_raw2(gnutls_privkey_t key,
        gnutls_datum_t * p, gnutls_datum_t * q,
        gnutls_datum_t * g, gnutls_datum_t * y,
        gnutls_datum_t * x, unsigned flags);

int
gnutls_privkey_export_ecc_raw(gnutls_privkey_t key,
           gnutls_ecc_curve_t * curve,
           gnutls_datum_t * x,
           gnutls_datum_t * y,
           gnutls_datum_t * k);

int
gnutls_privkey_export_ecc_raw2(gnutls_privkey_t key,
           gnutls_ecc_curve_t * curve,
           gnutls_datum_t * x,
           gnutls_datum_t * y,
           gnutls_datum_t * k,
           unsigned flags);

int
gnutls_privkey_export_gost_raw2(gnutls_privkey_t key,
           gnutls_ecc_curve_t * curve,
           gnutls_digest_algorithm_t * digest,
           gnutls_gost_paramset_t * paramset,
           gnutls_datum_t * x,
           gnutls_datum_t * y,
           gnutls_datum_t * k,
           unsigned flags);


int gnutls_x509_crt_privkey_sign(gnutls_x509_crt_t crt,
     gnutls_x509_crt_t issuer,
     gnutls_privkey_t issuer_key,
     gnutls_digest_algorithm_t dig,
     unsigned int flags);

int gnutls_x509_crl_privkey_sign(gnutls_x509_crl_t crl,
     gnutls_x509_crt_t issuer,
     gnutls_privkey_t issuer_key,
     gnutls_digest_algorithm_t dig,
     unsigned int flags);

int gnutls_x509_crq_privkey_sign(gnutls_x509_crq_t crq,
     gnutls_privkey_t key,
     gnutls_digest_algorithm_t dig,
     unsigned int flags);
typedef struct gnutls_pcert_st {
 gnutls_pubkey_t pubkey;
 gnutls_datum_t cert;
 gnutls_certificate_type_t type;
} gnutls_pcert_st;




int gnutls_pcert_import_x509(gnutls_pcert_st * pcert,
        gnutls_x509_crt_t crt, unsigned int flags);

int gnutls_pcert_import_x509_list(gnutls_pcert_st * pcert,
      gnutls_x509_crt_t *crt, unsigned *ncrt,
      unsigned int flags);

int gnutls_pcert_export_x509(gnutls_pcert_st * pcert,
                             gnutls_x509_crt_t * crt);

int
gnutls_pcert_list_import_x509_raw(gnutls_pcert_st * pcerts,
      unsigned int *pcert_max,
      const gnutls_datum_t * data,
      gnutls_x509_crt_fmt_t format,
      unsigned int flags);

int gnutls_pcert_list_import_x509_file(gnutls_pcert_st *pcert_list,
           unsigned *pcert_list_size,
           const char *file,
           gnutls_x509_crt_fmt_t format,
           gnutls_pin_callback_t pin_fn,
           void *pin_fn_userdata,
           unsigned int flags);

int gnutls_pcert_import_x509_raw(gnutls_pcert_st * pcert,
     const gnutls_datum_t * cert,
     gnutls_x509_crt_fmt_t format,
     unsigned int flags);

int gnutls_pcert_import_openpgp_raw(gnutls_pcert_st * pcert,
        const gnutls_datum_t * cert,
        gnutls_openpgp_crt_fmt_t
        format,
        gnutls_openpgp_keyid_t keyid,
        unsigned int flags);

int gnutls_pcert_import_openpgp(gnutls_pcert_st * pcert,
    gnutls_openpgp_crt_t crt,
    unsigned int flags);

int gnutls_pcert_export_openpgp(gnutls_pcert_st * pcert,
                                gnutls_openpgp_crt_t * crt);

void gnutls_pcert_deinit(gnutls_pcert_st * pcert);

int gnutls_pcert_import_rawpk(gnutls_pcert_st* pcert,
        gnutls_pubkey_t key, unsigned int flags);

int gnutls_pcert_import_rawpk_raw(gnutls_pcert_st* pcert,
        const gnutls_datum_t* rawpubkey,
        gnutls_x509_crt_fmt_t format,
        unsigned int key_usage, unsigned int flags);






typedef int gnutls_certificate_retrieve_function2(gnutls_session_t,
      const gnutls_datum_t *req_ca_rdn,
      int nreqs,
      const gnutls_pk_algorithm_t *pk_algos,
      int pk_algos_length,
      gnutls_pcert_st**,
      unsigned int *pcert_length,
      gnutls_privkey_t *privkey);


void gnutls_certificate_set_retrieve_function2
    (gnutls_certificate_credentials_t cred,
     gnutls_certificate_retrieve_function2 *func);

struct gnutls_cert_retr_st {
 unsigned version;
 gnutls_certificate_credentials_t cred;
 const gnutls_datum_t *req_ca_rdn;
 unsigned nreqs;
 const gnutls_pk_algorithm_t *pk_algos;
 unsigned pk_algos_length;


 unsigned char padding[64];
};





typedef int gnutls_certificate_retrieve_function3(
    gnutls_session_t,
    const struct gnutls_cert_retr_st *info,
    gnutls_pcert_st **certs,
    unsigned int *certs_length,
    gnutls_ocsp_data_st **ocsp,
    unsigned int *ocsp_length,
    gnutls_privkey_t *privkey,
    unsigned int *flags);


void gnutls_certificate_set_retrieve_function3
    (gnutls_certificate_credentials_t cred,
     gnutls_certificate_retrieve_function3 *func);

int
gnutls_certificate_set_key(gnutls_certificate_credentials_t res,
      const char **names,
      int names_size,
      gnutls_pcert_st * pcert_list,
      int pcert_list_size, gnutls_privkey_t key);

int
gnutls_pubkey_print(gnutls_pubkey_t pubkey,
      gnutls_certificate_print_formats_t format,
      gnutls_datum_t * out);
typedef struct api_cipher_hd_st *gnutls_cipher_hd_t;

int gnutls_cipher_init(gnutls_cipher_hd_t * handle,
         gnutls_cipher_algorithm_t cipher,
         const gnutls_datum_t * key,
         const gnutls_datum_t * iv);
int gnutls_cipher_encrypt(const gnutls_cipher_hd_t handle,
     void *text, size_t textlen);
int gnutls_cipher_decrypt(const gnutls_cipher_hd_t handle,
     void *ciphertext, size_t ciphertextlen);
int gnutls_cipher_decrypt2(gnutls_cipher_hd_t handle,
      const void *ciphertext,
      size_t ciphertextlen, void *text,
      size_t textlen);
int gnutls_cipher_encrypt2(gnutls_cipher_hd_t handle,
      const void *text, size_t textlen,
      void *ciphertext, size_t ciphertextlen);
typedef enum gnutls_cipher_flags_t {
 GNUTLS_CIPHER_PADDING_PKCS7 = 1
} gnutls_cipher_flags_t;

int gnutls_cipher_encrypt3(gnutls_cipher_hd_t handle,
      const void *ptext, size_t ptext_len,
      void *ctext, size_t *ctext_len,
      unsigned flags);
int gnutls_cipher_decrypt3(gnutls_cipher_hd_t handle,
      const void *ctext, size_t ctext_len,
      void *ptext, size_t *ptext_len,
      unsigned flags);

void gnutls_cipher_set_iv(gnutls_cipher_hd_t handle, void *iv,
     size_t ivlen);

int gnutls_cipher_tag(gnutls_cipher_hd_t handle, void *tag,
        size_t tag_size);
int gnutls_cipher_add_auth(gnutls_cipher_hd_t handle,
      const void *text, size_t text_size);

void gnutls_cipher_deinit(gnutls_cipher_hd_t handle);
unsigned gnutls_cipher_get_block_size(gnutls_cipher_algorithm_t algorithm) __attribute__((const));
unsigned gnutls_cipher_get_iv_size(gnutls_cipher_algorithm_t algorithm) __attribute__((const));
unsigned gnutls_cipher_get_tag_size(gnutls_cipher_algorithm_t algorithm) __attribute__((const));



typedef struct api_aead_cipher_hd_st *gnutls_aead_cipher_hd_t;

int gnutls_aead_cipher_init(gnutls_aead_cipher_hd_t * handle,
       gnutls_cipher_algorithm_t cipher,
       const gnutls_datum_t * key);

int gnutls_aead_cipher_set_key(gnutls_aead_cipher_hd_t handle,
          const gnutls_datum_t *key);

int
gnutls_aead_cipher_decrypt(gnutls_aead_cipher_hd_t handle,
      const void *nonce, size_t nonce_len,
      const void *auth, size_t auth_len,
      size_t tag_size,
      const void *ctext, size_t ctext_len,
      void *ptext, size_t *ptext_len);
int
gnutls_aead_cipher_encrypt(gnutls_aead_cipher_hd_t handle,
      const void *nonce, size_t nonce_len,
      const void *auth, size_t auth_len,
      size_t tag_size,
      const void *ptext, size_t ptext_len,
      void *ctext, size_t *ctext_len);

int
gnutls_aead_cipher_encryptv(gnutls_aead_cipher_hd_t handle,
       const void *nonce, size_t nonce_len,
       const giovec_t *auth_iov, int auth_iovcnt,
       size_t tag_size,
       const giovec_t *iov, int iovcnt,
       void *ctext, size_t *ctext_len);

int
gnutls_aead_cipher_encryptv2(gnutls_aead_cipher_hd_t handle,
        const void *nonce, size_t nonce_len,
        const giovec_t *auth_iov, int auth_iovcnt,
        const giovec_t *iov, int iovcnt,
        void *tag, size_t *tag_size);

int
gnutls_aead_cipher_decryptv2(gnutls_aead_cipher_hd_t handle,
        const void *nonce, size_t nonce_len,
        const giovec_t *auth_iov, int auth_iovcnt,
        const giovec_t *iov, int iovcnt,
        void *tag, size_t tag_size);

void gnutls_aead_cipher_deinit(gnutls_aead_cipher_hd_t handle);



typedef struct hash_hd_st *gnutls_hash_hd_t;
typedef struct hmac_hd_st *gnutls_hmac_hd_t;

size_t gnutls_mac_get_nonce_size(gnutls_mac_algorithm_t algorithm) __attribute__((const));
int gnutls_hmac_init(gnutls_hmac_hd_t * dig,
       gnutls_mac_algorithm_t algorithm,
       const void *key, size_t keylen);
void gnutls_hmac_set_nonce(gnutls_hmac_hd_t handle,
      const void *nonce, size_t nonce_len);
int gnutls_hmac(gnutls_hmac_hd_t handle, const void *text, size_t textlen);
void gnutls_hmac_output(gnutls_hmac_hd_t handle, void *digest);
void gnutls_hmac_deinit(gnutls_hmac_hd_t handle, void *digest);
unsigned gnutls_hmac_get_len(gnutls_mac_algorithm_t algorithm) __attribute__((const));
unsigned gnutls_hmac_get_key_size(gnutls_mac_algorithm_t algorithm) __attribute__((const));
int gnutls_hmac_fast(gnutls_mac_algorithm_t algorithm,
       const void *key, size_t keylen,
       const void *text, size_t textlen, void *digest);
gnutls_hmac_hd_t gnutls_hmac_copy(gnutls_hmac_hd_t handle);

int gnutls_hash_init(gnutls_hash_hd_t * dig,
       gnutls_digest_algorithm_t algorithm);
int gnutls_hash(gnutls_hash_hd_t handle, const void *text, size_t textlen);
void gnutls_hash_output(gnutls_hash_hd_t handle, void *digest);
void gnutls_hash_deinit(gnutls_hash_hd_t handle, void *digest);
unsigned gnutls_hash_get_len(gnutls_digest_algorithm_t algorithm) __attribute__((const));
int gnutls_hash_fast(gnutls_digest_algorithm_t algorithm,
       const void *text, size_t textlen, void *digest);
gnutls_hash_hd_t gnutls_hash_copy(gnutls_hash_hd_t handle);



int gnutls_hkdf_extract(gnutls_mac_algorithm_t mac,
   const gnutls_datum_t *key,
   const gnutls_datum_t *salt,
   void *output);

int gnutls_hkdf_expand(gnutls_mac_algorithm_t mac,
         const gnutls_datum_t *key,
         const gnutls_datum_t *info,
         void *output, size_t length);

int gnutls_pbkdf2(gnutls_mac_algorithm_t mac,
    const gnutls_datum_t *key,
    const gnutls_datum_t *salt,
    unsigned iter_count,
    void *output, size_t length);
typedef enum gnutls_rnd_level {
 GNUTLS_RND_NONCE = 0,
 GNUTLS_RND_RANDOM = 1,
 GNUTLS_RND_KEY = 2
} gnutls_rnd_level_t;

int gnutls_rnd(gnutls_rnd_level_t level, void *data, size_t len);

void gnutls_rnd_refresh(void);





typedef int (*gnutls_cipher_init_func) (gnutls_cipher_algorithm_t, void **ctx, int enc);
typedef int (*gnutls_cipher_setkey_func) (void *ctx, const void *key, size_t keysize);

typedef int (*gnutls_cipher_setiv_func) (void *ctx, const void *iv, size_t ivsize);
typedef int (*gnutls_cipher_getiv_func) (void *ctx, void *iv, size_t ivsize);
typedef int (*gnutls_cipher_encrypt_func) (void *ctx, const void *plain, size_t plainsize,
    void *encr, size_t encrsize);
typedef int (*gnutls_cipher_decrypt_func) (void *ctx, const void *encr, size_t encrsize,
   void *plain, size_t plainsize);


typedef int (*gnutls_cipher_auth_func) (void *ctx, const void *data, size_t datasize);
typedef void (*gnutls_cipher_tag_func) (void *ctx, void *tag, size_t tagsize);

typedef int (*gnutls_cipher_aead_encrypt_func) (void *ctx,
   const void *nonce, size_t noncesize,
   const void *auth, size_t authsize,
   size_t tag_size,
   const void *plain, size_t plainsize,
   void *encr, size_t encrsize);
typedef int (*gnutls_cipher_aead_decrypt_func) (void *ctx,
   const void *nonce, size_t noncesize,
   const void *auth, size_t authsize,
   size_t tag_size,
   const void *encr, size_t encrsize,
   void *plain, size_t plainsize);
typedef void (*gnutls_cipher_deinit_func) (void *ctx);

int
gnutls_crypto_register_cipher(gnutls_cipher_algorithm_t algorithm,
         int priority,
         gnutls_cipher_init_func init,
         gnutls_cipher_setkey_func setkey,
         gnutls_cipher_setiv_func setiv,
         gnutls_cipher_encrypt_func encrypt,
         gnutls_cipher_decrypt_func decrypt,
         gnutls_cipher_deinit_func deinit)
         ;

int
gnutls_crypto_register_aead_cipher(gnutls_cipher_algorithm_t algorithm,
         int priority,
         gnutls_cipher_init_func init,
         gnutls_cipher_setkey_func setkey,
         gnutls_cipher_aead_encrypt_func aead_encrypt,
         gnutls_cipher_aead_decrypt_func aead_decrypt,
         gnutls_cipher_deinit_func deinit)
         ;

typedef int (*gnutls_mac_init_func) (gnutls_mac_algorithm_t, void **ctx);
typedef int (*gnutls_mac_setkey_func) (void *ctx, const void *key, size_t keysize);
typedef int (*gnutls_mac_setnonce_func) (void *ctx, const void *nonce, size_t noncesize);
typedef int (*gnutls_mac_hash_func) (void *ctx, const void *text, size_t textsize);
typedef int (*gnutls_mac_output_func) (void *src_ctx, void *digest, size_t digestsize);
typedef void (*gnutls_mac_deinit_func) (void *ctx);
typedef int (*gnutls_mac_fast_func) (gnutls_mac_algorithm_t, const void *nonce,
       size_t nonce_size, const void *key, size_t keysize,
       const void *text, size_t textsize, void *digest);
typedef void *(*gnutls_mac_copy_func) (const void *ctx);

int
gnutls_crypto_register_mac(gnutls_mac_algorithm_t mac,
      int priority,
      gnutls_mac_init_func init,
      gnutls_mac_setkey_func setkey,
      gnutls_mac_setnonce_func setnonce,
      gnutls_mac_hash_func hash,
      gnutls_mac_output_func output,
      gnutls_mac_deinit_func deinit,
      gnutls_mac_fast_func hash_fast)
      ;

typedef int (*gnutls_digest_init_func) (gnutls_digest_algorithm_t, void **ctx);
typedef int (*gnutls_digest_hash_func) (void *ctx, const void *text, size_t textsize);
typedef int (*gnutls_digest_output_func) (void *src_ctx, void *digest, size_t digestsize);
typedef void (*gnutls_digest_deinit_func) (void *ctx);
typedef int (*gnutls_digest_fast_func) (gnutls_digest_algorithm_t,
       const void *text, size_t textsize, void *digest);
typedef void *(*gnutls_digest_copy_func) (const void *ctx);

int
gnutls_crypto_register_digest(gnutls_digest_algorithm_t digest,
      int priority,
      gnutls_digest_init_func init,
      gnutls_digest_hash_func hash,
      gnutls_digest_output_func output,
      gnutls_digest_deinit_func deinit,
      gnutls_digest_fast_func hash_fast)
      ;


int
gnutls_encode_ber_digest_info(gnutls_digest_algorithm_t hash,
         const gnutls_datum_t * digest,
         gnutls_datum_t * output);

int
gnutls_decode_ber_digest_info(const gnutls_datum_t * info,
         gnutls_digest_algorithm_t *hash,
         unsigned char *digest, unsigned int *digest_size);

int gnutls_decode_rs_value(const gnutls_datum_t * sig_value, gnutls_datum_t *r, gnutls_datum_t *s);
int gnutls_encode_rs_value(gnutls_datum_t * sig_value, const gnutls_datum_t * r, const gnutls_datum_t * s);

int gnutls_encode_gost_rs_value(gnutls_datum_t * sig_value, const gnutls_datum_t * r, const gnutls_datum_t *s);
int gnutls_decode_gost_rs_value(const gnutls_datum_t * sig_value, gnutls_datum_t * r, gnutls_datum_t * s);

       




       
extern int _gl_cxxalias_dummy;




extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                   ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                             ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                        ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                       ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                          ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                            ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                          ;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy


                                          ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                          ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                     ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                           ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                                   ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                   ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                              ;


extern int _gl_cxxalias_dummy;
       
       





extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                        ;



extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                        ;



extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;



extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                         ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                     ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
       
       







extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                 ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                                             ;



extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                          ;
extern int _gl_cxxalias_dummy

                                                              ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                     ;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                             ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
       
       
       

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                               ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                               ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;



       
       
       


       


extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
       
       
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int rpl_fcntl (int fd, int action, ...);
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;




extern int _gl_cxxalias_dummy;

       
       








       








extern char *_gnutls_fread_file (FILE * stream, int flags, size_t * length);

extern char *_gnutls_read_file (const char *filename, int flags, size_t * length);




void cfg_init(void);
int template_parse(const char *template);

void read_crt_set(gnutls_x509_crt_t crt, const char *input_str,
    const char *oid);
void read_crq_set(gnutls_x509_crq_t crq, const char *input_str,
    const char *oid);
int64_t read_int(const char *input_str);
int serial_decode(const char *input, gnutls_datum_t *output);
const char *read_str(const char *input_str);
int read_yesno(const char *input_str, int def);

const char *get_pass(void);
const char *get_confirmed_pass(
                              _Bool 
                                   empty_ok);
const char *get_challenge_pass(void);
void get_crl_dist_point_set(gnutls_x509_crt_t crt);
void crt_constraints_set(gnutls_x509_crt_t crt);
void get_country_crt_set(gnutls_x509_crt_t crt);
void get_organization_crt_set(gnutls_x509_crt_t crt);
void get_unit_crt_set(gnutls_x509_crt_t crt);
void get_state_crt_set(gnutls_x509_crt_t crt);
void get_locality_crt_set(gnutls_x509_crt_t crt);
void get_cn_crt_set(gnutls_x509_crt_t crt);
void get_dn_crt_set(gnutls_x509_crt_t crt);
void get_dn_crq_set(gnutls_x509_crq_t crt);
void get_uid_crt_set(gnutls_x509_crt_t crt);
void get_pkcs9_email_crt_set(gnutls_x509_crt_t crt);
void get_oid_crt_set(gnutls_x509_crt_t crt);
void get_key_purpose_set(int type, void *crt);
void get_serial(unsigned char* serial, size_t* serial_size);
time_t get_expiration_date(void);
time_t get_activation_date(void);
int get_ca_status(void);
void get_crl_number(unsigned char* serial, size_t* serial_size);
int get_path_len(void);
int get_crq_extensions_status(void);
const char *get_pkcs12_key_name(void);
int get_tls_client_status(void);
int get_tls_server_status(void);
time_t get_crl_next_update(void);
time_t get_crl_revocation_date(void);
time_t get_crl_this_update_date(void);
int get_time_stamp_status(void);
int get_email_protection_status(void);
int get_ocsp_sign_status(void);
int get_code_sign_status(void);
int get_crl_sign_status(void);
int get_cert_sign_status(void);
int get_encrypt_status(int server);
int get_sign_status(int server);
void get_ip_addr_set(int type, void *crt);
void get_dns_name_set(int type, void *crt);
void get_other_name_set(int type, void *crt);
void get_extensions_crt_set(int type, void *crt);
void get_policy_set(gnutls_x509_crt_t);
void get_uri_set(int type, void *crt);
void get_email_set(int type, void *crt);
int get_ipsec_ike_status(void);
void get_dc_set(int type, void *crt);
void get_ca_issuers_set(gnutls_x509_crt_t crt);
void get_ocsp_issuer_set(gnutls_x509_crt_t crt);
void crt_unique_ids_set(gnutls_x509_crt_t crt);
void get_tlsfeatures_set(int type, void *crt);

int get_key_agreement_status(void);
int get_non_repudiation_status(void);
int get_data_encipherment_status(void);

void get_cn_crq_set(gnutls_x509_crq_t crq);
void get_uid_crq_set(gnutls_x509_crq_t crq);
void get_locality_crq_set(gnutls_x509_crq_t crq);
void get_state_crq_set(gnutls_x509_crq_t crq);
void get_unit_crq_set(gnutls_x509_crq_t crq);
void get_organization_crq_set(gnutls_x509_crq_t crq);
void get_country_crq_set(gnutls_x509_crq_t crq);
void get_oid_crq_set(gnutls_x509_crq_t crq);
const char *get_proxy_policy(char **policy, size_t * policylen);

void crq_extensions_set(gnutls_x509_crt_t crt, gnutls_x509_crq_t crq);


       







void certtool_version(void);




typedef struct common_info {
 const char *secret_key;
 const char *privkey;
 const char *pubkey;
 int pkcs8;
 int incert_format;
 int outcert_format;
 int outtext;
 const char *cert;

 const char *request;
 const char *crl;
 const char *ca;
 const char *data_file;
 const char *ca_privkey;
 unsigned bits;
 const char *sec_param;
 const char *pkcs_cipher;
 const char *password;
 int null_password;
 int empty_password;
 int ask_pass;
 unsigned int crq_extensions;
 unsigned int v1_cert;

 unsigned provable;

 unsigned char *seed;
 unsigned seed_size;

 const char *pin;
 const char *so_pin;

 gnutls_digest_algorithm_t hash;
 int cprint;
 unsigned key_usage;

 unsigned int batch;

 unsigned int only_urls;
 unsigned int verbose;

 unsigned rsa_pss_sign;
 unsigned sort_chain;

 gnutls_sec_param_t verification_profile;
} common_info_st;

static inline
void switch_to_pkcs8_when_needed(common_info_st *cinfo, gnutls_x509_privkey_t key, unsigned key_type)
{
 if (cinfo->pkcs8)
  return;

 if (key_type == GNUTLS_PK_RSA_PSS || key_type == GNUTLS_PK_EDDSA_ED25519 || key_type == GNUTLS_PK_EDDSA_ED448 ||
            key_type == GNUTLS_PK_ECDH_X25519 || key_type == GNUTLS_PK_ECDH_X448 ||
     key_type == GNUTLS_PK_GOST_01 || key_type == GNUTLS_PK_GOST_12_256 ||
     key_type == GNUTLS_PK_GOST_12_512) {
  if (cinfo->verbose)
   fprintf(
          stderr
                , "Assuming --pkcs8 is given; %s private keys can only be exported in PKCS#8 format\n",
    gnutls_pk_algorithm_get_name(key_type));
  cinfo->pkcs8 = 1;
  if (cinfo->password == 
                        ((void *)0)
                            )
   cinfo->password = "";
 }

 if (gnutls_x509_privkey_get_seed(key, 
                                      ((void *)0)
                                          , 
                                            ((void *)0)
                                                , 0) != -50) {
  if (cinfo->verbose)
   fprintf(
          stderr
                , "Assuming --pkcs8 is given; provable private keys can only be exported in PKCS#8 format\n");
  cinfo->pkcs8 = 1;
  if (cinfo->password == 
                        ((void *)0)
                            )
   cinfo->password = "";
 }
}


const char *get_pass(void);
const char *get_confirmed_pass(
                              _Bool 
                                   empty_ok);
void app_exit(int val)

__attribute__ ((__noreturn__))

;
int cipher_to_flags(const char *cipher);

void
print_private_key(FILE *outfile, common_info_st * cinfo, gnutls_x509_privkey_t key);
gnutls_pubkey_t load_public_key_or_import(int mand,
       gnutls_privkey_t privkey,
       common_info_st * info);
gnutls_privkey_t load_private_key(int mand, common_info_st * info);
gnutls_x509_privkey_t load_x509_private_key(int mand,
         common_info_st * info);
gnutls_x509_privkey_t *load_privkey_list(int mand, size_t * privkey_size,
      common_info_st * info);
gnutls_x509_crq_t load_request(common_info_st * info);
gnutls_privkey_t load_ca_private_key(common_info_st * info);
gnutls_x509_crt_t load_ca_cert(unsigned mand, common_info_st * info);
gnutls_x509_crt_t load_cert(int mand, common_info_st * info);
gnutls_datum_t *load_secret_key(int mand, common_info_st * info);
gnutls_pubkey_t load_pubkey(int mand, common_info_st * info);
gnutls_x509_crt_t *load_cert_list(int mand, size_t * size,
      common_info_st * info);
gnutls_x509_crl_t *load_crl_list(int mand, size_t * size,
      common_info_st * info);
int get_bits(gnutls_pk_algorithm_t key_type, int info_bits,
      const char *info_sec_param, int warn);

gnutls_sec_param_t str_to_sec_param(const char *str);
gnutls_ecc_curve_t str_to_curve(const char *str);


int generate_prime(FILE * outfile, int how, common_info_st * info);
void dh_info(FILE * infile, FILE * outfile, common_info_st * ci);

gnutls_x509_privkey_t *load_privkey_list(int mand, size_t * privkey_size,
      common_info_st * info);

void print_pubkey_info(gnutls_pubkey_t pubkey,
         FILE *outfile,
         gnutls_certificate_print_formats_t format,
         gnutls_x509_crt_fmt_t outcert_format,
         unsigned int outtext);
void print_ecc_pkey(FILE * outfile, gnutls_ecc_curve_t curve,
      gnutls_datum_t * k, gnutls_datum_t * x,
      gnutls_datum_t * y, int cprint);
void print_gost_pkey(FILE * outfile, gnutls_ecc_curve_t curve,
       gnutls_digest_algorithm_t digest,
       gnutls_gost_paramset_t paramset,
       gnutls_datum_t * k, gnutls_datum_t * x,
       gnutls_datum_t * y, int cprint);
void print_rsa_pkey(FILE * outfile, gnutls_datum_t * m, gnutls_datum_t * e,
      gnutls_datum_t * d, gnutls_datum_t * p,
      gnutls_datum_t * q, gnutls_datum_t * u,
      gnutls_datum_t * exp1, gnutls_datum_t * exp2,
      int cprint);
void print_dsa_pkey(FILE * outfile, gnutls_datum_t * x, gnutls_datum_t * y,
      gnutls_datum_t * p, gnutls_datum_t * q,
      gnutls_datum_t * g, int cprint);

__attribute__ ((__malloc__))
FILE *safe_open_rw(const char *file, int privkey_op);

const char *get_password(common_info_st * cinfo, unsigned int *flags,
    int confirm);

extern unsigned char *lbuffer;
extern unsigned long lbuffer_size;

void fix_lbuffer(unsigned long);

void decode_seed(gnutls_datum_t *seed, const char *hex, unsigned hex_size);



gnutls_pk_algorithm_t figure_key_type(const char *key_type);

gnutls_digest_algorithm_t hash_to_id(const char *hash);

void sign_params_to_flags(common_info_st *cinfo, const char *params);

inline 
              _Bool

c_isalnum (int c)
{
  switch (c)
    {
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    case 'a' + (0): case 'b' + (0): case 'c' + (0): case 'd' + (0): case 'e' + (0): case 'f' + (0): case 'g' + (0): case 'h' + (0): case 'i' + (0): case 'j' + (0): case 'k' + (0): case 'l' + (0): case 'm' + (0): case 'n' + (0): case 'o' + (0): case 'p' + (0): case 'q' + (0): case 'r' + (0): case 's' + (0): case 't' + (0): case 'u' + (0): case 'v' + (0): case 'w' + (0): case 'x' + (0): case 'y' + (0): case 'z' + (0):
    case 'a' + ('A' - 'a'): case 'b' + ('A' - 'a'): case 'c' + ('A' - 'a'): case 'd' + ('A' - 'a'): case 'e' + ('A' - 'a'): case 'f' + ('A' - 'a'): case 'g' + ('A' - 'a'): case 'h' + ('A' - 'a'): case 'i' + ('A' - 'a'): case 'j' + ('A' - 'a'): case 'k' + ('A' - 'a'): case 'l' + ('A' - 'a'): case 'm' + ('A' - 'a'): case 'n' + ('A' - 'a'): case 'o' + ('A' - 'a'): case 'p' + ('A' - 'a'): case 'q' + ('A' - 'a'): case 'r' + ('A' - 'a'): case 's' + ('A' - 'a'): case 't' + ('A' - 'a'): case 'u' + ('A' - 'a'): case 'v' + ('A' - 'a'): case 'w' + ('A' - 'a'): case 'x' + ('A' - 'a'): case 'y' + ('A' - 'a'): case 'z' + ('A' - 'a'):
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_isalpha (int c)
{
  switch (c)
    {
    case 'a' + (0): case 'b' + (0): case 'c' + (0): case 'd' + (0): case 'e' + (0): case 'f' + (0): case 'g' + (0): case 'h' + (0): case 'i' + (0): case 'j' + (0): case 'k' + (0): case 'l' + (0): case 'm' + (0): case 'n' + (0): case 'o' + (0): case 'p' + (0): case 'q' + (0): case 'r' + (0): case 's' + (0): case 't' + (0): case 'u' + (0): case 'v' + (0): case 'w' + (0): case 'x' + (0): case 'y' + (0): case 'z' + (0):
    case 'a' + ('A' - 'a'): case 'b' + ('A' - 'a'): case 'c' + ('A' - 'a'): case 'd' + ('A' - 'a'): case 'e' + ('A' - 'a'): case 'f' + ('A' - 'a'): case 'g' + ('A' - 'a'): case 'h' + ('A' - 'a'): case 'i' + ('A' - 'a'): case 'j' + ('A' - 'a'): case 'k' + ('A' - 'a'): case 'l' + ('A' - 'a'): case 'm' + ('A' - 'a'): case 'n' + ('A' - 'a'): case 'o' + ('A' - 'a'): case 'p' + ('A' - 'a'): case 'q' + ('A' - 'a'): case 'r' + ('A' - 'a'): case 's' + ('A' - 'a'): case 't' + ('A' - 'a'): case 'u' + ('A' - 'a'): case 'v' + ('A' - 'a'): case 'w' + ('A' - 'a'): case 'x' + ('A' - 'a'): case 'y' + ('A' - 'a'): case 'z' + ('A' - 'a'):
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}



inline 
              _Bool

c_isascii (int c)
{
  switch (c)
    {
    case ' ':
    case '\a': case '\b': case '\f': case '\n': case '\r': case '\t': case '\v': case '\x00': case '\x01': case '\x02': case '\x03': case '\x04': case '\x05': case '\x06': case '\x0e': case '\x0f': case '\x10': case '\x11': case '\x12': case '\x13': case '\x14': case '\x15': case '\x16': case '\x17': case '\x18': case '\x19': case '\x1a': case '\x1b': case '\x1c': case '\x1d': case '\x1e': case '\x1f': case '\x7f':
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    case 'a' + (0): case 'b' + (0): case 'c' + (0): case 'd' + (0): case 'e' + (0): case 'f' + (0): case 'g' + (0): case 'h' + (0): case 'i' + (0): case 'j' + (0): case 'k' + (0): case 'l' + (0): case 'm' + (0): case 'n' + (0): case 'o' + (0): case 'p' + (0): case 'q' + (0): case 'r' + (0): case 's' + (0): case 't' + (0): case 'u' + (0): case 'v' + (0): case 'w' + (0): case 'x' + (0): case 'y' + (0): case 'z' + (0):
    case '!': case '"': case '#': case '$': case '%': case '&': case '\'': case '(': case ')': case '*': case '+': case ',': case '-': case '.': case '/': case ':': case ';': case '<': case '=': case '>': case '?': case '@': case '[': case '\\': case ']': case '^': case '_': case '`': case '{': case '|': case '}': case '~':
    case 'a' + ('A' - 'a'): case 'b' + ('A' - 'a'): case 'c' + ('A' - 'a'): case 'd' + ('A' - 'a'): case 'e' + ('A' - 'a'): case 'f' + ('A' - 'a'): case 'g' + ('A' - 'a'): case 'h' + ('A' - 'a'): case 'i' + ('A' - 'a'): case 'j' + ('A' - 'a'): case 'k' + ('A' - 'a'): case 'l' + ('A' - 'a'): case 'm' + ('A' - 'a'): case 'n' + ('A' - 'a'): case 'o' + ('A' - 'a'): case 'p' + ('A' - 'a'): case 'q' + ('A' - 'a'): case 'r' + ('A' - 'a'): case 's' + ('A' - 'a'): case 't' + ('A' - 'a'): case 'u' + ('A' - 'a'): case 'v' + ('A' - 'a'): case 'w' + ('A' - 'a'): case 'x' + ('A' - 'a'): case 'y' + ('A' - 'a'): case 'z' + ('A' - 'a'):
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_isblank (int c)
{
  return c == ' ' || c == '\t';
}

inline 
              _Bool

c_iscntrl (int c)
{
  switch (c)
    {
    case '\a': case '\b': case '\f': case '\n': case '\r': case '\t': case '\v': case '\x00': case '\x01': case '\x02': case '\x03': case '\x04': case '\x05': case '\x06': case '\x0e': case '\x0f': case '\x10': case '\x11': case '\x12': case '\x13': case '\x14': case '\x15': case '\x16': case '\x17': case '\x18': case '\x19': case '\x1a': case '\x1b': case '\x1c': case '\x1d': case '\x1e': case '\x1f': case '\x7f':
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_isdigit (int c)
{
  switch (c)
    {
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_isgraph (int c)
{
  switch (c)
    {
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    case 'a' + (0): case 'b' + (0): case 'c' + (0): case 'd' + (0): case 'e' + (0): case 'f' + (0): case 'g' + (0): case 'h' + (0): case 'i' + (0): case 'j' + (0): case 'k' + (0): case 'l' + (0): case 'm' + (0): case 'n' + (0): case 'o' + (0): case 'p' + (0): case 'q' + (0): case 'r' + (0): case 's' + (0): case 't' + (0): case 'u' + (0): case 'v' + (0): case 'w' + (0): case 'x' + (0): case 'y' + (0): case 'z' + (0):
    case '!': case '"': case '#': case '$': case '%': case '&': case '\'': case '(': case ')': case '*': case '+': case ',': case '-': case '.': case '/': case ':': case ';': case '<': case '=': case '>': case '?': case '@': case '[': case '\\': case ']': case '^': case '_': case '`': case '{': case '|': case '}': case '~':
    case 'a' + ('A' - 'a'): case 'b' + ('A' - 'a'): case 'c' + ('A' - 'a'): case 'd' + ('A' - 'a'): case 'e' + ('A' - 'a'): case 'f' + ('A' - 'a'): case 'g' + ('A' - 'a'): case 'h' + ('A' - 'a'): case 'i' + ('A' - 'a'): case 'j' + ('A' - 'a'): case 'k' + ('A' - 'a'): case 'l' + ('A' - 'a'): case 'm' + ('A' - 'a'): case 'n' + ('A' - 'a'): case 'o' + ('A' - 'a'): case 'p' + ('A' - 'a'): case 'q' + ('A' - 'a'): case 'r' + ('A' - 'a'): case 's' + ('A' - 'a'): case 't' + ('A' - 'a'): case 'u' + ('A' - 'a'): case 'v' + ('A' - 'a'): case 'w' + ('A' - 'a'): case 'x' + ('A' - 'a'): case 'y' + ('A' - 'a'): case 'z' + ('A' - 'a'):
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_islower (int c)
{
  switch (c)
    {
    case 'a' + (0): case 'b' + (0): case 'c' + (0): case 'd' + (0): case 'e' + (0): case 'f' + (0): case 'g' + (0): case 'h' + (0): case 'i' + (0): case 'j' + (0): case 'k' + (0): case 'l' + (0): case 'm' + (0): case 'n' + (0): case 'o' + (0): case 'p' + (0): case 'q' + (0): case 'r' + (0): case 's' + (0): case 't' + (0): case 'u' + (0): case 'v' + (0): case 'w' + (0): case 'x' + (0): case 'y' + (0): case 'z' + (0):
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_isprint (int c)
{
  switch (c)
    {
    case ' ':
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    case 'a' + (0): case 'b' + (0): case 'c' + (0): case 'd' + (0): case 'e' + (0): case 'f' + (0): case 'g' + (0): case 'h' + (0): case 'i' + (0): case 'j' + (0): case 'k' + (0): case 'l' + (0): case 'm' + (0): case 'n' + (0): case 'o' + (0): case 'p' + (0): case 'q' + (0): case 'r' + (0): case 's' + (0): case 't' + (0): case 'u' + (0): case 'v' + (0): case 'w' + (0): case 'x' + (0): case 'y' + (0): case 'z' + (0):
    case '!': case '"': case '#': case '$': case '%': case '&': case '\'': case '(': case ')': case '*': case '+': case ',': case '-': case '.': case '/': case ':': case ';': case '<': case '=': case '>': case '?': case '@': case '[': case '\\': case ']': case '^': case '_': case '`': case '{': case '|': case '}': case '~':
    case 'a' + ('A' - 'a'): case 'b' + ('A' - 'a'): case 'c' + ('A' - 'a'): case 'd' + ('A' - 'a'): case 'e' + ('A' - 'a'): case 'f' + ('A' - 'a'): case 'g' + ('A' - 'a'): case 'h' + ('A' - 'a'): case 'i' + ('A' - 'a'): case 'j' + ('A' - 'a'): case 'k' + ('A' - 'a'): case 'l' + ('A' - 'a'): case 'm' + ('A' - 'a'): case 'n' + ('A' - 'a'): case 'o' + ('A' - 'a'): case 'p' + ('A' - 'a'): case 'q' + ('A' - 'a'): case 'r' + ('A' - 'a'): case 's' + ('A' - 'a'): case 't' + ('A' - 'a'): case 'u' + ('A' - 'a'): case 'v' + ('A' - 'a'): case 'w' + ('A' - 'a'): case 'x' + ('A' - 'a'): case 'y' + ('A' - 'a'): case 'z' + ('A' - 'a'):
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_ispunct (int c)
{
  switch (c)
    {
    case '!': case '"': case '#': case '$': case '%': case '&': case '\'': case '(': case ')': case '*': case '+': case ',': case '-': case '.': case '/': case ':': case ';': case '<': case '=': case '>': case '?': case '@': case '[': case '\\': case ']': case '^': case '_': case '`': case '{': case '|': case '}': case '~':
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_isspace (int c)
{
  switch (c)
    {
    case ' ': case '\t': case '\n': case '\v': case '\f': case '\r':
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_isupper (int c)
{
  switch (c)
    {
    case 'a' + ('A' - 'a'): case 'b' + ('A' - 'a'): case 'c' + ('A' - 'a'): case 'd' + ('A' - 'a'): case 'e' + ('A' - 'a'): case 'f' + ('A' - 'a'): case 'g' + ('A' - 'a'): case 'h' + ('A' - 'a'): case 'i' + ('A' - 'a'): case 'j' + ('A' - 'a'): case 'k' + ('A' - 'a'): case 'l' + ('A' - 'a'): case 'm' + ('A' - 'a'): case 'n' + ('A' - 'a'): case 'o' + ('A' - 'a'): case 'p' + ('A' - 'a'): case 'q' + ('A' - 'a'): case 'r' + ('A' - 'a'): case 's' + ('A' - 'a'): case 't' + ('A' - 'a'): case 'u' + ('A' - 'a'): case 'v' + ('A' - 'a'): case 'w' + ('A' - 'a'): case 'x' + ('A' - 'a'): case 'y' + ('A' - 'a'): case 'z' + ('A' - 'a'):
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_isxdigit (int c)
{
  switch (c)
    {
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    case 'a' + (0): case 'b' + (0): case 'c' + (0): case 'd' + (0): case 'e' + (0): case 'f' + (0): case 'a' + ('A' - 'a'): case 'b' + ('A' - 'a'): case 'c' + ('A' - 'a'): case 'd' + ('A' - 'a'): case 'e' + ('A' - 'a'): case 'f' + ('A' - 'a'):
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline int
c_tolower (int c)
{
  switch (c)
    {
    case 'a' + ('A' - 'a'): case 'b' + ('A' - 'a'): case 'c' + ('A' - 'a'): case 'd' + ('A' - 'a'): case 'e' + ('A' - 'a'): case 'f' + ('A' - 'a'): case 'g' + ('A' - 'a'): case 'h' + ('A' - 'a'): case 'i' + ('A' - 'a'): case 'j' + ('A' - 'a'): case 'k' + ('A' - 'a'): case 'l' + ('A' - 'a'): case 'm' + ('A' - 'a'): case 'n' + ('A' - 'a'): case 'o' + ('A' - 'a'): case 'p' + ('A' - 'a'): case 'q' + ('A' - 'a'): case 'r' + ('A' - 'a'): case 's' + ('A' - 'a'): case 't' + ('A' - 'a'): case 'u' + ('A' - 'a'): case 'v' + ('A' - 'a'): case 'w' + ('A' - 'a'): case 'x' + ('A' - 'a'): case 'y' + ('A' - 'a'): case 'z' + ('A' - 'a'):
      return c - 'A' + 'a';
    default:
      return c;
    }
}

inline int
c_toupper (int c)
{
  switch (c)
    {
    case 'a' + (0): case 'b' + (0): case 'c' + (0): case 'd' + (0): case 'e' + (0): case 'f' + (0): case 'g' + (0): case 'h' + (0): case 'i' + (0): case 'j' + (0): case 'k' + (0): case 'l' + (0): case 'm' + (0): case 'n' + (0): case 'o' + (0): case 'p' + (0): case 'q' + (0): case 'r' + (0): case 's' + (0): case 't' + (0): case 'u' + (0): case 'v' + (0): case 'w' + (0): case 'x' + (0): case 'y' + (0): case 'z' + (0):
      return c - 'a' + 'A';
    default:
      return c;
    }
}






       
       
       





       

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                                        ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy


                                                     ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                                        ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                     ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                        ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy


                                                     ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                                    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                               ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;

       






       
       
extern int _gl_cxxalias_dummy



                                                   ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy



                                   ;
extern int _gl_cxxalias_dummy;





       

extern const char str_unknown[];



int print_info(gnutls_session_t state, int verbose, int flags);
void print_cert_info(gnutls_session_t, int flag, int print_cert);
void print_key_material(gnutls_session_t, const char *label, size_t size);

int log_msg(FILE *file, const char *message, ...) __attribute__((format(printf, 2, 3)));
void log_set(FILE *file);

void print_cert_info2(gnutls_session_t, int flag, FILE *fp, int print_cert);

void print_list(const char *priorities, int verbose);
int cert_verify(gnutls_session_t session, const char *hostname, const char *purpose);

int compress_cert_set_methods(gnutls_session_t session, const char **strings,
         size_t n_strings);

const char *raw_to_string(const unsigned char *raw, size_t raw_size);
const char *raw_to_hex(const unsigned char *raw, size_t raw_size);
const char *raw_to_base64(const unsigned char *raw, size_t raw_size);
int check_command(gnutls_session_t session, const char *str, unsigned no_cli_cert);


void getenv_copy(char *str, size_t max_str_size, const char *envvar);
void getpass_copy(char *pass, size_t max_pass_size, const char *prompt);

int
pin_callback(void *user, int attempt, const char *token_url,
      const char *token_label, unsigned int flags, char *pin,
      size_t pin_max);

void pkcs11_common(common_info_st *c);

inline static int is_ip(const char *hostname)
{
int len = strlen(hostname);

 if (strchr(hostname, ':') != 0)
  return 1;
 else if (len > 2 && c_isdigit(hostname[0]) && c_isdigit(hostname[len-1]))
  return 1;
 return 0;
}

void sockets_init(void);
char *simple_ctime(const time_t *t, char buf[64]);

       




struct certtool_list
{
  const char **args;
  unsigned int count;
};

struct certtool_options
{

  struct
  {
    
   _Bool 
        debug;
    
   _Bool 
        verbose;
    
   _Bool 
        infile;
    
   _Bool 
        outfile;
    
   _Bool 
        certificate_info;
    
   _Bool 
        pubkey_info;
    
   _Bool 
        generate_self_signed;
    
   _Bool 
        generate_certificate;
    
   _Bool 
        generate_proxy;
    
   _Bool 
        update_certificate;
    
   _Bool 
        fingerprint;
    
   _Bool 
        key_id;
    
   _Bool 
        certificate_pubkey;
    
   _Bool 
        v1;
    
   _Bool 
        sign_params;
    
   _Bool 
        crq_info;
    
   _Bool 
        generate_request;
    
   _Bool 
        no_crq_extensions;
    
   _Bool 
        p12_info;
    
   _Bool 
        p12_name;
    
   _Bool 
        to_p12;
    
   _Bool 
        key_info;
    
   _Bool 
        p8_info;
    
   _Bool 
        to_rsa;
    
   _Bool 
        generate_privkey;
    
   _Bool 
        key_type;
    
   _Bool 
        bits;
    
   _Bool 
        curve;
    
   _Bool 
        sec_param;
    
   _Bool 
        to_p8;
    
   _Bool 
        pkcs8;
    
   _Bool 
        provable;
    
   _Bool 
        verify_provable_privkey;
    
   _Bool 
        seed;
    
   _Bool 
        crl_info;
    
   _Bool 
        generate_crl;
    
   _Bool 
        verify_crl;
    
   _Bool 
        verify_chain;
    
   _Bool 
        verify;
    
   _Bool 
        verify_hostname;
    
   _Bool 
        verify_email;
    
   _Bool 
        verify_purpose;
    
   _Bool 
        verify_allow_broken;
    
   _Bool 
        verify_profile;
    
   _Bool 
        p7_generate;
    
   _Bool 
        p7_sign;
    
   _Bool 
        p7_detached_sign;
    
   _Bool 
        p7_include_cert;
    
   _Bool 
        p7_time;
    
   _Bool 
        p7_show_data;
    
   _Bool 
        p7_info;
    
   _Bool 
        p7_verify;
    
   _Bool 
        smime_to_p7;
    
   _Bool 
        generate_dh_params;
    
   _Bool 
        get_dh_params;
    
   _Bool 
        dh_info;
    
   _Bool 
        load_privkey;
    
   _Bool 
        load_pubkey;
    
   _Bool 
        load_request;
    
   _Bool 
        load_certificate;
    
   _Bool 
        load_ca_privkey;
    
   _Bool 
        load_ca_certificate;
    
   _Bool 
        load_crl;
    
   _Bool 
        load_data;
    
   _Bool 
        password;
    
   _Bool 
        null_password;
    
   _Bool 
        empty_password;
    
   _Bool 
        hex_numbers;
    
   _Bool 
        cprint;
    
   _Bool 
        rsa;
    
   _Bool 
        dsa;
    
   _Bool 
        ecc;
    
   _Bool 
        hash;
    
   _Bool 
        salt_size;
    
   _Bool 
        inder;
    
   _Bool 
        outder;
    
   _Bool 
        disable_quick_random;
    
   _Bool 
        template;
    
   _Bool 
        stdout_info;
    
   _Bool 
        ask_pass;
    
   _Bool 
        pkcs_cipher;
    
   _Bool 
        provider;
    
   _Bool 
        text;
    
   _Bool 
        version;
    
   _Bool 
        help;
    
   _Bool 
        more_help;
  } present;


  struct
  {
    const char *debug;
    const char *infile;
    const char *outfile;
    const char *sign_params;
    const char *p12_name;
    const char *key_type;
    const char *bits;
    const char *curve;
    const char *sec_param;
    const char *seed;
    const char *verify_hostname;
    const char *verify_email;
    const char *verify_purpose;
    const char *verify_profile;
    const char *load_privkey;
    const char *load_pubkey;
    const char *load_request;
    const char *load_certificate;
    const char *load_ca_privkey;
    const char *load_ca_certificate;
    const char *load_crl;
    const char *load_data;
    const char *password;
    const char *hash;
    const char *salt_size;
    const char *template;
    const char *pkcs_cipher;
    const char *provider;
    const char *version;
  } arg;


  struct
  {
    int debug;
    int bits;
    int salt_size;
  } value;


  struct
  {
    
   _Bool 
        debug;
    
   _Bool 
        verbose;
    
   _Bool 
        infile;
    
   _Bool 
        outfile;
    
   _Bool 
        certificate_info;
    
   _Bool 
        pubkey_info;
    
   _Bool 
        generate_self_signed;
    
   _Bool 
        generate_certificate;
    
   _Bool 
        generate_proxy;
    
   _Bool 
        update_certificate;
    
   _Bool 
        fingerprint;
    
   _Bool 
        key_id;
    
   _Bool 
        certificate_pubkey;
    
   _Bool 
        v1;
    
   _Bool 
        sign_params;
    
   _Bool 
        crq_info;
    
   _Bool 
        generate_request;
    
   _Bool 
        no_crq_extensions;
    
   _Bool 
        p12_info;
    
   _Bool 
        p12_name;
    
   _Bool 
        to_p12;
    
   _Bool 
        key_info;
    
   _Bool 
        p8_info;
    
   _Bool 
        to_rsa;
    
   _Bool 
        generate_privkey;
    
   _Bool 
        key_type;
    
   _Bool 
        bits;
    
   _Bool 
        curve;
    
   _Bool 
        sec_param;
    
   _Bool 
        to_p8;
    
   _Bool 
        pkcs8;
    
   _Bool 
        provable;
    
   _Bool 
        verify_provable_privkey;
    
   _Bool 
        seed;
    
   _Bool 
        crl_info;
    
   _Bool 
        generate_crl;
    
   _Bool 
        verify_crl;
    
   _Bool 
        verify_chain;
    
   _Bool 
        verify;
    
   _Bool 
        verify_hostname;
    
   _Bool 
        verify_email;
    
   _Bool 
        verify_purpose;
    
   _Bool 
        verify_allow_broken;
    
   _Bool 
        verify_profile;
    
   _Bool 
        p7_generate;
    
   _Bool 
        p7_sign;
    
   _Bool 
        p7_detached_sign;
    
   _Bool 
        p7_include_cert;
    
   _Bool 
        p7_time;
    
   _Bool 
        p7_show_data;
    
   _Bool 
        p7_info;
    
   _Bool 
        p7_verify;
    
   _Bool 
        smime_to_p7;
    
   _Bool 
        generate_dh_params;
    
   _Bool 
        get_dh_params;
    
   _Bool 
        dh_info;
    
   _Bool 
        load_privkey;
    
   _Bool 
        load_pubkey;
    
   _Bool 
        load_request;
    
   _Bool 
        load_certificate;
    
   _Bool 
        load_ca_privkey;
    
   _Bool 
        load_ca_certificate;
    
   _Bool 
        load_crl;
    
   _Bool 
        load_data;
    
   _Bool 
        password;
    
   _Bool 
        null_password;
    
   _Bool 
        empty_password;
    
   _Bool 
        hex_numbers;
    
   _Bool 
        cprint;
    
   _Bool 
        rsa;
    
   _Bool 
        dsa;
    
   _Bool 
        ecc;
    
   _Bool 
        hash;
    
   _Bool 
        salt_size;
    
   _Bool 
        inder;
    
   _Bool 
        outder;
    
   _Bool 
        disable_quick_random;
    
   _Bool 
        template;
    
   _Bool 
        stdout_info;
    
   _Bool 
        ask_pass;
    
   _Bool 
        pkcs_cipher;
    
   _Bool 
        provider;
    
   _Bool 
        text;
    
   _Bool 
        version;
    
   _Bool 
        help;
    
   _Bool 
        more_help;
  } enabled;
};
extern struct certtool_options certtool_options;
int process_options (int argc, char **argv);
void usage (FILE *out, int status);



static FILE *stdlog = 
                     ((void *)0)
                         ;

static void print_crl_info(gnutls_x509_crl_t crl, FILE * out, common_info_st *cinfo);
void pkcs7_info(common_info_st *cinfo, unsigned display_data);
void pkcs7_sign(common_info_st *, unsigned embed);
void pkcs7_generate(common_info_st *);
void pkcs8_info(void);
void pkcs8_info_int(gnutls_datum_t *data, unsigned format,
   unsigned ignore_err, FILE *out, const char *tab);
void crq_info(common_info_st *cinfo);
void smime_to_pkcs7(void);
void pkcs12_info(common_info_st *);
void generate_pkcs12(common_info_st *);
void generate_pkcs8(common_info_st *);
static void verify_chain(common_info_st * cinfo);
void verify_crl(common_info_st * cinfo);
void verify_pkcs7(common_info_st * cinfo, const char *purpose, unsigned display_data);
void pubkey_info(gnutls_x509_crt_t crt, common_info_st *);
void certificate_info(int, common_info_st *);
void crl_info(common_info_st *cinfo);
void privkey_info(common_info_st *);
static void cmd_parser(int argc, char **argv);
void generate_self_signed(common_info_st *);
void generate_request(common_info_st *);
static void print_certificate_info(gnutls_x509_crt_t crt, FILE * out,
       unsigned int all);
static void verify_certificate(common_info_st * cinfo);

static void privkey_to_rsa(common_info_st * cinfo);

static void pubkey_keyid(common_info_st * cinfo);
static void certificate_fpr(common_info_st * cinfo);
static gnutls_digest_algorithm_t get_dig(gnutls_x509_crt_t crt, common_info_st * cinfo);

FILE *outfile;
static const char *outfile_name = 
                                 ((void *)0)
                                     ;



FILE *infile;
static unsigned int incert_format, outcert_format;
static unsigned int req_key_type = GNUTLS_PK_RSA;
gnutls_certificate_print_formats_t full_format = GNUTLS_CRT_PRINT_FULL;



int batch;
int ask_pass;


void app_exit(int val)
{
 if (val != 0) {
  if (outfile_name)
   (void)remove(outfile_name);
 }
 exit(val);
}

static void tls_log_func(int level, const char *str)
{
 fprintf(
        stderr
              , "|<%d>| %s", level, str);
}

int main(int argc, char **argv)
{

 signal(
       13
              , 
                ((__sighandler_t) 1)
                       );

 cfg_init();
 cmd_parser(argc, argv);

 return 0;
}
static gnutls_x509_privkey_t
generate_private_key_int(common_info_st * cinfo)
{
 gnutls_x509_privkey_t key;
 int ret, key_type, bits;
 unsigned provable = cinfo->provable;
 unsigned flags = 0;
 gnutls_keygen_data_st kdata[8];
 unsigned kdata_size = 0;
 gnutls_x509_spki_t spki;

 key_type = req_key_type;

 ret = gnutls_x509_privkey_init(&key);
 if (ret < 0) {
  fprintf(
         stderr
               , "privkey_init: %s", gnutls_strerror(ret));
  app_exit(1);
 }

 bits = get_bits(key_type, cinfo->bits, cinfo->sec_param, 1);

 if (key_type == GNUTLS_PK_ECDSA ||
     key_type == GNUTLS_PK_EDDSA_ED25519 ||
     key_type == GNUTLS_PK_EDDSA_ED448 ||
     key_type == GNUTLS_PK_GOST_01 ||
     key_type == GNUTLS_PK_GOST_12_256 ||
     key_type == GNUTLS_PK_GOST_12_512) {
  char name[64];
  int ecc_bits;

  if ((((unsigned int)(bits)) & 0x80000000)) {
   gnutls_ecc_curve_t curve = (((unsigned int)(bits)) & 0x7FFFFFFF);
   ecc_bits = gnutls_ecc_curve_get_size(curve) * 8;
   snprintf(name, sizeof(name), "(%s)", gnutls_ecc_curve_get_name(curve));
  } else {
   ecc_bits = bits;
   name[0] = 0;
  }

  fprintf(stdlog, "Generating a %d bit %s private key %s...\n",
   ecc_bits, gnutls_pk_algorithm_get_name(key_type), name);

  if (ecc_bits < 256)
   fprintf(
          stderr
                ,
    "Note that ECDSA keys with size less than 256 are not widely supported.\n\n");
 } else {
  fprintf(stdlog, "Generating a %d bit %s private key...\n",
   bits, gnutls_pk_algorithm_get_name(key_type));
 }

 if (provable && (!((key_type) == GNUTLS_PK_RSA || (key_type) == GNUTLS_PK_RSA_PSS) && key_type != GNUTLS_PK_DSA)) {
  fprintf(
         stderr
               ,
   "The --provable parameter can only be used with RSA and DSA keys.\n");
  app_exit(1);
 }

 if (bits > 1024 && key_type == GNUTLS_PK_DSA)
  fprintf(
         stderr
               ,
   "Note that DSA keys with size over 1024 may cause incompatibility problems when used with earlier than TLS 1.2 versions.\n\n");

 if ((certtool_options.present.seed || provable) && ((key_type) == GNUTLS_PK_RSA || (key_type) == GNUTLS_PK_RSA_PSS)) {


  if (bits != 2048 && bits != 3072 && bits != 4096 &&
      bits != 6144 && bits != 7680 && bits != 8192 &&
      bits != 15360) {
   fprintf(
          stderr
                , "Note that the FIPS 186-4 key generation restricts keys to be of known lengths (2048, 3072, etc)\n");
  }
 }

 ret = gnutls_x509_spki_init(&spki);
 if (ret < 0) {
  fprintf(
         stderr
               , "error in SPKI initialization: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 switch_to_pkcs8_when_needed(cinfo, key, key_type);

 if (cinfo->seed_size > 0) {
  kdata[kdata_size].type = GNUTLS_KEYGEN_SEED;
  kdata[kdata_size].data = (void*)cinfo->seed;
  kdata[kdata_size++].size = cinfo->seed_size;

  if (((key_type) == GNUTLS_PK_RSA || (key_type) == GNUTLS_PK_RSA_PSS)) {


   if ((bits == 2048 && cinfo->seed_size != 28) ||
       (bits == 3072 && cinfo->seed_size != 32) ||
       (bits == 4096 && cinfo->seed_size != 38) ||
       (bits == 6144 && cinfo->seed_size != 44) ||
       (bits == 7680 && cinfo->seed_size != 48) ||
       (bits == 8192 && cinfo->seed_size != 50) ||
       (bits == 15360 && cinfo->seed_size != 64)) {
    fprintf(
           stderr
                 , "The seed size (%d) doesn't match the size of the request security level; use -d 2 for more information.\n", (int)cinfo->seed_size);
   }
  } else if (key_type == GNUTLS_PK_DSA) {
   if (cinfo->seed_size != 65) {
    fprintf(
           stderr
                 , "The seed size (%d) doesn't match the size of the request security level; use -d 2 for more information.\n", (int)cinfo->seed_size);
   }
  }

  flags |= GNUTLS_PRIVKEY_FLAG_PROVABLE;
 }

 if (key_type == GNUTLS_PK_RSA_PSS && (cinfo->hash || certtool_options.present.salt_size)) {

  do { unsigned _salt_size; if (!cinfo->hash) { fprintf(
 stderr
 , "You must provide the hash algorithm and optionally the salt size for RSA-PSS\n"); app_exit(1); } if (certtool_options.present.salt_size) { _salt_size = certtool_options.value.salt_size; } else { _salt_size = gnutls_hash_get_len(cinfo->hash); } gnutls_x509_spki_set_rsa_pss_params(spki, cinfo->hash, _salt_size); } while(0);

  kdata[kdata_size].type = GNUTLS_KEYGEN_SPKI;
  kdata[kdata_size].data = (void*)spki;
  kdata[kdata_size++].size = sizeof(spki);
 }

 if (provable)
  flags |= GNUTLS_PRIVKEY_FLAG_PROVABLE;

 ret = gnutls_x509_privkey_generate2(key, key_type, bits, flags, kdata, kdata_size);
 if (ret < 0) {
  fprintf(
         stderr
               , "privkey_generate: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }

 gnutls_x509_spki_deinit(spki);

 ret = gnutls_x509_privkey_verify_params(key);
 if (ret < 0) {
  fprintf(
         stderr
               , "privkey_verify_params: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }

 return key;
}


static void generate_private_key(common_info_st * cinfo)
{
 gnutls_x509_privkey_t key;

 key = generate_private_key_int(cinfo);

 print_private_key(outfile, cinfo, key);

 gnutls_x509_privkey_deinit(key);
}

static void verify_provable_privkey(common_info_st * cinfo)
{
 gnutls_privkey_t pkey;
 int ret;

 pkey = load_private_key(1, cinfo);

 if (cinfo->seed_size > 0) {
  ret = gnutls_privkey_verify_seed(pkey, 0, cinfo->seed, cinfo->seed_size);
 } else {
  ret = gnutls_privkey_verify_seed(pkey, 0, 
                                           ((void *)0)
                                               , 0);
 }

 if (ret < 0) {
  if (ret == -1250)
   fprintf(
          stderr
                , "The private key type cannot be associated with validated parameters\n");
  else
   fprintf(
          stderr
                , "Error verifying private key: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 printf("Key was verified\n");
 gnutls_privkey_deinit(pkey);

 return;
}

static gnutls_x509_crt_t
generate_certificate(gnutls_privkey_t * ret_key,
       gnutls_x509_crt_t ca_crt, int proxy,
       common_info_st * cinfo)
{
 gnutls_x509_crt_t crt;
 gnutls_x509_spki_t spki;
 gnutls_privkey_t key = 
                       ((void *)0)
                           ;
 gnutls_pubkey_t pubkey;
 size_t size;
 int ret;
 int client;
 int result, ca_status = 0, is_ike = 0, path_len;
 time_t secs;
 int vers;
 unsigned int usage = 0, server, ask;
 gnutls_x509_crq_t crq;
 unsigned pk;
 char timebuf[64];

 ret = gnutls_x509_crt_init(&crt);
 if (ret < 0) {
  fprintf(
         stderr
               , "crt_init: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 crq = load_request(cinfo);

 if (crq == 
           ((void *)0)
               ) {

  key = load_private_key(0, cinfo);

  pubkey = load_public_key_or_import(1, key, cinfo);

  if (!batch)
   fprintf(
          stderr
                ,
    "Please enter the details of the certificate's distinguished name. "
    "Just press enter to ignore a field.\n");



  if (proxy) {
   result =
       gnutls_x509_crt_set_proxy_dn(crt, ca_crt, 0,
        
       ((void *)0)
           , 0);
   if (result < 0) {
    fprintf(
           stderr
                 , "set_proxy_dn: %s\n",
     gnutls_strerror(result));
    app_exit(1);
   }

   get_dn_crt_set(crt);
   get_cn_crt_set(crt);
  } else {
   get_dn_crt_set(crt);

   get_country_crt_set(crt);
   get_state_crt_set(crt);
   get_locality_crt_set(crt);
   get_organization_crt_set(crt);
   get_unit_crt_set(crt);
   get_cn_crt_set(crt);
   get_uid_crt_set(crt);
   get_dc_set(1, crt);

   get_oid_crt_set(crt);
   get_key_purpose_set(1, crt);

   if (!batch)
    fprintf(
           stderr
                 ,
     "This field should not be used in new certificates.\n");

   get_pkcs9_email_crt_set(crt);

   get_tlsfeatures_set(1, crt);
  }

  result = gnutls_x509_crt_set_pubkey(crt, pubkey);
  if (result < 0) {
   fprintf(
          stderr
                , "set_key: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }
  gnutls_pubkey_deinit(pubkey);
 } else {

  result = gnutls_x509_crt_set_crq(crt, crq);
  if (result < 0) {
   fprintf(
          stderr
                , "set_crq: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  crq_extensions_set(crt, crq);
 }

 pk = gnutls_x509_crt_get_pk_algorithm(crt, 
                                           ((void *)0)
                                               );

 {
  size_t serial_size;
  unsigned char serial[20];

  serial_size = sizeof(serial);

  get_serial(serial, &serial_size);

  result = gnutls_x509_crt_set_serial(crt, serial, serial_size);
  if (result < 0) {
   fprintf(
          stderr
                , "serial: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }
 }

 if (!batch)
  fprintf(
         stderr
               , "\n\nActivation/Expiration time.\n");

 secs = get_activation_date();

 result = gnutls_x509_crt_set_activation_time(crt, secs);
 if (result < 0) {
  fprintf(
         stderr
               , "set_activation: %s\n",
   gnutls_strerror(result));
  app_exit(1);
 }

 do {
  ask = 0;
  secs = get_expiration_date();

  if (ca_crt && (secs > gnutls_x509_crt_get_expiration_time(ca_crt))) {
   time_t exp = gnutls_x509_crt_get_expiration_time(ca_crt);
   fprintf(
          stderr
                , "\nExpiration time: %s\n", simple_ctime(&secs, timebuf));
   fprintf(
          stderr
                , "CA expiration time: %s\n", simple_ctime(&exp, timebuf));
   fprintf(
          stderr
                , "Warning: The time set exceeds the CA's expiration time\n");
   ask = 1;
  }
 } while(batch == 0 && ask != 0 && read_yesno("Is it ok to proceed? (y/N): ", 0) == 0);


 result = gnutls_x509_crt_set_expiration_time(crt, secs);
 if (result < 0) {
  fprintf(
         stderr
               , "set_expiration: %s\n",
   gnutls_strerror(result));
  app_exit(1);
 }

 if (!batch)
  fprintf(
         stderr
               , "\n\nExtensions.\n");


 if (crq && get_crq_extensions_status() != 0) {
  result = gnutls_x509_crt_set_crq_extensions(crt, crq);
  if (result < 0) {
   fprintf(
          stderr
                , "set_crq: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }
 }

 get_extensions_crt_set(1, crt);


 if (cinfo->v1_cert == 0) {

  if (proxy) {
   const char *policylanguage;
   char *policy;
   size_t policylen;
   int proxypathlen = get_path_len();

   if (!batch) {
    printf
        ("1.3.6.1.5.5.7.21.1 ::= id-ppl-inheritALL\n");
    printf
        ("1.3.6.1.5.5.7.21.2 ::= id-ppl-independent\n");
   }

   policylanguage =
       get_proxy_policy(&policy, &policylen);

   result =
       gnutls_x509_crt_set_proxy(crt, proxypathlen,
            policylanguage,
            policy, policylen);
   if (result < 0) {
    fprintf(
           stderr
                 , "set_proxy: %s\n",
     gnutls_strerror(result));
    app_exit(1);
   }
  }

  if (!proxy)
   ca_status = get_ca_status();
  if (ca_status)
   path_len = get_path_len();
  else
   path_len = -1;

  result =
      gnutls_x509_crt_set_basic_constraints(crt, ca_status,
         path_len);
  if (result < 0) {
   fprintf(
          stderr
                , "basic_constraints: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  client = get_tls_client_status();
  if (client != 0) {
   result = gnutls_x509_crt_set_key_purpose_oid(crt,
             "1.3.6.1.5.5.7.3.2",
             0);
   if (result < 0) {
    fprintf(
           stderr
                 , "key_kp: %s\n",
     gnutls_strerror(result));
    app_exit(1);
   }
  }

  crt_unique_ids_set(crt);

  is_ike = get_ipsec_ike_status();
  server = get_tls_server_status();

  get_dns_name_set(1, crt);
  get_uri_set(1, crt);
  get_ip_addr_set(1, crt);
  get_other_name_set(1, crt);
  get_policy_set(crt);

  if (server != 0) {
   result =
       gnutls_x509_crt_set_key_purpose_oid(crt,
        "1.3.6.1.5.5.7.3.1",
        0);
   if (result < 0) {
    fprintf(
           stderr
                 , "key_kp: %s\n",
     gnutls_strerror(result));
    app_exit(1);
   }
  } else if (!proxy) {
   get_email_set(1, crt);
  }

  if (!ca_status || server) {
   if (pk == GNUTLS_PK_RSA ||
       pk == GNUTLS_PK_GOST_01 ||
       pk == GNUTLS_PK_GOST_12_256 ||
       pk == GNUTLS_PK_GOST_12_512) {
    result = get_sign_status(server);
    if (result)
     usage |=
         128;

    result = get_encrypt_status(server);
    if (result)
     usage |=
         32;
   } else if (pk == GNUTLS_PK_ECDH_X25519 ||
                                   pk == GNUTLS_PK_ECDH_X448) {

                                usage |= 8;
   } else {
    usage |= 128;
   }

   if (is_ike) {
    result =
        gnutls_x509_crt_set_key_purpose_oid
        (crt, "1.3.6.1.5.5.7.3.17", 0);
    if (result < 0) {
     fprintf(
            stderr
                  , "key_kp: %s\n",
      gnutls_strerror(result));
     app_exit(1);
    }
   }

  } else if (ca_status) {

   if (get_sign_status(server))
    usage |= 128;
  }

  result = get_key_agreement_status();
  if (result)
   usage |= 8;

  result = get_data_encipherment_status();
  if (result)
   usage |= 16;

  result = get_non_repudiation_status();
  if (result)
   usage |= 64;

  result = get_ocsp_sign_status();
  if (result) {
   result =
       gnutls_x509_crt_set_key_purpose_oid
       (crt, "1.3.6.1.5.5.7.3.9", 0);
   if (result < 0) {
    fprintf(
           stderr
                 , "key_kp: %s\n",
     gnutls_strerror(result));
    app_exit(1);
   }
  }

  result = get_code_sign_status();
  if (result) {
   result =
       gnutls_x509_crt_set_key_purpose_oid
       (crt, "1.3.6.1.5.5.7.3.3", 0);
   if (result < 0) {
    fprintf(
           stderr
                 , "key_kp: %s\n",
     gnutls_strerror(result));
    app_exit(1);
   }
  }

  result = get_time_stamp_status();
  if (result) {
   result =
       gnutls_x509_crt_set_key_purpose_oid
       (crt, "1.3.6.1.5.5.7.3.8", 0);
   if (result < 0) {
    fprintf(
           stderr
                 , "key_kp: %s\n",
     gnutls_strerror(result));
    app_exit(1);
   }
  }

  result = get_email_protection_status();
  if (result) {
   result =
       gnutls_x509_crt_set_key_purpose_oid
       (crt, "1.3.6.1.5.5.7.3.4", 0);
   if (result < 0) {
    fprintf(
           stderr
                 , "key_kp: %s\n",
     gnutls_strerror(result));
    app_exit(1);
   }
  }

  if (ca_status) {
   result = get_cert_sign_status();
   if (result)
    usage |= 4;

   result = get_crl_sign_status();
   if (result)
    usage |= 2;


   crt_constraints_set(crt);
  }

  get_ocsp_issuer_set(crt);
  get_ca_issuers_set(crt);

  if (usage != 0) {



   if (is_ike && (get_sign_status(server) != 1))
    usage |= 64;
   result = gnutls_x509_crt_set_key_usage(crt, usage);
   if (result < 0) {
    fprintf(
           stderr
                 , "key_usage: %s\n",
     gnutls_strerror(result));
    app_exit(1);
   }
  }



  size = lbuffer_size;
  result = gnutls_x509_crt_get_key_id(crt, GNUTLS_KEYID_USE_SHA1, lbuffer, &size);
  if (result >= 0) {
   result =
       gnutls_x509_crt_set_subject_key_id(crt, lbuffer,
              size);
   if (result < 0) {
    fprintf(
           stderr
                 , "set_subject_key_id: %s\n",
     gnutls_strerror(result));
    app_exit(1);
   }
  }



  if (ca_crt != 
               ((void *)0)
                   ) {
   size = lbuffer_size;
   result =
       gnutls_x509_crt_get_subject_key_id(ca_crt,
              lbuffer,
              &size,
              
             ((void *)0)
                 );
   if (result >= 0) {
    result =
        gnutls_x509_crt_set_authority_key_id
        (crt, lbuffer, size);
    if (result < 0) {
     fprintf(
            stderr
                  ,
      "error setting authority key id: %s\n",
      gnutls_strerror(result));
     app_exit(1);
    }
   }
  }
 }



 if (cinfo->v1_cert != 0)
  vers = 1;
 else
  vers = 3;
 result = gnutls_x509_crt_set_version(crt, vers);
 if (result < 0) {
  fprintf(
         stderr
               , "error setting certificate version: %s\n",
   gnutls_strerror(result));
  app_exit(1);
 }

 if ((certtool_options.present.key_type || req_key_type != GNUTLS_PK_RSA) && req_key_type != pk) {
  if (pk != GNUTLS_PK_RSA || req_key_type != GNUTLS_PK_RSA_PSS) {
   fprintf(
          stderr
                , "cannot set certificate type (%s) incompatible with the key (%s)\n",
    gnutls_pk_get_name(req_key_type), gnutls_pk_get_name(pk));
   app_exit(1);
  }
 }



 if (pk == GNUTLS_PK_RSA_PSS && ca_status && key) {
  result = gnutls_x509_spki_init(&spki);
  if (result < 0) {
   fprintf(
          stderr
                , "spki_init: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  result = gnutls_privkey_get_spki(key, spki, 0);
  if (result >= 0) {
   result = gnutls_x509_crt_set_spki(crt, spki, 0);
   if (result < 0) {
    fprintf(
           stderr
                 , "error setting RSA-PSS SPKI information: %s\n",
     gnutls_strerror(result));
    app_exit(1);
   }
  }

  gnutls_x509_spki_deinit(spki);

 } else if (pk == GNUTLS_PK_RSA && req_key_type == GNUTLS_PK_RSA_PSS) {
  result = gnutls_x509_spki_init(&spki);
  if (result < 0) {
   fprintf(
          stderr
                , "spki_init: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  do { unsigned _salt_size; if (!cinfo->hash) { fprintf(
 stderr
 , "You must provide the hash algorithm and optionally the salt size for RSA-PSS\n"); app_exit(1); } if (certtool_options.present.salt_size) { _salt_size = certtool_options.value.salt_size; } else { _salt_size = gnutls_hash_get_len(cinfo->hash); } gnutls_x509_spki_set_rsa_pss_params(spki, cinfo->hash, _salt_size); } while(0);

  result = gnutls_x509_crt_set_spki(crt, spki, 0);
  if (result < 0) {
   fprintf(
          stderr
                , "error setting RSA-PSS SPKI information: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  gnutls_x509_spki_deinit(spki);
 }




 if (ca_status || !proxy) {
  get_crl_dist_point_set(crt);
 }

 *ret_key = key;
 return crt;

}

static gnutls_x509_crl_t
generate_crl(gnutls_x509_crt_t ca_crt, common_info_st * cinfo)
{
 gnutls_x509_crl_t crl;
 gnutls_x509_crt_t *crts;
 gnutls_x509_crl_t *crls;
 size_t size, crl_size;
 int result;
 unsigned int i;
 time_t secs, this_update, exp;

 crls = load_crl_list(0, &crl_size, cinfo);
 if (crls != 
            ((void *)0)
                ) {
  if (crl_size > 1) {
   fprintf(
          stderr
                , "load_crl: too many CRLs present\n");
   app_exit(1);
  }
  crl = crls[0];
  gnutls_free((void *) (crls)), crls=
 ((void *)0)
                  ;
 } else {
  result = gnutls_x509_crl_init(&crl);
  if (result < 0) {
   fprintf(
          stderr
                , "crl_init: %s\n", gnutls_strerror(result));
   app_exit(1);
  }
 }

 crts = load_cert_list(0, &size, cinfo);

 exp = get_crl_revocation_date();

 for (i = 0; i < size; i++) {
  result = gnutls_x509_crl_set_crt(crl, crts[i], exp);
  if (result < 0) {
   fprintf(
          stderr
                , "crl_set_crt: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }
  gnutls_x509_crt_deinit(crts[i]);
 }
 gnutls_free((void *) (crts)), crts=
((void *)0)
                 ;

 this_update = get_crl_this_update_date();

 result = gnutls_x509_crl_set_this_update(crl, this_update);
 if (result < 0) {
  fprintf(
         stderr
               , "this_update: %s\n",
   gnutls_strerror(result));
  app_exit(1);
 }

 secs = get_crl_next_update();

 result =
     gnutls_x509_crl_set_next_update(crl, secs);
 if (result < 0) {
  fprintf(
         stderr
               , "next_update: %s\n",
   gnutls_strerror(result));
  app_exit(1);
 }

 result = gnutls_x509_crl_set_version(crl, 2);
 if (result < 0) {
  fprintf(
         stderr
               , "set_version: %s\n",
   gnutls_strerror(result));
  app_exit(1);
 }



 if (ca_crt != 
              ((void *)0)
                  ) {
  size = lbuffer_size;
  result = gnutls_x509_crt_get_subject_key_id(ca_crt, lbuffer,
           &size, 
                 ((void *)0)
                     );
  if (result >= 0) {
   result =
       gnutls_x509_crl_set_authority_key_id(crl,
         lbuffer,
         size);
   if (result < 0) {
    fprintf(
           stderr
                 , "set_authority_key_id: %s\n",
     gnutls_strerror(result));
    app_exit(1);
   }

  }
 }

 {
  size_t serial_size;
  unsigned char serial[20];

  serial_size = sizeof(serial);

  get_crl_number(serial, &serial_size);

  result = gnutls_x509_crl_set_number(crl, serial, serial_size);
  if (result < 0) {
   fprintf(
          stderr
                , "error setting CRL serial: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }
 }

 return crl;
}

static gnutls_digest_algorithm_t get_dig_for_pub(gnutls_pubkey_t pubkey, common_info_st * cinfo)
{
 gnutls_digest_algorithm_t dig;
 int result;
 unsigned int mand;

 result =
     gnutls_pubkey_get_preferred_hash_algorithm(pubkey, &dig,
             &mand);
 if (result < 0) {
  {
   fprintf(
          stderr
                ,
    "crt_get_preferred_hash_algorithm: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }
 }


 if (mand == 0 && cinfo->hash != GNUTLS_DIG_UNKNOWN)
  dig = cinfo->hash;

 return dig;
}

static gnutls_digest_algorithm_t get_dig(gnutls_x509_crt_t crt, common_info_st * cinfo)
{
 gnutls_digest_algorithm_t dig;
 gnutls_pubkey_t pubkey;
 int result;

 result = gnutls_pubkey_init(&pubkey);
 if (result < 0) {
  fprintf(
         stderr
               , "memory error\n");
  app_exit(1);
 }

 result = gnutls_pubkey_import_x509(pubkey, crt, 0);
 if (result < 0) {
  {
   fprintf(
          stderr
                , "gnutls_pubkey_import_x509: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }
 }

 dig = get_dig_for_pub(pubkey, cinfo);

 gnutls_pubkey_deinit(pubkey);

 return dig;
}

void generate_self_signed(common_info_st * cinfo)
{
 gnutls_x509_crt_t crt;
 gnutls_datum_t out;
 gnutls_privkey_t key;
 int result;
 unsigned int flags = 0;

 fprintf(stdlog, "Generating a self signed certificate...\n");

 crt = generate_certificate(&key, 
                                 ((void *)0)
                                     , 0, cinfo);

 if (!key)
  key = load_private_key(1, cinfo);

 print_certificate_info(crt, stdlog, 0);

 fprintf(stdlog, "\n\nSigning certificate...\n");

 if (cinfo->rsa_pss_sign)
  flags |= GNUTLS_PRIVKEY_SIGN_FLAG_RSA_PSS;

 result =
     gnutls_x509_crt_privkey_sign(crt, crt, key, get_dig(crt, cinfo), flags);
 if (result < 0) {
  fprintf(
         stderr
               , "crt_sign: %s\n", gnutls_strerror(result));
  app_exit(1);
 }

 result =
     gnutls_x509_crt_export2(crt, outcert_format, &out);
 if (result < 0) {
  fprintf(
         stderr
               , "crt_export: %s\n", gnutls_strerror(result));
  app_exit(1);
 }

 fwrite(out.data, 1, out.size, outfile);
 gnutls_free((void *) (out.data)), out.data=
((void *)0)
                     ;

 gnutls_x509_crt_deinit(crt);
 gnutls_privkey_deinit(key);
}

static void generate_signed_certificate(common_info_st * cinfo)
{
 gnutls_x509_crt_t crt;
 gnutls_privkey_t key;
 gnutls_datum_t out;
 int result;
 gnutls_privkey_t ca_key;
 gnutls_x509_crt_t ca_crt;
 unsigned int flags = 0;

 fprintf(stdlog, "Generating a signed certificate...\n");

 ca_key = load_ca_private_key(cinfo);
 ca_crt = load_ca_cert(1, cinfo);

 crt = generate_certificate(&key, ca_crt, 0, cinfo);

 print_certificate_info(crt, stdlog, 0);

 fprintf(stdlog, "\n\nSigning certificate...\n");

 if (cinfo->rsa_pss_sign)
  flags |= GNUTLS_PRIVKEY_SIGN_FLAG_RSA_PSS;

 result =
     gnutls_x509_crt_privkey_sign(crt, ca_crt, ca_key,
      get_dig(ca_crt, cinfo), flags);
 if (result < 0) {
  fprintf(
         stderr
               , "crt_sign: %s\n", gnutls_strerror(result));
  app_exit(1);
 }

 result =
     gnutls_x509_crt_export2(crt, outcert_format, &out);
 if (result < 0) {
  fprintf(
         stderr
               , "crt_export: %s\n", gnutls_strerror(result));
  app_exit(1);
 }

 fwrite(out.data, 1, out.size, outfile);
 gnutls_free((void *) (out.data)), out.data=
((void *)0)
                     ;

 gnutls_x509_crt_deinit(crt);
 gnutls_x509_crt_deinit(ca_crt);
 gnutls_privkey_deinit(key);
 gnutls_privkey_deinit(ca_key);
}

static void generate_proxy_certificate(common_info_st * cinfo)
{
 gnutls_x509_crt_t crt, eecrt;
 gnutls_privkey_t key, eekey;
 gnutls_datum_t out;
 int result;
 unsigned int flags = 0;

 fprintf(stdlog, "Generating a proxy certificate...\n");

 eekey = load_ca_private_key(cinfo);
 eecrt = load_cert(1, cinfo);

 crt = generate_certificate(&key, eecrt, 1, cinfo);

 print_certificate_info(crt, stdlog, 0);

 fprintf(stdlog, "\n\nSigning certificate...\n");

 if (cinfo->rsa_pss_sign)
  flags |= GNUTLS_PRIVKEY_SIGN_FLAG_RSA_PSS;

 result =
     gnutls_x509_crt_privkey_sign(crt, eecrt, eekey, get_dig(eecrt, cinfo),
      flags);
 if (result < 0) {
  fprintf(
         stderr
               , "crt_sign: %s\n", gnutls_strerror(result));
  app_exit(1);
 }

 result =
     gnutls_x509_crt_export2(crt, outcert_format, &out);
 if (result < 0) {
  fprintf(
         stderr
               , "crt_export: %s\n", gnutls_strerror(result));
  app_exit(1);
 }

 fwrite(out.data, 1, out.size, outfile);
 gnutls_free((void *) (out.data)), out.data=
((void *)0)
                     ;

 gnutls_x509_crt_deinit(eecrt);
 gnutls_x509_crt_deinit(crt);
 gnutls_privkey_deinit(key);
 gnutls_privkey_deinit(eekey);
}

static void generate_signed_crl(common_info_st * cinfo)
{
 gnutls_x509_crl_t crl;
 int result;
 gnutls_privkey_t ca_key;
 gnutls_x509_crt_t ca_crt;

 fprintf(stdlog, "Generating a signed CRL...\n");

 ca_key = load_ca_private_key(cinfo);
 ca_crt = load_ca_cert(1, cinfo);
 crl = generate_crl(ca_crt, cinfo);

 fprintf(stdlog, "\n");
 result =
     gnutls_x509_crl_privkey_sign(crl, ca_crt, ca_key,
      get_dig(ca_crt, cinfo), 0);
 if (result < 0) {
  fprintf(
         stderr
               , "crl_privkey_sign: %s\n",
   gnutls_strerror(result));
  app_exit(1);
 }

 print_crl_info(crl, stdlog, cinfo);

 gnutls_privkey_deinit(ca_key);
 gnutls_x509_crl_deinit(crl);
 gnutls_x509_crt_deinit(ca_crt);
}

static void update_signed_certificate(common_info_st * cinfo)
{
 gnutls_x509_crt_t crt;
 int result;
 gnutls_privkey_t ca_key;
 gnutls_privkey_t pkey;
 gnutls_pubkey_t pubkey;
 gnutls_x509_crt_t ca_crt;
 gnutls_datum_t out;
 time_t tim;
 unsigned int flags = 0;

 fprintf(stdlog, "Generating a signed certificate...\n");


 ca_key = load_ca_private_key(cinfo);
 ca_crt = load_ca_cert(1, cinfo);
 crt = load_cert(1, cinfo);

 fprintf(
        stderr
              , "Activation/Expiration time.\n");
 tim = get_activation_date();

 result = gnutls_x509_crt_set_activation_time(crt, tim);
 if (result < 0) {
  fprintf(
         stderr
               , "set_activation: %s\n",
   gnutls_strerror(result));
  app_exit(1);
 }

 tim = get_expiration_date();
 result = gnutls_x509_crt_set_expiration_time(crt, tim);
 if (result < 0) {
  fprintf(
         stderr
               , "set_expiration: %s\n",
   gnutls_strerror(result));
  app_exit(1);
 }

 pkey = load_private_key(0, cinfo);
 pubkey = load_public_key_or_import(0, pkey, cinfo);

 if (pubkey) {
  fprintf(
         stderr
               , "Updating public key\n");
  result = gnutls_x509_crt_set_pubkey(crt, pubkey);
  if (result < 0) {
   fprintf(
          stderr
                , "cannot set public key: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }
 }

 fprintf(
        stderr
              , "\n\nSigning certificate...\n");

 if (cinfo->rsa_pss_sign)
  flags |= GNUTLS_PRIVKEY_SIGN_FLAG_RSA_PSS;

 result =
     gnutls_x509_crt_privkey_sign(crt, ca_crt, ca_key,
      get_dig(ca_crt, cinfo), flags);
 if (result < 0) {
  fprintf(
         stderr
               , "crt_sign: %s\n", gnutls_strerror(result));
  app_exit(1);
 }

 result =
     gnutls_x509_crt_export2(crt, outcert_format, &out);
 if (result < 0) {
  fprintf(
         stderr
               , "crt_export: %s\n", gnutls_strerror(result));
  app_exit(1);
 }

 fwrite(out.data, 1, out.size, outfile);
 gnutls_free((void *) (out.data)), out.data=
((void *)0)
                     ;

 gnutls_x509_crt_deinit(crt);
}

static void load_infile(const char *file)
{
 struct stat st;
 if (stat(file, &st) == 0) {
  fix_lbuffer(2*st.st_size);
 }

 infile = fopen(file, "rb");
 if (infile == 
              ((void *)0)
                  ) {
  fprintf(
         stderr
               , "Cannot open %s for reading\n", certtool_options.arg.infile);
  app_exit(1);
 }
}

static void cmd_parser(int argc, char **argv)
{
 int ret, privkey_op = 0;
 common_info_st cinfo;

 process_options(argc,argv);

 if (certtool_options.present.stdout_info) {

  stdlog = 
          stdout
                ;
 } else {
  stdlog = 
          stderr
                ;
 }

 if (certtool_options.present.generate_privkey || certtool_options.present.generate_request)
  privkey_op = 1;

 if (certtool_options.present.hex_numbers)
  full_format = GNUTLS_CRT_PRINT_FULL_NUMBERS;

 if (certtool_options.present.outfile) {
  outfile = safe_open_rw(certtool_options.arg.outfile, privkey_op);
  if (outfile == 
                ((void *)0)
                    ) {
   fprintf(
          stderr
                , "Cannot open %s for writing\n", certtool_options.arg.outfile);
   app_exit(1);
  }
  outfile_name = certtool_options.arg.outfile;
 } else {
  outfile = 
           stdout
                 ;
 }

 if (!certtool_options.present.infile) {

  if (certtool_options.present.certificate_info && certtool_options.present.load_certificate) {
   load_infile(certtool_options.arg.load_certificate);
  } else if (certtool_options.present.crq_info && certtool_options.present.load_request) {
   load_infile(certtool_options.arg.load_request);
  } else if (certtool_options.present.pubkey_info && certtool_options.present.load_pubkey) {
   load_infile(certtool_options.arg.load_pubkey);
  } else if (certtool_options.present.key_info && certtool_options.present.load_privkey) {
   load_infile(certtool_options.arg.load_privkey);
  } else if (certtool_options.present.to_rsa && certtool_options.present.load_privkey) {
   load_infile(certtool_options.arg.load_privkey);
  } else if (certtool_options.present.crl_info && certtool_options.present.load_crl) {
   load_infile(certtool_options.arg.load_crl);
  } else
   infile = 
           stdin
                ;
 } else {
  load_infile(certtool_options.arg.infile);
 }


 fix_lbuffer(0);

 if (certtool_options.present.inder)
  incert_format = GNUTLS_X509_FMT_DER;
 else
  incert_format = GNUTLS_X509_FMT_PEM;

 if (certtool_options.present.outder)
  outcert_format = GNUTLS_X509_FMT_DER;
 else
  outcert_format = GNUTLS_X509_FMT_PEM;


 if (certtool_options.present.rsa) {
  req_key_type = GNUTLS_PK_RSA;
 } else if (certtool_options.present.dsa) {
  req_key_type = GNUTLS_PK_DSA;
 } else if (certtool_options.present.ecc) {
  req_key_type = GNUTLS_PK_ECDSA;
 }

 if (certtool_options.present.key_type) {
  req_key_type = figure_key_type(certtool_options.arg.key_type);
  if (req_key_type == GNUTLS_PK_UNKNOWN)
   app_exit(1);
 }

 batch = 0;
 if (certtool_options.present.template) {
  batch = 1;
  template_parse(certtool_options.arg.template);
 }


 gnutls_global_set_log_function(tls_log_func);

 if (certtool_options.present.debug) {
  gnutls_global_set_log_level(certtool_options.value.debug);
  printf("Setting log level to %d\n", (int) certtool_options.value.debug);
 }

 if ((ret = gnutls_global_init()) < 0) {
  fprintf(
         stderr
               , "global_init: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 memset(&cinfo, 0, sizeof(cinfo));

 ask_pass = cinfo.ask_pass = certtool_options.enabled.ask_pass;
 cinfo.hash = GNUTLS_DIG_UNKNOWN;
 if (certtool_options.present.hash) {
  cinfo.hash = hash_to_id(certtool_options.arg.hash);
  if (cinfo.hash == GNUTLS_DIG_UNKNOWN) {
   fprintf(
          stderr
                , "invalid hash: %s\n", certtool_options.arg.hash);
   app_exit(1);
  }
 }
 if (certtool_options.present.verbose)
  cinfo.verbose = 1;

 if (certtool_options.present.seed) {
  gnutls_datum_t seed;
  decode_seed(&seed, certtool_options.arg.seed, strlen(certtool_options.arg.seed));

  cinfo.seed = seed.data;
  cinfo.seed_size = seed.size;
 }

 cinfo.batch = batch;
 cinfo.cprint = certtool_options.present.cprint;

 if (certtool_options.present.load_privkey)
  cinfo.privkey = certtool_options.arg.load_privkey;

 if (certtool_options.present.load_crl)
  cinfo.crl = certtool_options.arg.load_crl;

 if (certtool_options.present.load_data)
  cinfo.data_file = certtool_options.arg.load_data;

 cinfo.v1_cert = certtool_options.present.v1;
 if (certtool_options.present.no_crq_extensions)
  cinfo.crq_extensions = 0;
 else
  cinfo.crq_extensions = 1;

 if (certtool_options.present.load_pubkey)
  cinfo.pubkey = certtool_options.arg.load_pubkey;

 cinfo.pkcs8 = certtool_options.present.pkcs8;
 cinfo.incert_format = incert_format;
 cinfo.outcert_format = outcert_format;
 cinfo.outtext = certtool_options.enabled.text && outcert_format == GNUTLS_X509_FMT_PEM;

 if (certtool_options.present.load_certificate)
  cinfo.cert = certtool_options.arg.load_certificate;

 if (certtool_options.present.load_request)
  cinfo.request = certtool_options.arg.load_request;

 if (certtool_options.present.load_ca_certificate)
  cinfo.ca = certtool_options.arg.load_ca_certificate;

 if (certtool_options.present.load_ca_privkey)
  cinfo.ca_privkey = certtool_options.arg.load_ca_privkey;

 if (certtool_options.present.bits)
  cinfo.bits = certtool_options.value.bits;

 if (certtool_options.present.curve) {
  gnutls_ecc_curve_t curve = str_to_curve(certtool_options.arg.curve);
  cinfo.bits = (unsigned int)(((unsigned int)1<<31)|((unsigned int)(curve)));
 }

 if (certtool_options.present.sec_param)
  cinfo.sec_param = certtool_options.arg.sec_param;

 if (certtool_options.present.pkcs_cipher)
  cinfo.pkcs_cipher = certtool_options.arg.pkcs_cipher;

 if (certtool_options.present.password) {
  cinfo.password = certtool_options.arg.password;
  if (certtool_options.present.generate_privkey && cinfo.pkcs8 == 0) {
   fprintf(
          stderr
                , "Assuming PKCS #8 format...\n");
   cinfo.pkcs8 = 1;
  }
 }

 if (certtool_options.present.null_password) {
  cinfo.null_password = 1;
  cinfo.password = "";
 }

 if (certtool_options.present.provable)
  cinfo.provable = 1;

 if (certtool_options.present.empty_password) {
  cinfo.empty_password = 1;
  cinfo.password = "";
 }

 if (certtool_options.present.verify_profile) {
  if (strcasecmp(certtool_options.arg.verify_profile, "none") == 0) {
   cinfo.verification_profile = (gnutls_sec_param_t)GNUTLS_PROFILE_UNKNOWN;
  } else {
   cinfo.verification_profile = (gnutls_sec_param_t)gnutls_certificate_verification_profile_get_id(certtool_options.arg.verify_profile);
  }
 } else if (!certtool_options.present.verify_allow_broken) {
  if (certtool_options.present.verify_chain || certtool_options.present.verify) {
   fprintf(
          stderr
                , "Note that no verification profile was selected. In the future the medium profile will be enabled by default.\n");
   fprintf(
          stderr
                , "Use --verify-profile low to apply the default verification of NORMAL priority string.\n");
  }

 }

 if (certtool_options.present.sign_params)
  sign_params_to_flags(&cinfo, certtool_options.arg.sign_params);

 if (certtool_options.present.generate_self_signed)
  generate_self_signed(&cinfo);
 else if (certtool_options.present.generate_certificate)
  generate_signed_certificate(&cinfo);
 else if (certtool_options.present.generate_proxy)
  generate_proxy_certificate(&cinfo);
 else if (certtool_options.present.generate_crl)
  generate_signed_crl(&cinfo);
 else if (certtool_options.present.update_certificate)
  update_signed_certificate(&cinfo);
 else if (certtool_options.present.generate_privkey)
  generate_private_key(&cinfo);
 else if (certtool_options.present.generate_request)
  generate_request(&cinfo);
 else if (certtool_options.present.verify_provable_privkey)
  verify_provable_privkey(&cinfo);
 else if (certtool_options.present.verify_chain)
  verify_chain(&cinfo);
 else if (certtool_options.present.verify)
  verify_certificate(&cinfo);
 else if (certtool_options.present.verify_crl)
  verify_crl(&cinfo);
 else if (certtool_options.present.certificate_info)
  certificate_info(0, &cinfo);
 else if (certtool_options.present.dh_info)
  dh_info(infile, outfile, &cinfo);
 else if (certtool_options.present.certificate_pubkey)
  certificate_info(1, &cinfo);
 else if (certtool_options.present.key_info)
  privkey_info(&cinfo);
 else if (certtool_options.present.to_rsa) {
  privkey_to_rsa(&cinfo);
 } else if (certtool_options.present.pubkey_info)
  pubkey_info(
             ((void *)0)
                 , &cinfo);
 else if (certtool_options.present.fingerprint)
  certificate_fpr(&cinfo);
 else if (certtool_options.present.key_id)
  pubkey_keyid(&cinfo);
 else if (certtool_options.present.to_p12)
  generate_pkcs12(&cinfo);
 else if (certtool_options.present.p12_info)
  pkcs12_info(&cinfo);
 else if (certtool_options.present.generate_dh_params)
  generate_prime(outfile, 1, &cinfo);
 else if (certtool_options.present.get_dh_params)
  generate_prime(outfile, 0, &cinfo);
 else if (certtool_options.present.crl_info)
  crl_info(&cinfo);
 else if (certtool_options.present.p7_info)
  pkcs7_info(&cinfo, certtool_options.enabled.p7_show_data);
 else if (certtool_options.present.p7_generate)
  pkcs7_generate(&cinfo);
 else if (certtool_options.present.p7_sign)
  pkcs7_sign(&cinfo, 1);
 else if (certtool_options.present.p7_detached_sign)
  pkcs7_sign(&cinfo, 0);
 else if (certtool_options.present.p7_verify)
  verify_pkcs7(&cinfo, certtool_options.arg.verify_purpose, certtool_options.enabled.p7_show_data);
 else if (certtool_options.present.p8_info)
  pkcs8_info();
 else if (certtool_options.present.smime_to_p7)
  smime_to_pkcs7();
 else if (certtool_options.present.to_p8)
  generate_pkcs8(&cinfo);
 else if (certtool_options.present.crq_info)
  crq_info(&cinfo);
 else
  usage (
 stdout
 , (1));

 if (outfile != 
               stdout
                     )
  fclose(outfile);


 free(cinfo.seed);



 gnutls_global_deinit();
}

void certificate_info(int pubkey, common_info_st * cinfo)
{
 gnutls_x509_crt_t *crts = 
                          ((void *)0)
                              ;
 size_t size;
 gnutls_datum_t out;
 int ret, i, count;
 gnutls_datum_t pem;
 unsigned int crt_num;

 pem.data = (void *) _gnutls_fread_file(infile, 0, &size);
 pem.size = size;

 if (!pem.data) {
  fprintf(
         stderr
               , "%s", infile ? "file" : "standard input");
  app_exit(1);
 }

 ret =
     gnutls_x509_crt_list_import2(&crts, &crt_num, &pem, incert_format, 0);
 if (ret < 0) {
  fprintf(
         stderr
               , "import error: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 free(pem.data);

 count = crt_num;

 if (count > 1 && outcert_format == GNUTLS_X509_FMT_DER) {
  fprintf(
         stderr
               ,
   "Cannot output multiple certificates in DER format; "
   "using PEM instead\n");
  outcert_format = GNUTLS_X509_FMT_PEM;
 }

 for (i = 0; i < count; i++) {
  if (i > 0)
   fprintf(outfile, "\n");

  if (cinfo->outtext)
   print_certificate_info(crts[i], outfile, 1);

  if (pubkey) {

   pubkey_info(crts[i], cinfo);
  } else {
   ret =
       gnutls_x509_crt_export2(crts[i], outcert_format, &out);
   if (ret < 0) {
    fprintf(
           stderr
                 , "export error: %s\n",
     gnutls_strerror(ret));
    app_exit(1);
   }

   fwrite(out.data, 1, out.size, outfile);
   gnutls_free((void *) (out.data)), out.data=
  ((void *)0)
                       ;

   gnutls_x509_crt_deinit(crts[i]);
  }

 }
 gnutls_free((void *) (crts)), crts=
((void *)0)
                 ;
}

static void
print_certificate_info(gnutls_x509_crt_t crt, FILE * out, unsigned int all)
{
 gnutls_datum_t data;
 int ret;

 if (all)
  ret = gnutls_x509_crt_print(crt, full_format, &data);
 else
  ret =
      gnutls_x509_crt_print(crt,
       GNUTLS_CRT_PRINT_UNSIGNED_FULL,
       &data);
 if (ret == 0) {
  fprintf(out, "%s\n", data.data);
  gnutls_free((void *) (data.data)), data.data=
 ((void *)0)
                       ;
 }

 if (out == 
           stderr 
                  && batch == 0)
  if (read_yesno("Is the above information ok? (y/N): ", 0)
      == 0) {
   app_exit(1);
  }
}

static void print_crl_info(gnutls_x509_crl_t crl, FILE * out, common_info_st *cinfo)
{
 gnutls_datum_t data;
 gnutls_datum_t cout;
 int ret;

 if (cinfo->outtext) {
  ret = gnutls_x509_crl_print(crl, full_format, &data);
  if (ret < 0) {
   fprintf(
          stderr
                , "crl_print: %s\n", gnutls_strerror(ret));
   app_exit(1);
  }
  fprintf(out, "%s\n", data.data);

  gnutls_free((void *) (data.data)), data.data=
 ((void *)0)
                       ;
 }

 ret =
     gnutls_x509_crl_export2(crl, outcert_format, &cout);
 if (ret < 0) {
  fprintf(
         stderr
               , "crl_export: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 fwrite(cout.data, 1, cout.size, outfile);
 gnutls_free((void *) (cout.data)), cout.data=
((void *)0)
                      ;
}

void crl_info(common_info_st *cinfo)
{
 gnutls_x509_crl_t crl;
 int ret;
 size_t size;
 gnutls_datum_t pem;

 ret = gnutls_x509_crl_init(&crl);
 if (ret < 0) {
  fprintf(
         stderr
               , "crl_init: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 pem.data = (void *) _gnutls_fread_file(infile, 0, &size);
 pem.size = size;

 if (!pem.data) {
  fprintf(
         stderr
               , "%s", infile ? "file" : "standard input");
  app_exit(1);
 }

 ret = gnutls_x509_crl_import(crl, &pem, incert_format);

 free(pem.data);
 if (ret < 0) {
  fprintf(
         stderr
               , "import error: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 print_crl_info(crl, outfile, cinfo);

 gnutls_x509_crl_deinit(crl);
}

static void print_crq_info(gnutls_x509_crq_t crq, FILE * out, common_info_st *cinfo)
{
 gnutls_datum_t data;
 int ret;
 size_t size;

 if (cinfo->outtext) {
  ret = gnutls_x509_crq_print(crq, full_format, &data);
  if (ret < 0) {
   fprintf(
          stderr
                , "crq_print: %s\n",
    gnutls_strerror(ret));
   app_exit(1);
  }

  fprintf(out, "%s\n", data.data);

  gnutls_free((void *) (data.data)), data.data=
 ((void *)0)
                       ;
 }

 ret = gnutls_x509_crq_verify(crq, 0);
 if (ret < 0) {
  fprintf(cinfo->outtext ? out : 
                                stderr
                                      ,
   "Self signature: FAILED\n\n");
 } else {
  fprintf(cinfo->outtext ? out : 
                                stderr
                                      ,
   "Self signature: verified\n\n");
 }

 size = lbuffer_size;
 ret = gnutls_x509_crq_export(crq, outcert_format, lbuffer, &size);
 if (ret < 0) {
  fprintf(
         stderr
               , "crq_export: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 fwrite(lbuffer, 1, size, outfile);
}

void crq_info(common_info_st *cinfo)
{
 gnutls_x509_crq_t crq;
 int ret;
 size_t size;
 gnutls_datum_t pem;

 ret = gnutls_x509_crq_init(&crq);
 if (ret < 0) {
  fprintf(
         stderr
               , "crq_init: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 pem.data = (void *) _gnutls_fread_file(infile, 0, &size);
 pem.size = size;

 if (!pem.data) {
  fprintf(
         stderr
               , "%s", infile ? "file" : "standard input");
  app_exit(1);
 }

 ret = gnutls_x509_crq_import(crq, &pem, incert_format);

 free(pem.data);
 if (ret < 0) {
  fprintf(
         stderr
               , "import error: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 print_crq_info(crq, outfile, cinfo);

 gnutls_x509_crq_deinit(crq);
}

void privkey_info(common_info_st * cinfo)
{
 gnutls_x509_privkey_t key;
 size_t size;
 int ret;
 gnutls_datum_t pem;
 const char *pass;
 unsigned int flags = 0;

 size = fread(lbuffer, 1, lbuffer_size - 1, infile);
 lbuffer[size] = 0;

 ret = gnutls_x509_privkey_init(&key);
 if (ret < 0) {
  fprintf(
         stderr
               , "privkey_init: %s", gnutls_strerror(ret));
  app_exit(1);
 }

 pem.data = lbuffer;
 pem.size = size;

 ret =
     gnutls_x509_privkey_import2(key, &pem, incert_format, 
                                                          ((void *)0)
                                                              , GNUTLS_PKCS_PLAIN);


 if (ret == -24) {
  fprintf(
         stderr
               , "Encrypted structure detected...\n");

  if (outcert_format == GNUTLS_X509_FMT_DER)
   pkcs8_info_int(&pem, incert_format, 1, 
                                         stderr
                                               , "");
  else
   pkcs8_info_int(&pem, incert_format, 1, outfile, "");

  pass = get_password(cinfo, &flags, 0);

  ret = gnutls_x509_privkey_import2(key, &pem,
        incert_format, pass,
        flags);
 }
 if (ret < 0) {
  fprintf(
         stderr
               , "import error: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }


 cinfo->pkcs8 = 0;

 print_private_key(outfile, cinfo, key);

 ret = gnutls_x509_privkey_verify_params(key);
 if (ret < 0)
  fprintf(outfile,
   "\n** Private key parameters validation failed **\n\n");

 gnutls_x509_privkey_deinit(key);
}

static void privkey_to_rsa(common_info_st * cinfo)
{
 gnutls_x509_privkey_t key;
 size_t size;
 int ret;
 gnutls_datum_t pem;
 const char *pass;
 unsigned int flags = 0;
 gnutls_datum_t out;

 size = fread(lbuffer, 1, lbuffer_size - 1, infile);
 lbuffer[size] = 0;

 ret = gnutls_x509_privkey_init(&key);
 if (ret < 0) {
  fprintf(
         stderr
               , "privkey_init: %s", gnutls_strerror(ret));
  app_exit(1);
 }

 pem.data = lbuffer;
 pem.size = size;

 ret =
     gnutls_x509_privkey_import2(key, &pem, incert_format, 
                                                          ((void *)0)
                                                              , GNUTLS_PKCS_PLAIN);


 if (ret == -24) {
  fprintf(
         stderr
               , "Encrypted structure detected...\n");

  if (outcert_format == GNUTLS_X509_FMT_DER)
   pkcs8_info_int(&pem, incert_format, 1, 
                                         stderr
                                               , "");
  else
   pkcs8_info_int(&pem, incert_format, 1, outfile, "");

  pass = get_password(cinfo, &flags, 0);

  ret = gnutls_x509_privkey_import2(key, &pem,
        incert_format, pass,
        flags);
 }
 if (ret < 0) {
  fprintf(
         stderr
               , "import error: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 ret = gnutls_x509_privkey_get_pk_algorithm(key);
 if (ret != GNUTLS_PK_RSA && ret != GNUTLS_PK_RSA_PSS) {
  fprintf(
         stderr
               , "unexpected key type: %s\n", gnutls_pk_get_name(ret));
  app_exit(1);
 }

 gnutls_x509_privkey_set_flags(key, GNUTLS_PRIVKEY_FLAG_EXPORT_COMPAT);

 ret = gnutls_x509_privkey_export2(key, cinfo->outcert_format, &out);
 if (ret < 0) {
  fprintf(
         stderr
               , "export error: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 fwrite(out.data, out.size, 1, outfile);
 gnutls_free((void *) (out.data)), out.data=
((void *)0)
                     ;

 gnutls_x509_privkey_deinit(key);
}




void generate_request(common_info_st * cinfo)
{
 gnutls_x509_crq_t crq;
 gnutls_x509_privkey_t xkey;
 gnutls_pubkey_t pubkey;
 gnutls_privkey_t pkey;
 int ret, ca_status, path_len, pk;
 const char *pass;
 unsigned int usage = 0;

 fprintf(
        stderr
              , "Generating a PKCS #10 certificate request...\n");

 ret = gnutls_x509_crq_init(&crq);
 if (ret < 0) {
  fprintf(
         stderr
               , "crq_init: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }



 pkey = load_private_key(0, cinfo);
 if (!pkey) {
  if (certtool_options.present.load_pubkey) {
   fprintf(
          stderr
                , "--load-pubkey was specified without corresponding --load-privkey\n");
   app_exit(1);
  }

  ret = gnutls_privkey_init(&pkey);
  if (ret < 0) {
   fprintf(
          stderr
                , "privkey_init: %s\n",
    gnutls_strerror(ret));
   app_exit(1);
  }

  xkey = generate_private_key_int(cinfo);

  print_private_key(outfile, cinfo, xkey);

  ret =
      gnutls_privkey_import_x509(pkey, xkey,
            GNUTLS_PRIVKEY_IMPORT_AUTO_RELEASE);
  if (ret < 0) {
   fprintf(
          stderr
                , "privkey_import_x509: %s\n",
    gnutls_strerror(ret));
   app_exit(1);
  }
 }

 pubkey = load_public_key_or_import(1, pkey, cinfo);

 pk = gnutls_pubkey_get_pk_algorithm(pubkey, 
                                            ((void *)0)
                                                );



 get_dn_crq_set(crq);

 get_country_crq_set(crq);
 get_state_crq_set(crq);
 get_locality_crq_set(crq);
 get_organization_crq_set(crq);
 get_unit_crq_set(crq);
 get_cn_crq_set(crq);

 get_uid_crq_set(crq);
 get_dc_set(2, crq);
 get_oid_crq_set(crq);

 get_dns_name_set(2, crq);
 get_uri_set(2, crq);
 get_ip_addr_set(2, crq);
 get_email_set(2, crq);
 get_other_name_set(2, crq);
 get_extensions_crt_set(2, crq);

 pass = get_challenge_pass();

 if (pass != 
            ((void *)0) 
                 && pass[0] != 0) {
  ret = gnutls_x509_crq_set_challenge_password(crq, pass);
  if (ret < 0) {
   fprintf(
          stderr
                , "set_pass: %s\n",
    gnutls_strerror(ret));
   app_exit(1);
  }
 }

 if (cinfo->crq_extensions != 0) {
  ca_status = get_ca_status();
  if (ca_status)
   path_len = get_path_len();
  else
   path_len = -1;

  ret =
      gnutls_x509_crq_set_basic_constraints(crq, ca_status,
         path_len);
  if (ret < 0) {
   fprintf(
          stderr
                , "set_basic_constraints: %s\n",
    gnutls_strerror(ret));
   app_exit(1);
  }

  if (pk == GNUTLS_PK_RSA ||
      pk == GNUTLS_PK_GOST_01 ||
      pk == GNUTLS_PK_GOST_12_256 ||
      pk == GNUTLS_PK_GOST_12_512) {
   ret = get_sign_status(1);
   if (ret)
    usage |= 128;



   ret = get_encrypt_status(1);
   if (ret)
    usage |= 32;
   else
    usage |= 128;
  } else {
   if (get_encrypt_status(1))
    fprintf(
           stderr
                 , "warning: this algorithm does not support encryption; disabling the encryption flag\n");

   usage |= 128;
  }

  ret = get_code_sign_status();
  if (ret) {
   ret = gnutls_x509_crq_set_key_purpose_oid
       (crq, "1.3.6.1.5.5.7.3.3", 0);
   if (ret < 0) {
    fprintf(
           stderr
                 , "key_kp: %s\n",
     gnutls_strerror(ret));
    app_exit(1);
   }
  }

  ret = get_time_stamp_status();
  if (ret) {
   ret = gnutls_x509_crq_set_key_purpose_oid
       (crq, "1.3.6.1.5.5.7.3.8", 0);
   if (ret < 0) {
    fprintf(
           stderr
                 , "key_kp: %s\n",
     gnutls_strerror(ret));
    app_exit(1);
   }
  }

  ret = get_email_protection_status();
  if (ret) {
   ret =
       gnutls_x509_crq_set_key_purpose_oid
       (crq, "1.3.6.1.5.5.7.3.4", 0);
   if (ret < 0) {
    fprintf(
           stderr
                 , "key_kp: %s\n",
     gnutls_strerror(ret));
    app_exit(1);
   }
  }

  ret = get_ipsec_ike_status();
  if (ret) {
   ret = gnutls_x509_crq_set_key_purpose_oid
       (crq, "1.3.6.1.5.5.7.3.17", 0);
   if (ret < 0) {
    fprintf(
           stderr
                 , "key_kp: %s\n",
     gnutls_strerror(ret));
    app_exit(1);
   }
  }

  ret = get_ocsp_sign_status();
  if (ret) {
   ret = gnutls_x509_crq_set_key_purpose_oid
       (crq, "1.3.6.1.5.5.7.3.9", 0);
   if (ret < 0) {
    fprintf(
           stderr
                 , "key_kp: %s\n",
     gnutls_strerror(ret));
    app_exit(1);
   }
  }

  if (ca_status) {
   ret = get_cert_sign_status();
   if (ret)
    usage |= 4;

   ret = get_crl_sign_status();
   if (ret)
    usage |= 2;


  }

  ret = gnutls_x509_crq_set_key_usage(crq, usage);
  if (ret < 0) {
   fprintf(
          stderr
                , "key_usage: %s\n",
    gnutls_strerror(ret));
   app_exit(1);
  }

  ret = get_tls_client_status();
  if (ret != 0) {
   ret = gnutls_x509_crq_set_key_purpose_oid
       (crq, "1.3.6.1.5.5.7.3.2", 0);
   if (ret < 0) {
    fprintf(
           stderr
                 , "key_kp: %s\n",
     gnutls_strerror(ret));
    app_exit(1);
   }
  }

  ret = get_tls_server_status();
  if (ret != 0) {
   ret = gnutls_x509_crq_set_key_purpose_oid
       (crq, "1.3.6.1.5.5.7.3.1", 0);
   if (ret < 0) {
    fprintf(
           stderr
                 , "key_kp: %s\n",
     gnutls_strerror(ret));
    app_exit(1);
   }
  }

  get_key_purpose_set(2, crq);

  get_tlsfeatures_set(2, crq);
 }

 ret = gnutls_x509_crq_set_pubkey(crq, pubkey);
 if (ret < 0) {
  fprintf(
         stderr
               , "set_key: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 ret =
     gnutls_x509_crq_privkey_sign(crq, pkey,
      get_dig_for_pub(pubkey, cinfo), 0);
 if (ret < 0) {
  fprintf(
         stderr
               , "sign: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 print_crq_info(crq, outfile, cinfo);

 gnutls_x509_crq_deinit(crq);
 gnutls_privkey_deinit(pkey);
 gnutls_pubkey_deinit(pubkey);

}

static void print_verification_res(FILE * outfile, unsigned int output);

static const char *get_signature_algo(gnutls_x509_crt_t crt)
{
 int ret;
 static char oid[128];

 ret = gnutls_x509_crt_get_signature_algorithm(crt);
 if (ret < 0 || ret == GNUTLS_SIGN_UNKNOWN) {
  size_t oid_size = sizeof(oid);
  ret = gnutls_x509_crt_get_signature_oid(crt, oid, &oid_size);
  if (ret < 0)
   return 
         ((void *)0)
             ;
  return oid;
 }

 return gnutls_sign_get_name(ret);
}

static int detailed_verification(gnutls_x509_crt_t cert,
     gnutls_x509_crt_t issuer,
     gnutls_x509_crl_t crl,
     unsigned int verification_output)
{
 char tmp[255];
 size_t tmp_size;
 gnutls_datum_t name = {
                       ((void *)0)
                           ,0}, issuer_name = {
                                               ((void *)0)
                                                   ,0};
 gnutls_datum_t serial = {
                         ((void *)0)
                             ,0};
 int ret;

 ret =
     gnutls_x509_crt_get_issuer_dn3(cert, &issuer_name, 0);
 if (ret < 0) {
  fprintf(
         stderr
               , "gnutls_x509_crt_get_issuer_dn: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }

 ret = gnutls_x509_crt_get_dn3(cert, &name, 0);
 if (ret < 0) {
  if (ret == -56) {
   name.data = 0;
   name.size = 0;
  } else {
   fprintf(
          stderr
                , "gnutls_x509_crt_get_dn: %s\n",
    gnutls_strerror(ret));
   app_exit(1);
  }
 }

 fprintf(outfile, "\tSubject: %s\n", name.data);
 fprintf(outfile, "\tIssuer: %s\n", issuer_name.data);

 if (issuer != 
              ((void *)0)
                  ) {
  gnutls_free((void *) (issuer_name.data)), issuer_name.data=
 ((void *)0)
                              ;
  ret =
      gnutls_x509_crt_get_dn3(issuer, &issuer_name, 0);
  if (ret < 0) {
   fprintf(
          stderr
                ,
    "gnutls_x509_crt_get_issuer_dn: %s\n",
    gnutls_strerror(ret));
   app_exit(1);
  }

  fprintf(outfile, "\tChecked against: %s\n", issuer_name.data);
 }

 fprintf(outfile, "\tSignature algorithm: %s\n", get_signature_algo(cert));

 if (crl != 
           ((void *)0)
               ) {
  gnutls_datum_t data;
  gnutls_free((void *) (issuer_name.data)), issuer_name.data=
 ((void *)0)
                              ;

  ret =
      gnutls_x509_crl_get_issuer_dn3(crl, &issuer_name, 0);
  if (ret < 0) {
   fprintf(
          stderr
                ,
    "gnutls_x509_crl_get_issuer_dn: %s\n",
    gnutls_strerror(ret));
   app_exit(1);
  }

  tmp_size = sizeof(tmp);
  ret =
      gnutls_x509_crl_get_number(crl, tmp, &tmp_size, 
                                                     ((void *)0)
                                                         );
  if (ret < 0) {
   serial.data = (void*)gnutls_strdup("unnumbered");
  } else {
   data.data = (void *) tmp;
   data.size = tmp_size;

   ret = gnutls_hex_encode2(&data, &serial);
   if (ret < 0) {
    fprintf(
           stderr
                 , "gnutls_hex_encode: %s\n",
     gnutls_strerror(ret));
    app_exit(1);
   }
  }
  fprintf(outfile, "\tChecked against CRL[%s] of: %s\n",
   serial.data, issuer_name.data);
 }

 fprintf(outfile, "\tOutput: ");
 print_verification_res(outfile, verification_output);

 fputs("\n\n", outfile);

 gnutls_free((void *) (serial.data)), serial.data=
((void *)0)
                        ;
 gnutls_free((void *) (name.data)), name.data=
((void *)0)
                      ;
 gnutls_free((void *) (issuer_name.data)), issuer_name.data=
((void *)0)
                             ;

 return 0;
}

static void load_data(common_info_st *cinfo, gnutls_datum_t *data)
{
 FILE *fp;
 size_t size;

 fp = fopen(cinfo->data_file, "r");
 if (fp == 
          ((void *)0)
              ) {
  fprintf(
         stderr
               , "Could not open %s\n", cinfo->data_file);
  app_exit(1);
 }

 data->data = (void *) _gnutls_fread_file(fp, 0, &size);
 if (data->data == 
                  ((void *)0)
                      ) {
  fprintf(
         stderr
               , "Error reading data file");
  app_exit(1);
 }

 data->size = size;
 fclose(fp);
}

static gnutls_x509_trust_list_t load_tl(common_info_st * cinfo)
{
 gnutls_x509_trust_list_t list;
 int ret;

 ret = gnutls_x509_trust_list_init(&list, 0);
 if (ret < 0) {
  fprintf(
         stderr
               , "gnutls_x509_trust_list_init: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }

 if (cinfo->ca == 
                 ((void *)0)
                     ) {
  ret = gnutls_x509_trust_list_add_system_trust(list, 0, 0);
  if (ret < 0) {
   fprintf(
          stderr
                , "Error loading system trust: %s\n",
    gnutls_strerror(ret));
   app_exit(1);
  }
  fprintf(
         stderr
               , "Loaded system trust (%d CAs available)\n", ret);
 } else if (cinfo->ca != 
                        ((void *)0)
                            ) {
  ret = gnutls_x509_trust_list_add_trust_file(list, cinfo->ca, cinfo->crl, cinfo->incert_format, 0, 0);
  if (ret < 0) {
   int ret2 = gnutls_x509_trust_list_add_trust_file(list, cinfo->ca, cinfo->crl, GNUTLS_X509_FMT_PEM, 0, 0);
   if (ret2 >= 0)
    ret = ret2;
  }

  if (ret < 0) {
   fprintf(
          stderr
                , "gnutls_x509_trust_add_trust_file: %s\n",
    gnutls_strerror(ret));
   app_exit(1);
  }

  fprintf(
         stderr
               , "Loaded CAs (%d available)\n", ret);
 }

 return list;
}




static gnutls_x509_trust_list_t load_tl_from_cert_chain(const char *cert, int cert_size)
{
 gnutls_datum_t tmp;
 gnutls_x509_crt_t *x509_cert_list = 
                                    ((void *)0)
                                        ;
 gnutls_x509_crl_t *x509_crl_list = 
                                   ((void *)0)
                                       ;
 unsigned x509_ncerts, x509_ncrls = 0;
 unsigned i;
 int ret;
 gnutls_x509_trust_list_t list;


 ret = gnutls_x509_trust_list_init(&list, 0);
 if (ret < 0) {
  fprintf(
         stderr
               , "gnutls_x509_trust_list_init: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }

 tmp.data = (void *) cert;
 tmp.size = cert_size;

 ret = gnutls_x509_crt_list_import2(&x509_cert_list, &x509_ncerts, &tmp, GNUTLS_X509_FMT_PEM, 0);
 if (ret < 0 || x509_ncerts < 1) {
  fprintf(
         stderr
               , "error parsing CRTs: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }

 ret =
     gnutls_x509_crl_list_import2(&x509_crl_list,
      &x509_ncrls, &tmp,
      GNUTLS_X509_FMT_PEM, 0);
 if (ret < 0) {
  x509_crl_list = 
                 ((void *)0)
                     ;
  x509_ncrls = 0;
 }


 ret =
     gnutls_x509_trust_list_add_cas(list, &x509_cert_list[x509_ncerts - 1],
        1, 0);
 if (ret < 0) {
  fprintf(
         stderr
               , "gnutls_x509_trust_add_cas: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }


 if (x509_ncrls > 0) {
  ret =
      gnutls_x509_trust_list_add_crls(list, x509_crl_list,
          x509_ncrls, 0, 0);
  if (ret < 0) {
   fprintf(
          stderr
                , "gnutls_x509_trust_add_crls: %s\n",
    gnutls_strerror(ret));
   app_exit(1);
  }
 }

 if (x509_ncerts > 1) {
  for (i=0;i<x509_ncerts-1;i++)
   gnutls_x509_crt_deinit(x509_cert_list[i]);
 }
 gnutls_free((void *) (x509_cert_list)), x509_cert_list=
((void *)0)
                           ;
 gnutls_free((void *) (x509_crl_list)), x509_crl_list=
((void *)0)
                          ;

 return list;
}







static int
_verify_x509_mem(const void *cert, int cert_size, common_info_st *cinfo,
   unsigned use_system_trust,
   const char *purpose,
   const char *hostname, const char *email)
{
 int ret;
 unsigned i;
 gnutls_datum_t tmp;
 gnutls_x509_crt_t *x509_cert_list = 
                                    ((void *)0)
                                        ;
 unsigned int x509_ncerts;
 gnutls_x509_trust_list_t list;
 unsigned int output;
 unsigned vflags;

 if (use_system_trust != 0 || cinfo->ca != 
                                          ((void *)0)
                                              ) {
  list = load_tl(cinfo);
  if (list == 
             ((void *)0)
                 ) {
   fprintf(
          stderr
                , "error loading trust list\n");
  }

 } else {
  list = load_tl_from_cert_chain(cert, cert_size);
  if (list == 
             ((void *)0)
                 ) {
   fprintf(
          stderr
                , "error loading trust list\n");
  }
 }

 tmp.data = (void *) cert;
 tmp.size = cert_size;

 ret =
     gnutls_x509_crt_list_import2(&x509_cert_list,
      &x509_ncerts, &tmp,
      GNUTLS_X509_FMT_PEM, 0);
 if (ret < 0 || x509_ncerts < 1) {
  fprintf(
         stderr
               , "error parsing CRTs: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }

 vflags = GNUTLS_VERIFY_DO_NOT_ALLOW_SAME;
 vflags |= (((unsigned)cinfo->verification_profile)<<24);

 if (certtool_options.present.verify_allow_broken)
  vflags |= (GNUTLS_VERIFY_ALLOW_SIGN_RSA_MD2|GNUTLS_VERIFY_ALLOW_SIGN_RSA_MD5);


 if (purpose || hostname || email) {
  gnutls_typed_vdata_st vdata[2];
  unsigned vdata_size = 0;

  if (purpose) {
   vdata[vdata_size].type = GNUTLS_DT_KEY_PURPOSE_OID;
   vdata[vdata_size].data = (void*)purpose;
   vdata[vdata_size].size = strlen(purpose);
   vdata_size++;
  }

  if (hostname) {
   vdata[vdata_size].type = GNUTLS_DT_DNS_HOSTNAME;
   vdata[vdata_size].data = (void*)hostname;
   vdata[vdata_size].size = strlen(hostname);
   vdata_size++;
  } else if (email) {
   vdata[vdata_size].type = GNUTLS_DT_RFC822NAME;
   vdata[vdata_size].data = (void*)email;
   vdata[vdata_size].size = strlen(email);
   vdata_size++;
  }

  ret =
      gnutls_x509_trust_list_verify_crt2(list, x509_cert_list,
             x509_ncerts,
             vdata,
             vdata_size,
             vflags,
             &output,
             detailed_verification);
 } else {
  ret =
      gnutls_x509_trust_list_verify_crt(list, x509_cert_list,
            x509_ncerts,
            vflags,
            &output,
            detailed_verification);
 }
 if (ret < 0) {
  fprintf(
         stderr
               , "gnutls_x509_trusted_list_verify_crt: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }

 fprintf(outfile, "Chain verification output: ");
 print_verification_res(outfile, output);

 fprintf(outfile, "\n\n");

 gnutls_x509_trust_list_deinit(list, 1);
 for (i=0;i<x509_ncerts;i++)
  gnutls_x509_crt_deinit(x509_cert_list[i]);
 gnutls_free((void *) (x509_cert_list)), x509_cert_list=
((void *)0)
                           ;


 if (output != 0)
  exit(
      1
                  );

 return 0;
}

static void print_verification_res(FILE * out, unsigned int output)
{
 gnutls_datum_t pout;
 int ret;

 if (output) {
  fprintf(out, "Not verified.");
 } else {
  fprintf(out, "Verified.");
 }

 ret =
     gnutls_certificate_verification_status_print(output,
        GNUTLS_CRT_X509,
        &pout, 0);
 if (ret < 0) {
  fprintf(
         stderr
               , "error: %s\n", gnutls_strerror(ret));
  app_exit(
          1
                      );
 }

 fprintf(out, " %s", pout.data);
 gnutls_free((void *) (pout.data)), pout.data=
((void *)0)
                      ;
}

static void verify_chain(common_info_st * cinfo)
{
 char *buf;
 size_t size;

 if (cinfo->ca != 
                 ((void *)0)
                     ) {
  fprintf(
         stderr
               , "This option cannot be combined with --load-ca-certificate\n");
  app_exit(1);
 }

 buf = (void *) _gnutls_fread_file(infile, 0, &size);
 if (buf == 
           ((void *)0)
               ) {
  fprintf(
         stderr
               , "Error reading certificate chain");
  app_exit(1);
 }

 _verify_x509_mem(buf, size, cinfo, 0, certtool_options.arg.verify_purpose,
    certtool_options.arg.verify_hostname, certtool_options.arg.verify_email);
 free(buf);
}

static void verify_certificate(common_info_st * cinfo)
{
 char *cert;
 char *cas = 
            ((void *)0)
                ;
 size_t cert_size;

 cert = (void *) _gnutls_fread_file(infile, 0, &cert_size);
 if (cert == 
            ((void *)0)
                ) {
  fprintf(
         stderr
               , "Error reading certificate chain");
  app_exit(1);
 }

 _verify_x509_mem(cert, cert_size, cinfo, 1,
    certtool_options.arg.verify_purpose,
    certtool_options.arg.verify_hostname, certtool_options.arg.verify_email);
 free(cert);
 free(cas);


}

void verify_crl(common_info_st * cinfo)
{
 size_t size;
 gnutls_datum_t dn;
 unsigned int output;
 int ret, rc;
 gnutls_datum_t pem, pout;
 gnutls_x509_crl_t crl;
 gnutls_x509_crt_t issuer;

 issuer = load_ca_cert(1, cinfo);

 fprintf(outfile, "\nCA certificate:\n");

 ret = gnutls_x509_crt_get_dn3(issuer, &dn, 0);
 if (ret < 0) {
  fprintf(
         stderr
               , "crt_get_dn: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 fprintf(outfile, "\tSubject: %s\n\n", dn.data);

 ret = gnutls_x509_crl_init(&crl);
 if (ret < 0) {
  fprintf(
         stderr
               , "crl_init: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 pem.data = (void *) _gnutls_fread_file(infile, 0, &size);
 pem.size = size;

 if (!pem.data) {
  fprintf(
         stderr
               , "%s", infile ? "file" : "standard input");
  app_exit(1);
 }

 ret = gnutls_x509_crl_import(crl, &pem, incert_format);
 free(pem.data);
 if (ret < 0) {
  fprintf(
         stderr
               , "import error: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 print_crl_info(crl, outfile, cinfo);

 ret = gnutls_x509_crl_verify(crl, &issuer, 1, 0, &output);
 if (ret < 0) {
  fprintf(
         stderr
               , "verification error: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }

 fprintf(outfile, "Verification output: ");

 if (output) {
  fprintf(outfile, "Not verified. ");
  rc = 1;
 } else {
  fprintf(outfile, "Verified.");
  rc = 0;
 }

 ret =
     gnutls_certificate_verification_status_print(output,
        GNUTLS_CRT_X509,
        &pout, 0);
 if (ret < 0) {
  fprintf(
         stderr
               , "error: %s\n", gnutls_strerror(ret));
  app_exit(
          1
                      );
 }

 fprintf(outfile, " %s", pout.data);
 gnutls_free((void *) (pout.data)), pout.data=
((void *)0)
                      ;

 fprintf(outfile, "\n");

 app_exit(rc);
}

static void print_pkcs7_sig_info(gnutls_pkcs7_signature_info_st *info, common_info_st *cinfo)
{
 int ret;
 gnutls_datum_t str;

 ret = gnutls_pkcs7_print_signature_info(info, GNUTLS_CRT_PRINT_COMPACT, &str);
 if (ret < 0) {
  fprintf(
         stderr
               , "printing error: %s\n",
    gnutls_strerror(ret));
  app_exit(1);
 }

 fprintf(outfile, "%s", str.data);
 gnutls_free((void *) (str.data)), str.data=
((void *)0)
                     ;
}

void verify_pkcs7(common_info_st * cinfo, const char *purpose, unsigned display_data)
{
 gnutls_pkcs7_t pkcs7;
 int ret, ecode;
 size_t size;
 gnutls_datum_t data, detached = {
                                 ((void *)0)
                                     ,0};
 gnutls_datum_t tmp = {
                      ((void *)0)
                          ,0};
 int i;
 gnutls_pkcs7_signature_info_st info;
 gnutls_x509_trust_list_t tl = 
                              ((void *)0)
                                  ;
 gnutls_typed_vdata_st vdata[2];
 unsigned vdata_size = 0;
 gnutls_x509_crt_t signer = 
                           ((void *)0)
                               ;
 unsigned flags = 0;

 ret = gnutls_pkcs7_init(&pkcs7);
 if (ret < 0) {
  fprintf(
         stderr
               , "p7_init: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 data.data = (void *) _gnutls_fread_file(infile, 0, &size);
 data.size = size;

 if (!data.data) {
  fprintf(
         stderr
               , "%s", infile ? "file" : "standard input");
  app_exit(1);
 }

 ret = gnutls_pkcs7_import(pkcs7, &data, cinfo->incert_format);
 free(data.data);
 if (ret < 0) {
  fprintf(
         stderr
               , "import error: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }

 if (cinfo->cert != 
                   ((void *)0)
                       ) {
  signer = load_cert(1, cinfo);
 } else {
  tl = load_tl(cinfo);
  if (tl == 
           ((void *)0)
               ) {
   fprintf(
          stderr
                , "error loading trust list\n");
  }
 }

 if (cinfo->data_file)
  load_data(cinfo, &detached);

 if (purpose) {
  vdata[vdata_size].type = GNUTLS_DT_KEY_PURPOSE_OID;
  vdata[vdata_size].data = (void*)purpose;
  vdata[vdata_size].size = strlen(purpose);
  vdata_size++;
 }

 ecode = 1;
 for (i=0;;i++) {
  ret = gnutls_pkcs7_get_signature_info(pkcs7, i, &info);
  if (ret < 0)
   break;

  if (!display_data) {
   if (i==0) {
    fprintf(outfile, "eContent Type: %s\n", gnutls_pkcs7_get_embedded_data_oid(pkcs7));
    fprintf(outfile, "Signers:\n");
   }
   print_pkcs7_sig_info(&info, cinfo);
  } else if (i == 0) {
   if (!detached.data) {
    ret = gnutls_pkcs7_get_embedded_data(pkcs7, 0, &tmp);
    if (ret < 0) {
     fprintf(
            stderr
                  , "error getting embedded data: %s\n", gnutls_strerror(ret));
     app_exit(1);
    }

    fwrite(tmp.data, 1, tmp.size, outfile);
    gnutls_free((void *) (tmp.data)), tmp.data=
   ((void *)0)
                        ;
    tmp.data = 
              ((void *)0)
                  ;
   } else {
    fwrite(detached.data, 1, detached.size, outfile);
   }
  }

  gnutls_pkcs7_signature_info_deinit(&info);

  if (certtool_options.present.verify_allow_broken)
   flags |= (GNUTLS_VERIFY_ALLOW_SIGN_RSA_MD2|GNUTLS_VERIFY_ALLOW_SIGN_RSA_MD5);

  if (signer) {
   ret = gnutls_pkcs7_verify_direct(pkcs7, signer, i, detached.data!=
                                                                    ((void *)0)
                                                                        ?&detached:
                                                                                   ((void *)0)
                                                                                       , flags);

   if (ret >= 0 && purpose) {
    unsigned res = gnutls_x509_crt_check_key_purpose(signer, purpose, 0);
    if (res == 0)
     ret = -101;
   }

  } else {
   
  ((void) sizeof ((
  tl != 
  ((void *)0)) ? 1 : 0), __extension__ ({ if (
  tl != 
  ((void *)0)) ; else __assert_fail (
  "tl != NULL"
  , "certtool.c", 2756, __extension__ __PRETTY_FUNCTION__); }))
                    ;
   ret = gnutls_pkcs7_verify(pkcs7, tl, vdata, vdata_size, i, detached.data!=
                                                                            ((void *)0)
                                                                                ?&detached:
                                                                                           ((void *)0)
                                                                                               , flags);
  }
  if (ret < 0) {
   fprintf(
          stderr
                , "\tSignature status: verification failed: %s\n", gnutls_strerror(ret));
   ecode = 1;
  } else {
   fprintf(
          stderr
                , "\tSignature status: ok\n");
   ecode = 0;
  }
 }


 gnutls_pkcs7_deinit(pkcs7);
 if (signer)
  gnutls_x509_crt_deinit(signer);
 else
  gnutls_x509_trust_list_deinit(tl, 1);
 free(detached.data);
 app_exit(ecode);
}

void pkcs7_sign(common_info_st * cinfo, unsigned embed)
{
 gnutls_pkcs7_t pkcs7;
 gnutls_privkey_t key;
 int ret;
 size_t size;
 gnutls_datum_t data;
 unsigned flags = 0;
 gnutls_x509_crt_t *crts;
 size_t crt_size;
 size_t i;

 if (certtool_options.enabled.p7_time)
  flags |= GNUTLS_PKCS7_INCLUDE_TIME;

 if (certtool_options.enabled.p7_include_cert)
  flags |= GNUTLS_PKCS7_INCLUDE_CERT;

 ret = gnutls_pkcs7_init(&pkcs7);
 if (ret < 0) {
  fprintf(
         stderr
               , "p7_init: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 data.data = (void *) _gnutls_fread_file(infile, 0, &size);
 data.size = size;

 if (!data.data) {
  fprintf(
         stderr
               , "%s", infile ? "file" : "standard input");
  app_exit(1);
 }

 crts = load_cert_list(1, &crt_size, cinfo);
 key = load_private_key(1, cinfo);

 if (embed)
  flags |= GNUTLS_PKCS7_EMBED_DATA;

 ret = gnutls_pkcs7_sign(pkcs7, *crts, key, &data, 
                                                  ((void *)0)
                                                      , 
                                                        ((void *)0)
                                                            , get_dig(*crts, cinfo), flags);
 if (ret < 0) {
  fprintf(
         stderr
               , "Error signing: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 for (i=1;i<crt_size;i++) {
  ret = gnutls_pkcs7_set_crt(pkcs7, crts[i]);
  if (ret < 0) {
   fprintf(
          stderr
                , "Error adding cert: %s\n", gnutls_strerror(ret));
   exit(1);
  }
 }


 size = lbuffer_size;
 ret =
     gnutls_pkcs7_export(pkcs7, outcert_format, lbuffer, &size);
 if (ret < 0) {
  fprintf(
         stderr
               , "pkcs7_export: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 fwrite(lbuffer, 1, size, outfile);

 gnutls_privkey_deinit(key);
 for (i=0;i<crt_size;i++) {
  gnutls_x509_crt_deinit(crts[i]);
 }
 gnutls_free((void *) (crts)), crts=
((void *)0)
                 ;
 gnutls_pkcs7_deinit(pkcs7);
 app_exit(0);
}

void pkcs7_generate(common_info_st * cinfo)
{
 gnutls_pkcs7_t pkcs7;
 int ret;
 size_t crl_size = 0, crt_size = 0;
 gnutls_x509_crt_t *crts;
 gnutls_x509_crl_t *crls;
 gnutls_datum_t tmp;
 unsigned i;

 crts = load_cert_list(1, &crt_size, cinfo);
 crls = load_crl_list(0, &crl_size, cinfo);

 ret = gnutls_pkcs7_init(&pkcs7);
 if (ret < 0) {
  fprintf(
         stderr
               , "p7_init: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 for (i=0;i<crt_size;i++) {
  ret = gnutls_pkcs7_set_crt(pkcs7, crts[i]);
  if (ret < 0) {
   fprintf(
          stderr
                , "Error adding cert: %s\n", gnutls_strerror(ret));
   app_exit(1);
  }
  gnutls_x509_crt_deinit(crts[i]);
 }
 gnutls_free((void *) (crts)), crts=
((void *)0)
                 ;

 for (i=0;i<crl_size;i++) {
  ret = gnutls_pkcs7_set_crl(pkcs7, crls[i]);
  if (ret < 0) {
   fprintf(
          stderr
                , "Error adding CRL: %s\n", gnutls_strerror(ret));
   app_exit(1);
  }
  gnutls_x509_crl_deinit(crls[i]);
 }
 gnutls_free((void *) (crls)), crls=
((void *)0)
                 ;

 ret =
     gnutls_pkcs7_export2(pkcs7, outcert_format, &tmp);
 if (ret < 0) {
  fprintf(
         stderr
               , "pkcs7_export: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 fwrite(tmp.data, 1, tmp.size, outfile);
 gnutls_free((void *) (tmp.data)), tmp.data=
((void *)0)
                     ;

 gnutls_pkcs7_deinit(pkcs7);
 app_exit(0);
}


void generate_pkcs8(common_info_st * cinfo)
{
 gnutls_x509_privkey_t key;
 int result;
 size_t size;
 unsigned int flags = 0;
 const char *password;

 fprintf(
        stderr
              , "Generating a PKCS #8 key structure...\n");

 key = load_x509_private_key(1, cinfo);

 password = get_password(cinfo, &flags, 1);

 flags |= cipher_to_flags(cinfo->pkcs_cipher);

 size = lbuffer_size;
 result =
     gnutls_x509_privkey_export_pkcs8(key, outcert_format,
          password, flags, lbuffer,
          &size);

 if (result < 0) {
  fprintf(
         stderr
               , "key_export: %s\n", gnutls_strerror(result));
  app_exit(1);
 }

 fwrite(lbuffer, 1, size, outfile);

}





void generate_pkcs12(common_info_st * cinfo)
{
 gnutls_pkcs12_t pkcs12;
 gnutls_x509_crl_t *crls;
 gnutls_x509_crt_t *crts, ca_crt;
 gnutls_x509_privkey_t *keys;
 gnutls_mac_algorithm_t mac;
 int result;
 size_t size;
 gnutls_datum_t data;
 const char *pass;
 const char *name;
 unsigned int flags = 0, i;
 gnutls_datum_t key_id;
 unsigned char _key_id[64];
 int indx;
 size_t ncrts;
 size_t nkeys;
 size_t ncrls;

 fprintf(
        stderr
              , "Generating a PKCS #12 structure...\n");

 keys = load_privkey_list(0, &nkeys, cinfo);
 crts = load_cert_list(0, &ncrts, cinfo);
 ca_crt = load_ca_cert(0, cinfo);

 crls = load_crl_list(0, &ncrls, cinfo);

 if (keys == 
            ((void *)0) 
                 && crts == 
                            ((void *)0) 
                                 && ca_crt == 
                                              ((void *)0) 
                                                   && crls == 
                                                              ((void *)0)
                                                                  ) {
  fprintf(
         stderr
               , "You must specify one of\n\t--load-privkey\n\t--load-certificate\n\t--load-ca-certificate\n\t--load-crl\n");
  app_exit(1);
 }

 if (cinfo->hash != GNUTLS_DIG_UNKNOWN)
  mac = (gnutls_mac_algorithm_t)cinfo->hash;
 else
  mac = GNUTLS_MAC_SHA256;

 if (certtool_options.present.p12_name) {
  name = certtool_options.arg.p12_name;
 } else {
  name = get_pkcs12_key_name();
 }

 result = gnutls_pkcs12_init(&pkcs12);
 if (result < 0) {
  fprintf(
         stderr
               , "pkcs12_init: %s\n",
   gnutls_strerror(result));
  app_exit(1);
 }

 pass = get_password(cinfo, &flags, 1);
 flags |= cipher_to_flags(cinfo->pkcs_cipher);

 for (i = 0; i < ncrts; i++) {
  gnutls_pkcs12_bag_t bag;

  result = gnutls_pkcs12_bag_init(&bag);
  if (result < 0) {
   fprintf(
          stderr
                , "bag_init: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  
 ((void) sizeof ((
 crts != 
 ((void *)0) 
 && crts[i] != 
 ((void *)0)) ? 1 : 0), __extension__ ({ if (
 crts != 
 ((void *)0) 
 && crts[i] != 
 ((void *)0)) ; else __assert_fail (
 "crts != NULL && crts[i] != NULL"
 , "certtool.c", 3003, __extension__ __PRETTY_FUNCTION__); }))
                                        ;
  result = gnutls_pkcs12_bag_set_crt(bag, crts[i]);
  if (result < 0) {
   fprintf(
          stderr
                , "set_crt[%d]: %s\n", i,
    gnutls_strerror(result));
   app_exit(1);
  }

  indx = result;

  if (i == 0) {
   result =
       gnutls_pkcs12_bag_set_friendly_name(bag, indx,
        name);
   if (result < 0) {
    fprintf(
           stderr
                 ,
     "bag_set_friendly_name: %s\n",
     gnutls_strerror(result));
    app_exit(1);
   }
  }

  size = sizeof(_key_id);
  result =
      gnutls_x509_crt_get_key_id(crts[i], GNUTLS_KEYID_USE_SHA1, _key_id, &size);
  if (result < 0) {
   fprintf(
          stderr
                , "key_id[%d]: %s\n", i,
    gnutls_strerror(result));
   app_exit(1);
  }

  key_id.data = _key_id;
  key_id.size = size;

  result = gnutls_pkcs12_bag_set_key_id(bag, indx, &key_id);
  if (result < 0) {
   fprintf(
          stderr
                , "bag_set_key_id: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  if (!(flags & GNUTLS_PKCS_PLAIN) || cinfo->empty_password)
   result = gnutls_pkcs12_bag_encrypt(bag, pass, flags);
  if (result < 0) {
   fprintf(
          stderr
                , "bag_encrypt: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  result = gnutls_pkcs12_set_bag(pkcs12, bag);
  if (result < 0) {
   fprintf(
          stderr
                , "set_bag: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }
  gnutls_pkcs12_bag_deinit(bag);
 }


 for (i = 0; i < ncrls; i++) {
  gnutls_pkcs12_bag_t bag;

  result = gnutls_pkcs12_bag_init(&bag);
  if (result < 0) {
   fprintf(
          stderr
                , "bag_init: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  result = gnutls_pkcs12_bag_set_crl(bag, crls[i]);
  if (result < 0) {
   fprintf(
          stderr
                , "set_crl[%d]: %s\n", i,
    gnutls_strerror(result));
   app_exit(1);
  }

  result = gnutls_pkcs12_bag_encrypt(bag, pass, flags);
  if (result < 0) {
   fprintf(
          stderr
                , "bag_encrypt: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  result = gnutls_pkcs12_set_bag(pkcs12, bag);
  if (result < 0) {
   fprintf(
          stderr
                , "set_bag: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }
  gnutls_pkcs12_bag_deinit(bag);
 }


 if (ca_crt) {
  gnutls_pkcs12_bag_t bag;

  result = gnutls_pkcs12_bag_init(&bag);
  if (result < 0) {
   fprintf(
          stderr
                , "bag_init: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  result = gnutls_pkcs12_bag_set_crt(bag, ca_crt);
  if (result < 0) {
   fprintf(
          stderr
                , "set_crt[%d]: %s\n", i,
    gnutls_strerror(result));
   app_exit(1);
  }

  result = gnutls_pkcs12_bag_encrypt(bag, pass, flags);
  if (result < 0) {
   fprintf(
          stderr
                , "bag_encrypt: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  result = gnutls_pkcs12_set_bag(pkcs12, bag);
  if (result < 0) {
   fprintf(
          stderr
                , "set_bag: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }
  gnutls_pkcs12_bag_deinit(bag);
 }

 for (i = 0; i < nkeys; i++) {
  gnutls_pkcs12_bag_t kbag;

  result = gnutls_pkcs12_bag_init(&kbag);
  if (result < 0) {
   fprintf(
          stderr
                , "bag_init: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  
 ((void) sizeof ((
 keys != 
 ((void *)0) 
 && keys[i] != 
 ((void *)0)) ? 1 : 0), __extension__ ({ if (
 keys != 
 ((void *)0) 
 && keys[i] != 
 ((void *)0)) ; else __assert_fail (
 "keys != NULL && keys[i] != NULL"
 , "certtool.c", 3139, __extension__ __PRETTY_FUNCTION__); }))
                                        ;

  size = lbuffer_size;
  result =
      gnutls_x509_privkey_export_pkcs8(keys[i],
           GNUTLS_X509_FMT_DER,
           pass, flags, lbuffer,
           &size);
  if (result < 0) {
   fprintf(
          stderr
                , "key_export[%d]: %s\n", i,
    gnutls_strerror(result));
   app_exit(1);
  }

  data.data = lbuffer;
  data.size = size;
  result =
      gnutls_pkcs12_bag_set_data(kbag,
            GNUTLS_BAG_PKCS8_ENCRYPTED_KEY,
            &data);
  if (result < 0) {
   fprintf(
          stderr
                , "bag_set_data: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  indx = result;

  result =
      gnutls_pkcs12_bag_set_friendly_name(kbag, indx, name);
  if (result < 0) {
   fprintf(
          stderr
                , "bag_set_friendly_name: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  size = sizeof(_key_id);
  result =
      gnutls_x509_privkey_get_key_id(keys[i], GNUTLS_KEYID_USE_SHA1, _key_id,
         &size);
  if (result < 0) {
   fprintf(
          stderr
                , "key_id[%d]: %s\n", i,
    gnutls_strerror(result));
   app_exit(1);
  }

  key_id.data = _key_id;
  key_id.size = size;

  result = gnutls_pkcs12_bag_set_key_id(kbag, indx, &key_id);
  if (result < 0) {
   fprintf(
          stderr
                , "bag_set_key_id: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  result = gnutls_pkcs12_set_bag(pkcs12, kbag);
  if (result < 0) {
   fprintf(
          stderr
                , "set_bag: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }
  gnutls_pkcs12_bag_deinit(kbag);
 }

 result = gnutls_pkcs12_generate_mac2(pkcs12, mac, pass);
 if (result < 0) {
  fprintf(
         stderr
               , "generate_mac: %s\n",
   gnutls_strerror(result));
  app_exit(1);
 }

 size = lbuffer_size;
 result =
     gnutls_pkcs12_export(pkcs12, outcert_format, lbuffer, &size);
 if (result < 0) {
  fprintf(
         stderr
               , "pkcs12_export: %s\n",
   gnutls_strerror(result));
  app_exit(1);
 }

 fwrite(lbuffer, 1, size, outfile);
 for (i=0;i<ncrts;i++)
  gnutls_x509_crt_deinit(crts[i]);
 gnutls_free((void *) (crts)), crts=
((void *)0)
                 ;
 gnutls_x509_crt_deinit(ca_crt);
 gnutls_pkcs12_deinit(pkcs12);
}

static const char *BAGTYPE(gnutls_pkcs12_bag_type_t x)
{
 switch (x) {
 case GNUTLS_BAG_PKCS8_ENCRYPTED_KEY:
  return "PKCS #8 Encrypted key";
 case GNUTLS_BAG_EMPTY:
  return "Empty";
 case GNUTLS_BAG_PKCS8_KEY:
  return "PKCS #8 Key";
 case GNUTLS_BAG_CERTIFICATE:
  return "Certificate";
 case GNUTLS_BAG_ENCRYPTED:
  return "Encrypted";
 case GNUTLS_BAG_CRL:
  return "CRL";
 case GNUTLS_BAG_SECRET:
  return "Secret";
 default:
  return "Unknown";
 }
}

static void print_bag_data(gnutls_pkcs12_bag_t bag, int outtext)
{
 int result;
 int count, i, type;
 gnutls_datum_t cdata, id;
 const char *str, *name;
 gnutls_datum_t out;

 count = gnutls_pkcs12_bag_get_count(bag);
 if (count < 0) {
  fprintf(
         stderr
               , "get_count: %s\n", gnutls_strerror(count));
  app_exit(1);
 }

 if (outtext)
  fprintf(outfile, "\tElements: %d\n", count);

 for (i = 0; i < count; i++) {
  type = gnutls_pkcs12_bag_get_type(bag, i);
  if (type < 0) {
   fprintf(
          stderr
                , "get_type: %s\n",
    gnutls_strerror(type));
   app_exit(1);
  }

  if (outtext)
   fprintf(outfile, "\tType: %s\n", BAGTYPE(type));

  result = gnutls_pkcs12_bag_get_data(bag, i, &cdata);
  if (result < 0) {
   fprintf(
          stderr
                , "get_data: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  if (type == GNUTLS_BAG_PKCS8_ENCRYPTED_KEY &&
      outtext)
   pkcs8_info_int(&cdata, GNUTLS_X509_FMT_DER, 1, outfile, "\t");

  name = 
        ((void *)0)
            ;
  result =
      gnutls_pkcs12_bag_get_friendly_name(bag, i,
       (char **) &name);
  if (result < 0) {
   fprintf(
          stderr
                , "get_friendly_name: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  if (name && outtext)
   fprintf(outfile, "\tFriendly name: %s\n", name);

  id.data = 
           ((void *)0)
               ;
  id.size = 0;
  result = gnutls_pkcs12_bag_get_key_id(bag, i, &id);
  if (result < 0) {
   fprintf(
          stderr
                , "get_key_id: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  if (id.size > 0 && outtext)
   fprintf(outfile, "\tKey ID: %s\n",
    raw_to_string(id.data, id.size));


  switch (type) {
  case GNUTLS_BAG_PKCS8_ENCRYPTED_KEY:
   str = "ENCRYPTED PRIVATE KEY";
   break;
  case GNUTLS_BAG_PKCS8_KEY:
   str = "PRIVATE KEY";
   break;
  case GNUTLS_BAG_CERTIFICATE:
   str = "CERTIFICATE";
   break;
  case GNUTLS_BAG_CRL:
   str = "CRL";
   break;
  case GNUTLS_BAG_ENCRYPTED:
  case GNUTLS_BAG_EMPTY:
  default:
   str = 
        ((void *)0)
            ;
  }

  if (str != 
            ((void *)0)
                ) {
   result = gnutls_pem_base64_encode2(str, &cdata, &out);
   if (result < 0) {
    fprintf(
           stderr
                 , "Error in base64 encoding: %s\n", gnutls_strerror(result));
    app_exit(1);
   }
   fprintf(outfile, "%s", out.data);
   gnutls_free((void *) (out.data)), out.data=
  ((void *)0)
                       ;
  }

 }
}

static
void pkcs12_bag_enc_info(gnutls_pkcs12_bag_t bag, FILE *out)
{
 int ret;
 unsigned schema;
 unsigned cipher;
 unsigned char salt[32];
 char hex[64+1];
 unsigned salt_size = sizeof(salt);
 unsigned iter_count;
 gnutls_datum_t bin;
 size_t hex_size = sizeof(hex);
 const char *str;
 char *oid = 
            ((void *)0)
                ;

 ret = gnutls_pkcs12_bag_enc_info(bag,
  &schema, &cipher, salt, &salt_size, &iter_count, &oid);
 if (ret == -6) {
  fprintf(out, "\tSchema: unsupported (%s)\n", oid);
  gnutls_free((void *) (oid)), oid=
 ((void *)0)
                 ;
  return;
 }

 if (ret < 0) {
  fprintf(
         stderr
               , "PKCS #12 bag read error: %s\n",
   gnutls_strerror(ret));
  return;
 }
 gnutls_free((void *) (oid)), oid=
((void *)0)
                ;

 fprintf(out, "\tCipher: %s\n", gnutls_cipher_get_name(cipher));

 str = gnutls_pkcs_schema_get_name(schema);
 if (str != 
           ((void *)0)
               ) {
  fprintf(out, "\tSchema: %s (%s)\n", str, gnutls_pkcs_schema_get_oid(schema));
 }

 bin.data = salt;
 bin.size = salt_size;
 ret = gnutls_hex_encode(&bin, hex, &hex_size);
 if (ret < 0) {
  fprintf(
         stderr
               , "hex encode error: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }

 fprintf(out, "\tSalt: %s\n", hex);
 fprintf(out, "\tSalt size: %u\n", salt_size);
 fprintf(out, "\tIteration count: %u\n", iter_count);
}

void pkcs12_info(common_info_st * cinfo)
{
 gnutls_pkcs12_t pkcs12;
 gnutls_pkcs12_bag_t bag;
 gnutls_mac_algorithm_t mac_algo;
 char *mac_oid = 
                ((void *)0)
                    ;
 char hex[64+1];
 size_t hex_size = sizeof(hex);
 char salt[32];
 unsigned int salt_size;
 unsigned int mac_iter;
 int result;
 size_t size;
 gnutls_datum_t data;
 const char *pass;
 int indx, fail = 0;

 result = gnutls_pkcs12_init(&pkcs12);
 if (result < 0) {
  fprintf(
         stderr
               , "p12_init: %s\n", gnutls_strerror(result));
  app_exit(1);
 }

 data.data = (void *) _gnutls_fread_file(infile, 0, &size);
 data.size = size;

 if (!data.data) {
  fprintf(
         stderr
               , "%s", infile ? "file" : "standard input");
  app_exit(1);
 }

 result = gnutls_pkcs12_import(pkcs12, &data, incert_format, 0);
 free(data.data);
 if (result < 0) {
  fprintf(
         stderr
               , "p12_import: %s\n", gnutls_strerror(result));
  app_exit(1);
 }

 salt_size = sizeof(salt);
 result = gnutls_pkcs12_mac_info(pkcs12, &mac_algo, salt, &salt_size, &mac_iter, &mac_oid);
 if (result == -96 && cinfo->outtext) {
  fprintf(outfile, "MAC info:\n");
  if (mac_oid != 
                ((void *)0)
                    )
   fprintf(outfile, "\tMAC: unknown (%s)\n", mac_oid);
 } else if (result >= 0 && cinfo->outtext) {
  gnutls_datum_t bin;

  fprintf(outfile, "MAC info:\n");
  fprintf(outfile, "\tMAC: %s (%s)\n", gnutls_mac_get_name(mac_algo), mac_oid);

  bin.data = (void*)salt;
  bin.size = salt_size;
  result = gnutls_hex_encode(&bin, hex, &hex_size);
  if (result < 0) {
   fprintf(
          stderr
                , "hex encode error: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  fprintf(outfile, "\tSalt: %s\n", hex);
  fprintf(outfile, "\tSalt size: %u\n", salt_size);
  fprintf(outfile, "\tIteration count: %u\n\n", mac_iter);
 }
 gnutls_free((void *) (mac_oid)), mac_oid=
((void *)0)
                    ;

 pass = get_password(cinfo, 
                           ((void *)0)
                               , 0);

 result = gnutls_pkcs12_verify_mac(pkcs12, pass);
 if (result < 0) {
  fail = 1;
  fprintf(
         stderr
               , "verify_mac: %s\n", gnutls_strerror(result));
 }

 for (indx = 0;; indx++) {
  result = gnutls_pkcs12_bag_init(&bag);
  if (result < 0) {
   fprintf(
          stderr
                , "bag_init: %s\n",
    gnutls_strerror(result));
   app_exit(1);
  }

  result = gnutls_pkcs12_get_bag(pkcs12, indx, bag);
  if (result < 0) {
   gnutls_pkcs12_bag_deinit(bag);
   break;
  }

  result = gnutls_pkcs12_bag_get_count(bag);
  if (result < 0) {
   fprintf(
          stderr
                , "bag_count: %s\n",
    gnutls_strerror(result));
   gnutls_pkcs12_bag_deinit(bag);
   app_exit(1);
  }

  if (cinfo->outtext)
   fprintf(outfile, "%sBAG #%d\n", indx ? "\n" : "", indx);

  result = gnutls_pkcs12_bag_get_type(bag, 0);
  if (result < 0) {
   fprintf(
          stderr
                , "bag_init: %s\n",
    gnutls_strerror(result));
   gnutls_pkcs12_bag_deinit(bag);
   app_exit(1);
  }

  if (result == GNUTLS_BAG_ENCRYPTED) {
   if (cinfo->outtext) {
    fprintf(outfile, "\tType: %s\n", BAGTYPE(result));
    pkcs12_bag_enc_info(bag, outfile);
    fprintf(outfile, "\n\tDecrypting...\n");
   }

   result = gnutls_pkcs12_bag_decrypt(bag, pass);

   if (result < 0) {
    fail = 1;
    fprintf(
           stderr
                 , "bag_decrypt: %s\n",
     gnutls_strerror(result));
    gnutls_pkcs12_bag_deinit(bag);
    continue;
   }

   result = gnutls_pkcs12_bag_get_count(bag);
   if (result < 0) {
    fprintf(
           stderr
                 , "encrypted bag_count: %s\n",
     gnutls_strerror(result));
    gnutls_pkcs12_bag_deinit(bag);
    app_exit(1);
   }
  }

  print_bag_data(bag, cinfo->outtext);

  gnutls_pkcs12_bag_deinit(bag);
 }

 gnutls_pkcs12_deinit(pkcs12);

 if (fail) {
  fprintf(
         stderr
               ,
   "There were errors parsing the structure\n");
  app_exit(1);
 }
}

void pkcs8_info_int(gnutls_datum_t *data, unsigned format,
      unsigned ignore_err, FILE *out, const char *tab)
{
 int ret;
 unsigned schema;
 unsigned cipher;
 unsigned char salt[32];
 char hex[64+1];
 unsigned salt_size = sizeof(salt);
 unsigned iter_count;
 gnutls_datum_t bin;
 size_t hex_size = sizeof(hex);
 const char *str;
 char *oid = 
            ((void *)0)
                ;

 ret = gnutls_pkcs8_info(data, format,
  &schema, &cipher, salt, &salt_size, &iter_count, &oid);
 if (ret == -6) {
  fprintf(out, "PKCS #8 information:\n");
  fprintf(out, "\tSchema: unsupported (%s)\n", oid);
  goto cleanup;
 } else if (ret == -50) {
  fprintf(out, "PKCS #8 information:\n");
  fprintf(out, "\tSchema: unencrypted key\n");
  goto cleanup;
 }

 if (ret < 0) {
  if (ignore_err)
   return;
  fprintf(
         stderr
               , "PKCS #8 read error: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }

 fprintf(out, "%sPKCS #8 information:\n", tab);
 fprintf(out, "%s\tCipher: %s\n", tab, gnutls_cipher_get_name(cipher));

 str = gnutls_pkcs_schema_get_name(schema);
 if (str != 
           ((void *)0)
               ) {
  fprintf(out, "%s\tSchema: %s (%s)\n", tab, str, gnutls_pkcs_schema_get_oid(schema));
 }


 bin.data = salt;
 bin.size = salt_size;
 ret = gnutls_hex_encode(&bin, hex, &hex_size);
 if (ret < 0) {
  fprintf(
         stderr
               , "hex encode error: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }

 fprintf(out, "%s\tSalt: %s\n", tab, hex);
 fprintf(out, "%s\tSalt size: %u\n", tab, salt_size);
 fprintf(out, "%s\tIteration count: %u\n\n", tab, iter_count);

 cleanup:
 gnutls_free((void *) (oid)), oid=
((void *)0)
                ;
}

void pkcs8_info(void)
{
 size_t size;
 gnutls_datum_t data;

 data.data = (void *) _gnutls_fread_file(infile, 0, &size);
 data.size = size;

 if (!data.data) {
  fprintf(
         stderr
               , "%s", infile ? "file" : "standard input");
  app_exit(1);
 }

 pkcs8_info_int(&data, incert_format, 0, outfile, "");
 free(data.data);
}

void pkcs7_info(common_info_st *cinfo, unsigned display_data)
{
 gnutls_pkcs7_t pkcs7;
 int ret;
 size_t size;
 gnutls_datum_t data, str;

 ret = gnutls_pkcs7_init(&pkcs7);
 if (ret < 0) {
  fprintf(
         stderr
               , "p7_init: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 data.data = (void *) _gnutls_fread_file(infile, 0, &size);
 data.size = size;

 if (!data.data) {
  fprintf(
         stderr
               , "%s", infile ? "file" : "standard input");
  app_exit(1);
 }

 ret = gnutls_pkcs7_import(pkcs7, &data, incert_format);
 free(data.data);
 if (ret < 0) {
  fprintf(
         stderr
               , "import error: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }

 if (display_data) {
  gnutls_datum_t tmp;

  ret = gnutls_pkcs7_get_embedded_data(pkcs7, 0, &tmp);
  if (ret != -56) {
   if (ret < 0) {
    fprintf(
           stderr
                 , "error getting embedded data: %s\n", gnutls_strerror(ret));
    app_exit(1);
   }

   fwrite(tmp.data, 1, tmp.size, outfile);
   gnutls_free((void *) (tmp.data)), tmp.data=
  ((void *)0)
                       ;
  } else {
   fprintf(
          stderr
                , "no embedded data are available\n");
   app_exit(1);
  }
 } else {
  if (cinfo->outtext) {
   ret = gnutls_pkcs7_print(pkcs7, GNUTLS_CRT_PRINT_FULL, &str);
   if (ret < 0) {
    fprintf(
           stderr
                 , "printing error: %s\n",
     gnutls_strerror(ret));
    app_exit(1);
   }

   fprintf(outfile, "%s", str.data);
   gnutls_free((void *) (str.data)), str.data=
  ((void *)0)
                       ;
  }

  size = lbuffer_size;
  ret =
      gnutls_pkcs7_export(pkcs7, outcert_format,
     lbuffer, &size);
  if (ret < 0) {
   fprintf(
          stderr
                , "export error: %s\n",
    gnutls_strerror(ret));
   app_exit(1);
  }

  fwrite(lbuffer, 1, size, outfile);
 }

 gnutls_pkcs7_deinit(pkcs7);
}

void smime_to_pkcs7(void)
{
 size_t linesize = 0;
 char *lineptr = 
                ((void *)0)
                    ;
 ssize_t len;


 do {
  len = getline(&lineptr, &linesize, infile);
  if (len == -1) {
   fprintf(
          stderr
                ,
    "cannot find RFC 2822 header/body separator");
   app_exit(1);
  }
 }
 while (strcmp(lineptr, "\r\n") != 0 && strcmp(lineptr, "\n") != 0);


 do {
  len = getline(&lineptr, &linesize, infile);
  if (len == -1) {
   fprintf(
          stderr
                ,
    "message has RFC 2822 header but no body");
   app_exit(1);
  }
 }
 while (strcmp(lineptr, "\r\n") == 0 || strcmp(lineptr, "\n") == 0);

 fprintf(outfile, "%s", "-----BEGIN PKCS7-----\n");

 do {
  while (len > 0
         && (lineptr[len - 1] == '\r'
      || lineptr[len - 1] == '\n'))
   lineptr[--len] = '\0';
  if (strcmp(lineptr, "") != 0)
   fprintf(outfile, "%s\n", lineptr);
  len = getline(&lineptr, &linesize, infile);
 }
 while (len != -1);

 fprintf(outfile, "%s", "-----END PKCS7-----\n");

 free(lineptr);
}




static
gnutls_pubkey_t find_pubkey(gnutls_x509_crt_t crt, common_info_st * cinfo)
{
 gnutls_pubkey_t pubkey = 
                         ((void *)0)
                             ;
 gnutls_privkey_t privkey = 
                           ((void *)0)
                               ;
 gnutls_x509_crq_t crq = 
                        ((void *)0)
                            ;
 int ret;
 size_t size;
 gnutls_datum_t pem;

 ret = gnutls_pubkey_init(&pubkey);
 if (ret < 0) {
  fprintf(
         stderr
               , "pubkey_init: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 if (crt == 
           ((void *)0)
               ) {
  crt = load_cert(0, cinfo);
 }

 if (crq == 
           ((void *)0)
               ) {
  crq = load_request(cinfo);
 }

 if (crt != 
           ((void *)0)
               ) {
  ret = gnutls_pubkey_import_x509(pubkey, crt, 0);
  if (ret < 0) {
   fprintf(
          stderr
                , "pubkey_import_x509: %s\n",
    gnutls_strerror(ret));
   app_exit(1);
  }
  gnutls_x509_crt_deinit(crt);
 } else if (crq != 
                  ((void *)0)
                      ) {
  ret = gnutls_pubkey_import_x509_crq(pubkey, crq, 0);
  if (ret < 0) {
   fprintf(
          stderr
                , "pubkey_import_x509_crq: %s\n",
    gnutls_strerror(ret));
   app_exit(1);
  }
  gnutls_x509_crq_deinit(crq);
 } else {
  privkey = load_private_key(0, cinfo);

  if (privkey != 
                ((void *)0)
                    ) {
   ret =
       gnutls_pubkey_import_privkey(pubkey, privkey,
        0, 0);
   if (ret < 0) {
    fprintf(
           stderr
                 ,
     "pubkey_import_privkey: %s\n",
     gnutls_strerror(ret));
    app_exit(1);
   }
   gnutls_privkey_deinit(privkey);
  } else {
   gnutls_pubkey_deinit(pubkey);
   pubkey = load_pubkey(0, cinfo);

   if (pubkey == 
                ((void *)0)
                    ) {
    pem.data = (void *) _gnutls_fread_file(infile, 0, &size);
    pem.size = size;

    if (!pem.data) {
     fprintf(
            stderr
                  , "%s", infile ? "file" : "standard input");
     app_exit(1);
    }

    ret = gnutls_pubkey_init(&pubkey);
    if (ret < 0) {
     fprintf(
            stderr
                  ,
      "pubkey_init: %s\n",
      gnutls_strerror(ret));
     app_exit(1);
    }

    if (memmem(pem.data, pem.size, "BEGIN CERTIFICATE", 16) != 0 ||
        memmem(pem.data, pem.size, "BEGIN X509", 10) != 0) {
     ret = gnutls_x509_crt_init(&crt);
     if (ret < 0) {
      fprintf(
             stderr
                   ,
       "crt_init: %s\n",
       gnutls_strerror(ret));
      app_exit(1);
     }

     ret = gnutls_x509_crt_import(crt, &pem, GNUTLS_X509_FMT_PEM);
     if (ret < 0) {
      fprintf(
             stderr
                   ,
       "crt_import: %s\n",
       gnutls_strerror(ret));
      app_exit(1);
     }

     ret = gnutls_pubkey_import_x509(pubkey, crt, 0);
     if (ret < 0) {
      fprintf(
             stderr
                   , "pubkey_import_x509: %s\n",
      gnutls_strerror(ret));
      app_exit(1);
     }
     gnutls_x509_crt_deinit(crt);
    } else {
     ret = gnutls_pubkey_import(pubkey, &pem, incert_format);
     if (ret < 0) {
      fprintf(
             stderr
                   ,
       "pubkey_import: %s\n",
       gnutls_strerror(ret));
      app_exit(1);
     }
    }
    free(pem.data);
   }

  }
 }

 return pubkey;
}

void pubkey_info(gnutls_x509_crt_t crt, common_info_st * cinfo)
{
 gnutls_pubkey_t pubkey;

 pubkey = find_pubkey(crt, cinfo);
 if (pubkey == 0) {
  fprintf(
         stderr
               , "find public key error\n");
  app_exit(1);
 }

 print_pubkey_info(pubkey, outfile, full_format, outcert_format, cinfo->outtext);
 gnutls_pubkey_deinit(pubkey);
}

static
void pubkey_keyid(common_info_st * cinfo)
{
 gnutls_pubkey_t pubkey;
 uint8_t fpr[64];
 char txt[64*2+1];
 int ret;
 size_t size, fpr_size;
 gnutls_datum_t tmp;
 unsigned flags;

 pubkey = find_pubkey(
                     ((void *)0)
                         , cinfo);
 if (pubkey == 0) {
  fprintf(
         stderr
               , "find public key error\n");
  app_exit(1);
 }

 if (cinfo->hash == GNUTLS_DIG_SHA1 || cinfo->hash == GNUTLS_DIG_UNKNOWN)
  flags = GNUTLS_KEYID_USE_SHA1;
 else if (cinfo->hash == GNUTLS_DIG_SHA512)
  flags = GNUTLS_KEYID_USE_SHA512;
 else if (cinfo->hash == GNUTLS_DIG_SHA256)
  flags = GNUTLS_KEYID_USE_SHA256;
 else {
  fprintf(
         stderr
               , "Cannot calculate key ID with the provided hash (use sha1, sha256 or sha512)\n");
  app_exit(1);
 }

 fpr_size = sizeof(fpr);
 ret = gnutls_pubkey_get_key_id(pubkey, flags, fpr, &fpr_size);
 if (ret < 0) {
  fprintf(
         stderr
               ,
   "get_key_id: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }

 tmp.data = fpr;
 tmp.size = fpr_size;

 size = sizeof(txt);
 ret = gnutls_hex_encode(&tmp, txt, &size);
 if (ret < 0) {
  fprintf(
         stderr
               ,
   "hex_encode: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }

 fputs(txt, outfile);
 fputs("\n", outfile);

 gnutls_pubkey_deinit(pubkey);
 return;
}

static
void certificate_fpr(common_info_st * cinfo)
{
 gnutls_x509_crt_t crt;
 size_t size;
 int ret = 0;
 gnutls_datum_t pem, tmp;
 unsigned int crt_num;
 uint8_t fpr[64];
 char txt[64*2+1];
 size_t fpr_size;

 crt = load_cert(0, cinfo);

 if (crt == 
           ((void *)0)
               ) {
  pem.data = (void *) _gnutls_fread_file(infile, 0, &size);
  pem.size = size;

  if (!pem.data) {
   fprintf(
          stderr
                , "%s", infile ? "file" : "standard input");
   app_exit(1);
  }

  crt_num = 1;
  ret =
      gnutls_x509_crt_list_import(&crt, &crt_num, &pem, incert_format,
      GNUTLS_X509_CRT_LIST_IMPORT_FAIL_IF_EXCEED);
  if (ret == -51) {
   fprintf(
          stderr
                , "too many certificates (%d).",
    crt_num);
  } else if (ret >= 0 && crt_num == 0) {
   fprintf(
          stderr
                , "no certificates were found.\n");
  }

  free(pem.data);
 }

 if (ret < 0) {
  fprintf(
         stderr
               , "import error: %s\n", gnutls_strerror(ret));
  app_exit(1);
 }

 fpr_size = sizeof(fpr);

 if (cinfo->hash == GNUTLS_DIG_UNKNOWN)
  cinfo->hash = GNUTLS_DIG_SHA1;

 ret = gnutls_x509_crt_get_fingerprint(crt, cinfo->hash, fpr, &fpr_size);
 if (ret < 0) {
  fprintf(
         stderr
               ,
   "get_key_id: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }

 tmp.data = fpr;
 tmp.size = fpr_size;

 size = sizeof(txt);
 ret = gnutls_hex_encode(&tmp, txt, &size);
 if (ret < 0) {
  fprintf(
         stderr
               ,
   "hex_encode: %s\n",
   gnutls_strerror(ret));
  app_exit(1);
 }

 fputs(txt, outfile);
 fputs("\n", outfile);

 gnutls_x509_crt_deinit(crt);
 return;
}
