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
#define LIBOPENCM3_ADC_H 

#define LIBOPENCM3_ADC_COMMON_V1_MULTI_H 

#define LIBOPENCM3_ADC_COMMON_V1_H 
#define ADC1 ADC1_BASE





#define ADC_SR(block) MMIO32((block) + 0x00)


#define ADC_CR1(block) MMIO32((block) + 0x04)


#define ADC_CR2(block) MMIO32((block) + 0x08)


#define ADC_SMPR1(block) MMIO32((block) + 0x0c)


#define ADC_SMPR2(block) MMIO32((block) + 0x10)

#define ADC1_SR ADC_SR(ADC1)
#define ADC1_CR1 ADC_CR1(ADC1)
#define ADC1_CR2 ADC_CR2(ADC1)
#define ADC1_SMPR1 ADC_SMPR1(ADC1)
#define ADC1_SMPR2 ADC_SMPR2(ADC1)

#define ADC1_JOFR1 ADC_JOFR1(ADC1)
#define ADC1_JOFR2 ADC_JOFR2(ADC1)
#define ADC1_JOFR3 ADC_JOFR3(ADC1)
#define ADC1_JOFR4 ADC_JOFR4(ADC1)

#define ADC1_HTR ADC_HTR(ADC1)
#define ADC1_LTR ADC_LTR(ADC1)

#define ADC1_SQR1 ADC_SQR1(ADC1)
#define ADC1_SQR2 ADC_SQR2(ADC1)
#define ADC1_SQR3 ADC_SQR3(ADC1)
#define ADC1_JSQR ADC_JSQR(ADC1)

#define ADC1_JDR1 ADC_JDR1(ADC1)
#define ADC1_JDR2 ADC_JDR2(ADC1)
#define ADC1_JDR3 ADC_JDR3(ADC1)
#define ADC1_JDR4 ADC_JDR4(ADC1)
#define ADC1_DR ADC_DR(ADC1)


#define ADC2 ADC2_BASE
#define ADC2_SR ADC_SR(ADC2)
#define ADC2_CR1 ADC_CR1(ADC2)
#define ADC2_CR2 ADC_CR2(ADC2)
#define ADC2_SMPR1 ADC_SMPR1(ADC2)
#define ADC2_SMPR2 ADC_SMPR2(ADC2)

#define ADC2_JOFR1 ADC_JOFR1(ADC2)
#define ADC2_JOFR2 ADC_JOFR2(ADC2)
#define ADC2_JOFR3 ADC_JOFR3(ADC2)
#define ADC2_JOFR4 ADC_JOFR4(ADC2)


#define ADC2_HTR ADC_HTR(ADC2)

#define ADC2_LTR ADC_LTR(ADC2)


#define ADC2_SQR1 ADC_SQR1(ADC2)

#define ADC2_SQR2 ADC_SQR2(ADC2)

#define ADC2_SQR3 ADC_SQR3(ADC2)

#define ADC2_JSQR ADC_JSQR(ADC2)


#define ADC2_JDR1 ADC_JDR1(ADC2)
#define ADC2_JDR2 ADC_JDR2(ADC2)
#define ADC2_JDR3 ADC_JDR3(ADC2)
#define ADC2_JDR4 ADC_JDR4(ADC2)

#define ADC2_DR ADC_DR(ADC2)



#define ADC3 ADC3_BASE
#define ADC3_SR ADC_SR(ADC3)
#define ADC3_CR1 ADC_CR1(ADC3)
#define ADC3_CR2 ADC_CR2(ADC3)
#define ADC3_SMPR1 ADC_SMPR1(ADC3)
#define ADC3_SMPR2 ADC_SMPR2(ADC3)

#define ADC3_JOFR1 ADC_JOFR1(ADC3)
#define ADC3_JOFR2 ADC_JOFR2(ADC3)
#define ADC3_JOFR3 ADC_JOFR3(ADC3)
#define ADC3_JOFR4 ADC_JOFR4(ADC3)

#define ADC3_HTR ADC_HTR(ADC3)
#define ADC3_LTR ADC_LTR(ADC3)

#define ADC3_SQR1 ADC_SQR1(ADC3)
#define ADC3_SQR2 ADC_SQR2(ADC3)
#define ADC3_SQR3 ADC_SQR3(ADC3)
#define ADC3_JSQR ADC_JSQR(ADC3)

