/*
*		Wav decoding functions for wav file format reading.
*		|Author|	Wayne
*		|Date  |	2013.4.7
*		|Note  |	Wav decoding functions.
*	
*/
/*******************Revisions*******************/
/*	|Date  |	2013.4.7
*   |Detail|	1.Obsoleted Wav_FormatValid() function.
*							2.Added struct WAV_FILEFMT for writing file type parsing informations.
*							3.Added tBoolean as a boolean type object definition.
*
*		|Date  |	2013.4.9
*		|Detail|	1.Added WAV_FMT_CHECK_RESULT enumerator as a format check results returning value.
*							2.Added parseFileFmt() to parse the file header.
*							3.Added checkFileFmt_Type1() to check file format to meet Type1's content.
*							4.Added file header length and some offset parameter macros.
*							5.Obsoleted old variables: FileFormatCheck, FormatValidity and SampleDataSize.
*							
*							
*/

#include "wav.h"

// //*****************************************************************************
// //
// // A flag to indicate the file checking status
// //
// //*****************************************************************************
// tBoolean FileFormatCheck=false;

// tBoolean FormatValidity=false;

// unsigned long SampleDataSize=0;

//*****************************************************************************
//
// Convert 2-Byte Little-Endian value into 16bit value
//
//*****************************************************************************
unsigned int Wav_2ByteLittleEndianConvert(unsigned char byte[]){		
		
		unsigned int value=0;
		
		value=byte[0]+byte[1]*256;		
		
		return value;
}

//*****************************************************************************
//
// Convert 4-Byte Little-Endian value into 32bit value
//
//*****************************************************************************
unsigned long Wav_4ByteLittleEndianConvert(unsigned char byte[]){		//compare with (unsigned char *byte)
		
		unsigned long value=0;
		
		value=byte[0]+byte[1]*256+byte[2]*256*256+byte[3]*256*256*256;		//why 64bit is maximun of a value, not 32bit?
																																 //which is slower? 256*...*... or a single value?
		return value;																											//test << arithmetic
}

//*****************************************************************************
//
// Check whether file is RIFF format
//
//*****************************************************************************
tBoolean IsFileRIFF(unsigned char byte[]){
		
		if( byte[0]==Ascii_R && byte[1]==Ascii_I && byte[2]==Ascii_F && byte[3]==Ascii_F ){
				return true;
		}
		else{
				return false;
		}
}

//*****************************************************************************
//
// Check whether file is WAVE format
//
//*****************************************************************************
tBoolean IsFileWave(unsigned char byte[]){
		
		if( byte[0]==Ascii_W && byte[1]==Ascii_A && byte[2]==Ascii_V && byte[3]==Ascii_E ){
				return true;
		}
		else{
				return false;
		}
}

//*****************************************************************************
//
// Check whether WAVE file is PCM format
//
//*****************************************************************************
tBoolean IsPCMFormat(unsigned char byte[]){		//Wonder if there is default return value syntax?
		
		if(Wav_2ByteLittleEndianConvert(byte)==PCM_AudioFormat){
				return true;
		}
		else{
				return false;
		}
}

//*****************************************************************************
//
// How many channels of the WAVE file?
//
//*****************************************************************************
unsigned int getChNumber(unsigned char byte[]){
		
		unsigned int value=0;
		
		value=Wav_2ByteLittleEndianConvert(byte);
		
		return value;
}

//*****************************************************************************
//
// What is the Sample Rate of the WAVE file?
//
//*****************************************************************************
unsigned long getSampleRate(unsigned char byte[]){
		
		unsigned long value=0;
		
		value=Wav_4ByteLittleEndianConvert(byte);
		
		return value;
}

//*****************************************************************************
//
// What is the Byte Rate of the WAVE file?
//
//*****************************************************************************
unsigned long getByteRate(unsigned char byte[]){
		
		unsigned long value=0;
		
		value=Wav_4ByteLittleEndianConvert(byte);
		
		return value;
}

//*****************************************************************************
//
// How many bit per sample of the WAVE file?
//
//*****************************************************************************
unsigned int getBitPerSample(unsigned char byte[]){
		
		unsigned int value=0;
		
		value=Wav_2ByteLittleEndianConvert(byte);
		
		return value;
}

// //*****************************************************************************
// //
// // Check validity of the file to meet the format:RIFF WAVE PCM Stereo 44100Hz 16bit
// //
// //*****************************************************************************
// tBoolean Wav_FormatValid(unsigned char byte[]){
// 		
// 		if(IsFileRIFF(byte)==true){
// 				
// 				UARTprintf("\nFile is RIFF? : %d",true);
// 			
// 				if(IsFileWave(&byte[8])==true){
// 						
// 						UARTprintf("\nFile is WAVE? : %d",true);
// 						
// 						if(IsPCMFormat(&byte[20])==true){
// 								
// 								UARTprintf("\nPCM? : %d",true);
// 								
// 								if(getChNumber(&byte[22])==Stereo_Channel){
// 										
// 										UARTprintf("\nChannel: Stereo");
// 										
// 										if(getSampleRate(&byte[24])==SampleRate_44100){
// 												
// 												UARTprintf("\nSample Rate: %u",SampleRate_44100);
// 												
// 												if(getBitPerSample(&byte[34])==BitPerSample_16){
// 														
// 														UARTprintf("\nByte Rate: %u",getByteRate(&byte[28]));
// 														
// 														UARTprintf("\nBit Per Sample: %u",BitPerSample_16);
// 														
// 														return true;
// 												}
// 												else{
// 														
// 														UARTprintf("\nByte Rate: %u",getByteRate(&byte[28]));
// 														
// 														UARTprintf("\nBit Per Sample: %u",getBitPerSample(&byte[34]));
// 														
// 														return false;
// 												}
// 										}
// 										else{
// 												
// 												UARTprintf("\nSample Rate: %u",getSampleRate(&byte[24]));
// 												
// 												UARTprintf("\nByte Rate: %u",getByteRate(&byte[28]));
// 											
// 												UARTprintf("\nBit Per Sample: %u",getBitPerSample(&byte[34]));
// 											
// 												return false;
// 										}
// 								}
// 								else{
// 										
// 										UARTprintf("\nChannel: %u",getChNumber(&byte[22]));
// 										
// 										return false;
// 								}
// 						}
// 						else{
// 								
// 								UARTprintf("\nPCM? : %d",false);
// 								
// 								return false;
// 						}
// 				}
// 				else{
// 						
// 						UARTprintf("\nFile is WAVE? : %d",false);
// 						
// 						return false;
// 				}
// 		}
// 		else{
// 				
// 				UARTprintf("\nFile is RIFF? : %d",false);
// 				
// 				return false;
// 		}
// }

