cmake_minimum_required(VERSION 3.2)
project(programing_principles_and_practice)

set(CMAKE_CXX_STANDARD 23)

find_package(FLTK REQUIRED)

add_executable(programing_principles_and_practice
        std_lib.h
        c12/Graph.h
        c12/Graph.cpp
        c12/Gui.h
        c12/GUI.cpp
        c12/Point.h
        c12/Simple_window.h
        c12/Window.h
        c12/Window.cpp

        c13/e3.cpp
        c13/Arrow.cpp c13/Arrow.h)

target_link_libraries(programing_principles_and_practice fltk -lfltk_images)