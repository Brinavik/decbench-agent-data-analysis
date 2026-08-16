
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




extern 
      _Bool 
           is_valid_user_name (const char *name);
extern 
      _Bool 
           is_valid_group_name (const char *name);

struct faillog {
 short fail_cnt;
 short fail_max;
 char fail_line[12];
 time_t fail_time;




 long fail_locktime;
};
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



int run_part (char *script_path, const char *name, const char *action);
int run_parts (const char *directory, const char *name, const char *action);

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




extern void log_set_progname(const char *);
extern const char *log_get_progname(void);
extern void log_set_logfd(FILE *fd);
extern FILE *log_get_logfd(void);
const char *Prog;




static gid_t def_group = 1000;
static const char *def_gname = "other";
static const char *def_home = "/home";
static const char *def_shell = "/bin/bash";
static const char *def_template = "/etc/skel";
static const char *def_create_mail_spool = "yes";
static const char *def_log_init = "yes";

static long def_inactive = -1;
static const char *def_expire = "";



static const char *user_name = "";
static const char *user_pass = "!";
static uid_t user_id;
static gid_t user_gid;
static const char *user_comment = "";
static const char *user_home = "";
static const char *user_shell = "";
static const char *create_mail_spool = "";

static const char *prefix = "";
static const char *prefix_user_home = 
                                     ((void *)0)
                                         ;





static long user_expire = -1;
static 
      _Bool 
           is_shadow_pwd;


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
static uid_t sub_uid_start;
static gid_t sub_gid_start;

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
static char **user_groups;
static long sys_ngroups;
static 
      _Bool 
           do_grp_update = 
                           0
                                ;

extern int allow_bad_names;

static 
      _Bool
    
   bflg = 
          0
               ,
    cflg = 
          0
               ,
    dflg = 
          0
               ,
    Dflg = 
          0
               ,
    eflg = 
          0
               ,
    fflg = 
          0
               ,

    Fflg = 
          0
               ,

    gflg = 
          0
               ,
    Gflg = 
          0
               ,
    kflg = 
          0
               ,
    lflg = 
          0
               ,
    mflg = 
          0
               ,
    Mflg = 
          0
               ,
    Nflg = 
          0
               ,
    oflg = 
          0
               ,
    rflg = 
          0
               ,
    sflg = 
          0
               ,
    subvolflg = 
               0
                    ,
    uflg = 
          0
               ,
    Uflg = 
          0
               ;





static 
      _Bool 
           home_added = 
                        0
                             ;
static void fail_exit (int);
static void get_defaults (void);
static void show_defaults (void);
static int set_defaults (void);
static int get_groups (char *);
static struct group * get_local_group (char * grp_name);
static void usage (int status);
static void new_pwent (struct passwd *);

static long scale_age (long);
static void new_spent (struct spwd *);
static void grp_update (void);

static void process_flags (int argc, char **argv);
static void close_files (void);
static void close_group_files (void);
static void unlock_group_files (void);
static void open_files (void);
static void open_group_files (void);
static void open_shadow (void);
static void faillog_reset (uid_t);
static void lastlog_reset (uid_t);
static void tallylog_reset (const char *);
static void usr_update (unsigned long subuid_count, unsigned long subgid_count);
static void create_home (void);
static void create_mail (void);
static void check_uid_range(int rflg, uid_t user_id);




static void fail_exit (int code)
{
 if (home_added) {
  if (rmdir (prefix_user_home) != 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: %s was created, but could not be removed\n"),
            Prog, prefix_user_home);
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
  , "failed to remove %s", prefix_user_home) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );
  }
 }

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
, "failed adding user '%s', exit code: %d", user_name, code) ; if (
((void *)0) 
!= saved_locale) { (void) setlocale (
6
, saved_locale); free (saved_locale); } } while (
0
);
 exit (code);
}
static void get_defaults (void)
{
 FILE *fp;
 char *default_file = "/etc/default/useradd";
 char buf[1024];
 char *cp;

 if (prefix[0]) {
  size_t len;
  int wlen;

  len = strlen(prefix) + strlen("/etc/default/useradd") + 2;
  default_file = malloc(len);
                if (default_file == 
                                   ((void *)0)
                                       )
                       return;
  wlen = snprintf(default_file, len, "%s/%s", prefix, "/etc/default/useradd");
  
 ((void) sizeof ((
 wlen == (int) len -1
 ) ? 1 : 0), __extension__ ({ if (
 wlen == (int) len -1
 ) ; else __assert_fail (
 "wlen == (int) len -1"
 , "useradd.c", 355, __extension__ __PRETTY_FUNCTION__); }))
                              ;
 }





 fp = fopen (default_file, "r");
 if (
    ((void *)0) 
         == fp) {
  goto getdef_err;
 }





 while (fgets (buf, (int) sizeof buf, fp) == buf) {
  cp = strrchr (buf, '\n');
  if (
     ((void *)0) 
          != cp) {
   *cp = '\0';
  }

  cp = strchr (buf, '=');
  if (
     ((void *)0) 
          == cp) {
   continue;
  }

  cp++;




  if ((strncmp((buf),("GROUP="),strlen("GROUP=")) == 0)) {
   const struct group *grp = prefix_getgr_nam_gid (cp);
   if (
      ((void *)0) 
           == grp) {
    fprintf (
            stderr
                  ,
             gettext ("%s: group '%s' does not exist\n"),
             Prog, cp);
    fprintf (
            stderr
                  ,
             gettext ("%s: the %s configuration in %s will be ignored\n"),
             Prog, "GROUP=", default_file);
   } else {
    def_group = grp->gr_gid;
    def_gname = xstrdup (grp->gr_name);
   }
  }




  else if ((strncmp((buf),("HOME="),strlen("HOME=")) == 0)) {
   def_home = xstrdup (cp);
  }




  else if ((strncmp((buf),("SHELL="),strlen("SHELL=")) == 0)) {
   def_shell = xstrdup (cp);
  }




  else if ((strncmp((buf),("INACTIVE="),strlen("INACTIVE=")) == 0)) {
   if ( (getlong (cp, &def_inactive) == 0)
       || (def_inactive < -1)) {
    fprintf (
            stderr
                  ,
             gettext ("%s: invalid numeric argument '%s'\n"),
             Prog, cp);
    fprintf (
            stderr
                  ,
             gettext ("%s: the %s configuration in %s will be ignored\n"),
             Prog, "INACTIVE=", default_file);
    def_inactive = -1;
   }
  }




  else if ((strncmp((buf),("EXPIRE="),strlen("EXPIRE=")) == 0)) {
   def_expire = xstrdup (cp);
  }




  else if ((strncmp((buf),("SKEL="),strlen("SKEL=")) == 0)) {
   if ('\0' == *cp) {
    cp = "/etc/skel";
   }

   if (prefix[0]) {
    size_t len;
    int wlen;
    char* _def_template;

    len = strlen(prefix) + strlen(cp) + 2;
    _def_template = xmalloc(len);
    wlen = snprintf(_def_template, len, "%s/%s", prefix, cp);
    
   ((void) sizeof ((
   wlen == (int) len -1
   ) ? 1 : 0), __extension__ ({ if (
   wlen == (int) len -1
   ) ; else __assert_fail (
   "wlen == (int) len -1"
   , "useradd.c", 455, __extension__ __PRETTY_FUNCTION__); }))
                                ;
    def_template = _def_template;
   }
   else {
    def_template = xstrdup (cp);
   }
  }




  else if ((strncmp((buf),("CREATE_MAIL_SPOOL="),strlen("CREATE_MAIL_SPOOL=")) == 0)) {
   if (*cp == '\0') {
    cp = "no";
   }

   def_create_mail_spool = xstrdup (cp);
  }




  else if ((strncmp((buf),("LOG_INIT="),strlen("LOG_INIT=")) == 0)) {
   if (*cp == '\0') {
    cp = def_log_init;
   }
   def_log_init = xstrdup (cp);
  }
 }
 (void) fclose (fp);
     getdef_err:
 if (prefix[0]) {
  free(default_file);
 }
}







