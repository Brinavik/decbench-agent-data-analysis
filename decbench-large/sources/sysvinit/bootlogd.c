

















char ringbuf[32768];
char *endptr = ringbuf + sizeof(ringbuf);
char *inptr = ringbuf;
char *outptr = ringbuf;

int got_signal = 0;
int didnl = 1;
int createlogfile = 0;
int syncalot = 0;

struct real_cons {
 char name[1024];
 int fd;
};





struct consdev {
 char *cmdline;
 char *dev1;
 char *dev2;
} consdev[] = {
 { "ttyB", "/dev/ttyB%s", 
                          ((void *)0) 
                                },
 { "ttySC", "/dev/ttySC%s", "/dev/ttsc/%s" },
 { "ttyS", "/dev/ttyS%s", "/dev/tts/%s" },
 { "tty", "/dev/tty%s", "/dev/vc/%s" },
 { "hvc", "/dev/hvc%s", "/dev/hvc/%s" },
 { 
  ((void *)0)
      , 
         ((void *)0)
             , 
                 ((void *)0) 
                       },
};





char *defcons[] = { "tty0", "hvc0", "ttyS0", "ttySC0", "ttyB0", 
                                                               ((void *)0) 
                                                                    };




void handler(int sig)
{
 got_signal = sig;
}





static int chdir_int(const char *path)
{
 int ret;

 if ((ret = chdir(path)) != 0) {
  const char *msgprefix = "bootlogd: %s";
  char msg[
          4096 
                   + sizeof(msgprefix)];
  snprintf(msg, sizeof(msg), msgprefix, path);
          perror(msg);
 }

 return ret;
}





static int findtty(char *res, const char *startdir, int rlen, dev_t dev)
{
 DIR *dir;
 struct dirent *ent;
 struct stat st;
 int r = -1;
 char *olddir = getcwd(
                      ((void *)0)
                          , 0);

 if (chdir_int(startdir) < 0 || (dir = opendir(".")) == 
                                                       ((void *)0)
                                                           ) {
  chdir_int(olddir);
  return -1;
 }
 while ((ent = readdir(dir)) != 
                               ((void *)0)
                                   ) {
  if (lstat(ent->d_name, &st) != 0)
   continue;
  if (
     ((((
     st.st_mode
     )) & 0170000) == (0040000))
      
     && 0 != strcmp(".", ent->d_name)
      && 0 != strcmp("..", ent->d_name)) {
   char *path = malloc(rlen);
   snprintf(path, rlen, "%s/%s", startdir, ent->d_name);
   r = findtty(res, path, rlen, dev);
   free(path);
   if (0 == r) {
    closedir(dir);
    chdir_int(olddir);
    return 0;
   }
   continue;
  }
  if (!
      ((((
      st.st_mode
      )) & 0170000) == (0020000))
                         )
   continue;
  if (st.st_rdev == dev) {
   if ( (int) (strlen(ent->d_name) + strlen(startdir) + 1) >= rlen) {
    fprintf(
           stderr
                 , "bootlogd: console device name too long\n");
    closedir(dir);
    chdir_int(olddir);
    return -1;
   } else {
    snprintf(res, rlen, "%s/%s", startdir, ent->d_name);
    closedir(dir);
    chdir_int(olddir);
    return 0;
   }
  }
 }
 closedir(dir);

 chdir_int(olddir);
 return r;
}
int findpty(int *master, int *slave, char *name)
{
 char pty[16];
 char tty[16];
 int i, j;
 int found;

 if (openpty(master, slave, name, 
                                 ((void *)0)
                                     , 
                                       ((void *)0)
                                           ) >= 0)
  return 0;

 found = 0;

 for (i = 'p'; i <= 'z'; i++) {
  for (j = '0'; j <= 'f'; j++) {
   if (j == '9' + 1) j = 'a';
   sprintf(pty, "/dev/pty%c%c", i, j);
   sprintf(tty, "/dev/tty%c%c", i, j);
   if ((*master = open(pty, 
                           02
                                 |
                                  0400
                                          )) >= 0) {
    *slave = open(tty, 
                      02
                            |
                             0400
                                     );
    if (*slave >= 0) {
     found = 1;
     break;
    }
   }
  }
  if (found) break;
 }
 if (!found) return -1;

 if (name) strcpy(name, tty);

 return 0;
}

