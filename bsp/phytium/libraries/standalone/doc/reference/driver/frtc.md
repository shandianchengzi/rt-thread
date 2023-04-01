# RTC 

## 1. 

- (RTC)

- RTC

- RTC  FT2000/4D2000

## 2. 

RTC RTC
- RTC
- RTC
- RTC


```
frtc
     frtc.c
     frtc.h
     frtc_g.c
     frtc_hw.c
     frtc_hw.h
     frtc_intr.c
     frtc_sinit.c
```


## 3. 

 RTC :

- RTC
- 
- RTC
- RTC

## 4. 


### [rtc_test](../../../baremetal/example/rtc_test/README.md)


## 5. API


### 5.1. 

- drivers/rtc/frtc/frtc.h

```c
typedef struct
{
	uintptr control_base_addr; /* rtc */
	const char *instance_name; /* instance name */
} FRtcConfig;				   /* rtc */

typedef struct
{
	FRtcConfig config; 	/* rtc */
	u32 is_ready;		/* rtc */
} FRtcCtrl;
```

- RTC

```c
typedef struct
{
	u16 year;  /*Specifies the RTC Date Year.
				This parameter must be a number between Min_Data = 2000 and Max_Data = 2099 */
	u8 month;  /*Specifies the RTC Date Month.
				This parameter must be a number between Min_Data = 1 and Max_Data = 12 */
	u8 mday;   /*Specifies the RTC day of Month.
				This parameter must be a number between Min_Data = 1 and Max_Data = 31 */
	u8 hour;   /*Specifies the RTC Time Hour.
				This parameter must be a number between Min_Data = 0 and Max_Data = 23 */
	u8 minute; /*Specifies the RTC Time Minute.
				This parameter must be a number between Min_Data = 0 and Max_Data = 59 */
	u8 second; /*Specifies the RTC Time Second.
				This parameter must be a number between Min_Data = 0 and Max_Data = 59 */
} FRtcDateTime;
```
### 5.2  

-  `0x1020000`

- [0x0] FRTC_SUCCESS : success

- [0x1020001] FRTC_ERR_DATE_INVALID : invalid date parameters

- [0x1020002] FRTC_ERR_TIME_INVALID : invalid time parameters


### 5.3. API

- RTC

```c
const FRtcConfig *FRtcLookupConfig(void);
```

    Note:

    - FRtcConfig

    Input:

    - void, RTC    

    Return:

    - const FRTCConfig *,  NULL


- RTC
```c
FError FRtcCfgInitialize(FRtcCtrl *instance_p, const FRtcConfig *config_p);
```

    Note:

    - FRtcConfig

    Input:

    - FRtcCtrl *instance_p, RTC 
    - const FRtcConfig *config_p, RTC

    Return:

    - FRTC_SUCCESS

- RTC

```c
FError FRtcSetDateTime(FRtcCtrl *pctrl, const FRtcDateTime *date_time);
```

    Note:

    - RTC

    Input:

    - FRtcCtrl *pctrl, RTC 
    
    - const FRtcDateTime *date, RTC

    Return:

    - u32, 5.2

- RTC

```c
FError FRtcGetDateTime(FRtcCtrl *pctrl, FRtcDateTime *date_time);
```

    Note:

    - RTC

    Input:

    - FRtcCtrl *pctrl, RTC 
    
    - FRtcDateTime *date, RTC

    Return:

    - u32, 5.2

- RTC

```c
time_t FRtcReadTimeStamp(FRtcCtrl *pctrl, time_t *sec, time_t *msec);
```

    Note:

    - RTCtime_t

    Input:

    - FRtcCtrl *pctrl, RTC

    - time_t *sec, NULL
    
    - time_t *msec, NULL

    Return:

    - time_t, <time.h>
