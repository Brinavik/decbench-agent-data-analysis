
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
           is_shadow_grp;

static char *group_name;
static char *group_newname;
static char *group_passwd;
static gid_t group_id;
static gid_t group_newid;

static const char* prefix = "";
static char *user_list;

static struct cleanup_info_mod info_passwd;
static struct cleanup_info_mod info_group;

static struct cleanup_info_mod info_gshadow;


static 
      _Bool
    
   aflg = 
          0
               ,
    oflg = 
          0
               ,
    gflg = 
          0
               ,
    nflg = 
          0
               ,
    pflg = 
          0
               ;


static void usage (int status);
static void new_grent (struct group *);


static void new_sgent (struct sgrp *);

static void grp_update (void);
static void check_new_gid (void);
static void check_new_name (void);
static void process_flags (int, char **);
static void lock_files (void);
static void prepare_failure_reports (void);
static void open_files (void);
static void close_files (void);
static void update_primary_groups (gid_t ogid, gid_t ngid);






static void usage (int status)
{
 FILE *usageout = (0 != status) ? 
                                         stderr 
                                                : 
                                                  stdout
                                                        ;
 (void) fprintf (usageout,
                 
                dcgettext (((void *)0), 
                "Usage: %s [options] GROUP\n" "\n" "Options:\n"
                , 5)

                                
                               ,
                 Prog);
 (void) fputs (
              dcgettext (((void *)0), 
              "  -a, --append                  append the users mentioned by -U option to the group \n" "                                without removing existing user members\n"
              , 5)
                                                                                            
                                                                                           , usageout);
 (void) fputs (
              dcgettext (((void *)0), 
              "  -g, --gid GID                 change the group ID to GID\n"
              , 5)
                                                                               , usageout);
 (void) fputs (
              dcgettext (((void *)0), 
              "  -h, --help                    display this help message and exit\n"
              , 5)
                                                                                       , usageout);
 (void) fputs (
              dcgettext (((void *)0), 
              "  -n, --new-name NEW_GROUP      change the name to NEW_GROUP\n"
              , 5)
                                                                                 , usageout);
 (void) fputs (
              dcgettext (((void *)0), 
              "  -o, --non-unique              allow to use a duplicate (non-unique) GID\n"
              , 5)
                                                                                              , usageout);
 (void) fputs (
              dcgettext (((void *)0), 
              "  -p, --password PASSWORD       change the password to this (encrypted)\n" "                                PASSWORD\n"
              , 5)
                                                              
                                                             , usageout);
 (void) fputs (
              dcgettext (((void *)0), 
              "  -R, --root CHROOT_DIR         directory to chroot into\n"
              , 5)
                                                                             , usageout);
 (void) fputs (
              dcgettext (((void *)0), 
              "  -P, --prefix PREFIX_DIR       prefix directory where are located the /etc/* files\n"
              , 5)
                                                                                                        , usageout);
 (void) fputs (
              dcgettext (((void *)0), 
              "  -U, --users USERS             list of user members of this group\n"
              , 5)
                                                                                       , usageout);
 (void) fputs ("\n", usageout);
 exit (status);
}







static void new_grent (struct group *grent)
{
 if (nflg) {
  grent->gr_name = xstrdup (group_newname);
 }

 if (gflg) {
  grent->gr_gid = group_newid;
 }

 if ( pflg

     && ( (!is_shadow_grp)
         || (strcmp (grent->gr_passwd, "x") != 0))

  ) {





  grent->gr_passwd = group_passwd;
 }
}
static void new_sgent (struct sgrp *sgent)
{
 if (nflg) {
  sgent->sg_name = xstrdup (group_newname);
 }
 if (pflg) {
  sgent->sg_passwd = group_passwd;
 }
}







