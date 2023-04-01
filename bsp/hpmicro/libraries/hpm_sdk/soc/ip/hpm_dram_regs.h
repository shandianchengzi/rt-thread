/*
 * Copyright (c) 2021-2022 hpmicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#ifndef HPM_DRAM_H
#define HPM_DRAM_H

typedef struct {
    __RW uint32_t CTRL;                        /* 0x0: Control Register */
    __R  uint8_t  RESERVED0[4];                /* 0x4 - 0x7: Reserved */
    __RW uint32_t BMW0;                        /* 0x8: Bus (AXI) Weight Control Register 0 */
    __RW uint32_t BMW1;                        /* 0xC: Bus (AXI) Weight Control Register 1 */
    __RW uint32_t BR[2];                       /* 0x10 - 0x14: Base Register 0 (for SDRAM CS0 device) */
    __R  uint8_t  RESERVED1[32];               /* 0x18 - 0x37: Reserved */
    __RW uint32_t INTEN;                       /* 0x38: Interrupt Enable Register */
    __W  uint32_t INTR;                        /* 0x3C: Interrupt Status Register */
    __RW uint32_t SDRCTRL0;                    /* 0x40: SDRAM Control Register 0 */
    __RW uint32_t SDRCTRL1;                    /* 0x44: SDRAM Control Register 1 */
    __RW uint32_t SDRCTRL2;                    /* 0x48: SDRAM Control Register 2 */
    __RW uint32_t SDRCTRL3;                    /* 0x4C: SDRAM Control Register 3 */
    __R  uint8_t  RESERVED2[64];               /* 0x50 - 0x8F: Reserved */
    __RW uint32_t SADDR;                       /* 0x90: IP Command Control Register 0 */
    __RW uint32_t DATSZ;                       /* 0x94: IP Command Control Register 1 */
    __RW uint32_t BYTEMSK;                     /* 0x98: IP Command Control Register 2 */
    __RW uint32_t IPCMD;                       /* 0x9C: IP Command Register */
    __RW uint32_t IPTX;                        /* 0xA0: TX DATA Register */
    __R  uint8_t  RESERVED3[12];               /* 0xA4 - 0xAF: Reserved */
    __RW uint32_t IPRX;                        /* 0xB0: RX DATA Register */
    __R  uint8_t  RESERVED4[12];               /* 0xB4 - 0xBF: Reserved */
    __R  uint32_t STAT0;                       /* 0xC0: Status Register 0 */
    __R  uint8_t  RESERVED5[140];              /* 0xC4 - 0x14F: Reserved */
    __RW uint32_t DLYCFG;                      /* 0x150: Delay Line Config Register */
} DRAM_Type;


/* Bitfield definition for register: CTRL */
/*
 * BTO (RW)
 *
 * Bus timeout cycles
 * AXI Bus timeout cycle is as following (255*(2^BTO)):
 * 00000b - 255*1
 * 00001-11110b - 255*2 - 255*2^30
 * 11111b - 255*2^31
 */
#define DRAM_CTRL_BTO_MASK (0x1F000000UL)
#define DRAM_CTRL_BTO_SHIFT (24U)
#define DRAM_CTRL_BTO_SET(x) (((uint32_t)(x) << DRAM_CTRL_BTO_SHIFT) & DRAM_CTRL_BTO_MASK)
#define DRAM_CTRL_BTO_GET(x) (((uint32_t)(x) & DRAM_CTRL_BTO_MASK) >> DRAM_CTRL_BTO_SHIFT)

/*
 * CTO (RW)
 *
 * Command Execution timeout cycles
 * When Command Execution time exceed this timeout cycles, IPCMDERR or AXICMDERR interrupt is
 * generated. When CTO is set to zero, timeout cycle is 256*1024 cycle. otherwisee timeout cycle is
 * CTO*1024 cycle.
 */
#define DRAM_CTRL_CTO_MASK (0xFF0000UL)
#define DRAM_CTRL_CTO_SHIFT (16U)
#define DRAM_CTRL_CTO_SET(x) (((uint32_t)(x) << DRAM_CTRL_CTO_SHIFT) & DRAM_CTRL_CTO_MASK)
#define DRAM_CTRL_CTO_GET(x) (((uint32_t)(x) & DRAM_CTRL_CTO_MASK) >> DRAM_CTRL_CTO_SHIFT)

/*
 * DQS (RW)
 *
 * DQS (read strobe) mode
 * 0b - Dummy read strobe loopbacked internally
 * 1b - Dummy read strobe loopbacked from DQS pad
 */
#define DRAM_CTRL_DQS_MASK (0x4U)
#define DRAM_CTRL_DQS_SHIFT (2U)
#define DRAM_CTRL_DQS_SET(x) (((uint32_t)(x) << DRAM_CTRL_DQS_SHIFT) & DRAM_CTRL_DQS_MASK)
#define DRAM_CTRL_DQS_GET(x) (((uint32_t)(x) & DRAM_CTRL_DQS_MASK) >> DRAM_CTRL_DQS_SHIFT)

/*
 * DIS (RW)
 *
 * Module Disable
 * 0b - Module enabled
 * 1b - Module disabled
 */
#define DRAM_CTRL_DIS_MASK (0x2U)
#define DRAM_CTRL_DIS_SHIFT (1U)
#define DRAM_CTRL_DIS_SET(x) (((uint32_t)(x) << DRAM_CTRL_DIS_SHIFT) & DRAM_CTRL_DIS_MASK)
#define DRAM_CTRL_DIS_GET(x) (((uint32_t)(x) & DRAM_CTRL_DIS_MASK) >> DRAM_CTRL_DIS_SHIFT)

/*
 * RST (RW)
 *
 * Software Reset
 * Reset all internal logic in SEMC except configuration register
 */
#define DRAM_CTRL_RST_MASK (0x1U)
#define DRAM_CTRL_RST_SHIFT (0U)
#define DRAM_CTRL_RST_SET(x) (((uint32_t)(x) << DRAM_CTRL_RST_SHIFT) & DRAM_CTRL_RST_MASK)
#define DRAM_CTRL_RST_GET(x) (((uint32_t)(x) & DRAM_CTRL_RST_MASK) >> DRAM_CTRL_RST_SHIFT)

