/******************************************************************************************************************************************
* : SWM341_adc.c
* : SWM341ADC
* : http://www.synwit.com.cn/e/tool/gbook/?bid=1
* :
* : V1.0.0      2016130
* :
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
#include "SWM341_adc.h"


/******************************************************************************************************************************************
* : ADC_Init()
* : ADC
*     : ADC_TypeDef * ADCx        ADCADC0ADC1
*           ADC_InitStructure * initStruct      ADC
*     : 
* : 
******************************************************************************************************************************************/
void ADC_Init(ADC_TypeDef * ADCx, ADC_InitStructure * initStruct)
{
    uint32_t i;

    switch((uint32_t)ADCx)
    {
    case ((uint32_t)ADC0):
        SYS->CLKSEL &= ~(SYS_CLKSEL_AD0_Msk | SYS_CLKSEL_AD0DIV_Msk);
        SYS->CLKSEL |= (initStruct->clk_src << SYS_CLKSEL_AD0_Pos);

        SYS->CLKEN0 |= (0x01 << SYS_CLKEN0_ADC0_Pos);
        break;

    case ((uint32_t)ADC1):
        SYS->CLKSEL &= ~(SYS_CLKSEL_AD1_Msk | SYS_CLKSEL_AD1DIV_Msk);
        SYS->CLKSEL |= (initStruct->clk_src << SYS_CLKSEL_AD1_Pos);

        SYS->CLKEN1 |= (0x01 << SYS_CLKEN1_ADC1_Pos);
        break;
    }

    ADC_Close(ADCx);        //ADC

    ADCx->CR |= (1 <<ADC_CR_RESET_Pos);
    for(i = 0; i < 120*20; i++) __NOP();    //2
    ADCx->CR &= ~(1 << ADC_CR_RESET_Pos);

    ADCx->CR |= (0xF << ADC_CR_FFCLR_Pos);
    ADCx->CR &= ~(0xF << ADC_CR_FFCLR_Pos);

    ADCx->CR &= ~ADC_CR_AVG_Msk;
    ADCx->CR |= (initStruct->samplAvg << ADC_CR_AVG_Pos);

    ADCx->IE = 0;
    ADCx->IF = 0x3F3F3F3F;  //

    ADCx->IE |= (((initStruct->EOC_IEn & ADC_SEQ0) ? 1 : 0) << ADC_IE_SEQ0EOC_Pos) |
                (((initStruct->EOC_IEn & ADC_SEQ1) ? 1 : 0) << ADC_IE_SEQ1EOC_Pos) |
                (((initStruct->EOC_IEn & ADC_SEQ2) ? 1 : 0) << ADC_IE_SEQ2EOC_Pos) |
                (((initStruct->EOC_IEn & ADC_SEQ3) ? 1 : 0) << ADC_IE_SEQ3EOC_Pos);

    ADCx->IE |= (((initStruct->HalfIEn & ADC_SEQ0) ? 1 : 0) << ADC_IE_SEQ0HALF_Pos) |
                (((initStruct->HalfIEn & ADC_SEQ1) ? 1 : 0) << ADC_IE_SEQ1HALF_Pos) |
                (((initStruct->HalfIEn & ADC_SEQ2) ? 1 : 0) << ADC_IE_SEQ2HALF_Pos) |
                (((initStruct->HalfIEn & ADC_SEQ3) ? 1 : 0) << ADC_IE_SEQ3HALF_Pos);

    switch((uint32_t)ADCx)
    {
    case ((uint32_t)ADC0):
        if(initStruct->EOC_IEn | initStruct->HalfIEn) NVIC_EnableIRQ(ADC0_IRQn);
        break;

    case ((uint32_t)ADC1):
        if(initStruct->EOC_IEn | initStruct->HalfIEn) NVIC_EnableIRQ(ADC1_IRQn);
        break;
    }
}

static uint32_t ADC_seq2pos(uint32_t seq)
{
    uint32_t pos = 0;

    switch(seq)
    {
    case ADC_SEQ0: pos = 0;  break;
    case ADC_SEQ1: pos = 8;  break;
    case ADC_SEQ2: pos = 16; break;
    case ADC_SEQ3: pos = 24; break;
    }

    return pos;
}