#define ADC3_JDR1 ADC_JDR1(ADC3)
#define ADC3_JDR2 ADC_JDR2(ADC3)
#define ADC3_JDR3 ADC_JDR3(ADC3)
#define ADC3_JDR4 ADC_JDR4(ADC3)
#define ADC3_DR ADC_DR(ADC3)
#define ADC_CHANNEL0 0x00
#define ADC_CHANNEL1 0x01
#define ADC_CHANNEL2 0x02
#define ADC_CHANNEL3 0x03
#define ADC_CHANNEL4 0x04
#define ADC_CHANNEL5 0x05
#define ADC_CHANNEL6 0x06
#define ADC_CHANNEL7 0x07
#define ADC_CHANNEL8 0x08
#define ADC_CHANNEL9 0x09
#define ADC_CHANNEL10 0x0A
#define ADC_CHANNEL11 0x0B
#define ADC_CHANNEL12 0x0C
#define ADC_CHANNEL13 0x0D
#define ADC_CHANNEL14 0x0E
#define ADC_CHANNEL15 0x0F
#define ADC_CHANNEL16 0x10
#define ADC_CHANNEL17 0x11
#define ADC_CHANNEL18 0x12

#define ADC_CHANNEL_MASK 0x1F
#define ADC_SR_STRT (1 << 4)


#define ADC_SR_JSTRT (1 << 3)


#define ADC_SR_JEOC (1 << 2)


#define ADC_SR_EOC (1 << 1)


#define ADC_SR_AWD (1 << 0)





#define ADC_CR1_AWDEN (1 << 23)


#define ADC_CR1_JAWDEN (1 << 22)
#define ADC_CR1_DISCNUM_1CHANNELS (0x0 << 13)
#define ADC_CR1_DISCNUM_2CHANNELS (0x1 << 13)
#define ADC_CR1_DISCNUM_3CHANNELS (0x2 << 13)
#define ADC_CR1_DISCNUM_4CHANNELS (0x3 << 13)
#define ADC_CR1_DISCNUM_5CHANNELS (0x4 << 13)
#define ADC_CR1_DISCNUM_6CHANNELS (0x5 << 13)
#define ADC_CR1_DISCNUM_7CHANNELS (0x6 << 13)
#define ADC_CR1_DISCNUM_8CHANNELS (0x7 << 13)

#define ADC_CR1_DISCNUM_MASK (0x7 << 13)
#define ADC_CR1_DISCNUM_SHIFT 13


#define ADC_CR1_JDISCEN (1 << 12)


#define ADC_CR1_DISCEN (1 << 11)


#define ADC_CR1_JAUTO (1 << 10)


#define ADC_CR1_AWDSGL (1 << 9)


#define ADC_CR1_SCAN (1 << 8)


#define ADC_CR1_JEOCIE (1 << 7)


#define ADC_CR1_AWDIE (1 << 6)


#define ADC_CR1_EOCIE (1 << 5)
#define ADC_CR1_AWDCH_CHANNEL0 (0x00 << 0)
#define ADC_CR1_AWDCH_CHANNEL1 (0x01 << 0)
#define ADC_CR1_AWDCH_CHANNEL2 (0x02 << 0)
#define ADC_CR1_AWDCH_CHANNEL3 (0x03 << 0)
#define ADC_CR1_AWDCH_CHANNEL4 (0x04 << 0)
#define ADC_CR1_AWDCH_CHANNEL5 (0x05 << 0)
#define ADC_CR1_AWDCH_CHANNEL6 (0x06 << 0)
#define ADC_CR1_AWDCH_CHANNEL7 (0x07 << 0)
#define ADC_CR1_AWDCH_CHANNEL8 (0x08 << 0)
#define ADC_CR1_AWDCH_CHANNEL9 (0x09 << 0)
#define ADC_CR1_AWDCH_CHANNEL10 (0x0A << 0)
#define ADC_CR1_AWDCH_CHANNEL11 (0x0B << 0)
#define ADC_CR1_AWDCH_CHANNEL12 (0x0C << 0)
#define ADC_CR1_AWDCH_CHANNEL13 (0x0D << 0)
#define ADC_CR1_AWDCH_CHANNEL14 (0x0E << 0)
#define ADC_CR1_AWDCH_CHANNEL15 (0x0F << 0)
#define ADC_CR1_AWDCH_CHANNEL16 (0x10 << 0)
#define ADC_CR1_AWDCH_CHANNEL17 (0x11 << 0)

#define ADC_CR1_AWDCH_MASK (0x1F << 0)
#define ADC_CR1_AWDCH_SHIFT 0




#define ADC_CR2_ALIGN_RIGHT (0 << 11)
#define ADC_CR2_ALIGN_LEFT (1 << 11)
#define ADC_CR2_ALIGN (1 << 11)


#define ADC_CR2_DMA (1 << 8)


#define ADC_CR2_CONT (1 << 1)







