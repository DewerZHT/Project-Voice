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
#include "stm32f4_SDIO.h"

// Data Convert
#include "StringConvert.h"

// File System Libraries
#include "ff.h"
#include "diskio.h"

// Global Variables
FATFS fatfs;
FRESULT res;
FILINFO finfo;
DIR dirs;
FIL file;

const void *WriteData;

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
	
	// Initialize the storage of SD card.
	USART_SendStr(USART2, (u8*)" \r\n");
  USART_SendStr(USART2, (u8*)"----------------------\r\n");
  USART_SendStr(USART2, (u8*)"----------------------\r\n");
  USART_SendStr(USART2, (u8*)" SDIO SD Fatfs demo\r\n");
  USART_SendStr(USART2, (u8*)"----------------------\r\n");
  USART_SendStr(USART2, (u8*)"----------------------\r\n\r\n");
  USART_SendStr(USART2, (u8*)" SD Init ... \r\n");
  while(SD_Init() != SD_OK) {
    USART_SendStr(USART2, (u8*)"Failed!!\r\n");
    while(1) {
      LED_R = ~LED_R;
      delay_10ms(5);
    }
  }
	USART_SendStr(USART2, (u8*)" Success!!\r\n");
	
//	USART_SendStr(USART2, (u8*)"-----SD Init Info-----\r\n");
//  
//  USART_SendStr(USART2, (u8*)" Capacity : ");
//  USART_SendStr(USART2, int2str(SDCardInfo.CardCapacity>>20, Decimal));
//  USART_SendStr(USART2, (u8*)" MB\r\n");

//  USART_SendStr(USART2, (u8*)" CardBlockSize : ");
//  NumToChar(Type_D, 5, TrData[1], SDCardInfo.CardBlockSize);
//  USART_SendStr(USART2, TrData[1]);
//  USART_SendStr(USART2, (u8*)"\r\n");

//  USART_SendStr(USART2, (u8*)" CardType : ");
//  NumToChar(Type_D, 5, TrData[2], SDCardInfo.CardType);
//  USART_SendStr(USART2, TrData[2]);
//  USART_SendStr(USART2, (u8*)"\r\n");

//  USART_SendStr(USART2, (u8*)" RCA : ");
//  NumToChar(Type_D, 5, TrData[3], SDCardInfo.RCA);
//  USART_SendStr(USART2, TrData[3]);
//  USART_SendStr(USART2, (u8*)"\r\n");
//  USART_SendStr(USART2, (u8*)"----------------------\r\n");
//  USART_SendStr(USART2, (u8*)"\r\n");

  // Fat FS access
	// Read Directory File
  USART_SendStr(USART2, (u8*)"----------------------\r\n");
  USART_SendStr(USART2, (u8*)" SD_Card Read Directory File\r\n");
  USART_SendStr(USART2, (u8*)"----------------------\r\n\r\n");

  res = f_mount(0, &fatfs);
  res = f_opendir(&dirs, "0:/");
  res = f_readdir(&dirs, &finfo);
  while(res!= FR_OK) {
		USART_SendStr(USART2, (u8*)" Fatfs failed!!\r\n");
		while(1) {
      LED_R = ~LED_R;
      delay_10ms(20);
    }
	}
  USART_SendStr(USART2, (u8*)" File name : \r\n");
 
  while(finfo.fname[0]) {
    f_readdir(&dirs, &finfo);
    if(!finfo.fname[0])
      break;
    USART_SendStr(USART2, (u8*)" ... ");
    USART_SendStr(USART2, (u8*)finfo.fname);
    USART_SendStr(USART2, (u8*)"\r\n");
  }
	
	// create a wave file for recording
  USART_SendStr(USART2, (u8*)" f_open ... ");
  res = f_open(&file,"Wav_T.wav", FA_OPEN_ALWAYS | FA_READ | FA_WRITE);
  if(res==FR_OK)
    USART_SendStr(USART2, (u8*)"OK!!\r\n");
  else
    USART_SendStr(USART2, (u8*)"failed!!\r\n");

  USART_SendStr(USART2, (u8*)" f_write ... ");
//  res = f_write(&file, WriteData, 20, &i); 
  if(res==FR_OK)
    USART_SendStr(USART2, (u8*)"OK!!\r\n");
  else
    USART_SendStr(USART2, (u8*)"failed!!\r\n");
	
	while( 1 ) {
		
		LED_G = ~LED_G;
		ADC_Average(ADCaverageVal);
		
		// Display how many seconds pass during recording
		
//		USART_SendStr(USART2, (u8*) "ADC value = ");
//		USART_SendStr(USART2, (u8*) int2str(ADCaverageVal[0], Integer));
//		USART_SendStr(USART2, (u8*) "\r");
		delay_10ms(5);

	} // END while (continue convert voice wave to digital.)
	
	f_close(&file);

} // END main
