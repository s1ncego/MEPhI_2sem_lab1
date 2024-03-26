cmake_minimum_required(VERSION 3.26)
project(lab1Buntsev C)

set(CMAKE_C_STANDARD 11)

add_executable(lab1Buntsev main.c
        Menu.h
        array.h
        array.c
        tests.c
        tests.h
        fieldinfo.c
        fieldinfo.h
        number.c
        number.h
        float.c
        float.h
        func.c
        func.h
)