#define ADC_CR2_ADON (1 << 0)



#define ADC_JOFFSET_LSB 0
#define ADC_JOFFSET_MSK 0xfff
#define ADC_HT_LSB 0
#define ADC_HT_MSK 0xfff
#define ADC_LT_LSB 0
#define ADC_LT_MSK 0xfff




#define ADC_SQR1_L_LSB 20


#define ADC_JSQR_JL_LSB 20
#define ADC_JSQR_JSQ4_LSB 15
#define ADC_JSQR_JSQ3_LSB 10
#define ADC_JSQR_JSQ2_LSB 5
#define ADC_JSQR_JSQ1_LSB 0







#define ADC_JSQR_JL_1CHANNELS (0x0 << ADC_JSQR_JL_LSB)
#define ADC_JSQR_JL_2CHANNELS (0x1 << ADC_JSQR_JL_LSB)
#define ADC_JSQR_JL_3CHANNELS (0x2 << ADC_JSQR_JL_LSB)
#define ADC_JSQR_JL_4CHANNELS (0x3 << ADC_JSQR_JL_LSB)

#define ADC_JSQR_JL_MSK (0x2 << ADC_JSQR_JL_LSB)
#define ADC_JSQR_JSQ4_MSK (0x1f << ADC_JSQR_JSQ4_LSB)
#define ADC_JSQR_JSQ3_MSK (0x1f << ADC_JSQR_JSQ3_LSB)
#define ADC_JSQR_JSQ2_MSK (0x1f << ADC_JSQR_JSQ2_LSB)
#define ADC_JSQR_JSQ1_MSK (0x1f << ADC_JSQR_JSQ1_LSB)

#define ADC_JSQR_JSQ_VAL(n,val) ((val) << (((n) - 1) * 5))
#define ADC_JSQR_JL_VAL(val) (((val) - 1) << ADC_JSQR_JL_LSB)



void adc_power_on(uint32_t adc);
void adc_power_off(uint32_t adc);
void adc_enable_analog_watchdog_regular(uint32_t adc);
void adc_disable_analog_watchdog_regular(uint32_t adc);
void adc_enable_analog_watchdog_injected(uint32_t adc);
void adc_disable_analog_watchdog_injected(uint32_t adc);
void adc_enable_discontinuous_mode_regular(uint32_t adc, uint8_t length);
void adc_disable_discontinuous_mode_regular(uint32_t adc);
void adc_enable_discontinuous_mode_injected(uint32_t adc);
void adc_disable_discontinuous_mode_injected(uint32_t adc);
void adc_enable_automatic_injected_group_conversion(uint32_t adc);
void adc_disable_automatic_injected_group_conversion(uint32_t adc);
void adc_enable_analog_watchdog_on_all_channels(uint32_t adc);
void adc_enable_analog_watchdog_on_selected_channel(uint32_t adc,
          uint8_t channel);
void adc_enable_scan_mode(uint32_t adc);
void adc_disable_scan_mode(uint32_t adc);
void adc_enable_eoc_interrupt_injected(uint32_t adc);
void adc_disable_eoc_interrupt_injected(uint32_t adc);
void adc_enable_awd_interrupt(uint32_t adc);
void adc_disable_awd_interrupt(uint32_t adc);
void adc_enable_eoc_interrupt(uint32_t adc);
void adc_disable_eoc_interrupt(uint32_t adc);
void adc_set_left_aligned(uint32_t adc);
void adc_set_right_aligned(uint32_t adc);

_Bool 
    adc_eoc(uint32_t adc);

_Bool 
    adc_eoc_injected(uint32_t adc);
uint32_t adc_read_regular(uint32_t adc);
uint32_t adc_read_injected(uint32_t adc, uint8_t reg);
void adc_set_continuous_conversion_mode(uint32_t adc);
void adc_set_single_conversion_mode(uint32_t adc);
void adc_set_regular_sequence(uint32_t adc, uint8_t length, uint8_t channel[]);
void adc_set_injected_sequence(uint32_t adc, uint8_t length, uint8_t channel[]);
void adc_set_injected_offset(uint32_t adc, uint8_t reg, uint32_t offset);
void adc_set_watchdog_high_threshold(uint32_t adc, uint16_t threshold);
void adc_set_watchdog_low_threshold(uint32_t adc, uint16_t threshold);
void adc_start_conversion_regular(uint32_t adc);
void adc_start_conversion_injected(uint32_t adc);
void adc_enable_dma(uint32_t adc);
void adc_disable_dma(uint32_t adc);

_Bool 
    adc_get_flag(uint32_t adc, uint32_t flag);