/* Bitfield definition for register: BMW0 */
/*
 * RWS (RW)
 *
 * Weight of slave hit with Read/Write Switch. This weight score is valid when queue command's slave is
 * same as current executing command with read/write operation switch.
 */
#define DRAM_BMW0_RWS_MASK (0xFF0000UL)
#define DRAM_BMW0_RWS_SHIFT (16U)
#define DRAM_BMW0_RWS_SET(x) (((uint32_t)(x) << DRAM_BMW0_RWS_SHIFT) & DRAM_BMW0_RWS_MASK)
#define DRAM_BMW0_RWS_GET(x) (((uint32_t)(x) & DRAM_BMW0_RWS_MASK) >> DRAM_BMW0_RWS_SHIFT)

/*
 * SH (RW)
 *
 * Weight of Slave Hit without read/write switch. This weight score is valid when queue command's slave is
 * same as current executing command without read/write operation switch.
 */
#define DRAM_BMW0_SH_MASK (0xFF00U)
#define DRAM_BMW0_SH_SHIFT (8U)
#define DRAM_BMW0_SH_SET(x) (((uint32_t)(x) << DRAM_BMW0_SH_SHIFT) & DRAM_BMW0_SH_MASK)
#define DRAM_BMW0_SH_GET(x) (((uint32_t)(x) & DRAM_BMW0_SH_MASK) >> DRAM_BMW0_SH_SHIFT)

/*
 * AGE (RW)
 *
 * Weight of AGE calculation. Each command in queue has an age signal to indicate its wait period. It is
 * multiplied by WAGE to get weight score.
 */
#define DRAM_BMW0_AGE_MASK (0xF0U)
#define DRAM_BMW0_AGE_SHIFT (4U)
#define DRAM_BMW0_AGE_SET(x) (((uint32_t)(x) << DRAM_BMW0_AGE_SHIFT) & DRAM_BMW0_AGE_MASK)
#define DRAM_BMW0_AGE_GET(x) (((uint32_t)(x) & DRAM_BMW0_AGE_MASK) >> DRAM_BMW0_AGE_SHIFT)

/*
 * QOS (RW)
 *
 * Weight of QOS calculation. AXI bus access has AxQOS signal set, which is used as a priority indicator
 * for the associated write or read transaction. A higher value indicates a higher priority transaction. AxQOS
 * is multiplied by WQOS to get weight score.
 */
#define DRAM_BMW0_QOS_MASK (0xFU)
#define DRAM_BMW0_QOS_SHIFT (0U)
#define DRAM_BMW0_QOS_SET(x) (((uint32_t)(x) << DRAM_BMW0_QOS_SHIFT) & DRAM_BMW0_QOS_MASK)
#define DRAM_BMW0_QOS_GET(x) (((uint32_t)(x) & DRAM_BMW0_QOS_MASK) >> DRAM_BMW0_QOS_SHIFT)

/* Bitfield definition for register: BMW1 */
/*
 * BR (RW)
 *
 * Weight of Bank Rotation. This weight score is valid when queue command's bank is not same as current
 * executing command.
 */
#define DRAM_BMW1_BR_MASK (0xFF000000UL)
#define DRAM_BMW1_BR_SHIFT (24U)
#define DRAM_BMW1_BR_SET(x) (((uint32_t)(x) << DRAM_BMW1_BR_SHIFT) & DRAM_BMW1_BR_MASK)
#define DRAM_BMW1_BR_GET(x) (((uint32_t)(x) & DRAM_BMW1_BR_MASK) >> DRAM_BMW1_BR_SHIFT)

/*
 * RWS (RW)
 *
 * Weight of slave hit with Read/Write Switch. This weight score is valid when queue command's slave is
 * same as current executing command with read/write operation switch.
 */
#define DRAM_BMW1_RWS_MASK (0xFF0000UL)
#define DRAM_BMW1_RWS_SHIFT (16U)
#define DRAM_BMW1_RWS_SET(x) (((uint32_t)(x) << DRAM_BMW1_RWS_SHIFT) & DRAM_BMW1_RWS_MASK)
#define DRAM_BMW1_RWS_GET(x) (((uint32_t)(x) & DRAM_BMW1_RWS_MASK) >> DRAM_BMW1_RWS_SHIFT)

/*
 * PH (RW)
 *
 * Weight of Slave Hit without read/write switch. This weight score is valid when queue command's slave is
 * same as current executing command without read/write operation switch.
 */
#define DRAM_BMW1_PH_MASK (0xFF00U)
#define DRAM_BMW1_PH_SHIFT (8U)
#define DRAM_BMW1_PH_SET(x) (((uint32_t)(x) << DRAM_BMW1_PH_SHIFT) & DRAM_BMW1_PH_MASK)
#define DRAM_BMW1_PH_GET(x) (((uint32_t)(x) & DRAM_BMW1_PH_MASK) >> DRAM_BMW1_PH_SHIFT)

/*
 * AGE (RW)
 *
 * Weight of AGE calculation. Each command in queue has an age signal to indicate its wait period. It is
 * multiplied by WAGE to get weight score.
 */
#define DRAM_BMW1_AGE_MASK (0xF0U)
#define DRAM_BMW1_AGE_SHIFT (4U)
#define DRAM_BMW1_AGE_SET(x) (((uint32_t)(x) << DRAM_BMW1_AGE_SHIFT) & DRAM_BMW1_AGE_MASK)
#define DRAM_BMW1_AGE_GET(x) (((uint32_t)(x) & DRAM_BMW1_AGE_MASK) >> DRAM_BMW1_AGE_SHIFT)

/*
 * QOS (RW)
 *
 * Weight of QOS calculation. AXI bus access has AxQOS signal set, which is used as a priority indicator
 * for the associated write or read transaction. A higher value indicates a higher priority transaction. AxQOS
 * is multiplied by WQOS to get weight score.
 */
