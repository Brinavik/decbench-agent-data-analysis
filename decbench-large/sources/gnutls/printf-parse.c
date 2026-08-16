












       
extern wchar_t * wcsdup (const wchar_t *s);

extern int _gl_cxxalias_dummy;



extern int _gl_cxxalias_dummy;







typedef enum
{
  TYPE_NONE,
  TYPE_SCHAR,
  TYPE_UCHAR,
  TYPE_SHORT,
  TYPE_USHORT,
  TYPE_INT,
  TYPE_UINT,
  TYPE_LONGINT,
  TYPE_ULONGINT,
  TYPE_LONGLONGINT,
  TYPE_ULONGLONGINT,
  TYPE_DOUBLE,
  TYPE_LONGDOUBLE,
  TYPE_CHAR,

  TYPE_WIDE_CHAR,

  TYPE_STRING,

  TYPE_WIDE_STRING,

  TYPE_POINTER,
  TYPE_COUNT_SCHAR_POINTER,
  TYPE_COUNT_SHORT_POINTER,
  TYPE_COUNT_INT_POINTER,
  TYPE_COUNT_LONGINT_POINTER,
  TYPE_COUNT_LONGLONGINT_POINTER






} arg_type;


typedef struct
{
  arg_type type;
  union
  {
    signed char a_schar;
    unsigned char a_uchar;
    short a_short;
    unsigned short a_ushort;
    int a_int;
    unsigned int a_uint;
    long int a_longint;
    unsigned long int a_ulongint;
    long long int a_longlongint;
    unsigned long long int a_ulonglongint;
    float a_float;
    double a_double;
    long double a_longdouble;
    int a_char;

    wint_t a_wide_char;

    const char* a_string;

    const wchar_t* a_wide_string;

    void* a_pointer;
    signed char * a_count_schar_pointer;
    short * a_count_short_pointer;
    int * a_count_int_pointer;
    long int * a_count_longint_pointer;
    long long int * a_count_longlongint_pointer;






  }
  a;
}
argument;




typedef struct
{
  size_t count;
  argument *arg;
  argument direct_alloc_arg[7];
}
arguments;






extern

int printf_fetchargs (va_list args, arguments *a);
typedef struct
{
  const char* dir_start;
  const char* dir_end;
  int flags;
  const char* width_start;
  const char* width_end;
  size_t width_arg_index;
  const char* precision_start;
  const char* precision_end;
  size_t precision_arg_index;
  char conversion;
  size_t arg_index;
}
char_directive;


typedef struct
{
  size_t count;
  char_directive *dir;
  size_t max_width_length;
  size_t max_precision_length;
  char_directive direct_alloc_dir[7];
}
char_directives;
extern

int printf_parse (const char *format, char_directives *d, arguments *a);



       
       
       
       
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






       
       











inline size_t __attribute__ ((__pure__))
xsum (size_t size1, size_t size2)
{
  size_t sum = size1 + size2;
  return (sum >= size1 ? sum : 
                              (18446744073709551615UL)
                                      );
}


inline size_t __attribute__ ((__pure__))
xsum3 (size_t size1, size_t size2, size_t size3)
{
  return xsum (xsum (size1, size2), size3);
}


inline size_t __attribute__ ((__pure__))
xsum4 (size_t size1, size_t size2, size_t size3, size_t size4)
{
  return xsum (xsum (xsum (size1, size2), size3), size4);
}


inline size_t __attribute__ ((__pure__))
xmax (size_t size1, size_t size2)
{


  return (size1 >= size2 ? size1 : size2);
}

