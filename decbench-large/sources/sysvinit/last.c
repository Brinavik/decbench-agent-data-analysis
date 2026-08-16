
struct oldutmp {
 short ut_type;
 int ut_pid;
 char ut_line[12];
 char ut_id[4];
 long ut_oldtime;
 char ut_user[8];
 char ut_host[16];
 long ut_oldaddr;
};
char *Version = "@(#) last 2.85 31-Apr-2004 miquels";






struct utmplist {
  struct utmp ut;
  struct utmplist *next;
  struct utmplist *prev;
};
struct utmplist *utmplist = 
                           ((void *)0)
                               ;
int maxrecs = 0;
int recsdone = 0;
int showhost = 1;
int altlist = 0;
int allow_long_username = 0;
int usedns = 0;
int useip = 0;
int fulltime = 0;
int name_len = 8;
int domain_len = 16;
int oldfmt = 0;
char **show = 
             ((void *)0)
                 ;
char *ufile;
time_t lastdate;
char *progname;
void uconv(struct oldutmp *oldut, struct utmp *utn)
{
 memset(utn, 0, sizeof(struct utmp));
 utn->ut_type = oldut->ut_type;
 utn->ut_pid = oldut->ut_pid;
 utn->
     ut_tv.tv_sec 
             = oldut->ut_oldtime;
 utn->
     ut_addr_v6[0] 
             = oldut->ut_oldaddr;
 strncpy(utn->ut_line, oldut->ut_line, 12);
 strncpy(utn->ut_user, oldut->ut_user, 8);
 strncpy(utn->ut_host, oldut->ut_host, 16);
}






int uread(FILE *fp, struct utmp *u, int *quit)
{
 static int utsize;
 static char buf[16384];
 char tmp[1024];
 static off_t fpos;
 static int bpos;
 struct oldutmp uto;
 int r;
 off_t o;

 if (quit == 
            ((void *)0) 
                 && u != 
                         ((void *)0)
                             ) {



  if (oldfmt) {
   r = fread(&uto, sizeof(uto), 1, fp);
   uconv(&uto, u);
  } else
   r = fread(u, sizeof(struct utmp), 1, fp);
  return r;
 }

 if (u == 
         ((void *)0)
             ) {



  utsize = oldfmt ? sizeof(uto) : sizeof(struct utmp);
  fseeko(fp, 0, 
               2
                       );
  fpos = ftello(fp);
  if (fpos == 0)
   return 0;
  o = ((fpos - 1) / 16384) * 16384;
  if (fseeko(fp, o, 
                   0
                           ) < 0) {
   fprintf(
          stderr
                , "%s: seek failed!\n", progname);
   return 0;
  }
  bpos = (int)(fpos - o);
  if (fread(buf, bpos, 1, fp) != 1) {
   fprintf(
          stderr
                , "%s: read failed!\n", progname);
   return 0;
  }
  fpos = o;
  return 1;
 }




 bpos -= utsize;
 if (bpos >= 0) {
  if (oldfmt)
   uconv((struct oldutmp *)(buf + bpos), u);
  else
   memcpy(u, buf + bpos, sizeof(struct utmp));
  return 1;
 }





 fpos -= 16384;
 if (fpos < 0)
  return 0;




 memcpy(tmp + (-bpos), buf, utsize + bpos);
 if (fseeko(fp, fpos, 
                     0
                             ) < 0) {
  perror("fseek");
  return 0;
 }




 if (fread(buf, 16384, 1, fp) != 1) {
  perror("fread");
  return 0;
 }





 memcpy(tmp, buf + 16384 + bpos, -bpos);
 bpos += 16384;

 if (oldfmt)
  uconv((struct oldutmp *)tmp, u);
 else
  memcpy(u, tmp, sizeof(struct utmp));

 return 1;
}
char *getbtmp()
{
 static char btmp[2048 + 5];
 char *p;

        memset(btmp, '\0', 2048 + 5);
 strncpy(btmp, 
              "/var/log/wtmp"
                       , 2048);
 if ((p = strrchr(btmp, '/')) == 
                                ((void *)0)
                                    )
  p = btmp;
 else
  p++;
 *p = 0;
 strcat(btmp, "btmp");
 return btmp;
}





char *showdate()
{
 char *s = ctime(&lastdate);
 s[16] = 0;
 return s;
}




