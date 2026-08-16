
       












       
       
       
extern int _gl_cxxalias_dummy



                                                  ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                      ;

extern int _gl_cxxalias_dummy;
extern int rpl_fclose (FILE *stream) __attribute__ ((__nonnull__ (1)));
extern int _gl_cxxalias_dummy;




extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;




extern int _gl_cxxalias_dummy;
extern FILE * fdopen (int fd, const char *mode) __attribute__ ((__nonnull__ (2))) 
__attribute__ ((__malloc__ (
rpl_fclose
, 
1
)))

                                                                          
                                                                         ;

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int rpl_fflush (FILE *gl_stream);
extern int _gl_cxxalias_dummy;




extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                   ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern FILE * fopen (const char *
__restrict__ 
filename, const char *
__restrict__ 
mode) __attribute__ ((__nonnull__ (1, 2))) 
__attribute__ ((__malloc__ (
rpl_fclose
, 
1
)))

                                                                             
                                                                            ;

extern int _gl_cxxalias_dummy
                                                                             ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                        ;


extern int _gl_cxxalias_dummy;
extern int fpurge (FILE *gl_stream) __attribute__ ((__nonnull__ (1)));

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                       ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                          ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                          ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                            ;


extern int _gl_cxxalias_dummy;
extern int rpl_fseek (FILE *fp, long offset, int whence) __attribute__ ((__nonnull__ (1)))
                                                    ;
extern int _gl_cxxalias_dummy;




extern int _gl_cxxalias_dummy;
extern int rpl_fseeko (FILE *fp, off_t offset, int whence) __attribute__ ((__nonnull__ (1)))
                                                     ;
extern int _gl_cxxalias_dummy;







extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                          ;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy


                                          ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                          ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                       ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                           ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                     ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern FILE * tmpfile (void) 
__attribute__ ((__malloc__ (
rpl_fclose
, 
1
)))
                                                                     
                                                                    ;
extern int _gl_cxxalias_dummy
                                                           ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                                   ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                   ;


extern int _gl_cxxalias_dummy;
       




       








       
       


       


struct __time_t_must_be_integral {
  unsigned int __floating_time_t_unsupported : (time_t) 1;
};
extern int rpl_nanosleep (struct timespec const *__rqtp, struct timespec *__rmtp) __attribute__ ((__nonnull__ (1)))

                                        ;
extern int _gl_cxxalias_dummy
                                                                           ;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern time_t rpl_mktime (struct tm *__tp) __attribute__ ((__nonnull__ (1)));
extern int _gl_cxxalias_dummy;




extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                           ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                        ;


extern int _gl_cxxalias_dummy;
typedef struct tm_zone *timezone_t;
extern timezone_t tzalloc (char const *__name);
extern int _gl_cxxalias_dummy;




extern void tzfree (timezone_t __tz);
extern int _gl_cxxalias_dummy;






extern struct tm * localtime_rz (timezone_t __tz, time_t const *
__restrict__ 
__timer, struct tm *
__restrict__ 
__result) __attribute__ ((__nonnull__ (2, 3)))

                                                                          ;
extern int _gl_cxxalias_dummy

                                                 ;






extern time_t mktime_z (timezone_t __tz, struct tm *
__restrict__ 
__tm) __attribute__ ((__nonnull__ (2)))

                                        ;
extern int _gl_cxxalias_dummy
                                                              ;
extern time_t rpl_timegm (struct tm *__tm) __attribute__ ((__nonnull__ (1)));
extern int _gl_cxxalias_dummy;






extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                              ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                         ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                     ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                             ;


extern int _gl_cxxalias_dummy;





       
       
       
       
       


       
       

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                                         ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                               ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                               ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                 ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                      ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                             ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int rpl_pipe2 (int fd[2], int flags) __attribute__ ((__nonnull__ (1)));
extern int _gl_cxxalias_dummy;




extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                       ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                   ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                   ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy


                                                ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;





extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy


                                               ;
extern int _gl_cxxalias_dummy;







typedef void (*_gl_function_taking_int_returning_void_t) (int);
extern int _gl_cxxalias_dummy
                                                                           ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                               ;
extern int _gl_cxxalias_dummy;




       

       





       
       
extern int _gl_cxxalias_dummy
                                                                  ;

extern int _gl_cxxalias_dummy;
       







       







extern void free (void *);
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                 ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                                             ;



extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                          ;
extern int _gl_cxxalias_dummy

                               ;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                                  ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                                    ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                     ;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                               ;

extern int _gl_cxxalias_dummy;
extern char * strdup (char const *__s) __attribute__ ((__nonnull__ (1))) 
__attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))


                                                                  
                                                                 ;

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                            ;


extern int _gl_cxxalias_dummy;
extern char * strndup (char const *__s, size_t __n) __attribute__ ((__nonnull__ (1))) 
__attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))


                                                                  
                                                                 ;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                                                 ;



extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                              ;
extern size_t mbslen (const char *string) 
__attribute__ ((__pure__)) 
__attribute__ ((__nonnull__ (1)))

                                                        ;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern char * mbschr (const char *string, int c) 
__attribute__ ((__pure__)) 
__attribute__ ((__nonnull__ (1)))

                                                        ;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern char * mbsstr (const char *haystack, const char *needle)
     
    __attribute__ ((__pure__))
     
    __attribute__ ((__nonnull__ (1, 2)));
extern int mbscasecmp (const char *s1, const char *s2)
     
    __attribute__ ((__pure__))
     
    __attribute__ ((__nonnull__ (1, 2)));
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
       
       





extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern void * aligned_alloc (size_t alignment, size_t size) 
__attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))

                                                                  
                                                                 ;
extern void * calloc (size_t nmemb, size_t size) 
__attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))

                                                                  
                                                                 ;

extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern char * canonicalize_file_name (const char *name) __attribute__ ((__nonnull__ (1))) 
__attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))


                                                                  
                                                                 ;

extern int _gl_cxxalias_dummy;





extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                        ;



extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                        ;



extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;



extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern void * malloc (size_t size) 
__attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))

                                                                  
                                                                 ;

extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                            ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                 ;



extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern void * realloc (void *ptr, size_t size) 
__attribute__ ((__malloc__ (free, 1)))
                                                              
                                                             ;

extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                         ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                     ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                   ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                   ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                             ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                             ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;

extern char const *Version;


enum
{
  EXIT_TIMEDOUT = 124,
  EXIT_CANCELED = 125,
  EXIT_CANNOT_INVOKE = 126,
  EXIT_ENOENT = 127
};

extern int volatile exit_failure;


static inline void
initialize_exit_failure (int status)
{
  if (status != 
               1
                           )
    exit_failure = status;
}

       
       
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int rpl_fcntl (int fd, int action, ...);
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;




extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                               ;

extern int _gl_cxxalias_dummy;


enum { O_PATHSEARCH = 
                     010000000 
                            };




       











       
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern DIR * opendir (const char *dir_name) __attribute__ ((__nonnull__ (1))) 
__attribute__ ((__malloc__)) __attribute__ ((__malloc__ (
closedir
, 
1
)))


                                                                           
                                                                          ;

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern DIR * fdopendir (int fd) 
__attribute__ ((__malloc__)) __attribute__ ((__malloc__ (
closedir
, 
1
)))

                                                                           
                                                                          ;

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;





enum
{
  NOT_AN_INODE_NUMBER = 0
};
       
       
extern int _gl_cxxalias_dummy
                                                               ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                               ;

extern int _gl_cxxalias_dummy;

       










enum { TIMESPEC_HZ = 1000000000 };
enum { LOG10_TIMESPEC_HZ = 9 };




enum { TIMESPEC_RESOLUTION = TIMESPEC_HZ };
enum { LOG10_TIMESPEC_RESOLUTION = LOG10_TIMESPEC_HZ };



inline struct timespec
make_timespec (time_t s, long int ns)
{
  struct timespec r;
  r.tv_sec = s;
  r.tv_nsec = ns;
  return r;
}



inline int __attribute__ ((__pure__))
timespec_cmp (struct timespec a, struct timespec b)
{
  return 2 * (((a.tv_sec) > (b.tv_sec)) - ((a.tv_sec) < (b.tv_sec))) + (((a.tv_nsec) > (b.tv_nsec)) - ((a.tv_nsec) < (b.tv_nsec)));
}



inline int __attribute__ ((__pure__))
timespec_sign (struct timespec a)
{
  return (((a.tv_sec) > (0)) - ((a.tv_sec) < (0))) + (!a.tv_sec & !!a.tv_nsec);
}

struct timespec timespec_add (struct timespec, struct timespec)
  __attribute__ ((__const__));
struct timespec timespec_sub (struct timespec, struct timespec)
  __attribute__ ((__const__));
struct timespec dtotimespec (double)
  __attribute__ ((__const__));


inline double
timespectod (struct timespec a)
{
  return a.tv_sec + a.tv_nsec / 1e9;
}

long int gettime_res (void);
struct timespec current_timespec (void);
void gettime (struct timespec *) 
                                __attribute__ ((__nonnull__ 
                                (1)
                                ))
                                                     ;
int settime (struct timespec const *) 
                                     __attribute__ ((__nonnull__ 
                                     (1)
                                     ))
                                                          ;







       






static inline unsigned char to_uchar (char ch) { return ch; }


static inline 
             _Bool

field_sep (unsigned char ch)
{
  return 
        ((*__ctype_b_loc ())[(int) ((
        ch
        ))] & (unsigned short int) _ISblank) 
                     || ch == '\n';
}

       







extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int setlocale_null_r (int category, char *buf, size_t bufsize)
  __attribute__ ((__nonnull__ (2)));
extern const char *setlocale_null (int category);




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



  char buf[1024];
  char *msg_ctxt_id =
    (msgctxt_len + msgid_len <= sizeof (buf)
     ? buf
     : (char *) malloc (msgctxt_len + msgid_len));
  if (msg_ctxt_id != 
                    ((void *)0)
                        )

    {
      int found_translation;
      memcpy (msg_ctxt_id, msgctxt, msgctxt_len - 1);
      msg_ctxt_id[msgctxt_len - 1] = '\004';
      memcpy (msg_ctxt_id + msgctxt_len, msgid, msgid_len);
      translation = dcgettext (domain, msg_ctxt_id, category);
      found_translation = (translation != msg_ctxt_id);

      if (msg_ctxt_id != buf)
        free (msg_ctxt_id);

      if (found_translation)
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



  char buf[1024];
  char *msg_ctxt_id =
    (msgctxt_len + msgid_len <= sizeof (buf)
     ? buf
     : (char *) malloc (msgctxt_len + msgid_len));
  if (msg_ctxt_id != 
                    ((void *)0)
                        )

    {
      int found_translation;
      memcpy (msg_ctxt_id, msgctxt, msgctxt_len - 1);
      msg_ctxt_id[msgctxt_len - 1] = '\004';
      memcpy (msg_ctxt_id + msgctxt_len, msgid, msgid_len);
      translation = dcngettext (domain, msg_ctxt_id, msgid_plural, n, category);
      found_translation = !(translation == msg_ctxt_id || translation == msgid_plural);

      if (msg_ctxt_id != buf)
        free (msg_ctxt_id);

      if (found_translation)
        return translation;
    }
  return (n == 1 ? msgid : msgid_plural);
}
static inline unsigned long int
select_plural (uintmax_t n)
{


  enum { PLURAL_REDUCER = 1000000 };
  return (n <= 
              (0x7fffffffffffffffL * 2UL + 1UL) 
                        ? n : n % PLURAL_REDUCER + PLURAL_REDUCER);
}
       



typedef ptrdiff_t idx_t;
       






           _Noreturn void xalloc_die (void);





void *xmalloc (size_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (1))) __attribute__ ((__returns_nonnull__));
void *ximalloc (idx_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (1))) __attribute__ ((__returns_nonnull__));
void *xinmalloc (idx_t n, idx_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (1, 2))) __attribute__ ((__returns_nonnull__));
void *xzalloc (size_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (1))) __attribute__ ((__returns_nonnull__));
void *xizalloc (idx_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (1))) __attribute__ ((__returns_nonnull__));
void *xcalloc (size_t n, size_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (1, 2))) __attribute__ ((__returns_nonnull__));
void *xicalloc (idx_t n, idx_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (1, 2))) __attribute__ ((__returns_nonnull__));
void *xrealloc (void *p, size_t s)
  __attribute__ ((__alloc_size__ (2)));
