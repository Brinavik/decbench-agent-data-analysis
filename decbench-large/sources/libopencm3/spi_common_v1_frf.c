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
#define LIBOPENCM3_SPI_H 

       



       



#define LIBOPENCM3_SPI_COMMON_ALL_H 
#define SPI1 SPI1_BASE
#define SPI2 SPI2_BASE
#define SPI3 SPI3_BASE
#define SPI4 SPI4_BASE
#define SPI5 SPI5_BASE
#define SPI6 SPI6_BASE






#define SPI_CR1(spi_base) MMIO32((spi_base) + 0x00)
#define SPI1_CR1 SPI_CR1(SPI1_BASE)
#define SPI2_CR1 SPI_CR1(SPI2_BASE)
#define SPI3_CR1 SPI_CR1(SPI3_BASE)


#define SPI_CR2(spi_base) MMIO32((spi_base) + 0x04)
#define SPI1_CR2 SPI_CR2(SPI1_BASE)
#define SPI2_CR2 SPI_CR2(SPI2_BASE)
#define SPI3_CR2 SPI_CR2(SPI3_BASE)


#define SPI_SR(spi_base) MMIO32((spi_base) + 0x08)
#define SPI1_SR SPI_SR(SPI1_BASE)
#define SPI2_SR SPI_SR(SPI2_BASE)
#define SPI3_SR SPI_SR(SPI3_BASE)


#define SPI_DR(spi_base) MMIO32((spi_base) + 0x0c)
#define SPI1_DR SPI_DR(SPI1_BASE)
#define SPI2_DR SPI_DR(SPI2_BASE)
#define SPI3_DR SPI_DR(SPI3_BASE)



#define SPI_CRCPR(spi_base) MMIO32((spi_base) + 0x10)
#define SPI1_CRCPR SPI_CRCPR(SPI1_BASE)
#define SPI2_CRCPR SPI_CRCPR(SPI2_BASE)
#define SPI3_CRCPR SPI_CRCPR(SPI3_BASE)



#define SPI_RXCRCR(spi_base) MMIO32((spi_base) + 0x14)
#define SPI1_RXCRCR SPI_RXCRCR(SPI1_BASE)
#define SPI2_RXCRCR SPI_RXCRCR(SPI2_BASE)
#define SPI3_RXCRCR SPI_RXCRCR(SPI3_BASE)



#define SPI_TXCRCR(spi_base) MMIO32((spi_base) + 0x18)
#define SPI1_TXCRCR SPI_TXCRCR(SPI1_BASE)
#define SPI2_TXCRCR SPI_TXCRCR(SPI2_BASE)
#define SPI3_TXCRCR SPI_TXCRCR(SPI3_BASE)


#define SPI_I2SCFGR(spi_base) MMIO32((spi_base) + 0x1c)
#define SPI1_I2SCFGR SPI_I2SCFGR(SPI1_BASE)
#define SPI2_I2SCFGR SPI_I2SCFGR(SPI2_BASE)
#define SPI3_I2SCFGR SPI_I2SCFGR(SPI3_BASE)


#define SPI_I2SPR(spi_base) MMIO32((spi_base) + 0x20)
#define SPI1_I2SPR SPI_I2SPR(SPI1_BASE)
#define SPI2_I2SPR SPI_I2SPR(SPI2_BASE)
#define SPI3_I2SPR SPI_I2SPR(SPI3_BASE)






#define SPI_CR1_BIDIMODE_2LINE_UNIDIR (0 << 15)
#define SPI_CR1_BIDIMODE_1LINE_BIDIR (1 << 15)
#define SPI_CR1_BIDIMODE (1 << 15)


#define SPI_CR1_BIDIOE (1 << 14)


#define SPI_CR1_CRCEN (1 << 13)


#define SPI_CR1_CRCNEXT (1 << 12)


#define SPI_CR1_RXONLY (1 << 10)


#define SPI_CR1_SSM (1 << 9)


#define SPI_CR1_SSI (1 << 8)







