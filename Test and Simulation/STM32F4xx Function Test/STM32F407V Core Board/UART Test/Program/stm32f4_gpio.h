/**
 * @File    stm32f4_gpio.h
 * @Date    2013.08.20 Tuseday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief   
 *
 * @Create  2013.08.20 Tuseday
 *
 **/
 
#ifndef __STM32F4_GPIO_H
#define __STM32F4_GPIO_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/******************************************************************************
 * @Brief	 Definition STM32F4 GPIO Bit Band
 * @Note   This parameter definition is meant to shortcut the statment when you
 *		     have to access single bit in GPIO.
 *
 **/
#define Bit_Band(Addr, BitNum)  ((Addr & 0xF0000000)+0x2000000+((Addr &0xFFFFF)<<5)+(BitNum<<2))
#define Mem_Addr(Addr)          *((vu16 *)(Addr))
#define Bit_Addr(Addr, BitNum)  Mem_Addr(Bit_Band(Addr, BitNum))

#define GPIOA_ODR_Addr  (GPIOA_BASE+0x14)
#define GPIOB_ODR_Addr  (GPIOB_BASE+0x14)
#define GPIOC_ODR_Addr  (GPIOC_BASE+0x14)
#define GPIOD_ODR_Addr  (GPIOD_BASE+0x14)
#define GPIOE_ODR_Addr  (GPIOE_BASE+0x14)
#define GPIOF_ODR_Addr  (GPIOF_BASE+0x14)
#define GPIOG_ODR_Addr  (GPIOG_BASE+0x14)
#define GPIOA_IDR_Addr  (GPIOA_BASE+0x10)
#define GPIOB_IDR_Addr  (GPIOB_BASE+0x10)
#define GPIOC_IDR_Addr  (GPIOC_BASE+0x10)
#define GPIOD_IDR_Addr  (GPIOD_BASE+0x10)
#define GPIOE_IDR_Addr  (GPIOE_BASE+0x10)
#define GPIOF_IDR_Addr  (GPIOF_BASE+0x10)
#define GPIOG_IDR_Addr  (GPIOG_BASE+0x10)

#define PAO(Pin)  Bit_Addr(GPIOA_ODR_Addr, Pin) // GPIO Port A output
#define PAI(Pin)  Bit_Addr(GPIOA_IDR_Addr, Pin) // GPIO Port A input
#define PBO(Pin)  Bit_Addr(GPIOB_ODR_Addr, Pin) // GPIO Port B output
#define PBI(Pin)  Bit_Addr(GPIOB_IDR_Addr, Pin) // GPIO Port B input
#define PCO(Pin)  Bit_Addr(GPIOC_ODR_Addr, Pin) // GPIO Port C output
#define PCI(Pin)  Bit_Addr(GPIOC_IDR_Addr, Pin) // GPIO Port C input
#define PDO(Pin)  Bit_Addr(GPIOD_ODR_Addr, Pin) // GPIO Port D output
#define PDI(Pin)  Bit_Addr(GPIOD_IDR_Addr, Pin) // GPIO Port D input
#define PEO(Pin)  Bit_Addr(GPIOE_ODR_Addr, Pin) // GPIO Port E output
#define PEI(Pin)  Bit_Addr(GPIOE_IDR_Addr, Pin) // GPIO Port E input
#define PFO(Pin)  Bit_Addr(GPIOF_ODR_Addr, Pin) // GPIO Port F output
#define PFI(Pin)  Bit_Addr(GPIOF_IDR_Addr, Pin) // GPIO Port F input
#define PGO(Pin)  Bit_Addr(GPIOG_ODR_Addr, Pin) // GPIO Port G output
#define PGI(Pin)  Bit_Addr(GPIOG_IDR_Addr, Pin) // GPIO Port G input

extern void GPIO_InitConfig(void);
	 
#ifdef __cplusplus
	}
#endif
	 
#endif	
