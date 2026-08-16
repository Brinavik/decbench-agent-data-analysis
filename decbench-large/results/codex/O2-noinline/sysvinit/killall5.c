// Function: readproc @ 0x38b0
#include <dirent.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <syslog.h>
#include <unistd.h>

typedef struct proc {
    char *pathname;
    char *argv0;
    char *argv0base;
    char *argv1;
    char *argv1base;
    char *statname;
    pid_t pid;
    pid_t sid;
    char kernel;
    struct proc *next;
} PROC;

int readproc(void)
{
    extern PROC *plist;
    extern int list_dz;
    extern void *xmalloc(size_t size);
    extern int readarg(FILE *fp, char *buf, int size);
    extern void nsyslog(int priority, const char *format, ...);

    static const char stat_format[] =
        "%10s %*d %*d %d %*d %*d %*u %*u %*u %*u %*u %*u %*u "
        "%*d %*d %*d %*d %*d %*d %*u %*u %*d %*u %lu %lu";
    DIR *dir;
    struct dirent *entry;
    PROC *proc;
    PROC *next;
    FILE *fp;
    char path[PATH_MAX + 1];
    char line[PATH_MAX + 1];
    char state[11];
    char *name;
    char *rest;
    char *end;
    unsigned long startcode;
    unsigned long endcode;
    size_t count;
    int arglen;
    int pid;

    if (chdir("/proc") == -1) {
        nsyslog(LOG_ERR, "chdir /proc failed");
        return -1;
    }

    dir = opendir(".");
    if (dir == NULL) {
        nsyslog(LOG_ERR, "cannot opendir(/proc)");
        return -1;
    }

    for (proc = plist; proc != NULL; proc = next) {
        next = proc->next;
        if (proc->argv0 != NULL)
            free(proc->argv0);
        if (proc->argv1 != NULL)
            free(proc->argv1);
        if (proc->statname != NULL)
            free(proc->statname);
        if (proc->pathname != NULL)
            free(proc->pathname);
        free(proc);
    }
    plist = NULL;

    while ((entry = readdir(dir)) != NULL) {
        pid = atoi(entry->d_name);
        if (pid == 0)
            continue;

        proc = xmalloc(sizeof(*proc));
        memset(proc, 0, sizeof(*proc));

        snprintf(path, sizeof(path), "%s/stat", entry->d_name);
        fp = fopen(path, "r");
        if (fp == NULL) {
            free(proc);
            continue;
        }

        count = fread(line, 1, PATH_MAX, fp);
        line[count] = '\0';
        if (line[0] == '\0') {
            nsyslog(LOG_ERR, "can't read from %s\n", path);
            fclose(fp);
            free(proc);
            continue;
        }

        name = line;
        while (*name != '\0' && *name != ' ')
            name++;

        if (*name != '\0') {
            name++;
            if (*name == '(') {
                name++;
                end = strrchr(line, ')');
                if (end == NULL) {
                    proc->sid = 0;
                    nsyslog(LOG_ERR,
                            "can't get program name from /proc/%s\n", path);
                    fclose(fp);
                    if (proc->argv0 != NULL)
                        free(proc->argv0);
                    if (proc->argv1 != NULL)
                        free(proc->argv1);
                    if (proc->statname != NULL)
                        free(proc->statname);
                    if (proc->pathname != NULL)
                        free(proc->pathname);
                    free(proc);
                    continue;
                }
            } else {
                end = name;
                while (*end != '\0' && *end != ' ')
                    end++;
            }
        } else {
            end = name;
        }

        rest = end;
        if (*end != '\0') {
            *end = '\0';
            rest = end + 1;
            while (*rest == ' ')
                rest++;
        }

        proc->statname = xmalloc(strlen(name) + 1);
        strcpy(proc->statname, name);

        startcode = 0;
        endcode = 0;
        if (sscanf(rest, stat_format, state, &proc->sid,
                   &startcode, &endcode) != 4) {
            proc->sid = 0;
            nsyslog(LOG_ERR, "can't read sid from %s\n", path);
            fclose(fp);
            if (proc->argv0 != NULL)
                free(proc->argv0);
            if (proc->argv1 != NULL)
                free(proc->argv1);
            if (proc->statname != NULL)
                free(proc->statname);
            free(proc->pathname);
            free(proc);
            continue;
        }

        if (startcode == 0 && endcode == 0)
            proc->kernel = 1;

        fclose(fp);

        if (!list_dz && strchr(state, 'Z') != NULL) {
            if (proc->argv0 != NULL)
                free(proc->argv0);
            if (proc->argv1 != NULL)
                free(proc->argv1);
            if (proc->statname != NULL)
                free(proc->statname);
            free(proc);
            continue;
        }

        snprintf(path, sizeof(path), "%s/cmdline", entry->d_name);
        fp = fopen(path, "r");
        if (fp == NULL) {
            if (proc->argv0 != NULL)
                free(proc->argv0);
            if (proc->argv1 != NULL)
                free(proc->argv1);
            if (proc->statname != NULL)
                free(proc->statname);
            if (proc->pathname != NULL)
                free(proc->pathname);
            free(proc);
            continue;
        }

        arglen = readarg(fp, line, sizeof(line));
        if (line[0] != '\0') {
            proc->argv0 = xmalloc(arglen + 1);
            strcpy(proc->argv0, line);
            proc->argv0base = strrchr(proc->argv0, '/');
            if (proc->argv0base != NULL)
                proc->argv0base++;
            else
                proc->argv0base = proc->argv0;
        }

        do {
            arglen = readarg(fp, line, sizeof(line));
            if (arglen == EOF)
                break;
        } while (line[0] == '-');

        if (line[0] != '\0') {
            proc->argv1 = xmalloc(arglen + 1);
            strcpy(proc->argv1, line);
            proc->argv1base = strrchr(proc->argv1, '/');
            if (proc->argv1base != NULL)
                proc->argv1base++;
            else
                proc->argv1base = proc->argv1;
        }

        fclose(fp);

        snprintf(path, sizeof(path), "/proc/%s/exe", entry->d_name);
        proc->pathname = xmalloc(PATH_MAX);
        if (readlink(path, proc->pathname, PATH_MAX) == -1)
            proc->pathname = NULL;

        proc->pid = pid;
        proc->next = plist;
        plist = proc;
    }

    closedir(dir);
    return 0;
}


