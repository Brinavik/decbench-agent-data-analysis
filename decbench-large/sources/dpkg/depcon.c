



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




enum pkg_infodb_format {
 PKG_INFODB_FORMAT_UNKNOWN = -1,
 PKG_INFODB_FORMAT_LEGACY = 0,
 PKG_INFODB_FORMAT_MULTIARCH = 1,
 PKG_INFODB_FORMAT_LAST,
};

enum pkg_infodb_format pkg_infodb_get_format(void);
void pkg_infodb_set_format(enum pkg_infodb_format format);

_Bool 
    pkg_infodb_is_upgrading(void);
void pkg_infodb_upgrade(void);

const char *pkg_infodb_get_dir(void);
const char *pkg_infodb_get_file(const struct pkginfo *pkg, const struct pkgbin *pkgbin,
                                const char *filetype);
const char *pkg_infodb_reset_dir(void);

_Bool 
    pkg_infodb_has_file(struct pkginfo *pkg, struct pkgbin *pkgbin,
                         const char *name);

typedef void pkg_infodb_file_func(const char *filename, const char *filetype);

void pkg_infodb_foreach(struct pkginfo *pkg, struct pkgbin *pkgbin,
                        pkg_infodb_file_func *func);








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


enum debugflags {
 dbg_general = 01,
 dbg_scripts = 02,
 dbg_eachfile = 010,
 dbg_eachfiledetail = 0100,
 dbg_conff = 020,
 dbg_conffdetail = 0200,
 dbg_depcon = 040,
 dbg_depcondetail = 0400,
 dbg_veryverbose = 01000,
 dbg_stupidlyverbose = 02000,
 dbg_triggers = 010000,
 dbg_triggersdetail = 020000,
 dbg_triggersstupid = 040000,
};

void debug_set_output(FILE *output, const char *filename);
void debug_set_mask(int mask);

_Bool 
    debug_has_flag(int flag);
void debug(int flag, const char *fmt, ...) __attribute__((format(printf, 2, 2 + 1)));












struct pkg_list {
 struct pkg_list *next;
 struct pkginfo *pkg;
};

struct pkg_list *pkg_list_new(struct pkginfo *pkg, struct pkg_list *next);
void pkg_list_free(struct pkg_list *head);
void pkg_list_prepend(struct pkg_list **head, struct pkginfo *pkg);













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


enum force_flags {
 FORCE_ARCHITECTURE = (1UL << (0)),
 FORCE_BAD_PATH = (1UL << (1)),
 FORCE_BAD_VERIFY = (1UL << (2)),
 FORCE_BAD_VERSION = (1UL << (3)),
 FORCE_BREAKS = (1UL << (4)),
 FORCE_CONFF_ASK = (1UL << (5)),
 FORCE_CONFF_DEF = (1UL << (6)),
 FORCE_CONFF_MISS = (1UL << (7)),
 FORCE_CONFF_NEW = (1UL << (8)),
 FORCE_CONFF_OLD = (1UL << (9)),
 FORCE_CONFIGURE_ANY = (1UL << (10)),
 FORCE_CONFLICTS = (1UL << (11)),
 FORCE_DEPENDS = (1UL << (12)),
 FORCE_DEPENDS_VERSION = (1UL << (13)),
 FORCE_DOWNGRADE = (1UL << (14)),
 FORCE_HOLD = (1UL << (15)),
 FORCE_NON_ROOT = (1UL << (16)),
 FORCE_OVERWRITE = (1UL << (17)),
 FORCE_OVERWRITE_DIR = (1UL << (18)),
 FORCE_OVERWRITE_DIVERTED = (1UL << (19)),
 FORCE_REMOVE_ESSENTIAL = (1UL << (20)),
 FORCE_REMOVE_REINSTREQ = (1UL << (21)),
 FORCE_SCRIPT_CHROOTLESS = (1UL << (22)),
 FORCE_UNSAFE_IO = (1UL << (23)),
 FORCE_STATOVERRIDE_ADD = (1UL << (24)),
 FORCE_STATOVERRIDE_DEL = (1UL << (25)),
 FORCE_SECURITY_MAC = (1UL << (26)),
 FORCE_REMOVE_PROTECTED = (1UL << (27)),
 FORCE_ALL = 0xffffffff,
};


_Bool

in_force(int flags);
void
set_force(int flags);
void
reset_force(int flags);

char *
get_force_string(void);

void
parse_force(const char *value, 
                              _Bool 
                                   set);

