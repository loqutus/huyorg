#include "master.h"

master::master() :
   	conf_file(std::string("../master/master.conf")),
	conf(conf_file), 
	log(conf.get("log")),
	server_port(conf.get(std::string("port")))
{
		log.write("starting master");
		log.write("config: ", conf_file.c_str());
		log.write("port: ", server_port);
}

void master::listen(){
	while(true){
		tcpserver server(server_port);
		log.write("listening");
		server.accept();
		log.write("client connect");
		std::string s = server.read();
		json json_object(s);
		std::unordered_map<std::string, std::string> json_map = json_object.get_map();
		std::string action = json_map[std::string("action")];
		log.write("client action:", action);
		std::string action_string = this->do_action(json_map);
		server.write(action_string);
	}
}

std::string master::do_action(std::unordered_map<std::string, std::string> json_map){
	std::string return_string;
	std::string action = json_map["action"];
	if (action == std::string("add_slave")){
		std::string slave_name = json_map[std::string("slave_host")];
		store.set_slave(slave_name, json_map);	
		log.write("slave_add ", slave_name);
		return_string = std::string("slave added");
	}
	else if(action == std::string("add_pod")){
		std::string pod_name = json_map[std::string("pod_name")];
		store.set_pod(pod_name, json_map);
		log.write("pod_add ", pod_name);
		return_string = std::string("pod added");
	}
	return return_string;
}

master::~master(){
	log.write("stopping master");
}
