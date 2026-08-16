#define LIBOPENCM3_FSMC_H 

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


#define LIBOPENCM3_F4_FMC_H 





#define LIBOPENCM3_FMC_COMMON_F47_H 






#define FMC_BANK5_BASE 0xa0000000U
#define FMC_BANK6_BASE 0xb0000000U
#define FMC_BANK7_BASE 0xc0000000U
#define FMC_BANK8_BASE 0xd0000000U




#define FMC_SDCR(x) MMIO32(FSMC_BASE + 0x140 + 4 * (x))
#define FMC_SDCR1 FMC_SDCR(0)
#define FMC_SDCR2 FMC_SDCR(1)



#define FMC_SDTR(x) MMIO32(FSMC_BASE + 0x148 + 4 * (x))
#define FMC_SDTR1 FMC_SDTR(0)
#define FMC_SDTR2 FMC_SDTR(1)


#define FMC_SDCMR MMIO32(FSMC_BASE + (uint32_t) 0x150)


#define FMC_SDRTR MMIO32(FSMC_BASE + 0x154)


#define FMC_SDSR MMIO32(FSMC_BASE + (uint32_t) 0x158)






#define FMC_SDCR_RPIPE_SHIFT 13
#define FMC_SDCR_RPIPE_MASK (3 << FMC_SDCR_RPIPE_SHIFT)
#define FMC_SDCR_RPIPE_NONE (0 << FMC_SDCR_RPIPE_SHIFT)
#define FMC_SDCR_RPIPE_1CLK (1 << FMC_SDCR_RPIPE_SHIFT)
#define FMC_SDCR_RPIPE_2CLK (2 << FMC_SDCR_RPIPE_SHIFT)


#define FMC_SDCR_RBURST (1 << 12)


#define FMC_SDCR_SDCLK_SHIFT 10
#define FMC_SDCR_SDCLK_MASK (3 << FMC_SDCR_SDCLK_SHIFT)
#define FMC_SDCR_SDCLK_DISABLE (0 << FMC_SDCR_SDCLK_SHIFT)
#define FMC_SDCR_SDCLK_2HCLK (2 << FMC_SDCR_SDCLK_SHIFT)
#define FMC_SDCR_SDCLK_3HCLK (3 << FMC_SDCR_SDCLK_SHIFT)


#define FMC_SDCR_WP_ENABLE (1 << 9)


#define FMC_SDCR_CAS_SHIFT 7
#define FMC_SDCR_CAS_1CYC (1 << FMC_SDCR_CAS_SHIFT)
#define FMC_SDCR_CAS_2CYC (2 << FMC_SDCR_CAS_SHIFT)
#define FMC_SDCR_CAS_3CYC (3 << FMC_SDCR_CAS_SHIFT)


#define FMC_SDCR_NB2 0
#define FMC_SDCR_NB4 (1 << 6)


#define FMC_SDCR_MWID_SHIFT 4
#define FMC_SDCR_MWID_8b (0 << FMC_SDCR_MWID_SHIFT)
#define FMC_SDCR_MWID_16b (1 << FMC_SDCR_MWID_SHIFT)
#define FMC_SDCR_MWID_32b (2 << FMC_SDCR_MWID_SHIFT)


#define FMC_SDCR_NR_SHIFT 2
#define FMC_SDCR_NR_11 (0 << FMC_SDCR_NR_SHIFT)
#define FMC_SDCR_NR_12 (1 << FMC_SDCR_NR_SHIFT)
#define FMC_SDCR_NR_13 (2 << FMC_SDCR_NR_SHIFT)


#define FMC_SDCR_NC_SHIFT 0
#define FMC_SDCR_NC_8 (0 << FMC_SDCR_NC_SHIFT)
#define FMC_SDCR_NC_9 (1 << FMC_SDCR_NC_SHIFT)
#define FMC_SDCR_NC_10 (2 << FMC_SDCR_NC_SHIFT)
#define FMC_SDCR_NC_11 (3 << FMC_SDCR_NC_SHIFT)






#define FMC_SDTR_TRCD_SHIFT 24
#define FMC_SDTR_TRCD_MASK (15 << FMC_SDTR_TRCD_SHIFT)


#define FMC_SDTR_TRP_SHIFT 20
#define FMC_SDTR_TRP_MASK (15 << FMC_SDTR_TRP_SHIFT)


#define FMC_SDTR_TWR_SHIFT 16
#define FMC_SDTR_TWR_MASK (15 << FMC_SDTR_TWR_SHIFT)


