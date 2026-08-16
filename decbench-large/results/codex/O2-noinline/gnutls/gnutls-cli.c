// Function: send_ocsp_request @ 0x13d10
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

typedef struct gnutls_x509_crt_int *gnutls_x509_crt_t;

typedef struct {
    unsigned char *data;
    unsigned int size;
} gnutls_datum_t;

typedef struct {
    unsigned char opaque[0x108];
} socket_st;

enum {
    GNUTLS_IA_OCSP_URI = 0x2716,
    GNUTLS_E_UNKNOWN_ALGORITHM = -105,
    SOCKET_FLAG_RAW = 0x28,
    SOCKET_BUFFER_SIZE = 0x1001
};

extern int gnutls_x509_crt_get_authority_info_access(
    gnutls_x509_crt_t crt, unsigned int seq, int what,
    gnutls_datum_t *data, unsigned int *critical);
extern const char *gnutls_strerror(int error);
extern void gnutls_free(void *data);
extern void *memmem(const void *haystack, size_t haystack_len,
                    const void *needle, size_t needle_len);

extern char *sub_13ae0(const char *url, unsigned int *port,
                       const char **path);
extern void sub_13b90(size_t size, gnutls_datum_t *data);
extern void sub_13c00(gnutls_x509_crt_t crt, gnutls_x509_crt_t issuer,
                      gnutls_datum_t *request,
                      const gnutls_datum_t *nonce);
extern int sub_11250(socket_st *socket, const char *host,
                     const char *service, void *credentials,
                     unsigned int flags, const char *description, ...);
extern ssize_t sub_10f90(socket_st *socket, const void *data,
                         unsigned int size);
extern ssize_t sub_10d90(socket_st *socket, void *data,
                         unsigned int size);
extern void sub_11040(socket_st *socket, int graceful);
extern unsigned char sub_94700[];

int send_ocsp_request(const char *url, gnutls_x509_crt_t crt,
              gnutls_x509_crt_t issuer, gnutls_datum_t *response,
              const gnutls_datum_t *nonce)
{
    gnutls_datum_t uri;
    gnutls_datum_t request;
    gnutls_datum_t http_response = { NULL, 0 };
    socket_st socket;
    const char *original_url = url;
    const char *path;
    char *host;
    char *allocated_url = NULL;
    char port_string[16];
    char request_header[1024];
    unsigned int port;
    unsigned int seq;
    size_t header_size;
    unsigned char *body;
    ssize_t ret;

    signal(SIGPIPE, SIG_IGN);

    if (url == NULL) {
        seq = 0;
        do {
            ret = gnutls_x509_crt_get_authority_info_access(
                crt, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
        } while (ret == GNUTLS_E_UNKNOWN_ALGORITHM);

        if (ret < 0) {
            seq = 0;
            do {
                ret = gnutls_x509_crt_get_authority_info_access(
                    issuer, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
            } while (ret == GNUTLS_E_UNKNOWN_ALGORITHM);

            if (ret < 0) {
                fprintf(stderr,
                        "*** Cannot find OCSP server URI in certificate: %s\n",
                        gnutls_strerror((int)ret));
                return (int)ret;
            }
        }

        allocated_url = malloc((size_t)uri.size + 1);
        if (allocated_url == NULL)
            return -1;

        memcpy(allocated_url, uri.data, uri.size);
        allocated_url[uri.size] = '\0';
        gnutls_free(uri.data);
        url = allocated_url;
    }

    host = sub_13ae0(url, &port, &path);
    if (port == 0)
        strcpy(port_string, "80");
    else
        snprintf(port_string, sizeof(port_string), "%u", port);

    fprintf(stderr, "Connecting to OCSP server: %s...\n", host);

    sub_13c00(crt, issuer, &request, nonce);
    snprintf(request_header, sizeof(request_header),
             "POST /%s HTTP/1.0\r\n"
             "Host: %s\r\n"
             "Accept: */*\r\n"
             "Content-Type: application/ocsp-request\r\n"
             "Content-Length: %u\r\n"
             "Connection: close\r\n\r\n",
             path, host, request.size);
    header_size = strlen(request_header);

    sub_11250(&socket, host, port_string, NULL, SOCKET_FLAG_RAW,
              "Connecting to", NULL, NULL, NULL, NULL);
    sub_10f90(&socket, request_header, (unsigned int)header_size);
    sub_10f90(&socket, request.data, request.size);
    gnutls_free(request.data);
    request.data = NULL;

    while ((ret = sub_10d90(&socket, sub_94700, SOCKET_BUFFER_SIZE)) > 0)
        sub_13b90((size_t)ret, &http_response);

    if (ret != 0 || http_response.size == 0) {
        perror("recv");
        ret = -1;
        goto cleanup;
    }

    sub_11040(&socket, 0);

    body = memmem(http_response.data, http_response.size, "\r\n\r\n", 4);
    if (body == NULL) {
        fprintf(stderr, "Cannot interpret HTTP response\n");
        ret = -1;
        goto cleanup;
    }

    body += 4;
    response->size = http_response.size -
                     (unsigned int)(body - http_response.data);
    response->data = malloc(response->size);
    if (response->data == NULL) {
        perror("recv");
        ret = -1;
        goto cleanup;
    }

    memcpy(response->data, body, response->size);

cleanup:
    free(http_response.data);
    if (url != original_url)
        free(allocated_url);
    return (int)ret;
}


