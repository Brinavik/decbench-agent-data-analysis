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
#define LIBOPENCM3_USART_H 

#define LIBOPENCM3_USART_COMMON_F24_H 

#define LIBOPENCM3_USART_COMMON_F124_H 

#define LIBOPENCM3_USART_COMMON_ALL_H 
#define USART_PARITY_NONE 0x00
#define USART_PARITY_EVEN USART_CR1_PCE
#define USART_PARITY_ODD (USART_CR1_PS | USART_CR1_PCE)

#define USART_PARITY_MASK (USART_CR1_PS | USART_CR1_PCE)







#define USART_MODE_RX USART_CR1_RE
#define USART_MODE_TX USART_CR1_TE
#define USART_MODE_TX_RX (USART_CR1_RE | USART_CR1_TE)

#define USART_MODE_MASK (USART_CR1_RE | USART_CR1_TE)






#define USART_STOPBITS_1 USART_CR2_STOPBITS_1
#define USART_STOPBITS_0_5 USART_CR2_STOPBITS_0_5
#define USART_STOPBITS_2 USART_CR2_STOPBITS_2
#define USART_STOPBITS_1_5 USART_CR2_STOPBITS_1_5



#define USART_CR2_STOPBITS_1 (0x00 << 12)
#define USART_CR2_STOPBITS_0_5 (0x01 << 12)
#define USART_CR2_STOPBITS_2 (0x02 << 12)
#define USART_CR2_STOPBITS_1_5 (0x03 << 12)
#define USART_CR2_STOPBITS_MASK (0x03 << 12)
#define USART_CR2_STOPBITS_SHIFT 12
#define USART_FLOWCONTROL_NONE 0x00
#define USART_FLOWCONTROL_RTS USART_CR3_RTSE
#define USART_FLOWCONTROL_CTS USART_CR3_CTSE
#define USART_FLOWCONTROL_RTS_CTS (USART_CR3_RTSE | USART_CR3_CTSE)

#define USART_FLOWCONTROL_MASK (USART_CR3_RTSE | USART_CR3_CTSE)





void usart_set_baudrate(uint32_t usart, uint32_t baud);
void usart_set_databits(uint32_t usart, uint32_t bits);
void usart_set_stopbits(uint32_t usart, uint32_t stopbits);
void usart_set_parity(uint32_t usart, uint32_t parity);
void usart_set_mode(uint32_t usart, uint32_t mode);
void usart_set_flow_control(uint32_t usart, uint32_t flowcontrol);
void usart_enable(uint32_t usart);
void usart_disable(uint32_t usart);
void usart_send(uint32_t usart, uint16_t data);
uint16_t usart_recv(uint32_t usart);
void usart_wait_send_ready(uint32_t usart);
void usart_wait_recv_ready(uint32_t usart);
void usart_send_blocking(uint32_t usart, uint16_t data);
uint16_t usart_recv_blocking(uint32_t usart);
void usart_enable_rx_dma(uint32_t usart);
void usart_disable_rx_dma(uint32_t usart);
void usart_enable_tx_dma(uint32_t usart);
void usart_disable_tx_dma(uint32_t usart);
void usart_enable_rx_interrupt(uint32_t usart);
void usart_disable_rx_interrupt(uint32_t usart);
void usart_enable_tx_interrupt(uint32_t usart);
void usart_disable_tx_interrupt(uint32_t usart);
void usart_enable_tx_complete_interrupt(uint32_t usart);
void usart_disable_tx_complete_interrupt(uint32_t usart);
void usart_enable_idle_interrupt(uint32_t usart);
void usart_disable_idle_interrupt(uint32_t usart);
void usart_enable_error_interrupt(uint32_t usart);
void usart_disable_error_interrupt(uint32_t usart);

_Bool 
    usart_get_flag(uint32_t usart, uint32_t flag);








#define USART1 USART1_BASE
#define USART2 USART2_BASE
#define USART3 USART3_BASE
#define UART4 UART4_BASE
#define UART5 UART5_BASE





#define USART_SR(usart_base) MMIO32((usart_base) + 0x00)
#define USART1_SR USART_SR(USART1_BASE)
#define USART2_SR USART_SR(USART2_BASE)
#define USART3_SR USART_SR(USART3_BASE)
#define UART4_SR USART_SR(UART4_BASE)
#define UART5_SR USART_SR(UART5_BASE)


