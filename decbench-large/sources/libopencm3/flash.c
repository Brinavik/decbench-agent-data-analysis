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
#define LIBOPENCM3_FLASH_H 

       





void flash_prefetch_enable(void);





void flash_prefetch_disable(void);
void flash_set_ws(uint32_t ws);




void flash_lock(void);





void flash_unlock(void);





void flash_unlock_option_bytes(void);


       








void flash_clear_eop_flag(void);





void flash_clear_status_flags(void);





void flash_wait_for_last_operation(void);


#define LIBOPENCM3_FLASH_COMMON_F24_H 


       







#define FLASH_ACR_DCRST (1 << 12)
#define FLASH_ACR_ICRST (1 << 11)
#define FLASH_ACR_DCEN (1 << 10)
#define FLASH_ACR_ICEN (1 << 9)






void flash_dcache_enable(void);


void flash_dcache_disable(void);


void flash_icache_enable(void);


void flash_icache_disable(void);




void flash_dcache_reset(void);




void flash_icache_reset(void);







#define FLASH_ACR MMIO32(FLASH_MEM_INTERFACE_BASE + 0x00)

#define FLASH_KEYR MMIO32(FLASH_MEM_INTERFACE_BASE + 0x04)

#define FLASH_OPTKEYR MMIO32(FLASH_MEM_INTERFACE_BASE + 0x08)

#define FLASH_SR MMIO32(FLASH_MEM_INTERFACE_BASE + 0x0C)

#define FLASH_CR MMIO32(FLASH_MEM_INTERFACE_BASE + 0x10)

#define FLASH_OPTCR MMIO32(FLASH_MEM_INTERFACE_BASE + 0x14)

#define FLASH_OPTCR1 MMIO32(FLASH_MEM_INTERFACE_BASE + 0x18)





#define FLASH_ACR_LATENCY(w) ((w) & FLASH_ACR_LATENCY_MASK)
#define FLASH_ACR_LATENCY_0WS 0x00
#define FLASH_ACR_LATENCY_1WS 0x01
#define FLASH_ACR_LATENCY_2WS 0x02
#define FLASH_ACR_LATENCY_3WS 0x03
#define FLASH_ACR_LATENCY_4WS 0x04
#define FLASH_ACR_LATENCY_5WS 0x05
#define FLASH_ACR_LATENCY_6WS 0x06
#define FLASH_ACR_LATENCY_7WS 0x07

#define FLASH_ACR_LATENCY_SHIFT 0
#define FLASH_ACR_LATENCY_MASK 0x0f





#define FLASH_ACR_PRFTEN (1 << 8)




#define FLASH_SR_BSY (1 << 16)
#define FLASH_SR_PGPERR (1 << 6)
#define FLASH_SR_PGAERR (1 << 5)
#define FLASH_SR_WRPERR (1 << 4)
#define FLASH_SR_OPERR (1 << 1)
#define FLASH_SR_EOP (1 << 0)



#define FLASH_CR_LOCK (1 << 31)
#define FLASH_CR_ERRIE (1 << 25)
#define FLASH_CR_EOPIE (1 << 24)
#define FLASH_CR_STRT (1 << 16)
#define FLASH_CR_MER (1 << 2)
#define FLASH_CR_SER (1 << 1)
#define FLASH_CR_PG (1 << 0)
#define FLASH_CR_SNB_SHIFT 3
#define FLASH_CR_SNB_MASK 0x1f
#define FLASH_CR_PROGRAM_MASK 0x3
#define FLASH_CR_PROGRAM_SHIFT 8




#define FLASH_CR_PROGRAM_X8 0
#define FLASH_CR_PROGRAM_X16 1
#define FLASH_CR_PROGRAM_X32 2
#define FLASH_CR_PROGRAM_X64 3






#define FLASH_OPTCR_NRST_STDBY (1 << 7)
#define FLASH_OPTCR_NRST_STOP (1 << 6)
#define FLASH_OPTCR_OPTSTRT (1 << 1)
#define FLASH_OPTCR_OPTLOCK (1 << 0)
#define FLASH_OPTCR_BOR_LEVEL_3 (0x00 << 2)
#define FLASH_OPTCR_BOR_LEVEL_2 (0x01 << 2)
#define FLASH_OPTCR_BOR_LEVEL_1 (0x02 << 2)
#define FLASH_OPTCR_BOR_OFF (0x03 << 2)







#define FLASH_KEYR_KEY1 ((uint32_t)0x45670123)
#define FLASH_KEYR_KEY2 ((uint32_t)0xcdef89ab)

#define FLASH_OPTKEYR_KEY1 ((uint32_t)0x08192a3b)
#define FLASH_OPTKEYR_KEY2 ((uint32_t)0x4c5d6e7f)





void flash_lock_option_bytes(void);
void flash_clear_pgperr_flag(void);
void flash_clear_wrperr_flag(void);
void flash_clear_pgaerr_flag(void);
void flash_erase_all_sectors(uint32_t program_size);
void flash_erase_sector(uint8_t sector, uint32_t program_size);
void flash_program_double_word(uint32_t address, uint64_t data);
void flash_program_word(uint32_t address, uint32_t data);
void flash_program_half_word(uint32_t address, uint16_t data);
void flash_program_byte(uint32_t address, uint8_t data);
void flash_program(uint32_t address, const uint8_t *data, uint32_t len);
void flash_program_option_bytes(uint32_t data);



#define FLASH_SR_PGSERR (1 << 7)
#define FLASH_OPTCR_WDG_SW (1 << 5)



void flash_clear_pgserr_flag(void);



void flash_wait_for_last_operation(void)
{
 while (((*(volatile uint32_t *)((((0x40000000U) + 0x20000) + 0x3C00) + 0x0C)) & (1 << 16)) == (1 << 16));
}







void flash_clear_pgserr_flag(void)
{
 (*(volatile uint32_t *)((((0x40000000U) + 0x20000) + 0x3C00) + 0x0C)) |= (1 << 7);
}






void flash_clear_status_flags(void)
{
 flash_clear_pgserr_flag();
 flash_clear_pgaerr_flag();
 flash_clear_wrperr_flag();
 flash_clear_pgperr_flag();
 flash_clear_eop_flag();
}
