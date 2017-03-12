#include "../lib/json/json.h"
#include "../lib/storage/storage.h"
#include <gtest/gtest.h>

TEST(Storage, StorageSlave) {
  std::unordered_map<std::string, std::string> slave_map;
  slave_map[std::string("host")] = std::string("pi1");
  slave_map[std::string("port")] = std::string("9999");
  slave_map[std::string("cpus")] = std::string("4");
  slave_map[std::string("memory")] = std::string("1024");
  slave_map[std::string("disk")] = std::string("32");
  storage store;
  store.set_slave(std::string("pi1:9999"), slave_map);
  EXPECT_EQ(slave_map, store.get_slave(std::string("pi1:9999")));
}

TEST(Storage, StoragePod) {
  std::unordered_map<std::string, std::string> pod_map;
  pod_map[std::string("name")] = std::string("sleep");
  pod_map[std::string("count")] = int(1);
  pod_map[std::string("image")] = std::string("sleep");
  pod_map[std::string("command")] = std::string("/bin/sleep 10");
  storage store;
  store.set_pod(std::string("sleep"), pod_map);
  EXPECT_EQ(pod_map, store.get_pod(std::string("sleep")));
}
