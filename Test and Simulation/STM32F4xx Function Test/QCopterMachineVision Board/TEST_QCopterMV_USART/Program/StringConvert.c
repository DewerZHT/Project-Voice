/**
 * @File    StringConvert.c
 * @Date    2013.09.01 Sunday
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
 
char* int2str(int value, int NumBase)
{
	unsigned char ConvertFlag = 0;
	unsigned char NumCNT = 0;
	char* convertStr[MAX_SIZE] = {0};
	
	switch(NumBase) {
		
		case Binary :
			break;
		
		case Octal :
			break;
		
		case Hexadecimal :
			for(NumCNT = 0; NumCNT < ConvertFlag; NumCNT++) {
				
			} // END for
			
			break;
		
		case Integer :
			break;
		
		default :
			break;
		
	}

} // END num2str

int str2int(void)
{
	
	
} // END str2int

int str2float(void)
{
	
	
}
