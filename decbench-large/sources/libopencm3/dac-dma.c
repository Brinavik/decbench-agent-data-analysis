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
#define LIBOPENCM3_RCC_H 

#define LIBOPENCM3_PWR_H 

#define LIBOPENCM3_PWR_COMMON_V1_H 






#define PWR_CR MMIO32(POWER_CONTROL_BASE + 0x00)


#define PWR_CSR MMIO32(POWER_CONTROL_BASE + 0x04)






#define PWR_CR_DBP (1 << 8)


#define PWR_CR_PLS_LSB 5




#define PWR_CR_PLS_2V2 (0x0 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V3 (0x1 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V4 (0x2 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V5 (0x3 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V6 (0x4 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V7 (0x5 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V8 (0x6 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V9 (0x7 << PWR_CR_PLS_LSB)

#define PWR_CR_PLS_MASK (0x7 << PWR_CR_PLS_LSB)


#define PWR_CR_PVDE (1 << 4)


#define PWR_CR_CSBF (1 << 3)


#define PWR_CR_CWUF (1 << 2)


#define PWR_CR_PDDS (1 << 1)


#define PWR_CR_LPDS (1 << 0)






#define PWR_CSR_EWUP (1 << 8)




#define PWR_CSR_PVDO (1 << 2)


#define PWR_CSR_SBF (1 << 1)


#define PWR_CSR_WUF (1 << 0)






void pwr_disable_backup_domain_write_protect(void);
void pwr_enable_backup_domain_write_protect(void);
void pwr_enable_power_voltage_detect(uint32_t pvd_level);
void pwr_disable_power_voltage_detect(void);
void pwr_clear_standby_flag(void);
void pwr_clear_wakeup_flag(void);
void pwr_set_standby_mode(void);
void pwr_set_stop_mode(void);
void pwr_voltage_regulator_on_in_stop(void);
void pwr_voltage_regulator_low_power_in_stop(void);
void pwr_enable_wakeup_pin(void);
void pwr_disable_wakeup_pin(void);

_Bool 
    pwr_voltage_high(void);

_Bool 
    pwr_get_standby_flag(void);

_Bool 
    pwr_get_wakeup_flag(void);


#define PWR_CR_VOS_SHIFT 14
#define PWR_CR_VOS_MASK 0x3


#define PWR_CR_ADCDC1 (1 << 13)


#define PWR_CR_MRLVDS (1 << 11)
#define PWR_CR_MRUDS PWR_CR_MRLVDS


#define PWR_CR_LPLVDS (1 << 10)
#define PWR_CR_LPUDS PWR_CR_LPLVDS


#define PWR_CR_FPDS (1 << 9)




#define PWR_CSR_VOSRDY (1 << 14)


#define PWR_CSR_BRE (1 << 9)


#define PWR_CSR_BRR (1 << 3)



enum pwr_vos_scale {
 PWR_SCALE1 = 0x3,
 PWR_SCALE2 = 0x2,
 PWR_SCALE3 = 0x1,
};



void pwr_set_vos_scale(enum pwr_vos_scale scale);







#define RCC_CR MMIO32(RCC_BASE + 0x00)

#define RCC_PLLCFGR MMIO32(RCC_BASE + 0x04)

#define RCC_CFGR MMIO32(RCC_BASE + 0x08)

#define RCC_CIR MMIO32(RCC_BASE + 0x0c)

#define RCC_AHB1RSTR MMIO32(RCC_BASE + 0x10)

#define RCC_AHB2RSTR MMIO32(RCC_BASE + 0x14)

#define RCC_AHB3RSTR MMIO32(RCC_BASE + 0x18)


#define RCC_APB1RSTR MMIO32(RCC_BASE + 0x20)

#define RCC_APB2RSTR MMIO32(RCC_BASE + 0x24)



#define RCC_AHB1ENR MMIO32(RCC_BASE + 0x30)

#define RCC_AHB2ENR MMIO32(RCC_BASE + 0x34)

#define RCC_AHB3ENR MMIO32(RCC_BASE + 0x38)


#define RCC_APB1ENR MMIO32(RCC_BASE + 0x40)

#define RCC_APB2ENR MMIO32(RCC_BASE + 0x44)



#define RCC_AHB1LPENR MMIO32(RCC_BASE + 0x50)

#define RCC_AHB2LPENR MMIO32(RCC_BASE + 0x54)

#define RCC_AHB3LPENR MMIO32(RCC_BASE + 0x58)


#define RCC_APB1LPENR MMIO32(RCC_BASE + 0x60)

#define RCC_APB2LPENR MMIO32(RCC_BASE + 0x64)



#define RCC_BDCR MMIO32(RCC_BASE + 0x70)

#define RCC_CSR MMIO32(RCC_BASE + 0x74)



#define RCC_SSCGR MMIO32(RCC_BASE + 0x80)

#define RCC_PLLI2SCFGR MMIO32(RCC_BASE + 0x84)

#define RCC_PLLSAICFGR MMIO32(RCC_BASE + 0x88)

#define RCC_DCKCFGR MMIO32(RCC_BASE + 0x8C)

#define RCC_CKGATENR MMIO32(RCC_BASE + 0x90)

#define RCC_DCKCFGR2 MMIO32(RCC_BASE + 0x94)






#define RCC_CR_PLLSAIRDY (1 << 29)
#define RCC_CR_PLLSAION (1 << 28)
#define RCC_CR_PLLI2SRDY (1 << 27)
#define RCC_CR_PLLI2SON (1 << 26)
#define RCC_CR_PLLRDY (1 << 25)
#define RCC_CR_PLLON (1 << 24)
#define RCC_CR_CSSON (1 << 19)
#define RCC_CR_HSEBYP (1 << 18)
#define RCC_CR_HSERDY (1 << 17)
#define RCC_CR_HSEON (1 << 16)


#define RCC_CR_HSITRIM_SHIFT 3
#define RCC_CR_HSITRIM_MASK 0x1f
#define RCC_CR_HSIRDY (1 << 1)
#define RCC_CR_HSION (1 << 0)







#define RCC_PLLCFGR_PLLR_SHIFT 28
#define RCC_PLLCFGR_PLLR_MASK 0x7

#define RCC_PLLCFGR_PLLQ_SHIFT 24
#define RCC_PLLCFGR_PLLQ_MASK 0xf
#define RCC_PLLCFGR_PLLSRC (1 << 22)

#define RCC_PLLCFGR_PLLP_SHIFT 16
#define RCC_PLLCFGR_PLLP_MASK 0x3

#define RCC_PLLCFGR_PLLN_SHIFT 6
#define RCC_PLLCFGR_PLLN_MASK 0x1ff

#define RCC_PLLCFGR_PLLM_SHIFT 0
#define RCC_PLLCFGR_PLLM_MASK 0x3f







#define RCC_CFGR_MCO2_SHIFT 30
#define RCC_CFGR_MCO2_MASK 0x3
#define RCC_CFGR_MCO2_SYSCLK 0x0
#define RCC_CFGR_MCO2_PLLI2S 0x1
#define RCC_CFGR_MCO2_HSE 0x2
#define RCC_CFGR_MCO2_PLL 0x3


#define RCC_CFGR_MCO2PRE_SHIFT 27
#define RCC_CFGR_MCO2PRE_MASK 0x7
#define RCC_CFGR_MCO1PRE_SHIFT 24
#define RCC_CFGR_MCO1PRE_MASK 0x7
#define RCC_CFGR_MCOPRE_DIV_NONE 0x0
#define RCC_CFGR_MCOPRE_DIV_2 0x4
#define RCC_CFGR_MCOPRE_DIV_3 0x5
#define RCC_CFGR_MCOPRE_DIV_4 0x6
#define RCC_CFGR_MCOPRE_DIV_5 0x7


#define RCC_CFGR_PLLSRC_HSI_CLK 0x0
#define RCC_CFGR_PLLSRC_HSE_CLK 0x1


#define RCC_CFGR_I2SSRC (1 << 23)


#define RCC_CFGR_MCO1_SHIFT 21
#define RCC_CFGR_MCO1_MASK 0x3
#define RCC_CFGR_MCO1_HSI 0x0
#define RCC_CFGR_MCO1_LSE 0x1
#define RCC_CFGR_MCO1_HSE 0x2
#define RCC_CFGR_MCO1_PLL 0x3
#define RCC_CFGR_MCO_SHIFT RCC_CFGR_MCO1_SHIFT
#define RCC_CFGR_MCO_MASK RCC_CFGR_MCO1_MASK


#define RCC_CFGR_RTCPRE_SHIFT 16
#define RCC_CFGR_RTCPRE_MASK 0x1f

#define RCC_CFGR_PPRE2_SHIFT 13
#define RCC_CFGR_PPRE2_MASK 0x7
#define RCC_CFGR_PPRE1_SHIFT 10
#define RCC_CFGR_PPRE1_MASK 0x7




#define RCC_CFGR_PPRE_NODIV 0x0
#define RCC_CFGR_PPRE_DIV2 0x4
#define RCC_CFGR_PPRE_DIV4 0x5
#define RCC_CFGR_PPRE_DIV8 0x6
#define RCC_CFGR_PPRE_DIV16 0x7


#define RCC_CFGR_HPRE_SHIFT 4
#define RCC_CFGR_HPRE_MASK 0xf


#define RCC_CFGR_HPRE_NODIV 0x0
#define RCC_CFGR_HPRE_DIV2 (0x8 + 0)
#define RCC_CFGR_HPRE_DIV4 (0x8 + 1)
#define RCC_CFGR_HPRE_DIV8 (0x8 + 2)
#define RCC_CFGR_HPRE_DIV16 (0x8 + 3)
#define RCC_CFGR_HPRE_DIV64 (0x8 + 4)
#define RCC_CFGR_HPRE_DIV128 (0x8 + 5)
#define RCC_CFGR_HPRE_DIV256 (0x8 + 6)
#define RCC_CFGR_HPRE_DIV512 (0x8 + 7)



#define RCC_CFGR_SWS_SHIFT 2
#define RCC_CFGR_SWS_MASK 0x3
#define RCC_CFGR_SWS_HSI 0x0
#define RCC_CFGR_SWS_HSE 0x1
#define RCC_CFGR_SWS_PLL 0x2


#define RCC_CFGR_SW_SHIFT 0
#define RCC_CFGR_SW_HSI 0x0
#define RCC_CFGR_SW_HSE 0x1
#define RCC_CFGR_SW_PLL 0x2







