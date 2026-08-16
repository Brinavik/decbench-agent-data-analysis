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
#define LIBOPENCM3_TOOLS_H 






#define GET_REG(REG) ((uint16_t) *(REG))


#define SET_REG(REG,VAL) (*(REG) = (uint16_t)(VAL))


#define CLR_REG_BIT(REG,BIT) SET_REG((REG), (~(BIT)))


#define CLR_REG_BIT_MSK_AND_SET(REG,MSK,BIT,EXTRA_BITS) SET_REG((REG), (GET_REG((REG)) & (MSK) & (~(BIT))) | (EXTRA_BITS))


#define CLR_REG_BIT_MSK(REG,MSK,BIT) CLR_REG_BIT_MSK_AND_SET((REG), (MSK), (BIT), 0)



#define GET_REG_BIT(REG,BIT) (GET_REG(REG) & (BIT))
#define TOG_SET_REG_BIT_MSK_AND_SET(REG,MSK,BIT,EXTRA_BITS) do { register uint16_t toggle_mask = GET_REG(REG) & (MSK); toggle_mask ^= BIT; SET_REG((REG), toggle_mask | (EXTRA_BITS)); } while (0)






#define TOG_SET_REG_BIT_MSK(REG,MSK,BIT) TOG_SET_REG_BIT_MSK_AND_SET((REG), (MSK), (BIT), 0)
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


#define __USBD_H 

#define __USBSTD_H 
struct usb_setup_data {
 uint8_t bmRequestType;
 uint8_t bRequest;
 uint16_t wValue;
 uint16_t wIndex;
 uint16_t wLength;
} __attribute__((packed));


#define USB_CLASS_VENDOR 0xFF



#define USB_REQ_TYPE_DIRECTION 0x80
#define USB_REQ_TYPE_IN 0x80
#define USB_REQ_TYPE_OUT 0x0

#define USB_REQ_TYPE_TYPE 0x60
#define USB_REQ_TYPE_STANDARD 0x00
#define USB_REQ_TYPE_CLASS 0x20
#define USB_REQ_TYPE_VENDOR 0x40

#define USB_REQ_TYPE_RECIPIENT 0x1F
#define USB_REQ_TYPE_DEVICE 0x00
#define USB_REQ_TYPE_INTERFACE 0x01
#define USB_REQ_TYPE_ENDPOINT 0x02
#define USB_REQ_TYPE_OTHER 0x03


#define USB_REQ_GET_STATUS 0
#define USB_REQ_CLEAR_FEATURE 1

#define USB_REQ_SET_FEATURE 3

#define USB_REQ_SET_ADDRESS 5
#define USB_REQ_GET_DESCRIPTOR 6
#define USB_REQ_SET_DESCRIPTOR 7
#define USB_REQ_GET_CONFIGURATION 8
#define USB_REQ_SET_CONFIGURATION 9
#define USB_REQ_GET_INTERFACE 10
#define USB_REQ_SET_INTERFACE 11
#define USB_REQ_SET_SYNCH_FRAME 12


#define USB_DT_DEVICE 1
#define USB_DT_CONFIGURATION 2
#define USB_DT_STRING 3
#define USB_DT_INTERFACE 4
#define USB_DT_ENDPOINT 5
#define USB_DT_DEVICE_QUALIFIER 6
#define USB_DT_OTHER_SPEED_CONFIGURATION 7
#define USB_DT_INTERFACE_POWER 8

#define USB_DT_OTG 9
#define USB_DT_DEBUG 10
#define USB_DT_INTERFACE_ASSOCIATION 11


#define USB_FEAT_ENDPOINT_HALT 0
#define USB_FEAT_DEVICE_REMOTE_WAKEUP 1
#define USB_FEAT_TEST_MODE 2


#define USB_DEV_STATUS_SELF_POWERED 0x01
#define USB_DEV_STATUS_REMOTE_WAKEUP 0x02


struct usb_device_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint16_t bcdUSB;
 uint8_t bDeviceClass;
 uint8_t bDeviceSubClass;
 uint8_t bDeviceProtocol;
 uint8_t bMaxPacketSize0;
 uint16_t idVendor;
 uint16_t idProduct;
 uint16_t bcdDevice;
 uint8_t iManufacturer;
 uint8_t iProduct;
 uint8_t iSerialNumber;
 uint8_t bNumConfigurations;
} __attribute__((packed));

#define USB_DT_DEVICE_SIZE sizeof(struct usb_device_descriptor)




struct usb_device_qualifier_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint16_t bcdUSB;
 uint8_t bDeviceClass;
 uint8_t bDeviceSubClass;
 uint8_t bDeviceProtocol;
 uint8_t bMaxPacketSize0;
 uint8_t bNumConfigurations;
 uint8_t bReserved;
} __attribute__((packed));




struct usb_interface {
 uint8_t *cur_altsetting;
 uint8_t num_altsetting;
 const struct usb_iface_assoc_descriptor *iface_assoc;
 const struct usb_interface_descriptor *altsetting;
};


struct usb_config_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint16_t wTotalLength;
 uint8_t bNumInterfaces;
 uint8_t bConfigurationValue;
 uint8_t iConfiguration;
 uint8_t bmAttributes;
 uint8_t bMaxPower;


 const struct usb_interface *interface;
} __attribute__((packed));
#define USB_DT_CONFIGURATION_SIZE 9


#define USB_CONFIG_ATTR_DEFAULT 0x80
#define USB_CONFIG_ATTR_SELF_POWERED 0x40
#define USB_CONFIG_ATTR_REMOTE_WAKEUP 0x20






struct usb_interface_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bInterfaceNumber;
 uint8_t bAlternateSetting;
 uint8_t bNumEndpoints;
 uint8_t bInterfaceClass;
 uint8_t bInterfaceSubClass;
 uint8_t bInterfaceProtocol;
 uint8_t iInterface;


 const struct usb_endpoint_descriptor *endpoint;
 const void *extra;
 int extralen;
} __attribute__((packed));
#define USB_DT_INTERFACE_SIZE 9


struct usb_endpoint_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bEndpointAddress;
 uint8_t bmAttributes;
 uint16_t wMaxPacketSize;
 uint8_t bInterval;


 const void *extra;
 int extralen;
} __attribute__((packed));
#define USB_DT_ENDPOINT_SIZE 7


