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
#define LIBOPENCM3_MEMORYMAP_COMMON_H 
#define LIBOPENCM3_MEMORYMAP_H 

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




#define FLASH_BASE (0x08000000U)
#define PERIPH_BASE (0x40000000U)
#define PERIPH_BASE_APB1 (PERIPH_BASE + 0x00000)
#define PERIPH_BASE_APB2 (PERIPH_BASE + 0x10000)
#define PERIPH_BASE_AHB1 (PERIPH_BASE + 0x20000)
#define PERIPH_BASE_AHB2 0x50000000U
#define PERIPH_BASE_AHB3 0x60000000U




#define TIM2_BASE (PERIPH_BASE_APB1 + 0x0000)
#define TIM3_BASE (PERIPH_BASE_APB1 + 0x0400)
#define TIM4_BASE (PERIPH_BASE_APB1 + 0x0800)
#define TIM5_BASE (PERIPH_BASE_APB1 + 0x0c00)
#define TIM6_BASE (PERIPH_BASE_APB1 + 0x1000)
#define TIM7_BASE (PERIPH_BASE_APB1 + 0x1400)
#define TIM12_BASE (PERIPH_BASE_APB1 + 0x1800)
#define TIM13_BASE (PERIPH_BASE_APB1 + 0x1c00)
#define TIM14_BASE (PERIPH_BASE_APB1 + 0x2000)
#define LPTIM1_BASE (PERIPH_BASE_APB1 + 0x2400)
#define RTC_BASE (PERIPH_BASE_APB1 + 0x2800)
#define WWDG_BASE (PERIPH_BASE_APB1 + 0x2c00)
#define IWDG_BASE (PERIPH_BASE_APB1 + 0x3000)
#define I2S2_EXT_BASE (PERIPH_BASE_APB1 + 0x3400)
#define SPI2_BASE (PERIPH_BASE_APB1 + 0x3800)
#define SPI3_BASE (PERIPH_BASE_APB1 + 0x3c00)
#define I2S3_EXT_BASE (PERIPH_BASE_APB1 + 0x4000)
#define USART2_BASE (PERIPH_BASE_APB1 + 0x4400)
#define USART3_BASE (PERIPH_BASE_APB1 + 0x4800)
#define UART4_BASE (PERIPH_BASE_APB1 + 0x4c00)
#define UART5_BASE (PERIPH_BASE_APB1 + 0x5000)
#define I2C1_BASE (PERIPH_BASE_APB1 + 0x5400)
#define I2C2_BASE (PERIPH_BASE_APB1 + 0x5800)
#define I2C3_BASE (PERIPH_BASE_APB1 + 0x5C00)
#define FMPI2C1_BASE (PERIPH_BASE_APB1 + 0x6000)
#define BX_CAN1_BASE (PERIPH_BASE_APB1 + 0x6400)
#define BX_CAN2_BASE (PERIPH_BASE_APB1 + 0x6800)

#define POWER_CONTROL_BASE (PERIPH_BASE_APB1 + 0x7000)
#define DAC_BASE (PERIPH_BASE_APB1 + 0x7400)
#define UART7_BASE (PERIPH_BASE_APB1 + 0x7800)
#define UART8_BASE (PERIPH_BASE_APB1 + 0x7c00)



#define TIM1_BASE (PERIPH_BASE_APB2 + 0x0000)
#define TIM8_BASE (PERIPH_BASE_APB2 + 0x0400)

#define USART1_BASE (PERIPH_BASE_APB2 + 0x1000)
#define USART6_BASE (PERIPH_BASE_APB2 + 0x1400)

#define ADC1_BASE (PERIPH_BASE_APB2 + 0x2000)
#define ADC2_BASE (PERIPH_BASE_APB2 + 0x2100)
#define ADC3_BASE (PERIPH_BASE_APB2 + 0x2200)
#define ADC_COMMON_BASE (PERIPH_BASE_APB2 + 0x2300)

