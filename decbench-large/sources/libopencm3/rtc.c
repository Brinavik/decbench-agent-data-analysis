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
#define LIBOPENCM3_EXTI_H 

#define LIBOPENCM3_EXTI_COMMON_ALL_H 



#define EXTI0 (1 << 0)
#define EXTI1 (1 << 1)
#define EXTI2 (1 << 2)
#define EXTI3 (1 << 3)
#define EXTI4 (1 << 4)
#define EXTI5 (1 << 5)
#define EXTI6 (1 << 6)
#define EXTI7 (1 << 7)
#define EXTI8 (1 << 8)
#define EXTI9 (1 << 9)
#define EXTI10 (1 << 10)
#define EXTI11 (1 << 11)
#define EXTI12 (1 << 12)
#define EXTI13 (1 << 13)
#define EXTI14 (1 << 14)
#define EXTI15 (1 << 15)
#define EXTI16 (1 << 16)
#define EXTI17 (1 << 17)
#define EXTI18 (1 << 18)
#define EXTI19 (1 << 19)
#define EXTI20 (1 << 20)
#define EXTI21 (1 << 21)
#define EXTI22 (1 << 22)
#define EXTI23 (1 << 23)
#define EXTI24 (1 << 24)
#define EXTI25 (1 << 25)
#define EXTI26 (1 << 26)
#define EXTI27 (1 << 27)
#define EXTI28 (1 << 28)
#define EXTI29 (1 << 29)
#define EXTI30 (1 << 30)
#define EXTI31 (1 << 31)

#define EXTI32 (1 << 0)
#define EXTI33 (1 << 1)
#define EXTI34 (1 << 2)
#define EXTI35 (1 << 3)
#define EXTI36 (1 << 4)
#define EXTI37 (1 << 5)



enum exti_trigger_type {
 EXTI_TRIGGER_RISING,
 EXTI_TRIGGER_FALLING,
 EXTI_TRIGGER_BOTH,
};



void exti_set_trigger(uint32_t extis, enum exti_trigger_type trig);
void exti_enable_request(uint32_t extis);
void exti_disable_request(uint32_t extis);
void exti_reset_request(uint32_t extis);
void exti_select_source(uint32_t exti, uint32_t gpioport);
uint32_t exti_get_flag_status(uint32_t exti);



       
#define EXTI_IMR MMIO32(EXTI_BASE + 0x00)

#define EXTI_EMR MMIO32(EXTI_BASE + 0x04)

#define EXTI_RTSR MMIO32(EXTI_BASE + 0x08)

#define EXTI_FTSR MMIO32(EXTI_BASE + 0x0c)

#define EXTI_SWIER MMIO32(EXTI_BASE + 0x10)

#define EXTI_PR MMIO32(EXTI_BASE + 0x14)





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



#define LIBOPENCM3_RTC_H 

#define LIBOPENCM3_RTC2_H 
#define RTC_TR MMIO32(RTC_BASE + 0x00)


#define RTC_DR MMIO32(RTC_BASE + 0x04)


#define RTC_CR MMIO32(RTC_BASE + 0x08)


#define RTC_ISR MMIO32(RTC_BASE + 0x0c)


#define RTC_PRER MMIO32(RTC_BASE + 0x10)


#define RTC_WUTR MMIO32(RTC_BASE + 0x14)


#define RTC_CALIBR MMIO32(RTC_BASE + 0x18)


#define RTC_ALRMAR MMIO32(RTC_BASE + 0x1c)
#define RTC_ALRMBR MMIO32(RTC_BASE + 0x20)


#define RTC_WPR MMIO32(RTC_BASE + 0x24)


#define RTC_SSR MMIO32(RTC_BASE + 0x28)


#define RTC_SHIFTR MMIO32(RTC_BASE + 0x2c)


#define RTC_TSTR MMIO32(RTC_BASE + 0x30)

#define RTC_TSDR MMIO32(RTC_BASE + 0x34)

#define RTC_TSSSR MMIO32(RTC_BASE + 0x38)


#define RTC_CALR MMIO32(RTC_BASE + 0x3c)


#define RTC_TAFCR MMIO32(RTC_BASE + 0x40)


#define RTC_ALRMASSR MMIO32(RTC_BASE + 0x44)
#define RTC_ALRMBSSR MMIO32(RTC_BASE + 0x48)

#define RTC_BKP_BASE (RTC_BASE + 0x50)

#define RTC_BKPXR(reg) MMIO32(RTC_BKP_BASE + (4 * (reg)))
#define RTC_TR_PM (1 << 22)

