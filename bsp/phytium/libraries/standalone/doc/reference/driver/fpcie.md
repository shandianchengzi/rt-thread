# FPCIE 

## 1. 


- PCIePCIePCIe

- FPCIE  PCIE PCI-E UnitPEU PEU0  PEU1 PEU  3 C0C1  C2 PEU  X16 C1 

- 

1.  Root Complex  End Point 
2.  34 lane X16 2  X8 X1
3.  DMA 

## 2. 


- 
- drivers/pcie/fpcie

```
.
 fpcie.c
 fpcie.h
 fpcie.md
 fpcie_common.h
 fpcie_config.c
 fpcie_dma.c
 fpcie_dma.h
 fpcie_ep.c
 fpcie_g.c
 fpcie_hw.c
 fpcie_hw.h
 fpcie_misc.c
 fpcie_sinit.c
 fpcir_intx.c
 fspim.md
```

## 3. 

 PCIE :

- PCIE
- API  bar 
- INTX 
- DMA

## 4. 

"/baremetal/example/peripheral/fpcie_probe "

## 5. API

### 5.1 



- 

```c 
   typedef struct
    {
        void (*IntxCallBack)(void *args) ;
        void *args ;
        s32 bdf ;
    } FPcieIntxFun;
```

- 

```c
    struct FPcieRegion {
        FPcieAddr bus_start;	        /* Start on the bus */
        FPciePhysAddr phys_start;	/* Start in physical address space */
        FPcieSize size;	            /* Size */
        unsigned long flags;	    /* Resource flags */
        FPcieAddr bus_lower;
        u32 exist_flg;              /* exist flg */
    };
```

- 

```c
    typedef struct
    {
        u32 instance_id; /* Id of device */
        u32 irq_num;     /* Irq number */ 
        uintptr_t ecam;  /* The Memory way */
        uintptr_t peu0_config_address;
        uintptr_t peu1_config_address;
        
        uintptr_t control_c0_address;
        uintptr_t control_c1_address;
        uintptr_t control_c2_address;
        uintptr_t control_c3_address;
        uintptr_t control_c4_address;
        uintptr_t control_c5_address;
        
        u32 io_base_addr;
        u32 io_size ;
        u32 npmem_base_addr;
        u32 npmem_size;
        u64 pmem_base_addr; /* Prefetchable memory */
        u64 pmem_size;

        u8 inta_irq_num ;
        u8 intb_irq_num ;
        u8 intc_irq_num ;
        u8 intd_irq_num ;
        u8 need_skip    ;

    } FPcieConfig;
```

- 

```c
    typedef struct
    {
        u32 is_ready; /* Device is ininitialized and ready*/
        FPcieConfig config;

        struct FPcieRegion mem;
        struct FPcieRegion mem_prefetch;
        struct FPcieRegion mem_io;

        s32  bus_max; /* bus num */

        FPcieIrqCallBack fpcie_dma_rx_cb;
        void *dma_rx_args;

        FPcieIrqCallBack fpcie_dma_tx_cb;
        void *dma_tx_args;

        FPcieIrqCallBack fpcie_dma_rx_error_cb;
        void *dma_rx_error_args;

        FPcieIrqCallBack fpcie_dma_tx_error_cb;
        void *dma_tx_error_args;

        FPcieIntxFun inta_fun;

        FPcieIntxFun intb_fun;

        FPcieIntxFun intc_fun;

        FPcieIntxFun intd_fun;

    } FPcie;
```


- 

```
#define FPCIE_REGION_MEM		0x00000000	/* PCI memory space */
#define FPCIE_REGION_IO		    0x00000001	/* PCI IO space */
#define PCI_REGION_PREFETCH	    0x00000008	/* prefetchable PCI memory */
```


- bar 

```
#define FPCIE_BAR_0 0
#define FPCIE_BAR_1 1
#define FPCIE_BAR_2 2
#define FPCIE_BAR_3 3
#define FPCIE_BAR_4 4
#define FPCIE_BAR_5 5
```


### 5.2 

- 0x1090000
- [0x0] FT_SUCCESS
- [0x1090001] FPCIE_ERR_INVALID_PARAM 
- [0x1090002] FPCIE_ERR_OUTOF_BUS 
- [0x1090003] FPCIE_ERR_CONFIG_WRITE 
- [0x1090004] FPCIE_ERR_TYPE0 
- [0x1090005] FPCIE_ERR_TIMEOUT 
- [0x1090006] FPCIE_NEED_SKIP 
- [0x1090007] FPCIE_NOT_FOUND 


