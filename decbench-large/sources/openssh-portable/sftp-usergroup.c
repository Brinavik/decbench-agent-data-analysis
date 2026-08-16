











































void platform_pre_listen(void);
void platform_pre_fork(void);
void platform_pre_restart(void);
void platform_post_fork_parent(pid_t child_pid);
void platform_post_fork_child(void);
int platform_privileged_uidswap(void);
void platform_setusercontext(struct passwd *);
void platform_setusercontext_post_groups(struct passwd *);
char *platform_get_krb5_client(const char *);
char *platform_krb5_get_principal_name(const char *);
int platform_locked_account(struct passwd *);
int platform_sys_dir_uid(uid_t);
void platform_disable_tracing(int);


void platform_pledge_agent(void);
void platform_pledge_sftp_server(void);
void platform_pledge_mux(void);









int b64_ntop(u_char const *src, size_t srclength, char *target,
    size_t targsize);






int b64_pton(char const *src, u_char *target, size_t targsize);
char * readpassphrase(const char *, char *, size_t, int);
char *vis(char *, int, int, int);
int strvis(char *, const char *, int);
int stravis(char **, const char *, int);
int strnvis(char *, const char *, size_t, int)
  __attribute__ (());
int strvisx(char *, const char *, size_t, int)
  __attribute__ (());
int strunvis(char *, const char *);
int unvis(char *, char, int *, int);
ssize_t strnunvis(char *, const char *, size_t)
  __attribute__ (());

struct rdatainfo {
 unsigned int rdi_length;
 unsigned char *rdi_data;
};

struct rrsetinfo {
 unsigned int rri_flags;
 unsigned int rri_rdclass;
 unsigned int rri_rdtype;
 unsigned int rri_ttl;
 unsigned int rri_nrdatas;
 unsigned int rri_nsigs;
 char *rri_name;
 struct rdatainfo *rri_rdatas;
 struct rdatainfo *rri_sigs;
};

int getrrsetbyname(const char *, unsigned int, unsigned int, unsigned int, struct rrsetinfo **);
void freerrset(struct rrsetinfo *);
typedef struct BlowfishContext {
 u_int32_t S[4][256];
 u_int32_t P[16 + 2];
} blf_ctx;







void Blowfish_encipher(blf_ctx *, u_int32_t *, u_int32_t *);
void Blowfish_decipher(blf_ctx *, u_int32_t *, u_int32_t *);
void Blowfish_initstate(blf_ctx *);
void Blowfish_expand0state(blf_ctx *, const u_int8_t *, u_int16_t);
void Blowfish_expandstate
(blf_ctx *, const u_int8_t *, u_int16_t, const u_int8_t *, u_int16_t);



void blf_key(blf_ctx *, const u_int8_t *, u_int16_t);
void blf_enc(blf_ctx *, u_int32_t *, u_int16_t);
void blf_dec(blf_ctx *, u_int32_t *, u_int16_t);

void blf_ecb_encrypt(blf_ctx *, u_int8_t *, u_int32_t);
void blf_ecb_decrypt(blf_ctx *, u_int8_t *, u_int32_t);

void blf_cbc_encrypt(blf_ctx *, u_int8_t *, u_int8_t *, u_int32_t);
void blf_cbc_decrypt(blf_ctx *, u_int8_t *, u_int8_t *, u_int32_t);


u_int32_t Blowfish_stream2word(const u_int8_t *, u_int16_t , u_int16_t *);
int bindresvport_sa(int sd, struct sockaddr *sa);
void *memmem(const void *, size_t, const void *, size_t);







void *recallocarray(void *, size_t, size_t, size_t);







size_t strlcpy(char *dst, const char *src, size_t siz);



size_t strlcat(char *dst, const char *src, size_t siz);
void strmode(int mode, char *p);
int fmt_scaled(long long number, char *result);



int scan_scaled(char *, long long *);
void setproctitle(const char *fmt, ...);
void compat_init_setproctitle(int argc, char *argv[]);







int BSDgetopt(int argc, char * const *argv, const char *opts);
struct option {

 const char *name;




 int has_arg;

 int *flag;

 int val;
};

int getopt_long(int, char * const *, const char *,
     const struct option *, int *);
int getopt_long_only(int, char * const *, const char *,
     const struct option *, int *);


int BSDgetopt(int, char * const *, const char *);
int getsubopt(char **, char * const *, char **);

extern char *BSDoptarg;
extern int BSDopterr;
extern int BSDoptind;
extern int BSDoptopt;
extern int BSDoptreset;
extern char *suboptarg;
char *ssh_get_progname(char *);
int seed_from_prngd(unsigned char *, size_t);
int setlogin(const char *);
int pledge(const char *promises, const char *paths[]);



int getpeereid(int , uid_t *, gid_t *);



uint32_t arc4random(void);



void arc4random_buf(void *, size_t);







