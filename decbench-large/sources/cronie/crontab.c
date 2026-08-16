





int expand_envvar(const char *, char *, size_t);
typedef unsigned char bitstr_t;
extern char *tzname[2];
int getopt(int, char * const *, const char *);



extern char *optarg;
extern int optind, opterr, optopt;




extern int flock(int, int);







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



enum opt_t {
 opt_unknown, opt_list, opt_delete, opt_edit, opt_replace, opt_hostset,
 opt_hostget, opt_test
};


static const char *Options[] = {
 "???", "list", "delete", "edit", "replace", "hostset", "hostget", "test"
};




static const char *getoptargs = "u:lerincx:VT";
static pid_t Pid;
static char User[256], RealUser[256];
static char Filename[
                    4096
                             ], TempFilename[
                                             4096
                                                      ];
static char Host[64];
static FILE *NewCrontab;
static int CheckErrorCount;
static int PromptOnDelete;
static int HostSpecified;
static enum opt_t Option;
static struct passwd *pw;
static void list_cmd(void),
delete_cmd(void),
edit_cmd(void),
poke_daemon(void),
check_error(const char *), parse_args(int c, char *v[]),
die(int) __attribute__ ((__noreturn__));
static int replace_cmd(void), hostset_cmd(void), hostget_cmd(void),
test_cmd(void), check_syntax(FILE *);
static char *host_specific_filename(const char *prefix,
const char *suffix);
static const char *tmp_path(void);

static void usage(const char *msg) __attribute__ ((__noreturn__));
static void usage(const char *msg) {
 fprintf(
        stderr
              , "%s: usage error: %s\n", ProgramName, msg);
 fprintf(
        stderr
              , "Usage:\n");
 fprintf(
        stderr
              , " %s [options] file\n", ProgramName);
 fprintf(
        stderr
              , " %s [options]\n", ProgramName);
 fprintf(
        stderr
              , " %s -n [hostname]\n", ProgramName);
 fprintf(
        stderr
              , "\n");
 fprintf(
        stderr
              , "Options:\n");
 fprintf(
        stderr
              , " -u <user>  define user\n");
 fprintf(
        stderr
              , " -e         edit user's crontab\n");
 fprintf(
        stderr
              , " -l         list user's crontab\n");
 fprintf(
        stderr
              , " -r         delete user's crontab\n");
 fprintf(
        stderr
              , " -i         prompt before deleting\n");
 fprintf(
        stderr
              , " -n <host>  set host in cluster to run users' crontabs\n");
 fprintf(
        stderr
              , " -c         get host in cluster to run users' crontabs\n");
 fprintf(
        stderr
              , " -T <file>  test a crontab file syntax\n");



 fprintf(
        stderr
              , " -V         print version and exit\n");

 fprintf(
        stderr
              , " -x <mask>  enable debugging\n");

 fprintf(
        stderr
              , "\nDefault operation is replace, per 1003.2\n");
 exit(1);
}

int main(int argc, char *argv[]) {
 int exitstatus;

 if ((ProgramName = strrchr(argv[0], '/')) == 
                                             ((void *)0)
                                                 ) {
  ProgramName = argv[0];
 }
 else {
  ++ProgramName;
 }

 Pid = getpid();
 MailCmd[0] = '\0';
 cron_default_mail_charset[0] = '\0';

 setlocale(
          6
                , "");




 parse_args(argc, argv);
 check_spool_dir();
 if (!allowed(RealUser, "/usr/local/etc/cron.allow", "/usr/local/etc/cron.deny")) {
  fprintf(
         stderr
               ,
   "You (%s) are not allowed to use this program (%s)\n",
   User, ProgramName);
  fprintf(
         stderr
               , "See crontab(1) for more information\n");
  log_it(RealUser, Pid, "AUTH", "crontab command not allowed", 0);
  exit(1);
 }
 exitstatus = 0;
 switch (Option) {
 case opt_unknown:
  exitstatus = 1;
  break;
 case opt_list:
  list_cmd();
  break;
 case opt_delete:
  delete_cmd();
  break;
 case opt_edit:
  edit_cmd();
  break;
 case opt_replace:
  if (replace_cmd() < 0)
   exitstatus = 1;
  break;
 case opt_hostset:
  if (hostset_cmd() < 0)
   exitstatus = 1;
  break;
 case opt_hostget:
  if (hostget_cmd() < 0)
   exitstatus = 1;
  break;
 case opt_test:
  if (test_cmd() < 0)
   exitstatus = 1;
  break;
 default:
  abort();
 }



 exit(exitstatus);
               }

