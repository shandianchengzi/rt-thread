# LPM

## 

 CPU  RTOS  IDLE OS  IDLE CPU  IDLE RT-Thread  IDLE  CPU 

![PM](picture/pm_ostick.png) 

 IDLE  IDLE  OS Tick OS Tick OS tick

### [PM](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/pm/pm)

PMRT-Thread 

PM 

- PM 
- PM 
- PM 
- PM  OS Tick 
- PM 

PM

|                    |                                  |
| -------------------- | ---------------------------------- |
| PM_SLEEP_MODE_NONE     |   |
| PM_SLEEP_MODE_IDLE     | **** CPU  |
| PM_SLEEP_MODE_LIGHT    | ****CPU  |
| PM_SLEEP_MODE_DEEP     | ****CPU  |
| PM_SLEEP_MODE_STANDBY  | ****CPU () |
| PM_SLEEP_MODE_SHUTDOWN | **** Standby    |

### RALPM

RA2 MCULPM:

- Sleep mode
- Software Standby mode 
- Snooze mode 

|                 |                                                          |
| ----------------------- | ------------------------------------------------------------ |
| LPM_MODE_SLEEP          | ****CPUMCUSleep |
| LPM_MODE_STANDBY        | ****CPUCPUSRAMI/O |
| LPM_MODE_STANDBY_SNOOZE | ****CPUsnoozesnooze |



![image-20220705161631226](picture/lpm_mode.png)

Sleep>Snooze>Standby

RA2PM

| RA2                 | PM                |
| ----------------------- | --------------------- |
| LPM_MODE_SLEEP          | PM_SLEEP_MODE_IDLE    |
| LPM_MODE_STANDBY        | PM_SLEEP_MODE_DEEP    |
| LPM_MODE_STANDBY_SNOOZE | PM_SLEEP_MODE_STANDBY |


## LPM

RA2LPMbsp\renesas\ra2l1-cpk

- menuconfigLPMMDK5

![image-20220705172537997](picture/lpm_config.png)

- PMidle1024

![image-20220708183500091](picture/lpm_idle.png) 

- MDK5project.uvprojxFSPLPMstackLPMAGT1

![image-20220705183404587](picture/lpm_config1.png)

- LPMr_lpm**r_lpm**

![image-20220705185012409](picture/lpm_config2.png) 

### Sleep mode

r_lpmNameLow Power ModeNameg_lpm_sleepsleepstackLow Power ModeSleep mode

![image-20220705185611562](picture/lpm_config3.png) 

### Standby mode

Nameg_lpm_sw_standbyLow Power ModeSoftware Standby mode

MCUAGT1AGT1MCU

![image-20220705185734682](picture/lpm_config4.png) 

### Snooze mode

Nameg_lpm_sw_standby_with_snoozeLow Power ModeSnooze mode

MCUAGT1AGT1MCU

![image-20220705185903034](picture/lpm_config5.png) 

### AGT1

MCUAGT1PM

![image-20220706140137904](picture/lpm_config6.png) 

LPM


## DEMO

RT-ThreadRA2L1LPMDEMOMCU

DEMOCPK-RA2L1S1msh

### 

- IRQIRQ3

![image-20220706180228630](picture/lpm_demo1.png) 

![image-20220706180613033](picture/lpm_demo3.png) 

![image-20220706180438089](picture/lpm_demo2.png) 

- SnoozeStandbyIRQ3

![image-20220706181018705](picture/lpm_demo5.png) 

![image-20220706180846002](picture/lpm_demo4.png) 

- 

### 