#define RCC_CFGR_PPRE_DIV_NONE 0x0
#define RCC_CFGR_PPRE_DIV_2 0x4
#define RCC_CFGR_PPRE_DIV_4 0x5
#define RCC_CFGR_PPRE_DIV_8 0x6
#define RCC_CFGR_PPRE_DIV_16 0x7

#define RCC_CFGR_HPRE_DIV_NONE 0x0
#define RCC_CFGR_HPRE_DIV_2 (0x8 + 0)
#define RCC_CFGR_HPRE_DIV_4 (0x8 + 1)
#define RCC_CFGR_HPRE_DIV_8 (0x8 + 2)
#define RCC_CFGR_HPRE_DIV_16 (0x8 + 3)
#define RCC_CFGR_HPRE_DIV_64 (0x8 + 4)
#define RCC_CFGR_HPRE_DIV_128 (0x8 + 5)
#define RCC_CFGR_HPRE_DIV_256 (0x8 + 6)
#define RCC_CFGR_HPRE_DIV_512 (0x8 + 7)







#define RCC_CIR_CSSC (1 << 23)


#define RCC_CIR_PLLSAIRDYC (1 << 22)
#define RCC_CIR_PLLI2SRDYC (1 << 21)
#define RCC_CIR_PLLRDYC (1 << 20)
#define RCC_CIR_HSERDYC (1 << 19)
#define RCC_CIR_HSIRDYC (1 << 18)
#define RCC_CIR_LSERDYC (1 << 17)
#define RCC_CIR_LSIRDYC (1 << 16)


#define RCC_CIR_PLLSAIRDYIE (1 << 14)
#define RCC_CIR_PLLI2SRDYIE (1 << 13)
#define RCC_CIR_PLLRDYIE (1 << 12)
#define RCC_CIR_HSERDYIE (1 << 11)
#define RCC_CIR_HSIRDYIE (1 << 10)
#define RCC_CIR_LSERDYIE (1 << 9)
#define RCC_CIR_LSIRDYIE (1 << 8)


#define RCC_CIR_CSSF (1 << 7)


#define RCC_CIR_PLLSAIRDYF (1 << 6)
#define RCC_CIR_PLLI2SRDYF (1 << 5)
#define RCC_CIR_PLLRDYF (1 << 4)
#define RCC_CIR_HSERDYF (1 << 3)
#define RCC_CIR_HSIRDYF (1 << 2)
#define RCC_CIR_LSERDYF (1 << 1)
#define RCC_CIR_LSIRDYF (1 << 0)






#define RCC_AHB1RSTR_OTGHSRST (1 << 29)
#define RCC_AHB1RSTR_ETHMACRST (1 << 25)
#define RCC_AHB1RSTR_DMA2DRST (1 << 23)
#define RCC_AHB1RSTR_DMA2RST (1 << 22)
#define RCC_AHB1RSTR_DMA1RST (1 << 21)
#define RCC_AHB1RSTR_CRCRST (1 << 12)
#define RCC_AHB1RSTR_GPIOKRST (1 << 10)
#define RCC_AHB1RSTR_GPIOJRST (1 << 9)
#define RCC_AHB1RSTR_GPIOIRST (1 << 8)
#define RCC_AHB1RSTR_GPIOHRST (1 << 7)
#define RCC_AHB1RSTR_GPIOGRST (1 << 6)
#define RCC_AHB1RSTR_GPIOFRST (1 << 5)
#define RCC_AHB1RSTR_GPIOERST (1 << 4)
#define RCC_AHB1RSTR_GPIODRST (1 << 3)
#define RCC_AHB1RSTR_GPIOCRST (1 << 2)
#define RCC_AHB1RSTR_GPIOBRST (1 << 1)
#define RCC_AHB1RSTR_GPIOARST (1 << 0)






#define RCC_AHB1RSTR_IOPKRST RCC_AHB1RSTR_GPIOKRST
#define RCC_AHB1RSTR_IOPJRST RCC_AHB1RSTR_GPIOJRST
#define RCC_AHB1RSTR_IOPIRST RCC_AHB1RSTR_GPIOIRST
#define RCC_AHB1RSTR_IOPHRST RCC_AHB1RSTR_GPIOHRST
#define RCC_AHB1RSTR_IOPGRST RCC_AHB1RSTR_GPIOGRST
#define RCC_AHB1RSTR_IOPFRST RCC_AHB1RSTR_GPIOFRST
#define RCC_AHB1RSTR_IOPERST RCC_AHB1RSTR_GPIOERST
#define RCC_AHB1RSTR_IOPDRST RCC_AHB1RSTR_GPIODRST
#define RCC_AHB1RSTR_IOPCRST RCC_AHB1RSTR_GPIOCRST
#define RCC_AHB1RSTR_IOPBRST RCC_AHB1RSTR_GPIOBRST
#define RCC_AHB1RSTR_IOPARST RCC_AHB1RSTR_GPIOARST




#define RCC_AHB2RSTR_OTGFSRST (1 << 7)
#define RCC_AHB2RSTR_RNGRST (1 << 6)
#define RCC_AHB2RSTR_HASHRST (1 << 5)
#define RCC_AHB2RSTR_CRYPRST (1 << 4)
#define RCC_AHB2RSTR_DCMIRST (1 << 0)




#define RCC_AHB3RSTR_QSPIRST (1 << 1)
#define RCC_AHB3RSTR_FSMCRST (1 << 0)





#define RCC_APB1RSTR_UART8RST (1 << 31)
#define RCC_APB1RSTR_UART7RST (1 << 30)
#define RCC_APB1RSTR_DACRST (1 << 29)
#define RCC_APB1RSTR_PWRRST (1 << 28)
#define RCC_APB1RSTR_CAN2RST (1 << 26)
#define RCC_APB1RSTR_CAN1RST (1 << 25)
#define RCC_APB1RSTR_I2C3RST (1 << 23)
#define RCC_APB1RSTR_I2C2RST (1 << 22)
#define RCC_APB1RSTR_I2C1RST (1 << 21)
#define RCC_APB1RSTR_UART5RST (1 << 20)
#define RCC_APB1RSTR_UART4RST (1 << 19)
#define RCC_APB1RSTR_USART3RST (1 << 18)
#define RCC_APB1RSTR_USART2RST (1 << 17)
#define RCC_APB1RSTR_SPI3RST (1 << 15)
#define RCC_APB1RSTR_SPI2RST (1 << 14)
#define RCC_APB1RSTR_WWDGRST (1 << 11)
#define RCC_APB1RSTR_TIM14RST (1 << 8)
#define RCC_APB1RSTR_TIM13RST (1 << 7)
#define RCC_APB1RSTR_TIM12RST (1 << 6)
#define RCC_APB1RSTR_TIM7RST (1 << 5)
#define RCC_APB1RSTR_TIM6RST (1 << 4)
#define RCC_APB1RSTR_TIM5RST (1 << 3)
#define RCC_APB1RSTR_TIM4RST (1 << 2)
#define RCC_APB1RSTR_TIM3RST (1 << 1)
#define RCC_APB1RSTR_TIM2RST (1 << 0)




#define RCC_APB2RSTR_DSIRST (1 << 27)
#define RCC_APB2RSTR_LTDCRST (1 << 26)
#define RCC_APB2RSTR_SAI1RST (1 << 22)
#define RCC_APB2RSTR_SPI6RST (1 << 21)
#define RCC_APB2RSTR_SPI5RST (1 << 20)
#define RCC_APB2RSTR_TIM11RST (1 << 18)
#define RCC_APB2RSTR_TIM10RST (1 << 17)
#define RCC_APB2RSTR_TIM9RST (1 << 16)
#define RCC_APB2RSTR_SYSCFGRST (1 << 14)
#define RCC_APB2RSTR_SPI4RST (1 << 13)
#define RCC_APB2RSTR_SPI1RST (1 << 12)
#define RCC_APB2RSTR_SDIORST (1 << 11)
#define RCC_APB2RSTR_ADCRST (1 << 8)
#define RCC_APB2RSTR_USART6RST (1 << 5)
#define RCC_APB2RSTR_USART1RST (1 << 4)
#define RCC_APB2RSTR_TIM8RST (1 << 1)
#define RCC_APB2RSTR_TIM1RST (1 << 0)






#define RCC_AHB1ENR_OTGHSULPIEN (1 << 30)
#define RCC_AHB1ENR_OTGHSEN (1 << 29)
#define RCC_AHB1ENR_ETHMACPTPEN (1 << 28)
#define RCC_AHB1ENR_ETHMACRXEN (1 << 27)
#define RCC_AHB1ENR_ETHMACTXEN (1 << 26)
#define RCC_AHB1ENR_ETHMACEN (1 << 25)
#define RCC_AHB1ENR_DMA2DEN (1 << 23)
#define RCC_AHB1ENR_DMA2EN (1 << 22)
#define RCC_AHB1ENR_DMA1EN (1 << 21)
#define RCC_AHB1ENR_CCMDATARAMEN (1 << 20)
#define RCC_AHB1ENR_BKPSRAMEN (1 << 18)
#define RCC_AHB1ENR_CRCEN (1 << 12)
#define RCC_AHB1ENR_GPIOKEN (1 << 10)
#define RCC_AHB1ENR_GPIOJEN (1 << 9)
#define RCC_AHB1ENR_GPIOIEN (1 << 8)
#define RCC_AHB1ENR_GPIOHEN (1 << 7)
#define RCC_AHB1ENR_GPIOGEN (1 << 6)
#define RCC_AHB1ENR_GPIOFEN (1 << 5)
#define RCC_AHB1ENR_GPIOEEN (1 << 4)
#define RCC_AHB1ENR_GPIODEN (1 << 3)
#define RCC_AHB1ENR_GPIOCEN (1 << 2)
#define RCC_AHB1ENR_GPIOBEN (1 << 1)
#define RCC_AHB1ENR_GPIOAEN (1 << 0)






