       












       
       
       
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
       
       

struct dev_ino
{
  ino_t st_ino;
  dev_t st_dev;
};
       
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




extern struct quoting_options quote_quoting_options;





char const *quote_n_mem (int n, char const *arg, size_t argsize);




char const *quote_mem (char const *arg, size_t argsize);



char const *quote_n (int n, char const *arg);



char const *quote (char const *arg);

struct dev_ino *
get_root_dev_ino (struct dev_ino *root_d_i) __attribute__ ((__nonnull__ ));
       

int getfileconat (int dir_fd, char const *file, char **con);




int lgetfileconat (int dir_fd, char const *file, char **con);





int setfileconat (int dir_fd, char const *file, char const *con);






int lsetfileconat (int dir_fd, char const *file, char const *con);

       

       

enum { I_RING_SIZE = 4 };
_Static_assert (1 <= I_RING_SIZE, "verify (" "1 <= I_RING_SIZE" ")");
struct I_ring
{
  int ir_data[I_RING_SIZE];
  int ir_default_val;
  unsigned int ir_front;
  unsigned int ir_back;
  
 _Bool 
      ir_empty;
};
typedef struct I_ring I_ring;

void i_ring_init (I_ring *ir, int ir_default_val);
int i_ring_push (I_ring *ir, int val);
int i_ring_pop (I_ring *ir);

_Bool 
    i_ring_empty (I_ring const *ir) __attribute__ ((__pure__));

typedef struct {
        struct _ftsent *fts_cur;
        struct _ftsent *fts_child;
        struct _ftsent **fts_array;
        dev_t fts_dev;
        char *fts_path;
        int fts_rfd;
        int fts_cwd_fd;

        size_t fts_pathlen;
        size_t fts_nitems;
        int (*fts_compar) (struct _ftsent const **, struct _ftsent const **);
        int fts_options;
        struct hash_table *fts_leaf_optimization_works_ht;

        union {
                struct hash_table *ht;





                struct cycle_check_state *state;
        } fts_cycle;




        I_ring fts_fd_ring;
} FTS;

typedef struct _ftsent {
        struct _ftsent *fts_cycle;
        struct _ftsent *fts_parent;
        struct _ftsent *fts_link;
        DIR *fts_dirp;


        long fts_number;
        void *fts_pointer;
        char *fts_accpath;
        char *fts_path;
        int fts_errno;
        int fts_symfd;
        size_t fts_pathlen;

        FTS *fts_fts;



        ptrdiff_t fts_level;

        size_t fts_namelen;
        unsigned short int fts_info;



        unsigned short int fts_flags;





        unsigned short int fts_instr;

        struct stat fts_statp[1];
        char fts_name[];
} FTSENT;



 [[__nodiscard__]]
FTSENT *rpl_fts_children (FTS *, int) ;

[[__nodiscard__]]
int rpl_fts_close (FTS *) ;

[[__nodiscard__]]
FTS *rpl_fts_open (char * const *, int,
                   int (*)(const FTSENT **, const FTSENT **))
  __attribute__ ((__malloc__ (rpl_fts_close, 1))) ;

[[__nodiscard__]]
FTSENT *rpl_fts_read (FTS *) ;

int rpl_fts_set (FTS *, FTSENT *, int) ;


FTS *
xfts_open (char * const *, int options,
           int (*) (const FTSENT **, const FTSENT **))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (rpl_fts_close, 1)))
  __attribute__ ((__nonnull__ (1))) __attribute__ ((__returns_nonnull__));


_Bool

cycle_warning_required (FTS const *fts, FTSENT const *ent)
  __attribute__ ((__nonnull__ )) __attribute__ ((__pure__));
static 
      _Bool 
           affect_symlink_referent;


static 
      _Bool 
           recurse;


static 
      _Bool 
           verbose;



static struct dev_ino *root_dev_ino;


static char const *specified_context;


static char const *specified_user;
static char const *specified_role;
static char const *specified_range;
static char const *specified_type;



enum
{
  DEREFERENCE_OPTION = 0x7f + 1,
  NO_PRESERVE_ROOT,
  PRESERVE_ROOT,
  REFERENCE_FILE_OPTION
};

