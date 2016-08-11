#ifndef PROJECT_WATCHER_H
#define PROJECT_WATCHER_H

#include <unistd.h>
#include <boost/algorithm/string.hpp>
#include <chrono>
#include <iostream>
#include <list>
#include <thread>
#include "../lib/confreader/confreader.h"
#include "../lib/host_port_parser/host_port_parser.h"
#include "../lib/json/json.h"
#include "../lib/logging/logging.h"
#include "../lib/slave_client/slave_client.h"
#include "../lib/storage/storage.h"
#include "../lib/tcpserver/tcpserver.h"

class watcher {
 public:
  int watch();
};

#endif  // PROJECT_WATCHER_H
