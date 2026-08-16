










int expand_envvar(const char *, char *, size_t);







extern char *tzname[2];
int getopt(int, char * const *, const char *);



extern char *optarg;
extern int optind, opterr, optopt;




extern int flock(int, int);





typedef unsigned char bitstr_t;

typedef struct _entry {
 struct _entry *next;
 struct passwd *pwd;
 char **envp;
 char *cmd;
 bitstr_t (minute)[(((((59 - 0 + 1)) - 1) >> 3) + 1)];
 bitstr_t (hour)[(((((23 - 0 + 1)) - 1) >> 3) + 1)];
 bitstr_t (dom)[(((((31 - 1 + 1)) - 1) >> 3) + 1)];
 bitstr_t (month)[(((((12 - 1 + 1)) - 1) >> 3) + 1)];
 bitstr_t (dow)[(((((7 - 0 + 1)) - 1) >> 3) + 1)];
 int flags;
 int delay;






} entry;
typedef struct _user {
 struct _user *next, *prev;
 char *name;
 char *tabname;
 time_t mtime;
 entry *crontab;
 unsigned scontext;
 int system;
} user;

typedef struct _orphan {
 struct _orphan *next;
 char *uname;
 char *fname;
 char *tabname;
} orphan;

typedef struct _cron_db {
 user *head, *tail;
 time_t mtime;



} cron_db;

void set_cron_uid(void),
  check_spool_dir(void),
  open_logfile(void),
  sigpipe_func(void),
  job_add(entry *, user *),
  do_command(entry *, user *),
  link_user(cron_db *, user *),
  unlink_user(cron_db *, user *),
  free_user(user *),
  env_free(char **),
  unget_char(int, FILE *),
  free_entry(entry *),
  acquire_daemonlock(int),
  log_it(const char *, pid_t, const char *, const char *, int),
  log_close(void),
  check_orphans(cron_db *);






int load_database(cron_db *),
  job_runqueue(void),
  set_debug_flags(const char *),
  get_char(FILE *),
  get_string(char *, int, FILE *, const char *),
  swap_uids(void),
  swap_uids_back(void),
  load_env(char *, FILE *),
  env_set_from_environ(char ***envpp),
  cron_pclose(FILE *),
  glue_strings(char *, size_t, const char *, const char *, char),
  strcmp_until(const char *, const char *, char),
  skip_comments(FILE *),
  allowed(const char * ,const char * ,const char *);

size_t strlens(const char *, ...),
  strdtb(char *);

char *env_get(const char *, char **),
  *arpadate(time_t *),
  *mkprints(unsigned char *, size_t),
  *first_word(const char *, const char *),
  **env_init(void),
  **env_copy(char **),
  **env_set(char **, const char *),
  **env_update_home(char **, const char *);

user *load_user(int, struct passwd *, const char *, const char *, const char *),
  *find_user(cron_db *, const char *, const char *);

entry *load_entry(FILE *, void (*)(), struct passwd *, char **);

FILE *cron_popen(char *, const char *, struct passwd *, char **);

struct passwd *pw_dup(const struct passwd *);







void cron_restore_default_security_context( void );

int cron_set_job_security_context( entry *e, user *u, char ***jobenvp );

int cron_open_security_session( struct passwd *pw );

void cron_close_security_session( void );

int cron_change_groups( struct passwd *pw );

int cron_change_user_permanently( struct passwd *pw, char *homedir );

int get_security_context(const char *name,
    int crontab_fd,
    unsigned *rcontext,
    const char *tabname
                        );

void free_security_context( unsigned *scontext );

int crontab_security_access(void);
 const char *copyright[]

 = {
  "@(#) ISC Cron V4.1",
  "@(#) Copyright 1988,1989,1990,1993,1994 by Paul Vixie",
  "@(#) Copyright 1997,2000 by Internet Software Consortium, Inc.",
  "@(#) Copyright 2004 by Internet Systems Consortium, Inc.",
  "@(#) All rights reserved",
  
 ((void *)0)
 
}

 ;

 const char *MonthNames[]

 = {
  "Jan", "Feb", "Mar", "Apr", "May", "Jun",
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
  
 ((void *)0)
 
}

 ;

 const char *DowNames[]

 = {
  "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun",
  
 ((void *)0)
 
}

 ;

 char *ProgramName;
 int LineNumber;
 int SyslogOutput;
 time_t StartTime;
 int NoFork;
 int PermitAnyCrontab;
 char MailCmd[131072 +1];
 char cron_default_mail_charset[131072];
 int EnableClustering;
 int ChangePath;
 double RandomScale;


 int DebugFlags = 0;
 const char *DebugFlagNames[]

 = {
  "ext", "sch", "proc", "pars", "load", "misc", "test", "bit",
  
 ((void *)0)
 
}

 ;









