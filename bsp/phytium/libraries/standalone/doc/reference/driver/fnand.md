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
 * FilePath: fnand.md
 * Date: 2022-06-07 19:57:17
 * LastEditTime: 2022-06-07 19:57:18
 * Description:  This file is for 
 * 
 * Modify History: 
 *  Ver   Who  Date   Changes
 * ----- ------  -------- --------------------------------------
-->

# 
- NAND NAND :

1.  Toggle 
2.  
3. 
4. dma 
5. 
6. ECC
NAND :
1. NAND 
2. NAND 
3. NAND page/spare space 
4. 
5. 

##  

 :

.
 fnand_bbm.c
 fnand_bbm.h
 fnand.c
 fnand_dma.c
 fnand_dma.h
 fnand_ecc.c
 fnand_ecc.h
 fnand_g.c
 fnand.h
 fnand_hw.c
 fnand_hw.h
 fnand_intr.c
 fnand_option.c
 fnand_sinit.c
 fnand_timing.c
 fnand_timing.h
 fnand_toggle.c
 fnand_toggle.h

fnand.h :
1. Nand 
2. Nand id /
3. Nand 
4. Nand 
5. Nand 


## 
```c
    typedef struct _FNand
    {
        u32 is_ready; /* Device is ininitialized and ready*/
        FNandConfig config;
        u32 work_mode;              /* NAND controler work mode */

        /* nand flash info */
        FNandInterMode inter_mode[FNAND_CONNECT_MAX_NUM]; /* NAND controler timing work mode */
        FNandTimingMode timing_mode[FNAND_CONNECT_MAX_NUM];
        u32 nand_flash_interface[FNAND_CONNECT_MAX_NUM] ; /* Nand Flash Interface , followed by FNAND_ONFI_MODE \ FNAND_TOGGLE_MODE*/

        struct FNandDmaBuffer dma_data_buffer;          /* DMA data buffer */
        struct FNandDmaBuffer descriptor_buffer;        /* DMA descriptor */
        struct FNandDmaDescriptor descriptor[2];        /* DMA descriptor */
        struct FNandSdrTimings sdr_timing;              /* SDR NAND chip timings */

        /* bbm */
        FNandBadBlockManager bbt_manager[FNAND_CONNECT_MAX_NUM];    /* bad block manager handler */
        /* nand detect */
        FNandNandGeometry nand_geometry[FNAND_CONNECT_MAX_NUM];     /* nand flash infomation */
        /* dma  */
        FnandIrqEventHandler irq_event_fun_p;                       /* Interrupt event response function */
        void *irq_args;

        FNandOperationWaitIrqCallback wait_irq_fun_p;               /* The NAND controller operates the wait function */
        void *wait_args;        

        /* operations */
        FNandTransferP write_p ;                                    /* Write page function */
        FNandTransferP read_p ;                                     /* Read page function */
        FNandTransferP write_oob_p ;                                /* Write page spare space function */
        FNandTransferP read_oob_p ;                                 /* Read page spare space function */
        FNandTransferP write_hw_ecc_p ;                             /* Write page with hardware function */
        FNandTransferP read_hw_ecc_p ;                              /* Read page with hardware function */
        FNandEraseP erase_p;                                        /* Erase block  function */
    } FNand;
```

## 
```
FNAND_ERR_OPERATION					/* NAND NAND flash  */
FNAND_ERR_INVAILD_PARAMETER			/* NAND  */
FNAND_IS_BUSY							/* NAND NAND flash , */
FNAND_OP_TIMEOUT						/* NAND  */
FNAND_VALUE_ERROR						/* NAND BBM  */
FNAND_VALUE_FAILURE						/*  */
FNAND_NOT_FET_TOGGLE_MODE			/* toggle  */
FNAND_ERR_READ_ECC						/* ecc  */
FNAND_ERR_IRQ_OP_FAILED                 /* // */
FNAND_ERR_IRQ_LACK_OF_CALLBACK          /* // */
FNAND_ERR_IRQ_OP_FAILED                 /*  */
FNAND_ERR_NOT_MATCH                     /* flash id     */
```
## 
- baremetal/example/peripheral/nand/nand_test
## API 

### 1. FNandLookupConfig

```
FNandConfig *FNandLookupConfig(u32 instance_id)
```

#### 
- FNand

#### 
- u32 instance_id :NandID

#### 
FGicConfig * :


### 2. FNandCfgInitialize

```
FError FNandCfgInitialize(FNand *instance_p,FNandConfig *config_p)
```

#### 
- NAND

#### 
- FNand *instance_p  FNand 
- FNandConfig * 

#### 
- FError :FT_SUCCESS 

### 3. FNandScan

```
FError FNandScan(FNand *instance_p)
```

#### 
- Nand flash Nand flash 

#### 
- FNand *instance_p  FNand 

#### 
- FError :FT_SUCCESS 

### 4. FNandWritePage

```
FError FNandWritePage(FNand *instance_p,u32 page_addr,u8 *buffer,u32 page_copy_offset ,u32 length,u8 *oob_buffer,u32 oob_copy_offset,u32 oob_length,u32 chip_addr)
```

#### 
-  ecc 

#### 
- FNand *instance_p  FNand 
- u32 page_addr     
- u8 *buffer	      
- u32 page_copy_offset 0  page_addr 0 + page_copy_offset 0xff
- u32 length 		  
- u8 *oob_buffer	  spare space 
- u32 oob_copy_offset spare space 0 page_addr   + page_copy_offset 0xff
- u32 oob_length      spare space
- u32 chip_addr		   