void
set_force_default(int mask);
void
set_force_option(const struct cmdinfo *cip, const char *value);
void
reset_force_option(const struct cmdinfo *cip, const char *value);

void
forcibleerr(int forceflag, const char *format, ...) __attribute__((format(printf, 2, 2 + 1)));
int
forcible_nonroot_error(int rc);


struct fsys_namenode_list;
struct fsys_namenode;

enum pkg_istobe {

 PKG_ISTOBE_NORMAL,

 PKG_ISTOBE_REMOVE,

 PKG_ISTOBE_INSTALLNEW,

 PKG_ISTOBE_DECONFIGURE,

 PKG_ISTOBE_PREINSTALL,
};

enum pkg_cycle_color {
 PKG_CYCLE_WHITE,
 PKG_CYCLE_GRAY,
 PKG_CYCLE_BLACK,
};

struct perpackagestate {
  enum pkg_istobe istobe;


  enum pkg_cycle_color color;

  
 _Bool 
      enqueued;

  int replacingfilesandsaid;
  int cmdline_seen;


  struct pkg_list *trigprocdeferred;
};

enum action {
 act_unset,

 act_unpack,
 act_configure,
 act_install,
 act_triggers,
 act_remove,
 act_purge,
 act_verify,
 act_commandfd,

 act_status,
 act_listpackages,
 act_listfiles,
 act_searchfiles,
 act_controlpath,
 act_controllist,
 act_controlshow,

 act_cmpversions,

 act_arch_add,
 act_arch_remove,
 act_printarch,
 act_printforeignarches,

 act_assertpredep,
 act_assertepoch,
 act_assertlongfilenames,
 act_assertmulticonrep,
 act_assertmultiarch,
 act_assertverprovides,
 act_assert_protected,

 act_validate_pkgname,
 act_validate_trigname,
 act_validate_archname,
 act_validate_version,

 act_audit,
 act_unpackchk,
 act_predeppackage,

 act_getselections,
 act_setselections,
 act_clearselections,

 act_avail,
 act_printavail,
 act_avclear,
 act_avreplace,
 act_avmerge,
 act_forgetold,
};

extern const char *const statusstrings[];

extern int f_robot;
extern int f_pending, f_recursive, f_alsoselect, f_skipsame, f_noact;
extern int f_autodeconf, f_nodebsig;
extern int f_triggers;

extern 
      _Bool 
           abort_processing;
extern int errabort;
extern const char *instdir;
extern struct pkg_list *ignoredependss;

struct invoke_hook {
 struct invoke_hook *next;
 char *command;
};

struct invoke_list {
 struct invoke_hook *head, **tail;
};



void ensure_package_clientdata(struct pkginfo *pkg);



int archivefiles(const char *const *argv);
void process_archive(const char *filename);

_Bool 
    wanttoinstall(struct pkginfo *pkg);



int forgetold(const char *const *argv);
int updateavailable(const char *const *argv);



int audit(const char *const *argv);
int unpackchk(const char *const *argv);
int assertepoch(const char *const *argv);
int assertpredep(const char *const *argv);
int assertlongfilenames(const char *const *argv);
int assertmulticonrep(const char *const *argv);
int assertmultiarch(const char *const *argv);
int assertverprovides(const char *const *argv);
int assert_protected(const char *const *argv);
int validate_pkgname(const char *const *argv);
int validate_trigname(const char *const *argv);
int validate_archname(const char *const *argv);
int validate_version(const char *const *argv);
int predeppackage(const char *const *argv);
int printarch(const char *const *argv);
int printinstarch(const char *const *argv);
int print_foreign_arches(const char *const *argv);
int cmpversions(const char *const *argv);




_Bool 
    verify_set_output(const char *name);
int verify(const char *const *argv);



int getselections(const char *const *argv);
int setselections(const char *const *argv);
int clearselections(const char *const *argv);



void md5hash(struct pkginfo *pkg, char *hashbuf, const char *fn);
void enqueue_package(struct pkginfo *pkg);
void enqueue_package_mark_seen(struct pkginfo *pkg);
void process_queue(void);
int packages(const char *const *argv);
void removal_bulk(struct pkginfo *pkg);
int conffderef(struct pkginfo *pkg, struct varbuf *result, const char *in);

enum dep_check {
  DEP_CHECK_HALT = 0,
  DEP_CHECK_DEFER = 1,
  DEP_CHECK_OK = 2,
};

enum dep_check dependencies_ok(struct pkginfo *pkg, struct pkginfo *removing,
                               struct varbuf *aemsgs);
