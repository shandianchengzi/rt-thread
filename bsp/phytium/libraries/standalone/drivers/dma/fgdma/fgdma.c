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
 * FilePath: fgdma.c
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 08:25:29
 * Description: This files is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 *  1.0   huanghe    2021-11-5    init commit
 *  1.1   zhugengyu  2022-5-16    support chan alloc. and qos setting
 */


/***************************** Include Files *********************************/
#include <string.h>

#include "fdebug.h"

#include "fgdma_hw.h"
#include "fgdma.h"

/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/

/***************** Macros (Inline Functions) Definitions *********************/
#define FGDMA_DEBUG_TAG "GDMA"
#define FGDMA_ERROR(format, ...)   FT_DEBUG_PRINT_E(FGDMA_DEBUG_TAG, format, ##__VA_ARGS__)
#define FGDMA_WARN(format, ...)    FT_DEBUG_PRINT_W(FGDMA_DEBUG_TAG, format, ##__VA_ARGS__)
#define FGDMA_INFO(format, ...)    FT_DEBUG_PRINT_I(FGDMA_DEBUG_TAG, format, ##__VA_ARGS__)
#define FGDMA_DEBUG(format, ...)   FT_DEBUG_PRINT_D(FGDMA_DEBUG_TAG, format, ##__VA_ARGS__)

/************************** Function Prototypes ******************************/
static void FGdmaReset(FGdma *const instance_p);

/************************** Variable Definitions *****************************/

/*****************************************************************************/

/**
 * @name: FGdmaCfgInitialize
 * @msg: GDMA
 * @return {FError} FGDMA_SUCCESS
 * @param FGdma *const instance_p, GDMA
 * @param const FGdmaConfig *input_config, GDMA
 */
FError FGdmaCfgInitialize(FGdma *const instance_p, const FGdmaConfig *input_config)
{
    FASSERT(instance_p && input_config);
    uintptr base_addr = input_config->base_addr;
    FError ret = FGDMA_SUCCESS;

    if (FT_COMPONENT_IS_READY == instance_p->is_ready)
    {
        FGDMA_WARN("device is already initialized!!!");
    }

    FGdmaDeInitialize(instance_p);

    if (&instance_p->config != input_config)
        instance_p->config = *input_config;

    FASSERT_MSG((0 != base_addr), "invalid device base address");
    FGdmaReset(instance_p);

    if (FGDMA_SUCCESS == ret)
    {
        instance_p->is_ready = FT_COMPONENT_IS_READY;
    }

    return ret;
}

/**
 * @name: FGdmaDeInitialize
 * @msg: GDMA
 * @return {void} 
 * @param FGdma *const instance_p, GDMA
 */
void FGdmaDeInitialize(FGdma *const instance_p)
{
    FASSERT(instance_p);
    u32 chan;

    for (chan = FGDMA_CHAN0_INDEX; chan < FGDMA_NUM_OF_CHAN; chan++)
    {
        if (NULL != instance_p->chans[chan])
        {
            FGDMA_WARN("chan-%d might be in use !!!", chan);
        }
    }

    memset(instance_p, 0, sizeof(*instance_p));
    return;
}

/**
 * @name: FGdmaSetChanQos
 * @msg: GDMAQos
 * @return {void} 
 * @param {uintptr} base_addr, GDMA
 * @param {FGdmaChan} *dma_chan, GDMA
 */
static void FGdmaSetChanQos(uintptr base_addr, FGdmaChan *const dma_chan)
{
    FASSERT(dma_chan);
    FGdmaChanIndex chan_id = dma_chan->config.chan_id;
    u32 reg_val = FGDMA_READREG(base_addr, FGDMA_CHX_MODE_OFFSET(chan_id));
    FGdmaOperPriority prev_rd_qos = FGDMA_CHX_MODE_RD_QOS_GET(reg_val);
    FGdmaOperPriority prev_wr_qos = FGDMA_CHX_MODE_WR_QOS_GET(reg_val);

    FGDMA_INFO("prev rd qos: 0x%x, set rd qos: 0x%x", prev_rd_qos, dma_chan->config.rd_qos);
    FGDMA_INFO("prev wr qos: 0x%x, set wr qos: 0x%x", prev_wr_qos, dma_chan->config.wr_qos);

    if (prev_rd_qos != dma_chan->config.rd_qos) /* need to update rd qos */
    {
        /* replace with new rd qos config */
        reg_val &= ~FGDMA_CHX_MODE_RD_QOS_MASK;
        reg_val |= FGDMA_CHX_MODE_RD_QOS_EN |
                   FGDMA_CHX_MODE_RD_QOS_SET(dma_chan->config.rd_qos);
    }

    if (prev_wr_qos != dma_chan->config.wr_qos) /* need to update wr qos */
    {
        /* replace with new wr qos config */
        reg_val &= ~FGDMA_CHX_MODE_WR_QOS_MASK;
        reg_val |= FGDMA_CHX_MODE_WR_QOS_EN |
                   FGDMA_CHX_MODE_WR_QOS_SET(dma_chan->config.wr_qos);
    }

    FGDMA_WRITEREG(base_addr, FGDMA_CHX_MODE_OFFSET(chan_id), reg_val);
    return;
}

