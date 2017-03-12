#include "../lib/httpclient/httpclient.h"
#include <gtest/gtest.h>
#include <iostream>
#include <list>
#include <string>

TEST(HTTP, HttpPostTest) {
  std::string url("http://127.0.0.1]:7777/containers/create");
  std::string json_body =
      "{\"image\":\"sleep\", \"command\":\"/bin/sleep 60\"}";
  httpclient client(url);
  auto create_container = client.post(url, json_body);
  std::cerr << create_container;
  EXPECT_NE(create_container, std::string(""));
  EXPECT_NE(create_container, std::string("Fuck!"));
}

TEST(HTTP, HttpGetTest) {
  httpclient client("127.0.0.1", "7777", 1);
  std::string url("http://[127.0.0.1]:7777/containers/json");
  auto get_containers = client.get(url);
  std::cerr << get_containers;
  EXPECT_NE(get_containers, std::string(""));
  EXPECT_NE(get_containers, std::string("Fuck!"));
}
