#include "storage.h"

storage::~storage() {
  slaves_map.clear();
  pods_map.clear();
  containers_map.clear();
}

bool storage::is_slaves_empty() { return slaves_map.empty(); }

bool storage::is_pods_empty() { return pods_map.empty(); }

bool storage::is_containers_empty() { return containers_map.empty(); }

bool storage::set_slave(std::string key,
                        std::unordered_map<std::string, std::string> value) {
  this->slaves_map[key] = value;
  return true;
}

int storage::remove_slave(std::string key) {
  this->slaves_map.erase(key);
  return 0;
}

bool storage::set_pod(std::string key,
                      std::unordered_map<std::string, std::string> value) {
  this->pods_map[key] = value;
  return true;
}

int storage::remove_pod(std::string key) {
  this->pods_map.erase(key);
  return 0;
}

bool storage::set_container(std::string key, std::string value) {
  this->containers_map[key] = value;
  return true;
}

std::unordered_map<std::string, std::string> storage::get_slave(
    std::string key) {
  return this->slaves_map[key];
}

std::unordered_map<std::string, std::string> storage::get_pod(std::string key) {
  return this->pods_map[key];
}

std::vector<std::string> storage::get_slaves_vector() {
  std::vector<std::string> slaves_vector;
  for (auto& iterator : this->slaves_map) {
    slaves_vector.push_back(iterator.first);
  }
  return slaves_vector;
}

std::vector<std::string> storage::get_pods_vector() {
  std::vector<std::string> pods_vector;
  for (auto& iterator : this->pods_map) {
    pods_vector.push_back(iterator.first);
  }
  return pods_vector;
}

std::vector<std::string> storage::get_containers_vector() {
  std::vector<std::string> containers_vector;
  for (auto& iterator : this->containers_map) {
    containers_vector.push_back(iterator.first);
  }
  return containers_vector;
}

void storage::update_slave_minus(std::string slave_name, std::string pod_name) {
  auto slave = this->get_slave(slave_name);
  auto pod = this->get_pod(pod_name);
  auto pod_cpus = std::stoi(pod["pod_cpus"]);
  auto pod_memory = std::stoi(pod["pod_memory"]);
  auto pod_disk = std::stoi(pod["pod_disk"]);
  auto slave_cpus = std::stoi(slave["slave_cpus"]);
  auto slave_memory = std::stoi(slave["slave_memory"]);
  auto slave_disk = std::stoi(slave["slave_disk"]);
  slave_cpus -= pod_cpus;
  slave_memory -= pod_memory;
  slave_disk -= pod_disk;
  slave["cpus"] = slave_cpus;
  slave["memory"] = slave_memory;
  slave["disk"] = slave_disk;
  this->set_slave(slave_name, slave);
}

void storage::update_slave_plus(std::string slave_name, std::string pod_name) {
  auto slave = this->get_slave(slave_name);
  auto pod = this->get_pod(pod_name);
  auto pod_cpus = std::stoi(pod["pod_cpus"]);
  auto pod_memory = std::stoi(pod["pod_memory"]);
  auto pod_disk = std::stoi(pod["pod_disk"]);
  auto slave_cpus = std::stoi(slave["slave_cpus"]);
  auto slave_memory = std::stoi(slave["slave_memory"]);
  auto slave_disk = std::stoi(slave["slave_disk"]);
  slave_cpus += pod_cpus;
  slave_memory += pod_memory;
  slave_disk += pod_disk;
  slave["cpus"] = slave_cpus;
  slave["memory"] = slave_memory;
  slave["disk"] = slave_disk;
  this->set_slave(slave_name, slave);
}