void adc_clear_flag(uint32_t adc, uint32_t flag);


void adc_set_sample_time(uint32_t adc, uint8_t channel, uint8_t time);
void adc_set_sample_time_on_all_channels(uint32_t adc, uint8_t time);
void adc_disable_external_trigger_regular(uint32_t adc);
void adc_disable_external_trigger_injected(uint32_t adc);







#define ADC_COMMON_REGISTERS_BASE (ADC1_BASE+0x300)
#define ADC_CSR MMIO32(ADC_COMMON_REGISTERS_BASE + 0x0)
#define ADC_CCR MMIO32(ADC_COMMON_REGISTERS_BASE + 0x4)
#define ADC_CDR MMIO32(ADC_COMMON_REGISTERS_BASE + 0x8)
#define ADC_SR_OVR (1 << 5)



#define ADC_CR1_OVRIE (1 << 26)







#define ADC_CR1_RES_12BIT (0x0 << 24)
#define ADC_CR1_RES_10BIT (0x1 << 24)
#define ADC_CR1_RES_8BIT (0x2 << 24)
#define ADC_CR1_RES_6BIT (0x3 << 24)

#define ADC_CR1_RES_MASK (0x3 << 24)
#define ADC_CR1_RES_SHIFT 24
#define ADC_CR2_SWSTART (1 << 30)



#define ADC_CR2_EXTEN_SHIFT 28
#define ADC_CR2_EXTEN_MASK (0x3 << ADC_CR2_EXTEN_SHIFT)



#define ADC_CR2_EXTEN_DISABLED (0x0 << ADC_CR2_EXTEN_SHIFT)
#define ADC_CR2_EXTEN_RISING_EDGE (0x1 << ADC_CR2_EXTEN_SHIFT)
#define ADC_CR2_EXTEN_FALLING_EDGE (0x2 << ADC_CR2_EXTEN_SHIFT)
#define ADC_CR2_EXTEN_BOTH_EDGES (0x3 << ADC_CR2_EXTEN_SHIFT)





#define ADC_CR2_EXTSEL_MASK (0xF << 24)
#define ADC_CR2_EXTSEL_SHIFT 24




#define ADC_CR2_JSWSTART (1 << 22)



#define ADC_CR2_JEXTEN_SHIFT 20
#define ADC_CR2_JEXTEN_MASK (0x3 << ADC_CR2_JEXTEN_SHIFT)



#define ADC_CR2_JEXTEN_DISABLED (0x0 << ADC_CR2_JEXTEN_SHIFT)
#define ADC_CR2_JEXTEN_RISING_EDGE (0x1 << ADC_CR2_JEXTEN_SHIFT)
#define ADC_CR2_JEXTEN_FALLING_EDGE (0x2 << ADC_CR2_JEXTEN_SHIFT)
#define ADC_CR2_JEXTEN_BOTH_EDGES (0x3 << ADC_CR2_JEXTEN_SHIFT)





#define ADC_CR2_JEXTSEL_SHIFT 16
#define ADC_CR2_JEXTSEL_MASK (0xF << ADC_CR2_JEXTSEL_SHIFT)


#define ADC_CR2_ALIGN_RIGHT (0 << 11)
#define ADC_CR2_ALIGN_LEFT (1 << 11)
#define ADC_CR2_ALIGN (1 << 11)


#define ADC_CR2_EOCS (1 << 10)


#define ADC_CR2_DDS (1 << 9)


#define ADC_CR2_DMA (1 << 8)




#define ADC_CR2_CONT (1 << 1)







#define ADC_CR2_ADON (1 << 0)





#define ADC_SQRx_MASK 0x1f



#define ADC_JDATA_LSB 0
#define ADC_DATA_LSB 0
#define ADC_JDATA_MSK (0xffff << ADC_JDATA_LSB)
#define ADC_DATA_MSK (0xffff << ADC_DA)






#define ADC_CSR_OVR3 (1 << 21)


#define ADC_CSR_STRT3 (1 << 20)


#define ADC_CSR_JSTRT3 (1 << 19)


#define ADC_CSR_JEOC3 (1 << 18)


#define ADC_CSR_EOC3 (1 << 17)


#define ADC_CSR_AWD3 (1 << 16)




#define ADC_CSR_OVR2 (1 << 13)


#define ADC_CSR_STRT2 (1 << 12)


#define ADC_CSR_JSTRT2 (1 << 11)


#define ADC_CSR_JEOC2 (1 << 10)


#define ADC_CSR_EOC2 (1 << 9)


#define ADC_CSR_AWD2 (1 << 8)




#define ADC_CSR_OVR1 (1 << 5)


