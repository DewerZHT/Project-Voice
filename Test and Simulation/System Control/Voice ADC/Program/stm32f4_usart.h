/**
 * @File    QCopterMV_USART.h
 * @Date    2013.09.19 Thursday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V2
 * @Brief   QCopter - MachineVision Board RS232 config and access
 *
 * @Create  2013.08.30 Firday
 *
 **/ 

#ifndef __QCOPTERMV_USART_H
#define __QCOPTERMV_USART_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
// ST library
#include <stm32f4xx.h>

/* Function declaration ------------------------------------------------------*/
void USART_Config( void );
void USART_SendStr( USART_TypeDef* USARTx, unsigned char *pWord );
void USART_VisualScope( USART_TypeDef*, u8*, u16 );
	 
#ifdef __cplusplus
	}
#endif
	 
#endif
