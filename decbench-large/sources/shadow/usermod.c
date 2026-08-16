
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

static char *user_name;
static char *user_newname;
static char *user_pass;
static uid_t user_id;
static uid_t user_newid;
static gid_t user_gid;
static gid_t user_newgid;
static char *user_comment;
static char *user_newcomment;
static char *user_home;
static char *user_newhome;
static char *user_shell;



static char *user_newshell;
static long user_expire;
static long user_newexpire;
static long user_inactive;
static long user_newinactive;
static long sys_ngroups;
static char **user_groups;

static const char* prefix = "";
static char* prefix_user_home = 
                               ((void *)0)
                                   ;
static char* prefix_user_newhome = 
                                  ((void *)0)
                                      ;

static 
      _Bool
    
   aflg = 
          0
               ,
    cflg = 
          0
               ,
    dflg = 
          0
               ,
    eflg = 
          0
               ,
    fflg = 
          0
               ,
    gflg = 
          0
               ,
    Gflg = 
          0
               ,
    Lflg = 
          0
               ,
    lflg = 
          0
               ,
    mflg = 
          0
               ,
    oflg = 
          0
               ,
    pflg = 
          0
               ,
    rflg = 
          0
               ,
    sflg = 
          0
               ,




    vflg = 
          0
               ,
    Vflg = 
          0
               ,
    wflg = 
          0
               ,
    Wflg = 
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
           is_shadow_pwd;


static 
      _Bool 
           is_shadow_grp;



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
           pw_locked = 
                        0
                             ;
static 
      _Bool 
           spw_locked = 
                        0
                             ;
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




static int get_groups (char *);
static void usage (int status);
static void new_pwent (struct passwd *);
static void new_spent (struct spwd *);
static void fail_exit (int);
static void update_group (void);


static void update_gshadow (void);

static void grp_update (void);

static void process_flags (int, char **);
static void close_files (void);
static void open_files (void);
static void usr_update (void);
static void move_home (void);
static void update_lastlog (void);
static void update_faillog (void);


static void move_mailbox (void);


extern int allow_bad_names;
static int get_groups (char *list)
{
 char *cp;
 const struct group *grp;
 int errors = 0;
 int ngroups = 0;




 user_groups[0] = (char *) 0;

 if ('\0' == *list) {
  return 0;
 }






 do {



  cp = strchr (list, ',');
  if (
     ((void *)0) 
          != cp) {
   *cp = '\0';
   cp++;
  }





  grp = prefix_getgr_nam_gid (list);





  if (
     ((void *)0) 
          == grp) {
   fprintf (
           stderr
                 , gettext ("%s: group '%s' does not exist\n"),
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
   gr_free ((struct group *)grp);
   break;
  }




  user_groups[ngroups++] = xstrdup (grp->gr_name);
  gr_free ((struct group *)grp);
 } while (
         ((void *)0) 
              != list);

 user_groups[ngroups] = (char *) 0;




 if (0 != errors) {
  return -1;
 }

 return 0;
}


struct ulong_range
{
 unsigned long first;
 unsigned long last;
};

static struct ulong_range getulong_range(const char *str)
{
 struct ulong_range result = { .first = 
                                       (0x7fffffffffffffffL * 2UL + 1UL)
                                                , .last = 0 };
 long long first, last;
 char *pos;

 
(*__errno_location ()) 
      = 0;
 first = strtoll(str, &pos, 10);
 if (('\0' == *str) || ('-' != *pos ) || (
                                         34 
                                                == 
                                                   (*__errno_location ())
                                                        ) ||
     (first != (unsigned long int)first))
  goto out;

 
(*__errno_location ()) 
      = 0;
 last = strtoll(pos + 1, &pos, 10);
 if (('\0' != *pos ) || (
                        34 
                               == 
                                  (*__errno_location ())
                                       ) ||
     (last != (unsigned long int)last))
  goto out;

 if (first > last)
  goto out;

 result.first = (unsigned long int)first;
 result.last = (unsigned long int)last;
out:
 return result;
}

struct ulong_range_list_entry {
 struct ulong_range_list_entry *next;
 struct ulong_range range;
};

static struct ulong_range_list_entry *add_sub_uids = 
                                                    ((void *)0)
                                                        , *del_sub_uids = 
                                                                          ((void *)0)
                                                                              ;
static struct ulong_range_list_entry *add_sub_gids = 
                                                    ((void *)0)
                                                        , *del_sub_gids = 
                                                                          ((void *)0)
                                                                              ;

static int prepend_range(const char *str, struct ulong_range_list_entry **head)
{
 struct ulong_range range;
 struct ulong_range_list_entry *entry;
 range = getulong_range(str);
 if (range.first > range.last)
  return 0;

 entry = malloc(sizeof(*entry));
 if (!entry) {
  fprintf (
          stderr
                ,
   gettext ("%s: failed to allocate memory: %s\n"),
   Prog, strerror (
                  (*__errno_location ())
                       ));
  return 0;
 }
 entry->next = *head;
 entry->range = range;
 *head = entry;
 return 1;
}





static void usage (int status)
{
 FILE *usageout = (0 != status) ? 
                                         stderr 
                                                : 
                                                  stdout
                                                        ;
 (void) fprintf (usageout,
                 gettext ("Usage: %s [options] LOGIN\n" "\n" "Options:\n")

                                ,
                 Prog);
 (void) fputs (gettext ("  -a, --append                  append the user to the supplemental GROUPS\n" "                                mentioned by the -G option without removing\n" "                                the user from other groups\n")

                                                                                , usageout);
 (void) fputs (gettext ("  -b, --badname                 allow bad names\n"), usageout);
 (void) fputs (gettext ("  -c, --comment COMMENT         new value of the GECOS field\n"), usageout);
 (void) fputs (gettext ("  -d, --home HOME_DIR           new home directory for the user account\n"), usageout);
 (void) fputs (gettext ("  -e, --expiredate EXPIRE_DATE  set account expiration date to EXPIRE_DATE\n"), usageout);
 (void) fputs (gettext ("  -f, --inactive INACTIVE       set password inactive after expiration\n" "                                to INACTIVE\n")
                                                                 , usageout);
 (void) fputs (gettext ("  -g, --gid GROUP               force use GROUP as new primary group\n"), usageout);
 (void) fputs (gettext ("  -G, --groups GROUPS           new list of supplementary GROUPS\n"), usageout);
 (void) fputs (gettext ("  -h, --help                    display this help message and exit\n"), usageout);
 (void) fputs (gettext ("  -l, --login NEW_LOGIN         new value of the login name\n"), usageout);
 (void) fputs (gettext ("  -L, --lock                    lock the user account\n"), usageout);
 (void) fputs (gettext ("  -m, --move-home               move contents of the home directory to the\n" "                                new location (use only with -d)\n")
                                                                                     , usageout);
 (void) fputs (gettext ("  -o, --non-unique              allow using duplicate (non-unique) UID\n"), usageout);
 (void) fputs (gettext ("  -p, --password PASSWORD       use encrypted password for the new password\n"), usageout);
 (void) fputs (gettext ("  -P, --prefix PREFIX_DIR       prefix directory where are located the /etc/* files\n"), usageout);
 (void) fputs (gettext ("  -r, --remove                  remove the user from only the supplemental GROUPS\n" "                                mentioned by the -G option without removing\n" "                                the user from other groups\n")

                                                                                , usageout);
 (void) fputs (gettext ("  -R, --root CHROOT_DIR         directory to chroot into\n"), usageout);
 (void) fputs (gettext ("  -s, --shell SHELL             new login shell for the user account\n"), usageout);
 (void) fputs (gettext ("  -u, --uid UID                 new UID for the user account\n"), usageout);
 (void) fputs (gettext ("  -U, --unlock                  unlock the user account\n"), usageout);

 (void) fputs (gettext ("  -v, --add-subuids FIRST-LAST  add range of subordinate uids\n"), usageout);
 (void) fputs (gettext ("  -V, --del-subuids FIRST-LAST  remove range of subordinate uids\n"), usageout);
 (void) fputs (gettext ("  -w, --add-subgids FIRST-LAST  add range of subordinate gids\n"), usageout);
 (void) fputs (gettext ("  -W, --del-subgids FIRST-LAST  remove range of subordinate gids\n"), usageout);




 (void) fputs ("\n", usageout);
 exit (status);
}





static char *new_pw_passwd (char *pw_pass)
{
 if (Lflg && ('!' != pw_pass[0])) {
  char *buf = xmalloc (strlen (pw_pass) + 2);






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
 , "lock user '%s' password", user_newname) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );
  strcpy (buf, "!");
  strcat (buf, pw_pass);
  pw_pass = buf;
 } else if (Uflg && pw_pass[0] == '!') {
  char *s;

  if (pw_pass[1] == '\0') {
   fprintf (
           stderr
                 ,
            gettext ("%s: unlocking the user's password would result in a passwordless account.\n" "You should set a password with usermod -p to unlock this user's password.\n")
                                                                                            ,
            Prog);
   return pw_pass;
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
 , "unlock user '%s' password", user_newname) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );
  s = pw_pass;
  while ('\0' != *s) {
   *s = *(s + 1);
   s++;
  }
 } else if (pflg) {





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
 , "change user '%s' password", user_newname) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );
  pw_pass = xstrdup (user_pass);
 }
 return pw_pass;
}







