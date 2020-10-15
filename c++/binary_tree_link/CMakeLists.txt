cmake_minimum_required(VERSION 3.10)
project(binary_tree_link)

set(CMAKE_CXX_STANDARD 11)

include_directories(binary_tree_link)

add_executable(binary_tree_link
        binary_tree_link/BinaryTreeLink.cpp
        binary_tree_link/BinaryTreeLink.h
        binary_tree_link/Node.h)
