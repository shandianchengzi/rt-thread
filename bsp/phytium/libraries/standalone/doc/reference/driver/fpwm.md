# FPWM 

## 1. 

PWMPulse Width Modulation

## 2. 

pwmpwm
- pwm
- FIFO_EMPTY
- E20008PWM()pwm0pwm1channel0channel1bypasschannelpwmbypasschannel0channel1


```
.
 fpwm_g.c
 fpwm_hw.c
 fpwm_hw.h
 fpwm_intr.c
 fpwm_sinit.c
 fpwm.c
 fpwm.h
```

## 3. 

 fpwm :

- pwm
- pwm
- 
- pwm
![pwm_duty](./figs/pwm_duty.png)

e200050Mfreqduty1/freq
perioadFPWM_PERIOD_OFFSETdivFPWM_TIM_CTRL_OFFSETDIVccrFPWM_CCR_OFFSET

## 4 

### [pwm](../../../baremetal/example/peripheral/pwm)

## 5. API

### 5.1. 

- fpwm

```c
typedef struct
{
    FPwmConfig config;/* Pwm */
    u32 is_ready;/* Pwm */

	u8 channel_ctrl_enable[2];	/* pwm channel ctrl enable state */

	FPwmIntrEventHandler event_handler[FPWM_INTR_EVENT_NUM];  /* event handler for interrupt */
    void *event_param[FPWM_INTR_EVENT_NUM];   /* parameters ptr of event handler */
	
} FPwmCtrl;
```

- fpwmFPwmConfigpwmidFPwmDbVariableConfigFPwmVariableConfigpwm

```c
typedef struct 
{	
  	u8 instance_id;/* pwm id */
	uintptr db_base_addr;
	uintptr pwm_base_addr;
	
	u64 base_clk;
	u32 irq_num;    	/* pwm irq num*/
    u32 irq_prority;	/* pwm irq priority */
  	const char *instance_name;/* instance name */

}FPwmConfig;/* Pwm */; 

typedef struct 
{
	FPwmDbPolarity db_polarity_sel;
	FPwmDbOutMode db_out_mode;
	FPwmDbInMode db_in_mode;
	u16 db_fall_cycle;
	u16 db_rise_cycle;
}FPwmDbVariableConfig; 

typedef struct 
{
	u8 tim_ctrl_enable;/* pwm time ctrl enable state */
	FPwmTimCtrlMode tim_ctrl_mode;
	u16 tim_ctrl_div;
	u16 pwm_period;
	FPwmCtrlMode pwm_mode;
	FPwmPolarity pwm_polarity;
	FPwmDutySourceMode pwm_duty_source_mode;
	u16 pwm_pulse;

}FPwmVariableConfig;
```

- 
```c
typedef enum
{
	FPWM_DB_OUT_MODE_BYPASS = 0b00,
	FPWM_DB_OUT_MODE_FORBID_RISE = 0b01,
	FPWM_DB_OUT_MODE_FORBID_FALL = 0b10,
	FPWM_DB_OUT_MODE_ENABLE_RISE_FALL = 0b11,
	FPWM_DB_OUT_MODE_NUM
} FPwmDbOutMode;
```

- fpwm duty
```c
typedef enum
{
	FPWM_DUTY_CCR = 0,
	FPWM_DUTY_FIFO = 1,

	FPWM_DUTY_SEL_MODE_NUM
	
} FPwmDutySourceMode;;
```

- fpwm
```c
typedef enum
{
    FPWM_INTR_EVENT_COUNTER = 0,    /**< Handler type for counter interrupt */
    FPWM_INTR_EVENT_FIFO_EMPTY = 1, /**< Handler type for fifo empty interrupt*/
    FPWM_INTR_EVENT_NUM
} FPwmIntrEventType;

```

### 5.2  

- FPWM_SUCCESS                 
- FPWM_ERR_INVAL_PARM         
- FPWM_ERR_NOT_READY          
- FPWM_ERR_TIMEOUT            
- FPWM_ERR_NOT_SUPPORT        
- FPWM_ERR_CMD_FAILED         

### 5.3. API

#### FPwmLookupConfig

- Fata

```c
const FPwmConfig *FPwmLookupConfig(FPwmInstance instance_id);
```

Note:

- 

Input:

- {FPwmInstance} instance_idpwmid

Return:

- {const FPwmConfig *} pwmNULL

#### FPwmCfgInitialize

- fpwm, 

```c
FError FPwmCfgInitialize(FPwmCtrl *pctrl, const FPwmConfig *input_config_p);
```

Note:

- FPwmLookupConfig

Input:

- {FPwmCtrl} *pctrlpwm
- {FPwmConfig} *input_config_ppwm

Return:

- {FError} FPWM_SUCCESS 

#### FPwmDbVariableSet

- pwm

```c
FError FPwmDbVariableSet(FPwmCtrl *pctrl, FPwmDbVariableConfig *db_cfg);
```

Note:

- pwm

Input:

- {FPwmCtrl} *pctrlpwm
- {FPwmDbVariableConfig} *db_cfgpwm

Return:

- {FError} FPWM_SUCCESS 

#### FPwmVariableSet

- pwm

```c
FError FPwmVariableSet(FPwmCtrl *pctrl, u32 channel, FPwmVariableConfig *pwm_cfg);
```

Note:

- pwm

Input:

- {FPwmCtrl} *pctrlpwm
- {u32} channelpwm
- {FPwmVariableConfig} *pwm_cfgpwm

Return:

- {FError} FPWM_SUCCESS 


#### FPwmPulseSet

- pwm

```c
FError FPwmPulseSet(FPwmCtrl *pctrl, u32 channel, u16 pwm_ccr);
```

Note:

- pwm

Input:

- {FPwmCtrl} *pctrlpwm
- {u32} channelpwm
- {u16} pwm_ccr

Return:

- {FError} FPWM_SUCCESS 

#### FPwmEnable

- pwm

```c
void FPwmEnable(FPwmCtrl *pctrl, u32 channel);
```

Note:

- pwm

Input:

- {FPwmCtrl} *pctrlpwm
- {u32} channelpwm

Return:

- {FError} FPWM_SUCCESS 

#### FPwmRegisterInterruptHandler

- pwm

```c
void FPwmRegisterInterruptHandler(FPwmCtrl *instance_p, FPwmIntrEventType event_type, 
                                    FPwmIntrEventHandler handler, void *param);
```

Note:
- 

Input:
- {FPwmCtrl} *instance_pfpwm
- {FPwmIntrEventType} event_type
- {FPwmIntrEventHandler} handler
- {void} *param

Return:
- 

#### FPwmIntrHandler

- pwm

```c
void FPwmIntrHandler(s32 vector, void *args);
```

Note:
- 

Input:
- {s32} vector
- {void} *param, fpwm

Return:
- 
