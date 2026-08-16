





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






struct pkg_array {
 int n_pkgs;
 struct pkginfo **pkgs;
};

typedef struct pkginfo *pkg_mapper_func(const char *name);
typedef void pkg_array_visitor_func(struct pkg_array *a, struct pkginfo *pkg,
                                    void *pkg_data);

void pkg_array_init_from_hash(struct pkg_array *a);
void pkg_array_init_from_names(struct pkg_array *a, pkg_mapper_func *pkg_mapper,
                               const char **pkg_names);
void pkg_array_foreach(struct pkg_array *a, pkg_array_visitor_func *pkg_visitor,
                       void *pkg_data);
void pkg_array_sort(struct pkg_array *a, pkg_sorter_func *pkg_sort);
void pkg_array_destroy(struct pkg_array *a);












enum pkg_spec_flags {

 PKG_SPEC_PATTERNS = (1UL << (0)),


 PKG_SPEC_ARCH_SINGLE = (1UL << (8)),
 PKG_SPEC_ARCH_WILDCARD = (1UL << (9)),
 PKG_SPEC_ARCH_MASK = 0xff00,
};

struct pkg_spec {
 char *name;
 const struct dpkg_arch *arch;

 enum pkg_spec_flags flags;



 
_Bool 
     name_is_pattern;
 
_Bool 
     arch_is_pattern;


 struct pkg_hash_iter *pkg_iter;

 struct pkginfo *pkg_next;
};

void pkg_spec_init(struct pkg_spec *ps, enum pkg_spec_flags flags);
void pkg_spec_destroy(struct pkg_spec *ps);

const char *pkg_spec_is_illegal(struct pkg_spec *ps);

const char *pkg_spec_set(struct pkg_spec *ps,
                         const char *pkgname, const char *archname);
const char *pkg_spec_parse(struct pkg_spec *ps, const char *str);

_Bool 
    pkg_spec_match_pkg(struct pkg_spec *ps,
                        struct pkginfo *pkg, struct pkgbin *pkgbin);

struct pkginfo *pkg_spec_parse_pkg(const char *str, struct dpkg_error *err);
struct pkginfo *pkg_spec_find_pkg(const char *pkgname, const char *archname,
                                  struct dpkg_error *err);

void pkg_spec_iter_init(struct pkg_spec *ps);
struct pkginfo *pkg_spec_iter_next_pkg(struct pkg_spec *ps);
void pkg_spec_iter_destroy(struct pkg_spec *ps);












struct pkg_format_node;


_Bool

pkg_format_needs_db_fsys(const struct pkg_format_node *head);

struct pkg_format_node *pkg_format_parse(const char *fmt,
                                         struct dpkg_error *err);
void pkg_format_free(struct pkg_format_node *head);
void pkg_format_show(const struct pkg_format_node *head,
                     struct pkginfo *pkg, struct pkgbin *pkgbin);












int pkg_sorter_by_nonambig_name_arch(const void *a, const void *b);

const char *pkgbin_synopsis(const struct pkginfo *pkg,
                            const struct pkgbin *pkgbin, int *len_ret);
const char *
pkg_synopsis(const struct pkginfo *pkg, int *len_ret);
int pkg_abbrev_want(const struct pkginfo *pkg);
int pkg_abbrev_status(const struct pkginfo *pkg);
int pkg_abbrev_eflag(const struct pkginfo *pkg);
















size_t path_trim_slash_slashdot(char *path);
const char *path_skip_slash_dotslash(const char *path);
const char *path_basename(const char *path);
char *path_quote_filename(char *dst, const char *src, size_t size);

char *path_make_temp_template(const char *suffix);

int secure_unlink_statted(const char *pathname, const struct stat *stab);
int secure_unlink(const char *pathname);
int secure_remove(const char *pathname);

void path_remove_tree(const char *pathname);












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












struct pager;

void
pager_enable(
            _Bool 
                 enable);

const char *
pager_get_exec(void);

struct pager *
pager_spawn(const char *desc);

void
pager_reap(struct pager *pager);












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

static const char *showformat = "${binary:Package}\t${Version}\n";

static int opt_loadavail = 0;

