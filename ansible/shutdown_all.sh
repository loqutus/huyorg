#!/usr/bin/env bash
for i in $(seq 1 4); do
  ssh root@pi$i shutdown -h now
done
shutdown -h now
