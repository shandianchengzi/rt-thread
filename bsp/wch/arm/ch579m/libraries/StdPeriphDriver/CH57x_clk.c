/********************************** (C) COPYRIGHT *******************************
* File Name          : CH57x_clk.c
* Author             : WCH
* Version            : V1.0
* Date               : 2018/12/15
* Description
*******************************************************************************/

#include "CH57x_common.h"

/*******************************************************************************
* Function Name  : SystemInit
* Description    : 
* Input          : None
* Return         : None
*******************************************************************************/
void SystemInit(void)
{
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    R16_CLK_SYS_CFG = (2<<6)|0x08;          // 32M -> Fsys
    *((PUINT16V)0x40001048) |= 4;
    R8_SAFE_ACCESS_SIG = 0;

    mDelayuS(10);
    /*  */
    PowerMonitor( ENABLE );
}

/*******************************************************************************
* Function Name  : SetSysClock
* Description    : 
* Input          : sc: 
                    refer to SYS_CLKTypeDef
* Return         : None
*******************************************************************************/
void SetSysClock( SYS_CLKTypeDef sc)
{
    switch( sc )
    {
        case CLK_SOURCE_LSI:
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
            R8_CK32K_CONFIG &= ~RB_CLK_OSC32K_XT;
            R16_CLK_SYS_CFG = (3<<6)|0x08;
            break;
        case CLK_SOURCE_LSE:
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
            R8_CK32K_CONFIG |= RB_CLK_OSC32K_XT;
            R16_CLK_SYS_CFG = (3<<6)|0x08;
            break;
        case CLK_SOURCE_HSE_32MHz:
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
            R16_CLK_SYS_CFG = RB_CLK_OSC32M_XT|(2<<6)|0x08;
            break;
        case CLK_SOURCE_HSE_16MHz:
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
            R16_CLK_SYS_CFG = RB_CLK_OSC32M_XT|(0<<6)|0x02;
            break;
        case CLK_SOURCE_HSE_8MHz:
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
            R16_CLK_SYS_CFG = RB_CLK_OSC32M_XT|(0<<6)|0x04;
            break;
        case CLK_SOURCE_HSI_32MHz:
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
            R16_CLK_SYS_CFG = (2<<6)|0x08;
            break;
        case CLK_SOURCE_HSI_16MHz:
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
            R16_CLK_SYS_CFG = (0<<6)|0x02;
            break;
        case CLK_SOURCE_HSI_8MHz:
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
            R16_CLK_SYS_CFG = (0<<6)|0x04;
            break;
        case CLK_SOURCE_PLL_40MHz:
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
            R16_CLK_SYS_CFG = RB_CLK_OSC32M_XT|(1<<6)|12;
            break;
        case CLK_SOURCE_PLL_32MHz:
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
            R16_CLK_SYS_CFG = RB_CLK_OSC32M_XT|(1<<6)|15;
            break;
        case CLK_SOURCE_PLL_24MHz:
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
            R16_CLK_SYS_CFG = RB_CLK_OSC32M_XT|(1<<6)|20;
            break;
        case CLK_SOURCE_PLL_20MHz:
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
            R16_CLK_SYS_CFG = RB_CLK_OSC32M_XT|(1<<6)|24;
            break;
        case CLK_SOURCE_PLL_16MHz:
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
            R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
            R16_CLK_SYS_CFG = RB_CLK_OSC32M_XT|(1<<6)|30;
            break;
        default :
            break;
    }
    R8_SAFE_ACCESS_SIG = 0;
}

/*******************************************************************************
* Function Name  : GetSysClock
* Description    : 
* Input          : None
* Return         : Hz
*******************************************************************************/
UINT32 GetSysClock( void )
{
    UINT16  rev;

    rev = R16_CLK_SYS_CFG & 0xff;
    if( (rev & RB_CLK_SYS_MOD) == (2<<6) ){             // 32M
        return (32000000);
    }
    else if( (rev & RB_CLK_SYS_MOD) == (1<<6) ){        // PLL
        return (480000000/(rev&0x1f));
    }
    else if( (rev & RB_CLK_SYS_MOD) == (0<<6) ){        // 32M
        return (32000000/(rev&0x1f));
    }
    else {                                              // 32K
        return (32000);
    }
}

/*******************************************************************************
* Function Name  : HClk32M_Select
* Description    : 32M 
* Input          : hc:
                    Clk32M_HSI   -   32M
                    Clk32M_HSE   -   32M
* Return         : None
*******************************************************************************/
void HClk32M_Select( HClk32MTypeDef hc)
{
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    if( hc == Clk32M_HSI)
        R16_CLK_SYS_CFG &= ~RB_CLK_OSC32M_XT;
    else
        R16_CLK_SYS_CFG |= RB_CLK_OSC32M_XT;
    R8_SAFE_ACCESS_SIG = 0;
}

