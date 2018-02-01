#!/bin/sh

HERE=`realpath $(dirname $0)`
cd $HERE
P=$HERE/../install

cd ../pkgs
V=1.8.0
if [ -d googletest-release-${V} ]; then
    rm -rf googletest-release-${V}
fi
if [ ! -d googletest-release-${V} ]; then
    tar xf googletest-release-${V}.tar.gz 
fi

cd googletest-release-${V}
SUBDIRS="googletest googlemock"
for subdir in $SUBDIRS; do
    if [ -d $subdir ]; then
	cd $subdir
    fi
    if [ ! -f configure ]; then
	autoreconf -f -i
	automake -a
    fi
    if [ ! -f configure ]; then
	echo "autoreconf failed"
	exit 1
    fi
    
    ./configure --prefix=$P
     # Make sure we are really using our compilers
     #make CXXFLAGS=-v CFLAGS=-v
     if [ -f Makefile ]; then
	 make -j
	 if [ $? = 0 ]; then
	     make check
	     echo "Make $subdir checked"
	 else
	     echo "Make $subdir failed"
	     exit 1
	 fi
     else
	 echo "Configure $subdir failed"
	 exit 1
     fi
done
