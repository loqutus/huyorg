#include <gtest/gtest.h>
#include <iostream>
#include "../lib/container/container.h"

/*TEST(Container, RunContainerTest) {
  container container_client("::1", "7777");
  auto container_id = container_client.run_container("sleep", "/bin/sleep 1");
  std::cerr << container_id << std::endl;
  EXPECT_NE(container_id, std::string(""));
}*/

TEST(Container, GetContainersTest) {
  container container_client("::1", "7777");
  auto container_id =
      container_client.create_container("sleep", "/bin/sleep 1");
  std::cerr << container_id << std::endl;
  auto container_started = container_client.run_container(container_id);
  std::cerr << container_started << std::endl;
  auto containers_list = container_client.get_containers();
  std::cerr << containers_list.back() << std::endl;
  EXPECT_NE(container_id, std::string(""));
}
