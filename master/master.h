#ifndef PROJECT_MASTER_H
#define PROJECT_MASTER_H

#include "../lib/confreader/confreader.h"
#include "../lib/logging/logging.h"
#include "../lib/tcpserver/tcpserver.h"
#include "../lib/json/json.h"
#include <iostream>
class master{
	const std::string conf_file;
	confreader conf;
	logging log;
	const std::string server_port;
public:
	master();
	~master();
	int listen();
};
#endif //PROJECT_MASTER_H
