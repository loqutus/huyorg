#include "watcher.h"

void watcher::watch(){
	while(true){
		auto running_containers = this->get_running_containers();
	}
}

std::unordered_map<std::string, std::list<std::string> > watcher::get_running_containers(){
	auto slaves_list = store.get_slaves_list();
}