#define SDIO_BASE (PERIPH_BASE_APB2 + 0x2C00)

#define SPI1_BASE (PERIPH_BASE_APB2 + 0x3000)
#define SPI4_BASE (PERIPH_BASE_APB2 + 0x3400)

#define SYSCFG_BASE (PERIPH_BASE_APB2 + 0x3800)
#define EXTI_BASE (PERIPH_BASE_APB2 + 0x3C00)
#define TIM9_BASE (PERIPH_BASE_APB2 + 0x4000)
#define TIM10_BASE (PERIPH_BASE_APB2 + 0x4400)
#define TIM11_BASE (PERIPH_BASE_APB2 + 0x4800)

#define SPI5_BASE (PERIPH_BASE_APB2 + 0x5000)
#define SPI6_BASE (PERIPH_BASE_APB2 + 0x5400)
#define SAI1_BASE (PERIPH_BASE_APB2 + 0x5800)
#define LTDC_BASE (PERIPH_BASE_APB2 + 0x6800)
#define DSI_BASE (PERIPH_BASE_APB2 + 0x6C00)



#define GPIO_PORT_A_BASE (PERIPH_BASE_AHB1 + 0x0000)
#define GPIO_PORT_B_BASE (PERIPH_BASE_AHB1 + 0x0400)
#define GPIO_PORT_C_BASE (PERIPH_BASE_AHB1 + 0x0800)
#define GPIO_PORT_D_BASE (PERIPH_BASE_AHB1 + 0x0C00)
#define GPIO_PORT_E_BASE (PERIPH_BASE_AHB1 + 0x1000)
#define GPIO_PORT_F_BASE (PERIPH_BASE_AHB1 + 0x1400)
#define GPIO_PORT_G_BASE (PERIPH_BASE_AHB1 + 0x1800)
#define GPIO_PORT_H_BASE (PERIPH_BASE_AHB1 + 0x1C00)
#define GPIO_PORT_I_BASE (PERIPH_BASE_AHB1 + 0x2000)
#define GPIO_PORT_J_BASE (PERIPH_BASE_AHB1 + 0x2400)
#define GPIO_PORT_K_BASE (PERIPH_BASE_AHB1 + 0x2800)

#define CRC_BASE (PERIPH_BASE_AHB1 + 0x3000)

#define RCC_BASE (PERIPH_BASE_AHB1 + 0x3800)
#define FLASH_MEM_INTERFACE_BASE (PERIPH_BASE_AHB1 + 0x3C00)
#define BKPSRAM_BASE (PERIPH_BASE_AHB1 + 0x4000)

#define DMA1_BASE (PERIPH_BASE_AHB1 + 0x6000)
#define DMA2_BASE (PERIPH_BASE_AHB1 + 0x6400)

#define ETHERNET_BASE (PERIPH_BASE_AHB1 + 0x8000)
#define DMA2D_BASE (PERIPH_BASE_AHB1 + 0xB000U)

#define USB_OTG_HS_BASE (PERIPH_BASE_AHB1 + 0x20000)



#define USB_OTG_FS_BASE (PERIPH_BASE_AHB2 + 0x00000)

#define DCMI_BASE (PERIPH_BASE_AHB2 + 0x50000)

#define CRYP_BASE (PERIPH_BASE_AHB2 + 0x60000)
#define HASH_BASE (PERIPH_BASE_AHB2 + 0x60400)

#define RNG_BASE (PERIPH_BASE_AHB2 + 0x60800)




#define FMC_BANK1 (PERIPH_BASE_AHB3)

#define FMC_BANK2 (PERIPH_BASE_AHB3 + 0x10000000U)

#define FMC_BANK3 (PERIPH_BASE_AHB3 + 0x20000000U)