uint32_t arc4random_uniform(uint32_t);
long long strtonum(const char *, long long, long long, const char **);
char *user_from_uid(uid_t, int);



char *group_from_gid(gid_t, int);



int timingsafe_bcmp(const void *, const void *, size_t);



int bcrypt_pbkdf(const char *, size_t, const uint8_t *, size_t,
    uint8_t *, size_t, unsigned int);







void freezero(void *, size_t);
char *xcrypt(const char *password, const char *salt);
char *shadow_pw(struct passwd *pw);





void oom_adjust_restore(void);
void oom_adjust_setup(void);
void solaris_contract_pre_fork(void);
void solaris_contract_post_fork_child(void);
void solaris_contract_post_fork_parent(pid_t pid);
void solaris_set_default_project(struct passwd *);
struct Channel;
struct ssh;



int sys_tun_open(int, int, char **);




int sys_tun_infilter(struct ssh *, struct Channel *, char *, int);
u_char *sys_tun_outfilter(struct ssh *, struct Channel *, u_char **, size_t *);






char *sys_get_rdomain(int fd);
int sys_set_rdomain(int fd, const char *name);
int sys_valid_rdomain(const char *name);
void kludge_FD_SET(int, fd_set *);
int kludge_FD_ISSET(int, fd_set *);

struct sshbuf;

void seed_rng(void);
void rexec_send_rng_seed(struct sshbuf *);
void rexec_recv_rng_seed(struct sshbuf *);





const char *ssh_err(int n);


typedef enum {
 SYSLOG_FACILITY_DAEMON,
 SYSLOG_FACILITY_USER,
 SYSLOG_FACILITY_AUTH,



 SYSLOG_FACILITY_LOCAL0,
 SYSLOG_FACILITY_LOCAL1,
 SYSLOG_FACILITY_LOCAL2,
 SYSLOG_FACILITY_LOCAL3,
 SYSLOG_FACILITY_LOCAL4,
 SYSLOG_FACILITY_LOCAL5,
 SYSLOG_FACILITY_LOCAL6,
 SYSLOG_FACILITY_LOCAL7,
 SYSLOG_FACILITY_NOT_SET = -1
} SyslogFacility;

typedef enum {
 SYSLOG_LEVEL_QUIET,
 SYSLOG_LEVEL_FATAL,
 SYSLOG_LEVEL_ERROR,
 SYSLOG_LEVEL_INFO,
 SYSLOG_LEVEL_VERBOSE,
 SYSLOG_LEVEL_DEBUG1,
 SYSLOG_LEVEL_DEBUG2,
 SYSLOG_LEVEL_DEBUG3,
 SYSLOG_LEVEL_NOT_SET = -1
} LogLevel;

typedef void (log_handler_fn)(LogLevel, int, const char *, void *);

void log_init(const char *, LogLevel, SyslogFacility, int);
LogLevel log_level_get(void);
int log_change_level(LogLevel);
int log_is_on_stderr(void);
void log_redirect_stderr_to(const char *);
void log_verbose_add(const char *);
void log_verbose_reset(void);

SyslogFacility log_facility_number(char *);
const char * log_facility_name(SyslogFacility);
LogLevel log_level_number(char *);
const char * log_level_name(LogLevel);

void set_log_handler(log_handler_fn *, void *);
void cleanup_exit(int) __attribute__((noreturn));

void sshlog(const char *, const char *, int, int,
    LogLevel, const char *, const char *, ...)
    __attribute__((format(printf, 7, 8)));
void sshlogv(const char *, const char *, int, int,
    LogLevel, const char *, const char *, va_list);
void sshsigdie(const char *, const char *, int, int,
    LogLevel, const char *, const char *, ...) __attribute__((noreturn))
    __attribute__((format(printf, 7, 8)));
void sshlogdie(const char *, const char *, int, int,
    LogLevel, const char *, const char *, ...) __attribute__((noreturn))
    __attribute__((format(printf, 7, 8)));
void sshfatal(const char *, const char *, int, int,
    LogLevel, const char *, const char *, ...) __attribute__((noreturn))
    __attribute__((format(printf, 7, 8)));
void sshlogdirect(LogLevel, int, const char *, ...)
    __attribute__((format(printf, 3, 4)));
void *xmalloc(size_t);
void *xcalloc(size_t, size_t);
void *xreallocarray(void *, size_t, size_t);
void *xrecallocarray(void *, size_t, size_t, size_t);
char *xstrdup(const char *);
int xasprintf(char **, const char *, ...)
    __attribute__((__format__ (printf, 2, 3))) __attribute__((__nonnull__ (2)));
int xvasprintf(char **, const char *, va_list)
    __attribute__((__nonnull__ (2)));

struct sshbuf;
typedef struct Attrib Attrib;


