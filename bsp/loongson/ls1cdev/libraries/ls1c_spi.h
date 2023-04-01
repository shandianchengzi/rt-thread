/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-10-23            first version
 */

// spi

#ifndef __OPENLOONGSON_SPI_H
#define __OPENLOONGSON_SPI_H


// SPI
#define LS1C_SPI_0                      (0)
#define LS1C_SPI_1                      (1)

// 
#define LS1C_SPI_CS_0                   (0)
#define LS1C_SPI_CS_1                   (1)
#define LS1C_SPI_CS_2                   (2)
#define LS1C_SPI_CS_3                   (3)

// 
#define SPI_CPOL_1                      (1)
#define SPI_CPOL_0                      (0)
#define SPI_CPHA_1                      (1)
#define SPI_CPHA_0                      (0)


// 
#define LS1C_SPI_SPCR_OFFSET                (0)     // 
#define LS1C_SPI_SPSR_OFFSET                (1)     // 
#define LS1C_SPI_TxFIFO_OFFSET              (2)     // 
#define LS1C_SPI_RxFIFO_OFFSET              (2)     // 
#define LS1C_SPI_SPER_OFFSET                (3)     // 
#define LS1C_SPI_SFC_PARAM_OFFSET           (4)     // 
#define LS1C_SPI_SFC_SOFTCS_OFFSET          (5)     // 
#define LS1C_SPI_SFC_TIMING_OFFSET          (6)     // 

// SPCR
#define LS1C_SPI_SPCR_SPIE_BIT              (7)
#define LS1C_SPI_SPCR_SPIE_MASK             (0x01 << LS1C_SPI_SPCR_SPIE_BIT)
#define LS1C_SPI_SPCR_SPE_BIT               (6)
#define LS1C_SPI_SPCR_SPE_MASK              (0x01 << LS1C_SPI_SPCR_SPE_BIT)
#define LS1C_SPI_SPCR_CPOL_BIT              (3)
#define LS1C_SPI_SPCR_CPOL_MASK             (0x01 << LS1C_SPI_SPCR_CPOL_BIT)
#define LS1C_SPI_SPCR_CPHA_BIT              (2)
#define LS1C_SPI_SPCR_CPHA_MASK             (0x01 << LS1C_SPI_SPCR_CPHA_BIT)
#define LS1C_SPI_SPCR_SPR_BIT               (0)
#define LS1C_SPI_SPCR_SPR_MASK              (0x03 << LS1C_SPI_SPCR_SPR_BIT)

// SPSR
#define LS1C_SPI_SPSR_SPIF_BIT              (7)
#define LS1C_SPI_SPSR_SPIF_MASK             (0x01 << LS1C_SPI_SPSR_SPIF_BIT)
#define LS1C_SPI_SPSR_WCOL_BIT              (6)
#define LS1C_SPI_SPSR_WCOL_MASK             (0x01 << LS1C_SPI_SPSR_WCOL_BIT)

// SPER
#define LS1C_SPI_SPER_SPRE_BIT              (0)
#define LS1C_SPI_SPER_SPRE_MASK             (0x3 << LS1C_SPI_SPER_SPRE_BIT)

// SFC_SOFTCS
#define LS1C_SPI_SFC_SOFTCS_CSN_BIT         (4)
#define LS1C_SPI_SFC_SOFTCS_CSN_MASK        (0x0f << LS1C_SPI_SFC_SOFTCS_CSN_BIT)
#define LS1C_SPI_SFC_SOFTCS_CSEN_BIT        (0)
#define LS1C_SPI_SFC_SOFTCS_CSEN_MASK       (0x0f << LS1C_SPI_SFC_SOFTCS_CSEN_BIT)

// 
#define LS1C_SPI_TX_TIMEOUT                 (20000)



/*
 * SPI
 * @SPIx SPI
 */
void *ls1c_spi_get_base(unsigned char SPIx);


/*
 * 
 * @spi_base 
 * @max_hz hz
 */
void ls1c_spi_set_clock(void *spi_base, unsigned long max_hz);


/*
 * ()
 * @spi_base 
 * @cpol 
 * @cpha 
 */
void ls1c_spi_set_mode(void *spi_base, unsigned char cpol, unsigned char cpha);


/*
 * 
 * @spi_base 
 * @cs 
 * @new_status 01
 */
void ls1c_spi_set_cs(void *spi_base, unsigned char cs, int new_status);


/*
 * SPI
 * 
 * SPI
 * 1cSPI
 * @spi_base 
 * @tx_ch 
 * @ret 
 */
unsigned char ls1c_spi_txrx_byte(void *spi_base, unsigned char tx_ch);


/*
 * SPI
 * @spi_base 
 */
void ls1c_spi_print_all_regs_info(void *spi_base);




#endif

