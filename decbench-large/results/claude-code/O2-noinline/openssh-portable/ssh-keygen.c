// Function: ssh_rsa_verify @ 0x52cb0
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

/* Opaque crypto/buffer types */
typedef struct rsa_st RSA;
typedef struct bignum_st BIGNUM;
struct sshbuf;

/* struct sshkey (only the fields this function touches) */
struct sshkey {
	int	 type;		/* offset 0x00 */
	int	 flags;		/* offset 0x04 */
	RSA	*rsa;		/* offset 0x08 */
};

/* enum sshkey_types: KEY_RSA is the first value == 0 */
#define KEY_RSA				0

/* ssherr.h return codes (values as used by this build) */
#define SSH_ERR_INTERNAL_ERROR		-1
#define SSH_ERR_ALLOC_FAIL		-2
#define SSH_ERR_INVALID_FORMAT		-4
#define SSH_ERR_INVALID_ARGUMENT	-10
#define SSH_ERR_KEY_BITS_MISMATCH	-11
#define SSH_ERR_KEY_TYPE_MISMATCH	-13
#define SSH_ERR_SIGNATURE_INVALID	-21
#define SSH_ERR_UNEXPECTED_TRAILING_DATA -23
#define SSH_ERR_KEY_LENGTH		-56

#define SSH_RSA_MINIMUM_MODULUS_SIZE	1024
#define SSH_DIGEST_MAX_LENGTH		64

/* externs */
extern int sshkey_type_plain(int);
extern void RSA_get0_key(const RSA *, const BIGNUM **, const BIGNUM **,
    const BIGNUM **);
extern int BN_num_bits(const BIGNUM *);
extern int RSA_size(const RSA *);

extern struct sshbuf *sshbuf_from(const void *, size_t);
extern int sshbuf_get_cstring(struct sshbuf *, char **, size_t *);
extern int sshbuf_get_string(struct sshbuf *, u_char **, size_t *);
extern size_t sshbuf_len(const struct sshbuf *);
extern void sshbuf_free(struct sshbuf *);

extern int rsa_hash_alg_from_ident(const char *);
extern size_t ssh_digest_bytes(int);
extern int ssh_digest_memory(int, const void *, size_t, u_char *, size_t);
extern int openssh_RSA_verify(int, u_char *, size_t, u_char *, size_t, RSA *);

extern void freezero(void *, size_t);
extern void explicit_bzero(void *, size_t);

int
ssh_rsa_verify(const struct sshkey *key, const u_char *sig, size_t siglen,
    const u_char *data, size_t datalen, const char *alg)
{
	char *sigtype = NULL;
	int hash_alg, want_alg, ret = SSH_ERR_INTERNAL_ERROR;
	size_t len = 0, diff, modlen, dlen;
	struct sshbuf *b = NULL;
	u_char digest[SSH_DIGEST_MAX_LENGTH], *osigblob, *sigblob = NULL;
	const BIGNUM *rsa_n;

	if (key == NULL || key->rsa == NULL ||
	    sshkey_type_plain(key->type) != KEY_RSA ||
	    sig == NULL || siglen == 0)
		return SSH_ERR_INVALID_ARGUMENT;

	RSA_get0_key(key->rsa, &rsa_n, NULL, NULL);
	if (BN_num_bits(rsa_n) < SSH_RSA_MINIMUM_MODULUS_SIZE)
		return SSH_ERR_KEY_LENGTH;

	/* Extract signature blob */
	if ((b = sshbuf_from(sig, siglen)) == NULL)
		return SSH_ERR_ALLOC_FAIL;
	if (sshbuf_get_cstring(b, &sigtype, NULL) != 0) {
		ret = SSH_ERR_INVALID_FORMAT;
		goto out;
	}
	if ((hash_alg = rsa_hash_alg_from_ident(sigtype)) == -1) {
		ret = SSH_ERR_KEY_TYPE_MISMATCH;
		goto out;
	}
	/*
	 * Allow ssh-rsa-cert-v01 signatures made using either of the
	 * SHA-2 algorithms, but require an exact match otherwise.
	 */
	if (alg != NULL && strcmp(alg, "ssh-rsa") != 0) {
		if ((want_alg = rsa_hash_alg_from_ident(alg)) == -1) {
			ret = SSH_ERR_INVALID_ARGUMENT;
			goto out;
		}
		if (hash_alg != want_alg) {
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
	/* RSA_verify expects a signature of RSA_size */
	modlen = RSA_size(key->rsa);
	if (len > modlen) {
		ret = SSH_ERR_KEY_BITS_MISMATCH;
		goto out;
	} else if (len < modlen) {
		diff = modlen - len;
		osigblob = sigblob;
		if ((sigblob = realloc(sigblob, modlen)) == NULL) {
			sigblob = osigblob; /* put it back for clear/free */
			ret = SSH_ERR_ALLOC_FAIL;
			goto out;
		}
		memmove(sigblob + diff, sigblob, len);
		explicit_bzero(sigblob, diff);
		len = modlen;
	}
	if ((dlen = ssh_digest_bytes(hash_alg)) == 0) {
		/* ret == SSH_ERR_INTERNAL_ERROR */
		goto out;
	}
	if ((ret = ssh_digest_memory(hash_alg, data, datalen,
	    digest, sizeof(digest))) != 0)
		goto out;

	ret = openssh_RSA_verify(hash_alg, digest, dlen, sigblob, len,
	    key->rsa);
 out:
	freezero(sigblob, len);
	free(sigtype);
	sshbuf_free(b);
	explicit_bzero(digest, sizeof(digest));
	return ret;
}


