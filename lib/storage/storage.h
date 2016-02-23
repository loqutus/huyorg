#ifndef PROJECT_STORAGE_H
#define PROJECT_STORAGE_H

#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

class storage {
	std::unordered_map<std::string, std::unordered_map<std::string, std::string> > slaves_map;
	std::unordered_map<std::string, std::unordered_map<std::string, std::string> > pods_map;
	std::unordered_map<std::string, std::unordered_map<std::string, std::string> > containers_map;
public:
    ~storage();
    int set_slave(std::string key, std::unordered_map<std::string, std::string> value);
    int set_pod(std::string key, std::unordered_map<std::string, std::string> value);
    int set_container(std::string key, std::unordered_map<std::string, std::string> value);
	int count_slaves();
	std::unordered_map<std::string, std::string> get_slave(std::string key);
	std::unordered_map<std::string, std::string> get_pod(std::string key);
	std::unordered_map<std::string, std::string> get_container(std::string key);
	std::vector<std::string> get_slaves_list();
	std::vector<std::string> get_pods_list();
	std::vector<std::string> get_containers_list();
	
};
//extern storage store;
extern std::unique_ptr<storage> store;

#endif //PROJECT_STORAGE_H
