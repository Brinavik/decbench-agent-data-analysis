

typedef struct proc {
 char *pathname;
 char *argv0;
 char *argv0base;
 char *argv1;
 char *argv1base;
 char *statname;
 pid_t pid;
 pid_t sid;
 char kernel;
 char nfs;
 struct proc *next;
} PROC;



typedef struct pidq {
 PROC *proc;
 struct pidq *next;
} PIDQ;

typedef struct {
 PIDQ *head;
 PIDQ *tail;
 PIDQ *next;
} PIDQ_HEAD;

typedef struct _s_omit {
 struct _s_omit *next;
 struct _s_omit *prev;
 pid_t pid;
} OMIT;

typedef struct _s_shadow
{
 struct _s_shadow *next;
 struct _s_shadow *prev;
 size_t nlen;
 char * name;
} SHADOW;

typedef struct _s_nfs
{
 struct _s_nfs *next;
 struct _s_nfs *prev;
 SHADOW *shadow;
 size_t nlen;
 char * name;
} NFS;


PROC *plist;


OMIT *omit;


NFS *nlist;


int sent_sigstop;
int scripts_too = 0;
int list_dz_processes = 0;

char *progname;

__attribute__ ((format (printf, 2, 3)))

void nsyslog(int pri, char *fmt, ...);
static void *xmalloc(size_t) __attribute__ ((__malloc__));

static void *xmalloc(size_t bytes)
{
 void *p;

 if ((p = malloc(bytes)) == 
                           ((void *)0)
                               ) {
  if (sent_sigstop) kill(-1, 
                            18
                                   );
  nsyslog(
         3
                , "out of memory");
  exit(1);
 }
 return p;
}


static __inline__ void xmemalign(void **, size_t, size_t) __attribute__ ((__nonnull__ (1)));

static __inline__ void xmemalign(void **memptr, size_t alignment, size_t size)
{
 if ((posix_memalign(memptr, alignment, size)) < 0) {
  if (sent_sigstop) kill(-1, 
                            18
                                   );
  nsyslog(
         3
                , "out of memory");
  exit(1);
 }
}




int mount_proc(void)
{
 struct stat st;
 char *args[] = { "mount", "-t", "proc", "proc", "/proc", 0 };
 pid_t pid, rc;
 int wst;
 int did_mount = 0;


 if (stat("/proc/version", &st) < 0 && 
                                      (*__errno_location ()) 
                                            == 
                                               2
                                                     ) {


  if ((pid = fork()) < 0) {
   nsyslog(
          3
                 , "cannot fork");
   exit(1);
  }
  if (pid == 0) {

   execv("/bin/mount", args);
   execv("/sbin/mount", args);


   nsyslog(
          3
                 , "cannot execute mount");
   exit(1);
  }

  while ((rc = wait(&wst)) != pid)
   if (rc < 0 && 
                (*__errno_location ()) 
                      == 
                         10
                               )
    break;
  if (rc != pid || 
                  (((
                  wst
                  ) & 0xff00) >> 8) 
                                   != 0)
   nsyslog(
          3
                 , "mount returned non-zero exit status");

  did_mount = 1;
 }


 if (stat("/proc/version", &st) < 0) {
  if (
     (*__errno_location ()) 
           == 
              2
                    )
   nsyslog(
          3
                 , "/proc not mounted, failed to mount.");
  else
   nsyslog(
          3
                 , "/proc unavailable.");
  exit(1);
 }

 return did_mount;
}

static __inline__ int isnetfs(const char * type)
{
 static const char* netfs[] = {"nfs", "nfs4", "smbfs", "cifs", "afs", "ncpfs", (char*)0};
 int n;
 for (n = 0; netfs[n]; n++) {
  if (!strcasecmp(netfs[n], type))
   return 1;
 }
 return 0;
}




