#include "storage.h"

storage::storage(std::string storagefilename) {
    storage_file.open(storagefilename, std::ios::out);
}

storage::~storage() {
    storage_file.close();
	storage_map.clear();
}

int storage::set(std::string key, std::string value) {
	storage_map[key] = value;
    return 0;
}

std::string storage::get(std::string key) {
	return storage_map[key];
}
