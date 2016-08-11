#ifndef PROJECT_STORAGE_H
#define PROJECT_STORAGE_H

#include <fstream>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class storage {
  std::unordered_map<std::string, std::unordered_map<std::string, std::string>>
      slaves_map;
  std::unordered_map<std::string, std::unordered_map<std::string, std::string>>
      pods_map;
  std::unordered_map<std::string, std::unordered_map<std::string, std::string>>
      containers_map;

 public:
  ~storage();
  int set_slave(std::string host_port,
                std::unordered_map<std::string, std::string>
                    value);  // key-slave host, port; value=slave parameters
  int set_pod(std::string key,
              std::unordered_map<std::string, std::string>
                  value);  // key-pod name, value=pod parameters
  int set_container(
      std::string key,
      std::unordered_map<std::string, std::string> value);  // key=pod name,
  // value key =
  // container id,
  // value value =
  // container status
  int remove_slave(std::string host_port);
  int remove_pod(std::string key);
  bool is_slaves_empty();
  bool is_pods_empty();
  bool is_containers_empty();
  std::unordered_map<std::string, std::string> get_slave(std::string key);
  std::unordered_map<std::string, std::string> get_pod(std::string key);
  std::unordered_map<std::string, std::string> get_container(std::string key);
  std::vector<std::string> get_slaves_vector();
  std::vector<std::string> get_pods_vector();
  std::vector<std::string> get_containers_vector();
};
extern storage store;

#endif  // PROJECT_STORAGE_H
