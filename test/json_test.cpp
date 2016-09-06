#include "../lib/json/json.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(Json, JsonGetMapFromString) {
  std::string json_str("{\"1\":\"2\"}");
  json json_obj(json_str);
  auto json_map = json_obj.get_map();
  EXPECT_EQ(std::string("2"), json_map[std::string("1")]);
}

TEST(Json, JsonGetListOfMapsFromString) {
  std::string json_str("{\"1\":\"2\",\"3\":\"4\"}");
  json json_obj(json_str);
  auto json_map = json_obj.get_map();
  EXPECT_EQ(std::string("2"), json_map[std::string("1")]);
  EXPECT_EQ(std::string("4"), json_map[std::string("3")]);
}

TEST(Json, JsonGetKeyFromString) {
  std::string json_str("{\"1\":\"2\",\"3\":\"4\"}");
  json json_obj(json_str);
  auto result_string = json_obj.get_key_from_map(std::string("1"));
  EXPECT_EQ(std::string("2"), result_string);
}
