// Function: main @ 0x3d20
#include <assert.h>
#include <errno.h>
#include <grp.h>
#include <libintl.h>
#include <locale.h>
#include <pwd.h>
#include <shadow.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct pam_handle pam_handle_t;
struct pam_conv {
    int (*conv)(int, const void *, void *, void **);
    void *data;
};

struct login_utmp {
    unsigned char pad[76];
    char ut_host[256];
};

extern char **environ;
extern int optind;
extern FILE *stderr;
extern int misc_conv(int, const void *, void *, void **);
extern int pam_start(const char *, const char *, const struct pam_conv *, pam_handle_t **);
extern int pam_end(pam_handle_t *, int);
extern int pam_set_item(pam_handle_t *, int, const void *);
extern int pam_authenticate(pam_handle_t *, int);
extern int pam_acct_mgmt(pam_handle_t *, int);
extern int pam_chauthtok(pam_handle_t *, int);
extern int pam_open_session(pam_handle_t *, int);
extern int pam_close_session(pam_handle_t *, int);
extern int pam_setcred(pam_handle_t *, int);
extern int pam_fail_delay(pam_handle_t *, unsigned int);
extern char **pam_getenvlist(pam_handle_t *);
extern const char *pam_strerror(pam_handle_t *, int);

extern unsigned char amroot;
extern unsigned char hflg;
extern unsigned char fflg;
extern unsigned char pflg;
extern char *hostname;
extern char *username;
extern char *Prog;
extern char **newenvp;
extern pam_handle_t *pamh;
extern const struct pam_conv login_conv;
extern char login_timeout_msg[256];

extern void sanitize_env(void);
extern void initenv(void);
extern void process_flags(int, char **);
extern void init_tty(void);
extern struct login_utmp *get_current_utmp(void);
extern void addenv(const char *, const char *);
extern void get_options(void);
extern void check_flags(int, char **);
extern int getdef_num(const char *, int);
extern const char *getdef_str(const char *);
extern int getdef_bool(const char *);
extern char *xstrdup(const char *);
extern struct passwd *xgetpwnam(const char *);
extern void get_pam_user(char **);
extern const char *pam_user_for_log(const char *);
extern int hushed(const char *);
extern void chown_tty(const struct passwd *);
extern int setup_groups(const struct passwd *);
extern int change_uid(const struct passwd *);
extern void setup_env(const struct passwd *);
extern void subsystem(const struct passwd *);
extern void update_utmp(const char *, const char *, const char *, struct login_utmp *);
extern void show_login_messages(const char *);
extern int shell_exec(const char *, const char *, char *const *);
extern const char *base_name(const char *);
extern void log_set_progname(const char *);
extern void log_set_logfd(FILE *);
extern void login_timeout(int);
extern void endsgent(void);

