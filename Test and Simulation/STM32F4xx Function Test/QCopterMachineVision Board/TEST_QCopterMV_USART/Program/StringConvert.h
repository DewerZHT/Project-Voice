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

enum NumberBase {

	Binary      = 2,
	Octal       = 8,
	Integer     = 10,
	Hexadecimal = 16

};
	 
#ifdef __cplusplus
	}
#endif
	 
#endif
 