static int
pkg_array_match_patterns(struct pkg_array *array,
                         pkg_array_visitor_func *pkg_visitor, void *pkg_data,
                         const char *const *argv)
{
  int argc, i, ip, *found;
  int rc = 0;
  struct pkg_spec *ps;

  for (argc = 0; argv[argc]; argc++);
  found = m_calloc(argc, sizeof(int));

  ps = m_malloc(sizeof(*ps) * argc);
  for (ip = 0; ip < argc; ip++) {
    pkg_spec_init(&ps[ip], PKG_SPEC_PATTERNS | PKG_SPEC_ARCH_WILDCARD);
    pkg_spec_parse(&ps[ip], argv[ip]);
  }

  for (i = 0; i < array->n_pkgs; i++) {
    struct pkginfo *pkg;
    
   _Bool 
        pkg_found = 
                    0
                         ;

    pkg = array->pkgs[i];
    for (ip = 0; ip < argc; ip++) {
      if (pkg_spec_match_pkg(&ps[ip], pkg, &pkg->installed)) {
        pkg_found = 
                   1
                       ;
        found[ip]++;
      }
    }
    if (!pkg_found)
      array->pkgs[i] = 
                      ((void *)0)
                          ;
  }

  pkg_array_foreach(array, pkg_visitor, pkg_data);

  for (ip = 0; ip < argc; ip++) {
    if (!found[ip]) {
      notice(gettext("no packages found matching %s"), argv[ip]);
      rc++;
    }
    pkg_spec_destroy(&ps[ip]);
  }

  free(ps);
  free(found);

  return rc;
}

struct list_format {
  
 _Bool 
      head;
  int nw;
  int vw;
  int aw;
  int dw;
};

static void
list_format_init(struct list_format *fmt, struct pkg_array *array)
{
  int i;

  if (fmt->nw != 0)
    return;

  fmt->nw = 14;
  fmt->vw = 12;
  fmt->aw = 12;
  fmt->dw = 33;

  for (i = 0; i < array->n_pkgs; i++) {
    int plen, vlen, alen, dlen;

    if (array->pkgs[i] == 
                         ((void *)0)
                             )
      continue;

    plen = str_width(pkg_name(array->pkgs[i], pnaw_nonambig));
    vlen = str_width(versiondescribe(&array->pkgs[i]->installed.version,
                                     vdew_nonambig));
    alen = str_width(dpkg_arch_describe(array->pkgs[i]->installed.arch));
    pkg_synopsis(array->pkgs[i], &dlen);

    if (plen > fmt->nw)
      fmt->nw = plen;
    if (vlen > fmt->vw)
      fmt->vw = vlen;
    if (alen > fmt->aw)
      fmt->aw = alen;
    if (dlen > fmt->dw)
      fmt->dw = dlen;
  }
}

static void
list_format_print(struct list_format *fmt,
                  int c_want, int c_status, int c_eflag,
                  const char *name, const char *version, const char *arch,
                  const char *desc, int desc_len)
{
  struct str_crop_info ns, vs, as, ds;

  str_gen_crop(name, fmt->nw, &ns);
  str_gen_crop(version, fmt->vw, &vs);
  str_gen_crop(arch, fmt->aw, &as);
  str_gen_crop(desc, desc_len, &ds);

  printf("%c%c%c %-*.*s %-*.*s %-*.*s %.*s\n", c_want, c_status, c_eflag,
         ns.max_bytes, ns.str_bytes, name,
         vs.max_bytes, vs.str_bytes, version,
         as.max_bytes, as.str_bytes, arch,
         ds.str_bytes, desc);
}

static void
list_format_print_header(struct list_format *fmt)
{
  int l;

  if (fmt->head)
    return;







  fputs(gettext("Desired=Unknown/Install/Remove/Purge/Hold\n| Status=Not/Inst/Conf-files/Unpacked/halF-conf/Half-inst/trig-aWait/Trig-pend\n|/ Err?=(none)/Reinst-required (Status,Err: uppercase=bad)\n")


                                                              , 
                                                               stdout
                                                                     );
  list_format_print(fmt, '|', '|', '/', gettext("Name"), gettext("Version"),
                    gettext("Architecture"), gettext("Description"), fmt->dw);


  printf("+++-");


  for (l = 0; l < fmt->nw; l++)
    printf("=");
  printf("-");


  for (l = 0; l < fmt->vw; l++)
    printf("=");
  printf("-");


  for (l = 0; l < fmt->aw; l++)
    printf("=");
  printf("-");


  for (l = 0; l < fmt->dw; l++)
    printf("=");
  printf("\n");

  fmt->head = 
             1
                 ;
}

