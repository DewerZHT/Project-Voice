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
 
char* int2str(int value, int numBase)
{
	unsigned char isConvert = false;
	unsigned int  numBuf[MAX_SIZE] = {0};
	unsigned char numCNT = 0;
	unsigned char numOffset = 1;

	for(numCNT = 0; numCNT < MAX_SIZE; numCNT++)
		convertStr[numCNT] = '\0';
	
	switch(numBase) {
		
		case Binary :
		case Octal :
		case Decimal :
		case Hexadecimal :
			for(numCNT = 0; isConvert == false ; numCNT++) {
				
				numBuf[numCNT] = value / numOffset;
				
				if(numBuf[numCNT] == 0) {
					
					isConvert = true;
					numCNT--;
					
				} // END if there is no data to be convert
				
				numOffset = numOffset * numBase;
				
			} // END for all data seperate by hex
			
			for(numOffset = 0; numOffset < numCNT; numOffset++) {
				
				convertStr[numCNT-numOffset-1] = numBuf[numOffset] - numBuf[numOffset+1]*numBase;
				
				if(convertStr[numCNT-numOffset-1] > 9) {
					
					convertStr[numCNT-numOffset-1] += 65; // 65 is 'A' ascii code
					
				} // END if convert data > 9
				
				else {
					
					convertStr[numCNT-numOffset-1] += 48; // 48 is '0' ascii code
					
				} // END else convert data <= 9
				
			} // END for all data convert to char
			
			convertStr[numCNT] = '\0';
			
			break; // END Hexadecimal convert
		
		case Integer :
			if(value<0) {
				
				convertStr[0] = '-';
				value = (~value) + 1;
				
				for(numCNT=1; isConvert == false; numCNT++) {
					
					numBuf[numCNT-1] = ((u32)value) / numOffset;
					if(numBuf[numCNT-1] == 0) isConvert = true;
					numOffset = numOffset * 10;
					
				}
				
				for(numOffset=1; numOffset < numCNT+1; numOffset++) {
					
					convertStr[numCNT-numOffset+1] = numBuf[numOffset-1] - numBuf[numOffset]*10;
					convertStr[numCNT-numOffset+1] += 48;
					
				}
				
				convertStr[numCNT+1] = '\0';
				
			} // END if value < 0
			
			else {
				
				for(numCNT=0; isConvert == false; numCNT++) {
					
					numBuf[numCNT] = value / numOffset;
					if(numBuf[numCNT] == 0) isConvert = true;
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
