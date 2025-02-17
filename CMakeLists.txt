cmake_minimum_required(VERSION 3.12)
project(libpacreader VERSION 0.0.13)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

FILE(GLOB SOURCES src/*.c) # Ohhh, so that's why I couldn't get any functions outside of debug.c

add_executable(libpacreader ${SOURCES})

target_include_directories(libpacreader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