struct Attrib {
 u_int32_t flags;
 u_int64_t size;
 u_int32_t uid;
 u_int32_t gid;
 u_int32_t perm;
 u_int32_t atime;
 u_int32_t mtime;
};

void attrib_clear(Attrib *);
void stat_to_attrib(const struct stat *, Attrib *);
void attrib_to_stat(const Attrib *, struct stat *);
int decode_attrib(struct sshbuf *, Attrib *);
int encode_attrib(struct sshbuf *, const Attrib *);
char *ls_file(const char *, const struct stat *, int, int,
    const char *, const char *);

const char *fx2txt(int);
struct stat;
typedef struct {
 size_t gl_pathc;
 size_t gl_matchc;
 size_t gl_offs;
 int gl_flags;
 char **gl_pathv;
 struct stat **gl_statv;

 int (*gl_errfunc)(const char *, int);






 void (*gl_closedir)(void *);
 struct dirent *(*gl_readdir)(void *);
 void *(*gl_opendir)(const char *);
 int (*gl_lstat)(const char *, struct stat *);
 int (*gl_stat)(const char *, struct stat *);
} _ssh_compat_glob_t;
int _ssh__compat_glob(const char *, int, int (*)(const char *, int), _ssh_compat_glob_t *);
void _ssh__compat_globfree(_ssh_compat_glob_t *);


typedef struct SFTP_DIRENT SFTP_DIRENT;

struct SFTP_DIRENT {
 char *filename;
 char *longname;
 Attrib a;
};





struct sftp_statvfs {
 u_int64_t f_bsize;
 u_int64_t f_frsize;
 u_int64_t f_blocks;
 u_int64_t f_bfree;
 u_int64_t f_bavail;
 u_int64_t f_files;
 u_int64_t f_ffree;
 u_int64_t f_favail;
 u_int64_t f_fsid;
 u_int64_t f_flag;
 u_int64_t f_namemax;
};


struct sftp_limits {
 u_int64_t packet_length;
 u_int64_t read_length;
 u_int64_t write_length;
 u_int64_t open_handles;
};
struct sftp_conn *do_init(int, int, u_int, u_int, u_int64_t);

u_int sftp_proto_version(struct sftp_conn *);


int do_limits(struct sftp_conn *, struct sftp_limits *);


int do_close(struct sftp_conn *, const u_char *, u_int);


int do_readdir(struct sftp_conn *, const char *, SFTP_DIRENT ***);


void free_sftp_dirents(SFTP_DIRENT **);


int do_rm(struct sftp_conn *, const char *);


int do_mkdir(struct sftp_conn *, const char *, Attrib *, int);


int do_rmdir(struct sftp_conn *, const char *);


Attrib *do_stat(struct sftp_conn *, const char *, int);


Attrib *do_lstat(struct sftp_conn *, const char *, int);


int do_setstat(struct sftp_conn *, const char *, Attrib *);


int do_fsetstat(struct sftp_conn *, const u_char *, u_int, Attrib *);


int do_lsetstat(struct sftp_conn *conn, const char *path, Attrib *a);


char *do_realpath(struct sftp_conn *, const char *);


char *do_expand_path(struct sftp_conn *, const char *);


int can_expand_path(struct sftp_conn *);


int do_statvfs(struct sftp_conn *, const char *, struct sftp_statvfs *, int);


int do_rename(struct sftp_conn *, const char *, const char *, int);


int do_copy(struct sftp_conn *, const char *, const char *);


int do_hardlink(struct sftp_conn *, const char *, const char *);


int do_symlink(struct sftp_conn *, const char *, const char *);


int do_fsync(struct sftp_conn *conn, u_char *, u_int);





int do_download(struct sftp_conn *, const char *, const char *, Attrib *,
    int, int, int, int);





int download_dir(struct sftp_conn *, const char *, const char *, Attrib *,
    int, int, int, int, int, int);





int do_upload(struct sftp_conn *, const char *, const char *,
    int, int, int, int);





int upload_dir(struct sftp_conn *, const char *, const char *,
    int, int, int, int, int, int);





int
do_crossload(struct sftp_conn *from, struct sftp_conn *to,
    const char *from_path, const char *to_path,
    Attrib *a, int preserve_flag);





int crossload_dir(struct sftp_conn *from, struct sftp_conn *to,
    const char *from_path, const char *to_path,
    Attrib *dirattrib, int preserve_flag, int print_flag,
    int follow_link_flag);




int can_get_users_groups_by_id(struct sftp_conn *conn);
int do_get_users_groups_by_id(struct sftp_conn *conn,
    const u_int *uids, u_int nuids,
    const u_int *gids, u_int ngids,
    char ***usernamesp, char ***groupnamesp);


char *path_append(const char *, const char *);



char *make_absolute(char *, const char *);


int remote_is_dir(struct sftp_conn *conn, const char *path);


int local_is_dir(const char *path);


