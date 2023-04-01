# FSDMMC 

## 1. 

SD/MMCMMCMultiMedia CardSDSecure Digital Card

## 2. 

SD/MMCSD/MMC
- SD/MMC
- /
- /
- SD/MMC

SD/MMCsdmmc


```
fsdmmc
     fsdmmc.c
     fsdmmc.h
     fsdmmc_dma.c
     fsdmmc_dma.h
     fsdmmc_g.c
     fsdmmc_hw.c
     fsdmmc_hw.h
     fsdmmc_intr.c
     fsdmmc_sinit.c
```

## 3. 

 FSDMMC :

- FSDMMC
- SD/MMC
- SD/MMC

## 4 

### [SD](../../../baremetal/example/peripheral/mmc/fsdmmc_probe)

### [SD/MMC](../../../third-party/sdmmc)

### [SD](../../../baremetal/example/storage/sdmmc_cmds)

### [SD](../../../baremetal/example/storage/sdmmc_fatfs)

## 5. API

### 5.1. 

- FSDMMC

```c
typedef struct
{
    FSdmmcConfig config;      /* Current active configs */
    u32          is_ready;    /* Device is initialized and ready */
    FSdmmcEventHandler evt_handler[FSDMMC_EVT_NUM];
} FSdmmc; /* Device instance */
```

- FSDMMC

```c
typedef struct
{
    u32     instance_id; /* Device instance id */
    uintptr base_addr;   /* Device base address */
    u32     irq_num[FSDMMC_INTR_NUM];
} FSdmmcConfig;
```

- FSDMMC
```c
typedef struct 
{
    u32 cmdidx;
    u32 cmdarg;
    u32 resptype;
    u32 response[4];
    u32 flag;
#define FSDMMC_CMD_FLAG_NEED_STOP         BIT(0)
#define FSDMMC_CMD_FLAG_NEED_INIT         BIT(1)
#define FSDMMC_CMD_FLAG_EXP_RESP          BIT(2)
#define FSDMMC_CMD_FLAG_EXP_LONG_RESP     BIT(3)
#define FSDMMC_CMD_FLAG_NEED_RESP_CRC     BIT(4)
#define FSDMMC_CMD_FLAG_EXP_DATA          BIT(5)
#define FSDMMC_CMD_FLAG_WRITE_DATA        BIT(6)
#define FSDMMC_CMD_FLAG_READ_DATA         BIT(7)
#define FSDMMC_CMD_FLAG_NEED_AUTO_STOP    BIT(8)
#define FSDMMC_CMD_FLAG_ADTC              BIT(9)
    FSdmmcData *data_p;
} FSdmmcCmd;
```

- FSDMMC
```c
typedef struct 
{
    u8 *buf;
    u32 blksz;
    u32 blkcnt;
    u32 datalen;
} FSdmmcData;
```

- FSDMMC
```c
enum
{
    FSDMMC_DMA_BD_INTR = 0,
    FSDMMC_CMD_INTR,
    FSDMMC_ERROR_INTR,

    FSDMMC_INTR_NUM  
}; /*  */

enum
{
    FSDMMC_EVT_CARD_REMOVED = 0,
    FSDMMC_EVT_CMD_DONE,
    FSDMMC_EVT_CMD_ERROR,
    FSDMMC_EVT_CMD_RESP_ERROR,
    FSDMMC_EVT_DATA_ERROR,
    FSDMMC_EVT_DATA_READ_DONE,
    FSDMMC_EVT_DATA_WRITE_DONE,

    FSDMMC_EVT_NUM
}; /*  */
```

### 5.2  

- [0x0] FSDMMC_SUCCESS : success

- [0x10c0001] FSDMMC_ERR_NOT_READY : FSDMMC

- [0x10c0001] FSDMMC_ERR_TIMEOUT : 

- [0x10c0001] FSDMMC_ERR_CMD_FAILED : 

- [0x10c0001] FSDMMC_ERR_DATA_FAILED : 

- [0x10c0001] FSDMMC_ERR_CARD_NO_FOUND : 