static void
pkg_array_list_item(struct pkg_array *array, struct pkginfo *pkg, void *pkg_data)
{
  struct list_format *fmt = pkg_data;
  int l;
  const char *pdesc;

  list_format_init(fmt, array);
  list_format_print_header(fmt);

  pdesc = pkg_synopsis(pkg, &l);
  l = ((l) < (fmt->dw) ? (l) : (fmt->dw));

  list_format_print(fmt,
                    pkg_abbrev_want(pkg),
                    pkg_abbrev_status(pkg),
                    pkg_abbrev_eflag(pkg),
                    pkg_name(pkg, pnaw_nonambig),
                    versiondescribe(&pkg->installed.version, vdew_nonambig),
                    dpkg_arch_describe(pkg->installed.arch),
                    pdesc, l);
}

static int
listpackages(const char *const *argv)
{
  struct pkg_array array;
  struct pkginfo *pkg;
  int i;
  int rc = 0;
  struct list_format fmt;
  struct pager *pager;

  if (!opt_loadavail)
    modstatdb_open(msdbrw_readonly);
  else
    modstatdb_open(msdbrw_readonly | msdbrw_available_readonly);

  pkg_array_init_from_hash(&array);
  pkg_array_sort(&array, pkg_sorter_by_nonambig_name_arch);

  memset(&fmt, 0, sizeof(fmt));

  pager = pager_spawn(gettext("showing package list on pager"));

  if (!*argv) {
    for (i = 0; i < array.n_pkgs; i++) {
      pkg = array.pkgs[i];
      if (pkg->status == PKG_STAT_NOTINSTALLED)
        array.pkgs[i] = 
                       ((void *)0)
                           ;
    }

    pkg_array_foreach(&array, pkg_array_list_item, &fmt);
  } else {
    rc = pkg_array_match_patterns(&array, pkg_array_list_item, &fmt, argv);
  }

  m_output(
          stdout
                , gettext("<standard output>"));
  m_output(
          stderr
                , gettext("<standard error>"));

  pager_reap(pager);

  pkg_array_destroy(&array);
  modstatdb_shutdown();

  return rc;
}

static int
searchoutput(struct fsys_namenode *namenode)
{
  struct fsys_node_pkgs_iter *iter;
  struct pkginfo *pkg_owner;
  int found;

  if (namenode->divert) {
    const char *name_from = namenode->divert->camefrom ?
                            namenode->divert->camefrom->name : namenode->name;
    const char *name_to = namenode->divert->useinstead ?
                          namenode->divert->useinstead->name : namenode->name;

    if (namenode->divert->pkgset) {
      printf(gettext("diversion by %s from: %s\n"),
             namenode->divert->pkgset->name, name_from);
      printf(gettext("diversion by %s to: %s\n"),
             namenode->divert->pkgset->name, name_to);
    } else {
      printf(gettext("local diversion from: %s\n"), name_from);
      printf(gettext("local diversion to: %s\n"), name_to);
    }
  }
  found= 0;

  iter = fsys_node_pkgs_iter_new(namenode);
  while ((pkg_owner = fsys_node_pkgs_iter_next(iter))) {
    if (found)
      fputs(", ", 
                 stdout
                       );
    fputs(pkg_name(pkg_owner, pnaw_nonambig), 
                                             stdout
                                                   );
    found++;
  }
  fsys_node_pkgs_iter_free(iter);

  if (found) printf(": %s\n",namenode->name);
  return found + (namenode->divert ? 1 : 0);
}

