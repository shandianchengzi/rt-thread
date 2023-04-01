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
 * FilePath: fnand_dma.h
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 08:56:27
 * Description: This files is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */

#ifndef DRIVERS_NAND_FNAND_DMA_H
#define DRIVERS_NAND_FNAND_DMA_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "ftypes.h"

#define FNAND_CMDCTRL_TYPE_RESET 0x00    /* reset */
#define FNAND_CMDCTRL_TYPE_SET_FTR 0x01  /* Set features */
#define FNAND_CMDCTRL_TYPE_GET_FTR 0x02  /* Get features */
#define FNAND_CMDCTRL_TYPE_READ_ID 0x03  /* Read ID */
#define FNAND_CMDCTRL_TYPE_READ_COL 0x03 /* Read Column */
#define FNAND_CMDCTRL_TYPE_PAGE_PRO 0x04 /* Page program */
#define FNAND_CMDCTRL_TYPE_ERASE 0x05    /* Block Erase */
#define FNAND_CMDCTRL_TYPE_READ 0x06     /* Read */
#define FNAND_CMDCTRL_TYPE_TOGGLE 0x07   /* Toggle Two_plane */

#define FNAND_CMDCTRL_READ_PARAM 0x02
#define FNAND_CMDCTRL_READ_STATUS 0x03

#define FNAND_CMDCTRL_CH_READ_COL 0x03
#define FNAND_CMDCTRL_CH_ROW_ADDR 0x01
#define FNAND_CMDCTRL_CH_WR_COL 0x01

#define FNAND_NFC_ADDR_MAX_LEN 0x5

#define FNAND_DESCRIPTORS_SIZE 16

struct CmdCtrl
{
    u16 csel : 4;     /* NAND FLASH   */
    u16 dbc : 1;      /* 211CMD1 */
    u16 addr_cyc : 3; /* b000: b001:1 */
    u16 nc : 1;       /*  */
    u16 cmd_type : 4; /*  */
    u16 dc : 1;       /* 1 */
    u16 auto_rs : 1;  /*  */
    u16 ecc_en : 1;   /* ECC 1 ECC1ECC  */
};

struct FNandDmaDescriptor
{
    u8 cmd0; /* NAND FLASH  */
    u8 cmd1; /* NAND FLASH  */
    union
    {
        u16 ctrl;
        struct CmdCtrl nfc_ctrl;
    } cmd_ctrl; /* 16 */
    u8 addr[FNAND_NFC_ADDR_MAX_LEN];
    u16 page_cnt;
    u8 mem_addr_first[FNAND_NFC_ADDR_MAX_LEN];

} __attribute__((packed)) __attribute__((aligned(128)));



typedef struct
{
    u8 *addr_p; /* Address  */
    u32 addr_length;
    uintptr phy_address;
    u32 phy_bytes_length;
    u32 chip_addr;
    u8 contiune_dma; /*  */
} FNandDmaPackData;


/* DMA format */
typedef struct
{
    s32 start_cmd;  /* Start command */
    s32 end_cmd;    /* End command */
    u8 addr_cycles; /* Number of address cycles */
    u8 cmd_type;    /* Presentation command type ,followed by FNAND_CMDCTRL_XXXX */
    u8 ecc_en;      /* Hardware ecc open */
    u8 auto_rs;     /*  */
} FNandCmdFormat;


#ifdef __cplusplus
}
#endif

#endif // !
