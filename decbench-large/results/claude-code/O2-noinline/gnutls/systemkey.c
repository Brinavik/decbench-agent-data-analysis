// Function: print_list @ 0xf1f0
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/* gnutls opaque/enum types (all algorithm enums are ints on this ABI) */
typedef void *gnutls_priority_t;
typedef int gnutls_protocol_t;
typedef int gnutls_cipher_algorithm_t;
typedef int gnutls_mac_algorithm_t;
typedef int gnutls_kx_algorithm_t;
typedef int gnutls_digest_algorithm_t;
typedef int gnutls_compression_method_t;
typedef int gnutls_group_t;
typedef int gnutls_pk_algorithm_t;
typedef int gnutls_sign_algorithm_t;
typedef int gnutls_certificate_type_t;

/* relevant gnutls error codes */
#define GNUTLS_E_INVALID_REQUEST              (-50)
#define GNUTLS_E_UNKNOWN_CIPHER_SUITE         (-21)
#define GNUTLS_E_REQUESTED_DATA_NOT_AVAILABLE (-56)

extern const char *gnutls_strerror(int error);

extern int gnutls_priority_init(gnutls_priority_t *priority_cache,
                                const char *priorities, const char **err_pos);
extern void gnutls_priority_deinit(gnutls_priority_t priority_cache);
extern int gnutls_priority_get_cipher_suite_index(gnutls_priority_t pcache,
                                                  unsigned int idx,
                                                  unsigned int *sidx);

extern const char *gnutls_cipher_suite_info(size_t idx, unsigned char *cs_id,
                                            gnutls_kx_algorithm_t *kx,
                                            gnutls_cipher_algorithm_t *cipher,
                                            gnutls_mac_algorithm_t *mac,
                                            gnutls_protocol_t *version);

extern int gnutls_priority_protocol_list(gnutls_priority_t pcache,
                                         const unsigned int **list);
extern int gnutls_priority_cipher_list(gnutls_priority_t pcache,
                                       const unsigned int **list);
extern int gnutls_priority_mac_list(gnutls_priority_t pcache,
                                    const unsigned int **list);
extern int gnutls_priority_kx_list(gnutls_priority_t pcache,
                                   const unsigned int **list);
extern int gnutls_priority_group_list(gnutls_priority_t pcache,
                                      const unsigned int **list);
extern int gnutls_priority_sign_list(gnutls_priority_t pcache,
                                     const unsigned int **list);

extern const gnutls_certificate_type_t *gnutls_certificate_type_list(void);
extern const gnutls_protocol_t *gnutls_protocol_list(void);
extern const gnutls_cipher_algorithm_t *gnutls_cipher_list(void);
extern const gnutls_mac_algorithm_t *gnutls_mac_list(void);
extern const gnutls_digest_algorithm_t *gnutls_digest_list(void);
extern const gnutls_kx_algorithm_t *gnutls_kx_list(void);
extern const gnutls_compression_method_t *gnutls_compression_list(void);
extern const gnutls_group_t *gnutls_group_list(void);
extern const gnutls_pk_algorithm_t *gnutls_pk_list(void);
extern const gnutls_sign_algorithm_t *gnutls_sign_list(void);

extern const char *gnutls_protocol_get_name(gnutls_protocol_t version);
extern const char *gnutls_cipher_get_name(gnutls_cipher_algorithm_t algorithm);
extern const char *gnutls_mac_get_name(gnutls_mac_algorithm_t algorithm);
extern const char *gnutls_digest_get_name(gnutls_digest_algorithm_t algorithm);
extern const char *gnutls_kx_get_name(gnutls_kx_algorithm_t algorithm);
extern const char *gnutls_compression_get_name(gnutls_compression_method_t algorithm);
extern const char *gnutls_group_get_name(gnutls_group_t group);
extern const char *gnutls_pk_algorithm_get_name(gnutls_pk_algorithm_t algorithm);
extern const char *gnutls_sign_get_name(gnutls_sign_algorithm_t algorithm);
extern const char *gnutls_certificate_type_get_name(gnutls_certificate_type_t type);

