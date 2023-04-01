/********************************** (C) COPYRIGHT *******************************
* File Name          : CH57x_timer3.c
* Author             : WCH
* Version            : V1.0
* Date               : 2018/12/15
* Description
*******************************************************************************/

#include "CH57x_common.h"


/*******************************************************************************
* Function Name  : TMR3_TimerInit
* Description    : 
* Input          : t: Tsys,  67108864

* Return         : None
*******************************************************************************/
void TMR3_TimerInit( UINT32 t )
{
    R32_TMR3_CNT_END = t;
    R8_TMR3_CTRL_MOD = RB_TMR_ALL_CLEAR;
    R8_TMR3_CTRL_MOD = RB_TMR_COUNT_EN;
}

/*******************************************************************************
* Function Name  : TMR3_EXTSingleCounterInit
* Description    : 
* Input          : c: ,  67108864
* Return         : None
*******************************************************************************/
void TMR3_EXTSingleCounterInit( UINT32 c )
{
    R32_TMR3_CNT_END = c;
    R8_TMR3_CTRL_MOD = RB_TMR_ALL_CLEAR;
    R8_TMR3_CTRL_MOD = RB_TMR_CAP_COUNT|RB_TMR_MODE_IN|RB_TMR_COUNT_EN;
}

/*******************************************************************************
* Function Name  : TMR3_CountInit
* Description    : 
* Input          : cap: 
                    CAP_NULL - 
                    Edge_To_Edge - 
                    FallEdge_To_FallEdge - 
                    RiseEdge_To_RiseEdge - 
* Return         : None
*******************************************************************************/
void TMR3_CountInit( CapModeTypeDef cap )
{
    R8_TMR3_CTRL_MOD = RB_TMR_ALL_CLEAR;
    R8_TMR3_CTRL_MOD = RB_TMR_COUNT_EN      \
                      |RB_TMR_CAP_COUNT     \
                      |RB_TMR_MODE_IN       \
                      |(cap<<6);
}

/*******************************************************************************
* Function Name  : TMR3_PWMInit
* Description    : PWM 
* Input          : pr:  select wave polar
                    refer to PWMX_PolarTypeDef
                   ts:  set pwm repeat times
                    refer to PWM_RepeatTsTypeDef
* Return         : None
*******************************************************************************/
void TMR3_PWMInit( PWMX_PolarTypeDef pr, PWM_RepeatTsTypeDef ts )
{
//    R8_TMR3_CTRL_MOD = RB_TMR_ALL_CLEAR;
    R8_TMR3_CTRL_MOD = RB_TMR_COUNT_EN      \
                        |RB_TMR_OUT_EN      \
                        |(pr<<4)            \
                        |(ts<<6);
}


/*******************************************************************************
* Function Name  : TMR3_CapInit
* Description    : 
* Input          : cap:  select capture mode
                    refer to CapModeTypeDef
* Return         : None
*******************************************************************************/
void TMR3_CapInit( CapModeTypeDef cap )
{
        R8_TMR3_CTRL_MOD = RB_TMR_ALL_CLEAR;
        R8_TMR3_CTRL_MOD = RB_TMR_COUNT_EN      \
                            |RB_TMR_MODE_IN     \
                            |(cap<<6);
}






