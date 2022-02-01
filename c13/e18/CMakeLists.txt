cmake_minimum_required(VERSION 3.22)
project(programing_principles_and_practice)

set(CMAKE_CXX_STANDARD 23)

find_package(FLTK REQUIRED)

add_executable(programing_principles_and_practice
        ../../GUI/Graph.h
        ../../GUI/Graph.cpp
        ../../GUI/Gui.h
        ../../GUI/GUI.cpp
        ../../GUI/Simple_window.h
        ../../GUI/Window.h
        ../../GUI/Window.cpp
        ../../GUI/Point.h
        main.cpp
        Poly.cpp Poly.h ../../c14/drill/main.cpp)

target_link_libraries(programing_principles_and_practice fltk -lfltk_images)