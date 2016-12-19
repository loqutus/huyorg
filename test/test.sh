#!/usr/bin/env bash
set -e
#set -x
ulimit -c unlimited
cd ../build
rm -f master.log
killall -9 master 2>&1 > /dev/null || true 2>&1 > /dev/null
killall -9 slave 2>&1 > /dev/null || true 2>&1 > /dev/null
killall -9 client 2>&1 > /dev/null || true 2>&1 > /dev/null
./build.sh
./master/master &
sleep 1
./slave/slave &
ps aux | grep master | grep -v grep | awk '{print $2}'
ps aux | grep slave | grep -v grep | awk '{print $2}'
sleep 10
#sudo netstat -tulpn | egrep -e '9999|8888'
./client/client --json ../test/add_slave.json
sleep 1
./client/client --json ../test/add_pod.json
echo "sleep 30"
sleep 30
cat master.log
cat slave.log
date
curl http://\[::1\]:7777/containers/json
killall -9 master 2>&1 > /dev/null || true 2>&1 > /dev/null
killall -9 slave 2>&1 > /dev/null || true 2>&1 > /dev/null
killall -9 client 2>&1 > /dev/null || true 2>&1 > /dev/null
docker -H 127.0.0.1:7777 ps
for i in $(docker -H 127.0.0.1:7777 ps -a | grep -v CONTAINER | awk '{print $1}'); do
  docker -H 127.0.0.1:7777  stop $i;
  docker -H 127.0.0.1:7777 rm $i;
done