#define USB_ENDPOINT_ADDR_OUT(x) (x)
#define USB_ENDPOINT_ADDR_IN(x) (0x80 | (x))



#define USB_ENDPOINT_ATTR_CONTROL 0x00
#define USB_ENDPOINT_ATTR_ISOCHRONOUS 0x01
#define USB_ENDPOINT_ATTR_BULK 0x02
#define USB_ENDPOINT_ATTR_INTERRUPT 0x03
#define USB_ENDPOINT_ATTR_TYPE 0x03

#define USB_ENDPOINT_ATTR_NOSYNC 0x00
#define USB_ENDPOINT_ATTR_ASYNC 0x04
#define USB_ENDPOINT_ATTR_ADAPTIVE 0x08
#define USB_ENDPOINT_ATTR_SYNC 0x0C
#define USB_ENDPOINT_ATTR_SYNCTYPE 0x0C

#define USB_ENDPOINT_ATTR_DATA 0x00
#define USB_ENDPOINT_ATTR_FEEDBACK 0x10
#define USB_ENDPOINT_ATTR_IMPLICIT_FEEDBACK_DATA 0x20
#define USB_ENDPOINT_ATTR_USAGETYPE 0x30




struct usb_string_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint16_t wData[];
} __attribute__((packed));


struct usb_iface_assoc_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bFirstInterface;
 uint8_t bInterfaceCount;
 uint8_t bFunctionClass;
 uint8_t bFunctionSubClass;
 uint8_t bFunctionProtocol;
 uint8_t iFunction;
} __attribute__((packed));
#define USB_DT_INTERFACE_ASSOCIATION_SIZE sizeof(struct usb_iface_assoc_descriptor)


enum usb_language_id {
 USB_LANGID_ENGLISH_US = 0x409,
};




enum usbd_request_return_codes {
 USBD_REQ_NOTSUPP = 0,
 USBD_REQ_HANDLED = 1,
 USBD_REQ_NEXT_CALLBACK = 2,
};

typedef struct _usbd_driver usbd_driver;
typedef struct _usbd_device usbd_device;

extern const usbd_driver st_usbfs_v1_usb_driver;
extern const usbd_driver stm32f107_usb_driver;
extern const usbd_driver stm32f207_usb_driver;
extern const usbd_driver st_usbfs_v2_usb_driver;
#define otgfs_usb_driver stm32f107_usb_driver
#define otghs_usb_driver stm32f207_usb_driver
extern const usbd_driver efm32lg_usb_driver;
extern const usbd_driver efm32hg_usb_driver;
extern const usbd_driver lm4f_usb_driver;
extern usbd_device * usbd_init(const usbd_driver *driver,
          const struct usb_device_descriptor *dev,
          const struct usb_config_descriptor *conf,
          const char * const *strings, int num_strings,
          uint8_t *control_buffer,
          uint16_t control_buffer_size);


extern void usbd_register_reset_callback(usbd_device *usbd_dev,
      void (*callback)(void));

extern void usbd_register_suspend_callback(usbd_device *usbd_dev,
        void (*callback)(void));

extern void usbd_register_resume_callback(usbd_device *usbd_dev,
       void (*callback)(void));

extern void usbd_register_sof_callback(usbd_device *usbd_dev,
           void (*callback)(void));

typedef void (*usbd_control_complete_callback)(usbd_device *usbd_dev,
  struct usb_setup_data *req);

typedef enum usbd_request_return_codes (*usbd_control_callback)(
  usbd_device *usbd_dev,
  struct usb_setup_data *req, uint8_t **buf, uint16_t *len,
  usbd_control_complete_callback *complete);

typedef void (*usbd_set_config_callback)(usbd_device *usbd_dev,
      uint16_t wValue);

typedef void (*usbd_set_altsetting_callback)(usbd_device *usbd_dev,
          uint16_t wIndex, uint16_t wValue);

typedef void (*usbd_endpoint_callback)(usbd_device *usbd_dev, uint8_t ep);
extern int usbd_register_control_callback(usbd_device *usbd_dev, uint8_t type,
       uint8_t type_mask,
       usbd_control_callback callback);
extern int usbd_register_set_config_callback(usbd_device *usbd_dev,
       usbd_set_config_callback callback);




extern void usbd_register_set_altsetting_callback(usbd_device *usbd_dev,
     usbd_set_altsetting_callback callback);


extern void usbd_register_extra_string(usbd_device *usbd_dev, int index, const char* string);


extern void usbd_poll(usbd_device *usbd_dev);
extern void usbd_disconnect(usbd_device *usbd_dev, 
                                                  _Bool 
                                                       disconnected);
extern void usbd_ep_setup(usbd_device *usbd_dev, uint8_t addr, uint8_t type,
  uint16_t max_size, usbd_endpoint_callback callback);
extern uint16_t usbd_ep_write_packet(usbd_device *usbd_dev, uint8_t addr,
    const void *buf, uint16_t len);
extern uint16_t usbd_ep_read_packet(usbd_device *usbd_dev, uint8_t addr,
          void *buf, uint16_t len);





extern void usbd_ep_stall_set(usbd_device *usbd_dev, uint8_t addr,
         uint8_t stall);






extern uint8_t usbd_ep_stall_get(usbd_device *usbd_dev, uint8_t addr);






extern void usbd_ep_nak_set(usbd_device *usbd_dev, uint8_t addr, uint8_t nak);


#define LIBOPENCM3_USB_DWC_OTG_FS_H 


#define LIBOPENCM3_USB_DWC_OTG_COMMON_H 


#define OTG_GOTGCTL 0x000
#define OTG_GOTGINT 0x004
#define OTG_GAHBCFG 0x008
#define OTG_GUSBCFG 0x00C
#define OTG_GRSTCTL 0x010
#define OTG_GINTSTS 0x014
#define OTG_GINTMSK 0x018
#define OTG_GRXSTSR 0x01C
#define OTG_GRXSTSP 0x020
#define OTG_GRXFSIZ 0x024
#define OTG_GNPTXFSIZ 0x028
#define OTG_GNPTXSTS 0x02C
#define OTG_GCCFG 0x038
#define OTG_CID 0x03C
#define OTG_HPTXFSIZ 0x100
#define OTG_DIEPTXF(x) (0x104 + 4*((x)-1))


