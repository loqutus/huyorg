project(test CXX)
#add_subdirectory(/usr/local/src/googletest/googletest/ ${CMAKE_CURRENT_BINARY_DIR}/libgtest )
#add_subdirectory(/usr/src/gtest ${CMAKE_CURRENT_BINARY_DIR}/libgtest )
add_subdirectory(/Users/rusik/Downloads/googletest/googletest ${CMAKE_CURRENT_BINARY_DIR}/libgtest )
add_executable(json_test json_test.cpp)
add_executable(confreader_test confreader_test.cpp)
add_executable(storage_test storage_test.cpp)
add_executable(tcp_test tcp_test.cpp)
add_executable(http_test http_test.cpp)
add_executable(container_test container_test.cpp)
target_link_libraries(json_test gtest gtest_main json)
target_link_libraries(confreader_test gtest gtest_main confreader)
target_link_libraries(storage_test gtest gtest_main confreader storage)
target_link_libraries(tcp_test gtest gtest_main tcpserver tcpclient json ${Boost_LIBRARIES})
target_link_libraries(http_test httpclient gtest gtest_main curlpp curl json ${Boost_LIBRARIES})
target_link_libraries(container_test container httpclient tcpclient json gtest gtest_main curlpp curl ${Boost_LIBRARIES})
add_test(NAME json_test COMMAND json_test)
add_test(NAME confreader_test COMMAND confreader_test)
add_test(NAME storage_test COMMAND storage_test)
add_test(NAME tcp_test COMMAND tcp_test)
add_test(NAME http_test COMMAND http_test)
add_test(NAME container_test COMMAND container_test)
