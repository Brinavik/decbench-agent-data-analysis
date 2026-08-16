       












       
       
       
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
       
       


_Bool 
    acl_errno_valid (int) __attribute__ ((__const__));
int file_has_acl (char const *, struct stat const *);
int qset_acl (char const *, int, mode_t);
int set_acl (char const *, int, mode_t);
int qcopy_acl (char const *, int, char const *, int, mode_t);
int copy_acl (char const *, int, char const *, int, mode_t);
int chmod_or_fchmod (char const *, int, mode_t);
       






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


       

       







enum backup_type
{

  no_backups,


  simple_backups,



  numbered_existing_backups,


  numbered_backups
};




extern char const *simple_backup_suffix;

void set_simple_backup_suffix (char const *);
char *backup_file_rename (int, char const *, enum backup_type)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)));
char *find_backup_file_name (int, char const *, enum backup_type)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__returns_nonnull__));
enum backup_type get_version (char const *context, char const *arg);
enum backup_type xget_version (char const *context, char const *arg);
size_t buffer_lcm (size_t, size_t, size_t) __attribute__ ((__const__));
       







enum canonicalize_mode_t
  {

    CAN_EXISTING = 0,


    CAN_ALL_BUT_LAST = 1,


    CAN_MISSING = 2,


    CAN_NOLINKS = 4
  };
typedef enum canonicalize_mode_t canonicalize_mode_t;
char *canonicalize_filename_mode (const char *, canonicalize_mode_t)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)));
       






struct hash_tuning
  {



    float shrink_threshold;
    float shrink_factor;
    float growth_threshold;
    float growth_factor;
    
   _Bool 
        is_n_buckets;
  };

typedef struct hash_tuning Hash_tuning;

struct hash_table;

typedef struct hash_table Hash_table;
extern size_t hash_get_n_buckets (const Hash_table *table)
       __attribute__ ((__pure__));


extern size_t hash_get_n_buckets_used (const Hash_table *table)
       __attribute__ ((__pure__));


extern size_t hash_get_n_entries (const Hash_table *table)
       __attribute__ ((__pure__));


extern size_t hash_get_max_bucket_length (const Hash_table *table)
       __attribute__ ((__pure__));



extern 
      _Bool 
           hash_table_ok (const Hash_table *table)
       __attribute__ ((__pure__));

extern void hash_print_statistics (const Hash_table *table, FILE *stream);



extern void *hash_lookup (const Hash_table *table, const void *entry);
extern void *hash_get_first (const Hash_table *table)
       __attribute__ ((__pure__));




extern void *hash_get_next (const Hash_table *table, const void *entry);




extern size_t hash_get_entries (const Hash_table *table, void **buffer,
                                size_t buffer_size);

typedef 
       _Bool 
            (*Hash_processor) (void *entry, void *processor_data);
extern size_t hash_do_for_each (const Hash_table *table,
                                Hash_processor processor, void *processor_data);







extern size_t hash_string (const char *string, size_t n_buckets)
       __attribute__ ((__pure__));

extern void hash_reset_tuning (Hash_tuning *tuning);

typedef size_t (*Hash_hasher) (const void *entry, size_t table_size);
typedef 
       _Bool 
            (*Hash_comparator) (const void *entry1, const void *entry2);
typedef void (*Hash_data_freer) (void *entry);





extern void hash_free (Hash_table *table);
[[__nodiscard__]]
extern Hash_table *hash_initialize (size_t candidate,
                                    const Hash_tuning *tuning,
                                    Hash_hasher hasher,
                                    Hash_comparator comparator,
                                    Hash_data_freer data_freer)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (hash_free, 1)));



[[__nodiscard__]]
extern Hash_table *hash_xinitialize (size_t candidate,
                                     const Hash_tuning *tuning,
                                     Hash_hasher hasher,
                                     Hash_comparator comparator,
                                     Hash_data_freer data_freer)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (hash_free, 1)))
  __attribute__ ((__returns_nonnull__));




extern void hash_clear (Hash_table *table);
[[__nodiscard__]]
extern 
      _Bool 
           hash_rehash (Hash_table *table, size_t candidate);






[[__nodiscard__]]
extern void *hash_insert (Hash_table *table, const void *entry);



extern void *hash_xinsert (Hash_table *table, const void *entry);
extern int hash_insert_if_absent (Hash_table *table, const void *entry,
                                  const void **matched_ent);




extern void *hash_remove (Hash_table *table, const void *entry);



[[__deprecated__]]
extern void *hash_delete (Hash_table *table, const void *entry);

struct selabel_handle;


enum Sparse_type
{
  SPARSE_UNUSED,


  SPARSE_NEVER,




  SPARSE_AUTO,






  SPARSE_ALWAYS
};


enum Reflink_type
{

  REFLINK_NEVER,


  REFLINK_AUTO,


  REFLINK_ALWAYS
};


enum Interactive
{
  I_ALWAYS_YES = 1,
  I_ALWAYS_NO,
  I_ASK_USER,
  I_UNSPECIFIED
};


enum Dereference_symlink
{
  DEREF_UNDEFINED = 1,


  DEREF_NEVER,



  DEREF_COMMAND_LINE_ARGUMENTS,


  DEREF_ALWAYS
};
struct cp_options
{
  enum backup_type backup_type;


  enum Dereference_symlink dereference;




  enum Interactive interactive;


  enum Sparse_type sparse_mode;



  mode_t mode;



  
 _Bool 
      copy_as_regular;



  
 _Bool 
      unlink_dest_before_opening;






  
 _Bool 
      unlink_dest_after_failed_open;



  
 _Bool 
      hard_link;



  
 _Bool 
      move_mode;


  
 _Bool 
      install_mode;



  
 _Bool 
      chown_privileges;






  
 _Bool 
      owner_privileges;



  
 _Bool 
      one_file_system;



  
 _Bool 
      preserve_ownership;
  
 _Bool 
      preserve_mode;
  
 _Bool 
      preserve_timestamps;
  
 _Bool 
      explicit_no_preserve_mode;


  struct selabel_handle *set_security_context;
  
 _Bool 
      preserve_links;



  
 _Bool 
      data_copy_required;





  
 _Bool 
      require_preserve;



  
 _Bool 
      preserve_security_context;
  
 _Bool 
      require_preserve_context;



  
 _Bool 
      preserve_xattr;
  
 _Bool 
      require_preserve_xattr;
  
 _Bool 
      reduce_diagnostics;



  
 _Bool 
      recursive;



  
 _Bool 
      set_mode;



  
 _Bool 
      symbolic_link;



  
 _Bool 
      update;


  
 _Bool 
      verbose;


  
 _Bool 
      stdin_tty;




  
 _Bool 
      open_dangling_dest_symlink;



  
 _Bool 
      last_file;




  int rename_errno;


  enum Reflink_type reflink_mode;
  Hash_table *dest_info;


  Hash_table *src_info;
};

_Bool 
    copy (char const *src_name, char const *dst_name,
           int dst_dirfd, char const *dst_relname,
           int nonexistent_dst, const struct cp_options *options,
           
          _Bool 
               *copy_into_self, 
                                _Bool 
                                     *rename_succeeded)
  __attribute__ ((__nonnull__ (1, 2, 4, 6, 7)));

extern 
      _Bool 
           set_process_security_ctx (char const *src_name,
                                      char const *dst_name,
                                      mode_t mode, 
                                                  _Bool 
                                                       new_dst,
                                      const struct cp_options *x)
  __attribute__ ((__nonnull__ ));

extern 
      _Bool 
           set_file_security_ctx (char const *dst_name,
                                   
                                  _Bool 
                                       recurse, const struct cp_options *x)
  __attribute__ ((__nonnull__ ));

void dest_info_init (struct cp_options *) __attribute__ ((__nonnull__ ));
void dest_info_free (struct cp_options *) __attribute__ ((__nonnull__ ));
void src_info_init (struct cp_options *) __attribute__ ((__nonnull__ ));
void src_info_free (struct cp_options *) __attribute__ ((__nonnull__ ));

void cp_options_default (struct cp_options *) __attribute__ ((__nonnull__ ));

_Bool 
    chown_failure_ok (struct cp_options const *)
  __attribute__ ((__nonnull__ )) __attribute__ ((__pure__));
mode_t cached_umask (void);
void hash_init (void);
void forget_created (ino_t ino, dev_t dev);
char *remember_copied (char const *node, ino_t ino, dev_t dev)
  __attribute__ ((__nonnull__ ));
char *src_to_dest_lookup (ino_t ino, dev_t dev);
       
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
       
       

int open_safer (char const *, int, ...);
int creat_safer (char const *, mode_t);


int openat_safer (int, char const *, int, ...);
       
       



extern void record_file (Hash_table *ht, char const *file,
                         struct stat const *stats)

  __attribute__ ((__nonnull__ (2, 3)))

;

extern 
      _Bool 
           seen_file (Hash_table const *ht, char const *file,
                       struct stat const *stats);
       
       
extern void strmode (mode_t mode, char *str);


extern void filemodestring (struct stat const *statp, char *str);
       


char *file_name_concat (char const *dir, char const *base,
                        char **base_in_result)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__returns_nonnull__));


char *mfile_name_concat (char const *dir, char const *base,
                         char **base_in_result)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)));
extern int force_linkat (int, char const *, int, char const *, int, 
                                                                   _Bool
                                                                       , int)
  __attribute__ ((__nonnull__ ));
extern int force_symlinkat (char const *, int, char const *, 
                                                            _Bool
                                                                , int)
  __attribute__ ((__nonnull__ ));
extern size_t full_write (int fd, const void *buf, size_t count);

       
       



struct F_triple
{
  char *name;
  ino_t st_ino;
  dev_t st_dev;
};



extern size_t triple_hash (void const *x, size_t table_size) __attribute__ ((__pure__));
extern 
      _Bool 
           triple_compare_ino_str (void const *x, void const *y)
  __attribute__ ((__pure__));
extern void triple_free (void *x);


extern size_t triple_hash_no_name (void const *x, size_t table_size)
  __attribute__ ((__pure__));
extern 
      _Bool 
           triple_compare (void const *x, void const *y);
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



extern struct quoting_options quote_quoting_options;





char const *quote_n_mem (int n, char const *arg, size_t argsize);




char const *quote_mem (char const *arg, size_t argsize);



char const *quote_n (int n, char const *arg);



char const *quote (char const *arg);
       






extern int renameatu (int, char const *, int, char const *, unsigned int);

_Bool 
    same_name (const char *source, const char *dest);

_Bool 
    same_nameat (int, char const *, int, char const *);
       

enum savedir_option
  {
    SAVEDIR_SORT_NONE,
    SAVEDIR_SORT_NAME,

    SAVEDIR_SORT_INODE,
    SAVEDIR_SORT_FASTREAD = SAVEDIR_SORT_INODE



  };

char *streamsavedir (DIR *, enum savedir_option)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)));
char *savedir (char const *, enum savedir_option)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)));

       
       





inline long int __attribute__ ((__pure__))
get_stat_atime_ns (struct stat const *st)
{

  return ((st)->st_atim).tv_nsec;





}


inline long int __attribute__ ((__pure__))
get_stat_ctime_ns (struct stat const *st)
{

  return ((st)->st_ctim).tv_nsec;





}


inline long int __attribute__ ((__pure__))
get_stat_mtime_ns (struct stat const *st)
{

  return ((st)->st_mtim).tv_nsec;





}


inline long int __attribute__ ((__pure__))
get_stat_birthtime_ns ([[__maybe_unused__]] struct stat const *st)
{





  return 0;

}


inline struct timespec __attribute__ ((__pure__))
get_stat_atime (struct stat const *st)
{

  return ((st)->st_atim);






}


inline struct timespec __attribute__ ((__pure__))
get_stat_ctime (struct stat const *st)
{

  return ((st)->st_ctim);






}


inline struct timespec __attribute__ ((__pure__))
get_stat_mtime (struct stat const *st)
{

  return ((st)->st_mtim);






}



inline struct timespec __attribute__ ((__pure__))
get_stat_birthtime ([[__maybe_unused__]] struct stat const *st)
{
  struct timespec t;
  t.tv_sec = -1;
  t.tv_nsec = -1;
  return t;
}






inline int
stat_time_normalize (int result, [[__maybe_unused__]] struct stat *st)
{
  return result;
}






       
       


enum
{



  UTIMECMP_TRUNCATE_SOURCE = 1
};

int utimecmp (char const *, struct stat const *, struct stat const *, int);
int utimecmpat (int, char const *, struct stat const *, struct stat const *,
                int);
       
int fdutimens (int, char const *, struct timespec const [2]);
int utimens (char const *, struct timespec const [2]);
int lutimens (char const *, struct timespec const [2]);


       
       









int fdutimensat (int fd, int dir, char const *name, struct timespec const [2],
                 int atflag);


inline int
lutimensat (int dir, char const *file, struct timespec const times[2])
{
  return utimensat (dir, file, times, 
                                     0x100
                                                        );
}



_Bool 
    can_write_any_file (void);
       

