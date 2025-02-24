# akatsuki

A fantasy console thing

## Build

This repo is built with the `clang` family of compilers and uses Emscripten for web builds.

Clone this repo and initialize submodules:
```shell
git clone --recurse-submodules https://github.com/Monczak/akatsuki
cd akatsuki
```

Initialize the Emscripten SDK:
```shell
cd external/emsdk
./emsdk install latest
./emsdk activate latest
```

### Linux
It's quite possible you have SDL2 set up on your system already. 
If not, refer to [the SDL2 installation guide](https://wiki.libsdl.org/SDL2/Installation#linuxunix) to get SDL2.

To build akatsuki, you can use the included CMake presets:
- `native-debug` - native debug build
- `native-release` - native release build (with `-O3` by default)
- `web-debug` - web debug build with Emscripten
- `web-release` - web release build with Emscripten (with `-O3` by default)

You can also use the `./build.sh` script - additional arguments may be passed to create different builds. By default, the script creates a native debug build.
```shell
./build.sh [native|web] [debug|release]
```

### Windows
You'll need to set up SDL2 yourself. The recommended way to do this is using `vcpkg`:
```shell
vcpkg install sdl2
```
Then you'll be able to use the `native-debug-vcpkg` and `native-release-vcpkg` CMake presets to build akatsuki. 
Emscripten builds should work out of the box since it links SDL2 by default.

**Note:** The `vcpkg` presets require the environment variable `VCPKG_ROOT` to be set. This should be done during `vcpkg` installation, but if the variable is unset, simply set it to the directory where `vcpkg` is installed in your system.

#### Debugging Note
You need to use the MSVC toolchain for debugging to work as MinGW seems to only support `gdb` on Windows. Then you'll be able to use `lldb`.

## Run web builds

### Linux
Use the provided `web-run.sh` script:
```shell
./web-run.sh
```
This will open a new tab in your default browser with akatsuki running. Chrome should work best. Firefox should also work, but YMMV.

### Windows
Make sure EMSDK is activated in your shell:
```shell
./external/emsdk/emsdk_env.ps1 # If using PowerShell - use .bat for cmd
```
Then perform:
```shell
emrun --browser chrome ./build/web-debug/akatsuki.html # For chrome - swap out for other browsers
```
Firefox may have issues with initializing SDL's WebGL context, which would result in a black screen despite logs appearing normally - again, YMMV. Chrome should run well, though.
