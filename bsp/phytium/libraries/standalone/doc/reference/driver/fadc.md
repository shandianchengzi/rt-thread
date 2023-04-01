# FADC 

## 1. 

ADCAnalog-to-Digital Converter///

## 2. 

adcadc
- adc
- adc
- 


```
.
 fadc_g.c
 fadc_hw.c
 fadc_hw.h
 fadc_intr.c
 fadc_sinit.c
 fadc.c
 fadc.h
```

## 3. 

 fadc :

- adc
- adc
- adcadc

## 4 

### [adc](../../../baremetal/example/peripheral/adc)

## 5. API

### 5.1. 

- fadc

```c
typedef struct
{
    FAdcConfig config;/* adc config */
    FAdcConvertConfig convert_config; /* adc convert config */
    FAdcThresholdConfig threshold_config; /* adc channel threshold config */
    u32 is_ready;/* adc init ready flag */
    u16 value[FADC_CHANNEL_NUM];  /* adc value */
    boolean convert_complete[FADC_CHANNEL_NUM]; /*!< Specifies whether the conversion is complete> */
    FAdcIntrEventHandler event_handler[FADC_INTR_EVENT_NUM];  /* event handler for interrupt */
    void *event_param[FADC_INTR_EVENT_NUM];   /* parameters of event handler */
  
}FAdcCtrl;
```

- fadcFAdcConfigadcidFAdcConvertConfigFAdcThresholdConfig

```c
typedef struct
{
    u32 instance_id;/* adc id */
    uintptr base_addr;/* adc control register base address*/
    u32 irq_num;/* adc interrupt number */
    u32 irq_prority;/* adc interrupt priority*/
    const char *instance_name;/* instance name */

} FAdcConfig; 

typedef struct
{
    u32 convert_interval; /* convert interval time */
    u32 clk_div; /* clock divider */
    FAdcConvertMode convert_mode;/*!<  convert mode */
    FAdcChannelMode channel_mode;/*!< channel mode */

} FAdcConvertConfig; 

typedef struct
{
    u16 high_threshold[FADC_CHANNEL_NUM]; /*!< Configures the ADC analog high threshold value.
                                           This parameter must be a 10-bit value. */
    u16 low_threshold[FADC_CHANNEL_NUM];  /*!< Configures the ADC analog low threshold value. 
                                            This parameter must be a 10-bit value. */
} FAdcThresholdConfig;
```

- fadc
```c
typedef enum
{
    FADC_CONTINUOUS_CONVERT = 0,/* continuous conversion*/
    FADC_SINGLE_CONVERT = 1,    /* single conversion*/
    
    FADC_CONVERT_MODE_NUM
    
} FAdcCovertMode;
```

- fadc
```c
typedef enum
{
    FADC_MULTI_CHANNEL = 0, /* multi channel conversion*/
    FADC_FIXED_CHANNEL = 1, /* fixed channel conversion*/
    
    FADC_CHANNEL_MODE_NUM
} FAdcChannelMode;
```

- fadc
```c
typedef enum
{
    FADC_INTR_EVENT_COVFIN = 0,  /**< Handler type for convert finish interrupt */
    FADC_INTR_EVENT_DLIMIT = 1,  /**< Handler type for low limit interrupt*/
    FADC_INTR_EVENT_ULIMIT = 2,  /**< Handler type for high limit interrupt*/
    FADC_INTR_EVENT_ERROR  = 3,  /**< Handler type for error interrupt*/

    FADC_INTR_EVENT_NUM
} FAdcIntrEventType;

```

### 5.2  

- FADC_SUCCESS                 
- FADC_ERR_INVAL_PARM         
- FADC_ERR_NOT_READY          
- FADC_ERR_TIMEOUT            
- FADC_ERR_CMD_FAILED         

### 5.3. API

#### FAdcLookupConfig

- fadc

```c
const FAdcConfig *FAdcLookupConfig(FAdcInstance instance_id);
```

Note:

- 

Input:

- {FAdcInstance} instance_idadcid

Return:

- {const FAdcConfig *} adcNULL

#### FAdcCfgInitialize

- fadc, 

```c
FError FAdcCfgInitialize(FAdcCtrl *pctrl, const FAdcConfig *input_config_p);
```

Note:

- FAdcLookupConfig

Input:

- {FAdcCtrl} *pctrladc
- {FAdcConfig} *input_config_padc

Return:

- {FError} FADC_SUCCESS 

#### FAdcVariableConfig

- adc

```c
FError FAdcVariableConfig(FAdcCtrl *pctrl, u8 channel, FAdcConvertConfig *convert_config, 
                        FAdcThresholdConfig *threshold_config);
```

Note:

- adc

Input:

- {FAdcCtrl} *pctrladc
- {u8} channeladc
- {FAdcConvertConfig} *convert_configadc
- {FAdcThresholdConfig} *threshold_configadc

Return:

- {FError} FADC_SUCCESS 

#### FAdcChannelThresholdSet

- adc

```c
FError FAdcChannelThresholdSet(FAdcCtrl *pctrl, u8 channel, FAdcThresholdConfig *threshold_config);
```

Note:

- adc

Input:

- {FAdcCtrl} *pctrladc
- {u8} channeladc
- {FAdcThresholdConfig} *threshold_configadc

Return:

- {FError} FADC_SUCCESS 

#### FAdcConvertStart

- adc

```c
FError FAdcConvertStart(FAdcCtrl *pctrl);
```

Note:

- adc

Input:

- {FAdcCtrl} *pctrladc

Return:

- {FError} FADC_SUCCESS 

#### FAdcInterruptEnable

- adc

```c
FError FAdcInterruptEnable(FAdcCtrl *pctrl, u8 channel, FAdcIntrEventType event_type);
```

Note:

- adc

Input:

- {FAdcCtrl} *pctrladc
- {u8} channeladc
- {FAdcIntrEventType} event_type

Return:

- {FError} FADC_SUCCESS 


#### FAdcReadConvertResult

- adc

```c
FError FAdcReadConvertResult(FAdcCtrl *pctrl, u8 channel, u16 *val);
```

Note:

- adc

Input:

- {FAdcCtrl} *pctrladc
- {u8} channeladc
- {u16} *val

Return:

- {FError} FADC_SUCCESS 


#### FAdcRegisterInterruptHandler

- adc

```c
void FAdcRegisterInterruptHandler(FAdcCtrl *instance_p, FAdcIntrEventType event_type, 
                                    FAdcIntrEventHandler handler, void *param);
```

Note:
- 

Input:
- {FAdcCtrl} *instance_pfadc
- {FAdcIntrEventType} event_type
- {FAdcIntrEventHandler} handler
- {void} *param

Return:
- 

#### FAdcIntrHandler

- adc

```c
void FAdcIntrHandler(s32 vector, void *args);
```

Note:
- 

Input:
- {s32} vector
- {void} *param, fadc

Return:
- 