enum timejump { negative, small, medium, large };

static void usage(void) __attribute__ ((__noreturn__)),
run_reboot_jobs(cron_db *),
find_jobs(int, cron_db *, int, int, long),
set_time(int),
cron_sleep(int, cron_db *),
sigchld_handler(int),
sighup_handler(int __attribute__ ((__unused__))),
sigchld_reaper(void),
sigintterm_handler(int __attribute__ ((__unused__))), parse_args(int c, char *v[]);

static volatile sig_atomic_t got_sighup, got_sigchld, got_sigintterm;
static int timeRunning, virtualTime, clockTime;
static long GMToff;
static int DisableInotify;
static void handle_signals(cron_db * database) {
 if (got_sighup) {
  got_sighup = 0;
  database->mtime = (time_t) 0;
  log_close();
 }

 if (got_sigchld) {
  got_sigchld = 0;
  sigchld_reaper();
 }
}

static void usage(void) {
 const char **dflags;

 fprintf(
        stderr
              , "Usage:\n");
 fprintf(
        stderr
              , " %s [options]\n", ProgramName);
 fprintf(
        stderr
              , "\n");
 fprintf(
        stderr
              , "Options:\n");
 fprintf(
        stderr
              , " -h         print this message \n");
 fprintf(
        stderr
              , " -i         deamon runs without inotify support\n");
 fprintf(
        stderr
              , " -m <comm>  off, or specify preferred client for sending mails\n");
 fprintf(
        stderr
              , " -n         run in foreground\n");
 fprintf(
        stderr
              , " -f         run in foreground, the same as -n\n");
 fprintf(
        stderr
              , " -p         permit any crontab\n");
 fprintf(
        stderr
              , " -P         inherit PATH from environment instead of using default value");
 fprintf(
        stderr
              , "            of \"%s\"\n", 
                                           "/usr/bin:/bin"
                                                        );
 fprintf(
        stderr
              , " -c         enable clustering support\n");
 fprintf(
        stderr
              , " -s         log into syslog instead of sending mails\n");
 fprintf(
        stderr
              , " -V         print version and exit\n");
 fprintf(
        stderr
              , " -x <flag>  print debug information\n");
 fprintf(
        stderr
              , "\n");
 fprintf(
        stderr
              , "Debugging flags are: ");
 for (dflags = DebugFlagNames; *dflags; dflags++)
  fprintf(
         stderr
               , "%s%s", *dflags, dflags[1] ? "," : "\n");
 exit(1);
}

