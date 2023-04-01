/*****************************************************************************
 * Copyright (c) 2019, Nations Technologies Inc.
 *
 * All rights reserved.
 * ****************************************************************************
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Nations' name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY NATIONS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL NATIONS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ****************************************************************************/

/**
 * @brief .
 * :(TIMER->API->->)
 * @file n32xx_tsc_alg_api.h
 * @author Nations
 * @version v1.0.1
 * @copyright Copyright (c) 2019, Nations Technologies Inc. All rights reserved.
 */
#ifndef __N32XX_TSC_ALG_API__
#define __N32XX_TSC_ALG_API__

#ifdef __cplusplus
extern "C" {
#endif // defined __cplusplus

#define TSC_ALG_VERSION_NUMBER "Ver1.0.4" //

#define TSC_ALG_HANDLER_STOP2_DATA_SIZE (144)  //STOP2TSC
#define TSC_ALG_HANDLER_PERIOD_PER_CHN  (400)  //
#define TSC_ALG_WAKEUP_TIMES            (1000) //TSC
#define TSC_ALG_DEBUG_BUF_SIZE          (260)  //BUF
#define TSC_ALG_REF_SIZE_PER_CHN        (430)  //tsc_alg_need_sramsize()

/**
 * @brief 
 */
typedef enum tsc_alg_type_e
{
    TSC_ALG_BUTTON_TYPE = 0, ///< tsc application of simple button
    TSC_ALG_TYPE_MAX         ///<
} tsc_alg_type;

/**
 * @brief 
 */
typedef enum tsc_press_key_event_e
{
    TSC_PRESS_KEY_NORMAL = 0, //
    TSC_PRESS_KEY_MAX         ///<
} tsc_press_key_event;

/**
 * @brief 
 */
typedef enum tsc_ret_code_e
{
    TSC_SUCCESS = 0,               ///< 
    TSC_NOT_INIT_ERR,              ///< 
    TSC_NOT_REG_CHN_ERR,           ///< 
    TSC_NOT_ACCORD_LIB_ERR,        ///< 
    TSC_POINTER_NULL_ERR,          ///< 
    TSC_PARAM_ZERO_ERR,            ///< 
    TSC_REPEAT_REG_ERR,            ///< 
    TSC_CHN_NUM_ERR,               ///< 
    TSC_REG_CHANNEL_ENOUGH_ERR,    ///< 
    TSC_REG_TIMX_ERR,              ///< Timer
    TSC_REG_DMA_ERR,               ///< DMA
    TSC_SOURCE_NOT_ENOUGH_ERR,     ///< 
    TSC_NOT_SUPPORT_ERR,           ///< 
    TSC_LEVEL_CFG_ERR,             ///< 
    TSC_AUTO_CALIB_TIMER_ERR,      ///< 2.
    TSC_DISTURB_ERR,               ///< .
    TSC_CHN_RAM_NOT_ENOUGH_ERR,    ///< TSCRAMNULL
    TSC_STOP2_NULL_OR_INVALID_ERR, ///< Stop2DataNULL16K retention
    TSC_DEBUG_BUF_ENOUGH_ERR       ///< 
} tsc_ret_code;

/**
 * @brief 
 * :
 * :
 */
typedef enum tsc_hld_lev_e
{
    TSC_HOLD_LEV1  = 1,  // HOLD1(5ms)
    TSC_HOLD_LEV2  = 2,  // HOLD2(7ms)
    TSC_HOLD_LEV3  = 3,  // HOLD3(11ms)
    TSC_HOLD_LEV4  = 4,  // HOLD4(17ms)
    TSC_HOLD_LEV5  = 5,  // HOLD5(25ms)
    TSC_HOLD_LEV6  = 6,  // HOLD6(35ms)
    TSC_HOLD_LEV7  = 7,  // HOLD7(47ms)
    TSC_HOLD_LEV8  = 8,  // HOLD8(61ms)
    TSC_HOLD_LEV9  = 9,  // HOLD9(77ms)
    TSC_HOLD_LEV10 = 10, // HOLD10(95ms)
    TSC_HOLD_LEV11 = 11, // HOLD11(115ms)
    TSC_HOLD_LEV12 = 12, // HOLD12(137ms)
    TSC_HOLD_LEV13 = 13, // HOLD13(161ms)
    TSC_HOLD_LEV14 = 14, // HOLD14(187ms)
    TSC_HOLD_LEV15 = 15, // HOLD15(215ms)
    TSC_HOLD_LEV16 = 16, // HOLD16(245ms)
    TSC_HOLD_LEV17 = 17, // HOLD17(277ms)
    TSC_HOLD_LEV18 = 18, // HOLD18(311ms)
    TSC_HOLD_LEV19 = 19, // HOLD19(347ms)
    TSC_HOLD_LEV20 = 20, // HOLD20(385ms)
    TSC_HOLD_MAX         ///< 
} tsc_hld_lev;

/**
 * @brief 
 * 
 * deltaTSC
 * delta
 * LEV15
 */
typedef enum tsc_delta_limit_lev_e
{
    TSC_DELTA_LIMIT_LEV1  = 1,  //
    TSC_DELTA_LIMIT_LEV2  = 2,  //
    TSC_DELTA_LIMIT_LEV3  = 3,  //
    TSC_DELTA_LIMIT_LEV4  = 4,  //
    TSC_DELTA_LIMIT_LEV5  = 5,  //
    TSC_DELTA_LIMIT_LEV6  = 6,  //
    TSC_DELTA_LIMIT_LEV7  = 7,  //
    TSC_DELTA_LIMIT_LEV8  = 8,  //
    TSC_DELTA_LIMIT_LEV9  = 9,  //
    TSC_DELTA_LIMIT_LEV10 = 10, //
    TSC_DELTA_LIMIT_LEV11 = 11, //
    TSC_DELTA_LIMIT_LEV12 = 12, //
    TSC_DELTA_LIMIT_LEV13 = 13, //
    TSC_DELTA_LIMIT_LEV14 = 14, //
    TSC_DELTA_LIMIT_LEV15 = 15, //
    TSC_DELTA_LIMIT_LEV16 = 16, //
    TSC_DELTA_LIMIT_LEV17 = 17, //
    TSC_DELTA_LIMIT_LEV18 = 18, //
    TSC_DELTA_LIMIT_LEV19 = 19, //
    TSC_DELTA_LIMIT_LEV20 = 20, //
    TSC_DELTA_LIMIT_MAX         ///< 
} tsc_delta_limit_lev;

/**
 * @brief 
 * ,.
 */
typedef enum tsc_resist_disturb_lev_e
{
    TSC_RESIST_DIS_LEV0 = 0, //PCBA&
    TSC_RESIST_DIS_LEV1 = 1, //
    TSC_RESIST_DIS_LEV2 = 2, //
    TSC_RESIST_DIS_MAX       ///< 
} tsc_resist_disturb_lev;

/**
 * @brief TSC
 */
typedef struct TSC_AlgInitThreValue_t
{
    uint16_t hold_level;     /*  */
    uint16_t rate_of_change; /* (70,77(77-70)/70 = 0.1%10(:8%)5,%5 */
    uint32_t chn;            /*  */
} TSC_AlgInitThreValue;

/**
 * @brief TSC
 */
typedef struct TSC_AlgInitTypeDef_t
{
    TIM_Module* TIMx;                      /* TIMER(TIMER2) */
    DMA_ChannelType* DMAyChx;              /* DMA(DMA1_CH5) */
    uint32_t DMARemapEnable;               /* DMA REMAP(DMA1REMAP1) */
    TSC_AlgInitThreValue* pTScChannelList; /* 1(,TSC) */
    uint32_t AutoCalibrateTimer;           /* (),1000ms,65535ms2 */
    uint32_t ResistDisturbLev;             /* (tsc_resist_disturb_lev),. */
    uint8_t* pTscSramAddr;                 /* TSCRAM*/
    uint32_t TscSramSize;                  /* TSCRAM.(bytes) */
    uint16_t* LogBuf;                      /* buf,0 */
    uint16_t LogBufSize;                   /* u16 * 256.(bytes) */
    uint8_t* Stop2Data;                    /* STOP2TSCBUF */
    uint16_t Stop2DataSize;                /* STOP2TSCBUF(bytes) */
} TSC_AlgInitTypeDef;

/**
 * @brief (TIMER)
 * @TIMERDEMO.
 * @param void
 * @return void
 */
void tsc_alg_analyze_handler(void);

/**
 * @brief 
 * @param uint32_t delta_limit_level tsc_delta_limit_lev
 * @uint32_t hse_or_hsi 0:HSI,  1:HSE;
 * @return
 * - `TSC_SUCCESS 
 * - 
 * - STOP2
 */
int32_t tsc_alg_set_powerdown_calibrate(tsc_delta_limit_lev delta_limit_level, uint32_t hse_or_hsi);

/**
 * @brief ,
 * @param void
 * @return 0:1:
 */
int32_t tsc_alg_wakeup_disturb_check(uint32_t* wakeup_src);

/**
 * @brief 
 * @param void
 * @return void
 */
char* tsc_alg_get_version(void);

/**
 * @brief ,1ms
 * @param void
 * @return void
 */
void tsc_alg_tick_count(void);

/**
 * @brief TSCSRAM
 * uint32_t      chn_totals; // TSC
 * @return
 * - 0:     
 * - 0:  
 */
uint32_t tsc_alg_need_sramsize(uint32_t chn_totals);

/**
 * @brief 
 * @param tsc_init_parameter *ptsc_init_parameter .
 * @param void
 * @return
 * - `TSC_SUCCESS 
 * - 
 */
int32_t tsc_alg_init(TSC_AlgInitTypeDef* TSC_AlgInitStruct);

/**
 * @brief 
 * @param void
 * @return
 * - `TSC_SUCCESS 
 * - 
 */
int32_t tsc_alg_start(void);

/**
 * @brief TSC()
 * @param uint32_t TScChannelList 0
 * @return
 * - `TSC_SUCCESS 
 * - 
 * - STOP2
 */
int32_t tsc_alg_set_powerdown(uint32_t TscChannelList);

////////////////////////////////////////////////////////////

/**************************
 * @brief 
 * @param tsc_touch_type type ()
 * @param uint32_t event 0:
 * @param uint32_t chn 
 * @param uint32_t value 10
 * @return
 * - `TSC_SUCCESS 
 * - 
 * :
 ********************************************************/
int32_t tsc_alg_isr_callback(tsc_alg_type type, uint32_t event, uint32_t chn, uint32_t value);

/**
 * @brief PCPC
 * @param uint32_t chn 
 * @return uint8_t data 
 */
void tsc_alg_debug_output(uint32_t chn, uint8_t data);

#ifdef __cplusplus
}
#endif // defined __cplusplus

#endif //__N32XX_TSC_ALG_API__
