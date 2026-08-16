
       


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

_Bool 
    parse_datetime (struct timespec *__restrict__,
                     char const *, struct timespec const *);






_Bool 
    parse_datetime2 (struct timespec *__restrict__,
                      char const *, struct timespec const *,
                      unsigned int flags, timezone_t, char const *);




typedef ptrdiff_t idx_t;
       
       
       










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






       
size_t nstrftime (char *__restrict__, size_t, char const *, struct tm const *,
                  timezone_t __tz, int __ns);
       
       


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

  char msg_ctxt_id[msgctxt_len + msgid_len];
    {
      int found_translation;
      memcpy (msg_ctxt_id, msgctxt, msgctxt_len - 1);
      msg_ctxt_id[msgctxt_len - 1] = '\004';
      memcpy (msg_ctxt_id + msgctxt_len, msgid, msgid_len);
      translation = dcgettext (domain, msg_ctxt_id, category);
      found_translation = (translation != msg_ctxt_id);




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

  char msg_ctxt_id[msgctxt_len + msgid_len];
    {
      int found_translation;
      memcpy (msg_ctxt_id, msgctxt, msgctxt_len - 1);
      msg_ctxt_id[msgctxt_len - 1] = '\004';
      memcpy (msg_ctxt_id + msgctxt_len, msgid, msgid_len);
      translation = dcngettext (domain, msg_ctxt_id, msgid_plural, n, category);
      found_translation = !(translation == msg_ctxt_id || translation == msgid_plural);




      if (found_translation)
        return translation;
    }
  return (n == 1 ? msgid : msgid_plural);
}
_Static_assert (((time_t) 1.5 == 1), "verify (" "TYPE_IS_INTEGER (time_t)" ")");
_Static_assert (!(! ((time_t) 0 < (time_t) -1)) || 
(-9223372036854775807L -1) 
<= ((time_t) ~ ((time_t) (! (! ((time_t) 0 < (time_t) -1)) ? (time_t) -1 : ((((time_t) 1 << ((sizeof (time_t) * 8) - 2)) - 1) * 2 + 1)))), "verify (" "!TYPE_SIGNED (time_t) || INTMAX_MIN <= TYPE_MINIMUM (time_t)" ")");
_Static_assert (((time_t) (! (! ((time_t) 0 < (time_t) -1)) ? (time_t) -1 : ((((time_t) 1 << ((sizeof (time_t) * 8) - 2)) - 1) * 2 + 1))) <= 
(9223372036854775807L)
, "verify (" "TYPE_MAXIMUM (time_t) <= INTMAX_MAX" ")");


static 
      _Bool

time_overflow (intmax_t n)
{
  return ! (((! ((time_t) 0 < (time_t) -1)) ? ((time_t) ~ ((time_t) (! (! ((time_t) 0 < (time_t) -1)) ? (time_t) -1 : ((((time_t) 1 << ((sizeof (time_t) * 8) - 2)) - 1) * 2 + 1)))) <= n : 0 <= n)
            && n <= ((time_t) (! (! ((time_t) 0 < (time_t) -1)) ? (time_t) -1 : ((((time_t) 1 << ((sizeof (time_t) * 8) - 2)) - 1) * 2 + 1))));
}




static unsigned char to_uchar (char ch) { return ch; }

static void __attribute__ ((__format__ (__printf__, 1, 2)))
dbg_printf (char const *msg, ...)
{
  va_list args;

  fputs ("date: ", 
                  stderr
                        );

  
 __builtin_va_start(
 args
 ,
 msg
 )
                     ;
  vfprintf (
           stderr
                 , msg, args);
  
 __builtin_va_end(
 args
 )
              ;
}




typedef struct
{
  
 _Bool 
      negative;
  intmax_t value;
  idx_t digits;
} textint;


typedef struct
{
  char const *name;
  int type;
  int value;
} table;


enum { MERam, MERpm, MER24 };


enum { DBGBUFSIZE = 100 };

enum { BILLION = 1000000000, LOG10_BILLION = 9 };


typedef struct
{

  intmax_t year;
  intmax_t month;
  intmax_t day;
  intmax_t hour;
  intmax_t minutes;
  intmax_t seconds;
  int ns;
} relative_time;
typedef struct
{

  const char *input;


  intmax_t day_ordinal;


  int day_number;


  int local_isdst;


  int time_zone;


  int meridian;


  textint year;
  intmax_t month;
  intmax_t day;
  intmax_t hour;
  intmax_t minutes;
  struct timespec seconds;


  relative_time rel;


  
 _Bool 
      timespec_seen;
  
 _Bool 
      rels_seen;
  idx_t dates_seen;
  idx_t days_seen;
  idx_t local_zones_seen;
  idx_t dsts_seen;
  idx_t times_seen;
  idx_t zones_seen;
  
 _Bool 
      year_seen;







  
 _Bool 
      debug_dates_seen;
  
 _Bool 
      debug_days_seen;
  
 _Bool 
      debug_local_zones_seen;
  
 _Bool 
      debug_times_seen;
  
 _Bool 
      debug_zones_seen;
  
 _Bool 
      debug_year_seen;


  
 _Bool 
      debug_ordinal_day_seen;


  table local_time_zone_table[3];
} parser_control;

static 
      _Bool

debugging (parser_control const *pc)
{



  return 
        0
             ;

}

union YYSTYPE;
static int yylex (union YYSTYPE *, parser_control *);
static int yyerror (parser_control const *, char const *);
static 
      _Bool 
           time_zone_hhmm (parser_control *, textint, intmax_t);




static void
digits_to_date_time (parser_control *pc, textint text_int)
{
  if (pc->dates_seen && ! pc->year.digits
      && ! pc->rels_seen && (pc->times_seen || 2 < text_int.digits))
    {
      pc->year_seen = 
                     1
                         ;
      pc->year = text_int;
    }
  else
    {
      if (4 < text_int.digits)
        {
          pc->dates_seen++;
          pc->day = text_int.value % 100;
          pc->month = (text_int.value / 100) % 100;
          pc->year.value = text_int.value / 10000;
          pc->year.digits = text_int.digits - 4;
        }
      else
        {
          pc->times_seen++;
          if (text_int.digits <= 2)
            {
              pc->hour = text_int.value;
              pc->minutes = 0;
            }
          else
            {
              pc->hour = text_int.value / 100;
              pc->minutes = text_int.value % 100;
            }
          pc->seconds.tv_sec = 0;
          pc->seconds.tv_nsec = 0;
          pc->meridian = MER24;
        }
    }
}



static 
      _Bool

apply_relative_time (parser_control *pc, relative_time rel, int factor)
{
  if (factor < 0
      ? (__builtin_sub_overflow (pc->rel.ns, rel.ns, &pc->rel.ns)
         | __builtin_sub_overflow (pc->rel.seconds, rel.seconds, &pc->rel.seconds)
         | __builtin_sub_overflow (pc->rel.minutes, rel.minutes, &pc->rel.minutes)
         | __builtin_sub_overflow (pc->rel.hour, rel.hour, &pc->rel.hour)
         | __builtin_sub_overflow (pc->rel.day, rel.day, &pc->rel.day)
         | __builtin_sub_overflow (pc->rel.month, rel.month, &pc->rel.month)
         | __builtin_sub_overflow (pc->rel.year, rel.year, &pc->rel.year))
      : (__builtin_add_overflow (pc->rel.ns, rel.ns, &pc->rel.ns)
         | __builtin_add_overflow (pc->rel.seconds, rel.seconds, &pc->rel.seconds)
         | __builtin_add_overflow (pc->rel.minutes, rel.minutes, &pc->rel.minutes)
         | __builtin_add_overflow (pc->rel.hour, rel.hour, &pc->rel.hour)
         | __builtin_add_overflow (pc->rel.day, rel.day, &pc->rel.day)
         | __builtin_add_overflow (pc->rel.month, rel.month, &pc->rel.month)
         | __builtin_add_overflow (pc->rel.year, rel.year, &pc->rel.year)))
    return 
          0
               ;
  pc->rels_seen = 
                 1
                     ;
  return 
        1
            ;
}


static void
set_hhmmss (parser_control *pc, intmax_t hour, intmax_t minutes,
            time_t sec, int nsec)
{
  pc->hour = hour;
  pc->minutes = minutes;
  pc->seconds.tv_sec = sec;
  pc->seconds.tv_nsec = nsec;
}



static const char *
str_days (parser_control *pc, char *buffer, int n)
{

  static char const ordinal_values[][11] = {
     "last",
     "this",
     "next/first",
     "(SECOND)",
     "third",
     "fourth",
     "fifth",
     "sixth",
     "seventh",
     "eight",
     "ninth",
     "tenth",
     "eleventh",
     "twelfth"
  };

  static char const days_values[][4] = {
     "Sun",
     "Mon",
     "Tue",
     "Wed",
     "Thu",
     "Fri",
     "Sat"
  };

  int len;



  if (pc->debug_ordinal_day_seen)
    {

      len = (-1 <= pc->day_ordinal && pc->day_ordinal <= 12
             ? snprintf (buffer, n, "%s", ordinal_values[pc->day_ordinal + 1])
             : snprintf (buffer, n, "%"
                                      "l" "d"
                                             , pc->day_ordinal));
    }
  else
    {
      buffer[0] = '\0';
      len = 0;
    }


  if (0 <= pc->day_number && pc->day_number <= 6 && 0 <= len && len < n)
    snprintf (buffer + len, n - len, &" %s"[len == 0],
              days_values[pc->day_number]);
  else
    {

    }
  return buffer;
}



enum { TIME_ZONE_BUFSIZE = (((((sizeof (intmax_t) * 8) - (! ((__typeof__ (intmax_t)) 0 < (__typeof__ (intmax_t)) -1))) * 146 + 484) / 485) + (! ((__typeof__ (intmax_t)) 0 < (__typeof__ (intmax_t)) -1))) + sizeof ":MM:SS" } ;

static char const *
time_zone_str (int time_zone, char time_zone_buf[TIME_ZONE_BUFSIZE])
{
  char *p = time_zone_buf;
  char sign = time_zone < 0 ? '-' : '+';
  int hour = abs (time_zone / (60 * 60));
  p += sprintf (time_zone_buf, "%c%02d", sign, hour);
  int offset_from_hour = abs (time_zone % (60 * 60));
  if (offset_from_hour != 0)
    {
      int mm = offset_from_hour / 60;
      int ss = offset_from_hour % 60;
      *p++ = ':';
      *p++ = '0' + mm / 10;
      *p++ = '0' + mm % 10;
      if (ss)
        {
          *p++ = ':';
          *p++ = '0' + ss / 10;
          *p++ = '0' + ss % 10;
        }
      *p = '\0';
    }
  return time_zone_buf;
}