#define FMC_SDTR_TRC_SHIFT 12
#define FMC_SDTR_TRC_MASK (15 << FMC_SDTR_TRC_SHIFT)


#define FMC_SDTR_TRAS_SHIFT 8
#define FMC_SDTR_TRAS_MASK (15 << FMC_SDTR_TRAS_SHIFT)


#define FMC_SDTR_TXSR_SHIFT 4
#define FMC_SDTR_TXSR_MASK (15 << FMC_SDTR_TXSR_SHIFT)


#define FMC_SDTR_TMRD_SHIFT 0
#define FMC_SDTR_TMRD_MASK (15 << FMC_SDTR_TMRD_SHIFT)







#define FMC_SDTR_DNC_MASK (FMC_SDTR_TRP_MASK | FMC_SDTR_TRC_MASK)
#define FMC_SDCR_DNC_MASK (FMC_SDCR_SDCLK_MASK | FMC_SDCR_RPIPE_MASK | FMC_SDCR_RBURST)
#define FMC_SDCMR_MRD_SHIFT 9
#define FMC_SDCMR_MRD_MASK (0x1fff << FMC_SDCMR_MRD_SHIFT)


#define FMC_SDCMR_NRFS_SHIFT 5
#define FMC_SDCMR_NRFS_MASK (15 << FMC_SDCMR_NRFS_SHIFT)


#define FMC_SDCMR_CTB1 (1 << 4)


#define FMC_SDCMR_CTB2 (1 << 3)


#define FMC_SDCMR_MODE_SHIFT 0
#define FMC_SDCMR_MODE_MASK 7
#define FMC_SDCMR_MODE_NORMAL 0
#define FMC_SDCMR_MODE_CLOCK_CONFIG_ENA 1
#define FMC_SDCMR_MODE_PALL 2
#define FMC_SDCMR_MODE_AUTO_REFRESH 3
#define FMC_SDCMR_MODE_LOAD_MODE_REGISTER 4
#define FMC_SDCMR_MODE_SELF_REFRESH 5
#define FMC_SDCMR_MODE_POWER_DOWN 6






#define FMC_SDRTR_REIE (1 << 14)


#define FMC_SDRTR_COUNT_SHIFT 1
#define FMC_SDRTR_COUNT_MASK (0x1fff << FMC_SDRTR_COUNT_SHIFT)


#define FMC_SDRTR_CRE (1 << 0)






#define FMC_SDSR_BUSY (1 << 5)


#define FMC_SDSR_MODE_NORMAL 0
#define FMC_SDSR_MODE_SELF_REFRESH 1
#define FMC_SDSR_MODE_POWER_DOWN 2


#define FMC_SDSR_MODE2_SHIFT 3
#define FMC_SDSR_MODE1_SHIFT 1


#define FMC_SDSR_RE (1 << 0)



struct sdram_timing {
 int trcd;
 int trp;
 int twr;
 int trc;
 int tras;
 int txsr;
 int tmrd;
};


#define SDRAM_MODE_BURST_LENGTH_1 ((uint16_t)0x0000)
#define SDRAM_MODE_BURST_LENGTH_2 ((uint16_t)0x0001)
#define SDRAM_MODE_BURST_LENGTH_4 ((uint16_t)0x0002)
#define SDRAM_MODE_BURST_LENGTH_8 ((uint16_t)0x0004)
#define SDRAM_MODE_BURST_TYPE_SEQUENTIAL ((uint16_t)0x0000)
#define SDRAM_MODE_BURST_TYPE_INTERLEAVED ((uint16_t)0x0008)
#define SDRAM_MODE_CAS_LATENCY_2 ((uint16_t)0x0020)
#define SDRAM_MODE_CAS_LATENCY_3 ((uint16_t)0x0030)
#define SDRAM_MODE_OPERATING_MODE_STANDARD ((uint16_t)0x0000)
#define SDRAM_MODE_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
#define SDRAM_MODE_WRITEBURST_MODE_SINGLE ((uint16_t)0x0200)

enum fmc_sdram_bank { SDRAM_BANK1, SDRAM_BANK2, SDRAM_BOTH_BANKS };
enum fmc_sdram_command { SDRAM_CLK_CONF, SDRAM_NORMAL, SDRAM_PALL,
    SDRAM_AUTO_REFRESH, SDRAM_LOAD_MODE,
    SDRAM_SELF_REFRESH, SDRAM_POWER_DOWN };






uint32_t sdram_timing(struct sdram_timing *t);
void sdram_command(enum fmc_sdram_bank bank, enum fmc_sdram_command cmd,
   int autorefresh, int modereg);









