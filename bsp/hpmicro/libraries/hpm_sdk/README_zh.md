# HPM SDK 
HPM SDKHPMicro MCUMCUBSDRTOSlittlevgl/ lwIP/ TinyUSB/ FreeRTOS

# HPM SDK

## 

|  |  |
|--- | --- |
| CMake | 3.13 |
| Python | 3.8 |

## 

- Ubuntu:
  - :

```shell
    sudo apt install build-essential cmake ninja-build libc6-i386 libc6-i386-cross libstdc++6-i386-cross
```

  - python3 (3.8.5 minimum) pip:

```shell
    sudo apt install python3 python3-pip
```

- Windows:
  - Windows:
  Windows(cmd.exe):
    -  Chocolatey (<https://chocolatey.org/>):
    Windows,Windows:
    1. Chocolatey(<https://chocolatey.org/install>)
    2. "cmd.exe"
    3. :

      ```Batchfile
          choco feature enable -n allowGlobalConfirmation
      ```

    4. CMake:

      ```Batchfile
          choco install cmake --installargs 'ADD_CMAKE_TO_PATH=System'
      ```

    5. :

      ```Batchfile
          choco install git python ninja
      ```

    6. 

## 

- :
  - gnu-gcc <-- 
  - nds-gcc
- :
  - gnu-gcc:
      - ,.TOOLCHAIN_PATH(TOOLCHAIN_PATH\binriscv32-unknown-elf-gcc)
      - "GNURISCV_TOOLCHAIN_PATH":
        - Linux, zsh(TOOLCHAIN_PATH):
    ```shell
      export GNURISCV_TOOLCHAIN_PATH=TOOLCHAIN_PATH
      export HPM_SDK_TOOLCHAIN_VARIANT=
    ```
    - Windows:
    ```Batchfile
      set GNURISCV_TOOLCHAIN_PATH=TOOLCHAIN_PATH
      set HPM_SDK_TOOLCHAIN_VARIANT=
    ```
  - nds-gcc:
      - ,.TOOLCHAIN_PATH(TOOLCHAIN_PATH\binriscv32-elf-gcc)
      - "GNURISCV_TOOLCHAIN_PATH":
        - Linux, zsh(TOOLCHAIN_PATH):
    ```shell
      export GNURISCV_TOOLCHAIN_PATH=TOOLCHAIN_PATH
      export HPM_SDK_TOOLCHAIN_VARIANT=nds-gcc
    ```
    - Windows:
    ```Batchfile
      set GNURISCV_TOOLCHAIN_PATH=TOOLCHAIN_PATH
      set HPM_SDK_TOOLCHAIN_VARIANT=nds-gcc
    ```
    Note: WindowsAndes toolchaincygwin:
           - cygwin1.dll
           - cygncursesw-10.dll
          PATH

- SDK:
  - :
    - Linux:

    ```shell
      source env.sh
    ```

    - Windows :

    ```Batchfile
      env.cmd
    ```

  - "HPM_SDK_BASE"SDK:
    - Linux, zsh($HOME/hpm_sdkSDK):

    ```shell
      export HPM_SDK_BASE=$HOME/hpm_sdk
    ```

    - Windows (c:\hpm_sdkSDK):
    ```Batchfile
      set HPM_SDK_BASE=c:\hpm_sdk
    ```

- Python:
  - Linux:

  ```shell
    pip3 install --user -r "$HPM_SDK_BASE/scripts/requirements.txt"
  ```

  - Window (WindowsPython 3.x  python3/pip3, python/pip):
  ```Batchfile
    pip install --user -r "%HPM_SDK_BASE%/scripts/requirements.txt"
  ```

- GNU GCC:
    , SDK.  hello_world:
    1. :

    ```shell
      cd samples/hello_world
    ```

    2. build:
       - Linux:

        ```shell
          mkdir build
        ```

       - Windows:

        ```Batchfile
          md build
        ```

    3. "build"

    ```shell
      cd build
    ```

    4. Ninja-build:

    ```shell
      cmake -GNinja -DBOARD=hpm6750evk ..
    ```

    Note: "CMAKE_MAKE_PROGRAM is not set", "-DCMAKE_MAKE_PROGRAM=YOUR_MAKE_EXECUTABLE_PATH" (NINJA_PATHninja-build,ninja):
        # cmake -GNinja -DBOARD=hpm6750evk -DCMAKE_MAKE_PROGRAM=NINJA_PATH/ninja ..

    5. :

    ```shell
      ninja
    ```

    ,elfoutput.

- /(hello_world):
    1. ,,
    2. 
    3. ,baudrate115200
    4. openocd(0.11)
    5. SDK, :
    - Linux:

      ```shell
        $ source env.sh
      ```
    - Windows command prompt:

      ```Batchfile
        env.cmd
      ```
    OPENOCD_SCRIPTS:
    - Linux:
      ``` shell
        $ export OPENOCD_SCRIPTS=${HPM_SDK_BASE}/boards/openocd

      ```
    - Windows:
      ```
        set OPENOCD_SCRIPTS=%HPM_SDK_BASE%\boards\openocd
      ```

    6. openocd, : , , ft2232hpm6750evk:

    ```shell
      openocd -f probes/ft2232.cfg -f soc/hpm6750-single-core.cfg -f boards/hpm6750evk.cfg
    ```

    Note: FTDI`Error: libusb_open() failed with LIBUSB_ERROR_NOT_FOUND` , FTDI usb [zadig](https://github.com/pbatard/libwdi/releases/download/b730/zadig-2.5.exe) 

    zadig Options->List All Devices.

    ![List All Devices](doc/images/readme/zadig_list_all_devices.png)

     Dual RS232-HS (Interface 0).

    ![Select Dual RS232-HS (Interface 0)](doc/images/readme/zadig_select_dual_rs232-hs.png)

      Install Driver  Replace Driver.

    ![Replace Driver](doc/images/readme/zadig_replace_driver.png)

    7. hello_world

    ```shell
      cd samples/hello_world
    ```

    8. ,GDB client:
    - gnu-gcc:

    ```shell
      TOOLCHAIN_PATH/bin/riscv32-unknown-elf-gdb
    ```

    - nds-gcc:

    ```shell
      TOOLCHAIN_PATH/bin/riscv32-elf-gdb
    ```

    9. GDB clientopenocd GDB server (, openocd gdbserver  3333)

    ```GDB
      gdb> file build/output/hello_world.elf
      gdb> target remote localhost:3333
      gdb> load
      gdb> b main
      gdb> c
    ```
    10. "hello_world".

- Segger Embedded Studio for RISC-V
  - Segger Embedded Studio for RISC-V  https://www.segger.com/downloads/embedded-studio/ 
  - Segger Embedded Studio for RISC-V  "GNU GCC:" -> "4. Ninja-build:" 
  - (.emProject)build/segger_embedded_studio

  openocdPATH, Segger Embedded Studio

# 