int globpath_is_dir(const char *pathname);
void get_remote_user_groups_from_glob(struct sftp_conn *conn, _ssh_compat_glob_t *g);
void get_remote_user_groups_from_dirents(struct sftp_conn *conn, SFTP_DIRENT **d);


const char *ruser_name(uid_t uid);
const char *rgroup_name(uid_t gid);


struct idname {
        u_int id;
 char *name;
        struct { struct idname *rbe_left; struct idname *rbe_right; struct idname *rbe_parent; int rbe_color; } entry;

};
static int
idname_cmp(struct idname *a, struct idname *b)
{
 if (a->id == b->id)
  return 0;
 return a->id > b->id ? 1 : -1;
}
struct idname_tree { struct idname *rbh_root; };
__attribute__((__unused__)) static void idname_tree_RB_INSERT_COLOR(struct idname_tree *head, struct idname *elm) { struct idname *parent, *gparent, *tmp; while ((parent = (elm)->entry.rbe_parent) && (parent)->entry.rbe_color == 1) { gparent = (parent)->entry.rbe_parent; if (parent == (gparent)->entry.rbe_left) { tmp = (gparent)->entry.rbe_right; if (tmp && (tmp)->entry.rbe_color == 1) { (tmp)->entry.rbe_color = 0; do { (parent)->entry.rbe_color = 0; (gparent)->entry.rbe_color = 1; } while (0); elm = gparent; continue; } if ((parent)->entry.rbe_right == elm) { do { (tmp) = (parent)->entry.rbe_right; if (((parent)->entry.rbe_right = (tmp)->entry.rbe_left)) { ((tmp)->entry.rbe_left)->entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->entry.rbe_parent = (parent)->entry.rbe_parent)) { if ((parent) == ((parent)->entry.rbe_parent)->entry.rbe_left) ((parent)->entry.rbe_parent)->entry.rbe_left = (tmp); else ((parent)->entry.rbe_parent)->entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->entry.rbe_left = (parent); (parent)->entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->entry.rbe_parent)) do {} while (0); } while (0); tmp = parent; parent = elm; elm = tmp; } do { (parent)->entry.rbe_color = 0; (gparent)->entry.rbe_color = 1; } while (0); do { (tmp) = (gparent)->entry.rbe_left; if (((gparent)->entry.rbe_left = (tmp)->entry.rbe_right)) { ((tmp)->entry.rbe_right)->entry.rbe_parent = (gparent); } do {} while (0); if (((tmp)->entry.rbe_parent = (gparent)->entry.rbe_parent)) { if ((gparent) == ((gparent)->entry.rbe_parent)->entry.rbe_left) ((gparent)->entry.rbe_parent)->entry.rbe_left = (tmp); else ((gparent)->entry.rbe_parent)->entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->entry.rbe_right = (gparent); (gparent)->entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->entry.rbe_parent)) do {} while (0); } while (0); } else { tmp = (gparent)->entry.rbe_left; if (tmp && (tmp)->entry.rbe_color == 1) { (tmp)->entry.rbe_color = 0; do { (parent)->entry.rbe_color = 0; (gparent)->entry.rbe_color = 1; } while (0); elm = gparent; continue; } if ((parent)->entry.rbe_left == elm) { do { (tmp) = (parent)->entry.rbe_left; if (((parent)->entry.rbe_left = (tmp)->entry.rbe_right)) { ((tmp)->entry.rbe_right)->entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->entry.rbe_parent = (parent)->entry.rbe_parent)) { if ((parent) == ((parent)->entry.rbe_parent)->entry.rbe_left) ((parent)->entry.rbe_parent)->entry.rbe_left = (tmp); else ((parent)->entry.rbe_parent)->entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->entry.rbe_right = (parent); (parent)->entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->entry.rbe_parent)) do {} while (0); } while (0); tmp = parent; parent = elm; elm = tmp; } do { (parent)->entry.rbe_color = 0; (gparent)->entry.rbe_color = 1; } while (0); do { (tmp) = (gparent)->entry.rbe_right; if (((gparent)->entry.rbe_right = (tmp)->entry.rbe_left)) { ((tmp)->entry.rbe_left)->entry.rbe_parent = (gparent); } do {} while (0); if (((tmp)->entry.rbe_parent = (gparent)->entry.rbe_parent)) { if ((gparent) == ((gparent)->entry.rbe_parent)->entry.rbe_left) ((gparent)->entry.rbe_parent)->entry.rbe_left = (tmp); else ((gparent)->entry.rbe_parent)->entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->entry.rbe_left = (gparent); (gparent)->entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->entry.rbe_parent)) do {} while (0); } while (0); } } (head->rbh_root)->entry.rbe_color = 0; } __attribute__((__unused__)) static void idname_tree_RB_REMOVE_COLOR(struct idname_tree *head, struct idname *parent, struct idname *elm) { struct idname *tmp; while ((elm == 
((void *)0) 
|| (elm)->entry.rbe_color == 0) && elm != (head)->rbh_root) { if ((parent)->entry.rbe_left == elm) { tmp = (parent)->entry.rbe_right; if ((tmp)->entry.rbe_color == 1) { do { (tmp)->entry.rbe_color = 0; (parent)->entry.rbe_color = 1; } while (0); do { (tmp) = (parent)->entry.rbe_right; if (((parent)->entry.rbe_right = (tmp)->entry.rbe_left)) { ((tmp)->entry.rbe_left)->entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->entry.rbe_parent = (parent)->entry.rbe_parent)) { if ((parent) == ((parent)->entry.rbe_parent)->entry.rbe_left) ((parent)->entry.rbe_parent)->entry.rbe_left = (tmp); else ((parent)->entry.rbe_parent)->entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->entry.rbe_left = (parent); (parent)->entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->entry.rbe_parent)) do {} while (0); } while (0); tmp = (parent)->entry.rbe_right; } if (((tmp)->entry.rbe_left == 
((void *)0) 
|| ((tmp)->entry.rbe_left)->entry.rbe_color == 0) && ((tmp)->entry.rbe_right == 
((void *)0) 
|| ((tmp)->entry.rbe_right)->entry.rbe_color == 0)) { (tmp)->entry.rbe_color = 1; elm = parent; parent = (elm)->entry.rbe_parent; } else { if ((tmp)->entry.rbe_right == 
((void *)0) 
|| ((tmp)->entry.rbe_right)->entry.rbe_color == 0) { struct idname *oleft; if ((oleft = (tmp)->entry.rbe_left)) (oleft)->entry.rbe_color = 0; (tmp)->entry.rbe_color = 1; do { (oleft) = (tmp)->entry.rbe_left; if (((tmp)->entry.rbe_left = (oleft)->entry.rbe_right)) { ((oleft)->entry.rbe_right)->entry.rbe_parent = (tmp); } do {} while (0); if (((oleft)->entry.rbe_parent = (tmp)->entry.rbe_parent)) { if ((tmp) == ((tmp)->entry.rbe_parent)->entry.rbe_left) ((tmp)->entry.rbe_parent)->entry.rbe_left = (oleft); else ((tmp)->entry.rbe_parent)->entry.rbe_right = (oleft); } else (head)->rbh_root = (oleft); (oleft)->entry.rbe_right = (tmp); (tmp)->entry.rbe_parent = (oleft); do {} while (0); if (((oleft)->entry.rbe_parent)) do {} while (0); } while (0); tmp = (parent)->entry.rbe_right; } (tmp)->entry.rbe_color = (parent)->entry.rbe_color; (parent)->entry.rbe_color = 0; if ((tmp)->entry.rbe_right) ((tmp)->entry.rbe_right)->entry.rbe_color = 0; do { (tmp) = (parent)->entry.rbe_right; if (((parent)->entry.rbe_right = (tmp)->entry.rbe_left)) { ((tmp)->entry.rbe_left)->entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->entry.rbe_parent = (parent)->entry.rbe_parent)) { if ((parent) == ((parent)->entry.rbe_parent)->entry.rbe_left) ((parent)->entry.rbe_parent)->entry.rbe_left = (tmp); else ((parent)->entry.rbe_parent)->entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->entry.rbe_left = (parent); (parent)->entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->entry.rbe_parent)) do {} while (0); } while (0); elm = (head)->rbh_root; break; } } else { tmp = (parent)->entry.rbe_left; if ((tmp)->entry.rbe_color == 1) { do { (tmp)->entry.rbe_color = 0; (parent)->entry.rbe_color = 1; } while (0); do { (tmp) = (parent)->entry.rbe_left; if (((parent)->entry.rbe_left = (tmp)->entry.rbe_right)) { ((tmp)->entry.rbe_right)->entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->entry.rbe_parent = (parent)->entry.rbe_parent)) { if ((parent) == ((parent)->entry.rbe_parent)->entry.rbe_left) ((parent)->entry.rbe_parent)->entry.rbe_left = (tmp); else ((parent)->entry.rbe_parent)->entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->entry.rbe_right = (parent); (parent)->entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->entry.rbe_parent)) do {} while (0); } while (0); tmp = (parent)->entry.rbe_left; } if (((tmp)->entry.rbe_left == 
((void *)0) 
|| ((tmp)->entry.rbe_left)->entry.rbe_color == 0) && ((tmp)->entry.rbe_right == 
((void *)0) 
|| ((tmp)->entry.rbe_right)->entry.rbe_color == 0)) { (tmp)->entry.rbe_color = 1; elm = parent; parent = (elm)->entry.rbe_parent; } else { if ((tmp)->entry.rbe_left == 
((void *)0) 
|| ((tmp)->entry.rbe_left)->entry.rbe_color == 0) { struct idname *oright; if ((oright = (tmp)->entry.rbe_right)) (oright)->entry.rbe_color = 0; (tmp)->entry.rbe_color = 1; do { (oright) = (tmp)->entry.rbe_right; if (((tmp)->entry.rbe_right = (oright)->entry.rbe_left)) { ((oright)->entry.rbe_left)->entry.rbe_parent = (tmp); } do {} while (0); if (((oright)->entry.rbe_parent = (tmp)->entry.rbe_parent)) { if ((tmp) == ((tmp)->entry.rbe_parent)->entry.rbe_left) ((tmp)->entry.rbe_parent)->entry.rbe_left = (oright); else ((tmp)->entry.rbe_parent)->entry.rbe_right = (oright); } else (head)->rbh_root = (oright); (oright)->entry.rbe_left = (tmp); (tmp)->entry.rbe_parent = (oright); do {} while (0); if (((oright)->entry.rbe_parent)) do {} while (0); } while (0); tmp = (parent)->entry.rbe_left; } (tmp)->entry.rbe_color = (parent)->entry.rbe_color; (parent)->entry.rbe_color = 0; if ((tmp)->entry.rbe_left) ((tmp)->entry.rbe_left)->entry.rbe_color = 0; do { (tmp) = (parent)->entry.rbe_left; if (((parent)->entry.rbe_left = (tmp)->entry.rbe_right)) { ((tmp)->entry.rbe_right)->entry.rbe_parent = (parent); } do {} while (0); if (((tmp)->entry.rbe_parent = (parent)->entry.rbe_parent)) { if ((parent) == ((parent)->entry.rbe_parent)->entry.rbe_left) ((parent)->entry.rbe_parent)->entry.rbe_left = (tmp); else ((parent)->entry.rbe_parent)->entry.rbe_right = (tmp); } else (head)->rbh_root = (tmp); (tmp)->entry.rbe_right = (parent); (parent)->entry.rbe_parent = (tmp); do {} while (0); if (((tmp)->entry.rbe_parent)) do {} while (0); } while (0); elm = (head)->rbh_root; break; } } } if (elm) (elm)->entry.rbe_color = 0; } __attribute__((__unused__)) static struct idname * idname_tree_RB_REMOVE(struct idname_tree *head, struct idname *elm) { struct idname *child, *parent, *old = elm; int color; if ((elm)->entry.rbe_left == 
((void *)0)
) child = (elm)->entry.rbe_right; else if ((elm)->entry.rbe_right == 
((void *)0)
) child = (elm)->entry.rbe_left; else { struct idname *left; elm = (elm)->entry.rbe_right; while ((left = (elm)->entry.rbe_left)) elm = left; child = (elm)->entry.rbe_right; parent = (elm)->entry.rbe_parent; color = (elm)->entry.rbe_color; if (child) (child)->entry.rbe_parent = parent; if (parent) { if ((parent)->entry.rbe_left == elm) (parent)->entry.rbe_left = child; else (parent)->entry.rbe_right = child; do {} while (0); } else (head)->rbh_root = child; if ((elm)->entry.rbe_parent == old) parent = elm; (elm)->entry = (old)->entry; if ((old)->entry.rbe_parent) { if (((old)->entry.rbe_parent)->entry.rbe_left == old) ((old)->entry.rbe_parent)->entry.rbe_left = elm; else ((old)->entry.rbe_parent)->entry.rbe_right = elm; do {} while (0); } else (head)->rbh_root = elm; ((old)->entry.rbe_left)->entry.rbe_parent = elm; if ((old)->entry.rbe_right) ((old)->entry.rbe_right)->entry.rbe_parent = elm; if (parent) { left = parent; do { do {} while (0); } while ((left = (left)->entry.rbe_parent)); } goto color; } parent = (elm)->entry.rbe_parent; color = (elm)->entry.rbe_color; if (child) (child)->entry.rbe_parent = parent; if (parent) { if ((parent)->entry.rbe_left == elm) (parent)->entry.rbe_left = child; else (parent)->entry.rbe_right = child; do {} while (0); } else (head)->rbh_root = child; color: if (color == 0) idname_tree_RB_REMOVE_COLOR(head, parent, child); return (old); } __attribute__((__unused__)) static struct idname * idname_tree_RB_INSERT(struct idname_tree *head, struct idname *elm) { struct idname *tmp; struct idname *parent = 
((void *)0)
; int comp = 0; tmp = (head)->rbh_root; while (tmp) { parent = tmp; comp = (idname_cmp)(elm, parent); if (comp < 0) tmp = (tmp)->entry.rbe_left; else if (comp > 0) tmp = (tmp)->entry.rbe_right; else return (tmp); } do { (elm)->entry.rbe_parent = parent; (elm)->entry.rbe_left = (elm)->entry.rbe_right = 
((void *)0)
; (elm)->entry.rbe_color = 1; } while (0); if (parent != 
((void *)0)
) { if (comp < 0) (parent)->entry.rbe_left = elm; else (parent)->entry.rbe_right = elm; do {} while (0); } else (head)->rbh_root = elm; idname_tree_RB_INSERT_COLOR(head, elm); return (
((void *)0)
); } __attribute__((__unused__)) static struct idname * idname_tree_RB_FIND(struct idname_tree *head, struct idname *elm) { struct idname *tmp = (head)->rbh_root; int comp; while (tmp) { comp = idname_cmp(elm, tmp); if (comp < 0) tmp = (tmp)->entry.rbe_left; else if (comp > 0) tmp = (tmp)->entry.rbe_right; else return (tmp); } return (
((void *)0)
); } __attribute__((__unused__)) static struct idname * idname_tree_RB_NFIND(struct idname_tree *head, struct idname *elm) { struct idname *tmp = (head)->rbh_root; struct idname *res = 
((void *)0)
; int comp; while (tmp) { comp = idname_cmp(elm, tmp); if (comp < 0) { res = tmp; tmp = (tmp)->entry.rbe_left; } else if (comp > 0) tmp = (tmp)->entry.rbe_right; else return (tmp); } return (res); } __attribute__((__unused__)) static struct idname * idname_tree_RB_NEXT(struct idname *elm) { if ((elm)->entry.rbe_right) { elm = (elm)->entry.rbe_right; while ((elm)->entry.rbe_left) elm = (elm)->entry.rbe_left; } else { if ((elm)->entry.rbe_parent && (elm == ((elm)->entry.rbe_parent)->entry.rbe_left)) elm = (elm)->entry.rbe_parent; else { while ((elm)->entry.rbe_parent && (elm == ((elm)->entry.rbe_parent)->entry.rbe_right)) elm = (elm)->entry.rbe_parent; elm = (elm)->entry.rbe_parent; } } return (elm); } __attribute__((__unused__)) static struct idname * idname_tree_RB_PREV(struct idname *elm) { if ((elm)->entry.rbe_left) { elm = (elm)->entry.rbe_left; while ((elm)->entry.rbe_right) elm = (elm)->entry.rbe_right; } else { if ((elm)->entry.rbe_parent && (elm == ((elm)->entry.rbe_parent)->entry.rbe_right)) elm = (elm)->entry.rbe_parent; else { while ((elm)->entry.rbe_parent && (elm == ((elm)->entry.rbe_parent)->entry.rbe_left)) elm = (elm)->entry.rbe_parent; elm = (elm)->entry.rbe_parent; } } return (elm); } __attribute__((__unused__)) static struct idname * idname_tree_RB_MINMAX(struct idname_tree *head, int val) { struct idname *tmp = (head)->rbh_root; struct idname *parent = 
((void *)0)
; while (tmp) { parent = tmp; if (val < 0) tmp = (tmp)->entry.rbe_left; else tmp = (tmp)->entry.rbe_right; } return (parent); }

