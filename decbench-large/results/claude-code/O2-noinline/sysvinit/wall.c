// Function: wall @ 0x2d50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>
#include <setjmp.h>
#include <utmp.h>

#ifndef _PATH_DEV
#define _PATH_DEV "/dev/"
#endif

#ifndef UT_LINESIZE
#define UT_LINESIZE 32
#endif

/* Helpers implemented elsewhere in the program. */
extern void get_who_where(char **whom, char **where);   /* sub_2bf0 */
extern int  check_dev(const char *path);                /* sub_2a30 */
extern int  write_mbuf(const char *msg, FILE *fp);      /* sub_2b40 */
extern void timeout_handler(int sig);                   /* sub_2a10 */

/* Shared with timeout_handler(), which siglongjmp()s back here. */
extern sigjmp_buf jmp_env;

void wall(char *mbuf, int remote)
{
	char device[strlen(_PATH_DEV) + UT_LINESIZE + 1];
	char hostname[65];
	char lbuf[256];
	char *whom, *where, *date, *cp;
	struct utmp *ut;
	struct sigaction sa;
	time_t now;
	FILE *fp;
	int fd;

	get_who_where(&whom, &where);

	if (gethostname(hostname, sizeof(hostname)) != 0)
		strcpy(hostname, "[unknown]");

	time(&now);
	date = ctime(&now);
	for (cp = date; *cp != '\0' && *cp != '\n'; cp++)
		;
	*cp = '\0';

	if (remote)
		snprintf(lbuf, sizeof(lbuf),
			 "\r\nRemote broadcast message (%s):\r\n\r\n", date);
	else
		snprintf(lbuf, sizeof(lbuf),
			 "\r\nBroadcast message from %s@%s %s(%s):\r\n\r\n",
			 whom, hostname, where, date);

	if (fork() != 0)
		return;

	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = timeout_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGALRM, &sa, NULL);

	setutent();
	while ((ut = getutent()) != NULL) {
		if (ut->ut_type != USER_PROCESS)
			continue;
		if (ut->ut_user[0] == '\0')
			continue;

		if (strncmp(ut->ut_line, _PATH_DEV, strlen(_PATH_DEV)) == 0) {
			device[0] = '\0';
			strncat(device, ut->ut_line,
				strlen(_PATH_DEV) + UT_LINESIZE);
		} else {
			snprintf(device, sizeof(device), "/dev/%.*s",
				 UT_LINESIZE, ut->ut_line);
		}

		if (strstr(device, "/../") != NULL)
			continue;

		fp = NULL;
		fd = -1;
		if (sigsetjmp(jmp_env, 1) == 0) {
			alarm(2);
			if (check_dev(device)) {
				fd = open(device,
					  O_WRONLY | O_NONBLOCK | O_NOCTTY);
				if (fd >= 0) {
					if (isatty(fd)) {
						fp = fdopen(fd, "w");
						if (fp != NULL) {
							fputs(lbuf, fp);
							write_mbuf(mbuf, fp);
							fflush(fp);
						}
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


