#ifndef PROJECT_MASTER_H
#define PROJECT_MASTER_H

#include <iostream>
#include "../lib/confreader/confreader.h"
#include "../lib/json/json.h"
#include "../lib/logging/logging.h"
#include "../lib/storage/storage.h"
#include "../lib/tcpserver/tcpserver.h"

class master {
  const std::string server_port;

 public:
  master();
  ~master();
  int listen();
  std::string do_action(std::unordered_map<std::string, std::string> json_map);
};

#endif  // PROJECT_MASTER_H