#define DRAM_BMW1_QOS_MASK (0xFU)
#define DRAM_BMW1_QOS_SHIFT (0U)
#define DRAM_BMW1_QOS_SET(x) (((uint32_t)(x) << DRAM_BMW1_QOS_SHIFT) & DRAM_BMW1_QOS_MASK)
#define DRAM_BMW1_QOS_GET(x) (((uint32_t)(x) & DRAM_BMW1_QOS_MASK) >> DRAM_BMW1_QOS_SHIFT)

/* Bitfield definition for register array: BR */
/*
 * BASE (RW)
 *
 * Base Address
 * This field determines high position 20 bits of SoC level Base Address. SoC level Base Address low
 * position 12 bits are all zero.
 */
#define DRAM_BR_BASE_MASK (0xFFFFF000UL)
#define DRAM_BR_BASE_SHIFT (12U)
#define DRAM_BR_BASE_SET(x) (((uint32_t)(x) << DRAM_BR_BASE_SHIFT) & DRAM_BR_BASE_MASK)
#define DRAM_BR_BASE_GET(x) (((uint32_t)(x) & DRAM_BR_BASE_MASK) >> DRAM_BR_BASE_SHIFT)

/*
 * SIZE (RW)
 *
 * Memory size
 * 00000b - 4KB
 * 00001b - 8KB
 * 00010b - 16KB
 * 00011b - 32KB
 * 00100b - 64KB
 * 00101b - 128KB
 * 00110b - 256KB
 * 00111b - 512KB
 * 01000b - 1MB
 * 01001b - 2MB
 * 01010b - 4MB
 * 01011b - 8MB
 * 01100b - 16MB
 * 01101b - 32MB
 * 01110b - 64MB
 * 01111b - 128MB
 * 10000b - 256MB
 * 10001b - 512MB
 * 10010b - 1GB
 * 10011b - 2GB
 * 10100-11111b - 4GB
 */
#define DRAM_BR_SIZE_MASK (0x3EU)
#define DRAM_BR_SIZE_SHIFT (1U)
#define DRAM_BR_SIZE_SET(x) (((uint32_t)(x) << DRAM_BR_SIZE_SHIFT) & DRAM_BR_SIZE_MASK)
#define DRAM_BR_SIZE_GET(x) (((uint32_t)(x) & DRAM_BR_SIZE_MASK) >> DRAM_BR_SIZE_SHIFT)

/*
 * VLD (RW)
 *
 * Valid
 */
#define DRAM_BR_VLD_MASK (0x1U)
#define DRAM_BR_VLD_SHIFT (0U)
#define DRAM_BR_VLD_SET(x) (((uint32_t)(x) << DRAM_BR_VLD_SHIFT) & DRAM_BR_VLD_MASK)
#define DRAM_BR_VLD_GET(x) (((uint32_t)(x) & DRAM_BR_VLD_MASK) >> DRAM_BR_VLD_SHIFT)

/* Bitfield definition for register: INTEN */
/*
 * AXIBUSERR (RW)
 *
 * AXI BUS error interrupt enable
 * 0b - Interrupt is disabled
 * 1b - Interrupt is enabled
 */
#define DRAM_INTEN_AXIBUSERR_MASK (0x8U)
#define DRAM_INTEN_AXIBUSERR_SHIFT (3U)
#define DRAM_INTEN_AXIBUSERR_SET(x) (((uint32_t)(x) << DRAM_INTEN_AXIBUSERR_SHIFT) & DRAM_INTEN_AXIBUSERR_MASK)
#define DRAM_INTEN_AXIBUSERR_GET(x) (((uint32_t)(x) & DRAM_INTEN_AXIBUSERR_MASK) >> DRAM_INTEN_AXIBUSERR_SHIFT)

/*
 * AXICMDERR (RW)
 *
 * AXI command error interrupt enable
 * 0b - Interrupt is disabled
 * 1b - Interrupt is enabled
 */
#define DRAM_INTEN_AXICMDERR_MASK (0x4U)
#define DRAM_INTEN_AXICMDERR_SHIFT (2U)
#define DRAM_INTEN_AXICMDERR_SET(x) (((uint32_t)(x) << DRAM_INTEN_AXICMDERR_SHIFT) & DRAM_INTEN_AXICMDERR_MASK)
#define DRAM_INTEN_AXICMDERR_GET(x) (((uint32_t)(x) & DRAM_INTEN_AXICMDERR_MASK) >> DRAM_INTEN_AXICMDERR_SHIFT)

/*
 * IPCMDERR (RW)
 *
 * IP command error interrupt enable
 * 0b - Interrupt is disabled
 * 1b - Interrupt is enabled
 */
#define DRAM_INTEN_IPCMDERR_MASK (0x2U)
#define DRAM_INTEN_IPCMDERR_SHIFT (1U)
#define DRAM_INTEN_IPCMDERR_SET(x) (((uint32_t)(x) << DRAM_INTEN_IPCMDERR_SHIFT) & DRAM_INTEN_IPCMDERR_MASK)
#define DRAM_INTEN_IPCMDERR_GET(x) (((uint32_t)(x) & DRAM_INTEN_IPCMDERR_MASK) >> DRAM_INTEN_IPCMDERR_SHIFT)

/*
 * IPCMDDONE (RW)
 *
 * IP command done interrupt enable
 * 0b - Interrupt is disabled
 * 1b - Interrupt is enabled
 */
#define DRAM_INTEN_IPCMDDONE_MASK (0x1U)
#define DRAM_INTEN_IPCMDDONE_SHIFT (0U)
#define DRAM_INTEN_IPCMDDONE_SET(x) (((uint32_t)(x) << DRAM_INTEN_IPCMDDONE_SHIFT) & DRAM_INTEN_IPCMDDONE_MASK)
#define DRAM_INTEN_IPCMDDONE_GET(x) (((uint32_t)(x) & DRAM_INTEN_IPCMDDONE_MASK) >> DRAM_INTEN_IPCMDDONE_SHIFT)

