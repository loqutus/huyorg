#include "tcpserver.h"

tcpserver::tcpserver(std::string host, std::string port)
    : endpoint(boost::asio::ip::tcp::endpoint(
          boost::asio::ip::address::from_string(host.c_str()),
          boost::lexical_cast<unsigned short>(port))),
      acceptor(boost::asio::ip::tcp::acceptor(io_service, endpoint)) {}

std::string tcpserver::read_string() {
  boost::asio::ip::tcp::iostream stream;
  boost::system::error_code ec;
  this->acceptor.accept(*stream.rdbuf(), ec);
  std::string s;
  std::getline(stream, s);
  return s;
}

bool tcpserver::write_string(std::string message) {
  boost::asio::ip::tcp::iostream stream;
  boost::system::error_code ec;
  this->acceptor.accept(*stream.rdbuf(), ec);
  stream << message;
  stream.flush();
  std::string answer;
  stream >> answer;
  return true;
}