static void parse_args(int argc, char *argv[]) {
 int argch;

 if (!(pw = getpwuid(getuid()))) {
  fprintf(
         stderr
               , "%s: your UID isn't in the passwd file.\n",
   ProgramName);
  fprintf(
         stderr
               , "bailing out.\n");
  exit(1);
 }
 if (strlen(pw->pw_name) >= sizeof User) {
  fprintf(
         stderr
               , "username too long\n");
  exit(1);
 }
 strcpy(User, pw->pw_name);
 strcpy(RealUser, User);
 Filename[0] = '\0';
 Option = opt_unknown;
 PromptOnDelete = 0;
 HostSpecified = 0;
 while (-1 != (argch = getopt(argc, argv, getoptargs))) {
  switch (argch) {

  case 'x':
   if (!set_debug_flags(optarg))
    usage("bad debug option");
   break;

  case 'u':
   if (getuid() != 0) {
    fprintf(
           stderr
                 , "must be privileged to use -u\n");
    exit(1);
   }







   if (Option == opt_hostset || Option == opt_hostget ||
    Option == opt_test) {
    fprintf(
           stderr
                 , "cannot use -u with -n, -c or -T\n");
    exit(1);
   }

   if (!(pw = getpwnam(optarg))) {
    fprintf(
           stderr
                 , "%s:  user `%s' unknown\n",
     ProgramName, optarg);
    exit(1);
   }
   if (strlen(optarg) >= sizeof User)
    usage("username too long");
   (void) strcpy(User, optarg);
   break;
  case 'l':
   if (Option != opt_unknown)
    usage("only one operation permitted");
   Option = opt_list;
   break;
  case 'r':
   if (Option != opt_unknown)
    usage("only one operation permitted");
   Option = opt_delete;
   break;
  case 'e':
   if (Option != opt_unknown)
    usage("only one operation permitted");
   Option = opt_edit;
   break;
  case 'T':
   if (Option != opt_unknown)
    usage("only one operation permitted");
   Option = opt_test;
   break;
  case 'i':
   PromptOnDelete = 1;
   break;
  case 'n':
   if (getuid() != 0) {
    fprintf(
           stderr
                 , "must be privileged to set host with -n\n");
    exit(1);
   }
   if (Option != opt_unknown)
    usage("only one operation permitted");
   if (strcmp(User, RealUser) != 0) {
    fprintf(
           stderr
                 , "cannot use -u with -n or -c\n");
    exit(1);
   }
   Option = opt_hostset;
   break;
  case 'c':
   if (Option != opt_unknown)
    usage("only one operation permitted");
   if (strcmp(User, RealUser) != 0) {
    fprintf(
           stderr
                 , "cannot use -u with -n or -c\n");
    exit(1);
   }
   Option = opt_hostget;
   break;
  case 'V':
   puts("cronie 1.6.1");
   exit(
       0
                   );
  default:
   usage("unrecognized option");
  }
 }

 endpwent();

 if (Option == opt_hostset && argv[optind] != 
                                             ((void *)0)
                                                 ) {
  HostSpecified = 1;
  if (strlen(argv[optind]) >= sizeof Host)
   usage("hostname too long");
  (void) strcpy(Host, argv[optind]);
  optind++;
 }

 if (Option == opt_unknown) {

  Option = opt_replace;
 }

 if (Option == opt_replace || Option == opt_test) {
  if (argv[optind] != 
                     ((void *)0)
                         ) {
   if (strlen(argv[optind]) >= sizeof Filename)
    usage("filename too long");
   (void) strcpy(Filename, argv[optind]);
   optind++;
  }
  else if (isatty(
                 0
                             )) {
   usage("file name or - (for stdin) must be specified");
  }
  else {
   strcpy(Filename, "-");
  }
 }

 if (Option != opt_unknown && argv[optind] != 
                                             ((void *)0)
                                                 ) {
  usage("no arguments permitted after this option");
 }

 if (Filename[0] != '\0') {
  if (!strcmp(Filename, "-"))
   NewCrontab = 
               stdin
                    ;
  else {







   struct stat sb;

   if (swap_uids() < 0) {
    perror("swapping uids");
    exit(1);
   }
   if (!(NewCrontab = fopen(Filename, "r"))) {
    perror(Filename);
    exit(1);
   }
   if (fstat(fileno(NewCrontab), &sb) < 0) {
    perror(Filename);
    exit(1);
   }
   if ((sb.st_mode & 
                    0170000
                          ) == 
                               0040000
                                      ) {
    fprintf(
           stderr
                 ,
     "invalid crontab file: '%s' is a directory\n", Filename);
    fclose(NewCrontab);
    exit(1);
   }
   if (swap_uids_back() < 0) {
    perror("swapping uids back");
    exit(1);
   }
  }
 }

 if ((DebugFlags & (0x0020)) != 0) printf ("user=%s, file=%s, option=%s\n", User, Filename, Options[(int) Option])
                                          ;
}

