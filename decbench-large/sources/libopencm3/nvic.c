#define LIBOPENCM3_NVIC_H 

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
#define NVIC_ISER(iser_id) MMIO32(NVIC_BASE + 0x00 + ((iser_id) * 4))
#define NVIC_ICER(icer_id) MMIO32(NVIC_BASE + 0x80 + ((icer_id) * 4))
#define NVIC_ISPR(ispr_id) MMIO32(NVIC_BASE + 0x100 + ((ispr_id) * 4))
#define NVIC_ICPR(icpr_id) MMIO32(NVIC_BASE + 0x180 + ((icpr_id) * 4))
#define NVIC_IABR(iabr_id) MMIO32(NVIC_BASE + 0x200 + ((iabr_id) * 4))
#define NVIC_IPR(ipr_id) MMIO8(NVIC_BASE + 0x300 + (ipr_id))





#define NVIC_STIR MMIO32(STIR_BASE)
#define NVIC_NMI_IRQ -14
#define NVIC_HARD_FAULT_IRQ -13



#define NVIC_MEM_MANAGE_IRQ -12
#define NVIC_BUS_FAULT_IRQ -11
#define NVIC_USAGE_FAULT_IRQ -10



#define NVIC_SV_CALL_IRQ -5



#define DEBUG_MONITOR_IRQ -4



#define NVIC_PENDSV_IRQ -2
#define NVIC_SYSTICK_IRQ -1












#define LIBOPENCM3_STM32_F4_NVIC_H 







#define NVIC_NVIC_WWDG_IRQ 0
#define NVIC_PVD_IRQ 1
#define NVIC_TAMP_STAMP_IRQ 2
#define NVIC_RTC_WKUP_IRQ 3
#define NVIC_FLASH_IRQ 4
#define NVIC_RCC_IRQ 5
#define NVIC_EXTI0_IRQ 6
#define NVIC_EXTI1_IRQ 7
#define NVIC_EXTI2_IRQ 8
#define NVIC_EXTI3_IRQ 9
#define NVIC_EXTI4_IRQ 10
#define NVIC_DMA1_STREAM0_IRQ 11
#define NVIC_DMA1_STREAM1_IRQ 12
#define NVIC_DMA1_STREAM2_IRQ 13
#define NVIC_DMA1_STREAM3_IRQ 14
#define NVIC_DMA1_STREAM4_IRQ 15
#define NVIC_DMA1_STREAM5_IRQ 16
#define NVIC_DMA1_STREAM6_IRQ 17
#define NVIC_ADC_IRQ 18
#define NVIC_CAN1_TX_IRQ 19
#define NVIC_CAN1_RX0_IRQ 20
#define NVIC_CAN1_RX1_IRQ 21
#define NVIC_CAN1_SCE_IRQ 22
#define NVIC_EXTI9_5_IRQ 23
#define NVIC_TIM1_BRK_TIM9_IRQ 24
#define NVIC_TIM1_UP_TIM10_IRQ 25
#define NVIC_TIM1_TRG_COM_TIM11_IRQ 26
#define NVIC_TIM1_CC_IRQ 27
#define NVIC_TIM2_IRQ 28
#define NVIC_TIM3_IRQ 29
#define NVIC_TIM4_IRQ 30
#define NVIC_I2C1_EV_IRQ 31
#define NVIC_I2C1_ER_IRQ 32
#define NVIC_I2C2_EV_IRQ 33
#define NVIC_I2C2_ER_IRQ 34
#define NVIC_SPI1_IRQ 35
#define NVIC_SPI2_IRQ 36
#define NVIC_USART1_IRQ 37
#define NVIC_USART2_IRQ 38
#define NVIC_USART3_IRQ 39
#define NVIC_EXTI15_10_IRQ 40
#define NVIC_RTC_ALARM_IRQ 41
#define NVIC_USB_FS_WKUP_IRQ 42
#define NVIC_TIM8_BRK_TIM12_IRQ 43
#define NVIC_TIM8_UP_TIM13_IRQ 44
#define NVIC_TIM8_TRG_COM_TIM14_IRQ 45
#define NVIC_TIM8_CC_IRQ 46
#define NVIC_DMA1_STREAM7_IRQ 47
#define NVIC_FSMC_IRQ 48
#define NVIC_SDIO_IRQ 49
#define NVIC_TIM5_IRQ 50
#define NVIC_SPI3_IRQ 51
#define NVIC_UART4_IRQ 52
#define NVIC_UART5_IRQ 53
#define NVIC_TIM6_DAC_IRQ 54
#define NVIC_TIM7_IRQ 55
#define NVIC_DMA2_STREAM0_IRQ 56
#define NVIC_DMA2_STREAM1_IRQ 57
#define NVIC_DMA2_STREAM2_IRQ 58
#define NVIC_DMA2_STREAM3_IRQ 59
#define NVIC_DMA2_STREAM4_IRQ 60
#define NVIC_ETH_IRQ 61
#define NVIC_ETH_WKUP_IRQ 62
#define NVIC_CAN2_TX_IRQ 63
#define NVIC_CAN2_RX0_IRQ 64
#define NVIC_CAN2_RX1_IRQ 65
#define NVIC_CAN2_SCE_IRQ 66
#define NVIC_OTG_FS_IRQ 67
#define NVIC_DMA2_STREAM5_IRQ 68
#define NVIC_DMA2_STREAM6_IRQ 69
#define NVIC_DMA2_STREAM7_IRQ 70
#define NVIC_USART6_IRQ 71
#define NVIC_I2C3_EV_IRQ 72
#define NVIC_I2C3_ER_IRQ 73
#define NVIC_OTG_HS_EP1_OUT_IRQ 74
#define NVIC_OTG_HS_EP1_IN_IRQ 75
#define NVIC_OTG_HS_WKUP_IRQ 76
#define NVIC_OTG_HS_IRQ 77
#define NVIC_DCMI_IRQ 78
#define NVIC_CRYP_IRQ 79
#define NVIC_HASH_RNG_IRQ 80
#define NVIC_FPU_IRQ 81
#define NVIC_UART7_IRQ 82
#define NVIC_UART8_IRQ 83
#define NVIC_SPI4_IRQ 84
#define NVIC_SPI5_IRQ 85
#define NVIC_SPI6_IRQ 86
#define NVIC_SAI1_IRQ 87
#define NVIC_LCD_TFT_IRQ 88
#define NVIC_LCD_TFT_ERR_IRQ 89
#define NVIC_DMA2D_IRQ 90