static void
debug_print_current_time (char const *item, parser_control *pc)
{
  
 _Bool 
      space = 
              0
                   ;

  if (!debugging (pc))
    return;


  dbg_printf (gettext ("parsed %s part: "), item);

  if (pc->dates_seen && !pc->debug_dates_seen)
    {

      fprintf (
              stderr
                    , "(Y-M-D) %04"
                                   "l" "d"
                                          "-%02"
                                                "l" "d"
                                                       "-%02"
                                                             "l" "d"
                                                                    ,
              pc->year.value, pc->month, pc->day);
      pc->debug_dates_seen = 
                            1
                                ;
      space = 
             1
                 ;
    }

  if (pc->year_seen != pc->debug_year_seen)
    {
      if (space)
        fputc (' ', 
                   stderr
                         );
      fprintf (
              stderr
                    , gettext ("year: %04"
                      "l" "d"
                      ), pc->year.value);

      pc->debug_year_seen = pc->year_seen;
      space = 
             1
                 ;
    }

  if (pc->times_seen && !pc->debug_times_seen)
    {
      intmax_t sec = pc->seconds.tv_sec;
      fprintf (
              stderr
                    , &" %02"
                             "l" "d"
                                    ":%02"
                                          "l" "d"
                                                 ":%02"
                                                       "l" "d"
                                                              [!space],
               pc->hour, pc->minutes, sec);
      if (pc->seconds.tv_nsec != 0)
        {
          int nsec = pc->seconds.tv_nsec;
          fprintf (
                  stderr
                        , ".%09d", nsec);
        }
      if (pc->meridian == MERpm)
        fputs ("pm", 
                    stderr
                          );

      pc->debug_times_seen = 
                            1
                                ;
      space = 
             1
                 ;
    }

  if (pc->days_seen && !pc->debug_days_seen)
    {
      if (space)
        fputc (' ', 
                   stderr
                         );
      char tmp[DBGBUFSIZE];
      fprintf (
              stderr
                    , gettext ("%s (day ordinal=%"
                      "l" "d"
                      " number=%d)"),
               str_days (pc, tmp, sizeof tmp),
               pc->day_ordinal, pc->day_number);
      pc->debug_days_seen = 
                           1
                               ;
      space = 
             1
                 ;
    }



  if (pc->local_zones_seen && !pc->debug_local_zones_seen)
    {
      fprintf (
              stderr
                    , &" isdst=%d%s"[!space],
               pc->local_isdst, pc->dsts_seen ? " DST" : "");
      pc->debug_local_zones_seen = 
                                  1
                                      ;
      space = 
             1
                 ;
    }

  if (pc->zones_seen && !pc->debug_zones_seen)
    {
      char time_zone_buf[TIME_ZONE_BUFSIZE];
      fprintf (
              stderr
                    , &" UTC%s"[!space],
               time_zone_str (pc->time_zone, time_zone_buf));
      pc->debug_zones_seen = 
                            1
                                ;
      space = 
             1
                 ;
    }

  if (pc->timespec_seen)
    {
      intmax_t sec = pc->seconds.tv_sec;
      if (space)
        fputc (' ', 
                   stderr
                         );
      fprintf (
              stderr
                    , gettext ("number of seconds: %"
                      "l" "d"
                      ), sec);
    }

  fputc ('\n', 
              stderr
                    );
}



static 
      _Bool

print_rel_part (
               _Bool 
                    space, intmax_t val, char const *name)
{
  if (val == 0)
    return space;
  fprintf (
          stderr
                , &" %+"
                        "l" "d"
                               " %s"[!space], val, name);
  return 
        1
            ;
}

static void
debug_print_relative_time (char const *item, parser_control const *pc)
{
  
 _Bool 
      space = 
              0
                   ;

  if (!debugging (pc))
    return;


  dbg_printf (gettext ("parsed %s part: "), item);

  if (pc->rel.year == 0 && pc->rel.month == 0 && pc->rel.day == 0
      && pc->rel.hour == 0 && pc->rel.minutes == 0 && pc->rel.seconds == 0
      && pc->rel.ns == 0)
    {

      fputs (gettext ("today/this/now\n"), 
                                   stderr
                                         );
      return;
    }

  space = print_rel_part (space, pc->rel.year, "year(s)");
  space = print_rel_part (space, pc->rel.month, "month(s)");
  space = print_rel_part (space, pc->rel.day, "day(s)");
  space = print_rel_part (space, pc->rel.hour, "hour(s)");
  space = print_rel_part (space, pc->rel.minutes, "minutes");
  space = print_rel_part (space, pc->rel.seconds, "seconds");
  print_rel_part (space, pc->rel.ns, "nanoseconds");

  fputc ('\n', 
              stderr
                    );
}
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,
    YYerror = 256,
    YYUNDEF = 257,
    tAGO = 258,
    tDST = 259,
    tYEAR_UNIT = 260,
    tMONTH_UNIT = 261,
    tHOUR_UNIT = 262,
    tMINUTE_UNIT = 263,
    tSEC_UNIT = 264,
    tDAY_UNIT = 265,
    tDAY_SHIFT = 266,
    tDAY = 267,
    tDAYZONE = 268,
    tLOCAL_ZONE = 269,
    tMERIDIAN = 270,
    tMONTH = 271,
    tORDINAL = 272,
    tZONE = 273,
    tSNUMBER = 274,
    tUNUMBER = 275,
    tSDECIMAL_NUMBER = 276,
    tUDECIMAL_NUMBER = 277
  };
  typedef enum yytokentype yytoken_kind_t;




union YYSTYPE
{

  intmax_t intval;
  textint textintval;
  struct timespec timespec;
  relative_time rel;

};
typedef union YYSTYPE YYSTYPE;






int yyparse (parser_control *pc);

enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,
  YYSYMBOL_YYerror = 1,
  YYSYMBOL_YYUNDEF = 2,
  YYSYMBOL_tAGO = 3,
  YYSYMBOL_tDST = 4,
  YYSYMBOL_tYEAR_UNIT = 5,
  YYSYMBOL_tMONTH_UNIT = 6,
  YYSYMBOL_tHOUR_UNIT = 7,
  YYSYMBOL_tMINUTE_UNIT = 8,
  YYSYMBOL_tSEC_UNIT = 9,
  YYSYMBOL_tDAY_UNIT = 10,
  YYSYMBOL_tDAY_SHIFT = 11,
  YYSYMBOL_tDAY = 12,
  YYSYMBOL_tDAYZONE = 13,
  YYSYMBOL_tLOCAL_ZONE = 14,
  YYSYMBOL_tMERIDIAN = 15,
  YYSYMBOL_tMONTH = 16,
  YYSYMBOL_tORDINAL = 17,
  YYSYMBOL_tZONE = 18,
  YYSYMBOL_tSNUMBER = 19,
  YYSYMBOL_tUNUMBER = 20,
  YYSYMBOL_tSDECIMAL_NUMBER = 21,
  YYSYMBOL_tUDECIMAL_NUMBER = 22,
  YYSYMBOL_23_ = 23,
  YYSYMBOL_24_T_ = 24,
  YYSYMBOL_25_ = 25,
  YYSYMBOL_26_ = 26,
  YYSYMBOL_27_ = 27,
  YYSYMBOL_YYACCEPT = 28,
  YYSYMBOL_spec = 29,
  YYSYMBOL_timespec = 30,
  YYSYMBOL_items = 31,
  YYSYMBOL_item = 32,
  YYSYMBOL_datetime = 33,
  YYSYMBOL_iso_8601_datetime = 34,
  YYSYMBOL_time = 35,
  YYSYMBOL_iso_8601_time = 36,
  YYSYMBOL_o_zone_offset = 37,
  YYSYMBOL_zone_offset = 38,
  YYSYMBOL_local_zone = 39,
  YYSYMBOL_zone = 40,
  YYSYMBOL_day = 41,
  YYSYMBOL_date = 42,
  YYSYMBOL_iso_8601_date = 43,
  YYSYMBOL_rel = 44,
  YYSYMBOL_relunit = 45,
  YYSYMBOL_relunit_snumber = 46,
  YYSYMBOL_dayshift = 47,
  YYSYMBOL_seconds = 48,
  YYSYMBOL_signed_seconds = 49,
  YYSYMBOL_unsigned_seconds = 50,
  YYSYMBOL_number = 51,
  YYSYMBOL_hybrid = 52,
  YYSYMBOL_o_colon_minutes = 53
};
typedef enum yysymbol_kind_t yysymbol_kind_t;
typedef signed char yytype_int8;







typedef short int yytype_int16;
typedef unsigned char yytype_uint8;
typedef short unsigned int yytype_uint16;
typedef yytype_int8 yy_state_t;


typedef int yy_state_fast_t;
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};
static const yytype_int8 yytranslate[] =
{
       0, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 26, 2, 2, 27, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 25, 2,
       2, 2, 2, 2, 23, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 24, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 1, 2, 3, 4,
       5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
      15, 16, 17, 18, 19, 20, 21, 22
};
static const yytype_int8 yypact[] =
{
      38, 27, 77, -93, 46, -93, -93, -93, -93, -93,
     -93, -93, -93, -93, -93, -93, -93, -93, -93, -93,
      62, -93, 82, -3, 66, 3, 74, -4, 83, 84,
      75, -93, -93, -93, -93, -93, -93, -93, -93, -93,
      71, -93, 93, -93, -93, -93, -93, -93, -93, 78,
      72, -93, -93, -93, -93, -93, -93, -93, -93, 25,
     -93, -93, -93, -93, -93, -93, -93, -93, -93, -93,
     -93, -93, -93, -93, -93, 21, 19, 79, 80, -93,
     -93, -93, -93, -93, 81, -93, -93, 85, 86, -93,
     -93, -93, -93, -93, -6, 76, 17, -93, -93, -93,
     -93, 87, 69, -93, -93, 88, 89, -1, -93, 18,
     -93, -93, 69, 91
};




static const yytype_int8 yydefact[] =
{
       5, 0, 0, 2, 3, 85, 87, 84, 86, 4,
      82, 83, 1, 56, 59, 65, 68, 73, 62, 81,
      37, 35, 28, 0, 0, 30, 0, 88, 0, 0,
      31, 6, 7, 16, 8, 21, 9, 10, 12, 11,
      49, 13, 52, 74, 53, 14, 15, 38, 29, 0,
      45, 54, 57, 63, 66, 69, 60, 39, 36, 90,
      32, 75, 76, 78, 79, 80, 77, 55, 58, 64,
      67, 70, 61, 40, 18, 47, 90, 0, 0, 22,
      89, 71, 72, 33, 0, 51, 44, 0, 0, 34,
      43, 48, 50, 27, 25, 41, 0, 17, 46, 91,
      19, 90, 0, 23, 26, 0, 0, 25, 42, 25,
      20, 24, 0, 25
};


static const yytype_int8 yypgoto[] =
{
     -93, -93, -93, -93, -93, -93, -93, -93, 20, -68,
     -27, -93, -93, -93, -93, -93, -93, -93, 60, -93,
     -93, -93, -92, -93, -93, 43
};


