/**
 * @File    StringConvert.c
 * @Date    2013.09.02 Monday
 * @Author  Wu, Chen-Hao
 *					CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief   Some methods of string data convert
 *
 * @Create  2013.09.01 Sunday
 *
 **/
 
/* Includes ------------------------------------------------------------------*/
#include "StringConvert.h"
 
char* int2str(const int value, int numBase)
{
	bool convertFlag = true;
	unsigned int  numBuf[MAX_SIZE] = {0};
	unsigned char numCNT = 0;
	unsigned char numOffset = 1;
	char* convertStr[MAX_SIZE] = {0};
	
	switch(numBase) {
		
		case Binary :
			break;
		
		case Octal :
			break;
		
		case Hexadecimal :
			for(numCNT = 0; convertFlag == true ; numCNT++) {
				numBuf[numCNT] = value / numOffset;
				
			} // END for
			
			break;
		
		case Integer :
			break;
		
		default :
			break;
		
	}

} // END num2str

char* float2str(const float value, int NumBase)
{
	

} // END float2str

int str2int(const char* str)
{
	
	
} // END str2int

float str2float(const char* str)
{
	
	
} // END str2float