void init_nfs(void)
{
        struct stat st;
        struct mntent * ent;
 FILE * mnt;

 nlist = (NFS*)0;

 if (stat("/proc/version", &st) < 0)
  return;
 if ((mnt = setmntent("/proc/mounts", "r")) == (FILE*)0)
  return;

 while ((ent = getmntent(mnt))) {
  if (isnetfs(ent->mnt_type)) {
   size_t nlen = strlen(ent->mnt_dir);
   NFS *__restrict__ p;
   xmemalign((void*)&p, sizeof(void*), ((sizeof(NFS)+(sizeof(void*)-1)) & ~(sizeof(void*)-1))+(nlen+1));
   p->name = ((char*)p)+((sizeof(NFS)+(sizeof(void*)-1)) & ~(sizeof(void*)-1));
   p->nlen = nlen;
   p->shadow = (SHADOW*)0;

   strcpy(p->name, ent->mnt_dir);
   if (nlist)
    nlist->prev = p;
   p->next = nlist;
   p->prev = (NFS*)0;
   nlist = p;
  }
 }
 endmntent(mnt);

 if ((mnt = setmntent("/proc/mounts", "r")) == (FILE*)0)
  return;

 while ((ent = getmntent(mnt))) {
  NFS *p;

  for (p = nlist; p; p = p->next) {
   SHADOW * __restrict__ s;
   size_t nlen;

   if (strcmp(ent->mnt_dir, p->name) == 0)
    continue;
   if (strncmp(ent->mnt_dir, p->name, p->nlen) != 0)
    continue;

   nlen = strlen(ent->mnt_dir);
   xmemalign((void*)&s, sizeof(void*), ((sizeof(SHADOW)+(sizeof(void*)-1)) & ~(sizeof(void*)-1))+(nlen+1));
   s->name = ((char*)s)+((sizeof(SHADOW)+(sizeof(void*)-1)) & ~(sizeof(void*)-1));
   s->nlen = nlen;

   strcpy(s->name, ent->mnt_dir);
   if (p->shadow)
       p->shadow->prev = s;
   s->next = p->shadow;
   s->prev = (SHADOW*)0;
   p->shadow = s;
  }
 }
 endmntent(mnt);
}

static void clear_shadow(SHADOW *__restrict__ shadow)
{
 SHADOW *s, *n, *l;

 n = shadow;
 l = (SHADOW*)0;
 for (s = shadow; n; s = n) {
  l = s->prev;
  n = s->next;
  if (s == shadow) {
   if (n) n->prev = (SHADOW*)0;
   shadow = n;
  } else if (l) {
   if (n) n->prev = l;
   l->next = n;
  }
  free(s);
 }
}

static void clear_mnt(void)
{
 NFS *p, *n, *l;

 n = nlist;
 l = (NFS*)0;
 for (p = nlist; n; p = n) {
  l = p->prev;
  n = p->next;
  if (p == nlist) {
   if (n) n->prev = (NFS*)0;
   nlist = n;
  } else if (l) {
   if (n) n->prev = l;
   l->next = n;
  }
  if (p->shadow)
   clear_shadow(p->shadow);
  free(p);
 }
}




static int shadow(SHADOW *__restrict__ this, const char *__restrict__ name, const size_t nlen)
{
 SHADOW *s;

 if (!this)
  goto out;
 for (s = this; s; s = s->next) {
  if (nlen < s->nlen)
   continue;
  if (name[s->nlen] != '\0' && name[s->nlen] != '/')
   continue;
  if (strncmp(name, s->name, s->nlen) == 0)
   return 1;
 }
out:
 return 0;
}





static int maxsymlinks(void)
{
 int v = sysconf(
                _SC_SYMLOOP_MAX
                               );

 if (v == -1)
  return 
        20
                   ;

 return v;
}




