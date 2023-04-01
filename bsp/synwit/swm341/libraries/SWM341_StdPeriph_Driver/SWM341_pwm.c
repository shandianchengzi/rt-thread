/******************************************************************************************************************************************
* : SWM341_pwm.c
* : SWM341PWM
* : http://www.synwit.com.cn/e/tool/gbook/?bid=1
* :
* : V1.0.0      2016130
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
#include "SWM341_pwm.h"


/******************************************************************************************************************************************
* : PWM_Init()
* : PWM
*     : PWM_TypeDef * PWMx        PWMPWM0PWM1PWM2PWM3PWM4
*           PWM_InitStructure * initStruct  PWM
*     : 
* : 
******************************************************************************************************************************************/
void PWM_Init(PWM_TypeDef * PWMx, PWM_InitStructure * initStruct)
{
    SYS->CLKEN0 |= (0x01 << SYS_CLKEN0_PWM_Pos);

    PWMx->CR = (initStruct->Mode         << PWM_CR_MODE_Pos)   |
               (1                        << PWM_CR_MULT_Pos)   |    // 
               (0                        << PWM_CR_DIR_Pos)    |    // 
               (0                        << PWM_CR_CLKSRC_Pos) |    // 
               ((initStruct->Clkdiv - 1) << PWM_CR_CLKDIV_Pos) |
               (0                        << PWM_CR_RPTNUM_Pos); // 

    PWMx->OCR = ((initStruct->IdleLevelA  ? 1 : 0) << PWM_OCR_IDLEA_Pos)  |
                ((initStruct->IdleLevelB  ? 1 : 0) << PWM_OCR_IDLEB_Pos)  |
                ((initStruct->IdleLevelAN ? 1 : 0) << PWM_OCR_IDLEAN_Pos) |
                ((initStruct->IdleLevelBN ? 1 : 0) << PWM_OCR_IDLEBN_Pos) |
                ((initStruct->OutputInvA  ? 1 : 0) << PWM_OCR_INVA_Pos)   |
                ((initStruct->OutputInvB  ? 1 : 0) << PWM_OCR_INVB_Pos)   |
                ((initStruct->OutputInvAN ? 1 : 0) << PWM_OCR_INVAN_Pos)  |
                ((initStruct->OutputInvBN ? 1 : 0) << PWM_OCR_INVBN_Pos);

    PWMx->PERIOD = initStruct->Period - 1;

    PWMx->CMPA  = initStruct->HdutyA;
    PWMx->CMPA2 = initStruct->HdutyA2;
    PWMx->DZA   = initStruct->DeadzoneA;

    PWMx->CMPB  = initStruct->HdutyB;
    PWMx->CMPB2 = initStruct->HdutyB2;
    PWMx->DZB   = initStruct->DeadzoneB;

    PWMG->RELOADEN = 0x3F;

    PWMx->IF = 0x3F;
    PWMx->IE = ((initStruct->UpOvfIE    ? 1 : 0) << PWM_IE_UPOVF_Pos)  |
               ((initStruct->DownOvfIE  ? 1 : 0) << PWM_IE_DNOVF_Pos)  |
               ((initStruct->UpCmpAIE   ? 1 : 0) << PWM_IE_UPCMPA_Pos) |
               ((initStruct->DownCmpAIE ? 1 : 0) << PWM_IE_DNCMPA_Pos) |
               ((initStruct->UpCmpBIE   ? 1 : 0) << PWM_IE_UPCMPB_Pos) |
               ((initStruct->DownCmpBIE ? 1 : 0) << PWM_IE_DNCMPB_Pos);

    if(initStruct->UpOvfIE || initStruct->DownOvfIE || initStruct->UpCmpAIE ||
       initStruct->DownCmpAIE || initStruct->UpCmpBIE || initStruct->DownCmpBIE)
    {
        switch((uint32_t)PWMx)
        {
        case((uint32_t)PWM0):
            NVIC_EnableIRQ(PWM0_IRQn);
            break;

        case((uint32_t)PWM1):
            NVIC_EnableIRQ(PWM1_IRQn);
            break;

        case((uint32_t)PWM2):
            NVIC_EnableIRQ(PWM2_IRQn);
            break;

        case((uint32_t)PWM3):
            NVIC_EnableIRQ(PWM3_IRQn);
            break;

        case((uint32_t)PWM4):
            NVIC_EnableIRQ(PWM4_IRQn);
            break;
        }
    }
}

