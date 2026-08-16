



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












struct pkg_list {
 struct pkg_list *next;
 struct pkginfo *pkg;
};

struct pkg_list *pkg_list_new(struct pkginfo *pkg, struct pkg_list *next);
void pkg_list_free(struct pkg_list *head);
void pkg_list_prepend(struct pkg_list **head, struct pkginfo *pkg);












struct pkg_queue {
 struct pkg_list *head, *tail;
 int length;
};
void pkg_queue_init(struct pkg_queue *queue);
void pkg_queue_destroy(struct pkg_queue *queue);

int pkg_queue_is_empty(struct pkg_queue *queue);

struct pkg_list *pkg_queue_push(struct pkg_queue *queue, struct pkginfo *pkg);
struct pkginfo *pkg_queue_pop(struct pkg_queue *queue);













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

static struct pkginfo *progress_bytrigproc;
static struct pkg_queue queue = { .head = 
                               ((void *)0)
                               , .tail = 
                               ((void *)0)
                               , .length = 0 };

enum dependtry dependtry = DEPEND_TRY_NORMAL;
int sincenothing = 0;

void
enqueue_package(struct pkginfo *pkg)
{
  ensure_package_clientdata(pkg);
  if (pkg->clientdata->enqueued)
    return;
  pkg->clientdata->enqueued = 
                             1
                                 ;
  pkg_queue_push(&queue, pkg);
}

void
enqueue_package_mark_seen(struct pkginfo *pkg)
{
  enqueue_package(pkg);
  pkg->clientdata->cmdline_seen++;
}

static void
enqueue_pending(void)
{
  struct pkg_hash_iter *iter;
  struct pkginfo *pkg;

  iter = pkg_hash_iter_new();
  while ((pkg = pkg_hash_iter_next_pkg(iter)) != 
                                                ((void *)0)
                                                    ) {
    switch (cipaction->arg_int) {
    case act_configure:
      if (!(pkg->status == PKG_STAT_UNPACKED ||
            pkg->status == PKG_STAT_HALFCONFIGURED ||
            pkg->trigpend_head))
        continue;
      if (pkg->want != PKG_WANT_INSTALL &&
          pkg->want != PKG_WANT_HOLD)
        continue;
      break;
    case act_triggers:
      if (!pkg->trigpend_head)
        continue;
      if (pkg->want != PKG_WANT_INSTALL &&
          pkg->want != PKG_WANT_HOLD)
        continue;
      break;
    case act_remove:
    case act_purge:
      if (pkg->want != PKG_WANT_PURGE) {
        if (pkg->want != PKG_WANT_DEINSTALL)
          continue;
        if (pkg->status == PKG_STAT_CONFIGFILES)
          continue;
      }
      if (pkg->status == PKG_STAT_NOTINSTALLED)
        continue;
      break;
    default:
      do_internerr("packages.c", 109, __func__, "unknown action '%d'", cipaction->arg_int);
    }
    enqueue_package(pkg);
  }
  pkg_hash_iter_free(iter);
}

static void
enqueue_specified(const char *const *argv)
{
  const char *thisarg;

  while ((thisarg = *argv++) != 
                               ((void *)0)
                                   ) {
    struct pkginfo *pkg;

    pkg = dpkg_options_parse_pkgname(cipaction, thisarg);
    if (pkg->status == PKG_STAT_NOTINSTALLED &&
        str_match_end(pkg->set->name, ".deb")) {
      badusage(gettext("you must specify packages by their own names, " "not by quoting the names of the files they come in")
                                                                      );
    }
    enqueue_package_mark_seen(pkg);
  }

  if (cipaction->arg_int == act_configure)
    trigproc_populate_deferred();
}

int
packages(const char *const *argv)
{
  trigproc_install_hooks();

  modstatdb_open(f_noact ? msdbrw_readonly :
                 in_force(FORCE_NON_ROOT) ? msdbrw_write :
                                            msdbrw_needsuperuser);
  checkpath();
  pkg_infodb_upgrade();

  log_message("startup packages %s", cipaction->olong);

  if (f_pending) {
    if (*argv)
      badusage(gettext("--%s --pending does not take any non-option arguments"),cipaction->olong);

    enqueue_pending();
  } else {
    if (!*argv)
      badusage(gettext("--%s needs at least one package name argument"), cipaction->olong);

    enqueue_specified(argv);
  }

  ensure_diversions();

  process_queue();
  trigproc_run_deferred();

  modstatdb_shutdown();

  return 0;
}