#define QUADSPI_BANK (PERIPH_BASE_AHB3 + 0x30000000U)
#define FSMC_BASE (PERIPH_BASE_AHB3 + 0x40000000U)
#define FMC_BASE (PERIPH_BASE_AHB3 + 0x40000000U)
#define QUADSPI_BASE (PERIPH_BASE_AHB3 + 0x40001000U)

#define FMC_BANK5 (PERIPH_BASE_AHB3 + 0x60000000U)

#define FMC_BANK6 (PERIPH_BASE_AHB3 + 0x70000000U)


#define DBGMCU_BASE (PPBI_BASE + 0x00042000)


#define DESIG_FLASH_SIZE_BASE (0x1FFF7A22U)
#define DESIG_UNIQUE_ID_BASE (0x1FFF7A10U)
#define DESIG_UNIQUE_ID0 MMIO32(DESIG_UNIQUE_ID_BASE)
#define DESIG_UNIQUE_ID1 MMIO32(DESIG_UNIQUE_ID_BASE + 4)
#define DESIG_UNIQUE_ID2 MMIO32(DESIG_UNIQUE_ID_BASE + 8)


#define ST_VREFINT_CAL MMIO16(0x1FFF7A2A)
#define ST_TSENSE_CAL1_30C MMIO16(0x1FFF7A2C)
#define ST_TSENSE_CAL2_110C MMIO16(0x1FFF7A2E)


#define LIBOPENCM3_LPTIMER_H 


#define LIBOPENCM3_LPTIMER_COMMON_H 



#define LPTIM_ISR(tim_base) MMIO32((tim_base) + 0x00)
#define LPTIM_ICR(tim_base) MMIO32((tim_base) + 0x04)
#define LPTIM_IER(tim_base) MMIO32((tim_base) + 0x08)
#define LPTIM_CFGR(tim_base) MMIO32((tim_base) + 0x0C)
#define LPTIM_CR(tim_base) MMIO32((tim_base) + 0x10)
#define LPTIM_CMP(tim_base) MMIO32((tim_base) + 0x14)
#define LPTIM_ARR(tim_base) MMIO32((tim_base) + 0x18)
#define LPTIM_CNT(tim_base) MMIO32((tim_base) + 0x1C)

#define LPTIM1_ISR LPTIM_ISR(LPTIM1_BASE)
#define LPTIM1_ICR LPTIM_ICR(LPTIM1_BASE)
#define LPTIM1_IER LPTIM_IER(LPTIM1_BASE)
#define LPTIM1_CFGR LPTIM_CFGR(LPTIM1_BASE)
#define LPTIM1_CR LPTIM_CR(LPTIM1_BASE)
#define LPTIM1_CMP LPTIM_CMP(LPTIM1_BASE)
#define LPTIM1_ARR LPTIM_ARR(LPTIM1_BASE)
#define LPTIM1_CNT LPTIM_CNT(LPTIM1_BASE)
#define LPTIM_ISR_CMPM (1 << 0)


#define LPTIM_ISR_ARRM (1 << 1)


#define LPTIM_ISR_EXTTRIG (1 << 2)


#define LPTIM_ISR_CMPOK (1 << 3)


#define LPTIM_ISR_ARROK (1 << 4)


#define LPTIM_ISR_UP (1 << 5)


#define LPTIM_ISR_DOWN (1 << 6)







#define LPTIM_ICR_CMPMCF (1 << 0)


#define LPTIM_ICR_ARRMCF (1 << 1)


#define LPTIM_ICR_EXTTRIGCF (1 << 2)


#define LPTIM_ICR_CMPOKCF (1 << 3)


#define LPTIM_ICR_ARROKCF (1 << 4)


#define LPTIM_ICR_UPCF (1 << 5)


#define LPTIM_ICR_DOWNCF (1 << 6)







#define LPTIM_IER_CMPMIE (1 << 0)


#define LPTIM_IER_ARRMIE (1 << 1)


#define LPTIM_IER_EXTTRIGIE (1 << 2)