static void new_pwent (struct passwd *pwent)
{
 if (lflg) {
  if (pw_locate (user_newname) != 
                                 ((void *)0)
                                     ) {




   fprintf (
           stderr
                 ,
            gettext ("%s: user '%s' already exists in %s\n"),
            Prog, user_newname, pw_dbname ());
   fail_exit (9);
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
 , "change user name '%s' to '%s'", pwent->pw_name, user_newname) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 )

                                         ;
  pwent->pw_name = xstrdup (user_newname);
 }





 if ( (!is_shadow_pwd)
     || (strcmp (pwent->pw_passwd, "x") != 0)) {
  pwent->pw_passwd = new_pw_passwd (pwent->pw_passwd);
 }

 if (uflg) {





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
 , "change user '%s' UID from '%d' to '%d'", pwent->pw_name, pwent->pw_uid, user_newid) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 )

                                                      ;
  pwent->pw_uid = user_newid;
 }
 if (gflg) {





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
 , "change user '%s' GID from '%d' to '%d'", pwent->pw_name, pwent->pw_gid, user_newgid) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 )

                                                       ;
  pwent->pw_gid = user_newgid;
 }
 if (cflg) {





  pwent->pw_gecos = user_newcomment;
 }

 if (dflg) {





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
 , "change user '%s' home from '%s' to '%s'", pwent->pw_name, pwent->pw_dir, user_newhome) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 )

                                                        ;

  if (strlen(user_newhome) > 1
   && '/' == user_newhome[strlen(user_newhome)-1]) {
   user_newhome[strlen(user_newhome)-1]='\0';
  }

  pwent->pw_dir = user_newhome;
 }
 if (sflg) {





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
 , "change user '%s' shell from '%s' to '%s'", pwent->pw_name, pwent->pw_shell, user_newshell) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 )

                                                           ;
  pwent->pw_shell = user_newshell;
 }
}







static void new_spent (struct spwd *spent)
{
 if (lflg) {
  if (spw_locate (user_newname) != 
                                  ((void *)0)
                                      ) {
   fprintf (
           stderr
                 ,
            gettext ("%s: user '%s' already exists in %s\n"),
            Prog, user_newname, spw_dbname ());
   fail_exit (9);
  }
  spent->sp_namp = xstrdup (user_newname);
 }

 if (fflg) {





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
 , "change user '%s' inactive from '%ld' to '%ld'", spent->sp_namp, spent->sp_inact, user_newinactive) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 )

                                                              ;
  spent->sp_inact = user_newinactive;
 }
 if (eflg) {

  char new_exp[16], old_exp[16];
  date_to_str (sizeof(new_exp), new_exp, user_newexpire * (24L*3600L));
  date_to_str (sizeof(old_exp), old_exp, user_expire * (24L*3600L));





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
 , "change user '%s' expiration from '%s' to '%s'", spent->sp_namp, old_exp, new_exp) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 )

                                             ;
  spent->sp_expire = user_newexpire;
 }
 spent->sp_pwdp = new_pw_passwd (spent->sp_pwdp);

 if (pflg) {
  spent->sp_lstchg = (long) gettime () / (24L*3600L);
  if (0 == spent->sp_lstchg) {


   spent->sp_lstchg = -1;
  }
 }
}




