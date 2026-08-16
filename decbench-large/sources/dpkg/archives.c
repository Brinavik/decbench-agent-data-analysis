





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












typedef int pkg_sorter_func(const void *a, const void *b);

void pkgset_link_pkg(struct pkgset *set, struct pkginfo *pkg);

void pkg_set_status(struct pkginfo *pkg, enum pkgstatus status);
void pkg_set_eflags(struct pkginfo *pkg, enum pkgeflag eflag);
void pkg_clear_eflags(struct pkginfo *pkg, enum pkgeflag eflag);
void pkg_reset_eflags(struct pkginfo *pkg);
void pkg_copy_eflags(struct pkginfo *pkg_dst, struct pkginfo *pkg_src);
void pkg_set_want(struct pkginfo *pkg, enum pkgwant want);















size_t path_trim_slash_slashdot(char *path);
const char *path_skip_slash_dotslash(const char *path);
const char *path_basename(const char *path);
char *path_quote_filename(char *dst, const char *src, size_t size);

char *path_make_temp_template(const char *suffix);

int secure_unlink_statted(const char *pathname, const struct stat *stab);
int secure_unlink(const char *pathname);
int secure_remove(const char *pathname);

void path_remove_tree(const char *pathname);












ssize_t fd_read(int fd, void *buf, size_t len);
ssize_t fd_write(int fd, const void *buf, size_t len);

int
fd_allocate_size(int fd, off_t offset, off_t len);





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












enum subproc_flags {

 SUBPROC_NORMAL = 0,

 SUBPROC_WARN = (1UL << (0)),

 SUBPROC_NOPIPE = (1UL << (1)),

 SUBPROC_NOCHECK = (1UL << (2)),

 SUBPROC_RETERROR = (1UL << (3)),

 SUBPROC_RETSIGNO = (1UL << (3)),
};

void subproc_signals_ignore(const char *name);
void subproc_signals_cleanup(int argc, void **argv);
void subproc_signals_restore(void);

pid_t subproc_fork(void);
int subproc_reap(pid_t pid, const char *desc, enum subproc_flags flags);





struct command {

 const char *name;

 const char *filename;
 int argc;
 int argv_size;
 const char **argv;
};

void command_init(struct command *cmd, const char *filename, const char *name);
void command_destroy(struct command *cmd);

void command_add_arg(struct command *cmd, const char *arg);
void command_add_argl(struct command *cmd, const char **argv);
void command_add_argv(struct command *cmd, va_list args);
void command_add_args(struct command *cmd, ...) __attribute__((sentinel));

void command_exec(struct command *cmd) __attribute__((noreturn));

void command_shell(const char *cmd, const char *name) __attribute__((noreturn));












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












enum treewalk_options {
 TREEWALK_NONE = 0,
 TREEWALK_FORCE_STAT = (1UL << (0)),
 TREEWALK_FOLLOW_LINKS = (1UL << (1)),
};

struct treenode;

typedef int treenode_visit_func(struct treenode *node);
typedef 
       _Bool 
            treenode_skip_func(struct treenode *node);
typedef int treenode_sort_func(struct treenode *node);

struct treewalk_funcs {
 treenode_visit_func *visit;
 treenode_sort_func *sort;
 treenode_skip_func *skip;
};

struct treeroot *
treewalk_open(const char *rootdir, enum treewalk_options options,
              struct treewalk_funcs *funcs);
struct treenode *
treewalk_node(struct treeroot *tree);
struct treenode *
treewalk_next(struct treeroot *tree);
void
treewalk_close(struct treeroot *tree);

int
treewalk(const char *rootdir, enum treewalk_options options,
         struct treewalk_funcs *funcs);

struct treenode *
treenode_get_parent(struct treenode *node);
const char *
treenode_get_name(struct treenode *node);
const char *
treenode_get_pathname(struct treenode *node);
const char *
treenode_get_virtname(struct treenode *node);
mode_t
treenode_get_mode(struct treenode *node);
struct stat *
treenode_get_stat(struct treenode *node);




enum tar_format {
 TAR_FORMAT_UNKNOWN,
 TAR_FORMAT_OLD,
 TAR_FORMAT_GNU,
 TAR_FORMAT_USTAR,
 TAR_FORMAT_PAX,
};

enum tar_filetype {

 TAR_FILETYPE_FILE0 = '\0',
 TAR_FILETYPE_FILE = '0',
 TAR_FILETYPE_HARDLINK = '1',
 TAR_FILETYPE_SYMLINK = '2',
 TAR_FILETYPE_CHARDEV = '3',
 TAR_FILETYPE_BLOCKDEV = '4',
 TAR_FILETYPE_DIR = '5',
 TAR_FILETYPE_FIFO = '6',
 TAR_FILETYPE_CONTIG = '7',
 TAR_FILETYPE_GNU_LONGLINK = 'K',
 TAR_FILETYPE_GNU_LONGNAME = 'L',
 TAR_FILETYPE_GNU_VOLUME = 'V',
 TAR_FILETYPE_GNU_MULTIVOL = 'M',
 TAR_FILETYPE_GNU_DUMPDIR = 'D',
 TAR_FILETYPE_GNU_SPARSE = 'S',
 TAR_FILETYPE_PAX_GLOBAL = 'g',
 TAR_FILETYPE_PAX_EXTENDED = 'x',
 TAR_FILETYPE_SOLARIS_EXTENDED = 'X',
 TAR_FILETYPE_SOLARIS_ACL = 'A',
};

struct tar_entry {

 enum tar_format format;

 enum tar_filetype type;

 char *name;

 char *linkname;

 off_t size;

 intmax_t mtime;

 dev_t dev;

 struct file_stat stat;
};

struct tar_archive;

typedef int tar_read_func(struct tar_archive *tar, char *buffer, int length);
typedef int tar_make_func(struct tar_archive *tar, struct tar_entry *h);

struct tar_operations {
 tar_read_func *read;

 tar_make_func *extract_file;
 tar_make_func *link;
 tar_make_func *symlink;
 tar_make_func *mkdir;
 tar_make_func *mknod;
};

struct tar_archive {

 struct dpkg_error err;


 enum tar_format format;


 const struct tar_operations *ops;
 void *ctx;
};

uintmax_t
tar_atoul(const char *s, size_t size, uintmax_t max);
intmax_t
tar_atosl(const char *s, size_t size, intmax_t min, intmax_t max);

void
tar_entry_update_from_system(struct tar_entry *te);

int
tar_extractor(struct tar_archive *tar);








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


const char *trig_name_is_illegal(const char *p);

enum trig_options {
 TRIG_AWAIT,
 TRIG_NOAWAIT,
};

struct trigfileint {
 struct pkginfo *pkg;
 struct pkgbin *pkgbin;
 struct fsys_namenode *fnn;
 enum trig_options options;
 struct trigfileint *samefile_next;
 struct {
  struct trigfileint *next, *prev;
 } inoverall;
};






struct trig_hooks {
 void (*enqueue_deferred)(struct pkginfo *pend);
 void (*transitional_activate)(enum modstatdb_rw cstatus);

 struct fsys_namenode *(*namenode_find)(const char *filename, 
                                                             _Bool 
                                                                  nonew);
 struct trigfileint **(*namenode_interested)(struct fsys_namenode *fnn);


 const char *(*namenode_name)(struct fsys_namenode *fnn);
};
void trig_override_hooks(const struct trig_hooks *hooks);

void trig_file_activate_byname(const char *trig, struct pkginfo *aw);
void trig_file_activate(struct fsys_namenode *trig, struct pkginfo *aw);
void trig_path_activate(struct fsys_namenode *trig, struct pkginfo *aw);


_Bool 
    trig_note_pend_core(struct pkginfo *pend, const char *trig );

_Bool 
    trig_note_pend(struct pkginfo *pend, const char *trig );

_Bool 
    trig_note_aw(struct pkginfo *pend, struct pkginfo *aw);
void trig_clear_awaiters(struct pkginfo *notpend);

typedef void trig_awaited_pend_foreach_func(struct pkginfo *pkg);

void trig_awaited_pend_enqueue(struct pkginfo *pend);
void trig_awaited_pend_foreach(trig_awaited_pend_foreach_func *func);
void trig_awaited_pend_free(void);

void trig_fixup_awaiters(enum modstatdb_rw cstatus);

void trig_file_interests_ensure(void);
void trig_file_interests_save(void);

typedef void trig_parse_cicb(const char *trig, struct pkginfo *pkg,
                             struct pkgbin *pkgbin, enum trig_options to);
void trig_cicb_interest_delete(const char *trig, struct pkginfo *pkg,
                             struct pkgbin *pkgbin, enum trig_options to);
void trig_cicb_interest_add(const char *trig, struct pkginfo *pkg,
                             struct pkgbin *pkgbin, enum trig_options to);
