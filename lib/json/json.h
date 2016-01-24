#ifndef PROJECT_JSON_H
#define PROJECT_JSON_H

#include <fstream>
#include <string>
#include <algorithm>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <unordered_map>

class json {
	std::unordered_map<std::string, std::string> map;
	std::string string;
public:
	json(std::string input);
	~json();
	std::unordered_map<std::string, std::string> get_map();
};

#endif //PROJECT_JSON_H
