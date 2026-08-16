













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

int Write_Runlevel_Log(int new_runlevel);
int Read_Runlevel_Log(int *runlevel);
char *Version = "@(#) init " "3.05" " miquels@cistron.nl";
char *bootmsg = "version " "3.05" " %s";


CHILD *family = 
               ((void *)0)
                   ;
CHILD *newFamily = 
                  ((void *)0)
                      ;

CHILD ch_emerg = {
 32, 0, 0, 0, 0,
 "~~",
 "S",
 3,
 "/sbin/sulogin",
 
((void *)0)
    ,
 
((void *)0)

};

char runlevel = 'S';
char thislevel = 'S';
char prevlevel = 'N';
int dfl_level = 0;
sig_atomic_t got_cont = 0;
sig_atomic_t got_signals;
int emerg_shell = 0;
int wrote_wtmp_reboot = 1;
int wrote_utmp_reboot = 1;
int wrote_wtmp_rlevel = 1;
int wrote_utmp_rlevel = 1;
int sleep_time = 3;
char *argv0;
int maxproclen;
struct utmp utproto;
char *console_dev;
int pipe_fd = -1;
int did_boot = 0;
int main(int, char **);


int reload = 0;
char *myname="/sbin/init";
int oops_error;
const char *Signature = "12567362";







struct actions {
  char *name;
  int act;
} actions[] = {
  { "respawn", 1 },
  { "wait", 2 },
  { "once", 3 },
  { "boot", 4 },
  { "bootwait", 5 },
  { "powerfail", 6 },
  { "powerfailnow",14 },
  { "powerwait", 7 },
  { "powerokwait", 8 },
  { "ctrlaltdel", 9 },
  { "off", 10 },
  { "ondemand", 11 },
  { "initdefault", 12 },
  { "sysinit", 13 },
  { "kbrequest", 15 },
  { 
   ((void *)0)
       , 0 },
};




struct {
  char name[4];
  int cmd;
} cmds[] = {
  { "VER", 1 },
  { "END", 2 },
  { "REC", 3 },
  { "EOR", 4 },
  { "LEV", 5 },
  { "FL ", 6 },
  { "AC ", 7 },
  { "CMD", 8 },
  { "PID", 9 },
  { "EXS", 10 },
  { "-RL", -2 },
  { "-TL", -3 },
  { "-PL", -4 },
  { "-SI", -5 },
  { "-WR", -6},
  { "-WU", -7},
  { "-ST", -8 },
  { "-DB", -9 },
  { "-LW", -16},
  { "-LU", -17},
  { "", 0 }
};
struct {
 char *name;
 int mask;
} flags[]={
 {"RU",2},
 {"DE",8},
 {"XD",128},
 {"WT",32},
 {
 ((void *)0)
     ,0}
};


char *extra_env[16];
static
void do_msleep(int msec)
{
 struct timeval tv;

 tv.tv_sec = msec / 1000;
 tv.tv_usec = (msec % 1000) * 1000;

 while(select(0, 
                ((void *)0)
                    , 
                      ((void *)0)
                          , 
                            ((void *)0)
                                , &tv) < 0 && 
                                              (*__errno_location ()) 
                                                    == 
                                                       4
                                                            )
  ;
}





static
void *imalloc(size_t size)
{
 void *m;

 while ((m = malloc(size)) == 
                             ((void *)0)
                                 ) {
  initlog((1|2), "out of memory");
  do_msleep(5000);
 }
 memset(m, 0, size);
 return m;
}

static
char *istrdup(const char *s)
{
 char *m;
 int l;

 l = strlen(s) + 1;
 m = imalloc(l);
 memcpy(m, s, l);
 return m;
}






static
void send_state(int fd)
{
 FILE *fp;
 CHILD *p;
 int i,val;

 fp = fdopen(fd,"w");

 fprintf(fp, "VER%s\n", Version);
 fprintf(fp, "-RL%c\n", runlevel);
 fprintf(fp, "-TL%c\n", thislevel);
 fprintf(fp, "-PL%c\n", prevlevel);
 fprintf(fp, "-SI%u\n", got_signals);
 fprintf(fp, "-WR%d\n", wrote_wtmp_reboot);
 fprintf(fp, "-WU%d\n", wrote_utmp_reboot);
 fprintf(fp, "-ST%d\n", sleep_time);
 fprintf(fp, "-DB%d\n", did_boot);

 for (p = family; p; p = p->next) {
  fprintf(fp, "REC%s\n", p->id);
  fprintf(fp, "LEV%s\n", p->rlevel);
  for (i = 0, val = p->flags; flags[i].mask; i++)
   if (val & flags[i].mask) {
    val &= ~flags[i].mask;
    fprintf(fp, "FL %s\n",flags[i].name);
   }
  fprintf(fp, "PID%d\n",p->pid);
  fprintf(fp, "EXS%u\n",p->exstat);
  for(i = 0; actions[i].act; i++)
   if (actions[i].act == p->action) {
    fprintf(fp, "AC %s\n", actions[i].name);
    break;
   }
  fprintf(fp, "CMD%s\n", p->process);
  fprintf(fp, "EOR\n");
 }
 fprintf(fp, "END\n");
 fclose(fp);
}
static int get_string(char *p, int size, FILE *f)
{
 int c;

 while ((c = getc(f)) != 
                        (-1) 
                            && c != '\n') {
  if (--size > 0)
   *p++ = c;
 }
 *p = '\0';
 return (c != 
             (-1)
                ) && (size > 0);
}




static int get_void(FILE *f)
{
 int c;

 while ((c = getc(f)) != 
                        (-1) 
                            && c != '\n')
  ;

 return (c != 
             (-1)
                );
}




static int get_cmd(FILE *f)
{
 char cmd[4] = "   ";
 int i;

 if (fread(cmd, 1, sizeof(cmd) - 1, f) != sizeof(cmd) - 1)
  return -1;

 for(i = 0; cmds[i].cmd && strcmp(cmds[i].name, cmd) != 0; i++)
  ;
 return cmds[i].cmd;
}




static CHILD *get_record(FILE *f)
{
 int cmd;
 char s[32];
 int i;
 CHILD *p;

 do {
  
 (*__errno_location ()) 
       = 0;
  switch (cmd = get_cmd(f)) {
   case 2:
    get_void(f);
    return 
          ((void *)0)
              ;
   case 0:
    get_void(f);
    break;
   case 3:
    break;
   case -2:
    if (fscanf(f, "%c\n", &runlevel) == 
                                       (-1) 
                                           && 
                                              (*__errno_location ()) 
                                                    != 0) {
     fprintf(
            stderr
                  , "%s (%d): %s\n", "init.c", 406, strerror(
                                                                  (*__errno_location ())
                                                                       ));
    }
    break;
   case -3:
    if (fscanf(f, "%c\n", &thislevel) == 
                                        (-1) 
                                            && 
                                               (*__errno_location ()) 
                                                     != 0) {
     fprintf(
            stderr
                  , "%s (%d): %s\n", "init.c", 411, strerror(
                                                                  (*__errno_location ())
                                                                       ));
    }
    break;
   case -4:
    if (fscanf(f, "%c\n", &prevlevel) == 
                                        (-1) 
                                            && 
                                               (*__errno_location ()) 
                                                     != 0) {
     fprintf(
            stderr
                  , "%s (%d): %s\n", "init.c", 416, strerror(
                                                                  (*__errno_location ())
                                                                       ));
    }
    break;
   case -5:
    if (fscanf(f, "%u\n", &got_signals) == 
                                          (-1) 
                                              && 
                                                 (*__errno_location ()) 
                                                       != 0) {
     fprintf(
            stderr
                  , "%s (%d): %s\n", "init.c", 421, strerror(
                                                                  (*__errno_location ())
                                                                       ));
    }
    break;
   case -6:
    if (fscanf(f, "%d\n", &wrote_wtmp_reboot) == 
                                                (-1) 
                                                    && 
                                                       (*__errno_location ()) 
                                                             != 0) {
     fprintf(
            stderr
                  , "%s (%d): %s\n", "init.c", 426, strerror(
                                                                  (*__errno_location ())
                                                                       ));
    }
    break;
   case -7:
    if (fscanf(f, "%d\n", &wrote_utmp_reboot) == 
                                                (-1) 
                                                    && 
                                                       (*__errno_location ()) 
                                                             != 0) {
     fprintf(
            stderr
                  , "%s (%d): %s\n", "init.c", 431, strerror(
                                                                  (*__errno_location ())
                                                                       ));
    }
    break;
   case -8:
    if (fscanf(f, "%d\n", &sleep_time) == 
                                         (-1) 
                                             && 
                                                (*__errno_location ()) 
                                                      != 0) {
     fprintf(
            stderr
                  , "%s (%d): %s\n", "init.c", 436, strerror(
                                                                  (*__errno_location ())
                                                                       ));
    }
    break;
   case -9:
    if (fscanf(f, "%d\n", &did_boot) == 
                                       (-1) 
                                           && 
                                              (*__errno_location ()) 
                                                    != 0) {
     fprintf(
            stderr
                  , "%s (%d): %s\n", "init.c", 441, strerror(
                                                                  (*__errno_location ())
                                                                       ));
    }
    break;
   case -16:
    if (fscanf(f, "%d\n", &wrote_wtmp_rlevel) == 
                                                (-1) 
                                                    && 
                                                       (*__errno_location ()) 
                                                             != 0) {
     fprintf(
            stderr
                  , "%s (%d): %s\n", "init.c", 446, strerror(
                                                                  (*__errno_location ())
                                                                       ));
    }
    break;
   case -17:
    if (fscanf(f, "%d\n", &wrote_utmp_rlevel) == 
                                                (-1) 
                                                    && 
                                                       (*__errno_location ()) 
                                                             != 0) {
     fprintf(
            stderr
                  , "%s (%d): %s\n", "init.c", 451, strerror(
                                                                  (*__errno_location ())
                                                                       ));
    }
    break;
   default:
    if (cmd > 0 || cmd == -1) {
     oops_error = -1;
     return 
           ((void *)0)
               ;
    }
  }
 } while (cmd != 3);

 p = imalloc(sizeof(CHILD));
 get_string(p->id, sizeof(p->id), f);

 do switch(cmd = get_cmd(f)) {
  case 0:
  case 4:
   get_void(f);
   break;
  case 9:
   if (fscanf(f, "%d\n", &(p->pid)) == 
                                      (-1) 
                                          && 
                                             (*__errno_location ()) 
                                                   != 0) {
    fprintf(
           stderr
                 , "%s (%d): %s\n", "init.c", 472, strerror(
                                                                 (*__errno_location ())
                                                                      ));
   }
   break;
  case 10:
   if (fscanf(f, "%u\n", &(p->exstat)) == 
                                         (-1) 
                                             && 
                                                (*__errno_location ()) 
                                                      != 0) {
    fprintf(
           stderr
                 , "%s (%d): %s\n", "init.c", 477, strerror(
                                                                 (*__errno_location ())
                                                                      ));
   }
   break;
  case 5:
   get_string(p->rlevel, sizeof(p->rlevel), f);
   break;
  case 8:
   get_string(p->process, sizeof(p->process), f);
   break;
  case 6:
   get_string(s, sizeof(s), f);
   for(i = 0; flags[i].name; i++) {
    if (strcmp(flags[i].name,s) == 0)
     break;
   }
   p->flags |= flags[i].mask;
   break;
  case 7:
   get_string(s, sizeof(s), f);
   for(i = 0; actions[i].name; i++) {
    if (strcmp(actions[i].name, s) == 0)
     break;
   }
   p->action = actions[i].act ? actions[i].act : 10;
   break;
  default:
   free(p);
   oops_error = -1;
   return 
         ((void *)0)
             ;
 } while( cmd != 4);

 return p;
}





