









struct init_request_bsd {
 char gen_id[8];
 char tty_id[16];
 char host[
          64
                     ];
 char term_type[16];
 int signal;
 int pid;
 char exec_name[128];
 char reserved[128];
};
struct init_request {
 int magic;
 int cmd;
 int runlevel;
 int sleeptime;
 union {
  struct init_request_bsd bsd;
  char data[368];
 } i;
};
void write_utmp_wtmp(char *user, char *id, int pid, int type, char *line);
void write_wtmp(char *user, char *id, int pid, int type, char *line);

__attribute__ ((format (printf, 2, 3)))

void initlog(int loglevel, char *fmt, ...);
void set_term(int how);
void print(char *fmt);


void wall(const char *text, int remote);
typedef struct _child_ {
  int flags;
  int exstat;
  int pid;
  time_t tm;
  int count;
  char id[8];
  char rlevel[12];
  int action;
  char process[128];
  struct _child_ *new;
  struct _child_ *next;
} CHILD;
extern CHILD *family;
extern int wrote_wtmp_reboot;
extern int wrote_utmp_reboot;
extern int wrote_wtmp_rlevel;
extern int wrote_utmp_rlevel;
extern char thislevel;
extern char prevlevel;
int dontshut = 0;
char down_level[2];
int dosync = 1;
int fastboot = 0;
int forcefsck = 0;
char message[256];
char *sltime = 0;
char newstate[64];
int doself = 0;
int got_alrm = 0;

char *clean_env[] = {
 "HOME=/",
 "PATH=" "/sbin:/usr/sbin:/bin:/usr/bin",
 "TERM=dumb",
 "SHELL=/bin/sh",
 
((void *)0)
    ,
};


extern void write_wtmp(char *user, char *id, int pid, int type, char *line);




void hardsleep(int secs)
{
 struct timespec ts, rem;

 ts.tv_sec = secs;
 ts.tv_nsec = 0;

 while(nanosleep(&ts, &rem) < 0 && 
                                  (*__errno_location ()) 
                                        == 
                                           4
                                                )
  ts = rem;
}





void stopit(int sig __attribute__((unused)))




{
 unlink("/etc/nologin");
 unlink("/fastboot");
 unlink("/forcefsck");
 unlink("/var/run/shutdown.pid");
 printf("\r\nShutdown cancelled.\r\n");
 exit(0);
}




void usage(void)
{
 fprintf(
        stderr
              ,
 "Usage:\t  shutdown [-akrhPHfFnc] [-t sec] time [warning message]\n"
 "\t\t  -a:      use /etc/shutdown.allow\n"
 "\t\t  -k:      don't really shutdown, only warn.\n"
 "\t\t  -r:      reboot after shutdown.\n"
 "\t\t  -h:      halt after shutdown.\n"
 "\t\t  -P:      halt action is to turn off power.\n"
        "\t\t           can only be used along with -h flag.\n"
 "\t\t  -H:      halt action is to just halt.\n"
        "\t\t           can only be used along with -h flag.\n"
 "\t\t  -f:      do a 'fast' reboot (skip fsck).\n"
 "\t\t  -F:      Force fsck on reboot.\n"
 "\t\t  -n:      do not go through \"init\" but go down real fast.\n"
 "\t\t  -c:      cancel a running shutdown.\n"
        "\t\t  -q:      quiet mode - display fewer shutdown warnings.\n"
        "\t\t  -Q:      full quiet mode - display only final shutdown warning.\n"
 "\t\t  -t secs: delay between warning and kill signal.\n"
 "\t\t  ** the \"time\" argument is mandatory! (try \"now\") **\n");
 exit(1);
}


void alrm_handler(int sig)
{
 got_alrm = sig;
}





