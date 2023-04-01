/*
*@:Copyright(c)2021PhytiumInformationTechnology,Inc.
*
*SPDX-License-Identifier:Apache-2.0.
 *
 * @Date: 2021-04-27 15:31:57
 * @LastEditTime: 2021-04-27 15:31:57
 * @Description: Descriptionoffile
 * @ModifyHistory:
 * **VerWhoDateChanges
 * *---------------------------------------------------------
 */

#include "ft_can.h"
#include "ft_parameters.h"

extern FCan_Config_t FCan_Config[FT_CAN_NUM];

/**
 * @name:
 * @msg:
 * @inparam:
 * @return {*}
 * @param {u32} InstanceId
 */
FCan_Config_t *FCan_LookupConfig(u32 InstanceId)
{
    FCan_Config_t *CfgPtr = NULL;
    u32 Index;

    for (Index = 0; Index < (u32)FT_CAN_NUM; Index++)
    {
        if (FCan_Config[Index].InstanceId == InstanceId)
        {
            CfgPtr = &FCan_Config[Index];
            break;
        }
    }
    return (FCan_Config_t *)CfgPtr;
}
