#  PPP 

   PPP  4G CAT-1  AT  PCI-E  CAT-1 

   PPP  RT-Thread lwIP  lwIP  PPP  RT-Thread  PPP_Device  Cat -1  ppp 

1.  ENV  ppp 

    ![](./picture/board.png) 

2.  ENV  IOT  PPP_Device 

    ![](./picture/select_ppp_device.png) 

3.  PPP_Device  APN  ```ppp device uart name```  ```uart2```

    ![](./picture/configure_apn_modem.png) 

4.  ENV  lwIP TCPIP<>  2048 

    ![](./picture/configure_lwip.png) 

5.  ppp_device_ec20.c EC20  -1

    ![](./picture/config_ppp_device_code.png) 

6.  FSP  UART2 
7.  SIM 
   ![image-20220223162348320](picture/ppp_sim.png) 

8. debug 

    RESRT 
   ![image-20220223163648879](picture/ppp_test.png) 
    `ifconfig`  `ping baidu.com` 
   ![image-20220223164520966](picture/ppp_test1.png) 