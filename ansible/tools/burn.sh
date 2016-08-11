#!/usr/bin/env bash
cd ..
ansible -T 3600 -i ./hosts common -m shell -a '/usr/local/bin/burn.sh' &
for j in $(seq 1 200); do
  for i in $(seq 1 5); do 
    echo -n "pi$i: "
    ssh root@pi$i /usr/local/bin/temp.sh
  done
  sleep 1
done