#define OTG_HCFG 0x400
#define OTG_HFIR 0x404
#define OTG_HFNUM 0x408
#define OTG_HPTXSTS 0x410
#define OTG_HAINT 0x414
#define OTG_HAINTMSK 0x418
#define OTG_HPRT 0x440
#define OTG_HCCHAR(x) (0x500 + 0x20*(x))
#define OTG_HCINT(x) (0x508 + 0x20*(x))
#define OTG_HCINTMSK(x) (0x50C + 0x20*(x))
#define OTG_HCTSIZ(x) (0x510 + 0x20*(x))



#define OTG_DCFG 0x800
#define OTG_DCTL 0x804
#define OTG_DSTS 0x808
#define OTG_DIEPMSK 0x810
#define OTG_DOEPMSK 0x814
#define OTG_DAINT 0x818
#define OTG_DAINTMSK 0x81C
#define OTG_DVBUSDIS 0x828
#define OTG_DVBUSPULSE 0x82C
#define OTG_DIEPEMPMSK 0x834

#define OTG_DIEPCTL0 0x900
#define OTG_DIEPCTL(x) (0x900 + 0x20*(x))
#define OTG_DOEPCTL0 0xB00
#define OTG_DOEPCTL(x) (0xB00 + 0x20*(x))
#define OTG_DIEPINT(x) (0x908 + 0x20*(x))
#define OTG_DOEPINT(x) (0xB08 + 0x20*(x))
#define OTG_DIEPTSIZ0 0x910
#define OTG_DIEPTSIZ(x) (0x910 + 0x20*(x))
#define OTG_DOEPTSIZ0 0xB10
#define OTG_DOEPTSIZ(x) (0xB10 + 0x20*(x))
#define OTG_DTXFSTS(x) (0x918 + 0x20*(x))


#define OTG_PCGCCTL 0xE00


#define OTG_FIFO(x) (((x) + 1) << 12)




#define OTG_GOTGCTL_BSVLD (1 << 19)
#define OTG_GOTGCTL_ASVLD (1 << 18)
#define OTG_GOTGCTL_DBCT (1 << 17)
#define OTG_GOTGCTL_CIDSTS (1 << 16)
#define OTG_GOTGCTL_DHNPEN (1 << 11)
#define OTG_GOTGCTL_HSHNPEN (1 << 10)
#define OTG_GOTGCTL_HNPRQ (1 << 9)
#define OTG_GOTGCTL_HNGSCS (1 << 8)
#define OTG_GOTGCTL_SRQ (1 << 1)
#define OTG_GOTGCTL_SRQSCS (1 << 0)


#define OTG_GOTGINT_DBCDNE (1 << 19)
#define OTG_GOTGINT_ADTOCHG (1 << 18)
#define OTG_GOTGINT_HNGDET (1 << 17)
#define OTG_GOTGINT_HNSSCHG (1 << 9)
#define OTG_GOTGINT_SRSSCHG (1 << 8)
#define OTG_GOTGINT_SEDET (1 << 2)


#define OTG_GAHBCFG_GINT 0x0001
#define OTG_GAHBCFG_TXFELVL 0x0080
#define OTG_GAHBCFG_PTXFELVL 0x0100


#define OTG_GUSBCFG_TOCAL 0x00000003
#define OTG_GUSBCFG_SRPCAP 0x00000100
#define OTG_GUSBCFG_HNPCAP 0x00000200
#define OTG_GUSBCFG_TRDT_MASK (0xf << 10)
#define OTG_GUSBCFG_NPTXRWEN 0x00004000
#define OTG_GUSBCFG_FHMOD 0x20000000
#define OTG_GUSBCFG_FDMOD 0x40000000
#define OTG_GUSBCFG_CTXPKT 0x80000000
#define OTG_GUSBCFG_PHYSEL (1 << 6)


#define OTG_GRSTCTL_AHBIDL (1 << 31)

#define OTG_GRSTCTL_TXFNUM_MASK (0x1f << 6)
#define OTG_GRSTCTL_TXFNUM_ALL (0x10 << 6)
#define OTG_GRSTCTL_TXFFLSH (1 << 5)
#define OTG_GRSTCTL_RXFFLSH (1 << 4)

#define OTG_GRSTCTL_FCRST (1 << 2)
#define OTG_GRSTCTL_HSRST (1 << 1)
#define OTG_GRSTCTL_CSRST (1 << 0)


#define OTG_GINTSTS_WKUPINT (1 << 31)
#define OTG_GINTSTS_SRQINT (1 << 30)
#define OTG_GINTSTS_DISCINT (1 << 29)
#define OTG_GINTSTS_CIDSCHG (1 << 28)

#define OTG_GINTSTS_PTXFE (1 << 26)
#define OTG_GINTSTS_HCINT (1 << 25)
#define OTG_GINTSTS_HPRTINT (1 << 24)

#define OTG_GINTSTS_IPXFR (1 << 21)
#define OTG_GINTSTS_INCOMPISOOUT (1 << 21)
#define OTG_GINTSTS_IISOIXFR (1 << 20)
#define OTG_GINTSTS_OEPINT (1 << 19)
#define OTG_GINTSTS_IEPINT (1 << 18)

#define OTG_GINTSTS_EOPF (1 << 15)
#define OTG_GINTSTS_ISOODRP (1 << 14)
#define OTG_GINTSTS_ENUMDNE (1 << 13)
#define OTG_GINTSTS_USBRST (1 << 12)
#define OTG_GINTSTS_USBSUSP (1 << 11)
#define OTG_GINTSTS_ESUSP (1 << 10)

#define OTG_GINTSTS_GONAKEFF (1 << 7)
#define OTG_GINTSTS_GINAKEFF (1 << 6)
#define OTG_GINTSTS_NPTXFE (1 << 5)
#define OTG_GINTSTS_RXFLVL (1 << 4)
#define OTG_GINTSTS_SOF (1 << 3)
#define OTG_GINTSTS_OTGINT (1 << 2)
#define OTG_GINTSTS_MMIS (1 << 1)
#define OTG_GINTSTS_CMOD (1 << 0)


