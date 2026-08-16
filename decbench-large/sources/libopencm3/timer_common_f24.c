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
       
       
       






#define TIM1 TIM1_BASE
#define TIM2 TIM2_BASE
#define TIM3 TIM3_BASE

#define TIM4 TIM4_BASE

#define TIM5 TIM5_BASE
#define TIM6 TIM6_BASE
#define TIM7 TIM7_BASE

#define TIM8 TIM8_BASE


#define TIM9 TIM9_BASE


#define TIM10 TIM10_BASE


#define TIM11 TIM11_BASE


#define TIM12 TIM12_BASE


#define TIM13 TIM13_BASE


#define TIM14 TIM14_BASE
#define TIM_CR1(tim_base) MMIO32((tim_base) + 0x00)
#define TIM1_CR1 TIM_CR1(TIM1)
#define TIM2_CR1 TIM_CR1(TIM2)
#define TIM3_CR1 TIM_CR1(TIM3)
#define TIM4_CR1 TIM_CR1(TIM4)
#define TIM5_CR1 TIM_CR1(TIM5)
#define TIM6_CR1 TIM_CR1(TIM6)
#define TIM7_CR1 TIM_CR1(TIM7)
#define TIM8_CR1 TIM_CR1(TIM8)
#define TIM9_CR1 TIM_CR1(TIM9)
#define TIM10_CR1 TIM_CR1(TIM10)
#define TIM11_CR1 TIM_CR1(TIM11)
#define TIM12_CR1 TIM_CR1(TIM12)
#define TIM13_CR1 TIM_CR1(TIM13)
#define TIM14_CR1 TIM_CR1(TIM14)
#define TIM15_CR1 TIM_CR1(TIM15)
#define TIM16_CR1 TIM_CR1(TIM16)
#define TIM17_CR1 TIM_CR1(TIM17)


#define TIM_CR2(tim_base) MMIO32((tim_base) + 0x04)
#define TIM1_CR2 TIM_CR2(TIM1)
#define TIM2_CR2 TIM_CR2(TIM2)
#define TIM3_CR2 TIM_CR2(TIM3)
#define TIM4_CR2 TIM_CR2(TIM4)
#define TIM5_CR2 TIM_CR2(TIM5)
#define TIM6_CR2 TIM_CR2(TIM6)
#define TIM7_CR2 TIM_CR2(TIM7)
#define TIM8_CR2 TIM_CR2(TIM8)
#define TIM15_CR2 TIM_CR2(TIM15)
#define TIM16_CR2 TIM_CR2(TIM16)
#define TIM17_CR2 TIM_CR2(TIM17)


#define TIM_SMCR(tim_base) MMIO32((tim_base) + 0x08)
#define TIM1_SMCR TIM_SMCR(TIM1)
#define TIM2_SMCR TIM_SMCR(TIM2)
#define TIM3_SMCR TIM_SMCR(TIM3)
#define TIM4_SMCR TIM_SMCR(TIM4)
#define TIM5_SMCR TIM_SMCR(TIM5)
#define TIM8_SMCR TIM_SMCR(TIM8)
#define TIM9_SMCR TIM_SMCR(TIM9)
#define TIM12_SMCR TIM_SMCR(TIM12)
#define TIM15_SMCR TIM_SMCR(TIM15)


#define TIM_DIER(tim_base) MMIO32((tim_base) + 0x0C)
#define TIM1_DIER TIM_DIER(TIM1)
#define TIM2_DIER TIM_DIER(TIM2)
#define TIM3_DIER TIM_DIER(TIM3)
#define TIM4_DIER TIM_DIER(TIM4)
#define TIM5_DIER TIM_DIER(TIM5)
#define TIM6_DIER TIM_DIER(TIM6)
#define TIM7_DIER TIM_DIER(TIM7)
#define TIM8_DIER TIM_DIER(TIM8)
#define TIM9_DIER TIM_DIER(TIM9)
#define TIM10_DIER TIM_DIER(TIM10)
#define TIM11_DIER TIM_DIER(TIM11)
#define TIM12_DIER TIM_DIER(TIM12)
#define TIM13_DIER TIM_DIER(TIM13)
#define TIM14_DIER TIM_DIER(TIM14)
#define TIM15_DIER TIM_DIER(TIM15)
#define TIM16_DIER TIM_DIER(TIM16)
#define TIM17_DIER TIM_DIER(TIM17)


#define TIM_SR(tim_base) MMIO32((tim_base) + 0x10)
#define TIM1_SR TIM_SR(TIM1)
#define TIM2_SR TIM_SR(TIM2)
#define TIM3_SR TIM_SR(TIM3)
#define TIM4_SR TIM_SR(TIM4)
#define TIM5_SR TIM_SR(TIM5)
#define TIM6_SR TIM_SR(TIM6)
#define TIM7_SR TIM_SR(TIM7)
#define TIM8_SR TIM_SR(TIM8)
#define TIM9_SR TIM_SR(TIM9)
#define TIM10_SR TIM_SR(TIM10)
#define TIM11_SR TIM_SR(TIM11)
#define TIM12_SR TIM_SR(TIM12)
#define TIM13_SR TIM_SR(TIM13)
#define TIM14_SR TIM_SR(TIM14)
#define TIM15_SR TIM_SR(TIM15)
#define TIM16_SR TIM_SR(TIM16)
#define TIM17_SR TIM_SR(TIM17)


#define TIM_EGR(tim_base) MMIO32((tim_base) + 0x14)
#define TIM1_EGR TIM_EGR(TIM1)
#define TIM2_EGR TIM_EGR(TIM2)
#define TIM3_EGR TIM_EGR(TIM3)
#define TIM4_EGR TIM_EGR(TIM4)
#define TIM5_EGR TIM_EGR(TIM5)
#define TIM6_EGR TIM_EGR(TIM6)
#define TIM7_EGR TIM_EGR(TIM7)
#define TIM8_EGR TIM_EGR(TIM8)
#define TIM9_EGR TIM_EGR(TIM9)
#define TIM10_EGR TIM_EGR(TIM10)
#define TIM11_EGR TIM_EGR(TIM11)
#define TIM12_EGR TIM_EGR(TIM12)
#define TIM13_EGR TIM_EGR(TIM13)
#define TIM14_EGR TIM_EGR(TIM14)
#define TIM15_EGR TIM_EGR(TIM15)
#define TIM16_EGR TIM_EGR(TIM16)
#define TIM17_EGR TIM_EGR(TIM17)


#define TIM_CCMR1(tim_base) MMIO32((tim_base) + 0x18)
#define TIM1_CCMR1 TIM_CCMR1(TIM1)
#define TIM2_CCMR1 TIM_CCMR1(TIM2)
#define TIM3_CCMR1 TIM_CCMR1(TIM3)
#define TIM4_CCMR1 TIM_CCMR1(TIM4)
#define TIM5_CCMR1 TIM_CCMR1(TIM5)
#define TIM8_CCMR1 TIM_CCMR1(TIM8)
#define TIM9_CCMR1 TIM_CCMR1(TIM9)
#define TIM10_CCMR1 TIM_CCMR1(TIM10)
#define TIM11_CCMR1 TIM_CCMR1(TIM11)
#define TIM12_CCMR1 TIM_CCMR1(TIM12)
#define TIM13_CCMR1 TIM_CCMR1(TIM13)
#define TIM14_CCMR1 TIM_CCMR1(TIM14)
#define TIM15_CCMR1 TIM_CCMR1(TIM15)
#define TIM16_CCMR1 TIM_CCMR1(TIM16)
#define TIM17_CCMR1 TIM_CCMR1(TIM17)


#define TIM_CCMR2(tim_base) MMIO32((tim_base) + 0x1C)
#define TIM1_CCMR2 TIM_CCMR2(TIM1)
#define TIM2_CCMR2 TIM_CCMR2(TIM2)
#define TIM3_CCMR2 TIM_CCMR2(TIM3)
#define TIM4_CCMR2 TIM_CCMR2(TIM4)
#define TIM5_CCMR2 TIM_CCMR2(TIM5)
#define TIM8_CCMR2 TIM_CCMR2(TIM8)


#define TIM_CCER(tim_base) MMIO32((tim_base) + 0x20)
#define TIM1_CCER TIM_CCER(TIM1)
#define TIM2_CCER TIM_CCER(TIM2)
#define TIM3_CCER TIM_CCER(TIM3)
#define TIM4_CCER TIM_CCER(TIM4)
#define TIM5_CCER TIM_CCER(TIM5)
#define TIM8_CCER TIM_CCER(TIM8)
#define TIM9_CCER TIM_CCER(TIM9)
#define TIM10_CCER TIM_CCER(TIM10)
#define TIM11_CCER TIM_CCER(TIM11)
#define TIM12_CCER TIM_CCER(TIM12)
#define TIM13_CCER TIM_CCER(TIM13)
#define TIM14_CCER TIM_CCER(TIM14)
#define TIM15_CCER TIM_CCER(TIM15)
#define TIM16_CCER TIM_CCER(TIM16)
#define TIM17_CCER TIM_CCER(TIM17)


#define TIM_CNT(tim_base) MMIO32((tim_base) + 0x24)
#define TIM1_CNT TIM_CNT(TIM1)
#define TIM2_CNT TIM_CNT(TIM2)
#define TIM3_CNT TIM_CNT(TIM3)
#define TIM4_CNT TIM_CNT(TIM4)
#define TIM5_CNT TIM_CNT(TIM5)
#define TIM6_CNT TIM_CNT(TIM6)
#define TIM7_CNT TIM_CNT(TIM7)
#define TIM8_CNT TIM_CNT(TIM8)
#define TIM9_CNT TIM_CNT(TIM9)
#define TIM10_CNT TIM_CNT(TIM10)
#define TIM11_CNT TIM_CNT(TIM11)
#define TIM12_CNT TIM_CNT(TIM12)
#define TIM13_CNT TIM_CNT(TIM13)
#define TIM14_CNT TIM_CNT(TIM14)
#define TIM15_CNT TIM_CNT(TIM15)
#define TIM16_CNT TIM_CNT(TIM16)
#define TIM17_CNT TIM_CNT(TIM17)


#define TIM_PSC(tim_base) MMIO32((tim_base) + 0x28)
#define TIM1_PSC TIM_PSC(TIM1)
#define TIM2_PSC TIM_PSC(TIM2)
#define TIM3_PSC TIM_PSC(TIM3)
#define TIM4_PSC TIM_PSC(TIM4)
#define TIM5_PSC TIM_PSC(TIM5)
#define TIM6_PSC TIM_PSC(TIM6)
#define TIM7_PSC TIM_PSC(TIM7)
#define TIM8_PSC TIM_PSC(TIM8)
#define TIM9_PSC TIM_PSC(TIM9)
#define TIM10_PSC TIM_PSC(TIM10)
#define TIM11_PSC TIM_PSC(TIM11)
#define TIM12_PSC TIM_PSC(TIM12)
#define TIM13_PSC TIM_PSC(TIM13)
#define TIM14_PSC TIM_PSC(TIM14)
#define TIM15_PSC TIM_PSC(TIM15)
#define TIM16_PSC TIM_PSC(TIM16)
#define TIM17_PSC TIM_PSC(TIM17)


#define TIM_ARR(tim_base) MMIO32((tim_base) + 0x2C)
#define TIM1_ARR TIM_ARR(TIM1)
#define TIM2_ARR TIM_ARR(TIM2)
#define TIM3_ARR TIM_ARR(TIM3)
#define TIM4_ARR TIM_ARR(TIM4)
#define TIM5_ARR TIM_ARR(TIM5)
#define TIM6_ARR TIM_ARR(TIM6)
#define TIM7_ARR TIM_ARR(TIM7)
#define TIM8_ARR TIM_ARR(TIM8)
#define TIM9_ARR TIM_ARR(TIM9)
#define TIM10_ARR TIM_ARR(TIM10)
#define TIM11_ARR TIM_ARR(TIM11)
#define TIM12_ARR TIM_ARR(TIM12)
#define TIM13_ARR TIM_ARR(TIM13)
#define TIM14_ARR TIM_ARR(TIM14)
#define TIM15_ARR TIM_ARR(TIM15)
#define TIM16_ARR TIM_ARR(TIM16)
#define TIM17_ARR TIM_ARR(TIM17)


#define TIM_RCR(tim_base) MMIO32((tim_base) + 0x30)
#define TIM1_RCR TIM_RCR(TIM1)
#define TIM8_RCR TIM_RCR(TIM8)
#define TIM15_RCR TIM_RCR(TIM15)
#define TIM16_RCR TIM_RCR(TIM16)
#define TIM17_RCR TIM_RCR(TIM17)


#define TIM_CCR1(tim_base) MMIO32((tim_base) + 0x34)
#define TIM1_CCR1 TIM_CCR1(TIM1)
#define TIM2_CCR1 TIM_CCR1(TIM2)
#define TIM3_CCR1 TIM_CCR1(TIM3)
#define TIM4_CCR1 TIM_CCR1(TIM4)
#define TIM5_CCR1 TIM_CCR1(TIM5)
#define TIM8_CCR1 TIM_CCR1(TIM8)
#define TIM9_CCR1 TIM_CCR1(TIM9)
#define TIM10_CCR1 TIM_CCR1(TIM10)
#define TIM11_CCR1 TIM_CCR1(TIM11)
#define TIM12_CCR1 TIM_CCR1(TIM12)
#define TIM13_CCR1 TIM_CCR1(TIM13)
#define TIM14_CCR1 TIM_CCR1(TIM14)
#define TIM15_CCR1 TIM_CCR1(TIM15)
#define TIM16_CCR1 TIM_CCR1(TIM16)
#define TIM17_CCR1 TIM_CCR1(TIM17)


#define TIM_CCR2(tim_base) MMIO32((tim_base) + 0x38)
#define TIM1_CCR2 TIM_CCR2(TIM1)
#define TIM2_CCR2 TIM_CCR2(TIM2)
#define TIM3_CCR2 TIM_CCR2(TIM3)
#define TIM4_CCR2 TIM_CCR2(TIM4)
#define TIM5_CCR2 TIM_CCR2(TIM5)
#define TIM8_CCR2 TIM_CCR2(TIM8)
#define TIM9_CCR2 TIM_CCR2(TIM9)
#define TIM12_CCR2 TIM_CCR2(TIM12)
#define TIM15_CCR2 TIM_CCR2(TIM15)


#define TIM_CCR3(tim_base) MMIO32((tim_base) + 0x3C)
#define TIM1_CCR3 TIM_CCR3(TIM1)
#define TIM2_CCR3 TIM_CCR3(TIM2)
#define TIM3_CCR3 TIM_CCR3(TIM3)
#define TIM4_CCR3 TIM_CCR3(TIM4)
#define TIM5_CCR3 TIM_CCR3(TIM5)
#define TIM8_CCR3 TIM_CCR3(TIM8)


#define TIM_CCR4(tim_base) MMIO32((tim_base) + 0x40)
#define TIM1_CCR4 TIM_CCR4(TIM1)
#define TIM2_CCR4 TIM_CCR4(TIM2)
#define TIM3_CCR4 TIM_CCR4(TIM3)
#define TIM4_CCR4 TIM_CCR4(TIM4)
#define TIM5_CCR4 TIM_CCR4(TIM5)
#define TIM8_CCR4 TIM_CCR4(TIM8)


#define TIM_BDTR(tim_base) MMIO32((tim_base) + 0x44)
#define TIM1_BDTR TIM_BDTR(TIM1)
#define TIM8_BDTR TIM_BDTR(TIM8)
#define TIM15_BDTR TIM_BDTR(TIM15)
#define TIM16_BDTR TIM_BDTR(TIM16)
#define TIM17_BDTR TIM_BDTR(TIM17)


#define TIM_DCR(tim_base) MMIO32((tim_base) + 0x48)
#define TIM1_DCR TIM_DCR(TIM1)
#define TIM2_DCR TIM_DCR(TIM2)
#define TIM3_DCR TIM_DCR(TIM3)
#define TIM4_DCR TIM_DCR(TIM4)
#define TIM5_DCR TIM_DCR(TIM5)
#define TIM8_DCR TIM_DCR(TIM8)
#define TIM15_DCR TIM_DCR(TIM15)
#define TIM16_DCR TIM_DCR(TIM16)
#define TIM17_DCR TIM_DCR(TIM17)


#define TIM_DMAR(tim_base) MMIO32((tim_base) + 0x4C)
#define TIM1_DMAR TIM_DMAR(TIM1)
#define TIM2_DMAR TIM_DMAR(TIM2)
#define TIM3_DMAR TIM_DMAR(TIM3)
#define TIM4_DMAR TIM_DMAR(TIM4)
#define TIM5_DMAR TIM_DMAR(TIM5)
#define TIM8_DMAR TIM_DMAR(TIM8)
#define TIM15_DMAR TIM_DMAR(TIM15)
#define TIM16_DMAR TIM_DMAR(TIM16)
#define TIM17_DMAR TIM_DMAR(TIM17)







#define TIM_CR1_CKD_CK_INT (0x0 << 8)
#define TIM_CR1_CKD_CK_INT_MUL_2 (0x1 << 8)
#define TIM_CR1_CKD_CK_INT_MUL_4 (0x2 << 8)
#define TIM_CR1_CKD_CK_INT_MASK (0x3 << 8)



#define TIM_CR1_ARPE (1 << 7)