static void fail_exit (int code)
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


static void update_group (void)
{
 
_Bool 
     is_member;
 
_Bool 
     was_member;
 
_Bool 
     changed;
 const struct group *grp;
 struct group *ngrp;

 changed = 
          0
               ;





 while ((grp = gr_next ()) != 
                             ((void *)0)
                                 ) {




  was_member = is_on_list (grp->gr_mem, user_name);
  is_member = Gflg && ( (was_member && aflg)
                       || is_on_list (user_groups, grp->gr_name));

  if (!was_member && !is_member) {
   continue;
  }





  if (Gflg && rflg) {
   is_member = !is_member;
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
   fail_exit (10);
  }

  if (was_member) {
   if ((!Gflg) || is_member) {




    if (lflg) {
     ngrp->gr_mem = del_list (ngrp->gr_mem,
                              user_name);
     ngrp->gr_mem = add_list (ngrp->gr_mem,
                              user_newname);
     changed = 
              1
                  ;





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
    , "change '%s' to '%s' in group '%s'", user_name, user_newname, ngrp->gr_name) ; if (
    ((void *)0) 
    != saved_locale) { (void) setlocale (
    6
    , saved_locale); free (saved_locale); } } while (
    0
    )


                             ;
    }
   } else {



    ngrp->gr_mem = del_list (ngrp->gr_mem, user_name);
    changed = 
             1
                 ;





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
   , "delete '%s' from group '%s'", user_name, ngrp->gr_name) ; if (
   ((void *)0) 
   != saved_locale) { (void) setlocale (
   6
   , saved_locale); free (saved_locale); } } while (
   0
   )

                                       ;
   }
  } else if (is_member) {



   ngrp->gr_mem = add_list (ngrp->gr_mem, user_newname);
   changed = 
            1
                ;





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
  , "add '%s' to group '%s'", user_newname, ngrp->gr_name) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  )
                                         ;
  }
  if (!changed) {
   continue;
  }

  changed = 
           0
                ;
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
  4
  , "failed to prepare the new %s entry '%s'", gr_dbname (), ngrp->gr_name) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );
   fail_exit (10);
  }

  gr_free(ngrp);
 }
}


