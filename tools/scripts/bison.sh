#!/bin/sh
set -x

cd ..
P=$PWD/install

cd src
V=3.8.2
S=bison-${V}
U=https://ftp.gnu.org/gnu/bison/
if [ ! -f ../pkgs/${S}.tar.gz ]; then
    cd ../pkgs
    wget ${U}/${S}.tar.gz
    cd -
fi
tar xf ../pkgs/${S}.tar.gz
cd ${S}
if [ -d build ]; then
    rm -rf build
fi
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