#define TIM_CR1_CMS_EDGE (0x0 << 5)
#define TIM_CR1_CMS_CENTER_1 (0x1 << 5)
#define TIM_CR1_CMS_CENTER_2 (0x2 << 5)
#define TIM_CR1_CMS_CENTER_3 (0x3 << 5)
#define TIM_CR1_CMS_MASK (0x3 << 5)






#define TIM_CR1_DIR_UP (0 << 4)
#define TIM_CR1_DIR_DOWN (1 << 4)



#define TIM_CR1_OPM (1 << 3)


#define TIM_CR1_URS (1 << 2)


#define TIM_CR1_UDIS (1 << 1)


#define TIM_CR1_CEN (1 << 0)







#define TIM_CR2_OIS4 (1 << 14)


#define TIM_CR2_OIS3N (1 << 13)


#define TIM_CR2_OIS3 (1 << 12)


#define TIM_CR2_OIS2N (1 << 11)


#define TIM_CR2_OIS2 (1 << 10)


#define TIM_CR2_OIS1N (1 << 9)


#define TIM_CR2_OIS1 (1 << 8)
#define TIM_CR2_OIS_MASK (0x7f << 8)



#define TIM_CR2_TI1S (1 << 7)





#define TIM_CR2_MMS_RESET (0x0 << 4)
#define TIM_CR2_MMS_ENABLE (0x1 << 4)
#define TIM_CR2_MMS_UPDATE (0x2 << 4)
#define TIM_CR2_MMS_COMPARE_PULSE (0x3 << 4)
#define TIM_CR2_MMS_COMPARE_OC1REF (0x4 << 4)
#define TIM_CR2_MMS_COMPARE_OC2REF (0x5 << 4)
#define TIM_CR2_MMS_COMPARE_OC3REF (0x6 << 4)
#define TIM_CR2_MMS_COMPARE_OC4REF (0x7 << 4)
#define TIM_CR2_MMS_MASK (0x7 << 4)



#define TIM_CR2_CCDS (1 << 3)


#define TIM_CR2_CCUS (1 << 2)


#define TIM_CR2_CCPC (1 << 0)




#define TIM_SMCR_ETP (1 << 15)


#define TIM_SMCR_ECE (1 << 14)


#define TIM_SMCR_ETPS_OFF (0x0 << 12)
#define TIM_SMCR_ETPS_ETRP_DIV_2 (0x1 << 12)
#define TIM_SMCR_ETPS_ETRP_DIV_4 (0x2 << 12)
#define TIM_SMCR_ETPS_ETRP_DIV_8 (0x3 << 12)
#define TIM_SMCR_ETPS_MASK (0X3 << 12)


#define TIM_SMCR_ETF_OFF (0x0 << 8)
#define TIM_SMCR_ETF_CK_INT_N_2 (0x1 << 8)
#define TIM_SMCR_ETF_CK_INT_N_4 (0x2 << 8)
#define TIM_SMCR_ETF_CK_INT_N_8 (0x3 << 8)
#define TIM_SMCR_ETF_DTS_DIV_2_N_6 (0x4 << 8)
#define TIM_SMCR_ETF_DTS_DIV_2_N_8 (0x5 << 8)
#define TIM_SMCR_ETF_DTS_DIV_4_N_6 (0x6 << 8)
#define TIM_SMCR_ETF_DTS_DIV_4_N_8 (0x7 << 8)
#define TIM_SMCR_ETF_DTS_DIV_8_N_6 (0x8 << 8)
#define TIM_SMCR_ETF_DTS_DIV_8_N_8 (0x9 << 8)
#define TIM_SMCR_ETF_DTS_DIV_16_N_5 (0xA << 8)
#define TIM_SMCR_ETF_DTS_DIV_16_N_6 (0xB << 8)
#define TIM_SMCR_ETF_DTS_DIV_16_N_8 (0xC << 8)
#define TIM_SMCR_ETF_DTS_DIV_32_N_5 (0xD << 8)
#define TIM_SMCR_ETF_DTS_DIV_32_N_6 (0xE << 8)
#define TIM_SMCR_ETF_DTS_DIV_32_N_8 (0xF << 8)
#define TIM_SMCR_ETF_MASK (0xF << 8)


#define TIM_SMCR_MSM (1 << 7)





#define TIM_SMCR_TS_ITR0 (0x0 << 4)

#define TIM_SMCR_TS_ITR1 (0x1 << 4)

#define TIM_SMCR_TS_ITR2 (0x2 << 4)

#define TIM_SMCR_TS_ITR3 (0x3 << 4)

#define TIM_SMCR_TS_TI1F_ED (0x4 << 4)

#define TIM_SMCR_TS_TI1FP1 (0x5 << 4)

#define TIM_SMCR_TS_TI2FP2 (0x6 << 4)

#define TIM_SMCR_TS_ETRF (0x7 << 4)
#define TIM_SMCR_TS_MASK (0x7 << 4)






#define TIM_SMCR_SMS_OFF (0x0 << 0)


#define TIM_SMCR_SMS_EM1 (0x1 << 0)


#define TIM_SMCR_SMS_EM2 (0x2 << 0)


#define TIM_SMCR_SMS_EM3 (0x3 << 0)



#define TIM_SMCR_SMS_RM (0x4 << 0)



#define TIM_SMCR_SMS_GM (0x5 << 0)

#define TIM_SMCR_SMS_TM (0x6 << 0)



#define TIM_SMCR_SMS_ECM1 (0x7 << 0)
#define TIM_SMCR_SMS_MASK (0x7 << 0)
#define TIM_DIER_TDE (1 << 14)


#define TIM_DIER_COMDE (1 << 13)


#define TIM_DIER_CC4DE (1 << 12)


#define TIM_DIER_CC3DE (1 << 11)


#define TIM_DIER_CC2DE (1 << 10)


#define TIM_DIER_CC1DE (1 << 9)


#define TIM_DIER_UDE (1 << 8)


#define TIM_DIER_BIE (1 << 7)


