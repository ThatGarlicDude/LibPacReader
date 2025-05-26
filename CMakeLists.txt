cmake_minimum_required(VERSION 3.18)
project(pacreader VERSION 1.2.0)

# Set up specifications for the C compiler.
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# Set output directories.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include its submodule.
add_subdirectory(submodules/LibPacSorter)

# Gather the files.
FILE(GLOB SOURCES src/*.c)

# Output the project.
add_library(pacreader SHARED ${SOURCES}) # Create the library.
target_include_directories(pacreader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)
target_link_libraries(pacreader PUBLIC pacsorter pacset)
install(TARGETS pacreader DESTINATION lib)