#define RCC_AHB1ENR_IOPKEN RCC_AHB1ENR_GPIOKEN
#define RCC_AHB1ENR_IOPJEN RCC_AHB1ENR_GPIOJEN
#define RCC_AHB1ENR_IOPIEN RCC_AHB1ENR_GPIOIEN
#define RCC_AHB1ENR_IOPHEN RCC_AHB1ENR_GPIOHEN
#define RCC_AHB1ENR_IOPGEN RCC_AHB1ENR_GPIOGEN
#define RCC_AHB1ENR_IOPFEN RCC_AHB1ENR_GPIOFEN
#define RCC_AHB1ENR_IOPEEN RCC_AHB1ENR_GPIOEEN
#define RCC_AHB1ENR_IOPDEN RCC_AHB1ENR_GPIODEN
#define RCC_AHB1ENR_IOPCEN RCC_AHB1ENR_GPIOCEN
#define RCC_AHB1ENR_IOPBEN RCC_AHB1ENR_GPIOBEN
#define RCC_AHB1ENR_IOPAEN RCC_AHB1ENR_GPIOAEN




#define RCC_AHB2ENR_OTGFSEN (1 << 7)
#define RCC_AHB2ENR_RNGEN (1 << 6)
#define RCC_AHB2ENR_HASHEN (1 << 5)
#define RCC_AHB2ENR_CRYPEN (1 << 4)
#define RCC_AHB2ENR_DCMIEN (1 << 0)




#define RCC_AHB3ENR_QSPIEN (1 << 1)
#define RCC_AHB3ENR_FSMCEN (1 << 0)

#define RCC_AHB3ENR_FMCEN (1 << 0)





#define RCC_APB1ENR_UART8EN (1 << 31)
#define RCC_APB1ENR_UART7EN (1 << 30)
#define RCC_APB1ENR_DACEN (1 << 29)
#define RCC_APB1ENR_PWREN (1 << 28)
#define RCC_APB1ENR_CAN2EN (1 << 26)
#define RCC_APB1ENR_CAN1EN (1 << 25)
#define RCC_APB1ENR_I2C3EN (1 << 23)
#define RCC_APB1ENR_I2C2EN (1 << 22)
#define RCC_APB1ENR_I2C1EN (1 << 21)
#define RCC_APB1ENR_UART5EN (1 << 20)
#define RCC_APB1ENR_UART4EN (1 << 19)
#define RCC_APB1ENR_USART3EN (1 << 18)
#define RCC_APB1ENR_USART2EN (1 << 17)
#define RCC_APB1ENR_SPI3EN (1 << 15)
#define RCC_APB1ENR_SPI2EN (1 << 14)
#define RCC_APB1ENR_WWDGEN (1 << 11)
#define RCC_APB1ENR_TIM14EN (1 << 8)
#define RCC_APB1ENR_TIM13EN (1 << 7)
#define RCC_APB1ENR_TIM12EN (1 << 6)
#define RCC_APB1ENR_TIM7EN (1 << 5)
#define RCC_APB1ENR_TIM6EN (1 << 4)
#define RCC_APB1ENR_TIM5EN (1 << 3)
#define RCC_APB1ENR_TIM4EN (1 << 2)
#define RCC_APB1ENR_TIM3EN (1 << 1)
#define RCC_APB1ENR_TIM2EN (1 << 0)




#define RCC_APB2ENR_DSIEN (1 << 27)
#define RCC_APB2ENR_LTDCEN (1 << 26)
#define RCC_APB2ENR_SAI1EN (1 << 22)
#define RCC_APB2ENR_SPI6EN (1 << 21)
#define RCC_APB2ENR_SPI5EN (1 << 20)
#define RCC_APB2ENR_TIM11EN (1 << 18)
#define RCC_APB2ENR_TIM10EN (1 << 17)
#define RCC_APB2ENR_TIM9EN (1 << 16)
#define RCC_APB2ENR_SYSCFGEN (1 << 14)
#define RCC_APB2ENR_SPI4EN (1 << 13)
#define RCC_APB2ENR_SPI1EN (1 << 12)
#define RCC_APB2ENR_SDIOEN (1 << 11)
#define RCC_APB2ENR_ADC3EN (1 << 10)
#define RCC_APB2ENR_ADC2EN (1 << 9)
#define RCC_APB2ENR_ADC1EN (1 << 8)
#define RCC_APB2ENR_USART6EN (1 << 5)
#define RCC_APB2ENR_USART1EN (1 << 4)
#define RCC_APB2ENR_TIM8EN (1 << 1)
#define RCC_APB2ENR_TIM1EN (1 << 0)




#define RCC_AHB1LPENR_OTGHSULPILPEN (1 << 30)
#define RCC_AHB1LPENR_OTGHSLPEN (1 << 29)
#define RCC_AHB1LPENR_ETHMACPTPLPEN (1 << 28)
#define RCC_AHB1LPENR_ETHMACRXLPEN (1 << 27)
#define RCC_AHB1LPENR_ETHMACTXLPEN (1 << 26)
#define RCC_AHB1LPENR_ETHMACLPEN (1 << 25)
#define RCC_AHB1LPENR_DMA2DLPEN (1 << 23)
#define RCC_AHB1LPENR_DMA2LPEN (1 << 22)
#define RCC_AHB1LPENR_DMA1LPEN (1 << 21)
#define RCC_AHB1LPENR_SRAM3LPEN (1 << 19)
#define RCC_AHB1LPENR_BKPSRAMLPEN (1 << 18)
#define RCC_AHB1LPENR_SRAM2LPEN (1 << 17)
#define RCC_AHB1LPENR_SRAM1LPEN (1 << 16)
#define RCC_AHB1LPENR_FLITFLPEN (1 << 15)
#define RCC_AHB1LPENR_CRCLPEN (1 << 12)
#define RCC_AHB1LPENR_GPIOKLPEN (1 << 10)
#define RCC_AHB1LPENR_GPIOJLPEN (1 << 9)
#define RCC_AHB1LPENR_GPIOILPEN (1 << 8)
#define RCC_AHB1LPENR_GPIOHLPEN (1 << 7)
#define RCC_AHB1LPENR_GPIOGLPEN (1 << 6)
#define RCC_AHB1LPENR_GPIOFLPEN (1 << 5)
#define RCC_AHB1LPENR_GPIOELPEN (1 << 4)
#define RCC_AHB1LPENR_GPIODLPEN (1 << 3)
#define RCC_AHB1LPENR_GPIOCLPEN (1 << 2)
#define RCC_AHB1LPENR_GPIOBLPEN (1 << 1)
#define RCC_AHB1LPENR_GPIOALPEN (1 << 0)





#define RCC_AHB1LPENR_IOPKLPEN RCC_AHB1LPENR_GPIOKLPEN
#define RCC_AHB1LPENR_IOPJLPEN RCC_AHB1LPENR_GPIOJLPEN
#define RCC_AHB1LPENR_IOPILPEN RCC_AHB1LPENR_GPIOILPEN
#define RCC_AHB1LPENR_IOPHLPEN RCC_AHB1LPENR_GPIOHLPEN
#define RCC_AHB1LPENR_IOPGLPEN RCC_AHB1LPENR_GPIOGLPEN
#define RCC_AHB1LPENR_IOPFLPEN RCC_AHB1LPENR_GPIOFLPEN
#define RCC_AHB1LPENR_IOPELPEN RCC_AHB1LPENR_GPIOELPEN
#define RCC_AHB1LPENR_IOPDLPEN RCC_AHB1LPENR_GPIODLPEN
#define RCC_AHB1LPENR_IOPCLPEN RCC_AHB1LPENR_GPIOCLPEN
#define RCC_AHB1LPENR_IOPBLPEN RCC_AHB1LPENR_GPIOBLPEN
#define RCC_AHB1LPENR_IOPALPEN RCC_AHB1LPENR_GPIOALPEN




#define RCC_AHB2LPENR_OTGFSLPEN (1 << 7)
#define RCC_AHB2LPENR_RNGLPEN (1 << 6)
#define RCC_AHB2LPENR_HASHLPEN (1 << 5)
#define RCC_AHB2LPENR_CRYPLPEN (1 << 4)
#define RCC_AHB2LPENR_DCMILPEN (1 << 0)



#define RCC_AHB3LPENR_QSPIEN (1 << 1)
#define RCC_AHB3LPENR_FSMCLPEN (1 << 0)
#define RCC_AHB3LPENR_FMCLPEN (1 << 0)





#define RCC_APB1LPENR_UART8EN (1 << 31)
#define RCC_APB1LPENR_UART7EN (1 << 30)
#define RCC_APB1LPENR_DACLPEN (1 << 29)
#define RCC_APB1LPENR_PWRLPEN (1 << 28)
#define RCC_APB1LPENR_CAN2LPEN (1 << 26)
#define RCC_APB1LPENR_CAN1LPEN (1 << 25)
#define RCC_APB1LPENR_I2C3LPEN (1 << 23)
#define RCC_APB1LPENR_I2C2LPEN (1 << 22)
#define RCC_APB1LPENR_I2C1LPEN (1 << 21)
#define RCC_APB1LPENR_UART5LPEN (1 << 20)
#define RCC_APB1LPENR_UART4LPEN (1 << 19)
#define RCC_APB1LPENR_USART3LPEN (1 << 18)
#define RCC_APB1LPENR_USART2LPEN (1 << 17)
#define RCC_APB1LPENR_SPI3LPEN (1 << 15)
#define RCC_APB1LPENR_SPI2LPEN (1 << 14)
#define RCC_APB1LPENR_WWDGLPEN (1 << 11)
#define RCC_APB1LPENR_TIM14LPEN (1 << 8)
#define RCC_APB1LPENR_TIM13LPEN (1 << 7)
#define RCC_APB1LPENR_TIM12LPEN (1 << 6)
#define RCC_APB1LPENR_TIM7LPEN (1 << 5)
#define RCC_APB1LPENR_TIM6LPEN (1 << 4)
#define RCC_APB1LPENR_TIM5LPEN (1 << 3)
#define RCC_APB1LPENR_TIM4LPEN (1 << 2)
#define RCC_APB1LPENR_TIM3LPEN (1 << 1)
#define RCC_APB1LPENR_TIM2LPEN (1 << 0)



