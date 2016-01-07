#include "tcpclient.h"

tcpclient::tcpclient(std::string host, std::string port) : socket(boost::asio::ip::tcp::socket(aios)) {
    boost::asio::ip::tcp::resolver resolver(aios);
    boost::asio::ip::tcp::resolver::iterator endpoint = resolver.resolve(
            boost::asio::ip::tcp::resolver::query(host.c_str(), port.c_str()));
    boost::asio::connect(socket, endpoint);
}

std::string tcpclient::send(std::string message) {
    char buf[1048576];

}