int main(int argc, char **argv)
{
    enum {
        PAM_SUCCESS = 0,
        PAM_USER = 2,
        PAM_TTY = 3,
        PAM_RHOST = 4,
        PAM_USER_PROMPT = 9,
        PAM_MAXTRIES = 11,
        PAM_NEW_AUTHTOK_REQD = 12,
        PAM_ABORT = 26,
        PAM_ESTABLISH_CRED = 2,
        PAM_CHANGE_EXPIRED_AUTHTOK = 0x20,
        PAM_SILENT = 0x8000,
        PAM_DATA_SILENT = 0x40000000
    };
    char **saved_environ = environ;
    struct login_utmp *utent;
    struct passwd *pwd;
    const char *tty_name;
    const char *logname;
    const char *fake_shell;
    const char *old_locale;
    char *saved_locale;
    char *pam_username = NULL;
    char **pam_env;
    char tty[8192];
    char hostinfo[512];
    char hostname_buf[256];
    char prompt[256];
    unsigned int failcount;
    int timeout;
    int fail_delay;
    int retries;
    int pamret;
    int status;
    pid_t child;

    sanitize_env();
    setlocale(LC_ALL, "");
    bindtextdomain("shadow", "/usr/share/locale");
    textdomain("shadow");
    initenv();

    amroot = getuid() == 0;
    Prog = (char *)base_name(argv[0]);
    log_set_progname(Prog);
    log_set_logfd(stderr);

    if (geteuid() != 0) {
        fprintf(stderr, gettext("%s: Cannot possibly work without effective root\n"),
                Prog);
        exit(EXIT_FAILURE);
    }

    process_flags(argc, argv);
    if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO) ||
        !isatty(STDERR_FILENO))
        exit(EXIT_FAILURE);

    utent = get_current_utmp();
    if (!amroot && utent == NULL) {
        puts(gettext("No utmp entry.  You must exec \"login\" from the lowest level \"sh\""));
        exit(EXIT_FAILURE);
    }

    tty_name = ttyname(STDIN_FILENO);
    if (tty_name == NULL)
        tty_name = "UNKNOWN";
    strncpy(tty, tty_name, sizeof(tty) - 1);
    tty[sizeof(tty) - 1] = '\0';

    if (hflg)
        addenv("REMOTEHOST", hostname);

    openlog("login", LOG_PID, LOG_AUTHPRIV);
    init_tty();

    if (pflg) {
        char **ep = saved_environ;
        while (*ep != NULL)
            addenv(*ep++, NULL);
    } else {
        const char *term = getenv("TERM");
        if (term != NULL)
            addenv("TERM", term);
    }

    get_options();
    if (optind < argc)
        check_flags(argc - optind, argv + optind);

    if ((hflg && hostname != NULL && *hostname != '\0') ||
        (!hflg && utent != NULL && utent->ut_host[0] != '\0')) {
        const char *host = hflg ? hostname : utent->ut_host;
        snprintf(hostinfo, sizeof(hostinfo), " on '%.100s' from '%.200s'", tty, host);
    } else {
        snprintf(hostinfo, sizeof(hostinfo), " on '%.100s'", tty);
    }

