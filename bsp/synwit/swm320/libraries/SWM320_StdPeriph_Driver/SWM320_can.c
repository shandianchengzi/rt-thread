/******************************************************************************************************************************************
* : SWM320_can.c
* : SWM320CAN
* : http://www.synwit.com.cn/e/tool/gbook/?bid=1
* :
* : V1.1.0      20171025
* :
*
*
*******************************************************************************************************************************************
* @attention
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS WITH CODING INFORMATION
* REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME. AS A RESULT, SYNWIT SHALL NOT BE HELD LIABLE
* FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
* OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN IN CONN-
* -ECTION WITH THEIR PRODUCTS.
*
* COPYRIGHT 2012 Synwit Technology
*******************************************************************************************************************************************/
#include "SWM320.h"
#include "SWM320_can.h"


/******************************************************************************************************************************************
* : CAN_Init()
* : CAN
*     : CAN_TypeDef * CANx    CANCAN
*           CAN_InitStructure * initStruct    CAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_Init(CAN_TypeDef * CANx, CAN_InitStructure * initStruct)
{
    switch((uint32_t)CANx)
    {
    case ((uint32_t)CAN):
        SYS->CLKEN |= (0x01 << SYS_CLKEN_CAN_Pos);
        break;
    }

    CAN_Close(CANx);    //CAN

    CANx->CR &= ~(CAN_CR_LOM_Msk | CAN_CR_STM_Msk | CAN_CR_AFM_Msk);
    CANx->CR |= (initStruct->Mode << CAN_CR_LOM_Pos) |
                (initStruct->FilterMode << CAN_CR_AFM_Pos);

    CANx->FILTER.AMR[3] = initStruct->FilterMask32b & 0xFF;
    CANx->FILTER.AMR[2] = (initStruct->FilterMask32b >>  8) & 0xFF;
    CANx->FILTER.AMR[1] = (initStruct->FilterMask32b >> 16) & 0xFF;
    CANx->FILTER.AMR[0] = (initStruct->FilterMask32b >> 24) & 0xFF;

    CANx->FILTER.ACR[3] = initStruct->FilterCheck32b & 0xFF;
    CANx->FILTER.ACR[2] = (initStruct->FilterCheck32b >>  8) & 0xFF;
    CANx->FILTER.ACR[1] = (initStruct->FilterCheck32b >> 16) & 0xFF;
    CANx->FILTER.ACR[0] = (initStruct->FilterCheck32b >> 24) & 0xFF;

    CANx->BT1 = (0 << CAN_BT1_SAM_Pos) |
                (initStruct->CAN_BS1 << CAN_BT1_TSEG1_Pos) |
                (initStruct->CAN_BS2 << CAN_BT1_TSEG2_Pos);

    CANx->BT0 = (initStruct->CAN_SJW << CAN_BT0_SJW_Pos) |
                ((SystemCoreClock/2/initStruct->Baudrate/(1 + (initStruct->CAN_BS1 + 1) + (initStruct->CAN_BS2 + 1)) - 1) << CAN_BT0_BRP_Pos);

    CANx->RXERR = 0;    //
    CANx->TXERR = 0;

    CANx->IE = (initStruct->RXNotEmptyIEn << CAN_IE_RXDA_Pos)    |
               (initStruct->RXOverflowIEn << CAN_IE_RXOV_Pos)    |
               (initStruct->ArbitrLostIEn << CAN_IE_ARBLOST_Pos) |
               (initStruct->ErrPassiveIEn << CAN_IE_ERRPASS_Pos);

    switch((uint32_t)CANx)
    {
    case ((uint32_t)CAN):
        if(initStruct->RXNotEmptyIEn | initStruct->RXOverflowIEn | initStruct->ArbitrLostIEn | initStruct->ErrPassiveIEn)
        {
            NVIC_EnableIRQ(CAN_IRQn);
        }
        else
        {
            NVIC_DisableIRQ(CAN_IRQn);
        }
        break;
    }
}

/******************************************************************************************************************************************
* : CAN_Open()
* : CAN
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_Open(CAN_TypeDef * CANx)
{
    CANx->CR &= ~(0x01 << CAN_CR_RST_Pos);  //
}

/******************************************************************************************************************************************
* : CAN_Close()
* : CAN
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_Close(CAN_TypeDef * CANx)
{
    CANx->CR |= (0x01 << CAN_CR_RST_Pos);   //
}

/******************************************************************************************************************************************
* : CAN_Transmit()
* : CAN
*     : CAN_TypeDef * CANx    CANCAN
*           uint32_t format     CAN_FRAME_STD     CAN_FRAME_EXT 
*           uint32_t id         ID
*           uint8_t data[]      
*           uint32_t size       
*           uint32_t once       NAK
*     : 
* : 
******************************************************************************************************************************************/
void CAN_Transmit(CAN_TypeDef * CANx, uint32_t format, uint32_t id, uint8_t data[], uint32_t size, uint32_t once)
{
    uint32_t i;

    if(format == CAN_FRAME_STD)
    {
        CANx->FRAME.INFO = (0 << CAN_INFO_FF_Pos)  |
                           (0 << CAN_INFO_RTR_Pos) |
                           (size << CAN_INFO_DLC_Pos);

        CANx->FRAME.DATA[0] = id >> 3;
        CANx->FRAME.DATA[1] = id << 5;

        for(i = 0; i < size; i++)
        {
            CANx->FRAME.DATA[i+2] = data[i];
        }
    }
    else //if(format == CAN_FRAME_EXT)
    {
        CANx->FRAME.INFO = (1 << CAN_INFO_FF_Pos)  |
                           (0 << CAN_INFO_RTR_Pos) |
                           (size << CAN_INFO_DLC_Pos);

        CANx->FRAME.DATA[0] = id >> 21;
        CANx->FRAME.DATA[1] = id >> 13;
        CANx->FRAME.DATA[2] = id >>  5;
        CANx->FRAME.DATA[3] = id <<  3;

        for(i = 0; i < size; i++)
        {
            CANx->FRAME.DATA[i+4] = data[i];
        }
    }

    if(CANx->CR & CAN_CR_STM_Msk)
    {
        CANx->CMD = (1 << CAN_CMD_SRR_Pos);
    }
    else
    {
        if(once == 0)
        {
            CANx->CMD = (1 << CAN_CMD_TXREQ_Pos);
        }
        else
        {
            CANx->CMD = (1 << CAN_CMD_TXREQ_Pos) | (1 << CAN_CMD_ABTTX_Pos);
        }
    }
}

