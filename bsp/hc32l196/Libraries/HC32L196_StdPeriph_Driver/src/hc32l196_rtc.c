/*************************************************************************************
* Copyright (C) 2019, Huada Semiconductor Co.,Ltd All rights reserved.    
*
* This software is owned and published by: 
* Huada Semiconductor Co.,Ltd ("HDSC").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND 
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with HDSC 
* components. This software is licensed by HDSC to be adapted only 
* for use in systems utilizing HDSC components. HDSC shall not be 
* responsible for misuse or illegal use of this software for devices not 
* supported herein. HDSC is providing this software "AS IS" and will 
* not be responsible for issues arising from incorrect user implementation 
* of the software.  
*
* Disclaimer:
* HDSC MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS), 
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING, 
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED 
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED 
* WARRANTY OF NONINFRINGEMENT.  
* HDSC SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT, 
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT 
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, 
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR 
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA, 
* SAVINGS OR PROFITS, 
* EVEN IF Disclaimer HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED 
* FROM, THE SOFTWARE.  
*
* This software may be replicated in part or whole for the licensed use, 
* with the restriction that this Disclaimer and Copyright notice must be 
* included with each copy of this software, whether used in part or whole, 
* at all times.                        
*/
/******************************************************************************/
/** \file rtc.c
 **
 ** RTC function driver API.
 ** @link SampleGroup Some description @endlink
 **
 **   - 2019-04-10    First version 
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "hc32l196_rtc.h"
/**
 ******************************************************************************
 ** \addtogroup RtcGroup
 ******************************************************************************/
//@{

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/

/******************************************************************************/
/* Local function prototypes ('const')                                       */
/******************************************************************************/
const uint8_t Leap_Month_Base[]     =    {3,6,0,3,5,1,3,6,2,4,0,2};
const uint8_t NonLeap_Month_Base[]  =    {4,0,0,3,5,1,3,6,2,4,0,2};
const uint8_t Cnst_Month_Tbl[12]={0x31,0x28,0x31,0x30,0x31,0x30,0x31,0x31,0x30,0x31,0x30,0x31};
/******************************************************************************/
/* Local function prototypes ('static')                                       */
/******************************************************************************/

/******************************************************************************/
/* Local variable prototypes ('static')                                       */
/******************************************************************************/

/*****************************************************************************
 * Function implementation - global ('extern') and local ('static')
 *****************************************************************************/
 
/**
******************************************************************************
    ** \brief  RTC
    ** 
    ** @param  NewState : TRUE  FALSE
    ** \retval 
    **
******************************************************************************/ 
void Rtc_Cmd(boolean_t NewState)
{
    SetBit((uint32_t)(&(M0P_RTC->CR0)), 7, NewState);
}

/**
******************************************************************************
    ** \brief  RTCRTC
    **         RTC
    ** 
    ** @param  NewState : TRUE  FALSE
    ** \retval 
    **
******************************************************************************/ 
void Rtc_StartWait(void)
{
    M0P_RTC->CR1_f.WAIT = 1;
    while (M0P_RTC->CR1_f.WAITF != 1)  //WAITF=1
    {
        ;
    }
    M0P_RTC->CR1_f.WAIT = 0;
    while (M0P_RTC->CR1_f.WAITF != 0)  //WAITF=0 
    {
        ;
    }
}
 
/**
******************************************************************************
    ** \brief  RTC1Hz
    ** @param  pricision : RtcHz1selGeneralPricision  RtcHz1selHighPricision
    ** @param  NewState : Hz1o_Disable  HZ1o_Enable
    ** \retval 
    **
******************************************************************************/ 
void Rtc_Hz1Cmd(en_rtc_hz1sel_t pricision, boolean_t NewState)
{
    SetBit((uint32_t)(&(M0P_RTC->CR0)), 6, pricision);  //1Hz
    SetBit((uint32_t)(&(M0P_RTC->CR0)), 5, NewState);   //1Hz
}    

/**
******************************************************************************
    ** \brief  (PRDSEL)(PRDSPRDX)
    ** 
  ** @param   pstCyc: PRDSELPRDSPRDX
    ** \retval  OkError  ErrorInvalidParameter
    **
******************************************************************************/ 
en_result_t Rtc_SetCyc(stc_rtc_cyccfg_t* pstCyc)
{
    en_result_t enRet = Error;
    M0P_RTC->CR0_f.PRDSEL = pstCyc->rtcPrdsel;
    if(pstCyc->rtcPrdsel == RtcPrds)
    {
        M0P_RTC->CR0_f.PRDS = pstCyc->rtcPrds; 
    }
    else if(pstCyc->rtcPrdsel == RtcPrdx)
    {
        if(pstCyc->rtcPrdx>=64)
        {
            enRet = ErrorInvalidParameter;
            return enRet;
        }
        M0P_RTC->CR0_f.PRDX = pstCyc->rtcPrdx;
    }
    else
    {
        ;
    }
    enRet = Ok;
    return enRet;
}    

