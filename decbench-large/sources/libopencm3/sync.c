#define LIBOPENCM3_CM3_SYNC_H 

#define LIBOPENCM3_CM3_COMMON_H 
#define BEGIN_DECLS 
#define END_DECLS 






#define LIBOPENCM3_DEPRECATED(x) __attribute__((deprecated(x)))


#define MMIO8(addr) (*(volatile uint8_t *)(addr))
#define MMIO16(addr) (*(volatile uint16_t *)(addr))
#define MMIO32(addr) (*(volatile uint32_t *)(addr))
#define MMIO64(addr) (*(volatile uint64_t *)(addr))


#define BBIO_SRAM(addr,bit) MMIO32((((uint32_t)addr) & 0x0FFFFF) * 32 + 0x22000000 + (bit) * 4)


#define BBIO_PERIPH(addr,bit) MMIO32((((uint32_t)addr) & 0x0FFFFF) * 32 + 0x42000000 + (bit) * 4)




#define BIT0 (1<<0)
#define BIT1 (1<<1)
#define BIT2 (1<<2)
#define BIT3 (1<<3)
#define BIT4 (1<<4)
#define BIT5 (1<<5)
#define BIT6 (1<<6)
#define BIT7 (1<<7)
#define BIT8 (1<<8)
#define BIT9 (1<<9)
#define BIT10 (1<<10)
#define BIT11 (1<<11)
#define BIT12 (1<<12)
#define BIT13 (1<<13)
#define BIT14 (1<<14)
#define BIT15 (1<<15)
#define BIT16 (1<<16)
#define BIT17 (1<<17)
#define BIT18 (1<<18)
#define BIT19 (1<<19)
#define BIT20 (1<<20)
#define BIT21 (1<<21)
#define BIT22 (1<<22)
#define BIT23 (1<<23)
#define BIT24 (1<<24)
#define BIT25 (1<<25)
#define BIT26 (1<<26)
#define BIT27 (1<<27)
#define BIT28 (1<<28)
#define BIT29 (1<<29)
#define BIT30 (1<<30)
#define BIT31 (1<<31)




void __dmb(void);
uint32_t __ldrex(volatile uint32_t *addr);
uint32_t __strex(uint32_t val, volatile uint32_t *addr);





typedef uint32_t mutex_t;

#define MUTEX_UNLOCKED 0
#define MUTEX_LOCKED 1

void mutex_lock(mutex_t *m);
uint32_t mutex_trylock(mutex_t *m);
void mutex_unlock(mutex_t *m);






void __dmb()
{
 __asm__ volatile ("dmb");
}




uint32_t __ldrex(volatile uint32_t *addr)
{
 uint32_t res;
 __asm__ volatile ("ldrex %0, [%1]" : "=r" (res) : "r" (addr));
 return res;
}

uint32_t __strex(uint32_t val, volatile uint32_t *addr)
{
 uint32_t res;
 __asm__ volatile ("strex %0, %2, [%1]"
     : "=&r" (res) : "r" (addr), "r" (val));
 return res;
}

void mutex_lock(mutex_t *m)
{
 while (!mutex_trylock(m));
}


uint32_t mutex_trylock(mutex_t *m)
{
 uint32_t status = 1;


 if (__ldrex(m) == 0) {

  status = __strex(1, m);
 }


 __dmb();



 return status == 0;
}

void mutex_unlock(mutex_t *m)
{

 __dmb();


 *m = 0;
}
