





__inline





static const char *
pgettext_aux (const char *domain,
       const char *msg_ctxt_id, const char *msgid,
       int category)
{
  const char *translation = dcgettext (domain, msg_ctxt_id, category);
  if (translation == msg_ctxt_id)
    return msgid;
  else
    return translation;
}


__inline





static const char *
npgettext_aux (const char *domain,
        const char *msg_ctxt_id, const char *msgid,
        const char *msgid_plural, unsigned long int n,
        int category)
{
  const char *translation =
    dcngettext (domain, msg_ctxt_id, msgid_plural, n, category);
  if (translation == msg_ctxt_id || translation == msgid_plural)
    return (n == 1 ? msgid : msgid_plural);
  else
    return translation;
}
__inline





static const char *
dcpgettext_expr (const char *domain,
   const char *msgctxt, const char *msgid,
   int category)
{
  size_t msgctxt_len = strlen (msgctxt) + 1;
  size_t msgid_len = strlen (msgid) + 1;
  const char *translation;

  char msg_ctxt_id[msgctxt_len + msgid_len];
    {
      memcpy (msg_ctxt_id, msgctxt, msgctxt_len - 1);
      msg_ctxt_id[msgctxt_len - 1] = '\004';
      memcpy (msg_ctxt_id + msgctxt_len, msgid, msgid_len);
      translation = dcgettext (domain, msg_ctxt_id, category);




      if (translation != msg_ctxt_id)
 return translation;
    }
  return msgid;
}







__inline





static const char *
dcnpgettext_expr (const char *domain,
    const char *msgctxt, const char *msgid,
    const char *msgid_plural, unsigned long int n,
    int category)
{
  size_t msgctxt_len = strlen (msgctxt) + 1;
  size_t msgid_len = strlen (msgid) + 1;
  const char *translation;

  char msg_ctxt_id[msgctxt_len + msgid_len];
    {
      memcpy (msg_ctxt_id, msgctxt, msgctxt_len - 1);
      msg_ctxt_id[msgctxt_len - 1] = '\004';
      memcpy (msg_ctxt_id + msgctxt_len, msgid, msgid_len);
      translation = dcngettext (domain, msg_ctxt_id, msgid_plural, n, category);




      if (!(translation == msg_ctxt_id || translation == msgid_plural))
 return translation;
    }
  return (n == 1 ? msgid : msgid_plural);
}







void dpkg_locales_init(const char *package);
void dpkg_locales_done(void);

struct dpkg_locale {
 void *oldloc;
};

struct dpkg_locale dpkg_locale_switch_C(void);
void dpkg_locale_switch_back(struct dpkg_locale loc);

















void dpkg_set_progname(const char *name);
const char *dpkg_get_progname(void);
















extern volatile int onerr_abort;

enum {
 ehflag_normaltidy = (1UL << (0)),
 ehflag_bombout = (1UL << (1)),
 ehflag_recursiveerror = (1UL << (2)),
};

typedef void error_handler_func(void);
typedef void error_printer_func(const char *emsg, const void *data);

void print_fatal_error(const char *emsg, const void *data);
void catch_fatal_error(void);

void push_error_context_jump(jmp_buf *jumper,
                             error_printer_func *printer,
                             const void *printer_data);
void push_error_context_func(error_handler_func *handler,
                             error_printer_func *printer,
                             const void *printer_data);
void push_error_context(void);
void pop_error_context(int flagset);

void push_cleanup_fallback(void (*f1)(int argc, void **argv), int flagmask1,
                           void (*f2)(int argc, void **argv), int flagmask2,
                           unsigned int nargs, ...);
void push_cleanup(void (*call)(int argc, void **argv), int flagmask,
                  unsigned int nargs, ...);
void push_checkpoint(int mask, int value);
void pop_cleanup(int flagset);

void ohshitv(const char *fmt, va_list args)
 __attribute__((noreturn)) __attribute__((format(printf, 1, 0)));
void ohshit(const char *fmt, ...) __attribute__((noreturn)) __attribute__((format(printf, 1, 1 + 1)));
void ohshite(const char *fmt, ...) __attribute__((noreturn)) __attribute__((format(printf, 1, 1 + 1)));

void do_internerr(const char *file, int line, const char *func,
                  const char *fmt, ...)
 __attribute__((noreturn)) __attribute__((format(printf, 4, 4 + 1)));













void dpkg_set_report_piped_mode(int mode);
void dpkg_set_report_buffer(FILE *fp);

typedef void dpkg_warning_printer_func(const char *msg, void *data);

void dpkg_warning_printer(const char *msg, void *data);
void dpkg_set_warning_printer(dpkg_warning_printer_func *printer, void *data);

int warning_get_count(void);
void warningv(const char *fmt, va_list args) __attribute__((format(printf, 1, 0)));
void warning(const char *fmt, ...) __attribute__((format(printf, 1, 1 + 1)));

void notice(const char *fmt, ...) __attribute__((format(printf, 1, 1 + 1)));

void info(const char *fmt, ...) __attribute__((format(printf, 1, 1 + 1)));








static inline 
             _Bool

str_is_unset(const char *str)
{
 return str == 
              ((void *)0) 
                        || str[0] == '\0';
}




static inline 
             _Bool

str_is_set(const char *str)
{
 return str != 
              ((void *)0) 
                        && str[0] != '\0';
}


_Bool 
    str_match_end(const char *str, const char *end);

unsigned int str_fnv_hash(const char *str);

char *str_concat(char *dst, ...) __attribute__((sentinel));
char *str_fmt(const char *fmt, ...) __attribute__((format(printf, 1, 1 + 1)));
char *str_escape_fmt(char *dest, const char *src, size_t n);
char *str_quote_meta(const char *src);
char *str_strip_quotes(char *str);
char *str_rtrim_spaces(const char *str, char *str_end);

struct str_crop_info {
 int str_bytes;
 int max_bytes;
};

int str_width(const char *str);
void str_gen_crop(const char *str, int max_width, struct str_crop_info *crop);












void dpkg_program_init(const char *progname);
void dpkg_program_done(void);







extern const char *log_file;
void log_message(const char *fmt, ...) __attribute__((format(printf, 1, 1 + 1)));

void statusfd_add(int fd);
void statusfd_send(const char *fmt, ...) __attribute__((format(printf, 1, 1 + 1)));



void cu_closestream(int argc, void **argv);
void cu_closepipe(int argc, void **argv);
void cu_closedir(int argc, void **argv);
void cu_closefd(int argc, void **argv);
void cu_filename(int argc, void **argv);



void setcloexec(int fd, const char *fn);
void *m_malloc(size_t);
void *m_calloc(size_t nmemb, size_t size);
void *m_realloc(void *, size_t);
char *m_strdup(const char *str);
char *m_strndup(const char *str, size_t n);
int m_asprintf(char **strp, const char *fmt, ...) __attribute__((format(printf, 2, 2 + 1)));
int m_vasprintf(char **strp, const char *fmt, va_list args)
 __attribute__((format(printf, 2, 0)));
int m_dup(int oldfd);
void m_dup2(int oldfd, int newfd);
void m_pipe(int fds[2]);
void m_output(FILE *f, const char *name);



