


       


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

size_t nstrftime (char *__restrict__, size_t, char const *, struct tm const *,
                  timezone_t __tz, int __ns);

struct tm_zone
{


  struct tm_zone *next;
  char tz_is_set;
  char abbrs[];
};


       
       
       
       
       
       
       
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

       

static char *memcpy_lowcase (char *dest, const char *src,
                               size_t len );

static char *
memcpy_lowcase (char *dest, const char *src, size_t len )
{
  while (len-- > 0)
    dest[len] = 
               (__extension__ ({ int __res; if (sizeof (
               (unsigned char) src[len]
               ) > 1) { if (__builtin_constant_p (
               (unsigned char) src[len]
               )) { int __c = (
               (unsigned char) src[len]
               ); __res = __c < -128 || __c > 255 ? __c : (*__ctype_tolower_loc ())[__c]; } else __res = tolower (
               (unsigned char) src[len]
               ); } else __res = (*__ctype_tolower_loc ())[(int) (
               (unsigned char) src[len]
               )]; __res; }))
                                                ;
  return dest;
}

static char *memcpy_uppcase (char *dest, const char *src,
                               size_t len );

static char *
memcpy_uppcase (char *dest, const char *src, size_t len )
{
  while (len-- > 0)
    dest[len] = 
               (__extension__ ({ int __res; if (sizeof (
               (unsigned char) src[len]
               ) > 1) { if (__builtin_constant_p (
               (unsigned char) src[len]
               )) { int __c = (
               (unsigned char) src[len]
               ); __res = __c < -128 || __c > 255 ? __c : (*__ctype_toupper_loc ())[__c]; } else __res = toupper (
               (unsigned char) src[len]
               ); } else __res = (*__ctype_toupper_loc ())[(int) (
               (unsigned char) src[len]
               )]; __res; }))
                                                ;
  return dest;
}
static int iso_week_days (int, int);

__inline__

static int
iso_week_days (int yday, int wday)
{

  int big_enough_multiple_of_7 = (-(-366) / 7 + 2) * 7;
  return (yday
          - (yday - wday + 4 + big_enough_multiple_of_7) % 7
          + 4 - 1);
}
static size_t __strftime_internal (char *, size_t,
                                   const char *, const struct tm *,
                                   
                                  _Bool
                                      , int, int, 
                                                  _Bool 
                                                       *
                                   , timezone_t tz, int ns );