#define FSMC_BANK1_BASE 0x60000000U
#define FSMC_BANK2_BASE 0x70000000U
#define FSMC_BANK3_BASE 0x80000000U
#define FSMC_BANK4_BASE 0x90000000U




#define FSMC_BCR(x) MMIO32(FSMC_BASE + 0x00 + 8 * (x))
#define FSMC_BCR1 FSMC_BCR(0)
#define FSMC_BCR2 FSMC_BCR(1)
#define FSMC_BCR3 FSMC_BCR(2)
#define FSMC_BCR4 FSMC_BCR(3)


#define FSMC_BTR(x) MMIO32(FSMC_BASE + 0x04 + 8 * (x))
#define FSMC_BTR1 FSMC_BTR(0)
#define FSMC_BTR2 FSMC_BTR(1)
#define FSMC_BTR3 FSMC_BTR(2)
#define FSMC_BTR4 FSMC_BTR(3)


#define FSMC_BWTR(x) MMIO32(FSMC_BASE + 0x104 + 8 * (x))
#define FSMC_BWTR1 FSMC_BWTR(0)
#define FSMC_BWTR2 FSMC_BWTR(1)
#define FSMC_BWTR3 FSMC_BWTR(2)
#define FSMC_BWTR4 FSMC_BWTR(3)


#define FSMC_PCR(x) MMIO32(FSMC_BASE + 0x40 + 0x20 * (x))
#define FSMC_PCR2 FSMC_PCR(1)
#define FSMC_PCR3 FSMC_PCR(2)
#define FSMC_PCR4 FSMC_PCR(3)


#define FSMC_SR(x) MMIO32(FSMC_BASE + 0x44 + 0x20 * (x))
#define FSMC_SR2 FSMC_SR(1)
#define FSMC_SR3 FSMC_SR(2)
#define FSMC_SR4 FSMC_SR(3)


#define FSMC_PMEM(x) MMIO32(FSMC_BASE + 0x48 + 0x20 * (x))
#define FSMC_PMEM2 FSMC_PMEM(1)
#define FSMC_PMEM3 FSMC_PMEM(2)
#define FSMC_PMEM4 FSMC_PMEM(3)


#define FSMC_PATT(x) MMIO32(FSMC_BASE + 0x4c + 0x20 * (x))
#define FSMC_PATT2 FSMC_PATT(1)
#define FSMC_PATT3 FSMC_PATT(2)
#define FSMC_PATT4 FSMC_PATT(3)


#define FSMC_PIO4 MMIO32(FSMC_BASE + 0xb0)


#define FSMC_ECCR(x) MMIO32(FSMC_BASE + 0x54 + 0x20 * (x))
#define FSMC_ECCR2 FSMC_ECCR(1)
#define FSMC_ECCR3 FSMC_ECCR(2)






#define FSMC_BCR_CBURSTRW (1 << 19)




#define FSMC_BCR_ASYNCWAIT (1 << 15)


#define FSMC_BCR_EXTMOD (1 << 14)


#define FSMC_BCR_WAITEN (1 << 13)


#define FSMC_BCR_WREN (1 << 12)


#define FSMC_BCR_WAITCFG (1 << 11)


#define FSMC_BCR_WRAPMOD (1 << 10)


#define FSMC_BCR_WAITPOL (1 << 9)


#define FSMC_BCR_BURSTEN (1 << 8)




#define FSMC_BCR_FACCEN (1 << 6)


#define FSMC_BCR_MWID (1 << 4)


#define FSMC_BCR_MTYP (1 << 2)


#define FSMC_BCR_MUXEN (1 << 1)


#define FSMC_BCR_MBKEN (1 << 0)






#define FSMC_BTx_ACCMOD_A (0)
#define FSMC_BTx_ACCMOD_B (1)
#define FSMC_BTx_ACCMOD_C (2)
#define FSMC_BTx_ACCMOD_D (3)


#define FSMC_BTR_ACCMOD (1 << 28)
#define FSMC_BTR_ACCMODx(x) (((x) & 0x03) << 28)


#define FSMC_BTR_DATLAT (1 << 24)
#define FSMC_BTR_DATLATx(x) (((x) & 0x0f) << 24)


#define FSMC_BTR_CLKDIV (1 << 20)
#define FSMC_BTR_CLKDIVx(x) (((x) & 0x0f) << 20)


#define FSMC_BTR_BUSTURN (1 << 16)
#define FSMC_BTR_BUSTURNx(x) (((x) & 0x0f) << 16)


