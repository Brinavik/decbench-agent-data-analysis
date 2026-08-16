
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
extern 
      _Bool 
           getdef_bool (const char *);
extern long getdef_long (const char *, long);
extern int getdef_num (const char *, int);
extern unsigned long getdef_ulong (const char *, unsigned long);
extern unsigned int getdef_unum (const char *, unsigned int);
extern const char *getdef_str (const char *);
extern int putdef_str (const char *, const char *);
extern void setdef_config_file (const char* file);
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














extern int sub_uid_close(void);
extern 
      _Bool 
           have_sub_uids(const char *owner, uid_t start, unsigned long count);
extern 
      _Bool 
           sub_uid_file_present (void);
extern 
      _Bool 
           local_sub_uid_assigned(const char *owner);
extern int sub_uid_lock (void);
extern int sub_uid_setdbname (const char *filename);
extern const char *sub_uid_dbname (void);
extern int sub_uid_open (int mode);
extern int sub_uid_unlock (void);
extern int sub_uid_add (const char *owner, uid_t start, unsigned long count);
extern int sub_uid_remove (const char *owner, uid_t start, unsigned long count);
extern uid_t sub_uid_find_free_range(uid_t min, uid_t max, unsigned long count);
extern int list_owner_ranges(const char *owner, enum subid_type id_type, struct subid_range **ranges);
extern 
      _Bool 
           new_subid_range(struct subordinate_range *range, enum subid_type id_type, 
                                                                                     _Bool 
                                                                                          reuse);
extern 
      _Bool 
           release_subid_range(struct subordinate_range *range, enum subid_type id_type);
extern int find_subid_owners(unsigned long id, enum subid_type id_type, uid_t **uids);
extern void free_subordinate_ranges(struct subordinate_range **ranges, int count);

extern int sub_gid_close(void);
extern 
      _Bool 
           have_sub_gids(const char *owner, gid_t start, unsigned long count);
extern 
      _Bool 
           sub_gid_file_present (void);
extern 
      _Bool 
           local_sub_gid_assigned(const char *owner);
extern int sub_gid_lock (void);
extern int sub_gid_setdbname (const char *filename);
extern const char *sub_gid_dbname (void);
extern int sub_gid_open (int mode);
extern int sub_gid_unlock (void);
extern int sub_gid_add (const char *owner, gid_t start, unsigned long count);
extern int sub_gid_remove (const char *owner, gid_t start, unsigned long count);
extern uid_t sub_gid_find_free_range(gid_t min, gid_t max, unsigned long count);

extern 
      _Bool 
           is_valid_user_name (const char *name);
extern 
      _Bool 
           is_valid_group_name (const char *name);
extern void log_set_progname(const char *);
extern const char *log_get_progname(void);
extern void log_set_logfd(FILE *fd);
extern FILE *log_get_logfd(void);




const char *Prog;

static 
      _Bool 
           rflg = 
                  0
                       ;
static 
      _Bool 
           is_shadow;

static 
      _Bool 
           is_shadow_grp;
static 
      _Bool 
           sgr_locked = 
                        0
                             ;

static 
      _Bool 
           pw_locked = 
                       0
                            ;
static 
      _Bool 
           gr_locked = 
                       0
                            ;
static 
      _Bool 
           spw_locked = 
                        0
                             ;

static 
      _Bool 
           is_sub_uid = 
                        0
                             ;
static 
      _Bool 
           is_sub_gid = 
                        0
                             ;
static 
      _Bool 
           sub_uid_locked = 
                            0
                                 ;
static 
      _Bool 
           sub_gid_locked = 
                            0
                                 ;



static void usage (int status);
static void fail_exit (int);
static int add_group (const char *, const char *, gid_t *, gid_t);
static int get_user_id (const char *, uid_t *);
static int add_user (const char *, uid_t, gid_t);



static int add_passwd (struct passwd *, const char *);
static void process_flags (int argc, char **argv);
static void check_flags (void);
static void check_perms (void);
static void open_files (void);
static void close_files (void);

extern int allow_bad_names;




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
 (void) fputs (gettext ("  -b, --badname                 allow bad names\n"), usageout);
 (void) fputs (gettext ("  -h, --help                    display this help message and exit\n"), usageout);
 (void) fputs (gettext ("  -r, --system                  create system accounts\n"), usageout);
 (void) fputs (gettext ("  -R, --root CHROOT_DIR         directory to chroot into\n"), usageout);







 (void) fputs ("\n", usageout);

 exit (status);
}




