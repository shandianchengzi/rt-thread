# FSPIM 

## 1. 


- SPI 4SPI 4 MISOMOSISCLKCS

- CSSCLKSDISDO

- FT2000/4D2000SPI

- FT2000/4D2000 2  SPI  SPI  4  SPI 


## 2. 


- 
- drivers/spi/fspim

```
.
 fspim.c
 fspim.h
 fspim_g.c
 fspim_hw.c
 fspim_hw.h
 fspim_intr.c
 fspim_options.c
 fspim_sinit.c
```

- FSPIM Nor-flash SPI  Nor-flash,  FSPIM  SFUD  Spi Nor-flashSPI LittleFS  SPIFFS/`4 ` 

![spi_app](./figs/spi_app.png)

## 3. 


 FSPIM :

### 3.1  SFUD SPI

-  CONFIG_USE_FSPIM  CONFIG_USE_SFUD 
-  SFUD 
-  SFUD  API  SPI 

 SFUD [sfud.md](./sfud.md)

### 3.2  SFUD SPI

-  CONFIG_USE_FSPIM 
-  FSPIM 
-  FSPIM  API  SPI  SPI 

## 4 

### [SPI ](../../../baremetal/example/peripheral/spi/fspim_loopback/README.md)

### [SPI Norflash](../../../baremetal/example/storage/spi_sfud/README.md)

### [SPI Norflash-LittleFS](../../../baremetal/example/storage/littlefs_test/README.md)

### [SPI Norflash-SPIFFS](../../../baremetal/example/storage/spiffs_test/README.md)

## 4. API

### 4.1 

- SPIM 
```c
typedef struct
{
    u32                  instance_id;  /* Device instance id */
    uintptr              base_addr;    /* Device base address */
    u32                  irq_num;      /* Device intrrupt id */
    u32                  irq_prority;  /* Device intrrupt priority */    
    FSpimSlaveDevice     slave_dev_id; /* Slave device id */
    u32                  max_freq_hz;  /* Clock frequency in Hz */
    FSpimTransByte       n_bytes;      /* Bytes in transfer */
    FSpimCpolType        cpol;         /* Polarity of the clock */
    FSpimCphaType        cpha;         /* Phase of the clock */
    boolean              en_test;      /* Enable test mode */
} FSpimConfig;
```

- SPIM 
```c
typedef struct
{
    FSpimConfig         config;      /* Current active configs */
    u32                 is_ready;    /* Device is initialized and ready */
    u32                 length;      /* Data length in transfer */
    const void          *tx_buff;    /* Tx buffer beg */
    void                *rx_buff;    /* Rx buffer beg */
    const void          *tx_buff_end; /* Tx buffer end */
    void                *rx_buff_end; /* Rx buffer end */
    u32                 tx_fifo_len;  /* Depth of tx fifo */
    u32                 rx_fifo_len;  /* Depth of rx fifo */
    FSpimEvtHandler     evt_handler[FSPIM_INTR_EVT_NUM];  /* event handler for interrupt */
    void                *evt_param[FSPIM_INTR_EVT_NUM];   /* parameters ptr of event handler */
} FSpim;
```

- SPI ID4
```c
enum
{
    FSPIM_SLAVE_DEV_0 = 0,
    FSPIM_SLAVE_DEV_1,
    FSPIM_SLAVE_DEV_2,
    FSPIM_SLAVE_DEV_3,

    FSPIM_NUM_OF_SLAVE_DEV
};
```

-  SPI 
```c
enum
{
    FSPIM_1_BYTE = 1,
    FSPIM_2_BYTE = 2,

    FSPIM_MAX_BYTES_NUM
};
```

- SPI/
```c
enum
{
    FSPIM_TRANS_MODE_RX_TX = 0x0,
    FSPIM_TRANS_MODE_TX_ONLY = 0x1,
    FSPIM_TRANS_MODE_RX_ONLY = 0x2,
    FSPIM_TRANS_MODE_READ_EEPROM = 0x3,

    FSPIM_TRANS_MODE_MAX
};
```

