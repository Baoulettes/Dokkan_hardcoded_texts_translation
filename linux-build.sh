#!/usr/bin/env bash

GENERATOR=Ninja
NINJA_VERSION=1.9.0
ANDROID_NDK_REV=r20
DOKKAN_SDK_REV=r1
ANDROID_MIN_SDK=21
pushd . > /dev/null
cd "../../"
UD_SDK_ROOT=$(pwd)
popd > /dev/null

echo UD_SDK_ROOT: $UD_SDK_ROOT

source <(grep AndroidNDK "$UD_SDK_ROOT/deps/dependencies-linux.ini")
source <(grep Ninja "$UD_SDK_ROOT/deps/dependencies-linux.ini")
source <(grep CMake "$UD_SDK_ROOT/deps/dependencies-linux.ini")

ANDROID_NDK_PATH=$AndroidNDK
NINJA_PATH=$Ninja
CMAKE_PATH=$CMake

echo ANDROID_NDK_PATH:
echo $ANDROID_NDK_PATH
echo NINJA_PATH:
echo $NINJA_PATH
echo CMAKE_PATH:
echo $CMAKE_PATH
echo -

mkdir -p build
cd build

$CMAKE_PATH/bin/cmake \
-G "$GENERATOR" \
-DCMAKE_MAKE_PROGRAM="$NINJA_PATH/ninja" \
-DCMAKE_TOOLCHAIN_FILE="$ANDROID_NDK_PATH/build/cmake/android.toolchain.cmake" \
-DCMAKE_CXX_STANDARD=17 \
-DCMAKE_CXX_STANDARD_REQUIRED=ON \
-DANDROID_PLATFORM=$ANDROID_MIN_SDK \
-DANDROID_ABI=armeabi-v7a \
-DCMAKE_BUILD_TYPE=RELEASE \
..

if [ $? -eq 0 ]
then
    $NINJA_PATH/ninja
else
    echo CMake generation failed, exiting
fi