static const yytype_int8 yydefgoto[] =
{
       0, 2, 3, 4, 31, 32, 33, 34, 35, 103,
     104, 36, 37, 38, 39, 40, 41, 42, 43, 44,
       9, 10, 11, 45, 46, 93
};




static const yytype_int8 yytable[] =
{
      79, 67, 68, 69, 70, 71, 72, 58, 73, 100,
     107, 74, 75, 101, 110, 76, 49, 50, 101, 102,
     113, 77, 59, 78, 61, 62, 63, 64, 65, 66,
      61, 62, 63, 64, 65, 66, 101, 101, 92, 111,
      90, 91, 106, 112, 88, 111, 5, 6, 7, 8,
      88, 13, 14, 15, 16, 17, 18, 19, 20, 21,
      22, 1, 23, 24, 25, 26, 27, 28, 29, 79,
      30, 51, 52, 53, 54, 55, 56, 12, 57, 61,
      62, 63, 64, 65, 66, 60, 48, 80, 47, 6,
      83, 8, 81, 82, 26, 84, 85, 86, 87, 94,
      95, 96, 89, 105, 97, 98, 99, 0, 108, 109,
     101, 0, 88
};

static const yytype_int8 yycheck[] =
{
      27, 5, 6, 7, 8, 9, 10, 4, 12, 15,
     102, 15, 16, 19, 15, 19, 19, 20, 19, 25,
     112, 25, 19, 27, 5, 6, 7, 8, 9, 10,
       5, 6, 7, 8, 9, 10, 19, 19, 19, 107,
      19, 20, 25, 25, 25, 113, 19, 20, 21, 22,
      25, 5, 6, 7, 8, 9, 10, 11, 12, 13,
      14, 23, 16, 17, 18, 19, 20, 21, 22, 96,
      24, 5, 6, 7, 8, 9, 10, 0, 12, 5,
       6, 7, 8, 9, 10, 25, 4, 27, 26, 20,
      30, 22, 9, 9, 19, 24, 3, 19, 26, 20,
      20, 20, 59, 27, 84, 20, 20, -1, 20, 20,
      19, -1, 25
};



static const yytype_int8 yystos[] =
{
       0, 23, 29, 30, 31, 19, 20, 21, 22, 48,
      49, 50, 0, 5, 6, 7, 8, 9, 10, 11,
      12, 13, 14, 16, 17, 18, 19, 20, 21, 22,
      24, 32, 33, 34, 35, 36, 39, 40, 41, 42,
      43, 44, 45, 46, 47, 51, 52, 26, 4, 19,
      20, 5, 6, 7, 8, 9, 10, 12, 4, 19,
      46, 5, 6, 7, 8, 9, 10, 5, 6, 7,
       8, 9, 10, 12, 15, 16, 19, 25, 27, 38,
      46, 9, 9, 46, 24, 3, 19, 26, 25, 53,
      19, 20, 19, 53, 20, 20, 20, 36, 20, 20,
      15, 19, 25, 37, 38, 27, 25, 50, 20, 20,
      15, 37, 25, 50
};


static const yytype_int8 yyr1[] =
{
       0, 28, 29, 29, 30, 31, 31, 32, 32, 32,
      32, 32, 32, 32, 32, 32, 33, 34, 35, 35,
      35, 35, 36, 36, 36, 37, 37, 38, 39, 39,
      40, 40, 40, 40, 40, 40, 40, 41, 41, 41,
      41, 42, 42, 42, 42, 42, 42, 42, 42, 42,
      43, 44, 44, 44, 45, 45, 45, 45, 45, 45,
      45, 45, 45, 45, 45, 45, 45, 45, 45, 45,
      45, 45, 45, 45, 45, 46, 46, 46, 46, 46,
      46, 47, 48, 48, 49, 49, 50, 50, 51, 52,
      53, 53
};


static const yytype_int8 yyr2[] =
{
       0, 2, 1, 1, 2, 0, 2, 1, 1, 1,
       1, 1, 1, 1, 1, 1, 1, 3, 2, 4,
       6, 1, 2, 4, 6, 0, 1, 2, 1, 2,
       1, 1, 2, 2, 3, 1, 2, 1, 2, 2,
       2, 3, 5, 3, 3, 2, 4, 2, 3, 1,
       3, 2, 1, 1, 2, 2, 1, 2, 2, 1,
       2, 2, 1, 2, 2, 1, 2, 2, 1, 2,
       2, 2, 2, 1, 1, 2, 2, 2, 2, 2,
       2, 1, 1, 1, 1, 1, 1, 1, 1, 2,
       0, 2
};