### 5.3 API


#### FPcieLookupConfig

- FPCIE

```c
const FPcieConfig *FPcieLookupConfig(u32 instance_id)
```

Note:

- `FPcieCfgInitialize`

Input:

- u32 instance_id, FPcie

Return:

- const FPcieConfig *, NULL



#### FPcieCfgInitialize

- FPCIE 

```c
FError FPcieCfgInitialize(FPcie *instance_p, FPcieConfig *config_p)
```

Note:

- 'FPcieLookupConfig'

Input:

- FPcie *instance_p FPcie

- FPcieConfig *config_p FPcieConfig

Return :

-  FT_SUCCESS


#### FPcieDmaDescSet

- PCIE DMA

```c
FError FPcieDmaDescSet(uintptr axi_addr,
                       uintptr bar_addr,
                       u32 length,
                       struct FPcieDmaDescriptor *desc,
                       struct FPcieDmaDescriptor *next_desc)
```

Note:

- dma PCIE 


Input:

- uintptr axi_addr 

- uintptr bar_addr functionbar

- u32 length       

- struct FPcieDmaDescriptor *next_desc   

Output:

- struct FPcieDmaDescriptor *desc 



#### FPcieDmaRead

Note:

- dmaPcie function

```c
void FPcieDmaRead(uintptr bar_address, struct FPcieDmaDescriptor *desc)
```

Input:

- uintptr bar_address 

- struct FPcieDmaDescriptor *desc  

#### FPcieDmaWrite

- dmaPcie function

```c
void FPcieDmaWrite(uintptr bar_address, struct FPcieDmaDescriptor *desc)
```

Input:

- uintptr bar_address 

- struct FPcieDmaDescriptor *desc  


#### FPcieDmaPollDone

- DMA

```c
FError FPcieDmaPollDone(struct FPcieDmaDescriptor *desc, u32 wait_cnt)
```

Input:

- struct FPcieDmaDescriptor *desc  Descdma 

- u32 wait_cnt   

####  FPcieFetchDeviceInBus

- 

```c
FError FPcieFetchDeviceInBus(FPcie *instance_p, u32 bus_num)
```

Input:

- FPcie *instance_p FPcie

- u32 bus_num /  

Output:

- FError FT_SUCCESS 


#### FPcieFindDeviceNum

- Vendor ID  Device ID PCIE 

```c
u32  FPcieFindDeviceNum(FPcie *instance_p, u32 bus_num,u32 vendor_id,u32 device_id)
```

Input:

- FPcie *instance_p FPcie

- u32 bus_num bus

- u32 vendor_id  Vendor ID

- u32 device_id  Device ID

Output:

- u32 return 



#### FPcieGetBusDeviceBarInfo

- Vendor IDdevice IDfunction iddevice id  bar 

```c
FError FPcieGetBusDeviceBarInfo(FPcie *instance_p,u32 bus,u32 vendor_id,u32 device_id,u32 bar_num ,u32 *device_p,u32 *function_p,uintptr *bar_addr_p)
```

Input:
- FPcie *instance_p FPcie

- u32 bus bus

- u32 vendor_id  Vendor ID

- u32 device_id  Device ID

- u32 bar_num bar

Output:

- u32 * device_p 

- u32 * function_p 

- uintptr * bar_addr_p bar

- FError return FT_SUCCESS 


#### FPcieSearchFunByClass

-  class code 

```c
u32 FPcieSearchFunByClass(FPcie *instance_p,u32 class_code,FPcieSearchFunNode *node_p ,u32 node_num)
```

Input:

- FPcie *instance_p FPcie

- u32 class_code 

- FPcieSearchFunNode * node_p 

- u32 node_num 

Output:

- u32 return 



#### FPcieIntxIrqHandler

- fpcieIntx

```c
void FPcieIntxIrqHandler(s32 vector, void *args)
```

Input:

- s32 vector 

- void * args 


#### FPcieIntxRegiterIrqHandler

- bus iddevice id function idINTX  

```c
FError FPcieIntxRegiterIrqHandler(FPcie *instance_p,
                                u32 bus,
                                u32 device,
                                u32 function,
                                FPcieIntxFun *intx_fun_p)
```

Input:

- FPcie *instance_p FPcie

- u32 bus       bus id

- u32 device    device id

- u32 function  function id

- FPcieIntxFun * intx_fun_p 
