# FGMAC 

## 1. 

GMAC IEEE802.3-2005  RGMII  PHY 

GMAC 
-  1000Mbps/100Mbps/10Mbps
-  IEEE 802.3-2005 Ethernet MACReduced Gigabit Media Independent Interface (RGMII)

## 2. 

FGMAC /PHY

FGMAC 

```
 Kconfig
 fgmac.c 
 fgmac.h
 fgmac_dma.c
 fgmac_g.c
 fgmac_hw.c
 fgmac_hw.h
 fgmac_intr.c
 fgmac_sinit.c
 phy
     ar803x
      fgmac_ar803x.c
      fgmac_ar803x.h
     fgmac_phy.c
     fgmac_phy.h
```

## 3. 

 FGMAC /:

-  GMAC 
-  API GMAC 
-  GMAC API GMAC 
- API PHY 
-  PHY API PHY 
-  GMAC  DMA  DMA  API 
-  API /

LWIP

## 4 

### [fgmac_link](../../../baremetal/example/fgmac_link/README.md)

GMAC

### [fgmac_lwip_echo](../../../baremetal/example/fgmac_lwip_echo/README.md)

LWIPFGMACping

### [fgmac_lwip_tftp](../../../baremetal/example/fgmac_lwip_tftp/README.md)

LWIPFGMACtftp

## 5. API

### 5.1. 

- FGMAC 
```c
typedef struct
{
    u32     instance_id;  /* device instance id */
    uintptr base_addr;    /* device base address */
    u32     irq_num;      /* irq num */
    u32     cheksum_mode; /* hardware or software checksum */
    u32     duplex_mode;         /* selects the MAC duplex mode: Half-Duplex or Full-Duplex mode */    
    u32 max_packet_size;  /* max num of bytes in frame transfer */
    u32     mdc_clk_hz;          /* MDC clock access PHY. [1.0MHz ~2.5MHz] */
    boolean en_auto_negtiation;  /* auto-negotiation or not */
    u32     speed;               /* sets the Ethernet speed: 10/100/1000 Mbps.*/
  
} FGmacConfig; /* FGMAC  */
```

- FGMAC 
```c

typedef struct
{
    FGmacConfig config;      /* Current active configs */
    u32         is_ready;    /* Device is initialized and ready */
    FGmacRingDescData rx_ring;  /* RX DMA descriptor data (idx, length) */
    volatile FGmacDmaDesc *rx_desc;  /* RX DMA descriptor table in ring */
    FGmacRingDescData tx_ring; /* TX DMA descriptor data (idx, length) */
    volatile FGmacDmaDesc *tx_desc; /* TX DMA descriptor table in ring */
    FGmacEvtHandler evt_handler[FGMAC_INTR_EVT_NUM]; /* User registered interrupt handler */
    u32 phy_valid_mask; 
    u32 phy_speed;
    u32 phy_addr;            /* phy ic addr */
} FGmac; /* FGMAC  */
```

- FGMAC DMA

```c
typedef struct
{
    volatile u32 status;
    u32 ctrl;
    u32 buf_addr;
    u32 next;
} FGmacDmaDesc; 
```

- FGMAC DMA()
```c
typedef struct
{
    u32 desc_idx;       /* For Current Desc position */
    u32 desc_buf_idx;   /* For Current Desc buffer buf position */
    u32 desc_max_num;   /* Max Number for  Desc and Desc buffer */
    u8 *desc_buf_base;  /*  Desc buffer Base */
} FGmacRingDescData; 
```

- FGMAC 
```c
enum
{
    FGMAC_CHECKSUM_BY_SOFTWARE = 0,
    FGMAC_CHECKSUM_BY_HARDWARE
}; 
```

- FGMAC 
```c
enum
{
    FGMAC_TX_COMPLETE_EVT = 0,
    FGMAC_RX_COMPLETE_EVT,
    FGMAC_LINK_STATUS_EVT,
    FGMAC_PHY_STATUS_EVT,
    FGMAC_DMA_ERR_EVT,

    FGMAC_INTR_EVT_NUM
};
```

### 5.2  

- 0x1070000
- [0x0] FGMAC: Success
- [0x1070001] FGMAC: wait timeout
- [0x1070002] FGMAC: DMA address invalid
- [0x1070003] FGMAC: driver not ready
- [0x1070004] FGMAC: data transaction failed
- [0x1070005] FGMAC: PHY type not support
- [0x1070006] FGMAC: PHY is not found

### 5.3. API

#### FGmacLookupConfig

- FGMAC

```c
const FGmacConfig *FGmacLookupConfig(u32 instance_id);
```

Note:

- FGMAC
- instance_id

Input:

- {u32} instance_id, 

Return:

- {const FGmacConfig *}, 
#### FGmacCfgInitialize

- FGMAC

```c
FError FGmacCfgInitialize(FGmac *instance_p, const FGmacConfig *cofig_p);
```

Note:

- FGMACFGMAC

Input:

- {FGmac} *instance_p 

- {FGmacConfig} *cofig_p 

Return:

- {FError} FGMAC_SUCCESS 

#### FGmacDeInitialize

- FGMAC

```c
FError FGmacDeInitialize(FGmac *instance_p);
```

Note:

- FGMAC

Input:

- {FGmac} *instance_p 

Return:

- {FError} FGMAC_SUCCESS 

#### FGmacSetupTxDescRing

- FGMACDMA

```c
FError FGmacSetupTxDescRing(FGmac *instance_p, volatile FGmacDmaDesc *tx_desc_tbl, u8 *tx_buf, const fsize_t tx_pre_buf_len, const fsize_t tx_buf_num);
```

Note:

- tx_desc_tbltx_buf32

Input:

- {FGmac *}instance_p 

- {volatile FGmacDmaDesc *} tx_desc_tbl DMA()

- {u8} *tx_buf DMA()

- {const fsize_t} tx_pre_buf_len DMA

- {const fsize_t} tx_buf_num DMADMA

Return:

- {FError} TX DMAFGMAC_SUCCESS TX DMATX DMA

#### FGmacSetupRxDescRing

- FGMACDMA

```c
FError FGmacSetupRxDescRing(FGmac *instance_p, volatile FGmacDmaDesc *rx_desc_tbl, u8 *rx_buf, const fsize_t rx_pre_buf_len, const fsize_t rx_buf_num);
```

Note:

- rx_desc_tblrx_buf32

Input:

- {FGmac *}instance_p 
- {volatile FGmacDmaDesc *} rx_desc_tbl DMA()
- {u8} *rx_buf DMA()
- {const fsize_t} rx_pre_buf_len DMA
- {const fsize_t} rx_buf_num DMADMA

Return:

- {FError} RX DMAFGMAC_SUCCESS RX DMARX DMA

#### FGmacInterruptHandler

- FGMAC

```c
void FGmacInterruptHandler(s32 vector, void *param);
```

Note:

- 

Input:

- {s32} vector, 
- {void} *param, FGMAC

Return:



#### FGmacRegisterEvtHandler

- FGMAC

```c
void FGmacRegisterEvtHandler(FGmac *instance_p, u32 evt, FGmacEvtHandler handler);
```

Note:

- handler

Input:

- {FGmac} *instance_p 
- {u32} evt 
- {FGmacEvtHandler} handler 

Return:



#### FGmacStartTrans

- FGMAC DMA/

```c
FError FGmacStartTrans(FGmac *instance_p);
```

Note:

- FGMAC

Input:

- {FGmac} *instance_p 

Return:

- {FError} FGMAC_SUCCESS 

#### FGmacStopTrans

- FGMAC DMA, /

```c
FError FGmacStopTrans(FGmac *instance_p);
```

Note:

- FGMAC

Input:

- {FGmac} *instance_p 

Return:

- {FError} FGMAC_SUCCESS 

#### FGmacRecvFrame

- FGMAC

```c
FError FGmacRecvFrame(FGmac *instance_p)
```

Note:

- FGMAC

Input:

- {FGmac} *instance_p 

Return:

- {FError} FGMAC_SUCCESS 

#### FGmacSendFrame

- FGMAC

```c
FError FGmacSendFrame(FGmac *instance_p, u32 frame_len);
```

Note:

- FGMAC

Input:

- {FGmac} *instance_p 

- {u32} frame_len 

Return:

- {FError} FGMAC_SUCCESS 


#### FGmacPhyLookupConfig

- FGMAC PHY 

```c
void FGmacPhyLookupConfig(u32 gmac_instance_id, FGmac *instance_p);
```

Note:

 FGMAC 

Input:

- {u32} gmac_instance_id FGMAC id
- {FGmac} *instance_p FGMAC 

Return:



#### FGmacPhyCfgInitialize

- GMACphyFGMAC PHY

```c
FError FGmacPhyCfgInitialize(FGmac *instance_p);
```

Note:

-  FGMAC 

Input:

- {FGmac} *instance_p GMAC

Return:

- {FError} FGMAC_SUCCESS PHYPHY

#### FGmacSetInterruptMask

- FGMAC

```c
void FGmacSetInterruptMask(FGmac *instance_p, u32 intr_type, u32 mask, boolean enable);
```

Note:

- FGMAC

Input:

- {FGmac} *instance_p 

- {u32} intr_type  GMAC/DMA

- {u32} mask 

- {boolean} enable TRUE: FALSE: 

Return:


