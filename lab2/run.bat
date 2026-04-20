@echo off

:loop
cls
echo (write q to quit)

set /p size="Enter matrix size: "
if  /i "%size%" == "q" goto end

set /p threads="Enter threads: "
if  /i "%threads%" == "q" goto end

python matrix_generation.py %size%
main.exe %size%  %threads%
python verification.py
pause

goto loop
:end