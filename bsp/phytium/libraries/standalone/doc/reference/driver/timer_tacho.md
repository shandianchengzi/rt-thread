# TIMER_TACHO 

## 1. 


- TIMER_TACHO2PAD
- 32/64restart/free
- 
- E2000(DQS)
- E2000DQS38DQ4tachoS16

## 2. 

- :
- drivers/timer/ftimer_tacho

```
.
 ftacho.c --> 
 ftimer_tacho_g.c --> 
 ftimer_tacho_hw.h --> 
 ftimer_tacho_intr.c --> 
 ftimer_tacho.h --> 
 ftimer.c --> 
```

## 3. 

ftimer_tacho:

- timer_tachotimertacho
- timeridtachoid
- 

## 4. 

### [timer](../../../baremetal/example/peripheral/timer/timer_tacho/README.md)

#### timer
- FTimerFunctionInit     cmd
- FTimerCfgInit          
- FTimerStartTest       
- 

#### tacho
- FTachoFunctionInit    cmdid
- FTachoCfgInit         
- TachoEnableIntr       
- FTimerStart           tacho
- FTachoGetRPM          RPM

#### timertacho
- disableF****DeInitFTimerSwithMode

## 5. API

### 5.1 

- ftimer_tacho

```c
typedef struct
{
    FTimerTachoConfig     config;   /* Current active configs */
    boolean               isready;  /* Device is initialized and ready */
    FTimerEventHandler    evt_handlers[FMAX_TIMER_TACHO_EVENT];/* event handler for interrupt */
}FTimerTachoCtrl;
```

- ftimer_tacho

```c
typedef struct 
{
    u32     id;        /* id of timer tacho */
    char    name[12];  /* instance name */
    u32     irq_priority; /* intr priority */
    u32     work_mode;  /* timer/tacho/capture mode */
    /* for timer function */
    u32     timer_mode; /* free-run/restart */
    u32     timer_bits; /* 32/64 bits */
    u32     cmp_type; /* once/cycle cmp */
    boolean clear_cnt;  /* clear timer counts */
    boolean force_load; /* start count from start val */
    /* for tacho function */
    u32     edge_mode; /* rising/falling/double */
    u32     jitter_level; /* jitter level */
    u32     plus_num;  /* plus_num of period to calculate rpm */
    u32     captue_cnt; /* in capture mode, when cnt reach this val, intr asserted */
}FTimerTachoConfig;
```

- ftimer_tacho
```c
typedef enum
{
    /*TimerTacho mode */
    FTIMER_WORK_MODE_TIMER = 0,
    FTIMER_WORK_MODE_TACHO,
    FTIMER_WORK_MODE_CAPTURE
}FTimerTachoModeType;
```

- timer
```c
typedef enum
{
    /*Timer count mode*/
    FTIMER_FREE_RUN = 0,
    FTIMER_RESTART
}FTimerCntModeType;
```

- ftimer_tacho
```c
typedef enum
{
    FTACHO_EVENT_OVER = 0,      /*tacho*/
    FTACHO_EVENT_UNDER,         /*tacho*/
    FTIMER_EVENT_ROLL_OVER,     /**/
    FTIMER_EVENT_ONCE_CMP,      /**/
    FTIMER_EVENT_CYC_CMP,       /**/
    FTACHO_EVENT_CAPTURE,       /*tacho*/
    
    FMAX_TIMER_TACHO_EVENT
}FTimerTachoEventType;
```

- tacho
```c
typedef enum
{
    FTACHO_FALLING_EDGE = 0,
    FTACHO_RISING_EDGE,
    FTACHO_DOUBLE_EDGE
}FTachoEdgeType;
```

- tacho
```c
typedef enum
{
    FTACHO_JITTER_LEVEL0 = 0,
    FTACHO_JITTER_LEVEL1,
    FTACHO_JITTER_LEVEL2,
    FTACHO_JITTER_LEVEL3,
}FTachoJitterLevelType;
```

### 5.2 

- FTIMER_TACHO_ERR_IS_READ                 
- FTIMER_TACHO_ERR_NOT_READY              
- FTIMER_TACHO_ERR_INVAL_PARM             
- FTIMER_TACHO_ERR_INIT_FAILED            
- FTIMER_TACHO_ERR_ABORT                  
- FTIMER_TACHO_ERR_FAILED                 
- FTIMER_TACHO_ERR_NOT_SUPPORT            