void trig_cicb_statuschange_activate(const char *trig, struct pkginfo *pkg,
                             struct pkgbin *pkgbin, enum trig_options to);
void trig_parse_ci(const char *file, trig_parse_cicb *interest,
                   trig_parse_cicb *activate, struct pkginfo *pkg,
                   struct pkgbin *pkgbin);

void trig_incorporate(enum modstatdb_rw cstatus);




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
struct tarcontext {
  int backendpipe;
  struct pkginfo *pkg;

  struct fsys_namenode_queue *newfiles_queue;

  
 _Bool 
      pkgset_getting_in_sync;
};

struct pkg_deconf_list {
  struct pkg_deconf_list *next;
  struct pkginfo *pkg;
  struct pkginfo *pkg_removal;
};

extern struct varbuf_state fname_state;
extern struct varbuf fnamevb;
extern struct varbuf fnametmpvb;
extern struct varbuf fnamenewvb;
extern struct pkg_deconf_list *deconfigure;

void clear_deconfigure_queue(void);
void enqueue_deconfigure(struct pkginfo *pkg, struct pkginfo *pkg_removal);
void enqueue_conflictor(struct pkginfo *pkg);

void cu_pathname(int argc, void **argv);
void cu_cidir(int argc, void **argv);
void cu_fileslist(int argc, void **argv);
void cu_backendpipe(int argc, void **argv);

void cu_installnew(int argc, void **argv);

void cu_prermupgrade(int argc, void **argv);
void cu_prerminfavour(int argc, void **argv);
void cu_preinstverynew(int argc, void **argv);
void cu_preinstnew(int argc, void **argv);
void cu_preinstupgrade(int argc, void **argv);
void cu_postrmupgrade(int argc, void **argv);

void cu_prermdeconfigure(int argc, void **argv);
void ok_prermdeconfigure(int argc, void **argv);

void setupfnamevbs(const char *filename);

int
tarobject(struct tar_archive *tar, struct tar_entry *ti);
int
tarfileread(struct tar_archive *tar, char *buf, int len);
void
tar_deferred_extract(struct fsys_namenode_list *files, struct pkginfo *pkg);

struct fsys_namenode_list *
tar_fsys_namenode_queue_push(struct fsys_namenode_queue *queue,
                             struct fsys_namenode *namenode);


_Bool

filesavespackage(struct fsys_namenode_list *, struct pkginfo *,
                 struct pkginfo *pkgbeinginstalled);

void check_conflict(struct dependency *dep, struct pkginfo *pkg,
                    const char *pfilename);
void check_breaks(struct dependency *dep, struct pkginfo *pkg,
                  const char *pfilename);

extern int cleanup_pkg_failed, cleanup_conflictor_failed;


void filter_add(const char *glob, 
                                 _Bool 
                                      include);

_Bool 
    filter_should_skip(struct tar_entry *ti);



static inline void
fd_writeback_init(int fd)
{




  sync_file_range(fd, 0, 0, 
                           2
                                                );



}

static struct obstack tar_pool;
static 
      _Bool 
           tar_pool_init = 
                           0
                                ;




static void *
tar_pool_alloc(size_t size)
{
  if (!tar_pool_init) {
    
   _obstack_begin ((
   &tar_pool
   ), 0, 0, (void *(*)(long))
   m_malloc
   , (void (*)(void *))
   free
   )
                          ;
    tar_pool_init = 
                   1
                       ;
  }

  return 
        __extension__ ({ struct obstack *__h = (
        &tar_pool
        ); __extension__ ({ struct obstack *__o = (__h); int __len = ((
        size
        )); if (__o->chunk_limit - __o->next_free < __len) _obstack_newchunk (__o, __len); ((__o)->next_free += (__len)); (void) 0; }); __extension__ ({ struct obstack *__o1 = (__h); void *__value = (void *) __o1->object_base; if (__o1->next_free == __value) __o1->maybe_empty_object = 1; __o1->next_free = ((sizeof (long int) < sizeof (void *) ? (__o1->object_base) : (char *) 0) + (((__o1->next_free) - (sizeof (long int) < sizeof (void *) ? (__o1->object_base) : (char *) 0) + (__o1->alignment_mask)) & ~(__o1->alignment_mask))); if (__o1->next_free - (char *) __o1->chunk > __o1->chunk_limit - (char *) __o1->chunk) __o1->next_free = __o1->chunk_limit; __o1->object_base = __o1->next_free; __value; }); })
                                      ;
}




static void
tar_pool_free(void *ptr)
{
  
 __extension__ ({ struct obstack *__o = (
 &tar_pool
 ); void *__obj = (
 ptr
 ); if (__obj > (void *) __o->chunk && __obj < (void *) __o->chunk_limit) __o->next_free = __o->object_base = (char *) __obj; else (obstack_free) (__o, __obj); })
                             ;
}




static void
tar_pool_release(void)
{
  if (tar_pool_init) {
    
   __extension__ ({ struct obstack *__o = (
   &tar_pool
   ); void *__obj = (((void *)0)); if (__obj > (void *) __o->chunk && __obj < (void *) __o->chunk_limit) __o->next_free = __o->object_base = (char *) __obj; else (obstack_free) (__o, __obj); })
                                ;
    tar_pool_init = 
                   0
                        ;
  }
}

struct fsys_namenode_list *
tar_fsys_namenode_queue_push(struct fsys_namenode_queue *queue,
                            struct fsys_namenode *namenode)
{
  struct fsys_namenode_list *node;

  node = tar_pool_alloc(sizeof(*node));
  node->namenode = namenode;
  node->next = 
              ((void *)0)
                  ;

  *queue->tail = node;
  queue->tail = &node->next;

  return node;
}

static void
tar_fsys_namenode_queue_pop(struct fsys_namenode_queue *queue,
                           struct fsys_namenode_list **tail_prev,
                           struct fsys_namenode_list *node)
{
  tar_pool_free(node);
  queue->tail = tail_prev;
  *tail_prev = 
              ((void *)0)
                  ;
}

_Bool

filesavespackage(struct fsys_namenode_list *file,
                 struct pkginfo *pkgtobesaved,
                 struct pkginfo *pkgbeinginstalled)
{
  struct fsys_node_pkgs_iter *iter;
  struct pkgset *divpkgset;
  struct pkginfo *thirdpkg;

  debug(dbg_eachfiledetail, "filesavespackage file '%s' package %s",
        file->namenode->name, pkg_name(pkgtobesaved, pnaw_always));





  if (file->namenode->divert && file->namenode->divert->useinstead) {
    divpkgset = file->namenode->divert->pkgset;
    if (divpkgset == pkgtobesaved->set || divpkgset == pkgbeinginstalled->set) {
      debug(dbg_eachfiledetail,"filesavespackage ... diverted -- save!");
      return 
            1
                ;
    }
  }

  if (file->namenode->flags & FNNF_NEW_INARCHIVE) {
    debug(dbg_eachfiledetail,"filesavespackage ... in new archive -- no save");
    return 
          0
               ;
  }


  iter = fsys_node_pkgs_iter_new(file->namenode);
  while ((thirdpkg = fsys_node_pkgs_iter_next(iter))) {
    debug(dbg_eachfiledetail, "filesavespackage ... also in %s",
          pkg_name(thirdpkg, pnaw_always));



    if (thirdpkg == pkgbeinginstalled || thirdpkg == pkgtobesaved)
      continue;




    if (pkgtobesaved->installed.multiarch == PKG_MULTIARCH_SAME &&
        thirdpkg->set == pkgtobesaved->set)
      continue;



    debug(dbg_eachfiledetail,"filesavespackage ...  is 3rd package");

    if (!thirdpkg->files_list_valid) {
      debug(dbg_eachfiledetail, "process_archive ... already disappeared!");
      continue;
    }


    debug(dbg_eachfiledetail, "filesavespackage ...  taken -- no save");
    fsys_node_pkgs_iter_free(iter);
    return 
          0
               ;
  }
  fsys_node_pkgs_iter_free(iter);

  debug(dbg_eachfiledetail, "filesavespackage ... not taken -- save !");
  return 
        1
            ;
}

static void
md5hash_prev_conffile(struct pkginfo *pkg, char *oldhash, const char *oldname,
                      struct fsys_namenode *namenode)
{
  struct pkginfo *otherpkg;
  struct conffile *conff;

  debug(dbg_conffdetail, "tarobject looking for shared conffile %s",
        namenode->name);

  for (otherpkg = &pkg->set->pkg; otherpkg; otherpkg = otherpkg->arch_next) {
    if (otherpkg == pkg)
      continue;



    if (otherpkg->status <= PKG_STAT_UNPACKED &&
        dpkg_version_compare(&otherpkg->installed.version,
                             &otherpkg->configversion) != 0)
      continue;
    for (conff = otherpkg->installed.conffiles; conff; conff = conff->next) {
      if (conff->obsolete || conff->remove_on_upgrade)
        continue;
      if (strcmp(conff->name, namenode->name) == 0)
        break;
    }
    if (conff) {
      strcpy(oldhash, conff->hash);
      debug(dbg_conffdetail,
            "tarobject found shared conffile, from pkg %s (%s); hash=%s",
            pkg_name(otherpkg, pnaw_always),
            pkg_status_name(otherpkg), oldhash);
      break;
    }
  }




