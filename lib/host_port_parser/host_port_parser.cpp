#include "watcher.h"

std::string watcher::get_port(std::string host_port) {
  std::vector<std::string> strs;
  boost::algorithm::split(strs, host_port, boost::is_any_of(":"));
  return strs.back();
}

std::string watcher::get_host(std::string host_port) {
  std::vector<std::string> strs;
  boost::algorithm::split(strs, host_port, boost::is_any_of(":"));
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
