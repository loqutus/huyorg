#include <gtest/gtest.h>
#include <iostream>
#include "../lib/container/container.h"

TEST(Container, GetContainersTest) {
  container container_client("::1", "7777");
  auto containers_list = container_client.get_containers();
  std::list<std::string> empty_list;
  EXPECT_EQ(containers_list, empty_list);
}

TEST(Container, RunContainerTest) {
  container container_client("::1", "7777");
  auto container_id = container_client.run_container("sleep", "/bin/sleep 1");
  std::cerr << container_id << std::endl;
  EXPECT_NE(container_id, std::string(""));
}
