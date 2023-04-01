#ifndef __SWM320_DMA_H__
#define __SWM320_DMA_H__


#define DMA_CH0     0
#define DMA_CH1     1
#define DMA_CH2     2


void DMA_CHM_Config(uint32_t chn, uint32_t src_addr, uint32_t src_addr_incr, uint32_t dst_addr, uint32_t dst_addr_incr, uint32_t num_word, uint32_t int_en);    //DMAFlashRAM
void DMA_CH_Open(uint32_t chn);                 //DMA
void DMA_CH_Close(uint32_t chn);                //DMA

void DMA_CH_INTEn(uint32_t chn);                //DMA
void DMA_CH_INTDis(uint32_t chn);               //DMA
void DMA_CH_INTClr(uint32_t chn);               //DMA
uint32_t DMA_CH_INTStat(uint32_t chn);          //DMA1     0 


#endif //__SWM320_DMA_H__
