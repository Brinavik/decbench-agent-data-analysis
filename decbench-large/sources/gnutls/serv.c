
       
       
       
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







void certtool_version(void);


       
       

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

       




struct gnutls_serv_list
{
  const char **args;
  unsigned int count;
};

struct gnutls_serv_options
{

  struct
  {
    
   _Bool 
        debug;
    
   _Bool 
        sni_hostname;
    
   _Bool 
        sni_hostname_fatal;
    
   _Bool 
        alpn;
    
   _Bool 
        alpn_fatal;
    
   _Bool 
        noticket;
    
   _Bool 
        earlydata;
    
   _Bool 
        maxearlydata;
    
   _Bool 
        nocookie;
    
   _Bool 
        generate;
    
   _Bool 
        quiet;
    
   _Bool 
        nodb;
    
   _Bool 
        http;
    
   _Bool 
        echo;
    
   _Bool 
        crlf;
    
   _Bool 
        udp;
    
   _Bool 
        mtu;
    
   _Bool 
        srtp_profiles;
    
   _Bool 
        disable_client_cert;
    
   _Bool 
        require_client_cert;
    
   _Bool 
        verify_client_cert;
    
   _Bool 
        compress_cert;
    
   _Bool 
        heartbeat;
    
   _Bool 
        x509fmtder;
    
   _Bool 
        priority;
    
   _Bool 
        dhparams;
    
   _Bool 
        x509cafile;
    
   _Bool 
        x509crlfile;
    
   _Bool 
        pgpkeyfile;
    
   _Bool 
        x509keyfile;
    
   _Bool 
        x509certfile;
    
   _Bool 
        rawpkkeyfile;
    
   _Bool 
        rawpkfile;
    
   _Bool 
        srppasswd;
    
   _Bool 
        srppasswdconf;
    
   _Bool 
        pskpasswd;
    
   _Bool 
        pskhint;
    
   _Bool 
        ocsp_response;
    
   _Bool 
        ignore_ocsp_response_errors;
    
   _Bool 
        port;
    
   _Bool 
        list;
    
   _Bool 
        provider;
    
   _Bool 
        keymatexport;
    
   _Bool 
        keymatexportsize;
    
   _Bool 
        recordsize;
    
   _Bool 
        httpdata;
    
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
    const char *sni_hostname;
    const char *maxearlydata;
    const char *mtu;
    const char *srtp_profiles;
    const char *priority;
    const char *dhparams;
    const char *x509cafile;
    const char *x509crlfile;
    const char *pgpkeyfile;
    const char *srppasswd;
    const char *srppasswdconf;
    const char *pskpasswd;
    const char *pskhint;
    const char *port;
    const char *provider;
    const char *keymatexport;
    const char *keymatexportsize;
    const char *recordsize;
    const char *httpdata;
    const char *version;
  } arg;


  struct
  {
    int debug;
    int maxearlydata;
    int mtu;
    int port;
    int keymatexportsize;
    int recordsize;
  } value;


  struct
  {
    struct gnutls_serv_list alpn;
    struct gnutls_serv_list compress_cert;
    struct gnutls_serv_list x509keyfile;
    struct gnutls_serv_list x509certfile;
    struct gnutls_serv_list rawpkkeyfile;
    struct gnutls_serv_list rawpkfile;
    struct gnutls_serv_list ocsp_response;
  } list;


  struct
  {
    
   _Bool 
        debug;
    
   _Bool 
        sni_hostname;
    
   _Bool 
        sni_hostname_fatal;
    
   _Bool 
        alpn;
    
   _Bool 
        alpn_fatal;
    
   _Bool 
        noticket;
    
   _Bool 
        earlydata;
    
   _Bool 
        maxearlydata;
    
   _Bool 
        nocookie;
    
   _Bool 
        generate;
    
   _Bool 
        quiet;
    
   _Bool 
        nodb;
    
   _Bool 
        http;
    
   _Bool 
        echo;
    
   _Bool 
        crlf;
    
   _Bool 
        udp;
    
   _Bool 
        mtu;
    
   _Bool 
        srtp_profiles;
    
   _Bool 
        disable_client_cert;
    
   _Bool 
        require_client_cert;
    
   _Bool 
        verify_client_cert;
    
   _Bool 
        compress_cert;
    
   _Bool 
        heartbeat;
    
   _Bool 
        x509fmtder;
    
   _Bool 
        priority;
    
   _Bool 
        dhparams;
    
   _Bool 
        x509cafile;
    
   _Bool 
        x509crlfile;
    
   _Bool 
        pgpkeyfile;
    
   _Bool 
        x509keyfile;
    
   _Bool 
        x509certfile;
    
   _Bool 
        rawpkkeyfile;
    
   _Bool 
        rawpkfile;
    
   _Bool 
        srppasswd;
    
   _Bool 
        srppasswdconf;
    
   _Bool 
        pskpasswd;
    
   _Bool 
        pskhint;
    
   _Bool 
        ocsp_response;
    
   _Bool 
        ignore_ocsp_response_errors;
    
   _Bool 
        port;
    
   _Bool 
        list;
    
   _Bool 
        provider;
    
   _Bool 
        keymatexport;
    
   _Bool 
        keymatexportsize;
    
   _Bool 
        recordsize;
    
   _Bool 
        httpdata;
    
   _Bool 
        version;
    
   _Bool 
        help;
    
   _Bool 
        more_help;
  } enabled;
};
extern struct gnutls_serv_options gnutls_serv_options;
int process_options (int argc, char **argv);
void usage (FILE *out, int status);
void gnutls_dtls_set_timeouts(gnutls_session_t session,
         unsigned int retrans_timeout,
         unsigned int total_timeout);

unsigned int gnutls_dtls_get_mtu(gnutls_session_t session);
unsigned int gnutls_dtls_get_data_mtu(gnutls_session_t session);

void gnutls_dtls_set_mtu(gnutls_session_t session, unsigned int mtu);
int gnutls_dtls_set_data_mtu(gnutls_session_t session, unsigned int mtu);

unsigned int gnutls_dtls_get_timeout(gnutls_session_t session);
typedef struct {
 unsigned int record_seq;
 unsigned int hsk_read_seq;
 unsigned int hsk_write_seq;
} gnutls_dtls_prestate_st;

int gnutls_dtls_cookie_send(gnutls_datum_t * key,
       void *client_data,
       size_t client_data_size,
       gnutls_dtls_prestate_st * prestate,
       gnutls_transport_ptr_t ptr,
       gnutls_push_func push_func);

int gnutls_dtls_cookie_verify(gnutls_datum_t * key,
         void *client_data,
         size_t client_data_size, void *_msg,
         size_t msg_size,
         gnutls_dtls_prestate_st * prestate);

void gnutls_dtls_prestate_set(gnutls_session_t session,
         gnutls_dtls_prestate_st * prestate);

unsigned int gnutls_record_get_discarded(gnutls_session_t session);

void udp_server(const char *name, int port, int mtu);
gnutls_session_t initialize_session(int dtls);
const char *human_addr(const struct sockaddr *sa, socklen_t salen,
         char *buf, size_t buflen);
int wait_for_connection(void);
int listen_socket(const char *name, int listen_port, int socktype);
       
       
       





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
       
       


       
       
extern int _gl_cxxalias_dummy
                                                                  ;

extern int _gl_cxxalias_dummy;
       
       
       
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int rpl_fcntl (int fd, int action, ...);
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;




extern int _gl_cxxalias_dummy;






       

typedef enum {
 GNUTLS_KTLS_RECV = 1 << 0,
 GNUTLS_KTLS_SEND = 1 << 1,
 GNUTLS_KTLS_DUPLEX = GNUTLS_KTLS_RECV | GNUTLS_KTLS_SEND,
} gnutls_transport_ktls_enable_flags_t;


gnutls_transport_ktls_enable_flags_t
gnutls_transport_is_ktls_enabled(gnutls_session_t session);

void gnutls_transport_set_fastopen(gnutls_session_t session,
                                   int fd,
                                   struct sockaddr *connect_addr,
                                   socklen_t connect_addrlen,
                                   unsigned int flags);
typedef struct {
 int fd;
 gnutls_session_t session;
 int secure;
 char *hostname;
 const char *app_proto;
 char *ip;
 char *service;
 struct addrinfo *ptr;
 struct addrinfo *addr_info;
 int verbose;


 struct sockaddr_storage connect_addr;
 socklen_t connect_addrlen;

 FILE *server_trace;
 FILE *client_trace;


 gnutls_datum_t rdata;

 gnutls_datum_t edata;
} socket_st;


extern gnutls_session_t init_tls_session(const char *host);
int do_handshake(socket_st * socket);

ssize_t socket_recv(const socket_st * socket, void *buffer,
      int buffer_size);
ssize_t socket_recv_timeout(const socket_st * socket, void *buffer,
      int buffer_size, unsigned ms);
ssize_t socket_send(const socket_st * socket, const void *buffer,
      int buffer_size);
ssize_t socket_send_range(const socket_st * socket, const void *buffer,
     int buffer_size, gnutls_range_st * range);
void
socket_open2(socket_st * hd, const char *hostname, const char *service,
     const char *app_proto, int flags, const char *msg, gnutls_datum_t *rdata, gnutls_datum_t *edata,
     FILE *server_trace, FILE *client_trace);







void socket_bye(socket_st * socket, unsigned polite);

int service_to_port(const char *service, const char *proto);
const char *port_to_service(const char *sport, const char *proto);
int starttls_proto_to_port(const char *app_proto);
const char *starttls_proto_to_service(const char *app_proto);

void canonicalize_host(char *hostname, char *service, unsigned service_size);







typedef 
       _Bool 
            (*gl_listelement_equals_fn) (const void *elt1, const void *elt2);



typedef size_t (*gl_listelement_hashcode_fn) (const void *elt);



typedef void (*gl_listelement_dispose_fn) (const void *elt);

struct gl_list_impl;

typedef struct gl_list_impl * gl_list_t;

struct gl_list_node_impl;



typedef struct gl_list_node_impl * gl_list_node_t;

struct gl_list_implementation;

typedef const struct gl_list_implementation * gl_list_implementation_t;
typedef struct
{

  const struct gl_list_implementation *vtable;

  gl_list_t list;
  size_t count;

  void *p; void *q;
  size_t i; size_t j;
} gl_list_iterator_t;
typedef int (*gl_listelement_compar_fn) (const void *elt1, const void *elt2);
struct gl_list_implementation
{