void *xirealloc (void *p, idx_t s)
  __attribute__ ((__alloc_size__ (2))) __attribute__ ((__returns_nonnull__));
void *xreallocarray (void *p, size_t n, size_t s)
  __attribute__ ((__alloc_size__ (2, 3)));
void *xireallocarray (void *p, idx_t n, idx_t s)
  __attribute__ ((__alloc_size__ (2, 3))) __attribute__ ((__returns_nonnull__));
void *x2realloc (void *p, size_t *ps)
  __attribute__ ((__returns_nonnull__));
void *x2nrealloc (void *p, size_t *pn, size_t s)
  __attribute__ ((__returns_nonnull__));
void *xpalloc (void *pa, idx_t *pn, idx_t n_incr_min, ptrdiff_t n_max, idx_t s)
  __attribute__ ((__returns_nonnull__));
void *xmemdup (void const *p, size_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (2))) __attribute__ ((__returns_nonnull__));
void *ximemdup (void const *p, idx_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (2))) __attribute__ ((__returns_nonnull__));
char *ximemdup0 (void const *p, idx_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__returns_nonnull__));
char *xstrdup (char const *str)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__returns_nonnull__));
void *xnmalloc (size_t n, size_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (1, 2))) __attribute__ ((__returns_nonnull__));





inline void *xnrealloc (void *p, size_t n, size_t s)
  __attribute__ ((__alloc_size__ (2, 3)));
inline void *
xnrealloc (void *p, size_t n, size_t s)
{
  return xreallocarray (p, n, s);
}




char *xcharalloc (size_t n)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (1))) __attribute__ ((__returns_nonnull__));

       
       

       
       
extern char *last_component (char const *filename) __attribute__ ((__pure__));




extern size_t base_len (char const *filename) __attribute__ ((__pure__));
char *base_name (char const *file)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__returns_nonnull__));
char *dir_name (char const *file)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__returns_nonnull__));


char *mdir_name (char const *file)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)));
size_t dir_len (char const *file) __attribute__ ((__pure__));


_Bool 
    strip_trailing_slashes (char *file);
       

       
       







_Noreturn void openat_restore_fail (int);
_Noreturn void openat_save_fail (int);
inline int
chownat (int fd, char const *file, uid_t owner, gid_t group)
{
  return fchownat (fd, file, owner, group, 0);
}

inline int
lchownat (int fd, char const *file, uid_t owner, gid_t group)
{
  return fchownat (fd, file, owner, group, 
                                          0x100
                                                             );
}
inline int
chmodat (int fd, char const *file, mode_t mode)
{
  return fchmodat (fd, file, mode, 0);
}

inline int
lchmodat (int fd, char const *file, mode_t mode)
{
  return fchmodat (fd, file, mode, 
                                  0x100
                                                     );
}


static inline 
             _Bool

dot_or_dotdot (char const *file_name)
{
  if (file_name[0] == '.')
    {
      char sep = file_name[(file_name[1] == '.') + 1];
      return (! sep || ((sep) == '/'));
    }
  else
    return 
          0
               ;
}


static inline struct dirent const *
readdir_ignoring_dot_and_dotdot (DIR *dirp)
{
  while (
        1
            )
    {
      struct dirent const *dp = readdir (dirp);
      if (dp == 
               ((void *)0) 
                    || ! dot_or_dotdot (dp->d_name))
        return dp;
    }
}




static inline 
             _Bool

is_empty_dir (int fd_cwd, char const *dir)
{
  DIR *dirp;
  struct dirent const *dp;
  int saved_errno;
  int fd = openat (fd_cwd, dir,
                   (
                   00 
                            | 
                              0200000
                    
                   | 
                     0400 
                              | 
                                0400000 
                                           | 
                                             04000
                                                       ));

  if (fd < 0)
    return 
          0
               ;

  dirp = fdopendir (fd);
  if (dirp == 
             ((void *)0)
                 )
    {
      close (fd);
      return 
            0
                 ;
    }

  
 (*__errno_location ()) 
       = 0;
  dp = readdir_ignoring_dot_and_dotdot (dirp);
  saved_errno = 
               (*__errno_location ())
                    ;
  closedir (dirp);
  
 (*__errno_location ()) 
       = saved_errno;
  if (dp != 
           ((void *)0)
               )
    return 
          0
               ;
  return saved_errno == 0 ? 
                           1 
                                : 
                                  0
                                       ;
}






enum
{
  GETOPT_HELP_CHAR = (
                     (-0x7f - 1) 
                              - 2),
  GETOPT_VERSION_CHAR = (
                        (-0x7f - 1) 
                                 - 3)
};
void close_stdin_set_file_name (const char *file);
void close_stdin (void);
void close_stdout_set_file_name (const char *file);
void close_stdout_set_ignore_EPIPE (
                                   _Bool 
                                        ignore);
void close_stdout (void);


       






extern const char version_etc_copyright[];
extern void version_etc_arn (FILE *stream,
                             const char *command_name, const char *package,
                             const char *version,
                             const char * const * authors, size_t n_authors);


extern void version_etc_ar (FILE *stream,
                            const char *command_name, const char *package,
                            const char *version, const char * const * authors);


extern void version_etc_va (FILE *stream,
                            const char *command_name, const char *package,
                            const char *version, va_list authors);



extern void version_etc (FILE *stream,
                         const char *command_name, const char *package,
                         const char *version,
                                                              ...)
  __attribute__ ((__sentinel__ (0)));


extern void unused__emit_bug_reporting_address (void);


extern const char * proper_name (const char *name) ;





extern const char * proper_name_utf8 (const char *name_ascii,
                                      const char *name_utf8);







extern const char *program_name;




extern void set_program_name (const char *argv0);
__attribute__ ((__const__))
static inline size_t
gcd (size_t u, size_t v)
{
  do
    {
      size_t t = u % v;
      u = v;
      v = t;
    }
  while (v);

  return u;
}





__attribute__ ((__const__))
static inline size_t
lcm (size_t u, size_t v)
{
  return u * (v / gcd (u, v));
}