static void show_defaults (void)
{
 printf ("GROUP=%u\n", (unsigned int) def_group);
 printf ("HOME=%s\n", def_home);
 printf ("INACTIVE=%ld\n", def_inactive);
 printf ("EXPIRE=%s\n", def_expire);
 printf ("SHELL=%s\n", def_shell);
 printf ("SKEL=%s\n", def_template);
 printf ("CREATE_MAIL_SPOOL=%s\n", def_create_mail_spool);
 printf ("LOG_INIT=%s\n", def_log_init);
}
static int set_defaults (void)
{
 FILE *ifp;
 FILE *ofp;
 char buf[1024];
 char *new_file = 
                 ((void *)0)
                     ;
 char *new_file_dup = 
                     ((void *)0)
                         ;
 char *default_file = "/etc/default/useradd";
 char *cp;
 int ofd;
 int wlen;
 
_Bool 
     out_group = 
                 0
                      ;
 
_Bool 
     out_home = 
                0
                     ;
 
_Bool 
     out_inactive = 
                    0
                         ;
 
_Bool 
     out_expire = 
                  0
                       ;
 
_Bool 
     out_shell = 
                 0
                      ;
 
_Bool 
     out_skel = 
                0
                     ;
 
_Bool 
     out_create_mail_spool = 
                             0
                                  ;
 
_Bool 
     out_log_init = 
                    0
                         ;
 size_t len;
 int ret = -1;


 len = strlen(prefix) + strlen("/etc/default/nuaddXXXXXX") + 2;
 new_file = malloc(len);
        if (new_file == 
                       ((void *)0)
                           ) {
  fprintf (
          stderr
                ,
           gettext ("%s: cannot create new defaults file: %s\n"),
           Prog, strerror(
                         (*__errno_location ())
                              ));
  return -1;
        }
 wlen = snprintf(new_file, len, "%s%s%s", prefix, prefix[0]?"/":"", "/etc/default/nuaddXXXXXX");
 
((void) sizeof ((
wlen <= (int) len -1
) ? 1 : 0), __extension__ ({ if (
wlen <= (int) len -1
) ; else __assert_fail (
"wlen <= (int) len -1"
, "useradd.c", 548, __extension__ __PRETTY_FUNCTION__); }))
                             ;

 if (prefix[0]) {
  len = strlen(prefix) + strlen("/etc/default/useradd") + 2;
  default_file = malloc(len);
  if (default_file == 
                     ((void *)0)
                         ) {
   fprintf (
           stderr
                 ,
            gettext ("%s: cannot create new defaults file: %s\n"),
            Prog, strerror(
                          (*__errno_location ())
                               ));
   goto setdef_err;
  }
  wlen = snprintf(default_file, len, "%s/%s", prefix, "/etc/default/useradd");
  
 ((void) sizeof ((
 wlen == (int) len -1
 ) ? 1 : 0), __extension__ ({ if (
 wlen == (int) len -1
 ) ; else __assert_fail (
 "wlen == (int) len -1"
 , "useradd.c", 560, __extension__ __PRETTY_FUNCTION__); }))
                              ;
 }

 new_file_dup = strdup(new_file);
 if (new_file_dup == 
                    ((void *)0)
                        ) {
  fprintf (
          stderr
                ,
   gettext ("%s: cannot create directory for defaults file\n"),
   Prog);
  goto setdef_err;
 }

 ret = mkdir(dirname(new_file_dup), 0755);
 if (-1 == ret && 
                 17 
                        != 
                           (*__errno_location ())
                                ) {
  fprintf (
          stderr
                ,
   gettext ("%s: cannot create directory for defaults file\n"),
   Prog);
  free(new_file_dup);
  goto setdef_err;
 }
 free(new_file_dup);




 ofd = mkstemp (new_file);
 if (-1 == ofd) {
  fprintf (
          stderr
                ,
           gettext ("%s: cannot create new defaults file\n"),
           Prog);
  goto setdef_err;
 }

 ofp = fdopen (ofd, "w");
 if (
    ((void *)0) 
         == ofp) {
  fprintf (
          stderr
                ,
           gettext ("%s: cannot open new defaults file\n"),
           Prog);
  goto setdef_err;
 }






 ifp = fopen (default_file, "r");
 if (
    ((void *)0) 
         == ifp) {
  fprintf (ofp, "# useradd defaults file\n");
  goto skip;
 }

 while (fgets (buf, (int) sizeof buf, ifp) == buf) {
  cp = strrchr (buf, '\n');
  if (
     ((void *)0) 
          != cp) {
   *cp = '\0';
  } else {



   if (feof (ifp) == 0) {
    fprintf (
            stderr
                  ,
             gettext ("%s: line too long in %s: %s..."),
             Prog, default_file, buf);
    (void) fclose (ifp);
    goto setdef_err;
   }
  }

  if (!out_group && (strncmp((buf),("GROUP="),strlen("GROUP=")) == 0)) {
   fprintf (ofp, "GROUP=" "%u\n", (unsigned int) def_group);
   out_group = 
              1
                  ;
  } else if (!out_home && (strncmp((buf),("HOME="),strlen("HOME=")) == 0)) {
   fprintf (ofp, "HOME=" "%s\n", def_home);
   out_home = 
             1
                 ;
  } else if (!out_inactive && (strncmp((buf),("INACTIVE="),strlen("INACTIVE=")) == 0)) {
   fprintf (ofp, "INACTIVE=" "%ld\n", def_inactive);
   out_inactive = 
                 1
                     ;
  } else if (!out_expire && (strncmp((buf),("EXPIRE="),strlen("EXPIRE=")) == 0)) {
   fprintf (ofp, "EXPIRE=" "%s\n", def_expire);
   out_expire = 
               1
                   ;
  } else if (!out_shell && (strncmp((buf),("SHELL="),strlen("SHELL=")) == 0)) {
   fprintf (ofp, "SHELL=" "%s\n", def_shell);
   out_shell = 
              1
                  ;
  } else if (!out_skel && (strncmp((buf),("SKEL="),strlen("SKEL=")) == 0)) {
   fprintf (ofp, "SKEL=" "%s\n", def_template);
   out_skel = 
             1
                 ;
  } else if (!out_create_mail_spool
      && (strncmp((buf),("CREATE_MAIL_SPOOL="),strlen("CREATE_MAIL_SPOOL=")) == 0)) {
   fprintf (ofp,
            "CREATE_MAIL_SPOOL=" "%s\n",
            def_create_mail_spool);
   out_create_mail_spool = 
                          1
                              ;
  } else if (!out_log_init
      && (strncmp((buf),("LOG_INIT="),strlen("LOG_INIT=")) == 0)) {
   fprintf (ofp,
            "LOG_INIT=" "%s\n",
            def_log_init);
   out_log_init = 
                 1
                     ;
  } else
   fprintf (ofp, "%s\n", buf);
 }
 (void) fclose (ifp);

      skip:





 if (!out_group)
  fprintf (ofp, "GROUP=" "%u\n", (unsigned int) def_group);
 if (!out_home)
  fprintf (ofp, "HOME=" "%s\n", def_home);
 if (!out_inactive)
  fprintf (ofp, "INACTIVE=" "%ld\n", def_inactive);
 if (!out_expire)
  fprintf (ofp, "EXPIRE=" "%s\n", def_expire);
 if (!out_shell)
  fprintf (ofp, "SHELL=" "%s\n", def_shell);
 if (!out_skel)
  fprintf (ofp, "SKEL=" "%s\n", def_template);

 if (!out_create_mail_spool)
  fprintf (ofp, "CREATE_MAIL_SPOOL=" "%s\n", def_create_mail_spool);
 if (!out_log_init)
  fprintf (ofp, "LOG_INIT=" "%s\n", def_log_init);




 (void) fflush (ofp);
 if ( (ferror (ofp) != 0)
     || (fsync (fileno (ofp)) != 0)
     || (fclose (ofp) != 0)) {
  unlink (new_file);
  goto setdef_err;
 }




 wlen = snprintf (buf, sizeof buf, "%s-", default_file);
 
((void) sizeof ((
wlen < (int) sizeof buf
) ? 1 : 0), __extension__ ({ if (
wlen < (int) sizeof buf
) ; else __assert_fail (
"wlen < (int) sizeof buf"
, "useradd.c", 702, __extension__ __PRETTY_FUNCTION__); }))
                                ;
 unlink (buf);
 if ((link (default_file, buf) != 0) && (
                                        2 
                                               != 
                                                  (*__errno_location ())
                                                       )) {
  int err = 
           (*__errno_location ())
                ;
  fprintf (
          stderr
                ,
           gettext ("%s: Cannot create backup file (%s): %s\n"),
           Prog, buf, strerror (err));
  unlink (new_file);
  goto setdef_err;
 }




 if (rename (new_file, default_file) != 0) {
  int err = 
           (*__errno_location ())
                ;
  fprintf (
          stderr
                ,
           gettext ("%s: rename: %s: %s\n"),
           Prog, new_file, strerror (err));
  goto setdef_err;
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
, "useradd defaults: GROUP=%u, HOME=%s, SHELL=%s, INACTIVE=%ld, " "EXPIRE=%s, SKEL=%s, CREATE_MAIL_SPOOL=%s, LOG_INIT=%s", (unsigned int) def_group, def_home, def_shell, def_inactive, def_expire, def_template, def_create_mail_spool, def_log_init) ; if (
((void *)0) 
!= saved_locale) { (void) setlocale (
6
, saved_locale); free (saved_locale); } } while (
0
)




                                               ;
 ret = 0;
    setdef_err:
 free(new_file);
 if (prefix[0]) {
  free(default_file);
 }

 return ret;
}
static int get_groups (char *list)
{
 char *cp;
 struct group *grp;
 int errors = 0;
 int ngroups = 0;

 if ('\0' == *list) {
  return 0;
 }




 open_group_files ();






 do {



  cp = strchr (list, ',');
  if (
     ((void *)0) 
          != cp) {
   *cp++ = '\0';
  }





  grp = get_local_group (list);







  if (
     ((void *)0) 
          == grp) {
   fprintf (
           stderr
                 ,
            gettext ("%s: group '%s' does not exist\n"),
            Prog, list);
   errors++;
  }
  list = cp;





  if (
     ((void *)0) 
          == grp) {
   continue;
  }
  if (ngroups == sys_ngroups) {
   fprintf (
           stderr
                 ,
            gettext ("%s: too many groups specified (max %d).\n"),
            Prog, ngroups);
   gr_free(grp);
   break;
  }




  user_groups[ngroups++] = xstrdup (grp->gr_name);
  gr_free (grp);
 } while (
         ((void *)0) 
              != list);

 close_group_files ();
 unlock_group_files ();

 user_groups[ngroups] = (char *) 0;




 if (0 != errors) {
  return -1;
 }

 return 0;
}
static struct group * get_local_group(char * grp_name)
{
 const struct group *grp;
 struct group *result_grp = 
                           ((void *)0)
                               ;
 long long int gid;
 char *endptr;

