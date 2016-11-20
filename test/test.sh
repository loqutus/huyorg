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
sleep 1
#sudo netstat -tulpn | egrep -e '9999|8888'
sudo lsof -iTCP -sTCP:LISTEN -n -P | egrep -e '9999|8888'
./client/client --json ../test/add_slave.json
sleep 1
./client/client --json ../test/add_pod.json
echo "sleep 10"
sleep 10
cat master.log
cat slave.log
date
curl http://\[::1\]:3375/containers/json
killall -9 master 2>&1 > /dev/null || true 2>&1 > /dev/null
killall -9 slave 2>&1 > /dev/null || true 2>&1 > /dev/null
killall -9 client 2>&1 > /dev/null || true 2>&1 > /dev/null
sudo docker ps -a | grep -v 'CONTAINER' |  head -n 2 | grep -v docker-proxy
for i in $(docker ps -a | grep -v docker-proxy | grep -v CONTAINER | awk '{print $1}'); do
  docker stop $i;
  docker rm $i;
done
