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
 * FilePath: fqspi_sinit.c
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 09:01:10
 * Description: This files is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 * 1.1    wangxiaodong  2021.11.12  re-construct
 */

#include "fparameters.h"
#include "fassert.h"
#include "fqspi.h"

extern FQspiConfig FQspiConfigTbl[FQSPI_INSTANCE_NUM];

const FQspiConfig *FQspiLookupConfig(u32 instance_id)
{
    FASSERT(instance_id < FQSPI_INSTANCE_NUM);
    const FQspiConfig *pconfig = NULL;
    u32 index;

    for (index = 0; index < (u32)FQSPI_INSTANCE_NUM; index++)
    {
        if (FQspiConfigTbl[index].instance_id == instance_id)
        {
            pconfig = &FQspiConfigTbl[index];
            break;
        }
    }

    return (const FQspiConfig *)pconfig;
}