 gid = strtoll (grp_name, &endptr, 10);
 if ( ('\0' != *grp_name)
  && ('\0' == *endptr)
  && (
     34 
            != 
               (*__errno_location ())
                    )
  && (gid == (gid_t)gid)) {
  grp = gr_locate_gid ((gid_t) gid);
 }
 else {
  grp = gr_locate(grp_name);
 }

 if (grp != 
           ((void *)0)
               ) {
  result_grp = __gr_dup (grp);
  if (
     ((void *)0) 
          == result_grp) {
   fprintf (
           stderr
                 ,
     gettext ("%s: Out of memory. Cannot find group '%s'.\n"),
     Prog, grp_name);
   fail_exit (10);
  }
 }

 return result_grp;
}




static void usage (int status)
{
 FILE *usageout = (0 != status) ? 
                                         stderr 
                                                : 
                                                  stdout
                                                        ;
 (void) fprintf (usageout,
                 gettext ("Usage: %s [options] LOGIN\n" "       %s -D\n" "       %s -D [options]\n" "\n" "Options:\n")



                                ,
                 Prog, Prog, Prog);
 (void) fputs (gettext ("      --badname                 do not check for bad names\n"), usageout);
 (void) fputs (gettext ("  -b, --base-dir BASE_DIR       base directory for the home directory of the\n" "                                new account\n")
                                                                 , usageout);

 (void) fputs (gettext ("      --btrfs-subvolume-home    use BTRFS subvolume for home directory\n"), usageout);

 (void) fputs (gettext ("  -c, --comment COMMENT         GECOS field of the new account\n"), usageout);
 (void) fputs (gettext ("  -d, --home-dir HOME_DIR       home directory of the new account\n"), usageout);
 (void) fputs (gettext ("  -D, --defaults                print or change default useradd configuration\n"), usageout);
 (void) fputs (gettext ("  -e, --expiredate EXPIRE_DATE  expiration date of the new account\n"), usageout);
 (void) fputs (gettext ("  -f, --inactive INACTIVE       password inactivity period of the new account\n"), usageout);

 (void) fputs (gettext ("  -F, --add-subids-for-system   add entries to sub[ud]id even when adding a system user\n"), usageout);

 (void) fputs (gettext ("  -g, --gid GROUP               name or ID of the primary group of the new\n" "                                account\n")
                                                             , usageout);
 (void) fputs (gettext ("  -G, --groups GROUPS           list of supplementary groups of the new\n" "                                account\n")
                                                             , usageout);
 (void) fputs (gettext ("  -h, --help                    display this help message and exit\n"), usageout);
 (void) fputs (gettext ("  -k, --skel SKEL_DIR           use this alternative skeleton directory\n"), usageout);
 (void) fputs (gettext ("  -K, --key KEY=VALUE           override /etc/login.defs defaults\n"), usageout);
 (void) fputs (gettext ("  -l, --no-log-init             do not add the user to the lastlog and\n" "                                faillog databases\n")
                                                                       , usageout);
 (void) fputs (gettext ("  -m, --create-home             create the user's home directory\n"), usageout);
 (void) fputs (gettext ("  -M, --no-create-home          do not create the user's home directory\n"), usageout);
 (void) fputs (gettext ("  -N, --no-user-group           do not create a group with the same name as\n" "                                the user\n")
                                                              , usageout);
 (void) fputs (gettext ("  -o, --non-unique              allow to create users with duplicate\n" "                                (non-unique) UID\n")
                                                                      , usageout);
 (void) fputs (gettext ("  -p, --password PASSWORD       encrypted password of the new account\n"), usageout);
 (void) fputs (gettext ("  -r, --system                  create a system account\n"), usageout);
 (void) fputs (gettext ("  -R, --root CHROOT_DIR         directory to chroot into\n"), usageout);
 (void) fputs (gettext ("  -P, --prefix PREFIX_DIR       prefix directory where are located the /etc/* files\n"), usageout);
 (void) fputs (gettext ("  -s, --shell SHELL             login shell of the new account\n"), usageout);
 (void) fputs (gettext ("  -u, --uid UID                 user ID of the new account\n"), usageout);
 (void) fputs (gettext ("  -U, --user-group              create a group with the same name as the user\n"), usageout);



 (void) fputs ("\n", usageout);
 exit (status);
}







