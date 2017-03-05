#include <gtest/gtest.h>
#include <iostream>
#include <list>
#include <string>
#include "../lib/httpclient/httpclient.h"

TEST(HTTP, HttpPostTest) {
  httpclient client("127.0.0.1", "7777");
  std::string url("http://127.0.0.1]:7777/containers/create");
  std::string json_body =
      "{\"image\":\"sleep\", \"command\":\"/bin/sleep 60\"}";
  auto create_container = client.post(url, json_body);
  EXPECT_NE(create_container, std::string(""));
  EXPECT_NE(create_container, std::string("Fuck!"));
}

TEST(HTTP, HttpGetTest) {
  httpclient client("127.0.0.1", "7777");
  std::string url("http://[127.0.0.1]:7777/containers/json");
  auto get_containers = client.get(url);
  EXPECT_NE(get_containers, std::string(""));
  EXPECT_NE(get_containers, std::string("Fuck!"));
}
