: BSP

    python2.7 (python2.6vs

 
rtconfig.py

1). msvc windows
  
    kernel
    finsh
    LWIP
    DFS, ELM FatFS, UFFS, JFFS2, DFS_WIN32
    RTGUI
    APP MODULE
2). mingw windows
    kernel
    finsh
    DFS, ELM FatFS, UFFS, DFS_WIN32
    RTGUI
    APP MODULE
3). gcc linux
    kernel
    finsh
    DFS, ELM FatFS, UFFS
    RTGUI

rtconfig.pyCROSS_TOOL

 
1) RTGUI
RTGUIgithubhttps://github.com/RT-Thread/RTGUI
RTGUIRTGUIcomponentsrtguiRt-threadcomponents

 
1) Visual Studio(2005)
cmd
`scons --target=vs -s`
vs2005project.vsprojvs2005(VS2005

vs2012
`scons --target=vs2012 -s`

2) 
rtconfig.py, (msvc/mingw/gcc)
cmd
`scons -j4`
 rtthread-win32.exe

 
1) 

 sd.bin--SDfat16M
 nand.bin-nand flashuffspage=2048+64bytesblock=64pages16M
 nor.bin--nor flashjffs2sst25vf2M
fatfs
`mkfs sd0`
FATFS

2) RTGUI
RTGUIfinshsnake_main()

3) APP module
rtconfig.hRT_USING_MODULE

app module3a, b, c

a. rtthread.def
`scons --def`rtthread.def
rtconfig.hrtthread.def.

b. 

  `scons -j4`

c. app module
  testdll testdll/SConstruct RTT_RTGUI 13)
  
    `scons --app=basicapp`
   basicapp/building basicapp.dll 

  simulator rtthread-win32.exe, finsh   
    `exec("/testdll/basicapp/build/basicapp.dll")` 
  basicapp.dll simualtor
    `exec("/basicapp.dll")`

  
  `scons --app=snake`snake/build/snake.dll
