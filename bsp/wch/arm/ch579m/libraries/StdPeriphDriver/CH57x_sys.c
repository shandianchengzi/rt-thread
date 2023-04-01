/********************************** (C) COPYRIGHT *******************************
* File Name          : CH57x_SYS.c
* Author             : WCH
* Version            : V1.0
* Date               : 2018/12/15
* Description
*******************************************************************************/

#include "CH57x_common.h"


/*******************************************************************************
* Function Name  : SYS_GetInfoSta
* Description    : 
* Input          : i:
                    refer to SYS_InfoStaTypeDef
* Return         : DISABLE  -  
                   ENABLE   -  
*******************************************************************************/
UINT8 SYS_GetInfoSta( SYS_InfoStaTypeDef i )
{
    if(i == STA_SAFEACC_ACT)
        return (R8_SAFE_ACCESS_SIG & RB_SAFE_ACC_ACT);
    else
        return (R8_GLOB_CFG_INFO&(1<<i));
}

/*******************************************************************************
* Function Name  : SYS_ResetExecute
* Description    : 
* Input          : None
* Return         : None
*******************************************************************************/
void SYS_ResetExecute( void )
{
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    R8_RST_WDOG_CTRL |= RB_SOFTWARE_RESET;
    R8_SAFE_ACCESS_SIG = 0;
}

/*******************************************************************************
* Function Name  : SYS_DisableAllIrq
* Description    : 
* Input          : pirqv
* Return         : None
*******************************************************************************/
void SYS_DisableAllIrq( PUINT32 pirqv)
{
    *pirqv = NVIC->ISER[0];
    NVIC->ICER[0] = 0xffffffff;
}

/*******************************************************************************
* Function Name  : SYS_RecoverIrq
* Description    : 
* Input          : irq_status
* Return         : None
*******************************************************************************/
void SYS_RecoverIrq( UINT32 irq_status )
{
    NVIC->ISER[0] = irq_status;
}

/*******************************************************************************
* Function Name  : SYS_GetSysTickCnt
* Description    : (SYSTICK)
* Input          : None
* Return         : 
*******************************************************************************/
UINT32 SYS_GetSysTickCnt( void )
{
    return(SysTick->VAL );
}

/*******************************************************************************
* Function Name  : WWDG_ITCfg
* Description    : 
* Input          : DISABLE-      ENABLE-
* Return         : None
*******************************************************************************/
void  WWDG_ITCfg( UINT8 s )
{
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    if(s == DISABLE)        R8_RST_WDOG_CTRL&=~RB_WDOG_INT_EN;
    else                    R8_RST_WDOG_CTRL|=RB_WDOG_INT_EN;
    R8_SAFE_ACCESS_SIG = 0;
}

/*******************************************************************************
* Function Name  : WWDG_ResetCfg
* Description    : 
* Input          : DISABLE-      ENABLE-
* Return         : None
*******************************************************************************/
void WWDG_ResetCfg( UINT8 s )
{
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    if(s == DISABLE)        R8_RST_WDOG_CTRL&=~RB_WDOG_RST_EN;
    else                    R8_RST_WDOG_CTRL|=RB_WDOG_RST_EN;
    R8_SAFE_ACCESS_SIG = 0;
}

/*******************************************************************************
* Function Name  : WWDG_ClearFlag
* Description    : 
* Input          : None
* Return         : None
*******************************************************************************/
void WWDG_ClearFlag( void )
{
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    R8_RST_WDOG_CTRL |= RB_WDOG_INT_FLAG;
    R8_SAFE_ACCESS_SIG = 0;
}


/*******************************************************************************
* Function Name  : mDelayuS
* Description    : uS 
* Input          : t: 
* Return         : None
*******************************************************************************/
void mDelayuS( UINT16 t )
{
    UINT16 i, j;

    for(j=0; j<t; j++)
    {

#if     (FREQ_SYS == 40000000)
    for(i=0; i<4; i++)      __nop();

#elif       (FREQ_SYS == 32000000)
    i = 2;
    while(i--)  { __nop();  __nop(); }

#elif       (FREQ_SYS == 24000000)
    i = 1;
    while(i--)  { __nop();  __nop(); }

 #elif       (FREQ_SYS == 20000000)
    for(i=0; i<1; i++)      __nop();

 #elif       (FREQ_SYS == 16000000)
    __nop(); __nop();   __nop(); __nop();
    __nop(); __nop();   __nop(); __nop(); __nop();

#elif       (FREQ_SYS == 8000000)
    __nop(); __nop();

#endif

    }
}

/*******************************************************************************
* Function Name  : mDelaymS
* Description    : mS 
* Input          : t: 
* Return         : None
*******************************************************************************/
void mDelaymS( UINT16 t )
{
    UINT16 i;

    for(i=0; i<t; i++)
        mDelayuS(1000);
}


#if( defined  DEBUG)
int fputc( int c, FILE *f )
{
#if  DEBUG == Debug_UART0
  while( R8_UART0_TFC == UART_FIFO_SIZE );                        /*  */
  R8_UART0_THR = c;                                               /*  */
#elif DEBUG == Debug_UART1
  while( R8_UART1_TFC == UART_FIFO_SIZE );                        /*  */
  R8_UART1_THR = c;                                               /*  */
#elif DEBUG == Debug_UART2
  while( R8_UART2_TFC == UART_FIFO_SIZE );                        /*  */
  R8_UART2_THR = c;                                               /*  */
#elif DEBUG == Debug_UART3
  while( R8_UART3_TFC == UART_FIFO_SIZE );                        /*  */
  R8_UART3_THR = c;                                               /*  */
#endif
  return( c );
}
#endif