void int_handler()
{
 printf("Interrupted %s\n", showdate());
 exit(1);
}




void quit_handler()
{
 printf("Interrupted %s\n", showdate());
 signal(
       3
              , quit_handler);
}




char *mybasename(char *s)
{
 char *p;

 if ((p = strrchr(s, '/')) != 
                             ((void *)0)
                                 )
  p++;
 else
  p = s;
 return p;
}




int dns_lookup(char *result, int size, int useip, int32_t *a)
{
 struct sockaddr_in sin;
 struct sockaddr_in6 sin6;
 struct sockaddr *sa;
 int salen, flags;
 int mapped = 0;

 flags = useip ? 
                1 
                               : 0;
 if (a[0] == 0 && a[1] == 0 && a[2] == (int32_t)htonl (0xffff))
  mapped = 1;

 if (mapped || (a[1] == 0 && a[2] == 0 && a[3] == 0)) {

  sin.sin_family = 
                  2
                         ;
  sin.sin_port = 0;
  sin.sin_addr.s_addr = mapped ? a[3] : a[0];
  sa = (struct sockaddr *)&sin;
  salen = sizeof(sin);
 } else {

  memset(&sin6, 0, sizeof(sin6));
  sin6.sin6_family = 
                    10
                            ;
  sin6.sin6_port = 0;
  memcpy(sin6.sin6_addr.
                       __in6_u.__u6_addr8
                              , a, 16);
  sa = (struct sockaddr *)&sin6;
  salen = sizeof(sin6);
 }

 return getnameinfo(sa, salen, result, size, 
                                            ((void *)0)
                                                , 0, flags);
}




