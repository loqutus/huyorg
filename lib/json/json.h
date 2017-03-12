#ifndef PROJECT_JSON_H
#define PROJECT_JSON_H

#include <algorithm>
#include <boost/foreach.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <fstream>
#include <list>
#include <string>
#include <unordered_map>

class json {
  std::string input_string;
  std::unordered_map<std::string, std::string> input_map;
  std::list<std::string> input_list;

public:
  json(std::string input);
  json(std::unordered_map<std::string, std::string> input);
  json(std::list<std::string> input);
  ~json();
  std::unordered_map<std::string, std::string> get_map();
  std::string get_key_from_map(std::string key);
  std::list<std::string> get_list();
  std::list<std::unordered_map<std::string, std::string>> get_list_of_maps();
  std::string get_string_from_map();
  std::string get_string_from_list();
};

#endif // PROJECT_JSON_H
