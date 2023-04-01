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
 * FilePath: fsemaphore.h
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 08:25:35
 * Description: This files is for semaphore user api definition
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 * 1.0   zhugengyu  2022/5/23    init commit
 */


#ifndef  DRIVERS_IPC_FSEMAPHORE_H
#define  DRIVERS_IPC_FSEMAPHORE_H

#ifdef __cplusplus
extern "C"
{
#endif

/***************************** Include Files *********************************/
#include "ftypes.h"
#include "ferror_code.h"

/************************** Constant Definitions *****************************/
#define FSEMA_NUM_OF_LOCKER             32U
#define FSEMA_OWNER_NONE                0U

#define FSEMA_SUCCESS                   FT_SUCCESS
#define FSEMA_ERR_NOT_INIT              FT_MAKE_ERRCODE(ErrModBsp, ErrSema, 0U)
#define FSEMA_ERR_NO_AVAILABLE_LOCKER   FT_MAKE_ERRCODE(ErrModBsp, ErrSema, 1U)
#define FSEMA_ERR_LOCK_TIMEOUT          FT_MAKE_ERRCODE(ErrModBsp, ErrSema, 2U)
#define FSEMA_ERR_NO_PERMISSION         FT_MAKE_ERRCODE(ErrModBsp, ErrSema, 3U)
/**************************** Type Definitions *******************************/
typedef struct
{
    u32 id;             /* Semaphoreid */
    uintptr base_addr;  /* Semaphore */
} FSemaConfig; /* Semaphore */

typedef struct _FSema FSema;

typedef struct
{
    u32 index;                              /* Semaphoreid */
#define FSEMA_LOCKER_NAME_LEN       32U
    char name[FSEMA_LOCKER_NAME_LEN];       /* Semaphore */
    u32 owner;                              /* Semaphore, , FSEMA_OWNER_NONE */
    FSema *sema;                            /* Semaphore */
} FSemaLocker; /* Semaphore */

typedef struct _FSema
{
    FSemaConfig config;                       /* Semaphore */
    u32 is_ready;                             /* Semaphore */
    FSemaLocker *locker[FSEMA_NUM_OF_LOCKER]; /* Semaphorelocker[i] == NULL  */
} FSema; /* Semaphore */

typedef void (*FSemaRelaxHandler)(FSema *const instance); /* relax */
/************************** Variable Definitions *****************************/

/***************** Macros (Inline Functions) Definitions *********************/

/************************** Function Prototypes ******************************/
/* Semaphore */
const FSemaConfig *FSemaLoopkupConfig(u32 instance_id);

/* Semaphore */
FError FSemaCfgInitialize(FSema *const instance, const FSemaConfig *config);

/* Semaphore */
void FSemaDeInitialize(FSema *const instance);

/* Semaphore */
FError FSemaCreateLocker(FSema *const instance, FSemaLocker *const locker);

/* Semaphore */
FError FSemaDeleteLocker(FSemaLocker *const locker);

/* Semaphore */
FError FSemaTryLock(FSemaLocker *const locker, u32 owner, u32 try_times, FSemaRelaxHandler relax_handler);

/* Semaphore */
FError FSemaUnlock(FSemaLocker *const locker, u32 owner);

/* Semaphore */
FError FSemaUnlockAll(FSema *const instance);

/* Semaphore */
boolean FSemaIsLocked(FSemaLocker *locker);

#ifdef __cplusplus
}
#endif

#endif
