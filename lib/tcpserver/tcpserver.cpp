#include "tcpserver.h"

tcpserver::tcpserver(std::string port) : endpoint(
        boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v6(), boost::lexical_cast<unsigned short>(port))),
                                            acceptor(boost::asio::ip::tcp::acceptor(io_service, endpoint)),
                                            socket(boost::asio::ip::tcp::socket(io_service)) {

}

tcpserver::~tcpserver() {
    socket.close();
}

int tcpserver::accept() {
    acceptor.accept(socket);
    return 0;
}