#include "watcher.h"

std::unordered_map<std::string, std::list<std::string>>
watcher::get_all_running_containers() {
  std::unordered_map<std::string, std::list<std::string>>
      all_running_containers;
  auto slave_names = store.get_slaves_vector();
  if (slave_names.size() > 0) {
    for (auto slave_name : slave_names) {
      auto slave = store.get_slave(slave_name);
      slave_client slaveclient(slave["slave_host"], slave["slave_port"]);
      auto slave_running_containers = slaveclient.get_containers();
      all_running_containers[slave_name] = slave_running_containers;
    }
  }
  return all_running_containers;
}

void watcher::watch(int sleep_time) {
  while (true) {
    auto all_running_containers = this->get_all_running_containers();
    auto pods = store.get_pods_vector();
    for (auto pod_name : pods) {
      log_obj.write("WATCHER: pod", pod_name);
      auto pod_params = store.get_pod(pod_name);
      auto pod_count = std::stoi(pod_params["pod_count"]);
      auto slaves = store.get_slaves_vector();
      while (pod_count > 0) {
        for (auto slave_name : slaves) {
          log_obj.write("WATCHER: slave", slave_name);
          auto slave = store.get_slave(slave_name);
          slave_client slaveclient(slave["slave_host"], slave["slave_port"]);
          auto container_id = slaveclient.run_container(
              pod_params["pod_image"], pod_params["pod_command"]);
          store.update_slave_minus(slave_name, pod_name);
          log_obj.write("WATCHER: container_id", container_id);
          pod_count--;
        }
      }
    }
    std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
  }
}
