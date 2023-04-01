/**
  ****************************************************************************************************
  * @file    fm33lc0xx_fl_aes.c
  * @author  FMSH Application Team
  * @brief   Src file of AES FL Module
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

/** @addtogroup AES
  * @{
  */

#ifdef FL_AES_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup AES_FL_Private_Macros
  * @{
  */

#define         IS_FL_AES_INSTANCE(INSTANCE)                (((INSTANCE) == AES))

#define         IS_FL_AES_KEYLENGTH(__VALUE__)               (((__VALUE__) == FL_AES_KEY_LENGTH_128B)||\
                                                             ((__VALUE__) == FL_AES_KEY_LENGTH_192B)||\
                                                             ((__VALUE__) == FL_AES_KEY_LENGTH_256B))

#define         IS_FL_AES_CIPHERMODE(__VALUE__)             (((__VALUE__) == FL_AES_CIPHER_ECB)||\
                                                             ((__VALUE__) == FL_AES_CIPHER_CBC)||\
                                                             ((__VALUE__) == FL_AES_CIPHER_CTR)||\
                                                             ((__VALUE__) == FL_AES_CIPHER_MULTH))

#define         IS_FL_AES_OPERATIONMODE(__VALUE__)          (((__VALUE__) == FL_AES_OPERATION_MODE_ENCRYPTION)||\
                                                             ((__VALUE__) == FL_AES_OPERATION_MODE_KEYDERIVATION)||\
                                                             ((__VALUE__) == FL_AES_OPERATION_MODE_DECRYPTION)||\
                                                             ((__VALUE__) == FL_AES_OPERATION_MODE_KEYDERIVATION_DECRYPTION))

#define         IS_FL_AES_DATATYPE(__VALUE__)               (((__VALUE__) == FL_AES_DATA_TYPE_32B)||\
                                                             ((__VALUE__) == FL_AES_DATA_TYPE_16B)||\
                                                             ((__VALUE__) == FL_AES_DATA_TYPE_8B)||\
                                                             ((__VALUE__) == FL_AES_DATA_TYPE_1B))
/**
  * @}
  */

/** @addtogroup AES_FL_EF_Init
  * @{
  */

/**
  * @brief  AES
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_AES_DeInit(void)
{
    /*  */
    FL_RCC_EnablePeripheralReset();
    /* AES */
    FL_RCC_EnableResetAPB2Peripheral(FL_RCC_RSTAPB_AES);
    FL_RCC_DisableResetAPB2Peripheral(FL_RCC_RSTAPB_AES);
    /*  */
    FL_RCC_DisableGroup2BusClock(FL_RCC_GROUP2_BUSCLK_AES);
    /*  */
    FL_RCC_DisablePeripheralReset();
    return FL_PASS;
}

/**
  * @brief   AES_InitStructer .
  *
  * @param  AESx 
  * @param  AES_InitStructer  @ref FL_AES_InitTypeDef 
  *
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_AES_Init(AES_Type *AESx, FL_AES_InitTypeDef *AES_InitStructer)
{
    /*  */
    assert_param(IS_FL_AES_INSTANCE(AESx));
    assert_param(IS_FL_AES_KEYLENGTH(AES_InitStructer->keyLength));
    assert_param(IS_FL_AES_CIPHERMODE(AES_InitStructer->cipherMode));
    assert_param(IS_FL_AES_OPERATIONMODE(AES_InitStructer->operationMode));
    assert_param(IS_FL_AES_DATATYPE(AES_InitStructer->dataType));
    FL_AES_Disable(AES);
    if(FL_AES_IsEnabled(AESx) == 0)
    {
        /*  */
        FL_RCC_EnableGroup2BusClock(FL_RCC_GROUP2_BUSCLK_AES);
        /* key */
        FL_AES_SetKeySize(AESx, AES_InitStructer->keyLength);
        /*  */
        FL_AES_SetCipherMode(AESx, AES_InitStructer->cipherMode);
        /*  */
        FL_AES_SetOperationMode(AESx, AES_InitStructer->operationMode);
        /*  */
        FL_AES_SetDataType(AESx, AES_InitStructer->dataType);
    }
    else
    {
        return FL_FAIL;
    }
    return FL_PASS;
}

/**
  * @brief   @ref FL_AES_InitTypeDef 
  * @param  AES_InitStructer  @ref FL_AES_InitTypeDef 
  *
  * @retval None
  */
void FL_AES_StructInit(FL_AES_InitTypeDef *AES_InitStructer)
{
    AES_InitStructer->keyLength      = FL_AES_KEY_LENGTH_128B;
    AES_InitStructer->cipherMode     = FL_AES_CIPHER_ECB;
    AES_InitStructer->operationMode  = FL_AES_OPERATION_MODE_ENCRYPTION;
    AES_InitStructer->dataType       = FL_AES_DATA_TYPE_32B;
}
/**
  * @}
  */

#endif /* FL_AES_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
