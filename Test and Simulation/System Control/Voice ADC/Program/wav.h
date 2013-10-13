/** Wave Format Module *********************************************************
 * @File    wav.c
 * @Date    2013.10.13 Sunday
 * @Author  Wu, Chen-Hao (CH. Wu)
 *					CYCU ICE, Lab801; AutoControl Club
 * @Version V1.1 (Complete )
 * @Brief 	Audio Wave format access
 *          Base on reference data :
 *            - https://ccrma.stanford.edu/courses/422/projects/WaveFormat/
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

#include "type.h"

typedef struct RIFF_FMT {
	char ID[4];
	char SIZE[4];
	char FORMAT[4];
} RIFF_FMT;

typedef struct WAV_FMT {
	char ID[4];
	char SIZE[4];
	char FMT[2];
	char CHANNEL[2];
} WAV_FMT;

typedef struct WavInf_FMT {
	char* FILE_Name;
	RIFF_FMT RIFF_Inf;
	WAV_FMT  WAV_Inf;
} WavInf_FMT;

extern unsigned char* pByte;

#endif
