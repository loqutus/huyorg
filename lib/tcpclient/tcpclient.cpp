#include "tcpclient.h"

tcpclient::tcpclient(std::string host, std::string port)
    : host(host), port(port) {}

bool tcpclient::write_string(std::string message, int timeout) {
  boost::asio::ip::tcp::iostream stream;
  //stream.expires_from_now(boost::posix_time::seconds(timeout));
  stream.connect(this->host, this->port);
  if (!stream) return false;
  stream << message;
  stream.flush();
  stream.close();
  return true;
}

std::string tcpclient::read_string(int timeout) {
  boost::asio::ip::tcp::iostream stream;
  //stream.expires_from_now(boost::posix_time::seconds(timeout));
  stream.connect(this->host.c_str(), this->port.c_str());
  if (!stream) return std::string("Fuck!");
  std::string read_data;
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
  std::string temp("");
  logging log_obj("tcpclient.log");
  for(int i=0;i<18;i++){
    stream >> temp;
  }
  log_obj.write(temp);
  return temp;
}