extern char *areadlink (char const *filename)
  __attribute__ ((__malloc__ (free, 1)));
extern char *areadlink_with_size (char const *filename, size_t size_hint)
  __attribute__ ((__malloc__ (free, 1)));


extern char *areadlinkat (int fd, char const *filename)
  __attribute__ ((__malloc__ (free, 1)));



extern char *areadlinkat_with_size (int fd, char const *filename,
                                    size_t size_hint)
  __attribute__ ((__malloc__ (free, 1)));

_Bool 
    yesno (void);
struct selabel_handle;



static inline 
             _Bool

ignorable_ctx_err (int err)
{
  return err == 
               95 
                       || err == 
                                 61
                                        ;
}



extern 
      _Bool

restorecon (struct selabel_handle *selabel_handle,
            char const *path, 
                             _Bool 
                                  recurse);
extern int
defaultcon (struct selabel_handle *selabel_handle,
            char const *path, mode_t mode);







       

extern void verror (int __status, int __errnum, const char *__format,
                    va_list __args)
     __attribute__ ((__format__ (
    __gnu_printf__
    , 3, 0)));
extern void verror_at_line (int __status, int __errnum, const char *__fname,
                            unsigned int __lineno, const char *__format,
                            va_list __args)
     __attribute__ ((__format__ (
    __gnu_printf__
    , 5, 0)));

struct dir_list
{
  struct dir_list *parent;
  ino_t ino;
  dev_t dev;
};




static 
      _Bool 
           copy_internal (char const *src_name, char const *dst_name,
                           int dst_dirfd, char const *dst_relname,
                           int nonexistent_dst, struct stat const *parent,
                           struct dir_list *ancestors,
                           const struct cp_options *x,
                           
                          _Bool 
                               command_line_arg,
                           
                          _Bool 
                               *first_dir_created_per_command_line_arg,
                           
                          _Bool 
                               *copy_into_self,
                           
                          _Bool 
                               *rename_succeeded);
static 
      _Bool 
           owner_failure_ok (struct cp_options const *x);



static char const *top_level_src_name;
static char const *top_level_dst_name;
static int
follow_fstatat (int dirfd, char const *filename, struct stat *st, int flags)
{
  int result = fstatat (dirfd, filename, st, flags);

  if (
     0 
                         && result == 0 && !(flags & 
                                                     0x100
                                                                        )
      && 
        ((((
        st->st_mode
        )) & 0170000) == (0020000))
                             )
    {
      static dev_t stdin_rdev;
      static signed char stdin_rdev_status;
      if (stdin_rdev_status == 0)
        {
          struct stat stdin_st;
          if (stat ("/dev/stdin", &stdin_st) == 0 && 
                                                    ((((
                                                    stdin_st.st_mode
                                                    )) & 0170000) == (0020000))
              
             && 
                gnu_dev_minor (
                stdin_st.st_rdev
                ) 
                                         == 
                                            0
                                                        )
            {
              stdin_rdev = stdin_st.st_rdev;
              stdin_rdev_status = 1;
            }
          else
            stdin_rdev_status = -1;
        }
      if (0 < stdin_rdev_status && 
                                  gnu_dev_major (
                                  stdin_rdev
                                  ) 
                                                     == 
                                                        gnu_dev_major (
                                                        st->st_rdev
                                                        )
                                                                           )
        result = fstat (
                       gnu_dev_minor (
                       st->st_rdev
                       )
                                          , st);
    }

  return result;
}





static int
punch_hole (int fd, off_t offset, off_t length)
{
  int ret = 0;



  ret = fallocate (fd, 
                      0x02 
                                           | 
                                             0x01
                                                                ,
                   offset, length);
  if (ret < 0 && (is_ENOTSUP (
                             (*__errno_location ())
                                  ) || 
                                       (*__errno_location ()) 
                                             == 
                                                38
                                                      ))
    ret = 0;


  return ret;
}




static 
      _Bool

create_hole (int fd, char const *name, 
                                      _Bool 
                                           punch_holes, off_t size)
{
  off_t file_end = lseek (fd, size, 
                                   1
                                           );

  if (file_end < 0)
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("cannot lseek %s"), quotearg_style (shell_escape_always_quoting_style, name));
      return 
            0
                 ;
    }





  if (punch_holes && punch_hole (fd, file_end - size, size) < 0)
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("error deallocating %s"), quotearg_style (shell_escape_always_quoting_style, name));
      return 
            0
                 ;
    }

  return 
        1
            ;
}
static 
      _Bool

sparse_copy (int src_fd, int dest_fd, char **abuf, size_t buf_size,
             size_t hole_size, 
                              _Bool 
                                   punch_holes, 
                                                _Bool 
                                                     allow_reflink,
             char const *src_name, char const *dst_name,
             uintmax_t max_n_read, off_t *total_n_read,
             
            _Bool 
                 *last_write_made_hole)
{
  *last_write_made_hole = 
                         0
                              ;
  *total_n_read = 0;



  if (!hole_size && allow_reflink)
    while (max_n_read)
      {



        ssize_t copy_max = 
                          (((0x7fffffffffffffffL)<((18446744073709551615UL)))?(0x7fffffffffffffffL):((18446744073709551615UL))) 
                                                    >> 30 << 30;
        ssize_t n_copied = copy_file_range (src_fd, 
                                                   ((void *)0)
                                                       , dest_fd, 
                                                                  ((void *)0)
                                                                      ,
                                            
                                           (((
                                           max_n_read
                                           )<(
                                           copy_max
                                           ))?(
                                           max_n_read
                                           ):(
                                           copy_max
                                           ))
                                                                     , 0);
        if (n_copied == 0)
          {




            if (*total_n_read == 0)
              break;
            return 
                  1
                      ;
          }
        if (n_copied < 0)
          {
            if (
               (*__errno_location ()) 
                     == 
                        38 
                               || is_ENOTSUP (
                                              (*__errno_location ())
                                                   )
                || 
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
                                                    )
              break;






            if (
               (*__errno_location ()) 
                     == 
                        1 
                              && *total_n_read == 0)
              break;

            if (
               (*__errno_location ()) 
                     == 
                        4
                             )
              n_copied = 0;
            else
              {
                error (0, 
                         (*__errno_location ())
                              , gettext ("error copying %s to %s"),
                       quotearg_n_style (0, shell_escape_always_quoting_style, src_name), quotearg_n_style (1, shell_escape_always_quoting_style, dst_name));
                return 
                      0
                           ;
              }
          }
        max_n_read -= n_copied;
        *total_n_read += n_copied;
      }

  
 _Bool 
      make_hole = 
                  0
                       ;
  off_t psize = 0;

  while (max_n_read)
    {
      if (!*abuf)
        *abuf = xalignalloc (getpagesize (), buf_size);
      char *buf = *abuf;
      ssize_t n_read = read (src_fd, buf, 
                                         (((
                                         max_n_read
                                         )<(
                                         buf_size
                                         ))?(
                                         max_n_read
                                         ):(
                                         buf_size
                                         ))
                                                                   );
      if (n_read < 0)
        {
          if (
             (*__errno_location ()) 
                   == 
                      4
                           )
            continue;
          error (0, 
                   (*__errno_location ())
                        , gettext ("error reading %s"), quotearg_style (shell_escape_always_quoting_style, src_name));
          return 
                0
                     ;
        }
      if (n_read == 0)
        break;
      max_n_read -= n_read;
      *total_n_read += n_read;


      size_t csize = hole_size ? hole_size : buf_size;
      char *cbuf = buf;
      char *pbuf = buf;

      while (n_read)
        {
          
         _Bool 
              prev_hole = make_hole;
          csize = 
                 (((
                 csize
                 )<(
                 n_read
                 ))?(
                 csize
                 ):(
                 n_read
                 ))
                                    ;

          if (hole_size && csize)
            make_hole = is_nul (cbuf, csize);

          
         _Bool 
              transition = (make_hole != prev_hole) && psize;
          
         _Bool 
              last_chunk = (n_read == csize && ! make_hole) || ! csize;

          if (transition || last_chunk)
            {
              if (! transition)
                psize += csize;

              if (! prev_hole)
                {
                  if (full_write (dest_fd, pbuf, psize) != psize)
                    {
                      error (0, 
                               (*__errno_location ())
                                    , gettext ("error writing %s"),
                             quotearg_style (shell_escape_always_quoting_style, dst_name));
                      return 
                            0
                                 ;
                    }
                }
              else
                {
                  if (! create_hole (dest_fd, dst_name, punch_holes, psize))
                    return 
                          0
                               ;
                }

              pbuf = cbuf;
              psize = csize;

              if (last_chunk)
                {
                  if (! csize)
                    n_read = 0;

                  if (transition)
                    csize = 0;
                  else
                    psize = 0;
                }
            }
          else
            {
              if (__builtin_add_overflow (psize, csize, &psize))
                {
                  error (0, 0, gettext ("overflow reading %s"), quotearg_style (shell_escape_always_quoting_style, src_name));
                  return 
                        0
                             ;
                }
            }

          n_read -= csize;
          cbuf += csize;
        }

      *last_write_made_hole = make_hole;





    }



  if (make_hole && ! create_hole (dest_fd, dst_name, punch_holes, psize))
    return 
          0
               ;
  else
    return 
          1
              ;
}



static inline int
clone_file (int dest_fd, int src_fd)
{

  return ioctl (dest_fd, 
                        (((1U) << (((0 +8)+8)+14)) | (((0x94)) << (0 +8)) | (((9)) << 0) | ((((sizeof(int)))) << ((0 +8)+8)))
                               , src_fd);






}



static 
      _Bool

write_zeros (int fd, off_t n_bytes)
{
  static char *zeros;
  static size_t nz = IO_BUFSIZE;




  if (zeros == 
              ((void *)0)
                  )
    {
      static char fallback[1024];
      zeros = calloc (nz, 1);
      if (zeros == 
                  ((void *)0)
                      )
        {
          zeros = fallback;
          nz = sizeof fallback;
        }
    }

  while (n_bytes)
    {
      size_t n = 
                (((
                nz
                )<(
                n_bytes
                ))?(
                nz
                ):(
                n_bytes
                ))
                                 ;
      if ((full_write (fd, zeros, n)) != n)
        return 
              0
                   ;
      n_bytes -= n;
    }

  return 
        1
            ;
}
static 
      _Bool

lseek_copy (int src_fd, int dest_fd, char **abuf, size_t buf_size,
            size_t hole_size, off_t ext_start, off_t src_total_size,
            enum Sparse_type sparse_mode,
            
           _Bool 
                allow_reflink,
            char const *src_name, char const *dst_name)
{
  off_t last_ext_start = 0;
  off_t last_ext_len = 0;
  off_t dest_pos = 0;
  
 _Bool 
      wrote_hole_at_eof = 
                          1
                              ;

  while (0 <= ext_start)
    {
      off_t ext_end = lseek (src_fd, ext_start, 
                                               4
                                                        );
      if (ext_end < 0)
        {
          if (
             (*__errno_location ()) 
                   != 
                      6
                           )
            goto cannot_lseek;
          ext_end = src_total_size;
          if (ext_end <= ext_start)
            {

              src_total_size = lseek (src_fd, 0, 
                                                2
                                                        );
              if (src_total_size < 0)
                goto cannot_lseek;


              if (src_total_size <= ext_start)
                break;

              ext_end = src_total_size;
            }
        }

      if (src_total_size < ext_end)
        src_total_size = ext_end;

      if (lseek (src_fd, ext_start, 
                                   0
                                           ) < 0)
        goto cannot_lseek;

      wrote_hole_at_eof = 
                         0
                              ;
      off_t ext_hole_size = ext_start - last_ext_start - last_ext_len;

      if (ext_hole_size)
        {
          if (sparse_mode != SPARSE_NEVER)
            {
              if (! create_hole (dest_fd, dst_name,
                                 sparse_mode == SPARSE_ALWAYS,
                                 ext_hole_size))
                return 
                      0
                           ;
              wrote_hole_at_eof = 
                                 1
                                     ;
            }
          else
            {



              if (! write_zeros (dest_fd, ext_hole_size))
                {
                  error (0, 
                           (*__errno_location ())
                                , gettext ("%s: write failed"),
                         quotearg_n_style_colon (0, shell_escape_quoting_style, dst_name));
                  return 
                        0
                             ;
                }
            }
        }

      off_t ext_len = ext_end - ext_start;
      last_ext_start = ext_start;
      last_ext_len = ext_len;




      off_t n_read;
      
     _Bool 
          read_hole;
      if ( ! sparse_copy (src_fd, dest_fd, abuf, buf_size,
                          sparse_mode == SPARSE_NEVER ? 0 : hole_size,
                          
                         1
                             , allow_reflink, src_name, dst_name,
                          ext_len, &n_read, &read_hole))
        return 
              0
                   ;

      dest_pos = ext_start + n_read;
      if (n_read)
        wrote_hole_at_eof = read_hole;
      if (n_read < ext_len)
        {

          src_total_size = dest_pos;
          break;
        }

      ext_start = lseek (src_fd, dest_pos, 
                                          3
                                                   );
      if (ext_start < 0 && 
                          (*__errno_location ()) 
                                != 
                                   6
                                        )
        goto cannot_lseek;
    }
  if ((dest_pos < src_total_size || wrote_hole_at_eof)
      && ! (sparse_mode == SPARSE_NEVER
            ? write_zeros (dest_fd, src_total_size - dest_pos)
            : ftruncate (dest_fd, src_total_size) == 0))
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("failed to extend %s"), quotearg_style (shell_escape_always_quoting_style, dst_name));
      return 
            0
                 ;
    }

  if (sparse_mode == SPARSE_ALWAYS && dest_pos < src_total_size
      && punch_hole (dest_fd, dest_pos, src_total_size - dest_pos) < 0)
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("error deallocating %s"), quotearg_style (shell_escape_always_quoting_style, dst_name));
      return 
            0
                 ;
    }

  return 
        1
            ;

 cannot_lseek:
  error (0, 
           (*__errno_location ())
                , gettext ("cannot lseek %s"), quotearg_style (shell_escape_always_quoting_style, src_name));
  return 
        0
             ;
}