static struct idname_tree user_idname = { 
                                       ((void *)0) 
                                       };
static struct idname_tree group_idname = { 
                                        ((void *)0) 
                                        };

static void
idname_free(struct idname *idname)
{
 if (idname == 
              ((void *)0)
                  )
  return;
 free(idname->name);
 free(idname);
}

static void
idname_enter(struct idname_tree *tree, u_int id, const char *name)
{
 struct idname *idname;

 if ((idname = xcalloc(1, sizeof(*idname))) == 
                                              ((void *)0)
                                                  )
  sshfatal("sftp-usergroup.c", __func__, 70, 1, SYSLOG_LEVEL_FATAL, 
 ((void *)0)
 , "alloc");
 idname->id = id;
 idname->name = xstrdup(name);
 if (idname_tree_RB_INSERT(tree, idname) != 
                                            ((void *)0)
                                                )
  idname_free(idname);
}

static const char *
idname_lookup(struct idname_tree *tree, u_int id)
{
 struct idname idname, *found;

 memset(&idname, 0, sizeof(idname));
 idname.id = id;
 if ((found = idname_tree_RB_FIND(tree, &idname)) != 
                                                     ((void *)0)
                                                         )
  return found->name;
 return 
       ((void *)0)
           ;
}

static void
freenames(char **names, u_int nnames)
{
 u_int i;

 if (names == 
             ((void *)0)
                 )
  return;
 for (i = 0; i < nnames; i++)
  free(names[i]);
 free(names);
}

