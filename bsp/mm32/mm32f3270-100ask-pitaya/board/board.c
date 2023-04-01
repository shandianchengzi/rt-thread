/*
 * Copyright (c) 2020-2022, CQ 100ask Development Team
 *
 * Change Logs:
 *   Date           Author          Notes
 * 2022-05-29        Alen       first version
 */

#include "board.h"
#include "hal_rcc.h"

static uint32_t SystemClockFreq = HSI_VALUE;
static uint32_t AHBClockFreq = HSI_VALUE;
static uint32_t APB1ClockFreq = HSI_VALUE;
static uint32_t APB2ClockFreq = HSI_VALUE;

static void update_systemclock(void);
static void update_ahb_clock(void);
static void update_apb1_clock(void);
static void update_apb2_clock(void);

void SystemClock_Config(void)
{
    /*  */
    RCC->AHB1ENR |= (1u << 13u);    // FLASH
    FLASH->ACR |= (4<<0);           // Flash

    /* PWR/DBG */
    RCC->APB1ENR |= (1<<28);
    PWR->CR1 &= ~(2<<14);
    PWR->CR1 |= (2<<14);    //  120MHz VOS  2b10  1.7V

    RCC->CR &= ~((1<<16) | (1<<24) ); // HSE/PLL

    /* HSEPLL */
    RCC->CR |= (1<<16);             // HSE
    while(0 == ((RCC->CR)&(1<<17)));// HSE

    RCC->PLLCFGR |= (1<<0);         // PLLHSE
    RCC->PLLCFGR &= ~(1<<1);        // PLLHSE
    RCC->PLLCFGR &= ~(0x7F<<16);
    RCC->PLLCFGR |= (19<<16);       // PLL:20 -> 12MHz/2*20 = 120MHz
    RCC->PLLCFGR &= ~(0x7<<8);
    RCC->PLLCFGR |= (1<<8);         // PLL:2

    RCC->CR |= (1<<24);             // PLL
    while(0 == (RCC->CR & (1<<25)));// PLL

    /* AHBAPB */
    RCC->CFGR |= (0<<4);            // AHB
    RCC->CFGR |= (4<<8);            // APB1 2
    RCC->CFGR |= (4<<11);           // APB2 2
    RCC->CFGR |= (2<<22);           // PLL3USB120MHz/3=40MHz
    RCC->CFGR |= (7<<24);           // PLL2MCO
    RCC->CFGR |= (2<<0);            // PLL
    while(0 == (RCC->CFGR & (2<<2)));   // PLL

    update_systemclock();
    update_ahb_clock();
    update_apb1_clock();
    update_apb2_clock();
}

static void update_systemclock(void)
{
    uint32_t tmpreg = 0U, prediv = 0U, pllclk = 0U, pllmul = 0U;
    uint32_t sysclockfreq = HSI_VALUE;

    tmpreg = RCC->CFGR;
    /*  */
    switch(tmpreg & RCC_CFGR_SWS_MASK)
    {
        case RCC_SYSCLKSOURCE_STATUS_HSI:
        {
            sysclockfreq = HSI_VALUE;
            break;
        }
        case RCC_SYSCLKSOURCE_STATUS_HSE:
        {
            sysclockfreq = HSE_VALUE;
            break;
        }
        case RCC_SYSCLKSOURCE_STATUS_LSI:
        {
            sysclockfreq = LSI_VALUE;
            break;
        }
        case RCC_SYSCLKSOURCE_STATUS_PLLCLK:
        {
            /* PLL */
            if(RCC->PLLCFGR&0x01)       // HSEPLL
            {
                if(RCC->PLLCFGR&0x02)   // HSEPLL
                {
                    pllclk = HSE_VALUE>>1;
                }
                else                    // HSEPLL
                {
                    pllclk = HSE_VALUE;
                }
            }
            else    // HSIPLL
            {
                pllclk = HSI_VALUE;
            }
            prediv = (RCC->PLLCFGR>>8)&0x07;    // PLLPLLCFGR[10:8]
            pllmul = (RCC->PLLCFGR>>16)&0x7F;   // PLL: PLLCFGR[22:16]
            sysclockfreq = pllclk * (pllmul+1) / (prediv+1);

            break;
        }
        default:break;
    }

    SystemClockFreq = sysclockfreq;
}

static void update_ahb_clock(void)
{
    uint32_t tmpreg = RCC->CFGR;
    uint8_t hpre = (tmpreg>>4)&0x0F;
    if((hpre&0x08) == 0)   // 
        AHBClockFreq = SystemClockFreq;
    else
    {
        hpre = (hpre&0x07) + 1;
        AHBClockFreq = SystemClockFreq>>hpre;
    }
}

static void update_apb1_clock(void)
{
    uint32_t tmpreg = RCC->CFGR;
    uint8_t ppre1 = (tmpreg>>8)&0x0F;
    if((ppre1&0x04) == 0)   // 
        APB1ClockFreq = AHBClockFreq;
    else
    {
        ppre1 = (ppre1&0x03) + 1;
        APB1ClockFreq = AHBClockFreq>>ppre1;
    }
}

static void update_apb2_clock(void)
{
    uint32_t tmpreg = RCC->CFGR;
    uint8_t ppre2 = (tmpreg>>11)&0x0F;
    if((ppre2&0x04) == 0)   // 
        APB2ClockFreq = AHBClockFreq;
    else
    {
        ppre2 = (ppre2&0x03) + 1;
        APB2ClockFreq = AHBClockFreq>>ppre2;
    }
}

uint32_t HAL_GetSysClockFreq(void)
{
    return SystemClockFreq;
}

uint32_t HAL_Get_AHB_Clock(void)
{
    return AHBClockFreq;
}

uint32_t HAL_Get_APB1_Clock(void)
{
    return APB1ClockFreq;
}

uint32_t HAL_Get_APB2_Clock(void)
{
    return APB2ClockFreq;
}

