<!--
 * Copyright: (C)2022PhytiumInformationTechnology,Inc. 
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
 * FilePath: fgic.md
 * Date: 2022-04-15 13:57:32
 * LastEditTime: 2022-04-15 13:57:32
 * Description: This file is for 
 * 
 * ModifyHistory: 
 *  VerWhoDateChanges
 * ---------------------------------------------------------
-->


# GIC 

## 1.

GIC ARM CPUGICSPI\SGI\PPIGICv3
1.SPI
2.SGI
3.PPI 
4.CPU interface 
5.
6.Non-secure

## 2.


```
.
 fgic.c
 fgic.h
 fgic_cpu_interface.S
 fgic_cpu_interface.h
 fgic_distributor.h
 fgic_g.c
 fgic_hw.h
 fgic_redistributor.h
 fgic_sinit.c
```
- fgic.c/h 
1. GIC 
2. 
3. 
4. 
5. SGI
6. Acknowledge
7. 
8. DistrutiorRedistrubutiorCPU interface  

## 3.

```
typedef struct
{
  u32 instance_id; /*Gic */
  uintptr dis_base; /* Distributor */
  
} FGicConfig;

```

```
typedef struct
{
  FGicConfig config; /* */
  u32 is_ready;    /*  */
  uintptr redis_base; /* Redistributor  */
  SECURITY_STATE security ; /* GIC  */
  s32 max_spi_num;  /* SPI ID */
} FGic;
```

## 4.

```
FGIC_CTLR_ERR_TYPE   /* CTLR  */
FGIC_CTLR_ERR_NUM   /* id */
FGIC_CTLR_ERR_IN_SET  /*  */
FGIC_CTLR_ERR_IN_GET  /*  */
```

## 5.

common/interrupt.c	
/baremetal/example/peripheral/gic/fgic_test  gic

## 6.API

### 1. FGicLookupConfig

```
FGicConfig *FGicLookupConfig(u32 instance_id)
```

#### 
GIC 
#### 
- u32 instance_id GIC ID

#### 
- FGicConfig * 

### 2. FGicCfgInitialize

```
FError FGicCfgInitialize(FGic *instance_p, const FGicConfig *input_config_p , uintptr redis_base)
```

#### 
GIC 

#### 
- FGic *instance_pFGic
- const FGicConfig *input_config_p
- redis_base  

#### 
- FError FGIC_SUCCESS 


### 3. FGicDistrubutiorInit

```
void FGicDistrubutiorInit(FGic *instance_p)
```

#### 
Distrubutior 

#### 
- FGic *instance_pFGic

#### 


### 4. FGicRedistrubutiorInit

```
FError FGicRedistrubutiorInit(FGic *instance_p)
```

#### 
Redistrubutior 

#### 
- FGic *instance_pFGic

#### 
- {FError} FGIC_SUCCESS is success ,FGIC_ERR_IN_TIMEOUT is timeout

### 5. FGicCpuInterfaceInit

```
void FGicCpuInterfaceInit(void)
```

#### 
cpu interface

#### 


### 6. FGicIntEnable

```
FError FGicIntEnable(FGic *instance_p,s32 int_id)
```

#### 


#### 
- FGic *instance_pFGic
- s32 int_idID

#### 
- FError FGIC_SUCCESS 

### 7. FGicIntDisable

```
FError FGicIntDisable(FGic *instance_p,s32 int_id)
```

#### 


#### 
- FGic *instance_pFGic
- s32 int_idID

#### 
- FError FGIC_SUCCESS 

### 8. FGicSetPriority

```
FError FGicSetPriority(FGic *instance_p,s32 int_id,u32 priority)
```

#### 


#### 
- FGic *instance_pFGic
- s32 int_idID
- u32 priority 8bit

#### 
- FError FGIC_SUCCESS  FGIC_CTLR_ERR_IN_GET ID

### 9. FGicGetPriority

```
u32 FGicGetPriority(FGic *instance_p,s32 int_id)
```

#### 


#### 
- FGic *instance_pFGic
- s32 int_idID

#### 
- u32 8bit FGIC_CTLR_ERR_IN_GET ID

### 10. FGicSetTriggerLevel

```
FError FGicSetTriggerLevel(FGic *instance_p,s32 int_id,TRIGGER_LEVEL trigger_way)
```

#### 


#### 
- FGic *instance_pFGic
- s32 int_idID
- TRIGGER_LEVEL trigger_way  01

#### 
- FError FGIC_SUCCESS  FGIC_CTLR_ERR_IN_GET ID

### 11. FGicGetTriggerLevel

```
u32 FGicGetTriggerLevel(FGic *instance_p,s32 int_id)
```

#### 


#### 
- FGic *instance_pFGic
- s32 int_idID

#### 
- TRIGGER_LEVEL trigger_way  01

### 12. FGicSetSpiAffinityRouting

