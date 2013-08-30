/**
 * @File    Test_LED_Main.c
 * @Date    2013.08.30 Firday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief   To test LED on QCopter - MachineVision Board,
 *          with key button control.
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

// QCopter MachineVision Module
#include "QCopterMV_LED.h"

int main(void)
{
	// Initial STM32F4 MCU System
	SystemInit();
	
	// Initial QCopterMV LED indicator
	LED_Config();
	
	while(1) {
		
		LED_R = 0;
		LED_G = 1;
		LED_B = 1;
		delay_10ms(15);
		LED_R = 1;
		LED_G = 0;
		LED_B = 1;
		delay_10ms(15);
		LED_R = 1;
		LED_G = 1;
		LED_B = 0;
		delay_10ms(15);
		
		while(KEY) {
			
			LED_R = 0;
			LED_G = 0;
			LED_B = 0;
			delay_100ms(2);
			LED_R = 1;
			LED_G = 1;
			LED_B = 1;
			delay_100ms(2);
			
		} // END while KEY pressed
		
	} // END while

} // END main
