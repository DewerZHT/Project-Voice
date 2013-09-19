/**
 * @File    QCopterMV_USART.c
 * @Date    2013.09.19 Thursday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V2
 * @Brief   QCopter - MachineVision Board USART config and access
 *
 * @Create  2013.08.30 Firday
 *
 **/ 

/* Includes ------------------------------------------------------------------*/
// STM32F4xx Config library
#include "stm32f4_gpio.h"

// QCopter MachineVision Module
#include "QCopterMV_USART.h"

/******************************************************************************
 * @Function USART_Config
 * @Brief    Config USART at STM32F4 USART3:
 *					 BaudRate							9600
 *           WordLength						8-bits
 *					 StopBits							1
 *					 HardwareFlowControl		None
 *					 Mode									Tx & Rx
 *
 **/
void USART_Config( void )
{
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,  ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);

 	/* USART3 Tx PA2 */	/* USART3 Rx PA3 */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);

	USART_InitStruct.USART_BaudRate = 9600;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART2, &USART_InitStruct);
	USART_Cmd(USART2, ENABLE);
	
	// initial at line one column 1
	USART_SendStr(USART2, (u8*) "\r");
	
} // END USART_Config

/******************************************************************************
 * @Function USART_SendStr
 * @Brief    Send out string util it go to end.
 *
 **/
void USART_SendStr( USART_TypeDef* USARTx, unsigned char *pWord )
{
	while(*pWord != '\0') {
		
		USART_SendData(USARTx, *pWord);
		
		// Wait transmit compelete.
		while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);
		pWord++;
	
	} // END while string end
	
} // END USART_SendStr

/******************************************************************************
 * @Function USART_VisualScope_CRC16
 * @Brief    Calculated 16-bits CRC code for PC's application VisualScope,
 *           then send it out.
 *
 **/
static u16 USART_VisualScope_CRC16( u8 *Array, u16 Len )
{
	u16 USART_IX, USART_IY, USART_CRC;

	USART_CRC = 0xffff;
	
	for(USART_IX=0; USART_IX<Len; USART_IX++) {
		
		USART_CRC = USART_CRC^(u16)(Array[USART_IX]);
		
		for(USART_IY=0; USART_IY<=7; USART_IY++) {
			
			if((USART_CRC&1)!=0)
				USART_CRC = (USART_CRC>>1)^0xA001;
			else
				USART_CRC = USART_CRC>>1;
		
		} // END for
		
	} // END for 
	
	return(USART_CRC);
	
} // END USART_VisualScope_CRC16

/******************************************************************************
 * @Function USART_VisualScope
 * @Brief    Send data to PC's application VisualScope,
 *
 **/
void USART_VisualScope( USART_TypeDef* USARTx, u8 *pWord, u16 Len )
{
	u8 i = 0;
	u16 Temp = 0;

	Temp = USART_VisualScope_CRC16(pWord, Len);
	pWord[8] = Temp&0x00ff;
	pWord[9] = (Temp&0xff00)>>8;

	for(i=0; i<10; i++) {
		
		USART_SendData(USARTx, *pWord);
		while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);
		pWord++;
		
	} // END for
	
} // END USART_VisualScope


