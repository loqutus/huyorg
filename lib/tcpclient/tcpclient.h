#ifndef PROJECT_TCPCLIENT_H
#define PROJECT_TCPCLIENT_H

#include "../logging/logging.h"
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>

class tcpclient {
  public:
    tcpclient(std::string host = std::string("::1"),
              std::string port = std::string("9999"), int timeout = 60);
    bool write_string(std::string message);
    std::string read_string();
    // std::string write_read_string(std::string message);

  private:
    std::string host;
    std::string port;
    int timeout;
    int buffer_size = 1048576;
};

#endif // PROJECT_TCPCLIENT_H
