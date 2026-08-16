








struct chardata {
 uint8_t erase;
 uint8_t kill;
 uint8_t eol;
 uint8_t parity;
};
struct console {
 char *tty;
 FILE *file;
 uint32_t flags;
 int fd, id;


 pid_t pid;
 struct chardata cp;
 struct termios tio;
 struct console *next;
};
extern struct console *consoles;
extern int detect_consoles(const char *, int);
char *Version = "@(#)sulogin 2.85-3 23-Apr-2003 miquels@cistron.nl";

static int timeout;
static int profile;
static volatile uint32_t openfd;
static volatile uint32_t *usemask;

static sighandler_t saved_sigint = 
                                   ((__sighandler_t) 0)
                                          ;
static sighandler_t saved_sigtstp = 
                                   ((__sighandler_t) 0)
                                          ;
static sighandler_t saved_sigquit = 
                                   ((__sighandler_t) 0)
                                          ;
static sighandler_t saved_sighup = 
                                   ((__sighandler_t) 0)
                                          ;

static volatile sig_atomic_t alarm_rised;
static volatile sig_atomic_t sigchild;
static
void tcinit(struct console *con)
{
 int serial, flags;
 struct termios *tio = &con->tio;
 int fd = con->fd;


 serial = 
         (*__errno_location ()) 
               = 0;


 if (tcgetattr(fd, tio) < 0) {
  con->flags |= 0x0002;
  return;
 }


 if (ioctl (fd, 
               0x5415
                       , (char*)&serial) == 0) {
  speed_t ispeed, ospeed;
  struct winsize ws;


  con->flags |= 0x0001;


  (void) tcflush(fd, 
                    2
                             );

  ispeed = cfgetispeed(tio);
  ospeed = cfgetospeed(tio);

  if (!ispeed) ispeed = 
                       (0000015)
                                   ;
  if (!ospeed) ospeed = 
                       (0000015)
                                   ;

  tio->c_iflag = tio->c_lflag = tio->c_oflag = 0;
  tio->c_cflag = 
                0000200 
                      | 
                        0000060 
                            | 
                              0002000 
                                    | (tio->c_cflag & 
                                                      0004000
                                                            );

  cfsetispeed(tio, ispeed);
  cfsetospeed(tio, ospeed);


  tio->c_line = 0;

  tio->c_cc[
           5
                ] = 0;
  tio->c_cc[
           6
               ] = 1;

  if (ioctl(fd, 
               0x5413
                         , &ws) == 0) {
   int set = 0;
   if (ws.ws_row == 0) {
    ws.ws_row = 24;
    set++;
   }
   if (ws.ws_col == 0) {
    ws.ws_col = 80;
    set++;
   }
   (void)ioctl(fd, 
                  0x5414
                            , &ws);
  }

  goto setattr;
 }
setattr:

 tcsetattr(fd, 
              0
                     , tio);


 if ((flags = fcntl(fd, 
                       3
                              , 0)) != -1)
  (void)fcntl(fd, 
                 4
                        , flags & ~
                                   04000
                                             );
}





