/*
*@:Copyright(c)2021PhytiumInformationTechnology,Inc.
*
*SPDX-License-Identifier:Apache-2.0.
*
 * @Date: 2021-03-31 14:59:20
 * @LastEditTime: 2021-04-19 16:17:39
 * @Description: This files is for sd ctrl register
 *
 * @ModifyHistory: **VerWhoDateChanges
 * ---------------------------------------------------------
 */

#ifndef _SDCTRL_HW_H
#define _SDCTRL_HW_H

#include "ft_sdctrl.h"

/* Register Offset */

#define CONTROLL_SETTING_REG_OFFSET 0x00 /* Controller configuration register */
#define ARGUMENT_REG_OFFSET 0x04         /* Parameter register */
#define CMD_SETTING_REG_OFFSET 0x08      /* Command register */
#define CLOCK_DIV_REG_OFFSET 0x0C        /* Clock division register */
#define SOFTWARE_RESET_REG_OFFSET 0x10   /* Reset control register */
#define POWER_CONTROLL_REG_OFFSET 0x14   /* Power control register */
#define TIMEOUT_CMD_REG_OFFSET 0x18      /* cmd Timeout setting register */
#define TIMEOUT_DATA_REG_OFFSET 0x1C     /* Data timeout setting register */
#define NORMAL_INT_EN_REG_OFFSET 0x20    /* Interrupt Enable Register */
#define ERROR_INT_EN_REG_OFFSET 0x24     /* error Interrupt Enable Register */
#define BD_ISR_EN_REG_OFFSET 0x28        /* Data Transfer Interrupt Enable Register */
#define CAPABILIES_REG_OFFSET 0x2c       /* capabilies register */
#define SD_DRV_REG_OFFSET 0x30           /* SD card driver phase register */
#define SD_SAMP_REG_OFFSET 0x34          /* SD card sampling phase register */
#define SD_SEN_REG_OFFSET 0x38           /* Card detection controller */
#define HDS_AXI_REG_CONF1_OFFSET 0x3c    /* AXI boundary configuration register 1 */
#define DAT_IN_M_RX_BD 0x40              /*  SD BD RX address register */
#define DAT_IN_M_TX_BD 0x60              /*  SD BD TX address register */
#define BLK_CNT_REG 0x80                 /*  Block reads and writes configuration registers */
#define HDS_AXI_REG_CONF2 0xa8           /*  AXI boundary configuration register 2 */
#define NORMAL_INT_STATUS_REG 0xc0       /*  Interrupt status register */
#define ERROR_INT_STATUS_REG 0xc4        /*  ERROR interrupt register */
#define BD_ISR_REG 0xc8                  /*  Data Transfer Interrupt Status Register */
#define BD_STATUS 0xcc                   /*  BD descriptor register */
#define STATUS_REG 0xd0                  /*  state register */
#define BLOCK 0xd4                       /*  Block length register */
#define CMD_RESP_1 0xe0                  /*  Command response register 1 */
#define CMD_RESP_2 0xe4                  /*  Command response register 2 */
#define CMD_RESP_3 0xe8                  /*  Command response register 3 */
#define CMD_RESP_4 0xec                  /*  Command response register 4 */

/* Controller configuration register */
#define CONTROLL_SETTING_PERMDR(x) ((x & 3) << 8)  /* Read operation corresponding to the size of the end selection: 00: small end alignment,01: large end alignment,10: SD protocol mode */
#define CONTROLL_SETTING_PERMDW(x) ((x & 3) << 10) /* Write operation corresponding to the size of the endian selection: 00: small endian alignment 01: large endian alignment 10: SD protocol mode*/

/* Parameter register */
#define ARGUMENT_REG(x) (x & 0xffffffff)

/* Command register */
#define CMD_SETTING_RTS(x) ((x & 3) << 0) /* 0: No response 01: Response byte length 136 10: Response byte length 48 11: Response byte length 48 */
#define CMD_SETTING_CRCE (1U << 3)        /* 0: CRC check is not performed on CMD response 1: CRC check is performed on CMD response */
#define CMD_SETTING_CICE (1U << 4)        /* 0CMD  1CMD  */
#define CMD_SETTING_CMDW(x) ((x & 3) << 6)
#define CMD_SETTING_CMDI(x) ((x & 0x3f) << 8) /*  */
#define CMD_SETTING_TRTY(x) ((x & 3) << 14)   /* 10 adtc  ,  */

