#include "main.h"

int main(int argc, char** argv){
    optparse options(argc, argv);
    std::string command = options.get("command");
    tcpclient client(options.get(std::string("host")), options.get(std::string("port")));
	std::cout << command << std::endl;
    if (command == std::string("upload")) {
        upload (options.get(std::string("config")), client);
		std::cout << "read: " << client.read();
	}
	return 0;
}