int fgets_checked(char *buf, size_t bufsz, FILE *f, const char *fn);
int fgets_must(char *buf, size_t bufsz, FILE *f, const char *fn);








struct varbuf {
 size_t used, size;
 char *buf;
};





struct varbuf *varbuf_new(size_t size);
void varbuf_init(struct varbuf *v, size_t size);
void varbuf_grow(struct varbuf *v, size_t need_size);
void varbuf_trunc(struct varbuf *v, size_t used_size);
char *varbuf_detach(struct varbuf *v);
void varbuf_reset(struct varbuf *v);
void varbuf_destroy(struct varbuf *v);
void varbuf_free(struct varbuf *v);

void varbuf_add_char(struct varbuf *v, int c);
void varbuf_dup_char(struct varbuf *v, int c, size_t n);
void varbuf_map_char(struct varbuf *v, int c_src, int c_dst);

void varbuf_add_buf(struct varbuf *v, const void *s, size_t size);
void varbuf_end_str(struct varbuf *v);
const char *varbuf_get_str(struct varbuf *v);

int varbuf_printf(struct varbuf *v, const char *fmt, ...) __attribute__((format(printf, 2, 2 + 1)));
int varbuf_vprintf(struct varbuf *v, const char *fmt, va_list va)
 __attribute__((format(printf, 2, 0)));

struct varbuf_state {
 size_t used;
};

void varbuf_snapshot(struct varbuf *v, struct varbuf_state *vs);
void varbuf_rollback(struct varbuf *v, struct varbuf_state *vs);





struct dpkg_version {

 unsigned int epoch;

 const char *version;

 const char *revision;
};
enum dpkg_relation {

 DPKG_RELATION_NONE = 0,

 DPKG_RELATION_EQ = (1UL << (0)),

 DPKG_RELATION_LT = (1UL << (1)),

 DPKG_RELATION_LE = DPKG_RELATION_LT | DPKG_RELATION_EQ,

 DPKG_RELATION_GT = (1UL << (2)),

 DPKG_RELATION_GE = DPKG_RELATION_GT | DPKG_RELATION_EQ,
};

void dpkg_version_blank(struct dpkg_version *version);

_Bool 
    dpkg_version_is_informative(const struct dpkg_version *version);
int dpkg_version_compare(const struct dpkg_version *a,
                         const struct dpkg_version *b);

_Bool 
    dpkg_version_relate(const struct dpkg_version *a,
                         enum dpkg_relation rel,
                         const struct dpkg_version *b);












enum dpkg_arch_type {
 DPKG_ARCH_NONE,
 DPKG_ARCH_EMPTY,
 DPKG_ARCH_ILLEGAL,
 DPKG_ARCH_WILDCARD,
 DPKG_ARCH_ALL,
 DPKG_ARCH_NATIVE,
 DPKG_ARCH_FOREIGN,
 DPKG_ARCH_UNKNOWN,
};

struct dpkg_arch {
 struct dpkg_arch *next;
 const char *name;
 enum dpkg_arch_type type;
};

const char *dpkg_arch_name_is_illegal(const char *name) __attribute__((nonnull(1)));
struct dpkg_arch *dpkg_arch_find(const char *name);
struct dpkg_arch *dpkg_arch_get(enum dpkg_arch_type type);
struct dpkg_arch *dpkg_arch_get_list(void);
void dpkg_arch_reset_list(void);

const char *dpkg_arch_describe(const struct dpkg_arch *arch);

struct dpkg_arch *dpkg_arch_add(const char *name);
void dpkg_arch_unmark(struct dpkg_arch *arch);
void dpkg_arch_load_list(void);
void dpkg_arch_save_list(void);

void varbuf_add_archqual(struct varbuf *vb, const struct dpkg_arch *arch);













enum deptype {
  dep_suggests,
  dep_recommends,
  dep_depends,
  dep_predepends,
  dep_breaks,
  dep_conflicts,
  dep_provides,
  dep_replaces,
  dep_enhances
};

struct dependency {
  struct pkginfo *up;
  struct dependency *next;
  struct deppossi *list;
  enum deptype type;
};

struct deppossi {
  struct dependency *up;
  struct pkgset *ed;
  struct deppossi *next, *rev_next, *rev_prev;
  const struct dpkg_arch *arch;
  struct dpkg_version version;
  enum dpkg_relation verrel;
  
 _Bool 
      arch_is_implicit;
  
 _Bool 
      cyclebreak;
};

struct arbitraryfield {
  struct arbitraryfield *next;
  const char *name;
  const char *value;
};

struct conffile {
  struct conffile *next;
  const char *name;
  const char *hash;
  
 _Bool 
      obsolete;
  
 _Bool 
      remove_on_upgrade;
};

struct archivedetails {
  struct archivedetails *next;
  const char *name;
  const char *msdosname;
  const char *size;
  const char *md5sum;
};

enum pkgmultiarch {
 PKG_MULTIARCH_NO,
 PKG_MULTIARCH_SAME,
 PKG_MULTIARCH_ALLOWED,
 PKG_MULTIARCH_FOREIGN,
};






struct pkgbin {
  struct dependency *depends;

  
 _Bool 
      essential;

  
 _Bool 
      is_protected;
  enum pkgmultiarch multiarch;
  const struct dpkg_arch *arch;


  const char *pkgname_archqual;
  const char *description;
  const char *maintainer;
  const char *source;
  const char *installedsize;
  const char *origin;
  const char *bugs;
  struct dpkg_version version;
  struct conffile *conffiles;
  struct arbitraryfield *arbs;
};
struct trigpend {
  struct trigpend *next;
  const char *name;
};




struct trigaw {
  struct pkginfo *aw, *pend;
  struct trigaw *samepend_next;
  struct {
    struct trigaw *next, *prev;
  } sameaw;
};


struct perpackagestate;

enum pkgwant {
 PKG_WANT_UNKNOWN,
 PKG_WANT_INSTALL,
 PKG_WANT_HOLD,
 PKG_WANT_DEINSTALL,
 PKG_WANT_PURGE,

 PKG_WANT_SENTINEL,
};

enum pkgeflag {
 PKG_EFLAG_OK = 0,
 PKG_EFLAG_REINSTREQ = 1,
};

enum pkgstatus {
 PKG_STAT_NOTINSTALLED,
 PKG_STAT_CONFIGFILES,
 PKG_STAT_HALFINSTALLED,
 PKG_STAT_UNPACKED,
 PKG_STAT_HALFCONFIGURED,
 PKG_STAT_TRIGGERSAWAITED,
 PKG_STAT_TRIGGERSPENDING,
 PKG_STAT_INSTALLED,
};

enum pkgpriority {
 PKG_PRIO_REQUIRED,
 PKG_PRIO_IMPORTANT,
 PKG_PRIO_STANDARD,
 PKG_PRIO_OPTIONAL,
 PKG_PRIO_EXTRA,
 PKG_PRIO_OTHER,
 PKG_PRIO_UNKNOWN,
 PKG_PRIO_UNSET = -1,
};






struct pkginfo {
  struct pkgset *set;
  struct pkginfo *arch_next;

  enum pkgwant want;

