/******************************************************************************************************************************************
* : SWM320_i2c.c
* : SWM320I2C
* : http://www.synwit.com.cn/e/tool/gbook/?bid=1
* :
* : V1.1.0      20171025
* :
*
*
*******************************************************************************************************************************************
* @attention
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIES AT PROVIDING CUSTOMERS WITH CODING INFORMATION
* REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIEE. AS A RESULT, SYNWIT SHALL NOT BE HELD LIABLE
* FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIES ARISING FROM THE CONTENT
* OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN IN CONN-
* -ECTION WITH THEIR PRODUCTS.
*
* COPYRIGHT 2012 Synwit Technology
*******************************************************************************************************************************************/
#include "SWM320.h"
#include "SWM320_i2c.h"

/******************************************************************************************************************************************
* : I2C_Init()
* : I2C
*     : I2C_TypeDef * I2Cx        I2CI2C0I2C1
*           I2C_InitStructure * initStruct  I2C
*     : 
* : 
******************************************************************************************************************************************/
void I2C_Init(I2C_TypeDef * I2Cx, I2C_InitStructure * initStruct)
{
    switch((uint32_t)I2Cx)
    {
    case ((uint32_t)I2C0):
        SYS->CLKEN |= (0x01 << SYS_CLKEN_I2C0_Pos);
        break;

    case ((uint32_t)I2C1):
        SYS->CLKEN |= (0x01 << SYS_CLKEN_I2C1_Pos);
        break;
    }

    I2C_Close(I2Cx);    //I2C

    if(initStruct->Master == 1)
    {
        I2Cx->CLKDIV = SystemCoreClock/5/initStruct->MstClk;

        I2Cx->MSTCMD = (I2Cx->MSTCMD & (~I2C_MSTCMD_IF_Msk)) | (1 << I2C_MSTCMD_IF_Pos);    //
        I2Cx->CTRL &= ~I2C_CTRL_MSTIE_Msk;
        I2Cx->CTRL |= (initStruct->MstIEn << I2C_CTRL_MSTIE_Pos);

        switch((uint32_t)I2Cx)
        {
        case ((uint32_t)I2C0):
            if(initStruct->MstIEn)
            {
                NVIC_EnableIRQ(I2C0_IRQn);
            }
            else
            {
                NVIC_DisableIRQ(I2C0_IRQn);
            }
            break;

        case ((uint32_t)I2C1):
            if(initStruct->MstIEn)
            {
                NVIC_EnableIRQ(I2C1_IRQn);
            }
            else
            {
                NVIC_DisableIRQ(I2C1_IRQn);
            }
            break;
        }
    }
    else
    {
        I2Cx->SLVCR |=  (1 << I2C_SLVCR_SLAVE_Pos);

        I2Cx->SLVCR &= ~(I2C_SLVCR_ADDR7b_Msk | I2C_SLVCR_ADDR_Msk);
        I2Cx->SLVCR |= (1 << I2C_SLVCR_ACK_Pos) |
                       (initStruct->Addr7b << I2C_SLVCR_ADDR7b_Pos) |
                       (initStruct->SlvAddr << I2C_SLVCR_ADDR_Pos);

        I2Cx->SLVIF = I2C_SLVIF_RXEND_Msk | I2C_SLVIF_TXEND_Msk | I2C_SLVIF_STADET_Msk | I2C_SLVIF_STODET_Msk;  //
        I2Cx->SLVCR &= ~(I2C_SLVCR_IM_RXEND_Msk | I2C_SLVCR_IM_TXEND_Msk | I2C_SLVCR_IM_STADET_Msk | I2C_SLVCR_IM_STODET_Msk |
                         I2C_SLVCR_IM_RDREQ_Msk | I2C_SLVCR_IM_WRREQ_Msk);
        I2Cx->SLVCR |= ((initStruct->SlvRxEndIEn  ? 0 : 1) << I2C_SLVCR_IM_RXEND_Pos)  |
                       ((initStruct->SlvTxEndIEn  ? 0 : 1) << I2C_SLVCR_IM_TXEND_Pos)  |
                       ((initStruct->SlvSTADetIEn ? 0 : 1) << I2C_SLVCR_IM_STADET_Pos) |
                       ((initStruct->SlvSTODetIEn ? 0 : 1) << I2C_SLVCR_IM_STODET_Pos) |
                       ((initStruct->SlvRdReqIEn  ? 0 : 1) << I2C_SLVCR_IM_RDREQ_Pos)  |
                       ((initStruct->SlvWrReqIEn  ? 0 : 1) << I2C_SLVCR_IM_WRREQ_Pos);

        switch((uint32_t)I2Cx)
        {
        case ((uint32_t)I2C0):
            if(initStruct->SlvRxEndIEn | initStruct->SlvTxEndIEn | initStruct->SlvSTADetIEn |
               initStruct->SlvSTODetIEn | initStruct->SlvRdReqIEn | initStruct->SlvWrReqIEn)
            {
                NVIC_EnableIRQ(I2C0_IRQn);
            }
            else
            {
                NVIC_DisableIRQ(I2C0_IRQn);
            }
            break;

        case ((uint32_t)I2C1):
            if(initStruct->SlvRxEndIEn | initStruct->SlvTxEndIEn | initStruct->SlvSTADetIEn |
               initStruct->SlvSTODetIEn | initStruct->SlvRdReqIEn | initStruct->SlvWrReqIEn)
            {
                NVIC_EnableIRQ(I2C1_IRQn);
            }
            else
            {
                NVIC_DisableIRQ(I2C1_IRQn);
            }
            break;
        }
    }
}