static void new_pwent (struct passwd *pwent)
{
 explicit_bzero((pwent), (sizeof *pwent));
 pwent->pw_name = (char *) user_name;
 if (is_shadow_pwd) {
  pwent->pw_passwd = (char *) "x";
 } else {
  pwent->pw_passwd = (char *) user_pass;
 }

 pwent->pw_uid = user_id;
 pwent->pw_gid = user_gid;
 pwent->pw_gecos = (char *) user_comment;
 pwent->pw_dir = (char *) user_home;
 pwent->pw_shell = (char *) user_shell;
}

static long scale_age (long x)
{
 if (x <= 0) {
  return x;
 }

 return x * ((24L*3600L) / (24L*3600L));
}







static void new_spent (struct spwd *spent)
{
 explicit_bzero((spent), (sizeof *spent));
 spent->sp_namp = (char *) user_name;
 spent->sp_pwdp = (char *) user_pass;
 spent->sp_lstchg = (long) gettime () / (24L*3600L);
 if (0 == spent->sp_lstchg) {

  spent->sp_lstchg = -1;
 }
 if (!rflg) {
  spent->sp_min = scale_age (getdef_num ("PASS_MIN_DAYS", -1));
  spent->sp_max = scale_age (getdef_num ("PASS_MAX_DAYS", -1));
  spent->sp_warn = scale_age (getdef_num ("PASS_WARN_AGE", -1));
  spent->sp_inact = scale_age (def_inactive);
  spent->sp_expire = scale_age (user_expire);
 } else {
  spent->sp_min = -1;
  spent->sp_max = -1;
  spent->sp_warn = -1;
  spent->sp_inact = -1;
  spent->sp_expire = -1;
 }
 spent->sp_flag = ((unsigned long int)-1);
}
static void grp_update (void)
{
 const struct group *grp;
 struct group *ngrp;


 const struct sgrp *sgrp;
 struct sgrp *nsgrp;
 for (gr_rewind (), grp = gr_next (); 
                                     ((void *)0) 
                                          != grp; grp = gr_next ()) {





  if (!is_on_list (user_groups, grp->gr_name)) {
   continue;
  }





  ngrp = __gr_dup (grp);
  if (
     ((void *)0) 
          == ngrp) {
   fprintf (
           stderr
                 ,
            gettext ("%s: Out of memory. Cannot update %s.\n"),
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
  , "failed to prepare the new %s entry '%s'", gr_dbname (), user_name) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );






   fail_exit (10);
  }





  ngrp->gr_mem = add_list (ngrp->gr_mem, user_name);
  if (gr_update (ngrp) == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: failed to prepare the new %s entry '%s'\n"),
            Prog, gr_dbname (), ngrp->gr_name);
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
  , "failed to prepare the new %s entry '%s'", gr_dbname (), user_name) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );






   fail_exit (10);
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
 , "add '%s' to group '%s'", user_name, ngrp->gr_name) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 )

                                     ;
 }


 if (!is_shadow_grp)
  return;






 for (sgr_rewind (), sgrp = sgr_next (); 
                                        ((void *)0) 
                                             != sgrp; sgrp = sgr_next ()) {
  if (gr_locate (sgrp->sg_name) == 
                                  ((void *)0)
                                      ) {
   continue;
  }

  if (!is_on_list (user_groups, sgrp->sg_name)) {
   continue;
  }





  nsgrp = __sgr_dup (sgrp);
  if (
     ((void *)0) 
          == nsgrp) {
   fprintf (
           stderr
                 ,
            gettext ("%s: Out of memory. Cannot update %s.\n"),
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
  , "failed to prepare the new %s entry '%s'", sgr_dbname (), user_name) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );






   fail_exit (10);
  }





  nsgrp->sg_mem = add_list (nsgrp->sg_mem, user_name);
  if (sgr_update (nsgrp) == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: failed to prepare the new %s entry '%s'\n"),
            Prog, sgr_dbname (), nsgrp->sg_name);
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
  , "failed to prepare the new %s entry '%s'", sgr_dbname (), user_name) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );






   fail_exit (10);
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
 , "add '%s' to shadow group '%s'", user_name, nsgrp->sg_name) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 )

                                      ;
 }

}
static void process_flags (int argc, char **argv)
{
 const struct group *grp;
 
_Bool 
     anyflag = 
               0
                    ;
 char *cp;
 struct stat st;

 {



  int c;
  static struct option long_options[] = {
   {"base-dir", 
                     1
                                      , 
                                        ((void *)0)
                                            , 'b'},

   {"btrfs-subvolume-home", 
                           0
                                      , 
                                        ((void *)0)
                                            , 200},

   {"badname", 
                     0
                                , 
                                        ((void *)0)
                                            , 201},
   {"comment", 
                     1
                                      , 
                                        ((void *)0)
                                            , 'c'},
   {"home-dir", 
                     1
                                      , 
                                        ((void *)0)
                                            , 'd'},
   {"defaults", 
                     0
                                , 
                                        ((void *)0)
                                            , 'D'},
   {"expiredate", 
                     1
                                      , 
                                        ((void *)0)
                                            , 'e'},
   {"inactive", 
                     1
                                      , 
                                        ((void *)0)
                                            , 'f'},

   {"add-subids-for-system", 
                            0
                                       ,
                                        ((void *)0)
                                            , 'F'},

   {"gid", 
                     1
                                      , 
                                        ((void *)0)
                                            , 'g'},
   {"groups", 
                     1
                                      , 
                                        ((void *)0)
                                            , 'G'},
   {"help", 
                     0
                                , 
                                        ((void *)0)
                                            , 'h'},
   {"skel", 
                     1
                                      , 
                                        ((void *)0)
                                            , 'k'},
   {"key", 
                     1
                                      , 
                                        ((void *)0)
                                            , 'K'},
   {"no-log-init", 
                     0
                                , 
                                        ((void *)0)
                                            , 'l'},
   {"create-home", 
                     0
                                , 
                                        ((void *)0)
                                            , 'm'},
   {"no-create-home", 
                     0
                                , 
                                        ((void *)0)
                                            , 'M'},
   {"no-user-group", 
                     0
                                , 
                                        ((void *)0)
                                            , 'N'},
   {"non-unique", 
                     0
                                , 
                                        ((void *)0)
                                            , 'o'},
   {"password", 
                     1
                                      , 
                                        ((void *)0)
                                            , 'p'},
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
   {"prefix", 
                     1
                                      , 
                                        ((void *)0)
                                            , 'P'},
   {"shell", 
                     1
                                      , 
                                        ((void *)0)
                                            , 's'},
   {"uid", 
                     1
                                      , 
                                        ((void *)0)
                                            , 'u'},
   {"user-group", 
                     0
                                , 
                                        ((void *)0)
                                            , 'U'},



   {
   ((void *)0)
       , 0, 
            ((void *)0)
                , '\0'}
  };
  while ((c = getopt_long (argc, argv,
      "b:c:d:De:f:g:G:hk:K:lmMNop:rR:P:s:u:U"




                           "F"

      "",
                           long_options, 
                                        ((void *)0)
                                            )) != -1) {
   switch (c) {
   case 'b':
    if ( ( !(strcspn (optarg, ":\n") == strlen (optarg)) )
        || ( optarg[0] != '/' )) {
     fprintf (
             stderr
                   ,
              gettext ("%s: invalid base directory '%s'\n"),
              Prog, optarg);
     exit (3);
    }
    def_home = optarg;
    bflg = 
          1
              ;
    break;
   case 200:
    subvolflg = 
               1
                   ;
    break;
   case 201:
    allow_bad_names = 
                     1
                         ;
    break;
   case 'c':
    if (!(strcspn (optarg, ":\n") == strlen (optarg))) {
     fprintf (
             stderr
                   ,
              gettext ("%s: invalid comment '%s'\n"),
              Prog, optarg);
     exit (3);
    }
    user_comment = optarg;
    cflg = 
          1
              ;
    break;
   case 'd':
    if ( ( !(strcspn (optarg, ":\n") == strlen (optarg)) )
        || ( optarg[0] != '/' )) {
     fprintf (
             stderr
                   ,
              gettext ("%s: invalid home directory '%s'\n"),
              Prog, optarg);
     exit (3);
    }
    user_home = optarg;
    dflg = 
          1
              ;
    break;
   case 'D':
    if (anyflag) {
     usage (2);
    }
    Dflg = 
          1
              ;
    break;
   case 'e':
    if ('\0' != *optarg) {
     user_expire = strtoday (optarg);
     if (user_expire < -1) {
      fprintf (
              stderr
                    ,
               gettext ("%s: invalid date '%s'\n"),
               Prog, optarg);
      exit (3);
     }
    } else {
     user_expire = -1;
    }





    if ((-1 != user_expire) && !is_shadow_pwd) {
     fprintf (
             stderr
                   ,
              gettext ("%s: shadow passwords required for -e\n"),
              Prog);
     exit (2);
    }
    if (Dflg) {
     def_expire = optarg;
    }
    eflg = 
          1
              ;
    break;
   case 'f':
    if ( (getlong (optarg, &def_inactive) == 0)
        || (def_inactive < -1)) {
     fprintf (
             stderr
                   ,
              gettext ("%s: invalid numeric argument '%s'\n"),
              Prog, optarg);
     exit (3);
    }




    if ((-1 != def_inactive) && !is_shadow_pwd) {
     fprintf (
             stderr
                   ,
              gettext ("%s: shadow passwords required for -f\n"),
              Prog);
     exit (2);
    }
    fflg = 
          1
              ;
    break;

   case 'F':
    Fflg = 
          1
              ;
    break;

   case 'g':
    grp = prefix_getgr_nam_gid (optarg);
    if (
       ((void *)0) 
            == grp) {
     fprintf (
             stderr
                   ,
              gettext ("%s: group '%s' does not exist\n"),
              Prog, optarg);
     exit (6);
    }
    if (Dflg) {
     def_group = grp->gr_gid;
     def_gname = optarg;
    } else {
     user_gid = grp->gr_gid;
    }
    gflg = 
          1
              ;
    break;
   case 'G':
    if (get_groups (optarg) != 0) {
     exit (6);
    }
    if (
       ((void *)0) 
            != user_groups[0]) {
     do_grp_update = 
                    1
                        ;
    }
    Gflg = 
          1
              ;
    break;
   case 'h':
    usage (0);
    break;
   case 'k':
    def_template = optarg;
    kflg = 
          1
              ;
    break;
   case 'K':





    cp = strchr (optarg, '=');
    if (
       ((void *)0) 
            == cp) {
     fprintf (
             stderr
                   ,
              gettext ("%s: -K requires KEY=VALUE\n"),
              Prog);
     exit (3);
    }

    *cp = '\0';
    cp++;
    if (putdef_str (optarg, cp) < 0) {
     exit (3);
    }
    break;
   case 'l':
    lflg = 
          1
              ;
    break;
   case 'm':
    mflg = 
          1
              ;
    break;
   case 'M':
    Mflg = 
          1
              ;
    break;
   case 'N':
    Nflg = 
          1
              ;
    break;
   case 'o':
    oflg = 
          1
              ;
    break;
   case 'p':
    if (!(strcspn (optarg, ":\n") == strlen (optarg))) {
     fprintf (
             stderr
                   ,
              gettext ("%s: invalid field '%s'\n"),
              Prog, optarg);
     exit (3);
    }
    user_pass = optarg;
    break;
   case 'r':
    rflg = 
          1
              ;
    break;
   case 'R':
    break;
   case 'P':
    break;
   case 's':
    if ( ( !(strcspn (optarg, ":\n") == strlen (optarg)) )
        || ( ('\0' != optarg[0])
            && ('/' != optarg[0])
            && ('*' != optarg[0]) )) {
     fprintf (
             stderr
                   ,
              gettext ("%s: invalid shell '%s'\n"),
              Prog, optarg);
     exit (3);
    }
    if ( '\0' != optarg[0]
         && '*' != optarg[0]
         && strcmp(optarg, "/sbin/nologin") != 0
         && ( stat(optarg, &st) != 0
             || 
               ((((
               st.st_mode
               )) & 0170000) == (0040000))
             
            || access(optarg, 
                              1
                                  ) != 0)) {
     fprintf (
             stderr
                   ,
              gettext ("%s: Warning: missing or non-executable shell '%s'\n"),
              Prog, optarg);
    }
    user_shell = optarg;
    def_shell = optarg;
    sflg = 
          1
              ;
    break;
   case 'u':
    if ( (get_uid (optarg, &user_id) == 0)
        || (user_id == (gid_t)-1)) {
     fprintf (
             stderr
                   ,
              gettext ("%s: invalid user ID '%s'\n"),
              Prog, optarg);
     exit (3);
    }
    uflg = 
          1
              ;
    break;
   case 'U':
    Uflg = 
          1
              ;
    break;
   default:
    usage (2);
   }
   anyflag = 
            1
                ;
  }
 }

 if (!gflg && !Nflg && !Uflg) {

  Uflg = getdef_bool ("USERGROUPS_ENAB");
 }





 if (oflg && !uflg) {
  fprintf (
          stderr
                ,
           gettext ("%s: %s flag is only allowed with the %s flag\n"),
           Prog, "-o", "-u");
  usage (2);
 }
 if (kflg && !mflg) {
  fprintf (
          stderr
                ,
           gettext ("%s: %s flag is only allowed with the %s flag\n"),
           Prog, "-k", "-m");
  usage (2);
 }
 if (Uflg && gflg) {
  fprintf (
          stderr
                ,
           gettext ("%s: options %s and %s conflict\n"),
           Prog, "-U", "-g");
  usage (2);
 }
 if (Uflg && Nflg) {
  fprintf (
          stderr
                ,
           gettext ("%s: options %s and %s conflict\n"),
           Prog, "-U", "-N");
  usage (2);
 }
 if (mflg && Mflg) {
  fprintf (
          stderr
                ,
           gettext ("%s: options %s and %s conflict\n"),
           Prog, "-m", "-M");
  usage (2);
 }





 if (Dflg) {
  if (optind != argc) {
   usage (2);
  }

  if (uflg || Gflg || dflg || cflg || mflg) {
   usage (2);
  }
 } else {
  if (optind != argc - 1) {
   usage (2);
  }

  user_name = argv[optind];
  if (!is_valid_user_name (user_name)) {
   fprintf (
           stderr
                 ,
            gettext ("%s: invalid user name '%s': use --badname to ignore\n"),
            Prog, user_name);






   exit (3);
  }
  if (!dflg) {
   char *uh;
   size_t len = strlen (def_home) + strlen (user_name) + 2;
   int wlen;

   uh = xmalloc (len);
   wlen = snprintf (uh, len, "%s/%s", def_home, user_name);
   
  ((void) sizeof ((
  wlen == (int) len -1
  ) ? 1 : 0), __extension__ ({ if (
  wlen == (int) len -1
  ) ; else __assert_fail (
  "wlen == (int) len -1"
  , "useradd.c", 1560, __extension__ __PRETTY_FUNCTION__); }))
                               ;

   user_home = uh;
  }
  if (prefix[0]) {
   size_t len = strlen(prefix) + strlen(user_home) + 2;
   int wlen;
   char* _prefix_user_home;
   _prefix_user_home = xmalloc(len);
   wlen = snprintf(_prefix_user_home, len, "%s/%s", prefix, user_home);
   
  ((void) sizeof ((
  wlen == (int) len -1
  ) ? 1 : 0), __extension__ ({ if (
  wlen == (int) len -1
  ) ; else __assert_fail (
  "wlen == (int) len -1"
  , "useradd.c", 1570, __extension__ __PRETTY_FUNCTION__); }))
                               ;
   prefix_user_home = _prefix_user_home;
  }
  else {
   prefix_user_home = user_home;
  }
 }

 if (!eflg) {
  user_expire = strtoday (def_expire);
 }

 if (!gflg) {
  user_gid = def_group;
 }

 if (!sflg) {
  user_shell = def_shell;
 }

 create_mail_spool = def_create_mail_spool;

 if (!lflg) {


  if (strcmp (def_log_init, "no") == 0) {
   lflg = 
         1
             ;
  }
 }

 if (!rflg) {


  if (getdef_bool ("CREATE_HOME")) {
   mflg = 
         1
             ;
  }
 }

 if (Mflg) {

  mflg = 
        0
             ;
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
  fail_exit (1);
 }
 if (is_shadow_pwd && (spw_close () == 0)) {
  fprintf (
          stderr
                ,
           gettext ("%s: failure while writing changes to %s\n"), Prog, spw_dbname ());
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
  fail_exit (1);
 }

 close_group_files ();


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
  fail_exit (16);
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
  fail_exit (18);
 }

 if (is_shadow_pwd) {
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
  spw_locked = 
              0
                   ;
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

 unlock_group_files ();


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







static void close_group_files (void)
{
 if (do_grp_update) {
  if (gr_close () == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: failure while writing changes to %s\n"), Prog, gr_dbname ());
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
   fail_exit (10);
  }

  if (is_shadow_grp && (sgr_close () == 0)) {
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
   fail_exit (10);
  }

 }
}







static void unlock_group_files (void)
{
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
 gr_locked = 
            0
                 ;

 if (is_shadow_grp) {
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
  sgr_locked = 
              0
                   ;
 }

}






static void open_files (void)
{
 if (pw_lock () == 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: cannot lock %s; try again later.\n"),
           Prog, pw_dbname ());
  exit (1);
 }
 pw_locked = 
            1
                ;
 if (pw_open (
             0100 
                     | 
                       02
                             ) == 0) {
  fprintf (
          stderr
                , gettext ("%s: cannot open %s\n"), Prog, pw_dbname ());
  fail_exit (1);
 }



 open_group_files ();


 if (is_sub_uid) {
  if (sub_uid_lock () == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: cannot lock %s; try again later.\n"),
            Prog, sub_uid_dbname ());
   fail_exit (16);
  }
  sub_uid_locked = 
                  1
                      ;
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
   fail_exit (16);
  }
 }
 if (is_sub_gid) {
  if (sub_gid_lock () == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: cannot lock %s; try again later.\n"),
            Prog, sub_gid_dbname ());
   fail_exit (18);
  }
  sub_gid_locked = 
                  1
                      ;
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
   fail_exit (18);
  }
 }

}

