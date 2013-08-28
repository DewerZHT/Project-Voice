/**
 * @File    UART_Test_Main.c
 * @Date    2013.08.24 Firday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief   To test uart transmit function
 *
 * @Create  2013.08.23 Firday
 *
 **/

/* Includes -----------------------------------------------------------------*/
// ST library
#include <stm32f4xx.h>

// Self library
#include "stm32f4_delay.h"
#include "stm32f4_usart.h"

uint8_t newLineCmd[] = {'\n', '\r', '\0'};

int main(void)
{
	// Test string declaration
// 	uint8_t str1[]="This is STM32F103! Hello the wonderful world! Enter a command.";
// 	uint8_t str2[]="Command is valid.";
// 	uint8_t str3[]="Command is invalid!";
	
	// Initial STM32F4 MCU System
	SystemInit();
	
	// Initial USART1
	USART1_Init();
	
	delay_100ms(5);

// 	USART_WriteString(str1);
// 	USART_WriteString(newLineCmd);
// 	
// 	delay_100ms(20);

// 	USART_WriteString(str1);
// 	USART_WriteString(newLineCmd);
	
	while(1) {
		USART_WriteByte('a');
		delay_100ms(2);
		
	} // END while
	
} // END main