int
printf_parse (const char *format, char_directives *d, arguments *a)
{
  const char *cp = format;
  size_t arg_posn = 0;
  size_t d_allocated;
  size_t a_allocated;
  size_t max_width_length = 0;
  size_t max_precision_length = 0;

  d->count = 0;
  d_allocated = 7;
  d->dir = d->direct_alloc_dir;

  a->count = 0;
  a_allocated = 7;
  a->arg = a->direct_alloc_arg;
  while (*cp != '\0')
    {
      char c = *cp++;
      if (c == '%')
        {
          size_t arg_index = (~(size_t)0);
          char_directive *dp = &d->dir[d->count];


          dp->dir_start = cp - 1;
          dp->flags = 0;
          dp->width_start = 
                           ((void *)0)
                               ;
          dp->width_end = 
                         ((void *)0)
                             ;
          dp->width_arg_index = (~(size_t)0);
          dp->precision_start = 
                               ((void *)0)
                                   ;
          dp->precision_end = 
                             ((void *)0)
                                 ;
          dp->precision_arg_index = (~(size_t)0);
          dp->arg_index = (~(size_t)0);


          if (*cp >= '0' && *cp <= '9')
            {
              const char *np;

              for (np = cp; *np >= '0' && *np <= '9'; np++)
                ;
              if (*np == '$')
                {
                  size_t n = 0;

                  for (np = cp; *np >= '0' && *np <= '9'; np++)
                    n = xsum (((n) <= 
                             (18446744073709551615UL) 
                             / (10) ? (size_t) (n) * (10) : 
                             (18446744073709551615UL)
                             ), *np - '0');
                  if (n == 0)

                    goto error;
                  if (((n) == 
                     (18446744073709551615UL)
                     ))

                    goto error;
                  arg_index = n - 1;
                  cp = np + 1;
                }
            }


          for (;;)
            {
              if (*cp == '\'')
                {
                  dp->flags |= 1;
                  cp++;
                }
              else if (*cp == '-')
                {
                  dp->flags |= 2;
                  cp++;
                }
              else if (*cp == '+')
                {
                  dp->flags |= 4;
                  cp++;
                }
              else if (*cp == ' ')
                {
                  dp->flags |= 8;
                  cp++;
                }
              else if (*cp == '#')
                {
                  dp->flags |= 16;
                  cp++;
                }
              else if (*cp == '0')
                {
                  dp->flags |= 32;
                  cp++;
                }

              else if (*cp == 'I')
                {
                  dp->flags |= 64;
                  cp++;
                }

              else
                break;
            }


          if (*cp == '*')
            {
              dp->width_start = cp;
              cp++;
              dp->width_end = cp;
              if (max_width_length < 1)
                max_width_length = 1;


              if (*cp >= '0' && *cp <= '9')
                {
                  const char *np;

                  for (np = cp; *np >= '0' && *np <= '9'; np++)
                    ;
                  if (*np == '$')
                    {
                      size_t n = 0;

                      for (np = cp; *np >= '0' && *np <= '9'; np++)
                        n = xsum (((n) <= 
                                 (18446744073709551615UL) 
                                 / (10) ? (size_t) (n) * (10) : 
                                 (18446744073709551615UL)
                                 ), *np - '0');
                      if (n == 0)

                        goto error;
                      if (((n) == 
                         (18446744073709551615UL)
                         ))

                        goto error;
                      dp->width_arg_index = n - 1;
                      cp = np + 1;
                    }
                }
              if (dp->width_arg_index == (~(size_t)0))
                {
                  dp->width_arg_index = arg_posn++;
                  if (dp->width_arg_index == (~(size_t)0))

                    goto error;
                }
              { size_t n = (dp->width_arg_index); if (n >= a_allocated) { size_t memory_size; argument *memory; a_allocated = ((a_allocated) <= 
             (18446744073709551615UL) 
             / (2) ? (size_t) (a_allocated) * (2) : 
             (18446744073709551615UL)
             ); if (a_allocated <= n) a_allocated = xsum (n, 1); memory_size = ((a_allocated) <= 
             (18446744073709551615UL) 
             / (sizeof (argument)) ? (size_t) (a_allocated) * (sizeof (argument)) : 
             (18446744073709551615UL)
             ); if (((memory_size) == 
             (18446744073709551615UL)
             )) goto out_of_memory; memory = (argument *) (a->arg != a->direct_alloc_arg ? realloc (a->arg, memory_size) : malloc (memory_size)); if (memory == 
             ((void *)0)
             ) goto out_of_memory; if (a->arg == a->direct_alloc_arg) memcpy (memory, a->arg, a->count * sizeof (argument)); a->arg = memory; } while (a->count <= n) a->arg[a->count++].type = TYPE_NONE; if (a->arg[n].type == TYPE_NONE) a->arg[n].type = (TYPE_INT); else if (a->arg[n].type != (TYPE_INT)) goto error; };
            }
          else if (*cp >= '0' && *cp <= '9')
            {
              size_t width_length;

              dp->width_start = cp;
              for (; *cp >= '0' && *cp <= '9'; cp++)
                ;
              dp->width_end = cp;
              width_length = dp->width_end - dp->width_start;
              if (max_width_length < width_length)
                max_width_length = width_length;
            }


          if (*cp == '.')
            {
              cp++;
              if (*cp == '*')
                {
                  dp->precision_start = cp - 1;
                  cp++;
                  dp->precision_end = cp;
                  if (max_precision_length < 2)
                    max_precision_length = 2;


                  if (*cp >= '0' && *cp <= '9')
                    {
                      const char *np;

                      for (np = cp; *np >= '0' && *np <= '9'; np++)
                        ;
                      if (*np == '$')
                        {
                          size_t n = 0;

                          for (np = cp; *np >= '0' && *np <= '9'; np++)
                            n = xsum (((n) <= 
                                     (18446744073709551615UL) 
                                     / (10) ? (size_t) (n) * (10) : 
                                     (18446744073709551615UL)
                                     ), *np - '0');
                          if (n == 0)

                            goto error;
                          if (((n) == 
                             (18446744073709551615UL)
                             ))


                            goto error;
                          dp->precision_arg_index = n - 1;
                          cp = np + 1;
                        }
                    }
                  if (dp->precision_arg_index == (~(size_t)0))
                    {
                      dp->precision_arg_index = arg_posn++;
                      if (dp->precision_arg_index == (~(size_t)0))

                        goto error;
                    }
                  { size_t n = (dp->precision_arg_index); if (n >= a_allocated) { size_t memory_size; argument *memory; a_allocated = ((a_allocated) <= 
                 (18446744073709551615UL) 
                 / (2) ? (size_t) (a_allocated) * (2) : 
                 (18446744073709551615UL)
                 ); if (a_allocated <= n) a_allocated = xsum (n, 1); memory_size = ((a_allocated) <= 
                 (18446744073709551615UL) 
                 / (sizeof (argument)) ? (size_t) (a_allocated) * (sizeof (argument)) : 
                 (18446744073709551615UL)
                 ); if (((memory_size) == 
                 (18446744073709551615UL)
                 )) goto out_of_memory; memory = (argument *) (a->arg != a->direct_alloc_arg ? realloc (a->arg, memory_size) : malloc (memory_size)); if (memory == 
                 ((void *)0)
                 ) goto out_of_memory; if (a->arg == a->direct_alloc_arg) memcpy (memory, a->arg, a->count * sizeof (argument)); a->arg = memory; } while (a->count <= n) a->arg[a->count++].type = TYPE_NONE; if (a->arg[n].type == TYPE_NONE) a->arg[n].type = (TYPE_INT); else if (a->arg[n].type != (TYPE_INT)) goto error; };
                }
              else
                {
                  size_t precision_length;

                  dp->precision_start = cp - 1;
                  for (; *cp >= '0' && *cp <= '9'; cp++)
                    ;
                  dp->precision_end = cp;
                  precision_length = dp->precision_end - dp->precision_start;
                  if (max_precision_length < precision_length)
                    max_precision_length = precision_length;
                }
            }

          {
            arg_type type;


            {
              int flags = 0;

              for (;;)
                {
                  if (*cp == 'h')
                    {
                      flags |= (1 << (flags & 1));
                      cp++;
                    }
                  else if (*cp == 'L')
                    {
                      flags |= 4;
                      cp++;
                    }
                  else if (*cp == 'l')
                    {
                      flags += 8;
                      cp++;
                    }
                  else if (*cp == 'j')
                    {
                      if (sizeof (intmax_t) > sizeof (long))
                        {

                          flags += 16;
                        }
                      else if (sizeof (intmax_t) > sizeof (int))
                        {

                          flags += 8;
                        }
                      cp++;
                    }
                  else if (*cp == 'z' || *cp == 'Z')
                    {



                      if (sizeof (size_t) > sizeof (long))
                        {

                          flags += 16;
                        }
                      else if (sizeof (size_t) > sizeof (int))
                        {

                          flags += 8;
                        }
                      cp++;
                    }
                  else if (*cp == 't')
                    {
                      if (sizeof (ptrdiff_t) > sizeof (long))
                        {

                          flags += 16;
                        }
                      else if (sizeof (ptrdiff_t) > sizeof (int))
                        {

                          flags += 8;
                        }
                      cp++;
                    }
                  else
                    break;
                }


              c = *cp++;
              switch (c)
                {
                case 'd': case 'i':

                  if (flags >= 16 || (flags & 4))
                    type = TYPE_LONGLONGINT;
                  else


                  if (flags >= 8)
                    type = TYPE_LONGINT;
                  else if (flags & 2)
                    type = TYPE_SCHAR;
                  else if (flags & 1)
                    type = TYPE_SHORT;
                  else
                    type = TYPE_INT;
                  break;
                case 'o': case 'u': case 'x': case 'X':

                  if (flags >= 16 || (flags & 4))
                    type = TYPE_ULONGLONGINT;
                  else


                  if (flags >= 8)
                    type = TYPE_ULONGINT;
                  else if (flags & 2)
                    type = TYPE_UCHAR;
                  else if (flags & 1)
                    type = TYPE_USHORT;
                  else
                    type = TYPE_UINT;
                  break;
                case 'f': case 'F': case 'e': case 'E': case 'g': case 'G':
                case 'a': case 'A':
                  if (flags >= 16 || (flags & 4))
                    type = TYPE_LONGDOUBLE;
                  else
                    type = TYPE_DOUBLE;
                  break;
                case 'c':
                  if (flags >= 8)

                    type = TYPE_WIDE_CHAR;



                  else
                    type = TYPE_CHAR;
                  break;

                case 'C':
                  type = TYPE_WIDE_CHAR;
                  c = 'c';
                  break;

                case 's':
                  if (flags >= 8)

                    type = TYPE_WIDE_STRING;



                  else
                    type = TYPE_STRING;
                  break;

                case 'S':
                  type = TYPE_WIDE_STRING;
                  c = 's';
                  break;

                case 'p':
                  type = TYPE_POINTER;
                  break;
                case 'n':

                  if (flags >= 16 || (flags & 4))
                    type = TYPE_COUNT_LONGLONGINT_POINTER;
                  else


                  if (flags >= 8)
                    type = TYPE_COUNT_LONGINT_POINTER;
                  else if (flags & 2)
                    type = TYPE_COUNT_SCHAR_POINTER;
                  else if (flags & 1)
                    type = TYPE_COUNT_SHORT_POINTER;
                  else
                    type = TYPE_COUNT_INT_POINTER;
                  break;
                case '%':
                  type = TYPE_NONE;
                  break;
                default:

                  goto error;
                }
            }

            if (type != TYPE_NONE)
              {
                dp->arg_index = arg_index;
                if (dp->arg_index == (~(size_t)0))
                  {
                    dp->arg_index = arg_posn++;
                    if (dp->arg_index == (~(size_t)0))

                      goto error;
                  }
                { size_t n = (dp->arg_index); if (n >= a_allocated) { size_t memory_size; argument *memory; a_allocated = ((a_allocated) <= 
               (18446744073709551615UL) 
               / (2) ? (size_t) (a_allocated) * (2) : 
               (18446744073709551615UL)
               ); if (a_allocated <= n) a_allocated = xsum (n, 1); memory_size = ((a_allocated) <= 
               (18446744073709551615UL) 
               / (sizeof (argument)) ? (size_t) (a_allocated) * (sizeof (argument)) : 
               (18446744073709551615UL)
               ); if (((memory_size) == 
               (18446744073709551615UL)
               )) goto out_of_memory; memory = (argument *) (a->arg != a->direct_alloc_arg ? realloc (a->arg, memory_size) : malloc (memory_size)); if (memory == 
               ((void *)0)
               ) goto out_of_memory; if (a->arg == a->direct_alloc_arg) memcpy (memory, a->arg, a->count * sizeof (argument)); a->arg = memory; } while (a->count <= n) a->arg[a->count++].type = TYPE_NONE; if (a->arg[n].type == TYPE_NONE) a->arg[n].type = (type); else if (a->arg[n].type != (type)) goto error; };
              }
            dp->conversion = c;
            dp->dir_end = cp;
          }

          d->count++;
          if (d->count >= d_allocated)
            {
              size_t memory_size;
              char_directive *memory;

              d_allocated = ((d_allocated) <= 
                           (18446744073709551615UL) 
                           / (2) ? (size_t) (d_allocated) * (2) : 
                           (18446744073709551615UL)
                           );
              memory_size = ((d_allocated) <= 
                           (18446744073709551615UL) 
                           / (sizeof (char_directive)) ? (size_t) (d_allocated) * (sizeof (char_directive)) : 
                           (18446744073709551615UL)
                           );
              if (((memory_size) == 
                 (18446744073709551615UL)
                 ))

                goto out_of_memory;
              memory = (char_directive *) (d->dir != d->direct_alloc_dir
                                      ? realloc (d->dir, memory_size)
                                      : malloc (memory_size));
              if (memory == 
                           ((void *)0)
                               )

                goto out_of_memory;
              if (d->dir == d->direct_alloc_dir)
                memcpy (memory, d->dir, d->count * sizeof (char_directive));
              d->dir = memory;
            }
        }







    }
  d->dir[d->count].dir_start = cp;

  d->max_width_length = max_width_length;
  d->max_precision_length = max_precision_length;
  return 0;

error:
  if (a->arg != a->direct_alloc_arg)
    free (a->arg);
  if (d->dir != d->direct_alloc_dir)
    free (d->dir);
  
 (*__errno_location ()) 
       = 
         22
               ;
  return -1;

out_of_memory:
  if (a->arg != a->direct_alloc_arg)
    free (a->arg);
  if (d->dir != d->direct_alloc_dir)
    free (d->dir);
  
 (*__errno_location ()) 
       = 
         12
               ;
  return -1;
}
