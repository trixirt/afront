#!/bin/sh

set -x

LLVM_VER=5.0
TAG=current
if [ -d /volume/hab ]; then
    OS=`uname -s`
    HM=`uname -m`
    HABTOOLS_PREFIX=/volume/hab
    R=`${HABTOOLS_PREFIX}/${OS}/bin/os-id`
    HABTOOLS=${HABTOOLS_PREFIX}/${OS}/${R}/${HM}
else
    echo "Expecting hab.."
    exit 1
fi
export PATH=$HABTOOLS/llvm/${LLVM_VER}/${TAG}/bin:$PATH
CC=clang
CXX=clang++
FORMAT=clang-format
	
cd ../../../..
TOP=$PWD
SRC=$PWD/src
OBJ=$TOP/obj
TOOLS=$TOP/tools/install
LEX=$TOOLS/bin/flex
YACC=$TOOLS/bin/bison
LYPP=$TOOLS/bin/lypp
CXXFLAGS="-std=c++17 -I${SRC} -I${TOOLS}/include -I${OBJ} -g -O0 -fno-limit-debug-info"
CINCLUDES="-I${SRC}/c -I${SRC}/c/pt -I${SRC}/c/l -I${OBJ}/c"
cd -

$LYPP -D debug.all -I ${SRC}/c/y c.test.yy > c.parser.yy
if [ $? != 0 ]; then
    echo "Problem in lypp"
    exit 1
fi
if [ -f c.parser.tab.cc ]; then
    rm c.parser.tab.cc
fi
$YACC -d -v c.parser.yy
if [ ! -f c.parser.tab.cc ]; then
    echo "Problem with yacc"
    exit 1
fi
$CXX $CXXFLAGS $CINCLUDES -c c.parser.tab.cc -o c.parser.o
if [ ! -f c.parser.o ]; then
    echo "Problem building parser"
    exit 1
fi

OBJS="$OBJ/c/cc1.o $OBJ/c/driver.o $OBJ/c/c.lexer.o "
$CXX $OBJS c.parser.o $OBJ/c/libcpt.a -o cc1


