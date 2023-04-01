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
 * FilePath: fsemaphore_hw.h
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 08:24:52
 * Description: This files is for semaphore register definition
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 * 1.0   zhugengyu  2022/5/23    init commit
 */


#ifndef  DRIVERS_IPC_FSEMAPHORE_HW_H
#define  DRIVERS_IPC_FSEMAPHORE_HW_H

#ifdef __cplusplus
extern "C"
{
#endif
/***************************** Include Files *********************************/

#include "fparameters.h"
#include "ftypes.h"
#include "fio.h"
#include "fassert.h"
#include "fkernel.h"

/************************** Constant Definitions *****************************/
/** @name Register Map
 *
 * Register offsets from the base address of an Semaphore.
 * @{
 */
#define FSEMA_RST_REG_OFFSET             0x0U /*  1  */
#define FSEMA_IND_RST_REG_OFFSET         0x4U /*  1 */
#define FSEMA_STATE_REG_OFFSET           0x8U /*  0 ~ 31 */
#define FSEMA_RLOCK_X_REG_OFFSET(x)      (0x10U + (x) * 4)  /*  X  */

/** @name FSEMA_RST_REG_OFFSET Register
 */
#define FSEMA_RST_ALL                   BIT(0) /*  1  */

/** @name FSEMA_IND_RST_REG_OFFSET Register
 */
#define FSEMA_IND_RSET(locker_idx)      BIT(locker_idx) /*  1 */

/** @name FSEMA_STATE_REG_OFFSET Register
 */
#define FSEMA_LOCKER_STATE(locker_idx)  BIT(locker_idx) /* :0 1  */

/** @name FSEMA_RLOCK_X_REG_OFFSET Register
 */
#define FSEMA_RLOCK_X_UNLOCK               0  /*  0 */
/*  0
    1 */
#define FSEMA_RLOCK_X_IS_LOCKED         1
#define FSEMA_RLOCK_X_TAKE_LOCKER       0

#define FSEMA_MIN_LOCKER_IDX            0
#define FSEMA_MAX_LOCKER_IDX            31

/**************************** Type Definitions *******************************/

/************************** Variable Definitions *****************************/

/***************** Macros (Inline Functions) Definitions *********************/
static u32 FSemaReadReg(uintptr base_addr, u32 reg_off)
{
    return FtIn32(base_addr + reg_off);
}

static inline void FSemaWriteReg(uintptr base_addr, u32 reg_off, u32 reg_val)
{
    FtOut32(base_addr + reg_off, reg_val);
    return;
}

/**
 * @name: FSemaHwResetAll
 * @msg: 
 * @return {void} 
 * @param {uintptr} base_addr, Semaphore 
 */
static inline void FSemaHwResetAll(uintptr base_addr)
{
    FSemaWriteReg(base_addr, FSEMA_RST_REG_OFFSET, FSEMA_RST_ALL);
}

/**
 * @name: FSemaHwResetLocker
 * @msg: 
 * @return {void} 
 * @param {uintptr} base_addr, Semaphore 
 * @param {u32} locker_idx, Semaphoreid
 */
static inline void FSemaHwResetLocker(uintptr base_addr, u32 locker_idx)
{
    u32 reg_val = FSemaReadReg(base_addr, FSEMA_IND_RST_REG_OFFSET);
    reg_val |= FSEMA_IND_RSET(locker_idx);
    FSemaWriteReg(base_addr, FSEMA_IND_RST_REG_OFFSET, reg_val);
    return;
}

/**
 * @name: FSemaHwGetStatus
 * @msg: 
 * @return {boolean} TRUE: , FALSE: 
 * @param {uintptr} base_addr, Semaphore 
 * @param {u32} locker_idx, Semaphoreid
 */
static inline boolean FSemaHwGetStatus(uintptr base_addr, u32 locker_idx)
{
    u32 reg_val = FSemaReadReg(base_addr, FSEMA_STATE_REG_OFFSET);
    return (reg_val & FSEMA_LOCKER_STATE(locker_idx)) ? TRUE : FALSE;
}

/**
 * @name: FSemaTryLockOnce
 * @msg: 
 * @return {boolean} TRUE: 
 * @param {uintptr} base_addr, Semaphore 
 * @param {u32} locker_idx, Semaphoreid
 */
static inline boolean FSemaTryLockOnce(uintptr base_addr, u32 locker_idx)
{
    boolean lock_success = FALSE;
    u32 reg_val = FSemaReadReg(base_addr, FSEMA_RLOCK_X_REG_OFFSET(locker_idx)); /*  */

    /*  1
        0 */
    return (FSEMA_RLOCK_X_IS_LOCKED & reg_val) ? FALSE : TRUE;
}

/************************** Function Prototypes ******************************/

#ifdef __cplusplus
}
#endif

#endif