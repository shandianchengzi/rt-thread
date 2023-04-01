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
 * FilePath: frtc_g.c
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 09:01:26
 * Description: This files is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 * 1.0   Wangxiaodong   2021/8/25   init
 */

#include "fparameters.h"
#include "frtc.h"

/* default configs of rtc ctrl */
const FRtcConfig FRtcConfigTbl =
{
    .control_base_addr = RTC_CONTROL_BASE,
    .instance_name = "RTC"
};