  gl_list_t (*nx_create_empty) (gl_list_implementation_t implementation,
                                gl_listelement_equals_fn equals_fn,
                                gl_listelement_hashcode_fn hashcode_fn,
                                gl_listelement_dispose_fn dispose_fn,
                                
                               _Bool 
                                    allow_duplicates);
  gl_list_t (*nx_create) (gl_list_implementation_t implementation,
                          gl_listelement_equals_fn equals_fn,
                          gl_listelement_hashcode_fn hashcode_fn,
                          gl_listelement_dispose_fn dispose_fn,
                          
                         _Bool 
                              allow_duplicates,
                          size_t count, const void **contents);
  size_t (*size) (gl_list_t list);
  const void * (*node_value) (gl_list_t list, gl_list_node_t node);
  int (*node_nx_set_value) (gl_list_t list, gl_list_node_t node,
                            const void *elt);
  gl_list_node_t (*next_node) (gl_list_t list, gl_list_node_t node);
  gl_list_node_t (*previous_node) (gl_list_t list, gl_list_node_t node);
  gl_list_node_t (*first_node) (gl_list_t list);
  gl_list_node_t (*last_node) (gl_list_t list);
  const void * (*get_at) (gl_list_t list, size_t position);
  gl_list_node_t (*nx_set_at) (gl_list_t list, size_t position,
                               const void *elt);
  gl_list_node_t (*search_from_to) (gl_list_t list, size_t start_index,
                                    size_t end_index, const void *elt);
  size_t (*indexof_from_to) (gl_list_t list, size_t start_index,
                             size_t end_index, const void *elt);
  gl_list_node_t (*nx_add_first) (gl_list_t list, const void *elt);
  gl_list_node_t (*nx_add_last) (gl_list_t list, const void *elt);
  gl_list_node_t (*nx_add_before) (gl_list_t list, gl_list_node_t node,
                                   const void *elt);
  gl_list_node_t (*nx_add_after) (gl_list_t list, gl_list_node_t node,
                                  const void *elt);
  gl_list_node_t (*nx_add_at) (gl_list_t list, size_t position,
                               const void *elt);
  
 _Bool 
      (*remove_node) (gl_list_t list, gl_list_node_t node);
  
 _Bool 
      (*remove_at) (gl_list_t list, size_t position);
  
 _Bool 
      (*remove_elt) (gl_list_t list, const void *elt);
  void (*list_free) (gl_list_t list);

  gl_list_iterator_t (*iterator) (gl_list_t list);
  gl_list_iterator_t (*iterator_from_to) (gl_list_t list,
                                          size_t start_index,
                                          size_t end_index);
  
 _Bool 
      (*iterator_next) (gl_list_iterator_t *iterator,
                         const void **eltp, gl_list_node_t *nodep);
  void (*iterator_free) (gl_list_iterator_t *iterator);

  gl_list_node_t (*sortedlist_search) (gl_list_t list,
                                       gl_listelement_compar_fn compar,
                                       const void *elt);
  gl_list_node_t (*sortedlist_search_from_to) (gl_list_t list,
                                               gl_listelement_compar_fn compar,
                                               size_t start_index,
                                               size_t end_index,
                                               const void *elt);
  size_t (*sortedlist_indexof) (gl_list_t list,
                                gl_listelement_compar_fn compar,
                                const void *elt);
  size_t (*sortedlist_indexof_from_to) (gl_list_t list,
                                        gl_listelement_compar_fn compar,
                                        size_t start_index, size_t end_index,
                                        const void *elt);
  gl_list_node_t (*sortedlist_nx_add) (gl_list_t list,
                                       gl_listelement_compar_fn compar,
                                    const void *elt);
  
 _Bool 
      (*sortedlist_remove) (gl_list_t list,
                             gl_listelement_compar_fn compar,
                             const void *elt);
};

struct gl_list_impl_base
{
  const struct gl_list_implementation *vtable;
  gl_listelement_equals_fn equals_fn;
  gl_listelement_hashcode_fn hashcode_fn;
  gl_listelement_dispose_fn dispose_fn;
  
 _Bool 
      allow_duplicates;
};




inline gl_list_t
gl_list_nx_create_empty (gl_list_implementation_t implementation,
                         gl_listelement_equals_fn equals_fn,
                         gl_listelement_hashcode_fn hashcode_fn,
                         gl_listelement_dispose_fn dispose_fn,
                         
                        _Bool 
                             allow_duplicates)
{
  return implementation->nx_create_empty (implementation, equals_fn,
                                          hashcode_fn, dispose_fn,
                                          allow_duplicates);
}

inline gl_list_t
gl_list_nx_create (gl_list_implementation_t implementation,
                   gl_listelement_equals_fn equals_fn,
                   gl_listelement_hashcode_fn hashcode_fn,
                   gl_listelement_dispose_fn dispose_fn,
                   
                  _Bool 
                       allow_duplicates,
                   size_t count, const void **contents)
{
  return implementation->nx_create (implementation, equals_fn, hashcode_fn,
                                    dispose_fn, allow_duplicates, count,
                                    contents);
}

inline size_t
gl_list_size (gl_list_t list)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->size (list);
}

inline const void *
gl_list_node_value (gl_list_t list, gl_list_node_t node)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->node_value (list, node);
}

inline __attribute__ ((__warn_unused_result__)) int
gl_list_node_nx_set_value (gl_list_t list, gl_list_node_t node,
                           const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->node_nx_set_value (list, node, elt);
}

inline gl_list_node_t
gl_list_next_node (gl_list_t list, gl_list_node_t node)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->next_node (list, node);
}

inline gl_list_node_t
gl_list_previous_node (gl_list_t list, gl_list_node_t node)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->previous_node (list, node);
}

inline gl_list_node_t
gl_list_first_node (gl_list_t list)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->first_node (list);
}

inline gl_list_node_t
gl_list_last_node (gl_list_t list)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->last_node (list);
}

inline const void *
gl_list_get_at (gl_list_t list, size_t position)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->get_at (list, position);
}

inline const void *
gl_list_get_first (gl_list_t list)
{
  return gl_list_get_at (list, 0);
}

inline const void *
gl_list_get_last (gl_list_t list)
{
  return gl_list_get_at (list, gl_list_size (list) - 1);
}

inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_set_at (gl_list_t list, size_t position, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->nx_set_at (list, position, elt);
}

inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_set_first (gl_list_t list, const void *elt)
{
  return gl_list_nx_set_at (list, 0, elt);
}

inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_set_last (gl_list_t list, const void *elt)
{
  return gl_list_nx_set_at (list, gl_list_size (list) - 1, elt);
}

inline gl_list_node_t
gl_list_search (gl_list_t list, const void *elt)
{
  size_t size = ((const struct gl_list_impl_base *) list)->vtable->size (list);
  return ((const struct gl_list_impl_base *) list)->vtable
         ->search_from_to (list, 0, size, elt);
}

inline gl_list_node_t
gl_list_search_from (gl_list_t list, size_t start_index, const void *elt)
{
  size_t size = ((const struct gl_list_impl_base *) list)->vtable->size (list);
  return ((const struct gl_list_impl_base *) list)->vtable
         ->search_from_to (list, start_index, size, elt);
}

inline gl_list_node_t
gl_list_search_from_to (gl_list_t list, size_t start_index, size_t end_index,
                        const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->search_from_to (list, start_index, end_index, elt);
}

inline size_t
gl_list_indexof (gl_list_t list, const void *elt)
{
  size_t size = ((const struct gl_list_impl_base *) list)->vtable->size (list);
  return ((const struct gl_list_impl_base *) list)->vtable
         ->indexof_from_to (list, 0, size, elt);
}

inline size_t
gl_list_indexof_from (gl_list_t list, size_t start_index, const void *elt)
{
  size_t size = ((const struct gl_list_impl_base *) list)->vtable->size (list);
  return ((const struct gl_list_impl_base *) list)->vtable
         ->indexof_from_to (list, start_index, size, elt);
}

inline size_t
gl_list_indexof_from_to (gl_list_t list, size_t start_index, size_t end_index,
                         const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->indexof_from_to (list, start_index, end_index, elt);
}

inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_add_first (gl_list_t list, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->nx_add_first (list, elt);
}

inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_add_last (gl_list_t list, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->nx_add_last (list, elt);
}

inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_add_before (gl_list_t list, gl_list_node_t node, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->nx_add_before (list, node, elt);
}

inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_add_after (gl_list_t list, gl_list_node_t node, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->nx_add_after (list, node, elt);
}

inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_add_at (gl_list_t list, size_t position, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->nx_add_at (list, position, elt);
}

inline 
              _Bool

gl_list_remove_node (gl_list_t list, gl_list_node_t node)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->remove_node (list, node);
}

inline 
              _Bool

gl_list_remove_at (gl_list_t list, size_t position)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->remove_at (list, position);
}

inline 
              _Bool

gl_list_remove_first (gl_list_t list)
{
  size_t size = gl_list_size (list);
  if (size > 0)
    return gl_list_remove_at (list, 0);
  else
    return 
          0
               ;
}

inline 
              _Bool

gl_list_remove_last (gl_list_t list)
{
  size_t size = gl_list_size (list);
  if (size > 0)
    return gl_list_remove_at (list, size - 1);
  else
    return 
          0
               ;
}

inline 
              _Bool

gl_list_remove (gl_list_t list, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->remove_elt (list, elt);
}

inline void
gl_list_free (gl_list_t list)
{
  ((const struct gl_list_impl_base *) list)->vtable->list_free (list);
}

inline gl_list_iterator_t
gl_list_iterator (gl_list_t list)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->iterator (list);
}

inline gl_list_iterator_t
gl_list_iterator_from_to (gl_list_t list, size_t start_index, size_t end_index)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->iterator_from_to (list, start_index, end_index);
}

inline 
              _Bool

gl_list_iterator_next (gl_list_iterator_t *iterator,
                       const void **eltp, gl_list_node_t *nodep)
{
  return iterator->vtable->iterator_next (iterator, eltp, nodep);
}

inline void
gl_list_iterator_free (gl_list_iterator_t *iterator)
{
  iterator->vtable->iterator_free (iterator);
}

inline gl_list_node_t
gl_sortedlist_search (gl_list_t list, gl_listelement_compar_fn compar, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->sortedlist_search (list, compar, elt);
}

inline gl_list_node_t
gl_sortedlist_search_from_to (gl_list_t list, gl_listelement_compar_fn compar, size_t start_index, size_t end_index, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->sortedlist_search_from_to (list, compar, start_index, end_index,
                                      elt);
}

inline size_t
gl_sortedlist_indexof (gl_list_t list, gl_listelement_compar_fn compar, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->sortedlist_indexof (list, compar, elt);
}

inline size_t
gl_sortedlist_indexof_from_to (gl_list_t list, gl_listelement_compar_fn compar, size_t start_index, size_t end_index, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->sortedlist_indexof_from_to (list, compar, start_index, end_index,
                                       elt);
}

inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_sortedlist_nx_add (gl_list_t list, gl_listelement_compar_fn compar, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->sortedlist_nx_add (list, compar, elt);
}

inline 
              _Bool

gl_sortedlist_remove (gl_list_t list, gl_listelement_compar_fn compar, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->sortedlist_remove (list, compar, elt);
}











extern const struct gl_list_implementation gl_linked_list_implementation;



typedef ptrdiff_t idx_t;
       






           _Noreturn void xalloc_die (void);





void *xmalloc (size_t s)
      __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1)));
void *xzalloc (size_t s)
      __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1)));
void *xcalloc (size_t n, size_t s)
      __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1, 2)));
void *xrealloc (void *p, size_t s)
      __attribute__ ((__alloc_size__ (2)));
void *xreallocarray (void *p, size_t n, size_t s)
      __attribute__ ((__alloc_size__ (2, 3)));
void *x2realloc (void *p, size_t *pn);
void *xpalloc (void *pa, idx_t *nitems, idx_t nitems_incr_min,
               ptrdiff_t nitems_max, idx_t item_size);
void *xmemdup (void const *p, size_t s)
      __attribute__ ((__alloc_size__ (2)));
char *xstrdup (char const *str)
      __attribute__ ((__malloc__));
inline void *xnmalloc (size_t n, size_t s)
                    __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1, 2)));