__attribute__ ((__pure__))
static 
      _Bool

is_ancestor (const struct stat *sb, const struct dir_list *ancestors)
{
  while (ancestors != 0)
    {
      if (ancestors->ino == sb->st_ino && ancestors->dev == sb->st_dev)
        return 
              1
                  ;
      ancestors = ancestors->parent;
    }
  return 
        0
             ;
}

static 
      _Bool

errno_unsupported (int err)
{
  return err == 
               95 
                       || err == 
                                 61
                                        ;
}


__attribute__ ((__format__ (printf, 2, 3)))
static void
copy_attr_error ([[__maybe_unused__]] struct error_context *ctx,
                 char const *fmt, ...)
{
  if (!errno_unsupported (
                         (*__errno_location ())
                              ))
    {
      int err = 
               (*__errno_location ())
                    ;
      va_list ap;


      
     __builtin_va_start(
     ap
     ,
     fmt
     )
                       ;
      verror (0, err, fmt, ap);
      
     __builtin_va_end(
     ap
     )
                ;
    }
}

__attribute__ ((__format__ (printf, 2, 3)))
static void
copy_attr_allerror ([[__maybe_unused__]] struct error_context *ctx,
                    char const *fmt, ...)
{
  int err = 
           (*__errno_location ())
                ;
  va_list ap;


  
 __builtin_va_start(
 ap
 ,
 fmt
 )
                   ;
  verror (0, err, fmt, ap);
  
 __builtin_va_end(
 ap
 )
            ;
}

static char const *
copy_attr_quote ([[__maybe_unused__]] struct error_context *ctx, char const *str)
{
  return quotearg_style (shell_escape_always_quoting_style, str);
}

static void
copy_attr_free ([[__maybe_unused__]] struct error_context *ctx,
                [[__maybe_unused__]] char const *str)
{
}






static int
check_selinux_attr (char const *name, struct error_context *ctx)
{
  return strncmp (name, "" "security.selinux" "", sizeof ("security.selinux") - 1)
         && attr_copy_check_permissions (name, ctx);
}




static 
      _Bool

copy_attr (char const *src_path, int src_fd,
           char const *dst_path, int dst_fd, struct cp_options const *x)
{
  
 _Bool 
      all_errors = (!x->data_copy_required || x->require_preserve_xattr);
  
 _Bool 
      some_errors = (!all_errors && !x->reduce_diagnostics);
  int (*check) (char const *, struct error_context *)
    = (x->preserve_security_context || x->set_security_context
       ? check_selinux_attr : 
                             ((void *)0)
                                 );



#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsuggest-attribute=format"

  struct error_context *ctx
    = (all_errors || some_errors
       ? (&(struct error_context) {
           .error = all_errors ? copy_attr_allerror : copy_attr_error,
           .quote = copy_attr_quote,
           .quote_free = copy_attr_free
         })
       : 
        ((void *)0)
            );

#pragma GCC diagnostic pop


  return ! (0 <= src_fd && 0 <= dst_fd
            ? attr_copy_fd (src_path, src_fd, dst_path, dst_fd, check, ctx)
            : attr_copy_file (src_path, dst_path, check, ctx));
}
static 
      _Bool

copy_dir (char const *src_name_in, char const *dst_name_in,
          int dst_dirfd, char const *dst_relname_in, 
                                                    _Bool 
                                                         new_dst,
          const struct stat *src_sb, struct dir_list *ancestors,
          const struct cp_options *x,
          
         _Bool 
              *first_dir_created_per_command_line_arg,
          
         _Bool 
              *copy_into_self)
{
  char *name_space;
  char *namep;
  struct cp_options non_command_line_options = *x;
  
 _Bool 
      ok = 
           1
               ;

  name_space = savedir (src_name_in, SAVEDIR_SORT_FASTREAD);
  if (name_space == 
                   ((void *)0)
                       )
    {


      error (0, 
               (*__errno_location ())
                    , gettext ("cannot access %s"), quotearg_style (shell_escape_always_quoting_style, src_name_in));
      return 
            0
                 ;
    }



  if (x->dereference == DEREF_COMMAND_LINE_ARGUMENTS)
    non_command_line_options.dereference = DEREF_NEVER;

  
 _Bool 
      new_first_dir_created = 
                              0
                                   ;
  namep = name_space;
  while (*namep != '\0')
    {
      
     _Bool 
          local_copy_into_self;
      char *src_name = file_name_concat (src_name_in, namep, 
                                                            ((void *)0)
                                                                );
      char *dst_name = file_name_concat (dst_name_in, namep, 
                                                            ((void *)0)
                                                                );
      
     _Bool 
          first_dir_created = *first_dir_created_per_command_line_arg;
      
     _Bool 
          rename_succeeded;

      ok &= copy_internal (src_name, dst_name, dst_dirfd,
                           dst_name + (dst_relname_in - dst_name_in),
                           new_dst, src_sb,
                           ancestors, &non_command_line_options, 
                                                                0
                                                                     ,
                           &first_dir_created,
                           &local_copy_into_self, &rename_succeeded);
      *copy_into_self |= local_copy_into_self;

      free (dst_name);
      free (src_name);




      if (local_copy_into_self)
        break;

      new_first_dir_created |= first_dir_created;
      namep += strlen (namep) + 1;
    }
  free (name_space);
  *first_dir_created_per_command_line_arg = new_first_dir_created;

  return ok;
}
static int
set_owner (const struct cp_options *x, char const *dst_name,
           int dst_dirfd, char const *dst_relname, int dest_desc,
           struct stat const *src_sb, 
                                     _Bool 
                                          new_dst,
           struct stat const *dst_sb)
{
  uid_t uid = src_sb->st_uid;
  gid_t gid = src_sb->st_gid;







  if (!new_dst && (x->preserve_mode || x->move_mode || x->set_mode))
    {
      mode_t old_mode = dst_sb->st_mode;
      mode_t new_mode =
        (x->preserve_mode || x->move_mode ? src_sb->st_mode : x->mode);
      mode_t restrictive_temp_mode = old_mode & new_mode & 
                                                          (0400|0200|0100)
                                                                 ;

      if ((0
           || (old_mode & (
                         04000 
                         | 
                         02000 
                         | 
                         01000 
                         | 
                         (0400|0200|0100) 
                         | 
                         ((0400|0200|0100) >> 3) 
                         | 
                         (((0400|0200|0100) >> 3) >> 3)
                         )
               & (~new_mode | 
                             04000 
                                     | 
                                       02000 
                                               | 
                                                 01000
                                                        )))
          && qset_acl (dst_name, dest_desc, restrictive_temp_mode) != 0)
        {
          if (! owner_failure_ok (x))
            error (0, 
                     (*__errno_location ())
                          , gettext ("clearing permissions for %s"),
                   quotearg_style (shell_escape_always_quoting_style, dst_name));
          return -x->require_preserve;
        }
    }

  if (1 && dest_desc != -1)
    {
      if (fchown (dest_desc, uid, gid) == 0)
        return 1;
      if (
         (*__errno_location ()) 
               == 
                  1 
                        || 
                           (*__errno_location ()) 
                                 == 
                                    22
                                          )
        {


          int saved_errno = 
                           (*__errno_location ())
                                ;
          (__extension__ ({ __typeof__ (fchown (dest_desc, -1, gid)) __x = (fchown (dest_desc, -1, gid)); (void) __x; }));
          
         (*__errno_location ()) 
               = saved_errno;
        }
    }
  else
    {
      if (lchownat (dst_dirfd, dst_relname, uid, gid) == 0)
        return 1;
      if (
         (*__errno_location ()) 
               == 
                  1 
                        || 
                           (*__errno_location ()) 
                                 == 
                                    22
                                          )
        {


          int saved_errno = 
                           (*__errno_location ())
                                ;
          (__extension__ ({ __typeof__ (lchownat (dst_dirfd, dst_relname, -1, gid)) __x = (lchownat (dst_dirfd, dst_relname, -1, gid)); (void) __x; }));
          
         (*__errno_location ()) 
               = saved_errno;
        }
    }

  if (! chown_failure_ok (x))
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("failed to preserve ownership for %s"),
             quotearg_style (shell_escape_always_quoting_style, dst_name));
      if (x->require_preserve)
        return -1;
    }

  return 0;
}






static void
set_author (char const *dst_name, int dest_desc, const struct stat *src_sb)
{
  (void) dst_name;
  (void) dest_desc;
  (void) src_sb;

}

_Bool

set_process_security_ctx (char const *src_name, char const *dst_name,
                          mode_t mode, 
                                      _Bool 
                                           new_dst, const struct cp_options *x)
{
  if (x->preserve_security_context)
    {

      
     _Bool 
          all_errors = !x->data_copy_required || x->require_preserve_context;
      
     _Bool 
          some_errors = !all_errors && !x->reduce_diagnostics;
      char *con;

      if (0 <= rpl_lgetfilecon (src_name, &con))
        {
          if (setfscreatecon (con) < 0)
            {
              if (all_errors || (some_errors && !errno_unsupported (
                                                                   (*__errno_location ())
                                                                        )))
                error (0, 
                         (*__errno_location ())
                              ,
                       gettext ("failed to set default file creation context to %s"),
                       quote (con));
              if (x->require_preserve_context)
                {
                  freecon (con);
                  return 
                        0
                             ;
                }
            }
          freecon (con);
        }
      else
        {
          if (all_errors || (some_errors && !errno_unsupported (
                                                               (*__errno_location ())
                                                                    )))
            {
              error (0, 
                       (*__errno_location ())
                            ,
                     gettext ("failed to get security context of %s"),
                     quotearg_style (shell_escape_always_quoting_style, src_name));
            }
          if (x->require_preserve_context)
            return 
                  0
                       ;
        }
    }
  else if (x->set_security_context)
    {


      if (new_dst && defaultcon (x->set_security_context, dst_name, mode) < 0
          && ! ignorable_ctx_err (
                                 (*__errno_location ())
                                      ))
        {
          error (0, 
                   (*__errno_location ())
                        ,
                 gettext ("failed to set default file creation context for %s"),
                 quotearg_style (shell_escape_always_quoting_style, dst_name));
        }
    }

  return 
        1
            ;
}

_Bool

set_file_security_ctx (char const *dst_name,
                       
                      _Bool 
                           recurse, const struct cp_options *x)
{
  
 _Bool 
      all_errors = (!x->data_copy_required
                     || x->require_preserve_context);
  
 _Bool 
      some_errors = !all_errors && !x->reduce_diagnostics;

  if (! restorecon (x->set_security_context, dst_name, recurse))
    {
      if (all_errors || (some_errors && !errno_unsupported (
                                                           (*__errno_location ())
                                                                )))
        error (0, 
                 (*__errno_location ())
                      , gettext ("failed to set the security context of %s"),
               quotearg_n_style (0, shell_escape_always_quoting_style, dst_name));
      return 
            0
                 ;
    }

  return 
        1
            ;
}





static int
fchmod_or_lchmod (int desc, int dirfd, char const *name, mode_t mode)
{

  if (0 <= desc)
    return fchmod (desc, mode);

  return lchmodat (dirfd, name, mode);
}






enum scantype
  {

   ERROR_SCANTYPE,


   PLAIN_SCANTYPE,



   ZERO_SCANTYPE,


   LSEEK_SCANTYPE,
  };


union scan_inference
{


  off_t ext_start;
};



static enum scantype
infer_scantype (int fd, struct stat const *sb,
                union scan_inference *scan_inference)
{
  if (! (1
         && 
           ((((
           sb->st_mode
           )) & 0170000) == (0100000))
         
        && ((*sb).st_blocks) < sb->st_size / 
                                            512
                                                         ))
    return PLAIN_SCANTYPE;


