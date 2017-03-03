# CMake generated Testfile for 
# Source directory: /Users/rusik/ClionProjects/huyorg/test
# Build directory: /Users/rusik/ClionProjects/huyorg/cmake-build-debug/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(json_test "/Users/rusik/ClionProjects/huyorg/cmake-build-debug/test/json_test")
add_test(confreader_test "/Users/rusik/ClionProjects/huyorg/cmake-build-debug/test/confreader_test")
add_test(storage_test "/Users/rusik/ClionProjects/huyorg/cmake-build-debug/test/storage_test")
add_test(tcp_test "/Users/rusik/ClionProjects/huyorg/cmake-build-debug/test/tcp_test")
add_test(http_test "/Users/rusik/ClionProjects/huyorg/cmake-build-debug/test/http_test")
add_test(docker_test "/Users/rusik/ClionProjects/huyorg/cmake-build-debug/test/docker_test")
subdirs(libgtest)
