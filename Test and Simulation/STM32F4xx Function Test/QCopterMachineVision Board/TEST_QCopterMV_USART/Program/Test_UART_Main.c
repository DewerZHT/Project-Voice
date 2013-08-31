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
	
	while(1) {
		
		
		
	} // END while

} // END main