#define NVIC_IRQ_COUNT 91



void nvic_wwdg_isr(void);
void pvd_isr(void);
void tamp_stamp_isr(void);
void rtc_wkup_isr(void);
void flash_isr(void);
void rcc_isr(void);
void exti0_isr(void);
void exti1_isr(void);
void exti2_isr(void);
void exti3_isr(void);
void exti4_isr(void);
void dma1_stream0_isr(void);
void dma1_stream1_isr(void);
void dma1_stream2_isr(void);
void dma1_stream3_isr(void);
void dma1_stream4_isr(void);
void dma1_stream5_isr(void);
void dma1_stream6_isr(void);
void adc_isr(void);
void can1_tx_isr(void);
void can1_rx0_isr(void);
void can1_rx1_isr(void);
void can1_sce_isr(void);
void exti9_5_isr(void);
void tim1_brk_tim9_isr(void);
void tim1_up_tim10_isr(void);
void tim1_trg_com_tim11_isr(void);
void tim1_cc_isr(void);
void tim2_isr(void);
void tim3_isr(void);
void tim4_isr(void);
void i2c1_ev_isr(void);
void i2c1_er_isr(void);
void i2c2_ev_isr(void);
void i2c2_er_isr(void);
void spi1_isr(void);
void spi2_isr(void);
void usart1_isr(void);
void usart2_isr(void);
void usart3_isr(void);
void exti15_10_isr(void);
void rtc_alarm_isr(void);
void usb_fs_wkup_isr(void);
void tim8_brk_tim12_isr(void);
void tim8_up_tim13_isr(void);
void tim8_trg_com_tim14_isr(void);
void tim8_cc_isr(void);
void dma1_stream7_isr(void);
void fsmc_isr(void);
void sdio_isr(void);
void tim5_isr(void);
void spi3_isr(void);
void uart4_isr(void);
void uart5_isr(void);
void tim6_dac_isr(void);
void tim7_isr(void);
void dma2_stream0_isr(void);
void dma2_stream1_isr(void);
void dma2_stream2_isr(void);
void dma2_stream3_isr(void);
void dma2_stream4_isr(void);
void eth_isr(void);
void eth_wkup_isr(void);
void can2_tx_isr(void);
void can2_rx0_isr(void);
void can2_rx1_isr(void);
void can2_sce_isr(void);
void otg_fs_isr(void);
void dma2_stream5_isr(void);
void dma2_stream6_isr(void);
void dma2_stream7_isr(void);
void usart6_isr(void);
void i2c3_ev_isr(void);
void i2c3_er_isr(void);
void otg_hs_ep1_out_isr(void);
void otg_hs_ep1_in_isr(void);
void otg_hs_wkup_isr(void);
void otg_hs_isr(void);
void dcmi_isr(void);
void cryp_isr(void);
void hash_rng_isr(void);
void fpu_isr(void);
void uart7_isr(void);
void uart8_isr(void);
void spi4_isr(void);
void spi5_isr(void);
void spi6_isr(void);
void sai1_isr(void);
void lcd_tft_isr(void);
void lcd_tft_err_isr(void);
void dma2d_isr(void);