static void update_gshadow (void)
{
 
_Bool 
     is_member;
 
_Bool 
     was_member;
 
_Bool 
     was_admin;
 
_Bool 
     changed;
 const struct sgrp *sgrp;
 struct sgrp *nsgrp;

 changed = 
          0
               ;





 while ((sgrp = sgr_next ()) != 
                               ((void *)0)
                                   ) {




  was_member = is_on_list (sgrp->sg_mem, user_name);




  was_admin = is_on_list (sgrp->sg_adm, user_name);





  is_member = Gflg && ( (was_member && aflg)
                       || is_on_list (user_groups, sgrp->sg_name));

  if (!was_member && !was_admin && !is_member) {
   continue;
  }





  if (Gflg && rflg) {
   is_member = !is_member;
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
   fail_exit (10);
  }

  if (was_admin && lflg) {



   nsgrp->sg_adm = del_list (nsgrp->sg_adm, user_name);
   nsgrp->sg_adm = add_list (nsgrp->sg_adm, user_newname);
   changed = 
            1
                ;





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
  , "change admin '%s' to '%s' in shadow group '%s'", user_name, user_newname, nsgrp->sg_name) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  )

                                                     ;
  }

  if (was_member) {
   if ((!Gflg) || is_member) {




    if (lflg) {
     nsgrp->sg_mem = del_list (nsgrp->sg_mem,
                               user_name);
     nsgrp->sg_mem = add_list (nsgrp->sg_mem,
                               user_newname);
     changed = 
              1
                  ;





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
    , "change '%s' to '%s' in shadow group '%s'", user_name, user_newname, nsgrp->sg_name) ; if (
    ((void *)0) 
    != saved_locale) { (void) setlocale (
    6
    , saved_locale); free (saved_locale); } } while (
    0
    )


                              ;
    }
   } else {



    nsgrp->sg_mem = del_list (nsgrp->sg_mem, user_name);
    changed = 
             1
                 ;





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
   , "delete '%s' from shadow group '%s'", user_name, nsgrp->sg_name) ; if (
   ((void *)0) 
   != saved_locale) { (void) setlocale (
   6
   , saved_locale); free (saved_locale); } } while (
   0
   )

                                        ;
   }
  } else if (is_member) {



   nsgrp->sg_mem = add_list (nsgrp->sg_mem, user_newname);
   changed = 
            1
                ;





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
  , "add '%s' to shadow group '%s'", user_newname, nsgrp->sg_name) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  )
                                          ;
  }
  if (!changed) {
   continue;
  }

  changed = 
           0
                ;




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
  4
  , "failed to prepare the new %s entry '%s'", sgr_dbname (), nsgrp->sg_name) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  )
                                           ;
   fail_exit (10);
  }

  free (nsgrp);
 }
}
static void grp_update (void)
{
 update_group ();

 if (is_shadow_grp) {
  update_gshadow ();
 }

}
static void process_flags (int argc, char **argv)
{
 const struct group *grp;
 struct stat st;
 
_Bool 
     anyflag = 
               0
                    ;

 {



  int c;
  static struct option long_options[] = {
   {"append", 
                   0
                              , 
                                      ((void *)0)
                                          , 'a'},
   {"badnames", 
                   0
                              , 
                                      ((void *)0)
                                          , 'b'},
   {"comment", 
                   1
                                    , 
                                      ((void *)0)
                                          , 'c'},
   {"home", 
                   1
                                    , 
                                      ((void *)0)
                                          , 'd'},
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
   {"login", 
                   1
                                    , 
                                      ((void *)0)
                                          , 'l'},
   {"lock", 
                   0
                              , 
                                      ((void *)0)
                                          , 'L'},
   {"move-home", 
                   0
                              , 
                                      ((void *)0)
                                          , 'm'},
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
   {"remove", 
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
   {"unlock", 
                   0
                              , 
                                      ((void *)0)
                                          , 'U'},

   {"add-subuids", 
                   1
                                    , 
                                      ((void *)0)
                                          , 'v'},
   {"del-subuids", 
                   1
                                    , 
                                      ((void *)0)
                                          , 'V'},
    {"add-subgids", 
                    1
                                     , 
                                       ((void *)0)
                                           , 'w'},
    {"del-subgids", 
                    1
                                     , 
                                       ((void *)0)
                                           , 'W'},




   {
   ((void *)0)
       , 0, 
            ((void *)0)
                , '\0'}
  };
  while ((c = getopt_long (argc, argv,
                           "abc:d:e:f:g:G:hl:Lmop:rR:s:u:UP:"

                           "v:w:V:W:"




                    , long_options, 
                                   ((void *)0)
                                       )) != -1) {
   switch (c) {
   case 'a':
    aflg = 
          1
              ;
    break;
   case 'b':
    allow_bad_names = 
                     1
                         ;
    break;
   case 'c':
    if (!(strcspn (optarg, ":\n") == strlen (optarg))) {
     fprintf (
             stderr
                   ,
              gettext ("%s: invalid field '%s'\n"),
              Prog, optarg);
     exit (3);
    }
    user_newcomment = optarg;
    cflg = 
          1
              ;
    break;
   case 'd':
    if (!(strcspn (optarg, ":\n") == strlen (optarg))) {
     fprintf (
             stderr
                   ,
              gettext ("%s: invalid field '%s'\n"),
              Prog, optarg);
     exit (3);
    }
    dflg = 
          1
              ;
    user_newhome = optarg;
    if (user_newhome[0] != '/') {
     fprintf (
             stderr
                   ,
              gettext ("%s: homedir must be an absolute path\n"),
              Prog);
     exit (3);
    }
    break;
   case 'e':
    user_newexpire = strtoday (optarg);
    if (user_newexpire < -1) {
     fprintf (
             stderr
                   ,
       gettext ("%s: invalid date '%s'\n"),
       Prog, optarg);
     exit (3);
    }
    user_newexpire *= (24L*3600L) / (24L*3600L);
    eflg = 
          1
              ;
    break;
   case 'f':
    if ( (getlong (optarg, &user_newinactive) == 0)
        || (user_newinactive < -1)) {
     fprintf (
             stderr
                   ,
              gettext ("%s: invalid numeric argument '%s'\n"),
              Prog, optarg);
     exit (3);
    }
    fflg = 
          1
              ;
    break;
   case 'g':
    grp = getgr_nam_gid (optarg);
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
    user_newgid = grp->gr_gid;
    gflg = 
          1
              ;
    gr_free (grp);
    break;
   case 'G':
    if (get_groups (optarg) != 0) {
     exit (6);
    }
    Gflg = 
          1
              ;
    break;
   case 'h':
    usage (0);
                    break;
   case 'l':
    if (!is_valid_user_name (optarg)) {
     fprintf (
             stderr
                   ,
              gettext ("%s: invalid user name '%s': use --badname to ignore\n"),
              Prog, optarg);
     exit (3);
    }
    lflg = 
          1
              ;
    user_newname = optarg;
    break;
   case 'L':
    Lflg = 
          1
              ;
    break;
   case 'm':
    mflg = 
          1
              ;
    break;
   case 'o':
    oflg = 
          1
              ;
    break;
   case 'p':
    user_pass = optarg;
    pflg = 
          1
              ;
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
    user_newshell = optarg;
    sflg = 
          1
              ;
    break;
   case 'u':
    if ( (get_uid (optarg, &user_newid) ==0)
        || (user_newid == (uid_t)-1)) {
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

   case 'v':
    if (prepend_range (optarg, &add_sub_uids) == 0) {
     fprintf (
             stderr
                   ,
      gettext ("%s: invalid subordinate uid range '%s'\n"),
      Prog, optarg);
     exit(3);
    }
    vflg = 
          1
              ;
    break;
   case 'V':
    if (prepend_range (optarg, &del_sub_uids) == 0) {
     fprintf (
             stderr
                   ,
      gettext ("%s: invalid subordinate uid range '%s'\n"),
      Prog, optarg);
     exit(3);
    }
    Vflg = 
          1
              ;
    break;
   case 'w':
    if (prepend_range (optarg, &add_sub_gids) == 0) {
     fprintf (
             stderr
                   ,
      gettext ("%s: invalid subordinate gid range '%s'\n"),
      Prog, optarg);
     exit(3);
    }
    wflg = 
          1
              ;
                break;
   case 'W':
    if (prepend_range (optarg, &del_sub_gids) == 0) {
     fprintf (
             stderr
                   ,
      gettext ("%s: invalid subordinate gid range '%s'\n"),
      Prog, optarg);
     exit(3);
    }
    Wflg = 
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

 if (optind != argc - 1) {
  usage (2);
 }

 user_name = argv[argc - 1];

 {
  const struct passwd *pwd;

  pwd = prefix_getpwnam (user_name);
  if (
     ((void *)0) 
          == pwd) {
   fprintf (
           stderr
                 ,
            gettext ("%s: user '%s' does not exist\n"),
            Prog, user_name);
   exit (6);
  }

  user_id = pwd->pw_uid;
  user_gid = pwd->pw_gid;
  user_comment = xstrdup (pwd->pw_gecos);
  user_home = xstrdup (pwd->pw_dir);
  user_shell = xstrdup (pwd->pw_shell);
 }



 if (!lflg) {
  user_newname = user_name;
 }
 if (!uflg) {
  user_newid = user_id;
 }
 if (!gflg) {
  user_newgid = user_gid;
 }
 if (prefix[0]) {
  size_t len = strlen(prefix) + strlen(user_home) + 2;
  int wlen;
  prefix_user_home = xmalloc(len);
  wlen = snprintf(prefix_user_home, len, "%s/%s", prefix, user_home);
  
 ((void) sizeof ((
 wlen == (int) len -1
 ) ? 1 : 0), __extension__ ({ if (
 wlen == (int) len -1
 ) ; else __assert_fail (
 "wlen == (int) len -1"
 , "usermod.c", 1265, __extension__ __PRETTY_FUNCTION__); }))
                              ;
  if (user_newhome) {
   len = strlen(prefix) + strlen(user_newhome) + 2;
   prefix_user_newhome = xmalloc(len);
   wlen = snprintf(prefix_user_newhome, len, "%s/%s", prefix, user_newhome);
   
  ((void) sizeof ((
  wlen == (int) len -1
  ) ? 1 : 0), __extension__ ({ if (
  wlen == (int) len -1
  ) ; else __assert_fail (
  "wlen == (int) len -1"
  , "usermod.c", 1270, __extension__ __PRETTY_FUNCTION__); }))
                               ;
  }

 }
 else {
  prefix_user_home = user_home;
  prefix_user_newhome = user_newhome;
 }
 {
  const struct spwd *spwd = 
                           ((void *)0)
                               ;

  if (is_shadow_pwd && ((spwd = prefix_getspnam (user_name)) != 
                                                               ((void *)0)
                                                                   )) {
   user_expire = spwd->sp_expire;
   user_inactive = spwd->sp_inact;
  }
 }

 if (!anyflag) {
  fprintf (
          stderr
                , gettext ("%s: no options\n"), Prog);
  usage (2);
 }

 if (aflg && (!Gflg)) {
  fprintf (
          stderr
                ,
           gettext ("%s: %s flag is only allowed with the %s flag\n"),
           Prog, "-a", "-G");
  usage (2);
 }

 if (rflg && (!Gflg)) {
  fprintf (
          stderr
                ,
           gettext ("%s: %s flag is only allowed with the %s flag\n"),
           Prog, "-r", "-G");
  usage (2);
 }

 if (rflg && aflg) {
  fprintf (
          stderr
                ,
           gettext ("%s: %s and %s are mutually exclusive flags\n"),
           Prog, "-r", "-a");
  usage (2);
 }

 if ((Lflg && (pflg || Uflg)) || (pflg && Uflg)) {
  fprintf (
          stderr
                ,
           gettext ("%s: the -L, -p, and -U flags are exclusive\n"),
           Prog);
  usage (2);
 }

 if (oflg && !uflg) {
  fprintf (
          stderr
                ,
           gettext ("%s: %s flag is only allowed with the %s flag\n"),
           Prog, "-o", "-u");
  usage (2);
 }

 if (mflg && !dflg) {
  fprintf (
          stderr
                ,
           gettext ("%s: %s flag is only allowed with the %s flag\n"),
           Prog, "-m", "-d");
  usage (2);
 }

 if (user_newid == user_id) {
  uflg = 
        0
             ;
  oflg = 
        0
             ;
 }
 if (user_newgid == user_gid) {
  gflg = 
        0
             ;
 }
 if ( (
        ((void *)0) 
             != user_newshell)
     && (strcmp (user_newshell, user_shell) == 0)) {
  sflg = 
        0
             ;
 }
 if (strcmp (user_newname, user_name) == 0) {
  lflg = 
        0
             ;
 }
 if (user_newinactive == user_inactive) {
  fflg = 
        0
             ;
 }
 if (user_newexpire == user_expire) {
  eflg = 
        0
             ;
 }
 if ( (
        ((void *)0) 
             != user_newhome)
     && (strcmp (user_newhome, user_home) == 0)) {
  dflg = 
        0
             ;
  mflg = 
        0
             ;
 }
 if ( (
        ((void *)0) 
             != user_newcomment)
     && (strcmp (user_newcomment, user_comment) == 0)) {
  cflg = 
        0
             ;
 }

 if (!(Uflg || uflg || sflg || pflg || mflg || Lflg ||
       lflg || Gflg || gflg || fflg || eflg || dflg || cflg

       || vflg || Vflg || wflg || Wflg




 )) {
  fprintf (
          stdout
                , gettext ("%s: no changes\n"), Prog);
  exit (0);
 }

 if (!is_shadow_pwd && (eflg || fflg)) {
  fprintf (
          stderr
                ,
           gettext ("%s: shadow passwords required for -e and -f\n"),
           Prog);
  exit (2);
 }


 if (lflg && (prefix_getpwnam (user_newname) != 
                                               ((void *)0)
                                                   )) {
  fprintf (
          stderr
                ,
           gettext ("%s: user '%s' already exists\n"),
           Prog, user_newname);
  exit (9);
 }


 if (uflg && !oflg && (prefix_getpwuid (user_newid) != 
                                                      ((void *)0)
                                                          )) {
  fprintf (
          stderr
                ,
           gettext ("%s: UID '%lu' already exists\n"),
           Prog, (unsigned long) user_newid);
  exit (4);
 }


 if ( (vflg || Vflg)
     && !is_sub_uid) {
  fprintf (
          stderr
                ,
           gettext ("%s: %s does not exist, you cannot use the flags %s or %s\n"),
           Prog, sub_uid_dbname (), "-v", "-V");
  exit (2);
 }

 if ( (wflg || Wflg)
     && !is_sub_gid) {
  fprintf (
          stderr
                ,
           gettext ("%s: %s does not exist, you cannot use the flags %s or %s\n"),
           Prog, sub_gid_dbname (), "-w", "-W");
  exit (2);
 }

}







static void close_files (void)
{
 if (pw_close () == 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: failure while writing changes to %s\n"),
           Prog, pw_dbname ());
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
 )

                          ;
  fail_exit (1);
 }

 if (Gflg || lflg) {
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
  )

                          ;
   fail_exit (10);
  }

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
   )

                            ;
    fail_exit (10);
   }
  }


  if (is_shadow_grp) {
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
   )

                            ;

   }
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
  )

                          ;

  }
 }

 if (is_shadow_pwd) {
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
  )

                           ;

  }
 }
 if (pw_unlock () == 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: failed to unlock %s\n"),
           Prog, pw_dbname ());
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
 spw_locked = 
             0
                  ;
 gr_locked = 
            0
                 ;

 sgr_locked = 
             0
                  ;



 if (vflg || Vflg) {
  if (sub_uid_close () == 0) {
   fprintf (
           stderr
                 , gettext ("%s: failure while writing changes to %s\n"), Prog, sub_uid_dbname ());
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
 if (wflg || Wflg) {
  if (sub_gid_close () == 0) {
   fprintf (
           stderr
                 , gettext ("%s: failure while writing changes to %s\n"), Prog, sub_gid_dbname ());
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





 endpwent ();
 endspent ();
 endgrent ();

 endsgent ();

}






static void open_files (void)
{
 if (pw_lock () == 0) {
  fprintf (
          stderr
                ,
           gettext ("%s: cannot lock %s; try again later.\n"),
           Prog, pw_dbname ());
  fail_exit (1);
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
                ,
           gettext ("%s: cannot open %s\n"),
           Prog, pw_dbname ());
  fail_exit (1);
 }
 if (is_shadow_pwd && (spw_lock () == 0)) {
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
 if (is_shadow_pwd && (spw_open (
                                0100 
                                        | 
                                          02
                                                ) == 0)) {
  fprintf (
          stderr
                ,
           gettext ("%s: cannot open %s\n"),
           Prog, spw_dbname ());
  fail_exit (1);
 }

 if (Gflg || lflg) {




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
                 ,
            gettext ("%s: cannot open %s\n"),
            Prog, gr_dbname ());
   fail_exit (10);
  }

  if (is_shadow_grp && (sgr_lock () == 0)) {
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
  if (is_shadow_grp && (sgr_open (
                                 0100 
                                         | 
                                           02
                                                 ) == 0)) {
   fprintf (
           stderr
                 ,
            gettext ("%s: cannot open %s\n"),
            Prog, sgr_dbname ());
   fail_exit (10);
  }

 }

 if (vflg || Vflg) {
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
 if (wflg || Wflg) {
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







static void usr_update (void)
{
 struct passwd pwent;
 const struct passwd *pwd;

 struct spwd spent;
 const struct spwd *spwd = 
                          ((void *)0)
                              ;




 pwd = pw_locate (user_name);
 if (
    ((void *)0) 
         == pwd) {
  fprintf (
          stderr
                ,
           gettext ("%s: user '%s' does not exist in %s\n"),
           Prog, user_name, pw_dbname ());
  fail_exit (6);
 }
 pwent = *pwd;
 new_pwent (&pwent);



 if (is_shadow_pwd) {
  spwd = spw_locate (user_name);
  if (
     ((void *)0) 
          != spwd) {

   spent = *spwd;
   new_spent (&spent);
  } else if ( ( pflg
                 && (strcmp (pwent.pw_passwd, "x") == 0))
             || eflg || fflg) {






   memset (&spent, 0, sizeof spent);
   spent.sp_namp = user_name;




   spent.sp_pwdp = xstrdup (pwent.pw_passwd);
   pwent.pw_passwd = xstrdup ("x");

   spent.sp_lstchg = (long) gettime () / (24L*3600L);
   if (0 == spent.sp_lstchg) {


    spent.sp_lstchg = -1;
   }
   spent.sp_min = getdef_num ("PASS_MIN_DAYS", -1);
   spent.sp_max = getdef_num ("PASS_MAX_DAYS", -1);
   spent.sp_warn = getdef_num ("PASS_WARN_AGE", -1);
   spent.sp_inact = -1;
   spent.sp_expire = -1;
   spent.sp_flag = ((unsigned long int)-1);
   new_spent (&spent);
   spwd = &spent;
  }
 }

 if (lflg || uflg || gflg || cflg || dflg || sflg || pflg
     || Lflg || Uflg) {
  if (pw_update (&pwent) == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: failed to prepare the new %s entry '%s'\n"),
            Prog, pw_dbname (), pwent.pw_name);
   fail_exit (1);
  }
  if (lflg && (pw_remove (user_name) == 0)) {
   fprintf (
           stderr
                 ,
            gettext ("%s: cannot remove entry '%s' from %s\n"),
            Prog, user_name, pw_dbname ());
   fail_exit (1);
  }
 }
 if ((
     ((void *)0) 
          != spwd) && (lflg || eflg || fflg || pflg || Lflg || Uflg)) {
  if (spw_update (&spent) == 0) {
   fprintf (
           stderr
                 ,
            gettext ("%s: failed to prepare the new %s entry '%s'\n"),
            Prog, spw_dbname (), spent.sp_namp);
   fail_exit (1);
  }
  if (lflg && (spw_remove (user_name) == 0)) {
   fprintf (
           stderr
                 ,
            gettext ("%s: cannot remove entry '%s' from %s\n"),
            Prog, user_name, spw_dbname ());
   fail_exit (1);
  }
 }
}







static void move_home (void)
{
 struct stat sb;

 if (access (prefix_user_newhome, 
                                 0
                                     ) == 0) {




  fprintf (
          stderr
                ,
           gettext ("%s: directory %s exists\n"),
           Prog, user_newhome);
  fail_exit (12);
 }

 if (stat (prefix_user_home, &sb) == 0) {




  if (!
      ((((
      sb.st_mode
      )) & 0170000) == (0040000))
                          ) {
   fprintf (
           stderr
                 ,
            gettext ("%s: The previous home directory (%s) was " "not a directory. It is not removed and no " "home directories are created.\n")

                                                ,
            Prog, user_home);
   fail_exit (12);
  }
  if (rename (prefix_user_home, prefix_user_newhome) == 0) {



   if (chown_tree (prefix_user_newhome,
                   user_id, uflg ? user_newid : (uid_t)-1,
                   user_gid, gflg ? user_newgid : (gid_t)-1) != 0) {
    fprintf (
            stderr
                  ,
             gettext ("%s: Failed to change ownership of the home directory"),
             Prog);
    fail_exit (12);
   }






   return;
  } else {
   if (
      18 
            == 
               (*__errno_location ())
                    ) {

    if (btrfs_is_subvolume (prefix_user_home) > 0) {
     fprintf (
             stderr
                   ,
             gettext ("%s: error: cannot move subvolume from %s to %s - different device\n"),
             Prog, prefix_user_home, prefix_user_newhome);
     fail_exit (12);
    }


    if (copy_tree (prefix_user_home, prefix_user_newhome, 
                                                         1
                                                             ,
                   
                  1
                      ,
                   user_id,
                   uflg ? user_newid : (uid_t)-1,
                   user_gid,
                   gflg ? user_newgid : (gid_t)-1) == 0) {
     if (remove_tree (prefix_user_home, 
                                       1
                                           ) != 0) {
      fprintf (
              stderr
                    ,
               gettext ("%s: warning: failed to completely remove old home directory %s"),
               Prog, prefix_user_home);
     }
     return;
    }

    (void) remove_tree (prefix_user_newhome, 
                                            1
                                                );
   }
   fprintf (
           stderr
                 ,
            gettext ("%s: cannot rename directory %s to %s\n"),
            Prog, prefix_user_home, prefix_user_newhome);
   fail_exit (12);
  }
 } else {
  fprintf (
          stderr
                ,
           gettext ("%s: The previous home directory (%s) does not " "exist or is inaccessible. Move cannot be completed.\n")
                                                                     ,
           Prog, prefix_user_home);
 }
}
static void update_lastlog (void)
{
 struct lastlog ll;
 int fd;
 off_t off_uid = (off_t) user_id * sizeof ll;
 off_t off_newuid = (off_t) user_newid * sizeof ll;
 uid_t max_uid;

 if (access ("/var/log/lastlog", 
                          0
                              ) != 0) {
  return;
 }

 max_uid = (uid_t) getdef_ulong ("LASTLOG_UID_MAX", 0xFFFFFFFFUL);
 if (user_newid > max_uid) {

  return;
 }

 fd = open ("/var/log/lastlog", 
                         02
                               );

 if (-1 == fd) {
  fprintf (
          stderr
                ,
           gettext ("%s: failed to copy the lastlog entry of user %lu to user %lu: %s\n"),
           Prog, (unsigned long) user_id, (unsigned long) user_newid, strerror (
                                                                               (*__errno_location ())
                                                                                    ));
  return;
 }

 if ( (lseek (fd, off_uid, 
                            0
                                    ) == off_uid)
     && (read (fd, &ll, sizeof ll) == (ssize_t) sizeof ll)) {

  if ( (lseek (fd, off_newuid, 
                                0
                                        ) != off_newuid)
      || (write (fd, &ll, sizeof ll) != (ssize_t) sizeof ll)
      || (fsync (fd) != 0)) {
   fprintf (
           stderr
                 ,
            gettext ("%s: failed to copy the lastlog entry of user %lu to user %lu: %s\n"),
            Prog, (unsigned long) user_id, (unsigned long) user_newid, strerror (
                                                                                (*__errno_location ())
                                                                                     ));
  }
 } else {




  if ( (lseek (fd, off_newuid, 
                                0
                                        ) == off_newuid)
      && (read (fd, &ll, sizeof ll) == (ssize_t) sizeof ll)) {

   explicit_bzero((&ll), (sizeof (ll)));
   if ( (lseek (fd, off_newuid, 
                                 0
                                         ) != off_newuid)
       || (write (fd, &ll, sizeof ll) != (ssize_t) sizeof ll)
       || (fsync (fd) != 0)) {
    fprintf (
            stderr
                  ,
             gettext ("%s: failed to copy the lastlog entry of user %lu to user %lu: %s\n"),
             Prog, (unsigned long) user_id, (unsigned long) user_newid, strerror (
                                                                                 (*__errno_location ())
                                                                                      ));
   }
  }
 }

 (void) close (fd);
}
static void update_faillog (void)
{
 struct faillog fl;
 int fd;
 off_t off_uid = (off_t) user_id * sizeof fl;
 off_t off_newuid = (off_t) user_newid * sizeof fl;

 if (access ("/var/log/faillog", 
                          0
                              ) != 0) {
  return;
 }

 fd = open ("/var/log/faillog", 
                         02
                               );

 if (-1 == fd) {
  fprintf (
          stderr
                ,
           gettext ("%s: failed to copy the faillog entry of user %lu to user %lu: %s\n"),
           Prog, (unsigned long) user_id, (unsigned long) user_newid, strerror (
                                                                               (*__errno_location ())
                                                                                    ));
  return;
 }

 if ( (lseek (fd, off_uid, 
                            0
                                    ) == off_uid)
     && (read (fd, (char *) &fl, sizeof fl) == (ssize_t) sizeof fl)) {

  if ( (lseek (fd, off_newuid, 
                                0
                                        ) != off_newuid)
      || (write (fd, &fl, sizeof fl) != (ssize_t) sizeof fl)
      || (fsync (fd) != 0)) {
   fprintf (
           stderr
                 ,
            gettext ("%s: failed to copy the faillog entry of user %lu to user %lu: %s\n"),
            Prog, (unsigned long) user_id, (unsigned long) user_newid, strerror (
                                                                                (*__errno_location ())
                                                                                     ));
  }
 } else {




  if ( (lseek (fd, off_newuid, 
                                0
                                        ) == off_newuid)
      && (read (fd, &fl, sizeof fl) == (ssize_t) sizeof fl)) {

   explicit_bzero((&fl), (sizeof (fl)));
   if ( (lseek (fd, off_newuid, 
                                 0
                                         ) != off_newuid)
       || (write (fd, &fl, sizeof fl) != (ssize_t) sizeof fl)) {
    fprintf (
            stderr
                  ,
             gettext ("%s: failed to copy the faillog entry of user %lu to user %lu: %s\n"),
             Prog, (unsigned long) user_id, (unsigned long) user_newid, strerror (
                                                                                 (*__errno_location ())
                                                                                      ));
   }
  }
 }

 (void) close (fd);
}
static void move_mailbox (void)
{
 const char *maildir;
 char* mailfile;
 char* newmailfile;
 int fd;
 struct stat st;
 size_t len;

 maildir = getdef_str ("MAIL_DIR");

 if ((
     ((void *)0) 
          == maildir) && (getdef_str ("MAIL_FILE") == 
                                                      ((void *)0)
                                                          )) {
  maildir = "/var/mail";
 }

 if (
    ((void *)0) 
         == maildir) {
  return;
 }
 len = strlen (prefix) + strlen (maildir) + strlen (user_name) + 2;
 mailfile = 
           __builtin_alloca (
           len
           )
                       ;







 if (prefix[0]) {
  (void) snprintf (mailfile, len, "%s/%s/%s",
                   prefix, maildir, user_name);
 }
 else {
  (void) snprintf (mailfile, len, "%s/%s",
                   maildir, user_name);
 }
 mailfile[len-1] = '\0';

 fd = open (mailfile, 
                     00 
                              | 
                                04000
                                          , 0);
 if (fd < 0) {

  if (
     (*__errno_location ()) 
           != 
              2
                    ) {
   perror (mailfile);
  }
  return;
 }
 if (fstat (fd, &st) < 0) {
  perror ("fstat");
  (void) close (fd);
  return;
 }
 if (st.st_uid != user_id) {

  fprintf (
          stderr
                , gettext ("%s: warning: %s not owned by %s\n"),
           Prog, mailfile, user_name);
  (void) close (fd);
  return;
 }
 if (uflg) {
  if (fchown (fd, user_newid, (gid_t) -1) < 0) {
   perror (gettext ("failed to change mailbox owner"));
  }







 }

 (void) close (fd);

 if (lflg) {
  len = strlen (prefix) + strlen (maildir) + strlen (user_newname) + 2;
  newmailfile = 
               __builtin_alloca (
               len
               )
                          ;
  if (prefix[0]) {
   (void) snprintf (newmailfile, len, "%s/%s/%s",
                    prefix, maildir, user_newname);
  }
  else {
   (void) snprintf (newmailfile, len, "%s/%s",
                    maildir, user_newname);
  }
  newmailfile[len - 1] = '\0';
  if ( (link (mailfile, newmailfile) != 0)
      || (unlink (mailfile) != 0)) {
   perror (gettext ("failed to rename mailbox"));
  }







 }
}





int main (int argc, char **argv)
{
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
 prefix = process_prefix_flag ("-P", argc, argv);

 openlog("usermod", (
0x01
), 
(10<<3)
);




 sys_ngroups = sysconf (
                       _SC_NGROUPS_MAX
                                      );
 user_groups = (char **) malloc (sizeof (char *) * (1 + sys_ngroups));
 user_groups[0] = (char *) 0;

 is_shadow_pwd = spw_file_present ();

 is_shadow_grp = sgr_file_present ();


 is_sub_uid = sub_uid_file_present ();
 is_sub_gid = sub_gid_file_present ();


 process_flags (argc, argv);






 if ( (prefix[0] == '\0') && (uflg || lflg || dflg

         || Vflg || Wflg

        )
     && (user_busy (user_name, user_id) != 0)) {
  exit (8);
 }
 open_files ();
 if ( cflg || dflg || eflg || fflg || gflg || Lflg || lflg || pflg
     || sflg || uflg || Uflg) {
  usr_update ();
 }
 if (Gflg || lflg) {
  grp_update ();
 }

 if (Vflg) {
  struct ulong_range_list_entry *ptr;
  for (ptr = del_sub_uids; ptr != 
                                 ((void *)0)
                                     ; ptr = ptr->next) {
   unsigned long count = ptr->range.last - ptr->range.first + 1;
   if (sub_uid_remove(user_name, ptr->range.first, count) == 0) {
    fprintf (
            stderr
                  ,
     gettext ("%s: failed to remove uid range %lu-%lu from '%s'\n"),
     Prog, ptr->range.first, ptr->range.last,
     sub_uid_dbname ());
    fail_exit (16);
   }
  }
 }
 if (vflg) {
  struct ulong_range_list_entry *ptr;
  for (ptr = add_sub_uids; ptr != 
                                 ((void *)0)
                                     ; ptr = ptr->next) {
   unsigned long count = ptr->range.last - ptr->range.first + 1;
   if (sub_uid_add(user_name, ptr->range.first, count) == 0) {
    fprintf (
            stderr
                  ,
     gettext ("%s: failed to add uid range %lu-%lu to '%s'\n"),
     Prog, ptr->range.first, ptr->range.last,
     sub_uid_dbname ());
    fail_exit (16);
   }
  }
 }
 if (Wflg) {
  struct ulong_range_list_entry *ptr;
  for (ptr = del_sub_gids; ptr != 
                                 ((void *)0)
                                     ; ptr = ptr->next) {
   unsigned long count = ptr->range.last - ptr->range.first + 1;
   if (sub_gid_remove(user_name, ptr->range.first, count) == 0) {
    fprintf (
            stderr
                  ,
     gettext ("%s: failed to remove gid range %lu-%lu from '%s'\n"),
     Prog, ptr->range.first, ptr->range.last,
     sub_gid_dbname ());
    fail_exit (18);
   }
  }
 }
 if (wflg) {
  struct ulong_range_list_entry *ptr;
  for (ptr = add_sub_gids; ptr != 
                                 ((void *)0)
                                     ; ptr = ptr->next) {
   unsigned long count = ptr->range.last - ptr->range.first + 1;
   if (sub_gid_add(user_name, ptr->range.first, count) == 0) {
    fprintf (
            stderr
                  ,
     gettext ("%s: failed to add gid range %lu-%lu to '%s'\n"),
     Prog, ptr->range.first, ptr->range.last,
     sub_gid_dbname ());
    fail_exit (18);
   }
  }
 }

 close_files ();
 nscd_flush_cache ("passwd");
 nscd_flush_cache ("group");
 sssd_flush_cache (0x001 | 0x002);
 if (mflg) {
  move_home ();
 }


 if (lflg || uflg) {
  move_mailbox ();
 }


 if (uflg) {
  update_lastlog ();
  update_faillog ();
 }

 if (!mflg && (uflg || gflg)) {
  struct stat sb;

  if (stat (dflg ? prefix_user_newhome : prefix_user_home, &sb) == 0 &&
   ((uflg && sb.st_uid == user_newid) || sb.st_uid == user_id)) {
   if (chown_tree (dflg ? prefix_user_newhome : prefix_user_home,
                   user_id,
                   uflg ? user_newid : (uid_t)-1,
                   user_gid,
                   gflg ? user_newgid : (gid_t)-1) != 0) {
    fprintf (
            stderr
                  ,
             gettext ("%s: Failed to change ownership of the home directory"),
             Prog);
    fail_exit (12);
   }
  }
 }

 return 0;
}