static void grp_update (void)
{
 struct group grp;
 const struct group *ogrp;


 struct sgrp sgrp;
 const struct sgrp *osgrp = 
                           ((void *)0)
                               ;





 ogrp = gr_locate (group_name);
 if (
    ((void *)0) 
         == ogrp) {
  fprintf (
          stderr
                ,
           
          dcgettext (((void *)0), 
          "%s: group '%s' does not exist in %s\n"
          , 5)
                                                    ,
           Prog, group_name, gr_dbname ());
  exit (10);
 }
 grp = *ogrp;
 new_grent (&grp);

 if ( is_shadow_grp
     && (pflg || nflg)) {
  osgrp = sgr_locate (group_name);
  if (
     ((void *)0) 
          != osgrp) {
   sgrp = *osgrp;
   new_sgent (&sgrp);
  } else if ( pflg
             && (strcmp (grp.gr_passwd, "x") == 0)) {
   static char *empty = 
                       ((void *)0)
                           ;





   memset (&sgrp, 0, sizeof sgrp);
   sgrp.sg_name = xstrdup (grp.gr_name);
   sgrp.sg_passwd = xstrdup (grp.gr_passwd);
   sgrp.sg_adm = &empty;
   sgrp.sg_mem = dup_list (grp.gr_mem);
   new_sgent (&sgrp);
   osgrp = &sgrp;
  }
 }


 if (gflg) {
  update_primary_groups (ogrp->gr_gid, group_newid);
 }

 if (user_list) {
  char *token;

  if (!aflg) {

   if (
      ((void *)0) 
           != grp.gr_mem[0])
    gr_free_members(&grp);
   grp.gr_mem = (char **)xmalloc(sizeof(char *));
   grp.gr_mem[0] = (char *)0;
  } else {

   if (
      ((void *)0) 
           != grp.gr_mem[0])
    grp.gr_mem = dup_list (grp.gr_mem);
  }

  token = strtok(user_list, ",");
  while (token) {
   if (prefix_getpwnam (token) == 
                                 ((void *)0)
                                     ) {
    fprintf (
            stderr
                  , 
                    dcgettext (((void *)0), 
                    "Invalid member username %s\n"
                    , 5)
                                                     , token);
    exit (10);
   }
   grp.gr_mem = add_list(grp.gr_mem, token);
   token = strtok(
                 ((void *)0)
                     , ",");
  }
 }




 if (gr_update (&grp) == 0) {
  fprintf (
          stderr
                ,
           
          dcgettext (((void *)0), 
          "%s: failed to prepare the new %s entry '%s'\n"
          , 5)
                                                            ,
           Prog, gr_dbname (), grp.gr_name);
  exit (10);
 }
 if (nflg && (gr_remove (group_name) == 0)) {
  fprintf (
          stderr
                ,
           
          dcgettext (((void *)0), 
          "%s: cannot remove entry '%s' from %s\n"
          , 5)
                                                     ,
           Prog, grp.gr_name, gr_dbname ());
  exit (10);
 }





 if (
    ((void *)0) 
         != osgrp) {



  if (sgr_update (&sgrp) == 0) {
   fprintf (
           stderr
                 ,
            
           dcgettext (((void *)0), 
           "%s: failed to prepare the new %s entry '%s'\n"
           , 5)
                                                             ,
            Prog, sgr_dbname (), sgrp.sg_name);
   exit (10);
  }
  if (nflg && (sgr_remove (group_name) == 0)) {
   fprintf (
           stderr
                 ,
            
           dcgettext (((void *)0), 
           "%s: cannot remove entry '%s' from %s\n"
           , 5)
                                                      ,
            Prog, group_name, sgr_dbname ());
   exit (10);
  }
 }

}






static void check_new_gid (void)
{





 if (group_id == group_newid) {
  gflg = 0;
  return;
 }

 if (oflg ||
     (getgrgid (group_newid) == 
                               ((void *)0)
                                   )
    ) {
  return;
 }




 fprintf (
         stderr
               ,
          
         dcgettext (((void *)0), 
         "%s: GID '%lu' already exists\n"
         , 5)
                                            ,
          Prog, (unsigned long int) group_newid);
 exit (4);
}







