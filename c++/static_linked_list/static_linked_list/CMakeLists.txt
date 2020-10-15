cmake_minimum_required(VERSION 3.10)
project(static_linked_list)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(static_linked_list
        Node.h
        StaicLinkedList.h
        StaticLinkedList.cpp)
