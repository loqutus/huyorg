#include <gtest/gtest.h>
#include <chrono>
#include <iostream>
#include <thread>
#include "../lib/json/json.h"
#include "../lib/tcpclient/tcpclient.h"
#include "../lib/tcpserver/tcpserver.h"
#include "../lib/tcpserver/tcpserver.h"

std::string server_string, client_string, client_string_json;

void run_server() {
  tcpserver tcp_server;
  std::string read_string = tcp_server.read_string();
  tcp_server.write_string("OK");
  server_string = read_string;
}

void run_client() {
  tcpclient tcp_client;
  bool write_string = tcp_client.write_string("OK");
  std::string read_string = tcp_client.read_string();
  client_string = read_string;
}

TEST(Tcp, Tcptest) {
  std::thread server_thread(run_server);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::thread client_thread(run_client);
  server_thread.join();
  client_thread.join();
  std::cerr << server_string << std::endl;
  std::cerr << client_string << std::endl;
  EXPECT_EQ(server_string, client_string);
}

void run_server_json() {
  tcpserver tcp_server(std::string("::1"), std::string("6666"));
  std::string read_string = tcp_server.read_string();
  json json_obj(read_string);
  auto json_map = json_obj.get_map();
  std::string value = json_map[std::string("key")];
  tcp_server.write_string(value);
}

void run_client_json() {
  tcpclient tcp_client(std::string("::1"), std::string("6666"));
  std::string json_str = "{\"key\":\"value\"}";
  tcp_client.write_string(json_str);
  std::string read_string = tcp_client.read_string();
  client_string_json = read_string;
}

TEST(Tcp, TcpJsontest) {
  std::thread server_thread_json(run_server_json);
  std::thread client_thread_json(run_client_json);
  server_thread_json.join();
  client_thread_json.join();
  EXPECT_EQ(std::string("value"), client_string_json);
}
