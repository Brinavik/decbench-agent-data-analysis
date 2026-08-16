
       












       
       
       
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


       

       
       




extern struct quoting_options quote_quoting_options;





char const *quote_n_mem (int n, char const *arg, size_t argsize);




char const *quote_mem (char const *arg, size_t argsize);



char const *quote_n (int n, char const *arg);



char const *quote (char const *arg);
ptrdiff_t argmatch (char const *arg, char const *const *arglist,
                    void const *vallist, size_t valsize) __attribute__ ((__pure__));

ptrdiff_t argmatch_exact (char const *arg, char const *const *arglist)
  __attribute__ ((__pure__));
typedef void (*argmatch_exit_fn) (void);
extern argmatch_exit_fn argmatch_die;



void argmatch_invalid (char const *context, char const *value,
                       ptrdiff_t problem);
void argmatch_valid (char const *const *arglist,
                     void const *vallist, size_t valsize);
ptrdiff_t __xargmatch_internal (char const *context,
                                char const *arg, char const *const *arglist,
                                void const *vallist, size_t valsize,
                                argmatch_exit_fn exit_fn,
                                
                               _Bool 
                                    allow_abbreviation);
char const *argmatch_to_argument (void const *value,
                                  char const *const *arglist,
                                  void const *vallist, size_t valsize)
  __attribute__ ((__pure__));
       
intmax_t xdectoimax (char const *n_str, intmax_t min, intmax_t max, char const *suffixes, char const *err, int err_exit) __attribute__ ((__nonnull__ (1, 5)));
uintmax_t xdectoumax (char const *n_str, uintmax_t min, uintmax_t max, char const *suffixes, char const *err, int err_exit) __attribute__ ((__nonnull__ (1, 5)));

intmax_t xnumtoimax (char const *n_str, int base, intmax_t min, intmax_t max, char const *suffixes, char const *err, int err_exit) __attribute__ ((__nonnull__ (1, 6)));
uintmax_t xnumtoumax (char const *n_str, int base, uintmax_t min, uintmax_t max, char const *suffixes, char const *err, int err_exit) __attribute__ ((__nonnull__ (1, 6)));
       
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

       
       

int open_safer (char const *, int, ...);
int creat_safer (char const *, mode_t);


int openat_safer (int, char const *, int, ...);
       




enum strtol_error
  {
    LONGINT_OK = 0,



    LONGINT_OVERFLOW = 1,
    LONGINT_INVALID_SUFFIX_CHAR = 2,

    LONGINT_INVALID_SUFFIX_CHAR_WITH_OVERFLOW = (LONGINT_INVALID_SUFFIX_CHAR
                                                 | LONGINT_OVERFLOW),
    LONGINT_INVALID = 4
  };
typedef enum strtol_error strtol_error;




strtol_error xstrtol (const char *, char **, int, long int *, const char *);
strtol_error xstrtoul (const char *, char **, int, unsigned long int *, const char *);
strtol_error xstrtoll (const char *, char **, int, long long int *, const char *);
strtol_error xstrtoull (const char *, char **, int, unsigned long long int *, const char *);
strtol_error xstrtoimax (const char *, char **, int, intmax_t *, const char *);
strtol_error xstrtoumax (const char *, char **, int, uintmax_t *, const char *);
enum
{




  human_ceiling = 0,

  human_round_to_nearest = 1,

  human_floor = 2,




  human_group_digits = 4,


  human_suppress_point_zero = 8,


  human_autoscale = 16,


  human_base_1024 = 32,


  human_space_before_unit = 64,


  human_SI = 128,


  human_B = 256
};

char *human_readable (uintmax_t, char *, int, uintmax_t, uintmax_t);

enum strtol_error human_options (char const *, int *, uintmax_t *);

struct randread_source;

int randread_free (struct randread_source *) __attribute__ ((__nonnull__ ));
struct randread_source *randread_new (char const *, size_t)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (randread_free, 1)));
void randread (struct randread_source *, void *, size_t)
  __attribute__ ((__nonnull__ ));
void randread_set_handler (struct randread_source *, void (*) (void const *))
  __attribute__ ((__nonnull__ ));
void randread_set_handler_arg (struct randread_source *, void const *)
  __attribute__ ((__nonnull__ (1)));



typedef uintmax_t randint;


struct randint_source;

void randint_free (struct randint_source *) __attribute__ ((__nonnull__ ));
int randint_all_free (struct randint_source *) __attribute__ ((__nonnull__ ));
struct randint_source *randint_new (struct randread_source *)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (randint_free, 1)))
  __attribute__ ((__nonnull__ )) __attribute__ ((__returns_nonnull__));
