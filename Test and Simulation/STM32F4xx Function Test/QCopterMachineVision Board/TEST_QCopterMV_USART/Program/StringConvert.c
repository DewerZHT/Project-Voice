/**
 * @File    StringConvert.c
 * @Date    2013.09.03 Tuesday
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

static char convertStr[MAX_SIZE] = {0};
 
char* int2str(int value, int numBase)
{
	unsigned char isNumEnd = false;
	unsigned int  numBuf[MAX_SIZE] = {0};
	unsigned int numCNT = 0;
	unsigned int numOffset = 1;
	
	switch(numBase) {
		
		case Binary :
		case Octal :
		case Decimal :
		case Hexadecimal :
			for(numCNT = 0; isNumEnd == false ; numCNT++) {
				
				numBuf[numCNT] = value / numOffset;
				numOffset = numOffset * numBase;
				
				if(numBuf[numCNT] == 0) {
					
					isNumEnd = true;
					numCNT--;
					
				} // END if there is no data to be convert
				
			} // END for all data seperate by hex
			
			for(numOffset = 0; numOffset < numCNT; numOffset++) {
				
				convertStr[numOffset] = numBuf[numCNT-numOffset-1] % (numBase);
				
				if(convertStr[numOffset] > 9) {
					
					convertStr[numOffset] += (65 - 10); // 65 is 'A' ascii code
					
				} // END if convert data > 9
				
				else {
					
					convertStr[numOffset] += 48; // 48 is '0' ascii code
					
				} // END else convert data <= 9
				
			} // END for all data convert to char
			
			break; // END Hexadecimal convert
		
		case Integer :
			if(value<0) {
				
				convertStr[0] = '-';
				value = (~value) + 1;
				
				for(numCNT=1; isNumEnd == false; numCNT++) {
					
					numBuf[numCNT-1] = ((u32)value) / numOffset;
					if(numBuf[numCNT-1] == 0) isNumEnd = true;
					numOffset = numOffset * 10;
					
				}
				
				for(numOffset=1; numOffset < numCNT+1; numOffset++) {
					
					convertStr[numCNT-numOffset+1] = numBuf[numOffset-1] - numBuf[numOffset]*10;
					convertStr[numCNT-numOffset+1] += 48;
					
				}
				
				convertStr[numCNT+1] = '\0';
				
			} // END if value < 0
			
			else {
				
				for(numCNT=0; isNumEnd == false; numCNT++) {
					
					numBuf[numCNT] = value / numOffset;
					if(numBuf[numCNT] == 0) isNumEnd = true;
					numOffset = numOffset * 10;
					
				}
				
				for(numOffset=1; numOffset < numCNT+1; numOffset++) {
					
					convertStr[numCNT-numOffset-1] = numBuf[numOffset-1] - numBuf[numOffset]*10;
					convertStr[numCNT-numOffset-1] += 48;
					
				}
				
				convertStr[numCNT] = '\0';
			} // END else value >= 0
			
			break;
		
		default :
			break;
		
	}
	
	return convertStr;

} // END num2str

char* float2str(float value, int NumBase)
{
	return convertStr;

} // END float2str

int str2int(const char* str)
{
	int temp;
	
	return temp;
	
} // END str2int

float str2float(const char* str)
{
	float temp;
	
	return temp;
	
} // END str2float