static void list_cmd(void) {
 char n[
       4096
                ];
 FILE *f;
 int ch;
 const int colorize = isatty(1) && getenv("NO_COLOR") == 
                                                             ((void *)0)
                                                                 ;
 int new_line = 1;
 int in_comment = 0;

 log_it(RealUser, Pid, "LIST", User, 0);
 if (!glue_strings(n, sizeof n, "/usr/local/var/spool/cron", User, '/')) {
  fprintf(
         stderr
               , "path too long\n");
  exit(1);
 }
 if (!(f = fopen(n, "r"))) {
  if (
     (*__errno_location ()) 
           == 
              2
                    )
   fprintf(
          stderr
                , "no crontab for %s\n", User);
  else
   perror(n);
  exit(1);
 }



 {if ((DebugFlags & (0x0008|0x0001)) != 0) printf ("linenum=%d\n",1); LineNumber = 1; };
 while (
       (-1) 
           != (ch = get_char(f))) {
  if (colorize) {
   if (!in_comment && new_line && ch == '#') {
    in_comment = 1;
    fputs("\x1B[34;1m", 
                        stdout
                              );
   }
   if (in_comment && ch == '\n') {
    in_comment = 0;
    fputs("\x1B[0m", 
                      stdout
                            );
   }
  }
  putchar(ch);
  new_line = ch == '\n';
 }

 if (colorize && !new_line) {
  putchar('\n');
  fputs("\x1B[31;1m" "No end-of-line character at the end of file"
   "\x1B[0m", 
               stdout
                     );
  putchar('\n');
 }
 fclose(f);
}

static void delete_cmd(void) {
 char n[
       4096
                ] = "";
 if (PromptOnDelete == 1) {
  printf("crontab: really delete %s's crontab? ", User);
  fflush(
        stdout
              );
  if ((fgets(n, 
               4096 
                         - 1, 
                              stdin
                                   ) == 
                                        ((void *)0)
                                            )
   || ((n[0] != 'Y') && (n[0] != 'y'))
   )
   exit(0);
 }

 log_it(RealUser, Pid, "DELETE", User, 0);
 if (!glue_strings(n, sizeof n, "/usr/local/var/spool/cron", User, '/')) {
  fprintf(
         stderr
               , "path too long\n");
  exit(1);
 }
 if (unlink(n) != 0) {
  if (
     (*__errno_location ()) 
           == 
              2
                    )
   fprintf(
          stderr
                , "no crontab for %s\n", User);
  else
   perror(n);
  exit(1);
 }
 poke_daemon();
}

static void check_error(const char *msg) {
 CheckErrorCount++;
 fprintf(
        stderr
              , "\"%s\":%d: %s\n", Filename, LineNumber - 1, msg);
}

static const char *tmp_path(void) {
 const char *tmpdir = 
                     ((void *)0)
                         ;

 if ((getuid() == geteuid()) && (getgid() == getegid())) {
  tmpdir = getenv("TMPDIR");
 }
 return tmpdir ? tmpdir : "/tmp";
}