void process_queue(void) {
  struct pkg_list *rundown;
  struct pkginfo *volatile pkg;
  volatile enum action action_todo;
  jmp_buf ejbuf;
  enum pkg_istobe istobe = PKG_ISTOBE_NORMAL;

  if (abort_processing)
    return;

  clear_istobes();

  switch (cipaction->arg_int) {
  case act_triggers:
  case act_configure:
  case act_install:
    istobe = PKG_ISTOBE_INSTALLNEW;
    break;
  case act_remove:
  case act_purge:
    istobe = PKG_ISTOBE_REMOVE;
    break;
  default:
    do_internerr("packages.c", 195, __func__, "unknown action '%d'", cipaction->arg_int);
  }
  for (rundown = queue.head; rundown; rundown = rundown->next) {
    ensure_package_clientdata(rundown->pkg);



    if (rundown->pkg->clientdata->cmdline_seen > 1) {
      switch (cipaction->arg_int) {
      case act_triggers:
      case act_configure: case act_remove: case act_purge:
        printf(gettext("Package %s listed more than once, only processing once.\n"),
               pkg_name(rundown->pkg, pnaw_nonambig));
        break;
      case act_install:
        printf(gettext("More than one copy of package %s has been unpacked\n" " in this run !  Only configuring it once.\n")
                                                             ,
               pkg_name(rundown->pkg, pnaw_nonambig));
        break;
      default:
        do_internerr("packages.c", 215, __func__, "unknown action '%d'", cipaction->arg_int);
      }
    }
    rundown->pkg->clientdata->istobe = istobe;
  }

  while (!pkg_queue_is_empty(&queue)) {
    pkg = pkg_queue_pop(&queue);
    if (!pkg)
      continue;

    ensure_package_clientdata(pkg);
    pkg->clientdata->enqueued = 
                               0
                                    ;

    action_todo = cipaction->arg_int;

    if (sincenothing++ > queue.length * 3 + 2) {



      dependtry++;
      sincenothing = 0;
      if (dependtry >= DEPEND_TRY_LAST)
        do_internerr("packages.c", 238, __func__, "exceeded dependtry %d (sincenothing=%d; queue.length=%d)", dependtry, sincenothing, queue.length)
                                                        ;
    } else if (sincenothing > queue.length * 2 + 2) {
      if (dependtry >= DEPEND_TRY_TRIGGERS &&
          progress_bytrigproc && progress_bytrigproc->trigpend_head) {
        enqueue_package(pkg);
        pkg = progress_bytrigproc;
        progress_bytrigproc = 
                             ((void *)0)
                                 ;
        action_todo = act_configure;
      } else {
        dependtry++;
        sincenothing = 0;
        if (dependtry >= DEPEND_TRY_LAST)
          do_internerr("packages.c", 251, __func__, "exceeded dependtry %d (sincenothing=%d, queue.length=%d)", dependtry, sincenothing, queue.length)
                                                          ;
      }
    }

    debug(dbg_general, "process queue pkg %s queue.len %d progress %d, try %d",
          pkg_name(pkg, pnaw_always), queue.length, sincenothing, dependtry);

    if (pkg->status > PKG_STAT_INSTALLED)
      do_internerr("packages.c", 260, __func__, "package %s status %d is out-of-bounds", pkg_name(pkg, pnaw_always), pkg->status)
                                                        ;

    if (
       _setjmp (
       ejbuf
       )
                    ) {


      pkg->clientdata->istobe = PKG_ISTOBE_NORMAL;

      pop_error_context(ehflag_bombout);
      if (abort_processing)
        return;
      continue;
    }
    push_error_context_jump(&ejbuf, print_error_perpackage,
                            pkg_name(pkg, pnaw_nonambig));

    switch (action_todo) {
    case act_triggers:
      if (!pkg->trigpend_head)
        ohshit(gettext("package %.250s is not ready for trigger processing\n" " (current status '%.250s' with no pending triggers)")
                                                                       ,
               pkg_name(pkg, pnaw_nonambig), pkg_status_name(pkg));

    case act_install:

      if (pkg->status == PKG_STAT_NOTINSTALLED)
        break;

    case act_configure:

      if (pkg->trigpend_head)
        trigproc(pkg, TRIGPROC_TRY_QUEUED);
      else
        deferred_configure(pkg);
      break;
    case act_remove: case act_purge:
      deferred_remove(pkg);
      break;
    default:
      do_internerr("packages.c", 299, __func__, "unknown action '%d'", cipaction->arg_int);
    }
    m_output(
            stdout
                  , gettext("<standard output>"));
    m_output(
            stderr
                  , gettext("<standard error>"));

    pop_error_context(ehflag_normaltidy);
  }

  if (queue.length)
    do_internerr("packages.c", 308, __func__, "finished package processing with non-empty queue length %d", queue.length)
                           ;
}
enum found_status {
  FOUND_NONE = 0,
  FOUND_DEFER = 1,
  FOUND_FORCED = 2,
  FOUND_OK = 3,
};