static void open_group_files (void)
{
 if (gr_lock () == 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: cannot lock %s; try again later.\n"),
           Prog, gr_dbname ());
  fail_exit (10);
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
                , gettext ("%s: cannot open %s\n"), Prog, gr_dbname ());
  fail_exit (10);
 }


 if (is_shadow_grp) {
  if (sgr_lock () == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: cannot lock %s; try again later.\n"),
            Prog, sgr_dbname ());
   fail_exit (10);
  }
  sgr_locked = 
              1
                  ;
  if (sgr_open (
               0100 
                       | 
                         02
                               ) == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: cannot open %s\n"),
            Prog, sgr_dbname ());
   fail_exit (10);
  }
 }

}

static void open_shadow (void)
{
 if (!is_shadow_pwd) {
  return;
 }
 if (spw_lock () == 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: cannot lock %s; try again later.\n"),
           Prog, spw_dbname ());
  fail_exit (1);
 }
 spw_locked = 
             1
                 ;
 if (spw_open (
              0100 
                      | 
                        02
                              ) == 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: cannot open %s\n"),
           Prog, spw_dbname ());
  fail_exit (1);
 }
}

static char *empty_list = 
                         ((void *)0)
                             ;
static void new_grent (struct group *grent)
{
 explicit_bzero((grent), (sizeof *grent));
 grent->gr_name = (char *) user_name;

 if (is_shadow_grp) {
  grent->gr_passwd = "x";
 } else

 {
  grent->gr_passwd = "!";
 }
 grent->gr_gid = user_gid;
 grent->gr_mem = &empty_list;
}
static void new_sgent (struct sgrp *sgent)
{
 explicit_bzero((sgent), (sizeof *sgent));
 sgent->sg_name = (char *) user_name;
 sgent->sg_passwd = "!";
 sgent->sg_adm = &empty_list;
 sgent->sg_mem = &empty_list;
}
static void grp_add (void)
{
 struct group grp;


 struct sgrp sgrp;





 new_grent (&grp);

 new_sgent (&sgrp);





 if (gr_update (&grp) == 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: failed to prepare the new %s entry '%s'\n"),
           Prog, gr_dbname (), grp.gr_name);






  fail_exit (10);
 }




 if (is_shadow_grp && (sgr_update (&sgrp) == 0)) {
  fprintf (
          stderr
                ,
           gettext ("%s: failed to prepare the new %s entry '%s'\n"),
           Prog, sgr_dbname (), sgrp.sg_name);






  fail_exit (10);
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
, "new group: name=%s, GID=%u", user_name, user_gid) ; if (
((void *)0) 
!= saved_locale) { (void) setlocale (
6
, saved_locale); free (saved_locale); } } while (
0
);






 do_grp_update = 
                1
                    ;
}