static inline void *
ptr_align (void const *ptr, size_t alignment)
{
  char const *p0 = ptr;
  char const *p1 = p0 + alignment - 1;
  return (void *) (p1 - (size_t) p1 % alignment);
}




__attribute__ ((__pure__))
static inline 
             _Bool

is_nul (void const *buf, size_t length)
{
  const unsigned char *p = buf;
  unsigned char word;


  if (! length)
      return 
            1
                ;


  while (__builtin_expect ((length & (sizeof word - 1)), 0))
    {
      if (*p)
        return 
              0
                   ;
      p++;
      length--;
      if (! length)
        return 
              1
                  ;
   }


  for (;;)
    {
      memcpy (&word, p, sizeof word);
      if (word)
        return 
              0
                   ;
      p += sizeof word;
      length -= sizeof word;
      if (! length)
        return 
              1
                  ;
      if (__builtin_expect ((length & 15), 0) == 0)
        break;
   }


   return memcmp (buf, p, length) == 0;
}
static inline void
emit_stdin_note (void)
{
  fputs_unlocked (gettext ("\nWith no FILE, or when FILE is -, read standard input.\n"),
 stdout
 )

           ;
}
static inline void
emit_mandatory_arg_note (void)
{
  fputs_unlocked (gettext ("\nMandatory arguments to long options are mandatory for short options too.\n"),
 stdout
 )

           ;
}

static inline void
emit_size_note (void)
{
  fputs_unlocked (gettext ("\nThe SIZE argument is an integer and optional unit (example: 10K is 10*1024).\nUnits are K,M,G,T,P,E,Z,Y (powers of 1024) or KB,MB,... (powers of 1000).\nBinary prefixes can be used, too: KiB=K, MiB=M, and so on.\n"),
 stdout
 )



           ;
}

static inline void
emit_blocksize_note (char const *program)
{
  printf (gettext ("\nDisplay values are in units of the first available SIZE from --block-size,\nand the %s_BLOCK_SIZE, BLOCK_SIZE and BLOCKSIZE environment variables.\nOtherwise, units default to 1024 bytes (or 512 if POSIXLY_CORRECT is set).\n")



  , program);
}

static inline void
emit_backup_suffix_note (void)
{
  fputs_unlocked (gettext ("\nThe backup suffix is '~', unless set with --suffix or SIMPLE_BACKUP_SUFFIX.\nThe version control method may be selected via the --backup option or through\nthe VERSION_CONTROL environment variable.  Here are the values:\n\n"),
 stdout
 )





           ;
  fputs_unlocked (gettext ("  none, off       never make backups (even if --backup is given)\n  numbered, t     make numbered backups\n  existing, nil   numbered if numbered backups exist, simple otherwise\n  simple, never   always make simple backups\n"),
 stdout
 )




           ;
}

static inline void
emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { 
     ((void *)0)
         , 
           ((void *)0) 
                }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! (strcmp (program, map_prog->program) == 0))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (gettext ("\n%s online help: <%s>\n"), "GNU coreutils", "https://www.gnu.org/software/coreutils/");



  char const *lc_messages = setlocale (
                                      5
                                                 , 
                                                   ((void *)0)
                                                       );
  if (lc_messages && strncmp (lc_messages, "" "en_" "", sizeof ("en_") - 1))
    {




      fputs_unlocked (gettext ("Report any translation bugs to " "<https://translationproject.org/team/>\n"),
     stdout
     )
                                                                   ;
    }



  char const *url_program = (strcmp (program, "[") == 0) ? "test" : program;
  printf (gettext ("Full documentation <%s%s>\n"),
          "https://www.gnu.org/software/coreutils/", url_program);
  printf (gettext ("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}
       



[[__nodiscard__]] char *imaxtostr (intmax_t, char *);
[[__nodiscard__]] char *inttostr (int, char *);
[[__nodiscard__]] char *offtostr (off_t, char *);
[[__nodiscard__]] char *uinttostr (unsigned int, char *);
[[__nodiscard__]] char *umaxtostr (uintmax_t, char *);

static inline char *
timetostr (time_t t, char *buf)
{
  return ((! ((time_t) 0 < (time_t) -1))
          ? imaxtostr (t, buf)
          : umaxtostr (t, buf));
}

static inline char *
bad_cast (char const *s)
{
  return (char *) s;
}


static inline 
             _Bool

usable_st_size (struct stat const *sb)
{
  return (
         ((((
         sb->st_mode
         )) & 0170000) == (0100000)) 
                               || 
                                  ((((
                                  sb->st_mode
                                  )) & 0170000) == (0120000))
          
         || 
            ((
            sb
            )->st_mode - (
            sb
            )->st_mode) 
                             || 
                                0
                                                );
}

_Noreturn void usage (int status);
static inline char *
stzncpy (char *__restrict__ dest, char const *__restrict__ src, size_t len)
{
  char const *src_end = src + len;
  while (src < src_end && *src)
    *dest++ = *src++;
  *dest = 0;
  return dest;
}
static inline 
             _Bool

is_ENOTSUP (int err)
{
  return err == 
               95 
                          || (
                              95 
                                      != 
                                         95 
                                                    && err == 
                                                              95
                                                                     );
}




       







enum quoting_style
  {
    literal_quoting_style,
    shell_quoting_style,
    shell_always_quoting_style,
    shell_escape_quoting_style,
    shell_escape_always_quoting_style,
    c_quoting_style,
    c_maybe_quoting_style,
    escape_quoting_style,
    locale_quoting_style,
    clocale_quoting_style,
    custom_quoting_style
  };


enum quoting_flags
  {



    QA_ELIDE_NULL_BYTES = 0x01,




    QA_ELIDE_OUTER_QUOTES = 0x02,





    QA_SPLIT_TRIGRAPHS = 0x04
  };







extern char const *const quoting_style_args[];
extern enum quoting_style const quoting_style_vals[];

struct quoting_options;







struct quoting_options *clone_quoting_options (struct quoting_options *o)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__returns_nonnull__));


enum quoting_style get_quoting_style (struct quoting_options const *o);



void set_quoting_style (struct quoting_options *o, enum quoting_style s);
int set_char_quoting (struct quoting_options *o, char c, int i);





int set_quoting_flags (struct quoting_options *o, int i);
void set_custom_quoting (struct quoting_options *o,
                         char const *left_quote,
                         char const *right_quote);
size_t quotearg_buffer (char *__restrict__ buffer, size_t buffersize,
                        char const *arg, size_t argsize,
                        struct quoting_options const *o);




char *quotearg_alloc (char const *arg, size_t argsize,
                      struct quoting_options const *o)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__returns_nonnull__));







char *quotearg_alloc_mem (char const *arg, size_t argsize,
                          size_t *size, struct quoting_options const *o)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__returns_nonnull__));
char *quotearg_n (int n, char const *arg);


char *quotearg (char const *arg);




char *quotearg_n_mem (int n, char const *arg, size_t argsize);


char *quotearg_mem (char const *arg, size_t argsize);




char *quotearg_n_style (int n, enum quoting_style s, char const *arg);




char *quotearg_n_style_mem (int n, enum quoting_style s,
                            char const *arg, size_t argsize);


char *quotearg_style (enum quoting_style s, char const *arg);


char *quotearg_style_mem (enum quoting_style s,
                          char const *arg, size_t argsize);



char *quotearg_char (char const *arg, char ch);


char *quotearg_char_mem (char const *arg, size_t argsize, char ch);


char *quotearg_colon (char const *arg);


char *quotearg_colon_mem (char const *arg, size_t argsize);


char *quotearg_n_style_colon (int n, enum quoting_style s, char const *arg);





char *quotearg_n_custom (int n, char const *left_quote,
                         char const *right_quote, char const *arg);



char *quotearg_n_custom_mem (int n, char const *left_quote,
                             char const *right_quote,
                             char const *arg, size_t argsize);


char *quotearg_custom (char const *left_quote, char const *right_quote,
                       char const *arg);



char *quotearg_custom_mem (char const *left_quote,
                           char const *right_quote,
                           char const *arg, size_t argsize);


void quotearg_free (void);
       






inline void
alignfree (void *ptr)
{
  free (ptr);
}







inline
__attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (2)))

void *
alignalloc (idx_t alignment, idx_t size)
{
  if ((size_t) -1 < alignment)
    alignment = (size_t) -1;
  if ((size_t) -1 < size)
    size = (size_t) -1;


  return aligned_alloc (alignment, size);







}
void *xalignalloc (idx_t, idx_t)
  __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (2)))
  __attribute__ ((__returns_nonnull__)) ;


enum { IO_BUFSIZE = 128 * 1024 };
static inline idx_t
io_blksize (struct stat sb)
{


  return 
        (((((((9223372036854775807L))<((18446744073709551615UL)))?((9223372036854775807L)):((18446744073709551615UL))) 
        / 2 + 1
        )<((((
        IO_BUFSIZE
        )>(
        ((0 < (sb).st_blksize && (sb).st_blksize <= ((size_t)-1) / 8 + 1) ? (sb).st_blksize : 
        512
        )
        ))?(
        IO_BUFSIZE
        ):(
        ((0 < (sb).st_blksize && (sb).st_blksize <= ((size_t)-1) / 8 + 1) ? (sb).st_blksize : 
        512
        )
        ))))?(((((9223372036854775807L))<((18446744073709551615UL)))?((9223372036854775807L)):((18446744073709551615UL))) 
        / 2 + 1
        ):((((
        IO_BUFSIZE
        )>(
        ((0 < (sb).st_blksize && (sb).st_blksize <= ((size_t)-1) / 8 + 1) ? (sb).st_blksize : 
        512
        )
        ))?(
        IO_BUFSIZE
        ):(
        ((0 < (sb).st_blksize && (sb).st_blksize <= ((size_t)-1) / 8 + 1) ? (sb).st_blksize : 
        512
        )
        ))))
                                                
                                               ;
}
       
extern void error (int __status, int __errnum, const char *__format, ...)

     __attribute__ ((__format__ (
    __gnu_printf__
    , 3, 4)))



     ;

extern void error_at_line (int __status, int __errnum, const char *__fname,
                           unsigned int __lineno, const char *__format, ...)

     __attribute__ ((__format__ (
    __gnu_printf__
    , 5, 6)))



     ;




extern void (*error_print_progname) (void);


extern unsigned int error_message_count;



extern int error_one_per_line;

       
       
       
typedef enum {
  FADVISE_NORMAL = 
                      0
                                       ,
  FADVISE_SEQUENTIAL = 
                      2
                                           ,
  FADVISE_NOREUSE = 
                      5
                                        ,
  FADVISE_DONTNEED = 
                      4
                                         ,
  FADVISE_WILLNEED = 
                      3
                                         ,
  FADVISE_RANDOM = 
                      1

} fadvice_t;
void fdadvise (int fd, off_t offset, off_t len, fadvice_t advice);
void fadvise (FILE *fp, fadvice_t advice);
extern size_t full_write (int fd, const void *buf, size_t count);
extern size_t safe_read (int fd, void *buf, size_t count);
       



       





inline int
__gl_setmode ([[__maybe_unused__]] int fd, [[__maybe_unused__]] int mode)
{
  return 
        0
                ;
}
inline int
set_binary_mode (int fd, int mode)
{
  return __gl_setmode (fd, mode);
}


















inline void xset_binary_mode_error (void) {}





inline void
xset_binary_mode (int fd, int mode)
{
  if (set_binary_mode (fd, mode) < 0)
    xset_binary_mode_error ();
}


static char const *infile;


static int input_desc;





static char line_buf[20] =
  {
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '0',
    '\t', '\0'
  };



static char *line_num_print = line_buf + 20 - 8;


static char *line_num_start = line_buf + 20 - 3;


static char *line_num_end = line_buf + 20 - 3;


static int newlines2 = 0;


static 
      _Bool 
           pending_cr = 
                        0
                             ;

