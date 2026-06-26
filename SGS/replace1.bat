@echo off

set /a "randomNum=%RANDOM% %% 4 + 1"

echo Random number between 1 and 4: %randomNum%

pause

reg add "hkcu\control panel\desktop" /v wallpaper /d "C:\Users\Administrator\Desktop\SGS\wallpaper\%randomNum%.bmp " /f

RunDll32.exe USER32.DLL,UpdatePerUserSystemParameters
RunDll32.exe USER32.DLL,UpdatePerUserSystemParameters

pause

exit




