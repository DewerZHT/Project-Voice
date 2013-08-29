/**
 *
 * @Filename : Main.cpp
 * @Date     : 2013.08.28 Wednesday
 *
 * @Author             : WU, CHEN-HAO
 * @Platform : Windows 7 SP1
 * @Develop  : Code::Blocks v12.11
 * @Version  : 0 (Not complete)
 * @Brief
 *    The homework for Operating System Course #03,
 *    some memory page replacement methods simulation.
 *    	1. First in first out        - FIFO
 *    	2. Least Recently Used       - LRU
 *      3. Additional Reference Bits - ARB
 *    	3. Second Chance             - SC
 *    	4. Least Frequently Used     - LFU
 *    	5. Most Frequently Used      - MFU
 *    Other function for utility use
 *      1. Get page frame            - getPageFrame
 *      2. Get page reference        - getPageRefOrder
 *      3. Output memory information - outMemReplaceInf
 *      4. Clear memory information  - clearMemInf
 *      5. Initial memory page - initMemPage
 *
**/


// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// parameters
#define MAX_SIZE 200
#define END_SIGN -1

// type definition
typedef char STRING[MAX_SIZE];
typedef struct {
  int PageData;
  int UsedTimes;
  int AccessTimes;

} MEM_REF;

// global variables
static FILE*  g_InFile;
static FILE*  g_OutFile;
static STRING g_StrBuf, g_OutBuf;
static int    g_PageFrame, g_PageFault, g_PageReplace;
static int    g_PageRefOrder[MAX_SIZE];

// function prototype
void getPageFrame(FILE* pDataFile);
void getPageRefOrder(FILE* pDataFile);
void outMemReplaceInf(void);
void clearMemInf(void);
void initMemPage(MEM_REF* memoryPage);
void FIFO(const int pageFrame);
void LRU(const int pageFrame);
void SC(const int pageFrame);
void ARB(const int pageFrame);
void LFU(const int pageFrame);
void MFU(const int pageFrame);

int main(void)
{
  int mCount;
  STRING inFilename;

  // open input file.
  printf("Enter input file name :\n");
  scanf("%s", g_StrBuf);
  printf("\n");
  strcpy(inFilename, g_StrBuf);
  g_InFile = fopen(inFilename, "r");

  if(g_InFile != NULL) {
    printf("File : %s opened success.\n", inFilename);

  } // end if
  else {
    printf("File : %s couldn't be opened, or not exsist.\n", inFilename);
	  printf("Program terminated.\n");
	  return 0;

  } // end else

  // open output file.
  g_OutFile = fopen("output.txt", "w");

  if(g_OutFile != NULL) {
    printf("File : %s opened success.\n", "output.txt");

  } // end if
  else {
  	printf("File : %s couldn't be opened.\n", "output.txt");
		printf("Program terminated.\n");
		return 0;

  } // end else

  // Get memory page frame
  getPageFrame(g_InFile);
  printf("Page Frame : %d\n", g_PageFrame);
  printf("\n");

  // Get page reference order
  getPageRefOrder(g_InFile);
  for(mCount = 0; g_PageRefOrder[mCount] != END_SIGN; mCount++) {
    printf("%d", g_PageRefOrder[mCount]);

  } // end for
  printf("\n\n");

  clearMemInf();

  // First In First Out Page Replacement
  printf("First In First Out\n");
  fputs("----- First In First Out -------------\n", g_OutFile);
  FIFO(g_PageFrame);
  outMemReplaceInf();
  clearMemInf();
  printf("First In First Out Accessed.\n\n");

  // Least Recently Used Page Replacement
  printf("Least Recently Used\n");
  fputs("----- Least Recently Used ------------\n", g_OutFile);
  LRU(g_PageFrame);
  outMemReplaceInf();
  clearMemInf();
  printf("Least Recently Used Accessed.\n\n");

  // Additional Reference Bits Page Replacement
  printf("Additional Reference Bits\n");
  fputs("----- Additional Reference Bits ------\n", g_OutFile);

  outMemReplaceInf();
  clearMemInf();
  printf("Additional Reference Bits Not Accessed.\n\n");

  // Second Chance Page Replacement
  printf("Second Chance\n");
  fputs("----- Second Chance ------------------\n", g_OutFile);

  outMemReplaceInf();
  clearMemInf();
  printf("Second Chance Not Accessed.\n\n");

  // Least Frequently Used Page Replacement
  printf("Least Frequently Used\n");
  fputs("----- Least Frequently Used ----------\n", g_OutFile);
//	LFU(g_PageFrame);
  outMemReplaceInf();
  clearMemInf();
  printf("Least Frequently Used Not Accessed.\n\n");

  // Most Frequently Used Page Replacement
  printf("Most Frequently Used\n");
  fputs("----- Most Frequently Used -----------\n", g_OutFile);

  outMemReplaceInf();
  clearMemInf();
  printf("Most Frequently Used Not Accessed.\n\n");

  fclose(g_InFile);
  fclose(g_OutFile);

  return 0;

} // end main