  scan_inference->ext_start = lseek (fd, 0, 
                                           3
                                                    );
  if (0 <= scan_inference->ext_start || 
                                       (*__errno_location ()) 
                                             == 
                                                6
                                                     )
    return LSEEK_SCANTYPE;
  else if (
          (*__errno_location ()) 
                != 
                   22 
                          && !is_ENOTSUP (
                                          (*__errno_location ())
                                               ))
    return ERROR_SCANTYPE;


  return ZERO_SCANTYPE;
}
static 
      _Bool

copy_reg (char const *src_name, char const *dst_name,
          int dst_dirfd, char const *dst_relname,
          const struct cp_options *x,
          mode_t dst_mode, mode_t omitted_permissions, 
                                                      _Bool 
                                                           *new_dst,
          struct stat const *src_sb)
{
  char *buf = 
             ((void *)0)
                 ;
  int dest_desc;
  int dest_errno;
  int source_desc;
  mode_t src_mode = src_sb->st_mode;
  mode_t extra_permissions;
  struct stat sb;
  struct stat src_open_sb;
  union scan_inference scan_inference;
  
 _Bool 
      return_val = 
                   1
                       ;
  
 _Bool 
      data_copy_required = x->data_copy_required;
  
 _Bool 
      preserve_xattr = 1 & x->preserve_xattr;

  source_desc = open_safer (src_name,
                      (
                      00 
                               | 
                                 0
                       
                      | (x->dereference == DEREF_NEVER ? 
                                                         0400000 
                                                                    : 0)));
  if (source_desc < 0)
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("cannot open %s for reading"), quotearg_style (shell_escape_always_quoting_style, src_name));
      return 
            0
                 ;
    }

  if (fstat (source_desc, &src_open_sb) != 0)
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("cannot fstat %s"), quotearg_style (shell_escape_always_quoting_style, src_name));
      return_val = 
                  0
                       ;
      goto close_src_desc;
    }



  if (! ((*src_sb).st_ino == (src_open_sb).st_ino && (*src_sb).st_dev == (src_open_sb).st_dev))
    {
      error (0, 0,
             gettext ("skipping file %s, as it was replaced while being copied"),
             quotearg_style (shell_escape_always_quoting_style, src_name));
      return_val = 
                  0
                       ;
      goto close_src_desc;
    }



  if (! *new_dst)
    {
      int open_flags =
        
       01 
                | 
                  0 
                           | (data_copy_required ? 
                                                   01000 
                                                           : 0);
      dest_desc = openat_safer (dst_dirfd, dst_relname, open_flags);
      dest_errno = 
                  (*__errno_location ())
                       ;
      if (0 <= dest_desc
          && (x->set_security_context || x->preserve_security_context))
        {
          if (! set_file_security_ctx (dst_name, 
                                                0
                                                     , x))
            {
              if (x->require_preserve_context)
                {
                  return_val = 
                              0
                                   ;
                  goto close_src_and_dst_desc;
                }
            }
        }

      if (dest_desc < 0 && dest_errno != 
                                        2
          
         && x->unlink_dest_after_failed_open)
        {
          if (unlinkat (dst_dirfd, dst_relname, 0) == 0)
            {
              if (x->verbose)
                printf (gettext ("removed %s\n"), quotearg_style (shell_escape_always_quoting_style, dst_name));
            }
          else if (
                  (*__errno_location ()) 
                        != 
                           2
                                 )
            {
              error (0, 
                       (*__errno_location ())
                            , gettext ("cannot remove %s"), quotearg_style (shell_escape_always_quoting_style, dst_name));
              return_val = 
                          0
                               ;
              goto close_src_desc;
            }

          dest_errno = 
                      2
                            ;
        }

      if (dest_desc < 0 && dest_errno == 
                                        2
                                              )
        {


          if (x->set_security_context)
            {
              if (! set_process_security_ctx (src_name, dst_name, dst_mode,
                                              
                                             1
                                                 , x))
                {
                  return_val = 
                              0
                                   ;
                  goto close_src_desc;
                }
            }


          *new_dst = 
                    1
                        ;
        }
    }

  if (*new_dst)
    {
      mode_t open_mode =
        ((dst_mode & ~omitted_permissions)
         | (preserve_xattr && !x->owner_privileges ? 
                                                    0200 
                                                            : 0));
      extra_permissions = open_mode & ~dst_mode;

      int open_flags = 
                      01 
                               | 
                                 0100 
                                         | 
                                           0
                                                   ;
      dest_desc = openat_safer (dst_dirfd, dst_relname, open_flags | 
                                                              0200
                                                                    ,
                          open_mode);
      dest_errno = 
                  (*__errno_location ())
                       ;
      if (dest_desc < 0 && dest_errno == 
                                        17 
                                               && ! x->move_mode)
        {
          char dummy[1];
          if (0 <= readlinkat (dst_dirfd, dst_relname, dummy, sizeof dummy))
            {
              if (x->open_dangling_dest_symlink)
                {
                  dest_desc = openat_safer (dst_dirfd, dst_relname,
                                      open_flags, open_mode);
                  dest_errno = 
                              (*__errno_location ())
                                   ;
                }
              else
                {
                  error (0, 0, gettext ("not writing through dangling symlink %s"),
                         quotearg_style (shell_escape_always_quoting_style, dst_name));
                  return_val = 
                              0
                                   ;
                  goto close_src_desc;
                }
            }
        }



      if (dest_desc < 0 && dest_errno == 
                                        21
          
         && *dst_name && dst_name[strlen (dst_name) - 1] == '/')
        dest_errno = 
                    20
                           ;
    }
  else
    {
      omitted_permissions = extra_permissions = 0;
    }

  if (dest_desc < 0)
    {
      error (0, dest_errno, gettext ("cannot create regular file %s"),
             quotearg_style (shell_escape_always_quoting_style, dst_name));
      return_val = 
                  0
                       ;
      goto close_src_desc;
    }


  if (data_copy_required && x->reflink_mode)
    {
      if (clone_file (dest_desc, source_desc) == 0)
        data_copy_required = 
                            0
                                 ;
      else if (x->reflink_mode == REFLINK_ALWAYS)
        {
          error (0, 
                   (*__errno_location ())
                        , gettext ("failed to clone %s from %s"),
                 quotearg_n_style (0, shell_escape_always_quoting_style, dst_name), quotearg_n_style (1, shell_escape_always_quoting_style, src_name));
          return_val = 
                      0
                           ;
          goto close_src_and_dst_desc;
        }
    }

  if (! (data_copy_required | x->preserve_ownership | extra_permissions))
    sb.st_mode = 0;
  else if (fstat (dest_desc, &sb) != 0)
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("cannot fstat %s"), quotearg_style (shell_escape_always_quoting_style, dst_name));
      return_val = 
                  0
                       ;
      goto close_src_and_dst_desc;
    }




  mode_t temporary_mode = sb.st_mode | extra_permissions;
  if (temporary_mode != sb.st_mode
      && (fchmod_or_lchmod (dest_desc, dst_dirfd, dst_relname, temporary_mode)
          != 0))
    extra_permissions = 0;

  if (data_copy_required)
    {

      size_t buf_size = io_blksize (sb);
      size_t hole_size = ((0 < (sb).st_blksize && (sb).st_blksize <= ((size_t)-1) / 8 + 1) ? (sb).st_blksize : 
                        512
                        );


      enum scantype scantype = infer_scantype (source_desc, &src_open_sb,
                                               &scan_inference);
      if (scantype == ERROR_SCANTYPE)
        {
          error (0, 
                   (*__errno_location ())
                        , gettext ("cannot lseek %s"), quotearg_style (shell_escape_always_quoting_style, src_name));
          return_val = 
                      0
                           ;
          goto close_src_and_dst_desc;
        }
      
     _Bool 
          make_holes
        = (
          ((((
          sb.st_mode
          )) & 0170000) == (0100000))
           
          && (x->sparse_mode == SPARSE_ALWAYS
               || (x->sparse_mode == SPARSE_AUTO
                   && scantype != PLAIN_SCANTYPE)));

      fdadvise (source_desc, 0, 0, FADVISE_SEQUENTIAL);



      if (! make_holes)
        {


          size_t blcm_max = 
                           ((((18446744073709551615UL))<(0x7fffffffffffffffL))?((18446744073709551615UL)):(0x7fffffffffffffffL))
                                                    ;
          size_t blcm = buffer_lcm (io_blksize (src_open_sb), buf_size,
                                    blcm_max);



          if (
             ((((
             src_open_sb.st_mode
             )) & 0170000) == (0100000)) 
                                           && src_open_sb.st_size < buf_size)
            buf_size = src_open_sb.st_size + 1;




          buf_size += blcm - 1;
          buf_size -= buf_size % blcm;
          if (buf_size == 0 || blcm_max < buf_size)
            buf_size = blcm;
        }

      off_t n_read;
      
     _Bool 
          wrote_hole_at_eof = 
                              0
                                   ;
      if (! (

             scantype == LSEEK_SCANTYPE
             ? lseek_copy (source_desc, dest_desc, &buf, buf_size, hole_size,
                           scan_inference.ext_start, src_open_sb.st_size,
                           make_holes ? x->sparse_mode : SPARSE_NEVER,
                           x->reflink_mode != REFLINK_NEVER,
                           src_name, dst_name)
             :

               sparse_copy (source_desc, dest_desc, &buf, buf_size,
                            make_holes ? hole_size : 0,
                            x->sparse_mode == SPARSE_ALWAYS,
                            x->reflink_mode != REFLINK_NEVER,
                            src_name, dst_name, 
                                               (18446744073709551615UL)
                                                          , &n_read,
                            &wrote_hole_at_eof)))
        {
          return_val = 
                      0
                           ;
          goto close_src_and_dst_desc;
        }
      else if (wrote_hole_at_eof && ftruncate (dest_desc, n_read) < 0)
        {
          error (0, 
                   (*__errno_location ())
                        , gettext ("failed to extend %s"), quotearg_style (shell_escape_always_quoting_style, dst_name));
          return_val = 
                      0
                           ;
          goto close_src_and_dst_desc;
        }
    }

  if (x->preserve_timestamps)
    {
      struct timespec timespec[2];
      timespec[0] = get_stat_atime (src_sb);
      timespec[1] = get_stat_mtime (src_sb);

      if (fdutimensat (dest_desc, dst_dirfd, dst_relname, timespec, 0) != 0)
        {
          error (0, 
                   (*__errno_location ())
                        , gettext ("preserving times for %s"), quotearg_style (shell_escape_always_quoting_style, dst_name));
          if (x->require_preserve)
            {
              return_val = 
                          0
                               ;
              goto close_src_and_dst_desc;
            }
        }
    }



  if (x->preserve_ownership && ! (((*src_sb).st_uid == (sb).st_uid) && ((*src_sb).st_gid == (sb).st_gid)))
    {
      switch (set_owner (x, dst_name, dst_dirfd, dst_relname, dest_desc,
                         src_sb, *new_dst, &sb))
        {
        case -1:
          return_val = 
                      0
                           ;
          goto close_src_and_dst_desc;

        case 0:
          src_mode &= ~ (
                        04000 
                                | 
                                  02000 
                                          | 
                                            01000
                                                   );
          break;
        }
    }

  if (preserve_xattr)
    {
      if (!copy_attr (src_name, source_desc, dst_name, dest_desc, x)
          && x->require_preserve_xattr)
        return_val = 
                    0
                         ;
    }

  set_author (dst_name, dest_desc, src_sb);

  if (x->preserve_mode || x->move_mode)
    {
      if (copy_acl (src_name, source_desc, dst_name, dest_desc, src_mode) != 0
          && x->require_preserve)
        return_val = 
                    0
                         ;
    }
  else if (x->set_mode)
    {
      if (set_acl (dst_name, dest_desc, x->mode) != 0)
        return_val = 
                    0
                         ;
    }
  else if (x->explicit_no_preserve_mode && *new_dst)
    {
      if (set_acl (dst_name, dest_desc, (
                                       0400 
                                       | 
                                       0200 
                                       | 
                                       (0400 >> 3) 
                                       | 
                                       (0200 >> 3) 
                                       | 
                                       ((0400 >> 3) >> 3) 
                                       | 
                                       ((0200 >> 3) >> 3)
                                       ) & ~cached_umask ()) != 0)
        return_val = 
                    0
                         ;
    }
  else if (omitted_permissions | extra_permissions)
    {
      omitted_permissions &= ~ cached_umask ();
      if ((omitted_permissions | extra_permissions)
          && (fchmod_or_lchmod (dest_desc, dst_dirfd, dst_relname,
                                dst_mode & ~ cached_umask ())
              != 0))
        {
          error (0, 
                   (*__errno_location ())
                        , gettext ("preserving permissions for %s"),
                 quotearg_style (shell_escape_always_quoting_style, dst_name));
          if (x->require_preserve)
            return_val = 
                        0
                             ;
        }
    }

close_src_and_dst_desc:
  if (close (dest_desc) < 0)
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("failed to close %s"), quotearg_style (shell_escape_always_quoting_style, dst_name));
      return_val = 
                  0
                       ;
    }
