@echo off
set /p num=Enter a value: 
set /a mod=num %% 2
if %mod% == 0 (
  echo even
) else (
  echo odd
)
