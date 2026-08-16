



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
extern const char *copyright[]
 ;

extern const char *MonthNames[]







 ;

extern const char *DowNames[]






 ;

extern char *ProgramName;
extern int LineNumber;
extern int SyslogOutput;
extern time_t StartTime;
extern int NoFork;
extern int PermitAnyCrontab;
extern char MailCmd[131072 +1];
extern char cron_default_mail_charset[131072];
extern int EnableClustering;
extern int ChangePath;
extern double RandomScale;


extern int DebugFlags ;
extern const char *DebugFlagNames[]






 ;




typedef enum ecode {
 e_none, e_minute, e_hour, e_dom, e_month, e_dow,
 e_cmd, e_timespec, e_username, e_option, e_memory
} ecode_e;

static const char *ecodes[] = {
 "no error",
 "bad minute",
 "bad hour",
 "bad day-of-month",
 "bad month",
 "bad day-of-week",
 "bad command",
 "bad time specifier",
 "bad username",
 "bad option",
 "out of memory"
};

typedef enum {
 R_START,
 R_AST,
 R_STEP,
 R_TERMS,
 R_NUM1,
 R_RANGE,
 R_RANGE_NUM2,
 R_RANDOM,
 R_RANDOM_NUM2,
 R_FINISH,
} range_state_t;

static int get_list(bitstr_t *, int, int, const char *[], int, FILE *),
get_range(bitstr_t *, int, int, const char *[], FILE *),
get_number(int *, int, const char *[], FILE *),
set_element(bitstr_t *, int, int, int);

void free_entry(entry * e) {
 free(e->cmd);
 free(e->pwd);
 env_free(e->envp);
 free(e);
}




