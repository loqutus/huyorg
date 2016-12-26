#include <gtest/gtest.h>
#include <chrono>
#include <iostream>
#include <thread>
#include "../lib/container/container.h"

TEST(Container, RunContainerTest) {
  container container_client("::1", "7777");
  auto container_id =
      container_client.create_container("sleep", "/bin/sleep 10");
  std::cerr << container_id << std::endl;
  auto container_started = container_client.run_container(container_id);
  std::cerr << container_started << std::endl;
  EXPECT_EQ(container_started, true);
}
/*
TEST(Container, GetContainersTest) {
  container container_client("::1", "7777");
  auto container_id =
      container_client.create_container("sleep", "/bin/sleep 10");
  std::cerr << container_id << std::endl;
  auto container_started = container_client.run_container(container_id);
  std::cerr << container_started << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(2));
  auto containers_list = container_client.get_containers();
  std::cerr << containers_list << std::endl;
  EXPECT_NE(container_id, std::string(""));
}*/
