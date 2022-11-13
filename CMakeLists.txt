cmake_minimum_required(VERSION 3.23)
project(DataStructure_ex2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DataStructure_ex2
        HashTable.cpp
        HashTable.h
        HSubject.cpp
        HSubject.h
        main.cpp
        Item.h)
