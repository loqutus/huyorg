#ifndef PROJECT_CONTAINER_H
#define PROJECT_CONTAINER_H

#include <string>
#include <unordered_map>
#include <vector>
#include "../httpclient/httpclient.h"
#include "../json/json.h"

class container {
  httpclient http_client;

 public:
  container(std::string host, std::string port);
  std::list<std::string> get_containers();
  std::string run_container(std::string image, std::string command);
  std::string destroy_container(std::string container_id);
};

#endif  // PROJECT_CONTAINER_H
