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



#define LIBOPENCM3_MEMORYMAP_COMMON_H 
#define LIBOPENCM3_MEMORYMAP_H 






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

#define LED_DISCO_GREEN_PORT GPIOG
#define LED_DISCO_GREEN_PIN GPIO13

#define USART_CONSOLE USART1

int _write(int file, char *ptr, int len);

static void clock_setup(void)
{
 rcc_clock_setup_pll(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_168MHZ]);

 rcc_periph_clock_enable(RCC_GPIOG);
 rcc_periph_clock_enable(RCC_GPIOA);


 rcc_periph_clock_enable(RCC_USART1);
 rcc_periph_clock_enable(RCC_DAC);


 rcc_periph_clock_enable(RCC_ADC1);
}

static void usart_setup(void)
{

 gpio_mode_setup((((0x40000000U) + 0x20000) + 0x0000), 0x2, 0x0, (1 << 9));


 gpio_set_af((((0x40000000U) + 0x20000) + 0x0000), 0x7, (1 << 9));

 usart_set_baudrate((((0x40000000U) + 0x10000) + 0x1000), 115200);
 usart_set_databits((((0x40000000U) + 0x10000) + 0x1000), 8);
 usart_set_stopbits((((0x40000000U) + 0x10000) + 0x1000), (0x00 << 12));
 usart_set_mode((((0x40000000U) + 0x10000) + 0x1000), (1 << 3));
 usart_set_parity((((0x40000000U) + 0x10000) + 0x1000), 0x00);
 usart_set_flow_control((((0x40000000U) + 0x10000) + 0x1000), 0x00);


 usart_enable((((0x40000000U) + 0x10000) + 0x1000));
}
int _write(int file, char *ptr, int len)
{
 int i;

 if (file == 
            1 
                          || file == 
                                     2
                                                  ) {
  for (i = 0; i < len; i++) {
   if (ptr[i] == '\n') {
    usart_send_blocking((((0x40000000U) + 0x10000) + 0x1000), '\r');
   }
   usart_send_blocking((((0x40000000U) + 0x10000) + 0x1000), ptr[i]);
  }
  return i;
 }
 
(*__errno()) 
      = 
        5
           ;
 return -1;
}

static void adc_setup(void)
{
 gpio_mode_setup((((0x40000000U) + 0x20000) + 0x0000), 0x3, 0x0, (1 << 0));
 gpio_mode_setup((((0x40000000U) + 0x20000) + 0x0000), 0x3, 0x0, (1 << 1));

 adc_power_off((((0x40000000U) + 0x10000) + 0x2000));
 adc_disable_scan_mode((((0x40000000U) + 0x10000) + 0x2000));
 adc_set_sample_time_on_all_channels((((0x40000000U) + 0x10000) + 0x2000), 0x0);

 adc_power_on((((0x40000000U) + 0x10000) + 0x2000));

}

static void dac_setup(void)
{
 gpio_mode_setup((((0x40000000U) + 0x20000) + 0x0000), 0x3, 0x0, (1 << 5));
 dac_disable((((0x40000000U) + 0x00000) + 0x7400), (1 << 1));
 dac_disable_waveform_generation((((0x40000000U) + 0x00000) + 0x7400), (1 << 1));
 dac_enable((((0x40000000U) + 0x00000) + 0x7400), (1 << 1));
 dac_set_trigger_source((((0x40000000U) + 0x00000) + 0x7400), (0x7 << 19));
}

static uint16_t read_adc_naiive(uint8_t channel)
{
 uint8_t channel_array[16];
 channel_array[0] = channel;
 adc_set_regular_sequence((((0x40000000U) + 0x10000) + 0x2000), 1, channel_array);
 adc_start_conversion_regular((((0x40000000U) + 0x10000) + 0x2000));
 while (!adc_eoc((((0x40000000U) + 0x10000) + 0x2000)));
 uint16_t reg16 = adc_read_regular((((0x40000000U) + 0x10000) + 0x2000));
 return reg16;
}

int main(void)
{
 int i;
 int j = 0;
 clock_setup();
 usart_setup();
 printf("hi guys!\n");
 adc_setup();
 dac_setup();


 gpio_mode_setup((((0x40000000U) + 0x20000) + 0x1800), 0x1, 0x0,
   (1 << 13));

 while (1) {
  uint16_t input_adc0 = read_adc_naiive(0);
  uint16_t target = input_adc0 / 2;
  dac_load_data_buffer_single((((0x40000000U) + 0x00000) + 0x7400), target, DAC_ALIGN_RIGHT12, (1 << 1));
  dac_software_trigger((((0x40000000U) + 0x00000) + 0x7400), (1 << 1));
  uint16_t input_adc1 = read_adc_naiive(1);
  printf("tick: %d: adc0= %u, target adc1=%d, adc1=%d\n",
   j++, input_adc0, target, input_adc1);


  gpio_toggle((((0x40000000U) + 0x20000) + 0x1800), (1 << 13));

  for (i = 0; i < 1000000; i++) {
   __asm__("NOP");
  }
 }

 return 0;
}