static void faillog_reset (uid_t uid)
{
 struct faillog fl;
 int fd;
 off_t offset_uid = (off_t) (sizeof fl) * uid;
 struct stat st;

 if (stat ("/var/log/faillog", &st) != 0 || st.st_size <= offset_uid) {
  return;
 }

 explicit_bzero((&fl), (sizeof (fl)));

 fd = open ("/var/log/faillog", 
                         02
                               );
 if (-1 == fd) {
  fprintf (
          stderr
                ,
           gettext ("%s: failed to open the faillog file for UID %lu: %s\n"),
           Prog, (unsigned long) uid, strerror (
                                               (*__errno_location ())
                                                    ));
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
 4
 , "failed to open the faillog file for UID %lu", (unsigned long) uid) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );
  return;
 }
 if ( (lseek (fd, offset_uid, 
                               0
                                       ) != offset_uid)
     || (write (fd, &fl, sizeof (fl)) != (ssize_t) sizeof (fl))
     || (fsync (fd) != 0)) {
  fprintf (
          stderr
                ,
           gettext ("%s: failed to reset the faillog entry of UID %lu: %s\n"),
           Prog, (unsigned long) uid, strerror (
                                               (*__errno_location ())
                                                    ));
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
 4
 , "failed to reset the faillog entry of UID %lu", (unsigned long) uid) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );
 }
 if (close (fd) != 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: failed to close the faillog file for UID %lu: %s\n"),
           Prog, (unsigned long) uid, strerror (
                                               (*__errno_location ())
                                                    ));
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
 4
 , "failed to close the faillog file for UID %lu", (unsigned long) uid) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );
 }
}

