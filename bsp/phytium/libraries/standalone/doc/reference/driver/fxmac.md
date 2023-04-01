<!--
 * Copyright : (C) 2022 Phytium Information Technology, Inc. 
 * All Rights Reserved.
 *  
 * This program is OPEN SOURCE software: you can redistribute it and/or modify it  
 * under the terms of the Phytium Public License as published by the Phytium Technology Co.,Ltd,  
 * either version 1.0 of the License, or (at your option) any later version. 
 *  
 * This program is distributed in the hope that it will be useful,but WITHOUT ANY WARRANTY;  
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the Phytium Public License for more details. 
 *  
 * 
 * FilePath: fxmac.md
 * Date: 2022-07-12 15:31:05
 * LastEditTime: 2022-07-12 15:31:05
 * Description:  This file is for 
 * 
 * Modify History: 
 *  Ver   Who  Date   Changes
 * ----- ------  -------- --------------------------------------
-->
# FXMAC 

## 1. 

XMAC IEEE802.3 standard  SGMII/RGMII  PHY 

XMAC 
-  1000Mbps/100Mbps/10Mbps
-  Reduced Gigabit Media Independent Interface (RGMII)
-  SGMII Serial Gigabit Media-Independent Interface SGMII

## 2. 

XMAC DMA PHY 

XMAC 

```
.
 fxmac_bd.h
 fxmac_bdring.c
 fxmac_bdring.h
 fxmac.c
 fxmac_g.c
 fxmac.h
 fxmac_hw.h
 fxmac_intr.c
 fxmac_options.c
 fxmac_phy.c
 fxmac_phy.h
 fxmac_sinit.c
 Kconfig
 phy
     eth_ieee_reg.h
     yt
         phy_yt.c
         phy_yt.h
```

- fxmac.h/fxmac.c 
1. mac 
2. 4mac
3. 4mac
4. phy 
5. 

- fxmac_bdring.h/fxmac_bdring.c 
1.  dma 
2.  
3.  
4.  



## 4 

### [fgmac_lwip_echo](../../../baremetal/example/fgmac_lwip_echo/README.md)

- LWIPFXMACping

### [lwip port](../../../third-party/lwip-2.1.2/ports/fxmac/)

- fxmac lwip 

## 5. API

### 5.1. 

- FXMAC 
```c
    typedef struct
    {
        u32 instance_id; /* Id of device*/
        volatile uintptr_t base_address;
        volatile uintptr_t extral_mode_base;
        volatile uintptr_t extral_loopback_base;
        FXmacPhyInterface interface; /* SGMII/RGMII  */
        u32 speed;    /* FXMAC_SPEED_XXX */
        u32 duplex;   /* 1 is full-duplex , 0 is half-duplex */
        u32 auto_neg; /* Enable auto-negotiation - when set active high, autonegotiation operation is enabled. */
        u32 pclk_hz;
        u32 max_queue_num; /* Number of Xmac Controller Queues  */
        u32 tx_queue_id;   /* 0 ~ FT_XMAC_QUEUE_MAX_NUM ,Index queue number */
        u32 rx_queue_id;   /* 0 ~ FT_XMAC_QUEUE_MAX_NUM ,Index queue number */
        u32 hotplug_irq_num;
        u32 dma_brust_length; /*  burst length */
        u32 network_default_config; /* mac  */
        u32 queue_irq_num[FT_XMAC_QUEUE_MAX_NUM]; /* mac0 8  4 */
    } FXmacConfig;
```