#define OTG_GINTMSK_MMISM 0x00000002
#define OTG_GINTMSK_OTGINT 0x00000004
#define OTG_GINTMSK_SOFM 0x00000008
#define OTG_GINTMSK_RXFLVLM 0x00000010
#define OTG_GINTMSK_NPTXFEM 0x00000020
#define OTG_GINTMSK_GINAKEFFM 0x00000040
#define OTG_GINTMSK_GONAKEFFM 0x00000080
#define OTG_GINTMSK_ESUSPM 0x00000400
#define OTG_GINTMSK_USBSUSPM 0x00000800
#define OTG_GINTMSK_USBRST 0x00001000
#define OTG_GINTMSK_ENUMDNEM 0x00002000
#define OTG_GINTMSK_ISOODRPM 0x00004000
#define OTG_GINTMSK_EOPFM 0x00008000
#define OTG_GINTMSK_EPMISM 0x00020000
#define OTG_GINTMSK_IEPINT 0x00040000
#define OTG_GINTMSK_OEPINT 0x00080000
#define OTG_GINTMSK_IISOIXFRM 0x00100000
#define OTG_GINTMSK_IISOOXFRM 0x00200000
#define OTG_GINTMSK_IPXFRM 0x00200000
#define OTG_GINTMSK_PRTIM 0x01000000
#define OTG_GINTMSK_HCIM 0x02000000
#define OTG_GINTMSK_PTXFEM 0x04000000
#define OTG_GINTMSK_CIDSCHGM 0x10000000
#define OTG_GINTMSK_DISCINT 0x20000000
#define OTG_GINTMSK_SRQIM 0x40000000
#define OTG_GINTMSK_WUIM 0x80000000



#define OTG_GRXSTSP_FRMNUM_MASK (0xf << 21)
#define OTG_GRXSTSP_PKTSTS_MASK (0xf << 17)
#define OTG_GRXSTSP_PKTSTS_GOUTNAK (0x1 << 17)
#define OTG_GRXSTSP_PKTSTS_OUT (0x2 << 17)
#define OTG_GRXSTSP_PKTSTS_IN (0x2 << 17)
#define OTG_GRXSTSP_PKTSTS_OUT_COMP (0x3 << 17)
#define OTG_GRXSTSP_PKTSTS_IN_COMP (0x3 << 17)
#define OTG_GRXSTSP_PKTSTS_SETUP_COMP (0x4 << 17)
#define OTG_GRXSTSP_PKTSTS_DTERR (0x5 << 17)
#define OTG_GRXSTSP_PKTSTS_SETUP (0x6 << 17)
#define OTG_GRXSTSP_PKTSTS_CHH (0x7 << 17)
#define OTG_GRXSTSP_DPID_MASK (0x3 << 15)
#define OTG_GRXSTSP_DPID_DATA0 (0x0 << 15)
#define OTG_GRXSTSP_DPID_DATA1 (0x2 << 15)
#define OTG_GRXSTSP_DPID_DATA2 (0x1 << 15)
#define OTG_GRXSTSP_DPID_MDATA (0x3 << 15)
#define OTG_GRXSTSP_BCNT_MASK (0x7ff << 4)
#define OTG_GRXSTSP_EPNUM_MASK (0xf << 0)



#define OTG_GCCFG_NOVBUSSENS (1 << 21)

#define OTG_GCCFG_VBDEN (1 << 21)
#define OTG_GCCFG_SOFOUTEN (1 << 20)
#define OTG_GCCFG_VBUSBSEN (1 << 19)
#define OTG_GCCFG_VBUSASEN (1 << 18)

#define OTG_GCCFG_PWRDWN (1 << 16)



#define OTG_CID_HAS_VBDEN 0x00002000




#define OTG_DCTL_POPRGDNE (1 << 11)
#define OTG_DCTL_CGONAK (1 << 10)
#define OTG_DCTL_SGONAK (1 << 9)
#define OTG_DCTL_SGINAK (1 << 8)
#define OTG_DCTL_TCTL_MASK (7 << 4)
#define OTG_DCTL_GONSTS (1 << 3)
#define OTG_DCTL_GINSTS (1 << 2)
#define OTG_DCTL_SDIS (1 << 1)
#define OTG_DCTL_RWUSIG (1 << 0)


#define OTG_DCFG_DSPD 0x0003
#define OTG_DCFG_NZLSOHSK 0x0004
#define OTG_DCFG_DAD 0x07F0
#define OTG_DCFG_PFIVL 0x1800


#define OTG_DSTS_SUSPSTS (1 << 0)



#define OTG_DIEPMSK_BIM (1 << 9)
#define OTG_DIEPMSK_TXFURM (1 << 8)

#define OTG_DIEPMSK_INEPNEM (1 << 6)
#define OTG_DIEPMSK_INEPNMM (1 << 5)
#define OTG_DIEPMSK_ITTXFEMSK (1 << 4)
#define OTG_DIEPMSK_TOM (1 << 3)

#define OTG_DIEPMSK_EPDM (1 << 1)
#define OTG_DIEPMSK_XFRCM (1 << 0)



#define OTG_DOEPMSK_BOIM (1 << 9)
#define OTG_DOEPMSK_OPEM (1 << 8)

#define OTG_DOEPMSK_B2BSTUP (1 << 6)

#define OTG_DOEPMSK_OTEPDM (1 << 4)
#define OTG_DOEPMSK_STUPM (1 << 3)

#define OTG_DOEPMSK_EPDM (1 << 1)
#define OTG_DOEPMSK_XFRCM (1 << 0)


#define OTG_DIEPCTL0_EPENA (1 << 31)
#define OTG_DIEPCTL0_EPDIS (1 << 30)

#define OTG_DIEPCTLX_SD0PID (1 << 28)
#define OTG_DIEPCTL0_SNAK (1 << 27)
#define OTG_DIEPCTL0_CNAK (1 << 26)
#define OTG_DIEPCTL0_TXFNUM_MASK (0xf << 22)
#define OTG_DIEPCTL0_STALL (1 << 21)

