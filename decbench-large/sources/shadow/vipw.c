
#ident "$Id$"































struct sgrp {
 char *sg_name;
 char *sg_passwd;
 char **sg_adm;
 char **sg_mem;
};
                        struct sgrp *getsgent (void);
                        struct sgrp *getsgnam (const char *);
                        struct sgrp *sgetsgent (const char *);
                        struct sgrp *fgetsgent ( FILE *);
void setsgent (void);
void endsgent (void);
int putsgent (const struct sgrp *, FILE *);




extern int gr_close (void);
extern const struct group *gr_locate (const char *name);
extern const struct group *gr_locate_gid (gid_t gid);
extern int gr_lock (void);
extern int gr_setdbname (const char *filename);
extern const char *gr_dbname (void);
extern const struct group *gr_next (void);
extern int gr_open (int mode);
extern int gr_remove (const char *name);
extern int gr_rewind (void);
extern int gr_unlock (void);
extern int gr_update (const struct group *gr);
extern int gr_sort (void);







extern int nscd_flush_cache (const char *service);
extern int sssd_flush_cache (int dbflags);











struct commonio_entry {
           char *line;
           void *eptr;
                           struct commonio_entry *prev;
                       struct commonio_entry *next;
 
_Bool 
     changed:1;
};




struct commonio_ops {




                      void *(*dup) (const void *);




 void (*free) ( void *);





 const char *(*getname) (const void *);





 void *(*parse) (const char *);





 int (*put) (const void *, FILE *);





           char *(*fgets) ( char *s, int n, FILE *stream);
 int (*fputs) (const char *, FILE *);







           int (*open_hook) (void);
           int (*close_hook) (void);
};




struct commonio_db {



 char filename[1024];




               const struct commonio_ops *ops;




                           FILE *fp;







 mode_t st_mode;
 uid_t st_uid;
 gid_t st_gid;



                       struct commonio_entry *head;
                           struct commonio_entry *tail;
                           struct commonio_entry *cursor;




 
_Bool 
     changed:1;
 
_Bool 
     isopen:1;
 
_Bool 
     locked:1;
 
_Bool 
     readonly:1;
 
_Bool 
     setname:1;
};

extern int commonio_setname (struct commonio_db *, const char *);
extern 
      _Bool 
           commonio_present (const struct commonio_db *db);
extern int commonio_lock (struct commonio_db *);
extern int commonio_lock_nowait (struct commonio_db *, 
                                                      _Bool 
                                                           log);
extern int commonio_open (struct commonio_db *, int);
extern const void *commonio_locate (struct commonio_db *, const char *);
extern int commonio_update (struct commonio_db *, const void *);

extern int commonio_append (struct commonio_db *, const void *);

extern int commonio_remove (struct commonio_db *, const char *);
extern int commonio_rewind (struct commonio_db *);
extern const void *commonio_next (struct commonio_db *);
extern int commonio_close (struct commonio_db *);
extern int commonio_unlock (struct commonio_db *);
extern void commonio_del_entry (struct commonio_db *,
                                const struct commonio_entry *);
extern int commonio_sort_wrt (struct commonio_db *shadow,
                              const struct commonio_db *passwd);
extern int commonio_sort (struct commonio_db *db,
                          int (*cmp) (const void *, const void *));







extern void agecheck ( const struct spwd *);
extern int expire (const struct passwd *, const struct spwd *);

extern int isexpired (const struct passwd *, const struct spwd *);



extern int btrfs_create_subvolume(const char *path);
extern int btrfs_remove_subvolume(const char *path);
extern int btrfs_is_subvolume(const char *path);
extern int is_btrfs(const char *path);




extern const char *Basename (const char *str);


extern int chown_tree (const char *root,
                       uid_t old_uid, uid_t new_uid,
                       gid_t old_gid, gid_t new_gid);


extern void chown_tty (const struct passwd *);


typedef void (*cleanup_function) ( void *arg);
void add_cleanup ( cleanup_function pcf, void *arg);
void del_cleanup ( cleanup_function pcf);
void do_cleanups (void);


struct cleanup_info_mod {
 char *audit_msg;
 char *action;
               const char *name;
};
void cleanup_report_add_group (void *group_name);
void cleanup_report_add_group_group (void *group_name);

void cleanup_report_add_group_gshadow (void *group_name);

void cleanup_report_del_group (void *group_name);
void cleanup_report_del_group_group (void *group_name);