#define FSMC_BTR_DATAST (1 << 8)
#define FSMC_BTR_DATASTx(x) (((x) & 0xff) << 8)


#define FSMC_BTR_ADDHLD (1 << 4)
#define FSMC_BTR_ADDHLDx(x) (((x) & 0x0f) << 4)


#define FSMC_BTR_ADDSET (1 << 0)
#define FSMC_BTR_ADDSETx(x) (((x) & 0x0f) << 0)






#define FSMC_BWTR_ACCMOD (1 << 28)


#define FSMC_BWTR_DATLAT (1 << 24)


#define FSMC_BWTR_CLKDIV (1 << 20)




#define FSMC_BWTR_DATAST (1 << 8)


#define FSMC_BWTR_ADDHLD (1 << 4)


#define FSMC_BWTR_ADDSET (1 << 0)






#define FSMC_PCR_ECCPS (1 << 17)


#define FSMC_PCR_TAR (1 << 13)


#define FSMC_PCR_TCLR (1 << 9)




#define FSMC_PCR_ECCEN (1 << 6)


#define FSMC_PCR_PWID (1 << 4)


#define FSMC_PCR_PTYP (1 << 3)


#define FSMC_PCR_PBKEN (1 << 2)


#define FSMC_PCR_PWAITEN (1 << 1)
#define FSMC_SR_FEMPT (1 << 6)


#define FSMC_SR_IFEN (1 << 5)


#define FSMC_SR_ILEN (1 << 4)


#define FSMC_SR_IREN (1 << 3)


#define FSMC_SR_IFS (1 << 2)


#define FSMC_SR_ILS (1 << 1)


#define FSMC_SR_IRS (1 << 0)




#define FSMC_PMEM_MEMHIZX (1 << 24)


#define FSMC_PMEM_MEMHOLDX (1 << 16)


#define FSMC_PMEM_MEMWAITX (1 << 8)


#define FSMC_PMEM_MEMSETX (1 << 0)




#define FSMC_PATT_ATTHIZX (1 << 24)


#define FSMC_PATT_ATTHOLDX (1 << 16)


#define FSMC_PATT_ATTWAITX (1 << 8)


#define FSMC_PATT_ATTSETX (1 << 0)




#define FSMC_PIO4_IOHIZX (1 << 24)


#define FSMC_PIO4_IOHOLDX (1 << 16)


#define FSMC_PIO4_IOWAITX (1 << 8)


#define FSMC_PIO4_IOSETX (1 << 0)




#define FSMC_ECCR_ECCX (1 << 0)
uint32_t
sdram_timing(struct sdram_timing *t) {
 uint32_t result;

 result = 0;
 result |= ((t->trcd - 1) & 0xf) << 24;
 result |= ((t->trp - 1) & 0xf) << 20;
 result |= ((t->twr - 1) & 0xf) << 16;
 result |= ((t->trc - 1) & 0xf) << 12;
 result |= ((t->tras - 1) & 0xf) << 8;
 result |= ((t->txsr - 1) & 0xf) << 4;
 result |= ((t->tmrd - 1) & 0xf) << 0;
 return result;
}






void
sdram_command(enum fmc_sdram_bank bank,
       enum fmc_sdram_command cmd, int autorefresh, int modereg) {
 uint32_t tmp_reg = 0;

 switch (bank) {
 case SDRAM_BANK1:
  tmp_reg = (1 << 4);
  break;
 case SDRAM_BANK2:
  tmp_reg = (1 << 3);
  break;
 case SDRAM_BOTH_BANKS:
  tmp_reg = (1 << 4) | (1 << 3);
  break;
 }
 tmp_reg |= autorefresh << 5;
 tmp_reg |= modereg << 9;
 switch (cmd) {
 case SDRAM_CLK_CONF:
  tmp_reg |= 1;
  break;
 case SDRAM_AUTO_REFRESH:
  tmp_reg |= 3;
  break;
 case SDRAM_LOAD_MODE:
  tmp_reg |= 4;
  break;
 case SDRAM_PALL:
  tmp_reg |= 2;
  break;
 case SDRAM_SELF_REFRESH:
  tmp_reg |= 5;
  break;
 case SDRAM_POWER_DOWN:
  tmp_reg |= 6;
  break;
 case SDRAM_NORMAL:
 default:
  break;
 }


 while ((*(volatile uint32_t *)((0x60000000U + 0x40000000U) + (uint32_t) 0x158)) & (1 << 5));


 (*(volatile uint32_t *)((0x60000000U + 0x40000000U) + (uint32_t) 0x150)) = tmp_reg;
}