  enum pkgeflag eflag;
  enum pkgstatus status;
  enum pkgpriority priority;
  const char *otherpriority;
  const char *section;
  struct dpkg_version configversion;
  struct pkgbin installed;
  struct pkgbin available;
  struct perpackagestate *clientdata;

  struct archivedetails *archives;

  struct {

    struct trigaw *head, *tail;
  } trigaw;


  struct trigaw *othertrigaw_head;
  struct trigpend *trigpend_head;
  struct fsys_namenode_list *files;
  off_t files_list_phys_offs;
  
 _Bool 
      files_list_valid;


  
 _Bool 
      status_dirty;
};




struct pkgset {
  struct pkgset *next;
  const char *name;
  struct pkginfo pkg;
  struct {
    struct deppossi *available;
    struct deppossi *installed;
  } depended;
  int installed_instances;
};



const char *dpkg_db_set_dir(const char *dir);
const char *dpkg_db_get_dir(void);
char *dpkg_db_get_path(const char *pathpart);









enum atomic_file_flags {
 ATOMIC_FILE_NORMAL = 0,
 ATOMIC_FILE_BACKUP = (1UL << (0)),
 ATOMIC_FILE_MKPATH = (1UL << (1)),
};

struct atomic_file {
 enum atomic_file_flags flags;
 char *name;
 char *name_new;
 FILE *fp;
};

struct atomic_file *
atomic_file_new(const char *filename, enum atomic_file_flags flags);
void atomic_file_open(struct atomic_file *file);
void atomic_file_sync(struct atomic_file *file);
void atomic_file_close(struct atomic_file *file);
void atomic_file_commit(struct atomic_file *file);
void atomic_file_remove(struct atomic_file *file);
void atomic_file_free(struct atomic_file *file);







enum modstatdb_rw {

  msdbrw_readonly,
  msdbrw_needsuperuserlockonly,
  msdbrw_writeifposs,
  msdbrw_write,
  msdbrw_needsuperuser,


  msdbrw_available_readonly = (1UL << (8)),
  msdbrw_available_write = (1UL << (9)),
  msdbrw_available_mask = 0xff00,
};

void modstatdb_init(void);
void modstatdb_done(void);

_Bool 
    modstatdb_is_locked(void);

_Bool 
    modstatdb_can_lock(void);
void modstatdb_lock(void);
void modstatdb_unlock(void);
enum modstatdb_rw modstatdb_open(enum modstatdb_rw reqrwflags);
enum modstatdb_rw modstatdb_get_status(void);
void modstatdb_note(struct pkginfo *pkg);
void modstatdb_note_ifwrite(struct pkginfo *pkg);
void modstatdb_checkpoint(void);
void modstatdb_shutdown(void);



void pkgset_blank(struct pkgset *set);
int pkgset_installed_instances(struct pkgset *set);

void pkg_blank(struct pkginfo *pp);
void pkgbin_blank(struct pkgbin *pkgbin);

_Bool 
    pkg_is_informative(struct pkginfo *pkg, struct pkgbin *info);

struct pkgset *
pkg_hash_find_set(const char *name);
struct pkginfo *
pkg_hash_get_singleton(struct pkgset *set);
struct pkginfo *
pkg_hash_find_singleton(const char *name);
struct pkginfo *
pkg_hash_get_pkg(struct pkgset *set, const struct dpkg_arch *arch);
struct pkginfo *
pkg_hash_find_pkg(const char *name, const struct dpkg_arch *arch);
int
pkg_hash_count_set(void);
int
pkg_hash_count_pkg(void);
void
pkg_hash_reset(void);

struct pkg_hash_iter *
pkg_hash_iter_new(void);
struct pkgset *
pkg_hash_iter_next_set(struct pkg_hash_iter *iter);
struct pkginfo *
pkg_hash_iter_next_pkg(struct pkg_hash_iter *iter);
void
pkg_hash_iter_free(struct pkg_hash_iter *iter);

void
pkg_hash_report(FILE *);



enum parsedbflags {

  pdb_single_stanza = (1UL << (0)),

  pdb_recordavailable = (1UL << (1)),

  pdb_rejectstatus = (1UL << (2)),

  pdb_weakclassification = (1UL << (3)),

  pdb_ignore_archives = (1UL << (4)),

  pdb_ignoreolder = (1UL << (5)),

  pdb_lax_version_parser = (1UL << (6)),

  pdb_lax_stanza_parser = (1UL << (9)),

  pdb_lax_parser = pdb_lax_stanza_parser | pdb_lax_version_parser,

  pdb_close_fd = (1UL << (7)),

  pdb_dash_is_stdin = (1UL << (8)),

  pdb_allow_empty = (1UL << (9)),



  pdb_parse_status = pdb_lax_parser | pdb_weakclassification |
      pdb_allow_empty,
  pdb_parse_update = pdb_parse_status | pdb_single_stanza,
  pdb_parse_available = pdb_recordavailable | pdb_rejectstatus |
      pdb_lax_parser | pdb_allow_empty,
  pdb_parse_binary = pdb_recordavailable | pdb_rejectstatus |
      pdb_single_stanza,
};

const char *pkg_name_is_illegal(const char *p);

const struct fieldinfo *
find_field_info(const struct fieldinfo *fields, const char *fieldname);
const struct arbitraryfield *
find_arbfield_info(const struct arbitraryfield *arbs, const char *fieldname);

int parsedb(const char *filename, enum parsedbflags, struct pkginfo **donep);
void copy_dependency_links(struct pkginfo *pkg,
                           struct dependency **updateme,
                           struct dependency *newdepends,
                           
                          _Bool 
                               available);











struct namevalue {
 const char *name;
 int value;
 int length;
};




const struct namevalue *namevalue_find_by_name(const struct namevalue *head,
                                               const char *str);





extern const struct namevalue booleaninfos[];
extern const struct namevalue multiarchinfos[];
extern const struct namevalue priorityinfos[];
extern const struct namevalue statusinfos[];
extern const struct namevalue eflaginfos[];
extern const struct namevalue wantinfos[];









enum dpkg_msg_type {
 DPKG_MSG_NONE,
 DPKG_MSG_WARN,
 DPKG_MSG_ERROR,
};

struct dpkg_error {
 enum dpkg_msg_type type;

 int syserrno;
 char *str;
};






_Bool 
    dpkg_has_error(struct dpkg_error *err);

int dpkg_put_warn(struct dpkg_error *err, const char *fmt, ...)
 __attribute__((format(printf, 2, 2 + 1)));
int dpkg_put_error(struct dpkg_error *err, const char *fmt, ...)
 __attribute__((format(printf, 2, 2 + 1)));
int dpkg_put_errno(struct dpkg_error *err, const char *fmt, ...)
 __attribute__((format(printf, 2, 2 + 1)));

void dpkg_error_print(struct dpkg_error *err, const char *fmt, ...)
 __attribute__((format(printf, 2, 2 + 1)));

void dpkg_error_move(struct dpkg_error *dst, struct dpkg_error *src);
void dpkg_error_destroy(struct dpkg_error *err);





enum versiondisplayepochwhen { vdew_never, vdew_nonambig, vdew_always };
void varbufversion(struct varbuf *, const struct dpkg_version *,
                   enum versiondisplayepochwhen);
int parseversion(struct dpkg_version *version, const char *,
                 struct dpkg_error *err);
