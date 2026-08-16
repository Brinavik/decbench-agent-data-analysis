// Function: main @ 0x7e00
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    typedef void *gnutls_certificate_credentials_t;
    typedef void *gnutls_srp_server_credentials_t;
    typedef void *gnutls_psk_server_credentials_t;
    typedef void *gnutls_anon_server_credentials_t;
    typedef void *gnutls_anti_replay_t;
    typedef void *gl_list_t;
    typedef struct {
        unsigned char *data;
        unsigned int size;
    } gnutls_datum_t;

    enum {
        GNUTLS_X509_FMT_DER = 0,
        GNUTLS_X509_FMT_PEM = 1,
        GNUTLS_SEC_PARAM_MEDIUM = 35,
        GNUTLS_CERTIFICATE_SKIP_OCSP_RESPONSE_CHECK = 4
    };

    extern void cmd_parser(int, char **);
    extern void terminate(int);
    extern void tls_log_func(int, const char *);
    extern void tls_audit_log_func(void *, const char *);
    extern void client_free(void *);
    extern const unsigned char gl_array_list_implementation;
    extern gl_list_t gl_list_create_empty(const void *, void *, void *,
                                          void (*)(void *), int);

    extern int gnutls_global_init(void);
    extern void gnutls_global_set_log_function(void (*)(int, const char *));
    extern void gnutls_global_set_audit_log_function(void (*)(void *, const char *));
    extern void gnutls_global_set_log_level(int);
    extern const char *gnutls_strerror(int);
    extern const char *safe_gnutls_strerror(int);

    extern int gnutls_certificate_allocate_credentials(gnutls_certificate_credentials_t *);
    extern int gnutls_certificate_set_x509_trust_file(gnutls_certificate_credentials_t,
                                                       const char *, int);
    extern int gnutls_certificate_set_x509_crl_file(gnutls_certificate_credentials_t,
                                                     const char *, int);
    extern int gnutls_certificate_set_x509_key_file(gnutls_certificate_credentials_t,
                                                     const char *, const char *, int);
    extern int gnutls_certificate_set_rawpk_key_file(gnutls_certificate_credentials_t,
                                                      const char *, const char *, int, ...);
    extern void gnutls_certificate_set_flags(gnutls_certificate_credentials_t, unsigned int);
    extern int gnutls_certificate_set_ocsp_status_request_file(
        gnutls_certificate_credentials_t, const char *, unsigned int);
    extern int gnutls_certificate_set_known_dh_params(gnutls_certificate_credentials_t, int);
    extern void gnutls_certificate_set_params_function(gnutls_certificate_credentials_t,
                                                        void *);

    extern int gnutls_srp_allocate_server_credentials(gnutls_srp_server_credentials_t *);
    extern int gnutls_srp_set_server_credentials_file(gnutls_srp_server_credentials_t,
                                                       const char *, const char *);
    extern int gnutls_psk_allocate_server_credentials(gnutls_psk_server_credentials_t *);
    extern int gnutls_psk_set_server_credentials_file(gnutls_psk_server_credentials_t,
                                                       const char *);
    extern int gnutls_psk_set_server_credentials_hint(gnutls_psk_server_credentials_t,
                                                       const char *);
    extern int gnutls_psk_set_server_known_dh_params(gnutls_psk_server_credentials_t, int);
    extern void gnutls_psk_set_server_params_function(gnutls_psk_server_credentials_t,
                                                       void *);
    extern int gnutls_anon_allocate_server_credentials(gnutls_anon_server_credentials_t *);
    extern int gnutls_anon_set_server_known_dh_params(gnutls_anon_server_credentials_t, int);
    extern void gnutls_anon_set_server_params_function(gnutls_anon_server_credentials_t,
                                                        void *);

    extern int gnutls_session_ticket_key_generate(gnutls_datum_t *);
    extern int gnutls_anti_replay_init(gnutls_anti_replay_t *);
    extern void gnutls_anti_replay_set_add_function(gnutls_anti_replay_t, void *);
    extern void gnutls_anti_replay_set_ptr(gnutls_anti_replay_t, void *);

    extern void load_dh_params(void);
    extern void generate_dh_params(void);
    extern int server_params_callback(void *, int, void *);
    extern void anti_replay_add(void);
    extern void tcp_server(const char *, int);
    extern void udp_server(const char *, int, int);

    extern gl_list_t client_list;
    extern gnutls_certificate_credentials_t x509_cred;
    extern gnutls_srp_server_credentials_t srp_cred;
    extern gnutls_psk_server_credentials_t psk_cred;
    extern gnutls_anon_server_credentials_t anon_cred;
    extern gnutls_anti_replay_t anti_replay;
    extern gnutls_datum_t session_ticket_key;

    extern int debug_level;
    extern int http_mode;
    extern int generate_dh;
    extern int certificate_format;
    extern int disable_tickets;
    extern int enable_early_data;
    extern char *dh_params_file;
    extern char *ca_file;
    extern char *crl_file;
    extern char *srp_password_file;
    extern char *srp_password_conf_file;
    extern char *psk_password_file;
    extern char *psk_identity_hint;
    extern unsigned int x509_cert_count;
    extern unsigned int x509_key_count;
    extern char **x509_cert_files;
    extern char **x509_key_files;
    extern unsigned int rawpk_count;
    extern unsigned int rawpk_key_count;
    extern char **rawpk_files;
    extern char **rawpk_key_files;
    extern unsigned int ocsp_response_count;
    extern char **ocsp_response_files;
    extern unsigned char udp_option;
    extern unsigned char mtu_option;
    extern unsigned char port_option;
    extern unsigned char psk_hint_option;
    extern unsigned char ignore_ocsp_errors_option;
    extern int option_mtu;
    extern int option_port;

    char server_name[256];
    int ret;
    int use_known_dh_params;
    unsigned int i;

    cmd_parser(argc, argv);

    signal(SIGHUP, SIG_IGN);
    signal(SIGTERM, terminate);
    if (signal(SIGINT, terminate) == SIG_IGN)
        signal(SIGINT, SIG_IGN);
    signal(SIGPIPE, SIG_IGN);

    client_list = gl_list_create_empty(&gl_array_list_implementation, NULL, NULL,
                                       client_free, 1);

    server_name[0] = '\0';
    if (udp_option)
        strcpy(server_name, "UDP ");
    strcat(server_name, http_mode == 1 ? "HTTP Server" : "Echo Server");

    gnutls_global_set_log_function(tls_log_func);
    gnutls_global_set_audit_log_function(tls_audit_log_func);
    gnutls_global_set_log_level(debug_level);

    ret = gnutls_global_init();
    if (ret < 0) {
        fprintf(stderr, "global_init: %s\n", gnutls_strerror(ret));
        exit(1);
    }

    if (generate_dh) {
        generate_dh_params();
        use_known_dh_params = 0;
    } else if (dh_params_file != NULL) {
        load_dh_params();
        use_known_dh_params = 0;
    } else {
        use_known_dh_params = 1;
    }

    ret = gnutls_certificate_allocate_credentials(&x509_cred);
    if (ret < 0) {
        fprintf(stderr, "memory error\n");
        exit(1);
    }

    if (ca_file != NULL) {
        ret = gnutls_certificate_set_x509_trust_file(x509_cred, ca_file,
                                                      certificate_format);
        if (ret < 0) {
            fprintf(stderr, "Error reading '%s'\n", ca_file);
            fprintf(stderr, "Error: %s\n", safe_gnutls_strerror(ret));
            exit(1);
        }
        printf("Processed %d CA certificate(s).\n", ret);
    }

    if (crl_file != NULL) {
        ret = gnutls_certificate_set_x509_crl_file(x509_cred, crl_file,
                                                    certificate_format);
        if (ret < 0) {
            fprintf(stderr, "Error reading '%s'\n", crl_file);
            fprintf(stderr, "Error: %s\n", safe_gnutls_strerror(ret));
            exit(1);
        }
        printf("Processed %d CRL(s).\n", ret);
    }

    {
        int have_key_pair = 0;

        if (x509_cert_count != 0 && x509_key_count != 0) {
            for (i = 0; i < x509_cert_count; i++) {
                ret = gnutls_certificate_set_x509_key_file(x509_cred,
                                                            x509_cert_files[i],
                                                            x509_key_files[i],
                                                            certificate_format);
                if (ret < 0) {
                    fprintf(stderr, "Error reading '%s' or '%s'\n",
                            x509_cert_files[i], x509_key_files[i]);
                    fprintf(stderr, "Error: %s\n", safe_gnutls_strerror(ret));
                    exit(1);
                }
            }
            have_key_pair = 1;
        }

        if (rawpk_count != 0 && rawpk_key_count != 0) {
            for (i = 0; i < rawpk_count; i++) {
                ret = gnutls_certificate_set_rawpk_key_file(
                    x509_cred, rawpk_files[i], rawpk_key_files[i], certificate_format,
                    NULL, 0, NULL, 0, 0);
                if (ret < 0) {
                    fprintf(stderr, "Error reading '%s' or '%s'\n",
                            rawpk_files[i], rawpk_key_files[i]);
                    fprintf(stderr, "Error: %s\n", safe_gnutls_strerror(ret));
                    exit(1);
                }
            }
            have_key_pair = 1;
        }

        if (!have_key_pair)
            fprintf(stderr,
                    "Warning: no private key and certificate pairs were set.\n");
    }

    if (ignore_ocsp_errors_option)
        gnutls_certificate_set_flags(
            x509_cred, GNUTLS_CERTIFICATE_SKIP_OCSP_RESPONSE_CHECK);

    for (i = 0; i < ocsp_response_count; i++) {
        ret = gnutls_certificate_set_ocsp_status_request_file(
            x509_cred, ocsp_response_files[i], 0);
        if (ret < 0) {
            fprintf(stderr, "Cannot set OCSP status request file: %s: %s\n",
                    ocsp_response_files[i], gnutls_strerror(ret));
            exit(1);
        }
    }

    if (use_known_dh_params) {
        ret = gnutls_certificate_set_known_dh_params(x509_cred,
                                                      GNUTLS_SEC_PARAM_MEDIUM);
    } else {
        gnutls_certificate_set_params_function(x509_cred,
                                                (void *)server_params_callback);
        ret = 0;
    }
    if (ret < 0) {
        fprintf(stderr, "Error while setting DH parameters: %s\n",
                gnutls_strerror(ret));
        exit(1);
    }

    if (srp_password_file != NULL) {
        gnutls_srp_allocate_server_credentials(&srp_cred);
        ret = gnutls_srp_set_server_credentials_file(srp_cred, srp_password_file,
                                                      srp_password_conf_file);
        if (ret < 0) {
            fprintf(stderr, "Error while setting SRP parameters\n");
            fprintf(stderr, "Error: %s\n", safe_gnutls_strerror(ret));
        }
    }

    if (psk_password_file != NULL) {
        gnutls_psk_allocate_server_credentials(&psk_cred);
        ret = gnutls_psk_set_server_credentials_file(psk_cred,
                                                      psk_password_file);
        if (ret < 0) {
            fprintf(stderr, "Error while setting PSK parameters\n");
            fprintf(stderr, "Error: %s\n", safe_gnutls_strerror(ret));
        }

        if (psk_hint_option) {
            ret = gnutls_psk_set_server_credentials_hint(psk_cred,
                                                          psk_identity_hint);
            if (ret != 0) {
                fprintf(stderr, "Error setting PSK identity hint.\n");
                fprintf(stderr, "Error: %s\n", safe_gnutls_strerror(ret));
            }
        }

        if (use_known_dh_params) {
            ret = gnutls_psk_set_server_known_dh_params(
                psk_cred, GNUTLS_SEC_PARAM_MEDIUM);
        } else {
            gnutls_psk_set_server_params_function(
                psk_cred, (void *)server_params_callback);
            ret = 0;
        }
        if (ret < 0) {
            fprintf(stderr, "Error while setting DH parameters: %s\n",
                    gnutls_strerror(ret));
            exit(1);
        }
    }

    gnutls_anon_allocate_server_credentials(&anon_cred);
    if (use_known_dh_params) {
        ret = gnutls_anon_set_server_known_dh_params(anon_cred,
                                                      GNUTLS_SEC_PARAM_MEDIUM);
    } else {
        gnutls_anon_set_server_params_function(anon_cred,
                                                (void *)server_params_callback);
        ret = 0;
    }
    if (ret < 0) {
        fprintf(stderr, "Error while setting DH parameters: %s\n",
                gnutls_strerror(ret));
        exit(1);
    }

    if (!disable_tickets)
        gnutls_session_ticket_key_generate(&session_ticket_key);

    if (enable_early_data) {
        ret = gnutls_anti_replay_init(&anti_replay);
        if (ret < 0) {
            fprintf(stderr, "Error while initializing anti-replay: %s\n",
                    gnutls_strerror(ret));
            exit(1);
        }
        gnutls_anti_replay_set_add_function(anti_replay,
                                             (void *)anti_replay_add);
        gnutls_anti_replay_set_ptr(anti_replay, NULL);
    }

    if (udp_option)
        udp_server(server_name, port_option ? option_port : 5556,
                   mtu_option ? option_mtu : 1300);
    else
        tcp_server(server_name, port_option ? option_port : 5556);

    return 0;
}