void nvic_enable_irq(uint8_t irqn);
void nvic_disable_irq(uint8_t irqn);
uint8_t nvic_get_pending_irq(uint8_t irqn);
void nvic_set_pending_irq(uint8_t irqn);
void nvic_clear_pending_irq(uint8_t irqn);
uint8_t nvic_get_irq_enabled(uint8_t irqn);
void nvic_set_priority(uint8_t irqn, uint8_t priority);



uint8_t nvic_get_active_irq(uint8_t irqn);
void nvic_generate_software_interrupt(uint16_t irqn);


void reset_handler(void);
void nmi_handler(void);
void hard_fault_handler(void);
void sv_call_handler(void);
void pend_sv_handler(void);
void sys_tick_handler(void);



void mem_manage_handler(void);
void bus_fault_handler(void);
void usage_fault_handler(void);
void debug_monitor_handler(void);



#define LIBOPENCM3_SCB_H 
#define SCB_CPUID MMIO32(SCB_BASE + 0x00)


#define SCB_ICSR MMIO32(SCB_BASE + 0x04)


#define SCB_VTOR MMIO32(SCB_BASE + 0x08)


#define SCB_AIRCR MMIO32(SCB_BASE + 0x0C)


#define SCB_SCR MMIO32(SCB_BASE + 0x10)


#define SCB_CCR MMIO32(SCB_BASE + 0x14)
#define SCB_SHPR(ipr_id) MMIO8(SCS_BASE + 0xD18 + (ipr_id))



#define SCB_SHCSR MMIO32(SCB_BASE + 0x24)


#define SCB_DFSR MMIO32(SCB_BASE + 0x30)




#define SCB_CFSR MMIO32(SCB_BASE + 0x28)


#define SCB_HFSR MMIO32(SCB_BASE + 0x2C)


#define SCB_MMFAR MMIO32(SCB_BASE + 0x34)


#define SCB_BFAR MMIO32(SCB_BASE + 0x38)


#define SCB_AFSR MMIO32(SCB_BASE + 0x3C)


#define SCB_ID_PFR0 MMIO32(SCB_BASE + 0x40)


#define SCB_ID_PFR1 MMIO32(SCB_BASE + 0x44)


#define SCB_ID_DFR0 MMIO32(SCB_BASE + 0x48)


#define SCB_ID_AFR0 MMIO32(SCB_BASE + 0x4C)


#define SCB_ID_MMFR0 MMIO32(SCB_BASE + 0x50)


#define SCB_ID_MMFR1 MMIO32(SCB_BASE + 0x54)


#define SCB_ID_MMFR2 MMIO32(SCB_BASE + 0x58)


#define SCB_ID_MMFR3 MMIO32(SCB_BASE + 0x5C)


#define SCB_ID_ISAR0 MMIO32(SCB_BASE + 0x60)


#define SCB_ID_ISAR1 MMIO32(SCB_BASE + 0x64)


