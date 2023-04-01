# FDDMA 

## 1. 

DDMA(Device Direct Memory Access)E2000DMADMADMA

## 2. 

FDDMA  DDMA DDMA

```
fddma
    .
     fddma.c
     fddma.h
     fddma_g.c
     fddma_hw.c
     fddma_hw.h
     fddma_intr.c
     fddma_selftest.c
     fddma_sinit.c
```

## 3. 

 FDDMA :

-  DDMA 
-  DDMA 
-  DDMA  

## 4 

### [DDMASPI](../../../baremetal/example/peripheral/dma/fddma_spi)

## 5. API

### 5.1. 

#### FDdmaConfig

- DDMA 

```c
typedef struct
{
    u32 id;                     /* DDMA ctrl id */
    uintptr base_addr;          /* DDMA ctrl base address */
    u32 irq_num;                /* DDMA ctrl interrupt id */
    u32 irq_prority;            /* DDMA ctrl interrupt priority */
} FDdmaConfig; /* DDMA instance configuration */
```

#### FDdmaChanConfig

- DDMA 

```c
typedef struct
{
    FDdmaChanIndex id;          /* DMA channel index */
    u32 slave_id;               /* Perpherial slave id for DDMA */
    FDdmaChanRequst req_mode;   /* DMA transfer direction */
    uintptr ddr_addr;           /* DMA channel DDR address, could be source or destination */
    u32 dev_addr;               /* DMA channel Perpherial, could be source or destination */
    u32 trans_len;              /* DMA channel transfer length */
#define FDDMA_MAX_TRANSFER_LEN      64 /* max bytes in transfer */
#define FDDMA_MIN_TRANSFER_LEN      4  /* min bytes in transfer */
    u32 timeout;                /* timeout = 0 means no use DMA timeout */
} FDdmaChanConfig;  /* DDMA channel instance */
```

#### FDdmaChan

- DDMA 

```c
typedef struct FDdmaChan_
{
    FDdmaChanConfig config; /* DDMA channel configuration */
    boolean is_used;        /* TRUE means channel is in use */
    FDdma *dma;             /* DMA instance of this channel */
    FDdmaChanEvtHandler evt_handler[FDDMA_NUM_OF_CHAN_EVT]; /* interrupt evt */
    void *evt_handler_args[FDDMA_NUM_OF_CHAN_EVT]; /* interrupt evt args */
} FDdmaChan; /* DDMA channel instance */
```

#### FDdma

- DDMA 

```c
typedef struct FDdma_
{
    FDdmaConfig config;  /* DDMA instance configuration */
    FDdmaChan   *chan[FDDMA_NUM_OF_CHAN];  /* DDMA channel instance, NULL means channel not yet allocate */
    u32 is_ready;        /* TRUE means DDMA init ok */
    u32 bind_status;     /* channel bind status, BIT(n) = 1 means channel n is allocated */
} FDdma; /* DDMA instance */
```

### 5.2  


- FDDMA_SUCCESS                   :   
- FDDMA_ERR_NOT_INIT              
- FDDMA_ERR_CHAN_BINDED           
- FDDMA_ERR_CHAN_RUNNING          : 
- FDDMA_ERR_INVALID_TRANS_SIZE    : DMA
- FDDMA_ERR_WAIT_TIMEOUT          : DMA
- FDDMA_ERR_INVALID_DDR_ADDR      : DMA

### 5.3. API

#### FDdmaLookupConfig


```c
const FDdmaConfig *FDdmaLookupConfig(u32 instance_id);
```

Note:

- DDMA 

Input:

- {u32} instance_id, DDMA

Return:

- {const FDdmaConfig *} DDMA

#### FDdmaCfgInitialization


```c
FError FDdmaCfgInitialization(FDdma *const instance, const FDdmaConfig *input_config);
```

Note:

- DDMA

Input:

- {FDdma} *instance, DDMA
- {FDdmaConfig} *input_config, DDMA

Return:

- {FError} FDDMA_SUCCESS

#### FDdmaDeInitialization


```c
void FDdmaDeInitialization(FDdma *const instance);
```

Note:

- DDMA

Input:

- {FDdma} *instance, DDMA

Return:

- 

#### FDdmaAllocateChan

```c
FError FDdmaAllocateChan(FDdma *const instance, FDdmaChan *const dma_chan, const FDdmaChanConfig *dma_chan_config);
```

Note:

- DDMA

Input:

- {FDdma} *instance, DDMA
- {FDdmaChan} *dma_chan, DDMA
- {FDdmaChanConfig} *dma_chan_config, DDMA

Return:

- {FError} FDDMA_SUCCESS

#### FDdmaDellocateChan

```c
FError FDdmaDellocateChan(FDdmaChan *const dma_chan);
```

Note:

- DDMA

Input:

- {FDdmaChan} *dma_chan, DDMA

Return:

- {FError} FDDMA_SUCCESS

#### FDdmaStart

```c
FError FDdmaStart(FDdma *const instance);
```

Note:

- DDMA

Input:

- {FDdma} *instance, DDMA

Return:

- {FError} FDDMA_SUCCESS

#### FDdmaStop

```c
FError FDdmaStop(FDdma *const instance);
```

Note:

- DDMA

Input:

- {FDdma} *instance, DDMA

Return:

- {FError} FDDMA_SUCCESS

#### FDdmaIrqHandler

```c
void FDdmaIrqHandler(s32 vector, void *args)
```

Note:

- DDMA 

Input:

- {s32} vector
- {void} *param, 

Return:

- 

#### FDdmaRegisterChanEvtHandler

```c
void FDdmaRegisterChanEvtHandler(FDdmaChan *const dma_chan,
                                 FDdmaChanEvt evt, 
                                 FDdmaChanEvtHandler handler, 
                                 void *handler_arg);
```

Note:

- DDMA 

Input:

- {FDdmaChan} *dma_chan, DDMA
- {FDdmaChanEvt} evt, 
- {FDdmaChanEvtHandler} handler, 
- {void} *handler_arg, 

Return:

- 