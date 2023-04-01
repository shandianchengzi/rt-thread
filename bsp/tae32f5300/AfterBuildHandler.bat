md build\keil\Execute

@echo off
:: enter .bat folder
cd %~dp0
:: 
set bat_path=%0
:: MDK $J KEIL 
set tool_chain_inc=%1
:: MDK #L KEILaxf
set axf_full_path=%2
:: axf
set axf_name=%~n2

if %tool_chain_inc:~-1,1% == \ (
    :: \
    set tool_chain_inc=%tool_chain_inc:~,-1%
)

:: call .bin generate function
call :binGenerate %tool_chain_inc% %axf_full_path%
if %errorlevel% == 1 (
    echo Failed 1: fromelf generate .bin failed!
    goto :EOF
)

:: call 
call :doFileCopy %axf_full_path%

:: hexPatchpatch.bin.hex
call :doFilePatch %axf_name%
if %errorlevel% == 1 (
    echo Failed 2: Patch failed!
    goto :EOF
)

exit /b %errorlevel%

:: Function Definiations ------------------------------------------------

:: .bin generate function
:binGenerate
:: 
set tool_chain_root=%~dp1
:: axf
set axf_path=%~dp2
:: axf
set axf_name=%~n2
:: echo %axf_path%
:: echo %axf_name%
:: echo %tool_chain_root%
:: fromelf bin
%tool_chain_root%bin\fromelf --bin %2 --output %axf_path%\%axf_name%.bin
exit /b %errorlevel%

:: axf/hex/binExecute
:doFileCopy
:: axf
set axf_name=%~n1
copy /Y .\build\keil\Obj\%axf_name%.axf .\build\keil\Execute\%axf_name%.axf
copy /Y .\build\keil\Obj\%axf_name%.hex .\build\keil\Execute\%axf_name%.hex
copy /Y .\build\keil\Obj\%axf_name%.bin .\build\keil\Execute\%axf_name%.bin
:: hex
exit /b 0

:: Patch
:doFilePatch
set target_name=%1
Patcher.exe .\build\keil\Execute\%target_name%.hex
exit /b %errorlevel%