#define ADC_CSR_STRT1 (1 << 4)


#define ADC_CSR_JSTRT1 (1 << 3)


#define ADC_CSR_JEOC1 (1 << 2)


#define ADC_CSR_EOC1 (1 << 1)


#define ADC_CSR_AWD1 (1 << 0)




#define ADC_CCR_TSVREFE (1 << 23)


#define ADC_CCR_VBATE (1 << 22)
#define ADC_CCR_DMA_DISABLE (0x0 << 14)
#define ADC_CCR_DMA_MODE_1 (0x1 << 14)
#define ADC_CCR_DMA_MODE_2 (0x2 << 14)
#define ADC_CCR_DMA_MODE_3 (0x3 << 14)

#define ADC_CCR_DMA_MASK (0x3 << 14)
#define ADC_CCR_DMA_SHIFT 14


#define ADC_CCR_DDS (1 << 13)
#define ADC_CCR_DELAY_5ADCCLK (0x0 << 8)
#define ADC_CCR_DELAY_6ADCCLK (0x1 << 8)
#define ADC_CCR_DELAY_7ADCCLK (0x2 << 8)
#define ADC_CCR_DELAY_8ADCCLK (0x3 << 8)
#define ADC_CCR_DELAY_9ADCCLK (0x4 << 8)
#define ADC_CCR_DELAY_10ADCCLK (0x5 << 8)
#define ADC_CCR_DELAY_11ADCCLK (0x6 << 8)
#define ADC_CCR_DELAY_12ADCCLK (0x7 << 8)
#define ADC_CCR_DELAY_13ADCCLK (0x8 << 8)
#define ADC_CCR_DELAY_14ADCCLK (0x9 << 8)
#define ADC_CCR_DELAY_15ADCCLK (0xa << 8)
#define ADC_CCR_DELAY_16ADCCLK (0xb << 8)
#define ADC_CCR_DELAY_17ADCCLK (0xc << 8)
#define ADC_CCR_DELAY_18ADCCLK (0xd << 8)
#define ADC_CCR_DELAY_19ADCCLK (0xe << 8)
#define ADC_CCR_DELAY_20ADCCLK (0xf << 8)

#define ADC_CCR_DELAY_MASK (0xf << 8)
#define ADC_CCR_DELAY_SHIFT 8
#define ADC_CCR_MULTI_INDEPENDENT (0x00 << 0)






#define ADC_CCR_MULTI_DUAL_REG_SIMUL_AND_INJECTED_SIMUL (0x01 << 0)




#define ADC_CCR_MULTI_DUAL_REG_SIMUL_AND_ALTERNATE_TRIG (0x02 << 0)

#define ADC_CCR_MULTI_DUAL_INJECTED_SIMUL (0x05 << 0)

#define ADC_CCR_MULTI_DUAL_REGULAR_SIMUL (0x06 << 0)

#define ADC_CCR_MULTI_DUAL_INTERLEAVED (0x07 << 0)

#define ADC_CCR_MULTI_DUAL_ALTERNATE_TRIG (0x09 << 0)






#define ADC_CCR_MULTI_TRIPLE_REG_SIMUL_AND_INJECTED_SIMUL (0x11 << 0)




#define ADC_CCR_MULTI_TRIPLE_REG_SIMUL_AND_ALTERNATE_TRIG (0x12 << 0)

#define ADC_CCR_MULTI_TRIPLE_INJECTED_SIMUL (0x15 << 0)

#define ADC_CCR_MULTI_TRIPLE_REGULAR_SIMUL (0x16 << 0)

#define ADC_CCR_MULTI_TRIPLE_INTERLEAVED (0x17 << 0)

#define ADC_CCR_MULTI_TRIPLE_ALTERNATE_TRIG (0x19 << 0)


#define ADC_CCR_MULTI_MASK (0x1f << 0)
#define ADC_CCR_MULTI_SHIFT 0



#define ADC_CDR_DATA2_MASK (0xffff << 16)
#define ADC_CDR_DATA2_SHIFT 16

#define ADC_CDR_DATA1_MASK (0xffff << 0)
#define ADC_CDR_DATA1_SHIFT 0



void adc_set_clk_prescale(uint32_t prescaler);
void adc_enable_external_trigger_regular(uint32_t adc, uint32_t trigger,
      uint32_t polarity);
void adc_enable_external_trigger_injected(uint32_t adc, uint32_t trigger,
       uint32_t polarity);
void adc_set_resolution(uint32_t adc, uint32_t resolution);
void adc_enable_overrun_interrupt(uint32_t adc);
void adc_disable_overrun_interrupt(uint32_t adc);

