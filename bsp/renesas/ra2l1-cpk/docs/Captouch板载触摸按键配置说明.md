# Captouch

## 

(CTSU2)CTSU

()

![image-20220802110717583](picture/captouch1.png) 

CTSUCTSU

![image-20220802111936905](picture/captouch2.png) 

CPK-RA2L1

## FSP

FSPMDKprojectREADMEFSPFSPMDKFSP

FSP**Pins** **Peripherals** **Input: CTSU** CTSU0  

![image-20220802113049978](picture/captouch3.png) 

### CapTouch

**Stacks****HAL/Common Stacks****New Stack****CapTouch**->**Touch (rm_touch)**

![image-20220802114613066](picture/captouch4.png) 

rm_touchUARTTuningmonitoring

![image-20220802115356241](picture/captouch5.png) 

UART

![image-20220803110210310](picture/captouch6.png) 

### UART

UARTUART 0channel

![image-20220803114356569](picture/captouch7.png) 

SCI0SPISCI0UART

![image-20220803114511416](picture/captouch8.png) 

stacksUARTDTCDTC

![image-20220803114731495](picture/captouch9.png) 

UARTrxtxDTC

![image-20220803114819813](picture/captouch10.png) 



![image-20220803114919483](picture/captouch11.png) 

### r_ctsu

r_ctsuDTCDTC

![image-20220803115033965](picture/captouch12.png) 

![image-20220803115133548](picture/captouch13.png) 



![image-20220803115205206](picture/captouch14.png) 

### 

FSP MDK

![image-20220803134930532](picture/captouch15.png) 

FSP QE for Capacitive Touch 

## QE for Capacitive Touch

[QE](https://www.renesas.com/cn/zh/software-tool/qe-capacitive-touch-development-assistance-tool-capacitive-touch-sensors) QE for Capacitive Touch

![image-20220803142500065](picture/captouch16.png) 



![image-20220803143218409](picture/captouch17.png) 

 eclipseqe-touch.exe

![image-20220803143307233](picture/captouch18.png) 

QE

![image-20220803144721954](picture/captouch19.png) 

### 

ra2l1-cpkBSP

![image-20220803145816770](picture/captouch20.png) 

![image-20220803145832333](picture/captouch21.png) 



![image-20220803150443690](picture/captouch22.png) 

### 

***Create a new configuration***

![image-20220803150603024](picture/captouch23.png) 

 ***Button***  ESC  

 RED X ***There are some problems with setting*** MCU  

 Button00 TS32  MCU  

![	](picture/captouch24.png) 

***Create***

![image-20220803152119579](picture/captouch25.png) 

`ra2l1-cpk/QE-Touch`

![image-20220803152648669](picture/captouch26.png) 

![image-20220803152701419](picture/captouch27.png) 

![image-20220803152715716](picture/captouch28.png) 

sample

![image-20220803154102544](picture/captouch29.png) 

RT-ThreadsampleENV`scons --target=mdk5`MDKsample

![image-20220803154630457](picture/captouch30.png) 

MDKdebugjlink`r7fa2l1ab`OK

![image-20220803155646859](picture/captouch_jlink.png) 

MDKdebugrun

![image-20220804141317303](picture/captouch_dbg.png) 

touchsample

![image-20220803155821105](picture/captouch_msh.png) 

### Tuning

QETuningUART0(P100P101)USB-TTL

![image-20220804140317043](picture/captouch_tuning0.png) 

 ![image-20220803152701419](picture/captouch27.png)

![image-20220803152715716](picture/captouch28.png) 



![image-20220804104724939](picture/captouch_tuning.png) 

  Tuning  BTN3TS28/ Tuning

 BTN3/TS28**** BTN1 ()  BTN1  BTN2 

![image-20220804105539784](picture/captouch_tuning1.png) 

 1000 

 Tuning< 10pF Tuning CTSU/CTSU2 IP  10pF  10pF 

![image-20220804105830232](picture/captouch_tuning2.png) 

***Continue the Tuning Process***  Tuning

![image-20220804110018273](picture/captouch_tuning3.png) 

Tuning***Output Parameter Files*******

![image-20220804110107072](picture/captouch_tuning4.png) 

### 

UART

![image-20220804113515382](picture/captouch_tuning5.png) 

***Enable Monitoring***

 CapTouch Status Chart (QE) 

 CapTouch Multi Status Chart (QE) 

![image-20220804114016844](picture/captouch_monitoring.png) 

LED