static void fail_exit (int code)
{
 if (spw_locked) {
  if (spw_unlock () == 0) {
   fprintf (
           stderr
                 , gettext ("%s: failed to unlock %s\n"), Prog, spw_dbname ());
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
  , "failed to unlock %s", spw_dbname ()) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );

  }
 }
 if (pw_locked) {
  if (pw_unlock () == 0) {
   fprintf (
           stderr
                 , gettext ("%s: failed to unlock %s\n"), Prog, pw_dbname ());
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
  , "failed to unlock %s", pw_dbname ()) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );

  }
 }
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


 if (sub_uid_locked) {
  if (sub_uid_unlock () == 0) {
   fprintf (
           stderr
                 , gettext ("%s: failed to unlock %s\n"), Prog, sub_uid_dbname ());
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
  , "failed to unlock %s", sub_uid_dbname ()) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );

  }
 }
 if (sub_gid_locked) {
  if (sub_gid_unlock () == 0) {
   fprintf (
           stderr
                 , gettext ("%s: failed to unlock %s\n"), Prog, sub_gid_dbname ());
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
  , "failed to unlock %s", sub_gid_dbname ()) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );

  }
 }


 exit (code);
}




static int add_group (const char *name, const char *gid, gid_t *ngid, uid_t uid)
{
 const struct group *grp;
 struct group grent;
 char *members[1];

 const struct sgrp *sg;






 grp = getgrnam (gid);
 if (
    ((void *)0) 
         == grp) {
  grp = gr_locate (gid);
 }
 if (
    ((void *)0) 
         != grp) {

  *ngid = grp->gr_gid;

  return 0;
 }

 if (
    ((*__ctype_b_loc ())[(int) ((
    gid[0]
    ))] & (unsigned short int) _ISdigit)
                    ) {





  if (get_gid (gid, &grent.gr_gid) == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: invalid group ID '%s'\n"),
            Prog, gid);
   return -1;
  }




  if ( (getgrgid ((gid_t) grent.gr_gid) != 
                                            ((void *)0)
                                                )
      || (gr_locate_gid ((gid_t) grent.gr_gid) != 
                                                 ((void *)0)
                                                     )) {


   *ngid = (gid_t) grent.gr_gid;
   return 0;
  }


  if (grent.gr_gid == (gid_t)-1) {
   fprintf (
           stderr
                 ,
            gettext ("%s: invalid group ID '%s'\n"),
            Prog, gid);
   return -1;
  }
 } else {




  if (find_new_gid(rflg, &grent.gr_gid, &uid) < 0) {
   return -1;
  }
 }




 if (('\0' != gid[0]) && (!
                          ((*__ctype_b_loc ())[(int) ((
                          gid[0]
                          ))] & (unsigned short int) _ISdigit)
                                          )) {
  grent.gr_name = xstrdup (gid);
 } else {
  grent.gr_name = xstrdup (name);

 }


 if (!is_valid_group_name (grent.gr_name)) {
  fprintf (
          stderr
                ,
           gettext ("%s: invalid group name '%s'\n"),
           Prog, grent.gr_name);
  free (grent.gr_name);
  return -1;
 }

 grent.gr_passwd = "*";
 members[0] = 
             ((void *)0)
                 ;
 grent.gr_mem = members;

 *ngid = grent.gr_gid;


 if (is_shadow_grp) {
  sg = sgr_locate (grent.gr_name);

  if (
     ((void *)0) 
          != sg) {
   fprintf (
           stderr
                 ,
            gettext ("%s: group '%s' is a shadow group, but does not exist in /etc/group\n"),
            Prog, grent.gr_name);
   return -1;
  }
 }



 if (is_shadow_grp) {
  struct sgrp sgrent;
  char *admins[1];
  sgrent.sg_name = grent.gr_name;
  sgrent.sg_passwd = "*";
  grent.gr_passwd = "x";
  admins[0] = 
             ((void *)0)
                 ;
  sgrent.sg_adm = admins;
  sgrent.sg_mem = members;

  if (sgr_update (&sgrent) == 0) {
   return -1;
  }
 }


 if (gr_update (&grent) == 0) {
  return -1;
 }

 return 0;
}