static
void tcfinal(struct console *con)
{
 struct termios *tio = &con->tio;
 int fd = con->fd;


 
(*__errno_location ()) 
      = 0;

 if ((con->flags & 0x0001) == 0) {

  setenv("TERM", "linux", 1);



  return;
 }
 if (con->flags & 0x0002)
  return;
 setenv("TERM", "vt100", 1);

 tio->c_iflag |= (
                 0002000 
                      | 
                        0010000
                             );
 tio->c_lflag |= (
                 0000002 
                        | 
                          0000001 
                               | 
                                 0000010
                                     |
                                      0000020
                                           |
                                            0000040
                                                 |
                                                  0004000
                                                        );
 tio->c_oflag |= 
                0000001
                     ;

 tio->c_cc[
          0
               ] = 
                      ('c'&037)
                           ;
 tio->c_cc[
          1
               ] = 
                      034
                           ;
 tio->c_cc[
          2
                ] = con->cp.erase;
 tio->c_cc[
          3
               ] = con->cp.kill;
 tio->c_cc[
          4
              ] = 
                      ('d'&037)
                          ;

 tio->c_cc[
          7
               ] = 
                      '\0'
                                     ;



 tio->c_cc[
          8
                ] = 
                      ('q'&037)
                            ;
 tio->c_cc[
          9
               ] = 
                      ('s'&037)
                           ;
 tio->c_cc[
          10
               ] = 
                      ('z'&037)
                           ;
 tio->c_cc[
          11
              ] = 
                      '\0'
                                     ;

 if (con->cp.eol == 
                   (
                   'm'
                   &037)
                     ) {
  tio->c_iflag |= 
                 0000400
                      ;
  tio->c_iflag &= ~(
                   0000100
                        |
                         0000200
                              );
  tio->c_oflag |= 
                 0000004
                      ;
  tio->c_oflag &= ~(
                   0000010
                        |
                         0000040
                               );
 }

 switch (con->cp.parity) {
 default:
 case 0:
  tio->c_cflag &= ~(
                   0001000 
                          | 
                            0000400
                                  );
  tio->c_iflag &= ~(
                   0000020 
                         | 
                           0000040
                                 );
  break;
 case 1:
  tio->c_cflag |= 
                 0001000
                       ;

 case 2:
  tio->c_cflag |= 
                 0000400
                       ;
  tio->c_iflag |= (
                  0000020 
                        | 
                          0000040
                                );

 case (1 | 2):
  tio->c_cflag &= ~
                  0000060
                       ;
  tio->c_cflag |= 
                 0000040
                    ;
  break;
 }


 (void)tcsetattr(fd, 
                    0
                           , tio);
}




static

__attribute__((__noinline__))
void alrm_handler(int sig __attribute__((unused)))



{
 alarm_rised++;
}




static

__attribute__((__noinline__))
void chld_handler(int sig __attribute__((unused)))



{
 sigchild++;
}






static
int valid(const char *pass)
{
 const char *s;
 char id[5];
 size_t len;
 off_t off;

 if (pass[0] == 0) return 1;

 if (pass[0] != '$') goto check_des;




 for(s = pass+1; *s && *s != '$'; s++)
  ;
 if (*s++ != '$') return 0;
 if ((off = (off_t)(s-pass)) > 4 || off < 3) return 0;

 memset(id, '\0', sizeof(id));
 strncpy(id, pass, off);




 for(; *s && *s != '$'; s++)
  ;
 if (*s++ != '$') return 0;
 if ((off_t)(s-pass) > 16) return 0;
 len = strlen(s);




 if ((strcmp(id, "$1$") == 0) && (len < 22 || len > 24)) return 0;




 if ((strcmp(id, "$5$") == 0) && (len < 42 || len > 44)) return 0;




 if ((strcmp(id, "$6$") == 0) && (len < 85 || len > 87)) return 0;




 return 1;
check_des:


 if (strlen(pass) != 13) return 0;
 for (s = pass; *s; s++) {
  if ((*s < '0' || *s > '9') &&
      (*s < 'a' || *s > 'z') &&
      (*s < 'A' || *s > 'Z') &&
      *s != '.' && *s != '/') return 0;
 }

 return 1;
}




static
void set(char **var, char *val)
{
 if (val) *var = val;
}




static
struct passwd *getrootpwent(int try_manually)
{
 static struct passwd pwd;
 struct passwd *pw;
 struct spwd *spw;
 FILE *fp;
 static char line[256];
 static char sline[256];
 char *p;





 if ((pw = getpwnam("root")) &&
     !strcmp(pw->pw_passwd, "x") &&
     (spw = getspnam("root")))
  pw->pw_passwd = spw->sp_pwdp;
 if (pw || !try_manually) return pw;






 pwd.pw_name = "root";
 pwd.pw_passwd = "";
 pwd.pw_gecos = "Super User";
 pwd.pw_dir = "/";
 pwd.pw_shell = "";
 pwd.pw_uid = 0;
 pwd.pw_gid = 0;

 if ((fp = fopen("/etc/passwd", "r")) == 
                                   ((void *)0)
                                       ) {
  perror("/etc/passwd");
  return &pwd;
 }




