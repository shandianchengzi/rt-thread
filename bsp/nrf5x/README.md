# nRF5x BSP 

## 

         Nordic nRF5x  MCU  Bluetooth  2.4 GHz 

         [sdk16.0](http://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v16.x.x/nRF5_SDK_16.0.0_98a08e2.zip)BSPSDKRT-THREADsdkRT-Thread

        `nrf52832(pca10040)``nrf52840`pca10056

        bspSTM32nordicnordicnordicnordicbsp

Nordic nRF5xBSP 

| nordic |                                                    | bsp |  |
| ------------ | ------------------------------------------------------------ | ------------- | ---- |
| nrf52840     | pca10056                                                 | nrf52840      |      |
| nrf52832     | pca10040                                                 | nrf52832      |      |
| nrf52840     | [52840](https://item.taobao.com/item.htm?spm=a1z10.1-c-s.w4004-15118192232.5.46a15d490SURQ9&id=581711815379) | nrf52840      |      |

### 

- softdevicesample ble_app_uartble_app_blinkyble_app_hrssoftdevicenordic
- nimblesample
- softdevicesampleRT-THREAD

  

### 

```
nrf5x
docs 
   images                      // nrf5x
   nRF5xBSP.md
libraries                       // nrf5xBSP
   drivers                     // nRF5x  
   templates                   //  BSP 
      nrf52x                  // nrf52x  BSP 
      nrf5x_board_kconfig     //  BSP 
nrf52832                        // nrf52832 BSP 
   application                 // 
      board                       // 
      package                     // 
      nRF5_SDK                // nordic  nRF5x SDK
      kconfig                     // 
   rtconfig.h
nrf52840                        // nrf52840 BSP 
README.md                       // nordic 
```

###  

#### RT-THREAD

         RT-THREADbsp

        BSPUARTGPIO

****

envkeilRT-THREAD

- `git clone https://github.com/RT-Thread/rt-thread.git`
- `rt-thread/bsp/nrf5x/nrf52840`
- env
- menuconfig BSP
- `pkgs --update` HAL
- `scons --target=mdk5`  keilLED
- softdevicert-thread

#### Softdevice 

ble_app_beacon(SDK16.0peripheral sample)

- menuconfig Hardware Drivers Config BLE STACK Nordic softdevice

![image-20201017191936859](docs/images/image-20201017191936859.png)

- menuconfig peripheral libraries and driversnrf5x_sdk

![image-20201017190154925](docs/images/softdevice_menuconfig.png)

- sample

![image-20201017190301705](docs/images/softdevice_2.png)

- `pkgs --update`, `scons --target=mdk5`  
- keil softdevicesoftdevice(SDK16.0softdevice)softdevice

![image-20201017192453525](docs/images/image-20201017192453525.png)

- rtthread

![image-20201017192639096](docs/images/image-20201017192639096.png)

-  `ble_app_beacon` samplelogbeacon

![image-20201017192807997](docs/images/image-20201017192807997.png)

- nrf connect beacon

![image-20201017193633608](docs/images/nrf_connect.jpg)

#### nimble

nimblesoftdevicenrf52840`git reset --hard`  `git clean -xfd`

- menuconfigBLE STACK nimble

- menuconfignimble

![image-20201017194305048](docs/images/nimble.png)

- Controller Configuration nrf52840
- Bluetooth Samples ble beacon sample
- `pkgs --update` 
- `scons --target=mdk5` 
- keilGNU extensions

![screen2021-08-19_100407](docs/images/screen2021-08-19_100407.jpg)

- keilsoftdeviceflashsoftdevice
- cmd `ble_ibeacon`
- nrf connect beacon



## RTT-STUDIO

RTT-STUDIO V2.2.0BSP

![image-20220609112426518](docs/images/image-20220609112426518.png)

### nRF5x BSPRTT-STUDIO

1. 

   ![image-20220609112322574](docs/images/image-20220609112322574.png)

2. BSP

   ![image-20220609112938212](docs/images/image-20220609112938212.png)

3. BSP

   ![image-20220609113142111](docs/images/image-20220609113142111.png)

   ![image-20220609113203519](docs/images/image-20220609113203519.png)

4. LOGBSP

   ```
   BSP
   scons --dist-ide --project-path=D:\RT-ThreadStudio\workspace/nrf52832_test --project-name=nrf52832_test
   ```

   ![image-20220609113439251](docs/images/image-20220609113439251.png)



5. 

   ![image-20220609113611068](docs/images/image-20220609113611068.png)

6. studio: 2.2.3

   ![image-20220609113726186](docs/images/image-20220609113726186.png)



		

		6.1 .settingsprojcfg.ini

				![image-20220609114026961](docs/images/image-20220609114026961.png)

		6.2 `J-Link`

![image-20220609114121378](docs/images/image-20220609114121378.png)

6.3 [](https://www.segger.com/supported-devices/jlink/)

![image-20220609114333827](docs/images/image-20220609114333827.png)

![image-20220609114533743](docs/images/image-20220609114533743.png)

![image-20220609114554402](docs/images/image-20220609114554402.png)

## FAQ:

#### 1. 

![image-20200912144630334](docs/images/faq1.png)

softdevicesoftdevice

softdevicekeilsoftdevice EraseFLASHsoftdevice

![image-20201017194935643](docs/images/softdevice_erase.png)



### 2.softdevicehardfault



```
psr: 0x8100000f
r00: 0x00000000
r01: 0x200034e6
r02: 0x00000000
r03: 0x200034dc
r04: 0x200034dc
r05: 0x00000000
r06: 0x200034e6
r07: 0xdeadbeef
r08: 0xdeadbeef
r09: 0xdeadbeef
r10: 0xdeadbeef
r11: 0xdeadbeef
r12: 0x00000000
 lr: 0x000369af
 pc: 0x00036972
hard fault on handler

```

hardfaultSOFTDEVICEhardfault

```
rt_hw_interrupt_disable    PROC
    EXPORT  rt_hw_interrupt_disable
    ;MRS     r0, PRIMASK
    ;CPSID   I
    BX      LR
    ENDP

;/*
; * void rt_hw_interrupt_enable(rt_base_t level);
; */
rt_hw_interrupt_enable    PROC
    EXPORT  rt_hw_interrupt_enable
    ;MSR     PRIMASK, r0
    BX      LR
    ENDP
```



