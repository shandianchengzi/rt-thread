/********************************** (C) COPYRIGHT *******************************
* File Name          : CH57x_flash.c
* Author             : WCH
* Version            : V1.1
* Date               : 2020/03/20
* Description        :
*******************************************************************************/

/******************************************************************************/
/*  */
#include "CH57x_common.h"

/* Flash */
#define CODEFLASH_SAFE_FLAG1          0x57
#define CODEFLASH_SAFE_FLAG2          0xA8

/* Flash */
unsigned char codeflash_access_flag1 = 0x0;
unsigned char codeflash_access_flag2 = 0x0;

/*******************************************************************************
* Function Name  : GetUniqueID
* Description    : ID6B-ID 2B-CKS
* Input          : buf: 86ID2
* Return         : None
*******************************************************************************/
void GetUniqueID(PUINT8 buf)
{
    PUINT8  pID;
    UINT8   i;

    pID = (PUINT8)ROM_UUID_ADDR;
    for(i=0; i<8; i++) *buf++ = *pID++;
}

/*******************************************************************************
* Function Name  : GetMACAddress
* Description    : MAC6B-MAC
* Input          : buf: 66 MAC
* Return         : None
*******************************************************************************/
void GetMACAddress(PUINT8 buf)
{
    PUINT8  pMAC;
    UINT8   i;

    pMAC = (PUINT8)ROM_MAC_ADDR;
    for(i=0; i<6; i++) *buf++ = *pMAC++;
}

/*******************************************************************************
* Function Name  : FlashBlockErase
* Description    : Flash 512B
* Input          : addr: 32512
*                       codeflash:  startAddr - 0x00000000    size - 0x3E800
*                       dataflash:  startAddr - 0x3E800(DATA_FLASH_ADDR)       size -  0x0800(DATA_FLASH_SIZE)
* Return         : 0 -   - 
*******************************************************************************/
UINT8 FlashBlockErase(UINT32 addr)
{
    UINT8  status = 0;
    volatile UINT8  op_step;

    if( addr & (0x200-1) )          return 1;  //

    op_step = 0x11;
    codeflash_access_flag1 = 0;
    codeflash_access_flag2 = 0;
    R8_FLASH_PROTECT = RB_ROM_WE_MUST_10;

    //
    op_step += 0x11;
    if((R8_BAT_DET_CTRL & 0x0F) != 0x0D)        PowerMonitor( ENABLE );

    op_step += 0x11;
    if((R8_BAT_STATUS & 0x03) != 0x00)      return 2;  //Flash

    op_step += 0x11;
    if(((R8_BAT_STATUS & 0x03) == 0x00)
        &&(op_step == 0x44))
    {
        codeflash_access_flag1 = CODEFLASH_SAFE_FLAG1;
    }

    op_step += 0x11;
    if(((R8_BAT_STATUS & 0x03) == 0x00)
        &&(op_step == 0x55)
        &&(codeflash_access_flag1 == CODEFLASH_SAFE_FLAG1))
    {
        codeflash_access_flag2 = CODEFLASH_SAFE_FLAG2;
    }

    op_step += 0x11;
    if((codeflash_access_flag1 == CODEFLASH_SAFE_FLAG1)
     &&(codeflash_access_flag2 == CODEFLASH_SAFE_FLAG2)
     &&(op_step == 0x66))
    {
        R32_FLASH_ADDR = addr;
        if( addr < DATA_FLASH_ADDR  )    R8_FLASH_PROTECT = RB_ROM_WE_MUST_10|RB_ROM_CODE_WE;   // Codefalsh
        else       R8_FLASH_PROTECT = RB_ROM_WE_MUST_10|RB_ROM_DATA_WE;         // datafalsh
    }

    op_step += 0x11;
    /* Flash */
    if((codeflash_access_flag1 == CODEFLASH_SAFE_FLAG1)
     &&(codeflash_access_flag2 == CODEFLASH_SAFE_FLAG2)
     &&(op_step == 0x77))
    {
        R8_FLASH_COMMAND = ROM_CMD_ERASE;
        status = (unsigned char)(R16_FLASH_STATUS & 0xff);
    }

    op_step = 0x00;
    codeflash_access_flag1 = 0x00;
    codeflash_access_flag2 = 0x00;
    R8_FLASH_PROTECT = RB_ROM_WE_MUST_10;       // LOCK

    if( status != RB_ROM_ADDR_OK )  return 3;   //
    return 0;
}

