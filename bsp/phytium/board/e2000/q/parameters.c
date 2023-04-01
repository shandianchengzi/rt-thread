/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Email: opensource_embedded@phytium.com.cn
 *
 * Change Logs:
 * Date        Author       Notes
 * 2022-10-26  huanghe      first commit
 *
 */

#include "rtconfig.h"
#include <rtthread.h>

#include "fcpu_info.h"
#include "fparameters.h"


/**
 * @name: GetCpuMaskToAffval
 * @msg:   GetCpuMaskToAffval  id 01 id  23
 * @return {*}
 * @note:
 * @param {u32} *cpu_mask
 * @param {u32} *cluster_id
 * @param {u32} *target_list
 */
u32 GetCpuMaskToAffval(u32 *cpu_mask, u32 *cluster_id, u32 *target_list)
{
    if (*cpu_mask == 0)
    {
        return 0;
    }

    *target_list = 0;
    *cluster_id = 0;

    if (*cpu_mask & 0x4)
    {
        *target_list = 1;
        *cpu_mask &= ~0x4;
    }
    else if (*cpu_mask & 0x8)
    {
        *cluster_id = 0x100;
        *target_list = 1;
        *cpu_mask &= ~0x8;
    }
    else if (*cpu_mask & 0x3)
    {
        *cluster_id = 0x200;
        if ((*cpu_mask & 0x3) == 0x3)
        {
            *target_list = 3;
        }
        else if ((*cpu_mask & 0x4))
        {
            *target_list = 1;
        }
        else
        {
            *target_list = 2;
        }
        *cpu_mask &= ~0x3;
    }
    else
    {
        *cpu_mask = 0;
        return 0;
    }

    return 1;
}