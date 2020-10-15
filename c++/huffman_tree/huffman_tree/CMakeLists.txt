cmake_minimum_required(VERSION 3.10)
project(huffman_tree)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(huffman_tree
        HuffmanTree.cpp
        HuffmanTree.h
        Node.h)