#define LPTIM_IER_CMPOKIE (1 << 3)


#define LPTIM_IER_ARROKIE (1 << 4)


#define LPTIM_IER_UPIE (1 << 5)


#define LPTIM_IER_DOWNIE (1 << 6)







#define LPTIM_CFGR_CKSEL (1 << 0)

#define LPTIM_CFGR_CKPOL_SHIFT 1
#define LPTIM_CFGR_CKPOL_MASK 0x03
#define LPTIM_CFGR_CKPOL (3 << LPTIM_CFGR_CKPOL_SHIFT)


#define LPTIM_CFGR_CKPOL_RISING (0 << LPTIM_CFGR_CKPOL_SHIFT)
#define LPTIM_CFGR_CKPOL_FALLING (1 << LPTIM_CFGR_CKPOL_SHIFT)
#define LPTIM_CFGR_CKPOL_BOTH (2 << LPTIM_CFGR_CKPOL_SHIFT)
#define LPTIM_CFGR_CKPOL_ENC_1 (0 << LPTIM_CFGR_CKPOL_SHIFT)
#define LPTIM_CFGR_CKPOL_ENC_2 (1 << LPTIM_CFGR_CKPOL_SHIFT)
#define LPTIM_CFGR_CKPOL_ENC_3 (2 << LPTIM_CFGR_CKPOL_SHIFT)


#define LPTIM_CFGR_CKFLT_SHIFT 3
#define LPTIM_CFGR_CKFLT_MASK 0x03
#define LPTIM_CFGR_CKFLT (3 << LPTIM_CFGR_CKFLT_SHIFT)


#define LPTIM_CFGR_CKFLT_2 (1 << LPTIM_CFGR_CKFLT_SHIFT)
#define LPTIM_CFGR_CKFLT_4 (2 << LPTIM_CFGR_CKFLT_SHIFT)
#define LPTIM_CFGR_CKFLT_8 (3 << LPTIM_CFGR_CKFLT_SHIFT)


#define LPTIM_CFGR_TRGFLT_SHIFT 6
#define LPTIM_CFGR_TRGFLT_MASK 0x03
#define LPTIM_CFGR_TRGFLT (3 << LPTIM_CFGR_TRGFLT_SHIFT)


#define LPTIM_CFGR_TRGFLT_2 (1 << LPTIM_CFGR_TRGFLT_SHIFT)
#define LPTIM_CFGR_TRGFLT_4 (2 << LPTIM_CFGR_TRGFLT_SHIFT)
#define LPTIM_CFGR_TRGFLT_8 (3 << LPTIM_CFGR_TRGFLT_SHIFT)


#define LPTIM_CFGR_PRESC_SHIFT 9
#define LPTIM_CFGR_PRESC_MASK 0x07
#define LPTIM_CFGR_PRESC (7 << LPTIM_CFGR_PRESC_SHIFT)


#define LPTIM_CFGR_PRESC_1 (0 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_2 (1 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_4 (2 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_8 (3 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_16 (4 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_32 (5 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_64 (6 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_128 (7 << LPTIM_CFGR_PRESC_SHIFT)


#define LPTIM_CFGR_TRIGSEL_SHIFT 13
#define LPTIM_CFGR_TRIGSEL_MASK 0x07
#define LPTIM_CFGR_TRIGSEL (7 << LPTIM_CFGR_TRIGSEL_SHIFT)


#define LPTIM_CFGR_TRIGSEL_EXT_TRIG0 (0 << LPTIM_CFGR_TRIGSEL_SHIFT)
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG1 (1 << LPTIM_CFGR_TRIGSEL_SHIFT)
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG2 (2 << LPTIM_CFGR_TRIGSEL_SHIFT)
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG3 (3 << LPTIM_CFGR_TRIGSEL_SHIFT)
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG4 (4 << LPTIM_CFGR_TRIGSEL_SHIFT)

