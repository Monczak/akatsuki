#!/bin/bash
ROOT=$(pwd)

EMSDK_QUIET=1 source "$ROOT/external/emsdk/emsdk_env.sh"
cd build/web-debug
emrun akatsuki.html