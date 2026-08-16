




 
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
void do_command(entry *e, user *u) {

 (void)e;
 (void)u;
}
const char *flagname[]= {
 "MIN_STAR",
 "HR_STAR",
 "DOM_STAR",
 "DOW_STAR",
 "WHEN_REBOOT",
 "DONT_LOG"
};

void printflags(char *indent, int flags) {
 size_t f;
 int first = 1;

 printf("%s    flagnames:", indent);
 for (f = 0; f < sizeof(flagname)/sizeof(char *); f++)
  if (flags & (int)1 << f) {
   printf("%s%s", first ? " " : "|", flagname[f]);
   first = 0;
  }
 printf("\n");
}




void printentry(char *indent, entry *e, time_t next) {
 printf("%s  - user: %s\n", indent, e->pwd->pw_name);
 printf("%s    cmd: \"%s\"\n", indent, e->cmd);
 printf("%s    flags: 0x%02X\n", indent, e->flags);
 printflags(indent, e->flags);
 printf("%s    delay: %d\n", indent, e->delay);
 printf("%s    next: %ld\n", indent, (long)next);
 printf("%s    nextstring: ", indent);
 printf("%s", asctime(localtime(&next)));
}




void printcrontab(user *u) {
 printf("  - user: \"%s\"\n", u->name);
 printf("    crontab: %s\n", u->tabname);
 printf("    system: %d\n", u->system);
 printf("    entries:\n");
}
int matchday(entry *e, time_t time) {
 struct tm current;

 localtime_r(&time, &current);

 if (e->flags & 0x08)
  return ((e->dom)[((current.tm_mday - 1) >> 3)] & (1 << ((current.tm_mday - 1)&0x7)));
 if (e->flags & 0x04)
  return ((e->dow)[((current.tm_wday) >> 3)] & (1 << ((current.tm_wday)&0x7)));
 return ((e->dom)[((current.tm_mday - 1) >> 3)] & (1 << ((current.tm_mday - 1)&0x7))) ||
  ((e->dow)[((current.tm_wday) >> 3)] & (1 << ((current.tm_wday)&0x7)));
}




time_t nextmatch(entry *e, time_t start, time_t end) {
 time_t time;
 struct tm current;

 for (time = start; time <= end; ) {
  localtime_r(&time, &current);


  if (!((e->month)[((current.tm_mon) >> 3)] & (1 << ((current.tm_mon)&0x7)))) {
   current.tm_mon++;
   if (current.tm_mon >= 12) {
    current.tm_year++;
    current.tm_mon = 0;
   }
   current.tm_mday = 1;
   current.tm_hour = 0;
   current.tm_min = 0;
   time = mktime(&current);
   continue;
  }


  if (!matchday(e, time) && !matchday(e, time + 24 * 60 * 60)) {
   time += 24 * 60 * 60;
   continue;
  }





  if (((e->month)[((current.tm_mon) >> 3)] & (1 << ((current.tm_mon)&0x7))) &&
   matchday(e, time) &&
   ((e->hour)[((current.tm_hour) >> 3)] & (1 << ((current.tm_hour)&0x7))) &&
   ((e->minute)[((current.tm_min) >> 3)] & (1 << ((current.tm_min)&0x7)))
  )
   return time;


  time += 60;
 }

 return -1;
}




int matchuser(char *user_name, char *list) {
 char *pos;
 size_t l = strlen(user_name);

 for (pos = list; (pos = strstr(pos, user_name)) != 
                                                   ((void *)0)
                                                       ; pos += l) {
  if ((pos != list) && (*(pos - 1) != ','))
   continue;
  if ((pos[l] != '\0') && (pos[l] != ','))
   continue;
  return 1;
 }
 return 0;
}




time_t cronnext(cron_db database,
  time_t start, time_t end,
  char *include, char *exclude, char *command, int flags) {
 time_t closest, next;
 user *u;
 entry *e;
 char *indent = "";

 if (flags & 0x02) {
  printf("crontabs:\n");
  indent = "    ";
 }
 else if (flags & 0x08)
  printf("jobs:\n");


 closest = -1;
 for (u = database.head; u; u = u->next) {
  if (include && !matchuser(u->name, include))
   continue;
  if (exclude && matchuser(u->name, exclude))
   continue;
  if (!(flags & 0x04) && u->system)
   continue;

  if (flags & 0x02)
   printcrontab(u);

  for (e = u->crontab; e; e = e->next) {
   if (command && strstr(e->cmd, command) == 
                                            ((void *)0)
                                                )
    continue;
   for (next = nextmatch(e, start, end);
        next <= end;
        next = nextmatch(e, next + 60, end)) {
    if (next < 0)
     break;
    if (closest < 0 || next < closest)
     closest = next;
    if (flags & 0x01)
     printentry(indent, e, next);
    if (! (flags & 0x08))
     break;
   }
  }
 }

 return closest;
}