static void lastlog_reset (uid_t uid)
{
 struct lastlog ll;
 int fd;
 off_t offset_uid = (off_t) (sizeof ll) * uid;
 uid_t max_uid;
 struct stat st;

 if (stat ("/var/log/lastlog", &st) != 0 || st.st_size <= offset_uid) {
  return;
 }

 max_uid = (uid_t) getdef_ulong ("LASTLOG_UID_MAX", 0xFFFFFFFFUL);
 if (uid > max_uid) {

  return;
 }

 explicit_bzero((&ll), (sizeof (ll)));

 fd = open ("/var/log/lastlog", 
                         02
                               );
 if (-1 == fd) {
  fprintf (
          stderr
                ,
           gettext ("%s: failed to open the lastlog file for UID %lu: %s\n"),
           Prog, (unsigned long) uid, strerror (
                                               (*__errno_location ())
                                                    ));
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
 4
 , "failed to open the lastlog file for UID %lu", (unsigned long) uid) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );
  return;
 }
 if ( (lseek (fd, offset_uid, 
                               0
                                       ) != offset_uid)
     || (write (fd, &ll, sizeof (ll)) != (ssize_t) sizeof (ll))
     || (fsync (fd) != 0)) {
  fprintf (
          stderr
                ,
           gettext ("%s: failed to reset the lastlog entry of UID %lu: %s\n"),
           Prog, (unsigned long) uid, strerror (
                                               (*__errno_location ())
                                                    ));
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
 4
 , "failed to reset the lastlog entry of UID %lu", (unsigned long) uid) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );

 }
 if (close (fd) != 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: failed to close the lastlog file for UID %lu: %s\n"),
           Prog, (unsigned long) uid, strerror (
                                               (*__errno_location ())
                                                    ));
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
 4
 , "failed to close the lastlog file for UID %lu", (unsigned long) uid) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );

 }
}

static void tallylog_reset (const char *user_name)
{
 const char pam_tally2[] = "/sbin/pam_tally2";
 const char *pname;
 pid_t childpid;
 int failed;
 int status;

 if (access(pam_tally2, 
                       1
                           ) == -1)
  return;

 failed = 0;
 switch (childpid = fork())
 {
 case -1:
  failed = 1;
  break;
 case 0:
  pname = strrchr(pam_tally2, '/');
  if (pname == 
              ((void *)0)
                  )
   pname = pam_tally2;
  else
   pname++;
  execl(pam_tally2, pname, "--user", user_name, "--reset", "--quiet", 
                                                                     ((void *)0)
                                                                         );

  perror(pam_tally2);
  exit(42);

  break;
 default:
  if (waitpid(childpid, &status, 0) == -1 || !
                                             (((
                                             status
                                             ) & 0x7f) == 0) 
                                                               || 
                                                                  (((
                                                                  status
                                                                  ) & 0xff00) >> 8) 
                                                                                      != 0)
   failed = 1;
  break;
 }

 if (failed)
 {
  fprintf (
          stderr
                ,
           gettext ("%s: failed to reset the tallylog entry of user \"%s\"\n"),
           Prog, user_name);
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
 4
 , "failed to reset the tallylog entry of user \"%s\"", user_name) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );
 }

 return;
}







static void usr_update (unsigned long subuid_count, unsigned long subgid_count)
{
 struct passwd pwent;
 struct spwd spent;
 char *tty;





 new_pwent (&pwent);
 new_spent (&spent);





 tty=ttyname (
             0
                         );
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
, "new user: name=%s, UID=%u, GID=%u, home=%s, shell=%s, from=%s", user_name, (unsigned int) user_id, (unsigned int) user_gid, user_home, user_shell, tty ? tty : "none" ) ; if (
((void *)0) 
!= saved_locale) { (void) setlocale (
6
, saved_locale); free (saved_locale); } } while (
0
)



                               ;
 if ((!lflg) && (prefix_getpwuid (user_id) == 
                                             ((void *)0)
                                                 )) {
  faillog_reset (user_id);
  lastlog_reset (user_id);
 }




 if (pw_update (&pwent) == 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: failed to prepare the new %s entry '%s'\n"),
           Prog, pw_dbname (), pwent.pw_name);
  fail_exit (1);
 }




 if (is_shadow_pwd && (spw_update (&spent) == 0)) {
  fprintf (
          stderr
                ,
           gettext ("%s: failed to prepare the new %s entry '%s'\n"),
           Prog, spw_dbname (), spent.sp_namp);






  fail_exit (1);
 }

 if (is_sub_uid &&
     (sub_uid_add(user_name, sub_uid_start, subuid_count) == 0)) {
  fprintf (
          stderr
                ,
           gettext ("%s: failed to prepare the new %s entry\n"),
           Prog, sub_uid_dbname ());
  fail_exit (16);
 }
 if (is_sub_gid &&
     (sub_gid_add(user_name, sub_gid_start, subgid_count) == 0)) {
  fprintf (
          stderr
                ,
           gettext ("%s: failed to prepare the new %s entry\n"),
           Prog, sub_uid_dbname ());
  fail_exit (18);
 }
 if (do_grp_update) {
  grp_update ();
 }
}
static void create_home (void)
{
 if (access (prefix_user_home, 
                              0
                                  ) != 0) {
  char path[strlen (prefix_user_home) + 2];
  char *bhome, *cp;

  path[0] = '\0';
  bhome = strdup (prefix_user_home);
  if (!bhome) {
   fprintf (
           stderr
                 ,
       gettext ("%s: error while duplicating string %s\n"),
       Prog, user_home);
   fail_exit (12);
  }
  cp = strtok (bhome, "/");
  while (cp) {


                        if (bhome[0] == '/' || strlen (path) != 0) {
           strcat (path, "/");
                        }
   strcat (path, cp);
   if (access (path, 
                    0
                        ) != 0) {





    if (subvolflg && (strlen(prefix_user_home) - (int)strlen(path)) <= 1) {
     char *btrfs_check = strdup(path);

     if (!btrfs_check) {
      fprintf (
              stderr
                    ,
               gettext ("%s: error while duplicating string in BTRFS check %s\n"),
               Prog, path);
      fail_exit (12);
     }
     btrfs_check[strlen(path) - strlen(cp) - 1] = '\0';
     if (is_btrfs(btrfs_check) <= 0) {
      fprintf (
              stderr
                    ,
               gettext ("%s: home directory \"%s\" must be mounted on BTRFS\n"),
               Prog, path);
      fail_exit (12);
     }

     if (btrfs_create_subvolume(path)) {
      fprintf (
              stderr
                    ,
               gettext ("%s: failed to create BTRFS subvolume: %s\n"),
               Prog, path);
      fail_exit (12);
     }
    }
    else

    if (mkdir (path, 0) != 0) {
   fprintf (
           stderr
                 ,
       gettext ("%s: cannot create directory %s\n"),
       Prog, path);






   fail_exit (12);
  }
    if (chown (path, 0, 0) < 0) {
     fprintf (
             stderr
                   ,
         gettext ("%s: warning: chown on `%s' failed: %m\n"),
         Prog, path);
    }
    if (chmod (path, 0755) < 0) {
     fprintf (
             stderr
                   ,
         gettext ("%s: warning: chmod on `%s' failed: %m\n"),
         Prog, path);
    }
   }
   cp = strtok (
               ((void *)0)
                   , "/");
  }
  free (bhome);

  (void) chown (prefix_user_home, user_id, user_gid);
  mode_t mode = getdef_num ("HOME_MODE",
                            0777 & ~getdef_num ("UMASK", 022));
  if (chmod (prefix_user_home, mode)) {
   fprintf (
           stderr
                 , gettext ("%s: warning: chown on '%s' failed: %m\n"),
                    Prog, path);
  }
  home_added = 
              1
                  ;
 }
}
static void create_mail (void)
{
 if (strcasecmp (create_mail_spool, "yes") == 0) {
  const char *spool;
  char *file;
  int fd;
  struct group *gr;
  gid_t gid;
  mode_t mode;

  spool = getdef_str ("MAIL_DIR");

  if ((
      ((void *)0) 
           == spool) && (getdef_str ("MAIL_FILE") == 
                                                     ((void *)0)
                                                         )) {
   spool = "/var/mail";
  }

  if (
     ((void *)0) 
          == spool) {
   return;
  }
  file = 
        __builtin_alloca (
        strlen (prefix) + strlen (spool) + strlen (user_name) + 3
        )
                                                                          ;
  if (prefix[0])
   sprintf (file, "%s/%s/%s", prefix, spool, user_name);
  else
   sprintf (file, "%s/%s", spool, user_name);
  fd = open (file, 
                  0100 
                          | 
                            01 
                                     | 
                                       01000 
                                               | 
                                                 0200
                                                       , 0);
  if (fd < 0) {
   perror (gettext ("Creating mailbox file"));
   return;
  }

  gr = prefix_getgrnam ("mail");
  if (
     ((void *)0) 
          == gr) {
   fputs (gettext ("Group 'mail' not found. Creating the user mailbox file with 0600 mode.\n"),
          
         stderr
               );
   gid = user_gid;
   mode = 0600;
  } else {
   gid = gr->gr_gid;
   mode = 0660;
  }

  if ( (fchown (fd, user_id, gid) != 0)
      || (fchmod (fd, mode) != 0)) {
   perror (gettext ("Setting mailbox file permissions"));
  }

  fsync (fd);
  close (fd);
 }
}

