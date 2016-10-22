#include "httpclient.h"

httpclient::httpclient(std::string host, std::string port)
    : host(host), port(port) {}

std::string httpclient::get(std::string url) {
  tcpclient tcp_client(this->host, this->port);
  std::string message = std::string("GET ") + url + " HTTP/1.1\n\n";
  if (tcp_client.write_string(message)) {
    auto read_message = tcp_client.read_string();
    // read_message.erase(0, read_message.find("\n") + 1);
    // read_message.erase(0, read_message.find("\n") + 1);
    // read_message.erase(0, read_message.find("\n") + 1);
    return read_message;
  } else {
    return "FAIL";
  }
}

std::string httpclient::post(std::string url, std::string body) {
  tcpclient tcp_client(this->host, this->port);
  std::string message = std::string("POST ") + url +
                        " HTTP/1.1\n Content-Type: application/json\n\n" + body + "\n";
  if (tcp_client.write_string(message)) {
    auto read_message = tcp_client.read_string();
    // read_message.erase(0, read_message.find("\n") + 1);
    // read_message.erase(0, read_message.find("\n") + 1);
    // read_message.erase(0, read_message.find("\n") + 1);
    return read_message;
  } else {
    return "FAIL";
  }
}
