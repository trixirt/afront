#!/bin/sh
set -x

cd ..
P=$PWD/install

cd src
S=merr
cd ${S}

if [ -f merr ]; then
    rm merr
fi
icont merr.icn

if [ ! -f merr ]; then
    echo "Failed to build merr"
    exit 1
fi

cp merr $P/bin
