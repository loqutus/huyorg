//
// Created by Ruslan Gustomyasov on 31/12/15.
//

#ifndef PROJECT_TCPCLIENT_H
#define PROJECT_TCPCLIENT_H
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <string>
class tcpclient {
    tcpclient(std::string host, std::string port = std::string("9999"));
private:
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::resolver resolver;
    boost::asio::ip::tcp::resolver::query query;
    boost::asio::ip::tcp::resolver::iterator endpoint;
};


#endif //PROJECT_TCPCLIENT_H