#define USART_DR(usart_base) MMIO32((usart_base) + 0x04)
#define USART1_DR USART_DR(USART1_BASE)
#define USART2_DR USART_DR(USART2_BASE)
#define USART3_DR USART_DR(USART3_BASE)
#define UART4_DR USART_DR(UART4_BASE)
#define UART5_DR USART_DR(UART5_BASE)


#define USART_BRR(usart_base) MMIO32((usart_base) + 0x08)
#define USART1_BRR USART_BRR(USART1_BASE)
#define USART2_BRR USART_BRR(USART2_BASE)
#define USART3_BRR USART_BRR(USART3_BASE)
#define UART4_BRR USART_BRR(UART4_BASE)
#define UART5_BRR USART_BRR(UART5_BASE)


#define USART_CR1(usart_base) MMIO32((usart_base) + 0x0c)
#define USART1_CR1 USART_CR1(USART1_BASE)
#define USART2_CR1 USART_CR1(USART2_BASE)
#define USART3_CR1 USART_CR1(USART3_BASE)
#define UART4_CR1 USART_CR1(UART4_BASE)
#define UART5_CR1 USART_CR1(UART5_BASE)


#define USART_CR2(usart_base) MMIO32((usart_base) + 0x10)
#define USART1_CR2 USART_CR2(USART1_BASE)
#define USART2_CR2 USART_CR2(USART2_BASE)
#define USART3_CR2 USART_CR2(USART3_BASE)
#define UART4_CR2 USART_CR2(UART4_BASE)
#define UART5_CR2 USART_CR2(UART5_BASE)


#define USART_CR3(usart_base) MMIO32((usart_base) + 0x14)
#define USART1_CR3 USART_CR3(USART1_BASE)
#define USART2_CR3 USART_CR3(USART2_BASE)
#define USART3_CR3 USART_CR3(USART3_BASE)
#define UART4_CR3 USART_CR3(UART4_BASE)
#define UART5_CR3 USART_CR3(UART5_BASE)


#define USART_GTPR(usart_base) MMIO32((usart_base) + 0x18)
#define USART1_GTPR USART_GTPR(USART1_BASE)
#define USART2_GTPR USART_GTPR(USART2_BASE)
#define USART3_GTPR USART_GTPR(USART3_BASE)
#define UART4_GTPR USART_GTPR(UART4_BASE)
#define UART5_GTPR USART_GTPR(UART5_BASE)
#define USART_FLAG_PE USART_SR_PE
#define USART_FLAG_FE USART_SR_FE
#define USART_FLAG_NF USART_SR_NF
#define USART_FLAG_ORE USART_SR_ORE
#define USART_FLAG_IDLE USART_SR_IDLE
#define USART_FLAG_RXNE USART_SR_RXNE
#define USART_FLAG_TC USART_SR_TC
#define USART_FLAG_TXE USART_SR_TXE
#define USART_SR_CTS (1 << 9)


#define USART_SR_LBD (1 << 8)


#define USART_SR_TXE (1 << 7)


#define USART_SR_TC (1 << 6)


#define USART_SR_RXNE (1 << 5)


#define USART_SR_IDLE (1 << 4)


#define USART_SR_ORE (1 << 3)


#define USART_SR_NE (1 << 2)


#define USART_SR_FE (1 << 1)


#define USART_SR_PE (1 << 0)





#define USART_DR_MASK 0x1FF




#define USART_BRR_DIV_MANTISSA_MASK (0xFFF << 4)

#define USART_BRR_DIV_FRACTION_MASK 0xF




#define USART_CR1_UE (1 << 13)


#define USART_CR1_M (1 << 12)


#define USART_CR1_WAKE (1 << 11)


#define USART_CR1_PCE (1 << 10)


#define USART_CR1_PS (1 << 9)


#define USART_CR1_PEIE (1 << 8)


#define USART_CR1_TXEIE (1 << 7)


#define USART_CR1_TCIE (1 << 6)


#define USART_CR1_RXNEIE (1 << 5)


#define USART_CR1_IDLEIE (1 << 4)


