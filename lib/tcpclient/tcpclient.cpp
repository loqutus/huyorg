#include "tcpclient.h"

tcpclient::tcpclient(std::string host, std::string port, int timeout)
    : host(host), port(port), timeout(timeout) {}

bool tcpclient::write_string(std::string message) {
    boost::asio::ip::tcp::iostream stream;
    stream.expires_from_now(boost::posix_time::seconds(this->timeout));
    stream.connect(this->host, this->port);
    if (!stream)
        return false;
    stream << message;
    stream.flush();
    stream.close();
    return true;
}

std::string tcpclient::read_string() {
    boost::asio::ip::tcp::iostream stream;
    stream.expires_from_now(boost::posix_time::seconds(this->timeout));
    stream.connect(this->host.c_str(), this->port.c_str());
    if (!stream)
        return std::string("Fuck!");
    std::string read_data;
    stream >> read_data;
    stream.close();
    return read_data;
}

// std::string tcpclient::write_read_string(std::string message) {
//  boost::asio::ip::tcp::iostream stream;
//  stream.expires_from_now(boost::posix_time::seconds(this->timeout));
//  stream.connect(this->host.c_str(), this->port.c_str());
//  if (!stream) return std::string("Fuck!");
//  stream << message;
//  stream.flush();
//  std::string result, temp;
//  while (stream >> temp && stream.good() && !stream.eof() && temp.c_str()[0]
//  != '\n') {
//  }
//  while(std::getline(stream, temp)){
//    if (temp == std::string(""))
//  }
//  stream >> temp;
//  stream >> result;
//  stream.close();
//  return result;
//}
