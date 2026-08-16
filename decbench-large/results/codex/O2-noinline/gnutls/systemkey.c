// Function: print_list @ 0xf1f0
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef int gnutls_protocol_t;
typedef int gnutls_kx_algorithm_t;
typedef int gnutls_cipher_algorithm_t;
typedef int gnutls_mac_algorithm_t;
typedef int gnutls_digest_algorithm_t;
typedef int gnutls_compression_method_t;
typedef int gnutls_certificate_type_t;
typedef int gnutls_group_t;
typedef int gnutls_pk_algorithm_t;
typedef int gnutls_sign_algorithm_t;
typedef struct gnutls_priority_st *gnutls_priority_t;

enum {
    GNUTLS_E_REQUESTED_DATA_NOT_AVAILABLE = -56,
    GNUTLS_E_INVALID_REQUEST = -50,
    GNUTLS_E_UNKNOWN_CIPHER_SUITE = -21
};

extern int oprintf(FILE *, const char *, ...);
extern int gnutls_priority_init(gnutls_priority_t *, const char *,
                                const char **);
extern void gnutls_priority_deinit(gnutls_priority_t);
extern int gnutls_priority_get_cipher_suite_index(gnutls_priority_t,
                                                   unsigned int,
                                                   unsigned int *);
extern const char *gnutls_cipher_suite_info(size_t, unsigned char *,
                                            gnutls_kx_algorithm_t *,
                                            gnutls_cipher_algorithm_t *,
                                            gnutls_mac_algorithm_t *,
                                            gnutls_protocol_t *);
extern unsigned int gnutls_priority_protocol_list(
    gnutls_priority_t, const gnutls_protocol_t **);
extern unsigned int gnutls_priority_cipher_list(
    gnutls_priority_t, const gnutls_cipher_algorithm_t **);
extern unsigned int gnutls_priority_mac_list(
    gnutls_priority_t, const gnutls_mac_algorithm_t **);
extern unsigned int gnutls_priority_kx_list(
    gnutls_priority_t, const gnutls_kx_algorithm_t **);
extern unsigned int gnutls_priority_group_list(
    gnutls_priority_t, const gnutls_group_t **);
extern unsigned int gnutls_priority_sign_list(
    gnutls_priority_t, const gnutls_sign_algorithm_t **);
extern const char *gnutls_protocol_get_name(gnutls_protocol_t);
extern const char *gnutls_cipher_get_name(gnutls_cipher_algorithm_t);
extern const char *gnutls_mac_get_name(gnutls_mac_algorithm_t);
extern const char *gnutls_kx_get_name(gnutls_kx_algorithm_t);
extern const char *gnutls_group_get_name(gnutls_group_t);
extern const char *gnutls_sign_get_name(gnutls_sign_algorithm_t);
extern const char *gnutls_digest_get_name(gnutls_digest_algorithm_t);
extern const char *gnutls_compression_get_name(gnutls_compression_method_t);
extern const char *gnutls_certificate_type_get_name(gnutls_certificate_type_t);
extern const char *gnutls_pk_algorithm_get_name(gnutls_pk_algorithm_t);
extern const char *gnutls_strerror(int);
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

