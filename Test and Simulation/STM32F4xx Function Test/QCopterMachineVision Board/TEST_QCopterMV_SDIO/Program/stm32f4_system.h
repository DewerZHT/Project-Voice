/* #include "stm32f4_system.h" */

#include "stm32f4xx.h"
#include "stm32f4_typedef.h"
#include "stm32f4_delay.h"
//#include <math.h>

#ifndef __STM32F4_SYSTEM_H
#define __STM32F4_SYSTEM_H	
/*=====================================================================================================*/
/*=====================================================================================================*/
// I/O�ާ@�w�q
#define Bit_Band(Addr, BitNum)	((Addr & 0xF0000000)+0x2000000+((Addr &0xFFFFF)<<5)+(BitNum<<2))
#define Mem_Addr(Addr)					*((vu16 *)(Addr))
#define Bit_Addr(Addr, BitNum)	Mem_Addr(Bit_Band(Addr, BitNum))

// I/O�a�}�M�g
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

// I/O Bit�ާ@ Pin�ȥ����p��16
#define PAO(Pin)  Bit_Addr(GPIOA_ODR_Addr, Pin)  // ��X 
#define PAI(Pin)  Bit_Addr(GPIOA_IDR_Addr, Pin)  // ��J 
#define PBO(Pin)  Bit_Addr(GPIOB_ODR_Addr, Pin)  // ��X 
#define PBI(Pin)  Bit_Addr(GPIOB_IDR_Addr, Pin)  // ��J 
#define PCO(Pin)  Bit_Addr(GPIOC_ODR_Addr, Pin)  // ��X 
#define PCI(Pin)  Bit_Addr(GPIOC_IDR_Addr, Pin)  // ��J 
#define PDO(Pin)  Bit_Addr(GPIOD_ODR_Addr, Pin)  // ��X 
#define PDI(Pin)  Bit_Addr(GPIOD_IDR_Addr, Pin)  // ��J 
#define PEO(Pin)  Bit_Addr(GPIOE_ODR_Addr, Pin)  // ��X 
#define PEI(Pin)  Bit_Addr(GPIOE_IDR_Addr, Pin)  // ��J
#define PFO(Pin)  Bit_Addr(GPIOF_ODR_Addr, Pin)  // ��X 
#define PFI(Pin)  Bit_Addr(GPIOF_IDR_Addr, Pin)  // ��J	
#define PGO(Pin)  Bit_Addr(GPIOG_ODR_Addr, Pin)  // ��X 
#define PGI(Pin)  Bit_Addr(GPIOG_IDR_Addr, Pin)  // ��J
/*=====================================================================================================*/
/*=====================================================================================================*/
typedef struct {
	unsigned L:8;
	unsigned H:8;
}	HL_Struct;
/*=====================================================================================================*/
/*=====================================================================================================*/
#endif	
