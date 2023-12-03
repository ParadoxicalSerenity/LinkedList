cmake_minimum_required(VERSION 3.16.3)
project(LinkedList)

set(CMAKE_CXX_STANDARD 20)

add_executable(
    LinkedList 
    source/main.cpp 
    source/LinkedList.cpp 
    source/LinkedList.h
    )