static
int receive_state(int fd)
{
 FILE *f;
 char old_version[256];
 CHILD **pp;

 f = fdopen(fd, "r");

  if (get_cmd(f) != 1) {
  fclose(f);
  return -1;
 }
 get_string(old_version, sizeof(old_version), f);
 oops_error = 0;
 for (pp = &family; (*pp = get_record(f)) != 
                                            ((void *)0)
                                                ; pp = &((*pp)->next))
  ;
 fclose(f);
 return oops_error;
}






__attribute__ ((format (printf, 1, 2)))




static int setproctitle(char *fmt, ...)
{
 va_list ap;
 int len;
 char buf[256];

 buf[0] = 0;

 
__builtin_va_start(
ap
,
fmt
)
                 ;
 len = vsnprintf(buf, sizeof(buf), fmt, ap);
 
__builtin_va_end(
ap
)
          ;

 if (maxproclen > 1) {
  memset(argv0, 0, maxproclen);
  strncpy(argv0, buf, maxproclen - 1);
 }

 return len;
}





static
void console_init(void)
{
 int fd;
 int tried_devcons = 0;
 int tried_vtmaster = 0;
 char *s;

 if ((s = getenv("CONSOLE")) != 
                               ((void *)0)
                                   )
  console_dev = s;
 else {
  console_dev = "/dev/console";
  tried_devcons++;
 }

 while ((fd = open(console_dev, 
                               00
                                       |
                                        04000
                                                  )) < 0) {
  if (!tried_devcons) {
   tried_devcons++;
   console_dev = "/dev/console";
   continue;
  }
  if (!tried_vtmaster) {
   tried_vtmaster++;
   console_dev = "/dev/tty0";
   continue;
  }
  break;
 }
 if (fd < 0)
  console_dev = "/dev/null";
 else
  close(fd);
}





static
int console_open(int mode)
{
 int f, fd = -1;
 int m;




 m = mode | 
           04000
                     ;




 for(f = 0; f < 5; f++) {
  if ((fd = open(console_dev, m)) >= 0) break;
  usleep(10000);
 }

 if (fd < 0) return fd;




 if (m != mode)
    fcntl(fd, 
             4
                    , mode);
 return fd;
}




static
void signal_handler(int sig)
{
 ((got_signals) |= (1 << (sig)));
}




static

void chld_handler(int sig __attribute__((unused)))



{
 CHILD *ch;
 int pid, st;
 int saved_errno = 
                   (*__errno_location ())
                        ;




 while((pid = waitpid(-1, &st, 
                              1
                                     )) != 0) {
  if (
     (*__errno_location ()) 
           == 
              10
                    ) break;
  for( ch = family; ch; ch = ch->next )
   if ( ch->pid == pid && (ch->flags & 2) ) {
   

             ;
    ((got_signals) |= (1 << (
   17
   )));
    ch->exstat = st;
    ch->flags |= 64;
    if (ch->new) {
     ch->new->exstat = st;
     ch->new->flags |= 64;
    }
    break;
   }
  if (ch == 
           ((void *)0)
               ) {
  
        ;
  }
 }
 
(*__errno_location ()) 
      = saved_errno;
}
static

void cont_handler(int sig __attribute__((unused)))



{
 got_cont = 1;
}




static
void coredump(void)
{
 static int dumped = 0;
 struct rlimit rlim;
 sigset_t mask;

 if (dumped) return;
 dumped = 1;

 if (fork() != 0) return;

 sigfillset(&mask);
 sigprocmask(
            2
                       , &mask, 
                                ((void *)0)
                                    );

 rlim.rlim_cur = 
                ((__rlim_t) -1)
                             ;
 rlim.rlim_max = 
                ((__rlim_t) -1)
                             ;
 setrlimit(
          RLIMIT_CORE
                     , &rlim);
 if (0 != chdir("/"))
  initlog((1|2), "unable to chdir to /: %s",
   strerror(
           (*__errno_location ())
                ));

 signal(
       11
              , 
                ((__sighandler_t) 0)
                       );
 raise(
      11
             );
 sigdelset(&mask, 
                 11
                        );
 sigprocmask(
            2
                       , &mask, 
                                ((void *)0)
                                    );

 do_msleep(5000);
 exit(0);
}






static
void segv_handler(int sig __attribute__((unused)))



{
 int saved_errno = 
                  (*__errno_location ())
                       ;

 initlog((1|2),
  "PANIC: segmentation violation! sleeping for 30 seconds.");
 coredump();
 do_msleep(30000);
 
(*__errno_location ()) 
      = saved_errno;
}





static

void stop_handler(int sig __attribute__((unused)))



{
 int saved_errno = 
                  (*__errno_location ())
                       ;

 got_cont = 0;
 while(!got_cont) pause();
 got_cont = 0;
 
(*__errno_location ()) 
      = saved_errno;
}




static
void console_stty(void)
{
 struct termios tty;
 int fd;

 if ((fd = console_open(
                       02
                             |
                              0400
                                      )) < 0) {
  initlog((1|2), "can't open %s", console_dev);
  return;
 }
 (void) tcgetattr(fd, &tty);

 tty.c_cflag &= 
               000000010017
                    |
                     000000010000
                            |
                             0000060
                                  |
                                   0000100
                                         |
                                          0000400
                                                |
                                                 0001000
                                                       ;
 tty.c_cflag |= 
               0002000
                    |
                     0004000
                           |
                            0000200
                                 ;

 tty.c_cc[
         0
              ] = 
                      ('c'&037)
                           ;
 tty.c_cc[
         1
              ] = 
                      034
                           ;
 tty.c_cc[
         2
               ] = 
                      0177
                            ;
 tty.c_cc[
         3
              ] = 
                      ('u'&037)
                           ;
 tty.c_cc[
         4
             ] = 
                     ('d'&037)
                         ;
 tty.c_cc[
         5
              ] = 0;
 tty.c_cc[
         6
             ] = 1;

 tty.c_cc[
         7
              ] = 
                      '\0'
                                     ;

 tty.c_cc[
         8
               ] = 
                      ('q'&037)
                            ;
 tty.c_cc[
         9
              ] = 
                      ('s'&037)
                           ;
 tty.c_cc[
         10
              ] = 
                      ('z'&037)
                           ;
 tty.c_cc[
         11
             ] = 
                     '\0'
                                    ;
 tty.c_cc[
         12
                 ] = 
                      ('r'&037)
                              ;
 tty.c_cc[
         13
                 ] = 
                      ('o'&037)
                              ;
 tty.c_cc[
         14
                ] = 
                      ('w'&037)
                             ;
 tty.c_cc[
         15
               ] = 
                      ('v'&037)
                            ;
 tty.c_cc[
         16
              ] = 
                      '\0'
                                     ;




 tty.c_iflag = 
              0000004
                    |
                     0000400
                          |
                           0002000
                               |
                                0004000

   
  | (tty.c_iflag & 
                   0040000
                        )

  ;
 tty.c_oflag = 
              0000001
                   |
                    0000004
                         ;
 tty.c_lflag = 
              0000001
                  |
                   0000002
                         |
                          0000010
                              |
                               0001000
                                      |
                                       0000020
                                            |
                                             0004000
                                                   ;
 (void) tcsetattr(fd, 
                     0
                            , &tty);
 (void) tcflush(fd, 
                   2
                            );
 (void) close(fd);
}