static int istty(const char *dev)
{
 int fd, ret;

 fd = open(dev, 
               00
                       |
                        04000
                                  );
 if (fd < 0)
  return 0;

 ret = isatty(fd);

 close(fd);

 return ret;
}





int isconsole(char *s, char *res, int rlen)
{
 struct consdev *c;
 int l, sl, i, fd;
 char *p, *q;

 sl = strlen(s);

 for (c = consdev; c->cmdline; c++) {
  l = strlen(c->cmdline);
  if (sl <= l) continue;
  p = s + l;
  if (strncmp(s, c->cmdline, l) != 0)
   continue;
  for (i = 0; i < 2; i++) {
   snprintf(res, rlen, i ? c->dev1 : c->dev2, p);
   if ((q = strchr(res, ',')) != 
                                ((void *)0)
                                    ) *q = 0;
   if ((fd = open(res, 
                      00
                              |
                               04000
                                         )) >= 0) {
    close(fd);
    return 1;
   }
  }
 }


 snprintf(res, rlen, "/dev/%s", s);
 if ((q = strchr(res, ',')) != 
                              ((void *)0)
                                  ) *q = 0;
 if (istty(res))
  return 1;

 return 0;
}





int consolenames(struct real_cons *cons, int max_consoles)
{

 unsigned int kdev;

 struct stat st, st2;
 char buf[4096];
 char *p;
 int didmount = 0;
 int n;
 int fd;
 int considx, num_consoles = 0;





 stat("/", &st);
 if (stat("/proc", &st2) < 0) {
  perror("bootlogd: /proc");
  return 0;
 }
 if (st.st_dev == st2.st_dev) {
  if (mount("proc", "/proc", "proc", 0, 
                                       ((void *)0)
                                           ) < 0) {
   perror("bootlogd: mount /proc");
   return -1;
  }
  didmount = 1;
 }

 n = -1;
 if ((fd = open("/proc/cmdline", 
                                00
                                        )) < 0) {
  perror("bootlogd: /proc/cmdline");
 } else {
  buf[0] = 0;
  if ((n = read(fd, buf, 4096 - 1)) < 0)
   perror("bootlogd: /proc/cmdline");
  close(fd);
 }
 if (didmount) umount("/proc");

 if (n < 0) return 0;





 p = buf + n;
 *p-- = 0;
 while (p >= buf) {
  if (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n') {
   *p-- = 0;
   continue;
  }
  if (strncmp(p, "console=", 8) == 0 &&
   isconsole(p + 8, cons[num_consoles].name, sizeof(cons[num_consoles].name))) {



    for (considx = 0; considx < num_consoles; considx++) {
     if (!strcmp(cons[num_consoles].name, cons[considx].name)) {
      goto dontuse;
     }
    }

   num_consoles++;
   if (num_consoles >= max_consoles) {
    break;
   }
  }
dontuse:
  p--;
 }

 if (num_consoles > 0) return num_consoles;

 fstat(0, &st);
 if (
    gnu_dev_major (
    st.st_rdev
    ) 
                      != 5 || 
                              gnu_dev_minor (
                              st.st_rdev
                              ) 
                                                != 1) {



  int r = findtty(cons[num_consoles].name, "/dev",
                                sizeof(cons[num_consoles].name), st.st_rdev);
  if (!r)
   num_consoles++;
 }

 if (num_consoles > 0) return num_consoles;





 if (ioctl(0, 
             (((2U) << (((0 +8)+8)+14)) | ((('T')) << (0 +8)) | (((0x32)) << 0) | ((((sizeof(unsigned int)))) << ((0 +8)+8)))
                     , &kdev) == 0) {
  int r = findtty(cons[num_consoles].name, "/dev",
                                sizeof(cons[num_consoles].name), (dev_t)kdev);
  if (!r)
   num_consoles++;
 }

 if (num_consoles > 0) return num_consoles;






 for (n = 0; defcons[n]; n++)
  if (isconsole(defcons[n], cons[0].name, sizeof(cons[0].name)))
   return 1;

 fprintf(
        stderr
              , "bootlogd: cannot deduce real console device\n");

 return 0;
}





