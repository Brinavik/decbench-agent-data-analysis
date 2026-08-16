// Function: main @ 0x7e00
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

/* --- opaque GnuTLS handle types (stripped binary, reconstructed) --- */
typedef void *gnutls_certificate_credentials_t;
typedef void *gnutls_anon_server_credentials_t;
typedef void *gnutls_psk_server_credentials_t;
typedef void *gnutls_srp_server_credentials_t;
typedef void *gnutls_anti_replay_t;
typedef struct {
	unsigned char *data;
	unsigned int size;
} gnutls_datum_t;

/* --- program globals (recovered from .data/.bss references) --- */
extern gnutls_certificate_credentials_t x509_cred;        /* 0x1a070 */
extern gnutls_anon_server_credentials_t anon_cred;        /* 0x1a078 */
extern gnutls_psk_server_credentials_t  psk_cred;         /* 0x1a080 */
extern gnutls_srp_server_credentials_t  srp_cred;         /* 0x1a088 */
extern gnutls_anti_replay_t             anti_replay;      /* 0x1a0a0 */
extern gnutls_datum_t                   session_ticket_key; /* 0x1a0b0 */

extern void *priority_cache;                              /* 0x1a170 */

extern unsigned int ocsp_count;                           /* 0x1a0e0 */
extern char       **ocsp_files;                           /* 0x1a0e8 */
extern unsigned int rawpk_key_count;                      /* 0x1a0f0 */
extern unsigned int rawpk_cert_count;                     /* 0x1a0f4 */
extern char       **rawpk_certs;                          /* 0x1a0f8 */
extern char       **rawpk_keys;                           /* 0x1a100 */
extern char        *x509_crlfile;                         /* 0x1a110 */
extern char        *dhparams_file;                        /* 0x1a118 */
extern char        *x509_cafile;                          /* 0x1a120 */
extern unsigned int x509_key_count;                       /* 0x1a128 */
extern unsigned int x509_cert_count;                      /* 0x1a12c */
extern char       **x509_certfiles;                       /* 0x1a130 */
extern char       **x509_keyfiles;                        /* 0x1a138 */
extern char        *srp_passwd_conf;                      /* 0x1a140 */
extern char        *srp_passwd;                           /* 0x1a148 */
extern char        *psk_passwd;                           /* 0x1a150 */
extern int          have_session_ticket_key;              /* 0x1a17c */
extern int          enable_anti_replay;                   /* 0x1a178 */
extern int          debug_level;                          /* 0x1a184 */
extern int          x509ctype;                            /* 0x1a188 */
extern int          http_mode;                            /* 0x1a18c */
extern int          dhparams_bits;                        /* 0x1a190 */

extern char         opt_psk_hint;                         /* 0x1af04 */
extern char         opt_certificate_flags;                /* 0x1af06 */
extern char         opt_udp;                              /* 0x1aeef */
extern char         opt_have_mtu;                         /* 0x1aef0 */
extern char         opt_have_port;                        /* 0x1af07 */
extern unsigned int opt_mtu;                              /* 0x1afc8 */
extern unsigned int opt_port;                             /* 0x1afcc */
extern char        *psk_hint_string;                      /* 0x1af80 */

extern char         g_options[];                          /* 0x19520 */

/* --- internal helpers (still stripped: identified by entry address) --- */
extern void        finalize_config(void);                 /* sub_9010  */
extern void        ignore_sigpipe(void);                  /* sub_c820  */
extern void       *register_options(void *, unsigned int, unsigned int,
                                    void *, int);          /* sub_11360 */
extern void        load_dh_params_file(void);             /* sub_9330  */
extern void        generate_dh_params(void);              /* sub_a450  */
extern const char *str_error(int);                        /* sub_8700  */
extern void        run_udp_server(char *, int, int);      /* sub_bd70  */
extern void        run_tcp_server(char *, int, int);      /* sub_b0b0  */
extern void        option_callback(void);                 /* sub_8fa0  */
extern int         get_dh_params_cb(void);                /* sub_86c0  */
extern void        term_handler(int);                     /* sub_a0d0  */
extern void        tls_log_func(int, const char *);       /* sub_8a00  */
extern void        tls_audit_log_func(void *, const char *); /* sub_8a30 */
extern int         anti_replay_db_add(void *, void *, void *); /* sub_8ed0 */

/* --- GnuTLS prototypes (resolved from PLT) --- */
extern void gnutls_global_set_log_function(void (*)(int, const char *));
extern void gnutls_global_set_audit_log_function(void (*)(void *, const char *));
extern void gnutls_global_set_log_level(int);
extern int  gnutls_global_init(void);
extern const char *gnutls_strerror(int);
extern int  gnutls_certificate_allocate_credentials(gnutls_certificate_credentials_t *);
extern int  gnutls_certificate_set_x509_trust_file(gnutls_certificate_credentials_t, const char *, int);
extern int  gnutls_certificate_set_x509_crl_file(gnutls_certificate_credentials_t, const char *, int);
extern int  gnutls_certificate_set_x509_key_file(gnutls_certificate_credentials_t, const char *, const char *, int);
extern int  gnutls_certificate_set_rawpk_key_file(gnutls_certificate_credentials_t, const char *, const char *,
                                                  int, const char *, unsigned int, const char **, unsigned int,
                                                  unsigned int, unsigned int);