close_src_desc:
  if (close (source_desc) < 0)
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("failed to close %s"), quotearg_style (shell_escape_always_quoting_style, src_name));
      return_val = 
                  0
                       ;
    }

  alignfree (buf);
  return return_val;
}
static 
      _Bool

same_file_ok (char const *src_name, struct stat const *src_sb,
              int dst_dirfd, char const *dst_relname, struct stat const *dst_sb,
              const struct cp_options *x, 
                                         _Bool 
                                              *return_now)
{
  const struct stat *src_sb_link;
  const struct stat *dst_sb_link;
  struct stat tmp_dst_sb;
  struct stat tmp_src_sb;

  
 _Bool 
      same_link;
  
 _Bool 
      same = ((*src_sb).st_ino == (*dst_sb).st_ino && (*src_sb).st_dev == (*dst_sb).st_dev);

  *return_now = 
               0
                    ;






  if (same && x->hard_link)
    {
      *return_now = 
                   1
                       ;
      return 
            1
                ;
    }

  if (x->dereference == DEREF_NEVER)
    {
      same_link = same;




      if (
         ((((
         src_sb->st_mode
         )) & 0170000) == (0120000)) 
                                   && 
                                      ((((
                                      dst_sb->st_mode
                                      )) & 0170000) == (0120000))
                                                               )
        {
          
         _Bool 
              sn = same_nameat (
                                -100
                                        , src_name, dst_dirfd, dst_relname);
          if ( ! sn)
            {

              if (x->backup_type != no_backups)
                return 
                      1
                          ;





              if (same_link)
                {
                  *return_now = 
                               1
                                   ;
                  return ! x->move_mode;
                }
            }

          return ! sn;
        }

      src_sb_link = src_sb;
      dst_sb_link = dst_sb;
    }
  else
    {
      if (!same)
        return 
              1
                  ;

      if (fstatat (dst_dirfd, dst_relname, &tmp_dst_sb,
                   
                  0x100
                                     ) != 0
          || lstat (src_name, &tmp_src_sb) != 0)
        return 
              1
                  ;

      src_sb_link = &tmp_src_sb;
      dst_sb_link = &tmp_dst_sb;

      same_link = ((*src_sb_link).st_ino == (*dst_sb_link).st_ino && (*src_sb_link).st_dev == (*dst_sb_link).st_dev);






      if (
         ((((
         src_sb_link->st_mode
         )) & 0170000) == (0120000)) 
                                        && 
                                           ((((
                                           dst_sb_link->st_mode
                                           )) & 0170000) == (0120000))
          
         && x->unlink_dest_before_opening)
        return 
              1
                  ;
    }






  if (x->backup_type != no_backups)
    {
      if (!same_link)
        {
          if ( ! x->move_mode
               && x->dereference != DEREF_NEVER
               && 
                 ((((
                 src_sb_link->st_mode
                 )) & 0170000) == (0120000))
               
              && ! 
                   ((((
                   dst_sb_link->st_mode
                   )) & 0170000) == (0120000))
                                                 )
            return 
                  0
                       ;

          return 
                1
                    ;
        }


      return ! same_nameat (
                           -100
                                   , src_name, dst_dirfd, dst_relname);
    }
  if (x->move_mode || x->unlink_dest_before_opening)
    {




      if (
         ((((
         dst_sb_link->st_mode
         )) & 0170000) == (0120000))
                                       )
        return 
              1
                  ;



      if (same_link
          && 1 < dst_sb_link->st_nlink
          && ! same_nameat (
                           -100
                                   , src_name, dst_dirfd, dst_relname))
        return ! x->move_mode;
    }



  if (!
      ((((
      src_sb_link->st_mode
      )) & 0170000) == (0120000)) 
                                     && !
                                         ((((
                                         dst_sb_link->st_mode
                                         )) & 0170000) == (0120000))
                                                                       )
    {
      if (!((*src_sb_link).st_ino == (*dst_sb_link).st_ino && (*src_sb_link).st_dev == (*dst_sb_link).st_dev))
        return 
              1
                  ;


      if (x->hard_link)
        {
          *return_now = 
                       1
                           ;
          return 
                1
                    ;
        }
    }
  if (x->move_mode
      && 
        ((((
        src_sb->st_mode
        )) & 0170000) == (0120000))
      
     && 1 < dst_sb_link->st_nlink)
    {
      char *abs_src = canonicalize_file_name (src_name);
      if (abs_src)
        {
          
         _Bool 
              result = ! same_nameat (
                                      -100
                                              , abs_src,
                                       dst_dirfd, dst_relname);
          free (abs_src);
          return result;
        }
    }


  if (x->symbolic_link && 
                         ((((
                         dst_sb_link->st_mode
                         )) & 0170000) == (0120000))
                                                       )
    return 
          1
              ;

  if (x->dereference == DEREF_NEVER)
    {
      if ( ! 
            ((((
            src_sb_link->st_mode
            )) & 0170000) == (0120000))
                                          )
        tmp_src_sb = *src_sb_link;
      else if (stat (src_name, &tmp_src_sb) != 0)
        return 
              1
                  ;

      if ( ! 
            ((((
            dst_sb_link->st_mode
            )) & 0170000) == (0120000))
                                          )
        tmp_dst_sb = *dst_sb_link;
      else if (fstatat (dst_dirfd, dst_relname, &tmp_dst_sb, 0) != 0)
        return 
              1
                  ;

      if ( ! ((tmp_src_sb).st_ino == (tmp_dst_sb).st_ino && (tmp_src_sb).st_dev == (tmp_dst_sb).st_dev))
        return 
              1
                  ;

      if (x->hard_link)
        {




          *return_now = ! 
                         ((((
                         dst_sb_link->st_mode
                         )) & 0170000) == (0120000))
                                                       ;
          return 
                1
                    ;
        }
    }

  return 
        0
             ;
}




static 
      _Bool

writable_destination (int dst_dirfd, char const *dst_relname, mode_t mode)
{
  return (
         ((((
         mode
         )) & 0170000) == (0120000))
          
         || can_write_any_file ()
          || faccessat (dst_dirfd, dst_relname, 
                                               2
                                                   , 
                                                     0x200
                                                               ) == 0);
}

static 
      _Bool

overwrite_ok (struct cp_options const *x, char const *dst_name,
              int dst_dirfd, char const *dst_relname,
              struct stat const *dst_sb)
{
  if (! writable_destination (dst_dirfd, dst_relname, dst_sb->st_mode))
    {
      char perms[12];
      strmode (dst_sb->st_mode, perms);
      perms[10] = '\0';
      fprintf (
              stderr
                    ,
               (x->move_mode || x->unlink_dest_before_opening
                || x->unlink_dest_after_failed_open)
               ? gettext ("%s: replace %s, overriding mode %04lo (%s)? ")
               : gettext ("%s: unwritable %s (mode %04lo, %s); try anyway? "),
               program_name, quotearg_style (shell_escape_always_quoting_style, dst_name),
               (unsigned long int) (dst_sb->st_mode & (
                                                     04000 
                                                     | 
                                                     02000 
                                                     | 
                                                     01000 
                                                     | 
                                                     (0400|0200|0100) 
                                                     | 
                                                     ((0400|0200|0100) >> 3) 
                                                     | 
                                                     (((0400|0200|0100) >> 3) >> 3)
                                                     )),
               &perms[1]);
    }
  else
    {
      fprintf (
              stderr
                    , gettext ("%s: overwrite %s? "),
               program_name, quotearg_style (shell_escape_always_quoting_style, dst_name));
    }

  return yesno ();
}



extern void
dest_info_init (struct cp_options *x)
{
  x->dest_info
    = hash_initialize (61,
                       
                      ((void *)0)
                          ,
                       triple_hash,
                       triple_compare,
                       triple_free);
  if (! x->dest_info)
    xalloc_die ();
}



extern void
src_info_init (struct cp_options *x)
{
  x->src_info
    = hash_initialize (61,
                       
                      ((void *)0)
                          ,
                       triple_hash_no_name,
                       triple_compare,
                       triple_free);
  if (! x->src_info)
    xalloc_die ();
}
static 
      _Bool

abandon_move (const struct cp_options *x,
              char const *dst_name,
              int dst_dirfd, char const *dst_relname,
              struct stat const *dst_sb)
{
  
 ((void) sizeof ((
 x->move_mode
 ) ? 1 : 0), __extension__ ({ if (
 x->move_mode
 ) ; else __assert_fail (
 "x->move_mode"
 , "src/copy.c", 1808, __extension__ __PRETTY_FUNCTION__); }))
                      ;
  return (x->interactive == I_ALWAYS_NO
          || ((x->interactive == I_ASK_USER
               || (x->interactive == I_UNSPECIFIED
                   && x->stdin_tty
                   && ! writable_destination (dst_dirfd, dst_relname,
                                              dst_sb->st_mode)))
              && ! overwrite_ok (x, dst_name, dst_dirfd, dst_relname, dst_sb)));
}




static void
emit_verbose (char const *src, char const *dst, char const *backup_dst_name)
{
  printf ("%s -> %s", quotearg_n_style (0, shell_escape_always_quoting_style, src), quotearg_n_style (1, shell_escape_always_quoting_style, dst));
  if (backup_dst_name)
    printf (gettext (" (backup: %s)"), quotearg_style (shell_escape_always_quoting_style, backup_dst_name));
  putchar_unlocked ('\n');
}


static void
restore_default_fscreatecon_or_die (void)
{
  if (setfscreatecon (
                     ((void *)0)
                         ) != 0)
    ((!!sizeof (struct { _Static_assert (
   1
   , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), gettext (\"failed to restore the default file creation context\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
   1
   , 
   (*__errno_location ())
   , gettext ("failed to restore the default file creation context")), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
   1
   , 
   (*__errno_location ())
   , gettext ("failed to restore the default file creation context")), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))))
                                                                  ;
}



static char *
subst_suffix (char const *str, char const *suffix, char const *newsuffix)
{
  idx_t prefixlen = suffix - str;
  idx_t newsuffixsize = strlen (newsuffix) + 1;
  char *r = ximalloc (prefixlen + newsuffixsize);
  memcpy (r + prefixlen, newsuffix, newsuffixsize);
  return memcpy (r, str, prefixlen);
}
static 
      _Bool

create_hard_link (char const *src_name, int src_dirfd, char const *src_relname,
                  char const *dst_name, int dst_dirfd, char const *dst_relname,
                  
                 _Bool 
                      replace, 
                               _Bool 
                                    verbose, 
                                             _Bool 
                                                  dereference)
{
  int err = force_linkat (src_dirfd, src_relname, dst_dirfd, dst_relname,
                          dereference ? 
                                       0x400 
                                                         : 0,
                          replace, -1);
  if (0 < err)
    {

      char *a_src_name = 
                        ((void *)0)
                            ;
      if (!src_name)
        src_name = a_src_name = subst_suffix (dst_name, dst_relname,
                                              src_relname);
      error (0, err, gettext ("cannot create hard link %s to %s"),
             quotearg_n_style (0, shell_escape_always_quoting_style, dst_name), quotearg_n_style (1, shell_escape_always_quoting_style, src_name));
      free (a_src_name);
      return 
            0
                 ;
    }
  if (err < 0 && verbose)
    printf (gettext ("removed %s\n"), quotearg_style (shell_escape_always_quoting_style, dst_name));
  return 
        1
            ;
}




__attribute__ ((__pure__))
static inline 
             _Bool

should_dereference (const struct cp_options *x, 
                                               _Bool 
                                                    command_line_arg)
{
  return x->dereference == DEREF_ALWAYS
         || (x->dereference == DEREF_COMMAND_LINE_ARGUMENTS
             && command_line_arg);
}



static 
      _Bool

source_is_dst_backup (char const *srcbase, struct stat const *src_st,
                      int dst_dirfd, char const *dst_relname)
{
  size_t srcbaselen = strlen (srcbase);
  char const *dstbase = last_component (dst_relname);
  size_t dstbaselen = strlen (dstbase);
  size_t suffixlen = strlen (simple_backup_suffix);
  if (! (srcbaselen == dstbaselen + suffixlen
         && memcmp (srcbase, dstbase, dstbaselen) == 0
         && (strcmp (srcbase + dstbaselen, simple_backup_suffix) == 0)))
    return 
          0
               ;
  char *dst_back = subst_suffix (dst_relname,
                                 dst_relname + strlen (dst_relname),
                                 simple_backup_suffix);
  struct stat dst_back_sb;
  int dst_back_status = fstatat (dst_dirfd, dst_back, &dst_back_sb, 0);
  free (dst_back);
  return dst_back_status == 0 && ((*src_st).st_ino == (dst_back_sb).st_ino && (*src_st).st_dev == (dst_back_sb).st_dev);
}
static 
      _Bool

