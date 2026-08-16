



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

int expand_envvar(const char *, char *, size_t);





static int child_process(entry *, char **);
static int safe_p(const char *, const char *);

void do_command(entry * e, user * u) {
 pid_t pid = getpid();
 int ev;
 char **jobenv = 
                ((void *)0)
                    ;

 if ((DebugFlags & (0x0004)) != 0) printf ("[%ld] do_command(%s, (%s,%ld,%ld))\n", (long) pid, e->cmd, u->name, (long) e->pwd->pw_uid, (long) e->pwd->pw_gid)

                                                 ;
  switch (fork()) {
 case -1:
  log_it("CRON", pid, "CAN'T FORK", "do_command", 
                                                 (*__errno_location ())
                                                      );
  break;
 case 0:

  acquire_daemonlock(1);


  if (cron_set_job_security_context(e, u, &jobenv) != 0) {
   _exit(1);
  }
  ev = child_process(e, jobenv);



  env_free(jobenv);
  if ((DebugFlags & (0x0004)) != 0) printf ("[%ld] child process done, exiting\n", (long) getpid());
  _exit(ev);
  break;
 default:

  break;
 }
 if ((DebugFlags & (0x0004)) != 0) printf ("[%ld] main process returning to work\n", (long) pid);
}

static int child_process(entry * e, char **jobenv) {
 int stdin_pipe[2], stdout_pipe[2];
 char *input_data, *usernm, *mailto, *mailfrom;
 char mailto_expanded[255];
 char mailfrom_expanded[255];
 int children = 0;
 pid_t pid = getpid();
 struct sigaction sa;



 memset(&sa, 0, sizeof(sa));
 sa.
   __sigaction_handler.sa_handler 
              = 
                ((__sighandler_t) 1)
                       ;
 sigaction(
          13
                 , &sa, 
                        ((void *)0)
                            );






 sa.
   __sigaction_handler.sa_handler 
              = 
                ((__sighandler_t) 0)
                       ;
 sigaction(
          17
                 , &sa, 
                        ((void *)0)
                            );


 if ((DebugFlags & (0x0004)) != 0) printf ("[%ld] child_process('%s')\n", (long) getpid(), e->cmd);




             {
  char *pch;

  for (pch = ProgramName; *pch; pch++)
   *pch = (char)(
               ((*__ctype_b_loc ())[(int) ((
               *pch
               ))] & (unsigned short int) _ISlower) 
               ? toupper(*pch) : *pch);
 }




 usernm = e->pwd->pw_name;
 mailto = env_get("MAILTO", jobenv);
 mailfrom = env_get("MAILFROM", e->envp);

 if (mailto != 
              ((void *)0)
                  ) {
  if (expand_envvar(mailto, mailto_expanded, sizeof(mailto_expanded))) {
   mailto = mailto_expanded;
  }
  else {
   log_it("CRON", pid, "WARNING", "The environment variable 'MAILTO' could not be expanded. The non-expanded value will be used." , 0);
  }
 }

 if (mailfrom != 
                ((void *)0)
                    ) {
  if (expand_envvar(mailfrom, mailfrom_expanded, sizeof(mailfrom_expanded))) {
   mailfrom = mailfrom_expanded;
  }
  else {
   log_it("CRON", pid, "WARNING", "The environment variable 'MAILFROM' could not be expanded. The non-expanded value will be used." , 0);
  }
 }



 if (pipe(stdin_pipe) == -1) {
  log_it("CRON", pid, "PIPE() FAILED", "stdin_pipe", 
                                                    (*__errno_location ())
                                                         );
  return 1;
 }

 if (pipe(stdout_pipe) == -1) {
  log_it("CRON", pid, "PIPE() FAILED", "stdout_pipe", 
                                                     (*__errno_location ())
                                                          );
  return 1;
 }
             {
  int escaped = 0;
  int ch;
  char *p;

  for (input_data = p = e->cmd;
   (ch = *input_data) != '\0'; input_data++, p++) {
   if (p != input_data)
    *p = (char)ch;
   if (escaped) {
    if (ch == '%')
     *--p = (char)ch;
    escaped = 0;
    continue;
   }
   if (ch == '\\') {
    escaped = 1;
    continue;
   }
   if (ch == '%') {
    *input_data++ = '\0';
    break;
   }
  }
  *p = '\0';
 }




 switch (fork()) {
 case -1:
  log_it("CRON", pid, "CAN'T FORK", "child_process", 
                                                    (*__errno_location ())
                                                         );
  return 1;

 case 0:
  if ((DebugFlags & (0x0004)) != 0) printf ("[%ld] grandchild process fork()'ed\n", (long) getpid());






  if ((e->flags & 0x20) == 0) {
   char *x = mkprints((u_char *) e->cmd, strlen(e->cmd));

   if (x == 
           ((void *)0)
               )
    _exit(1);

   log_it(usernm, getpid(), "CMD", x, 0);
   free(x);
  }

  if (cron_change_user_permanently(e->pwd, env_get("HOME", jobenv)) < 0)
   _exit(1);



  (void) setsid();




  sa.
    __sigaction_handler.sa_handler 
               = 
                 ((__sighandler_t) 0)
                        ;
  sigaction(
           13
                  , &sa, 
                         ((void *)0)
                             );







  close(stdin_pipe[1]);
  close(stdout_pipe[0]);




  if (stdin_pipe[0] != 0) {
   dup2(stdin_pipe[0], 0);
   close(stdin_pipe[0]);
  }
  if (stdout_pipe[1] != 1) {
   dup2(stdout_pipe[1], 1);
   close(stdout_pipe[1]);
  }
  dup2(1, 2);




  {
   char *shell = env_get("SHELL", jobenv);
   int fd, fdmax = ((getdtablesize())<(10000)?(getdtablesize()):(10000));


   for(fd = 2 + 1; fd < fdmax; fd++) {
    close(fd);
   }


   if (DebugFlags & 0x0040) {
    fprintf(
           stderr
                 , "debug DTEST is on, not exec'ing command.\n");
    fprintf(
           stderr
                 , "\tcmd='%s' shell='%s'\n", e->cmd, shell);
    _exit(0);
   }

    execle(shell, shell, "-c", e->cmd, (char *) 0, jobenv);
   fprintf(
          stderr
                , "execl: couldn't exec `%s'\n", shell);
   perror("execl");
   _exit(1);
  }
  break;
 default:
  cron_restore_default_security_context();

  break;
 }

 children++;





 if ((DebugFlags & (0x0004)) != 0) printf ("[%ld] child continues, closing pipes\n", (long) getpid());




 close(stdin_pipe[0]);
 close(stdout_pipe[1]);
 if (*input_data && fork() == 0) {
  FILE *out = fdopen(stdin_pipe[1], "w");
  int need_newline = 0;
  int escaped = 0;
  int ch;

  if ((DebugFlags & (0x0004)) != 0) printf ("[%ld] child2 sending data to grandchild\n", (long) getpid())
                     ;




  sa.
    __sigaction_handler.sa_handler 
               = 
                 ((__sighandler_t) 0)
                        ;
  sigaction(
           13
                  , &sa, 
                         ((void *)0)
                             );




  close(stdout_pipe[0]);

  if (cron_change_user_permanently(e->pwd, env_get("HOME", jobenv)) < 0)
   _exit(1);





  while ((ch = *input_data++) != '\0') {
   if (escaped) {
    if (ch != '%')
     putc('\\', out);
   }
   else {
    if (ch == '%')
     ch = '\n';
   }

   if (!(escaped = (ch == '\\'))) {
    putc(ch, out);
    need_newline = (ch != '\n');
   }
  }
  if (escaped)
   putc('\\', out);
  if (need_newline)
   putc('\n', out);




  fclose(out);

  if ((DebugFlags & (0x0004)) != 0) printf ("[%ld] child2 done sending to grandchild\n", (long) getpid())
                     ;
  _exit(0);
 }




 close(stdin_pipe[1]);

 children++;
 if ((DebugFlags & (0x0004)) != 0) printf ("[%ld] child reading output from grandchild\n", (long) getpid())
                    ;

             {
  FILE *in = fdopen(stdout_pipe[0], "r");
  int ch = getc(in);

  if (ch != 
           (-1)
              ) {
   FILE *mail = 
               ((void *)0)
                   ;
   int bytes = 1;
   int status = 0;

   char logbuf[1024];
   int bufidx = 0;
   if (SyslogOutput) {
    if (ch != '\n')
     logbuf[bufidx++] = (char)ch;
   }


   if ((DebugFlags & (0x0004 | 0x0001)) != 0) printf ("[%ld] got data (%x:%c) from grandchild\n", (long) getpid(), ch, ch)

                              ;




    if (mailto) {


    if (!*mailto) {


     mailto = 
             ((void *)0)
                 ;
    }
   }
   else {


    mailto = usernm;
   }




   if (!mailfrom || !*mailfrom || !safe_p(usernm, mailfrom)) {
    mailfrom = e->pwd->pw_name;
   }







   if (mailto && safe_p(usernm, mailto)
    && strncmp(MailCmd,"off",3) && !SyslogOutput) {
    char **env;
    char mailcmd[131072 +1];
    char hostname[64];
    char *content_type = env_get("CONTENT_TYPE", jobenv),
     *content_transfer_encoding =
     env_get("CONTENT_TRANSFER_ENCODING", jobenv);

    gethostname(hostname, 64);

    if (MailCmd[0] == '\0') {
     int len;

     len = snprintf(mailcmd, sizeof mailcmd, "%s -FCronDaemon -i -odi -oem -oi -t -f %s", "/usr/sbin/sendmail", mailfrom);
     if (len < 0) {
      fprintf(
             stderr
                   , "mailcmd snprintf failed\n");
      (void) _exit(1);
     }
     if (sizeof mailcmd <= (size_t) len) {
      fprintf(
             stderr
                   , "mailcmd too long\n");
      (void) _exit(1);
     }
    }
    else {
     strncpy(mailcmd, MailCmd, 131072 +1);
    }
    if (!(mail = cron_popen(mailcmd, "w", e->pwd, jobenv))) {
     perror(mailcmd);
     (void) _exit(1);
    }

    fprintf(mail, "From: \"(Cron Daemon)\" <%s>\n", mailfrom);
    fprintf(mail, "To: %s\n", mailto);
    fprintf(mail, "Subject: Cron <%s@%s> %s\n",
     usernm, first_word(hostname, "."), e->cmd);




    fprintf(mail, "MIME-Version: 1.0\n");
    if (content_type == 
                       ((void *)0)
                           ) {
     fprintf(mail, "Content-Type: text/plain; charset=%s\n",
      cron_default_mail_charset);
    }
    else {



     char *nl = content_type;
     size_t ctlen = strlen(content_type);
     while ((*nl != '\0')
      && ((nl = strchr(nl, '\n')) != 
                                    ((void *)0)
                                        )
      && (nl < (content_type + ctlen))
      )
      *nl = ' ';
     fprintf(mail, "Content-Type: %s\n", content_type);
    }
    if (content_transfer_encoding == 
                                    ((void *)0)
                                        ) {
     fprintf(mail, "Content-Transfer-Encoding: 8bit\n");
    }
    else {
     char *nl = content_transfer_encoding;
     size_t ctlen = strlen(content_transfer_encoding);
     while ((*nl != '\0')
      && ((nl = strchr(nl, '\n')) != 
                                    ((void *)0)
                                        )
      && (nl < (content_transfer_encoding + ctlen))
      )
      *nl = ' ';
     fprintf(mail, "Content-Transfer-Encoding: %s\n",
      content_transfer_encoding);
    }




    fprintf(mail, "Auto-Submitted: auto-generated\n");
    fprintf(mail, "Precedence: bulk\n");

    for (env = jobenv; *env; env++)
     fprintf(mail, "X-Cron-Env: <%s>\n", *env);
    fprintf(mail, "\n");



    putc(ch, mail);
   }






   while (
         (-1) 
             != (ch = getc(in))) {
    if (ch == '\r')
     continue;
    bytes++;
    if (mail)
     putc(ch, mail);

    if (SyslogOutput) {
     logbuf[bufidx++] = (char)ch;
     if ((ch == '\n') || (bufidx == sizeof(logbuf)-1)) {
      if (ch == '\n')
       logbuf[bufidx-1] = '\0';
      else
       logbuf[bufidx] = '\0';
      log_it(usernm, getpid(), "CMDOUT", logbuf, 0);
      bufidx = 0;
     }
    }

   }




   if (mail) {
    if ((DebugFlags & (0x0004)) != 0) printf ("[%ld] closing pipe to mail\n", (long) getpid());






     status = cron_pclose(mail);
   }

   if (SyslogOutput) {
    if (bufidx) {
     logbuf[bufidx] = '\0';
     log_it(usernm, getpid(), "CMDOUT", logbuf, 0);
    }
   }






   if (mail && status && !SyslogOutput) {
    char buf[131072];

    sprintf(buf,
     "mailed %d byte%s of output but got status 0x%04x\n",
     bytes, (bytes == 1) ? "" : "s", status);
    log_it(usernm, getpid(), "MAIL", buf, 0);
   }

  }

  if ((DebugFlags & (0x0004)) != 0) printf ("[%ld] got EOF from grandchild\n", (long) getpid());

  fclose(in);
 }



 for (; children > 0; children--) {
  int waiter;
  pid_t child;

  if ((DebugFlags & (0x0004)) != 0) printf ("[%ld] waiting for grandchild #%d to finish\n", (long) getpid(), children)
                               ;
  while ((child = wait(&waiter)) < 0 && 
                                        (*__errno_location ()) 
                                              == 
                                                 4
                                                      ) ;
  if (child < 0) {
   if ((DebugFlags & (0x0004)) != 0) printf ("[%ld] no more grandchildren--mail written?\n", (long) getpid())

                      ;
   break;
  }
  if ((DebugFlags & (0x0004)) != 0) printf ("[%ld] grandchild #%ld finished, status=%04x", (long) getpid(), (long) child, 
 (((
 waiter
 ) & 0xff00) >> 8)
 )
                                                        ;
   if (
      (((signed char) (((
      waiter
      ) & 0x7f) + 1) >> 1) > 0) 
                          && 
                             ((
                             waiter
                             ) & 0x80)
                                              )
    if ((DebugFlags & (0x0004)) != 0) printf (", dumped core");
   if ((DebugFlags & (0x0004)) != 0) printf ("\n");
 }
 if ((e->flags & 0x20) == 0) {
  char *x = mkprints((u_char *) e->cmd, strlen(e->cmd));

  log_it(usernm, getpid(), "CMDEND", x ? x : "**Unknown command**" , 0);
  free(x);
 }
 return 0;
}

static int safe_p(const char *usernm, const char *s) {
 static const char safe_delim[] = "@!:%-.,_+";
 const char *t;
 int ch, first;

 for (t = s, first = 1; (ch = *t++) != '\0'; first = 0) {
  if (
     (((
     ch
     ) & ~0x7f) == 0) 
                 && 
                    ((*__ctype_b_loc ())[(int) ((
                    ch
                    ))] & (unsigned short int) _ISprint) 
                                &&
   (
   ((*__ctype_b_loc ())[(int) ((
   ch
   ))] & (unsigned short int) _ISalnum) 
               || (!first && strchr(safe_delim, ch))))
   continue;
  log_it(usernm, getpid(), "UNSAFE", s, 0);
  return (0);
 }
 return (1);
}