#define SPI_CR1_MSBFIRST (0 << 7)
#define SPI_CR1_LSBFIRST (1 << 7)



#define SPI_CR1_SPE (1 << 6)







#define SPI_CR1_BAUDRATE_FPCLK_DIV_2 (0x00 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_4 (0x01 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_8 (0x02 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_16 (0x03 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_32 (0x04 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_64 (0x05 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_128 (0x06 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_256 (0x07 << 3)






#define SPI_CR1_BR_FPCLK_DIV_2 0x0
#define SPI_CR1_BR_FPCLK_DIV_4 0x1
#define SPI_CR1_BR_FPCLK_DIV_8 0x2
#define SPI_CR1_BR_FPCLK_DIV_16 0x3
#define SPI_CR1_BR_FPCLK_DIV_32 0x4
#define SPI_CR1_BR_FPCLK_DIV_64 0x5
#define SPI_CR1_BR_FPCLK_DIV_128 0x6
#define SPI_CR1_BR_FPCLK_DIV_256 0x7



#define SPI_CR1_MSTR (1 << 2)







#define SPI_CR1_CPOL_CLK_TO_0_WHEN_IDLE (0 << 1)
#define SPI_CR1_CPOL_CLK_TO_1_WHEN_IDLE (1 << 1)

#define SPI_CR1_CPOL (1 << 1)







#define SPI_CR1_CPHA_CLK_TRANSITION_1 (0 << 0)
#define SPI_CR1_CPHA_CLK_TRANSITION_2 (1 << 0)

#define SPI_CR1_CPHA (1 << 0)






#define SPI_CR2_TXEIE (1 << 7)


#define SPI_CR2_RXNEIE (1 << 6)


#define SPI_CR2_ERRIE (1 << 5)





#define SPI_CR2_SSOE (1 << 2)


#define SPI_CR2_TXDMAEN (1 << 1)


#define SPI_CR2_RXDMAEN (1 << 0)






#define SPI_SR_BSY (1 << 7)


#define SPI_SR_OVR (1 << 6)



#define SPI_SR_MODF (1 << 5)



#define SPI_SR_CRCERR (1 << 4)



#define SPI_SR_UDR (1 << 3)



#define SPI_SR_CHSIDE (1 << 2)


#define SPI_SR_TXE (1 << 1)


#define SPI_SR_RXNE (1 << 0)
#define SPI_I2SCFGR_I2SMOD (1 << 11)


#define SPI_I2SCFGR_I2SE (1 << 10)


#define SPI_I2SCFGR_I2SCFG_LSB 8
#define SPI_I2SCFGR_I2SCFG_SLAVE_TRANSMIT 0x0
#define SPI_I2SCFGR_I2SCFG_SLAVE_RECEIVE 0x1
#define SPI_I2SCFGR_I2SCFG_MASTER_TRANSMIT 0x2
#define SPI_I2SCFGR_I2SCFG_MASTER_RECEIVE 0x3


#define SPI_I2SCFGR_PCMSYNC (1 << 7)




#define SPI_I2SCFGR_I2SSTD_LSB 4
#define SPI_I2SCFGR_I2SSTD_I2S_PHILIPS 0x0
#define SPI_I2SCFGR_I2SSTD_MSB_JUSTIFIED 0x1
#define SPI_I2SCFGR_I2SSTD_LSB_JUSTIFIED 0x2
#define SPI_I2SCFGR_I2SSTD_PCM 0x3


#define SPI_I2SCFGR_CKPOL (1 << 3)


#define SPI_I2SCFGR_DATLEN_LSB 1
#define SPI_I2SCFGR_DATLEN_16BIT 0x0
#define SPI_I2SCFGR_DATLEN_24BIT 0x1
#define SPI_I2SCFGR_DATLEN_32BIT 0x2


#define SPI_I2SCFGR_CHLEN (1 << 0)
#define SPI_I2SPR_MCKOE (1 << 9)


#define SPI_I2SPR_ODD (1 << 8)









