#!/bin/sh

if [ -d ../install ]; then
    rm -rf ../install
fi
./flex.sh
./bison.sh
./googletest.sh
./merr.sh
git clone https://github.com/trixirt/lypp.git
cp ./lypp/lypp.py ../install/bin/lypp
chmod 755 ../install/bin/lypp
