cmake_minimum_required(VERSION 3.7)
project(20170217A)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
set(V2 v2.c)
add_executable(20170217A ${SOURCE_FILES})
add_executable(V2 ${V2})