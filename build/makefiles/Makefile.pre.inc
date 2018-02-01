SRC=${TOP}/src
OBJ=${TOP}/obj
_INC=${TOP}/include
INC=$(_INC)
TLS=${TOP}/tools

AR=ar
RANLIB=ranlib
_CC=clang
_CXX=clang++
LD=$(_CXX)
CC=ccache $(_CC)
CXX=ccache $(_CXX)
FORMAT=clang-format
SCAN=scan-build
 
CXXFLAGS=-std=c++17
LLVM_CONFIG=llvm-config
LLVM_CXXFLAGS := $(shell $(LLVM_CONFIG) --cxxflags | sed -e 's/-fno-rtti/-frtti/' | sed -e 's/-O3//' | sed -e 's/-fno-exceptions//' )
LLVM_INC := $(shell $(LLVM_CONFIG) --includedir )
LLVM_LDFLAGS := $(shell $(LLVM_CONFIG) --ldflags)
LLVM_LIBS := $(shell $(LLVM_CONFIG) --system-libs --libs)

LLVM_CXXFLAGS += -Wno-unused-command-line-argument

DEBUG_FLAGS=-fno-limit-debug-info -O0 -g
MEMSAN_FLAGS=-fsanitize=memory -fsanitize-memory-track-origins=2
UBSAN_FLAGS=-fsanitize=undefined