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
#define LIBOPENCM3_DMA_H 

#define LIBOPENCM3_DMA_COMMON_F24_H 






#define DMA1 DMA1_BASE
#define DMA2 DMA2_BASE






#define DMA_STREAM0 0
#define DMA_STREAM1 1
#define DMA_STREAM2 2
#define DMA_STREAM3 3
#define DMA_STREAM4 4
#define DMA_STREAM5 5
#define DMA_STREAM6 6
#define DMA_STREAM7 7


#define DMA_STREAM(port,n) ((port) + 0x10 + (24 * (n)))
#define DMA1_STREAM(n) DMA_STREAM(DMA1, (n))
#define DMA2_STREAM(n) DMA_STREAM(DMA2, (n))

#define DMA1_STREAM0 DMA1_STREAM(0)
#define DMA1_STREAM1 DMA1_STREAM(1)
#define DMA1_STREAM2 DMA1_STREAM(2)
#define DMA1_STREAM3 DMA1_STREAM(3)
#define DMA1_STREAM4 DMA1_STREAM(4)
#define DMA1_STREAM5 DMA1_STREAM(5)
#define DMA1_STREAM6 DMA1_STREAM(6)
#define DMA1_STREAM7 DMA1_STREAM(7)

#define DMA2_STREAM0 DMA2_STREAM(0)
#define DMA2_STREAM1 DMA2_STREAM(1)
#define DMA2_STREAM2 DMA2_STREAM(2)
#define DMA2_STREAM3 DMA2_STREAM(3)
#define DMA2_STREAM4 DMA2_STREAM(4)
#define DMA2_STREAM5 DMA2_STREAM(5)
#define DMA2_STREAM6 DMA2_STREAM(6)
#define DMA2_STREAM7 DMA2_STREAM(7)




#define DMA_LISR(port) MMIO32((port) + 0x00)
#define DMA1_LISR DMA_LISR(DMA1)
#define DMA2_LISR DMA_LISR(DMA2)


#define DMA_HISR(port) MMIO32((port) + 0x04)
#define DMA1_HISR DMA_HISR(DMA1)
#define DMA2_HISR DMA_HISR(DMA2)


#define DMA_LIFCR(port) MMIO32((port) + 0x08)
#define DMA1_LIFCR DMA_LIFCR(DMA1)
#define DMA2_LIFCR DMA_LIFCR(DMA2)


#define DMA_HIFCR(port) MMIO32((port) + 0x0C)
#define DMA1_HIFCR DMA_HIFCR(DMA1)
#define DMA2_HIFCR DMA_HIFCR(DMA2)




#define DMA_SCR(port,n) MMIO32(DMA_STREAM((port), (n)) + 0x00)
#define DMA1_SCR(n) DMA_SCR(DMA1, (n))
#define DMA2_SCR(n) DMA_SCR(DMA2, (n))

#define DMA1_S0CR DMA1_SCR(0)
#define DMA1_S1CR DMA1_SCR(1)
#define DMA1_S2CR DMA1_SCR(2)
#define DMA1_S3CR DMA1_SCR(3)
#define DMA1_S4CR DMA1_SCR(4)
#define DMA1_S5CR DMA1_SCR(5)
#define DMA1_S6CR DMA1_SCR(6)
#define DMA1_S7CR DMA1_SCR(7)

#define DMA2_S0CR DMA2_SCR(0)
#define DMA2_S1CR DMA2_SCR(1)
#define DMA2_S2CR DMA2_SCR(2)
#define DMA2_S3CR DMA2_SCR(3)
#define DMA2_S4CR DMA2_SCR(4)
#define DMA2_S5CR DMA2_SCR(5)
#define DMA2_S6CR DMA2_SCR(6)
#define DMA2_S7CR DMA2_SCR(7)


#define DMA_SNDTR(port,n) MMIO32(DMA_STREAM((port), (n)) + 0x04)
#define DMA1_SNDTR(n) DMA_SNDTR(DMA1, (n))
#define DMA2_SNDTR(n) DMA_SNDTR(DMA2, (n))

