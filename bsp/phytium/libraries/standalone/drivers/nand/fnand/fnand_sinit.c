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
 * FilePath: fnand_sinit.c
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 08:56:56
 * Description: This files is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */


#include "fnand.h"
#include "fparameters.h"

extern FNandConfig FNandConfigTable[FNAND_NUM] ;

/**
 * @name: FNandLookupConfig
 * @msg:  This function looks up the device configuration based on the unique device ID.
 * @param {u32} instance_id contains the ID of the device
 * @return {FNandConfig *} - A pointer to the configuration found . - NULL if the specified device ID is not found
 */
FNandConfig *FNandLookupConfig(u32 instance_id)
{
    FNandConfig *ptr = NULL;
    u32 index;

    for (index = 0; index < (u32)FNAND_NUM; index++)
    {
        if (FNandConfigTable[index].instance_id == instance_id)
        {
            ptr = &FNandConfigTable[index];
            break;
        }
    }

    return (FNandConfig *)ptr;
}