copy_internal (char const *src_name, char const *dst_name,
               int dst_dirfd, char const *dst_relname,
               int nonexistent_dst,
               struct stat const *parent,
               struct dir_list *ancestors,
               const struct cp_options *x,
               
              _Bool 
                   command_line_arg,
               
              _Bool 
                   *first_dir_created_per_command_line_arg,
               
              _Bool 
                   *copy_into_self,
               
              _Bool 
                   *rename_succeeded)
{
  struct stat src_sb;
  struct stat dst_sb;
  mode_t src_mode ;
  mode_t dst_mode ;
  mode_t dst_mode_bits;
  mode_t omitted_permissions;
  
 _Bool 
      restore_dst_mode = 
                         0
                              ;
  char *earlier_file = 
                      ((void *)0)
                          ;
  char *dst_backup = 
                    ((void *)0)
                        ;
  
 _Bool 
      delayed_ok;
  
 _Bool 
      copied_as_regular = 
                          0
                               ;
  
 _Bool 
      dest_is_symlink = 
                        0
                             ;
  
 _Bool 
      have_dst_lstat = 
                       0
                            ;





  
 _Bool 
      new_dst = 0 < nonexistent_dst;

  *copy_into_self = 
                   0
                        ;

  int rename_errno = x->rename_errno;
  if (x->move_mode)
    {
      if (rename_errno < 0)
        rename_errno = (renameatu (
                                  -100
                                          , src_name, dst_dirfd, dst_relname,
                                   
                                  (1 << 0)
                                                  )
                        ? 
                         (*__errno_location ()) 
                               : 0);
      nonexistent_dst = *rename_succeeded = new_dst = rename_errno == 0;
    }

  if (rename_errno == 0
      ? !x->last_file
      : rename_errno != 
                       17 
                              || x->interactive != I_ALWAYS_NO)
    {
      char const *name = rename_errno == 0 ? dst_name : src_name;
      int dirfd = rename_errno == 0 ? dst_dirfd : 
                                                 -100
                                                         ;
      char const *relname = rename_errno == 0 ? dst_relname : src_name;
      int fstatat_flags
        = x->dereference == DEREF_NEVER ? 
                                         0x100 
                                                             : 0;
      if (follow_fstatat (dirfd, relname, &src_sb, fstatat_flags) != 0)
        {
          error (0, 
                   (*__errno_location ())
                        , gettext ("cannot stat %s"), quotearg_style (shell_escape_always_quoting_style, name));
          return 
                0
                     ;
        }

      src_mode = src_sb.st_mode;

      if (
         ((((
         src_mode
         )) & 0170000) == (0040000)) 
                            && !x->recursive)
        {
          error (0, 0, ! x->install_mode
                 ? gettext ("-r not specified; omitting directory %s")
                 : gettext ("omitting directory %s"),
                 quotearg_style (shell_escape_always_quoting_style, src_name));
          return 
                0
                     ;
        }
    }
  else
    {




    }





  if (command_line_arg && x->src_info)
    {
      if ( ! 
            ((((
            src_mode
            )) & 0170000) == (0040000))
           
          && x->backup_type == no_backups
           && seen_file (x->src_info, src_name, &src_sb))
        {
          error (0, 0, gettext ("warning: source file %s specified more than once"),
                 quotearg_style (shell_escape_always_quoting_style, src_name));
          return 
                1
                    ;
        }

      record_file (x->src_info, src_name, &src_sb);
    }

  
 _Bool 
      dereference = should_dereference (x, command_line_arg);

  if (nonexistent_dst <= 0)
    {
      if (! (rename_errno == 
                            17 
                                   && x->interactive == I_ALWAYS_NO))
        {






          
         _Bool 
              use_lstat
            = ((! 
                 ((((
                 src_mode
                 )) & 0170000) == (0100000))
                
               && (! x->copy_as_regular
                    || 
                      ((((
                      src_mode
                      )) & 0170000) == (0040000)) 
                                         || 
                                            ((((
                                            src_mode
                                            )) & 0170000) == (0120000))
                                                              ))
               || x->move_mode || x->symbolic_link || x->hard_link
               || x->backup_type != no_backups
               || x->unlink_dest_before_opening);
          int fstatat_flags = use_lstat ? 
                                         0x100 
                                                             : 0;
          if (!use_lstat && nonexistent_dst < 0)
            new_dst = 
                     1
                         ;
          else if (follow_fstatat (dst_dirfd, dst_relname, &dst_sb,
                                   fstatat_flags)
                   == 0)
            {
              have_dst_lstat = use_lstat;
              rename_errno = 
                            17
                                  ;
            }
          else
            {
              if (
                 (*__errno_location ()) 
                       == 
                          40 
                                && x->unlink_dest_after_failed_open)
                                                              ;
              else if (
                      (*__errno_location ()) 
                            != 
                               2
                                     )
                {
                  error (0, 
                           (*__errno_location ())
                                , gettext ("cannot stat %s"), quotearg_style (shell_escape_always_quoting_style, dst_name));
                  return 
                        0
                             ;
                }
              else
                new_dst = 
                         1
                             ;
            }
        }

      if (rename_errno == 
                         17
                               )
        {
          
         _Bool 
              return_now = 
                           0
                                ;

          if (x->interactive != I_ALWAYS_NO
              && ! same_file_ok (src_name, &src_sb, dst_dirfd, dst_relname,
                                 &dst_sb, x, &return_now))
            {
              error (0, 0, gettext ("%s and %s are the same file"),
                     quotearg_n_style (0, shell_escape_always_quoting_style, src_name), quotearg_n_style (1, shell_escape_always_quoting_style, dst_name));
              return 
                    0
                         ;
            }

          if (x->update && !
                           ((((
                           src_mode
                           )) & 0170000) == (0040000))
                                             )
            {




              int options = ((x->preserve_timestamps
                              && ! (x->move_mode
                                    && dst_sb.st_dev == src_sb.st_dev))
                             ? UTIMECMP_TRUNCATE_SOURCE
                             : 0);

              if (0 <= utimecmpat (dst_dirfd, dst_relname, &dst_sb,
                                   &src_sb, options))
                {




                  if (rename_succeeded)
                    *rename_succeeded = 
                                       1
                                           ;






                  earlier_file = remember_copied (dst_relname, src_sb.st_ino,
                                                  src_sb.st_dev);
                  if (earlier_file)
                    {


                      if (! create_hard_link (
                                             ((void *)0)
                                                 , dst_dirfd, earlier_file,
                                              dst_name, dst_dirfd, dst_relname,
                                              
                                             1
                                                 ,
                                              x->verbose, dereference))
                        {
                          goto un_backup;
                        }
                    }

                  return 
                        1
                            ;
                }
            }
          if (x->move_mode)
            {
              if (abandon_move (x, dst_name, dst_dirfd, dst_relname, &dst_sb))
                {


                  if (rename_succeeded)
                    *rename_succeeded = 
                                       1
                                           ;
                  return 
                        1
                            ;
                }
            }
          else
            {
              if (! 
                   ((((
                   src_mode
                   )) & 0170000) == (0040000))
                  
                 && (x->interactive == I_ALWAYS_NO
                      || (x->interactive == I_ASK_USER
                          && ! overwrite_ok (x, dst_name, dst_dirfd,
                                             dst_relname, &dst_sb))))
                return 
                      1
                          ;
            }

          if (return_now)
            return 
                  1
                      ;

          if (!
              ((((
              dst_sb.st_mode
              )) & 0170000) == (0040000))
                                      )
            {
              if (
                 ((((
                 src_mode
                 )) & 0170000) == (0040000))
                                   )
                {
                  if (x->move_mode && x->backup_type != no_backups)
                    {


                    }
                  else
                    {
                      error (0, 0,
                       gettext ("cannot overwrite non-directory %s with directory %s"),
                             quotearg_n_style (0, shell_escape_always_quoting_style, dst_name), quotearg_n_style (1, shell_escape_always_quoting_style, src_name));
                      return 
                            0
                                 ;
                    }
                }
              if (command_line_arg
                  && x->backup_type != numbered_backups
                  && seen_file (x->dest_info, dst_relname, &dst_sb))
                {
                  error (0, 0,
                         gettext ("will not overwrite just-created %s with %s"),
                         quotearg_n_style (0, shell_escape_always_quoting_style, dst_name), quotearg_n_style (1, shell_escape_always_quoting_style, src_name));
                  return 
                        0
                             ;
                }
            }

          if (!
              ((((
              src_mode
              )) & 0170000) == (0040000))
                                )
            {
              if (
                 ((((
                 dst_sb.st_mode
                 )) & 0170000) == (0040000))
                                         )
                {
                  if (x->move_mode && x->backup_type != no_backups)
                    {


                    }
                  else
                    {
                      error (0, 0,
                         gettext ("cannot overwrite directory %s with non-directory"),
                             quotearg_style (shell_escape_always_quoting_style, dst_name));
                      return 
                            0
                                 ;
                    }
                }
            }

          if (x->move_mode)
            {

              if (
                 ((((
                 src_sb.st_mode
                 )) & 0170000) == (0040000)) 
                                          && !
                                              ((((
                                              dst_sb.st_mode
                                              )) & 0170000) == (0040000))
                  
                 && x->backup_type == no_backups)
                {
                  error (0, 0,
                       gettext ("cannot move directory onto non-directory: %s -> %s"),
                         quotearg_n_style_colon (0, shell_escape_quoting_style, src_name), quotearg_n_style_colon (0, shell_escape_quoting_style, dst_name));
                  return 
                        0
                             ;
                }
            }

          char const *srcbase;
          if (x->backup_type != no_backups


              && ! dot_or_dotdot (srcbase = last_component (src_name))





              && (x->move_mode || ! 
                                   ((((
                                   dst_sb.st_mode
                                   )) & 0170000) == (0040000))
                                                           ))
            {




              if (x->backup_type != numbered_backups
                  && source_is_dst_backup (srcbase, &src_sb,
                                           dst_dirfd, dst_relname))
                {
                  char const *fmt;
                  fmt = (x->move_mode
                 ? gettext ("backing up %s might destroy source;  %s not moved")
                 : gettext ("backing up %s might destroy source;  %s not copied"));
                  error (0, 0, fmt,
                         quotearg_n_style (0, shell_escape_always_quoting_style, dst_name),
                         quotearg_n_style (1, shell_escape_always_quoting_style, src_name));
                  return 
                        0
                             ;
                }

              char *tmp_backup = backup_file_rename (dst_dirfd, dst_relname,
                                                     x->backup_type);






              if (tmp_backup)
                {
                  idx_t dirlen = dst_relname - dst_name;
                  idx_t backupsize = strlen (tmp_backup) + 1;
                  dst_backup = __builtin_alloca (dirlen + backupsize);
                  memcpy (mempcpy (dst_backup, dst_name, dirlen),
                          tmp_backup, backupsize);
                  free (tmp_backup);
                }
              else if (
                      (*__errno_location ()) 
                            != 
                               2
                                     )
                {
                  error (0, 
                           (*__errno_location ())
                                , gettext ("cannot backup %s"), quotearg_style (shell_escape_always_quoting_style, dst_name));
                  return 
                        0
                             ;
                }
              new_dst = 
                       1
                           ;
            }
          else if (! 
                    ((((
                    dst_sb.st_mode
                    )) & 0170000) == (0040000))

                   
                  && ! x->move_mode
                   && (x->unlink_dest_before_opening
                       || (x->data_copy_required
                           && ((x->preserve_links && 1 < dst_sb.st_nlink)
                               || (x->dereference == DEREF_NEVER
                                   && ! 
                                       ((((
                                       src_sb.st_mode
                                       )) & 0170000) == (0100000))
                                                               )))
                      ))
            {
              if (unlinkat (dst_dirfd, dst_relname, 0) != 0 && 
                                                              (*__errno_location ()) 
                                                                    != 
                                                                       2
                                                                             )
                {
                  error (0, 
                           (*__errno_location ())
                                , gettext ("cannot remove %s"), quotearg_style (shell_escape_always_quoting_style, dst_name));
                  return 
                        0
                             ;
                }
              new_dst = 
                       1
                           ;
              if (x->verbose)
                printf (gettext ("removed %s\n"), quotearg_style (shell_escape_always_quoting_style, dst_name));
            }
        }
    }



  if (command_line_arg
      && x->dest_info
      && ! x->move_mode
      && x->backup_type == no_backups)
    {
      
     _Bool 
          lstat_ok = 
                     1
                         ;
      struct stat tmp_buf;
      struct stat *dst_lstat_sb;



      if (have_dst_lstat)
        dst_lstat_sb = &dst_sb;
      else
        {
          if (fstatat (dst_dirfd, dst_relname, &tmp_buf,
                       
                      0x100
                                         ) == 0)
            dst_lstat_sb = &tmp_buf;
          else
            lstat_ok = 
                      0
                           ;
        }


      if (lstat_ok
          && 
            ((((
            dst_lstat_sb->st_mode
            )) & 0170000) == (0120000))
          
         && seen_file (x->dest_info, dst_relname, dst_lstat_sb))
        {
          error (0, 0,
                 gettext ("will not copy %s through just-created symlink %s"),
                 quotearg_n_style (0, shell_escape_always_quoting_style, src_name), quotearg_n_style (1, shell_escape_always_quoting_style, dst_name));
          return 
                0
                     ;
        }
    }





  if (x->verbose && !x->move_mode && !
                                     ((((
                                     src_mode
                                     )) & 0170000) == (0040000))
                                                       )
    emit_verbose (src_name, dst_name, dst_backup);
  if (rename_errno == 0)
    earlier_file = 
                  ((void *)0)
                      ;
  else if (x->recursive && 
                          ((((
                          src_mode
                          )) & 0170000) == (0040000))
                                            )
    {
      if (command_line_arg)
        earlier_file = remember_copied (dst_relname,
                                        src_sb.st_ino, src_sb.st_dev);
      else
        earlier_file = src_to_dest_lookup (src_sb.st_ino, src_sb.st_dev);
    }
  else if (x->move_mode && src_sb.st_nlink == 1)
    {
      earlier_file = src_to_dest_lookup (src_sb.st_ino, src_sb.st_dev);
    }
  else if (x->preserve_links
           && !x->hard_link
           && (1 < src_sb.st_nlink
               || (command_line_arg
                   && x->dereference == DEREF_COMMAND_LINE_ARGUMENTS)
               || x->dereference == DEREF_ALWAYS))
    {
      earlier_file = remember_copied (dst_relname,
                                      src_sb.st_ino, src_sb.st_dev);
    }




  if (earlier_file)
    {



      if (
         ((((
         src_mode
         )) & 0170000) == (0040000))
                           )
        {


          if (same_nameat (
                          -100
                                  , src_name, dst_dirfd, earlier_file))
            {
              error (0, 0, gettext ("cannot copy a directory, %s, into itself, %s"),
                     quotearg_n_style (0, shell_escape_always_quoting_style, top_level_src_name),
                     quotearg_n_style (1, shell_escape_always_quoting_style, top_level_dst_name));
              *copy_into_self = 
                               1
                                   ;
              goto un_backup;
            }
          else if (same_nameat (dst_dirfd, dst_relname,
                                dst_dirfd, earlier_file))
            {
              error (0, 0, gettext ("warning: source directory %s " "specified more than once")
                                                        ,
                     quotearg_style (shell_escape_always_quoting_style, top_level_src_name));




              if (x->move_mode && rename_succeeded)
                *rename_succeeded = 
                                   1
                                       ;


              return 
                    1
                        ;
            }
          else if (x->dereference == DEREF_ALWAYS
                   || (command_line_arg
                       && x->dereference == DEREF_COMMAND_LINE_ARGUMENTS))
            {






            }
          else
            {
              char *earlier = subst_suffix (dst_name, dst_relname,
                                            earlier_file);
              error (0, 0, gettext ("will not create hard link %s to directory %s"),
                     quotearg_n_style (0, shell_escape_always_quoting_style, dst_name), quotearg_n_style (1, shell_escape_always_quoting_style, earlier));
              free (earlier);
              goto un_backup;
            }
        }
      else
        {
          if (! create_hard_link (
                                 ((void *)0)
                                     , dst_dirfd, earlier_file,
                                  dst_name, dst_dirfd, dst_relname,
                                  
                                 1
                                     , x->verbose, dereference))
            goto un_backup;

          return 
                1
                    ;
        }
    }

  if (x->move_mode)
    {
      if (rename_errno == 
                         17
                               )
        rename_errno = ((renameat (
                                  -100
                                          , src_name, dst_dirfd, dst_relname)
                         == 0)
                        ? 0 : 
                             (*__errno_location ())
                                  );

      if (rename_errno == 0)
        {
          if (x->verbose)
            {
              printf (gettext ("renamed "));
              emit_verbose (src_name, dst_name, dst_backup);
            }

          if (x->set_security_context)
            {

              (void) set_file_security_ctx (dst_name, 
                                                     1
                                                         , x);
            }

          if (rename_succeeded)
            *rename_succeeded = 
                               1
                                   ;

          if (command_line_arg && !x->last_file)
            {







              record_file (x->dest_info, dst_relname, &src_sb);
            }

          return 
                1
                    ;
        }






      if (rename_errno == 
                         22
                               )
        {



          error (0, 0, gettext ("cannot move %s to a subdirectory of itself, %s"),
                 quotearg_n_style (0, shell_escape_always_quoting_style, top_level_src_name),
                 quotearg_n_style (1, shell_escape_always_quoting_style, top_level_dst_name));





          *copy_into_self = 
                           1
                               ;



          return 
                1
                    ;
        }
      if (rename_errno != 
                         18
                              )
        {
          error (0, rename_errno,
                 gettext ("cannot move %s to %s"),
                 quotearg_n_style (0, shell_escape_always_quoting_style, src_name), quotearg_n_style (1, shell_escape_always_quoting_style, dst_name));
          forget_created (src_sb.st_ino, src_sb.st_dev);
          return 
                0
                     ;
        }







      if ((unlinkat (dst_dirfd, dst_relname,
                     
                    ((((
                    src_mode
                    )) & 0170000) == (0040000)) 
                                       ? 
                                         0x200 
                                                      : 0)
           != 0)
          && 
            (*__errno_location ()) 
                  != 
                     2
                           )
        {
          error (0, 
                   (*__errno_location ())
                        ,
             gettext ("inter-device move failed: %s to %s; unable to remove target"),
                 quotearg_n_style (0, shell_escape_always_quoting_style, src_name), quotearg_n_style (1, shell_escape_always_quoting_style, dst_name));
          forget_created (src_sb.st_ino, src_sb.st_dev);
          return 
                0
                     ;
        }

      if (x->verbose && !
                        ((((
                        src_mode
                        )) & 0170000) == (0040000))
                                          )
        {
          printf (gettext ("copied "));
          emit_verbose (src_name, dst_name, dst_backup);
        }
      new_dst = 
               1
                   ;
    }





  dst_mode_bits = (x->set_mode ? x->mode : src_mode) & (
                                                      04000 
                                                      | 
                                                      02000 
                                                      | 
                                                      01000 
                                                      | 
                                                      (0400|0200|0100) 
                                                      | 
                                                      ((0400|0200|0100) >> 3) 
                                                      | 
                                                      (((0400|0200|0100) >> 3) >> 3)
                                                      );
  omitted_permissions =
    (dst_mode_bits
     & (x->preserve_ownership ? 
                               ((0400|0200|0100) >> 3) 
                                       | 
                                         (((0400|0200|0100) >> 3) >> 3)
        
       : 
         ((((
         src_mode
         )) & 0170000) == (0040000)) 
                            ? 
                              (0200 >> 3) 
                                      | 
                                        ((0200 >> 3) >> 3)
        
       : 0));

  delayed_ok = 
              1
                  ;





  if (! set_process_security_ctx (src_name, dst_name, src_mode, new_dst, x))
    return 
          0
               ;

  if (
     ((((
     src_mode
     )) & 0170000) == (0040000))
                       )
    {
      struct dir_list *dir;






      if (is_ancestor (&src_sb, ancestors))
        {
          error (0, 0, gettext ("cannot copy cyclic symbolic link %s"),
                 quotearg_style (shell_escape_always_quoting_style, src_name));
          goto un_backup;
        }



      dir = __builtin_alloca (sizeof *dir);
      dir->parent = ancestors;
      dir->ino = src_sb.st_ino;
      dir->dev = src_sb.st_dev;

      if (new_dst || !
                     ((((
                     dst_sb.st_mode
                     )) & 0170000) == (0040000))
                                             )
        {




          mode_t mode = dst_mode_bits & ~omitted_permissions;
          if (mkdirat (dst_dirfd, dst_relname, mode) != 0)
            {
              error (0, 
                       (*__errno_location ())
                            , gettext ("cannot create directory %s"),
                     quotearg_style (shell_escape_always_quoting_style, dst_name));
              goto un_backup;
            }





          if (fstatat (dst_dirfd, dst_relname, &dst_sb,
                       
                      0x100
                                         ) != 0)
            {
              error (0, 
                       (*__errno_location ())
                            , gettext ("cannot stat %s"), quotearg_style (shell_escape_always_quoting_style, dst_name));
              goto un_backup;
            }
          else if ((dst_sb.st_mode & 
                                    (0400|0200|0100)
                                           ) != 
                                                (0400|0200|0100)
                                                       )
            {


              dst_mode = dst_sb.st_mode;
              restore_dst_mode = 
                                1
                                    ;

              if (lchmodat (dst_dirfd, dst_relname, dst_mode | 
                                                              (0400|0200|0100)
                                                                     ) != 0)
                {
                  error (0, 
                           (*__errno_location ())
                                , gettext ("setting permissions for %s"),
                         quotearg_style (shell_escape_always_quoting_style, dst_name));
                  goto un_backup;
                }
            }





          if (!*first_dir_created_per_command_line_arg)
            {
              remember_copied (dst_relname, dst_sb.st_ino, dst_sb.st_dev);
              *first_dir_created_per_command_line_arg = 
                                                       1
                                                           ;
            }

          if (x->verbose)
            {
              if (x->move_mode)
                printf (gettext ("created directory %s\n"), quotearg_style (shell_escape_always_quoting_style, dst_name));
              else
                emit_verbose (src_name, dst_name, 
                                                 ((void *)0)
                                                     );
            }
        }
      else
        {
          omitted_permissions = 0;




          if (x->set_security_context || x->preserve_security_context)
            if (! set_file_security_ctx (dst_name, 
                                                  0
                                                       , x))
              {
                if (x->require_preserve_context)
                  goto un_backup;
              }
        }


      if (x->one_file_system && parent && parent->st_dev != src_sb.st_dev)
        {


        }
      else
        {




          delayed_ok = copy_dir (src_name, dst_name, dst_dirfd, dst_relname,
                                 new_dst, &src_sb, dir, x,
                                 first_dir_created_per_command_line_arg,
                                 copy_into_self);
        }
    }
  else if (x->symbolic_link)
    {
      dest_is_symlink = 
                       1
                           ;
      if (*src_name != '/')
        {

          struct stat dot_sb;
          struct stat dst_parent_sb;
          char *dst_parent;
          
         _Bool 
              in_current_dir;

          dst_parent = dir_name (dst_relname);

          in_current_dir = ((dst_dirfd == 
                                         -100 
                                                  && (strcmp (".", dst_parent) == 0))



                            || stat (".", &dot_sb) != 0
                            || (fstatat (dst_dirfd, dst_parent, &dst_parent_sb,
                                         0) != 0)
                            || ((dot_sb).st_ino == (dst_parent_sb).st_ino && (dot_sb).st_dev == (dst_parent_sb).st_dev));
          free (dst_parent);

          if (! in_current_dir)
            {
              error (0, 0,
           gettext ("%s: can make relative symbolic links only in current directory"),
                     quotearg_n_style_colon (0, shell_escape_quoting_style, dst_name));
              goto un_backup;
            }
        }

      int err = force_symlinkat (src_name, dst_dirfd, dst_relname,
                                 x->unlink_dest_after_failed_open, -1);
      if (0 < err)
        {
          error (0, err, gettext ("cannot create symbolic link %s to %s"),
                 quotearg_n_style (0, shell_escape_always_quoting_style, dst_name), quotearg_n_style (1, shell_escape_always_quoting_style, src_name));
          goto un_backup;
        }
    }
  else if (x->hard_link
           && !(! 1 && 
                                          ((((
                                          src_mode
                                          )) & 0170000) == (0120000))
                
               && x->dereference == DEREF_NEVER))
    {
      
     _Bool 
          replace = (x->unlink_dest_after_failed_open
                      || x->interactive == I_ASK_USER);
      if (! create_hard_link (src_name, 
                                       -100
                                               , src_name,
                              dst_name, dst_dirfd, dst_relname,
                              replace, 
                                      0
                                           , dereference))
        goto un_backup;
    }
  else if (
          ((((
          src_mode
          )) & 0170000) == (0100000))
           
          || (x->copy_as_regular && !
                                     ((((
                                     src_mode
                                     )) & 0170000) == (0120000))
                                                       ))
    {
      copied_as_regular = 
                         1
                             ;
      if (! copy_reg (src_name, dst_name, dst_dirfd, dst_relname,
                      x, dst_mode_bits & 
                                        ((0400|0200|0100) | ((0400|0200|0100) >> 3) | (((0400|0200|0100) >> 3) >> 3))
                                                 ,
                      omitted_permissions, &new_dst, &src_sb))
        goto un_backup;
    }
  else if (
          ((((
          src_mode
          )) & 0170000) == (0010000))
                             )
    {




      mode_t mode = src_mode & ~omitted_permissions;
      if (mknodat (dst_dirfd, dst_relname, mode, 0) != 0)
        if (mkfifoat (dst_dirfd, dst_relname, mode & ~
                                                     0010000
                                                            ) != 0)
          {
            error (0, 
                     (*__errno_location ())
                          , gettext ("cannot create fifo %s"), quotearg_style (shell_escape_always_quoting_style, dst_name));
            goto un_backup;
          }
    }
  else if (
          ((((
          src_mode
          )) & 0170000) == (0060000)) 
                             || 
                                ((((
                                src_mode
                                )) & 0170000) == (0020000)) 
                                                   || 
                                                      ((((
                                                      src_mode
                                                      )) & 0170000) == (0140000))
                                                                         )
    {
      mode_t mode = src_mode & ~omitted_permissions;
      if (mknodat (dst_dirfd, dst_relname, mode, src_sb.st_rdev) != 0)
        {
          error (0, 
                   (*__errno_location ())
                        , gettext ("cannot create special file %s"),
                 quotearg_style (shell_escape_always_quoting_style, dst_name));
          goto un_backup;
        }
    }
  else if (
          ((((
          src_mode
          )) & 0170000) == (0120000))
                            )
    {
      char *src_link_val = areadlink_with_size (src_name, src_sb.st_size);
      dest_is_symlink = 
                       1
                           ;
      if (src_link_val == 
                         ((void *)0)
                             )
        {
          error (0, 
                   (*__errno_location ())
                        , gettext ("cannot read symbolic link %s"),
                 quotearg_style (shell_escape_always_quoting_style, src_name));
          goto un_backup;
        }

      int symlink_err = force_symlinkat (src_link_val, dst_dirfd, dst_relname,
                                         x->unlink_dest_after_failed_open, -1);
      if (0 < symlink_err && x->update && !new_dst && 
                                                     ((((
                                                     dst_sb.st_mode
                                                     )) & 0170000) == (0120000))
          
         && dst_sb.st_size == strlen (src_link_val))
        {




          char *dest_link_val =
            areadlinkat_with_size (dst_dirfd, dst_relname, dst_sb.st_size);
          if (dest_link_val)
            {
              if ((strcmp (dest_link_val, src_link_val) == 0))
                symlink_err = 0;
              free (dest_link_val);
            }
        }
      free (src_link_val);
      if (0 < symlink_err)
        {
          error (0, symlink_err, gettext ("cannot create symbolic link %s"),
                 quotearg_style (shell_escape_always_quoting_style, dst_name));
          goto un_backup;
        }

      if (x->preserve_security_context)
        restore_default_fscreatecon_or_die ();

      if (x->preserve_ownership)
        {


          if (1
              && (lchownat (dst_dirfd, dst_relname,
                            src_sb.st_uid, src_sb.st_gid)
                  != 0)
              && ! chown_failure_ok (x))
            {
              error (0, 
                       (*__errno_location ())
                            , gettext ("failed to preserve ownership for %s"),
                     dst_name);
              if (x->require_preserve)
                goto un_backup;
            }
          else
            {




            }
        }
    }
  else
    {
      error (0, 0, gettext ("%s has unknown file type"), quotearg_style (shell_escape_always_quoting_style, src_name));
      goto un_backup;
    }



  if (!new_dst && !x->copy_as_regular && !
                                         ((((
                                         src_mode
                                         )) & 0170000) == (0040000))
      
     && (x->set_security_context || x->preserve_security_context))
    {
      if (! set_file_security_ctx (dst_name, 
                                            0
                                                 , x))
        {
           if (x->require_preserve_context)
             goto un_backup;
        }
    }

  if (command_line_arg && x->dest_info)
    {


      struct stat sb;
      if (fstatat (dst_dirfd, dst_relname, &sb, 
                                               0x100
                                                                  ) == 0)
        record_file (x->dest_info, dst_relname, &sb);
    }



  if (x->hard_link && ! 
                       ((((
                       src_mode
                       )) & 0170000) == (0040000))
      
     && !(! 1 && 
                                     ((((
                                     src_mode
                                     )) & 0170000) == (0120000))
           
          && x->dereference == DEREF_NEVER))
    return delayed_ok;

  if (copied_as_regular)
    return delayed_ok;
  if (x->preserve_timestamps)
    {
      struct timespec timespec[2];
      timespec[0] = get_stat_atime (&src_sb);
      timespec[1] = get_stat_mtime (&src_sb);

      int utimensat_flags = dest_is_symlink ? 
                                             0x100 
                                                                 : 0;
      if (utimensat (dst_dirfd, dst_relname, timespec, utimensat_flags) != 0)
        {
          error (0, 
                   (*__errno_location ())
                        , gettext ("preserving times for %s"), quotearg_style (shell_escape_always_quoting_style, dst_name));
          if (x->require_preserve)
            return 
                  0
                       ;
        }
    }


  if (!dest_is_symlink && x->preserve_ownership
      && (new_dst || !(((src_sb).st_uid == (dst_sb).st_uid) && ((src_sb).st_gid == (dst_sb).st_gid))))
    {
      switch (set_owner (x, dst_name, dst_dirfd, dst_relname, -1,
                         &src_sb, new_dst, &dst_sb))
        {
        case -1:
          return 
                0
                     ;

        case 0:
          src_mode &= ~ (
                        04000 
                                | 
                                  02000 
                                          | 
                                            01000
                                                   );
          break;
        }
    }


  if (x->preserve_xattr && ! copy_attr (src_name, -1, dst_name, -1, x)
      && x->require_preserve_xattr)
    return 
          0
               ;


  if (dest_is_symlink)
    return delayed_ok;

  set_author (dst_name, -1, &src_sb);

  if (x->preserve_mode || x->move_mode)
    {
      if (copy_acl (src_name, -1, dst_name, -1, src_mode) != 0
          && x->require_preserve)
        return 
              0
                   ;
    }
  else if (x->set_mode)
    {
      if (set_acl (dst_name, -1, x->mode) != 0)
        return 
              0
                   ;
    }
  else if (x->explicit_no_preserve_mode && new_dst)
    {
      int default_permissions = 
                               ((((
                               src_mode
                               )) & 0170000) == (0040000)) 
                                                  || 
                                                     ((((
                                                     src_mode
                                                     )) & 0170000) == (0140000))
                                
                               ? 
                                 ((0400|0200|0100) | ((0400|0200|0100) >> 3) | (((0400|0200|0100) >> 3) >> 3)) 
                                           : (
                                             0400 
                                             | 
                                             0200 
                                             | 
                                             (0400 >> 3) 
                                             | 
                                             (0200 >> 3) 
                                             | 
                                             ((0400 >> 3) >> 3) 
                                             | 
                                             ((0200 >> 3) >> 3)
                                             );
      if (set_acl (dst_name, -1, default_permissions & ~cached_umask ()) != 0)
        return 
              0
                   ;
    }
  else
    {
      if (omitted_permissions)
        {
          omitted_permissions &= ~ cached_umask ();

          if (omitted_permissions && !restore_dst_mode)
            {






              if (new_dst && fstatat (dst_dirfd, dst_relname, &dst_sb,
                                     
                                    0x100
                                                       ) != 0)
                {
                  error (0, 
                           (*__errno_location ())
                                , gettext ("cannot stat %s"), quotearg_style (shell_escape_always_quoting_style, dst_name));
                  return 
                        0
                             ;
                }
              dst_mode = dst_sb.st_mode;
              if (omitted_permissions & ~dst_mode)
                restore_dst_mode = 
                                  1
                                      ;
            }
        }

      if (restore_dst_mode)
        {
          if (lchmodat (dst_dirfd, dst_relname, dst_mode | omitted_permissions)
              != 0)
            {
              error (0, 
                       (*__errno_location ())
                            , gettext ("preserving permissions for %s"),
                     quotearg_style (shell_escape_always_quoting_style, dst_name));
              if (x->require_preserve)
                return 
                      0
                           ;
            }
        }
    }

  return delayed_ok;

un_backup:

  if (x->preserve_security_context)
    restore_default_fscreatecon_or_die ();







  if (earlier_file == 
                     ((void *)0)
                         )
    forget_created (src_sb.st_ino, src_sb.st_dev);

  if (dst_backup)
    {
      char const *dst_relbackup = &dst_backup[dst_relname - dst_name];
      if (renameat (dst_dirfd, dst_relbackup, dst_dirfd, dst_relname) != 0)
        error (0, 
                 (*__errno_location ())
                      , gettext ("cannot un-backup %s"), quotearg_style (shell_escape_always_quoting_style, dst_name));
      else
        {
          if (x->verbose)
            printf (gettext ("%s -> %s (unbackup)\n"),
                    quotearg_n_style (0, shell_escape_always_quoting_style, dst_backup), quotearg_n_style (1, shell_escape_always_quoting_style, dst_name));
        }
    }
  return 
        0
             ;
}