  if (otherpkg == 
                 ((void *)0)
                     ) {
    md5hash(pkg, oldhash, oldname);
    debug(dbg_conffdetail,
          "tarobject found shared conffile, from disk; hash=%s", oldhash);
  }
}

void cu_pathname(int argc, void **argv) {
  path_remove_tree((char*)(argv[0]));
}

int
tarfileread(struct tar_archive *tar, char *buf, int len)
{
  struct tarcontext *tc = (struct tarcontext *)tar->ctx;
  int r;

  r = fd_read(tc->backendpipe, buf, len);
  if (r < 0)
    ohshite(gettext("error reading from dpkg-deb pipe"));
  return r;
}

static void
tarobject_skip_padding(struct tarcontext *tc, struct tar_entry *te)
{
  struct dpkg_error err;
  size_t r;

  r = te->size % 512;
  if (r == 0)
    return;

  if (buffer_skip_Int(tc->backendpipe, 0, 512 - r, &err) < 0)
    ohshit(gettext("cannot skip padding for file '%.255s': %s"), te->name, err.str);
}

static void
tarobject_skip_entry(struct tarcontext *tc, struct tar_entry *ti)
{


  if (ti->type == TAR_FILETYPE_FILE) {
    struct dpkg_error err;
    char fnamebuf[256];

    if (buffer_skip_Int(tc->backendpipe, 0, ti->size, &err) < 0)
      ohshit(gettext("cannot skip file '%.255s' (replaced or excluded?) from pipe: %s"),
             path_quote_filename(fnamebuf, ti->name, 256), err.str);
    tarobject_skip_padding(tc, ti);
  }
}

struct varbuf_state fname_state;
struct varbuf fnamevb;
struct varbuf fnametmpvb;
struct varbuf fnamenewvb;
struct pkg_deconf_list *deconfigure = 
                                     ((void *)0)
                                         ;

static time_t currenttime;

static int
does_replace(struct pkginfo *new_pkg, struct pkgbin *new_pkgbin,
             struct pkginfo *old_pkg, struct pkgbin *old_pkgbin)
{
  struct dependency *dep;

  debug(dbg_depcon,"does_replace new=%s old=%s (%s)",
        pkgbin_name(new_pkg, new_pkgbin, pnaw_always),
        pkgbin_name(old_pkg, old_pkgbin, pnaw_always),
        versiondescribe_c(&old_pkgbin->version, vdew_always));
  for (dep = new_pkgbin->depends; dep; dep = dep->next) {
    if (dep->type != dep_replaces || dep->list->ed != old_pkg->set)
      continue;
    debug(dbg_depcondetail,"does_replace ... found old, version %s",
          versiondescribe_c(&dep->list->version,vdew_always));
    if (!versionsatisfied(old_pkgbin, dep->list))
      continue;


    if (!archsatisfied(old_pkgbin, dep->list))
      continue;
    debug(dbg_depcon,"does_replace ... yes");
    return 
          1
              ;
  }
  debug(dbg_depcon,"does_replace ... no");
  return 
        0
             ;
}

static void
tarobject_extract(struct tarcontext *tc, struct tar_entry *te,
                  const char *path, struct file_stat *st,
                  struct fsys_namenode *namenode)
{
  static struct varbuf hardlinkfn;
  static int fd;

  struct dpkg_error err;
  struct fsys_namenode *linknode;
  char fnamebuf[256];
  char fnamenewbuf[256];
  char *newhash;
  int rc;

  switch (te->type) {
  case TAR_FILETYPE_FILE:


    fd = open(path, 
                   0100 
                           | 
                             0200 
                                    | 
                                      01
                                              , 0);
    if (fd < 0)
      ohshite(gettext("unable to create '%.255s' (while processing '%.255s')"),
              path, te->name);
    push_cleanup(cu_closefd, ehflag_bombout, 1, &fd);
    debug(dbg_eachfiledetail, "tarobject file open size=%jd",
          (intmax_t)te->size);




    fd_allocate_size(fd, 0, te->size);

    newhash = nfmalloc(32 + 1);
    if (buffer_copy_IntInt(tc->backendpipe, 0, newhash, 5, fd, 2, te->size, &err) < 0)
      ohshit(gettext("cannot copy extracted data for '%.255s' to '%.255s': %s"),
             path_quote_filename(fnamebuf, te->name, 256),
             path_quote_filename(fnamenewbuf, fnamenewvb.buf, 256), err.str);
    namenode->newhash = newhash;
    debug(dbg_eachfiledetail, "tarobject file hash=%s", namenode->newhash);

    tarobject_skip_padding(tc, te);

    fd_writeback_init(fd);

    if (namenode->statoverride)
      debug(dbg_eachfile, "tarobject ... stat override, uid=%d, gid=%d, mode=%04o",
            namenode->statoverride->uid,
            namenode->statoverride->gid,
            namenode->statoverride->mode);
    rc = fchown(fd, st->uid, st->gid);
    if (forcible_nonroot_error(rc))
      ohshite(gettext("error setting ownership of '%.255s'"), te->name);
    rc = fchmod(fd, st->mode & ~
                               0170000
                                     );
    if (forcible_nonroot_error(rc))
      ohshite(gettext("error setting permissions of '%.255s'"), te->name);


    if (!in_force(FORCE_UNSAFE_IO))
      namenode->flags |= FNNF_DEFERRED_FSYNC;

    pop_cleanup(ehflag_normaltidy);
    if (close(fd))
      ohshite(gettext("error closing/writing '%.255s'"), te->name);
    break;
  case TAR_FILETYPE_FIFO:
    if (mkfifo(path, 0))
      ohshite(gettext("error creating pipe '%.255s'"), te->name);
    debug(dbg_eachfiledetail, "tarobject fifo");
    break;
  case TAR_FILETYPE_CHARDEV:
    if (mknod(path, 
                   0020000
                          , te->dev))
      ohshite(gettext("error creating device '%.255s'"), te->name);
    debug(dbg_eachfiledetail, "tarobject chardev");
    break;
  case TAR_FILETYPE_BLOCKDEV:
    if (mknod(path, 
                   0060000
                          , te->dev))
      ohshite(gettext("error creating device '%.255s'"), te->name);
    debug(dbg_eachfiledetail, "tarobject blockdev");
    break;
  case TAR_FILETYPE_HARDLINK:
    varbuf_reset(&hardlinkfn);
    varbuf_add_buf(&hardlinkfn, instdir, strlen(instdir));
    linknode = fsys_hash_find_node(te->linkname, 0);
    varbuf_add_buf(&hardlinkfn, namenodetouse(linknode, tc->pkg, &tc->pkg->available)->name, strlen(namenodetouse(linknode, tc->pkg, &tc->pkg->available)->name))
                                                                               ;
    if (linknode->flags & (FNNF_DEFERRED_RENAME | FNNF_NEW_CONFF))
      varbuf_add_buf(&hardlinkfn, ".dpkg-new", strlen(".dpkg-new"));
    varbuf_end_str(&hardlinkfn);
    if (link(hardlinkfn.buf, path))
      ohshite(gettext("error creating hard link '%.255s'"), te->name);
    namenode->newhash = linknode->newhash;
    debug(dbg_eachfiledetail, "tarobject hardlink hash=%s", namenode->newhash);
    break;
  case TAR_FILETYPE_SYMLINK:

    if (symlink(te->linkname, path))
      ohshite(gettext("error creating symbolic link '%.255s'"), te->name);
    debug(dbg_eachfiledetail, "tarobject symlink creating");
    break;
  case TAR_FILETYPE_DIR:

    if (mkdir(path, 0))
      ohshite(gettext("error creating directory '%.255s'"), te->name);
    debug(dbg_eachfiledetail, "tarobject directory creating");
    break;
  default:
    do_internerr("archives.c", 451, __func__, "unknown tar type '%d', but already checked", te->type);
  }
}

static void
tarobject_hash(struct tarcontext *tc, struct tar_entry *te,
               struct fsys_namenode *namenode)
{
  if (te->type == TAR_FILETYPE_FILE) {
    struct dpkg_error err;
    char fnamebuf[256];
    char *newhash;

    newhash = nfmalloc(32 + 1);
    if (buffer_copy_IntPtr(tc->backendpipe, 0, newhash, 5, 
       ((void *)0)
       , 3, te->size, &err) < 0)
      ohshit(gettext("cannot compute MD5 hash for tar file '%.255s': %s"),
             path_quote_filename(fnamebuf, te->name, 256), err.str);
    tarobject_skip_padding(tc, te);

    namenode->newhash = newhash;
    debug(dbg_eachfiledetail, "tarobject file hash=%s", namenode->newhash);
  } else if (te->type == TAR_FILETYPE_HARDLINK) {
    struct fsys_namenode *linknode;

    linknode = fsys_hash_find_node(te->linkname, 0);
    namenode->newhash = linknode->newhash;
    debug(dbg_eachfiledetail, "tarobject hardlink hash=%s", namenode->newhash);
  }
}