enum { YYENOMEM = -2 };
static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, parser_control *pc)
{
  ((void) (yyvaluep));
  ((void) (pc));
  if (!yymsg)
    yymsg = "Deleting";
  ;

 
#pragma GCC diagnostic push
 
#pragma GCC diagnostic ignored "-Wuninitialized"
 
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
 
  ((void) (yykind));
 
#pragma GCC diagnostic pop
 
}
int
yyparse (parser_control *pc)
{

int yychar;






YYSTYPE yylval ;


    int yynerrs = 0;

    yy_state_fast_t yystate = 0;

    int yyerrstatus = 0;





    long int yystacksize = 20;


    yy_state_t yyssa[20];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;


    YYSTYPE yyvsa[20];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;

  int yyresult;

  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;


  YYSTYPE yyval;







  int yylen = 0;

  ((void) 0);

  yychar = YYEMPTY;
  goto yysetstate;





yynewstate:


  yyssp++;





yysetstate:
  ((void) 0);
  ((void) (0 && (0 <= yystate && yystate < 114)));
 
  *yyssp = ((yy_state_t) (yystate));
 
  ;

  if (yyss + yystacksize - 1 <= yyssp)



    {

      long int yysize = yyssp - yyss + 1;
      if (20 <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (20 < yystacksize)
        yystacksize = 20;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          ((union yyalloc *) (malloc (((long unsigned int) (((yystacksize) * (((long int) (sizeof (yy_state_t))) + ((long int) (sizeof (YYSTYPE)))) + (((long int) (sizeof (union yyalloc))) - 1)))))))
                                                                                   ;
        if (! yyptr)
          goto yyexhaustedlab;
        do { long int yynewbytes; __builtin_memcpy (&yyptr->yyss_alloc, yyss, ((long unsigned int) ((yysize))) * sizeof (*(yyss))); yyss = &yyptr->yyss_alloc; yynewbytes = yystacksize * ((long int) (sizeof (*yyss))) + (((long int) (sizeof (union yyalloc))) - 1); yyptr += yynewbytes / ((long int) (sizeof (*yyptr))); } while (0);
        do { long int yynewbytes; __builtin_memcpy (&yyptr->yyvs_alloc, yyvs, ((long unsigned int) ((yysize))) * sizeof (*(yyvs))); yyvs = &yyptr->yyvs_alloc; yynewbytes = yystacksize * ((long int) (sizeof (*yyvs))) + (((long int) (sizeof (union yyalloc))) - 1); yyptr += yynewbytes / ((long int) (sizeof (*yyptr))); } while (0);

        if (yyss1 != yyssa)
          free (yyss1);
      }


      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

     
      ((void) 0)
                                               ;
     

      if (yyss + yystacksize - 1 <= yyssp)
        goto yyabortlab;
    }


  if (yystate == 12)
    goto yyacceptlab;

  goto yybackup;





yybackup:




  yyn = yypact[yystate];
  if (((yyn) == (-93)))
    goto yydefault;




  if (yychar == YYEMPTY)
    {
      ((void) 0);
      yychar = yylex (&yylval, pc);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      ((void) 0);
    }
  else if (yychar == YYerror)
    {




      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = (0 <= (yychar) && (yychar) <= 277 ? ((yysymbol_kind_t) (yytranslate[yychar])) : YYSYMBOL_YYUNDEF);
      ;
    }



  yyn += yytoken;
  if (yyn < 0 || 112 < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (0)
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }



  if (yyerrstatus)
    yyerrstatus--;


  ;
  yystate = yyn;
 
#pragma GCC diagnostic push
 
#pragma GCC diagnostic ignored "-Wuninitialized"
 
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
 
  *++yyvsp = yylval;
 
#pragma GCC diagnostic pop
 


  yychar = YYEMPTY;
  goto yynewstate;





yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;





yyreduce:

  yylen = yyr2[yyn];
  yyval = yyvsp[1-yylen];


  ;
  switch (yyn)
    {
  case 4:
      {
        pc->seconds = (yyvsp[0].timespec);
        pc->timespec_seen = 
                           1
                               ;
        debug_print_current_time (gettext ("number of seconds"), pc);
      }
    break;

  case 7:
      {
        pc->times_seen++; pc->dates_seen++;
        debug_print_current_time (gettext ("datetime"), pc);
      }
    break;

  case 8:
      {
        pc->times_seen++;
        debug_print_current_time (gettext ("time"), pc);
      }
    break;

  case 9:
      {
        pc->local_zones_seen++;
        debug_print_current_time (gettext ("local_zone"), pc);
      }
    break;

  case 10:
      {
        pc->zones_seen++;
        debug_print_current_time (gettext ("zone"), pc);
      }
    break;

  case 11:
      {
        pc->dates_seen++;
        debug_print_current_time (gettext ("date"), pc);
      }
    break;

  case 12:
      {
        pc->days_seen++;
        debug_print_current_time (gettext ("day"), pc);
      }
    break;

  case 13:
      {
        debug_print_relative_time (gettext ("relative"), pc);
      }
    break;

  case 14:
      {
        debug_print_current_time (gettext ("number"), pc);
      }
    break;

  case 15:
      {
        debug_print_relative_time (gettext ("hybrid"), pc);
      }
    break;

  case 18:
      {
        set_hhmmss (pc, (yyvsp[-1].textintval).value, 0, 0, 0);
        pc->meridian = (yyvsp[0].intval);
      }
    break;

  case 19:
      {
        set_hhmmss (pc, (yyvsp[-3].textintval).value, (yyvsp[-1].textintval).value, 0, 0);
        pc->meridian = (yyvsp[0].intval);
      }
    break;

  case 20:
      {
        set_hhmmss (pc, (yyvsp[-5].textintval).value, (yyvsp[-3].textintval).value, (yyvsp[-1].timespec).tv_sec, (yyvsp[-1].timespec).tv_nsec);
        pc->meridian = (yyvsp[0].intval);
      }
    break;

  case 22:
      {
        set_hhmmss (pc, (yyvsp[-1].textintval).value, 0, 0, 0);
        pc->meridian = MER24;
      }
    break;

  case 23:
      {
        set_hhmmss (pc, (yyvsp[-3].textintval).value, (yyvsp[-1].textintval).value, 0, 0);
        pc->meridian = MER24;
      }
    break;

  case 24:
      {
        set_hhmmss (pc, (yyvsp[-5].textintval).value, (yyvsp[-3].textintval).value, (yyvsp[-1].timespec).tv_sec, (yyvsp[-1].timespec).tv_nsec);
        pc->meridian = MER24;
      }
    break;

  case 27:
      {
        pc->zones_seen++;
        if (! time_zone_hhmm (pc, (yyvsp[-1].textintval), (yyvsp[0].intval))) goto yyabortlab;
      }
    break;

  case 28:
      { pc->local_isdst = (yyvsp[0].intval); }
    break;

  case 29:
      {
        pc->local_isdst = 1;
        pc->dsts_seen++;
      }
    break;

  case 30:
      { pc->time_zone = (yyvsp[0].intval); }
    break;

  case 31:
      { pc->time_zone = -(60 * 60 * (7)); }
    break;

  case 32:
      { pc->time_zone = (yyvsp[-1].intval);
        if (! apply_relative_time (pc, (yyvsp[0].rel), 1)) goto yyabortlab;
        debug_print_relative_time (gettext ("relative"), pc);
      }
    break;

  case 33:
      { pc->time_zone = -(60 * 60 * (7));
        if (! apply_relative_time (pc, (yyvsp[0].rel), 1)) goto yyabortlab;
        debug_print_relative_time (gettext ("relative"), pc);
      }
    break;

  case 34:
      { if (! time_zone_hhmm (pc, (yyvsp[-1].textintval), (yyvsp[0].intval))) goto yyabortlab;
        if (__builtin_add_overflow (pc->time_zone, (yyvsp[-2].intval), &pc->time_zone)) goto yyabortlab; }
    break;

  case 35:
      { pc->time_zone = (yyvsp[0].intval) + 60 * 60; }
    break;

  case 36:
      { pc->time_zone = (yyvsp[-1].intval) + 60 * 60; }
    break;

  case 37:
      {
        pc->day_ordinal = 0;
        pc->day_number = (yyvsp[0].intval);
      }
    break;

  case 38:
      {
        pc->day_ordinal = 0;
        pc->day_number = (yyvsp[-1].intval);
      }
    break;

  case 39:
      {
        pc->day_ordinal = (yyvsp[-1].intval);
        pc->day_number = (yyvsp[0].intval);
        pc->debug_ordinal_day_seen = 
                                    1
                                        ;
      }
    break;

  case 40:
      {
        pc->day_ordinal = (yyvsp[-1].textintval).value;
        pc->day_number = (yyvsp[0].intval);
        pc->debug_ordinal_day_seen = 
                                    1
                                        ;
      }
    break;

  case 41:
      {
        pc->month = (yyvsp[-2].textintval).value;
        pc->day = (yyvsp[0].textintval).value;
      }
    break;

  case 42:
      {





        if (4 <= (yyvsp[-4].textintval).digits)
          {
            if (debugging (pc))
              {
                intmax_t digits = (yyvsp[-4].textintval).digits;
                dbg_printf (gettext ("warning: value %"
                           "l" "d"
                           " has %"
                           "l" "d"
                           " digits. " "Assuming YYYY/MM/DD\n")
                                                      ,
                            (yyvsp[-4].textintval).value, digits);
              }

            pc->year = (yyvsp[-4].textintval);
            pc->month = (yyvsp[-2].textintval).value;
            pc->day = (yyvsp[0].textintval).value;
          }
        else
          {
            if (debugging (pc))
              dbg_printf (gettext ("warning: value %"
                         "l" "d"
                         " has less than 4 digits. " "Assuming MM/DD/YY[YY]\n")
                                                      ,
                          (yyvsp[-4].textintval).value);

            pc->month = (yyvsp[-4].textintval).value;
            pc->day = (yyvsp[-2].textintval).value;
            pc->year = (yyvsp[0].textintval);
          }
      }
    break;

  case 43:
      {

        pc->day = (yyvsp[-2].textintval).value;
        pc->month = (yyvsp[-1].intval);
        if (__builtin_sub_overflow (0, (yyvsp[0].textintval).value, &pc->year.value)) goto yyabortlab;
        pc->year.digits = (yyvsp[0].textintval).digits;
      }
    break;

  case 44:
      {

        pc->month = (yyvsp[-2].intval);
        if (__builtin_sub_overflow (0, (yyvsp[-1].textintval).value, &pc->day)) goto yyabortlab;
        if (__builtin_sub_overflow (0, (yyvsp[0].textintval).value, &pc->year.value)) goto yyabortlab;
        pc->year.digits = (yyvsp[0].textintval).digits;
      }
    break;

  case 45:
      {
        pc->month = (yyvsp[-1].intval);
        pc->day = (yyvsp[0].textintval).value;
      }
    break;

  case 46:
      {
        pc->month = (yyvsp[-3].intval);
        pc->day = (yyvsp[-2].textintval).value;
        pc->year = (yyvsp[0].textintval);
      }
    break;

  case 47:
      {
        pc->day = (yyvsp[-1].textintval).value;
        pc->month = (yyvsp[0].intval);
      }
    break;

  case 48:
      {
        pc->day = (yyvsp[-2].textintval).value;
        pc->month = (yyvsp[-1].intval);
        pc->year = (yyvsp[0].textintval);
      }
    break;

  case 50:
      {

        pc->year = (yyvsp[-2].textintval);
        if (__builtin_sub_overflow (0, (yyvsp[-1].textintval).value, &pc->month)) goto yyabortlab;
        if (__builtin_sub_overflow (0, (yyvsp[0].textintval).value, &pc->day)) goto yyabortlab;
      }
    break;

  case 51:
      { if (! apply_relative_time (pc, (yyvsp[-1].rel), (yyvsp[0].intval))) goto yyabortlab; }
    break;

  case 52:
      { if (! apply_relative_time (pc, (yyvsp[0].rel), 1)) goto yyabortlab; }
    break;

  case 53:
      { if (! apply_relative_time (pc, (yyvsp[0].rel), 1)) goto yyabortlab; }
    break;

  case 54:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).year = (yyvsp[-1].intval); }
    break;

  case 55:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).year = (yyvsp[-1].textintval).value; }
    break;

  case 56:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).year = 1; }
    break;

  case 57:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).month = (yyvsp[-1].intval); }
    break;

  case 58:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).month = (yyvsp[-1].textintval).value; }
    break;

  case 59:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).month = 1; }
    break;

  case 60:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 });
        if (__builtin_mul_overflow ((yyvsp[-1].intval), (yyvsp[0].intval), &(yyval.rel).day)) goto yyabortlab; }
    break;

  case 61:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 });
        if (__builtin_mul_overflow ((yyvsp[-1].textintval).value, (yyvsp[0].intval), &(yyval.rel).day)) goto yyabortlab; }
    break;

  case 62:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).day = (yyvsp[0].intval); }
    break;

  case 63:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).hour = (yyvsp[-1].intval); }
    break;

  case 64:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).hour = (yyvsp[-1].textintval).value; }
    break;

  case 65:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).hour = 1; }
    break;

  case 66:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).minutes = (yyvsp[-1].intval); }
    break;

  case 67:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).minutes = (yyvsp[-1].textintval).value; }
    break;

  case 68:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).minutes = 1; }
    break;

  case 69:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).seconds = (yyvsp[-1].intval); }
    break;

  case 70:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).seconds = (yyvsp[-1].textintval).value; }
    break;

  case 71:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).seconds = (yyvsp[-1].timespec).tv_sec; (yyval.rel).ns = (yyvsp[-1].timespec).tv_nsec; }
    break;

  case 72:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).seconds = (yyvsp[-1].timespec).tv_sec; (yyval.rel).ns = (yyvsp[-1].timespec).tv_nsec; }
    break;

  case 73:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).seconds = 1; }
    break;

  case 75:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).year = (yyvsp[-1].textintval).value; }
    break;

  case 76:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).month = (yyvsp[-1].textintval).value; }
    break;

  case 77:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 });
        if (__builtin_mul_overflow ((yyvsp[-1].textintval).value, (yyvsp[0].intval), &(yyval.rel).day)) goto yyabortlab; }
    break;

  case 78:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).hour = (yyvsp[-1].textintval).value; }
    break;

  case 79:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).minutes = (yyvsp[-1].textintval).value; }
    break;

  case 80:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).seconds = (yyvsp[-1].textintval).value; }
    break;

  case 81:
      { (yyval.rel) = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 }); (yyval.rel).day = (yyvsp[0].intval); }
    break;

  case 85:
      { if (time_overflow ((yyvsp[0].textintval).value)) goto yyabortlab;
        (yyval.timespec).tv_sec = (yyvsp[0].textintval).value; (yyval.timespec).tv_nsec = 0; }
    break;

  case 87:
      { if (time_overflow ((yyvsp[0].textintval).value)) goto yyabortlab;
        (yyval.timespec).tv_sec = (yyvsp[0].textintval).value; (yyval.timespec).tv_nsec = 0; }
    break;

  case 88:
      { digits_to_date_time (pc, (yyvsp[0].textintval)); }
    break;

  case 89:
      {


        digits_to_date_time (pc, (yyvsp[-1].textintval));
        if (! apply_relative_time (pc, (yyvsp[0].rel), 1)) goto yyabortlab;
      }
    break;

  case 90:
      { (yyval.intval) = -1; }
    break;

  case 91:
      { (yyval.intval) = (yyvsp[0].textintval).value; }
    break;

      default: break;
    }
  ;

  (yyvsp -= (yylen), yyssp -= (yylen));
  yylen = 0;

  *++yyvsp = yyval;




  {
    const int yylhs = yyr1[yyn] - 28;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= 112 && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;





yyerrlab:


  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : (0 <= (yychar) && (yychar) <= 277 ? ((yysymbol_kind_t) (yytranslate[yychar])) : YYSYMBOL_YYUNDEF);

  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (pc, "syntax error");
    }

  if (yyerrstatus == 3)
    {



      if (yychar <= YYEOF)
        {

          if (yychar == YYEOF)
            goto yyabortlab;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, pc);
          yychar = YYEMPTY;
        }
    }



  goto yyerrlab1;





yyerrorlab:


  if (0)
    goto yyerrorlab;



  (yyvsp -= (yylen), yyssp -= (yylen));
  yylen = 0;
  ;
  yystate = *yyssp;
  goto yyerrlab1;





yyerrlab1:
  yyerrstatus = 3;


  for (;;)
    {
      yyn = yypact[yystate];
      if (!((yyn) == (-93)))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= 112 && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }


      if (yyssp == yyss)
        goto yyabortlab;


      yydestruct ("Error: popping",
                  ((yysymbol_kind_t) (yystos[yystate])), yyvsp, pc);
      (yyvsp -= (1), yyssp -= (1));
      yystate = *yyssp;
      ;
    }

 
#pragma GCC diagnostic push
 
#pragma GCC diagnostic ignored "-Wuninitialized"
 
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
 
  *++yyvsp = yylval;
 
