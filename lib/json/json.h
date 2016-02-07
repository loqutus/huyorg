#ifndef PROJECT_JSON_H
#define PROJECT_JSON_H

#include <fstream>
#include <string>
#include <algorithm>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <unordered_map>
#include <list>

class json {
	std::string input_string;
public:
	json(std::string input);
	~json();
	std::unordered_map<std::string, std::string> get_map();
	std::list<std::map<std::string, std::string> > get_list_of_maps();
};

#endif //PROJECT_JSON_H
