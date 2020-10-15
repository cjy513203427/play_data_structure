cmake_minimum_required(VERSION 3.10)
project(huffman_tree)

set(CMAKE_CXX_STANDARD 11)

include_directories(huffman_tree)

add_executable(huffman_tree
        huffman_tree/HuffmanTree.cpp
        huffman_tree/HuffmanTree.h
        huffman_tree/Node.h
        CMakeLists.txt)
