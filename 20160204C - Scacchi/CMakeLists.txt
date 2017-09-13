cmake_minimum_required(VERSION 3.7)
project(20160204C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

set(SOURCE_FILES main.c)
set(NOFUNCT_FILES nofunct.c)
add_executable(20160204C ${SOURCE_FILES})
add_executable(nofunct ${NOFUNCT_FILES})
