       












       
       
       
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

       


char *file_name_concat (char const *dir, char const *base,
                        char **base_in_result)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__returns_nonnull__));


char *mfile_name_concat (char const *dir, char const *base,
                         char **base_in_result)
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






       

       





extern int target_directory_operand (char const *file, struct stat *st);


inline __attribute__ ((__pure__)) 
                                   _Bool

target_dirfd_valid (int fd)
{
  return fd != -1 - (
                    -100 
                             == -1);
}


       
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
    acl_errno_valid (int) __attribute__ ((__const__));
int file_has_acl (char const *, struct stat const *);
int qset_acl (char const *, int, mode_t);
int set_acl (char const *, int, mode_t);
int qcopy_acl (char const *, int, char const *, int, mode_t);
int copy_acl (char const *, int, char const *, int, mode_t);
int chmod_or_fchmod (char const *, int, mode_t);
struct dir_attr
{
  struct stat st;
  
 _Bool 
      restore_mode;
  size_t slash_offset;
  struct dir_attr *next;
};



enum
{
  ATTRIBUTES_ONLY_OPTION = 0x7f + 1,
  COPY_CONTENTS_OPTION,
  NO_PRESERVE_ATTRIBUTES_OPTION,
  PARENTS_OPTION,
  PRESERVE_ATTRIBUTES_OPTION,
  REFLINK_OPTION,
  SPARSE_OPTION,
  STRIP_TRAILING_SLASHES_OPTION,
  UNLINK_DEST_BEFORE_OPENING
};


static 
      _Bool 
           selinux_enabled;



static 
      _Bool 
           parents_option = 
                            0
                                 ;


static 
      _Bool 
           remove_trailing_slashes;

static char const *const sparse_type_string[] =
{
  "never", "auto", "always", 
                            ((void *)0)

};
static enum Sparse_type const sparse_type[] =
{
  SPARSE_NEVER, SPARSE_AUTO, SPARSE_ALWAYS
};
_Static_assert ((sizeof (sparse_type_string) / sizeof *(sparse_type_string)) == (sizeof (sparse_type) / sizeof *(sparse_type)) + 1, "verify (" "ARRAY_CARDINALITY (sparse_type_string) == ARRAY_CARDINALITY (sparse_type) + 1" ")");

static char const *const reflink_type_string[] =
{
  "auto", "always", "never", 
                            ((void *)0)

};
static enum Reflink_type const reflink_type[] =
{
  REFLINK_AUTO, REFLINK_ALWAYS, REFLINK_NEVER
};
_Static_assert ((sizeof (reflink_type_string) / sizeof *(reflink_type_string)) == (sizeof (reflink_type) / sizeof *(reflink_type)) + 1, "verify (" "ARRAY_CARDINALITY (reflink_type_string) == ARRAY_CARDINALITY (reflink_type) + 1" ")");

static struct option const long_opts[] =
{
  {"archive", 
             0
                        , 
                          ((void *)0)
                              , 'a'},
  {"attributes-only", 
                     0
                                , 
                                  ((void *)0)
                                      , ATTRIBUTES_ONLY_OPTION},
  {"backup", 
            2
                             , 
                               ((void *)0)
                                   , 'b'},
  {"copy-contents", 
                   0
                              , 
                                ((void *)0)
                                    , COPY_CONTENTS_OPTION},
  {"dereference", 
                 0
                            , 
                              ((void *)0)
                                  , 'L'},
  {"force", 
           0
                      , 
                        ((void *)0)
                            , 'f'},
  {"interactive", 
                 0
                            , 
                              ((void *)0)
                                  , 'i'},
  {"link", 
          0
                     , 
                       ((void *)0)
                           , 'l'},
  {"no-clobber", 
                0
                           , 
                             ((void *)0)
                                 , 'n'},
  {"no-dereference", 
                    0
                               , 
                                 ((void *)0)
                                     , 'P'},
  {"no-preserve", 
                 1
                                  , 
                                    ((void *)0)
                                        , NO_PRESERVE_ATTRIBUTES_OPTION},
  {"no-target-directory", 
                         0
                                    , 
                                      ((void *)0)
                                          , 'T'},
  {"one-file-system", 
                     0
                                , 
                                  ((void *)0)
                                      , 'x'},
  {"parents", 
             0
                        , 
                          ((void *)0)
                              , PARENTS_OPTION},
  {"path", 
          0
                     , 
                       ((void *)0)
                           , PARENTS_OPTION},
  {"preserve", 
              2
                               , 
                                 ((void *)0)
                                     , PRESERVE_ATTRIBUTES_OPTION},
  {"recursive", 
               0
                          , 
                            ((void *)0)
                                , 'R'},
  {"remove-destination", 
                        0
                                   , 
                                     ((void *)0)
                                         , UNLINK_DEST_BEFORE_OPENING},
  {"sparse", 
            1
                             , 
                               ((void *)0)
                                   , SPARSE_OPTION},
  {"reflink", 
             2
                              , 
                                ((void *)0)
                                    , REFLINK_OPTION},
  {"strip-trailing-slashes", 
                            0
                                       , 
                                         ((void *)0)
                                             , STRIP_TRAILING_SLASHES_OPTION},
  {"suffix", 
            1
                             , 
                               ((void *)0)
                                   , 'S'},
  {"symbolic-link", 
                   0
                              , 
                                ((void *)0)
                                    , 's'},
  {"target-directory", 
                      1
                                       , 
                                         ((void *)0)
                                             , 't'},
  {"update", 
            0
                       , 
                         ((void *)0)
                             , 'u'},
  {"verbose", 
             0
                        , 
                          ((void *)0)
                              , 'v'},
  {"context", 
  2
  , 
  ((void *)0)
  , 'Z'},
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
      printf (gettext ("Usage: %s [OPTION]... [-T] SOURCE DEST\n  or:  %s [OPTION]... SOURCE... DIRECTORY\n  or:  %s [OPTION]... -t DIRECTORY SOURCE...\n")



  ,
              program_name, program_name, program_name);
      fputs_unlocked (gettext ("Copy SOURCE to DEST, or multiple SOURCE(s) to DIRECTORY.\n"),
     stdout
     )

