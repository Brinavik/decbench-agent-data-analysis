
       


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




typedef ptrdiff_t idx_t;
struct tm_zone
{


  struct tm_zone *next;
  char tz_is_set;
  char abbrs[];
};



enum { DEFAULT_MXFAST = 64 * sizeof (size_t) / 4 };




enum { ABBR_SIZE_MIN = DEFAULT_MXFAST - 
                                       __builtin_offsetof (
                                       struct tm_zone
                                       , 
                                       abbrs
                                       ) 
                                                                        };




static timezone_t const local_tz = (timezone_t) 1;




static void
extend_abbrs (char *abbrs, char const *abbr, size_t abbr_size)
{
  memcpy (abbrs, abbr, abbr_size);
  abbrs[abbr_size] = '\0';
}



timezone_t
tzalloc (char const *name)
{
  size_t name_size = name ? strlen (name) + 1 : 0;
  size_t abbr_size = name_size < ABBR_SIZE_MIN ? ABBR_SIZE_MIN : name_size + 1;
  timezone_t tz = malloc (((
                         __builtin_offsetof (
                         struct tm_zone
                         , 
                         abbrs
                         ) 
                         + _Alignof (struct tm_zone) - 1 + (abbr_size)) & ~ (_Alignof (struct tm_zone) - 1)));
  if (tz)
    {
      tz->next = 
                ((void *)0)
                    ;



      tz->tz_is_set = !!name;
      tz->abbrs[0] = '\0';
      if (name)
        extend_abbrs (tz->abbrs, name, name_size);
    }
  return tz;
}





static 
      _Bool

save_abbr (timezone_t tz, struct tm *tm)
{

  char const *zone = 
                    ((void *)0)
                        ;
  char *zone_copy = (char *) "";






  zone = tm->tm_zone;
  if (!zone || ((char *) tm <= zone && zone < (char *) (tm + 1)))
    return 
          1
              ;

  if (*zone)
    {
      zone_copy = tz->abbrs;

      while (strcmp (zone_copy, zone) != 0)
        {
          if (! (*zone_copy || (zone_copy == tz->abbrs && tz->tz_is_set)))
            {
              idx_t zone_size = strlen (zone) + 1;
              if (zone_size < tz->abbrs + ABBR_SIZE_MIN - zone_copy)
                extend_abbrs (zone_copy, zone, zone_size);
              else
                {
                  tz = tz->next = tzalloc (zone);
                  if (!tz)
                    return 
                          0
                               ;
                  tz->tz_is_set = 0;
                  zone_copy = tz->abbrs;
                }
              break;
            }

          zone_copy += strlen (zone_copy) + 1;
          if (!*zone_copy && tz->next)
            {
              tz = tz->next;
              zone_copy = tz->abbrs;
            }
        }
    }



  tm->tm_zone = zone_copy;






  return 
        1
            ;
}


void
tzfree (timezone_t tz)
{
  if (tz != local_tz)
    while (tz)
      {
        timezone_t next = tz->next;
        free (tz);
        tz = next;
      }
}





static char *
getenv_TZ (void)
{
  return getenv ("TZ");
}



static int
setenv_TZ (char const *tz)
{
  return tz ? setenv ("TZ", tz, 1) : unsetenv ("TZ");
}




static 
      _Bool

change_env (timezone_t tz)
{
  if (setenv_TZ (tz->tz_is_set ? tz->abbrs : 
                                            ((void *)0)
                                                ) != 0)
    return 
          0
               ;
  tzset ();
  return 
        1
            ;
}





static timezone_t
set_tz (timezone_t tz)
{
  char *env_tz = getenv_TZ ();
  if (env_tz
      ? tz->tz_is_set && strcmp (tz->abbrs, env_tz) == 0
      : !tz->tz_is_set)
    return local_tz;
  else
    {
      timezone_t old_tz = tzalloc (env_tz);
      if (!old_tz)
        return old_tz;
      if (! change_env (tz))
        {
          int saved_errno = 
                           (*__errno_location ())
                                ;
          tzfree (old_tz);
          
         (*__errno_location ()) 
               = saved_errno;
          return 
                ((void *)0)
                    ;
        }
      return old_tz;
    }
}




static 
      _Bool

revert_tz (timezone_t tz)
{
  if (tz == local_tz)
    return 
          1
              ;
  else
    {
      int saved_errno = 
                       (*__errno_location ())
                            ;
      
     _Bool 
          ok = change_env (tz);
      if (!ok)
        saved_errno = 
                     (*__errno_location ())
                          ;
      tzfree (tz);
      
     (*__errno_location ()) 
           = saved_errno;
      return ok;
    }
}


struct tm *
localtime_rz (timezone_t tz, time_t const *t, struct tm *tm)
{
  if (!tz)
    return gmtime_r (t, tm);
  else
    {
      timezone_t old_tz = set_tz (tz);
      if (old_tz)
        {
          
         _Bool 
              abbr_saved = localtime_r (t, tm) && save_abbr (tz, tm);
          if (revert_tz (old_tz) && abbr_saved)
            return tm;
        }
      return 
            ((void *)0)
                ;
    }
}


time_t
mktime_z (timezone_t tz, struct tm *tm)
{
  if (!tz)
    return timegm (tm);
  else
    {
      timezone_t old_tz = set_tz (tz);
      if (old_tz)
        {
          struct tm tm_1;
          tm_1.tm_sec = tm->tm_sec;
          tm_1.tm_min = tm->tm_min;
          tm_1.tm_hour = tm->tm_hour;
          tm_1.tm_mday = tm->tm_mday;
          tm_1.tm_mon = tm->tm_mon;
          tm_1.tm_year = tm->tm_year;
          tm_1.tm_yday = -1;
          tm_1.tm_isdst = tm->tm_isdst;
          time_t t = mktime (&tm_1);
          
         _Bool 
              ok = 0 <= tm_1.tm_yday;

          ok = ok && save_abbr (tz, &tm_1);

          if (revert_tz (old_tz) && ok)
            {
              *tm = tm_1;
              return t;
            }
        }
      return -1;
    }
}
