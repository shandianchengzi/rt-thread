/*
 * Copyright: (C)2022PhytiumInformationTechnology,Inc.
 * All Rights Reserved.
 *
 * This program is OPEN SOURCE software: you can redistribute it and/or modify it
 * under the terms of the Phytium Public License as published by the Phytium Technology Co.,Ltd,
 * either version 1.0 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the Phytium Public License for more details.
 *
 *
 * FilePath: frtc.h
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 09:02:51
 * Description: This files is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 * 1.0   Wangxiaodong 2021/8/26   init
 */

#ifndef BSP_DRIVERS_FRTC_H
#define BSP_DRIVERS_FRTC_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <time.h>

#include "ftypes.h"
#include "ferror_code.h"

typedef struct
{
    uintptr control_base_addr; /* rtc */
    const char *instance_name; /* instance name */
} FRtcConfig;                  /* rtc */

typedef struct
{
    FRtcConfig config;  /* rtc */
    u32 is_ready;       /* rtc */
} FRtcCtrl;

typedef struct
{
    u16 year;  /*Specifies the RTC Date Year.
                This parameter must be a number between Min_Data = 2000 and Max_Data = 2099 */
    u8 month;  /*Specifies the RTC Date Month.
                This parameter must be a number between Min_Data = 1 and Max_Data = 12 */
    u8 mday;   /*Specifies the RTC day of Month.
                This parameter must be a number between Min_Data = 1 and Max_Data = 31 */
    u8 hour;   /*Specifies the RTC Time Hour.
                This parameter must be a number between Min_Data = 0 and Max_Data = 23 */
    u8 minute; /*Specifies the RTC Time Minute.
                This parameter must be a number between Min_Data = 0 and Max_Data = 59 */
    u8 second; /*Specifies the RTC Time Second.
                This parameter must be a number between Min_Data = 0 and Max_Data = 59 */
} FRtcDateTime;

#define FRTC_SUCCESS FT_SUCCESS
#define FRTC_ERR_DATE_INVALID FT_MAKE_ERRCODE(ErrModBsp, ErrBspRtc, BIT(1))
#define FRTC_ERR_TIME_INVALID FT_MAKE_ERRCODE(ErrModBsp, ErrBspRtc, BIT(2))

/* rtc config init */
const FRtcConfig *FRtcLookupConfig(void);

/* initialize rtc ctrl */
FError FRtcCfgInitialize(FRtcCtrl *instance_p, const FRtcConfig *config_p);

/* deinitialize rtc ctrl */
void FRtcCfgDeInitialize(FRtcCtrl *pctrl);

/* set rtc time */
FError FRtcSetDateTime(FRtcCtrl *pctrl, const FRtcDateTime *date_time);

/* get rtc time */
FError FRtcGetDateTime(FRtcCtrl *pctrl, FRtcDateTime *date_time);

/* read rtc time in secs and mesc */
void FRtcReadTimeStamp(FRtcCtrl *pctrl, time_t *sec, time_t *msec);

#ifdef __cplusplus
}
#endif

#endif