static struct option const long_options[] =
{
  {"recursive", 
               0
                          , 
                            ((void *)0)
                                , 'R'},
  {"dereference", 
                 0
                            , 
                              ((void *)0)
                                  , DEREFERENCE_OPTION},
  {"no-dereference", 
                    0
                               , 
                                 ((void *)0)
                                     , 'h'},
  {"no-preserve-root", 
                      0
                                 , 
                                   ((void *)0)
                                       , NO_PRESERVE_ROOT},
  {"preserve-root", 
                   0
                              , 
                                ((void *)0)
                                    , PRESERVE_ROOT},
  {"reference", 
               1
                                , 
                                  ((void *)0)
                                      , REFERENCE_FILE_OPTION},
  {"user", 
          1
                           , 
                             ((void *)0)
                                 , 'u'},
  {"role", 
          1
                           , 
                             ((void *)0)
                                 , 'r'},
  {"type", 
          1
                           , 
                             ((void *)0)
                                 , 't'},
  {"range", 
           1
                            , 
                              ((void *)0)
                                  , 'l'},
  {"verbose", 
             0
                        , 
                          ((void *)0)
                              , 'v'},
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




static int
compute_context_from_mask (char const *context, context_t *ret)
{
  
 _Bool 
      ok = 
           1
               ;
  context_t new_context = context_new (context);
  if (!new_context)
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("failed to create security context: %s"),
             quote (context));
      return 1;
    }
  do { if (specified_user && context_user_set ((new_context), specified_user)) { error (0, 
 (*__errno_location ())
 , gettext ("failed to set %s security context component to %s"), "user", quote (specified_user)); ok = 
 0
 ; } } while (0);
  do { if (specified_range && context_range_set ((new_context), specified_range)) { error (0, 
 (*__errno_location ())
 , gettext ("failed to set %s security context component to %s"), "range", quote (specified_range)); ok = 
 0
 ; } } while (0);
  do { if (specified_role && context_role_set ((new_context), specified_role)) { error (0, 
 (*__errno_location ())
 , gettext ("failed to set %s security context component to %s"), "role", quote (specified_role)); ok = 
 0
 ; } } while (0);
  do { if (specified_type && context_type_set ((new_context), specified_type)) { error (0, 
 (*__errno_location ())
 , gettext ("failed to set %s security context component to %s"), "type", quote (specified_type)); ok = 
 0
 ; } } while (0);

  if (!ok)
    {
      int saved_errno = 
                       (*__errno_location ())
                            ;
      context_free (new_context);
      
     (*__errno_location ()) 
           = saved_errno;
      return 1;
    }

  *ret = new_context;
  return 0;
}





static int
change_file_context (int fd, char const *file)
{
  char *file_context = 
                      ((void *)0)
                          ;
  context_t context ;
  char const * context_string;
  int errors = 0;

  if (specified_context == 
                          ((void *)0)
                              )
    {
      int status = (affect_symlink_referent
                    ? getfileconat (fd, file, &file_context)
                    : lgetfileconat (fd, file, &file_context));

      if (status < 0 && 
                       (*__errno_location ()) 
                             != 
                                61
                                       )
        {
          error (0, 
                   (*__errno_location ())
                        , gettext ("failed to get security context of %s"),
                 quotearg_style (shell_escape_always_quoting_style, file));
          return 1;
        }




      if (file_context == 
                         ((void *)0)
                             )
        {
          error (0, 0, gettext ("can't apply partial context to unlabeled file %s"),
                 quotearg_style (shell_escape_always_quoting_style, file));
          return 1;
        }

      if (compute_context_from_mask (file_context, &context))
        return 1;

      context_string = context_str (context);
    }
  else
    {
      context_string = specified_context;
    }

  if (file_context == 
                     ((void *)0) 
                          || ! (strcmp (context_string, file_context) == 0))
    {
      int fail = (affect_symlink_referent
                  ? setfileconat (fd, file, context_string)
                  : lsetfileconat (fd, file, context_string));

      if (fail)
        {
          errors = 1;
          error (0, 
                   (*__errno_location ())
                        , gettext ("failed to change context of %s to %s"),
                 quotearg_n_style (0, shell_escape_always_quoting_style, file), quote_n (1, context_string));
        }
    }

  if (specified_context == 
                          ((void *)0)
                              )
    {
      context_free (context);
      freecon (file_context);
    }

  return errors;
}





static 
      _Bool

