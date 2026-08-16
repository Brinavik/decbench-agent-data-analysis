// Function: getpasswd @ 0x3b40
#include <errno.h>
#include <signal.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

struct console {
    char *tty;
    FILE *file;
    int flags;
    int fd;
    int id;
    pid_t pid;
    cc_t erase;
    cc_t kill;
    cc_t eol;
    unsigned char parity;
    struct termios tio;
    struct console *next;
};

enum {
    CON_SERIAL = 1,
    CON_NOTTY = 2,
    PARITY_ODD = 1,
    PARITY_EVEN = 2
};

extern int timeout;
extern void sub_34f0(int);
extern void sub_38d0(struct console *con);

char *getpasswd(struct console *con)
{
    static char password[128];
    static char *ptr;
    struct termios tio;
    struct sigaction action;
    char *result;
    unsigned char ch;
    int eight_bit;
    int termios_error;

    if (con->flags & CON_NOTTY)
        return password;

    tio = con->tio;
    tio.c_iflag &= ~(IUCLC | IXON | IXANY | IXOFF);
    tio.c_lflag &= ~(ISIG | ECHO | ECHOE | ECHOK | ECHONL | TOSTOP);
    termios_error = tcsetattr(con->fd, TCSAFLUSH, &tio);

    action.sa_handler = sub_34f0;
    action.sa_flags = 0;
    sigaction(SIGALRM, &action, NULL);
    if (timeout)
        alarm((unsigned int)timeout);

    password[0] = '\0';
    ptr = password;
    con->eol = '\0';

    eight_bit = 1;
    if (con->flags & CON_SERIAL)
        eight_bit = (tio.c_cflag & (PARENB | PARODD)) == 0;

    while (con->eol == '\0') {
        ssize_t count = read(con->fd, &ch, 1);

        if (count <= 0) {
            int error = errno;

            if (error == EINTR || error == EAGAIN) {
                usleep(1000);
                continue;
            }

            if (error != 0 && error != ENOENT && error != ESRCH &&
                error != EIO && error != EINVAL)
                fprintf(stderr, "sulogin: read(%s): %m\n\r", con->tty);

            result = NULL;
            goto out;
        }

        if (!eight_bit && (ch & 0x80)) {
            unsigned char value = ch & 0x7f;
            unsigned int bits = 1;
            unsigned int mask;

            for (mask = 1; mask <= 0x40; mask <<= 1) {
                if (value & mask)
                    ++bits;
            }
            con->parity |= (bits & 1) ? PARITY_ODD : PARITY_EVEN;
            ch = value;
        }

        switch (ch) {
        case '\0':
            *ptr = '\0';
            result = password;
            goto out;

        case 4:
            result = password;
            goto out;

        case '\b':
        case 0x7f:
            con->erase = ch;
            if (ptr > password)
                --ptr;
            break;

        case '\n':
        case '\r':
            *ptr = '\0';
            con->eol = ch;
            break;

        case 0x15:
            con->kill = ch;
            ptr = password;
            break;

        default:
            if ((size_t)(ptr - password) > 126) {
                fprintf(stderr, "sulogin: input overrun at %s\n\r", con->tty);
                result = NULL;
                goto out;
            }
            *ptr++ = (char)ch;
            break;
        }
    }

    result = password;

out:
    alarm(0);
    if (termios_error == 0)
        tcsetattr(con->fd, TCSAFLUSH, &con->tio);
    if (result != NULL && password[0] != '\0')
        sub_38d0(con);
    printf("\r\n");
    return result;
}


