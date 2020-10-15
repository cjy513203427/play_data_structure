cmake_minimum_required(VERSION 3.10)
project(sequence_list)

set(CMAKE_CXX_STANDARD 11)

include_directories(sequence_list)

add_executable(sequence_list
        sequence_list/sequence_list.cpp
        sequence_list/sequence_list.h)
