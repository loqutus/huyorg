#!/usr/bin/env bash
set -e
cd ..
#./format.sh
cd build
./build.sh > /dev/null
killall -9 master 2>&1 > /dev/null || true
killall -9 client 2>&1 > /dev/null  || true
./master/master &
sleep 1
./client/client --json ../test/add_slave.json
sleep 1
cat master.log
killall -9 master 2>&1 > /dev/null || true
killall -9 client 2>&1 > /dev/null  || true
