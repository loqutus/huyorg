#include "watcher.h"
int watcher::watch(){
  auto pods = store.get_pods_vector();
  for (auto pod_name:pods)
}
