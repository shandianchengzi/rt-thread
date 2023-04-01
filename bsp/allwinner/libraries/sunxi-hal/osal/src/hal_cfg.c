/*
*********************************************************************************************************
*                                                    MELIS
*                                    the Easy Portable/Player Develop Kits
*                                                Config system
*
*                                    (c) Copyright 2011-2014, Sunny China
*                                             All Rights Reserved
*
* File    : sys_config.c
* By      : Sunny
* Version : v1.0
* Date    : 2011-4-28
* Descript: system config sevice functions.
* Update  : date                auther      ver     notes
*           2011-4-28 20:57:56  Sunny       1.0     Create this file.
*********************************************************************************************************
*/
#include "hal_cfg.h"

int32_t esCFG_GetKeyValue(char *SecName, char *KeyName, int32_t Value[], int32_t Count);
int32_t esCFG_GetGPIOSecKeyCount(char *GPIOSecName);
int32_t esCFG_GetGPIOSecData(char *GPIOSecName, void *pGPIOCfg, int32_t GPIONum);

#if 0
/*
*********************************************************************************************************
*                                       INITIALIZE CONFIG SYSTEM
*
* Description:
*
* Arguments  :
*
* Returns    :
*
* Note       :
*********************************************************************************************************
*/
int32_t Hal_Cfg_Init(uint8_t *CfgVAddr, uint32_t size)
{
    return esCFG_Init(CfgVAddr, size);
}

/*
*********************************************************************************************************
*                                       EXIT CONFIG SYSTEM
*
* Description:
*
* Arguments  :
*
* Returns    :
*
* Note       :
*********************************************************************************************************
*/
int32_t Hal_Cfg_Exit(void)
{
    return esCFG_Exit();
}
#endif

/*
*********************************************************************************************************
*                                       
*
* Description:
*
* Arguments  : main_name    
*
*              sub_name     
*
*              value        buffer
*
*              count        buffer
*
*
* Returns    : 
*
* Notes      :
*********************************************************************************************************
*/
int32_t Hal_Cfg_GetKeyValue(char *SecName, char *KeyName, int32_t Value[], int32_t Count)
{
    return  esCFG_GetKeyValue(SecName, KeyName, Value, Count);
}

#if 0
/*
*********************************************************************************************************
*                                       
*
* Description:
*
* Arguments  : main_name    
*
*
*
* Returns    : 
*              
*
* Notes      :
*********************************************************************************************************
*/
int32_t Hal_Cfg_GetSecKeyCount(char *SecName)
{
    return  esCFG_GetSecKeyCount(SecName);
}

/*
*********************************************************************************************************
*                                       
*
* Description:
*
* Arguments  :
*
*
*
* Returns    : 
*              
*
* Notes      :
*********************************************************************************************************
*/
int32_t Hal_Cfg_GetSecCount(void)
{
    return  esCFG_GetSecCount();
}
#endif
/*
*********************************************************************************************************
*                                       GPIO
*
* Description:
*
* Arguments  : main_name    
*
*
*
* Returns    : 
*              
*
* Notes      :
*********************************************************************************************************
*/
int32_t Hal_Cfg_GetGPIOSecKeyCount(char *GPIOSecName)
{
    return  esCFG_GetGPIOSecKeyCount(GPIOSecName);
}

/*
*********************************************************************************************************
*                                       GPIO
*
* Description:
*
* Arguments  : main_name    
*
*              gpio_cfg     GPIObuffer
*
*              gpio_count   GPIO
*
*
* Returns    : 
*              
*
* Notes      :
*********************************************************************************************************
*/
int32_t Hal_Cfg_GetGPIOSecData(char *GPIOSecName, void *pGPIOCfg, int32_t GPIONum)
{
    return  esCFG_GetGPIOSecData(GPIOSecName, pGPIOCfg, GPIONum);
}
