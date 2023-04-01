# RA FSP 

## 1. 

###  1.1  MDK FSP

1.  MDK Tools -> Customize Tools Menu
2.  new : RA Smart Configurator
3. Command  ****rasc.exe (rasc )
4. Initial Folder : $P
5. Arguments : --device $D --compiler ARMv6 configuration.xml
6.  OK 

![img](figures/customize.png) 

7.  Tools -> RA smart Configurator****RA Smart Config

![image.png](figures/openrasc.png) 

PS FSP 

FSP https://www2.renesas.cn/jp/zh/software-tool/flexible-software-package-fsp#document

###  1.2 

####  1.2.1 FSP 

RA **FSP 3.5.0**  **FSP 3.5.0** ****

** RASC  FSP version BoardDevice **

![fsp_version](figures/fsp_version.png) 

#### 1.2.2 

 FSP   

![img](figures/import_changes.png) 

## 2.  FSP 

**PS**

### UART

 UART 

1.  Stacks  New Stack  UART
![image.png](figures/fsp_uart.png) 

2.  UART  RT-Thread **name** **channel**  **callback** 
![image.png](figures/fsp_uart1.png)

###  GPIO 

 IO 

1.  P105  IRQx 

![image-20211103200949759](figures/p105.png) 

2.  ICU  IRQ00

![image-20211103200813467](figures/irq0.png) 

3.  stack  RT-Thread  **name** **channel** **callback**`irq_callback`

![](figures/1635929089445.png) 

![image-20211103201047103](figures/irq1.png) 

4. 

   ```c
   #define IRQ_TEST_PIN	"p105"
   void irq_callback_test(void *args)
   {
       rt_kprintf("\n IRQ00 triggered \n");
   }

   void icu_sample(void)
   {
       /* init */
       rt_uint32_t pin = rt_pin_get(IRQ_TEST_PIN);
       rt_kprintf("\n pin number : 0x%04X \n", pin);
       rt_err_t err = rt_pin_attach_irq(pin, PIN_IRQ_MODE_RISING, irq_callback_test, RT_NULL);
       if(RT_EOK != err)
       {
           rt_kprintf("\n attach irq failed. \n");
       }
       err = rt_pin_irq_enable(pin, PIN_IRQ_ENABLE);
       if(RT_EOK != err)
       {
           rt_kprintf("\n enable irq failed. \n");
       }
   }
   MSH_CMD_EXPORT(icu_sample, icu sample);
   ```

### WDT

1.  WDT

![image-20211019152302939](figures/wdt.png) 

2.  WDT RT-Thread  WDT  WDT  name `g_wdt` 

![image-20211019152407572](figures/wdt_config.png) 

3.  ENV  WDT [WDT ](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/watchdog/watchdog)

![image-20211027183406251](figures/wdt_env.png) 

### RTC

1.  RTC 

![image-20211019152536749](figures/rtc.png) 

2.  RTC RT-Thread  RTC  RTC  name `g_rtc`  Callback  rtc_callback

![image-20211019152627412](figures/rtc_config.png) 

3.  ENV  RTC [ RTC ](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/rtc/rtc)

![image-20211027181550233](figures/rtc_env.png) 

### Flash

1.  Flash

![image-20211026105031200](figures/add_flash.png) 

2.  Flash RT-Thread  flash  flash  name `g_flash` 

![image-20211026105628706](figures/config_flash.png) 

3.  ENV  Flash

![image-20211026123252310](figures/flash_menuconfig.png) 

### SPI

1.  SPI 

![image-20211027180820968](figures/spi_add.png) 

2.  channelnameClock PhaseClock PolarityCallback SPI Mode  API 

![img](figures/fsp_spi1.png) 

3.  Pins  SPI1 ** SSLx **

![image-20211209162334093](figures/fsp_spi2.png) 


4.  ENV  SPI  [SPI ](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/spi/spi)

   ![image-20211027181444023](figures/spi_env.png) 

### ADC/DAC

 ADC/DAC

![img](figures/adc_dac.png) 

- **ADC**

1.  nameunitmode

![img](figures/adc_config.png) 

2. 

![img](figures/adc_config1.png) 

3.  menuconfig 

- **DAC**

1.  P014  mode

![img](figures/dac_config0.png) 

2.  DAC0 

![img](figures/dac_config1.png) 

3.  0 DAC0 

![img](figures/dac_config2.png) 

4.  menuconfig 

### PWMGPT

GPT  PWM  PWM GPT  gpt0 - gpt9  10  PWM  PWM 

1.  GPT 

![img](./figures/add_gpt1.png) 

2. 

![img](./figures/add_gpt2.png) 

    GPT 

   1. ``Common`` ->``Pin Output Support``  Enable  PWM 
   2.  GPT  GPT  GPT  3  GPT ``g_timer3`` PWM  PWM 
   3.  PWM  50% 
   4.  GPT 
   5.  GPT 
3. 

![img](./figures/add_gpt3.png) 

    GPT  GPT  GPT3 **1**  ``GTIOCA or GTIOCB``  **2**  GPT 

   4.  menuconfig [RT-Thread  pwm ](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/pwm/pwm)

![image-20211103202216381](figures/pwm_env.png) 

### CAN

1. CAN

![image-20211102145023112](figures/can.png) 

2. Callback `can0_callback`  `can1_callback`

![image-20211102145227603](figures/can_callback.png) 

3. 

4. ENVCAN[CAN](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/can/can)

![image-20211102145613309](figures/can_menuconfig.png) 

### SDHI

1. sdhi

![sdhi](figures/sdhi_config.png) 

1. DMAC

![DMAC](figures/dmac_config.png) 

2. DMAC

![DMAC](figures/dmac_int.png) 

3. SDHI

![SDHI](figures/sdhi_config1.png) 

4. ENVSDHI

![SDHI](figures/sdhi_env.png) 

5. ENVDFSFatFS

![DFS](figures/sdhi_dfs.png) 

6.  `mkfs sd0 -t elm` sd

7.  `mount sd0 / elm` sd0 `/`

8. RT-Thread DFS[ (rt-thread.org)](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/filesystem/filesystem)

### WiFi : [RW007 ](https://github.com/RT-Thread-packages/rw007) 

1.  RW007

![image-20211108142805319](figures/rw007_pkg.png) 

2. menuconfig  RW007  SPI1  SPI1 

![image-20211108142453678](figures/rw007_spi.png) 

![image-20211213212034701](figures/drv_rw007.png) 

3.  [WLAN ](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/wlan/wlan)

![image-20211108143027485](figures/rw007_wlan.png) 

 NETDEV 

![image-20211108143712513](figures/rw007_netdev.png) 

 kernel  mempool 

![image-20211209161902884](figures/rw007_mempool.png) 

4. FSP  SPI [SPI](#SPI) SPI1 

![image-20211108183631379](figures/fsp_spi1.png) 

5. RW007  INT  IRQ  P506 

![image-20211108183724282](figures/rw007_int.png) 

6. RW007  RESET  RASC  mode  RW007 

![image-20211213144108558](figures/rw007_reset.png) 

7.  MDK 

![image-20211109102232233](figures/rw007_mdk.png) 

8. 

 RW007 `wifi scan`  WiFi [ WiFi ](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/wlan/wlan?id=finsh-%e5%91%bd%e4%bb%a4)

![image-20211109103856130](figures/rw007_test.png) 

 `WiFi join`  WiFi  

![image-20211109104735733](figures/rw007_wifijoin.png) 

 `ping rt-thread.com` 

![image-20211109104700939](figures/rw007_ping.png) 