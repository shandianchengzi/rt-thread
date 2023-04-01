#ifndef __SWM320_PWM_H__
#define __SWM320_PWM_H__

typedef struct {
    uint8_t  clk_div;       //PWM_CLKDIV_1PWM_CLKDIV_8

    uint8_t  mode;          //PWM_MODE_INDEPPWM_MODE_COMPLPWM_MODE_INDEP_CALIGNPWM_MODE_COMPL_CALIGN

    uint16_t cycleA;        //A
    uint16_t hdutyA;        //A
    uint16_t deadzoneA;     //A0--1023
    uint8_t  initLevelA;    //A0     1 

    uint16_t cycleB;        //B
    uint16_t hdutyB;        //B
    uint16_t deadzoneB;     //B0--1023
    uint8_t  initLevelB;    //B0     1 

    uint8_t  HEndAIEn;      //A
    uint8_t  NCycleAIEn;    //A
    uint8_t  HEndBIEn;      //B
    uint8_t  NCycleBIEn;    //B
} PWM_InitStructure;

#define PWM_CLKDIV_1    0
#define PWM_CLKDIV_8    1

#define PWM_MODE_INDEP          0       //AB
#define PWM_MODE_COMPL          1       //AB
#define PWM_MODE_INDEP_CALIGN   3       //AB
#define PWM_MODE_COMPL_CALIGN   4       //AB

#define PWM_CH_A    0
#define PWM_CH_B    1


void PWM_Init(PWM_TypeDef * PWMx, PWM_InitStructure * initStruct);          //PWM
void PWM_Start(PWM_TypeDef * PWMx, uint32_t chA, uint32_t chB);             //PWMPWM
void PWM_Stop(PWM_TypeDef * PWMx, uint32_t chA, uint32_t chB);              //PWMPWM

void PWM_SetCycle(PWM_TypeDef * PWMx, uint32_t chn, uint16_t cycle);        //
uint16_t PWM_GetCycle(PWM_TypeDef * PWMx, uint32_t chn);                    //
void PWM_SetHDuty(PWM_TypeDef * PWMx, uint32_t chn, uint16_t hduty);        //
uint16_t PWM_GetHDuty(PWM_TypeDef * PWMx, uint32_t chn);                    //
void PWM_SetDeadzone(PWM_TypeDef * PWMx, uint32_t chn, uint8_t deadzone);   //
uint8_t  PWM_GetDeadzone(PWM_TypeDef * PWMx, uint32_t chn);                 //

void PWM_IntNCycleEn(PWM_TypeDef * PWMx, uint32_t chn);                     //
void PWM_IntNCycleDis(PWM_TypeDef * PWMx, uint32_t chn);                    //
void PWM_IntNCycleClr(PWM_TypeDef * PWMx, uint32_t chn);                    //
uint32_t PWM_IntNCycleStat(PWM_TypeDef * PWMx, uint32_t chn);               //
void PWM_IntHEndEn(PWM_TypeDef * PWMx, uint32_t chn);                       //
void PWM_IntHEndDis(PWM_TypeDef * PWMx, uint32_t chn);                      //
void PWM_IntHEndClr(PWM_TypeDef * PWMx, uint32_t chn);                      //
uint32_t PWM_IntHEndStat(PWM_TypeDef * PWMx, uint32_t chn);                 //


#endif //__SWM320_PWM_H__
