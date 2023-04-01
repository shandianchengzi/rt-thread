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
 * FilePath: fgmac_sinit.c
 * Date: 2022-04-06 14:46:52
 * LastEditTime: 2022-04-06 14:46:58
 * Description: This file is for
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
#include "fgmac.h"

/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/

/***************** Macros (Inline Functions) Definitions *********************/

/************************** Variable Definitions *****************************/

extern const FGmacConfig FGMAC_CONFIG_TBL[GMAC_INSTANCE_NUM];

/************************** Function Prototypes ******************************/
/**
 * @name: FGmacLookupConfig
 * @msg: FGMAC
 * @return {const FGmacConfig *}, 
 * @param {u32} instance_id, 
 * @note FGMAC
 *       instance_id
 */
const FGmacConfig *FGmacLookupConfig(u32 instance_id)
{
    const FGmacConfig *ptr = NULL;
    u32 index;

    for (index = 0; index < (u32)GMAC_INSTANCE_NUM; index++)
    {
        if (FGMAC_CONFIG_TBL[index].instance_id == instance_id)
        {
            ptr = &FGMAC_CONFIG_TBL[index];
            break;
        }
    }

    return (const FGmacConfig *)ptr;
}