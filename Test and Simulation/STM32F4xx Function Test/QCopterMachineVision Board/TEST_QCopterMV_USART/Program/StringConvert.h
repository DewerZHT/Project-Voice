/**
 * @File    StringConvert.h
 * @Date    2013.09.01 Sunday
 * @Author  Wu, Chen-Hao
 *					CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief   Some methods of string data convert
 *
 * @Create  2013.09.01 Sunday
 *
 **/

#ifndef __STRING_CONVERT_H
#define __STRING_CONVERT_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
// ST library
#include <stm32f4xx.h>
		
#define MAX_SIZE 200
		
// Define boolean
#define bool	_Bool
#define true	1
#define false	0

enum NumberBase {

	Binary      = 2,
	Octal       = 8,
	Decimal			= 10,
	Hexadecimal = 16,
	Integer     = 0

};

static char convertStr[MAX_SIZE] = {0};

// Function declaration
char* int2str(int value, int NumBase);
char* float2str(float value, int NumBase);
int str2int(const char* str);
float str2float(const char* str);
	 
#ifdef __cplusplus
	}
#endif
	 
#endif
