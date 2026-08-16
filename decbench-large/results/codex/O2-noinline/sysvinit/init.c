// Function: check_init_fifo @ 0x8350
#include <errno.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <unistd.h>

extern int pipe_fd;
extern int sltime;

extern void do_power_fail(int type);
extern void console_init(void);
extern void initlog(int level, const char *format, ...);
extern void init_setenv(char *data);
extern void fifo_new_level(int runlevel);

void check_init_fifo(void)
{
    enum {
        INIT_MAGIC = 0x03091969,
        INIT_CMD_START = 0,
        INIT_CMD_RUNLVL = 1,
        INIT_CMD_POWERFAIL = 2,
        INIT_CMD_POWERFAILNOW = 3,
        INIT_CMD_POWEROK = 4,
        INIT_CMD_BSD = 5,
        INIT_CMD_SETENV = 6,
        INIT_FIFO_FD = 10
    };
    struct init_request {
        int magic;
        int cmd;
        int runlevel;
        int sleeptime;
        char data[368];
    } request;
    const char *fifo_name = "/run/initctl";
    struct stat st;
    struct stat fst;
    struct timeval timeout;
    fd_set readfds;
    int n;

    if (stat(fifo_name, &st) < 0 && errno == ENOENT)
        mkfifo(fifo_name, 0600);

    if (pipe_fd >= 0) {
        fstat(pipe_fd, &fst);
        if (stat(fifo_name, &st) < 0 ||
            fst.st_dev != st.st_dev || fst.st_ino != st.st_ino) {
            close(pipe_fd);
            pipe_fd = -1;
        }
    }

    if (pipe_fd == -1) {
        pipe_fd = open(fifo_name, O_RDWR | O_NONBLOCK);
        if (pipe_fd < 0) {
            if (pipe_fd == -1)
                pause();
            return;
        }

        fstat(pipe_fd, &fst);
        if (!S_ISFIFO(fst.st_mode)) {
            initlog(3, "%s is not a fifo", fifo_name);
            close(pipe_fd);
            pipe_fd = -1;
            pause();
            return;
        }

        dup2(pipe_fd, INIT_FIFO_FD);
        close(pipe_fd);
        pipe_fd = INIT_FIFO_FD;
    } else if (pipe_fd < 0) {
        return;
    }

    for (;;) {
        FD_ZERO(&readfds);
        FD_SET(pipe_fd, &readfds);
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        n = select(pipe_fd + 1, &readfds, NULL, NULL, &timeout);
        if (n == 0 || (n < 0 && errno == EINTR))
            return;
        if (n < 0)
            continue;

        n = read(pipe_fd, &request, sizeof(request));
        if (n == 0) {
            close(pipe_fd);
            pipe_fd = -1;
            return;
        }
        if (n < 0) {
            if (errno == EINTR)
                return;
            initlog(3, "error reading initrequest");
            continue;
        }

        console_init();

        if (request.magic != INIT_MAGIC || n != (int)sizeof(request)) {
            initlog(3, "got bogus initrequest");
            continue;
        }

        switch (request.cmd) {
        case INIT_CMD_RUNLVL:
            sltime = request.sleeptime;
            fifo_new_level(request.runlevel);
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
            init_setenv(request.data);
            continue;

        case INIT_CMD_START:
        case INIT_CMD_BSD:
        default:
            initlog(3, "got unimplemented initrequest.");
            continue;
        }

        if (pipe_fd == -1)
            pause();
        return;
    }
}


