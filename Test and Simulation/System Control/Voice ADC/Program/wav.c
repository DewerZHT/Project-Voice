/** Wave Format Module *********************************************************
 * @File    wav.c
 * @Date    2013.10.03 Thursday
 * @Author  Wu, Chen-Hao (CH. Wu)
 *					CYCU ICE, Lab801; AutoControl Club
 * @Version V1
 * @Brief 	Audio Wave format access 
 *
 * @Create  2013.10.03 Thursday
 *
 **/ 

#include "wav.h"

isRIFF()
{

} // END isRIFF

isWav()
{

} // END isWav

isPCM()
{

} // END isPCM

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
	unsigned char* pByte;

	pByte = malloc(byteSize * sizeof(char));

	for( byteCNT = 0; byteCNT < byteSize; byteCNT++) {

		pByte[byteSize-1 - byteCNT] = byteVal[byteCNT] << byteCNT;

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
	unsigned char* pByte;

	pByte = malloc(byteSize * sizeof(char));

	for(byteCNT = 0; byteCNT < byteSize; byteCNT++) {

		pByte[byteCNT] = byteVal[byteSize-1 - byteCNT] << byteCNT;

	} // END for all byte values

	return pByte;

} // END BEdian2LEdian

/** creat wave file ************************************************************
 *
 * @Function creatWav
 * @Input  : char* fileName
 * @Output : 
 *
 **/
creatWav(const char* fileName)
{

} // END creatWav

openWav(const char* fileName)
{

} // END openWav

playWav()
{

} // END playWav

recordWav(const char* fileName)
{

} // END recordWav

getWavInf()
{

} // END getWavInf

deleteWav()
{

} // END delete 