           ;

      emit_mandatory_arg_note ();

      fputs_unlocked (gettext ("  -a, --archive                same as -dR --preserve=all\n      --attributes-only        don't copy the file data, just the attributes\n      --backup[=CONTROL]       make a backup of each existing destination file\n  -b                           like --backup but does not accept an argument\n      --copy-contents          copy contents of special files when recursive\n  -d                           same as --no-dereference --preserve=links\n"),
     stdout
     )







           ;
      fputs_unlocked (gettext ("  -f, --force                  if an existing destination file cannot be\n                                 opened, remove it and try again (this option\n                                 is ignored when the -n option is also used)\n  -i, --interactive            prompt before overwrite (overrides a previous -n\n                                  option)\n  -H                           follow command-line symbolic links in SOURCE\n"),
     stdout
     )







           ;
      fputs_unlocked (gettext ("  -l, --link                   hard link files instead of copying\n  -L, --dereference            always follow symbolic links in SOURCE\n"),
     stdout
     )


           ;
      fputs_unlocked (gettext ("  -n, --no-clobber             do not overwrite an existing file (overrides\n                                 a previous -i option)\n  -P, --no-dereference         never follow symbolic links in SOURCE\n"),
     stdout
     )



           ;
      fputs_unlocked (gettext ("  -p                           same as --preserve=mode,ownership,timestamps\n      --preserve[=ATTR_LIST]   preserve the specified attributes (default:\n                                 mode,ownership,timestamps), if possible\n                                 additional attributes: context, links, xattr,\n                                 all\n"),
     stdout
     )






           ;
      fputs_unlocked (gettext ("      --no-preserve=ATTR_LIST  don't preserve the specified attributes\n      --parents                use full source file name under DIRECTORY\n"),
     stdout
     )


           ;
      fputs_unlocked (gettext ("  -R, -r, --recursive          copy directories recursively\n      --reflink[=WHEN]         control clone/CoW copies. See below\n      --remove-destination     remove each existing destination file before\n                                 attempting to open it (contrast with --force)\n"),
     stdout
     )




             ;
      fputs_unlocked (gettext ("      --sparse=WHEN            control creation of sparse files. See below\n      --strip-trailing-slashes  remove any trailing slashes from each SOURCE\n                                 argument\n"),
     stdout
     )



           ;
      fputs_unlocked (gettext ("  -s, --symbolic-link          make symbolic links instead of copying\n  -S, --suffix=SUFFIX          override the usual backup suffix\n  -t, --target-directory=DIRECTORY  copy all SOURCE arguments into DIRECTORY\n  -T, --no-target-directory    treat DEST as a normal file\n"),
     stdout
     )




           ;
      fputs_unlocked (gettext ("  -u, --update                 copy only when the SOURCE file is newer\n                                 than the destination file or when the\n                                 destination file is missing\n  -v, --verbose                explain what is being done\n  -x, --one-file-system        stay on this file system\n"),
     stdout
     )





           ;
      fputs_unlocked (gettext ("  -Z                           set SELinux security context of destination\n                                 file to default type\n      --context[=CTX]          like -Z, or if CTX is specified then set the\n                                 SELinux or SMACK security context to CTX\n"),
     stdout
     )




           ;
      fputs_unlocked (gettext ("      --help        display this help and exit\n"),
     stdout
     );
      fputs_unlocked (gettext ("      --version     output version information and exit\n"),
     stdout
     );
      fputs_unlocked (gettext ("\nBy default, sparse SOURCE files are detected by a crude heuristic and the\ncorresponding DEST file is made sparse as well.  That is the behavior\nselected by --sparse=auto.  Specify --sparse=always to create a sparse DEST\nfile whenever the SOURCE file contains a long enough sequence of zero bytes.\nUse --sparse=never to inhibit creation of sparse files.\n"),
     stdout
     )






           ;
      fputs_unlocked (gettext ("\nWhen --reflink[=always] is specified, perform a lightweight copy, where the\ndata blocks are copied only when modified.  If this is not possible the copy\nfails, or if --reflink=auto is specified, fall back to a standard copy.\nUse --reflink=never to ensure a standard copy is performed.\n"),
     stdout
     )





