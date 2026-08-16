// Function: socket_open2 @ 0xee70
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

/* ------------------------------------------------------------------ */
/* minimal GnuTLS types used by this translation unit                 */
/* ------------------------------------------------------------------ */
typedef struct gnutls_session_int *gnutls_session_t;
typedef void *gnutls_transport_ptr_t;

typedef struct {
	unsigned char *data;
	unsigned int size;
} gnutls_datum_t;

typedef ssize_t (*gnutls_push_func)(gnutls_transport_ptr_t, const void *, size_t);
typedef ssize_t (*gnutls_pull_func)(gnutls_transport_ptr_t, void *, size_t);
typedef int (*gnutls_pull_timeout_func)(gnutls_transport_ptr_t, unsigned int);

#define GNUTLS_E_PUSH_ERROR (-53)

extern int gnutls_idna_map(const char *input, unsigned ilen,
			   gnutls_datum_t *out, unsigned flags);
extern const char *gnutls_strerror(int error);
extern int gnutls_record_send_early_data(gnutls_session_t session,
					 const void *data, size_t data_size);
extern int gnutls_session_set_data(gnutls_session_t session,
				   const void *session_data,
				   size_t session_data_size);
extern void gnutls_transport_set_push_function(gnutls_session_t session,
					       gnutls_push_func push_func);
extern void gnutls_transport_set_pull_function(gnutls_session_t session,
					       gnutls_pull_func pull_func);
extern void gnutls_transport_set_pull_timeout_function(gnutls_session_t session,
						       gnutls_pull_timeout_func f);
extern void gnutls_transport_set_ptr(gnutls_session_t session,
				     gnutls_transport_ptr_t ptr);
extern void gnutls_transport_set_int2(gnutls_session_t session, int r, int s);
extern void gnutls_deinit(gnutls_session_t session);
extern void (*gnutls_free)(void *ptr);

/* ------------------------------------------------------------------ */
/* socket state kept by the caller                                    */
/* ------------------------------------------------------------------ */
typedef struct {
	int fd;				/* 0x00 */
	gnutls_session_t session;	/* 0x08 */
	int secure;			/* 0x10 */
	char *hostname;			/* 0x18 */
	char *app_proto;		/* 0x20 */
	char *ip;			/* 0x28 */
	char *service;			/* 0x30 */
	struct addrinfo *ptr;		/* 0x38 */
	struct addrinfo *addr_info;	/* 0x40 */
	int verbose;			/* 0x48 */
	struct sockaddr_storage connect_addr;	/* 0x50 */
	socklen_t connect_addrlen;	/* 0xd0 */
	FILE *server_trace;		/* 0xd8 */
	FILE *client_trace;		/* 0xe0 */
	gnutls_datum_t session_data;	/* 0xe8 (resume data)  */
	gnutls_datum_t early_data;	/* 0xf8 (early data)   */
} socket_st;

#define SOCKET_FLAG_UDP		0x01
#define SOCKET_FLAG_FASTOPEN	0x02
#define SOCKET_FLAG_STARTTLS	0x04
#define SOCKET_FLAG_RAW		0x08
#define SOCKET_FLAG_VERBOSE	0x10
#define SOCKET_FLAG_SKIP_INIT	0x20
#define SOCKET_FLAG_QUIET	0x40

/* helpers implemented elsewhere in the program */
extern void log_msg(FILE *out, const char *fmt, ...);
extern gnutls_session_t init_tls_session(const char *hostname);
extern void socket_starttls(socket_st *hd);
extern int do_handshake(socket_st *hd);
extern ssize_t wrap_push(gnutls_transport_ptr_t ptr, const void *data, size_t len);
extern ssize_t wrap_pull(gnutls_transport_ptr_t ptr, void *data, size_t len);
extern int wrap_pull_timeout(gnutls_transport_ptr_t ptr, unsigned int ms);

