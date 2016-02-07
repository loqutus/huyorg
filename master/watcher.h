#ifndef PROJECT_WATCHER_H
#define PROJECT_WATCHER_H

#include "../lib/confreader/confreader.h"
#include "../lib/logging/logging.h"
#include "../lib/tcpserver/tcpserver.h"
#include "../lib/json/json.h"
#include "../lib/storage/storage.h"
#include <iostream>

class watcher{
public:
	void watch();
	std::unordered_map<std::string, std::list<std::string> > get_running_containers();
};

#endif //PROJECT_WATCHER_H