static void check_new_name (void)
{



 if (strcmp (group_name, group_newname) == 0) {
  nflg = 0;
  return;
 }

 if (is_valid_group_name (group_newname)) {





  if (prefix_getgrnam (group_newname) != 
                                        ((void *)0)
                                            ) {
   fprintf (
           stderr
                 ,
            
           dcgettext (((void *)0), 
           "%s: group '%s' already exists\n"
           , 5)
                                               ,
            Prog, group_newname);
   exit (9);
  }
  return;
 }





 fprintf (
         stderr
               ,
          
         dcgettext (((void *)0), 
         "%s: invalid group name '%s'\n"
         , 5)
                                           ,
          Prog, group_newname);
 exit (3);
}
static void process_flags (int argc, char **argv)
{
 int c;
 static struct option long_options[] = {
  {"append", 
                0
                           , 
                                   ((void *)0)
                                       , 'a'},
  {"gid", 
                1
                                 , 
                                   ((void *)0)
                                       , 'g'},
  {"help", 
                0
                           , 
                                   ((void *)0)
                                       , 'h'},
  {"new-name", 
                1
                                 , 
                                   ((void *)0)
                                       , 'n'},
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
  {"users", 
                1
                                 , 
                                   ((void *)0)
                                       , 'U'},
  {
  ((void *)0)
      , 0, 
           ((void *)0)
               , '\0'}
 };
 while ((c = getopt_long (argc, argv, "ag:hn:op:R:P:U:",
                   long_options, 
                                ((void *)0)
                                    )) != -1) {
  switch (c) {
  case 'a':
   aflg = 
         1
             ;
   break;
  case 'g':
   gflg = 
         1
             ;
   if ( (get_gid (optarg, &group_newid) == 0)
       || (group_newid == (gid_t)-1)) {
    fprintf (
            stderr
                  ,
             
            dcgettext (((void *)0), 
            "%s: invalid group ID '%s'\n"
            , 5)
                                            ,
             Prog, optarg);
    exit (3);
   }
   break;
  case 'h':
   usage (0);
   break;
  case 'n':
   nflg = 
         1
             ;
   group_newname = optarg;
   break;
  case 'o':
   oflg = 
         1
             ;
   break;
  case 'p':
   group_passwd = optarg;
   pflg = 
         1
             ;
   break;
  case 'R':
   break;
  case 'P':
   break;
  case 'U':
   user_list = optarg;
   break;
  default:
   usage (2);
  }
 }

 if (oflg && !gflg) {
  usage (2);
 }

 if (optind != (argc - 1)) {
  usage (2);
 }

 group_name = argv[argc - 1];
}







static void close_files (void)
{
 if (gr_close () == 0) {
  fprintf (
          stderr
                ,
           
          dcgettext (((void *)0), 
          "%s: failure while writing changes to %s\n"
          , 5)
                                                        ,
           Prog, gr_dbname ());
  exit (10);
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
, "group changed in %s (%s)", gr_dbname (), info_group.action) ; if (
((void *)0) 
!= saved_locale) { (void) setlocale (
6
, saved_locale); free (saved_locale); } } while (
0
)

                                           ;
 del_cleanup (cleanup_report_mod_group);

 cleanup_unlock_group (
                      ((void *)0)
                          );
 del_cleanup (cleanup_unlock_group);


 if ( is_shadow_grp
     && (pflg || nflg)) {
  if (sgr_close () == 0) {
   fprintf (
           stderr
                 ,
            
           dcgettext (((void *)0), 
           "%s: failure while writing changes to %s\n"
           , 5)
                                                         ,
            Prog, sgr_dbname ());
   exit (10);
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
 , "group changed in %s (%s)", sgr_dbname (), info_gshadow.action) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 )

                                               ;
  del_cleanup (cleanup_report_mod_gshadow);

  cleanup_unlock_gshadow (
                         ((void *)0)
                             );
  del_cleanup (cleanup_unlock_gshadow);
 }


 if (gflg) {
  if (pw_close () == 0) {
   fprintf (
           stderr
                 ,
            
           dcgettext (((void *)0), 
           "%s: failure while writing changes to %s\n"
           , 5)
                                                         ,
            Prog, pw_dbname ());
   exit (10);
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
 , "group changed in %s (%s)", pw_dbname (), info_passwd.action) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 )

                                             ;
  del_cleanup (cleanup_report_mod_passwd);

  cleanup_unlock_passwd (
                        ((void *)0)
                            );
  del_cleanup (cleanup_unlock_passwd);
 }







}





