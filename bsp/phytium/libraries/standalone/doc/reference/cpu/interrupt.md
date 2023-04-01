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
 * FilePath: interrupt.md
 * Date: 2022-04-14 23:39:11
 * LastEditTime: 2022-04-14 23:39:11
 * Description: This file is for 
 * 
 * ModifyHistory: 
 *  VerWhoDateChanges
 * ---------------------------------------------------------
-->

# interrupt

## 1

Armv8 IRQ 
1.id 
2.sdk 
3.
4.
5.

## 2


.
 finterrupt.c
 finterrupt.h


1.Not use default interrupt configuration

![](./figs/NotUseDefaultConfig.png)

 /baremetal/example/peripheral/gic/fgic_test 

2.CORE0 0 

![](./figs/UseDefaultConfig.png)

## 3

```
typedef void (*IrqHandler)(s32 vector, void *param); /* IRQ  */

```

```
struct IrqDesc
{
        IrqHandler handler;	 /* IRQ  */
        void *param;		/* IRQ  */
};
```


```
#define INTERRUPT_CPU_ALL_SELECT 0xffffffffffffffffULL /*  */
#define INTERRUPT_CPU_TARGET_ALL_SET 0xffffffffUL  /* SPI SPI  */

#define IRQ_MODE_TRIG_LEVEL (0x00)	  /* Trigger: level triggered interrupt */
#define IRQ_MODE_TRIG_EDGE (0x01)  /* Trigger: edge triggered interrupt */
```

```
typedef enum
{
 INTERRUPT_ROLE_MASTER = 0 , /*   */
 INTERRUPT_ROLE_SLAVE,  	  /*   */
}INTERRUPT_ROLE_SELECT; /*  */
```

```
#define IRQ_GROUP_PRIORITY_3    3 /* group priority valid mask is bit[7:3],subpriority valid mask is bit[4:0] */
#define IRQ_GROUP_PRIORITY_4    4 /* group priority valid mask is bit[7:4],subpriority valid mask is bit[3:0] */
#define IRQ_GROUP_PRIORITY_5    5 /* group priority valid mask is bit[7:5],subpriority valid mask is bit[4:0] */
#define IRQ_GROUP_PRIORITY_6    6 /* group priority valid mask is bit[7:6],subpriority valid mask is bit[5:0] */
#define IRQ_GROUP_PRIORITY_7    7 /* group priority valid mask is bit[7],subpriority valid mask is bit[6:0] */
```

IRQ_GROUP_PRIORITY_*  group priority subpriority   

```
#define IRQ_PRIORITY_VALUE_0    0
#define IRQ_PRIORITY_VALUE_1    0x10
#define IRQ_PRIORITY_VALUE_2    0x20
#define IRQ_PRIORITY_VALUE_3    0x30
#define IRQ_PRIORITY_VALUE_4    0x40
#define IRQ_PRIORITY_VALUE_5    0x50
#define IRQ_PRIORITY_VALUE_6    0x60
#define IRQ_PRIORITY_VALUE_7    0x70
#define IRQ_PRIORITY_VALUE_8    0x80
#define IRQ_PRIORITY_VALUE_9    0x90
#define IRQ_PRIORITY_VALUE_10   0xa0
#define IRQ_PRIORITY_VALUE_11   0xb0
#define IRQ_PRIORITY_VALUE_12   0xc0
#define IRQ_PRIORITY_VALUE_13   0xe0
#define IRQ_PRIORITY_VALUE_14   0xf0
```

IRQ_PRIORITY_VALUE_* 16

```
#define IRQ_PRIORITY_MASK_0    0
#define IRQ_PRIORITY_MASK_1    0x10
#define IRQ_PRIORITY_MASK_2    0x20
#define IRQ_PRIORITY_MASK_3    0x30
#define IRQ_PRIORITY_MASK_4    0x40
#define IRQ_PRIORITY_MASK_5    0x50
#define IRQ_PRIORITY_MASK_6    0x60
#define IRQ_PRIORITY_MASK_7    0x70
#define IRQ_PRIORITY_MASK_8    0x80
#define IRQ_PRIORITY_MASK_9    0x90
#define IRQ_PRIORITY_MASK_10   0xa0
#define IRQ_PRIORITY_MASK_11   0xb0
#define IRQ_PRIORITY_MASK_12   0xc0
#define IRQ_PRIORITY_MASK_13   0xe0
#define IRQ_PRIORITY_MASK_14   0xf0
```

IRQ_PRIORITY_MASK_* 16CPU

## 4

#define FINT_SET_TARGET_ERR    /* CPU id CPU ID  */
#define FINT_INT_NUM_NOT_FIT  /*  */


## 5
/baremetal/example/peripheral/gic/fgic_test  gicinterrupt 


## 6API

1. ,
   
```
InterruptInit(&interrupt_instance,INTERRUPT_DRV_INTS_ID,INTERRUPT_ROLE_MASTER);
```

2.  

```
InterruptSetPriorityGroupBits(IRQ_GROUP_PRIORITY_*);
```

3. ,CPU

