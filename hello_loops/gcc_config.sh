#!/bin/bash

rm -rf CMakeFiles *Cache.txt *.cmake
COMPILER_PATH='/usr/local/bin'

cmake \
    -DCMAKE_CXX_COMPILER:STRING='g++' \
    -DCMAKE_C_COMPILER:STRING='gcc' \
    -DCMAKE_CXX_FLAGS:STRING='-Wall -fPIC -pipe -std=c++11 -fopenmp' \
    -DCMAKE_C_FLAGS:STRING='-fPIC -pipe -Wall -fopenmp' \

make -j8