/* Bitfield definition for register: INTR */
/*
 * AXIBUSERR (W1C)
 *
 * AXI bus error interrupt
 * AXI Bus error interrupt is generated in following cases:
 *  AXI address is invalid
 *  AXI 8-bit or 16-bit WRAP write/read
 */
#define DRAM_INTR_AXIBUSERR_MASK (0x8U)
#define DRAM_INTR_AXIBUSERR_SHIFT (3U)
#define DRAM_INTR_AXIBUSERR_SET(x) (((uint32_t)(x) << DRAM_INTR_AXIBUSERR_SHIFT) & DRAM_INTR_AXIBUSERR_MASK)
#define DRAM_INTR_AXIBUSERR_GET(x) (((uint32_t)(x) & DRAM_INTR_AXIBUSERR_MASK) >> DRAM_INTR_AXIBUSERR_SHIFT)

/*
 * AXICMDERR (W1C)
 *
 * AXI command error interrupt
 * AXI command error interrupt is generated when AXI command execution timeout.
 */
#define DRAM_INTR_AXICMDERR_MASK (0x4U)
#define DRAM_INTR_AXICMDERR_SHIFT (2U)
#define DRAM_INTR_AXICMDERR_SET(x) (((uint32_t)(x) << DRAM_INTR_AXICMDERR_SHIFT) & DRAM_INTR_AXICMDERR_MASK)
#define DRAM_INTR_AXICMDERR_GET(x) (((uint32_t)(x) & DRAM_INTR_AXICMDERR_MASK) >> DRAM_INTR_AXICMDERR_SHIFT)

/*
 * IPCMDERR (W1C)
 *
 * IP command error done interrupt
 * IP command error interrupt is generated in following case:
 *  IP Command Address target invalid device space
 *  IP Command Code unsupported
 *  IP Command triggered when previous command
 */
#define DRAM_INTR_IPCMDERR_MASK (0x2U)
#define DRAM_INTR_IPCMDERR_SHIFT (1U)
#define DRAM_INTR_IPCMDERR_SET(x) (((uint32_t)(x) << DRAM_INTR_IPCMDERR_SHIFT) & DRAM_INTR_IPCMDERR_MASK)
#define DRAM_INTR_IPCMDERR_GET(x) (((uint32_t)(x) & DRAM_INTR_IPCMDERR_MASK) >> DRAM_INTR_IPCMDERR_SHIFT)

/*
 * IPCMDDONE (W1C)
 *
 * IP command normal done interrupt
 */
#define DRAM_INTR_IPCMDDONE_MASK (0x1U)
#define DRAM_INTR_IPCMDDONE_SHIFT (0U)
#define DRAM_INTR_IPCMDDONE_SET(x) (((uint32_t)(x) << DRAM_INTR_IPCMDDONE_SHIFT) & DRAM_INTR_IPCMDDONE_MASK)
#define DRAM_INTR_IPCMDDONE_GET(x) (((uint32_t)(x) & DRAM_INTR_IPCMDDONE_MASK) >> DRAM_INTR_IPCMDDONE_SHIFT)

/* Bitfield definition for register: SDRCTRL0 */
/*
 * BANK2 (RW)
 *
 * 2 Bank selection bit
 * 0b - SDRAM device has 4 banks.
 * 1b - SDRAM device has 2 banks.
 */
#define DRAM_SDRCTRL0_BANK2_MASK (0x4000U)
#define DRAM_SDRCTRL0_BANK2_SHIFT (14U)
#define DRAM_SDRCTRL0_BANK2_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL0_BANK2_SHIFT) & DRAM_SDRCTRL0_BANK2_MASK)
#define DRAM_SDRCTRL0_BANK2_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL0_BANK2_MASK) >> DRAM_SDRCTRL0_BANK2_SHIFT)

/*
 * CAS (RW)
 *
 * CAS Latency
 * 00b - 1
 * 01b - 1
 * 10b - 2
 * 11b - 3
 */
#define DRAM_SDRCTRL0_CAS_MASK (0xC00U)
#define DRAM_SDRCTRL0_CAS_SHIFT (10U)
#define DRAM_SDRCTRL0_CAS_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL0_CAS_SHIFT) & DRAM_SDRCTRL0_CAS_MASK)
#define DRAM_SDRCTRL0_CAS_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL0_CAS_MASK) >> DRAM_SDRCTRL0_CAS_SHIFT)

/*
 * COL (RW)
 *
 * Column address bit number
 * 00b - 12 bit
 * 01b - 11 bit
 * 10b - 10 bit
 * 11b - 9 bit
 */
#define DRAM_SDRCTRL0_COL_MASK (0x300U)
#define DRAM_SDRCTRL0_COL_SHIFT (8U)
#define DRAM_SDRCTRL0_COL_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL0_COL_SHIFT) & DRAM_SDRCTRL0_COL_MASK)
#define DRAM_SDRCTRL0_COL_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL0_COL_MASK) >> DRAM_SDRCTRL0_COL_SHIFT)

/*
 * COL8 (RW)
 *
 * Column 8 selection bit
 * 0b - Column address bit number is decided by COL field.
 * 1b - Column address bit number is 8. COL field is ignored.
 */
#define DRAM_SDRCTRL0_COL8_MASK (0x80U)
#define DRAM_SDRCTRL0_COL8_SHIFT (7U)
#define DRAM_SDRCTRL0_COL8_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL0_COL8_SHIFT) & DRAM_SDRCTRL0_COL8_MASK)
#define DRAM_SDRCTRL0_COL8_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL0_COL8_MASK) >> DRAM_SDRCTRL0_COL8_SHIFT)

/*
 * BURSTLEN (RW)
 *
 * Burst Length
 * 000b - 1
 * 001b - 2
 * 010b - 4
 * 011b - 8
 * 100b - 8
 * 101b - 8
 * 110b - 8
 * 111b - 8
 */