static int get_user_id (const char *uid, uid_t *nuid) {





 if (
    ((*__ctype_b_loc ())[(int) ((
    uid[0]
    ))] & (unsigned short int) _ISdigit)
                    ) {
  if ((get_uid (uid, nuid) == 0) || (*nuid == (uid_t)-1)) {
   fprintf (
           stderr
                 ,
            gettext ("%s: invalid user ID '%s'\n"),
            Prog, uid);
   return -1;
  }
 } else {
  if ('\0' != uid[0]) {
   const struct passwd *pwd;

   pwd = getpwnam (uid);
   if (
      ((void *)0) 
           == pwd) {
    pwd = pw_locate (uid);
   }

   if (
      ((void *)0) 
           != pwd) {
    *nuid = pwd->pw_uid;
   } else {
    fprintf (
            stderr
                  ,
             gettext ("%s: user '%s' does not exist\n"),
             Prog, uid);
    return -1;
   }
  } else {
   if (find_new_uid (rflg, nuid, 
                                ((void *)0)
                                    ) < 0) {
    return -1;
   }
  }
 }

 return 0;
}




static int add_user (const char *name, uid_t uid, gid_t gid)
{
 struct passwd pwent;


 if (!is_valid_user_name (name)) {
  fprintf (
          stderr
                ,
           gettext ("%s: invalid user name '%s': use --badname to ignore\n"),
           Prog, name);
  return -1;
 }






 pwent.pw_name = xstrdup (name);
 pwent.pw_uid = uid;
 pwent.pw_passwd = "x";
 pwent.pw_gid = gid;
 pwent.pw_gecos = "";
 pwent.pw_dir = "";
 pwent.pw_shell = "";

 return (pw_update (&pwent) == 0) ? -1 : 0;
}
static int add_passwd (struct passwd *pwd, const char *password)
{
 const struct spwd *sp;
 struct spwd spent;
 sp = spw_locate (pwd->pw_name);
 if ( (
        ((void *)0) 
             != sp)
     || (strcmp (pwd->pw_passwd, "x") != 0)) {
  return 0;
 }






 spent.sp_namp = pwd->pw_name;
 spent.sp_pwdp = "!";

 spent.sp_lstchg = (long) gettime () / (24L*3600L);
 if (0 == spent.sp_lstchg) {

  spent.sp_lstchg = -1;
 }
 spent.sp_min = getdef_num ("PASS_MIN_DAYS", 0);

 spent.sp_max = getdef_num ("PASS_MAX_DAYS", 10000);
 spent.sp_warn = getdef_num ("PASS_WARN_AGE", -1);
 spent.sp_inact = -1;
 spent.sp_expire = -1;
 spent.sp_flag = ((unsigned long int)-1);

 return (spw_update (&spent) == 0);
}