#### 
- FError :FT_SUCCESS 

### 5. FNandWritePageRaw

```
FError FNandWritePageRaw(FNand *instance_p,u32 page_addr,u8 *buffer,u32 page_copy_offset ,u32 length,u8 *oob_buffer,u32 oob_copy_offset,u32 oob_length,u32 chip_addr)
```

#### 
-  ecc 

#### 
- FNand *instance_p  FNand 
- u32 page_addr     
- u8 *buffer	      
- u32 page_copy_offset 0  page_addr 0 + page_copy_offset 0xff
- u32 length 		  
- u8 *oob_buffer	  spare space 
- u32 oob_copy_offset spare space 0 page_addr   + page_copy_offset 0xff
- u32 oob_length      spare space
- u32 chip_addr		   

#### 
- FError :FT_SUCCESS 


### 6. FNandReadPage

```
FError FNandReadPage(FNand *instance_p,u32 page_addr,u8 *buffer,u32 page_copy_offset,u32 length,u8 *oob_buffer,u32 oob_copy_offset,u32 oob_length,u32 chip_addr)
```

#### 
-  ecc 

#### 
```
FNand *instance_p  FNand 
u32 page_addr     
u8 *buffer	      
u32 page_copy_offset 0  page_addr  0 + page_copy_offset 
u32 length 		  
u8 *oob_buffer	  spare space 
u32 oob_copy_offset spare space 0 page_addr   + page_copy_offset 
u32 oob_length      spare space
u32 chip_addr		   
```


#### 
- FError :FT_SUCCESS 

### 7. FNandReadPageRaw

```
FError FNandReadPageRaw(FNand *instance_p,u32 page_addr,u8 *buffer,u32 page_copy_offset,u32 length,u8 *oob_buffer,u32 oob_copy_offset,u32 oob_length,u32 chip_addr)
```

#### 
-  ecc 

#### 
```
FNand *instance_p  FNand 
u32 page_addr     
u8 *buffer	      
u32 page_copy_offset 0  page_addr  0 + page_copy_offset 
u32 length 		  
u8 *oob_buffer	  spare space 
u32 oob_copy_offset spare space 0 page_addr   + page_copy_offset 
u32 oob_length      spare space
u32 chip_addr		   
```


#### 
- FError :FT_SUCCESS 

### 8. FNandEraseBlock

```
FError FNandEraseBlock(FNand *instance_p, u32 block, u32 chip_addr)
```

#### 
- 

#### 
FNand *instance_p  FNand 
u32 block 		  
u32 chip_addr		  

#### 
- FError :FT_SUCCESS 



### 9. FNandReadPageOOb

```
FError FNandReadPageOOb(FNand *instance_p,u32 page_addr,u8 *oob_buffer,u32 oob_copy_offset,u32 oob_length,u32 chip_addr)
```

#### 
-  spare space 

#### 
- FNand *instance_p   FNand 
- u32 page_addr	  Row Address 
- u8 * oob_buffer	  
- u32 oob_copy_offset spare space 0  page_addr  page length +  oob_copy_offset 
- u32 	oob_length 	   spare space 
- u32 chip_addr		  

#### 
- FError :FT_SUCCESS 

### 10. FNandWritePageOOb


```
FError FNandWritePageOOb(FNand *instance_p,u32 page_addr,u8 *oob_buffer,u32 page_copy_offset,u32 oob_length,u32 chip_addr)
```

#### 
-  spare space 

#### 
- FNand *instance_p   FNand 
- u32 page_addr	  Row Address 
- u8 * oob_buffer	  
- u32 oob_copy_offset spare space 0 page_addr  page length +  oob_copy_offset 
- u32 oob_length 	   spare space 
- u32 chip_addr		  

#### 
- FError :FT_SUCCESS 


### 11. FNandSetIsrHandler

```
void FNandSetIsrHandler(FNand *instance_p, FnandIrqEventHandler event_p, void *irq_args)
```

#### 
- 

#### 
- FNand *instance_p   FNand 
- FnandIrqEventHandler event_p 
- void *irq_args 	       

#### 


### 12. FNandIrqHandler

```
void FNandIrqHandler(s32 vector, void *param)
```

#### 
- Nand 

#### 
- s32 vector  ID
- void * param  

#### 
- 

### 13. FNandInitBbtDesc

```
void FNandInitBbtDesc(FNand *instance_p)
```

#### 
- 

#### 
- FNand *instance_p   FNand 

#### 
- 


### 10. FNandScanBbt

```
FError FNandScanBbt(FNand *instance_p, u32 target_addr)
```

#### 
- Nand flash

#### 
- FNand *instance_p   FNand 
- u32 chip_addr		  

#### 
- FError :FT_SUCCESS 

### 11. FNandIsBlockBad

```
FError FNandIsBlockBad(FNand *instance_p, u32 block, u32 target_addr)
```
#### 
- 

#### 
- FNand *instance_p   FNand 
- u32 block			   ID
- u32 chip_addr		  

#### 
- FError :FT_SUCCESS 

### 12. FNandOperationWaitIrqRegister 

```
void FNandOperationWaitIrqRegister(FNand *instance_p,FNandOperationWaitIrqCallback wait_irq_fun_p ,void *wait_args)
```

#### 
- FNand *instance_p   FNand 
- FNandOperationWaitIrqCallback // FT_SUCCESS 
- void *wait_args     

### 




### 13. FNandSetOption

- options 

```c
FError FNandSetOption(FNand *instance_p,u32 options,u32 value)
```

#### 
- FNand *instance_p   FNand 
- u32 option 
- u32 value  

