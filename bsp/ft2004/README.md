# ft2004  BSP 

## 

  ft2000/4  BSP () 



- 
- BSP 
- 
- 

### 1. 

FT-2000/4  4  2  1
Cluster L2 Cache

-  ARM v8 64  32 
- 
-  ASIMD 
-  2  DDR4  DDR 
-  34 Lane PCIE3.0 2  X16 2  X82  X1
-  2  GMACRGMII  10/100/1000 
-  1  SD  SD 2.0 
-  1  HDAudio 4  Codec
-  SM2SM3SM4 
-  4  UART1  LPC32  GPIO4  I2C1  QSPI2 
   SPI2  WDT16  GPIO  IO
- 

### 2. BSP 

|    |  |                    |
| -------- | -------- | ---------------------- |
| ft_gicv3 |      | gicv3        |
| ft_gmac  |      | ft gmac  |
| ft_i2c   |      | FT I2C                 |
| ft_qspi  |      | FT qspi          |
| ft_sd    |      | FT mmcsd         |
| ft_uart  |      | PrimeCell PL011        |
| ft_spi   |      | FT spi           |
| ft_gpio  |      | FT gpio          |
| ft_can   |      | FT can           |

### 3. 

#### ubuntu 

1.  ubuntu 

```
sudo apt-get install gcc-arm-none-eabi
```

2. 

```
arm-none-eabi-gcc -v
```

3.  tftp 

   -  tftp 
     >  ubuntu 

   ```
   sudo apt-get install tftp-hpa tftpd-hpa
   sudo apt-get install xinetd
   ```

   -  tftboot :
     `/mnt/d/tftboot`

   >  tftboot `chmod 777 /**/tftboot`

   -  tftpboot 

   /etc/xinetd.d/tftp

   ```
   # /etc/xinetd.d/tftp

   server tftp
   {
   socket_type = dgram
   protocol = udp
   wait = yes
   user = root
   server = /usr/sbin/in.tftpd
   server_args = -s /mnt/d/tftboot
   disable = no
   per_source = 11
   cps = 100 2
   flags = IPv4
   }
   ```

   -  tftp 

   ```
   sudo service tftpd-hpa start
   ```

   -  tftp 
     /etc/default/tftpd-hpa

   ```
   sudo nano /etc/default/tftpd-hpa
   # /etc/default/tftpd-hpa

   TFTP_USERNAME="tftp"
   TFTP_DIRECTORY="/mnt/d/tftboot"
   TFTP_ADDRESS=":69"
   TFTP_OPTIONS="-l -c -s"
   ```

   -  tftp 
     > 

   ```
   sudo service tftpd-hpa restart
   ```

   -  tftp 
     >  tftp 

   ```
   $ tftp 192.168.4.50
   tftp> get test1234
   tftp> q
   ```

#### 

1.  bsp  RT-THREAD bsp/

1.  Ubuntu  bsp 

```
cd rt-thread/bsp/ft2004
```

3.  scons -c 

4.  scons --menuconfig 

![](./figures/onchipPeripheral.png)

5.  scons , rtthread.bin rtthread.bin  tftp 

6.  PC, 115200-8-1-N

7. 

8.  uboot uboot   bin  ram 

```
setenv ipaddr 192.168.x.x      # ip
setenv serverip 192.168.x.x    # tftpip
setenv gatewayip 192.168.x.x   # ip
tftpboot 80100000 rtthread.bin #  /tftpbootrtthread.bin80100000
```

7. 

```
bootvx32 80100000

boot32 80100000
```

![](./figures/.png)

### 5. 

#### 

-  ping   sudo ping 192.168.3.20 ()

- rtt ping   ping 192.168.x.x ()

- 

![](./figures/rttPing.png)

#### sd 

- mv echo ls cd rm ....

![](./figures/rttsd.png)

#### spi flash 

-  spi flash  ft-2004  sf25s  gd25q  spi flash
-  rt-thread  BSP_USE_SPI  BSP_USE_GPIO  BSP_USE_QSPI  rt-thread  SFUD 
-  rt-thread spi flash probe 
-  sf read, write, erase

#### 

1. sf probe S25FS256

2. sf read 0x1FFF000 16

3. sf write 0x1FFF000 16 25 68 78 95 15 75 20

4. sf read 0x1FFF000 16

5. sf erase 0x1FFF000 16

#### can 

1.  scons menuconfig  Enable Can

2.  Enable can0 Enable can0 work in loop back

3. 

4.  can  1000000

5.  can 

## 6. 

- ARM Architecture Reference Manual

- FT-20004 -V1.4

## 7. 



huanghe@phytium.com.cn

zhugengyu@phytium.com.cn
