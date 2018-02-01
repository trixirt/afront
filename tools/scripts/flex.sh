#!/bin/sh
set -x

cd ..
P=$PWD/install

cd src
V=2.6.4
S=flex-${V}
tar xf ../pkgs/${S}.tar.gz
cd ${S}
mkdir build
cd build
../configure --prefix=$P
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