process_file (FTS *fts, FTSENT *ent)
{
  char const *file_full_name = ent->fts_path;
  char const *file = ent->fts_accpath;
  const struct stat *file_stats = ent->fts_statp;
  
 _Bool 
      ok = 
           1
               ;

  switch (ent->fts_info)
    {
    case 1:
      if (recurse)
        {
          if ((root_dev_ino && ((*ent->fts_statp).st_ino == (*root_dev_ino).st_ino && (*ent->fts_statp).st_dev == (*root_dev_ino).st_dev)))
            {


              do { if ((strcmp (file_full_name, "/") == 0)) error (0, 0, gettext ("it is dangerous to operate recursively on %s"), quotearg_style (shell_escape_always_quoting_style, file_full_name)); else error (0, 0, gettext ("it is dangerous to operate recursively on %s (same as %s)"), quotearg_n_style (0, shell_escape_always_quoting_style, file_full_name), quotearg_n_style (1, shell_escape_always_quoting_style, "/")); error (0, 0, gettext ("use --no-preserve-root to override this failsafe")); } while (0);

              rpl_fts_set (fts, ent, 4);

              (__extension__ ({ __typeof__ (rpl_fts_read (fts)) __x = (rpl_fts_read (fts)); (void) __x; }));
              return 
                    0
                         ;
            }
          return 
                1
                    ;
        }
      break;

    case 6:
      if (! recurse)
        return 
              1
                  ;
      break;

    case 10:







      if (ent->fts_level == 0 && ent->fts_number == 0)
        {
          ent->fts_number = 1;
          rpl_fts_set (fts, ent, 1);
          return 
                1
                    ;
        }
      error (0, ent->fts_errno, gettext ("cannot access %s"),
             quotearg_style (shell_escape_always_quoting_style, file_full_name));
      ok = 
          0
               ;
      break;

    case 7:
      error (0, ent->fts_errno, "%s", quotearg_n_style_colon (0, shell_escape_quoting_style, file_full_name));
      ok = 
          0
               ;
      break;

    case 4:
      error (0, ent->fts_errno, gettext ("cannot read directory %s"),
             quotearg_style (shell_escape_always_quoting_style, file_full_name));
      ok = 
          0
               ;
      break;

    case 2:
      if (cycle_warning_required (fts, ent))
        {
          do { error (0, 0, gettext ("WARNING: Circular directory structure.\nThis almost certainly means that you have a corrupted file system.\nNOTIFY YOUR SYSTEM MANAGER.\nThe following directory is part of the cycle:\n  %s\n"), quotearg_n_style_colon (0, shell_escape_quoting_style, file_full_name)); } while (0);
          return 
                0
                     ;
        }
      break;

    default:
      break;
    }

  if (ent->fts_info == 6
      && ok && (root_dev_ino && ((*file_stats).st_ino == (*root_dev_ino).st_ino && (*file_stats).st_dev == (*root_dev_ino).st_dev)))
    {
      do { if ((strcmp (file_full_name, "/") == 0)) error (0, 0, gettext ("it is dangerous to operate recursively on %s"), quotearg_style (shell_escape_always_quoting_style, file_full_name)); else error (0, 0, gettext ("it is dangerous to operate recursively on %s (same as %s)"), quotearg_n_style (0, shell_escape_always_quoting_style, file_full_name), quotearg_n_style (1, shell_escape_always_quoting_style, "/")); error (0, 0, gettext ("use --no-preserve-root to override this failsafe")); } while (0);
      ok = 
          0
               ;
    }

  if (ok)
    {
      if (verbose)
        printf (gettext ("changing security context of %s\n"),
                quotearg_style (shell_escape_always_quoting_style, file_full_name));

      if (change_file_context (fts->fts_cwd_fd, file) != 0)
        ok = 
            0
                 ;
    }

  if ( ! recurse)
    rpl_fts_set (fts, ent, 4);

  return ok;
}





static 
      _Bool

