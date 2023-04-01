/******************************************************************************
* Copyright (C) 2016, Huada Semiconductor Co.,Ltd All rights reserved.
*
* This software is owned and published by:
* Huada Semiconductor Co.,Ltd ("HDSC").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with HDSC
* components. This software is licensed by HDSC to be adapted only
* for use in systems utilizing HDSC components. HDSC shall not be
* responsible for misuse or illegal use of this software for devices not
* supported herein. HDSC is providing this software "AS IS" and will
* not be responsible for issues arising from incorrect user implementation
* of the software.
*
* Disclaimer:
* HDSC MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS),
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING,
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED
* WARRANTY OF NONINFRINGEMENT.
* HDSC SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT,
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA,
* SAVINGS OR PROFITS,
* EVEN IF Disclaimer HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED
* FROM, THE SOFTWARE.
*
* This software may be replicated in part or whole for the licensed use,
* with the restriction that this Disclaimer and Copyright notice must be
* included with eaenCh copy of this software, whether used in part or whole,
* at all times.
*/
/*****************************************************************************/
/** \file spi.c
 **
 ** SPI driver API.
 ** @link Driver Group Some description @endlink
 **
 **   - 2018-05-17  1.0  Devi First version for Device Driver Library of
 **                      Module.
 **
 *****************************************************************************/

/******************************************************************************
 * Include files
 *****************************************************************************/
#include "hc32l196_spi.h"

/**
 ******************************************************************************
 ** \addtogroup SpiGroup
 *****************************************************************************/
//@{

/******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 *****************************************************************************/

#define IS_VALID_STAT(x)            (   SpiIf == (x)||\
                                        SpiSserr == (x)||\
                                        SpiBusy == (x)||\
                                        SpiMdf == (x)||\
                                        SpiTxe == (x)||\
                                        SpiRxne == (x))


/******************************************************************************/
/* Local function prototypes ('static')                                       */
/******************************************************************************/

/******************************************************************************/
/* Local variable prototypes ('static')                                       */
/******************************************************************************/

/**
 ******************************************************************************
 ** \brief  SPI 
 **
 ** \param [in]SPIx  enStatus 
 **
 ** \retval 
 **
 ******************************************************************************/
boolean_t Spi_GetStatus(M0P_SPI_TypeDef* SPIx, en_spi_status_t enStatus)
{
    ASSERT(IS_VALID_STAT(enStatus));

    if(SPIx->STAT&enStatus)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}
/**
 ******************************************************************************
 ** \brief  SPI
 **
 ** \param [in]SPIx 
 **
 ** \retval 
 **
 ******************************************************************************/
