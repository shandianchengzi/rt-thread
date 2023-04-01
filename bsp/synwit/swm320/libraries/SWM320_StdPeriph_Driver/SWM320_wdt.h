#ifndef __SWM320_WDT_H__
#define __SWM320_WDT_H__

#define WDT_MODE_RESET      0
#define WDT_MODE_INTERRUPT  1

void WDT_Init(WDT_TypeDef * WDTx, uint32_t peroid, uint32_t mode);  //WDT
void WDT_Start(WDT_TypeDef * WDTx);         //WDT
void WDT_Stop(WDT_TypeDef * WDTx);          //WDT

void WDT_Feed(WDT_TypeDef * WDTx);          //

int32_t WDT_GetValue(WDT_TypeDef * WDTx);   //


void WDT_INTClr(WDT_TypeDef * WDTx);        //
uint32_t WDT_INTStat(WDT_TypeDef * WDTx);   //

#endif //__SWM320_WDT_H__
