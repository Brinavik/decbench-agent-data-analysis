





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








enum c_ctype_bit {
 C_CTYPE_BLANK = (1 << (0)),
 C_CTYPE_WHITE = (1 << (1)),
 C_CTYPE_SPACE = (1 << (2)),
 C_CTYPE_UPPER = (1 << (3)),
 C_CTYPE_LOWER = (1 << (4)),
 C_CTYPE_DIGIT = (1 << (5)),

 C_CTYPE_ALPHA = C_CTYPE_UPPER | C_CTYPE_LOWER,
 C_CTYPE_ALNUM = C_CTYPE_ALPHA | C_CTYPE_DIGIT,
};


_Bool

c_isbits(int c, enum c_ctype_bit bits);




static inline 
             _Bool

c_isblank(int c)
{
 return c_isbits(c, C_CTYPE_BLANK);
}




static inline 
             _Bool

c_iswhite(int c)
{
 return c_isbits(c, C_CTYPE_WHITE);
}




static inline 
             _Bool

c_isspace(int c)
{
 return c_isbits(c, C_CTYPE_SPACE);
}




static inline 
             _Bool

c_isdigit(int c)
{
 return c_isbits(c, C_CTYPE_DIGIT);
}




static inline 
             _Bool

c_isupper(int c)
{
 return c_isbits(c, C_CTYPE_UPPER);
}




static inline 
             _Bool

c_islower(int c)
{
 return c_isbits(c, C_CTYPE_LOWER);
}




static inline 
             _Bool

c_isalpha(int c)
{
 return c_isbits(c, C_CTYPE_ALPHA);
}




static inline 
             _Bool

c_isalnum(int c)
{
 return c_isbits(c, C_CTYPE_ALNUM);
}




static inline int
c_tolower(int c)
{
 return (c_isupper(c) ?
         ((unsigned char)(c) & ~0x20) | 0x20 : c);
}
















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



void filter_add(const char *glob, 
                                 _Bool 
                                      include);

_Bool 
    filter_should_skip(struct tar_entry *ti);



static void __attribute__((noreturn))
printversion(const struct cmdinfo *ci, const char *value)
{
  if (f_robot) {
    printf("%s", "1.20.12");
  } else {
    printf(gettext("Debian '%s' package management program version %s.\n"),
           "dpkg", "1.20.12" " (" "amd64" ")");
    printf(gettext("This is free software; see the GNU General Public License version 2 or\n" "later for copying conditions. There is NO warranty.\n")

                                                        );
  }

  m_output(
          stdout
                , gettext("<standard output>"));

  exit(0);
}