 while((p = fgets(line, 256, fp)) != 
                                                ((void *)0)
                                                    ) {
  if (strncmp(line, "root:", 5) != 0)
   continue;
  p += 5;
  set(&pwd.pw_passwd, strsep(&p, ":"));
  (void)strsep(&p, ":");
  (void)strsep(&p, ":");
  set(&pwd.pw_gecos, strsep(&p, ":"));
  set(&pwd.pw_dir, strsep(&p, ":"));
  set(&pwd.pw_shell, strsep(&p, "\n"));
  p = line;
  break;
 }
 fclose(fp);





 if (p == 
         ((void *)0)
             ) {
  fprintf(
         stderr
               , "sulogin: %s: no entry for root\n\r", "/etc/passwd");
  return &pwd;
 }
 if (valid(pwd.pw_passwd)) return &pwd;





 strcpy(pwd.pw_passwd, "");
 if ((fp = fopen("/etc/shadow", "r")) == 
                                   ((void *)0)
                                       ) {
  fprintf(
         stderr
               , "sulogin: %s: root password garbled\n\r", "/etc/passwd");
  return &pwd;
 }
 while((p = fgets(sline, 256, fp)) != 
                                                 ((void *)0)
                                                     ) {
  if (strncmp(sline, "root:", 5) != 0)
   continue;
  p += 5;
  set(&pwd.pw_passwd, strsep(&p, ":"));
  break;
 }
 fclose(fp);





 if (p == 
         ((void *)0)
             ) {
  fprintf(
         stderr
               , "sulogin: %s: no entry for root\n\r", "/etc/shadow");
  strcpy(pwd.pw_passwd, "");
 }
 if (!valid(pwd.pw_passwd)) {
  fprintf(
         stderr
               , "sulogin: %s: root password garbled\n\r", "/etc/shadow");
  strcpy(pwd.pw_passwd, ""); }
 return &pwd;
}




static
void doprompt(const char *crypted, struct console *con)
{
 struct termios tty;

 if (con->flags & 0x0001) {
  tty = con->tio;




  tty.c_oflag |= (
                 0000004 
                       | 
                         0000001
                              );
  (void) tcsetattr(con->fd, 
                           1
                                    , &tty);
 }
 if (con->file == (FILE*)0) {
  if ((con->file = fdopen(con->fd, "r+")) == (FILE*)0)
   goto err;
 }






 if (crypted[0])
  fprintf(con->file, "Give root password for maintenance\n\r");
 else
  fprintf(con->file, "Press enter for maintenance");
 fprintf(con->file, "(or type Control-D to continue): ");

 fflush(con->file);
err:
 if (con->flags & 0x0001)
  (void) tcsetattr(con->fd, 
                           1
                                    , &con->tio);
}




static
void setup(struct console *con)
{
 pid_t pid, pgrp, ppgrp, ttypgrp;
 int fd;

 if (con->flags & 0x0002)
  return;
 fd = con->fd;





 pid = getpid();
 pgrp = getpgid(0);
 ppgrp = getpgid(getppid());
 ttypgrp = tcgetpgrp(fd);

 if (pgrp != ttypgrp && ppgrp != ttypgrp) {
  if (pid != getsid(0)) {
   if (pid == getpgid(0))
    setpgid(0, getpgid(getppid()));
   setsid();
  }

  signal(
        1
              , 
                ((__sighandler_t) 1)
                       );
  if (ttypgrp > 0)
   ioctl(0, 
           0x5422
                    , (char *)1);
  signal(
        1
              , saved_sighup);
  if (fd > 0) close(0);
  if (fd > 1) close(1);
  if (fd > 2) close(2);

  ioctl(fd, 
           0x540E
                    , (char *)1);
  tcsetpgrp(fd, ppgrp);
 }
 dup2(fd, 0);
 dup2(fd, 1);
 dup2(fd, 2);
 con->fd = 0;

 for (fd = 3; fd < 32; fd++) {
  if (openfd & (1<<fd)) {
   close(fd);
   openfd &= ~(1<<fd);
  }
 }
}