struct randint_source *randint_all_new (char const *, size_t)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (randint_all_free, 1)));
struct randread_source *randint_get_source (struct randint_source const *)
  __attribute__ ((__nonnull__ )) __attribute__ ((__pure__));
randint randint_genmax (struct randint_source *, randint genmax)
  __attribute__ ((__nonnull__ ));



static inline randint
randint_choose (struct randint_source *s, randint choices)
{
  return randint_genmax (s, choices - 1);
}
       






extern int renameatu (int, char const *, int, char const *, unsigned int);


enum { DEFAULT_PASSES = 3 };



enum { VERBOSE_UPDATE = 5 };



enum { SECTOR_SIZE = 512 };
enum { SECTOR_MASK = SECTOR_SIZE - 1 };
_Static_assert (0 < SECTOR_SIZE && (SECTOR_SIZE & SECTOR_MASK) == 0, "verify (" "0 < SECTOR_SIZE && (SECTOR_SIZE & SECTOR_MASK) == 0" ")");

enum remove_method
{
  remove_none = 0,
  remove_unlink,
  remove_wipe,
  remove_wipesync
};

static char const *const remove_args[] =
{
  "unlink", "wipe", "wipesync", 
                               ((void *)0)

};

static enum remove_method const remove_methods[] =
{
  remove_unlink, remove_wipe, remove_wipesync
};

struct Options
{
  
 _Bool 
      force;
  size_t n_iterations;
  off_t size;
  enum remove_method remove_file;
  
 _Bool 
      verbose;
  
 _Bool 
      exact;
  
 _Bool 
      zero_fill;
};



enum
{
  RANDOM_SOURCE_OPTION = 0x7f + 1
};

static struct option const long_opts[] =
{
  {"exact", 
           0
                      , 
                        ((void *)0)
                            , 'x'},
  {"force", 
           0
                      , 
                        ((void *)0)
                            , 'f'},
  {"iterations", 
                1
                                 , 
                                   ((void *)0)
                                       , 'n'},
  {"size", 
          1
                           , 
                             ((void *)0)
                                 , 's'},
  {"random-source", 
                   1
                                    , 
                                      ((void *)0)
                                          , RANDOM_SOURCE_OPTION},
  {"remove", 
            2
                             , 
                               ((void *)0)
                                   , 'u'},
  {"verbose", 
             0
                        , 
                          ((void *)0)
                              , 'v'},
  {"zero", 
          0
                     , 
                       ((void *)0)
                           , 'z'},
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
      printf (gettext ("Usage: %s [OPTION]... FILE...\n"), program_name);
      fputs_unlocked (gettext ("Overwrite the specified FILE(s) repeatedly, in order to make it harder\nfor even very expensive hardware probing to recover the data.\n"),
     stdout
     )


           ;
      fputs_unlocked (gettext ("\nIf FILE is -, shred standard output.\n"),
     stdout
     )


           ;

      emit_mandatory_arg_note ();

      printf (gettext ("  -f, --force    change permissions to allow writing if necessary\n  -n, --iterations=N  overwrite N times instead of the default (%d)\n      --random-source=FILE  get random bytes from FILE\n  -s, --size=N   shred this many bytes (suffixes like K, M, G accepted)\n")




  , DEFAULT_PASSES);
      fputs_unlocked (gettext ("  -u             deallocate and remove file after overwriting\n      --remove[=HOW]  like -u but give control on HOW to delete;  See below\n  -v, --verbose  show progress\n  -x, --exact    do not round file sizes up to the next full block;\n                   this is the default for non-regular files\n  -z, --zero     add a final overwrite with zeros to hide shredding\n"),
     stdout
     )






           ;
      fputs_unlocked (gettext ("      --help        display this help and exit\n"),
     stdout
     );
      fputs_unlocked (gettext ("      --version     output version information and exit\n"),
     stdout
     );
      fputs_unlocked (gettext ("\nDelete FILE(s) if --remove (-u) is specified.  The default is not to remove\nthe files because it is common to operate on device files like /dev/hda,\nand those files usually should not be removed.\nThe optional HOW parameter indicates how to remove a directory entry:\n'unlink' => use a standard unlink call.\n'wipe' => also first obfuscate bytes in the name.\n'wipesync' => also sync each obfuscated byte to the device.\nThe default mode is 'wipesync', but note it can be expensive.\n\n"),
     stdout
     )
           ;
      fputs_unlocked (gettext ("CAUTION: shred assumes the file system and hardware overwrite data in place.\nAlthough this is common, many platforms operate otherwise.  Also, backups\nand mirrors may contain unremovable copies that will let a shredded file\nbe recovered later.  See the GNU coreutils manual for details.\n"),
     stdout
     )