#define DRAM_SDRCTRL0_BURSTLEN_MASK (0x70U)
#define DRAM_SDRCTRL0_BURSTLEN_SHIFT (4U)
#define DRAM_SDRCTRL0_BURSTLEN_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL0_BURSTLEN_SHIFT) & DRAM_SDRCTRL0_BURSTLEN_MASK)
#define DRAM_SDRCTRL0_BURSTLEN_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL0_BURSTLEN_MASK) >> DRAM_SDRCTRL0_BURSTLEN_SHIFT)

/*
 * HIGHBAND (RW)
 *
 * high band select
 * 0: use data[15:0] for 16bit SDRAM;
 * 1: use data[31:16] for 16bit SDRAM;
 * only used when Port Size is 16bit(PORTSZ=01b)
 */
#define DRAM_SDRCTRL0_HIGHBAND_MASK (0x8U)
#define DRAM_SDRCTRL0_HIGHBAND_SHIFT (3U)
#define DRAM_SDRCTRL0_HIGHBAND_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL0_HIGHBAND_SHIFT) & DRAM_SDRCTRL0_HIGHBAND_MASK)
#define DRAM_SDRCTRL0_HIGHBAND_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL0_HIGHBAND_MASK) >> DRAM_SDRCTRL0_HIGHBAND_SHIFT)

/*
 * PORTSZ (RW)
 *
 * Port Size
 * 00b - 8bit
 * 01b - 16bit
 * 10b - 32bit
 */
#define DRAM_SDRCTRL0_PORTSZ_MASK (0x3U)
#define DRAM_SDRCTRL0_PORTSZ_SHIFT (0U)
#define DRAM_SDRCTRL0_PORTSZ_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL0_PORTSZ_SHIFT) & DRAM_SDRCTRL0_PORTSZ_MASK)
#define DRAM_SDRCTRL0_PORTSZ_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL0_PORTSZ_MASK) >> DRAM_SDRCTRL0_PORTSZ_SHIFT)

/* Bitfield definition for register: SDRCTRL1 */
/*
 * ACT2PRE (RW)
 *
 * ACT to Precharge minimum time
 * It is promised ACT2PRE+1 clock cycles delay between ACTIVE command to PRECHARGE/PRECHARGE_ALL command.
 */
#define DRAM_SDRCTRL1_ACT2PRE_MASK (0xF00000UL)
#define DRAM_SDRCTRL1_ACT2PRE_SHIFT (20U)
#define DRAM_SDRCTRL1_ACT2PRE_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL1_ACT2PRE_SHIFT) & DRAM_SDRCTRL1_ACT2PRE_MASK)
#define DRAM_SDRCTRL1_ACT2PRE_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL1_ACT2PRE_MASK) >> DRAM_SDRCTRL1_ACT2PRE_SHIFT)

/*
 * CKEOFF (RW)
 *
 * CKE OFF minimum time
 * It is promised clock suspend last at leat CKEOFF+1 clock cycles.
 */
#define DRAM_SDRCTRL1_CKEOFF_MASK (0xF0000UL)
#define DRAM_SDRCTRL1_CKEOFF_SHIFT (16U)
#define DRAM_SDRCTRL1_CKEOFF_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL1_CKEOFF_SHIFT) & DRAM_SDRCTRL1_CKEOFF_MASK)
#define DRAM_SDRCTRL1_CKEOFF_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL1_CKEOFF_MASK) >> DRAM_SDRCTRL1_CKEOFF_SHIFT)

/*
 * WRC (RW)
 *
 * Write recovery time
 * It is promised WRC+1 clock cycles delay between WRITE command to PRECHARGE/PRECHARGE_ALL command. This could help to meet tWR timing requirement by SDRAM device.
 */
#define DRAM_SDRCTRL1_WRC_MASK (0xE000U)
#define DRAM_SDRCTRL1_WRC_SHIFT (13U)
#define DRAM_SDRCTRL1_WRC_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL1_WRC_SHIFT) & DRAM_SDRCTRL1_WRC_MASK)
#define DRAM_SDRCTRL1_WRC_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL1_WRC_MASK) >> DRAM_SDRCTRL1_WRC_SHIFT)

/*
 * RFRC (RW)
 *
 * Refresh recovery time
 * It is promised RFRC+1 clock cycles delay between REFRESH command to ACTIVE command. Thiscould help to meet tRFC timing requirement by SDRAM device.
 */
#define DRAM_SDRCTRL1_RFRC_MASK (0x1F00U)
#define DRAM_SDRCTRL1_RFRC_SHIFT (8U)
#define DRAM_SDRCTRL1_RFRC_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL1_RFRC_SHIFT) & DRAM_SDRCTRL1_RFRC_MASK)
#define DRAM_SDRCTRL1_RFRC_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL1_RFRC_MASK) >> DRAM_SDRCTRL1_RFRC_SHIFT)

/*
 * ACT2RW (RW)
 *
 * ACT to Read/Write wait time
 * It is promised ACT2RW+1 clock cycles delay between ACTIVE command to READ/WRITE command.This could help to meet tRCD timing requirement by SDRAM device.
 */
#define DRAM_SDRCTRL1_ACT2RW_MASK (0xF0U)
#define DRAM_SDRCTRL1_ACT2RW_SHIFT (4U)
#define DRAM_SDRCTRL1_ACT2RW_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL1_ACT2RW_SHIFT) & DRAM_SDRCTRL1_ACT2RW_MASK)
#define DRAM_SDRCTRL1_ACT2RW_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL1_ACT2RW_MASK) >> DRAM_SDRCTRL1_ACT2RW_SHIFT)

/*
 * PRE2ACT (RW)
 *
 * PRECHARGE to ACT/Refresh wait time
 * It is promised PRE2ACT+1 clock cycles delay between PRECHARGE/PRECHARGE_ALL commandto ACTIVE/REFRESH command. This could help to meet tRP timing requirement by SDRAM device.
 */