static ssize_t
safe_write(int fd, const char *buffer, size_t count)
{
 ssize_t offset = 0;

 while (count > 0) {
  ssize_t block = write(fd, &buffer[offset], count);

  if (block < 0 && 
                  (*__errno_location ()) 
                        == 
                           4
                                )
   continue;
  if (block <= 0)
   return offset ? offset : block;
  offset += block;
  count -= block;
 }
 return offset;
}




void print(char *s)
{
 int fd;

 if ((fd = console_open(
                       01
                               |
                                0400
                                        |
                                         04000
                                                 )) >= 0) {
  safe_write(fd, s, strlen(s));
  close(fd);
 }
}





__attribute__ ((format (printf, 2, 3)))

void initlog(int loglevel, char *s, ...)
{
 va_list va_alist;
 char buf[256];
 sigset_t nmask, omask;

 
__builtin_va_start(
va_alist
,
s
)
                     ;
 vsnprintf(buf, sizeof(buf), s, va_alist);
 
__builtin_va_end(
va_alist
)
                ;

 if (loglevel & 2) {




  sigfillset(&nmask);
  sigprocmask(
             0
                      , &nmask, &omask);
  openlog("init", 0, 
                    (3<<3)
                              );
  syslog(
        6
                , "%s", buf);
  closelog();
  sigprocmask(
             2
                        , &omask, 
                                  ((void *)0)
                                      );
 }




 if (loglevel & 1) {
  print("\rINIT: ");
  print(buf);
  print("\r\n");
 }
}




int addnewenv(const char *new, char **curr, int n)
{
 size_t nlen = strcspn(new, "=");
 int i;
 for (i = 0; i < n; i++) {
  if (nlen != strcspn(curr[i], "="))
   continue;
  if (strncmp (new, curr[i], nlen) == 0)
   break;
 }
 if (i >= n)
  curr[n++] = istrdup(new);
 else {
  free(curr[i]);
  curr[i] = istrdup(new);
 }
 return n;
}




char **init_buildenv(int child)
{
 char i_lvl[] = "RUNLEVEL=x";
 char i_prev[] = "PREVLEVEL=x";
 char i_cons[128];
 char i_shell[] = "SHELL=" "/bin/sh";
 char **e;
 int n, i;

 for (n = 0; environ[n]; n++)
  ;
 n += 16 + 1;
 if (child)
  n += 8;

 while ((e = (char**)calloc(n, sizeof(char *))) == 
                                                  ((void *)0)
                                                      ) {
  initlog((1|2), "out of memory");
  do_msleep(5000);
 }

 for (n = 0; environ[n]; n++)
  e[n] = istrdup(environ[n]);

 for (i = 0; i < 16; i++) {
  if (extra_env[i] == 
                     ((void *)0) 
                          || *extra_env[i] == '\0')
   continue;
  n = addnewenv(extra_env[i], e, n);
 }

 if (child) {
  snprintf(i_cons, sizeof(i_cons), "CONSOLE=%s", console_dev);
  i_lvl[9] = thislevel;
  i_prev[10] = prevlevel;
  n = addnewenv(i_shell, e, n);
  n = addnewenv(i_lvl, e, n);
  n = addnewenv(i_prev, e, n);
  n = addnewenv(i_cons, e, n);
  n = addnewenv("INIT_VERSION=sysvinit-" "3.05", e, n);
 }

 e[n++] = 
         ((void *)0)
             ;

 return e;
}


void init_freeenv(char **e)
{
 int n;

 for (n = 0; e[n]; n++)
  free(e[n]);
 free(e);
}
static
pid_t spawn(CHILD *ch, int *res)
{
  char *args[16];
  char buf[136];
  int f, st;
  char *ptr;
  time_t t;
  int oldAlarm;
  char *proc = ch->process;
  pid_t pid, pgrp;
  sigset_t nmask, omask;
  struct sigaction sa;

  *res = -1;
  buf[sizeof(buf) - 1] = 0;


  if (proc[0] == '+') proc++;

  ch->flags |= 128;

  if (ch->action == 1 || ch->action == 11) {

 time(&t);
 if (ch->tm + 120 > t) {
  ch->count++;
 } else {
  ch->count = 0;
  ch->tm = t;
 }


 if (ch->count >= 10) {

   initlog((1|2),
  "Id \"%s\" respawning too fast: disabled for %d minutes",
  ch->id, 300 / 60);
   ch->flags &= ~2;
   ch->flags |= 16;


   ch->tm = t;


   oldAlarm = alarm(0);
   if (oldAlarm > 300 || oldAlarm <= 0) oldAlarm = 300;
   alarm(oldAlarm);
   return(-1);
 }
  }


  if (access("/etc/initscript", 
                        4
                            ) == 0 && runlevel != 'S') {

 args[1] = "/bin/sh";
 args[2] = "/etc/initscript";
 args[3] = ch->id;
 args[4] = ch->rlevel;
 args[5] = "unknown";
 for(f = 0; actions[f].name; f++) {
  if (ch->action == actions[f].act) {
   args[5] = actions[f].name;
   break;
  }
 }
        if (proc[0] == '@') proc++;
 args[6] = proc;
 args[7] = 
          ((void *)0)
              ;
  } else if ( (strpbrk(proc, "~`!$^&*()=|\\{}[];\"'<>?")) && (proc[0] != '@') ){



   args[1] = "/bin/sh";
   args[2] = "-c";
   strcpy(buf, "exec ");
   strncat(buf, proc, sizeof(buf) - strlen(buf) - 1);
   args[3] = buf;
   args[4] = 
            ((void *)0)
                ;
  } else {

 buf[0] = 0;
        if (proc[0] == '@') proc++;
   strncat(buf, proc, sizeof(buf) - 1);
   ptr = buf;
   for(f = 1; f < 15; f++) {

    while(*ptr == ' ' || *ptr == '\t') ptr++;
    args[f] = ptr;


  if (*ptr == 0) break;


    while(*ptr && *ptr != ' ' && *ptr != '\t' && *ptr != '#')
     ptr++;


    if (*ptr == '#' || *ptr == 0) {
     f++;
     *ptr = 0;
     break;
    }

    *ptr++ = 0;
   }
   args[f] = 
            ((void *)0)
                ;
  }
  args[0] = args[1];
  while(1) {



 sigemptyset(&nmask);
 sigaddset(&nmask, 
                  17
                         );
 sigprocmask(
            0
                     , &nmask, &omask);

 if ((pid = fork()) == 0) {

  close(0);
  close(1);
  close(2);
  if (pipe_fd >= 0)
                {
                    close(pipe_fd);
                    pipe_fd = -1;
                }

    sigprocmask(
               2
                          , &omask, 
                                    ((void *)0)
                                        );






    if (strchr("*#sS", runlevel) && ch->flags & 32) {
   int ftty;





   setsid();
   if ((ftty = console_open(
                           02
                                 |
                                  0400
                                          )) >= 0) {

    (void)ioctl(ftty, 
                     0x540E
                              , 1);

    if(dup(ftty) < 0){
            initlog((1|2), "cannot duplicate console fd");
    }

    if(dup(ftty) < 0){
            initlog((1|2), "cannot duplicate console fd");
    }

   }
   do { memset(&sa, 0, sizeof(sa)); sa.
  __sigaction_handler.sa_handler 
  = 
  ((__sighandler_t) 0)
  ; sa.sa_flags = 
  0x10000000
  ; sigemptyset(&sa.sa_mask); sigaction(
  17
  , &sa, 
  ((void *)0)
  ); } while(0);
   if ((pid = fork()) < 0) {
      initlog((1|2), "cannot fork: %s",
     strerror(
             (*__errno_location ())
                  ));
    exit(1);
   }
   if (pid > 0) {
    pid_t rc;




    do { memset(&sa, 0, sizeof(sa)); sa.
   __sigaction_handler.sa_handler 
   = 
   ((__sighandler_t) 1)
   ; sa.sa_flags = 
   0x10000000
   ; sigemptyset(&sa.sa_mask); sigaction(
   2
   , &sa, 
   ((void *)0)
   ); } while(0);
    do { memset(&sa, 0, sizeof(sa)); sa.
   __sigaction_handler.sa_handler 
   = 
   ((__sighandler_t) 1)
   ; sa.sa_flags = 
   0x10000000
   ; sigemptyset(&sa.sa_mask); sigaction(
   20
   , &sa, 
   ((void *)0)
   ); } while(0);
    do { memset(&sa, 0, sizeof(sa)); sa.
   __sigaction_handler.sa_handler 
   = 
   ((__sighandler_t) 1)
   ; sa.sa_flags = 
   0x10000000
   ; sigemptyset(&sa.sa_mask); sigaction(
   3
   , &sa, 
   ((void *)0)
   ); } while(0);

    while ((rc = waitpid(pid, &st, 0)) != pid)
     if (rc < 0 && 
                  (*__errno_location ()) 
                        == 
                           10
                                 )
      break;





    pgrp = tcgetpgrp(ftty);
    if (pgrp != getpid())
     exit(0);





    if ((pid = fork()) < 0) {
       initlog((1|2), "cannot fork: %s",
      strerror(
              (*__errno_location ())
                   ));
     exit(1);
    }
    if (pid == 0) {
     setsid();
     (void)ioctl(ftty, 
                      0x540E
                               , 1);
     exit(0);
    }
    while((rc = waitpid(pid, &st, 0)) != pid)
     if (rc < 0 && 
                  (*__errno_location ()) 
                        == 
                           10
                                 )
      break;
    exit(0);
   }


   console_stty();

    } else {
   int fd;
   setsid();
   if ((fd = console_open(
                         02
                               |
                                0400
                                        )) < 0) {
    initlog((1|2), "open(%s): %s", console_dev,
     strerror(
             (*__errno_location ())
                  ));
    fd = open("/dev/null", 
                          02
                                );
   }

   if(dup(fd) < 0) {
    initlog((1|2), "cannot duplicate /dev/null fd");
   }

   if(dup(fd) < 0) {
    initlog((1|2), "cannot duplicate /dev/null fd");
   }

  }
  if (ch->process[0] != '+')
   write_utmp_wtmp("", ch->id, getpid(), 
                                        5
                                                    , "");


    for(f = 1; f < 
                  (64 + 1)
                      ; f++) do { memset(&sa, 0, sizeof(sa)); sa.
                             __sigaction_handler.sa_handler 
                             = 
                             ((__sighandler_t) 0)
                             ; sa.sa_flags = 
                             0x10000000
                             ; sigemptyset(&sa.sa_mask); sigaction(f, &sa, 
                             ((void *)0)
                             ); } while(0);
  environ = init_buildenv(1);





    execvp(args[1], args + 1);
  if (
     (*__errno_location ()) 
           == 
              8
                     ) {
     args[1] = "/bin/sh";
     args[2] = "-c";
     strcpy(buf, "exec ");
     strncat(buf, proc, sizeof(buf) - strlen(buf) - 1);
     args[3] = buf;
     args[4] = 
              ((void *)0)
                  ;
   execvp(args[1], args + 1);
  }
    initlog((1|2), "cannot execute \"%s\"", args[1]);

  if (ch->process[0] != '+')
   write_utmp_wtmp("", ch->id, getpid(), 
                                        8
                                                    , 
                                                      ((void *)0)
                                                          );
    exit(1);
   }
 *res = pid;
   sigprocmask(
              2
                         , &omask, 
                                   ((void *)0)
                                       );

 ;

 if (pid == -1) {
  initlog((1|2), "cannot fork, retry..");
 do_msleep(5000);
  continue;
 }
 return(pid);
  }
}