```c
#include <rtthread.h>

#ifdef BSP_USING_LPM
#include <rtdevice.h>
#include <board.h>
#include <drivers/pm.h>

#define WAKEUP_APP_THREAD_STACK_SIZE        512
#define WAKEUP_APP__THREAD_PRIORITY         RT_THREAD_PRIORITY_MAX / 3
#define WAKEUP_EVENT_BUTTON                 (1 << 0)

static rt_event_t wakeup_event;

#define USER_INPUT  "P004"
#define LED2_PIN    "P501" /* Onboard LED pins */

void rt_lptimer_init(rt_lptimer_t  timer,
                   const char *name,
                   void (*timeout)(void *parameter),
                   void       *parameter,
                   rt_tick_t   time,
                   rt_uint8_t  flag);

rt_err_t rt_lptimer_detach(rt_lptimer_t timer);
rt_err_t rt_lptimer_start(rt_lptimer_t timer);
rt_err_t rt_lptimer_stop(rt_lptimer_t timer);

rt_err_t rt_lptimer_control(rt_lptimer_t timer, int cmd, void *arg);

static struct rt_lptimer lptimer; 

static void timeout_cb(void *parameter)
{
    rt_interrupt_enter();
    rt_kprintf("\n lptimer callback \n");
    rt_interrupt_leave();
}

static void lptimer_init(void)
{
    rt_lptimer_init(&lptimer,
                    "lpm",
                    timeout_cb,
                    (void*)&wakeup_event,
                    1000,
                    RT_TIMER_FLAG_PERIODIC);
}

static void lptimer_stop(void)
{
    rt_lptimer_stop(&lptimer);
}

static void lptimer_start(void)
{
    rt_lptimer_start(&lptimer);
}

static void led_app(void)
{
    static uint8_t key_status = 0x00;
    rt_uint32_t led2_pin = rt_pin_get(LED2_PIN);

    rt_pin_write(led2_pin, PIN_HIGH);
    switch(key_status%4)
    {
    case 0:/* IDLE */
		lptimer_stop();
        rt_pm_release(PM_SLEEP_MODE_NONE);
        rt_kprintf("\trequest:IDLE\n");
        rt_pm_request(PM_SLEEP_MODE_IDLE);
        break;
    case 1:/* DEEP */
		lptimer_stop();
		lptimer_start();
        rt_pm_release(PM_SLEEP_MODE_IDLE);
        rt_kprintf("\trequest:DEEP\n");
        rt_pm_request(PM_SLEEP_MODE_DEEP);
        break;
    case 2:/* STANDBY */
		lptimer_stop();
		lptimer_start();
        rt_pm_release(PM_SLEEP_MODE_DEEP);
        rt_kprintf("\trequest:STANDBY\n");
        rt_pm_request(PM_SLEEP_MODE_STANDBY);
        break;
    case 3:/* NONE */
		lptimer_stop();
        rt_pm_release(PM_SLEEP_MODE_STANDBY);
        rt_kprintf("\trequest:NONE\n");
        rt_pm_request(PM_SLEEP_MODE_NONE);
        break;
    default:
        break;
    }

    key_status++;
    rt_pin_write(led2_pin, PIN_LOW);
}

static void wakeup_callback(void* p)
{
    rt_event_send(wakeup_event, WAKEUP_EVENT_BUTTON);
}

void wakeup_sample(void)
{
    /* init */
    rt_uint32_t pin = rt_pin_get(USER_INPUT);
    rt_kprintf("\n pin number : 0x%04X \n", pin);
    rt_err_t err = rt_pin_attach_irq(pin, PIN_IRQ_MODE_RISING, wakeup_callback, RT_NULL);
    if (RT_EOK != err)
    {
        rt_kprintf("\n attach irq failed. \n");
    }
    err = rt_pin_irq_enable(pin, PIN_IRQ_ENABLE);
    if (RT_EOK != err)
    {
        rt_kprintf("\n enable irq failed. \n");
    }
}

static void wakeup_init(void)
{
    wakeup_event = rt_event_create("wakup", RT_IPC_FLAG_FIFO);
    RT_ASSERT(wakeup_event != RT_NULL);
    wakeup_sample();
}

static void pm_mode_init(void)
{
    rt_pm_release_all(RT_PM_DEFAULT_SLEEP_MODE);
    rt_pm_request(PM_SLEEP_MODE_NONE);
}

void pm_test_entry(void* para)
{
    /*  */
	wakeup_init();

    /*  */
    pm_mode_init();

	lptimer_init();
	
    while (1)
    {
        /*  */
        if (rt_event_recv(wakeup_event,
                            WAKEUP_EVENT_BUTTON,
                            RT_EVENT_FLAG_AND | RT_EVENT_FLAG_CLEAR,
                            RT_WAITING_FOREVER, RT_NULL) == RT_EOK)
        {
            led_app();
        }
    }
}

int pm_test(void)
{

    rt_thread_t tid = rt_thread_create(
            "pmtest",pm_test_entry,RT_NULL,512,10,10);
    if(tid)
        rt_thread_startup(tid);

    return 0;
}
MSH_CMD_EXPORT(pm_test, pm_test);
// INIT_APP_EXPORT(pm_test);
#endif
```

DEMOhal_entry.c


### 

`pm_test`DEMO

S1DEEPSTANDBY

![image-20220706183705384](picture/lpm_demo6.png) 

