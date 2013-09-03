/**
 * @File    stm32f4_delay.c
 * @Date    2013.08.23 Firday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief   To test gpio function
 *
 * @Create  2013.08.23 Firday
 *
 **/

/* Includes -----------------------------------------------------------------*/
// ST library
#include <stm32f4xx.h>

// Self library
#include "stm32f4_delay.h"

#define ADC_CHANNEL_NUM 1

int main(void)
{
	// Declared ADC Initial Structure 
	ADC_InitTypeDef ADC_InitStruct;
	ADC_CommonInitTypeDef ADC_ComInitStruct;
	GPIO_InitTypeDef GPIO_InitStruct;
	
	// Set GPIO A's clock speed with AHB1
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	// Set GPIO initial structure
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	// Initial GPIO
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	// Set ADC's clock speed with APB2
	RCC_APB2PeriphClockLPModeCmd(RCC_APB2Periph_ADC, ENABLE);
	
	// Set ADC common initial structure
	ADC_ComInitStruct.ADC_Mode             = ADC_Mode_Independent; // set each adc channel independent
	ADC_ComInitStruct.ADC_Prescaler        = ADC_Prescaler_Div8;   // 
	ADC_ComInitStruct.ADC_DMAAccessMode    = ADC_DMAAccessMode_Disabled;
	ADC_ComInitStruct.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
	
	// Set ADC type initial structure
	ADC_InitStruct.ADC_Resolution           = ADC_Resolution_12b;
	ADC_InitStruct.ADC_ScanConvMode         = ENABLE;
	ADC_InitStruct.ADC_ContinuousConvMode   = ENABLE;
	ADC_InitStruct.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	ADC_InitStruct.ADC_DataAlign            = ADC_DataAlign_Right;
	ADC_InitStruct.ADC_NbrOfConversion      = ADC_CHANNEL_NUM;
	
	// Initial ADC
	ADC_CommonInit(&ADC_ComInitStruct);
	ADC_Init(ADC1, &ADC_InitStruct);
	
	while(1) {

	} // END while
	
} // END main