static
void startup(CHILD *ch)
{



 if (ch->flags & 16) return;

 switch(ch->action) {

  case 13:
  case 5:
  case 2:
  case 7:
  case 14:
  case 8:
  case 9:
   if (!(ch->flags & 128)) ch->flags |= 32;

  case 15:
  case 4:
  case 6:
  case 3:
   if (ch->flags & 128) break;

  case 11:
  case 1:
     ch->flags |= 2;
     (void)spawn(ch, &(ch->pid));
     break;
 }
}


static
void check_kernel_console()
{
 FILE* fp;
 char buf[4096];
 if ((fp = fopen("/proc/cmdline", "r")) == 0) {
  return;
 }
 if (fgets(buf, sizeof(buf), fp)) {
  char* p = buf;
           if ( strstr(p, "init.autocon=1") )
           {
  while ((p = strstr(p, "console="))) {
   char* e;
   p += strlen("console=");
   for (e = p; *e; ++e) {
    switch (*e) {
     case '-' ... '9':
     case 'A' ... 'Z':
     case '_':
     case 'a' ... 'z':
      continue;
    }
    break;
   }
   if (p != e) {
    CHILD* old;
    int dup = 0;
    char id[8] = {0};
    char dev[32] = {0};
    strncpy(dev, p, 
                   (((
                   sizeof(dev)
                   )<(
                   (unsigned)(e-p)
                   ))?(
                   sizeof(dev)
                   ):(
                   (unsigned)(e-p)
                   ))
                                                    );
    if (!strncmp(dev, "tty", 3))
     strncpy(id, dev+3, sizeof(id));
    else
     strncpy(id, dev, sizeof(id));

    for(old = newFamily; old; old = old->next) {
     if (!strcmp(old->id, id)) {
      dup = 1;
     }
    }
    if (!dup) {
     CHILD* ch = imalloc(sizeof(CHILD));
     ch->action = 1;
     strcpy(ch->id, id);
     strcpy(ch->rlevel, "2345");
     sprintf(ch->process, "/sbin/agetty -L -s 115200,38400,9600 %s vt102", dev);
     ch->next = 
               ((void *)0)
                   ;
     for(old = family; old; old = old->next) {
      if (strcmp(old->id, ch->id) == 0) {
       old->new = ch;
       break;
      }
     }

     for(old = newFamily; old; old = old->next) {
      if (!old->next) {
       old->next = ch;
       break;
      }
     }

     initlog((1|2), "added agetty on %s with id %s", dev, id);
    }
   }
  }
            }
 }
 fclose(fp);
 return;
}





