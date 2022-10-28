cmake_minimum_required(VERSION 3.23)
project(app C CXX)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)

add_executable(drills drills.c)
add_executable(e1 e1.c)
add_executable(e2 e2.c LL.c)
add_executable(e3 e3.c LL2.c)
add_executable(e4 e4.cpp Linked_list.hpp)