static void process_flags (int argc, char **argv)
{
 int c;





 static struct option long_options[] = {
  {"badname", 
                  0
                             , 
                                     ((void *)0)
                                         , 'b'},



  {"help", 
                  0
                             , 
                                     ((void *)0)
                                         , 'h'},
  {"system", 
                  0
                             , 
                                     ((void *)0)
                                         , 'r'},
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

 while ((c = getopt_long (argc, argv,







                          "bhr",

                          long_options, 
                                       ((void *)0)
                                           )) != -1) {
  switch (c) {
  case 'b':
   allow_bad_names = 
                    1
                        ;
   break;





  case 'h':
   usage (
         0
                     );
   break;
  case 'r':
   rflg = 
         1
             ;
   break;
  case 'R':
   break;
  default:
   usage (
         1
                     );
   break;
  }
 }

 if ( (optind != argc)
     && (optind + 1 != argc)) {
  usage (
        1
                    );
 }

 if (argv[optind] != 
                    ((void *)0)
                        ) {
  if (freopen (argv[optind], "r", 
                                 stdin
                                      ) == 
                                           ((void *)0)
                                               ) {
   char buf[
           8192
                 ];
   snprintf (buf, sizeof buf, "%s: %s", Prog, argv[1]);
   perror (buf);
   fail_exit (
             1
                         );
  }
 }


 check_flags ();
}






static void check_flags (void)
{
}
static void check_perms (void)
{
}




static void open_files (void)
{






 if (pw_lock () == 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: cannot lock %s; try again later.\n"),
           Prog, pw_dbname ());
  fail_exit (
            1
                        );
 }
 pw_locked = 
            1
                ;
 if (is_shadow) {
  if (spw_lock () == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: cannot lock %s; try again later.\n"),
            Prog, spw_dbname ());
   fail_exit (
             1
                         );
  }
  spw_locked = 
              1
                  ;
 }
 if (gr_lock () == 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: cannot lock %s; try again later.\n"),
           Prog, gr_dbname ());
  fail_exit (
            1
                        );
 }
 gr_locked = 
            1
                ;

 if (is_shadow_grp) {
  if (sgr_lock () == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: cannot lock %s; try again later.\n"),
            Prog, sgr_dbname ());
   fail_exit (
             1
                         );
  }
  sgr_locked = 
              1
                  ;
 }


 if (is_sub_uid) {
  if (sub_uid_lock () == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: cannot lock %s; try again later.\n"),
            Prog, sub_uid_dbname ());
   fail_exit (
             1
                         );
  }
  sub_uid_locked = 
                  1
                      ;
 }
 if (is_sub_gid) {
  if (sub_gid_lock () == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: cannot lock %s; try again later.\n"),
            Prog, sub_gid_dbname ());
   fail_exit (
             1
                         );
  }
  sub_gid_locked = 
                  1
                      ;
 }


 if (pw_open (
             0100 
                     | 
                       02
                             ) == 0) {
  fprintf (
          stderr
                , gettext ("%s: cannot open %s\n"), Prog, pw_dbname ());
  fail_exit (
            1
                        );
 }
 if (is_shadow && (spw_open (
                            0100 
                                    | 
                                      02
                                            ) == 0)) {
  fprintf (
          stderr
                , gettext ("%s: cannot open %s\n"), Prog, spw_dbname ());
  fail_exit (
            1
                        );
 }
 if (gr_open (
             0100 
                     | 
                       02
                             ) == 0) {
  fprintf (
          stderr
                , gettext ("%s: cannot open %s\n"), Prog, gr_dbname ());
  fail_exit (
            1
                        );
 }

 if (is_shadow_grp && (sgr_open (
                                0100 
                                        | 
                                          02
                                                ) == 0)) {
  fprintf (
          stderr
                , gettext ("%s: cannot open %s\n"), Prog, sgr_dbname ());
  fail_exit (
            1
                        );
 }


 if (is_sub_uid) {
  if (sub_uid_open (
                   0100 
                           | 
                             02
                                   ) == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: cannot open %s\n"),
            Prog, sub_uid_dbname ());
   fail_exit (
             1
                         );
  }
 }
 if (is_sub_gid) {
  if (sub_gid_open (
                   0100 
                           | 
                             02
                                   ) == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: cannot open %s\n"),
            Prog, sub_gid_dbname ());
   fail_exit (
             1
                         );
  }
 }

}




static void close_files (void)
{
 if (pw_close () == 0) {
  fprintf (
          stderr
                , gettext ("%s: failure while writing changes to %s\n"), Prog, pw_dbname ());
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
 , "failure while writing changes to %s", pw_dbname ()) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );
  fail_exit (
            1
                        );
 }
 if (pw_unlock () == 0) {
  fprintf (
          stderr
                , gettext ("%s: failed to unlock %s\n"), Prog, pw_dbname ());
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
 , "failed to unlock %s", pw_dbname ()) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );

 }
 pw_locked = 
            0
                 ;

 if (is_shadow) {
  if (spw_close () == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: failure while writing changes to %s\n"),
            Prog, spw_dbname ());
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
  , "failure while writing changes to %s", spw_dbname ()) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );
   fail_exit (
             1
                         );
  }
  if (spw_unlock () == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: failed to unlock %s\n"),
            Prog, spw_dbname ());
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
  , "failed to unlock %s", spw_dbname ()) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );

  }
  spw_locked = 
              0
                   ;
 }

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
  fail_exit (
            1
                        );
 }

 if (is_sub_uid && (sub_uid_close () == 0)) {
  fprintf (
          stderr
                ,
           gettext ("%s: failure while writing changes to %s\n"), Prog, sub_uid_dbname ());
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
 , "failure while writing changes to %s", sub_uid_dbname ()) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );
  fail_exit (
            1
                        );
 }
 if (is_sub_gid && (sub_gid_close () == 0)) {
  fprintf (
          stderr
                ,
           gettext ("%s: failure while writing changes to %s\n"), Prog, sub_gid_dbname ());
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
 , "failure while writing changes to %s", sub_gid_dbname ()) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );
  fail_exit (
            1
                        );
 }


 if (gr_unlock () == 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: failed to unlock %s\n"),
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
 , "failed to unlock %s", gr_dbname ()) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );

 }
 gr_locked = 
            0
                 ;


 if (is_shadow_grp) {
  if (sgr_close () == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: failure while writing changes to %s\n"),
            Prog, sgr_dbname ());
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
  , "failure while writing changes to %s", sgr_dbname ()) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );
   fail_exit (
             1
                         );
  }
  if (sgr_unlock () == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: failed to unlock %s\n"),
            Prog, sgr_dbname ());
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
  sgr_locked = 
              0
                   ;
 }


 if (is_sub_uid) {
  if (sub_uid_unlock () == 0) {
   fprintf (
           stderr
                 , gettext ("%s: failed to unlock %s\n"), Prog, sub_uid_dbname ());
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
  , "failed to unlock %s", sub_uid_dbname ()) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );

  }
  sub_uid_locked = 
                  0
                       ;
 }
 if (is_sub_gid) {
  if (sub_gid_unlock () == 0) {
   fprintf (
           stderr
                 , gettext ("%s: failed to unlock %s\n"), Prog, sub_gid_dbname ());
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
  , "failed to unlock %s", sub_gid_dbname ()) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );

  }
  sub_gid_locked = 
                  0
                       ;
 }

}