void
usage (int status)
{
  if (status != 
               0
                           )
    do { fprintf (
   stderr
   , gettext ("Try '%s --help' for more information.\n"), program_name); } while (0);
  else
    {
      printf (gettext ("Usage: %s [OPTION]... [FILE]...\n")

  ,
              program_name);
      fputs_unlocked (gettext ("Concatenate FILE(s) to standard output.\n"),
     stdout
     )

           ;

      emit_stdin_note ();

      fputs_unlocked (gettext ("\n  -A, --show-all           equivalent to -vET\n  -b, --number-nonblank    number nonempty output lines, overrides -n\n  -e                       equivalent to -vE\n  -E, --show-ends          display $ at end of each line\n  -n, --number             number all output lines\n  -s, --squeeze-blank      suppress repeated empty output lines\n"),
     stdout
     )







           ;
      fputs_unlocked (gettext ("  -t                       equivalent to -vT\n  -T, --show-tabs          display TAB characters as ^I\n  -u                       (ignored)\n  -v, --show-nonprinting   use ^ and M- notation, except for LFD and TAB\n"),
     stdout
     )




           ;
      fputs_unlocked (gettext ("      --help        display this help and exit\n"),
     stdout
     );
      fputs_unlocked (gettext ("      --version     output version information and exit\n"),
     stdout
     );
      printf (gettext ("\nExamples:\n  %s f - g  Output f's contents, then standard input, then g's contents.\n  %s        Copy standard input to standard output.\n")




  ,
              program_name, program_name);
      emit_ancillary_info ("cat");
    }
  exit (status);
}



static void
next_line_num (void)
{
  char *endp = line_num_end;
  do
    {
      if ((*endp)++ < '9')
        return;
      *endp-- = '0';
    }
  while (endp >= line_num_start);

  if (line_num_start > line_buf)
    *--line_num_start = '1';
  else
    *line_buf = '>';
  if (line_num_start < line_num_print)
    line_num_print--;
}





static 
      _Bool

simple_cat (char *buf, idx_t bufsize)
{


  while (
        1
            )
    {


      size_t n_read = safe_read (input_desc, buf, bufsize);
      if (n_read == ((size_t) -1))
        {
          error (0, 
                   (*__errno_location ())
                        , "%s", quotearg_n_style_colon (0, shell_escape_quoting_style, infile));
          return 
                0
                     ;
        }



      if (n_read == 0)
        return 
              1
                  ;



      if (full_write (
                     1
                                  , buf, n_read) != n_read)
        ((!!sizeof (struct { _Static_assert (
       1
       , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), gettext (\"write error\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
       1
       , 
       (*__errno_location ())
       , gettext ("write error")), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
       1
       , 
       (*__errno_location ())
       , gettext ("write error")), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))));
    }
}





static inline void
write_pending (char *outbuf, char **bpout)
{
  idx_t n_write = *bpout - outbuf;
  if (0 < n_write)
    {
      if (full_write (
                     1
                                  , outbuf, n_write) != n_write)
        ((!!sizeof (struct { _Static_assert (
       1
       , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), gettext (\"write error\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
       1
       , 
       (*__errno_location ())
       , gettext ("write error")), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
       1
       , 
       (*__errno_location ())
       , gettext ("write error")), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))));
      *bpout = outbuf;
    }
}
static 
      _Bool

