#include "watcher.h"

void watcher::watch(int sleep_time) {
  while (true) {
    auto pods = store.get_pods_vector();
    for (auto pod_name : pods) {
      log_obj.write("WATCHER: pod", pod_name);
      auto pod_params = store.get_pod(pod_name);
      auto slaves = store.get_slaves_vector();
      for (auto slave_name : slaves) {
        log_obj.write("WATCHER: slave", slave_name);
        auto slave = store.get_slave(slave_name);
        slave_client slaveclient(slave["slave_host"], slave["slave_port"]);
        auto container_json = slaveclient.run_container(
            pod_params["pod_image"], pod_params["pod_command"]);
        log_obj.write("WATCHER: ", container_json);
      }
    }
    std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
  }
}
