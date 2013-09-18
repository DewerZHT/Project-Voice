/**
 * @File    QCopterMV_RS232.h
 * @Date    2013.08.30 Firday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief   QCopter - MachineVision Board RS232 config and access
 *
 * @Create  2013.08.30 Firday
 *
 **/ 

#ifndef __QCOPTERMV_RS232_H
#define __QCOPTERMV_RS232_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
// ST library
#include <stm32f4xx.h>

/* Function declaration ------------------------------------------------------*/
void RS232_Config( void );
void RS232_SendStr( USART_TypeDef* USARTx, unsigned char *pWord );
void RS232_VisualScope( USART_TypeDef*, u8*, u16 );
	 
#ifdef __cplusplus
	}
#endif
	 
#endif
