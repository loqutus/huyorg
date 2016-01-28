#include "storage.h"

storage::~storage() {
	storage_map.clear();
}

int storage::set(std::string key, std::string value) {
	storage_map[key] = value;
    return 0;
}

std::string storage::get(std::string key) {
	return storage_map[key];
}
