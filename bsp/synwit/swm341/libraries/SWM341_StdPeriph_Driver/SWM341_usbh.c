/******************************************************************************************************************************************
* : SWM341_usbh.c
* : SWM341USB
* : http://www.synwit.com.cn/e/tool/gbook/?bid=1
* :
* : V1.1.0      2020113
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
#include <string.h>
#include "SWM341.h"
#include "SWM341_usbh.h"


static uint32_t Speed;


/******************************************************************************************************************************************
* : USBH_HW_Init()
* : USB Host Hardware 
*     : 
*     : 
* : 
******************************************************************************************************************************************/
void USBH_HW_Init(void)
{
    SYS->USBCR = 0;
    for(int i = 0; i < CyclesPerUs; i++) __NOP();
    SYS->USBCR |= (1 << SYS_USBCR_RST48M_Pos); __DSB();
    SYS->USBCR |= (1 << SYS_USBCR_RST12M_Pos); __DSB();
    SYS->USBCR |= (1 << SYS_USBCR_RSTPLL_Pos); __DSB();

    SYS->USBCR &= ~SYS_USBCR_ROLE_Msk;
    SYS->USBCR |= (2 << SYS_USBCR_ROLE_Pos);

    SYS->USBCR |= (1 << SYS_USBCR_VBUS_Pos);

    SYS->CLKEN0 |= (0x01 << SYS_CLKEN0_USB_Pos);

    USBH->CR = USBH_CR_FLUSHFF_Msk;

    USBD->DEVCR = (0 << USBD_DEVCR_DEVICE_Pos) |    // 
                  (3 << USBD_DEVCR_SPEED_Pos)  |
                  (1 << USBD_DEVCR_CSRDONE_Pos);

    USBH->PORTSR = USBH_PORTSR_POWER_Msk;
}


/******************************************************************************************************************************************
* : USBH_ResetPort()
* : 
*     : 
*     : 
* : 
******************************************************************************************************************************************/
void USBH_ResetPort(void)
{
    USBH->PORTSR = USBH_PORTSR_RESET_Msk;
}


/******************************************************************************************************************************************
* : USBH_IsDeviceConnected()
* : 
*     : 
*     : 
* : 
******************************************************************************************************************************************/
uint32_t USBH_IsDeviceConnected(void)
{
    return (USBH->PORTSR & USBH_PORTSR_CONN_Msk) ? 1 : 0;
}


/******************************************************************************************************************************************
* : USBH_IsPortEnabled()
* : 
*     : 
*     : 
* : 
******************************************************************************************************************************************/
uint32_t USBH_IsPortEnabled(void)
{
    return (USBH->PORTSR & USBH_PORTSR_ENA_Msk) ? 1 : 0;
}


/******************************************************************************************************************************************
* : USBH_GetDeviceSpeed()
* : 
*     : 
*     : uint32_t          2    3 
* : 
******************************************************************************************************************************************/
uint32_t USBH_GetDeviceSpeed(void)
{
    Speed = (USBH->PORTSR & USBH_PORTSR_SPEED_Msk) ? 2 : 3;

    return Speed;
}


/******************************************************************************************************************************************
* : USBH_State()
* :
*     : 
*     : 
* : 
******************************************************************************************************************************************/
USBH_Resp USBH_State(void)
{
    if(USBH->IF & USBH_IF_RXSTAT_Msk)
    {
        USBH->IF = USBH_IF_RXSTAT_Msk;

        switch(USBH->SR & USBH_SR_RESP_Msk)
        {
        case USBR_ACK:
        case USBR_NAK:
        case USBR_STALL:
            return (USBH->SR & USBH_SR_RESP_Msk);

        case USBR_ERR_PID:
        case USBR_ERR_CRC:
        case USBR_ERR_STUFF:
        case USBR_ERR_TOGGLE:
        case USBR_TIMEOUT:
        case USBR_UNEXPECTED_PID:
            return USBR_ERROR;
        }
    }

    return USBR_NO;
}