#pragma GCC diagnostic pop
 



  ;

  yystate = yyn;
  goto yynewstate;





yyacceptlab:
  yyresult = 0;
  goto yyreturn;





yyabortlab:
  yyresult = 1;
  goto yyreturn;






yyexhaustedlab:
  yyerror (pc, "memory exhausted");
  yyresult = 2;
  goto yyreturn;






yyreturn:
  if (yychar != YYEMPTY)
    {


      yytoken = (0 <= (yychar) && (yychar) <= 277 ? ((yysymbol_kind_t) (yytranslate[yychar])) : YYSYMBOL_YYUNDEF);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, pc);
    }


  (yyvsp -= (yylen), yyssp -= (yylen));
  ;
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  ((yysymbol_kind_t) (yystos[+*yyssp])), yyvsp, pc);
      (yyvsp -= (1), yyssp -= (1));
    }

  if (yyss != yyssa)
    free (yyss);


  return yyresult;
}


static table const meridian_table[] =
{
  { "AM", tMERIDIAN, MERam },
  { "A.M.", tMERIDIAN, MERam },
  { "PM", tMERIDIAN, MERpm },
  { "P.M.", tMERIDIAN, MERpm },
  { 
   ((void *)0)
       , 0, 0 }
};

static table const dst_table[] =
{
  { "DST", tDST, 0 }
};

static table const month_and_day_table[] =
{
  { "JANUARY", tMONTH, 1 },
  { "FEBRUARY", tMONTH, 2 },
  { "MARCH", tMONTH, 3 },
  { "APRIL", tMONTH, 4 },
  { "MAY", tMONTH, 5 },
  { "JUNE", tMONTH, 6 },
  { "JULY", tMONTH, 7 },
  { "AUGUST", tMONTH, 8 },
  { "SEPTEMBER",tMONTH, 9 },
  { "SEPT", tMONTH, 9 },
  { "OCTOBER", tMONTH, 10 },
  { "NOVEMBER", tMONTH, 11 },
  { "DECEMBER", tMONTH, 12 },
  { "SUNDAY", tDAY, 0 },
  { "MONDAY", tDAY, 1 },
  { "TUESDAY", tDAY, 2 },
  { "TUES", tDAY, 2 },
  { "WEDNESDAY",tDAY, 3 },
  { "WEDNES", tDAY, 3 },
  { "THURSDAY", tDAY, 4 },
  { "THUR", tDAY, 4 },
  { "THURS", tDAY, 4 },
  { "FRIDAY", tDAY, 5 },
  { "SATURDAY", tDAY, 6 },
  { 
   ((void *)0)
       , 0, 0 }
};

static table const time_units_table[] =
{
  { "YEAR", tYEAR_UNIT, 1 },
  { "MONTH", tMONTH_UNIT, 1 },
  { "FORTNIGHT",tDAY_UNIT, 14 },
  { "WEEK", tDAY_UNIT, 7 },
  { "DAY", tDAY_UNIT, 1 },
  { "HOUR", tHOUR_UNIT, 1 },
  { "MINUTE", tMINUTE_UNIT, 1 },
  { "MIN", tMINUTE_UNIT, 1 },
  { "SECOND", tSEC_UNIT, 1 },
  { "SEC", tSEC_UNIT, 1 },
  { 
   ((void *)0)
       , 0, 0 }
};


static table const relative_time_table[] =
{
  { "TOMORROW", tDAY_SHIFT, 1 },
  { "YESTERDAY",tDAY_SHIFT, -1 },
  { "TODAY", tDAY_SHIFT, 0 },
  { "NOW", tDAY_SHIFT, 0 },
  { "LAST", tORDINAL, -1 },
  { "THIS", tORDINAL, 0 },
  { "NEXT", tORDINAL, 1 },
  { "FIRST", tORDINAL, 1 },

  { "THIRD", tORDINAL, 3 },
  { "FOURTH", tORDINAL, 4 },
  { "FIFTH", tORDINAL, 5 },
  { "SIXTH", tORDINAL, 6 },
  { "SEVENTH", tORDINAL, 7 },
  { "EIGHTH", tORDINAL, 8 },
  { "NINTH", tORDINAL, 9 },
  { "TENTH", tORDINAL, 10 },
  { "ELEVENTH", tORDINAL, 11 },
  { "TWELFTH", tORDINAL, 12 },
  { "AGO", tAGO, -1 },
  { "HENCE", tAGO, 1 },
  { 
   ((void *)0)
       , 0, 0 }
};




static table const universal_time_zone_table[] =
{
  { "GMT", tZONE, (60 * 60 * (0)) },
  { "UT", tZONE, (60 * 60 * (0)) },
  { "UTC", tZONE, (60 * 60 * (0)) },
  { 
   ((void *)0)
       , 0, 0 }
};






static table const time_zone_table[] =
{
  { "WET", tZONE, (60 * 60 * (0)) },
  { "WEST", tDAYZONE, (60 * 60 * (0)) },
  { "BST", tDAYZONE, (60 * 60 * (0)) },
  { "ART", tZONE, -(60 * 60 * (3)) },
  { "BRT", tZONE, -(60 * 60 * (3)) },
  { "BRST", tDAYZONE, -(60 * 60 * (3)) },
  { "NST", tZONE, -((60 * 60 * (3)) + 30 * 60) },
  { "NDT", tDAYZONE,-((60 * 60 * (3)) + 30 * 60) },
  { "AST", tZONE, -(60 * 60 * (4)) },
  { "ADT", tDAYZONE, -(60 * 60 * (4)) },
  { "CLT", tZONE, -(60 * 60 * (4)) },
  { "CLST", tDAYZONE, -(60 * 60 * (4)) },
  { "EST", tZONE, -(60 * 60 * (5)) },
  { "EDT", tDAYZONE, -(60 * 60 * (5)) },
  { "CST", tZONE, -(60 * 60 * (6)) },
  { "CDT", tDAYZONE, -(60 * 60 * (6)) },
  { "MST", tZONE, -(60 * 60 * (7)) },
  { "MDT", tDAYZONE, -(60 * 60 * (7)) },
  { "PST", tZONE, -(60 * 60 * (8)) },
  { "PDT", tDAYZONE, -(60 * 60 * (8)) },
  { "AKST", tZONE, -(60 * 60 * (9)) },
  { "AKDT", tDAYZONE, -(60 * 60 * (9)) },
  { "HST", tZONE, -(60 * 60 * (10)) },
  { "HAST", tZONE, -(60 * 60 * (10)) },
  { "HADT", tDAYZONE, -(60 * 60 * (10)) },
  { "SST", tZONE, -(60 * 60 * (12)) },
  { "WAT", tZONE, (60 * 60 * (1)) },
  { "CET", tZONE, (60 * 60 * (1)) },
  { "CEST", tDAYZONE, (60 * 60 * (1)) },
  { "MET", tZONE, (60 * 60 * (1)) },
  { "MEZ", tZONE, (60 * 60 * (1)) },
  { "MEST", tDAYZONE, (60 * 60 * (1)) },
  { "MESZ", tDAYZONE, (60 * 60 * (1)) },
  { "EET", tZONE, (60 * 60 * (2)) },
  { "EEST", tDAYZONE, (60 * 60 * (2)) },
  { "CAT", tZONE, (60 * 60 * (2)) },
  { "SAST", tZONE, (60 * 60 * (2)) },
  { "EAT", tZONE, (60 * 60 * (3)) },
  { "MSK", tZONE, (60 * 60 * (3)) },
  { "MSD", tDAYZONE, (60 * 60 * (3)) },
  { "IST", tZONE, ((60 * 60 * (5)) + 30 * 60) },
  { "SGT", tZONE, (60 * 60 * (8)) },
  { "KST", tZONE, (60 * 60 * (9)) },
  { "JST", tZONE, (60 * 60 * (9)) },
  { "GST", tZONE, (60 * 60 * (10)) },
  { "NZST", tZONE, (60 * 60 * (12)) },
  { "NZDT", tDAYZONE, (60 * 60 * (12)) },
  { 
   ((void *)0)
       , 0, 0 }
};
static table const military_table[] =
{
  { "A", tZONE, (60 * 60 * (1)) },
  { "B", tZONE, (60 * 60 * (2)) },
  { "C", tZONE, (60 * 60 * (3)) },
  { "D", tZONE, (60 * 60 * (4)) },
  { "E", tZONE, (60 * 60 * (5)) },
  { "F", tZONE, (60 * 60 * (6)) },
  { "G", tZONE, (60 * 60 * (7)) },
  { "H", tZONE, (60 * 60 * (8)) },
  { "I", tZONE, (60 * 60 * (9)) },
  { "K", tZONE, (60 * 60 * (10)) },
  { "L", tZONE, (60 * 60 * (11)) },
  { "M", tZONE, (60 * 60 * (12)) },
  { "N", tZONE, -(60 * 60 * (1)) },
  { "O", tZONE, -(60 * 60 * (2)) },
  { "P", tZONE, -(60 * 60 * (3)) },
  { "Q", tZONE, -(60 * 60 * (4)) },
  { "R", tZONE, -(60 * 60 * (5)) },
  { "S", tZONE, -(60 * 60 * (6)) },
  { "T", 'T', 0 },
  { "U", tZONE, -(60 * 60 * (8)) },
  { "V", tZONE, -(60 * 60 * (9)) },
  { "W", tZONE, -(60 * 60 * (10)) },
  { "X", tZONE, -(60 * 60 * (11)) },
  { "Y", tZONE, -(60 * 60 * (12)) },
  { "Z", tZONE, (60 * 60 * (0)) },
  { 
   ((void *)0)
       , 0, 0 }
};
static 
      _Bool

time_zone_hhmm (parser_control *pc, textint s, intmax_t mm)
{
  intmax_t n_minutes;
  
 _Bool 
      overflow = 
                 0
                      ;



  if (s.digits <= 2 && mm < 0)
    s.value *= 100;

  if (mm < 0)
    n_minutes = (s.value / 100) * 60 + s.value % 100;
  else
    {
      overflow |= __builtin_mul_overflow (s.value, 60, &n_minutes);
      overflow |= (s.negative
                   ? __builtin_sub_overflow (n_minutes, mm, &n_minutes)
                   : __builtin_add_overflow (n_minutes, mm, &n_minutes));
    }

  if (overflow || ! (-24 * 60 <= n_minutes && n_minutes <= 24 * 60))
    return 
          0
               ;
  pc->time_zone = n_minutes * 60;
  return 
        1
            ;
}

static int
to_hour (intmax_t hours, int meridian)
{
  switch (meridian)
    {
    default:
    case MER24:
      return 0 <= hours && hours < 24 ? hours : -1;
    case MERam:
      return 0 < hours && hours < 12 ? hours : hours == 12 ? 0 : -1;
    case MERpm:
      return 0 < hours && hours < 12 ? hours + 12 : hours == 12 ? 12 : -1;
    }
}