/**
******************************************************************************
    ** \brief  RTC
    ** 
    ** @param  NewState : TRUE  FALSE
    ** \retval 
    **
******************************************************************************/
void Rtc_AlmIeCmd(boolean_t NewState)
{
    SetBit((uint32_t)(&(M0P_RTC->CR1)), 3, 0);        //
    SetBit((uint32_t)(&(M0P_RTC->CR1)), 4, 0);        //
    SetBit((uint32_t)(&(M0P_RTC->CR1)), 6, NewState);
}
 
/**
******************************************************************************
    ** \brief  RTC
    ** 
    ** @param  NewState : Almen_Disable  Almen_Enable
    ** \retval 
    **
******************************************************************************/ 
void Rtc_AlmEnCmd(boolean_t NewState)
{
    SetBit((uint32_t)(&(M0P_RTC->CR1)), 7, NewState);
}

/**
******************************************************************************
    ** \brief  RTC
    ** 
    ** @param  
    ** \retval TRUE  FALSE
    **
******************************************************************************/
boolean_t Rtc_GetAlmfItStatus(void)
{
    return GetBit((uint32_t)(&(M0P_RTC->CR1)), 4);
}

/**
******************************************************************************
    ** \brief  RTC
    ** 
    ** @param  
    ** \retval 
    **
******************************************************************************/
void Rtc_ClearAlmfItStatus(void)
{
    SetBit((uint32_t)(&(M0P_RTC->CR1)), 4, 0);
}

/**
******************************************************************************
    ** \brief  RTC
    ** 
    ** @param  
    ** \retval 
    **
******************************************************************************/
void Rtc_ClearPrdfItStatus(void)
{
    SetBit((uint32_t)(&(M0P_RTC->CR1)), 3, 0);
}

/**
******************************************************************************
    ** \brief  RTC
    ** 
    ** @param  
    ** \retval TRUE  FALSE
    **
******************************************************************************/
boolean_t Rtc_GetPridItStatus(void)
{
    return GetBit((uint32_t)(&(M0P_RTC->CR1)), 3);
}

/**
******************************************************************************
    ** \brief  RTC
    ** 
    ** @param  CompValue:32-256
    ** @param  NewStatus: RtcCompenDisable  RtcAmCompenEnable
    ** \retval Ok  ErrorInvalidParameter
    **
******************************************************************************/
en_result_t Rtc_CompCfg(uint16_t CompVlue, en_rtc_compen_t NewStatus)
{
    en_result_t enRet = Error;
    if(CompVlue<=256)
    {
        M0P_RTC->COMPEN_f.EN = NewStatus;
        M0P_RTC->COMPEN_f.CR = CompVlue;
    }
    else
    {
        enRet = ErrorInvalidParameter;
    }
    return enRet;
}

/**
 ******************************************************************************
 ** \brief  RTC
 **
 ** \param pu8buf
 ** \param u8limit_min
 ** \param u8limit_max
 **
 ** \retval Error Ok
 ** 
 ******************************************************************************/
en_result_t Check_BCD_Format(uint8_t u8data,uint8_t u8limit_min, uint8_t u8limit_max)
{

    if (((u8data & 0x0F) > 0x09) || ((u8data & 0xF0) > 0x90)
    ||(u8data > u8limit_max) || (u8data < u8limit_min))
    {
        return Error;
    }
    return Ok;
}

/**
 ******************************************************************************
 ** \brief  RTC 
 **
** \param  u8year::0-99
 **
 ** \retval  1:  0
 **
 ******************************************************************************/