static void __attribute__((noreturn))
usage(const struct cmdinfo *ci, const char *value)
{
  printf(gettext("Usage: %s [<option>...] <command>\n" "\n")

     , "dpkg");

  printf(gettext("Commands:\n" "  -i|--install       <.deb file name>... | -R|--recursive <directory>...\n" "  --unpack           <.deb file name>... | -R|--recursive <directory>...\n" "  -A|--record-avail  <.deb file name>... | -R|--recursive <directory>...\n" "  --configure        <package>... | -a|--pending\n" "  --triggers-only    <package>... | -a|--pending\n" "  -r|--remove        <package>... | -a|--pending\n" "  -P|--purge         <package>... | -a|--pending\n" "  -V|--verify [<package>...]       Verify the integrity of package(s).\n" "  --get-selections [<pattern>...]  Get list of selections to stdout.\n" "  --set-selections                 Set package selections from stdin.\n" "  --clear-selections               Deselect every non-essential package.\n" "  --update-avail [<Packages-file>] Replace available packages info.\n" "  --merge-avail [<Packages-file>]  Merge with info from file.\n" "  --clear-avail                    Erase existing available info.\n" "  --forget-old-unavail             Forget uninstalled unavailable pkgs.\n" "  -s|--status [<package>...]       Display package status details.\n" "  -p|--print-avail [<package>...]  Display available version details.\n" "  -L|--listfiles <package>...      List files 'owned' by package(s).\n" "  -l|--list [<pattern>...]         List packages concisely.\n" "  -S|--search <pattern>...         Find package(s) owning file(s).\n" "  -C|--audit [<package>...]        Check for broken package(s).\n" "  --yet-to-unpack                  Print packages selected for installation.\n" "  --predep-package                 Print pre-dependencies to unpack.\n" "  --add-architecture <arch>        Add <arch> to the list of architectures.\n" "  --remove-architecture <arch>     Remove <arch> from the list of architectures.\n" "  --print-architecture             Print dpkg architecture.\n" "  --print-foreign-architectures    Print allowed foreign architectures.\n" "  --assert-<feature>               Assert support for the specified feature.\n" "  --validate-<thing> <string>      Validate a <thing>'s <string>.\n" "  --compare-versions <a> <op> <b>  Compare version numbers - see below.\n" "  --force-help                     Show help on forcing.\n" "  -Dh|--debug=help                 Show help on debugging.\n" "\n")
     );

  printf(gettext("  -?, --help                       Show this help message.\n" "      --version                    Show the version.\n" "\n")


     );

  printf(gettext("Assertable features: support-predepends, working-epoch, long-filenames,\n" "  multi-conrep, multi-arch, versioned-provides, protected-field.\n" "\n")


     );

  printf(gettext("Validatable things: pkgname, archname, trigname, version.\n" "\n")

     );

  printf(gettext("Use dpkg with -b, --build, -c, --contents, -e, --control, -I, --info,\n" "  -f, --field, -x, --extract, -X, --vextract, --ctrl-tarfile, --fsys-tarfile\n" "on archives (type %s --help).\n" "\n")



     , "dpkg-deb");

  printf(gettext("Options:\n" "  --admindir=<directory>     Use <directory> instead of %s.\n" "  --root=<directory>         Install on a different root directory.\n" "  --instdir=<directory>      Change installation dir without changing admin dir.\n" "  --pre-invoke=<command>     Set a pre-invoke hook.\n" "  --post-invoke=<command>    Set a post-invoke hook.\n" "  --path-exclude=<pattern>   Do not install paths which match a shell pattern.\n" "  --path-include=<pattern>   Re-include a pattern after a previous exclusion.\n" "  -O|--selected-only         Skip packages not selected for install/upgrade.\n" "  -E|--skip-same-version     Skip packages whose same version is installed.\n" "  -G|--refuse-downgrade      Skip packages with earlier version than installed.\n" "  -B|--auto-deconfigure      Install even if it would break some other package.\n" "  --[no-]triggers            Skip or force consequential trigger processing.\n" "  --verify-format=<format>   Verify output format (supported: 'rpm').\n" "  --no-pager                 Disables the use of any pager.\n" "  --no-debsig                Do not try to verify package signatures.\n" "  --no-act|--dry-run|--simulate\n" "                             Just say what we would do - don't do it.\n" "  -D|--debug=<octal>         Enable debugging (see -Dhelp or --debug=help).\n" "  --status-fd <n>            Send status change updates to file descriptor <n>.\n" "  --status-logger=<command>  Send status change updates to <command>'s stdin.\n" "  --log=<filename>           Log status changes and actions to <filename>.\n" "  --ignore-depends=<package>[,...]\n" "                             Ignore dependencies involving <package>.\n" "  --force-<thing>[,...]      Override problems (see --force-help).\n" "  --no-force-<thing>[,...]   Stop when problems encountered.\n" "  --refuse-<thing>[,...]     Ditto.\n" "  --abort-after <n>          Abort after encountering <n> errors.\n" "  --robot                    Use machine-readable output on some commands.\n" "\n")
     , "/usr/local/var/lib/dpkg");

  printf(gettext("Comparison operators for --compare-versions are:\n" "  lt le eq ne ge gt       (treat empty version as earlier than any version);\n" "  lt-nl le-nl ge-nl gt-nl (treat empty version as later than any version);\n" "  < << <= = >= >> >       (only for compatibility with control file syntax).\n" "\n")




     );

  printf(gettext("Use 'apt' or 'aptitude' for user-friendly package management.\n")
                                                                  );

  m_output(
          stdout
                , gettext("<standard output>"));

  exit(0);
}