- FGMAC 
```c
    typedef struct
    {
        FXmacConfig config;
        u32 is_ready; /* Device is ininitialized and ready*/
        u32 is_started; 
        u32 link_status; /* indicates link status ,FXMAC_LINKUP is link up ,FXMAC_LINKDOWN is link down,FXMAC_NEGOTIATING is need to negotiating*/
        u32 options;

        FXmacQueue tx_bd_queue; /* Transmit Queue */
        FXmacQueue rx_bd_queue; /* Receive Queue */

        FXmacIrqHandler send_irq_handler;
        void *send_args;

        FXmacIrqHandler recv_irq_handler;
        void *recv_args;

        FXmacErrorIrqHandler error_irq_handler;
        void *error_args;

        FXmacIrqHandler link_change_handler;
        void *link_change_args;

        FXmacIrqHandler restart_handler;
        void *restart_args;

        u32 moudle_id; /* Module identification number */
        u32 max_mtu_size;
        u32 max_frame_size;

        u32 phy_address;                    /* phy address */
        u32 rxbuf_mask; /* Filter length */ /* 1000,100,10 */

    } FXmac;
```

- FGMAC DMA

```c
    typedef struct
    {
        uintptr phys_base_addr; /* Physical address of 1st BD in list */
        uintptr base_bd_addr;   /* Virtual address of 1st BD in list */
        uintptr high_bd_addr;   /* Virtual address of last BD in the list */
        u32 length;             /* Total size of ring in bytes */
        u32 run_state;          /* Flag to indicate DMA is started */
        u32 separation;         /* Number of bytes between the starting address
                                  of adjacent BDs */
        FXmacBd *free_head;
        /* First BD in the free group */
        FXmacBd *pre_head; /* First BD in the pre-work group */
        FXmacBd *hw_head;  /* First BD in the work group */
        FXmacBd *hw_tail;  /* Last BD in the work group */
        FXmacBd *post_head;
        /* First BD in the post-work group */
        FXmacBd *bda_restart;
        /* BDA to load when channel is started */

        volatile u32 hw_cnt; /* Number of BDs in work group */
        u32 pre_cnt;         /* Number of BDs in pre-work group */
        u32 free_cnt;        /* Number of allocatable BDs in the free group */
        u32 post_cnt;        /* Number of BDs in post-work group */
        u32 all_cnt;         /* Total Number of BDs for channel */
    } FXmacBdRing;
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


### 5.2  

- 0x1070000
- [0x0] FGMAC: Success
- FXMAC_ERR_INVALID_PARAM : Invalid parameter
- FXMAC_ERR_SG_LIST : dma ring out of sequence
- FXMAC_ERR_GENERAL :the number of BDs to allocate greater that the number of BDs in the preprocessing state.
- FXMAC_ERR_SG_NO_LIST : dma ring is not allocated
- FXMAC_ERR_PHY_BUSY  : if there is another PHY operation in progress
- FXMAC_PHY_IS_NOT_FOUND : phy is not found
- FXMAC_PHY_AUTO_AUTONEGOTIATION_FAILED : PHY autonegotiation is error
- FXMAC_ERR_MAC_IS_PROCESSING : MAC controllers are enabled together. As a result, some operations cannot be mirrored


### 5.3 

1. FXmacLookupConfig 
2.   phy interface 
3. mac 
4. phy 
5. mac 
6. dma 
7. mac mac 


### 5.4. API

#### FXmacLookupConfig

- FXMAC

```c
const FXmacConfig *FXmacLookupConfig(u32 instance_id);
```

Note:

- FXMAC
- instance_id

Input:

- {u32} instance_id, 

Return:

- {const FXmacConfig *}, 
#### FXmacCfgInitialize

- FGMAC

```c
FError FXmacCfgInitialize(FXmac *instance_p, const FXmacConfig *config_p)
```

Note:

- FGMACFGMAC

Input:

- {FXmac} *instance_p MAC 

- {FXmacConfig} *cofig_p 

Return:

- {FError} FGMAC_SUCCESS 

#### FXmacInitInterface

- phy  mac 

```c
void FXmacInitInterface(FXmac *instance_p)
```

Note:
-  PHY PHY

Input:
- {FXmac}     *instance_p MAC 

#### FXmacGetMacAddress

- index mac 

```c
void FXmacGetMacAddress(FXmac *instance_p, u8 *address_ptr, u8 index)
```

Input :

- {FGmac} *instance_p MAC 
- {u8}  index MAC(0-3)

Output :
- {u8}  *address_ptr MAC


#### FXmacSetMacAddress

- index mac 

```c
FError FXmacSetMacAddress(FXmac *instance_p, u8 *address_ptr, u8 index);
```

Input :

- {FGmac} *instance_p MAC 
- {u8}  *address_ptr MAC
- {u8}  index MAC(0-3)

Output :

- {FError} FT_SUCCESS MAC

#### FXmacSetOptions

- FXmac 

```c
FError FXmacSetOptions(FXmac *instance_p, u32 options, u32 queue_num)
```

Note:
- mac 

Input:
- {FGmac} *instance_p MAC 
- {u32} options   fxmac.h  FXMAC_****_OPTION 
- {u32} queue_num mac FXMAC_JUMBO_ENABLE_OPTION 

Return:
- {FError} FT_SUCCESS 

#### FXmacClearOptions

- FXmac 

```c
FError FXmacClearOptions(FXmac *instance_p, u32 options, u32 queue_num)
```

Note:
- mac 

Input:
- {FGmac} *instance_p MAC 
- {u32} options   fxmac.h  FXMAC_****_OPTION 
- {u32} queue_num mac FXMAC_JUMBO_ENABLE_OPTION 

Return:
- {FError} FT_SUCCESS 

#### FXmacStart

- 

```c
void FXmacStart(FXmac *instance_p)
```

note:

-  network_default_config  FXMAC_TRANSMIT_ENABLE_OPTION  
FXMAC_RECEIVER_ENABLE_OPTION 

Input:

- {FGmac} *instance_p MAC 


#### FXmacStop

- 

```c
void FXmacStop(FXmac *instance_p)
```

note:
- 

Input:

- {FGmac} *instance_p MAC 


#### FXmacSetQueuePtr

- mac / 

```c
void FXmacSetQueuePtr(FXmac *instance_p, uintptr queue_p, u8 queue_num,
                      u32 direction)