#define USART_CR1_TE (1 << 3)


#define USART_CR1_RE (1 << 2)


#define USART_CR1_RWU (1 << 1)


#define USART_CR1_SBK (1 << 0)




#define USART_CR2_LINEN (1 << 14)


#define USART_CR2_CLKEN (1 << 11)


#define USART_CR2_CPOL (1 << 10)


#define USART_CR2_CPHA (1 << 9)


#define USART_CR2_LBCL (1 << 8)


#define USART_CR2_LBDIE (1 << 6)


#define USART_CR2_LBDL (1 << 5)


#define USART_CR2_ADD_MASK 0xF





#define USART_CR3_CTSIE (1 << 10)



#define USART_CR3_CTSE (1 << 9)



#define USART_CR3_RTSE (1 << 8)



#define USART_CR3_DMAT (1 << 7)



#define USART_CR3_DMAR (1 << 6)



#define USART_CR3_SCEN (1 << 5)



#define USART_CR3_NACK (1 << 4)


#define USART_CR3_HDSEL (1 << 3)


#define USART_CR3_IRLP (1 << 2)


#define USART_CR3_IREN (1 << 1)


#define USART_CR3_EIE (1 << 0)





#define USART_GTPR_GT_MASK (0xFF << 8)



#define USART_GTPR_PSC_MASK 0xFF







#define USART6 USART6_BASE
#define UART7 UART7_BASE
#define UART8 UART8_BASE





#define USART6_SR USART_SR(USART6_BASE)
#define UART7_SR USART_SR(UART7)
#define UART8_SR USART_SR(UART8)


#define USART6_DR USART_DR(USART6_BASE)
#define UART7_DR USART_DR(UART7)
#define UART8_DR USART_DR(UART8)


#define USART6_BRR USART_BRR(USART6_BASE)
#define UART7_BRR USART_BRR(UART7)
#define UART8_BRR USART_BRR(UART8)


#define USART6_CR1 USART_CR1(USART6_BASE)
#define UART7_CR1 USART_CR1(UART7)
#define UART8_CR1 USART_CR1(UART8)


#define USART6_CR2 USART_CR2(USART6_BASE)
#define UART7_CR2 USART_CR2(UART7)
#define UART8_CR2 USART_CR2(UART8)


#define USART6_CR3 USART_CR3(USART6_BASE)
#define UART7_CR3 USART_CR3(UART7)
#define UART8_CR3 USART_CR3(UART8)


#define USART6_GTPR USART_GTPR(USART6_BASE)
#define UART7_GTPR USART_GTPR(UART7)
#define UART8_GTPR USART_GTPR(UART8)




#define USART_CR1_OVER8 (1 << 15)




#define USART_CR3_ONEBIT (1 << 11)







int _write(int fd, char *ptr, int len);
int _read(int fd, char *ptr, int len);
void get_buffered_line(void);




#define BUFLEN 127

static uint16_t start_ndx;
static uint16_t end_ndx;
static char buf[127 +1];
#define buf_len ((end_ndx - start_ndx) % BUFLEN)
static inline int inc_ndx(int n) { return ((n + 1) % 127); }
static inline int dec_ndx(int n) { return (((n + 127) - 1) % 127); }


static void clock_setup(void)
{

 rcc_periph_clock_enable(RCC_GPIOA);


 rcc_periph_clock_enable(RCC_USART2);
}

static void usart_setup(void)
{

 usart_set_baudrate((((0x40000000U) + 0x00000) + 0x4400), 115200);
 usart_set_databits((((0x40000000U) + 0x00000) + 0x4400), 8);
 usart_set_stopbits((((0x40000000U) + 0x00000) + 0x4400), (0x00 << 12));
 usart_set_mode((((0x40000000U) + 0x00000) + 0x4400), ((1 << 2) | (1 << 3)));
 usart_set_parity((((0x40000000U) + 0x00000) + 0x4400), 0x00);
 usart_set_flow_control((((0x40000000U) + 0x00000) + 0x4400), 0x00);


 usart_enable((((0x40000000U) + 0x00000) + 0x4400));
}

