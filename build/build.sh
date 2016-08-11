#!/usr/bin/env bash
dir=${PWD##*/}
build_dir="build"
if [ "$dir" != "$build_dir" ]; then
  exit 1
fi
for i in $(ls | grep -v build.sh); do
	rm -Rf ./$i
done
rm master.log 2>&1 > /dev/null
export CXX="distcc-pump clang++" 
#export CXX="/usr/bin/c++" 
export CC="distcc-pump clang" 
#export CC="/usr/bin/cc" 
#cmake -DCMAKE_VERBOSE_MAKEFILE=ON -DCMAKE_BUILD_TYPE=Debug ..
cmake DCMAKE_BUILD_TYPE=Debug ..
#cmake DCMAKE_BUILD_TYPE=Release ..
#make -j 4 V=1
make -j 20
exit $?
