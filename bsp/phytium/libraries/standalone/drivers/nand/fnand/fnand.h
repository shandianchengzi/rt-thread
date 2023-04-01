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
 * FilePath: fnand.h
 * Date: 2022-05-07 15:40:42
 * LastEditTime: 2022-05-07 15:40:42
 * Description: This files is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */
#ifndef DRIVERS_NAND_FNAND_H
#define DRIVERS_NAND_FNAND_H

#ifdef __cplusplus
extern "C"
{
#endif


#include "ftypes.h"
#include "fassert.h"
#include "fnand_dma.h"
#include "fnand_timing.h"
#include "fparameters.h"
#include "fkernel.h"

#define FNAND_ERR_OPERATION FT_CODE_ERR(ErrModBsp, ErrNand, 0x1u)
#define FNAND_ERR_INVAILD_PARAMETER FT_CODE_ERR(ErrModBsp, ErrNand, 0x2u)
#define FNAND_IS_BUSY FT_CODE_ERR(ErrModBsp, ErrNand, 0x3u)
#define FNAND_OP_TIMEOUT FT_CODE_ERR(ErrModBsp, ErrNand, 0x4u)
#define FNAND_VALUE_ERROR FT_CODE_ERR(ErrModBsp, ErrNand, 0x7u)
#define FNAND_VALUE_FAILURE FT_CODE_ERR(ErrModBsp, ErrNand, 0x8u)
#define FNAND_NOT_FET_TOGGLE_MODE FT_CODE_ERR(ErrModBsp, ErrNand, 0xCu)
#define FNAND_ERR_READ_ECC  FT_CODE_ERR(ErrModBsp, ErrNand, 0xBu)
#define FNAND_ERR_IRQ_LACK_OF_CALLBACK  FT_CODE_ERR(ErrModBsp, ErrNand, 0xCu)
#define FNAND_ERR_IRQ_OP_FAILED  FT_CODE_ERR(ErrModBsp, ErrNand, 0xdu)
#define FNAND_ERR_NOT_MATCH  FT_CODE_ERR(ErrModBsp, ErrNand, 0xEu)



#define FNAND_MAX_BLOCKS 32768    /* Max number of Blocks */
#define FNAND_MAX_PAGE_SIZE 16384 /* Max page size of NAND \
                    flash */
#define FNAND_MAX_SPARE_SIZE 1024  /* Max spare bytes of a NAND \
                    flash page */


/* dma */
#define FNAND_DMA_MAX_LENGTH (32*1024)

/* options */
/* These constants are used as option to FNandSetOption()  */
#define FNAND_OPS_INTER_MODE_SELECT 1U      /*  */


/* These constants are used as parameters to FNandSetIsrHandler() */
#define FNAND_WORK_MODE_POLL 0U
#define FNAND_WORK_MODE_ISR  1U


/* NAND Flash Interface */

#define FNAND_ONFI_MODE     0U
#define FNAND_TOGGLE_MODE   1U


typedef enum
{
    FNAND_ASYNC_TIM_INT_MODE0 = 0,
    FNAND_ASYNC_TIM_INT_MODE1,
    FNAND_ASYNC_TIM_INT_MODE2,
    FNAND_ASYNC_TIM_INT_MODE3,
    FNAND_ASYNC_TIM_INT_MODE4,
} FNandAsyncTimint;

typedef enum
{
    FNAND_CMD_TYPE = 0,     /* cmd  */
    FNAND_WRITE_PAGE_TYPE,     /* PAGE program  */
    FNAND_READ_PAGE_TYPE,     /* PAGE read  */
    FNAND_WAIT_ECC_TYPE, /* Waiting ECC FINISH  */
    FNAND_TYPE_NUM
} FNandOperationType;

/* Irq Callback events */
typedef enum
{
    FNAND_IRQ_BUSY_EVENT = 0,/* nandflash */
    FNAND_IRQ_DMA_BUSY_EVENT, /* dma */
    FNAND_IRQ_DMA_PGFINISH_EVENT, /* dma */
    FNAND_IRQ_DMA_FINISH_EVENT, /* dma */
    FNAND_IRQ_FIFO_EMP_EVENT, /* fifo */
    FNAND_IRQ_FIFO_FULL_EVENT, /* fifo */
    FNAND_IRQ_FIFO_TIMEOUT_EVENT, /* fifo */
    FNAND_IRQ_CMD_FINISH_EVENT, /* nand */
    FNAND_IRQ_PGFINISH_EVENT, /* nand */
    FNAND_IRQ_RE_EVENT, /* re_n */
    FNAND_IRQ_DQS_EVENT, /* dqs */
    FNAND_IRQ_RB_EVENT, /* rb_nbusy */
    FNAND_IRQ_ECC_FINISH_EVENT, /* ecc */
    FNAND_IRQ_ECC_ERR_EVENT /* ecc */
} FNAND_CALL_BACK_EVENT;

typedef struct
{
    u32 bytes_per_page;       /* Bytes per page */
    u32 spare_bytes_per_page; /* Size of spare area in bytes */
    u32 pages_per_block;      /* Pages per block */
    u32 blocks_per_lun;       /* Bocks per LUN */
    u8 num_lun;               /* Total number of LUN */
    u8 flash_width;           /* Data width of flash device */
    u64 num_pages;            /* Total number of pages in device */
    u64 num_blocks;           /* Total number of blocks in device */
    u64 block_size;           /* Size of a block in bytes */
    u64 device_size;          /* Total device size in bytes */
    u8 rowaddr_cycles;        /* Row address cycles */
    u8 coladdr_cycles;        /* Column address cycles */
    u32 hw_ecc_steps;         /* number of ECC steps per page */
    u32 hw_ecc_length;        /* ecc */
    u32 ecc_offset;           /* spare_bytes_per_page - hw_ecc_length = obbecc */
    u32 ecc_step_size;        /* ecc  */
} FNandNandGeometry;

typedef enum
{
    FNAND_ASYN_SDR = 0,    /* ONFI & Toggle async */
    FNAND_ONFI_DDR = 1,    /* ONFI sync */
    FNAND_TOG_ASYN_DDR = 2 /* Toggle async */
} FNandInterMode;

typedef enum
{
    FNAND_TIMING_MODE0 = 0,
    FNAND_TIMING_MODE1 = 1,
    FNAND_TIMING_MODE2 = 2,
    FNAND_TIMING_MODE3 = 3,
    FNAND_TIMING_MODE4 = 4,
    FNAND_TIMING_MODE5 = 5,
} FNandTimingMode;

typedef struct
{
    u32 instance_id; /* Id of device*/
    u32 irq_num;     /* Irq number */
    volatile uintptr_t base_address;
    u32 ecc_strength; /* ecc  */
    u32 ecc_step_size; /* ecc  */
} FNandConfig;

/**
 * Bad block pattern
 */
typedef struct
{
    u32 options;   /**< Options to search the bad block pattern */
    u32 offset;    /**< Offset to search for specified pattern */
    u32 length;    /**< Number of bytes to check the pattern */
    u8 pattern[2]; /**< Pattern format to search for */
} FNandBadBlockPattern;


typedef struct
{
    u32 page_addr;
    u8 *page_buf; /* page  */
    u32 page_offset; /* offset */
    u32 page_length; /* offset */
    s32 obb_required; /* obb ,1 oob  */
    u8 *oob_buf; /* obb  */
    u32 oob_offset; /* offset */
    u32 oob_length; /* offset */
    u32 chip_addr; /*  */
} FNandOpData;

/**
 * Bad block table descriptor
 */
typedef struct
{
    u32 page_offset;   /* Page offset where BBT resides */
    u32 sig_offset;    /* Signature offset in Spare area */
    u32 ver_offset;    /* Offset of BBT version */
    u32 sig_length;    /* Length of the signature */
    u32 max_blocks;    /* Max blocks to search for BBT */
    char signature[4]; /* BBT signature */
    u8 version;        /* BBT version */
    u32 valid;         /* BBT descriptor is valid or not */
} FNandBbtDesc;

typedef struct
{
    u8 bbt[FNAND_MAX_BLOCKS >> 2];
    FNandBbtDesc bbt_desc;           /* Bad block table descriptor */
    FNandBbtDesc bbt_mirror_desc;    /* Mirror BBT descriptor */
    FNandBadBlockPattern bb_pattern; /* Bad block pattern to search */
} FNandBadBlockManager;

/* DMA */

/* DMA buffer  */
struct FNandDmaBuffer
{
    u8 data_buffer[FNAND_DMA_MAX_LENGTH];
} __attribute__((packed)) __attribute__((aligned(128)));

/* operation api */
typedef struct _FNand FNand;

typedef FError(*FNandTransferP)(FNand *instance_p, FNandOpData *op_data_p);
typedef FError(*FNandEraseP)(FNand *instance_p, u32 page_address, u32 chip_addr);

typedef void (*FnandIrqEventHandler)(void *args, FNAND_CALL_BACK_EVENT event) ;
typedef FError(*FNandOperationWaitIrqCallback)(void *args);


typedef struct
{
    u8 data[8];
    u32 len;

} FNandId;

typedef struct _FNand
{
    u32 is_ready; /* Device is ininitialized and ready*/
    FNandConfig config;
    u32 work_mode;              /* NAND controler work mode */

    /* nand flash info */
    FNandInterMode inter_mode[FNAND_CONNECT_MAX_NUM]; /* NAND controler timing work mode */
    FNandTimingMode timing_mode[FNAND_CONNECT_MAX_NUM];
    u32 nand_flash_interface[FNAND_CONNECT_MAX_NUM] ; /* Nand Flash Interface , followed by FNAND_ONFI_MODE \ FNAND_TOGGLE_MODE*/

    struct FNandDmaBuffer dma_data_buffer;          /* DMA data buffer */
    struct FNandDmaBuffer descriptor_buffer;        /* DMA descriptor */
    struct FNandSdrTimings sdr_timing;              /* SDR NAND chip timings */

    /* bbm */
    FNandBadBlockManager bbt_manager[FNAND_CONNECT_MAX_NUM];    /* bad block manager handler */
    /* nand detect */
    FNandNandGeometry nand_geometry[FNAND_CONNECT_MAX_NUM];     /* nand flash infomation */
    /* dma  */
    FnandIrqEventHandler irq_event_fun_p;                       /* Interrupt event response function */
    void *irq_args;

    FNandOperationWaitIrqCallback wait_irq_fun_p;               /* The NAND controller operates the wait function */
    void *wait_args;

    /* operations */
    FNandTransferP write_p ;                                    /* Write page function */
    FNandTransferP read_p ;                                     /* Read page function */
    FNandTransferP write_oob_p ;                                /* Write page spare space function */
    FNandTransferP read_oob_p ;                                 /* Read page spare space function */
    FNandTransferP write_hw_ecc_p ;                             /* Write page with hardware function */
    FNandTransferP read_hw_ecc_p ;                              /* Read page with hardware function */
    FNandEraseP erase_p;                                        /* Erase block  function */
} FNand;

FNandConfig *FNandLookupConfig(u32 instance_id);
FError FNandCfgInitialize(FNand *instance_p,
                          FNandConfig *config_p);
FError FNandScan(FNand *instance_p);
FError FNandSetOption(FNand *instance_p, u32 options, u32 value);

/* API */
FError FNandWritePage(FNand *instance_p, u32 page_addr, u8 *buffer, u32 page_copy_offset, u32 length, u8 *oob_buffer, u32 oob_copy_offset, u32 oob_length, u32 chip_addr);
FError FNandWritePageRaw(FNand *instance_p, u32 page_addr, u8 *buffer, u32 page_copy_offset, u32 length, u8 *oob_buffer, u32 oob_copy_offset, u32 oob_length, u32 chip_addr);
FError FNandReadPage(FNand *instance_p, u32 page_addr, u8 *buffer, u32 page_copy_offset, u32 length, u8 *oob_buffer, u32 oob_copy_offset, u32 oob_length, u32 chip_addr);
FError FNandEraseBlock(FNand *instance_p, u32 block, u32 chip_addr);
FError FNandReadPageOOb(FNand *instance_p, u32 page_addr, u8 *oob_buffer, u32 oob_copy_offset, u32 oob_length, u32 chip_addr);
FError FNandWritePageOOb(FNand *instance_p, u32 page_addr, u8 *oob_buffer, u32 page_copy_offset, u32 oob_length, u32 chip_addr);
FError FNandReadPageRaw(FNand *instance_p, u32 page_addr, u8 *buffer, u32 page_copy_offset, u32 length, u8 *oob_buffer, u32 oob_copy_offset, u32 oob_length, u32 chip_addr);
/* irq */
void FNandSetIsrHandler(FNand *instance_p, FnandIrqEventHandler event_p, void *irq_args);
void FNandIrqHandler(s32 vector, void *param);
void FNandOperationWaitIrqRegister(FNand *instance_p, FNandOperationWaitIrqCallback wait_irq_fun_p, void *wait_args);
void FNandIrqDisable(FNand *instance_p, u32 int_mask);
void FNandIsrEnable(FNand *instance_p, u32 int_mask);
/* bbm */
void FNandInitBbtDesc(FNand *instance_p);
FError FNandScanBbt(FNand *instance_p, u32 target_addr);
FError FNandIsBlockBad(FNand *instance_p, u32 block, u32 target_addr);
FError FNandMarkBlockBad(FNand *instance_p, u32 block, u32 chip_addr);
#ifdef __cplusplus
}
#endif



#endif // !