           ;
      emit_ancillary_info ("shred");
    }
  exit (status);
}




static 
      _Bool

periodic_pattern (int type)
{
  if (type <= 0)
    return 
          0
               ;

  unsigned char r[3];
  unsigned int bits = type & 0xfff;

  bits |= bits << 12;
  r[0] = (bits >> 4) & 255;
  r[1] = (bits >> 8) & 255;
  r[2] = bits & 255;

  return (r[0] != r[1]) || (r[0] != r[2]);
}







static void
fillpattern (int type, unsigned char *r, size_t size)
{
  size_t i;
  unsigned int bits = type & 0xfff;

  bits |= bits << 12;
  r[0] = (bits >> 4) & 255;
  r[1] = (bits >> 8) & 255;
  r[2] = bits & 255;
  for (i = 3; i <= size / 2; i *= 2)
    memcpy (r + i, r, i);
  if (i < size)
    memcpy (r + i, r, size - i);


  if (type & 0x1000)
    for (i = 0; i < size; i += SECTOR_SIZE)
      r[i] ^= 0x80;
}






static void
passname (unsigned char const *data, char name[7])
{
  if (data)
    sprintf (name, "%02x%02x%02x", data[0], data[1], data[2]);
  else
    memcpy (name, "random", 7);
}



static 
      _Bool

ignorable_sync_errno (int errno_val)
{
  return (errno_val == 
                      22
          
         || errno_val == 
                         9

          
         || errno_val == 
                         21
                               );
}







static int
dosync (int fd, char const *qname)
{
  int err;


  if (fdatasync (fd) == 0)
    return 0;
  err = 
       (*__errno_location ())
            ;
  if ( ! ignorable_sync_errno (err))
    {
      error (0, err, gettext ("%s: fdatasync failed"), qname);
      
     (*__errno_location ()) 
           = err;
      return -1;
    }


  if (fsync (fd) == 0)
    return 0;
  err = 
       (*__errno_location ())
            ;
  if ( ! ignorable_sync_errno (err))
    {
      error (0, err, gettext ("%s: fsync failed"), qname);
      
     (*__errno_location ()) 
           = err;
      return -1;
    }

  sync ();
  return 0;
}



static void
direct_mode (int fd, 
                    _Bool 
                         enable)
{
  if (
     040000
             )
    {
      int fd_flags = 
                    rpl_fcntl 
                          (fd, 
                               3
                                      );
      if (0 < fd_flags)
        {
          int new_flags = (enable
                           ? (fd_flags | 
                                        040000
                                                )
                           : (fd_flags & ~
                                         040000
                                                 ));
          if (new_flags != fd_flags)
            
           rpl_fcntl 
                 (fd, 
                      4
                             , new_flags);
        }
    }





}


static 
      _Bool

dorewind (int fd, struct stat const *st)
{
  if (
     ((((
     st->st_mode
     )) & 0170000) == (0020000))
                          )
    {




      struct mtop op;
      op.mt_op = 
                6
                     ;
      op.mt_count = 1;
      if (ioctl (fd, 
                    (((1U) << (((0 +8)+8)+14)) | ((('m')) << (0 +8)) | (((1)) << 0) | ((((sizeof(struct mtop)))) << ((0 +8)+8)))
                            , &op) == 0)
        return 
              1
                  ;

    }
  off_t offset = lseek (fd, 0, 
                              0
                                      );
  if (0 < offset)
    
   (*__errno_location ()) 
         = 
           22
                 ;
  return offset == 0;
}



static 
      _Bool

