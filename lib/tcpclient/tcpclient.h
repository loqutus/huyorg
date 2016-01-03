//
// Created by Ruslan Gustomyasov on 31/12/15.
//

#ifndef PROJECT_TCPCLIENT_H
#define PROJECT_TCPCLIENT_H
#include <string>

class tcpclient {
    tcpclient(std::string address, unsigned short port);
    std::string send(std::string request);
private:
    boost::asio::io_service io_service;
};


#endif //PROJECT_TCPCLIENT_H