int init_setenv(char *name, char *value)
{
 struct init_request request;
 struct sigaction sa;
 int fd;
 size_t nl, vl;

 memset(&request, 0, sizeof(request));
 request.magic = 0x03091969;
 request.cmd = 6;
 nl = strlen(name);
 vl = value ? strlen(value) : 0;

 if (nl + vl + 3 >= (int)sizeof(request.i.data))
  return -1;

 memcpy(request.i.data, name, nl);
 if (value) {
  request.i.data[nl] = '=';
  memcpy(request.i.data + nl + 1, value, vl);
 }





 memset(&sa, 0, sizeof(sa));
 sa.
   __sigaction_handler.sa_handler 
              = alrm_handler;
 sigaction(
          14
                 , &sa, 
                        ((void *)0)
                            );
 got_alrm = 0;
 alarm(3);
 if ((fd = open("/run/initctl", 
                          01
                                  )) >= 0) {
  ssize_t p = 0;
  size_t s = sizeof(request);
  void *ptr = &request;
  while (s > 0) {
   p = write(fd, ptr, s);
   if (p < 0) {
    if (
       (*__errno_location ()) 
             == 
                4 
                      || 
                         (*__errno_location ()) 
                               == 
                                  11
                                        )
     continue;
    break;
   }
   ptr += p;
   s -= p;
  }
  close(fd);
  alarm(0);
  return 0;
 }

 fprintf(
        stderr
              , "shutdown: ");
 if (got_alrm) {
  fprintf(
         stderr
               , "timeout opening/writing control channel %s\n",
   "/run/initctl");
 } else {
  perror("/run/initctl");
 }
 return -1;
}





void issue_warn(int mins)
{
 char buf[256 + sizeof(newstate) + 1];
 int len;

 buf[0] = 0;
 strncpy(buf, message, 256);
 len = strlen(buf);

 if (mins == 0)
  snprintf(buf + len, sizeof(buf) - len,
   "\rThe system is going down %s NOW!\r\n",
   newstate);
 else
    snprintf(buf + len, sizeof(buf) - len,
   "\rThe system is going DOWN %s in %d minute%s!\r\n",
    newstate, mins, mins == 1 ? "" : "s");
 wall(buf, 0);
}




void donologin(int min)
{
 FILE *fp;
 time_t t;

 time(&t);
 t += 60 * min;

 if ((fp = fopen("/etc/nologin", "w")) != 
                                  ((void *)0)
                                      ) {
    fprintf(fp, "\rThe system is going down on %s\r\n", ctime(&t));
    if (message[0]) fputs(message, fp);
    fclose(fp);
 }
}




int spawn(int noerr, char *prog, ...)
{
 va_list ap;
 pid_t pid, rc;
 int i;
 char *argv[8];

 i = 0;
 while ((pid = fork()) < 0 && i < 10) {
  perror("fork");
  sleep(5);
  i++;
 }

 if (pid < 0) return -1;

 if (pid > 0) {
  while((rc = wait(&i)) != pid)
   if (rc < 0 && 
                (*__errno_location ()) 
                      == 
                         10
                               )
    break;
  return (rc == pid) ? 
                      (((
                      i
                      ) & 0xff00) >> 8) 
                                     : -1;
 }

 if (noerr) fclose(
                  stderr
                        );

 argv[0] = prog;
 
__builtin_va_start(
ap
,
prog
)
                  ;
 for (i = 1; i < 7 && (argv[i] = 
                                __builtin_va_arg(
                                ap
                                ,
                                char *
                                )
                                                  ) != 
                                                       ((void *)0)
                                                           ; i++)
  ;
 argv[i] = 
          ((void *)0)
              ;
 
__builtin_va_end(
ap
)
          ;

 if (chdir("/"))
  exit(1);
 environ = clean_env;

 execvp(argv[0], argv);
 perror(argv[0]);
 exit(1);


 return 0;
}