uint8_t Rtc_CheckLeapYear(uint8_t u8year)
{
        uint16_t tmp;
        tmp=2000+u8year;
        if((((tmp % 4)==0) && ((tmp % 100) !=0))|| ((tmp % 400) ==0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 ******************************************************************************
 ** \brief  RTC
 **
 ** \param [in] u8monthu8year
 **
** \retval u8day:2829
 ** 
 ******************************************************************************/
uint8_t Get_Month2_Day( uint8_t u8year)
{
    uint8_t u8day = 0;
    
    u8day = 28;
    if(Rtc_CheckLeapYear(u8year) == 1)
    {
        u8day++;
    }
    return u8day;
}

/**
 ******************************************************************************
 ** \brief  RTC
 **
 ** \param time: BCD
 **
 ** \retval Ok  
 ** \retval ErrorTimeout 
 ******************************************************************************/
en_result_t Rtc_ReadDateTime(stc_rtc_time_t* time)
{
    uint32_t u32TimeOut;
    ASSERT(NULL != pstcTimeDate);  
    u32TimeOut = 1000;
    if(1 == M0P_RTC->CR0_f.START)
    {
        M0P_RTC->CR1_f.WAIT = 1;
        while(u32TimeOut--)
        {
            if(M0P_RTC->CR1_f.WAITF)
            {
            break;
            }
        }
        if(u32TimeOut==0)
        {
            return ErrorTimeout;
        }
    }
    time->u8Second  = M0P_RTC->SEC;
    time->u8Minute  = M0P_RTC->MIN;
    if(1 == M0P_RTC->CR0_f.AMPM)
    {
        time->u8Hour   = M0P_RTC->HOUR;
    }
    else
    {
        time->u8Hour   = M0P_RTC->HOUR&0x1f;
    }
    time->u8Day       = M0P_RTC->DAY;
    time->u8DayOfWeek = M0P_RTC->WEEK;
    time->u8Month     = M0P_RTC->MON;
    time->u8Year      = M0P_RTC->YEAR;

    M0P_RTC->CR1_f.WAIT = 0;
    if(1 == M0P_RTC->CR0_f.START)
    {
            while(M0P_RTC->CR1_f.WAITF)
            {}
    }
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief  RTC
 **
 ** \param time BCD
 **
 ** \retval ErrorTimeout  Ok
 ** 
 ******************************************************************************/
en_result_t Rtc_SetTime(stc_rtc_time_t* time)
{
    en_result_t enRet = Ok;
    uint16_t u16TimeOut;
    u16TimeOut = 1000;
    if(M0P_RTC->CR0_f.START == 1)
    {
        M0P_RTC->CR1_f.WAIT = 1;
        while(--u16TimeOut)
        {
            if(M0P_RTC->CR1_f.WAITF)
            {
                    break;
            }
        }
        if(u16TimeOut==0)
        {
            return ErrorTimeout;
        }
    }
    M0P_RTC->SEC   = time->u8Second;
    M0P_RTC->MIN   = time->u8Minute;
    M0P_RTC->HOUR  = time->u8Hour;
    M0P_RTC->DAY   = time->u8Day;
    M0P_RTC->MON   = time->u8Month;
    M0P_RTC->YEAR  = time->u8Year;
    M0P_RTC->WEEK  = time->u8DayOfWeek;

    M0P_RTC->CR1_f.WAIT = 0;
    if(M0P_RTC->CR0_f.START == 1)
    {
        while(M0P_RTC->CR1_f.WAITF)
        {}
    }
    enRet = Ok;
    return enRet;
}

/**
 ******************************************************************************
 ** \brief  RTC
 **
 ** \param pstcAlarmTime    
 **
 ** \retval 
 ** 
 ******************************************************************************/
void Rtc_GetAlarmTime(stc_rtc_alarmtime_t* pstcAlarmTime)
{
    pstcAlarmTime->RtcAlarmSec    = M0P_RTC->ALMSEC;
    pstcAlarmTime->RtcAlarmMinute = M0P_RTC->ALMMIN;
    pstcAlarmTime->RtcAlarmHour     = M0P_RTC->ALMHOUR;
    pstcAlarmTime->RtcAlarmWeek     = M0P_RTC->ALMWEEK;
}

/**
 ******************************************************************************
 ** \brief  RTC
 **
 ** \param [in] pstcAlarmTime   
 **
 ** \retval Ok  
 ** 
 ******************************************************************************/
en_result_t Rtc_SetAlarmTime(stc_rtc_alarmtime_t* pstcAlarmTime)
{
    en_result_t enRet = Ok;
//    ASSERT(NULL != pstcAlarmTime);
    Rtc_AlmEnCmd(FALSE);      //
    enRet = Check_BCD_Format(pstcAlarmTime->RtcAlarmSec,0x00,0x59);
    if(M0P_RTC->CR0_f.AMPM == RtcAm)
    {
        enRet = Check_BCD_Format(pstcAlarmTime->RtcAlarmHour,0x00,0x12);
    }
    else
    {
        enRet = Check_BCD_Format(pstcAlarmTime->RtcAlarmHour,0x00,0x24);
    }
    if(enRet != Ok)
    {
        return enRet;
    }
    enRet = Check_BCD_Format(pstcAlarmTime->RtcAlarmMinute,0x00,0x59);
    if(enRet != Ok)
    {
        return enRet;
    }

    if(enRet != Ok)
    {
            return enRet; 
    }
    M0P_RTC->ALMSEC  = pstcAlarmTime->RtcAlarmSec & 0x7f;
    M0P_RTC->ALMMIN  = pstcAlarmTime->RtcAlarmMinute & 0x7f;
    M0P_RTC->ALMHOUR = pstcAlarmTime->RtcAlarmHour & 0x3f;
    M0P_RTC->ALMWEEK = pstcAlarmTime->RtcAlarmWeek;
    Rtc_AlmEnCmd(TRUE);      //
    enRet = Ok;
    return enRet;
}

/**
******************************************************************************
    ** \brief  RTC
    ** 
    ** @param  Rtc_InitStruct stc_rtc_initstruct_t
    ** \retval 
    **
******************************************************************************/
void Rtc_Init(stc_rtc_initstruct_t* Rtc_InitStruct)
{
    Rtc_Cmd(FALSE);
    M0P_RTC->CR0_f.AMPM = Rtc_InitStruct->rtcAmpm;        //
    Rtc_SetCyc(&Rtc_InitStruct->rtcPrdsel);                //(PRDSEL)(PRDSPRDX)
    M0P_RTC->CR1_f.CKSEL = Rtc_InitStruct->rtcClksrc;      //RTC
    Rtc_CompCfg(Rtc_InitStruct->rtcCompValue, Rtc_InitStruct->rtcCompen); //
    Rtc_SetTime(&Rtc_InitStruct->rtcTime);                 //
}



