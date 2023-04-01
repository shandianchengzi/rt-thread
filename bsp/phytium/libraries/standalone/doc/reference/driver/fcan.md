# FCAN 

## 1. 

CAN (Controller Area Network)BOSCH(ISO 11898)

## 2. 

CANCAN
- CAN
- /
- /


```
.
 fcan_g.c
 fcan_hw.c
 fcan_hw.h
 fcan_intr.c
 fcan_sinit.c
 fcan.c
 fcan.h
```

## 3. 

 fcan :

- CAN
- CAN

## 4 

### [can](../../../baremetal/example/peripheral/can)

## 5. API

### 5.1. 

- fcan

```c
typedef struct
{
    FCanConfig config;
    u32 is_ready;  /* Device is initialized and ready */
    boolean use_canfd; /* if use canfd function */
    
    FCanIntrEventConfig intr_event[FCAN_INTR_EVENT_NUM];/* event handler and parameters for interrupt */
} FCanCtrl;
```

- fcanFCanConfigcanidFCanIntrEventConfig

```c
typedef struct
{
    u32 instance_id;   /* Id of device */
    uintptr base_address; /* Can base Address */
    u32 irq_num;    /* interrupt number */
    u32 irq_prority;/* interrupt priority*/
}FCanConfig;
```

- fcan
```c
typedef struct
{
    FCanSegmentType segment;
    boolean auto_calc; /* if auto calculate baudrate parameters */
    u32 baudrate;     /* baudrate */
    u32 sample_point; /* sample point */
    u32 prop_seg;     /* Propagation segment in TQs */
    u32 phase_seg1;   /* Phase buffer segment 1 in TQs */
    u32 phase_seg2;   /* Phase buffer segment 2 in TQs */
    u32 sjw;          /* Synchronisation jump width in TQs */
    u32 brp;          /* Baudrate prescaler */
}FCanBaudrateConfig;
```

- fcan
```c
typedef struct
{
    u32 canid;
    u8 candlc;
    u8 flags; /* additional flags for CAN FD */
    u8 data[FCAN_DATA_LENGTH] __attribute__((aligned(8)));
}FCanFrame;
```

- fcan
```c
typedef enum
{
    FCAN_INTR_EVENT_SEND = 0,    /* Handler type for frame sending interrupt */
    FCAN_INTR_EVENT_RECV = 1,    /* Handler type for frame reception interrupt */
    FCAN_INTR_EVENT_ERROR,       /* Handler type for error interrupt */
    FCAN_INTR_EVENT_NUM
} FCanIntrEventType;
```

### 5.2  

- FCAN_SUCCESS      
- FCAN_NOT_READY    
- FCAN_FAILURE      
- FCAN_INVAL_PARAM  

### 5.3. API

#### FCanLookupConfig

- Fata

```c
const FCanConfig *FCanLookupConfig(FCanInstance instance_id);
```

Note:

- 

Input:

- {FCanInstance} instance_idid

Return:

- {const FCanConfig *} fcanNULL

#### FCanCfgInitialize

- fcan, 

```c
FError FCanCfgInitialize(FCanCtrl *instance_p, const FCanConfig *input_config_p);
```

Note:

- FCanLookupConfig

Input:

- {FCanCtrl} *instance_p fcan
- {FCanConfig} *input_config_p fcan

Return:

- {FError} FCAN_SUCCESS 

#### FCanSend

- can

```c
FError FCanSend(FCanCtrl *instance_p, FCanFrame *frame_p);
```

Note:

- cancan

Input:

- {FCanCtrl} *instance_pfcan
- {FCanFrame} *frame_pcan

Return:

- {FError} FCAN_SUCCESS 

#### FCanRecv

- can

```c
FError FCanRecv(FCanCtrl *instance_p, FCanFrame *frame_p);
```

Note:

- cancan

Input:

- {FCanCtrl} *instance_pfcan
- {FCanFrame} *frame_pcan

Return:

- {FError} FCAN_SUCCESS 

#### FCanRegisterInterruptHandler

- can

```c
void FCanRegisterInterruptHandler(FCanCtrl *instance_p, FCanIntrEventConfig *intr_event_p);
```

Note:
- 

Input:
- {FCanCtrl} *instance_pfcan
- {FCanIntrEventConfig} *intr_event_p

Return:
- 

#### FCanIntrHandler

- can

```c
void FCanIntrHandler(s32 vector, void *args);
```

Note:
- 

Input:
- {s32} vector
- {void} *param, fcan

Return:
- 

#### FCanIdMaskFilterSet

- can id

```c
FError FCanIdMaskFilterSet(FCanCtrl *instance_p, FCanIdMaskConfig *id_mask_p);
```

Note:
- id

Input:
- {FCanCtrl} *instance_p, fcan
- {FCanIdMaskConfig} *id_mask_p, idid

Return:
- {FError} FCAN_SUCCESS 