cat (char *inbuf, idx_t insize, char *outbuf, idx_t outsize,
     
    _Bool 
         show_nonprinting, 
                           _Bool 
                                show_tabs, 
                                           _Bool 
                                                number, 
                                                        _Bool 
                                                             number_nonblank,
     
    _Bool 
         show_ends, 
                    _Bool 
                         squeeze_blank)
{

  unsigned char ch;






  int newlines = newlines2;




  
 _Bool 
      use_fionread = 
                     1
                         ;







  char *eob = inbuf;


  char *bpin = eob + 1;


  char *bpout = outbuf;

  while (
        1
            )
    {
      do
        {


          if (outbuf + outsize <= bpout)
            {
              char *wp = outbuf;
              idx_t remaining_bytes;
              do
                {
                  if (full_write (
                                 1
                                              , wp, outsize) != outsize)
                    ((!!sizeof (struct { _Static_assert (
                   1
                   , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), gettext (\"write error\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
                   1
                   , 
                   (*__errno_location ())
                   , gettext ("write error")), ((
                   0
                   ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
                   1
                   , 
                   (*__errno_location ())
                   , gettext ("write error")), ((
                   0
                   ) ? (void) 0 : __builtin_unreachable ()))));
                  wp += outsize;
                  remaining_bytes = bpout - wp;
                }
              while (outsize <= remaining_bytes);




              memmove (outbuf, wp, remaining_bytes);
              bpout = outbuf + remaining_bytes;
            }



          if (bpin > eob)
            {
              
             _Bool 
                  input_pending = 
                                  0
                                       ;

              int n_to_read = 0;





              if (use_fionread
                  && ioctl (input_desc, 
                                       0x541B
                                               , &n_to_read) < 0)
                {






                  if (
                     (*__errno_location ()) 
                           == 
                              95 
                                         || 
                                            (*__errno_location ()) 
                                                  == 
                                                     25
                      
                     || 
                        (*__errno_location ()) 
                              == 
                                 22 
                                        || 
                                           (*__errno_location ()) 
                                                 == 
                                                    19
                      
                     || 
                        (*__errno_location ()) 
                              == 
                                 38
                                       )
                    use_fionread = 
                                  0
                                       ;
                  else
                    {
                      error (0, 
                               (*__errno_location ())
                                    , gettext ("cannot do ioctl on %s"),
                             quotearg_style (shell_escape_always_quoting_style, infile));
                      newlines2 = newlines;
                      return 
                            0
                                 ;
                    }
                }
              if (n_to_read != 0)
                input_pending = 
                               1
                                   ;


              if (!input_pending)
                write_pending (outbuf, &bpout);



              size_t n_read = safe_read (input_desc, inbuf, insize);
              if (n_read == ((size_t) -1))
                {
                  error (0, 
                           (*__errno_location ())
                                , "%s", quotearg_n_style_colon (0, shell_escape_quoting_style, infile));
                  write_pending (outbuf, &bpout);
                  newlines2 = newlines;
                  return 
                        0
                             ;
                }
              if (n_read == 0)
                {
                  write_pending (outbuf, &bpout);
                  newlines2 = newlines;
                  return 
                        1
                            ;
                }




              bpin = inbuf;
              eob = bpin + n_read;
              *eob = '\n';
            }
          else
            {





              if (++newlines > 0)
                {
                  if (newlines >= 2)
                    {



                      newlines = 2;




                      if (squeeze_blank)
                        {
                          ch = *bpin++;
                          continue;
                        }
                    }



                  if (number && !number_nonblank)
                    {
                      next_line_num ();
                      bpout = stpcpy (bpout, line_num_print);
                    }
                }


              if (show_ends)
                {
                  if (pending_cr)
                    {
                      *bpout++ = '^';
                      *bpout++ = 'M';
                      pending_cr = 
                                  0
                                       ;
                    }
                  *bpout++ = '$';
                }



              *bpout++ = '\n';
            }
          ch = *bpin++;
        }
      while (ch == '\n');



      if (pending_cr)
        {
          *bpout++ = '\r';
          pending_cr = 
                      0
                           ;
        }



      if (newlines >= 0 && number)
        {
          next_line_num ();
          bpout = stpcpy (bpout, line_num_print);
        }







      if (show_nonprinting)
        {
          while (
                1
                    )
            {
              if (ch >= 32)
                {
                  if (ch < 127)
                    *bpout++ = ch;
                  else if (ch == 127)
                    {
                      *bpout++ = '^';
                      *bpout++ = '?';
                    }
                  else
                    {
                      *bpout++ = 'M';
                      *bpout++ = '-';
                      if (ch >= 128 + 32)
                        {
                          if (ch < 128 + 127)
                            *bpout++ = ch - 128;
                          else
                            {
                              *bpout++ = '^';
                              *bpout++ = '?';
                            }
                        }
                      else
                        {
                          *bpout++ = '^';
                          *bpout++ = ch - 128 + 64;
                        }
                    }
                }
              else if (ch == '\t' && !show_tabs)
                *bpout++ = '\t';
              else if (ch == '\n')
                {
                  newlines = -1;
                  break;
                }
              else
                {
                  *bpout++ = '^';
                  *bpout++ = ch + 64;
                }

              ch = *bpin++;
            }
        }
      else
        {

          while (
                1
                    )
            {
              if (ch == '\t' && show_tabs)
                {
                  *bpout++ = '^';
                  *bpout++ = ch + 64;
                }
              else if (ch != '\n')
                {
                  if (ch == '\r' && *bpin == '\n' && show_ends)
                    {
                      if (bpin == eob)
                        pending_cr = 
                                    1
                                        ;
                      else
                        {
                          *bpout++ = '^';
                          *bpout++ = 'M';
                        }
                    }
                  else
                    *bpout++ = ch;
                }
              else
                {
                  newlines = -1;
                  break;
                }

              ch = *bpin++;
            }
        }
    }
}





static int
copy_cat (void)
{



  ssize_t copy_max = 
                    (((0x7fffffffffffffffL)<((18446744073709551615UL)))?(0x7fffffffffffffffL):((18446744073709551615UL))) 
                                              >> 30 << 30;







  for (
      _Bool 
           some_copied = 
                         0
                              ; ; some_copied = 
                                                1
                                                    )
    switch (copy_file_range (input_desc, 
                                        ((void *)0)
                                            , 
                                              1
                                                           , 
                                                             ((void *)0)
                                                                 ,
                             copy_max, 0))
      {
      case 0:
        return some_copied;

      case -1:
        if (
           (*__errno_location ()) 
                 == 
                    38 
                           || is_ENOTSUP (
                                          (*__errno_location ())
                                               ) || 
                                                    (*__errno_location ()) 
                                                          == 
                                                             22
            
           || 
              (*__errno_location ()) 
                    == 
                       9 
                             || 
                                (*__errno_location ()) 
                                      == 
                                         18 
                                               || 
                                                  (*__errno_location ()) 
                                                        == 
                                                           26
            
           || 
              (*__errno_location ()) 
                    == 
                       1
                            )
          return 0;
        error (0, 
                 (*__errno_location ())
                      , "%s", quotearg_n_style_colon (0, shell_escape_quoting_style, infile));
        return -1;
      }
}


int
main (int argc, char **argv)
{

  
 _Bool 
      have_read_stdin = 
                        0
                             ;

  struct stat stat_buf;


  
 _Bool 
      number = 
               0
                    ;
  
 _Bool 
      number_nonblank = 
                        0
                             ;
  
 _Bool 
      squeeze_blank = 
                      0
                           ;
  
 _Bool 
      show_ends = 
                  0
                       ;
  
 _Bool 
      show_nonprinting = 
                         0
                              ;
  
 _Bool 
      show_tabs = 
                  0
                       ;
  int file_open_mode = 
                      00
                              ;

  static struct option const long_options[] =
  {
    {"number-nonblank", 
                       0
                                  , 
                                    ((void *)0)
                                        , 'b'},
    {"number", 
              0
                         , 
                           ((void *)0)
                               , 'n'},
    {"squeeze-blank", 
                     0
                                , 
                                  ((void *)0)
                                      , 's'},
    {"show-nonprinting", 
                        0
                                   , 
                                     ((void *)0)
                                         , 'v'},
    {"show-ends", 
                 0
                            , 
                              ((void *)0)
                                  , 'E'},
    {"show-tabs", 
                 0
                            , 
                              ((void *)0)
                                  , 'T'},
    {"show-all", 
                0
                           , 
                             ((void *)0)
                                 , 'A'},
    {"help", 
    0
    , 
    ((void *)0)
    , GETOPT_HELP_CHAR},
    {"version", 
    0
    , 
    ((void *)0)
    , GETOPT_VERSION_CHAR},
    {
    ((void *)0)
        , 0, 
             ((void *)0)
                 , 0}
  };

  ;
  set_program_name (argv[0]);
  setlocale (
            6
                  , "");
  bindtextdomain ("coreutils", "/usr/local/share/locale");
  textdomain ("coreutils");





  atexit (close_stdout);



  int c;
  while ((c = getopt_long (argc, argv, "benstuvAET", long_options, 
                                                                  ((void *)0)
                                                                      ))
         != -1)
    {
      switch (c)
        {
        case 'b':
          number = 
                  1
                      ;
          number_nonblank = 
                           1
                               ;
          break;

        case 'e':
          show_ends = 
                     1
                         ;
          show_nonprinting = 
                            1
                                ;
          break;

        case 'n':
          number = 
                  1
                      ;
          break;

        case 's':
          squeeze_blank = 
                         1
                             ;
          break;

        case 't':
          show_tabs = 
                     1
                         ;
          show_nonprinting = 
                            1
                                ;
          break;

        case 'u':

          break;

        case 'v':
          show_nonprinting = 
                            1
                                ;
          break;

        case 'A':
          show_nonprinting = 
                            1
                                ;
          show_ends = 
                     1
                         ;
          show_tabs = 
                     1
                         ;
          break;

        case 'E':
          show_ends = 
                     1
                         ;
          break;

        case 'T':
          show_tabs = 
                     1
                         ;
          break;

        case GETOPT_HELP_CHAR: usage (
       0
       ); break;;

        case GETOPT_VERSION_CHAR: version_etc (
       stdout
       , "cat", "GNU coreutils", Version, ("Torbjorn Granlund"), ("Richard M. Stallman"), (char *) 
       ((void *)0)
       ); exit (
       0
       ); break;;

        default:
          usage (
                1
                            );
        }
    }



  if (fstat (
            1
                         , &stat_buf) < 0)
    ((!!sizeof (struct { _Static_assert (
   1
   , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), gettext (\"standard output\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
   1
   , 
   (*__errno_location ())
   , gettext ("standard output")), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
   1
   , 
   (*__errno_location ())
   , gettext ("standard output")), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))));


  idx_t outsize = io_blksize (stat_buf);


  dev_t out_dev = stat_buf.st_dev;
  ino_t out_ino = stat_buf.st_ino;


  
 _Bool 
      out_isreg = 
                  ((((
                  stat_buf.st_mode
                  )) & 0170000) == (0100000)) 
                                             != 0;

  if (! (number || show_ends || squeeze_blank))
    {
      file_open_mode |= 
                       0
                               ;
      xset_binary_mode (
                       1
                                    , 
                                      0
                                              );
    }



  infile = "-";
  int argind = optind;
  
 _Bool 
      ok = 
           1
               ;
  idx_t page_size = getpagesize ();

  do
    {
      if (argind < argc)
        infile = argv[argind];

      
     _Bool 
          reading_stdin = (strcmp (infile, "-") == 0);
      if (reading_stdin)
        {
          have_read_stdin = 
                           1
                               ;
          input_desc = 
                      0
                                  ;
          if (file_open_mode & 
                              0
                                      )
            xset_binary_mode (
                             0
                                         , 
                                           0
                                                   );
        }
      else
        {
          input_desc = open (infile, file_open_mode);
          if (input_desc < 0)
            {
              error (0, 
                       (*__errno_location ())
                            , "%s", quotearg_n_style_colon (0, shell_escape_quoting_style, infile));
              ok = 
                  0
                       ;
              continue;
            }
        }

      if (fstat (input_desc, &stat_buf) < 0)
        {
          error (0, 
                   (*__errno_location ())
                        , "%s", quotearg_n_style_colon (0, shell_escape_quoting_style, infile));
          ok = 
              0
                   ;
          goto contin;
        }


      idx_t insize = io_blksize (stat_buf);

      fdadvise (input_desc, 0, 0, FADVISE_SEQUENTIAL);





      if (out_isreg
          && stat_buf.st_dev == out_dev && stat_buf.st_ino == out_ino
          && lseek (input_desc, 0, 
                                  1
                                          ) < stat_buf.st_size)
        {
          error (0, 0, gettext ("%s: input file is output file"), quotearg_n_style_colon (0, shell_escape_quoting_style, infile));
          ok = 
              0
                   ;
          goto contin;
        }


      char *inbuf;





      if (! (number || show_ends || show_nonprinting
             || show_tabs || squeeze_blank))
        {
          int copy_cat_status =
            out_isreg && 
                        ((((
                        stat_buf.st_mode
                        )) & 0170000) == (0100000)) 
                                                   ? copy_cat () : 0;
          if (copy_cat_status != 0)
            {
              inbuf = 
                     ((void *)0)
                         ;
              ok &= 0 < copy_cat_status;
            }
          else
            {
              insize = 
                      (((
                      insize
                      )>(
                      outsize
                      ))?(
                      insize
                      ):(
                      outsize
                      ))
                                           ;
              inbuf = xalignalloc (page_size, insize);
              ok &= simple_cat (inbuf, insize);
            }
        }
      else
        {

          inbuf = xalignalloc (page_size, insize + 1);
          idx_t bufsize;
          if (__builtin_mul_overflow (insize, 4, &bufsize)
              || __builtin_add_overflow (bufsize, outsize, &bufsize)
              || __builtin_add_overflow (bufsize, 20 - 1, &bufsize))
            xalloc_die ();
          char *outbuf = xalignalloc (page_size, bufsize);

          ok &= cat (inbuf, insize, outbuf, outsize, show_nonprinting,
                     show_tabs, number, number_nonblank, show_ends,
                     squeeze_blank);

          alignfree (outbuf);
        }

      alignfree (inbuf);

    contin:
      if (!reading_stdin && close (input_desc) < 0)
        {
          error (0, 
                   (*__errno_location ())
                        , "%s", quotearg_n_style_colon (0, shell_escape_quoting_style, infile));
          ok = 
              0
                   ;
        }
    }
  while (++argind < argc);

  if (pending_cr)
    {
      if (full_write (
                     1
                                  , "\r", 1) != 1)
        ((!!sizeof (struct { _Static_assert (
       1
       , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), gettext (\"write error\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
       1
       , 
       (*__errno_location ())
       , gettext ("write error")), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
       1
       , 
       (*__errno_location ())
       , gettext ("write error")), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))));
    }

  if (have_read_stdin && close (
                               0
                                           ) < 0)
    ((!!sizeof (struct { _Static_assert (
   1
   , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), gettext (\"closing standard input\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
   1
   , 
   (*__errno_location ())
   , gettext ("closing standard input")), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
   1
   , 
   (*__errno_location ())
   , gettext ("closing standard input")), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))));

  return ok ? 
             0 
                          : 
                            1
                                        ;
}