/******************************************************************************************************************************************
* : CAN_TransmitRequest()
* : CAN
*     : CAN_TypeDef * CANx    CANCAN
*           uint32_t format     CAN_FRAME_STD     CAN_FRAME_EXT 
*           uint32_t id         ID
*           uint32_t once       NAK
*     : 
* : 
******************************************************************************************************************************************/
void CAN_TransmitRequest(CAN_TypeDef * CANx, uint32_t format, uint32_t id, uint32_t once)
{
    if(format == CAN_FRAME_STD)
    {
        CANx->FRAME.INFO = (0 << CAN_INFO_FF_Pos)  |
                           (1 << CAN_INFO_RTR_Pos) |
                           (0 << CAN_INFO_DLC_Pos);

        CANx->FRAME.DATA[0] = id >> 3;
        CANx->FRAME.DATA[1] = id << 5;
    }
    else //if(format == CAN_FRAME_EXT)
    {
        CANx->FRAME.INFO = (1 << CAN_INFO_FF_Pos)  |
                           (1 << CAN_INFO_RTR_Pos) |
                           (0 << CAN_INFO_DLC_Pos);

        CANx->FRAME.DATA[0] = id >> 21;
        CANx->FRAME.DATA[1] = id >> 13;
        CANx->FRAME.DATA[2] = id >>  5;
        CANx->FRAME.DATA[3] = id <<  3;
    }

    if(once == 0)
    {
        CANx->CMD = (1 << CAN_CMD_TXREQ_Pos);
    }
    else
    {
        CANx->CMD = (1 << CAN_CMD_TXREQ_Pos) | (1 << CAN_CMD_ABTTX_Pos);
    }
}

