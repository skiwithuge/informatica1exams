cmake_minimum_required(VERSION 3.7)
project(20160616B)

set(CMAKE_C_STANDARD 99)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

set(SOURCE_FILES  20160616B.c)
set(SQUILLERO_FILES 2016-06-16-Turno-B1-soluzione.c)
set(NOFUNC_FILES nofunct.c)
add_executable(squillero ${SQUILLERO_FILES})

add_executable(20160616B ${SOURCE_FILES})

add_executable(nofun ${NOFUNC_FILES})