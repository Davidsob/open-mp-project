#!/bin/bash

rm -rf CMakeFiles *Cache.txt *.cmake
COMPILER_PATH='/usr/local/bin'

cmake \
    -DCMAKE_CXX_COMPILER:STRING=$COMPILER_PATH/clang-omp++ \
    -DCMAKE_C_COMPILER:STRING=$COMPILER_PATH/clang-omp \
    -DCMAKE_CXX_FLAGS:STRING='-Wall -fPIC -pipe -std=c++11 -stdlib=libc++ -fopenmp' \
    -DCMAKE_C_FLAGS:STRING='-fPIC -pipe -Wall -fopenmp' \

make -j8