entry *load_entry(FILE * file, void (*error_func) (), struct passwd *pw,
 char **envp) {
 ecode_e ecode = e_none;
 entry *e = 
           ((void *)0)
               ;
 int ch;
 char cmd[131072];
 char envstr[131072];
 char **tenvp;
 char *p;
 struct passwd temppw;
 int i;

 if ((DebugFlags & (0x0008)) != 0) printf ("load_entry()...about to eat comments\n");

 ch = get_char(file);
 if (ch == 
          (-1)
             )
  return (
         ((void *)0)
             );






 e = (entry *) calloc(sizeof (entry), sizeof (char));
 if (e == 
         ((void *)0)
             ) {
  ecode = e_memory;
  goto eof;
 }




 if (ch == '-') {



  if (pw == 
           ((void *)0) 
                || pw->pw_uid == 0)
   e->flags |= 0x20;
  else {
   log_it("CRON", getpid(), "ERROR", "Only privileged user can disable logging", 0);
   ecode = e_option;
   goto eof;
  }
  ch = get_char(file);
  if (ch == 
           (-1)
              ) {
   free(e);
   return 
         ((void *)0)
             ;
  }
 }

 if (ch == '@') {
  ch = get_string(cmd, 131072, file, " \t\n");
  if (!strcmp("reboot", cmd)) {
   e->flags |= 0x10;
  }
  else if (!strcmp("yearly", cmd) || !strcmp("annually", cmd)) {
   (e->minute)[((0) >> 3)] |= (bitstr_t)(1 << ((0)&0x7));
   (e->hour)[((0) >> 3)] |= (bitstr_t)(1 << ((0)&0x7));
   (e->dom)[((0) >> 3)] |= (bitstr_t)(1 << ((0)&0x7));
   (e->month)[((0) >> 3)] |= (bitstr_t)(1 << ((0)&0x7));
   { register bitstr_t *_name = e->dow; register int _start = 0, _stop = 7 - 0; register int _startbyte = ((_start) >> 3); register int _stopbyte = ((_stop) >> 3); if (_startbyte == _stopbyte) { _name[_startbyte] |= (bitstr_t)((0xff << (_start&0x7)) & (0xff >> (7 - (_stop&0x7)))); } else { _name[_startbyte] |= (bitstr_t)(0xff << ((_start)&0x7)); while (++_startbyte < _stopbyte) _name[_startbyte] = 0xff; _name[_stopbyte] |= (bitstr_t)(0xff >> (7 - (_stop&0x7))); } };
   e->flags |= 0x08;
  }
  else if (!strcmp("monthly", cmd)) {
   (e->minute)[((0) >> 3)] |= (bitstr_t)(1 << ((0)&0x7));
   (e->hour)[((0) >> 3)] |= (bitstr_t)(1 << ((0)&0x7));
   (e->dom)[((0) >> 3)] |= (bitstr_t)(1 << ((0)&0x7));
   { register bitstr_t *_name = e->month; register int _start = 0, _stop = 12 - 1; register int _startbyte = ((_start) >> 3); register int _stopbyte = ((_stop) >> 3); if (_startbyte == _stopbyte) { _name[_startbyte] |= (bitstr_t)((0xff << (_start&0x7)) & (0xff >> (7 - (_stop&0x7)))); } else { _name[_startbyte] |= (bitstr_t)(0xff << ((_start)&0x7)); while (++_startbyte < _stopbyte) _name[_startbyte] = 0xff; _name[_stopbyte] |= (bitstr_t)(0xff >> (7 - (_stop&0x7))); } };
   { register bitstr_t *_name = e->dow; register int _start = 0, _stop = 7 - 0; register int _startbyte = ((_start) >> 3); register int _stopbyte = ((_stop) >> 3); if (_startbyte == _stopbyte) { _name[_startbyte] |= (bitstr_t)((0xff << (_start&0x7)) & (0xff >> (7 - (_stop&0x7)))); } else { _name[_startbyte] |= (bitstr_t)(0xff << ((_start)&0x7)); while (++_startbyte < _stopbyte) _name[_startbyte] = 0xff; _name[_stopbyte] |= (bitstr_t)(0xff >> (7 - (_stop&0x7))); } };
   e->flags |= 0x08;
  }
  else if (!strcmp("weekly", cmd)) {
   (e->minute)[((0) >> 3)] |= (bitstr_t)(1 << ((0)&0x7));
   (e->hour)[((0) >> 3)] |= (bitstr_t)(1 << ((0)&0x7));
   { register bitstr_t *_name = e->dom; register int _start = 0, _stop = 31 - 1; register int _startbyte = ((_start) >> 3); register int _stopbyte = ((_stop) >> 3); if (_startbyte == _stopbyte) { _name[_startbyte] |= (bitstr_t)((0xff << (_start&0x7)) & (0xff >> (7 - (_stop&0x7)))); } else { _name[_startbyte] |= (bitstr_t)(0xff << ((_start)&0x7)); while (++_startbyte < _stopbyte) _name[_startbyte] = 0xff; _name[_stopbyte] |= (bitstr_t)(0xff >> (7 - (_stop&0x7))); } };
   { register bitstr_t *_name = e->month; register int _start = 0, _stop = 12 - 1; register int _startbyte = ((_start) >> 3); register int _stopbyte = ((_stop) >> 3); if (_startbyte == _stopbyte) { _name[_startbyte] |= (bitstr_t)((0xff << (_start&0x7)) & (0xff >> (7 - (_stop&0x7)))); } else { _name[_startbyte] |= (bitstr_t)(0xff << ((_start)&0x7)); while (++_startbyte < _stopbyte) _name[_startbyte] = 0xff; _name[_stopbyte] |= (bitstr_t)(0xff >> (7 - (_stop&0x7))); } };
   (e->dow)[((0) >> 3)] |= (bitstr_t)(1 << ((0)&0x7));
   e->flags |= 0x04;
  }
  else if (!strcmp("daily", cmd) || !strcmp("midnight", cmd)) {
   (e->minute)[((0) >> 3)] |= (bitstr_t)(1 << ((0)&0x7));
   (e->hour)[((0) >> 3)] |= (bitstr_t)(1 << ((0)&0x7));
   { register bitstr_t *_name = e->dom; register int _start = 0, _stop = 31 - 1; register int _startbyte = ((_start) >> 3); register int _stopbyte = ((_stop) >> 3); if (_startbyte == _stopbyte) { _name[_startbyte] |= (bitstr_t)((0xff << (_start&0x7)) & (0xff >> (7 - (_stop&0x7)))); } else { _name[_startbyte] |= (bitstr_t)(0xff << ((_start)&0x7)); while (++_startbyte < _stopbyte) _name[_startbyte] = 0xff; _name[_stopbyte] |= (bitstr_t)(0xff >> (7 - (_stop&0x7))); } };
   { register bitstr_t *_name = e->month; register int _start = 0, _stop = 12 - 1; register int _startbyte = ((_start) >> 3); register int _stopbyte = ((_stop) >> 3); if (_startbyte == _stopbyte) { _name[_startbyte] |= (bitstr_t)((0xff << (_start&0x7)) & (0xff >> (7 - (_stop&0x7)))); } else { _name[_startbyte] |= (bitstr_t)(0xff << ((_start)&0x7)); while (++_startbyte < _stopbyte) _name[_startbyte] = 0xff; _name[_stopbyte] |= (bitstr_t)(0xff >> (7 - (_stop&0x7))); } };
   { register bitstr_t *_name = e->dow; register int _start = 0, _stop = 7 - 0; register int _startbyte = ((_start) >> 3); register int _stopbyte = ((_stop) >> 3); if (_startbyte == _stopbyte) { _name[_startbyte] |= (bitstr_t)((0xff << (_start&0x7)) & (0xff >> (7 - (_stop&0x7)))); } else { _name[_startbyte] |= (bitstr_t)(0xff << ((_start)&0x7)); while (++_startbyte < _stopbyte) _name[_startbyte] = 0xff; _name[_stopbyte] |= (bitstr_t)(0xff >> (7 - (_stop&0x7))); } };
  }
  else if (!strcmp("hourly", cmd)) {
   (e->minute)[((0) >> 3)] |= (bitstr_t)(1 << ((0)&0x7));
   { register bitstr_t *_name = e->hour; register int _start = 0, _stop = 23 - 0; register int _startbyte = ((_start) >> 3); register int _stopbyte = ((_stop) >> 3); if (_startbyte == _stopbyte) { _name[_startbyte] |= (bitstr_t)((0xff << (_start&0x7)) & (0xff >> (7 - (_stop&0x7)))); } else { _name[_startbyte] |= (bitstr_t)(0xff << ((_start)&0x7)); while (++_startbyte < _stopbyte) _name[_startbyte] = 0xff; _name[_stopbyte] |= (bitstr_t)(0xff >> (7 - (_stop&0x7))); } };
   { register bitstr_t *_name = e->dom; register int _start = 0, _stop = 31 - 1; register int _startbyte = ((_start) >> 3); register int _stopbyte = ((_stop) >> 3); if (_startbyte == _stopbyte) { _name[_startbyte] |= (bitstr_t)((0xff << (_start&0x7)) & (0xff >> (7 - (_stop&0x7)))); } else { _name[_startbyte] |= (bitstr_t)(0xff << ((_start)&0x7)); while (++_startbyte < _stopbyte) _name[_startbyte] = 0xff; _name[_stopbyte] |= (bitstr_t)(0xff >> (7 - (_stop&0x7))); } };
   { register bitstr_t *_name = e->month; register int _start = 0, _stop = 12 - 1; register int _startbyte = ((_start) >> 3); register int _stopbyte = ((_stop) >> 3); if (_startbyte == _stopbyte) { _name[_startbyte] |= (bitstr_t)((0xff << (_start&0x7)) & (0xff >> (7 - (_stop&0x7)))); } else { _name[_startbyte] |= (bitstr_t)(0xff << ((_start)&0x7)); while (++_startbyte < _stopbyte) _name[_startbyte] = 0xff; _name[_stopbyte] |= (bitstr_t)(0xff >> (7 - (_stop&0x7))); } };
   { register bitstr_t *_name = e->dow; register int _start = 0, _stop = 7 - 0; register int _startbyte = ((_start) >> 3); register int _stopbyte = ((_stop) >> 3); if (_startbyte == _stopbyte) { _name[_startbyte] |= (bitstr_t)((0xff << (_start&0x7)) & (0xff >> (7 - (_stop&0x7)))); } else { _name[_startbyte] |= (bitstr_t)(0xff << ((_start)&0x7)); while (++_startbyte < _stopbyte) _name[_startbyte] = 0xff; _name[_stopbyte] |= (bitstr_t)(0xff >> (7 - (_stop&0x7))); } };
   e->flags |= 0x02;
  }
  else {
   ecode = e_timespec;
   goto eof;
  }



  while (ch == '\t' || ch == ' ') ch = get_char(file);;
  if (ch == 
           (-1) 
               || ch == '\n') {
   ecode = e_cmd;
   goto eof;
  }
 }
 else {
  if ((DebugFlags & (0x0008)) != 0) printf ("load_entry()...about to parse numerics\n");

  if (ch == '*')
   e->flags |= 0x01;
  ch = get_list(e->minute, 0, 59, ((const char **)
                                                     ((void *)0)
                                                     ), ch, file);
  if (ch == 
           (-1)
              ) {
   ecode = e_minute;
   goto eof;
  }




  if (ch == '*')
   e->flags |= 0x02;
  ch = get_list(e->hour, 0, 23, ((const char **)
                                               ((void *)0)
                                               ), ch, file);
  if (ch == 
           (-1)
              ) {
   ecode = e_hour;
   goto eof;
  }




  if (ch == '*')
   e->flags |= 0x04;
  ch = get_list(e->dom, 1, 31, ((const char **)
                                            ((void *)0)
                                            ), ch, file);
  if (ch == 
           (-1)
              ) {
   ecode = e_dom;
   goto eof;
  }




  ch = get_list(e->month, 1, 12, MonthNames, ch, file);
  if (ch == 
           (-1)
              ) {
   ecode = e_month;
   goto eof;
  }




  if (ch == '*')
   e->flags |= 0x08;
  ch = get_list(e->dow, 0, 7, DowNames, ch, file);
  if (ch == 
           (-1)
              ) {
   ecode = e_dow;
   goto eof;
  }
 }


 if (((e->dow)[((0) >> 3)] & (1 << ((0)&0x7))) || ((e->dow)[((7) >> 3)] & (1 << ((7)&0x7)))) {
  (e->dow)[((0) >> 3)] |= (bitstr_t)(1 << ((0)&0x7));
  (e->dow)[((7) >> 3)] |= (bitstr_t)(1 << ((7)&0x7));
 }


 if (ch == '\n' || ch == '*') {
  ecode = e_cmd;
  goto eof;
 }


 unget_char(ch, file);

 if (!pw) {
  char *username = cmd;

  if ((DebugFlags & (0x0008)) != 0) printf ("load_entry()...about to parse username\n");
  ch = get_string(username, 131072, file, " \t\n");

  if ((DebugFlags & (0x0008)) != 0) printf ("load_entry()...got %s\n", username);
  if (ch == 
           (-1) 
               || ch == '\n' || ch == '*') {
   ecode = e_cmd;
   goto eof;
  }

  pw = getpwnam(username);
  if (pw == 
           ((void *)0)
               ) {
   if ((DebugFlags & (0x0008)) != 0) printf ("load_entry()...unknown user entry\n");
   memset(&temppw, 0, sizeof (temppw));
   temppw.pw_name = username;
   temppw.pw_passwd = "";
   pw = &temppw;
  } else {
   if ((DebugFlags & (0x0008)) != 0) printf ("load_entry()...uid %ld, gid %ld\n", (long) pw->pw_uid, (long) pw->pw_gid)
                                          ;
  }

  while (ch == '\t' || ch == ' ') ch = get_char(file);;


  if (ch == 
           (-1) 
               || ch == '\n') {
   ecode = e_cmd;
   goto eof;
  }


  unget_char(ch, file);
 }

 if ((e->pwd = pw_dup(pw)) == 
                             ((void *)0)
                                 ) {
  ecode = e_memory;
  goto eof;
 }
 memset(e->pwd->pw_passwd, 0, strlen(e->pwd->pw_passwd));

 p = env_get("RANDOM_DELAY", envp);
 if (p) {
  char *endptr;
  long val;

  
 (*__errno_location ()) 
       = 0;
  val = strtol(p, &endptr, 10);
  if (
     (*__errno_location ()) 
           != 0 || val < 0 || val > 24*60) {
   log_it("CRON", getpid(), "ERROR", "bad value of RANDOM_DELAY", 0);
  } else {
   e->delay = (int)((double)val * RandomScale);
  }
 }




 if ((e->envp = env_copy(envp)) == 
                                  ((void *)0)
                                      ) {
  ecode = e_memory;
  goto eof;
 }
 if (!env_get("SHELL", e->envp)) {
  if (glue_strings(envstr, sizeof envstr, "SHELL", 
                                                  "/bin/sh"
                                                              , '=')) {
   if ((tenvp = env_set(e->envp, envstr)) == 
                                            ((void *)0)
                                                ) {
    ecode = e_memory;
    goto eof;
   }
   e->envp = tenvp;
  }
  else
   log_it("CRON", getpid(), "ERROR", "can't set SHELL", 0);
 }
 if ((tenvp = env_update_home(e->envp, pw->pw_dir)) == 
                                                      ((void *)0)
                                                          ) {
  ecode = e_memory;
  goto eof;
 }
 e->envp = tenvp;


 if (!env_get("PATH", e->envp)) {
  char *defpath;

  if (ChangePath)
   defpath = 
            "/usr/bin:/bin"
                         ;
  else {
   defpath = getenv("PATH");
   if (defpath == 
                 ((void *)0)
                     )
    defpath = 
             "/usr/bin:/bin"
                          ;
  }

  if (glue_strings(envstr, sizeof envstr, "PATH", defpath, '=')) {
   if ((tenvp = env_set(e->envp, envstr)) == 
                                            ((void *)0)
                                                ) {
    ecode = e_memory;
    goto eof;
   }
   e->envp = tenvp;
  }
  else
   log_it("CRON", getpid(), "ERROR", "can't set PATH", 0);
 }

 if (glue_strings(envstr, sizeof envstr, "LOGNAME", pw->pw_name, '=')) {
  if ((tenvp = env_set(e->envp, envstr)) == 
                                           ((void *)0)
                                               ) {
   ecode = e_memory;
   goto eof;
  }
  e->envp = tenvp;
 }
 else
  log_it("CRON", getpid(), "ERROR", "can't set LOGNAME", 0);

 if (glue_strings(envstr, sizeof envstr, "USER", pw->pw_name, '=')) {
  if ((tenvp = env_set(e->envp, envstr)) == 
                                           ((void *)0)
                                               ) {
   ecode = e_memory;
   goto eof;
  }
  e->envp = tenvp;
 }
 else
  log_it("CRON", getpid(), "ERROR", "can't set USER", 0);


 if ((DebugFlags & (0x0008)) != 0) printf ("load_entry()...about to parse command\n");





 ch = get_string(cmd, 131072, file, "\n");



 if (ch == 
          (-1)
             ) {
  ecode = e_cmd;
  goto eof;
 }



 if ((e->cmd = strdup(cmd)) == 
                              ((void *)0)
                                  ) {
  ecode = e_memory;
  goto eof;
 }

 if ((DebugFlags & (0x0008)) != 0) printf ("load_entry()...returning successfully\n");



 return (e);

  eof:
 if (e) {
  if (e->envp)
   env_free(e->envp);
  free(e->pwd);
  free(e->cmd);
  free(e);
 }
 for (i = 0; i < 131072 && ch != '\n' && !feof(file); i++)
  ch = get_char(file);
 if (ecode != e_none && error_func)
  (*error_func) (ecodes[(int) ecode]);
 return (
        ((void *)0)
            );
}

