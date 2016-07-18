#ifndef PROJECT_HTTPSERVER_H
#define PROJECT_HTTPSERVER_H

#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <string>

class tcpserver {
 public:
  tcpserver(std::string host = std::string("::1"), std::string port = std::string("9999"));
  ~tcpserver();
  int accept();
  std::string read();
  int write(std::string message);
  int write(char *message);

 private:
  boost::asio::io_service io_service;
  boost::asio::ip::tcp::endpoint endpoint;
  boost::asio::ip::tcp::acceptor acceptor;
  boost::asio::ip::tcp::socket socket;
};

#endif  // PROJECT_HTTPSERVER_H
