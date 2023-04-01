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
 * FilePath: fmio.h
 * Date: 2022-06-21 15:40:06
 * LastEditTime: 2022-06-21 15:40:06
 * Description: This file is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */

#ifndef DRIVERS_MIO_FMIO_H
#define DRIVERS_MIO_FMIO_H

#ifdef __cplusplus
extern "C"
{
#endif

/***************************** Include Files *********************************/

#include "ftypes.h"
#include "ferror_code.h"
#include "fassert.h"

/************************** Constant Definitions *****************************/
#define FMIO_SUCCESS          FT_SUCCESS
#define FMIO_ERR_INVAL_PARM   FT_MAKE_ERRCODE(ErrModBsp, ErrBspMio, 1)
#define FMIO_ERR_NOT_READY    FT_MAKE_ERRCODE(ErrModBsp, ErrBspMio, 2)
#define FMIO_ERR_TIMEOUT      FT_MAKE_ERRCODE(ErrModBsp, ErrBspMio, 3)
#define FMIO_ERR_NOT_SUPPORT  FT_MAKE_ERRCODE(ErrModBsp, ErrBspMio, 4)
#define FMIO_ERR_INVAL_STATE  FT_MAKE_ERRCODE(ErrModBsp, ErrBspMio, 5)

/**************************** Type Definitions *******************************/

typedef struct
{
    u32     instance_id;        /*mio id*/
    uintptr func_base_addr; /*I2C or UART function address*/
    u32     irq_num;     /* Device intrrupt id */
    uintptr mio_base_addr;  /*MIO control address*/
} FMioConfig;               /*mio configs*/

typedef struct
{
    FMioConfig config;  /* mio config */
    u32 is_ready;   /* mio initialize the complete flag */
} FMioCtrl;

/************************** Function Prototypes ******************************/
/*MIO*/
const FMioConfig *FMioLookupConfig(u32 instance_id);

/*MIO*/
FError FMioFuncInit(FMioCtrl *instance_p, u32 mio_type);

/**/
FError FMioFuncDeinit(FMioCtrl *instance_p);

/**/
uintptr FMioFuncGetAddress(FMioCtrl *instance_p, u32 mio_type);

/**/
u32 FMioFuncGetIrqNum(FMioCtrl *instance_p, u32 mio_type);

#ifdef __cplusplus
}
#endif

#endif