/**
 * @name: FGdmaAllocateChan
 * @msg: GDMA
 * @return {FError} FGDMA_SUCCESS
 * @param FGdma *const instance_p, GDMA
 * @param FGdmaChan *const dma_chan, GDMA
 * @param const FGdmaChanConfig *dma_chan_config, GDMA
 */
FError FGdmaAllocateChan(FGdma *const instance_p, FGdmaChan *const dma_chan,
                         const FGdmaChanConfig *dma_chan_config)
{
    FASSERT(instance_p);
    FASSERT(dma_chan);
    FASSERT(dma_chan_config);
    uintptr base_addr = instance_p->config.base_addr;
    FError ret = FGDMA_SUCCESS;
    FGdmaChanIndex chan_idx = dma_chan_config->chan_id;
    u32 reg_val;

    if (FT_COMPONENT_IS_READY != instance_p->is_ready)
    {
        FGDMA_ERROR("dma instance not init !!!");
        return FGDMA_ERR_NOT_INIT;
    }

    if (NULL != instance_p->chans[chan_idx])
    {
        FGDMA_ERROR("chan %d is in use !!!", chan_idx);
        return FGDMA_ERR_CHAN_IN_USE;
    }

    if (&dma_chan->config != dma_chan_config)
        dma_chan->config = *dma_chan_config;

    /* disable and reset chan */
    FGdmaChanDisable(base_addr, chan_idx);
    FGdmaChanReset(base_addr, chan_idx);

    /* enable channel clock */
    FGdmaSetChanClock(base_addr, chan_idx, TRUE);

    /* set chan mode */
    reg_val = FGDMA_READREG(base_addr, FGDMA_CHX_MODE_OFFSET(chan_idx));
    if (FGDMA_OPER_BDL == dma_chan->config.trans_mode)
    {
        FGDMA_INFO("set as BDL mode");
        reg_val |= FGDMA_CHX_MODE_BDL_EN;

        if (dma_chan->config.roll_back)
        {
            reg_val |= FGDMA_CHX_MODE_BDL_ROLL_EN; /* run BDL in roll-back mode */
        }
        else
        {
            reg_val &= ~FGDMA_CHX_MODE_BDL_ROLL_EN;
        }
    }
    else
    {
        FGDMA_INFO("set as Direct mode");
        reg_val &= ~FGDMA_CHX_MODE_BDL_EN;
        reg_val &= ~FGDMA_CHX_MODE_BDL_ROLL_EN;
    }
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_MODE_OFFSET(chan_idx), reg_val);

    FGdmaSetChanQos(base_addr, dma_chan);
    FGDMA_INFO("mode: 0x%x", FGDMA_READREG(base_addr, FGDMA_CHX_MODE_OFFSET(chan_idx)));

    /* set xfer config */
    reg_val = 0;
    reg_val |= FGDMA_CHX_XFER_CFG_AR_LEN_SET(FGDMA_MAX_BURST_LEN) | /* burst length configed as max 8, which adapted when trans bytes less than 8 */
               FGDMA_CHX_XFER_CFG_AR_SIZE_SET((u32)dma_chan->config.rd_align) |
               FGDMA_CHX_XFER_CFG_AR_BRUST_SET(FGDMA_INCR); /* mem to mem trans work in incr mode */

    reg_val |= FGDMA_CHX_XFER_CFG_AW_LEN_SET(FGDMA_MAX_BURST_LEN) |
               FGDMA_CHX_XFER_CFG_AW_SIZE_SET((u32)dma_chan->config.wr_align) |
               FGDMA_CHX_XFER_CFG_AW_BRUST_SET(FGDMA_INCR); /* mem to mem trans work in incr mode */
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_XFER_CFG_OFFSET(chan_idx), reg_val);
    FGDMA_INFO("xfer cfg: 0x%x", FGDMA_READREG(base_addr, FGDMA_CHX_XFER_CFG_OFFSET(chan_idx)));

    instance_p->chans[chan_idx] = dma_chan;
    dma_chan->gdma = instance_p;

    return ret;
}

