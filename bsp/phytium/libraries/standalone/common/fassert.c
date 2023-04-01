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
 * FilePath: ft_assert.c
 * Date: 2021-04-07 09:53:07
 * LastEditTime: 2022-02-17 18:04:28
 * Description: This files is for assertion implmentation
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 * 1.0   huanghe    2021.4       init commit
 * 1.1   zhugengyu  2022.3       re-define assert macro
 */

/***************************** Include Files *********************************/
#include "ftypes.h"
#include "fassert.h"

/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/
typedef struct
{
    u32 status; /*  */
    FAssertCB cb; /*  */
} FAssertInfo; /*  */

/***************** Macros (Inline Functions) Definitions *********************/

/************************** Function Prototypes ******************************/
static void FAssertCallback(const char *file, s32 line, int ret);

/************************** Variable Definitions *****************************/
static FAssertInfo assert_info =
{
    .status = FASSERT_NONE,
    .cb     = FAssertCallback
}; /*  */

/*****************************************************************************/
/**
 * @name: FAssertSetStatus
 * @msg: 
 * @return {*}
 * @param {FAssertStatus} status, 
 */
void FAssertSetStatus(FAssertStatus status)
{
    assert_info.status = status;
}

/**
 * @name: FAssertGetStatus
 * @msg: 
 * @return {FAssertStatus} 
 */
FAssertStatus FAssertGetStatus(void)
{
    return assert_info.status;
}

/**
 * @name: FAssertCallback
 * @msg: 
 * @return {*}
 * @param {char} *file, 
 * @param {s32} line, 
 * @param {int} ret, Non-block
 */
static void FAssertCallback(const char *file, s32 line, int ret)
{
    f_printk("Assert Error at %s : %ld \r\n", file, line);
}

/**
 * @name: FAssertSetCB
 * @msg: 
 * @return {*}
 * @param {FAssertCB} cb, 
 */
void FAssertSetCB(FAssertCB cb)
{
    if (NULL != cb)
        assert_info.cb = cb;
}

/**
 * @name: FAssert
 * @msg: 
 * @return {*}
 * @param {char} *file, 
 * @param {s32} line, 
 * @param {int} code, Non-block
 */
void FAssert(const char *file, s32 line, int code)
{
    if (NULL != assert_info.cb)
    {
        /* Non-block */
        assert_info.cb(file, line, code);
    }

    while (TRUE)
    {
        ;
    }
}