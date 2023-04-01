#ifndef __SYS_H
#define __SYS_H
#include "tk499.h"
#include "HAL_conf.h"
//,51GPIO
//,<<CM3>>(87~92).M4M3,.
//IO
//#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2))
//#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr))
//#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum))

void  RemapVtorTable(void);
void  AI_Responder_enable(void);
void  AI_Responder_disable(void);

void Sys_Soft_Reset(void);                                  //
void Sys_Standby(void);                                     //

void TK499_NVIC_Init(u8 NVIC_PreemptionPriority,u8 NVIC_SubPriority,u8 NVIC_Channel,u8 NVIC_Group);
void Ex_NVIC_Config(u8 GPIOx,u8 BITx,u8 TRIM);              //(GPIOA~I)

//
void WFI_SET(void);     //WFI
void INTX_DISABLE(void);//
void INTX_ENABLE(void); //

void TIM3_Config(u16 arr,u16 psc);
#endif