void writelog(FILE *fp, unsigned char *ptr, int len, int print_escape_characters)
{
 int dosync = 0;
 int i;
 static int first_run = 1;
 static int inside_esc = 0;

 for (i = 0; i < len; i++) {
  int ignore = 0;


  if (*(ptr-1) == '\n' || first_run) {
   time_t t;
   char *s;
   time(&t);
   s = ctime(&t);
   fprintf(fp, "%.24s: ", s);
   dosync = 1;
   first_run = 0;
  }



                if (! print_escape_characters)
                {
                    if (inside_esc == 1) {

   if (*ptr == '[') {

    ignore = 1;
    inside_esc = 2;
   } else {

    if (*ptr >= 64 && *ptr <= 95) {
     ignore = 1;
    }
    inside_esc = 0;
   }
                    } else if (inside_esc == 2) {
   switch (*ptr) {
    case '0' ... '9':
    case ';':
    case 32 ... 47:
     if (inside_esc) {
      ignore = 1;
     }
     break;
    case 64 ... 126:
     if (inside_esc) {
      ignore = 1;
      inside_esc = 0;
     }
     break;
                        }
       } else {
   switch (*ptr) {
    case '\r':
     ignore = 1;
     break;
    case 27:
     ignore = 1;
     inside_esc = 1;
     break;
   }
       }
                }

  if (!ignore) {
   fwrite(ptr, sizeof(char), 1, fp);
  }

  ptr++;
 }
 if (dosync) {
  fflush(fp);
  if (syncalot) {
   fdatasync(fileno(fp));
  }
 }

 outptr += len;
 if (outptr >= endptr)
  outptr = ringbuf;

}





void usage(void)
{
 fprintf(
        stderr
              , "Usage: bootlogd [-v] [-r] [-d] [-e] [-s] [-c] [-p pidfile] [-l logfile]\n");
 exit(1);
}

int open_nb(char *buf)
{
 int fd, n;

 if ((fd = open(buf, 
                    01
                            |
                             04000
                                       |
                                        0400
                                                )) < 0)
  return -1;
 n = fcntl(fd, 
              3
                     );
 n &= ~(
       04000
                 );
 fcntl(fd, 
          4
                 , n);

 return fd;
}





int write_err(int pts, int realfd, char *realcons, int e)
{
 int fd;

 if (e != 
         5
            ) {
werr:
  close(pts);
  fprintf(
         stderr
               , "bootlogd: writing to console: %s\n",
   strerror(e));
  return -1;
 }
 close(realfd);
 if ((fd = open_nb(realcons)) < 0)
  goto werr;

 return fd;
}