const char *versiondescribe(const struct dpkg_version *,
                            enum versiondisplayepochwhen);
const char *versiondescribe_c(const struct dpkg_version *version,
                              enum versiondisplayepochwhen vdew);

enum pkg_name_arch_when {

  pnaw_never,

  pnaw_nonambig,

  pnaw_foreign,

  pnaw_always,
};

void varbuf_add_pkgbin_name(struct varbuf *vb, const struct pkginfo *pkg,
                            const struct pkgbin *pkgbin,
                            enum pkg_name_arch_when pnaw);

const char *
pkgbin_name_archqual(const struct pkginfo *pkg, const struct pkgbin *pkgbin);

const char *
pkgbin_name(struct pkginfo *pkg, struct pkgbin *pkgbin,
            enum pkg_name_arch_when pnaw);
const char *
pkg_name(struct pkginfo *pkg, enum pkg_name_arch_when pnaw);

const char *
pkgbin_name_const(const struct pkginfo *pkg, const struct pkgbin *pkgbin,
                  enum pkg_name_arch_when pnaw);
const char *
pkg_name_const(const struct pkginfo *pkg, enum pkg_name_arch_when pnaw);

void
pkg_source_version(struct dpkg_version *version,
                   const struct pkginfo *pkg, const struct pkgbin *pkgbin);

void
varbuf_add_source_version(struct varbuf *vb,
                          const struct pkginfo *pkg, const struct pkgbin *pkgbin);

const char *pkg_want_name(const struct pkginfo *pkg);
const char *pkg_status_name(const struct pkginfo *pkg);
const char *pkg_eflag_name(const struct pkginfo *pkg);

const char *pkg_priority_name(const struct pkginfo *pkg);



void writerecord(FILE*, const char*,
                 const struct pkginfo *, const struct pkgbin *);

enum writedb_flags {

  wdb_dump_available = (1UL << (0)),

  wdb_must_sync = (1UL << (1)),
};

void writedb_records(FILE *fp, const char *filename, enum writedb_flags flags);
void writedb(const char *filename, enum writedb_flags flags);



void varbufrecord(struct varbuf *, const struct pkginfo *,
                  const struct pkgbin *);
void varbufdependency(struct varbuf *vb, struct dependency *dep);




_Bool 
    versionsatisfied(struct pkgbin *it, struct deppossi *against);

_Bool 
    deparchsatisfied(struct pkgbin *it, const struct dpkg_arch *arch,
                      struct deppossi *against);

_Bool 
    archsatisfied(struct pkgbin *it, struct deppossi *against);


_Bool

pkg_virtual_deppossi_satisfied(struct deppossi *dependee,
                               struct deppossi *provider);


void *nfmalloc(size_t);
char *nfstrsave(const char*);
char *nfstrnsave(const char*, size_t);
void nffreeall(void);













struct file_stat {
 uid_t uid;
 gid_t gid;
 mode_t mode;



 char *uname;
 char *gname;
};

void file_copy_perms(const char *src, const char *dst);

int
file_slurp(const char *filename, struct varbuf *vb, struct dpkg_error *err);

enum file_lock_flags {
 FILE_LOCK_NOWAIT,
 FILE_LOCK_WAIT,
};


_Bool 
    file_is_locked(int lockfd, const char *filename);
void file_lock(int *lockfd, enum file_lock_flags flags, const char *filename,
               const char *filedesc);
void file_unlock(int fd, const char *filename, const char *filedesc);
void file_show(const char *filename);












struct glob_node {
 struct glob_node *next;
 char *pattern;
};

void glob_list_prepend(struct glob_node **list, char *pattern);
void glob_list_free(struct glob_node *head);





struct buffer_data {
 union {
  void *ptr;
  int i;
 } arg;
 int type;
};
off_t buffer_copy_IntPtr(int i, int typeIn,
                         void *f, int typeDigest,
                         void *p, int typeOut,
                         off_t limit, struct dpkg_error *err)
 __attribute__((warn_unused_result));
off_t buffer_copy_IntInt(int i1, int typeIn,
                         void *f, int typeDigest,
                         int i2, int typeOut,
                         off_t limit, struct dpkg_error *err)
 __attribute__((warn_unused_result));
off_t buffer_skip_Int(int I, int T, off_t limit, struct dpkg_error *err)
 __attribute__((warn_unused_result));
off_t buffer_digest(const void *buf, void *hash, int typeDigest, off_t length);












typedef int action_func(const char *const *argv);

struct cmdinfo {
  const char *olong;
  char oshort;







  int takesvalue;
  int *iassignto;
  const char **sassignto;
  void (*call)(const struct cmdinfo*, const char *value);

  int arg_int;
  void *arg_ptr;

  action_func *action;
};

void badusage(const char *fmt, ...) __attribute__((noreturn)) __attribute__((format(printf, 1, 1 + 1)));



void dpkg_options_load(const char *prog, const struct cmdinfo *cmdinfos);
void dpkg_options_parse(const char *const **argvp,
                        const struct cmdinfo *cmdinfos, const char *help_str);

long dpkg_options_parse_arg_int(const struct cmdinfo *cmd, const char *str);

struct pkginfo *
dpkg_options_parse_pkgname(const struct cmdinfo *cmd, const char *name);




extern const struct cmdinfo *cipaction;

void setaction(const struct cmdinfo *cip, const char *value);
void setobsolete(const struct cmdinfo *cip, const char *value);

struct pkginfo;




enum fsys_hash_find_flags {

 FHFF_NOCOPY = (1UL << (0)),

 FHFF_NONE = (1UL << (1)),
};

enum fsys_namenode_flags {

 FNNF_NEW_CONFF = (1UL << (0)),

 FNNF_NEW_INARCHIVE = (1UL << (1)),

 FNNF_OLD_CONFF = (1UL << (2)),

 FNNF_OBS_CONFF = (1UL << (3)),

 FNNF_ELIDE_OTHER_LISTS = (1UL << (4)),

 FNNF_NO_ATOMIC_OVERWRITE = (1UL << (5)),

 FNNF_PLACED_ON_DISK = (1UL << (6)),
 FNNF_DEFERRED_FSYNC = (1UL << (7)),
 FNNF_DEFERRED_RENAME = (1UL << (8)),

 FNNF_FILTERED = (1UL << (9)),

 FNNF_RM_CONFF_ON_UPGRADE = (1UL << (10)),
};




struct file_ondisk_id {
 dev_t id_dev;
 ino_t id_ino;
};

struct fsys_namenode {
 struct fsys_namenode *next;
 const char *name;
 struct pkg_list *packages;
 struct fsys_diversion *divert;






 struct file_stat *statoverride;

 struct trigfileint *trig_interested;







 enum fsys_namenode_flags flags;


 const char *oldhash;


 const char *newhash;

 struct file_ondisk_id *file_ondisk_id;
};

struct fsys_namenode_list {
 struct fsys_namenode_list *next;
 struct fsys_namenode *namenode;
};




struct fsys_namenode_queue {
 struct fsys_namenode_list *head, **tail;
};
struct fsys_diversion {
 struct fsys_namenode *useinstead;
 struct fsys_namenode *camefrom;
 struct pkgset *pkgset;


 struct fsys_diversion *next;
};

