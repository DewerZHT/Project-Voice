/**
 * @File    QCopterMV_LED.c
 * @Date    2013.08.30 Firday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief   QCopter - MachineVision Board LED indicator config and access
 *
 * @Create  2013.08.30 Firday
 *
 **/ 

/* Includes ------------------------------------------------------------------*/
// STM32F4xx Config library
#include "stm32f4_gpio.h"

// QCopter MachineVision Module
#include "QCopterMV_LED.h"

/******************************************************************************
 * @Function LED_Config
 * @Brief    Config LED indicator and KEY button.
 *
 **/
void LED_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

  /* LED_R PC15 */  /* LED_G PC14 */  /* LED_B PC13 */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	
	/* KEY PB2 */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOB, &GPIO_InitStruct);

  LED_G = 1;
  LED_R = 1;
  LED_B = 1;

} // END LED_Config