size_t
nstrftime (char *s, size_t maxsize,
             const char *format,
             const struct tm *tp , timezone_t tz, int ns )
{
  
 _Bool 
      tzset_called = 
                     0
                          ;
  return __strftime_internal (s, maxsize, format, tp, 
                                                                   0
                                                                        ,
                              0, -1, &tzset_called , tz, ns );
}
static size_t
__strftime_internal (char *s, size_t maxsize,
                     const char *format,
                     const struct tm *tp, 
                                         _Bool 
                                              upcase,
                     int yr_spec, int width, 
                                            _Bool 
                                                 *tzset_called
                     , timezone_t tz, int ns )
{







  int saved_errno = 
                   (*__errno_location ())
                        ;
  int hour12 = tp->tm_hour;
  const char *zone;
  size_t i = 0;
  char *p = s;
  const char *f;




  zone = 
        ((void *)0)
            ;







  zone = (const char *) tp->tm_zone;
  if (! zone)
    zone = "";

  if (hour12 > 12)
    hour12 -= 12;
  else
    if (hour12 == 0)
      hour12 = 12;

  for (f = format; *f != '\0'; width = -1, f++)
    {
      int pad = 0;
      int modifier;
      int digits = 0;
      int number_value;
      unsigned int u_number_value;
      
     _Bool 
          negative_number;
      
     _Bool 
          always_output_a_sign;
      int tz_colon_mask;
      const char *subfmt;
      char *bufp;
      char buf[1
                 + 2
                 + (sizeof (int) < sizeof (time_t)
                    ? (((((sizeof (time_t) * 8) - (! ((__typeof__ (time_t)) 0 < (__typeof__ (time_t)) -1))) * 146 + 484) / 485) + (! ((__typeof__ (time_t)) 0 < (__typeof__ (time_t)) -1)))
                    : (((((sizeof (int) * 8) - (! ((__typeof__ (int)) 0 < (__typeof__ (int)) -1))) * 146 + 484) / 485) + (! ((__typeof__ (int)) 0 < (__typeof__ (int)) -1))))];
      
     _Bool 
          to_lowcase = 
                       0
                            ;
      
     _Bool 
          to_uppcase = upcase;
      size_t colons;
      
     _Bool 
          change_case = 
                        0
                             ;
      int format_char;
      int subwidth;
      if (*f != '%')
        {
          do { size_t _n = (1); size_t _w = pad == '-' || width < 0 ? 0 : width; size_t _incr = _n < _w ? _w : _n; if (_incr >= maxsize - i) { 
         (*__errno_location ()) 
         = 
         34
         ; return 0; } if (p) { if (_n < _w) { size_t _delta = _w - _n; if (pad == '0' || pad == '+') (memset (p, '0', _delta), (p) += (_delta)); else (memset (p, ' ', _delta), (p) += (_delta)); } *p = *f; ((p) += (_n)); } i += _incr; } while (0);
          continue;
        }




      while (1)
        {
          switch (*++f)
            {

            case '_':
            case '-':
            case '+':
            case '0':
              pad = *f;
              continue;


            case '^':
              to_uppcase = 
                          1
                              ;
              continue;
            case '#':
              change_case = 
                           1
                               ;
              continue;

            default:
              break;
            }
          break;
        }

      if (((unsigned int) (*f) - '0' <= 9))
        {
          width = 0;
          do
            {
              if (__builtin_mul_overflow (width, 10, &width)
                  || __builtin_add_overflow (width, *f - '0', &width))
                width = 0x7fffffff;
              ++f;
            }
          while (((unsigned int) (*f) - '0' <= 9));
        }


      switch (*f)
        {
        case 'E':
        case 'O':
          modifier = *f++;
          break;

        default:
          modifier = 0;
          break;
        }


      format_char = *f;
      switch (format_char)
        {
        case '%':
          if (modifier != 0)
            goto bad_format;
          do { size_t _n = (1); size_t _w = pad == '-' || width < 0 ? 0 : width; size_t _incr = _n < _w ? _w : _n; if (_incr >= maxsize - i) { 
         (*__errno_location ()) 
         = 
         34
         ; return 0; } if (p) { if (_n < _w) { size_t _delta = _w - _n; if (pad == '0' || pad == '+') (memset (p, '0', _delta), (p) += (_delta)); else (memset (p, ' ', _delta), (p) += (_delta)); } *p = *f; ((p) += (_n)); } i += _incr; } while (0);
          break;

        case 'a':
          if (modifier != 0)
            goto bad_format;
          if (change_case)
            {
              to_uppcase = 
                          1
                              ;
              to_lowcase = 
                          0
                               ;
            }




          goto underlying_strftime;


        case 'A':
          if (modifier != 0)
            goto bad_format;
          if (change_case)
            {
              to_uppcase = 
                          1
                              ;
              to_lowcase = 
                          0
                               ;
            }




          goto underlying_strftime;


        case 'b':
        case 'h':
          if (change_case)
            {
              to_uppcase = 
                          1
                              ;
              to_lowcase = 
                          0
                               ;
            }
          if (modifier == 'E')
            goto bad_format;







          goto underlying_strftime;


        case 'B':
          if (modifier == 'E')
            goto bad_format;
          if (change_case)
            {
              to_uppcase = 
                          1
                              ;
              to_lowcase = 
                          0
                               ;
            }







          goto underlying_strftime;


        case 'c':
          if (modifier == 'O')
            goto bad_format;
          goto underlying_strftime;


        subformat:
          subwidth = -1;
        subformat_width:
          {
            size_t len = __strftime_internal (
                                             ((void *)0)
                                                 , (size_t) -1,
                                              subfmt, tp, to_uppcase,
                                              pad, subwidth, tzset_called
                                              , tz, ns );
            do { size_t _n = (len); size_t _w = pad == '-' || width < 0 ? 0 : width; size_t _incr = _n < _w ? _w : _n; if (_incr >= maxsize - i) { 
           (*__errno_location ()) 
           = 
           34
           ; return 0; } if (p) { if (_n < _w) { size_t _delta = _w - _n; if (pad == '0' || pad == '+') (memset (p, '0', _delta), (p) += (_delta)); else (memset (p, ' ', _delta), (p) += (_delta)); } __strftime_internal (p, maxsize - i, subfmt, tp, to_uppcase, pad, subwidth, tzset_called , tz, ns ); ((p) += (_n)); } i += _incr; } while (0)



                                                                  ;
          }
          break;


        underlying_strftime:
          {


            char ufmt[5];
            char *u = ufmt;
            char ubuf[1024];
            size_t len;
            *u++ = ' ';
            *u++ = '%';
            if (modifier != 0)
              *u++ = modifier;
            *u++ = format_char;
            *u = '\0';
            len = strftime (ubuf, sizeof ubuf, ufmt, tp);
            if (len != 0)
              do { size_t _n = (len - 1); size_t _w = pad == '-' || width < 0 ? 0 : width; size_t _incr = _n < _w ? _w : _n; if (_incr >= maxsize - i) { 
             (*__errno_location ()) 
             = 
             34
             ; return 0; } if (p) { if (_n < _w) { size_t _delta = _w - _n; if (pad == '0' || pad == '+') (memset (p, '0', _delta), (p) += (_delta)); else (memset (p, ' ', _delta), (p) += (_delta)); } if (to_lowcase) memcpy_lowcase (p, (ubuf + 1), _n ); else if (to_uppcase) memcpy_uppcase (p, (ubuf + 1), _n ); else memcpy ((void *) p, (void const *) (ubuf + 1), _n); ((p) += (_n)); } i += _incr; } while (0);
          }
          break;


        case 'C':
          if (modifier == 'E')
            {
              goto underlying_strftime;

            }

          {
            
           _Bool 
                negative_year = tp->tm_year < - 1900;
            
           _Bool 
                zero_thru_1899 = !negative_year & (tp->tm_year < 0);
            int century = ((tp->tm_year - 99 * zero_thru_1899) / 100
                           + 1900 / 100);
            do { digits = 2; negative_number = negative_year; u_number_value = century; goto do_yearish; } while (0);
          }

        case 'x':
          if (modifier == 'O')
            goto bad_format;
          goto underlying_strftime;

        case 'D':
          if (modifier != 0)
            goto bad_format;
          subfmt = "%m/%d/%y";
          goto subformat;

        case 'd':
          if (modifier == 'E')
            goto bad_format;

          do { digits = 2; number_value = tp->tm_mday; goto do_number; } while (0);

        case 'e':
          if (modifier == 'E')
            goto bad_format;

          do { digits = 2; number_value = tp->tm_mday; goto do_number_spacepad; } while (0);




        do_tz_offset:
          always_output_a_sign = 
                                1
                                    ;
          goto do_number_body;

        do_yearish:
          if (pad == 0)
            pad = yr_spec;
          always_output_a_sign
            = (pad == '+'
               && ((digits == 2 ? 99 : 9999) < u_number_value
                   || digits < width));
          goto do_maybe_signed_number;

        do_number_spacepad:
          if (pad == 0)
            pad = '_';

        do_number:

          negative_number = number_value < 0;
          u_number_value = number_value;

        do_signed_number:
          always_output_a_sign = 
                                0
                                     ;

        do_maybe_signed_number:
          tz_colon_mask = 0;

        do_number_body:





          if (modifier == 'O' && !negative_number)
            {
              goto underlying_strftime;

            }

          bufp = buf + sizeof (buf) / sizeof (buf[0]);

          if (negative_number)
            u_number_value = - u_number_value;

          do
            {
              if (tz_colon_mask & 1)
                *--bufp = ':';
              tz_colon_mask >>= 1;
              *--bufp = u_number_value % 10 + '0';
              u_number_value /= 10;
            }
          while (u_number_value != 0 || tz_colon_mask != 0);

        do_number_sign_and_padding:
          if (pad == 0)
            pad = '0';
          if (width < 0)
            width = digits;

          {
            char sign_char = (negative_number ? '-'
                                : always_output_a_sign ? '+'
                                : 0);
            int numlen = buf + sizeof buf / sizeof buf[0] - bufp;
            int shortage = width - !!sign_char - numlen;
            int padding = pad == '-' || shortage <= 0 ? 0 : shortage;

            if (sign_char)
              {
                if (pad == '_')
                  {
                    if (p)
                      (memset (p, ' ', padding), (p) += (padding));
                    i += padding;
                    width -= padding;
                  }
                do { size_t _n = (1); size_t _w = pad == '-' || 0 < 0 ? 0 : 0; size_t _incr = _n < _w ? _w : _n; if (_incr >= maxsize - i) { 
               (*__errno_location ()) 
               = 
               34
               ; return 0; } if (p) { if (_n < _w) { size_t _delta = _w - _n; if (pad == '0' || pad == '+') (memset (p, '0', _delta), (p) += (_delta)); else (memset (p, ' ', _delta), (p) += (_delta)); } *p = sign_char; ((p) += (_n)); } i += _incr; } while (0);
                width--;
              }

            do { size_t _n = (numlen); size_t _w = pad == '-' || width < 0 ? 0 : width; size_t _incr = _n < _w ? _w : _n; if (_incr >= maxsize - i) { 
           (*__errno_location ()) 
           = 
           34
           ; return 0; } if (p) { if (_n < _w) { size_t _delta = _w - _n; if (pad == '0' || pad == '+') (memset (p, '0', _delta), (p) += (_delta)); else (memset (p, ' ', _delta), (p) += (_delta)); } if (to_lowcase) memcpy_lowcase (p, (bufp), _n ); else if (to_uppcase) memcpy_uppcase (p, (bufp), _n ); else memcpy ((void *) p, (void const *) (bufp), _n); ((p) += (_n)); } i += _incr; } while (0);
          }
          break;

        case 'F':
          if (modifier != 0)
            goto bad_format;
          if (pad == 0 && width < 0)
            {
              pad = '+';
              subwidth = 4;
            }
          else
            {
              subwidth = width - 6;
              if (subwidth < 0)
                subwidth = 0;
            }
          subfmt = "%Y-%m-%d";
          goto subformat_width;

        case 'H':
          if (modifier == 'E')
            goto bad_format;

          do { digits = 2; number_value = tp->tm_hour; goto do_number; } while (0);

        case 'I':
          if (modifier == 'E')
            goto bad_format;

          do { digits = 2; number_value = hour12; goto do_number; } while (0);

        case 'k':
          if (modifier == 'E')
            goto bad_format;

          do { digits = 2; number_value = tp->tm_hour; goto do_number_spacepad; } while (0);

        case 'l':
          if (modifier == 'E')
            goto bad_format;

          do { digits = 2; number_value = hour12; goto do_number_spacepad; } while (0);

        case 'j':
          if (modifier == 'E')
            goto bad_format;

          do { digits = 3; negative_number = tp->tm_yday < -1; u_number_value = tp->tm_yday + 1U; goto do_signed_number; } while (0);

        case 'M':
          if (modifier == 'E')
            goto bad_format;

          do { digits = 2; number_value = tp->tm_min; goto do_number; } while (0);

        case 'm':
          if (modifier == 'E')
            goto bad_format;

          do { digits = 2; negative_number = tp->tm_mon < -1; u_number_value = tp->tm_mon + 1U; goto do_signed_number; } while (0);


        case 'N':
          if (modifier == 'E')
            goto bad_format;
          {
            int n = ns, ns_digits = 9;
            if (width <= 0)
              width = ns_digits;
            int ndigs = ns_digits;
            while (width < ndigs || (1 < ndigs && n % 10 == 0))
              ndigs--, n /= 10;
            for (int j = ndigs; 0 < j; j--)
              buf[j - 1] = n % 10 + '0', n /= 10;
            if (!pad)
              pad = '0';
            do { size_t _n = (ndigs); size_t _w = pad == '-' || 0 < 0 ? 0 : 0; size_t _incr = _n < _w ? _w : _n; if (_incr >= maxsize - i) { 
           (*__errno_location ()) 
           = 
           34
           ; return 0; } if (p) { if (_n < _w) { size_t _delta = _w - _n; if (pad == '0' || pad == '+') (memset (p, '0', _delta), (p) += (_delta)); else (memset (p, ' ', _delta), (p) += (_delta)); } if (to_lowcase) memcpy_lowcase (p, (buf), _n ); else if (to_uppcase) memcpy_uppcase (p, (buf), _n ); else memcpy ((void *) p, (void const *) (buf), _n); ((p) += (_n)); } i += _incr; } while (0);
            do { size_t _n = (0); size_t _w = pad == '-' || width - ndigs < 0 ? 0 : width - ndigs; size_t _incr = _n < _w ? _w : _n; if (_incr >= maxsize - i) { 
           (*__errno_location ()) 
           = 
           34
           ; return 0; } if (p) { if (_n < _w) { size_t _delta = _w - _n; if (pad == '0' || pad == '+') (memset (p, '0', _delta), (p) += (_delta)); else (memset (p, ' ', _delta), (p) += (_delta)); } (void) 0; ((p) += (_n)); } i += _incr; } while (0);
          }
          break;


        case 'n':
          do { size_t _n = (1); size_t _w = pad == '-' || width < 0 ? 0 : width; size_t _incr = _n < _w ? _w : _n; if (_incr >= maxsize - i) { 
         (*__errno_location ()) 
         = 
         34
         ; return 0; } if (p) { if (_n < _w) { size_t _delta = _w - _n; if (pad == '0' || pad == '+') (memset (p, '0', _delta), (p) += (_delta)); else (memset (p, ' ', _delta), (p) += (_delta)); } *p = '\n'; ((p) += (_n)); } i += _incr; } while (0);
          break;

        case 'P':
          to_lowcase = 
                      1
                          ;

          format_char = 'p';

          __attribute__ ((__fallthrough__));
        case 'p':
          if (change_case)
            {
              to_uppcase = 
                          0
                               ;
              to_lowcase = 
                          1
                              ;
            }




          goto underlying_strftime;


        case 'q':
          do { digits = 1; negative_number = 
         0
         ; u_number_value = ((tp->tm_mon * 11) >> 5) + 1; goto do_signed_number; } while (0);
          break;

        case 'R':
          subfmt = "%H:%M";
          goto subformat;

        case 'r':







          goto underlying_strftime;


        case 'S':
          if (modifier == 'E')
            goto bad_format;

          do { digits = 2; number_value = tp->tm_sec; goto do_number; } while (0);

        case 's':
          {
            struct tm ltm;
            time_t t;

            ltm = *tp;
            ltm.tm_yday = -1;
            t = mktime_z (tz, &ltm);
            if (ltm.tm_yday < 0)
              {
                
               (*__errno_location ()) 
                     = 
                       75
                                ;
                return 0;
              }




            bufp = buf + sizeof (buf) / sizeof (buf[0]);
            negative_number = t < 0;

            do
              {
                int d = t % 10;
                t /= 10;
                *--bufp = (negative_number ? -d : d) + '0';
              }
            while (t != 0);

            digits = 1;
            always_output_a_sign = 
                                  0
                                       ;
            goto do_number_sign_and_padding;
          }

        case 'X':
          if (modifier == 'O')
            goto bad_format;
          goto underlying_strftime;

        case 'T':
          subfmt = "%H:%M:%S";
          goto subformat;

        case 't':
          do { size_t _n = (1); size_t _w = pad == '-' || width < 0 ? 0 : width; size_t _incr = _n < _w ? _w : _n; if (_incr >= maxsize - i) { 
         (*__errno_location ()) 
         = 
         34
         ; return 0; } if (p) { if (_n < _w) { size_t _delta = _w - _n; if (pad == '0' || pad == '+') (memset (p, '0', _delta), (p) += (_delta)); else (memset (p, ' ', _delta), (p) += (_delta)); } *p = '\t'; ((p) += (_n)); } i += _incr; } while (0);
          break;

        case 'u':
          do { digits = 1; number_value = (tp->tm_wday - 1 + 7) % 7 + 1; goto do_number; } while (0);

        case 'U':
          if (modifier == 'E')
            goto bad_format;

          do { digits = 2; number_value = (tp->tm_yday - tp->tm_wday + 7) / 7; goto do_number; } while (0);

        case 'V':
        case 'g':
        case 'G':
          if (modifier == 'E')
            goto bad_format;
          {




            int year = (tp->tm_year
                        + (tp->tm_year < 0
                           ? 1900 % 400
                           : 1900 % 400 - 400));
            int year_adjust = 0;
            int days = iso_week_days (tp->tm_yday, tp->tm_wday);

            if (days < 0)
              {

                year_adjust = -1;
                days = iso_week_days (tp->tm_yday + (365 + 
                                                          ((
                                                          year - 1
                                                          ) % 4 == 0 && ((
                                                          year - 1
                                                          ) % 100 != 0 || (
                                                          year - 1
                                                          ) % 400 == 0))
                                                                             ),
                                      tp->tm_wday);
              }
            else
              {
                int d = iso_week_days (tp->tm_yday - (365 + 
                                                           ((
                                                           year
                                                           ) % 4 == 0 && ((
                                                           year
                                                           ) % 100 != 0 || (
                                                           year
                                                           ) % 400 == 0))
                                                                          ),
                                       tp->tm_wday);
                if (0 <= d)
                  {

                    year_adjust = 1;
                    days = d;
                  }
              }

            switch (*f)
              {
              case 'g':
                {
                  int yy = (tp->tm_year % 100 + year_adjust) % 100;
                  do { digits = 2; negative_number = 
                 0
                 ; u_number_value = (0 <= yy ? yy : tp->tm_year < -1900 - year_adjust ? -yy : yy + 100); goto do_yearish; } while (0)




                                           ;
                }

              case 'G':
                do { digits = 4; negative_number = tp->tm_year < -1900 - year_adjust; u_number_value = (tp->tm_year + (unsigned int) 1900 + year_adjust); goto do_yearish; } while (0)

                                            ;

              default:
                do { digits = 2; number_value = days / 7 + 1; goto do_number; } while (0);
              }
          }

        case 'W':
          if (modifier == 'E')
            goto bad_format;

          do { digits = 2; number_value = (tp->tm_yday - (tp->tm_wday - 1 + 7) % 7 + 7) / 7; goto do_number; } while (0);

        case 'w':
          if (modifier == 'E')
            goto bad_format;

          do { digits = 1; number_value = tp->tm_wday; goto do_number; } while (0);

        case 'Y':
          if (modifier == 'E')
            {
              goto underlying_strftime;

            }
          if (modifier == 'O')
            goto bad_format;

          do { digits = 4; negative_number = tp->tm_year < -1900; u_number_value = tp->tm_year + (unsigned int) 1900; goto do_yearish; } while (0)
                                                                ;

        case 'y':
          if (modifier == 'E')
            {
              goto underlying_strftime;

            }

          {
            int yy = tp->tm_year % 100;
            if (yy < 0)
              yy = tp->tm_year < - 1900 ? -yy : yy + 100;
            do { digits = 2; negative_number = 
           0
           ; u_number_value = yy; goto do_yearish; } while (0);
          }

        case 'Z':
          if (change_case)
            {
              to_uppcase = 
                          0
                               ;
              to_lowcase = 
                          1
                              ;
            }
          do { size_t _n = (strlen (zone)); size_t _w = pad == '-' || width < 0 ? 0 : width; size_t _incr = _n < _w ? _w : _n; if (_incr >= maxsize - i) { 
         (*__errno_location ()) 
         = 
         34
         ; return 0; } if (p) { if (_n < _w) { size_t _delta = _w - _n; if (pad == '0' || pad == '+') (memset (p, '0', _delta), (p) += (_delta)); else (memset (p, ' ', _delta), (p) += (_delta)); } if (to_lowcase) memcpy_lowcase (p, (zone), _n ); else if (to_uppcase) memcpy_uppcase (p, (zone), _n ); else memcpy ((void *) p, (void const *) (zone), _n); ((p) += (_n)); } i += _incr; } while (0);

          break;

        case ':':


          for (colons = 1; f[colons] == ':'; colons++)
            continue;
          if (f[colons] != 'z')
            goto bad_format;
          f += colons;
          goto do_z_conversion;

        case 'z':
          colons = 0;

        do_z_conversion:
          if (tp->tm_isdst < 0)
            break;

          {
            int diff;
            int hour_diff;
            int min_diff;
            int sec_diff;

            diff = tp->tm_gmtoff;
            negative_number = diff < 0 || (diff == 0 && *zone == '-');
            hour_diff = diff / 60 / 60;
            min_diff = diff / 60 % 60;
            sec_diff = diff % 60;

            switch (colons)
              {
              case 0:
                do { digits = 5; tz_colon_mask = 0; u_number_value = hour_diff * 100 + min_diff; goto do_tz_offset; } while (0);

              case 1: tz_hh_mm:
                do { digits = 6; tz_colon_mask = 04; u_number_value = hour_diff * 100 + min_diff; goto do_tz_offset; } while (0);

              case 2: tz_hh_mm_ss:
                do { digits = 9; tz_colon_mask = 024; u_number_value = hour_diff * 10000 + min_diff * 100 + sec_diff; goto do_tz_offset; } while (0)
                                                                            ;

              case 3:
                if (sec_diff != 0)
                  goto tz_hh_mm_ss;
                if (min_diff != 0)
                  goto tz_hh_mm;
                do { digits = 3; tz_colon_mask = 0; u_number_value = hour_diff; goto do_tz_offset; } while (0);

              default:
                goto bad_format;
              }
          }

        case '\0':
            --f;
            __attribute__ ((__fallthrough__));
        default:



        bad_format:
          {
            int flen;
            for (flen = 1; f[1 - flen] != '%'; flen++)
              continue;
            do { size_t _n = (flen); size_t _w = pad == '-' || width < 0 ? 0 : width; size_t _incr = _n < _w ? _w : _n; if (_incr >= maxsize - i) { 
           (*__errno_location ()) 
           = 
           34
           ; return 0; } if (p) { if (_n < _w) { size_t _delta = _w - _n; if (pad == '0' || pad == '+') (memset (p, '0', _delta), (p) += (_delta)); else (memset (p, ' ', _delta), (p) += (_delta)); } if (to_lowcase) memcpy_lowcase (p, (&f[1 - flen]), _n ); else if (to_uppcase) memcpy_uppcase (p, (&f[1 - flen]), _n ); else memcpy ((void *) p, (void const *) (&f[1 - flen]), _n); ((p) += (_n)); } i += _incr; } while (0);
          }
          break;
        }
    }


  if (p && maxsize != 0)
    *p = '\0';


  
 (*__errno_location ()) 
       = saved_errno;
  return i;
}
