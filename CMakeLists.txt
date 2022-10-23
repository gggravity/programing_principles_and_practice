cmake_minimum_required(VERSION 3.11)
project(programing_principles_and_practice)

set(CMAKE_CXX_STANDARD 23)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost COMPONENTS regex date_time system filesystem thread graph program_options)
find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-4.0)
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(drill_c25 c25/drill.cpp)
add_executable(c25_e1 c25/e1.cpp)
add_executable(c25_e3 c25/e3.cpp)
add_executable(c25_e7 c25/e7.cpp)

add_executable(drill_c24 c24/drill.cpp c24/Matrix.h)
add_executable(c24_e1 c24/e1.cpp)
add_executable(c24_e2 c24/e2.cpp)
add_executable(c24_e4 c24/e4.cpp)
add_executable(c24_e5 c24/e5.cpp)

add_executable(drill_c23 c23/drill.cpp)
add_executable(c23_e1 c23/e1.cpp)
add_executable(c23_e2 c23/e2.cpp)
add_executable(c23_e3 c23/e3.cpp)
add_executable(c23_e6 c23/e6.cpp)
add_executable(c23_e7 c23/e7.cpp)
add_executable(c23_e9 c23/e9.cpp)
add_executable(c23_e10 c23/e10.cpp)
add_executable(c23_e11 c23/e11.cpp)

add_executable(drill_c21 c21/drill.cpp)
add_executable(c21_e1 c21/e1.cpp)
add_executable(c21_e3 c21/e3.cpp)
add_executable(c21_e4 c21/e4.cpp)
add_executable(c21_e5 c21/e5.cpp)
add_executable(c21_e6 c21/e6.cpp)
add_executable(c21_e7 c21/e7.cpp)
add_executable(c21_e8 c21/e8.cpp)
add_executable(c21_e9 c21/e9.cpp)
add_executable(c21_e10 c21/e10.cpp)
add_executable(c21_e11 c21/e11.cpp)
add_executable(c21_e12 c21/e12.cpp)

add_executable(drill_c20 c20/drill.cpp)
add_executable(e1_c20 c20/e1.cpp)
add_executable(e2_c20 c20/e2.cpp)
add_executable(e3_c20 c20/e3.cpp)
add_executable(e4_c20 c20/e4.cpp)
add_executable(e5_c20 c20/e5.cpp)
add_executable(e6_c20 c20/e6.cpp)
add_executable(e7_c20 c20/e7.cpp)
add_executable(e8_c20 c20/e8.cpp)
add_executable(e9_c20 c20/e9.cpp)
add_executable(e10_c20 c20/e10.cpp)
add_executable(e11_c20 c20/e11.cpp)
add_executable(e12_c20 c20/e12.cpp c20/List.hpp)

add_executable(drill c19/drill.cpp c19/e3.cpp)
add_executable(e1 c19/e1.cpp)
add_executable(e2 c19/e2.cpp)
add_executable(e3 c19/e3.cpp)
add_executable(e4 c19/e4.cpp c19/Link.hpp)
add_executable(e5 c19/e5.cpp)
add_executable(e6 c19/e6.cpp)
add_executable(e7 c19/e7.cpp)
add_executable(e8 c19/e8.cpp c19/Vector.hpp)
add_executable(e9 c19/e9.cpp c19/Vector.hpp)
add_executable(e10 c19/e10.cpp c19/Unique_ptr.hpp)
add_executable(e11 c19/e11.cpp c19/Counted_ptr.hpp)
add_executable(e12 c19/e12.cpp c19/File_handle.hpp)
add_executable(e13 c19/e13.cpp c19/Tracer.hpp)




target_link_libraries(c21_e11 ${GTKMM_LIBRARIES})
target_link_libraries(c21_e12 ${GTKMM_LIBRARIES})

#include_directories(${CMAKE_SOURCE_DIR}/GUI)
#link_directories(${CMAKE_SOURCE_DIR}/GUI)
#
#add_subdirectory("${PROJECT_SOURCE_DIR}/c14/e11" "${PROJECT_SOURCE_DIR}/c14/e11")


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