- SPI
```c
enum
{
    FSPIM_CPOL_LOW  = 0,
    FSPIM_CPOL_HIGH
};

enum
{
    FSPIM_CPHA_1_EDGE = 0,
    FSPIM_CPHA_2_EDGE
};
```

### 4.2 

- 0x1060000
- [0x0] FSPIM_SUCCESS : fspim success
- [0x1060000] FSPIM_SUCCESS : fspim success
- [0x1060001] FSPIM_ERR_INVAL_STATE : fspim invalid state
- [0x1060002] FSPIM_ERR_NOT_READY : fspim driver not ready
- [0x1060003] FSPIM_ERR_INVAL_PARAM : fspim invalid input parameters
- [0x1060004] FSPIM_ERR_BUS_BUSY : fspim bus is busy
- [0x1060005] FSPIM_ERR_NOT_SUPPORT : fspim not support operation
- [0x1060006] FSPIM_ERR_TIMEOUT : fspim wait timeout

### 4.3 API

#### FSpimLookupConfig

- FSPIM

```c
const FSpimConfig *FSpimLookupConfig(u32 instance_id)
```

Note:

- `FSpimCfgInitialize`

Input:

- u32 instance_id, FSPIM

Return:

- const FSpimConfig *, NULL


#### FSpimCfgInitialize

- FSPIM

```c
FError FSpimCfgInitialize(FSpim *instance_p, const FSpimConfig *cofig_p);
```

Note:

- FSPIMFSPIM

Input:

- FSpim *instance_p, FSPIM

- const FSpimConfig *input_config_p, FSPIM

Return:

- FError, FSPIM_SUCCESS 

#### FSpimDeInitialize

- FSPIM

```c
void FSpimDeInitialize(FSpim *instance_p)
```

Note:

- FSPIM

Input:

- FSpim *instance_p, FSPIM

Return:



#### FSpimTransferPollFifo
-  ()Fifo

```c
FError FSpimTransferPollFifo(FSpim *instance_p, const void *tx_buf, void *rx_buf, fsize_t len);
```

Note:

- FSPIM
- TX FIFOTX FIFO/

Input:

- FSpim *instance_p, FSPIM

- const void *tx_buf, 0xff

- void *rx_buf, , SPI

- fsize_t len, tx_bufrx_bufbuflen

Return:

- FError, FSPIM_SUCCESS 

#### FSpimTransferByInterrupt

-  ()Fifo

```c
FError FSpimTransferByInterrupt(FSpim *instance_p, const void *tx_buf, void *rx_buf, fsize_t len);
```

Note:

- FSPIM
- TX FIFOTX FIFO/FSPIM_INTR_EVT_RX_DONEtx_bufrx_buf

Input:

- FSpim *instance_p, FSPIM

- const void *tx_buf, 0xff

- void *rx_buf, , SPI

- fsize_t len, tx_bufrx_bufbuflen

Return:

- FError, FSPIM_SUCCESS 

#### FSpimInterruptHandler

- SPIM 

```c
void FSpimInterruptHandler(s32 vector, void *param);
```

Note:

- 
- 

Input:

- s32 vector, 

- void *param, , FSPIM

Return:



#### FSpimRegisterIntrruptHandler
- SPIM

```c
void FSpimRegisterIntrruptHandler(FSpim *instance_p, u32 evt, FSpimEvtHandler handler, void *param)
```

Note:

- FSpimInterruptHandler

Input:

- FSpim *instance_p, FSPIM

- u32 evt, FSPIM_INTR_EVT_NUM

- FSpimEvtHandler handler, 

- void *param, 

Return:



#### FSpimErrorToMessage

- FSPIM 

```c
const char *FSpimErrorToMessage(FError error);
```

Note:



Input:

- FError error, FSPIM

Return:

const char *, FSPIM

#### FSpimSetChipSelection

- FSPIM 

```c
void FSpimSetChipSelection(FSpim *instance_p, boolean on);
```

Note:



Input:

- {FSpim} *instance_p, 
- {boolean} on, TRUE: , FALSE: 

Return:

- 