#define DMA1_S0NDTR DMA1_SNDTR(0)
#define DMA1_S1NDTR DMA1_SNDTR(1)
#define DMA1_S2NDTR DMA1_SNDTR(2)
#define DMA1_S3NDTR DMA1_SNDTR(3)
#define DMA1_S4NDTR DMA1_SNDTR(4)
#define DMA1_S5NDTR DMA1_SNDTR(5)
#define DMA1_S6NDTR DMA1_SNDTR(6)
#define DMA1_S7NDTR DMA1_SNDTR(7)

#define DMA2_S0NDTR DMA2_SNDTR(0)
#define DMA2_S1NDTR DMA2_SNDTR(1)
#define DMA2_S2NDTR DMA2_SNDTR(2)
#define DMA2_S3NDTR DMA2_SNDTR(3)
#define DMA2_S4NDTR DMA2_SNDTR(4)
#define DMA2_S5NDTR DMA2_SNDTR(5)
#define DMA2_S6NDTR DMA2_SNDTR(6)
#define DMA2_S7NDTR DMA2_SNDTR(7)


#define DMA_SPAR(port,n) (*(volatile void **) (DMA_STREAM((port), (n)) + 0x08))

#define DMA1_SPAR(n) DMA_SPAR(DMA1, (n))
#define DMA2_SPAR(n) DMA_SPAR(DMA2, (n))

#define DMA1_S0PAR DMA1_SPAR(0)
#define DMA1_S1PAR DMA1_SPAR(1)
#define DMA1_S2PAR DMA1_SPAR(2)
#define DMA1_S3PAR DMA1_SPAR(3)
#define DMA1_S4PAR DMA1_SPAR(4)
#define DMA1_S5PAR DMA1_SPAR(5)
#define DMA1_S6PAR DMA1_SPAR(6)
#define DMA1_S7PAR DMA1_SPAR(7)

#define DMA2_S0PAR DMA2_SPAR(0)
#define DMA2_S1PAR DMA2_SPAR(1)
#define DMA2_S2PAR DMA2_SPAR(2)
#define DMA2_S3PAR DMA2_SPAR(3)
#define DMA2_S4PAR DMA2_SPAR(4)
#define DMA2_S5PAR DMA2_SPAR(5)
#define DMA2_S6PAR DMA2_SPAR(6)
#define DMA2_S7PAR DMA2_SPAR(7)


#define DMA_SM0AR(port,n) (*(volatile void **) (DMA_STREAM((port), (n)) + 0x0c))

#define DMA1_SM0AR(n) DMA_SM0AR(DMA1, (n))
#define DMA2_SM0AR(n) DMA_SM0AR(DMA2, (n))

#define DMA1_S0M0AR DMA1_SM0AR(0)
#define DMA1_S1M0AR DMA1_SM0AR(1)
#define DMA1_S2M0AR DMA1_SM0AR(2)
#define DMA1_S3M0AR DMA1_SM0AR(3)
#define DMA1_S4M0AR DMA1_SM0AR(4)
#define DMA1_S5M0AR DMA1_SM0AR(5)
#define DMA1_S6M0AR DMA1_SM0AR(6)
#define DMA1_S7M0AR DMA1_SM0AR(7)

#define DMA2_S0M0AR DMA2_SM0AR(0)
#define DMA2_S1M0AR DMA2_SM0AR(1)
#define DMA2_S2M0AR DMA2_SM0AR(2)
#define DMA2_S3M0AR DMA2_SM0AR(3)
#define DMA2_S4M0AR DMA2_SM0AR(4)
#define DMA2_S5M0AR DMA2_SM0AR(5)
#define DMA2_S6M0AR DMA2_SM0AR(6)
#define DMA2_S7M0AR DMA2_SM0AR(7)


#define DMA_SM1AR(port,n) (*(volatile void **) (DMA_STREAM((port), (n)) + 0x10))

#define DMA1_SM1AR(n) DMA_SM1AR(DMA1, (n))
#define DMA2_SM1AR(n) DMA_SM1AR(DMA2, (n))

#define DMA1_S0M1AR DMA1_SM1AR(0)
#define DMA1_S1M1AR DMA1_SM1AR(1)
#define DMA1_S2M1AR DMA1_SM1AR(2)
#define DMA1_S3M1AR DMA1_SM1AR(3)
#define DMA1_S4M1AR DMA1_SM1AR(4)
#define DMA1_S5M1AR DMA1_SM1AR(5)
#define DMA1_S6M1AR DMA1_SM1AR(6)
#define DMA1_S7M1AR DMA1_SM1AR(7)

