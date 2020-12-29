@echo off
for /r C:\Users\Aser_Pc\Desktop\Си\Homework\Homework2\ %%B in (*.c) do (
	cl /EHsc %%B
	echo %%B
	echo %errorlevel%
	if not errorlevel 1 (
		echo test passed
	) else (
		echo test failed
	)
)
pause