           ;
      emit_backup_suffix_note ();
      fputs_unlocked (gettext ("\nAs a special case, cp makes a backup of SOURCE when the force and backup\noptions are given and SOURCE and DEST are the same name for an existing,\nregular file.\n"),
     stdout
     )




           ;
      emit_ancillary_info ("cp");
    }
  exit (status);
}
static 
      _Bool

re_protect (char const *const_dst_name, int dst_dirfd, char const *dst_relname,
            struct dir_attr *attr_list, const struct cp_options *x)
{
  struct dir_attr *p;
  char *dst_name;
  char *src_name;

  do { dst_name = 
 (__extension__ ({ const char *__old = (
 const_dst_name
 ); size_t __len = strlen (__old) + 1; char *__new = (char *) __builtin_alloca (__len); (char *) memcpy (__new, __old, __len); }))
 ; } while (0);
  src_name = dst_name + (dst_relname - const_dst_name);

  for (p = attr_list; p; p = p->next)
    {
      dst_name[p->slash_offset] = '\0';





      if (x->preserve_timestamps)
        {
          struct timespec timespec[2];

          timespec[0] = get_stat_atime (&p->st);
          timespec[1] = get_stat_mtime (&p->st);

          if (utimensat (dst_dirfd, src_name, timespec, 0))
            {
              error (0, 
                       (*__errno_location ())
                            , gettext ("failed to preserve times for %s"),
                     quotearg_style (shell_escape_always_quoting_style, dst_name));
              return 
                    0
                         ;
            }
        }

      if (x->preserve_ownership)
        {
          if (lchownat (dst_dirfd, src_name, p->st.st_uid, p->st.st_gid) != 0)
            {
              if (! chown_failure_ok (x))
                {
                  error (0, 
                           (*__errno_location ())
                                , gettext ("failed to preserve ownership for %s"),
                         quotearg_style (shell_escape_always_quoting_style, dst_name));
                  return 
                        0
                             ;
                }


              (__extension__ ({ __typeof__ (lchownat (dst_dirfd, src_name, -1, p->st.st_gid)) __x = (lchownat (dst_dirfd, src_name, -1, p->st.st_gid)); (void) __x; }));
            }
        }

      if (x->preserve_mode)
        {
          if (copy_acl (src_name, -1, dst_name, -1, p->st.st_mode) != 0)
            return 
                  0
                       ;
        }
      else if (p->restore_mode)
        {
          if (lchmodat (dst_dirfd, src_name, p->st.st_mode) != 0)
            {
              error (0, 
                       (*__errno_location ())
                            , gettext ("failed to preserve permissions for %s"),
                     quotearg_style (shell_escape_always_quoting_style, dst_name));
              return 
                    0
                         ;
            }
        }

      dst_name[p->slash_offset] = '/';
    }
  return 
        1
            ;
}
static 
      _Bool