process_files (char **files, int bit_flags)
{
  
 _Bool 
      ok = 
           1
               ;

  FTS *fts = xfts_open (files, bit_flags, 
                                         ((void *)0)
                                             );

  while (
        1
            )
    {
      FTSENT *ent;

      ent = rpl_fts_read (fts);
      if (ent == 
                ((void *)0)
                    )
        {
          if (
             (*__errno_location ()) 
                   != 0)
            {

              error (0, 
                       (*__errno_location ())
                            , gettext ("fts_read failed"));
              ok = 
                  0
                       ;
            }
          break;
        }

      ok &= process_file (fts, ent);
    }

  if (rpl_fts_close (fts) != 0)
    {
      error (0, 
               (*__errno_location ())
                    , gettext ("fts_close failed"));
      ok = 
          0
               ;
    }

  return ok;
}

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
      printf (gettext ("Usage: %s [OPTION]... CONTEXT FILE...\n  or:  %s [OPTION]... [-u USER] [-r ROLE] [-l RANGE] [-t TYPE] FILE...\n  or:  %s [OPTION]... --reference=RFILE FILE...\n")



  ,
        program_name, program_name, program_name);
      fputs_unlocked (gettext ("Change the SELinux security context of each FILE to CONTEXT.\nWith --reference, change the security context of each FILE to that of RFILE.\n"),
     stdout
     )


           ;

      emit_mandatory_arg_note ();

      fputs_unlocked (gettext ("      --dereference      affect the referent of each symbolic link (this is\n                         the default), rather than the symbolic link itself\n  -h, --no-dereference   affect symbolic links instead of any referenced file\n"),
     stdout
     )



           ;
      fputs_unlocked (gettext ("  -u, --user=USER        set user USER in the target security context\n  -r, --role=ROLE        set role ROLE in the target security context\n  -t, --type=TYPE        set type TYPE in the target security context\n  -l, --range=RANGE      set range RANGE in the target security context\n"),
     stdout
     )




           ;
      fputs_unlocked (gettext ("      --no-preserve-root  do not treat '/' specially (the default)\n      --preserve-root    fail to operate recursively on '/'\n"),
     stdout
     )


           ;
      fputs_unlocked (gettext ("      --reference=RFILE  use RFILE's security context rather than specifying\n                         a CONTEXT value\n"),
     stdout
     )


           ;
      fputs_unlocked (gettext ("  -R, --recursive        operate on files and directories recursively\n"),
     stdout
     )

           ;
      fputs_unlocked (gettext ("  -v, --verbose          output a diagnostic for every file processed\n"),
     stdout
     )

           ;
      fputs_unlocked (gettext ("\nThe following options modify how a hierarchy is traversed when the -R\noption is also specified.  If more than one is specified, only the final\none takes effect.\n\n  -H                     if a command line argument is a symbolic link\n                         to a directory, traverse it\n  -L                     traverse every symbolic link to a directory\n                         encountered\n  -P                     do not traverse any symbolic links (default)\n\n"),
     stdout
     )
           ;
      fputs_unlocked (gettext ("      --help        display this help and exit\n"),
     stdout
     );
      fputs_unlocked (gettext ("      --version     output version information and exit\n"),
     stdout
     );
      emit_ancillary_info ("chcon");
    }
  exit (status);
}

