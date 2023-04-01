/********************************** (C) COPYRIGHT *******************************
* File Name          : CH57x_pwm.c
* Author             : WCH
* Version            : V1.0
* Date               : 2018/12/15
* Description
*******************************************************************************/

#include "CH57x_common.h"


/*******************************************************************************
* Function Name  : PWMX_CycleCfg
* Description    : PWM4-PWM11
* Input          : cyc:
                    refer to PWMX_CycleTypeDef
* Return         : None
*******************************************************************************/
void PWMX_CycleCfg( PWMX_CycleTypeDef cyc )
{
    switch( cyc )
    {
        case PWMX_Cycle_256:
            R8_PWM_CONFIG = R8_PWM_CONFIG & 0xf0;
            break;

        case PWMX_Cycle_255:
            R8_PWM_CONFIG = (R8_PWM_CONFIG & 0xf0) | 0x01;
            break;

        case PWMX_Cycle_128:
            R8_PWM_CONFIG = (R8_PWM_CONFIG & 0xf0) | (1<<2);
            break;

        case PWMX_Cycle_127:
            R8_PWM_CONFIG = (R8_PWM_CONFIG & 0xf0) | (1<<2) | 0x01;
            break;

        case PWMX_Cycle_64:
            R8_PWM_CONFIG = (R8_PWM_CONFIG & 0xf0) | (2<<2);
            break;

        case PWMX_Cycle_63:
            R8_PWM_CONFIG = (R8_PWM_CONFIG & 0xf0) | (2<<2) | 0x01;
            break;

        case PWMX_Cycle_32:
            R8_PWM_CONFIG = (R8_PWM_CONFIG & 0xf0) | (3<<2);
            break;

        case PWMX_Cycle_31:
            R8_PWM_CONFIG = (R8_PWM_CONFIG & 0xf0) | (3<<2) | 0x01;
            break;

        default :
            break;
    }
}

/*******************************************************************************
* Function Name  : PWMX_ACTOUT
* Description    : PWM4-PWM11
* Input          : ch:  select channel of pwm
                    refer to channel of PWM define
                   da:  effective pulse width
                   pr:  select wave polar
                    refer to PWMX_PolarTypeDef
                   s :  control pwmx function
                    ENABLE  - PWM
                    DISABLE - PWM
* Return         : None
*******************************************************************************/
void PWMX_ACTOUT( UINT8 ch, UINT8 da, PWMX_PolarTypeDef pr, UINT8 s)
{
    UINT8 i;

    if(s == DISABLE)    R8_PWM_OUT_EN &= ~(ch);
    else
    {
        (pr)?(R8_PWM_POLAR|=(ch)):(R8_PWM_POLAR&=~(ch));
        for(i=0; i<8; i++)
        {
            if((ch>>i)&1)       *((PUINT8V)((&R8_PWM4_DATA)+i)) = da;
        }
        R8_PWM_OUT_EN |= (ch);
    }
}

/*******************************************************************************
* Function Name  : PWMX_AlterOutCfg
* Description    : PWM 
* Input          : ch:  select group of PWM alternate output
                    RB_PWM4_5_STAG_EN   -  PWM4  PWM5 
                    RB_PWM6_7_STAG_EN   -  PWM6  PWM7 
                    RB_PWM8_9_STAG_EN   -  PWM8  PWM9 
                    RB_PWM10_11_STAG_EN -  PWM10  PWM11 
                   s :  control pwmx function
                    ENABLE  - 
                    DISABLE - 
* Return         : None
*******************************************************************************/
void PWMX_AlterOutCfg( UINT8 ch, UINT8 s)
{
    if(s == DISABLE)        R8_PWM_CONFIG &= ~(ch);
    else                    R8_PWM_CONFIG |= (ch);
}




