// Function: pkcs11_fetch_rsa_pubkey @ 0xb1c0
#include <stdlib.h>

/* --- minimal PKCS#11 declarations --- */
typedef unsigned long CK_ULONG;
typedef CK_ULONG CK_RV;
typedef CK_ULONG CK_ATTRIBUTE_TYPE;
typedef CK_ULONG CK_SESSION_HANDLE;
typedef CK_ULONG CK_OBJECT_HANDLE;
typedef void *CK_VOID_PTR;

#define CKR_OK              0UL
#define CKA_ID              0x102UL
#define CKA_MODULUS         0x120UL
#define CKA_PUBLIC_EXPONENT 0x122UL

typedef struct ck_attribute {
	CK_ATTRIBUTE_TYPE type;
	CK_VOID_PTR       pValue;
	CK_ULONG          ulValueLen;
} CK_ATTRIBUTE;

typedef struct ck_function_list {
	/* only the member used here matters for reconstruction */
	unsigned char pad_before_get_attribute_value[0xc8];
	CK_RV (*C_GetAttributeValue)(CK_SESSION_HANDLE, CK_OBJECT_HANDLE,
	    CK_ATTRIBUTE *, CK_ULONG);
} CK_FUNCTION_LIST;

/* --- OpenSSL RSA (opaque) --- */
typedef struct rsa_st RSA;
typedef struct bignum_st BIGNUM;
RSA *RSA_new(void);
void RSA_free(RSA *);
BIGNUM *BN_bin2bn(const unsigned char *, int, BIGNUM *);
int RSA_set0_key(RSA *, BIGNUM *, BIGNUM *, BIGNUM *);

/* --- OpenSSH provider / key types --- */
struct pkcs11_slotinfo {
	unsigned char     pad[0xd0];
	CK_SESSION_HANDLE session;
};

struct pkcs11_provider {
	unsigned char           pad0[0x10];
	CK_FUNCTION_LIST       *function_list;   /* offset 0x10 */
	unsigned char           pad1[0x68];
	struct pkcs11_slotinfo *slotinfo;        /* offset 0x80 */
};

#define KEY_RSA          0
#define KEY_UNSPEC       14
#define SSHKEY_FLAG_EXT  0x1

struct sshkey {
	int   type;    /* offset 0 */
	int   flags;   /* offset 4 */
	RSA  *rsa;     /* offset 8 */
};

extern void error(const char *, ...);
extern void fatal_f(const char *, ...);
void *xcalloc(size_t, size_t);
struct sshkey *sshkey_new(int);
int pkcs11_rsa_wrap(struct pkcs11_provider *, CK_ULONG, CK_ATTRIBUTE *, RSA *);

/* extract public RSA key material from a PKCS#11 object */
struct sshkey *
pkcs11_fetch_rsa_pubkey(struct pkcs11_provider *p, CK_ULONG slotidx, CK_OBJECT_HANDLE *obj)
{
	CK_ATTRIBUTE       key_attr[3];
	CK_SESSION_HANDLE  session;
	CK_FUNCTION_LIST  *f;
	CK_RV              rv;
	RSA               *rsa = NULL;
	BIGNUM            *rsa_n, *rsa_e;
	struct sshkey     *key = NULL;
	int                i;

	memset(key_attr, 0, sizeof(key_attr));
	key_attr[0].type = CKA_ID;
	key_attr[1].type = CKA_MODULUS;
	key_attr[2].type = CKA_PUBLIC_EXPONENT;

	f = p->function_list;
	session = p->slotinfo[slotidx].session;

	/* figure out size of the attributes */
	rv = f->C_GetAttributeValue(session, *obj, key_attr, 3);
	if (rv != CKR_OK) {
		error("C_GetAttributeValue failed: %lu", rv);
		return (NULL);
	}

	/* check that all *required* attributes are there */
	if (key_attr[1].ulValueLen == 0 || key_attr[2].ulValueLen == 0) {
		error("invalid attribute length");
		return (NULL);
	}

	/* allocate buffers for the attribute values */
	for (i = 0; i < 3; i++) {
		if (key_attr[i].ulValueLen != 0)
			key_attr[i].pValue = xcalloc(1, key_attr[i].ulValueLen);
	}

	/* retrieve ID, modulus and public exponent of the RSA key */
	rv = f->C_GetAttributeValue(session, *obj, key_attr, 3);
	if (rv != CKR_OK) {
		error("C_GetAttributeValue failed: %lu", rv);
		goto fail;
	}

	if ((rsa = RSA_new()) == NULL) {
		error("RSA_new failed");
		goto fail;
	}

	rsa_n = BN_bin2bn(key_attr[1].pValue, key_attr[1].ulValueLen, NULL);
	rsa_e = BN_bin2bn(key_attr[2].pValue, key_attr[2].ulValueLen, NULL);
	if (rsa_n == NULL || rsa_e == NULL) {
		error("BN_bin2bn failed");
		goto fail;
	}
	if (!RSA_set0_key(rsa, rsa_n, rsa_e, NULL))
		fatal_f("set key");

	if (pkcs11_rsa_wrap(p, slotidx, &key_attr[0], rsa))
		goto fail;

	if ((key = sshkey_new(KEY_UNSPEC)) == NULL) {
		error("sshkey_new failed");
		goto fail;
	}
	key->rsa = rsa;
	key->flags |= SSHKEY_FLAG_EXT;
	key->type = KEY_RSA;
	rsa = NULL;	/* now owned by key */

fail:
	for (i = 0; i < 3; i++)
		free(key_attr[i].pValue);
	RSA_free(rsa);

	return (key);
}