static void
tarobject_set_mtime(struct tar_entry *te, const char *path)
{
  struct timeval tv[2];

  tv[0].tv_sec = currenttime;
  tv[0].tv_usec = 0;
  tv[1].tv_sec = te->mtime;
  tv[1].tv_usec = 0;

  if (te->type == TAR_FILETYPE_SYMLINK) {

    if (lutimes(path, tv) && 
                            (*__errno_location ()) 
                                  != 
                                     38
                                           )
      ohshite(gettext("error setting timestamps of '%.255s'"), path);

  } else {
    if (utimes(path, tv))
      ohshite(gettext("error setting timestamps of '%.255s'"), path);
  }
}

static void
tarobject_set_perms(struct tar_entry *te, const char *path, struct file_stat *st)
{
  int rc;

  if (te->type == TAR_FILETYPE_FILE)
    return;

  if (te->type == TAR_FILETYPE_SYMLINK) {
    rc = lchown(path, st->uid, st->gid);
    if (forcible_nonroot_error(rc))
      ohshite(gettext("error setting ownership of symlink '%.255s'"), path);
  } else {
    rc = chown(path, st->uid, st->gid);
    if (forcible_nonroot_error(rc))
      ohshite(gettext("error setting ownership of '%.255s'"), path);
    rc = chmod(path, st->mode & ~
                                0170000
                                      );
    if (forcible_nonroot_error(rc))
      ohshite(gettext("error setting permissions of '%.255s'"), path);
  }
}

static void
tarobject_set_se_context(const char *matchpath, const char *path, mode_t mode)
{
  dpkg_selabel_set_context(matchpath, path, mode);
}

static void
tarobject_matches(struct tarcontext *tc,
                  const char *fn_old, struct stat *stab, char *oldhash,
                  const char *fn_new, struct tar_entry *te,
                  struct fsys_namenode *namenode)
{
  char *linkname;
  ssize_t linksize;

  debug(dbg_eachfiledetail, "tarobject matches on-disk object?");

  switch (te->type) {
  case TAR_FILETYPE_DIR:

    return;
  case TAR_FILETYPE_SYMLINK:


    if (!
        ((((
        stab->st_mode
        )) & 0170000) == (0120000))
                              )
      break;
    linkname = m_malloc(stab->st_size + 1);
    linksize = readlink(fn_old, linkname, stab->st_size + 1);
    if (linksize < 0)
      ohshite(gettext("unable to read link '%.255s'"), fn_old);
    else if (linksize > stab->st_size)
      ohshit(gettext("symbolic link '%.250s' size has changed from %jd to %zd"),
             fn_old, (intmax_t)stab->st_size, linksize);
    else if (linksize < stab->st_size)
      warning(gettext("symbolic link '%.250s' size has changed from %jd to %zd"),
             fn_old, (intmax_t)stab->st_size, linksize);
    linkname[linksize] = '\0';
    if (strcmp(linkname, te->linkname) == 0) {
      free(linkname);
      return;
    } else {
      free(linkname);
    }
    break;
  case TAR_FILETYPE_CHARDEV:
    if (
       ((((
       stab->st_mode
       )) & 0170000) == (0020000)) 
                              && stab->st_rdev == te->dev)
      return;
    break;
  case TAR_FILETYPE_BLOCKDEV:
    if (
       ((((
       stab->st_mode
       )) & 0170000) == (0060000)) 
                              && stab->st_rdev == te->dev)
      return;
    break;
  case TAR_FILETYPE_FIFO:
    if (
       ((((
       stab->st_mode
       )) & 0170000) == (0010000))
                              )
      return;
    break;
  case TAR_FILETYPE_HARDLINK:

  case TAR_FILETYPE_FILE:

    if (!(namenode->flags & FNNF_NEW_CONFF) &&
        !(
         ((((
         stab->st_mode
         )) & 0170000) == (0100000)) 
                                && te->size == stab->st_size))
      break;
    if (strcmp(oldhash, namenode->newhash) == 0)
      return;
    break;
  default:
    do_internerr("archives.c", 591, __func__, "unknown tar type '%d', but already checked", te->type);
  }

  forcibleerr(FORCE_OVERWRITE,
              gettext("trying to overwrite shared '%.250s', which is different " "from other instances of package %.250s")
                                                         ,
              namenode->name, pkg_name(tc->pkg, pnaw_nonambig));
}

void setupfnamevbs(const char *filename) {
  varbuf_rollback(&fnamevb, &fname_state);
  varbuf_add_buf(&fnamevb, filename, strlen(filename));
  varbuf_end_str(&fnamevb);

  varbuf_rollback(&fnametmpvb, &fname_state);
  varbuf_add_buf(&fnametmpvb, filename, strlen(filename));
  varbuf_add_buf(&fnametmpvb, ".dpkg-tmp", strlen(".dpkg-tmp"));
  varbuf_end_str(&fnametmpvb);

  varbuf_rollback(&fnamenewvb, &fname_state);
  varbuf_add_buf(&fnamenewvb, filename, strlen(filename));
  varbuf_add_buf(&fnamenewvb, ".dpkg-new", strlen(".dpkg-new"));
  varbuf_end_str(&fnamenewvb);

  debug(dbg_eachfiledetail, "setupvnamevbs main='%s' tmp='%s' new='%s'",
        fnamevb.buf, fnametmpvb.buf, fnamenewvb.buf);
}

static 
      _Bool

linktosameexistingdir(const struct tar_entry *ti, const char *fname,
                      struct varbuf *symlinkfn)
{
  struct stat oldstab, newstab;
  int statr;
  const char *lastslash;

  statr= stat(fname, &oldstab);
  if (statr) {
    if (!(
         (*__errno_location ()) 
               == 
                  2 
                         || 
                            (*__errno_location ()) 
                                  == 
                                     40 
                                           || 
                                              (*__errno_location ()) 
                                                    == 
                                                       20
                                                              ))
      ohshite(gettext("failed to stat (dereference) existing symlink '%.250s'"),
              fname);
    return 
          0
               ;
  }
  if (!
      ((((
      oldstab.st_mode
      )) & 0170000) == (0040000))
                              )
    return 
          0
               ;


  varbuf_reset(symlinkfn);
  if (ti->linkname[0] == '/') {
    varbuf_add_buf(symlinkfn, instdir, strlen(instdir));
  } else {
    lastslash= strrchr(fname, '/');
    if (lastslash == 
                    ((void *)0)
                        )
      do_internerr("archives.c", 644, __func__, "tar entry filename '%s' does not contain '/'", fname);
    varbuf_add_buf(symlinkfn, fname, (lastslash - fname) + 1);
  }
  varbuf_add_buf(symlinkfn, ti->linkname, strlen(ti->linkname));
  varbuf_end_str(symlinkfn);

  statr= stat(symlinkfn->buf, &newstab);
  if (statr) {
    if (!(
         (*__errno_location ()) 
               == 
                  2 
                         || 
                            (*__errno_location ()) 
                                  == 
                                     40 
                                           || 
                                              (*__errno_location ()) 
                                                    == 
                                                       20
                                                              ))
      ohshite(gettext("failed to stat (dereference) proposed new symlink target" " '%.250s' for symlink '%.250s'")
                                                 , symlinkfn->buf, fname);
    return 
          0
               ;
  }
  if (!
      ((((
      newstab.st_mode
      )) & 0170000) == (0040000))
                              )
    return 
          0
               ;
  if (newstab.st_dev != oldstab.st_dev ||
      newstab.st_ino != oldstab.st_ino)
    return 
          0
               ;
  return 
        1
            ;
}