int check4nfs(const char * path, char * real)
{
 char buf[
         4096
                 +1];
 const char *curr;
 int deep = maxsymlinks();

 if (!nlist) return 0;

 curr = path;
 do {
  const char *prev;
  int len;

  if ((prev = 
             (__extension__ ({ const char *__old = (
             curr
             ); size_t __len = strlen (__old) + 1; char *__new = (char *) __builtin_alloca (__len); (char *) memcpy (__new, __old, __len); }))
                          ) == 
                               ((void *)0)
                                   ) {
   nsyslog(
          3
                 , "strdupa(): %s\n", strerror(
                                               (*__errno_location ())
                                                    ));
   return 0;
  }

  
 (*__errno_location ()) 
       = 0;
  if ((len = readlink(curr, buf, 
                                4096
                                        )) < 0)
   break;
  buf[len] = '\0';

  if (buf[0] != '/') {
   const char *slash;

   if ((slash = strrchr(prev, '/'))) {
    size_t off = slash - prev + 1;

    if (off + len > 
                   4096
                           )
     len = 
          4096 
                   - off;

    memmove(&buf[off], &buf[0], len + 1);
    memcpy(&buf[0], prev, off);
   }
  }
  curr = &buf[0];

  if (deep-- <= 0) return 0;

 } while (1);

 if (real)
        {
           memset(real, '\0', 
                             4096 
                                      + 1);
           strncpy(real, curr, 
                              4096
                                      );
        }

 if (
    (*__errno_location ()) 
          == 
             22
                   ) {
  const size_t nlen = strlen(curr);
  NFS *p;
  for (p = nlist; p; p = p->next) {
   if (nlen < p->nlen)
    continue;
   if (curr[p->nlen] != '\0' && curr[p->nlen] != '/')
    continue;
   if (!strncmp(curr, p->name, p->nlen)) {
    if (shadow(p->shadow, curr, nlen))
     continue;
    return 1;
   }
  }
 }

 return 0;
}

int readarg(FILE *fp, char *buf, int sz)
{
 int c = 0, f = 0;

 while (f < (sz-1) && (c = fgetc(fp)) != 
                                        (-1) 
                                            && c)
  buf[f++] = c;
 buf[f] = 0;

 return (c == 
             (-1) 
                 && f == 0) ? c : f;
}