/**
 * @name: FGdmaDellocateChan
 * @msg: GDMA
 * @return {FError} FGDMA_SUCCESS
 * @param FGdmaChan *const dma_chan, GDMA
 */
FError FGdmaDellocateChan(FGdmaChan *const dma_chan)
{
    FASSERT(dma_chan);
    FASSERT(dma_chan->gdma);
    FGdma *const instance_p = dma_chan->gdma;
    uintptr base_addr = instance_p->config.base_addr;
    FError ret = FGDMA_SUCCESS;
    FGdmaChanIndex chan_idx = dma_chan->config.chan_id;
    u32 reg_val;

    if (FT_COMPONENT_IS_READY != instance_p->is_ready)
    {
        FGDMA_ERROR("dma instance not init !!!");
        return FGDMA_ERR_NOT_INIT;
    }

    if (dma_chan != instance_p->chans[chan_idx])
    {
        FGDMA_ERROR("chan %d not bind !!!", chan_idx);
        return FGDMA_ERR_CHAN_NOT_INIT;
    }

    /* disable chan and it irq */
    FGdmaChanIrqDisable(base_addr, chan_idx);
    FGdmaChanDisable(base_addr, chan_idx);

    /* disable channel clock */
    FGdmaSetChanClock(base_addr, chan_idx, FALSE);

    instance_p->chans[chan_idx] = NULL;
    memset(dma_chan, 0, sizeof(*dma_chan));

    return ret;
}

/**
 * @name: FGdmaDirectTransfer
 * @msg: DMA
 * @return {FError} FGDMA_SUCCESS
 * @param FGdmaChan *const chan_p, GDMA
 * @param uintptr src_addr, 
 * @param uintptr dst_addr, 
 */
FError FGdmaDirectTransfer(FGdmaChan *const chan_p, uintptr src_addr, uintptr dst_addr, fsize_t data_len)
{
    FASSERT(chan_p);
    FASSERT(chan_p->gdma);
    u32 reg_val;
    FGdma *const instance_p = chan_p->gdma;
    uintptr base_addr = instance_p->config.base_addr;
    FGdmaChanIndex chan_idx = chan_p->config.chan_id;

    if (FT_COMPONENT_IS_READY != instance_p->is_ready)
    {
        FGDMA_ERROR("dma instance not init !!!");
        return FGDMA_ERR_NOT_INIT;
    }

    if ((src_addr % FGDMA_GET_BURST_SIZE(chan_p->config.rd_align)) ||
            (dst_addr % FGDMA_GET_BURST_SIZE(chan_p->config.wr_align)))
    {
        FGDMA_ERROR("src addr 0x%x or dst addr 0x%x not aligned with %d bytes",
                    src_addr, dst_addr, FGDMA_ADDR_ALIGMENT);
        return FGDMA_ERR_INVALID_ADDR;
    }

    if (0 != (data_len % chan_p->config.wr_align))
    {
        FGDMA_ERROR("data length %d must be N times of burst size %d !!!",
                    data_len, chan_p->config.wr_align);
        return FGDMA_ERR_INVALID_SIZE;
    }

    /* src address */
#ifdef __aarch64__
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_UPSADDR_OFFSET(chan_idx), UPPER_32_BITS(src_addr));
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_LWSADDR_OFFSET(chan_idx), LOWER_32_BITS(src_addr));
#else
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_UPSADDR_OFFSET(chan_idx), 0x0U);
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_LWSADDR_OFFSET(chan_idx), (u32)(src_addr));
#endif

    FGDMA_INFO("src: 0x%x-0x%x",
               FGDMA_READREG(base_addr, FGDMA_CHX_UPSADDR_OFFSET(chan_idx)),
               FGDMA_READREG(base_addr, FGDMA_CHX_LWSADDR_OFFSET(chan_idx)));

    /* dest address */