struct fsys_node_pkgs_iter;
struct fsys_node_pkgs_iter *
fsys_node_pkgs_iter_new(struct fsys_namenode *fnn);
struct pkginfo *
fsys_node_pkgs_iter_next(struct fsys_node_pkgs_iter *iter);
void
fsys_node_pkgs_iter_free(struct fsys_node_pkgs_iter *iter);

void
fsys_hash_init(void);
void
fsys_hash_reset(void);
void
fsys_hash_report(FILE *file);
int
fsys_hash_entries(void);

struct fsys_hash_iter;
struct fsys_hash_iter *
fsys_hash_iter_new(void);
struct fsys_namenode *
fsys_hash_iter_next(struct fsys_hash_iter *iter);
void
fsys_hash_iter_free(struct fsys_hash_iter *iter);

struct fsys_namenode *
fsys_hash_find_node(const char *filename, enum fsys_hash_find_flags flags);

struct fsys_hash_rev_iter {
 struct fsys_namenode_list *todo;
};

void
fsys_hash_rev_iter_init(struct fsys_hash_rev_iter *iter,
                        struct fsys_namenode_list *files);
struct fsys_namenode *
fsys_hash_rev_iter_next(struct fsys_hash_rev_iter *iter);
void
fsys_hash_rev_iter_abort(struct fsys_hash_rev_iter *iter);

const char *dpkg_fsys_set_dir(const char *dir);
const char *dpkg_fsys_get_dir(void);
char *dpkg_fsys_get_path(const char *pathpart);
struct pkginfo;

void ensure_diversions(void);

enum statdb_parse_flags {
 STATDB_PARSE_NORMAL = 0,
 STATDB_PARSE_LAX = 1,
};

uid_t statdb_parse_uid(const char *str);
gid_t statdb_parse_gid(const char *str);
mode_t statdb_parse_mode(const char *str);
void ensure_statoverrides(enum statdb_parse_flags flags);




void ensure_packagefiles_available(struct pkginfo *pkg);
void ensure_allinstfiles_available(void);
void ensure_allinstfiles_available_quiet(void);
void note_must_reread_files_inpackage(struct pkginfo *pkg);
void parse_filehash(struct pkginfo *pkg, struct pkgbin *pkgbin);
void write_filelist_except(struct pkginfo *pkg, struct pkgbin *pkgbin,
                           struct fsys_namenode_list *list, enum fsys_namenode_flags mask);
void write_filehash_except(struct pkginfo *pkg, struct pkgbin *pkgbin,
                           struct fsys_namenode_list *list, enum fsys_namenode_flags mask);


static const char printforhelp[] = "Use --help for help about diverting files."
                                             ;

static const char *admindir;
const char *instdir;

static 
      _Bool 
           opt_pkgname_match_any = 
                                   1
                                       ;
static const char *opt_pkgname = 
                                ((void *)0)
                                    ;
static const char *opt_divertto = 
                                 ((void *)0)
                                     ;

static int opt_verbose = 1;
static int opt_test = 0;
static int opt_rename = -1;


static void
printversion(const struct cmdinfo *cip, const char *value)
{
 printf(gettext("Debian %s version %s.\n"), dpkg_get_progname(),
        "1.20.12" " (" "amd64" ")");

 printf(gettext("This is free software; see the GNU General Public License version 2 or\n" "later for copying conditions. There is NO warranty.\n")

                                                        );

 m_output(
         stdout
               , gettext("<standard output>"));

 exit(0);
}

static void
usage(const struct cmdinfo *cip, const char *value)
{
 printf(gettext("Usage: %s [<option>...] <command>\n" "\n")

     , dpkg_get_progname());

 printf(gettext("Commands:\n" "  [--add] <file>           add a diversion.\n" "  --remove <file>          remove the diversion.\n" "  --list [<glob-pattern>]  show file diversions.\n" "  --listpackage <file>     show what package diverts the file.\n" "  --truename <file>        return the diverted file.\n" "\n")






     );

 printf(gettext("Options:\n" "  --package <package>      name of the package whose copy of <file> will not\n" "                             be diverted.\n" "  --local                  all packages' versions are diverted.\n" "  --divert <divert-to>     the name used by other packages' versions.\n" "  --rename                 actually move the file aside (or back).\n" "  --no-rename              do not move the file aside (or back) (default).\n" "  --admindir <directory>   set the directory with the diversions file.\n" "  --instdir <directory>    set the root directory, but not the admin dir.\n" "  --root <directory>       set the directory of the root filesystem.\n" "  --test                   don't do anything, just demonstrate.\n" "  --quiet                  quiet operation, minimal output.\n" "  --help                   show this help message.\n" "  --version                show the version.\n" "\n")
     );

 printf(gettext("When adding, default is --local and --divert <original>.distrib.\n" "When removing, --package or --local and --divert must match if specified.\n" "Package preinst/postrm scripts should always specify --package and --divert.\n")


                                                                                 );

 m_output(
         stdout
               , gettext("<standard output>"));

 exit(0);
}

static void
opt_rename_setup(void)
{
 if (opt_rename >= 0)
  return;

 opt_rename = 0;
 warning(gettext("please specify --no-rename explicitly, the default " "will change to --rename in 1.20.x")
                                               );
}

struct file {
 char *name;
 enum {
  FILE_STAT_INVALID,
  FILE_STAT_VALID,
  FILE_STAT_NOFILE,
 } stat_state;
 struct stat stat;
};

static void
file_init(struct file *f, const char *filename)
{
 struct varbuf usefilename = { 0, 0, 
                            ((void *)0) 
                            };

 varbuf_add_buf(&usefilename, instdir, strlen(instdir));
 varbuf_add_buf(&usefilename, filename, strlen(filename));
 varbuf_end_str(&usefilename);

 f->name = varbuf_detach(&usefilename);
 f->stat_state = FILE_STAT_INVALID;
}

static void
file_destroy(struct file *f)
{
 free(f->name);
}

static void
file_stat(struct file *f)
{
 int ret;

 if (f->stat_state != FILE_STAT_INVALID)
  return;

 ret = lstat(f->name, &f->stat);
 if (ret && 
           (*__errno_location ()) 
                 != 
                    2
                          )
  ohshite(gettext("cannot stat file '%s'"), f->name);

 if (ret == 0)
  f->stat_state = FILE_STAT_VALID;
 else
  f->stat_state = FILE_STAT_NOFILE;
}

static void
check_writable_dir(struct file *f)
{
 char *tmpname;
 int tmpfd;

 tmpname = str_fmt("%s%s", f->name, ".dpkg-divert.tmp");

 tmpfd = creat(tmpname, 0600);
 if (tmpfd < 0)
  ohshite(gettext("error checking '%s'"), f->name);
 close(tmpfd);
 (void)unlink(tmpname);

 free(tmpname);
}

static 
      _Bool

check_rename(struct file *src, struct file *dst)
{
 file_stat(src);



 if (src->stat_state == FILE_STAT_NOFILE)
  return 
        0
             ;

 file_stat(dst);
 check_writable_dir(src);
 check_writable_dir(dst);

 if (src->stat_state == FILE_STAT_VALID &&
     dst->stat_state == FILE_STAT_VALID &&
     !(src->stat.st_dev == dst->stat.st_dev &&
       src->stat.st_ino == dst->stat.st_ino))
  ohshit(gettext("rename involves overwriting '%s' with\n" "  different file '%s', not allowed")
                                                ,
          dst->name, src->name);

 return 
       1
           ;
}

