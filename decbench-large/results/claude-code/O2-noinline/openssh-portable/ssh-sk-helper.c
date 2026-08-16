// Function: cert_parse @ 0x14ea0
#include <sys/types.h>
#include <stdlib.h>

typedef unsigned char u_char;

/* ssh error codes (values as observed in this binary) */
#define SSH_ERR_INTERNAL_ERROR			-1
#define SSH_ERR_ALLOC_FAIL			-2
#define SSH_ERR_INVALID_FORMAT			-4
#define SSH_ERR_KEY_CERT_INVALID		-18
#define SSH_ERR_KEY_CERT_INVALID_SIGN_KEY	-19

#define SSH2_CERT_TYPE_USER		1
#define SSH2_CERT_TYPE_HOST		2

#define SSHKEY_CERT_MAX_PRINCIPALS	256

struct sshbuf;

struct sshkey_cert {
	struct sshbuf	*certblob;	/* 0x00: kept for wire serialisation */
	u_int		 type;		/* 0x08: SSH2_CERT_TYPE_* */
	u_int64_t	 serial;	/* 0x10 */
	char		*key_id;	/* 0x18 */
	u_int		 nprincipals;	/* 0x20 */
	char		**principals;	/* 0x28 */
	u_int64_t	 valid_after;	/* 0x30 */
	u_int64_t	 valid_before;	/* 0x38 */
	struct sshbuf	*critical;	/* 0x40 */
	struct sshbuf	*extensions;	/* 0x48 */
	struct sshkey	*signature_key;	/* 0x50 */
	char		*signature_type;/* 0x58 */
};

struct sshkey {
	int		 type;		/* 0x00 */
	char		 pad[0x80 - sizeof(int)];
	struct sshkey_cert *cert;	/* 0x80 */
};

/* sshbuf primitives */
extern int sshbuf_putb(struct sshbuf *, const struct sshbuf *);
extern int sshbuf_get_u32(struct sshbuf *, u_int *);
extern int sshbuf_get_u64(struct sshbuf *, u_int64_t *);
extern int sshbuf_get_cstring(struct sshbuf *, char **, size_t *);
extern int sshbuf_get_string(struct sshbuf *, u_char **, size_t *);
extern int sshbuf_get_string_direct(struct sshbuf *, const u_char **, size_t *);
extern int sshbuf_froms(struct sshbuf *, struct sshbuf **);
extern size_t sshbuf_len(const struct sshbuf *);
extern const u_char *sshbuf_ptr(const struct sshbuf *);
extern void sshbuf_free(struct sshbuf *);
extern void sshbuf_reset(struct sshbuf *);

/* sshkey helpers */
extern int sshkey_from_blob_internal(struct sshbuf *, struct sshkey **, int);
extern int sshkey_type_is_valid_ca(int);
extern int sshkey_verify(const struct sshkey *, const u_char *, size_t,
    const u_char *, size_t, const char *, u_int, void *);
extern int sshkey_get_sigtype(const u_char *, size_t, char **);

extern void *recallocarray(void *, size_t, size_t, size_t);