#define TIM_DIER_TIE (1 << 6)


#define TIM_DIER_COMIE (1 << 5)


#define TIM_DIER_CC4IE (1 << 4)


#define TIM_DIER_CC3IE (1 << 3)


#define TIM_DIER_CC2IE (1 << 2)


#define TIM_DIER_CC1IE (1 << 1)


#define TIM_DIER_UIE (1 << 0)
#define TIM_SR_CC4OF (1 << 12)


#define TIM_SR_CC3OF (1 << 11)


#define TIM_SR_CC2OF (1 << 10)


#define TIM_SR_CC1OF (1 << 9)


#define TIM_SR_BIF (1 << 7)


#define TIM_SR_TIF (1 << 6)


#define TIM_SR_COMIF (1 << 5)


#define TIM_SR_CC4IF (1 << 4)


#define TIM_SR_CC3IF (1 << 3)


#define TIM_SR_CC2IF (1 << 2)


#define TIM_SR_CC1IF (1 << 1)


#define TIM_SR_UIF (1 << 0)
#define TIM_EGR_BG (1 << 7)


#define TIM_EGR_TG (1 << 6)


#define TIM_EGR_COMG (1 << 5)


#define TIM_EGR_CC4G (1 << 4)


#define TIM_EGR_CC3G (1 << 3)


#define TIM_EGR_CC2G (1 << 2)


#define TIM_EGR_CC1G (1 << 1)


#define TIM_EGR_UG (1 << 0)







#define TIM_CCMR1_OC2CE (1 << 15)


#define TIM_CCMR1_OC2M_FROZEN (0x0 << 12)
#define TIM_CCMR1_OC2M_ACTIVE (0x1 << 12)
#define TIM_CCMR1_OC2M_INACTIVE (0x2 << 12)
#define TIM_CCMR1_OC2M_TOGGLE (0x3 << 12)
#define TIM_CCMR1_OC2M_FORCE_LOW (0x4 << 12)
#define TIM_CCMR1_OC2M_FORCE_HIGH (0x5 << 12)
#define TIM_CCMR1_OC2M_PWM1 (0x6 << 12)
#define TIM_CCMR1_OC2M_PWM2 (0x7 << 12)
#define TIM_CCMR1_OC2M_MASK (0x7 << 12)


#define TIM_CCMR1_OC2PE (1 << 11)


#define TIM_CCMR1_OC2FE (1 << 10)




#define TIM_CCMR1_CC2S_OUT (0x0 << 8)
#define TIM_CCMR1_CC2S_IN_TI2 (0x1 << 8)
#define TIM_CCMR1_CC2S_IN_TI1 (0x2 << 8)
#define TIM_CCMR1_CC2S_IN_TRC (0x3 << 8)
#define TIM_CCMR1_CC2S_MASK (0x3 << 8)


#define TIM_CCMR1_OC1CE (1 << 7)


#define TIM_CCMR1_OC1M_FROZEN (0x0 << 4)
#define TIM_CCMR1_OC1M_ACTIVE (0x1 << 4)
#define TIM_CCMR1_OC1M_INACTIVE (0x2 << 4)
#define TIM_CCMR1_OC1M_TOGGLE (0x3 << 4)
#define TIM_CCMR1_OC1M_FORCE_LOW (0x4 << 4)
#define TIM_CCMR1_OC1M_FORCE_HIGH (0x5 << 4)
#define TIM_CCMR1_OC1M_PWM1 (0x6 << 4)
#define TIM_CCMR1_OC1M_PWM2 (0x7 << 4)
#define TIM_CCMR1_OC1M_MASK (0x7 << 4)


#define TIM_CCMR1_OC1PE (1 << 3)


#define TIM_CCMR1_OC1FE (1 << 2)




#define TIM_CCMR1_CC1S_OUT (0x0 << 0)
#define TIM_CCMR1_CC1S_IN_TI2 (0x2 << 0)
#define TIM_CCMR1_CC1S_IN_TI1 (0x1 << 0)
#define TIM_CCMR1_CC1S_IN_TRC (0x3 << 0)
#define TIM_CCMR1_CC1S_MASK (0x3 << 0)




#define TIM_CCMR1_IC2F_OFF (0x0 << 12)
#define TIM_CCMR1_IC2F_CK_INT_N_2 (0x1 << 12)
#define TIM_CCMR1_IC2F_CK_INT_N_4 (0x2 << 12)
#define TIM_CCMR1_IC2F_CK_INT_N_8 (0x3 << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_2_N_6 (0x4 << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_2_N_8 (0x5 << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_4_N_6 (0x6 << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_4_N_8 (0x7 << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_8_N_6 (0x8 << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_8_N_8 (0x9 << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_16_N_5 (0xA << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_16_N_6 (0xB << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_16_N_8 (0xC << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_32_N_5 (0xD << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_32_N_6 (0xE << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_32_N_8 (0xF << 12)
#define TIM_CCMR1_IC2F_MASK (0xF << 12)


#define TIM_CCMR1_IC2PSC_OFF (0x0 << 10)
#define TIM_CCMR1_IC2PSC_2 (0x1 << 10)
#define TIM_CCMR1_IC2PSC_4 (0x2 << 10)
#define TIM_CCMR1_IC2PSC_8 (0x3 << 10)
#define TIM_CCMR1_IC2PSC_MASK (0x3 << 10)


#define TIM_CCMR1_IC1F_OFF (0x0 << 4)
#define TIM_CCMR1_IC1F_CK_INT_N_2 (0x1 << 4)
#define TIM_CCMR1_IC1F_CK_INT_N_4 (0x2 << 4)
#define TIM_CCMR1_IC1F_CK_INT_N_8 (0x3 << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_2_N_6 (0x4 << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_2_N_8 (0x5 << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_4_N_6 (0x6 << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_4_N_8 (0x7 << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_8_N_6 (0x8 << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_8_N_8 (0x9 << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_16_N_5 (0xA << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_16_N_6 (0xB << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_16_N_8 (0xC << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_32_N_5 (0xD << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_32_N_6 (0xE << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_32_N_8 (0xF << 4)
#define TIM_CCMR1_IC1F_MASK (0xF << 4)