int
tarobject(struct tar_archive *tar, struct tar_entry *ti)
{
  static struct varbuf conffderefn, symlinkfn;
  const char *usename;
  struct fsys_namenode *namenode, *usenode;

  struct conffile *conff;
  struct tarcontext *tc = tar->ctx;
  
 _Bool 
      existingdir, keepexisting;
  
 _Bool 
      refcounting;
  char oldhash[32 + 1];
  int statr;
  ssize_t r;
  struct stat stab, stabtmp;
  struct file_stat nodestat;
  struct fsys_namenode_list *nifd, **oldnifd;
  struct pkgset *divpkgset;
  struct pkginfo *otherpkg;

  tar_entry_update_from_system(ti);


  if (strchr(ti->name, '\n'))
    ohshit(gettext("newline not allowed in archive object name '%.255s'"), ti->name);

  namenode = fsys_hash_find_node(ti->name, 0);

  if (namenode->flags & FNNF_RM_CONFF_ON_UPGRADE)
    ohshit(gettext("conffile '%s' marked for removal on upgrade, shipped in package"),
           ti->name);




  oldnifd = tc->newfiles_queue->tail;
  nifd = tar_fsys_namenode_queue_push(tc->newfiles_queue, namenode);
  nifd->namenode->flags |= FNNF_NEW_INARCHIVE;

  debug(dbg_eachfile,
        "tarobject ti->name='%s' mode=%lo owner=%u:%u type=%d(%c)"
        " ti->linkname='%s' namenode='%s' flags=%o instead='%s'",
        ti->name, (long)ti->stat.mode,
        (unsigned)ti->stat.uid, (unsigned)ti->stat.gid,
        ti->type,
        ti->type >= '0' && ti->type <= '6' ? "-hlcbdp"[ti->type - '0'] : '?',
        ti->linkname,
        nifd->namenode->name, nifd->namenode->flags,
        nifd->namenode->divert && nifd->namenode->divert->useinstead
        ? nifd->namenode->divert->useinstead->name : "<none>");

  if (nifd->namenode->divert && nifd->namenode->divert->camefrom) {
    divpkgset = nifd->namenode->divert->pkgset;

    if (divpkgset) {
      forcibleerr(FORCE_OVERWRITE_DIVERTED,
                  gettext("trying to overwrite '%.250s', which is the " "diverted version of '%.250s' (package: %.100s)")
                                                                     ,
                  nifd->namenode->name, nifd->namenode->divert->camefrom->name,
                  divpkgset->name);
    } else {
      forcibleerr(FORCE_OVERWRITE_DIVERTED,
                  gettext("trying to overwrite '%.250s', which is the " "diverted version of '%.250s'")
                                                   ,
                  nifd->namenode->name, nifd->namenode->divert->camefrom->name);
    }
  }

  if (nifd->namenode->statoverride) {
    nodestat = *nifd->namenode->statoverride;
    nodestat.mode |= ti->stat.mode & 
                                    0170000
                                          ;
  } else {
    nodestat = ti->stat;
  }

  usenode = namenodetouse(nifd->namenode, tc->pkg, &tc->pkg->available);
  usename = usenode->name;

  trig_file_activate(usenode, tc->pkg);

  if (nifd->namenode->flags & FNNF_NEW_CONFF) {


    if (conffderef(tc->pkg, &conffderefn, usename))
      usename= conffderefn.buf;
    debug(dbg_conff, "tarobject FNNF_NEW_CONFF deref='%s'", usename);
  }

  setupfnamevbs(usename);

  statr= lstat(fnamevb.buf,&stab);
  if (statr) {

    if (
       (*__errno_location ()) 
             != 
                2 
                       && 
                          (*__errno_location ()) 
                                != 
                                   20
                                          )
      ohshite(gettext("unable to stat '%.255s' (which was about to be installed)"),
              ti->name);




    if (rename(fnametmpvb.buf,fnamevb.buf)) {
      if (
         (*__errno_location ()) 
               != 
                  2 
                         && 
                            (*__errno_location ()) 
                                  != 
                                     20
                                            )
        ohshite(gettext("unable to clean up mess surrounding '%.255s' before " "installing another version")
                                               , ti->name);
      debug(dbg_eachfiledetail,"tarobject nonexistent");
    } else {
      debug(dbg_eachfiledetail,"tarobject restored tmp to main");
      statr= lstat(fnamevb.buf,&stab);
      if (statr)
        ohshite(gettext("unable to stat restored '%.255s' before installing" " another version")
                                     , ti->name);
    }
  } else {
    debug(dbg_eachfiledetail,"tarobject already exists");
  }




  existingdir = 
               0
                    ;
  switch (ti->type) {
  case TAR_FILETYPE_SYMLINK:

    if (!statr && 
                 ((((
                 stab.st_mode
                 )) & 0170000) == (0040000))
                                      ) {
      debug(dbg_eachfiledetail, "tarobject symlink exists as directory");
      existingdir = 
                   1
                       ;
    } else if (!statr && 
                        ((((
                        stab.st_mode
                        )) & 0170000) == (0120000))
                                             ) {
      if (linktosameexistingdir(ti, fnamevb.buf, &symlinkfn))
        existingdir = 
                     1
                         ;
    }
    break;
  case TAR_FILETYPE_DIR:

    if (!stat(fnamevb.buf,&stabtmp) && 
                                      ((((
                                      stabtmp.st_mode
                                      )) & 0170000) == (0040000))
                                                              ) {
      debug(dbg_eachfiledetail, "tarobject directory exists");
      existingdir = 
                   1
                       ;
    }
    break;
  case TAR_FILETYPE_FILE:
  case TAR_FILETYPE_CHARDEV:
  case TAR_FILETYPE_BLOCKDEV:
  case TAR_FILETYPE_FIFO:
  case TAR_FILETYPE_HARDLINK:
    break;
  default:
    ohshit(gettext("archive contained object '%.255s' of unknown type 0x%x"),
           ti->name, ti->type);
  }

  keepexisting = 
                0
                     ;
  refcounting = 
               0
                    ;
  if (!existingdir) {
    struct fsys_node_pkgs_iter *iter;

    iter = fsys_node_pkgs_iter_new(nifd->namenode);
    while ((otherpkg = fsys_node_pkgs_iter_next(iter))) {
      if (otherpkg == tc->pkg)
        continue;
      debug(dbg_eachfile, "tarobject ... found in %s",
            pkg_name(otherpkg, pnaw_always));




      if (otherpkg->set == tc->pkg->set &&
          otherpkg->installed.multiarch == PKG_MULTIARCH_SAME &&
          tc->pkg->available.multiarch == PKG_MULTIARCH_SAME) {
        if (statr == 0 && tc->pkgset_getting_in_sync)
          refcounting = 
                       1
                           ;
        debug(dbg_eachfiledetail, "tarobject ... shared with %s %s (syncing=%d)",
              pkg_name(otherpkg, pnaw_always),
              versiondescribe_c(&otherpkg->installed.version, vdew_nonambig),
              tc->pkgset_getting_in_sync);
        continue;
      }

      if (nifd->namenode->divert && nifd->namenode->divert->useinstead) {



        divpkgset = nifd->namenode->divert->pkgset;
        debug(dbg_eachfile, "tarobject ... diverted, divpkgset=%s",
              divpkgset ? divpkgset->name : "<none>");
        if (otherpkg->set == divpkgset || tc->pkg->set == divpkgset)
          continue;
      }





      if (statr != 0 && ti->type == TAR_FILETYPE_DIR) {
        debug(dbg_eachfile, "tarobject ... assuming shared directory");
        continue;
      }

      ensure_package_clientdata(otherpkg);


      switch (otherpkg->clientdata->replacingfilesandsaid) {
      case 2:
        keepexisting = 
                      1
                          ;

      case 1:
        continue;
      }




      if (otherpkg->status == PKG_STAT_CONFIGFILES)
        continue;


      if (otherpkg->clientdata->istobe == PKG_ISTOBE_REMOVE)
        continue;



      if ((nifd->namenode->flags & FNNF_NEW_CONFF) &&
          !statr && 
                   ((((
                   stab.st_mode
                   )) & 0170000) == (0100000))
                                        ) {
        for (conff = otherpkg->installed.conffiles;
             conff;
             conff = conff->next) {
          if (!conff->obsolete)
            continue;
          if (strcmp(conff->name, nifd->namenode->name) == 0)
            break;
        }
        if (conff) {
          debug(dbg_eachfiledetail, "tarobject other's obsolete conffile");

          continue;
        }
      }

      if (does_replace(tc->pkg, &tc->pkg->available,
                       otherpkg, &otherpkg->installed)) {
        printf(gettext("Replacing files in old package %s (%s) ...\n"),
               pkg_name(otherpkg, pnaw_nonambig),
               versiondescribe(&otherpkg->installed.version, vdew_nonambig));
        otherpkg->clientdata->replacingfilesandsaid = 1;
      } else if (does_replace(otherpkg, &otherpkg->installed,
                              tc->pkg, &tc->pkg->available)) {
        printf(gettext("Replaced by files in installed package %s (%s) ...\n"),
               pkg_name(otherpkg, pnaw_nonambig),
               versiondescribe(&otherpkg->installed.version, vdew_nonambig));
        otherpkg->clientdata->replacingfilesandsaid = 2;
        nifd->namenode->flags &= ~FNNF_NEW_INARCHIVE;
        keepexisting = 
                      1
                          ;
      } else {

        if (!statr && 
                     ((((
                     stab.st_mode
                     )) & 0170000) == (0040000))
                                          ) {
          forcibleerr(FORCE_OVERWRITE_DIR,
                      gettext("trying to overwrite directory '%.250s' " "in package %.250s %.250s with nondirectory")
                                                                     ,
                      nifd->namenode->name, pkg_name(otherpkg, pnaw_nonambig),
                      versiondescribe(&otherpkg->installed.version,
                                      vdew_nonambig));
        } else {
          forcibleerr(FORCE_OVERWRITE,
                      gettext("trying to overwrite '%.250s', " "which is also in package %.250s %.250s")
                                                                 ,
                      nifd->namenode->name, pkg_name(otherpkg, pnaw_nonambig),
                      versiondescribe(&otherpkg->installed.version,
                                      vdew_nonambig));
        }
      }
    }
    fsys_node_pkgs_iter_free(iter);
  }

  if (keepexisting) {
    if (nifd->namenode->flags & FNNF_NEW_CONFF)
      nifd->namenode->flags |= FNNF_OBS_CONFF;
    tar_fsys_namenode_queue_pop(tc->newfiles_queue, oldnifd, nifd);
    tarobject_skip_entry(tc, ti);
    return 0;
  }

  if (filter_should_skip(ti)) {
    nifd->namenode->flags &= ~FNNF_NEW_INARCHIVE;
    nifd->namenode->flags |= FNNF_FILTERED;
    tarobject_skip_entry(tc, ti);

    return 0;
  }

  if (existingdir)
    return 0;



  if (refcounting) {
    debug(dbg_eachfiledetail, "tarobject hashing on-disk file '%s', refcounting",
          fnamevb.buf);
    if (nifd->namenode->flags & FNNF_NEW_CONFF) {
      md5hash_prev_conffile(tc->pkg, oldhash, fnamenewvb.buf, nifd->namenode);
    } else if (
              ((((
              stab.st_mode
              )) & 0170000) == (0100000))
                                   ) {
      md5hash(tc->pkg, oldhash, fnamevb.buf);
    } else {
      strcpy(oldhash, "-");
    }
  }

  if (refcounting && !in_force(FORCE_OVERWRITE)) {


    tarobject_hash(tc, ti, nifd->namenode);
  } else {


    path_remove_tree(fnamenewvb.buf);
    path_remove_tree(fnametmpvb.buf);




    push_cleanup(cu_installnew, ~ehflag_normaltidy, 1, nifd->namenode);







    tarobject_extract(tc, ti, fnamenewvb.buf, &nodestat, nifd->namenode);
  }


  if (refcounting)
    tarobject_matches(tc, fnamevb.buf, &stab, oldhash,
                          fnamenewvb.buf, ti, nifd->namenode);


  if (refcounting && !in_force(FORCE_OVERWRITE))
    return 0;

  tarobject_set_perms(ti, fnamenewvb.buf, &nodestat);
  tarobject_set_mtime(ti, fnamenewvb.buf);
  tarobject_set_se_context(fnamevb.buf, fnamenewvb.buf, nodestat.mode);
  if (nifd->namenode->flags & FNNF_NEW_CONFF) {
    debug(dbg_conffdetail,"tarobject conffile extracted");
    nifd->namenode->flags |= FNNF_ELIDE_OTHER_LISTS;
    return 0;
  }



  if (statr) {

    debug(dbg_eachfiledetail,"tarobject new - no backup");
  } else {
    if (ti->type == TAR_FILETYPE_DIR || 
                                       ((((
                                       stab.st_mode
                                       )) & 0170000) == (0040000))
                                                            ) {

      debug(dbg_eachfiledetail,"tarobject directory, nonatomic");
      nifd->namenode->flags |= FNNF_NO_ATOMIC_OVERWRITE;
      if (rename(fnamevb.buf,fnametmpvb.buf))
        ohshite(gettext("unable to move aside '%.255s' to install new version"),
                ti->name);
    } else if (
              ((((
              stab.st_mode
              )) & 0170000) == (0120000))
                                   ) {
      int rc;




      varbuf_reset(&symlinkfn);
      varbuf_grow(&symlinkfn, stab.st_size + 1);
      r = readlink(fnamevb.buf, symlinkfn.buf, symlinkfn.size);
      if (r < 0)
        ohshite(gettext("unable to read link '%.255s'"), ti->name);
      else if (r > stab.st_size)
        ohshit(gettext("symbolic link '%.250s' size has changed from %jd to %zd"),
               fnamevb.buf, (intmax_t)stab.st_size, r);
      else if (r < stab.st_size)
        warning(gettext("symbolic link '%.250s' size has changed from %jd to %zd"),
               fnamevb.buf, (intmax_t)stab.st_size, r);
      varbuf_trunc(&symlinkfn, r);
      varbuf_end_str(&symlinkfn);
      if (symlink(symlinkfn.buf,fnametmpvb.buf))
        ohshite(gettext("unable to make backup symlink for '%.255s'"), ti->name);
      rc = lchown(fnametmpvb.buf, stab.st_uid, stab.st_gid);
      if (forcible_nonroot_error(rc))
        ohshite(gettext("unable to chown backup symlink for '%.255s'"), ti->name);
      tarobject_set_se_context(fnamevb.buf, fnametmpvb.buf, stab.st_mode);
    } else {
      debug(dbg_eachfiledetail, "tarobject nondirectory, 'link' backup");
      if (link(fnamevb.buf,fnametmpvb.buf))
        ohshite(gettext("unable to make backup link of '%.255s' before installing new version"),
                ti->name);
    }
  }






  if (ti->type == TAR_FILETYPE_FILE || ti->type == TAR_FILETYPE_HARDLINK ||
      ti->type == TAR_FILETYPE_SYMLINK) {
    nifd->namenode->flags |= FNNF_DEFERRED_RENAME;

    debug(dbg_eachfiledetail, "tarobject done and installation deferred");
  } else {
    if (rename(fnamenewvb.buf, fnamevb.buf))
      ohshite(gettext("unable to install new version of '%.255s'"), ti->name);
    nifd->namenode->flags |= FNNF_PLACED_ON_DISK;
    nifd->namenode->flags |= FNNF_ELIDE_OTHER_LISTS;

    debug(dbg_eachfiledetail, "tarobject done and installed");
  }

  return 0;
}