/******************************************************************************************************************************************
* : PWM_Start()
* : PWMPWM
*     : uint32_t pwm          PWM0_MSKPWM1_MSKPWM2_MSKPWM3_MSKPWM4_MSKPWM5_MSK 
*     : 
* : 
******************************************************************************************************************************************/
void PWM_Start(uint32_t pwm)
{
    PWMG->START |= pwm;
}

/******************************************************************************************************************************************
* : PWM_Stop()
* : PWMPWM
*     : uint32_t pwm          PWM0_MSKPWM1_MSKPWM2_MSKPWM3_MSKPWM4_MSKPWM5_MSK 
*     : 
* : 
******************************************************************************************************************************************/
void PWM_Stop(uint32_t pwm)
{
    PWMG->START &= ~pwm;
}

/******************************************************************************************************************************************
* : PWM_Restart()
* : PWMPWM
*     : uint32_t pwm          PWM0_MSKPWM1_MSKPWM2_MSKPWM3_MSKPWM4_MSKPWM5_MSK 
*     : 
* : 
******************************************************************************************************************************************/
void PWM_Restart(uint32_t pwm)
{
    PWMG->RESTART = (pwm << PWMG_RESTART_PWM0_Pos);
}

/******************************************************************************************************************************************
* : PWM_ReloadEn()
* :  Reload Enable  PERIODCMPACMPBDZADZB 
*     : uint32_t pwm          PWM0_MSKPWM1_MSKPWM2_MSKPWM3_MSKPWM4_MSKPWM5_MSK 
*     : 
* :  PERIODCMPACMPBDZADZB 
*           PWM_ReloadDis(PWM0_MSK | PWM1_MSK);
*            PERIODCMPACMPBDZADZB 
*           PWM_ReloadEn(PWM0_MSK | PWM1_MSK);
******************************************************************************************************************************************/
void PWM_ReloadEn(uint32_t pwm)
{
    PWMG->RELOADEN |= pwm;
}

/******************************************************************************************************************************************
* : PWM_ReloadDis()
* :  Reload Enable  PERIODCMPACMPBDZADZB 
*     : uint32_t pwm          PWM0_MSKPWM1_MSKPWM2_MSKPWM3_MSKPWM4_MSKPWM5_MSK 
*     : 
* : 
******************************************************************************************************************************************/
void PWM_ReloadDis(uint32_t pwm)
{
    PWMG->RELOADEN &= ~pwm;
}

/******************************************************************************************************************************************
* : PWM_BrkInPolarity()
* : 
*     : uint32_t brk          PWM_BRK0PWM_BRK1PWM_BRK2 
*           uint32_t level          0    1 
*     : 
* : 
******************************************************************************************************************************************/
void PWM_BrkInPolarity(uint32_t brk, uint32_t level)
{
    if(level)
        PWMG->BRKPOL |= brk;
    else
        PWMG->BRKPOL &= ~brk;
}

