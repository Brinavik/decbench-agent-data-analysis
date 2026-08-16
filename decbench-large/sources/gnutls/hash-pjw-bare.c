







extern size_t hash_pjw_bare (const void *x, size_t n) __attribute__ ((__pure__));

       
       

size_t
hash_pjw_bare (const void *x, size_t n)
{
  const unsigned char *s = x;
  size_t h = 0;
  unsigned i;

  for (i = 0; i < n; i++)
    h = s[i] + ((h << 9) | (h >> ((sizeof (size_t) * 8) - 9)));

  return h;
}
