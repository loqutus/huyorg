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

int master::listen(){
	while(true){
		tcpserver server(server_port);
		log.write("listening");
		server.accept();
		log.write("client connect");
		std::string s = server.read();
		json json_object(s);
		auto json_map = json_object.get_map();
		std::string action = json_map[std::string("action")];
		log.write("client action", action);
	}
	return 0;
}

master::~master(){
	log.write("stopping master");
}
