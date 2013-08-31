/**
 * @File    QCopterMV_Config.h
 * @Date    2013.08.30 Firday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief   QCopter - MachineVision Board LED indicator config and access
 *
 * @Create  2013.08.30 Firday
 *
 **/ 

#ifndef __QCOPTERMV_CONFIG_H
#define __QCOPTERMV_CONFIG_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
// ST library
#include <stm32f4xx.h>

void RS232_Config( void );
void RS232_SendStr( USART_TypeDef* USARTx, unsigned char *pWord );
void RS232_VisualScope( USART_TypeDef*, u8*, u16 );
	 
#ifdef __cplusplus
	}
#endif
	 
#endif
