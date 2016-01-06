//
// Created by Ruslan Gustomyasov on 31/12/15.
//

#include "tcpclient.h"
tcpclient(std::string host, std::string port = std::string("9999")):
    resolver(boost::asio::ip::tcp::resolver(io_service)),
    query(host.c_str(), port.c_str()),
    endpoint(query)
{
    boost::asio::connect(socket, endpoint);
}