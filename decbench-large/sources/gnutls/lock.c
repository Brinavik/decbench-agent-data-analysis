
       
       
       
       
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
extern int _gl_cxxalias_dummy;



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
#pragma weak thrd_exit
       
#pragma weak pthread_mutex_init
#pragma weak pthread_mutex_lock
#pragma weak pthread_mutex_unlock
#pragma weak pthread_mutex_destroy
#pragma weak pthread_rwlock_init
#pragma weak pthread_rwlock_rdlock
#pragma weak pthread_rwlock_wrlock
#pragma weak pthread_rwlock_unlock
#pragma weak pthread_rwlock_destroy
#pragma weak pthread_once
#pragma weak pthread_cond_init
#pragma weak pthread_cond_wait
#pragma weak pthread_cond_signal
#pragma weak pthread_cond_broadcast
#pragma weak pthread_cond_destroy
#pragma weak pthread_mutexattr_init
#pragma weak pthread_mutexattr_settype
#pragma weak pthread_mutexattr_destroy
#pragma weak pthread_rwlockattr_init

#pragma weak pthread_rwlockattr_setkind_np

#pragma weak pthread_rwlockattr_destroy

#pragma weak pthread_self
#pragma weak pthread_mutexattr_gettype

typedef pthread_mutex_t gl_lock_t;
typedef pthread_rwlock_t gl_rwlock_t;
extern int glthread_rwlock_init_for_glibc (pthread_rwlock_t *lock);
typedef pthread_mutex_t gl_recursive_lock_t;
extern int glthread_recursive_lock_init_multithreaded (gl_recursive_lock_t *lock);
typedef pthread_once_t gl_once_t;
extern int glthread_once_singlethreaded (pthread_once_t *once_control);
int
glthread_rwlock_init_for_glibc (pthread_rwlock_t *lock)
{
  pthread_rwlockattr_t attributes;
  int err;

  err = pthread_rwlockattr_init (&attributes);
  if (err != 0)
    return err;




  err = pthread_rwlockattr_setkind_np (&attributes,
                                       PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP);
  if (err == 0)
    err = pthread_rwlock_init(lock, &attributes);


  pthread_rwlockattr_destroy (&attributes);
  return err;
}
int
glthread_recursive_lock_init_multithreaded (gl_recursive_lock_t *lock)
{
  pthread_mutexattr_t attributes;
  int err;

  err = pthread_mutexattr_init (&attributes);
  if (err != 0)
    return err;
  err = pthread_mutexattr_settype (&attributes, PTHREAD_MUTEX_RECURSIVE);
  if (err != 0)
    {
      pthread_mutexattr_destroy (&attributes);
      return err;
    }
  err = pthread_mutex_init (lock, &attributes);
  if (err != 0)
    {
      pthread_mutexattr_destroy (&attributes);
      return err;
    }
  err = pthread_mutexattr_destroy (&attributes);
  if (err != 0)
    return err;
  return 0;
}
static const pthread_once_t fresh_once = 
                                        0
                                                         ;

int
glthread_once_singlethreaded (pthread_once_t *once_control)
{


  char *firstbyte = (char *)once_control;
  if (*firstbyte == *(const char *)&fresh_once)
    {

      *firstbyte = ~ *(const char *)&fresh_once;
      return 1;
    }
  else
    return 0;
}
