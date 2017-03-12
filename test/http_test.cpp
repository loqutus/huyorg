#include "../lib/httpclient/httpclient.h"
#include <gtest/gtest.h>
#include <iostream>
#include <list>
#include <string>

TEST(HTTP, HttpPostTest) {
    std::string url("http://127.0.0.1]:7777/containers/create");
    std::string json_body =
        "{\"image\":\"sleep\", \"command\":\"/bin/sleep 60\"}";
    httpclient client(url, json_body);
    auto create_container = client.post();
    std::cerr << create_container;
    EXPECT_NE(create_container, std::string(""));
    EXPECT_NE(create_container, std::string("ERROR"));
}

TEST(HTTP, HttpGetTest) {
    std::string url("http://[127.0.0.1]:7777/containers/json");
    httpclient client(url);
    auto get_containers = client.get();
    EXPECT_NE(get_containers, std::string(""));
    EXPECT_NE(get_containers, std::string("ERROR"));
}
