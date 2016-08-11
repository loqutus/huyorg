#!/usr/bin/env bash
set -e
set -x
cd ..
#./format.sh
cd build
./build.sh > /dev/null
killall -9 master || true
killall -9 client || true
./master/master &
sleep 1
./client/client --json ../test/add_slave.json
sleep 1
cat master.log
killall -9 master || true
killall -9 client || true
