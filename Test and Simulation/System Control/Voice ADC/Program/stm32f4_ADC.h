/**
 * @File    QCopterMV_ADC.h
 * @Date    2013.09.12 Thursday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief   QCopter - MachineVision Board ADC Periphral Config
 *
 * @Create  2013.09.12 Thursday
 *
 **/ 

#ifndef QCOPTERMV_ADC_H
#define QCOPTERMV_ADC_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
// ST library
#include <stm32f4xx.h>

/* Parameters ----------------------------------------------------------------*/
#define ADC1_DR_ADDRESS	((u32)0x4001204C)
#define ADC2_DR_ADDRESS	((u32)0x4001214C)
#define ADC3_DR_ADDRESS	((u32)0x4001224C)

#define ADC_Channel		1
#define ADC_Sample		32
		
/* Function declaration ------------------------------------------------------*/
void ADC_Config( void );
void ADC_Average( u16* pADC_AveTr );
	 
#ifdef __cplusplus
	}
#endif
	 
#endif
