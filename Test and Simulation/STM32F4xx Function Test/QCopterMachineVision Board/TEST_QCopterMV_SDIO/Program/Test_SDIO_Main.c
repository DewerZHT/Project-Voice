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
#include "stm32f4_sdio.h"

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
	
	// Show up system inf.
	RS232_SendStr(USART2, (u8*) "QCopter MV SDIO Test Demon\n\r");
	RS232_SendStr(USART2, (u8*) "--------------------------\n\r");
	
	while(SD_Init() != SD_OK) {
			
		RS232_SendStr(USART2, (u8*) "SD card initial failed...\n\r");
		
		while(1) {
			
			LED_R = ~LED_R;
			delay_100ms(1);
			while(SD_Init() == SD_OK); // wait util initial success
		
		}
		
	} // END while SD initial failed
	
	RS232_SendStr(USART2, (u8*) "SD card initial success...\n\r");
	
	while(1) {
		
	} // END while

} // END main
