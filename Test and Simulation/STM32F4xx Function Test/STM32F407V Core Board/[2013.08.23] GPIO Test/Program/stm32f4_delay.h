/* #include "stm32f4_delay.h" */

/**
 * @File    stm32f4_delay.h
 * @Date    2013.08.16 Firday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief   delay funtion when STM32F4xx fosc at 168MHz
 *
 * @Create  2013.08.16 Firday
 *
 **/

#ifndef __STM32F4_DELAY_H
#define __STM32F4_DELAY_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
	 
/******************************************************************************
 * @Brief STM32F4 168MHz Time delay Function Reference
 *
 **/
extern void delay_1us  ( unsigned int delay_Times );
extern void delay_10us ( unsigned int delay_Times );
extern void delay_100us( unsigned int delay_Times );
extern void delay_1ms  ( unsigned int delay_Times );
extern void delay_10ms ( unsigned int delay_Times );
extern void delay_100ms( unsigned int delay_Times );
	 
#ifdef __cplusplus
	}
#endif
	 
#endif	 