int list(struct utmp *p, time_t t, int what)
{
 time_t secs, tmp;
 char logintime[32];
 char logouttime[32];
 char length[32];
 char final[512];
 char utline[
             32
                        +1];
 char domain[256];
 char *s, **walk;
 int mins, hours, days;
 int r, len;




 utline[0] = 0;
 strncat(utline, p->ut_line, 
                            32
                                       );
 if (strncmp(utline, "ftp", 3) == 0 && 
                                      ((*__ctype_b_loc ())[(int) ((
                                      utline[3]
                                      ))] & (unsigned short int) _ISdigit)
                                                        )
  utline[3] = 0;
 if (strncmp(utline, "uucp", 4) == 0 && 
                                       ((*__ctype_b_loc ())[(int) ((
                                       utline[4]
                                       ))] & (unsigned short int) _ISdigit)
                                                         )
  utline[4] = 0;




 if (show) {
  for (walk = show; *walk; walk++) {
   if (strncmp(p->
                 ut_user
                        , *walk, 
                                 32
                                            ) == 0 ||
       strcmp(utline, *walk) == 0 ||
       (strncmp(utline, "tty", 3) == 0 &&
        strcmp(utline + 3, *walk) == 0)) break;
  }
  if (*walk == 
              ((void *)0)
                  ) return 0;
 }




 tmp = (time_t)p->
                 ut_tv.tv_sec
                        ;
 strncpy(logintime, ctime(&tmp), sizeof(logintime));
 logintime[sizeof(logintime)-1] = 0;
 if (fulltime)
  sprintf(logouttime, "- %s", ctime(&t));
 else {
  logintime[16] = 0;
  sprintf(logouttime, "- %s", ctime(&t) + 11);
  logouttime[7] = 0;
 }
 secs = t - p->
              ut_tv.tv_sec
                     ;
 mins = (secs / 60) % 60;
 hours = (secs / 3600) % 24;
 days = secs / 86400;
 if (days)
  sprintf(length, "(%d+%02d:%02d)", days, hours, mins);
 else
  sprintf(length, " (%02d:%02d)", hours, mins);

 switch(what) {
  case 1:
   sprintf(logouttime, "- crash");
   break;
  case 2:
   sprintf(logouttime, "- down ");
   break;
  case 4:
   length[0] = 0;
   if (fulltime)
    sprintf(logouttime, "  still logged in");
   else {
    sprintf(logouttime, "  still");
    sprintf(length, "logged in");
   }
   break;
  case 6:
   length[0] = 0;
   if (fulltime)
    sprintf(logouttime, "  gone - no logout");
   else {
    sprintf(logouttime, "   gone");
    sprintf(length, "- no logout");
   }
   break;
  case 5:
   break;
  case 7:
   logouttime[0] = 0;
   length[0] = 0;
   break;
  case 3:
   break;
  }




 r = -1;
 if (usedns || useip)
  r = dns_lookup(domain, sizeof(domain), useip, p->ut_addr_v6);
 if (r < 0) {
  len = 
       256
                  ;
  if (len >= (int)sizeof(domain)) len = sizeof(domain) - 1;
  domain[0] = 0;
  strncat(domain, p->ut_host, len);
 }

 if (showhost) {
  if (!altlist) {
                    if (allow_long_username)
                    {
                       len = snprintf(final, sizeof(final),
  oldfmt ? "%-" "8" "." "8" "s %-12.12s "
  "%-16.16s %-16.16s %-7.7s %-12.12s\n"
                : "%-" "32" "." "32" "s %-12.12s "
  "%-16.16s %-16.16s %-7.7s %-12.12s\n",
     p->
       ut_user
              , utline,
     domain, logintime, logouttime, length);
                    }
                    else
                    {
   len = snprintf(final, sizeof(final),
    fulltime ?
        "%-8.*s %-12.12s %-16.*s %-24.24s %-26.26s %-12.12s\n" :
    "%-8.*s %-12.12s %-16.*s %-16.16s %-7.7s %-12.12s\n",
    name_len, p->
                ut_user
                       , utline,
    domain_len, domain, logintime, logouttime, length);
                    }
  } else {
                     if (allow_long_username)
                     {
                         len = snprintf(final, sizeof(final),
  oldfmt ? "%-" "8" "." "8" "s %-12.12s "
  "%-16.16s %-7.7s %-16.16s %s\n"
         : "%-" "32" "." "32" "s %-12.12s "
  "%-16.16s %-7.7s %-16.16s %s\n",
     p->
       ut_user
              , utline,
     logintime, logouttime, length, domain);
                     }
                     else
                     {
   len = snprintf(final, sizeof(final),
    fulltime ?
    "%-8.*s %-12.12s %-24.24s %-26.26s %-12.12s %s\n" :
    "%-8.*s %-12.12s %-16.16s %-7.7s %-12.12s %s\n",
    name_len, p->
                ut_user
                       , utline,
    logintime, logouttime, length, domain);
                     }
  }
 } else
             if (allow_long_username)
             {
                  len = snprintf(final, sizeof(final),
    oldfmt ? "%-" "8" "." "8" "s %-12.12s "
  "%-16.16s %-7.7s %-12.12s\n"
     : "%-" "32" "." "32" "s %-12.12s "
  "%-16.16s %-7.7s %-12.12s\n",
    p->
      ut_user
             , utline,
    logintime, logouttime, length);
             }
             else
             {
  len = snprintf(final, sizeof(final),
   fulltime ?
   "%-8.*s %-12.12s %-24.24s %-26.26s %-12.12s\n" :
   "%-8.*s %-12.12s %-16.16s %-7.7s %-12.12s\n",
   name_len, p->
               ut_user
                      , utline,
   logintime, logouttime, length);
             }
 for (s = final; *s; s++) {
  if (*s == '\n' || (*s >= 32 && (unsigned char)*s <= 126))
   putchar(*s);
  else
   putchar('*');
 }

 if (len < 0 || (size_t)len >= sizeof(final))
  putchar('\n');

 recsdone++;
 if (maxrecs && recsdone >= maxrecs)
  return 1;

 return 0;
}





void usage(char *s)
{
 fprintf(
        stderr
              , "Usage: %s [-num | -n num] [-f file] "
   "[-t YYYYMMDDHHMMSS] "
   "[-R] [-adioxFw] [username..] [tty..]\n", s);
 exit(1);
}

time_t parsetm(char *ts)
{
 struct tm u, origu;
 time_t tm;

 memset(&tm, 0, sizeof(tm));

 if (sscanf(ts, "%4d%2d%2d%2d%2d%2d", &u.tm_year,
     &u.tm_mon, &u.tm_mday, &u.tm_hour, &u.tm_min,
     &u.tm_sec) != 6)
  return (time_t)-1;

 u.tm_year -= 1900;
 u.tm_mon -= 1;
 u.tm_isdst = -1;

 origu = u;

 if ((tm = mktime(&u)) == (time_t)-1)
  return tm;
 if (u.tm_year != origu.tm_year ||
     u.tm_mon != origu.tm_mon ||
     u.tm_mday != origu.tm_mday ||
     u.tm_hour != origu.tm_hour ||
     u.tm_min != origu.tm_min ||
     u.tm_sec != origu.tm_sec)
  return (time_t)-1;

 return tm;
}

