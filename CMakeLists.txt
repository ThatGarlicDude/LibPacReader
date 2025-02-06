cmake_minimum_required(VERSION 3.12)
project(libpacreader VERSION 0.0.5)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(libpacreader src/debug.c)

target_include_directories(libpacreader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
