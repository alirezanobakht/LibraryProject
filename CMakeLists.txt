cmake_minimum_required(VERSION 3.12)
project(library)

set(CMAKE_CXX_STANDARD 14)

add_executable(library main.cpp Classes/libraries.cpp Classes/libraries.h Classes/books.cpp Classes/books.h)