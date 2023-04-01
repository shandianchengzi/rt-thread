#ifndef __SWM320_TIMR_H__
#define __SWM320_TIMR_H__

#define TIMR_MODE_TIMER     0
#define TIMR_MODE_COUNTER   1

void TIMR_Init(TIMR_TypeDef * TIMRx, uint32_t mode, uint32_t period, uint32_t int_en);  ///
void TIMR_Start(TIMR_TypeDef * TIMRx);                          ///
void TIMR_Stop(TIMR_TypeDef * TIMRx);                           //
void TIMR_Halt(TIMR_TypeDef * TIMRx);                           //
void TIMR_Resume(TIMR_TypeDef * TIMRx);                         //

void TIMR_SetPeriod(TIMR_TypeDef * TIMRx, uint32_t period);     ///
uint32_t TIMR_GetPeriod(TIMR_TypeDef * TIMRx);                  ///
uint32_t TIMR_GetCurValue(TIMR_TypeDef * TIMRx);                //

void TIMR_INTEn(TIMR_TypeDef * TIMRx);                          //
void TIMR_INTDis(TIMR_TypeDef * TIMRx);                         //
void TIMR_INTClr(TIMR_TypeDef * TIMRx);                         //
uint32_t TIMR_INTStat(TIMR_TypeDef * TIMRx);                    //



#define PULSE_LOW    0
#define PULSE_HIGH   1

void Pulse_Init(uint32_t pulse, uint32_t int_en);
void Pulse_Start(void);
uint32_t Pulse_Done(void);


#endif //__SWM320_TIMR_H__
