#!/bin/bash

PLATFORM=${1:-native}
ROOT=`pwd`

cd "build-$PLATFORM"

if [ "$PLATFORM" = "web" ]; then
    EMSDK_QUIET=1 source $ROOT/external/emsdk/emsdk_env.sh
    emcmake cmake ..
    emmake make
else
    cmake ..
    make
fi

