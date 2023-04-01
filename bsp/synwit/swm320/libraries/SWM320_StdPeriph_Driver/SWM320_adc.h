#ifndef __SWM320_ADC_H__
#define __SWM320_ADC_H__

typedef struct {
    uint8_t clk_src;        //ADCADC_CLKSRC_HRCADC_CLKSRC_VCO_DIV16ADC_CLKSRC_VCO_DIV32ADC_CLKSRC_VCO_DIV32
    uint8_t clk_div;        //ADC1--31
    uint8_t pga_ref;        //PGAPGA_REF_INTERNALPGA_REF_EXTERNAL
    uint8_t channels;       //ADCADC_CH0ADC_CH1... ... ADC_CH7
    uint8_t samplAvg;       //ADCADC
    uint8_t trig_src;       //ADCADC_TRIGSRC_SWADC_TRIGSRC_PWMADC_TRIGSRC_TIMR2ADC_TRIGSRC_TIMR3
    uint8_t Continue;       //1 START
                            //                  0 START
    uint8_t EOC_IEn;        //EOCADC_CH0ADC_CH1... ... ADC_CH7
    uint8_t OVF_IEn;        //OVFADC_CH0ADC_CH1... ... ADC_CH7
    uint8_t HFULL_IEn;      //FIFOADC_CH0ADC_CH1... ... ADC_CH7
    uint8_t FULL_IEn;       //FIFO  ADC_CH0ADC_CH1... ... ADC_CH7
} ADC_InitStructure;

#define ADC_CH0     0x01
#define ADC_CH1     0x02
#define ADC_CH2     0x04
#define ADC_CH3     0x08
#define ADC_CH4     0x10
#define ADC_CH5     0x20
#define ADC_CH6     0x40
#define ADC_CH7     0x80

#define ADC_CLKSRC_HRC          1
#define ADC_CLKSRC_VCO_DIV16    2
#define ADC_CLKSRC_VCO_DIV32    3
#define ADC_CLKSRC_VCO_DIV64    4

#define ADC_AVG_SAMPLE1         0
#define ADC_AVG_SAMPLE2         1   //2
#define ADC_AVG_SAMPLE4         3
#define ADC_AVG_SAMPLE8         7
#define ADC_AVG_SAMPLE16        15

#define ADC_TRIGSRC_SW          0   //ADC->START.GO1
#define ADC_TRIGSRC_PWM         1

#define PGA_REF_INTERNAL        1   //PGAADC_REFPADC_REFN
#define PGA_REF_EXTERNAL        0   //PGA(ADC_REFP + ADC_REFN) 


void ADC_Init(ADC_TypeDef * ADCx, ADC_InitStructure * initStruct);      //ADC
void ADC_Open(ADC_TypeDef * ADCx);                          //ADCADC
void ADC_Close(ADC_TypeDef * ADCx);                         //ADCADC
void ADC_Start(ADC_TypeDef * ADCx);                         //ADC
void ADC_Stop(ADC_TypeDef * ADCx);                          //ADC

uint32_t ADC_Read(ADC_TypeDef * ADCx, uint32_t chn);        //
uint32_t ADC_IsEOC(ADC_TypeDef * ADCx, uint32_t chn);       //End Of Conversion

void ADC_ChnSelect(ADC_TypeDef * ADCx, uint32_t chns);


void ADC_IntEOCEn(ADC_TypeDef * ADCx, uint32_t chn);        //
void ADC_IntEOCDis(ADC_TypeDef * ADCx, uint32_t chn);       //
void ADC_IntEOCClr(ADC_TypeDef * ADCx, uint32_t chn);       //
uint32_t ADC_IntEOCStat(ADC_TypeDef * ADCx, uint32_t chn);  //

void ADC_IntOVFEn(ADC_TypeDef * ADCx, uint32_t chn);        //
void ADC_IntOVFDis(ADC_TypeDef * ADCx, uint32_t chn);       //
void ADC_IntOVFClr(ADC_TypeDef * ADCx, uint32_t chn);       //
uint32_t ADC_IntOVFStat(ADC_TypeDef * ADCx, uint32_t chn);  //

void ADC_IntHFULLEn(ADC_TypeDef * ADCx, uint32_t chn);      //FIFO
void ADC_IntHFULLDis(ADC_TypeDef * ADCx, uint32_t chn);     //FIFO
void ADC_IntHFULLClr(ADC_TypeDef * ADCx, uint32_t chn);     //FIFO
uint32_t ADC_IntHFULLStat(ADC_TypeDef * ADCx, uint32_t chn);//FIFO

void ADC_IntFULLEn(ADC_TypeDef * ADCx, uint32_t chn);       //FIFO
void ADC_IntFULLDis(ADC_TypeDef * ADCx, uint32_t chn);      //FIFO
void ADC_IntFULLClr(ADC_TypeDef * ADCx, uint32_t chn);      //FIFO
uint32_t ADC_IntFULLStat(ADC_TypeDef * ADCx, uint32_t chn); //FIFO


#endif //__SWM320_ADC_H__
