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
 * FilePath: fgdma_g.c
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 08:25:09
 * Description: This files is for static variables definition
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 * 1.0   huanghe    2021-11-5    init commit
 * 1.1   zhugengyu  2022-5-16    modify according to tech manual.
 */

/***************************** Include Files *********************************/

#include "ftypes.h"
#include "fparameters.h"

#include "fgdma.h"
#include "fgdma_hw.h"

/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/

/***************** Macros (Inline Functions) Definitions *********************/

/************************** Function Prototypes ******************************/

/************************** Variable Definitions *****************************/

const FGdmaConfig fgdma_cfg_tbl[FGDMA_INSTANCE_NUM] =
{
    [FGDMA0_ID] =
    {
        .instance_id = FGDMA0_ID,
        .base_addr = FGDMA0_BASE_ADDR,
        .irq_num = FGDMA0_IRQ_NUM,
        .irq_prority = 0,
        .rd_qos = FGDMA_OPER_NONE_PRIORITY_POLL,
        .wr_qos = FGDMA_OPER_NONE_PRIORITY_POLL
    }
};


/*****************************************************************************/
