#!/bin/sh

set -x

CXXFLAGS="-std=c++17 -frtti -fno-limit-debug-info -O0 -g "
INCLUDE="-I ../../../src -I ../../../src/fig -I ../../../src/pt"

clang++ $CXXFLAGS $INCLUDE figc1.cpp -L ../../../obj/fig -lfigpt -o figc1