static void prepare_failure_reports (void)
{
 info_group.name = group_name;

 info_gshadow.name = group_name;

 info_passwd.name = group_name;

 info_group.audit_msg = xmalloc (512);

 info_gshadow.audit_msg = xmalloc (512);

 info_passwd.audit_msg = xmalloc (512);

 (void) snprintf (info_group.audit_msg, 511,
                  "changing %s; ", gr_dbname ());

 (void) snprintf (info_gshadow.audit_msg, 511,
                  "changing %s; ", sgr_dbname ());

 (void) snprintf (info_passwd.audit_msg, 511,
                  "changing %s; ", pw_dbname ());

 info_group.action = info_group.audit_msg
                       + strlen (info_group.audit_msg);

 info_gshadow.action = info_gshadow.audit_msg
                       + strlen (info_gshadow.audit_msg);

 info_passwd.action = info_passwd.audit_msg
                       + strlen (info_passwd.audit_msg);

 (void) snprintf (info_group.action,
                  511 - strlen (info_group.audit_msg),
                  "group %s/%lu",
                  group_name, (unsigned long int) group_id);

 (void) snprintf (info_gshadow.action,
                  511 - strlen (info_group.audit_msg),
                  "group %s", group_name);

 (void) snprintf (info_passwd.action,
                  511 - strlen (info_group.audit_msg),
                  "group %s/%lu",
                  group_name, (unsigned long int) group_id);

 if (nflg) {
  strncat (info_group.action, ", new name: ",
           511 - strlen (info_group.audit_msg));
  strncat (info_group.action, group_newname,
           511 - strlen (info_group.audit_msg));


  strncat (info_gshadow.action, ", new name: ",
           511 - strlen (info_gshadow.audit_msg));
  strncat (info_gshadow.action, group_newname,
           511 - strlen (info_gshadow.audit_msg));


  strncat (info_passwd.action, ", new name: ",
           511 - strlen (info_passwd.audit_msg));
  strncat (info_passwd.action, group_newname,
           511 - strlen (info_passwd.audit_msg));
 }
 if (pflg) {
  strncat (info_group.action, ", new password",
           511 - strlen (info_group.audit_msg));


  strncat (info_gshadow.action, ", new password",
           511 - strlen (info_gshadow.audit_msg));

 }
 if (gflg) {
  strncat (info_group.action, ", new gid: ",
           511 - strlen (info_group.audit_msg));
  (void) snprintf (info_group.action+strlen (info_group.action),
                   511 - strlen (info_group.audit_msg),
                   "%lu", (unsigned long int) group_newid);

  strncat (info_passwd.action, ", new gid: ",
           511 - strlen (info_passwd.audit_msg));
  (void) snprintf (info_passwd.action+strlen (info_passwd.action),
                   511 - strlen (info_passwd.audit_msg),
                   "%lu", (unsigned long int) group_newid);
 }
 info_group.audit_msg[511] = '\0';

 info_gshadow.audit_msg[511] = '\0';

 info_passwd.audit_msg[511] = '\0';


 add_cleanup (cleanup_report_mod_group, &info_group);

 if ( is_shadow_grp
     && (pflg || nflg)) {
  add_cleanup (cleanup_report_mod_gshadow, &info_gshadow);
 }

 if (gflg) {
  add_cleanup (cleanup_report_mod_passwd, &info_passwd);
 }

}






