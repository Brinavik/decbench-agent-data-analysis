// Function: cert_parse @ 0x14ea0
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

struct sshbuf;
struct sshkey;

struct sshkey_cert {
	struct sshbuf *certblob;
	uint32_t type;
	uint64_t serial;
	char *key_id;
	unsigned int nprincipals;
	char **principals;
	uint64_t valid_after;
	uint64_t valid_before;
	struct sshbuf *critical;
	struct sshbuf *extensions;
	struct sshkey *signature_key;
	char *signature_type;
};

struct sshkey {
	int type;
	unsigned char opaque[124];
	struct sshkey_cert *cert;
};

enum {
	SSH_ERR_ALLOC_FAIL = -2,
	SSH_ERR_INVALID_FORMAT = -4,
	SSH_ERR_KEY_CERT_UNKNOWN_TYPE = -18,
	SSH_ERR_KEY_CERT_INVALID_SIGN_KEY = -19,
	SSH2_CERT_TYPE_USER = 1,
	SSH2_CERT_TYPE_HOST = 2,
	SSHKEY_CERT_MAX_PRINCIPALS = 256
};

extern int sshbuf_putb(struct sshbuf *, const struct sshbuf *);
extern int sshbuf_get_u64(struct sshbuf *, uint64_t *);
extern int sshbuf_get_u32(struct sshbuf *, uint32_t *);
extern int sshbuf_get_cstring(struct sshbuf *, char **, size_t *);
extern int sshbuf_get_string(struct sshbuf *, unsigned char **, size_t *);
extern int sshbuf_froms(struct sshbuf *, struct sshbuf **);
extern size_t sshbuf_len(const struct sshbuf *);
extern const unsigned char *sshbuf_ptr(const struct sshbuf *);
extern void sshbuf_free(struct sshbuf *);
extern void sshbuf_reset(struct sshbuf *);
extern void *recallocarray(void *, size_t, size_t, size_t);
extern int sshkey_from_blob_internal(struct sshbuf *, struct sshkey **, int);
extern int sshkey_type_is_valid_ca(int);
extern int sshkey_verify(const struct sshkey *, const unsigned char *, size_t,
    const unsigned char *, size_t, const char *, unsigned int, void **);
extern int sshkey_get_sigtype(const unsigned char *, size_t, char **);

int
cert_parse(struct sshbuf *b, struct sshkey *key, const struct sshbuf *certbuf)
{
	struct sshbuf *principals = NULL, *critical = NULL;
	struct sshbuf *extensions = NULL, *ca = NULL;
	unsigned char *sig = NULL;
	char *principal = NULL;
	char **old_principals;
	size_t key_id_len = 0, siglen = 0, signed_len;
	int ret;

	if ((ret = sshbuf_putb(key->cert->certblob, certbuf)) != 0)
		return ret;

	if (sshbuf_get_u64(b, &key->cert->serial) != 0 ||
	    sshbuf_get_u32(b, &key->cert->type) != 0 ||
	    sshbuf_get_cstring(b, &key->cert->key_id, &key_id_len) != 0 ||
	    sshbuf_froms(b, &principals) != 0 ||
	    sshbuf_get_u64(b, &key->cert->valid_after) != 0 ||
	    sshbuf_get_u64(b, &key->cert->valid_before) != 0 ||
	    sshbuf_froms(b, &critical) != 0 ||
	    sshbuf_froms(b, &extensions) != 0 ||
	    sshbuf_get_string(b, NULL, NULL) != 0 ||
	    sshbuf_froms(b, &ca) != 0) {
		ret = SSH_ERR_INVALID_FORMAT;
		goto out;
	}

	signed_len = sshbuf_len(key->cert->certblob) - sshbuf_len(b);
	if (sshbuf_get_string(b, &sig, &siglen) != 0) {
		ret = SSH_ERR_INVALID_FORMAT;
		goto out;
	}

	if (key->cert->type != SSH2_CERT_TYPE_USER &&
	    key->cert->type != SSH2_CERT_TYPE_HOST) {
		ret = SSH_ERR_KEY_CERT_UNKNOWN_TYPE;
		goto out;
	}

	while (sshbuf_len(principals) != 0) {
		principal = NULL;
		if (key->cert->nprincipals >= SSHKEY_CERT_MAX_PRINCIPALS ||
		    sshbuf_get_cstring(principals, &principal, NULL) != 0) {
			ret = SSH_ERR_INVALID_FORMAT;
			goto out;
		}
		old_principals = key->cert->principals;
		key->cert->principals = recallocarray(key->cert->principals,
		    key->cert->nprincipals, key->cert->nprincipals + 1,
		    sizeof(*key->cert->principals));
		if (key->cert->principals == NULL) {
			free(principal);
			key->cert->principals = old_principals;
			ret = SSH_ERR_ALLOC_FAIL;
			goto out;
		}
		key->cert->principals[key->cert->nprincipals++] = principal;
		principal = NULL;
	}

	if ((ret = sshbuf_putb(key->cert->critical, critical)) != 0)
		goto out;
	if (extensions != NULL &&
	    (ret = sshbuf_putb(key->cert->extensions, extensions)) != 0)
		goto out;

	while (sshbuf_len(critical) != 0) {
		if (sshbuf_get_string(critical, NULL, NULL) != 0 ||
		    sshbuf_get_string(critical, NULL, NULL) != 0) {
			sshbuf_reset(key->cert->critical);
			ret = SSH_ERR_INVALID_FORMAT;
			goto out;
		}
	}

	while (extensions != NULL && sshbuf_len(extensions) != 0) {
		if (sshbuf_get_string(extensions, NULL, NULL) != 0 ||
		    sshbuf_get_string(extensions, NULL, NULL) != 0) {
			sshbuf_reset(key->cert->extensions);
			ret = SSH_ERR_INVALID_FORMAT;
			goto out;
		}
	}

	if (sshkey_from_blob_internal(ca, &key->cert->signature_key, 0) != 0 ||
	    !sshkey_type_is_valid_ca(key->cert->signature_key->type)) {
		ret = SSH_ERR_KEY_CERT_INVALID_SIGN_KEY;
		goto out;
	}

	ret = sshkey_verify(key->cert->signature_key, sig, siglen,
	    sshbuf_ptr(key->cert->certblob), signed_len, NULL, 0, NULL);
	if (ret != 0)
		goto out;

	ret = sshkey_get_sigtype(sig, siglen, &key->cert->signature_type);

out:
	sshbuf_free(ca);
	sshbuf_free(critical);
	sshbuf_free(extensions);
	sshbuf_free(principals);
	free(sig);
	return ret;
}