inline void *
xnmalloc (size_t n, size_t s)
{
  return xreallocarray (
                       ((void *)0)
                           , n, s);
}





inline void *xnrealloc (void *p, size_t n, size_t s)
                    __attribute__ ((__alloc_size__ (2, 3)));
inline void *
xnrealloc (void *p, size_t n, size_t s)
{
  return xreallocarray (p, n, s);
}
inline void *
x2nrealloc (void *p, size_t *pn, size_t s)
{
  size_t n = *pn;

  if (! p)
    {
      if (! n)
        {




          enum { DEFAULT_MXFAST = 64 * sizeof (size_t) / 4 };

          n = DEFAULT_MXFAST / s;
          n += !n;
        }
    }
  else
    {

      if (__builtin_add_overflow (n, (n >> 1) + 1, &n))
        xalloc_die ();
    }

  p = xreallocarray (p, n, s);
  *pn = n;
  return p;
}




inline char *xcharalloc (size_t n)
                    __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1)));
inline char *
xcharalloc (size_t n)
{
  return ((char *) (sizeof (char) == 1 ? xmalloc (n) : xnmalloc (n, sizeof (char))));
}






inline gl_list_t
gl_list_create_empty (gl_list_implementation_t implementation,
                      gl_listelement_equals_fn equals_fn,
                      gl_listelement_hashcode_fn hashcode_fn,
                      gl_listelement_dispose_fn dispose_fn,
                      
                     _Bool 
                          allow_duplicates)
{
  gl_list_t result =
    gl_list_nx_create_empty (implementation, equals_fn, hashcode_fn, dispose_fn,
                             allow_duplicates);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

inline gl_list_t
gl_list_create (gl_list_implementation_t implementation,
                gl_listelement_equals_fn equals_fn,
                gl_listelement_hashcode_fn hashcode_fn,
                gl_listelement_dispose_fn dispose_fn,
                
               _Bool 
                    allow_duplicates,
                size_t count, const void **contents)
{
  gl_list_t result =
    gl_list_nx_create (implementation, equals_fn, hashcode_fn, dispose_fn,
                       allow_duplicates, count, contents);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

inline void
gl_list_node_set_value (gl_list_t list, gl_list_node_t node, const void *elt)
{
  int result = gl_list_node_nx_set_value (list, node, elt);
  if (result < 0)
    xalloc_die ();
}

inline gl_list_node_t
gl_list_set_at (gl_list_t list, size_t position, const void *elt)
{
  gl_list_node_t result = gl_list_nx_set_at (list, position, elt);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

inline gl_list_node_t
gl_list_set_first (gl_list_t list, const void *elt)
{
  gl_list_node_t result = gl_list_nx_set_first (list, elt);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

inline gl_list_node_t
gl_list_set_last (gl_list_t list, const void *elt)
{
  gl_list_node_t result = gl_list_nx_set_last (list, elt);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

inline gl_list_node_t
gl_list_add_first (gl_list_t list, const void *elt)
{
  gl_list_node_t result = gl_list_nx_add_first (list, elt);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

inline gl_list_node_t
gl_list_add_last (gl_list_t list, const void *elt)
{
  gl_list_node_t result = gl_list_nx_add_last (list, elt);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

inline gl_list_node_t
gl_list_add_before (gl_list_t list, gl_list_node_t node, const void *elt)
{
  gl_list_node_t result = gl_list_nx_add_before (list, node, elt);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

inline gl_list_node_t
gl_list_add_after (gl_list_t list, gl_list_node_t node, const void *elt)
{
  gl_list_node_t result = gl_list_nx_add_after (list, node, elt);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

inline gl_list_node_t
gl_list_add_at (gl_list_t list, size_t position, const void *elt)
{
  gl_list_node_t result = gl_list_nx_add_at (list, position, elt);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

inline gl_list_node_t
gl_sortedlist_add (gl_list_t list, gl_listelement_compar_fn compar,
                   const void *elt)
{
  gl_list_node_t result = gl_sortedlist_nx_add (list, compar, elt);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}






       
       
       


       







extern char *_gnutls_fread_file (FILE * stream, int flags, size_t * length);

extern char *_gnutls_read_file (const char *filename, int flags, size_t * length);
int gl_sockets_startup (int version)

  __attribute__ ((__const__))

  ;

int gl_sockets_cleanup (void)

  __attribute__ ((__const__))

  ;


       










inline size_t __attribute__ ((__pure__))
xsum (size_t size1, size_t size2)
{
  size_t sum = size1 + size2;
  return (sum >= size1 ? sum : 
                              (18446744073709551615UL)
                                      );
}


inline size_t __attribute__ ((__pure__))
xsum3 (size_t size1, size_t size2, size_t size3)
{
  return xsum (xsum (size1, size2), size3);
}


inline size_t __attribute__ ((__pure__))
xsum4 (size_t size1, size_t size2, size_t size3, size_t size4)
{
  return xsum (xsum (xsum (size1, size2), size3), size4);
}


inline size_t __attribute__ ((__pure__))
xmax (size_t size1, size_t size2)
{


  return (size1 >= size2 ? size1 : size2);
}






static int generate = 0;
static int http = 0;
static int strip_crlf = 1;
static int x509ctype;
static int debug = 0;

unsigned int verbose = 1;
static int nodb;
static int noticket;
static int earlydata;
int require_cert;
int disable_client_cert;

const char *psk_passwd = 
                        ((void *)0)
                            ;
const char *srp_passwd = 
                        ((void *)0)
                            ;
const char *srp_passwd_conf = 
                             ((void *)0)
                                 ;
const char **x509_keyfile = 
                           ((void *)0)
                               ;
const char **x509_certfile = 
                            ((void *)0)
                                ;
unsigned x509_certfile_size = 0;
unsigned x509_keyfile_size = 0;
const char *x509_cafile = 
                         ((void *)0)
                             ;
const char *dh_params_file = 
                            ((void *)0)
                                ;
const char *x509_crlfile = 
                          ((void *)0)
                              ;
const char *priorities = 
                        ((void *)0)
                            ;
const char **rawpk_keyfile = 
                            ((void *)0)
                                ;
const char **rawpk_file = 
                         ((void *)0)
                             ;
unsigned rawpk_keyfile_size = 0;
unsigned rawpk_file_size = 0;

const char **ocsp_responses = 
                             ((void *)0)
                                 ;
unsigned ocsp_responses_size = 0;

const char *sni_hostname = 
                          ((void *)0)
                              ;
int sni_hostname_fatal = 0;

const char **alpn_protos = 
                          ((void *)0)
                              ;
unsigned alpn_protos_size = 0;

gnutls_datum_t session_ticket_key;
gnutls_anti_replay_t anti_replay;
int record_max_size;
const char *http_data_file = 
                            ((void *)0)
                                ;
static void tcp_server(const char *name, int port);
gnutls_srp_server_credentials_t srp_cred = 
                                          ((void *)0)
                                              ;
gnutls_psk_server_credentials_t psk_cred = 
                                          ((void *)0)
                                              ;

gnutls_anon_server_credentials_t dh_cred = 
                                          ((void *)0)
                                              ;

gnutls_certificate_credentials_t cert_cred = 
                                            ((void *)0)
                                                ;

const int ssl_session_cache = 2048;

static void wrap_db_init(void);
static void wrap_db_deinit(void);
static int wrap_db_store(void *dbf, gnutls_datum_t key,
    gnutls_datum_t data);
static gnutls_datum_t wrap_db_fetch(void *dbf, gnutls_datum_t key);
static int wrap_db_delete(void *dbf, gnutls_datum_t key);
static int anti_replay_db_add(void *dbf, time_t exp, const gnutls_datum_t *key,
         const gnutls_datum_t *data);

static void cmd_parser(int argc, char **argv);






typedef struct {
 char *http_request;
 char *http_response;
 int request_length;
 int response_length;
 int response_written;
 int http_state;
 int listen_socket;
 int fd;
 gnutls_session_t tls_session;
 int handshake_ok;
 int close_ok;
 time_t start;
 int earlydata_eof;
} listener_item;

static const char *safe_strerror(int value)
{
 const char *ret = gnutls_strerror(value);
 if (ret == 
           ((void *)0)
               )
  ret = str_unknown;
 return ret;
}

static void listener_free(const void *elt)
{
 listener_item *j = (listener_item *)elt;

 free(j->http_request);
 free(j->http_response);
 if (j->fd >= 0) {
  if (j->close_ok)
   gnutls_bye(j->tls_session, GNUTLS_SHUT_WR);
  shutdown(j->fd, 2);
  close(j->fd);
  gnutls_deinit(j->tls_session);
 }
}






gnutls_dh_params_t dh_params = 
                              ((void *)0)
                                  ;
gnutls_rsa_params_t rsa_params = 
                                ((void *)0)
                                    ;

static int generate_dh_primes(void)
{
 int prime_bits =
     gnutls_sec_param_to_pk_bits(GNUTLS_PK_DH,
     GNUTLS_SEC_PARAM_MEDIUM);

 if (gnutls_dh_params_init(&dh_params) < 0) {
  fprintf(
         stderr
               , "Error in dh parameter initialization\n");
  exit(1);
 }






 printf
     ("Generating Diffie-Hellman parameters [%d]. Please wait...\n",
      prime_bits);
 fflush(
       stdout
             );

 if (gnutls_dh_params_generate2(dh_params, prime_bits) < 0) {
  fprintf(
         stderr
               , "Error in prime generation\n");
  exit(1);
 }

 return 0;
}

static void read_dh_params(void)
{
 char tmpdata[2048];
 int size;
 gnutls_datum_t params;
 FILE *fp;

 if (gnutls_dh_params_init(&dh_params) < 0) {
  fprintf(
         stderr
               , "Error in dh parameter initialization\n");
  exit(1);
 }



 fp = fopen(dh_params_file, "r");
 if (fp == 
          ((void *)0)
              ) {
  fprintf(
         stderr
               , "Could not open %s\n", dh_params_file);
  exit(1);
 }

 size = fread(tmpdata, 1, sizeof(tmpdata) - 1, fp);
 tmpdata[size] = 0;
 fclose(fp);

 params.data = (unsigned char *) tmpdata;
 params.size = size;

 size =
     gnutls_dh_params_import_pkcs3(dh_params, &params,
       GNUTLS_X509_FMT_PEM);

 if (size < 0) {
  fprintf(
         stderr
               , "Error parsing dh params: %s\n",
   safe_strerror(size));
  exit(1);
 }

 printf("Read Diffie-Hellman parameters.\n");
 fflush(
       stdout
             );

}

static int
get_params(gnutls_session_t session, gnutls_params_type_t type,
    gnutls_params_st * st)
{

 if (type == GNUTLS_PARAMS_DH) {
  if (dh_params == 
                  ((void *)0)
                      )
   return -1;
  st->params.dh = dh_params;
 } else
  return -1;

 st->type = type;
 st->deinit = 0;

 return 0;
}

static gl_list_t listener_list;

static int cert_verify_callback(gnutls_session_t session)
{
listener_item * j = gnutls_session_get_ptr(session);
unsigned int size;
int ret;

 if (gnutls_auth_get_type(session) == GNUTLS_CRD_CERTIFICATE) {
  if (!require_cert && gnutls_certificate_get_peers(session, &size) == 
                                                                      ((void *)0)
                                                                          )
   return 0;

  if (gnutls_serv_options.enabled.verify_client_cert) {
   if (cert_verify(session, 
                           ((void *)0)
                               , 
                                 ((void *)0)
                                     ) == 0) {
    do {
     ret = gnutls_alert_send(session, GNUTLS_AL_FATAL, GNUTLS_A_ACCESS_DENIED);
    } while(ret == -52 || ret == -28);

    j->http_state = 3;
    return -1;
   }
  } else {
   printf("- Peer's certificate was NOT verified.\n");
  }
 }
 return 0;
}




static int
post_client_hello(gnutls_session_t session)
{
 int ret;

 char *name;
 size_t len = 256;
 unsigned int type;
 int i;

 name = malloc(len);
 if (name == 
            ((void *)0)
                )
  return -25;

 for (i=0; ; ) {
  ret = gnutls_server_name_get(session, name, &len, &type, i);
  if (ret == -51) {
   char *new_name;
   new_name = realloc(name, len);
   if (new_name == 
                  ((void *)0)
                      ) {
    ret = -25;
    goto end;
   }
   name = new_name;
   continue;
  }


  if (ret == -56)
   break;
  i++;
  if (ret != 0)
   goto end;

  if (type != GNUTLS_NAME_DNS)
   continue;

  if (strlen(sni_hostname) != len)
   continue;

  if (!strncmp(name, sni_hostname, len)) {
   ret = 0;
   goto end;
  }
 };

 if (i == 0) {
  fprintf(
         stderr
               , "Warning: client did not include SNI extension, using default host\n");
  ret = 0;
  goto end;
 }

 if (sni_hostname_fatal == 1) {

  ret = -294;
  goto end;
 }

 fprintf(
        stderr
              , "Warning: client provided unrecognized host name\n");



 do {
  ret = gnutls_alert_send(session,
     GNUTLS_AL_WARNING,
     GNUTLS_A_UNRECOGNIZED_NAME);
 } while (ret == -28 || ret == -52);


end:
 free(name);
 return ret;
}


gnutls_session_t initialize_session(int dtls)
{
 gnutls_session_t session;
 int ret;
 unsigned i;
 const char *err;

 gnutls_datum_t alpn[16];

 unsigned alpn_size;
 unsigned flags = (1) | GNUTLS_POST_HANDSHAKE_AUTH | GNUTLS_ENABLE_RAWPK;

 if (dtls)
  flags |= (1<<2);

 if (earlydata)
  flags |= GNUTLS_ENABLE_EARLY_DATA;

 gnutls_init(&session, flags);



 gnutls_handshake_set_private_extensions(session, 1);

 gnutls_handshake_set_timeout(session,
         ((unsigned int)-1));

 if (nodb == 0) {
  gnutls_db_set_retrieve_function(session, wrap_db_fetch);
  gnutls_db_set_remove_function(session, wrap_db_delete);
  gnutls_db_set_store_function(session, wrap_db_store);
  gnutls_db_set_ptr(session, 
                            ((void *)0)
                                );
 }

 if (noticket == 0)
  gnutls_session_ticket_enable_server(session,
          &session_ticket_key);

 if (earlydata) {
  gnutls_anti_replay_enable(session, anti_replay);
  if (gnutls_serv_options.present.maxearlydata) {
   ret = gnutls_record_set_max_early_data_size(session, gnutls_serv_options.value.maxearlydata);
   if (ret < 0) {
    fprintf(
           stderr
                 , "Could not set max early data size: %s\n", gnutls_strerror(ret));
    exit(1);
   }
  }
 }

 if (sni_hostname != 
                    ((void *)0)
                        )
  gnutls_handshake_set_post_client_hello_function(session,
        &post_client_hello);

 if (priorities == 
                  ((void *)0)
                      ) {
  ret = gnutls_set_default_priority(session);
  if (ret < 0) {
   fprintf(
          stderr
                , "Could not set default policy: %s\n", gnutls_strerror(ret));
   exit(1);
  }
 } else {
  ret = gnutls_priority_set_direct(session, priorities, &err);
  if (ret < 0) {
   fprintf(
          stderr
                , "Syntax error at: %s\n", err);
   exit(1);
  }
 }







 alpn_size = 
            (((
            16
            )<(
            alpn_protos_size
            ))?(
            16
            ):(
            alpn_protos_size
            ))
                                                    ;
 for (i=0;i<alpn_size;i++) {
  alpn[i].data = (void*)alpn_protos[i];
  alpn[i].size = strlen(alpn_protos[i]);
 }

 ret = gnutls_alpn_set_protocols(session, alpn, alpn_size, gnutls_serv_options.present.alpn_fatal?GNUTLS_ALPN_MANDATORY:0);
 if (ret < 0) {
  fprintf(
         stderr
               , "Error setting ALPN protocols: %s\n", gnutls_strerror(ret));
  exit(1);
 }



 gnutls_credentials_set(session, GNUTLS_CRD_ANON, dh_cred);


 if (srp_cred != 
                ((void *)0)
                    )
  gnutls_credentials_set(session, GNUTLS_CRD_SRP, srp_cred);

 if (psk_cred != 
                ((void *)0)
                    )
  gnutls_credentials_set(session, GNUTLS_CRD_PSK, psk_cred);

 if (cert_cred != 
                 ((void *)0)
                     ) {
  gnutls_certificate_set_verify_function(cert_cred,
            cert_verify_callback);

  gnutls_credentials_set(session, GNUTLS_CRD_CERTIFICATE,
           cert_cred);
 }

 if (disable_client_cert)
  gnutls_certificate_server_set_request(session,
            GNUTLS_CERT_IGNORE);
 else {
  if (require_cert)
   gnutls_certificate_server_set_request(session,
             GNUTLS_CERT_REQUIRE);
  else
   gnutls_certificate_server_set_request(session,
             GNUTLS_CERT_REQUEST);
 }


 if (record_max_size > 0) {
  if (gnutls_record_set_max_recv_size(session, record_max_size) <
      0) {
   fprintf(
          stderr
                ,
    "Cannot set the maximum record receive size to %d.\n",
    record_max_size);
   exit(1);
  }
 }

 if (gnutls_serv_options.present.compress_cert) {
  ret = compress_cert_set_methods(session,
      gnutls_serv_options.list.compress_cert.args,
      gnutls_serv_options.list.compress_cert.count);
  if (ret < 0)
   exit(1);
 }

 if (gnutls_serv_options.present.heartbeat)
  gnutls_heartbeat_enable(session,
     (1));


 if (gnutls_serv_options.present.srtp_profiles) {
  ret =
      gnutls_srtp_set_profile_direct(session,
         gnutls_serv_options.arg.srtp_profiles,
         &err);
  if (ret == -50)
   fprintf(
          stderr
                , "Syntax error at: %s\n", err);
  else if (ret != 0)
   fprintf(
          stderr
                , "Error in profiles: %s\n",
    gnutls_strerror(ret));
  else fprintf(
              stderr
                    ,"DTLS profile set to %s\n",
        gnutls_serv_options.arg.srtp_profiles);

  if (ret != 0) exit(1);
 }



 return session;
}



static const char DEFAULT_DATA[] =
    "This is the default message reported by the GnuTLS implementation. "
    "For more information please visit "
    "<a href=\"https://www.gnutls.org/\">https://www.gnutls.org/</a>.";





static char *peer_print_info(gnutls_session_t session, int *ret_length,
        const char *header)
{
 const char *tmp;
 unsigned char sesid[32];
 size_t i, sesid_size;
 char *http_buffer, *desc;
 gnutls_kx_algorithm_t kx_alg;
 size_t len = 20 * 1024 + strlen(header);
 char *crtinfo = 
                ((void *)0)
                    ;
 gnutls_protocol_t version;
 size_t ncrtinfo = 0;

 if (verbose == 0) {
  http_buffer = malloc(len);
  if (http_buffer == 
                    ((void *)0)
                        )
   return 
         ((void *)0)
             ;

  strcpy(http_buffer, "HTTP/1.0 200 OK\r\nContent-type: text/html\r\n\r\n" "\n" "<HTML><BODY>\n" "<CENTER><H1>This is <a href=\"http://www.gnu.org/software/gnutls\">" "GnuTLS</a></H1></CENTER>\n\n");
  strcpy(&http_buffer[sizeof("HTTP/1.0 200 OK\r\nContent-type: text/html\r\n\r\n" "\n" "<HTML><BODY>\n" "<CENTER><H1>This is <a href=\"http://www.gnu.org/software/gnutls\">" "GnuTLS</a></H1></CENTER>\n\n") - 1], DEFAULT_DATA);
  strcpy(&http_buffer
         [sizeof("HTTP/1.0 200 OK\r\nContent-type: text/html\r\n\r\n" "\n" "<HTML><BODY>\n" "<CENTER><H1>This is <a href=\"http://www.gnu.org/software/gnutls\">" "GnuTLS</a></H1></CENTER>\n\n") + sizeof(DEFAULT_DATA) - 2],
         "</BODY></HTML>\n\n");
  *ret_length =
      sizeof(DEFAULT_DATA) + sizeof("HTTP/1.0 200 OK\r\nContent-type: text/html\r\n\r\n" "\n" "<HTML><BODY>\n" "<CENTER><H1>This is <a href=\"http://www.gnu.org/software/gnutls\">" "GnuTLS</a></H1></CENTER>\n\n") +
      sizeof("</BODY></HTML>\n\n") - 3;
  return http_buffer;
 }

 if (gnutls_certificate_type_get2(session, GNUTLS_CTYPE_CLIENT) == GNUTLS_CRT_X509) {
  const gnutls_datum_t *cert_list;
  unsigned int cert_list_size = 0;

  cert_list =
      gnutls_certificate_get_peers(session, &cert_list_size);

  for (i = 0; i < cert_list_size; i++) {
   gnutls_x509_crt_t cert = 
                           ((void *)0)
                               ;
   gnutls_datum_t info;

   if (gnutls_x509_crt_init(&cert) == 0 &&
       gnutls_x509_crt_import(cert, &cert_list[i],
         GNUTLS_X509_FMT_DER) ==
       0
       && gnutls_x509_crt_print(cert,
           GNUTLS_CRT_PRINT_FULL,
           &info) == 0) {
    const char post[] = "</PRE><P><PRE>";
    char *crtinfo_new;
    size_t ncrtinfo_new;

    ncrtinfo_new = xsum3(ncrtinfo, info.size,
           sizeof(post));
    if (((ncrtinfo_new) == 
       (18446744073709551615UL)
       )) {
     free(crtinfo);
     return 
           ((void *)0)
               ;
    }
    crtinfo_new = realloc(crtinfo, ncrtinfo_new);
    if (crtinfo_new == 
                      ((void *)0)
                          ) {
     free(crtinfo);
     return 
           ((void *)0)
               ;
    }
    crtinfo = crtinfo_new;
    memcpy(crtinfo + ncrtinfo, info.data,
           info.size);
    ncrtinfo += info.size;
    memcpy(crtinfo + ncrtinfo, post,
           strlen(post));
    ncrtinfo += strlen(post);
    crtinfo[ncrtinfo] = '\0';
    gnutls_free((void *) (info.data)), info.data=
   ((void *)0)
                         ;
   }
   gnutls_x509_crt_deinit(cert);
  }
 }

 http_buffer = malloc(len);
 if (http_buffer == 
                   ((void *)0)
                       ) {
  free(crtinfo);
  return 
        ((void *)0)
            ;
 }

 strcpy(http_buffer, "HTTP/1.0 200 OK\r\nContent-type: text/html\r\n\r\n" "\n" "<HTML><BODY>\n" "<CENTER><H1>This is <a href=\"http://www.gnu.org/software/gnutls\">" "GnuTLS</a></H1></CENTER>\n\n");

 version = gnutls_protocol_get_version(session);


 sesid_size = sizeof(sesid);
 gnutls_session_get_id(session, sesid, &sesid_size);
 snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer), "\n<p>Session ID: <i>");
 for (i = 0; i < sesid_size; i++)
  snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer), "%.2X", sesid[i]);
 snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer), "</i></p>\n");
 snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer),
   "<h5>If your browser supports session resumption, then you should see the "
   "same session ID, when you press the <b>reload</b> button.</h5>\n");




 {
  char dns[256];
  size_t dns_size = sizeof(dns);
  unsigned int type;

  if (gnutls_server_name_get
      (session, dns, &dns_size, &type, 0) == 0) {
   snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer),
     "\n<p>Server Name: %s</p>\n", dns);
  }

 }

 kx_alg = gnutls_kx_get(session);



 if (kx_alg == GNUTLS_KX_SRP) {
  snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer),
    "<p>Connected as user '%s'.</p>\n",
    gnutls_srp_server_get_username(session));
 }



 if (kx_alg == GNUTLS_KX_PSK && gnutls_psk_server_get_username(session)) {
  snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer),
    "<p>Connected as user '%s'.</p>\n",
    gnutls_psk_server_get_username(session));
 }




 strcat(http_buffer, "<P>\n");

 tmp =
     gnutls_protocol_get_name(version);
 if (tmp == 
           ((void *)0)
               )
  tmp = str_unknown;
 snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer),
   "<TABLE border=1><TR><TD>Protocol version:</TD><TD>%s</TD></TR>\n",
   tmp);

 desc = gnutls_session_get_desc(session);
 if (desc) {
  snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer),
   "<TR><TD>Description:</TD><TD>%s</TD></TR>\n",
   desc);
  gnutls_free((void *) (desc)), desc=
 ((void *)0)
                  ;
 }

 if (gnutls_auth_get_type(session) == GNUTLS_CRD_CERTIFICATE &&
     gnutls_certificate_type_get2(session, GNUTLS_CTYPE_CLIENT) != GNUTLS_CRT_X509) {
  tmp =
      gnutls_certificate_type_get_name
      (gnutls_certificate_type_get2(session, GNUTLS_CTYPE_CLIENT));
  if (tmp == 
            ((void *)0)
                )
   tmp = str_unknown;
  snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer),
    "<TR><TD>Certificate Type:</TD><TD>%s</TD></TR>\n",
    tmp);
 }

 if (version < GNUTLS_TLS1_3) {
  tmp = gnutls_kx_get_name(kx_alg);
  if (tmp == 
            ((void *)0)
                )
   tmp = str_unknown;
  snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer),
    "<TR><TD>Key Exchange:</TD><TD>%s</TD></TR>\n", tmp);


  if (kx_alg == GNUTLS_KX_ANON_DH) {
   snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer),
     "<p> Connect using anonymous DH (prime of %d bits)</p>\n",
     gnutls_dh_get_prime_bits(session));
  }



  if (kx_alg == GNUTLS_KX_DHE_RSA || kx_alg == GNUTLS_KX_DHE_DSS) {
   snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer),
     "Ephemeral DH using prime of <b>%d</b> bits.<br>\n",
     gnutls_dh_get_prime_bits(session));
  }


  tmp = gnutls_compression_get_name(gnutls_compression_get(session));
  if (tmp == 
            ((void *)0)
                )
   tmp = str_unknown;
  snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer),
    "<TR><TD>Compression</TD><TD>%s</TD></TR>\n", tmp);

  tmp = gnutls_cipher_suite_get_name(kx_alg,
         gnutls_cipher_get(session),
         gnutls_mac_get(session));
  if (tmp == 
            ((void *)0)
                )
   tmp = str_unknown;
  snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer),
    "<TR><TD>Ciphersuite</TD><TD>%s</TD></TR>\n",
    tmp);
 }

 tmp = gnutls_cipher_get_name(gnutls_cipher_get(session));
 if (tmp == 
           ((void *)0)
               )
  tmp = str_unknown;
 snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer),
   "<TR><TD>Cipher</TD><TD>%s</TD></TR>\n", tmp);

 tmp = gnutls_mac_get_name(gnutls_mac_get(session));
 if (tmp == 
           ((void *)0)
               )
  tmp = str_unknown;
 snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer),
   "<TR><TD>MAC</TD><TD>%s</TD></TR>\n", tmp);

 snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer),
   "</TABLE></P>\n");

 if (crtinfo) {
  snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer),
    "<hr><PRE>%s\n</PRE>\n", crtinfo);
  free(crtinfo);
 }

 snprintf(&http_buffer[strlen(http_buffer)], len-strlen(http_buffer),
   "<hr><P>Your HTTP header was:<PRE>%s</PRE></P>\n"
   "</BODY></HTML>\n\n", header);

 *ret_length = strlen(http_buffer);

 return http_buffer;
}

