











































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








void *xmalloc(size_t);
void *xcalloc(size_t, size_t);
void *xreallocarray(void *, size_t, size_t);
void *xrecallocarray(void *, size_t, size_t, size_t);
char *xstrdup(const char *);
int xasprintf(char **, const char *, ...)
    __attribute__((__format__ (printf, 2, 3))) __attribute__((__nonnull__ (2)));
int xvasprintf(char **, const char *, va_list)
    __attribute__((__nonnull__ (2)));
struct passwd;

int sftp_server_main(int, char **, struct passwd *);
void sftp_server_cleanup_exit(int) __attribute__((noreturn));
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

int remote_glob(struct sftp_conn *, const char *, int,
    int (*)(const char *, int), _ssh_compat_glob_t *);

struct SFTP_OPENDIR {
 SFTP_DIRENT **dir;
 int offset;
};

static struct {
 struct sftp_conn *conn;
} cur;

static void *
fudge_opendir(const char *path)
{
 struct SFTP_OPENDIR *r;

 r = xcalloc(1, sizeof(*r));

 if (do_readdir(cur.conn, path, &r->dir)) {
  free(r);
  return(
        ((void *)0)
            );
 }

 r->offset = 0;

 return((void *)r);
}

static struct dirent *
fudge_readdir(struct SFTP_OPENDIR *od)
{

 static char buf[sizeof(struct dirent) + 
                                        4096
                                                  ];
 struct dirent *ret = (struct dirent *)buf;

 static int inum = 1;


 if (od->dir[od->offset] == 
                           ((void *)0)
                               )
  return(
        ((void *)0)
            );

 memset(buf, 0, sizeof(buf));
 strlcpy(ret->d_name, od->dir[od->offset++]->filename,
     sizeof(ret->d_name));







 ret->d_ino = inum++;
 if (!inum)
  inum = 1;


 return(ret);
}

static void
fudge_closedir(struct SFTP_OPENDIR *od)
{
 free_sftp_dirents(od->dir);
 free(od);
}

static int
fudge_lstat(const char *path, struct stat *st)
{
 Attrib *a;

 if (!(a = do_lstat(cur.conn, path, 1)))
  return(-1);

 attrib_to_stat(a, st);

 return(0);
}

static int
fudge_stat(const char *path, struct stat *st)
{
 Attrib *a;

 if (!(a = do_stat(cur.conn, path, 1)))
  return(-1);

 attrib_to_stat(a, st);

 return(0);
}

int
remote_glob(struct sftp_conn *conn, const char *pattern, int flags,
    int (*errfunc)(const char *, int), _ssh_compat_glob_t *pglob)
{
 pglob->gl_opendir = fudge_opendir;
 pglob->gl_readdir = (struct dirent *(*)(void *))fudge_readdir;
 pglob->gl_closedir = (void (*)(void *))fudge_closedir;
 pglob->gl_lstat = fudge_lstat;
 pglob->gl_stat = fudge_stat;

 memset(&cur, 0, sizeof(cur));
 cur.conn = conn;

 return(_ssh__compat_glob(pattern, flags | 0x0040, errfunc, pglob));
}
