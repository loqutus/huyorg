#include "dockerclient.h"

dockerclient::dockerclient(std::string docker_host, std::string docker_port):
http_client(docker_host, docker_port){
}

std::list<std::string> dockerclient::get_containers(){
	std::string json_string = http_client.get(std::string("/containers/json"));
	json json_object(json_string);
}