_Bool 
    adc_get_overrun_flag(uint32_t adc);
void adc_clear_overrun_flag(uint32_t adc);

_Bool 
    adc_awd(uint32_t adc);
void adc_eoc_after_each(uint32_t adc);
void adc_eoc_after_group(uint32_t adc);
void adc_set_dma_continue(uint32_t adc);
void adc_set_dma_terminate(uint32_t adc);
void adc_enable_temperature_sensor(void);
void adc_disable_temperature_sensor(void);




#define ADC_JOFR1(block) MMIO32((block) + 0x14)
#define ADC_JOFR2(block) MMIO32((block) + 0x18)
#define ADC_JOFR3(block) MMIO32((block) + 0x1c)
#define ADC_JOFR4(block) MMIO32((block) + 0x20)


#define ADC_HTR(block) MMIO32((block) + 0x24)


#define ADC_LTR(block) MMIO32((block) + 0x28)


#define ADC_SQR1(block) MMIO32((block) + 0x2c)


#define ADC_SQR2(block) MMIO32((block) + 0x30)


#define ADC_SQR3(block) MMIO32((block) + 0x34)


#define ADC_JSQR(block) MMIO32((block) + 0x38)


#define ADC_JDR1(block) MMIO32((block) + 0x3c)
#define ADC_JDR2(block) MMIO32((block) + 0x40)
#define ADC_JDR3(block) MMIO32((block) + 0x44)
#define ADC_JDR4(block) MMIO32((block) + 0x48)


#define ADC_DR(block) MMIO32((block) + 0x4c)





#define ADC_CHANNEL_TEMP_F40 16
#define ADC_CHANNEL_TEMP_F42 18
#define ADC_CHANNEL_VREF 17
#define ADC_CHANNEL_VBAT 18




#define ADC_CR1_AWDCH_MAX 18
#define ADC_CR2_EXTSEL_TIM1_CC1 (0x0 << 24)

#define ADC_CR2_EXTSEL_TIM1_CC2 (0x1 << 24)

#define ADC_CR2_EXTSEL_TIM1_CC3 (0x2 << 24)

#define ADC_CR2_EXTSEL_TIM2_CC2 (0x3 << 24)

#define ADC_CR2_EXTSEL_TIM2_CC3 (0x4 << 24)

#define ADC_CR2_EXTSEL_TIM2_CC4 (0x5 << 24)

#define ADC_CR2_EXTSEL_TIM2_TRGO (0x6 << 24)

#define ADC_CR2_EXTSEL_TIM3_CC1 (0x7 << 24)

#define ADC_CR2_EXTSEL_TIM3_TRGO (0x8 << 24)

#define ADC_CR2_EXTSEL_TIM4_CC4 (0x9 << 24)

#define ADC_CR2_EXTSEL_TIM5_CC1 (0xA << 24)

#define ADC_CR2_EXTSEL_TIM5_CC2 (0xB << 24)

#define ADC_CR2_EXTSEL_TIM5_CC3 (0xC << 24)

#define ADC_CR2_EXTSEL_TIM8_CC1 (0xD << 24)

#define ADC_CR2_EXTSEL_TIM8_TRGO (0xE << 24)

#define ADC_CR2_EXTSEL_EXTI_LINE_11 (0xF << 24)
#define ADC_CR2_JEXTSEL_TIM1_CC4 (0x0 << 16)
#define ADC_CR2_JEXTSEL_TIM1_TRGO (0x1 << 16)
#define ADC_CR2_JEXTSEL_TIM2_CC1 (0x2 << 16)
#define ADC_CR2_JEXTSEL_TIM2_TRGO (0x3 << 16)
#define ADC_CR2_JEXTSEL_TIM3_CC2 (0x4 << 16)
#define ADC_CR2_JEXTSEL_TIM3_CC4 (0x5 << 16)
#define ADC_CR2_JEXTSEL_TIM4_CC1 (0x6 << 16)
#define ADC_CR2_JEXTSEL_TIM4_CC2 (0x7 << 16)
#define ADC_CR2_JEXTSEL_TIM4_CC3 (0x8 << 16)
#define ADC_CR2_JEXTSEL_TIM4_TRGO (0x9 << 16)
#define ADC_CR2_JEXTSEL_TIM5_CC4 (0xA << 16)
#define ADC_CR2_JEXTSEL_TIM5_TRGO (0xB << 16)
#define ADC_CR2_JEXTSEL_TIM8_CC2 (0xC << 16)
#define ADC_CR2_JEXTSEL_TIM8_CC3 (0xD << 16)
#define ADC_CR2_JEXTSEL_TIM8_CC4 (0xE << 16)
#define ADC_CR2_JEXTSEL_EXTI_LINE_15 (0xF << 16)