make_dir_parents_private (char const *const_dir, size_t src_offset,
                          int dst_dirfd,
                          char const *verbose_fmt_string,
                          struct dir_attr **attr_list, 
                                                      _Bool 
                                                           *new_dst,
                          const struct cp_options *x)
{
  struct stat stats;
  char *dir;
  char *src;
  char *dst_dir;
  idx_t dirlen = dir_len (const_dir);

  *attr_list = 
              ((void *)0)
                  ;



  if (dirlen <= src_offset)
    return 
          1
              ;

  do { dir = 
 (__extension__ ({ const char *__old = (
 const_dir
 ); size_t __len = strlen (__old) + 1; char *__new = (char *) __builtin_alloca (__len); (char *) memcpy (__new, __old, __len); }))
 ; } while (0);

  src = dir + src_offset;

  dst_dir = __builtin_alloca (dirlen + 1);
  memcpy (dst_dir, dir, dirlen);
  dst_dir[dirlen] = '\0';
  char const *dst_reldir = dst_dir + src_offset;
  while (*dst_reldir == '/')
    dst_reldir++;



  if (fstatat (dst_dirfd, dst_reldir, &stats, 0) != 0)
    {


      char *slash;

      slash = src;
      while (*slash == '/')
        slash++;
      dst_reldir = slash;

      while ((slash = strchr (slash, '/')))
        {
          struct dir_attr *new;
          
         _Bool 
              missing_dir;

          *slash = '\0';
          missing_dir = fstatat (dst_dirfd, dst_reldir, &stats, 0) != 0;

          if (missing_dir || x->preserve_ownership || x->preserve_mode
              || x->preserve_timestamps)
            {


              struct stat src_st;
              int src_errno = (stat (src, &src_st) != 0
                               ? 
                                (*__errno_location ())
                               
                              : 
                                ((((
                                src_st.st_mode
                                )) & 0170000) == (0040000))
                               
                              ? 0
                               : 
                                20
                                       );
              if (src_errno)
                {
                  error (0, src_errno, gettext ("failed to get attributes of %s"),
                         quotearg_style (shell_escape_always_quoting_style, src));
                  return 
                        0
                             ;
                }

              new = xmalloc (sizeof *new);
              new->st = src_st;
              new->slash_offset = slash - dir;
              new->restore_mode = 
                                 0
                                      ;
              new->next = *attr_list;
              *attr_list = new;
            }


          if (! set_process_security_ctx (src, dir,
                                          missing_dir ? new->st.st_mode : 0,
                                          missing_dir, x))
            return 
                  0
                       ;

          if (missing_dir)
            {
              mode_t src_mode;
              mode_t omitted_permissions;
              mode_t mkdir_mode;






              *new_dst = 
                        1
                            ;
              src_mode = new->st.st_mode;




              omitted_permissions = (src_mode
                                     & (x->preserve_ownership
                                        ? 
                                         ((0400|0200|0100) >> 3) 
                                                 | 
                                                   (((0400|0200|0100) >> 3) >> 3)
                                        
                                       : x->preserve_mode
                                        ? 
                                         (0200 >> 3) 
                                                 | 
                                                   ((0200 >> 3) >> 3)
                                        
                                       : 0));





              mkdir_mode = x->explicit_no_preserve_mode ? 
                                                         ((0400|0200|0100) | ((0400|0200|0100) >> 3) | (((0400|0200|0100) >> 3) >> 3)) 
                                                                   : src_mode;
              mkdir_mode &= (
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
                           ) & ~omitted_permissions;
              if (mkdirat (dst_dirfd, dst_reldir, mkdir_mode) != 0)
                {
                  error (0, 
                           (*__errno_location ())
                                , gettext ("cannot make directory %s"),
                         quotearg_style (shell_escape_always_quoting_style, dir));
                  return 
                        0
                             ;
                }
              else
                {
                  if (verbose_fmt_string != 
                                           ((void *)0)
                                               )
                    printf (verbose_fmt_string, src, dir);
                }





              if (fstatat (dst_dirfd, dst_reldir, &stats, 
                                                         0x100
                                                                            ))
                {
                  error (0, 
                           (*__errno_location ())
                                , gettext ("failed to get attributes of %s"),
                         quotearg_style (shell_escape_always_quoting_style, dir));
                  return 
                        0
                             ;
                }


              if (! x->preserve_mode)
                {
                  if (omitted_permissions & ~stats.st_mode)
                    omitted_permissions &= ~ cached_umask ();
                  if (omitted_permissions & ~stats.st_mode
                      || (stats.st_mode & 
                                         (0400|0200|0100)
                                                ) != 
                                                     (0400|0200|0100)
                                                            )
                    {
                      new->st.st_mode = stats.st_mode | omitted_permissions;
                      new->restore_mode = 
                                         1
                                             ;
                    }
                }

              mode_t accessible = stats.st_mode | 
                                                 (0400|0200|0100)
                                                        ;
              if (stats.st_mode != accessible)
                {



                  if (lchmodat (dst_dirfd, dst_reldir, accessible) != 0)
                    {
                      error (0, 
                               (*__errno_location ())
                                    , gettext ("setting permissions for %s"),
                             quotearg_style (shell_escape_always_quoting_style, dir));
                      return 
                            0
                                 ;
                    }
                }
            }
          else if (!
                   ((((
                   stats.st_mode
                   )) & 0170000) == (0040000))
                                          )
            {
              error (0, 0, gettext ("%s exists but is not a directory"),
                     quotearg_style (shell_escape_always_quoting_style, dir));
              return 
                    0
                         ;
            }
          else
            *new_dst = 
                      0
                           ;



          if (! *new_dst
              && (x->set_security_context || x->preserve_security_context))
            {
              if (! set_file_security_ctx (dir, 
                                               0
                                                    , x)
                  && x->require_preserve_context)
                return 
                      0
                           ;
            }

          *slash++ = '/';



          while (*slash == '/')
            slash++;
        }
    }



  else if (!
           ((((
           stats.st_mode
           )) & 0170000) == (0040000))
                                  )
    {
      error (0, 0, gettext ("%s exists but is not a directory"), quotearg_style (shell_escape_always_quoting_style, dst_dir));
      return 
            0
                 ;
    }
  else
    {
      *new_dst = 
                0
                     ;
    }
  return 
        1
            ;
}




static 
      _Bool

