/******************************************************************************
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
/*****************************************************************************/
/** \file rtc.h
 **
 ** Headerfile for RTC functions
 **  
 **
 ** History:
 **   - 2019-04-10        First Version
 **
 *****************************************************************************/

#ifndef __RTC_H__
#define __RTC_H__

/*****************************************************************************
 * Include files
 *****************************************************************************/
#include "ddl.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup RtcGroup Real Time Clock (RTC)
 **
 ******************************************************************************/
//@{

/******************************************************************************/
/* Global pre-processor symbols/macros ('#define')                            */
/******************************************************************************/

/******************************************************************************
 * Global type definitions
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief rtc                       RTC_CR0  PRDS
 *****************************************************************************/
typedef enum
{
    RtcNone   = 0u, //
    Rtc05S    = 1u, //0.5S
    Rtc1S     = 2u, //1
    Rtc1Min   = 3u, //1
    Rtc1H     = 4u, //1
    Rtc1Day   = 5u, //1
    Rtc1Mon   = 6u  //1
}en_rtc_prds_t;

/**
 ******************************************************************************
 ** \brief rtc 12h24h                   RTC_CR0  AMPM
 *****************************************************************************/
typedef enum
{
    RtcAm = 0u,     //12
    RtcPm = 1u      //24
}en_rtc_ampm_t;

/**
 ******************************************************************************
 ** \brief 1Hz                   RTC_CR0  HZ1SEL
 *****************************************************************************/
typedef enum
{
    RtcHz1selGeneralPricision = 0u,    //1Hz
    RtcHz1selHighPricision = 1u        //1Hz
}en_rtc_hz1sel_t;

/**
 ******************************************************************************
 ** \brief                              RTC_CR0  PRDSEL
 *****************************************************************************/
typedef enum
{
    RtcPrds = 0u,   //PRDS
    RtcPrdx = 1u    //PRDX
}en_rtc_prdsel_t;

/**
 ******************************************************************************
 ** \brief rtc                           RTC_CR1  CKSEL
 *****************************************************************************/
typedef enum 
{
    RtcClkXtl      = 0u, //XTL  32.768k    
    RtcClkRcl      = 2u, //RCL  32k   
    RtcClkXth128   = 4u, //4M       XTH/128
    RtcClkXth256   = 5u, //8M       XTH/256
    RtcClkXth512   = 6u, //16M      XTH/512
    RtcClkXth1024  = 7u  //32M      XTH/1024
}en_rtc_cksel_t;

/**
 ******************************************************************************
 ** \brief                       RTC_COMPEN  EN
 *****************************************************************************/
typedef enum
{
    RtcCompenDisable = 0u,
    RtcCompenEnable  = 1u
}en_rtc_compen_t;

/**
 ******************************************************************************
** \brief PRD                      
 *****************************************************************************/
typedef struct
{
    en_rtc_prdsel_t rtcPrdsel;
    uint8_t         rtcPrdx;
    en_rtc_prds_t   rtcPrds;
}stc_rtc_cyccfg_t;

/**
 ******************************************************************************
 ** \brief 
 *****************************************************************************/
typedef struct
{
    uint8_t  RtcAlarmSec;    //
    uint8_t  RtcAlarmMinute; //
    uint8_t  RtcAlarmHour;   //
    uint8_t  RtcAlarmWeek;   //
}stc_rtc_alarmtime_t;

/**
 ******************************************************************************
 ** \brief 
 *****************************************************************************/
/**
 ******************************************************************************
 ** \brief rtc
 *****************************************************************************/
typedef struct stc_rtc_time
{
    uint8_t  u8Second;      //    
    uint8_t  u8Minute;      //
    uint8_t  u8Hour;        //
    uint8_t  u8DayOfWeek;   //
    uint8_t  u8Day;         //    
    uint8_t  u8Month;       //
    uint8_t  u8Year;        //
} stc_rtc_time_t;

/**
 ******************************************************************************
 ** \brief RTC
 *****************************************************************************/
typedef struct
{
    en_rtc_ampm_t         rtcAmpm;      //
    stc_rtc_cyccfg_t      rtcPrdsel;    //PRDSPRDX
    en_rtc_cksel_t        rtcClksrc;    //
    en_rtc_compen_t       rtcCompen;    //
    uint16_t              rtcCompValue; //:0-255
    stc_rtc_time_t        rtcTime;      //
}stc_rtc_initstruct_t;

/******************************************************************************
  Global function prototypes (definition in C source)
*******************************************************************************/
//RTC
extern void Rtc_Cmd(boolean_t NewState);
//RTC
extern void Rtc_StartWait(void);
//RTC1Hz
extern void Rtc_Hz1Cmd(en_rtc_hz1sel_t pricision, boolean_t NewState);
//(PRDSEL)(PRDSPRDX)
extern en_result_t Rtc_SetCyc(stc_rtc_cyccfg_t* pstCyc);
//RTC
extern void Rtc_AlmIeCmd(boolean_t NewState);
//RTC
extern void Rtc_AlmEnCmd(boolean_t NewState);
//RTC
extern boolean_t Rtc_GetAlmfItStatus(void);
//RTC
extern void Rtc_ClearAlmfItStatus(void);
//RTC
extern void Rtc_ClearPrdfItStatus(void);
//RTC
extern boolean_t Rtc_GetPridItStatus(void);
//RTC
extern en_result_t Rtc_CompCfg(uint16_t CompVlue, en_rtc_compen_t NewStatus);
//RTC
extern en_result_t Check_BCD_Format(uint8_t u8data,uint8_t u8limit_min, uint8_t u8limit_max);
//RTC
extern en_result_t Rtc_ReadDateTime(stc_rtc_time_t* time);
//RTC
extern en_result_t Rtc_SetTime(stc_rtc_time_t* time);
//RTC
extern void Rtc_GetAlarmTime(stc_rtc_alarmtime_t* pstcAlarmTime);
//RTC
extern en_result_t Rtc_SetAlarmTime(stc_rtc_alarmtime_t* pstcAlarmTime);
//RTC
extern void Rtc_Init(stc_rtc_initstruct_t* Rtc_InitStruct);
#endif /* __RTC_H__ */
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/    


