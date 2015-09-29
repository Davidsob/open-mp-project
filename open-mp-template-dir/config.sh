#!/bin/bash

rm -rf CMakeFiles *Cache.txt *.cmake


cmake \
    -DCMAKE_CXX_FLAGS:STRING='-Wall -fPIC -pipe -std=c++11 -stdlib=libc++ -fopenmp' \
    -DCMAKE_C_FLAGS:STRING='-fPIC -pipe -Wall -fopenmp' \

make -j8