static
void read_inittab(void)
{
  FILE *fp;
  FILE *fp_tab;
  CHILD *ch, *old, *i;
  CHILD *head = 
                ((void *)0)
                    ;



  sigset_t nmask, omask;
  char buf[256];
  char err[64];
  char *id, *rlevel,
  *action, *process;
  char *p;
  int lineNo = 0;
  int actionNo;
  int f;
  int round;
  int foundOne = 0;
  int talk;
  int done = -1;
  DIR *tabdir=
               ((void *)0)
                   ;
  struct dirent *file_entry;
  char f_name[272];
  if ((fp = fopen("/etc/inittab", "r")) == 
                                   ((void *)0)
                                       )
 initlog((1|2), "No inittab file found");




  if( (tabdir = opendir("/etc/inittab.d"))==
                                   ((void *)0)
                                       )
   initlog((1|2), "No inittab.d directory found");

  while(done!=1) {



 if(done == -1) {
  if (fp == 
           ((void *)0) 
                || fgets(buf, sizeof(buf), fp) == 
                                                  ((void *)0)
                                                      ) {
   done = 0;



   for(old = newFamily; old; old = old->next)
    if (strpbrk(old->rlevel, "S")) break;
   if (old == 
             ((void *)0)
                 )
    snprintf(buf, sizeof(buf), "~~:S:wait:%s\n", "/sbin/sulogin");
   else
    continue;
  }
 }
 else if ( done == 0 ){

  if(tabdir!=
            ((void *)0)
                ){
   if( (file_entry = readdir(tabdir))!=
                                      ((void *)0)
                                          ){

    if (!strcmp(file_entry->d_name, ".") || !strcmp(file_entry->d_name, ".."))
     continue;
    if (strlen(file_entry->d_name) < 5 || strcmp(file_entry->d_name + strlen(file_entry->d_name) - 4, ".tab"))
     continue;



    memset(f_name,0,sizeof(char)*272);
    snprintf(f_name,272,"/etc/inittab.d/%s",file_entry->d_name);
    initlog((1|2), "Reading: %s",f_name);



    if ((fp_tab = fopen(f_name, "r")) == 
                                        ((void *)0)
                                            )
     continue;

    while( fgets(buf, sizeof(buf), fp_tab) != 
                                             ((void *)0)
                                                 ) {
     for(p = buf; *p == ' ' || *p == '\t'; p++);
     if (*p != '#' && *p != '\n')
      break;
    }
    fclose(fp_tab);

    if( strlen( p ) == 0 )
     continue;
   }
   else {
    done = 1;
    continue;
   }
  }
  else {
   done = 1;
   continue;
  }
 }
 lineNo++;



 for(p = buf; *p == ' ' || *p == '\t'; p++)
  ;
 if (*p == '#' || *p == '\n') continue;




 id = strsep(&p, ":");
 rlevel = strsep(&p, ":");
 action = strsep(&p, ":");
 process = strsep(&p, "\n");





 err[0] = 0;
 if (!id || !*id) strcpy(err, "missing id field");
 if (!rlevel) strcpy(err, "missing runlevel field");
 if (!process) strcpy(err, "missing process field");
 if (!action || !*action)
   strcpy(err, "missing action field");
 if (id && strlen(id) > sizeof(utproto.ut_id))
  sprintf(err, "id field too long (max %d characters)",
   (int)sizeof(utproto.ut_id));
 if (rlevel && strlen(rlevel) > 11)
  strcpy(err, "rlevel field too long (max 11 characters)");
 if (process && strlen(process) > 127)
  strcpy(err, "process field too long (max 127 characters)");
 if (action && strlen(action) > 32)
  strcpy(err, "action field too long");
 if (err[0] != 0) {
  initlog((1|2), "%s[%d]: %s", "/etc/inittab", lineNo, err);
  ;
  continue;
 }




 actionNo = -1;
 for(f = 0; actions[f].name; f++)
  if (strcasecmp(action, actions[f].name) == 0) {
   actionNo = actions[f].act;
   break;
  }
 if (actionNo == -1) {
  initlog((1|2), "%s[%d]: %s: unknown action field",
   "/etc/inittab", lineNo, action);
  continue;
 }




 for(old = newFamily; old; old = old->next) {
  if(strcmp(old->id, id) == 0 && strcmp(id, "~~")) {
   initlog((1|2), "%s[%d]: duplicate ID field \"%s\"",
    "/etc/inittab", lineNo, id);
   break;
  }
 }
 if (old) continue;




 ch = imalloc(sizeof(CHILD));




 ch->action = actionNo;
 strncpy(ch->id, id, sizeof(utproto.ut_id) + 1);
 strncpy(ch->process, process, sizeof(ch->process) - 1);
 if (rlevel[0]) {
  for(f = 0; f < (int)sizeof(rlevel) - 1 && rlevel[f]; f++) {
   ch->rlevel[f] = rlevel[f];
   if (ch->rlevel[f] == 's') ch->rlevel[f] = 'S';
  }
  strncpy(ch->rlevel, rlevel, sizeof(ch->rlevel) - 1);
 } else {
  strcpy(ch->rlevel, "0123456789");
  if (((ch->action) == 7 || (ch->action) == 6 || (ch->action) == 8 || (ch->action) == 14 || (ch->action) == 9))
   strcpy(ch->rlevel, "S0123456789");
 }




 if (ch->action == 13) strcpy(ch->rlevel, "#");
 if (ch->action == 4 || ch->action == 5)
  strcpy(ch->rlevel, "*");




 if (((ch->action) == 7 || (ch->action) == 6 || (ch->action) == 8 || (ch->action) == 14 || (ch->action) == 9)) {




  ch->flags |= 128;




  old = 
       ((void *)0)
           ;
  for(i = newFamily; i; i = i->next) {
   if (!((i->action) == 7 || (i->action) == 6 || (i->action) == 8 || (i->action) == 14 || (i->action) == 9)) break;
   old = i;
  }



  if (old) {
   ch->next = i;
   old->next = ch;
   if (i == 
           ((void *)0)
               ) head = ch;
  } else {
   ch->next = newFamily;
   newFamily = ch;
   if (ch->next == 
                  ((void *)0)
                      ) head = ch;
  }
 } else {



  if (ch->action == 15) ch->flags |= 128;
  ch->next = 
            ((void *)0)
                ;
  if (head)
   head->next = ch;
  else
   newFamily = ch;
  head = ch;
 }




 for(old = family; old; old = old->next)
  if (strcmp(old->id, ch->id) == 0) {
   old->new = ch;
   break;
  }
  }




  if (fp) fclose(fp);
  if(tabdir) closedir(tabdir);


  check_kernel_console();







  ;
  for(round = 0; round < 2; round++) {
    talk = 1;
    for(ch = family; ch; ch = ch->next) {
 ch->flags &= ~4;




 if (ch->new == 
               ((void *)0)
                   ) ch->flags |= 4;
 if (ch->new && ch->action != ch->new->action) ch->flags |= 4;




 if (ch->action != 4 &&
     strchr(ch->rlevel, runlevel) == 
                                    ((void *)0)
                                        ) {




  if (runlevel == 'S' || !(ch->flags & 8))
   ch->flags |= 4;
 }




 if ((ch->flags & 4) == 0) {
  ch->new->flags = ch->flags;
  ch->new->pid = ch->pid;
  ch->new->exstat = ch->exstat;
  continue;
 }





 if ((ch->flags & 2) == 0) {
  ch->flags &= ~4;
  continue;
 }
 ;
 switch(round) {
  case 0:
   if (talk)
    initlog(1,
     "Sending processes configured via /etc/inittab the TERM signal");
   kill(-(ch->pid), 
                   15
                          );
   foundOne = 1;
   break;
  case 1:
   if (talk)
    initlog(1,
     "Sending processes configured via /etc/inittab the KILL signal");
   kill(-(ch->pid), 
                   9
                          );
   break;
 }
 talk = 0;

    }



    if (foundOne && round == 0) {




 for(f = 0; f < 100 * sleep_time; f++) {
  for(ch = family; ch; ch = ch->next) {
   if (!(ch->flags & 4)) continue;
   if ((ch->flags & 2) && !(ch->flags & 64))
    break;
  }
  if (ch == 
           ((void *)0)
               ) {



   round = 1;
   foundOne = 0;
   break;
  }
  do_msleep(10);
 }
    }
  }




  if (foundOne) do_msleep(10);
  for(ch = family; ch; ch = ch->next)
 if (ch->flags & 4) {
  if (!(ch->flags & 64))
      initlog(1, "Pid %d [id %s] seems to hang", ch->pid,
    ch->id);
  else {
     
                    ;
      ch->flags &= ~2;
      if (ch->process[0] != '+')
       write_utmp_wtmp("", ch->id, ch->pid, 
                                           8
                                                       , 
                                                         ((void *)0)
                                                             );
  }
 }




  sigemptyset(&nmask);
  sigaddset(&nmask, 
                   17
                          );
  sigprocmask(
             0
                      , &nmask, &omask);
  for(ch = family; ch; ch = old) {
 old = ch->next;
 free(ch);
  }
  family = newFamily;
  for(ch = family; ch; ch = ch->next) ch->new = 
                                               ((void *)0)
                                                   ;
  newFamily = 
             ((void *)0)
                 ;
  sigprocmask(
             2
                        , &omask, 
                                  ((void *)0)
                                      );
}






static
void start_if_needed(void)
{
 CHILD *ch;
 int delete;

 ;

 for(ch = family; ch; ch = ch->next) {
  if (ch->flags & 32) break;


  if (ch->flags & 2) continue;


  delete = 1;
  if (strchr(ch->rlevel, runlevel) ||
      ((ch->flags & 8) && !strchr("#*Ss", runlevel))) {
   startup(ch);
   delete = 0;
  }

  if (delete) {

   ch->flags &= ~(2|32);
   if (!((ch->action) == 7 || (ch->action) == 6 || (ch->action) == 8 || (ch->action) == 14 || (ch->action) == 9) && ch->action != 15)
    ch->flags &= ~128;
   ch->pid = 0;
  } else

   if (ch->flags & 32) break;
 }

}




static
int ask_runlevel(void)
{
 const char prompt[] = "\nEnter runlevel: ";
 char buf[8];
 int lvl = -1;
 int fd;

 console_stty();
 fd = console_open(
                  02
                        |
                         0400
                                 );

 if (fd < 0) return('S');

 while(!strchr("0123456789S", lvl)) {
  safe_write(fd, prompt, sizeof(prompt) - 1);
  if (read(fd, buf, sizeof(buf)) <= 0)
   buf[0] = 0;
    if (buf[0] != 0 && (buf[1] == '\r' || buf[1] == '\n'))
   lvl = buf[0];
  if (
     ((*__ctype_b_loc ())[(int) ((
     lvl
     ))] & (unsigned short int) _ISlower)
                 ) lvl = toupper(lvl);
 }
 close(fd);
 return lvl;
}