#define RCC_APB2LPENR_DSILPEN (1 << 27)
#define RCC_APB2LPENR_LTDCLPEN (1 << 26)
#define RCC_APB2LPENR_SAI1LPEN (1 << 22)
#define RCC_APB2LPENR_SPI6LPEN (1 << 21)
#define RCC_APB2LPENR_SPI5LPEN (1 << 20)
#define RCC_APB2LPENR_TIM11LPEN (1 << 18)
#define RCC_APB2LPENR_TIM10LPEN (1 << 17)
#define RCC_APB2LPENR_TIM9LPEN (1 << 16)
#define RCC_APB2LPENR_SYSCFGLPEN (1 << 14)
#define RCC_APB2LPENR_SPI1LPEN (1 << 12)
#define RCC_APB2LPENR_SDIOLPEN (1 << 11)
#define RCC_APB2LPENR_ADC3LPEN (1 << 10)
#define RCC_APB2LPENR_ADC2LPEN (1 << 9)
#define RCC_APB2LPENR_ADC1LPEN (1 << 8)
#define RCC_APB2LPENR_USART6LPEN (1 << 5)
#define RCC_APB2LPENR_USART1LPEN (1 << 4)
#define RCC_APB2LPENR_TIM8LPEN (1 << 1)
#define RCC_APB2LPENR_TIM1LPEN (1 << 0)






#define RCC_BDCR_BDRST (1 << 16)
#define RCC_BDCR_RTCEN (1 << 15)

#define RCC_BDCR_RTCSEL_SHIFT 8
#define RCC_BDCR_RTCSEL_MASK 0x3
#define RCC_BDCR_RTCSEL_NONE 0
#define RCC_BDCR_RTCSEL_LSE 1
#define RCC_BDCR_RTCSEL_LSI 2
#define RCC_BDCR_RTCSEL_HSE 3
#define RCC_BDCR_LSEMOD (1 << 3)
#define RCC_BDCR_LSEBYP (1 << 2)
#define RCC_BDCR_LSERDY (1 << 1)
#define RCC_BDCR_LSEON (1 << 0)






#define RCC_CSR_LPWRRSTF (1 << 31)
#define RCC_CSR_WWDGRSTF (1 << 30)
#define RCC_CSR_IWDGRSTF (1 << 29)
#define RCC_CSR_SFTRSTF (1 << 28)
#define RCC_CSR_PORRSTF (1 << 27)
#define RCC_CSR_PINRSTF (1 << 26)
#define RCC_CSR_BORRSTF (1 << 25)
#define RCC_CSR_RMVF (1 << 24)
#define RCC_CSR_RESET_FLAGS (RCC_CSR_LPWRRSTF | RCC_CSR_WWDGRSTF | RCC_CSR_IWDGRSTF | RCC_CSR_SFTRSTF | RCC_CSR_PORRSTF | RCC_CSR_PINRSTF | RCC_CSR_BORRSTF)


#define RCC_CSR_LSIRDY (1 << 1)
#define RCC_CSR_LSION (1 << 0)
#define RCC_SSCGR_SSCGEN (1 << 31)
#define RCC_SSCGR_SPREADSEL (1 << 30)

#define RCC_SSCGR_INCSTEP_SHIFT 13
#define RCC_SSCGR_INCSTEP_MASK 0x7fff

#define RCC_SSCGR_MODPER_SHIFT 0
#define RCC_SSCGR_MODPER_MASK 0x1fff
#define RCC_PLLI2SCFGR_PLLI2SR_SHIFT 28
#define RCC_PLLI2SCFGR_PLLI2SR_MASK 0x7

#define RCC_PLLI2SCFGR_PLLI2SQ_SHIFT 24
#define RCC_PLLI2SCFGR_PLLI2SQ_MASK 0xf

#define RCC_PLLI2SCFGR_PLLI2SN_SHIFT 6
#define RCC_PLLI2SCFGR_PLLI2SN_MASK 0x1ff




#define RCC_PLLSAICFGR_PLLSAIR_SHIFT 28
#define RCC_PLLSAICFGR_PLLSAIR_MASK 0x7


#define RCC_PLLSAICFGR_PLLSAIQ_SHIFT 24
#define RCC_PLLSAICFGR_PLLSAIQ_MASK 0xF


#define RCC_PLLSAICFGR_PLLSAIP_SHIFT 16
#define RCC_PLLSAICFGR_PLLSAIP_MASK 0x3



#define RCC_PLLSAICFGR_PLLSAIP_DIV2 0x0
#define RCC_PLLSAICFGR_PLLSAIP_DIV4 0x1
#define RCC_PLLSAICFGR_PLLSAIP_DIV6 0x2
#define RCC_PLLSAICFGR_PLLSAIP_DIV8 0x3



#define RCC_PLLSAICFGR_PLLSAIN_SHIFT 6
#define RCC_PLLSAICFGR_PLLSAIN_MASK 0x1FF



#define RCC_DCKCFGR_DSISEL (1 << 29)
#define RCC_DCKCFGR_SDMMCSEL (1 << 28)
#define RCC_DCKCFGR_48MSEL (1 << 27)
#define RCC_DCKCFGR_TIMPRE (1 << 24)

#define RCC_DCKCFGR_SAI1BSRC_SHIFT 22
#define RCC_DCKCFGR_SAI1BSRC_MASK 0x3

#define RCC_DCKCFGR_SAI1ASRC_SHIFT 20
#define RCC_DCKCFGR_SAI1ASRC_MASK 0x3


#define RCC_DCKCFGR_SAI1SRC_SAIQ 0x0
#define RCC_DCKCFGR_SAI1SRC_I2SQ 0x1
#define RCC_DCKCFGR_SAI1SRC_ALT 0x2
#define RCC_DCKCFGR_SAI1SRC_ERROR 0x3

#define RCC_DCKCFGR_PLLSAIDIVR_SHIFT 16
#define RCC_DCKCFGR_PLLSAIDIVR_MASK 0x3
#define RCC_DCKCFGR_PLLSAIDIVR_DIVR_2 0x0
#define RCC_DCKCFGR_PLLSAIDIVR_DIVR_4 0x1
#define RCC_DCKCFGR_PLLSAIDIVR_DIVR_8 0x2
#define RCC_DCKCFGR_PLLSAIDIVR_DIVR_16 0x3

#define RCC_DCKCFGR_PLLSAIDIVQ_SHIFT 8
#define RCC_DCKCFGR_PLLSAIDIVQ_MASK 0x1f

#define RCC_DCKCFGR_PLLI2SDIVQ_SHIFT 0
#define RCC_DCKCFGR_PLLI2SDIVQ_MASK 0x1f






#define RCC_CKGATENR_EVTCL_CKEN (1<<7)
#define RCC_CKGATENR_RCC_CKEN (1<<6)
#define RCC_CKGATENR_FLITF_CKEN (1<<5)
#define RCC_CKGATENR_SRAM_CKEN (1<<4)
#define RCC_CKGATENR_SPARE_CKEN (1<<3)
#define RCC_CKGATENR_CM4DBG_CKEN (1<<2)
#define RCC_CKGATENR_AHB2APB2_CKEN (1<<1)
#define RCC_CKGATENR_AHB2APB1_CKEN (1<<0)



extern uint32_t rcc_ahb_frequency;
extern uint32_t rcc_apb1_frequency;
extern uint32_t rcc_apb2_frequency;



enum rcc_clock_3v3 {
 RCC_CLOCK_3V3_84MHZ,
 RCC_CLOCK_3V3_96MHZ,
 RCC_CLOCK_3V3_168MHZ,
 RCC_CLOCK_3V3_180MHZ,
 RCC_CLOCK_3V3_END
};

struct rcc_clock_scale {
 uint8_t pllm;
 uint16_t plln;
 uint8_t pllp;
 uint8_t pllq;
 uint8_t pllr;
 uint8_t pll_source;
 uint32_t flash_config;
 uint8_t hpre;
 uint8_t ppre1;
 uint8_t ppre2;
 enum pwr_vos_scale voltage_scale;
 uint32_t ahb_frequency;
 uint32_t apb1_frequency;
 uint32_t apb2_frequency;
};

extern const struct rcc_clock_scale rcc_hsi_configs[RCC_CLOCK_3V3_END];
extern const struct rcc_clock_scale rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_END];
extern const struct rcc_clock_scale rcc_hse_12mhz_3v3[RCC_CLOCK_3V3_END];
extern const struct rcc_clock_scale rcc_hse_16mhz_3v3[RCC_CLOCK_3V3_END];
extern const struct rcc_clock_scale rcc_hse_25mhz_3v3[RCC_CLOCK_3V3_END];

enum rcc_osc {
 RCC_PLL,
 RCC_PLLSAI,
 RCC_PLLI2S,
 RCC_HSE,
 RCC_HSI,
 RCC_LSE,
 RCC_LSI
};

#define _REG_BIT(base,bit) (((base) << 5) + (bit))

enum rcc_periph_clken {

 RCC_GPIOA = (((0x30) << 5) + (0)),
 RCC_GPIOB = (((0x30) << 5) + (1)),
 RCC_GPIOC = (((0x30) << 5) + (2)),
 RCC_GPIOD = (((0x30) << 5) + (3)),
 RCC_GPIOE = (((0x30) << 5) + (4)),
 RCC_GPIOF = (((0x30) << 5) + (5)),
 RCC_GPIOG = (((0x30) << 5) + (6)),
 RCC_GPIOH = (((0x30) << 5) + (7)),
 RCC_GPIOI = (((0x30) << 5) + (8)),
 RCC_GPIOJ = (((0x30) << 5) + (9)),
 RCC_GPIOK = (((0x30) << 5) + (10)),
 RCC_CRC = (((0x30) << 5) + (12)),
 RCC_BKPSRAM = (((0x30) << 5) + (18)),
 RCC_CCMDATARAM = (((0x30) << 5) + (20)),
 RCC_DMA1 = (((0x30) << 5) + (21)),
 RCC_DMA2 = (((0x30) << 5) + (22)),
 RCC_DMA2D = (((0x30) << 5) + (23)),
 RCC_ETHMAC = (((0x30) << 5) + (25)),
 RCC_ETHMACTX = (((0x30) << 5) + (26)),
 RCC_ETHMACRX = (((0x30) << 5) + (27)),
 RCC_ETHMACPTP = (((0x30) << 5) + (28)),
 RCC_OTGHS = (((0x30) << 5) + (29)),
 RCC_OTGHSULPI = (((0x30) << 5) + (30)),


 RCC_DCMI = (((0x34) << 5) + (0)),
 RCC_CRYP = (((0x34) << 5) + (4)),
 RCC_HASH = (((0x34) << 5) + (5)),
 RCC_RNG = (((0x34) << 5) + (6)),
 RCC_OTGFS = (((0x34) << 5) + (7)),