#define ADC_SMPR_SMP_3CYC 0x0
#define ADC_SMPR_SMP_15CYC 0x1
#define ADC_SMPR_SMP_28CYC 0x2
#define ADC_SMPR_SMP_56CYC 0x3
#define ADC_SMPR_SMP_84CYC 0x4
#define ADC_SMPR_SMP_112CYC 0x5
#define ADC_SMPR_SMP_144CYC 0x6
#define ADC_SMPR_SMP_480CYC 0x7



#define ADC_SQR1_L_MSK (0xf << ADC_SQR1_L_LSB)

#define ADC_SQR_MAX_CHANNELS_REGULAR 16







#define ADC_CCR_ADCPRE_BY2 (0x0 << 16)
#define ADC_CCR_ADCPRE_BY4 (0x1 << 16)
#define ADC_CCR_ADCPRE_BY6 (0x2 << 16)
#define ADC_CCR_ADCPRE_BY8 (0x3 << 16)

#define ADC_CCR_ADCPRE_MASK (0x3 << 16)
#define ADC_CCR_ADCPRE_SHIFT 16




void adc_set_multi_mode(uint32_t mode);
void adc_enable_vbat_sensor(void);
void adc_disable_vbat_sensor(void);


void adc_power_off(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x08)) &= ~(1 << 0);
}
void adc_enable_analog_watchdog_regular(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x04)) |= (1 << 23);
}
void adc_disable_analog_watchdog_regular(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x04)) &= ~(1 << 23);
}
void adc_enable_analog_watchdog_injected(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x04)) |= (1 << 22);
}







void adc_disable_analog_watchdog_injected(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x04)) &= ~(1 << 22);
}
void adc_enable_discontinuous_mode_regular(uint32_t adc, uint8_t length)
{
 if ((length-1) > 7) {
  return;
 }
 (*(volatile uint32_t *)((adc) + 0x04)) |= (1 << 11);
 (*(volatile uint32_t *)((adc) + 0x04)) |= ((length-1) << 13);
}







void adc_disable_discontinuous_mode_regular(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x04)) &= ~(1 << 11);
}
void adc_enable_discontinuous_mode_injected(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x04)) |= (1 << 12);
}







void adc_disable_discontinuous_mode_injected(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x04)) &= ~(1 << 12);
}
void adc_enable_automatic_injected_group_conversion(uint32_t adc)
{
 adc_disable_external_trigger_injected(adc);
 (*(volatile uint32_t *)((adc) + 0x04)) |= (1 << 10);
}







void adc_disable_automatic_injected_group_conversion(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x04)) &= ~(1 << 10);
}
void adc_enable_analog_watchdog_on_all_channels(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x04)) &= ~(1 << 9);
}
void adc_enable_analog_watchdog_on_selected_channel(uint32_t adc,
          uint8_t channel)
{
 uint32_t reg32;

 reg32 = ((*(volatile uint32_t *)((adc) + 0x04)) & ~(0x1F << 0));
 if (channel <= 18) {
  reg32 |= channel;
 }
 (*(volatile uint32_t *)((adc) + 0x04)) = reg32;
 (*(volatile uint32_t *)((adc) + 0x04)) |= (1 << 9);
}
void adc_enable_scan_mode(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x04)) |= (1 << 8);
}







void adc_disable_scan_mode(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x04)) &= ~(1 << 8);
}







void adc_enable_eoc_interrupt_injected(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x04)) |= (1 << 7);
}







void adc_disable_eoc_interrupt_injected(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x04)) &= ~(1 << 7);
}







void adc_enable_awd_interrupt(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x04)) |= (1 << 6);
}







void adc_disable_awd_interrupt(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x04)) &= ~(1 << 6);
}
void adc_enable_eoc_interrupt(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x04)) |= (1 << 5);
}







void adc_disable_eoc_interrupt(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x04)) &= ~(1 << 5);
}
void adc_set_left_aligned(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x08)) |= (1 << 11);
}
void adc_set_right_aligned(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x08)) &= ~(1 << 11);
}

_Bool 
    adc_eoc(uint32_t adc)
{
 return ((*(volatile uint32_t *)((adc) + 0x00)) & (1 << 1)) != 0;
}

