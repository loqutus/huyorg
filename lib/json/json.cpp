#include "json.h"

json::json(std::string input){
	this->input_string = input;
}

json::~json(){
	input.clear();
}

std::unordered_map<std::string, std::string> json::get_map(){
	boost::property_tree::ptree ptree;
	std::stringstream ss;
	ss << input_string;
	boost::property_tree::read_json(ss, ptree);
	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, ptree){
		this->map[v.first] = v.second.data();
	}
	return this->map;
}

std::unordered_map<std::string, std::string> json::get_map_of_maps(){
	boost::property_tree::ptree ptree;
	std::stringstream ss;
	ss << input_string;
	boost::property_tree::read_json(ss, ptree);
	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, ptree){
		input_string2 = v.second.data();
		boost::property_tree::ptree ptree2;
		std::stringstream ss2;
		ss2 << input_string2;
		boost::property_tree::read_json(ss2, ptree2);
		BOOST_FOREACH(boost::property_tree::ptree::value_type &v2, ptree2){
			this->map[v.first] = v.second.data();
		}
	}
	return this->map;
}
