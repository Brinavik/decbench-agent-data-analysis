













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









static void overwrite_database(cron_db *, cron_db *);

static void process_crontab(const char *, const char *,
 const char *, cron_db *, cron_db *);

static int not_a_crontab(struct dirent * dp);


static void max_mtime(const char *dir_name, struct stat *max_st);


static int
check_open(const char *tabname, const char *uname,
 struct passwd *pw, time_t * mtime) {
 struct stat statbuf;
 int crontab_fd;
 pid_t pid = getpid();

 if ((crontab_fd =
   open(tabname, 
                00 
                         | 
                           04000
                                     , 0)) == -1) {
  log_it(uname, pid, "CAN'T OPEN", tabname, 
                                           (*__errno_location ())
                                                );
  return (-1);
 }
 if (fstat(crontab_fd, &statbuf) < 0) {
  log_it(uname, pid, "STAT FAILED", tabname, 
                                            (*__errno_location ())
                                                 );
  close(crontab_fd);
  return (-1);
 }
 *mtime = statbuf.
                 st_mtim.tv_sec
                         ;
 if (PermitAnyCrontab == 0) {
  if (!
      ((((
      statbuf.st_mode
      )) & 0170000) == (0100000))
                              ) {
   log_it(uname, pid, "NOT REGULAR", tabname, 0);
   close(crontab_fd);
   return (-1);
  }
  if ((statbuf.st_mode & 07533) != 0400) {
   log_it(uname, pid, "BAD FILE MODE", tabname, 0);
   close(crontab_fd);
   return (-1);
  }
  if (statbuf.st_uid != 0 && (pw == 
                                          ((void *)0) 
                                               ||
    statbuf.st_uid != pw->pw_uid ||
    strcmp(uname, pw->pw_name) != 0)) {
   log_it(uname, pid, "WRONG FILE OWNER", tabname, 0);
   close(crontab_fd);
   return (-1);
  }
  if (pw && statbuf.st_nlink != 1) {
   log_it(uname, pid, "BAD LINK COUNT", tabname, 0);
   close(crontab_fd);
   return (-1);
  }
 }
 return (crontab_fd);
}

static orphan *orphans;

static void
free_orphan(orphan *o) {
 free(o->tabname);
 free(o->fname);
 free(o->uname);
 free(o);
}

void
check_orphans(cron_db *db) {
 orphan *prev_orphan = 
                      ((void *)0)
                          ;
 orphan *o = orphans;

 while (o != 
            ((void *)0)
                ) {
  if (getpwnam(o->uname) != 
                           ((void *)0)
                               ) {
   orphan *next = o->next;

   if (prev_orphan == 
                     ((void *)0)
                         ) {
    orphans = next;
   } else {
    prev_orphan->next = next;
   }

   process_crontab(o->uname, o->fname, o->tabname,
    db, 
       ((void *)0)
           );


   if (prev_orphan == 
                     ((void *)0) 
                          && orphans != next) {
    prev_orphan = orphans;
   }
   free_orphan(o);
   o = next;
  } else {
   prev_orphan = o;
   o = o->next;
  }
 }
}

static int
find_orphan(const char *uname, const char *fname, const char *tabname) {
 orphan *o;

 for (o = orphans; o != 
                       ((void *)0)
                           ; o = o->next) {
  if (uname && o->uname) {
   if (strcmp(uname, o->uname) != 0)
    continue;
  } else if (uname != o->uname)
   continue;

  if (fname && o->fname) {
   if (strcmp(fname, o->fname) != 0)
    continue;
  } else if (fname != o->fname)
   continue;

  if (tabname && o->tabname) {
   if (strcmp(tabname, o->tabname) != 0)
    continue;
  } else if (tabname != o->tabname)
   continue;
  return 1;
 }

 return 0;
}

