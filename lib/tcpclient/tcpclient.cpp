#include "tcpclient.h"

tcpclient::tcpclient(std::string host, std::string port)
    : host(host), port(port) {}

void tcpclient::connect(int timeout) {
  this->network_stream.expires_from_now(boost::posix_time::seconds(timeout));
  this->network_stream.connect(host, port);
}

bool tcpclient::write_string(std::string message, int timeout) {
  // this->network_stream.expires_from_now(boost::posix_time::seconds(timeout));
  std::string answer;
  if (!this->network_stream) return false;
  this->network_stream << message;
  this->network_stream.flush();
  return true;
}

std::string tcpclient::read_string(int timeout) {
  this->network_stream.expires_from_now(boost::posix_time::seconds(timeout));
  std::string read_data;
  if (!this->network_stream) return std::string("");
  this->network_stream >> read_data;
  return read_data;
}

int tcpclient::close() {
  this->network_stream.close();
  return 0;
}
