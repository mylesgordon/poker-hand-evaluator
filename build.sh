#!/bin/bash

clean () {
        rm -r build
}

cmake () {
        CXX=/usr/bin/clang++ bash -c 'cmake -Bbuild'
}

build () {
        cmake
        cd build
        make
        cd ..
}

parse_arg() {
        if [ "$1" = "build" ] ; then
                build
        elif [ "$1" = "clean" ] ; then
                clean
        elif [ "$1" = "cmake" ] ; then
                cmake
        elif [ "$1" = "run" ] ; then
                ./build/poker-hand-evaluator
        fi
}

for var in "$@"
do
        parse_arg "$var"
done
