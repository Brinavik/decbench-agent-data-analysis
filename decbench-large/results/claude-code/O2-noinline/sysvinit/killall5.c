// Function: readproc @ 0x38b0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

/* One node per process, kept in a singly linked list. Size 0x48. */
struct proc_info {
    char *exe;               /* 0x00: target of /proc/PID/exe symlink       */
    char *cmd;               /* 0x08: argv[0] taken from /proc/PID/cmdline  */
    char *cmd_base;          /* 0x10: basename of cmd (points into cmd)     */
    char *argv1;             /* 0x18: first non-option cmdline argument     */
    char *argv1_base;        /* 0x20: basename of argv1 (points into argv1) */
    char *name;              /* 0x28: comm field from /proc/PID/stat        */
    int   pid;               /* 0x30                                        */
    int   sid;               /* 0x34: session id                           */
    char  kernel_thread;     /* 0x38: set when start_code == end_code == 0  */
    struct proc_info *next;  /* 0x40                                        */
};

/* Program-wide state (lives in .bss). */
static struct proc_info *proc_list;    /* head of the process list (0x7098) */
static int opt_include_zombies;        /* option flag (0x7078)              */

/* Helpers implemented elsewhere in the program. */
extern void *xmalloc(size_t size);
extern void  message(int level, const char *fmt, ...);
/* Read one NUL-/EOF-terminated field into buf (up to size-1 bytes);
   returns the number of bytes read, or -1 when nothing was read. */
extern int   read_field(FILE *fp, char *buf, int size);

int readproc(void)
{
    DIR *dir;
    struct dirent *de;
    struct proc_info *node, *p;
    char path[4097];
    char buf[4097];
    char state[11];
    unsigned long start_code, end_code;
    int pid, n;

    if (chdir("/proc") == -1) {
        message(3, "chdir /proc failed");
        return -1;
    }

    dir = opendir(".");
    if (dir == NULL) {
        message(3, "cannot opendir(/proc)");
        return -1;
    }

    /* Discard any previously collected list. */
    for (p = proc_list; p != NULL; ) {
        node = p;
        p = p->next;
        free(node->cmd);
        free(node->argv1);
        free(node->name);
        free(node->exe);
        free(node);
    }
    proc_list = NULL;

    while ((de = readdir(dir)) != NULL) {
        char *dname = de->d_name;
        char *cur, *comm, *end, *rest, *q;
        int c, c2;
        FILE *fp;

        pid = atoi(dname);
        if (pid == 0)
            continue;

        node = xmalloc(sizeof(*node));
        memset(node, 0, sizeof(*node));

        /* /proc/PID/stat */
        snprintf(path, sizeof(path), "%s/stat", dname);
        fp = fopen(path, "r");
        if (fp == NULL) {
            free(node->cmd);
            free(node->argv1);
            free(node->name);
            free(node->exe);
            free(node);
            continue;
        }

        n = fread(buf, 1, 0x1000, fp);
        buf[n] = '\0';
        if (buf[0] == '\0') {
            message(3, "can't read from %s\n", path);
            fclose(fp);
            free(node);
            continue;
        }

        /* Extract the program name out of "PID (comm) state ...", coping with
           names that themselves contain spaces or parentheses. */
        cur = buf;
        c = (unsigned char)*cur;
        if (c != ' ') {
            do {
                c = (unsigned char)cur[1];
                cur++;
            } while (c != ' ' && c != '\0');
        }

        if (c == '\0') {
            comm = end = cur;
        } else {
            c2 = (unsigned char)cur[1];
            if (c2 == '(') {
                comm = cur + 2;
                end = strrchr(buf, ')');
                if (end == NULL) {
                    node->sid = 0;
                    message(3, "can't get program name from /proc/%s\n", path);
                    fclose(fp);
                    free(node->cmd);
                    free(node->argv1);
                    free(node->name);
                    free(node->exe);
                    free(node);
                    continue;
                }
                c = ')';
            } else if (c2 == ' ' || c2 == '\0') {
                comm = end = cur + 1;
                c = c2;
            } else {
                comm = cur + 1;
                end = cur + 1;
                do {
                    c = (unsigned char)end[1];
                    end++;
                } while (c != ' ' && c != '\0');
            }
        }

        rest = end;
        if (c != '\0') {
            rest = end + 1;
            *end = '\0';
            while (*rest == ' ')
                rest++;
        }

        node->name = xmalloc(strlen(comm) + 1);
        strcpy(node->name, comm);

        if (sscanf(rest,
                   "%10s %*d %*d %d %*d %*d %*u %*u %*u %*u %*u %*u %*u %*u "
                   "%*d %*d %*d %*d %*d %*d %*u %*u %*d %*u %lu %lu",
                   state, &node->sid, &start_code, &end_code) != 4) {
            node->sid = 0;
            message(3, "can't read sid from %s\n", path);
            fclose(fp);
            free(node->cmd);
            free(node->argv1);
            free(node->name);
            free(node->exe);
            free(node);
            continue;
        }
        if ((start_code | end_code) == 0)
            node->kernel_thread = 1;

        fclose(fp);

        /* Skip zombies unless explicitly requested. */
        if (opt_include_zombies == 0 && strchr(state, 'Z') != NULL) {
            free(node->cmd);
            free(node->argv1);
            free(node->name);
            free(node->exe);
            free(node);
            continue;
        }

        /* /proc/PID/cmdline */
        snprintf(path, sizeof(path), "%s/cmdline", dname);
        fp = fopen(path, "r");
        if (fp == NULL) {
            free(node->cmd);
            free(node->argv1);
            free(node->name);
            free(node->exe);
            free(node);
            continue;
        }

        n = read_field(fp, buf, sizeof(buf));
        if (buf[0] != '\0') {
            node->cmd = xmalloc(n + 1);
            strcpy(node->cmd, buf);
            q = strrchr(node->cmd, '/');
            node->cmd_base = q ? q + 1 : node->cmd;
        }

        /* Skip leading options; the first real argument is the script name. */
        while ((n = read_field(fp, buf, sizeof(buf))) != -1 && buf[0] == '-')
            continue;
        if (buf[0] != '\0') {
            node->argv1 = xmalloc(n + 1);
            strcpy(node->argv1, buf);
            q = strrchr(node->argv1, '/');
            node->argv1_base = q ? q + 1 : node->argv1;
        }
        fclose(fp);

        /* /proc/PID/exe */
        snprintf(path, sizeof(path), "/proc/%s/exe", dname);
        node->exe = xmalloc(4096);
        if (readlink(path, node->exe, 4096) == -1)
            node->exe = NULL;

        node->next = proc_list;
        proc_list = node;
        node->pid = pid;
    }

    closedir(dir);
    return 0;
}