static enum found_status
found_forced_on(enum dependtry dependtry_forced)
{
  if (dependtry >= dependtry_forced)
    return FOUND_FORCED;
  else
    return FOUND_DEFER;
}
static enum found_status
deppossi_ok_found(struct pkginfo *possdependee, struct pkginfo *requiredby,
                  struct pkginfo *removing, struct deppossi *provider,
                  struct pkginfo **fixbytrig,
                  
                 _Bool 
                      *matched, struct deppossi *checkversion,
                  int *interestingwarnings, struct varbuf *oemsgs)
{
  enum found_status thisf;

  if (ignore_depends(possdependee)) {
    debug(dbg_depcondetail,"      ignoring depended package so ok and found");
    return FOUND_OK;
  }
  thisf = FOUND_NONE;
  if (possdependee == removing) {
    if (provider) {
      varbuf_printf(oemsgs,
                    gettext("  Package %s which provides %s is to be removed.\n"),
                    pkg_name(possdependee, pnaw_nonambig),
                    provider->ed->name);
    } else {
      varbuf_printf(oemsgs, gettext("  Package %s is to be removed.\n"),
                    pkg_name(possdependee, pnaw_nonambig));
    }

    *matched = 
              1
                  ;
    debug(dbg_depcondetail,"      removing possdependee, returning %d",thisf);
    return thisf;
  }
  switch (possdependee->status) {
  case PKG_STAT_UNPACKED:
  case PKG_STAT_HALFCONFIGURED:
  case PKG_STAT_TRIGGERSAWAITED:
  case PKG_STAT_TRIGGERSPENDING:
  case PKG_STAT_INSTALLED:
    if (checkversion) {
      if (provider) {
        debug(dbg_depcondetail, "      checking package %s provided by pkg %s",
              checkversion->ed->name, pkg_name(possdependee, pnaw_always));
        if (!pkg_virtual_deppossi_satisfied(checkversion, provider)) {
          varbuf_printf(oemsgs,
                        gettext("  Version of %s on system, provided by %s, is %s.\n"),
                        checkversion->ed->name,
                        pkg_name(possdependee, pnaw_always),
                        versiondescribe(&provider->version, vdew_nonambig));
          if (in_force(FORCE_DEPENDS_VERSION))
            thisf = found_forced_on(DEPEND_TRY_FORCE_DEPENDS_VERSION);
          debug(dbg_depcondetail, "      bad version");
          goto unsuitable;
        }
      } else {
        debug(dbg_depcondetail, "      checking non-provided pkg %s",
              pkg_name(possdependee, pnaw_always));
        if (!versionsatisfied(&possdependee->installed, checkversion)) {
          varbuf_printf(oemsgs, gettext("  Version of %s on system is %s.\n"),
                        pkg_name(possdependee, pnaw_nonambig),
                        versiondescribe(&possdependee->installed.version,
                                        vdew_nonambig));
          if (in_force(FORCE_DEPENDS_VERSION))
            thisf = found_forced_on(DEPEND_TRY_FORCE_DEPENDS_VERSION);
          debug(dbg_depcondetail, "      bad version");
          goto unsuitable;
        }
      }
    }
    if (possdependee->status == PKG_STAT_INSTALLED ||
        possdependee->status == PKG_STAT_TRIGGERSPENDING) {
      debug(dbg_depcondetail,"      is installed, ok and found");
      return FOUND_OK;
    }
    if (possdependee->status == PKG_STAT_TRIGGERSAWAITED) {
      if (possdependee->trigaw.head == 
                                      ((void *)0)
                                          )
        do_internerr("packages.c", 448, __func__, "package %s in state %s, has no awaited triggers", pkg_name(possdependee, pnaw_always), pkg_status_name(possdependee))

                                                ;

      if (removing ||
          !(f_triggers ||
            (possdependee->clientdata &&
             possdependee->clientdata->istobe == PKG_ISTOBE_INSTALLNEW))) {
        if (provider) {
          varbuf_printf(oemsgs,
                        gettext("  Package %s which provides %s awaits trigger processing.\n"),
                        pkg_name(possdependee, pnaw_nonambig),
                        provider->ed->name);
        } else {
          varbuf_printf(oemsgs,
                        gettext("  Package %s awaits trigger processing.\n"),
                        pkg_name(possdependee, pnaw_nonambig));
        }
        debug(dbg_depcondetail, "      triggers-awaited, no fixbytrig");
        goto unsuitable;
      }
      *fixbytrig = possdependee->trigaw.head->pend;
      debug(dbg_depcondetail,
            "      triggers-awaited, fixbytrig '%s', defer",
            pkg_name(*fixbytrig, pnaw_always));
      return FOUND_DEFER;
    }
    if (possdependee->clientdata &&
        possdependee->clientdata->istobe == PKG_ISTOBE_INSTALLNEW) {
      debug(dbg_depcondetail,"      unpacked/halfconfigured, defer");
      return FOUND_DEFER;
    } else if (!removing && in_force(FORCE_CONFIGURE_ANY) &&
               !skip_due_to_hold(possdependee) &&
               !(possdependee->status == PKG_STAT_HALFCONFIGURED)) {
      notice(gettext("also configuring '%s' (required by '%s')"),
             pkg_name(possdependee, pnaw_nonambig),
             pkg_name(requiredby, pnaw_nonambig));
      enqueue_package(possdependee);
      sincenothing = 0;
      return FOUND_DEFER;
    } else {
      if (provider) {
        varbuf_printf(oemsgs,
                      gettext("  Package %s which provides %s is not configured yet.\n"),
                      pkg_name(possdependee, pnaw_nonambig),
                      provider->ed->name);
      } else {
        varbuf_printf(oemsgs, gettext("  Package %s is not configured yet.\n"),
                      pkg_name(possdependee, pnaw_nonambig));
      }

      debug(dbg_depcondetail, "      not configured/able");
      goto unsuitable;
    }

  default:
    if (provider) {
      varbuf_printf(oemsgs,
                    gettext("  Package %s which provides %s is not installed.\n"),
                    pkg_name(possdependee, pnaw_nonambig),
                    provider->ed->name);
    } else {
      varbuf_printf(oemsgs, gettext("  Package %s is not installed.\n"),
                    pkg_name(possdependee, pnaw_nonambig));
    }

    debug(dbg_depcondetail, "      not installed");
    goto unsuitable;
  }

unsuitable:
  debug(dbg_depcondetail, "        returning %d", thisf);
  (*interestingwarnings)++;

  return thisf;
}