static
char *getpasswd(struct console *con)
{
 static char pass[128], *ptr;
 struct sigaction sa;
 struct chardata *cp;
 struct termios tty;
 char *ret = pass;
 unsigned char tc;
 char c, ascval;
 int eightbit;
 int fd;

 if (con->flags & 0x0002)
  goto out;
 fd = con->fd;
 cp = &con->cp;

 tty = con->tio;
 tty.c_iflag &= ~(
                 0001000
                      |
                       0002000
                           |
                            0010000
                                 |
                                  0004000
                                       );
 tty.c_lflag &= ~(
                 0000010
                     |
                      0000020
                           |
                            0000040
                                 |
                                  0000100
                                        |
                                         0000400
                                               |
                                                0000001
                                                    );
 tc = (tcsetattr(fd, 
                    2
                             , &tty) == 0);

 sa.
   __sigaction_handler.sa_handler 
              = alrm_handler;
 sa.sa_flags = 0;
 sigaction(
          14
                 , &sa, 
                        ((void *)0)
                            );
 if (timeout) alarm(timeout);

 ptr = &pass[0];
 cp->eol = *ptr = '\0';

 eightbit = ((con->flags & 0x0001) == 0 || (tty.c_cflag & (
                                                              0001000
                                                                    |
                                                                     0000400
                                                                           )) == 0);
 while (cp->eol == '\0') {
  if (read(fd, &c, 1) < 1) {
   if (
      (*__errno_location ()) 
            == 
               4 
                     || 
                        (*__errno_location ()) 
                              == 
                                 11
                                       ) {
    usleep(1000);
    continue;
   }
   ret = (char*)0;
   switch (
          (*__errno_location ())
               ) {
   case 0:
   case 
       5
          :
   case 
       3
            :
   case 
       22
             :
   case 
       2
             :
    break;
   default:
    fprintf(
           stderr
                 , "sulogin: read(%s): %m\n\r", con->tty);
    break;
   }
   goto quit;
  }

  if (eightbit)
   ascval = c;
  else if (c != (ascval = (c & 0177))) {
   uint32_t bits, mask;
   for (bits = 1, mask = 1; mask & 0177; mask <<= 1) {
    if (mask & ascval)
     bits++;
   }
   cp->parity |= ((bits & 1) ? 1 : 2);
  }

  switch (ascval) {
  case 0:
   *ptr = '\0';
   goto quit;
  case 
      (
      'm'
      &037)
        :
  case 
      (
      'j'
      &037)
        :
   *ptr = '\0';
   cp->eol = ascval;
   break;
  case 
      (
      'h'
      &037)
        :
  case 
      0177
            :
   cp->erase = ascval;
   if (ptr > &pass[0])
    ptr--;
   break;
  case 
      ('u'&037)
           :
   cp->kill = ascval;
   while (ptr > &pass[0])
    ptr--;
   break;
  case 
      ('d'&037)
          :
   goto quit;
  default:
   if ((size_t)(ptr - &pass[0]) >= (sizeof(pass) -1 )) {
     fprintf(
            stderr
                  , "sulogin: input overrun at %s\n\r", con->tty);
     ret = (char*)0;
     goto quit;
   }
   *ptr++ = ascval;
   break;
  }
 }
quit:
 alarm(0);
 if (tc)
  (void)tcsetattr(fd, 
                     2
                              , &con->tio);
 if (ret && *ret != '\0')
  tcfinal(con);
 printf("\r\n");
out:
 return ret;
}




