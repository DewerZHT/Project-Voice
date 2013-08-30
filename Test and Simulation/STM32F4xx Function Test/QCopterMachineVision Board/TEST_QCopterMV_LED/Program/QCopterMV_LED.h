/**
 * @File    QCopterMV_LED.h
 * @Date    2013.08.30 Firday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief   QCopter - MachineVision Board LED indicator config and access
 *
 * @Create  2013.08.30 Firday
 *
 **/ 

#ifndef __QCMV_LED_CONFIG_H
#define __QCMV_LED_CONFIG_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
// ST library
#include <stm32f4xx.h>

// General function pin parameter
#define KEY   PBI(2)
#define LED_B PCO(15)
#define LED_G PCO(14)
#define LED_R PCO(13)
		
extern void LED_Config(void);
	 
#ifdef __cplusplus
	}
#endif
	 
#endif
