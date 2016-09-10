#!/usr/bin/env bash
set -e
set -x
ulimit -c unlimited
cd ..
#./format.sh
cd build
rm -f master.log
./build.sh > /dev/null
killall -9 master || true
killall -9 slave || true
killall -9 client || true
./master/master &
sleep 1
./slave/slave &
sleep 1
sudo netstat -tulpn | egrep -e '9999|8888'
./client/client --json ../test/add_slave.json
sleep 1
./client/client --json ../test/add_pod.json
sleep 1
cat master.log
cat slave.log
sudo docker ps -a
killall -9 master || true
killall -9 client || true
