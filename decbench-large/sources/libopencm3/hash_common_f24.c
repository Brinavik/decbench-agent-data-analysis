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




#define LIBOPENCM3_HASH_H 

#define LIBOPENCM3_HASH_COMMON_F24_H 
#define HASH_BASE (PERIPH_BASE_AHB2 + 0x60400)
#define HASH HASH_BASE





#define HASH_CR MMIO32(HASH + 0x00)


#define HASH_DIN MMIO32(HASH + 0x04)


#define HASH_STR MMIO32(HASH + 0x08)


#define HASH_HR (&MMIO32(HASH + 0x0C))


#define HASH_IMR MMIO32(HASH + 0x20)


#define HASH_SR MMIO32(HASH + 0x28)


#define HASH_CSR (&MMIO32(HASH + 0xF8))




#define HASH_CR_INIT (1 << 2)


#define HASH_CR_DMAE (1 << 3)







#define HASH_DATA_32BIT (0 << 4)
#define HASH_DATA_16BIT (1 << 4)
#define HASH_DATA_8BIT (2 << 4)
#define HASH_DATA_BITSTRING (3 << 4)

#define HASH_CR_DATATYPE (3 << 4)







#define HASH_MODE_HASH (0 << 6)
#define HASH_MODE_HMAC (1 << 6)

#define HASH_CR_MODE (1 << 6)







#define HASH_ALGO_SHA1 (0 << 7)
#define HASH_ALGO_MD5 (1 << 7)

#define HASH_CR_ALGO (1 << 7)


#define HASH_CR_NBW (15 << 8)


#define HASH_CR_DINNE (1 << 12)







#define HASH_KEY_SHORT (0 << 16)
#define HASH_KEY_LONG (1 << 16)

#define HASH_CR_LKEY (1 << 16)





#define HASH_STR_NBW (31 << 0)


#define HASH_STR_DCAL (1 << 8)




#define HASH_IMR_DINIE (1 << 0)


#define HASH_IMR_DCIE (1 << 1)




#define HASH_SR_DINIS (1 << 0)


#define HASH_SR_DCIS (1 << 1)


#define HASH_SR_DMAS (1 << 2)


#define HASH_SR_BUSY (1 << 3)






void hash_set_mode(uint8_t mode);
void hash_set_algorithm(uint8_t algorithm);
void hash_set_data_type(uint8_t datatype);
void hash_set_key_length(uint8_t keylength);
void hash_set_last_word_valid_bits(uint8_t validbits);
void hash_init(void);
void hash_add_data(uint32_t data);
void hash_digest(void);
void hash_get_result(uint32_t *data);


void hash_set_mode(uint8_t mode)
{
 (*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x00)) &= ~(1 << 6);
 (*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x00)) |= mode;
}
void hash_set_algorithm(uint8_t algorithm)
{
 (*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x00)) &= ~(1 << 7);
 (*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x00)) |= algorithm;
}
void hash_set_data_type(uint8_t datatype)
{
 (*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x00)) &= ~(3 << 4);
 (*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x00)) |= datatype;
}
void hash_set_key_length(uint8_t keylength)
{
 (*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x00)) &= ~(1 << 16);
 (*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x00)) |= keylength;
}
void hash_set_last_word_valid_bits(uint8_t validbits)
{
 (*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x08)) &= ~((31 << 0));
 (*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x08)) |= validbits;
}
void hash_init()
{
 (*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x00)) |= (1 << 2);
}
void hash_add_data(uint32_t data)
{
 (*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x04)) = data;
}
void hash_digest()
{
 (*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x08)) |= (1 << 8);
}
void hash_get_result(uint32_t *data)
{
 data[0] = (&(*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x0C)))[0];
 data[1] = (&(*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x0C)))[1];
 data[2] = (&(*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x0C)))[2];
 data[3] = (&(*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x0C)))[3];

 if (((*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x00)) & (1 << 7)) == (0 << 7)) {
  data[4] = (&(*(volatile uint32_t *)((0x50000000U + 0x60400) + 0x0C)))[4];
 }
}
