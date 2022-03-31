cmake_minimum_required(VERSION 3.5)

project(techchallenge LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(techchallenge main.cpp)

add_executable(techchallenge_test test.cpp)