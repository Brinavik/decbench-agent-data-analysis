// Function: ssh_rsa_verify @ 0x52cb0
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char u_char;
typedef struct bignum_st BIGNUM;
typedef struct rsa_st RSA;

struct sshbuf;

struct sshkey {
	int type;
	int flags;
	RSA *rsa;
};

enum {
	KEY_RSA = 0,
	SSH_RSA_MINIMUM_MODULUS_SIZE = 1024,
	SSH_DIGEST_MAX_LENGTH = 64,
	SSH_ERR_INTERNAL_ERROR = -1,
	SSH_ERR_ALLOC_FAIL = -2,
	SSH_ERR_INVALID_FORMAT = -4,
	SSH_ERR_INVALID_ARGUMENT = -10,
	SSH_ERR_KEY_BITS_MISMATCH = -11,
	SSH_ERR_KEY_TYPE_MISMATCH = -13,
	SSH_ERR_SIGNATURE_INVALID = -21,
	SSH_ERR_UNEXPECTED_TRAILING_DATA = -23,
	SSH_ERR_KEY_LENGTH = -56
};

extern int sshkey_type_plain(int);
extern struct sshbuf *sshbuf_from(const void *, size_t);
extern void sshbuf_free(struct sshbuf *);
extern size_t sshbuf_len(const struct sshbuf *);
extern int sshbuf_get_cstring(struct sshbuf *, char **, size_t *);
extern int sshbuf_get_string(struct sshbuf *, u_char **, size_t *);
extern int rsa_hash_id_from_keyname(const char *);
extern int rsa_hash_id_from_ident(const char *);
extern size_t ssh_digest_bytes(int);
extern int ssh_digest_memory(int, const void *, size_t, u_char *, size_t);
extern int openssh_RSA_verify(int, const u_char *, size_t,
    const u_char *, size_t, RSA *);
extern void RSA_get0_key(const RSA *, const BIGNUM **, const BIGNUM **,
    const BIGNUM **);
extern int BN_num_bits(const BIGNUM *);
extern int RSA_size(const RSA *);
extern void explicit_bzero(void *, size_t);
extern void freezero(void *, size_t);

int
ssh_rsa_verify(const struct sshkey *key, const u_char *sig, size_t siglen,
    const u_char *data, size_t datalen, const char *alg_ident)
{
	const BIGNUM *rsa_n;
	char *ktype = NULL;
	int hash_alg, want_hash_alg, ret = SSH_ERR_INTERNAL_ERROR;
	size_t len = 0, diff, modlen, dlen;
	struct sshbuf *b = NULL;
	u_char digest[SSH_DIGEST_MAX_LENGTH], *osig, *sigblob = NULL;

	if (key == NULL || key->rsa == NULL ||
	    sshkey_type_plain(key->type) != KEY_RSA ||
	    sig == NULL || siglen == 0)
		return SSH_ERR_INVALID_ARGUMENT;
	RSA_get0_key(key->rsa, &rsa_n, NULL, NULL);
	if (BN_num_bits(rsa_n) < SSH_RSA_MINIMUM_MODULUS_SIZE)
		return SSH_ERR_KEY_LENGTH;
	if ((b = sshbuf_from(sig, siglen)) == NULL)
		return SSH_ERR_ALLOC_FAIL;
	if (sshbuf_get_cstring(b, &ktype, NULL) != 0) {
		ret = SSH_ERR_INVALID_FORMAT;
		goto out;
	}
	if ((hash_alg = rsa_hash_id_from_keyname(ktype)) == -1) {
		ret = SSH_ERR_KEY_TYPE_MISMATCH;
		goto out;
	}
	if (alg_ident != NULL &&
	    strcmp(alg_ident, "ssh-rsa-cert-v01@openssh.com") != 0) {
		if ((want_hash_alg = rsa_hash_id_from_ident(alg_ident)) == -1) {
			ret = SSH_ERR_INVALID_ARGUMENT;
			goto out;
		}
		if (hash_alg != want_hash_alg) {
			ret = SSH_ERR_SIGNATURE_INVALID;
			goto out;
		}
	}
	if (sshbuf_get_string(b, &sigblob, &len) != 0) {
		ret = SSH_ERR_INVALID_FORMAT;
		goto out;
	}
	if (sshbuf_len(b) != 0) {
		ret = SSH_ERR_UNEXPECTED_TRAILING_DATA;
		goto out;
	}
	modlen = (size_t)RSA_size(key->rsa);
	if (len > modlen) {
		ret = SSH_ERR_KEY_BITS_MISMATCH;
		goto out;
	} else if (len < modlen) {
		diff = modlen - len;
		if ((osig = realloc(sigblob, modlen)) == NULL) {
			ret = SSH_ERR_ALLOC_FAIL;
			goto out;
		}
		sigblob = osig;
		memmove(sigblob + diff, sigblob, len);
		explicit_bzero(sigblob, diff);
		len = modlen;
	}
	if ((dlen = ssh_digest_bytes(hash_alg)) == 0) {
		ret = SSH_ERR_INTERNAL_ERROR;
		goto out;
	}
	if ((ret = ssh_digest_memory(hash_alg, data, datalen, digest,
	    sizeof(digest))) != 0)
		goto out;
	ret = openssh_RSA_verify(hash_alg, digest, dlen, sigblob, len,
	    key->rsa);

 out:
	freezero(sigblob, len);
	free(ktype);
	sshbuf_free(b);
	explicit_bzero(digest, sizeof(digest));
	return ret;
}