static void
add_orphan(const char *uname, const char *fname, const char *tabname) {
 orphan *o;

 if (find_orphan(uname, fname, tabname))
  return;

 o = calloc(1, sizeof(*o));
 if (o == 
         ((void *)0)
             )
  return;

 if (uname)
  if ((o->uname=strdup(uname)) == 
                                 ((void *)0)
                                     )
   goto cleanup;

 if (fname)
  if ((o->fname=strdup(fname)) == 
                                 ((void *)0)
                                     )
   goto cleanup;

 if (tabname)
  if ((o->tabname=strdup(tabname)) == 
                                     ((void *)0)
                                         )
   goto cleanup;

 o->next = orphans;
 orphans = o;
 return;

cleanup:
 free_orphan(o);
}

static void
process_crontab(const char *uname, const char *fname, const char *tabname,
 cron_db * new_db, cron_db * old_db) {
 struct passwd *pw = 
                    ((void *)0)
                        ;
 int crontab_fd = -1;
 user *u = 
          ((void *)0)
              ;
 time_t mtime;
 int crond_crontab = (fname == 
                              ((void *)0)
                                  ) && (strcmp(tabname, "/usr/local/etc/crontab") != 0);

 if (fname == 
             ((void *)0)
                 ) {


  fname = "*system*";
 }
 else if ((pw = getpwnam(uname)) == 
                                   ((void *)0)
                                       ) {


  log_it(uname, getpid(), "ORPHAN", "no passwd entry", 0);
  add_orphan(uname, fname, tabname);

  goto next_crontab;
 }

 if ((crontab_fd = check_open(tabname, uname, pw, &mtime)) == -1)
  goto next_crontab;

 mtime = ((new_db->mtime)<(mtime)?(new_db->mtime):(mtime));

 if ((DebugFlags & (0x0010)) != 0) printf ("\t%s:", fname);

 if (old_db != 
              ((void *)0)
                  )
  u = find_user(old_db, fname, crond_crontab ? tabname : 
                                                        ((void *)0)
                                                            );

 if (u != 
         ((void *)0)
             ) {



  if (u->mtime == mtime) {
   if ((DebugFlags & (0x0010)) != 0) printf (" [no change, using old data]");
   unlink_user(old_db, u);
   link_user(new_db, u);
   goto next_crontab;
  }
  if ((DebugFlags & (0x0010)) != 0) printf (" [delete old data]");
  unlink_user(old_db, u);
  free_user(u);
  log_it(fname, getpid(), "RELOAD", tabname, 0);
 }

 u = load_user(crontab_fd, pw, uname, fname, tabname);
 crontab_fd = -1;
 if (u != 
         ((void *)0)
             ) {
  u->mtime = mtime;
  link_user(new_db, u);
 }

  next_crontab:
 if (crontab_fd != -1) {
  if ((DebugFlags & (0x0010)) != 0) printf (" [done]\n");
  close(crontab_fd);
 }
}

static int
cluster_host_is_local(void)
{
 char filename[
              255
                      +1];
 int is_local;
 FILE *f;
 char hostname[64], myhostname[64];

 if (!EnableClustering)
  return (1);
 is_local = 0;
 if (glue_strings(filename, sizeof filename, "/usr/local/var/spool/cron", ".cron.hostname", '/')) {
  if ((f = fopen(filename, "r"))) {

   if (
      (-1) 
          != get_string(hostname, 64, f, "\n") &&
       gethostname(myhostname, 64) == 0) {
    is_local = (strcmp(myhostname, hostname) == 0);
   } else {
    if ((DebugFlags & (0x0010)) != 0) printf ("cluster: hostname comparison error\n");
   }

   fclose(f);
  } else {
   if ((DebugFlags & (0x0010)) != 0) printf ("cluster: file %s not found\n", filename);
  }
 }

 return (is_local);
}
static void overwrite_database(cron_db * old_db, cron_db * new_db) {
 user *u, *nu;


 if ((DebugFlags & (0x0010)) != 0) printf ("unlinking old database:\n");
  for (u = old_db->head; u != 
                             ((void *)0)
                                 ; u = nu) {
  if ((DebugFlags & (0x0010)) != 0) printf ("\t%s\n", u->name);
   nu = u->next;
  unlink_user(old_db, u);
  free_user(u);
 }



 *old_db = *new_db;
}

