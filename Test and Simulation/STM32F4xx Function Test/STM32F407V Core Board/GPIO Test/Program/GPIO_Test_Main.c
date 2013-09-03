/**
 * @File    GPIO_Test_Main.c
 * @Date    2013.08.20 Thrusday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V3
 * @Brief   To test gpio function with ST Lib sigle bit set,
 *          then access with bitband function
 *
 * @Create  2013.08.15 Thursday
 *
 **/

/* Includes ------------------------------------------------------------------*/
// ST library
#include <stm32f4xx.h>

// Self library
#include "stm32f4_delay.h"
#include "stm32f4_gpio_config.h"

// Standard C library
#include <stdlib.h>

int main(void)
{
	// Initial STM32F4 MCU System
	SystemInit();
	
	// Initial GPIO
	GPIO_InitConfig();
	
	while(1){
		
		PAO(1) = 1;
		delay_100ms(3);
		PAO(1) = 0;
		delay_100ms(3);
		
 	} // END while
	
} // END main
