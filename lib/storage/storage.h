#ifndef PROJECT_STORAGE_H
#define PROJECT_STORAGE_H

#include <fstream>
#include <string>
#include <unordered_map>

class storage {
	std::unordered_map<std::string, std::string> storage_map;
public:
    storage(std::string storagefilename);
    ~storage();
    int set(std::string key, std::string value);
	std::string get(std::string key);
};

#endif //PROJECT_STORAGE_H