known (off_t size)
{
  return 0 <= size;
}
static int
dopass (int fd, struct stat const *st, char const *qname, off_t *sizep,
        int type, struct randread_source *s,
        unsigned long int k, unsigned long int n)
{
  off_t size = *sizep;
  off_t offset;
  time_t thresh ;
  time_t now = 0;
  size_t lim;
  size_t soff;
  ssize_t ssize;


  size_t page_size = getpagesize ();


  _Static_assert ((60 * 1024) % 3 == 0, "verify (" "PERIODIC_OUTPUT_SIZE % 3 == 0" ")");
  size_t output_size = periodic_pattern (type)
                       ? (60 * 1024) : (64 * 1024);

  unsigned char *pbuf = xalignalloc (page_size, (((output_size + 2) / 3) * 3));

  char pass_string[7];
  
 _Bool 
      write_error = 
                    0
                         ;
  
 _Bool 
      other_error = 
                    0
                         ;


  char previous_offset_buf[((2 * sizeof (uintmax_t) * 8 * 146 / 485 + 1) * (
                          16 
                          + 1) - 
                          16 
                          + 1 + 3) + 1];
  char const *previous_human_offset;




  
 _Bool 
      try_without_directio = 0 < size && size < output_size;
  if (! try_without_directio)
    direct_mode (fd, 
                    1
                        );

  if (! dorewind (fd, st))
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("%s: cannot rewind"), qname);
      other_error = 
                   1
                       ;
      goto free_pattern_mem;
    }


  if (type >= 0)
    {
      lim = known (size) && size < (((output_size + 2) / 3) * 3) ? size : (((output_size + 2) / 3) * 3);
      fillpattern (type, pbuf, lim);
      passname (pbuf, pass_string);
    }
  else
    {
      passname (0, pass_string);
    }


  if (n)
    {
      error (0, 0, gettext ("%s: pass %lu/%lu (%s)..."), qname, k, n, pass_string);
      thresh = time (
                    ((void *)0)
                        ) + VERBOSE_UPDATE;
      previous_human_offset = "";
    }

  offset = 0;
  while (
        1
            )
    {

      lim = output_size;
      if (known (size) && size - offset < output_size)
        {
          if (size < offset)
            break;
          lim = size - offset;
          if (!lim)
            break;
        }
      if (type < 0)
        randread (s, pbuf, lim);

      for (soff = 0; soff < lim; soff += ssize)
        {
          ssize = write (fd, pbuf + soff, lim - soff);
          if (0 < ssize)
            ((ssize <= lim - soff) ? (void) 0 : __builtin_unreachable ());
          else
            {
              if (! known (size) && (ssize == 0 || 
                                                  (*__errno_location ()) 
                                                        == 
                                                           28
                                                                 ))
                {

                  if (soff <= ((off_t) (! (! ((off_t) 0 < (off_t) -1)) ? (off_t) -1 : ((((off_t) 1 << ((sizeof (off_t) * 8) - 2)) - 1) * 2 + 1))) - offset)
                    *sizep = size = offset + soff;
                  break;
                }
              else
                {
                  int errnum = 
                              (*__errno_location ())
                                   ;
                  char buf[((((((sizeof (uintmax_t) * 8) - (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1))) * 146 + 484) / 485) + (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1))) + 1)];





                  if (! try_without_directio && 
                                               (*__errno_location ()) 
                                                     == 
                                                        22
                                                              )
                    {
                      direct_mode (fd, 
                                      0
                                           );
                      ssize = 0;
                      try_without_directio = 
                                            1
                                                ;
                      continue;
                    }
                  error (0, errnum, gettext ("%s: error writing at offset %s"),
                         qname, umaxtostr (offset + soff, buf));






                  _Static_assert ((60 * 1024) % SECTOR_SIZE == 0, "verify (" "PERIODIC_OUTPUT_SIZE % SECTOR_SIZE == 0" ")");
                  _Static_assert ((64 * 1024) % SECTOR_SIZE == 0, "verify (" "NONPERIODIC_OUTPUT_SIZE % SECTOR_SIZE == 0" ")");
                  if (errnum == 
                               5 
                                   && known (size)
                      && (soff | SECTOR_MASK) < lim)
                    {
                      size_t soff1 = (soff | SECTOR_MASK) + 1;
                      if (lseek (fd, offset + soff1, 
                                                    0
                                                            ) != -1)
                        {

                          ssize = soff1 - soff;
                          write_error = 
                                       1
                                           ;
                          continue;
                        }
                      error (0, 
                               (*__errno_location ())
                                    , gettext ("%s: lseek failed"), qname);
                    }
                  other_error = 
                               1
                                   ;
                  goto free_pattern_mem;
                }
            }
        }



      if (((off_t) (! (! ((off_t) 0 < (off_t) -1)) ? (off_t) -1 : ((((off_t) 1 << ((sizeof (off_t) * 8) - 2)) - 1) * 2 + 1))) - offset < soff)
        {
          error (0, 0, gettext ("%s: file too large"), qname);
          other_error = 
                       1
                           ;
          goto free_pattern_mem;
        }

      offset += soff;

      
     _Bool 
          done = offset == size;


      if (n && ((done && *previous_human_offset)
                || thresh <= (now = time (
                                         ((void *)0)
                                             ))))
        {
          char offset_buf[((2 * sizeof (uintmax_t) * 8 * 146 / 485 + 1) * (
                         16 
                         + 1) - 
                         16 
                         + 1 + 3) + 1];
          char size_buf[((2 * sizeof (uintmax_t) * 8 * 146 / 485 + 1) * (
                       16 
                       + 1) - 
                       16 
                       + 1 + 3) + 1];
          int human_progress_opts = (human_autoscale | human_SI
                                     | human_base_1024 | human_B);
          char const *human_offset
            = human_readable (offset, offset_buf,
                              human_floor | human_progress_opts, 1, 1);

          if (done || !(strcmp (previous_human_offset, human_offset) == 0))
            {
              if (! known (size))
                error (0, 0, gettext ("%s: pass %lu/%lu (%s)...%s"),
                       qname, k, n, pass_string, human_offset);
              else
                {
                  uintmax_t off = offset;
                  int percent = (size == 0
                                 ? 100
                                 : (off <= ((uintmax_t) (! (! ((uintmax_t) 0 < (uintmax_t) -1)) ? (uintmax_t) -1 : ((((uintmax_t) 1 << ((sizeof (uintmax_t) * 8) - 2)) - 1) * 2 + 1))) / 100
                                    ? off * 100 / size
                                    : off / (size / 100)));
                  char const *human_size
                    = human_readable (size, size_buf,
                                      human_ceiling | human_progress_opts,
                                      1, 1);
                  if (done)
                    human_offset = human_size;
                  error (0, 0, gettext ("%s: pass %lu/%lu (%s)...%s/%s %d%%"),
                         qname, k, n, pass_string, human_offset, human_size,
                         percent);
                }

              strcpy (previous_offset_buf, human_offset);
              previous_human_offset = previous_offset_buf;
              thresh = now + VERBOSE_UPDATE;
              if (dosync (fd, qname) != 0)
                {
                  if (
                     (*__errno_location ()) 
                           != 
                              5
                                 )
                    {
                      other_error = 
                                   1
                                       ;
                      goto free_pattern_mem;
                    }
                  write_error = 
                               1
                                   ;
                }
            }
        }
    }


  if (dosync (fd, qname) != 0)
    {
      if (
         (*__errno_location ()) 
               != 
                  5
                     )
        {
          other_error = 
                       1
                           ;
          goto free_pattern_mem;
        }
      write_error = 
                   1
                       ;
    }

