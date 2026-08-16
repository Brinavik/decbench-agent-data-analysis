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
void gpio_mode_setup(uint32_t gpioport, uint8_t mode, uint8_t pull_up_down,
       uint16_t gpios)
{
 uint16_t i;
 uint32_t moder, pupd;





 moder = (*(volatile uint32_t *)((gpioport) + 0x00));
 pupd = (*(volatile uint32_t *)((gpioport) + 0x0c));

 for (i = 0; i < 16; i++) {
  if (!((1 << i) & gpios)) {
   continue;
  }

  moder &= ~(0x3 << (2 * (i)));
  moder |= ((mode) << (2 * (i)));
  pupd &= ~(0x3 << (2 * (i)));
  pupd |= ((pull_up_down) << (2 * (i)));
 }


 (*(volatile uint32_t *)((gpioport) + 0x00)) = moder;
 (*(volatile uint32_t *)((gpioport) + 0x0c)) = pupd;
}
void gpio_set_output_options(uint32_t gpioport, uint8_t otype, uint8_t speed,
        uint16_t gpios)
{
 uint16_t i;
 uint32_t ospeedr;

 if (otype == 0x1) {
  (*(volatile uint32_t *)((gpioport) + 0x04)) |= gpios;
 } else {
  (*(volatile uint32_t *)((gpioport) + 0x04)) &= ~gpios;
 }

 ospeedr = (*(volatile uint32_t *)((gpioport) + 0x08));

 for (i = 0; i < 16; i++) {
  if (!((1 << i) & gpios)) {
   continue;
  }
  ospeedr &= ~(0x3 << (2 * (i)));
  ospeedr |= ((speed) << (2 * (i)));
 }

 (*(volatile uint32_t *)((gpioport) + 0x08)) = ospeedr;
}
void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint16_t gpios)
{
 uint16_t i;
 uint32_t afrl, afrh;

 afrl = (*(volatile uint32_t *)((gpioport) + 0x20));
 afrh = (*(volatile uint32_t *)((gpioport) + 0x24));

 for (i = 0; i < 8; i++) {
  if (!((1 << i) & gpios)) {
   continue;
  }
  afrl &= ~(0xf << ((i) * 4));
  afrl |= ((alt_func_num) << ((i) * 4));
 }

 for (i = 8; i < 16; i++) {
  if (!((1 << i) & gpios)) {
   continue;
  }
  afrh &= ~(0xf << ((i - 8) * 4));
  afrh |= ((alt_func_num) << ((i - 8) * 4));
 }

 (*(volatile uint32_t *)((gpioport) + 0x20)) = afrl;
 (*(volatile uint32_t *)((gpioport) + 0x24)) = afrh;
}