static char *peer_print_data(gnutls_session_t session, int *ret_length)
{
 gnutls_datum_t data;
 char *http_buffer;
 size_t len;
 int ret;

 ret = gnutls_load_file(http_data_file, &data);
 if (ret < 0) {
  ret = asprintf(&http_buffer,
          "HTTP/1.0 404 Not Found\r\n"
          "Content-type: text/html\r\n"
          "\r\n"
          "<HTML><HEAD><TITLE>404 Not Found</TITLE></HEAD>\n"
          "<BODY><H1>Couldn't read %s</H1></BODY></HTML>\n\n",
          http_data_file);
  if (ret < 0)
   return 
         ((void *)0)
             ;

  *ret_length = strlen(http_buffer);
  return http_buffer;
 }

 ret = asprintf(&http_buffer,
         "HTTP/1.0 200 OK\r\n"
         "Content-Type: application/octet-stream\r\n"
         "Content-Length: %u\r\n"
         "\r\n",
         data.size);
 if (ret < 0)
  return 
        ((void *)0)
            ;
 len = ret;
 http_buffer = realloc(http_buffer, len + data.size);
 memcpy(&http_buffer[len], data.data, data.size);
 gnutls_free((void *) (data.data)), data.data=
((void *)0)
                      ;
 *ret_length = len + data.size;
 return http_buffer;
}

