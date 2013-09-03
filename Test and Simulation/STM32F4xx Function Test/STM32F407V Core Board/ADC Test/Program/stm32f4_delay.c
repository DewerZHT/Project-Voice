/**
 * @File    stm32f4_delay.c
 * @Date    2013.08.16 Firday
 * @Author  Wu, Chen-Hao
 *				  CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief   To test gpio function
 *
 * @Create  2013.08.16 Firday
 *
 **/

/* Includes -----------------------------------------------------------------*/
#include "stm32f4_delay.h"

/* Functions Reference ------------------------------------------------------*/


/******************************************************************************
 * @Function Delay_1us
 * @Brief    Delay 1 micro second with system clock 168MHz
 *
 **/
void delay_1us( unsigned int delay_Times )
{
	unsigned int machine_Cnt;
	for(; delay_Times != 0; delay_Times--)
		for(machine_Cnt = 45; machine_Cnt != 0; machine_Cnt--);
}


/******************************************************************************
 * @Function Delay_10us
 * @Brief    Delay 10 micro second with system clock 168MHz
 *
 **/
void delay_10us( unsigned int delay_Times )
{
	unsigned int machine_Cnt;
	for(; delay_Times != 0; delay_Times--)
		for(machine_Cnt = 556; machine_Cnt != 0; machine_Cnt--);
}


/******************************************************************************
 * @Function Delay_100us
 * @Brief    Delay 100 micro second with system clock 168MHz
 *
 **/
void delay_100us( unsigned int delay_Times )
{
	unsigned int machine_Cnt;
	for(; delay_Times != 0; delay_Times--)
		for(machine_Cnt = 5400; machine_Cnt != 0; machine_Cnt--);
}


/******************************************************************************
 * @Function Delay_1ms
 * @Brief    Delay 1 milli second with system clock 168MHz
 *
 **/
void delay_1ms( unsigned int delay_Times )
{
	unsigned int machine_Cnt;
	for(; delay_Times != 0; delay_Times--)
		for(machine_Cnt = 56580; machine_Cnt != 0; machine_Cnt--);
}


/******************************************************************************
 * @Function Delay_10ms
 * @Brief    Delay 10 milli second with system clock 168MHz
 *
 **/
void delay_10ms( unsigned int delay_Times )
{
	unsigned int machine_Cnt;
	for(; delay_Times != 0; delay_Times--)
		for(machine_Cnt = 559928; machine_Cnt != 0; machine_Cnt--);
}


/******************************************************************************
 * @Function Delay_100ms
 * @Brief    Delay 100 milli second with system clock 168MHz
 *
 **/
void delay_100ms( unsigned int delay_Times )
{
	unsigned int machine_Cnt;
	for(; delay_Times != 0; delay_Times--)
		for(machine_Cnt = 5655000; machine_Cnt != 0; machine_Cnt--);
}

