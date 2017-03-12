#ifndef PROJECT_WATCHER_H
#define PROJECT_WATCHER_H

#include "../lib/confreader/confreader.h"
#include "../lib/json/json.h"
#include "../lib/logging/logging.h"
#include "../lib/slave_client/slave_client.h"
#include "../lib/storage/storage.h"
#include "../lib/tcpserver/tcpserver.h"
#include <boost/algorithm/string.hpp>
#include <chrono>
#include <iostream>
#include <list>
#include <thread>
#include <unistd.h>

class watcher {
    // key: slave_name, value: vector with running container ids
    std::unordered_map<std::string, std::list<std::string>>
    get_all_running_containers();

  public:
    void watch(int sleep_time = 60);
};

#endif // PROJECT_WATCHER_H