#define TIM_CCMR1_IC1PSC_OFF (0x0 << 2)
#define TIM_CCMR1_IC1PSC_2 (0x1 << 2)
#define TIM_CCMR1_IC1PSC_4 (0x2 << 2)
#define TIM_CCMR1_IC1PSC_8 (0x3 << 2)
#define TIM_CCMR1_IC1PSC_MASK (0x3 << 2)






#define TIM_CCMR2_OC4CE (1 << 15)


#define TIM_CCMR2_OC4M_FROZEN (0x0 << 12)
#define TIM_CCMR2_OC4M_ACTIVE (0x1 << 12)
#define TIM_CCMR2_OC4M_INACTIVE (0x2 << 12)
#define TIM_CCMR2_OC4M_TOGGLE (0x3 << 12)
#define TIM_CCMR2_OC4M_FORCE_LOW (0x4 << 12)
#define TIM_CCMR2_OC4M_FORCE_HIGH (0x5 << 12)
#define TIM_CCMR2_OC4M_PWM1 (0x6 << 12)
#define TIM_CCMR2_OC4M_PWM2 (0x7 << 12)
#define TIM_CCMR2_OC4M_MASK (0x7 << 12)


#define TIM_CCMR2_OC4PE (1 << 11)


#define TIM_CCMR2_OC4FE (1 << 10)




#define TIM_CCMR2_CC4S_OUT (0x0 << 8)
#define TIM_CCMR2_CC4S_IN_TI4 (0x1 << 8)
#define TIM_CCMR2_CC4S_IN_TI3 (0x2 << 8)
#define TIM_CCMR2_CC4S_IN_TRC (0x3 << 8)
#define TIM_CCMR2_CC4S_MASK (0x3 << 8)


#define TIM_CCMR2_OC3CE (1 << 7)


#define TIM_CCMR2_OC3M_FROZEN (0x0 << 4)
#define TIM_CCMR2_OC3M_ACTIVE (0x1 << 4)
#define TIM_CCMR2_OC3M_INACTIVE (0x2 << 4)
#define TIM_CCMR2_OC3M_TOGGLE (0x3 << 4)
#define TIM_CCMR2_OC3M_FORCE_LOW (0x4 << 4)
#define TIM_CCMR2_OC3M_FORCE_HIGH (0x5 << 4)
#define TIM_CCMR2_OC3M_PWM1 (0x6 << 4)
#define TIM_CCMR2_OC3M_PWM2 (0x7 << 4)
#define TIM_CCMR2_OC3M_MASK (0x7 << 4)


#define TIM_CCMR2_OC3PE (1 << 3)


#define TIM_CCMR2_OC3FE (1 << 2)




#define TIM_CCMR2_CC3S_OUT (0x0 << 0)
#define TIM_CCMR2_CC3S_IN_TI3 (0x1 << 0)
#define TIM_CCMR2_CC3S_IN_TI4 (0x2 << 0)
#define TIM_CCMR2_CC3S_IN_TRC (0x3 << 0)
#define TIM_CCMR2_CC3S_MASK (0x3 << 0)




#define TIM_CCMR2_IC4F_OFF (0x0 << 12)
#define TIM_CCMR2_IC4F_CK_INT_N_2 (0x1 << 12)
#define TIM_CCMR2_IC4F_CK_INT_N_4 (0x2 << 12)
#define TIM_CCMR2_IC4F_CK_INT_N_8 (0x3 << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_2_N_6 (0x4 << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_2_N_8 (0x5 << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_4_N_6 (0x6 << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_4_N_8 (0x7 << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_8_N_6 (0x8 << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_8_N_8 (0x9 << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_16_N_5 (0xA << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_16_N_6 (0xB << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_16_N_8 (0xC << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_32_N_5 (0xD << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_32_N_6 (0xE << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_32_N_8 (0xF << 12)
#define TIM_CCMR2_IC4F_MASK (0xF << 12)


#define TIM_CCMR2_IC4PSC_OFF (0x0 << 10)
#define TIM_CCMR2_IC4PSC_2 (0x1 << 10)
#define TIM_CCMR2_IC4PSC_4 (0x2 << 10)
#define TIM_CCMR2_IC4PSC_8 (0x3 << 10)
#define TIM_CCMR2_IC4PSC_MASK (0x3 << 10)


#define TIM_CCMR2_IC3F_OFF (0x0 << 4)
#define TIM_CCMR2_IC3F_CK_INT_N_2 (0x1 << 4)
#define TIM_CCMR2_IC3F_CK_INT_N_4 (0x2 << 4)
#define TIM_CCMR2_IC3F_CK_INT_N_8 (0x3 << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_2_N_6 (0x4 << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_2_N_8 (0x5 << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_4_N_6 (0x6 << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_4_N_8 (0x7 << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_8_N_6 (0x8 << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_8_N_8 (0x9 << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_16_N_5 (0xA << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_16_N_6 (0xB << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_16_N_8 (0xC << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_32_N_5 (0xD << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_32_N_6 (0xE << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_32_N_8 (0xF << 4)
#define TIM_CCMR2_IC3F_MASK (0xF << 4)


#define TIM_CCMR2_IC3PSC_OFF (0x0 << 2)
#define TIM_CCMR2_IC3PSC_2 (0x1 << 2)
#define TIM_CCMR2_IC3PSC_4 (0x2 << 2)
#define TIM_CCMR2_IC3PSC_8 (0x3 << 2)
#define TIM_CCMR2_IC3PSC_MASK (0x3 << 2)




#define TIM_CCER_CC4NP (1 << 15)


