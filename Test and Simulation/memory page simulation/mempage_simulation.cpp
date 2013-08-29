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
 *      3. Output memory information - outMemInf
 *      4. Clear memory information  - clearMemInf
 *      5. Initial memory page       - initMemPage
 *      6. Output memory page        - outMemPage
 *
**/

/** includes             ******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/** includes             ******************************************************/
#define MAX_SIZE 200
#define END_SIGN -1

/** Data-type definition ******************************************************/
typedef char STRING[MAX_SIZE];
typedef struct MemoryPageReference {
  int PageData;
  int UsedTimes;
  int AccessTimes;

} MEM_REF;

/** Global variables     ******************************************************/
FILE*  gInOutFile;
STRING gStrBuf;
int    gPageFrame, gPageFault, gPageReplace;
int    gPageRequest[MAX_SIZE];
int    gPageFaultFlag = 0;
int    gFreePage = 1;

/** Function declaration ******************************************************/
// Utility methods function
void getPageFrame(void);
void getPageRequest(void);
void outMemInf(void);
void clearMemInf(void);
void initMemPage(MEM_REF* memoryPage);
void outMemPage(int newMemRequest, MEM_REF* memoryPage);
void checkPageFault(int requestMemData, MEM_REF* memoryPage);
void checkFreePage(MEM_REF* memoryPage);
void shiftMemPage(MEM_REF* memoryPage);
// Memory page replacement methods function
void FIFO(MEM_REF* memoryPage);

int main(void)
{
  // open input file.
  printf("Enter input file name :\n");
  scanf("%s", gStrBuf);
  printf("\n");
  gInOutFile = fopen(gStrBuf, "r");

  if(gInOutFile != NULL) {
    printf("File : %s opened success.\n", gStrBuf);

  } // end if
  else {
    printf("File : %s could not be opened, or not exists.\n", gStrBuf);
	  printf("Program terminated.\n");

	  return 0;

  } // end else

  // Get page frame value
  getPageFrame();
  printf("Page frame : %d\n", gPageFrame);

  // Get page request
  getPageRequest();
  // print out page request
  printf("Page request : ");
  for(int CNT = 0; gPageRequest[CNT] != END_SIGN; CNT++)
    printf("%d ", gPageRequest[CNT]);
  printf("\n");

  // Close input file
  fclose(gInOutFile);

  // Declaration memory page reference
  MEM_REF* memoryPage = (MEM_REF*) malloc(sizeof(MEM_REF) * gPageFrame);
  // Initial memory page
  initMemPage(memoryPage);
  // Output memory page and information
  outMemPage(0, memoryPage);
  printf("\n");
  outMemInf();

  // Reset memory information and memory page
  clearMemInf();
  initMemPage(memoryPage);

  // Method First In First Out
  printf("----- First In First Out -------------\n");
  FIFO(memoryPage);
  outMemInf();

  return 0;

} // END main

void getPageFrame(void)
{
  if( fgets(gStrBuf, MAX_SIZE, gInOutFile) != NULL) {
    gPageFrame = atoi(gStrBuf);

  } // end if

} // END getPageFrame

void getPageRequest(void)
{
  int mChar, mCount;
  mCount = 0;

  do {
  	mChar = fgetc(gInOutFile);

  	// convert char to int and store in gPageRequest
  	switch(mChar) {
  	  case '0' :
  	  	gPageRequest[mCount] = 0;
  	  	break;

  	  case '1' :
  	  	gPageRequest[mCount] = 1;
  	  	break;

  	  case '2' :
  	  	gPageRequest[mCount] = 2;
  	  	break;

  	  case '3' :
  	  	gPageRequest[mCount] = 3;
  	  	break;

  	  case '4' :
  	  	gPageRequest[mCount] = 4;
  	  	break;

  	  case '5' :
  	  	gPageRequest[mCount] = 5;
  	  	break;

  	  case '6' :
  	  	gPageRequest[mCount] = 6;
  	  	break;

  	  case '7' :
  	  	gPageRequest[mCount] = 7;
  	  	break;

  	  case '8' :
  	  	gPageRequest[mCount] = 8;
  	  	break;

  	  case '9' :
  	  	gPageRequest[mCount] = 9;
  	  	break;

  	  default :
  	  	mCount--;
  	  	break;

	} // end switch

  	mCount++;

  } while(mChar != EOF); // end do-while

  gPageRequest[mCount] = END_SIGN;

} // END getPageRequest

