#include "tcpclient.h"

tcpclient::tcpclient(std::string host, std::string port) : socket(boost::asio::ip::tcp::socket(aios)) {
    boost::asio::ip::tcp::resolver resolver(aios);
    boost::asio::ip::tcp::resolver::iterator endpoint = resolver.resolve(
            boost::asio::ip::tcp::resolver::query(host.c_str(), port.c_str()));
    boost::asio::connect(socket, endpoint);
}

std::string tcpclient::send(std::string message) {
    boost::asio::write(socket, boost::asio::buffer(message));
}

std::string tcpclient::read() {
    std::array<char, 1048576> buf;
    for (; ;) {
        boost::system::error_code error;
        size_t len = socket.read_some(boost::asio::buffer(buf), error);
        if (error == boost::asio::error::eof)
            break;
        else if (error)
            throw boost::system::system_error(error);
    }
    return std::string(buf.data());
}