//*****************************************************************************
//
// What is the size of the sample data chunk?
//
//*****************************************************************************
unsigned long getSampleDataSize(unsigned char byte[]){
		
		unsigned long value=0;
		
		value=Wav_4ByteLittleEndianConvert(byte);
		
		return value;
}

//*****************************************************************************
//
// Parsing a file header to meet RIFF WAVE PCM file format, reading out the specifications and updating the file format object
//
//*****************************************************************************
void parseFileFmt(unsigned char* const headerAddr, WAV_FILEFMT* const filefmt){
		
		//Initialize file format object to default value.
		filefmt->Fmt_IsFile_RIFF = false;
		filefmt->Fmt_IsFile_WAVE = false;
		filefmt->Fmt_IsFile_PCM = false;
		filefmt->Fmt_File_Channel = 0;
		filefmt->Fmt_File_SampleRate = 0;
		filefmt->Fmt_File_ByteRate = 0;
		filefmt->Fmt_File_BitDepth = 0;
		filefmt->Fmt_File_DataChunkSize = 0;
		
		//Parse the file header to meet RIFF WAVE PCM file format, reading out the specifications and updating the file format object
		if(IsFileRIFF(headerAddr + Header_Offset_RIFF)==true){
			
			filefmt->Fmt_IsFile_RIFF = true;
			
			if(IsFileWave(headerAddr + Header_Offset_WAVE)==true){
				
				filefmt->Fmt_IsFile_WAVE = true;
				
				if(IsPCMFormat(headerAddr + Header_Offset_PCM)==true){
					
					filefmt->Fmt_IsFile_PCM = true;
					
					filefmt->Fmt_File_Channel = getChNumber(headerAddr + Header_Offset_Channel);
					filefmt->Fmt_File_SampleRate = getSampleRate(headerAddr + Header_Offset_SampleRate);
					filefmt->Fmt_File_ByteRate = getByteRate(headerAddr + Header_Offset_ByteRate);
					filefmt->Fmt_File_BitDepth = getBitPerSample(headerAddr + Header_Offset_BitDepth);
					filefmt->Fmt_File_DataChunkSize = getSampleDataSize(headerAddr + Header_Offset_DataChunkSize);
					
				}
				else{
					filefmt->Fmt_IsFile_PCM = false;
				}
				
			}
			else{
				filefmt->Fmt_IsFile_WAVE = false;
			}
			
		}
		else{
			filefmt->Fmt_IsFile_RIFF = false;
		}
		
}

//*****************************************************************************
//
// Format Type1: RIFF WAVE PCM Stereo 44100Hz 16bit, also check the DataChunkSize validity(omit the ByteRate parameter)
//
//*****************************************************************************
WAV_FMT_CHECK_RESULT checkFileFmt_Type1(unsigned char* const headerAddr, unsigned long fileSize, WAV_FILEFMT* const filefmt){
				
		//Parse the header, initialize and fill the file format object.
		parseFileFmt(headerAddr,filefmt);
		
		//Check the format object to meet Type1's content.
		if(filefmt->Fmt_IsFile_RIFF){
			
			if(filefmt->Fmt_IsFile_WAVE){
				
				if(filefmt->Fmt_IsFile_PCM){
					
					if(filefmt->Fmt_File_Channel==Stereo_Channel){
						
						if(filefmt->Fmt_File_SampleRate==SampleRate_44100){
							
							if(filefmt->Fmt_File_BitDepth==BitPerSample_16){
								
								if(filefmt->Fmt_File_DataChunkSize <= fileSize - Header_Length){
									
									if(filefmt->Fmt_File_DataChunkSize%2==0){
										
										return RESULT_FMT_VALID;
										
									}
									else{
										return RESULT_DATACHUNKPAIR_INVALID;
									}
									
								}
								else{
									return RESULT_DATACHUNKSIZE_INVALID;
								}
								
							}
							else{
								return RESULT_BITDEPTH_INVALID;
							}
							
						}
						else{
							return RESULT_SAMPLINGRATE_INVALID;
						}
						
					}
					else{
						return RESULT_CHANNEL_INVALID;
					}
					
				}
				else{
					return RESULT_PCM_INVALID;
				}
				
			}
			else{
				return RESULT_WAVE_INVALID;
			}
			
		}
		else{
			return RESULT_RIFF_INVALID;
		}
		
}