__attribute__ ((__pure__))
static 
      _Bool

valid_options (const struct cp_options *co)
{
  
 ((void) sizeof ((
 ((unsigned int) (co->backup_type) <= numbered_backups)
 ) ? 1 : 0), __extension__ ({ if (
 ((unsigned int) (co->backup_type) <= numbered_backups)
 ) ; else __assert_fail (
 "VALID_BACKUP_TYPE (co->backup_type)"
 , "src/copy.c", 3087, __extension__ __PRETTY_FUNCTION__); }))
                                             ;
  
 ((void) sizeof ((
 ((co->sparse_mode) == SPARSE_NEVER || (co->sparse_mode) == SPARSE_AUTO || (co->sparse_mode) == SPARSE_ALWAYS)
 ) ? 1 : 0), __extension__ ({ if (
 ((co->sparse_mode) == SPARSE_NEVER || (co->sparse_mode) == SPARSE_AUTO || (co->sparse_mode) == SPARSE_ALWAYS)
 ) ; else __assert_fail (
 "VALID_SPARSE_MODE (co->sparse_mode)"
 , "src/copy.c", 3088, __extension__ __PRETTY_FUNCTION__); }))
                                             ;
  
 ((void) sizeof ((
 ((co->reflink_mode) == REFLINK_NEVER || (co->reflink_mode) == REFLINK_AUTO || (co->reflink_mode) == REFLINK_ALWAYS)
 ) ? 1 : 0), __extension__ ({ if (
 ((co->reflink_mode) == REFLINK_NEVER || (co->reflink_mode) == REFLINK_AUTO || (co->reflink_mode) == REFLINK_ALWAYS)
 ) ; else __assert_fail (
 "VALID_REFLINK_MODE (co->reflink_mode)"
 , "src/copy.c", 3089, __extension__ __PRETTY_FUNCTION__); }))
                                               ;
  
 ((void) sizeof ((
 !(co->hard_link && co->symbolic_link)
 ) ? 1 : 0), __extension__ ({ if (
 !(co->hard_link && co->symbolic_link)
 ) ; else __assert_fail (
 "!(co->hard_link && co->symbolic_link)"
 , "src/copy.c", 3090, __extension__ __PRETTY_FUNCTION__); }))
                                               ;
  
 ((void) sizeof ((
 ! (co->reflink_mode == REFLINK_ALWAYS && co->sparse_mode != SPARSE_AUTO)
 ) ? 1 : 0), __extension__ ({ if (
 ! (co->reflink_mode == REFLINK_ALWAYS && co->sparse_mode != SPARSE_AUTO)
 ) ; else __assert_fail (
 "! (co->reflink_mode == REFLINK_ALWAYS && co->sparse_mode != SPARSE_AUTO)"
 , "src/copy.c", 3091, __extension__ __PRETTY_FUNCTION__); }))

                                              
                                             ;
  return 
        1
            ;
}
extern 
      _Bool

