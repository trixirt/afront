#!/bin/sh


clang++ -g -O0 -std=c++17 -frtti -I ../../../src/c -I ../../../src/pt -I ../../../src -I ../../../src/pt/c/v -L ../../../obj/c -L ../../../obj test-001.cpp ../../../obj/m.o -lpt -lcpt -lpt -lcvtypedefs