static
int get_init_default(void)
{
 CHILD *ch;
 int lvl = -1;
 char *p;




 for(ch = family; ch; ch = ch->next)
  if (ch->action == 12) {
   p = ch->rlevel;
   while(*p) {
    if (*p > lvl) lvl = *p;
    p++;
   }
   break;
  }



 if (lvl > 0) {
  if (
     ((*__ctype_b_loc ())[(int) ((
     lvl
     ))] & (unsigned short int) _ISlower)
                 ) lvl = toupper(lvl);
  if (strchr("0123456789S", lvl) == 
                                   ((void *)0)
                                       ) {
   initlog((1|2),
    "Initdefault level '%c' is invalid", lvl);
   lvl = 0;
  }
 }



 if (lvl <= 0) lvl = ask_runlevel();




        Write_Runlevel_Log(lvl);
 return lvl;
}
static
int read_level(int arg)
{
 CHILD *ch;
 unsigned char foo = 'X';
 int ok = 1;






 if (arg) foo = arg;
 if (
    ((*__ctype_b_loc ())[(int) ((
    foo
    ))] & (unsigned short int) _ISlower)
                ) foo = toupper(foo);
 if (ok < 1 || ok > 2 || strchr("QS0123456789ABCU", foo) == 
                                                           ((void *)0)
                                                               ) {
   initlog((1|2), "bad runlevel: %c", foo);
    return runlevel;
 }


 switch(foo) {
  case 'S':
     initlog((1|2), "Going single user");
   break;
  case 'Q':
   initlog(2, "Re-reading inittab");
   break;
  case 'A':
  case 'B':
  case 'C':
   initlog(2,
    "Activating demand-procedures for '%c'", foo);
   break;
  case 'U':
   initlog(2, "Trying to re-exec init");
   return 'U';
  default:
     initlog((1|2), "Switching to runlevel: %c", foo);
 }

 if (foo == 'Q') {





  return runlevel;
 }


 if (strchr("ABC", foo)) {
  if (runlevel == 'S') return(runlevel);


  read_inittab();


  for(ch = family; ch; ch = ch->next)
   if (strchr(ch->rlevel, foo) != 
                                 ((void *)0) 
                                      ||
       strchr(ch->rlevel, tolower(foo)) != 
                                          ((void *)0)
                                              ) {
    ch->flags |= 8;
    ch->flags &= ~128;
   

                       ;
   }
    return runlevel;
 }


 wrote_utmp_rlevel = 0;
 wrote_wtmp_rlevel = 0;
 write_utmp_wtmp("runlevel", "~~", foo + 256*runlevel, 
                                                      1
                                                             , "~");
 thislevel = foo;
 prevlevel = runlevel;
        Write_Runlevel_Log(runlevel);
 return foo;
}
static
void fail_check(void)
{
 CHILD *ch;
 time_t t;
 time_t next_alarm = 0;

 time(&t);

 for(ch = family; ch; ch = ch->next) {

  if (ch->flags & 16) {

   if (ch->tm + 300 < t) {
    ch->flags &= ~16;
    ch->count = 0;
    ch->tm = 0;
   } else {

    if (next_alarm == 0 ||
        ch->tm + 300 > next_alarm)
     next_alarm = ch->tm + 300;
   }
  }
 }
 if (next_alarm) {
  next_alarm -= t;
  if (next_alarm < 1) next_alarm = 1;
  alarm(next_alarm);
 }
}


static
void fail_cancel(void)
{
 CHILD *ch;

 for(ch = family; ch; ch = ch->next) {
  ch->count = 0;
  ch->tm = 0;
  ch->flags &= ~16;
 }
}




static
void do_power_fail(int pwrstat)
{
 CHILD *ch;




 for (ch = family; ch; ch = ch->next) {
  if (pwrstat == 'O') {



   if (ch->action == 8)
    ch->flags &= ~128;
  } else if (pwrstat == 'L') {



   if (ch->action == 14)
    ch->flags &= ~128;
  } else {



   if (ch->action == 6 || ch->action == 7)
    ch->flags &= ~128;
  }
 }
}




static
int check_pipe(int fd)
{
 struct timeval t;
 fd_set s;
 char signature[8];

 
do { unsigned int __i; fd_set *__arr = (
&s
); for (__i = 0; __i < sizeof (fd_set) / sizeof (__fd_mask); ++__i) ((__arr)->fds_bits)[__i] = 0; } while (0)
           ;
 
((void) (((
&s
)->fds_bits)[((
fd
) / (8 * (int) sizeof (__fd_mask)))] |= ((__fd_mask) (1UL << ((
fd
) % (8 * (int) sizeof (__fd_mask)))))))
              ;
 t.tv_sec = t.tv_usec = 0;

 if (select(fd+1, &s, 
                     ((void *)0)
                         , 
                           ((void *)0)
                               , &t) != 1)
  return 0;
 if (read(fd, signature, 8) != 8)
   return 0;
 return strncmp(Signature, signature, 8) == 0;
}




static
int make_pipe(int fd)
{
 int fds[2];

 if (pipe(fds)) {
  initlog((1|2), "pipe: %m");
  return -1;
 }
 dup2(fds[0], fd);
 close(fds[0]);
 fcntl(fds[1], 
              2
                     , 1);
 fcntl(fd, 
          2
                 , 0);
 safe_write(fds[1], Signature, 8);

 return fds[1];
}






static
void my_re_exec(void)
{
 CHILD *ch;
 sigset_t mask, oldset;
 pid_t pid;
 char **env;
 int fd;

 if (strchr("S0123456",runlevel) == 
                                   ((void *)0)
                                       )
  return;




 alarm(0);
 sigfillset(&mask);
 sigprocmask(
            0
                     , &mask, &oldset);




 if ((fd = make_pipe(11)) < 0) {
  sigprocmask(
             2
                        , &oldset, 
                                   ((void *)0)
                                       );
  initlog(1, "Attempt to re-exec failed");
 }

 fail_cancel();
 if (pipe_fd >= 0)
          close(pipe_fd);
    pipe_fd = -1;
 ((got_signals) &= ~(1 << (
17
)));
 ((got_signals) &= ~(1 << (
1
)));
 ((got_signals) &= ~(1 << (
10
)));
 ((got_signals) &= ~(1 << (
12
)));




 for(ch = family; ch; ch = ch->next)
     if (ch->flags & 64) {
  ;
  ch->flags &= ~(2|64|32);
  if (ch->process[0] != '+')
   write_utmp_wtmp("", ch->id, ch->pid, 
                                       8
                                                   , 
                                                     ((void *)0)
                                                         );
     }

 if ((pid = fork()) == 0) {



  send_state(fd);
  exit(0);
 }




 env = init_buildenv(0);
 execle(myname, myname, "--init", 
                                 ((void *)0)
                                     , env);





 init_freeenv(env);
 close(fd);
 close(11);
 sigprocmask(
            2
                       , &oldset, 
                                  ((void *)0)
                                      );
 initlog(1, "Attempt to re-exec failed");
}





static
void redo_utmp_wtmp(void)
{
 struct stat ustat;
 const int ret = stat(
                     "/var/run/utmp"
                              , &ustat);

 if ((ret < 0) || (ustat.st_size == 0))
  wrote_utmp_rlevel = wrote_utmp_reboot = 0;

 if ((wrote_wtmp_reboot == 0) || (wrote_utmp_reboot == 0))
  write_utmp_wtmp("reboot", "~~", 0, 
                                    2
                                             , "~");

 if ((wrote_wtmp_rlevel == 0) || (wrote_utmp_rlevel == 0))
  write_utmp_wtmp("runlevel", "~~", thislevel + 256 * prevlevel, 
                                                                1
                                                                       , "~");
}





static
void fifo_new_level(int level)
{



 int oldlevel;

 if (level == runlevel) return;







 {

  oldlevel = runlevel;
  runlevel = read_level(level);
  if (runlevel == 'U') {
   runlevel = oldlevel;
   my_re_exec();
  } else {
   if (oldlevel != 'S' && runlevel == 'S') console_stty();
   if (runlevel == '6' || runlevel == '0' ||
       runlevel == '1') console_stty();
   if (runlevel > '1' && runlevel < '6') redo_utmp_wtmp();
   read_inittab();
   fail_cancel();
   setproctitle("init [%c]", (int)runlevel);
  }
 }
        Write_Runlevel_Log(runlevel);
}







static
void initcmd_setenv(char *data, int size)
{
 char *env, *p, *e;
 size_t sz;
 int i, eq;

 e = data + size;

 while (*data && data < e) {
  for (p = data; *p && p < e; p++)
   ;
  if (*p) break;
  env = data;
  data = ++p;




  if (strncmp(env, "INIT_", 5) != 0)
   continue;

  sz = strcspn(env, "=");
  eq = (env[sz] == '=');




  for (i = 0; i < 16; i++) {
   if (extra_env[i] == 
                      ((void *)0)
                          )
    continue;
   if (sz != strcspn(extra_env[i], "="))
    continue;
   if (strncmp(extra_env[i], env, sz) == 0) {
    free(extra_env[i]);
    extra_env[i] = 
                  ((void *)0)
                      ;
   }
  }

  if (eq == 0)
   continue;


  for (i = 0; i < 16; i++) {
   if (extra_env[i] == 
                      ((void *)0)
                          ) {
    extra_env[i] = istrdup(env);
    break;
   }
  }
 }
}






