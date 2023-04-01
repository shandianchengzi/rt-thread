/******************************************************************************************************************************************
* : SWM341_can.c
* : SWM341CAN
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
#include "SWM341.h"
#include "SWM341_can.h"


/******************************************************************************************************************************************
* : CAN_Init()
* : CAN
*     : CAN_TypeDef * CANx    CANCAN0CAN1
*           CAN_InitStructure * initStruct    CAN
*     : 
* : 
******************************************************************************************************************************************/
void CAN_Init(CAN_TypeDef * CANx, CAN_InitStructure * initStruct)
{
    uint32_t brp = (SystemCoreClock/2)/2/initStruct->Baudrate/(1 + (initStruct->CAN_bs1 + 1) + (initStruct->CAN_bs2 + 1)) - 1;

    switch((uint32_t)CANx)
    {
    case ((uint32_t)CAN0):
        SYS->CLKEN0 |= (0x01 << SYS_CLKEN0_CAN0_Pos);
        break;

    case ((uint32_t)CAN1):
        SYS->CLKEN1 |= (0x01 << SYS_CLKEN1_CAN1_Pos);
        break;
    }

    CAN_Close(CANx);    //CAN

    CANx->CR &= ~(CAN_CR_LOM_Msk | CAN_CR_STM_Msk);
    CANx->CR |= (initStruct->Mode << CAN_CR_LOM_Pos);

    CANx->BT1 = (0 << CAN_BT1_SAM_Pos) |
                (initStruct->CAN_bs1 << CAN_BT1_TSEG1_Pos) |
                (initStruct->CAN_bs2 << CAN_BT1_TSEG2_Pos);

    CANx->BT0 = (initStruct->CAN_sjw << CAN_BT0_SJW_Pos) |
                ((brp & 0x3F) << CAN_BT0_BRP_Pos);

    CANx->BT2 = ((brp >> 6) << CAN_BT2_BRP_Pos);

    CANx->RXERR = 0;    //
    CANx->TXERR = 0;

    CANx->IE = (initStruct->RXNotEmptyIEn << CAN_IE_RXDA_Pos)    |
               (initStruct->ArbitrLostIEn << CAN_IE_ARBLOST_Pos) |
               (initStruct->ErrPassiveIEn << CAN_IE_ERRPASS_Pos);

    switch((uint32_t)CANx)
    {
    case ((uint32_t)CAN0):
        if(initStruct->RXNotEmptyIEn | initStruct->ArbitrLostIEn | initStruct->ErrPassiveIEn)
        {
            NVIC_EnableIRQ(CAN0_IRQn);
        }
        else
        {
            NVIC_DisableIRQ(CAN0_IRQn);
        }
        break;

    case ((uint32_t)CAN1):
        if(initStruct->RXNotEmptyIEn | initStruct->ArbitrLostIEn | initStruct->ErrPassiveIEn)
        {
            NVIC_EnableIRQ(CAN1_IRQn);
        }
        else
        {
            NVIC_DisableIRQ(CAN1_IRQn);
        }
        break;
    }
}