void spi_enable(uint32_t spi);
void spi_disable(uint32_t spi);
uint16_t spi_clean_disable(uint32_t spi);
void spi_write(uint32_t spi, uint16_t data);
void spi_send(uint32_t spi, uint16_t data);
uint16_t spi_read(uint32_t spi);
uint16_t spi_xfer(uint32_t spi, uint16_t data);
void spi_set_bidirectional_mode(uint32_t spi);
void spi_set_unidirectional_mode(uint32_t spi);
void spi_set_bidirectional_receive_only_mode(uint32_t spi);
void spi_set_bidirectional_transmit_only_mode(uint32_t spi);
void spi_enable_crc(uint32_t spi);
void spi_disable_crc(uint32_t spi);
void spi_set_next_tx_from_buffer(uint32_t spi);
void spi_set_next_tx_from_crc(uint32_t spi);
void spi_set_full_duplex_mode(uint32_t spi);
void spi_set_receive_only_mode(uint32_t spi);
void spi_disable_software_slave_management(uint32_t spi);
void spi_enable_software_slave_management(uint32_t spi);
void spi_set_nss_high(uint32_t spi);
void spi_set_nss_low(uint32_t spi);
void spi_send_lsb_first(uint32_t spi);
void spi_send_msb_first(uint32_t spi);
void spi_set_baudrate_prescaler(uint32_t spi, uint8_t baudrate);
void spi_set_master_mode(uint32_t spi);
void spi_set_slave_mode(uint32_t spi);
void spi_set_clock_polarity_1(uint32_t spi);
void spi_set_clock_polarity_0(uint32_t spi);
void spi_set_clock_phase_1(uint32_t spi);
void spi_set_clock_phase_0(uint32_t spi);
void spi_enable_tx_buffer_empty_interrupt(uint32_t spi);
void spi_disable_tx_buffer_empty_interrupt(uint32_t spi);
void spi_enable_rx_buffer_not_empty_interrupt(uint32_t spi);
void spi_disable_rx_buffer_not_empty_interrupt(uint32_t spi);
void spi_enable_error_interrupt(uint32_t spi);
void spi_disable_error_interrupt(uint32_t spi);
void spi_enable_ss_output(uint32_t spi);
void spi_disable_ss_output(uint32_t spi);
void spi_enable_tx_dma(uint32_t spi);
void spi_disable_tx_dma(uint32_t spi);
void spi_enable_rx_dma(uint32_t spi);
void spi_disable_rx_dma(uint32_t spi);
void spi_set_standard_mode(uint32_t spi, uint8_t mode);


#define SPI_CR1_DFF_8BIT (0 << 11)
#define SPI_CR1_DFF_16BIT (1 << 11)



#define SPI_CR1_DFF (1 << 11)





int spi_init_master(uint32_t spi, uint32_t br, uint32_t cpol, uint32_t cpha,
  uint32_t dff, uint32_t lsbfirst);
void spi_set_dff_8bit(uint32_t spi);
void spi_set_dff_16bit(uint32_t spi);







#define SPI_CR2_FRF (1 << 4)
#define SPI_CR2_FRF_MOTOROLA_MODE (0 << 4)
#define SPI_CR2_FRF_TI_MODE (1 << 4)




#define SPI_SR_TIFRFE (1 << 8)
#define SPI_SR_FRE (1 << 8)





void spi_set_frf_ti(uint32_t spi);
void spi_set_frf_motorola(uint32_t spi);


void spi_set_frf_ti(uint32_t spi)
{
 (*(volatile uint32_t *)((spi) + 0x04)) |= (1 << 4);
}







void spi_set_frf_motorola(uint32_t spi)
{
 (*(volatile uint32_t *)((spi) + 0x04)) &= ~(1 << 4);
}

#define SPI_CR2_FRF (1 << 4)
#define SPI_CR2_FRF_MOTOROLA_MODE (0 << 4)
#define SPI_CR2_FRF_TI_MODE (1 << 4)




#define SPI_SR_TIFRFE (1 << 8)
#define SPI_SR_FRE (1 << 8)