/******************************************************************************************************************************************
* : CAN_Receive()
* : CAN
*     : CAN_TypeDef * CANx    CANCAN
*           CAN_RXMessage *msg  
*     : 
* : 
******************************************************************************************************************************************/
void CAN_Receive(CAN_TypeDef * CANx, CAN_RXMessage *msg)
{
    uint32_t i;
    msg->format = (CANx->FRAME.INFO & CAN_INFO_FF_Msk) >> CAN_INFO_FF_Pos;

    msg->remote = (CANx->FRAME.INFO & CAN_INFO_RTR_Msk) >> CAN_INFO_RTR_Pos;
    msg->size = (CANx->FRAME.INFO & CAN_INFO_DLC_Msk) >> CAN_INFO_DLC_Pos;

    if(msg->format == CAN_FRAME_STD)
    {
        msg->id = (CANx->FRAME.DATA[0] << 3) | (CANx->FRAME.DATA[1] >> 5);

        for(i = 0; i < msg->size; i++)
        {
            msg->data[i] = CANx->FRAME.DATA[i+2];
        }
    }
    else //if(msg->format == CAN_FRAME_EXT)
    {
        msg->id = (CANx->FRAME.DATA[0] << 21) | (CANx->FRAME.DATA[1] << 13) | (CANx->FRAME.DATA[2] << 5) | (CANx->FRAME.DATA[3] >> 3);

        for(i = 0; i < msg->size; i++)
        {
            msg->data[i] = CANx->FRAME.DATA[i+4];
        }
    }

    CANx->CMD = (1 << CAN_CMD_RRB_Pos);
}

/******************************************************************************************************************************************
* : CAN_TXComplete()
* : 
*     : CAN_TypeDef * CANx    CANCAN
*     : uint32_t          1     0 
* : Abort
******************************************************************************************************************************************/
uint32_t CAN_TXComplete(CAN_TypeDef * CANx)
{
    return (CANx->SR & CAN_SR_TXBR_Msk) ? 1 : 0;
}

/******************************************************************************************************************************************
* : CAN_TXSuccess()
* : 
*     : CAN_TypeDef * CANx    CANCAN
*     : uint32_t          1     0 
* : 
******************************************************************************************************************************************/
uint32_t CAN_TXSuccess(CAN_TypeDef * CANx)
{
    return (CANx->SR & CAN_SR_TXOK_Msk) ? 1 : 0;
}

/******************************************************************************************************************************************
* : CAN_AbortTransmit()
* : 
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_AbortTransmit(CAN_TypeDef * CANx)
{
    CANx->CMD = (1 << CAN_CMD_ABTTX_Pos);
}

/******************************************************************************************************************************************
* : CAN_TXBufferReady()
* : TX Buffer
*     : CAN_TypeDef * CANx    CANCAN
*     : uint32_t          1     0 
* : 
******************************************************************************************************************************************/
uint32_t CAN_TXBufferReady(CAN_TypeDef * CANx)
{
    return (CANx->SR & CAN_SR_TXBR_Msk) ? 1 : 0;
}

/******************************************************************************************************************************************
* : CAN_RXDataAvailable()
* : RX FIFO
*     : CAN_TypeDef * CANx    CANCAN
*     : uint32_t          1     0 
* : 
******************************************************************************************************************************************/
uint32_t CAN_RXDataAvailable(CAN_TypeDef * CANx)
{
    return (CANx->SR & CAN_SR_RXDA_Msk) ? 1 : 0;
}