const char *human_addr(const struct sockaddr *sa, socklen_t salen,
         char *buf, size_t buflen)
{
 const char *save_buf = buf;
 size_t l;

 if (!buf || !buflen)
  return "(error)";

 *buf = 0;

 switch (sa->sa_family) {

 case 
     10
             :
  snprintf(buf, buflen, "IPv6 ");
  break;


 case 
     2
            :
  snprintf(buf, buflen, "IPv4 ");
  break;
 }

 l = 5;
 buf += l;
 buflen -= l;

 if (getnameinfo(sa, salen, buf, buflen, 
                                        ((void *)0)
                                            , 0, 
                                                 1
                                                               ) !=
     0) {
  return "(error)";
 }

 l = strlen(buf);
 buf += l;
 buflen -= l;

 if (buflen < 8)
  return save_buf;

 strcat(buf, " port ");
 buf += 6;
 buflen -= 6;

 if (getnameinfo(sa, salen, 
                           ((void *)0)
                               , 0, buf, buflen, 
                                                 2
                                                               ) !=
     0) {
  snprintf(buf, buflen, "%s", " unknown");
 }

 return save_buf;
}

int wait_for_connection(void)
{
 fd_set rd, wr;
 int n, sock = -1;
 gl_list_iterator_t iter;
 const void *elt;

 
do { unsigned int __i; fd_set *__arr = (
&rd
); for (__i = 0; __i < sizeof (fd_set) / sizeof (__fd_mask); ++__i) ((__arr)->fds_bits)[__i] = 0; } while (0)
            ;
 
do { unsigned int __i; fd_set *__arr = (
&wr
); for (__i = 0; __i < sizeof (fd_set) / sizeof (__fd_mask); ++__i) ((__arr)->fds_bits)[__i] = 0; } while (0)
            ;
 n = 0;

 iter = gl_list_iterator(listener_list);
 while (gl_list_iterator_next(&iter, &elt, 
                                          ((void *)0)
                                              )) {
  const listener_item *j = elt;

  if (j->listen_socket) {
   
  ((void) (((
  &rd
  )->fds_bits)[((
  j->fd
  ) / (8 * (int) sizeof (__fd_mask)))] |= ((__fd_mask) (1UL << ((
  j->fd
  ) % (8 * (int) sizeof (__fd_mask)))))))
                    ;
   n = 
      (((
      n
      )>(
      j->fd
      ))?(
      n
      ):(
      j->fd
      ))
                   ;
  }
 }
 gl_list_iterator_free(&iter);


 n = select(n + 1, &rd, &wr, 
                            ((void *)0)
                                , 
                                  ((void *)0)
                                      );
 if (n == -1 && 
               (*__errno_location ()) 
                     == 
                        4
                             )
  return -1;
 if (n < 0) {
  perror("select()");
  exit(1);
 }


 iter = gl_list_iterator(listener_list);
 while (gl_list_iterator_next(&iter, &elt, 
                                          ((void *)0)
                                              )) {
  const listener_item *j = elt;


  if (
     ((((
     &rd
     )->fds_bits)[((
     j->fd
     ) / (8 * (int) sizeof (__fd_mask)))] & ((__fd_mask) (1UL << ((
     j->fd
     ) % (8 * (int) sizeof (__fd_mask)))))) != 0) 
                          && j->listen_socket) {
   sock = j->fd;
   break;
  }
 }
 gl_list_iterator_free(&iter);
 return sock;
}

int listen_socket(const char *name, int listen_port, int socktype)
{
 struct addrinfo hints, *res, *ptr;
 char portname[6];
 int s = -1;
 int yes;
 listener_item *j = 
                   ((void *)0)
                       ;

 snprintf(portname, sizeof(portname), "%d", listen_port);
 memset(&hints, 0, sizeof(hints));
 hints.ai_socktype = socktype;
 hints.ai_flags = 
                 0x0001
                           ;

 if ((s = getaddrinfo(
                     ((void *)0)
                         , portname, &hints, &res)) != 0) {
  fprintf(
         stderr
               , "getaddrinfo() failed: %s\n",
   gai_strerror(s));
  return -1;
 }

 for (ptr = res; ptr != 
                       ((void *)0)
                           ; ptr = ptr->ai_next) {
  int news;






  {
   char topbuf[512];

   fprintf(
          stderr
                , "%s listening on %s...",
    name, human_addr(ptr->ai_addr,
       ptr->ai_addrlen, topbuf,
       sizeof(topbuf)));
  }

  if ((news = socket(ptr->ai_family, ptr->ai_socktype,
    ptr->ai_protocol)) < 0) {
   perror("socket() failed");
   continue;
  }
  s = news;

  if (ptr->ai_family == 
                       10
                               ) {
   yes = 1;


   (void)setsockopt(s, 
                      IPPROTO_IPV6
                                  , 
                                    26
                                               ,
       (const void *) &yes, sizeof(yes));
  }


  if (socktype == 
                 SOCK_STREAM
                            ) {
   yes = 1;
   if (setsockopt(s, 
                    1
                              , 
                                2
                                            ,
           (const void *) &yes,
           sizeof(yes)) < 0) {
    perror("setsockopt() failed");
    close(s);
    continue;
   }
  } else {







   yes = 
        2
                      ;
   if (setsockopt(s, 
                    IPPROTO_IP
                              , 
                                10
                                               ,
           (const void *) &yes,
           sizeof(yes)) < 0)
    perror("setsockopt(IP_DF) failed");

  }

  if (bind(s, ptr->ai_addr, ptr->ai_addrlen) < 0) {
   perror("bind() failed");
   close(s);
   continue;
  }

  if (socktype == 
                 SOCK_STREAM
                            ) {
   if (listen(s, 10) < 0) {
    perror("listen() failed");
    exit(1);
   }
  }


  j = xzalloc(sizeof(*j));
  gl_list_add_last(listener_list, j);
  j->listen_socket = 1;
  j->fd = s;


  fprintf(
         stderr
               , "done\n");
 }

 fflush(
       stderr
             );

 freeaddrinfo(res);

 return s;
}



