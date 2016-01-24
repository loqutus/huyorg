#include "json.h"

json::json(std::string input){
	boost::property_tree::ptree ptree;
	std::stringstream ss;
	ss << input;
	boost::property_tree::read_json(ss, ptree);
	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, ptree){
		this->map[v.first] = v.second.data();
	}
}

json::~json(){
	map.clear();
}

std::unordered_map<std::string, std::string> json::get_map(){
	return this->map;
}