static int
searchfiles(const char *const *argv)
{
  struct fsys_namenode *namenode;
  struct fsys_hash_iter *iter;
  const char *thisarg;
  int found;
  int failures = 0;
  struct varbuf path = { 0, 0, 
                      ((void *)0) 
                      };
  static struct varbuf vb;

  if (!*argv)
    badusage(gettext("--search needs at least one file name pattern argument"));

  modstatdb_open(msdbrw_readonly);
  ensure_allinstfiles_available_quiet();
  ensure_diversions();

  while ((thisarg = *argv++) != 
                               ((void *)0)
                                   ) {
    found= 0;

    if (!strchr("*[?/",*thisarg)) {
      varbuf_reset(&vb);
      varbuf_add_char(&vb, '*');
      varbuf_add_buf(&vb, thisarg, strlen(thisarg));
      varbuf_add_char(&vb, '*');
      varbuf_end_str(&vb);
      thisarg= vb.buf;
    }
    if (!strpbrk(thisarg, "*[?\\")) {


      varbuf_reset(&path);
      varbuf_add_buf(&path, thisarg, strlen(thisarg));
      varbuf_end_str(&path);
      varbuf_trunc(&path, path_trim_slash_slashdot(path.buf));

      namenode = fsys_hash_find_node(path.buf, 0);
      found += searchoutput(namenode);
    } else {
      iter = fsys_hash_iter_new();
      while ((namenode = fsys_hash_iter_next(iter)) != 
                                                      ((void *)0)
                                                          ) {
        if (fnmatch(thisarg,namenode->name,0)) continue;
        found+= searchoutput(namenode);
      }
      fsys_hash_iter_free(iter);
    }
    if (!found) {
      notice(gettext("no path found matching pattern %s"), thisarg);
      failures++;
      m_output(
              stderr
                    , gettext("<standard error>"));
    } else {
      m_output(
              stdout
                    , gettext("<standard output>"));
    }
  }
  modstatdb_shutdown();

  varbuf_destroy(&path);

  return failures;
}

static int
print_status(const char *const *argv)
{
  const char *thisarg;
  struct pkginfo *pkg;
  int failures = 0;

  modstatdb_open(msdbrw_readonly);

  if (!*argv) {
    writedb_records(
                   stdout
                         , gettext("<standard output>"), 0);
  } else {
    while ((thisarg = *argv++) != 
                                 ((void *)0)
                                     ) {
      pkg = dpkg_options_parse_pkgname(cipaction, thisarg);

      if (pkg->status == PKG_STAT_NOTINSTALLED &&
          pkg->priority == PKG_PRIO_UNKNOWN &&
          str_is_unset(pkg->section) &&
          !pkg->archives &&
          pkg->want == PKG_WANT_UNKNOWN &&
          !pkg_is_informative(pkg, &pkg->installed)) {
        notice(gettext("package '%s' is not installed and no information is available"),
               pkg_name(pkg, pnaw_nonambig));
        failures++;
      } else {
        writerecord(
                   stdout
                         , gettext("<standard output>"), pkg, &pkg->installed);
      }

      if (*argv != 
                  ((void *)0)
                      )
        putchar('\n');
    }
  }

  m_output(
          stdout
                , gettext("<standard output>"));
  if (failures) {
    fputs(gettext("Use dpkg --info (= dpkg-deb --info) to examine archive files.\n"),
          
         stderr
               );
    m_output(
            stderr
                  , gettext("<standard error>"));
  }

  modstatdb_shutdown();

  return failures;
}

static int
print_avail(const char *const *argv)
{
  const char *thisarg;
  struct pkginfo *pkg;
  int failures = 0;

  modstatdb_open(msdbrw_readonly | msdbrw_available_readonly);

  if (!*argv) {
    writedb_records(
                   stdout
                         , gettext("<standard output>"), wdb_dump_available);
  } else {
    while ((thisarg = *argv++) != 
                                 ((void *)0)
                                     ) {
      pkg = dpkg_options_parse_pkgname(cipaction, thisarg);

      if (!pkg_is_informative(pkg, &pkg->available)) {
        notice(gettext("package '%s' is not available"),
               pkgbin_name(pkg, &pkg->available, pnaw_nonambig));
        failures++;
      } else {
        writerecord(
                   stdout
                         , gettext("<standard output>"), pkg, &pkg->available);
      }

      if (*argv != 
                  ((void *)0)
                      )
        putchar('\n');
    }
  }

  m_output(
          stdout
                , gettext("<standard output>"));
  if (failures)
    m_output(
            stderr
                  , gettext("<standard error>"));

  modstatdb_shutdown();

  return failures;
}

