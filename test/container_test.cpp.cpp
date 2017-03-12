#include <gtest/gtest.h>
#include <iostream>
#include <list>
#include <string>
//#include <thread>
#include "../lib/container/container.h"

TEST(CONTAINER, CreateContainer) {
    container container_server("127.0.0.1", "7777");
    auto container_id =
        container_server.create_container("sleep", "/bin/sleep 60");
    std::cerr << container_id;
    EXPECT_NE(container_id, std::string(""));
}

TEST(CONTAINER, RunContainer) {
    container container_server("127.0.0.1", "7777");
    auto container_id =
        container_server.create_container("sleep", "/bin/sleep 60");
    std::cerr << container_id;
    EXPECT_NE(container_id, std::string(""));
}

TEST(CONTAINER, GetContainers) {
    container container_server("127.0.0.1", "7777");
    auto containers_list = container_server.get_containers();
    for (auto c : containers_list) {
        std::cerr << c;
    }
    EXPECT_NE(containers_list, std::list<std::string>());
}