static
void check_init_fifo(void)
{
  struct init_request request;
  struct timeval tv;
  struct stat st, st2;
  fd_set fds;
  int n;
  int quit = 0;




  if (stat("/run/initctl", &st2) < 0 && 
                                  (*__errno_location ()) 
                                        == 
                                           2
                                                 )
 (void)mkfifo("/run/initctl", 0600);





  if (pipe_fd >= 0) {
 fstat(pipe_fd, &st);
 if (stat("/run/initctl", &st2) < 0 ||
     st.st_dev != st2.st_dev ||
     st.st_ino != st2.st_ino) {
  close(pipe_fd);
  pipe_fd = -1;
 }
  }





  if (pipe_fd == -1) {
 if ((pipe_fd = open("/run/initctl", 
                               02
                                     |
                                      04000
                                                )) >= 0) {
  fstat(pipe_fd, &st);
  if (!
      ((((
      st.st_mode
      )) & 0170000) == (0010000))
                          ) {
   initlog((1|2), "%s is not a fifo", "/run/initctl");
   close(pipe_fd);
   pipe_fd = -1;
  }
 }
 if (pipe_fd >= 0) {



  (void) dup2(pipe_fd, 10);
  close(pipe_fd);
  pipe_fd = 10;




 }
  }


  if (pipe_fd >= 0) {
     while(!quit) {


 
do { unsigned int __i; fd_set *__arr = (
&fds
); for (__i = 0; __i < sizeof (fd_set) / sizeof (__fd_mask); ++__i) ((__arr)->fds_bits)[__i] = 0; } while (0)
             ;
 
((void) (((
&fds
)->fds_bits)[((
pipe_fd
) / (8 * (int) sizeof (__fd_mask)))] |= ((__fd_mask) (1UL << ((
pipe_fd
) % (8 * (int) sizeof (__fd_mask)))))))
                     ;
 tv.tv_sec = 5;
 tv.tv_usec = 0;
 n = select(pipe_fd + 1, &fds, 
                              ((void *)0)
                                  , 
                                    ((void *)0)
                                        , &tv);
 if (n <= 0) {
  if (n == 0 || 
               (*__errno_location ()) 
                     == 
                        4
                             ) return;
  continue;
 }


 n = read(pipe_fd, &request, sizeof(request));
 if (n == 0) {





  close(pipe_fd);
  pipe_fd = -1;
  return;
 }
 if (n <= 0) {
  if (
     (*__errno_location ()) 
           == 
              4
                   ) return;
  initlog((1|2), "error reading initrequest");
  continue;
 }





 console_init();




 if (request.magic != 0x03091969 || n != sizeof(request)) {
  initlog((1|2), "got bogus initrequest");
  continue;
 }
 switch(request.cmd) {
  case 1:
   sleep_time = request.sleeptime;
   fifo_new_level(request.runlevel);
   quit = 1;
   break;
  case 2:
   sleep_time = request.sleeptime;
   do_power_fail('F');
   quit = 1;
   break;
  case 3:
   sleep_time = request.sleeptime;
   do_power_fail('L');
   quit = 1;
   break;
  case 4:
   sleep_time = request.sleeptime;
   do_power_fail('O');
   quit = 1;
   break;
  case 6:
   initcmd_setenv(request.i.data, sizeof(request.i.data));
   break;
  default:
   initlog((1|2), "got unimplemented initrequest.");
   break;
 }
    }
  }



  if (pipe_fd == -1) pause();

}






static
void boot_transitions()
{
  CHILD *ch;
  static int newlevel = 0;
  static int warn = 1;
  int loglevel;
  int oldlevel;


  for( ch = family; ch; ch = ch->next )
 if ((ch->flags & 2) && ch->action != 4) break;

  if (ch == 
           ((void *)0)
               ) {

 loglevel = -1;
 oldlevel = 'N';
 switch(runlevel) {
  case '#':
   ;


   wrote_utmp_reboot = 0;
   wrote_wtmp_reboot = 0;
   write_utmp_wtmp("reboot", "~~", 0, 
                                     2
                                              , "~");


     newlevel = dfl_level ? dfl_level : get_init_default();
   if (newlevel == 'S') {
    runlevel = newlevel;

    setproctitle("init [S]");
   } else
    runlevel = '*';
   break;
  case '*':
   ;
   if (runlevel != newlevel)
    loglevel = newlevel;
   runlevel = newlevel;
   did_boot = 1;
   warn = 1;
   break;
  case 'S':
  case 's':
   ;
   newlevel = get_init_default();
   if (!did_boot && newlevel != 'S')
    runlevel = '*';
   else {
    if (runlevel != newlevel)
     loglevel = newlevel;
    runlevel = newlevel;
    oldlevel = 'S';
   }
   warn = 1;
   for(ch = family; ch; ch = ch->next)
       if (strcmp(ch->rlevel, "S") == 0)
    ch->flags &= ~(16|32|128);
   break;
  default:
   if (warn)
     initlog((1|2),
    "no more processes left in this runlevel");
   warn = 0;
   loglevel = -1;
   if (got_signals == 0)
    check_init_fifo();
   break;
 }
 if (loglevel > 0) {
  initlog((1|2), "Entering runlevel: %c", runlevel);
  wrote_utmp_rlevel = 0;
  wrote_wtmp_rlevel = 0;
  write_utmp_wtmp("runlevel", "~~", runlevel + 256 * oldlevel, 
                                                              1
                                                                     , "~");
  thislevel = runlevel;
  prevlevel = oldlevel;
  setproctitle("init [%c]", (int)runlevel);
 }
        Write_Runlevel_Log(runlevel);
  }
}





static
void process_signals()
{
  CHILD *ch;
  int pwrstat;
  int oldlevel;
  int fd;
  char c;

  if (((got_signals) & (1 << (
     30
     )))) {
 ;

 pwrstat = 0;
 if ((fd = open("/var/run/powerstatus", 
                        00
                                )) >= 0) {
  if (read(fd, &c, 1) != 1)
   c = 0;
  pwrstat = c;
  close(fd);
  unlink("/var/run/powerstatus");
 } else if ((fd = open("/etc/powerstatus", 
                                   00
                                           )) >= 0) {

  initlog((1|2), "warning: found obsolete path %s, use %s instead",
   "/etc/powerstatus", "/var/run/powerstatus");
  if (read(fd, &c, 1) != 1)
   c = 0;
  pwrstat = c;
  close(fd);
  unlink("/etc/powerstatus");
        }
 do_power_fail(pwrstat);
 ((got_signals) &= ~(1 << (
30
)));
  }

  if (((got_signals) & (1 << (
     2
     )))) {





 ;

 for(ch = family; ch; ch = ch->next)
  if (ch->action == 9)
   ch->flags &= ~128;
 ((got_signals) &= ~(1 << (
2
)));
  }

  if (((got_signals) & (1 << (
     28
     )))) {
 ;

 for(ch = family; ch; ch = ch->next)
  if (ch->action == 15)
   ch->flags &= ~128;
 ((got_signals) &= ~(1 << (
28
)));
  }

  if (((got_signals) & (1 << (
     14
     )))) {
 ;

 ((got_signals) &= ~(1 << (
14
)));
  }

  if (((got_signals) & (1 << (
     17
     )))) {
 ;

 ((got_signals) &= ~(1 << (
17
)));


 for(ch = family; ch; ch = ch->next)
     if (ch->flags & 64) {
  ;
  ch->flags &= ~(2|64|32);
  if (ch->process[0] != '+')
   write_utmp_wtmp("", ch->id, ch->pid, 
                                       8
                                                   , 
                                                     ((void *)0)
                                                         );
     }

  }

  if (((got_signals) & (1 << (
     1
     )))) {
 ;






 {

  oldlevel = runlevel;



  if (runlevel == 'U') {
   runlevel = oldlevel;
   my_re_exec();
  } else {
   if (oldlevel != 'S' && runlevel == 'S') console_stty();
   if (runlevel == '6' || runlevel == '0' ||
       runlevel == '1') console_stty();
   read_inittab();
   fail_cancel();
   setproctitle("init [%c]", (int)runlevel);
   ((got_signals) &= ~(1 << (
  1
  )));
  }
                Write_Runlevel_Log(runlevel);
 }
  }
  if (((got_signals) & (1 << (
     10
     )))) {



 ;
 if (pipe_fd)
           close(pipe_fd);
 pipe_fd = -1;
 ((got_signals) &= ~(1 << (
10
)));
  }
  else if (((got_signals) & (1 << (
          12
          )))) {

       ;
       if (pipe_fd)
           close(pipe_fd);
       pipe_fd = -2;
       ((got_signals) &= ~(1 << (
      12
      )));
  }
}




