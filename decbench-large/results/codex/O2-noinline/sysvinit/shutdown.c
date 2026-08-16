// Function: wall @ 0x4540
#define _GNU_SOURCE
#include <fcntl.h>
#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <utmp.h>

void wall(char *message, int remote)
{
    extern void sub_43e0(char **user, char **tty);
    extern int sub_4220(const char *path);
    extern void sub_4330(const char *text, FILE *stream);
    extern void sub_4200(int signal_number);
    extern sigjmp_buf sub_8300;

    char *user;
    char *tty;
    char hostname[65];
    char header[256];
    char *date;
    char *newline;
    time_t now;
    struct utmp *ut;
    char device[sizeof(ut->ut_line) + strlen("/dev/") + 1];
    int fd;
    FILE *term;

    sub_43e0(&user, &tty);

    if (gethostname(hostname, sizeof(hostname)) != 0)
        strncpy(hostname, "[unknown]", sizeof(hostname) - 1);
    hostname[sizeof(hostname) - 1] = '\0';

    time(&now);
    date = ctime(&now);
    for (newline = date; *newline != '\0' && *newline != '\n'; ++newline)
        ;
    *newline = '\0';

    if (remote) {
        snprintf(header, sizeof(header),
                 "\r\nRemote broadcast message (%s):\r\n\r\n", date);
    } else {
        snprintf(header, sizeof(header),
                 "\r\nBroadcast message from %s@%s %s(%s):\r\n\r\n",
                 user, hostname, tty, date);
    }

    if (fork() != 0)
        return;

    struct sigaction action = { .sa_handler = sub_4200 };

    sigemptyset(&action.sa_mask);
    sigaction(SIGALRM, &action, NULL);

    setutent();
    while ((ut = getutent()) != NULL) {
        if (ut->ut_type != USER_PROCESS || ut->ut_user[0] == '\0')
            continue;

        if (strncmp(ut->ut_line, "/dev/", strlen("/dev/")) == 0) {
            device[0] = '\0';
            strncat(device, ut->ut_line, sizeof(device) - 1);
        } else {
            snprintf(device, sizeof(device), "/dev/%.*s",
                     (int)sizeof(ut->ut_line), ut->ut_line);
        }

        if (strstr(device, "/../") != NULL)
            continue;

        fd = -1;
        term = NULL;
        if (sigsetjmp(sub_8300, 1) == 0) {
            alarm(2);
            if (sub_4220(device) &&
                (fd = open(device, O_WRONLY | O_NONBLOCK | O_NOCTTY)) >= 0 &&
                isatty(fd) && (term = fdopen(fd, "w")) != NULL) {
                fputs(header, term);
                sub_4330(message, term);
                fflush(term);
            }
        }

        alarm(0);
        if (fd >= 0)
            close(fd);
        if (term != NULL)
            fclose(term);
    }

    endutent();
    exit(0);
}


