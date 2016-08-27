#ifndef PROJECT_TCPSERVER_H
#define PROJECT_TCPSERVER_H

#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <string>
#include <vector>

class tcpserver {
 public:
  tcpserver(std::string host = std::string("::1"),
            std::string port = std::string("9999"));
  void listen();
  std::string read_string(int timeout = 60);
  bool write_string(std::string message, int timeout = 60);
  int close();

 private:
  boost::asio::io_service io_service;
  boost::asio::ip::tcp::endpoint endpoint;
  boost::asio::ip::tcp::acceptor acceptor;
  boost::asio::ip::tcp::iostream stream;
  boost::system::error_code ec;
};

#endif  // PROJECT_SERVER_H