 RCC_FSMC = (((0x38) << 5) + (0)),
 RCC_FMC = (((0x38) << 5) + (0)),
 RCC_QUADSPI = (((0x38) << 5) + (1)),


 RCC_TIM2 = (((0x40) << 5) + (0)),
 RCC_TIM3 = (((0x40) << 5) + (1)),
 RCC_TIM4 = (((0x40) << 5) + (2)),
 RCC_TIM5 = (((0x40) << 5) + (3)),
 RCC_TIM6 = (((0x40) << 5) + (4)),
 RCC_TIM7 = (((0x40) << 5) + (5)),
 RCC_TIM12 = (((0x40) << 5) + (6)),
 RCC_TIM13 = (((0x40) << 5) + (7)),
 RCC_TIM14 = (((0x40) << 5) + (8)),
 RCC_WWDG = (((0x40) << 5) + (11)),
 RCC_SPI2 = (((0x40) << 5) + (14)),
 RCC_SPI3 = (((0x40) << 5) + (15)),
 RCC_USART2 = (((0x40) << 5) + (17)),
 RCC_USART3 = (((0x40) << 5) + (18)),
 RCC_UART4 = (((0x40) << 5) + (19)),
 RCC_UART5 = (((0x40) << 5) + (20)),
 RCC_I2C1 = (((0x40) << 5) + (21)),
 RCC_I2C2 = (((0x40) << 5) + (22)),
 RCC_I2C3 = (((0x40) << 5) + (23)),
 RCC_CAN1 = (((0x40) << 5) + (25)),
 RCC_CAN2 = (((0x40) << 5) + (26)),
 RCC_PWR = (((0x40) << 5) + (28)),
 RCC_DAC = (((0x40) << 5) + (29)),
 RCC_UART7 = (((0x40) << 5) + (30)),
 RCC_UART8 = (((0x40) << 5) + (31)),


 RCC_TIM1 = (((0x44) << 5) + (0)),
 RCC_TIM8 = (((0x44) << 5) + (1)),
 RCC_USART1 = (((0x44) << 5) + (4)),
 RCC_USART6 = (((0x44) << 5) + (5)),
 RCC_ADC1 = (((0x44) << 5) + (8)),
 RCC_ADC2 = (((0x44) << 5) + (9)),
 RCC_ADC3 = (((0x44) << 5) + (10)),
 RCC_SDIO = (((0x44) << 5) + (11)),
 RCC_SPI1 = (((0x44) << 5) + (12)),
 RCC_SPI4 = (((0x44) << 5) + (13)),
 RCC_SYSCFG = (((0x44) << 5) + (14)),
 RCC_TIM9 = (((0x44) << 5) + (16)),
 RCC_TIM10 = (((0x44) << 5) + (17)),
 RCC_TIM11 = (((0x44) << 5) + (18)),
 RCC_SPI5 = (((0x44) << 5) + (20)),
 RCC_SPI6 = (((0x44) << 5) + (21)),
 RCC_SAI1EN = (((0x44) << 5) + (22)),
 RCC_LTDC = (((0x44) << 5) + (26)),
 RCC_DSI = (((0x44) << 5) + (27)),



 RCC_RTC = (((0x70) << 5) + (15)),


 SCC_GPIOA = (((0x50) << 5) + (0)),
 SCC_GPIOB = (((0x50) << 5) + (1)),
 SCC_GPIOC = (((0x50) << 5) + (2)),
 SCC_GPIOD = (((0x50) << 5) + (3)),
 SCC_GPIOE = (((0x50) << 5) + (4)),
 SCC_GPIOF = (((0x50) << 5) + (5)),
 SCC_GPIOG = (((0x50) << 5) + (6)),
 SCC_GPIOH = (((0x50) << 5) + (7)),
 SCC_GPIOI = (((0x50) << 5) + (8)),
 SCC_GPIOJ = (((0x50) << 5) + (9)),
 SCC_GPIOK = (((0x50) << 5) + (10)),
 SCC_CRC = (((0x50) << 5) + (12)),
 SCC_FLTIF = (((0x50) << 5) + (15)),
 SCC_SRAM1 = (((0x50) << 5) + (16)),
 SCC_SRAM2 = (((0x50) << 5) + (17)),
 SCC_BKPSRAM = (((0x50) << 5) + (18)),
 SCC_SRAM3 = (((0x50) << 5) + (19)),
 SCC_DMA1 = (((0x50) << 5) + (21)),
 SCC_DMA2 = (((0x50) << 5) + (22)),
 SCC_DMA2D = (((0x50) << 5) + (23)),
 SCC_ETHMAC = (((0x50) << 5) + (25)),
 SCC_ETHMACTX = (((0x50) << 5) + (26)),
 SCC_ETHMACRX = (((0x50) << 5) + (27)),
 SCC_ETHMACPTP = (((0x50) << 5) + (28)),
 SCC_OTGHS = (((0x50) << 5) + (29)),
 SCC_OTGHSULPI = (((0x50) << 5) + (30)),


 SCC_DCMI = (((0x54) << 5) + (0)),
 SCC_CRYP = (((0x54) << 5) + (4)),
 SCC_HASH = (((0x54) << 5) + (5)),
 SCC_RNG = (((0x54) << 5) + (6)),
 SCC_OTGFS = (((0x54) << 5) + (7)),


 SCC_QSPIC = (((0x58) << 5) + (1)),
 SCC_FMC = (((0x58) << 5) + (0)),
 SCC_FSMC = (((0x58) << 5) + (0)),


 SCC_TIM2 = (((0x60) << 5) + (0)),
 SCC_TIM3 = (((0x60) << 5) + (1)),
 SCC_TIM4 = (((0x60) << 5) + (2)),
 SCC_TIM5 = (((0x60) << 5) + (3)),
 SCC_TIM6 = (((0x60) << 5) + (4)),
 SCC_TIM7 = (((0x60) << 5) + (5)),
 SCC_TIM12 = (((0x60) << 5) + (6)),
 SCC_TIM13 = (((0x60) << 5) + (7)),
 SCC_TIM14 = (((0x60) << 5) + (8)),
 SCC_WWDG = (((0x60) << 5) + (11)),
 SCC_SPI2 = (((0x60) << 5) + (14)),
 SCC_SPI3 = (((0x60) << 5) + (15)),
 SCC_USART2 = (((0x60) << 5) + (17)),
 SCC_USART3 = (((0x60) << 5) + (18)),
 SCC_UART4 = (((0x60) << 5) + (19)),
 SCC_UART5 = (((0x60) << 5) + (20)),
 SCC_I2C1 = (((0x60) << 5) + (21)),
 SCC_I2C2 = (((0x60) << 5) + (22)),
 SCC_I2C3 = (((0x60) << 5) + (23)),
 SCC_CAN1 = (((0x60) << 5) + (25)),
 SCC_CAN2 = (((0x60) << 5) + (26)),
 SCC_PWR = (((0x60) << 5) + (28)),
 SCC_DAC = (((0x60) << 5) + (29)),
 SCC_UART7 = (((0x60) << 5) + (30)),
 SCC_UART8 = (((0x60) << 5) + (31)),


 SCC_TIM1 = (((0x64) << 5) + (0)),
 SCC_TIM8 = (((0x64) << 5) + (1)),
 SCC_USART1 = (((0x64) << 5) + (4)),
 SCC_USART6 = (((0x64) << 5) + (5)),
 SCC_ADC1 = (((0x64) << 5) + (8)),
 SCC_ADC2 = (((0x64) << 5) + (9)),
 SCC_ADC3 = (((0x64) << 5) + (10)),
 SCC_SDIO = (((0x64) << 5) + (11)),
 SCC_SPI1 = (((0x64) << 5) + (12)),
 SCC_SPI4 = (((0x64) << 5) + (13)),
 SCC_SYSCFG = (((0x64) << 5) + (14)),
 SCC_TIM9 = (((0x64) << 5) + (16)),
 SCC_TIM10 = (((0x64) << 5) + (17)),
 SCC_TIM11 = (((0x64) << 5) + (18)),
 SCC_SPI5 = (((0x64) << 5) + (20)),
 SCC_SPI6 = (((0x64) << 5) + (21)),
 SCC_SAI1 = (((0x64) << 5) + (22)),
 SCC_LTDC = (((0x64) << 5) + (26)),
 SCC_DSI = (((0x64) << 5) + (27)),
};

enum rcc_periph_rst {

 RST_GPIOA = (((0x10) << 5) + (0)),
 RST_GPIOB = (((0x10) << 5) + (1)),
 RST_GPIOC = (((0x10) << 5) + (2)),
 RST_GPIOD = (((0x10) << 5) + (3)),
 RST_GPIOE = (((0x10) << 5) + (4)),
 RST_GPIOF = (((0x10) << 5) + (5)),
 RST_GPIOG = (((0x10) << 5) + (6)),
 RST_GPIOH = (((0x10) << 5) + (7)),
 RST_GPIOI = (((0x10) << 5) + (8)),
 RST_GPIOJ = (((0x10) << 5) + (9)),
 RST_GPIOK = (((0x10) << 5) + (10)),
 RST_CRC = (((0x10) << 5) + (12)),
 RST_DMA1 = (((0x10) << 5) + (21)),
 RST_DMA2 = (((0x10) << 5) + (22)),
 RST_DMA2D = (((0x10) << 5) + (23)),
 RST_ETHMAC = (((0x10) << 5) + (25)),
 RST_OTGHS = (((0x10) << 5) + (29)),


 RST_DCMI = (((0x14) << 5) + (0)),
 RST_CRYP = (((0x14) << 5) + (4)),
 RST_HASH = (((0x14) << 5) + (5)),
 RST_RNG = (((0x14) << 5) + (6)),
 RST_OTGFS = (((0x14) << 5) + (7)),


 RST_QSPI = (((0x18) << 5) + (1)),
 RST_FSMC = (((0x18) << 5) + (0)),
 RST_FMC = (((0x18) << 5) + (0)),


