#include "tcpserver.h"

tcpserver::tcpserver(std::string host, std::string port)
    : endpoint(boost::asio::ip::tcp::endpoint(
          boost::asio::ip::address::from_string(host.c_str()),
          boost::lexical_cast<unsigned short>(port))),
      acceptor(boost::asio::ip::tcp::acceptor(io_service, endpoint)) {}

void tcpserver::listen() {
  this->acceptor.accept(*this->stream.rdbuf(), this->ec);
}

std::string tcpserver::read_string(int timeout) {
  this->stream.expires_from_now(boost::posix_time::seconds(timeout));
  std::string s;
  char buffer[4096];
  while (this->stream.read(buffer, sizeof(buffer))) {
    s.append(buffer, sizeof(buffer));
  }
  s.append(buffer, stream.gcount());
  return s;
}

bool tcpserver::write_string(std::string message, int timeout) {
  this->stream.expires_from_now(boost::posix_time::seconds(timeout));
  this->stream.write(message.c_str(), sizeof(message.c_str()));
  // this->stream << message;
  this->stream.flush();
  return true;
}

int tcpserver::close() {
  this->stream.close();
  return 0;
}