#define SCB_ID_ISAR2 MMIO32(SCB_BASE + 0x68)


#define SCB_ID_ISAR3 MMIO32(SCB_BASE + 0x6C)


#define SCB_ID_ISAR4 MMIO32(SCB_BASE + 0x70)


#define SCB_CPACR MMIO32(SCB_BASE + 0x88)


#define SCB_FPCCR MMIO32(SCB_BASE + 0x234)


#define SCB_FPCAR MMIO32(SCB_BASE + 0x238)


#define SCB_FPDSCR MMIO32(SCB_BASE + 0x23C)


#define SCB_MVFR0 MMIO32(SCB_BASE + 0x240)


#define SCB_MVFR1 MMIO32(SCB_BASE + 0x244)





#define SCB_CLIDR MMIO32(SCB_BASE + 0x78)


#define SCB_CTR MMIO32(SCB_BASE + 0x7C)


#define SCB_CCSIDR MMIO32(SCB_BASE + 0x80)


#define SCB_CCSELR MMIO32(SCB_BASE + 0x84)


#define SCB_ICIALLU MMIO32(SCB_BASE + 0x250)


#define SCB_ICIMVAU MMIO32(SCB_BASE + 0x258)


#define SCB_DCIMVAC MMIO32(SCB_BASE + 0x25C)


#define SCB_DCISW MMIO32(SCB_BASE + 0x260)


#define SCB_DCCMVAU MMIO32(SCB_BASE + 0x264)


#define SCB_DCCMVAC MMIO32(SCB_BASE + 0x268)


#define SCB_DCCSW MMIO32(SCB_BASE + 0x26C)


#define SCB_DCCIMVAC MMIO32(SCB_BASE + 0x270)


#define SCB_DCCISW MMIO32(SCB_BASE + 0x274)


#define SCB_BPIALL MMIO32(SCB_BASE + 0x278)
#define SCB_CPUID_IMPLEMENTER_LSB 24
#define SCB_CPUID_IMPLEMENTER (0xFF << SCB_CPUID_IMPLEMENTER_LSB)

#define SCB_CPUID_VARIANT_LSB 20
#define SCB_CPUID_VARIANT (0xF << SCB_CPUID_VARIANT_LSB)




#define SCB_CPUID_CONSTANT_LSB 16
#define SCB_CPUID_CONSTANT (0xF << SCB_CPUID_CONSTANT_LSB)
#define SCB_CPUID_CONSTANT_ARMV6 (0xC << SCB_CPUID_CONSTANT_LSB)
#define SCB_CPUID_CONSTANT_ARMV7 (0xF << SCB_CPUID_CONSTANT_LSB)


#define SCB_CPUID_PARTNO_LSB 4
#define SCB_CPUID_PARTNO (0xFFF << SCB_CPUID_PARTNO_LSB)

#define SCB_CPUID_REVISION_LSB 0
#define SCB_CPUID_REVISION (0xF << SCB_CPUID_REVISION_LSB)







#define SCB_ICSR_NMIPENDSET (1 << 31)


#define SCB_ICSR_PENDSVSET (1 << 28)

#define SCB_ICSR_PENDSVCLR (1 << 27)

#define SCB_ICSR_PENDSTSET (1 << 26)

#define SCB_ICSR_PENDSTCLR (1 << 25)


#define SCB_ICSR_ISRPREEMPT (1 << 23)

#define SCB_ICSR_ISRPENDING (1 << 22)

#define SCB_ICSR_VECTPENDING_LSB 12
#define SCB_ICSR_VECTPENDING (0x1FF << SCB_ICSR_VECTPENDING_LSB)

#define SCB_ICSR_RETOBASE (1 << 11)


#define SCB_ICSR_VECTACTIVE_LSB 0
#define SCB_ICSR_VECTACTIVE (0x1FF << SCB_ICSR_VECTACTIVE_LSB)
#define SCB_VTOR_TBLOFF_LSB 9
#define SCB_VTOR_TBLOFF (0x7FFFFF << SCB_VTOR_TBLOFF_LSB)
#define SCB_AIRCR_VECTKEYSTAT_LSB 16
#define SCB_AIRCR_VECTKEYSTAT (0xFFFF << SCB_AIRCR_VECTKEYSTAT_LSB)
#define SCB_AIRCR_VECTKEY (0x05FA << SCB_AIRCR_VECTKEYSTAT_LSB)


