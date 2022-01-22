cmake_minimum_required(VERSION 3.2)
project(programing_principles_and_practice)

set(CMAKE_CXX_STANDARD 17)

add_executable(programing_principles_and_practice
        c7/drill/main.cpp
        c7/drill/Token.h
        c7/drill/Token_stream.cpp
        c7/drill/Token_stream.h
        c7/drill/Calculator.cpp
        c7/drill/Calculator.h
        c7/drill/Variable.h
        c7/drill/Globals.h
        c7/drill/Variable.cpp
        c7/drill/Variable_table.cpp
        c7/drill/Variable_table.h
        c7/drill/Globals.cpp c7/drill/Code.h c7/drill/Key.h c7/drill/Variable_type.cpp c7/drill/Variable_type.h)
