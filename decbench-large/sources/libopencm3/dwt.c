#define LIBOPENCM3_CM3_SCS_H 
#define SCS_DHCSR MMIO32(SCS_BASE + 0xDF0)
#define SCS_DCRSR MMIO32(SCS_BASE + 0xDF4)
#define SCS_DCRDR MMIO32(SCS_BASE + 0xDF8)
#define SCS_DEMCR MMIO32(SCS_BASE + 0xDFC)




#define SCS_DHCSR_DBGKEY 0xA05F0000
#define SCS_DHCSR_C_DEBUGEN 0x00000001
#define SCS_DHCSR_C_HALT 0x00000002
#define SCS_DHCSR_C_STEP 0x00000004
#define SCS_DHCSR_C_MASKINTS 0x00000008
#define SCS_DHCSR_C_SNAPSTALL 0x00000020
#define SCS_DHCSR_S_REGRDY 0x00010000
#define SCS_DHCSR_S_HALT 0x00020000
#define SCS_DHCSR_S_SLEEP 0x00040000
#define SCS_DHCSR_S_LOCKUP 0x00080000
#define SCS_DHCSR_S_RETIRE_ST 0x01000000
#define SCS_DHCSR_S_RESET_ST 0x02000000


#define SCS_DCRSR_REGSEL_MASK 0x0000001F
#define SCS_DCRSR_REGSEL_XPSR 0x00000010
#define SCS_DCRSR_REGSEL_MSP 0x00000011
#define SCS_DCRSR_REGSEL_PSP 0x00000012



#define SCS_DEMCR_TRCENA (1 << 24)

#define SCS_DEMCR_MON_REQ (1 << 19)
#define SCS_DEMCR_MON_STEP (1 << 18)
#define SCS_DEMCR_VC_MON_PEND (1 << 17)
#define SCS_DEMCR_VC_MON_EN (1 << 16)

#define SCS_DEMCR_VC_HARDERR (1 << 10)
#define SCS_DEMCR_VC_INTERR (1 << 9)
#define SCS_DEMCR_VC_BUSERR (1 << 8)
#define SCS_DEMCR_VC_STATERR (1 << 7)
#define SCS_DEMCR_VC_CHKERR (1 << 6)
#define SCS_DEMCR_VC_NOCPERR (1 << 5)
#define SCS_DEMCR_VC_MMERR (1 << 4)

#define SCS_DEMCR_VC_CORERESET (1 << 0)


#define SCS_DWT_LSR MMIO32(SCS_DWT_BASE + 0xFB4)

#define SCS_DWT_LAR MMIO32(SCS_DWT_BASE + 0xFB0)
#define LIBOPENCM3_CM3_DWT_H 

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
#define DWT_CTRL MMIO32(DWT_BASE + 0x00)
#define DWT_CYCCNT MMIO32(DWT_BASE + 0x04)
#define DWT_CPICNT MMIO32(DWT_BASE + 0x08)
#define DWT_EXCCNT MMIO32(DWT_BASE + 0x0C)
#define DWT_SLEEPCNT MMIO32(DWT_BASE + 0x10)
#define DWT_LSUCNT MMIO32(DWT_BASE + 0x14)
#define DWT_FOLDCNT MMIO32(DWT_BASE + 0x18)



#define DWT_PCSR MMIO32(DWT_BASE + 0x1C)
#define DWT_COMP(n) MMIO32(DWT_BASE + 0x20 + (n) * 16)
#define DWT_MASK(n) MMIO32(DWT_BASE + 0x24 + (n) * 16)
#define DWT_FUNCTION(n) MMIO32(DWT_BASE + 0x28 + (n) * 16)


#define DWT_LSR MMIO32(DWT_BASE + CORESIGHT_LSR_OFFSET)

#define DWT_LAR MMIO32(DWT_BASE + CORESIGHT_LAR_OFFSET)
#define DWT_CTRL_NUMCOMP_SHIFT 28
#define DWT_CTRL_NUMCOMP (0x0F << DWT_CTRL_NUMCOMP_SHIFT)




#define DWT_CTRL_NOTRCPKT (1 << 27)
#define DWT_CTRL_NOEXTTRIG (1 << 26)
#define DWT_CTRL_NOCYCCNT (1 << 25)
#define DWT_CTRL_NOPRFCCNT (1 << 24)