static
void sushell(struct passwd *pwd)
{
 char shell[128];
 char home[128];
 char *p;
 char *sushell;




 if (chdir(pwd->pw_dir) < 0) {
  if (chdir("/") < 0)
   fprintf(
          stderr
                , "sulogin: change of working directory failed: %m\n\r");
 }
 if ((p = getenv("SUSHELL")) != 
                               ((void *)0)
                                   )
  sushell = p;
 else if ((p = getenv("sushell")) != 
                                    ((void *)0)
                                        )
  sushell = p;
 else {
  if (pwd->pw_shell[0])
   sushell = pwd->pw_shell;
  else
   sushell = "/bin/sh";
 }
 if ((p = strrchr(sushell, '/')) == 
                                   ((void *)0)
                                       )
  p = sushell;
 else
  p++;
 snprintf(shell, sizeof(shell), profile ? "-%s" : "%s", p);




 if (getcwd(home, sizeof(home)) == (char*)0)
  strcpy(home, "/");
 setenv("HOME", home, 1);
 setenv("LOGNAME", "root", 1);
 setenv("USER", "root", 1);
 if (!profile)
  setenv("SHLVL","0",1);




 setenv("SHELL", sushell, 1);
 signal(
       2
             , saved_sigint);
 signal(
       20
              , saved_sigtstp);
 signal(
       3
              , saved_sigquit);
 signal(
       1
             , 
                ((__sighandler_t) 0)
                       );
 execl(sushell, shell, 
                      ((void *)0)
                          );
 perror(sushell);

 setenv("SHELL", "/bin/sh", 1);
 execl("/bin/sh", profile ? "-sh" : "sh", 
                                     ((void *)0)
                                         );
 perror("/bin/sh");



 setenv("SHELL", "/bin/sash", 1);
 execl("/bin/sash", "/bin/sash", 
                          ((void *)0)
                              );
 perror("/bin/sash");
}





static uint32_t mounts;



static __attribute__((__noinline__))
void putmounts(void)
{
 if (mounts & 0x0002)
  umount2("/dev", 
                 MNT_DETACH
                           );
 if (mounts & 0x0001)
  umount2("/proc", 
                  MNT_DETACH
                            );
}

static __attribute__((__constructor__))
void getmounts(void)
{
 struct statfs st;
 if (statfs("/proc", &st) == 0 && st.f_type != 
                                              0x9fa0
                                                              ) {
  if (mount("proc", "/proc", "proc", 
                                    MS_RELATIME
                                               , 
                                                 ((void *)0)
                                                     ) == 0)
   mounts |= 0x0001;
 }
 if (statfs("/dev", &st) == 0 && st.f_type != 
                                             0x01021994
                                                        ) {
  if (mount("devtmpfs", "/dev", "devtmpfs", 
                                           MS_RELATIME
                                                      , "mode=0755,nr_inodes=0") == 0) {
   mounts |= 0x0002;
   (void)mknod("/dev/console", 
                              0020000
                                     |
                                      0400
                                             |
                                              0200
                                                     , 
                                                       gnu_dev_makedev (5, 
                                                       1
                                                       )
                                                                               );
   if (symlink("/proc/self/fd", "/dev/fd") == 0) {
    if ((symlink("fd/0", "/dev/stdin"))){};
    if ((symlink("fd/1", "/dev/stdout"))){};
    if ((symlink("fd/2", "/dev/stderr"))){};
   }
  }
 }
 if (mounts) atexit(putmounts);
}


static
void usage(void)
{
 fprintf(
        stderr
              , "Usage: sulogin [-e] [-p] [-t timeout] [tty device]\n\r");
}