enum dep_check breakses_ok(struct pkginfo *pkg, struct varbuf *aemsgs);

void deferred_remove(struct pkginfo *pkg);
void deferred_configure(struct pkginfo *pkg);
enum dependtry {
 DEPEND_TRY_NORMAL = 1,
 DEPEND_TRY_CYCLES = 2,
 DEPEND_TRY_TRIGGERS = 3,
 DEPEND_TRY_TRIGGERS_CYCLES = 4,
 DEPEND_TRY_FORCE_DEPENDS_VERSION = 5,
 DEPEND_TRY_FORCE_DEPENDS = 6,
 DEPEND_TRY_LAST,
};

extern enum dependtry dependtry;
extern int sincenothing;



void cu_prermremove(int argc, void **argv);



void print_error_perpackage(const char *emsg, const void *data);
void print_error_perarchive(const char *emsg, const void *data);
int reportbroken_retexitstatus(int ret);

_Bool 
    skip_due_to_hold(struct pkginfo *pkg);



struct stat;


_Bool 
    ignore_depends(struct pkginfo *pkg);

_Bool 
    force_breaks(struct deppossi *possi);

_Bool 
    force_depends(struct deppossi *possi);

_Bool 
    force_conflicts(struct deppossi *possi);
void
conffile_mark_obsolete(struct pkginfo *pkg, struct fsys_namenode *namenode);
void pkg_conffiles_mark_old(struct pkginfo *pkg);

_Bool 
    find_command(const char *prog);
void checkpath(void);

struct fsys_namenode *
namenodetouse(struct fsys_namenode *namenode,
              struct pkginfo *pkg, struct pkgbin *pkgbin);

int maintscript_installed(struct pkginfo *pkg, const char *scriptname,
                          const char *desc, ...) __attribute__((sentinel));
int maintscript_new(struct pkginfo *pkg,
                    const char *scriptname, const char *desc,
                    const char *cidir, char *cidirrest, ...)
 __attribute__((sentinel));
int maintscript_fallback(struct pkginfo *pkg,
                         const char *scriptname, const char *desc,
                         const char *cidir, char *cidirrest,
                         const char *ifok, const char *iffallback);




int maintscript_postinst(struct pkginfo *pkg, ...) __attribute__((sentinel));
void post_postinst_tasks(struct pkginfo *pkg, enum pkgstatus new_status);

void clear_istobes(void);

_Bool

dir_is_used_by_others(struct fsys_namenode *namenode, struct pkginfo *pkg);

_Bool

dir_is_used_by_pkg(struct fsys_namenode *namenode, struct pkginfo *pkg,
                   struct fsys_namenode_list *list);

_Bool

dir_has_conffiles(struct fsys_namenode *namenode, struct pkginfo *pkg);

void log_action(const char *action, struct pkginfo *pkg, struct pkgbin *pkgbin);



void dpkg_selabel_load(void);
void dpkg_selabel_set_context(const char *matchpath, const char *path, mode_t mode);
void dpkg_selabel_close(void);



enum trigproc_type {

 TRIGPROC_TRY_DEFERRED,

 TRIGPROC_TRY_QUEUED,

 TRIGPROC_REQUIRED,
};

void trigproc_install_hooks(void);
void trigproc_populate_deferred(void);
void trigproc_run_deferred(void);
void trigproc_reset_cycle(void);

void trigproc(struct pkginfo *pkg, enum trigproc_type type);

void trig_activate_packageprocessing(struct pkginfo *pkg);



enum which_pkgbin {
  wpb_installed,
  wpb_available,
  wpb_by_istobe,
};

struct deppossi_pkg_iterator;

struct deppossi_pkg_iterator *
deppossi_pkg_iter_new(struct deppossi *possi, enum which_pkgbin wpb);
struct pkginfo *
deppossi_pkg_iter_next(struct deppossi_pkg_iterator *iter);
void
deppossi_pkg_iter_free(struct deppossi_pkg_iterator *iter);


_Bool 
    depisok(struct dependency *dep, struct varbuf *whynot,
             struct pkginfo **fixbyrm, struct pkginfo **fixbytrigaw,
             
            _Bool 
                 allowunconfigd);
struct cyclesofarlink;

_Bool 
    findbreakcycle(struct pkginfo *pkg);
void describedepcon(struct varbuf *addto, struct dependency *dep);

