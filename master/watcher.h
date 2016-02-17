#ifndef PROJECT_WATCHER_H
#define PROJECT_WATCHER_H

#include "../lib/confreader/confreader.h"
#include "../lib/logging/logging.h"
#include "../lib/tcpserver/tcpserver.h"
#include "../lib/json/json.h"
#include "../lib/storage/storage.h"
#include "../lib/dockerclient/dockerclient.h"
#include <iostream>
#include <boost/algorithm/string.hpp>

class watcher{
public:
	void watch();
	std::string get_host(std::string host_port);
	std::string get_port(std::string host_port);
	std::unordered_map<std::string, std::list<std::string> > get_running_containers();
};

#endif //PROJECT_WATCHER_H