void cleanup_report_del_group_gshadow (void *group_name);

void cleanup_report_mod_passwd (void *cleanup_info);
void cleanup_report_mod_group (void *cleanup_info);
void cleanup_report_mod_gshadow (void *cleanup_info);
void cleanup_unlock_group ( void *__attribute__((unused)));

void cleanup_unlock_gshadow ( void *__attribute__((unused)));

void cleanup_unlock_passwd ( void *__attribute__((unused)));


extern 
      _Bool 
           console (const char *);


extern int copy_tree (const char *src_root, const char *dst_root,
                      
                     _Bool 
                          copy_root,
                      
                     _Bool 
                          reset_selinux,
                      uid_t old_uid, uid_t new_uid,
                      gid_t old_gid, gid_t new_gid);


extern void date_to_str (size_t size, char buf[size], long date);


extern char *pw_encrypt (const char *, const char *);


extern void pw_entry (const char *, struct passwd *);


extern void addenv (const char *, const char *);
extern void initenv (void);
extern void set_env (int, char *const *);
extern void sanitize_env (void);


extern void change_field (char *, size_t, const char *);
extern int valid_field (const char *, const char *);


extern int find_new_gid (
                        _Bool 
                             sys_group,
                         gid_t *gid,
                                   gid_t const *preferred_gid);


extern int find_new_uid (
                        _Bool 
                             sys_user,
                         uid_t *uid,
                                   uid_t const *preferred_uid);



extern int find_new_sub_gids (gid_t *range_start, unsigned long *range_count);


extern int find_new_sub_uids (uid_t *range_start, unsigned long *range_count);




extern int get_gid (const char *gidstr, gid_t *gid);


extern struct group *getgr_nam_gid ( const char *grname);


extern int getlong (const char *numstr, long int *result);


extern int get_pid (const char *pidstr, pid_t *pid);


extern int getrange (const char *range,
                     unsigned long *min, 
                                        _Bool 
                                             *has_min,
                     unsigned long *max, 
                                        _Bool 
                                             *has_max);


extern time_t gettime (void);


extern int get_uid (const char *uidstr, uid_t *uid);


extern int getulong (const char *numstr, unsigned long int *result);


extern char *fgetsx ( char *, int, FILE *);
extern int fputsx (const char *, FILE *);


extern void __gr_del_entry (const struct commonio_entry *ent);
extern const struct commonio_db *__gr_get_db (void);
extern struct commonio_entry *__gr_get_head (void);
extern void __gr_set_changed (void);


extern struct group *__gr_dup (const struct group *grent);
extern void gr_free_members (struct group *grent);
extern void gr_free ( struct group *grent);
extern 
      _Bool 
           gr_append_member (struct group *grp, char *member);


extern 
      _Bool 
           hushed (const char *username);
extern char **add_list ( char **, const char *);
extern char **del_list ( char **, const char *);
extern char **dup_list (char *const *);
extern 
      _Bool 
           is_on_list (char *const *list, const char *member);
extern char **comma_to_list (const char *);


extern void dolastlog (
 struct lastlog *ll,
 const struct passwd *pw,
             const char *line,
             const char *host);


extern int login_access (const char *user, const char *from);


extern void login_prompt (const char *, char *, int);


extern void mailcheck (void);


extern void motd (void);


extern struct passwd *get_my_pwent (void);


struct subid_range {
 unsigned long start;
 unsigned long count;
};



struct subordinate_range {
 const char *owner;
 unsigned long start;
 unsigned long count;
};

enum subid_type {
 ID_TYPE_UID = 1,
 ID_TYPE_GID = 2
};

enum subid_status {
 SUBID_STATUS_SUCCESS = 0,
 SUBID_STATUS_UNKNOWN_USER = 1,
 SUBID_STATUS_ERROR_CONN = 2,
 SUBID_STATUS_ERROR = 3,
};

_Bool 
    subid_init(const char *progname, FILE *logfd);
int subid_get_uid_ranges(const char *owner, struct subid_range **ranges);
int subid_get_gid_ranges(const char *owner, struct subid_range **ranges);
int subid_get_uid_owners(uid_t uid, uid_t **owner);
int subid_get_gid_owners(gid_t gid, uid_t **owner);

_Bool 
    subid_grant_uid_range(struct subordinate_range *range, 
                                                           _Bool 
                                                                reuse);

_Bool 
    subid_grant_gid_range(struct subordinate_range *range, 
                                                           _Bool 
                                                                reuse);

_Bool 
    subid_ungrant_uid_range(struct subordinate_range *range);

_Bool 
    subid_ungrant_gid_range(struct subordinate_range *range);
extern void nss_init(const char *nsswitch_path);
extern 
      _Bool 
           nss_is_initialized(void);

struct subid_nss_ops {
 enum subid_status (*has_range)(const char *owner, unsigned long start, unsigned long count, enum subid_type idtype, 
                                                                                                                    _Bool 
                                                                                                                         *result);
 enum subid_status (*list_owner_ranges)(const char *owner, enum subid_type id_type, struct subid_range **ranges, int *count);
 enum subid_status (*find_subid_owners)(unsigned long id, enum subid_type id_type, uid_t **uids, int *count);


 void *handle;
};

extern struct subid_nss_ops *get_subid_nss_handle(void);




extern int do_pam_passwd_non_interactive (const char *pam_service,
                                           const char *username,
                                           const char* password);
extern void do_pam_passwd (const char *user, 
                                            _Bool 
                                                 silent, 
                                                         _Bool 
                                                              change_expired);



extern 
      _Bool 
           isttytime (const char *, const char *, time_t);


extern const char* process_prefix_flag (const char* short_opt, int argc, char **argv);
extern struct group *prefix_getgrnam(const char *name);
extern struct group *prefix_getgrgid(gid_t gid);
extern struct passwd *prefix_getpwuid(uid_t uid);
extern struct passwd *prefix_getpwnam(const char* name);
extern struct spwd *prefix_getspnam(const char* name);
extern struct group *prefix_getgr_nam_gid(const char *grname);
extern void prefix_setpwent(void);
extern struct passwd* prefix_getpwent(void);
extern void prefix_endpwent(void);
extern void prefix_setgrent(void);
extern struct group* prefix_getgrent(void);
extern void prefix_endgrent(void);
extern void pwd_init (void);


extern void __pw_del_entry (const struct commonio_entry *ent);
extern struct commonio_db *__pw_get_db (void);
extern struct commonio_entry *__pw_get_head (void);


extern struct passwd *__pw_dup (const struct passwd *pwent);
extern void pw_free ( struct passwd *pwent);


extern int remove_tree (const char *root, 
                                         _Bool 
                                              remove_root);


extern int do_rlogin (const char *remote_host, char *name, size_t namelen,
                      char *term, size_t termlen);


extern void process_root_flag (const char* short_opt, int argc, char **argv);


extern const char *crypt_make_salt ( const char *meth, void *arg);
extern int setup_groups (const struct passwd *info);
extern int change_uid (const struct passwd *info);



extern int setup_uid_gid (const struct passwd *info);



extern void setup (struct passwd *);


extern void setup_env (struct passwd *);


extern struct group *sgetgrent (const char *buf);


extern struct passwd *sgetpwent (const char *buf);







extern void __sgr_del_entry (const struct commonio_entry *ent);
extern struct sgrp *__sgr_dup (const struct sgrp *sgent);
extern void sgr_free ( struct sgrp *sgent);
extern struct commonio_entry *__sgr_get_head (void);
extern void __sgr_set_changed (void);


extern struct commonio_entry *__spw_get_head (void);
extern void __spw_del_entry (const struct commonio_entry *ent);


extern struct spwd *__spw_dup (const struct spwd *spent);
extern void spw_free ( struct spwd *spent);


extern int shell (const char *file, const char *arg, char *const envp[]);


extern int run_command (const char *cmd, const char *argv[],
                                  const char *envp[], int *status);


extern long strtoday (const char *);


extern int check_su_auth (const char *actual_id,
                          const char *wanted_id,
                          
                         _Bool 
                              su_to_root);


extern void sulog (const char *tty,
                   
                  _Bool 
                       success,
                   const char *oldname,
                   const char *name);


extern void subsystem (const struct passwd *);


extern void ttytype (const char *);







extern int set_filesize_limit (int blocks);


extern int user_busy (const char *name, uid_t uid);



extern struct utmp *get_current_utmp (void);
extern struct utmp *prepare_utmp (const char *name,
                                  const char *line,
                                  const char *host,
                                            const struct utmp *ut);
extern int setutmp (struct utmp *ut);
extern 
      _Bool 
           valid (const char *, const struct passwd *);


