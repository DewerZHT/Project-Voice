/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2007        */
/*-----------------------------------------------------------------------*/
/* This is a stub disk I/O module that acts as front end of the existing */
/* disk I/O modules and attach it to FatFs module with common interface. */
/*-----------------------------------------------------------------------*/

/* Include  **/
#include <stm32f4xx.h>
/* Include STM32F4 periph driver **/
#include "stm32_SDIO.h"
/* Include Low Level Disk I/O driver **/
#include "diskio.h"


/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */

DSTATUS disk_initialize (
	BYTE drv				/* Physical drive nmuber (0..) */
)
{
    u8 state;

    if(drv)
    {
        return STA_NOINIT;  // only supprot disk 0 to access
    }

    state = SD_Init();
    if(state == STA_NODISK)
    {
        return STA_NODISK;
    }
    else if(state != 0)
    {
        return STA_NOINIT;  // the others exception : Initial Failure
    }
    else
    {
        return 0;           // initial success
    }
}



/*-----------------------------------------------------------------------*/
/* Return Disk Status                                                    */

DSTATUS disk_status (
	BYTE drv		/* Physical drive nmuber (0..) */
)
{
    if(drv)
    {
        return STA_NOINIT;  // 
    }

    // check is sd card inserted 
//    if(!SD_DET())
//    {
//        return STA_NODISK;
//    }
    return 0;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */

DRESULT disk_read (
	BYTE drv,		/* Physical drive nmuber (0..) */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	/* Sector address (LBA) */
	BYTE count		/* Number of sectors to read (1..255) */
)
{
	u8 res=0;
    if (drv || !count)
    {    
        return RES_PARERR;  /* only support single disk access,
														   count can;t be 0 (return value error) */
    }
//    if(!SD_DET())
//    {
//        return RES_NOTRDY;  // if not sensor sd card, retuen NOT READY exception
//    }

    
	
    if(count==1)            // read one sector    
    {                                                
        res = SD_ReadSingleBlock(sector, buff);      
    }                                                
    else                    // read multi sector     
    {                                                
        res = SD_ReadMultiBlock(sector, buff, count);
    }                                                
	/*
    do                           
    {                                          
        if(SD_ReadSingleBlock(sector, buff)!=0)
        {                                      
            res = 1;                           
            break;                             
        }                                      
        buff+=512;                             
    }while(--count);                                         
    */
    // return value convert to FATFS
    if(res == 0x00)
    {
        return RES_OK;
    }
    else
    {
        return RES_ERROR;
    }
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */

#if _READONLY == 0
DRESULT disk_write (
	BYTE drv,			/* Physical drive nmuber (0..) */
	const BYTE *buff,	/* Data to be written */
	DWORD sector,		/* Sector address (LBA) */
	BYTE count			/* Number of sectors to write (1..255) */
)
{
	u8 res;

    if (drv || !count)
    {    
        return RES_PARERR;  /* only support single disk access,
														   count can;t be 0 (return value error) */
    }
//    if(!SD_DET())
//    {
//        return RES_NOTRDY;  // if not sensor sd card, retuen NOT READY exception
//    }

    // read write access
    if(count == 1)
    {
        res = SD_WriteSingleBlock(sector, buff);
    }
    else
    {
        res = SD_WriteMultiBlock(sector, buff, count);
    }
		
    // return value convert to FATFS
    if(res == 0)
    {
        return RES_OK;
    }
    else
    {
        return RES_ERROR;
    }
}
#endif /* _READONLY */



/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */

DRESULT disk_ioctl (
	BYTE drv,		/* Physical drive nmuber (0..) */
	BYTE ctrl,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
    DRESULT res;


    if (drv)
    {    
        return RES_PARERR;  /* only support single disk access,
														   count can;t be 0 (return value error) */
    }
    
    // In this version, FATFS only need to process three instruction 
		// CTRL_SYNC¡AGET_SECTOR_COUNT¡AGET_BLOCK_SIZ
    switch(ctrl)
    {
    case CTRL_SYNC:
        SD_CS_ENABLE();
        if(SD_WaitReady()==0)
        {
            res = RES_OK;
        }
        else
        {
            res = RES_ERROR;
        }
        SD_CS_DISABLE();
        break;
        
    case GET_BLOCK_SIZE:
        *(WORD*)buff = 512;
        res = RES_OK;
        break;

    case GET_SECTOR_COUNT:
        *(DWORD*)buff = SD_GetCapacity();
        res = RES_OK;
        break;
    default:
        res = RES_PARERR;
        break;
    }

    return res;
}


/*-----------------------------------------------------------------------*/
/* User defined function to give a current time to fatfs module          */
/* 31-25: Year(0-127 org.1980), 24-21: Month(1-12), 20-16: Day(1-31) */                                                                                                                                                                                                                                          
/* 15-11: Hour(0-23), 10-5: Minute(0-59), 4-0: Second(0-29 *2) */                                                                                                                                                                                                                                                
DWORD get_fattime (void)
{
    //2013.04.02 18hr:30min:30sec. check if it's valid
    DWORD date=1115853775;

    return date;
}
							




