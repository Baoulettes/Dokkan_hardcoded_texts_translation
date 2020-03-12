@echo off
SET "GENERATOR=Ninja"
SET "NINJA_VERSION=1.9.0"
SET "ANDROID_NDK_REV=r20"
SET "DOKKAN_SDK_REV=r1"
SET "ANDROID_MIN_SDK=21"
CALL :NORMALIZEPATH "..\..\"
SET "UD_SDK_ROOT=%RETVAL%"

echo UD_SDK_ROOT: %UD_SDK_ROOT%

SETLOCAL ENABLEDELAYEDEXPANSION
FOR /F "delims== tokens=1,*" %%a in ('type "%UD_SDK_ROOT%\deps\dependencies-windows.ini"') DO ( 
    IF "%%a"=="AndroidNDK" (
        SET "ANDROID_NDK_PATH=%%b"
    )
    IF "%%a"=="Ninja" (
        SET "NINJA_PATH=%%b"
    )
    IF "%%a"=="CMake" (
        SET "CMAKE_PATH=%%b"
    )
)
echo ANDROID_NDK_PATH:
echo !ANDROID_NDK_PATH!
echo NINJA_PATH:
echo !NINJA_PATH!
echo CMAKE_PATH
echo !CMAKE_PATH!
echo -

mkdir build
cd build

%CMAKE_PATH%\bin\cmake.exe ^
-G "%GENERATOR%" ^
-DCMAKE_MAKE_PROGRAM="%NINJA_PATH%\ninja.exe" ^
-DCMAKE_TOOLCHAIN_FILE="%ANDROID_NDK_PATH%\build\cmake\android.toolchain.cmake" ^
-DCMAKE_CXX_STANDARD=17 ^
-DCMAKE_CXX_STANDARD_REQUIRED=ON ^
-DANDROID_PLATFORM=%ANDROID_MIN_SDK% ^
-DANDROID_ABI=armeabi-v7a ^
-DCMAKE_BUILD_TYPE=RELEASE ^
..

if errorlevel 1 (
	echo CMake generation failed
	PAUSE
)

%NINJA_PATH%\ninja.exe

if errorlevel 1 (
	echo Ninja compilation failed
	PAUSE
)

:: ========== FUNCTIONS ==========
EXIT /B

:NORMALIZEPATH
  SET RETVAL=%~dpfn1
  EXIT /B