int readproc()
{
 DIR *dir;
 FILE *fp;
 PROC *p, *n;
 struct dirent *d;
 char path[
           4096
                   +1];
 char buf[
          4096
                  +1];
 char *s, *q;
 unsigned long startcode, endcode;
 int pid, f;
        char process_status[11];


 if (chdir("/proc") == -1) {
  nsyslog(
         3
                , "chdir /proc failed");
  return -1;
 }
 if ((dir = opendir(".")) == 
                            ((void *)0)
                                ) {
  nsyslog(
         3
                , "cannot opendir(/proc)");
  return -1;
 }


 n = plist;
 for (p = plist; n; p = n) {
  n = p->next;
  if (p->argv0) free(p->argv0);
  if (p->argv1) free(p->argv1);
  if (p->statname) free(p->statname);
  if (p->pathname) free(p->pathname);
  free(p);
 }
 plist = 
        ((void *)0)
            ;


 while ((d = readdir(dir)) != 
                             ((void *)0)
                                 ) {


  if ((pid = atoi(d->d_name)) == 0) continue;


  p = (PROC *)xmalloc(sizeof(PROC));
  memset(p, 0, sizeof(PROC));


  snprintf(path, sizeof(path), "%s/stat", d->d_name);


  if ((fp = fopen(path, "r")) != 
                                ((void *)0)
                                    ) {
   size_t len;

   len = fread(buf, sizeof(char), sizeof(buf)-1, fp);
   buf[len] = '\0';

   if (buf[0] == '\0') {
    nsyslog(
           3
                  ,
     "can't read from %s\n", path);
    fclose(fp);
    free(p);
    continue;
   }


   s = buf;
   while (*s && *s != ' ') s++;
   if (*s) s++;
   if (*s == '(') {

    q = strrchr(buf, ')');
    if (q == 
            ((void *)0)
                ) {
     p->sid = 0;
     nsyslog(
            3
                   ,
     "can't get program name from /proc/%s\n",
      path);
     fclose(fp);
     if (p->argv0) free(p->argv0);
     if (p->argv1) free(p->argv1);
     if (p->statname) free(p->statname);
     if (p->pathname) free(p->pathname);
     free(p);
     continue;
    }
    s++;
   } else {
    q = s;
    while (*q && *q != ' ') q++;
   }
   if (*q) *q++ = 0;
   while (*q == ' ') q++;
   p->statname = (char *)xmalloc(strlen(s)+1);
   strcpy(p->statname, s);


   startcode = endcode = 0;
   if (sscanf(q, "%10s %*d %*d %d %*d %*d %*u %*u "
     "%*u %*u %*u %*u %*u %*d %*d "
     "%*d %*d %*d %*d %*u %*u %*d "
     "%*u %lu %lu",
     process_status,
     &p->sid, &startcode, &endcode) != 4) {

    p->sid = 0;
    nsyslog(
           3
                  , "can't read sid from %s\n",
     path);
    fclose(fp);
    if (p->argv0) free(p->argv0);
    if (p->argv1) free(p->argv1);
    if (p->statname) free(p->statname);
    free(p->pathname);
    free(p);
    continue;
   }
   if (startcode == 0 && endcode == 0)
    p->kernel = 1;
   fclose(fp);
                        if ( (! list_dz_processes) &&
                               (strchr(process_status, 'Z') != 
                                                              ((void *)0)
                                                                  ) ) {

                              if (p->argv0) free(p->argv0);
                              if (p->argv1) free(p->argv1);
                              if (p->statname) free(p->statname);
                             free(p);
                             continue;
                        }
  } else {

   if (p->argv0) free(p->argv0);
   if (p->argv1) free(p->argv1);
   if (p->statname) free(p->statname);
   if (p->pathname) free(p->pathname);
   free(p);
   continue;
  }

  snprintf(path, sizeof(path), "%s/cmdline", d->d_name);
  if ((fp = fopen(path, "r")) != 
                                ((void *)0)
                                    ) {


   f = readarg(fp, buf, sizeof(buf));

   if (buf[0]) {

    p->argv0 = (char *)xmalloc(f + 1);
    strcpy(p->argv0, buf);


    p->argv0base = strrchr(p->argv0, '/');
    if (p->argv0base != 
                       ((void *)0)
                           )
     p->argv0base++;
    else
     p->argv0base = p->argv0;
   }


   while ((f = readarg(fp, buf, sizeof(buf))) != 
                                                (-1)
                                                   )
    if (buf[0] != '-') break;

   if (buf[0]) {

    p->argv1 = (char *)xmalloc(f + 1);
    strcpy(p->argv1, buf);


    p->argv1base = strrchr(p->argv1, '/');
    if (p->argv1base != 
                       ((void *)0)
                           )
     p->argv1base++;
    else
     p->argv1base = p->argv1;
   }

   fclose(fp);

  } else {

   if (p->argv0) free(p->argv0);
   if (p->argv1) free(p->argv1);
   if (p->statname) free(p->statname);
   if (p->pathname) free(p->pathname);
   free(p);
   continue;
  }


  snprintf(path, sizeof(path), "/proc/%s/exe", d->d_name);
                p->pathname = (char *)xmalloc(
                                             4096
                                                     );
   if (readlink(path, p->pathname, 
                                  4096
                                          ) == -1) {
    p->pathname = 
                 ((void *)0)
                     ;
   }


  p->next = plist;
  plist = p;
  p->pid = pid;
 }
 closedir(dir);


 return 0;
}

PIDQ_HEAD *init_pid_q(PIDQ_HEAD *q)
{
 q->head = q->next = q->tail = 
                               ((void *)0)
                                   ;
 return q;
}