int load_database(cron_db * old_db) {
 struct stat statbuf, syscron_stat, crond_stat;
 cron_db new_db;
 struct dirent *dp;
 DIR *dir;
 pid_t pid = getpid();
 int is_local = 0;
 time_t now;

 if ((DebugFlags & (0x0010)) != 0) printf ("[%ld] load_database()\n", (long) pid);

 now = time(
           ((void *)0)
               );





 if (stat("/usr/local/var/spool/cron", &statbuf) < 0) {
  log_it("CRON", pid, "STAT FAILED", "/usr/local/var/spool/cron", 
                                               (*__errno_location ())
                                                    );
  statbuf.
         st_mtim.tv_sec 
                  = 0;
 }
 else {
  max_mtime("/usr/local/var/spool/cron", &statbuf);
 }

 if (stat("/usr/local/etc/cron.d", &crond_stat) < 0) {
  log_it("CRON", pid, "STAT FAILED", "/usr/local/etc/cron.d", 
                                                   (*__errno_location ())
                                                        );
  crond_stat.
            st_mtim.tv_sec 
                     = 0;
 }
 else {
  max_mtime("/usr/local/etc/cron.d", &crond_stat);
 }




 if (stat("/usr/local/etc/crontab", &syscron_stat) < 0)
  syscron_stat.
              st_mtim.tv_sec 
                       = 0;
 if (old_db->mtime != 0
     && old_db->mtime == ((now - 1)<(((crond_stat.
                        st_mtim.tv_sec
                        )>(((statbuf.
                        st_mtim.tv_sec
                        )>(syscron_stat.
                        st_mtim.tv_sec
                        )?(statbuf.
                        st_mtim.tv_sec
                        ):(syscron_stat.
                        st_mtim.tv_sec
                        )))?(crond_stat.
                        st_mtim.tv_sec
                        ):(((statbuf.
                        st_mtim.tv_sec
                        )>(syscron_stat.
                        st_mtim.tv_sec
                        )?(statbuf.
                        st_mtim.tv_sec
                        ):(syscron_stat.
                        st_mtim.tv_sec
                        )))))?(now - 1):(((crond_stat.
                        st_mtim.tv_sec
                        )>(((statbuf.
                        st_mtim.tv_sec
                        )>(syscron_stat.
                        st_mtim.tv_sec
                        )?(statbuf.
                        st_mtim.tv_sec
                        ):(syscron_stat.
                        st_mtim.tv_sec
                        )))?(crond_stat.
                        st_mtim.tv_sec
                        ):(((statbuf.
                        st_mtim.tv_sec
                        )>(syscron_stat.
                        st_mtim.tv_sec
                        )?(statbuf.
                        st_mtim.tv_sec
                        ):(syscron_stat.
                        st_mtim.tv_sec
                        ))))))


  ) {
  if ((DebugFlags & (0x0010)) != 0) printf ("[%ld] spool dir mtime unch, no load needed.\n", (long) pid)
                ;
  return 0;
 }






 new_db.mtime = now - 1;
 new_db.head = new_db.tail = 
                            ((void *)0)
                                ;





 if (syscron_stat.
                 st_mtim.tv_sec
                         )
  process_crontab("root", 
                         ((void *)0)
                             , "/usr/local/etc/crontab", &new_db, old_db);


 if (!(dir = opendir("/usr/local/etc/cron.d"))) {
  log_it("CRON", pid, "OPENDIR FAILED", "/usr/local/etc/cron.d", 
                                                      (*__errno_location ())
                                                           );
 }
 else {
  while (
        ((void *)0) 
             != (dp = readdir(dir))) {
   char tabname[
               255 
                        + 1];

   if (not_a_crontab(dp))
    continue;

   if (!glue_strings(tabname, sizeof tabname, "/usr/local/etc/cron.d",
     dp->d_name, '/'))
    continue;

   process_crontab("root", 
                          ((void *)0)
                              , tabname, &new_db, old_db);
  }
  closedir(dir);
 }






 if (!(dir = opendir("/usr/local/var/spool/cron"))) {
  log_it("CRON", pid, "OPENDIR FAILED", "/usr/local/var/spool/cron", 
                                                  (*__errno_location ())
                                                       );
 }
 else {

  is_local = cluster_host_is_local();

  while (is_local && 
                    ((void *)0) 
                         != (dp = readdir(dir))) {
   char fname[
             255 
                      + 1], tabname[
                                    255 
                                             + 1];

   if (not_a_crontab(dp))
    continue;

   strncpy(fname, dp->d_name, 
                             255
                                     );
   fname[
        255
                ] = '\0';

   if (!glue_strings(tabname, sizeof tabname, "/usr/local/var/spool/cron", fname, '/'))
    continue;

   process_crontab(fname, fname, tabname, &new_db, old_db);
  }
  closedir(dir);
 }





 endpwent();

 overwrite_database(old_db, &new_db);
 if ((DebugFlags & (0x0010)) != 0) printf ("load_database is done\n");
 return 1;
}

