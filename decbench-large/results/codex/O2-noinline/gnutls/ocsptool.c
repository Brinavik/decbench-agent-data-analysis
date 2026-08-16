// Function: socket_open2 @ 0xee70
#define _GNU_SOURCE

#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

typedef void *gnutls_session_t;

typedef struct {
    unsigned char *data;
    unsigned int size;
} gnutls_datum_t;

typedef struct socket_st {
    int fd;
    gnutls_session_t session;
    int secure;
    char *hostname;
    const char *app_proto;
    char *ip;
    char *port;
    struct addrinfo *addr;
    struct addrinfo *addr_list;
    int verbose;
    struct sockaddr_storage peer_addr;
    socklen_t peer_addrlen;
    FILE *read_log;
    FILE *write_log;
    gnutls_datum_t session_data;
    gnutls_datum_t early_data;
} socket_st;

enum {
    SOCKET_DGRAM = 0x01,
    SOCKET_FAST_OPEN = 0x02,
    SOCKET_STARTTLS = 0x04,
    SOCKET_DEFER_HANDSHAKE = 0x08,
    SOCKET_VERBOSE = 0x10,
    SOCKET_PLAIN = 0x20,
    SOCKET_QUIET_HANDSHAKE_ERROR = 0x40
};

extern int gnutls_idna_map(const char *, unsigned int, gnutls_datum_t *,
                           unsigned int);
extern const char *gnutls_strerror(int);
extern ssize_t gnutls_record_send_early_data(gnutls_session_t, const void *,
                                             size_t);
extern int gnutls_session_set_data(gnutls_session_t, const void *, size_t);
extern void gnutls_transport_set_push_function(
    gnutls_session_t, ssize_t (*)(void *, const void *, size_t));
extern void gnutls_transport_set_pull_function(
    gnutls_session_t, ssize_t (*)(void *, void *, size_t));
extern void gnutls_transport_set_pull_timeout_function(
    gnutls_session_t, int (*)(void *, unsigned int));
extern void gnutls_transport_set_ptr(gnutls_session_t, void *);
extern void gnutls_transport_set_int2(gnutls_session_t, int, int);
extern void gnutls_deinit(gnutls_session_t);
extern void (*gnutls_free)(void *);

extern ssize_t socket_send(void *, const void *, size_t);
extern ssize_t socket_recv(void *, void *, size_t);
extern int socket_recv_timeout(void *, unsigned int);
extern void socket_starttls(socket_st *);
extern gnutls_session_t init_tls_session(const char *);
extern int do_handshake(socket_st *);
extern int socket_printf(FILE *, const char *, ...);