/******************************************************************************************************************************************
* : PWM_BrkConfig()
* : 
*     : PWM_TypeDef * PWMx        PWMPWM0PWM1PWM2PWM3PWM4
*           uint32_t chn            PWMPWM_CH_APWM_CH_B
*           uint32_t brk            PWM_BRK0PWM_BRK1PWM_BRK2 
*           uint32_t out            PWMxA/PWMxB
*           uint32_t outN           PWMxAN/PWMxBN
*           uint32_t outHold        0    1 
*           uint32_t stpCount       1 
*     : 
* : 
******************************************************************************************************************************************/
void PWM_BrkConfig(PWM_TypeDef * PWMx, uint32_t chn, uint32_t brk, uint32_t out, uint32_t outN, uint32_t outHold, uint32_t stpCount)
{
    if(chn == PWM_CH_A)
    {
        PWMx->BRKIN &= ~(0x7 << PWM_BRKIN_BRK0A_Pos);
        PWMx->BRKIN |=  (brk << PWM_BRKIN_BRK0A_Pos);

        PWMx->BRKCR &= ~(PWM_BRKCR_OUTA_Msk | PWM_BRKCR_OUTAN_Msk | PWM_BRKCR_OFFA_Msk);
        PWMx->BRKCR |= (out      << PWM_BRKCR_OUTA_Pos)  |
                       (outN     << PWM_BRKCR_OUTAN_Pos) |
                       (outHold  << PWM_BRKCR_OFFA_Pos)  |
                       (stpCount << PWM_BRKCR_STPCNT_Pos);
    }
    else
    {
        PWMx->BRKIN &= ~(0x7 << PWM_BRKIN_BRK0B_Pos);
        PWMx->BRKIN |=  (brk << PWM_BRKIN_BRK0B_Pos);

        PWMx->BRKCR &= ~(PWM_BRKCR_OUTB_Msk | PWM_BRKCR_OUTBN_Msk | PWM_BRKCR_OFFB_Msk);
        PWMx->BRKCR |= (out      << PWM_BRKCR_OUTB_Pos)  |
                       (outN     << PWM_BRKCR_OUTBN_Pos) |
                       (outHold  << PWM_BRKCR_OFFB_Pos)  |
                       (stpCount << PWM_BRKCR_STPCNT_Pos);
    }
}

/******************************************************************************************************************************************
* : PWM_OvfTrigger()
* : 
*     : PWM_TypeDef * PWMx        PWMPWM0PWM1PWM2PWM3PWM4
*           uint32_t en_up          
*           uint32_t en_down        
*           uint32_t trig_chn       8PWM_TRG_0PWM_TRG_1...PWM_TRG_7
*     : 
* : 
******************************************************************************************************************************************/
void PWM_OvfTrigger(PWM_TypeDef * PWMx, uint32_t en_up, uint32_t en_down, uint32_t trig_chn)
{
    PWMx->OVFTRG = (en_up    << PWM_OVFTRG_UPEN_Pos) |
                   (en_down  << PWM_OVFTRG_DNEN_Pos) |
                   (trig_chn << PWM_OVFTRG_MUX_Pos);
}

/******************************************************************************************************************************************
* : PWM_CmpTrigger()
* : 
*     : PWM_TypeDef * PWMx        PWMPWM0PWM1PWM2PWM3PWM4
*           uint16_t match          match
*           uint32_t dir            PWM_DIR_UP match   PWM_DIR_DOWN match
*           uint32_t width          0    1 4   2 8    ...   63 252
*           uint32_t trig_chn       8PWM_TRG_0PWM_TRG_1...PWM_TRG_7
*           uint32_t adc_trig_pos    adc_trig_pos/8 adc0--7
*     : 
* : 
******************************************************************************************************************************************/
void PWM_CmpTrigger(PWM_TypeDef * PWMx, uint16_t match, uint32_t dir, uint32_t width, uint32_t trig_chn, uint32_t adc_trig_pos)
{
    PWMx->CMPTRG = (1        << PWM_CMPTRG_EN_Pos)    |
                   (match    << PWM_CMPTRG_CMP_Pos)   |
                   (dir      << PWM_CMPTRG_DIR_Pos)   |
                   (width    << PWM_CMPTRG_WIDTH_Pos) |
                   (trig_chn << PWM_CMPTRG_MUX_Pos);

    PWM0->CMPTRG &= ~PWM_CMPTRG_ATP_Msk;
    PWM0->CMPTRG |= (adc_trig_pos << PWM_CMPTRG_ATP_Pos);
}