/*******************************************************************************
* Function Name  : FlashWriteDW
* Description    : Flash 4
* Input          : addr: 324
*                       codeflash:  startAddr - 0x00000000    size - 0x3E800
*                       dataflash:  startAddr - 0x3E800(DATA_FLASH_ADDR)       size -  0x0800(DATA_FLASH_SIZE)
                    dat: 32
* Return         : FAILED  - 
                   SUCCESS - 
*******************************************************************************/
UINT8 FlashWriteDW(UINT32 addr, UINT32 dat)
{
    UINT32  add = addr;
    UINT32  val = dat;
    UINT8  status = 0;
    volatile UINT8  op_step;

    if( addr & (4-1) )              return 1; //

    op_step = 0x11;
    codeflash_access_flag1 = 0;
    codeflash_access_flag2 = 0;
    R8_FLASH_PROTECT = RB_ROM_WE_MUST_10;

    //
    op_step += 0x11;
    if((R8_BAT_DET_CTRL & 0x0F) != 0x0D)        PowerMonitor( ENABLE );

    op_step += 0x11;
    if((R8_BAT_STATUS & 0x03) != 0x00)      return 2;  //Flash

    op_step += 0x11;
    if(((R8_BAT_STATUS & 0x01) == 0x00)
        &&(op_step == 0x44))
    {
        codeflash_access_flag1 = CODEFLASH_SAFE_FLAG1;
    }

    op_step += 0x11;
    if(((R8_BAT_STATUS & 0x01) == 0x00)
        &&(op_step == 0x55)
        &&(codeflash_access_flag1 == CODEFLASH_SAFE_FLAG1))
    {
        codeflash_access_flag2 = CODEFLASH_SAFE_FLAG2;
    }

    op_step += 0x11;
    if((codeflash_access_flag1 == CODEFLASH_SAFE_FLAG1)
     &&(codeflash_access_flag2 == CODEFLASH_SAFE_FLAG2)
     &&(op_step == 0x66))
    {
        if( addr < DATA_FLASH_ADDR  )    R8_FLASH_PROTECT = RB_ROM_WE_MUST_10|RB_ROM_CODE_WE;   // Codefalsh
        else       R8_FLASH_PROTECT = RB_ROM_WE_MUST_10|RB_ROM_DATA_WE;         // datafalsh
    }

    op_step += 0x11;
    /* OTAFlash */
    if((codeflash_access_flag1==CODEFLASH_SAFE_FLAG1)
     &&(codeflash_access_flag2==CODEFLASH_SAFE_FLAG2)
     &&(op_step == 0x77))
    {
        R32_FLASH_ADDR = add;
        R32_FLASH_DATA = val;
        R8_FLASH_COMMAND = ROM_CMD_PROG;
        status = (unsigned char)(R16_FLASH_STATUS & 0xff);
    }

    op_step = 0x00;
    codeflash_access_flag1 = 0x00;
    codeflash_access_flag2 = 0x00;
    R8_FLASH_PROTECT = RB_ROM_WE_MUST_10;
    if( status != RB_ROM_ADDR_OK )  return 3;  //

    return 0;

}

/*******************************************************************************
* Function Name  : FlashWriteBuf
* Description    : Flash 
* Input          : addr: 324
*                       codeflash:  startAddr - 0x00000000    size - 0x3E800
*                       dataflash:  startAddr - 0x3E800(DATA_FLASH_ADDR)       size -  0x0800(DATA_FLASH_SIZE)
*                  pdat: 
*                   len: 
* Return         : 0 -   - 
*******************************************************************************/
UINT8 FlashWriteBuf(UINT32 addr, PUINT32 pdat, UINT16 len)
{
    UINT32  add = addr;
    PUINT32 p32 = pdat;
    UINT8  status = 0;
    UINT16  i;
    volatile UINT8  op_step;

    if( addr & (4-1) )              return 1; //

    op_step = 0x11;
    codeflash_access_flag1 = 0;
    codeflash_access_flag2 = 0;
    R8_FLASH_PROTECT = RB_ROM_WE_MUST_10;

    //
    op_step += 0x11;
    if((R8_BAT_DET_CTRL & 0x0F) != 0x0D)        PowerMonitor( ENABLE );

    op_step += 0x11;
    if((R8_BAT_STATUS & 0x03) != 0x00)      return 2;  //Flash

    op_step += 0x11;
    if(((R8_BAT_STATUS & 0x01) == 0x00)
        &&(op_step == 0x44))
    {
        codeflash_access_flag1 = CODEFLASH_SAFE_FLAG1;
    }

    op_step += 0x11;
    if(((R8_BAT_STATUS & 0x01) == 0x00)
        &&(op_step == 0x55)
        &&(codeflash_access_flag1 == CODEFLASH_SAFE_FLAG1))
    {
        codeflash_access_flag2 = CODEFLASH_SAFE_FLAG2;
    }

    op_step += 0x11;
    if((codeflash_access_flag1 == CODEFLASH_SAFE_FLAG1)
     &&(codeflash_access_flag2 == CODEFLASH_SAFE_FLAG2)
     &&(op_step == 0x66))
    {
        if( addr < DATA_FLASH_ADDR  )    R8_FLASH_PROTECT = RB_ROM_WE_MUST_10|RB_ROM_CODE_WE;   // Codefalsh
        else       R8_FLASH_PROTECT = RB_ROM_WE_MUST_10|RB_ROM_DATA_WE;         // datafalsh
    }

    op_step += 0x11;
    /* OTAFlash */
    if((codeflash_access_flag1==CODEFLASH_SAFE_FLAG1)
     &&(codeflash_access_flag2==CODEFLASH_SAFE_FLAG2)
     &&(op_step == 0x77))
    {
        for(i=0; i<len; i+=4)
        {
            R32_FLASH_ADDR = add;
            R32_FLASH_DATA = *p32++;
            R8_FLASH_COMMAND = ROM_CMD_PROG;
            add += 4;
            //status = R8_FLASH_STATUS;
            status = (unsigned char)(R16_FLASH_STATUS & 0xff);
            if( status != RB_ROM_ADDR_OK )  break;
        }
    }

    op_step = 0x00;
    codeflash_access_flag1 = 0x00;
    codeflash_access_flag2 = 0x00;
    R8_FLASH_PROTECT = RB_ROM_WE_MUST_10;
    if( status != RB_ROM_ADDR_OK )  return 3;  //

    return 0;
}