static void strip(char *data)
{
 int i;
 int len = strlen(data);

 for (i = 0; i < len; i++) {
  if (data[i] == '\r' && data[i + 1] == '\n'
      && data[i + 2] == 0) {
   data[i] = '\n';
   data[i + 1] = 0;
   break;
  }
 }
}

static unsigned
get_response(gnutls_session_t session, char *request,
      char **response, int *response_length)
{
 char *p, *h;

 if (http != 0) {
  if (strncmp(request, "GET ", 4))
   goto unimplemented;

  if (!(h = strchr(request, '\n')))
   goto unimplemented;

  *h++ = '\0';
  while (*h == '\r' || *h == '\n')
   h++;

  if (!(p = strchr(request + 4, ' ')))
   goto unimplemented;
  *p = '\0';
 }

 if (http != 0) {
  if (http_data_file == 
                       ((void *)0)
                           )
   *response = peer_print_info(session, response_length, h);
  else
   *response = peer_print_data(session, response_length);
 } else {
  int ret;
  if (strip_crlf != 0)
   strip(request);
  fprintf(
         stderr
               , "received cmd: %s\n", request);

  ret = check_command(session, request, disable_client_cert);
  if (ret > 0) {
   *response = strdup("Successfully executed command\n");
   if (*response == 
                   ((void *)0)
                       ) {
    fprintf(
           stderr
                 , "Memory error\n");
    return 0;
   }
   *response_length = strlen(*response);
   return 1;
  } else if (ret == 0) {
   *response = strdup(request);
   if (*response == 
                   ((void *)0)
                       ) {
    fprintf(
           stderr
                 , "Memory error\n");
    return 0;
   }
   *response_length = strlen(*response);
  } else {
   *response = 
              ((void *)0)
                  ;
   do {
    ret = gnutls_alert_send_appropriate(session, ret);
   } while(ret == -28 || ret == -52);
   return 0;
  }
 }

 return 1;

      unimplemented:
 *response = strdup("<!DOCTYPE HTML PUBLIC \"-//IETF//DTD HTML 2.0//EN\">\r\n<HTML><HEAD>\r\n<TITLE>501 Method Not Implemented</TITLE>\r\n</HEAD><BODY>\r\n<H1>Method Not Implemented</H1>\r\n<HR>\r\n</BODY></HTML>\r\n");
 if (*response == 
                 ((void *)0)
                     )
  return 0;
 *response_length = ((*response) ? strlen(*response) : 0);
 return 1;
}

static void terminate(int sig) __attribute__ ((__noreturn__));

static void terminate(int sig)
{
 char buf[64] = { 0 };
 char *p;


 p = stpcpy(buf, "Exiting via signal ");

 if (sig > 10)
  *p++ = '0' + sig / 10;
 *p++ = '0' + sig % 10;
 *p++ = '\n';

 write(
      2
                   , buf, p - buf);
 _exit(1);
}


static void check_alert(gnutls_session_t session, int ret)
{
 if (ret == -16
     || ret == -12) {
  int last_alert = gnutls_alert_get(session);
  if (last_alert == GNUTLS_A_NO_RENEGOTIATION &&
      ret == -16)
   printf
       ("* Received NO_RENEGOTIATION alert. Client does not support renegotiation.\n");
  else
   printf("* Received alert '%d': %s.\n", last_alert,
          gnutls_alert_get_name(last_alert));
 }
}

static void tls_log_func(int level, const char *str)
{
 fprintf(
        stderr
              , "|<%d>| %s", level, str);
}

static void tls_audit_log_func(gnutls_session_t session, const char *str)
{
 fprintf(
        stderr
              , "|<%p>| %s", session, str);
}

int main(int argc, char **argv)
{
 int ret, mtu, port;
 char name[256];
 int cert_set = 0;
 unsigned use_static_dh_params = 0;
 unsigned i;

 cmd_parser(argc, argv);


 signal(
       1
             , 
               ((__sighandler_t) 1)
                      );
 signal(
       15
              , terminate);
 if (signal(
           2
                 , terminate) == 
                                 ((__sighandler_t) 1)
                                        )
  signal(
        2
              , 
                ((__sighandler_t) 1)
                       );


 sockets_init();

 listener_list = gl_list_create_empty(&gl_linked_list_implementation,
          
         ((void *)0)
             , 
               ((void *)0)
                   , listener_free,
          
         1
             );

 if (nodb == 0)
  wrap_db_init();

 if (gnutls_serv_options.present.udp)
  strcpy(name, "UDP ");
 else
  name[0] = 0;

 if (http == 1) {
  strcat(name, "HTTP Server");
 } else {
  strcat(name, "Echo Server");
 }

 gnutls_global_set_log_function(tls_log_func);
 gnutls_global_set_audit_log_function(tls_audit_log_func);
 gnutls_global_set_log_level(debug);

 if ((ret = gnutls_global_init()) < 0) {
  fprintf(
         stderr
               , "global_init: %s\n", gnutls_strerror(ret));
  exit(1);
 }
 if (generate != 0) {
  generate_dh_primes();
 } else if (dh_params_file) {
  read_dh_params();
 } else {
  use_static_dh_params = 1;
 }

 if (gnutls_certificate_allocate_credentials(&cert_cred) < 0) {
  fprintf(
         stderr
               , "memory error\n");
  exit(1);
 }


 if (x509_cafile != 
                   ((void *)0)
                       ) {
  if ((ret = gnutls_certificate_set_x509_trust_file
       (cert_cred, x509_cafile, x509ctype)) < 0) {
   fprintf(
          stderr
                , "Error reading '%s'\n",
    x509_cafile);
   fprintf(
  stderr
  , "Error: %s\n", safe_strerror(ret));
   exit(1);
  } else {
   printf("Processed %d CA certificate(s).\n", ret);
  }
 }
 if (x509_crlfile != 
                    ((void *)0)
                        ) {
  if ((ret = gnutls_certificate_set_x509_crl_file
       (cert_cred, x509_crlfile, x509ctype)) < 0) {
   fprintf(
          stderr
                , "Error reading '%s'\n",
    x509_crlfile);
   fprintf(
  stderr
  , "Error: %s\n", safe_strerror(ret));
   exit(1);
  } else {
   printf("Processed %d CRL(s).\n", ret);
  }
 }

 if (x509_certfile_size > 0 && x509_keyfile_size > 0) {
  for (i = 0; i < x509_certfile_size; i++) {
   ret = gnutls_certificate_set_x509_key_file
       (cert_cred, x509_certfile[i], x509_keyfile[i], x509ctype);
   if (ret < 0) {
    fprintf(
           stderr
                 ,
      "Error reading '%s' or '%s'\n",
      x509_certfile[i], x509_keyfile[i]);
    fprintf(
   stderr
   , "Error: %s\n", safe_strerror(ret));
    exit(1);
   } else
    cert_set = 1;
  }
 }


 if (rawpk_file_size > 0 && rawpk_keyfile_size > 0) {
  for (i = 0; i < rawpk_keyfile_size; i++) {
   ret = gnutls_certificate_set_rawpk_key_file(cert_cred, rawpk_file[i],
                                               rawpk_keyfile[i],
                                               x509ctype,
                                               
                                              ((void *)0)
                                                  , 0, 
                                                       ((void *)0)
                                                           , 0,
                                               0, 0);
   if (ret < 0) {
    fprintf(
           stderr
                 , "Error reading '%s' or '%s'\n",
            rawpk_file[i], rawpk_keyfile[i]);
     fprintf(
    stderr
    , "Error: %s\n", safe_strerror(ret));
     exit(1);
   } else {
    cert_set = 1;
   }
  }
 }

 if (cert_set == 0) {
  fprintf(
         stderr
               ,
   "Warning: no private key and certificate pairs were set.\n");
 }
 if (gnutls_serv_options.present.ignore_ocsp_response_errors)
  gnutls_certificate_set_flags(cert_cred, GNUTLS_CERTIFICATE_SKIP_OCSP_RESPONSE_CHECK);

 for (i = 0; i < ocsp_responses_size; i++ ) {
  ret = gnutls_certificate_set_ocsp_status_request_file
      (cert_cred, ocsp_responses[i], 0);
  if (ret < 0) {
   fprintf(
          stderr
                ,
    "Cannot set OCSP status request file: %s: %s\n",
    ocsp_responses[i],
    gnutls_strerror(ret));
   exit(1);
  }
 }


 if (use_static_dh_params) {

  ret = gnutls_certificate_set_known_dh_params(cert_cred, GNUTLS_SEC_PARAM_MEDIUM);
  if (ret < 0) {
   fprintf(
          stderr
                , "Error while setting DH parameters: %s\n", gnutls_strerror(ret));
   exit(1);
  }




 } else {
  gnutls_certificate_set_params_function(cert_cred, get_params);
 }





 if (srp_passwd != 
                  ((void *)0)
                      ) {
  gnutls_srp_allocate_server_credentials(&srp_cred);

  if ((ret =
       gnutls_srp_set_server_credentials_file(srp_cred,
           srp_passwd,
           srp_passwd_conf))
      < 0) {


   fprintf(
          stderr
                ,
    "Error while setting SRP parameters\n");
   fprintf(
  stderr
  , "Error: %s\n", safe_strerror(ret));
  }
 }





 if (psk_passwd != 
                  ((void *)0)
                      ) {
  gnutls_psk_allocate_server_credentials(&psk_cred);

  if ((ret =
       gnutls_psk_set_server_credentials_file(psk_cred,
           psk_passwd)) <
      0) {


   fprintf(
          stderr
                ,
    "Error while setting PSK parameters\n");
   fprintf(
  stderr
  , "Error: %s\n", safe_strerror(ret));
  }

  if (gnutls_serv_options.present.pskhint) {
   ret =
       gnutls_psk_set_server_credentials_hint
       (psk_cred, gnutls_serv_options.arg.pskhint);
   if (ret) {
    fprintf(
           stderr
                 ,
     "Error setting PSK identity hint.\n");
    fprintf(
   stderr
   , "Error: %s\n", safe_strerror(ret));
   }
  }

  if (use_static_dh_params) {
   ret = gnutls_psk_set_server_known_dh_params(psk_cred, GNUTLS_SEC_PARAM_MEDIUM);
   if (ret < 0) {
    fprintf(
           stderr
                 , "Error while setting DH parameters: %s\n", gnutls_strerror(ret));
    exit(1);
   }
  } else {
   gnutls_psk_set_server_params_function(psk_cred,
             get_params);
  }
 }



 gnutls_anon_allocate_server_credentials(&dh_cred);

 if (use_static_dh_params) {
  ret = gnutls_anon_set_server_known_dh_params(dh_cred, GNUTLS_SEC_PARAM_MEDIUM);
  if (ret < 0) {
   fprintf(
          stderr
                , "Error while setting DH parameters: %s\n", gnutls_strerror(ret));
   exit(1);
  }
 } else {
  gnutls_anon_set_server_params_function(dh_cred, get_params);
 }


 if (noticket == 0)
  gnutls_session_ticket_key_generate(&session_ticket_key);

 if (earlydata) {
  ret = gnutls_anti_replay_init(&anti_replay);
  if (ret < 0) {
   fprintf(
          stderr
                , "Error while initializing anti-replay: %s\n", gnutls_strerror(ret));
   exit(1);
  }
  gnutls_anti_replay_set_add_function(anti_replay, anti_replay_db_add);
  gnutls_anti_replay_set_ptr(anti_replay, 
                                         ((void *)0)
                                             );
 }

 if (gnutls_serv_options.present.mtu)
  mtu = gnutls_serv_options.value.mtu;
 else
  mtu = 1300;

 if (gnutls_serv_options.present.port)
  port = gnutls_serv_options.value.port;
 else
  port = 5556;

 if (gnutls_serv_options.present.udp)
  udp_server(name, port, mtu);
 else
  tcp_server(name, port);

 return 0;
}

