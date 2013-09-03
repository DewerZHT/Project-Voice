/**
 * @File    stm32f4_usart.h
 * @Date    2013.08.24 Saturday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief   
 *
 * @Create  2013.08.24 Saturday
 *
 **/
 
#ifndef __STM32F4_USART_H
#define __STM32F4_USART_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

// Define data type parameters
#define BUF_SIZE 100

extern unsigned char USART_RxStr[BUF_SIZE];
extern unsigned char USART_TxStr[BUF_SIZE];
		
void USART1_Init(void);
void USART_WriteByte(const unsigned char DWord);
unsigned char USART_ReceiveByte(void);
void USART_WriteString(const unsigned char* TxStr);
	 
#ifdef __cplusplus
	}
#endif
	 
#endif	