static void
breaks_check_one(struct varbuf *aemsgs, enum dep_check *ok,
                 struct deppossi *breaks, struct pkginfo *broken,
                 struct pkginfo *breaker, struct deppossi *virtbroken)
{
  struct varbuf depmsg = { 0, 0, 
                        ((void *)0) 
                        };

  debug(dbg_depcondetail, "      checking breaker %s virtbroken %s",
        pkg_name(breaker, pnaw_always),
        virtbroken ? virtbroken->ed->name : "<none>");

  if (breaker->status == PKG_STAT_NOTINSTALLED ||
      breaker->status == PKG_STAT_CONFIGFILES)
    return;
  if (broken == breaker) return;
  if (!versionsatisfied(&broken->installed, breaks)) return;


  if (!archsatisfied(&broken->installed, breaks))
    return;
  if (ignore_depends(breaker)) return;
  if (virtbroken && ignore_depends(&virtbroken->ed->pkg))
    return;
  if (virtbroken && !pkg_virtual_deppossi_satisfied(breaks, virtbroken))
    return;

  varbufdependency(&depmsg, breaks->up);
  varbuf_end_str(&depmsg);
  varbuf_printf(aemsgs, gettext(" %s (%s) breaks %s and is %s.\n"),
                pkg_name(breaker, pnaw_nonambig),
                versiondescribe(&breaker->installed.version, vdew_nonambig),
                depmsg.buf, gettext(statusstrings[breaker->status]));
  varbuf_destroy(&depmsg);