static int
get_list(bitstr_t * bits, int low, int high, const char *names[],
 int ch, FILE * file) {
 int done;







 if ((DebugFlags & (0x0008 | 0x0001)) != 0) printf ("get_list()...entered\n");





 { register bitstr_t *_name = bits; register int _start = 0, _stop = (high - low); register int _startbyte = ((_start) >> 3); register int _stopbyte = ((_stop) >> 3); if (_startbyte == _stopbyte) { _name[_startbyte] &= (bitstr_t)((0xff >> (8 - (_start&0x7))) | (0xff << ((_stop&0x7) + 1))); } else { _name[_startbyte] &= (bitstr_t)(0xff >> (8 - (_start&0x7))); while (++_startbyte < _stopbyte) _name[_startbyte] = 0; _name[_stopbyte] &= (bitstr_t)(0xff << ((_stop&0x7) + 1)); } };



 done = 0;


 unget_char(ch, file);
 while (!done) {
  if (
     (-1) 
         == (ch = get_range(bits, low, high, names, file)))
   return (
          (-1)
             );
  if (ch == ',')
   continue;
  else
   done = 1;
 }



 while (ch!='\t' && ch!=' ' && ch!='\n' && ch != 
(-1)
) ch = get_char(file);
 while (ch == '\t' || ch == ' ') ch = get_char(file);

 if ((DebugFlags & (0x0008 | 0x0001)) != 0) printf ("get_list()...exiting w/ %02x\n", ch);

 return (ch);
}

