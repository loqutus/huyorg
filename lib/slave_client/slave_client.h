#ifndef PROJECT_SLAVE_CLIENT_H
#define PROJECT_SLAVE_CLIENT_H

#include "../json/json.h"
#include "../tcpclient/tcpclient.h"
#include <string>
#include <unordered_map>
#include <vector>

class slave_client {
    std::string slave_host;
    std::string slave_port;

public:
    slave_client(std::string slave_host, std::string slave_port);
    std::list<std::string> get_containers();
    std::string run_container(std::string image, std::string command);
    std::string destroy_container(std::string container_id);
};

#endif // PROJECT_SLAVE_CLIENT_H
