/*******************************************************************************
* Copyright (C) 2019, Huada Semiconductor Co.,Ltd All rights reserved.
*
* This software is owned and published by:
* Huada Semiconductor Co.,Ltd ("HDSC").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with HDSC
* components. This software is licensed by HDSC to be adapted only
* for use in systems utilizing HDSC components. HDSC shall not be
* responsible for misuse or illegal use of this software for devices not
* supported herein. HDSC is providing this software "AS IS" and will
* not be responsible for issues arising from incorrect user implementation
* of the software.
*
* Disclaimer:
* HDSC MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS),
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING,
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED
* WARRANTY OF NONINFRINGEMENT.
* HDSC SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT,
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA,
* SAVINGS OR PROFITS,
* EVEN IF Disclaimer HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED
* FROM, THE SOFTWARE.
*
* This software may be replicated in part or whole for the licensed use,
* with the restriction that this Disclaimer and Copyright notice must be
* included with each copy of this software, whether used in part or whole,
* at all times.
*/
/******************************************************************************/
/** \file OPA.h
 **
 ** Headerfile for OPA functions
 ** @link OPA Group Some description @endlink 
 **
 ** History:
 **   - 2019-04-11       First Version
 **
 ******************************************************************************/

#ifndef __OPA_H__
#define __OPA_H__

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "ddl.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup OPAGroup  (OPA)
  **
 ******************************************************************************/
//@{

/**
 *******************************************************************************
 ** function prototypes.
 ******************************************************************************/

typedef enum en_opa_oenx
{
    OpaOen1  = 3u,            //OUT1
    OpaOen2  = 4u,            //OUT2
    OpaOen3  = 5u,            //OUT3
    OpaOen4  = 6u             //OUT4
}en_opa_oenx_t;
 
typedef enum en_opa_clksrc    // 
{
    OpaM1Pclk     = 0u,       // 1PCLK
    OpaM2Pclk     = 1u,       // 2PCLK
    OpaM4Pclk     = 2u,       // 4PCLK
    OpaM8Pclk     = 3u,       // 8PCLK
    OpaM16Pclk    = 4u,       // 16PCLK
    OpaM32Pclk    = 5u,       // 32PCLK
    OpaM64Pclk    = 6u,       // 64PCLK
    OpaM128Pclk   = 7u,       // 128PCLK
    OpaM256Pclk   = 8u,       // 256PCLK
    OpaM512Pclk   = 9u,       // 512PCLK
    OpaM1024Pclk  = 10u,      // 1024PCLK
    OpaM2048Pclk  = 11u,      // 2048PCLK
    OpaM4096Pclk  = 12u       // 4096PCLK
}en_opa_clksrc_t;

typedef enum en_opa_set0ctrl
{
    enClkSwSet = 3u,          // 
    enAzPulse  = 2u,          // 
    enTrigger  = 1u,          // 
    enAdctr    = 1u           // ADCOPA
}en_opa_set0ctrl_t;

typedef struct
{
    boolean_t         bAzen;        // 
    boolean_t         bClk_sw_set;  // 
    boolean_t         bAz_pulse;    // 
    boolean_t         bTrigger;     // 
    boolean_t         bAdctr_en;    // ADCOPA
    en_opa_clksrc_t   enClksrc;     // 
}stc_opa_zcfg_t;    


/******************************************************************************
 * Global variable declarations ('extern', definition in C source)
 ******************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 ******************************************************************************/
//OPA 
extern void Opa_Cmd(boolean_t NewStatus);
extern void Opa_CmdBuf(boolean_t NewStatus);

//OPA
extern void Opa_SetZero(stc_opa_zcfg_t* InitZero);

//OUTX
extern void Opa_CmdOnex(en_opa_oenx_t onex, boolean_t NewState);

//
extern void Opa_ZeroBitCtrl(en_opa_set0ctrl_t CtrlBit, boolean_t NewState);

//@} // OPA Group

#ifdef __cplusplus
#endif

#endif /* __OPA_H__ */
/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/