  if (virtbroken) {
    varbuf_printf(aemsgs, gettext("  %s (%s) provides %s.\n"),
                  pkg_name(broken, pnaw_nonambig),
                  versiondescribe(&broken->installed.version, vdew_nonambig),
                  virtbroken->ed->name);
  } else if (breaks->verrel != DPKG_RELATION_NONE) {
    varbuf_printf(aemsgs, gettext("  Version of %s to be configured is %s.\n"),
                  pkg_name(broken, pnaw_nonambig),
                  versiondescribe(&broken->installed.version, vdew_nonambig));
    if (in_force(FORCE_DEPENDS_VERSION))
      return;
  }
  if (force_breaks(breaks)) return;
  *ok = DEP_CHECK_HALT;
}

static void
breaks_check_target(struct varbuf *aemsgs, enum dep_check *ok,
                    struct pkginfo *broken, struct pkgset *target,
                    struct deppossi *virtbroken)
{
  struct deppossi *possi;

  for (possi = target->depended.installed; possi; possi = possi->rev_next) {
    if (possi->up->type != dep_breaks) continue;
    breaks_check_one(aemsgs, ok, possi, broken, possi->up->up, virtbroken);
  }
}

enum dep_check
breakses_ok(struct pkginfo *pkg, struct varbuf *aemsgs)
{
  struct dependency *dep;
  struct deppossi *virtbroken;
  enum dep_check ok = DEP_CHECK_OK;

  debug(dbg_depcon, "    checking Breaks");

  breaks_check_target(aemsgs, &ok, pkg, pkg->set, 
                                                 ((void *)0)
                                                     );

  for (dep= pkg->installed.depends; dep; dep= dep->next) {
    if (dep->type != dep_provides) continue;
    virtbroken = dep->list;
    debug(dbg_depcondetail, "     checking virtbroken %s", virtbroken->ed->name);
    breaks_check_target(aemsgs, &ok, pkg, virtbroken->ed, virtbroken);
  }
  return ok;
}




enum dep_check
dependencies_ok(struct pkginfo *pkg, struct pkginfo *removing,
                struct varbuf *aemsgs)
{

  enum dep_check ok;

  enum found_status found, thisf;
  int interestingwarnings;
  
 _Bool 
      matched, anycannotfixbytrig;
  struct varbuf oemsgs = { 0, 0, 
                        ((void *)0) 
                        };
  struct dependency *dep;
  struct deppossi *possi, *provider;
  struct pkginfo *possfixbytrig, *canfixbytrig;

  ok = DEP_CHECK_OK;
  debug(dbg_depcon,"checking dependencies of %s (- %s)",
        pkg_name(pkg, pnaw_always),
        removing ? pkg_name(removing, pnaw_always) : "<none>");