do_copy (int n_files, char **file, char const *target_directory,
         
        _Bool 
             no_target_directory, struct cp_options *x)
{
  struct stat sb;
  
 _Bool 
      new_dst = 
                0
                     ;
  
 _Bool 
      ok = 
           1
               ;

  if (n_files <= !target_directory)
    {
      if (n_files <= 0)
        error (0, 0, gettext ("missing file operand"));
      else
        error (0, 0, gettext ("missing destination file operand after %s"),
               quotearg_style (shell_escape_always_quoting_style, file[0]));
      usage (
            1
                        );
    }

  sb.st_mode = 0;
  int target_dirfd = 
                    -100
                            ;
  if (no_target_directory)
    {
      if (target_directory)
        ((!!sizeof (struct { _Static_assert (
       1
       , "verify_expr (" "1" ", " "(error (1, 0, gettext (\"cannot combine --target-directory (-t) \" \"and --no-target-directory (-T)\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
       1
       , 0, gettext ("cannot combine --target-directory (-t) " "and --no-target-directory (-T)")), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
       1
       , 0, gettext ("cannot combine --target-directory (-t) " "and --no-target-directory (-T)")), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))))

                                                 ;
      if (2 < n_files)
        {
          error (0, 0, gettext ("extra operand %s"), quotearg_style (shell_escape_always_quoting_style, file[2]));
          usage (
                1
                            );
        }
    }
  else if (target_directory)
    {
      target_dirfd = target_directory_operand (target_directory, &sb);
      if (! target_dirfd_valid (target_dirfd))
        ((!!sizeof (struct { _Static_assert (
       1
       , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), gettext (\"target directory %s\"), quotearg_style (shell_escape_always_quoting_style, target_directory)), assume (false))" ")"); int _gl_dummy; })) ? ((error (
       1
       , 
       (*__errno_location ())
       , gettext ("target directory %s"), quotearg_style (shell_escape_always_quoting_style, target_directory)), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
       1
       , 
       (*__errno_location ())
       , gettext ("target directory %s"), quotearg_style (shell_escape_always_quoting_style, target_directory)), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))))
                                        ;
    }
  else
    {
      char const *lastfile = file[n_files - 1];
      int fd = target_directory_operand (lastfile, &sb);
      if (target_dirfd_valid (fd))
        {
          target_dirfd = fd;
          target_directory = lastfile;
          n_files--;
        }
      else
        {
          int err = 
                   (*__errno_location ())
                        ;
          if (err == 
                    2
                          )
            new_dst = 
                     1
                         ;
          if (2 < n_files
              || (O_PATHSEARCH == 
                                 00 
                                          && err == 
                                                    13
                  
                 && (sb.st_mode || stat (lastfile, &sb) == 0)
                  && 
                    ((((
                    sb.st_mode
                    )) & 0170000) == (0040000))
                                        ))
            ((!!sizeof (struct { _Static_assert (
           1
           , "verify_expr (" "1" ", " "(error (1, err, gettext (\"target %s\"), quotearg_style (shell_escape_always_quoting_style, lastfile)), assume (false))" ")"); int _gl_dummy; })) ? ((error (
           1
           , err, gettext ("target %s"), quotearg_style (shell_escape_always_quoting_style, lastfile)), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
           1
           , err, gettext ("target %s"), quotearg_style (shell_escape_always_quoting_style, lastfile)), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))));
        }
    }

  if (target_directory)
    {







      if (2 <= n_files)
        {
          dest_info_init (x);
          src_info_init (x);
        }

      for (int i = 0; i < n_files; i++)
        {
          char *dst_name;
          
         _Bool 
              parent_exists = 
                              1
                                  ;
          struct dir_attr *attr_list;
          char *arg_in_concat = 
                               ((void *)0)
                                   ;
          char *arg = file[i];



          if (remove_trailing_slashes)
            strip_trailing_slashes (arg);

          if (parents_option)
            {
              char *arg_no_trailing_slash;





              do { arg_no_trailing_slash = 
             (__extension__ ({ const char *__old = (
             arg
             ); size_t __len = strlen (__old) + 1; char *__new = (char *) __builtin_alloca (__len); (char *) memcpy (__new, __old, __len); }))
             ; } while (0);
              strip_trailing_slashes (arg_no_trailing_slash);


              dst_name = file_name_concat (target_directory,
                                           arg_no_trailing_slash,
                                           &arg_in_concat);




              parent_exists =
                (make_dir_parents_private
                 (dst_name, arg_in_concat - dst_name, target_dirfd,
                  (x->verbose ? "%s -> %s\n" : 
                                              ((void *)0)
                                                  ),
                  &attr_list, &new_dst, x));

              while (*arg_in_concat == '/')
                arg_in_concat++;
            }
          else
            {
              char *arg_base;

              do { arg_base = 
             (__extension__ ({ const char *__old = (
             last_component (arg)
             ); size_t __len = strlen (__old) + 1; char *__new = (char *) __builtin_alloca (__len); (char *) memcpy (__new, __old, __len); }))
             ; } while (0);
              strip_trailing_slashes (arg_base);

              arg_base += (strcmp (arg_base, "..") == 0);
              dst_name = file_name_concat (target_directory, arg_base,
                                           &arg_in_concat);
            }

          if (!parent_exists)
            {


              ok = 
                  0
                       ;
            }
          else
            {
              
             _Bool 
                  copy_into_self;
              ok &= copy (arg, dst_name, target_dirfd, arg_in_concat,
                          new_dst, x, &copy_into_self, 
                                                      ((void *)0)
                                                          );

              if (parents_option)
                ok &= re_protect (dst_name, target_dirfd, arg_in_concat,
                                  attr_list, x);
            }

          if (parents_option)
            {
              while (attr_list)
                {
                  struct dir_attr *p = attr_list;
                  attr_list = attr_list->next;
                  free (p);
                }
            }

          free (dst_name);
        }
    }
  else
    {
      char const *source = file[0];
      char const *dest = file[1];
      
     _Bool 
          unused;

      if (parents_option)
        {
          error (0, 0,
                 gettext ("with --parents, the destination must be a directory"));
          usage (
                1
                            );
        }







      if (x->unlink_dest_after_failed_open
          && x->backup_type != no_backups
          && (strcmp (source, dest) == 0)
          && !new_dst
          && (sb.st_mode != 0 || stat (dest, &sb) == 0) && 
                                                          ((((
                                                          sb.st_mode
                                                          )) & 0170000) == (0100000))
                                                                              )
        {
          static struct cp_options x_tmp;

          dest = find_backup_file_name (
                                       -100
                                               , dest, x->backup_type);





          x_tmp = *x;
          x_tmp.backup_type = no_backups;
          x = &x_tmp;
        }

      ok = copy (source, dest, 
                              -100
                                      , dest, -new_dst, x, &unused, 
                                                                    ((void *)0)
                                                                        );
    }

  return ok;
}

