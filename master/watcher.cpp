#include "watcher.h"

std::string watcher::get_port(std::string host_port){
	std::vector<std::string> strs;
	boost::algorithm::split(strs, host_port, boost::is_any_of(":"));
	return strs.back();
}

std::string watcher::get_host(std::string host_port){
	std::vector<std::string> strs;
	boost::algorithm::split(strs, host_port, boost::is_any_of(":"));
	std::string return_string("");
	for(std::string i:strs){
		if(i == strs.back()){
			return_string.pop_back();
			break;
		}
		return_string += i;	
		return_string += std::string(":");
	}
	return return_string;
}

void watcher::watch(){
	while(true){
		auto running_containers = this->get_running_containers();
	}
}

std::unordered_map<std::string, std::list<std::string> > watcher::get_running_containers(){
	auto slaves_list = store.get_slaves_list();
	for (std::string i:slaves_list) {
		    dockerclient docker_client(get_host(i), get_port(i));
	}
}