#define DMA2_S0M1AR DMA2_SM1AR(0)
#define DMA2_S1M1AR DMA2_SM1AR(1)
#define DMA2_S2M1AR DMA2_SM1AR(2)
#define DMA2_S3M1AR DMA2_SM1AR(3)
#define DMA2_S4M1AR DMA2_SM1AR(4)
#define DMA2_S5M1AR DMA2_SM1AR(5)
#define DMA2_S6M1AR DMA2_SM1AR(6)
#define DMA2_S7M1AR DMA2_SM1AR(7)


#define DMA_SFCR(port,n) MMIO32(DMA_STREAM((port), (n)) + 0x14)
#define DMA1_SFCR(n) DMA_SFCR(DMA1, (n))
#define DMA2_SFCR(n) DMA_SFCR(DMA2, (n))

#define DMA1_S0FCR DMA1_SFCR(0)
#define DMA1_S1FCR DMA1_SFCR(1)
#define DMA1_S2FCR DMA1_SFCR(2)
#define DMA1_S3FCR DMA1_SFCR(3)
#define DMA1_S4FCR DMA1_SFCR(4)
#define DMA1_S5FCR DMA1_SFCR(5)
#define DMA1_S6FCR DMA1_SFCR(6)
#define DMA1_S7FCR DMA1_SFCR(7)

#define DMA2_S0FCR DMA2_SFCR(0)
#define DMA2_S1FCR DMA2_SFCR(1)
#define DMA2_S2FCR DMA2_SFCR(2)
#define DMA2_S3FCR DMA2_SFCR(3)
#define DMA2_S4FCR DMA2_SFCR(4)
#define DMA2_S5FCR DMA2_SFCR(5)
#define DMA2_S6FCR DMA2_SFCR(6)
#define DMA2_S7FCR DMA2_SFCR(7)
#define DMA_TCIF (1 << 5)

#define DMA_HTIF (1 << 4)

#define DMA_TEIF (1 << 3)

#define DMA_DMEIF (1 << 2)

#define DMA_FEIF (1 << 0)





#define DMA_ISR_OFFSET(stream) (6*((stream) & 0x01)+16*(((stream) & 0x02) >> 1))
#define DMA_ISR_FLAGS (DMA_TCIF | DMA_HTIF | DMA_TEIF | DMA_DMEIF | DMA_FEIF)

#define DMA_ISR_MASK(stream) (DMA_ISR_FLAGS << DMA_ISR_OFFSET(stream))



#define DMA_LISR_FEIF0 (1 << 0)
#define DMA_LISR_DMEIF0 (1 << 2)
#define DMA_LISR_TEIF0 (1 << 3)
#define DMA_LISR_HTIF0 (1 << 4)
#define DMA_LISR_TCIF0 (1 << 5)

#define DMA_LISR_FEIF1 (1 << 6)
#define DMA_LISR_DMEIF1 (1 << 8)
#define DMA_LISR_TEIF1 (1 << 9)
#define DMA_LISR_HTIF1 (1 << 10)
#define DMA_LISR_TCIF1 (1 << 11)

#define DMA_LISR_FEIF2 (1 << 16)
#define DMA_LISR_DMEIF2 (1 << 18)
#define DMA_LISR_TEIF2 (1 << 19)
#define DMA_LISR_HTIF2 (1 << 20)
#define DMA_LISR_TCIF2 (1 << 21)

#define DMA_LISR_FEIF3 (1 << 22)
#define DMA_LISR_DMEIF3 (1 << 24)
#define DMA_LISR_TEIF3 (1 << 25)
#define DMA_LISR_HTIF3 (1 << 26)
#define DMA_LISR_TCIF3 (1 << 27)



#define DMA_HISR_FEIF4 (1 << 0)
#define DMA_HISR_DMEIF4 (1 << 2)
#define DMA_HISR_TEIF4 (1 << 3)
#define DMA_HISR_HTIF4 (1 << 4)
#define DMA_HISR_TCIF4 (1 << 5)

#define DMA_HISR_FEIF5 (1 << 6)
#define DMA_HISR_DMEIF5 (1 << 8)
#define DMA_HISR_TEIF5 (1 << 9)
#define DMA_HISR_HTIF5 (1 << 10)
#define DMA_HISR_TCIF5 (1 << 11)