struct deppossi_pkg_iterator {
  struct deppossi *possi;
  struct pkginfo *pkg_next;
  enum which_pkgbin which_pkgbin;
};

struct deppossi_pkg_iterator *
deppossi_pkg_iter_new(struct deppossi *possi, enum which_pkgbin wpb)
{
  struct deppossi_pkg_iterator *iter;

  iter = m_malloc(sizeof(*iter));
  iter->possi = possi;
  iter->pkg_next = &possi->ed->pkg;
  iter->which_pkgbin = wpb;

  return iter;
}

struct pkginfo *
deppossi_pkg_iter_next(struct deppossi_pkg_iterator *iter)
{
  struct pkginfo *pkg_cur;
  struct pkgbin *pkgbin;

  while ((pkg_cur = iter->pkg_next)) {
    iter->pkg_next = pkg_cur->arch_next;

    switch (iter->which_pkgbin) {
    case wpb_installed:
      pkgbin = &pkg_cur->installed;
      break;
    case wpb_available:
      pkgbin = &pkg_cur->available;
      break;
    case wpb_by_istobe:
      if (pkg_cur->clientdata &&
          pkg_cur->clientdata->istobe == PKG_ISTOBE_INSTALLNEW)
        pkgbin = &pkg_cur->available;
      else
        pkgbin = &pkg_cur->installed;
      break;
    default:
      do_internerr("depcon.c", 85, __func__, "unknown which_pkgbin %d", iter->which_pkgbin);
    }

    if (archsatisfied(pkgbin, iter->possi))
      return pkg_cur;
  }

  return 
        ((void *)0)
            ;
}

void
deppossi_pkg_iter_free(struct deppossi_pkg_iterator *iter)
{
  free(iter);
}

struct cyclesofarlink {
  struct cyclesofarlink *prev;
  struct pkginfo *pkg;
  struct deppossi *possi;
};

static 
      _Bool 
           findbreakcyclerecursive(struct pkginfo *pkg,
                                    struct cyclesofarlink *sofar);

static 
      _Bool

foundcyclebroken(struct cyclesofarlink *thislink, struct cyclesofarlink *sofar,
                 struct pkginfo *dependedon, struct deppossi *possi)
{
  struct cyclesofarlink *sol;

  if(!possi)
    return 
          0
               ;





  for (sol = sofar; sol && sol->pkg != dependedon; sol = sol->prev);


  if (!sol)
    return findbreakcyclerecursive(dependedon, thislink);

  debug(dbg_depcon,"found cycle");
  sofar= thislink;
  for (sol = sofar; !(sol != sofar && sol->pkg == dependedon); sol = sol->prev) {
    if (!pkg_infodb_has_file(sol->pkg, &sol->pkg->installed, "postinst"))
      break;
  }



  sol->possi->cyclebreak = 
                          1
                              ;

  debug(dbg_depcon, "cycle broken at %s -> %s",
        pkg_name(sol->possi->up->up, pnaw_always), sol->possi->ed->name);

  return 
        1
            ;
}







static 
      _Bool

findbreakcyclerecursive(struct pkginfo *pkg, struct cyclesofarlink *sofar)
{
  struct cyclesofarlink thislink, *sol;
  struct dependency *dep;
  struct deppossi *possi, *providelink;
  struct pkginfo *provider, *pkg_pos;

  if (pkg->clientdata->color == PKG_CYCLE_BLACK)
    return 
          0
               ;
  pkg->clientdata->color = PKG_CYCLE_GRAY;

  if (debug_has_flag(dbg_depcondetail)) {
    struct varbuf str_pkgs = { 0, 0, 
                            ((void *)0) 
                            };

    for (sol = sofar; sol; sol = sol->prev) {
      varbuf_add_buf(&str_pkgs, " <- ", strlen(" <- "));
      varbuf_add_pkgbin_name(&str_pkgs, sol->pkg, &sol->pkg->installed, pnaw_nonambig);
    }
    varbuf_end_str(&str_pkgs);
    debug(dbg_depcondetail, "findbreakcyclerecursive %s %s",
          pkg_name(pkg, pnaw_always), str_pkgs.buf);
    varbuf_destroy(&str_pkgs);
  }
  thislink.pkg= pkg;
  thislink.prev = sofar;
  thislink.possi = 
                  ((void *)0)
                      ;
  for (dep= pkg->installed.depends; dep; dep= dep->next) {
    if (dep->type != dep_depends && dep->type != dep_predepends) continue;
    for (possi= dep->list; possi; possi= possi->next) {
      struct deppossi_pkg_iterator *possi_iter;


      if (possi->cyclebreak) continue;
      thislink.possi= possi;

      possi_iter = deppossi_pkg_iter_new(possi, wpb_installed);
      while ((pkg_pos = deppossi_pkg_iter_next(possi_iter)))
        if (foundcyclebroken(&thislink, sofar, pkg_pos, possi)) {
          deppossi_pkg_iter_free(possi_iter);
          return 
                1
                    ;
        }
      deppossi_pkg_iter_free(possi_iter);


      for (providelink = possi->ed->depended.installed;
           providelink;
           providelink = providelink->rev_next) {
        if (providelink->up->type != dep_provides) continue;
        provider= providelink->up->up;
        if (provider->clientdata->istobe == PKG_ISTOBE_NORMAL)
          continue;


        if (foundcyclebroken(&thislink, sofar, provider, possi))
          return 
                1
                    ;
      }
    }
  }

  pkg->clientdata->color = PKG_CYCLE_BLACK;
  return 
        0
             ;
}