static void
file_copy(const char *src, const char *dst)
{
 struct dpkg_error err;
 char *tmp;
 int srcfd, dstfd;

 srcfd = open(src, 
                  00
                          );
 if (srcfd < 0)
  ohshite(gettext("unable to open file '%s'"), src);

 tmp = str_fmt("%s%s", dst, ".dpkg-divert.tmp");
 dstfd = creat(tmp, 0600);
 if (dstfd < 0)
  ohshite(gettext("unable to create file '%s'"), tmp);

 push_cleanup(cu_filename, ~ehflag_normaltidy, 1, tmp);

 if (buffer_copy_IntInt(srcfd, 0, 
    ((void *)0)
    , 4, dstfd, 2, -1, &err) < 0)
  ohshit(gettext("cannot copy '%s' to '%s': %s"), src, tmp, err.str);

 close(srcfd);

 if (fsync(dstfd))
  ohshite(gettext("unable to sync file '%s'"), tmp);
 if (close(dstfd))
  ohshite(gettext("unable to close file '%s'"), tmp);

 file_copy_perms(src, tmp);

 if (rename(tmp, dst) != 0)
  ohshite(gettext("cannot rename '%s' to '%s'"), tmp, dst);

 free(tmp);

 pop_cleanup(ehflag_normaltidy);
}

static void
file_rename(struct file *src, struct file *dst)
{
 if (src->stat_state == FILE_STAT_NOFILE)
  return;

 if (dst->stat_state == FILE_STAT_VALID) {
  if (unlink(src->name))
   ohshite(gettext("rename: remove duplicate old link '%s'"),
           src->name);
 } else {
  if (rename(src->name, dst->name) == 0)
   return;


  file_copy(src->name, dst->name);

  if (unlink(src->name))
   ohshite(gettext("unable to remove copied source file '%s'"),
           src->name);
 }
}

static void
diversion_check_filename(const char *filename)
{
 if (filename[0] != '/')
  badusage(gettext("filename \"%s\" is not absolute"), filename);
 if (strchr(filename, '\n') != 
                              ((void *)0)
                                  )
  badusage(gettext("file may not contain newlines"));
}

static const char *
diversion_pkg_name(struct fsys_diversion *d)
{
 if (d->pkgset == 
                 ((void *)0)
                     )
  return ":";
 else
  return d->pkgset->name;
}

static const char *
varbuf_diversion(struct varbuf *str, const char *pkgname,
                 const char *filename, const char *divertto)
{
 varbuf_reset(str);

 if (pkgname == 
               ((void *)0)
                   ) {
  if (divertto == 
                 ((void *)0)
                     )
   varbuf_printf(str, gettext("local diversion of %s"), filename);
  else
   varbuf_printf(str, gettext("local diversion of %s to %s"),
                 filename, divertto);
 } else {
  if (divertto == 
                 ((void *)0)
                     )
   varbuf_printf(str, gettext("diversion of %s by %s"),
                 filename, pkgname);
  else
   varbuf_printf(str, gettext("diversion of %s to %s by %s"),
                 filename, divertto, pkgname);
 }

 return str->buf;
}

static const char *
diversion_current(const char *filename)
{
 static struct varbuf str = { 0, 0, 
                           ((void *)0) 
                           };

 if (opt_pkgname_match_any) {
  varbuf_reset(&str);

  if (opt_divertto == 
                     ((void *)0)
                         )
   varbuf_printf(&str, gettext("any diversion of %s"), filename);
  else
   varbuf_printf(&str, gettext("any diversion of %s to %s"),
                 filename, opt_divertto);
 } else {
  return varbuf_diversion(&str, opt_pkgname, filename, opt_divertto);
 }

 return str.buf;
}

static const char *
diversion_describe(struct fsys_diversion *d)
{
 static struct varbuf str = { 0, 0, 
                           ((void *)0) 
                           };
 const char *pkgname;
 const char *name_from, *name_to;

 if (d->camefrom) {
  name_from = d->camefrom->name;
  name_to = d->camefrom->divert->useinstead->name;
 } else {
  name_from = d->useinstead->divert->camefrom->name;
  name_to = d->useinstead->name;
 }

 if (d->pkgset == 
                 ((void *)0)
                     )
  pkgname = 
           ((void *)0)
               ;
 else
  pkgname = d->pkgset->name;

 return varbuf_diversion(&str, pkgname, name_from, name_to);
}

static void
divertdb_write(void)
{
 char *dbname;
 struct atomic_file *file;
 struct fsys_hash_iter *iter;
 struct fsys_namenode *namenode;

 dbname = dpkg_db_get_path("diversions");

 file = atomic_file_new(dbname, ATOMIC_FILE_BACKUP);
 atomic_file_open(file);

 iter = fsys_hash_iter_new();
 while ((namenode = fsys_hash_iter_next(iter))) {
  struct fsys_diversion *d = namenode->divert;

  if (d == 
          ((void *)0) 
               || d->useinstead == 
                                   ((void *)0)
                                       )
   continue;

  fprintf(file->fp, "%s\n%s\n%s\n",
          d->useinstead->divert->camefrom->name,
          d->useinstead->name,
          diversion_pkg_name(d));
 }
 fsys_hash_iter_free(iter);

 atomic_file_sync(file);
 atomic_file_close(file);
 atomic_file_commit(file);
 atomic_file_free(file);

 free(dbname);
}

static 
      _Bool

diversion_is_essential(struct fsys_namenode *namenode)
{
 struct pkginfo *pkg;
 struct pkg_hash_iter *pkg_iter;
 struct fsys_node_pkgs_iter *iter;
 
_Bool 
     essential = 
                 0
                      ;

 pkg_iter = pkg_hash_iter_new();
 while ((pkg = pkg_hash_iter_next_pkg(pkg_iter))) {
  if (pkg->installed.essential)
   ensure_packagefiles_available(pkg);
 }
 pkg_hash_iter_free(pkg_iter);

 iter = fsys_node_pkgs_iter_new(namenode);
 while ((pkg = fsys_node_pkgs_iter_next(iter))) {
  if (pkg->installed.essential) {
   essential = 
              1
                  ;
   break;
  }
 }
 fsys_node_pkgs_iter_free(iter);

 return essential;
}

static 
      _Bool

diversion_is_owned_by_self(struct pkgset *set, struct fsys_namenode *namenode)
{
 struct pkginfo *pkg;
 struct fsys_node_pkgs_iter *iter;
 
_Bool 
     owned = 
             0
                  ;

 if (set == 
           ((void *)0)
               )
  return 
        0
             ;

 for (pkg = &set->pkg; pkg; pkg = pkg->arch_next)
  ensure_packagefiles_available(pkg);

 iter = fsys_node_pkgs_iter_new(namenode);
 while ((pkg = fsys_node_pkgs_iter_next(iter))) {
  if (pkg->set == set) {
   owned = 
          1
              ;
   break;
  }
 }
 fsys_node_pkgs_iter_free(iter);

 return owned;
}

