#include "../lib/httpclient/httpclient.h"
#include "../lib/json/json.h"
#include <gtest/gtest.h>
#include <iostream>
#include <list>
#include <string>

TEST(HTTP, HttpPostTest) {
    std::string url("http://127.0.0.1:7777/containers/create");
    std::string body = "{\"image\":\"sleep\", \"command\":\"/bin/sleep 60\"}";
    httpclient client(url, body);
    auto create_container = client.post();
    EXPECT_NE(create_container, std::string(""));
}

TEST(HTTP, HttpGetTest) {
    std::string url("http://127.0.0.1:7777/containers/json");
    httpclient client(url);
    auto get_containers = client.get();
    std::cerr << get_containers << std::endl;
    EXPECT_NE(get_containers, std::string(""));
}