#define DMA_HISR_FEIF6 (1 << 16)
#define DMA_HISR_DMEIF6 (1 << 18)
#define DMA_HISR_TEIF6 (1 << 19)
#define DMA_HISR_HTIF6 (1 << 20)
#define DMA_HISR_TCIF6 (1 << 21)

#define DMA_HISR_FEIF7 (1 << 22)
#define DMA_HISR_DMEIF7 (1 << 24)
#define DMA_HISR_TEIF7 (1 << 25)
#define DMA_HISR_HTIF7 (1 << 26)
#define DMA_HISR_TCIF7 (1 << 27)



#define DMA_LIFCR_CFEIF0 (1 << 0)
#define DMA_LIFCR_CDMEIF0 (1 << 2)
#define DMA_LIFCR_CTEIF0 (1 << 3)
#define DMA_LIFCR_CHTIF0 (1 << 4)
#define DMA_LIFCR_CTCIF0 (1 << 5)

#define DMA_LIFCR_CFEIF1 (1 << 6)
#define DMA_LIFCR_CDMEIF1 (1 << 8)
#define DMA_LIFCR_CTEIF1 (1 << 9)
#define DMA_LIFCR_CHTIF1 (1 << 10)
#define DMA_LIFCR_CTCIF1 (1 << 11)

#define DMA_LIFCR_CFEIF2 (1 << 16)
#define DMA_LIFCR_CDMEIF2 (1 << 18)
#define DMA_LIFCR_CTEIF2 (1 << 19)
#define DMA_LIFCR_CHTIF2 (1 << 20)
#define DMA_LIFCR_CTCIF2 (1 << 21)

#define DMA_LIFCR_CFEIF3 (1 << 22)
#define DMA_LIFCR_CDMEIF3 (1 << 24)
#define DMA_LIFCR_CTEIF3 (1 << 25)
#define DMA_LIFCR_CHTIF3 (1 << 26)
#define DMA_LIFCR_CTCIF3 (1 << 27)



#define DMA_HIFCR_CFEIF4 (1 << 0)
#define DMA_HIFCR_CDMEIF4 (1 << 2)
#define DMA_HIFCR_CTEIF4 (1 << 3)
#define DMA_HIFCR_CHTIF4 (1 << 4)
#define DMA_HIFCR_CTCIF4 (1 << 5)

#define DMA_HIFCR_CFEIF5 (1 << 6)
#define DMA_HIFCR_CDMEIF5 (1 << 8)
#define DMA_HIFCR_CTEIF5 (1 << 9)
#define DMA_HIFCR_CHTIF5 (1 << 10)
#define DMA_HIFCR_CTCIF5 (1 << 11)

#define DMA_HIFCR_CFEIF6 (1 << 16)
#define DMA_HIFCR_CDMEIF6 (1 << 18)
#define DMA_HIFCR_CTEIF6 (1 << 19)
#define DMA_HIFCR_CHTIF6 (1 << 20)
#define DMA_HIFCR_CTCIF6 (1 << 21)

#define DMA_HIFCR_CFEIF7 (1 << 22)
#define DMA_HIFCR_CDMEIF7 (1 << 24)
#define DMA_HIFCR_CTEIF7 (1 << 25)
#define DMA_HIFCR_CHTIF7 (1 << 26)
#define DMA_HIFCR_CTCIF7 (1 << 27)




#define DMA_SxCR_EN (1 << 0)

#define DMA_SxCR_DMEIE (1 << 1)

#define DMA_SxCR_TEIE (1 << 2)

#define DMA_SxCR_HTIE (1 << 3)

#define DMA_SxCR_TCIE (1 << 4)

#define DMA_SxCR_PFCTRL (1 << 5)






#define DMA_SxCR_DIR_PERIPHERAL_TO_MEM (0 << 6)
#define DMA_SxCR_DIR_MEM_TO_PERIPHERAL (1 << 6)
#define DMA_SxCR_DIR_MEM_TO_MEM (2 << 6)

#define DMA_SxCR_DIR_SHIFT 6
#define DMA_SxCR_DIR_MASK (3 << 6)


#define DMA_SxCR_CIRC (1 << 8)