static int
diversion_add(const char *const *argv)
{
 const char *filename = argv[0];
 struct file file_from, file_to;
 struct fsys_diversion *contest, *altname;
 struct fsys_namenode *fnn_from, *fnn_to;
 struct pkgset *pkgset;

 opt_pkgname_match_any = 
                        0
                             ;
 opt_rename_setup();


 if (!filename || argv[1])
  badusage(gettext("--%s needs a single argument"), cipaction->olong);

 diversion_check_filename(filename);

 file_init(&file_from, filename);
 file_stat(&file_from);

 if (file_from.stat_state == FILE_STAT_VALID &&
     
    ((((
    file_from.stat.st_mode
    )) & 0170000) == (0040000))
                                   )
  badusage(gettext("cannot divert directories"));

 fnn_from = fsys_hash_find_node(filename, 0);


 if (opt_divertto == 
                    ((void *)0)
                        )
  opt_divertto = str_fmt("%s.distrib", filename);

 if (strcmp(filename, opt_divertto) == 0)
  badusage(gettext("cannot divert file '%s' to itself"), filename);

 file_init(&file_to, opt_divertto);

 fnn_to = fsys_hash_find_node(opt_divertto, 0);


 if (opt_pkgname == 
                   ((void *)0)
                       )
  pkgset = 
          ((void *)0)
              ;
 else
  pkgset = pkg_hash_find_set(opt_pkgname);


 if (fnn_from->divert || fnn_to->divert) {
  if (fnn_to->divert && fnn_to->divert->camefrom &&
      strcmp(fnn_to->divert->camefrom->name, filename) == 0 &&
      fnn_from->divert && fnn_from->divert->useinstead &&
      strcmp(fnn_from->divert->useinstead->name, opt_divertto) == 0 &&
      fnn_from->divert->pkgset == pkgset) {
   if (opt_verbose > 0)
    printf(gettext("Leaving '%s'\n"),
           diversion_describe(fnn_from->divert));

   file_destroy(&file_from);
   file_destroy(&file_to);

   return 0;
  }

  ohshit(gettext("'%s' clashes with '%s'"),
         diversion_current(filename),
         fnn_from->divert ?
         diversion_describe(fnn_from->divert) :
         diversion_describe(fnn_to->divert));
 }


 contest = nfmalloc(sizeof(*contest));
 altname = nfmalloc(sizeof(*altname));

 altname->camefrom = fnn_from;
 altname->camefrom->divert = contest;
 altname->useinstead = 
                      ((void *)0)
                          ;
 altname->pkgset = pkgset;

 contest->useinstead = fnn_to;
 contest->useinstead->divert = altname;
 contest->camefrom = 
                    ((void *)0)
                        ;
 contest->pkgset = pkgset;


 if (opt_verbose > 0)
  printf(gettext("Adding '%s'\n"), diversion_describe(contest));
 if (opt_rename)
  opt_rename = check_rename(&file_from, &file_to);

 if (opt_rename && diversion_is_owned_by_self(pkgset, fnn_from)) {
  if (opt_verbose > 0)
   printf(gettext("Ignoring request to rename file '%s' " "owned by diverting package '%s'\n")
                                                ,
          filename, pkgset->name);
  opt_rename = 
              0
                   ;
 }
 if (opt_rename && diversion_is_essential(fnn_from))
  warning(gettext("diverting file '%s' from an Essential package with " "rename is dangerous, use --no-rename")
                                                   , filename);
 if (!opt_test) {
  divertdb_write();
  if (opt_rename)
   file_rename(&file_from, &file_to);
 }

 file_destroy(&file_from);
 file_destroy(&file_to);

 return 0;
}

static 
      _Bool

diversion_is_shared(struct pkgset *set, struct fsys_namenode *namenode)
{
 const char *archname;
 struct pkginfo *pkg;
 struct dpkg_arch *arch;
 struct fsys_node_pkgs_iter *iter;
 
_Bool 
     shared = 
              0
                   ;

 if (set == 
           ((void *)0)
               )
  return 
        0
             ;

 archname = getenv("DPKG_MAINTSCRIPT_ARCH");
 arch = dpkg_arch_find(archname);
 if (arch->type == DPKG_ARCH_NONE || arch->type == DPKG_ARCH_EMPTY)
  return 
        0
             ;

 for (pkg = &set->pkg; pkg; pkg = pkg->arch_next)
  ensure_packagefiles_available(pkg);

 iter = fsys_node_pkgs_iter_new(namenode);
 while ((pkg = fsys_node_pkgs_iter_next(iter))) {
  if (pkg->set == set && pkg->installed.arch != arch) {
   shared = 
           1
               ;
   break;
  }
 }
 fsys_node_pkgs_iter_free(iter);

 return shared;
}

static int
diversion_remove(const char *const *argv)
{
 const char *filename = argv[0];
 struct fsys_namenode *namenode;
 struct fsys_diversion *contest, *altname;
 struct file file_from, file_to;
 struct pkgset *pkgset;

 opt_rename_setup();

 if (!filename || argv[1])
  badusage(gettext("--%s needs a single argument"), cipaction->olong);

 diversion_check_filename(filename);

 namenode = fsys_hash_find_node(filename, FHFF_NONE);

 if (namenode == 
                ((void *)0) 
                     || namenode->divert == 
                                            ((void *)0) 
                                                 ||
     namenode->divert->useinstead == 
                                    ((void *)0)
                                        ) {
  if (opt_verbose > 0)
   printf(gettext("No diversion '%s', none removed.\n"),
          diversion_current(filename));
  return 0;
 }

 if (opt_pkgname == 
                   ((void *)0)
                       )
  pkgset = 
          ((void *)0)
              ;
 else
  pkgset = pkg_hash_find_set(opt_pkgname);

 contest = namenode->divert;
 altname = contest->useinstead->divert;

 if (opt_divertto != 
                    ((void *)0) 
                         &&
     strcmp(opt_divertto, contest->useinstead->name) != 0)
  ohshit(gettext("mismatch on divert-to\n" "  when removing '%s'\n" "  found '%s'")

                          ,
         diversion_current(filename),
         diversion_describe(contest));

 if (!opt_pkgname_match_any && pkgset != contest->pkgset)
  ohshit(gettext("mismatch on package\n" "  when removing '%s'\n" "  found '%s'")

                          ,
         diversion_current(filename),
         diversion_describe(contest));



 if (diversion_is_shared(pkgset, namenode)) {
  if (opt_verbose > 0)
   printf(gettext("Ignoring request to remove shared diversion '%s'.\n"),
          diversion_describe(contest));
  return 0;
 }

 if (opt_verbose > 0)
  printf(gettext("Removing '%s'\n"), diversion_describe(contest));

 file_init(&file_from, altname->camefrom->name);
 file_init(&file_to, contest->useinstead->name);


 contest->useinstead->divert = 
                              ((void *)0)
                                  ;
 altname->camefrom->divert = 
                            ((void *)0)
                                ;

 if (opt_rename)
  opt_rename = check_rename(&file_to, &file_from);
 if (opt_rename && !opt_test)
  file_rename(&file_to, &file_from);

 if (!opt_test)
  divertdb_write();

 file_destroy(&file_from);
 file_destroy(&file_to);

 return 0;
}