static char *host_specific_filename(const char *prefix, const char *suffix) {






 static char safename[
                     4096
                              ];
 char hostname[
              4096
                       ];

 if (gethostname(hostname, sizeof hostname) != 0)
  return 
        ((void *)0)
            ;

 if (prefix) {
  if (!glue_strings(safename, sizeof safename, prefix, hostname, '.'))
   return 
         ((void *)0)
             ;
  strcpy(hostname, safename);
 }
 if (suffix) {
  if (!glue_strings(safename, sizeof safename, hostname, suffix, '.'))
   return 
         ((void *)0)
             ;
 }

 return safename;
}

static void edit_cmd(void) {
 char n[
       4096
                ], q[131072];
 const char *editor;
 FILE *f;
 int ch = '\0', t;
 struct stat statbuf;
 struct utimbuf utimebuf;
 int waiter;
 pid_t pid, xpid;

 log_it(RealUser, Pid, "BEGIN EDIT", User, 0);
 if (!glue_strings(n, sizeof n, "/usr/local/var/spool/cron", User, '/')) {
  fprintf(
         stderr
               , "path too long\n");
  exit(1);
 }
 if (!(f = fopen(n, "r"))) {
  if (
     (*__errno_location ()) 
           != 
              2
                    ) {
   perror(n);
   exit(1);
  }
  fprintf(
         stderr
               , "no crontab for %s - using an empty one\n", User);
  if (!(f = fopen(
                 "/dev/null"
                              , "r"))) {
   perror(
         "/dev/null"
                      );
   exit(1);
  }
 }


 (void) signal(
              1
                    , 
                      ((__sighandler_t) 1)
                             );
 (void) signal(
              2
                    , 
                      ((__sighandler_t) 1)
                             );
 (void) signal(
              3
                     , 
                       ((__sighandler_t) 1)
                              );

 if (!glue_strings(Filename, sizeof Filename, tmp_path(),
   "crontab.XXXXXX", '/')) {
  fprintf(
         stderr
               , "path too long\n");
  exit(1);
 }
 if (swap_uids() == -1) {
  perror("swapping uids");
  exit(1);
 }
 if (-1 == (t = mkstemp(Filename))) {
  perror(Filename);
  goto fatal;
 }

 if (swap_uids_back() == -1) {
  perror("swapping uids back");
  goto fatal;
 }
 if (!(NewCrontab = fdopen(t, "r+"))) {
  perror("fdopen");
  goto fatal;
 }

 {if ((DebugFlags & (0x0008|0x0001)) != 0) printf ("linenum=%d\n",1); LineNumber = 1; };






 if (
    (-1) 
        != ch)
  while (
        (-1) 
            != (ch = get_char(f)))
   putc(ch, NewCrontab);
 fclose(f);
 if (fflush(NewCrontab) < 0) {
  perror(Filename);
  exit(1);
 }
 if (swap_uids() == -1) {
  perror("swapping uids");
  exit(1);
 }

 utimebuf.actime = 0;
 utimebuf.modtime = 0;
 utime(Filename, &utimebuf);
 if (swap_uids_back() == -1) {
  perror("swapping uids");
  exit(1);
 }
  again:
 rewind(NewCrontab);
 if (ferror(NewCrontab)) {
  fprintf(
         stderr
               , "%s: error while writing new crontab to %s\n",
   ProgramName, Filename);
   fatal:
  unlink(Filename);
  exit(1);
 }

 if (((editor = getenv("VISUAL")) == 
                                    ((void *)0) 
                                         || *editor == '\0') &&
  ((editor = getenv("EDITOR")) == 
                                 ((void *)0) 
                                      || *editor == '\0')) {
  editor = "/usr/bin/vi";
 }
 switch (pid = fork()) {
 case -1:
  perror("fork");
  goto fatal;
 case 0:

  if (setgid(getgid()) < 0) {
   perror("setgid(getgid())");
   exit(1);
  }
  if (setuid(getuid()) < 0) {
   perror("setuid(getuid())");
   exit(1);
  }
  if (!glue_strings(q, sizeof q, editor, Filename, ' ')) {
   fprintf(
          stderr
                , "%s: editor command line too long\n", ProgramName);
   exit(1);
  }
  execlp(
        "/bin/sh"
                    , 
                      "/bin/sh"
                                  , "-c", q, (char *) 0);
  perror(editor);
  exit(1);
                 default:

  break;
 }


 for (;;) {
  xpid = waitpid(pid, &waiter, 0);
  if (xpid == -1) {
   if (
      (*__errno_location ()) 
            != 
               4
                    )
    fprintf(
           stderr
                 ,
     "%s: waitpid() failed waiting for PID %ld from \"%s\": %s\n",
     ProgramName, (long) pid, editor, strerror(
                                              (*__errno_location ())
                                                   ));
  }
  else if (xpid != pid) {
   fprintf(
          stderr
                , "%s: wrong PID (%ld != %ld) from \"%s\"\n",
    ProgramName, (long) xpid, (long) pid, editor);
   goto fatal;
  }
  else if (
          (((
          waiter
          ) & 0x7f) == 0) 
                            && 
                               (((
                               waiter
                               ) & 0xff00) >> 8)
                                                  ) {
   fprintf(
          stderr
                , "%s: \"%s\" exited with status %d\n",
    ProgramName, editor, 
                        (((
                        waiter
                        ) & 0xff00) >> 8)
                                           );
   goto fatal;
  }
  else if (
          (((signed char) (((
          waiter
          ) & 0x7f) + 1) >> 1) > 0)
                             ) {
   fprintf(
          stderr
                ,
    "%s: \"%s\" killed; signal %d (%score dumped)\n",
    ProgramName, editor, 
                        ((
                        waiter
                        ) & 0x7f)
                                        ,
    
   ((
   waiter
   ) & 0x80) 
                     ? "" : "no ");
   goto fatal;
  }
  else
   break;
 }
 (void) signal(
              1
                    , 
                      ((__sighandler_t) 0)
                             );
 (void) signal(
              2
                    , 
                      ((__sighandler_t) 0)
                             );
 (void) signal(
              3
                     , 
                       ((__sighandler_t) 0)
                              );




 if (lstat(Filename, &statbuf) < 0) {
  perror("lstat");
  goto fatal;
 }

 if (!
     ((((
     statbuf.st_mode
     )) & 0170000) == (0100000))
                             ) {
  fprintf(
         stderr
               , "%s: illegal crontab\n", ProgramName);
  goto remove;
 }

 if (statbuf.
            st_mtim.tv_sec 
                     == 0) {
  fprintf(
         stderr
               , "%s: no changes made to crontab\n", ProgramName);
  goto remove;
 }

 fprintf(
        stderr
              , "%s: installing new crontab\n", ProgramName);
 fclose(NewCrontab);
 if (swap_uids() < 0) {
  perror("swapping uids");
  goto remove;
 }
 if (!(NewCrontab = fopen(Filename, "r+"))) {
  perror("cannot read new crontab");
  goto remove;
 }
 if (swap_uids_back() < 0) {
  perror("swapping uids back");
  exit(1);
 }
 if (NewCrontab == 
                  ((void *)0)
                      ) {
  perror("fopen");
  goto fatal;
 }
 switch (replace_cmd()) {
 case 0:
  break;
 case -1:
  for (;;) {
   printf("Do you want to retry the same edit? (Y/N) ");
   fflush(
         stdout
               );
   q[0] = '\0';
   if (fgets(q, sizeof q, 
                         stdin
                              ) == 
                                   ((void *)0)
                                       )
    continue;
   switch (q[0]) {
   case 'y':
   case 'Y':
    goto again;
   case 'n':
   case 'N':
    goto abandon;
   default:
    fprintf(
           stderr
                 , "Enter Y or N\n");
   }
  }
                 case -2:
   abandon:
  fprintf(
         stderr
               , "%s: edits left in %s\n", ProgramName, Filename);
  goto done;
 default:
  fprintf(
         stderr
               , "%s: panic: bad switch() in replace_cmd()\n",
   ProgramName);
  goto fatal;
 }
  remove:
 unlink(Filename);
  done:
 log_it(RealUser, Pid, "END EDIT", User, 0);
}




