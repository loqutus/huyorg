#include "httpclient.h"

httpclient::httpclient(std::string host, std::string port)
    : host(host), port(port) {}

std::string httpclient::get(std::string url) {
  tcpclient tcp_client(this->host, this->port);
  std::string message =
      std::string("GET ") + url + " HTTP/1.1\n Host: " + this->host + ":" +
      this->port +
      "\nUser-agent: huyorg/0.0.1\n Accept: */* \nAccept-Encoding: gzip" +
      "\n\n";
  auto read_message = tcp_client.write_read_string(message);
  return read_message;
}

std::string httpclient::post(std::string url, std::string body) {
  // logging log_obj("httpclient.log");
  tcpclient tcp_client(this->host, this->port);
  int body_length = body.length();
  std::string body_length_str = std::to_string(body_length - 1);
  std::string message = std::string("POST ") + url + " HTTP/1.1\nHost: [" +
                        this->host + "]:" + this->port + "\n" +
                        "User-agent: huyorg/0.0.1\nAccept: */*\nContent-Type: "
                        "application/json\n" +
                        "Content-Length: " + body_length_str + "\n\n" + body +
                        "\n";
  auto read_message = tcp_client.write_read_string(message);
  return read_message;
}

bool httpclient::post_zero_body(std::string uri) {
  tcpclient tcp_client(this->host, this->port);
  auto message = std::string("POST " + uri + " HTTP/1.1\nHost: [" +
                             this->host.c_str() + "]:" + this->port.c_str() +
                             "\nUser-Agent: huyorg/0.0.1\nAccept: */*\n\n");
  tcp_client.write_string(std::string(message));
  return true;
}
