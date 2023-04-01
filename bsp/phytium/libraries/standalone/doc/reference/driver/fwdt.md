# WDT 

## 1. 

- WDT(watchdog timer)

- 

- WDT  FT2000/4D2000E2000

## 2. 

WDT WDT

- 
- 
- 


```
fwdt
     fwdt.c
     fwdt.h
     fwdt_g.c
     fwdt_hw.c
     fwdt_hw.h
     fwdt_intr.c
     fwdt_sinit.c
```

## 3. 

 WDT :

- WDT
- 
- 
- 

## 4. 


### [wdt_test](../../../baremetal/example/peripheral/timer/wdt_test/README.md)


## 5. API


### 5.1. 

- drivers/wdt/fwdt/fwdt.h

- wdt

```c
typedef struct
{
    u32 instance_id;/* wdt id */
    uintptr refresh_base_addr;/* wdt refresh base addr */
    uintptr control_base_addr;/* wdt control base addr */
    u32 irq_num;    /* wdt ir num */
    u32 irq_prority;/* wdt irq priority */
    const char *instance_name;/* instance name */
}FWdtConfig;/* wdt config */
```

### 5.2  

- FWDT_SUCCESS : success
- FWDT_ERR_INVAL_PARM : invalid input parameters
- FWDT_NOT_READY : driver not ready
- FWDT_NOT_SUPPORT : not support operation
- FWDT_TIMEOUT : wait timeout

### 5.3. API

- wdt

```c
const FWdtConfig *FWdtLookupConfig(u32 instance_id);
```

    Note:
    
    - FWdtConfig

    Input:

    - u32 instance_id, WDT 

    Return:

    - const FWdtConfig *,  NULL


- wdt

```c
u32 FWdtSetTimeout(FWdtCtrl *pCtrl, u32 timeout);
```

    Note:

    - WDT;
    - WDTWDT 6stimeout=3;

    Input:

    - FWdtCtrl *pCtrl, WDT 
    
    - u32 timeout, WDT89

    Return:

    - u32, 5.2


- WDT

```c
u32 FWdtRefresh(FWdtCtrl *pCtrl);
```

    Note:

    - wdt

    Input:

    - FWdtCtrl *pCtrl, WDT 

    Return:

    - u32, 5.2

- WDT

```c
u32 FWdtStart(FWdtCtrl *pCtrl);
```

    Note:

    - wdt

    Input:

    - FWdtCtrl *pCtrl, WDT 

    Return:

    - u32, 5.2

    
- WDT

```c
u32 FWdtStop(FWdtCtrl *pCtrl);
```

    Note:

    - wdt

    Input:

    - FWdtCtrl *pCtrl, WDT 

    Return:

    - u32, 5.2