static int test_cmd(void) {
 if (check_syntax(NewCrontab) < 0) {
  fprintf(
         stderr
               , "Invalid crontab file. Syntax issues were found.\n");
  return (-2);
 }
 else {
  fprintf(
         stderr
               , "No syntax issues were found in the crontab file.\n");
 }
 return (0);
}





static int replace_cmd(void) {
 char n[
       4096
                ];
 FILE *tmp;
 int ch, fd;
 int error = 0;
 uid_t file_owner;
 char *safename;

 safename = host_specific_filename("#tmp", "XXXXXXXXXX");
 if (!safename || !glue_strings(TempFilename, sizeof TempFilename, "/usr/local/var/spool/cron",
   safename, '/')) {
  TempFilename[0] = '\0';
  fprintf(
         stderr
               , "path too long\n");
  return (-2);
 }
 if ((fd = mkstemp(TempFilename)) == -1 || !(tmp = fdopen(fd, "w+"))) {
  perror(TempFilename);
  if (fd != -1) {
   close(fd);
   unlink(TempFilename);
  }
  TempFilename[0] = '\0';
  return (-2);
 }

 (void) signal(
              1
                    , die);
 (void) signal(
              2
                    , die);
 (void) signal(
              3
                     , die);
 rewind(NewCrontab);
 {if ((DebugFlags & (0x0008|0x0001)) != 0) printf ("linenum=%d\n",1); LineNumber = 1; };
 while (
       (-1) 
           != (ch = get_char(NewCrontab)))
  putc(ch, tmp);
 if (ftruncate(fileno(tmp), ftell(tmp)) == -1) {
  fprintf(
         stderr
               , "%s: error while writing new crontab to %s\n",
   ProgramName, TempFilename);
  fclose(tmp);
  error = -2;
  goto done;
 }
 if (ferror(tmp) || fflush(tmp) || fsync(fileno(tmp))) {
  fprintf(
         stderr
               , "%s: error while writing new crontab to %s\n",
   ProgramName, TempFilename);
  fclose(tmp);
  error = -2;
  goto done;
 }
 rewind(tmp);

 if ((error = check_syntax(tmp)) < 0) {
  fprintf(
         stderr
               , "Invalid crontab file, can't install.\n");
  fclose(tmp);
  goto done;
 }

 file_owner = (getgid() == geteuid() &&
  getgid() == getegid()) ? 0 : pw->pw_uid;


 if (fchown(fileno(tmp), file_owner, (gid_t)-1) < 0) {
  perror("fchown");
  fclose(tmp);
  error = -2;
  goto done;
 }
 if (fclose(tmp) == 
                   (-1)
                      ) {
  perror("fclose");
  error = -2;
  goto done;
 }

 if (!glue_strings(n, sizeof n, "/usr/local/var/spool/cron", User, '/')) {
  fprintf(
         stderr
               , "path too long\n");
  error = -2;
  goto done;
 }
 if (rename(TempFilename, n)) {
  fprintf(
         stderr
               , "%s: error renaming %s to %s\n",
   ProgramName, TempFilename, n);
  perror("rename");
  error = -2;
  goto done;
 }
 TempFilename[0] = '\0';
 log_it(RealUser, Pid, "REPLACE", User, 0);

 poke_daemon();

  done:
 (void) signal(
              1
                    , 
                      ((__sighandler_t) 0)
                             );
 (void) signal(
              2
                    , 
                      ((__sighandler_t) 0)
                             );
 (void) signal(
              3
                     , 
                       ((__sighandler_t) 0)
                              );
 if (TempFilename[0]) {
  (void) unlink(TempFilename);
  TempFilename[0] = '\0';
 }
 return (error);
}
static int check_syntax(FILE * crontab_file) {
 char **envp = env_init();
 int eof = 0;
 int envs = 0, entries = 0;

 CheckErrorCount = 0;
 {if ((DebugFlags & (0x0008|0x0001)) != 0) printf ("linenum=%d\n",1 - 0); LineNumber = 1 - 0; };

 if (envp == 
            ((void *)0)
                ) {
  fprintf(
         stderr
               , "%s: Cannot allocate memory.\n", ProgramName);
  return (-2);
 }

 while (!CheckErrorCount && !eof) {
  char envstr[131072];
  entry *e;

  if (!skip_comments(crontab_file)) {
   check_error
    ("too much non-parseable content (comments, empty lines, spaces)");
   break;
  }

  switch (load_env(envstr, crontab_file)) {
  case (-1):

   if (envstr[0] != '\0') {
    {if ((DebugFlags & (0x0008|0x0001)) != 0) printf ("linenum=%d\n",LineNumber + 1); LineNumber = LineNumber + 1; };
    check_error("premature EOF");
   }
   eof = 1;
   break;
  case 0:
   e = load_entry(crontab_file, check_error, pw, envp);
   if (e) {
    ++entries;
    free_entry(e);
   }
   break;
  case 1:
   ++envs;
   break;
  }
 }
 env_free(envp);

 if (envs > 1000) {
  fprintf(
         stderr
               ,
   "There are too many environment variables in the crontab file. Limit: %d\n",
   1000);
  return (-1);
 }

 if (entries > 10000) {
  fprintf(
         stderr
               ,
   "There are too many entries in the crontab file. Limit: %d\n",
   10000);
  return (-1);
 }

 if (CheckErrorCount != 0) {
  return (-1);
 }

 return 0;
}