void fastdown()
{
 int do_halt = (down_level[0] == '0');
 int i;
 for(i = 0; i < 3; i++)
  if (!isatty(i)) {
   close(i);
   open("/dev/null", 
                    02
                          );
  }
 for(i = 3; i < 20; i++) close(i);
 close(255);


 if (kill(1, 
            20
                   ) < 0) {
  fprintf(
         stderr
               , "shutdown: can't idle init: %s.\r\n", strerror(
                                                                (*__errno_location ())
                                                                     ));
  exit(1);
 }


 fprintf(
        stderr
              , "shutdown: sending all processes the TERM signal...\r\n");
 kill(-1, 
         15
                );
 sleep(sltime ? atoi(sltime) : 3);
 fprintf(
        stderr
              , "shutdown: sending all processes the KILL signal.\r\n");
 (void) kill(-1, 
                9
                       );
 write_wtmp("shutdown", "~~", 0, 
                                1
                                       , "~~");
 spawn(1, "accton", 
                   ((void *)0)
                       );


 spawn(1, "quotaoff", "-a", 
                           ((void *)0)
                               );

 sync();
 fprintf(
        stderr
              , "shutdown: turning off swap\r\n");
 spawn(0, "swapoff", "-a", 
                          ((void *)0)
                              );
 fprintf(
        stderr
              , "shutdown: unmounting all file systems\r\n");
 spawn(0, "umount", "-a", 
                         ((void *)0)
                             );


 if (do_halt) {
  fprintf(
         stderr
               , "The system is halted. Press CTRL-ALT-DEL "
    "or turn off power\r\n");
  reboot(
 0xcdef0123
 );
  exit(0);
 }

 fprintf(
        stderr
              , "Please stand by while rebooting the system.\r\n");
 reboot(
0x01234567
);
 exit(0);
}




void issue_shutdown(char *halttype)
{
 char *args[8];
 int argp = 0;
 int do_halt = (down_level[0] == '0');


 issue_warn(0);
 if (dontshut) {
  hardsleep(1);
  stopit(0);
 }
 openlog("shutdown", 
                    0x01
                           , 
                             (1<<3)
                                     );
 if (do_halt)
    syslog(
          5
                    , "shutting down for system halt");
 else
  syslog(
        5
                  , "shutting down for system reboot");
 closelog();


 if (doself) fastdown();


 args[argp++] = "/sbin/init";
 if (sltime) {
  args[argp++] = "-t";
  args[argp++] = sltime;
 }
 args[argp++] = down_level;
 args[argp] = (char *)
                       ((void *)0)
                           ;

 unlink("/var/run/shutdown.pid");
 unlink("/etc/nologin");


 sync();
 init_setenv("INIT_HALT", halttype);
 execv("/sbin/init", args);


 fprintf(
        stderr
              , "\rshutdown: cannot execute %s\r\n", "/sbin/init");
 unlink("/fastboot");
 unlink("/forcefsck");
 init_setenv("INIT_HALT", 
                         ((void *)0)
                             );
 openlog("shutdown", 
                    0x01
                           , 
                             (1<<3)
                                     );
 syslog(
       5
                 , "shutdown failed");
 closelog();
 exit(1);
}




static int needwarning(int wt, int quiet_mode)
{
 int ret;

        if (quiet_mode == 2) return 0;
        else if (quiet_mode == 1)
        {
            if (wt == 10)
               return 1;
            else if (wt == 5)
               return 1;
            else if ( (wt % 60) == 0)
               return 1;
            else
               return 0;
        }

 if (wt < 10)
  ret = 1;
 else if (wt < 60)
  ret = (wt % 15 == 0);
 else if (wt < 180)
  ret = (wt % 30 == 0);
 else
  ret = (wt % 60 == 0);

 return ret;
}





