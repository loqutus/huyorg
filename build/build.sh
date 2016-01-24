#!/usr/bin/env bash
for i in $(ls | grep -v build.sh); do
	rm -Rf ./$i
done
cmake .. -DCMAKE_BUILD_TYPE=Debug
make -j 4