static
void init_main(void)
{
  CHILD *ch;
  struct sigaction sa;
  sigset_t sgt;
  int f, st;

  if (!reload) {
 reboot(
0
);
 if ((f = open("/dev/tty0", 
                         02 
                                | 
                                  0400
                                          )) >= 0) {
  (void) ioctl(f, 
                 0x4B4E
                            , 
                              28
                                      );
  close(f);
 } else
  (void) ioctl(0, 
                 0x4B4E
                            , 
                              28
                                      );





 for(f = 1; f <= 
                (64 + 1)
                    ; f++)
  do { memset(&sa, 0, sizeof(sa)); sa.
 __sigaction_handler.sa_handler 
 = 
 ((__sighandler_t) 1)
 ; sa.sa_flags = 
 0x10000000
 ; sigemptyset(&sa.sa_mask); sigaction(f, &sa, 
 ((void *)0)
 ); } while(0);
  }

  do { memset(&sa, 0, sizeof(sa)); sa.
 __sigaction_handler.sa_handler 
 = signal_handler; sa.sa_flags = 0; sigemptyset(&sa.sa_mask); sigaction(
 14
 , &sa, 
 ((void *)0)
 ); } while(0);
  do { memset(&sa, 0, sizeof(sa)); sa.
 __sigaction_handler.sa_handler 
 = signal_handler; sa.sa_flags = 0; sigemptyset(&sa.sa_mask); sigaction(
 1
 , &sa, 
 ((void *)0)
 ); } while(0);
  do { memset(&sa, 0, sizeof(sa)); sa.
 __sigaction_handler.sa_handler 
 = signal_handler; sa.sa_flags = 0; sigemptyset(&sa.sa_mask); sigaction(
 2
 , &sa, 
 ((void *)0)
 ); } while(0);
  do { memset(&sa, 0, sizeof(sa)); sa.
 __sigaction_handler.sa_handler 
 = chld_handler; sa.sa_flags = 
 0x10000000
 ; sigemptyset(&sa.sa_mask); sigaction(
 17
 , &sa, 
 ((void *)0)
 ); } while(0);
  do { memset(&sa, 0, sizeof(sa)); sa.
 __sigaction_handler.sa_handler 
 = signal_handler; sa.sa_flags = 0; sigemptyset(&sa.sa_mask); sigaction(
 30
 , &sa, 
 ((void *)0)
 ); } while(0);
  do { memset(&sa, 0, sizeof(sa)); sa.
 __sigaction_handler.sa_handler 
 = signal_handler; sa.sa_flags = 0; sigemptyset(&sa.sa_mask); sigaction(
 28
 , &sa, 
 ((void *)0)
 ); } while(0);
  do { memset(&sa, 0, sizeof(sa)); sa.
 __sigaction_handler.sa_handler 
 = signal_handler; sa.sa_flags = 0; sigemptyset(&sa.sa_mask); sigaction(
 10
 , &sa, 
 ((void *)0)
 ); } while(0);
  do { memset(&sa, 0, sizeof(sa)); sa.
 __sigaction_handler.sa_handler 
 = signal_handler; sa.sa_flags = 0; sigemptyset(&sa.sa_mask); sigaction(
 12
 , &sa, 
 ((void *)0)
 ); } while(0);
  do { memset(&sa, 0, sizeof(sa)); sa.
 __sigaction_handler.sa_handler 
 = stop_handler; sa.sa_flags = 
 0x10000000
 ; sigemptyset(&sa.sa_mask); sigaction(
 19
 , &sa, 
 ((void *)0)
 ); } while(0);
  do { memset(&sa, 0, sizeof(sa)); sa.
 __sigaction_handler.sa_handler 
 = stop_handler; sa.sa_flags = 
 0x10000000
 ; sigemptyset(&sa.sa_mask); sigaction(
 20
 , &sa, 
 ((void *)0)
 ); } while(0);
  do { memset(&sa, 0, sizeof(sa)); sa.
 __sigaction_handler.sa_handler 
 = cont_handler; sa.sa_flags = 
 0x10000000
 ; sigemptyset(&sa.sa_mask); sigaction(
 18
 , &sa, 
 ((void *)0)
 ); } while(0);
  do { memset(&sa, 0, sizeof(sa)); sa.
 __sigaction_handler.sa_handler 
 = (void (*)(int))segv_handler; sa.sa_flags = 
 0x10000000
 ; sigemptyset(&sa.sa_mask); sigaction(
 11
 , &sa, 
 ((void *)0)
 ); } while(0);

  console_init();

  if (!reload) {
 int fd;


 close(0);
 close(1);
 close(2);
   console_stty();
   setsid();




   setenv("PATH", "/sbin:/usr/sbin:/bin:/usr/bin", 1 );





 if ((fd = open(
               "/var/run/utmp"
                        , 
                          01
                                  |
                                   0100
                                          |
                                           01000
                                                  , 0644)) >= 0)
  close(fd);




   initlog(1, bootmsg, "booting");




 if (emerg_shell) {
  pid_t rc;
  do { memset(&sa, 0, sizeof(sa)); sa.
 __sigaction_handler.sa_handler 
 = 
 ((__sighandler_t) 0)
 ; sa.sa_flags = 
 0x10000000
 ; sigemptyset(&sa.sa_mask); sigaction(
 17
 , &sa, 
 ((void *)0)
 ); } while(0);
  if (spawn(&ch_emerg, &f) > 0) {
   while((rc = wait(&st)) != f)
    if (rc < 0 && 
                 (*__errno_location ()) 
                       == 
                          10
                                )
     break;
  }
    do { memset(&sa, 0, sizeof(sa)); sa.
   __sigaction_handler.sa_handler 
   = chld_handler; sa.sa_flags = 
   0x10000000
   ; sigemptyset(&sa.sa_mask); sigaction(
   17
   , &sa, 
   ((void *)0)
   ); } while(0);
   }




   runlevel = '#';
   read_inittab();

  } else {



 initlog(1, bootmsg, "reloading");
 sigfillset(&sgt);
 sigprocmask(
            1
                       , &sgt, 
                               ((void *)0)
                                   );




   setenv("PATH", "/sbin:/usr/sbin:/bin:/usr/bin", 0 );
  }
  start_if_needed();

  while(1) {


     boot_transitions();
     ;


     for(ch = family; ch; ch = ch->next)
 if ((ch->flags & 2) && ch->action != 4) break;
     if (ch != 
              ((void *)0) 
                   && got_signals == 0) check_init_fifo();



     fail_check();


     process_signals();


     start_if_needed();
  }

}




static
void usage(char *s)
{
 fprintf(
        stderr
              , "Usage: %s {-e VAR[=VAL] | [-t SECONDS] {0|1|2|3|4|5|6|S|s|Q|q|A|a|B|b|C|c|U|u}}\n", s);
 exit(1);
}

static
int telinit(char *progname, int argc, char **argv)
{



 struct init_request request;
 struct sigaction sa;
 int f, fd, l;
 char *env = 
              ((void *)0)
                  ;

 memset(&request, 0, sizeof(request));
 request.magic = 0x03091969;

 while ((f = getopt(argc, argv, "t:e:")) != 
                                           (-1)
                                              ) switch(f) {
  case 't':
   sleep_time = atoi(optarg);
   break;
  case 'e':
   if (env == 
             ((void *)0)
                 )
    env = request.i.data;
   l = strlen(optarg);
   if (env + l + 2 > request.i.data + sizeof(request.i.data)) {
    fprintf(
           stderr
                 , "%s: -e option data "
     "too large\n", progname);
    exit(1);
   }
   memcpy(env, optarg, l);
   env += l;
   *env++ = 0;
   break;
  default:
   usage(progname);
   break;
 }

 if (env) *env++ = 0;

 if (env) {
  if (argc != optind)
   usage(progname);
  request.cmd = 6;
 } else {
  if (argc - optind != 1 || strlen(argv[optind]) != 1)
   usage(progname);
  if (!strchr("0123456789SsQqAaBbCcUu", argv[optind][0]))
   usage(progname);
  request.cmd = 1;
  request.runlevel = argv[optind][0];
  request.sleeptime = sleep_time;
 }


 if (0 != chdir("/"))
  initlog((1|2), "unable to chdir to /: %s",
   strerror(
           (*__errno_location ())
                ));



 do { memset(&sa, 0, sizeof(sa)); sa.
__sigaction_handler.sa_handler 
= signal_handler; sa.sa_flags = 0; sigemptyset(&sa.sa_mask); sigaction(
14
, &sa, 
((void *)0)
); } while(0);
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
              , "%s: ", progname);
 if (((got_signals) & (1 << (
    14
    )))) {
  fprintf(
         stderr
               , "timeout opening/writing control channel %s\n",
   "/run/initctl");
 } else {
  perror("/run/initctl");
 }
 return 1;
}




int main(int argc, char **argv)
{
 char *p;
 int f;
 int isinit;





 if ((p = strrchr(argv[0], '/')) != 
                                   ((void *)0)
                                       )
    p++;
 else
    p = argv[0];

        if ( (argc == 2) && (! strcmp(argv[1], "--version") ) )
        {
           printf("SysV init version: %s\n\n", "3.05");
           exit(0);
        }


 umask(umask(077) | 022);


 if (geteuid() != 0) {
  fprintf(
         stderr
               , "%s: must be superuser.\n", p);
  exit(1);
 }




 isinit = (getpid() == 1);
 for (f = 1; f < argc; f++) {
  if (!strcmp(argv[f], "-i") || !strcmp(argv[f], "--init")) {
   isinit = 1;
   break;
  }
 }
 if (!isinit) exit(telinit(p, argc, argv));




 if (check_pipe(11)) {

  receive_state(11);

  myname = istrdup(argv[0]);
  argv0 = argv[0];
  maxproclen = 0;
  for (f = 0; f < argc; f++)
   maxproclen += strlen(argv[f]) + 1;
  reload = 1;
  setproctitle("init [%c]", (int)runlevel);

  init_main();
 }


 maxproclen = strlen(argv[0]) + 1;
   for(f = 1; f < argc; f++) {
  if (!strcmp(argv[f], "single") || !strcmp(argv[f], "-s"))
   dfl_level = 'S';
  else if (!strcmp(argv[f], "-a") || !strcmp(argv[f], "auto"))
   putenv("AUTOBOOT=YES");
  else if (!strcmp(argv[f], "-b") || !strcmp(argv[f],"emergency"))
   emerg_shell = 1;
  else if (!strcmp(argv[f], "-z")) {

   if (argv[f + 1]) f++;
  } else if (strchr("0123456789sS", argv[f][0])
   && strlen(argv[f]) == 1)
   dfl_level = argv[f][0];

  if (dfl_level == 's') dfl_level = 'S';
  maxproclen += strlen(argv[f]) + 1;
 }
 argv0 = argv[0];
 argv[1] = 
          ((void *)0)
              ;
 setproctitle("init boot");
 init_main();


 return 0;
}