static int
list_files(const char *const *argv)
{
  const char *thisarg;
  struct fsys_namenode_list *file;
  struct pkginfo *pkg;
  struct fsys_namenode *namenode;
  int failures = 0;

  if (!*argv)
    badusage(gettext("--%s needs at least one package name argument"), cipaction->olong);

  modstatdb_open(msdbrw_readonly);

  while ((thisarg = *argv++) != 
                               ((void *)0)
                                   ) {
    pkg = dpkg_options_parse_pkgname(cipaction, thisarg);

    switch (pkg->status) {
    case PKG_STAT_NOTINSTALLED:
      notice(gettext("package '%s' is not installed"),
             pkg_name(pkg, pnaw_nonambig));
      failures++;
      break;
    default:
      ensure_packagefiles_available(pkg);
      ensure_diversions();
      file = pkg->files;
      if (!file) {
        printf(gettext("Package '%s' does not contain any files (!)\n"),
               pkg_name(pkg, pnaw_nonambig));
      } else {
        while (file) {
          namenode = file->namenode;
          puts(namenode->name);
          if (namenode->divert && !namenode->divert->camefrom) {
            if (!namenode->divert->pkgset)
              printf(gettext("locally diverted to: %s\n"),
                     namenode->divert->useinstead->name);
            else if (pkg->set == namenode->divert->pkgset)
              printf(gettext("package diverts others to: %s\n"),
                     namenode->divert->useinstead->name);
            else
              printf(gettext("diverted by %s to: %s\n"),
                     namenode->divert->pkgset->name,
                     namenode->divert->useinstead->name);
          }
          file = file->next;
        }
      }
      break;
    }

    if (*argv != 
                ((void *)0)
                    )
      putchar('\n');
  }

  m_output(
          stdout
                , gettext("<standard output>"));
  if (failures) {
    fputs(gettext("Use dpkg --contents (= dpkg-deb --contents) to list archive files contents.\n"),
             
            stderr
                  );
    m_output(
            stderr
                  , gettext("<standard error>"));
  }

  modstatdb_shutdown();

  return failures;
}

static void
pkg_array_load_db_fsys(struct pkg_array *array, struct pkginfo *pkg, void *pkg_data)
{
  ensure_packagefiles_available(pkg);
}

static void
pkg_array_show_item(struct pkg_array *array, struct pkginfo *pkg, void *pkg_data)
{
  struct pkg_format_node *fmt = pkg_data;

  pkg_format_show(fmt, pkg, &pkg->installed);
}

static int
showpackages(const char *const *argv)
{
  struct dpkg_error err;
  struct pkg_array array;
  struct pkginfo *pkg;
  struct pkg_format_node *fmt;
  
 _Bool 
      fmt_needs_db_fsys;
  int i;
  int rc = 0;

  fmt = pkg_format_parse(showformat, &err);
  if (!fmt) {
    notice(gettext("error in show format: %s"), err.str);
    dpkg_error_destroy(&err);
    rc++;
    return rc;
  }

  fmt_needs_db_fsys = pkg_format_needs_db_fsys(fmt);

  if (!opt_loadavail)
    modstatdb_open(msdbrw_readonly);
  else
    modstatdb_open(msdbrw_readonly | msdbrw_available_readonly);

  pkg_array_init_from_hash(&array);
  pkg_array_sort(&array, pkg_sorter_by_nonambig_name_arch);

  if (!*argv) {
    if (fmt_needs_db_fsys)
      ensure_allinstfiles_available_quiet();
    for (i = 0; i < array.n_pkgs; i++) {
      pkg = array.pkgs[i];
      if (pkg->status == PKG_STAT_NOTINSTALLED)
        continue;
      pkg_format_show(fmt, pkg, &pkg->installed);
    }
  } else {
    if (fmt_needs_db_fsys)
      pkg_array_foreach(&array, pkg_array_load_db_fsys, 
                                                       ((void *)0)
                                                           );
    rc = pkg_array_match_patterns(&array, pkg_array_show_item, fmt, argv);
  }

  m_output(
          stdout
                , gettext("<standard output>"));
  m_output(
          stderr
                , gettext("<standard error>"));

  pkg_array_destroy(&array);
  pkg_format_free(fmt);
  modstatdb_shutdown();

  return rc;
}

static 
      _Bool

pkg_infodb_is_internal(const char *filetype)
{

  if (strcmp(filetype, "list") == 0 ||
      strcmp(filetype, "conffiles") == 0)
    return 
          1
              ;

  if (strlen(filetype) > 100)
    return 
          1
              ;

  return 
        0
             ;
}