int main(int argc, char *argv[]) {
 struct sigaction sact;
 cron_db database;
 int fd;
 char *cs;
 pid_t pid = getpid();
 long oldGMToff;
 struct timeval tv;
 struct timezone tz;
 char buf[256];

 if ((ProgramName=strrchr(argv[0], '/')) == 
                                           ((void *)0)
                                               ) {
  ProgramName = argv[0];
 }
 else {
  ++ProgramName;
 }

 MailCmd[0] = '\0';
 cron_default_mail_charset[0] = '\0';

 setlocale(
          6
                , "");






 SyslogOutput = 0;
 NoFork = 0;
 ChangePath = 1;
 parse_args(argc, argv);

 memset((char *) &sact, 0, sizeof sact);
 sigemptyset(&sact.sa_mask);
 sact.sa_flags = 0;

 sact.sa_flags |= 
                 0x10000000
                           ;

 sact.
     __sigaction_handler.sa_handler 
                = sigchld_handler;
 (void) sigaction(
                 17
                        , &sact, 
                                 ((void *)0)
                                     );
 sact.
     __sigaction_handler.sa_handler 
                = sighup_handler;
 (void) sigaction(
                 1
                       , &sact, 
                                ((void *)0)
                                    );
 sact.
     __sigaction_handler.sa_handler 
                = sigintterm_handler;
 (void) sigaction(
                 2
                       , &sact, 
                                ((void *)0)
                                    );
 (void) sigaction(
                 15
                        , &sact, 
                                 ((void *)0)
                                     );

 acquire_daemonlock(0);
 set_cron_uid();
 check_spool_dir();

 if (ChangePath) {
  if (setenv("PATH", 
                    "/usr/bin:/bin"
                                 , 1) < 0) {
   log_it("CRON", pid, "DEATH", "can't setenv PATH",
    
   (*__errno_location ())
        );
   exit(1);
  }
 }




 setlocale(
          6
                , "");

 if ((cs = nl_langinfo(
                      CODESET
                             )) != 
                                   ((void *)0)
                                       )
  strncpy(cron_default_mail_charset, cs, 131072 -1);
 else
  strcpy(cron_default_mail_charset, "US-ASCII");



 if (DebugFlags) {

  (void) fprintf(
                stderr
                      , "[%ld] cron started\n", (long) getpid());

 }
 else if (NoFork == 0) {
  switch (fork()) {
  case -1:
   log_it("CRON", pid, "DEATH", "can't fork", 
                                             (*__errno_location ())
                                                  );
   exit(0);
   break;
  case 0:

   (void) setsid();
   if ((fd = open(
                 "/dev/null"
                              , 
                                02
                                      , 0)) >= 0) {
    (void) dup2(fd, 0);
    (void) dup2(fd, 1);
    (void) dup2(fd, 2);
    if (fd != 2)
     (void) close(fd);
   }
   break;
  default:

   _exit(0);
  }
 }

 log_it("CRON", getpid(), "STARTUP", "1.6.1", 0);

 if (!SyslogOutput && MailCmd[0] == '\0' && access("/usr/sbin/sendmail", 
                                                                        1
                                                                            ) != 0) {
  SyslogOutput=1;
  log_it("CRON", pid, "INFO","Syslog will be used instead of sendmail.", 0);
 }

 pid = getpid();


 if (gettimeofday(&tv, &tz) != 0)
  tv.tv_usec = 0;
 srandom((unsigned int)(pid + tv.tv_usec));
 RandomScale = (double)random() / (double)(1lu << 31);
 snprintf(buf, sizeof(buf), "RANDOM_DELAY will be scaled with factor %d%% if used.", (int)(RandomScale*100));
 log_it("CRON", pid, "INFO", buf, 0);

 acquire_daemonlock(0);

 fd = -1;
 database.head = 
                ((void *)0)
                    ;
 database.tail = 
                ((void *)0)
                    ;
 database.mtime = (time_t) 0;

 load_database(&database);

 set_time(1);
 run_reboot_jobs(&database);
 timeRunning = virtualTime = clockTime;
 oldGMToff = GMToff;
 while (!got_sigintterm) {
  int timeDiff;
  enum timejump wakeupKind;


  do {
   cron_sleep(timeRunning + 1, &database);
   set_time(0);
  } while (!got_sigintterm && clockTime == timeRunning);
  if (got_sigintterm)
   break;
  timeRunning = clockTime;





  timeDiff = timeRunning - virtualTime;
  check_orphans(&database);
  load_database(&database);



  if (timeDiff == 1) {
   virtualTime = timeRunning;
   oldGMToff = GMToff;
   find_jobs(virtualTime, &database, 1, 1, oldGMToff);
  }
  else {
   if (timeDiff > (3 * (59 - 0 + 1)) || timeDiff < -(3 * (59 - 0 + 1)))
    wakeupKind = large;
   else if (timeDiff > 5)
    wakeupKind = medium;
   else if (timeDiff > 0)
    wakeupKind = small;
   else
    wakeupKind = negative;

   switch (wakeupKind) {
   case small:





    if ((DebugFlags & (0x0002)) != 0) printf ("[%ld], normal case %d minutes to go\n", (long) pid, timeDiff)
                            ;
    do {
     if (job_runqueue())
      sleep(10);
     virtualTime++;
     if (virtualTime >= timeRunning)

      oldGMToff = GMToff;
     find_jobs(virtualTime, &database, 1, 1, oldGMToff);
    } while (virtualTime < timeRunning);
    break;

   case medium:
    if ((DebugFlags & (0x0002)) != 0) printf ("[%ld], DST begins %d minutes to go\n", (long) pid, timeDiff)
                            ;

    find_jobs(timeRunning, &database, 1, 0, GMToff);


    do {
     if (job_runqueue())
      sleep(10);
     virtualTime++;
     if (virtualTime >= timeRunning)

      oldGMToff = GMToff;
     find_jobs(virtualTime, &database, 0, 1, oldGMToff);
     set_time(0);
    } while (virtualTime < timeRunning && clockTime == timeRunning);
    break;

   case negative:
    if ((DebugFlags & (0x0002)) != 0) printf ("[%ld], DST ends %d minutes to go\n", (long) pid, timeDiff)
                            ;
    find_jobs(timeRunning, &database, 1, 0, GMToff);
    break;
   default:




    if ((DebugFlags & (0x0002)) != 0) printf ("[%ld], clock jumped\n", (long) pid);
    virtualTime = timeRunning;
    oldGMToff = GMToff;
    find_jobs(timeRunning, &database, 1, 1, GMToff);
   }
  }


  job_runqueue();

  handle_signals(&database);
 }
 log_it("CRON", pid, "INFO", "Shutting down", 0);

 (void) unlink("/usr/local/var/run" "/" "crond.pid");

 return 0;
}