#define DMA_SxCR_PINC (1 << 9)

#define DMA_SxCR_MINC (1 << 10)






#define DMA_SxCR_PSIZE_8BIT (0 << 11)
#define DMA_SxCR_PSIZE_16BIT (1 << 11)
#define DMA_SxCR_PSIZE_32BIT (2 << 11)

#define DMA_SxCR_PSIZE_SHIFT 11
#define DMA_SxCR_PSIZE_MASK (3 << 11)






#define DMA_SxCR_MSIZE_8BIT (0 << 13)
#define DMA_SxCR_MSIZE_16BIT (1 << 13)
#define DMA_SxCR_MSIZE_32BIT (2 << 13)

#define DMA_SxCR_MSIZE_SHIFT 13
#define DMA_SxCR_MSIZE_MASK (3 << 13)


#define DMA_SxCR_PINCOS (1 << 15)






#define DMA_SxCR_PL_LOW (0 << 16)
#define DMA_SxCR_PL_MEDIUM (1 << 16)
#define DMA_SxCR_PL_HIGH (2 << 16)
#define DMA_SxCR_PL_VERY_HIGH (3 << 16)

#define DMA_SxCR_PL_SHIFT 16
#define DMA_SxCR_PL_MASK (3 << 16)


#define DMA_SxCR_DBM (1 << 18)

#define DMA_SxCR_CT (1 << 19)
#define DMA_SxCR_PBURST_SINGLE (0 << 21)
#define DMA_SxCR_PBURST_INCR4 (1 << 21)
#define DMA_SxCR_PBURST_INCR8 (2 << 21)
#define DMA_SxCR_PBURST_INCR16 (3 << 21)

#define DMA_SxCR_PBURST_SHIFT 21
#define DMA_SxCR_PBURST_MASK (3 << 21)






#define DMA_SxCR_MBURST_SINGLE (0 << 23)
#define DMA_SxCR_MBURST_INCR4 (1 << 23)
#define DMA_SxCR_MBURST_INCR8 (2 << 23)
#define DMA_SxCR_MBURST_INCR16 (3 << 23)

#define DMA_SxCR_MBURST_SHIFT 23
#define DMA_SxCR_MBURST_MASK (3 << 23)






#define DMA_SxCR_CHSEL_0 (0 << DMA_SxCR_CHSEL_SHIFT)
#define DMA_SxCR_CHSEL_1 (1 << DMA_SxCR_CHSEL_SHIFT)
#define DMA_SxCR_CHSEL_2 (2 << DMA_SxCR_CHSEL_SHIFT)
#define DMA_SxCR_CHSEL_3 (3 << DMA_SxCR_CHSEL_SHIFT)
#define DMA_SxCR_CHSEL_4 (4 << DMA_SxCR_CHSEL_SHIFT)
#define DMA_SxCR_CHSEL_5 (5 << DMA_SxCR_CHSEL_SHIFT)
#define DMA_SxCR_CHSEL_6 (6 << DMA_SxCR_CHSEL_SHIFT)
#define DMA_SxCR_CHSEL_7 (7 << DMA_SxCR_CHSEL_SHIFT)

#define DMA_SxCR_CHSEL_SHIFT 25
#define DMA_SxCR_CHSEL_MASK (7 << 25)
#define DMA_SxCR_CHSEL(n) ((n) << DMA_SxCR_CHSEL_SHIFT)
#define DMA_SxFCR_FTH_1_4_FULL (0 << 0)
#define DMA_SxFCR_FTH_2_4_FULL (1 << 0)
#define DMA_SxFCR_FTH_3_4_FULL (2 << 0)
#define DMA_SxFCR_FTH_4_4_FULL (3 << 0)

#define DMA_SxFCR_FTH_SHIFT 0
#define DMA_SxFCR_FTH_MASK (3 << 0)


#define DMA_SxFCR_DMDIS (1 << 2)






#define DMA_SxFCR_FS_LT_1_4_FULL (0 << 0)
#define DMA_SxFCR_FS_LT_2_4_FULL (1 << 0)
#define DMA_SxFCR_FS_LT_3_4_FULL (2 << 0)
#define DMA_SxFCR_FS_LT_4_4_FULL (3 << 0)
#define DMA_SxFCR_FS_FULL (4 << 3)
#define DMA_SxFCR_FS_EMPTY (5 << 3)

