/**
 * Wav decoding functions for wav file format access.
 * Fork from Wayne (CYCU EE)
 *
 * File name wav.c
 * Author		 Wu, Chen-Hao
 * Date  		 2013.09.24
 * Brief  	 Wav coding and decoding functions.
 *	
 **/

#ifndef __WAV_H
#define __WAV_H

#ifdef __cplusplus
	extern "C" {
#endif
		
//Define a struct for file check status of the file.
typedef struct WAV_FILEFMT {
	bool Fmt_IsFile_RIFF;
	bool Fmt_IsFile_WAVE;
	bool Fmt_IsFile_PCM;
	unsigned int  Fmt_File_Channel;
	unsigned long Fmt_File_SampleRate;
	unsigned long Fmt_File_ByteRate;
	unsigned int  Fmt_File_BitDepth;
	unsigned long Fmt_File_DataChunkSize;
}	WAV_FILEFMT;

//Enumerator for format check results.
typedef enum{
	RESULT_FMT_VALID = 0,					/*0*/		//Format check passed.
	RESULT_RIFF_INVALID,					/*1*/		//Not RIFF type file.
	RESULT_WAVE_INVALID,					/*2*/		//Not Wave format file.
	RESULT_PCM_INVALID,						/*3*/		//Not standard PCM type.
	RESULT_CHANNEL_INVALID,				/*4*/		//Channel number incompatible.
	RESULT_SAMPLINGRATE_INVALID,	/*5*/		//Sampling rate incompatible.
	RESULT_BITDEPTH_INVALID,			/*6*/		//Sample Bit depth incompatible.
	RESULT_DATACHUNKSIZE_INVALID,	/*7*/		//Data chunk size(whole file size - header length) mismatched(or shorter) with SubChunk2Size value indicated in the header.
	RESULT_DATACHUNKPAIR_INVALID	/*8*/		//SubChunk2Size not end on an even byte boundary. For stereo channel format only.
}	WAV_FMT_CHECK_RESULT;

#define FileFormatCheck_none false
#define FileFormatCheck_done true

#define Header_Length 44								//RIFF-WAVE contains 44 bytes of file header.
#define Header_Offset_RIFF 0
#define Header_Offset_WAVE 8
#define Header_Offset_PCM 20
#define Header_Offset_Channel 22
#define Header_Offset_SampleRate 24
#define Header_Offset_ByteRate 28
#define Header_Offset_BitDepth 34
#define Header_Offset_DataChunkSize 40

#define ASCII_R 0x52
#define ASCII_I 0x49
#define ASCII_F 0x46
#define ASCII_W 0x57
#define ASCII_A 0x41
#define ASCII_V 0x56
#define ASCII_E 0x45
#define ASCII_f 0x66
#define ASCII_m 0x6d
#define ASCII_t 0x74

#define PCM_AudioFormat 0x0001
#define Stereo_Channel 0x0002
#define SampleRate_44100 44100
#define ByteRate_176400 176400
#define BitPerSample_16 16

unsigned long Wav_4ByteLittleEndianConvert(unsigned char byte[]);
tBoolean IsFileRIFF(unsigned char byte[]);
tBoolean IsFileWave(unsigned char byte[]);
tBoolean IsPCMFormat(unsigned char byte[]);
unsigned int getChNumber(unsigned char byte[]);
unsigned long getSampleRate(unsigned char byte[]);
unsigned long getByteRate(unsigned char byte[]);
unsigned int getBitPerSample(unsigned char byte[]);
tBoolean Wav_FormatValid(unsigned char byte[]);
unsigned long getSampleDataSize(unsigned char byte[]);
void parseFileFmt(unsigned char* const headerAddr, WAV_FILEFMT* const filefmt);
WAV_FMT_CHECK_RESULT checkFileFmt_Type1(unsigned char* const headerAddr, unsigned long fileSize, WAV_FILEFMT* const filefmt);

#endif
