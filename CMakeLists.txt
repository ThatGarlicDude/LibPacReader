cmake_minimum_required(VERSION 3.12) # Cmake must be on version 3.12 or above to proceed.
project(pacreader VERSION 1.1.0) # Start the project.

set(CMAKE_C_STANDARD 99) # C99 is required.
set(CMAKE_C_STANDARD_REQUIRED ON)

FILE(GLOB SOURCES src/*.c) # Get all the files from the src directory.

add_subdirectory(submodules/LibPacSorter)
add_library(pacreader SHARED ${SOURCES}) # Create the library.

target_include_directories(pacreader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers) # Get the files in the header directory as well.

target_link_libraries(pacreader PUBLIC pacsorter)