free_pattern_mem:
  alignfree (pbuf);

  return other_error ? -1 : write_error;
}
static int const
  patterns[] =
{
  -2,
  2, 0x000, 0xFFF,
  2, 0x555, 0xAAA,
  -1,
  6, 0x249, 0x492, 0x6DB, 0x924, 0xB6D, 0xDB6,
  12, 0x111, 0x222, 0x333, 0x444, 0x666, 0x777,
  0x888, 0x999, 0xBBB, 0xCCC, 0xDDD, 0xEEE,
  -1,

  8, 0x1000, 0x1249, 0x1492, 0x16DB, 0x1924, 0x1B6D, 0x1DB6, 0x1FFF,
  14, 0x1111, 0x1222, 0x1333, 0x1444, 0x1555, 0x1666, 0x1777,
  0x1888, 0x1999, 0x1AAA, 0x1BBB, 0x1CCC, 0x1DDD, 0x1EEE,
  -1,
  0
};







static void
genpattern (int *dest, size_t num, struct randint_source *s)
{
  size_t randpasses;
  int const *p;
  int *d;
  size_t n;
  size_t accum, top, swap;
  int k;

  if (!num)
    return;


  p = patterns;
  randpasses = 0;
  d = dest;
  n = num;

  while (
        1
            )
    {
      k = *p++;
      if (!k)
        {
          p = patterns;
        }
      else if (k < 0)
        {
          k = -k;
          if ((size_t) k >= n)
            {
              randpasses += n;
              break;
            }
          randpasses += k;
          n -= k;
        }
      else if ((size_t) k <= n)
        {
          memcpy (d, p, k * sizeof (int));
          p += k;
          d += k;
          n -= k;
        }
      else if (n < 2 || 3 * n < (size_t) k)
        {
          randpasses += n;
          break;
        }
      else
        {
          do
            {
              if (n == (size_t) k || randint_choose (s, k) < n)
                {
                  *d++ = *p;
                  n--;
                }
              p++;
              k--;
            }
          while (n);
          break;
        }
    }
  top = num - randpasses;
  randpasses--;
  accum = randpasses;
  for (n = 0; n < num; n++)
    {
      if (accum <= randpasses)
        {
          accum += num - 1;
          dest[top++] = dest[n];
          dest[n] = -1;
        }
      else
        {
          swap = n + randint_choose (s, top - n);
          k = dest[n];
          dest[n] = dest[swap];
          dest[swap] = k;
        }
      accum -= randpasses;
    }

}