#define RTC_TR_HT_SHIFT (20)

#define RTC_TR_HT_MASK (0x3)

#define RTC_TR_HU_SHIFT (16)

#define RTC_TR_HU_MASK (0xf)

#define RTC_TR_MNT_SHIFT (12)

#define RTC_TR_MNT_MASK (0x7)

#define RTC_TR_MNU_SHIFT (8)

#define RTC_TR_MNU_MASK (0xf)

#define RTC_TR_ST_SHIFT (4)

#define RTC_TR_ST_MASK (0x7)

#define RTC_TR_SU_SHIFT (0)

#define RTC_TR_SU_MASK (0xf)







#define RTC_DR_YT_SHIFT (20)

#define RTC_DR_YT_MASK (0xf)

#define RTC_DR_YU_SHIFT (16)

#define RTC_DR_YU_MASK (0xf)

#define RTC_DR_WDU_SHIFT (13)

#define RTC_DR_WDU_MASK (0x7)

#define RTC_DR_MT_SHIFT (12)

#define RTC_DR_MT_MASK (1)

#define RTC_DR_MU_SHIFT (8)

#define RTC_DR_MU_MASK (0xf)

#define RTC_DR_DT_SHIFT (4)

#define RTC_DR_DT_MASK (0x3)

#define RTC_DR_DU_SHIFT (0)

#define RTC_DR_DU_MASK (0xf)
#define RTC_CR_COE (1<<23)

#define RTC_CR_OSEL_SHIFT 21
#define RTC_CR_OSEL_MASK (0x3)




#define RTC_CR_OSEL_DISABLED (0x0)
#define RTC_CR_OSEL_ALARMA (0x1)
#define RTC_CR_OSEL_ALARMB (0x2)
#define RTC_CR_OSEL_WAKEUP (0x3)



#define RTC_CR_POL (1<<20)

#define RTC_CR_COSEL (1<<19)

#define RTC_CR_BKP (1<<18)

#define RTC_CR_SUB1H (1<<17)

#define RTC_CR_ADD1H (1<<16)

#define RTC_CR_TSIE (1<<15)

#define RTC_CR_WUTIE (1<<14)

#define RTC_CR_ALRBIE (1<<13)

#define RTC_CR_ALRAIE (1<<12)

#define RTC_CR_TSE (1<<11)

#define RTC_CR_WUTE (1<<10)

#define RTC_CR_ALRBE (1<<9)

#define RTC_CR_ALRAE (1<<8)

#define RTC_CR_DCE (1<<7)

#define RTC_CR_FMT (1<<6)

#define RTC_CR_BYPSHAD (1<<5)

#define RTC_CR_REFCKON (1<<4)

#define RTC_CR_TSEDGE (1<<3)


#define RTC_CR_WUCLKSEL_SHIFT (0)
#define RTC_CR_WUCLKSEL_MASK (0x7)
#define RTC_CR_WUCLKSEL_RTC_DIV16 (0x0)
#define RTC_CR_WUCLKSEL_RTC_DIV8 (0x1)
#define RTC_CR_WUCLKSEL_RTC_DIV4 (0x2)
#define RTC_CR_WUCLKSEL_RTC_DIV2 (0x3)
#define RTC_CR_WUCLKSEL_SPRE (0x4)
#define RTC_CR_WUCLKSEL_SPRE_216 (0x6)
#define RTC_ISR_RECALPF (1<<16)

#define RTC_ISR_TAMP3F (1<<15)

#define RTC_ISR_TAMP2F (1<<14)

#define RTC_ISR_TAMP1F (1<<13)

#define RTC_ISR_TSOVF (1<<12)

#define RTC_ISR_TSF (1<<11)

#define RTC_ISR_WUTF (1<<10)

#define RTC_ISR_ALRBF (1<<9)

#define RTC_ISR_ALRAF (1<<8)

#define RTC_ISR_INIT (1<<7)

#define RTC_ISR_INITF (1<<6)

#define RTC_ISR_RSF (1<<5)

#define RTC_ISR_INITS (1<<4)

#define RTC_ISR_SHPF (1<<3)

#define RTC_ISR_WUTWF (1<<2)

#define RTC_ISR_ALRBWF (1<<1)

#define RTC_ISR_ALRAWF (1<<0)






#define RTC_PRER_PREDIV_A_SHIFT (16)

#define RTC_PRER_PREDIV_A_MASK (0x7f)

#define RTC_PRER_PREDIV_S_SHIFT (0)

#define RTC_PRER_PREDIV_S_MASK (0x7fff)



