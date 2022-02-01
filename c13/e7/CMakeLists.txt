cmake_minimum_required(VERSION 3.2)
project(programing_principles_and_practice)

set(CMAKE_CXX_STANDARD 23)

find_package(FLTK REQUIRED)

add_executable(programing_principles_and_practice
        #        ../GUI/std_lib.h
        #        ../GUI/Graph.h
        ../GUI/Graph.cpp
        #        ../GUI/Gui.h
        ../GUI/GUI.cpp
        #        ../GUI/Simple_window.h
        #        ../GUI/Window.h
        ../GUI/Window.cpp
        main.cpp
        )

target_link_libraries(programing_principles_and_practice fltk -lfltk_images)