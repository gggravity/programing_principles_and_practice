cmake_minimum_required(VERSION 3.2)
project(programing_principles_and_practice)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        programing_principles_and_practice
        c9/e5/main.cpp
        c9/e5/ISBN.h
        c9/e5/ISBN.cpp
        c9/e5/Book.h
        c9/e5/Book.cpp
        c9/e5/Genre.cpp c9/e5/Genre.h c9/e5/Patron.cpp c9/e5/Patron.h c9/e5/Library.cpp c9/e5/Library.h c9/e5/Date.cpp c9/e5/Date.h c9/e5/Month.cpp c9/e5/Month.h c9/e5/Transaction.cpp c9/e5/Transaction.h)