void socket_open2(socket_st *hd, const char *hostname, const char *service,
              const char *app_proto, unsigned int flags, const char *message,
              const gnutls_datum_t *session_data,
              const gnutls_datum_t *early_data, FILE *read_log,
              FILE *write_log)
{
    struct addrinfo hints;
    struct addrinfo *addr_list;
    struct addrinfo *addr;
    gnutls_datum_t idna;
    char port[16];
    char ip[4096];
    int fd = -1;
    int ret;

    memset(hd, 0, sizeof(*hd));

    if (flags & SOCKET_VERBOSE)
        hd->verbose = 1;

    if (session_data != NULL)
        hd->session_data = *session_data;
    if (early_data != NULL)
        hd->early_data = *early_data;

    ret = gnutls_idna_map(hostname, (unsigned int)strlen(hostname), &idna, 0);
    if (ret < 0) {
        fprintf(stderr, "Cannot convert %s to IDNA: %s\n", hostname,
                gnutls_strerror(ret));
        exit(1);
    }

    hd->hostname = strdup(hostname);

    if (message != NULL)
        socket_printf(stdout, "Resolving '%s:%s'...\n", idna.data, service);

    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = 1 + (flags & SOCKET_DGRAM);

    ret = getaddrinfo((const char *)idna.data, service, &hints, &addr_list);
    if (ret != 0) {
        fprintf(stderr, "Cannot resolve %s:%s: %s\n", hostname, service,
                gai_strerror(ret));
        exit(1);
    }

    for (addr = addr_list; addr != NULL; addr = addr->ai_next) {
        fd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
        if (fd == -1)
            continue;

        ret = getnameinfo(addr->ai_addr, addr->ai_addrlen, ip, sizeof(ip),
                          port, sizeof(port), NI_NUMERICHOST | NI_NUMERICSERV);
        if (ret != 0) {
            fprintf(stderr, "getnameinfo(): %s\n", gai_strerror(ret));
            close(fd);
            continue;
        }

        if (hints.ai_socktype == SOCK_DGRAM) {
            int val = IP_PMTUDISC_DO;

            if (setsockopt(fd, IPPROTO_IP, IP_MTU_DISCOVER, &val,
                           sizeof(val)) < 0)
                perror("setsockopt(IP_DF) failed");
        }

        if ((flags & SOCKET_FAST_OPEN) &&
            addr->ai_socktype == SOCK_STREAM &&
            (addr->ai_family == AF_INET || addr->ai_family == AF_INET6)) {
            memcpy(&hd->peer_addr, addr->ai_addr, addr->ai_addrlen);
            hd->peer_addrlen = addr->ai_addrlen;

            if (message != NULL)
                socket_printf(stdout, "%s '%s:%s' (TFO)...\n", message, ip,
                              port);
        } else {
            if (message != NULL)
                socket_printf(stdout, "%s '%s:%s'...\n", message, ip, port);

            ret = connect(fd, addr->ai_addr, addr->ai_addrlen);
            if (ret < 0) {
                close(fd);
                continue;
            }
        }

        hd->fd = fd;

        if (flags & SOCKET_STARTTLS) {
            hd->app_proto = app_proto;
            socket_starttls(hd);
            hd->app_proto = NULL;
        }

        if (!(flags & SOCKET_PLAIN)) {
            hd->session = init_tls_session(hostname);
            if (hd->session == NULL) {
                fprintf(stderr, "error initializing session\n");
                close(fd);
                exit(1);
            }

            if (hd->early_data.data != NULL &&
                gnutls_record_send_early_data(hd->session,
                                              hd->early_data.data,
                                              hd->early_data.size) < 0) {
                fprintf(stderr, "error sending early data\n");
                close(fd);
                exit(1);
            }

            if (hd->session_data.data != NULL)
                gnutls_session_set_data(hd->session, hd->session_data.data,
                                        hd->session_data.size);

            if (read_log != NULL || write_log != NULL) {
                hd->read_log = read_log;
                hd->write_log = write_log;
                gnutls_transport_set_push_function(hd->session, socket_send);
                gnutls_transport_set_pull_function(hd->session, socket_recv);
                gnutls_transport_set_pull_timeout_function(
                    hd->session, socket_recv_timeout);
                gnutls_transport_set_ptr(hd->session, hd);
            } else {
                gnutls_transport_set_int2(hd->session, hd->fd, hd->fd);
            }
        }

        if (!(flags & (SOCKET_DEFER_HANDSHAKE | SOCKET_PLAIN))) {
            ret = do_handshake(hd);
            if (ret == -53) {
                gnutls_deinit(hd->session);
                hd->session = NULL;
                close(fd);
                continue;
            }
            if (ret < 0) {
                if (!(flags & SOCKET_QUIET_HANDSHAKE_ERROR))
                    fprintf(stderr, "*** handshake has failed: %s\n",
                            gnutls_strerror(ret));
                close(fd);
                exit(1);
            }
        }

        break;
    }

    if (addr == NULL) {
        if (ret != 0) {
            fprintf(stderr, "Could not connect to %s:%s: %s\n", ip, port,
                    strerror(errno));
            exit(1);
        }
        if (fd == -1) {
            fprintf(stderr, "Could not find a supported socket\n");
            exit(1);
        }
    }

    hd->fd = fd;
    hd->secure = !(flags & (SOCKET_DEFER_HANDSHAKE | SOCKET_PLAIN));
    hd->ip = strdup(ip);
    hd->port = strdup(port);
    hd->addr = addr;
    hd->addr_list = addr_list;

    gnutls_free(hd->session_data.data);
    hd->session_data.data = NULL;
    gnutls_free(hd->early_data.data);
    hd->early_data.data = NULL;
    gnutls_free(idna.data);
}


