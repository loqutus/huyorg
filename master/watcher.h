#ifndef PROJECT_WATCHER_H
#define PROJECT_WATCHER_H

#include <boost/algorithm/string.hpp>
#include <chrono>
#include <iostream>
#include <thread>
#include "../lib/confreader/confreader.h"
#include "../lib/json/json.h"
#include "../lib/logging/logging.h"
#include "../lib/slave_client/slave_client.h"
#include "../lib/storage/storage.h"
#include "../lib/tcpserver/tcpserver.h"

class watcher {
 public:
  void watch();
  std::string get_host(std::string host_port);
  std::string get_port(std::string host_port);
  bool check_pod_in_containers(std::string pod_name,
                               std::vector<std::string> containers_vector);
  std::unordered_map<std::string, std::vector<std::string>>
  get_running_containers();
  std::string run_container(std::string slave, std::string image,
                            std::string command);
};

#endif  // PROJECT_WATCHER_H
