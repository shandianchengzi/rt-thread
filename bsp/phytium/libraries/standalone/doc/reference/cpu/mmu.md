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
 * FilePath: mmu.md
 * Date: 2022-02-22 16:26:16
 * LastEditTime: 2022-02-22 16:26:16
 * Description: This file is for 
 * 
 * ModifyHistory: 
 *  VerWhoDateChanges
 * ---------------------------------------------------------
-->

# MMU 

## 1. 

- VMSAMMU 

- CPU(VAs)(PAs)

- SDK aarch32 state  section 
- SDK aarch64 state  4KB  

## 2. 

- MMUMMU

## 3. 

## 4. 

"baremetal/example/system/amp/libmetal_test"
"baremetal/example/system/amp/openamp"

## 5. API


### 5.1 


/*  */
```
#define MT_P_NA_U_NA  /* higher Exception level access=NA, user=NA */
#define MT_P_RW_U_NA  /* higher Exception level access=RW, user=NA */
#define MT_P_RW_U_RO  /* higher Exception level access=RW, user=RO */
#define MT_P_RW_U_RW  /* higher Exception level access=RW, user=RW */
#define MT_P_RO_U_NA  /* higher Exception level access=RO, user=NA */
#define MT_P_RO_U_RO  /* higher Exception level access=RO, user=RO */
```

/*  */
```
#define MT_DEVICE_NGNRNE       /* Device-nGnRnE , Outer Shareable */
#define MT_DEVICE_NGNRE        /* Device-nGnRE , Outer Shareable */

#define MT_NORMAL_WT           /* Outer and Inner Write-Through, Read-Allocate No Write-Allocate , Outer Shareable  */

#define MT_NORMAL_WB_WCN       /* Outer and Inner Write-Back, Read-Allocate No Write-Allocate , Outer Shareable  */

#define MT_NORMAL_NC          /* Outer and Inner Non-cacheable , Outer Shareable , Outer Shareable */
#define MT_NORMAL             /* Outer and Inner Write-Back, Read-Allocate Write-Allocate , Outer Shareable , Outer Shareable  */

```

### 5.2 API

- 

```c
void FSetTlbAttributes(uintptr addr, fsize_t size, u32 attrib);
```

    Note:
        aarch32 state  section addr 1MB size MB
        aarch64 state  4KB  addr 4KB size 4KB

    Input:

    - addr  

    - size  

    - attrib ,     ### 5.1 

    Return:

    - void