```
FError FGicSetSpiAffinityRouting(FGic *instance_p,s32 int_id,SPI_ROUTING_MODE route_mode,u64 affinity)
```

#### 
SPI  

#### 
- FGic *instance_pFGic
- s32 int_idID
- SPI_ROUTING_MODE route_mode SPI_ROUTING_TO_SPECIFIC spi PE ,SPI_ROUTING_TO_ANY spi SPI PE
- u64 affinity
 * |--------[bit39-32]-------[bit23-16]-------------[bit15-8]--------[bit7-0]
 * |--------Affinity level3-----Affinity level2-----Affinity level1---Affinity level0   

#### 
- FError FGIC_SUCCESS FGIC_CTLR_ERR_IN_SET ID SPI


### 13. FGicGetAffinityRouting

```
FError FGicGetAffinityRouting(FGic *instance_p,s32 int_id,SPI_ROUTING_MODE *route_mode_p,u64 *affinity_p)
```

#### 
SPI  

#### 
- FGic *instance_pFGic
- s32 int_idID
- SPI_ROUTING_MODE  *route_mode_p SPI_ROUTING_TO_SPECIFIC  spi PE , SPI_ROUTING_TO_ANY  spi SPI PE
- u64  *affinity_p
 * |--------[bit39-32]-------[bit23-16]-------------[bit15-8]--------[bit7-0]
 * |--------Affinity level3-----Affinity level2-----Affinity level1---Affinity level0   

#### 
- FError FGIC_SUCCESS FGIC_CTLR_ERR_IN_GET ID SPI

### 14. FGicGenerateSgi
```
FError FGicGenerateSgi(FGic *instance_p,s32 int_id,u32 target_list,SGI_ROUTING_MODE routing_mode,u64 affinity)
```

#### 
idSGI 

#### 
- FGic *instance_pFGic
- s32 int_idID
- u32 target_listSGIpe  PE
SGI_ROUTING_MODE routing_modeSGI SGI_ROUTING_TO_SPECIFIC PE,SGI_ROUTING_TO_ANY PE 
- u64 affinity 
 * |--------[bit55-48]-------[bit39-32]-------------[bit23-16]
 * |--------Affinity level3-----Affinity level2-----Affinity level1   

#### 
- FError FGIC_SUCCESS FGIC_CTLR_ERR_IN_SET ID SGI

### 15. FGicDeactionInterrupt

```
void FGicDeactionInterrupt(FGic *instance_p,s32 int_id)
```

#### 


#### 
- FGic *instance_pFGic
- s32 int_idID

#### 


### 16. FGicAcknowledgeInt

```
s32 FGicAcknowledgeInt(FGic *instance_p)
```

#### 


#### 
- FGic *instance_pFGic

#### 
- s32 int_idID


### 17. FGicSetPriorityFilter

```
void FGicSetPriorityFilter(FGic *instance_p,u32 priority_mask)
```

#### 
ICC_PMR
 
#### 
- FGic *instance_pFGic
- u32 priority_maskPE priority_mask  
 * |priority_mask---------------256-------254--------252------248-------240
 * |Implemented priority bits---[7:0]----[7:1]------[7:2]-----[7:3]-----[7:4]  
 * |priority the growing steps--any-----even value----4---------8--------16  

#### 


### 18. FGicSetPriorityGroup

```
void FGicSetPriorityGroup(FGic *instance_p,u32 binary_point)
```

#### 
 

#### 
- FGic *instance_pFGic
- u32 binary_point8 
- binary_point  
 * |return value----------------0-------1--------2------3-------4------5------6-------7
 * |Group priority field------[---]----[7:1]---[7:2]--[7:3]---[7:4]---[7:5]---[7:6]---[7]  
 * |Subpriority field---------[---]-----[0]----[1:0]--[2:0]---[3:0]---[4:0]---[5:0]---[6:0] 

#### 



### 19. FGicGetPriorityFilter

```
u32 FGicGetPriorityFilter(FGic *instance_p)
```

#### 


#### 
- FGic *instance_pFGic

#### 
- u32 Priority MaskCPU PE  priority_mask 
 * |return value------------------256------254--------252------248-------240
 * |Implemented priority bits---[7:0]----[7:1]------[7:2]-----[7:3]-----[7:4]  
 * |priority the growing steps---any-----even value----4--------8-------16  

### 20. FGicGetPriorityGroup

```
u32 FGicGetPriorityGroup(FGic *instance_p)
```

#### 
CPU interface 

#### 
- FGic *instance_pFGic

#### 
- u32 Priority group8 
binary_point  
 * |return value----------------0-------1--------2------3-------4------5------6-------7
 * |Group priority field------[---]----[7:1]---[7:2]--[7:3]---[7:4]---[7:5]---[7:6]---[7]  
 * |Subpriority field---------[---]-----[0]----[1:0]--[2:0]---[3:0]---[4:0]---[5:0]---[6:0] 