@echo off

set /a "randomNum=%RANDOM% %% 28 + 1"

echo Random number between 1 and 28: %randomNum%

pause

reg add "hkcu\control panel\desktop" /v wallpaper /d "
C:\Users\Administrator\Desktop\SGS\wallpaper\bmp\%randomNum%.bmp " /f

RunDll32.exe USER32.DLL,UpdatePerUserSystemParameters
RunDll32.exe USER32.DLL,UpdatePerUserSystemParameters

pause

exit