static void retry_handshake(listener_item *j)
{
 int r, ret;

 r = gnutls_handshake(j->tls_session);
 if (r < 0 && gnutls_error_is_fatal(r) == 0) {
  check_alert(j->tls_session, r);

 } else if (r < 0) {
  j->http_state = 3;
  check_alert(j->tls_session, r);
  fprintf(
         stderr
               , "Error in handshake: %s\n", gnutls_strerror(r));

  do {
   ret = gnutls_alert_send_appropriate(j->tls_session, r);
  } while (ret == -28 || ret == -52);
  j->close_ok = 0;
 } else if (r == 0) {
  if (gnutls_session_is_resumed(j->tls_session) != 0 && verbose != 0)
   printf("*** This is a resumed session\n");

  if (verbose != 0) {
   print_info(j->tls_session, verbose, verbose);

   if (gnutls_serv_options.present.keymatexport)
    print_key_material(j->tls_session,
         gnutls_serv_options.arg.keymatexport,
         gnutls_serv_options.present.keymatexportsize ?
         gnutls_serv_options.value.keymatexportsize :
         20);
  }

  j->close_ok = 1;
  j->handshake_ok = 1;
 }
}

static void try_rehandshake(listener_item *j)
{
 int r, ret;
 fprintf(
        stderr
              , "*** Received hello message\n");

 do {
  r = gnutls_handshake(j->tls_session);
 } while (r == -52 || r == -28);

 if (r < 0) {
  do {
   ret = gnutls_alert_send_appropriate(j->tls_session, r);
  } while (ret == -28 || ret == -52);
  fprintf(
         stderr
               , "Error in rehandshake: %s\n", gnutls_strerror(r));
  j->http_state = 3;
 } else {
  j->close_ok = 1;
  j->http_state = 1;
 }
}

static void tcp_server(const char *name, int port)
{
 int n, s;
 char topbuf[512];
 int accept_fd;
 struct sockaddr_storage client_address;
 socklen_t calen;
 struct timeval tv;

 s = listen_socket(name, port, 
                              SOCK_STREAM
                                         );
 if (s < 0)
  exit(1);

 for (;;) {
  gl_list_iterator_t iter;
  gl_list_node_t node;
  const void *elt;
  gl_list_t accepted_list = gl_list_create_empty(&gl_linked_list_implementation,
              
             ((void *)0)
                 , 
                   ((void *)0)
                       , 
                         ((void *)0)
                             ,
              
             1
                 );
  fd_set rd, wr;
  time_t now = time(0);

  int val;


  
 do { unsigned int __i; fd_set *__arr = (
 &rd
 ); for (__i = 0; __i < sizeof (fd_set) / sizeof (__fd_mask); ++__i) ((__arr)->fds_bits)[__i] = 0; } while (0)
             ;
  
 do { unsigned int __i; fd_set *__arr = (
 &wr
 ); for (__i = 0; __i < sizeof (fd_set) / sizeof (__fd_mask); ++__i) ((__arr)->fds_bits)[__i] = 0; } while (0)
             ;
  n = 0;


  iter = gl_list_iterator(listener_list);
  while (gl_list_iterator_next(&iter, &elt, &node)) {
   listener_item *j = (listener_item *)elt;


   val = 
        rpl_fcntl
             (j->fd, 
                     3
                            , 0);
   if ((val == -1)
       || (
          rpl_fcntl
               (j->fd, 
                       4
                              , val | 
                                      04000
                                                ) <
    0)) {
    perror("fcntl()");
    exit(1);
   }

   if (j->start != 0 && now - j->start > 30) {
    if (verbose != 0) {
     fprintf(
            stderr
                  , "Scheduling inactive connection for close\n");
    }
    j->http_state = 3;
   }

   if (j->listen_socket) {
    
   ((void) (((
   &rd
   )->fds_bits)[((
   j->fd
   ) / (8 * (int) sizeof (__fd_mask)))] |= ((__fd_mask) (1UL << ((
   j->fd
   ) % (8 * (int) sizeof (__fd_mask)))))))
                     ;
    n = 
       (((
       n
       )>(
       j->fd
       ))?(
       n
       ):(
       j->fd
       ))
                    ;
   }
   if (j->http_state == 1) {
    
   ((void) (((
   &rd
   )->fds_bits)[((
   j->fd
   ) / (8 * (int) sizeof (__fd_mask)))] |= ((__fd_mask) (1UL << ((
   j->fd
   ) % (8 * (int) sizeof (__fd_mask)))))))
                     ;
    n = 
       (((
       n
       )>(
       j->fd
       ))?(
       n
       ):(
       j->fd
       ))
                    ;
   }
   if (j->http_state == 2) {
    
   ((void) (((
   &wr
   )->fds_bits)[((
   j->fd
   ) / (8 * (int) sizeof (__fd_mask)))] |= ((__fd_mask) (1UL << ((
   j->fd
   ) % (8 * (int) sizeof (__fd_mask)))))))
                     ;
    n = 
       (((
       n
       )>(
       j->fd
       ))?(
       n
       ):(
       j->fd
       ))
                    ;
   }
   gl_list_node_set_value(listener_list, node, j);
  }
  gl_list_iterator_free(&iter);


  tv.tv_sec = 10;
  tv.tv_usec = 0;
  n = select(n + 1, &rd, &wr, 
                             ((void *)0)
                                 , &tv);
  if (n == -1 && 
                (*__errno_location ()) 
                      == 
                         4
                              )
   continue;
  if (n < 0) {
   perror("select()");
   exit(1);
  }


  iter = gl_list_iterator(listener_list);
  while (gl_list_iterator_next(&iter, &elt, &node)) {
   listener_item *j = (listener_item *)elt;


   if (
      ((((
      &rd
      )->fds_bits)[((
      j->fd
      ) / (8 * (int) sizeof (__fd_mask)))] & ((__fd_mask) (1UL << ((
      j->fd
      ) % (8 * (int) sizeof (__fd_mask)))))) != 0) 
                           && j->listen_socket) {
    calen = sizeof(client_address);
    memset(&client_address, 0, calen);
    accept_fd =
        accept(j->fd,
        (struct sockaddr *)
        &client_address, &calen);

    if (accept_fd < 0) {
     perror("accept()");
    } else {
     char timebuf[64];
     time_t tt = time(0);
     char *ctt;
     listener_item *jj;


     jj = xzalloc(sizeof(*jj));
     gl_list_add_last(accepted_list, jj);
     jj->http_request =
         (char *) strdup("");
     jj->http_state = 1;
     jj->fd = accept_fd;
     jj->start = tt;

     jj->tls_session = initialize_session(0);
     gnutls_session_set_ptr(jj->tls_session, jj);
     gnutls_transport_set_int2(jj->tls_session, accept_fd, accept_fd)
                                     ;
     ;
     jj->handshake_ok = 0;
     jj->close_ok = 0;

     if (verbose != 0) {
      ctt = simple_ctime(&tt, timebuf);
      ctt[strlen(ctt) - 1] = 0;

      printf
          ("\n* Accepted connection from %s on %s\n",
           human_addr((struct
         sockaddr
         *)
        &client_address,
        calen,
        topbuf,
        sizeof
        (topbuf)),
           ctt);
     }
    }
   }

   if (
      ((((
      &rd
      )->fds_bits)[((
      j->fd
      ) / (8 * (int) sizeof (__fd_mask)))] & ((__fd_mask) (1UL << ((
      j->fd
      ) % (8 * (int) sizeof (__fd_mask)))))) != 0) 
                           && !j->listen_socket) {

    char buf[16*1024];
    int r;

    if (j->handshake_ok == 0) {
     retry_handshake(j);
    }

    if (j->handshake_ok == 1) {
     int earlydata_read = 0;
     if (earlydata && !j->earlydata_eof) {
      r = gnutls_record_recv_early_data(j->
            tls_session,
            buf,
            
           (((
           sizeof(buf)
           )<(
           (2147483647)
           ))?(
           sizeof(buf)
           ):(
           (2147483647)
           ))
                                
                               );
      if (r == -56) {
       j->earlydata_eof = 1;
      }
      if (r == 0) {
       earlydata_read = 1;
      }
     }
     if (!earlydata_read) {
      r = gnutls_record_recv(j->
               tls_session,
               buf,
               
              (((
              sizeof(buf)
              )<(
              (2147483647)
              ))?(
              sizeof(buf)
              ):(
              (2147483647)
              ))
                            
                           );
     }
     if (r == -52 || r == -28) {

     } else if (r <= 0) {
      if (r == -293) {
       gnutls_heartbeat_pong(j->tls_session, 0);
      } else if (r == -37) {
       try_rehandshake(j);
      } else {
       j->http_state = 3;
       if (r < 0) {
        int ret;
        check_alert(j->tls_session, r);
        fprintf(
               stderr
                     ,
             "Error while receiving data\n");
        do {
         ret = gnutls_alert_send_appropriate(j->tls_session, r);
        } while (ret == -28 || ret == -52);
        fprintf(
       stderr
       , "Error: %s\n", safe_strerror(r));
        j->close_ok = 0;
       }
      }
     } else {
      j->http_request =
          realloc(j->
           http_request,
           j->
           request_length
           + r + 1);
      if (j->http_request !=
          
         ((void *)0)
             ) {
       memcpy(j->
              http_request
              +
              j->
              request_length,
              buf, r);
       j->request_length
           += r;
       j->http_request[j->
         request_length]
           = '\0';
      } else {
       j->http_state =
           3;
      }
     }


     j->http_response = 
                       ((void *)0)
                           ;
     if (j->http_state == 1 && j->http_request != 
                                                                  ((void *)0)
                                                                      ) {
      if ((http == 0
           && strchr(j->
              http_request,
              '\n'))
          || strstr(j->
             http_request,
             "\r\n\r\n")
          || strstr(j->
             http_request,
             "\n\n")) {
       if (get_response(j->
                 tls_session,
                 j->
                 http_request,
                 &j->
                 http_response,
                 &j->
                 response_length)) {
        j->http_state =
            2;
        j->response_written
            = 0;
       } else {
        j->http_state = 3;
       }
      }
     }
    }
   }

   if (
      ((((
      &wr
      )->fds_bits)[((
      j->fd
      ) / (8 * (int) sizeof (__fd_mask)))] & ((__fd_mask) (1UL << ((
      j->fd
      ) % (8 * (int) sizeof (__fd_mask)))))) != 0)
                          ) {

    int r;

    if (j->handshake_ok == 0) {
     retry_handshake(j);
    }

    if (j->handshake_ok == 1 && j->http_response == 
                                                   ((void *)0)
                                                       ) {
     j->http_state = 3;
    } else if (j->handshake_ok == 1 && j->http_response != 
                                                          ((void *)0)
                                                              ) {
     r = gnutls_record_send(j->tls_session,
              j->http_response
              +
              j->response_written,
              
             (((
             j->response_length - j->response_written
             )<(
             (2147483647)
             ))?(
             j->response_length - j->response_written
             ):(
             (2147483647)
             ))


                           
                          );
     if (r == -52 || r == -28) {

     } else if (r <= 0) {
      j->http_state = 3;
      if (r < 0) {
       fprintf(
              stderr
                    ,
        "Error while sending data\n");
       fprintf(
      stderr
      , "Error: %s\n", safe_strerror(r));
      }
      check_alert(j->tls_session,
           r);
     } else {
      j->response_written += r;

      if (j->response_written ==
          j->response_length) {
       if (http != 0)
        j->http_state = 3;
       else {
        j->http_state = 1;
        free(j->
             http_response);
        j->http_response = 
                          ((void *)0)
                              ;
        j->response_length = 0;
        j->request_length = 0;
        j->http_request[0] = 0;
       }
      }
     }
    } else {
     j->request_length = 0;
     j->http_request[0] = 0;
     j->http_state = 1;
    }
   }
   gl_list_node_set_value(listener_list, node, j);
  }
  gl_list_iterator_free(&iter);


  iter = gl_list_iterator(listener_list);
  while (gl_list_iterator_next(&iter, &elt, &node)) {
   const listener_item *j = elt;

   if (j->http_state == 3) {
    gl_list_remove_node(listener_list, node);
   }
  }
  gl_list_iterator_free(&iter);

  iter = gl_list_iterator(accepted_list);
  while (gl_list_iterator_next(&iter, &elt, &node)) {
   gl_list_add_last(listener_list, elt);
  }
  gl_list_iterator_free(&iter);
  gl_list_free(accepted_list);
 }


 gnutls_certificate_free_credentials(cert_cred);


 if (srp_cred)
  gnutls_srp_free_server_credentials(srp_cred);



 if (psk_cred)
  gnutls_psk_free_server_credentials(psk_cred);



 gnutls_anon_free_server_credentials(dh_cred);


 if (noticket == 0)
  gnutls_free((void *) (session_ticket_key.data)), session_ticket_key.data=
 ((void *)0)
                                     ;

 if (earlydata)
  gnutls_anti_replay_deinit(anti_replay);

 if (nodb == 0)
  wrap_db_deinit();
 gnutls_global_deinit();

}