restart_authentication:
    timeout = getdef_num("LOGIN_TIMEOUT", 60);
    snprintf(login_timeout_msg, 256,
             gettext("Login timed out after %u seconds.\n"), (unsigned int)timeout);
    signal(SIGALRM, login_timeout);
    if (timeout != 0)
        alarm((unsigned int)timeout);

    environ = newenvp;
    fail_delay = getdef_num("FAIL_DELAY", 1);
    retries = getdef_num("LOGIN_RETRIES", 3);

    pamret = pam_start("login", username, &login_conv, &pamh);
    if (pamret != PAM_SUCCESS) {
        fprintf(stderr, gettext("login: PAM Failure, aborting: %s\n"),
                pam_strerror(pamh, pamret));
        syslog(LOG_ERR, "Couldn't initialize PAM: %s", pam_strerror(pamh, pamret));
        exit(99);
    }

    pamret = pam_set_item(pamh, PAM_RHOST, hostname);
    if (pamret != PAM_SUCCESS)
        goto pam_failure;
    pamret = pam_set_item(pamh, PAM_TTY, tty);
    if (pamret != PAM_SUCCESS)
        goto pam_failure;

    pamret = pam_fail_delay(pamh, (unsigned int)(fail_delay * 1000000));
    if (pamret != PAM_SUCCESS)
        goto pam_failure;

    if (!fflg) {
        if (gethostname(hostname_buf, sizeof(hostname_buf)) != 0)
            strncpy(prompt, gettext("login: "), sizeof(prompt));
        else
            snprintf(prompt, sizeof(prompt), gettext("%s login: "), hostname_buf);

        pamret = pam_set_item(pamh, PAM_USER_PROMPT, prompt);
        if (pamret != PAM_SUCCESS)
            goto pam_failure;

        get_pam_user(&pam_username);
        if (pam_username != NULL && *pam_username == '\0') {
            pamret = pam_set_item(pamh, PAM_USER, NULL);
            if (pamret != PAM_SUCCESS)
                goto pam_failure;
        }

        failcount = 0;
        for (;;) {
            if (fail_delay != 0) {
                pamret = pam_fail_delay(pamh, (unsigned int)(fail_delay * 1000000));
                if (pamret != PAM_SUCCESS)
                    goto pam_failure;
            }

            pamret = pam_authenticate(pamh, 0);
            get_pam_user(&pam_username);
            logname = pam_user_for_log(pam_username);

            if (pamret == PAM_SUCCESS)
                break;
            if (pamret == PAM_MAXTRIES)
                goto too_many_tries;
            if (pamret == PAM_ABORT)
                goto pam_abort;

            ++failcount;
            old_locale = setlocale(LC_ALL, NULL);
            saved_locale = old_locale != NULL ? strdup(old_locale) : NULL;
            setlocale(LC_ALL, "C");
            syslog(LOG_NOTICE, "FAILED LOGIN (%u)%s FOR '%s', %s",
                   failcount, hostinfo, logname, pam_strerror(pamh, pamret));
            if (saved_locale != NULL) {
                setlocale(LC_ALL, saved_locale);
                free(saved_locale);
            }

            puts("");
            puts(gettext("Login incorrect"));
            if (failcount >= (unsigned int)retries)
                goto too_many_tries;

            pamret = pam_set_item(pamh, PAM_USER, NULL);
            if (pamret != PAM_SUCCESS)
                goto pam_failure;
        }
        alarm(0);
    }

    pamret = pam_acct_mgmt(pamh, 0);
    if (pamret == PAM_NEW_AUTHTOK_REQD)
        pamret = pam_chauthtok(pamh, PAM_CHANGE_EXPIRED_AUTHTOK);
    if (pamret != PAM_SUCCESS)
        goto pam_failure;

    get_pam_user(&pam_username);
    pamret = pam_open_session(pamh, hushed(pam_username) ? PAM_SILENT : 0);
    if (pamret != PAM_SUCCESS)
        goto pam_failure;

    get_pam_user(&pam_username);
    free(username);
    username = xstrdup(pam_username);
    logname = pam_user_for_log(username);
    pwd = xgetpwnam(username);
    if (pwd == NULL) {
        old_locale = setlocale(LC_ALL, NULL);
        saved_locale = old_locale != NULL ? strdup(old_locale) : NULL;
        setlocale(LC_ALL, "C");
        syslog(LOG_ERR, "cannot find user %s", logname);
        if (saved_locale != NULL) {
            setlocale(LC_ALL, saved_locale);
            free(saved_locale);
        }
        fprintf(stderr, gettext("Cannot find user (%s)\n"), username);
        exit(EXIT_FAILURE);
    }

    if (setup_groups(pwd) != 0)
        exit(EXIT_FAILURE);

    pamret = pam_setcred(pamh, PAM_ESTABLISH_CRED);
    if (pamret != PAM_SUCCESS)
        goto pam_failure;

    assert(NULL != username);
    alarm(0);

    if (getenv("IFS") != NULL)
        addenv("IFS= \t", NULL);

    if (pwd->pw_shell[0] == '*') {
        ++pwd->pw_shell;
        subsystem(pwd);
        endpwent();
        endgrent();
        endspent();
        endsgent();
        goto restart_authentication;
    }

    chown_tty(pwd);
    signal(SIGINT, SIG_IGN);
    child = fork();
    if (child < 0) {
        fprintf(stderr, gettext("%s: failure forking: %s\n"),
                Prog, strerror(errno));
        goto close_session;
    }
    if (child > 0) {
        wait(NULL);
        goto close_session;
    }

    if (getppid() == 1) {
        setsid();
        if (ioctl(STDIN_FILENO, TIOCSCTTY, 1) != 0)
            fprintf(stderr, gettext("TIOCSCTTY failed on %s\n"), tty);
    }

    update_utmp(username, tty, hostname, utent);
    endpwent();
    endgrent();
    endspent();
    endsgent();

    if (change_uid(pwd) != 0)
        exit(EXIT_FAILURE);
    setup_env(pwd);

    pam_env = pam_getenvlist(pamh);
    if (pam_env != NULL) {
        char **ep = pam_env;
        while (*ep != NULL)
            addenv(*ep++, NULL);
    }
    pam_end(pamh, PAM_DATA_SILENT);

    setlocale(LC_ALL, "");
    bindtextdomain("shadow", "/usr/share/locale");
    textdomain("shadow");

    if (hushed(username))
        addenv("HUSHLOGIN=TRUE", NULL);
    else
        addenv("HUSHLOGIN=FALSE", NULL);

    show_login_messages(tty);
    signal(SIGQUIT, SIG_DFL);
    signal(SIGTERM, SIG_DFL);
    signal(SIGALRM, SIG_DFL);
    signal(SIGHUP, SIG_DFL);
    signal(SIGINT, SIG_DFL);

    if (pwd->pw_uid == 0) {
        old_locale = setlocale(LC_ALL, NULL);
        saved_locale = old_locale != NULL ? strdup(old_locale) : NULL;
        setlocale(LC_ALL, "C");
        syslog(LOG_NOTICE, "ROOT LOGIN %s", hostinfo);
        if (saved_locale != NULL) {
            setlocale(LC_ALL, saved_locale);
            free(saved_locale);
        }
    } else if (getdef_bool("LOG_OK_LOGINS")) {
        old_locale = setlocale(LC_ALL, NULL);
        saved_locale = old_locale != NULL ? strdup(old_locale) : NULL;
        setlocale(LC_ALL, "C");
        syslog(LOG_INFO, "'%s' logged in %s", username, hostinfo);
        if (saved_locale != NULL) {
            setlocale(LC_ALL, saved_locale);
            free(saved_locale);
        }
    }

    closelog();
    fake_shell = getdef_str("FAKE_SHELL");
    if (fake_shell != NULL)
        status = shell_exec(fake_shell, pwd->pw_shell, newenvp);
    else
        status = shell_exec(pwd->pw_shell, NULL, newenvp);
    return status == ENOENT ? 127 : 126;

