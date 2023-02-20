cmake_minimum_required(VERSION 3.2)
project(programing_principles_and_practice)

set(CMAKE_CXX_STANDARD 23)

find_package(FLTK REQUIRED)

add_executable(programing_principles_and_practice
        std_lib.h
        Graph.h
        Graph.cpp
        Gui.h
        GUI.cpp
        Point.h
        Simple_window.h
        Window.h
        Window.cpp
        Arrow.cpp
        Arrow.h
#        Box.h
#        Box.cpp
        e6.cpp
        Textbox.cpp
        Textbox.h)

target_link_libraries(programing_principles_and_practice fltk -lfltk_images)