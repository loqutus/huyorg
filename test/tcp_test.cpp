#include "../lib/tcpserver/tcpserver.h"
#include "../lib/tcpclient/tcpclient.h"
#include <thread>
#include <gtest/gtest.h>
#include <chrono>
#include <iostream>

std::string server_string, client_string;

void run_server(){
  tcpserver tcp_server;
  std::string read_string = tcp_server.read_string();
  tcp_server.write_string("OK");
  server_string = read_string;
}

void run_client(){
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

