// Function: main @ 0x2720
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <termios.h>

#define MAX_CONSOLES 16
#define LOGFILE      "/var/log/boot"
#define VERSION      "3.05"
#define RINGSIZE     0x8000

struct real_cons {
	char	name[1024];
	int	fd;
};

/* 32 KB circular buffer shared with writelog(). */
extern char	ringbuf[RINGSIZE];
extern char	*inptr;		/* where the next read() stores data   */
extern char	*outptr;	/* where writelog() takes data from    */
extern char	*endptr;	/* ringbuf + sizeof(ringbuf)           */

extern int	syncalot;	/* -s : fdatasync() the logfile        */
extern int	createlogfile;	/* -c : create logfile if absent       */
extern int	didnl;		/* last logged line ended in a newline */
extern volatile int got_signal;	/* set by handler() and on fatal error */

extern void	usage(void);
extern void	handler(int sig);
extern int	consolenames(struct real_cons *cons, int max);
extern int	openfd(const char *name);
extern int	getpty(int *master, int *slave, char *name);
extern int	reopen(int sfd, int fd, const char *name, int err);
extern void	writelog(FILE *fp, char *ptr, int len, int print);

int main(int argc, char **argv)
{
	struct real_cons	cons[MAX_CONSOLES];
	struct timeval		tv;
	fd_set			fds;
	FILE			*fp;
	char			buf[1024];
	char			*logfile = LOGFILE;
	char			*pidfile = NULL;
	char			*p, *oldptr;
	int			master, slave, fd;
	int			consoles, working;
	int			rotate = 0, dontfork = 0, printbuf = 0;
	int			i, n, w, len, pid, c;

	while ((c = getopt(argc, argv, "cdesl:p:rv")) != -1) {
		switch (c) {
		case 'c':
			createlogfile = 1;
			break;
		case 'd':
			dontfork = 1;
			break;
		case 'e':
			printbuf = 1;
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
			printf("bootlogd - %s\n", VERSION);
			exit(0);
		default:
			usage();
		}
	}
	if (optind < argc)
		usage();

	/*
	 *	Catch or ignore the signals that could disturb us.
	 */
	signal(SIGTERM, handler);
	signal(SIGQUIT, handler);
	signal(SIGINT,  handler);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);

	/*
	 *	Find out the real console device(s) and open them.
	 */
	consoles = consolenames(cons, MAX_CONSOLES);
	if (consoles <= 0)
		return 1;

	working = consoles;
	for (i = 0; i < consoles; i++) {
		if (strcmp(cons[i].name, "/dev/tty0") == 0)
			strcpy(cons[i].name, "/dev/tty1");
		if (strcmp(cons[i].name, "/dev/vc/0") == 0)
			strcpy(cons[i].name, "/dev/vc/1");
		if ((cons[i].fd = openfd(cons[i].name)) < 0) {
			fprintf(stderr, "bootlogd: %s: %s\n",
				cons[i].name, strerror(errno));
			working--;
		}
	}
	if (working == 0)
		return 1;

	/*
	 *	Grab a pseudo tty and redirect all console output to it,
	 *	so that we can read the console output on the master side.
	 */
	buf[0] = 0;
	master = slave = -1;
	if (getpty(&master, &slave, buf) < 0) {
		fprintf(stderr, "bootlogd: cannot allocate pseudo tty: %s\n",
			strerror(errno));
		return 1;
	}

	ioctl(0, TIOCCONS, NULL);
	if ((fd = open("/dev/tty0", O_RDWR)) >= 0) {
		ioctl(fd, TIOCCONS, NULL);
		close(fd);
	}
	if (ioctl(slave, TIOCCONS, NULL) < 0) {
		fprintf(stderr, "bootlogd: ioctl(%s, TIOCCONS): %s\n",
			buf, strerror(errno));
		return 1;
	}

	/*
	 *	Go into the background unless asked not to.
	 */
	if (!dontfork) {
		if ((pid = fork()) == -1) {
			fprintf(stderr, "bootlogd: fork failed: %s\n",
				strerror(errno));
			exit(1);
		}
		if (pid > 0)
			exit(0);
		setsid();
	}

	/*
	 *	Write our pid to the pidfile.
	 */
	if (pidfile) {
		unlink(pidfile);
		if ((fp = fopen(pidfile, "w")) != NULL) {
			fprintf(fp, "%d\n", getpid());
			fclose(fp);
		}
	}

	/*
	 *	Main loop: copy console output to the real consoles and,
	 *	once it becomes available, to the logfile.
	 */
	fp = NULL;
	while (!got_signal) {

		FD_ZERO(&fds);
		FD_SET(master, &fds);
		tv.tv_sec = 0;
		tv.tv_usec = 500000;

		if (select(master + 1, &fds, NULL, NULL, &tv) == 1) {
			n = read(master, inptr, endptr - inptr);
			if (n >= 0) {
				/*
				 *	Echo the data to every real console.
				 */
				for (i = 0; i < consoles; i++) {
					if (cons[i].fd < 0 || n == 0)
						continue;
					p = inptr;
					len = n;
					for (;;) {
						w = write(cons[i].fd, p, len);
						if (w >= 0) {
							len -= w;
							p += w;
							if (len <= 0)
								break;
							continue;
						}
						cons[i].fd = reopen(slave,
							cons[i].fd,
							cons[i].name, errno);
						if (cons[i].fd >= 0)
							continue;
						if (--working <= 0)
							got_signal = 1;
						break;
					}
				}

				/*
				 *	Advance the ring buffer, dropping the
				 *	oldest unwritten data if we caught up.
				 */
				oldptr = inptr;
				inptr += n;
				if (oldptr < outptr && inptr > outptr)
					outptr = inptr;
				if (inptr >= endptr)
					inptr = ringbuf;
				if (outptr >= endptr)
					outptr = ringbuf;
			}
		}

		/*
		 *	Try to open the logfile as soon as it exists.
		 */
		if (fp == NULL) {
			if (access(logfile, F_OK) == 0) {
				if (rotate) {
					snprintf(buf, sizeof(buf), "%s~",
						logfile);
					rename(logfile, buf);
				}
				fp = fopen(logfile, "a");
			}
			if (fp == NULL && createlogfile)
				fp = fopen(logfile, "a");
		}

		/*
		 *	Flush pending data to the logfile.
		 */
		if (fp != NULL) {
			if (inptr >= outptr)
				len = inptr - outptr;
			else
				len = endptr - outptr;
			if (len)
				writelog(fp, outptr, len, printbuf);
		}
	}

	if (fp != NULL) {
		if (!didnl)
			fputc('\n', fp);
		fclose(fp);
	}
	close(slave);
	close(master);
	for (i = 0; i < consoles; i++)
		close(cons[i].fd);

	return 0;
}