#define RTC_CALIBR_DCS (1 << 7)

#define RTC_CALIBR_DC_SHIFT (0)
#define RTC_CALIBR_DC_MASK (0x1f)





#define RTC_ALRMXR_MSK4 (1<<31)
#define RTC_ALRMXR_WDSEL (1<<30)
#define RTC_ALRMXR_DT_SHIFT (28)
#define RTC_ALRMXR_DT_MASK (0x3)
#define RTC_ALRMXR_DU_SHIFT (24)
#define RTC_ALRMXR_DU_MASK (0xf)
#define RTC_ALRMXR_MSK3 (1<<23)
#define RTC_ALRMXR_PM (1<<22)
#define RTC_ALRMXR_HT_SHIFT (20)
#define RTC_ALRMXR_HT_MASK (0x3)
#define RTC_ALRMXR_HU_SHIFT (16)
#define RTC_ALRMXR_HU_MASK (0xf)
#define RTC_ALRMXR_MSK2 (1<<15)
#define RTC_ALRMXR_MNT_SHIFT (12)
#define RTC_ALRMXR_MNT_MASK (0x7)
#define RTC_ALRMXR_MNU_SHIFT (8)
#define RTC_ALRMXR_MNU_MASK (0xf)
#define RTC_ALRMXR_MSK1 (1<<7)
#define RTC_ALRMXR_ST_SHIFT (4)
#define RTC_ALRMXR_ST_MASK (0x7)
#define RTC_ALRMXR_SU_SHIFT (0)
#define RTC_ALRMXR_SU_MASK (0xf)



#define RTC_SHIFTR_ADD1S (1<<31)

#define RTC_SHIFTR_SUBFS_SHIFT (0)
#define RTC_SHIFTR_SUBFS_MASK (0x7fff)




#define RTC_TSTR_PM (1<<22)
#define RTC_TSTR_HT_SHIFT (20)
#define RTC_TSTR_HT_MASK (0x3)
#define RTC_TSTR_HU_SHIFT (16)
#define RTC_TSTR_HU_MASK (0xf)
#define RTC_TSTR_MNT_SHIFT (12)
#define RTC_TSTR_MNT_MASK (0x7)
#define RTC_TSTR_MNU_SHIFT (8)
#define RTC_TSTR_MNU_MASK (0xf)
#define RTC_TSTR_ST_SHIFT (4)
#define RTC_TSTR_ST_MASK (0x7)
#define RTC_TSTR_SU_SHIFT (0)
#define RTC_TSTR_SU_MASK (0xf)





#define RTC_TSDR_WDU_SHIFT (13)
#define RTC_TSDR_WDU_MASK (0x7)
#define RTC_TSDR_MT (1<<12)
#define RTC_TSDR_MU_SHIFT (8)
#define RTC_TSDR_MU_MASK (0xf)
#define RTC_TSDR_DT_SHIFT (4)
#define RTC_TSDR_DT_MASK (0x3)
#define RTC_TSDR_DU_SHIFT (0)
#define RTC_TSDR_DU_MASK (0xf)





#define RTC_CALR_CALP (1 << 15)
#define RTC_CALR_CALW8 (1 << 14)
#define RTC_CALR_CALW16 (1 << 13)
#define RTC_CALR_CALM_SHIFT (0)
#define RTC_CALR_CALM_MASK (0x1ff)





#define RTC_TAFCR_ALARMOUTTYPE (1<<18)
#define RTC_TAFCR_TAMPPUDIS (1<<15)

#define RTC_TAFCR_TAMPPRCH_SHIFT (13)
#define RTC_TAFCR_TAMPPRCH_MASK (0x3)
#define RTC_TAFCR_TAMPPRCH_1RTC (0x0)
#define RTC_TAFCR_TAMPPRCH_2RTC (0x1)
#define RTC_TAFCR_TAMPPRCH_4RTC (0x2)
#define RTC_TAFCR_TAMPPRCH_8RTC (0x3)

#define RTC_TAFCR_TAMPFLT_SHIFT (11)
#define RTC_TAFCR_TAMPFLT_MASK (0x3)
#define RTC_TAFCR_TAMPFLT_EDGE1 (0x0)
#define RTC_TAFCR_TAMPFLT_EDGE2 (0x1)
#define RTC_TAFCR_TAMPFLT_EDGE4 (0x2)
#define RTC_TAFCR_TAMPFLT_EDGE8 (0x3)