/*  */
#define CLOCK_DIV_RE(x) (x & 0xffffffff) /* CLKD- SD_frequency= 600M/ (2*(clock_d+1)) */

/*  */
#define SOFTWARE_RESET_SRST (1U)  /*  */
#define SOFTWARE_RESET_BDRST (4U) /* DMA BD  0 */
#define SOFTWARE_RESET_CFCLF (8U) /*  0 */

/* cmd  */
#define TIMEOUT_CMD_REG(x) (x & 0xffffffff) /* command  */

/*  */
#define TIMEOUT_DATA_REG(x) (x & 0xffffffff) /* data  */

/*  */
#define NORMAL_INT_EN_ECC 1U          /*  */
#define NORMAL_INT_EN_ECCRCE 2U       /*  */
#define NORMAL_INT_EN_ECIE (1U << 15) /*  */

/* error  */
#define ERROR_INT_EN_CNR (1U << 4)   /* Command response error interrupted */
#define ERROR_INT_EN_CIR (1U << 3)   /*  */
#define ERROR_INT_EN_CCRCE (1U << 1) /*  CRC  */
#define ERROR_INT_EN_CTE (1U << 0)   /*  */

/*  */
#define BD_ISR_EN_ETRS (1U << 0)      /* DMA  */
#define BD_ISR_EN_EDTE (1U << 3)      /*  */
#define BD_ISR_EN_ECMDE (1U << 4)     /*  */
#define BD_ISR_EN_ETRE (1U << 5)      /*  */
#define BD_ISR_EN_ENRCRCE (1U << 6)   /* CRC  */
#define BD_ISR_EN_EDATFRAXE (1U << 7) /* AXI  */
#define BD_ISR_EN_RESPE (1U << 8)     /*  SD AXI BR  */
#define BD_ISR_EN_EDAISE (1U << 15)   /* DMA  */
#define BD_ISR_ALL_MASK (BD_ISR_EN_ETRS | BD_ISR_EN_EDTE |         \
                         BD_ISR_EN_ECMDE | BD_ISR_EN_ETRE |        \
                         BD_ISR_EN_ENRCRCE | BD_ISR_EN_EDATFRAXE | \
                         BD_ISR_EN_RESPE | BD_ISR_EN_EDAISE)

/*  */
#define CAPABILIES_REG(x) (x & 0xffffffff)

/* SD  */
#define SD_DRV_REG(x) (x & 0xffffffff) /*  */

/* SD  */
#define SD_SAMP_REG(x) (x & 0xffffffff) /*  */
#define SD_SAMP_DEFAULT 11              /* when SD card work in high-speed mode, \
                                        the best sampling pharse is needed to    \
                                        get the correct data */
#define SD_FRRQ_DIV_DEFAULT 5           /* default freq div */
#define SD_CLK_FREQ_400KHZ 400000
#define SD_CLK_FREQ_25MHZ 25000000

/*  */
#define SD_SEN_REG_CREFR (1U << 1)                 /*  AXI  */
#define SD_SEN_REG_CRES (1U << 2)                  /* CARD  0 -0-1 1: -1-0 */
#define SD_SEN_REG_DEBNCE(x) ((x & 0xffffff) << 8) /*  */

/* AXI  1 */
#define HDS_AXI_REG_CONF1_AWDOMAIN_HDS_M(x) ((x & 0x3) << 0)
#define HDS_AXI_REG_CONF1_AWBAR_HDS_M(x) ((x & 0x3) << 2)
#define HDS_AXI_REG_CONF1_ARSNOOP_HDS_M(x) ((x & 0xf) << 4)
#define HDS_AXI_REG_CONF1_ARREGION_HDS_M(x) ((x & 0xf) << 8)
#define HDS_AXI_REG_CONF1_ARDOMAIN_HDS_M(x) ((x & 0x3) << 12)
#define HDS_AXI_REG_CONF1_ARBAR_HDS_M(x) ((x & 0x3) << 14)
#define HDS_AXI_REG_CONF1_AWSNOOP_HDS_M(x) ((x & 0x7) << 16)
#define HDS_AXI_REG_CONF1_AWREGION_HDS_M(x) ((x & 0xF) << 19)

/*  SD BD RX  */
#define DAT_IN_M_RX_BD_MASK(x) (x & 0xffffffff) /* dma 4  cycle , 4B- 4B-SD  4B- SD  4B */