/******************************************************************************************************************************************
* : ADC_SEQ_Init()
* : ADC
*     : ADC_TypeDef * ADCx        ADCADC0ADC1
*           uint32_t seq            ADC_SEQ0ADC_SEQ1ADC_SEQ2ADC_SEQ3
*           ADC_SEQ_InitStructure * initStruct      ADC
*     : 
* : 
******************************************************************************************************************************************/
void ADC_SEQ_Init(ADC_TypeDef * ADCx, uint32_t seq, ADC_SEQ_InitStructure * initStruct)
{
    uint32_t pos = ADC_seq2pos(seq);

    switch(seq)
    {
    case ADC_SEQ0:
    case ADC_SEQ1:
        ADCx->SEQCHN0 &= ~(0xFFFu              << (pos * 2));
        ADCx->SEQCHN0 |= (initStruct->channels << (pos * 2));
        break;

    case ADC_SEQ2:
    case ADC_SEQ3:
        ADCx->SEQCHN1 &= ~(0xFFFu              << ((pos - 16) * 2));
        ADCx->SEQCHN1 |= (initStruct->channels << ((pos - 16) * 2));
        break;
    }

    ADCx->SEQTRG &= ~(0xFFu << pos);
    ADCx->SEQTRG |= (initStruct->trig_src << pos);

    ADCx->SEQCOV &= ~(0xFFu << pos);
    ADCx->SEQCOV |= ((initStruct->conv_cnt ? initStruct->conv_cnt - 1 : 0) << pos);

    ADCx->SEQSMP &= ~(0xFFu << pos);
    ADCx->SEQSMP |= (initStruct->samp_tim << pos);
}

/******************************************************************************************************************************************
* : ADC_CMP_Init()
* : ADC
*     : ADC_TypeDef * ADCx        ADCADC0ADC1
*           uint32_t seq            ADC_SEQ0ADC_SEQ1ADC_SEQ2ADC_SEQ3
*           ADC_CMP_InitStructure * initStruct      ADC
*     : 
* : 
******************************************************************************************************************************************/
void ADC_CMP_Init(ADC_TypeDef * ADCx, uint32_t seq, ADC_CMP_InitStructure * initStruct)
{
    uint32_t idx;
    uint32_t pos = ADC_seq2pos(seq);

    idx = pos / 8;
    ADCx->SEQ[idx].CMP = (initStruct->UpperLimit << ADC_CMP_MAX_Pos) |
                         (initStruct->LowerLimit << ADC_CMP_MIN_Pos);

    if(initStruct->UpperLimitIEn) ADCx->IE |= (1 << (pos + 4));
    else                          ADCx->IE &= ~(1 << (pos + 4));

    if(initStruct->LowerLimitIEn) ADCx->IE |= (1 << (pos + 5));
    else                          ADCx->IE &= ~(1 << (pos + 5));

    if(initStruct->UpperLimitIEn || initStruct->LowerLimitIEn)
    {
        switch((uint32_t)ADCx)
        {
        case ((uint32_t)ADC0): NVIC_EnableIRQ(ADC0_IRQn); break;
        case ((uint32_t)ADC1): NVIC_EnableIRQ(ADC1_IRQn); break;
        }
    }
}

/******************************************************************************************************************************************
* : ADC_Open()
* : ADCADC
*     : ADC_TypeDef * ADCx        ADCADC0ADC1
*     : 
* : 
******************************************************************************************************************************************/
void ADC_Open(ADC_TypeDef * ADCx)
{
    uint32_t i;

    ADCx->CR2 |= (1 << ADC_CR2_ENLDO_Pos);
    for(i = 0; i < 64*20; i++) __NOP();

    ADCx->CR |= (0x01 << ADC_CR_EN_Pos);
}

/******************************************************************************************************************************************
* : ADC_Calibrate()
* : ADC
*     : ADC_TypeDef * ADCx        ADCADC0ADC1
*     : 
* : 
******************************************************************************************************************************************/
void ADC_Calibrate(ADC_TypeDef * ADCx)
{
    uint32_t i;

    ADCx->CALIB |= (1 << ADC_CALIB_RESET_Pos);
    for(i = 0; i < 120 * 20; i++) __NOP();          //2

    ADCx->CALIB |= (1 << ADC_CALIB_START_Pos);
    for(i = 0; i < 120 * 10; i++) __NOP();
    ADCx->CALIB &=~(1 << ADC_CALIB_START_Pos);
    while(ADCx->CALIB & ADC_CALIB_BUSY_Msk) __NOP();

    ADCx->CALIB |= (1 << ADC_CALIB_LOAD_Pos);
}

/******************************************************************************************************************************************
* : ADC_Close()
* : ADCADC
*     : ADC_TypeDef * ADCx        ADCADC0ADC1
*     : 
* : 
******************************************************************************************************************************************/
void ADC_Close(ADC_TypeDef * ADCx)
{
    ADCx->CR &= ~(0x01 << ADC_CR_EN_Pos);
}

/******************************************************************************************************************************************
* : ADC_Start()
* : ADC
*     : ADC_TypeDef * ADCx        ADCADC0ADC1
*           uint32_t seq            ADCADC_SEQ0ADC_SEQ1ADC_SEQ2ADC_SEQ3
*     : 
* : 
******************************************************************************************************************************************/
void ADC_Start(ADC_TypeDef * ADCx, uint32_t seq)
{
    ADCx->GO |= (seq << ADC_GO_SEQ0_Pos);
}

/******************************************************************************************************************************************
* : ADC_Stop()
* : ADC
*     : ADC_TypeDef * ADCx        ADCADC0ADC1
*           uint32_t seq            ADCADC_SEQ0ADC_SEQ1ADC_SEQ2ADC_SEQ3
*     : 
* : 
******************************************************************************************************************************************/
void ADC_Stop(ADC_TypeDef * ADCx, uint32_t seq)
{
    ADCx->GO &= ~(seq << ADC_GO_SEQ0_Pos);
}

