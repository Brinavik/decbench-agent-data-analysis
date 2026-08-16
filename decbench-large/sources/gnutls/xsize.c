


       
       










extern inline size_t __attribute__ ((__pure__))
xsum (size_t size1, size_t size2)
{
  size_t sum = size1 + size2;
  return (sum >= size1 ? sum : 
                              (18446744073709551615UL)
                                      );
}


extern inline size_t __attribute__ ((__pure__))
xsum3 (size_t size1, size_t size2, size_t size3)
{
  return xsum (xsum (size1, size2), size3);
}


extern inline size_t __attribute__ ((__pure__))
xsum4 (size_t size1, size_t size2, size_t size3, size_t size4)
{
  return xsum (xsum (xsum (size1, size2), size3), size4);
}


extern inline size_t __attribute__ ((__pure__))
xmax (size_t size1, size_t size2)
{


  return (size1 >= size2 ? size1 : size2);
}

