cmake_minimum_required(VERSION 3.2)
project(programing_principles_and_practice)

set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/GUI)
link_directories(${CMAKE_SOURCE_DIR}/GUI)

add_subdirectory("${PROJECT_SOURCE_DIR}/c14/e11" "${PROJECT_SOURCE_DIR}/c14/e11")


#find_package(FLTK REQUIRED)
#
#add_executable(programing_principles_and_practice
#        std_lib.h
#        c12/Graph.h
#        c12/Graph.cpp
#        c12/Gui.h
#        c12/GUI.cpp
#        c12/Point.h
#        c12/Simple_window.h
#        c12/Window.h
#        c12/Window.cpp
#        c13/Arrow.cpp
#        c13/Arrow.h
#        c13/Box.h
#        c13/Box.cpp
#        c13/e6.cpp c13/Textbox.cpp c13/Textbox.h)
#
#target_link_libraries(programing_principles_and_practice fltk -lfltk_images)