/******************************************************************************************************************************************
* : PWM_OutMask()
* : PWM
*     : PWM_TypeDef * PWMx        PWMPWM0PWM1PWM2PWM3PWM4
*           uint32_t chn            PWMPWM_CH_APWM_CH_B
*           uint32_t evt            PWMxY  event PWM_EVT_DISPWM_EVT_0PWM_EVT_1...PWM_EVT_6
*           uint32_t out            PWMxY 
*           uint32_t evt_n          PWMxYN event PWM_EVT_DISPWM_EVT_0PWM_EVT_1...PWM_EVT_6
*           uint32_t out_n          PWMxYN
*     : 
* : 
******************************************************************************************************************************************/
void PWM_OutMask(PWM_TypeDef * PWMx, uint32_t chn, uint32_t evt, uint32_t out, uint32_t evt_n, uint32_t out_n)
{
    if(chn == PWM_CH_A)
    {
        PWMx->EVMUX &= ~(PWM_EVMUX_MASKA_Msk | PWM_EVMUX_MASKAN_Msk);
        PWMx->EVMUX |= (evt   << PWM_EVMUX_MASKA_Pos) |
                       (evt_n << PWM_EVMUX_MASKAN_Pos);

        PWMx->EVMSK &= ~(PWM_EVMSK_OUTA_Msk | PWM_EVMSK_OUTAN_Msk);
        PWMx->EVMSK |= (out   << PWM_EVMSK_OUTA_Pos)  |
                       (out_n << PWM_EVMSK_OUTAN_Pos) |
                       (1     << PWM_EVMSK_IMME_Pos);
    }
    else
    {
        PWMx->EVMUX &= ~(PWM_EVMUX_MASKB_Msk | PWM_EVMUX_MASKBN_Msk);
        PWMx->EVMUX |= (evt   << PWM_EVMUX_MASKB_Pos) |
                       (evt_n << PWM_EVMUX_MASKBN_Pos);

        PWMx->EVMSK &= ~(PWM_EVMSK_OUTB_Msk | PWM_EVMSK_OUTBN_Msk);
        PWMx->EVMSK |= (out   << PWM_EVMSK_OUTB_Pos)  |
                       (out_n << PWM_EVMSK_OUTBN_Pos) |
                       (1     << PWM_EVMSK_IMME_Pos);
    }
}

/******************************************************************************************************************************************
* : PWM_SetPeriod()
* : 
*     : PWM_TypeDef * PWMx        PWMPWM0PWM1PWM2PWM3PWM4
*           uint16_t period         
*     : 
* : 
******************************************************************************************************************************************/
void PWM_SetPeriod(PWM_TypeDef * PWMx, uint16_t period)
{
    PWMx->PERIOD = period - 1;
}

/******************************************************************************************************************************************
* : PWM_GetPeriod()
* : 
*     : PWM_TypeDef * PWMx        PWMPWM0PWM1PWM2PWM3PWM4
*     : uint16_t              
* : 
******************************************************************************************************************************************/
uint16_t PWM_GetPeriod(PWM_TypeDef * PWMx)
{
    return PWMx->PERIOD + 1;
}

/******************************************************************************************************************************************
* : PWM_SetHDuty()
* : 
*     : PWM_TypeDef * PWMx        PWMPWM0PWM1PWM2PWM3PWM4
*           uint32_t chn            PWMPWM_CH_APWM_CH_B
*           uint16_t hduty          
*     : 
* : 
******************************************************************************************************************************************/
void PWM_SetHDuty(PWM_TypeDef * PWMx, uint32_t chn, uint16_t hduty)
{
    if(chn == PWM_CH_A)
        PWMx->CMPA = hduty;
    else
        PWMx->CMPB = hduty;
}