static const char printforhelp[] = "Type dpkg --help for help about installing and deinstalling packages [*];\n" "Use 'apt' or 'aptitude' for user-friendly package management;\n" "Type dpkg -Dhelp for a list of dpkg debug flag values;\n" "Type dpkg --force-help for a list of forcing options;\n" "Type dpkg-deb --help for help about manipulating *.deb files;\n" "\n" "Options marked [*] produce a lot of output - pipe it through 'less' or 'more' !"






                                                                                  ;

int f_robot = 0;
int f_pending=0, f_recursive=0, f_alsoselect=1, f_skipsame=0, f_noact=0;
int f_autodeconf=0, f_nodebsig=0;
int f_triggers = 0;

int errabort = 50;
static const char *admindir;
const char *instdir= "";
struct pkg_list *ignoredependss = 
                                 ((void *)0)
                                     ;




static const struct debuginfo {
  int flag;
  const char *name;
  const char *desc;
} debuginfos[] = {
  { .flag = dbg_general, .name = "general", .desc = "Generally helpful progress information" },
  { .flag = dbg_scripts, .name = "scripts", .desc = "Invocation and status of maintainer scripts" },
  { .flag = dbg_eachfile, .name = "eachfile", .desc = "Output for each file processed" },
  { .flag = dbg_eachfiledetail, .name = "eachfiledetail", .desc = "Lots of output for each file processed" },
  { .flag = dbg_conff, .name = "conff", .desc = "Output for each configuration file" },
  { .flag = dbg_conffdetail, .name = "conffdetail", .desc = "Lots of output for each configuration file" },
  { .flag = dbg_depcon, .name = "depcon", .desc = "Dependencies and conflicts" },
  { .flag = dbg_depcondetail, .name = "depcondetail", .desc = "Lots of dependencies/conflicts output" },
  { .flag = dbg_triggers, .name = "triggers", .desc = "Trigger activation and processing" },
  { .flag = dbg_triggersdetail, .name = "triggersdetail", .desc = "Lots of output regarding triggers" },
  { .flag = dbg_triggersstupid, .name = "triggersstupid", .desc = "Silly amounts of output regarding triggers" },
  { .flag = dbg_veryverbose, .name = "veryverbose", .desc = "Lots of drivel about eg the dpkg/info directory" },
  { .flag = dbg_stupidlyverbose, .name = "stupidlyverbose", .desc = "Insane amounts of drivel" },
  { 0, 
      ((void *)0)
          , 
            ((void *)0) 
                 }
};

static void
set_debug(const struct cmdinfo *cpi, const char *value)
{
  char *endp;
  long mask;
  const struct debuginfo *dip;

  if (*value == 'h') {
    printf(gettext("%s debugging option, --debug=<octal> or -D<octal>:\n" "\n" " Number  Ref. in source   Description\n")


                                          , "dpkg");

    for (dip = debuginfos; dip->name; dip++)
      printf(" %6o  %-16s %s\n", dip->flag, dip->name, gettext(dip->desc));

    printf(gettext("\n" "Debugging options can be mixed using bitwise-or.\n" "Note that the meanings and values are subject to change.\n")

                                                             );
    m_output(
            stdout
                  , gettext("<standard output>"));
    exit(0);
  }

  
 (*__errno_location ()) 
       = 0;
  mask = strtol(value, &endp, 8);
  if (value == endp || *endp || mask < 0 || 
                                           (*__errno_location ()) 
                                                 == 
                                                    34
                                                          )
    badusage(gettext("--%s requires a positive octal argument"), cpi->olong);

  debug_set_mask(mask);
}

static void
set_no_pager(const struct cmdinfo *ci, const char *value)
{
  pager_enable(
              0
                   );


  setenv("DPKG_PAGER", "cat", 1);
}

static void
set_filter(const struct cmdinfo *cip, const char *value)
{
  filter_add(value, cip->arg_int);
}

