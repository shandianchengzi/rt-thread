# FGDMA 

## 1. 

GDMA(Generic Direct Memory Access)DMA


## 2. 

FGDMA  GDMA GDMA 

```
fgdma
    .
     fgdma.c
     fgdma.h
     fgdma_g.c
     fgdma_hw.h
     fgdma_intr.c
     fgdma_selftest.c
     fgdma_sinit.c
```

## 3. 

 FGDMA :

-  GDMA 
-  GDMA  BDL 
-  GDMA 

## 4. 

### [GDMA](../../../baremetal/example/peripheral/dma/fgdma_async_memcpy)

## 5. API

### 5.1. 

#### FGdmaConfig

- GDMA

```c
typedef struct
{
    u32 instance_id;               /* GDMAID */
    u32 irq_num;                   /* GDMA */
    u32 irq_prority;               /* GDMA */
    volatile uintptr_t base_addr;  /* GDMA */
    FGdmaOperPriority rd_qos;      /*  */
    FGdmaOperPriority wr_qos;      /*  */
} FGdmaConfig;
```

#### FGdmaChanConfig

- DMA

```c
typedef struct
{
    FGdmaChanIndex      chan_id; /* DMAID */
    FGdmaOperPriority   rd_qos;  /* DMAQos */
    FGdmaOperPriority   wr_qos;  /* DMAQos */
    FGdmaOperMode       trans_mode; /* DMABDL */
    /* Direct */
    FGdmaBurstSize      rd_align; /* DMABurst */
    FGdmaBurstSize      wr_align; /* DMABurst */    
    /* BDL */
    boolean             roll_back; /* TRUE: BDLBDL */ 
    FGdmaBdlDesc        *descs;
    u32                 total_desc_num;
    u32                 valid_desc_num;
} FGdmaChanConfig; /* DMA */
```

#### FGdmaChan

- GDMA

```c
typedef struct _FGdmaChan
{
    FGdmaChanConfig config;     /* DMA */
    FGdma *gdma;                /* DMA */
    FGdmaChanEvtHandler evt_handlers[FGDMA_CHAN_NUM_OF_EVT];  /* DMA */
    void *evt_handler_args[FGDMA_CHAN_NUM_OF_EVT];            /* DMA */
} FGdmaChan; /* GDMA */
```

#### FGdma

- GDMA

```c
typedef struct _FGdma
{
    FGdmaConfig config;       /* GDMA */
    u32 is_ready;             /* GDMA */
    FGdmaChan *chans[FGDMA_NUM_OF_CHAN]; /* GDMANULL */
} FGdma; /* GDMA */
```

#### FGdmaBdlDesc

- BDL

```c
typedef struct
{
    u32 src_addr_l; /* 0x0, 32 */
    u32 src_addr_h; /* 0x4, 32 */
    u32 dst_addr_l; /* 0x8, 32 */
    u32 dst_addr_h; /* 0xc, 32 */
#define FGDMA_SRC_TC_BDL_BURST_SET(x)      SET_REG32_BITS((x), 1U, 0U)
#define FGDMA_SRC_TC_BDL_SIZE_SET(x)       SET_REG32_BITS((x), 6U, 4U)
#define FGDMA_SRC_TC_BDL_LEN_SET(x)        SET_REG32_BITS((x), 15U, 8U)
    u32 src_tc;     /* 0x10,  */
#define FGDMA_DST_TC_BDL_BURST_SET(x)      SET_REG32_BITS((x), 1U, 0U)
#define FGDMA_DST_TC_BDL_SIZE_SET(x)       SET_REG32_BITS((x), 6U, 4U)
#define FGDMA_DST_TC_BDL_LEN_SET(x)        SET_REG32_BITS((x), 15U, 8U)
    u32 dst_tc;     /* 0x14,  */
    u32 total_bytes;/* 0x18, Byte  */
    u32 ioc;        /* 0x1c,   */
} __attribute__((__packed__)) FGdmaBdlDesc; /* BDL */
```

### 5.2  