#define SCB_AIRCR_ENDIANESS (1 << 15)





#define SCB_AIRCR_PRIGROUP_GROUP16_NOSUB (0x3 << 8)
#define SCB_AIRCR_PRIGROUP_GROUP8_SUB2 (0x4 << 8)
#define SCB_AIRCR_PRIGROUP_GROUP4_SUB4 (0x5 << 8)
#define SCB_AIRCR_PRIGROUP_GROUP2_SUB8 (0x6 << 8)
#define SCB_AIRCR_PRIGROUP_NOGROUP_SUB16 (0x7 << 8)
#define SCB_AIRCR_PRIGROUP_MASK (0x7 << 8)
#define SCB_AIRCR_PRIGROUP_SHIFT 8




#define SCB_AIRCR_SYSRESETREQ (1 << 2)

#define SCB_AIRCR_VECTCLRACTIVE (1 << 1)




#define SCB_AIRCR_VECTRESET (1 << 0)
#define SCB_SCR_SEVONPEND (1 << 4)


#define SCB_SCR_SLEEPDEEP (1 << 2)

#define SCB_SCR_SLEEPONEXIT (1 << 1)
#define SCB_CCR_STKALIGN (1 << 9)




#define SCB_CCR_BFHFNMIGN (1 << 8)


#define SCB_CCR_DIV_0_TRP (1 << 4)



#define SCB_CCR_UNALIGN_TRP (1 << 3)





#define SCB_CCR_USERSETMPEND (1 << 1)

#define SCB_CCR_NONBASETHRDENA (1 << 0)





#define SCB_CCR_BP (1 << 18)

#define SCB_CCR_IC (1 << 17)

#define SCB_CCR_DC (1 << 16)






#define SCB_SHPR_PRI_4_MEMMANAGE 0
#define SCB_SHPR_PRI_5_BUSFAULT 1
#define SCB_SHPR_PRI_6_USAGEFAULT 2
#define SCB_SHPR_PRI_7_RESERVED 3

#define SCB_SHPR_PRI_8_RESERVED 4
#define SCB_SHPR_PRI_9_RESERVED 5
#define SCB_SHPR_PRI_10_RESERVED 6
#define SCB_SHPR_PRI_11_SVCALL 7

#define SCB_SHPR_PRI_12_RESERVED 8
#define SCB_SHPR_PRI_13_RESERVED 9
#define SCB_SHPR_PRI_14_PENDSV 10
#define SCB_SHPR_PRI_15_SYSTICK 11
#define SCB_SHCSR_USGFAULTENA (1 << 18)

#define SCB_SHCSR_BUSFAULTENA (1 << 17)

#define SCB_SHCSR_MEMFAULTENA (1 << 16)



#define SCB_SHCSR_SVCALLPENDED (1 << 15)




#define SCB_SHCSR_BUSFAULTPENDED (1 << 14)

#define SCB_SHCSR_MEMFAULTPENDED (1 << 13)

#define SCB_SHCSR_USGFAULTPENDED (1 << 12)

#define SCB_SHCSR_SYSTICKACT (1 << 11)

#define SCB_SHCSR_PENDSVACT (1 << 10)


#define SCB_SHCSR_MONITORACT (1 << 8)

#define SCB_SHCSR_SVCALLACT (1 << 7)


#define SCB_SHCSR_USGFAULTACT (1 << 3)


#define SCB_SHCSR_BUSFAULTACT (1 << 1)

#define SCB_SHCSR_MEMFAULTACT (1 << 0)





#define SCB_CFSR_DIVBYZERO (1 << 25)

#define SCB_CFSR_UNALIGNED (1 << 24)


#define SCB_CFSR_NOCP (1 << 19)

#define SCB_CFSR_INVPC (1 << 18)

#define SCB_CFSR_INVSTATE (1 << 17)

#define SCB_CFSR_UNDEFINSTR (1 << 16)

#define SCB_CFSR_BFARVALID (1 << 15)