/*******************************************************************************
* Function Name  : LClk32K_Select
* Description    : 32K 
* Input          : hc:
                    Clk32K_LSI   -   32K
                    Clk32K_LSE   -   32K
* Return         : None
*******************************************************************************/
void LClk32K_Select( LClk32KTypeDef hc)
{
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    if( hc == Clk32K_LSI)
        R8_CK32K_CONFIG &= ~RB_CLK_OSC32K_XT;
    else
        R8_CK32K_CONFIG |= RB_CLK_OSC32K_XT;
    R8_SAFE_ACCESS_SIG = 0;
}


/*******************************************************************************
* Function Name  : HSECFG_Current
* Description    : HSE 
* Input          : c: 75%,100%,125%,150%
* Return         : None
*******************************************************************************/
void HSECFG_Current( HSECurrentTypeDef c )
{
    UINT8  x32M_c;

    x32M_c = R8_XT32M_TUNE;
    x32M_c = (x32M_c&0xfc)|(c&0x03);

    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    R8_XT32M_TUNE = x32M_c;
    R8_SAFE_ACCESS_SIG = 0;
}

/*******************************************************************************
* Function Name  : HSECFG_Capacitance
* Description    : HSE 
* Input          : c: refer to HSECapTypeDef
* Return         : None
*******************************************************************************/
void HSECFG_Capacitance( HSECapTypeDef c )
{
    UINT8  x32M_c;

    x32M_c = R8_XT32M_TUNE;
    x32M_c = (x32M_c&0x8f)|(c<<4);

    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    R8_XT32M_TUNE = x32M_c;
    R8_SAFE_ACCESS_SIG = 0;
}

/*******************************************************************************
* Function Name  : LSECFG_Current
* Description    : LSE 
* Input          : c: 70%,100%,140%,200%
* Return         : None
*******************************************************************************/
void LSECFG_Current( LSECurrentTypeDef c )
{
    UINT8  x32K_c;

    x32K_c = R8_XT32K_TUNE;
    x32K_c = (x32K_c&0xfc)|(c&0x03);

    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    R8_XT32K_TUNE = x32K_c;
    R8_SAFE_ACCESS_SIG = 0;
}

/*******************************************************************************
* Function Name  : LSECFG_Capacitance
* Description    : LSE 
* Input          : c: refer to LSECapTypeDef
* Return         : None
*******************************************************************************/
void LSECFG_Capacitance( LSECapTypeDef c )
{
    UINT8  x32K_c;

    x32K_c = R8_XT32K_TUNE;
    x32K_c = (x32K_c&0x0f)|(c<<4);

    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    R8_XT32K_TUNE = x32K_c;
    R8_SAFE_ACCESS_SIG = 0;
}
/*******************************************************************************
* Function Name  : Calibration_LSI
* Description    : 32K
* Input          : None
* Return         : 
*******************************************************************************/
// 0-26030Hz    1023-44220Hz
UINT16 Calibration_LSI( void )
{
    UINT16  rev, basev;
    UINT32  calv;
    UINT16  i;
    UINT16  loc, loc_t;
    signed short   CNT_STEP_K;
    signed short   diff_1, diff_2, diffc;
    UINT8  k=0;

    /* T-step */
    rev = R16_CLK_SYS_CFG & 0xff;
    // CNT_STEP_K=Fsys*5*(1/26030 - 1/44220)/1023;
    if( (rev & RB_CLK_SYS_MOD) == (2<<6) ){             // 32M
        calv = ((5*32000000+(CAB_LSIFQ>>1))/CAB_LSIFQ);
        CNT_STEP_K = -3;
    }
    else if( (rev & RB_CLK_SYS_MOD) == (1<<6) ){        // PLL
        calv = (((UINT32)5*480000000/(rev&0x1f)+(CAB_LSIFQ>>1))/CAB_LSIFQ);
        CNT_STEP_K =( -37-((rev&0x1f)-1))/(rev&0x1f);
    }
    else if( (rev & RB_CLK_SYS_MOD) == (0<<6) ){        // 32M
        calv = ((5*32000000/(rev&0x1f)+(CAB_LSIFQ>>1))/CAB_LSIFQ);
        CNT_STEP_K = ( -3-((rev&0x1f)-1))/(rev&0x1f);
    }
    else {                                              // 32K
        calv = (5);
        CNT_STEP_K = 0;
    }

    /*  */
    basev = ( calv &0xfff );                    // 
    // loc = 1023*(f-26030)/f/((44220-26030)/44220)  
    loc = R16_INT32K_TUNE;
    diff_2 = 0;
    diffc = 0;

    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    R8_OSC_CAL_CTRL = RB_OSC_CNT_EN;
    do
    {
        R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
        R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
        R16_INT32K_TUNE = loc;
        R8_SAFE_ACCESS_SIG = 0;

        /*  */
        while(!(R8_OSC_CAL_CTRL&RB_OSC_CNT_HALT));
        i = R16_OSC_CAL_CNT;            // 
        while(R8_OSC_CAL_CTRL&RB_OSC_CNT_HALT);
        while(!(R8_OSC_CAL_CTRL&RB_OSC_CNT_HALT));
        i = R16_OSC_CAL_CNT;            // 
        k++;

        diff_1 = i-basev;

        if( diff_1 == 0 ){
            return 0;       // 
        }
        else if((diff_1*diff_2)<0){                 // 
            if((diffc == 1) || (diffc == -1) || (diffc == 0))
            {
                // 
                if( diff_2<0 )  diff_2 = ~(diff_2-1);
                else            diff_1 = ~(diff_1-1);

                if(diff_1>diff_2){
                    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
                    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
                    R16_INT32K_TUNE = loc_t;
                    R8_SAFE_ACCESS_SIG = 0;

                    return (diff_2*1000/basev);             // 
                }
                else    return(diff_1*1000/basev);
            }
        }

        // 
        diff_2 = diff_1;
        loc_t = loc;
        diffc = diff_1/CNT_STEP_K;
        loc = loc - diffc;
        if( loc == loc_t )
        {
            if( diff_1 > 0 )    loc = loc+1;    // 
            else                loc = loc-1;    // 
        }
    }while( k<20 );

    return(0xff);
}