_Bool

findbreakcycle(struct pkginfo *pkg)
{
  struct pkg_hash_iter *iter;
  struct pkginfo *tpkg;


  iter = pkg_hash_iter_new();
  while ((tpkg = pkg_hash_iter_next_pkg(iter))) {
    ensure_package_clientdata(tpkg);
    tpkg->clientdata->color = PKG_CYCLE_WHITE;
  }
  pkg_hash_iter_free(iter);

  return findbreakcyclerecursive(pkg, 
                                     ((void *)0)
                                         );
}

void describedepcon(struct varbuf *addto, struct dependency *dep) {
  struct varbuf depstr = { 0, 0, 
                        ((void *)0) 
                        };

  varbufdependency(&depstr, dep);
  varbuf_end_str(&depstr);

  switch (dep->type) {
  case dep_depends:
    varbuf_printf(addto, gettext("%s depends on %s"),
                  pkg_name(dep->up, pnaw_nonambig), depstr.buf);
    break;
  case dep_predepends:
    varbuf_printf(addto, gettext("%s pre-depends on %s"),
                  pkg_name(dep->up, pnaw_nonambig), depstr.buf);
    break;
  case dep_recommends:
    varbuf_printf(addto, gettext("%s recommends %s"),
                  pkg_name(dep->up, pnaw_nonambig), depstr.buf);
    break;
  case dep_suggests:
    varbuf_printf(addto, gettext("%s suggests %s"),
                  pkg_name(dep->up, pnaw_nonambig), depstr.buf);
    break;
  case dep_breaks:
    varbuf_printf(addto, gettext("%s breaks %s"),
                  pkg_name(dep->up, pnaw_nonambig), depstr.buf);
    break;
  case dep_conflicts:
    varbuf_printf(addto, gettext("%s conflicts with %s"),
                  pkg_name(dep->up, pnaw_nonambig), depstr.buf);
    break;
  case dep_enhances:
    varbuf_printf(addto, gettext("%s enhances %s"),
                  pkg_name(dep->up, pnaw_nonambig), depstr.buf);
    break;
  default:
    do_internerr("depcon.c", 277, __func__, "unknown deptype '%d'", dep->type);
  }

  varbuf_destroy(&depstr);
}

_Bool

