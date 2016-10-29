#ifndef PROJECT_TCPCLIENT_H
#define PROJECT_TCPCLIENT_H

#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include "../logging/logging.h"

class tcpclient {
 public:
  tcpclient(std::string host, std::string port);
  bool write_string(std::string message, int timeout = 60);
  std::string read_string(int timeout = 60);
  std::string write_read_string(std::string message, int timeout=60);

 private:
  std::string host;
  std::string port;
  int buffer_size = 1048576;
};

#endif  // PROJECT_TCPCLIENT_H