int empty_q(PIDQ_HEAD *q)
{
 return (q->head == 
                   ((void *)0)
                       );
}

int add_pid_to_q(PIDQ_HEAD *q, PROC *p)
{
 PIDQ *tmp;

 tmp = (PIDQ *)xmalloc(sizeof(PIDQ));

 tmp->proc = p;
 tmp->next = 
            ((void *)0)
                ;

 if (empty_q(q)) {
  q->head = tmp;
  q->tail = tmp;
 } else {
  q->tail->next = tmp;
  q->tail = tmp;
 }
 return 0;
}

PROC *get_next_from_pid_q(PIDQ_HEAD *q)
{
 PROC *p;
 PIDQ *tmp = q->head;

 if (!empty_q(q)) {
  p = q->head->proc;
  q->head = tmp->next;
  free(tmp);
  return p;
 }

 return 
       ((void *)0)
           ;
}


PIDQ_HEAD *pidof(char *prog)
{
 PROC *p;
 PIDQ_HEAD *q;
 char *s;
 int nfs = 0;
 int dostat = 0;
 int foundone = 0;
 int ok = 0;
 const int root = (getuid() == 0);
 char real_path[
                4096
                        +1];

 if (! prog)
  return 
        ((void *)0)
            ;


 if ( (prog[0] == '/') && ( realpath(prog, real_path) ) ) {
  memset(&real_path[0], 0, sizeof(real_path));
  dostat++;
 }


 if ((s = strrchr(prog, '/')) == 
                                ((void *)0)
                                    )
  s = prog;
 else
  s++;

 if (! *s)
  return 
        ((void *)0)
            ;

 q = (PIDQ_HEAD *)xmalloc(sizeof(PIDQ_HEAD));
 q = init_pid_q(q);


 if (dostat) {
  for (p = plist; p; p = p->next) {
   if (p->pathname && strcmp(real_path, p->pathname) == 0) {
    add_pid_to_q(q, p);
    foundone++;
   }
  }
 }



 if (!foundone && nfs) {
  for (p = plist; p; p = p->next) {
   if (!p->pathname)
    continue;
   if (!p->nfs)
    continue;
   if (strcmp(prog, p->pathname) != 0)
    continue;
   add_pid_to_q(q, p);
   foundone++;
  }
 }


 if (!foundone) for (p = plist; p; p = p->next) {
  if (prog[0] == '/') {
   if (!p->pathname) {
    if (root)
     continue;
    goto fallback;
   }
   if (strcmp(prog, p->pathname)) {
    int len = strlen(prog);
    if (strncmp(prog, p->pathname, len))
    {
     if (scripts_too)
      goto fallback;
     continue;
    }
    if (strcmp(" (deleted)", p->pathname + len))
    {
     if (scripts_too)
      goto fallback;
     continue;
    }
   }
   add_pid_to_q(q, p);
   continue;
  }

 fallback:
  ok = 0;
  ok |=
   (p->argv0 && strcmp(p->argv0, prog) == 0)
   || (p->argv0 && s != prog && strcmp(p->argv0, s) == 0)
   || (p->argv0base && strcmp(p->argv0base, prog) == 0);


  if (
   scripts_too && p->statname && p->argv1base
   && !strncmp(p->statname, p->argv1base, 15)
  ) {
   ok |=
    (p->argv1 && strcmp(p->argv1, prog) == 0)
    || (p->argv1 && s != prog && strcmp(p->argv1, s) == 0)
    || (p->argv1base && strcmp(p->argv1base, prog) == 0);
  }





  if (strlen(s) <= 15 &&
      (p->argv0 == 
                  ((void *)0) 
                       ||
       p->argv0[0] == 0 ||
       strchr(p->argv0, ' '))) {
   ok |= (strcmp(p->statname, s) == 0);
  }





  if (strlen(s) <= 15 &&
      p->argv1 == 
                 ((void *)0) 
                      &&
      (p->argv0 != 
                  ((void *)0) 
                       &&
       p->argv0[0] == '-')) {
   ok |= (strcmp(p->statname, s) == 0);
  }

  if (ok) add_pid_to_q(q, p);
 }

 return q;
}


