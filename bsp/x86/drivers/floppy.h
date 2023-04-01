/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 */
#ifndef _FLOPPY_H
#define _FLOPPY_H

#define FD_STATUS           0x3f4                   // 
#define FD_DATA             0x3f5                   // 
#define FD_DOR              0x3f2                   // 
#define FD_DIR              0x3f7                   // 
#define FD_DCR              0x3f7                   // 

/*  */

#define STATUS_BUSYMASK     0x0F                    // 
#define STATUS_BUSY         0x10                    // 
#define STATUS_DMA          0x20                    // 0 - DMA 1 - DMA 
#define STATUS_DIR          0x40                    // 0 - CPU .. fdc1 - 
#define STATUS_READY        0x80                    // 


/*0ST0 */

#define ST0_DS              0x03                    // 
#define ST0_HA              0x04                    // 
#define ST0_NR              0x08                    // 
#define ST0_ECE             0x10                    // 
#define ST0_SE              0x20                    // 
#define ST0_INTR            0xC0                    // 00 - 
                                                    // 01 - 10 - 11 - FDD 

/*1ST1 */

#define ST1_MAM             0x01                    // (ID AM)
#define ST1_WP              0x02                    // 
#define ST1_ND              0x04                    // 
#define ST1_OR              0x10                    // DMA 
#define ST1_CRC             0x20                    // CRC 
#define ST1_EOC             0x80                    // 

/*2ST2 */

#define ST2_MAM             0x01                    // 
#define ST2_BC              0x02                    // 
#define ST2_SNS             0x04                    // 
#define ST2_SEH             0x08                    // 
#define ST2_WC              0x10                    // 
#define ST2_CRC             0x20                    // CRC 
#define ST2_CM              0x40                    // 

/*3ST3 */

#define ST3_HA              0x04                    // 
#define ST3_TZ              0x10                    // 
#define ST3_WP              0x40                    // 


/*  */

#define FD_RECALIBRATE      0x07                    // ()
#define FD_SEEK             0x0F                    // 
#define FD_READ             0xE6                    // MT MFM 
#define FD_WRITE            0xC5                    // MTMFM
#define FD_SENSEI           0x08                    // 
#define FD_SPECIFY          0x03                    // 


/* DMA  */
#define DMA_READ            0x46                    // DMA DMA DMA 1211
#define DMA_WRITE           0x4A

extern void rt_floppy_init(void);

#endif
