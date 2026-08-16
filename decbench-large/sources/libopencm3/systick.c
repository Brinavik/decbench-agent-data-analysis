#define LIBOPENCM3_SYSTICK_H 

#define LIBOPENCM3_CM3_MEMORYMAP_H 




#define PPBI_BASE (0xE0000000U)




#define ITM_BASE (PPBI_BASE + 0x0000)


#define DWT_BASE (PPBI_BASE + 0x1000)


#define FPB_BASE (PPBI_BASE + 0x2000)




#define SCS_BASE (PPBI_BASE + 0xE000)





#define TPIU_BASE (PPBI_BASE + 0x40000)







#define ITR_BASE (SCS_BASE + 0x0000)



#define SYS_TICK_BASE (SCS_BASE + 0x0010)


#define NVIC_BASE (SCS_BASE + 0x0100)


#define SCB_BASE (SCS_BASE + 0x0D00)


#define MPU_BASE (SCS_BASE + 0x0D90)
#define STIR_BASE (SCS_BASE + 0x0F00)

#define ID_BASE (SCS_BASE + 0x0FD0)
#define CORESIGHT_LSR_OFFSET 0xfb4
#define CORESIGHT_LAR_OFFSET 0xfb0


#define CORESIGHT_LSR_SLK (1<<1)

#define CORESIGHT_LSR_SLI (1<<0)

#define CORESIGHT_LAR_KEY 0xC5ACCE55
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






#define STK_CSR MMIO32(SYS_TICK_BASE + 0x00)
#define STK_RVR MMIO32(SYS_TICK_BASE + 0x04)






#define STK_CVR MMIO32(SYS_TICK_BASE + 0x08)






#define STK_CALIB MMIO32(SYS_TICK_BASE + 0x0C)
#define STK_CSR_COUNTFLAG (1 << 16)

#define STK_CSR_CLKSOURCE_LSB 2





#define STK_CSR_CLKSOURCE (1 << STK_CSR_CLKSOURCE_LSB)
#define STK_CSR_CLKSOURCE_AHB_DIV8 (0 << STK_CSR_CLKSOURCE_LSB)
#define STK_CSR_CLKSOURCE_AHB (1 << STK_CSR_CLKSOURCE_LSB)




#define STK_CSR_TICKINT (1 << 1)

#define STK_CSR_ENABLE (1 << 0)






#define STK_RVR_RELOAD 0x00FFFFFF
#define STK_CVR_CURRENT 0x00FFFFFF
#define STK_CALIB_NOREF (1 << 31)






#define STK_CALIB_SKEW (1 << 30)







#define STK_CALIB_TENMS 0x00FFFFFF







void systick_set_reload(uint32_t value);

_Bool 
    systick_set_frequency(uint32_t freq, uint32_t ahb);
uint32_t systick_get_reload(void);
uint32_t systick_get_value(void);
void systick_set_clocksource(uint8_t clocksource);
void systick_interrupt_enable(void);
void systick_interrupt_disable(void);
void systick_counter_enable(void);
void systick_counter_disable(void);
uint8_t systick_get_countflag(void);
void systick_clear(void);

uint32_t systick_get_calib(void);


void systick_set_reload(uint32_t value)
{
 (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0010) + 0x04)) = (value & 0x00FFFFFF);
}







uint32_t systick_get_reload(void)
{
 return (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0010) + 0x04)) & 0x00FFFFFF;
}

_Bool 
    systick_set_frequency(uint32_t freq, uint32_t ahb)
{
 uint32_t ratio = ahb / freq;




 if (ratio >= (0x00FFFFFF * 8)) {

  return 
        0
             ;
 } else if (ratio >= 0x00FFFFFF) {
  ratio /= 8;
  systick_set_clocksource((0 << 2));
 } else {
  systick_set_clocksource((1 << 2));
 }

 systick_set_reload(ratio - 1);
 return 
       1
           ;
}







uint32_t systick_get_value(void)
{
 return (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0010) + 0x08)) & 0x00FFFFFF;
}
void systick_set_clocksource(uint8_t clocksource)
{
 (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0010) + 0x00)) = ((*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0010) + 0x00)) & ~(1 << 2)) |
    (clocksource & (1 << 2));
}






void systick_interrupt_enable(void)
{
 (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0010) + 0x00)) |= (1 << 1);
}






void systick_interrupt_disable(void)
{
 (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0010) + 0x00)) &= ~(1 << 1);
}






void systick_counter_enable(void)
{
 (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0010) + 0x00)) |= (1 << 0);
}






void systick_counter_disable(void)
{
 (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0010) + 0x00)) &= ~(1 << 0);
}
uint8_t systick_get_countflag(void)
{
 return ((*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0010) + 0x00)) & (1 << 16)) ? 1 : 0;
}







void systick_clear(void)
{
 (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0010) + 0x08)) = 0;
}






uint32_t systick_get_calib(void)
{
 return (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0010) + 0x0C)) & 0x00FFFFFF;
}