#define OTG_DIEPCTL0_EPTYP_MASK (0x3 << 18)
#define OTG_DIEPCTL0_NAKSTS (1 << 17)

#define OTG_DIEPCTL0_USBAEP (1 << 15)

#define OTG_DIEPCTL0_MPSIZ_MASK (0x3 << 0)
#define OTG_DIEPCTL0_MPSIZ_64 (0x0 << 0)
#define OTG_DIEPCTL0_MPSIZ_32 (0x1 << 0)
#define OTG_DIEPCTL0_MPSIZ_16 (0x2 << 0)
#define OTG_DIEPCTL0_MPSIZ_8 (0x3 << 0)


#define OTG_DOEPCTL0_EPENA (1 << 31)
#define OTG_DOEPCTL0_EPDIS (1 << 30)

#define OTG_DOEPCTLX_SD0PID (1 << 28)
#define OTG_DOEPCTL0_SNAK (1 << 27)
#define OTG_DOEPCTL0_CNAK (1 << 26)

#define OTG_DOEPCTL0_STALL (1 << 21)
#define OTG_DOEPCTL0_SNPM (1 << 20)
#define OTG_DOEPCTL0_EPTYP_MASK (0x3 << 18)
#define OTG_DOEPCTL0_NAKSTS (1 << 17)

#define OTG_DOEPCTL0_USBAEP (1 << 15)

#define OTG_DOEPCTL0_MPSIZ_MASK (0x3 << 0)
#define OTG_DOEPCTL0_MPSIZ_64 (0x0 << 0)
#define OTG_DOEPCTL0_MPSIZ_32 (0x1 << 0)
#define OTG_DOEPCTL0_MPSIZ_16 (0x2 << 0)
#define OTG_DOEPCTL0_MPSIZ_8 (0x3 << 0)



#define OTG_DIEPINTX_TXFE (1 << 7)
#define OTG_DIEPINTX_INEPNE (1 << 6)

#define OTG_DIEPINTX_ITTXFE (1 << 4)
#define OTG_DIEPINTX_TOC (1 << 3)

#define OTG_DIEPINTX_EPDISD (1 << 1)
#define OTG_DIEPINTX_XFRC (1 << 0)



#define OTG_DOEPINTX_B2BSTUP (1 << 6)

#define OTG_DOEPINTX_OTEPDIS (1 << 4)
#define OTG_DOEPINTX_STUP (1 << 3)

#define OTG_DOEPINTX_EPDISD (1 << 1)
#define OTG_DOEPINTX_XFRC (1 << 0)



#define OTG_DIEPSIZ0_STUPCNT_1 (0x1 << 29)
#define OTG_DIEPSIZ0_STUPCNT_2 (0x2 << 29)
#define OTG_DIEPSIZ0_STUPCNT_3 (0x3 << 29)
#define OTG_DIEPSIZ0_STUPCNT_MASK (0x3 << 29)

#define OTG_DIEPSIZ0_PKTCNT (1 << 19)

#define OTG_DIEPSIZ0_XFRSIZ_MASK (0x7f << 0)






#define OTG_HNPTXFSIZ_PTXFD_MASK (0xffff0000)
#define OTG_HNPTXFSIZ_PTXSA_MASK (0x0000ffff)


#define OTG_HPTXFSIZ_PTXFD_MASK (0xffff0000)
#define OTG_HPTXFSIZ_PTXSA_MASK (0x0000ffff)



#define OTG_HCFG_FSLSS (1 << 2)
#define OTG_HCFG_FSLSPCS_48MHz (0x1 << 0)
#define OTG_HCFG_FSLSPCS_6MHz (0x2 << 0)
#define OTG_HCFG_FSLSPCS_MASK (0x3 << 0)



#define OTG_HFIR_FRIVL_MASK (0x0000ffff)


#define OTG_HFNUM_FTREM_MASK (0xffff0000)
#define OTG_HFNUM_FRNUM_MASK (0x0000ffff)


#define OTG_HPTXSTS_PTXQTOP_MASK (0xff000000)
#define OTG_HPTXSTS_PTXQTOP_ODDFRM (1<<31)
#define OTG_HPTXSTS_PTXQTOP_EVENFRM (0<<31)
#define OTG_HPTXSTS_PTXQTOP_CHANNEL_NUMBER_MASK (0xf<<27)
#define OTG_HPTXSTS_PTXQTOP_ENDPOINT_NUMBER_MASK (0xf<<27)
#define OTG_HPTXSTS_PTXQTOP_TYPE_INOUT (0x00<<25)
#define OTG_HPTXSTS_PTXQTOP_TYPE_ZEROLENGTH (0x01<<25)
#define OTG_HPTXSTS_PTXQTOP_TYPE_DISABLECMD (0x11<<25)
#define OTG_HPTXSTS_PTXQTOP_TERMINATE (1<<24)
#define OTG_HPTXSTS_PTXQSAV_MASK (0x00ff0000)
#define OTG_HPTXSTS_PTXFSAVL_MASK (0x0000ffff)



#define OTG_HAINTMSK_HAINT_MASK (0x0000ffff)



#define OTG_HAINTMSK_HAINTM_MASK (0x0000ffff)



#define OTG_HPRT_PSPD_HIGH (0x0 << 17)
#define OTG_HPRT_PSPD_FULL (0x1 << 17)
#define OTG_HPRT_PSPD_LOW (0x2 << 17)
#define OTG_HPRT_PSPD_MASK (0x3 << 17)
#define OTG_HPRT_PTCTL_DISABLED (0x0 << 13)
#define OTG_HPRT_PTCTL_J (0x1 << 13)
#define OTG_HPRT_PTCTL_K (0x2 << 13)
#define OTG_HPRT_PTCTL_SE0_NAK (0x3 << 13)
#define OTG_HPRT_PTCTL_PACKET (0x4 << 13)
#define OTG_HPRT_PTCTL_FORCE_ENABLE (0x5 << 13)
#define OTG_HPRT_PPWR (1 << 12)
#define OTG_HPRT_PLSTS_DM (1 << 11)
#define OTG_HPRT_PLSTS_DP (1 << 10)

