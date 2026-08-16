
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



struct faillog {
 short fail_cnt;
 short fail_max;
 char fail_line[12];
 time_t fail_time;




 long fail_locktime;
};

extern void failure (uid_t, const char *, struct faillog *);
extern int failcheck (uid_t uid, struct faillog *fl, 
                                                    _Bool 
                                                         failed);







extern void failprint (const struct faillog *);
extern void failtmp (const char *username, const struct utmp *);
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

extern void log_set_progname(const char *);
extern const char *log_get_progname(void);
extern void log_set_logfd(FILE *fd);
extern FILE *log_get_logfd(void);

















static struct pam_conv conv = {
 misc_conv,
 
((void *)0)

};

static pam_handle_t *pamh = 
                           ((void *)0)
                               ;
const char *Prog;

static const char *hostname = "";
static char *username = 
                                            ((void *)0)
                                                ;
static int reason = 2;




static 
      _Bool 
           pflg = 
                  0
                       ;
static 
      _Bool 
           fflg = 
                  0
                       ;






static 
      _Bool 
           hflg = 
                  0
                       ;
static 
      _Bool 
           preauth_flag = 
                          0
                               ;

static 
      _Bool 
           amroot;
static char tmsg[256];





extern char **newenvp;
extern size_t newenvc;
extern char **environ;
static void usage (void);
static void setup_tty (void);
static void process_flags (int argc, char *const *argv);
static const char *get_failent_user ( const char *user);
static void update_utmp (const char *user,
                         const char *tty,
                         const char *host,



                                   const struct utmp *utent

   );







static void get_pam_user (char **ptr_pam_user);


static void init_env (void);
static void alarm_handler (int);
static void usage (void)
{
 fprintf (
         stderr
               , gettext ("Usage: %s [-p] [name]\n"), Prog);
 if (!amroot) {
  exit (1);
 }
 fprintf (
         stderr
               , gettext ("       %s [-p] [-h host] [-f name]\n"), Prog);



 exit (1);
}

static void setup_tty (void)
{
 struct termios termio;

 if (tcgetattr(0, &termio) == 0) {
  int erasechar;
  int killchar;




  termio.c_lflag |= 
                   0000001 
                        | 
                          0000002 
                                 | 
                                   0000010 
                                        | 
                                          0000020
                                               ;
  termio.c_iflag |= 
                   0000400
                        ;


  termio.c_lflag |= 
                   0004000 
                          | 
                            0001000
                                   ;


  termio.c_lflag &= ~(
                     0002000 
                             | 
                               0000200 
                                      | 
                                        0000400
                                              );


  termio.c_oflag |= 
                   0000004
                        ;



  erasechar = getdef_num ("ERASECHAR", (int) termio.c_cc[
                                                        2
                                                              ]);
  killchar = getdef_num ("KILLCHAR", (int) termio.c_cc[
                                                      3
                                                           ]);
  termio.c_cc[
             2
                   ] = (cc_t) erasechar;
  termio.c_cc[
             3
                  ] = (cc_t) killchar;



  if (erasechar != (int) termio.c_cc[
                                    2
                                          ]) {
   fprintf (
           stderr
                 ,
            gettext ("configuration error - cannot parse %s value: '%d'"),
            "ERASECHAR", erasechar);
   exit (1);
  }
  if (killchar != (int) termio.c_cc[
                                   3
                                        ]) {
   fprintf (
           stderr
                 ,
            gettext ("configuration error - cannot parse %s value: '%d'"),
            "KILLCHAR", killchar);
   exit (1);
  }





  (void) tcsetattr(0, 
        0
        , &termio);
 }
}
static void process_flags (int argc, char *const *argv)
{
 int arg;
 int flag;






 for (arg = 1; arg < argc; arg++) {
  if (argv[arg][0] == '-' && strlen (argv[arg]) > 2) {
   usage ();
  }
  if (strcmp(argv[arg], "--") == 0) {
   break;
  }
 }




 while ((flag = getopt (argc, argv, "d:fh:pr:")) != 
                                                   (-1)
                                                      ) {
  switch (flag) {
  case 'd':

   break;
  case 'f':
   fflg = 
         1
             ;
   break;
  case 'h':
   hflg = 
         1
             ;
   hostname = optarg;
   reason = 201;
   break;







  case 'p':
   pflg = 
         1
             ;
   break;
  default:
   usage ();
  }
 }
 if ((
     0 
          || fflg || hflg) && !amroot) {
  fprintf (
          stderr
                , gettext ("%s: Permission denied.\n"), Prog);
  exit (1);
 }




 if (optind < argc) {
  
 ((void) sizeof ((((void *)0) 
 == username
 ) ? 1 : 0), __extension__ ({ if (((void *)0) 
 == username
 ) ; else __assert_fail (
 "NULL == username"
 , "login.c", 335, __extension__ __PRETTY_FUNCTION__); }))
                          ;
  username = xstrdup (argv[optind]);
  explicit_bzero((argv[optind]), (strlen(argv[optind])));
  ++optind;
 }






 if (fflg && (
             ((void *)0) 
                  == username)) {
  usage ();
 }

}