void getPageFrame(FILE* pDataFile)
{
  if( fgets(g_StrBuf, MAX_SIZE, pDataFile) != NULL) {
    g_PageFrame = atoi(g_StrBuf);

  } // end if

} // end getPageFrame

void getPageRefOrder(FILE* pDataFile)
{
  int mChar, mCount;
  mCount = 0;

  do {
  	mChar = fgetc(pDataFile);

  	// convert char to int and store in g_PageRefOrder
  	switch(mChar) {
  	  case '0' :
  	  	g_PageRefOrder[mCount] = 0;
  	  	break;

  	  case '1' :
  	  	g_PageRefOrder[mCount] = 1;
  	  	break;

  	  case '2' :
  	  	g_PageRefOrder[mCount] = 2;
  	  	break;

  	  case '3' :
  	  	g_PageRefOrder[mCount] = 3;
  	  	break;

  	  case '4' :
  	  	g_PageRefOrder[mCount] = 4;
  	  	break;

  	  case '5' :
  	  	g_PageRefOrder[mCount] = 5;
  	  	break;

  	  case '6' :
  	  	g_PageRefOrder[mCount] = 6;
  	  	break;

  	  case '7' :
  	  	g_PageRefOrder[mCount] = 7;
  	  	break;

  	  case '8' :
  	  	g_PageRefOrder[mCount] = 8;
  	  	break;

  	  case '9' :
  	  	g_PageRefOrder[mCount] = 9;
  	  	break;

  	  default :
  	  	mCount--;
  	  	break;

	} // end switch

  	mCount++;

  } while(mChar != EOF); // end do-while

  g_PageRefOrder[mCount] = END_SIGN;

} // end getPageRefOrder

void outMemReplaceInf(void)
{
  printf("Page Fault : %d\n", g_PageFault);
  strcpy(g_OutBuf, "Page Fault : ");
  itoa(g_PageFault, g_StrBuf, 10);
  strcat(g_OutBuf, g_StrBuf);
  fputs(g_OutBuf, g_OutFile);
  fputs("\n", g_OutFile);

  printf("Page Replaces : %d\n", g_PageReplace);
  strcpy(g_OutBuf, "Page Replaces : ");
  itoa(g_PageReplace, g_StrBuf, 10);
  strcat(g_OutBuf, g_StrBuf);
  fputs(g_OutBuf, g_OutFile);
  fputs("\n", g_OutFile);

  printf("Page Frames : %d\n", g_PageFrame);
  strcpy(g_OutBuf, "Page Frames : ");
  itoa(g_PageFrame, g_StrBuf, 10);
  strcat(g_OutBuf, g_StrBuf);
  fputs(g_OutBuf, g_OutFile);
  printf("\n\n");
  fputs("\n\n", g_OutFile);

} // end outMemReplaceInf

void initMemPage(MEM_REF* memoryPage)
{
  for(int CNT = 0; CNT < g_PageFrame; CNT++) {
  	memoryPage[CNT].PageData = -1;
  	memoryPage[CNT].UsedTimes = 0;
  	memoryPage[CNT].AccessTimes = 0;

  } // end for

} // END initMemPage