void usage(void)
{
 nsyslog(
        3
               , "only one argument, a signal number, allowed");
 closelog();
 exit(1);
}


void pidof_usage(void)
{
   printf("pidof usage: [options] <program-name>\n\n");
   printf(" -c           Return PIDs with the same root directory\n");
   printf(" -d <sep>     Use the provided character as output separator\n");
   printf(" -h           Display this help text\n");
   printf(" -n           Avoid using stat system function on network shares\n");
   printf(" -o <pid>     Omit results with a given PID\n");
   printf(" -q           Quiet mode. Do not display output\n");
   printf(" -s           Only return one PID\n");
   printf(" -x           Return PIDs of shells running scripts with a matching name\n");
   printf(" -z           List zombie and I/O waiting processes. May cause pidof to hang.\n");
   printf("\n");
}




__attribute__ ((format (printf, 2, 3)))

void nsyslog(int pri, char *fmt, ...)
{
 va_list args;

 
__builtin_va_start(
args
,
fmt
)
                   ;

 if (ttyname(0) == 
                  ((void *)0)
                      ) {
  vsyslog(pri, fmt, args);
 } else {
  fprintf(
         stderr
               , "%s: ",progname);
  vfprintf(
          stderr
                , fmt, args);
  fprintf(
         stderr
               , "\n");
 }

 
__builtin_va_end(
args
)
            ;
}
int main_pidof(int argc, char **argv)
{
 PIDQ_HEAD *q;
 PROC *p;
 char *token, *here;
 int f;
 int first = 1;
 int opt, flags = 0;
 int chroot_check = 0;
 struct stat st;
 char tmp[512];
        char sep = ' ';

 omit = (OMIT*)0;
 nlist = (NFS*)0;
 opterr = 0;

 if ((token = getenv("PIDOF_NETFS")) && (strcmp(token,"no") != 0))
  flags |= 0x04;

 while ((opt = getopt(argc,argv,"qhco:d:sxzn")) != 
                                                  (-1)
                                                     ) switch (opt) {
  case '?':
   nsyslog(
          3
                 ,"invalid options on command line!\n");
   closelog();
   exit(1);
  case 'c':
   if (geteuid() == 0) chroot_check = 1;
   break;
                case 'h':
                        pidof_usage();
                        exit(0);
                case 'd':
                        sep = optarg[0];
                        break;
  case 'o':
   here = optarg;
   while ((token = strsep(&here, ",;:"))) {
    OMIT *__restrict__ optr;
    pid_t opid;

    if (strcmp("%PPID", token) == 0)
     opid = getppid();
    else
     opid = (pid_t)atoi(token);

    if (opid < 1) {
     nsyslog(
            3
                   ,
      "illegal omit pid value "
      "(%s)!\n", token);
     continue;
    }
    xmemalign((void*)&optr, sizeof(void*), ((sizeof(OMIT)+(sizeof(void*)-1)) & ~(sizeof(void*)-1)));
    optr->next = omit;
    optr->prev = (OMIT*)0;
    optr->pid = opid;
    omit = optr;
   }
   flags |= 0x02;
   break;
                case 'q':
                        flags |= 0x08;
                        break;
  case 's':
   flags |= 0x01;
   break;
  case 'x':
   scripts_too++;
   break;
                case 'z':
                        list_dz_processes = 1;
                        break;
  case 'n':
   flags |= 0x04;
   break;
  default:

   break;
 }
 argc -= optind;
 argv += optind;


 if (chroot_check) {
  snprintf(tmp, 512, "/proc/%d/root", getpid());
  if (stat(tmp, &st) < 0) {
   nsyslog(
          3
                 , "stat failed for %s!\n", tmp);
   closelog();
   exit(1);
  }
 }

 if (flags & 0x04)
  init_nfs();


 readproc();

 for(f = 0; f < argc; f++) {
  if ((q = pidof(argv[f])) != 
                             ((void *)0)
                                 ) {
   pid_t spid = 0;
   while ((p = get_next_from_pid_q(q))) {
    if ((flags & 0x02) && omit) {
     OMIT * optr;
     for (optr = omit; optr; optr = optr->next) {
      if (optr->pid == p->pid)
       break;
     }





     if (optr)
      continue;
    }
    if (flags & 0x01) {
     if (spid)
      continue;
     else
      spid = 1;
    }
    if (chroot_check) {
     struct stat st2;
     snprintf(tmp, 512, "/proc/%d/root",
       p->pid);
     if (stat(tmp, &st2) < 0 ||
         st.st_dev != st2.st_dev ||
         st.st_ino != st2.st_ino) {
      continue;
     }
    }

    if ( ~flags & 0x08 ) {
     if (! first)
      printf("%c", sep);
     printf("%d", p->pid);
    }
    first = 0;
   }
  }
 }
 if (!first)
        {
            if ( ~flags & 0x08 )
  printf("\n");
        }

 clear_mnt();

 closelog();
 return(first ? 1 : 0);
}


