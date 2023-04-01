#include "flash.h"
#include "eeprom.h"
#include <string.h>

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Constants and macros
******************************************************************************/


/******************************************************************************
* Local types
******************************************************************************/

/******************************************************************************
* Local function prototypes
******************************************************************************/

/******************************************************************************
* Local variables
******************************************************************************/

/******************************************************************************
* Local functions
******************************************************************************/


/******************************************************************************
*
* EEPROM eeprom
*adr512bytes eeprom
*
******************************************************************************/
uint16_t Adress_Js(uint32_t adr)
{
    uint16_t err = EEPROM_ERR_SUCCESS;

  
    if(adr & 0x03)
    {
        err = EEPROM_ERR_INVALID_PARAM;
	return (err);
	}
  
    if(adr >1024)
    {
        err=EEPROM_ADR_OverFlow;
      return(err);
    }
    return(err);
}

/******************************************************************************
*
* EEPROM eeprom
*adr512bytes eeprom
*
******************************************************************************/


uint16_t EEPROM_Erase(uint32_t adr)
{
    uint16_t err = EEPROM_ERR_SUCCESS;
    uint32_t e_adr;

     if(adr & 0x03)
    {
        err = EEPROM_ERR_INVALID_PARAM;
	return (err);
	}
  
    if(adr >1024)
    {
        err=EEPROM_ADR_OverFlow;
    
      return(err);
    }
    
    e_adr=adr+EEPROM_START_ADR;
    err = Flash_EraseSector(e_adr);  
    return(err);
}

/******************************************************************************
*
* EEPROM eeprom
*
*
******************************************************************************/
uint32_t EEPROM_Read(uint32_t adr)
{
    uint16_t err = EEPROM_ERR_SUCCESS;
    uint32_t e_adr;
    uint32_t data;
    
    if(adr & 0x03)
    {
        err = EEPROM_ERR_INVALID_PARAM;
	return (err);
	}
  
    if(adr >1024)
    {
        err=EEPROM_ADR_OverFlow;
      return(err);
    }
    
    e_adr=adr+EEPROM_START_ADR;
    data = M32(e_adr);
    return(data);
    
}
/******************************************************************************
*
* EEPROM eeprom
*eeprom
*512bytes sectorsram
*flasheeprom
*
*
******************************************************************************/
uint16_t EEPROM_Write(uint32_t adr, uint32_t Data)
{
  
    uint32_t err = EEPROM_ERR_SUCCESS;
    uint32_t e_adr;
    uint32_t r_data;
    uint16_t i;
    uint32_t start_adr;
 //   uint32_t modify_adr;
    uint32_t EEPROM_DATA[128];

    if(adr & 0x03)
    {
        err = EEPROM_ERR_INVALID_PARAM;
	return (err);
	}
  
    if(adr >1024)
    {
        err=EEPROM_ADR_OverFlow;
      return(err);
    }

    
    r_data = EEPROM_Read(adr);
    
    e_adr=adr+EEPROM_START_ADR;

    if(r_data== EEPROM_BLANK) //
    {
      err= Flash_Program1LongWord(e_adr,Data);
    }
   else if((r_data&Data) == Data)//bit1
     {
      err= Flash_Program1LongWord(e_adr,Data);
    }
    else if(r_data == Data) //
    {
      return(err);
    }
    else
    {
        start_adr = e_adr & EEPROM_SECTOR_MASK; //sector    
        
        for( i=0;i<128;i++ ) //flashsram
        {
          EEPROM_DATA[i] = M32(start_adr + 4*i);
        }
            
        EEPROM_DATA[(adr&EEPROM_ARRAY_ADR_MASK)>>2] = Data; //SRAM 
        
        err=EEPROM_Erase(adr);
     
        err=Flash_Program(start_adr,(uint8_t*)EEPROM_DATA,512);//flash
    }
    return(err);
    
}

