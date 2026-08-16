

       
       
       
       
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


extern void * mmalloca (size_t n);



extern void freea (void *p);
enum
{


  sa_alignment_long = __alignof__ (long),
  sa_alignment_double = __alignof__ (double),
  sa_alignment_longlong = __alignof__ (long long),
  sa_alignment_longdouble = __alignof__ (long double),
  sa_alignment_max = ((sa_alignment_long - 1) | (sa_alignment_double - 1)
                      | (sa_alignment_longlong - 1)
                      | (sa_alignment_longdouble - 1)
                     ) + 1
};

typedef ptrdiff_t idx_t;
       
       

typedef unsigned char small_t;

_Static_assert (2 * sa_alignment_max - 1 <= (small_t) -1, "verify (" "2 * sa_alignment_max - 1 <= (small_t) -1" ")");

void *
mmalloca (size_t n)
{



  int plus = sizeof (small_t) + 2 * sa_alignment_max - 1;
  idx_t nplus;
  if (!__builtin_add_overflow (n, plus, &nplus) && !__builtin_mul_overflow_p (nplus, 1, (ptrdiff_t) 1))
    {
      char *mem = (char *) malloc (nplus);

      if (mem != 
                ((void *)0)
                    )
        {
          char *p =
            (char *)((((uintptr_t)mem + sizeof (small_t) + sa_alignment_max - 1)
                      & ~(uintptr_t)(2 * sa_alignment_max - 1))
                     + sa_alignment_max);





          ((small_t *) p)[-1] = p - mem;

          return p;
        }
    }

  return 
        ((void *)0)
            ;







}


void
freea (void *p)
{

  if ((uintptr_t) p & (sa_alignment_max - 1))
    {

      abort ();
    }

  if ((uintptr_t) p & sa_alignment_max)
    {
      void *mem = (char *) p - ((small_t *) p)[-1];
      free (mem);
    }
}