static void
cp_option_init (struct cp_options *x)
{
  cp_options_default (x);
  x->copy_as_regular = 
                      1
                          ;
  x->dereference = DEREF_UNDEFINED;
  x->unlink_dest_before_opening = 
                                 0
                                      ;
  x->unlink_dest_after_failed_open = 
                                    0
                                         ;
  x->hard_link = 
                0
                     ;
  x->interactive = I_UNSPECIFIED;
  x->move_mode = 
                0
                     ;
  x->install_mode = 
                   0
                        ;
  x->one_file_system = 
                      0
                           ;
  x->reflink_mode = REFLINK_AUTO;

  x->preserve_ownership = 
                         0
                              ;
  x->preserve_links = 
                     0
                          ;
  x->preserve_mode = 
                    0
                         ;
  x->preserve_timestamps = 
                          0
                               ;
  x->explicit_no_preserve_mode = 
                                0
                                     ;
  x->preserve_security_context = 
                                0
                                     ;
  x->require_preserve_context = 
                               0
                                    ;
  x->set_security_context = 
                           ((void *)0)
                               ;
  x->preserve_xattr = 
                     0
                          ;
  x->reduce_diagnostics = 
                         0
                              ;
  x->require_preserve_xattr = 
                             0
                                  ;

  x->data_copy_required = 
                         1
                             ;
  x->require_preserve = 
                       0
                            ;
  x->recursive = 
                0
                     ;
  x->sparse_mode = SPARSE_AUTO;
  x->symbolic_link = 
                    0
                         ;
  x->set_mode = 
               0
                    ;
  x->mode = 0;


  x->stdin_tty = 
                0
                     ;

  x->update = 
             0
                  ;
  x->verbose = 
              0
                   ;





  x->open_dangling_dest_symlink = getenv ("POSIXLY_CORRECT") != 
                                                               ((void *)0)
                                                                   ;

  x->dest_info = 
                ((void *)0)
                    ;
  x->src_info = 
               ((void *)0)
                   ;
}



static void
decode_preserve_arg (char const *arg, struct cp_options *x, 
                                                           _Bool 
                                                                on_off)
{
  enum File_attribute
    {
      PRESERVE_MODE,
      PRESERVE_TIMESTAMPS,
      PRESERVE_OWNERSHIP,
      PRESERVE_LINK,
      PRESERVE_CONTEXT,
      PRESERVE_XATTR,
      PRESERVE_ALL
    };
  static enum File_attribute const preserve_vals[] =
    {
      PRESERVE_MODE, PRESERVE_TIMESTAMPS,
      PRESERVE_OWNERSHIP, PRESERVE_LINK, PRESERVE_CONTEXT, PRESERVE_XATTR,
      PRESERVE_ALL
    };

  static char const *const preserve_args[] =
    {
      "mode", "timestamps",
      "ownership", "links", "context", "xattr", "all", 
                                                      ((void *)0)
    
   };
  _Static_assert ((sizeof (preserve_args) / sizeof *(preserve_args)) == (sizeof (preserve_vals) / sizeof *(preserve_vals)) + 1, "verify (" "ARRAY_CARDINALITY (preserve_args) == ARRAY_CARDINALITY (preserve_vals) + 1" ")");

  char *arg_writable = xstrdup (arg);
  char *s = arg_writable;
  do
    {

      char *comma = strchr (s, ',');
      enum File_attribute val;


      if (comma)
        *comma++ = 0;


      val = ((preserve_vals) [__xargmatch_internal (on_off ? "--preserve" : "--no-preserve", s, preserve_args, (void const *) (preserve_vals), sizeof *(preserve_vals), argmatch_die, 
           1
           )])
                                                       ;
      switch (val)
        {
        case PRESERVE_MODE:
          x->preserve_mode = on_off;
          x->explicit_no_preserve_mode = !on_off;
          break;

        case PRESERVE_TIMESTAMPS:
          x->preserve_timestamps = on_off;
          break;

        case PRESERVE_OWNERSHIP:
          x->preserve_ownership = on_off;
          break;

        case PRESERVE_LINK:
          x->preserve_links = on_off;
          break;

        case PRESERVE_CONTEXT:
          x->require_preserve_context = on_off;
          x->preserve_security_context = on_off;
          break;

        case PRESERVE_XATTR:
          x->preserve_xattr = on_off;
          x->require_preserve_xattr = on_off;
          break;

        case PRESERVE_ALL:
          x->preserve_mode = on_off;
          x->preserve_timestamps = on_off;
          x->preserve_ownership = on_off;
          x->preserve_links = on_off;
          x->explicit_no_preserve_mode = !on_off;
          if (selinux_enabled)
            x->preserve_security_context = on_off;
          x->preserve_xattr = on_off;
          break;

        default:
          abort ();
        }
      s = comma;
    }
  while (s);

  free (arg_writable);
}

