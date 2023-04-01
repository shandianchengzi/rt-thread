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

#include <string.h>
#include "ls1c_public.h"
#include "ls1c_regs.h"
#include "ls1c_clock.h"
#include "ls1c_spi.h"




/*
 * SPI
 * @SPIx SPI
 */
void *ls1c_spi_get_base(unsigned char SPIx)
{
    void *base = NULL;

    switch (SPIx)
    {
        case LS1C_SPI_0:
            base = (void *)LS1C_SPI0_BASE;
            break;

        case LS1C_SPI_1:
            base = (void *)LS1C_SPI1_BASE;
            break;

        default:
            base = NULL;
            break;
    }

    return base;
}


/*
 * SPI
 * @spi_base 
 */
void ls1c_spi_print_all_regs_info(void *spi_base)
{
    printf("[%s] SPCR=0x%x, SPSR=0x%x, SPER=0x%x, SFC_PARAM=0x%x, SFC_SOFTCS=0x%x, SFC_TIMING=0x%x\r\n",
              __FUNCTION__, 
              reg_read_8(spi_base + LS1C_SPI_SPCR_OFFSET),
              reg_read_8(spi_base + LS1C_SPI_SPSR_OFFSET),
              reg_read_8(spi_base + LS1C_SPI_SPER_OFFSET),
              reg_read_8(spi_base + LS1C_SPI_SFC_PARAM_OFFSET),
              reg_read_8(spi_base + LS1C_SPI_SFC_SOFTCS_OFFSET),
              reg_read_8(spi_base + LS1C_SPI_SFC_TIMING_OFFSET));

    return ;
}


/*
 * SPI
 * @max_speed_hz SPI
 * @ret 
 */
unsigned int ls1c_spi_get_div(unsigned int max_speed_hz)
{
    unsigned long clk = 0;
    unsigned int div = 0;
    unsigned int div_tmp = 0;
    unsigned int bit = 0;

    clk = clk_get_apb_rate();
    div = DIV_ROUND_UP(clk, max_speed_hz);

    if (div < 2)
        div = 2;

    if (div > 4096)
        div = 4096;

    bit = ls1c_fls(div) - 1;
    switch (1 << bit)
    {
        case 16:
            div_tmp = 2;
            if (div > (1 << bit))
            {
                div_tmp++;
            }
            break;

        case 32:
            div_tmp = 3;
            if (div > (1 << bit))
            {
                div_tmp += 2;
            }
            break;

        case 8:
            div_tmp = 4;
            if (div > (1 << bit))
            {
                div_tmp -= 2;
            }
            break;

        default:
            div_tmp = bit - 1;
            if (div > (1 << bit))
            {
                div_tmp++;
            }
            break;
    }
/*    
    printf("[%s] clk=%ld, max_speed_hz=%d, div_tmp=%d, bit=%d\r\n", 
              __FUNCTION__, clk, max_speed_hz, div_tmp, bit);
*/
    return div_tmp;
}


/*
 * 
 * @spi_base 
 * @max_hz hz
 */
void ls1c_spi_set_clock(void *spi_base, unsigned long max_hz)
{
    unsigned int div = 0;
    unsigned char val = 0;

    // 
    div = ls1c_spi_get_div(max_hz);

    // spr
    val = reg_read_8(spi_base + LS1C_SPI_SPCR_OFFSET);
    val &= (~LS1C_SPI_SPCR_SPR_MASK);                       // spr
    val |= (div & LS1C_SPI_SPCR_SPR_MASK);                  // spr
    reg_write_8(val, spi_base + LS1C_SPI_SPCR_OFFSET);

    // spre
    val = reg_read_8(spi_base + LS1C_SPI_SPER_OFFSET);
    val &= (~LS1C_SPI_SPER_SPRE_MASK);                      // spre
    val |= ((div >> 2) & LS1C_SPI_SPER_SPRE_MASK);        // spre
    reg_write_8(val, spi_base + LS1C_SPI_SPER_OFFSET);

    return ;
}


/*
 * ()
 * @spi_base 
 * @cpol 
 * @cpha 
 */
void ls1c_spi_set_mode(void *spi_base, unsigned char cpol, unsigned char cpha)
{
    unsigned char val = 0;

    val = reg_read_8(spi_base + LS1C_SPI_SPCR_OFFSET);
    
    // --cpol
    val &= (~LS1C_SPI_SPCR_CPOL_MASK);                  // cpol0
    val |= (cpol << LS1C_SPI_SPCR_CPOL_BIT);            // cpol
    
    // --cpha
    val &= (~LS1C_SPI_SPCR_CPHA_MASK);                  // cpha0
    val |= (cpha << LS1C_SPI_SPCR_CPHA_BIT);            // cpha
    
    reg_write_8(val, spi_base + LS1C_SPI_SPCR_OFFSET);

    return ;
}


/*
 * 
 * @spi_base 
 * @cs 
 * @new_status 01
 */
void ls1c_spi_set_cs(void *spi_base, unsigned char cs, int new_status)
{
    unsigned char val = 0;

    val = reg_read_8(spi_base + LS1C_SPI_SFC_SOFTCS_OFFSET);
    val |= 0x01 << cs ; //csen=1  
    if (new_status)         // cs = 1
    {
        val |= (0x10 << cs);            // csn=1
    }
    else                    // cs = 0
    {
        val &= ~(0x10 << cs);           // csn=0
    }
    reg_write_8(val, spi_base + LS1C_SPI_SFC_SOFTCS_OFFSET);

    return ;
}


/*
 * 
 * @spi_base 
 */
void ls1c_spi_wait_txrx_done(void *spi_base)
{
    int timeout = LS1C_SPI_TX_TIMEOUT;

    while (timeout--)
    {
        if (LS1C_SPI_SPSR_SPIF_MASK & reg_read_8(spi_base + LS1C_SPI_SPSR_OFFSET))
            break;
    }
    
    return ;
}


/*
 * 
 * @spi_base 
 */
void ls1c_spi_clear(void *spi_base)
{
    unsigned char val = 0;

    // 
    val = reg_read_8(spi_base + LS1C_SPI_SPSR_OFFSET);
    val |= LS1C_SPI_SPSR_SPIF_MASK;
    reg_write_8(val, spi_base + LS1C_SPI_SPSR_OFFSET);

    // (Write-Collision Clear)
    val = reg_read_8(spi_base + LS1C_SPI_SPSR_OFFSET);
    if (LS1C_SPI_SPSR_WCOL_MASK & val)
    {
        printf("[%s] clear register SPSR's wcol!\r\n");       // linux
        reg_write_8(val & ~LS1C_SPI_SPSR_WCOL_MASK, spi_base + LS1C_SPI_SPSR_OFFSET);   // 0linux0
//        reg_write_8(val | LS1C_SPI_SPSR_WCOL_MASK, spi_base + LS1C_SPI_SPSR_OFFSET);  // 11c1
    }

    return ;
}



/*
 * SPI
 * 
 * SPI
 * 1cSPI
 * @spi_base 
 * @tx_ch 
 * @ret 
 */
unsigned char ls1c_spi_txrx_byte(void *spi_base, unsigned char tx_ch)
{
    unsigned char rx_ch = 0;

    // 
    reg_write_8(tx_ch, spi_base + LS1C_SPI_TxFIFO_OFFSET);      // 
    ls1c_spi_wait_txrx_done(spi_base);                          // 
    rx_ch = reg_read_8(spi_base + LS1C_SPI_RxFIFO_OFFSET);      // 
    ls1c_spi_clear(spi_base);                                   // 

    return rx_ch;
}