/*******************************************************************************
* Function Name  : RTCInitTime
* Description    : RTC
* Input          : y:  - 
                    MAX_Y = BEGYEAR + 44
                     mon:  - 
                    MAX_MON = 12
                     d:  - 
                    MAX_D = 31

                     h:  - 
                    MAX_H = 23
                   m:  - 
                    MAX_M = 59
                   s:  - 
                  MAX_S = 59
* Return         : None
*******************************************************************************/
void RTC_InitTime( UINT16 y, UINT16 mon, UINT16 d, UINT16 h, UINT16 m, UINT16 s )
{
    UINT32  t;
    UINT16  year, month, day, sec2, t32k;
    UINT8V clk_pin;

        year = y;
        month = mon;
        day = 0;
    while ( year > BEGYEAR )
    {
      day += YearLength( year-1 );
      year--;
    }
    while ( month > 1 )
    {
      day += monthLength( IsLeapYear( y ), month-2 );
      month--;
    }

    day += d-1;
    sec2 = (h%24)*1800+m*30+s/2;
    t32k = (s&1)?(0x8000):(0);
    t = sec2;
    t = t<<16 | t32k;

    do{
      clk_pin = (R8_CK32K_CONFIG&RB_32K_CLK_PIN);
    }while( (clk_pin != (R8_CK32K_CONFIG&RB_32K_CLK_PIN)) || (!clk_pin) );


    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    R32_RTC_TRIG = day;
    R8_RTC_MODE_CTRL |= RB_RTC_LOAD_HI;
    R32_RTC_TRIG = t;
    R8_RTC_MODE_CTRL |= RB_RTC_LOAD_LO;
    R8_SAFE_ACCESS_SIG = 0;
}

/*******************************************************************************
* Function Name  : RTC_GetTime
* Description    : 
* Input          : y:  - 
                    MAX_Y = BEGYEAR + 44
                     mon:  - 
                    MAX_MON = 12
                     d:  - 
                    MAX_D = 31
                     ph:  - 
                    MAX_H = 23
                   pm:  - 
                    MAX_M = 59
                   ps:  - 
                  MAX_S = 59
* Return         : None
*******************************************************************************/
void RTC_GetTime( PUINT16 py, PUINT16 pmon, PUINT16 pd, PUINT16 ph, PUINT16 pm, PUINT16 ps )
{
    UINT32  t;
    UINT16  day, sec2, t32k;

    day = R32_RTC_CNT_DAY & 0x3FFF;
    sec2 = R16_RTC_CNT_2S;
    t32k = R16_RTC_CNT_32K;

    t = sec2*2 + ((t32k<0x8000)?0:1);

        *py = BEGYEAR;
    while ( day >= YearLength( *py ) )
    {
      day -= YearLength( *py );
      (*py)++;
    }

    *pmon = 0;
    while ( day >= monthLength( IsLeapYear( *py ), *pmon ) )
    {
      day -= monthLength( IsLeapYear( *py ), *pmon );
      (*pmon)++;
    }
        (*pmon) ++;
        *pd = day+1;
    *ph = t/3600;
    *pm = t%3600/60;
    *ps = t%60;
}

