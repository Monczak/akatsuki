#!/bin/bash

PLATFORM=${1:-native}
MODE=${2:-debug}
ROOT=$(pwd)

if [ "$PLATFORM" = "web" ]; then
    PRESET="web-$MODE"
else
    PRESET="native-$MODE"
fi

mkdir -p "build/$PRESET"
cd "build/$PRESET"

if [ "$PLATFORM" = "web" ]; then
    EMSDK_QUIET=1 source "$ROOT/external/emsdk/emsdk_env.sh"
    emcmake cmake $ROOT
    emmake make
else
    cmake --preset="$PRESET" $ROOT
    cmake --build .
fi