enum { TM_YEAR_BASE = 1900 };
enum { TM_YEAR_BUFSIZE = ((((((sizeof (int) * 8) - (! ((__typeof__ (int)) 0 < (__typeof__ (int)) -1))) * 146 + 484) / 485) + (! ((__typeof__ (int)) 0 < (__typeof__ (int)) -1))) + 1) + 1 };




static char const *
tm_year_str (int tm_year, char buf[TM_YEAR_BUFSIZE])
{
  _Static_assert (TM_YEAR_BASE % 100 == 0, "verify (" "TM_YEAR_BASE % 100 == 0" ")");
  sprintf (buf, &"-%02d%02d"[-TM_YEAR_BASE <= tm_year],
           abs (tm_year / 100 + TM_YEAR_BASE / 100),
           abs (tm_year % 100));
  return buf;
}




static 
      _Bool

to_tm_year (textint textyear, 
                             _Bool 
                                  debug, int *tm_year)
{
  intmax_t year = textyear.value;



  if (0 <= year && textyear.digits == 2)
    {
      year += year < 69 ? 2000 : 1900;
      if (debug)
        dbg_printf (gettext ("warning: adjusting year value %"
                   "l" "d" 
                   " to %"
                   "l" "d"
                   "\n")
                                         ,
                    textyear.value, year);
    }

  if (year < 0
      ? __builtin_sub_overflow (-TM_YEAR_BASE, year, tm_year)
      : __builtin_sub_overflow (year, TM_YEAR_BASE, tm_year))
    {
      if (debug)
        dbg_printf (gettext ("error: out-of-range year %"
                   "l" "d"
                   "\n"), year);
      return 
            0
                 ;
    }

  return 
        1
            ;
}

static table const * __attribute__ ((__pure__))
lookup_zone (parser_control const *pc, char const *name)
{
  table const *tp;

  for (tp = universal_time_zone_table; tp->name; tp++)
    if (strcmp (name, tp->name) == 0)
      return tp;



  for (tp = pc->local_time_zone_table; tp->name; tp++)
    if (strcmp (name, tp->name) == 0)
      return tp;

  for (tp = time_zone_table; tp->name; tp++)
    if (strcmp (name, tp->name) == 0)
      return tp;

  return 
        ((void *)0)
            ;
}
static table const *
lookup_word (parser_control const *pc, char *word)
{
  char *p;
  char *q;
  idx_t wordlen;
  table const *tp;
  
 _Bool 
      period_found;
  
 _Bool 
      abbrev;


  for (p = word; *p; p++)
    *p = c_toupper (to_uchar (*p));

  for (tp = meridian_table; tp->name; tp++)
    if (strcmp (word, tp->name) == 0)
      return tp;


  wordlen = strlen (word);
  abbrev = wordlen == 3 || (wordlen == 4 && word[3] == '.');

  for (tp = month_and_day_table; tp->name; tp++)
    if ((abbrev ? strncmp (word, tp->name, 3) : strcmp (word, tp->name)) == 0)
      return tp;

  if ((tp = lookup_zone (pc, word)))
    return tp;

  if (strcmp (word, dst_table[0].name) == 0)
    return dst_table;

  for (tp = time_units_table; tp->name; tp++)
    if (strcmp (word, tp->name) == 0)
      return tp;


  if (word[wordlen - 1] == 'S')
    {
      word[wordlen - 1] = '\0';
      for (tp = time_units_table; tp->name; tp++)
        if (strcmp (word, tp->name) == 0)
          return tp;
      word[wordlen - 1] = 'S';
    }

  for (tp = relative_time_table; tp->name; tp++)
    if (strcmp (word, tp->name) == 0)
      return tp;


  if (wordlen == 1)
    for (tp = military_table; tp->name; tp++)
      if (word[0] == tp->name[0])
        return tp;


  for (period_found = 
                     0
                          , p = q = word; (*p = *q); q++)
    if (*q == '.')
      period_found = 
                    1
                        ;
    else
      p++;
  if (period_found && (tp = lookup_zone (pc, word)))
    return tp;

  return 
        ((void *)0)
            ;
}

static int
yylex (union YYSTYPE *lvalp, parser_control *pc)
{
  unsigned char c;

  for (;;)
    {
      while (c = *pc->input, c_isspace (c))
        pc->input++;

      if (c_isdigit (c) || c == '-' || c == '+')
        {
          char const *p = pc->input;
          int sign;
          if (c == '-' || c == '+')
            {
              sign = c == '-' ? -1 : 1;
              while (c = *(pc->input = ++p), c_isspace (c))
                continue;
              if (! c_isdigit (c))

                continue;
            }
          else
            sign = 0;

          time_t value = 0;
          do
            {
              if (__builtin_mul_overflow (value, 10, &value))
                return '?';
              if (__builtin_add_overflow (value, sign < 0 ? '0' - c : c - '0', &value))
                return '?';
              c = *++p;
            }
          while (c_isdigit (c));

          if ((c == '.' || c == ',') && c_isdigit (p[1]))
            {
              time_t s = value;
              int digits;


              p++;
              int ns = *p++ - '0';
              for (digits = 2; digits <= LOG10_BILLION; digits++)
                {
                  ns *= 10;
                  if (c_isdigit (*p))
                    ns += *p++ - '0';
                }


              if (sign < 0)
                for (; c_isdigit (*p); p++)
                  if (*p != '0')
                    {
                      ns++;
                      break;
                    }
              while (c_isdigit (*p))
                p++;




              if (sign < 0 && ns)
                {
                  if (__builtin_sub_overflow (s, 1, &s))
                    return '?';
                  ns = BILLION - ns;
                }

              lvalp->timespec.tv_sec = s;
              lvalp->timespec.tv_nsec = ns;
              pc->input = p;
              return sign ? tSDECIMAL_NUMBER : tUDECIMAL_NUMBER;
            }
          else
            {
              lvalp->textintval.negative = sign < 0;
              lvalp->textintval.value = value;
              lvalp->textintval.digits = p - pc->input;
              pc->input = p;
              return sign ? tSNUMBER : tUNUMBER;
            }
        }

      if (c_isalpha (c))
        {
          char buff[20];
          char *p = buff;
          table const *tp;

          do
            {
              if (p < buff + sizeof buff - 1)
                *p++ = c;
              c = *++pc->input;
            }
          while (c_isalpha (c) || c == '.');

          *p = '\0';
          tp = lookup_word (pc, buff);
          if (! tp)
            {
              if (debugging (pc))
                dbg_printf (gettext ("error: unknown word '%s'\n"), buff);
              return '?';
            }
          lvalp->intval = tp->value;
          return tp->type;
        }

      if (c != '(')
        return to_uchar (*pc->input++);

      idx_t count = 0;
      do
        {
          c = *pc->input++;
          if (c == '\0')
            return c;
          if (c == '(')
            count++;
          else if (c == ')')
            count--;
        }
      while (count != 0);
    }
}


static int
yyerror (parser_control const *pc __attribute__ ((__unused__)),
         char const *s __attribute__ ((__unused__)))
{
  return 0;
}







static 
      _Bool

mktime_ok (struct tm const *tm0, struct tm const *tm1)
{
  if (tm1->tm_wday < 0)
    return 
          0
               ;

  return ! ((tm0->tm_sec ^ tm1->tm_sec)
            | (tm0->tm_min ^ tm1->tm_min)
            | (tm0->tm_hour ^ tm1->tm_hour)
            | (tm0->tm_mday ^ tm1->tm_mday)
            | (tm0->tm_mon ^ tm1->tm_mon)
            | (tm0->tm_year ^ tm1->tm_year));
}



static char const *
debug_strfdatetime (struct tm const *tm, parser_control const *pc,
                    char *buf, int n)
{
  int m = nstrftime (buf, n, "(Y-M-D) %Y-%m-%d %H:%M:%S", tm, 0, 0);



  if (pc && m < n && pc->zones_seen)
    {
      int tz = pc->time_zone;


      if (pc->local_zones_seen && !pc->zones_seen && 0 < pc->local_isdst)
        tz += 60 * 60;

      char time_zone_buf[TIME_ZONE_BUFSIZE];
      snprintf (&buf[m], n - m, " TZ=%s", time_zone_str (tz, time_zone_buf));
    }
  return buf;
}

static char const *
debug_strfdate (struct tm const *tm, char *buf, int n)
{
  char tm_year_buf[TM_YEAR_BUFSIZE];
  snprintf (buf, n, "(Y-M-D) %s-%02d-%02d",
            tm_year_str (tm->tm_year, tm_year_buf),
            tm->tm_mon + 1, tm->tm_mday);
  return buf;
}

static char const *
debug_strftime (struct tm const *tm, char *buf, int n)
{
  snprintf (buf, n, "%02d:%02d:%02d", tm->tm_hour, tm->tm_min, tm->tm_sec);
  return buf;
}
static void
debug_mktime_not_ok (struct tm const *tm0, struct tm const *tm1,
                     parser_control const *pc, 
                                              _Bool 
                                                   time_zone_seen)
{

  char tmp[DBGBUFSIZE];
  int i;
  const 
       _Bool 
            eq_sec = (tm0->tm_sec == tm1->tm_sec);
  const 
       _Bool 
            eq_min = (tm0->tm_min == tm1->tm_min);
  const 
       _Bool 
            eq_hour = (tm0->tm_hour == tm1->tm_hour);
  const 
       _Bool 
            eq_mday = (tm0->tm_mday == tm1->tm_mday);
  const 
       _Bool 
            eq_month = (tm0->tm_mon == tm1->tm_mon);
  const 
       _Bool 
            eq_year = (tm0->tm_year == tm1->tm_year);

  const 
       _Bool 
            dst_shift = eq_sec && eq_min && !eq_hour
                         && eq_mday && eq_month && eq_year;

  if (!debugging (pc))
    return;

  dbg_printf (gettext ("error: invalid date/time value:\n"));
  dbg_printf (gettext ("    user provided time: '%s'\n"),
              debug_strfdatetime (tm0, pc, tmp, sizeof tmp));
  dbg_printf (gettext ("       normalized time: '%s'\n"),
              debug_strfdatetime (tm1, pc, tmp, sizeof tmp));


  i = snprintf (tmp, sizeof tmp,
                "                                 %4s %2s %2s %2s %2s %2s",
                eq_year ? "" : "----",
                eq_month ? "" : "--",
                eq_mday ? "" : "--",
                eq_hour ? "" : "--",
                eq_min ? "" : "--",
                eq_sec ? "" : "--");

  if (0 <= i)
    {
      if (sizeof tmp - 1 < i)
        i = sizeof tmp - 1;
      while (0 < i && tmp[i - 1] == ' ')
        --i;
      tmp[i] = '\0';
    }
  dbg_printf ("%s\n", tmp);

  dbg_printf (gettext ("     possible reasons:\n"));
  if (dst_shift)
    dbg_printf (gettext ("       non-existing due to daylight-saving time;\n"));
  if (!eq_mday && !eq_month)
    dbg_printf (gettext ("       invalid day/month combination;\n"));
  dbg_printf (gettext ("       numeric values overflow;\n"));
  dbg_printf ("       %s\n", (time_zone_seen ? gettext ("incorrect timezone")
                              : gettext ("missing timezone")));
}