#define RTC_TAFCR_TAMPFREQ_SHIFT (8)
#define RTC_TAFCR_TAMPFREQ_MASK (0x7)
#define RTC_TAFCR_TAMPFREQ_RTCDIV32K (0x0)
#define RTC_TAFCR_TAMPFREQ_RTCDIV16K (0x1)
#define RTC_TAFCR_TAMPFREQ_RTCDIV8K (0x2)
#define RTC_TAFCR_TAMPFREQ_RTCDIV4K (0x3)
#define RTC_TAFCR_TAMPFREQ_RTCDIV2K (0x4)
#define RTC_TAFCR_TAMPFREQ_RTCDIV1K (0x5)
#define RTC_TAFCR_TAMPFREQ_RTCDIV512 (0x6)
#define RTC_TAFCR_TAMPFREQ_RTCDIV256 (0x7)

#define RTC_TAFCR_TAMPTS (1<<7)
#define RTC_TAFCR_TAMP3TRG (1<<6)
#define RTC_TAFCR_TAMP3E (1<<5)
#define RTC_TAFCR_TAMP2TRG (1<<4)
#define RTC_TAFCR_TAMP2E (1<<3)
#define RTC_TAFCR_TAMPIE (1<<2)
#define RTC_TAFCR_TAMP1TRG (1<<1)
#define RTC_TAFCR_TAMP1E (1<<0)




#define RTC_ALRMXSSR_MASKSS_SHIFT (24)
#define RTC_ALARXSSR_MASKSS_MASK (0xf)

#define RTC_ALRMXSSR_SS_SHIFT (0)
#define RTC_ALARXSSR_SS_MASK (0x7fff)

enum rtc_weekday {
 RTC_DR_WDU_MON = 0x01,
 RTC_DR_WDU_TUE,
 RTC_DR_WDU_WED,
 RTC_DR_WDU_THU,
 RTC_DR_WDU_FRI,
 RTC_DR_WDU_SAT,
 RTC_DR_WDU_SUN,
};



void rtc_set_prescaler(uint32_t sync, uint32_t async);
void rtc_wait_for_synchro(void);
void rtc_lock(void);
void rtc_unlock(void);
void rtc_set_wakeup_time(uint16_t wkup_time, uint8_t rtc_cr_wucksel);
void rtc_clear_wakeup_flag(void);
void rtc_set_init_flag(void);
void rtc_clear_init_flag(void);

_Bool 
    rtc_init_flag_is_ready(void);
void rtc_wait_for_init_ready(void);
void rtc_set_bypass_shadow_register(void);
void rtc_enable_bypass_shadow_register(void);
void rtc_disable_bypass_shadow_register(void);
void rtc_set_am_format(void);
void rtc_set_pm_format(void);
void rtc_calendar_set_year(uint8_t year);
void rtc_calendar_set_weekday(enum rtc_weekday rtc_dr_wdu);
void rtc_calendar_set_month(uint8_t month);
void rtc_calendar_set_day(uint8_t day);
void rtc_calendar_set_date(uint8_t year, uint8_t month, uint8_t day, enum rtc_weekday rtc_dr_wdu);
void rtc_time_set_hour(uint8_t hour, 
                                    _Bool 
                                         use_am_notation);
void rtc_time_set_minute(uint8_t minute);
void rtc_time_set_second(uint8_t second);
void rtc_time_set_time(uint8_t hour, uint8_t minute, uint8_t second, 
                                                                    _Bool 
                                                                         use_am_notation);





void rtc_enable_wakeup_timer(void);
void rtc_disable_wakeup_timer(void);
void rtc_enable_wakeup_timer_interrupt(void);
void rtc_disable_wakeup_timer_interrupt(void);


void rtc_enable_wakeup_timer(void)
{
 (*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x2800) + 0x08)) |= (1<<10) | ((0x3) << 21);
 rtc_enable_wakeup_timer_interrupt();
}






void rtc_disable_wakeup_timer(void)
{
 (*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x2800) + 0x08)) &= ~(1<<10);
 rtc_disable_wakeup_timer_interrupt();
}






void rtc_enable_wakeup_timer_interrupt(void)
{






 exti_enable_request((1 << 22));
 exti_set_trigger((1 << 22), EXTI_TRIGGER_RISING);


 nvic_enable_irq(3);
 nvic_set_priority(3, 1);


 (*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x2800) + 0x08)) |= (1<<14);
}






void rtc_disable_wakeup_timer_interrupt(void)
{

 exti_disable_request((1 << 22));


 nvic_disable_irq(3);


 (*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x2800) + 0x08)) &= ~(1<<14);
}
