#!/bin/sh
set -x

cd ..
P=$PWD/install

cd src
V=3.0.4
S=bison-${V}
tar xf ../pkgs/${S}.tar.gz
cd ${S}
mkdir build
cd build
../configure --prefix=$P
if [ ! -f Makefile ]; then
    exit 1
fi
make
if [ ! -x src/bison ]; then
    exit 1
fi
make install
if [ ! -x $P/bin/bison ]; then
    exit 1
fi
make check
