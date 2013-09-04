/**
 * @File    Test_SDIO_Main.c
 * @Date    2013.09.04 Tuesday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V3
 * @Brief   To test SDIO on QCopter - MachineVision Board,
 *
 * @Create  2013.09.03 Tuesday
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
#include "QCopterMV_RS232.h"

// Data Convert
#include "StringConvert.h"

int main(void)
{
	// System Initialize
	SystemInit();
	// QCopterMV Initialize
	LED_Config();
	RS232_Config();
	
	while(1) {

	} // END while

} // END main