#define LPTIM_CFGR_TRIGSEL_EXT_TRIG6 (6 << LPTIM_CFGR_TRIGSEL_SHIFT)
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG7 (7 << LPTIM_CFGR_TRIGSEL_SHIFT)


#define LPTIM_CFGR_TRIGEN_SHIFT 17
#define LPTIM_CFGR_TRIGEN_MASK 0x07
#define LPTIM_CFGR_TRIGEN (3 << LPTIM_CFGR_TRIGEN_SHIFT)


#define LPTIM_CFGR_TRIGEN_SW (0 << LPTIM_CFGR_TRIGEN_SHIFT)
#define LPTIM_CFGR_TRIGEN_RISING (1 << LPTIM_CFGR_TRIGEN_SHIFT)
#define LPTIM_CFGR_TRIGEN_FALLING (2 << LPTIM_CFGR_TRIGEN_SHIFT)
#define LPTIM_CFGR_TRIGEN_BOTH (3 << LPTIM_CFGR_TRIGEN_SHIFT)



#define LPTIM_CFGR_TIMOUT (1 << 19)


#define LPTIM_CFGR_WAVE (1 << 20)


#define LPTIM_CFGR_WAVPOL (1 << 21)


#define LPTIM_CFGR_PRELOAD (1 << 22)


#define LPTIM_CFGR_COUNTMODE (1 << 23)


#define LPTIM_CFGR_ENC (1 << 24)







#define LPTIM_CR_ENABLE (1 << 0)


#define LPTIM_CR_SNGSTRT (1 << 1)


#define LPTIM_CR_CNTSTRT (1 << 2)








void lptimer_enable(uint32_t timer_peripheral);
void lptimer_disable(uint32_t timer_peripheral);

void lptimer_start_counter(uint32_t timer_peripheral, uint32_t mode);
void lptimer_set_counter(uint32_t timer_peripheral, uint16_t count);
uint16_t lptimer_get_counter(uint32_t timer_peripheral);
void lptimer_set_compare(uint32_t timer_peripheral, uint16_t compare_value);
void lptimer_set_period(uint32_t lptimer_peripheral, uint16_t period_value);
void lptimer_enable_preload(uint32_t lptimer_peripheral);
void lptimer_disable_preload(uint32_t lptimer_peripheral);
void lptimer_set_waveform_polarity_high(uint32_t lptimer_peripheral);
void lptimer_set_waveform_polarity_low(uint32_t lptimer_peripheral);

void lptimer_set_prescaler(uint32_t timer_peripheral, uint32_t prescaler);
void lptimer_enable_trigger(uint32_t lptimer_peripheral, uint32_t trigen);
void lptimer_select_trigger_source(uint32_t lptimer_peripheral, uint32_t trigger_source);
void lptimer_set_internal_clock_source(uint32_t timer_peripheral);
void lptimer_set_external_clock_source(uint32_t timer_peripheral);

void lptimer_clear_flag(uint32_t timer_peripheral, uint32_t flag);

_Bool 
    lptimer_get_flag(uint32_t timer_peripheral, uint32_t flag);
void lptimer_enable_irq(uint32_t timer_peripheral, uint32_t irq);
void lptimer_disable_irq(uint32_t timer_peripheral, uint32_t irq);






#define LPTIM1 LPTIM1_BASE





void lptimer_set_counter(uint32_t lptimer_peripheral, uint16_t count)
{
 (*(volatile uint32_t *)((lptimer_peripheral) + 0x1C)) = count;
}
uint16_t lptimer_get_counter(uint32_t lptimer_peripheral)
{
 return (*(volatile uint32_t *)((lptimer_peripheral) + 0x1C));
}






void lptimer_clear_flag(uint32_t lptimer_peripheral, uint32_t flag)
{
 (*(volatile uint32_t *)((lptimer_peripheral) + 0x04)) = flag;
}