#ifdef __aarch64__
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_UPDADDR_OFFSET(chan_idx), UPPER_32_BITS(dst_addr));
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_LWDADDR_OFFSET(chan_idx), LOWER_32_BITS(dst_addr));
#else
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_UPDADDR_OFFSET(chan_idx), 0x0U);
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_LWDADDR_OFFSET(chan_idx), (u32)(dst_addr));
#endif

    FGDMA_INFO("dst: 0x%x-0x%x",
               FGDMA_READREG(base_addr, FGDMA_CHX_UPDADDR_OFFSET(chan_idx)),
               FGDMA_READREG(base_addr, FGDMA_CHX_LWDADDR_OFFSET(chan_idx)));

    /* num of BDL entry not used in direct mode */
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_LVI_OFFSET(chan_idx), 0x0U);

    /* length of data to transfer */
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_TS_OFFSET(chan_idx), data_len);

    FGDMA_INFO("ts: 0x%x", FGDMA_READREG(base_addr, FGDMA_CHX_TS_OFFSET(chan_idx)));

    /* enable channel interrupt */
    FGdmaChanIrqEnable(base_addr, chan_idx, FGDMA_CHX_INT_CTRL_TRANS_END_ENABLE);

    /* enable channel and start transfer */
    FGdmaChanEnable(base_addr, chan_idx);

    return FGDMA_SUCCESS;
}

/**
 * @name: FGdmaSetupBDLEntry
 * @msg: BDL
 * @return {FError} FGDMA_SUCCESS 
 * @param FGdmaBdlDesc *desc_entry, BDL
 * @param uintptr src_addr, 
 * @param uintptr dst_addr, 
 * @param fsize_t data_len, 
 */
FError FGdmaAppendBDLEntry(FGdmaChan *const chan_p, uintptr src_addr, uintptr dst_addr, fsize_t data_len)
{
    FASSERT(chan_p);
    FASSERT_MSG((chan_p->config.descs) && (chan_p->config.total_desc_num > 0), "BDL descriptor list not yet assign !!!");
    u32 desc_idx = chan_p->config.valid_desc_num;
    FGdmaBdlDesc *desc_entry = &(chan_p->config.descs[desc_idx]);

    if (chan_p->config.valid_desc_num >= chan_p->config.total_desc_num)
    {
        FGDMA_ERROR("total BDL descriptor num is %d, already used up", chan_p->config.total_desc_num);
        return FGDMA_ERR_BDL_NOT_ENOUGH;
    }

    if ((0U != (dst_addr % FGDMA_GET_BURST_SIZE(chan_p->config.wr_align))) ||
            (0U != (src_addr % FGDMA_GET_BURST_SIZE(chan_p->config.rd_align))))
    {
        FGDMA_ERROR("src addr 0x%x or dst addr 0x%x not aligned with %d bytes",
                    src_addr, dst_addr, FGDMA_GET_BURST_SIZE(chan_p->config.wr_align));
        return FGDMA_ERR_INVALID_ADDR;
    }

    if (0U != (data_len % chan_p->config.wr_align))
    {
        FGDMA_ERROR("data length %d must be N times of burst size %d !!!",
                    data_len, chan_p->config.wr_align);
        return FGDMA_ERR_INVALID_SIZE;
    }

#ifdef __aarch64___
    desc_entry->src_addr_h = UPPER_32_BITS(src_addr);
    desc_entry->src_addr_l = LOWER_32_BITS(src_addr);
    desc_entry->dst_addr_h = UPPER_32_BITS(dst_addr);
    desc_entry->dst_addr_l = LOWER_32_BITS(dst_addr);
#else
    desc_entry->src_addr_h = 0U;
    desc_entry->src_addr_l = src_addr;
    desc_entry->dst_addr_h = 0U;
    desc_entry->dst_addr_l = dst_addr;
#endif

    /* rd = src */
    desc_entry->src_tc = FGDMA_SRC_TC_BDL_BURST_SET(FGDMA_INCR) |
                         FGDMA_SRC_TC_BDL_SIZE_SET((u32)chan_p->config.rd_align) |
                         FGDMA_SRC_TC_BDL_LEN_SET(FGDMA_MAX_BURST_LEN);

    /* wr = dst */
    desc_entry->dst_tc = FGDMA_DST_TC_BDL_BURST_SET(FGDMA_INCR) |
                         FGDMA_DST_TC_BDL_SIZE_SET((u32)chan_p->config.wr_align) |
                         FGDMA_DST_TC_BDL_LEN_SET(FGDMA_MAX_BURST_LEN);

    desc_entry->total_bytes = data_len;
    desc_entry->ioc = 0U;

    chan_p->config.valid_desc_num++;

    return FGDMA_SUCCESS;
}