/******************************************************************************************************************************************
* : PWM_GetHDuty()
* : 
*     : PWM_TypeDef * PWMx        PWMPWM0PWM1PWM2PWM3PWM4
*           uint32_t chn            PWMPWM_CH_APWM_CH_B
*     : uint16_t              
* : 
******************************************************************************************************************************************/
uint16_t PWM_GetHDuty(PWM_TypeDef * PWMx, uint32_t chn)
{
    if(chn == PWM_CH_A)
        return PWMx->CMPA;
    else
        return PWMx->CMPB;
}

/******************************************************************************************************************************************
* : PWM_SetHDuty2()
* : 
*     : PWM_TypeDef * PWMx        PWMPWM0PWM1PWM2PWM3PWM4
*           uint32_t chn            PWMPWM_CH_APWM_CH_B
*           uint16_t hduty          
*           uint16_t hduty2         
*     : 
* : 
******************************************************************************************************************************************/
void PWM_SetHDuty2(PWM_TypeDef * PWMx, uint32_t chn, uint16_t hduty, uint16_t hduty2)
{
    if(chn == PWM_CH_A)
    {
        PWMx->CMPA  = hduty;
        PWMx->CMPA2 = hduty2;
    }
    else
    {
        PWMx->CMPB  = hduty;
        PWMx->CMPB2 = hduty2;
    }
}

/******************************************************************************************************************************************
* : PWM_GetHDuty2()
* : 
*     : PWM_TypeDef * PWMx        PWMPWM0PWM1PWM2PWM3PWM4
*           uint32_t chn            PWMPWM_CH_APWM_CH_B
*     : uint16_t *hduty           
*           uint16_t *hduty2        
* : 
******************************************************************************************************************************************/
void PWM_GetHDuty2(PWM_TypeDef * PWMx, uint32_t chn, uint16_t *hduty, uint16_t *hduty2)
{
    if(chn == PWM_CH_A)
    {
        *hduty  = PWMx->CMPA;
        *hduty2 = PWMx->CMPA2;
    }
    else
    {
        *hduty  = PWMx->CMPB;
        *hduty2 = PWMx->CMPB2;
    }
}

/******************************************************************************************************************************************
* : PWM_SetDeadzone()
* : 
*     : PWM_TypeDef * PWMx        PWMPWM0PWM1PWM2PWM3PWM4
*           uint32_t chn            PWMPWM_CH_APWM_CH_B
*           uint16_t deadzone       0--1023
*     : 
* : 
******************************************************************************************************************************************/
void PWM_SetDeadzone(PWM_TypeDef * PWMx, uint32_t chn, uint16_t deadzone)
{
    if(chn == PWM_CH_A)
        PWMx->DZA = deadzone;
    else
        PWMx->DZB = deadzone;
}

/******************************************************************************************************************************************
* : PWM_GetDeadzone()
* : 
*     : PWM_TypeDef * PWMx        PWMPWM0PWM1PWM2PWM3PWM4
*           uint32_t chn            PWMPWM_CH_APWM_CH_B
*     : uint16_t              
* : 
******************************************************************************************************************************************/
uint16_t PWM_GetDeadzone(PWM_TypeDef * PWMx, uint32_t chn)
{
    if(chn == PWM_CH_A)
        return PWMx->DZA;
    else
        return PWMx->DZB;
}


/******************************************************************************************************************************************
* : PWM_IntEn()
* : 
*     : PWM_TypeDef * PWMx        PWMPWM0PWM1PWM2PWM3PWM4
*           uint32_t it             interrupt typePWM_IT_OVF_UPPWM_IT_OVF_DOWNPWM_IT_CMPA_UPPWM_IT_CMPB_UP
*                                   PWM_IT_CMPA_DOWNPWM_IT_CMPB_DOWN 
*     : 
* : 
******************************************************************************************************************************************/
void PWM_IntEn(PWM_TypeDef * PWMx, uint32_t it)
{
    PWMx->IE |= it;
}

