#ifndef PROJECT_CONTAINER_H
#define PROJECT_CONTAINER_H

#include <string>
#include <unordered_map>
#include <vector>
#include "../httpclient/httpclient.h"
#include "../json/json.h"

class container {
  std::string host, port, url;

 public:
  container(std::string host, std::string port);
  std::list<std::string> get_containers();
  std::string create_container(std::string image, std::string command);
  bool run_container(std::string container_id);
  bool destroy_container(std::string container_id);
};

#endif  // PROJECT_CONTAINER_H