```
InterruptSetPriorityMask(IRQ_PRIORITY_MASK_*);
```

4.  InterruptSetPriorityGroupBits 

```
InterruptSetPriority(INT_NUM,priority);
```

5. CPU

```
InterruptSetTargetCpus(INT_NUM,CPU_ID) 
```

6. ,

```
InterruptInstall(INT_NUM,int_handler,int_args,"int_name")
```

7. 

```
InterruptUmask(INT_NUM)
```

8. 

```
InterruptCoreInterSend(INT_NUM,CPU_MASK)
```

9. 

```
InterruptMask(INT_NUM)
```

## 7API

### 1. InterruptInit


```
void InterruptInit(InterruptDrvType * int_driver_p,u32 instance_id,INTERRUPT_ROLE_SELECT role_select)
```

#### 


#### 
- InterruptDrvType * int_driver_p  
- u32 instance_id: 
- INTERRUPT_ROLE_SELECT role_select INTERRUPT_ROLE_MASTER INTERRUPT_ROLE_SLAVE 

#### 


### 2. InterruptMask

```
void InterruptMask(int int_id)
```

#### 
ID

#### 
- int int_id id 

#### 


### 3. InterruptUmask

```
void InterruptUmask(int int_id)
```

#### 
ID

#### 
- int int_id id 

#### 


### 4. InterruptSetTargetCpus

```
FError InterruptSetTargetCpus(int int_id,u32 cpu_id)
```

#### 
CPU,CPU

#### 
- int int_id  id   32-1019
- u32 cpu_id :  CPUINTERRUPT_CPU_TARGET_ALL_SET CPU

#### 
FError  FINT_SUCCESSFINT_INT_NUM_NOT_FIT FINT_SET_TARGET_ERR CPU id CPU ID 

### 5. InterruptGetTargetCpus

```
FError InterruptGetTargetCpus(int int_id,u32 *cpu_p)
```

#### 
ID 

#### 
- int int_id  id 
- u32 *cpu_p :  CPUINTERRUPT_CPU_TARGET_ALL_SET CPU

#### 
FError  FINT_SUCCESSFINT_INT_NUM_NOT_FIT FINT_SET_TARGET_ERR CPU id CPU ID 

### 6. InterruptSetTrigerMode

```
void InterruptSetTrigerMode(int int_id, unsigned int mode)
```

#### 
ID 

#### 
- int int_id  id 
- unsigned int mode :  IRQ_MODE_TRIG_LEVEL (0x00) /* Trigger: level triggered interrupt */
- IRQ_MODE_TRIG_EDGE (0x01)  /* Trigger: edge triggered interrupt */

#### 


### 7. InterruptGetTrigerMode

```
unsigned int InterruptGetTrigerMode(int int_id)
```

#### 
ID 

#### 
- int int_id  id 

#### 
- unsigned int mode :  IRQ_MODE_TRIG_LEVEL (0x00) /* Trigger: level triggered interrupt */
- IRQ_MODE_TRIG_EDGE (0x01)  /* Trigger: edge triggered interrupt */

### 8. InterruptSetPriority

```
void InterruptSetPriority(int int_id, unsigned int priority)
```

#### 
ID 

#### 
- int int_id  id 
- unsigned int priority  IRQ_PRIORITY_VALUE_*

#### 


### 9. InterruptGetPriority

```
 unsigned int InterruptGetPriority(int int_id)
```

#### 
ID

#### 
- int int_id id 
- unsigned int priority 

#### 


### 10. InterruptSetPriorityMask

```
void InterruptSetPriorityMask(unsigned int priority)
```

#### 


#### 
- unsigned int priority CPU  IRQ_PRIORITY_MASK_* 

#### 


### 11. InterruptGetPriorityMask

```
void InterruptGetPriorityMask(void)
```

#### 


#### 

#### 
- unsigned int priority CPU 

### 12. InterruptSetPriorityGroupBits

```
void InterruptSetPriorityGroupBits(unsigned int bits)
```

#### 


#### 
- unsigned int bits 8IRQ_GROUP_PRIORITY_* 
 * |bits       ----------------0-------1--------2------3-------4------5-------6-------7
 * | ------[---]----[7:1]---[7:2]--[7:3]---[7:4]--[7:5]--[7:6]---[7]  
 * | ------[---]-----[0]----[1:0]--[2:0]---[3:0]---[4:0]--[5:0]--[6:0]   
  
#### 


### 13. InterruptInstall

```
IrqHandler InterruptInstall(int int_id, IrqHandler handler,void *param, const char *name)
```

#### 
id

#### 
- int int_idid 
- IrqHandler handler
- void *param
- const char *name
  
#### 


### 14. InterruptCoreInterSend

```
void InterruptCoreInterSend(int ipi_vector, u64 cpu_mask)
```

#### 


#### 
- int int_idid  , 0~15
- u64 cpu_maskcpu_maskCPU0x3core0CORE1  

#### 


### 15. InterruptEarlyInit

```
void InterruptEarlyInit(void)
```

#### 
CORE0CORE

#### 


#### 
