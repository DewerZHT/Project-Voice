/**
 * @File    stm32f4_gpio_config.c
 * @Date    2013.08.20 Tuseday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief   
 *
 * @Create  2013.08.20 Tuseday
 *
 **/
 
/* Includes ------------------------------------------------------------------*/
#include "stm32f4_gpio_config.h"

// Standard C library
#include <stdlib.h>

void GPIO_InitConfig(void)
{
	// Set GPIO A Initial Structure
	GPIO_InitTypeDef GPIOA_InitStruct;
	
	// Set GPIO A Periphral Clock with AHB1
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	
	// Config GPIOA_InitStruct parameter
	GPIOA_InitStruct.GPIO_Pin   = GPIO_Pin_0 | GPIO_Pin_1;
	GPIOA_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIOA_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIOA_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIOA_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	
	// Initial GPIO A
	GPIO_Init(GPIOA, &GPIOA_InitStruct);
	
	// release GPIOA_InitStruct
	free(&GPIOA_InitStruct);
	
} // END GPIO_InitConfig