#define DRAM_SDRCTRL1_PRE2ACT_MASK (0xFU)
#define DRAM_SDRCTRL1_PRE2ACT_SHIFT (0U)
#define DRAM_SDRCTRL1_PRE2ACT_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL1_PRE2ACT_SHIFT) & DRAM_SDRCTRL1_PRE2ACT_MASK)
#define DRAM_SDRCTRL1_PRE2ACT_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL1_PRE2ACT_MASK) >> DRAM_SDRCTRL1_PRE2ACT_SHIFT)

/* Bitfield definition for register: SDRCTRL2 */
/*
 * ITO (RW)
 *
 * SDRAM Idle timeout
 * It closes all opened pages if the SDRAM idle time lasts more than idle timeout period. SDRAM is
 * considered idle when there is no AXI Bus transfer and no SDRAM command pending.
 * 00000000b - IDLE timeout period is 256*Prescale period.
 * 00000001-11111111b - IDLE timeout period is ITO*Prescale period.
 */
#define DRAM_SDRCTRL2_ITO_MASK (0xFF000000UL)
#define DRAM_SDRCTRL2_ITO_SHIFT (24U)
#define DRAM_SDRCTRL2_ITO_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL2_ITO_SHIFT) & DRAM_SDRCTRL2_ITO_MASK)
#define DRAM_SDRCTRL2_ITO_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL2_ITO_MASK) >> DRAM_SDRCTRL2_ITO_SHIFT)

/*
 * ACT2ACT (RW)
 *
 * ACT to ACT wait time
 * It is promised ACT2ACT+1 clock cycles delay between ACTIVE command to ACTIVE command. This
 * could help to meet tRRD timing requirement by SDRAM device.
 */
#define DRAM_SDRCTRL2_ACT2ACT_MASK (0xFF0000UL)
#define DRAM_SDRCTRL2_ACT2ACT_SHIFT (16U)
#define DRAM_SDRCTRL2_ACT2ACT_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL2_ACT2ACT_SHIFT) & DRAM_SDRCTRL2_ACT2ACT_MASK)
#define DRAM_SDRCTRL2_ACT2ACT_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL2_ACT2ACT_MASK) >> DRAM_SDRCTRL2_ACT2ACT_SHIFT)

/*
 * REF2REF (RW)
 *
 * Refresh to Refresh wait time
 * It is promised REF2REF+1 clock cycles delay between REFRESH command to REFRESH command.
 * This could help to meet tRFC timing requirement by SDRAM device.
 */
#define DRAM_SDRCTRL2_REF2REF_MASK (0xFF00U)
#define DRAM_SDRCTRL2_REF2REF_SHIFT (8U)
#define DRAM_SDRCTRL2_REF2REF_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL2_REF2REF_SHIFT) & DRAM_SDRCTRL2_REF2REF_MASK)
#define DRAM_SDRCTRL2_REF2REF_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL2_REF2REF_MASK) >> DRAM_SDRCTRL2_REF2REF_SHIFT)

/*
 * SRRC (RW)
 *
 * Self Refresh Recovery time
 * It is promised SRRC+1 clock cycles delay between Self-REFRESH command to any command.
 */
#define DRAM_SDRCTRL2_SRRC_MASK (0xFFU)
#define DRAM_SDRCTRL2_SRRC_SHIFT (0U)
#define DRAM_SDRCTRL2_SRRC_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL2_SRRC_SHIFT) & DRAM_SDRCTRL2_SRRC_MASK)
#define DRAM_SDRCTRL2_SRRC_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL2_SRRC_MASK) >> DRAM_SDRCTRL2_SRRC_SHIFT)

/* Bitfield definition for register: SDRCTRL3 */
/*
 * UT (RW)
 *
 * Refresh urgent threshold
 * Internal refresh request is generated on every Refresh period. Before internal request timer count up to
 * urgent request threshold, the refresh request is considered as normal refresh request. Normal refresh
 * request is handled in lower priority than any pending AXI command or IP command to SDRAM device.
 * When internal request timer count up to this urgent threshold, refresh request is considered as urgent
 * refresh request. Urgent refresh request is handled in higher priority than any pending AXI command or IP
 * command to SDRAM device.
 * NOTE: When urgent threshold is no less than refresh period, refresh request is always considered as
 * urgent refresh request.
 * Refresh urgent threshold is as follwoing:
 * 00000000b - 256*Prescaler period
 * 00000001-11111111b - UT*Prescaler period
 */
#define DRAM_SDRCTRL3_UT_MASK (0xFF000000UL)
#define DRAM_SDRCTRL3_UT_SHIFT (24U)
#define DRAM_SDRCTRL3_UT_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL3_UT_SHIFT) & DRAM_SDRCTRL3_UT_MASK)
#define DRAM_SDRCTRL3_UT_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL3_UT_MASK) >> DRAM_SDRCTRL3_UT_SHIFT)

/*
 * RT (RW)
 *
 * Refresh timer period
 * Refresh timer period is as following:
 * 00000000b - 256*Prescaler period
 * 00000001-11111111b - RT*Prescaler period
 */
#define DRAM_SDRCTRL3_RT_MASK (0xFF0000UL)
#define DRAM_SDRCTRL3_RT_SHIFT (16U)
#define DRAM_SDRCTRL3_RT_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL3_RT_SHIFT) & DRAM_SDRCTRL3_RT_MASK)
#define DRAM_SDRCTRL3_RT_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL3_RT_MASK) >> DRAM_SDRCTRL3_RT_SHIFT)

/*
 * PRESCALE (RW)
 *
 * Prescaler timer period
 * Prescaler timer period is as following:
 * 00000000b - 256*16 clock cycles
 * 00000001-11111111b - PRESCALE*16 clock cycles
 */
#define DRAM_SDRCTRL3_PRESCALE_MASK (0xFF00U)
#define DRAM_SDRCTRL3_PRESCALE_SHIFT (8U)
#define DRAM_SDRCTRL3_PRESCALE_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL3_PRESCALE_SHIFT) & DRAM_SDRCTRL3_PRESCALE_MASK)
#define DRAM_SDRCTRL3_PRESCALE_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL3_PRESCALE_MASK) >> DRAM_SDRCTRL3_PRESCALE_SHIFT)