static void
pkg_infodb_check_filetype(const char *filetype)
{
  const char *c;


  for (c = "/."; *c; c++)
    if (strchr(filetype, *c))
      badusage(gettext("control file contains %c"), *c);
}

static void
pkg_infodb_print_filename(const char *filename, const char *filetype)
{
  if (pkg_infodb_is_internal(filetype))
    return;

  printf("%s\n", filename);
}

static void
pkg_infodb_print_filetype(const char *filename, const char *filetype)
{
  if (pkg_infodb_is_internal(filetype))
    return;

  printf("%s\n", filetype);
}

static void
control_path_file(struct pkginfo *pkg, const char *control_file)
{
  const char *control_pathname;
  struct stat st;

  control_pathname = pkg_infodb_get_file(pkg, &pkg->installed, control_file);
  if (stat(control_pathname, &st) < 0)
    return;
  if (!
      ((((
      st.st_mode
      )) & 0170000) == (0100000))
                         )
    return;

  pkg_infodb_print_filename(control_pathname, control_file);
}

static int
control_path(const char *const *argv)
{
  struct pkginfo *pkg;
  const char *pkgname;
  const char *control_file;

  pkgname = *argv++;
  if (!pkgname)
    badusage(gettext("--%s needs at least one package name argument"),
             cipaction->olong);

  control_file = *argv++;
  if (control_file && *argv)
    badusage(gettext("--%s takes at most two arguments"), cipaction->olong);

  if (control_file)
    pkg_infodb_check_filetype(control_file);

  modstatdb_open(msdbrw_readonly);

  pkg = dpkg_options_parse_pkgname(cipaction, pkgname);
  if (pkg->status == PKG_STAT_NOTINSTALLED)
    ohshit(gettext("package '%s' is not installed"),
           pkg_name(pkg, pnaw_nonambig));

  if (control_file)
    control_path_file(pkg, control_file);
  else
    pkg_infodb_foreach(pkg, &pkg->installed, pkg_infodb_print_filename);

  modstatdb_shutdown();

  return 0;
}

static int
control_list(const char *const *argv)
{
  struct pkginfo *pkg;
  const char *pkgname;

  pkgname = *argv++;
  if (!pkgname || *argv)
    badusage(gettext("--%s takes one package name argument"), cipaction->olong);

  modstatdb_open(msdbrw_readonly);

  pkg = dpkg_options_parse_pkgname(cipaction, pkgname);
  if (pkg->status == PKG_STAT_NOTINSTALLED)
    ohshit(gettext("package '%s' is not installed"), pkg_name(pkg, pnaw_nonambig));

  pkg_infodb_foreach(pkg, &pkg->installed, pkg_infodb_print_filetype);

  modstatdb_shutdown();

  return 0;
}

static int
control_show(const char *const *argv)
{
  struct pkginfo *pkg;
  const char *pkgname;
  const char *filename;
  const char *control_file;

  pkgname = *argv++;
  if (!pkgname || !*argv)
    badusage(gettext("--%s takes exactly two arguments"),
             cipaction->olong);

  control_file = *argv++;
  if (!control_file || *argv)
    badusage(gettext("--%s takes exactly two arguments"), cipaction->olong);

  pkg_infodb_check_filetype(control_file);

  modstatdb_open(msdbrw_readonly);

  pkg = dpkg_options_parse_pkgname(cipaction, pkgname);
  if (pkg->status == PKG_STAT_NOTINSTALLED)
    ohshit(gettext("package '%s' is not installed"), pkg_name(pkg, pnaw_nonambig));

  if (pkg_infodb_has_file(pkg, &pkg->installed, control_file))
    filename = pkg_infodb_get_file(pkg, &pkg->installed, control_file);
  else
    ohshit(gettext("control file '%s' does not exist"), control_file);

  modstatdb_shutdown();

  file_show(filename);

  return 0;
}

static void
set_no_pager(const struct cmdinfo *ci, const char *value)
{
  pager_enable(
              0
                   );
}

