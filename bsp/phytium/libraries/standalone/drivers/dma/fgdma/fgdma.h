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
 * FilePath: fgdma.h
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 08:25:35
 * Description: This files is for gdma user api implementation
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 * 1.0   huanghe    2021-11-5    init commit
 * 1.1   zhugengyu  2022-5-16    modify according to tech manual.
 */

#ifndef DRIVERS_FGDMA_H
#define DRIVERS_FGDMA_H

#ifdef __cplusplus
extern "C"
{
#endif

/***************************** Include Files *********************************/

#include "ftypes.h"
#include "fassert.h"
#include "ferror_code.h"
#include "fkernel.h"

/************************** Constant Definitions *****************************/
typedef enum
{
    FGDMA_CHAN0_INDEX = 0,
    FGDMA_CHAN1_INDEX = 1,
    FGDMA_CHAN2_INDEX = 2,
    FGDMA_CHAN3_INDEX = 3,
    FGDMA_CHAN4_INDEX = 4,
    FGDMA_CHAN5_INDEX = 5,
    FGDMA_CHAN6_INDEX = 6,
    FGDMA_CHAN7_INDEX = 7,
    FGDMA_CHAN8_INDEX = 8,
    FGDMA_CHAN9_INDEX = 9,
    FGDMA_CHAN10_INDEX = 10,
    FGDMA_CHAN11_INDEX = 11,
    FGDMA_CHAN12_INDEX = 12,
    FGDMA_CHAN13_INDEX = 13,
    FGDMA_CHAN14_INDEX = 14,
    FGDMA_CHAN15_INDEX = 15,

    FGDMA_NUM_OF_CHAN
} FGdmaChanIndex; /* 16, 0 ~ 15 */

typedef enum
{
    FGDMA_OPER_NONE_PRIORITY_POLL = -1, /* Priority = -1 Poll */
    FGDMA_OPER_PRIORITY0 = 0, /* Priority >= 0 Qos */
    FGDMA_OPER_PRIORITY1 = 1,
    FGDMA_OPER_PRIORITY2 = 2,
    FGDMA_OPER_PRIORITY3 = 3,
    FGDMA_OPER_PRIORITY4 = 4,
    FGDMA_OPER_PRIORITY5 = 5,
    FGDMA_OPER_PRIORITY6 = 6,
    FGDMA_OPER_PRIORITY7 = 7,
    FGDMA_OPER_PRIORITY8 = 8,
    FGDMA_OPER_PRIORITY9 = 9,
    FGDMA_OPER_PRIORITY10 = 10,
    FGDMA_OPER_PRIORITY11 = 11,
    FGDMA_OPER_PRIORITY12 = 12,
    FGDMA_OPER_PRIORITY13 = 13,
    FGDMA_OPER_PRIORITY14 = 14,
    FGDMA_OPER_PRIORITY15 = 15
} FGdmaOperPriority; /* Qos */

typedef enum
{
    FGDMA_OPER_DIRECT = 0, /*  */
    FGDMA_OPER_BDL /* BDL */
} FGdmaOperMode; /*  */

typedef enum
{
    FGDMA_BURST_SIZE_1_BYTE = 0,
    FGDMA_BURST_SIZE_2_BYTE = 1,
    FGDMA_BURST_SIZE_4_BYTE = 2,
    FGDMA_BURST_SIZE_8_BYTE = 3,
    FGDMA_BURST_SIZE_16_BYTE = 4
} FGdmaBurstSize; /* size */

#define FGDMA_GET_BURST_SIZE(brust_align)   (1U << brust_align)

typedef enum
{
    FGDMA_CHAN_EVT_FIFO_EMPTY = 0, /* Fifo */
    FGDMA_CHAN_EVT_FIFO_FULL,      /* Fifo */
    FGDMA_CHAN_EVT_BDL_END,        /* BDLBDL */
    FGDMA_CHAN_EVT_TRANS_END,      /*  */
    FGDMA_CHAN_EVT_BUSY,           /*  */

    FGDMA_CHAN_NUM_OF_EVT
} FGdmaChanEvtType; /*  */

#define FGDMA_SUCCESS           FT_SUCCESS
#define FGDMA_ERR_NOT_INIT      FT_MAKE_ERRCODE(ErrModBsp, ErrGdma, 0)
#define FGDMA_ERR_CHAN_IN_USE   FT_MAKE_ERRCODE(ErrModBsp, ErrGdma, 1)
#define FGDMA_ERR_CHAN_NOT_INIT FT_MAKE_ERRCODE(ErrModBsp, ErrGdma, 2)
#define FGDMA_ERR_INVALID_ADDR  FT_MAKE_ERRCODE(ErrModBsp, ErrGdma, 3)
#define FGDMA_ERR_INVALID_SIZE  FT_MAKE_ERRCODE(ErrModBsp, ErrGdma, 4)
#define FGDMA_ERR_BDL_NOT_ENOUGH  FT_MAKE_ERRCODE(ErrModBsp, ErrGdma, 5)

#define FGDMA_ADDR_ALIGMENT                      128U  /* BDL128 */

/**************************** Type Definitions *******************************/
typedef struct _FGdma FGdma;
typedef struct _FGdmaChan FGdmaChan;

typedef struct
{
    u32 instance_id;               /* GDMAID */
    u32 irq_num;                   /* GDMA */
    u32 irq_prority;               /* GDMA */
    volatile uintptr_t base_addr;  /* GDMA */
    FGdmaOperPriority rd_qos;      /*  */
    FGdmaOperPriority wr_qos;      /*  */
} FGdmaConfig; /* GDMA */

typedef struct
{
    u32 src_addr_l; /* 0x0, 32 */
    u32 src_addr_h; /* 0x4, 32 */
    u32 dst_addr_l; /* 0x8, 32 */
    u32 dst_addr_h; /* 0xc, 32 */
#define FGDMA_SRC_TC_BDL_BURST_SET(x)      SET_REG32_BITS((x), 1U, 0U)
#define FGDMA_SRC_TC_BDL_SIZE_SET(x)       SET_REG32_BITS((x), 6U, 4U)
#define FGDMA_SRC_TC_BDL_LEN_SET(x)        SET_REG32_BITS((x), 15U, 8U)
    u32 src_tc;     /* 0x10,  */
#define FGDMA_DST_TC_BDL_BURST_SET(x)      SET_REG32_BITS((x), 1U, 0U)
#define FGDMA_DST_TC_BDL_SIZE_SET(x)       SET_REG32_BITS((x), 6U, 4U)
#define FGDMA_DST_TC_BDL_LEN_SET(x)        SET_REG32_BITS((x), 15U, 8U)
    u32 dst_tc;     /* 0x14,  */
    u32 total_bytes;/* 0x18, Byte  */
    u32 ioc;        /* 0x1c,   */
} __attribute__((__packed__)) FGdmaBdlDesc; /* BDL */

FASSERT_STATIC(0x20U == sizeof(FGdmaBdlDesc));

typedef struct
{
    FGdmaChanIndex      chan_id; /* DMAID */
    FGdmaOperPriority   rd_qos;  /* DMAQos */
    FGdmaOperPriority   wr_qos;  /* DMAQos */
    FGdmaOperMode       trans_mode; /* DMABDL */
    /* Direct */
    FGdmaBurstSize      rd_align; /* DMABurst */
    FGdmaBurstSize      wr_align; /* DMABurst */
    /* BDL */
    boolean             roll_back; /* TRUE: BDLBDL */
    FGdmaBdlDesc        *descs;
    u32                 total_desc_num;
    u32                 valid_desc_num;
} FGdmaChanConfig; /* DMA */

typedef void (*FGdmaChanEvtHandler)(FGdmaChan *const chan, void *args);

typedef struct _FGdmaChan
{
    FGdmaChanConfig config;     /* DMA */
    FGdma *gdma;                /* DMA */
    FGdmaChanEvtHandler evt_handlers[FGDMA_CHAN_NUM_OF_EVT];  /* DMA */
    void *evt_handler_args[FGDMA_CHAN_NUM_OF_EVT];            /* DMA */
} FGdmaChan; /* GDMA */

typedef struct _FGdma
{
    FGdmaConfig config;       /* GDMA */
    u32 is_ready;             /* GDMA */
    FGdmaChan *chans[FGDMA_NUM_OF_CHAN]; /* GDMANULL */
} FGdma; /* GDMA */

/************************** Variable Definitions *****************************/

/***************** Macros (Inline Functions) Definitions *********************/
/*  */
#define FGDMA_DEFAULT_DIRECT_CHAN_CONFIG(_chan_id)\
(FGdmaChanConfig){ \
    .chan_id = (_chan_id),\
    .rd_align = FGDMA_BURST_SIZE_4_BYTE,\
    .wr_align = FGDMA_BURST_SIZE_4_BYTE,\
    .rd_qos = FGDMA_OPER_NONE_PRIORITY_POLL,\
    .wr_qos = FGDMA_OPER_NONE_PRIORITY_POLL,\
    .trans_mode = FGDMA_OPER_DIRECT,\
    .roll_back = FALSE\
}

#define FGDMA_DEFAULT_BDL_CHAN_CONFIG(_chan_id, _bdl_descs, _bdl_desc_num)\
(FGdmaChanConfig){ \
    .chan_id = (_chan_id),\
    .rd_align = FGDMA_BURST_SIZE_4_BYTE,\
    .wr_align = FGDMA_BURST_SIZE_4_BYTE,\
    .rd_qos = FGDMA_OPER_NONE_PRIORITY_POLL,\
    .wr_qos = FGDMA_OPER_NONE_PRIORITY_POLL,\
    .trans_mode = FGDMA_OPER_BDL,\
    .roll_back = FALSE,\
    .descs = _bdl_descs,\
    .total_desc_num = _bdl_desc_num,\
    .valid_desc_num = 0U\
}

/************************** Function Prototypes ******************************/
/* GDMA */
const FGdmaConfig *FGdmaLookupConfig(u32 instance_id);

/* GDMA */
FError FGdmaCfgInitialize(FGdma *const instance_p, const FGdmaConfig *config_p);

/* GDMA */
void FGdmaDeInitialize(FGdma *const instance_p);

/* GDMA */
FError FGdmaAllocateChan(FGdma *const instance_p, FGdmaChan *const chan_p,
                         const FGdmaChanConfig *config_p);

/* GDMA */
FError FGdmaDellocateChan(FGdmaChan *const chan_p);

/* DMA */
FError FGdmaDirectTransfer(FGdmaChan *const chan_p, uintptr src_addr, uintptr dst_addr, fsize_t data_len);

/* BDL */
FError FGdmaAppendBDLEntry(FGdmaChan *const chan_p, uintptr src_addr, uintptr dst_addr, fsize_t data_len);

/* BDLDMA */
FError FGdmaBDLTransfer(FGdmaChan *const chan_p);

/* GDMA */
FError FGdmaStart(FGdma *const instance_p);

/* GDMA */
FError FGdmaStop(FGdma *const instance_p);

/* GDMA */
void FGdmaIrqHandler(s32 vector, void *args);

/* GDMA */
void FGdmaChanRegisterEvtHandler(FGdmaChan *const chan_p, FGdmaChanEvtType evt,
                                 FGdmaChanEvtHandler handler, void *handler_arg);

/* GDMA, DEBUG */
void FGdmaDumpRegisterVals(uintptr base_addr, u32 max_chan);

#ifdef __cplusplus
}
#endif

#endif