static int
diversion_list(const char *const *argv)
{
 struct fsys_hash_iter *iter;
 struct fsys_namenode *namenode;
 struct glob_node *glob_list = 
                              ((void *)0)
                                  ;
 const char *pattern;

 while ((pattern = *argv++))
  glob_list_prepend(&glob_list, m_strdup(pattern));

 if (glob_list == 
                 ((void *)0)
                     )
  glob_list_prepend(&glob_list, m_strdup("*"));

 iter = fsys_hash_iter_new();
 while ((namenode = fsys_hash_iter_next(iter))) {
  struct glob_node *g;
  struct fsys_diversion *contest = namenode->divert;
  struct fsys_diversion *altname;
  const char *pkgname;

  if (contest == 
                ((void *)0) 
                     || contest->useinstead == 
                                               ((void *)0)
                                                   )
   continue;

  altname = contest->useinstead->divert;

  pkgname = diversion_pkg_name(contest);

  for (g = glob_list; g; g = g->next) {
   if (fnmatch(g->pattern, pkgname, 0) == 0 ||
       fnmatch(g->pattern, contest->useinstead->name, 0) == 0 ||
       fnmatch(g->pattern, altname->camefrom->name, 0) == 0) {
    printf("%s\n", diversion_describe(contest));
    break;
   }
  }
 }
 fsys_hash_iter_free(iter);

 glob_list_free(glob_list);

 return 0;
}

static int
diversion_truename(const char *const *argv)
{
 const char *filename = argv[0];
 struct fsys_namenode *namenode;

 if (!filename || argv[1])
  badusage(gettext("--%s needs a single argument"), cipaction->olong);

 diversion_check_filename(filename);

 namenode = fsys_hash_find_node(filename, FHFF_NONE);


 if (namenode && namenode->divert && namenode->divert->useinstead)
  printf("%s\n", namenode->divert->useinstead->name);
 else
  printf("%s\n", filename);

 return 0;
}

static int
diversion_listpackage(const char *const *argv)
{
 const char *filename = argv[0];
 struct fsys_namenode *namenode;

 if (!filename || argv[1])
  badusage(gettext("--%s needs a single argument"), cipaction->olong);

 diversion_check_filename(filename);

 namenode = fsys_hash_find_node(filename, FHFF_NONE);


 if (namenode == 
                ((void *)0) 
                     || namenode->divert == 
                                            ((void *)0)
                                                )
  return 0;

 if (namenode->divert->pkgset == 
                                ((void *)0)
                                    )


  printf("LOCAL\n");
 else
  printf("%s\n", namenode->divert->pkgset->name);

 return 0;
}

static void
set_package(const struct cmdinfo *cip, const char *value)
{
 opt_pkgname_match_any = 
                        0
                             ;


 opt_pkgname = value;

 if (opt_pkgname && strchr(opt_pkgname, '\n') != 
                                                ((void *)0)
                                                    )
  badusage(gettext("package may not contain newlines"));
}

static void
set_divertto(const struct cmdinfo *cip, const char *value)
{
 opt_divertto = value;

 if (opt_divertto[0] != '/')
  badusage(gettext("filename \"%s\" is not absolute"), opt_divertto);
 if (strchr(opt_divertto, '\n') != 
                                  ((void *)0)
                                      )
  badusage(gettext("divert-to may not contain newlines"));
}

static void
set_instdir(const struct cmdinfo *cip, const char *value)
{
 instdir = dpkg_fsys_set_dir(value);
}

static void
set_root(const struct cmdinfo *cip, const char *value)
{
 instdir = dpkg_fsys_set_dir(value);
 admindir = dpkg_fsys_get_path("/usr/local/var/lib/dpkg");
}

static const struct cmdinfo cmdinfo_add =
 { "add", 0, 0, 
((void *)0)
, 
((void *)0)
, setaction, 0, 
((void *)0)
, diversion_add };

static const struct cmdinfo cmdinfos[] = {
 { "add", 0, 0, 
((void *)0)
, 
((void *)0)
, setaction, 0, 
((void *)0)
, diversion_add },
 { "remove", 0, 0, 
((void *)0)
, 
((void *)0)
, setaction, 0, 
((void *)0)
, diversion_remove },
 { "list", 0, 0, 
((void *)0)
, 
((void *)0)
, setaction, 0, 
((void *)0)
, diversion_list },
 { "listpackage", 0, 0, 
((void *)0)
, 
((void *)0)
, setaction, 0, 
((void *)0)
, diversion_listpackage },
 { "truename", 0, 0, 
((void *)0)
, 
((void *)0)
, setaction, 0, 
((void *)0)
, diversion_truename },

 { "admindir", 0, 1, 
                         ((void *)0)
                             , &admindir, 
                                                  ((void *)0) 
                                                                },
 { "instdir", 0, 1, 
                         ((void *)0)
                             , 
                                       ((void *)0)
                                           , set_instdir, 0 },
 { "root", 0, 1, 
                         ((void *)0)
                             , 
                                       ((void *)0)
                                           , set_root, 0 },
 { "divert", 0, 1, 
                         ((void *)0)
                             , 
                                       ((void *)0)
                                           , set_divertto },
 { "package", 0, 1, 
                         ((void *)0)
                             , 
                                       ((void *)0)
                                           , set_package },
 { "local", 0, 0, 
                         ((void *)0)
                             , 
                                       ((void *)0)
                                           , set_package },
 { "quiet", 0, 0, &opt_verbose, 
                                       ((void *)0)
                                           , 
                                                  ((void *)0)
                                                      , 0 },
 { "rename", 0, 0, &opt_rename, 
                                       ((void *)0)
                                           , 
                                                  ((void *)0)
                                                      , 1 },
 { "no-rename", 0, 0, &opt_rename, 
                                       ((void *)0)
                                           , 
                                                  ((void *)0)
                                                      , 0 },
 { "test", 0, 0, &opt_test, 
                                       ((void *)0)
                                           , 
                                                  ((void *)0)
                                                      , 1 },
 { "help", '?', 0, 
                         ((void *)0)
                             , 
                                       ((void *)0)
                                           , usage },
 { "version", 0, 0, 
                         ((void *)0)
                             , 
                                       ((void *)0)
                                           , printversion },
 { 
   ((void *)0)
       , 0 }
};

int
main(int argc, const char * const *argv)
{
 const char *env_pkgname;
 int ret;

 dpkg_locales_init("dpkg");
 dpkg_program_init("dpkg-divert");
 dpkg_options_parse(&argv, cmdinfos, printforhelp);

 admindir = dpkg_db_set_dir(admindir);
 instdir = dpkg_fsys_set_dir(instdir);

 env_pkgname = getenv("DPKG_MAINTSCRIPT_PACKAGE");
 if (opt_pkgname_match_any && env_pkgname)
  set_package(
             ((void *)0)
                 , env_pkgname);

 if (!cipaction)
  setaction(&cmdinfo_add, 
                         ((void *)0)
                             );

 modstatdb_open(msdbrw_readonly);
 ensure_diversions();

 ret = cipaction->action(argv);

 modstatdb_shutdown();

 dpkg_program_done();
 dpkg_locales_done();

 return ret;
}
