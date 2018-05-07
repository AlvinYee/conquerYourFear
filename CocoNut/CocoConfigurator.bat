@echo off
echo ************************************************************************
echo [INFO]: CocoNut.CocoConfigurator starts
echo [version]: 1.0
echo ************************************************************************

set _HDL_RMH_Cfg=..\template\_HDL_RMH_Cfg.h
set _HDL_TMH_Cfg=..\template\_HDL_TMH_Cfg.h
set _HCM_LCD_Cfg=..\template\_HCM_LCD_Cfg.h

set HDL_RMH_Cfg=..\output\HDL_RMH_Cfg.h
set HDL_TMH_Cfg=..\output\HDL_TMH_Cfg.h
set HCM_LCD_Cfg=..\output\HCM_LCD_Cfg.h

if not exist %_HDL_RMH_Cfg% goto ErrorWrongPath
if not exist %_HDL_TMH_Cfg% goto ErrorWrongPath
if not exist %_HCM_LCD_Cfg% goto ErrorWrongPath

if not exist %HDL_RMH_Cfg% cd.> %HDL_RMH_Cfg%
if not exist %HDL_TMH_Cfg% cd.> %HDL_TMH_Cfg%
if not exist %HCM_LCD_Cfg% cd.> %HCM_LCD_Cfg%

python -m cogapp -d -o %HDL_RMH_Cfg% %_HDL_RMH_Cfg%
python -m cogapp -d -o %HDL_TMH_Cfg% %_HDL_TMH_Cfg%
python -m cogapp -d -o %HCM_LCD_Cfg% %_HCM_LCD_Cfg%

goto End
:ErrorWrongPath
echo ************************************************************************
echo [ERROR]: template file does not exist
echo ************************************************************************

:End
echo ************************************************************************
echo [INFO]: CocoNut.CocoConfigurator ends
echo ************************************************************************
pause
