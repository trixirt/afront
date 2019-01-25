#!/bin/sh
set -x

cd ..
P=$PWD/install

cd src
V=2.6.4
S=flex-${V}
tar xf ../pkgs/${S}.tar.gz
cd ${S}
if [ -d build ]; then
    rm -rf build
fi
mkdir build
cd build

# Problems building 2.6.4 will gcc 7.2
# https://github.com/spack/spack/issues/6812
# Is causing a build failure on Ubuntu 18.04
# So switch to building with clang.
CC=clang ../configure --prefix=$P
if [ ! -f Makefile ]; then
    exit 1
fi
make
if [ ! -x src/flex ]; then
    exit 1
fi
make install
if [ ! -x $P/bin/flex ]; then
    exit 1
fi
make check
