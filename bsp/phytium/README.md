
# PHYTIUM BSP 

## 

 RT-THREAD  Phytium  CPU  BSP 

:

- BSP 
- 
-  Ubuntu/Windows  BSP
- 
- 
- 


## BSP

- CPUSCPUDCPUE



- BSPDE CPU, Phytium-Standalone-SDK 

- BSP PhytiumCPU  aarch32/aarch64  CPU 



## 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| UART              |          | uart1 |

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| E2000D              |          | SMP |
| E2000Q              |          | SMP |
| E2000S              |          | |


##  Ubuntu/Windows BSP


### Ubuntu 

1.  [Linux x86_64 SDK](https://gitee.com/phytium_embedded/phytium-standalone-sdk/blob/release/doc/reference/usr/install_linux_x86_64.md) 1.1  - 1.2  SDK 
2. [RT-Thread/env](https://github.com/RT-Thread/env) Tutorial ubuntu  env 
3.  ```source ~/.env/env.sh```
4. aarch32 ```cd bsp/phytium/aarch32```


### Windows 

1. [Windows 10 SDK](https://gitee.com/phytium_embedded/phytium-standalone-sdk/blob/release/doc/reference/usr/install_windows.md) SDK  Windows  AARCH32_CROSS_PATH  AARCH64_CROSS_PATH
2. [RT-Thread/env](https://github.com/RT-Thread/env) Tutorial  Windows  env 
3. aarch32 ```cd bsp/phytium/aarch32```
4.  export_project.py  BSP 
5.  RT-Studio  BSP 


## 

### 

- [AARCH32](./aarch32/README.md)
- [AARCH64](./aarch64/README.md)

###  

#### Ubuntu  tftp 

- `host``tftp`

```
sudo apt-get install tftp-hpa tftpd-hpa
sudo apt-get install xinetd
```

-  tftboot , `/mnt/d/tftboot`, makefileUSR_BOOT_DIR,  tftboot `chmod 777 /**/tftboot`

-  tftpboot , `/etc/xinetd.d/tftp`

```
# /etc/xinetd.d/tftp

server tftp
{
  socket_type = dgram
  protocol = udp
  wait = yes
  user = root
  server =  /usr/sbin/in.tftpd
  server_args = -s /mnt/d/tftboot
  disable = no
  per_source = 11
  cps = 100 2
  flags = IPv4
}
```

- `tftp`

```
$ sudo service tftpd-hpa start
```

- `tftp``tftboot`
  /etc/default/tftpd-hpa

```
$ sudo nano /etc/default/tftpd-hpa
# /etc/default/tftpd-hpa

TFTP_USERNAME="tftp"
TFTP_DIRECTORY="/mnt/d/tftboot"
TFTP_ADDRESS=":69"
TFTP_OPTIONS="-l -c -s"
```

- `tftp`

```
$ sudo service tftpd-hpa restart
```

- `tftp`
  > `tftp``tftboot`

```
$ tftp 192.168.4.50
tftp> get test1234
tftp> q
```

#### Windows tftp 

- Tftpd64  Tftpd64 

![](./figures/tftp32_srv.png)

- Windows

![](./figures/config_tftp32.png)

#### uboot tftp 

- `u-boot`ip`host`ip
  ```
  setenv ipaddr 192.168.4.20  
  setenv serverip 192.168.4.50 
  setenv gatewayip 192.168.4.1 
  ```
- elf bin Tftpd64
- 
  
  ```
  tftpboot 0x90100000 rtthread.elf
  bootelf -p 0x90100000
  ```

### 

![](./figures/result.png)


## 

- huanghe:  huanghe@phytium.com.cn
- zhugengyu:  zhugengyu@phytium.com.cn