













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



struct match_node {
 struct match_node *next;
 char *filetype;
 char *filename;
};

struct match_node *
match_node_new(const char *name, const char *type, struct match_node *next);
void
match_node_free(struct match_node *node);

struct match_node *
match_node_new(const char *name, const char *type, struct match_node *next)
{
 struct match_node *node;

 node = m_malloc(sizeof(*node));
 node->next = next;
 node->filename = m_strdup(name);
 node->filetype = m_strdup(type);

 return node;
}

void
match_node_free(struct match_node *node)
{
 free(node->filetype);
 free(node->filename);
 free(node);
}