#define FGDMA_SUCCESS           :       
#define FGDMA_ERR_NOT_INIT      : 
#define FGDMA_ERR_CHAN_IN_USE   : 
#define FGDMA_ERR_CHAN_NOT_INIT : 
#define FGDMA_ERR_INVALID_ADDR  : 
#define FGDMA_ERR_INVALID_SIZE  : 
#define FGDMA_ERR_BDL_NOT_ENOUGH : BDL


### 5.3. API

#### FGdmaLookupConfig

```c
const FGdmaConfig *FGdmaLookupConfig(u32 instance_id)
```

Note:

- GDMA

Input:

- {u32} instance_id, GDMAID

Return:

- {const FGdmaConfig *} 

#### FGdmaCfgInitialize

```c
FError FGdmaCfgInitialize(FGdma *const instance_p, const FGdmaConfig *input_config)
```

Note:

- GDMA

Input:

- FGdma *const instance_p, GDMA
- const FGdmaConfig *input_config, GDMA

Return:

- {FError} FGDMA_SUCCESS

#### FGdmaDeInitialize

```c
void FGdmaDeInitialize(FGdma *const instance_p)
```

Note:

- GDMA

Input:

- FGdma *const instance_p, GDMA

Return:

- 

#### FGdmaAllocateChan

```c
FError FGdmaAllocateChan(FGdma *const instance_p, FGdmaChan *const dma_chan, 
						 const FGdmaChanConfig *dma_chan_config)
```

Note:

- GDMA

Input:

- FGdma *const instance_p, GDMA
- FGdmaChan *const dma_chan, GDMA
- const FGdmaChanConfig *dma_chan_config, GDMA

Return:

- {FError} FGDMA_SUCCESS

#### FGdmaDellocateChan

```c
FError FGdmaDellocateChan(FGdmaChan *const dma_chan)
```

Note:

- GDMA

Input:

- FGdmaChan *const dma_chan, GDMA

Return:

- {FError} FGDMA_SUCCESS

#### FGdmaDirectTransfer

```c
FError FGdmaDirectTransfer(FGdmaChan *const chan_p, uintptr src_addr, uintptr dst_addr, fsize_t data_len);

```

Note:

- DMA

Input:

- FGdmaChan *const chan_p, GDMA
- uintptr src_addr, 
- uintptr dst_addr, 

Return:

- {FError} FGDMA_SUCCESS

#### FGdmaAppendBDLEntry

```c
FError FGdmaAppendBDLEntry(FGdmaChan *const chan_p, uintptr src_addr, uintptr dst_addr, fsize_t data_len)
```

Note:

- BDL

Input:

- FGdmaBdlDesc *desc_entry, BDL
- uintptr src_addr, 
- uintptr dst_addr, 
- fsize_t data_len, 

Return:

- {FError} FGDMA_SUCCESS 

#### FGdmaBDLTransfer

```c
FError FGdmaBDLTransfer(FGdmaChan *const chan_p)
```

Note:

- BDLDMA

Input:

- FGdmaChan *const chan_p, DMA

Return:

- {FError} FGDMA_SUCCESS 

#### FGdmaStart

```c
FError FGdmaStart(FGdma *const instance_p)
```

Note:

- GDMA
- FGdmaAllocateChan

Input:

- FGdma *const instance_p, GDMA

Return:

- {FError} FGDMA_SUCCESS

#### FGdmaStop

```c
FError FGdmaStop(FGdma *const instance_p)
```

Note:

- GDMA

Input:

- FGdma *const instance_p, GDMA

Return:

- {FError} FGDMA_SUCCESS

#### FGdmaIrqHandler

```c
void FGdmaIrqHandler(s32 vector, void *args)
```

Note:

- GDMA

Input:

- {s32} vector, 
- {void} *args, 

Return:

- 

#### FGdmaChanRegisterEvtHandler

```c
void FGdmaChanRegisterEvtHandler(FGdmaChan *const chan_p, FGdmaChanEvtType evt, 
                                 FGdmaChanEvtHandler handler, void *handler_arg)
```

Note:

- GDMA

Input:

- {FGdmaChan} *chan_p, GDMA
- {FGdmaChanEvtType} evt, 
- {FGdmaChanEvtHandler} handler, 
- {void} *handler_arg, 

Return:

- 