void clearMemInf(void)
{
	g_PageFault = 0;
  g_PageReplace = 0;

} // end clearMemInf

void FIFO(const int pageFrame)
{
  int mCount1, mCount2, mFaultFlag, mFreeSpace;
  MEM_REF MemBuf;

  MEM_REF* memoryPage = (MEM_REF*) malloc(sizeof(MEM_REF) * pageFrame);

  // initial memoryPage
  for(mCount1 = 0; mCount1 < pageFrame; mCount1++) {
  	memoryPage[mCount1].PageData = -1;
  	memoryPage[mCount1].UsedTimes = 0;
  	memoryPage[mCount1].AccessTimes = 0;

  } // end for

  // Page Replacement in Reference order
  for(mCount1 = 0; g_PageRefOrder[mCount1] != END_SIGN; mCount1++) {

		// Search page reference in memory
  	for(mCount2 = 0; mCount2 < pageFrame; mCount2++) {

  		if(memoryPage[mCount2].PageData == g_PageRefOrder[mCount1]) {
  			mFaultFlag = 0;
  			break;

  		} // end if
  		else {
  			mFaultFlag = 1;

  		} // end else

  	}

  	if(mFaultFlag == 1) {

  		g_PageFault++;

		} // end if

		// Check free space in memroy
		for(mCount2 = 0; mCount2 < pageFrame; mCount2++) {

			if(memoryPage[mCount2].PageData != 0) {
				mFreeSpace = 0;

			} // end if
			else {
				mFreeSpace = 1;
  	    break;

			}

		} // end for

		// Page reference swape into memory free space
		if(mFreeSpace == 1) {

			// Move page reference back one block in memory
			for(mCount2 = pageFrame - 1; mCount2 >= 0; mCount2--) {

				MemBuf = memoryPage[mCount2];
				memoryPage[mCount2 + 1] = MemBuf;

			}

			memoryPage[0].PageData = g_PageRefOrder[mCount1];
	  	memoryPage[0].UsedTimes = memoryPage[0].UsedTimes + 1;
	  	memoryPage[0].AccessTimes = mCount1;

		} // end if

		// Page Replacement
		if(mFaultFlag == 1 && (mFreeSpace == 0)) {

			// Move page reference back one block in memory
			for(mCount2 = pageFrame - 1; mCount2 >= 0; mCount2--) {

				MemBuf = memoryPage[mCount2];
				memoryPage[mCount2 + 1] = MemBuf;

			}

			memoryPage[0].PageData = g_PageRefOrder[mCount1];
	  	memoryPage[0].UsedTimes = memoryPage[0].UsedTimes + 1;
	  	memoryPage[0].AccessTimes = mCount1;

	  	g_PageReplace++;

		} // end if

		// Print out the memory page frame
//		printf("%d\t", g_PageRefOrder[mCount1]);
		itoa(g_PageRefOrder[mCount1], g_StrBuf, 10);
		strcat(g_StrBuf, "\t");
		fputs(g_StrBuf, g_OutFile);
		strcpy(g_OutBuf, "");
		for(mCount2 = 0; mCount2 < pageFrame; mCount2++) {

//			printf("%d", memoryPage[mCount2].PageData);
			itoa(memoryPage[mCount2].PageData, g_StrBuf, 10);
			strcat(g_OutBuf, g_StrBuf);

		} // end for
//		printf("\t");
		strcat(g_OutBuf, "\t");
		fputs(g_OutBuf, g_OutFile);
		if(mFaultFlag == 1) {

//			printf("F");
			fputs("F\n", g_OutFile);

		} // end if
		else {
			fputs("\n", g_OutFile);
		} // end if
//		printf("\n");

  } // end for

  fputs("\n", g_OutFile);

  free(memoryPage);

} // end FIFO