 RST_TIM2 = (((0x20) << 5) + (0)),
 RST_TIM3 = (((0x20) << 5) + (1)),
 RST_TIM4 = (((0x20) << 5) + (2)),
 RST_TIM5 = (((0x20) << 5) + (3)),
 RST_TIM6 = (((0x20) << 5) + (4)),
 RST_TIM7 = (((0x20) << 5) + (5)),
 RST_TIM12 = (((0x20) << 5) + (6)),
 RST_TIM13 = (((0x20) << 5) + (7)),
 RST_TIM14 = (((0x20) << 5) + (8)),
 RST_WWDG = (((0x20) << 5) + (11)),
 RST_SPI2 = (((0x20) << 5) + (14)),
 RST_SPI3 = (((0x20) << 5) + (15)),
 RST_USART2 = (((0x20) << 5) + (17)),
 RST_USART3 = (((0x20) << 5) + (18)),
 RST_UART4 = (((0x20) << 5) + (19)),
 RST_UART5 = (((0x20) << 5) + (20)),
 RST_I2C1 = (((0x20) << 5) + (21)),
 RST_I2C2 = (((0x20) << 5) + (22)),
 RST_I2C3 = (((0x20) << 5) + (23)),
 RST_CAN1 = (((0x20) << 5) + (25)),
 RST_CAN2 = (((0x20) << 5) + (26)),
 RST_PWR = (((0x20) << 5) + (28)),
 RST_DAC = (((0x20) << 5) + (29)),
 RST_UART7 = (((0x20) << 5) + (30)),
 RST_UART8 = (((0x20) << 5) + (31)),


 RST_TIM1 = (((0x24) << 5) + (0)),
 RST_TIM8 = (((0x24) << 5) + (1)),
 RST_USART1 = (((0x24) << 5) + (4)),
 RST_USART6 = (((0x24) << 5) + (5)),
 RST_ADC = (((0x24) << 5) + (8)),
 RST_SDIO = (((0x24) << 5) + (11)),
 RST_SPI1 = (((0x24) << 5) + (12)),
 RST_SPI4 = (((0x24) << 5) + (13)),
 RST_SYSCFG = (((0x24) << 5) + (14)),
 RST_TIM9 = (((0x24) << 5) + (16)),
 RST_TIM10 = (((0x24) << 5) + (17)),
 RST_TIM11 = (((0x24) << 5) + (18)),
 RST_SPI5 = (((0x24) << 5) + (20)),
 RST_SPI6 = (((0x24) << 5) + (21)),
 RST_SAI1RST = (((0x24) << 5) + (22)),
 RST_LTDC = (((0x24) << 5) + (26)),
 RST_DSI = (((0x24) << 5) + (27)),


 RST_BDCR = (((0x70) << 5) + (16)),
};

#undef _REG_BIT

#define LIBOPENCM3_RCC_COMMON_ALL_H 





void rcc_peripheral_enable_clock(volatile uint32_t *reg, uint32_t en);
void rcc_peripheral_disable_clock(volatile uint32_t *reg, uint32_t en);
void rcc_peripheral_reset(volatile uint32_t *reg, uint32_t reset);
void rcc_peripheral_clear_reset(volatile uint32_t *reg, uint32_t clear_reset);

void rcc_periph_clock_enable(enum rcc_periph_clken clken);
void rcc_periph_clock_disable(enum rcc_periph_clken clken);
void rcc_periph_reset_pulse(enum rcc_periph_rst rst);
void rcc_periph_reset_hold(enum rcc_periph_rst rst);
void rcc_periph_reset_release(enum rcc_periph_rst rst);

void rcc_set_mco(uint32_t mcosrc);
void rcc_osc_bypass_enable(enum rcc_osc osc);
void rcc_osc_bypass_disable(enum rcc_osc osc);







_Bool 
    rcc_is_osc_ready(enum rcc_osc osc);






void rcc_wait_for_osc_ready(enum rcc_osc osc);






uint16_t rcc_get_div_from_hpre(uint8_t div_val);





void rcc_osc_ready_int_clear(enum rcc_osc osc);
void rcc_osc_ready_int_enable(enum rcc_osc osc);
void rcc_osc_ready_int_disable(enum rcc_osc osc);
int rcc_osc_ready_int_flag(enum rcc_osc osc);
void rcc_css_int_clear(void);
int rcc_css_int_flag(void);
void rcc_wait_for_sysclk_status(enum rcc_osc osc);
void rcc_osc_on(enum rcc_osc osc);
void rcc_osc_off(enum rcc_osc osc);
void rcc_css_enable(void);
void rcc_css_disable(void);
void rcc_plli2s_config(uint16_t n, uint8_t r);
void rcc_pllsai_config(uint16_t n, uint16_t p, uint16_t q, uint16_t r);
void rcc_pllsai_postscalers(uint8_t q, uint8_t r);
void rcc_set_sysclk_source(uint32_t clk);
void rcc_set_pll_source(uint32_t pllsrc);
void rcc_set_ppre2(uint32_t ppre2);
void rcc_set_ppre1(uint32_t ppre1);
void rcc_set_hpre(uint32_t hpre);
void rcc_set_rtcpre(uint32_t rtcpre);
void rcc_set_main_pll_hsi(uint32_t pllm, uint32_t plln, uint32_t pllp,
     uint32_t pllq, uint32_t pllr);
void rcc_set_main_pll_hse(uint32_t pllm, uint32_t plln, uint32_t pllp,
     uint32_t pllq, uint32_t pllr);
uint32_t rcc_system_clock_source(void);
void rcc_clock_setup_pll(const struct rcc_clock_scale *clock);
void __attribute__((deprecated("Use rcc_clock_setup_pll as direct replacement"))) rcc_clock_setup_hse_3v3(const struct rcc_clock_scale *clock);
uint32_t rcc_get_usart_clk_freq(uint32_t usart);
uint32_t rcc_get_timer_clk_freq(uint32_t timer);
uint32_t rcc_get_i2c_clk_freq(uint32_t i2c);
uint32_t rcc_get_spi_clk_freq(uint32_t spi);


#define LIBOPENCM3_GPIO_H 

#define LIBOPENCM3_GPIO_COMMON_F24_H 



#define LIBOPENCM3_GPIO_COMMON_F234_H 



#define LIBOPENCM3_GPIO_COMMON_ALL_H 







#define GPIO_LCKK (1 << 16)







#define GPIO0 (1 << 0)
#define GPIO1 (1 << 1)
#define GPIO2 (1 << 2)
#define GPIO3 (1 << 3)
#define GPIO4 (1 << 4)
#define GPIO5 (1 << 5)
#define GPIO6 (1 << 6)
#define GPIO7 (1 << 7)
#define GPIO8 (1 << 8)
#define GPIO9 (1 << 9)
#define GPIO10 (1 << 10)
#define GPIO11 (1 << 11)
#define GPIO12 (1 << 12)
#define GPIO13 (1 << 13)
#define GPIO14 (1 << 14)
#define GPIO15 (1 << 15)
#define GPIO_ALL 0xffff




void gpio_set(uint32_t gpioport, uint16_t gpios);
void gpio_clear(uint32_t gpioport, uint16_t gpios);
uint16_t gpio_get(uint32_t gpioport, uint16_t gpios);
void gpio_toggle(uint32_t gpioport, uint16_t gpios);
uint16_t gpio_port_read(uint32_t gpioport);
void gpio_port_write(uint32_t gpioport, uint16_t data);
void gpio_port_config_lock(uint32_t gpioport, uint16_t gpios);








#define GPIOA GPIO_PORT_A_BASE
#define GPIOB GPIO_PORT_B_BASE
#define GPIOC GPIO_PORT_C_BASE
#define GPIOD GPIO_PORT_D_BASE
#define GPIOE GPIO_PORT_E_BASE
#define GPIOF GPIO_PORT_F_BASE
#define GPIOG GPIO_PORT_G_BASE
#define GPIOH GPIO_PORT_H_BASE






#define GPIO_MODER(port) MMIO32((port) + 0x00)
#define GPIOA_MODER GPIO_MODER(GPIOA)
#define GPIOB_MODER GPIO_MODER(GPIOB)
#define GPIOC_MODER GPIO_MODER(GPIOC)
#define GPIOD_MODER GPIO_MODER(GPIOD)
#define GPIOE_MODER GPIO_MODER(GPIOE)
#define GPIOF_MODER GPIO_MODER(GPIOF)
#define GPIOG_MODER GPIO_MODER(GPIOG)
#define GPIOH_MODER GPIO_MODER(GPIOH)


#define GPIO_OTYPER(port) MMIO32((port) + 0x04)
#define GPIOA_OTYPER GPIO_OTYPER(GPIOA)
#define GPIOB_OTYPER GPIO_OTYPER(GPIOB)
#define GPIOC_OTYPER GPIO_OTYPER(GPIOC)
#define GPIOD_OTYPER GPIO_OTYPER(GPIOD)
#define GPIOE_OTYPER GPIO_OTYPER(GPIOE)
#define GPIOF_OTYPER GPIO_OTYPER(GPIOF)
#define GPIOG_OTYPER GPIO_OTYPER(GPIOG)
#define GPIOH_OTYPER GPIO_OTYPER(GPIOH)


#define GPIO_OSPEEDR(port) MMIO32((port) + 0x08)
#define GPIOA_OSPEEDR GPIO_OSPEEDR(GPIOA)
#define GPIOB_OSPEEDR GPIO_OSPEEDR(GPIOB)
#define GPIOC_OSPEEDR GPIO_OSPEEDR(GPIOC)
#define GPIOD_OSPEEDR GPIO_OSPEEDR(GPIOD)
#define GPIOE_OSPEEDR GPIO_OSPEEDR(GPIOE)
#define GPIOF_OSPEEDR GPIO_OSPEEDR(GPIOF)
#define GPIOG_OSPEEDR GPIO_OSPEEDR(GPIOG)
#define GPIOH_OSPEEDR GPIO_OSPEEDR(GPIOH)


#define GPIO_PUPDR(port) MMIO32((port) + 0x0c)
#define GPIOA_PUPDR GPIO_PUPDR(GPIOA)
#define GPIOB_PUPDR GPIO_PUPDR(GPIOB)
#define GPIOC_PUPDR GPIO_PUPDR(GPIOC)
#define GPIOD_PUPDR GPIO_PUPDR(GPIOD)
#define GPIOE_PUPDR GPIO_PUPDR(GPIOE)
#define GPIOF_PUPDR GPIO_PUPDR(GPIOF)
#define GPIOG_PUPDR GPIO_PUPDR(GPIOG)
#define GPIOH_PUPDR GPIO_PUPDR(GPIOH)