/*
 * REBL (RW)
 *
 * Refresh burst length
 * It could send multiple Auto-Refresh command in one burst when REBL is set to non-zero. The
 * number of Auto-Refresh command cycle sent to all SDRAM device in one refresh period is as following.
 * 000b - 1
 * 001b - 2
 * 010b - 3
 * 011b - 4
 * 100b - 5
 * 101b - 6
 * 110b - 7
 * 111b - 8
 */
#define DRAM_SDRCTRL3_REBL_MASK (0xEU)
#define DRAM_SDRCTRL3_REBL_SHIFT (1U)
#define DRAM_SDRCTRL3_REBL_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL3_REBL_SHIFT) & DRAM_SDRCTRL3_REBL_MASK)
#define DRAM_SDRCTRL3_REBL_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL3_REBL_MASK) >> DRAM_SDRCTRL3_REBL_SHIFT)

/*
 * REN (RW)
 *
 * Refresh enable
 */
#define DRAM_SDRCTRL3_REN_MASK (0x1U)
#define DRAM_SDRCTRL3_REN_SHIFT (0U)
#define DRAM_SDRCTRL3_REN_SET(x) (((uint32_t)(x) << DRAM_SDRCTRL3_REN_SHIFT) & DRAM_SDRCTRL3_REN_MASK)
#define DRAM_SDRCTRL3_REN_GET(x) (((uint32_t)(x) & DRAM_SDRCTRL3_REN_MASK) >> DRAM_SDRCTRL3_REN_SHIFT)

/* Bitfield definition for register: SADDR */
/*
 * SA (RW)
 *
 * Slave address
 */
#define DRAM_SADDR_SA_MASK (0xFFFFFFFFUL)
#define DRAM_SADDR_SA_SHIFT (0U)
#define DRAM_SADDR_SA_SET(x) (((uint32_t)(x) << DRAM_SADDR_SA_SHIFT) & DRAM_SADDR_SA_MASK)
#define DRAM_SADDR_SA_GET(x) (((uint32_t)(x) & DRAM_SADDR_SA_MASK) >> DRAM_SADDR_SA_SHIFT)

/* Bitfield definition for register: DATSZ */
/*
 * DATSZ (RW)
 *
 * Data Size in Byte
 * When IP command is not a write/read operation, DATSZ field would be ignored.
 * 000b - 4
 * 001b - 1
 * 010b - 2
 * 011b - 3
 * 100b - 4
 * 101b - 4
 * 110b - 4
 * 111b - 4
 */
#define DRAM_DATSZ_DATSZ_MASK (0x7U)
#define DRAM_DATSZ_DATSZ_SHIFT (0U)
#define DRAM_DATSZ_DATSZ_SET(x) (((uint32_t)(x) << DRAM_DATSZ_DATSZ_SHIFT) & DRAM_DATSZ_DATSZ_MASK)
#define DRAM_DATSZ_DATSZ_GET(x) (((uint32_t)(x) & DRAM_DATSZ_DATSZ_MASK) >> DRAM_DATSZ_DATSZ_SHIFT)

/* Bitfield definition for register: BYTEMSK */
/*
 * BM3 (RW)
 *
 * Byte Mask for Byte 3 (IPTXD bit 31:24)
 * 0b - Byte Unmasked
 * 1b - Byte Masked
 */
#define DRAM_BYTEMSK_BM3_MASK (0x8U)
#define DRAM_BYTEMSK_BM3_SHIFT (3U)
#define DRAM_BYTEMSK_BM3_SET(x) (((uint32_t)(x) << DRAM_BYTEMSK_BM3_SHIFT) & DRAM_BYTEMSK_BM3_MASK)
#define DRAM_BYTEMSK_BM3_GET(x) (((uint32_t)(x) & DRAM_BYTEMSK_BM3_MASK) >> DRAM_BYTEMSK_BM3_SHIFT)

/*
 * BM2 (RW)
 *
 * Byte Mask for Byte 2 (IPTXD bit 23:16)
 * 0b - Byte Unmasked
 * 1b - Byte Masked
 */
#define DRAM_BYTEMSK_BM2_MASK (0x4U)
#define DRAM_BYTEMSK_BM2_SHIFT (2U)
#define DRAM_BYTEMSK_BM2_SET(x) (((uint32_t)(x) << DRAM_BYTEMSK_BM2_SHIFT) & DRAM_BYTEMSK_BM2_MASK)
#define DRAM_BYTEMSK_BM2_GET(x) (((uint32_t)(x) & DRAM_BYTEMSK_BM2_MASK) >> DRAM_BYTEMSK_BM2_SHIFT)

/*
 * BM1 (RW)
 *
 * Byte Mask for Byte 1 (IPTXD bit 15:8)
 * 0b - Byte Unmasked
 * 1b - Byte Masked
 */
#define DRAM_BYTEMSK_BM1_MASK (0x2U)
#define DRAM_BYTEMSK_BM1_SHIFT (1U)
#define DRAM_BYTEMSK_BM1_SET(x) (((uint32_t)(x) << DRAM_BYTEMSK_BM1_SHIFT) & DRAM_BYTEMSK_BM1_MASK)
#define DRAM_BYTEMSK_BM1_GET(x) (((uint32_t)(x) & DRAM_BYTEMSK_BM1_MASK) >> DRAM_BYTEMSK_BM1_SHIFT)

/*
 * BM0 (RW)
 *
 * Byte Mask for Byte 0 (IPTXD bit 7:0)
 * 0b - Byte Unmasked
 * 1b - Byte Masked
 */
#define DRAM_BYTEMSK_BM0_MASK (0x1U)
#define DRAM_BYTEMSK_BM0_SHIFT (0U)
#define DRAM_BYTEMSK_BM0_SET(x) (((uint32_t)(x) << DRAM_BYTEMSK_BM0_SHIFT) & DRAM_BYTEMSK_BM0_MASK)
#define DRAM_BYTEMSK_BM0_GET(x) (((uint32_t)(x) & DRAM_BYTEMSK_BM0_MASK) >> DRAM_BYTEMSK_BM0_SHIFT)

