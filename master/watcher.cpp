#include "watcher.h"

int watcher::watch() {
  while (true) {
    auto pods = store.get_pods_vector();
    for (auto pod_name : pods) {
      auto pod_params = store.get_pod(pod_name);
      auto slaves = store.get_slaves_vector();
      for (auto slave_name : slaves) {
        auto slave = store.get_slave(slave_name);
        slave_client slaveclient(slave["slave_host"], slave["slave_port"]);
        slaveclient.run_container(pod_params["pod_image"],
                                  pod_params["pod_command"]);
      }
    }
    sleep(60);
  }
}