int
main (int argc, char **argv)
{

  int bit_flags = 0x0010;



  int dereference = -1;

  
 _Bool 
      ok;
  
 _Bool 
      preserve_root = 
                      0
                           ;
  
 _Bool 
      component_specified = 
                            0
                                 ;
  char *reference_file = 
                        ((void *)0)
                            ;
  int optc;

  ;
  set_program_name (argv[0]);
  setlocale (
            6
                  , "");
  bindtextdomain ("coreutils", "/usr/local/share/locale");
  textdomain ("coreutils");

  atexit (close_stdout);

  while ((optc = getopt_long (argc, argv, "HLPRhvu:r:t:l:", long_options, 
                                                                         ((void *)0)
                                                                             ))
         != -1)
    {
      switch (optc)
        {
        case 'H':
          bit_flags = 0x0001 | 0x0010;
          break;

        case 'L':
          bit_flags = 0x0002;
          break;

        case 'P':
          bit_flags = 0x0010;
          break;

        case 'h':
          dereference = 0;
          break;

        case DEREFERENCE_OPTION:

          dereference = 1;
          break;

        case NO_PRESERVE_ROOT:
          preserve_root = 
                         0
                              ;
          break;

        case PRESERVE_ROOT:
          preserve_root = 
                         1
                             ;
          break;

        case REFERENCE_FILE_OPTION:
          reference_file = optarg;
          break;

        case 'R':
          recurse = 
                   1
                       ;
          break;

        case 'f':

          break;

        case 'v':
          verbose = 
                   1
                       ;
          break;

        case 'u':
          specified_user = optarg;
          component_specified = 
                               1
                                   ;
          break;

        case 'r':
          specified_role = optarg;
          component_specified = 
                               1
                                   ;
          break;

        case 't':
          specified_type = optarg;
          component_specified = 
                               1
                                   ;
          break;

        case 'l':
          specified_range = optarg;
          component_specified = 
                               1
                                   ;
          break;

        case GETOPT_HELP_CHAR: usage (
       0
       ); break;;
        case GETOPT_VERSION_CHAR: version_etc (
       stdout
       , "chcon", "GNU coreutils", Version, ("Russell Coker"), ("Jim Meyering"), (char *) 
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

  if (recurse)
    {
      if (bit_flags == 0x0010)
        {
          if (dereference == 1)
            ((!!sizeof (struct { _Static_assert (
           1
           , "verify_expr (" "1" ", " "(error (1, 0, gettext (\"-R --dereference requires either -H or -L\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
           1
           , 0, gettext ("-R --dereference requires either -H or -L")), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
           1
           , 0, gettext ("-R --dereference requires either -H or -L")), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))))
                                                                ;
          affect_symlink_referent = 
                                   0
                                        ;
        }
      else
        {
          if (dereference == 0)
            ((!!sizeof (struct { _Static_assert (
           1
           , "verify_expr (" "1" ", " "(error (1, 0, gettext (\"-R -h requires -P\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
           1
           , 0, gettext ("-R -h requires -P")), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
           1
           , 0, gettext ("-R -h requires -P")), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))));
          affect_symlink_referent = 
                                   1
                                       ;
        }
    }
  else
    {
      bit_flags = 0x0010;
      affect_symlink_referent = (dereference != 0);
    }

  if (argc - optind < (reference_file || component_specified ? 1 : 2))
    {
      if (argc <= optind)
        error (0, 0, gettext ("missing operand"));
      else
        error (0, 0, gettext ("missing operand after %s"), quote (argv[argc - 1]));
      usage (
            1
                        );
    }

  if (reference_file)
    {
      char *ref_context = 
                         ((void *)0)
                             ;

      if (rpl_getfilecon (reference_file, &ref_context) < 0)
        ((!!sizeof (struct { _Static_assert (
       1
       , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), gettext (\"failed to get security context of %s\"), quotearg_style (shell_escape_always_quoting_style, reference_file)), assume (false))" ")"); int _gl_dummy; })) ? ((error (
       1
       , 
       (*__errno_location ())
       , gettext ("failed to get security context of %s"), quotearg_style (shell_escape_always_quoting_style, reference_file)), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
       1
       , 
       (*__errno_location ())
       , gettext ("failed to get security context of %s"), quotearg_style (shell_escape_always_quoting_style, reference_file)), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))))
                                      ;

      specified_context = ref_context;
    }
  else if (component_specified)
    {

      specified_context = 
                         ((void *)0)
                             ;
    }
  else
    {
      specified_context = argv[optind++];
      if (0 < is_selinux_enabled ()
          && security_check_context (specified_context) < 0)
        ((!!sizeof (struct { _Static_assert (
       1
       , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), gettext (\"invalid context: %s\"), quote (specified_context)), assume (false))" ")"); int _gl_dummy; })) ? ((error (
       1
       , 
       (*__errno_location ())
       , gettext ("invalid context: %s"), quote (specified_context)), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
       1
       , 
       (*__errno_location ())
       , gettext ("invalid context: %s"), quote (specified_context)), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))))
                                       ;
    }

  if (reference_file && component_specified)
    {
      error (0, 0, gettext ("conflicting security context specifiers given"));
      usage (
            1
                        );
    }

  if (recurse && preserve_root)
    {
      static struct dev_ino dev_ino_buf;
      root_dev_ino = get_root_dev_ino (&dev_ino_buf);
      if (root_dev_ino == 
                         ((void *)0)
                             )
        ((!!sizeof (struct { _Static_assert (
       1
       , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), gettext (\"failed to get attributes of %s\"), quotearg_style (shell_escape_always_quoting_style, \"/\")), assume (false))" ")"); int _gl_dummy; })) ? ((error (
       1
       , 
       (*__errno_location ())
       , gettext ("failed to get attributes of %s"), quotearg_style (shell_escape_always_quoting_style, "/")), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
       1
       , 
       (*__errno_location ())
       , gettext ("failed to get attributes of %s"), quotearg_style (shell_escape_always_quoting_style, "/")), ((
       0
       ) ? (void) 0 : __builtin_unreachable ()))))
                           ;
    }
  else
    {
      root_dev_ino = 
                    ((void *)0)
                        ;
    }

  ok = process_files (argv + optind, bit_flags | 0x0008);

  return ok ? 
             0 
                          : 
                            1
                                        ;
}
