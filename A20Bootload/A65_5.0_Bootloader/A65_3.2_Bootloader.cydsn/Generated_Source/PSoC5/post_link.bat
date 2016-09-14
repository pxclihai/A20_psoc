@REM This script allows a 3rd party IDE to use CyHexTool to perform
@REM any post processing that is necessary to convert the raw flash
@REM image into a complete hex file to use in programming the PSoC.
@REM USAGE: post_link.bat
@REM    arg1: Persistant path back to the directory containing the app project.
@REM    arg2: Path (relative to arg1) of the directory where the hex files go.
@REM    arg3: Name of the project.
@REM NOTE: This script is auto generated. Do not modify.

"C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\bin\cyvalidateide.exe" -dev CY8C5267AXI-LP051 -ide "%~1\%~3" -flsAddr 0x0 -flsSize 0x20000 -sramAddr 0x1FFFC000 -sramSize 0x8000
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
move "%~1\%~2\%~n3.hex" "%~1\%~2\%~n3.ihx"
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
"C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\bin\cyhextool" -o "%~1\%~2\%~n3.hex" -f "%~1\%~2\%~n3.ihx" -prot "%~dp0protect.hex" -id 2E133069 -a EEPROM=90200000:800,PROGRAM=00000000:20000,CONFIG=80000000:4000,PROTECT=90400000:80 -meta 0001 -cunv 00004005 -wonv BC90ACAF -ecc "%~dp0config.hex" 
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
CD /D "C:\Keil\UV4"
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
IF EXIST "C:\Tetraelc Company\Project\Shears_Bend_20130901\Shear_A60_Program\A60_Finish_Program\A62_Psoc_Ver_160x160\A62_Psoc_V0.0.07_20140116\A62_Psoc160_V1.0.01_20140123\A62_Bend.cydsn\A62_Bend.svd" "C:\Keil\UV4\SVDConv.exe" "C:\Tetraelc Company\Project\Shears_Bend_20130901\Shear_A60_Program\A60_Finish_Program\A62_Psoc_Ver_160x160\A62_Psoc_V0.0.07_20140116\A62_Psoc160_V1.0.01_20140123\A62_Bend.cydsn\A62_Bend.svd" -o "C:\Tetraelc Company\Project\Shears_Bend_20130901\Shear_A60_Program\A60_Finish_Program\A62_Psoc_Ver_160x160\A62_Psoc_V0.0.07_20140116\A62_Psoc160_V1.0.01_20140123\A62_Bend.cydsn" --generate=sfr -n "A62_Bend"
IF NOT EXIST "C:\Tetraelc Company\Project\Shears_Bend_20130901\Shear_A60_Program\A60_Finish_Program\A62_Psoc_Ver_160x160\A62_Psoc_V0.0.07_20140116\A62_Psoc160_V1.0.01_20140123\A62_Bend.cydsn\A62_Bend.svd" rem "C:\Tetraelc Company\Project\Shears_Bend_20130901\Shear_A60_Program\A60_Finish_Program\A62_Psoc_Ver_160x160\A62_Psoc_V0.0.07_20140116\A62_Psoc160_V1.0.01_20140123\A62_Bend.cydsn\A62_Bend.sfr"
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
