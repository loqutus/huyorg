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
    std::string data;

  public:
    httpclient(std::string url, std::string data = "");
    std::string get();
    std::string post();
};

#endif // PROJECT_HTTPCLIENT_H
