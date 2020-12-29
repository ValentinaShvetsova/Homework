@echo off
for /r in (*.c) do (
	cl /EHsc %%B
	%%~nB
	echo %%B
	echo %errorlevel%
	if %errorlevel% EQU 0 (
		echo test passed
	) else (
		echo test failed
	)
)
pause