#ifndef PROJECT_DOCKERCLIENT_H
#define PROJECT_DOCKERCLIENT_H

#include "../httpclient/httpclient.h"
#include "../json/json.h"
#include <unordered_map>
#include <string>
#include <list>

class dockerclient {
	httpclient http_client;
public:
	dockerclient(std::string docker_host, std::string docker_port);
	std::list<std::string> get_containers();
};

#endif //PROJECT_DOCKERCLIENT_H