void print_list(const char *priorities, int verbose)
{
	gnutls_priority_t pcache;
	const char *err;
	const char *name;
	unsigned int idx;
	gnutls_protocol_t version;
	gnutls_kx_algorithm_t kx;
	gnutls_cipher_algorithm_t cipher;
	gnutls_mac_algorithm_t mac;
	unsigned char id[2];
	const unsigned int *list;
	size_t i;
	int ret;

	if (priorities != NULL) {
		fprintf(stdout, "Cipher suites for %s\n", priorities);

		ret = gnutls_priority_init(&pcache, priorities, &err);
		if (ret < 0) {
			if (ret == GNUTLS_E_INVALID_REQUEST)
				fprintf(stderr, "Syntax error at: %s\n", err);
			else
				fprintf(stderr, "Error in priorities: %s\n",
					gnutls_strerror(ret));
			exit(1);
		}

		for (i = 0;; i++) {
			ret = gnutls_priority_get_cipher_suite_index(pcache, i,
								     &idx);
			if (ret == GNUTLS_E_UNKNOWN_CIPHER_SUITE)
				continue;
			if (ret == GNUTLS_E_REQUESTED_DATA_NOT_AVAILABLE)
				break;

			name = gnutls_cipher_suite_info(idx, id, NULL, NULL,
							NULL, &version);
			if (name != NULL)
				fprintf(stdout,
					"%-50s\t0x%02x, 0x%02x\t%s\n", name,
					(unsigned char) id[0],
					(unsigned char) id[1],
					gnutls_protocol_get_name(version));
		}

		fprintf(stdout, "\n");

		fprintf(stdout, "Protocols: ");
		ret = gnutls_priority_protocol_list(pcache, &list);
		if (ret == 0) {
			fprintf(stdout, "none\n");
		} else {
			for (i = 0; i < (size_t) ret; i++) {
				fprintf(stdout, "VERS-%s",
					gnutls_protocol_get_name(list[i]));
				if (i + 1 != (size_t) ret)
					fprintf(stdout, ", ");
			}
			fprintf(stdout, "\n");
		}

		fprintf(stdout, "Ciphers: ");
		ret = gnutls_priority_cipher_list(pcache, &list);
		if (ret == 0) {
			fprintf(stdout, "none\n");
		} else {
			for (i = 0; i < (size_t) ret; i++) {
				fprintf(stdout, "%s",
					gnutls_cipher_get_name(list[i]));
				if (i + 1 != (size_t) ret)
					fprintf(stdout, ", ");
			}
			fprintf(stdout, "\n");
		}

		fprintf(stdout, "MACs: ");
		ret = gnutls_priority_mac_list(pcache, &list);
		if (ret == 0) {
			fprintf(stdout, "none\n");
		} else {
			for (i = 0; i < (size_t) ret; i++) {
				fprintf(stdout, "%s",
					gnutls_mac_get_name(list[i]));
				if (i + 1 != (size_t) ret)
					fprintf(stdout, ", ");
			}
			fprintf(stdout, "\n");
		}

		fprintf(stdout, "Key Exchange Algorithms: ");
		ret = gnutls_priority_kx_list(pcache, &list);
		if (ret == 0) {
			fprintf(stdout, "none\n");
		} else {
			for (i = 0; i < (size_t) ret; i++) {
				fprintf(stdout, "%s",
					gnutls_kx_get_name(list[i]));
				if (i + 1 != (size_t) ret)
					fprintf(stdout, ", ");
			}
			fprintf(stdout, "\n");
		}

		fprintf(stdout, "Groups: ");
		ret = gnutls_priority_group_list(pcache, &list);
		if (ret == 0) {
			fprintf(stdout, "none\n");
		} else {
			for (i = 0; i < (size_t) ret; i++) {
				fprintf(stdout, "GROUP-%s",
					gnutls_group_get_name(list[i]));
				if (i + 1 != (size_t) ret)
					fprintf(stdout, ", ");
			}
			fprintf(stdout, "\n");
		}

		fprintf(stdout, "PK-signatures: ");
		ret = gnutls_priority_sign_list(pcache, &list);
		if (ret == 0) {
			fprintf(stdout, "none\n");
		} else {
			for (i = 0; i < (size_t) ret; i++) {
				fprintf(stdout, "SIGN-%s",
					gnutls_sign_get_name(list[i]));
				if (i + 1 != (size_t) ret)
					fprintf(stdout, ", ");
			}
			fprintf(stdout, "\n");
		}

		gnutls_priority_deinit(pcache);
		return;
	}

	fprintf(stdout, "Cipher suites:\n");
	for (i = 0;; i++) {
		name = gnutls_cipher_suite_info(i, id, &kx, &cipher, &mac,
						&version);
		if (name == NULL)
			break;

		fprintf(stdout, "%-50s\t0x%02x, 0x%02x\t%s\n", name,
			(unsigned char) id[0], (unsigned char) id[1],
			gnutls_protocol_get_name(version));

		if (verbose)
			fprintf(stdout,
				"\tKey exchange: %s\n\tCipher: %s\n\tMAC: %s\n\n",
				gnutls_kx_get_name(kx),
				gnutls_cipher_get_name(cipher),
				gnutls_mac_get_name(mac));
	}

	fprintf(stdout, "\n");

	{
		const gnutls_certificate_type_t *p =
			gnutls_certificate_type_list();
		fprintf(stdout, "Certificate types: ");
		for (i = 0; p[i] != 0; i++) {
			fprintf(stdout, "CTYPE-%s",
				gnutls_certificate_type_get_name(p[i]));
			if (p[i + 1] != 0)
				fprintf(stdout, ", ");
			else
				fprintf(stdout, "\n");
		}
	}

	{
		const gnutls_protocol_t *p = gnutls_protocol_list();
		fprintf(stdout, "Protocols: ");
		for (i = 0; p[i] != 0; i++) {
			fprintf(stdout, "VERS-%s",
				gnutls_protocol_get_name(p[i]));
			if (p[i + 1] != 0)
				fprintf(stdout, ", ");
			else
				fprintf(stdout, "\n");
		}
	}

	{
		const gnutls_cipher_algorithm_t *p = gnutls_cipher_list();
		fprintf(stdout, "Ciphers: ");
		for (i = 0; p[i] != 0; i++) {
			fprintf(stdout, "%s", gnutls_cipher_get_name(p[i]));
			if (p[i + 1] != 0)
				fprintf(stdout, ", ");
			else
				fprintf(stdout, "\n");
		}
	}

	{
		const gnutls_mac_algorithm_t *p = gnutls_mac_list();
		fprintf(stdout, "MACs: ");
		for (i = 0; p[i] != 0; i++) {
			fprintf(stdout, "%s", gnutls_mac_get_name(p[i]));
			if (p[i + 1] != 0)
				fprintf(stdout, ", ");
			else
				fprintf(stdout, "\n");
		}
	}

	{
		const gnutls_digest_algorithm_t *p = gnutls_digest_list();
		fprintf(stdout, "Digests: ");
		for (i = 0; p[i] != 0; i++) {
			fprintf(stdout, "%s", gnutls_digest_get_name(p[i]));
			if (p[i + 1] != 0)
				fprintf(stdout, ", ");
			else
				fprintf(stdout, "\n");
		}
	}

	{
		const gnutls_kx_algorithm_t *p = gnutls_kx_list();
		fprintf(stdout, "Key exchange algorithms: ");
		for (i = 0; p[i] != 0; i++) {
			fprintf(stdout, "%s", gnutls_kx_get_name(p[i]));
			if (p[i + 1] != 0)
				fprintf(stdout, ", ");
			else
				fprintf(stdout, "\n");
		}
	}

	{
		const gnutls_compression_method_t *p =
			gnutls_compression_list();
		fprintf(stdout, "Compression: ");
		for (i = 0; p[i] != 0; i++) {
			fprintf(stdout, "COMP-%s",
				gnutls_compression_get_name(p[i]));
			if (p[i + 1] != 0)
				fprintf(stdout, ", ");
			else
				fprintf(stdout, "\n");
		}
	}

	{
		const gnutls_group_t *p = gnutls_group_list();
		fprintf(stdout, "Groups: ");
		for (i = 0; p[i] != 0; i++) {
			fprintf(stdout, "GROUP-%s",
				gnutls_group_get_name(p[i]));
			if (p[i + 1] != 0)
				fprintf(stdout, ", ");
			else
				fprintf(stdout, "\n");
		}
	}

	{
		const gnutls_pk_algorithm_t *p = gnutls_pk_list();
		fprintf(stdout, "Public Key Systems: ");
		for (i = 0; p[i] != 0; i++) {
			fprintf(stdout, "%s",
				gnutls_pk_algorithm_get_name(p[i]));
			if (p[i + 1] != 0)
				fprintf(stdout, ", ");
			else
				fprintf(stdout, "\n");
		}
	}

	{
		const gnutls_sign_algorithm_t *p = gnutls_sign_list();
		fprintf(stdout, "PK-signatures: ");
		for (i = 0; p[i] != 0; i++) {
			fprintf(stdout, "SIGN-%s",
				gnutls_sign_get_name(p[i]));
			if (p[i + 1] != 0)
				fprintf(stdout, ", ");
			else
				fprintf(stdout, "\n");
		}
	}
}


