@echo off

set /p size="Enter matrix size: "

python matrix_generation.py %size%

main.exe %size%
pause

python verification.py
pause