inline static int is_separator(int ch) {
 switch (ch) {
  case '\t':
  case '\n':
  case ' ':
  case ',':
   return 1;
  default:
   return 0;
 }
}



static int
get_range(bitstr_t * bits, int low, int high, const char *names[],
  FILE * file) {




 int ch, i, num1, num2, num3;



 num3 = 1;
 range_state_t state = R_START;

 while (state != R_FINISH && ((ch = get_char(file)) != 
                                                      (-1)
                                                         )) {
  switch (state) {
   case R_START:
    if (ch == '*') {
     num1 = low;
     num2 = high;
     state = R_AST;
     break;
    }
    if (ch == '~') {
     num1 = low;
     state = R_RANDOM;
     break;
    }
    unget_char(ch, file);
    if (get_number(&num1, low, names, file) != 
                                              (-1)
                                                 ) {
     state = R_NUM1;
     break;
    }
    return (
           (-1)
              );

   case R_AST:
    if (ch == '/') {
     state = R_STEP;
     break;
    }
    if (is_separator(ch)) {
     state = R_FINISH;
     break;
    }
    return (
           (-1)
              );

   case R_STEP:
    unget_char(ch, file);
    if (get_number(&num3, 0, ((const char **)
                            ((void *)0)
                            ), file) != 
                                               (-1)
        
       && num3 != 0) {
     state = R_TERMS;
     break;
    }
    return (
           (-1)
              );

   case R_TERMS:
    if (is_separator(ch)) {
     state = R_FINISH;
     break;
    }
    return (
           (-1)
              );

   case R_NUM1:
    if (ch == '-') {
     state = R_RANGE;
     break;
    }
    if (ch == '~') {
     state = R_RANDOM;
     break;
    }
    if (is_separator(ch)) {
     num2 = num1;
     state = R_FINISH;
     break;
    }
    return (
           (-1)
              );

   case R_RANGE:
    unget_char(ch, file);
    if (get_number(&num2, low, names, file) != 
                                              (-1)
                                                 ) {
     state = R_RANGE_NUM2;
     break;
    }
    return (
           (-1)
              );

   case R_RANGE_NUM2:
    if (ch == '/') {
     state = R_STEP;
     break;
    }
    if (is_separator(ch)) {
     state = R_FINISH;
     break;
    }
    return (
           (-1)
              );

   case R_RANDOM:
    if (is_separator(ch)) {
     num2 = high;
     state = R_FINISH;
    }
    else if (unget_char(ch, file),
      get_number(&num2, low, names, file) != 
                                            (-1)
                                               ) {
     state = R_TERMS;
    }


    else
     return (
            (-1)
               );


    if (num1 > num2)
     return (
            (-1)
               );



    num1 = num2 = random() % (num2 - num1 + 1) + num1;
    break;


   default:


    return (
           (-1)
              );
  }
 }
 if (state != R_FINISH || ch == 
                               (-1)
                                  )
  return (
         (-1)
            );

 for (i = num1; i <= num2; i += num3)
  if (
     (-1) 
         == set_element(bits, low, high, i)) {
   unget_char(ch, file);
   return (
          (-1)
             );
  }
 return ch;
}