void clearMemInf(void)
{
  gPageFault = 0;
  gPageReplace = 0;

} // END clearMemInf

void initMemPage(MEM_REF* memoryPage)
{
  for(int CNT = 0; CNT < gPageFrame; CNT++) {
  	memoryPage[CNT].PageData = -1;
  	memoryPage[CNT].UsedTimes = -1;
  	memoryPage[CNT].AccessTimes = -1;

  } // end for

} // END initMemPage

void outMemPage(int newMemRequest, MEM_REF* memoryPage)
{
  printf("%d\t", newMemRequest);

  for(int CNT = 0; CNT < gPageFrame; CNT++) {
    if(memoryPage[CNT].PageData == -1)
      printf(" ");
    else
      printf("%d", memoryPage[CNT].PageData);

  } // end for all memory page

  if(gPageFaultFlag) {
    printf("\tF\n");

  } // END if Page Fault
  else {
    printf("\n");
  }

} // END outMemPage

void outMemInf(void)
{
  printf("Page Fault = %d\n", gPageFault);
  printf("Page Replace = %d\n", gPageReplace);
  printf("Page Frame = %d\n", gPageFrame);

} // END outMemInf

void checkPageFault(int requestMemData, MEM_REF* memoryPage)
{
  // Search page reference in memory
  for(int CNT = 0; CNT < gPageFrame; CNT++) {

    if(memoryPage[CNT].PageData == requestMemData) {
      gPageFaultFlag = 0;

    } // end if
    else {
      gPageFaultFlag = 1;

    } // end else

  } // END for

} // END checkPageFault

void checkFreePage(MEM_REF* memoryPage)
{
  // Search page reference in memory
  for(int CNT = 0; CNT < gPageFrame; CNT++) {

    if(memoryPage[CNT].PageData == -1) {
      gFreePage = 1;

    } // end if
    else {
      gFreePage = 0;

    } // end else

  } // END for

} // END checkFreePage

void shiftMemPage(MEM_REF* memoryPage)
{
  MEM_REF  MemBuf;

  // Move page reference forward one block in memory
  for(int CNT = gPageFrame - 1; CNT >= 0; CNT--) {

    MemBuf = memoryPage[CNT];
    memoryPage[CNT + 1] = MemBuf;

  }

  memoryPage[0].PageData = 0;
  memoryPage[0].UsedTimes = 0;
  memoryPage[0].AccessTimes = 0;

} // END shiftMemPage

void FIFO(MEM_REF* memoryPage)
{
  for(int CNT = 0; gPageRequest[CNT] != END_SIGN; CNT++) {

    checkPageFault(gPageRequest[CNT], memoryPage);

    if(gPageFaultFlag) {

      gPageFault++;
      checkFreePage(memoryPage);

      if(gFreePage) {

        shiftMemPage(memoryPage);
        memoryPage[0].PageData = gPageRequest[CNT];
        memoryPage[0].UsedTimes = 0;
        memoryPage[0].AccessTimes = 0;

      } // END if memory have free page
      else {

        shiftMemPage(memoryPage);
        memoryPage[0].PageData = gPageRequest[CNT];
        memoryPage[0].UsedTimes = 0;
        memoryPage[0].AccessTimes = 0;
        gPageReplace++;

      } // END else memory do not have free page

    } // END if Page Fault

    // Print out memory page
    outMemPage(gPageRequest[CNT], memoryPage);

  } // END for memory page request

} // END FIFO
