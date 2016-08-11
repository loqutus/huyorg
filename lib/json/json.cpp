#include "json.h"

json::json(std::string input) { this->input_string = input; }

json::json(std::unordered_map<std::string, std::string> input) {
  this->input_map = input;
}

json::json(std::list<std::string> input) { this->input_list = input; }

json::~json() { input_string.clear(); }

std::string json::get_string_from_map() {
  if (input_map.empty()) {
    return std::string("{}");
  }
  std::string str("{");
  for (auto kv : input_map) {
    str += " \"";
    str += kv.first;
    str += "\" : \"";
    str += kv.second;
    str += "\" ,";
  }
  str.pop_back();
  str += "}";
  return str;
}

std::string json::get_string_from_list() {
  if (input_list.empty()) {
    return std::string("[]");
  }
  std::string str("[");
  for (auto v : this->input_list) {
    str += "\"";
    str += v;
    str += "\",";
  }
  str.pop_back();
  str += "]";
  return str;
}

std::unordered_map<std::string, std::string> json::get_map() {
  try {
    std::unordered_map<std::string, std::string>* map =
        new std::unordered_map<std::string, std::string>;
    boost::property_tree::ptree ptree;
    std::stringstream ss;
    ss << input_string;
    boost::property_tree::read_json(ss, ptree);
    BOOST_FOREACH (boost::property_tree::ptree::value_type& v, ptree) {
      map->at(v.first) = v.second.data();
    }
    return *map;
  } catch (...) {
    return std::unordered_map<std::string, std::string>();
  }
}

std::list<std::string> json::get_list() {
  try {
    std::list<std::string> list;
    boost::property_tree::ptree ptree;
    std::stringstream ss;
    ss << this->input_string;
    boost::property_tree::read_json(ss, ptree);
    BOOST_FOREACH (boost::property_tree::ptree::value_type& v, ptree) {
      list.push_back(v.first.data());
    }
    return list;
  } catch (...) {
    return std::list<std::string>();
  }
}

std::list<std::unordered_map<std::string, std::string>>
json::get_list_of_maps() {
  try {
    std::list<std::unordered_map<std::string, std::string>> result_list;
    boost::property_tree::ptree ptree;
    std::stringstream ss;
    ss << input_string;
    boost::property_tree::read_json(ss, ptree);
    BOOST_FOREACH (boost::property_tree::ptree::value_type& v, ptree) {
      std::string input_string2 = v.second.data();
      boost::property_tree::ptree ptree2;
      std::stringstream ss2;
      ss2 << input_string2;
      boost::property_tree::read_json(ss2, ptree2);
      std::unordered_map<std::string, std::string> temp_map;
      BOOST_FOREACH (boost::property_tree::ptree::value_type& v2, ptree2) {
        temp_map[v2.first] = v2.second.data();
      }
      result_list.push_back(temp_map);
    }
    return result_list;
  } catch (...) {
    return std::list<std::unordered_map<std::string, std::string>>();
  }
}