static 
      _Bool

do_wipefd (int fd, char const *qname, struct randint_source *s,
           struct Options const *flags)
{
  size_t i;
  struct stat st;
  off_t size;
  off_t i_size = 0;
  unsigned long int n;
  int *passarray;
  
 _Bool 
      ok = 
           1
               ;
  struct randread_source *rs;

  n = 0;
  if (flags->verbose)
    n = flags->n_iterations + flags->zero_fill;

  if (fstat (fd, &st))
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("%s: fstat failed"), qname);
      return 
            0
                 ;
    }




  if ((
      ((((
      st.st_mode
      )) & 0170000) == (0020000)) 
                           && isatty (fd))
      || 
        ((((
        st.st_mode
        )) & 0170000) == (0010000))
      
     || 
        ((((
        st.st_mode
        )) & 0170000) == (0140000))
                             )
    {
      error (0, 0, gettext ("%s: invalid file type"), qname);
      return 
            0
                 ;
    }
  else if (
          ((((
          st.st_mode
          )) & 0170000) == (0100000)) 
                               && st.st_size < 0)
    {
      error (0, 0, gettext ("%s: file has negative size"), qname);
      return 
            0
                 ;
    }


  passarray = xnmalloc (flags->n_iterations, sizeof *passarray);

  size = flags->size;
  if (size == -1)
    {
      if (
         ((((
         st.st_mode
         )) & 0170000) == (0100000))
                             )
        {
          size = st.st_size;

          if (! flags->exact)
            {

              off_t remainder = size % ((0 < (st).st_blksize && (st).st_blksize <= ((size_t)-1) / 8 + 1) ? (st).st_blksize : 
                                      512
                                      );
              if (size && size < ((0 < (st).st_blksize && (st).st_blksize <= ((size_t)-1) / 8 + 1) ? (st).st_blksize : 
                                512
                                ))
                i_size = size;
              if (remainder != 0)
                {
                  off_t size_incr = ((0 < (st).st_blksize && (st).st_blksize <= ((size_t)-1) / 8 + 1) ? (st).st_blksize : 
                                   512
                                   ) - remainder;
                  size += 
                         (((
                         size_incr
                         )<(
                         ((off_t) (! (! ((off_t) 0 < (off_t) -1)) ? (off_t) -1 : ((((off_t) 1 << ((sizeof (off_t) * 8) - 2)) - 1) * 2 + 1))) - size
                         ))?(
                         size_incr
                         ):(
                         ((off_t) (! (! ((off_t) 0 < (off_t) -1)) ? (off_t) -1 : ((((off_t) 1 << ((sizeof (off_t) * 8) - 2)) - 1) * 2 + 1))) - size
                         ))
                                                          ;
                }
            }
        }
      else
        {



          size = lseek (fd, 0, 
                              2
                                      );
          if (size <= 0)
            {


              size = -1;
            }
        }
    }
  else if (
          ((((
          st.st_mode
          )) & 0170000) == (0100000))
           
          && st.st_size < 
                          (((
                          ((0 < (st).st_blksize && (st).st_blksize <= ((size_t)-1) / 8 + 1) ? (st).st_blksize : 
                          512
                          )
                          )<(
                          size
                          ))?(
                          ((0 < (st).st_blksize && (st).st_blksize <= ((size_t)-1) / 8 + 1) ? (st).st_blksize : 
                          512
                          )
                          ):(
                          size
                          ))
                                                     )
    i_size = st.st_size;


  genpattern (passarray, flags->n_iterations, s);

  rs = randint_get_source (s);

  while (
        1
            )
    {
      off_t pass_size;
      unsigned long int pn = n;

      if (i_size)
        {
          pass_size = i_size;
          i_size = 0;
          pn = 0;
        }
      else if (size)
        {
          pass_size = size;
          size = 0;
        }



      else
        break;

      for (i = 0; i < flags->n_iterations + flags->zero_fill; i++)
        {
          int err = 0;
          int type = i < flags->n_iterations ? passarray[i] : 0;

          err = dopass (fd, &st, qname, &pass_size, type, rs, i + 1, pn);

          if (err)
            {
              ok = 
                  0
                       ;
              if (err < 0)
                goto wipefd_out;
            }
        }
    }






  if (flags->remove_file && ftruncate (fd, 0) != 0
      && (
         ((((
         st.st_mode
         )) & 0170000) == (0100000)) 
                              || 
                                 ((
                                 &st
                                 )->st_mode - (
                                 &st
                                 )->st_mode)
                                                  ))
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("%s: error truncating"), qname);
      ok = 
          0
               ;
      goto wipefd_out;
    }