/******************************************************************************************************************************************
* : ADC_Read()
* : 
*     : ADC_TypeDef * ADCx        ADCADC0ADC1
*           uint32_t seq            ADCADC_SEQ0ADC_SEQ1ADC_SEQ2ADC_SEQ3
*           uint32_t *chn           ADC_CH0ADC_CH1... ...ADC_CH10ADC_CH11
*     : uint32_t              
* : 
******************************************************************************************************************************************/
uint32_t ADC_Read(ADC_TypeDef * ADCx, uint32_t seq, uint32_t *chn)
{
    uint32_t idx = ADC_seq2pos(seq) / 8;

    uint32_t reg = ADCx->SEQ[idx].DR;

    *chn = 1 << ((reg & ADC_DR_CHNUM_Msk) >> ADC_DR_CHNUM_Pos);

    return reg & ADC_DR_VALUE_Msk;
}

/******************************************************************************************************************************************
* : ADC_DataAvailable()
* : 
*     : ADC_TypeDef * ADCx        ADCADC0ADC1
*           uint32_t seq            ADCADC_SEQ0ADC_SEQ1ADC_SEQ2ADC_SEQ3
*     : uint32_t              1     0 
* : 
******************************************************************************************************************************************/
uint32_t ADC_DataAvailable(ADC_TypeDef * ADCx, uint32_t seq)
{
    uint32_t idx = ADC_seq2pos(seq) / 8;

    return (ADCx->SEQ[idx].SR & ADC_SR_EMPTY_Msk) ? 0 : 1;
}


/******************************************************************************************************************************************
* : ADC_INTEn()
* : 
*     : ADC_TypeDef * ADCx        ADCADC0ADC1
*           uint32_t seq            ADCADC_SEQ0ADC_SEQ1ADC_SEQ2ADC_SEQ3
*           uint32_t it             interrupt typeADC_IT_EOCADC_IT_FIFO_OVFADC_IT_FIFO_HALFADC_IT_FIFO_FULL
*                                           ADC_IT_CMP_MAXADC_IT_CMP_MIN 
*     : 
* : 
******************************************************************************************************************************************/
void ADC_INTEn(ADC_TypeDef * ADCx, uint32_t seq, uint32_t it)
{
    uint32_t pos = ADC_seq2pos(seq);

    ADCx->IE |= (it << pos);
}

/******************************************************************************************************************************************
* : ADC_INTDis()
* : 
*     : ADC_TypeDef * ADCx        ADCADC0ADC1
*           uint32_t seq            ADCADC_SEQ0ADC_SEQ1ADC_SEQ2ADC_SEQ3
*           uint32_t it             interrupt typeADC_IT_EOCADC_IT_FIFO_OVFADC_IT_FIFO_HALFADC_IT_FIFO_FULL
*                                           ADC_IT_CMP_MAXADC_IT_CMP_MIN 
*     : 
* : 
******************************************************************************************************************************************/
void ADC_INTDis(ADC_TypeDef * ADCx, uint32_t seq, uint32_t it)
{
    uint32_t pos = ADC_seq2pos(seq);

    ADCx->IE &= ~(it << pos);
}

/******************************************************************************************************************************************
* : ADC_INTClr()
* : 
*     : ADC_TypeDef * ADCx        ADCADC0ADC1
*           uint32_t seq            ADCADC_SEQ0ADC_SEQ1ADC_SEQ2ADC_SEQ3
*           uint32_t it             interrupt typeADC_IT_EOCADC_IT_FIFO_OVFADC_IT_FIFO_HALFADC_IT_FIFO_FULL
*                                           ADC_IT_CMP_MAXADC_IT_CMP_MIN 
*     : 
* : 
******************************************************************************************************************************************/
void ADC_INTClr(ADC_TypeDef * ADCx, uint32_t seq, uint32_t it)
{
    uint32_t pos = ADC_seq2pos(seq);

    ADCx->IF = (it << pos);
}

/******************************************************************************************************************************************
* : ADC_INTStat()
* : 
*     : ADC_TypeDef * ADCx        ADCADC0ADC1
*           uint32_t seq            ADCADC_SEQ0ADC_SEQ1ADC_SEQ2ADC_SEQ3
*           uint32_t it             interrupt typeADC_IT_EOCADC_IT_FIFO_OVFADC_IT_FIFO_HALFADC_IT_FIFO_FULL
*                                           ADC_IT_CMP_MAXADC_IT_CMP_MIN 
*     : uint32_t                  1     0 
* : 
******************************************************************************************************************************************/
uint32_t ADC_INTStat(ADC_TypeDef * ADCx, uint32_t seq, uint32_t it)
{
    uint32_t pos = ADC_seq2pos(seq);

    return (ADCx->IF & (it << pos)) ? 1 : 0;
}
