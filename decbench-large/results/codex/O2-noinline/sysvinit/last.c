// Function: list @ 0x3840
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <utmp.h>

int list(struct utmp *ut, time_t logout_time, int status)
{
    extern int max_host_length;
    extern int max_user_length;
    extern int show_host;
    extern char **name_list;
    extern int old_utmp_format;
    extern int full_times;
    extern int numeric_host;
    extern int resolve_host;
    extern int long_names;
    extern int host_last;
    extern int records_printed;
    extern int max_records;
    extern int sub_3740(char *, int, int, const int32_t *);

    char login_date[32];
    char logout_date[32];
    char duration[32];
    char line[UT_LINESIZE + 1];
    char host[UT_HOSTSIZE];
    char output[512];
    char **name;
    char *p;
    time_t login_time;
    time_t elapsed;
    int days;
    int hours;
    int minutes;
    int length;

    line[0] = '\0';
    strncat(line, ut->ut_line, UT_LINESIZE);

    if (strncmp(line, "ftp", 3) == 0 && isdigit(line[3]))
        line[3] = '\0';
    if (strncmp(line, "uucp", 4) == 0 && isdigit(line[4]))
        line[4] = '\0';

    if (name_list != NULL) {
        for (name = name_list; *name != NULL; name++) {
            if (strncmp(ut->ut_user, *name, UT_NAMESIZE) == 0 ||
                strcmp(line, *name) == 0 ||
                (strncmp(line, "tty", 3) == 0 &&
                 strcmp(line + 3, *name) == 0))
                break;
        }
        if (*name == NULL)
            return 0;
    }

    login_time = ut->ut_tv.tv_sec;
    strncpy(login_date, ctime(&login_time), sizeof(login_date) - 1);
    login_date[sizeof(login_date) - 1] = '\0';

    if (full_times) {
        sprintf(logout_date, "- %s", ctime(&logout_time));
    } else {
        login_date[16] = '\0';
        sprintf(logout_date, "- %s", ctime(&logout_time) + 11);
        logout_date[7] = '\0';
    }

    elapsed = logout_time - login_time;
    days = elapsed / (24 * 60 * 60);
    hours = (elapsed / (60 * 60)) % 24;
    minutes = (elapsed / 60) % 60;
    if (days != 0)
        sprintf(duration, "(%d+%02d:%02d)", days, hours, minutes);
    else
        sprintf(duration, " (%02d:%02d)", hours, minutes);

    switch (status) {
    case 1:
        strcpy(logout_date, "- crash");
        break;
    case 2:
        strcpy(logout_date, "- down ");
        break;
    case 4:
        duration[0] = '\0';
        if (full_times) {
            strcpy(logout_date, "  still logged in");
        } else {
            strcpy(logout_date, "  still");
            strcpy(duration, "logged in");
        }
        break;
    case 6:
        duration[0] = '\0';
        if (full_times) {
            strcpy(logout_date, "  gone - no logout");
        } else {
            strcpy(logout_date, "   gone");
            strcpy(duration, "- no logout");
        }
        break;
    case 7:
        logout_date[0] = '\0';
        duration[0] = '\0';
        break;
    default:
        break;
    }

    host[0] = '\0';
    if (numeric_host || resolve_host) {
        if (sub_3740(host, sizeof(host), numeric_host, ut->ut_addr_v6) < 0)
            strncat(host, ut->ut_host, sizeof(host) - 1);
    } else {
        strncat(host, ut->ut_host, sizeof(host) - 1);
    }

    if (show_host) {
        if (host_last) {
            if (long_names) {
                if (old_utmp_format)
                    length = snprintf(output, sizeof(output),
                        "%-8.8s %-12.12s %-16.16s %-7.7s %-16.16s %s\n",
                        ut->ut_user, line, login_date, logout_date,
                        duration, host);
                else
                    length = snprintf(output, sizeof(output),
                        "%-32.32s %-12.12s %-16.16s %-7.7s %-16.16s %s\n",
                        ut->ut_user, line, login_date, logout_date,
                        duration, host);
            } else if (full_times) {
                length = snprintf(output, sizeof(output),
                    "%-8.*s %-12.12s %-24.24s %-26.26s %-12.12s %s\n",
                    max_user_length, ut->ut_user, line, login_date,
                    logout_date, duration, host);
            } else {
                length = snprintf(output, sizeof(output),
                    "%-8.*s %-12.12s %-16.16s %-7.7s %-12.12s %s\n",
                    max_user_length, ut->ut_user, line, login_date,
                    logout_date, duration, host);
            }
        } else if (long_names) {
            if (old_utmp_format)
                length = snprintf(output, sizeof(output),
                    "%-8.8s %-12.12s %-16.16s %-16.16s %-7.7s %-12.12s\n",
                    ut->ut_user, line, host, login_date, logout_date,
                    duration);
            else
                length = snprintf(output, sizeof(output),
                    "%-32.32s %-12.12s %-16.16s %-16.16s %-7.7s %-12.12s\n",
                    ut->ut_user, line, host, login_date, logout_date,
                    duration);
        } else if (full_times) {
            length = snprintf(output, sizeof(output),
                "%-8.*s %-12.12s %-16.*s %-24.24s %-26.26s %-12.12s\n",
                max_user_length, ut->ut_user, line, max_host_length, host,
                login_date, logout_date, duration);
        } else {
            length = snprintf(output, sizeof(output),
                "%-8.*s %-12.12s %-16.*s %-16.16s %-7.7s %-12.12s\n",
                max_user_length, ut->ut_user, line, max_host_length, host,
                login_date, logout_date, duration);
        }
    } else if (long_names) {
        if (old_utmp_format)
            length = snprintf(output, sizeof(output),
                "%-8.8s %-12.12s %-16.16s %-7.7s %-12.12s\n",
                ut->ut_user, line, login_date, logout_date, duration);
        else
            length = snprintf(output, sizeof(output),
                "%-32.32s %-12.12s %-16.16s %-7.7s %-12.12s\n",
                ut->ut_user, line, login_date, logout_date, duration);
    } else if (full_times) {
        length = snprintf(output, sizeof(output),
            "%-8.*s %-12.12s %-24.24s %-26.26s %-12.12s\n",
            max_user_length, ut->ut_user, line, login_date, logout_date,
            duration);
    } else {
        length = snprintf(output, sizeof(output),
            "%-8.*s %-12.12s %-16.16s %-7.7s %-12.12s\n",
            max_user_length, ut->ut_user, line, login_date, logout_date,
            duration);
    }

    for (p = output; *p != '\0'; p++) {
        if ((*p < ' ' || *p > '~') && *p != '\n')
            *p = '*';
        putchar(*p);
    }
    if ((size_t)length > sizeof(output) - 1)
        putchar('\n');

    records_printed++;
    return max_records != 0 && records_printed >= max_records;
}