static void
lookup_and_record(struct sftp_conn *conn,
    u_int *uids, u_int nuids, u_int *gids, u_int ngids)
{
 int r;
 u_int i;
 char **usernames = 
                   ((void *)0)
                       , **groupnames = 
                                        ((void *)0)
                                            ;

 if ((r = do_get_users_groups_by_id(conn, uids, nuids, gids, ngids,
     &usernames, &groupnames)) != 0) {
  sshlog("sftp-usergroup.c", __func__, 111, 1, SYSLOG_LEVEL_DEBUG1, ssh_err(r), "do_get_users_groups_by_id");
  return;
 }
 for (i = 0; i < nuids; i++) {
  if (usernames[i] == 
                     ((void *)0)
                         ) {
   sshlog("sftp-usergroup.c", __func__, 116, 1, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "uid %u not resolved", uids[i]);
   continue;
  }
  sshlog("sftp-usergroup.c", __func__, 119, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "record uid %u => \"%s\"", uids[i], usernames[i]);
  idname_enter(&user_idname, uids[i], usernames[i]);
 }
 for (i = 0; i < ngids; i++) {
  if (groupnames[i] == 
                      ((void *)0)
                          ) {
   sshlog("sftp-usergroup.c", __func__, 124, 1, SYSLOG_LEVEL_DEBUG3, 
  ((void *)0)
  , "gid %u not resolved", gids[i]);
   continue;
  }
  sshlog("sftp-usergroup.c", __func__, 127, 1, SYSLOG_LEVEL_DEBUG3, 
 ((void *)0)
 , "record gid %u => \"%s\"", gids[i], groupnames[i]);
  idname_enter(&group_idname, gids[i], groupnames[i]);
 }
 freenames(usernames, nuids);
 freenames(groupnames, ngids);
}

