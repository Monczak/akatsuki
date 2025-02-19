cmake_minimum_required(VERSION 3.20)
project(akatsuki)

set(CMAKE_CXX_STANDARD 23)

if(EMSCRIPTEN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_SDL=2 -s WASM=1")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
else()
    set(CMAKE_C_COMPILER clang)
    set(CMAKE_CXX_COMPILER clang++)
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
endif()

add_executable(${PROJECT_NAME} src/main.cpp)

if(EMSCRIPTEN)
    # Emscripten automatically links SDL2
else()
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
endif()
