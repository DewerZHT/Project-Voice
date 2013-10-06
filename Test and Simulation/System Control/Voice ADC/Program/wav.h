/** Wave Format Module *********************************************************
 * @File    wav.h
 * @Date    2013.10.03 Thursday
 * @Author  Wu, Chen-Hao (CH. Wu)
 *					CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief 	Audio Wave format access 
 *
 * @Create  2013.10.03 Thursday
 *
 **/ 

#ifndef __WAV_H
#define __WAV_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
// C Standard Library
#include <stdbool.h>
#include <string.h>

typedef struct RIFF_FMT {
	char ID[4];
	char SIZE[4];
	char FORMAT[4];
} RIFF_FMT;

typedef struct WAV_FMT {
	char ID[4];
	char SIZE[4];
	char 
} WAV_FMT;

typedef struct WavInf_FMT {
	char* FILE_Name;
	RIFF_FMT RIFF_Inf;
	WAV_FMT  WAV_Inf;
} WavInf_FMT;

#endif
