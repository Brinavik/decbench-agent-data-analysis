

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






int main(int argc, char **argv)
{
  char buf[4096];
  char line[80 + 3];
  int i, f, ch;
  int len = 0;
  int remote = 0;
  char *p;
  char *whoami;
  struct passwd *pwd;

  buf[0] = 0;
  if ((pwd = getpwuid(getuid())) == 
                                   ((void *)0)
                                       ) {
 if (getuid() == 0)
  whoami = "root";
 else {
  fprintf(
         stderr
               , "You don't exist. Go away.\n");
  exit(1);
 }
  } else
 whoami = pwd->pw_name;

  while((ch = getopt(argc, argv, "n")) != 
                                         (-1)
                                            )
 switch(ch) {
  case 'n':





   if (geteuid() != 0 && getgid() != getegid()) {
    fprintf(
           stderr
                 , "wall -n: not privileged\n");
    exit(1);
   }
   remote = 1;
   break;
  default:
   fprintf(
          stderr
                , "usage: wall [message]\n");
   return 1;
   break;
 }

  if ((argc - optind) > 0) {
 for(f = optind; f < argc; f++) {
  len += strlen(argv[f]) + 1;
  if (len >= 4096 -4) break;
  strcat(buf, argv[f]);
  if (f < argc-1) strcat(buf, " ");
 }
 strcat(buf, "\r\n");
  } else {
 while(fgets(line, 80, 
                      stdin
                           )) {



  for(p = line; *p && *p != '\r' && *p != '\n'; p++)
   ;
  strcpy(p, "\r\n");
  len += strlen(line);
  if (len >= 4096) break;
  strcat(buf, line);
 }
  }

  i = 0;
  for (p = buf; *p; p++) {
 if (*p == '\n' && ++i >= 20) {
  *++p = 0;
  break;
 }
  }

  openlog("wall", 
                 0x01
                        , 
                          (1<<3)
                                  );
  syslog(
        6
                , "wall: user %s broadcasted %d lines (%zu chars)",
 whoami, i, strlen(buf));
  closelog();

  unsetenv("TZ");
  wall(buf, remote);


  return 0;
}