int main(int argc, char **argv)
{
 FILE *fp;
 struct timeval tv;
 fd_set fds;
 char buf[1024];
 char *p;
 char *logfile;
 char *pidfile;
 int rotate;
 int dontfork;
 int ptm, pts;

 int n, m, i;
 int todo;



 int considx;
 struct real_cons cons[16];
 int num_consoles, consoles_left;
        int print_escape_sequence = 0;
 fp = 
     ((void *)0)
         ;
 logfile = "/var/log/boot";
 pidfile = 
          ((void *)0)
              ;
 rotate = 0;
 dontfork = 0;

 while ((i = getopt(argc, argv, "cdesl:p:rv")) != 
                                                 (-1)
                                                    ) switch(i) {
  case 'l':
   logfile = optarg;
   break;
  case 'r':
   rotate = 1;
   break;
  case 'v':
   printf("bootlogd - %s\n", "3.05");
   exit(0);
   break;
  case 'p':
   pidfile = optarg;
   break;
  case 'c':
   createlogfile = 1;
   break;
  case 'd':
   dontfork = 1;
   break;
                case 'e':
                        print_escape_sequence = 1;
                        break;
  case 's':
   syncalot = 1;
   break;
  default:
   usage();
   break;
 }
 if (optind < argc) usage();

 signal(
       15
              , handler);
 signal(
       3
              , handler);
 signal(
       2
             , handler);
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
 signal(
       20
              , 
                 ((__sighandler_t) 1)
                        );
        if ((num_consoles = consolenames(cons, 16)) <= 0)
                return 1;
        consoles_left = num_consoles;
        for (considx = 0; considx < num_consoles; considx++) {
               if (strcmp(cons[considx].name, "/dev/tty0") == 0)
                       strcpy(cons[considx].name, "/dev/tty1");
               if (strcmp(cons[considx].name, "/dev/vc/0") == 0)
                       strcpy(cons[considx].name, "/dev/vc/1");

               if ((cons[considx].fd = open_nb(cons[considx].name)) < 0) {
                       fprintf(
                              stderr
                                    , "bootlogd: %s: %s\n",
                                cons[considx].name, strerror(
                                                            (*__errno_location ())
                                                                 ));
                       consoles_left--;
               }
        }
        if (!consoles_left)
               return 1;





 ptm = -1;
 pts = -1;
 buf[0] = 0;
 if (findpty(&ptm, &pts, buf) < 0) {
  fprintf(
         stderr
               ,
   "bootlogd: cannot allocate pseudo tty: %s\n",
   strerror(
           (*__errno_location ())
                ));
  return 1;
 }


 (void)ioctl(0, 
               0x541D
                       , 
                         ((void *)0)
                             );

 if ((n = open("/dev/tty0", 
                           02
                                 )) >= 0) {
  (void)ioctl(n, 
                0x541D
                        , 
                          ((void *)0)
                              );
  close(n);
 }


 if (ioctl(pts, 
               0x541D
                       , 
                         ((void *)0)
                             ) < 0)



 {
  fprintf(
         stderr
               , "bootlogd: ioctl(%s, TIOCCONS): %s\n",
   buf, strerror(
                (*__errno_location ())
                     ));
  return 1;
 }




 if (!dontfork) {
  pid_t child_pid = fork();
  switch (child_pid) {
  case -1:
   fprintf(
          stderr
                , "bootlogd: fork failed: %s\n",
    strerror(
            (*__errno_location ())
                 ));
   exit(1);
   break;
  case 0:
   break;
  default:
   exit(0);
   break;
  }
  setsid();
 }
 if (pidfile) {
  unlink(pidfile);
  if ((fp = fopen(pidfile, "w")) != 
                                   ((void *)0)
                                       ) {
   fprintf(fp, "%d\n", (int)getpid());
   fclose(fp);
  }
  fp = 
      ((void *)0)
          ;
 }





 while (!got_signal) {






  tv.tv_sec = 0;
  tv.tv_usec = 500000;
  
 do { unsigned int __i; fd_set *__arr = (
 &fds
 ); for (__i = 0; __i < sizeof (fd_set) / sizeof (__fd_mask); ++__i) ((__arr)->fds_bits)[__i] = 0; } while (0)
              ;
  
 ((void) (((
 &fds
 )->fds_bits)[((
 ptm
 ) / (8 * (int) sizeof (__fd_mask)))] |= ((__fd_mask) (1UL << ((
 ptm
 ) % (8 * (int) sizeof (__fd_mask)))))))
                  ;
  if (select(ptm + 1, &fds, 
                           ((void *)0)
                               , 
                                 ((void *)0)
                                     , &tv) == 1) {



   if ((n = read(ptm, inptr, endptr - inptr)) >= 0) {




    for (considx = 0; considx < num_consoles; considx++) {
     if (cons[considx].fd < 0) continue;
     m = n;
     p = inptr;
     while (m > 0) {
      i = write(cons[considx].fd, p, m);
      if (i >= 0) {
       m -= i;
       p += i;
       continue;
      }




      cons[considx].fd = write_err(pts,
       cons[considx].fd,
       cons[considx].name, 
                          (*__errno_location ())
                               );
      if (cons[considx].fd >= 0) continue;




      if (--consoles_left <= 0) got_signal = 1;
      break;
      }
    }






    inptr += n;
    if (inptr - n < outptr && inptr > outptr)
     outptr = inptr;
    if (inptr >= endptr)
     inptr = ringbuf;
    if (outptr >= endptr)
     outptr = ringbuf;
   }
  }




  if (fp == 
           ((void *)0) 
                && access(logfile, 
                                   0
                                       ) == 0) {
   if (rotate) {
    snprintf(buf, sizeof(buf), "%s~", logfile);
    rename(logfile, buf);
   }
   fp = fopen(logfile, "a");
  }
  if (fp == 
           ((void *)0) 
                && createlogfile)
   fp = fopen(logfile, "a");

  if (inptr >= outptr)
   todo = inptr - outptr;
  else
   todo = endptr - outptr;
  if (fp && todo)
   writelog(fp, (unsigned char *)outptr, todo, print_escape_sequence);
 }

 if (fp) {
  if (!didnl) fputc('\n', fp);
  fclose(fp);
 }

 close(pts);
 close(ptm);
 for (considx = 0; considx < num_consoles; considx++) {
  close(cons[considx].fd);
 }

 return 0;
}
