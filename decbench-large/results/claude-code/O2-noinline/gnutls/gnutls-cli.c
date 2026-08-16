// Function: send_ocsp_request @ 0x13d10
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --- minimal GnuTLS declarations needed by this function --- */

typedef struct gnutls_x509_crt_int *gnutls_x509_crt_t;

typedef struct {
	unsigned char *data;
	unsigned int size;
} gnutls_datum_t;

/* opaque socket handle used by the helper routines below */
typedef struct {
	int fd;
	char *hostname;
	char *service;
	int secure;
	char _reserved[240];
} socket_st;

#define GNUTLS_IA_OCSP_URI        10006    /* 0x2716 */
#define GNUTLS_E_UNKNOWN_ALGORITHM (-105)

#define MAX_BUF 4096

extern int gnutls_x509_crt_get_authority_info_access(gnutls_x509_crt_t crt,
						     unsigned int seq, int what,
						     gnutls_datum_t *data,
						     unsigned int *critical);
extern const char *gnutls_strerror(int error);
extern void (*gnutls_free)(void *ptr);

/* local helpers (defined elsewhere in this translation unit) */
extern void sockets_init(void);
extern char *get_hostname(const char *url, unsigned int *port, char **path);
extern void generate_request(gnutls_x509_crt_t cert, gnutls_x509_crt_t issuer,
			     gnutls_datum_t *req, gnutls_datum_t *nonce);
extern void socket_open2(socket_st *hd, const char *hostname,
			 const char *service, const char *app_proto, int flags,
			 const char *msg, void *a, int b, int c, int d);
extern void socket_send(const socket_st *hd, const void *buf, int len);
extern int socket_recv(const socket_st *hd, void *buf, int len);
extern void socket_bye(socket_st *hd, unsigned int how);
extern void append(int size, gnutls_datum_t *d);

/* shared receive buffer; also read back by append() */
static char buffer[MAX_BUF + 1];

int send_ocsp_request(const char *server, gnutls_x509_crt_t cert,
	      gnutls_x509_crt_t issuer, gnutls_datum_t *data,
	      gnutls_datum_t *nonce)
{
	gnutls_datum_t ud = { NULL, 0 };
	gnutls_datum_t req = { NULL, 0 };
	char *url = (char *) server;
	char headers[1024];
	char service[16];
	char *hostname;
	char *path;
	unsigned int port;
	unsigned char *p;
	int ret;
	socket_st hd;

	sockets_init();

	if (url == NULL) {
		gnutls_datum_t d;
		unsigned int i;

		/* try to read the OCSP URI from the certificate */
		for (i = 0;; i++) {
			ret = gnutls_x509_crt_get_authority_info_access(
				cert, i, GNUTLS_IA_OCSP_URI, &d, NULL);
			if (ret == GNUTLS_E_UNKNOWN_ALGORITHM)
				continue;
			break;
		}

		if (ret < 0) {
			/* fall back to the issuer certificate */
			for (i = 0;; i++) {
				ret = gnutls_x509_crt_get_authority_info_access(
					issuer, i, GNUTLS_IA_OCSP_URI, &d, NULL);
				if (ret == GNUTLS_E_UNKNOWN_ALGORITHM)
					continue;
				break;
			}

			if (ret < 0) {
				fprintf(stderr,
					"*** Cannot find OCSP server URI in certificate: %s\n",
					gnutls_strerror(ret));
				return ret;
			}
		}

		url = malloc(d.size + 1);
		if (url == NULL)
			return -1;
		memcpy(url, d.data, d.size);
		url[d.size] = 0;
		gnutls_free(d.data);
	}

	hostname = get_hostname(url, &port, &path);

	if (port != 0)
		snprintf(service, sizeof(service), "%u", port);
	else
		strcpy(service, "80");

	fprintf(stderr, "Connecting to OCSP server: %s...\n", hostname);

	generate_request(cert, issuer, &req, nonce);

	snprintf(headers, sizeof(headers),
		 "POST /%s HTTP/1.0\r\n"
		 "Host: %s\r\n"
		 "Accept: */*\r\n"
		 "Content-Type: application/ocsp-request\r\n"
		 "Content-Length: %u\r\n"
		 "Connection: close\r\n\r\n",
		 path, hostname, req.size);

	socket_open2(&hd, hostname, service, NULL, 40, "Connecting to",
		     NULL, 0, 0, 0);

	socket_send(&hd, headers, strlen(headers));
	socket_send(&hd, req.data, req.size);

	gnutls_free(req.data);
	req.data = NULL;

	do {
		ret = socket_recv(&hd, buffer, sizeof(buffer));
		if (ret > 0)
			append(ret, &ud);
	} while (ret > 0);

	if (ret < 0 || ud.size == 0) {
		perror("recv");
		ret = -1;
		goto cleanup;
	}

	socket_bye(&hd, 0);

	p = memmem(ud.data, ud.size, "\r\n\r\n", 4);
	if (p == NULL) {
		fprintf(stderr, "Cannot interpret HTTP response\n");
		ret = -1;
		goto cleanup;
	}

	p += 4;
	data->size = ud.size - (p - ud.data);
	data->data = malloc(data->size);
	if (data->data == NULL) {
		perror("recv");
		ret = -1;
		goto cleanup;
	}
	memcpy(data->data, p, data->size);
	ret = 0;

cleanup:
	free(ud.data);
	if (url != server)
		free(url);

	return ret;
}


