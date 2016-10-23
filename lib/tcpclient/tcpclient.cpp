#include "tcpclient.h"

tcpclient::tcpclient(std::string host, std::string port)
    : host(host), port(port) {}

bool tcpclient::write_string(std::string message, int timeout) {
  boost::asio::ip::tcp::iostream stream;
  stream.expires_from_now(boost::posix_time::seconds(timeout));
  stream.connect(host, port);
  if (!stream) return false;
  stream << message;
  stream.flush();
  stream.close();
  return true;
}

std::string tcpclient::read_string(int timeout) {
  boost::asio::ip::tcp::iostream stream;
  stream.expires_from_now(boost::posix_time::seconds(timeout));
  stream.connect(host, port);
  std::string read_data;
  if (!stream) return std::string("Fuck!");
  stream >> read_data;
  stream.close();
  return read_data;
}

std::string tcpclient::write_read_string(std::string message, int timeout) {
  boost::asio::ip::tcp::iostream stream;
  stream.expires_from_now(boost::posix_time::seconds(timeout));
  stream.connect(host, port);
  if (!stream) return std::string("Fuck!");
  stream << message;
  stream.flush();
  std::string answer;
  stream >> answer;
  stream.close();
  return answer;
}


