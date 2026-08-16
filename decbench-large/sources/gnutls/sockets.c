

int gl_sockets_startup (int version)

  __attribute__ ((__const__))

  ;

int gl_sockets_cleanup (void)

  __attribute__ ((__const__))

  ;
int
gl_sockets_startup (int version __attribute__ ((__unused__)))
{
  return 0;
}

int
gl_sockets_cleanup (void)
{
  return 0;
}
