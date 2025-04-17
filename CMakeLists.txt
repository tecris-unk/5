cmake_minimum_required(VERSION 3.29)
project(5 C)

set(CMAKE_C_STANDARD 23)

add_executable(5 main.c
        functions.h
        stack.h
        functions.c
        tasks.c
        mystring.c
        mystring.h)
