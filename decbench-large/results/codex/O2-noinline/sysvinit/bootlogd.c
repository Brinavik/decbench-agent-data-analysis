// Function: main @ 0x2720
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <unistd.h>

typedef struct {
    char device[1024];
    int fd;
} console_device;

extern volatile sig_atomic_t got_signal;
extern int createlog;
extern int syncalot;
extern int didnl;
extern char ring_buffer[];
extern char *buffer_in;
extern char *buffer_out;
extern char *buffer_end;

extern void signal_handler(int signal_number);
extern int findpty(int *master, int *slave, char *name);
extern int getconsoles(console_device *consoles, int max_consoles);
extern int open_console(const char *device);
extern int reopen_console(int master, int old_fd, console_device *console,
                          int error_number);
extern void writelog(FILE *log, const char *data, int length,
                     int keep_escape_sequences);
extern void usage(void) __attribute__((noreturn));

int main(int argc, char **argv)
{
    const char *logfile = "/var/log/boot";
    const char *pidfile = NULL;
    console_device consoles[16];
    char name[1024];
    FILE *log = NULL;
    int rotate = 0;
    int dont_fork = 0;
    int keep_escape_sequences = 0;
    int console_count;
    int active_consoles;
    int master = -1;
    int slave = -1;
    int option;
    int i;

    while ((option = getopt(argc, argv, "cdesl:p:rv")) != -1) {
        switch (option) {
        case 'c':
            createlog = 1;
            break;
        case 'd':
            dont_fork = 1;
            break;
        case 'e':
            keep_escape_sequences = 1;
            break;
        case 'l':
            logfile = optarg;
            break;
        case 'p':
            pidfile = optarg;
            break;
        case 'r':
            rotate = 1;
            break;
        case 's':
            syncalot = 1;
            break;
        case 'v':
            printf("bootlogd - %s\n", "3.05");
            exit(0);
        default:
            usage();
        }
    }

    if (optind < argc)
        usage();

    signal(SIGTERM, signal_handler);
    signal(SIGQUIT, signal_handler);
    signal(SIGINT, signal_handler);
    signal(SIGTTIN, SIG_IGN);
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);

    console_count = getconsoles(consoles, 16);
    if (console_count <= 0)
        return 1;

    active_consoles = console_count;
    for (i = 0; i < console_count; i++) {
        if (strcmp(consoles[i].device, "/dev/tty0") == 0)
            strcpy(consoles[i].device, "/dev/tty1");
        if (strcmp(consoles[i].device, "/dev/vc/0") == 0)
            strcpy(consoles[i].device, "/dev/vc/1");

        consoles[i].fd = open_console(consoles[i].device);
        if (consoles[i].fd < 0) {
            fprintf(stderr, "bootlogd: %s: %s\n", consoles[i].device,
                    strerror(errno));
            active_consoles--;
        }
    }

    if (active_consoles == 0)
        return 1;

    name[0] = '\0';
    if (findpty(&master, &slave, name) < 0) {
        fprintf(stderr, "bootlogd: cannot allocate pseudo tty: %s\n",
                strerror(errno));
        return 1;
    }

    ioctl(0, TIOCCONS, 0);
    i = open("/dev/tty0", O_RDWR);
    if (i >= 0) {
        ioctl(i, TIOCCONS, 0);
        close(i);
    }

    if (ioctl(slave, TIOCCONS, 0) < 0) {
        fprintf(stderr, "bootlogd: ioctl(%s, TIOCCONS): %s\n", name,
                strerror(errno));
        return 1;
    }

    if (!dont_fork) {
        pid_t pid = fork();

        if (pid < 0) {
            fprintf(stderr, "bootlogd: fork failed: %s\n", strerror(errno));
            exit(1);
        }
        if (pid > 0)
            exit(0);
        setsid();
    }

    if (pidfile != NULL) {
        FILE *pidfp;

        unlink(pidfile);
        pidfp = fopen(pidfile, "w");
        if (pidfp != NULL) {
            fprintf(pidfp, "%d\n", (int)getpid());
            fclose(pidfp);
        }
    }

    while (!got_signal) {
        fd_set readfds;
        struct timeval timeout;
        int ready;

        timeout.tv_sec = 0;
        timeout.tv_usec = 500000;
        FD_ZERO(&readfds);
        FD_SET(master, &readfds);
        ready = select(master + 1, &readfds, NULL, NULL, &timeout);

        if (ready == 1) {
            int count = (int)read(master, buffer_out,
                                  (size_t)(buffer_end - buffer_out));

            if (count >= 0) {
                for (i = 0; i < console_count; i++) {
                    char *data;
                    int left;

                    if (consoles[i].fd < 0 || count == 0)
                        continue;

                    data = buffer_out;
                    left = count;
                    while (left > 0) {
                        int written = (int)write(consoles[i].fd, data,
                                                 (size_t)left);

                        if (written < 0) {
                            consoles[i].fd = reopen_console(
                                master, consoles[i].fd, &consoles[i], errno);
                            if (consoles[i].fd < 0) {
                                if (--active_consoles <= 0)
                                    got_signal = 1;
                                break;
                            }
                        } else {
                            data += written;
                            left -= written;
                        }
                    }
                }

                {
                    char *old_out = buffer_out;

                    buffer_out += count;
                    if (old_out < buffer_in && buffer_out > buffer_in)
                        buffer_in = buffer_out;
                    if (buffer_out >= buffer_end)
                        buffer_out = ring_buffer;
                    if (buffer_in >= buffer_end)
                        buffer_in = ring_buffer;
                }
            }
        }

        if (log == NULL) {
            if (access(logfile, F_OK) == 0) {
                if (rotate) {
                    snprintf(name, sizeof(name), "%s~", logfile);
                    rename(logfile, name);
                }
                log = fopen(logfile, "a");
            } else if (createlog) {
                log = fopen(logfile, "a");
            }
        }

        if (log != NULL) {
            int count;

            if (buffer_out < buffer_in)
                count = (int)(buffer_end - buffer_in);
            else
                count = (int)(buffer_out - buffer_in);

            if (count != 0)
                writelog(log, buffer_in, count, keep_escape_sequences);
        }
    }

    if (log != NULL) {
        if (!didnl)
            fputc('\n', log);
        fclose(log);
    }

    close(slave);
    close(master);
    for (i = 0; i < console_count; i++)
        close(consoles[i].fd);

    return 0;
}