/* Bitfield definition for register: IPCMD */
/*
 * KEY (WO)
 *
 * This field should be written with 0x5AA5 when trigging an IP command for all device types. The memory
 * device is selected by BRx settings and IPCR0 registers.
 */
#define DRAM_IPCMD_KEY_MASK (0xFFFF0000UL)
#define DRAM_IPCMD_KEY_SHIFT (16U)
#define DRAM_IPCMD_KEY_SET(x) (((uint32_t)(x) << DRAM_IPCMD_KEY_SHIFT) & DRAM_IPCMD_KEY_MASK)
#define DRAM_IPCMD_KEY_GET(x) (((uint32_t)(x) & DRAM_IPCMD_KEY_MASK) >> DRAM_IPCMD_KEY_SHIFT)

/*
 * CMD (RW)
 *
 * SDRAM Commands:
 *  0x8: READ
 *  0x9: WRITE
 *  0xA: MODESET
 *  0xB: ACTIVE
 *  0xC: AUTO REFRESH
 *  0xD: SELF REFRESH
 *  0xE: PRECHARGE
 *  0xF: PRECHARGE ALL
 *  Others: RSVD
 * NOTE: SELF REFRESH is sent to all SDRAM devices because they shared same CLK pin.
 */
#define DRAM_IPCMD_CMD_MASK (0xFFFFU)
#define DRAM_IPCMD_CMD_SHIFT (0U)
#define DRAM_IPCMD_CMD_SET(x) (((uint32_t)(x) << DRAM_IPCMD_CMD_SHIFT) & DRAM_IPCMD_CMD_MASK)
#define DRAM_IPCMD_CMD_GET(x) (((uint32_t)(x) & DRAM_IPCMD_CMD_MASK) >> DRAM_IPCMD_CMD_SHIFT)

/* Bitfield definition for register: IPTX */
/*
 * DAT (RW)
 *
 * Data
 */
#define DRAM_IPTX_DAT_MASK (0xFFFFFFFFUL)
#define DRAM_IPTX_DAT_SHIFT (0U)
#define DRAM_IPTX_DAT_SET(x) (((uint32_t)(x) << DRAM_IPTX_DAT_SHIFT) & DRAM_IPTX_DAT_MASK)
#define DRAM_IPTX_DAT_GET(x) (((uint32_t)(x) & DRAM_IPTX_DAT_MASK) >> DRAM_IPTX_DAT_SHIFT)

/* Bitfield definition for register: IPRX */
/*
 * DAT (RW)
 *
 * Data
 */
#define DRAM_IPRX_DAT_MASK (0xFFFFFFFFUL)
#define DRAM_IPRX_DAT_SHIFT (0U)
#define DRAM_IPRX_DAT_SET(x) (((uint32_t)(x) << DRAM_IPRX_DAT_SHIFT) & DRAM_IPRX_DAT_MASK)
#define DRAM_IPRX_DAT_GET(x) (((uint32_t)(x) & DRAM_IPRX_DAT_MASK) >> DRAM_IPRX_DAT_SHIFT)

/* Bitfield definition for register: STAT0 */
/*
 * IDLE (RO)
 *
 * Indicating whether it is in IDLE state.
 * When IDLE=1, it is in IDLE state. There is no pending AXI command in internal queue and no
 * pending device access.
 */
#define DRAM_STAT0_IDLE_MASK (0x1U)
#define DRAM_STAT0_IDLE_SHIFT (0U)
#define DRAM_STAT0_IDLE_GET(x) (((uint32_t)(x) & DRAM_STAT0_IDLE_MASK) >> DRAM_STAT0_IDLE_SHIFT)

/* Bitfield definition for register: DLYCFG */
/*
 * OE (RW)
 *
 * delay clock output enable, should be set after setting DLYEN and DLYSEL
 */
#define DRAM_DLYCFG_OE_MASK (0x2000U)
#define DRAM_DLYCFG_OE_SHIFT (13U)
#define DRAM_DLYCFG_OE_SET(x) (((uint32_t)(x) << DRAM_DLYCFG_OE_SHIFT) & DRAM_DLYCFG_OE_MASK)
#define DRAM_DLYCFG_OE_GET(x) (((uint32_t)(x) & DRAM_DLYCFG_OE_MASK) >> DRAM_DLYCFG_OE_SHIFT)

/*
 * DLYSEL (RW)
 *
 * delay line select, 0 for 1 cell, 31 for all 32 cells
 */
#define DRAM_DLYCFG_DLYSEL_MASK (0x3EU)
#define DRAM_DLYCFG_DLYSEL_SHIFT (1U)
#define DRAM_DLYCFG_DLYSEL_SET(x) (((uint32_t)(x) << DRAM_DLYCFG_DLYSEL_SHIFT) & DRAM_DLYCFG_DLYSEL_MASK)
#define DRAM_DLYCFG_DLYSEL_GET(x) (((uint32_t)(x) & DRAM_DLYCFG_DLYSEL_MASK) >> DRAM_DLYCFG_DLYSEL_SHIFT)

/*
 * DLYEN (RW)
 *
 * delay line enable
 */
#define DRAM_DLYCFG_DLYEN_MASK (0x1U)
#define DRAM_DLYCFG_DLYEN_SHIFT (0U)
#define DRAM_DLYCFG_DLYEN_SET(x) (((uint32_t)(x) << DRAM_DLYCFG_DLYEN_SHIFT) & DRAM_DLYCFG_DLYEN_MASK)
#define DRAM_DLYCFG_DLYEN_GET(x) (((uint32_t)(x) & DRAM_DLYCFG_DLYEN_MASK) >> DRAM_DLYCFG_DLYEN_SHIFT)



/* BR register group index macro definition */
#define DRAM_BR_BASE0 (0UL)
#define DRAM_BR_BASE1 (1UL)


#endif /* HPM_DRAM_H */