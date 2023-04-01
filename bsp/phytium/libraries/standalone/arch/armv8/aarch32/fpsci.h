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
 * FilePath: fpsci.h
 * Date: 2022-02-10 14:53:41
 * LastEditTime: 2022-02-17 17:30:40
 * Description: This files is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */


#ifndef BSP_ARCH_ARMV8_AARCH32_PSCI_H
#define BSP_ARCH_ARMV8_AARCH32_PSCI_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "ftypes.h"
#include "ferror_code.h"

FError PsciCpuOn(s32 cpu_id_mask, uintptr bootaddr);
void PsciCpuReset(void);

#ifdef __cplusplus
}
#endif

#endif // !
