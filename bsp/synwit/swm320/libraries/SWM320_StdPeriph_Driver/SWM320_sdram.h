#ifndef __SWM320_SDRAM_H__
#define __SWM320_SDRAM_H__

typedef struct {
    uint8_t CellSize;           // SDRAMSDRAM_CELLSIZE_16MbSDRAM_CELLSIZE_64MbSDRAM_CELLSIZE_128MbSDRAM_CELLSIZE_256Mb
    uint8_t CellBank;           // SDRAMbankSDRAM_CELLBANK_2SDRAM_CELLBANK_4
    uint8_t CellWidth;          // SDRAMSDRAM_CELLWIDTH_16SDRAM_CELLWIDTH_32
    uint8_t CASLatency;         // SDRAM_CASLATENCY_2SDRAM_CASLATENCY_3

    uint8_t TimeTMRD;           // MRS to New Command
    uint8_t TimeTRRD;           // Activate to activate on different banks
    uint8_t TimeTRAS;           // Self refresh timeSelf-refresh
    uint8_t TimeTRC;            // Row cycle delayRefreshActivateRefresh
    uint8_t TimeTRCD;           // Row to column delayActivate
    uint8_t TimeTRP;            // Row precharge delayPrecharge
} SDRAM_InitStructure;

#define SDRAM_CELLSIZE_16Mb     3
#define SDRAM_CELLSIZE_64Mb     0
#define SDRAM_CELLSIZE_128Mb    1
#define SDRAM_CELLSIZE_256Mb    2

#define SDRAM_CELLBANK_2        0
#define SDRAM_CELLBANK_4        1

#define SDRAM_CELLWIDTH_16      0
#define SDRAM_CELLWIDTH_32      1

#define SDRAM_CASLATENCY_2      2
#define SDRAM_CASLATENCY_3      3

#define SDRAM_TMRD_3            3
#define SDRAM_TMRD_4            4
#define SDRAM_TMRD_5            5
#define SDRAM_TMRD_6            6
#define SDRAM_TMRD_7            7

#define SDRAM_TRRD_2            2
#define SDRAM_TRRD_3            3

#define SDRAM_TRAS_2            2
#define SDRAM_TRAS_3            3
#define SDRAM_TRAS_4            4
#define SDRAM_TRAS_5            5
#define SDRAM_TRAS_6            6
#define SDRAM_TRAS_7            7

#define SDRAM_TRC_2             2
#define SDRAM_TRC_3             3
#define SDRAM_TRC_4             4
#define SDRAM_TRC_5             5
#define SDRAM_TRC_6             6
#define SDRAM_TRC_7             7
#define SDRAM_TRC_8             8
#define SDRAM_TRC_9             9
#define SDRAM_TRC_10            10
#define SDRAM_TRC_11            11
#define SDRAM_TRC_12            12
#define SDRAM_TRC_13            13
#define SDRAM_TRC_14            14
#define SDRAM_TRC_15            15

#define SDRAM_TRCD_3            3
#define SDRAM_TRCD_4            4
#define SDRAM_TRCD_5            5
#define SDRAM_TRCD_6            6
#define SDRAM_TRCD_7            7

#define SDRAM_TRP_3             3
#define SDRAM_TRP_4             4
#define SDRAM_TRP_5             5
#define SDRAM_TRP_6             6
#define SDRAM_TRP_7             7



void SDRAM_Init(SDRAM_InitStructure * initStruct);

void SDRAM_Enable(void);
void SDRAM_Disable(void);

#endif //__SWM320_SDRAM_H__