static 
      _Bool

parse_datetime_body (struct timespec *result, char const *p,
                     struct timespec const *now, unsigned int flags,
                     timezone_t tzdefault, char const *tzstring)
{
  struct tm tm;
  struct tm tm0;
  char time_zone_buf[TIME_ZONE_BUFSIZE];
  char dbg_tm[DBGBUFSIZE];
  
 _Bool 
      ok = 
           0
                ;
  char const *input_sentinel = p + strlen (p);
  char *tz1alloc = 
                  ((void *)0)
                      ;



  enum { TZBUFSIZE = 100 };
  char tz1buf[TZBUFSIZE];

  struct timespec gettime_buffer;
  if (! now)
    {
      gettime (&gettime_buffer);
      now = &gettime_buffer;
    }

  time_t Start = now->tv_sec;
  int Start_ns = now->tv_nsec;

  unsigned char c;
  while (c = *p, c_isspace (c))
    p++;

  timezone_t tz = tzdefault;




  const relative_time rel_time_0 = ((relative_time) { 0, 0, 0, 0, 0, 0, 0 });

  if (strncmp (p, "TZ=\"", 4) == 0)
    {
      char const *tzbase = p + 4;
      idx_t tzsize = 1;
      char const *s;

      for (s = tzbase; *s; s++, tzsize++)
        if (*s == '\\')
          {
            s++;
            if (! (*s == '\\' || *s == '"'))
              break;
          }
        else if (*s == '"')
          {
            timezone_t tz1;
            char *tz1string = tz1buf;
            char *z;
            if (TZBUFSIZE < tzsize)
              {
                tz1alloc = malloc (tzsize);
                if (!tz1alloc)
                  goto fail;
                tz1string = tz1alloc;
              }
            z = tz1string;
            for (s = tzbase; *s != '"'; s++)
              *z++ = *(s += *s == '\\');
            *z = '\0';
            tz1 = tzalloc (tz1string);
            if (!tz1)
              goto fail;
            tz = tz1;
            tzstring = tz1string;

            p = s + 1;
            while (c = *p, c_isspace (c))
              p++;

            break;
          }
    }

  struct tm tmp;
  if (! localtime_rz (tz, &now->tv_sec, &tmp))
    goto fail;




  if (*p == '\0')
    p = "0";

  parser_control pc;
  pc.input = p;



  if (__builtin_add_overflow (tmp.tm_year, TM_YEAR_BASE, &pc.year.value))
    {
      if (debugging (&pc))
        dbg_printf (gettext ("error: initial year out of range\n"));
      goto fail;
    }
  pc.year.digits = 0;
  pc.month = tmp.tm_mon + 1;
  pc.day = tmp.tm_mday;
  pc.hour = tmp.tm_hour;
  pc.minutes = tmp.tm_min;
  pc.seconds.tv_sec = tmp.tm_sec;
  pc.seconds.tv_nsec = Start_ns;
  tm.tm_isdst = tmp.tm_isdst;

  pc.meridian = MER24;
  pc.rel = rel_time_0;
  pc.timespec_seen = 
                    0
                         ;
  pc.rels_seen = 
                0
                     ;
  pc.dates_seen = 0;
  pc.days_seen = 0;
  pc.times_seen = 0;
  pc.local_zones_seen = 0;
  pc.dsts_seen = 0;
  pc.zones_seen = 0;
  pc.year_seen = 
                0
                     ;
  pc.debug_dates_seen = 
                       0
                            ;
  pc.debug_days_seen = 
                      0
                           ;
  pc.debug_times_seen = 
                       0
                            ;
  pc.debug_local_zones_seen = 
                             0
                                  ;
  pc.debug_zones_seen = 
                       0
                            ;
  pc.debug_year_seen = 
                      0
                           ;
  pc.debug_ordinal_day_seen = 
                             0
                                  ;


  pc.local_time_zone_table[0].name = tmp.tm_zone;
  pc.local_time_zone_table[0].type = tLOCAL_ZONE;
  pc.local_time_zone_table[0].value = tmp.tm_isdst;
  pc.local_time_zone_table[1].name = 
                                    ((void *)0)
                                        ;



  {
    int quarter;
    for (quarter = 1; quarter <= 3; quarter++)
      {
        time_t probe;
        if (__builtin_add_overflow (Start, quarter * (90 * 24 * 60 * 60), &probe))
          break;
        struct tm probe_tm;
        if (localtime_rz (tz, &probe, &probe_tm) && probe_tm.tm_zone
            && probe_tm.tm_isdst != pc.local_time_zone_table[0].value)
          {
              {
                pc.local_time_zone_table[1].name = probe_tm.tm_zone;
                pc.local_time_zone_table[1].type = tLOCAL_ZONE;
                pc.local_time_zone_table[1].value = probe_tm.tm_isdst;
                pc.local_time_zone_table[2].name = 
                                                  ((void *)0)
                                                      ;
              }
            break;
          }
      }
  }
  if (pc.local_time_zone_table[0].name && pc.local_time_zone_table[1].name
      && ! strcmp (pc.local_time_zone_table[0].name,
                   pc.local_time_zone_table[1].name))
    {



      pc.local_time_zone_table[0].value = -1;
      pc.local_time_zone_table[1].name = 
                                        ((void *)0)
                                            ;
    }

  if (yyparse (&pc) != 0)
    {
      if (debugging (&pc))
        dbg_printf ((input_sentinel <= pc.input
                     ? gettext ("error: parsing failed\n")
                     : gettext ("error: parsing failed, stopped at '%s'\n")),
                    pc.input);
      goto fail;
    }




  if (debugging (&pc))
    {
      dbg_printf (gettext ("input timezone: "));

      if (pc.timespec_seen)
        fprintf (
                stderr
                      , gettext ("'@timespec' - always UTC"));
      else if (pc.zones_seen)
        fprintf (
                stderr
                      , gettext ("parsed date/time string"));
      else if (tzstring)
        {
          if (tz != tzdefault)
            fprintf (
                    stderr
                          , gettext ("TZ=\"%s\" in date string"), tzstring);
          else if ((strcmp (tzstring, "UTC0") == 0))
            {

              fprintf (
                      stderr
                            , gettext ("TZ=\"UTC0\" environment value or -u"));
            }
          else
            fprintf (
                    stderr
                          , gettext ("TZ=\"%s\" environment value"), tzstring);
        }
      else
        fprintf (
                stderr
                      , gettext ("system default"));




      if (pc.local_zones_seen && !pc.zones_seen && 0 < pc.local_isdst)
        fprintf (
                stderr
                      , ", dst");

      if (pc.zones_seen)
        fprintf (
                stderr
                      , " (%s)", time_zone_str (pc.time_zone, time_zone_buf));

      fputc ('\n', 
                  stderr
                        );
    }

  if (pc.timespec_seen)
    *result = pc.seconds;
  else
    {
      if (1 < (pc.times_seen | pc.dates_seen | pc.days_seen | pc.dsts_seen
               | (pc.local_zones_seen + pc.zones_seen)))
        {
          if (debugging (&pc))
            {
              if (pc.times_seen > 1)
                dbg_printf ("error: seen multiple time parts\n");
              if (pc.dates_seen > 1)
                dbg_printf ("error: seen multiple date parts\n");
              if (pc.days_seen > 1)
                dbg_printf ("error: seen multiple days parts\n");
              if (pc.dsts_seen > 1)
                dbg_printf ("error: seen multiple daylight-saving parts\n");
              if ((pc.local_zones_seen + pc.zones_seen) > 1)
                dbg_printf ("error: seen multiple time-zone parts\n");
            }
          goto fail;
        }

      if (! to_tm_year (pc.year, debugging (&pc), &tm.tm_year)
          || __builtin_add_overflow (pc.month, -1, &tm.tm_mon)
          || __builtin_add_overflow (pc.day, 0, &tm.tm_mday))
        {
          if (debugging (&pc))
            dbg_printf (gettext ("error: year, month, or day overflow\n"));
          goto fail;
        }
      if (pc.times_seen || (pc.rels_seen && ! pc.dates_seen && ! pc.days_seen))
        {
          tm.tm_hour = to_hour (pc.hour, pc.meridian);
          if (tm.tm_hour < 0)
            {
              char const *mrd = (pc.meridian == MERam ? "am"
                                 : pc.meridian == MERpm ?"pm" : "");
              if (debugging (&pc))
                dbg_printf (gettext ("error: invalid hour %"
                           "l" "d"
                           "%s\n"),
                            pc.hour, mrd);
              goto fail;
            }
          tm.tm_min = pc.minutes;
          tm.tm_sec = pc.seconds.tv_sec;
          if (debugging (&pc))
            dbg_printf ((pc.times_seen
                         ? gettext ("using specified time as starting value: '%s'\n")
                         : gettext ("using current time as starting value: '%s'\n")),
                        debug_strftime (&tm, dbg_tm, sizeof dbg_tm));
        }
      else
        {
          tm.tm_hour = tm.tm_min = tm.tm_sec = 0;
          pc.seconds.tv_nsec = 0;
          if (debugging (&pc))
            dbg_printf ("warning: using midnight as starting time: 00:00:00\n");
        }


      if (pc.dates_seen | pc.days_seen | pc.times_seen)
        tm.tm_isdst = -1;



      if (pc.local_zones_seen)
        tm.tm_isdst = pc.local_isdst;

      tm0.tm_sec = tm.tm_sec;
      tm0.tm_min = tm.tm_min;
      tm0.tm_hour = tm.tm_hour;
      tm0.tm_mday = tm.tm_mday;
      tm0.tm_mon = tm.tm_mon;
      tm0.tm_year = tm.tm_year;
      tm0.tm_isdst = tm.tm_isdst;
      tm.tm_wday = -1;

      Start = mktime_z (tz, &tm);

      if (! mktime_ok (&tm0, &tm))
        {
          
         _Bool 
              repaired = 
                         0
                              ;
          
         _Bool 
              time_zone_seen = pc.zones_seen != 0;
          if (time_zone_seen)
            {
              char tz2buf[sizeof "XXX" - 1 + TIME_ZONE_BUFSIZE];
              tz2buf[0] = tz2buf[1] = tz2buf[2] = 'X';
              time_zone_str (pc.time_zone, &tz2buf[3]);
              timezone_t tz2 = tzalloc (tz2buf);
              if (!tz2)
                {
                  if (debugging (&pc))
                    dbg_printf (gettext ("error: tzalloc (\"%s\") failed\n"), tz2buf);
                  goto fail;
                }
              tm.tm_sec = tm0.tm_sec;
              tm.tm_min = tm0.tm_min;
              tm.tm_hour = tm0.tm_hour;
              tm.tm_mday = tm0.tm_mday;
              tm.tm_mon = tm0.tm_mon;
              tm.tm_year = tm0.tm_year;
              tm.tm_isdst = tm0.tm_isdst;
              tm.tm_wday = -1;
              Start = mktime_z (tz2, &tm);
              repaired = mktime_ok (&tm0, &tm);
              tzfree (tz2);
            }

          if (! repaired)
            {
              debug_mktime_not_ok (&tm0, &tm, &pc, time_zone_seen);
              goto fail;
            }
        }

      char dbg_ord[DBGBUFSIZE];

      if (pc.days_seen && ! pc.dates_seen)
        {
          intmax_t dayincr;
          if (__builtin_mul_overflow ((pc.day_ordinal - (0 < pc.day_ordinal && tm.tm_wday != pc.day_number)), 7, &dayincr)



              || __builtin_add_overflow ((pc.day_number - tm.tm_wday + 7) % 7, dayincr, &dayincr)

              || __builtin_add_overflow (dayincr, tm.tm_mday, &tm.tm_mday))
            Start = -1;
          else
            {
              tm.tm_isdst = -1;
              Start = mktime_z (tz, &tm);
            }

          if (Start == (time_t) -1)
            {
              if (debugging (&pc))
                dbg_printf (gettext ("error: day '%s' " "(day ordinal=%"
                           "l" "d"
                           " number=%d) " "resulted in an invalid date: '%s'\n")

                                                                    ,
                            str_days (&pc, dbg_ord, sizeof dbg_ord),
                            pc.day_ordinal, pc.day_number,
                            debug_strfdatetime (&tm, &pc, dbg_tm,
                                                sizeof dbg_tm));
              goto fail;
            }

          if (debugging (&pc))
            dbg_printf (gettext ("new start date: '%s' is '%s'\n"),
                        str_days (&pc, dbg_ord, sizeof dbg_ord),
                        debug_strfdatetime (&tm, &pc, dbg_tm, sizeof dbg_tm));

        }

      if (debugging (&pc))
        {
          if (!pc.dates_seen && !pc.days_seen)
            dbg_printf (gettext ("using current date as starting value: '%s'\n"),
                        debug_strfdate (&tm, dbg_tm, sizeof dbg_tm));

          if (pc.days_seen && pc.dates_seen)
            dbg_printf (gettext ("warning: day (%s) ignored when explicit dates " "are given\n")
                                        ,
                        str_days (&pc, dbg_ord, sizeof dbg_ord));

          dbg_printf (gettext ("starting date/time: '%s'\n"),
                      debug_strfdatetime (&tm, &pc, dbg_tm, sizeof dbg_tm));
        }


      if (pc.rel.year | pc.rel.month | pc.rel.day)
        {
          if (debugging (&pc))
            {
              if ((pc.rel.year != 0 || pc.rel.month != 0) && tm.tm_mday != 15)
                dbg_printf (gettext ("warning: when adding relative months/years, " "it is recommended to specify the 15th of the " "months\n")

                                         );

              if (pc.rel.day != 0 && tm.tm_hour != 12)
                dbg_printf (gettext ("warning: when adding relative days, " "it is recommended to specify noon\n")
                                                                    );
            }

          int year, month, day;
          if (__builtin_add_overflow (tm.tm_year, pc.rel.year, &year)
              || __builtin_add_overflow (tm.tm_mon, pc.rel.month, &month)
              || __builtin_add_overflow (tm.tm_mday, pc.rel.day, &day))
            {
              if (debugging (&pc))
                dbg_printf (gettext ("error: %s:%d\n"), "parse-datetime.y", 2149);
              goto fail;
            }
          tm.tm_year = year;
          tm.tm_mon = month;
          tm.tm_mday = day;
          tm.tm_hour = tm0.tm_hour;
          tm.tm_min = tm0.tm_min;
          tm.tm_sec = tm0.tm_sec;
          tm.tm_isdst = tm0.tm_isdst;
          Start = mktime_z (tz, &tm);
          if (Start == (time_t) -1)
            {
              if (debugging (&pc))
                dbg_printf (gettext ("error: adding relative date resulted " "in an invalid date: '%s'\n")
                                                           ,
                            debug_strfdatetime (&tm, &pc, dbg_tm,
                                                sizeof dbg_tm));
              goto fail;
            }

          if (debugging (&pc))
            {
              dbg_printf (gettext ("after date adjustment " "(%+"
                         "l" "d"
                         " years, %+"
                         "l" "d"
                         " months, " "%+"
                         "l" "d"
                         " days),\n")

                                                   ,
                          pc.rel.year, pc.rel.month, pc.rel.day);
              dbg_printf (gettext ("    new date/time = '%s'\n"),
                          debug_strfdatetime (&tm, &pc, dbg_tm,
                                              sizeof dbg_tm));
              if (tm0.tm_isdst != -1 && tm.tm_isdst != tm0.tm_isdst)
                dbg_printf (gettext ("warning: daylight saving time changed after " "date adjustment\n")
                                                  );
              if (pc.rel.day == 0
                  && (tm.tm_mday != day
                      || (pc.rel.month == 0 && tm.tm_mon != month)))
                {
                  dbg_printf (gettext ("warning: month/year adjustment resulted in " "shifted dates:\n")
                                                   );
                  char tm_year_buf[TM_YEAR_BUFSIZE];
                  dbg_printf (gettext ("     adjusted Y M D: %s %02d %02d\n"),
                              tm_year_str (year, tm_year_buf), month + 1, day);
                  dbg_printf (gettext ("   normalized Y M D: %s %02d %02d\n"),
                              tm_year_str (tm.tm_year, tm_year_buf),
                              tm.tm_mon + 1, tm.tm_mday);
                }
            }

        }



      if (pc.zones_seen)
        {
          
         _Bool 
              overflow = 
                         0
                              ;

          long int utcoff = tm.tm_gmtoff;







          intmax_t delta;
          overflow |= __builtin_sub_overflow (pc.time_zone, utcoff, &delta);
          time_t t1;
          overflow |= __builtin_sub_overflow (Start, delta, &t1);
          if (overflow)
            {
              if (debugging (&pc))
                dbg_printf (gettext ("error: timezone %d caused time_t overflow\n"),
                            pc.time_zone);
              goto fail;
            }
          Start = t1;
        }

      if (debugging (&pc))
        {
          intmax_t Starti = Start;
          dbg_printf (gettext ("'%s' = %"
                     "l" "d"
                     " epoch-seconds\n"),
                      debug_strfdatetime (&tm, &pc, dbg_tm, sizeof dbg_tm),
                      Starti);
        }
      {
        intmax_t orig_ns = pc.seconds.tv_nsec;
        intmax_t sum_ns = orig_ns + pc.rel.ns;
        int normalized_ns = (sum_ns % BILLION + BILLION) % BILLION;
        int d4 = (sum_ns - normalized_ns) / BILLION;
        intmax_t d1, t1, d2, t2, t3;
        time_t t4;
        if (__builtin_mul_overflow (pc.rel.hour, 60 * 60, &d1)
            || __builtin_add_overflow (Start, d1, &t1)
            || __builtin_mul_overflow (pc.rel.minutes, 60, &d2)
            || __builtin_add_overflow (t1, d2, &t2)
            || __builtin_add_overflow (t2, pc.rel.seconds, &t3)
            || __builtin_add_overflow (t3, d4, &t4))
          {
            if (debugging (&pc))
              dbg_printf (gettext ("error: adding relative time caused an " "overflow\n")
                                         );
            goto fail;
          }

        result->tv_sec = t4;
        result->tv_nsec = normalized_ns;

        if (debugging (&pc)
            && (pc.rel.hour | pc.rel.minutes | pc.rel.seconds | pc.rel.ns))
          {
            dbg_printf (gettext ("after time adjustment (%+"
                       "l" "d"
                       " hours, " "%+"
                       "l" "d"
                       " minutes, " "%+"
                       "l" "d"
                       " seconds, %+d ns),\n")

                                                            ,
                        pc.rel.hour, pc.rel.minutes, pc.rel.seconds,
                        pc.rel.ns);
            intmax_t t4i = t4;
            dbg_printf (gettext ("    new time = %"
                       "l" "d"
                       " epoch-seconds\n"), t4i);
            struct tm lmt;
            if (tm.tm_isdst != -1 && localtime_rz (tz, &result->tv_sec, &lmt)
                && tm.tm_isdst != lmt.tm_isdst)
              dbg_printf (gettext ("warning: daylight saving time changed after " "time adjustment\n")
                                                );
          }
      }
    }

  if (debugging (&pc))
    {

      if (! tzstring)
        dbg_printf (gettext ("timezone: system default\n"));
      else if ((strcmp (tzstring, "UTC0") == 0))
        dbg_printf (gettext ("timezone: Universal Time\n"));
      else
        dbg_printf (gettext ("timezone: TZ=\"%s\" environment value\n"), tzstring);

      intmax_t sec = result->tv_sec;
      int nsec = result->tv_nsec;
      dbg_printf (gettext ("final: %"
                 "l" "d"
                 ".%09d (epoch-seconds)\n"),
                  sec, nsec);

      struct tm gmt, lmt;
      
     _Bool 
          got_utc = !!gmtime_r (&result->tv_sec, &gmt);
      if (got_utc)
        dbg_printf (gettext ("final: %s (UTC)\n"),
                    debug_strfdatetime (&gmt, 
                                             ((void *)0)
                                                 ,
                                        dbg_tm, sizeof dbg_tm));
      if (localtime_rz (tz, &result->tv_sec, &lmt))
        {

          
         _Bool 
              got_utcoff = 
                           1
                               ;
          long int utcoff = lmt.tm_gmtoff;






          if (got_utcoff)
            dbg_printf (gettext ("final: %s (UTC%s)\n"),
                        debug_strfdatetime (&lmt, 
                                                 ((void *)0)
                                                     , dbg_tm, sizeof dbg_tm),
                        time_zone_str (utcoff, time_zone_buf));
          else
            dbg_printf (gettext ("final: %s (unknown time zone offset)\n"),
                        debug_strfdatetime (&lmt, 
                                                 ((void *)0)
                                                     , dbg_tm, sizeof dbg_tm));
        }
    }

  ok = 
      1
          ;

 fail:
  if (tz != tzdefault)
    tzfree (tz);
  free (tz1alloc);
  return ok;
}

_Bool

parse_datetime (struct timespec *result, char const *p,
                struct timespec const *now)
{
  char const *tzstring = getenv ("TZ");
  timezone_t tz = tzalloc (tzstring);
  if (!tz)
    return 
          0
               ;
  
 _Bool 
      ok = parse_datetime_body (result, p, now, 0, tz, tzstring);
  tzfree (tz);
  return ok;
}