void LRU(const int pageFrame)
{
  int mCount1, mCount2, mFaultFlag, mFreeSpace;
	int mLeastAccess, mReplacePage;
  MEM_REF MemBuf;

  MEM_REF* memoryPage = (MEM_REF*) malloc(sizeof(MEM_REF) * pageFrame);

  // initial memoryPage
  for(mCount1 = 0; mCount1 < pageFrame; mCount1++) {
  	memoryPage[mCount1].PageData = -1;
  	memoryPage[mCount1].UsedTimes = 0;
  	memoryPage[mCount1].AccessTimes = 0;

  } // end for

  // Page Replacement in Reference order
  for(mCount1 = 0; g_PageRefOrder[mCount1] != END_SIGN; mCount1++) {

	// Search page reference in memory
  	for(mCount2 = 0; mCount2 < pageFrame; mCount2++) {

  	  if(memoryPage[mCount2].PageData == g_PageRefOrder[mCount1]) {
  	  	memoryPage[mCount2].PageData = g_PageRefOrder[mCount1];
	  		memoryPage[mCount2].UsedTimes = memoryPage[0].UsedTimes + 1;
	  		memoryPage[mCount2].AccessTimes = mCount1;
  			mFaultFlag = 0;
  			break;

  	  } // end if
      else {
  			mFaultFlag = 1;

  	  } // end else

  	}

  	if(mFaultFlag == 1) {

  		g_PageFault++;

		} // end if

		// Check free space in memroy
		for(mCount2 = 0; mCount2 < pageFrame; mCount2++) {

			if(memoryPage[mCount2].PageData != 0) {
				mFreeSpace = 0;

			} // end if
			else {
				mFreeSpace = 1;
  	   	break;

			} // end else

		} // end for

		// Page reference swape into memory free space
		if(mFreeSpace == 1) {

			// Move page reference back one block in memory
			for(mCount2 = pageFrame - 1; mCount2 >= 0; mCount2--) {

				MemBuf = memoryPage[mCount2];
				memoryPage[mCount2 + 1] = MemBuf;

			}

			memoryPage[0].PageData = g_PageRefOrder[mCount1];
	  	memoryPage[0].UsedTimes = memoryPage[0].UsedTimes + 1;
	  	memoryPage[0].AccessTimes = mCount1;

		} // end if

		// Page Replacement
		if(mFaultFlag == 1 && (mFreeSpace == 0)) {

			mLeastAccess = mCount1;

			// Search for Least Recently Used
			for(mCount2 = 0; mCount2 < pageFrame; mCount2++) {

				if(mLeastAccess > memoryPage[mCount2].AccessTimes) {

					mLeastAccess = memoryPage[mCount2].AccessTimes;
					mReplacePage = mCount2;

				} // end if

			} // end for

			memoryPage[mReplacePage].PageData = g_PageRefOrder[mCount1];
	  	memoryPage[mReplacePage].UsedTimes = memoryPage[0].UsedTimes + 1;
	  	memoryPage[mReplacePage].AccessTimes = mCount1;

			g_PageReplace++;

		} // end if

		// Print out the memory page frame
//		printf("%d\t", g_PageRefOrder[mCount1]);
		itoa(g_PageRefOrder[mCount1], g_StrBuf, 10);
		strcat(g_StrBuf, "\t");
		fputs(g_StrBuf, g_OutFile);
		strcpy(g_OutBuf, "");
		for(mCount2 = 0; mCount2 < pageFrame; mCount2++) {

//			printf("%d", memoryPage[mCount2].PageData);
			itoa(memoryPage[mCount2].PageData, g_StrBuf, 10);
			strcat(g_OutBuf, g_StrBuf);

		} // end for
//		printf("\t");
		strcat(g_OutBuf, "\t");
		fputs(g_OutBuf, g_OutFile);
		if(mFaultFlag == 1) {

//			printf("F");
			fputs("F\n", g_OutFile);

		} // end if
		else {
			fputs("\n", g_OutFile);
		} // end if
//		printf("\n");

  } // end for

  fputs("\n", g_OutFile);

  free(memoryPage);

} // end LRU

