cmake_minimum_required(VERSION 3.20)
project(akatsuki)

# ---------- CMake Options -----------
option(ENABLE_TESTS "Enable tests" ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# ---------- Native Setup -----------
if(NOT EMSCRIPTEN)
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
endif()

# ---------- Emscripten Setup -----------
if(EMSCRIPTEN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -sUSE_SDL=2")
endif()

# ---------- Library Dirs -----------
set(GOOGLETEST_DIR "${CMAKE_SOURCE_DIR}/external/googletest")
set(SPDLOG_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external/spdlog/include")

include_directories(${SPDLOG_INCLUDE_DIR})

# ---------- Test Setup -----------
if(ENABLE_TESTS)
    add_subdirectory(${GOOGLETEST_DIR})
    include_directories(${GOOGLETEST_DIR}/include ${GOOGLETEST_DIR})

    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/test)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/test/suites)
    add_executable(${PROJECT_NAME}-test test/test_driver.cpp)
    target_link_libraries(${PROJECT_NAME}-test gtest gtest_main)
endif()

# ---------- Target Setup -----------
add_executable(${PROJECT_NAME} src/main.cpp)

# ---------- Native Target Config -----------
if(NOT EMSCRIPTEN)
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
endif()

# ---------- Emscripten Target Config -----------
if(EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-sWASM=1 --emrun")
endif()