static void
tar_writeback_barrier(struct fsys_namenode_list *files, struct pkginfo *pkg)
{
  struct fsys_namenode_list *cfile;

  for (cfile = files; cfile; cfile = cfile->next) {
    struct fsys_namenode *usenode;
    int fd;

    if (!(cfile->namenode->flags & FNNF_DEFERRED_FSYNC))
      continue;

    usenode = namenodetouse(cfile->namenode, pkg, &pkg->available);

    setupfnamevbs(usenode->name);

    fd = open(fnamenewvb.buf, 
                             01
                                     );
    if (fd < 0)
      ohshite(gettext("unable to open '%.255s'"), fnamenewvb.buf);



    sync_file_range(fd, 0, 0, 
                             1
                                                        );
    if (close(fd))
      ohshite(gettext("error closing/writing '%.255s'"), fnamenewvb.buf);
  }
}







void
tar_deferred_extract(struct fsys_namenode_list *files, struct pkginfo *pkg)
{
  struct fsys_namenode_list *cfile;
  struct fsys_namenode *usenode;

  tar_writeback_barrier(files, pkg);

  for (cfile = files; cfile; cfile = cfile->next) {
    debug(dbg_eachfile, "deferred extract of '%.255s'", cfile->namenode->name);

    if (!(cfile->namenode->flags & FNNF_DEFERRED_RENAME))
      continue;

    usenode = namenodetouse(cfile->namenode, pkg, &pkg->available);

    setupfnamevbs(usenode->name);

    if (cfile->namenode->flags & FNNF_DEFERRED_FSYNC) {
      int fd;

      debug(dbg_eachfiledetail, "deferred extract needs fsync");

      fd = open(fnamenewvb.buf, 
                               01
                                       );
      if (fd < 0)
        ohshite(gettext("unable to open '%.255s'"), fnamenewvb.buf);
      if (fsync(fd))
        ohshite(gettext("unable to sync file '%.255s'"), fnamenewvb.buf);
      if (close(fd))
        ohshite(gettext("error closing/writing '%.255s'"), fnamenewvb.buf);

      cfile->namenode->flags &= ~FNNF_DEFERRED_FSYNC;
    }

    debug(dbg_eachfiledetail, "deferred extract needs rename");

    if (rename(fnamenewvb.buf, fnamevb.buf))
      ohshite(gettext("unable to install new version of '%.255s'"),
              cfile->namenode->name);

    cfile->namenode->flags &= ~FNNF_DEFERRED_RENAME;
    cfile->namenode->flags |= FNNF_PLACED_ON_DISK;
    cfile->namenode->flags |= FNNF_ELIDE_OTHER_LISTS;

    debug(dbg_eachfiledetail, "deferred extract done and installed");
  }
}