#define GPIO_IDR(port) MMIO32((port) + 0x10)
#define GPIOA_IDR GPIO_IDR(GPIOA)
#define GPIOB_IDR GPIO_IDR(GPIOB)
#define GPIOC_IDR GPIO_IDR(GPIOC)
#define GPIOD_IDR GPIO_IDR(GPIOD)
#define GPIOE_IDR GPIO_IDR(GPIOE)
#define GPIOF_IDR GPIO_IDR(GPIOF)
#define GPIOG_IDR GPIO_IDR(GPIOG)
#define GPIOH_IDR GPIO_IDR(GPIOH)


#define GPIO_ODR(port) MMIO32((port) + 0x14)
#define GPIOA_ODR GPIO_ODR(GPIOA)
#define GPIOB_ODR GPIO_ODR(GPIOB)
#define GPIOC_ODR GPIO_ODR(GPIOC)
#define GPIOD_ODR GPIO_ODR(GPIOD)
#define GPIOE_ODR GPIO_ODR(GPIOE)
#define GPIOF_ODR GPIO_ODR(GPIOF)
#define GPIOG_ODR GPIO_ODR(GPIOG)
#define GPIOH_ODR GPIO_ODR(GPIOH)


#define GPIO_BSRR(port) MMIO32((port) + 0x18)
#define GPIOA_BSRR GPIO_BSRR(GPIOA)
#define GPIOB_BSRR GPIO_BSRR(GPIOB)
#define GPIOC_BSRR GPIO_BSRR(GPIOC)
#define GPIOD_BSRR GPIO_BSRR(GPIOD)
#define GPIOE_BSRR GPIO_BSRR(GPIOE)
#define GPIOF_BSRR GPIO_BSRR(GPIOF)
#define GPIOG_BSRR GPIO_BSRR(GPIOG)
#define GPIOH_BSRR GPIO_BSRR(GPIOH)


#define GPIO_LCKR(port) MMIO32((port) + 0x1c)
#define GPIOA_LCKR GPIO_LCKR(GPIOA)
#define GPIOB_LCKR GPIO_LCKR(GPIOB)
#define GPIOC_LCKR GPIO_LCKR(GPIOC)
#define GPIOD_LCKR GPIO_LCKR(GPIOD)
#define GPIOE_LCKR GPIO_LCKR(GPIOE)
#define GPIOF_LCKR GPIO_LCKR(GPIOF)
#define GPIOG_LCKR GPIO_LCKR(GPIOG)
#define GPIOH_LCKR GPIO_LCKR(GPIOH)


#define GPIO_AFRL(port) MMIO32((port) + 0x20)
#define GPIOA_AFRL GPIO_AFRL(GPIOA)
#define GPIOB_AFRL GPIO_AFRL(GPIOB)
#define GPIOC_AFRL GPIO_AFRL(GPIOC)
#define GPIOD_AFRL GPIO_AFRL(GPIOD)
#define GPIOE_AFRL GPIO_AFRL(GPIOE)
#define GPIOF_AFRL GPIO_AFRL(GPIOF)
#define GPIOG_AFRL GPIO_AFRL(GPIOG)
#define GPIOH_AFRL GPIO_AFRL(GPIOH)


#define GPIO_AFRH(port) MMIO32((port) + 0x24)
#define GPIOA_AFRH GPIO_AFRH(GPIOA)
#define GPIOB_AFRH GPIO_AFRH(GPIOB)
#define GPIOC_AFRH GPIO_AFRH(GPIOC)
#define GPIOD_AFRH GPIO_AFRH(GPIOD)
#define GPIOE_AFRH GPIO_AFRH(GPIOE)
#define GPIOF_AFRH GPIO_AFRH(GPIOF)
#define GPIOG_AFRH GPIO_AFRH(GPIOG)
#define GPIOH_AFRH GPIO_AFRH(GPIOH)



#define GPIO_MODE(n,mode) ((mode) << (2 * (n)))
#define GPIO_MODE_MASK(n) (0x3 << (2 * (n)))



#define GPIO_MODE_INPUT 0x0
#define GPIO_MODE_OUTPUT 0x1
#define GPIO_MODE_AF 0x2
#define GPIO_MODE_ANALOG 0x3
#define GPIO_OTYPE_PP 0x0

#define GPIO_OTYPE_OD 0x1




#define GPIO_OSPEED(n,speed) ((speed) << (2 * (n)))
#define GPIO_OSPEED_MASK(n) (0x3 << (2 * (n)))



#define GPIO_OSPEED_2MHZ 0x0
#define GPIO_OSPEED_25MHZ 0x1
#define GPIO_OSPEED_50MHZ 0x2
#define GPIO_OSPEED_100MHZ 0x3




#define GPIO_PUPD(n,pupd) ((pupd) << (2 * (n)))
#define GPIO_PUPD_MASK(n) (0x3 << (2 * (n)))



#define GPIO_PUPD_NONE 0x0
#define GPIO_PUPD_PULLUP 0x1
#define GPIO_PUPD_PULLDOWN 0x2
#define GPIO_LCKK (1 << 16)







#define GPIO_AFR(n,af) ((af) << ((n) * 4))
#define GPIO_AFR_MASK(n) (0xf << ((n) * 4))



#define GPIO_AF0 0x0
#define GPIO_AF1 0x1
#define GPIO_AF2 0x2
#define GPIO_AF3 0x3
#define GPIO_AF4 0x4
#define GPIO_AF5 0x5
#define GPIO_AF6 0x6
#define GPIO_AF7 0x7
#define GPIO_AF8 0x8
#define GPIO_AF9 0x9
#define GPIO_AF10 0xa
#define GPIO_AF11 0xb
#define GPIO_AF12 0xc
#define GPIO_AF13 0xd
#define GPIO_AF14 0xe
#define GPIO_AF15 0xf







void gpio_mode_setup(uint32_t gpioport, uint8_t mode, uint8_t pull_up_down,
       uint16_t gpios);
void gpio_set_output_options(uint32_t gpioport, uint8_t otype, uint8_t speed,
        uint16_t gpios);
void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint16_t gpios);








#define GPIOI GPIO_PORT_I_BASE
#define GPIOJ GPIO_PORT_J_BASE
#define GPIOK GPIO_PORT_K_BASE





#define GPIOI_MODER GPIO_MODER(GPIOI)
#define GPIOJ_MODER GPIO_MODER(GPIOJ)
#define GPIOK_MODER GPIO_MODER(GPIOK)


#define GPIOI_OTYPER GPIO_OTYPER(GPIOI)
#define GPIOJ_OTYPER GPIO_OTYPER(GPIOJ)
#define GPIOK_OTYPER GPIO_OTYPER(GPIOK)


#define GPIOI_OSPEEDR GPIO_OSPEEDR(GPIOI)
#define GPIOJ_OSPEEDR GPIO_OSPEEDR(GPIOJ)
#define GPIOK_OSPEEDR GPIO_OSPEEDR(GPIOK)


#define GPIOI_PUPDR GPIO_PUPDR(GPIOI)
#define GPIOJ_PUPDR GPIO_PUPDR(GPIOJ)
#define GPIOK_PUPDR GPIO_PUPDR(GPIOK)


#define GPIOI_IDR GPIO_IDR(GPIOI)
#define GPIOJ_IDR GPIO_IDR(GPIOJ)
#define GPIOK_IDR GPIO_IDR(GPIOK)


#define GPIOI_ODR GPIO_ODR(GPIOI)
#define GPIOJ_ODR GPIO_ODR(GPIOJ)
#define GPIOK_ODR GPIO_ODR(GPIOK)


#define GPIOI_BSRR GPIO_BSRR(GPIOI)
#define GPIOJ_BSRR GPIO_BSRR(GPIOJ)
#define GPIOK_BSRR GPIO_BSRR(GPIOK)


#define GPIOI_LCKR GPIO_LCKR(GPIOI)
#define GPIOJ_LCKR GPIO_LCKR(GPIOJ)
#define GPIOK_LCKR GPIO_LCKR(GPIOK)


#define GPIOI_AFRL GPIO_AFRL(GPIOI)
#define GPIOJ_AFRL GPIO_AFRL(GPIOJ)
#define GPIOK_AFRL GPIO_AFRL(GPIOK)


#define GPIOI_AFRH GPIO_AFRH(GPIOI)
#define GPIOJ_AFRH GPIO_AFRH(GPIOJ)
#define GPIOK_AFRH GPIO_AFRH(GPIOK)
       
       
       






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


#define LIBOPENCM3_NVIC_H 
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



#define LIBOPENCM3_DAC_H 

#define LIBOPENCM3_DAC_COMMON_V1_H 

#define LIBOPENCM3_DAC_COMMON_ALL_H 





#define DAC_CR(dac) MMIO32((dac) + 0x00)


#define DAC_SWTRIGR(dac) MMIO32((dac) + 0x04)


#define DAC_DHR12R1(dac) MMIO32((dac) + 0x08)


#define DAC_DHR12L1(dac) MMIO32((dac) + 0x0C)


#define DAC_DHR8R1(dac) MMIO32((dac) + 0x10)


#define DAC_DHR12R2(dac) MMIO32((dac) + 0x14)


#define DAC_DHR12L2(dac) MMIO32((dac) + 0x18)


#define DAC_DHR8R2(dac) MMIO32((dac) + 0x1C)


#define DAC_DHR12RD(dac) MMIO32((dac) + 0x20)


#define DAC_DHR12LD(dac) MMIO32((dac) + 0x24)


#define DAC_DHR8RD(dac) MMIO32((dac) + 0x28)


#define DAC_DOR1(dac) MMIO32((dac) + 0x2C)


#define DAC_DOR2(dac) MMIO32((dac) + 0x30)




#define DAC_SR(dac) MMIO32((dac) + 0x34)
#define DAC_CR_DMAUDRIE2 (1 << 29)


#define DAC_CR_DMAEN2 (1 << 28)


#define DAC_CR_MAMP2_SHIFT 24


#define DAC_CR_WAVEx_MASK 0x3


#define DAC_CR_WAVE2_SHIFT 22


#define DAC_CR_EN2 (1 << 16)




#define DAC_CR_DMAUDRIE1 (1 << 13)


#define DAC_CR_DMAEN1 (1 << 12)


#define DAC_CR_MAMP1_SHIFT 8

#define DAC_CR_MAMPx_MASK 0xf


#define DAC_CR_WAVE1_SHIFT 6


