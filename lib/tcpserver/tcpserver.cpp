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

std::string tcpserver::read() {
    std::array<char, 1048576> buf;
    for(;;)
    {
        boost::system::error_code error;
        size_t len = socket.read_some(boost::asio::buffer(buf), error);
        if(error == boost::asio::error::eof)
            break;
        else if(error)
            throw boost::system::system_error(error);
    }
    return std::string(buf.data());
}

int tcpserver::write(std::string message) {
    boost::asio::write(socket, boost::asio::buffer(message));
    return 0;
}