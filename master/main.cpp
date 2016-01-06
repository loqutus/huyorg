//
// Created by Ruslan Gustomyasov on 21/11/15.
//

#include "main.h"
#include "../lib/tcpserver/tcpserver.h"
#include "../lib/logging/logging.h"
#include "../lib/confreader/confreader.h"

int main(int argc, char **argv) {
    const std::string conf_file("../master/master.conf");
    confreader conf(conf_file);
    logging log(conf.get(std::string("log")));
    log.write("starting master");
    log.write("read config file", conf_file);
    const std::string server_port = conf.get(std::string("port"));
    tcpserver server(server_port);
    log.write("listening on port", server_port);
    server.accept();
    server.write(std::string("hello"));
    return 0;
}