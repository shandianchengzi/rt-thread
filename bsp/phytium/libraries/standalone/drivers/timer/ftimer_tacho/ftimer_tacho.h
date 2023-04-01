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
 * FilePath: ftimer_tacho.h
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 09:09:43
 * Description: This files is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */

#ifndef BSP_DRIVERS_E2000_TIMER_TACHO_H
#define BSP_DRIVERS_E2000_TIMER_TACHO_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "ftypes.h"
#include "fdebug.h"
#include "ferror_code.h"

#define FTIMER_TACHO_SUCCESS          FT_SUCCESS
#define FTIMER_TACHO_ERR_INVAL_PARM   FT_MAKE_ERRCODE(ErrModBsp, ErrBspTimer, 1)
#define FTIMER_TACHO_ERR_NOT_READY    FT_MAKE_ERRCODE(ErrModBsp, ErrBspTimer, 2)
#define FTIMER_TACHO_ERR_INIT_FAILED  FT_MAKE_ERRCODE(ErrModBsp, ErrBspTimer, 3)
#define FTIMER_TACHO_ERR_NOT_SUPPORT  FT_MAKE_ERRCODE(ErrModBsp, ErrBspTimer, 4)
#define FTIMER_TACHO_ERR_INVAL_STATE  FT_MAKE_ERRCODE(ErrModBsp, ErrBspTimer, 5)
#define FTIMER_TACHO_ERR_IS_READ      FT_MAKE_ERRCODE(ErrModBsp, ErrBspTimer, 6)
#define FTIMER_TACHO_ERR_ABORT        FT_MAKE_ERRCODE(ErrModBsp, ErrBspTimer, 7)
#define FTIMER_TACHO_ERR_FAILED       FT_MAKE_ERRCODE(ErrModBsp, ErrBspTimer, 8)

#define FTIMER_DEBUG_TAG "TIMER"
#define FTIMER_ERROR(format, ...)   FT_DEBUG_PRINT_E(FTIMER_DEBUG_TAG, format, ##__VA_ARGS__)
#define FTIMER_INFO(format, ...)    FT_DEBUG_PRINT_I(FTIMER_DEBUG_TAG, format, ##__VA_ARGS__)
#define FTIMER_DEBUG(format, ...)   FT_DEBUG_PRINT_D(FTIMER_DEBUG_TAG, format, ##__VA_ARGS__)

#define FTACHO_DEBUG_TAG "TACHO"
#define FTACHO_ERROR(format, ...)   FT_DEBUG_PRINT_E(FTACHO_DEBUG_TAG, format, ##__VA_ARGS__)
#define FTACHO_INFO(format, ...)    FT_DEBUG_PRINT_I(FTACHO_DEBUG_TAG, format, ##__VA_ARGS__)
#define FTACHO_DEBUG(format, ...)   FT_DEBUG_PRINT_D(FTACHO_DEBUG_TAG, format, ##__VA_ARGS__)

typedef enum
{
    /*TimerTacho mode */
    FTIMER_WORK_MODE_TIMER = 0,
    FTIMER_WORK_MODE_TACHO,
    FTIMER_WORK_MODE_CAPTURE
} FTimerTachoModeType;

typedef enum
{
    /*Timer count mode*/
    FTIMER_FREE_RUN = 0,
    FTIMER_RESTART
} FTimerCntModeType;

typedef enum
{
    FTIMER_32_BITS = 0,
    FTIMER_64_BITS
} FTimerBitsType;

typedef enum
{
    FTIMER_ONCE_CMP = 0,
    FTIMER_CYC_CMP
} FTimerCmpType;

typedef enum
{
    FTACHO_EVENT_OVER = 0,      /*tacho*/
    FTACHO_EVENT_UNDER,         /*tacho*/
    FTIMER_EVENT_ROLL_OVER,     /**/
    FTIMER_EVENT_ONCE_CMP,      /**/
    FTIMER_EVENT_CYC_CMP,       /**/
    FTACHO_EVENT_CAPTURE,       /*tacho*/

    FMAX_TIMER_TACHO_EVENT
} FTimerTachoEventType;

typedef enum
{
    FTACHO_FALLING_EDGE = 0,    /**/
    FTACHO_RISING_EDGE,         /**/
    FTACHO_DOUBLE_EDGE          /**/
} FTachoEdgeType;