static void gpio_setup(void)
{

 gpio_mode_setup((((0x40000000U) + 0x20000) + 0x0000), 0x1, 0x0, (1 << 5));


 gpio_mode_setup((((0x40000000U) + 0x20000) + 0x0000), 0x2, 0x0, (1 << 2) | (1 << 3));


 gpio_set_af((((0x40000000U) + 0x20000) + 0x0000), 0x7, (1 << 2) | (1 << 3));
}

int main(void)
{
 int i, j;

 clock_setup();
 gpio_setup();
 usart_setup();
 printf("\nStandard I/O Example.\n");


 while (1) {
  int delay = 0;
  char local_buf[32];

  gpio_toggle((((0x40000000U) + 0x20000) + 0x0000), (1 << 5));
  do {
   printf("Enter the delay constant for blink : ");
   fflush(
         ((_impure_ptr)->_stdout)
               );
   fgets(local_buf, 32, 
                       ((_impure_ptr)->_stdin)
                            );
   delay = atoi(local_buf);
   if (delay <= 0) {
    printf("Error: expected a delay > 0\n");
   }
  } while (delay <= 0);

  printf("Blinking with a delay of %d\n", delay);
  for (j = 0; j < 1000; j++) {
   gpio_toggle((((0x40000000U) + 0x20000) + 0x0000), (1 << 5));
   for (i = 0; i < delay; i++) {
    __asm__("NOP");
   }
  }
 }
 return 0;
}


static inline void back_up(void)
{
 end_ndx = dec_ndx(end_ndx);
 usart_send_blocking((((0x40000000U) + 0x00000) + 0x4400), '\010');
 usart_send_blocking((((0x40000000U) + 0x00000) + 0x4400), ' ');
 usart_send_blocking((((0x40000000U) + 0x00000) + 0x4400), '\010');
}




void
get_buffered_line(void) {
 char c;

 if (start_ndx != end_ndx) {
  return;
 }
 while (1) {
  c = usart_recv_blocking((((0x40000000U) + 0x00000) + 0x4400));
  if (c == '\r') {
   buf[end_ndx] = '\n';
   end_ndx = inc_ndx(end_ndx);
   buf[end_ndx] = '\0';
   usart_send_blocking((((0x40000000U) + 0x00000) + 0x4400), '\r');
   usart_send_blocking((((0x40000000U) + 0x00000) + 0x4400), '\n');
   return;
  }

  if ((c == '\010') || (c == '\177')) {
   if (((end_ndx - start_ndx) % 127) == 0) {
    usart_send_blocking((((0x40000000U) + 0x00000) + 0x4400), '\a');
   } else {
    back_up();
   }

  } else if (c == 0x17) {
   while ((((end_ndx - start_ndx) % 127) > 0) &&
     (!(
       ((((_ctype_)+sizeof(""[
       (int) buf[end_ndx]
       ]))[(int)(
       (int) buf[end_ndx]
       )])&010)
                                  ))) {
    back_up();
   }

  } else if (c == 0x15) {
   while (((end_ndx - start_ndx) % 127) > 0) {
    back_up();
   }

  } else {
   if (((end_ndx - start_ndx) % 127) == (127 - 1)) {
    usart_send_blocking((((0x40000000U) + 0x00000) + 0x4400), '\a');
   } else {
    buf[end_ndx] = c;
    end_ndx = inc_ndx(end_ndx);
    usart_send_blocking((((0x40000000U) + 0x00000) + 0x4400), c);
   }
  }
 }
}





int
_write(int fd, char *ptr, int len)
{
 int i = 0;







 if (fd > 2) {
  return -1;
 }
 while (*ptr && (i < len)) {
  usart_send_blocking((((0x40000000U) + 0x00000) + 0x4400), *ptr);
  if (*ptr == '\n') {
   usart_send_blocking((((0x40000000U) + 0x00000) + 0x4400), '\r');
  }
  i++;
  ptr++;
 }
 return i;
}






int
_read(int fd, char *ptr, int len)
{
 int my_len;

 if (fd > 2) {
  return -1;
 }

 get_buffered_line();
 my_len = 0;
 while ((((end_ndx - start_ndx) % 127) > 0) && (len > 0)) {
  *ptr++ = buf[start_ndx];
  start_ndx = inc_ndx(start_ndx);
  my_len++;
  len--;
 }
 return my_len;
}
