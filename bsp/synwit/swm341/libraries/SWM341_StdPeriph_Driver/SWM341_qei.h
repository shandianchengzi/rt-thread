#ifndef __SWM341_QEI_H__
#define __SWM341_QEI_H__

typedef struct {
    uint8_t  mode;                  //QEI_MODE_X2QEI_MODE_X4
    uint16_t maxcnt;                //
    uint8_t  swapAB;                //1 AB
    uint8_t  intINDEXEn;            //Index
    uint8_t  intMATCHEn;            //POSCNTMAXCNTPOSCNTMAXCNT0
    uint8_t  intCNTOVEn;            //Counter Overrun
    uint8_t  intERROREn;            //
} QEI_InitStructure;


#define QEI_MODE_X2         0
#define QEI_MODE_X4         1

#define QEI_INT_INDEX       (1 << 0)
#define QEI_INT_MATCH       (1 << 1)
#define QEI_INT_CNTOV       (1 << 2)
#define QEI_INT_ERROR       (1 << 3)


void QEI_Init(QEI_TypeDef * QEIx, QEI_InitStructure * initStruct);      //QEI
void QEI_Start(QEI_TypeDef * QEIx);                     //QEI
void QEI_Stop(QEI_TypeDef * QEIx);                      //QEI

uint32_t QEI_IndexLvl(QEI_TypeDef * QEIx);              //QEI Index
uint32_t QEI_CountDir(QEI_TypeDef * QEIx);              //QEI0     1 

void QEI_IntEn(QEI_TypeDef * QEIx, uint32_t it);        //QEI
void QEI_IntDis(QEI_TypeDef * QEIx, uint32_t it);       //QEI
void QEI_IntClr(QEI_TypeDef * QEIx, uint32_t it);       //QEI
uint32_t QEI_IntStat(QEI_TypeDef * QEIx, uint32_t it);  //QEI


#endif //__SWM341_QEI_H__