/**
 * @name: FGdmaBDLTransfer
 * @msg: BDLDMA
 * @return {FError} FGDMA_SUCCESS 
 * @param FGdmaChan *const chan_p, DMA
 */
FError FGdmaBDLTransfer(FGdmaChan *const chan_p)
{
    FASSERT(chan_p);
    FASSERT(chan_p->gdma);
    FASSERT_MSG((chan_p->config.descs) && (chan_p->config.total_desc_num > 0), "BDL descriptor list not yet assign !!!");
    u32 reg_val;
    FGdma *const instance_p = chan_p->gdma;
    uintptr base_addr = instance_p->config.base_addr;
    FGdmaChanIndex chan_idx = chan_p->config.chan_id;

    if (FT_COMPONENT_IS_READY != instance_p->is_ready)
    {
        FGDMA_ERROR("dma instance not init !!!");
        return FGDMA_ERR_NOT_INIT;
    }

    if (0 == chan_p->config.valid_desc_num)
    {
        FGDMA_WARN("need to assign BDL entry fisrt !!!");
        return FGDMA_SUCCESS;
    }

    if (((uintptr)(void *)chan_p->config.descs) % FGDMA_ADDR_ALIGMENT)
    {
        FGDMA_ERROR("BDL addr %p not aligned with %d bytes", chan_p->config.descs, FGDMA_ADDR_ALIGMENT);
        return FGDMA_ERR_INVALID_ADDR;
    }

    u32 desc_idx = chan_p->config.valid_desc_num - 1;
    FGdmaBdlDesc *descs = chan_p->config.descs; /* get the first BDL entry */

    chan_p->config.descs[desc_idx].ioc = 1U; /* set as the last BDL entry */

    /* src address, and dst address has been defined in BDL */
#ifdef __aarch64__
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_UPSADDR_OFFSET(chan_idx), UPPER_32_BITS((uintptr)descs));
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_LWSADDR_OFFSET(chan_idx), LOWER_32_BITS((uintptr)descs));
#else
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_UPSADDR_OFFSET(chan_idx), 0x0U);
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_LWSADDR_OFFSET(chan_idx), (u32)((uintptr)descs));
#endif

    /* dst address not used in BDL mode */
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_UPDADDR_OFFSET(chan_idx), 0x0U);
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_LWDADDR_OFFSET(chan_idx), 0x0U);

    /* ts not used in BDL mode */
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_TS_OFFSET(chan_idx), 0x0U);

    /* num of BDL entry */
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_LVI_OFFSET(chan_idx), FGDMA_CHX_LVI_SET(chan_p->config.valid_desc_num));

    /* enable channel interrupt */
    FGdmaChanIrqEnable(base_addr, chan_idx, FGDMA_CHX_INT_CTRL_TRANS_END_ENABLE);

    /* enable channel and start transfer */
    FGdmaChanEnable(base_addr, chan_idx);

    return FGDMA_SUCCESS;
}

/**
 * @name: FGdmaStart
 * @msg: GDMA
 * @return {FError} FGDMA_SUCCESS
 * @param FGdma *const instance_p, GDMA
 * @note: FGdmaAllocateChan
 */
FError FGdmaStart(FGdma *const instance_p)
{
    FASSERT(instance_p);
    uintptr base_addr = instance_p->config.base_addr;
    u32 reg_val;

    if (FT_COMPONENT_IS_READY != instance_p->is_ready)
    {
        FGDMA_ERROR("dma instance not init !!!");
        return FGDMA_ERR_NOT_INIT;
    }

    FGdmaIrqEnable(base_addr);

    reg_val = FGDMA_READREG(base_addr, FGDMA_CTL_OFFSET);
    reg_val &= ~FGDMA_CTL_OT_MASK;
    reg_val |= FGDMA_CTL_OT_SET(FGDMA_OUTSTANDING); /* outstanding */
    reg_val |= FGDMA_CTL_ENABLE; /* DMA */
    FGDMA_WRITEREG(base_addr, FGDMA_CTL_OFFSET, reg_val);

    return FGDMA_SUCCESS; // 
}

/**
 * @name: FGdmaStop
 * @msg: GDMA
 * @return {FError} FGDMA_SUCCESS
 * @param FGdma *const instance_p, GDMA
 */