_Bool 
    adc_eoc_injected(uint32_t adc)
{
 return ((*(volatile uint32_t *)((adc) + 0x00)) & (1 << 2)) != 0;
}
uint32_t adc_read_regular(uint32_t adc)
{
 return (*(volatile uint32_t *)((adc) + 0x4c));
}
uint32_t adc_read_injected(uint32_t adc, uint8_t reg)
{
 switch (reg) {
 case 1:
  return (*(volatile uint32_t *)((adc) + 0x3c));
 case 2:
  return (*(volatile uint32_t *)((adc) + 0x40));
 case 3:
  return (*(volatile uint32_t *)((adc) + 0x44));
 case 4:
  return (*(volatile uint32_t *)((adc) + 0x48));
 }
 return 0;
}
void adc_set_continuous_conversion_mode(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x08)) |= (1 << 1);
}
void adc_set_single_conversion_mode(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x08)) &= ~(1 << 1);
}
void adc_set_watchdog_high_threshold(uint32_t adc, uint16_t threshold)
{
 uint32_t reg32 = 0;

 reg32 = (uint32_t)threshold;
 reg32 &= 0xfff;
 (*(volatile uint32_t *)((adc) + 0x24)) = reg32;
}
void adc_set_watchdog_low_threshold(uint32_t adc, uint16_t threshold)
{
 uint32_t reg32 = 0;

 reg32 = (uint32_t)threshold;
 reg32 &= 0xfff;
 (*(volatile uint32_t *)((adc) + 0x28)) = reg32;
}
void adc_set_regular_sequence(uint32_t adc, uint8_t length, uint8_t channel[])
{
 uint32_t fifth6 = 0;
 uint32_t fourth6 = 0;
 uint32_t third6 = 0;
 uint32_t second6 = 0;
 uint32_t first6 = 0;
 uint8_t i = 0;

 if (length > 16) {
  return;
 }

 for (i = 1; i <= length; i++) {
  if (i <= 6) {
   first6 |= (channel[i - 1] << ((i - 1) * 5));
  }
  if ((i > 6) && (i <= 12)) {
   second6 |= (channel[i - 1] << ((i - 6 - 1) * 5));
  }
  if ((i > 12) && (i <= 18)) {
   third6 |= (channel[i - 1] << ((i - 12 - 1) * 5));
  }
  if ((i > 18) && (i <= 24)) {
   fourth6 |= (channel[i - 1] << ((i - 18 - 1) * 5));
  }
  if ((i > 24) && (i <= 28)) {
   fifth6 |= (channel[i - 1] << ((i - 24 - 1) * 5));
  }
 }







 (*(volatile uint32_t *)((adc) + 0x2c)) = third6 | ((length - 1) << 20);
 (*(volatile uint32_t *)((adc) + 0x30)) = second6;
 (*(volatile uint32_t *)((adc) + 0x34)) = first6;

}
void adc_set_injected_sequence(uint32_t adc, uint8_t length, uint8_t channel[])
{
 uint32_t reg32 = 0;
 uint8_t i = 0;


 if ((length - 1) > 3) {
  return;
 }

 for (i = 0; i < length; i++) {
  reg32 |= ((channel[length - i - 1]) << (((4 - i) - 1) * 5));
 }

 reg32 |= (((length) - 1) << 20);

 (*(volatile uint32_t *)((adc) + 0x38)) = reg32;
}
void adc_set_injected_offset(uint32_t adc, uint8_t reg, uint32_t offset)
{
 switch (reg) {
 case 1:
  (*(volatile uint32_t *)((adc) + 0x14)) = offset;
  break;
 case 2:
  (*(volatile uint32_t *)((adc) + 0x18)) = offset;
  break;
 case 3:
  (*(volatile uint32_t *)((adc) + 0x1c)) = offset;
  break;
 case 4:
  (*(volatile uint32_t *)((adc) + 0x20)) = offset;
  break;
 }
}
void adc_start_conversion_regular(uint32_t adc)
{

 (*(volatile uint32_t *)((adc) + 0x08)) |= (1 << 30);


 while ((*(volatile uint32_t *)((adc) + 0x08)) & (1 << 30));
}
void adc_start_conversion_injected(uint32_t adc)
{

 (*(volatile uint32_t *)((adc) + 0x08)) |= (1 << 22);


 while ((*(volatile uint32_t *)((adc) + 0x08)) & (1 << 22));
}
void adc_enable_dma(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x08)) |= (1 << 8);
}







void adc_disable_dma(uint32_t adc)
{
 (*(volatile uint32_t *)((adc) + 0x08)) &= ~(1 << 8);
}

_Bool 
    adc_get_flag(uint32_t adc, uint32_t flag)
{
 return (*(volatile uint32_t *)((adc) + 0x00)) & flag;
}
void adc_clear_flag(uint32_t adc, uint32_t flag)
{

 (*(volatile uint32_t *)((adc) + 0x00)) = ~flag;
}