```

Note:
- 128bit 

Input:

- {FXmac} *instance_p MAC 
- {uintptr} queue_p 
- {u8} queue_num 
- {u32} direction  FXMAC_SEND  FXMAC_RECV 


#### FXmacPhyWrite

- PHY

```c
FError FXmacPhyWrite(FXmac *instance_p, u32 phy_address,
                     u32 register_num, u16 phy_data)
```

Note: 
-   

Input:
- {FXmac} *instance_p MAC 
- {u32} phy_address PHY
- {u32} register_num PHYPHY0-31 
- {u16} phy_data PHY  register_num 

Return:

- {FError} FT_SUCCESS PHY 


#### FXmacPhyRead

- PHY 

```c
FError FXmacPhyRead(FXmac *instance_p, u32 phy_address,
                    u32 register_num, u16 *phydat_aptr)
```

Note:

-   

Input:
- {FXmac} *instance_p MAC 
- {u32} phy_address PHY
- {u32} register_num PHYPHY0-31 

Output:
- {u16} *phydat_aptr  PHY  register_num
  
Return:

- {FError} FT_SUCCESS PHY 


#### FXmacPhyInit

- PHY  PHY 

```c
FError FXmacPhyInit(FXmac *instance_p, u32 speed,u32 duplex_mode, u32 autonegotiation_en);
```

Input:
- {FXmac} *instance_p MAC 
- {u32} speed 
- {u32} duplex_mode 10 
- {u32} autonegotiation_en 1 PHY 0 

Return:
- FError FT_SUCCESS 


#### FXmacSelectClk

- MAC  PHY 

```c
void FXmacSelectClk(FXmac *instance_p )
```

Input:
- {FXmac} *instance_p MAC 


#### FXmacSetHandler

- 

```c
FError FXmacSetHandler(FXmac *instance_p, u32 handler_type, void *func_pointer, void *call_back_ref)
```

Input:
- {FXmac} *instance_p MAC 
- {u32} handler_type  , FXMAC_HANDLER_*** 
- {void } *func_pointer  
- {void } *call_back_ref 