extern void *xmalloc (size_t size)
                                              ;
extern char *xstrdup (const char *);


extern struct passwd *xgetpwnam (const char *);

extern struct passwd *xgetpwuid (uid_t);

extern struct group *xgetgrnam (const char *);

extern struct group *xgetgrgid (gid_t);

extern struct spwd *xgetspnam(const char *);


extern 
      _Bool 
           yes_or_no (
                      _Bool 
                           read_only);
extern int pw_close (void);
extern const struct passwd *pw_locate (const char *name);
extern const struct passwd *pw_locate_uid (uid_t uid);
extern int pw_lock (void);
extern int pw_setdbname (const char *filename);
extern const char *pw_dbname (void);
extern const struct passwd *pw_next (void);
extern int pw_open (int mode);
extern int pw_remove (const char *name);
extern int pw_rewind (void);
extern int pw_unlock (void);
extern int pw_update (const struct passwd *pw);
extern int pw_sort (void);
extern int sgr_close (void);
extern 
      _Bool 
           sgr_file_present (void);
extern const struct sgrp *sgr_locate (const char *name);
extern int sgr_lock (void);
extern int sgr_setdbname (const char *filename);
extern const char *sgr_dbname (void);
extern const struct sgrp *sgr_next (void);
extern int sgr_open (int mode);
extern int sgr_remove (const char *name);
extern int sgr_rewind (void);
extern int sgr_unlock (void);
extern int sgr_update (const struct sgrp *sg);
extern int sgr_sort (void);
extern int spw_close (void);
extern 
      _Bool 
           spw_file_present (void);
extern const struct spwd *spw_locate (const char *name);
extern int spw_lock (void);
extern int spw_setdbname (const char *filename);
extern const char *spw_dbname (void);
extern const struct spwd *spw_next (void);
extern int spw_open (int mode);
extern int spw_remove (const char *name);
extern int spw_rewind (void);
extern int spw_unlock (void);
extern int spw_update (const struct spwd *sp);
extern int spw_sort (void);





extern void log_set_progname(const char *);
extern const char *log_get_progname(void);
extern void log_set_logfd(FILE *fd);
extern FILE *log_get_logfd(void);
const char *Prog;

static const char *filename, *fileeditname;
static 
      _Bool 
           filelocked = 
                        0
                             ;
static 
      _Bool 
           createedit = 
                        0
                             ;
static int (*unlock) (void);
static 
      _Bool 
           quiet = 
                   0
                        ;







static void usage (int status);
static int create_backup_file (FILE *, const char *, struct stat *);
static void vipwexit (const char *msg, int syserr, int ret);
static void vipwedit (const char *, int (*)(void), int (*)(void));




static void usage (int status)
{
 FILE *usageout = (
                  0 
                            != status) ? 
                                         stderr 
                                                : 
                                                  stdout
                                                        ;
 (void) fprintf (
                stderr
                      ,
                 gettext ("Usage: %s [options]\n" "\n" "Options:\n")

                                ,
                 Prog);
 (void) fputs (gettext ("  -g, --group                   edit group database\n"), usageout);
 (void) fputs (gettext ("  -h, --help                    display this help message and exit\n"), usageout);
 (void) fputs (gettext ("  -p, --passwd                  edit passwd database\n"), usageout);
 (void) fputs (gettext ("  -q, --quiet                   quiet mode\n"), usageout);
 (void) fputs (gettext ("  -R, --root CHROOT_DIR         directory to chroot into\n"), usageout);
 (void) fputs (gettext ("  -s, --shadow                  edit shadow or gshadow database\n"), usageout);



 (void) fputs (gettext ("\n"), usageout);
 exit (status);
}




