/*
*@:Copyright(c)2021PhytiumInformationTechnology,Inc.
*
*SPDX-License-Identifier:Apache-2.0.
*
 * @Date: 2021-04-07 09:53:07
 * @LastEditTime: 2021-05-25 10:51:35
 * @Description: This files is for generic timer functions
 *
 * @ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */

#include "ft_status.h"
#include "ft_types.h"
#include "ft_generic_timer.h"
#include "ft_printf.h"
#include "ft_assert.h"
#include "ft_aarch32_asm.h"
#include "ft_cpu.h"

#define GENERICTIMER_ASM(x) __asm__ volatile(x)
#define USEVIRTUAL 0
#define USE_ISRNUM GEN_TIMER_PHYSICAL_NOSECURE_IRQN

static volatile u32 _TickCnt;
static volatile u32 _Tickms;

typedef struct ft_Generictimer
{
    u64 Frequency;
    u64 MaxCount;
    u64 TicksPerUs;
    u32 Isr_PeriodMsec;
    u32 Isr_PeriodCnt; //<! 
    u8 UseVirtual;
    u8 InitFlg;      //<! 1 is ,0 is 
    u8 Isr_IsEnable; //<! 1 is init , 2 is open, 0 is close
    Ft_GenericTimer_Isr_Callback Callback;
} ft_Generictimer_handler_t;

ft_Generictimer_handler_t Ft_GenericTimer_Handler = {0};

/**
 * @name: GenericTimer_WriteReg
 * @msg:
 * @in IsVirtual{u8}: 1  0 
 * @in reg{u32}:  GEN_TIMER_REG_CTL GEN_TIMER_REG_TVAL 
 * @in val{u32}:   GEN_TIMER_CTRL_ENABLE GEN_TIMER_CTRL_IMASK GEN_TIMER_CTRL_ISTATUS
 * @return {*}
 */
__STATIC_INLINE void GenericTimer_WriteReg(FT_IN u8 IsVirtual, FT_IN u32 reg, FT_IN u32 val)
{
    if (IsVirtual)
    {
        if (reg == GEN_TIMER_REG_CTL)
        {
            arm_aarch32_cnthv_ctl_set(val);
        }
        else
        {
            arm_aarch32_cnthv_tval_set(val);
        }
    }
    else
    {
        if (reg == GEN_TIMER_REG_CTL)
        {
            arm_aarch32_cntp_ctl_set(val);
        }
        else
        {
            arm_aarch32_cntp_tval_set(val);
        }
    }

    GENERICTIMER_ASM("ISB");
}

/**
 * @name: GenericTimer_ReadReg
 * @msg:  GenericTimer 
 * @in IsVirtual{u8}: 1  0 
 * @in reg{u32}:  GEN_TIMER_REG_CTL GEN_TIMER_REG_TVAL 
 * @return {u32} 
 */
__STATIC_INLINE u32 GenericTimer_ReadReg(FT_IN u8 IsVirtual, FT_IN u32 reg)
{
    u32 val = 0;

    if (IsVirtual)
    {
        if (reg == GEN_TIMER_REG_CTL)
        {
            val = arm_aarch32_cnthv_ctl_get();
        }
        else
        {
            val = arm_aarch32_cnthv_tval_get();
        }
    }
    else
    {
        if (reg == GEN_TIMER_REG_CTL)
        {
            val = arm_aarch32_cntp_ctl_get();
        }
        else
        {
            val = arm_aarch32_cntp_ctl_get();
        }
    }

    return val;
}

/**
 * @name: GenericTimer_GetTimerCnt
 * @msg:  
 * @in IsVirtual{u8}: 1  0 
 * @return {u64} timer count value.
 */
__STATIC_INLINE u64 GenericTimer_GetTimerCnt(FT_IN u8 IsVirtual)
{

    GENERICTIMER_ASM("ISB");

    if (IsVirtual)
    {
        return arm_aarch32_cntvct_get();
    }
    else
    {
        return arm_aarch32_cntpct_get();
    }
}

/**
 * @name: Ft_GenericTimer_UsDelay
 * @msg:  us
 * @in param{u32}: DelayUs us
 * @param {u32} DelayUs
 */
int32_t Ft_GenericTimer_UsDelay(FT_IN u32 DelayUs)
{
    register volatile u64 oldVal;
    register volatile u64 newVal;
    register volatile u64 decElapsed = 0;
    register volatile u64 totalDelta;

    int loopcount = 0;

    if (Ft_GenericTimer_Handler.InitFlg == 0)
    {
        return FST_FAILURE;
    }

    if (DelayUs == 0)
    {
        return FST_FAILURE;
    }

    if (Ft_GenericTimer_Handler.TicksPerUs != 48)
    {
        //Ft_printf("ticksPerUs-%d should be 48 for this board, please check it!\r\n", Ft_GenericTimer_Handler.TicksPerUs);
    }

    totalDelta = Ft_GenericTimer_Handler.TicksPerUs * (u64)DelayUs;
    oldVal = GenericTimer_GetTimerCnt(Ft_GenericTimer_Handler.UseVirtual);

    while (decElapsed < totalDelta)
    {
        loopcount++;
        newVal = GenericTimer_GetTimerCnt(Ft_GenericTimer_Handler.UseVirtual);

        if (newVal == oldVal)
        {
            continue;
        }

        /* no rollover. count down... */

        if (newVal < oldVal)
        {
            decElapsed += (oldVal - newVal);
        }
        /* rollover */
        else
        {
            decElapsed += ((Ft_GenericTimer_Handler.MaxCount - oldVal) + newVal);
        }

        oldVal = newVal;
    }

    return FST_SUCCESS;
}