/******************************************************************************
*
*Byte 
*
******************************************************************************/
uint16_t EEPROM_WriteByte(uint32_t adr, uint8_t Data)
{
    uint32_t err = EEPROM_ERR_SUCCESS;
    uint32_t data_mask;
    uint32_t r_data;
    uint32_t data_m0;
    uint32_t data_m1;
    uint32_t word_adr = adr &0x3fc;
    uint32_t  b_sit= adr & 0x3;
    

 //FF
    data_m0 = Data << b_sit*8;   
    data_mask = 0xFFFFFFFF<<(b_sit+1)*8;    
//   printf("datam0:=0x%x \n",data_m0);    
//FF    
     data_m1 = 0xFFFFFFFF >> (32-b_sit*8);
     data_m1 = data_m1 | data_m0 | data_mask ;
     
//    printf("datam1:=0x%x \n",data_m1);  
    
    r_data = EEPROM_Read(word_adr);
//    printf("r_data:=0x%x \n",r_data);        
//    
    data_m1 = data_m1 & r_data;
		
    
//    printf("data_m1:=0x%x \n",data_m1);     ;           
    err = EEPROM_Write(word_adr , data_m1);
    
    return(err);

}

/******************************************************************************
*
*Byte 
*
******************************************************************************/
uint8_t EEPROM_ReadByte(uint32_t adr)
{
   uint32_t r_data;
   uint32_t word_adr = adr &0x3fc;
   uint32_t b_sit= adr & 0x3;
   uint8_t  data;
   
    r_data = EEPROM_Read(word_adr);
    data = (r_data>>b_sit*8)& 0xff;
    return(data);
   
   
}


/******************************************************************************
*
*bytesizeeeprom
*1keepromsram
*
*2K eeprom 2K 
******************************************************************************/
uint16_t EERPOM_Writeup4byte(uint32_t adr,uint8_t *pData,uint32_t length)
{
	uint8_t buf[512];
	uint8_t *pbuf;
	uint32_t e_adr;
	uint32_t e_sec;
	uint32_t e_offset;
	uint32_t a;
	uint32_t err = EEPROM_ERR_SUCCESS;
	
   #ifdef IAR
    if(adr & 0x03)
    {
        err = EEPROM_ERR_INVALID_PARAM;
	      return (err);
	   }
    #endif
  
    if((adr + length )>1024)
    {
        err=EEPROM_ADR_OverFlow;
      return(err);
    }
    
	e_adr=adr+EEPROM_START_ADR;
	e_sec=e_adr & EEPROM_SECTOR_MASK;
	e_offset=e_adr & 0x1ff;

	
	while (length>0){
          //0512 
		if (e_offset||(length<512)){
			pbuf=buf;
			a=512-e_offset;
			a=(length>a?a:length);
			
			memcpy(buf,(uint8_t*)e_sec,512);
			memcpy(&buf[e_offset],pData,a);
			pData+=a;
			length-=a;
			e_offset=0;

		}else{ //0512 
			pbuf=pData;
			pData+=512;
			length-=512;
		}
		err=Flash_EraseSector(e_sec);
		err=Flash_Program(e_sec,(uint8_t*)pbuf,512);//flash
		e_sec+=0x200;
	}
	return err;
}


/*
uint16_t EERPOM_Writeup4byte(uint32_t adr,uint8_t *pData,uint32_t bytesize)
{
    uint32_t err = EEPROM_ERR_SUCCESS;
    uint32_t e_adr;
    uint16_t i;
    uint32_t start_adr;
    uint32_t EEPROM_DATA[256];
    uint32_t longword = bytesize >>2;
    uint32_t *pwData = (uint32_t*)pData ;
    
    err=Adress_Js(adr);
    
    if(adr+bytesize >1024) //,1024
    {
      err = EEPROM_ADR_OverFlow;
      return(err);
    }
    
    e_adr=adr+EEPROM_START_ADR;
    
    start_adr = e_adr & EEPROM_SECTOR_MASK; //sector 

    for( i=0;i<256;i++ ) //sram
      {
        EEPROM_DATA[i] = M32(start_adr + 4*i);
        }
    for( i=0 ;i<longword ;i++) //
      {
        EEPROM_DATA[(adr>>2)+i] = *pwData++;
      }
     //erase2eeprom secoter     
     err=EEPROM_Erase(0x000);
     err=EEPROM_Erase(0x200);   
      
    err=Flash_Program(start_adr,(uint8_t*)EEPROM_DATA,1024);//flash
    
    return(err);
}
*/