int
main (int argc, char **argv)
{
  int c;
  
 _Bool 
      ok;
  
 _Bool 
      make_backups = 
                     0
                          ;
  char const *backup_suffix = 
                             ((void *)0)
                                 ;
  char *version_control_string = 
                                ((void *)0)
                                    ;
  struct cp_options x;
  
 _Bool 
      copy_contents = 
                      0
                           ;
  char *target_directory = 
                          ((void *)0)
                              ;
  
 _Bool 
      no_target_directory = 
                            0
                                 ;
  char const *scontext = 
                        ((void *)0)
                            ;

  ;
  set_program_name (argv[0]);
  setlocale (
            6
                  , "");
  bindtextdomain ("coreutils", "/usr/local/share/locale");
  textdomain ("coreutils");

  atexit (close_stdin);

  selinux_enabled = (0 < is_selinux_enabled ());
  cp_option_init (&x);

  while ((c = getopt_long (argc, argv, "abdfHilLnprst:uvxPRS:TZ",
                           long_opts, 
                                     ((void *)0)
                                         ))
         != -1)
    {
      switch (c)
        {
        case SPARSE_OPTION:
          x.sparse_mode = ((sparse_type) [__xargmatch_internal ("--sparse", optarg, sparse_type_string, (void const *) (sparse_type), sizeof *(sparse_type), argmatch_die, 
                         1
                         )])
                                                                     ;
          break;

        case REFLINK_OPTION:
          if (optarg == 
                       ((void *)0)
                           )
            x.reflink_mode = REFLINK_ALWAYS;
          else
            x.reflink_mode = ((reflink_type) [__xargmatch_internal ("--reflink", optarg, reflink_type_string, (void const *) (reflink_type), sizeof *(reflink_type), argmatch_die, 
                            1
                            )])
                                                                         ;
          break;

        case 'a':

          x.dereference = DEREF_NEVER;
          x.preserve_links = 
                            1
                                ;
          x.preserve_ownership = 
                                1
                                    ;
          x.preserve_mode = 
                           1
                               ;
          x.preserve_timestamps = 
                                 1
                                     ;
          x.require_preserve = 
                              1
                                  ;
          if (selinux_enabled)
             x.preserve_security_context = 
                                          1
                                              ;
          x.preserve_xattr = 
                            1
                                ;
          x.reduce_diagnostics = 
                                1
                                    ;
          x.recursive = 
                       1
                           ;
          break;

        case 'b':
          make_backups = 
                        1
                            ;
          if (optarg)
            version_control_string = optarg;
          break;

        case ATTRIBUTES_ONLY_OPTION:
          x.data_copy_required = 
                                0
                                     ;
          break;

        case COPY_CONTENTS_OPTION:
          copy_contents = 
                         1
                             ;
          break;

        case 'd':
          x.preserve_links = 
                            1
                                ;
          x.dereference = DEREF_NEVER;
          break;

        case 'f':
          x.unlink_dest_after_failed_open = 
                                           1
                                               ;
          break;

        case 'H':
          x.dereference = DEREF_COMMAND_LINE_ARGUMENTS;
          break;

        case 'i':
          x.interactive = I_ASK_USER;
          break;

        case 'l':
          x.hard_link = 
                       1
                           ;
          break;

        case 'L':
          x.dereference = DEREF_ALWAYS;
          break;

        case 'n':
          x.interactive = I_ALWAYS_NO;
          break;

        case 'P':
          x.dereference = DEREF_NEVER;
          break;

        case NO_PRESERVE_ATTRIBUTES_OPTION:
          decode_preserve_arg (optarg, &x, 
                                          0
                                               );
          break;

        case PRESERVE_ATTRIBUTES_OPTION:
          if (optarg == 
                       ((void *)0)
                           )
            {

            }
          else
            {
              decode_preserve_arg (optarg, &x, 
                                              1
                                                  );
              x.require_preserve = 
                                  1
                                      ;
              break;
            }
          [[__fallthrough__]];

        case 'p':
          x.preserve_ownership = 
                                1
                                    ;
          x.preserve_mode = 
                           1
                               ;
          x.preserve_timestamps = 
                                 1
                                     ;
          x.require_preserve = 
                              1
                                  ;
          break;

        case PARENTS_OPTION:
          parents_option = 
                          1
                              ;
          break;

        case 'r':
        case 'R':
          x.recursive = 
                       1
                           ;
          break;

        case UNLINK_DEST_BEFORE_OPENING:
          x.unlink_dest_before_opening = 
                                        1
                                            ;
          break;

        case STRIP_TRAILING_SLASHES_OPTION:
          remove_trailing_slashes = 
                                   1
                                       ;
          break;

        case 's':
          x.symbolic_link = 
                           1
                               ;
          break;

        case 't':
          if (target_directory)
            ((!!sizeof (struct { _Static_assert (
           1
           , "verify_expr (" "1" ", " "(error (1, 0, gettext (\"multiple target directories specified\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
           1
           , 0, gettext ("multiple target directories specified")), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
           1
           , 0, gettext ("multiple target directories specified")), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))))
                                                            ;
          target_directory = optarg;
          break;

        case 'T':
          no_target_directory = 
                               1
                                   ;
          break;

        case 'u':
          x.update = 
                    1
                        ;
          break;

        case 'v':
          x.verbose = 
                     1
                         ;
          break;

        case 'x':
          x.one_file_system = 
                             1
                                 ;
          break;

        case 'Z':

          if (selinux_enabled)
            {
              if (optarg)
                scontext = optarg;
              else
                {
                  x.set_security_context = selabel_open (
                                                        0
                                                                        ,
                                                         
                                                        ((void *)0)
                                                            , 0);
                  if (! x.set_security_context)
                    error (0, 
                             (*__errno_location ())
                                  , gettext ("warning: ignoring --context"));
                }
            }
          else if (optarg)
            {
              error (0, 0,
                     gettext ("warning: ignoring --context; " "it requires an SELinux-enabled kernel")
                                                               );
            }
          break;

        case 'S':
          make_backups = 
                        1
                            ;
          backup_suffix = optarg;
          break;

        case GETOPT_HELP_CHAR: usage (
       0
       ); break;;

        case GETOPT_VERSION_CHAR: version_etc (
       stdout
       , "cp", "GNU coreutils", Version, ("Torbjorn Granlund"), ("David MacKenzie"), ("Jim Meyering"), (char *) 
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

  if (x.hard_link && x.symbolic_link)
    {
      error (0, 0, gettext ("cannot make both hard and symbolic links"));
      usage (
            1
                        );
    }

  if (x.interactive == I_ALWAYS_NO)
    x.update = 
              0
                   ;

  if (make_backups && x.interactive == I_ALWAYS_NO)
    {
      error (0, 0,
             gettext ("options --backup and --no-clobber are mutually exclusive"));
      usage (
            1
                        );
    }

  if (x.reflink_mode == REFLINK_ALWAYS && x.sparse_mode != SPARSE_AUTO)
    {
      error (0, 0, gettext ("--reflink can be used only with --sparse=auto"));
      usage (
            1
                        );
    }

  x.backup_type = (make_backups
                   ? xget_version (gettext ("backup type"),
                                   version_control_string)
                   : no_backups);
  set_simple_backup_suffix (backup_suffix);

  if (x.dereference == DEREF_UNDEFINED)
    {
      if (x.recursive && ! x.hard_link)

        x.dereference = DEREF_NEVER;
      else
        x.dereference = DEREF_ALWAYS;
    }

  if (x.recursive)
    x.copy_as_regular = copy_contents;


  if ((x.set_security_context || scontext)
      && ! x.require_preserve_context)
    x.preserve_security_context = 
                                 0
                                      ;

  if (x.preserve_security_context && (x.set_security_context || scontext))
    ((!!sizeof (struct { _Static_assert (
   1
   , "verify_expr (" "1" ", " "(error (1, 0, gettext (\"cannot set target context and preserve it\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
   1
   , 0, gettext ("cannot set target context and preserve it")), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
   1
   , 0, gettext ("cannot set target context and preserve it")), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))))
                                                        ;

  if (x.require_preserve_context && ! selinux_enabled)
    ((!!sizeof (struct { _Static_assert (
   1
   , "verify_expr (" "1" ", " "(error (1, 0, gettext (\"cannot preserve security context \" \"without an SELinux-enabled kernel\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
   1
   , 0, gettext ("cannot preserve security context " "without an SELinux-enabled kernel")), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
   1
   , 0, gettext ("cannot preserve security context " "without an SELinux-enabled kernel")), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))))

                                                ;







  if (scontext && setfscreatecon (scontext) < 0)
    ((!!sizeof (struct { _Static_assert (
   1
   , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), gettext (\"failed to set default file creation context to %s\"), quote (scontext)), assume (false))" ")"); int _gl_dummy; })) ? ((error (
   1
   , 
   (*__errno_location ())
   , gettext ("failed to set default file creation context to %s"), quote (scontext)), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
   1
   , 
   (*__errno_location ())
   , gettext ("failed to set default file creation context to %s"), quote (scontext)), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))))

                          ;
  hash_init ();

  ok = do_copy (argc - optind, argv + optind,
                target_directory, no_target_directory, &x);

  return ok ? 
 0 
 : 
 1
                                             ;
}