/******************************************************************************************************************************************
* : CAN_Open()
* : CAN
*     : CAN_TypeDef * CANx    CANCAN0CAN1
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
*     : CAN_TypeDef * CANx    CANCAN0CAN1
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
*     : CAN_TypeDef * CANx    CANCAN0CAN1
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
*     : CAN_TypeDef * CANx    CANCAN0CAN1
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
*     : CAN_TypeDef * CANx    CANCAN0CAN1
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
*     : CAN_TypeDef * CANx    CANCAN0CAN1
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
*     : CAN_TypeDef * CANx    CANCAN0CAN1
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
*     : CAN_TypeDef * CANx    CANCAN0CAN1
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
*     : CAN_TypeDef * CANx    CANCAN0CAN1
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
*     : CAN_TypeDef * CANx    CANCAN0CAN1
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
*     : CAN_TypeDef * CANx    CANCAN0CAN1
*           uint32_t baudrate   
*           uint32_t CAN_bs1    CAN_BS1_1tqCAN_BS1_2tq... ... CAN_BS1_16tq
*           uint32_t CAN_bs2    CAN_BS2_1tqCAN_BS2_2tq... ... CAN_BS2_8tq
*           uint32_t CAN_sjw    CAN_SJW_1tqCAN_SJW_2tqCAN_SJW_3tqCAN_SJW_4tq
*     : 
* : CAN_Close()CAN
******************************************************************************************************************************************/
void CAN_SetBaudrate(CAN_TypeDef * CANx, uint32_t baudrate, uint32_t CAN_bs1, uint32_t CAN_bs2, uint32_t CAN_sjw)
{
    uint32_t brp = (SystemCoreClock/2)/2/baudrate/(1 + (CAN_bs1 + 1) + (CAN_bs2 + 1)) - 1;

    CANx->BT1 = (0 << CAN_BT1_SAM_Pos) |
                (CAN_bs1 << CAN_BT1_TSEG1_Pos) |
                (CAN_bs2 << CAN_BT1_TSEG2_Pos);

    CANx->BT0 = (CAN_sjw << CAN_BT0_SJW_Pos) |
                ((brp & 0x3F) << CAN_BT0_BRP_Pos);

    CANx->BT2 = ((brp >> 6) << CAN_BT2_BRP_Pos);
}

/******************************************************************************************************************************************
* : CAN_SetFilter32b()
* : 132
*     : CAN_TypeDef * CANx    CANCAN0CAN1
*           uint32_t filter     CAN_FILTER_1CAN_FILTER_2...CAN_FILTER_16
*           uint32_t check      maskMessagecheck & mask == ID & maskMessage
*           uint32_t mask
*     : 
* : 
******************************************************************************************************************************************/
void CAN_SetFilter32b(CAN_TypeDef * CANx, uint32_t filter, uint32_t check, uint32_t mask)
{
    CANx->AFM |= (1 << filter);

    CANx->ACR[filter] = __REV(check << 3);      // 29
    CANx->AMR[filter] = __REV(~(mask << 3));

    CANx->AFE |= (1 << filter);
}

/******************************************************************************************************************************************
* : CAN_SetFilter16b()
* : 216
*     : CAN_TypeDef * CANx    CANCAN0CAN1
*           uint32_t filter     CAN_FILTER_1CAN_FILTER_2...CAN_FILTER_16
*           uint16_t check1     maskMessagecheck & mask == ID & maskMessage
*           uint16_t mask1
*           uint16_t check2
*           uint16_t mask2
*     : 
* : 
******************************************************************************************************************************************/
void CAN_SetFilter16b(CAN_TypeDef * CANx, uint32_t filter, uint16_t check1, uint16_t mask1, uint16_t check2, uint16_t mask2)
{
    CANx->AFM &= ~(1 << filter);

    CANx->ACR[filter] = __REV((check1 << 5) | (check2 << 21));      // 11
    CANx->AMR[filter] = __REV(~((mask1 << 5) | (mask2 << 21)));

    CANx->AFE |= (1 << filter);
}

/******************************************************************************************************************************************
* : CAN_INTEn()
* : 
*     : CAN_TypeDef * CANx    CANCAN0CAN1
*           uint32_t it         interrupt typeCAN_INT_RX_NOTEMPTYCAN_INT_RX_OVERFLOWCAN_INT_TX_EMPTY...
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTEn(CAN_TypeDef * CANx, uint32_t it)
{
    CANx->IE |= it;
}

/******************************************************************************************************************************************
* : CAN_INTDis()
* : 
*     : CAN_TypeDef * CANx    CANCAN0CAN1
*           uint32_t it         interrupt typeCAN_INT_RX_NOTEMPTYCAN_INT_RX_OVERFLOWCAN_INT_TX_EMPTY...
*     : 
* : 
******************************************************************************************************************************************/
void CAN_INTDis(CAN_TypeDef * CANx, uint32_t it)
{
    CANx->IE &= ~it;
}

/******************************************************************************************************************************************
* : CAN_INTStat()
* : 
*     : CAN_TypeDef * CANx    CANCAN0CAN1
*     : uint32_t          
* : CANx->IFISR
******************************************************************************************************************************************/
uint32_t CAN_INTStat(CAN_TypeDef * CANx)
{
    return CANx->IF;
}
