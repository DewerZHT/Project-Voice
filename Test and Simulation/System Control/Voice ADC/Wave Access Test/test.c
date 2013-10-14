/** Test Bench *****************************************************************
 * @File    test.c
 * @Date    2013.10.03 Thursday
 * @Author  Wu, Chen-Hao (CH. Wu)
 *					CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief 	Audio Wave format access 
 *
 * @Create  2013.10.03 Thursday
 *
 **/

#include <stdio.h>
#include <stdlib.h>

typedef struct WAV_FMT {
	char* FILE_NAME;
	
	char RIFF_ID[4];
	char RIFF_Size[4];
	char RIFF_Format[4];
	
	char WAV_ID[4];
	char WAV_Size[4];
	char WAV_Audio_Format[2];
	char WAV_Channel_Num[2];
	char WAV_Sample_Rate[4];
	char WAV_Byte_Rate[4];
	char WAV_Block_Align[2];
	char WAV_BitsPerSample[2];
	
	
} RIFF_FMT;

unsigned char* LEdian2BEdian(unsigned char* byteVal, unsigned int byteSize);
unsigned char* BEdian2LEdian(unsigned char* byteVal, unsigned int byteSize);

unsigned char* pByte;

int main(void) {
	
	unsigned char CNT = 0;
	unsigned char  in1[4] = {0x36, 0x2F, 0x00, 0x00};
	unsigned char  in2[4] = {0x00, 0x00, 0x2F, 0x36};
	unsigned char* out;
	
	printf("Little to Big Edian data fromat\n");
	printf("The sample data : 36 2F 00 00\n");
	
	out = LEdian2BEdian(in1, 4);
	for(CNT = 0; CNT < 4; CNT++) {
	
		printf("%x ", out[CNT]);
	
	}
	printf("\n");
	printf("\n");
	
	printf("Big to Little Edian data fromat\n");
	printf("The sample data : 00 00 2F 36\n");
	
	out = BEdian2LEdian(in2, 4);
	for(CNT = 0; CNT < 4; CNT++) {
	
		printf("%x ", out[CNT]);
	
	}
	
	printf("\n");
	printf("\n");
	
	return 0;
	
} // END main

/** convert little edian to big edian ******************************************
 *
 * @Function LEdian2BEdian
 * @Input  : unsigned char* byteVal  - data wait to be convert
 *					 unsigned int   byteSize - data size (n Bytes)
 * @Output : unsigned char* pByte
 *
 **/
unsigned char* LEdian2BEdian(unsigned char* byteVal, unsigned int byteSize) 
{
	unsigned char  byteCNT;

	pByte = malloc(byteSize * sizeof(char));

	for( byteCNT = 0; byteCNT < byteSize; byteCNT++) {

		pByte[byteSize-1 - byteCNT] = byteVal[byteCNT];

	} // END for all byte values

	return pByte;

} // END LEdian2BEdian

/** convert big edian to little edian ******************************************
 *
 * @Function BEdian2LEdian
 * @Input  : unsigned char* byteVal  - data wait to be convert
 *					 unsigned int   byteSize - data size (n Bytes)
 * @Output : unsigned char* pByte 
 *
 **/
unsigned char* BEdian2LEdian(unsigned char* byteVal, unsigned int byteSize)
{
	unsigned char  byteCNT;

	pByte = malloc(byteSize * sizeof(char));

	for(byteCNT = 0; byteCNT < byteSize; byteCNT++) {

		pByte[byteCNT] = byteVal[byteSize-1 - byteCNT];

	} // END for all byte values

	return pByte;

} // END BEdian2LEdian

/** open wave file with it's file name *****************************************
 *
 * @Function openWav
 * @Input  : const char* fileName - wave file name
 * @Output : unsigned char* pByte 
 *
 **/
bool openWav(const char* fileName)
{
	FILE* 

} // END openWav
