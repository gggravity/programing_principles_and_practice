# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.22.1)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(catch2-populate NONE)


# Pass through things we've already detected in the main project to avoid
# paying the cost of redetecting them again in ExternalProject_Add()
set(GIT_EXECUTABLE [==[C:/msys64/usr/bin/git.exe]==])
set(GIT_VERSION_STRING [==[2.34.1]==])
set_property(GLOBAL PROPERTY _CMAKE_FindGit_GIT_EXECUTABLE_VERSION
        [==[C:/msys64/usr/bin/git.exe;2.34.1]==]
        )


include(ExternalProject)
ExternalProject_Add(catch2-populate
        "UPDATE_DISCONNECTED" "False" "GIT_SHALLOW" "TRUE" "GIT_REPOSITORY" "https://github.com/catchorg/Catch2.git" "GIT_TAG" "v3.0.0-preview3"
        SOURCE_DIR "C:/Users/martin.LAPLAND/CLionProjects/programing-principles-and-practice/c14/e8/build/_deps/catch2-src"
        BINARY_DIR "C:/Users/martin.LAPLAND/CLionProjects/programing-principles-and-practice/c14/e8/build/_deps/catch2-build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        TEST_COMMAND ""
        USES_TERMINAL_DOWNLOAD YES
        USES_TERMINAL_UPDATE YES
        )