static int create_backup_file (FILE * fp, const char *backup, struct stat *sb)
{
 struct utimbuf ub;
 FILE *bkfp;
 int c;
 mode_t mask;

 mask = umask (077);
 bkfp = fopen (backup, "w");
 (void) umask (mask);
 if (
    ((void *)0) 
         == bkfp) {
  return -1;
 }

 c = 0;
 if (fseeko (fp, 0, 
                   0
                           ) == 0)
  while ((c = getc (fp)) != 
                           (-1)
                              ) {
   if (putc (c, bkfp) == 
                        (-1)
                           ) {
    break;
   }
  }
 if ((
     (-1) 
         != c) || (ferror (fp) != 0) || (fflush (bkfp) != 0)) {
  fclose (bkfp);
  unlink (backup);
  return -1;
 }
 if (fsync (fileno (bkfp)) != 0) {
  (void) fclose (bkfp);
  unlink (backup);
  return -1;
 }
 if (fclose (bkfp) != 0) {
  unlink (backup);
  return -1;
 }

 ub.actime = sb->
                st_atim.tv_sec
                        ;
 ub.modtime = sb->
                 st_mtim.tv_sec
                         ;
 if ( (utime (backup, &ub) != 0)
     || (chmod (backup, sb->st_mode) != 0)
     || (chown (backup, sb->st_uid, sb->st_gid) != 0)) {
  unlink (backup);
  return -1;
 }
 return 0;
}




