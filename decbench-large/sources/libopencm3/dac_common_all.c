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
void dac_enable(uint32_t dac, int channel)
{
 switch (channel) {
 case (1 << 0):
  (*(volatile uint32_t *)((dac) + 0x00)) |= (1 << 0);
  break;
 case (1 << 1):
  (*(volatile uint32_t *)((dac) + 0x00)) |= (1 << 16);
  break;
 case ((1 << 0) | (1 << 1)):
  (*(volatile uint32_t *)((dac) + 0x00)) |= ((1 << 0) | (1 << 16));
  break;
 }
}
void dac_disable(uint32_t dac, int channel)
{
 switch (channel) {
 case (1 << 0):
  (*(volatile uint32_t *)((dac) + 0x00)) &= ~(1 << 0);
  break;
 case (1 << 1):
  (*(volatile uint32_t *)((dac) + 0x00)) &= ~(1 << 16);
  break;
 case ((1 << 0) | (1 << 1)):
  (*(volatile uint32_t *)((dac) + 0x00)) &= ~((1 << 0) | (1 << 16));
  break;
 default:
  break;
 }
}
void dac_dma_enable(uint32_t dac, int channel)
{
 switch (channel) {
 case (1 << 0):
  (*(volatile uint32_t *)((dac) + 0x00)) |= (1 << 12);
  break;
 case (1 << 1):
  (*(volatile uint32_t *)((dac) + 0x00)) |= (1 << 28);
  break;
 case ((1 << 0) | (1 << 1)):
  (*(volatile uint32_t *)((dac) + 0x00)) |= ((1 << 12) | (1 << 28));
  break;
 default:
  break;
 }
}
void dac_dma_disable(uint32_t dac, int channel)
{
 switch (channel) {
 case (1 << 0):
  (*(volatile uint32_t *)((dac) + 0x00)) &= ~(1 << 12);
  break;
 case (1 << 1):
  (*(volatile uint32_t *)((dac) + 0x00)) &= ~(1 << 28);
  break;
 case ((1 << 0) | (1 << 1)):
  (*(volatile uint32_t *)((dac) + 0x00)) &= ~((1 << 12) | (1 << 28));
  break;
 default:
  break;
 }
}
void dac_trigger_enable(uint32_t dac, int channel)
{
 switch (channel) {
 case (1 << 0):
  (*(volatile uint32_t *)((dac) + 0x00)) |= (1 << 2);
  break;
 case (1 << 1):
  (*(volatile uint32_t *)((dac) + 0x00)) |= (1 << 18);
  break;
 case ((1 << 0) | (1 << 1)):
  (*(volatile uint32_t *)((dac) + 0x00)) |= ((1 << 2) | (1 << 18));
  break;
 default:
  break;
 }
}
void dac_trigger_disable(uint32_t dac, int channel)
{
 switch (channel) {
 case (1 << 0):
  (*(volatile uint32_t *)((dac) + 0x00)) &= ~(1 << 2);
  break;
 case (1 << 1):
  (*(volatile uint32_t *)((dac) + 0x00)) &= ~(1 << 18);
  break;
 case ((1 << 0) | (1 << 1)):
  (*(volatile uint32_t *)((dac) + 0x00)) &= ~((1 << 2) | (1 << 18));
  break;
 default:
  break;
 }
}
void dac_set_trigger_source(uint32_t dac, uint32_t source)
{
 (*(volatile uint32_t *)((dac) + 0x00)) |= source;
}
void dac_set_waveform_generation(uint32_t dac, int channel, enum dac_wave wave)
{
 uint32_t reg = (*(volatile uint32_t *)((dac) + 0x00));
 switch(channel) {
 case (1 << 0):
  reg &= ~(0x3 << 6);
  reg |= wave << 6;
  break;
 case (1 << 1):
  reg &= ~(0x3 << 22);
  reg |= wave << 22;
  break;
 case ((1 << 0) | (1 << 1)):
  reg &= ~(0x3 << 6)
   | ~(0x3 << 22);
  reg |= wave << 6;
  reg |= wave << 22;
  break;
 default:
  break;
 }
 (*(volatile uint32_t *)((dac) + 0x00)) = reg;
}







void dac_disable_waveform_generation(uint32_t dac, int channel)
{
 dac_set_waveform_generation(dac, channel, DAC_WAVE_DISABLE);
}
void dac_set_waveform_characteristics(uint32_t dac, int channel, int mamp)
{
 uint32_t reg = (*(volatile uint32_t *)((dac) + 0x00));
 switch(channel) {
 case (1 << 0):
  reg &= ~(0xf << 8);
  reg |= mamp << 8;
  break;
 case (1 << 1):
  reg &= ~(0xf << 24);
  reg |= mamp << 24;
  break;
 case ((1 << 0) | (1 << 1)):
  reg &= ~(0xf << 8)
   | ~(0xf << 24);
  reg |= mamp << 8;
  reg |= mamp << 24;
  break;
 default:
  break;
 }
 (*(volatile uint32_t *)((dac) + 0x00)) = reg;
}
void dac_load_data_buffer_single(uint32_t dac, uint16_t data,
  enum dac_align align,
  int channel)
{
 if (channel == (1 << 0)) {
  switch (align) {
  case DAC_ALIGN_RIGHT8:
   (*(volatile uint32_t *)((dac) + 0x10)) = data;
   break;
  case DAC_ALIGN_RIGHT12:
   (*(volatile uint32_t *)((dac) + 0x08)) = data;
   break;
  case DAC_ALIGN_LEFT12:
   (*(volatile uint32_t *)((dac) + 0x0C)) = data;
   break;
  default:
   break;
  }
 } else if (channel == (1 << 1)) {
  switch (align) {
  case DAC_ALIGN_RIGHT8:
   (*(volatile uint32_t *)((dac) + 0x1C)) = data;
   break;
  case DAC_ALIGN_RIGHT12:
   (*(volatile uint32_t *)((dac) + 0x14)) = data;
   break;
  case DAC_ALIGN_LEFT12:
   (*(volatile uint32_t *)((dac) + 0x18)) = data;
   break;
  default:
   break;
  }
 }
}
void dac_load_data_buffer_dual(uint32_t dac,
  uint16_t data1, uint16_t data2,
  enum dac_align align)
{
 switch (align) {
 case DAC_ALIGN_RIGHT8:
  (*(volatile uint32_t *)((dac) + 0x28)) = ((data1 & 0xFF) | ((data2 & 0xFF) << 8));
  break;
 case DAC_ALIGN_RIGHT12:
  (*(volatile uint32_t *)((dac) + 0x20)) = ((data1 & 0xFFF) |
    ((data2 & 0xFFF) << 16));
  break;
 case DAC_ALIGN_LEFT12:
  (*(volatile uint32_t *)((dac) + 0x24)) = ((data1 & 0xFFF) |
    ((data2 & 0xFFF) << 16));
  break;
 default:
  break;
 }
}
void dac_software_trigger(uint32_t dac, int channel)
{
 switch (channel) {
 case (1 << 0):
  (*(volatile uint32_t *)((dac) + 0x04)) |= (1 << 0);
  break;
 case (1 << 1):
  (*(volatile uint32_t *)((dac) + 0x04)) |= (1 << 1);
  break;
 case ((1 << 0) | (1 << 1)):
  (*(volatile uint32_t *)((dac) + 0x04)) |= ((1 << 0) | (1 << 1));
  break;
 default:
  break;
 }
}
