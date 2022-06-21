cmake_minimum_required(VERSION 3.22)
project(programing_principles_and_practice CXX)
set(CMAKE_CXX_STANDARD 23)
find_package(FLTK REQUIRED)
#Include(FetchContent)
#FetchContent_Declare(
#        Catch2
#        GIT_SHALLOW TRUE
#        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#        GIT_TAG v3.0.0-preview3
#)
#list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
#FetchContent_MakeAvailable(Catch2)

#file(GLOB SOURCES
#        header-folder/*.h
#        source-folder/*.cpp
#        )

set(COMMON_SOURCES ../../GUI/Graph.h
        ../../GUI/Graph.cpp
        ../../GUI/Gui.h
        ../../GUI/GUI.cpp
        ../../GUI/Simple_window.h
        ../../GUI/Window.h
        ../../GUI/Window.cpp
        ../../GUI/Point.h
        Pseudo_window.h
        Pseudo_window.cpp
        )

#enable_testing()

set(TARGET_SOURCES main.cpp)
set(TEST_SOURCES tests/test.cpp)
add_executable(application ${COMMON_SOURCES} ${TARGET_SOURCES})
#add_executable(tests ${COMMON_SOURCES} ${TEST_SOURCES})

set(LIBS fltk -lfltk_images)

target_link_libraries(application ${LIBS})
#target_link_libraries(tests PRIVATE Catch2::Catch2WithMain ${LIBS})


#list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
#include(CTest)
#include(Catch)
#catch_discover_tests(tests)