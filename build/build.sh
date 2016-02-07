#!/usr/bin/env bash
for i in $(ls | grep -v build.sh); do
	rm -Rf ./$i
done
export CXX="/usr/bin/clang++" 
cmake .. -DCMAKE_BUILD_TYPE=Debug
make -j 4
