cmake_minimum_required(VERSION 3.2)

project(
        poker-hand-evaluator 
        VERSION 0.1
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(poker-hand-evaluator src/main.cpp)
