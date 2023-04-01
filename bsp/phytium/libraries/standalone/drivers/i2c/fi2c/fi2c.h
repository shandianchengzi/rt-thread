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
 * FilePath: fi2c.h
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 08:37:04
 * Description: This files is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */



#ifndef  DRIVERS_I2C_FI2C_H
#define  DRIVERS_I2C_FI2C_H

#ifdef __cplusplus
extern "C"
{
#endif

/***************************** Include Files *********************************/

#include "ftypes.h"
#include "fassert.h"
#include "ferror_code.h"
#include "sdkconfig.h"
/************************** Constant Definitions *****************************/
#define FI2C_SUCCESS          FT_SUCCESS
#define FI2C_ERR_INVAL_PARM   FT_MAKE_ERRCODE(ErrModBsp, ErrBspI2c, 1)
#define FI2C_ERR_NOT_READY    FT_MAKE_ERRCODE(ErrModBsp, ErrBspI2c, 2)
#define FI2C_ERR_TIMEOUT      FT_MAKE_ERRCODE(ErrModBsp, ErrBspI2c, 3)
#define FI2C_ERR_NOT_SUPPORT  FT_MAKE_ERRCODE(ErrModBsp, ErrBspI2c, 4)
#define FI2C_ERR_INVAL_STATE  FT_MAKE_ERRCODE(ErrModBsp, ErrBspI2c, 5)

/* add up new error code above and plust FI2C_ERR_CODE_MAX by ONE*/
#define FI2C_ERR_CODE_MAX     FT_MAKE_ERRCODE(ErrModBsp, ErrBspI2c, 6)
#define FI2C_ERR_CODE_PREFIX  FI2C_ERR_CODE_MAX & (FT_ERRCODE_SYS_MODULE_MASK | FT_ERRCODE_SUB_MODULE_MASK)
#define FI2C_NUM_OF_ERR_CODE  FI2C_ERR_CODE_MAX & FT_ERRCODE_TAIL_VALUE_MASK

/*
 * status codes
 */
#define STATUS_IDLE                 0x0
#define STATUS_WRITE_IN_PROGRESS    0x1
#define STATUS_READ_IN_PROGRESS     0x2

enum
{
    FI2C_MASTER = 0, /* i2c */
    FI2C_SLAVE       /* i2c */
};

enum
{
    FI2C_SPEED_STANDARD_RATE = 100000, /* 100kb/s */
    FI2C_SPEED_FAST_RATE = 400000      /* 400kb/s */
};

enum
{
    FI2C_EVT_MASTER_TRANS_ABORTED = 0,/*master*/
    FI2C_EVT_MASTER_READ_DONE,        /*master*/
    FI2C_EVT_MASTER_WRITE_DONE,       /*master*/

    FI2C_MASTER_INTR_EVT_NUM
}; /* master mode evt */

enum/*slave*/
{
    FI2C_EVT_SLAVE_READ_REQUESTED = 0,  /*slave*/
    FI2C_EVT_SLAVE_WRITE_REQUESTED,     /*slave*/
    FI2C_EVT_SLAVE_READ_PROCESSED,      /*Slave Master */
    FI2C_EVT_SLAVE_WRITE_RECEIVED,      /*Slave*/
    FI2C_EVT_SLAVE_STOP,                /*I2CSTOPMaster Slave */

    FI2C_SLAVE_INTR_EVT_NUM
}; /* slave mode evt */

/**************************** Type Definitions *******************************/

typedef struct
{
    u32         instance_id; /* Device instance id */
    uintptr     base_addr;   /* Device base address */
    u32         irq_num;     /* Device intrrupt id */
    u32         irq_prority;  /* Device intrrupt priority */
    u32         ref_clk_hz;   /* Input reference clock frequency in Hz */
    u32         work_mode;   /* Device work mode Slave or Master */
    u32         slave_addr;  /*Master mode Slave Address writing/reading to/from ,Slave mode set local address*/
    boolean     use_7bit_addr;  /* Slave in-chip address offset in 7bit or 10bit */
    u32         speed_rate;  /* I2C speed rate */
} FI2cConfig; /* Device configure setting */

typedef void (*FI2cEvtHandler)(void *instance_p, void *param);

typedef struct
{
    /* data */
    const void *data_buff;
    u32 tx_total_num;
    volatile u32 tx_cnt;
    u32 flag;/* CMD BIT(8), STOP BIT(9) and RESTART BIT(10) Generation */
} FI2cFrameTX;

typedef struct
{
    /* data */
    void *data_buff;
    u32 rx_total_num;
    volatile u32 rx_cnt;
} FI2cFrameRX;

typedef struct
{
    FI2cConfig      config;             /* Current active configs */
    u32             is_ready;           /* Device is initialized and ready */
    volatile u32    status;
    FI2cFrameTX     txframe;
    FI2cFrameRX     rxframe;
    /** only apply to master device **/
    /* Master intrrupt handler */
    FI2cEvtHandler master_evt_handlers[FI2C_MASTER_INTR_EVT_NUM];

    /** only apply to slave device **/
    /* Slave intrrupt handler */
    FI2cEvtHandler slave_evt_handlers[FI2C_SLAVE_INTR_EVT_NUM];

} FI2c; /* Device instance */

/************************** Variable Definitions *****************************/

/***************** Macros (Inline Functions) Definitions *********************/

/************************** Function Prototypes ******************************/

/* fi2c_sinit.c */
/* I2C */
const FI2cConfig *FI2cLookupConfig(u32 instance_id);

/* fi2c.c */
/* I2C*/
FError FI2cCfgInitialize(FI2c *instance_p, const FI2cConfig *cofig_p);

/* I2C */
void FI2cDeInitialize(FI2c *instance_p);

/* I2C */
const char *FI2cErrorToMessage(FError error);

/* fi2c_master.c */
/* I2C */
FError FI2cMasterReadPoll(FI2c *instance_p, u32 mem_addr, u8 mem_byte_len, u8 *buf_p, u32 buf_len);

/*I2C */
FError FI2cMasterReadIntr(FI2c *instance_p, u32 mem_addr, u8 mem_byte_len, u8 *buf_p, u32 buf_len);

/* I2C */
FError FI2cMasterWriteIntr(FI2c *instance_p, u32 mem_addr, u8 mem_byte_len, const u8 *buf_p, u32 buf_len);

/* I2C */
FError FI2cMasterWritePoll(FI2c *instance_p, u32 mem_addr, u8 mem_byte_len, const u8 *buf_p, u32 buf_len);

/* I2C*/
u32 FI2cGetIntr(FI2c *instance_p);

/* I2C */
FError FI2cMasterSetupIntr(FI2c *instance_p, u32 mask);

/*  */
void FI2cMasterIntrHandler(s32 vector, void *param);

/* I2C */
void FI2cMasterRegisterIntrHandler(FI2c *instance_p, u32 evt, FI2cEvtHandler handler);

/* I2C */
FError FI2cSlaveSetupIntr(FI2c *instance_p);

/*  */
void FI2cSlaveIntrHandler(s32 vector, void *param);

/* I2C */
void FI2cSlaveRegisterIntrHandler(FI2c *instance_p, u32 evt, FI2cEvtHandler handler);

#ifdef __cplusplus
}
#endif

#endif
