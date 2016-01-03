//
// Created by Ruslan Gustomyasov on 21/11/15.
//

#include "main.h"
#include "../lib/tcpserver/tcpserver.h"
#include "../lib/logging/logging.h"
#include "../lib/confreader/confreader.h"

int main(int argc, char **argv) {
    confreader conf(std::string("../../master/master.conf"));
    logging(conf.get(std::string("log")));
    tcpserver server(boost::lexical_cast<unsigned short>(conf.get(std::string("port"))));
    return 0;
}