static void lock_files (void)
{
 if (gr_lock () == 0) {
  fprintf (
          stderr
                ,
           
          dcgettext (((void *)0), 
          "%s: cannot lock %s; try again later.\n"
          , 5)
                                                     ,
           Prog, gr_dbname ());
  exit (10);
 }
 add_cleanup (cleanup_unlock_group, 
                                   ((void *)0)
                                       );


 if ( is_shadow_grp
     && (pflg || nflg)) {
  if (sgr_lock () == 0) {
   fprintf (
           stderr
                 ,
            
           dcgettext (((void *)0), 
           "%s: cannot lock %s; try again later.\n"
           , 5)
                                                      ,
            Prog, sgr_dbname ());
   exit (10);
  }
  add_cleanup (cleanup_unlock_gshadow, 
                                      ((void *)0)
                                          );
 }


 if (gflg) {
  if (pw_lock () == 0) {
   fprintf (
           stderr
                 ,
            
           dcgettext (((void *)0), 
           "%s: cannot lock %s; try again later.\n"
           , 5)
                                                      ,
            Prog, pw_dbname ());
   exit (10);
  }
  add_cleanup (cleanup_unlock_passwd, 
                                     ((void *)0)
                                         );
 }
}







static void open_files (void)
{
 if (gr_open (
             0100 
                     | 
                       02
                             ) == 0) {
  fprintf (
          stderr
                , 
                  dcgettext (((void *)0), 
                  "%s: cannot open %s\n"
                  , 5)
                                           , Prog, gr_dbname ());
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
 , "cannot open %s", gr_dbname ()) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );
  exit (10);
 }


 if ( is_shadow_grp
     && (pflg || nflg)) {
  if (sgr_open (
               0100 
                       | 
                         02
                               ) == 0) {
   fprintf (
           stderr
                 ,
            
           dcgettext (((void *)0), 
           "%s: cannot open %s\n"
           , 5)
                                    ,
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
  4
  , "cannot open %s", sgr_dbname ()) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );
   exit (10);
  }
 }


 if (gflg) {
  if (pw_open (
              0100 
                      | 
                        02
                              ) == 0) {
   fprintf (
           stderr
                 ,
            
           dcgettext (((void *)0), 
           "%s: cannot open %s\n"
           , 5)
                                    ,
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
  4
  , "cannot open %s", gr_dbname ()) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  );
   exit (10);
  }
 }
}

void update_primary_groups (gid_t ogid, gid_t ngid)
{
 struct passwd *pwd;

 prefix_setpwent ();
 while ((pwd = prefix_getpwent ()) != 
                                     ((void *)0)
                                         ) {
  if (pwd->pw_gid == ogid) {
   const struct passwd *lpwd;
   struct passwd npwd;
   lpwd = pw_locate (pwd->pw_name);
   if (
      ((void *)0) 
           == lpwd) {
    fprintf (
            stderr
                  ,
             
            dcgettext (((void *)0), 
            "%s: user '%s' does not exist in %s\n"
            , 5)
                                                     ,
             Prog, pwd->pw_name, pw_dbname ());
    exit (10);
   } else {
    npwd = *lpwd;
    npwd.pw_gid = ngid;
    if (pw_update (&npwd) == 0) {
     fprintf (
             stderr
                   ,
              
             dcgettext (((void *)0), 
             "%s: failed to prepare the new %s entry '%s'\n"
             , 5)
                                                               ,
              Prog, pw_dbname (), npwd.pw_name);
     exit (10);
    }
   }
  }
 }
 prefix_endpwent ();
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

 openlog("groupmod", (
0x01
), 
(10<<3)
);




 if (atexit (do_cleanups) != 0) {
  fprintf (
          stderr
                ,
           
          dcgettext (((void *)0), 
          "%s: Cannot setup cleanup service.\n"
          , 5)
                                                  ,
           Prog);
  exit (11);
 }

 process_flags (argc, argv);
 is_shadow_grp = sgr_file_present ();

 {
  struct group *grp;



  grp = prefix_getgrnam (group_name);
  if (
     ((void *)0) 
          == grp) {
   fprintf (
           stderr
                 ,
            
           dcgettext (((void *)0), 
           "%s: group '%s' does not exist\n"
           , 5)
                                               ,
            Prog, group_name);
   exit (6);
  } else {
   group_id = grp->gr_gid;
  }
 }
 if (gflg) {
  check_new_gid ();
 }

 if (nflg) {
  check_new_name ();
 }

 lock_files ();





 prepare_failure_reports ();





 open_files ();

 grp_update ();

 close_files ();

 nscd_flush_cache ("group");
 sssd_flush_cache (0x002);

 return 0;
}