/******************************************************************************************************************************************
* : CAN_SetBaudrate()
* : 
*     : CAN_TypeDef * CANx    CANCAN
*           uint32_t baudrate   
*           uint32_t CAN_BS1    CAN_BS1_1tqCAN_BS1_2tq... ... CAN_BS1_16tq
*           uint32_t CAN_BS2    CAN_BS2_1tqCAN_BS2_2tq... ... CAN_BS2_8tq
*           uint32_t CAN_SJW    CAN_SJW_1tqCAN_SJW_2tqCAN_SJW_3tqCAN_SJW_4tq
*     : 
* : CAN_Close()CAN
******************************************************************************************************************************************/
void CAN_SetBaudrate(CAN_TypeDef * CANx, uint32_t baudrate, uint32_t CAN_BS1, uint32_t CAN_BS2, uint32_t CAN_SJW)
{
    CANx->BT1 = (0 << CAN_BT1_SAM_Pos) |
                (CAN_BS1 << CAN_BT1_TSEG1_Pos) |
                (CAN_BS2 << CAN_BT1_TSEG2_Pos);

    CANx->BT0 = (CAN_SJW << CAN_BT0_SJW_Pos) |
                ((SystemCoreClock/2/baudrate/(1 + (CAN_BS1 + 1) + (CAN_BS2 + 1)) - 1) << CAN_BT0_BRP_Pos);
}

/******************************************************************************************************************************************
* : CAN_SetFilter32b()
* : 132
*     : CAN_TypeDef * CANx    CANCAN
*           uint32_t check      maskMessagecheck & (~mask) == ID & (~mask)Message
*           uint32_t mask
*     : 
* : CAN_Close()CAN
******************************************************************************************************************************************/
void CAN_SetFilter32b(CAN_TypeDef * CANx, uint32_t check, uint32_t mask)
{
    CANx->CR &= ~CAN_CR_AFM_Msk;
    CANx->CR |= (CAN_FILTER_32b << CAN_CR_AFM_Pos);

    CANx->FILTER.AMR[3] =  mask & 0xFF;
    CANx->FILTER.AMR[2] = (mask >>  8) & 0xFF;
    CANx->FILTER.AMR[1] = (mask >> 16) & 0xFF;
    CANx->FILTER.AMR[0] = (mask >> 24) & 0xFF;

    CANx->FILTER.ACR[3] =  check & 0xFF;
    CANx->FILTER.ACR[2] = (check >>  8) & 0xFF;
    CANx->FILTER.ACR[1] = (check >> 16) & 0xFF;
    CANx->FILTER.ACR[0] = (check >> 24) & 0xFF;
}

/******************************************************************************************************************************************
* : CAN_SetFilter16b()
* : 216
*     : CAN_TypeDef * CANx    CANCAN
*           uint16_t check1     maskMessagecheck & (~mask) == ID & (~mask)Message
*           uint16_t mask1
*           uint16_t check2
*           uint16_t mask2
*     : 
* : CAN_Close()CAN
******************************************************************************************************************************************/
void CAN_SetFilter16b(CAN_TypeDef * CANx, uint16_t check1, uint16_t mask1, uint16_t check2, uint16_t mask2)
{
    CANx->CR &= ~CAN_CR_AFM_Msk;
    CANx->CR |= (CAN_FILTER_16b << CAN_CR_AFM_Pos);

    CANx->FILTER.AMR[3] =  mask1 & 0xFF;
    CANx->FILTER.AMR[2] = (mask1 >>  8) & 0xFF;
    CANx->FILTER.AMR[1] =  mask2 & 0xFF;
    CANx->FILTER.AMR[0] = (mask2 >>  8) & 0xFF;

    CANx->FILTER.ACR[3] =  check1 & 0xFF;
    CANx->FILTER.ACR[2] = (check1 >>  8) & 0xFF;
    CANx->FILTER.ACR[1] =  check2 & 0xFF;
    CANx->FILTER.ACR[0] = (check2 >>  8) & 0xFF;
}