en_result_t Spi_ClearStatus(M0P_SPI_TypeDef* SPIx)
{
    SPIx->ICLR = 0;

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  SPI 
 **
 ** \param [in] SPIx 
 **
 ** \retval Ok
 **
 ******************************************************************************/
en_result_t Spi_IrqEnable(M0P_SPI_TypeDef* SPIx)
{
    SPIx->CR2 |= 0x4u;

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  SPI 
 **
 ** \param [in] enCh
 **
 ** \retval Ok
 **
 ******************************************************************************/
en_result_t Spi_IrqDisable(M0P_SPI_TypeDef* SPIx)
{
    SPIx->CR2 &= ~0x4u;

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  SPI 
 **
 ** \param [in] SPIx enFunc
 **
 ** \retval Ok
 **
 ******************************************************************************/
en_result_t Spi_FuncEnable(M0P_SPI_TypeDef* SPIx, en_spi_func_t enFunc)
{
    SPIx->CR2 |= enFunc;

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  SPI 
 **
 ** \param [in] SPIx enFunc
 **
 ** \retval Ok
 **
 ******************************************************************************/
en_result_t Spi_FuncDisable(M0P_SPI_TypeDef* SPIx, en_spi_func_t enFunc)
{
    SPIx->CR2 &= ~(uint32_t)enFunc;

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  SPI 
 **
 ** \param [in] SPIx 
 ** \param [in] pstcSpiCfg 
 **
 ** \retval Ok
 ** \retval ErrorInvalidParameter 
 ******************************************************************************/
en_result_t Spi_Init(M0P_SPI_TypeDef* SPIx, stc_spi_cfg_t *pstcSpiCfg)
{
    ASSERT(NULL != pstcSpiCfg);

    SPIx->CR = 0;

    SPIx->SSN = TRUE;

    SPIx->CR =  (uint32_t)pstcSpiCfg->enSpiMode |
                (uint32_t)pstcSpiCfg->enPclkDiv |
                (uint32_t)pstcSpiCfg->enCPOL    |
                (uint32_t)pstcSpiCfg->enCPHA    |
                (uint32_t)0x40;

    SPIx->STAT = 0x00;

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  SPI 
 **
 ** \param [in] SPIx bFlag
 **
 ** \retval 
 **
 ******************************************************************************/
void Spi_SetCS(M0P_SPI_TypeDef* SPIx, boolean_t bFlag)
{
    SPIx->SSN = bFlag;
}
/**
 ******************************************************************************
 ** \brief  SPI 
 **
 ** \param [in] SPIx u8Data
 **
 ** \retval Ok
 **
 ******************************************************************************/
en_result_t Spi_SendData(M0P_SPI_TypeDef* SPIx, uint8_t u8Data)
{
    SPIx->DATA = u8Data;

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  SPI /
 **
 ** \param [in] SPIx   
 ** \param [in] u8Data 
 **
 ** \retval 
 **
 ******************************************************************************/
uint8_t Spi_RWByte(M0P_SPI_TypeDef* SPIx, uint8_t u8Data)
{
    while(FALSE == SPIx->STAT_f.TXE){;}
    SPIx->DATA = u8Data;
    while(FALSE == SPIx->STAT_f.RXNE){;}
    return SPIx->DATA;
}

/**
 ******************************************************************************
** \brief  SPI 
 **
 ** \param [in] SPIx   
 ** \param [in] u8Data 
 **
 ** \retval None
 **
 ******************************************************************************/
void Spi_Slave_DummyWriteData(M0P_SPI_TypeDef* SPIx, uint8_t u8Data)
{
    while(FALSE == SPIx->STAT_f.TXE){;}
    SPIx->DATA = u8Data;
}

/**
 ******************************************************************************
 ** \brief  SPI 
 **
 ** \param [in] SPIx   
 ** \param [in] pu8Buf 
 **
 ** \retval Ok
 **
 ******************************************************************************/
en_result_t Spi_SendBuf(M0P_SPI_TypeDef* SPIx, uint8_t* pu8Buf, uint32_t u32Len)
{
    uint32_t u32Index=0;

    for(u32Index=0; u32Index<u32Len; u32Index++)
    {
        while(FALSE == SPIx->STAT_f.TXE){;}
        SPIx->DATA = pu8Buf[u32Index];
        while(FALSE == SPIx->STAT_f.RXNE){;}
        pu8Buf[u32Index] = SPIx->DATA;
    }

    while(FALSE == SPIx->STAT_f.TXE){;}
    while(TRUE == SPIx->STAT_f.BUSY){;}

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  SPI 
 **
 ** \param [in] SPIx
 **
 ** \retval 
 **
 ******************************************************************************/
uint8_t Spi_ReceiveData(M0P_SPI_TypeDef* SPIx)
{
    return SPIx->DATA;
}

/**
 ******************************************************************************
 ** \brief  SPI 
 **
 ** \param [in] SPIx   
 ** \param [in] pu8Buf 
 **
 ** \retval Ok
 **
 ******************************************************************************/
en_result_t Spi_ReceiveBuf(M0P_SPI_TypeDef* SPIx, uint8_t* pu8Buf, uint32_t u32Len)
{
    uint32_t u32Index=0;

    for(u32Index=0; u32Index<u32Len; u32Index++)
    {
        while(FALSE == SPIx->STAT_f.TXE){;}
        SPIx->DATA = 0x00;
        while(FALSE == SPIx->STAT_f.RXNE){;}
        pu8Buf[u32Index] = SPIx->DATA;
    }

    while(TRUE == SPIx->STAT_f.BUSY){;}

    return Ok;
}

//@} // SpiGroup
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/

