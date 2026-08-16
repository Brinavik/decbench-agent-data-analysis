
       












       
       
       
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

inline 
              _Bool

c_isalnum (int c)
{
  switch (c)
    {
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    case 'a' + (0): case 'b' + (0): case 'c' + (0): case 'd' + (0): case 'e' + (0): case 'f' + (0): case 'g' + (0): case 'h' + (0): case 'i' + (0): case 'j' + (0): case 'k' + (0): case 'l' + (0): case 'm' + (0): case 'n' + (0): case 'o' + (0): case 'p' + (0): case 'q' + (0): case 'r' + (0): case 's' + (0): case 't' + (0): case 'u' + (0): case 'v' + (0): case 'w' + (0): case 'x' + (0): case 'y' + (0): case 'z' + (0):
    case 'a' + ('A' - 'a'): case 'b' + ('A' - 'a'): case 'c' + ('A' - 'a'): case 'd' + ('A' - 'a'): case 'e' + ('A' - 'a'): case 'f' + ('A' - 'a'): case 'g' + ('A' - 'a'): case 'h' + ('A' - 'a'): case 'i' + ('A' - 'a'): case 'j' + ('A' - 'a'): case 'k' + ('A' - 'a'): case 'l' + ('A' - 'a'): case 'm' + ('A' - 'a'): case 'n' + ('A' - 'a'): case 'o' + ('A' - 'a'): case 'p' + ('A' - 'a'): case 'q' + ('A' - 'a'): case 'r' + ('A' - 'a'): case 's' + ('A' - 'a'): case 't' + ('A' - 'a'): case 'u' + ('A' - 'a'): case 'v' + ('A' - 'a'): case 'w' + ('A' - 'a'): case 'x' + ('A' - 'a'): case 'y' + ('A' - 'a'): case 'z' + ('A' - 'a'):
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_isalpha (int c)
{
  switch (c)
    {
    case 'a' + (0): case 'b' + (0): case 'c' + (0): case 'd' + (0): case 'e' + (0): case 'f' + (0): case 'g' + (0): case 'h' + (0): case 'i' + (0): case 'j' + (0): case 'k' + (0): case 'l' + (0): case 'm' + (0): case 'n' + (0): case 'o' + (0): case 'p' + (0): case 'q' + (0): case 'r' + (0): case 's' + (0): case 't' + (0): case 'u' + (0): case 'v' + (0): case 'w' + (0): case 'x' + (0): case 'y' + (0): case 'z' + (0):
    case 'a' + ('A' - 'a'): case 'b' + ('A' - 'a'): case 'c' + ('A' - 'a'): case 'd' + ('A' - 'a'): case 'e' + ('A' - 'a'): case 'f' + ('A' - 'a'): case 'g' + ('A' - 'a'): case 'h' + ('A' - 'a'): case 'i' + ('A' - 'a'): case 'j' + ('A' - 'a'): case 'k' + ('A' - 'a'): case 'l' + ('A' - 'a'): case 'm' + ('A' - 'a'): case 'n' + ('A' - 'a'): case 'o' + ('A' - 'a'): case 'p' + ('A' - 'a'): case 'q' + ('A' - 'a'): case 'r' + ('A' - 'a'): case 's' + ('A' - 'a'): case 't' + ('A' - 'a'): case 'u' + ('A' - 'a'): case 'v' + ('A' - 'a'): case 'w' + ('A' - 'a'): case 'x' + ('A' - 'a'): case 'y' + ('A' - 'a'): case 'z' + ('A' - 'a'):
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}



inline 
              _Bool

c_isascii (int c)
{
  switch (c)
    {
    case ' ':
    case '\a': case '\b': case '\f': case '\n': case '\r': case '\t': case '\v': case '\x00': case '\x01': case '\x02': case '\x03': case '\x04': case '\x05': case '\x06': case '\x0e': case '\x0f': case '\x10': case '\x11': case '\x12': case '\x13': case '\x14': case '\x15': case '\x16': case '\x17': case '\x18': case '\x19': case '\x1a': case '\x1b': case '\x1c': case '\x1d': case '\x1e': case '\x1f': case '\x7f':
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    case 'a' + (0): case 'b' + (0): case 'c' + (0): case 'd' + (0): case 'e' + (0): case 'f' + (0): case 'g' + (0): case 'h' + (0): case 'i' + (0): case 'j' + (0): case 'k' + (0): case 'l' + (0): case 'm' + (0): case 'n' + (0): case 'o' + (0): case 'p' + (0): case 'q' + (0): case 'r' + (0): case 's' + (0): case 't' + (0): case 'u' + (0): case 'v' + (0): case 'w' + (0): case 'x' + (0): case 'y' + (0): case 'z' + (0):
    case '!': case '"': case '#': case '$': case '%': case '&': case '\'': case '(': case ')': case '*': case '+': case ',': case '-': case '.': case '/': case ':': case ';': case '<': case '=': case '>': case '?': case '@': case '[': case '\\': case ']': case '^': case '_': case '`': case '{': case '|': case '}': case '~':
    case 'a' + ('A' - 'a'): case 'b' + ('A' - 'a'): case 'c' + ('A' - 'a'): case 'd' + ('A' - 'a'): case 'e' + ('A' - 'a'): case 'f' + ('A' - 'a'): case 'g' + ('A' - 'a'): case 'h' + ('A' - 'a'): case 'i' + ('A' - 'a'): case 'j' + ('A' - 'a'): case 'k' + ('A' - 'a'): case 'l' + ('A' - 'a'): case 'm' + ('A' - 'a'): case 'n' + ('A' - 'a'): case 'o' + ('A' - 'a'): case 'p' + ('A' - 'a'): case 'q' + ('A' - 'a'): case 'r' + ('A' - 'a'): case 's' + ('A' - 'a'): case 't' + ('A' - 'a'): case 'u' + ('A' - 'a'): case 'v' + ('A' - 'a'): case 'w' + ('A' - 'a'): case 'x' + ('A' - 'a'): case 'y' + ('A' - 'a'): case 'z' + ('A' - 'a'):
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_isblank (int c)
{
  return c == ' ' || c == '\t';
}

inline 
              _Bool

c_iscntrl (int c)
{
  switch (c)
    {
    case '\a': case '\b': case '\f': case '\n': case '\r': case '\t': case '\v': case '\x00': case '\x01': case '\x02': case '\x03': case '\x04': case '\x05': case '\x06': case '\x0e': case '\x0f': case '\x10': case '\x11': case '\x12': case '\x13': case '\x14': case '\x15': case '\x16': case '\x17': case '\x18': case '\x19': case '\x1a': case '\x1b': case '\x1c': case '\x1d': case '\x1e': case '\x1f': case '\x7f':
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_isdigit (int c)
{
  switch (c)
    {
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_isgraph (int c)
{
  switch (c)
    {
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    case 'a' + (0): case 'b' + (0): case 'c' + (0): case 'd' + (0): case 'e' + (0): case 'f' + (0): case 'g' + (0): case 'h' + (0): case 'i' + (0): case 'j' + (0): case 'k' + (0): case 'l' + (0): case 'm' + (0): case 'n' + (0): case 'o' + (0): case 'p' + (0): case 'q' + (0): case 'r' + (0): case 's' + (0): case 't' + (0): case 'u' + (0): case 'v' + (0): case 'w' + (0): case 'x' + (0): case 'y' + (0): case 'z' + (0):
    case '!': case '"': case '#': case '$': case '%': case '&': case '\'': case '(': case ')': case '*': case '+': case ',': case '-': case '.': case '/': case ':': case ';': case '<': case '=': case '>': case '?': case '@': case '[': case '\\': case ']': case '^': case '_': case '`': case '{': case '|': case '}': case '~':
    case 'a' + ('A' - 'a'): case 'b' + ('A' - 'a'): case 'c' + ('A' - 'a'): case 'd' + ('A' - 'a'): case 'e' + ('A' - 'a'): case 'f' + ('A' - 'a'): case 'g' + ('A' - 'a'): case 'h' + ('A' - 'a'): case 'i' + ('A' - 'a'): case 'j' + ('A' - 'a'): case 'k' + ('A' - 'a'): case 'l' + ('A' - 'a'): case 'm' + ('A' - 'a'): case 'n' + ('A' - 'a'): case 'o' + ('A' - 'a'): case 'p' + ('A' - 'a'): case 'q' + ('A' - 'a'): case 'r' + ('A' - 'a'): case 's' + ('A' - 'a'): case 't' + ('A' - 'a'): case 'u' + ('A' - 'a'): case 'v' + ('A' - 'a'): case 'w' + ('A' - 'a'): case 'x' + ('A' - 'a'): case 'y' + ('A' - 'a'): case 'z' + ('A' - 'a'):
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_islower (int c)
{
  switch (c)
    {
    case 'a' + (0): case 'b' + (0): case 'c' + (0): case 'd' + (0): case 'e' + (0): case 'f' + (0): case 'g' + (0): case 'h' + (0): case 'i' + (0): case 'j' + (0): case 'k' + (0): case 'l' + (0): case 'm' + (0): case 'n' + (0): case 'o' + (0): case 'p' + (0): case 'q' + (0): case 'r' + (0): case 's' + (0): case 't' + (0): case 'u' + (0): case 'v' + (0): case 'w' + (0): case 'x' + (0): case 'y' + (0): case 'z' + (0):
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_isprint (int c)
{
  switch (c)
    {
    case ' ':
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    case 'a' + (0): case 'b' + (0): case 'c' + (0): case 'd' + (0): case 'e' + (0): case 'f' + (0): case 'g' + (0): case 'h' + (0): case 'i' + (0): case 'j' + (0): case 'k' + (0): case 'l' + (0): case 'm' + (0): case 'n' + (0): case 'o' + (0): case 'p' + (0): case 'q' + (0): case 'r' + (0): case 's' + (0): case 't' + (0): case 'u' + (0): case 'v' + (0): case 'w' + (0): case 'x' + (0): case 'y' + (0): case 'z' + (0):
    case '!': case '"': case '#': case '$': case '%': case '&': case '\'': case '(': case ')': case '*': case '+': case ',': case '-': case '.': case '/': case ':': case ';': case '<': case '=': case '>': case '?': case '@': case '[': case '\\': case ']': case '^': case '_': case '`': case '{': case '|': case '}': case '~':
    case 'a' + ('A' - 'a'): case 'b' + ('A' - 'a'): case 'c' + ('A' - 'a'): case 'd' + ('A' - 'a'): case 'e' + ('A' - 'a'): case 'f' + ('A' - 'a'): case 'g' + ('A' - 'a'): case 'h' + ('A' - 'a'): case 'i' + ('A' - 'a'): case 'j' + ('A' - 'a'): case 'k' + ('A' - 'a'): case 'l' + ('A' - 'a'): case 'm' + ('A' - 'a'): case 'n' + ('A' - 'a'): case 'o' + ('A' - 'a'): case 'p' + ('A' - 'a'): case 'q' + ('A' - 'a'): case 'r' + ('A' - 'a'): case 's' + ('A' - 'a'): case 't' + ('A' - 'a'): case 'u' + ('A' - 'a'): case 'v' + ('A' - 'a'): case 'w' + ('A' - 'a'): case 'x' + ('A' - 'a'): case 'y' + ('A' - 'a'): case 'z' + ('A' - 'a'):
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_ispunct (int c)
{
  switch (c)
    {
    case '!': case '"': case '#': case '$': case '%': case '&': case '\'': case '(': case ')': case '*': case '+': case ',': case '-': case '.': case '/': case ':': case ';': case '<': case '=': case '>': case '?': case '@': case '[': case '\\': case ']': case '^': case '_': case '`': case '{': case '|': case '}': case '~':
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_isspace (int c)
{
  switch (c)
    {
    case ' ': case '\t': case '\n': case '\v': case '\f': case '\r':
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_isupper (int c)
{
  switch (c)
    {
    case 'a' + ('A' - 'a'): case 'b' + ('A' - 'a'): case 'c' + ('A' - 'a'): case 'd' + ('A' - 'a'): case 'e' + ('A' - 'a'): case 'f' + ('A' - 'a'): case 'g' + ('A' - 'a'): case 'h' + ('A' - 'a'): case 'i' + ('A' - 'a'): case 'j' + ('A' - 'a'): case 'k' + ('A' - 'a'): case 'l' + ('A' - 'a'): case 'm' + ('A' - 'a'): case 'n' + ('A' - 'a'): case 'o' + ('A' - 'a'): case 'p' + ('A' - 'a'): case 'q' + ('A' - 'a'): case 'r' + ('A' - 'a'): case 's' + ('A' - 'a'): case 't' + ('A' - 'a'): case 'u' + ('A' - 'a'): case 'v' + ('A' - 'a'): case 'w' + ('A' - 'a'): case 'x' + ('A' - 'a'): case 'y' + ('A' - 'a'): case 'z' + ('A' - 'a'):
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline 
              _Bool

c_isxdigit (int c)
{
  switch (c)
    {
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    case 'a' + (0): case 'b' + (0): case 'c' + (0): case 'd' + (0): case 'e' + (0): case 'f' + (0): case 'a' + ('A' - 'a'): case 'b' + ('A' - 'a'): case 'c' + ('A' - 'a'): case 'd' + ('A' - 'a'): case 'e' + ('A' - 'a'): case 'f' + ('A' - 'a'):
      return 
            1
                ;
    default:
      return 
            0
                 ;
    }
}

inline int
c_tolower (int c)
{
  switch (c)
    {
    case 'a' + ('A' - 'a'): case 'b' + ('A' - 'a'): case 'c' + ('A' - 'a'): case 'd' + ('A' - 'a'): case 'e' + ('A' - 'a'): case 'f' + ('A' - 'a'): case 'g' + ('A' - 'a'): case 'h' + ('A' - 'a'): case 'i' + ('A' - 'a'): case 'j' + ('A' - 'a'): case 'k' + ('A' - 'a'): case 'l' + ('A' - 'a'): case 'm' + ('A' - 'a'): case 'n' + ('A' - 'a'): case 'o' + ('A' - 'a'): case 'p' + ('A' - 'a'): case 'q' + ('A' - 'a'): case 'r' + ('A' - 'a'): case 's' + ('A' - 'a'): case 't' + ('A' - 'a'): case 'u' + ('A' - 'a'): case 'v' + ('A' - 'a'): case 'w' + ('A' - 'a'): case 'x' + ('A' - 'a'): case 'y' + ('A' - 'a'): case 'z' + ('A' - 'a'):
      return c - 'A' + 'a';
    default:
      return c;
    }
}

inline int
c_toupper (int c)
{
  switch (c)
    {
    case 'a' + (0): case 'b' + (0): case 'c' + (0): case 'd' + (0): case 'e' + (0): case 'f' + (0): case 'g' + (0): case 'h' + (0): case 'i' + (0): case 'j' + (0): case 'k' + (0): case 'l' + (0): case 'm' + (0): case 'n' + (0): case 'o' + (0): case 'p' + (0): case 'q' + (0): case 'r' + (0): case 's' + (0): case 't' + (0): case 'u' + (0): case 'v' + (0): case 'w' + (0): case 'x' + (0): case 'y' + (0): case 'z' + (0):
      return c - 'a' + 'A';
    default:
      return c;
    }
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



extern struct quoting_options quote_quoting_options;





char const *quote_n_mem (int n, char const *arg, size_t argsize);




char const *quote_mem (char const *arg, size_t argsize);



char const *quote_n (int n, char const *arg);



char const *quote (char const *arg);
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
       
intmax_t xdectoimax (char const *n_str, intmax_t min, intmax_t max, char const *suffixes, char const *err, int err_exit) __attribute__ ((__nonnull__ (1, 5)));
uintmax_t xdectoumax (char const *n_str, uintmax_t min, uintmax_t max, char const *suffixes, char const *err, int err_exit) __attribute__ ((__nonnull__ (1, 5)));

intmax_t xnumtoimax (char const *n_str, int base, intmax_t min, intmax_t max, char const *suffixes, char const *err, int err_exit) __attribute__ ((__nonnull__ (1, 6)));
uintmax_t xnumtoumax (char const *n_str, int base, uintmax_t min, uintmax_t max, char const *suffixes, char const *err, int err_exit) __attribute__ ((__nonnull__ (1, 6)));
       



       





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


struct base32_decode_context
{
  int i;
  char buf[8];
};

extern 
      _Bool 
           isbase32 (char ch) __attribute__ ((__const__));

extern void base32_encode (const char *__restrict__ in, idx_t inlen,
                           char *__restrict__ out, idx_t outlen);

extern idx_t base32_encode_alloc (const char *in, idx_t inlen, char **out);

extern void base32_decode_ctx_init (struct base32_decode_context *ctx);

extern 
      _Bool 
           base32_decode_ctx (struct base32_decode_context *ctx,
                               const char *__restrict__ in, idx_t inlen,
                               char *__restrict__ out, idx_t *outlen);

extern 
      _Bool 
           base32_decode_alloc_ctx (struct base32_decode_context *ctx,
                                     const char *in, idx_t inlen,
                                     char **out, idx_t *outlen);
struct base64_decode_context
{
  int i;
  char buf[4];
};

extern 
      _Bool 
           isbase64 (char ch) __attribute__ ((__const__));

extern void base64_encode (const char *__restrict__ in, idx_t inlen,
                           char *__restrict__ out, idx_t outlen);

extern idx_t base64_encode_alloc (const char *in, idx_t inlen, char **out);

extern void base64_decode_ctx_init (struct base64_decode_context *ctx);

extern 
      _Bool 
           base64_decode_ctx (struct base64_decode_context *ctx,
                               const char *__restrict__ in, idx_t inlen,
                               char *__restrict__ out, idx_t *outlen);

extern 
      _Bool 
           base64_decode_alloc_ctx (struct base64_decode_context *ctx,
                                     const char *in, idx_t inlen,
                                     char **out, idx_t *outlen);

enum
{
  BASE64_OPTION = 0x7f + 1,
  BASE64URL_OPTION,
  BASE32_OPTION,
  BASE32HEX_OPTION,
  BASE16_OPTION,
  BASE2MSBF_OPTION,
  BASE2LSBF_OPTION,
  Z85_OPTION
};


static struct option const long_options[] =
{
  {"decode", 
            0
                       , 0, 'd'},
  {"wrap", 
          1
                           , 0, 'w'},
  {"ignore-garbage", 
                    0
                               , 0, 'i'},

  {"base64", 
               0
                          , 0, BASE64_OPTION},
  {"base64url", 
               0
                          , 0, BASE64URL_OPTION},
  {"base32", 
               0
                          , 0, BASE32_OPTION},
  {"base32hex", 
               0
                          , 0, BASE32HEX_OPTION},
  {"base16", 
               0
                          , 0, BASE16_OPTION},
  {"base2msbf", 
               0
                          , 0, BASE2MSBF_OPTION},
  {"base2lsbf", 
               0
                          , 0, BASE2LSBF_OPTION},
  {"z85", 
               0
                          , 0, Z85_OPTION},

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
      printf (gettext ("Usage: %s [OPTION]... [FILE]\n")

  , program_name);


      fputs_unlocked (gettext ("basenc encode or decode FILE, or standard input, to standard output.\n"),
     stdout
     )

           ;






      emit_stdin_note ();
      emit_mandatory_arg_note ();

      fputs_unlocked (gettext ("      --base64          same as 'base64' program (RFC4648 section 4)\n"),
     stdout
     )

           ;
      fputs_unlocked (gettext ("      --base64url       file- and url-safe base64 (RFC4648 section 5)\n"),
     stdout
     )

           ;
      fputs_unlocked (gettext ("      --base32          same as 'base32' program (RFC4648 section 6)\n"),
     stdout
     )

           ;
      fputs_unlocked (gettext ("      --base32hex       extended hex alphabet base32 (RFC4648 section 7)\n"),
     stdout
     )

           ;
      fputs_unlocked (gettext ("      --base16          hex encoding (RFC4648 section 8)\n"),
     stdout
     )

           ;
      fputs_unlocked (gettext ("      --base2msbf       bit string with most significant bit (msb) first\n"),
     stdout
     )

           ;
      fputs_unlocked (gettext ("      --base2lsbf       bit string with least significant bit (lsb) first\n"),
     stdout
     )

           ;

      fputs_unlocked (gettext ("  -d, --decode          decode data\n  -i, --ignore-garbage  when decoding, ignore non-alphabet characters\n  -w, --wrap=COLS       wrap encoded lines after COLS character (default 76).\n                          Use 0 to disable line wrapping\n"),
     stdout
     )




           ;

      fputs_unlocked (gettext ("      --z85             ascii85-like encoding (ZeroMQ spec:32/Z85);\n                        when encoding, input length must be a multiple of 4;\n                        when decoding, input length must be a multiple of 5\n"),
     stdout
     )



           ;

      fputs_unlocked (gettext ("      --help        display this help and exit\n"),
     stdout
     );
      fputs_unlocked (gettext ("      --version     output version information and exit\n"),
     stdout
     );

      fputs_unlocked (gettext ("\nWhen decoding, the input may contain newlines in addition to the bytes of\nthe formal alphabet.  Use --ignore-garbage to attempt to recover\nfrom any other non-alphabet bytes in the encoded stream.\n"),
     stdout
     )




           ;
      emit_ancillary_info ("basenc");
    }

  exit (status);
}
_Static_assert ((4200) % 40 == 0, "verify (" "DEC_BLOCKSIZE % 40 == 0" ")");
_Static_assert ((4200) % 12 == 0, "verify (" "DEC_BLOCKSIZE % 12 == 0" ")");

static int (*base_length) (int i);
static 
      _Bool 
           (*isbase) (char ch);
static void (*base_encode) (char const *__restrict__ in, idx_t inlen,
                            char *__restrict__ out, idx_t outlen);

struct base16_decode_context
{
  char nibble;
  
 _Bool 
      have_nibble;
};

struct z85_decode_context
{
  int i;
  unsigned char octets[5];
};

struct base2_decode_context
{
  unsigned char octet;
};

struct base_decode_context
{
  int i;
  union {
    struct base64_decode_context base64;
    struct base32_decode_context base32;
    struct base16_decode_context base16;
    struct base2_decode_context base2;
    struct z85_decode_context z85;
  } ctx;
  char *inbuf;
  idx_t bufsize;
};
static void (*base_decode_ctx_init) (struct base_decode_context *ctx);
static 
      _Bool 
           (*base_decode_ctx) (struct base_decode_context *ctx,
                                char const *__restrict__ in, idx_t inlen,
                                char *__restrict__ out, idx_t *outlen);







static int
base64_length_wrapper (int len)
{
  return ((((len) + 2) / 3) * 4);
}

static void
base64_decode_ctx_init_wrapper (struct base_decode_context *ctx)
{
  base64_decode_ctx_init (&ctx->ctx.base64);
}

static 
      _Bool

base64_decode_ctx_wrapper (struct base_decode_context *ctx,
                           char const *__restrict__ in, idx_t inlen,
                           char *__restrict__ out, idx_t *outlen)
{
  
 _Bool 
      b = base64_decode_ctx (&ctx->ctx.base64, in, inlen, out, outlen);
  ctx->i = ctx->ctx.base64.i;
  return b;
}

static void
init_inbuf (struct base_decode_context *ctx)
{
  ctx->bufsize = (4200);
  ctx->inbuf = xcharalloc (ctx->bufsize);
}

static void
prepare_inbuf (struct base_decode_context *ctx, idx_t inlen)
{
  if (ctx->bufsize < inlen)
    {
      ctx->bufsize = inlen * 2;
      ctx->inbuf = xnrealloc (ctx->inbuf, ctx->bufsize, sizeof (char));
    }
}


static void
base64url_encode (char const *__restrict__ in, idx_t inlen,
                  char *__restrict__ out, idx_t outlen)
{
  base64_encode (in, inlen, out, outlen);

  char *p = out;
  while (outlen--)
    {
      if (*p == '+')
        *p = '-';
      else if (*p == '/')
        *p = '_';
      ++p;
    }
}

static 
      _Bool

isbase64url (char ch)
{
  return (ch == '-' || ch == '_'
          || (ch != '+' && ch != '/' && isbase64 (ch)));
}

static void
base64url_decode_ctx_init_wrapper (struct base_decode_context *ctx)
{
  base64_decode_ctx_init (&ctx->ctx.base64);
  init_inbuf (ctx);
}


static 
      _Bool

base64url_decode_ctx_wrapper (struct base_decode_context *ctx,
                              char const *__restrict__ in, idx_t inlen,
                              char *__restrict__ out, idx_t *outlen)
{
  prepare_inbuf (ctx, inlen);
  memcpy (ctx->inbuf, in, inlen);


  idx_t i = inlen;
  char *p = ctx->inbuf;
  while (i--)
    {
      if (*p == '+' || *p == '/')
        {
          *outlen = 0;
          return 
                0
                     ;
        }
      else if (*p == '-')
        *p = '+';
      else if (*p == '_')
        *p = '/';
      ++p;
    }

  
 _Bool 
      b = base64_decode_ctx (&ctx->ctx.base64, ctx->inbuf, inlen,
                              out, outlen);
  ctx->i = ctx->ctx.base64.i;

  return b;
}



static int
base32_length_wrapper (int len)
{
  return ((((len) + 4) / 5) * 8);
}

static void
base32_decode_ctx_init_wrapper (struct base_decode_context *ctx)
{
  base32_decode_ctx_init (&ctx->ctx.base32);
}

static 
      _Bool

base32_decode_ctx_wrapper (struct base_decode_context *ctx,
                           char const *__restrict__ in, idx_t inlen,
                           char *__restrict__ out, idx_t *outlen)
{
  
 _Bool 
      b = base32_decode_ctx (&ctx->ctx.base32, in, inlen, out, outlen);
  ctx->i = ctx->ctx.base32.i;
  return b;
}




static const char base32_norm_to_hex[32 + 9] = {

  'Q', 'R', 'S', 'T', 'U', 'V',

  0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40,


  '0', '1', '2', '3', '4', '5', '6', '7',


  '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',


  'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',


  'O', 'P',
};




static const char base32_hex_to_norm[32 + 9] = {

           'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',

  0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40,


           'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',


           'U', 'V', 'W', 'X', 'Y', 'Z', '2', '3', '4', '5',


           '6', '7'
};


inline static 
             _Bool

isbase32hex (char ch)
{
  return ('0' <= ch && ch <= '9') || ('A' <= ch && ch <= 'V');
}


static void
base32hex_encode (char const *__restrict__ in, idx_t inlen,
                  char *__restrict__ out, idx_t outlen)
{
  base32_encode (in, inlen, out, outlen);

  for (char *p = out; outlen--; p++)
    {
      
     ((void) sizeof ((
     0x32 <= *p && *p <= 0x5a
     ) ? 1 : 0), __extension__ ({ if (
     0x32 <= *p && *p <= 0x5a
     ) ; else __assert_fail (
     "0x32 <= *p && *p <= 0x5a"
     , "src/basenc.c", 452, __extension__ __PRETTY_FUNCTION__); }))
                                      ;
      *p = base32_norm_to_hex[*p - 0x32];
    }
}


static void
base32hex_decode_ctx_init_wrapper (struct base_decode_context *ctx)
{
  base32_decode_ctx_init (&ctx->ctx.base32);
  init_inbuf (ctx);
}


static 
      _Bool

base32hex_decode_ctx_wrapper (struct base_decode_context *ctx,
                              char const *__restrict__ in, idx_t inlen,
                              char *__restrict__ out, idx_t *outlen)
{
  prepare_inbuf (ctx, inlen);

  idx_t i = inlen;
  char *p = ctx->inbuf;
  while (i--)
    {
      if (isbase32hex (*in))
        *p = base32_hex_to_norm[ (int)*in - 0x30];
      else
        *p = *in;
      ++p;
      ++in;
    }

  
 _Bool 
      b = base32_decode_ctx (&ctx->ctx.base32, ctx->inbuf, inlen,
                              out, outlen);
  ctx->i = ctx->ctx.base32.i;

  return b;
}


static 
      _Bool

isbase16 (char ch)
{
  return ('0' <= ch && ch <= '9') || ('A' <= ch && ch <= 'F');
}

static int
base16_length (int len)
{
  return len * 2;
}

static const char base16[16] = "0123456789ABCDEF";

static void
base16_encode (char const *__restrict__ in, idx_t inlen,
               char *__restrict__ out, idx_t outlen)
{
  while (inlen--)
    {
      unsigned char c = *in;
      *out++ = base16[c >> 4];
      *out++ = base16[c & 0x0F];
      ++in;
    }
}


static void
base16_decode_ctx_init (struct base_decode_context *ctx)
{
  init_inbuf (ctx);
  ctx->ctx.base16.have_nibble = 
                               0
                                    ;
  ctx->i = 1;
}


static 
      _Bool

base16_decode_ctx (struct base_decode_context *ctx,
                   char const *__restrict__ in, idx_t inlen,
                   char *__restrict__ out, idx_t *outlen)
{
  
 _Bool 
      ignore_lines = 
                     1
                         ;

  *outlen = 0;




  if (inlen == 0)
    return !ctx->ctx.base16.have_nibble;

  while (inlen--)
    {
      if (ignore_lines && *in == '\n')
        {
          ++in;
          continue;
        }

      int nib = *in++;
      if ('0' <= nib && nib <= '9')
        nib -= '0';
      else if ('A' <= nib && nib <= 'F')
        nib -= 'A' - 10;
      else
        return 
              0
                   ;

      if (ctx->ctx.base16.have_nibble)
        {

          *out++ = (ctx->ctx.base16.nibble << 4) + nib;
          ++(*outlen);
        }
      else
        {

          ctx->ctx.base16.nibble = nib;
        }
      ctx->ctx.base16.have_nibble = !ctx->ctx.base16.have_nibble;
    }
  return 
        1
            ;
}




static int
z85_length (int len)
{

  int outlen = (len * 5) / 4;
  return outlen;
}

static 
      _Bool

isz85 (char ch)
{
  return c_isalnum (ch) || (strchr (".-:+=^!/*?&<>()[]{}@%$#", ch) != 
                                                                     ((void *)0)
                                                                         );
}

static char const z85_encoding[85] =
  "0123456789"
  "abcdefghijklmnopqrstuvwxyz"
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  ".-:+=^!/*?&<>()[]{}@%$#";

static void
z85_encode (char const *__restrict__ in, idx_t inlen,
            char *__restrict__ out, idx_t outlen)
{
  int i = 0;
  unsigned char quad[4];
  idx_t outidx = 0;

  while (
        1
            )
    {
      if (inlen == 0)
        {

          if (i == 0)
            return;


          ((!!sizeof (struct { _Static_assert (
         1
         , "verify_expr (" "1" ", " "(error (1, 0, gettext (\"invalid input (length must be multiple of 4 characters)\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
         1
         , 0, gettext ("invalid input (length must be multiple of 4 characters)")), ((
         0
         ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
         1
         , 0, gettext ("invalid input (length must be multiple of 4 characters)")), ((
         0
         ) ? (void) 0 : __builtin_unreachable ()))))
                                                                            ;
        }
      else
        {
          quad[i++] = *in++;
          --inlen;
        }


      if (i == 4)
        {
          int_fast64_t val = quad[0];
          val = (val << 24) + (quad[1] << 16) + (quad[2] << 8) + quad[3];

          for (int j = 4; j >= 0; --j)
            {
              int c = val % 85;
              val /= 85;





              if (outidx + j < outlen)
                out[j] = z85_encoding[c];
            }
          out += 5;
          outidx += 5;
          i = 0;
        }
    }
}

static void
z85_decode_ctx_init (struct base_decode_context *ctx)
{
  init_inbuf (ctx);
  ctx->ctx.z85.i = 0;
  ctx->i = 1;
}
static signed char const z85_decoding[93] = {
  68, -1, 84, 83, 82, 72, -1,
  75, 76, 70, 65, -1, 63, 62, 69,
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
  64, -1, 73, 66, 74, 71, 81,
  36, 37, 38, 39, 40, 41, 42, 43, 44, 45,
  46, 47, 48, 49, 50, 51, 52, 53, 54, 55,
  56, 57, 58, 59, 60, 61,
  77, -1, 78, 67, -1, -1,
  10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
  20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
  30, 31, 32, 33, 34, 35,
  79, -1, 80
};

static 
      _Bool

z85_decode_ctx (struct base_decode_context *ctx,
                char const *__restrict__ in, idx_t inlen,
                char *__restrict__ out, idx_t *outlen)
{
  
 _Bool 
      ignore_lines = 
                     1
                         ;

  *outlen = 0;




  if (inlen == 0)
    {
      if (ctx->ctx.z85.i > 0)
        {


          return 
                0
                     ;
        }
      return 
            1
                ;
    }

  while (inlen--)
    {
      if (ignore_lines && *in == '\n')
        {
          ++in;
          continue;
        }


      unsigned char c = *in;

      if (c >= 33 && c <= 125)
        {
          signed char ch = z85_decoding[c - 33];
          if (ch < 0)
            return 
                  0
                       ;
          c = ch;
        }
      else
        return 
              0
                   ;

      ++in;

      ctx->ctx.z85.octets[ctx->ctx.z85.i++] = c;
      if (ctx->ctx.z85.i == 5)
        {

          int_fast64_t val = (((ctx)->ctx.z85.octets[1] * 85 * 85 * 85) + ((ctx)->ctx.z85.octets[2] * 85 * 85) + ((ctx)->ctx.z85.octets[3] * 85) + ((ctx)->ctx.z85.octets[4]));




          val += ((int_fast64_t) (ctx)->ctx.z85.octets[0] * 85 * 85 * 85 * 85 );
          if ((val >> 24) & ~0xFF)
            return 
                  0
                       ;

          *out++ = val >> 24;
          *out++ = (val >> 16) & 0xFF;
          *out++ = (val >> 8) & 0xFF;
          *out++ = val & 0xFF;

          *outlen += 4;

          ctx->ctx.z85.i = 0;
        }
    }
  ctx->i = ctx->ctx.z85.i;
  return 
        1
            ;
}


inline static 
             _Bool

isbase2 (char ch)
{
  return ch == '0' || ch == '1';
}

static int
base2_length (int len)
{
  return len * 8;
}


inline static void
base2msbf_encode (char const *__restrict__ in, idx_t inlen,
                  char *__restrict__ out, idx_t outlen)
{
  while (inlen--)
    {
      unsigned char c = *in;
      for (int i = 0; i < 8; i++)
        {
          *out++ = c & 0x80 ? '1' : '0';
          c <<= 1;
        }
      outlen -= 8;
      ++in;
    }
}

inline static void
base2lsbf_encode (char const *__restrict__ in, idx_t inlen,
                  char *__restrict__ out, idx_t outlen)
{
  while (inlen--)
    {
      unsigned char c = *in;
      for (int i = 0; i < 8; i++)
        {
          *out++ = c & 0x01 ? '1' : '0';
          c >>= 1;
        }
      outlen -= 8;
      ++in;
    }
}


static void
base2_decode_ctx_init (struct base_decode_context *ctx)
{
  init_inbuf (ctx);
  ctx->ctx.base2.octet = 0;
  ctx->i = 0;
}


static 
      _Bool

base2lsbf_decode_ctx (struct base_decode_context *ctx,
                      char const *__restrict__ in, idx_t inlen,
                      char *__restrict__ out, idx_t *outlen)
{
  
 _Bool 
      ignore_lines = 
                     1
                         ;

  *outlen = 0;




  if (inlen == 0)
    return ctx->i == 0;

  while (inlen--)
    {
      if (ignore_lines && *in == '\n')
        {
          ++in;
          continue;
        }

      if (!isbase2 (*in))
        return 
              0
                   ;

      
     _Bool 
          bit = (*in == '1');
      ctx->ctx.base2.octet |= bit << ctx->i;
      ++ctx->i;

      if (ctx->i == 8)
        {
          *out++ = ctx->ctx.base2.octet;
          ctx->ctx.base2.octet = 0;
          ++*outlen;
          ctx->i = 0;
        }

      ++in;
    }

  return 
        1
            ;
}

static 
      _Bool

base2msbf_decode_ctx (struct base_decode_context *ctx,
                      char const *__restrict__ in, idx_t inlen,
                      char *__restrict__ out, idx_t *outlen)
{
  
 _Bool 
      ignore_lines = 
                     1
                         ;

  *outlen = 0;




  if (inlen == 0)
    return ctx->i == 0;

  while (inlen--)
    {
      if (ignore_lines && *in == '\n')
        {
          ++in;
          continue;
        }

      if (!isbase2 (*in))
        return 
              0
                   ;

      
     _Bool 
          bit = (*in == '1');
      if (ctx->i == 0)
        ctx->i = 8;
      --ctx->i;
      ctx->ctx.base2.octet |= bit << ctx->i;

      if (ctx->i == 0)
        {
          *out++ = ctx->ctx.base2.octet;
          ctx->ctx.base2.octet = 0;
          ++*outlen;
          ctx->i = 0;
        }

      ++in;
    }

  return 
        1
            ;
}





static void
wrap_write (char const *buffer, idx_t len,
            idx_t wrap_column, idx_t *current_column, FILE *out)
{
  if (wrap_column == 0)
    {

      if (fwrite_unlocked (buffer,1,len,
         stdout
         ) < len)
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
  else
    for (idx_t written = 0; written < len; )
      {
        idx_t to_write = 
                        (((
                        wrap_column - *current_column
                        )<(
                        len - written
                        ))?(
                        wrap_column - *current_column
                        ):(
                        len - written
                        ))
                                                                          ;

        if (to_write == 0)
          {
            if (fputc_unlocked ('\n',out) == 
                                    (-1)
                                       )
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
            *current_column = 0;
          }
        else
          {
            if (fwrite_unlocked (buffer + written,1,to_write,
               stdout
               ) < to_write)
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
            *current_column += to_write;
            written += to_write;
          }
      }
}

static _Noreturn void
finish_and_exit (FILE *in, char const *infile)
{
  if (
     rpl_fclose 
            (in) != 0)
    {
      if ((strcmp (infile, "-") == 0))
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
      else
        ((!!sizeof (struct { _Static_assert (
       1
       , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), \"%s\", quotearg_n_style_colon (0, shell_escape_quoting_style, infile)), assume (false))" ")"); int _gl_dummy; })) ? ((error (
       1
       , 
       (*__errno_location ())
       , "%s", quotearg_n_style_colon (0, shell_escape_quoting_style, infile)), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
       1
       , 
       (*__errno_location ())
       , "%s", quotearg_n_style_colon (0, shell_escape_quoting_style, infile)), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))));
    }

  exit (
       0
                   );
}

static _Noreturn void
do_encode (FILE *in, char const *infile, FILE *out, idx_t wrap_column)
{
  idx_t current_column = 0;
  char *inbuf, *outbuf;
  idx_t sum;

  inbuf = xmalloc ((1024 * 3 * 10));
  outbuf = xmalloc (base_length ((1024 * 3 * 10)));

  do
    {
      idx_t n;

      sum = 0;
      do
        {
          n = fread_unlocked (inbuf + sum,1,(1024 * 3 * 10) - sum,in);
          sum += n;
        }
      while (!feof_unlocked (in) && !ferror_unlocked (in) && sum < (1024 * 3 * 10));

      if (sum > 0)
        {


          base_encode (inbuf, sum, outbuf, base_length (sum));

          wrap_write (outbuf, base_length (sum), wrap_column,
                      &current_column, out);
        }
    }
  while (!feof_unlocked (in) && !ferror_unlocked (in) && sum == (1024 * 3 * 10));


  if (wrap_column && current_column > 0 && fputc_unlocked ('\n',out) == 
                                                               (-1)
                                                                  )
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

  if (ferror_unlocked (in))
    ((!!sizeof (struct { _Static_assert (
   1
   , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), gettext (\"read error\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
   1
   , 
   (*__errno_location ())
   , gettext ("read error")), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
   1
   , 
   (*__errno_location ())
   , gettext ("read error")), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))));

  finish_and_exit (in, infile);
}

static _Noreturn void
do_decode (FILE *in, char const *infile, FILE *out, 
                                                   _Bool 
                                                        ignore_garbage)
{
  char *inbuf, *outbuf;
  idx_t sum;
  struct base_decode_context ctx;

  inbuf = xmalloc (base_length ((4200)));
  outbuf = xmalloc ((4200));


  ctx.inbuf = 
             ((void *)0)
                 ;

  base_decode_ctx_init (&ctx);

  do
    {
      
     _Bool 
          ok;

      sum = 0;
      do
        {
          idx_t n = fread_unlocked (inbuf + sum,1,base_length ((4200)) - sum,in)
                                                                    ;

          if (ignore_garbage)
            {
              for (idx_t i = 0; n > 0 && i < n;)
                {
                  if (isbase (inbuf[sum + i]) || inbuf[sum + i] == '=')
                    i++;
                  else
                    memmove (inbuf + sum + i, inbuf + sum + i + 1, --n - i);
                }
            }

          sum += n;

          if (ferror_unlocked (in))
            ((!!sizeof (struct { _Static_assert (
           1
           , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), gettext (\"read error\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
           1
           , 
           (*__errno_location ())
           , gettext ("read error")), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
           1
           , 
           (*__errno_location ())
           , gettext ("read error")), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))));
        }
      while (sum < base_length ((4200)) && !feof_unlocked (in));





      for (int k = 0; k < 1 + !!feof_unlocked (in); k++)
        {
          if (k == 1 && ctx.i == 0)
            break;
          idx_t n = (4200);
          ok = base_decode_ctx (&ctx, inbuf, (k == 0 ? sum : 0), outbuf, &n);

          if (fwrite_unlocked (outbuf,1,n,out) < n)
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

          if (!ok)
            ((!!sizeof (struct { _Static_assert (
           1
           , "verify_expr (" "1" ", " "(error (1, 0, gettext (\"invalid input\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
           1
           , 0, gettext ("invalid input")), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
           1
           , 0, gettext ("invalid input")), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))));
        }
    }
  while (!feof_unlocked (in));

  finish_and_exit (in, infile);
}

int
main (int argc, char **argv)
{
  int opt;
  FILE *input_fh;
  char const *infile;


  
 _Bool 
      decode = 
               0
                    ;

  
 _Bool 
      ignore_garbage = 
                       0
                            ;

  idx_t wrap_column = 76;


  int base_type = 0;


  ;
  set_program_name (argv[0]);
  setlocale (
            6
                  , "");
  bindtextdomain ("coreutils", "/usr/local/share/locale");
  textdomain ("coreutils");

  atexit (close_stdout);

  while ((opt = getopt_long (argc, argv, "diw:", long_options, 
                                                              ((void *)0)
                                                                  )) != -1)
    switch (opt)
      {
      case 'd':
        decode = 
                1
                    ;
        break;

      case 'w':
        {
          intmax_t w;
          strtol_error s_err = xstrtoimax (optarg, 
                                                  ((void *)0)
                                                      , 10, &w, "");
          if (LONGINT_OVERFLOW < s_err || w < 0)
            ((!!sizeof (struct { _Static_assert (
           1
           , "verify_expr (" "1" ", " "(error (1, 0, \"%s: %s\", gettext (\"invalid wrap size\"), quote (optarg)), assume (false))" ")"); int _gl_dummy; })) ? ((error (
           1
           , 0, "%s: %s", gettext ("invalid wrap size"), quote (optarg)), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
           1
           , 0, "%s: %s", gettext ("invalid wrap size"), quote (optarg)), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))))
                                                        ;
          wrap_column = s_err == LONGINT_OVERFLOW || 
                                                    (9223372036854775807L) 
                                                            < w ? 0 : w;
        }
        break;

      case 'i':
        ignore_garbage = 
                        1
                            ;
        break;


      case BASE64_OPTION:
      case BASE64URL_OPTION:
      case BASE32_OPTION:
      case BASE32HEX_OPTION:
      case BASE16_OPTION:
      case BASE2MSBF_OPTION:
      case BASE2LSBF_OPTION:
      case Z85_OPTION:
        base_type = opt;
        break;


      case GETOPT_HELP_CHAR: usage (
     0
     ); break;;

      case GETOPT_VERSION_CHAR: version_etc (
     stdout
     , "basenc", "GNU coreutils", Version, ("Simon Josefsson"), ("Assaf Gordon"), (char *) 
     ((void *)0)
     ); exit (
     0
     ); break;;

      default:
        usage (
              1
                          );
        break;
      }


  switch (base_type)
    {
    case BASE64_OPTION:
      base_length = base64_length_wrapper;
      isbase = isbase64;
      base_encode = base64_encode;
      base_decode_ctx_init = base64_decode_ctx_init_wrapper;
      base_decode_ctx = base64_decode_ctx_wrapper;
      break;

    case BASE64URL_OPTION:
      base_length = base64_length_wrapper;
      isbase = isbase64url;
      base_encode = base64url_encode;
      base_decode_ctx_init = base64url_decode_ctx_init_wrapper;
      base_decode_ctx = base64url_decode_ctx_wrapper;
      break;

    case BASE32_OPTION:
      base_length = base32_length_wrapper;
      isbase = isbase32;
      base_encode = base32_encode;
      base_decode_ctx_init = base32_decode_ctx_init_wrapper;
      base_decode_ctx = base32_decode_ctx_wrapper;
      break;

    case BASE32HEX_OPTION:
      base_length = base32_length_wrapper;
      isbase = isbase32hex;
      base_encode = base32hex_encode;
      base_decode_ctx_init = base32hex_decode_ctx_init_wrapper;
      base_decode_ctx = base32hex_decode_ctx_wrapper;
      break;

    case BASE16_OPTION:
      base_length = base16_length;
      isbase = isbase16;
      base_encode = base16_encode;
      base_decode_ctx_init = base16_decode_ctx_init;
      base_decode_ctx = base16_decode_ctx;
      break;

    case BASE2MSBF_OPTION:
      base_length = base2_length;
      isbase = isbase2;
      base_encode = base2msbf_encode;
      base_decode_ctx_init = base2_decode_ctx_init;
      base_decode_ctx = base2msbf_decode_ctx;
      break;

    case BASE2LSBF_OPTION:
      base_length = base2_length;
      isbase = isbase2;
      base_encode = base2lsbf_encode;
      base_decode_ctx_init = base2_decode_ctx_init;
      base_decode_ctx = base2lsbf_decode_ctx;
      break;

    case Z85_OPTION:
      base_length = z85_length;
      isbase = isz85;
      base_encode = z85_encode;
      base_decode_ctx_init = z85_decode_ctx_init;
      base_decode_ctx = z85_decode_ctx;
      break;

    default:
      error (0, 0, gettext ("missing encoding type"));
      usage (
            1
                        );
    }


  if (argc - optind > 1)
    {
      error (0, 0, gettext ("extra operand %s"), quote (argv[optind + 1]));
      usage (
            1
                        );
    }

  if (optind < argc)
    infile = argv[optind];
  else
    infile = "-";

  if ((strcmp (infile, "-") == 0))
    {
      xset_binary_mode (
                       0
                                   , 
                                     0
                                             );
      input_fh = 
                stdin
                     ;
    }
  else
    {
      input_fh = fopen (infile, "rb");
      if (input_fh == 
                     ((void *)0)
                         )
        ((!!sizeof (struct { _Static_assert (
       1
       , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), \"%s\", quotearg_n_style_colon (0, shell_escape_quoting_style, infile)), assume (false))" ")"); int _gl_dummy; })) ? ((error (
       1
       , 
       (*__errno_location ())
       , "%s", quotearg_n_style_colon (0, shell_escape_quoting_style, infile)), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
       1
       , 
       (*__errno_location ())
       , "%s", quotearg_n_style_colon (0, shell_escape_quoting_style, infile)), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))));
    }

  fadvise (input_fh, FADVISE_SEQUENTIAL);

  if (decode)
    do_decode (input_fh, infile, 
                                stdout
                                      , ignore_garbage);
  else
    do_encode (input_fh, infile, 
                                stdout
                                      , wrap_column);
}