int main(int argc, char **argv)
{
 PROC *p;
 int pid, sid = -1;
 int sig = 
           9
                  ;
 int c;


 int retval = 2;


 if ((progname = strrchr(argv[0], '/')) == 
                                          ((void *)0)
                                              )
  progname = argv[0];
 else
  progname++;


 openlog(progname, 
                  0x02
                          |
                           0x01
                                  , 
                                    (3<<3)
                                              );


 if (strcmp(progname, "pidof") == 0)
  return main_pidof(argc, argv);


 omit = (OMIT*)0;

 if (argc > 1) {
  for (c = 1; c < argc; c++) {
   if (argv[c][0] == '-') (argv[c])++;
   if (argv[c][0] == 'o') {
    char * token, * here;

    if (++c >= argc)
     usage();

    here = argv[c];
    while ((token = strsep(&here, ",;:"))) {
     OMIT *__restrict__ optr;
     pid_t opid = (pid_t)atoi(token);

     if (opid < 1) {
      nsyslog(
             3
                    ,
       "illegal omit pid value "
       "(%s)!\n", token);
      continue;
     }
     xmemalign((void*)&optr, sizeof(void*), ((sizeof(OMIT)+(sizeof(void*)-1)) & ~(sizeof(void*)-1)));
     optr->next = omit;
     optr->prev = (OMIT*)0;
     optr->pid = opid;
     omit = optr;
    }
   }
   else if ((sig = atoi(argv[1])) <= 0 || sig > 31)
    usage();
  }
 }


 mount_proc();







 signal(
       15
              , 
                ((__sighandler_t) 1)
                       );
 signal(
       19
              , 
                ((__sighandler_t) 1)
                       );
 signal(
       9
              , 
                ((__sighandler_t) 1)
                       );


 mlockall(
         1 
                     | 
                       2
                                 );


 kill(-1, 
         19
                );
 sent_sigstop = 1;


 if (readproc() < 0) {
  kill(-1, 
          18
                 );
  return(1);
 }


 sid = (int)getsid(0);
 pid = (int)getpid();
 for (p = plist; p; p = p->next) {
  if (p->pid == 1 || p->pid == pid || p->sid == sid || p->kernel)
   continue;

  if (omit) {
   OMIT * optr;
   for (optr = omit; optr; optr = optr->next) {
    if (optr->pid == p->pid)
     break;
   }


   if (optr)
    continue;
  }

  kill(p->pid, sig);
  retval = 0;
 }


 kill(-1, 
         18
                );


 closelog();


 usleep(1);

 return retval;
}
