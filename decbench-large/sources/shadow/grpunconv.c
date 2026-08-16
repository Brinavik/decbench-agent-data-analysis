
#ident "$Id$"









extern int nscd_flush_cache (const char *service);
extern int sssd_flush_cache (int dbflags);





















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
extern void log_set_progname(const char *);
extern const char *log_get_progname(void);
extern void log_set_logfd(FILE *fd);
extern FILE *log_get_logfd(void);



const char *Prog;

static 
      _Bool 
           gr_locked = 
                        0
                             ;
static 
      _Bool 
           sgr_locked = 
                        0
                             ;


static void fail_exit (int status);
static void usage (int status);
static void process_flags (int argc, char **argv);

static void fail_exit (int status)
{
 if (gr_locked) {
  if (gr_unlock () == 0) {
   fprintf (
           stderr
                 , gettext ("%s: failed to unlock %s\n"), Prog, gr_dbname ());
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
  , "failed to unlock %s", gr_dbname ()) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );

  }
 }

 if (sgr_locked) {
  if (sgr_unlock () == 0) {
   fprintf (
           stderr
                 , gettext ("%s: failed to unlock %s\n"), Prog, sgr_dbname ());
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
  , "failed to unlock %s", sgr_dbname ()) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );

  }
 }

 exit (status);
}

static void usage (int status)
{
 FILE *usageout = (
                  0 
                            != status) ? 
                                         stderr 
                                                : 
                                                  stdout
                                                        ;
 (void) fprintf (usageout,
                 gettext ("Usage: %s [options]\n" "\n" "Options:\n")

                                ,
                 Prog);
 (void) fputs (gettext ("  -h, --help                    display this help message and exit\n"), usageout);
 (void) fputs (gettext ("  -R, --root CHROOT_DIR         directory to chroot into\n"), usageout);
 (void) fputs ("\n", usageout);
 exit (status);
}






static void process_flags (int argc, char **argv)
{



 int c;
 static struct option long_options[] = {
  {"help", 
          0
                     , 
                             ((void *)0)
                                 , 'h'},
  {"root", 
          1
                           , 
                             ((void *)0)
                                 , 'R'},
  {
  ((void *)0)
      , 0, 
           ((void *)0)
               , '\0'}
 };

 while ((c = getopt_long (argc, argv, "hR:",
                          long_options, 
                                       ((void *)0)
                                           )) != -1) {
  switch (c) {
  case 'h':
   usage (
         0
                  );
                   break;
  case 'R':
   break;
  default:
   usage (2);
  }
 }

 if (optind != argc) {
  usage (2);
 }
}

int main (int argc, char **argv)
{
 const struct group *gr;
 struct group grent;
 const struct sgrp *sg;

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

 openlog("grpunconv", (
0x01
), 
(10<<3)
);

 process_flags (argc, argv);

 if (sgr_file_present () == 0) {
  exit (0);
 }

 if (gr_lock () == 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: cannot lock %s; try again later.\n"),
           Prog, gr_dbname ());
  fail_exit (5);
 }
 gr_locked = 
            1
                ;
 if (gr_open (
             0100 
                     | 
                       02
                             ) == 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: cannot open %s\n"), Prog, gr_dbname ());
  fail_exit (1);
 }

 if (sgr_lock () == 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: cannot lock %s; try again later.\n"),
           Prog, sgr_dbname ());
  fail_exit (5);
 }
 sgr_locked = 
             1
                 ;
 if (sgr_open (
              00
                      ) == 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: cannot open %s\n"), Prog, sgr_dbname ());
  fail_exit (1);
 }




 (void) gr_rewind ();
 while ((gr = gr_next ()) != 
                            ((void *)0)
                                ) {
  sg = sgr_locate (gr->gr_name);
  if ( (
         ((void *)0) 
              != sg)
      && (strcmp (gr->gr_passwd, "x") == 0)) {

   grent = *gr;
   grent.gr_passwd = sg->sg_passwd;
   if (gr_update (&grent) == 0) {
    fprintf (
            stderr
                  ,
             gettext ("%s: failed to prepare the new %s entry '%s'\n"),
             Prog, gr_dbname (), grent.gr_name);
    fail_exit (3);
   }
  }
 }

 (void) sgr_close ();

 if (gr_close () == 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: failure while writing changes to %s\n"),
           Prog, gr_dbname ());
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
 , "failure while writing changes to %s", gr_dbname ()) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );
  fail_exit (3);
 }

 if (unlink ("/etc/gshadow") != 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: cannot delete %s\n"),
           Prog, "/etc/gshadow");
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
 , "cannot delete %s", "/etc/gshadow") ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );
  fail_exit (3);
 }

 if (gr_unlock () == 0) {
  fprintf (
          stderr
                , gettext ("%s: failed to unlock %s\n"), Prog, gr_dbname ());
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
 , "failed to unlock %s", gr_dbname ()) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );

 }

 if (sgr_unlock () == 0) {
  fprintf (
          stderr
                , gettext ("%s: failed to unlock %s\n"), Prog, sgr_dbname ());
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
 , "failed to unlock %s", sgr_dbname ()) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );

 }

 nscd_flush_cache ("group");
 sssd_flush_cache (0x002);

 return 0;
}