static void __attribute__((noreturn))
printversion(const struct cmdinfo *ci, const char *value)
{
  printf(gettext("Debian %s package management program query tool version %s.\n"),
         "dpkg-query", "1.20.12" " (" "amd64" ")");
  printf(gettext("This is free software; see the GNU General Public License version 2 or\n" "later for copying conditions. There is NO warranty.\n")

                                                        );

  m_output(
          stdout
                , gettext("<standard output>"));

  exit(0);
}

static void __attribute__((noreturn))
usage(const struct cmdinfo *ci, const char *value)
{
  printf(gettext("Usage: %s [<option>...] <command>\n" "\n")

     , "dpkg-query");

  printf(gettext("Commands:\n" "  -s, --status [<package>...]      Display package status details.\n" "  -p, --print-avail [<package>...] Display available version details.\n" "  -L, --listfiles <package>...     List files 'owned' by package(s).\n" "  -l, --list [<pattern>...]        List packages concisely.\n" "  -W, --show [<pattern>...]        Show information on package(s).\n" "  -S, --search <pattern>...        Find package(s) owning file(s).\n" "      --control-list <package>     Print the package control file list.\n" "      --control-show <package> <file>\n" "                                   Show the package control file.\n" "  -c, --control-path <package> [<file>]\n" "                                   Print path for package control file.\n" "\n")
     );

  printf(gettext("  -?, --help                       Show this help message.\n" "      --version                    Show the version.\n" "\n")


     );

  printf(gettext("Options:\n" "  --admindir=<directory>           Use <directory> instead of %s.\n" "  --load-avail                     Use available file on --show and --list.\n" "  --no-pager                       Disables the use of any pager.\n" "  -f|--showformat=<format>         Use alternative format for --show.\n" "\n")





     , "/usr/local/var/lib/dpkg");

  printf(gettext("Format syntax:\n" "  A format is a string that will be output for each package. The format\n" "  can include the standard escape sequences \\n (newline), \\r (carriage\n" "  return) or \\\\ (plain backslash). Package information can be included\n" "  by inserting variable references to package fields using the ${var[;width]}\n" "  syntax. Fields will be right-aligned unless the width is negative in which\n" "  case left alignment will be used.\n")






                                        );

  m_output(
          stdout
                , gettext("<standard output>"));

  exit(0);
}

static const char printforhelp[] = "Use --help for help about querying packages."
                                               ;

static const char *admindir;




static const struct cmdinfo cmdinfos[]= {
  { "listfiles", 'L', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_listfiles, 
 ((void *)0)
 , list_files },
  { "status", 's', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_status, 
 ((void *)0)
 , print_status },
  { "print-avail", 'p', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_printavail, 
 ((void *)0)
 , print_avail },
  { "list", 'l', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_listpackages, 
 ((void *)0)
 , listpackages },
  { "search", 'S', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_searchfiles, 
 ((void *)0)
 , searchfiles },
  { "show", 'W', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_listpackages, 
 ((void *)0)
 , showpackages },
  { "control-path", 'c', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_controlpath, 
 ((void *)0)
 , control_path },
  { "control-list", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_controllist, 
 ((void *)0)
 , control_list },
  { "control-show", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_controlshow, 
 ((void *)0)
 , control_show },

  { "admindir", 0, 1, 
                         ((void *)0)
                             , &admindir, 
                                            ((void *)0) 
                                                          },
  { "load-avail", 0, 0, &opt_loadavail, 
                                         ((void *)0)
                                             , 
                                               ((void *)0)
                                                   , 1 },
  { "showformat", 'f', 1, 
                         ((void *)0)
                             , &showformat, 
                                            ((void *)0) 
                                                          },
  { "no-pager", 0, 0, 
                         ((void *)0)
                             , 
                               ((void *)0)
                                   , set_no_pager },
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
        , 0, 0, 
                         ((void *)0)
                             , 
                               ((void *)0)
                                   , 
                                            ((void *)0) 
                                                          }
};

int main(int argc, const char *const *argv) {
  int ret;

  dpkg_set_report_piped_mode(
                            0
                                  );
  dpkg_locales_init("dpkg");
  dpkg_program_init("dpkg-query");
  dpkg_options_parse(&argv, cmdinfos, printforhelp);

  admindir = dpkg_db_set_dir(admindir);

  if (!cipaction) badusage(gettext("need an action option"));

  ret = cipaction->action(argv);

  dpkg_program_done();
  dpkg_locales_done();

  return !!ret;
}
