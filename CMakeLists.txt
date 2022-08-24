cmake_minimum_required(VERSION 3.2)

project(
        poker-hand-evaluator
        VERSION 0.1
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig)
pkg_check_modules(FMT REQUIRED fmt)

add_executable(poker-hand-evaluator src/card.h src/deck.h src/hand.h src/main.cpp)

target_link_libraries(poker-hand-evaluator ${FMT_LIBRARIES})
target_include_directories(poker-hand-evaluator PUBLIC ${FMT_INCLUDE_DIRS})
