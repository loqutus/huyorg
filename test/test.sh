#!/usr/bin/env bash
cd build
./build.sh || exit
cd ../test
../build/master/master
