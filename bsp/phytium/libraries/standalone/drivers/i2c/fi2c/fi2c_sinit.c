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
 * FilePath: fi2c_sinit.c
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 08:36:52
 * Description: This files is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */



/* - This file contains the implementation of driver's static initialization functionality.
-   */

/***************************** Include Files *********************************/

#include "ftypes.h"
#include "fparameters.h"
#include "fi2c.h"
#include "sdkconfig.h"
/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/

/***************** Macros (Inline Functions) Definitions *********************/

/************************** Variable Definitions *****************************/

extern const FI2cConfig FI2C_CONFIG_TBL[I2C_INSTANCE_NUM];
/************************** Function Prototypes ******************************/
/**
 * @name: FI2cLookupConfig
 * @msg: I2C
 * @return {const FI2cConfig*} 
 * @param {u32} instance_id, I2C
 */
const FI2cConfig *FI2cLookupConfig(u32 instance_id)
{
    const FI2cConfig *ptr = NULL;
    u32 index;

    for (index = 0; index < (u32)I2C_INSTANCE_NUM; index++)
    {
        if (FI2C_CONFIG_TBL[index].instance_id == instance_id)
        {
            ptr = &FI2C_CONFIG_TBL[index];
            break;
        }
    }

    return (const FI2cConfig *)ptr;
}