void LFU(const int pageFrame)
{
  int mCount1, mCount2, mFaultFlag, mFreeSpace;
	int mLeastUsed, mReplacePage;
  MEM_REF MemBuf;

  MEM_REF* memoryPage = (MEM_REF*) malloc(sizeof(MEM_REF) * pageFrame);

  // initial memoryPage
  for(mCount1 = 0; mCount1 < pageFrame; mCount1++) {
  	memoryPage[mCount1].PageData = 0;
  	memoryPage[mCount1].UsedTimes = 0;
  	memoryPage[mCount1].AccessTimes = 0;

  } // end for

  // Page Replacement in Reference order
  for(mCount1 = 0; g_PageRefOrder[mCount1] != END_SIGN; mCount1++) {

	// Search page reference in memory
  	for(mCount2 = 0; mCount2 < pageFrame; mCount2++) {

  	  if(memoryPage[mCount2].PageData == g_PageRefOrder[mCount1]) {
  	  	memoryPage[mCount2].PageData = g_PageRefOrder[mCount1];
	  		memoryPage[mCount2].UsedTimes = memoryPage[0].UsedTimes + 1;
	  		memoryPage[mCount2].AccessTimes = mCount1;
  			mFaultFlag = 0;
  			break;

  	  } // end if
      else {
  			mFaultFlag = 1;

  	  } // end else

  	}

  	if(mFaultFlag == 1) {

  		g_PageFault++;

		} // end if

		// Check free space in memroy
		for(mCount2 = 0; mCount2 < pageFrame; mCount2++) {

			if(memoryPage[mCount2].PageData != 0) {
				mFreeSpace = 0;

			} // end if
			else {
				mFreeSpace = 1;
  	   	break;

			} // end else

		} // end for

		// Page reference swape into memory free space
		if(mFreeSpace == 1) {

			// Move page reference back one block in memory
			for(mCount2 = pageFrame - 1; mCount2 >= 0; mCount2--) {

				MemBuf = memoryPage[mCount2];
				memoryPage[mCount2 + 1] = MemBuf;

			}

			memoryPage[0].PageData = g_PageRefOrder[mCount1];
	  	memoryPage[0].UsedTimes = memoryPage[0].UsedTimes + 1;
	  	memoryPage[0].AccessTimes = mCount1;

		} // end if

		// Page Replacement
		if(mFaultFlag == 1 && (mFreeSpace == 0)) {

			mLeastUsed = pageFrame;

			// Search for Least Frequently Used
			for(mCount2 = 0; mCount2 < pageFrame; mCount2++) {

				if(mLeastUsed > memoryPage[mCount2].UsedTimes) {

					mLeastUsed = memoryPage[mCount2].UsedTimes;
					mReplacePage = mCount2;

				} // end if

			} // end for

			memoryPage[mReplacePage].PageData = g_PageRefOrder[mCount1];
	  	memoryPage[mReplacePage].UsedTimes = 1;
	  	memoryPage[mReplacePage].AccessTimes = mCount1;

			g_PageReplace++;

		} // end if

		// Print out the memory page frame
//		printf("%d\t", g_PageRefOrder[mCount1]);
		itoa(g_PageRefOrder[mCount1], g_StrBuf, 10);
		strcat(g_StrBuf, "\t");
		fputs(g_StrBuf, g_OutFile);
		strcpy(g_OutBuf, "");
		for(mCount2 = 0; mCount2 < pageFrame; mCount2++) {

//			printf("%d", memoryPage[mCount2].PageData);
			itoa(memoryPage[mCount2].PageData, g_StrBuf, 10);
			strcat(g_OutBuf, g_StrBuf);

		} // end for
//		printf("\t");
		strcat(g_OutBuf, "\t");
		fputs(g_OutBuf, g_OutFile);
		if(mFaultFlag == 1) {

//			printf("F");
			fputs("F\n", g_OutFile);

		} // end if
//		printf("\n");

  } // end for

  fputs("\n", g_OutFile);

  free(memoryPage);

} // end LRU