#define SCB_CFSR_STKERR (1 << 12)

#define SCB_CFSR_UNSTKERR (1 << 11)

#define SCB_CFSR_IMPRECISERR (1 << 10)

#define SCB_CFSR_PRECISERR (1 << 9)

#define SCB_CFSR_IBUSERR (1 << 8)

#define SCB_CFSR_MMARVALID (1 << 7)


#define SCB_CFSR_MSTKERR (1 << 4)

#define SCB_CFSR_MUNSTKERR (1 << 3)


#define SCB_CFSR_DACCVIOL (1 << 1)

#define SCB_CFSR_IACCVIOL (1 << 0)




#define SCB_HFSR_DEBUG_VT (1 << 31)

#define SCB_HFSR_FORCED (1 << 30)


#define SCB_HFSR_VECTTBL (1 << 1)
#define SCB_CTR_FORMAT_SHIFT 29
#define SCB_CTR_FORMAT_MASK 0x7

#define SCB_CTR_CWG_SHIFT 24
#define SCB_CTR_CWG_MASK 0xf

#define SCB_CTR_ERG_SHIFT 20
#define SCB_CTR_ERG_MASK 0xf

#define SCB_CTR_DMINLINE_SHIFT 16
#define SCB_CTR_DMINLINE_MASK 0x1f

#define SCB_CTR_IMINLINE_SHIFT 0
#define SCB_CTR_IMINLINE_MASK 0xf






#define SCB_CPACR_NONE 0
#define SCB_CPACR_PRIV 1
#define SCB_CPACR_FULL 3


#define SCB_CPACR_CP10 (1 << 20)

#define SCB_CPACR_CP11 (1 << 22)






struct scb_exception_stack_frame {
 uint32_t r0;
 uint32_t r1;
 uint32_t r2;
 uint32_t r3;
 uint32_t r12;
 uint32_t lr;
 uint32_t pc;
 uint32_t xpsr;
} __attribute__((packed));

#define SCB_GET_EXCEPTION_STACK_FRAME(f) do { __asm__ volatile ("mov %[frameptr], sp" : [frameptr]"=r" (f)); } while (0)





void scb_reset_system(void) __attribute__((noreturn));



void scb_reset_core(void) __attribute__((noreturn));
void scb_set_priority_grouping(uint32_t prigroup);



void nvic_enable_irq(uint8_t irqn)
{
 (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0100) + 0x00 + ((irqn / 32) * 4))) = (1 << (irqn % 32));
}
void nvic_disable_irq(uint8_t irqn)
{
 (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0100) + 0x80 + ((irqn / 32) * 4))) = (1 << (irqn % 32));
}
uint8_t nvic_get_pending_irq(uint8_t irqn)
{
 return (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0100) + 0x100 + ((irqn / 32) * 4))) & (1 << (irqn % 32)) ? 1 : 0;
}
void nvic_set_pending_irq(uint8_t irqn)
{
 (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0100) + 0x100 + ((irqn / 32) * 4))) = (1 << (irqn % 32));
}
void nvic_clear_pending_irq(uint8_t irqn)
{
 (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0100) + 0x180 + ((irqn / 32) * 4))) = (1 << (irqn % 32));
}
uint8_t nvic_get_irq_enabled(uint8_t irqn)
{
 return (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0100) + 0x00 + ((irqn / 32) * 4))) & (1 << (irqn % 32)) ? 1 : 0;
}
void nvic_set_priority(uint8_t irqn, uint8_t priority)
{



 if (irqn >= 91) {
  (*(volatile uint8_t *)(((0xE0000000U) + 0xE000) + 0xD18 + ((irqn & 0xF) - 4))) = priority;

 } else {
  (*(volatile uint8_t *)((((0xE0000000U) + 0xE000) + 0x0100) + 0x300 + (irqn))) = priority;

 }
}
uint8_t nvic_get_active_irq(uint8_t irqn)
{
 return (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0100) + 0x200 + ((irqn / 32) * 4))) & (1 << (irqn % 32)) ? 1 : 0;
}
void nvic_generate_software_interrupt(uint16_t irqn)
{
 if (irqn <= 239) {
  (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0F00))) |= irqn;
 }
}