void
enqueue_deconfigure(struct pkginfo *pkg, struct pkginfo *pkg_removal)
{
  struct pkg_deconf_list *newdeconf;

  ensure_package_clientdata(pkg);
  pkg->clientdata->istobe = PKG_ISTOBE_DECONFIGURE;
  newdeconf = m_malloc(sizeof(*newdeconf));
  newdeconf->next = deconfigure;
  newdeconf->pkg = pkg;
  newdeconf->pkg_removal = pkg_removal;
  deconfigure = newdeconf;
}

void
clear_deconfigure_queue(void)
{
  struct pkg_deconf_list *deconf, *deconf_next;

  for (deconf = deconfigure; deconf; deconf = deconf_next) {
    deconf_next = deconf->next;
    free(deconf);
  }
  deconfigure = 
               ((void *)0)
                   ;
}
static int
try_deconfigure_can(
                   _Bool 
                        (*force_p)(struct deppossi *), struct pkginfo *pkg,
                    struct deppossi *pdep, const char *action,
                    struct pkginfo *removal, const char *why)
{
  if (force_p && force_p(pdep)) {
    warning(gettext("ignoring dependency problem with %s:\n%s"), action, why);
    return 2;
  } else if (f_autodeconf) {
    if (removal && pkg->installed.essential) {
      if (in_force(FORCE_REMOVE_ESSENTIAL)) {
        warning(gettext("considering deconfiguration of essential\n" " package %s, to enable %s")
                                              ,
                pkg_name(pkg, pnaw_nonambig), action);
      } else {
        notice(gettext("no, %s is essential, will not deconfigure\n" " it in order to enable %s")
                                             ,
               pkg_name(pkg, pnaw_nonambig), action);
        return 0;
      }
    }
    if (removal && pkg->installed.is_protected) {
      if (in_force(FORCE_REMOVE_PROTECTED)) {
        warning(gettext("considering deconfiguration of protected\n" " package %s, to enable %s")
                                              ,
                pkg_name(pkg, pnaw_nonambig), action);
      } else {
        notice(gettext("no, %s is protected, will not deconfigure\n" " it in order to enable %s")
                                             ,
               pkg_name(pkg, pnaw_nonambig), action);
        return 0;
      }
    }

    enqueue_deconfigure(pkg, removal);
    return 1;
  } else {
    notice(gettext("no, cannot proceed with %s (--auto-deconfigure will help):\n%s"),
           action, why);
    return 0;
  }
}

static int try_remove_can(struct deppossi *pdep,
                          struct pkginfo *fixbyrm,
                          const char *why) {
  char action[512];
  sprintf(action, gettext("removal of %.250s"), pkg_name(fixbyrm, pnaw_nonambig));
  return try_deconfigure_can(force_depends, pdep->up->up, pdep,
                             action, fixbyrm, why);
}

void check_breaks(struct dependency *dep, struct pkginfo *pkg,
                  const char *pfilename) {
  struct pkginfo *fixbydeconf;
  struct varbuf why = { 0, 0, 
                     ((void *)0) 
                     };
  int ok;

  fixbydeconf = 
               ((void *)0)
                   ;
  if (depisok(dep, &why, &fixbydeconf, 
                                      ((void *)0)
                                          , 
                                            0
                                                 )) {
    varbuf_destroy(&why);
    return;
  }

  varbuf_end_str(&why);

  if (fixbydeconf && f_autodeconf) {
    char action[512];

    ensure_package_clientdata(fixbydeconf);

    if (fixbydeconf->clientdata->istobe != PKG_ISTOBE_NORMAL)
      do_internerr("archives.c", 1305, __func__, "package %s being fixed by deconf is not to be normal, " "is to be %d", pkg_name(pkg, pnaw_always), fixbydeconf->clientdata->istobe)

                                                                            ;

    sprintf(action, gettext("installation of %.250s"),
            pkgbin_name(pkg, &pkg->available, pnaw_nonambig));
    notice(gettext("considering deconfiguration of %s, which would be broken by %s ..."),
           pkg_name(fixbydeconf, pnaw_nonambig), action);

    ok= try_deconfigure_can(force_breaks, fixbydeconf, dep->list,
                            action, 
                                   ((void *)0)
                                       , why.buf);
    if (ok == 1) {
      notice(gettext("yes, will deconfigure %s (broken by %s)"),
             pkg_name(fixbydeconf, pnaw_nonambig),
             pkgbin_name(pkg, &pkg->available, pnaw_nonambig));
    }
  } else {
    notice(gettext("regarding %s containing %s:\n%s"), pfilename,
           pkgbin_name(pkg, &pkg->available, pnaw_nonambig), why.buf);
    ok= 0;
  }
  varbuf_destroy(&why);
  if (ok > 0) return;

  if (force_breaks(dep->list)) {
    warning(gettext("ignoring breakage, may proceed anyway!"));
    return;
  }

  if (fixbydeconf && !f_autodeconf) {
    ohshit(gettext("installing %.250s would break %.250s, and\n" " deconfiguration is not permitted (--auto-deconfigure might help)")
                                                                                 ,
           pkgbin_name(pkg, &pkg->available, pnaw_nonambig),
           pkg_name(fixbydeconf, pnaw_nonambig));
  } else {
    ohshit(gettext("installing %.250s would break existing software"),
           pkgbin_name(pkg, &pkg->available, pnaw_nonambig));
  }
}

void check_conflict(struct dependency *dep, struct pkginfo *pkg,
                    const char *pfilename) {
  struct pkginfo *fixbyrm;
  struct deppossi *pdep, flagdeppossi = { 0 };
  struct varbuf conflictwhy = { 0, 0, 
                             ((void *)0) 
                             }, removalwhy = { 0, 0, 
                                                       ((void *)0) 
                                                       };
  struct dependency *providecheck;

  fixbyrm = 
           ((void *)0)
               ;
  if (depisok(dep, &conflictwhy, &fixbyrm, 
                                          ((void *)0)
                                              , 
                                                0
                                                     )) {
    varbuf_destroy(&conflictwhy);
    varbuf_destroy(&removalwhy);
    return;
  }
  if (fixbyrm) {
    ensure_package_clientdata(fixbyrm);
    if (fixbyrm->clientdata->istobe == PKG_ISTOBE_INSTALLNEW) {
      fixbyrm= dep->up;
      ensure_package_clientdata(fixbyrm);
    }
    if (((pkg->available.essential || pkg->available.is_protected) &&
         (fixbyrm->installed.essential || fixbyrm->installed.is_protected)) ||
        (((fixbyrm->want != PKG_WANT_INSTALL &&
           fixbyrm->want != PKG_WANT_HOLD) ||
          does_replace(pkg, &pkg->available, fixbyrm, &fixbyrm->installed)) &&
         ((!fixbyrm->installed.essential || in_force(FORCE_REMOVE_ESSENTIAL)) ||
          (!fixbyrm->installed.is_protected || in_force(FORCE_REMOVE_PROTECTED))))) {
      if (fixbyrm->clientdata->istobe != PKG_ISTOBE_NORMAL &&
          fixbyrm->clientdata->istobe != PKG_ISTOBE_DECONFIGURE)
        do_internerr("archives.c", 1373, __func__, "package %s to be fixed by removal is not to be normal " "nor deconfigure, is to be %d", pkg_name(pkg, pnaw_always), fixbyrm->clientdata->istobe)

                                                                          ;
      fixbyrm->clientdata->istobe = PKG_ISTOBE_REMOVE;
      notice(gettext("considering removing %s in favour of %s ..."),
             pkg_name(fixbyrm, pnaw_nonambig),
             pkgbin_name(pkg, &pkg->available, pnaw_nonambig));
      if (!(fixbyrm->status == PKG_STAT_INSTALLED ||
            fixbyrm->status == PKG_STAT_TRIGGERSPENDING ||
            fixbyrm->status == PKG_STAT_TRIGGERSAWAITED)) {
        notice(gettext("%s is not properly installed; ignoring any dependencies on it"),
               pkg_name(fixbyrm, pnaw_nonambig));
        pdep = 
              ((void *)0)
                  ;
      } else {
        for (pdep = fixbyrm->set->depended.installed;
             pdep;
             pdep = pdep->rev_next) {
          if (pdep->up->type != dep_depends && pdep->up->type != dep_predepends)
            continue;
          if (depisok(pdep->up, &removalwhy, 
                                            ((void *)0)
                                                , 
                                                  ((void *)0)
                                                      , 
                                                        0
                                                             ))
            continue;
          varbuf_end_str(&removalwhy);
          if (!try_remove_can(pdep,fixbyrm,removalwhy.buf))
            break;
        }
        if (!pdep) {

          for (providecheck= fixbyrm->installed.depends;
               providecheck;
               providecheck= providecheck->next) {
            if (providecheck->type != dep_provides) continue;
            for (pdep = providecheck->list->ed->depended.installed;
                 pdep;
                 pdep = pdep->rev_next) {
              if (pdep->up->type != dep_depends && pdep->up->type != dep_predepends)
                continue;
              if (depisok(pdep->up, &removalwhy, 
                                                ((void *)0)
                                                    , 
                                                      ((void *)0)
                                                          , 
                                                            0
                                                                 ))
                continue;
              varbuf_end_str(&removalwhy);
              notice(gettext("may have trouble removing %s, as it provides %s ..."),
                     pkg_name(fixbyrm, pnaw_nonambig),
                     providecheck->list->ed->name);
              if (!try_remove_can(pdep,fixbyrm,removalwhy.buf))
                goto break_from_both_loops_at_once;
            }
          }
        break_from_both_loops_at_once:;
        }
      }
      if (!pdep && skip_due_to_hold(fixbyrm)) {
        pdep= &flagdeppossi;
      }
      if (!pdep && (fixbyrm->eflag & PKG_EFLAG_REINSTREQ)) {
        if (in_force(FORCE_REMOVE_REINSTREQ)) {
          notice(gettext("package %s requires reinstallation, but will " "remove anyway as you requested")
                                                    ,
                 pkg_name(fixbyrm, pnaw_nonambig));
        } else {
          notice(gettext("package %s requires reinstallation, will not remove"),
                 pkg_name(fixbyrm, pnaw_nonambig));
          pdep= &flagdeppossi;
        }
      }
      if (!pdep) {

        enqueue_conflictor(fixbyrm);
        varbuf_destroy(&conflictwhy); varbuf_destroy(&removalwhy);
        notice(gettext("yes, will remove %s in favour of %s"),
               pkg_name(fixbyrm, pnaw_nonambig),
               pkgbin_name(pkg, &pkg->available, pnaw_nonambig));
        return;
      }

      fixbyrm->clientdata->istobe = PKG_ISTOBE_NORMAL;
    }
  }
  varbuf_end_str(&conflictwhy);
  notice(gettext("regarding %s containing %s:\n%s"), pfilename,
         pkgbin_name(pkg, &pkg->available, pnaw_nonambig), conflictwhy.buf);
  if (!force_conflicts(dep->list))
    ohshit(gettext("conflicting packages - not installing %.250s"),
           pkgbin_name(pkg, &pkg->available, pnaw_nonambig));
  warning(gettext("ignoring conflict, may proceed anyway!"));
  varbuf_destroy(&conflictwhy);

  return;
}

