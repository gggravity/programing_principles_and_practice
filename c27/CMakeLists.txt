cmake_minimum_required(VERSION 3.23)
project(app)

set(CMAKE_C_STANDARD 23)

add_executable(drills drills.c)
add_executable(e1 e1.c)
add_executable(e2 e2.c LL.c)
