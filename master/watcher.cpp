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

bool watcher::check_pod_in_containers(std::string pod_name, std::vector<std::string> containers_vector){
	return std::find(containers_vector.begin(), containers_vector.end(), pod_name) != containers_vector.end();
}


void watcher::watch(){
	log_obj.write("starting watcher");
	while(true){
		if (store.is_slaves_empty()){
			log_obj.write("sleeping 60 seconds");
			std::this_thread::sleep_for(std::chrono::milliseconds(60000));
			continue;
		}
		log_obj.write("sleeping 60 seconds");
		std::this_thread::sleep_for(std::chrono::milliseconds(60000));
	}
}

std::string watcher::run_container(std::string slave, std::string image, std::string command){
	dockerclient docker_client(this->get_host(slave), this->get_port(slave));
	std::string container_id = docker_client.run_container(image, command);
	return container_id;
}



std::unordered_map<std::string, std::vector<std::string> > watcher::get_running_containers(){
	auto slaves_vector = store.get_slaves_vector();
	std::unordered_map<std::string, std::vector<std::string> > running_containers;
	for (std::string slave : slaves_vector) {
		    dockerclient docker_client(get_host(slave), get_port(slave));
			running_containers[slave] = docker_client.get_containers();
	}
	return running_containers;
}