#define OTG_HPRT_PRST (1 << 8)
#define OTG_HPRT_PSUSP (1 << 7)
#define OTG_HPRT_PRES (1 << 6)
#define OTG_HPRT_POCCHNG (1 << 5)
#define OTG_HPRT_POCA (1 << 4)
#define OTG_HPRT_PENCHNG (1 << 3)
#define OTG_HPRT_PENA (1 << 2)
#define OTG_HPRT_PCDET (1 << 1)
#define OTG_HPRT_PCSTS (1 << 0)


#define OTG_HCCHAR_CHENA (1 << 31)
#define OTG_HCCHAR_CHDIS (1 << 30)
#define OTG_HCCHAR_ODDFRM (1 << 29)
#define OTG_HCCHAR_DAD_MASK (0x7f << 22)
#define OTG_HCCHAR_MCNT_1 (0x1 << 20)
#define OTG_HCCHAR_MCNT_2 (0x2 << 20)
#define OTG_HCCHAR_MCNT_3 (0x3 << 20)
#define OTG_HCCHAR_MCNT_MASK (0x3 << 20)
#define OTG_HCCHAR_EPTYP_CONTROL (0 << 18)
#define OTG_HCCHAR_EPTYP_ISOCHRONOUS (1 << 18)
#define OTG_HCCHAR_EPTYP_BULK (2 << 18)
#define OTG_HCCHAR_EPTYP_INTERRUPT (3 << 18)
#define OTG_HCCHAR_EPTYP_MASK (3 << 18)
#define OTG_HCCHAR_LSDEV (1 << 17)

#define OTG_HCCHAR_EPDIR_OUT (0 << 15)
#define OTG_HCCHAR_EPDIR_IN (1 << 15)
#define OTG_HCCHAR_EPDIR_MASK (1 << 15)
#define OTG_HCCHAR_EPNUM_MASK (0xf << 11)
#define OTG_HCCHAR_MPSIZ_MASK (0x7ff << 0)



#define OTG_HCINT_DTERR (1 << 10)
#define OTG_HCINT_FRMOR (1 << 9)
#define OTG_HCINT_BBERR (1 << 8)
#define OTG_HCINT_TXERR (1 << 7)

#define OTG_HCINT_NYET (1 << 6)
#define OTG_HCINT_ACK (1 << 5)
#define OTG_HCINT_NAK (1 << 4)
#define OTG_HCINT_STALL (1 << 3)

#define OTG_HCINT_AHBERR (1 << 2)
#define OTG_HCINT_CHH (1 << 1)
#define OTG_HCINT_XFRC (1 << 0)



#define OTG_HCINTMSK_DTERRM (1 << 10)
#define OTG_HCINTMSK_FRMORM (1 << 9)
#define OTG_HCINTMSK_BBERRM (1 << 8)
#define OTG_HCINTMSK_TXERRM (1 << 7)

#define OTG_HCINTMSK_NYET (1 << 6)
#define OTG_HCINTMSK_ACKM (1 << 5)
#define OTG_HCINTMSK_NAKM (1 << 4)
#define OTG_HCINTMSK_STALLM (1 << 3)

#define OTG_HCINTMSK_AHBERR (1 << 2)
#define OTG_HCINTMSK_CHHM (1 << 1)
#define OTG_HCINTMSK_XFRCM (1 << 0)



#define OTG_HCTSIZ_DOPING (1 << 31)
#define OTG_HCTSIZ_DPID_DATA0 (0x0 << 29)
#define OTG_HCTSIZ_DPID_DATA1 (0x2 << 29)
#define OTG_HCTSIZ_DPID_DATA2 (0x1 << 29)
#define OTG_HCTSIZ_DPID_MDATA (0x3 << 29)
#define OTG_HCTSIZ_DPID_MASK (0x3 << 29)
#define OTG_HCTSIZ_PKTCNT_MASK (0x3ff << 19)
#define OTG_HCTSIZ_XFRSIZ_MASK (0x7ffff << 0)
#define OTG_FS_GOTGCTL MMIO32(USB_OTG_FS_BASE + OTG_GOTGCTL)
#define OTG_FS_GOTGINT MMIO32(USB_OTG_FS_BASE + OTG_GOTGINT)
#define OTG_FS_GAHBCFG MMIO32(USB_OTG_FS_BASE + OTG_GAHBCFG)
#define OTG_FS_GUSBCFG MMIO32(USB_OTG_FS_BASE + OTG_GUSBCFG)
#define OTG_FS_GRSTCTL MMIO32(USB_OTG_FS_BASE + OTG_GRSTCTL)
#define OTG_FS_GINTSTS MMIO32(USB_OTG_FS_BASE + OTG_GINTSTS)
#define OTG_FS_GINTMSK MMIO32(USB_OTG_FS_BASE + OTG_GINTMSK)
#define OTG_FS_GRXSTSR MMIO32(USB_OTG_FS_BASE + OTG_GRXSTSR)
#define OTG_FS_GRXSTSP MMIO32(USB_OTG_FS_BASE + OTG_GRXSTSP)
#define OTG_FS_GRXFSIZ MMIO32(USB_OTG_FS_BASE + OTG_GRXFSIZ)
#define OTG_FS_GNPTXFSIZ MMIO32(USB_OTG_FS_BASE + OTG_GNPTXFSIZ)
#define OTG_FS_GNPTXSTS MMIO32(USB_OTG_FS_BASE + OTG_GNPTXSTS)
#define OTG_FS_GCCFG MMIO32(USB_OTG_FS_BASE + OTG_GCCFG)
#define OTG_FS_CID MMIO32(USB_OTG_FS_BASE + OTG_CID)
#define OTG_FS_HPTXFSIZ MMIO32(USB_OTG_FS_BASE + OTG_HPTXFSIZ)
#define OTG_FS_DIEPTXF(x) MMIO32(USB_OTG_FS_BASE + OTG_DIEPTXF(x))



