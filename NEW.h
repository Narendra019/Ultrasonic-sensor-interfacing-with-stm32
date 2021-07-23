#ifndef __NEW_H
#define __NEW_H
#define     __O     volatile             /*!< Defines 'write only' permissions */
#define     __IO    volatile             /*!< Defines 'read / write' permissions */
#include <stdio.h>
void SystemInit();
void Timer2_config();
typedef struct
{
	__IO uint32_t SR;  /*Status register , Address offset 0x00 */
	__IO uint32_t DR;  /*Data Register , Address offset  0x04*/
	__IO uint32_t BRR; /*Baud rate register ,Address offset 0x08 */
	__IO uint32_t CR1; /*Control register 1,Address offset 0x0C */
	__IO uint32_t CR2; /*Control register 2,Address offset 0x10 */
	__IO uint32_t CR3; /*Control register 3,Address offset 0x14 */
	__IO uint32_t GTPR; /*Guard time and prescaler register,Address offset 0x18 */
}USART_Typedef;

typedef struct
{
  __IO uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
  __IO uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;


typedef struct
{
   __IO uint32_t CR1;   /*!<TIMX control register 1         , address offset :0x00*/
   __IO uint32_t CR2;   /*!<TIMx control register 2         , Address offset :0x04*/
   __IO uint32_t SMCR;  /*!<TIMx slave mode control register, Address offset:0x08*/
   __IO uint32_t DIER;  /*!<TIMx DMA/Interrupt enable register, Address offset:0x0c*/
   __IO uint32_t SR;    /*!<TIMx status register            ,Address offset:0x10*/
   __IO uint32_t EGR;   /*!<TIMx event generation register  ,Address offset :0x14*/
   __IO uint32_t CCMR1; /*!<TIMx capture/compare mode register 1,Address offset :0x18*/
   __IO uint32_t CCMR2; /*!<TIMx capture/compare mode register 2,Address offset :0x1C*/
   __IO uint32_t CCER;  /*!<TIMx capture/compare enable register,Address offset :0x20*/
   __IO uint32_t CNT;   /*!<TIMx counter ,address offset :0x24*/
   __IO uint32_t PSC;   /*!<TIMx prescaler,address offset:0x28 */
   __IO uint32_t ARR;   /*!<TIMx auto-reload register,address offset :0x2c*/
   __IO uint32_t RCR;   /*!<TIMx RESERVED IN THIS,address offset :0x30 */
   __IO uint32_t CCR1;  /*!<TIMx capture/compare register 1,address offset:0x34*/
   __IO uint32_t CCR2;  /*!<TIMx capture/compare register 2,address offset:0x38*/
   __IO uint32_t CCR3;  /*!<TIMx capture/compare register 3,address offset:0x3c*/
   __IO uint32_t CCR4;  /*!<TIMx capture/compare register 4,address offset:0x40*/
   __IO uint32_t RES;   /*!<RESERVED IN THIS ,address offset:0x44*/
   __IO uint32_t DCR4;  /*!<TIMx DMA control register,address offset:0x48*/
   __IO uint32_t DMAR;  /*!<TIMx DMA address for full transfer,address offset :0x4c*/
   __IO uint32_t  OR;   /*!< TIM2 option register,address offset :0x50*/
}TIM_Typedef;

typedef struct
{
  __IO uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
  __IO uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
  __IO uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
  __IO uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
  __IO uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  __IO uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
  __IO uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
  uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
  __IO uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  __IO uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
  uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
  __IO uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  __IO uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  __IO uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
  uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
  __IO uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  __IO uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  __IO uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  __IO uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  __IO uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  __IO uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  __IO uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
  __IO uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  __IO uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  __IO uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  __IO uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
  uint32_t      RESERVED7[1];  /*!< Reserved, 0x88                                                                    */
  __IO uint32_t DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */
} RCC_TypeDef;

typedef struct
{
  __IO uint32_t CR;   /*!< PWR power control register,        Address offset: 0x00 */
  __IO uint32_t CSR;  /*!< PWR power control/status register, Address offset: 0x04 */
} PWR_TypeDef;


#define PERIPH_BASE           0x40000000UL
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000UL)

#define PWR_BASE              (APB1PERIPH_BASE + 0x7000UL)
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000UL)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00UL)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800UL)

#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOH               ((GPIO_TypeDef *) GPIOH_BASE)

#define TIM2_BASE           (PERIPH_BASE +  0X0000UL)
#define TIM3_BASE           (PERIPH_BASE +  0X0400UL)
#define TIM4_BASE           (PERIPH_BASE +  0X0800UL)
#define TIM5_BASE           (PERIPH_BASE +  0X0C00UL)

#define USART1_BASE         (APB2PERIPH_BASE + 0x1000UL)

#define USART1           ((USART_Typedef*) USART1_BASE)
#define TIM2             ((TIM_Typedef*) TIM2_BASE)
#define TIM3             ((TIM_Typedef*) TIM3_BASE)
#define TIM4             ((TIM_Typedef*) TIM4_BASE)
#define TIM5             ((TIM_Typedef*) TIM5_BASE)
#define RCC              ((RCC_TypeDef *) RCC_BASE)

#define NVIC_BASE_ADDRESS       0xE000E100
#define NVIC_ISER0              NVIC_BASE_ADDRESS + 0x00

#define ACCESS(address)         *((volatile unsigned int*)(address))
#define WRITE(address, data)	*((volatile unsigned int*)(address)) = data

#define PWR                 ((PWR_TypeDef *) PWR_BASE)
#define RCC_HSEON      1U<<16
#define RCC_HSION      1U<<0
#define RCC_PWREN      1U<<28
#define RCC_HPRE       8U<<4
#define RCC_PPRE1      4U<<10
#define RCC_PPRE2      0U
#define RCC_PLLSRC     1U<<22
#define RCC_PLLON      1U<<24
#define RCC_SW         0U
#define PWR_VOS        2U<<14
#define TIM2_CC1IE     1U<<1
#define TIM2_CCIS      1U
#define TIM2_IC1PSC    0U
#define TIM2_CC1P      0U<<1/* Output polarity in Capture Compare*/
#define TIM2_CC1NP     0U<<2
#define TIM2_CC1E      1

#define USART1_CLK     1<<4  /* USART1 CLK ENABLE */
#define USART1_EN      1<<13 /* USART1 Enable */
#define USART1_RE      1<<2  /* Recieve Enable */
#define USART1_TE      1<<3  /*Transmit Enable */
#define USART1_PE      1<<10
#define USART1_ODD     1<<9
#endif