int main(int argc, char **argv)
{
 char *tty = 
            ((void *)0)
                ;
 struct passwd *pwd;
 int c, status = 0;
 int reconnect = 0;
 int opt_e = 0;
 struct console *con;
 pid_t pid;




 if ((pid = getpid()) == 1) {
  setsid();
  (void)ioctl(0, 
                0x540E
                         , (char *)1);
 }




 opterr = 0;
 while((c = getopt(argc, argv, "ept:")) != 
                                          (-1)
                                             ) switch(c) {
  case 't':
   timeout = atoi(optarg);
   break;
  case 'p':
   profile = 1;
   break;
  case 'e':
   opt_e = 1;
   break;
  default:
   usage();

   break;
 }

 if (geteuid() != 0) {
  fprintf(
         stderr
               , "sulogin: only root can run sulogin.\n\r");
  exit(1);
 }

 saved_sigint = signal(
                       2
                             , 
                                ((__sighandler_t) 1)
                                       );
 saved_sigquit = signal(
                       3
                              , 
                                ((__sighandler_t) 1)
                                       );
 saved_sigtstp = signal(
                       20
                              , 
                                ((__sighandler_t) 1)
                                       );
 saved_sighup = signal(
                       1
                             , 
                                ((__sighandler_t) 1)
                                       );




 if (optind < argc)
  tty = argv[optind];
 if (!tty || *tty == '\0')
  tty = getenv("CONSOLE");





 reconnect = detect_consoles(tty, 0);




 if (!consoles) {
  if (!
      (*__errno_location ())
           )
   
  (*__errno_location ()) 
        = 
          12
                ;
  fprintf(
         stderr
               , "sulogin: cannot open console: %m\n\r");
  exit(1);
 }





 if (reconnect) {
  if (isatty(1) == 0)
   dup2(0, 1);
  if (isatty(2) == 0)
   dup2(0, 2);
 }




 if ((pwd = getrootpwent(opt_e)) == 
                                   ((void *)0)
                                       ) {
  fprintf(
         stderr
               , "sulogin: cannot open password database!\n\r");
  sleep(2);
 }




 for (con = consoles; con && con->id < 16; con = con->next) {
  if (con->fd >= 0) {
   openfd |= (1<<con->fd);
   tcinit(con);
   continue;
  }
  if ((con->fd = open(con->tty, 
                               02 
                                      | 
                                        0400 
                                                 | 
                                                   04000
                                                             )) < 0)
   continue;
  openfd |= (1<<con->fd);
  tcinit(con);
 }
 con = consoles;
 usemask = (uint32_t*)mmap(
                          ((void *)0)
                              , sizeof(uint32_t), 
                                                  0x1
                                                           |
                                                            0x2
                                                                      , 
                                                                        0x20
                                                                                     |
                                                                                      0x01
                                                                                                , -1, 0);

 if (con->next == (struct console*)0)
  goto nofork;

 signal(
       17
              , chld_handler);
 do {
  switch ((con->pid = fork())) {
  case 0:
   signal(
         17
                , 
                   ((__sighandler_t) 0)
                          );

  nofork:
   setup(con);
   while (1) {
    char *passwd = pwd->pw_passwd;
    char *answer;
    int failed = 0, doshell = 0;

    doprompt(passwd, con);
    if ((answer = getpasswd(con)) == 
                                    ((void *)0)
                                        )
     break;

    if (passwd[0] == '\0')
     doshell++;
    else {
     char *cryptbuf;
     cryptbuf = crypt(answer, passwd);
     if (cryptbuf == 
                    ((void *)0)
                        )
      fprintf(
             stderr
                   , "sulogin: crypt failed: %m\n\r");
     else if (strcmp(cryptbuf, pwd->pw_passwd) == 0)
      doshell++;
    }

    if (doshell) {
     *usemask |= (1<<con->id);
     sushell(pwd);
     *usemask &= ~(1<<con->id);
     failed++;
    }

    signal(
          3
                 , 
                   ((__sighandler_t) 1)
                          );
    signal(
          20
                 , 
                   ((__sighandler_t) 1)
                          );
    signal(
          2
                , 
                   ((__sighandler_t) 1)
                          );

    if (failed) {
     fprintf(
            stderr
                  , "sulogin: can not execute su shell.\n\r");
     break;
    }
    fprintf(
           stderr
                 , "Login incorrect.\n\r");
    sleep(3);
   }
   if (alarm_rised) {
    tcfinal(con);
    fprintf(
           stderr
                 , "Timed out.\n\r");
   }



   exit(0);
  case -1:
   fprintf(
          stderr
                , "sulogin: can not fork: %m\n\r");

  default:
   break;
  }
 } while ((con = con->next) && (con->id < 16));

 while ((pid = wait(&status))) {
  if (
     (*__errno_location ()) 
           == 
              10
                    )
   break;
  if (pid < 0)
   continue;
  for (con = consoles; con && con->id < 16; con = con->next) {
   if (con->pid == pid) {
    *usemask &= ~(1<<con->id);
    continue;
   }
   if (kill(con->pid, 0) < 0) {
    *usemask &= ~(1<<con->id);
    continue;
   }
   if (*usemask & (1<<con->id))
    continue;
   kill(con->pid, 
                 1
                       );
   usleep(5000);
   kill(con->pid, 
                 9
                        );
  }
 }
 signal(
       17
              , 
                 ((__sighandler_t) 0)
                        );

 return 0;
}
