




       


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

       
       

typedef time_t mktime_offset_t;
extern time_t mktime_internal (struct tm *tp,
                                     struct tm *(*func) (time_t const *,
                                                         struct tm *),
                                     mktime_offset_t *offset) ;
typedef long int long_int;



_Static_assert (0x7fffffff <= ((long_int) (! (! ((long_int) 0 < (long_int) -1)) ? (long_int) -1 : ((((long_int) 1 << ((sizeof (long_int) * 8) - 2)) - 1) * 2 + 1))) / 4 / 366 / 24 / 60 / 60, "verify (" "INT_MAX <= TYPE_MAXIMUM (long_int) / 4 / 366 / 24 / 60 / 60" ")");
static long_int
shr (long_int a, int b)
{
  long_int one = 1;
  return (-one >> 1 == -1
   ? a >> b
   : (a + (a < 0)) / (one << b) - (a < 0));
}



static long_int const mktime_min
  = (((! ((time_t) 0 < (time_t) -1))
      && ((time_t) ~ ((time_t) (! (! ((time_t) 0 < (time_t) -1)) ? (time_t) -1 : ((((time_t) 1 << ((sizeof (time_t) * 8) - 2)) - 1) * 2 + 1)))) < ((long_int) ~ ((long_int) (! (! ((long_int) 0 < (long_int) -1)) ? (long_int) -1 : ((((long_int) 1 << ((sizeof (long_int) * 8) - 2)) - 1) * 2 + 1)))))
     ? ((long_int) ~ ((long_int) (! (! ((long_int) 0 < (long_int) -1)) ? (long_int) -1 : ((((long_int) 1 << ((sizeof (long_int) * 8) - 2)) - 1) * 2 + 1)))) : ((time_t) ~ ((time_t) (! (! ((time_t) 0 < (time_t) -1)) ? (time_t) -1 : ((((time_t) 1 << ((sizeof (time_t) * 8) - 2)) - 1) * 2 + 1)))));
static long_int const mktime_max
  = (((long_int) (! (! ((long_int) 0 < (long_int) -1)) ? (long_int) -1 : ((((long_int) 1 << ((sizeof (long_int) * 8) - 2)) - 1) * 2 + 1))) < ((time_t) (! (! ((time_t) 0 < (time_t) -1)) ? (time_t) -1 : ((((time_t) 1 << ((sizeof (time_t) * 8) - 2)) - 1) * 2 + 1)))
     ? ((long_int) (! (! ((long_int) 0 < (long_int) -1)) ? (long_int) -1 : ((((long_int) 1 << ((sizeof (long_int) * 8) - 2)) - 1) * 2 + 1))) : ((time_t) (! (! ((time_t) 0 < (time_t) -1)) ? (time_t) -1 : ((((time_t) 1 << ((sizeof (time_t) * 8) - 2)) - 1) * 2 + 1))));



_Static_assert (1900 % 100 == 0, "verify (" "TM_YEAR_BASE % 100 == 0" ")");


static 
      _Bool

leapyear (long_int year)
{


  return
    ((year & 3) == 0
     && (year % 100 != 0
  || ((year / 100) & 3) == (- (1900 / 100) & 3)));
}



static

const unsigned short int __mon_yday[2][13] =
  {

    { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 },

    { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 }
  };




static 
      _Bool

isdst_differ (int a, int b)
{
  return (!a != !b) && (0 <= a) && (0 <= b);
}
static long_int
ydhms_diff (long_int year1, long_int yday1, int hour1, int min1, int sec1,
     int year0, int yday0, int hour0, int min0, int sec0)
{
  _Static_assert (-1 / 2 == 0, "verify (" "-1 / 2 == 0" ")");



  int a4 = shr (year1, 2) + shr (1900, 2) - ! (year1 & 3);
  int b4 = shr (year0, 2) + shr (1900, 2) - ! (year0 & 3);
  int a100 = (a4 + (a4 < 0)) / 25 - (a4 < 0);
  int b100 = (b4 + (b4 < 0)) / 25 - (b4 < 0);
  int a400 = shr (a100, 2);
  int b400 = shr (b100, 2);
  int intervening_leap_days = (a4 - b4) - (a100 - b100) + (a400 - b400);


  long_int years = year1 - year0;
  long_int days = 365 * years + yday1 - yday0 + intervening_leap_days;
  long_int hours = 24 * days + hour1 - hour0;
  long_int minutes = 60 * hours + min1 - min0;
  long_int seconds = 60 * minutes + sec1 - sec0;
  return seconds;
}



static long_int
long_int_avg (long_int a, long_int b)
{
  return shr (a, 1) + shr (b, 1) + ((a | b) & 1);
}
static long_int
tm_diff (long_int year, long_int yday, int hour, int min, int sec,
  struct tm const *tp)
{
  return ydhms_diff (year, yday, hour, min, sec,
       tp->tm_year, tp->tm_yday,
       tp->tm_hour, tp->tm_min, tp->tm_sec);
}




static struct tm *
convert_time (struct tm *(*convert) (const time_t *, struct tm *),
       long_int t, struct tm *tm)
{
  time_t x = t;
  return convert (&x, tm);
}