#define TIM_CCER_CC4P (1 << 13)


#define TIM_CCER_CC4E (1 << 12)


#define TIM_CCER_CC3NP (1 << 11)


#define TIM_CCER_CC3NE (1 << 10)


#define TIM_CCER_CC3P (1 << 9)


#define TIM_CCER_CC3E (1 << 8)


#define TIM_CCER_CC2NP (1 << 7)


#define TIM_CCER_CC2NE (1 << 6)


#define TIM_CCER_CC2P (1 << 5)


#define TIM_CCER_CC2E (1 << 4)


#define TIM_CCER_CC1NP (1 << 3)


#define TIM_CCER_CC1NE (1 << 2)


#define TIM_CCER_CC1P (1 << 1)


#define TIM_CCER_CC1E (1 << 0)
#define TIM_BDTR_MOE (1 << 15)


#define TIM_BDTR_AOE (1 << 14)


#define TIM_BDTR_BKP (1 << 13)


#define TIM_BDTR_BKE (1 << 12)


#define TIM_BDTR_OSSR (1 << 11)


#define TIM_BDTR_OSSI (1 << 10)





#define TIM_BDTR_LOCK_OFF (0x0 << 8)
#define TIM_BDTR_LOCK_LEVEL_1 (0x1 << 8)
#define TIM_BDTR_LOCK_LEVEL_2 (0x2 << 8)
#define TIM_BDTR_LOCK_LEVEL_3 (0x3 << 8)
#define TIM_BDTR_LOCK_MASK (0x3 << 8)



#define TIM_BDTR_DTG_MASK 0x00FF




#define TIM_BDTR_DBL_MASK (0x1F << 8)


#define TIM_BDTR_DBA_MASK (0x1F << 0)

enum tim_oc_id {
 TIM_OC1 = 0,
 TIM_OC1N,
 TIM_OC2,
 TIM_OC2N,
 TIM_OC3,
 TIM_OC3N,
 TIM_OC4,
};


enum tim_oc_mode {
 TIM_OCM_FROZEN,
 TIM_OCM_ACTIVE,
 TIM_OCM_INACTIVE,
 TIM_OCM_TOGGLE,
 TIM_OCM_FORCE_LOW,
 TIM_OCM_FORCE_HIGH,
 TIM_OCM_PWM1,
 TIM_OCM_PWM2,
};


enum tim_ic_id {
 TIM_IC1,
 TIM_IC2,
 TIM_IC3,
 TIM_IC4,
};
enum tim_ic_filter {
 TIM_IC_OFF,
 TIM_IC_CK_INT_N_2,
 TIM_IC_CK_INT_N_4,
 TIM_IC_CK_INT_N_8,
 TIM_IC_DTF_DIV_2_N_6,
 TIM_IC_DTF_DIV_2_N_8,
 TIM_IC_DTF_DIV_4_N_6,
 TIM_IC_DTF_DIV_4_N_8,
 TIM_IC_DTF_DIV_8_N_6,
 TIM_IC_DTF_DIV_8_N_8,
 TIM_IC_DTF_DIV_16_N_5,
 TIM_IC_DTF_DIV_16_N_6,
 TIM_IC_DTF_DIV_16_N_8,
 TIM_IC_DTF_DIV_32_N_5,
 TIM_IC_DTF_DIV_32_N_6,
 TIM_IC_DTF_DIV_32_N_8,
};




enum tim_ic_psc {
 TIM_IC_PSC_OFF,
 TIM_IC_PSC_2,
 TIM_IC_PSC_4,
 TIM_IC_PSC_8,
};





enum tim_ic_input {
 TIM_IC_OUT = 0,
 TIM_IC_IN_TI1 = 1,
 TIM_IC_IN_TI2 = 2,
 TIM_IC_IN_TRC = 3,
 TIM_IC_IN_TI3 = 5,
 TIM_IC_IN_TI4 = 6,
};


enum tim_et_pol {
 TIM_ET_RISING,
 TIM_ET_FALLING,
};


enum tim_ecm2_state {
    TIM_ECM2_DISABLED,
    TIM_ECM2_ENABLED,
};





void timer_enable_irq(uint32_t timer_peripheral, uint32_t irq);
void timer_disable_irq(uint32_t timer_peripheral, uint32_t irq);

_Bool 
    timer_interrupt_source(uint32_t timer_peripheral, uint32_t flag);

_Bool 
    timer_get_flag(uint32_t timer_peripheral, uint32_t flag);
void timer_clear_flag(uint32_t timer_peripheral, uint32_t flag);
void timer_set_mode(uint32_t timer_peripheral, uint32_t clock_div,
      uint32_t alignment, uint32_t direction);
