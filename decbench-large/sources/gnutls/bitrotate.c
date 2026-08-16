
       
       
       
       
       
extern int _gl_cxxalias_dummy

                                      ;

extern int _gl_cxxalias_dummy;






extern inline uint64_t
rotl64 (uint64_t x, int n)
{
  return ((x << n) | (x >> (64 - n))) & 
                                       (18446744073709551615UL)
                                                 ;
}




extern inline uint64_t
rotr64 (uint64_t x, int n)
{
  return ((x >> n) | (x << (64 - n))) & 
                                       (18446744073709551615UL)
                                                 ;
}





extern inline uint32_t
rotl32 (uint32_t x, int n)
{
  return ((x << n) | (x >> (32 - n))) & 
                                       (4294967295U)
                                                 ;
}




extern inline uint32_t
rotr32 (uint32_t x, int n)
{
  return ((x >> n) | (x << (32 - n))) & 
                                       (4294967295U)
                                                 ;
}




extern inline size_t
rotl_sz (size_t x, int n)
{
  return ((x << n) | (x >> ((8 * sizeof x) - n))) & 
                                                          (18446744073709551615UL)
                                                                  ;
}




extern inline size_t
rotr_sz (size_t x, int n)
{
  return ((x >> n) | (x << ((8 * sizeof x) - n))) & 
                                                          (18446744073709551615UL)
                                                                  ;
}






extern inline uint16_t
rotl16 (uint16_t x, int n)
{
  return (((unsigned int) x << n) | ((unsigned int) x >> (16 - n)))
         & 
          (65535)
                    ;
}






extern inline uint16_t
rotr16 (uint16_t x, int n)
{
  return (((unsigned int) x >> n) | ((unsigned int) x << (16 - n)))
         & 
          (65535)
                    ;
}






extern inline uint8_t
rotl8 (uint8_t x, int n)
{
  return (((unsigned int) x << n) | ((unsigned int) x >> (8 - n))) & 
                                                                    (255)
                                                                             ;
}






extern inline uint8_t
rotr8 (uint8_t x, int n)
{
  return (((unsigned int) x >> n) | ((unsigned int) x << (8 - n))) & 
                                                                    (255)
                                                                             ;
}