/******************************************************************************************************************************************
* : CAN_INTRXNotEmptyEn()
* : RX FIFO
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTRXNotEmptyEn(CAN_TypeDef * CANx)
{
    CANx->IE |= (1 << CAN_IE_RXDA_Pos);
}

/******************************************************************************************************************************************
* : CAN_INTRXNotEmptyDis()
* : RX FIFO
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTRXNotEmptyDis(CAN_TypeDef * CANx)
{
    CANx->IE &= ~(1 << CAN_IE_RXDA_Pos);
}

/******************************************************************************************************************************************
* : CAN_INTTXBufEmptyEn()
* : TX Buffer
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTTXBufEmptyEn(CAN_TypeDef * CANx)
{
    CANx->IE |= (1 << CAN_IE_TXBR_Pos);
}

/******************************************************************************************************************************************
* : CAN_INTTXBufEmptyDis()
* : TX Buffer
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTTXBufEmptyDis(CAN_TypeDef * CANx)
{
    CANx->IE &= ~(1 << CAN_IE_TXBR_Pos);
}

/******************************************************************************************************************************************
* : CAN_INTErrWarningEn()
* : TXERR/RXERRError Warning Limit
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTErrWarningEn(CAN_TypeDef * CANx)
{
    CANx->IE |= (1 << CAN_IE_ERRWARN_Pos);
}

/******************************************************************************************************************************************
* : CAN_INTErrWarningDis()
* : TXERR/RXERRError Warning Limit
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTErrWarningDis(CAN_TypeDef * CANx)
{
    CANx->IE &= ~(1 << CAN_IE_ERRWARN_Pos);
}

/******************************************************************************************************************************************
* : CAN_INTRXOverflowEn()
* : RX FIFO 
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTRXOverflowEn(CAN_TypeDef * CANx)
{
    CANx->IE |= (1 << CAN_IE_RXOV_Pos);
}

/******************************************************************************************************************************************
* : CAN_INTRXOverflowDis()
* : RX FIFO 
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTRXOverflowDis(CAN_TypeDef * CANx)
{
    CANx->IE &= ~(1 << CAN_IE_RXOV_Pos);
}

/******************************************************************************************************************************************
* : CAN_INTRXOverflowClear()
* : RX FIFO 
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTRXOverflowClear(CAN_TypeDef * CANx)
{
    CANx->CMD = (1 << CAN_CMD_CLROV_Pos);
}

/******************************************************************************************************************************************
* : CAN_INTWakeupEn()
* : 
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTWakeupEn(CAN_TypeDef * CANx)
{
    CANx->IE |= (1 << CAN_IE_WKUP_Pos);
}

/******************************************************************************************************************************************
* : CAN_INTWakeupDis()
* : 
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTWakeupDis(CAN_TypeDef * CANx)
{
    CANx->IE &= ~(1 << CAN_IE_WKUP_Pos);
}

/******************************************************************************************************************************************
* : CAN_INTErrPassiveEn()
* : TXERR/RXERR127
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTErrPassiveEn(CAN_TypeDef * CANx)
{
    CANx->IE |= (1 << CAN_IE_ERRPASS_Pos);
}

/******************************************************************************************************************************************
* : CAN_INTErrPassiveDis()
* : TXERR/RXERR127
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTErrPassiveDis(CAN_TypeDef * CANx)
{
    CANx->IE &= ~(1 << CAN_IE_ERRPASS_Pos);
}

/******************************************************************************************************************************************
* : CAN_INTArbitrLostEn()
* : 
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTArbitrLostEn(CAN_TypeDef * CANx)
{
    CANx->IE |= (1 << CAN_IE_ARBLOST_Pos);
}

/******************************************************************************************************************************************
* : CAN_INTArbitrLostDis()
* : 
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTArbitrLostDis(CAN_TypeDef * CANx)
{
    CANx->IE &= ~(1 << CAN_IE_ARBLOST_Pos);
}

/******************************************************************************************************************************************
* : CAN_INTBusErrorEn()
* : 
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTBusErrorEn(CAN_TypeDef * CANx)
{
    CANx->IE |= (1 << CAN_IE_BUSERR_Pos);
}

/******************************************************************************************************************************************
* : CAN_INTBusErrorDis()
* : 
*     : CAN_TypeDef * CANx    CANCAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTBusErrorDis(CAN_TypeDef * CANx)
{
    CANx->IE &= ~(1 << CAN_IE_BUSERR_Pos);
}

/******************************************************************************************************************************************
* : CAN_INTStat()
* : 
*     : CAN_TypeDef * CANx    CANCAN
*     : uint32_t          
* : CANx->IFISR
******************************************************************************************************************************************/
uint32_t CAN_INTStat(CAN_TypeDef * CANx)
{
    return CANx->IF;
}
