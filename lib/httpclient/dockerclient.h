#ifndef PROJECT_DOCKERCLIENT_H
#define PROJECT_DOCKERCLIENT_H

#include "../tcpclient/tcpclient.h"
#include "../json/json.h"
#include <unordered_map>
#include <string>

class dockerclient {
	tcpclient tcp_client;
public:
	dockerclient(std::string docker_host, std::string docker_port);
	std::string run_container();
	std::unordered_map<std::string, std::string> send(std::string command);
};

#endif //PROJECT_DOCKERCLIENT_H