static int
has_id(u_int id, u_int *ids, u_int nids)
{
 u_int i;

 if (nids == 0)
  return 0;


 for (i = 0; i < nids; i++) {
  if (ids[i] == id)
   break;
 }
 return i < nids;
}

static void
collect_ids_from_glob(_ssh_compat_glob_t *g, int user, u_int **idsp, u_int *nidsp)
{
 u_int id, i, n = 0, *ids = 
                           ((void *)0)
                               ;

 for (i = 0; g->gl_pathv[i] != 
                              ((void *)0)
                                  ; i++) {
  if (user) {
   if (ruser_name(g->gl_statv[i]->st_uid) != 
                                            ((void *)0)
                                                )
    continue;
   id = (u_int)g->gl_statv[i]->st_uid;
  } else {
   if (rgroup_name(g->gl_statv[i]->st_gid) != 
                                             ((void *)0)
                                                 )
    continue;
   id = (u_int)g->gl_statv[i]->st_gid;
  }
  if (has_id(id, ids, n))
   continue;
  ids = xrecallocarray(ids, n, n + 1, sizeof(*ids));
  ids[n++] = id;
 }
 *idsp = ids;
 *nidsp = n;
}

void
get_remote_user_groups_from_glob(struct sftp_conn *conn, _ssh_compat_glob_t *g)
{
 u_int *uids = 
              ((void *)0)
                  , nuids = 0, *gids = 
                                       ((void *)0)
                                           , ngids = 0;

 if (!can_get_users_groups_by_id(conn))
  return;

 collect_ids_from_glob(g, 1, &uids, &nuids);
 collect_ids_from_glob(g, 0, &gids, &ngids);
 lookup_and_record(conn, uids, nuids, gids, ngids);
 free(uids);
 free(gids);
}