### 5.3 API

#### Time & Tacho API 

##### FTimerSoftwareReset

- 

```c
FError FTimerSoftwareReset(FTimerTachoCtrl *instance_p);
```

Note:

- 

Input:

- {FTimerTachoCtrl} *instance_ptimer_tacho

Return:

- {FError} 

##### FTimerSetInterruptMask

- 

```c
void FTimerSetInterruptMask(FTimerTachoCtrl *instance_p,
                           FTimerTachoEventType intrType,
                           boolean enable);
```

Note:

- ,intrTypemask

Input:

- {FTimerTachoCtrl} *instance_ptimer_tacho
- {FTimerTachoEventType} intrTypetimer_tacho
- {boolean} enable

Return:

- void 

##### FTimerStart

- timer_tacho

```c
FError FTimerStart(FTimerTachoCtrl *instance_p);
```

Note:

- timer_tacho,

Input:

- {FTimerTachoCtrl} *instance_ptimer_tacho

Return:

- {FError} 

##### FTimerStop

- timer

```c
FError FTimerStop(FTimerTachoCtrl *instance_p);
```

Note:

- timer

Input:

- {FTimerTachoCtrl} *instance_ptimer_tacho

Return:

- {FError} 

##### FTimerSwithMode

- timer  tacho-capture

```c
FError FTimerSwithMode(FTimerTachoCtrl *instance_p, FTimerTachoConfig *new_config_p);
```

Note:

- timer  tacho-capture

Input:

- {FTimerTachoCtrl} *instance_ptimer_tacho
- {FTimerTachoConfig} *new_config_ptimer_tacho

Return:

- {FError} 

##### FTimerRegisterEvtCallback

- 

```c
void FTimerRegisterEvtCallback(FTimerTachoCtrl *instance_p, 
                              FTimerTachoEventType evt, 
                              FTimerEventHandler callback);
```

Note:

- 

Input:

- {FTimerTachoCtrl} *instance_ptimer_tacho
- {FTimerTachoEventType} evt
- {FTimerEventHandler} callback

Return:

- void 

##### FTimeSettingDump

- 

```c
FError FTimeSettingDump(const FTimerTachoCtrl *instance_p);
```

Note:

- timer_tacho

Input:

- {FTimerTachoCtrl} *instance_ptimer_tacho

Return:

- {FError} 

##### FTimerTachoIntrHandler

- TimerTacho

```c
void FTimerTachoIntrHandler(s32 vector, void *param);
```

Note:

- TimerTacho

Input:

- {s32} vector
- {void} *param, , FTimerTachoCtrl

Return:

- void 

##### FTimerTachoSetIntr

- 

```c
void FTimerTachoSetIntr(FTimerTachoCtrl *instance_p);
```

Note:

- 

Input:

- {FTimerTachoCtrl} *instance_ptimer_tacho

Return:

- void 

##### FTimerInit

- TimerTacho

```c
FError FTimerInit(FTimerTachoCtrl *instance_p, const FTimerTachoConfig *config_p);
```

Note:

- TimerTachoFTimerStart

Input:

- {FTimerTachoCtrl} *instance_ptimer_tacho
- {FTimerTachoConfig} *config_ptimer_tacho

Return:

- {FError} 

##### FTimerDeInit

- Timer

```c
void FTimerDeInit(FTimerTachoCtrl *instance_p);
```

Note:

- Timer

Input:

- {FTimerTachoCtrl} *instance_ptimer_tacho

Return:

- void 

##### FTachoInit

- Tacho

```c
FError FTachoInit(FTimerTachoCtrl *instance_p, const FTimerTachoConfig *config_p);
```

Note:

- Tacho

Input:

- {FTimerTachoCtrl} *instance_ptimer_tacho

Return:

- void 

##### FTachoGetFanRPM

- 

```c
FError FTachoGetFanRPM(FTimerTachoCtrl *instance_p,u32 *rpm);
```

Note:

- 

Input:

- {FTimerTachoCtrl} *instance_ptimer_tacho
- {u32} *rpm

Return:

- {FError} 

##### FTachoDeInit

- Tacho

```c
void FTachoDeInit(FTimerTachoCtrl *instance_p);
```

Note:

- Tacho

Input:

- {FTimerTachoCtrl} *instance_ptimer_tacho

Return:

- void 