void print_list(const char *priorities, int verbose)
{
    gnutls_priority_t priority_cache;
    const char *err_pos;
    const char *name;
    const gnutls_protocol_t *protocols;
    const gnutls_cipher_algorithm_t *ciphers;
    const gnutls_mac_algorithm_t *macs;
    const gnutls_kx_algorithm_t *kxs;
    const gnutls_group_t *groups;
    const gnutls_sign_algorithm_t *signatures;
    unsigned char id[2];
    unsigned int suite;
    unsigned int i;
    unsigned int count;
    int ret;

    if (priorities != NULL) {
        oprintf(stdout, "Cipher suites for %s\n", priorities);

        ret = gnutls_priority_init(&priority_cache, priorities, &err_pos);
        if (ret < 0) {
            if (ret == GNUTLS_E_INVALID_REQUEST)
                fprintf(stderr, "Syntax error at: %s\n", err_pos);
            else
                fprintf(stderr, "Error in priorities: %s\n",
                        gnutls_strerror(ret));
            exit(1);
        }

        for (i = 0;; i++) {
            gnutls_protocol_t version;

            ret = gnutls_priority_get_cipher_suite_index(priority_cache, i,
                                                          &suite);
            if (ret == GNUTLS_E_REQUESTED_DATA_NOT_AVAILABLE)
                break;
            if (ret == GNUTLS_E_UNKNOWN_CIPHER_SUITE)
                continue;

            name = gnutls_cipher_suite_info(suite, id, NULL, NULL, NULL,
                                            &version);
            if (name != NULL)
                oprintf(stdout, "%-50s\t0x%02x, 0x%02x\t%s\n", name,
                        id[0], id[1], gnutls_protocol_get_name(version));
        }

        oprintf(stdout, "\n");

        count = gnutls_priority_protocol_list(priority_cache, &protocols);
        oprintf(stdout, "Protocols: ");
        if (count == 0) {
            oprintf(stdout, "none\n");
        } else {
            for (i = 0; i < count; i++) {
                oprintf(stdout, "VERS-%s",
                        gnutls_protocol_get_name(protocols[i]));
                oprintf(stdout, i + 1 < count ? ", " : "\n");
            }
        }

        count = gnutls_priority_cipher_list(priority_cache, &ciphers);
        oprintf(stdout, "Ciphers: ");
        if (count == 0) {
            oprintf(stdout, "none\n");
        } else {
            for (i = 0; i < count; i++) {
                oprintf(stdout, "%s", gnutls_cipher_get_name(ciphers[i]));
                oprintf(stdout, i + 1 < count ? ", " : "\n");
            }
        }

        count = gnutls_priority_mac_list(priority_cache, &macs);
        oprintf(stdout, "MACs: ");
        if (count == 0) {
            oprintf(stdout, "none\n");
        } else {
            for (i = 0; i < count; i++) {
                oprintf(stdout, "%s", gnutls_mac_get_name(macs[i]));
                oprintf(stdout, i + 1 < count ? ", " : "\n");
            }
        }

        count = gnutls_priority_kx_list(priority_cache, &kxs);
        oprintf(stdout, "Key Exchange Algorithms: ");
        if (count == 0) {
            oprintf(stdout, "none\n");
        } else {
            for (i = 0; i < count; i++) {
                oprintf(stdout, "%s", gnutls_kx_get_name(kxs[i]));
                oprintf(stdout, i + 1 < count ? ", " : "\n");
            }
        }

        count = gnutls_priority_group_list(priority_cache, &groups);
        oprintf(stdout, "Groups: ");
        if (count == 0) {
            oprintf(stdout, "none\n");
        } else {
            for (i = 0; i < count; i++) {
                oprintf(stdout, "GROUP-%s", gnutls_group_get_name(groups[i]));
                oprintf(stdout, i + 1 < count ? ", " : "\n");
            }
        }

        count = gnutls_priority_sign_list(priority_cache, &signatures);
        oprintf(stdout, "PK-signatures: ");
        if (count == 0) {
            oprintf(stdout, "none\n");
        } else {
            for (i = 0; i < count; i++) {
                oprintf(stdout, "SIGN-%s",
                        gnutls_sign_get_name(signatures[i]));
                oprintf(stdout, i + 1 < count ? ", " : "\n");
            }
        }

        gnutls_priority_deinit(priority_cache);
        return;
    }

    oprintf(stdout, "Cipher suites:\n");
    for (i = 0;; i++) {
        gnutls_kx_algorithm_t kx;
        gnutls_cipher_algorithm_t cipher;
        gnutls_mac_algorithm_t mac;
        gnutls_protocol_t version;

        name = gnutls_cipher_suite_info(i, id, &kx, &cipher, &mac, &version);
        if (name == NULL)
            break;

        oprintf(stdout, "%-50s\t0x%02x, 0x%02x\t%s\n", name, id[0], id[1],
                gnutls_protocol_get_name(version));
        if (verbose)
            oprintf(stdout, "\tKey exchange: %s\n\tCipher: %s\n\tMAC: %s\n\n",
                    gnutls_kx_get_name(kx),
                    gnutls_cipher_get_name(cipher),
                    gnutls_mac_get_name(mac));
    }
    oprintf(stdout, "\n");

    {
        const gnutls_certificate_type_t *list =
            gnutls_certificate_type_list();
        oprintf(stdout, "Certificate types: ");
        for (i = 0; list[i] != 0; i++) {
            oprintf(stdout, "CTYPE-%s",
                    gnutls_certificate_type_get_name(list[i]));
            oprintf(stdout, list[i + 1] != 0 ? ", " : "\n");
        }
    }

    {
        const gnutls_protocol_t *list = gnutls_protocol_list();
        oprintf(stdout, "Protocols: ");
        for (i = 0; list[i] != 0; i++) {
            oprintf(stdout, "VERS-%s", gnutls_protocol_get_name(list[i]));
            oprintf(stdout, list[i + 1] != 0 ? ", " : "\n");
        }
    }

    {
        const gnutls_cipher_algorithm_t *list = gnutls_cipher_list();
        oprintf(stdout, "Ciphers: ");
        for (i = 0; list[i] != 0; i++) {
            oprintf(stdout, "%s", gnutls_cipher_get_name(list[i]));
            oprintf(stdout, list[i + 1] != 0 ? ", " : "\n");
        }
    }

    {
        const gnutls_mac_algorithm_t *list = gnutls_mac_list();
        oprintf(stdout, "MACs: ");
        for (i = 0; list[i] != 0; i++) {
            oprintf(stdout, "%s", gnutls_mac_get_name(list[i]));
            oprintf(stdout, list[i + 1] != 0 ? ", " : "\n");
        }
    }

    {
        const gnutls_digest_algorithm_t *list = gnutls_digest_list();
        oprintf(stdout, "Digests: ");
        for (i = 0; list[i] != 0; i++) {
            oprintf(stdout, "%s", gnutls_digest_get_name(list[i]));
            oprintf(stdout, list[i + 1] != 0 ? ", " : "\n");
        }
    }

    {
        const gnutls_kx_algorithm_t *list = gnutls_kx_list();
        oprintf(stdout, "Key exchange algorithms: ");
        for (i = 0; list[i] != 0; i++) {
            oprintf(stdout, "%s", gnutls_kx_get_name(list[i]));
            oprintf(stdout, list[i + 1] != 0 ? ", " : "\n");
        }
    }

    {
        const gnutls_compression_method_t *list = gnutls_compression_list();
        oprintf(stdout, "Compression: ");
        for (i = 0; list[i] != 0; i++) {
            oprintf(stdout, "COMP-%s",
                    gnutls_compression_get_name(list[i]));
            oprintf(stdout, list[i + 1] != 0 ? ", " : "\n");
        }
    }

    {
        const gnutls_group_t *list = gnutls_group_list();
        oprintf(stdout, "Groups: ");
        for (i = 0; list[i] != 0; i++) {
            oprintf(stdout, "GROUP-%s", gnutls_group_get_name(list[i]));
            oprintf(stdout, list[i + 1] != 0 ? ", " : "\n");
        }
    }

    {
        const gnutls_pk_algorithm_t *list = gnutls_pk_list();
        oprintf(stdout, "Public Key Systems: ");
        for (i = 0; list[i] != 0; i++) {
            oprintf(stdout, "%s", gnutls_pk_algorithm_get_name(list[i]));
            oprintf(stdout, list[i + 1] != 0 ? ", " : "\n");
        }
    }

    {
        const gnutls_sign_algorithm_t *list = gnutls_sign_list();
        oprintf(stdout, "PK-signatures: ");
        for (i = 0; list[i] != 0; i++) {
            oprintf(stdout, "SIGN-%s", gnutls_sign_get_name(list[i]));
            oprintf(stdout, list[i + 1] != 0 ? ", " : "\n");
        }
    }
}


