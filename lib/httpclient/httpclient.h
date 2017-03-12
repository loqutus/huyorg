#ifndef PROJECT_HTTPCLIENT_H
#define PROJECT_HTTPCLIENT_H

#include <cstddef>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>
#include <sstream>
#include <string>

class httpclient {
  std::string url;
  const char *data;
  static size_t readData(char *buffer, size_t size, size_t nitems);

public:
  httpclient(std::string url, std::string body = "");
  std::string get();
  std::string post();
};

#endif // PROJECT_HTTPCLIENT_H
