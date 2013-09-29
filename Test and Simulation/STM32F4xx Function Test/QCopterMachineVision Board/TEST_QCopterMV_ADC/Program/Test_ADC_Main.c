/**
 * @File    Test_ADC_Main.c
 * @Date    2013.09.12 Thursday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V3
 * @Brief   To test ADC on QCopter - MachineVision Board,
 *          just send data out to PC via UART.
 *
 * @Create  2013.09.12 Thursday
 *
 **/

/* Includes ------------------------------------------------------------------*/
// ST library
#include <stm32f4xx.h>

// STM32F4xx Config library
#include "stm32f4_delay.h"
#include "stm32f4_gpio.h"

// Standard C Library
#include "stdlib.h"

// QCopter MachineVision Module
#include "QCopterMV_LED.h"
#include "QCopterMV_RS232.h"
#include "QCopterMV_ADC.h"

// Data Convert Library
#include "StringConvert.h"

int main( void )
{
	// Variable
	u16 ADCaverageVal[ADC_Channel] = {0};
	
	// STM32F4 System Initial
	SystemInit();
	// QCopter MachineVision Config
	LED_Config();
	RS232_Config();
	ADC_Config();

	RS232_SendStr(USART2, (u8*) "Hello!\n\r");
	RS232_SendStr(USART2, (u8*) "STM32F4 QCMV ADC Test.\n\r");
	LED_G = ~LED_G;
	
	while(1) {
		
		LED_G = ~LED_G;
		ADC_Average(ADCaverageVal);
		ADCaverageVal[0] = (int) (ADCaverageVal[0] / 2047) * 65535;
		RS232_SendStr(USART2, (u8*) "ADC value = ");
		RS232_SendStr(USART2, (u8*) int2str(ADCaverageVal[0], Integer));
		RS232_SendStr(USART2, (u8*) "\n\r");
		delay_100ms(1);
		
	} // END while

} // END main