#define DWT_CTRL_CYCEVTENA (1 << 22)
#define DWT_CTRL_FOLDEVTENA (1 << 21)
#define DWT_CTRL_LSUEVTENA (1 << 20)
#define DWT_CTRL_SLEEPEVTENA (1 << 19)
#define DWT_CTRL_EXCEVTENA (1 << 18)
#define DWT_CTRL_CPIEVTENA (1 << 17)
#define DWT_CTRL_EXCTRCENA (1 << 16)
#define DWT_CTRL_PCSAMPLENA (1 << 12)

#define DWT_CTRL_SYNCTAP_SHIFT 10
#define DWT_CTRL_SYNCTAP (3 << DWT_CTRL_SYNCTAP_SHIFT)
#define DWT_CTRL_SYNCTAP_DISABLED (0 << DWT_CTRL_SYNCTAP_SHIFT)
#define DWT_CTRL_SYNCTAP_BIT24 (1 << DWT_CTRL_SYNCTAP_SHIFT)
#define DWT_CTRL_SYNCTAP_BIT26 (2 << DWT_CTRL_SYNCTAP_SHIFT)
#define DWT_CTRL_SYNCTAP_BIT28 (3 << DWT_CTRL_SYNCTAP_SHIFT)

#define DWT_CTRL_CYCTAP (1 << 9)

#define DWT_CTRL_POSTCNT_SHIFT 5
#define DWT_CTRL_POSTCNT (0x0F << DWT_CTRL_POSTCNT_SHIFT)

#define DWT_CTRL_POSTPRESET_SHIFT 1
#define DWT_CTRL_POSTPRESET (0x0F << DWT_CTRL_POSTPRESET_SHIFT)






#define DWT_CTRL_CYCCNTENA (1 << 0)





#define DWT_MASKx_MASK 0x0F



#define DWT_FUNCTIONx_MATCHED (1 << 24)




#define DWT_FUNCTIONx_DATAVADDR1_SHIFT 16
#define DWT_FUNCTIONx_DATAVADDR1 (15 << DWT_FUNCTIONx_DATAVADDR1_SHIFT)

#define DWT_FUNCTIONx_DATAVADDR0_SHIFT 12
#define DWT_FUNCTIONx_DATAVADDR0 (15 << DWT_FUNCTIONx_DATAVADDR0_SHIFT)

#define DWT_FUNCTIONx_DATAVSIZE_SHIFT 10
#define DWT_FUNCTIONx_DATAVSIZE (3 << DWT_FUNCTIONx_DATAVSIZE_SHIFT)
#define DWT_FUNCTIONx_DATAVSIZE_BYTE (0 << DWT_FUNCTIONx_DATAVSIZE_SHIFT)
#define DWT_FUNCTIONx_DATAVSIZE_HALF (1 << DWT_FUNCTIONx_DATAVSIZE_SHIFT)
#define DWT_FUNCTIONx_DATAVSIZE_WORD (2 << DWT_FUNCTIONx_DATAVSIZE_SHIFT)

#define DWT_FUNCTIONx_LNK1ENA (1 << 9)
#define DWT_FUNCTIONx_DATAVMATCH (1 << 8)
#define DWT_FUNCTIONx_CYCMATCH (1 << 7)
#define DWT_FUNCTIONx_EMITRANGE (1 << 5)



#define DWT_FUNCTIONx_FUNCTION 15
#define DWT_FUNCTIONx_FUNCTION_DISABLED 0


_Bool 
    dwt_enable_cycle_counter(void);
uint32_t dwt_read_cycle_counter(void);



_Bool 
    dwt_enable_cycle_counter(void)
{






 (*(volatile uint32_t *)(((0xE0000000U) + 0xE000) + 0xDFC)) |= (1 << 24);
 if ((*(volatile uint32_t *)(((0xE0000000U) + 0x1000) + 0x00)) & (1 << 25)) {
  return 
        0
             ;
 }

 (*(volatile uint32_t *)(((0xE0000000U) + 0x1000) + 0x04)) = 0;
 (*(volatile uint32_t *)(((0xE0000000U) + 0x1000) + 0x00)) |= (1 << 0);
 return 
       1
           ;



 return 
       0
            ;
}
uint32_t dwt_read_cycle_counter(void)
{





 if ((*(volatile uint32_t *)(((0xE0000000U) + 0x1000) + 0x00)) & (1 << 0)) {
  return (*(volatile uint32_t *)(((0xE0000000U) + 0x1000) + 0x04));
 } else {
  return 0;
 }

}