/******************************************************************************************************************************************
* : PWM_IntDis()
* : 
*     : PWM_TypeDef * PWMx        PWMPWM0PWM1PWM2PWM3PWM4
*           uint32_t it             interrupt typePWM_IT_OVF_UPPWM_IT_OVF_DOWNPWM_IT_CMPA_UPPWM_IT_CMPB_UP
*                                   PWM_IT_CMPA_DOWNPWM_IT_CMPB_DOWN 
*     : 
* : 
******************************************************************************************************************************************/
void PWM_IntDis(PWM_TypeDef * PWMx, uint32_t it)
{
    PWMx->IE &= ~it;
}

/******************************************************************************************************************************************
* : PWM_IntClr()
* :
*     : PWM_TypeDef * PWMx        PWMPWM0PWM1PWM2PWM3PWM4
*           uint32_t it             interrupt typePWM_IT_OVF_UPPWM_IT_OVF_DOWNPWM_IT_CMPA_UPPWM_IT_CMPB_UP
*                                   PWM_IT_CMPA_DOWNPWM_IT_CMPB_DOWN 
*     : 
* : 
******************************************************************************************************************************************/
void PWM_IntClr(PWM_TypeDef * PWMx, uint32_t it)
{
    PWMx->IF = it;
}

/******************************************************************************************************************************************
* : PWM_IntStat()
* : 
*     : PWM_TypeDef * PWMx        PWMPWM0PWM1PWM2PWM3PWM4
*           uint32_t it             interrupt typePWM_IT_OVF_UPPWM_IT_OVF_DOWNPWM_IT_CMPA_UPPWM_IT_CMPB_UP
*                                   PWM_IT_CMPA_DOWNPWM_IT_CMPB_DOWN 
*     : uint32_t              0    0 
* : 
******************************************************************************************************************************************/
uint32_t PWM_IntStat(PWM_TypeDef * PWMx, uint32_t it)
{
    return (PWMx->IF & it);
}

/******************************************************************************************************************************************
* : PWM_BrkIntEn()
* : 
*     : uint32_t brkit            brake interrupt type PWM_BRKIT_BRK0PWM_BRKIT_BRK0PWM_BRKIT_BRK0 
*     : 
* : 
******************************************************************************************************************************************/
void PWM_BrkIntEn(uint32_t brkit)
{
    PWMG->BRKIE |= brkit;
}

/******************************************************************************************************************************************
* : PWM_BrkIntDis()
* : 
*     : uint32_t brkit            brake interrupt type PWM_BRKIT_BRK0PWM_BRKIT_BRK0PWM_BRKIT_BRK0 
*     : 
* : 
******************************************************************************************************************************************/
void PWM_BrkIntDis(uint32_t brkit)
{
    PWMG->BRKIE &= ~brkit;
}

/******************************************************************************************************************************************
* : PWM_BrkIntClr()
* :
*     : uint32_t brkit            brake interrupt type PWM_BRKIT_BRK0PWM_BRKIT_BRK0PWM_BRKIT_BRK0 
*     : 
* : 
******************************************************************************************************************************************/
void PWM_BrkIntClr(uint32_t brkit)
{
    PWMG->BRKIF = brkit;
}

/******************************************************************************************************************************************
* : PWM_BrkIntStat()
* : 
*     : uint32_t brkit            brake interrupt type PWM_BRKIT_BRK0PWM_BRKIT_BRK0PWM_BRKIT_BRK0 
*     : uint32_t              0    0 
* : 
******************************************************************************************************************************************/
uint32_t PWM_BrkIntStat(uint32_t brkit)
{
    return (PWMG->BRKIF & brkit);
}
