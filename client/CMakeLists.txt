project(client CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp main.h)
add_executable(client ${SOURCE_FILES})