_Bool 
    lptimer_get_flag(uint32_t lptimer_peripheral, uint32_t flag)
{
 return ((*(volatile uint32_t *)((lptimer_peripheral) + 0x00)) & flag);
}







void lptimer_enable_irq(uint32_t lptimer_peripheral, uint32_t irq)
{
 (*(volatile uint32_t *)((lptimer_peripheral) + 0x08)) |= irq;
}







void lptimer_disable_irq(uint32_t lptimer_peripheral, uint32_t irq)
{
 (*(volatile uint32_t *)((lptimer_peripheral) + 0x08)) &= ~irq;
}





void lptimer_enable(uint32_t lptimer_peripheral)
{
 (*(volatile uint32_t *)((lptimer_peripheral) + 0x10)) |= (1 << 0);
}





void lptimer_disable(uint32_t lptimer_peripheral)
{
 (*(volatile uint32_t *)((lptimer_peripheral) + 0x10)) &= ~(1 << 0);
}
void lptimer_start_counter(uint32_t lptimer_peripheral, uint32_t mode)
{
 (*(volatile uint32_t *)((lptimer_peripheral) + 0x10)) |= mode;
}






void lptimer_set_prescaler(uint32_t lptimer_peripheral, uint32_t prescaler)
{
 uint32_t reg32 = (*(volatile uint32_t *)((lptimer_peripheral) + 0x0C));
 reg32 &= ~(0x07 << 9);
 (*(volatile uint32_t *)((lptimer_peripheral) + 0x0C)) = reg32 | prescaler;
}






void lptimer_enable_trigger(uint32_t lptimer_peripheral, uint32_t trigen)
{
 uint32_t reg32 = (*(volatile uint32_t *)((lptimer_peripheral) + 0x0C));
 reg32 &= ~(0x07 << 17);
 (*(volatile uint32_t *)((lptimer_peripheral) + 0x0C)) = reg32 | trigen;
}
void lptimer_select_trigger_source(uint32_t lptimer_peripheral, uint32_t trigger_source)
{
 uint32_t reg32 = (*(volatile uint32_t *)((lptimer_peripheral) + 0x0C));
 reg32 &= ~(0x07 << 13);
 (*(volatile uint32_t *)((lptimer_peripheral) + 0x0C)) = reg32 | trigger_source;
}
void lptimer_set_compare(uint32_t lptimer_peripheral, uint16_t compare_value)
{
 (*(volatile uint32_t *)((lptimer_peripheral) + 0x14)) = compare_value;
}
void lptimer_set_period(uint32_t lptimer_peripheral, uint16_t period_value)
{
 (*(volatile uint32_t *)((lptimer_peripheral) + 0x18)) = period_value;
}
void lptimer_enable_preload(uint32_t lptimer_peripheral)
{
 (*(volatile uint32_t *)((lptimer_peripheral) + 0x0C)) |= (1 << 22);
}
void lptimer_disable_preload(uint32_t lptimer_peripheral)
{
 (*(volatile uint32_t *)((lptimer_peripheral) + 0x0C)) &= ~(1 << 22);
}






void lptimer_set_internal_clock_source(uint32_t lptimer_peripheral)
{
 (*(volatile uint32_t *)((lptimer_peripheral) + 0x0C)) &= ~(1 << 0);
}





void lptimer_set_external_clock_source(uint32_t lptimer_peripheral)
{
 (*(volatile uint32_t *)((lptimer_peripheral) + 0x0C)) |= (1 << 0);
}
void lptimer_set_waveform_polarity_high(uint32_t lptimer_peripheral)
{
 (*(volatile uint32_t *)((lptimer_peripheral) + 0x0C)) |= (1 << 21);
}
void lptimer_set_waveform_polarity_low(uint32_t lptimer_peripheral)
{
 (*(volatile uint32_t *)((lptimer_peripheral) + 0x0C)) &= ~(1 << 21);
}