static void init_env (void)
{



 char *tmp;

 tmp = getenv ("LANG");
 if (
    ((void *)0) 
         != tmp) {
  addenv ("LANG", tmp);
 }





 tmp = getenv ("TZ");
 if (
    ((void *)0) 
         != tmp) {
  addenv ("TZ", tmp);
 }
 tmp = getenv ("HZ");
 if (
    ((void *)0) 
         != tmp) {
  addenv ("HZ", tmp);
 }
}


static void alarm_handler (__attribute__((unused)) int sig)
{
 write (
       2
                    , tmsg, strlen (tmsg));
 _exit (0);
}







static void get_pam_user (char **ptr_pam_user)
{
 int retcode;
 void *ptr_user;

 
((void) sizeof ((((void *)0) 
!= ptr_pam_user
) ? 1 : 0), __extension__ ({ if (((void *)0) 
!= ptr_pam_user
) ; else __assert_fail (
"NULL != ptr_pam_user"
, "login.c", 417, __extension__ __PRETTY_FUNCTION__); }))
                             ;

 retcode = pam_get_item (pamh, 
                              2
                                      , (const void **)&ptr_user);
 if (retcode != 
0
) { fprintf(
stderr
,"\n%s\n",pam_strerror(pamh, retcode)); do { char *old_locale = setlocale (
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
,"%s",pam_strerror(pamh, retcode)) ; if (
((void *)0) 
!= saved_locale) { (void) setlocale (
6
, saved_locale); free (saved_locale); } } while (
0
); (void) pam_end(pamh, retcode); exit(1); };

 free (*ptr_pam_user);
 if (
    ((void *)0) 
         != ptr_user) {
  *ptr_pam_user = xstrdup ((const char *)ptr_user);
 } else {
  *ptr_pam_user = 
                 ((void *)0)
                     ;
 }
}
static const char *get_failent_user ( const char *user)
{
 const char *failent_user = "UNKNOWN";
 
_Bool 
     log_unkfail_enab = getdef_bool("LOG_UNKFAIL_ENAB");

 if ((
     ((void *)0) 
          != user) && ('\0' != user[0])) {
  if ( log_unkfail_enab
      || (getpwnam (user) != 
                            ((void *)0)
                                )) {
   failent_user = user;
  }
 }

 return failent_user;
}
static void update_utmp (const char *user,
                         const char *tty,
                         const char *host,



                                   const struct utmp *utent

    )
{



 struct utmp *ut = prepare_utmp (user, tty, host, utent);



 (void) setutmp (ut);
 free (ut);




}
int main (int argc, char **argv)
{
 const char *tmptty;
 char tty[
         8192
               ];







 unsigned int delay;
 unsigned int retries;
 
_Bool 
     subroot = 
               0
                    ;



 int err;
 unsigned int timeout;
 const char *cp;
 const char *tmp;
 char fromhost[512];
 struct passwd *pwd = 
                     ((void *)0)
                         ;
 char **envp = environ;
 const char *failent_user;



           struct utmp *utent;



 int retcode;
 pid_t child;
 char *pam_user = 
                 ((void *)0)
                     ;







 sanitize_env ();

 (void) setlocale (
                  6
                        , "");
 (void) bindtextdomain ("shadow", "/usr/share/locale");
 (void) textdomain ("shadow");

 initenv ();

 amroot = (getuid () == 0);
 Prog = Basename (argv[0]);
 log_set_progname(Prog);
 log_set_logfd(
              stderr
                    );

 if (geteuid() != 0) {
  fprintf (
          stderr
                , gettext ("%s: Cannot possibly work without effective root\n"), Prog);
  exit (1);
 }

 process_flags (argc, argv);

 if ((isatty (0) == 0) || (isatty (1) == 0) || (isatty (2) == 0)) {
  exit (1);
 }

 utent = get_current_utmp ();







 if (!amroot && (
                ((void *)0) 
                     == utent)) {
  (void) puts (gettext ("No utmp entry.  You must exec \"login\" from the lowest level \"sh\""));
  exit (1);
 }


 tmptty = ttyname (0);
 if (
    ((void *)0) 
         == tmptty) {
  tmptty = "UNKNOWN";
 }
 (strncpy((tty), (tmptty), sizeof(tty) - 1), (tty)[sizeof(tty) - 1] = '\0');





 if (
    0 
         || hflg) {




  addenv ("REMOTEHOST", hostname);
 }
 if (fflg) {
  preauth_flag = 
                1
                    ;
 }
 if (hflg) {
  reason = 202;
 }
 openlog("login", (
0x01
), 
(10<<3)
);

 setup_tty ();
 if (pflg) {
  while (
        ((void *)0) 
             != *envp) {
   addenv (*envp, 
                 ((void *)0)
                     );
   envp++;
  }
 }






 {

  if (!pflg) {
   tmp = getenv ("TERM");
   if (
      ((void *)0) 
           != tmp) {
    addenv ("TERM", tmp);
   }
  }
 }

 init_env ();

 if (optind < argc) {
  set_env (argc - optind, &argv[optind]);
 }

 if (
    0 
         || hflg) {
  cp = hostname;

 } else if ((
            ((void *)0) 
                 != utent) && ('\0' != utent->ut_host[0])) {
  cp = utent->ut_host;

 } else {
  cp = "";
 }

 if ('\0' != *cp) {
  snprintf (fromhost, sizeof fromhost,
            " on '%.100s' from '%.200s'", tty, cp);
 } else {
  snprintf (fromhost, sizeof fromhost,
            " on '%.100s'", tty);
 }

      top:

 timeout = getdef_unum ("LOGIN_TIMEOUT", 60);
 snprintf (tmsg, sizeof tmsg,
           gettext ("\nLogin timed out after %u seconds.\n"), timeout);
 (void) signal (
               14
                      , alarm_handler);
 if (timeout > 0) {
  (void) alarm (timeout);
 }

 environ = newenvp;
 delay = getdef_unum ("FAIL_DELAY", 1);
 retries = getdef_unum ("LOGIN_RETRIES", 3);


 retcode = pam_start ("login", username, &conv, &pamh);
 if (retcode != 
               0
                          ) {
  fprintf (
          stderr
                ,
           gettext ("login: PAM Failure, aborting: %s\n"),
           pam_strerror (pamh, retcode));
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
 , "Couldn't initialize PAM: %s", pam_strerror (pamh, retcode)) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 )
                                         ;
  exit (99);
 }
 retcode = pam_set_item (pamh, 
                              4
                                       , hostname);
 if (retcode != 
0
) { fprintf(
stderr
,"\n%s\n",pam_strerror(pamh, retcode)); do { char *old_locale = setlocale (
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
,"%s",pam_strerror(pamh, retcode)) ; if (
((void *)0) 
!= saved_locale) { (void) setlocale (
6
, saved_locale); free (saved_locale); } } while (
0
); (void) pam_end(pamh, retcode); exit(1); };
 retcode = pam_set_item (pamh, 
                              3
                                     , tty);
 if (retcode != 
0
) { fprintf(
stderr
,"\n%s\n",pam_strerror(pamh, retcode)); do { char *old_locale = setlocale (
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
,"%s",pam_strerror(pamh, retcode)) ; if (
((void *)0) 
!= saved_locale) { (void) setlocale (
6
, saved_locale); free (saved_locale); } } while (
0
); (void) pam_end(pamh, retcode); exit(1); };

 retcode = pam_fail_delay (pamh, 1000000 * delay);
 if (retcode != 
0
) { fprintf(
stderr
,"\n%s\n",pam_strerror(pamh, retcode)); do { char *old_locale = setlocale (
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
,"%s",pam_strerror(pamh, retcode)) ; if (
((void *)0) 
!= saved_locale) { (void) setlocale (
6
, saved_locale); free (saved_locale); } } while (
0
); (void) pam_end(pamh, retcode); exit(1); };


 if (!fflg) {
  unsigned int failcount = 0;
  char hostn[256];
  char loginprompt[256];


  if (gethostname (hostn, sizeof (hostn)) == 0) {
   snprintf (loginprompt,
             sizeof (loginprompt),
             gettext ("%s login: "), hostn);
  } else {
   strncpy (loginprompt, gettext ("login: "),
            sizeof (loginprompt));
  }

  retcode = pam_set_item (pamh, 
                               9
                                              , loginprompt);
  if (retcode != 
 0
 ) { fprintf(
 stderr
 ,"\n%s\n",pam_strerror(pamh, retcode)); do { char *old_locale = setlocale (
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
 ,"%s",pam_strerror(pamh, retcode)) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 ); (void) pam_end(pamh, retcode); exit(1); };



  get_pam_user (&pam_user);
  if ((
      ((void *)0) 
           != pam_user) && ('\0' == pam_user[0])) {
   retcode = pam_set_item (pamh, 
                                2
                                        , 
                                          ((void *)0)
                                              );
   if (retcode != 
  0
  ) { fprintf(
  stderr
  ,"\n%s\n",pam_strerror(pamh, retcode)); do { char *old_locale = setlocale (
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
  ,"%s",pam_strerror(pamh, retcode)) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  ); (void) pam_end(pamh, retcode); exit(1); };
  }
  failcount = 0;
  while (
        1
            ) {
   
  _Bool 
       failed = 
                0
                     ;

   failcount++;

   if (delay > 0) {
    retcode = pam_fail_delay(pamh, 1000000*delay);
    if (retcode != 
   0
   ) { fprintf(
   stderr
   ,"\n%s\n",pam_strerror(pamh, retcode)); do { char *old_locale = setlocale (
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
   ,"%s",pam_strerror(pamh, retcode)) ; if (
   ((void *)0) 
   != saved_locale) { (void) setlocale (
   6
   , saved_locale); free (saved_locale); } } while (
   0
   ); (void) pam_end(pamh, retcode); exit(1); };
   }


   retcode = pam_authenticate (pamh, 0);

   get_pam_user (&pam_user);
   failent_user = get_failent_user (pam_user);

   if (retcode == 
                 11
                             ) {
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
   5
   , "TOO MANY LOGIN TRIES (%u)%s FOR '%s'", failcount, fromhost, failent_user) ; if (
   ((void *)0) 
   != saved_locale) { (void) setlocale (
   6
   , saved_locale); free (saved_locale); } } while (
   0
   )

                                                ;
    fprintf (
            stderr
                  ,
             gettext ("Maximum number of tries exceeded (%u)\n"),
             failcount);
    { retcode = pam_close_session(pamh,0); (void) pam_end(pamh,retcode); };
    exit(0);
   } else if (retcode == 
                        26
                                 ) {

    (void) fputs (gettext ("login: abort requested by PAM\n"), 
                                                       stderr
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
   3
   ,"PAM_ABORT returned from pam_authenticate()") ; if (
   ((void *)0) 
   != saved_locale) { (void) setlocale (
   6
   , saved_locale); free (saved_locale); } } while (
   0
   );
    { retcode = pam_close_session(pamh,0); (void) pam_end(pamh,retcode); };
    exit(99);
   } else if (retcode != 
                        0
                                   ) {
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
   5
   ,"FAILED LOGIN (%u)%s FOR '%s', %s", failcount, fromhost, failent_user, pam_strerror (pamh, retcode)) ; if (
   ((void *)0) 
   != saved_locale) { (void) setlocale (
   6
   , saved_locale); free (saved_locale); } } while (
   0
   )

                                           ;
    failed = 
            1
                ;
   }

   if (!failed) {
    break;
   }
   (void) puts ("");
   (void) puts (gettext ("Login incorrect"));

   if (failcount >= retries) {
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
   5
   , "TOO MANY LOGIN TRIES (%u)%s FOR '%s'", failcount, fromhost, failent_user) ; if (
   ((void *)0) 
   != saved_locale) { (void) setlocale (
   6
   , saved_locale); free (saved_locale); } } while (
   0
   )

                                                ;
    fprintf (
            stderr
                  ,
             gettext ("Maximum number of tries exceeded (%u)\n"),
             failcount);
    { retcode = pam_close_session(pamh,0); (void) pam_end(pamh,retcode); };
    exit(0);
   }






   retcode = pam_set_item (pamh, 
                                2
                                        , 
                                          ((void *)0)
                                              );
   if (retcode != 
  0
  ) { fprintf(
  stderr
  ,"\n%s\n",pam_strerror(pamh, retcode)); do { char *old_locale = setlocale (
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
  ,"%s",pam_strerror(pamh, retcode)) ; if (
  ((void *)0) 
  != saved_locale) { (void) setlocale (
  6
  , saved_locale); free (saved_locale); } } while (
  0
  ); (void) pam_end(pamh, retcode); exit(1); };
  }


  (void) alarm (0);
 }


 retcode = pam_acct_mgmt (pamh, 0);
 if (retcode == 
               12
                                   ) {
  retcode = pam_chauthtok (pamh, 
                                0x0020U
                                                          );
 }
 if (retcode != 
0
) { fprintf(
stderr
,"\n%s\n",pam_strerror(pamh, retcode)); do { char *old_locale = setlocale (
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
,"%s",pam_strerror(pamh, retcode)) ; if (
((void *)0) 
!= saved_locale) { (void) setlocale (
6
, saved_locale); free (saved_locale); } } while (
0
); (void) pam_end(pamh, retcode); exit(1); };


 get_pam_user (&pam_user);
 retcode = pam_open_session (pamh, hushed (pam_user) ? 
                                                      0x8000U 
                                                                 : 0);
 if (retcode != 
0
) { fprintf(
stderr
,"\n%s\n",pam_strerror(pamh, retcode)); do { char *old_locale = setlocale (
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
,"%s",pam_strerror(pamh, retcode)) ; if (
((void *)0) 
!= saved_locale) { (void) setlocale (
6
, saved_locale); free (saved_locale); } } while (
0
); (void) pam_end(pamh, retcode); exit(1); };







 get_pam_user (&pam_user);
 free (username);
 username = xstrdup (pam_user);
 failent_user = get_failent_user (username);

 pwd = xgetpwnam (username);
 if (
    ((void *)0) 
         == pwd) {
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
 , "cannot find user %s", failent_user) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );
  fprintf (
          stderr
                ,
           gettext ("Cannot find user (%s)\n"),
           username);
  exit (1);
 }





 if (setup_groups (pwd) != 0) {
  exit (1);
 }

 retcode = pam_setcred (pamh, 
                             0x0002U
                                               );
 if (retcode != 
0
) { fprintf(
stderr
,"\n%s\n",pam_strerror(pamh, retcode)); do { char *old_locale = setlocale (
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
,"%s",pam_strerror(pamh, retcode)) ; if (
((void *)0) 
!= saved_locale) { (void) setlocale (
6
, saved_locale); free (saved_locale); } } while (
0
); (void) pam_end(pamh, retcode); exit(1); };
 