void link_user(cron_db * db, user * u) {
 if (db->head == 
                ((void *)0)
                    )
  db->head = u;
 if (db->tail)
  db->tail->next = u;
 u->prev = db->tail;
 u->next = 
          ((void *)0)
              ;
 db->tail = u;
}

void unlink_user(cron_db * db, user * u) {
 if (u->prev == 
               ((void *)0)
                   )
  db->head = u->next;
 else
  u->prev->next = u->next;

 if (u->next == 
               ((void *)0)
                   )
  db->tail = u->prev;
 else
  u->next->prev = u->prev;
}

user *find_user(cron_db * db, const char *name, const char *tabname) {
 user *u;

 for (u = db->head; u != 
                        ((void *)0)
                            ; u = u->next)
  if ((strcmp(u->name, name) == 0)
   && ((tabname == 
                  ((void *)0)
                      )
    || (strcmp(tabname, u->tabname) == 0)
   )
   )
   break;
 return (u);
}

static int not_a_crontab(struct dirent * dp) {
 size_t len;






 if (dp->d_name[0] == '.')
  return (1);


 if (dp->d_name[0] == '#')
  return (1);


 if (0 == strcmp(dp->d_name, ".cron.hostname"))
  return(1);

 len = strlen(dp->d_name);

 if (len >= 
           255 
                    || len == 0)
  return (1);

 if (dp->d_name[len - 1] == '~')
  return (1);

 if ((len > 8) && (strncmp(dp->d_name + len - 8, ".rpmsave", 8) == 0))
  return (1);
 if ((len > 8) && (strncmp(dp->d_name + len - 8, ".rpmorig", 8) == 0))
  return (1);
 if ((len > 7) && (strncmp(dp->d_name + len - 7, ".rpmnew", 7) == 0))
  return (1);

 return (0);
}

static void max_mtime(const char *dir_name, struct stat *max_st) {
 DIR *dir;
 struct dirent *dp;
 struct stat st;

 if (!(dir = opendir(dir_name))) {
  max_st->
         st_mtim.tv_sec 
                  = 0;
  return;
 }

 while (
       ((void *)0) 
            != (dp = readdir(dir))) {
  char tabname[
              255 
                       + 1];

  if ( not_a_crontab ( dp ) && strcmp(dp->d_name, ".cron.hostname") != 0)
   continue;

  if (!glue_strings(tabname, sizeof tabname, dir_name, dp->d_name, '/'))
   continue;

  if (stat(tabname, &st) < 0)
   continue;

  if (st.
        st_mtim.tv_sec 
                 > max_st->
                           st_mtim.tv_sec
                                   )
   max_st->
          st_mtim.tv_sec 
                   = st.
                        st_mtim.tv_sec
                                ;
 }
 closedir(dir);
}