static 
      _Bool 
           want_subuids(void)
{
 if (get_subid_nss_handle() != 
                              ((void *)0)
                                  )
  return 
        0
             ;
 if (getdef_ulong ("SUB_UID_COUNT", 65536) == 0)
  return 
        0
             ;
 return 
       1
           ;
}

static 
      _Bool 
           want_subgids(void)
{
 if (get_subid_nss_handle() != 
                              ((void *)0)
                                  )
  return 
        0
             ;
 if (getdef_ulong ("SUB_GID_COUNT", 65536) == 0)
  return 
        0
             ;
 return 
       1
           ;
}

int main (int argc, char **argv)
{
 char buf[
         8192
               ];
 char *fields[8];
 int nfields;
 char *cp;
 const struct passwd *pw;
 struct passwd newpw;
 int errors = 0;
 int line = 0;
 uid_t uid;
 gid_t gid;

 int *lines = 
             ((void *)0)
                 ;
 char **usernames = 
                   ((void *)0)
                       ;
 char **passwords = 
                   ((void *)0)
                       ;
 unsigned int nusers = 0;


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

 openlog("newusers", (
0x01
), 
(10<<3)
);

 process_flags (argc, argv);

 check_perms ();

 is_shadow = spw_file_present ();


 is_shadow_grp = sgr_file_present ();


 is_sub_uid = sub_uid_file_present () && !rflg;
 is_sub_gid = sub_gid_file_present () && !rflg;


 open_files ();
 while (fgets (buf, (int) sizeof buf, 
                                     stdin
                                          ) != (char *) 0) {
  line++;
  cp = strrchr (buf, '\n');
  if (
     ((void *)0) 
          != cp) {
   *cp = '\0';
  } else {
   if (feof (
            stdin
                 ) == 0) {
    fprintf (
            stderr
                  ,
             gettext ("%s: line %d: line too long\n"),
             Prog, line);
    errors++;
    continue;
   }
  }






  for (cp = buf, nfields = 0; nfields < 7; nfields++) {
   fields[nfields] = cp;
   cp = strchr (cp, ':');
   if (
      ((void *)0) 
           != cp) {
    *cp = '\0';
    cp++;
   } else {
    break;
   }
  }
  if (nfields != 6) {
   fprintf (
           stderr
                 , gettext ("%s: line %d: invalid line\n"),
            Prog, line);
   errors++;
   continue;
  }




  pw = pw_locate (fields[0]);

  if ( (
         ((void *)0) 
              == pw)
      && (getpwnam (fields[0]) != 
                                 ((void *)0)
                                     )) {
   fprintf (
           stderr
                 , gettext ("%s: cannot update the entry of user %s (not in the passwd database)\n"), Prog, fields[0]);
   errors++;
   continue;
  }

  if ( (
         ((void *)0) 
              == pw)
      && (get_user_id (fields[2], &uid) != 0)) {
   fprintf (
           stderr
                 ,
            gettext ("%s: line %d: can't create user\n"),
            Prog, line);
   errors++;
   continue;
  }
  if ( (
         ((void *)0) 
              == pw)
      && (add_group (fields[0], fields[3], &gid, uid) != 0)) {
   fprintf (
           stderr
                 ,
            gettext ("%s: line %d: can't create group\n"),
            Prog, line);
   errors++;
   continue;
  }
  if ( (
         ((void *)0) 
              == pw)
      && (add_user (fields[0], uid, gid) != 0)) {
   fprintf (
           stderr
                 ,
            gettext ("%s: line %d: can't create user\n"),
            Prog, line);
   errors++;
   continue;
  }





  pw = pw_locate (fields[0]);
  if (
     ((void *)0) 
          == pw) {
   fprintf (
           stderr
                 ,
            gettext ("%s: line %d: user '%s' does not exist in %s\n"),
            Prog, line, fields[0], pw_dbname ());
   errors++;
   continue;
  }
  newpw = *pw;



  nusers++;
  lines = realloc (lines, sizeof (lines[0]) * nusers);
  usernames = realloc (usernames, sizeof (usernames[0]) * nusers);
  passwords = realloc (passwords, sizeof (passwords[0]) * nusers);
  lines[nusers-1] = line;
  usernames[nusers-1] = strdup (fields[0]);
  passwords[nusers-1] = strdup (fields[1]);

  if (add_passwd (&newpw, fields[1]) != 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: line %d: can't update password\n"),
            Prog, line);
   errors++;
   continue;
  }
  if ('\0' != fields[4][0]) {
   newpw.pw_gecos = fields[4];
  }

  if ('\0' != fields[5][0]) {
   newpw.pw_dir = fields[5];
  }

  if ('\0' != fields[6][0]) {
   newpw.pw_shell = fields[6];
  }

  if ( ('\0' != fields[5][0])
      && (access (newpw.pw_dir, 
                               0
                                   ) != 0)) {

   mode_t mode = getdef_num ("HOME_MODE",
                             0777 & ~getdef_num ("UMASK", 022));
   if (newpw.pw_dir[0] != '/') {
    fprintf(
           stderr
                 ,
     gettext ("%s: line %d: homedir must be an absolute path\n"),
     Prog, line);
    errors++;
    continue;
   };
   if (mkdir (newpw.pw_dir, mode) != 0) {
    fprintf (
            stderr
                  ,
             gettext ("%s: line %d: mkdir %s failed: %s\n"),
             Prog, line, newpw.pw_dir,
             strerror (
                      (*__errno_location ())
                           ));
   } else if (chown (newpw.pw_dir,
                     newpw.pw_uid,
                     newpw.pw_gid) != 0) {
    fprintf (
            stderr
                  ,
             gettext ("%s: line %d: chown %s failed: %s\n"),
             Prog, line, newpw.pw_dir,
             strerror (
                      (*__errno_location ())
                           ));
   }
  }




  if (pw_update (&newpw) == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: line %d: can't update entry\n"),
            Prog, line);
   errors++;
   continue;
  }





  if (is_sub_uid && want_subuids() && !local_sub_uid_assigned(fields[0])) {
   uid_t sub_uid_start = 0;
   unsigned long sub_uid_count = 0;
   if (find_new_sub_uids(&sub_uid_start, &sub_uid_count) == 0) {
    if (sub_uid_add(fields[0], sub_uid_start, sub_uid_count) == 0) {
     fprintf (
             stderr
                   ,
      gettext ("%s: failed to prepare new %s entry\n"),
      Prog, sub_uid_dbname ());
    }
   } else {
    fprintf (
            stderr
                  ,
     gettext ("%s: can't find subordinate user range\n"),
     Prog);
    errors++;
   }
  }




  if (is_sub_gid && want_subgids() && !local_sub_gid_assigned(fields[0])) {
   gid_t sub_gid_start = 0;
   unsigned long sub_gid_count = 0;
   if (find_new_sub_gids(&sub_gid_start, &sub_gid_count) == 0) {
    if (sub_gid_add(fields[0], sub_gid_start, sub_gid_count) == 0) {
     fprintf (
             stderr
                   ,
      gettext ("%s: failed to prepare new %s entry\n"),
      Prog, sub_uid_dbname ());
    }
   } else {
    fprintf (
            stderr
                  ,
     gettext ("%s: can't find subordinate group range\n"),
     Prog);
    errors++;
   }
  }

 }
 if (0 != errors) {
  fprintf (
          stderr
                ,
           gettext ("%s: error detected, changes ignored\n"), Prog);
  fail_exit (
            1
                        );
 }

 close_files ();

 nscd_flush_cache ("passwd");
 nscd_flush_cache ("group");
 sssd_flush_cache (0x001 | 0x002);


 unsigned int i;

 for (i = 0; i < nusers; i++) {
  if (do_pam_passwd_non_interactive ("newusers", usernames[i], passwords[i]) != 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: (line %d, user %s) password not changed\n"),
            Prog, lines[i], usernames[i]);
   errors++;
  }
 }


 return ((0 == errors) ? 
                        0 
                                     : 
                                       1
                                                   );
}
