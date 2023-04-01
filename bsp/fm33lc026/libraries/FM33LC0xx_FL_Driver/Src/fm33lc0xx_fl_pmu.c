/**
  ****************************************************************************************************
  * @file    fm33lc0xx_fl_pmu.c
  * @author  FMSH Application Team
  * @brief   Src file of PMU FL Module
  ****************************************************************************************************
  * @attention
  *
  * Copyright (c) [2021] [Fudan Microelectronics]
  * THIS SOFTWARE is licensed under Mulan PSL v2.
  * You can use this software according to the terms and conditions of the Mulan PSL v2.
  * You may obtain a copy of Mulan PSL v2 at:
  *          http://license.coscl.org.cn/MulanPSL2
  * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
  * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
  * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
  * See the Mulan PSL v2 for more details.
  *
  ****************************************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "fm33lc0xx_fl.h"

/** @addtogroup FM33LC0XX_FL_Driver
  * @{
  */

/** @addtogroup PMU
  * @{
  */

#ifdef FL_PMU_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup PMU_FL_Private_Macros
  * @{
  */

#define         IS_FL_PMU_INSTANCE(INSTANCE)                (((INSTANCE) == PMU))

#define         IS_FL_PMU_MODE(__VALUE__)                   (((__VALUE__) == FL_PMU_POWER_MODE_ACTIVE_OR_LPACTIVE)||\
                                                             ((__VALUE__) == FL_PMU_POWER_MODE_LPRUN_ONLY)||\
                                                             ((__VALUE__) == FL_PMU_POWER_MODE_SLEEP_OR_DEEPSLEEP))

#define         IS_FL_PMU_COREVOLTAGESCALING(__VALUE__)     (((__VALUE__) == FL_DISABLE)||\
                                                             ((__VALUE__) == FL_ENABLE))

#define         IS_FL_PMU_DEEPSLEEP(__VALUE__)              (((__VALUE__) == FL_PMU_SLEEP_MODE_DEEP)||\
                                                             ((__VALUE__) == FL_PMU_SLEEP_MODE_NORMAL))

#define         IS_FL_PMU_WAKEUPFREQUENCY(__VALUE__)        (((__VALUE__) == FL_PMU_RCHF_WAKEUP_FREQ_8MHZ)||\
                                                             ((__VALUE__) == FL_PMU_RCHF_WAKEUP_FREQ_16MHZ)||\
                                                             ((__VALUE__) == FL_PMU_RCHF_WAKEUP_FREQ_24MHZ))

#define         IS_FL_PMU_LDOLOWMODE(__VALUE__)             (((__VALUE__) == FL_PMU_LDO_LPM_DISABLE)||\
                                                             ((__VALUE__) == FL_PMU_LDO_LPM_ENABLE))

#define         IS_FL_PMU_WAKEUPDELAY(__VALUE__)            (((__VALUE__) == FL_PMU_WAKEUP_DELAY_0US)||\
                                                             ((__VALUE__) == FL_PMU_WAKEUP_DELAY_2US)||\
                                                             ((__VALUE__) == FL_PMU_WAKEUP_DELAY_4US)||\
                                                             ((__VALUE__) == FL_PMU_WAKEUP_DELAY_8US))

/**
  *@}
  */

/** @addtogroup PMU_FL_EF_Init
  * @{
  */
/**
  * @brief  PMU
  *
  * @param  
  *
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_PMU_Sleep_DeInit(PMU_Type *PMUx)
{
    FL_ErrorStatus status = FL_FAIL;
    /*  */
    assert_param(IS_FL_PMU_INSTANCE(PMUx));
    PMUx->CR   = 0x00060000U;
    PMUx->WKTR = 0xC0000001U;
    PMUx->IER  = 0x00000000U;
    status = FL_PASS;
    return status;
}


/**
  * @brief  LPM_InitStructPMU
  *
  * @note    @ref fm33lc0xx_fl_pmu.h
  *         BOR
  * @param  PMUx  
  * @param  LPM_InitStruct  @ref LL_PMU_SleepInitTypeDef LPUART
  *
  * @retval ErrorStatus
  *         -FL_FAIL 
  *         -FL_PASS LPUART
  */
FL_ErrorStatus FL_PMU_Sleep_Init(PMU_Type *PMUx, FL_PMU_SleepInitTypeDef *LPM_InitStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    /*  */
    assert_param(IS_FL_PMU_INSTANCE(PMUx));
    assert_param(IS_FL_PMU_LDOLOWMODE(LPM_InitStruct->LDOLowPowerMode));
    assert_param(IS_FL_PMU_COREVOLTAGESCALING(LPM_InitStruct->coreVoltageScaling));
    assert_param(IS_FL_PMU_DEEPSLEEP(LPM_InitStruct->deepSleep));
    assert_param(IS_FL_PMU_WAKEUPFREQUENCY(LPM_InitStruct->wakeupFrequency));
    assert_param(IS_FL_PMU_WAKEUPDELAY(LPM_InitStruct->wakeupDelay));
    /*  */
    FL_PMU_SetWakeupDelay(PMUx, LPM_InitStruct->wakeupDelay);
    /* RCHF */
    FL_PMU_SetRCHFWakeupFrequency(PMUx, LPM_InitStruct->wakeupFrequency);
    /*  */
    if(LPM_InitStruct->coreVoltageScaling == FL_ENABLE)
    {
        FL_PMU_EnableCoreVoltageScaling(PMUx);
    }
    else
    {
        FL_PMU_DisableCoreVoltageScaling(PMUx);
    }
    /* M0,0*/
    SCB->SCR = 0;
    /*  */
    FL_PMU_SetSleepMode(PMUx, LPM_InitStruct->deepSleep);
    status = FL_PASS;
    return status;
}

/**
  * @brief  LPM_InitStruct 
  * @param  LPM_InitStruct  @ref FL_PMU_SleepInitTypeDef structure
  *         
  * @retval None
  */
void FL_PMU_StructInit(FL_PMU_SleepInitTypeDef *LPM_InitStruct)
{
    LPM_InitStruct->deepSleep           = FL_PMU_SLEEP_MODE_NORMAL;
    LPM_InitStruct->LDOLowPowerMode     = FL_PMU_LDO_LPM_DISABLE;
    LPM_InitStruct->wakeupFrequency     = FL_PMU_RCHF_WAKEUP_FREQ_8MHZ;
    LPM_InitStruct->wakeupDelay         = FL_PMU_WAKEUP_DELAY_2US;
    LPM_InitStruct->coreVoltageScaling  = FL_DISABLE;
}

/**
  * @}
  */

#endif /* FL_PMU_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
