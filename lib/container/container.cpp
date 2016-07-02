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
	std::string body;
	body += "{ \"Image\" : \"";
	body += image;
	body += "\", \"Cmd\" : [ \"";
	body += command;
	body += "\" ] }";
	auto response = http_client.post("/containers/create", body);
	json json_object(response);
	auto map = json_object.get_map();
	std::string container_id = map["Id"];
	return container_id;
}