- [0x10c0001] FSDMMC_ERR_INVALID_BUF : 

### 5.3. API

#### FSdmmcLookupConfig

- FSDMMC

```c
const FSdmmcConfig *FSdmmcLookupConfig(u32 instance_id);
```

Note:

- instance_id0FSDMMC

Input:

- {u32} instance_id ID

Return:

- {const FSdmmcConfig *}  FSDMMCNULL

#### FSdmmcCfgInitialize

- FSDMMC, 

```c
FError FSdmmcCfgInitialize(FSdmmc *instance_p, const FSdmmcConfig *input_config_p);
```

Note:

- FSdmmcLookupConfig

Input:

- {FSdmmc} *instance_p FSDMMC
- {FSdmmcConfig} *input_config_p FSDMMC

Return:

- {FError} FSDMMC_SUCCESS 

#### FSdmmcDeInitialize

- FSDMMC, 

```c
void FSdmmcDeInitialize(FSdmmc *instance_p);
```

Note:

- 

Input:

- {FSdmmc} *instance_p FSDMMC

Return:

- 

#### FSdmmcPollTransfer

- FSDMMC/

```c
FError FSdmmcPollTransfer(FSdmmc *instance_p, FSdmmcCmd *cmd_data_p);
```

Note:

- FSDMMC

Input:

- {FSdmmc} *instance_p FSDMMC
- {FSdmmcCmd} *cmd_data_p FSDMMC

Return:

- {FError} FSDMMC_SUCCESS //

#### FSdmmcInterruptTransfer

- FSDMMC/

```c
FError FSdmmcInterruptTransfer(FSdmmc *instance_p, FSdmmcCmd *cmd_data_p);
```

Note:

- FSDMMCFSDMMC

Input:

- {FSdmmc} *instance_p FSDMMC
- {FSdmmcCmd} *cmd_data_p FSDMMC

Return:

- {FError} FSDMMC_SUCCESS //

#### FSdmmcGetInterruptMask

- FSDMMC

```c
u32 FSdmmcGetInterruptMask(uintptr base_addr, u32 intr_type);
```

Note:

- FSDMMC

Input:

- {uintptr} base_addr FSDMMC
- {u32} intr_type FSDMMC, FSDMMC_INTR_NUM

Return:

- {u32} 

#### FSdmmcSetInterruptMask

- FSDMMC

```c
void FSdmmcSetInterruptMask(uintptr base_addr, u32 intr_type, u32 mask, boolean enable);
```

Note:

- FSDMMC

Input:

- {uintptr} base_addr FSDMMC
- {u32} intr_type FSDMMC, FSDMMC_INTR_NUM
- {u32} mask 
- {boolean} enable TRUE:, FALSE:

Return:

- 

#### FSdmmcCmdInterrupHandler

- 

```c
void FSdmmcCmdInterrupHandler(s32 vector, void *param);
```

Note:

- FSDMMC

Input:

- vector 
- {void} *param 

Return:

- 

#### FSdmmcDmaInterrupHandler

- DMA

```c
void FSdmmcDmaInterrupHandler(s32 vector, void *param);
```

Note:

- FSDMMC

Input:

- {s32} vector 
- {void} *param 

Return:

- 

#### FSdmmcErrInterrupHandler

- 

```c
void FSdmmcErrInterrupHandler(s32 vector, void *param);
```

Note:

- FSDMMC

Input:

- {s32} vector 
- {void} *param 

Return:

- 

#### FSdmmcRegisterInterruptHandler

- 

```c
void FSdmmcRegisterInterruptHandler(FSdmmc *instance_p, u32 event, FSdmmcEventHandler handler);
```

Note:

- FSDMMCFSdmmcCmdInterrupHandlerFSdmmcErrInterrupHandler
 * FSdmmcDmaInterrupHandler

Input:

- {FSdmmc} *instance_p FSDMMC
- {u32} event FSDMMCFSDMMC_EVT_NUM
- {FSdmmcEventHandler} handler, FSDMMC

Return:

- 