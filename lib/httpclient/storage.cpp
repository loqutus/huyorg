#include "storage.h"

storage::~storage() {
	slaves_map.clear();
	pods_map.clear();
	containers_map.clear();
}

int storage::set_slave(std::string key, std::unordered_map<std::string, std::string> value) {
	this->slaves_map[key] = value;
    return 0;
}

int storage::set_pod(std::string key, std::unordered_map<std::string, std::string> value) {
	this->pods_map[key] = value;
    return 0;
}

int storage::set_container(std::string key, std::unordered_map<std::string, std::string> value) {
	this->slaves_map[key] = value;
    return 0;
}

std::unordered_map<std::string, std::string> storage::get_slave(std::string key) {
	return this->slaves_map[key];
}

std::unordered_map<std::string, std::string> storage::get_pod(std::string key) {
	return this->pods_map[key];
}

std::unordered_map<std::string, std::string> storage::get_container(std::string key) {
	return this->containers_map[key];
}
