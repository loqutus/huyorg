#include "main.h"

int main(int argc, char** argv){
    optparse options(argc, argv);
    std::string command = options.get("command");
    tcpclient client(options.get(std::string("host")), options.get(std::string("port")));
    if (command == std::string("upload"))
        upload (options.get(std::string("config")), client);
	return 0;
}