/*  SD BD TX  */
#define DAT_IN_M_TX_BD_MASK(x) (x & 0xffffffff) /* dma 4  cycle , 4B- 4B-SD  4B- SD  4B */

/*   */
#define BLK_CNT(x) (x & 0xffffffff) /* dma block num setting */

/*  AXI  2 */
#define HDS_AXI_REG_CONF2_D_ARPROT(x) ((x & 0x7) << 27)
#define HDS_AXI_REG_CONF2_SD_AWPROT(x) ((x & 0x7) << 24)
#define HDS_AXI_REG_CONF2_SD_ARCACHE_M(x) ((x & 0xf) << 20)
#define HDS_AXI_REG_CONF2_SD_AWCACHE_M(x) ((x & 0xf) << 16)
#define HDS_AXI_REG_CONF2_RESERVED(x) ((x & 0x3) << 14)
#define HDS_AXI_REG_CONF2_HDA_ARPRO(x) ((x & 0x7) << 11)
#define HDS_AXI_REG_CONF2_HDA_AWPROT(x) ((x & 0x7) << 8)
#define HDS_AXI_REG_CONF2_HDA_ARCACHE_M(x) ((x & 0xf) << 4)
#define HDS_AXI_REG_CONF2_HDA_AWCACHE_M(x) ((x & 0xf) << 0)

/*   */
#define NORMAL_INT_STATUS_EI (1U << 15) /*  */
#define NORMAL_INT_STATUS_CR (1U << 1)  /*  */
#define NORMAL_INT_STATUS_CC 1U         /*  */
#define NORMAL_INT_STATUS_ALL_MASK (NORMAL_INT_STATUS_EI | NORMAL_INT_STATUS_CR | NORMAL_INT_STATUS_CC)

/*  error  */
#define ERROR_INT_STATUS_CNR (1U << 4)   /*  */
#define ERROR_INT_STATUS_CIR (1U << 3)   /*  */
#define ERROR_INT_STATUS_CCRCE (1U << 1) /*  CRC  */
#define ERROR_INT_STATUS_CTE 1U          /*  */
#define ERROR_INT_STATUS_ALL_MASK (ERROR_INT_STATUS_CNR | ERROR_INT_STATUS_CIR | ERROR_INT_STATUS_CCRCE | ERROR_INT_STATUS_CTE)

/*   */
#define BD_ISR_REG_DAIS (1U << 15)   /* DMA */
#define BD_ISR_REG_RESPE (1U << 8)   /*  SD AXI BR */
#define BD_ISR_REG_DATFRAX (1U << 7) /* axi */
#define BD_ISR_REG_NRCRC (1U << 6)   /*  CRC */
#define BD_ISR_REG_TRE (1U << 5)     /* CRC */
#define BD_ISR_REG_CMDE (1U << 4)    /* */
#define BD_ISR_REG_DTE (1U << 3)     /* */
#define BD_ISR_REG_TRS (1U << 0)     /* DMA */

/*  bd  */
#define BD_STATUS_REG(x) (x & 0xffffffff) /*  bd  */

/*   */
#define STATUS_REG_DATMAST(x) ((x & 0xf) << 27) /* data_master  */
#define STATUS_REG_CDIF (1U << 26)              /*  */
#define STATUS_REG_CDRF (1U << 25)              /*  */
#define STATUS_REG_CLSL (1U << 24)              /*  */
#define STATUS_REG_DLSL(x) ((x & 0xf) << 20)    /*  */
#define STATUS_REG_CDSL (1U << 19)              /*  */
#define STATUS_REG_CST(x) ((x & 0xf) << 12)     /* cmd_host state  */
#define STATUS_REG_CSM(x) ((x & 0X1F) << 7)
#define STATUS_REG_DAT_AVA (1 << 6) /* DAT_AVA   */
#define STATUS_REG_CRC_VALID (1 << 5)
#define STATUS_REG_CICMD 1U /* RO 0x0 CMD  */

/*   */
#define BLOCK_RGE(x) (x & 0xffffffff) /*   */

/*   1 */
#define CMD_RESP_1_REG(x) (x & 0xffffffff)

/*   2 */
#define CMD_RESP_2_REG(x) (x & 0xffffffff)

/*   3 */
#define CMD_RESP_3_REG(x) (x & 0xffffffff)

/*   4 */
#define CMD_RESP_4_REG(x) (x & 0xffffffff)

#endif // !
