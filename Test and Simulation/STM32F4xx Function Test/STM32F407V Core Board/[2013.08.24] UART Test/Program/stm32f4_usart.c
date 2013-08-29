/**
 * @File    stm32f4_usart.c
 * @Date    2013.08.24 Saturday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief   
 *
 * @Create  2013.08.24 Saturday
 *
 **/
 
/* Includes ------------------------------------------------------------------*/
#include "stm32f4_usart.h"

unsigned char USART_RxStr[BUF_SIZE];
unsigned char USART_TxStr[BUF_SIZE];

void USART1_Init(void)
{
	// Declaration GPIO Initial Structure for USART1 usage.
	GPIO_InitTypeDef GPIO_InitStruct;
	// Declaration USART Initial Structure for USART Init config.
	USART_InitTypeDef USART_InitStructure;
	
	// Enable clock source for GPIOA, USART1 on APB2
	RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);
	
	// GPIO Config. for USART1 TX(PA9) to Alternate function Mode with Push-Pull.
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	
	// GPIO Init for USART1 TX(PA9) Config.
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	// GPIO Config. for USART1 RX(PA10) to Input Floating without Pull up and Pull down.
	GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	// GPIO Init for USART1 RX(PA10) Config.
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
  // Config USART parameters.
  USART_InitStructure.USART_BaudRate = 9600;		//Fpclk2=72MHz will be more accurate.
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  
  // Init USART1 Peripheral.
  USART_Init(USART1,&USART_InitStructure);
  
  // Enable USART1 Peripheral.
  USART_Cmd(USART1,ENABLE);
	
	// Clear TC after Init(Or the fist data could be lost).
	// Seems to be TC not RESET to 0 after Enabled. Gotta check.
	USART_ClearFlag(USART1,USART_FLAG_TC);
	
} // END USART1_Init

void USART_WriteByte(const unsigned char DWord)
{
	// Send the 8bit word.
	USART_SendData(USART1, DWord);
	
	// Wait until TC(Transmission Complete flag) is SET(Completed).
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) != SET);
	
	// Clear TC instantly.
	USART_ClearFlag(USART1,USART_FLAG_TC);
	
} // END USART_WriteByte

unsigned char USART_ReceiveByte(void)
{
  // To in case of the pre-occured Overrun that wasn't cleared. This sequence will clear the ORE.
	// 1. Make a read to SR reg.
	USART_GetFlagStatus(USART1,USART_FLAG_ORE);
	
	// 2. followed by a read of DR. Also, it will automatically clear RXNE.
	USART_ReceiveData(USART1);
	
	// Wait until RXNE is SET(Data received in DR reg).
	while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)!=SET);
	
	// Get the received data and automatically clear RXNE.
	return USART_ReceiveData(USART1);

} // END USART_ReadByte

void USART_WriteString(const unsigned char* TxStr)
{
	// Declaration variable for shift counter.(256 words limit).
	unsigned char s;
	
	//send the words until the end of line '\0'.(You can modify this function to meet 256 limit).
	for(s = 0; TxStr[s] != '\0'; s++) {
		
		USART_WriteByte(TxStr[s]);
		
	} // END for

} // END USART_WriteString
