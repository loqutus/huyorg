#include "dockerclient.h"

dockerclient::dockerclient(std::string docker_host, std::string docker_port):
http_client(docker_host, docker_port){
}

std::list<std::string> dockerclient::get_containers(){
	std::string json_string = http_client.get(std::string("/containers/json"));
	json json_object(json_string);
	auto list_of_maps = json_object.get_list_of_maps();
	std::list<std::string> list_of_strings;
	for (auto map:list_of_maps){
		list_of_strings.push_back(map["Id"]);
	}
	return list_of_strings;
}


std::string dockerclient::run_container(std::string image, std::string command){
	std::string str;
	str += "{ \"Image\" : \"";
	str += image;
	str += "\", \"Cmd\" : [ \"";
	str += command;
	str += "\" ] }";
}