int main(int argc, char **argv)
{
  FILE *fp;

  struct utmp ut;
  struct utmp oldut;
  struct utmplist *p;
  struct utmplist *next;

  time_t lastboot = 0;
  time_t lastrch = 0;
  time_t lastdown;
  time_t begintime;
  int whydown = 0;

  int c, x;
  struct stat st;
  int quit = 0;
  int down = 0;
  int lastb = 0;
  int extended = 0;
  char *altufile = 
                  ((void *)0)
                      ;

  time_t until = 0;

  progname = mybasename(argv[0]);


  while((c = getopt(argc, argv, "f:n:RxadFliot:0123456789w")) != 
                                                                (-1)
                                                                   )
    switch(c) {
 case 'R':
  showhost = 0;
  break;
 case 'x':
  extended = 1;
  break;
 case 'n':
  maxrecs = atoi(optarg);
  break;
 case 'o':
  oldfmt = 1;
  break;
 case 'f':
  if((altufile = malloc(strlen(optarg)+1)) == 
                                             ((void *)0)
                                                 ) {
   fprintf(
          stderr
                , "%s: out of memory\n",
    progname);
   exit(1);
  }
  strcpy(altufile, optarg);
  break;
 case 'd':
  usedns++;
  break;
 case 'i':
  useip++;
  break;
 case 'a':
  altlist++;
  break;
 case 'F':
  fulltime++;
  break;
        case 'l':
                allow_long_username = 1;
                break;
 case 't':
  if ((until = parsetm(optarg)) == (time_t)-1) {
   fprintf(
          stderr
                , "%s: Invalid time value \"%s\"\n",
    progname, optarg);
   usage(progname);
  }
  break;
 case 'w':
  if (
     32 
                 > name_len)
   name_len = 
             32
                        ;
  if (
     256 
                 > domain_len)
   domain_len = 
               256
                          ;
  break;
 case '0': case '1': case '2': case '3': case '4':
 case '5': case '6': case '7': case '8': case '9':
  maxrecs = 10*maxrecs + c - '0';
  break;
 default:
  usage(progname);
  break;
    }
  if (optind < argc) show = argv + optind;




  if (strcmp(progname, "lastb") == 0) {
 ufile = getbtmp();
 lastb = 1;
  } else
 ufile = 
        "/var/log/wtmp"
                 ;
  if (altufile)
 ufile = altufile;
  time(&lastdown);
  lastrch = lastdown;




  lastdate = lastdown;
  signal(
        2
              , int_handler);
  signal(
        3
               , quit_handler);




  if ((fp = fopen(ufile, "r")) == 
                                 ((void *)0)
                                     ) {
 x = 
    (*__errno_location ())
         ;
 fprintf(
        stderr
              , "%s: %s: %s\n", progname, ufile, strerror(
                                                          (*__errno_location ())
                                                               ));
 if (altufile == 
                ((void *)0) 
                     && x == 
                             2
                                   )
  fprintf(
         stderr
               , "Perhaps this file was removed by the "
   "operator to prevent logging %s info.\n", progname);
 exit(1);
  }




  setvbuf(fp, 
             ((void *)0)
                 , 
                   0
                         , 16384);




  if (uread(fp, &ut, 
                    ((void *)0)
                        ) == 1)
 begintime = ut.
               ut_tv.tv_sec
                      ;
  else {
   fstat(fileno(fp), &st);
 begintime = st.
               st_ctim.tv_sec
                       ;
 quit = 1;
  }





  uread(fp, 
           ((void *)0)
               , 
                 ((void *)0)
                     );




  while(!quit) {

 if (uread(fp, &ut, &quit) != 1)
  break;

 if (until && until < ut.
                        ut_tv.tv_sec
                               )
  continue;

 if (memcmp(&ut, &oldut, sizeof(struct utmp)) == 0) continue;
 memcpy(&oldut, &ut, sizeof(struct utmp));
 lastdate = ut.
              ut_tv.tv_sec
                     ;

   if (lastb) {
    quit = list(&ut, ut.
                       ut_tv.tv_sec
                              , 3);
    continue;
   }




 if (strncmp(ut.ut_line, "~", 1) == 0) {
  if (strncmp(ut.ut_user, "shutdown", 8) == 0)
   ut.ut_type = 254;
  else if (strncmp(ut.ut_user, "reboot", 6) == 0)
   ut.ut_type = 
               2
                        ;
  else if (strncmp(ut.ut_user, "runlevel", 8) == 0)
   ut.ut_type = 
               1
                      ;
 }





 else {
  if (ut.ut_type != 
                   8 
                                &&
      ut.
        ut_user
               [0] && ut.ut_line[0] &&
      strcmp(ut.
               ut_user
                      , "LOGIN") != 0)
   ut.ut_type = 
               7
                           ;





  if (ut.
        ut_user
               [0] == 0)
   ut.ut_type = 
               8
                           ;




  if (strcmp(ut.
               ut_user
                      , "date") == 0) {
   if (ut.ut_line[0] == '|') ut.ut_type = 
                                         4
                                                 ;
   if (ut.ut_line[0] == '{') ut.ut_type = 
                                         3
                                                 ;
  }
 }


 switch (ut.ut_type) {
  case 254:
   if (extended) {
    strncpy(ut.ut_line, "system down", 12 - 1);
    quit = list(&ut, lastboot, 3);
   }
   lastdown = lastrch = ut.
                          ut_tv.tv_sec
                                 ;
   down = 1;
   break;
  case 
      4
              :
  case 
      3
              :
   if (extended) {
    strncpy(ut.ut_line,
    ut.ut_type == 
                 3 
                          ? "new time" :
     "old time", 12 - 1);
    quit = list(&ut, lastdown, 7);
   }
   break;
  case 
      2
               :
   strncpy(ut.ut_line, "system boot", 12 - 1);
   quit = list(&ut, lastdown, 5);
   lastboot = ut.
                ut_tv.tv_sec
                       ;
   down = 1;
   break;
  case 
      1
             :
   x = ut.ut_pid & 255;
   if (extended) {
    sprintf(ut.ut_line, "(to lvl %c)", x);
    quit = list(&ut, lastrch, 3);
   }
   if (x == '0' || x == '6') {
    lastdown = ut.
                 ut_tv.tv_sec
                        ;
    down = 1;
    ut.ut_type = 254;
   }
   lastrch = ut.
               ut_tv.tv_sec
                      ;
   break;

  case 
      7
                  :





   c = 0;
   for (p = utmplist; p; p = next) {
    next = p->next;
    if (strncmp(p->ut.ut_line, ut.ut_line,
        
       32
                  ) == 0) {

     if (c == 0) {
      quit = list(&ut, p->ut.
                            ut_tv.tv_sec
                                   ,
       3);
      c = 1;
     }
     if (p->next) p->next->prev = p->prev;
     if (p->prev)
      p->prev->next = p->next;
     else
      utmplist = p->next;
     free(p);
    }
   }




   if (c == 0) {
    if (lastboot == 0) {
     c = 4;

     if (ut.ut_pid > 0 &&
         kill(ut.ut_pid, 0) != 0 &&
         
        (*__errno_location ()) 
              == 
                 3
                      )
      c = 6;
    } else
     c = whydown;
    quit = list(&ut, lastboot, c);
   }


  case 
      8
                  :




   if (ut.ut_line[0] == 0)
    break;
   if ((p = malloc(sizeof(struct utmplist))) == 
                                               ((void *)0)
                                                   ) {
    fprintf(
           stderr
                 , "%s: out of memory\n",
     progname);
    exit(1);
   }
   memcpy(&p->ut, &ut, sizeof(struct utmp));
   p->next = utmplist;
   p->prev = 
             ((void *)0)
                 ;
   if (utmplist) utmplist->prev = p;
   utmplist = p;
   break;

 }




 if (down) {
  lastboot = ut.
               ut_tv.tv_sec
                      ;
  whydown = (ut.ut_type == 254) ? 2 : 1;
  for (p = utmplist; p; p = next) {
   next = p->next;
   free(p);
  }
  utmplist = 
            ((void *)0)
                ;
  down = 0;
 }
  }
  printf("\n%s begins %s", mybasename(ufile), ctime(&begintime));

  fclose(fp);




  return 0;
}