void socket_open2(socket_st *hd, const char *hostname, const char *service,
	      const char *app_proto, int flags, const char *msg,
	      gnutls_datum_t *rdata, gnutls_datum_t *edata,
	      FILE *server_trace, FILE *client_trace)
{
	struct addrinfo hints, *res, *ptr;
	gnutls_datum_t idn = { NULL, 0 };
	char buffer[4096];
	char portname[16] = { 0 };
	int udp = flags & SOCKET_FLAG_UDP;
	int sd = -1;
	int err;
	int ret;

	memset(hd, 0, sizeof(*hd));

	if (flags & SOCKET_FLAG_VERBOSE)
		hd->verbose = 1;

	if (rdata) {
		hd->session_data.data = rdata->data;
		hd->session_data.size = rdata->size;
	}

	if (edata) {
		hd->early_data.data = edata->data;
		hd->early_data.size = edata->size;
	}

	ret = gnutls_idna_map(hostname, strlen(hostname), &idn, 0);
	if (ret < 0) {
		fprintf(stderr, "Cannot convert %s to IDNA: %s\n", hostname,
			gnutls_strerror(ret));
		exit(1);
	}

	hd->hostname = strdup(hostname);

	if (msg)
		log_msg(stdout, "Resolving '%s:%s'...\n", (char *)idn.data,
			service);

	memset(&hints, 0, sizeof(hints));
	hints.ai_socktype = udp ? SOCK_DGRAM : SOCK_STREAM;

	err = getaddrinfo((char *)idn.data, service, &hints, &res);
	if (err != 0) {
		fprintf(stderr, "Cannot resolve %s:%s: %s\n", hostname, service,
			gai_strerror(err));
		exit(1);
	}

	for (ptr = res; ptr != NULL; ptr = ptr->ai_next) {
		sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if (sd == -1)
			continue;

		err = getnameinfo(ptr->ai_addr, ptr->ai_addrlen, buffer,
				  sizeof(buffer), portname, sizeof(portname),
				  NI_NUMERICHOST | NI_NUMERICSERV);
		if (err != 0) {
			fprintf(stderr, "getnameinfo(): %s\n",
				gai_strerror(err));
			close(sd);
			continue;
		}

		if (hints.ai_socktype == SOCK_DGRAM) {
			int optval = IP_PMTUDISC_DO;

			if (setsockopt(sd, IPPROTO_IP, IP_MTU_DISCOVER,
				       &optval, sizeof(optval)) < 0)
				perror("setsockopt(IP_DF) failed");
		}

		if ((flags & SOCKET_FLAG_FASTOPEN) &&
		    ptr->ai_socktype == SOCK_STREAM &&
		    (ptr->ai_family == AF_INET || ptr->ai_family == AF_INET6)) {
			memcpy(&hd->connect_addr, ptr->ai_addr,
			       ptr->ai_addrlen);
			hd->connect_addrlen = ptr->ai_addrlen;

			if (msg)
				log_msg(stdout, "%s '%s:%s' (TFO)...\n", msg,
					buffer, portname);
		} else {
			if (msg)
				log_msg(stdout, "%s '%s:%s'...\n", msg, buffer,
					portname);

			err = connect(sd, ptr->ai_addr, ptr->ai_addrlen);
			if (err < 0) {
				close(sd);
				continue;
			}
		}

		hd->fd = sd;

		if (flags & SOCKET_FLAG_STARTTLS) {
			hd->app_proto = (char *)app_proto;
			socket_starttls(hd);
			hd->app_proto = NULL;
		}

		if (!(flags & SOCKET_FLAG_SKIP_INIT)) {
			hd->session = init_tls_session(hostname);
			if (hd->session == NULL) {
				fprintf(stderr,
					"error initializing session\n");
				close(sd);
				exit(1);
			}
		}

		if (hd->session != NULL) {
			if (hd->early_data.data != NULL) {
				if (gnutls_record_send_early_data(
					    hd->session, hd->early_data.data,
					    hd->early_data.size) < 0) {
					fprintf(stderr,
						"error sending early data\n");
					close(sd);
					exit(1);
				}
			}

			if (hd->session_data.data != NULL)
				gnutls_session_set_data(hd->session,
							hd->session_data.data,
							hd->session_data.size);

			if (server_trace != NULL || client_trace != NULL) {
				hd->server_trace = server_trace;
				hd->client_trace = client_trace;
				gnutls_transport_set_push_function(hd->session,
								   wrap_push);
				gnutls_transport_set_pull_function(hd->session,
								   wrap_pull);
				gnutls_transport_set_pull_timeout_function(
					hd->session, wrap_pull_timeout);
				gnutls_transport_set_ptr(hd->session, hd);
			} else {
				gnutls_transport_set_int2(hd->session, sd, sd);
			}
		}

		hd->secure = !(flags & (SOCKET_FLAG_RAW | SOCKET_FLAG_SKIP_INIT));

		if (hd->secure) {
			err = do_handshake(hd);
			if (err == GNUTLS_E_PUSH_ERROR) {
				gnutls_deinit(hd->session);
				hd->session = NULL;
				close(sd);
				continue;
			}
			if (err < 0) {
				if (!(flags & SOCKET_FLAG_QUIET))
					fprintf(stderr,
						"*** handshake has failed: %s\n",
						gnutls_strerror(err));
				close(sd);
				exit(1);
			}
		}

		hd->fd = sd;
		hd->ip = strdup(buffer);
		hd->service = strdup(portname);
		hd->ptr = ptr;
		hd->addr_info = res;

		gnutls_free(hd->session_data.data);
		hd->session_data.data = NULL;
		gnutls_free(hd->early_data.data);
		hd->early_data.data = NULL;
		gnutls_free(idn.data);
		return;
	}

	if (err != 0) {
		fprintf(stderr, "Could not connect to %s:%s: %s\n", buffer,
			portname, strerror(errno));
		exit(1);
	}

	fprintf(stderr, "Could not find a supported socket\n");
	exit(1);
}


