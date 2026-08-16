// Function: getpasswd @ 0x3b40
#define _GNU_SOURCE
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>

/* console flags */
#define CON_SERIAL 0x01
#define CON_NOTTY  0x02

/* control characters recognized while reading the password */
#define CH_EOF   0x04   /* Ctrl-D */
#define CH_ERASE 0x08   /* Ctrl-H / backspace */
#define CH_KILL  0x15   /* Ctrl-U */

/* parity flags accumulated in chardata.parity */
#define EVENPARITY 1
#define ODDPARITY  2

struct chardata {
	unsigned char erase;	/* +0x00 erase character seen */
	unsigned char kill;	/* +0x01 kill character seen  */
	unsigned char eol;	/* +0x02 end-of-line seen     */
	unsigned char parity;	/* +0x03 parity bits observed */
};

struct console {
	char *tty;		/* +0x00 device name          */
	char *id;		/* +0x08                      */
	int flags;		/* +0x10 CON_* flags          */
	int fd;			/* +0x14 open file descriptor */
	int pid;		/* +0x18                      */
	int reserved;		/* +0x1c                      */
	struct chardata cp;	/* +0x20                      */
	struct termios tio;	/* +0x24 saved tty state      */
};

/* SIGALRM handler (0x34f0) and post-read tty setup helper (0x38d0). */
extern void alrm_handler(int sig);
extern void sub_38d0(struct console *con);

/* login timeout in seconds; 0 disables the alarm. */
extern int timeout;

/* the collected password and a cursor into it, kept as file-scope state */
static char pass[128];
static char *ptr;

char *getpasswd(struct console *con)
{
	struct chardata *cp = &con->cp;
	struct termios tty;
	struct sigaction sa;
	int fd;
	int tc;
	int eightbit;
	unsigned char c;
	int ascval;
	int bits, mask;

	if (con->flags & CON_NOTTY)
		return pass;

	fd = con->fd;

	/* raw-ish mode: no echo, no signals, no flow control */
	tty = con->tio;
	tty.c_iflag &= ~(IUCLC | IXON | IXANY | IXOFF);
	tty.c_lflag &= ~(ISIG | ECHO | ECHOE | ECHOK | ECHONL | TOSTOP);
	tc = tcsetattr(fd, TCSAFLUSH, &tty);

	sa.sa_handler = alrm_handler;
	sa.sa_flags = 0;
	sigaction(SIGALRM, &sa, NULL);
	if (timeout)
		alarm(timeout);

	ptr = pass;
	*ptr = '\0';
	cp->eol = '\0';

	eightbit = ((con->flags & CON_SERIAL) == 0) ||
		   ((tty.c_cflag & (PARENB | PARODD)) == 0);

	while (cp->eol == '\0') {

		if (read(fd, &c, 1) < 1) {
			if (errno == EINTR || errno == EAGAIN) {
				usleep(1000);
				continue;
			}
			switch (errno) {
			case 0:
			case ENOENT:
			case ESRCH:
			case EIO:
			case EINVAL:
				break;
			default:
				fprintf(stderr, "sulogin: read(%s): %m\n\r",
					con->tty);
				break;
			}
			goto fail;
		}

		/* strip parity when the line is 7-bit */
		if (eightbit)
			ascval = c;
		else if (c & 0x80) {
			for (bits = 1, mask = 1; mask & 0x7f; mask <<= 1)
				if (c & mask)
					bits++;
			cp->parity |= (bits & 1) ? EVENPARITY : ODDPARITY;
			ascval = c & 0x7f;
		} else
			ascval = c;

		switch (ascval) {
		case 0:
			*ptr = '\0';
			/* fall through */
		case CH_EOF:
			goto quit;

		case CH_ERASE:
		case 0x7f:		/* DEL */
			cp->erase = ascval;
			if (ptr > pass)
				ptr--;
			break;

		case '\n':
		case '\r':
			*ptr = '\0';
			cp->eol = ascval;
			goto quit;

		case CH_KILL:
			cp->kill = ascval;
			if (ptr > pass)
				ptr = pass;
			break;

		default:
			if ((size_t)(ptr - pass) >= sizeof(pass) - 1) {
				fprintf(stderr,
					"sulogin: input overrun at %s\n\r",
					con->tty);
				goto fail;
			}
			*ptr++ = ascval;
			break;
		}
	}

quit:
	alarm(0);
	if (tc == 0)
		tcsetattr(fd, TCSAFLUSH, &con->tio);
	if (pass[0] != '\0')
		sub_38d0(con);
	printf("\r\n");
	return pass;

fail:
	alarm(0);
	if (tc == 0)
		tcsetattr(fd, TCSAFLUSH, &con->tio);
	printf("\r\n");
	return NULL;
}


