AR            := ar
CXX           := clang++
LD            := $(CXX)
LLD           := ld.lld
LEX           := $(TOP)/tools/install/bin/flex
LYPP          := $(TOP)/tools/install/bin/lypp
RANLIB        := ranlib
YACC          := $(TOP)/tools/install/bin/bison
TOOL_INCLUDES := -I $(TOP)/tools/install/include
TOOL_LIBS     := -L $(TOP)/tools/install/lib

WARN_FLAGS=-Werror -Wpedantic
DEBUG_FLAGS=-fno-limit-debug-info -O0 -g
MEMSAN_FLAGS=-fsanitize=memory -fsanitize-memory-track-origins=2
UBSAN_FLAGS=-fsanitize=undefined

CXXFLAGS=-fPIC -std=c++17 $(WARN_FLAGS) $(DEBUG_FLAGS)
YACC_FLAGS=
LYPP_FLAGS=

LLVM_CONFIG=llvm-config
LLVM_INCLUDEDIR  := $(shell $(LLVM_CONFIG) --includedir)
LLVM_LIBDIR      := $(shell $(LLVM_CONFIG) --libdir)
LLVM_LIBS        := $(shell $(LLVM_CONFIG) --libs)
LLVM_SYSTEM_LIBS := $(shell $(LLVM_CONFIG) --system-libs)