((void) sizeof ((((void *)0) 
!= username
) ? 1 : 0), __extension__ ({ if (((void *)0) 
!= username
) ; else __assert_fail (
"NULL != username"
, "login.c", 1098, __extension__ __PRETTY_FUNCTION__); }))
                         ;
 
((void) sizeof ((((void *)0) 
!= pwd
) ? 1 : 0), __extension__ ({ if (((void *)0) 
!= pwd
) ; else __assert_fail (
"NULL != pwd"
, "login.c", 1099, __extension__ __PRETTY_FUNCTION__); }))
                    ;

 (void) alarm (0);
 if (getenv ("IFS")) {
  addenv ("IFS= \t\n", 
                      ((void *)0)
                          );
 }

 if (pwd->pw_shell[0] == '*') {
  pwd->pw_shell++;
  subsystem (pwd);
  subroot = 
           1
               ;
  endpwent ();
  endgrent ();
  endspent ();

  endsgent ();

  goto top;
 }
 chown_tty (pwd);






 (void) signal (
               2
                     , 
                       ((__sighandler_t) 1)
                              );
 child = fork ();
 if (child < 0) {

  fprintf (
          stderr
                , gettext ("%s: failure forking: %s"),
           Prog, strerror (
                          (*__errno_location ())
                               ));
  { retcode = pam_close_session(pamh,0); (void) pam_end(pamh,retcode); };
  exit (0);
 } else if (child != 0) {




  wait (
       ((void *)0)
           );
  { retcode = pam_close_session(pamh,0); (void) pam_end(pamh,retcode); };
  exit (0);
 }




 if (getppid() == 1) {
  setsid();
  if (ioctl(0, 
              0x540E
                       , 1) != 0) {
   fprintf (
           stderr
                 , gettext ("TIOCSCTTY failed on %s"), tty);
  }
 }





 update_utmp (username, tty, hostname, utent);





 endpwent ();
 endgrent ();
 endspent ();

 endsgent ();
 if (change_uid (pwd))

 {
  exit (1);
 }

 setup_env (pwd);


 {
  const char *const *env;

  env = (const char *const *) pam_getenvlist (pamh);
  while ((
         ((void *)0) 
              != env) && (
                          ((void *)0) 
                               != *env)) {
   addenv (*env, 
                ((void *)0)
                    );
   env++;
  }
 }
 (void) pam_end (pamh, 
                      0 
                                  | 
                                    0x40000000
                                                   );


 (void) setlocale (
                  6
                        , "");
 (void) bindtextdomain ("shadow", "/usr/share/locale");
 (void) textdomain ("shadow");

 if (!hushed (username)) {
  addenv ("HUSHLOGIN=FALSE", 
                            ((void *)0)
                                );
 } else {
  addenv ("HUSHLOGIN=TRUE", 
                           ((void *)0)
                               );
 }

 ttytype (tty);

 (void) signal (
               3
                      , 
                        ((__sighandler_t) 0)
                               );
 (void) signal (
               15
                      , 
                        ((__sighandler_t) 0)
                               );
 (void) signal (
               14
                      , 
                        ((__sighandler_t) 0)
                               );
 (void) signal (
               1
                     , 
                       ((__sighandler_t) 0)
                              );
 (void) signal (
               2
                     , 
                       ((__sighandler_t) 0)
                              );

 if (0 == pwd->pw_uid) {
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
 5
 , "ROOT LOGIN %s", fromhost) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );
 } else if (getdef_bool ("LOG_OK_LOGINS")) {
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
 , "'%s' logged in %s", username, fromhost) ; if (
 ((void *)0) 
 != saved_locale) { (void) setlocale (
 6
 , saved_locale); free (saved_locale); } } while (
 0
 );
 }
 closelog ();
 tmp = getdef_str ("FAKE_SHELL");
 if (
    ((void *)0) 
         != tmp) {
  err = shell (tmp, pwd->pw_shell, newenvp);
 } else {

  err = shell (pwd->pw_shell, (char *) 0, newenvp);
 }

 return ((err == 
                2
                      ) ? 127 : 126);
}