static void
set_verify_format(const struct cmdinfo *cip, const char *value)
{
  if (!verify_set_output(value))
    badusage(gettext("unknown verify output format '%s'"), value);
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

static void
set_ignore_depends(const struct cmdinfo *cip, const char *value)
{
  char *copy, *p;

  copy= m_malloc(strlen(value)+2);
  strcpy(copy,value);
  copy[strlen(value) + 1] = '\0';
  for (p=copy; *p; p++) {
    if (*p != ',') continue;
    *p++ = '\0';
    if (!*p || *p==',' || p==copy+1)
      badusage(gettext("null package name in --%s comma-separated list '%.250s'"),
               cip->olong, value);
  }
  p= copy;
  while (*p) {
    struct pkginfo *pkg;

    pkg = dpkg_options_parse_pkgname(cip, p);
    pkg_list_prepend(&ignoredependss, pkg);

    p+= strlen(p)+1;
  }

  free(copy);
}

static void
set_integer(const struct cmdinfo *cip, const char *value)
{
  *cip->iassignto = dpkg_options_parse_arg_int(cip, value);
}

static void
set_pipe(const struct cmdinfo *cip, const char *value)
{
  long v;

  v = dpkg_options_parse_arg_int(cip, value);

  statusfd_add(v);
}

static 
      _Bool

is_invoke_action(enum action action)
{
  switch (action) {
  case act_unpack:
  case act_configure:
  case act_install:
  case act_triggers:
  case act_remove:
  case act_purge:
  case act_arch_add:
  case act_arch_remove:
    return 
          1
              ;
  default:
    return 
          0
               ;
  }
}

static struct invoke_list pre_invoke_hooks = {
  .head = 
         ((void *)0)
             ,
  .tail = &pre_invoke_hooks.head,
};
static struct invoke_list post_invoke_hooks = {
  .head = 
         ((void *)0)
             ,
  .tail = &post_invoke_hooks.head,
};
static struct invoke_list status_loggers = {
  .head = 
         ((void *)0)
             ,
  .tail = &status_loggers.head,
};

static void
set_invoke_hook(const struct cmdinfo *cip, const char *value)
{
  struct invoke_list *hook_list = cip->arg_ptr;
  struct invoke_hook *hook_new;

  hook_new = m_malloc(sizeof(*hook_new));
  hook_new->command = m_strdup(value);
  hook_new->next = 
                  ((void *)0)
                      ;


  *hook_list->tail = hook_new;
  hook_list->tail = &hook_new->next;
}

static void
run_invoke_hooks(const char *action, struct invoke_list *hook_list)
{
  struct invoke_hook *hook;

  setenv("DPKG_HOOK_ACTION", action, 1);

  for (hook = hook_list->head; hook; hook = hook->next) {
    int status;



    status = system(hook->command);
    if (status != 0)
      ohshit(gettext("error executing hook '%s', exit code %d"), hook->command,
             status);
  }

  unsetenv("DPKG_HOOK_ACTION");
}

static void
free_invoke_hooks(struct invoke_list *hook_list)
{
  struct invoke_hook *hook, *hook_next;

  for (hook = hook_list->head; hook; hook = hook_next) {
    hook_next = hook->next;
    free(hook->command);
    free(hook);
  }
}

static int
run_logger(struct invoke_hook *hook, const char *name)
{
  pid_t pid;
  int p[2];

  m_pipe(p);

  pid = subproc_fork();
  if (pid == 0) {

    m_dup2(p[0], 0);
    close(1);

    close(p[0]);
    close(p[1]);

    command_shell(hook->command, name);
  }
  close(p[0]);

  return p[1];
}

static void
run_status_loggers(struct invoke_list *hook_list)
{
  struct invoke_hook *hook;

  for (hook = hook_list->head; hook; hook = hook->next) {
    int fd;

    fd = run_logger(hook, gettext("status logger"));
    statusfd_add(fd);
  }
}

static int
arch_add(const char *const *argv)
{
  struct dpkg_arch *arch;
  const char *archname = *argv++;

  if (archname == 
                 ((void *)0) 
                      || *argv)
    badusage(gettext("--%s takes exactly one argument"), cipaction->olong);

  dpkg_arch_load_list();

  arch = dpkg_arch_add(archname);
  switch (arch->type) {
  case DPKG_ARCH_NATIVE:
  case DPKG_ARCH_FOREIGN:
    break;
  case DPKG_ARCH_ILLEGAL:
    ohshit(gettext("architecture '%s' is illegal: %s"), archname,
           dpkg_arch_name_is_illegal(archname));
  default:
    ohshit(gettext("architecture '%s' is reserved and cannot be added"), archname);
  }

  dpkg_arch_save_list();

  return 0;
}

static int
arch_remove(const char *const *argv)
{
  const char *archname = *argv++;
  struct dpkg_arch *arch;
  struct pkg_hash_iter *iter;
  struct pkginfo *pkg;

  if (archname == 
                 ((void *)0) 
                      || *argv)
    badusage(gettext("--%s takes exactly one argument"), cipaction->olong);

  modstatdb_open(msdbrw_readonly);

  arch = dpkg_arch_find(archname);
  if (arch->type != DPKG_ARCH_FOREIGN) {
    warning(gettext("cannot remove non-foreign architecture '%s'"), arch->name);
    return 0;
  }


  iter = pkg_hash_iter_new();
  while ((pkg = pkg_hash_iter_next_pkg(iter))) {
    if (pkg->status < PKG_STAT_HALFINSTALLED)
      continue;
    if (pkg->installed.arch == arch) {
      if (in_force(FORCE_ARCHITECTURE))
        warning(gettext("removing architecture '%s' currently in use by database"),
                arch->name);
      else
        ohshit(gettext("cannot remove architecture '%s' currently in use by the database"),
               arch->name);
      break;
    }
  }
  pkg_hash_iter_free(iter);

  dpkg_arch_unmark(arch);
  dpkg_arch_save_list();

  modstatdb_shutdown();

  return 0;
}

int execbackend(const char *const *argv) __attribute__((noreturn));
int commandfd(const char *const *argv);




static const struct cmdinfo cmdinfos[]= {



  { "install", 'i', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_install, 
 ((void *)0)
 , archivefiles },
  { "unpack", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_unpack, 
 ((void *)0)
 , archivefiles },
  { "record-avail", 'A', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_avail, 
 ((void *)0)
 , archivefiles },
  { "configure", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_configure, 
 ((void *)0)
 , packages },
  { "remove", 'r', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_remove, 
 ((void *)0)
 , packages },
  { "purge", 'P', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_purge, 
 ((void *)0)
 , packages },
  { "triggers-only", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_triggers, 
 ((void *)0)
 , packages },
  { "verify", 'V', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_verify, 
 ((void *)0)
 , verify },
  { "listfiles", 'L', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, 0, (void *)"dpkg-query", execbackend },
  { "status", 's', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, 0, (void *)"dpkg-query", execbackend },
  { "get-selections", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_getselections, 
 ((void *)0)
 , getselections },
  { "set-selections", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_setselections, 
 ((void *)0)
 , setselections },
  { "clear-selections", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_clearselections, 
 ((void *)0)
 , clearselections },
  { "print-avail", 'p', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, 0, (void *)"dpkg-query", execbackend },
  { "update-avail", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_avreplace, 
 ((void *)0)
 , updateavailable },
  { "merge-avail", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_avmerge, 
 ((void *)0)
 , updateavailable },
  { "clear-avail", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_avclear, 
 ((void *)0)
 , updateavailable },
  { "forget-old-unavail", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_forgetold, 
 ((void *)0)
 , forgetold },
  { "audit", 'C', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_audit, 
 ((void *)0)
 , audit },
  { "yet-to-unpack", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_unpackchk, 
 ((void *)0)
 , unpackchk },
  { "list", 'l', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, 0, (void *)"dpkg-query", execbackend },
  { "search", 'S', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, 0, (void *)"dpkg-query", execbackend },
  { "assert-support-predepends", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_assertpredep, 
 ((void *)0)
 , assertpredep },
  { "assert-working-epoch", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_assertepoch, 
 ((void *)0)
 , assertepoch },
  { "assert-long-filenames", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_assertlongfilenames, 
 ((void *)0)
 , assertlongfilenames },
  { "assert-multi-conrep", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_assertmulticonrep, 
 ((void *)0)
 , assertmulticonrep },
  { "assert-multi-arch", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_assertmultiarch, 
 ((void *)0)
 , assertmultiarch },
  { "assert-versioned-provides", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_assertverprovides, 
 ((void *)0)
 , assertverprovides },
  { "assert-protected-field", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_assert_protected, 
 ((void *)0)
 , assert_protected },
  { "add-architecture", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_arch_add, 
 ((void *)0)
 , arch_add },
  { "remove-architecture", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_arch_remove, 
 ((void *)0)
 , arch_remove },
  { "print-architecture", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_printarch, 
 ((void *)0)
 , printarch },
  { "print-foreign-architectures", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_printforeignarches, 
 ((void *)0)
 , print_foreign_arches },
  { "predep-package", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_predeppackage, 
 ((void *)0)
 , predeppackage },
  { "validate-pkgname", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_validate_pkgname, 
 ((void *)0)
 , validate_pkgname },
  { "validate-trigname", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_validate_trigname, 
 ((void *)0)
 , validate_trigname },
  { "validate-archname", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_validate_archname, 
 ((void *)0)
 , validate_archname },
  { "validate-version", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_validate_version, 
 ((void *)0)
 , validate_version },
  { "compare-versions", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, act_cmpversions, 
 ((void *)0)
 , cmpversions },




  { "pre-invoke", 0, 1, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , set_invoke_hook, 0, &pre_invoke_hooks },
  { "post-invoke", 0, 1, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , set_invoke_hook, 0, &post_invoke_hooks },
  { "path-exclude", 0, 1, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , set_filter, 0 },
  { "path-include", 0, 1, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , set_filter, 1 },
  { "verify-format", 0, 1, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , set_verify_format },
  { "status-logger", 0, 1, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , set_invoke_hook, 0, &status_loggers },
  { "status-fd", 0, 1, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , set_pipe, 0 },
  { "log", 0, 1, 
                                ((void *)0)
                                    , &log_file, 
                                                          ((void *)0)
                                                              , 0 },
  { "pending", 'a', 0, &f_pending, 
                                               ((void *)0)
                                                   , 
                                                          ((void *)0)
                                                              , 1 },
  { "recursive", 'R', 0, &f_recursive, 
                                               ((void *)0)
                                                   , 
                                                          ((void *)0)
                                                              , 1 },
  { "no-act", 0, 0, &f_noact, 
                                               ((void *)0)
                                                   , 
                                                          ((void *)0)
                                                              , 1 },
  { "dry-run", 0, 0, &f_noact, 
                                               ((void *)0)
                                                   , 
                                                          ((void *)0)
                                                              , 1 },
  { "simulate", 0, 0, &f_noact, 
                                               ((void *)0)
                                                   , 
                                                          ((void *)0)
                                                              , 1 },
  { "no-pager", 0, 0, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , set_no_pager, 0 },
  { "no-debsig", 0, 0, &f_nodebsig, 
                                               ((void *)0)
                                                   , 
                                                          ((void *)0)
                                                              , 1 },

  { 
    ((void *)0)
        , 'G', 0, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , reset_force_option, FORCE_DOWNGRADE },
  { "selected-only", 'O', 0, &f_alsoselect, 
                                               ((void *)0)
                                                   , 
                                                          ((void *)0)
                                                              , 0 },
  { "triggers", 0, 0, &f_triggers, 
                                               ((void *)0)
                                                   , 
                                                          ((void *)0)
                                                              , 1 },
  { "no-triggers", 0, 0, &f_triggers, 
                                               ((void *)0)
                                                   , 
                                                          ((void *)0)
                                                              , -1 },

  { "no-also-select", 'N', 0, &f_alsoselect, 
                                               ((void *)0)
                                                   , 
                                                          ((void *)0)
                                                              , 0 },
  { "skip-same-version", 'E', 0, &f_skipsame, 
                                               ((void *)0)
                                                   , 
                                                          ((void *)0)
                                                              , 1 },
  { "auto-deconfigure", 'B', 0, &f_autodeconf, 
                                               ((void *)0)
                                                   , 
                                                          ((void *)0)
                                                              , 1 },
  { "robot", 0, 0, &f_robot, 
                                               ((void *)0)
                                                   , 
                                                          ((void *)0)
                                                              , 1 },
  { "root", 0, 1, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , set_root, 0 },
  { "abort-after", 0, 1, &errabort, 
                                               ((void *)0)
                                                   , set_integer, 0 },
  { "admindir", 0, 1, 
                                ((void *)0)
                                    , &admindir, 
                                                          ((void *)0)
                                                              , 0 },
  { "instdir", 0, 1, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , set_instdir, 0 },
  { "ignore-depends", 0, 1, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , set_ignore_depends, 0 },
  { "force", 0, 2, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , set_force_option, 1 },
  { "refuse", 0, 2, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , set_force_option, 0 },
  { "no-force", 0, 2, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , set_force_option, 0 },
  { "debug", 'D', 1, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , set_debug, 0 },
  { "help", '?', 0, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , usage, 0 },
  { "version", 0, 0, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , printversion, 0 },
  { "build", 'b', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, 0, (void *)"dpkg-deb", execbackend },
  { "contents", 'c', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, 0, (void *)"dpkg-deb", execbackend },
  { "control", 'e', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, 0, (void *)"dpkg-deb", execbackend },
  { "info", 'I', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, 0, (void *)"dpkg-deb", execbackend },
  { "field", 'f', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, 0, (void *)"dpkg-deb", execbackend },
  { "extract", 'x', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, 0, (void *)"dpkg-deb", execbackend },
  { "vextract", 'X', 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, 0, (void *)"dpkg-deb", execbackend },
  { "ctrl-tarfile", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, 0, (void *)"dpkg-deb", execbackend },
  { "fsys-tarfile", 0, 0, 
 ((void *)0)
 , 
 ((void *)0)
 , setaction, 0, (void *)"dpkg-deb", execbackend },
  { 
   ((void *)0)
       , 0, 0, 
                                ((void *)0)
                                    , 
                                               ((void *)0)
                                                   , 
                                                          ((void *)0)
                                                              , 0 }
};

int
execbackend(const char *const *argv)
{
  struct command cmd;

  command_init(&cmd, cipaction->arg_ptr, 
                                        ((void *)0)
                                            );
  command_add_arg(&cmd, cipaction->arg_ptr);
  command_add_arg(&cmd, str_fmt("--%s", cipaction->olong));



  command_add_arg(&cmd, "--");
  command_add_argl(&cmd, (const char **)argv);

  command_exec(&cmd);
}

int
commandfd(const char *const *argv)
{
  struct varbuf linevb = { 0, 0, 
                        ((void *)0) 
                        };
  const char * pipein;
  const char **newargs = 
                        ((void *)0)
                            , **endargs;
  char *ptr, *endptr;
  FILE *in;
  long infd;
  int ret = 0;
  int c, lno, i;
  
 _Bool 
      skipchar;

  pipein = *argv++;
  if (pipein == 
               ((void *)0) 
                    || *argv)
    badusage(gettext("--%s takes exactly one argument"), cipaction->olong);

  infd = dpkg_options_parse_arg_int(cipaction, pipein);
  in = fdopen(infd, "r");
  if (in == 
           ((void *)0)
               )
    ohshite(gettext("couldn't open '%i' for stream"), (int)infd);

  for (;;) {
    
   _Bool 
        mode = 
               0
                    ;
    int argc= 1;
    lno= 0;

    push_error_context();

    do {
      c = getc(in);
      if (c == '\n')
        lno++;
    } while (c != 
                 (-1) 
                     && c_isspace(c));
    if (c == 
            (-1)
               ) break;
    if (c == '#') {
      do { c= getc(in); if (c == '\n') lno++; } while (c != 
                                                           (-1) 
                                                               && c != '\n');
      continue;
    }
    varbuf_reset(&linevb);
    do {
      varbuf_add_char(&linevb, c);
      c= getc(in);
      if (c == '\n') lno++;


      if (c_isspace(c))
        argc++;
    } while (c != 
                 (-1) 
                     && c != '\n');
    if (c == 
            (-1)
               )
      ohshit(gettext("unexpected end of file before end of line %d"), lno);
    if (!argc) continue;
    varbuf_end_str(&linevb);
    newargs = m_realloc(newargs, sizeof(const char *) * (argc + 1));
    argc= 1;
    ptr= linevb.buf;
    endptr = ptr + linevb.used + 1;
    skipchar = 
              0
                   ;
    while(ptr < endptr) {
      if (skipchar) {
 skipchar = 
           0
                ;
      } else if (*ptr == '\\') {
 memmove(ptr, (ptr+1), (linevb.used-(linevb.buf - ptr)-1));
 endptr--;
 skipchar = 
           1
               ;
 continue;
      } else if (c_isspace(*ptr)) {
 if (mode == 
            1
                ) {
   *ptr = '\0';
   mode = 
         0
              ;
 }
      } else {
 if (mode == 
            0
                 ) {
   newargs[argc]= ptr;
   argc++;
   mode = 
         1
             ;
 }
      }
      ptr++;
    }
    *ptr = '\0';
    newargs[argc++] = 
                     ((void *)0)
                         ;





    for(i=1;i<argc;i++)
      if (newargs[i])
        newargs[i] = m_strdup(newargs[i]);
    endargs = newargs;

    setaction(
             ((void *)0)
                 , 
                   ((void *)0)
                       );
    dpkg_options_parse((const char *const **)&endargs, cmdinfos, printforhelp);
    if (!cipaction) badusage(gettext("need an action option"));

    ret |= cipaction->action(endargs);

    fsys_hash_reset();

    pop_error_context(ehflag_normaltidy);
  }

  fclose(in);

  return ret;
}

int main(int argc, const char *const *argv) {
  char *force_string;
  int ret;

  dpkg_locales_init("dpkg");
  dpkg_program_init("dpkg");
  set_force_default(FORCE_ALL);
  dpkg_options_load("dpkg", cmdinfos);
  dpkg_options_parse(&argv, cmdinfos, printforhelp);



  if (!in_force(FORCE_NON_ROOT) && getuid() == 0)
    if (setgid(0) < 0)
      ohshite(gettext("cannot set primary group ID to root"));

  if (!cipaction) badusage(gettext("need an action option"));

  admindir = dpkg_db_set_dir(admindir);


  if (setenv("DPKG_ADMINDIR", admindir, 1) < 0)
    ohshite(gettext("unable to setenv for subprocesses"));
  if (setenv("DPKG_ROOT", instdir, 1) < 0)
    ohshite(gettext("unable to setenv for subprocesses"));
  force_string = get_force_string();
  if (setenv("DPKG_FORCE", force_string, 1) < 0)
    ohshite(gettext("unable to setenv for subprocesses"));
  free(force_string);

  if (!f_triggers)
    f_triggers = (cipaction->arg_int == act_triggers && *argv) ? -1 : 1;

  if (is_invoke_action(cipaction->arg_int)) {
    run_invoke_hooks(cipaction->olong, &pre_invoke_hooks);
    run_status_loggers(&status_loggers);
  }

  ret = cipaction->action(argv);

  if (is_invoke_action(cipaction->arg_int))
    run_invoke_hooks(cipaction->olong, &post_invoke_hooks);

  free_invoke_hooks(&pre_invoke_hooks);
  free_invoke_hooks(&post_invoke_hooks);

  dpkg_program_done();
  dpkg_locales_done();

  return reportbroken_retexitstatus(ret);
}