/******************************************************************************************************************************************
* : I2C_Open()
* : I2C
*     : I2C_TypeDef * I2Cx        I2CI2C0I2C1
*     : 
* : 
******************************************************************************************************************************************/
void I2C_Open(I2C_TypeDef * I2Cx)
{
    I2Cx->CTRL |= (0x01 << I2C_CTRL_EN_Pos);
}

/******************************************************************************************************************************************
* : I2C_Close()
* : I2C
*     : I2C_TypeDef * I2Cx        I2CI2C0I2C1
*     : 
* : 
******************************************************************************************************************************************/
void I2C_Close(I2C_TypeDef * I2Cx)
{
    I2Cx->CTRL &= ~I2C_CTRL_EN_Msk;
}

/******************************************************************************************************************************************
* : I2C_Start()
* : 
*     : I2C_TypeDef * I2Cx        I2CI2C0I2C1
*           uint8_t addr            
*     : uint8_t                   1 ACK   0 NACK
* : 
******************************************************************************************************************************************/
uint8_t I2C_Start(I2C_TypeDef * I2Cx, uint8_t addr)
{
    I2Cx->MSTDAT = addr;
    I2Cx->MSTCMD = (1 << I2C_MSTCMD_STA_Pos) |
                   (1 << I2C_MSTCMD_WR_Pos);                //
    while(I2Cx->MSTCMD & I2C_MSTCMD_TIP_Msk) __NOP();       //

    return (I2Cx->MSTCMD & I2C_MSTCMD_RXACK_Msk) ? 0 : 1;
}

/******************************************************************************************************************************************
* : I2C_Stop()
* : 
*     : I2C_TypeDef * I2Cx        I2CI2C0I2C1
*     : 
* : 
******************************************************************************************************************************************/
void I2C_Stop(I2C_TypeDef * I2Cx)
{
    I2Cx->MSTCMD = (1 << I2C_MSTCMD_STO_Pos);
    while(I2Cx->MSTCMD & I2C_MSTCMD_TIP_Msk) __NOP();       //
}

/******************************************************************************************************************************************
* : I2C_Write()
* : 
*     : I2C_TypeDef * I2Cx        I2CI2C0I2C1
*           uint8_t data            
*     : uint8_t                   1 ACK   0 NACK
* : 
******************************************************************************************************************************************/
uint8_t I2C_Write(I2C_TypeDef * I2Cx, uint8_t data)
{
    I2Cx->MSTDAT = data;
    I2Cx->MSTCMD = (1 << I2C_MSTCMD_WR_Pos);
    while(I2Cx->MSTCMD & I2C_MSTCMD_TIP_Msk) __NOP();       //

    return (I2Cx->MSTCMD & I2C_MSTCMD_RXACK_Msk) ? 0 : 1;
}

/******************************************************************************************************************************************
* : I2C_Read()
* : 
*     : I2C_TypeDef * I2Cx        I2CI2C0I2C1
*           uint8_t ack             1 ACK   0 NACK
*     : uint8_t                   
* : 
******************************************************************************************************************************************/
uint8_t I2C_Read(I2C_TypeDef * I2Cx, uint8_t ack)
{
    I2Cx->MSTCMD = (1 << I2C_MSTCMD_RD_Pos) |
                   ((ack ? 0 : 1) << I2C_MSTCMD_ACK_Pos);
    while(I2Cx->MSTCMD & I2C_MSTCMD_TIP_Msk) __NOP();       //

    return I2Cx->MSTDAT;
}