static struct tm *
ranged_convert (struct tm *(*convert) (const time_t *, struct tm *),
  long_int *t, struct tm *tp)
{
  long_int t1 = (*t < mktime_min ? mktime_min
   : *t <= mktime_max ? *t : mktime_max);
  struct tm *r = convert_time (convert, t1, tp);
  if (r)
    {
      *t = t1;
      return r;
    }
  if (
     (*__errno_location ()) 
           != 
              75
                       )
    return 
          ((void *)0)
              ;

  long_int bad = t1;
  long_int ok = 0;
  struct tm oktm; oktm.tm_sec = -1;




  while (
        1
            )
    {
      long_int mid = long_int_avg (ok, bad);
      if (mid == ok || mid == bad)
 break;
      if (convert_time (convert, mid, tp))
 ok = mid, oktm = *tp;
      else if (
              (*__errno_location ()) 
                    != 
                       75
                                )
 return 
       ((void *)0)
           ;
      else
 bad = mid;
    }

  if (oktm.tm_sec < 0)
    return 
          ((void *)0)
              ;
  *t = ok;
  *tp = oktm;
  return tp;
}
time_t
mktime_internal (struct tm *tp,
     struct tm *(*convert) (const time_t *, struct tm *),
     mktime_offset_t *offset)
{
  struct tm tm;





  int remaining_probes = 6;



  int sec = tp->tm_sec;
  int min = tp->tm_min;
  int hour = tp->tm_hour;
  int mday = tp->tm_mday;
  int mon = tp->tm_mon;
  int year_requested = tp->tm_year;
  int isdst = tp->tm_isdst;


  int dst2 = 0;


  int mon_remainder = mon % 12;
  int negative_mon_remainder = mon_remainder < 0;
  int mon_years = mon / 12 - negative_mon_remainder;
  long_int lyear_requested = year_requested;
  long_int year = lyear_requested + mon_years;






  int mon_yday = ((__mon_yday[leapyear (year)]
     [mon_remainder + 12 * negative_mon_remainder])
    - 1);
  long_int lmday = mday;
  long_int yday = mon_yday + lmday;

  mktime_offset_t off = *offset;
  int negative_offset_guess;

  int sec_requested = sec;

  if (1)
    {


      if (sec < 0)
 sec = 0;
      if (59 < sec)
 sec = 59;
    }




  __builtin_sub_overflow (0, off, &negative_offset_guess);
  long_int t0 = ydhms_diff (year, yday, hour, min, sec,
       1970 - 1900, 0, 0, 0,
       negative_offset_guess);
  long_int t = t0, t1 = t0, t2 = t0;



  while (
        1
            )
    {
      if (! ranged_convert (convert, &t, &tm))
 return -1;
      long_int dt = tm_diff (year, yday, hour, min, sec, &tm);
      if (dt == 0)
 break;

      if (t == t1 && t != t2
   && (tm.tm_isdst < 0
       || (isdst < 0
    ? dst2 <= (tm.tm_isdst != 0)
    : (isdst != 0) != (tm.tm_isdst != 0))))
 goto offset_found;

      remaining_probes--;
      if (remaining_probes == 0)
 {
   (
  (*__errno_location ()) 
  = (
  75
  ));
   return -1;
 }

      t1 = t2, t2 = t, t += dt, dst2 = tm.tm_isdst != 0;
    }



  if (isdst_differ (isdst, tm.tm_isdst))
    {
      int stride = 601200;






      int duration_max = 536454000;



      int delta_bound = duration_max / 2 + stride;

      int delta, direction;

      for (delta = stride; delta < delta_bound; delta += stride)
 for (direction = -1; direction <= 1; direction += 2)
   {
     long_int ot;
     if (! __builtin_add_overflow (t, delta * direction, &ot))
       {
  struct tm otm;
  if (! ranged_convert (convert, &ot, &otm))
    return -1;
  if (! isdst_differ (isdst, otm.tm_isdst))
    {


      long_int gt = ot + tm_diff (year, yday, hour, min, sec,
      &otm);
      if (mktime_min <= gt && gt <= mktime_max)
        {
   if (convert_time (convert, gt, &tm))
     {
       t = gt;
       goto offset_found;
     }
   if (
      (*__errno_location ()) 
            != 
               75
                        )
     return -1;
        }
    }
       }
   }

      (
     (*__errno_location ()) 
     = (
     75
     ));
      return -1;
    }

 offset_found:



  __builtin_sub_overflow (t, t0, offset);
  __builtin_sub_overflow (*offset, negative_offset_guess, offset);

  if (1 && sec_requested != tm.tm_sec)
    {


      long_int sec_adjustment = sec == 0 && tm.tm_sec == 60;
      sec_adjustment -= sec;
      sec_adjustment += sec_requested;
      if (__builtin_add_overflow (t, sec_adjustment, &t)
   || ! (mktime_min <= t && t <= mktime_max))
 {
   (
  (*__errno_location ()) 
  = (
  75
  ));
   return -1;
 }
      if (! convert_time (convert, t, &tm))
 return -1;
    }

  *tp = tm;
  return t;
}