/******************************************************************************************************************************************
* : USBH_SendSetupPacket()
* :  Setup 
*     : 
*     : 
* : 
******************************************************************************************************************************************/
uint32_t USBH_SendSetupPacket(uint8_t addr, uint8_t *data, uint16_t size)
{
    uint32_t res;

    __disable_irq();

    if((USBH->FRAMERM < 10000) && (USBH->FRAMERM > 2000))
    {
        USBH->TXTRSZ = size;
        for(uint32_t i = 0; i < size; i++)
        {
            ((uint8_t *)USBH->TXBUF)[i] = data[i];
        }

        USBH->TOKEN = (addr  << USBH_TOKEN_ADDR_Pos)  |
                      (0     << USBH_TOKEN_EPNR_Pos)  |
                      (13    << USBH_TOKEN_TYPE_Pos)  |
                      (0     << USBH_TOKEN_DATAX_Pos) |
                      (Speed << USBH_TOKEN_SPEED_Pos) |
                      (size  << USBH_TOKEN_TRSZ_Pos);

        res = 1;
    }
    else
    {
        res = 0;
    }

    __enable_irq();

    return res;
}


/******************************************************************************************************************************************
* : USBH_SendOutPacket()
* :  Out 
*     : 
*     : 
* : 
******************************************************************************************************************************************/
uint32_t USBH_SendOutPacket(uint8_t addr, uint8_t endp, uint8_t DATAx, uint8_t *data, uint16_t size)
{
    uint32_t res;

    __disable_irq();

    if((USBH->FRAMERM < 10000) && (USBH->FRAMERM > 2000))
    {
        USBH->TXTRSZ = size;
        for(uint32_t i = 0; i < size; i++)
        {
            ((uint8_t *)USBH->TXBUF)[i] = data[i];
        }

        USBH->TOKEN = (addr  << USBH_TOKEN_ADDR_Pos)  |
                      (endp  << USBH_TOKEN_EPNR_Pos)  |
                      (1     << USBH_TOKEN_TYPE_Pos)  |
                      (DATAx << USBH_TOKEN_DATAX_Pos) |
                      (Speed << USBH_TOKEN_SPEED_Pos) |
                      (size  << USBH_TOKEN_TRSZ_Pos);

        res = 1;
    }
    else
    {
        res = 0;
    }

    __enable_irq();

    return res;
}


/******************************************************************************************************************************************
* : USBH_SendInPacket()
* :  In 
*     : 
*     : 
* : 
******************************************************************************************************************************************/
uint32_t USBH_SendInPacket(uint8_t addr, uint8_t endp, uint8_t DATAx, uint16_t size)
{
    uint32_t res;

    __disable_irq();

    if((USBH->FRAMERM < 10000) && (USBH->FRAMERM > 2000))
    {
        endp &= 0x0F;

        USBH->TOKEN = (addr  << USBH_TOKEN_ADDR_Pos)  |
                      (endp  << USBH_TOKEN_EPNR_Pos)  |
                      (9     << USBH_TOKEN_TYPE_Pos)  |
                      (DATAx << USBH_TOKEN_DATAX_Pos) |
                      (Speed << USBH_TOKEN_SPEED_Pos) |
                      (size  << USBH_TOKEN_TRSZ_Pos);

        res = 1;
    }
    else
    {
        res = 0;
    }

    __enable_irq();

    return res;
}


/******************************************************************************************************************************************
* : USBH_ReadRxBuffer()
* : 
*     : 
*     : 
* : 
******************************************************************************************************************************************/
uint32_t USBH_ReadRxBuffer(uint8_t *buff, uint32_t size)
{
    uint32_t real_size = (USBH->SR & USBH_SR_TRSZ_Msk) >> USBH_SR_TRSZ_Pos;

    if(size > real_size)
        size = real_size;

    memcpy(buff, (uint8_t *)USBH->RXBUF, size);

    return size;
}

