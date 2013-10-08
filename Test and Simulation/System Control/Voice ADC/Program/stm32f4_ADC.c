/**
 * @File    stm32f4_ADC.c
 * @Date    2013.10.03 Thursday
 * @Author  Wu, Chen-Hao CH. Wu
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V2
 * @Brief Voice ADC Test and simulation  
 *        use QCopterMV Board ADC Periphral Config
 *
 * @Create  2013.09.12 Thursday
 *
 **/ 

/* Includes ------------------------------------------------------------------*/
// ST Library
#include <stm32f4xx_adc.h>

// STM32F4xx Config library
#include "stm32f4_GPIO.h"
#include "stm32f4_ADC.h"

static u16 ADC_DMA_Buf[ADC_Sample][ADC_Channel];

void ADC_Config( void )
{
	/** Variable declaration ****************************************************/
  DMA_InitTypeDef DMA_InitStruct;
  ADC_InitTypeDef ADC_InitStruct;
  ADC_CommonInitTypeDef ADC_CommonInitStruct;
  GPIO_InitTypeDef GPIO_InitStruct;

  /** ADC Clk Initials ********************************************************/
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

  /** ADC_I PA0 ***************************************************************/ 
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AN;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStruct);

  /** ADC DMA Configuration ***************************************************/
  DMA_InitStruct.DMA_Channel = DMA_Channel_0;
  DMA_InitStruct.DMA_PeripheralBaseAddr = (u32) ADC1_DR_ADDRESS;              // Peripheral address
  DMA_InitStruct.DMA_Memory0BaseAddr = (u32) &ADC_DMA_Buf;                    // Memory address
  DMA_InitStruct.DMA_DIR = DMA_DIR_PeripheralToMemory;                        // Peripheral to Memory
  DMA_InitStruct.DMA_BufferSize = ADC_Sample * ADC_Channel;                   // Memory Buffer Size
  DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Disable;               // Peripheral address increase Disable
  DMA_InitStruct.DMA_MemoryInc = DMA_MemoryInc_Enable;                        // Memory address increase Enable
  DMA_InitStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;    // Peripheral Data Size 16bit
  DMA_InitStruct.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;            // Memory Data Size 16bit
  DMA_InitStruct.DMA_Mode = DMA_Mode_Circular;                                // �`���Ҧ� Enable
  DMA_InitStruct.DMA_Priority = DMA_Priority_High;                            // ADC DMA�q�D ���u����
  DMA_InitStruct.DMA_FIFOMode = DMA_FIFOMode_Disable;                         // DMA FIFO Disable
  DMA_InitStruct.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
  DMA_InitStruct.DMA_MemoryBurst = DMA_MemoryBurst_Single;
  DMA_InitStruct.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
  DMA_Init(DMA2_Stream0, &DMA_InitStruct);
  DMA_Cmd(DMA2_Stream0, ENABLE);

  /* ADC Common Init **********************************************************/
  ADC_CommonInitStruct.ADC_Mode = ADC_Mode_Independent;
  ADC_CommonInitStruct.ADC_Prescaler = ADC_Prescaler_Div2;
  ADC_CommonInitStruct.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;        // ADC DMA Mode Disable
  ADC_CommonInitStruct.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
  ADC_CommonInit(&ADC_CommonInitStruct);

  /* ADC Init *****************************************************************/
  ADC_InitStruct.ADC_Resolution = ADC_Resolution_12b;                         // ADC resolution 12-bits
  ADC_InitStruct.ADC_ScanConvMode = ENABLE;                                   // 
  ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;                             // 
  ADC_InitStruct.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;    // Disable
  ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;                         // ADC
  ADC_InitStruct.ADC_NbrOfConversion = ADC_Channel;                           // 
  ADC_Init(ADC1, &ADC_InitStruct);

  /* ADC Regular Config *******************************************************/
  ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_3Cycles);  	// ADC_I

  ADC_DMARequestAfterLastTransferCmd(ADC1, ENABLE);
  ADC_DMACmd(ADC1, ENABLE);
  ADC_ContinuousModeCmd(ADC1, ENABLE);
  ADC_Cmd(ADC1, ENABLE);
  ADC_SoftwareStartConv(ADC1);
	
} // END ADC_Config

void ADC_Average( u16* pADC_AveTr )
{
  u8 i, j;
  u32 ADC_DMA_Tmp[ADC_Channel] = {0};

  for(i=0; i<ADC_Channel; i++) {
    for(j=0; j<ADC_Sample; j++)
      ADC_DMA_Tmp[i] += ADC_DMA_Buf[j][i];
    pADC_AveTr[i] = (u16)(ADC_DMA_Tmp[i] / ADC_Sample);
  }
} // END ADC_Average