static void run_reboot_jobs(cron_db * db) {
 user *u;
 entry *e;
 int reboot;
 pid_t pid = getpid();


 if (access("/usr/local/var/run" "/" "cron.reboot", 
                        0
                            ) == 0) {
  log_it("CRON", pid, "INFO",
   "@reboot jobs will be run at computer's startup.", 0);
  return;
 }

 if ((reboot = creat("/usr/local/var/run" "/" "cron.reboot", 
                                 0400 
                                         & 
                                           0200
                                                  )) < 0)
  log_it("CRON", pid, "INFO", "Can't create lock for reboot jobs.",
   
  (*__errno_location ())
       );
 else
  close(reboot);

 for (u = db->head; u != 
                        ((void *)0)
                            ; u = u->next) {
  for (e = u->crontab; e != 
                           ((void *)0)
                               ; e = e->next) {
   if (e->flags & 0x10)
    job_add(e, u);
  }
 }
 (void) job_runqueue();
}

static void find_jobs(int vtime, cron_db * db, int doWild, int doNonWild, long vGMToff) {
 char *orig_tz, *job_tz;
 struct tm *tm;
 int minute, hour, dom, month, dow;
 user *u;
 entry *e;
 orig_tz = getenv("TZ");







 for (u = db->head; u != 
                        ((void *)0)
                            ; u = u->next) {
  for (e = u->crontab; e != 
                           ((void *)0)
                               ; e = e->next) {
   time_t virtualSecond = (time_t)(vtime - e->delay) * (time_t)60;
   time_t virtualGMTSecond = virtualSecond - vGMToff;
   job_tz = env_get("CRON_TZ", e->envp);
   do { char *t = job_tz; if (t != 
  ((void *)0) 
  && *t != '\0') { setenv("TZ", t, 1); tm = localtime(&virtualGMTSecond); } else { if ((orig_tz) != 
  ((void *)0)
  ) setenv("TZ", (orig_tz), 1); else unsetenv("TZ"); tm = gmtime(&virtualSecond); } minute = tm->tm_min -0; hour = tm->tm_hour -0; dom = tm->tm_mday -1; month = tm->tm_mon +1 -1; dow = tm->tm_wday -0; } while (0);


   if (((e->minute)[((minute) >> 3)] & (1 << ((minute)&0x7))) &&
    ((e->hour)[((hour) >> 3)] & (1 << ((hour)&0x7))) &&
    ((e->month)[((month) >> 3)] & (1 << ((month)&0x7))) &&
    (((e->flags & 0x04) || (e->flags & 0x08))
     ? (((e->dow)[((dow) >> 3)] & (1 << ((dow)&0x7))) && ((e->dom)[((dom) >> 3)] & (1 << ((dom)&0x7))))
      : (((e->dow)[((dow) >> 3)] & (1 << ((dow)&0x7))) || ((e->dom)[((dom) >> 3)] & (1 << ((dom)&0x7))))
    )
   ) {
    if (job_tz != 
                 ((void *)0) 
                      && vGMToff != GMToff)



     continue;

    if ((doNonWild &&
      !(e->flags & (0x01 | 0x02))) ||
     (doWild && (e->flags & (0x01 | 0x02))))
     job_add(e, u);
   }
  }
 }
 if (orig_tz != 
               ((void *)0)
                   )
  setenv("TZ", orig_tz, 1);
 else
  unsetenv("TZ");
}