static void vipwexit (const char *msg, int syserr, int ret)
{
 int err = 
          (*__errno_location ())
               ;

 if (createedit) {
  if (unlink (fileeditname) != 0) {
   fprintf (
           stderr
                 , gettext ("%s: failed to remove %s\n"), Prog, fileeditname);

  }
 }
 if (filelocked) {
  if ((*unlock) () == 0) {
   fprintf (
           stderr
                 , gettext ("%s: failed to unlock %s\n"), Prog, fileeditname);
   do { char *old_locale = setlocale (
  6
  , 
  ((void *)0)
  ); char *saved_locale = 
  ((void *)0)
  ; if (
  ((void *)0) 
  != old_locale) { saved_locale = strdup (old_locale); } if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , "C"); } syslog (
  3
  , "failed to unlock %s", fileeditname) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );

  }
 }
 if (
    ((void *)0) 
         != msg) {
  fprintf (
          stderr
                , "%s: %s", Prog, msg);
 }
 if (0 != syserr) {
  fprintf (
          stderr
                , ": %s", strerror (err));
 }
 if ( (
        ((void *)0) 
             != msg)
     || (0 != syserr)) {
  (void) fputs ("\n", 
                     stderr
                           );
 }
 if (!quiet) {
  fprintf (
          stdout
                , gettext ("%s: %s is unchanged\n"), Prog,
    filename);
 }
 exit (ret);
}
static void
vipwedit (const char *file, int (*file_lock) (void), int (*file_unlock) (void))
{
 const char *editor;
 pid_t pid;
 struct stat st1, st2;
 int status;
 FILE *f;
 pid_t orig_pgrp, editor_pgrp = -1;
 sigset_t mask, omask;

 char filebackup[1024], fileedit[1024];
 char *to_rename;

 snprintf (filebackup, sizeof filebackup, "%s-", file);
  snprintf (fileedit, sizeof fileedit, "%s.edit", file);



 unlock = file_unlock;
 filename = file;
 fileeditname = fileedit;

 if (access (file, 
                  0
                      ) != 0) {
  vipwexit (file, 1, 1);
 }
 if (file_lock () == 0) {
  vipwexit (gettext ("Couldn't lock file"), 
                                    (*__errno_location ())
                                         , 5);
 }
 filelocked = 
             1
                 ;







 if (stat (file, &st1) != 0) {
  vipwexit (file, 1, 1);
 }
 f = fopen (file, "r");
 if (
    ((void *)0) 
         == f) {
  vipwexit (file, 1, 1);
 }




 if (create_backup_file (f, fileedit, &st1) != 0) {
  vipwexit (gettext ("Couldn't make backup"), 
                                      (*__errno_location ())
                                           , 1);
 }
 (void) fclose (f);
 createedit = 
             1
                 ;

 editor = getenv ("VISUAL");
 if (
    ((void *)0) 
         == editor) {
  editor = getenv ("EDITOR");
 }
 if (
    ((void *)0) 
         == editor) {
  editor = "vi";
 }

 orig_pgrp = tcgetpgrp(
                      0
                                  );

 pid = fork ();
 if (-1 == pid) {
  vipwexit ("fork", 1, 1);
 } else if (0 == pid) {


  char *buf;


  if (orig_pgrp != -1) {
   pid = getpid();
   setpgid(0, 0);
   while (tcgetpgrp(
                   0
                               ) != pid)
    continue;
  }

  buf = (char *) malloc (strlen (editor) + strlen (fileedit) + 2);
  snprintf (buf, strlen (editor) + strlen (fileedit) + 2,
            "%s %s", editor, fileedit);
  status = system (buf);
  if (-1 == status) {
   fprintf (
           stderr
                 , gettext ("%s: %s: %s\n"), Prog, editor,
            strerror (
                     (*__errno_location ())
                          ));
   exit (1);
  } else if ( 
               (((
               status
               ) & 0x7f) == 0)
             
            && (
                (((
                status
                ) & 0xff00) >> 8) 
                                     != 0)) {
   fprintf (
           stderr
                 , gettext ("%s: %s returned with status %d\n"),
            Prog, editor, 
                         (((
                         status
                         ) & 0xff00) >> 8)
                                             );
   exit (
        (((
        status
        ) & 0xff00) >> 8)
                            );
  } else if (
            (((signed char) (((
            status
            ) & 0x7f) + 1) >> 1) > 0)
                                ) {
   fprintf (
           stderr
                 , gettext ("%s: %s killed by signal %d\n"),
            Prog, editor, 
                         ((
                         status
                         ) & 0x7f)
                                          );
   exit (1);
  } else {
   exit (0);
  }
 }


 if (orig_pgrp != -1) {
  setpgid(pid, pid);
  tcsetpgrp(
           0
                       , pid);


  sigemptyset(&mask);
  sigaddset(&mask, 
                  22
                         );
  sigprocmask(
             0
                      , &mask, &omask);
 }


 signal(
       17
              , 
                ((__sighandler_t) 0)
                       );

 for (;;) {
  pid = waitpid (pid, &status, 
                              2
                                       );
  if ((pid != -1) && (
                     (((
                     status
                     ) & 0xff) == 0x7f) 
                                         != 0)) {


   if (orig_pgrp != -1) {
    editor_pgrp = tcgetpgrp(
                           0
                                       );
    if (editor_pgrp == -1) {
     fprintf (
             stderr
                   , "%s: %s: %s", Prog,
       "tcgetpgrp", strerror (
                             (*__errno_location ())
                                  ));
    }
    if (tcsetpgrp(
                 0
                             , orig_pgrp) == -1) {
     fprintf (
             stderr
                   , "%s: %s: %s", Prog,
       "tcsetpgrp", strerror (
                             (*__errno_location ())
                                  ));
    }
   }
   kill (getpid (), 
                   19
                          );

   if (editor_pgrp != -1) {
    if (tcsetpgrp(
                 0
                             , editor_pgrp) == -1) {
     fprintf (
             stderr
                   , "%s: %s: %s", Prog,
       "tcsetpgrp", strerror (
                             (*__errno_location ())
                                  ));
    }
   }
   killpg (pid, 
               18
                      );
  } else {
   break;
  }
 }

 if (orig_pgrp != -1)
  sigprocmask(
             2
                        , &omask, 
                                  ((void *)0)
                                      );

 if (-1 == pid) {
  vipwexit (editor, 1, 1);
 } else if ( 
              (((
              status
              ) & 0x7f) == 0)
            
           && (
               (((
               status
               ) & 0xff00) >> 8) 
                                    != 0)) {
  vipwexit (
           ((void *)0)
               , 0, 
                    (((
                    status
                    ) & 0xff00) >> 8)
                                        );
 } else if (
           (((signed char) (((
           status
           ) & 0x7f) + 1) >> 1) > 0)
                               ) {
  fprintf (
          stderr
                , gettext ("%s: %s killed by signal %d\n"),
           Prog, editor, 
                        ((
                        status
                        ) & 0x7f)
                                        );
  vipwexit (
           ((void *)0)
               , 0, 1);
 }

 if (stat (fileedit, &st2) != 0) {
  vipwexit (fileedit, 1, 1);
 }
 if (st1.
        st_mtim.tv_sec 
                 == st2.
                        st_mtim.tv_sec
                                ) {
  vipwexit (0, 0, 0);
 }
 createedit = 
             0
                  ;
  to_rename = fileedit;



 unlink (filebackup);
 link (file, filebackup);
 if (rename (to_rename, file) == -1) {
  fprintf (
          stderr
                ,
           gettext ("%s: can't restore %s: %s (your changes are in %s)\n"),
           Prog, file, strerror (
                                (*__errno_location ())
                                     ), to_rename);





  vipwexit (0, 0, 1);
 }
 if ((*file_unlock) () == 0) {
  fprintf (
          stderr
                , gettext ("%s: failed to unlock %s\n"), Prog, fileeditname);
  do { char *old_locale = setlocale (
 6
 , 
 ((void *)0)
 ); char *saved_locale = 
 ((void *)0)
 ; if (
 ((void *)0) 
 != old_locale) { saved_locale = strdup (old_locale); } if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , "C"); } syslog (
 3
 , "failed to unlock %s", fileeditname) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );

 }
 do { char *old_locale = setlocale (
6
, 
((void *)0)
); char *saved_locale = 
((void *)0)
; if (
((void *)0) 
!= old_locale) { saved_locale = strdup (old_locale); } if (
((void *)0) 
!= saved_locale) { (void) setlocale (
6
, "C"); } syslog (
6
, "file %s edited", fileeditname) ; if (
((void *)0) 
!= saved_locale) { (void) setlocale (
6
, saved_locale); free (saved_locale); } } while (
0
);
}

