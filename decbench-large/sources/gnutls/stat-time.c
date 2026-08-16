
       
       

       
       
       
       
extern int _gl_cxxalias_dummy

                                      ;

extern int _gl_cxxalias_dummy;


       


struct __time_t_must_be_integral {
  unsigned int __floating_time_t_unsupported : (time_t) 1;
};
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
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
       






extern inline long int __attribute__ ((__pure__))
get_stat_atime_ns (struct stat const *st)
{

  return ((st)->st_atim).tv_nsec;





}


extern inline long int __attribute__ ((__pure__))
get_stat_ctime_ns (struct stat const *st)
{

  return ((st)->st_ctim).tv_nsec;





}


extern inline long int __attribute__ ((__pure__))
get_stat_mtime_ns (struct stat const *st)
{

  return ((st)->st_mtim).tv_nsec;





}


extern inline long int __attribute__ ((__pure__))
get_stat_birthtime_ns (struct stat const *st __attribute__ ((__unused__)))
{





  return 0;

}


extern inline struct timespec __attribute__ ((__pure__))
get_stat_atime (struct stat const *st)
{

  return ((st)->st_atim);






}


extern inline struct timespec __attribute__ ((__pure__))
get_stat_ctime (struct stat const *st)
{

  return ((st)->st_ctim);






}


extern inline struct timespec __attribute__ ((__pure__))
get_stat_mtime (struct stat const *st)
{

  return ((st)->st_mtim);






}



extern inline struct timespec __attribute__ ((__pure__))
get_stat_birthtime (struct stat const *st __attribute__ ((__unused__)))
{
  struct timespec t;
  t.tv_sec = -1;
  t.tv_nsec = -1;
  return t;
}






extern inline int
stat_time_normalize (int result, struct stat *st __attribute__ ((__unused__)))
{
  return result;
}






