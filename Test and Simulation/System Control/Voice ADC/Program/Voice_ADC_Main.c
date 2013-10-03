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
#include "stm32f4_DELAY.h"
#include "stm32f4_GPIO.h"

// QCopter MachineVision Module
#include "stm32f4_LED.h"
#include "stm32f4_USART.h"
#include "stm32f4_ADC.h"

// Data Convert
#include "StringConvert.h"

int main( void )
{
	// Variable
	u16 ADCaverageVal[ADC_Channel] = {0};

	// STM32F4 System Initial
	SystemInit();
	// QCopter MachineVision Config
	LED_Config();
	USART_Config();
	ADC_Config();

// 	USART_SendStr(USART2, (u8*) "\n\r Hello! \n\r");
// 	USART_SendStr(USART2, (u8*) "Here is STM32F4 QCMV Voice ADC Test.\n\r");
// 	USART_SendStr(USART2, (u8*) "Please open VisualScope and config RS232 at COM1.\n\r");
	LED_G = ~LED_G;
	
	while( 1 ) {
		
		LED_G = ~LED_G;
		ADC_Average(ADCaverageVal);

// 		if(ADCaverageVal[0] > 0x00FF) {
// 		
// 			ADCaverageVal[0] = ADCaverageVal[0] & 0xFF00;
// 			
// 		} // END if ADC channel is above 1.65 V
// 		else {

// 			ADCaverageVal[0] = ADCaverageVal[0] & 0x00FF;

// 		} // END if ADC channel is below 1.65 V
		
		USART_SendStr(USART2, (u8*) "ADC value = ");
		USART_SendStr(USART2, (u8*) int2str(ADCaverageVal[0], Integer));
		USART_SendStr(USART2, (u8*) "\r");
		delay_10ms(5);

	} // END while (continue convert voice wave to digital.)

} // END main