FError FGdmaStop(FGdma *const instance_p)
{
    FASSERT(instance_p);
    uintptr base_addr = instance_p->config.base_addr;
    u32 reg_val;
    u32 chan_id;
    u32 chan_status;

    if (FT_COMPONENT_IS_READY != instance_p->is_ready)
    {
        FGDMA_ERROR("dma instance not init !!!");
        return FGDMA_ERR_NOT_INIT;
    }

    /* Abort  */
    for (chan_id = FGDMA_CHAN0_INDEX; chan_id < FGDMA_NUM_OF_CHAN; chan_id++)
    {
        if (NULL == instance_p->chans[chan_id])
            continue; /* skip un-allocate channel */

        chan_status = FGdmaReadChanStatus(base_addr, chan_id);
        if (FGDMA_CHX_INT_STATE_BUSY & chan_status)
        {
            FGDMA_WARN("chan-%d has abort unfinished request !!!", chan_id);
            FGdmaChanDisable(base_addr, chan_id); /*  */
            FGdmaChanReset(base_addr, chan_id); /*  */
        }
        else
        {
            FGdmaChanDisable(base_addr, chan_id); /*  */
        }

        FGdmaClearChanStatus(base_addr, chan_id, chan_status); /*  */
    }

    FGdmaDisable(base_addr);

    return FGDMA_SUCCESS;
}

/**
 * @name: FGdmaSetQos
 * @msg: GDMAQos
 * @return {void} 
 * @param {FGdma} *instance_p, GDMA
 */
static void FGdmaSetQos(FGdma *const instance_p)
{
    uintptr base_addr = instance_p->config.base_addr;
    u32 reg_val;

    /* enable/disable Qos */
    reg_val = FGDMA_READREG(base_addr, FGDMA_CTL_OFFSET);
    if (FGDMA_OPER_NONE_PRIORITY_POLL == instance_p->config.rd_qos) /* Poll mode */
    {
        reg_val &= ~FGDMA_CTL_RD_ARB;
    }
    else /* Qos mode */
    {
        reg_val |= FGDMA_CTL_RD_ARB;
    }

    if (FGDMA_OPER_NONE_PRIORITY_POLL == instance_p->config.wr_qos) /* Poll mode */
    {
        reg_val &= ~FGDMA_CTL_WR_ARB;
    }
    else /* Qos mode */
    {
        reg_val |= FGDMA_CTL_WR_ARB;
    }
    FGDMA_WRITEREG(base_addr, FGDMA_CTL_OFFSET, reg_val);

    /* set Qos configure */
    reg_val = FGDMA_READREG(base_addr, FGDMA_QOS_CFG_OFFSET);
    if (FGDMA_OPER_NONE_PRIORITY_POLL == instance_p->config.rd_qos) /* Poll mode */
    {
        reg_val &= ~FGDMA_QOS_CFG_ARGOS_MASK;
    }
    else /* Qos value */
    {
        reg_val |= FGDMA_QOS_CFG_ARGOS_SET((u32)instance_p->config.rd_qos);
    }

    if (FGDMA_OPER_NONE_PRIORITY_POLL == instance_p->config.wr_qos) /* Poll mode */
    {
        reg_val &= ~FGDMA_QOS_CFG_AWQOS_MASK;
    }
    else /* Qos value */
    {
        reg_val |= FGDMA_QOS_CFG_AWQOS_SET((u32)instance_p->config.wr_qos);
    }
    FGDMA_WRITEREG(base_addr, FGDMA_QOS_CFG_OFFSET, reg_val);

    return;
}

/**
 * @name: FGdmaReset
 * @msg: GDMA
 * @return {void} 
 * @param {FGdma} *instance_p, GDMA
 */
static void FGdmaReset(FGdma *const instance_p)
{
    uintptr base_addr = instance_p->config.base_addr;
    u32 chan;
    u32 reg_val;

    FGDMA_INFO("reset ctrl @0x%x ...", base_addr);

    FGdmaDisable(base_addr);
    FGdmaSoftwareReset(base_addr);

    FGdmaSetQos(instance_p);

    FGDMA_INFO("reset chan ...");

    for (chan = FGDMA_CHAN0_INDEX; chan < FGDMA_NUM_OF_CHAN; chan++)
    {
        FGdmaChanDisable(base_addr, chan);
        FGdmaChanIrqDisable(base_addr, chan);
        FGdmaChanReset(base_addr, chan);
        FGdmaSetChanClock(base_addr, chan, FALSE);
    }

    return;
}