wipefd_out:
  free (passarray);
  return ok;
}


static 
      _Bool

wipefd (int fd, char const *qname, struct randint_source *s,
        struct Options const *flags)
{
  int fd_flags = 
                rpl_fcntl 
                      (fd, 
                           3
                                  );

  if (fd_flags < 0)
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("%s: fcntl failed"), qname);
      return 
            0
                 ;
    }
  if (fd_flags & 
                02000
                        )
    {
      error (0, 0, gettext ("%s: cannot shred append-only file descriptor"), qname);
      return 
            0
                 ;
    }
  return do_wipefd (fd, qname, s, flags);
}




static char const nameset[] =
"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_.";






static 
      _Bool

incname (char *name, size_t len)
{
  while (len--)
    {
      char const *p = strchr (nameset, name[len]);



      
     ((void) sizeof ((
     p
     ) ? 1 : 0), __extension__ ({ if (
     p
     ) ; else __assert_fail (
     "p"
     , "src/shred.c", 1000, __extension__ __PRETTY_FUNCTION__); }))
               ;


      if (p[1])
        {
          name[len] = p[1];
          return 
                1
                    ;
        }


      name[len] = nameset[0];
    }

  return 
        0
             ;
}
static 
      _Bool

wipename (char *oldname, char const *qoldname, struct Options const *flags)
{
  char *newname = xstrdup (oldname);
  char *base = last_component (newname);
  char *dir = dir_name (newname);
  char *qdir = xstrdup (quotearg_n_style_colon (0, shell_escape_quoting_style, dir));
  
 _Bool 
      first = 
              1
                  ;
  
 _Bool 
      ok = 
           1
               ;
  int dir_fd = -1;

  if (flags->remove_file == remove_wipesync)
    dir_fd = open_safer (dir, 
                       00 
                                | 
                                  0200000 
                                              | 
                                                0400 
                                                         | 
                                                           04000
                                                                     );

  if (flags->verbose)
    error (0, 0, gettext ("%s: removing"), qoldname);

  if (flags->remove_file != remove_unlink)
    for (size_t len = base_len (base); len != 0; len--)
      {
        memset (base, nameset[0], len);
        base[len] = 0;
        
       _Bool 
            rename_ok;
        while (! (rename_ok = (renameatu (
                                         -100
                                                 , oldname, 
                                                            -100
                                                                    , newname,
                                          
                                         (1 << 0)
                                                         )
                               == 0))
               && 
                 (*__errno_location ()) 
                       == 
                          17 
                                 && incname (base, len))
          continue;
        if (rename_ok)
          {
            if (0 <= dir_fd && dosync (dir_fd, qdir) != 0)
              ok = 
                  0
                       ;
            if (flags->verbose)
              {




                char const *old = first ? qoldname : oldname;
                error (0, 0,
                       gettext ("%s: renamed to %s"), old, newname);
                first = 
                       0
                            ;
              }
            memcpy (oldname + (base - newname), base, len + 1);
          }
      }

  if (unlink (oldname) != 0)
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("%s: failed to remove"), qoldname);
      ok = 
          0
               ;
    }
  else if (flags->verbose)
    error (0, 0, gettext ("%s: removed"), qoldname);
  if (0 <= dir_fd)
    {
      if (dosync (dir_fd, qdir) != 0)
        ok = 
            0
                 ;
      if (close (dir_fd) != 0)
        {
          error (0, 
                   (*__errno_location ())
                        , gettext ("%s: failed to close"), qdir);
          ok = 
              0
                   ;
        }
    }
  free (newname);
  free (dir);
  free (qdir);
  return ok;
}
static 
      _Bool

wipefile (char *name, char const *qname,
          struct randint_source *s, struct Options const *flags)
{
  
 _Bool 
      ok;
  int fd;

  fd = open_safer (name, 
                  01 
                           | 
                             0400 
                                      | 
                                        0
                                                );
  if (fd < 0
      && (
         (*__errno_location ()) 
               == 
                  13 
                         && flags->force)
      && chmod (name, 
                     0200
                            ) == 0)
    fd = open_safer (name, 
                    01 
                             | 
                               0400 
                                        | 
                                          0
                                                  );
  if (fd < 0)
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("%s: failed to open for writing"), qname);
      return 
            0
                 ;
    }

  ok = do_wipefd (fd, qname, s, flags);
  if (close (fd) != 0)
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("%s: failed to close"), qname);
      ok = 
          0
               ;
    }
  if (ok && flags->remove_file)
    ok = wipename (name, qname, flags);
  return ok;
}