extern int  gnutls_certificate_set_ocsp_status_request_file(gnutls_certificate_credentials_t, const char *, unsigned int);
extern void gnutls_certificate_set_flags(gnutls_certificate_credentials_t, unsigned int);
extern int  gnutls_certificate_set_known_dh_params(gnutls_certificate_credentials_t, int);
extern void gnutls_certificate_set_params_function(gnutls_certificate_credentials_t, void *);
extern int  gnutls_srp_allocate_server_credentials(gnutls_srp_server_credentials_t *);
extern int  gnutls_srp_set_server_credentials_file(gnutls_srp_server_credentials_t, const char *, const char *);
extern int  gnutls_psk_allocate_server_credentials(gnutls_psk_server_credentials_t *);
extern int  gnutls_psk_set_server_credentials_file(gnutls_psk_server_credentials_t, const char *);
extern int  gnutls_psk_set_server_credentials_hint(gnutls_psk_server_credentials_t, const char *);
extern int  gnutls_psk_set_server_known_dh_params(gnutls_psk_server_credentials_t, int);
extern void gnutls_psk_set_server_params_function(gnutls_psk_server_credentials_t, void *);
extern int  gnutls_anon_allocate_server_credentials(gnutls_anon_server_credentials_t *);
extern int  gnutls_anon_set_server_known_dh_params(gnutls_anon_server_credentials_t, int);
extern void gnutls_anon_set_server_params_function(gnutls_anon_server_credentials_t, void *);
extern int  gnutls_anti_replay_init(gnutls_anti_replay_t *);
extern void gnutls_anti_replay_set_add_function(gnutls_anti_replay_t, void *);
extern void gnutls_anti_replay_set_ptr(gnutls_anti_replay_t, void *);
extern void gnutls_session_ticket_key_generate(gnutls_datum_t *);