#define DMA_SxFCR_FS_SHIFT 3
#define DMA_SxFCR_FS_MASK (7 << 3)




#define DMA_SxFCR_FEIE (1 << 7)













void dma_stream_reset(uint32_t dma, uint8_t stream);
void dma_clear_interrupt_flags(uint32_t dma, uint8_t stream,
          uint32_t interrupts);

_Bool 
    dma_get_interrupt_flag(uint32_t dma, uint8_t stream, uint32_t interrupt);
void dma_set_transfer_mode(uint32_t dma, uint8_t stream, uint32_t direction);
void dma_set_priority(uint32_t dma, uint8_t stream, uint32_t prio);
void dma_set_memory_size(uint32_t dma, uint8_t stream, uint32_t mem_size);
void dma_set_peripheral_size(uint32_t dma, uint8_t stream,
        uint32_t peripheral_size);
void dma_enable_memory_increment_mode(uint32_t dma, uint8_t stream);
void dma_disable_memory_increment_mode(uint32_t dma, uint8_t stream);
void dma_enable_peripheral_increment_mode(uint32_t dma, uint8_t stream);
void dma_disable_peripheral_increment_mode(uint32_t dma, uint8_t stream);
void dma_enable_fixed_peripheral_increment_mode(uint32_t dma, uint8_t stream);
void dma_enable_circular_mode(uint32_t dma, uint8_t stream);
void dma_channel_select(uint32_t dma, uint8_t stream, uint32_t channel);
void dma_set_memory_burst(uint32_t dma, uint8_t stream, uint32_t burst);
void dma_set_peripheral_burst(uint32_t dma, uint8_t stream, uint32_t burst);
void dma_set_initial_target(uint32_t dma, uint8_t stream, uint8_t memory);
uint8_t dma_get_target(uint32_t dma, uint8_t stream);
void dma_enable_double_buffer_mode(uint32_t dma, uint8_t stream);
void dma_disable_double_buffer_mode(uint32_t dma, uint8_t stream);
void dma_set_peripheral_flow_control(uint32_t dma, uint8_t stream);
void dma_set_dma_flow_control(uint32_t dma, uint8_t stream);
void dma_enable_transfer_error_interrupt(uint32_t dma, uint8_t stream);
void dma_disable_transfer_error_interrupt(uint32_t dma, uint8_t stream);
void dma_enable_half_transfer_interrupt(uint32_t dma, uint8_t stream);
void dma_disable_half_transfer_interrupt(uint32_t dma, uint8_t stream);
void dma_enable_transfer_complete_interrupt(uint32_t dma, uint8_t stream);
void dma_disable_transfer_complete_interrupt(uint32_t dma, uint8_t stream);
uint32_t dma_fifo_status(uint32_t dma, uint8_t stream);
void dma_enable_direct_mode_error_interrupt(uint32_t dma, uint8_t stream);
void dma_disable_direct_mode_error_interrupt(uint32_t dma, uint8_t stream);
void dma_enable_fifo_error_interrupt(uint32_t dma, uint8_t stream);
void dma_disable_fifo_error_interrupt(uint32_t dma, uint8_t stream);
void dma_enable_direct_mode(uint32_t dma, uint8_t stream);
void dma_enable_fifo_mode(uint32_t dma, uint8_t stream);
void dma_set_fifo_threshold(uint32_t dma, uint8_t stream, uint32_t threshold);
void dma_enable_stream(uint32_t dma, uint8_t stream);
void dma_disable_stream(uint32_t dma, uint8_t stream);
void dma_set_peripheral_address(uint32_t dma, uint8_t stream, uint32_t address);
void dma_set_memory_address(uint32_t dma, uint8_t stream, uint32_t address);
void dma_set_memory_address_1(uint32_t dma, uint8_t stream, uint32_t address);
uint16_t dma_get_number_of_data(uint32_t dma, uint8_t stream);
void dma_set_number_of_data(uint32_t dma, uint8_t stream, uint16_t number);