static int
cert_parse(struct sshbuf *b, struct sshkey *key, const struct sshbuf *certbuf)
{
	struct sshbuf *principals = NULL, *crit = NULL;
	struct sshbuf *exts = NULL, *ca = NULL;
	u_char *sig = NULL;
	size_t signed_len = 0, slen = 0, kidlen = 0;
	int ret = SSH_ERR_INTERNAL_ERROR;

	/* Copy the entire key blob for verification and later serialisation. */
	if ((ret = sshbuf_putb(key->cert->certblob, certbuf)) != 0)
		return ret;

	if ((ret = sshbuf_get_u64(b, &key->cert->serial)) != 0 ||
	    (ret = sshbuf_get_u32(b, &key->cert->type)) != 0 ||
	    (ret = sshbuf_get_cstring(b, &key->cert->key_id, &kidlen)) != 0 ||
	    (ret = sshbuf_froms(b, &principals)) != 0 ||
	    (ret = sshbuf_get_u64(b, &key->cert->valid_after)) != 0 ||
	    (ret = sshbuf_get_u64(b, &key->cert->valid_before)) != 0 ||
	    (ret = sshbuf_froms(b, &crit)) != 0 ||
	    (ret = sshbuf_froms(b, &exts)) != 0 ||
	    (ret = sshbuf_get_string_direct(b, NULL, NULL)) != 0 || /* reserved */
	    (ret = sshbuf_froms(b, &ca)) != 0) {
		/* Any parse failure here is a malformed certificate. */
		ret = SSH_ERR_INVALID_FORMAT;
		goto out;
	}

	/* Signed portion of the certificate is everything up to the signature. */
	signed_len = sshbuf_len(key->cert->certblob) - sshbuf_len(b);

	/* Read signature. */
	if ((ret = sshbuf_get_string(b, &sig, &slen)) != 0) {
		ret = SSH_ERR_INVALID_FORMAT;
		goto out;
	}

	if (key->cert->type != SSH2_CERT_TYPE_USER &&
	    key->cert->type != SSH2_CERT_TYPE_HOST) {
		ret = SSH_ERR_KEY_CERT_INVALID;
		goto out;
	}

	/* Unpack the principals list. */
	while (sshbuf_len(principals) != 0) {
		char *principal = NULL;
		char **oprincipals;

		if (key->cert->nprincipals >= SSHKEY_CERT_MAX_PRINCIPALS) {
			ret = SSH_ERR_INVALID_FORMAT;
			goto out;
		}
		if ((ret = sshbuf_get_cstring(principals, &principal, NULL)) != 0) {
			ret = SSH_ERR_INVALID_FORMAT;
			goto out;
		}
		oprincipals = key->cert->principals;
		key->cert->principals = recallocarray(key->cert->principals,
		    key->cert->nprincipals, key->cert->nprincipals + 1,
		    sizeof(*key->cert->principals));
		if (key->cert->principals == NULL) {
			free(principal);
			key->cert->principals = oprincipals;
			ret = SSH_ERR_ALLOC_FAIL;
			goto out;
		}
		key->cert->principals[key->cert->nprincipals++] = principal;
	}

	/* Preserve the critical options and extensions blobs. */
	if ((ret = sshbuf_putb(key->cert->critical, crit)) != 0)
		goto out;
	if (exts != NULL &&
	    (ret = sshbuf_putb(key->cert->extensions, exts)) != 0)
		goto out;

	/* Ensure critical options are well-formed name/data pairs. */
	while (sshbuf_len(crit) != 0) {
		if ((ret = sshbuf_get_string_direct(crit, NULL, NULL)) != 0 ||
		    (ret = sshbuf_get_string_direct(crit, NULL, NULL)) != 0) {
			sshbuf_reset(key->cert->critical);
			ret = SSH_ERR_INVALID_FORMAT;
			goto out;
		}
	}
	/* Ditto for extensions. */
	while (exts != NULL && sshbuf_len(exts) != 0) {
		if ((ret = sshbuf_get_string_direct(exts, NULL, NULL)) != 0 ||
		    (ret = sshbuf_get_string_direct(exts, NULL, NULL)) != 0) {
			sshbuf_reset(key->cert->extensions);
			ret = SSH_ERR_INVALID_FORMAT;
			goto out;
		}
	}

	/* Parse CA key and check that it is a plausible signing key. */
	if ((ret = sshkey_from_blob_internal(ca, &key->cert->signature_key,
	    0)) != 0) {
		ret = SSH_ERR_KEY_CERT_INVALID_SIGN_KEY;
		goto out;
	}
	if (!sshkey_type_is_valid_ca(key->cert->signature_key->type)) {
		ret = SSH_ERR_KEY_CERT_INVALID_SIGN_KEY;
		goto out;
	}

	/* Verify the certificate signature over the signed portion. */
	if ((ret = sshkey_verify(key->cert->signature_key, sig, slen,
	    sshbuf_ptr(key->cert->certblob), signed_len, NULL, 0, NULL)) != 0)
		goto out;

	/* Remember the signature algorithm used to sign the certificate. */
	if ((ret = sshkey_get_sigtype(sig, slen,
	    &key->cert->signature_type)) != 0)
		goto out;

	/* Success */
	ret = 0;
 out:
	sshbuf_free(principals);
	sshbuf_free(crit);
	sshbuf_free(exts);
	sshbuf_free(ca);
	free(sig);
	return ret;
}