typedef enum
{
    FTACHO_JITTER_LEVEL0 = 0,     /**/
    FTACHO_JITTER_LEVEL1,
    FTACHO_JITTER_LEVEL2,
    FTACHO_JITTER_LEVEL3,
} FTachoJitterLevelType;

typedef struct
{
    u32     id;        /* id of timer tacho */
    char    name[12];  /* instance name */
    u32     irq_priority; /* intr priority */
    u32     work_mode;  /* timer/tacho/capture mode */
    /* for timer function */
    u32     timer_mode; /* free-run/restart */
    u32     timer_bits; /* 32/64 bits */
    u32     cmp_type; /* once/cycle cmp */
    boolean clear_cnt;  /* clear timer counts */
    boolean force_load; /* start count from start val */
    /* for tacho function */
    u32     edge_mode; /* rising/falling/double */
    u32     jitter_level; /* jitter level */
    u32     plus_num;  /* plus_num of period to calculate rpm */
    u32     captue_cnt; /* in capture mode, when cnt reach this val, intr asserted */
} FTimerTachoConfig;

typedef void (*FTimerEventHandler)(void *instance_p);

typedef struct
{
    FTimerTachoConfig     config;   /* Current active configs */
    boolean               isready;  /* Device is initialized and ready */
    FTimerEventHandler    evt_handlers[FMAX_TIMER_TACHO_EVENT];/* event handler for interrupt */
} FTimerTachoCtrl;

/* Time & Tacho API */
/**/
FError FTimerSoftwareReset(FTimerTachoCtrl *instance_p);

/**/
u32 FTimerGetInterruptMask(FTimerTachoCtrl *instance_p);

/*,intrTypemask*/
void FTimerSetInterruptMask(FTimerTachoCtrl *instance_p,
                            FTimerTachoEventType intrType,
                            boolean enable);

/*timer_tacho,*/
FError FTimerStart(FTimerTachoCtrl *instance_p);

/*timer*/
FError FTimerStop(FTimerTachoCtrl *instance_p);

/*timer  tacho-capture*/
FError FTimerSwithMode(FTimerTachoCtrl *instance_p, FTimerTachoConfig *new_config_p);

/*  */
void FTimerRegisterEvtCallback(FTimerTachoCtrl *instance_p,
                               FTimerTachoEventType evt,
                               FTimerEventHandler callback);

/**/
FError FTimeSettingDump(const FTimerTachoCtrl *instance_p);

/*TimerTacho*/
void FTimerTachoIntrHandler(s32 vector, void *param);

/**/
void FTimerTachoSetIntr(FTimerTachoCtrl *instance_p);

/* Timer API */
/*TimerTacho*/
FError FTimerInit(FTimerTachoCtrl *instance_p, const FTimerTachoConfig *config_p);

/*Timer*/
void FTimerGetDefConfig(u32 timer_id, FTimerTachoConfig *config_p);

/*32compare*/
FError FTimerSetPeriod32(FTimerTachoCtrl *instance_p, u32 ticks);

/*64compare*/
FError FTimerSetPeriod64(FTimerTachoCtrl *instance_p, u64 ticks);

/*32*/
u32 FTimerGetCurCnt32(FTimerTachoCtrl *instance_p);

/*64*/
u64 FTimerGetCurCnt64(FTimerTachoCtrl *instance_p);

/**/
FError FTimerSetStartVal(FTimerTachoCtrl *instance_p, u32 cnt);

/*Timer*/
void FTimerDeInit(FTimerTachoCtrl *instance_p);

/* Tacho API */
/*Tacho*/
FError FTachoInit(FTimerTachoCtrl *instance_p, const FTimerTachoConfig *config_p);

/*Tacho*/
void FTachoGetDefConfig(u32 tacho_id, FTimerTachoConfig *config_p);

/*tach= pulse_num*/
void FTachoSetCntPeriod(FTimerTachoCtrl *instance_p, u32 ticks);

/* tach */
void FTachoSetOverLimit(FTimerTachoCtrl *instance_p, u32 overLim);

/* tach */
void FTachoSetUnderLimit(FTimerTachoCtrl *instance_p, u32 underLim);

/**/
FError FTachoGetFanRPM(FTimerTachoCtrl *instance_p, u32 *rpm);

/*capturetacho*/
u32 FTachoGetCaptureCnt(FTimerTachoCtrl *instance_p);

/*Tacho*/
void FTachoDeInit(FTimerTachoCtrl *instance_p);

#ifdef __cplusplus
}
#endif

#endif // !