void dma_stream_reset(uint32_t dma, uint8_t stream)
{

 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) &= ~(1 << 0);

 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) = 0;

 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x04)) = 0;

 (*(volatile void **) ((((dma)) + 0x10 + (24 * ((stream)))) + 0x08)) = 0;
 (*(volatile void **) ((((dma)) + 0x10 + (24 * ((stream)))) + 0x0c)) = 0;
 (*(volatile void **) ((((dma)) + 0x10 + (24 * ((stream)))) + 0x10)) = 0;

 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x14)) = 0x21;

 uint32_t mask = (((1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 0)) << (6*((stream) & 0x01)+16*(((stream) & 0x02) >> 1)));
 if (stream < 4) {
  (*(volatile uint32_t *)((dma) + 0x08)) |= mask;
 } else {
  (*(volatile uint32_t *)((dma) + 0x0C)) |= mask;
 }
}
void dma_clear_interrupt_flags(uint32_t dma, uint8_t stream,
          uint32_t interrupts)
{

 uint32_t flags = (interrupts << (6*((stream) & 0x01)+16*(((stream) & 0x02) >> 1)));



 if (stream < 4) {
  (*(volatile uint32_t *)((dma) + 0x08)) = flags;
 } else {
  (*(volatile uint32_t *)((dma) + 0x0C)) = flags;
 }
}