#define OTG_FS_HCFG MMIO32(USB_OTG_FS_BASE + OTG_HCFG)
#define OTG_FS_HFIR MMIO32(USB_OTG_FS_BASE + OTG_HFIR)
#define OTG_FS_HFNUM MMIO32(USB_OTG_FS_BASE + OTG_HFNUM)
#define OTG_FS_HPTXSTS MMIO32(USB_OTG_FS_BASE + OTG_HPTXSTS)
#define OTG_FS_HAINT MMIO32(USB_OTG_FS_BASE + OTG_HAINT)
#define OTG_FS_HAINTMSK MMIO32(USB_OTG_FS_BASE + OTG_HAINTMSK)
#define OTG_FS_HPRT MMIO32(USB_OTG_FS_BASE + OTG_HPRT)
#define OTG_FS_HCCHAR(x) MMIO32(USB_OTG_FS_BASE + OTG_HCCHAR(x))
#define OTG_FS_HCINT(x) MMIO32(USB_OTG_FS_BASE + OTG_HCINT(x))
#define OTG_FS_HCINTMSK(x) MMIO32(USB_OTG_FS_BASE + OTG_HCINTMSK(x))
#define OTG_FS_HCTSIZ(x) MMIO32(USB_OTG_FS_BASE + OTG_HCTSIZ(x))


#define OTG_FS_DCFG MMIO32(USB_OTG_FS_BASE + OTG_DCFG)
#define OTG_FS_DCTL MMIO32(USB_OTG_FS_BASE + OTG_DCTL)
#define OTG_FS_DSTS MMIO32(USB_OTG_FS_BASE + OTG_DSTS)
#define OTG_FS_DIEPMSK MMIO32(USB_OTG_FS_BASE + OTG_DIEPMSK)
#define OTG_FS_DOEPMSK MMIO32(USB_OTG_FS_BASE + OTG_DOEPMSK)
#define OTG_FS_DAINT MMIO32(USB_OTG_FS_BASE + OTG_DAINT)
#define OTG_FS_DAINTMSK MMIO32(USB_OTG_FS_BASE + OTG_DAINTMSK)
#define OTG_FS_DVBUSDIS MMIO32(USB_OTG_FS_BASE + OTG_DVBUSDIS)
#define OTG_FS_DVBUSPULSE MMIO32(USB_OTG_FS_BASE + OTG_DVBUSPULSE)
#define OTG_FS_DIEPEMPMSK MMIO32(USB_OTG_FS_BASE + OTG_DIEPEMPMSK)
#define OTG_FS_DIEPCTL0 MMIO32(USB_OTG_FS_BASE + OTG_DIEPCTL0)
#define OTG_FS_DIEPCTL(x) MMIO32(USB_OTG_FS_BASE + OTG_DIEPCTL(x))
#define OTG_FS_DOEPCTL0 MMIO32(USB_OTG_FS_BASE + OTG_DOEPCTL0)
#define OTG_FS_DOEPCTL(x) MMIO32(USB_OTG_FS_BASE + OTG_DOEPCTL(x))
#define OTG_FS_DIEPINT(x) MMIO32(USB_OTG_FS_BASE + OTG_DIEPINT(x))
#define OTG_FS_DOEPINT(x) MMIO32(USB_OTG_FS_BASE + OTG_DOEPINT(x))
#define OTG_FS_DIEPTSIZ0 MMIO32(USB_OTG_FS_BASE + OTG_DIEPTSIZ0)
#define OTG_FS_DOEPTSIZ0 MMIO32(USB_OTG_FS_BASE + OTG_DOEPTSIZ0)
#define OTG_FS_DIEPTSIZ(x) MMIO32(USB_OTG_FS_BASE + OTG_DIEPTSIZ(x))
#define OTG_FS_DTXFSTS(x) MMIO32(USB_OTG_FS_BASE + OTG_DTXFSTS(x))
#define OTG_FS_DOEPTSIZ(x) MMIO32(USB_OTG_FS_BASE + OTG_DOEPTSIZ(x))


#define OTG_FS_PCGCCTL MMIO32(USB_OTG_FS_BASE + OTG_PCGCCTL)


#define OTG_FS_FIFO(x) (&MMIO32(USB_OTG_FS_BASE + (((x) + 1) << 12)))
#define __USB_PRIVATE_H 

#define MAX_USER_CONTROL_CALLBACK 4
#define MAX_USER_SET_CONFIG_CALLBACK 4

#define MIN(a,b) ((a) < (b) ? (a) : (b))


struct _usbd_device {
 const struct usb_device_descriptor *desc;
 const struct usb_config_descriptor *config;
 const char * const *strings;
 int num_strings;

 uint8_t *ctrl_buf;
 uint16_t ctrl_buf_len;

 uint8_t current_address;
 uint8_t current_config;

 uint16_t pm_top;


 void (*user_callback_reset)(void);
 void (*user_callback_suspend)(void);
 void (*user_callback_resume)(void);
 void (*user_callback_sof)(void);

 struct usb_control_state {
  enum {
   IDLE, STALLED,
   DATA_IN, LAST_DATA_IN, STATUS_IN,
   DATA_OUT, LAST_DATA_OUT, STATUS_OUT,
  } state;
  struct usb_setup_data req __attribute__((aligned(4)));
  uint8_t *ctrl_buf;
  uint16_t ctrl_len;
  usbd_control_complete_callback complete;
  
 _Bool 
      needs_zlp;
 } control_state;

 struct user_control_callback {
  usbd_control_callback cb;
  uint8_t type;
  uint8_t type_mask;
 } user_control_callback[4];

 usbd_endpoint_callback user_callback_ctr[8][3];


 usbd_set_config_callback user_callback_set_config[4];

 usbd_set_altsetting_callback user_callback_set_altsetting;

 const struct _usbd_driver *driver;


 int extra_string_idx;
 const char* extra_string;



 uint16_t fifo_mem_top;
 uint16_t fifo_mem_top_ep0;
 uint8_t force_nak[4];




 uint32_t doeptsiz[4];





 uint16_t rxbcnt;
};

enum _usbd_transaction {
 USB_TRANSACTION_IN,
 USB_TRANSACTION_OUT,
 USB_TRANSACTION_SETUP,
};




void _usbd_control_in(usbd_device *usbd_dev, uint8_t ea);
void _usbd_control_out(usbd_device *usbd_dev, uint8_t ea);
void _usbd_control_setup(usbd_device *usbd_dev, uint8_t ea);

enum usbd_request_return_codes _usbd_standard_request_device(usbd_device *usbd_dev,
      struct usb_setup_data *req, uint8_t **buf,
      uint16_t *len);