cron_db database(int installed, char **additional) {
 cron_db db = {
              ((void *)0)
                  , 
                    ((void *)0)
                        , (time_t) 0};
 struct passwd pw;
 int fd;
 struct stat ss;
 user *u;

 if (installed)
  load_database(&db);

 for ( ; *additional != 
                       ((void *)0)
                           ; additional++) {
  fd = open(*additional, 
                        00
                                );
  if (fd == -1) {
   perror(*additional);
   continue;
  }
  fstat(fd, &ss);
  if (
     ((((
     ss.st_mode
     )) & 0170000) == (0040000))
                        ) {
   fprintf(
          stderr
                , "%s is a directory - skipping\n", *additional);
   close(fd);
   continue;
  }
  memset(&pw, 0, sizeof(pw));
  pw.pw_name = *additional;
  pw.pw_passwd = "";
  pw.pw_dir = ".";
  u = load_user(fd, &pw, *additional, *additional, *additional);
  if (u == 
          ((void *)0)
              ) {
   printf("cannot load crontab %s\n", *additional);
   continue;
  }
  link_user(&db, u);
 }

 return db;
}

void usage() {
 fprintf(
        stderr
              , "Find the time of the next scheduled cron job.\n");
 fprintf(
        stderr
              , "Usage:\n");
 fprintf(
        stderr
              , " cronnext [options] [file ...]\n");
 fprintf(
        stderr
              , "\n");
 fprintf(
        stderr
              , "Options:\n");
 fprintf(
        stderr
              , " -i users  include only the crontab of these users\n");
 fprintf(
        stderr
              , " -e users  exclude the crontab of these users\n");
 fprintf(
        stderr
              , " -s        do not include the system crontab\n");
 fprintf(
        stderr
              , " -a        examine installed crontabs even if files are given\n");
 fprintf(
        stderr
              , " -t time   start from this time (seconds since epoch)\n");
 fprintf(
        stderr
              , " -q time   end check at this time (seconds since epoch)\n");
 fprintf(
        stderr
              , " -j cmd    only check jobs that contain cmd as a substring\n");
 fprintf(
        stderr
              , " -l        print next jobs to be executed\n");
 fprintf(
        stderr
              , " -c        print next execution of each job\n");
 fprintf(
        stderr
              , " -f        print all jobs executed in the given interval\n");
 fprintf(
        stderr
              , " -h        this help\n");
 fprintf(
        stderr
              , " -V        print version and exit\n");
}




int main(int argn, char *argv[]) {
 int opt;
 char *include, *exclude, *command;
 int flags;
 time_t start, next, end = 0;
 int endtime, printjobs;
 cron_db db;
 int installed = 0;

 include = 
          ((void *)0)
              ;
 exclude = 
          ((void *)0)
              ;
 command = 
          ((void *)0)
              ;
 flags = 0x04;
 endtime = 0;
 printjobs = 0;
 start = time(
             ((void *)0)
                 ) / 60 * 60;

 while (-1 != (opt = getopt(argn, argv, "i:e:ast:q:j:lcfhV"))) {
  switch (opt) {
  case 'i':
   include = optarg;
   break;
  case 'e':
   exclude = optarg;
   break;
  case 'a':
   installed = 1;
   break;
  case 's':
   flags &= ~0x04;
   break;
  case 't':
   start = atoi(optarg) / 60 * 60;
   break;
  case 'q':
   end = atoi(optarg) / 60 * 60;
   endtime = 1;
   break;
  case 'j':
   command = optarg;
   break;
  case 'l':
   printjobs = 1;
   break;
  case 'c':
   flags |= 0x01 | 0x02;
   break;
  case 'f':
   flags |= 0x08 | 0x01;
   break;
  case 'h':
   usage();
   return 
         0
                     ;
  case 'V':
   puts("cronie 1.6.1");
   return 
         0
                     ;
  default:
   fprintf(
          stderr
                , "unrecognized option: %s\n",
    argv[optind - 1]);
   usage();
   exit(
       1
                   );
  }
 }

 if (flags & 0x08 && !endtime) {
  fprintf(
         stderr
               , "no ending time specified: -f requires -q\n");
  usage();
  exit(
      1
                  );
 }




 if (!endtime)
  end = start + 8 * 12 * 31 * 24 * 60 * 60;


 if (flags & 0x02) {
  printf("spool: %s\n", "/usr/local/var/spool/cron");
  set_debug_flags("");
 }




 db = database(installed || argv[optind] == 
                                           ((void *)0)
                                               , argv + optind);


 next = cronnext(db, start, end, include, exclude, command, flags);


 if (next == -1)
  return 
        1
                    ;
 else
  printf("next: %ld\n", (long) next);


 if (printjobs) {
  printf("nextjobs:\n");
  cronnext(db, next, next, include, exclude, command, (flags & 0x04) | 0x01);
 }

 return 
       0
                   ;
}