static void set_time(int initialize) {
 struct tm tm;
 static int isdst;

 StartTime = time(
                 ((void *)0)
                     );


 tm = *localtime(&StartTime);
 if (initialize || tm.tm_isdst != isdst) {
  isdst = tm.tm_isdst;
  GMToff = ((&tm)->tm_gmtoff);
  if ((DebugFlags & (0x0002)) != 0) printf ("[%ld] GMToff=%ld\n", (long) getpid(), (long) GMToff);
 }
 clockTime = (int)((StartTime + GMToff) / (time_t) 60);
}




static void cron_sleep(int target, cron_db * db) {
 time_t t1, t2;
 int seconds_to_wait;

 t1 = time(
          ((void *)0)
              ) + GMToff;
 seconds_to_wait = (int) (target * 60 - t1) + 1;
 if ((DebugFlags & (0x0002)) != 0) printf ("[%ld] Target time=%ld, sec-to-wait=%d\n", (long) getpid(), (long) target * 60, seconds_to_wait)

                    ;

 while (seconds_to_wait > 0 && seconds_to_wait < 65) {
  sleep((unsigned int) seconds_to_wait);

  if (got_sigintterm)
   return;






  handle_signals(db);

  t2 = time(
           ((void *)0)
               ) + GMToff;
  seconds_to_wait -= (int) (t2 - t1);
  t1 = t2;
 }
}

static void sighup_handler(int x __attribute__ ((__unused__))) {
 got_sighup = 1;
}

static void sigchld_handler(int x __attribute__ ((__unused__))) {
 got_sigchld = 1;
}

static void sigintterm_handler(int x __attribute__ ((__unused__))) {
 got_sigintterm = 1;
}

static void sigchld_reaper(void) {
 int waiter;
 pid_t pid;

 do {
  pid = waitpid(-1, &waiter, 
                            1
                                   );
  switch (pid) {
  case -1:
   if (
      (*__errno_location ()) 
            == 
               4
                    )
    continue;
   if ((DebugFlags & (0x0004)) != 0) printf ("[%ld] sigchld...no children\n", (long) getpid());
   break;
  case 0:
   if ((DebugFlags & (0x0004)) != 0) printf ("[%ld] sigchld...no dead kids\n", (long) getpid());
   break;
  default:
   if ((DebugFlags & (0x0004)) != 0) printf ("[%ld] sigchld...pid #%ld died, stat=%d\n", (long) getpid(), (long) pid, 
  (((
  waiter
  ) & 0xff00) >> 8)
  )

                                                       ;
   break;
  }
 } while (pid > 0);
}

static void parse_args(int argc, char *argv[]) {
 int argch;

 while (-1 != (argch = getopt(argc, argv, "hnfpsiPx:m:cV"))) {
  switch (argch) {
   case 'x':
    if (!set_debug_flags(optarg))
     usage();
    break;
   case 'n':
   case 'f':
    NoFork = 1;
    break;
   case 'p':
    PermitAnyCrontab = 1;
    break;
   case 's':
    SyslogOutput = 1;
    break;
   case 'i':
    DisableInotify = 1;
    break;
   case 'P':
    ChangePath = 0;
    break;
   case 'm':
    strncpy(MailCmd, optarg, 131072);
    break;
   case 'c':
    EnableClustering = 1;
    break;
   case 'V':
    puts("cronie 1.6.1");
    exit(
        0
                    );
   case 'h':
   default:
    usage();
    break;
  }
 }
}