static int hostset_cmd(void) {
 char n[
       4096
                ];
 FILE *tmp;
 int fd;
 int error = 0;
 char *safename;

 if (!HostSpecified)
  gethostname(Host, sizeof Host);

 safename = host_specific_filename("#tmp", "XXXXXXXXXX");
 if (!safename || !glue_strings(TempFilename, sizeof TempFilename, "/usr/local/var/spool/cron",
   safename, '/')) {
  TempFilename[0] = '\0';
  fprintf(
         stderr
               , "path too long\n");
  return (-2);
 }
 if ((fd = mkstemp(TempFilename)) == -1 || !(tmp = fdopen(fd, "w"))) {
  perror(TempFilename);
  if (fd != -1) {
   close(fd);
   unlink(TempFilename);
  }
  TempFilename[0] = '\0';
  return (-2);
 }

 (void) signal(
              1
                    , die);
 (void) signal(
              2
                    , die);
 (void) signal(
              3
                     , die);

 (void) fchmod(fd, 0600);

 if (fprintf(tmp, "%s\n", Host) < 0 || fclose(tmp) == 
                                                     (-1)
                                                        ) {
  fprintf(
         stderr
               , "%s: error while writing to %s\n",
   ProgramName, TempFilename);
  error = -2;
  goto done;
 }

 if (!glue_strings(n, sizeof n, "/usr/local/var/spool/cron", ".cron.hostname", '/')) {
  fprintf(
         stderr
               , "path too long\n");
  error = -2;
  goto done;
 }

 if (rename(TempFilename, n)) {
  fprintf(
         stderr
               , "%s: error renaming %s to %s\n",
   ProgramName, TempFilename, n);
  perror("rename");
  error = -2;
  goto done;
 }
 TempFilename[0] = '\0';
 log_it(RealUser, Pid, "SET HOST", Host, 0);

 poke_daemon();

  done:
 (void) signal(
              1
                    , 
                      ((__sighandler_t) 0)
                             );
 (void) signal(
              2
                    , 
                      ((__sighandler_t) 0)
                             );
 (void) signal(
              3
                     , 
                       ((__sighandler_t) 0)
                              );
 if (TempFilename[0]) {
  (void) unlink(TempFilename);
  TempFilename[0] = '\0';
 }
 return (error);
}