void timer_set_clock_division(uint32_t timer_peripheral, uint32_t clock_div);
void timer_enable_preload(uint32_t timer_peripheral);
void timer_disable_preload(uint32_t timer_peripheral);
void timer_set_alignment(uint32_t timer_peripheral, uint32_t alignment);
void timer_direction_up(uint32_t timer_peripheral);
void timer_direction_down(uint32_t timer_peripheral);
void timer_one_shot_mode(uint32_t timer_peripheral);
void timer_continuous_mode(uint32_t timer_peripheral);
void timer_update_on_any(uint32_t timer_peripheral);
void timer_update_on_overflow(uint32_t timer_peripheral);
void timer_enable_update_event(uint32_t timer_peripheral);
void timer_disable_update_event(uint32_t timer_peripheral);
void timer_enable_counter(uint32_t timer_peripheral);
void timer_disable_counter(uint32_t timer_peripheral);
void timer_set_output_idle_state(uint32_t timer_peripheral, uint32_t outputs);
void timer_reset_output_idle_state(uint32_t timer_peripheral, uint32_t outputs);
void timer_set_ti1_ch123_xor(uint32_t timer_peripheral);
void timer_set_ti1_ch1(uint32_t timer_peripheral);
void timer_set_master_mode(uint32_t timer_peripheral, uint32_t mode);
void timer_set_dma_on_compare_event(uint32_t timer_peripheral);
void timer_set_dma_on_update_event(uint32_t timer_peripheral);
void timer_enable_compare_control_update_on_trigger(uint32_t timer_peripheral);
void timer_disable_compare_control_update_on_trigger(uint32_t timer_peripheral);
void timer_enable_preload_complementry_enable_bits(uint32_t timer_peripheral);
void timer_disable_preload_complementry_enable_bits(uint32_t timer_peripheral);
void timer_set_prescaler(uint32_t timer_peripheral, uint32_t value);
void timer_set_repetition_counter(uint32_t timer_peripheral, uint32_t value);
void timer_set_period(uint32_t timer_peripheral, uint32_t period);
void timer_enable_oc_clear(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_disable_oc_clear(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_fast_mode(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_slow_mode(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_mode(uint32_t timer_peripheral, enum tim_oc_id oc_id,
         enum tim_oc_mode oc_mode);
void timer_enable_oc_preload(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_disable_oc_preload(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_polarity_high(uint32_t timer_peripheral,
    enum tim_oc_id oc_id);
void timer_set_oc_polarity_low(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_enable_oc_output(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_disable_oc_output(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_idle_state_set(uint32_t timer_peripheral,
     enum tim_oc_id oc_id);
void timer_set_oc_idle_state_unset(uint32_t timer_peripheral,
       enum tim_oc_id oc_id);
void timer_set_oc_value(uint32_t timer_peripheral, enum tim_oc_id oc_id,
   uint32_t value);
void timer_enable_break_main_output(uint32_t timer_peripheral);
void timer_disable_break_main_output(uint32_t timer_peripheral);
void timer_enable_break_automatic_output(uint32_t timer_peripheral);
void timer_disable_break_automatic_output(uint32_t timer_peripheral);
void timer_set_break_polarity_high(uint32_t timer_peripheral);
void timer_set_break_polarity_low(uint32_t timer_peripheral);
void timer_enable_break(uint32_t timer_peripheral);
void timer_disable_break(uint32_t timer_peripheral);
void timer_set_enabled_off_state_in_run_mode(uint32_t timer_peripheral);
void timer_set_disabled_off_state_in_run_mode(uint32_t timer_peripheral);
void timer_set_enabled_off_state_in_idle_mode(uint32_t timer_peripheral);
void timer_set_disabled_off_state_in_idle_mode(uint32_t timer_peripheral);
void timer_set_break_lock(uint32_t timer_peripheral, uint32_t lock);
void timer_set_deadtime(uint32_t timer_peripheral, uint32_t deadtime);
void timer_generate_event(uint32_t timer_peripheral, uint32_t event);
uint32_t timer_get_counter(uint32_t timer_peripheral);
void timer_set_counter(uint32_t timer_peripheral, uint32_t count);

void timer_ic_set_filter(uint32_t timer, enum tim_ic_id ic,
    enum tim_ic_filter flt);
void timer_ic_set_prescaler(uint32_t timer, enum tim_ic_id ic,
       enum tim_ic_psc psc);
void timer_ic_set_input(uint32_t timer, enum tim_ic_id ic,
   enum tim_ic_input in);
void timer_ic_enable(uint32_t timer, enum tim_ic_id ic);
void timer_ic_disable(uint32_t timer, enum tim_ic_id ic);

void timer_slave_set_filter(uint32_t timer, enum tim_ic_filter flt);
void timer_slave_set_prescaler(uint32_t timer, enum tim_ic_psc psc);
void timer_slave_set_polarity(uint32_t timer, enum tim_et_pol pol);
void timer_slave_set_mode(uint32_t timer, uint8_t mode);
void timer_slave_set_trigger(uint32_t timer, uint8_t trigger);
void timer_slave_set_extclockmode2(uint32_t timer_peripheral,
            enum tim_ecm2_state state);









#define TIM_OR(tim_base) MMIO32((tim_base) + 0x50)
#define TIM2_OR TIM_OR(TIM2)
#define TIM5_OR TIM_OR(TIM5)
#define TIM2_OR_ITR1_RMP_TIM8_TRGOU (0x0 << 10)

#define TIM2_OR_ITR1_RMP_PTP (0x1 << 10)

#define TIM2_OR_ITR1_RMP_OTG_FS_SOF (0x2 << 10)

#define TIM2_OR_ITR1_RMP_OTG_HS_SOF (0x3 << 10)

#define TIM2_OR_ITR1_RMP_MASK (0x3 << 10)
#define TIM5_OR_TI4_RMP_GPIO (0x0 << 6)

#define TIM5_OR_TI4_RMP_LSI (0x1 << 6)

#define TIM5_OR_TI4_RMP_LSE (0x2 << 6)

#define TIM5_OR_TI4_RMP_RTC (0x3 << 6)

#define TIM5_OR_TI4_RMP_MASK (0x3 << 6)


enum tim_ic_pol {
 TIM_IC_RISING,
 TIM_IC_FALLING,
 TIM_IC_BOTH,
};





void timer_set_option(uint32_t timer_peripheral, uint32_t option);
void timer_ic_set_polarity(uint32_t timer, enum tim_ic_id ic,
      enum tim_ic_pol pol);


void timer_set_option(uint32_t timer_peripheral, uint32_t option)
{
 if (timer_peripheral == (((0x40000000U) + 0x00000) + 0x0000)) {
  (*(volatile uint32_t *)((timer_peripheral) + 0x50)) &= ~(0x3 << 10);
  (*(volatile uint32_t *)((timer_peripheral) + 0x50)) |= option;
 } else if (timer_peripheral == (((0x40000000U) + 0x00000) + 0x0c00)) {
  (*(volatile uint32_t *)((timer_peripheral) + 0x50)) &= ~(0x3 << 6);
  (*(volatile uint32_t *)((timer_peripheral) + 0x50)) |= option;
 }
}