_Bool 
    dma_get_interrupt_flag(uint32_t dma, uint8_t stream, uint32_t interrupt)
{



 uint32_t flag = (interrupt << (6*((stream) & 0x01)+16*(((stream) & 0x02) >> 1)));

 if (stream < 4) {
  return (((*(volatile uint32_t *)((dma) + 0x00)) & flag) > 0);
 } else {
  return (((*(volatile uint32_t *)((dma) + 0x04)) & flag) > 0);
 }
}
void dma_set_transfer_mode(uint32_t dma, uint8_t stream, uint32_t direction)
{
 uint32_t reg32 = ((*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) & ~(3 << 6));




 if (direction == (2 << 6)) {
  reg32 &= ~((1 << 8) | (1 << 18));
 }

 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) = (reg32 | direction);
}
void dma_set_priority(uint32_t dma, uint8_t stream, uint32_t prio)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) &= ~((3 << 16));
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) |= prio;
}
void dma_set_memory_size(uint32_t dma, uint8_t stream, uint32_t mem_size)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) &= ~((3 << 13));
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) |= mem_size;
}
void dma_set_peripheral_size(uint32_t dma, uint8_t stream,
        uint32_t peripheral_size)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) &= ~((3 << 11));
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) |= peripheral_size;
}
void dma_enable_memory_increment_mode(uint32_t dma, uint8_t stream)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) |= (1 << 10);
}
void dma_disable_memory_increment_mode(uint32_t dma, uint8_t stream)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) &= ~(1 << 10);
}
void dma_enable_peripheral_increment_mode(uint32_t dma, uint8_t stream)
{
 uint32_t reg32 = ((*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) | (1 << 9));
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) = (reg32 & ~(1 << 15));
}
void dma_disable_peripheral_increment_mode(uint32_t dma, uint8_t stream)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) &= ~(1 << 9);
}
void dma_enable_fixed_peripheral_increment_mode(uint32_t dma, uint8_t stream)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) |= ((1 << 9) | (1 << 15));
}
void dma_enable_circular_mode(uint32_t dma, uint8_t stream)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) |= (1 << 8);
}
void dma_channel_select(uint32_t dma, uint8_t stream, uint32_t channel)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) |= channel;
}
void dma_set_memory_burst(uint32_t dma, uint8_t stream, uint32_t burst)
{
 uint32_t reg32 = ((*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) & ~(3 << 23));
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) = (reg32 | burst);
}
void dma_set_peripheral_burst(uint32_t dma, uint8_t stream, uint32_t burst)
{
 uint32_t reg32 = ((*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) & ~(3 << 21));
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) = (reg32 | burst);
}
void dma_set_initial_target(uint32_t dma, uint8_t stream, uint8_t memory)
{
 uint32_t reg32 = ((*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) & ~(1 << 19));
 if (memory == 1) {
  reg32 |= (1 << 19);
 }

 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) = reg32;
}
uint8_t dma_get_target(uint32_t dma, uint8_t stream)
{
 if ((*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) & (1 << 19)) {
  return 1;
 }

 return 0;
}
void dma_enable_double_buffer_mode(uint32_t dma, uint8_t stream)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) |= (1 << 18);
}
void dma_disable_double_buffer_mode(uint32_t dma, uint8_t stream)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) &= ~(1 << 18);
}
void dma_set_peripheral_flow_control(uint32_t dma, uint8_t stream)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) |= (1 << 5);
}
void dma_set_dma_flow_control(uint32_t dma, uint8_t stream)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) &= ~(1 << 5);
}
void dma_enable_transfer_error_interrupt(uint32_t dma, uint8_t stream)
{
 dma_clear_interrupt_flags(dma, stream, (1 << 3));
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) |= (1 << 2);
}
void dma_disable_transfer_error_interrupt(uint32_t dma, uint8_t stream)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) &= ~(1 << 2);
}
void dma_enable_half_transfer_interrupt(uint32_t dma, uint8_t stream)
{
 dma_clear_interrupt_flags(dma, stream, (1 << 4));
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) |= (1 << 3);
}
void dma_disable_half_transfer_interrupt(uint32_t dma, uint8_t stream)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) &= ~(1 << 3);
}
void dma_enable_transfer_complete_interrupt(uint32_t dma, uint8_t stream)
{
 dma_clear_interrupt_flags(dma, stream, (1 << 5));
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) |= (1 << 4);
}
void dma_disable_transfer_complete_interrupt(uint32_t dma, uint8_t stream)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) &= ~(1 << 4);
}
void dma_enable_direct_mode_error_interrupt(uint32_t dma, uint8_t stream)
{
 dma_clear_interrupt_flags(dma, stream, (1 << 2));
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) |= (1 << 1);
}
void dma_disable_direct_mode_error_interrupt(uint32_t dma, uint8_t stream)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) &= ~(1 << 1);
}
void dma_enable_fifo_error_interrupt(uint32_t dma, uint8_t stream)
{
 dma_clear_interrupt_flags(dma, stream, (1 << 0));
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x14)) |= (1 << 7);
}
void dma_disable_fifo_error_interrupt(uint32_t dma, uint8_t stream)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x14)) &= ~(1 << 7);
}
uint32_t dma_fifo_status(uint32_t dma, uint8_t stream)
{
 return (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x14)) & (7 << 3);
}
void dma_enable_direct_mode(uint32_t dma, uint8_t stream)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x14)) &= ~(1 << 2);
}
void dma_enable_fifo_mode(uint32_t dma, uint8_t stream)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x14)) |= (1 << 2);
}
void dma_set_fifo_threshold(uint32_t dma, uint8_t stream, uint32_t threshold)
{
 uint32_t reg32 = ((*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x14)) & ~(3 << 0));
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x14)) = (reg32 | threshold);
}
void dma_enable_stream(uint32_t dma, uint8_t stream)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) |= (1 << 0);
}
void dma_disable_stream(uint32_t dma, uint8_t stream)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) &= ~(1 << 0);
}
void dma_set_peripheral_address(uint32_t dma, uint8_t stream, uint32_t address)
{
 if (!((*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00)) & (1 << 0))) {
  (*(volatile void **) ((((dma)) + 0x10 + (24 * ((stream)))) + 0x08)) = (uint32_t *) address;
 }
}
void dma_set_memory_address(uint32_t dma, uint8_t stream, uint32_t address)
{
 uint32_t reg32 = (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00));
 if (!(reg32 & (1 << 0)) ||
      ((reg32 & (1 << 19)) && (reg32 & (1 << 18)))) {
  (*(volatile void **) ((((dma)) + 0x10 + (24 * ((stream)))) + 0x0c)) = (uint32_t *) address;
 }
}
void dma_set_memory_address_1(uint32_t dma, uint8_t stream, uint32_t address)
{
 uint32_t reg32 = (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x00));
 if (!(reg32 & (1 << 0)) ||
      (!(reg32 & (1 << 19)) && (reg32 & (1 << 18)))) {
  (*(volatile void **) ((((dma)) + 0x10 + (24 * ((stream)))) + 0x10)) = (uint32_t *) address;
 }
}
uint16_t dma_get_number_of_data(uint32_t dma, uint8_t stream)
{
 return (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x04));
}
void dma_set_number_of_data(uint32_t dma, uint8_t stream, uint16_t number)
{
 (*(volatile uint32_t *)((((dma)) + 0x10 + (24 * ((stream)))) + 0x04)) = number;
}
