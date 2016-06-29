#include "storage.h"

storage::~storage(){
	slaves_map.clear();
	pods_map.clear();
    containers_map.clear();
}

bool storage::is_slaves_empty(){
	return slaves_map.empty();
}

bool storage::is_pods_empty(){
	return pods_map.empty();
}

bool storage::is_containers_empty(){
    return containers_map.empty();
}

int storage::set_slave(std::string key, std::unordered_map<std::string, std::string> value){
	this->slaves_map[key] = value;
    return 0;
}

int storage::set_pod(std::string key, std::unordered_map<std::string, std::string> value){
	this->pods_map[key] = value;
    return 0;
}

int storage::set_container(std::string key, std::unordered_map<std::string, std::string> value){
    this->containers_map[key] = value;
    return 0;
}

std::unordered_map<std::string, std::string> storage::get_slave(std::string key){
	return this->slaves_map[key];
}

std::unordered_map<std::string, std::string> storage::get_pod(std::string key) {
	return this->pods_map[key];
}

std::vector<std::string> storage::get_slaves_vector(){
	std::vector<std::string> slaves_vector;
	for(auto &iterator: this->slaves_map){
		slaves_vector.push_back(iterator.first);
	}
	return slaves_vector;
}

std::vector<std::string> storage::get_pods_vector(){
	std::vector<std::string> pods_vector;
	for(auto &iterator: this->pods_map){
		pods_vector.push_back(iterator.first);
	}
	return pods_vector;
}

std::vector<std::string> storage::get_containers_vector(){
    std::vector<std::string> containers_vector;
    for(auto &iterator: this->containers_map){
        containers_vector.push_back(iterator.first);
    }
    return containers_vector;
}
