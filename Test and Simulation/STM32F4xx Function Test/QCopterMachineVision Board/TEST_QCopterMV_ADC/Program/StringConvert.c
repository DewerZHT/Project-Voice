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

/******************************************************************************
 * @Function int2str
 * @Brief    Convert integer numeric data to character string
 *           with binary, octal, decimal, hex format.
 *
 **/
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
			if(numBase == Binary) convertStr[0] = 'b';
			else if (numBase == Octal) convertStr[0] = 'o';
			else if (numBase == Decimal) convertStr[0] = 'd';
			else if (numBase == Hexadecimal) convertStr[0] = 'h';
		
			convertStr[1] = '\'';
		
			for(numCNT = 0; isNumEnd == false ; numCNT++) {
				
				numBuf[numCNT] = value / numOffset;
				numOffset = numOffset * numBase;
				
				if(numBuf[numCNT] == 0) {
					
					isNumEnd = true;
					numCNT--;
					
				} // END if there is no data to be convert
				
			} // END for all data seperate by hex
			
			for(numOffset = 0; numOffset < numCNT; numOffset++) {
				
				convertStr[numOffset+2] = numBuf[numCNT-numOffset-1] % (numBase);
				
				if(convertStr[numOffset+2] > 9) {
					
					convertStr[numOffset+2] += (65 - 10); // 65 is 'A' ascii code
					
				} // END if convert data > 9
				
				else {
					
					convertStr[numOffset+2] += 48; // 48 is '0' ascii code
					
				} // END else convert data <= 9
				
			} // END for all data convert to char

			convertStr[numOffset+3] = '\0';
			
			break; // END Hexadecimal convert
		
		case Integer :
			if(value >= 0)     convertStr[0] = '+'; // if(value is positive)
			else if(value < 0) convertStr[0] = '-'; // if(value is negative)
		
			for(numCNT = 0; isNumEnd == false ; numCNT++) {
				
				numBuf[numCNT] = value / numOffset;
				numOffset = numOffset * 10;
				
				if(numBuf[numCNT] == 0) {
					
					isNumEnd = true;
					numCNT--;
					
				} // END if there is no data to be convert
				
			} // END for all data seperate by hex
			
			for(numOffset = 0; numOffset < numCNT; numOffset++) {
				
				convertStr[numOffset+1] = numBuf[numCNT-numOffset-1] % 10;
				
				if(convertStr[numOffset+1] > 9) {
					
					convertStr[numOffset+1] += (65 - 10); // 65 is 'A' ascii code
					
				} // END if convert data > 9
				
				else {
					
					convertStr[numOffset+1] += 48; // 48 is '0' ascii code
					
				} // END else convert data <= 9
				
			} // END for all data convert to char

			convertStr[numOffset+2] = '\0';
		
			break;
		
		default :
			break;
		
	}
	
	return convertStr;

} // END num2str

/******************************************************************************
 * @Function float2str
 * @Brief    Convert float numeric data to character string
 *
 **/
char* float2str(float value, int NumBase)
{
	return convertStr;

} // END float2str

/******************************************************************************
 * @Function str2int
 * @Brief    Convert character string to integer 
 *
 **/
int str2int(const char* str)
{
	int temp;
	
	return temp;
	
} // END str2int

/******************************************************************************
 * @Function str2float
 * @Brief    Convert character string to float
 *
 **/
float str2float(const char* str)
{
	float temp;
	
	return temp;
	
} // END str2float