void cu_cidir(int argc, void **argv) {
  char *cidir= (char*)argv[0];
  char *cidirrest= (char*)argv[1];
  cidirrest[-1] = '\0';
  path_remove_tree(cidir);
  free(cidir);
}

void cu_fileslist(int argc, void **argv) {
  tar_pool_release();
}

int
archivefiles(const char *const *argv)
{
  const char *const *volatile argp;
  const char **volatile arglist = 
                                 ((void *)0)
                                     ;
  int i;
  jmp_buf ejbuf;
  enum modstatdb_rw msdbflags;

  trigproc_install_hooks();

  if (f_noact)
    msdbflags = msdbrw_readonly;
  else if (cipaction->arg_int == act_avail)
    msdbflags = msdbrw_readonly | msdbrw_available_write;
  else if (in_force(FORCE_NON_ROOT))
    msdbflags = msdbrw_write;
  else
    msdbflags = msdbrw_needsuperuser;

  modstatdb_open(msdbflags);

  checkpath();
  pkg_infodb_upgrade();

  log_message("startup archives %s", cipaction->olong);

  if (f_recursive) {
    const char *const *ap;
    int nfiles = 0;

    if (!*argv)
      badusage(gettext("--%s --recursive needs at least one path argument"),cipaction->olong);

    for (ap = argv; *ap; ap++) {
      struct treeroot *tree;
      struct treenode *node;

      tree = treewalk_open((const char *)*ap, TREEWALK_FOLLOW_LINKS, 
                                                                    ((void *)0)
                                                                        );

      while ((node = treewalk_next(tree))) {
        const char *nodename;

        if (!
            ((((
            treenode_get_mode(node)
            )) & 0170000) == (0100000))
                                            )
          continue;


        nodename = treenode_get_pathname(node);
        if (strcmp(nodename + strlen(nodename) - 4, ".deb") != 0)
          continue;

        arglist = m_realloc(arglist, sizeof(char *) * (nfiles + 2));
        arglist[nfiles++] = m_strdup(nodename);
      }

      treewalk_close(tree);
    }

    if (!nfiles)
      ohshit(gettext("searched, but found no packages (files matching *.deb)"));

    arglist[nfiles] = 
                     ((void *)0)
                         ;
    argp= arglist;
  } else {
    if (!*argv) badusage(gettext("--%s needs at least one package archive file argument"),
                         cipaction->olong);
    argp= argv;
  }


  for (i = 0; argp[i]; i++) {
    struct stat st;


    if (stat(argp[i], &st) < 0)
      ohshite(gettext("cannot access archive '%s'"), argp[i]);


    if (!
        ((((
        st.st_mode
        )) & 0170000) == (0100000))
                           )
      ohshit(gettext("archive '%s' is not a regular file"), argp[i]);
  }

  currenttime = time(
                    ((void *)0)
                        );



  varbuf_reset(&fnamevb);
  varbuf_reset(&fnametmpvb);
  varbuf_reset(&fnamenewvb);

  varbuf_add_buf(&fnamevb, instdir, strlen(instdir));
  varbuf_add_buf(&fnametmpvb, instdir, strlen(instdir));
  varbuf_add_buf(&fnamenewvb, instdir, strlen(instdir));

  varbuf_snapshot(&fnamevb, &fname_state);

  ensure_diversions();
  ensure_statoverrides(STATDB_PARSE_NORMAL);

  for (i = 0; argp[i]; i++) {
    if (
       _setjmp (
       ejbuf
       )
                    ) {
      pop_error_context(ehflag_bombout);
      if (abort_processing)
        break;
      continue;
    }
    push_error_context_jump(&ejbuf, print_error_perarchive, argp[i]);

    dpkg_selabel_load();

    process_archive(argp[i]);
    onerr_abort++;
    m_output(
            stdout
                  , gettext("<standard output>"));
    m_output(
            stderr
                  , gettext("<standard error>"));
    onerr_abort--;

    pop_error_context(ehflag_normaltidy);
  }

  dpkg_selabel_close();

  free(arglist);

  switch (cipaction->arg_int) {
  case act_install:
  case act_configure:
  case act_triggers:
  case act_remove:
  case act_purge:
    process_queue();
  case act_unpack:
  case act_avail:
    break;
  default:
    do_internerr("archives.c", 1607, __func__, "unknown action '%d'", cipaction->arg_int);
  }

  trigproc_run_deferred();
  modstatdb_shutdown();

  return 0;
}

_Bool

wanttoinstall(struct pkginfo *pkg)
{
  int rc;

  if (pkg->want != PKG_WANT_INSTALL && pkg->want != PKG_WANT_HOLD) {
    if (f_alsoselect) {
      printf(gettext("Selecting previously unselected package %s.\n"),
             pkgbin_name(pkg, &pkg->available, pnaw_nonambig));
      return 
            1
                ;
    } else {
      printf(gettext("Skipping unselected package %s.\n"),
             pkgbin_name(pkg, &pkg->available, pnaw_nonambig));
      return 
            0
                 ;
    }
  }

  if (pkg->eflag & PKG_EFLAG_REINSTREQ)
    return 
          1
              ;
  if (pkg->status < PKG_STAT_UNPACKED)
    return 
          1
              ;

  rc = dpkg_version_compare(&pkg->available.version, &pkg->installed.version);
  if (rc > 0) {
    return 
          1
              ;
  } else if (rc == 0) {

    if (f_skipsame) {
      notice(gettext("version %.250s of %.250s already installed, skipping"),
             versiondescribe(&pkg->installed.version, vdew_nonambig),
             pkg_name(pkg, pnaw_nonambig));
      return 
            0
                 ;
    } else {
      return 
            1
                ;
    }
  } else {
    if (in_force(FORCE_DOWNGRADE)) {
      warning(gettext("downgrading %.250s from %.250s to %.250s"),
              pkg_name(pkg, pnaw_nonambig),
              versiondescribe(&pkg->installed.version, vdew_nonambig),
              versiondescribe(&pkg->available.version, vdew_nonambig));
      return 
            1
                ;
    } else {
      notice(gettext("will not downgrade %.250s from %.250s to %.250s, skipping"),
             pkg_name(pkg, pnaw_nonambig),
             versiondescribe(&pkg->installed.version, vdew_nonambig),
             versiondescribe(&pkg->available.version, vdew_nonambig));
      return 
            0
                 ;
    }
  }
}