int main (int argc, char **argv)
{
 
_Bool 
     editshadow = 
                  0
                       ;
 
_Bool 
     do_vipw;

 Prog = Basename (argv[0]);
 log_set_progname(Prog);
 log_set_logfd(
              stderr
                    );

 (void) setlocale (
                  6
                        , "");
 (void) bindtextdomain ("shadow", "/usr/share/locale");
 (void) textdomain ("shadow");

 process_root_flag ("-R", argc, argv);

 do_vipw = (strcmp (Prog, "vigr") != 0);

 openlog(do_vipw ? "vipw" : "vigr", (
0x01
), 
(10<<3)
);

 {



  int c;
  static struct option long_options[] = {
   {"group", 
             0
                        , 
                                ((void *)0)
                                    , 'g'},
   {"help", 
             0
                        , 
                                ((void *)0)
                                    , 'h'},
   {"passwd", 
             0
                        , 
                                ((void *)0)
                                    , 'p'},
   {"quiet", 
             0
                        , 
                                ((void *)0)
                                    , 'q'},
   {"root", 
             1
                              , 
                                ((void *)0)
                                    , 'R'},
   {"shadow", 
             0
                        , 
                                ((void *)0)
                                    , 's'},



   {
   ((void *)0)
       , 0, 
            ((void *)0)
                , '\0'}
  };
  while ((c = getopt_long (argc, argv,



                           "ghpqR:s",

                           long_options, 
                                        ((void *)0)
                                            )) != -1) {
   switch (c) {
   case 'g':
    do_vipw = 
             0
                  ;
    break;
   case 'h':
    usage (
          0
                   );
    break;
   case 'p':
    do_vipw = 
             1
                 ;
    break;
   case 'q':
    quiet = 
           1
               ;
    break;
   case 'R':
    break;
   case 's':
    editshadow = 
                1
                    ;
    break;





   default:
    usage (2);
   }
  }

  if (optind != argc) {
   usage (2);
  }
 }

 if (do_vipw) {
  if (editshadow) {
   vipwedit (spw_dbname (), spw_lock, spw_unlock);
   printf (gettext ("You have modified %s.\n" "You may need to modify %s for consistency.\n" "Please use the command '%s' to do so.\n"),
           spw_dbname (),
           pw_dbname (),
           "vipw");
  } else {
   vipwedit (pw_dbname (), pw_lock, pw_unlock);
   if (spw_file_present ()) {
    printf (gettext ("You have modified %s.\n" "You may need to modify %s for consistency.\n" "Please use the command '%s' to do so.\n"),
            pw_dbname (),
            spw_dbname (),
            "vipw -s");
   }
  }
 } else {

  if (editshadow) {
   vipwedit (sgr_dbname (), sgr_lock, sgr_unlock);
   printf (gettext ("You have modified %s.\n" "You may need to modify %s for consistency.\n" "Please use the command '%s' to do so.\n"),
           sgr_dbname (),
           gr_dbname (),
           "vigr");
  } else {

   vipwedit (gr_dbname (), gr_lock, gr_unlock);

   if (sgr_file_present ()) {
    printf (gettext ("You have modified %s.\n" "You may need to modify %s for consistency.\n" "Please use the command '%s' to do so.\n"),
            gr_dbname (),
            sgr_dbname (),
            "vigr -s");
   }
  }

 }

 nscd_flush_cache ("passwd");
 nscd_flush_cache ("group");
 sssd_flush_cache (0x001 | 0x002);

 return 
       0
                ;
}
