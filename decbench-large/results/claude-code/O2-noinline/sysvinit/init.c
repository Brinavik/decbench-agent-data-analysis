// Function: check_init_fifo @ 0x8350
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/* ---- init request protocol (as used by sysvinit) ---------------------- */

#define INIT_MAGIC		0x03091969

#define INIT_CMD_RUNLVL		1
#define INIT_CMD_POWERFAIL	2
#define INIT_CMD_POWERFAILNOW	3
#define INIT_CMD_POWEROK	4
#define INIT_CMD_SETENV		6

struct init_request {
	int	magic;		/* Magic number				*/
	int	cmd;		/* What kind of request			*/
	int	runlevel;	/* Runlevel to change to		*/
	int	sleeptime;	/* Time between TERM and KILL		*/
	union {
		struct init_request_bsd {
			char	gen_id[8];
			char	tty_id[16];
			char	host[64];
			char	term_type[16];
			int	signal;
			int	pid;
			char	exec_name[128];
			char	reserved[128];
		} bsd;
		char	data[368];
	} i;
};

/* ---- environment this routine lives in -------------------------------- */

#define INIT_FIFO	"/run/initctl"
#define PIPE_FD		10
#define L_VB		3		/* verbose logging level		*/

extern int  sltime;			/* delay between SIGTERM and SIGKILL	*/

extern void initlog(int level, const char *fmt, ...);
extern void console_init(void);
extern void do_runlevel(int runlevel);
extern void do_power_fail(int event);
extern void initcmd_setenv(char *data);

static int pipe_fd = -1;

/*
 * Read and process requests coming in on the /run/initctl FIFO.
 */
void check_init_fifo(void)
{
	struct init_request	request;
	struct stat		st, st2;
	fd_set			fds;
	struct timeval		tv;
	int			n;

	/*
	 *	Create the FIFO if it doesn't exist yet.
	 */
	if (stat(INIT_FIFO, &st2) < 0 && errno == ENOENT)
		mkfifo(INIT_FIFO, 0600);

	/*
	 *	If the FIFO is already open, make sure it still refers to
	 *	the same inode - otherwise close it and reopen below.
	 */
	if (pipe_fd >= 0) {
		fstat(pipe_fd, &st);
		if (stat(INIT_FIFO, &st2) < 0 ||
		    st.st_dev != st2.st_dev ||
		    st.st_ino != st2.st_ino) {
			close(pipe_fd);
			pipe_fd = -1;
		}
	}

	/*
	 *	(Re)open the FIFO.
	 */
	if (pipe_fd < 0) {
		if ((pipe_fd = open(INIT_FIFO, O_RDWR | O_NONBLOCK)) >= 0) {
			fstat(pipe_fd, &st);
			if (!S_ISFIFO(st.st_mode)) {
				initlog(L_VB, "%s is not a fifo", INIT_FIFO);
				close(pipe_fd);
				pipe_fd = -1;
			}
		}
		if (pipe_fd < 0) {
			/* Nothing to listen on; wait for a signal. */
			pause();
			return;
		}
		/* Keep the FIFO out of the low descriptors. */
		dup2(pipe_fd, PIPE_FD);
		close(pipe_fd);
		pipe_fd = PIPE_FD;
	}

	/*
	 *	Wait for and process requests.
	 */
	while (pipe_fd >= 0) {

		FD_ZERO(&fds);
		FD_SET(pipe_fd, &fds);
		tv.tv_sec  = 5;
		tv.tv_usec = 0;

		n = select(pipe_fd + 1, &fds, NULL, NULL, &tv);
		if (n <= 0) {
			if (n == 0 || errno == EINTR)
				return;
			continue;
		}

		n = read(pipe_fd, &request, sizeof(request));
		if (n == 0) {
			/* Writer closed the FIFO. */
			close(pipe_fd);
			pipe_fd = -1;
			return;
		}
		if (n < 0) {
			if (errno == EINTR)
				return;
			initlog(L_VB, "error reading initrequest");
			continue;
		}

		console_init();

		if (request.magic != INIT_MAGIC || n != sizeof(request)) {
			initlog(L_VB, "got bogus initrequest");
			continue;
		}

		switch (request.cmd) {
		case INIT_CMD_RUNLVL:
			sltime = request.sleeptime;
			do_runlevel(request.runlevel);
			break;
		case INIT_CMD_POWERFAIL:
			sltime = request.sleeptime;
			do_power_fail('F');
			break;
		case INIT_CMD_POWERFAILNOW:
			sltime = request.sleeptime;
			do_power_fail('L');
			break;
		case INIT_CMD_POWEROK:
			sltime = request.sleeptime;
			do_power_fail('O');
			break;
		case INIT_CMD_SETENV:
			initcmd_setenv(request.i.data);
			continue;
		default:
			initlog(L_VB, "got unimplemented initrequest.");
			continue;
		}
		return;
	}
}


