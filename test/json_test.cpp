#include "../lib/json/json.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(JsonMap, JsonGetMapFromString) {
  std::string json_str("{\"1\":\"2\"}");
  json json_obj(json_str);
  auto json_map = json_obj.get_map();
  std::cerr << json_map[std::string("1")] << std::endl;
  EXPECT_EQ(std::string("2"), json_map[std::string("1")]);
}
