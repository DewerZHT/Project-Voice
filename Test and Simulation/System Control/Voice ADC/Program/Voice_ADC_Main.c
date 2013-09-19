/**
 * @File    Voice_ADC_Main.c
 * @Date    2013.09.18 Wednesday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief   Let voice wave convert to digital via ADC,
 *					then output at PC's monitor via USART and store in SD card.
 *					Use hardware - QCopter MachineVision Board
 *
 * @Create  2013.09.18 Wednesday
 *
 **/

/* Includes ------------------------------------------------------------------*/
// ST library
#include <stm32f4xx.h>

// STM32F4xx Config library
#include "stm32f4_delay.h"
#include "stm32f4_gpio.h"

// QCopter MachineVision Module
#include "QCopterMV_LED.h"
#include "QCopterMV_USART.h"
#include "QCopterMV_ADC.h"

// Data Convert
#include "StringConvert.h"

int main( void )
{
	// STM32F4 System Initial
	SystemInit();
	// QCopter MachineVision Config
	LED_Config();
	USART_Config();
	ADC_Config();

	USART_SendStr(USART2, (u8*) "Hello!\n\r");
	USART_SendStr(USART2, (u8*) "STM32F4 QCMV Voice ADC Test.\n\r");
	USART_SendStr(USART2, (u8*) "Please open VisualScope and config RS232 at COM1.\n\r");
	LED_G = ~LED_G;
	
	while( 1 ) {
		
		LED_G = ~LED_G;

	} // END while (continue convert voice wave to digital.)

} // END main