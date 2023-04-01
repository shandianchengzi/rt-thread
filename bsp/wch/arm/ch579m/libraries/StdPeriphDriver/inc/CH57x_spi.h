


#ifndef __CH57x_SPI_H__
#define __CH57x_SPI_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "CH579SFR.h"
#include "core_cm0.h"

/**
  * @brief  SPI0 interrupt bit define
  */

#define SPI0_IT_FST_BYTE        RB_SPI_IE_FST_BYTE              // 
#define SPI0_IT_FIFO_OV         RB_SPI_IE_FIFO_OV               // FIFO 
#define SPI0_IT_DMA_END         RB_SPI_IE_DMA_END               // DMA 
#define SPI0_IT_FIFO_HF         RB_SPI_IE_FIFO_HF               // FIFO 
#define SPI0_IT_BYTE_END        RB_SPI_IE_BYTE_END              // 
#define SPI0_IT_CNT_END         RB_SPI_IE_CNT_END               // 



/**
  * @brief  Configuration data mode
  */
typedef enum
{
    Mode0_LowBitINFront = 0,                    // 0
    Mode0_HighBitINFront,                       // 0
    Mode3_LowBitINFront,                        // 3
    Mode3_HighBitINFront,                       // 3
}ModeBitOrderTypeDef;


/**
  * @brief  Configuration SPI0 slave mode
  */
typedef enum
{
    Mode_DataStream = 0,                // 
    Mose_FirstCmd,                      // 
}Slave_ModeTypeDef;


/**************** SPI0 */
void SPI0_MasterDefInit( void );                            /* 0+3+8MHz */
void SPI0_CLKCfg( UINT8 c );                                /* SPI0 = d*Tsys */
void SPI0_DataMode( ModeBitOrderTypeDef m );                /*  */

void SPI0_MasterSendByte( UINT8 d );                        /*  (buffer) */
UINT8 SPI0_MasterRecvByte( void );                          /*  (buffer) */

void SPI0_MasterTrans( UINT8 *pbuf, UINT16 len );           /* FIFO */
void SPI0_MasterRecv( UINT8 *pbuf, UINT16 len );            /* FIFO */

void SPI0_MasterDMATrans( PUINT8 pbuf, UINT16 len);         /* DMA   */
void SPI0_MasterDMARecv( PUINT8 pbuf, UINT16 len);          /* DMA  */


void SPI0_SlaveInit( void );                                /* MISOGPIO */
#define SetFirstData(d)         (R8_SPI0_SLAVE_PRE = d)     /*  */
void SPI0_SlaveSendByte( UINT8 d );                         /*  */
UINT8 SPI0_SlaveRecvByte( void );                           /*  */

void SPI0_SlaveTrans( UINT8 *pbuf, UINT16 len );            /*  */
void SPI0_SlaveRecv( PUINT8 pbuf, UINT16 len );             /*   */

void SPI0_SlaveDMATrans( PUINT8 pbuf, UINT16 len);          /* DMA */
void SPI0_SlaveDMARecv( PUINT8 pbuf, UINT16 len);           /* DMA */

// refer to SPI0 interrupt bit define
#define SPI0_ITCfg(s,f)         ((s)?(R8_SPI0_INTER_EN|=f):(R8_SPI0_INTER_EN&=~f))
#define SPI0_GetITFlag(f)       (R8_SPI0_INT_FLAG&f)        /* 0-(!0)- */
#define SPI0_ClearITFlag(f)     (R8_SPI0_INT_FLAG = f)      /*  */




/**************** SPI1 */
void SPI1_MasterDefInit( void );                            /* 0+3+8MHz */
void SPI1_CLKCfg( UINT8 c );                                /* SPI1 = d*Tsys */
void SPI1_DataMode( ModeBitOrderTypeDef m );                /*  */

void SPI1_MasterSendByte( UINT8 d );                        /*  (buffer) */
UINT8 SPI1_MasterRecvByte( void );                          /*  (buffer) */

void SPI1_MasterTrans( UINT8 *pbuf, UINT16 len );           /* FIFO */
void SPI1_MasterRecv( UINT8 *pbuf, UINT16 len );            /* FIFO */


// refer to SPI1 interrupt bit define
#define SPI1_ITCfg(s,f)         ((s)?(R8_SPI1_INTER_EN|=f):(R8_SPI1_INTER_EN&=~f))
#define SPI1_GetITFlag(f)       (R8_SPI1_INT_FLAG&f)        /* 0-(!0)- */
#define SPI1_ClearITFlag(f)     (R8_SPI1_INT_FLAG = f)      /*  */




#ifdef __cplusplus
}
#endif

#endif  // __CH57x_SPI_H__