#define DAC_CR_EN1 (1 << 0)






#define DAC_SWTRIGR_SWTRIG2 (1 << 1)


#define DAC_SWTRIGR_SWTRIG1 (1 << 0)







#define DAC_DHR12R1_DACC1DHR_SHIFT 0
#define DAC_DHR12R1_DACC1DHR_MASK 0xFFF



#define DAC_DHR12L1_DACC1DHR_SHIFT 4
#define DAC_DHR12L1_DACC1DHR_MASK 0xFFF



#define DAC_DHR8R1_DACC1DHR_SHIFT 0
#define DAC_DHR8R1_DACC1DHR_MASK 0xFF



#define DAC_DHR12R2_DACC2DHR_SHIFT 0
#define DAC_DHR12R2_DACC2DHR_MASK 0xFFF



#define DAC_DHR12L2_DACC2DHR_SHIFT 4
#define DAC_DHR12L2_DACC2DHR_MASK 0xFFF



#define DAC_DHR8R2_DACC2DHR_SHIFT 0
#define DAC_DHR8R2_DACC2DHR_MASK 0xFF



#define DAC_DHR12RD_DACC2DHR_SHIFT 16
#define DAC_DHR12RD_DACC2DHR_MASK 0xFFF
#define DAC_DHR12RD_DACC1DHR_SHIFT 0
#define DAC_DHR12RD_DACC1DHR_MSK 0xFFF



#define DAC_DHR12LD_DACC2DHR_SHIFT 16
#define DAC_DHR12LD_DACC2DHR_MSK 0xFFF
#define DAC_DHR12LD_DACC1DHR_SHIFT 0
#define DAC_DHR12LD_DACC1DHR_MSK 0xFFF



#define DAC_DHR8RD_DACC2DHR_SHIFT 8
#define DAC_DHR8RD_DACC2DHR_MSK 0xFF
#define DAC_DHR8RD_DACC1DHR_SHIFT 0
#define DAC_DHR8RD_DACC1DHR_MSK 0xFF







#define DAC_DOR1_DACC1DOR_SHIFT 0
#define DAC_DOR1_DACC1DOR_MSK 0xFFF



#define DAC_DOR2_DACC2DOR_SHIFT 0
#define DAC_DOR2_DACC2DOR_MSK 0xFFF







#define DAC_SR_DMAUDR1 (1 << 13)


#define DAC_SR_DMAUDR2 (1 << 29)
#define DAC_CHANNEL1 (1 << 0)
#define DAC_CHANNEL2 (1 << 1)
#define DAC_CHANNEL_BOTH (DAC_CHANNEL1 | DAC_CHANNEL2)



enum dac_align {
 DAC_ALIGN_RIGHT8,
 DAC_ALIGN_RIGHT12,
 DAC_ALIGN_LEFT12,
};




enum dac_wave {
 DAC_WAVE_DISABLE = 0,
 DAC_WAVE_NOISE = 1,
 DAC_WAVE_TRIANGLE = 2,
 DAC_WAVE_SAWTOOTH = 3,
};



void dac_enable(uint32_t dac, int channel);
void dac_disable(uint32_t dac, int channel);
void dac_buffer_enable(uint32_t dac, int channel);
void dac_buffer_disable(uint32_t dac, int channel);
void dac_dma_enable(uint32_t dac, int channel);
void dac_dma_disable(uint32_t dac, int channel);
void dac_trigger_enable(uint32_t dac, int channel);
void dac_trigger_disable(uint32_t dac, int channel);
void dac_set_trigger_source(uint32_t dac, uint32_t source);
void dac_set_waveform_generation(uint32_t dac, int channel, enum dac_wave wave);
void dac_disable_waveform_generation(uint32_t dac, int channel);
void dac_set_waveform_characteristics(uint32_t dac, int channel, int mamp);
void dac_load_data_buffer_single(uint32_t dac, uint16_t data,
                                 enum dac_align align, int channel);
void dac_load_data_buffer_dual(uint32_t dac, uint16_t data1, uint16_t data2,
          enum dac_align align);
void dac_software_trigger(uint32_t dac, int channel);








#define DAC_CR_TSEL2_SHIFT 19
#define DAC_CR_TSEL2_T6 (0x0 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T3 (0x1 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T8 (0x1 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T7 (0x2 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T5 (0x3 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T15 (0x3 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T2 (0x4 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T4 (0x5 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_E9 (0x6 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_SW (0x7 << DAC_CR_TSEL2_SHIFT)



#define DAC_CR_TEN2 (1 << 18)


#define DAC_CR_BOFF2 (1 << 17)


#define DAC_CR_TSEL1_SHIFT 3
#define DAC_CR_TSEL1_T6 (0x0 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T3 (0x1 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T8 (0x1 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T7 (0x2 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T5 (0x3 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T15 (0x3 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T2 (0x4 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T4 (0x5 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_E9 (0x6 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_SW (0x7 << DAC_CR_TSEL1_SHIFT)



#define DAC_CR_TEN1 (1 << 2)


#define DAC_CR_BOFF1 (1 << 1)













#define DAC1 DAC_BASE
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




#define PERIOD 1152


uint8_t waveform[256];


static void clock_setup(void)
{
 rcc_clock_setup_pll(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_168MHZ]);
}


static void gpio_setup(void)
{

 rcc_periph_clock_enable(RCC_GPIOA);
 rcc_periph_clock_enable(RCC_GPIOC);

 gpio_mode_setup((((0x40000000U) + 0x20000) + 0x0800), 0x1, 0x0, (1 << 1));
 gpio_set_output_options((((0x40000000U) + 0x20000) + 0x0800), 0x0, 0x0, (1 << 1));

 gpio_mode_setup((((0x40000000U) + 0x20000) + 0x0000), 0x3, 0x0, (1 << 4));
}


static void timer_setup(void)
{

 rcc_periph_clock_enable(RCC_TIM2);
 rcc_periph_reset_pulse(RST_TIM2);

 timer_set_mode((((0x40000000U) + 0x00000) + 0x0000), (0x0 << 8),
         (0x0 << 5), (0 << 4));
 timer_continuous_mode((((0x40000000U) + 0x00000) + 0x0000));
 timer_set_period((((0x40000000U) + 0x00000) + 0x0000), 1152);
 timer_disable_oc_output((((0x40000000U) + 0x00000) + 0x0000), TIM_OC2 | TIM_OC3 | TIM_OC4);
 timer_enable_oc_output((((0x40000000U) + 0x00000) + 0x0000), TIM_OC1);
 timer_disable_oc_clear((((0x40000000U) + 0x00000) + 0x0000), TIM_OC1);
 timer_disable_oc_preload((((0x40000000U) + 0x00000) + 0x0000), TIM_OC1);
 timer_set_oc_slow_mode((((0x40000000U) + 0x00000) + 0x0000), TIM_OC1);
 timer_set_oc_mode((((0x40000000U) + 0x00000) + 0x0000), TIM_OC1, TIM_OCM_TOGGLE);
 timer_set_oc_value((((0x40000000U) + 0x00000) + 0x0000), TIM_OC1, 500);
 timer_disable_preload((((0x40000000U) + 0x00000) + 0x0000));


 timer_set_master_mode((((0x40000000U) + 0x00000) + 0x0000), (0x4 << 4));
 timer_enable_counter((((0x40000000U) + 0x00000) + 0x0000));
}


static void dma_setup(void)
{


 rcc_periph_clock_enable(RCC_DMA1);
 nvic_enable_irq(16);
 dma_stream_reset((((0x40000000U) + 0x20000) + 0x6000), 5);
 dma_set_priority((((0x40000000U) + 0x20000) + 0x6000), 5, (0 << 16));
 dma_set_memory_size((((0x40000000U) + 0x20000) + 0x6000), 5, (0 << 13));
 dma_set_peripheral_size((((0x40000000U) + 0x20000) + 0x6000), 5, (0 << 11));
 dma_enable_memory_increment_mode((((0x40000000U) + 0x20000) + 0x6000), 5);
 dma_enable_circular_mode((((0x40000000U) + 0x20000) + 0x6000), 5);
 dma_set_transfer_mode((((0x40000000U) + 0x20000) + 0x6000), 5,
    (1 << 6));


 dma_set_peripheral_address((((0x40000000U) + 0x20000) + 0x6000), 5, (uint32_t) &(*(volatile uint32_t *)(((((0x40000000U) + 0x00000) + 0x7400)) + 0x10)));

 dma_set_memory_address((((0x40000000U) + 0x20000) + 0x6000), 5, (uint32_t) waveform);
 dma_set_number_of_data((((0x40000000U) + 0x20000) + 0x6000), 5, 256);
 dma_enable_transfer_complete_interrupt((((0x40000000U) + 0x20000) + 0x6000), 5);
 dma_channel_select((((0x40000000U) + 0x20000) + 0x6000), 5, (7 << 25));
 dma_enable_stream((((0x40000000U) + 0x20000) + 0x6000), 5);
}


static void dac_setup(void)
{

 rcc_periph_clock_enable(RCC_DAC);


 dac_trigger_enable((((0x40000000U) + 0x00000) + 0x7400), (1 << 0));
 dac_set_trigger_source((((0x40000000U) + 0x00000) + 0x7400), (0x4 << 3));
 dac_dma_enable((((0x40000000U) + 0x00000) + 0x7400), (1 << 0));
 dac_enable((((0x40000000U) + 0x00000) + 0x7400), (1 << 0));
}




void dma1_stream5_isr(void)
{
 if (dma_get_interrupt_flag((((0x40000000U) + 0x20000) + 0x6000), 5, (1 << 5))) {
  dma_clear_interrupt_flags((((0x40000000U) + 0x20000) + 0x6000), 5, (1 << 5));

  gpio_toggle((((0x40000000U) + 0x20000) + 0x0800), (1 << 1));
 }
}


int main(void)
{


 uint16_t i, x;
 for (i = 0; i < 256; i++) {
  if (i < 10) {
   x = 10;
  } else if (i < 121) {
   x = 10 + ((i*i) >> 7);
  } else if (i < 170) {
   x = i/2;
  } else if (i < 246) {
   x = i + (80 - i/2);
  } else {
   x = 10;
  }
  waveform[i] = x;
 }
 clock_setup();
 gpio_setup();
 timer_setup();
 dma_setup();
 dac_setup();

 while (1);

 return 0;
}
