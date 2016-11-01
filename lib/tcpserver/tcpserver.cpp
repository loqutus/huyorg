#include "tcpserver.h"

tcpserver::tcpserver(std::string host, std::string port)
    : endpoint(boost::asio::ip::tcp::endpoint(
          boost::asio::ip::address::from_string(host.c_str()),
          boost::lexical_cast<unsigned short>(port))),
      acceptor(boost::asio::ip::tcp::acceptor(io_service, endpoint)) {}

std::string tcpserver::read_string(int timeout) {
  boost::asio::ip::tcp::iostream stream;
  boost::system::error_code ec;
  //stream.expires_from_now(boost::posix_time::seconds(timeout));
  this->acceptor.accept(*stream.rdbuf(), ec);
  char buffer[1];
  std::string s;
  while (stream.read(buffer, sizeof(buffer))) {
    s.append(buffer, sizeof(buffer));
  }
  //s.append(buffer, sizeof(buffer));
  stream.close();
  return s;
}

bool tcpserver::write_string(std::string message, int timeout) {
  boost::asio::ip::tcp::iostream stream;
  boost::system::error_code ec;
  //stream.expires_from_now(boost::posix_time::seconds(timeout));
  this->acceptor.accept(*stream.rdbuf(), ec);
  //stream.write(message.c_str(), sizeof(message.c_str()) + 1);
  //stream.write(message.c_str(), sizeof(message.c_str()));
  stream << message;
  stream.flush();
  stream.close();
  return true;
}
