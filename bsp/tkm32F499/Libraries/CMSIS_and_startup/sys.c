#include "sys.h"
#include "HAL_misc.h"

void  RemapVtorTable(void)
{
    int i;
    RCC->AHB1ENR |= 1<<13;//bkp clk,enable sram
    //ROM
    for(i = 0;i<90;i++)
    {
        NVIC_DisableIRQ((IRQn_Type)i);
    }
    SCB->VTOR = 0;
    SCB->VTOR |= 0x1<<29;
    for(i = 0;i < 512;i+=4)
    *(u32*)(T_SRAM_BASE + i) = *(u32*)(T_SDRAM_BASE+i);

}

void  AI_Responder_enable(void)
{
  AI_Responder->ADDR1= 0x70807040;
//  AI_Responder->ADDR0 = 0x70027080;
  AI_Responder->ADDR1 = 0;
  AI_Responder->CCR &= ~(0x3<<3);
  AI_Responder->CCR |= 1;
  while((AI_Responder->SR & 0x3) != 2);
}
void  AI_Responder_disable(void)
{
    AI_Responder->CCR &= ~1;
}


//
//GPIOA~E
//:
//GPIOx:0~4,GPIOA~E
//BITx:PB12 12;
//TRIM:,1,;2,;3
//1IO,IO,
//,
void Ex_NVIC_Config(u8 GPIOx,u8 BITx,u8 TRIM)
{
    u8 EXTOFFSET=(BITx%4)*4;
    RCC->APB2ENR|=1<<14;                        //SYSCFG
    SYSCFG->EXTICR[BITx/4]&=~(0x000F<<EXTOFFSET);//
    SYSCFG->EXTICR[BITx/4]|=GPIOx<<EXTOFFSET;   //EXTI.BITxGPIOx.BITx
    //
    EXTI->IMR|=1<<BITx;                 //line BITx()
    if(TRIM&0x01)EXTI->FTSR|=1<<BITx;   //line BITx
    if(TRIM&0x02)EXTI->RTSR|=1<<BITx;   //line BITx
}


//THUMB
//WFI
void WFI_SET(void)
{
    __ASM volatile("wfi");
}
//(faultNMI)
void INTX_DISABLE(void)
{
    __ASM volatile("cpsid i");
}
//
void INTX_ENABLE(void)
{
    __ASM volatile("cpsie i");
}
//  __set_MSP(0x70002000);

//
void Sys_Standby(void)
{
    SCB->SCR|=1<<2;     //SLEEPDEEP (SYS->CTRL)
    RCC->APB1ENR|=1<<28;//
    PWR->CSR|=1<<8;     //WKUP
    PWR->CR|=1<<2;      //Wake-up 
    PWR->CR|=1<<1;      //PDDS
    WFI_SET();          //WFI,
}
//
void Sys_Soft_Reset(void)
{
    SCB->AIRCR =0X05FA0000|(u32)0x04;
}

//      TK499_NVIC_Init(2,2,TK80_IRQn,2);
//NVIC
//NVIC_PreemptionPriority:
//NVIC_SubPriority       :
//NVIC_Channel           :
//NVIC_Group             : 0~4
//!
//:
//0:0,4
//1:1,3
//2:2,2
//3:3,1
//4:4,0
//NVIC_SubPriorityNVIC_PreemptionPriority,,
void TK499_NVIC_Init(u8 NVIC_PreemptionPriority,u8 NVIC_SubPriority,u8 NVIC_Channel,u8 NVIC_Group)
{
    u32 temp;
    NVIC_SetPriorityGrouping(NVIC_Group);//
    temp=NVIC_PreemptionPriority<<(4-NVIC_Group);
    temp|=NVIC_SubPriority&(0x0f>>NVIC_Group);
    temp&=0xf;                              //
    NVIC->ISER[NVIC_Channel/32]|=1<<NVIC_Channel%32;//(,ICER1)
    NVIC->IP[NVIC_Channel]|=temp<<4;                //
}

void TK80_IRQHandler(void)
{
    if(TK80->SR & 0x1)
    {

    }
    if(TK80->SR & 0x2)
    {

    }
    if(TK80->SR & 0x4)
    {

    }
    if(TK80->SR & 0x8)
    {

    }
    TK80->SR |= 0;
}

//
//#define T_SRAM_FUN1 0x20000400
//copyAtoB((u32)LCD_PutPixel&0xFFFFFFFE,T_SRAM_FUN1,800);//SRAM
//void copyAtoB(u32 srcAdd,u32 dstAdd,u16 len)
//{
//    len = (len + 3)/4;
//    while(len--)
//    {
//        *(u32*)dstAdd = *(u32*)srcAdd;
//        dstAdd += 4 ;
//        srcAdd +=4 ;
//    }
//}














