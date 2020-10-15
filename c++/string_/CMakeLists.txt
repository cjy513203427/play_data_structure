cmake_minimum_required(VERSION 3.10)
project(string_)

set(CMAKE_CXX_STANDARD 11)

include_directories(string_)

add_executable(string_
        string_/string_.cpp
        string_/string_.h)