int main(void)
{
	char name[256];
	int ret;
	int no_dhparams;
	unsigned int i;
	int port, mtu;

	finalize_config();

	signal(SIGHUP, SIG_IGN);
	signal(SIGTERM, term_handler);
	if (signal(SIGINT, term_handler) == SIG_IGN)
		signal(SIGINT, SIG_IGN);
	ignore_sigpipe();

	priority_cache = register_options(g_options, 0, 0, option_callback, 1);

	if (opt_udp)
		strcpy(name, "UDP ");
	else
		name[0] = '\0';
	if (http_mode == 1)
		strcat(name, "HTTP Server");
	else
		strcat(name, "Echo Server");

	gnutls_global_set_log_function(tls_log_func);
	gnutls_global_set_audit_log_function(tls_audit_log_func);
	gnutls_global_set_log_level(debug_level);

	ret = gnutls_global_init();
	if (ret < 0) {
		fprintf(stderr, "global_init: %s\n", gnutls_strerror(ret));
		exit(1);
	}

	/* Diffie-Hellman parameters: use explicit ones if configured,
	 * otherwise fall back to the well-known groups. */
	if (dhparams_bits != 0) {
		generate_dh_params();
		no_dhparams = 0;
	} else {
		no_dhparams = 1;
		if (dhparams_file != NULL) {
			load_dh_params_file();
			no_dhparams = 0;
		}
	}

	if (gnutls_certificate_allocate_credentials(&x509_cred) < 0) {
		fprintf(stderr, "memory error\n");
		exit(1);
	}

	if (x509_cafile != NULL) {
		ret = gnutls_certificate_set_x509_trust_file(x509_cred, x509_cafile, x509ctype);
		if (ret < 0) {
			fprintf(stderr, "Error reading '%s'\n", x509_cafile);
			fprintf(stderr, "Error: %s\n", str_error(ret));
			exit(1);
		}
		printf("Processed %d CA certificate(s).\n", ret);
	}

	if (x509_crlfile != NULL) {
		ret = gnutls_certificate_set_x509_crl_file(x509_cred, x509_crlfile, x509ctype);
		if (ret < 0) {
			fprintf(stderr, "Error reading '%s'\n", x509_crlfile);
			fprintf(stderr, "Error: %s\n", str_error(ret));
			exit(1);
		}
		printf("Processed %d CRL(s).\n", ret);
	}

	if (x509_cert_count != 0 && x509_key_count != 0) {
		for (i = 0; i < x509_cert_count; i++) {
			ret = gnutls_certificate_set_x509_key_file(x509_cred,
			                                           x509_certfiles[i],
			                                           x509_keyfiles[i],
			                                           x509ctype);
			if (ret < 0) {
				fprintf(stderr, "Error reading '%s' or '%s'\n",
				        x509_certfiles[i], x509_keyfiles[i]);
				fprintf(stderr, "Error: %s\n", str_error(ret));
				exit(1);
			}
		}
	}

	if (rawpk_key_count != 0 && rawpk_cert_count != 0) {
		for (i = 0; i < rawpk_cert_count; i++) {
			ret = gnutls_certificate_set_rawpk_key_file(x509_cred,
			                                            rawpk_certs[i],
			                                            rawpk_keys[i],
			                                            x509ctype,
			                                            NULL, 0, NULL, 0, 0, 0);
			if (ret < 0) {
				fprintf(stderr, "Error reading '%s' or '%s'\n",
				        rawpk_certs[i], rawpk_keys[i]);
				fprintf(stderr, "Error: %s\n", str_error(ret));
				exit(1);
			}
		}
	} else if (!(x509_cert_count != 0 && x509_key_count != 0)) {
		fprintf(stderr, "Warning: no private key and certificate pairs were set.\n");
	}

	if (opt_certificate_flags)
		gnutls_certificate_set_flags(x509_cred, 4);

	for (i = 0; i < ocsp_count; i++) {
		ret = gnutls_certificate_set_ocsp_status_request_file(x509_cred, ocsp_files[i], 0);
		if (ret < 0) {
			fprintf(stderr, "Cannot set OCSP status request file: %s: %s\n",
			        ocsp_files[i], gnutls_strerror(ret));
			exit(1);
		}
	}

	if (no_dhparams) {
		ret = gnutls_certificate_set_known_dh_params(x509_cred, 35);
		if (ret < 0) {
			fprintf(stderr, "Error while setting DH parameters: %s\n", gnutls_strerror(ret));
			exit(1);
		}
	} else {
		gnutls_certificate_set_params_function(x509_cred, get_dh_params_cb);
	}

	if (srp_passwd != NULL) {
		gnutls_srp_allocate_server_credentials(&srp_cred);
		ret = gnutls_srp_set_server_credentials_file(srp_cred, srp_passwd, srp_passwd_conf);
		if (ret < 0) {
			fprintf(stderr, "Error while setting SRP parameters\n");
			fprintf(stderr, "Error: %s\n", str_error(ret));
		}
	}

	if (psk_passwd != NULL) {
		gnutls_psk_allocate_server_credentials(&psk_cred);
		ret = gnutls_psk_set_server_credentials_file(psk_cred, psk_passwd);
		if (ret < 0) {
			fprintf(stderr, "Error while setting PSK parameters\n");
			fprintf(stderr, "Error: %s\n", str_error(ret));
		}

		if (opt_psk_hint) {
			ret = gnutls_psk_set_server_credentials_hint(psk_cred, psk_hint_string);
			if (ret != 0) {
				fprintf(stderr, "Error setting PSK identity hint.\n");
				fprintf(stderr, "Error: %s\n", str_error(ret));
			}
		}

		if (no_dhparams) {
			ret = gnutls_psk_set_server_known_dh_params(psk_cred, 35);
			if (ret < 0) {
				fprintf(stderr, "Error while setting DH parameters: %s\n", gnutls_strerror(ret));
				exit(1);
			}
			gnutls_anon_allocate_server_credentials(&anon_cred);
			ret = gnutls_anon_set_server_known_dh_params(anon_cred, 35);
			if (ret < 0) {
				fprintf(stderr, "Error while setting DH parameters: %s\n", gnutls_strerror(ret));
				exit(1);
			}
		} else {
			gnutls_psk_set_server_params_function(psk_cred, get_dh_params_cb);
			gnutls_anon_allocate_server_credentials(&anon_cred);
			gnutls_anon_set_server_params_function(anon_cred, get_dh_params_cb);
		}
	} else {
		gnutls_anon_allocate_server_credentials(&anon_cred);
		if (no_dhparams) {
			ret = gnutls_anon_set_server_known_dh_params(anon_cred, 35);
			if (ret < 0) {
				fprintf(stderr, "Error while setting DH parameters: %s\n", gnutls_strerror(ret));
				exit(1);
			}
		} else {
			gnutls_anon_set_server_params_function(anon_cred, get_dh_params_cb);
		}
	}

	if (enable_anti_replay != 0) {
		ret = gnutls_anti_replay_init(&anti_replay);
		if (ret < 0) {
			fprintf(stderr, "Error while initializing anti-replay: %s\n", gnutls_strerror(ret));
			exit(1);
		}
		gnutls_anti_replay_set_add_function(anti_replay, anti_replay_db_add);
		gnutls_anti_replay_set_ptr(anti_replay, NULL);
	}

	if (have_session_ticket_key == 0)
		gnutls_session_ticket_key_generate(&session_ticket_key);

	mtu  = opt_have_mtu  ? (int)opt_mtu  : 1300;
	port = opt_have_port ? (int)opt_port : 5556;

	if (opt_udp)
		run_udp_server(name, port, mtu);
	else
		run_tcp_server(name, port, mtu);

	return 0;
}


