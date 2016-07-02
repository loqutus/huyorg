#ifndef PROJECT_CONTAINER_H
#define PROJECT_CONTAINER_H

#include "../json/json.h"
#include <unordered_map>
#include <string>
#include <list>

class container {

public:
	dockerclient(std::string docker_host, std::string docker_port);
	std::list<std::string> get_containers();
	std::string run_conta:ner(std::string image, std::string command);
};

#endif //PROJECT_CONTAINER_H
