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
 * FilePath: fpinctrl.h
 * Date: 2022-03-28 14:16:09
 * LastEditTime: 2022-03-28 14:16:10
 * Description: This files is for IO pin ctrl API definition
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 * 1.0   zhugengyu   2022/3/28   init commit
 */
#ifndef  COMMON_FPINCTRL_H
#define  COMMON_FPINCTRL_H

#ifdef __cplusplus
extern "C"
{
#endif

/***************************** Include Files *********************************/
#include "ftypes.h"
#include "sdkconfig.h"

#if defined(CONFIG_TARGET_F2000_4) || defined(CONFIG_TARGET_D2000)
#ifndef FPIN_IO_CTRL
#define FPIN_IO_CTRL
#endif
#endif

#if defined(CONFIG_TARGET_E2000)
#ifndef FPIN_IO_PAD
#define FPIN_IO_PAD
#endif
#endif

#if defined(FPIN_IO_CTRL)
#include "fioctrl.h"
#endif

#if defined(FPIN_IO_PAD)
#include "fiopad.h"
#endif

/**************************** Type Definitions *******************************/

typedef enum
{
    FPIN_FUNC0 = 0b000,
    FPIN_FUNC1,
    FPIN_FUNC2,
    FPIN_FUNC3 = 0b011,
#if defined(FPIN_IO_PAD) /* E2000 support more pin func */
    FPIN_FUNC4,
    FPIN_FUNC5,
    FPIN_FUNC6,
    FPIN_FUNC7 = 0b111,
#endif
    FPIN_NUM_OF_FUNC
} FPinFunc; /* , func0 */

#if defined(FPIN_IO_PAD) /* Only support driver strength config in E2000 */
typedef enum
{
    FPIN_DRV0 = 0b0000,
    FPIN_DRV1,
    FPIN_DRV2,
    FPIN_DRV3,
    FPIN_DRV4,
    FPIN_DRV5,
    FPIN_DRV6,
    FPIN_DRV7,
    FPIN_DRV8,
    FPIN_DRV9,
    FPIN_DRV10,
    FPIN_DRV11,
    FPIN_DRV12,
    FPIN_DRV13,
    FPIN_DRV14,
    FPIN_DRV15 = 0b1111,

    FPIN_NUM_OF_DRIVE
} FPinDrive; /*  */
#endif

typedef enum
{
    FPIN_PULL_NONE = 0b00,
    FPIN_PULL_DOWN = 0b01,
    FPIN_PULL_UP = 0b10,

    FPIN_NUM_OF_PULL
} FPinPull; /*  */

typedef enum
{
    FPIN_OUTPUT_DELAY = 0, /*  */
    FPIN_INPUT_DELAY, /*  */

    FPIN_NUM_OF_DELAY_DIR
} FPinDelayDir; /*  */

typedef enum
{
    FPIN_DELAY_COARSE_TUNING = 0, /*  */
    FPIN_DELAY_FINE_TUNING, /*  */

    FPIN_NUM_OF_DELAY_TYPE
} FPinDelayType; /*  */

typedef enum
{
    FPIN_DELAY_NONE = 0,
    FPIN_DELAY_1,
    FPIN_DELAY_2,
    FPIN_DELAY_3,
    FPIN_DELAY_4,
    FPIN_DELAY_5,
    FPIN_DELAY_6,
    FPIN_DELAY_7,

    FPIN_NUM_OF_DELAY
} FPinDelay;

typedef enum
{
    FPIN_DELAY_IN_TYPE = 0,     /*  input delay */
    FPIN_DELAY_OUT_TYPE = 1,    /* output delay */
} FPinDelayIOType;

typedef struct
{
    u32 reg_off; /*  */
    u32 reg_bit; /*  */
} FPinIndex; /*  */
/************************** Variable Definitions *****************************/

/***************** Macros (Inline Functions) Definitions *********************/
#define FPIN_NULL  {0xffffffff, 0}

/************************** Function Prototypes ******************************/
/* IO */
FPinFunc FPinGetFunc(const FPinIndex pin);

/* IO */
void FPinSetFunc(const FPinIndex pin, FPinFunc func);

/* IO */
FPinPull FPinGetPull(const FPinIndex pin);

/* IO */
void FPinSetPull(const FPinIndex pin, FPinPull pull);

#if defined(FPIN_IO_PAD)
/* IO */
FPinDrive FPinGetDrive(const FPinIndex pin);

/* IO */
void FPinSetDrive(const FPinIndex pin, FPinDrive drive);

/* IO */
void FPinGetConfig(const FPinIndex pin, FPinFunc *func, FPinPull *pull, FPinDrive *drive);

/* IO */
void FPinSetConfig(const FPinIndex pin, FPinFunc func, FPinPull pull, FPinDrive drive);

#else

/* IO */
void FPinGetConfig(const FPinIndex pin, FPinFunc *func, FPinPull *pull);

/* IO */
void FPinSetConfig(const FPinIndex pin, FPinFunc func, FPinPull pull);

#endif

/* IO */
FPinDelay FPinGetDelay(const FPinIndex pin, FPinDelayDir dir, FPinDelayType type);

/* IO */
boolean FPinGetDelayEn(const FPinIndex pin, FPinDelayDir dir);

/* IO */
void FPinSetDelay(const FPinIndex pin, FPinDelayDir dir, FPinDelayType type, FPinDelay delay);

/* IO */
void FPinSetDelayEn(const FPinIndex pin, FPinDelayDir dir, boolean enable);

/* Update and enable common IO pin delay config */
void FPinSetDelayConfig(const FPinIndex pin, FPinDelayIOType in_out_type, FPinDelay roungh_delay, FPinDelay delicate_delay, boolean enable);

/* Get current common IO pin delay config */
void FPinGetDelayConfig(const FPinIndex pin, FPinDelay *in_roungh_delay, FPinDelay *in_delicate_delay,
                        FPinDelay *out_roungh_delay, FPinDelay *out_delicate_delay);

#ifdef __cplusplus
}
#endif

#endif