enum usbd_request_return_codes _usbd_standard_request_interface(usbd_device *usbd_dev,
         struct usb_setup_data *req, uint8_t **buf,
         uint16_t *len);
enum usbd_request_return_codes _usbd_standard_request_endpoint(usbd_device *usbd_dev,
        struct usb_setup_data *req, uint8_t **buf,
        uint16_t *len);
enum usbd_request_return_codes _usbd_standard_request(usbd_device *usbd_dev, struct usb_setup_data *req,
      uint8_t **buf, uint16_t *len);

void _usbd_reset(usbd_device *usbd_dev);


struct _usbd_driver {
 usbd_device *(*init)(void);
 void (*set_address)(usbd_device *usbd_dev, uint8_t addr);
 void (*ep_setup)(usbd_device *usbd_dev, uint8_t addr, uint8_t type,
    uint16_t max_size, usbd_endpoint_callback cb);
 void (*ep_reset)(usbd_device *usbd_dev);
 void (*ep_stall_set)(usbd_device *usbd_dev, uint8_t addr,
        uint8_t stall);
 void (*ep_nak_set)(usbd_device *usbd_dev, uint8_t addr, uint8_t nak);
 uint8_t (*ep_stall_get)(usbd_device *usbd_dev, uint8_t addr);
 uint16_t (*ep_write_packet)(usbd_device *usbd_dev, uint8_t addr,
        const void *buf, uint16_t len);
 uint16_t (*ep_read_packet)(usbd_device *usbd_dev, uint8_t addr,
       void *buf, uint16_t len);
 void (*poll)(usbd_device *usbd_dev);
 void (*disconnect)(usbd_device *usbd_dev, 
                                          _Bool 
                                               disconnected);
 uint32_t base_address;
 
_Bool 
     set_address_before_status;
 uint16_t rx_fifo_size;
};
#define __USB_DWC_COMMON_H_ 

void dwc_set_address(usbd_device *usbd_dev, uint8_t addr);
void dwc_ep_setup(usbd_device *usbd_dev, uint8_t addr, uint8_t type,
   uint16_t max_size,
   void (*callback)(usbd_device *usbd_dev, uint8_t ep));
void dwc_endpoints_reset(usbd_device *usbd_dev);
void dwc_ep_stall_set(usbd_device *usbd_dev, uint8_t addr, uint8_t stall);
uint8_t dwc_ep_stall_get(usbd_device *usbd_dev, uint8_t addr);
void dwc_ep_nak_set(usbd_device *usbd_dev, uint8_t addr, uint8_t nak);
uint16_t dwc_ep_write_packet(usbd_device *usbd_dev, uint8_t addr,
       const void *buf, uint16_t len);
uint16_t dwc_ep_read_packet(usbd_device *usbd_dev, uint8_t addr,
      void *buf, uint16_t len);
void dwc_poll(usbd_device *usbd_dev);
void dwc_disconnect(usbd_device *usbd_dev, 
                                          _Bool 
                                               disconnected);


#define RX_FIFO_SIZE 128

static usbd_device *stm32f107_usbd_init(void);

static struct _usbd_device usbd_dev;

const struct _usbd_driver stm32f107_usb_driver = {
 .init = stm32f107_usbd_init,
 .set_address = dwc_set_address,
 .ep_setup = dwc_ep_setup,
 .ep_reset = dwc_endpoints_reset,
 .ep_stall_set = dwc_ep_stall_set,
 .ep_stall_get = dwc_ep_stall_get,
 .ep_nak_set = dwc_ep_nak_set,
 .ep_write_packet = dwc_ep_write_packet,
 .ep_read_packet = dwc_ep_read_packet,
 .poll = dwc_poll,
 .disconnect = dwc_disconnect,
 .base_address = (0x50000000U + 0x00000),
 .set_address_before_status = 1,
 .rx_fifo_size = 128,
};


static usbd_device *stm32f107_usbd_init(void)
{
 rcc_periph_clock_enable(RCC_OTGFS);
 (*(volatile uint32_t *)((0x50000000U + 0x00000) + 0x00C)) |= (1 << 6);


 while (!((*(volatile uint32_t *)((0x50000000U + 0x00000) + 0x010)) & (1 << 31)));

 (*(volatile uint32_t *)((0x50000000U + 0x00000) + 0x010)) |= (1 << 0);
 while ((*(volatile uint32_t *)((0x50000000U + 0x00000) + 0x010)) & (1 << 0));

 if ((*(volatile uint32_t *)((0x50000000U + 0x00000) + 0x03C)) >= 0x00002000) {

  (*(volatile uint32_t *)((0x50000000U + 0x00000) + 0x038)) |= (1 << 21) | (1 << 16);
 } else {

  (*(volatile uint32_t *)((0x50000000U + 0x00000) + 0x038)) |= (1 << 19) | (1 << 16);
 }

 (*(volatile uint32_t *)((0x50000000U + 0x00000) + 0x804)) &= ~(1 << 1);


 (*(volatile uint32_t *)((0x50000000U + 0x00000) + 0x00C)) |= 0x40000000 | (0xf << 10);

 (*(volatile uint32_t *)((0x50000000U + 0x00000) + 0x014)) = (1 << 1);


 (*(volatile uint32_t *)((0x50000000U + 0x00000) + 0x800)) |= 0x0003;


 (*(volatile uint32_t *)((0x50000000U + 0x00000) + 0xE00)) = 0;

 (*(volatile uint32_t *)((0x50000000U + 0x00000) + 0x024)) = stm32f107_usb_driver.rx_fifo_size;
 usbd_dev.fifo_mem_top = stm32f107_usb_driver.rx_fifo_size;


 (*(volatile uint32_t *)((0x50000000U + 0x00000) + 0x008)) |= 0x0001;
 (*(volatile uint32_t *)((0x50000000U + 0x00000) + 0x018)) = 0x00002000 |
    0x00000010 |
    0x00040000 |
    0x00000800 |
    0x80000000;
 (*(volatile uint32_t *)((0x50000000U + 0x00000) + 0x81C)) = 0xF;
 (*(volatile uint32_t *)((0x50000000U + 0x00000) + 0x810)) = (1 << 0);

 return &usbd_dev;
}
