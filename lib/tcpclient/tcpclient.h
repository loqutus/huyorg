#ifndef PROJECT_TCPCLIENT_H
#define PROJECT_TCPCLIENT_H

#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
#include "../logging/logging.h"

class tcpclient {
 public:
  tcpclient(std::string host = std::string("::1"),
            std::string port = std::string("9999"));
  bool write_string(std::string message, int timeout = 60);
  std::string read_string(int timeout = 60);
  std::string write_read_string(std::string message, int timeout = 60);

 private:
  std::string host;
  std::string port;
  int buffer_size = 1048576;
};

#endif  // PROJECT_TCPCLIENT_H