/**
 * @name: Ft_GenericTimer_IsrSet
 * @msg:   GenericTimer 
 * @in param{u32}: HzRate , 1000
 * @in param{u32}: Cmd 1 0
 * @return {int32_t}: 
 */
int32_t Ft_GenericTimer_IsrSet(FT_IN u32 HzRate, FT_IN u32 Cmd)
{

    Ft_assertNonvoid(HzRate <= 1000);
    Ft_assertNonvoid(Ft_GenericTimer_Handler.InitFlg != 0);

    if (Cmd == 1)
    {
        if (Ft_GenericTimer_Handler.Isr_IsEnable == 2)
        {
            //<! turn off isr
            GenericTimer_WriteReg(Ft_GenericTimer_Handler.UseVirtual, GEN_TIMER_REG_CTL,
                                  GEN_TIMER_CTRL_IMASK);
        }

        Ft_GenericTimer_Handler.Isr_IsEnable = 1;
        Ft_GenericTimer_Handler.Isr_PeriodCnt = Ft_GenericTimer_Handler.Frequency / HzRate;
        Ft_GenericTimer_Handler.Isr_PeriodMsec = 1000 / HzRate;
        /* update the timer value register with maxTimerCount */
        GenericTimer_WriteReg(Ft_GenericTimer_Handler.UseVirtual, GEN_TIMER_REG_TVAL,
                              Ft_GenericTimer_Handler.Isr_PeriodCnt);

        /* set up the timer control register */
        GenericTimer_WriteReg(Ft_GenericTimer_Handler.UseVirtual, GEN_TIMER_REG_CTL,
                              GEN_TIMER_CTRL_ENABLE);
    }
    else if (Cmd == 0)
    {
        Ft_GenericTimer_Handler.Isr_IsEnable = 0;
        Ft_GenericTimer_Handler.Isr_PeriodCnt = Ft_GenericTimer_Handler.Frequency / HzRate;
        //<! turn off isr
        GenericTimer_WriteReg(Ft_GenericTimer_Handler.UseVirtual, GEN_TIMER_REG_CTL,
                              GEN_TIMER_CTRL_IMASK);
    }
    else
    {
        return FST_FAILURE;
    }
    return FST_SUCCESS;
}

/**
 * @name: Ft_GenericTimer_IrqHandler
 * @msg:  
 * @in param{void *}: param 
 */
void Ft_GenericTimer_IrqHandler(void *param)
{
    /* update the timer value register with maxTimerCount */
    GenericTimer_WriteReg(Ft_GenericTimer_Handler.UseVirtual, GEN_TIMER_REG_TVAL,
                          Ft_GenericTimer_Handler.Isr_PeriodCnt);

    /* set up the timer control register */
    GenericTimer_WriteReg(Ft_GenericTimer_Handler.UseVirtual, GEN_TIMER_REG_CTL,
                          GEN_TIMER_CTRL_ENABLE);

    if (Ft_GenericTimer_Handler.Callback)
    {
        Ft_GenericTimer_Handler.Callback(param);
    }

    _TickCnt++;

    _Tickms += Ft_GenericTimer_Handler.Isr_PeriodMsec;
}

void Ft_GenericTimer_Debug(void)
{
    Ft_printf("GenericTimer_ReadReg %x \r\n", GenericTimer_ReadReg(Ft_GenericTimer_Handler.UseVirtual, GEN_TIMER_REG_CTL));
}

/**
 * @name: Ft_GenericTimer_GetTick
 * @msg:  
 * @return {u32} _TickCnt
 */
u32 Ft_GenericTimer_GetTick(void)
{
    return _TickCnt;
}

/**
 * @name: Ft_GenericTimer_Msec
 * @msg:  ms
 * @return {u32}
 */
u32 Ft_GenericTimer_Msec(void)
{
    return _Tickms;
}

/**
 * @name: Ft_GenericTimer_Init
 * @msg:  GenericTimer 
 * @in param { u8} UseVirtual 1  0
 * @in param { Ft_GenericTimer_Isr_Callback} 
 * @return {*}
 */
void Ft_GenericTimer_Init(FT_IN u8 UseVirtual, FT_IN Ft_GenericTimer_Isr_Callback Callback)
{
    Ft_GenericTimer_Handler.Frequency = arm_aarch32_cntfrq_get();

    Ft_GenericTimer_Handler.TicksPerUs = Ft_GenericTimer_Handler.Frequency / 1000000;

    Ft_GenericTimer_Handler.MaxCount = 0xffffffffffffffffull;
    Ft_GenericTimer_Handler.Callback = Callback;
    Ft_GenericTimer_Handler.UseVirtual = UseVirtual;
    Ft_GenericTimer_Handler.InitFlg = 1;
    Ft_GenericTimer_Handler.Isr_IsEnable = 0;
    _Tickms = 0;
    _TickCnt = 0;

    //<! 
    /* update the timer value register with maxTimerCount */
    GenericTimer_WriteReg(Ft_GenericTimer_Handler.UseVirtual, GEN_TIMER_REG_TVAL,
                          Ft_GenericTimer_Handler.MaxCount);

    /* set up the timer control register */
    GenericTimer_WriteReg(Ft_GenericTimer_Handler.UseVirtual, GEN_TIMER_REG_CTL,
                          GEN_TIMER_CTRL_ENABLE);
}
