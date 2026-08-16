// Function: wall @ 0x4540
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <signal.h>
#include <setjmp.h>
#include <utmp.h>

/* Helper routines and globals resolved from the binary (defined elsewhere). */
extern void get_sender_ident(char **login, char **tty);   /* sub_43e0: who am i */
extern int  check_dev(const char *path);                  /* sub_4220: verify char device */
extern void write_message(const char *msg, FILE *fp);     /* sub_4330: emit body, escaping ctrl chars */
extern void alarm_handler(int sig);                       /* sub_4200: siglongjmp(timeout_env, 1) */
extern sigjmp_buf timeout_env;                            /* jmp buffer used by alarm_handler */

void wall(char *msg, int remote)
{
	size_t dev_len = strlen("/dev/");
	char line[dev_len + 0x30];      /* "/dev/" + terminal name */
	char host[65];
	char header[256];
	char *login, *tty, *when;
	time_t now;
	struct utmp *ut;
	struct sigaction sa;
	int fd;
	FILE *fp;

	get_sender_ident(&login, &tty);

	if (gethostname(host, 0x41) != 0)
		strcpy(host, "[unknown]");
	host[64] = '\0';

	time(&now);
	when = ctime(&now);
	{
		char *p = when;
		while (*p != '\0' && *p != '\n')
			p++;
		*p = '\0';
	}

	if (remote)
		snprintf(header, sizeof(header),
			 "\r\nRemote broadcast message (%s):\r\n\r\n", when);
	else
		snprintf(header, sizeof(header),
			 "\r\nBroadcast message from %s@%s %s(%s):\r\n\r\n",
			 login, host, tty, when);

	if (fork() != 0)
		return;

	/* Child: deliver the message to every logged-in terminal. */
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = alarm_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGALRM, &sa, NULL);

	setutent();
	while ((ut = getutent()) != NULL) {
		if (ut->ut_type != USER_PROCESS)
			continue;
		if (ut->ut_user[0] == '\0')
			continue;

		if (strncmp(ut->ut_line, "/dev/", dev_len) == 0) {
			line[0] = '\0';
			strncat(line, ut->ut_line, dev_len + 0x20);
		} else {
			snprintf(line, dev_len + 0x21, "/dev/%.*s", 32, ut->ut_line);
		}

		fp = NULL;
		if (strstr(line, "/../") != NULL)      /* reject path traversal */
			continue;

		fd = -1;
		if (sigsetjmp(timeout_env, 1) == 0) {
			alarm(2);
			if (check_dev(line)) {
				fd = open(line, O_WRONLY | O_NONBLOCK | O_NOCTTY);
				if (fd >= 0 && isatty(fd)) {
					fp = fdopen(fd, "w");
					if (fp != NULL) {
						fputs(header, fp);
						write_message(msg, fp);
						fflush(fp);
					}
				}
			}
		}

		alarm(0);
		if (fd >= 0)
			close(fd);
		if (fp != NULL)
			fclose(fp);
	}
	endutent();
	exit(0);
}


