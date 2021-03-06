/**
 * @File    Test_UART_Main.c
 * @Date    2013.09.03 Tuesday
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
#include "stm32f4_delay.h"
#include "stm32f4_gpio.h"

// Standard C Library
#include "stdlib.h"

// QCopter MachineVision Module
#include "QCopterMV_LED.h"
#include "QCopterMV_RS232.h"

// Data Convert
#include "StringConvert.h"

int main(void)
{
	unsigned int CNT = 0;
	u8* ReceBuf = {0};
	
	// STM32F4 System Initial
	SystemInit();
	// QCopter MachineVision Config
	LED_Config();
	// QCopter MachineVision Config
	RS232_Config();
	
	RS232_SendStr(USART2, (u8*) "Hello!\n\r");
	RS232_SendStr(USART2, (u8*) "STM32F4 QCMV UART Test.\n\r");
	LED_G = ~LED_G;

	while(1) {
		LED_G = ~LED_G;
		
		do {
			
			ReceBuf = RS232_ReceStr(USART2);
			
		} while(IS_USART_CLEAR_FLAG(USART_FLAG_RXNE)); // END while receive data from RS232
		
		RS232_SendStr(USART2, ReceBuf);
		
	} // END while

} // END main