static int
get_number(int *numptr, int low, const char *names[], FILE * file) {
 char temp[131072], *pc;
 int len, i, ch;
 char *endptr;

 pc = temp;
 len = 0;


 while (
       ((*__ctype_b_loc ())[(int) ((
       (ch = get_char(file))
       ))] & (unsigned short int) _ISalnum)
                                     ) {
  if (++len >= 131072)
   goto bad;
  *pc++ = (char)ch;
 }
 *pc = '\0';
 if (len == 0)
  goto bad;

 unget_char(ch, file);


 *numptr = (int) strtol(temp, &endptr, 10);
 if (*endptr == '\0' && temp != endptr) {

  return 0;
 }


 if (names) {
  for (i = 0; names[i] != 
                         ((void *)0)
                             ; i++) {
   if ((DebugFlags & (0x0008 | 0x0001)) != 0) printf ("get_num, compare(%s,%s)\n", names[i], temp);
   if (strcasecmp(names[i], temp) == 0) {
    *numptr = i + low;
    return 0;
   }
  }
 } else {
  goto bad;
 }

  bad:
 unget_char(ch, file);
 return (
        (-1)
           );
}

static int set_element(bitstr_t * bits, int low, int high, int number) {
 if ((DebugFlags & (0x0008 | 0x0001)) != 0) printf ("set_element(?,%d,%d,%d)\n", low, high, number);

 if (number < low || number > high)
  return (
         (-1)
            );

 (bits)[(((number - low)) >> 3)] |= (bitstr_t)(1 << (((number - low))&0x7));
 return (0);
}
