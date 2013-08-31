/**
 * @File    Test_UART_Main.c
 * @Date    2013.08.30 Firday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V3
 * @Brief   To test UART on QCopter - MachineVision Board,
 *          just send data out.
 *
 * @Create  2013.08.30 Firday
 *
 **/

/* Includes ------------------------------------------------------------------*/
// ST library
#include <stm32f4xx.h>

// STM32F4xx Config library
#include "stm32f4_gpio.h"

// QCopter MachineVision Module
#include "QCopterMV_LED.h"
#include "QCopterMV_RS232.h"

int main(void)
{
	// STM32F4 System Initial
	SystemInit();
	// QCopter MachineVision Config
	LED_Config();
	// QCopter MachineVision Config
	RS232_Config();
	
	RS232_SendStr(USART3, "Hello !\n\r");
	RS232_SendStr(USART3, "STM32F4 QCMV UART Test.\n\r");
	LED_G = ~LED_G;

	while(1) {
		

		
	} // END while

} // END main