static void cmd_parser(int argc, char **argv)
{
 process_options(argc,argv);

 disable_client_cert = gnutls_serv_options.present.disable_client_cert;
 require_cert = gnutls_serv_options.enabled.require_client_cert;
 if (gnutls_serv_options.present.debug)
  debug = gnutls_serv_options.value.debug;

 if (gnutls_serv_options.present.quiet)
  verbose = 0;

 if (gnutls_serv_options.present.priority)
  priorities = gnutls_serv_options.arg.priority;

 if (gnutls_serv_options.present.list) {
  print_list(priorities, verbose);
  exit(0);
 }

 nodb = gnutls_serv_options.present.nodb;
 noticket = gnutls_serv_options.present.noticket;
 earlydata = gnutls_serv_options.present.earlydata;

 if (gnutls_serv_options.present.echo) {
  http = 0;
  if (gnutls_serv_options.present.crlf)
   strip_crlf = 0;
 } else
  http = 1;

 record_max_size = gnutls_serv_options.value.recordsize;

 if (gnutls_serv_options.present.x509fmtder)
  x509ctype = GNUTLS_X509_FMT_DER;
 else
  x509ctype = GNUTLS_X509_FMT_PEM;

 generate = gnutls_serv_options.present.generate;

 if (gnutls_serv_options.present.dhparams)
  dh_params_file = gnutls_serv_options.arg.dhparams;

 if (gnutls_serv_options.present.alpn) {
  alpn_protos = gnutls_serv_options.list.alpn.args;
  alpn_protos_size = gnutls_serv_options.list.alpn.count;
 }

 if (gnutls_serv_options.present.x509keyfile) {
  x509_keyfile = gnutls_serv_options.list.x509keyfile.args;
  x509_keyfile_size = gnutls_serv_options.list.x509keyfile.count;
 }

 if (gnutls_serv_options.present.x509certfile) {
  x509_certfile = gnutls_serv_options.list.x509certfile.args;
  x509_certfile_size = gnutls_serv_options.list.x509certfile.count;
 }

 if (x509_certfile_size != x509_keyfile_size) {
  fprintf(
         stderr
               , "The certificate number provided (%u) doesn't match the keys (%u)\n",
   x509_certfile_size, x509_keyfile_size);
   exit(1);
 }

 if (gnutls_serv_options.present.x509cafile)
  x509_cafile = gnutls_serv_options.arg.x509cafile;
 if (gnutls_serv_options.present.x509crlfile)
  x509_crlfile = gnutls_serv_options.arg.x509crlfile;

 if (gnutls_serv_options.present.rawpkkeyfile) {
  rawpk_keyfile = gnutls_serv_options.list.rawpkkeyfile.args;
  rawpk_keyfile_size = gnutls_serv_options.list.rawpkkeyfile.count;
 }

 if (gnutls_serv_options.present.rawpkfile) {
  rawpk_file = gnutls_serv_options.list.rawpkfile.args;
  rawpk_file_size = gnutls_serv_options.list.rawpkfile.count;
 }

 if (rawpk_file_size != rawpk_keyfile_size) {
  fprintf(
         stderr
               , "The number of raw public-keys provided (%u) doesn't match the number of corresponding private keys (%u)\n",
   rawpk_file_size, rawpk_keyfile_size);
   exit(1);
 }

 if (gnutls_serv_options.present.srppasswd)
  srp_passwd = gnutls_serv_options.arg.srppasswd;
 if (gnutls_serv_options.present.srppasswdconf)
  srp_passwd_conf = gnutls_serv_options.arg.srppasswdconf;

 if (gnutls_serv_options.present.pskpasswd)
  psk_passwd = gnutls_serv_options.arg.pskpasswd;

 if (gnutls_serv_options.present.ocsp_response) {
  ocsp_responses = gnutls_serv_options.list.ocsp_response.args;
  ocsp_responses_size = gnutls_serv_options.list.ocsp_response.count;
 }

 if (gnutls_serv_options.present.sni_hostname)
  sni_hostname = gnutls_serv_options.arg.sni_hostname;

 if (gnutls_serv_options.present.sni_hostname_fatal)
  sni_hostname_fatal = 1;

 if (gnutls_serv_options.present.httpdata)
  http_data_file = gnutls_serv_options.arg.httpdata;

}






typedef struct {
 unsigned char session_id[128];
 unsigned int session_id_size;

 gnutls_datum_t session_data;
} CACHE;

static CACHE *cache_db;
static int cache_db_ptr;
static int cache_db_alloc;

static void wrap_db_init(void)
{
}

static void wrap_db_deinit(void)
{
 int i;

 for (i = 0; i < cache_db_ptr; i++)
  free(cache_db[i].session_data.data);
 free(cache_db);
}

static int
wrap_db_store(void *dbf, gnutls_datum_t key, gnutls_datum_t data)
{
 int i;
 time_t now = time(0);

 if (key.size > 128)
  return -30;
 if (data.size > (16*1024))
  return -30;

 if (cache_db_ptr < cache_db_alloc)
  i = cache_db_ptr++;
 else {

  for (i = 0; i < cache_db_ptr; i++)
   if (cache_db[i].session_id_size == 0 ||
       !(now <
         gnutls_db_check_entry_expire_time(&cache_db[i].
        session_data)))
    break;

  if (i == cache_db_ptr) {

   if (cache_db_ptr == ssl_session_cache) {
    fprintf(
           stderr
                 ,
     "Error: too many sessions\n");
    return -30;
   }
   cache_db_alloc = cache_db_alloc * 2 + 1;
   cache_db = realloc(cache_db,
        cache_db_alloc * sizeof(CACHE));
   if (!cache_db)
    return -25;
   memset(cache_db + cache_db_ptr, 0,
          (cache_db_alloc - cache_db_ptr) * sizeof(CACHE));
   cache_db_ptr++;
  }
 }

 memcpy(cache_db[i].session_id, key.data, key.size);
 cache_db[i].session_id_size = key.size;


 if (cache_db[i].session_data.size < data.size) {
  cache_db[i].session_data.data =
   realloc(cache_db[i].session_data.data,
    data.size);
  if (!cache_db[i].session_data.data)
   return -25;
 }
 memcpy(cache_db[i].session_data.data, data.data, data.size);
 cache_db[i].session_data.size = data.size;

 return 0;
}

static gnutls_datum_t wrap_db_fetch(void *dbf, gnutls_datum_t key)
{
 gnutls_datum_t res = { 
                       ((void *)0)
                           , 0 };
 time_t now = time(0);
 int i;

 for (i = 0; i < cache_db_ptr; i++) {
  if (key.size == cache_db[i].session_id_size &&
      memcmp(key.data, cache_db[i].session_id,
      key.size) == 0 &&
      now < gnutls_db_check_entry_expire_time(&cache_db[i].
           session_data)) {
   res.size = cache_db[i].session_data.size;

   res.data = malloc(res.size);
   if (res.data == 
                  ((void *)0)
                      )
    return res;

   memcpy(res.data, cache_db[i].session_data.data,
          res.size);

   return res;
  }
 }
 return res;
}

static int wrap_db_delete(void *dbf, gnutls_datum_t key)
{
 int i;

 for (i = 0; i < cache_db_ptr; i++) {
  if (key.size == cache_db[i].session_id_size &&
      memcmp(key.data, cache_db[i].session_id,
      key.size) == 0) {

   cache_db[i].session_id_size = 0;
   free(cache_db[i].session_data.data);
   cache_db[i].session_data.data = 
                                  ((void *)0)
                                      ;
   cache_db[i].session_data.size = 0;

   return 0;
  }
 }

 return -30;
}

static int
anti_replay_db_add(void *dbf, time_t exp, const gnutls_datum_t *key, const gnutls_datum_t *data)
{
 time_t now = time(0);
 int i;

 for (i = 0; i < cache_db_ptr; i++) {
  if (key->size == cache_db[i].session_id_size &&
      memcmp(key->data, cache_db[i].session_id,
      key->size) == 0 &&
      now < gnutls_db_check_entry_expire_time(&cache_db[i].
           session_data))
   return -428;
 }

 return wrap_db_store(dbf, *key, *data);
}
