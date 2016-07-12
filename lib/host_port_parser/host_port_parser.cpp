#include "host_port_parser.h"

host_port_parser::host_port_parser(std::string host_port) {
  this->host_port = host_port;
}

std::string host_port_parser::get_port() {
  std::vector<std::string> strs;
  boost::algorithm::split(strs, this->host_port, boost::is_any_of(":"));
  return strs.back();
}

std::string host_port_parser::get_host(std::string host_port) {
  std::vector<std::string> strs;
  boost::algorithm::split(strs, this->host_port, boost::is_any_of(":"));
  std::string return_string("");
  for (std::string i : strs) {
    if (i == strs.back()) {
      return_string.pop_back();
      break;
    }
    return_string += i;
    return_string += std::string(":");
  }
  return return_string;
}
