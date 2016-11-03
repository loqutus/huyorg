#ifndef PROJECT_HTTPCLIENT_H
#define PROJECT_HTTPCLIENT_H

#include <string>
#include "../logging/logging.h"
#include "../tcpclient/tcpclient.h"

class httpclient {
  std::string host;
  std::string port;

 public:
  httpclient(std::string host, std::string port);
  std::string get(std::string url);
  std::string post(std::string url, std::string body);
};

#endif  // PROJECT_HTTPCLIENT_H
