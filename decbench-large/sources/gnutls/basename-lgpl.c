


extern char *last_component (char const *filename) __attribute__ ((__pure__));




extern size_t base_len (char const *filename) __attribute__ ((__pure__));

       
       







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

       


char *
last_component (char const *name)
{
  char const *base = name + ((void) (name), 0);
  char const *p;
  
 _Bool 
      last_was_slash = 
                       0
                            ;

  while (((*base) == '/'))
    base++;

  for (p = base; *p; p++)
    {
      if (((*p) == '/'))
        last_was_slash = 
                        1
                            ;
      else if (last_was_slash)
        {
          base = p;
          last_was_slash = 
                          0
                               ;
        }
    }

  return (char *) base;
}

size_t
base_len (char const *name)
{
  size_t len;
  size_t prefix_len = ((void) (name), 0);

  for (len = strlen (name); 1 < len && ((name[len - 1]) == '/'); len--)
    continue;

  if (0 && len == 1
      && ((name[0]) == '/') && ((name[1]) == '/') && ! name[2])
    return 2;

  if (0 && prefix_len
      && len == prefix_len && ((name[prefix_len]) == '/'))
    return prefix_len + 1;

  return len;
}