int main(int argc, char **argv)
{
 FILE *fp;
 extern int getopt();
 extern int optind;
 struct sigaction sa;
 struct tm *lt;
 struct stat st;
 struct utmp *ut;
 time_t t, target_time;
 char *halttype;
 char *downusers[32];
 char buf[128];
 char term[
            32 
                        + 6];
 char *sp;
 char when[64];
 int c, i, wt;
 int hours, mins;
 int didnolog = 0;
 int cancel = 0;
 int useacl = 0;
 int pid = 0;
 int user_ok = 0;
        int quiet_level = 0;






        
       (*__errno_location ()) 
             = 0;
        if (setuid(geteuid()) == -1) {
            fprintf(
                   stderr
                         , "%s (%d): %s\n", "shutdown.c", 541, strerror(
                                                                         (*__errno_location ())
                                                                              ));
            abort();
 }

 if (getuid() != 0) {
    fprintf(
           stderr
                 , "shutdown: you must be root to do that!\n");
  usage();
    exit(1);
 }
 strcpy(down_level, "1");
 halttype = 
           ((void *)0)
               ;
        memset(when, '\0', 64);


 while((c = getopt(argc, argv, "HPacqQkrhnfFyt:g:i:")) != 
                                                         (-1)
                                                            ) {
    switch(c) {
   case 'H':
    halttype = "HALT";
    break;
   case 'P':
    halttype = "POWEROFF";
    break;
   case 'a':
    useacl = 1;
    break;
   case 'c':
    cancel = 1;
    break;
     case 'k':
      dontshut = 1;
      break;
     case 'r':
    down_level[0] = '6';
      break;
     case 'h':
    down_level[0] = '0';
      break;
     case 'f':
      fastboot = 1;
      break;
     case 'F':
      forcefsck = 1;
      break;
   case 'n':
    doself = 1;
    break;
   case 't':
    sltime = optarg;
    break;
                        case 'q':
                                quiet_level = 1;
                                break;
                        case 'Q':
                                quiet_level = 2;
                                break;
   case 'y':
    break;
   case 'g':
    strncpy(when, optarg, 64 - 1);
    break;
   case 'i':
    if (!strchr("0156aAbBcCsS", optarg[0])) {
     fprintf(
            stderr
                  ,
     "shutdown: `%s': bad runlevel\n",
     optarg);
     exit(1);
    }
    down_level[0] = optarg[0];
    break;
     default:
      usage();
      break;
    }
 }

 if (
    ((void *)0) 
         != halttype && down_level[0] != '0') {
  fprintf(
         stderr
               , "shutdown: -H and -P flags can only be used along with -h flag.\n");
  usage();
    exit(1);
 }


 if (useacl && (fp = fopen("/etc/shutdown.allow", "r")) != 
                                            ((void *)0)
                                                ) {


  i = 0;
  while(fgets(buf, 128, fp)) {
   if (buf[0] == '#' || buf[0] == '\n') continue;
   if (i > 31) continue;
   for(sp = buf; *sp; sp++) if (*sp == '\n') *sp = 0;
   downusers[i++] = strdup(buf);
  }
  if (i < 32) downusers[i] = 0;
  fclose(fp);


  while(!user_ok && (ut = getutent()) != 
                                        ((void *)0)
                                            ) {


   if (ut->ut_type != 
                     7
                                 ) continue;
   sprintf(term, "/dev/%.*s", 
                             32
                                        , ut->ut_line);
   if (stat(term, &st) < 0) continue;

   if (
      gnu_dev_major (
      st.st_rdev
      ) 
                        != 4 ||
       
      gnu_dev_minor (
      st.st_rdev
      ) 
                        > 63) continue;




   if (strcmp(ut->ut_user, "root") == 0) {
    user_ok++;
    break;
   }


   for(i = 0; i < 32 && downusers[i]; i++)
    if (!strncmp(downusers[i], ut->ut_user,
        
       32
                  )) {
     user_ok++;
     break;
    }
  }
  endutent();


  if (!user_ok) {
   if ((fp = fopen("/dev/console", "w")) != 
                                    ((void *)0)
                                        ) {
    fprintf(fp, "\rshutdown: no authorized users "
      "logged in.\r\n");
    fclose(fp);
   }
   exit(1);
  }
 }


 if ((fp = fopen("/var/run/shutdown.pid", "r")) != 
                                ((void *)0)
                                    ) {
  if (fscanf(fp, "%d", &pid) != 1)
   pid = 0;
  fclose(fp);
 }


 message[0] = 0;
 for(c = optind + (!cancel && !when[0]); c < argc; c++) {
  if (strlen(message) + strlen(argv[c]) + 4 > 256)
   break;
    strcat(message, argv[c]);
    strcat(message, " ");
 }
 if (message[0]) strcat(message, "\r\n");


 if (cancel) {
  if (pid <= 0) {
   fprintf(
          stderr
                , "shutdown: cannot find pid "
     "of running shutdown.\n");
   exit(1);
  }
  init_setenv("INIT_HALT", 
                          ((void *)0)
                              );
  if (kill(pid, 
               2
                     ) < 0) {
   fprintf(
          stderr
                , "shutdown: not running.\n");
   exit(1);
  }
  if (message[0]) wall(message, 0);
  exit(0);
 }


 if (when[0] == '\0') {
  if (optind == argc) usage();
                strncpy(when, argv[optind++], 64 - 1);
 }


 if (pid > 0 && kill(pid, 0) == 0) {
  fprintf(
         stderr
               , "\rshutdown: already running.\r\n");
  exit(1);
 }


 if (doself && down_level[0] != '0' && down_level[0] != '6') {
  fprintf(
         stderr
               ,
  "shutdown: can use \"-n\" for halt or reboot only.\r\n");
  exit(1);
 }


 switch(down_level[0]) {
  case '0':
   strncpy(newstate, "for system halt", 64);
   break;
  case '6':
   strncpy(newstate, "for reboot", 64);
   break;
  case '1':
   strncpy(newstate, "to maintenance mode", 64);
   break;
  default:
   snprintf(newstate, 64, "to runlevel %s", down_level);
   break;
 }


 if (chdir("/")) {
  fprintf(
         stderr
               , "shutdown: chdir(/): %m\n");
  exit(1);
 }


 unlink("/var/run/shutdown.pid");
 umask(022);
 if ((fp = fopen("/var/run/shutdown.pid", "w")) != 
                                ((void *)0)
                                    ) {
  fprintf(fp, "%d\n", getpid());
  fclose(fp);
 } else if (
           (*__errno_location ()) 
                 != 
                    30
                         )
  fprintf(
         stderr
               , "shutdown: warning: cannot open %s\n", "/var/run/shutdown.pid");




 signal(
       3
              , 
                ((__sighandler_t) 1)
                       );
 signal(
       17
              , 
                ((__sighandler_t) 1)
                       );
 signal(
       1
             , 
                ((__sighandler_t) 1)
                       );
 signal(
       20
              , 
                ((__sighandler_t) 1)
                       );
 signal(
       21
              , 
                ((__sighandler_t) 1)
                       );
 signal(
       22
              , 
                ((__sighandler_t) 1)
                       );

 memset(&sa, 0, sizeof(sa));
 sa.
   __sigaction_handler.sa_handler 
              = stopit;
 sigaction(
          2
                , &sa, 
                       ((void *)0)
                           );

 if (fastboot) close(open("/fastboot", 
                                     0100 
                                             | 
                                               02
                                                     , 0644));
 if (forcefsck) close(open("/forcefsck", 
                                     0100 
                                             | 
                                               02
                                                     , 0644));


 if (!strcmp(when, "now")) strcpy(when, "0");

        sp = when;

 for ( ; *sp; sp++) {
  if (*sp != '+' && *sp != ':' && (*sp < '0' || *sp > '9'))
   usage();
 }
 sp = when;

 if (when[0] == '+') sp++;
 if (strchr(when, ':') == 
                         ((void *)0)
                             ) {

  wt = atoi(sp);
  if (wt == 0 && sp[0] != '0') usage();
 } else {
  if (sscanf(when, "%d:%2d", &hours, &mins) != 2) usage();

  if (when[0] == '+') {

   if (hours > 99999 || mins > 59) usage();
   wt = (60*hours + mins);
   if (wt < 0) usage();
  } else {

   if (hours > 23 || mins > 59) usage();
   time(&t);
   lt = localtime(&t);
   wt = (60*hours + mins) - (60*lt->tm_hour + lt->tm_min);
   if (wt < 0) wt += 1440;
  }
 }

 if (wt == 0) issue_shutdown(halttype);
        time(&t);
        target_time = t + (60 * wt);


 if (wt < 15 && !needwarning(wt, quiet_level)) issue_warn(wt);
 while(wt) {
  if (wt <= 5 && !didnolog) {
   donologin(wt);
   didnolog++;
  }
  if (needwarning(wt, quiet_level)) issue_warn(wt);
  hardsleep(60);
                time(&t);
                if (t >= target_time)
                  wt = 0;
                else if ( (target_time - t) <= 60 )
                {
                    hardsleep(target_time - t);
                    wt = 0;
                }
                else
                   wt = (int) (target_time - t) / 60;
 }
 issue_shutdown(halttype);

 return 0;
}