depisok(struct dependency *dep, struct varbuf *whynot,
        struct pkginfo **canfixbyremove, struct pkginfo **canfixbytrigaw,
        
       _Bool 
            allowunconfigd)
{
  struct deppossi *possi;
  struct deppossi *provider;
  struct pkginfo *pkg_pos;
  int nconflicts;





  char linebuf[1024];

  if (dep->type != dep_depends &&
      dep->type != dep_predepends &&
      dep->type != dep_breaks &&
      dep->type != dep_conflicts &&
      dep->type != dep_recommends &&
      dep->type != dep_suggests &&
      dep->type != dep_enhances)
    do_internerr("depcon.c", 329, __func__, "unknown dependency type %d", dep->type);

  if (canfixbyremove)
    *canfixbyremove = 
                     ((void *)0)
                         ;
  if (canfixbytrigaw)
    *canfixbytrigaw = 
                     ((void *)0)
                         ;



  switch (dep->up->clientdata->istobe) {
  case PKG_ISTOBE_REMOVE:
  case PKG_ISTOBE_DECONFIGURE:
    return 
          1
              ;
  case PKG_ISTOBE_NORMAL:

    switch (dep->up->status) {
    case PKG_STAT_INSTALLED:
    case PKG_STAT_TRIGGERSPENDING:
    case PKG_STAT_TRIGGERSAWAITED:
      break;
    case PKG_STAT_HALFCONFIGURED:
    case PKG_STAT_UNPACKED:
    case PKG_STAT_HALFINSTALLED:
      if (dep->type == dep_predepends ||
          dep->type == dep_conflicts ||
          dep->type == dep_breaks)
        break;

    case PKG_STAT_CONFIGFILES:
    case PKG_STAT_NOTINSTALLED:
      return 
            1
                ;
    default:
      do_internerr("depcon.c", 361, __func__, "unknown status depending '%d'", dep->up->status);
    }
    break;
  case PKG_ISTOBE_INSTALLNEW:
  case PKG_ISTOBE_PREINSTALL:
    break;
  default:
    do_internerr("depcon.c", 368, __func__, "unknown istobe depending '%d'", dep->up->clientdata->istobe);
  }


  varbuf_reset(whynot);
  varbuf_add_char(whynot, ' ');
  describedepcon(whynot, dep);
  varbuf_add_char(whynot, '\n');


  if (dep->type == dep_depends || dep->type == dep_predepends ||
      dep->type == dep_recommends || dep->type == dep_suggests ) {





    for (possi= dep->list; possi; possi= possi->next) {
      struct deppossi_pkg_iterator *possi_iter;

      possi_iter = deppossi_pkg_iter_new(possi, wpb_by_istobe);
      while ((pkg_pos = deppossi_pkg_iter_next(possi_iter))) {
        switch (pkg_pos->clientdata->istobe) {
        case PKG_ISTOBE_REMOVE:
          sprintf(linebuf, gettext("  %.250s is to be removed.\n"),
                  pkg_name(pkg_pos, pnaw_nonambig));
          break;
        case PKG_ISTOBE_DECONFIGURE:
          sprintf(linebuf, gettext("  %.250s is to be deconfigured.\n"),
                  pkg_name(pkg_pos, pnaw_nonambig));
          break;
        case PKG_ISTOBE_INSTALLNEW:
          if (versionsatisfied(&pkg_pos->available, possi)) {
            deppossi_pkg_iter_free(possi_iter);
            return 
                  1
                      ;
          }
          sprintf(linebuf, gettext("  %.250s is to be installed, but is version " "%.250s.\n")
                                         ,
                  pkgbin_name(pkg_pos, &pkg_pos->available, pnaw_nonambig),
                  versiondescribe(&pkg_pos->available.version, vdew_nonambig));
          break;
        case PKG_ISTOBE_NORMAL:
        case PKG_ISTOBE_PREINSTALL:
          switch (pkg_pos->status) {
          case PKG_STAT_INSTALLED:
          case PKG_STAT_TRIGGERSPENDING:
            if (versionsatisfied(&pkg_pos->installed, possi)) {
              deppossi_pkg_iter_free(possi_iter);
              return 
                    1
                        ;
            }
            sprintf(linebuf, gettext("  %.250s is installed, but is version " "%.250s.\n")
                                           ,
                    pkg_name(pkg_pos, pnaw_nonambig),
                    versiondescribe(&pkg_pos->installed.version, vdew_nonambig));
            break;
          case PKG_STAT_NOTINSTALLED:



            *linebuf = '\0';
            break;
          case PKG_STAT_TRIGGERSAWAITED:
              if (canfixbytrigaw && versionsatisfied(&pkg_pos->installed, possi))
                *canfixbytrigaw = pkg_pos;

          case PKG_STAT_UNPACKED:
          case PKG_STAT_HALFCONFIGURED:
            if (allowunconfigd) {
              if (!dpkg_version_is_informative(&pkg_pos->configversion)) {
                sprintf(linebuf, gettext("  %.250s is unpacked, but has never been " "configured.\n")
                                                   ,
                        pkg_name(pkg_pos, pnaw_nonambig));
                break;
              } else if (!versionsatisfied(&pkg_pos->installed, possi)) {
                sprintf(linebuf, gettext("  %.250s is unpacked, but is version " "%.250s.\n")
                                               ,
                        pkg_name(pkg_pos, pnaw_nonambig),
                        versiondescribe(&pkg_pos->installed.version,
                                        vdew_nonambig));
                break;
              } else if (!dpkg_version_relate(&pkg_pos->configversion,
                                              possi->verrel,
                                              &possi->version)) {
                sprintf(linebuf, gettext("  %.250s latest configured version is " "%.250s.\n")
                                               ,
                        pkg_name(pkg_pos, pnaw_nonambig),
                        versiondescribe(&pkg_pos->configversion, vdew_nonambig));
                break;
              } else {
                deppossi_pkg_iter_free(possi_iter);
                return 
                      1
                          ;
              }
            }

          default:
            sprintf(linebuf, gettext("  %.250s is %s.\n"),
                    pkg_name(pkg_pos, pnaw_nonambig),
                    gettext(statusstrings[pkg_pos->status]));
            break;
          }
          break;
        default:
          do_internerr("depcon.c", 470, __func__, "unknown istobe depended '%d'", pkg_pos->clientdata->istobe);
        }
        varbuf_add_buf(whynot, linebuf, strlen(linebuf));
      }
      deppossi_pkg_iter_free(possi_iter);


        for (provider = possi->ed->depended.available;
             provider;
             provider = provider->rev_next) {
          if (provider->up->type != dep_provides) continue;
          if (!pkg_virtual_deppossi_satisfied(possi, provider))
            continue;
          if (provider->up->up->clientdata->istobe == PKG_ISTOBE_INSTALLNEW)
            return 
                  1
                      ;
        }


        for (provider = possi->ed->depended.installed;
             provider;
             provider = provider->rev_next) {
          if (provider->up->type != dep_provides) continue;
          if (!pkg_virtual_deppossi_satisfied(possi, provider))
            continue;

          switch (provider->up->up->clientdata->istobe) {
          case PKG_ISTOBE_INSTALLNEW:




            continue;
          case PKG_ISTOBE_REMOVE:
            sprintf(linebuf, gettext("  %.250s provides %.250s but is to be removed.\n"),
                    pkg_name(provider->up->up, pnaw_nonambig),
                    possi->ed->name);
            break;
          case PKG_ISTOBE_DECONFIGURE:
            sprintf(linebuf, gettext("  %.250s provides %.250s but is to be deconfigured.\n"),
                    pkg_name(provider->up->up, pnaw_nonambig),
                    possi->ed->name);
            break;
          case PKG_ISTOBE_NORMAL:
          case PKG_ISTOBE_PREINSTALL:
            if (provider->up->up->status == PKG_STAT_INSTALLED ||
                provider->up->up->status == PKG_STAT_TRIGGERSPENDING)
              return 
                    1
                        ;
            if (provider->up->up->status == PKG_STAT_TRIGGERSAWAITED)
              *canfixbytrigaw = provider->up->up;
            sprintf(linebuf, gettext("  %.250s provides %.250s but is %s.\n"),
                    pkg_name(provider->up->up, pnaw_nonambig),
                    possi->ed->name,
                    gettext(statusstrings[provider->up->up->status]));
            break;
          default:
            do_internerr("depcon.c", 525, __func__, "unknown istobe provider '%d'", provider->up->up->clientdata->istobe)
                                                           ;
          }
          varbuf_add_buf(whynot, linebuf, strlen(linebuf));
        }

        if (!*linebuf) {


          sprintf(linebuf, gettext("  %.250s is not installed.\n"), possi->ed->name);
          varbuf_add_buf(whynot, linebuf, strlen(linebuf));
        }
    }

    return 
          0
               ;
  } else {






    possi= dep->list;
    nconflicts= 0;

    if (possi->ed != possi->up->up->set) {
      struct deppossi_pkg_iterator *possi_iter;






      possi_iter = deppossi_pkg_iter_new(possi, wpb_by_istobe);
      while ((pkg_pos = deppossi_pkg_iter_next(possi_iter))) {
        switch (pkg_pos->clientdata->istobe) {
        case PKG_ISTOBE_REMOVE:
          break;
        case PKG_ISTOBE_INSTALLNEW:
          if (!versionsatisfied(&pkg_pos->available, possi))
            break;
          sprintf(linebuf, gettext("  %.250s (version %.250s) is to be installed.\n"),
                  pkgbin_name(pkg_pos, &pkg_pos->available, pnaw_nonambig),
                  versiondescribe(&pkg_pos->available.version, vdew_nonambig));
          varbuf_add_buf(whynot, linebuf, strlen(linebuf));
          if (!canfixbyremove) {
            deppossi_pkg_iter_free(possi_iter);
            return 
                  0
                       ;
          }
          nconflicts++;
          *canfixbyremove = pkg_pos;
          break;
        case PKG_ISTOBE_DECONFIGURE:
          if (dep->type == dep_breaks)
            break;

        case PKG_ISTOBE_NORMAL:
        case PKG_ISTOBE_PREINSTALL:
          switch (pkg_pos->status) {
          case PKG_STAT_NOTINSTALLED:
          case PKG_STAT_CONFIGFILES:
            break;
          case PKG_STAT_HALFINSTALLED:
          case PKG_STAT_UNPACKED:
          case PKG_STAT_HALFCONFIGURED:
            if (dep->type == dep_breaks)
              break;

          case PKG_STAT_INSTALLED:
          case PKG_STAT_TRIGGERSPENDING:
          case PKG_STAT_TRIGGERSAWAITED:
            if (!versionsatisfied(&pkg_pos->installed, possi))
              break;
            sprintf(linebuf, gettext("  %.250s (version %.250s) is present and %s.\n"),
                    pkg_name(pkg_pos, pnaw_nonambig),
                    versiondescribe(&pkg_pos->installed.version, vdew_nonambig),
                    gettext(statusstrings[pkg_pos->status]));
            varbuf_add_buf(whynot, linebuf, strlen(linebuf));
            if (!canfixbyremove) {
              deppossi_pkg_iter_free(possi_iter);
              return 
                    0
                         ;
            }
            nconflicts++;
            *canfixbyremove = pkg_pos;
          }
          break;
        default:
          do_internerr("depcon.c", 612, __func__, "unknown istobe conflict '%d'", pkg_pos->clientdata->istobe);
        }
      }
      deppossi_pkg_iter_free(possi_iter);
    }


      for (provider = possi->ed->depended.available;
           provider;
           provider = provider->rev_next) {
        if (provider->up->type != dep_provides) continue;
        if (provider->up->up->clientdata->istobe != PKG_ISTOBE_INSTALLNEW)
          continue;
        if (provider->up->up->set == dep->up->set)
          continue;
        if (!pkg_virtual_deppossi_satisfied(possi, provider))
          continue;
        sprintf(linebuf, gettext("  %.250s provides %.250s and is to be installed.\n"),
                pkgbin_name(provider->up->up, &provider->up->up->available,
                            pnaw_nonambig), possi->ed->name);
        varbuf_add_buf(whynot, linebuf, strlen(linebuf));

        if (canfixbyremove)
          *canfixbyremove = 
                           ((void *)0)
                               ;
        return 
              0
                   ;
      }


      for (provider = possi->ed->depended.installed;
           provider;
           provider = provider->rev_next) {
        if (provider->up->type != dep_provides) continue;

        if (provider->up->up->set == dep->up->set)
          continue;

        if (!pkg_virtual_deppossi_satisfied(possi, provider))
          continue;

        switch (provider->up->up->clientdata->istobe) {
        case PKG_ISTOBE_INSTALLNEW:




          continue;
        case PKG_ISTOBE_REMOVE:
          continue;
        case PKG_ISTOBE_DECONFIGURE:
          if (dep->type == dep_breaks)
            continue;

        case PKG_ISTOBE_NORMAL:
        case PKG_ISTOBE_PREINSTALL:
          switch (provider->up->up->status) {
          case PKG_STAT_NOTINSTALLED:
          case PKG_STAT_CONFIGFILES:
            continue;
          case PKG_STAT_HALFINSTALLED:
          case PKG_STAT_UNPACKED:
          case PKG_STAT_HALFCONFIGURED:
            if (dep->type == dep_breaks)
              break;

          case PKG_STAT_INSTALLED:
          case PKG_STAT_TRIGGERSPENDING:
          case PKG_STAT_TRIGGERSAWAITED:
            sprintf(linebuf,
                    gettext("  %.250s provides %.250s and is present and %s.\n"),
                    pkg_name(provider->up->up, pnaw_nonambig), possi->ed->name,
                    gettext(statusstrings[provider->up->up->status]));
            varbuf_add_buf(whynot, linebuf, strlen(linebuf));
            if (!canfixbyremove)
              return 
                    0
                         ;
            nconflicts++;
            *canfixbyremove= provider->up->up;
            break;
          }
          break;
        default:
          do_internerr("depcon.c", 692, __func__, "unknown istobe conflict provider '%d'", provider->up->up->clientdata->istobe)
                                                         ;
        }
      }

    if (!nconflicts)
      return 
            1
                ;
    if (nconflicts > 1)
      *canfixbyremove = 
                       ((void *)0)
                           ;
    return 
          0
               ;

  }
}