copy (char const *src_name, char const *dst_name,
      int dst_dirfd, char const *dst_relname,
      int nonexistent_dst, const struct cp_options *options,
      
     _Bool 
          *copy_into_self, 
                           _Bool 
                                *rename_succeeded)
{
  
 ((void) sizeof ((
 valid_options (options)
 ) ? 1 : 0), __extension__ ({ if (
 valid_options (options)
 ) ; else __assert_fail (
 "valid_options (options)"
 , "src/copy.c", 3114, __extension__ __PRETTY_FUNCTION__); }))
                                 ;
  top_level_src_name = src_name;
  top_level_dst_name = dst_name;

  
 _Bool 
      first_dir_created_per_command_line_arg = 
                                               0
                                                    ;
  return copy_internal (src_name, dst_name, dst_dirfd, dst_relname,
                        nonexistent_dst, 
                                        ((void *)0)
                                            , 
                                              ((void *)0)
                                                  ,
                        options, 
                                1
                                    ,
                        &first_dir_created_per_command_line_arg,
                        copy_into_self, rename_succeeded);
}



extern void
cp_options_default (struct cp_options *x)
{
  memset (x, 0, sizeof *x);
  x->chown_privileges = x->owner_privileges = (geteuid () == 0);

  x->rename_errno = -1;
}





extern 
      _Bool

chown_failure_ok (struct cp_options const *x)
{




  return ((
          (*__errno_location ()) 
                == 
                   1 
                         || 
                            (*__errno_location ()) 
                                  == 
                                     22
                                           ) && !x->chown_privileges);
}





static 
      _Bool

owner_failure_ok (struct cp_options const *x)
{
  return ((
          (*__errno_location ()) 
                == 
                   1 
                         || 
                            (*__errno_location ()) 
                                  == 
                                     22
                                           ) && !x->owner_privileges);
}







extern mode_t
cached_umask (void)
{
  static mode_t mask = (mode_t) -1;
  if (mask == (mode_t) -1)
    {
      mask = umask (0);
      umask (mask);
    }
  return mask;
}