static void check_uid_range(int rflg, uid_t user_id)
{
 uid_t uid_min ;
 uid_t uid_max ;
 if (rflg) {
  uid_max = (uid_t)getdef_ulong("SYS_UID_MAX",getdef_ulong("UID_MIN",1000UL)-1);
  if (user_id > uid_max) {
   fprintf(
          stderr
                , gettext ("%s warning: %s's uid %d is greater than SYS_UID_MAX %d\n"), Prog, user_name, user_id, uid_max);
  }
 }else{
  uid_min = (uid_t)getdef_ulong("UID_MIN", 1000UL);
  uid_max = (uid_t)getdef_ulong("UID_MAX", 6000UL);
  if (uid_min <= uid_max) {
   if (user_id < uid_min || user_id >uid_max)
    fprintf(
           stderr
                 , gettext ("%s warning: %s's uid %d outside of the UID_MIN %d and UID_MAX %d range.\n"), Prog, user_name, user_id, uid_min, uid_max);
  }
 }

}



int main (int argc, char **argv)
{
 uid_t uid_min;
 uid_t uid_max;

 unsigned long subuid_count = 0;
 unsigned long subgid_count = 0;




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

 prefix = process_prefix_flag("-P", argc, argv);

 openlog("useradd", (
0x01
), 
(10<<3)
);




 sys_ngroups = sysconf (
                       _SC_NGROUPS_MAX
                                      );
 user_groups = (char **) xmalloc ((1 + sys_ngroups) * sizeof (char *));



 user_groups[0] = (char *) 0;


 is_shadow_pwd = spw_file_present ();

 is_shadow_grp = sgr_file_present ();


 get_defaults ();

 process_flags (argc, argv);


 uid_min = (uid_t) getdef_ulong ("UID_MIN", 1000UL);
 uid_max = (uid_t) getdef_ulong ("UID_MAX", 60000UL);
 subuid_count = getdef_ulong ("SUB_UID_COUNT", 65536);
 subgid_count = getdef_ulong ("SUB_GID_COUNT", 65536);
 is_sub_uid = subuid_count > 0 && sub_uid_file_present () &&
     (!rflg || Fflg) &&
     (!user_id || (user_id <= uid_max && user_id >= uid_min));
 is_sub_gid = subgid_count > 0 && sub_gid_file_present () &&
     (!rflg || Fflg) &&
     (!user_id || (user_id <= uid_max && user_id >= uid_min));


 if (run_parts ("/etc/shadow-maint/useradd-pre.d", user_name,
   "useradd")) {
  exit(1);
 }
 if (Dflg) {
  if (gflg || bflg || fflg || eflg || sflg) {
   exit ((set_defaults () != 0) ? 1 : 0);
  }

  show_defaults ();
  exit (0);
 }




 if (prefix_getpwnam (user_name) != 
                                   ((void *)0)
                                       ) {
  fprintf (
          stderr
                , gettext ("%s: user '%s' already exists\n"), Prog, user_name);






  fail_exit (9);
 }







 if (Uflg) {

  if (prefix_getgrnam (user_name) != 
                                    ((void *)0)
                                        ) {
   fprintf (
           stderr
                 ,
            gettext ("%s: group %s exists - if you want to add this user to that group, use -g.\n"),
            Prog, user_name);






   fail_exit (9);
  }
 }
 open_files ();

 if (!oflg) {



  if (!uflg) {
   if (find_new_uid (rflg, &user_id, 
                                    ((void *)0)
                                        ) < 0) {
    fprintf (
            stderr
                  , gettext ("%s: can't create user\n"), Prog);
    fail_exit (4);
   }
  } else {
   if (prefix_getpwuid (user_id) != 
                                   ((void *)0)
                                       ) {
    fprintf (
            stderr
                  ,
             gettext ("%s: UID %lu is not unique\n"),
             Prog, (unsigned long) user_id);






    fail_exit (4);
   }
  }
 }

 if (uflg)
    check_uid_range(rflg,user_id);
 open_shadow ();



 if (Uflg) {
  if (find_new_gid (rflg, &user_gid, &user_id) < 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: can't create group\n"),
            Prog);
   fail_exit (4);
  }
  grp_add ();
 }


 if (is_sub_uid && subuid_count != 0) {
  if (find_new_sub_uids(&sub_uid_start, &subuid_count) < 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: can't create subordinate user IDs\n"),
            Prog);
   fail_exit(16);
  }
 }
 if (is_sub_gid && subgid_count != 0) {
  if (find_new_sub_gids(&sub_gid_start, &subgid_count) < 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: can't create subordinate group IDs\n"),
            Prog);
   fail_exit(18);
  }
 }


 usr_update (subuid_count, subgid_count);

 close_files ();

 nscd_flush_cache ("passwd");
 nscd_flush_cache ("group");
 sssd_flush_cache (0x001 | 0x002);






 if (!lflg && getpwuid (user_id) != 
                                   ((void *)0)
                                       ) {
  tallylog_reset (user_name);
 }
 if (mflg) {
  create_home ();
  if (home_added) {
   copy_tree (def_template, prefix_user_home, 
                                             0
                                                  , 
                                                    1
                                                        ,
              (uid_t)-1, user_id, (gid_t)-1, user_gid);
  } else {
   fprintf (
           stderr
                 ,
            gettext ("%s: warning: the home directory %s already exists.\n" "%s: Not copying any file from skel directory into it.\n")
                                                                        ,
            Prog, user_home, Prog);
  }

 }


 if (!rflg) {
  create_mail ();
 }

 if (run_parts ("/etc/shadow-maint/useradd-post.d", user_name,
   "useradd")) {
  exit(1);
 }

 return 0;
}
