#!/usr/bin/env bash
dir=${PWD##*/}
build_dir="build"
if [ "$dir" != "$build_dir" ]; then
  exit 1
fi
for i in $(ls | grep -v build.sh); do
	rm -Rf ./$i
done
export CXX="/usr/bin/clang++" 
#export CXX="/usr/bin/c++" 
export CC="/usr/bin/clang" 
#export CC="/usr/bin/cc" 
cmake -DCMAKE_VERBOSE_MAKEFILE=ON -DCMAKE_BUILD_TYPE=Debug ..
#cmake DCMAKE_BUILD_TYPE=Debug ..
make -j 4 V=1
#make -j 4
exit $?
