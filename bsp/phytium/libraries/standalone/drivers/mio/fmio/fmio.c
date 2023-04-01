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
 * FilePath: fmio.c
 * Date: 2022-07-06 15:01:30
 * LastEditTime: 2022-07-06 15:01:30
 * Description: This file is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */
#include <string.h>
#include "fmio_hw.h"
#include "fmio.h"

/***************** Macros (Inline Functions) Definitions *********************/
#define FMIO_DEBUG_TAG "MIO"
#define FMIO_ERROR(format, ...)   FT_DEBUG_PRINT_E(FMIO_DEBUG_TAG, format, ##__VA_ARGS__)
#define FMIO_INFO(format, ...)    FT_DEBUG_PRINT_I(FMIO_DEBUG_TAG, format, ##__VA_ARGS__)
#define FMIO_DEBUG(format, ...)   FT_DEBUG_PRINT_D(FMIO_DEBUG_TAG, format, ##__VA_ARGS__)

/**
 * @name: FMioFuncInit
 * @msg: 
 * @return {*}
 * @param {FMioCtrl} *instance_p
 * @param {u32} mio_type
 */
FError FMioFuncInit(FMioCtrl *instance_p, u32 mio_type)
{
    FASSERT(instance_p);

    FError ret = FMIO_SUCCESS;

    /*
        * If the device is started, disallow the initialize and return a Status
        * indicating it is started.  This allows the user to de-initialize the device
        * and reinitialize, but prevents a user from inadvertently
        * initializing.
    */
    if (FT_COMPONENT_IS_READY == instance_p->is_ready)
    {
        FMIO_ERROR("device is already initialized!!!");
        return FMIO_ERR_INVAL_STATE;
    }

    ret = FMioSelectFunc(instance_p->config.mio_base_addr, mio_type);
    if (FMIO_SUCCESS == ret)
    {
        instance_p->is_ready = FT_COMPONENT_IS_READY;
    }
    return ret;
}

/**
 * @name: FMioFuncDeinit
 * @msg: 
 * @return {*}
 * @param {FMioCtrl} *instance_p
 */
FError FMioFuncDeinit(FMioCtrl *instance_p)
{
    FASSERT(instance_p);
    FError ret = FMIO_SUCCESS;

    instance_p->is_ready = 0;

    /* IIC */
    ret = FMioSelectFunc(instance_p->config.mio_base_addr, FMIO_FUNC_SET_I2C);

    memset(instance_p, 0, sizeof(*instance_p));

    return ret;
}

/**
 * @name: FMioFuncGetAddress
 * @msg: 
 * @return {uintptr}
 * @param {FMioCtrl} *instance_p
 */
uintptr FMioFuncGetAddress(FMioCtrl *instance_p, u32 mio_type)
{
    FASSERT(instance_p);
    FError ret = FMIO_SUCCESS;

    if (instance_p->is_ready != FT_COMPONENT_IS_READY)
    {
        FMIO_ERROR("Mio instance_id: %d ,not init.", instance_p->config.instance_id);
        return FMIO_ERR_NOT_READY;
    }

    if (FMioGetFunc(instance_p->config.mio_base_addr) != mio_type)
    {
        FMIO_ERROR("Mio instance_id: %d ,mio_type error,please init type first.", instance_p->config.instance_id);
        return FMIO_ERR_INVAL_STATE;
    }

    return instance_p->config.func_base_addr;
}

/**
 * @name: FMioFuncGetIrqNum
 * @msg: MIO
 * @return {u32}
 * @param {FMioCtrl} *instance_p
 */
u32 FMioFuncGetIrqNum(FMioCtrl *instance_p, u32 mio_type)
{
    FASSERT(instance_p);
    FError ret = FMIO_SUCCESS;

    if (instance_p->is_ready != FT_COMPONENT_IS_READY)
    {
        FMIO_ERROR("Mio instance_id: %d ,not init.", instance_p->config.instance_id);
        return FMIO_ERR_NOT_READY;
    }

    if (FMioGetFunc(instance_p->config.mio_base_addr) != mio_type)
    {
        FMIO_ERROR("Mio instance_id: %d ,mio_type error,please init type first.", instance_p->config.instance_id);
        return FMIO_ERR_INVAL_STATE;
    }

    return instance_p->config.irq_num;
}