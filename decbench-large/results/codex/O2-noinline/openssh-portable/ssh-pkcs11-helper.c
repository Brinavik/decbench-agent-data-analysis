// Function: pkcs11_fetch_rsa_pubkey @ 0xb1c0
#include <stddef.h>
#include <stdlib.h>

typedef unsigned long CK_ULONG;
typedef CK_ULONG CK_RV;
typedef CK_ULONG CK_SESSION_HANDLE;
typedef CK_ULONG CK_OBJECT_HANDLE;
typedef CK_ULONG CK_ATTRIBUTE_TYPE;

typedef struct {
    CK_ATTRIBUTE_TYPE type;
    void *pValue;
    CK_ULONG ulValueLen;
} CK_ATTRIBUTE;

typedef struct rsa_st RSA;
typedef struct bignum_st BIGNUM;

struct ck_function_list {
    unsigned char _pad[0xc8];
    CK_RV (*C_GetAttributeValue)(CK_SESSION_HANDLE, CK_OBJECT_HANDLE,
        CK_ATTRIBUTE *, CK_ULONG);
};

struct pkcs11_slotinfo {
    unsigned char _pad[0xd0];
    CK_SESSION_HANDLE session;
    unsigned char _tail[8];
};

struct pkcs11_provider {
    unsigned char _pad0[0x10];
    struct ck_function_list *function_list;
    unsigned char _pad18[0x68];
    struct pkcs11_slotinfo *slotinfo;
};

struct sshkey {
    int type;
    unsigned int flags;
    RSA *rsa;
};

enum {
    CKR_OK = 0,
    CKA_ID = 0x102,
    CKA_MODULUS = 0x120,
    CKA_PUBLIC_EXPONENT = 0x122,
    KEY_RSA = 0,
    KEY_UNSPEC = 14,
    SSHKEY_FLAG_EXT = 1
};

extern void *xcalloc(size_t, size_t);
extern RSA *RSA_new(void);
extern void RSA_free(RSA *);
extern BIGNUM *BN_bin2bn(const unsigned char *, int, BIGNUM *);
extern int RSA_set0_key(RSA *, BIGNUM *, BIGNUM *, BIGNUM *);
extern int pkcs11_rsa_wrap(struct pkcs11_provider *, CK_ULONG,
    CK_ATTRIBUTE *, RSA *);
extern struct sshkey *sshkey_new(int);
extern void error(const char *, ...);
_Noreturn extern void fatal_f(const char *, ...);

struct sshkey *
pkcs11_fetch_rsa_pubkey(struct pkcs11_provider *p, CK_ULONG slotidx,
    CK_OBJECT_HANDLE *obj)
{
    struct sshkey *key = NULL;
    RSA *rsa = NULL;
    BIGNUM *rsa_n, *rsa_e;
    CK_SESSION_HANDLE session;
    struct ck_function_list *f;
    CK_RV rv;
    CK_ATTRIBUTE key_attr[3] = {
        { CKA_ID, NULL, 0 },
        { CKA_MODULUS, NULL, 0 },
        { CKA_PUBLIC_EXPONENT, NULL, 0 }
    };
    int i;

    f = p->function_list;
    session = p->slotinfo[slotidx].session;
    if ((rv = f->C_GetAttributeValue(session, *obj, key_attr, 3)) !=
        CKR_OK) {
        error("C_GetAttributeValue failed: %lu", rv);
        return NULL;
    }
    if (key_attr[1].ulValueLen == 0 || key_attr[2].ulValueLen == 0) {
        error("invalid attribute length");
        return NULL;
    }
    for (i = 0; i < 3; i++) {
        if (key_attr[i].ulValueLen != 0)
            key_attr[i].pValue = xcalloc(1, key_attr[i].ulValueLen);
    }
    if ((rv = f->C_GetAttributeValue(session, *obj, key_attr, 3)) !=
        CKR_OK) {
        error("C_GetAttributeValue failed: %lu", rv);
        goto out;
    }
    if ((rsa = RSA_new()) == NULL) {
        error("RSA_new failed");
        goto out;
    }
    rsa_n = BN_bin2bn(key_attr[1].pValue,
        (int)key_attr[1].ulValueLen, NULL);
    rsa_e = BN_bin2bn(key_attr[2].pValue,
        (int)key_attr[2].ulValueLen, NULL);
    if (rsa_n == NULL || rsa_e == NULL) {
        error("BN_bin2bn failed");
        goto out;
    }
    if (!RSA_set0_key(rsa, rsa_n, rsa_e, NULL))
        fatal_f("set key");
    if (pkcs11_rsa_wrap(p, slotidx, &key_attr[0], rsa) != 0)
        goto out;
    if ((key = sshkey_new(KEY_UNSPEC)) == NULL) {
        error("sshkey_new failed");
        goto out;
    }
    key->rsa = rsa;
    key->type = KEY_RSA;
    key->flags |= SSHKEY_FLAG_EXT;
    rsa = NULL;

out:
    for (i = 0; i < 3; i++)
        free(key_attr[i].pValue);
    RSA_free(rsa);
    return key;
}


