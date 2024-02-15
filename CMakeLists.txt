cmake_minimum_required(VERSION 3.26)
project(lab_14 C)

set(CMAKE_C_STANDARD 11)

add_executable(
        lab_14 main.c
        libs/vector/vector.h
        libs/vector/vector.c
)

add_subdirectory(libs)
target_link_libraries(lab_14 vector)