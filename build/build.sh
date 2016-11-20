#!/usr/bin/env bash
dir=${PWD##*/}
build_dir="build"
if [ "$dir" != "$build_dir" ]; then
  exit 1
fi
#for i in $(ls | grep -v build.sh); do
#	rm -Rf ./$i
#done
export CXX="clang++" 
export CC="clang" 
cmake DCMAKE_BUILD_TYPE=Debug ..
#cmake DCMAKE_BUILD_TYPE=Release ..
#make -j 4
make -j 8
make -j 8 test
exit $?
