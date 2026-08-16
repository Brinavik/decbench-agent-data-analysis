
static sigjmp_buf jbuf;






static void handler(int arg __attribute__((unused)))



{
 siglongjmp(jbuf, 1);
}





static void feputs(const char *line, FILE *fp)
{
 unsigned char *p;

 for (p = (unsigned char *)line; *p; p++) {
  if (strchr("\t\r\n", *p) ||
      (*p >= 32 && *p <= 127) || (*p >= 160)) {
   fputc(*p, fp);
  } else {
   fprintf(fp, "^%c", (*p & 0x1f) + 'A' - 1);
  }
 }
 fflush(fp);
}


static void getuidtty(char **userp, char **ttyp)
{
 struct passwd *pwd;
 uid_t uid;
 char *tty;
 static char uidbuf[32];
 static char ttynm[
                   32 
                               + 4];
 static int init = 0;

 if (!init) {

  uid = getuid();
  if ((pwd = getpwuid(uid)) != 
                              ((void *)0)
                                  ) {
   uidbuf[0] = 0;
   strncat(uidbuf, pwd->pw_name, sizeof(uidbuf) - 1);
  } else {




                        if (uid)
                           sprintf(uidbuf, "uid %d", (int) uid);
                        else
                           sprintf(uidbuf, "root");
  }

  if ((tty = ttyname(0)) != 
                           ((void *)0)
                               ) {
   const size_t plen = strlen(
                             "/dev/"
                                      );
   if (strncmp(tty, 
                   "/dev/"
                            , plen) == 0) {
    tty += plen;
    if (tty[0] == '/')
     tty++;
   }
   snprintf(ttynm, sizeof(ttynm), "(%.*s) ",
     
    32
               , tty);
  } else
   ttynm[0] = 0;
  init++;
 }

 *userp = uidbuf;
 *ttyp = ttynm;
}




static int file_isatty(const char *fname)
{
 struct stat st;
 int major;

 if (stat(fname, &st) < 0)
  return 0;

 if (st.st_nlink != 1 || !
                         ((((
                         st.st_mode
                         )) & 0170000) == (0020000))
                                            )
  return 0;







 major = 
        gnu_dev_major (
        st.st_dev
        )
                        ;
 if (major == 1 || major == 2 || major == 6 || major == 9 ||
     major == 12 || major == 16 || major == 21 || major == 27 ||
     major == 37 || major == 96 || major == 97 || major == 206 ||
     major == 230) return 0;

 return 1;
}




void wall(const char *text, int remote)
{
 FILE *tp;
 struct sigaction sa;
 struct utmp *utmp;
 time_t t;
 char term[
            32
                       + strlen(
                                "/dev/"
                                         ) + 1];
 char line[256];
 char hostname[
                64
                             +1];
 char *date, *p;
 char *user, *tty;
 int fd, flags;





 (void) &tp;
 (void) &fd;

 getuidtty(&user, &tty);



 if (0 != gethostname(hostname, sizeof(hostname))) {
  strncpy(hostname, "[unknown]", sizeof(hostname)-1);
 }



 hostname[sizeof(hostname)-1] = 0;


 time(&t);
 date = ctime(&t);
 for(p = date; *p && *p != '\n'; p++)
  ;
 *p = 0;

 if (remote) {
  snprintf(line, sizeof(line),
   "\r\nRemote broadcast message (%s):\r\n\r\n",
   date);
 } else {
  snprintf(line, sizeof(line),
   "\r\nBroadcast message from %s@%s %s(%s):\r\n\r\n",
   user, hostname, tty, date);
 }




 if (fork() != 0)
  return;

 memset(&sa, 0, sizeof(sa));
 sa.
   __sigaction_handler.sa_handler 
              = handler;
 sa.sa_flags = 0;
 sigemptyset(&sa.sa_mask);
 sigaction(
          14
                 , &sa, 
                        ((void *)0)
                            );

 setutent();

 while ((utmp = getutent()) != 
                              ((void *)0)
                                  ) {
  if(utmp->ut_type != 
                     7 
                                  ||
     utmp->ut_user[0] == 0) continue;
  if (strncmp(utmp->ut_line, 
                            "/dev/"
                                     , strlen(
                                              "/dev/"
                                                       )) == 0) {
   term[0] = 0;
   strncat(term, utmp->ut_line, sizeof(term)-1);
  } else
   snprintf(term, sizeof(term), 
                               "/dev/" 
                                         "%.*s",
    
   32
              , utmp->ut_line);
  if (strstr(term, "/../")) continue;

  fd = -1;
  tp = 
      ((void *)0)
          ;




  if (
     __sigsetjmp (
     jbuf
     , 
     1
     ) 
                        == 0) {
   alarm(2);
   flags = 
          01
                  |
                   04000
                           |
                            0400
                                    ;
   if (file_isatty(term) &&
       (fd = open(term, flags)) >= 0) {
    if (isatty(fd) &&
        (tp = fdopen(fd, "w")) != 
                                 ((void *)0)
                                     ) {
     fputs(line, tp);
     feputs(text, tp);
     fflush(tp);
    }
   }
  }
  alarm(0);
  if (fd >= 0) close(fd);
  if (tp != 
           ((void *)0)
               ) fclose(tp);
 }
 endutent();

 exit(0);
}
