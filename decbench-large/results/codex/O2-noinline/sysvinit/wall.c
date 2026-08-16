// Function: wall @ 0x2d50
#include <fcntl.h>
#include <setjmp.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <utmp.h>

void wall(const char *message, int no_banner)
{
    extern void sub_2a10(int);
    extern int sub_2a30(const char *);
    extern void sub_2b40(const char *, FILE *);
    extern void sub_2bf0(char **, char **);
    extern sigjmp_buf jump_buffer_60e0;

    char *user;
    char *tty;
    char *date;
    char *end;
    char hostname[65];
    char banner[256];
    time_t now;
    struct utmp *entry;
    struct sigaction action = { .sa_handler = sub_2a10 };
    size_t path_size = strlen("/dev/") + sizeof(entry->ut_line) + 1;
    char path[path_size];

    sub_2bf0(&user, &tty);

    if (gethostname(hostname, sizeof(hostname)) != 0)
        strcpy(hostname, "[unknown]");
    hostname[sizeof(hostname) - 1] = '\0';

    time(&now);
    date = ctime(&now);
    for (end = date; *end != '\0' && *end != '\n'; ++end)
        ;
    *end = '\0';

    if (no_banner) {
        snprintf(banner, sizeof(banner),
                 "\r\nRemote broadcast message (%s):\r\n\r\n", date);
    } else {
        snprintf(banner, sizeof(banner),
                 "\r\nBroadcast message from %s@%s %s(%s):\r\n\r\n",
                 user, hostname, tty, date);
    }

    if (fork() != 0)
        return;

    sigemptyset(&action.sa_mask);
    sigaction(SIGALRM, &action, NULL);

    setutent();
    while ((entry = getutent()) != NULL) {
        FILE *stream;
        int fd;

        if (entry->ut_type != USER_PROCESS || entry->ut_user[0] == '\0')
            continue;

        if (strncmp(entry->ut_line, "/dev/", strlen("/dev/")) == 0) {
            path[0] = '\0';
            strncat(path, entry->ut_line, path_size - 1);
        } else {
            snprintf(path, path_size, "/dev/%.*s",
                     (int)sizeof(entry->ut_line), entry->ut_line);
        }

        if (strstr(path, "/../") != NULL)
            continue;

        stream = NULL;
        fd = -1;
        if (sigsetjmp(jump_buffer_60e0, 1) == 0) {
            alarm(2);
            if (sub_2a30(path)) {
                fd = open(path, O_WRONLY | O_NOCTTY | O_NONBLOCK);
                if (fd >= 0 && isatty(fd)) {
                    stream = fdopen(fd, "w");
                    if (stream != NULL) {
                        fputs(banner, stream);
                        sub_2b40(message, stream);
                        fflush(stream);
                    }
                }
            }
        }

        alarm(0);
        if (fd >= 0)
            close(fd);
        if (stream != NULL)
            fclose(stream);
    }

    endutent();
    exit(0);
}