  anycannotfixbytrig = 
                      0
                           ;
  canfixbytrig = 
                ((void *)0)
                    ;
  for (dep= pkg->installed.depends; dep; dep= dep->next) {
    if (dep->type != dep_depends && dep->type != dep_predepends) continue;
    debug(dbg_depcondetail,"  checking group ...");
    matched = 
             0
                  ;
    interestingwarnings = 0;
    varbuf_reset(&oemsgs);
    found = FOUND_NONE;
    possfixbytrig = 
                   ((void *)0)
                       ;
    for (possi = dep->list; found != FOUND_OK && possi; possi = possi->next) {
      struct deppossi_pkg_iterator *possi_iter;
      struct pkginfo *pkg_pos;

      debug(dbg_depcondetail,"    checking possibility  -> %s",possi->ed->name);
      if (possi->cyclebreak) {
        debug(dbg_depcondetail,"      break cycle so ok and found");
        found = FOUND_OK;
        break;
      }

      thisf = FOUND_NONE;
      possi_iter = deppossi_pkg_iter_new(possi, wpb_installed);
      while ((pkg_pos = deppossi_pkg_iter_next(possi_iter))) {
        thisf = deppossi_ok_found(pkg_pos, pkg, removing, 
                                                         ((void *)0)
                                                             ,
                                  &possfixbytrig, &matched, possi,
                                  &interestingwarnings, &oemsgs);
        if (thisf > found)
          found = thisf;
        if (found == FOUND_OK)
          break;
      }
      deppossi_pkg_iter_free(possi_iter);

      if (found != FOUND_OK) {
        for (provider = possi->ed->depended.installed;
             found != FOUND_OK && provider;
             provider = provider->rev_next) {
          if (provider->up->type != dep_provides)
            continue;
          debug(dbg_depcondetail, "     checking provider %s",
                pkg_name(provider->up->up, pnaw_always));
          if (!deparchsatisfied(&provider->up->up->installed, provider->arch,
                                possi)) {
            debug(dbg_depcondetail, "       provider does not satisfy arch");
            continue;
          }
          thisf = deppossi_ok_found(provider->up->up, pkg, removing, provider,
                                    &possfixbytrig, &matched, possi,
                                    &interestingwarnings, &oemsgs);
          if (thisf == FOUND_DEFER && provider->up->up == pkg && !removing) {



             thisf = FOUND_OK;
          }
          if (thisf > found)
            found = thisf;
        }
      }
      debug(dbg_depcondetail,"    found %d",found);
      if (thisf > found) found= thisf;
    }
    if (in_force(FORCE_DEPENDS)) {
      thisf = found_forced_on(DEPEND_TRY_FORCE_DEPENDS);
      if (thisf > found) {
        found = thisf;
        debug(dbg_depcondetail, "  rescued by force-depends, found %d", found);
      }
    }
    debug(dbg_depcondetail, "  found %d matched %d possfixbytrig %s",
          found, matched,
          possfixbytrig ? pkg_name(possfixbytrig, pnaw_always) : "-");
    if (removing && !matched) continue;
    switch (found) {
    case FOUND_NONE:
      anycannotfixbytrig = 
                          1
                              ;
      ok = DEP_CHECK_HALT;

    case FOUND_FORCED:
      varbuf_add_buf(aemsgs, " ", strlen(" "));
      varbuf_add_pkgbin_name(aemsgs, pkg, &pkg->installed, pnaw_nonambig);
      varbuf_add_buf(aemsgs, gettext(" depends on "), strlen(gettext(" depends on ")));
      varbufdependency(aemsgs, dep);
      if (interestingwarnings) {


        varbuf_end_str(&oemsgs);
        varbuf_add_buf(aemsgs, gettext("; however:\n"), strlen(gettext("; however:\n")));
        varbuf_add_buf(aemsgs, oemsgs.buf, strlen(oemsgs.buf));
      } else {
        varbuf_add_buf(aemsgs, ".\n", strlen(".\n"));
      }
      break;
    case FOUND_DEFER:
      if (possfixbytrig)
        canfixbytrig = possfixbytrig;
      else
        anycannotfixbytrig = 
                            1
                                ;
      if (ok > DEP_CHECK_DEFER)
        ok = DEP_CHECK_DEFER;
      break;
    case FOUND_OK:
      break;
    default:
      do_internerr("packages.c", 746, __func__, "unknown value for found '%d'", found);
    }
  }
  if (ok == DEP_CHECK_HALT &&
      (pkg->clientdata && pkg->clientdata->istobe == PKG_ISTOBE_REMOVE))
    ok = DEP_CHECK_DEFER;
  if (!anycannotfixbytrig && canfixbytrig)
    progress_bytrigproc = canfixbytrig;

  varbuf_destroy(&oemsgs);
  debug(dbg_depcon,"ok %d msgs >>%.*s<<", ok, (int)aemsgs->used, aemsgs->buf);
  return ok;
}