static int hostget_cmd(void) {
 char n[
       4096
                ];
 FILE *f;

 if (!glue_strings(n, sizeof n, "/usr/local/var/spool/cron", ".cron.hostname", '/')) {
  fprintf(
         stderr
               , "path too long\n");
  return (-2);
 }

 if (!(f = fopen(n, "r"))) {
  if (
     (*__errno_location ()) 
           == 
              2
                    )
   fprintf(
          stderr
                , "File %s not found\n", n);
  else
   perror(n);
  return (-2);
 }

 if (get_string(Host, sizeof Host, f, "\n") == 
                                              (-1)
                                                 ) {
  fprintf(
         stderr
               , "Error reading from %s\n", n);
  fclose(f);
  return (-2);
 }

 fclose(f);

 printf("%s\n", Host);
 fflush(
       stdout
             );

 log_it(RealUser, Pid, "GET HOST", Host, 0);
 return (0);
}

static void poke_daemon(void) {
 if (utime("/usr/local/var/spool/cron", 
                     ((void *)0)
                         ) < 0) {
  fprintf(
         stderr
               , "crontab: can't update mtime on spooldir\n");
  perror("/usr/local/var/spool/cron");
  return;
 }
}

static void die(int x __attribute__ ((__unused__))) {
 if (TempFilename[0])
  (void) unlink(TempFilename);
 _exit(1);
}