static struct randint_source *randint_source;




static void
clear_random_data (void)
{
  randint_all_free (randint_source);
}


int
main (int argc, char **argv)
{
  
 _Bool 
      ok = 
           1
               ;
  struct Options flags = { 0, };
  char **file;
  int n_files;
  int c;
  int i;
  char const *random_source = 
                             ((void *)0)
                                 ;

  ;
  set_program_name (argv[0]);
  setlocale (
            6
                  , "");
  bindtextdomain ("coreutils", "/usr/local/share/locale");
  textdomain ("coreutils");

  atexit (close_stdout);

  flags.n_iterations = DEFAULT_PASSES;
  flags.size = -1;

  while ((c = getopt_long (argc, argv, "fn:s:uvxz", long_opts, 
                                                              ((void *)0)
                                                                  )) != -1)
    {
      switch (c)
        {
        case 'f':
          flags.force = 
                       1
                           ;
          break;

        case 'n':
          flags.n_iterations = xdectoumax (optarg, 0,
                                           
                                          ((((0x7fffffffffffffffL * 2UL + 1UL))<((18446744073709551615UL) 
                                          / sizeof (int)
                                          ))?((0x7fffffffffffffffL * 2UL + 1UL)):((18446744073709551615UL) 
                                          / sizeof (int)
                                          ))
                                                                        
                                                                       , "",
                                           gettext ("invalid number of passes"), 0);
          break;

        case RANDOM_SOURCE_OPTION:
          if (random_source && !(strcmp (random_source, optarg) == 0))
            ((!!sizeof (struct { _Static_assert (
           1
           , "verify_expr (" "1" ", " "(error (1, 0, gettext (\"multiple random sources specified\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
           1
           , 0, gettext ("multiple random sources specified")), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
           1
           , 0, gettext ("multiple random sources specified")), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))));
          random_source = optarg;
          break;

        case 'u':
          if (optarg == 
                       ((void *)0)
                           )
            flags.remove_file = remove_wipesync;
          else
            flags.remove_file = ((remove_methods) [__xargmatch_internal ("--remove", optarg, remove_args, (void const *) (remove_methods), sizeof *(remove_methods), argmatch_die, 
                               1
                               )])
                                                                       ;
          break;

        case 's':
          flags.size = xnumtoumax (optarg, 0, 0, ((off_t) (! (! ((off_t) 0 < (off_t) -1)) ? (off_t) -1 : ((((off_t) 1 << ((sizeof (off_t) * 8) - 2)) - 1) * 2 + 1))), "cbBkKMGTPEZY0",
                                   gettext ("invalid file size"), 0);
          break;

        case 'v':
          flags.verbose = 
                         1
                             ;
          break;

        case 'x':
          flags.exact = 
                       1
                           ;
          break;

        case 'z':
          flags.zero_fill = 
                           1
                               ;
          break;

        case GETOPT_HELP_CHAR: usage (
       0
       ); break;;

        case GETOPT_VERSION_CHAR: version_etc (
       stdout
       , "shred", "GNU coreutils", Version, ("Colin Plumb"), (char *) 
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

  file = argv + optind;
  n_files = argc - optind;

  if (n_files == 0)
    {
      error (0, 0, gettext ("missing file operand"));
      usage (
            1
                        );
    }

  randint_source = randint_all_new (random_source, 
                                                  (18446744073709551615UL)
                                                          );
  if (! randint_source)
    ((!!sizeof (struct { _Static_assert (
   1
   , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), \"%s\", quotearg_n_style_colon (0, shell_escape_quoting_style, random_source ? random_source : \"getrandom\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
   1
   , 
   (*__errno_location ())
   , "%s", quotearg_n_style_colon (0, shell_escape_quoting_style, random_source ? random_source : "getrandom")), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
   1
   , 
   (*__errno_location ())
   , "%s", quotearg_n_style_colon (0, shell_escape_quoting_style, random_source ? random_source : "getrandom")), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))))
                                                              ;
  atexit (clear_random_data);

  for (i = 0; i < n_files; i++)
    {
      char *qname = xstrdup (quotearg_n_style_colon (0, shell_escape_quoting_style, file[i]));
      if ((strcmp (file[i], "-") == 0))
        {
          ok &= wipefd (
                       1
                                    , qname, randint_source, &flags);
        }
      else
        {

          ok &= wipefile (file[i], qname, randint_source, &flags);
        }
      free (qname);
    }

  return ok ? 
             0 
                          : 
                            1
                                        ;
}