/*******************************************************************************
* Function Name  : RTC_SetCycle32k
* Description    : LSE/LSIRTC 
* Input          : cyc:  - cycle
                    MAX_CYC = 0xA8BFFFFF = 2831155199
* Return         : None
*******************************************************************************/
void RTC_SetCycle32k( UINT32 cyc )
{
    UINT8V clk_pin;

    do{
      clk_pin = (R8_CK32K_CONFIG&RB_32K_CLK_PIN);
    }while( (clk_pin != (R8_CK32K_CONFIG&RB_32K_CLK_PIN)) || (!clk_pin) );

    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    R32_RTC_TRIG = cyc;
    R8_RTC_MODE_CTRL |= RB_RTC_LOAD_LO;
    R8_SAFE_ACCESS_SIG = 0;
}

/*******************************************************************************
* Function Name  : RTC_GetCycle32k
* Description    : LSE/LSIRTC 
* Input          : None
* Return         : MAX_CYC = 0xA8BFFFFF = 2831155199
*******************************************************************************/
UINT32 RTC_GetCycle32k( void )
{
    UINT32 i;

    do{
        i = R32_RTC_CNT_32K;
    }while( i != R32_RTC_CNT_32K );

    return (i);
}

/*******************************************************************************
* Function Name  : RTC_TMRFunCfg
* Description    : RTC
* Input          : t:
                    refer to RTC_TMRCycTypeDef
* Return         : None
*******************************************************************************/
void RTC_TMRFunCfg( RTC_TMRCycTypeDef t )
{
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    R8_RTC_MODE_CTRL &= ~(RB_RTC_TMR_EN|RB_RTC_TMR_MODE);
    R8_RTC_MODE_CTRL |= RB_RTC_TMR_EN | (t);
    R8_SAFE_ACCESS_SIG = 0;
}

/*******************************************************************************
* Function Name  : RTC_TRIGFunCfg
* Description    : RTC
* Input          : cyc: LSE/LSI
* Return         : None
*******************************************************************************/
void RTC_TRIGFunCfg( UINT32 cyc )
{
    UINT32 t;

    t = RTC_GetCycle32k() + cyc;
    if( t>0xA8C00000)   t -= 0xA8C00000;
    if( t&0xFFFF )  t = t+0x10000;

    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    R32_RTC_TRIG = t;
    R8_RTC_MODE_CTRL |= RB_RTC_TRIG_EN;
    R8_SAFE_ACCESS_SIG = 0;
}

/*******************************************************************************
* Function Name  : RTC_ModeFunDisable
* Description    : RTC 
* Input          : m: 
* Return         : None
*******************************************************************************/
void RTC_ModeFunDisable( RTC_MODETypeDef m )
{
    UINT8  i=0;

    if( m == RTC_TRIG_MODE )    i |= RB_RTC_TRIG_EN;
    else if( m == RTC_TMR_MODE )     i |= RB_RTC_TMR_EN;

    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    R8_RTC_MODE_CTRL &= ~(i);
    R8_SAFE_ACCESS_SIG = 0;
}

/*******************************************************************************
* Function Name  : RTC_GetITFlag
* Description    : RTC
* Input          : f:
                    refer to RTC_EVENTTypeDef
* Return         : :
                    0     -     
                   (!0)   -     
*******************************************************************************/
UINT8 RTC_GetITFlag( RTC_EVENTTypeDef f )
{
    if( f == RTC_TRIG_EVENT )
        return ( R8_RTC_FLAG_CTRL & RB_RTC_TRIG_FLAG );
    else
        return ( R8_RTC_FLAG_CTRL & RB_RTC_TMR_FLAG );
}

/*******************************************************************************
* Function Name  : RTC_ClearITFlag
* Description    : RTC
* Input          : f:
                    refer to RTC_EVENTTypeDef
* Return         : None
*******************************************************************************/
void RTC_ClearITFlag( RTC_EVENTTypeDef f )
{
    switch( f )
    {
        case RTC_TRIG_EVENT:
            R8_RTC_FLAG_CTRL = RB_RTC_TRIG_CLR;
            break;
        case RTC_TMR_EVENT:
            R8_RTC_FLAG_CTRL = RB_RTC_TMR_CLR;
            break;
        default :
            break;
    }
}