static void
collect_ids_from_dirents(SFTP_DIRENT **d, int user, u_int **idsp, u_int *nidsp)
{
 u_int id, i, n = 0, *ids = 
                           ((void *)0)
                               ;

 for (i = 0; d[i] != 
                    ((void *)0)
                        ; i++) {
  if (user) {
   if (ruser_name((uid_t)(d[i]->a.uid)) != 
                                          ((void *)0)
                                              )
    continue;
   id = d[i]->a.uid;
  } else {
   if (rgroup_name((gid_t)(d[i]->a.gid)) != 
                                           ((void *)0)
                                               )
    continue;
   id = d[i]->a.gid;
  }
  if (has_id(id, ids, n))
   continue;
  ids = xrecallocarray(ids, n, n + 1, sizeof(*ids));
  ids[n++] = id;
 }
 *idsp = ids;
 *nidsp = n;
}

void
get_remote_user_groups_from_dirents(struct sftp_conn *conn, SFTP_DIRENT **d)
{
 u_int *uids = 
              ((void *)0)
                  , nuids = 0, *gids = 
                                       ((void *)0)
                                           , ngids = 0;

 if (!can_get_users_groups_by_id(conn))
  return;

 collect_ids_from_dirents(d, 1, &uids, &nuids);
 collect_ids_from_dirents(d, 0, &gids, &ngids);
 lookup_and_record(conn, uids, nuids, gids, ngids);
 free(uids);
 free(gids);
}

const char *
ruser_name(uid_t uid)
{
 return idname_lookup(&user_idname, (u_int)uid);
}

const char *
rgroup_name(uid_t gid)
{
 return idname_lookup(&group_idname, (u_int)gid);
}
