cmake_minimum_required(VERSION 3.6)
project(untitled)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c heap.h heap.c)
add_executable(untitled ${SOURCE_FILES})