too_many_tries:
    old_locale = setlocale(LC_ALL, NULL);
    saved_locale = old_locale != NULL ? strdup(old_locale) : NULL;
    setlocale(LC_ALL, "C");
    syslog(LOG_NOTICE, "TOO MANY LOGIN TRIES (%u)%s FOR '%s'",
           failcount, hostinfo, logname);
    if (saved_locale != NULL) {
        setlocale(LC_ALL, saved_locale);
        free(saved_locale);
    }
    fprintf(stderr, gettext("Maximum number of tries exceeded (%u)\n"), failcount);
    goto close_session;

pam_abort:
    fputs(gettext("login: abort requested by PAM\n"), stderr);
    syslog(LOG_ERR, "PAM_ABORT returned from pam_authenticate()");
    pamret = pam_close_session(pamh, 0);
    pam_end(pamh, pamret);
    exit(99);

pam_failure:
    fprintf(stderr, "\n%s\n", pam_strerror(pamh, pamret));
    old_locale = setlocale(LC_ALL, NULL);
    saved_locale = old_locale != NULL ? strdup(old_locale) : NULL;
    setlocale(LC_ALL, "C");
    syslog(LOG_ERR, "%s", pam_strerror(pamh, pamret));
    if (saved_locale != NULL) {
        setlocale(LC_ALL, saved_locale);
        free(saved_locale);
    }
    pam_end(pamh, pamret);
    exit(EXIT_FAILURE);

close_session:
    pamret = pam_close_session(pamh, 0);
    pam_end(pamh, pamret);
    exit(EXIT_SUCCESS);
}


