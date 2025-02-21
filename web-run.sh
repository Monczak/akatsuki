#!/bin/bash
ROOT=$(pwd)

EMSDK_QUIET=1 source "$ROOT/external/emsdk/emsdk_env.sh"
cd build/web-debug || (echo "No web-debug build found" && exit 1)
emrun akatsuki.html